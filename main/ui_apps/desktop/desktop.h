#ifndef desktop_app_H
#define desktop_app_H

#include "static_include.h"

typedef struct _desktop_watch_t
{
    const char *name;          // 表盘名称
    lv_obj_t *(*watch_load)(); // 初始化表盘并返回表盘LVGL screen对象
    void (*watch_close)();     // 关闭（禁用)表盘
} desktop_watch_t;             // 表盘初始化结构体

void desktop_app_install();

void desktop_add_watch(desktop_watch_t *watch);

//////////////////////////////////////////////////////////
void desktop_watch_list();

#endif
