#include "system_app.h"

void app_main(void)
{
    //esp_deep_sleep_start();
    system_init(); // 系统初始化
#if 0
    for (;;)
    {
        vTaskDelay(10);
        // printf("free:%d\n", heap_caps_get_free_size(MALLOC_CAP_8BIT));
        printf("f:%d,%d\n", ets_get_cpu_frequency(),ets_get_apb_freq());
    }
#endif
    vTaskDelete(NULL);
}
