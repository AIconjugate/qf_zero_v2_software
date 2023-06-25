// #ifndef scr_scheduler_H
// #define scr_scheduler_H

// #ifdef __cplusplus
// extern "C"
// {
// #endif

// #ifdef LV_LVGL_H_INCLUDE_SIMPLE
// #include "lvgl.h"
// #else
// #include "lvgl/lvgl.h"
// #endif

// #include "my_lv_symbol_font.h" //自定义图标、字体声明文件
// #include "scr_global_api.h"

//     /**
//      * @brief LVGL界面调度器@启凡科创
//      *
//      * 此库为界面管理、切换的调度器,同时还提供给用户快捷创建msgbox的接口用于系统通知等
//      * 使用此调度器和配套的界面编写格式，可简单快捷地实现界面之间的调度和切换
//      * 统一格式的界面demo为scr_template.c.bak,可自行复制后更改名称并去掉.bak作为空界面
//      * 适配LVGL版本：V8
//      * Version:1.0.1 2022-12-31
//      */

// #define scr_width_defaule 240                          // 屏幕默认宽度
// #define scr_height_defaule 240                         // 屏幕默认高度
// #define scr_load_time_defaule 500                      // 屏幕默认加载时长ms
// #define scr_load_delay_defaule 0                       // 屏幕默认加载延时ms
// #define scr_load_anim_defaule LV_SCR_LOAD_ANIM_FADE_ON // 屏幕默认加载动画
// #define scr_delete_old_screen 1                        // 是否在加载新界面后删除老界面的数据，0保留/1删除（RAM不足推荐使用）
// #define msgbox_text_font_default CangEr_Kai_18         // msgbox默认字体,使用私有字体请包含相关声明文件或在此定义下声明字体

//     /**
//      * @brief 界面激活状态
//      * 供用户在编写界面时使用，请务必正确设置屏幕的各种状态，以免发生重复创建数据和操作空数据等风险
//      */
//     typedef enum
//     {
//         // 后台状态
//         scr_no_obj_no_task,     //(默认初始化状态)调度器配置为删除旧界面，且界面没有后台任务运行
//         scr_no_obj_have_task,   // 调度器配置为删除旧界面，但后台有任务依然需要运行
//         scr_have_obj_no_task,   // 调度器配置为不删除旧界面，没有需要后台运行的任务
//         scr_have_obj_have_task, // 调度器配置为不删除旧界面，后台有任务依然需要运行

//         // 前台状态
//         scr_active // 界面当前正在显示当中
//     } scr_active_type;

//     /**
//      * @brief 使用预定义的宏默认参数加载界面,请确保加载前已经将界面注册到调度器
//      *
//      * @param name_str 界面名称字符串
//      */
//     void scr_load(const char *name_str);

//     /**
//      * @brief 使用指定参数加载界面
//      *
//      * @param name_str 界面名称字符串
//      * @param anim_type 动画类型
//      * @param time 加载用时ms
//      * @param delay 加载延迟时长ms
//      */
//     void scr_load_anim(const char *name_str, lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay);

//     /**
//      * @brief 事件回调函数创建msgbox，此功能会使用LV_OBJ_FLAG_USER_4,对象如果用了此标志，请勿将此对象用来创建msgbox
//      *
//      * @param e userdata为字符串
//      * -----使用方式如：lv_obj_add_event_cb(btn, scr_create_msg_box, LV_EVENT_CLICKED, (void *)"喵喵喵~");
//      */
//     void scr_create_msg_box(lv_event_t *e);

//     /**
//      * @brief 指定对象创建msgbox，弹窗期间无法再创建，此功能会使用LV_OBJ_FLAG_USER_4,对象如果用了此标志，请勿将此对象用来创建msgbox
//      *
//      * @param trig_obj 对象
//      * @param str 字符串
//      */
//     void scr_create_msg_box_str(lv_obj_t *trig_obj, const char *str);

//     /*****************************
//      * 以下内容为开发screen的时候需要注意的格式内容
//      */

//     /**
//      * @brief 界面加载回调函数格式，在调用此接口时，界面需要初始化绘制出一个供调度器加载的前台界面返回给调度器
//      *
//      * @return 指向界面目标，调度器将加载此界面，初始化界面失败返回NULL则调度器会终止加载界面
//      */
//     typedef lv_obj_t *(*scr_load_cb_t)();

//     /**
//      * @brief 界面转至后台运行通知函数，调度器在切换界面后，会删除旧界面的显示数据以节约内存，
//      *        调度器通过此接口通知旧界面它的显示数据已经被删除了，可以停下相关前台任务转至后台运行
//      */
//     typedef void (*scr_del_cb_t)();

//     /**
//      * @brief 注册界面,注册后界面调度器才能找到界面
//      *
//      * @param scr_load 界面内部的加载函数，格式统一
//      * @param scr_del 界面内部的删除函数，格式统一
//      * @param name_str 界面内预留的界面名字符串
//      */
//     void scr_attach(scr_load_cb_t scr_load, scr_del_cb_t scr_del, const char *name_str);

// #ifdef __cplusplus
// }
// #endif

// #endif
