#ifndef lvgl_interface_H
#define lvgl_interface_H

#include "static_include.h"
#include "lcd_driver_interface.h"

#define LVGL_REFRESH_TIME_MS 1
#if LCD_SUPPORT_TE
#define LVGL_BUFFER_SIZE (LCD_H_RES * (LCD_V_RES / 1))
#else
#define LVGL_BUFFER_SIZE (LCD_H_RES * (LCD_V_RES / 4))
#endif

/**
 * @brief 初始化LVGL,注册LCD显示器
 */
void lv_interface_init();

#endif
