#ifndef hc32_trans_interface_H
#define hc32_trans_interface_H

#include "static_include.h"

#define txd_hc32_io 2
#define rxd_hc32_io 1

#define HC32_TRANS_UART_NUM UART_NUM_2
#define hc32_trans_band 9600

/**
 * @brief 初始化HC32通信接口
 */
void hc32_trans_init();

#endif
