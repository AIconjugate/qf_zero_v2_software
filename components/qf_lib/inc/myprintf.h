#ifndef myprintf_H
#define myprintf_H
#ifdef __cplusplus
extern "C"
{
#endif
    /****************************************************************/
    /*
        格式化打印库 By 启凡科创。
        Version:1.0.1 2023-5-31
    */
    /****************************************************************/

    // #include "LIB_CONFIG.h"

#include <stdio.h>  //依赖库
#include <stdarg.h> //依赖库
#include <stdint.h>
#include <stdlib.h>

#ifndef MY_PRINTF_EN
#define MY_PRINTF_EN 0 // 如果配置文件未定义，则用户自定义，0禁用模块不不编译，1启用模块
#endif

#if MY_PRINTF_EN

#ifndef NULL
#define NULL ((void *)0)
#endif

// 打印缓冲大小bytes,要打印的内容超过此限制会造成内存泄漏,严格审定长度
#define print_buffer_size 128
#define print_buffer_use_malloc 1 // 打印用的缓存是否动态申请，1：动态申请（闲时不占用内存，但效率相对较低且可能造成内存碎片化）；0：使用固定数组作为缓存

    /*
        绑定打印单字节函数，通过更改绑定函数实现任意输出接口切换格式化打印
        你可以将oled屏显示一个字符的接口绑定上，以实现oled的格式化打印功能，
        使用完oled显示后，再将串口打印一个字符的函数绑定到此，又可以实现串口的格式化输出
        通过上述的操作步骤，你可以实现一个myprintf接口实现所有需要格式化输出的场景
        而需要格式化输出的地方仅需要能实现单个字节的打印而已
        绑定格式如：不是此格式请先将格式定义为此格式
            void uart1_putchar(char dat)
            {
                uart1_write_char(uart1,dat);
            }
    */
    void myprintf_attach(void (*func_putchar)(char chr));

    // 格式化打印，返回打印字节数
    uint8_t myprintf(const char *format, ...);

#endif
#ifdef __cplusplus
}
#endif
#endif
