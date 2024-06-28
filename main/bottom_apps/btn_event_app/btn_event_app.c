#include "btn_event_app.h"
#include "system_app.h"
#include "static_include.h"

static uint8_t gameing = 0;

static void btn_app_game_mode_cb(void *arg, size_t size)
{
    gameing = *(uint8_t *)arg;
}

static void btn_event_task(btask_event_t *arg)
{
    if (btn_available() == 0)
        return;
    btn_event_t ret;
    btn_read_event(NULL, &ret);

    // key_value_msg("sys_btn", &ret, sizeof(btn_event_t));

    if (ret == btn_down)
    {
        system_screen_keep_on(1);
        key_value_msg("btn_down", NULL, 0);
    }
    else if (ret == btn_up)
    {
        system_screen_keep_on(0);
        key_value_msg("btn_up", NULL, 0);
    }
    else if (ret == btn_double_click)
    {
        if (gameing == 0)
            key_value_msg("sys_home", NULL, 0);
        key_value_msg("btn_double", NULL, 0);
    }
    else if (ret == btn_long_press)
    {
        key_value_msg("btn_long", NULL, 0);
    }
    else if (ret == btn_click)
    {
        if (memcmp(app_get_loaded()->name, "desktop", 7) == 0)
            key_value_msg("sys_sleep", NULL, 0);
        else
            key_value_msg("btn_click", NULL, 0);
    }
}

static void btn_event_app_init(void *arg)
{
    btask_creat_ms(20, btn_event_task, 0, "btn_event", NULL);
    key_value_register(NULL, "game_mode", btn_app_game_mode_cb);
}

void btn_event_app_install()
{
    app_config_t cfg = {
        .app_close = NULL,
        .app_init = btn_event_app_init,
        .app_kill = NULL,
        .app_load = NULL,
        .app_power_off = NULL,
        .has_gui = 0,
        .icon = NULL,
        .name = "btn_event"};
    app_install(&cfg, NULL);
}