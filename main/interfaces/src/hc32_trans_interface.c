#include "hc32_trans_interface.h"
#include "lcd_driver_interface.h"

static trans_packer_handle_t *hc32_trans_handle = NULL;

static void hc32_trans_get_handle(void *value, size_t lenth)
{
    trans_packer_handle_t **tmp = value;
    *tmp = hc32_trans_handle;
}

void hc32_trans_send_pack(const char *cmd, uint8_t *dat, size_t lenth)
{
    trans_packer_send_pack(hc32_trans_handle, cmd, dat, lenth);
}

static void rx_task(void *arg)
{
    uint8_t tmp = 0;
    vTaskDelay(1);
    for (;;)
    {
        int rxBytes = uart_read_bytes(HC32_TRANS_UART_NUM, &tmp, 1, portMAX_DELAY);
        if (rxBytes > 0)
        {
            trans_packer_push_byte(hc32_trans_handle, tmp);
        }
    }
}

static void uart_hc32_write_bytes(const char *str, size_t size)
{
    uart_write_bytes(HC32_TRANS_UART_NUM, str, size);
    uart_wait_tx_done(HC32_TRANS_UART_NUM, portMAX_DELAY);
}

void hc32_trans_init()
{

    uart_config_t uartConfig = {
        .baud_rate = hc32_trans_band,
        .data_bits = UART_DATA_8_BITS,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .source_clk = UART_SCLK_XTAL,
    };

    uart_param_config(HC32_TRANS_UART_NUM, &uartConfig);

    uart_set_pin(
        HC32_TRANS_UART_NUM, // UART 编号
        txd_hc32_io,         // TX GPIO
        rxd_hc32_io,         // RX GPIO
        -1,                  // RTS GPIO
        -1                   // CTS GPIO
    );

    uart_driver_install(
        HC32_TRANS_UART_NUM, // UART 编号
        256,                 // Rx 缓冲区大小
        256,                 // Tx 缓冲区大小
        0,                   // 事件队列长度（可以不要，此参数填 0，然后下一个参数填NULL）
        NULL,                //(QueueHandle_t*)接受被创建的句柄的变量指针，类型为FreeRTOS的队列
        0                    // 中断分配标志，这里写 0 表示不想分配中断
    );

    hc32_trans_handle = trans_packer_creat_trans(24, 64, look_cmd);
    trans_packer_set_write_cb(hc32_trans_handle, uart_hc32_write_bytes);
    xTaskCreate(rx_task, "uart_rx_task", 1024 * 4, NULL, configMAX_PRIORITIES, NULL);

    trans_packer_send_pack(hc32_trans_handle, "get_time", NULL, 0);

    key_value_register(NULL, "hc32_handle", hc32_trans_get_handle);
}
