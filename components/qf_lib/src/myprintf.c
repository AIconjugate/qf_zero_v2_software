#include "myprintf.h"

#if MY_PRINTF_EN

static void (*_cb_ptr)(char dat) = NULL;

void myprintf_attach(void (*func_putchar)(char chr))
{
    _cb_ptr = func_putchar;
}

uint8_t myprintf(const char *format, ...)
{
    va_list aptr;
    size_t i, ret;
#if print_buffer_use_malloc
    char *print_buffer = malloc(print_buffer_size);
    if (print_buffer == NULL)
        return 0;
#else
    static char print_buffer[print_buffer_size];
#endif
    if (_cb_ptr == NULL)
        return 0;

    va_start(aptr, format);
    ret = vsprintf(print_buffer, format, aptr);
    va_end(aptr);

    for (i = 0; i < ret; i++)
    {
        _cb_ptr(print_buffer[i]);
    }
#if print_buffer_use_malloc
    free(print_buffer);
#endif

    return (ret);
}

#endif
