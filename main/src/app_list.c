
#include "atmospheric_app.h"
#include "weather_app.h"
#include "mems_app.h"

#include "test_app.h"
#include "muyu_app.h"
#include "pop_cat_app.h"
#include "clock_app.h"
#include "setting_app.h"

#include "watch_01.h"

void app_startup_list() // APP初始化列表
{
    // 无UI底层APP
    atmospheric_app_install(); // 大气压app
    weather_app_install();     // 天气管理app
    mems_app_install();        // 六轴数据app

    // 有UI交互APP
    test_app_install();    // 测试APP
    muyu_app_install();    // 电子木鱼APP
    pop_cat_app_install(); // pop猫APP
    clock_app_install();   // 时钟APP

    setting_app_install(); // 设置APP
}

void desktop_watch_list() // 表盘初始化列表
{
    watch_01_install();
}
