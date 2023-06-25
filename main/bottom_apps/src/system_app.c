#include "system_app.h"
#include "device_interfaces.h"

/**
 * @brief 系统参数
 */
typedef struct
{
    uint8_t lcd_blk;            // 背光亮度
    clock_time_t time;          // 时间
    uint32_t screen_rest_count; // 休眠计数
    cw2015_bat_info_t bat_info;
} system_data_t;

/**
 * @brief eeprom参数
 */
typedef struct
{
    uint32_t screen_rest_sec; // 休眠时长
} system_eeprom_t;

/**
 * @brief 系统参数
 */
typedef struct
{
    system_data_t data;
    system_eeprom_t eeprom;
} system_paras_t;

static system_paras_t sys_paras;
static RTC_FAST_ATTR uint8_t last_blk = 50;

static void system_data_init()
{
    memset(&sys_paras, 0, sizeof(system_paras_t));
    sys_paras.data.lcd_blk = last_blk;
    sys_paras.eeprom.screen_rest_sec = 5;
}

static void system_data_save()
{
    last_blk = sys_paras.data.lcd_blk;
}

static void clock_run_tsak(void *arg) // 时间运行任务
{
    sys_paras.data.time.sec++;
    if (sys_paras.data.time.sec == 60)
    {
        sys_paras.data.time.sec = 0;
        sys_paras.data.time.min++;
        if (sys_paras.data.time.min == 60)
        {
            sys_paras.data.time.min = 0;
            sys_paras.data.time.hour++;
            if (sys_paras.data.time.hour == 24) // 到新的一天
            {
                sys_paras.data.time.hour = 0;
                trans_packer_handle_t *hanlde;
                key_value_msg("hc32_handle", &hanlde, 0);
                trans_packer_send_pack(hanlde, "get_time", NULL, 0); // 下发指令给副处理器上传时间信息进行同步
            }
        }
    }

    sys_paras.data.screen_rest_count++;
    if (sys_paras.data.screen_rest_count >= sys_paras.eeprom.screen_rest_sec)
    {
        hc32_trans_send_pack("hc_sleep", NULL, 0);
        vTaskDelay(5);
        system_deep_sleep_start();
    }
    cw2015_get_info(&sys_paras.data.bat_info);
}

static void lcd_blk_task(btask_event_t *arg)
{
    static uint8_t now_blk = 0;

    if (now_blk == sys_paras.data.lcd_blk)
        return;
    if (now_blk < sys_paras.data.lcd_blk)
        now_blk++;
    else if (now_blk > sys_paras.data.lcd_blk)
        now_blk--;
    lcd_set_blk(now_blk);
}

// static void per_info_updata_task(btask_event_t *arg)
// {

// }

void system_upload_time(clock_time_t time)
{
    time.week = system_day_count_week(time.year, time.month, time.day);
    sys_paras.data.time = time;
}

static void system_upload_time_cb(void *value, size_t lenth)
{
    system_upload_time(*(clock_time_t *)value);
}

void system_set_time(clock_time_t time)
{
    system_upload_time(time);
    uint8_t tmp[6] = {
        time.year,
        time.month,
        time.day,
        time.hour,
        time.min,
        time.sec};
    hc32_trans_send_pack("set_time", tmp, sizeof(tmp));
}

static void system_set_time_cb(void *value, size_t lenth)
{
    system_set_time(*(clock_time_t *)value);
}

void system_get_time(clock_time_t *time)
{
    *time = sys_paras.data.time;
}

static void system_get_time_cb(void *value, size_t lenth)
{
    *(clock_time_t *)value = sys_paras.data.time;
}

void system_screen_rest_clr()
{
    sys_paras.data.screen_rest_count = 0;
}

static void system_screen_rest_clr_cb(void *value, size_t lenth)
{
    sys_paras.data.screen_rest_count = 0;
}

void system_set_screen_rest(uint32_t rest_sec)
{
    if (rest_sec < 3)
        return;
    sys_paras.eeprom.screen_rest_sec = rest_sec;
    sys_paras.data.screen_rest_count = 0;
}

static void system_set_screen_rest_cb(void *value, size_t lenth)
{
    system_set_screen_rest(*(uint32_t *)value);
}

uint32_t system_get_screen_rest()
{
    return (sys_paras.eeprom.screen_rest_sec);
}

void system_screen_keep_on(uint8_t en)
{
    static uint32_t last_blk_rec = 0;
    static uint8_t _en = 0;
    static uint8_t _busy = 0;

    if (_en == en)
        return;

    while (_busy)
        ;
    _busy = 1;

    _en = en;

    if (en)
    {
        last_blk_rec = system_get_screen_rest();
        system_set_screen_rest(screen_always_on);
    }
    else
    {
        system_screen_rest_clr();
        system_set_screen_rest(last_blk_rec);
    }
    _busy = 0;
}

static void system_screen_keep_on_cb(void *value, size_t lenth)
{
    system_screen_keep_on(*(uint8_t *)value);
}

static void system_get_screen_rest_cb(void *value, size_t lenth)
{
    *(uint32_t *)value = system_get_screen_rest();
}

void system_set_blk(uint8_t blk)
{
    sys_paras.data.lcd_blk = blk;
}

static void system_set_blk_cb(void *value, size_t lenth)
{
    system_set_blk(*(uint8_t *)value);
}

uint8_t system_get_blk()
{
    return sys_paras.data.lcd_blk;
}

static void system_get_blk_cb(void *value, size_t lenth)
{
    *(uint8_t *)value = system_get_blk();
}

void system_upload_bat(cw2015_bat_info_t *info)
{
    sys_paras.data.bat_info = *info;
}

static void system_upload_bat_cb(void *value, size_t lenth)
{
    system_upload_bat((cw2015_bat_info_t *)value);
}

void system_set_bat(uint8_t low_soc)
{
    if (low_soc > 30 || low_soc < 1)
        return;

    sys_paras.data.bat_info.low_soc = low_soc;

    hc32_trans_send_pack("low_soc", &low_soc, sizeof(low_soc));
}

static void system_set_bat_cb(void *value, size_t lenth)
{
    system_set_bat(*(uint8_t *)value);
}

void system_get_bat(cw2015_bat_info_t *info)
{
    *info = sys_paras.data.bat_info;
}

static void system_get_bat_cb(void *value, size_t lenth)
{
    *(cw2015_bat_info_t *)value = sys_paras.data.bat_info;
}

void system_deep_sleep_start()
{
    app_kill_all();
    esp_deep_sleep_start();
}

static void sys_app_init()
{
    system_data_init();
   // xTaskCreatePinnedToCore(clock_run_tsak, "clock_task", 1024 * 4, NULL, configMAX_PRIORITIES, NULL, 0); // 时间运行任务

    const esp_timer_create_args_t ms_tick_timer_args = {// 心跳定时器
                                                        .callback = &clock_run_tsak,
                                                        .name = "clock"};
    esp_timer_handle_t ms_tick_timer = NULL;
    esp_timer_create(&ms_tick_timer_args, &ms_tick_timer);
    esp_timer_start_periodic(ms_tick_timer, 1000 * 1000);

    btask_creat_ms(10, lcd_blk_task, btask_infinite, "lcd_blk_task", NULL); // 背光管理任务
    // /btask_creat_ms(1000, per_info_updata_task, btask_infinite, "lcd_blk_task", NULL);

    key_value_register(NULL, "sys_set_blk", system_set_blk_cb);          // 订阅设置背光事件
    key_value_register(NULL, "sys_get_blk", system_get_blk_cb);          // 订阅获取背光事件
    key_value_register(NULL, "sys_set_rest", system_set_screen_rest_cb); // 订阅设置息屏时间事件
    key_value_register(NULL, "sys_get_rest", system_get_screen_rest_cb); // 订阅设置息屏时间事件
    key_value_register(NULL, "sys_clr_rest", system_screen_rest_clr_cb); // 订阅重置息屏时间事件
    key_value_register(NULL, "sys_always_on", system_screen_keep_on_cb); // 订阅背光常亮事件
    key_value_register(NULL, "sys_up_time", system_upload_time_cb);      // 订阅更新时间事件
    key_value_register(NULL, "sys_set_time", system_set_time_cb);        // 订阅设置时间事件
    key_value_register(NULL, "sys_get_time", system_get_time_cb);        // 订阅获取时间事件
    key_value_register(NULL, "sys_upload_bat", system_upload_bat_cb);    // 订阅更新电池信息事件
    key_value_register(NULL, "sys_set_bat", system_set_bat_cb);          // 订阅设置电池报警值事件
    key_value_register(NULL, "sys_get_bat", system_get_bat_cb);          // 订阅获取电池信息事件
}

static void system_app_kill()
{
    system_data_save();
}

void system_app_install()
{
    app_config_t cfg = {
        .app_close = NULL,
        .app_init = sys_app_init,
        .app_kill = system_app_kill,
        .app_load = NULL,
        .has_gui = 0,
        .icon = NULL,
        .name = "system"};
    app_install(&cfg);
}
