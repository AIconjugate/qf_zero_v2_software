#include "yuanshen_app.h"
#include "system_app.h"
#include "desktop.h"

LV_IMG_DECLARE(yuanshen_app_img_icon);
LV_IMG_DECLARE(yuanshen_app_img_load);
LV_IMG_DECLARE(yuanshen_app_img_byebye);
LV_FONT_DECLARE(yuanshen_app_font_24);

static uint8_t act_flg = 0;

static void ui_event(lv_event_t *e)
{
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

static void lv_timer_cb(lv_timer_t *e)
{
    if (act_flg == 0)
    {
        lv_timer_del(e);
        return;
    }
    lv_obj_t *img = (lv_obj_t *)e->user_data;
    uint16_t opa = lv_obj_get_style_img_opa(img, LV_PART_MAIN);
    static uint8_t cnt = 0;
    static uint16_t motor_cnt = 0;

    if(opa == 0)
        motor_cnt = 0;

    if (opa < 255)
    {
        opa += 3;
        if (opa >= 255)
        {
            opa = 255;
            cnt = 0;
        }
        lv_obj_set_style_img_opa(img, opa, LV_PART_MAIN);
    }
    else
    {
        cnt++;
        if (cnt == 125)
        {
            lv_img_set_src(img, &yuanshen_app_img_byebye);
            lv_timer_del(e);
        }
    }

    motor_cnt++;

    if (motor_cnt == 14)
    {
        uint8_t motor = 30;
        key_value_msg("sys_set_motor", &motor, 1);
    }
    if (motor_cnt == 30)
    {
        uint8_t motor = 0;
        key_value_msg("sys_set_motor", &motor, 1);
    }
    if (motor_cnt == 40)
    {
        uint8_t motor = 30;
        key_value_msg("sys_set_motor", &motor, 1);
    }
    if (motor_cnt == 55)
    {
        uint8_t motor = 0;
        key_value_msg("sys_set_motor", &motor, 1);
    }

    if (motor_cnt == 100)
    {
        uint8_t motor = 80;
        key_value_msg("sys_set_motor", &motor, 1);
    }
    if (motor_cnt == 115)
    {
        uint8_t motor = 0;
        key_value_msg("sys_set_motor", &motor, 1);
    }
    if (motor_cnt == 125)
    {
        uint8_t motor = 100;
        key_value_msg("sys_set_motor", &motor, 1);
    }
    if (motor_cnt == 185)
    {
        uint8_t motor = 0;
        key_value_msg("sys_set_motor", &motor, 1);
    }
}

static void yuanshen_app_load()
{
    lv_obj_t *scr = lv_obj_create(NULL);

    lv_obj_clear_flag(scr, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(scr, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *img = lv_img_create(scr);

    lv_img_set_src(img, &yuanshen_app_img_load);
    lv_obj_clear_flag(img, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_align(img, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_img_opa(img, 0, LV_PART_MAIN);

    lv_timer_t *timer = lv_timer_create(lv_timer_cb, 16, img);
    lv_timer_set_repeat_count(timer, -1);

    lv_obj_add_event_cb(scr, ui_event, LV_EVENT_ALL, img);

    app_scr_load(scr, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0); // 加载APP界面

    act_flg = 1;
}

static void yuanshen_app_close()
{
    act_flg = 0;
}

void yuanshen_app_install()
{
    app_config_t cfg = {
        .app_close = yuanshen_app_close,
        .app_init = NULL,
        .app_kill = NULL,
        .app_load = yuanshen_app_load,
        .app_power_off = NULL,
        .has_gui = 1,
        .icon = &yuanshen_app_img_icon,
        .name = "原神",
        .name_font = &yuanshen_app_font_24};
    app_install(&cfg);
}