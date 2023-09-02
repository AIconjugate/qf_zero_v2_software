#include "atmospheric_app.h"

static uint32_t step = 0;

static void get_step_cb(void *value, size_t lenth)
{
    *(uint32_t *)value = step++;
}

static void mems_app_init()
{
    key_value_register(NULL, "mems_get_step", get_step_cb);
}

void mems_app_install()
{
    app_config_t cfg = {
        .app_close = NULL,
        .app_init = mems_app_init,
        .app_kill = NULL,
        .app_load = NULL,
        .has_gui = 0,
        .icon = NULL,
        .name = "mems_app",
        .name_font = NULL};
    app_install(&cfg);
}
