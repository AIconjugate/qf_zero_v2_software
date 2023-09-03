#include "lv_input_interface.h"
#include "lcd_driver_interface.h"
#include "system_app.h"

static lv_indev_t *indev_tp_handle = NULL;
static ring_buffer_handle_t ring_handle_x = NULL;
static ring_buffer_handle_t ring_handle_y = NULL;
static uint8_t tp_touch_sta = 0;

// static void gesture_motor_off(btask_event_t *e)
// {
//     system_set_motor(0);
// }

// static void gesture_motor()
// {
//     system_set_motor(100);
//     btask_creat_ms(20, gesture_motor_off, 1, NULL, NULL);
// }

static void get_tp_touch_sta_cb(void *value, size_t lenth)
{
    *(uint8_t *)value = tp_touch_sta;
}

static void tp_lvgl_read_cb(lv_indev_drv_t *indev, lv_indev_data_t *data)
{
    static cst816_info_t info;
    static uint8_t clr_flg = 0;
    static uint32_t start_t = 0;

    cst816_read_info(&info);
    if (info.state == tp_touching)
    {
        if (clr_flg == 0) // 触摸时背光常亮
        {
            tp_touch_sta = 1;
            ring_buffer_init_value(ring_handle_x, &info.now_x);
            ring_buffer_init_value(ring_handle_y, &info.now_y);

            clr_flg = 1;

            system_screen_keep_on(1);
        }
        else
        {
            ring_buffer_write(ring_handle_x, &info.now_x);
            ring_buffer_write(ring_handle_y, &info.now_y);
        }

        uint16_t nx = 0, ny = 0;
        ring_buffer_get_moveing_flitering(ring_handle_x, &nx);
        ring_buffer_get_moveing_flitering(ring_handle_y, &ny);

        data->point.x = nx;
        data->point.y = ny;
        data->state = LV_INDEV_STATE_PRESSED;
    }
    else
    {
        if (clr_flg == 1) // 释放背光常亮
        {
            tp_touch_sta = 0;
            uint8_t tmp = 0;
            int16_t cha = (int16_t)info.start_x - (int16_t)info.end_x;
            if (cha < 2 && cha > -2)
            {
                cha = (int16_t)info.start_y - (int16_t)info.end_y;
                if (cha > 2 || cha < -2)
                {
                    tmp = 1;
                }

                printf("t:%d\n", esp_log_timestamp() - start_t);
                if ((esp_log_timestamp() - start_t) <= 300)
                {
                    key_value_msg("tp_double", NULL, 0);
                }

                start_t = esp_log_timestamp();
            }
            else
            {
                tmp = 1;
            }
            system_tp_type(&tmp);

            clr_flg = 0;
            system_screen_keep_on(0);
            data->point.x = info.end_x;
            data->point.y = info.end_y;
        }

        data->state = LV_INDEV_STATE_RELEASED;
    }
    // if (info.gesture != tp_gesture_none)
    // {
    //     if (info.gesture == tp_gesture_down && info.start_y < tp_gesture_threshold)
    //     {
    //         if (info.now_y > (LCD_V_RES - (LCD_V_RES / 3)))
    //             key_value_msg("sys_status_bar", NULL, 0);
    //         return;
    //     }

    //     if ((esp_log_timestamp() - start_t) < tp_gesture_hold_time_ms)
    //         return;

    //     // 手指松开时必须在中心1/4才生效
    //     if (info.now_y < (LCD_V_RES / 2 - (LCD_V_RES / 8)))
    //         return;
    //     if (info.now_y > (LCD_V_RES / 2 + (LCD_V_RES / 8)))
    //         return;
    //     if (info.now_x < (LCD_H_RES / 2 - (LCD_H_RES / 8)))
    //         return;
    //     if (info.now_x > (LCD_H_RES / 2 + (LCD_H_RES / 8)))
    //         return;

    //     switch (info.gesture)
    //     {
    //     case tp_gesture_up:
    //         if (info.start_y > (LCD_V_RES - tp_gesture_threshold))
    //         {
    //             key_value_msg("sys_home", NULL, 0);
    //             gesture_motor();
    //         }
    //         break;

    //     case tp_gesture_left:
    //         if (info.start_x > (240 - tp_gesture_threshold))
    //         {
    //             key_value_msg("sys_back", NULL, 0);
    //             gesture_motor();
    //         }
    //         break;

    //     case tp_gesture_right:
    //         if (info.start_x < tp_gesture_threshold)
    //         {
    //             key_value_msg("sys_back", NULL, 0);
    //             gesture_motor();
    //         }
    //         break;

    //     default:
    //         break;
    //     }
    //     info.gesture = tp_gesture_none;
    //     // 添加手势功能
    // }
}

/**
 * @brief 触摸屏中断服务函数
 *
 * @param arg
 */
static void IRAM_ATTR tp_intrHandler(void *arg)
{
    cs816_intr();
}

static void tp_write_byte(uint8_t addr, uint8_t reg, uint8_t data)
{
    uint8_t tmp[2] = {reg, data};
    i2c_master_write_to_device(TP_USE_I2C_NUM, addr, tmp, 2, 1000 / portTICK_RATE_MS);
}

static void tp_read_bytes(uint8_t addr, uint8_t reg, uint8_t *data, size_t len)
{
    i2c_master_write_read_device(TP_USE_I2C_NUM, addr, &reg, 1, data, len, 1000 / portTICK_RATE_MS);
}

static esp_err_t tp_interface_init()
{

    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = TP_I2C_SDA_IO,
        .scl_io_num = TP_I2C_SCL_IO,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = TP_I2C_FREQ_HZ,
    };

    i2c_param_config(TP_USE_I2C_NUM, &conf);
    int ret = i2c_driver_install(TP_USE_I2C_NUM, conf.mode, 0, 0, 0);
    if (ret != ESP_OK)
        return ret;
    tp_i2c_cb cfg;
    cfg.i2c_read_bytes = tp_read_bytes;
    cfg.i2c_write_byte = tp_write_byte;
    cst816_attach_i2c_cb(&cfg);

    gpio_pad_select_gpio(TP_INTR_GPIO);
    gpio_set_direction(TP_INTR_GPIO, GPIO_MODE_INPUT);
    gpio_set_intr_type(TP_INTR_GPIO, GPIO_INTR_NEGEDGE);
    gpio_install_isr_service(0);
    gpio_isr_handler_add(TP_INTR_GPIO, tp_intrHandler, (void *)TP_INTR_GPIO);

    return ret;
}

void lv_input_tp_init()
{
    tp_interface_init();

    static lv_indev_drv_t tp_indev;
    lv_indev_drv_init(&tp_indev);
    tp_indev.type = LV_INDEV_TYPE_POINTER;
    tp_indev.read_cb = tp_lvgl_read_cb;
    indev_tp_handle = lv_indev_drv_register(&tp_indev);

    ring_handle_x = ring_buffer_create(sample_16bit, 0, 5);
    ring_handle_y = ring_buffer_create(sample_16bit, 0, 5);

    ring_buffer_set_moveing_flitering_en(ring_handle_x, 1);
    ring_buffer_set_moveing_flitering_en(ring_handle_y, 1);

    key_value_register(NULL, "tp_sta", get_tp_touch_sta_cb);
}

lv_indev_t *lv_input_get_handle()
{
    return indev_tp_handle;
}