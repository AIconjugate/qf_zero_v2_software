#ifndef usb_trans_interface_H
#define usb_trans_interface_H

#include "static_include.h"

#define usb_trans_txd_io 43
#define usb_trans_rxd_io 44

#define USB_TRANS_UART_NUM UART_NUM_0
#define usb_trans_band_default 115200

/**
 * @brief 初始化usb通信接口
 */
void usb_trans_init();

#endif
