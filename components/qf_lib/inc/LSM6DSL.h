

#ifndef _LSM6DSL_H
#define _LSM6DSL_H

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif
    /**
     * @brief LSM6DSL库by启凡科创
     * @param Version:1.0.0
     * @param DAY:2024-10-8
     */

#define lsm6dsl_lib_compile_en 1

#if lsm6dsl_lib_compile_en

#define LSM6DSL_IIC_ADDRESS_8BIT 0 // 1:8位地址模式，0：7位地址模式

#if LSM6DSL_IIC_ADDRESS_8BIT
#define LSM6DSL_ADDR (0x00) // 8bit器件IIC地址
#else
#define LSM6DSL_ADDR (0x00) // 7bit器件IIC地址
#endif

#define LSM6DSL_DEFAULT_CHIP_ID (0X00)  // ID寄存器
#define LSM6DSL_DEBUG 1                 // 调试输出信息,1:启用，0：关闭
#define LSM6DSL_DEBUG_LOG_PRINTF printf // 日志输出使用的函数名

    typedef enum
    {
        LSM6DSL_OK,          // 成功
        LSM6DSL_NO_TRANS_CB, // 无通信函数
        LSM6DSL_TRANS_ERR,   // 通信失败
        LSM6DSL_DATA_ERR     // 数据错误
        //...
    } lsm6dsl_ret_t;

    typedef enum
    {
        LSM6DSL_GET_GY,         // 获取陀螺仪
        LSM6DSL_GET_XL,         // 获取加速度
        LSM6DSL_GET_GY_XL,      // 获取陀螺仪和加速度
        LSM6DSL_GET_INTER_MASK, // 获取中断状态
        LSM6DSL_GET_STEP,       // 获取步数
        //...
    } lsm6dsl_get_t;

    typedef enum
    {
        LSM6DSL_SET_GY_ODR,      // 设置陀螺仪输出率
        LSM6DSL_SET_GY_RANGE,    // 设置陀螺仪采样范围
        LSM6DSL_SET_GY_INTR,     // 设置陀螺仪中断
        LSM6DSL_SET_XL_ODR,      // 设置加速度输出率
        LSM6DSL_SET_RANGE,       // 设置加速度采样范围
        LSM6DSL_SET_INTR,        // 设置中断
        LSM6DSL_SET_WRIST_ANGLE, // 设置抬腕角度
        LSM6DSL_SET_WRIST_TIME,  // 设置抬腕时间
        LSM6DSL_SET_WRIST_INTR,  // 设置抬腕中断
        LSM6DSL_SET_STEP_TIME,   // 设置计步抖动时间
        LSM6DSL_SET_STEP_INTR,   // 设置计步中断
        LSM6DSL_SET_STEP_CLEAR,  // 清楚计步数据
        LSM6DSL_SET_SLEEP,       // 设置睡眠
        LSM6DSL_SET_SOFTRESET,   // 软件复位
        //...
    } lsm6dsl_set_t;

    typedef void (*lsm6dsl_write_byte_cb_t)(uint8_t add, uint8_t reg, uint8_t dat);
    typedef void (*lsm6dsl_read_bytes_cb_t)(uint8_t add, uint8_t reg, uint8_t *dat, size_t size);

    typedef struct
    {
        lsm6dsl_write_byte_cb_t write_byte; // 从机地址add，寄存器reg，数据dat
        lsm6dsl_read_bytes_cb_t read_bytes; // 从机地址add，起始寄存器reg，始读size字节，存放到dat指向的内存
    } lsm6dsl_trans_cb_t;

    /**
     * @brief 注册IIC通信函数
     *
     * @param cbs 结构体，包含读和写的回调函数指针
     */
    void lsm6dsl_attach_trans_cb(lsm6dsl_trans_cb_t *cbs);

    /**
     * @brief 初始化lsm6dsl
     *
     * @return lsm6dsl_ret_t
     */
    lsm6dsl_ret_t lsm6dsl_begin(void);

    /**
     * @brief 读取
     *
     * @param get_type 读取类型
     * @param buffer 缓存
     * @return lsm6dsl_ret_t
     */
    lsm6dsl_ret_t lsm6dsl_read(lsm6dsl_get_t get_type, void *buffer);

    /**
     * @brief 设置
     *
     * @param set_type 设置类型
     * @param buffer 缓存
     * @return lsm6dsl_ret_t
     */
    lsm6dsl_ret_t lsm6dsl_set(lsm6dsl_set_t set_type, void *buffer);

#endif

#ifdef __cplusplus
}
#endif

#endif
