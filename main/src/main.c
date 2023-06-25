#include "system_app.h"

void app_main(void)
{
    system_init(); // 系统初始化
    vTaskDelete(NULL);
}
