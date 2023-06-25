#ifndef static_include_H
#define static_include_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include "sdkconfig.h"
#include "driver/gpio.h"
#include "esp_err.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_sleep.h"
#include "hal/ledc_hal.h"
#include "driver/spi_master.h"
#include "driver/ledc.h"
#include "esp_intr_alloc.h"
#include "soc/uart_struct.h"
#include "hal/uart_ll.h"
#include "driver/uart.h"
#include "freertos/queue.h"
#include "driver/i2c.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif
#include "cst816.h"
#include "esp_lcd_panel_gc9a01.h"
#include "ring_buffer.h"
#include "trans_packer.h"
#include "BMP280.h"
#include "button.h"
#include "myprintf.h"
#include "cw2015.h"
#include "beat_task.h"
#include "key_value_transation.h"
#include "app_manage.h"
#include "fast_lib.h"


#endif
