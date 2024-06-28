#include "device_interfaces.h"
#include "hc32_trans_app.h"
#include "system_app.h"

static trans_packer_handle_t *handle = NULL;

static void hc32_trans_app_task(btask_event_t *arg)
{

    if (trans_packer_get_pack_num(handle)) // 有数据包
    {
        const char name[128];
        uint8_t dat[128];

        trans_packer_get_pack(handle, name, dat); // 读出数据包

        if (strcmp_my(name, "bat_info") == 0)
        {
            cw2015_bat_info_t info;
            info.soc = dat[0];
            info.low_soc = dat[1];
            info.voltage = (dat[2] << 8) | dat[3];
            info.rtt = (dat[4] << 8) | dat[5];
            system_upload_bat(&info);
        }
        else if (strcmp_my(name, "time") == 0)
        {
            clock_time_t sys_time;
            sys_time.year = dat[0];
            sys_time.month = dat[1];
            sys_time.day = dat[2];
            sys_time.week = dat[3];
            sys_time.hour = dat[4];
            sys_time.min = dat[5];
            sys_time.sec = dat[6];

            system_upload_time(sys_time);
        }
        else if (strcmp_my(name, "wake_info") == 0)
        {
            printf("wake:%d\n",dat[0]);
        }
        else if (strcmp_my(name, "log") == 0)
        {
            printf("%s\n", dat);
        }
    }
}

static void hc32_trans_app_init(void *arg)
{
    key_value_msg("hc32_handle", &handle, 0);
    btask_creat_ms(10, hc32_trans_app_task, 0, "hc32_trans", NULL);
}

void hc32_trans_app_install()
{
    app_config_t cfg = {
        .app_close = NULL,
        .app_init = hc32_trans_app_init,
        .app_kill = NULL,
        .app_load = NULL,
        .app_power_off = NULL,
        .has_gui = 0,
        .icon = NULL,
        .name = "hc32_trans"};
    app_install(&cfg,NULL);
}
