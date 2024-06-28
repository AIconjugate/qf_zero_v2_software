#include "cst816.h"

// CST816寄存器
#define GestureID 0x01     // 手势寄存器
#define FingerNum 0x02     // 手指数量
#define XposH 0x03         // x高四位
#define XposL 0x04         // x低八位
#define YposH 0x05         // y高四位
#define YposL 0x06         // y低八位
#define ChipID 0xA7        // 芯片型号
#define BIG_TOUCH_RST 0XEA // 大面积触摸复位
#define MotionMask 0xEC    // 触发动作
#define AutoSleepTime 0xF9 // 自动休眠
#define IrqCrl 0xFA        // 中断控制
#define DEEP_SLEEP 0XE5    // 休眠
#define AutoReset 0xFB     // 无手势休眠
#define LongPressTime 0xFC // 长按休眠
#define DisAutoSleep 0xFE  // 使能低功耗模式

static uint8_t _touch_intr = 0;
static cst816_info_t _tp_info;
static tp_i2c_cb _cb = {NULL, NULL};
static uint8_t _init_flg = 2;

void cst816_read_point(cst816_point_t *point)
{
    *point = _tp_info.point;
}

cst816_slide_type_t cst816_read_slide_type()
{
    if (_tp_info.state == 0) // 无触摸
    {
        int16_t cha = _tp_info.point.start_x - _tp_info.point.end_x;
        if (cha < 2 && cha > -2)
        {
            cha = _tp_info.point.start_y - _tp_info.point.end_y;
            if (cha < 2 && cha > -2)
            {
                return cst816_click;
            }
        }
        return cst816_slided;
    }
    // 有触摸
    int16_t cha = _tp_info.point.start_x - _tp_info.point.now_x;
    if (cha < 2 && cha > -2)
    {
        cha = _tp_info.point.start_y - _tp_info.point.now_y;
        if (cha < 2 && cha > -2)
        {
            return cst816_pressed;
        }
    }
    return cst816_slided;
}

void cst816_attach_i2c_cb(tp_i2c_cb *cfg)
{
    _cb = *cfg;
}

void cs816_intr()
{
    _touch_intr = 1;
}

uint8_t cst816_init()
{
    if (_cb.i2c_read_bytes == NULL)
        return 1;

    _tp_info.chip_id = 0;
    _cb.i2c_read_bytes(TP_IIC_ADD, ChipID, &_tp_info.chip_id, 1);
    if (_tp_info.chip_id == TP_DEFAULT_ID)
    {
        _init_flg = 0;
#if !TP_NO_TOUCH_SLEEP
        _cb.i2c_write_byte(TP_IIC_ADD, AutoReset, 0x00);
#endif
#if !TP_LONG_PRESS_SLEEP
        _cb.i2c_write_byte(TP_IIC_ADD, LongPressTime, 0x00);
#endif
        _cb.i2c_write_byte(TP_IIC_ADD, BIG_TOUCH_RST, 0x00);
        return 0;
    }

    return 1;
}

static uint8_t cst816t_get_touch_points_num()
{
    uint8_t tmp;
    _cb.i2c_read_bytes(TP_IIC_ADD, FingerNum, &tmp, 1);
    return tmp;
}

void cst816_read_info(cst816_info_t *info)
{
    uint8_t data[4];
    static uint8_t shake_count = 0;
#if TP_GESTURE_EN
    static uint8_t gesture_tmp = 0;
#endif
    if (_cb.i2c_read_bytes == NULL)
        return;
    if (_touch_intr == 0) // 无触摸中断
    {
        info->state = 0;
        return;
    }
    info->chip_id = _tp_info.chip_id; // ic id

    data[0] = cst816t_get_touch_points_num();

    // 无触摸
    if (data[0] == 0) // touch leave
    {
        shake_count++;
        if (shake_count < 2) // 消抖
            return;
        shake_count = 0;

        _touch_intr = 0;    // 消除触摸中断标志
        _tp_info.state = 0; // 消除内部触摸状态

        info->point.end_x = _tp_info.point.end_x; // 记录下结束点
        info->point.end_y = _tp_info.point.end_y;
        _tp_info.point.now_x = 0;
        _tp_info.point.now_y = 0;

#if TP_GESTURE_EN
        if (gesture_tmp != 0) // 有手势
        {
            info->gesture = gesture_tmp;
            switch (gesture_tmp)
            {
            case tp_gesture_down: // 下滑
                if (_tp_info.start_y < TP_GESTURE_THRESHOULD)
                    info->gesture = tp_gesture_down;
                break;
            case tp_gesture_up: // 上滑
                if (_tp_info.start_y > (TP_HEIGHT - TP_GESTURE_THRESHOULD))
                    info->gesture = tp_gesture_up;
                break;
            case tp_gesture_right: // 右滑
                if (_tp_info.start_x < TP_GESTURE_THRESHOULD)
                    info->gesture = tp_gesture_right;
                break;
            case tp_gesture_left: // 左滑
                if (_tp_info.start_x > (TP_WIDTH - TP_GESTURE_THRESHOULD))
                    info->gesture = tp_gesture_left;
                break;
            default: // 长按
                info->gesture = tp_gesture_long;
                break;
            }
            gesture_tmp = 0;
        }
#endif
        return;
    }

    // 以下为有触摸

    info->state = data[0]; // 给外部有触摸的状态

#if TP_GESTURE_EN
    _cb.i2c_read_bytes(TP_IIC_ADD, GestureID, data, 1);
    if (data[0] != 0) // 有手势
        gesture_tmp = data[0];
#endif

    _cb.i2c_read_bytes(TP_IIC_ADD, XposH, data, 4); // 读取实时x，y

#if TP_SWAP_XY
    _tp_info.point.now_y = ((data[0] & 0x0f) << 8) | data[1];
    _tp_info.point.now_x = ((data[2] & 0x0f) << 8) | data[3];
#else
    _tp_info.point.now_x = ((data[0] & 0x0f) << 8) | data[1];
    _tp_info.point.now_y = ((data[2] & 0x0f) << 8) | data[3];
#endif

#if TP_SWAP_X
    _tp_info.point.now_x = -_tp_info.point.now_x + TP_WIDTH; // 翻转x坐标
#endif

#if TP_SWAP_Y
    _tp_info.point.now_y = -_tp_info.point.now_y + TP_HEIGHT; // 翻转y坐标
#endif

    if (_tp_info.point.now_x >= TP_WIDTH || _tp_info.point.now_y >= TP_HEIGHT) // 范围消抖
        return;

    if (_tp_info.state == 0) // 触摸起点
    {
        info->point.start_x = _tp_info.point.now_x; // 外部赋值起点
        info->point.start_y = _tp_info.point.now_y;
        _tp_info.point.start_x = _tp_info.point.now_x; // 内部记录起点
        _tp_info.point.start_y = _tp_info.point.now_y;
        _tp_info.state = info->state; // 内部状态同步
    }

    info->point.now_x = _tp_info.point.now_x; // 同步坐标
    info->point.now_y = _tp_info.point.now_y;
    _tp_info.point.end_x = _tp_info.point.now_x;
    _tp_info.point.end_y = _tp_info.point.now_y;
}

void cst816_sleep()
{
    if (_cb.i2c_read_bytes == NULL)
        return;
    _cb.i2c_write_byte(TP_IIC_ADD, DEEP_SLEEP, 0x03);
}

void cst816_set_motion_en(tp_motion_type cfg)
{
    if (_cb.i2c_read_bytes == NULL)
        return;
    _cb.i2c_write_byte(TP_IIC_ADD, MotionMask, cfg);
}
