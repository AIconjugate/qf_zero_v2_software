#ifndef senser_iic_interface_H
#define senser_iic_interface_H

#include "static_include.h"

#define SENSER_I2C_SCL_IO 19 /*!< GPIO number used for I2C master clock */
#define SENSER_I2C_SDA_IO 18 /*!< GPIO number used for I2C master data  */

#define SENSER_USE_I2C_NUM 1      /*!< I2C master i2c port number, the number of i2c peripheral interfaces available will depend on the chip */
#define SENSER_I2C_FREQ_HZ 300000 /*!< I2C master clock frequency */

/**
 * @brief 传感器IIC初始化
 *
 * @return esp_err_t ESP_OK：成功，其他：失败
 */
esp_err_t senser_iic_init();

/**
 * @brief 传感器读取一个字节
 *
 * @param slave_addr 从机地址
 * @param reg_addr 寄存器地址
 * @return uint8_t
 */
uint8_t senser_iic_read_byte(uint8_t slave_addr, uint8_t reg_addr);

/**
 * @brief 传感器写入一个字节
 *
 * @param slave_addr 从机地址
 * @param reg_addr 寄存器地址
 * @param dat 数据
 */
void senser_iic_write_byte(uint8_t slave_addr, uint8_t reg_addr, uint8_t dat);

/**
 * @brief 传感器IIC读出指定字节
 *
 * @param slave_addr 从机地址
 * @param reg_addr 寄存器地址
 * @param data 数据缓存
 * @param len 字节数
 */
void senser_iic_read_bytes(uint8_t slave_addr, uint8_t reg_addr, uint8_t *data, size_t len);

/**
 * @brief 传感器IIC写入指定字节
 *
 * @param slave_addr 从机地址
 * @param reg_addr 寄存器地址
 * @param data 数据缓存
 * @param len 字节数
 */
void senser_iic_write_bytes(uint8_t slave_addr, uint8_t reg_addr, uint8_t *data, size_t len);

#endif
