#include "peripheral_interface.h"

static void btn_tic_task(void *arg)
{
    vTaskDelay(1);
    while (gpio_get_level(BOTTON_IO) == 0)
        vTaskDelay(1);
    for (;;)
    {
        btn_tic_ms(BOTTON_TIC_MS);
        vTaskDelay(BOTTON_TIC_MS);
    }
}

extern uint8_t get_key_level();

static uint8_t btn_read_level(uint8_t io)
{
    return gpio_get_level(io) & get_key_level();
}

static void restart_cb(void *arg)
{
    esp_restart();
}

void per_init()
{
    ledc_timer_config_t ledc_timer = {// 初始化振动器控制
                                      .speed_mode = MOTOR_LEDC_MODE,
                                      .timer_num = MOTOR_LEDC_TIMER,
                                      .duty_resolution = MOTOR_LEDC_DUTY_RES,
                                      .freq_hz = MOTOR_LEDC_FREQUENCY, // Set output frequency at 5 kHz
                                      .clk_cfg = LEDC_AUTO_CLK};
    ledc_timer_config(&ledc_timer);

    ledc_channel_config_t ledc_channel = {// 初始化振动器控制
                                          .speed_mode = MOTOR_LEDC_MODE,
                                          .channel = MOTOR_LEDC_CHANNEL,
                                          .timer_sel = MOTOR_LEDC_TIMER,
                                          .intr_type = LEDC_INTR_DISABLE,
                                          .gpio_num = MOTOR_IO,
                                          .duty = 0, // Set duty to 0%
                                          .hpoint = 0};
    ledc_channel_config(&ledc_channel);

    gpio_config_t cfg = {// 初始化按键、USB输入状态IO
                         .intr_type = GPIO_INTR_DISABLE,
                         .mode = GPIO_MODE_INPUT,
                         .pin_bit_mask = (1ULL << USB_ONLINE_IO) | (1ULL << BOTTON_IO),
                         .pull_down_en = 0,
                         .pull_up_en = 0};
    gpio_config(&cfg);

    btn_attach_read_io_func(btn_read_level); // 注册读取按键电平函数
    btn_attach(BOTTON_IO, 0);                // 注册按键

    xTaskCreate(btn_tic_task, "btn_tick", 1024 * 3, NULL, configMAX_PRIORITIES, NULL);

    gpio_pad_select_gpio(ESP_PRINT_IO);
    gpio_set_direction(ESP_PRINT_IO, GPIO_MODE_INPUT);
    gpio_set_intr_type(ESP_PRINT_IO, GPIO_INTR_NEGEDGE);
    gpio_install_isr_service(0);
    gpio_isr_handler_add(ESP_PRINT_IO, restart_cb, (void *)ESP_PRINT_IO);
}

void per_motor_set(uint8_t var)
{
    uint8_t tmp = (float)var * 2.55;
    ledc_set_duty(MOTOR_LEDC_MODE, MOTOR_LEDC_CHANNEL, tmp);
    ledc_update_duty(MOTOR_LEDC_MODE, MOTOR_LEDC_CHANNEL);
}

uint8_t per_get_usb_online_sta()
{
    return gpio_get_level(USB_ONLINE_IO);
}
