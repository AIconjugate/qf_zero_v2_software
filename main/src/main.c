#include "device_interfaces.h"
#include "system_app.h"

////////////////////////////////////测试程序////////////////////////////////////////////////////

typedef struct userdata
{
    lv_obj_t *label_bat;
    lv_obj_t *label_time;
    lv_obj_t *label_usb;
} userdata_t;

void test_cb(btask_event_t *e)
{

    // 获取剩余的dram大小
    // size_t dram = heap_caps_get_free_size(MALLOC_CAP_INTERNAL);

    // // 获取剩余的iram大小
    // size_t iram = heap_caps_get_free_size(MALLOC_CAP_32BIT) - heap_caps_get_free_size(MALLOC_CAP_8BIT);

    // size_t heap = heap_caps_get_free_size(MALLOC_CAP_8BIT);

    // // 获取最大的连续的堆区空间
    // size_t heapmax = heap_caps_get_largest_free_block(MALLOC_CAP_8BIT);
    // int *p = (int *)malloc(heapmax);
    // free(p);

    // printf("\n\ndram:%d,iram:%d,heap:%d,heap_max:%d\n\n", dram, iram, heap, heapmax);

    // int32_t pre;
    // int16_t temp;
    // bmp280_read(&temp, &pre);
    // printf("temp:%d,pre:%d\n", temp, pre);

    userdata_t *tmp = (userdata_t *)e->userdata;

    cw2015_bat_info_t bat_info;
    system_get_bat(&bat_info);
    lv_label_set_text_fmt(tmp->label_bat, "%d%%  %dmV", bat_info.soc, bat_info.voltage);

    clock_time_t time;
    system_get_time(&time);

    lv_label_set_text_fmt(tmp->label_time, "%d-%d-%d", time.hour, time.min, time.sec);

    static uint8_t usb_sta = 0;
    if (per_get_usb_online_sta() != usb_sta)
    {
        usb_sta = per_get_usb_online_sta();
        if (usb_sta)
            lv_label_set_text(tmp->label_usb, "usb online");
        else
            lv_label_set_text(tmp->label_usb, "usb offline");
    }
}

void slider_cb(lv_event_t *e)
{
    uint8_t blk = lv_slider_get_value(e->target);
    key_value_msg("sys_set_blk", &blk, 1);
}

static void ui_test()
{
    static RTC_FAST_ATTR uint8_t reset_count = 0;
    static userdata_t labels;

    reset_count++;

    system_take_gui_key();

    lv_obj_t *slider = lv_slider_create(lv_scr_act());
    lv_slider_set_range(slider, 0, 100);
    lv_slider_set_value(slider, system_get_blk(), LV_ANIM_ON);
    lv_obj_set_size(slider, 200, 30);
    lv_obj_center(slider);
    lv_obj_add_event_cb(slider, slider_cb, LV_EVENT_VALUE_CHANGED, NULL);

    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_obj_align_to(label, slider, LV_ALIGN_OUT_BOTTOM_MID, -20, 10);
    labels.label_usb = label;

    lv_obj_t *label_reset = lv_label_create(lv_scr_act());
    lv_label_set_text_fmt(label_reset, "reset:%d", reset_count);
    lv_obj_align_to(label_reset, slider, LV_ALIGN_OUT_TOP_MID, 0, -80);

    lv_obj_t *label_bat = lv_label_create(lv_scr_act());
    lv_obj_align_to(label_bat, slider, LV_ALIGN_OUT_TOP_MID, -40, -50);
    labels.label_bat = label_bat;

    lv_obj_t *label_time = lv_label_create(lv_scr_act());
    lv_obj_align_to(label_time, slider, LV_ALIGN_OUT_TOP_MID, -20, -10);
    labels.label_time = label_time;

    system_give_gui_key();

    // bmp280_trans_cb_t bmp_cb;
    // bmp_cb.bmp_read_bytes = (bmp280_read_bytes_cb_t)senser_iic_read_bytes;
    // bmp_cb.bmp_write_byte = (bmp280_write_byte_cb_t)senser_iic_write_byte;
    // bmp280_attach_trans_cb(&bmp_cb);

    // bmp280_reset();

    // bmp280_begin();

    btask_creat_ms(10, test_cb, 0, NULL, &labels);
}

////////////////////以上为测试程序//////////////////////////

extern void app_startup_list();

void app_main(void)
{

    device_interface_init(); // 初始化接口程序
    app_startup_list();      // 初始化应用程序

    ui_test(); // 测试程序

    for (;;)
    {

        vTaskDelay(1);
    }
}
