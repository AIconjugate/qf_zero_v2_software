#include "lv_input_interface.h"
#include "lcd_driver_interface.h"
#include "system_app.h"
#include "app_mouse.h"

static lv_indev_t *indev_tp_handle = NULL;
static ring_buffer_handle_t ring_handle_x = NULL;
static ring_buffer_handle_t ring_handle_y = NULL;
static uint8_t tp_touch_sta = 0;

static void get_tp_indev_cb(void *value, size_t lenth)
{
    *(lv_indev_t **)value = indev_tp_handle;
}

static void get_tp_touch_sta_cb(void *value, size_t lenth)
{
    *(uint8_t *)value = tp_touch_sta;
}

static void tp_lvgl_read_cb(lv_indev_drv_t *indev, lv_indev_data_t *data)
{
    static cst816_info_t info;
    static uint8_t clr_flg = 0;
    static int16_t last_x = 0, last_y = 0;

    cst816_read_info(&info);

    if (info.state == tp_touching)
    {
        if (clr_flg == 0) // 触摸时背光常亮
        {
            tp_touch_sta = 1;
            ring_buffer_init_value(ring_handle_x, &info.point.now_x);
            ring_buffer_init_value(ring_handle_y, &info.point.now_y);
            last_x = info.point.now_x;
            last_y = info.point.now_y;
            clr_flg = 1;
            system_screen_keep_on(1);
        }
        else
        {
            ring_buffer_write(ring_handle_x, &info.point.now_x);
            ring_buffer_write(ring_handle_y, &info.point.now_y);
        }

        uint16_t nx = 0, ny = 0;
        ring_buffer_get_moveing_flitering(ring_handle_x, &nx);
        ring_buffer_get_moveing_flitering(ring_handle_y, &ny);

        if (app_mouse_get_act() == 0)
        {
            data->point.x = nx;
            data->point.y = ny;
        }
        else
        {
            static int16_t point_x = LCD_H_RES / 2, point_y = LCD_V_RES / 2;
            static float sx = 0, sy = 0;

            sx += (float)(nx - last_x) * app_mouse_get_sensity();
            sy += (float)(ny - last_y) * app_mouse_get_sensity();

            int16_t x_int = sx;
            int16_t y_int = sy;

            sx -= x_int;
            sy -= y_int;

            point_x += x_int;
            point_y += y_int;

            if (point_x < 0)
                point_x = 0;
            else if (point_x >= LCD_H_RES)
                point_x = LCD_H_RES - 1;

            if (point_y < 0)
                point_y = 0;
            else if (point_y >= LCD_V_RES)
                point_y = LCD_V_RES - 1;

            data->point.x = point_x;
            data->point.y = point_y;
        }

        last_x = nx;
        last_y = ny;

        // printf("%d,%d\n",nx,ny);

        data->state = LV_INDEV_STATE_PRESSED;
    }
    else
    {
        if (clr_flg == 1) // 释放背光常亮
        {
            tp_touch_sta = 0;
            clr_flg = 0;
            system_screen_keep_on(0);
            if (app_mouse_get_act() == 0)
            {
                data->point.x = info.point.end_x;
                data->point.y = info.point.end_y;
            }
        }
        data->state = LV_INDEV_STATE_RELEASED;
    }
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
    key_value_register(NULL, "sys_get_tp_indev", get_tp_indev_cb);
}

lv_indev_t *lv_input_get_handle()
{
    return indev_tp_handle;
}