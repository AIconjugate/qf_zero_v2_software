#include "device_interfaces.h"

#include "lcd_driver_interface.h"
#include "hc32_trans_interface.h"
#include "usb_trans_interface.h"
#include "senser_iic_interface.h"
#include "peripheral_interface.h"
#include "lvgl_interface.h"
#include "lv_input_interface.h"

/*************************************************************************************************************/

static TaskHandle_t btask_handle = NULL;

static void timer_1ms_tic(void *arg)
{
    btask_tick_inc(1);
    xTaskNotify(btask_handle, 0, eNoAction);
}

static void btask_task(void *arg)
{
    vTaskDelay(1);
    uint32_t tmp = 0;
    for (;;)
    {
        xTaskNotifyWait(0x00, 0x00, &tmp, portMAX_DELAY);
        btask_handler();
    }
}

static void wait_hc32_ready()
{
    gpio_config_t cfg = {
        .intr_type = GPIO_INTR_DISABLE,
        .mode = GPIO_MODE_INPUT,
        .pin_bit_mask = 1ULL << esp_sta_io,
        .pull_down_en = 0,
        .pull_up_en = 0};

    gpio_config(&cfg);
    uint16_t tout = 0;
    while (gpio_get_level(esp_sta_io) == 0 && tout++ < (1000 * 5)) // 等待副处理器初始化完成,超时未完成跳过等待
        vTaskDelay(1);
}

void device_interface_init()
{
    wait_hc32_ready();                            // 等待副处理器上线
    hc32_trans_init();                            // 初始化协处理器通信接口
    usb_trans_init();                             // 初始化USB通信串口
    lcd_driver_init();                            // 初始化LCD驱动
    lv_interface_init();                          // 初始化LVGL
    lv_input_tp_init();                           // 初始化触摸
    senser_iic_init();                            // 初始化传感器IIC
    per_init();                                   // 初始化无源外围
    esp_sleep_enable_ext0_wakeup(rxd_hc32_io, 0); // 使能休眠由协处理器唤醒

    const esp_timer_create_args_t ms_tick_timer_args = {// 心跳定时器
                                                        .callback = &timer_1ms_tic,
                                                        .name = "btask_tick"};
    esp_timer_handle_t ms_tick_timer = NULL;
    esp_timer_create(&ms_tick_timer_args, &ms_tick_timer);
    esp_timer_start_periodic(ms_tick_timer, 1 * 1000);

    xTaskCreate(btask_task, "btask", 1024 * 10, NULL, configMAX_PRIORITIES - 2, &btask_handle);
}
