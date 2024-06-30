#include "desktop.h"
#include "app_mouse.h"
#include "qf_zero_v2_gui_api_public.h"

LV_IMG_DECLARE(app_mouse_icon);
LV_IMG_DECLARE(app_mouse_img_pointer);
LV_FONT_DECLARE(app_mouse_font_24);

static RTC_FAST_ATTR float mouse_sensity_save = MOUSE_SENSITY_DEFAULT;
static float mouse_sensity = MOUSE_SENSITY_DEFAULT;
static lv_obj_t *point_cuser_obj = NULL;
static key_value_handle_t btn_click_handle = NULL;
static uint8_t mouse_mode = 0;
static uint8_t act_flg = 0;

enum
{
    bcd_minus,
    bcd_plus,
};

float app_mouse_get_sensity(void)
{
    return mouse_sensity;
}

void app_mouse_set_sensity(float sensity)
{
    mouse_sensity = sensity;
    mouse_sensity_save = sensity;
}

uint8_t app_mouse_get_act()
{
    return mouse_mode;
}

static void btn_click_event_cb(void *value, size_t size) // 单击返回桌面
{
    key_value_msg("take_gui_key", NULL, 0);
    lv_scr_load_anim_t anim = LV_SCR_LOAD_ANIM_FADE_ON;
    key_value_msg("sys_home", &anim, sizeof(anim));
    key_value_msg("give_gui_key", NULL, 0);
}

static void tp_mouse_event_cb(void *value, size_t size)
{
    lv_indev_t *indev = NULL; // 触屏输入对象
    key_value_msg("sys_get_tp_indev", &indev, sizeof(lv_indev_t *));

    if (indev != NULL)
    {
        lv_obj_t *img = lv_img_create(lv_scr_act()); // 无鼠标指针对象
        lv_img_set_src(img, &app_mouse_img_pointer); // 设置指针图标
        lv_indev_set_cursor(indev, img);             // 注册指针
        if (point_cuser_obj != NULL)
            lv_obj_del(point_cuser_obj);
        point_cuser_obj = img;
        mouse_mode = 1;
    }
}

static void tp_touch_event_cb(void *value, size_t size)
{
    if (mouse_mode == 0)
        return;

    lv_indev_t *indev = NULL;
    key_value_msg("sys_get_tp_indev", &indev, sizeof(lv_indev_t *));

    lv_obj_t *img = lv_img_create(lv_scr_act());
    lv_indev_set_cursor(indev, img);
    lv_obj_del(point_cuser_obj);
    point_cuser_obj = img;

    mouse_mode = 0;
}

static void event_cb(lv_event_t *e)
{
    uint8_t tp;
    key_value_msg("tp_type", &tp, sizeof(uint8_t));
    if (tp)
        return;
    if (public_lv_obj_get_bcd(e->target) == bcd_minus)
    {
        mouse_sensity -= 0.1;
        if (mouse_sensity < 0.1)
            mouse_sensity = 0.1;
    }
    else if (public_lv_obj_get_bcd(e->target) == bcd_plus)
    {
        mouse_sensity += 0.1;
        if (mouse_sensity > 10.0)
            mouse_sensity = 10.0;
    }
    mouse_sensity_save = mouse_sensity;
    lv_label_set_text_fmt((lv_obj_t *)e->user_data, "%2.1f", mouse_sensity);
}

static void app_load_cb(void *arg)
{

    tp_mouse_event_cb(NULL, 0);

    lv_obj_t *scr = lv_obj_create(NULL);
    lv_obj_clear_flag(scr, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(scr, lv_color_hex(0), LV_PART_MAIN | LV_STATE_DEFAULT);

    // // 创建提示语
    lv_obj_t *label = lv_label_create(scr);
    lv_obj_set_style_text_font(label, &app_mouse_font_24, LV_PART_MAIN);
    lv_label_set_text(label, "灵敏度");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, -50);

    label = lv_label_create(scr);
    lv_obj_set_style_text_font(label, &app_mouse_font_24, LV_PART_MAIN);
    lv_label_set_text(label, "按键退出");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 50);

    lv_obj_t *label_sen = lv_label_create(scr);
    lv_obj_set_style_text_font(label_sen, &app_mouse_font_24, LV_PART_MAIN);
    lv_label_set_text_fmt(label_sen, "%2.1f", mouse_sensity); // 灵敏度
    lv_obj_align(label_sen, LV_ALIGN_CENTER, 0, 0);

    label = lv_label_create(scr);
    lv_obj_set_style_text_font(label, &app_mouse_font_24, LV_PART_MAIN);
    lv_label_set_text(label, "一");
    lv_obj_align(label, LV_ALIGN_CENTER, -50, 0);
    lv_obj_add_flag(label, LV_OBJ_FLAG_CLICKABLE); // 开启地图点击使能
    lv_obj_set_ext_click_area(label, 20);          // 设置点击区域
    public_lv_obj_set_bcd(label, bcd_minus);
    lv_obj_add_event_cb(label, event_cb, LV_EVENT_CLICKED, label_sen); // 按下事件

    label = lv_label_create(scr);
    lv_obj_set_style_text_font(label, &app_mouse_font_24, LV_PART_MAIN);
    lv_label_set_text(label, "十");
    lv_obj_align(label, LV_ALIGN_CENTER, 50, 0);
    lv_obj_add_flag(label, LV_OBJ_FLAG_CLICKABLE); // 开启地图点击使能
    lv_obj_set_ext_click_area(label, 20);          // 设置点击区域
    public_lv_obj_set_bcd(label, bcd_plus);
    lv_obj_add_event_cb(label, event_cb, LV_EVENT_CLICKED, label_sen); // 按下事件

    app_scr_load(scr, LV_SCR_LOAD_ANIM_FADE_ON, 0, 100); // 加载APP界面

    key_value_register(&btn_click_handle, "btn_click", btn_click_event_cb); // 订阅键值对

    act_flg = 1;
}

static void app_close_cb(void *arg)
{
    if (act_flg == 0)
        return;
    act_flg = 0;
    tp_touch_event_cb(NULL, 0);
    key_value_del(btn_click_handle); // 注销键值对
}

static void app_init_cb(void *arg)
{
    mouse_sensity = mouse_sensity_save;
    key_value_register(NULL, "tp_mouse", tp_mouse_event_cb);  // 订阅键值对
    key_value_register(NULL, "tp_touch", tp_touch_event_cb); // 订阅键值对
}

void app_mouse_install()
{
    app_config_t cfg = {
        .app_close = app_close_cb,
        .app_init = app_init_cb,
        .app_kill = NULL,
        .app_load = app_load_cb,
        .app_power_off = NULL,
        .has_gui = 1,
        .icon = &app_mouse_icon,
        .name = "鼠标",
        .name_font = &app_mouse_font_24};
    app_install(&cfg, NULL);
}
