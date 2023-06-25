#include "peripheral_interface.h"

static void btn_tic_task(void *arg)
{
    static uint8_t last_level = 0;
    if (last_level == 0 && gpio_get_level(BOTTON_IO) == 0)
        return;
    last_level = 1;
    btn_tic_ms(BOTTON_TIC_MS);
}

static void task_restart(void *arg)
{
    esp_restart();
}

uint8_t btn_read_level(uint8_t io)
{
    return gpio_get_level(io);
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

    btn_attach_read_io_func(btn_read_level);           // 注册读取按键电平函数
    btn_attach(BOTTON_IO, 0);                          // 注册按键
    btn_attach_long_press_trig_cb(task_restart, NULL); // 注册按键长按重启功能

    const esp_timer_create_args_t ms_tick_timer_args = {// Ticker心跳定时器
                                                        .callback = &btn_tic_task,
                                                        .name = "btn_tick"};
    esp_timer_handle_t ms_tick_timer = NULL;
    esp_timer_create(&ms_tick_timer_args, &ms_tick_timer);
    esp_timer_start_periodic(ms_tick_timer, BOTTON_TIC_MS * 1000);
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
