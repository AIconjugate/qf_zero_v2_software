#ifndef lv_input_interface_H
#define lv_input_interface_H

#include "static_include.h"

#define TP_I2C_SCL_IO 16      /*!< GPIO number used for I2C master clock */
#define TP_I2C_SDA_IO 15      /*!< GPIO number used for I2C master data  */
#define TP_INTR_GPIO 17       /*!< Touch screen interrupt GPIO number */

#define TP_USE_I2C_NUM 0      /*!< I2C master i2c port number, the number of i2c peripheral interfaces available will depend on the chip */
#define TP_I2C_FREQ_HZ 300000 /*!< I2C master clock frequency */

/**
 * @brief 初始化触摸屏并注册到LVGL
 */
void lv_input_tp_init();

/**
 * @brief 获取输入设备句柄
 * 
 * @return lv_indev_t* 
 */
lv_indev_t *lv_input_get_handle();

#endif
