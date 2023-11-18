#include "desktop.h"
#include "system_app.h"

#if !QF_ZERO_V2_DESKTOP_HIDDEN_EN
LV_IMG_DECLARE(icon_desktop);
LV_IMG_DECLARE(desktop_img_set_blk);
#endif

static lv_obj_t *memu_cont = NULL;
static lv_obj_t *main_page = NULL;
static app_handle_t desktop_id;

typedef struct _desktop_watch_list_t
{
    desktop_watch_t watch;
    size_t watch_id;
    struct _desktop_watch_list_t *next;
    struct _desktop_watch_list_t *last;
} desktop_watch_list_t;

static desktop_watch_list_t *head = NULL;
static desktop_watch_list_t *tail = NULL;
static desktop_watch_list_t *move = NULL;
static RTC_FAST_ATTR size_t desktop_watch_id_save = 0;
static size_t watch_cnt = 0;

typedef enum
{
    watch_last,
    watch_next
} watch_switch_t;

typedef struct
{
    uint8_t sta : 1;        // 是否开启修改
    uint8_t change_flg : 1; // 状态更改标志
    uint8_t use_en : 1;
} blk_sta_t;

static blk_sta_t blk;
static key_value_handle_t tp_double_handle = NULL;
static lv_timer_t *btn_timer = NULL;

static void gestrue_cb(lv_event_t *e);
static void desktop_load();

static void tp_double_cb(void *value, size_t lenth) // 有双击
{
    blk.change_flg = 1; // 状态改变
    blk.sta = 1;        // 开启亮度修改
}

static void scr_pressed_cb(lv_event_t *e) // 点击空白处
{
    blk.change_flg = 1; // 状态改变
    blk.sta = 0;
}

static void set_blk_slider_cb(lv_event_t *e)
{
    uint8_t tmp = lv_slider_get_value(e->target);
    key_value_msg("sys_set_blk", &tmp, 1);
}

static void btn_timer_cb(lv_timer_t *e)
{
    if (blk.change_flg == 0) // 状态未改变
        return;
    blk.change_flg = 0; // 状态改变

    if (blk.use_en == 0)
        return;

    static lv_obj_t *slider = NULL;

    if (blk.sta == 1) // 开始编辑
    {
        if (slider != NULL)
            return;

        slider = lv_slider_create(lv_scr_act());
        lv_obj_set_size(slider, 180, 100);
        lv_obj_center(slider);
        lv_obj_remove_style(slider, NULL, LV_PART_KNOB);
        lv_obj_set_style_bg_color(slider, lv_color_hex(0x3B3B3B), LV_PART_MAIN);
        lv_obj_set_style_bg_opa(slider, 255, LV_PART_MAIN);
        lv_obj_set_style_bg_color(slider, lv_color_hex(0xffffff), LV_PART_INDICATOR);
        lv_obj_set_style_radius(slider, 20, LV_PART_INDICATOR);
        lv_slider_set_range(slider, 1, 100);
        uint8_t tmp = 0;
        key_value_msg("sys_get_blk", &tmp, 1);
        lv_slider_set_value(slider, tmp, LV_ANIM_OFF);
        lv_obj_add_event_cb(slider, set_blk_slider_cb, LV_EVENT_VALUE_CHANGED, NULL);

#if !QF_ZERO_V2_DESKTOP_HIDDEN_EN
        lv_obj_t *img = lv_img_create(slider);
        lv_img_set_src(img, &desktop_img_set_blk);
        lv_obj_center(img);
#endif
        return;
    }

    if (slider == NULL)
        return;

    lv_obj_del(slider);
    slider = NULL;
}

static void load_end_cb(lv_event_t *e)
{
    blk.change_flg = 0;
    blk.use_en = 1;
    key_value_register(&tp_double_handle, "tp_double", tp_double_cb);
    btn_timer = lv_timer_create(btn_timer_cb, 20, NULL);
    lv_timer_set_repeat_count(btn_timer, -1);
}

static desktop_watch_list_t *get_watch(size_t id)
{
    desktop_watch_list_t *tmp = head;
    for (size_t i = 0; i < id; i++)
    {
        tmp = tmp->next;
    }
    return tmp;
}

static void watch_switch(watch_switch_t type)
{

    if (blk.sta)
        return;

    if (move == NULL)
        return;

    void (*close_func)() = move->watch.watch_close;

    if (type == watch_last)
    {
        if (move->last == NULL)
            return;
        move = move->last;
    }
    else
    {
        if (move->next == NULL)
            return;
        move = move->next;
    }

    main_page = move->watch.watch_load();
    lv_obj_add_event_cb(main_page, load_end_cb, LV_EVENT_SCREEN_LOADED, NULL);
    lv_obj_add_event_cb(main_page, gestrue_cb, LV_EVENT_GESTURE, NULL);
    lv_obj_add_event_cb(main_page, scr_pressed_cb, LV_EVENT_PRESSED, NULL);
    desktop_load();
    close_func();
}

static void gestrue_cb(lv_event_t *e)
{

    switch (lv_indev_get_gesture_dir(lv_indev_get_act()))
    {
    case LV_DIR_LEFT:
        if (lv_scr_act() == main_page)
        {
            watch_switch(watch_next);
        }
        else
        {
            lv_scr_load_anim(main_page, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 100, 0, 0);
        }

        break;
    case LV_DIR_RIGHT:
        if (lv_scr_act() == main_page)
        {
            watch_switch(watch_last);
        }
        else
        {
            lv_scr_load_anim(main_page, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 100, 0, 0);
        }
        break;
    case LV_DIR_TOP:
        if (lv_scr_act() == main_page)
        {
            blk.use_en = 0;

            lv_scr_load_anim(memu_cont, LV_SCR_LOAD_ANIM_MOVE_TOP, 100, 0, 0);
        }

        break;
    case LV_DIR_BOTTOM:
        // if (lv_scr_act() == memu_cont)
        // {
        //     lv_scr_load_anim(main_page, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 100, 0, 0);
        // }
        break;
    default:
        break;
    }
}

static void scroll_event_cb(lv_event_t *e)
{

    lv_obj_t *cont = lv_event_get_target(e);

    lv_area_t cont_a;
    lv_obj_get_coords(cont, &cont_a);
    lv_coord_t cont_y_center = cont_a.y1 + lv_area_get_height(&cont_a) / 2;

    lv_coord_t r = lv_obj_get_height(cont) * 7 / 10;
    uint32_t i;
    uint32_t child_cnt = lv_obj_get_child_cnt(cont);
    for (i = 0; i < child_cnt; i++)
    {
        lv_obj_t *child = lv_obj_get_child(cont, i);
        lv_area_t child_a;
        lv_obj_get_coords(child, &child_a);

        lv_coord_t child_y_center = child_a.y1 + lv_area_get_height(&child_a) / 2;

        lv_coord_t diff_y = child_y_center - cont_y_center;
        diff_y = LV_ABS(diff_y);

        /*Get the x of diff_y on a circle.*/
        lv_coord_t x;
        /*If diff_y is out of the circle use the last point of the circle (the radius)*/
        if (diff_y >= r)
        {
            x = r;
        }
        else
        {
            /*Use Pythagoras theorem to get x from radius and y*/
            uint32_t x_sqr = r * r - diff_y * diff_y;
            lv_sqrt_res_t res;
            lv_sqrt(x_sqr, &res, 0x8000); /*Use lvgl's built in sqrt root function*/
            x = r - res.i;
        }

        /*Translate the item by the calculated X coordinate*/
        lv_obj_set_style_translate_x(child, x, 0);

        /*Use some opacity with larger translations*/
        lv_opa_t opa = lv_map(x, 0, r, LV_OPA_TRANSP, LV_OPA_COVER);
        lv_obj_set_style_opa(child, LV_OPA_COVER - opa, 0);
    }
}

static void desktop_home_cb(void *value, size_t lenth)
{
    if (app_get_handle(app_get_loaded()->name) == desktop_id)
        return;
    app_load("desktop", app_none);
}

static void app_click_cb(lv_event_t *e)
{
    uint8_t tmp;
    key_value_msg("tp_type", &tmp, 1); // 获取屏幕操作是否为点击
    if (tmp)                           // 如果有滑动
    {
        return; // 丢弃CLICK操作
    }
    printf("app name:%s\n", (const char *)e->user_data);
    app_load((const char *)e->user_data, app_none);
}

static void menu_load(void)
{
    memu_cont = lv_obj_create(NULL);

    lv_obj_set_style_pad_all(memu_cont, 25, LV_PART_MAIN);
    lv_obj_set_style_pad_row(memu_cont, 10, LV_PART_MAIN);

    lv_obj_set_size(memu_cont, LV_HOR_RES, LV_VER_RES);
    lv_obj_set_flex_flow(memu_cont, LV_FLEX_FLOW_COLUMN);
    lv_obj_add_event_cb(memu_cont, scroll_event_cb, LV_EVENT_SCROLL, NULL);
    lv_obj_set_scroll_dir(memu_cont, LV_DIR_VER);
    lv_obj_set_scroll_snap_y(memu_cont, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(memu_cont, LV_SCROLLBAR_MODE_OFF);

// lv_obj_set_style_bg_color(memu_cont, lv_color_hex(0), 0);
#if !QF_ZERO_V2_DESKTOP_HIDDEN_EN
    lv_obj_set_style_bg_img_src(memu_cont, &desktop_bg_default, LV_PART_MAIN);
#endif

    uint32_t i;
    for (i = 0; i < app_get_cnt() - 1; i++)
    {
        app_obj_t *app = app_get(NULL, i);
        if (app->has_gui == 0)
            continue;

        lv_obj_t *btn = lv_btn_create(memu_cont);
        lv_obj_set_style_radius(btn, LV_RADIUS_CIRCLE, LV_PART_MAIN);
        lv_obj_set_width(btn, lv_pct(98));
        lv_obj_set_height(btn, 40);
        lv_obj_set_style_bg_color(btn, lv_color_hex(0x626973), LV_PART_MAIN);
        lv_obj_set_style_bg_opa(btn, 200, LV_PART_MAIN);

        lv_obj_t *img = lv_img_create(btn);
        if (app->icon != NULL)
            lv_img_set_src(img, app->icon);
#if !QF_ZERO_V2_DESKTOP_HIDDEN_EN
        else
            lv_img_set_src(img, &icon_desktop);
#endif
        lv_obj_align(img, LV_ALIGN_LEFT_MID, 3, 0);

        lv_obj_t *label = lv_label_create(btn);
        lv_label_set_text(label, app_get_name(i));

        if (app->name_font != NULL)
            lv_obj_set_style_text_font(label, (const lv_font_t *)app->name_font, 0);

        lv_obj_align_to(label, img, LV_ALIGN_OUT_RIGHT_MID, 5, 0);

        lv_obj_add_event_cb(btn, app_click_cb, LV_EVENT_CLICKED, (void *)app_get_name(i));
    }

    /*Update the buttons position manually for first*/
    lv_event_send(memu_cont, LV_EVENT_SCROLL, NULL);

    /*Be sure the fist button is in the middle*/
    lv_obj_scroll_to_view(lv_obj_get_child(memu_cont, 0), LV_ANIM_OFF);

    lv_obj_add_event_cb(memu_cont, gestrue_cb, LV_EVENT_GESTURE, NULL);
}

static void desktop_init()
{
    desktop_watch_list();
    if (watch_cnt == 0)
    {
        main_page = lv_obj_create(NULL);
    }
    else
    {
        move = get_watch(desktop_watch_id_save);
        main_page = move->watch.watch_load();
    }
    lv_obj_add_event_cb(main_page, load_end_cb, LV_EVENT_SCREEN_LOADED, NULL);
    lv_obj_add_event_cb(main_page, gestrue_cb, LV_EVENT_GESTURE, NULL);
    lv_obj_add_event_cb(main_page, scr_pressed_cb, LV_EVENT_PRESSED, NULL);
    menu_load();
    key_value_register(NULL, "sys_home", desktop_home_cb);
}

static void desktop_load()
{
    lv_scr_load_anim(main_page, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, 1);
}

static void desktop_close()
{
    if (btn_timer != NULL)
    {
        lv_timer_del(btn_timer);
        btn_timer = NULL;
    }
    if (tp_double_handle != NULL)
    {
        key_value_del(tp_double_handle);
        tp_double_handle = NULL;
    }

    // printf("desktop close:%s,%d\n", move->watch->name, (uint32_t)move->watch);

    // printf("fun2:%d,%d\n", (uint32_t)move->watch->watch_close, (uint32_t)move);

    // vTaskDelay(100);

    // if (move != NULL && move->watch.watch_close != NULL)
    //     move->watch.watch_close();
}

static void desktop_kill()
{
    if (move == NULL)
        return;
    desktop_watch_id_save = move->watch_id;
    printf("desktop kill\n");
}

static void desktop_power_off()
{
    printf("desktop power off\n");
}

void app_scr_load(lv_obj_t *scr, lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay)
{
    lv_scr_load_anim(scr, anim_type, time, delay, false); // 加载界面
}

void desktop_app_install()
{
    app_config_t cfg = {
        .app_close = desktop_close,
        .app_init = desktop_init,
        .app_kill = desktop_kill,
        .app_load = desktop_load,
        .app_power_off = desktop_power_off,
        .has_gui = 1,
#if QF_ZERO_V2_DESKTOP_HIDDEN_EN
        .icon = NULL,
#else
        .icon = &icon_desktop,
#endif
        .name = "desktop",
        .name_font = NULL
    };
    desktop_id = app_install(&cfg);
}

void desktop_add_watch(desktop_watch_t *watch)
{
    desktop_watch_list_t *tmp = malloc(sizeof(desktop_watch_list_t));
    if (tmp == NULL)
        return;
    tmp->watch = *watch;
    tmp->next = NULL;
    tmp->last = tail;
    tmp->watch_id = watch_cnt++;
    if (tail != NULL)
    {
        tail->next = tmp;
    }
    tail = tmp;
    if (head == NULL)
    {
        head = tmp;
    }
}