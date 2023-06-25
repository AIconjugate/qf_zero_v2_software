#ifndef hc32_trans_interface_H
#define hc32_trans_interface_H

#include "static_include.h"

#define txd_hc32_io 2
#define rxd_hc32_io 1

#define esp_printf_io 46
#define esp_sta_io 42

#define HC32_TRANS_UART_NUM UART_NUM_2
#define hc32_trans_band 9600

/**
 * @brief 初始化HC32通信接口
 */
void hc32_trans_init();

/**
 * @brief 副处理器指令接口
 *
 * @param cmd 指令名
 * @param dat 数据
 * @param lenth 数据长度，字节
 */
void hc32_trans_send_pack(const char *cmd, uint8_t *dat, size_t lenth);

#endif
