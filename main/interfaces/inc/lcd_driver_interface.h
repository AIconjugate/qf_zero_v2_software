#ifndef lcd_driver_interface_H
#define lcd_driver_interface_H

#include "static_include.h"

#define LCD_H_RES 240 // 水平分辨率
#define LCD_V_RES 240 // 垂直分辨率

#define LCD_PIXEL_CLOCK_HZ (20 * 1000 * 1000) // 总线频率

// 8080接口IO定义
#define LCD_PIN_NUM_DATA0 6
#define LCD_PIN_NUM_DATA1 12
#define LCD_PIN_NUM_DATA2 5
#define LCD_PIN_NUM_DATA3 11
#define LCD_PIN_NUM_DATA4 4
#define LCD_PIN_NUM_DATA5 10
#define LCD_PIN_NUM_DATA6 3
#define LCD_PIN_NUM_DATA7 9
#define LCD_PIN_NUM_PCLK 7
#define LCD_PIN_NUM_CS 14
#define LCD_PIN_NUM_DC 13
#define LCD_PIN_NUM_RST 8
#define LCD_PIN_NUM_BK_LIGHT 45
#define LCD_PIN_NUM_TE 47
#define LCD_PIN_NUM_POWER 41

#define LCD_CMD_BITS 8                                // 指令位宽
#define LCD_PARAM_BITS 8                              // 数据位宽
#define I8080_TRANS_BYTES (LCD_H_RES * LCD_V_RES * 2) // 最大传输字节
#define LCD_BUFFER_USE MALLOC_CAP_INTERNAL            // 使用内存区域

#define LCD_LEDC_TIMER LEDC_TIMER_1         // ledc定时器通道
#define LCD_LEDC_MODE LEDC_LOW_SPEED_MODE   // 定时器模式
#define LCD_LEDC_CHANNEL LEDC_CHANNEL_2     // 通道
#define LCD_LEDC_DUTY_RES LEDC_TIMER_10_BIT // 分辨率
#define LCD_LEDC_FREQUENCY (1000)           // 频率

/**
 * @brief 初始化LCD
 */
void lcd_driver_init();

/**
 * @brief 设置背光亮度
 *
 * @param var 1-100
 */
void lcd_set_blk(uint8_t var);

/**
 * @brief 获取背光亮度
 *
 * @return uint8_t 1-100
 */
uint8_t lcd_get_blk();

/**
 * @brief 获取lcd对象
 *
 * @return lv_disp_drv_t*
 */
lv_disp_drv_t *lcd_get_disp_drv();

/**
 * @brief 获取LCD驱动器总线对象
 * 
 * @return esp_lcd_panel_handle_t 
 */
esp_lcd_panel_handle_t lcd_get_panel_handle();

/**
 * @brief LVGL刷屏回调函数
 *
 * @param drv
 * @param area
 * @param color_map
 */
void lcd_lvgl_flush_cb(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_map);


#endif
