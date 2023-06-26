#include "test_app.h"
#include "system_app.h"
#include "my_lv_symbol_font.h"

typedef struct userdata
{
    lv_obj_t *label_bat;
    lv_obj_t *label_time;
    lv_obj_t *label_usb;
} userdata_t;

void test_cb(lv_timer_t *e)
{
    userdata_t *tmp = (userdata_t *)e->user_data;

    cw2015_bat_info_t bat_info;
    system_get_bat(&bat_info);
    lv_label_set_text_fmt(tmp->label_bat, "%d%%  %dmV", bat_info.soc, bat_info.voltage);

    clock_time_t time;
    system_get_time(&time);

    lv_label_set_text_fmt(tmp->label_time, "%d-%d  %d  %d-%d-%d", time.month, time.day, time.week, time.hour, time.min, time.sec);

    static uint8_t usb_sta = 0;
    if (system_get_usb_sta() != usb_sta)
    {
        usb_sta = system_get_usb_sta();
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

static void test_app_load()
{
    static RTC_FAST_ATTR uint8_t reset_count = 0;
    static userdata_t labels;

    reset_count++;

    system_take_gui_key(); // 获取GUI增删权限

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
    lv_obj_align_to(label_time, slider, LV_ALIGN_OUT_TOP_MID, -40, -10);
    labels.label_time = label_time;

    system_give_gui_key(); // 归还GUI增删权限

    // bmp280_trans_cb_t bmp_cb;
    // bmp_cb.bmp_read_bytes = (bmp280_read_bytes_cb_t)senser_iic_read_bytes;
    // bmp_cb.bmp_write_byte = (bmp280_write_byte_cb_t)senser_iic_write_byte;
    // bmp280_attach_trans_cb(&bmp_cb);

    // bmp280_begin();

    lv_timer_create(test_cb, 10, &labels);
}

void test_app_install()
{
    app_config_t cfg = {
        .app_close = NULL,
        .app_init = NULL,
        .app_kill = NULL,
        .app_load = test_app_load,
        .app_power_off = NULL,
        .has_gui = 1,
        .icon = &img_popcat_close,
        .name = "test_app"};
    app_install(&cfg);
}