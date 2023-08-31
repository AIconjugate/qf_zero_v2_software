#ifndef peripheral_interface_H
#define peripheral_interface_H

#include "static_include.h"

#define MOTOR_IO 48
#define USB_ONLINE_IO 38
#define ESP_PRINT_IO 46

#define MOTOR_LEDC_TIMER LEDC_TIMER_0         // MOTOR定时器通道
#define MOTOR_LEDC_MODE LEDC_LOW_SPEED_MODE   // 定时器模式
#define MOTOR_LEDC_CHANNEL LEDC_CHANNEL_0     // 通道
#define MOTOR_LEDC_DUTY_RES LEDC_TIMER_8_BIT // 分辨率
#define MOTOR_LEDC_FREQUENCY (1000)           // 频率

#define BOTTON_IO 39
#define BOTTON_TIC_MS 5 //按键扫描心跳速度

/**
 * @brief 初始化外围设备
 */
void per_init();

/**
 * @brief 设置振动器强度
 * 
 * @param var 0-100
 */
void per_motor_set(uint8_t var);

/**
 * @brief 获取usb插入状态
 * 
 * @return uint8_t 1:已连接，0：未连接
 */
uint8_t per_get_usb_online_sta();

#endif
