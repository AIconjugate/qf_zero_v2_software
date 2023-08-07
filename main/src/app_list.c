
#include "test_app.h"

#include "watch_01.h"
#include "atmospheric_app.h"
#include "weather_app.h"
#include "mems_app.h"

void app_startup_list() // APP初始化列表
{
    atmospheric_app_install(); // 大气压app
    weather_app_install();     // 天气管理app
    test_app_install();        // 测试APP
    mems_app_install();        // 六轴数据app
}

void desktop_watch_list() // 表盘初始化列表
{
    watch_01_install();
}
