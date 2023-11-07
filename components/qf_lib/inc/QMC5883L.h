

#ifndef _QMC5883L_H
#define _QMC5883L_H

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif
    /**
     * @brief QMC5883L库by启凡科创
     * @param Version:1.0.0
     * @param DAY:2023-11-5
     * @param 校准参数部分参考ARDUINO库https://github.com/mprograms/QMC5883LCompass/
     */

#define qmc5883l_lib_compile_en 1 // 库编译使能   1：使能，0：不编译

#if qmc5883l_lib_compile_en

#define qmc5883l_IIC_ADDRESS_8BIT 0 // 1:8位地址模式，0：7位地址模式
#define qmc5883l_xy_offset_angle 90  // xy偏移角度补偿
#define qmc5883l_reverse 1          // 颠倒正反，用于传感器在PCB背面，1：颠倒，0：正常

#define qmc5883l_DEBUG 1                 // 调试输出信息,1:启用，0：关闭
#define qmc5883l_DEBUG_LOG_PRINTF printf // 日志输出使用的函数名

#if qmc5883l_IIC_ADDRESS_8BIT
#define qmc5883l_ADDR (0x1A) // 8bit器件IIC地址
#else
#define qmc5883l_ADDR (0x0D) // 7bit器件IIC地址
#endif

    typedef void (*qmc5883l_write_byte_cb_t)(uint8_t add, uint8_t reg, uint8_t dat);
    typedef void (*qmc5883l_read_bytes_cb_t)(uint8_t add, uint8_t reg, uint8_t *dat, size_t size);

    typedef struct
    {
        qmc5883l_write_byte_cb_t write_byte; // 从机地址add，寄存器reg，数据dat
        qmc5883l_read_bytes_cb_t read_bytes; // 从机地址add，起始寄存器reg，始读size字节，存放到dat指向的内存
    } qmc5883l_trans_cb_t;

    typedef enum
    {
        qmc_status_dor = 0x04,  // 0:正常，1：数据跳过阅读
        qmc_status_ovl = 0x02,  // 0:正常，1：数据溢出
        qmc_status_drdy = 0x01, // 0:数据未就绪，1：新数据已更新
    } qmc5883l_status_mask_t;   // 工作模式

    typedef enum
    {
        qmc_mode_standby,    // 待机
        qmc_mode_continuous, // 连续转换
    } qmc5883l_mode_t;       // 工作模式

    typedef enum
    {
        qmc_odr_10hz,  // 10HZ
        qmc_odr_50hz,  // 50HZ
        qmc_odr_100hz, // 100HZ
        qmc_odr_200hz, // 200HZ
    } qmc5883l_odr_t;  // 输出速率

    typedef enum
    {
        qmc_range_2g,   // 2G
        qmc_range_8g,   // 8G
    } qmc5883l_range_t; // 测量范围

    typedef enum
    {
        qmc_osr_512,  // 512
        qmc_osr_256,  // 256
        qmc_osr_128,  // 128
        qmc_osr_64,   // 64
    } qmc5883l_osr_t; // 过采样率，数值越大噪声越低功耗越高

    typedef struct
    {
        int16_t x_min;
        int16_t x_max;
        int16_t y_min;
        int16_t y_max;
        int16_t z_min;
        int16_t z_max;
    } qmc_xyz_range_t;

    /**
     * @brief 注册IIC通信函数
     *
     * @param cbs 结构体，包含读和写的回调函数指针
     */
    void qmc5883l_attach_trans_cb(qmc5883l_trans_cb_t *cbs);

    /**
     * @brief  初始化qmc5883l，初始化qmc5883l，配置相应模式等参数
     *
     * @param mode 工作模式
     * @param odr 输出速率
     * @param range 测量范围
     * @param osr 超采样速率
     * @return uint8_t 0：成功，1：IIC通信函数未绑定，2：硬件地址错误或硬件连接存在问题
     */
    uint8_t qmc5883l_begin(qmc5883l_mode_t mode, qmc5883l_odr_t odr, qmc5883l_range_t range, qmc5883l_osr_t osr);

    /**
     * @brief 读取三轴磁场数据
     *
     * @param x 指向接受结果的变量,不需要填NULL
     * @param y 指向接受结果的变量,不需要填NULL
     * @param z 指向接受结果的变量,不需要填NULL
     */
    void qmc5883l_get_xyz(int16_t *x, int16_t *y, int16_t *z);

    /**
     * @brief 获取方位角
     *
     * @return int16_t 角度 -180_+180
     */
    int16_t qmc5883l_get_angle();

    /**
     * @brief 使能进入休眠
     *
     * @param en
     */
    void qmc5883l_sleep(uint8_t en);

    /**
     * @brief 软件复位
     */
    void qmc5883l_reset();

    /**
     * @brief 使能更新xyz数据范围，默认关闭，开启后，将在每一次读取数据时自动更新xyz的最大最小值
     *        开启功能后，建议将数据读取率跟配置的数据输出率同步，同时尽可能提高数据输出率挡位，
     *        以获得更多的采样点，注意：必须调用qmc5883l_get_xyz函数才会更新一个点
     *
     * @param en 0：关闭，1：开启，校准完成后建议关闭，以节省算力
     */
    void qmc5883l_xyz_range_updata(uint8_t en);

    /**
     * @brief 获取xyz的最大最小区间
     *
     * @return qmc_xyz_range_t 范围数据的结构体
     */
    qmc_xyz_range_t qmc5883l_get_xyz_range();

    /**
     * @brief 设置校准参数
     *
     * @param range xyz的实际范围
     */
    void qmc5883l_set_calibration(qmc_xyz_range_t *range);

    /**
     * @brief 清除校准参数
     */
    void qmc5883l_clear_calibration();

#endif

#ifdef __cplusplus
}
#endif

#endif
