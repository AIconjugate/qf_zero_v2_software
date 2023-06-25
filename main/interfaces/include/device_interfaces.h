#ifndef device_interfaces_H
#define device_interfaces_H

#include "static_include.h"
#include "lcd_driver_interface.h"
#include "hc32_trans_interface.h"
#include "usb_trans_interface.h"
#include "senser_iic_interface.h"
#include "peripheral_interface.h"
#include "lvgl_interface.h"
#include "lv_input_interface.h"

/**
 * @brief 初始化设备接口
 */
void device_interface_init();

#endif
