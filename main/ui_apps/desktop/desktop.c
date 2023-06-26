#include "desktop.h"
#include "system_app.h"

LV_IMG_DECLARE(icon_desktop);

static lv_obj_t *obj_desktop = NULL;

static void tic_cb(btask_event_t *e)
{
    printf("free internal heap:%d\n", heap_caps_get_free_size(MALLOC_CAP_INTERNAL));
}

static void desktop_init()
{
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

/**
 * Translate the object as they scroll
 */
void lv_example_scroll_6(void)
{
    lv_obj_t *cont = lv_obj_create(lv_scr_act());
    lv_obj_set_size(cont, LV_HOR_RES, LV_VER_RES);
    lv_obj_center(cont);
    lv_obj_set_flex_flow(cont, LV_FLEX_FLOW_COLUMN);
    lv_obj_add_event_cb(cont, scroll_event_cb, LV_EVENT_SCROLL, NULL);
    lv_obj_set_scroll_dir(cont, LV_DIR_VER);
    lv_obj_set_scroll_snap_y(cont, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(cont, LV_SCROLLBAR_MODE_OFF);

    uint32_t i;
    for (i = 0; i < app_get_cnt(); i++)
    {

        lv_obj_t *btn = lv_btn_create(cont);
        lv_obj_set_style_radius(btn, LV_RADIUS_CIRCLE, LV_PART_MAIN);
        // lv_obj_set_width(btn, lv_pct(80));
        // lv_obj_set_height(btn, 80);
        lv_obj_set_style_bg_color(btn, lv_color_hex(0x626973), LV_PART_MAIN);

        app_obj_t *app = app_get(NULL, i);

        lv_obj_t *img = lv_img_create(btn);
        if (app->icon != NULL)
            lv_img_set_src(img, app->icon);
        else
            lv_img_set_src(img, &icon_desktop);

        lv_obj_t *label = lv_label_create(btn);
        lv_label_set_text(label, app_get_name(i));

        lv_obj_align_to(label, img, LV_ALIGN_OUT_RIGHT_MID, 10, 0);
    }

    /*Update the buttons position manually for first*/
    lv_event_send(cont, LV_EVENT_SCROLL, NULL);

    /*Be sure the fist button is in the middle*/
    lv_obj_scroll_to_view(lv_obj_get_child(cont, 0), LV_ANIM_OFF);
}

static void img_icon_cb(lv_event_t *e)
{
    lv_obj_add_flag(e->target, LV_OBJ_FLAG_HIDDEN);
    lv_example_scroll_6();
}

static void cb_test(lv_timer_t *e)
{
    static int16_t y = 120;
    lv_obj_set_y((lv_obj_t *)e->user_data, y);
    y++;
    if (y > 240)
        y = -64;
}

static void desktop_load()
{
    uint8_t blk = 100;
    key_value_msg("sys_set_blk", &blk, 1);

    system_take_gui_key();

    obj_desktop = lv_obj_create(NULL);
    lv_obj_set_size(obj_desktop, LV_HOR_RES, LV_VER_RES);
    lv_obj_set_scrollbar_mode(obj_desktop, LV_SCROLLBAR_MODE_OFF);
    lv_obj_clear_flag(obj_desktop, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_t *img = lv_img_create(obj_desktop);
    lv_img_set_src(img, &icon_desktop);

    lv_obj_set_x(img, 120 - 32);

    lv_obj_add_flag(img, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_add_event_cb(img, img_icon_cb, LV_EVENT_CLICKED, img);

    lv_scr_load_anim(obj_desktop, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, 1);

    system_give_gui_key();

    lv_timer_create(cb_test, 10, img);

    btask_creat(1, tic_cb, 0, NULL, NULL);
}

static void desktop_close()
{
}

static void desktop_kill()
{
}

static void desktop_power_off()
{
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
    app_install(&cfg);
}