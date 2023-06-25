// #ifndef scr_global_api_H
// #define scr_global_api_H

// #ifdef __cplusplus
// extern "C"
// {
// #endif

// #ifdef LV_LVGL_H_INCLUDE_SIMPLE
// #include "lvgl.h"
// #else
// #include "lvgl/lvgl.h"
// #endif
// #include <stdio.h>

//     /**
//      * @brief 此文件为一些界面公共函数及一些公共功能汇总
//      */

//     /************************/
//     // 将各个界面的装载界面到调度器的函数在此声明
//     /************************/


//     /**
//      * @brief 初始化并加载所有的界面到调度器，以让调度器能正常调度
//      */
//     void scr_global_load_init();

//     /**
//      * @brief slider数值改变同步刷新lable文本的共给回调函数，绑定时用户数据为label控件
//      *
//      * @param e
//      */
//     void slider_value_changed_cb(lv_event_t *e);

//     /**
//      * @brief 设置某控件的border或outline的聚焦、选中颜色（userdata下的颜色）和宽度、透明度
//      *
//      * @param obj
//      * @param width
//      * @param opa
//      */
//     void scr_obj_set_border_focus_color(lv_obj_t *obj, uint8_t width, uint8_t opa);
//     void scr_obj_set_border_edit_color(lv_obj_t *obj, uint8_t width, uint8_t opa);
//     void scr_obj_set_outline_focus_color(lv_obj_t *obj, uint8_t width, uint8_t opa);
//     void scr_obj_set_outline_edit_color(lv_obj_t *obj, uint8_t width, uint8_t opa);

//     /**
//      * @brief 创建一个格式化的label
//      *
//      * @param pararent 父对象
//      * @param width 宽度，0为自动
//      * @param height 高度，0为自动
//      * @param text 静态文本，动态数据给NULL
//      * @param font 指定字体，默认字体给NULL
//      * @param color 文字颜色
//      * @return lv_obj_t* 创建好的label对象
//      */
//     lv_obj_t *scr_lable_create(lv_obj_t *pararent, int32_t width, int32_t height, const char *text, const lv_font_t *font, lv_color_t color);

//     /**
//      * @brief 创建一个指定纯色背景和透明度的容器对象
//      *
//      * @param para 父对象
//      * @param weight 宽度
//      * @param height 高度
//      * @param radius 圆角半径
//      * @param color 背景颜色
//      * @param opa 透明度
//      * @return lv_obj_t* 创建的对象
//      */
//     lv_obj_t *scr_obj_creat(lv_obj_t *para, int32_t weight, int32_t height, uint8_t radius, lv_color_t color, uint8_t opa);

//     /**
//      * @brief 创建一个格式化的slider,全透明需自己添加颜色样式
//      *
//      * @param para 父对象
//      * @param min 最小值
//      * @param max 最大值
//      * @param var 默认值
//      * @param weight 宽度
//      * @param height 高度
//      * @param radius 圆角半径
//      * @param group 添加到指定组，不添加给NULL
//      * @return lv_obj_t* 创建好的slider对象
//      */
//     lv_obj_t *scr_slider_create(lv_obj_t *para, int32_t min, int32_t max, int32_t var, int32_t weight, int32_t height, uint8_t radius, lv_group_t *group);

//     /**
//      * @brief 设置slider样式
//      *
//      * @param obj slider对象
//      * @param bg 背景颜色
//      * @param in_bg 指示器颜色
//      * @param grad_en 指示器渐变使能
//      * @param grad_color 指示器渐变颜色
//      */
//     void scr_slider_set_style(lv_obj_t *obj, lv_color_t bg, lv_color_t in_bg, bool grad_en, lv_color_t grad_color);
//     /**
//      * @brief 创建一个格式化的按键,纯色背景，需自己添加颜色样式
//      *
//      * @param para 父对象
//      * @param weight 宽度
//      * @param height 高度
//      * @param radius 圆角半径
//      * @param color 背景颜色
//      * @param group 添加到指定组，不添加给NULL
//      * @return lv_obj_t* 创建好的btn对象
//      */
//     lv_obj_t *scr_btn_create(lv_obj_t *para, int32_t weight, int32_t height, uint8_t radius, lv_color_t color, lv_group_t *group);

//     /*
//         0xE7BFB5 深粉色
//         0xE9DE8D 暗黄色
//         0x7EB6D7 水蓝色
//         0x20C9D2 青蓝色
//         0x4BC9B0 亮青蓝
//         0x4B9377 暗青蓝
//         0x00CCFC 亮蓝色
//         0xF6B9F9 浅紫色
//         0xFEA457 橙色
//         0x4B7052 暗绿色
//         0x50FF7D 亮绿色
//         0xABEB13 浅绿色
//         0xC1DED2 淡绿色
//         0xE64472 玫红色
//         0xDDB0F6 薰衣草色
//         0xCCC5E8 淡紫色
//         0xFFFFFF 纯白
//         0x000000 纯黑
//         0xDDB5AC 肤色
//         0xE3735D 橘红色
//         0xF6AAB1 粉红色
//         0xEFC9C6 浅粉色
//         0x707988 灰蓝色
//         0xE5E2DA 米白色
//         0xE7D6C0 卡其色
//         0xEE1B24 红色
//         0xC61319 枣红色

//     */

//     /************************/

// #ifdef __cplusplus
// }
// #endif

// #endif
