#include "lv_input_interface.h"
#include "lcd_driver_interface.h"

static lv_indev_t *indev_tp_handle = NULL;

static void tp_lvgl_read_cb(lv_indev_drv_t *indev, lv_indev_data_t *data)
{
    static cst816_info_t info;
    static uint8_t clr_flg = 0;
    cst816_read_info(&info);
    if (info.state == tp_touching)
    {
        if (clr_flg == 0) // 触摸时背光常亮
        {
            clr_flg = 1;
            key_value_msg("sys_always_on", &clr_flg, sizeof(clr_flg));
        }

        data->point.x = info.now_x;
        data->point.y = info.now_y;
        data->state = LV_INDEV_STATE_PRESSED;
    }
    else
    {
        if (clr_flg == 1) // 释放背光常亮恢复
        {
            clr_flg = 0;
            key_value_msg("sys_always_on", &clr_flg, sizeof(clr_flg));
        }
        data->state = LV_INDEV_STATE_RELEASED;
    }
    if (info.gesture != tp_gesture_none)
    {
        // 添加手势功能
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
}

lv_indev_t *lv_input_get_handle()
{
    return indev_tp_handle;
}