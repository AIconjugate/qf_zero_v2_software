#include "pop_cat_app.h"
#include "system_app.h"
#include "desktop.h"

LV_IMG_DECLARE(pop_cat_app_icon);
LV_IMG_DECLARE(img_popcat_close);
LV_IMG_DECLARE(img_popcat_open);

LV_FONT_DECLARE(pop_cat_app_font_24);

static void ui_event_popcat(lv_event_t *e)
{
    lv_obj_t *img = (lv_obj_t *)e->user_data;
    if (e->code == LV_EVENT_PRESSED)
    {
        lv_img_set_src(img, &img_popcat_open);
        uint8_t motor = 30;
        key_value_msg("sys_set_motor", &motor, 1);
    }
    else if (e->code == LV_EVENT_RELEASED)
    {
        lv_img_set_src(img, &img_popcat_close);
        uint8_t motor = 0;
        key_value_msg("sys_set_motor", &motor, 1);
    }
    if (e->code == LV_EVENT_GESTURE)
    {
        if (lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT || lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT)
        {
            uint8_t motor = 0;
            key_value_msg("sys_set_motor", &motor, 1);
            key_value_msg("sys_home", NULL, 0);
        }
    }
}

static void pop_cat_app_load()
{
    lv_obj_t *scr = lv_obj_create(NULL);

    lv_obj_clear_flag(scr, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(scr, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *img = lv_img_create(scr);

    lv_img_set_src(img, &img_popcat_close);
    lv_obj_clear_flag(img, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_align(img, LV_ALIGN_CENTER, 0, 0);

    lv_obj_add_event_cb(scr, ui_event_popcat, LV_EVENT_ALL, img);

    app_scr_load(scr, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0); // 加载APP界面
}

void pop_cat_app_install()
{
    app_config_t cfg = {
        .app_close = NULL,
        .app_init = NULL,
        .app_kill = NULL,
        .app_load = pop_cat_app_load,
        .app_power_off = NULL,
        .has_gui = 1,
        .icon = &pop_cat_app_icon,
        .name = "POP猫",
        .name_font = &pop_cat_app_font_24};
    app_install(&cfg);
}