#include "desktop.h"
#include "system_app.h"

LV_IMG_DECLARE(icon_desktop);
LV_IMG_DECLARE(desktop_wallpaper_dog_fly);

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

typedef enum
{
    watch_last,
    watch_next
} watch_switch_t;

static void gestrue_cb(lv_event_t *e);
static void desktop_load();

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
    printf("switch\n");

    if (type == watch_last)
    {
        if (move->last == NULL)
            return;
        move = move->last;
        return;
    }
    if (move->next == NULL)
        return;
    void (*close_func)() = move->watch.watch_close;
    move = move->next;
    main_page = move->watch.watch_load();
    lv_obj_add_event_cb(main_page, gestrue_cb, LV_EVENT_GESTURE, NULL);
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
    lv_obj_remove_style_all(memu_cont);

    lv_obj_set_style_pad_all(memu_cont, 25, LV_PART_MAIN);
    lv_obj_set_style_pad_row(memu_cont, 10, LV_PART_MAIN);

    lv_obj_set_size(memu_cont, LV_HOR_RES, LV_VER_RES);
    lv_obj_set_flex_flow(memu_cont, LV_FLEX_FLOW_COLUMN);
    lv_obj_add_event_cb(memu_cont, scroll_event_cb, LV_EVENT_SCROLL, NULL);
    lv_obj_set_scroll_dir(memu_cont, LV_DIR_VER);
    lv_obj_set_scroll_snap_y(memu_cont, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(memu_cont, LV_SCROLLBAR_MODE_OFF);

    lv_obj_set_style_bg_img_src(memu_cont, &desktop_wallpaper_dog_fly, LV_PART_MAIN);

    uint32_t i;
    for (i = 0; i < app_get_cnt() - 1; i++)
    {
        app_obj_t *app = app_get(NULL, i);
        if (app->has_gui == 0)
            continue;

        lv_obj_t *btn = lv_btn_create(memu_cont);
        lv_obj_set_style_radius(btn, LV_RADIUS_CIRCLE, LV_PART_MAIN);
        lv_obj_set_width(btn, lv_pct(95));
        lv_obj_set_height(btn, 64 + 8);
        lv_obj_set_style_bg_color(btn, lv_color_hex(0x626973), LV_PART_MAIN);
        lv_obj_set_style_bg_opa(btn, 200, LV_PART_MAIN);

        lv_obj_t *img = lv_img_create(btn);
        if (app->icon != NULL)
            lv_img_set_src(img, app->icon);
        else
            lv_img_set_src(img, &icon_desktop);
        lv_obj_align(img, LV_ALIGN_LEFT_MID, 4, 0);

        lv_obj_t *label = lv_label_create(btn);
        lv_label_set_text(label, app_get_name(i));

        lv_obj_align_to(label, img, LV_ALIGN_OUT_RIGHT_MID, 10, 0);

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
    move = get_watch(desktop_watch_id_save);
    main_page = move->watch.watch_load();
    lv_obj_add_event_cb(main_page, gestrue_cb, LV_EVENT_GESTURE, NULL);
    menu_load();
    key_value_register(NULL, "sys_home", desktop_home_cb);
}

static void desktop_load()
{
    lv_scr_load_anim(main_page, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, 1);
}

static void desktop_close()
{
    // printf("desktop close:%s,%d\n", move->watch->name, (uint32_t)move->watch);

    // printf("fun2:%d,%d\n", (uint32_t)move->watch->watch_close, (uint32_t)move);

    // vTaskDelay(100);

    // if (move != NULL && move->watch.watch_close != NULL)
    //     move->watch.watch_close();
}

static void desktop_kill()
{
    desktop_watch_id_save = move->watch_id;
    printf("desktop kill\n");
}

static void desktop_power_off()
{
    printf("desktop power off\n");
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
        .icon = &icon_desktop,
        .name = "desktop"};
    desktop_id = app_install(&cfg);
}

void desktop_add_watch(desktop_watch_t *watch)
{
    desktop_watch_list_t *tmp = malloc(sizeof(desktop_watch_list_t));
    if (tmp == NULL)
        return;
    static size_t cnt_id = 0;
    tmp->watch = *watch;
    tmp->next = NULL;
    tmp->last = tail;
    tmp->watch_id = cnt_id++;
    tail = tmp;
    if (head == NULL)
    {
        head = tmp;
    }
}