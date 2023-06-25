#include "usb_trans_interface.h"

static trans_packer_handle_t *usb_trans_handle = NULL;

static void usb_trans_get_handle(void *value, size_t lenth)
{
    trans_packer_handle_t **tmp = value;
    *tmp = usb_trans_handle;
}

static void rx_task(void *arg)
{
    uint8_t tmp = 0;
    vTaskDelay(1);
    for (;;)
    {
        int rxBytes = uart_read_bytes(USB_TRANS_UART_NUM, &tmp, 1, portMAX_DELAY);
        if (rxBytes > 0)
            trans_packer_push_byte(usb_trans_handle, tmp);
    }
}

// static void uart_usb_write_bytes(const char *str, size_t size)
// {
//     uart_write_bytes(UART_NUM_0, str, size);
//     uart_wait_tx_done(UART_NUM_0, portMAX_DELAY);
// }

void usb_trans_init()
{
    uart_config_t uartConfig = {
        .baud_rate = usb_trans_band_default,
        .data_bits = UART_DATA_8_BITS,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .source_clk = UART_SCLK_APB,
    };

    uart_param_config(USB_TRANS_UART_NUM, &uartConfig);

    uart_set_pin(
        USB_TRANS_UART_NUM, // UART 编号
        usb_trans_txd_io,   // TX GPIO
        usb_trans_rxd_io,   // RX GPIO
        -1,                 // RTS GPIO
        -1                  // CTS GPIO
    );

    uart_driver_install(
        USB_TRANS_UART_NUM, // UART 编号
        256,                // Rx 缓冲区大小
        256,                // Tx 缓冲区大小
        0,                  // 事件队列长度（可以不要，此参数填 0，然后下一个参数填NULL）
        NULL,               //(QueueHandle_t*)接受被创建的句柄的变量指针，类型为FreeRTOS的队列
        0                   // 中断分配标志，这里写 0 表示不想分配中断
    );

    usb_trans_handle = trans_packer_creat_trans(64, 128, look_string);
    xTaskCreatePinnedToCore(rx_task, "uart_usb_rx", 1024 * 4, NULL, configMAX_PRIORITIES - 1, NULL, 0);

    key_value_register(NULL, "usb_handle", usb_trans_get_handle);
}
