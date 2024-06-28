#include "lcd_driver_interface.h"

static uint8_t lcd_blk = 0;
static lv_disp_drv_t disp_drv; // contains callback functions
static esp_lcd_panel_handle_t panel_handle;

#if LCD_SUPPORT_TE
static uint8_t flush_busy = 0;
static void IRAM_ATTR te_intrHandler(void *arg)
{
    if (flush_busy == 0)
        lv_disp_flush_ready(&disp_drv);
}
#endif

static bool notify_lvgl_flush_ready(esp_lcd_panel_io_handle_t panel_io, esp_lcd_panel_io_event_data_t *edata, void *user_ctx)
{
#if LCD_SUPPORT_TE
    flush_busy = 0;
#else
    lv_disp_flush_ready(&disp_drv);
#endif
    return false;
}

void lcd_lvgl_flush_cb(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_map)
{
    esp_lcd_panel_handle_t panel_handle = (esp_lcd_panel_handle_t)drv->user_data;
    esp_lcd_panel_draw_bitmap(panel_handle, area->x1, area->y1, area->x2 + 1, area->y2 + 1, color_map); // (uint16_t *)&color_map->full
#if LCD_SUPPORT_TE
    flush_busy = 1;
#endif
}

void lcd_driver_init()
{
    gpio_config_t gpio_cfg = {// LCD电源使能
                              .intr_type = GPIO_INTR_DISABLE,
                              .mode = GPIO_MODE_OUTPUT,
                              .pin_bit_mask = 1ULL << LCD_PIN_NUM_POWER,
                              .pull_down_en = 0,
                              .pull_up_en = 0};
    gpio_config(&gpio_cfg);

    // 上拉LCD复位IO 硬件复位关闭，使用软件复位
    gpio_cfg.mode = GPIO_MODE_INPUT;
    gpio_cfg.pin_bit_mask = 1ULL << LCD_PIN_NUM_RST;
    gpio_cfg.pull_up_en = 1;
    gpio_config(&gpio_cfg);

    gpio_cfg.pull_up_en = 0; // 屏蔽TE采集
    gpio_cfg.pin_bit_mask = 1ULL << LCD_PIN_NUM_TE;
    gpio_config(&gpio_cfg);

    esp_lcd_i80_bus_handle_t i80_bus = NULL;
    esp_lcd_i80_bus_config_t bus_config = {
        .dc_gpio_num = LCD_PIN_NUM_DC,
        .wr_gpio_num = LCD_PIN_NUM_PCLK,
        .data_gpio_nums = {
            LCD_PIN_NUM_DATA0,
            LCD_PIN_NUM_DATA1,
            LCD_PIN_NUM_DATA2,
            LCD_PIN_NUM_DATA3,
            LCD_PIN_NUM_DATA4,
            LCD_PIN_NUM_DATA5,
            LCD_PIN_NUM_DATA6,
            LCD_PIN_NUM_DATA7,
        },
        .bus_width = 8,
        .max_transfer_bytes = I8080_TRANS_BYTES};

    esp_lcd_new_i80_bus(&bus_config, &i80_bus); // 创建并初始化MCU接口

    esp_lcd_panel_io_handle_t io_handle = NULL;
    esp_lcd_panel_io_i80_config_t io_config = {
        .cs_gpio_num = LCD_PIN_NUM_CS,
        .pclk_hz = LCD_PIXEL_CLOCK_HZ,
        .trans_queue_depth = 10,
        .dc_levels = {
            .dc_idle_level = 0,
            .dc_cmd_level = 0,
            .dc_dummy_level = 0,
            .dc_data_level = 1,
        },
        .flags = {
            .swap_color_bytes = 1,
        },
        .on_color_trans_done = notify_lvgl_flush_ready,
        .user_ctx = &disp_drv,
        .lcd_cmd_bits = LCD_CMD_BITS,
        .lcd_param_bits = LCD_PARAM_BITS,
    };
    esp_lcd_new_panel_io_i80(i80_bus, &io_config, &io_handle); // 设定MCU接口通信格式

    esp_lcd_panel_dev_config_t panel_config = {
        .reset_gpio_num = -1,
        .color_space = ESP_LCD_COLOR_SPACE_RGB,
        .bits_per_pixel = 16,
    };
    esp_lcd_new_panel_gc9a01(io_handle, &panel_config, &panel_handle); // 创建LCD通信对象

    esp_lcd_panel_reset(panel_handle); // 复位LCD
    esp_lcd_panel_init(panel_handle);  // 初始化LCD

    ledc_timer_config_t ledc_timer = {// 初始化背光PWM定时器
                                      .speed_mode = LCD_LEDC_MODE,
                                      .timer_num = LCD_LEDC_TIMER,
                                      .duty_resolution = LCD_LEDC_DUTY_RES,
                                      .freq_hz = LCD_LEDC_FREQUENCY,
                                      .clk_cfg = LEDC_AUTO_CLK};
    ledc_timer_config(&ledc_timer);

    ledc_channel_config_t ledc_channel = {// 初始化背光参数
                                          .speed_mode = LCD_LEDC_MODE,
                                          .channel = LCD_LEDC_CHANNEL,
                                          .timer_sel = LCD_LEDC_TIMER,
                                          .intr_type = LEDC_INTR_DISABLE,
                                          .gpio_num = LCD_PIN_NUM_BK_LIGHT,
                                          .duty = 0, // Set duty to 0%
                                          .hpoint = 0};
    ledc_channel_config(&ledc_channel); // 启用背光LEDC

#if LCD_SUPPORT_TE
    gpio_set_intr_type(LCD_PIN_NUM_TE, GPIO_INTR_POSEDGE);
    gpio_install_isr_service(0);
    gpio_isr_handler_add(LCD_PIN_NUM_TE, te_intrHandler, (void *)LCD_PIN_NUM_TE);
#endif
}

void lcd_set_blk(uint8_t var)
{
    uint16_t tmp = var * 10.23;
    if (tmp > 1023)
        tmp = 1023;
    if (tmp == 0)
        tmp++;
    ledc_set_duty(LCD_LEDC_MODE, LCD_LEDC_CHANNEL, tmp);
    ledc_update_duty(LCD_LEDC_MODE, LCD_LEDC_CHANNEL);
    lcd_blk = tmp;
}

uint8_t lcd_get_blk()
{
    return lcd_blk;
}

lv_disp_drv_t *lcd_get_disp_drv()
{
    return &disp_drv;
}

esp_lcd_panel_handle_t lcd_get_panel_handle()
{
    return panel_handle;
}