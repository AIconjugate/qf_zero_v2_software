#include "muyu_app.h"
#include "system_app.h"
#include "desktop.h"

LV_IMG_DECLARE(muyu_app_img_muyu);
LV_IMG_DECLARE(muyu_app_icon);

LV_FONT_DECLARE(muyu_app_font_24);
LV_FONT_DECLARE(muyu_app_font_22);
LV_FONT_DECLARE(muyu_app_font_18);

static RTC_FAST_ATTR uint32_t muyu_cnt = 0;

static lv_obj_t *app_scr = NULL;
static lv_obj_t *app_img = NULL;

static int32_t _ui_anim_callback_get_y(lv_anim_t *a)
{
    if (app_scr == NULL)
        return 0;
    return lv_obj_get_y_aligned((lv_obj_t *)a->user_data);
}

static void _ui_anim_callback_set_y(lv_anim_t *a, int32_t v)
{
    if (app_scr == NULL)
        return;
    lv_obj_t *_obj = (lv_obj_t *)a->user_data;
    lv_obj_set_style_text_opa(_obj, (v + 125) * 5, 0);
    lv_obj_set_y(_obj, v);
}

static void ui_muyu_timer_img(lv_timer_t *e)
{
    if (app_scr == NULL)
        return;
    lv_img_set_zoom(app_img, 256);
    uint8_t motor = 0;
    key_value_msg("sys_set_motor", &motor, 1);
}

static void _anim_del_cb(lv_anim_t *a)
{
    if (app_scr == NULL)
        return;
    lv_obj_del((lv_obj_t *)a->user_data);
}

void ui_event_muyu(lv_event_t *e)
{
    if (e->code == LV_EVENT_PRESSED)
    {
        uint8_t motor = 40;
        key_value_msg("sys_set_motor", &motor, 1);

        lv_obj_t *label = lv_label_create(app_scr);
        lv_label_set_text(label, "功德+1");
        lv_obj_align(label, LV_ALIGN_CENTER, 0, -75);
        lv_obj_set_style_text_font(label, &muyu_app_font_22, 0);
        lv_obj_set_style_text_color(label, lv_color_hex(0x9A7E5D), 0);

        lv_anim_t _muyu_anim;
        lv_anim_init(&_muyu_anim);
        lv_anim_set_time(&_muyu_anim, 500);
        lv_anim_set_user_data(&_muyu_anim, label);
        lv_anim_set_custom_exec_cb(&_muyu_anim, _ui_anim_callback_set_y);
        lv_anim_set_values(&_muyu_anim, 0, -50);
        lv_anim_set_path_cb(&_muyu_anim, lv_anim_path_ease_in);
        lv_anim_set_delay(&_muyu_anim, 100);
        lv_anim_set_repeat_count(&_muyu_anim, 0);
        lv_anim_set_get_value_cb(&_muyu_anim, &_ui_anim_callback_get_y);
        lv_anim_set_deleted_cb(&_muyu_anim, _anim_del_cb);
        lv_anim_start(&_muyu_anim);

        lv_timer_t *muyu_timer = lv_timer_create(ui_muyu_timer_img, 30, NULL);
        lv_timer_set_repeat_count(muyu_timer, 1);
        lv_img_set_zoom(app_img, 256 + 15);

        muyu_cnt++;
        lv_label_set_text_fmt((lv_obj_t *)e->user_data, "功德:%d", muyu_cnt);
        lv_obj_align((lv_obj_t *)e->user_data, LV_ALIGN_BOTTOM_MID, 0, -8);
    }
    else if (e->code == LV_EVENT_GESTURE)
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        if (dir == LV_DIR_RIGHT || dir == LV_DIR_LEFT)
        {
            lv_scr_load_anim_t anim;
            if (dir == LV_DIR_LEFT)
                anim = LV_SCR_LOAD_ANIM_MOVE_LEFT;
            else if (dir == LV_DIR_RIGHT)
                anim = LV_SCR_LOAD_ANIM_MOVE_RIGHT;
            key_value_msg("sys_home", &anim, sizeof(anim));
            muyu_cnt--;
            return;
        }
    }
}

void ui_muyu_event_btn(lv_event_t *e)
{
    muyu_cnt = 0;
    lv_label_set_text_fmt((lv_obj_t *)e->user_data, "功德:%d", muyu_cnt);
    lv_obj_align((lv_obj_t *)e->user_data, LV_ALIGN_BOTTOM_MID, 0, -8);
}

static void muyu_app_load(void *arg)
{
    app_scr = lv_obj_create(NULL);

    lv_obj_clear_flag(app_scr, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(app_scr, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);

    app_img = lv_img_create(app_scr);
    lv_img_set_src(app_img, &muyu_app_img_muyu);
    lv_obj_clear_flag(app_img, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_align(app_img, LV_ALIGN_CENTER, 0, -10);

    lv_obj_t *btn = lv_btn_create(app_scr);
    lv_obj_remove_style_all(btn);
    lv_obj_set_size(btn, 30, 20);
    lv_obj_align(btn, LV_ALIGN_BOTTOM_MID, 0, -5);

    lv_obj_t *label = lv_label_create(app_scr);
    lv_obj_set_style_text_font(label, &muyu_app_font_18, 0);
    lv_obj_set_style_text_color(label, lv_color_hex(0xd9b38c), 0);
    lv_obj_align(label, LV_ALIGN_BOTTOM_MID, 0, -8);
    lv_label_set_text_fmt(label, "功德:%d", muyu_cnt);

    lv_obj_add_event_cb(btn, ui_muyu_event_btn, LV_EVENT_CLICKED, label);
    lv_obj_add_event_cb(app_scr, ui_event_muyu, LV_EVENT_ALL, label);

    app_scr_load(app_scr, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0); // 加载APP界面
}

static void muyu_app_close(void *arg)
{
    app_scr = NULL;
}

void muyu_app_install()
{
    app_config_t cfg = {
        .app_close = muyu_app_close,
        .app_init = NULL,
        .app_kill = NULL,
        .app_load = muyu_app_load,
        .app_power_off = NULL,
        .has_gui = 1,
        .icon = &muyu_app_icon,
        .name = "电子木鱼",
        .name_font = &muyu_app_font_24};
    app_install(&cfg,NULL);
}