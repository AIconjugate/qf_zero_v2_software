#include "lvgl_interface.h"
#include "lcd_driver_interface.h"

static EventGroupHandle_t lvgl_event_group = NULL;
static SemaphoreHandle_t mutex_handle;

void system_take_gui_key()
{
    xSemaphoreTake(mutex_handle, portMAX_DELAY);
}

void system_give_gui_key()
{
    xSemaphoreGive(mutex_handle);
}

static void lvgl_tic_cb(void *arg)
{
    static uint32_t event_bits = 0x1;
    xEventGroupSetBits(lvgl_event_group, event_bits);
    event_bits <<= 1;
    if (event_bits == 0x100)
        event_bits = 0x1;
}

static void lvgl_task(void *arg)
{
    vTaskDelay(10);
    for (;;)
    {
        xEventGroupWaitBits(lvgl_event_group, 0xff, true, false, LVGL_REFRESH_TIME_MS);
        xSemaphoreTake(mutex_handle, portMAX_DELAY);
        lv_timer_handler();
        xSemaphoreGive(mutex_handle);
    }
}

void lv_interface_init()
{

    static lv_disp_draw_buf_t disp_buf;

    lv_init(); // 初始化LVGL

    lv_color_t *buf1 = heap_caps_malloc(I8080_TRANS_BYTES, LCD_BUFFER_USE); // 申请全屏buffer
    lv_color_t *buf2 = heap_caps_malloc(I8080_TRANS_BYTES, LCD_BUFFER_USE);

    lv_disp_draw_buf_init(&disp_buf, buf1, buf2, LCD_H_RES * LCD_V_RES);

    lv_disp_drv_t *disp_drv = lcd_get_disp_drv(); // 获取LCD对象
    lv_disp_drv_init(disp_drv);                   // 初始化
    disp_drv->hor_res = LCD_H_RES;
    disp_drv->ver_res = LCD_V_RES;
    disp_drv->flush_cb = lcd_lvgl_flush_cb;
    disp_drv->draw_buf = &disp_buf;

    esp_lcd_panel_handle_t panel_handle = lcd_get_panel_handle();
    disp_drv->user_data = panel_handle;
    lv_disp_drv_register(disp_drv);

    xTaskCreatePinnedToCore(lvgl_task, "lvgl", 1024 * 10, NULL, configMAX_PRIORITIES, NULL, LVGL_TASK_ON_CORE);

    const esp_timer_create_args_t ms_tick_timer_args = {// 心跳定时器
                                                        .callback = &lvgl_tic_cb,
                                                        .name = "lvgl_tic"};
    esp_timer_handle_t ms_tick_timer = NULL;
    esp_timer_create(&ms_tick_timer_args, &ms_tick_timer);
    esp_timer_start_periodic(ms_tick_timer, LVGL_REFRESH_TIME_MS * 1000);

    lvgl_event_group = xEventGroupCreate();
    mutex_handle = xSemaphoreCreateMutex();
}
