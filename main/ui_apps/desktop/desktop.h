#ifndef desktop_app_H
#define desktop_app_H

#include "static_include.h"

// 桌面壁纸声明
LV_IMG_DECLARE(desktop_bg_01);
LV_IMG_DECLARE(desktop_bg_02);
LV_IMG_DECLARE(desktop_bg_03);

#define desktop_bg_default desktop_bg_03 // 默认桌面壁纸

typedef struct _desktop_watch_t
{
    const char *name;          // 表盘名称
    lv_obj_t *(*watch_load)(); // 初始化表盘并返回表盘LVGL screen对象
    void (*watch_close)();     // 关闭（禁用)表盘
} desktop_watch_t;             // 表盘初始化结构体

void desktop_app_install();

void desktop_add_watch(desktop_watch_t *watch);

/**
 * @brief APP加载界面
 *
 * @param scr 界面对象
 * @param anim_type 动画类型
 * @param time 过渡时长ms
 * @param delay 等待时长ms
 */
void app_scr_load(lv_obj_t *scr, lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay);

//////////////////////////////////////////////////////////
void desktop_watch_list();

#endif
