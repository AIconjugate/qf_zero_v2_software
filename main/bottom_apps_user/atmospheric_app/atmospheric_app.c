#include "atmospheric_app.h"
#include "system_app.h"

static void get_altitude_cb(void *value, size_t lenth)
{
    float altitude = 0;
    if (bmp280_get_altitude(&altitude) == 0)
    {
        *(int16_t *)value = (int16_t)altitude;
    }
}

static void atmospheric_app_init()
{
    bmp280_trans_cb_t trans = {
        .bmp_read_bytes = senser_iic_read_bytes,
        .bmp_write_byte = senser_iic_write_byte};
    bmp280_attach_trans_cb(&trans);

    bmp280_begin();

    key_value_register(NULL, "altitude_get", get_altitude_cb);
}

static void atmospheric_app_kill()
{
    bmp280_sleep(1);
}

void atmospheric_app_install()
{
    app_config_t cfg = {
        .app_close = NULL,
        .app_init = atmospheric_app_init,
        .app_kill = atmospheric_app_kill,
        .app_load = NULL,
        .has_gui = 0,
        .icon = NULL,
        .name = "atmospheric_app",
        .name_font = NULL};
    app_install(&cfg);
}
