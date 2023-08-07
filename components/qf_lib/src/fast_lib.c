#include "fast_lib.h"

inline int strcmp_my(const char *str1, const char *str2)
{
    for (; *str1 == *str2; ++str1, ++str2)
    {
        if (*str1 == '\0')
            return (0);
    }
    return 1;
}

uint8_t system_day_count_week(uint8_t year, uint8_t month, uint8_t day)
{
    int _year = year;
    if (month < 3)
    {
        month += 12;
        _year -= 1;
        if (_year < 0)
            _year = 99;
    }

    return (uint8_t)(day + 2 * month + 3 * (month + 1) / 5 + _year + _year / 4 - _year / 100 + _year / 400 + 1) % 7;
}