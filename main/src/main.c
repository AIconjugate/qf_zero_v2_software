#include "system_app.h"

void app_main(void)
{
    system_init(); // 系统初始化
#if 0
    for (;;)
    {
        vTaskDelay(1000);
        printf("free:%d\n", heap_caps_get_free_size(MALLOC_CAP_8BIT));
    }
#endif
    vTaskDelete(NULL);
}
