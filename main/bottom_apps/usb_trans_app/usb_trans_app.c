#include "usb_trans_app.h"
#include "system_app.h"

uint8_t key_sta = 1;
uint8_t cnt = 0;

uint8_t get_key_level()
{
    return key_sta;
}

static void usb_chek_app_task(void *arg)
{
    vTaskDelay(1);
    trans_packer_handle_t *handle = NULL;
    key_value_msg("usb_handle", &handle, 0);
    for (;;)
    {
        vTaskDelay(10);
        if (key_sta == 0 && cnt == 0)
            cnt++;
        if (key_sta == 0 && cnt == 4)
        {
            key_sta = 1;
            cnt = 0;
        }
            
        if (trans_packer_get_pack_num(handle))
        {
            const char *name = malloc(trans_packer_get_pack_str_lenth(handle));
            uint8_t *dat = malloc(trans_packer_get_pack_data_lenth(handle));

            trans_packer_get_pack(handle, name, dat);

            if (strcmp(name, "reset") == 0)
            {
                esp_restart();
            }
            else if (strcmp(name, "scan") == 0)
            {

                hc32_trans_send_pack("scan", NULL, 0);
            }

            else if (strcmp(name, "motor") == 0)
            {
                // uint8_t duty;
                // trans_packer_string_to_number((char *)dat, &duty, 1, 0);
                // trans_packer_send_pack(hc32_trans_get_handle(), "set motor", &duty, 1);
            }
            else if (strcmp(name, "time") == 0)
            {
                clock_time_t time;
                uint8_t dat_tmp[7];
                trans_packer_string_to_number((char *)dat, dat_tmp, 1, 0);
                time.year = dat_tmp[0];
                time.month = dat_tmp[1];
                time.day = dat_tmp[2];
                time.hour = dat_tmp[3];
                time.min = dat_tmp[4];
                time.sec = dat_tmp[5];
                system_set_time(time);
            }
            else if (strcmp(name, "key") == 0)
            {
                key_sta = 0;
            }

            free((void *)name);
            free(dat);
        }
    }
}

static void usb_trans_app_init(void *arg)
{
    xTaskCreatePinnedToCore(usb_chek_app_task, "usb_trans", 1024 * 3, NULL, configMAX_PRIORITIES, NULL, 0);
}

void usb_trans_app_install()
{
    app_config_t cfg = {
        .app_close = NULL,
        .app_init = usb_trans_app_init,
        .app_kill = NULL,
        .app_load = NULL,
        .has_gui = 0,
        .icon = NULL,
        .name = "usb_trans"};
    app_install(&cfg,NULL);
}