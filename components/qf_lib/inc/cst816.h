#ifndef cst816_H
#define cst816_H

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief By 启凡科创 @之渝
     * D:2023-12-15 V:1.0.1 修复交换Y轴导致的坐标为0的问题
     * D:2023-2-14 V:1.0.0
     * @ESP IDF 4.4
     */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TP_ADD_8BIT 0 // 1:8位地址，0：7位地址
#if TP_ADD_8BIT
#define TP_IIC_ADD 0x2a // 从机地址8bit
#else
#define TP_IIC_ADD 0x15 // 从机地址7bit
#endif
#define TP_DEFAULT_ID 0Xb4 // 芯片ID

#define TP_WIDTH 240             // 宽
#define TP_HEIGHT 240            // 高
#define TP_SWAP_X 1              // 交换X两端
#define TP_SWAP_Y 0              // 交换Y两端
#define TP_SWAP_XY 0             // 交换X和Y轴
#define TP_GESTURE_EN 0          // 手势检测使能
#define TP_GESTURE_THRESHOULD 50 // 手势检测边缘阈值，阈值越高灵敏度越大但错误手势的可能性也更大，默认50
#define TP_NO_TOUCH_SLEEP 0      // 长时间触摸无手势休眠使能,默认5s
#define TP_LONG_PRESS_SLEEP 0    // 长按一段时间自动休眠使能，默认10s

    typedef enum
    {
        tp_gesture_none = 0,
        tp_gesture_down = 1,
        tp_gesture_up = 2,
        tp_gesture_right = 3,
        tp_gesture_left = 4,
        tp_gesture_long = 12
    } tp_gesture_type; // 根据芯片实际情况更改顺序

    typedef enum
    {
        tp_not_touch,
        tp_touching
    } tp_touch_state;

    typedef enum
    {
        tp_motion_left_right = 0x01,
        tp_motion_up_down = 0x02,
        tp_motion_long_press = 0x04
    } tp_motion_type;

    typedef struct
    {
        void (*i2c_write_byte)(uint8_t slave, uint8_t reg, uint8_t data);              // I2C向指定从机slave指定寄存器reg，写入 一个字节data
        void (*i2c_read_bytes)(uint8_t slave, uint8_t reg, uint8_t *data, size_t len); // I2C从指定从机slave指定寄存器reg，读出指向data的len字节格式函数
    } tp_i2c_cb;

    typedef struct
    {
        uint16_t now_x;   // 实时X坐标
        uint16_t now_y;   // 实时Y坐标
        uint16_t start_x; // 单次触摸的起始点x坐标
        uint16_t start_y; // 单次触摸的起始点y坐标
        uint16_t end_x;   // 单次触摸的结束点x坐标
        uint16_t end_y;   // 单次触摸的结束点y坐标
    } cst816_point_t;

    typedef struct
    {
        uint8_t chip_id;         // 芯片ID
        tp_touch_state state;    // 触摸状态,tp_not_touch,tp_touching
        tp_gesture_type gesture; // 滑动手势,tp_gesture_down/up/left/right/none
        cst816_point_t point;    // 起始、当前、结束的坐标值
    } cst816_info_t;

    typedef enum
    {
        cst816_click,
        cst816_slided,
        cst816_pressed,
    } cst816_slide_type_t;

    /**
     * @brief 注册I2C通信函数，请注意tp_i2c_cb内格式
     *
     * @param cfg
     */
    void cst816_attach_i2c_cb(tp_i2c_cb *cfg);

    /**
     * @brief 将此函数放置于触摸中断函数里
     */
    void cs816_intr();

    /**
     * @brief 初始化触摸屏
     *
     * @return uint8_t --0 成功，1 失败
     */
    uint8_t cst816_init();

    /**
     * @brief 获取触摸屏数据(从芯片获取)
     *
     * @param info
     * @param ··chip_id   // 芯片ID
     * @param ··state     // 触摸状态,tp_not_touch,tp_touching
     * @param ··gesture   // 滑动手势,tp_gesture_down/up/left/right/none
     * @param ··now_x     // 实时X坐标
     * @param ··now_y     // 实时Y坐标
     * @param ··start_x   // 单次触摸的起始点x坐标
     * @param ··start_y   // 单次触摸的起始点y坐标
     * @param ··end_x     // 单次触摸的结束点x坐标
     * @param ··end_y    // 单次触摸的结束点y坐标
     */
    void cst816_read_info(cst816_info_t *info);

    /**
     * @brief 获取坐标信息（获取最近一次历史记录，不会与芯片通信）
     *
     * @param point
     */
    void cst816_read_point(cst816_point_t *point);

    /**
     * @brief 获取屏幕滑动状态
     * 
     * @return cst816_slide_type_t 点击、滑动过、按下未滑动
     */
    cst816_slide_type_t cst816_read_slide_type();

        /**
         * @brief 触摸屏休眠
         */
        void cst816_sleep();

    /**
     * @brief 设置触摸屏动作检测使能，多个需要开启|在一起
     *
     * @param cfg
     * @param ··tp_motion_left_right 左右滑动
     * @param ··tp_motion_up_down 上下滑动
     * @param ··tp_motion_long_press 长按
     */
    void cst816_set_motion_en(tp_motion_type cfg);

#ifdef __cplusplus
}
#endif

#endif
