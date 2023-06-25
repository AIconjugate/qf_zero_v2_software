#include "app_manage.h"

#include "usb_trans_app.h"
#include "hc32_trans_app.h"
#include "system_app.h"
#include "btn_event_app.h"
#include "test_app.h"

void app_startup_list()
{
    system_app_install();     // 安装系统APP
    hc32_trans_app_install(); // 安装协处理器通信APP
    usb_trans_app_install();  // 安装串口驱动程序
    btn_event_app_install();  // 安装按键事件管理APP

    test_app_install(); // 测试APP

    app_load("test_app", 0); // 加载测试APP
}
