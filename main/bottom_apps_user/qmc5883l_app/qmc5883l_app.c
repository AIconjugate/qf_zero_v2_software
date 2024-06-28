#include "qmc5883l_app.h"
#include "system_app.h"

static uint8_t qmc_use_flg = 0;
static RTC_FAST_ATTR qmc_xyz_range_t range = {-6595, 4205, -115, 11277, -775, 10750};

static void calibration_updata_task(btask_event_t *e)
{
    qmc5883l_get_xyz(NULL, NULL, NULL);
}

static void bt_get_angle(btask_event_t *e)
{
    *(int16_t *)e->userdata = qmc5883l_get_angle();
}

static void get_angle_cb(void *value, size_t lenth)
{
    static int16_t angle = 0;
    if (qmc_use_flg == 0)
    {
        qmc_use_flg = 1;
        qmc5883l_begin(qmc_mode_continuous, qmc_odr_200hz, qmc_range_2g, qmc_osr_512);
    }
    btask_creat_ms(1, bt_get_angle, 1, "qmc0", &angle);
    *(int16_t *)value = angle;
}

static void get_range_cb(void *value, size_t lenth)
{
    *(qmc_xyz_range_t *)value = qmc5883l_get_xyz_range();
}

static void calibration_cb(void *value, size_t lenth)
{
    uint8_t flg = *(uint8_t *)value;
    if (qmc_use_flg == 0)
    {
        qmc_use_flg = 1;
        qmc5883l_begin(qmc_mode_continuous, qmc_odr_200hz, qmc_range_2g, qmc_osr_512);
    }
    qmc5883l_xyz_range_updata(flg);
    if (flg)
    {
        if (btask_has_task(NULL, "qmc1"))
            return;
        btask_creat_ms(5, calibration_updata_task, 0, "qmc1", NULL);
    }
    else
    {
        if (btask_has_task(NULL, "qmc1") == 0)
            return;
        btask_del(NULL, "qmc1");
        range = qmc5883l_get_xyz_range();
        qmc5883l_set_calibration(&range);
    }
}

static void app_init(void *arg)
{
    qmc5883l_set_calibration(&range);

    key_value_register(NULL, "qmc_get_angle", get_angle_cb);
    key_value_register(NULL, "qmc_get_range", get_range_cb);
    key_value_register(NULL, "qmc_calibration", calibration_cb);
}

static void app_kill_cb(void *arg)
{
    qmc5883l_sleep(1);
}

void qmc5883l_app_install()
{
    app_config_t cfg = {
        .app_close = NULL,
        .app_init = app_init,
        .app_kill = app_kill_cb,
        .app_load = NULL,
        .has_gui = 0,
        .app_power_off = NULL,
        .icon = NULL,
        .name = "qmc5883l_app",
        .name_font = NULL};
    app_install(&cfg,NULL);
}
