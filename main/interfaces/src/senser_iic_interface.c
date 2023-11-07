#include "senser_iic_interface.h"

uint8_t senser_iic_read_byte(uint8_t slave_addr, uint8_t reg_addr)
{
    uint8_t dat = 0;
    i2c_master_write_read_device(SENSER_USE_I2C_NUM, slave_addr, &reg_addr, 1, &dat, 1, 1000 / portTICK_RATE_MS);
    return dat;
}

void senser_iic_write_byte(uint8_t slave_addr, uint8_t reg_addr, uint8_t dat)
{
    uint8_t write_buf[2] = {reg_addr, dat};
    i2c_master_write_to_device(SENSER_USE_I2C_NUM, slave_addr, write_buf, 2, 1000 / portTICK_RATE_MS);
}

void senser_iic_read_bytes(uint8_t slave_addr, uint8_t reg_addr, uint8_t *data, size_t len)
{
    i2c_master_write_read_device(SENSER_USE_I2C_NUM, slave_addr, &reg_addr, 1, data, len, 1000 / portTICK_RATE_MS);
}

void senser_iic_write_bytes(uint8_t slave_addr, uint8_t reg_addr, uint8_t *data, size_t len)
{
    uint8_t write_buf[len + 1];
    write_buf[0] = reg_addr;
    memcpy(&write_buf[1], data, len);
    i2c_master_write_to_device(SENSER_USE_I2C_NUM, slave_addr, write_buf, len + 1, 1000 / portTICK_RATE_MS);
}

esp_err_t senser_iic_init()
{
    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = SENSER_I2C_SDA_IO,
        .scl_io_num = SENSER_I2C_SCL_IO,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = SENSER_I2C_FREQ_HZ,
    };

    int ret = i2c_param_config(SENSER_USE_I2C_NUM, &conf);
    if (ret != ESP_OK)
        return ret;

    ret = i2c_driver_install(SENSER_USE_I2C_NUM, conf.mode, 0, 0, 0);
    if (ret != ESP_OK)
        return ret;

    cw2015_trans_cb_t cb;
    cb.iic_read_bytes = senser_iic_read_bytes;
    cb.iic_write_bytes = senser_iic_write_bytes;
    cw2015_attach_trans_cb(&cb); // 注册电量计通信接口

    qmc5883l_trans_cb_t cfg = {
        .read_bytes = senser_iic_read_bytes,
        .write_byte = senser_iic_write_byte};
    qmc5883l_attach_trans_cb(&cfg);

    return ESP_OK;
}