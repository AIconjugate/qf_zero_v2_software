#ifndef lvgl_interface_H
#define lvgl_interface_H

#include "static_include.h"

#define LVGL_TASK_ON_CORE 1
#define LVGL_REFRESH_TIME_MS 10

/**
 * @brief 初始化LVGL,注册LCD显示器
 */
void lv_interface_init();

#endif
