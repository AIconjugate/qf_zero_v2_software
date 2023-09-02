#include "setting_app.h"
#include "system_app.h"
#include "desktop.h"

LV_IMG_DECLARE(setting_app_icon);
LV_FONT_DECLARE(setting_app_font_24);

static void setting_app_load()
{

    // app_scr_load(scr, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0); // 加载APP界面
}

void setting_app_install()
{
    app_config_t cfg = {
        .app_close = NULL,
        .app_init = NULL,
        .app_kill = NULL,
        .app_load = setting_app_load,
        .app_power_off = NULL,
        .has_gui = 1,
        .icon = &setting_app_icon,
        .name = "设置",
        .name_font = &setting_app_font_24};
    app_install(&cfg);
}