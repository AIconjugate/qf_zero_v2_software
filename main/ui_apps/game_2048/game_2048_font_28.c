/*******************************************************************************
 * Size: 28 px
 * Bpp: 4
 * Opts: --bpp 4 --size 28 --no-compress --font OPlusSans3-Medium.ttf --symbols 0123456789 --format lvgl -o game_2048_font_28.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef GAME_2048_FONT_28
#define GAME_2048_FONT_28 1
#endif

#if GAME_2048_FONT_28

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0030 "0" */
    0x0, 0x0, 0x5b, 0xef, 0xfd, 0x81, 0x0, 0x0,
    0x1, 0xbf, 0xff, 0xff, 0xff, 0xf5, 0x0, 0x0,
    0xcf, 0xff, 0x96, 0x7c, 0xff, 0xf4, 0x0, 0x6f,
    0xfe, 0x20, 0x0, 0x7, 0xff, 0xd0, 0xc, 0xff,
    0x50, 0x0, 0x0, 0xc, 0xff, 0x40, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x7f, 0xf8, 0x2f, 0xfd, 0x0,
    0x0, 0x0, 0x4, 0xff, 0xa3, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0x3f, 0xfc, 0x3f, 0xfb, 0x0, 0x0,
    0x0, 0x3, 0xff, 0xc4, 0xff, 0xb0, 0x0, 0x0,
    0x0, 0x2f, 0xfc, 0x4f, 0xfb, 0x0, 0x0, 0x0,
    0x2, 0xff, 0xc4, 0xff, 0xb0, 0x0, 0x0, 0x0,
    0x3f, 0xfc, 0x3f, 0xfc, 0x0, 0x0, 0x0, 0x3,
    0xff, 0xc2, 0xff, 0xd0, 0x0, 0x0, 0x0, 0x4f,
    0xfa, 0xf, 0xff, 0x0, 0x0, 0x0, 0x7, 0xff,
    0x80, 0xbf, 0xf5, 0x0, 0x0, 0x0, 0xdf, 0xf4,
    0x5, 0xff, 0xe2, 0x0, 0x0, 0x7f, 0xfd, 0x0,
    0xb, 0xff, 0xf9, 0x67, 0xcf, 0xff, 0x40, 0x0,
    0x1b, 0xff, 0xff, 0xff, 0xff, 0x60, 0x0, 0x0,
    0x5, 0xbe, 0xff, 0xd8, 0x20, 0x0,

    /* U+0031 "1" */
    0x0, 0x0, 0x6e, 0xfb, 0x0, 0x5d, 0xff, 0xfb,
    0x4c, 0xff, 0xff, 0xfb, 0xdf, 0xff, 0xaf, 0xfb,
    0xdf, 0x81, 0x3f, 0xfb, 0x71, 0x0, 0x3f, 0xfb,
    0x0, 0x0, 0x3f, 0xfb, 0x0, 0x0, 0x3f, 0xfb,
    0x0, 0x0, 0x3f, 0xfb, 0x0, 0x0, 0x3f, 0xfb,
    0x0, 0x0, 0x3f, 0xfb, 0x0, 0x0, 0x3f, 0xfb,
    0x0, 0x0, 0x3f, 0xfb, 0x0, 0x0, 0x3f, 0xfb,
    0x0, 0x0, 0x3f, 0xfb, 0x0, 0x0, 0x3f, 0xfb,
    0x0, 0x0, 0x3f, 0xfb, 0x0, 0x0, 0x3f, 0xfb,
    0x0, 0x0, 0x3f, 0xfb, 0x0, 0x0, 0x3f, 0xfb,

    /* U+0032 "2" */
    0x0, 0x0, 0x4a, 0xef, 0xed, 0x81, 0x0, 0x0,
    0x0, 0xaf, 0xff, 0xff, 0xff, 0xf5, 0x0, 0x0,
    0xbf, 0xff, 0x97, 0x8d, 0xff, 0xf3, 0x0, 0x6f,
    0xfd, 0x10, 0x0, 0xa, 0xff, 0xb0, 0xd, 0xff,
    0x20, 0x0, 0x0, 0x1f, 0xff, 0x0, 0x28, 0x70,
    0x0, 0x0, 0x0, 0xff, 0xf2, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0x10, 0x0, 0x0, 0x0,
    0x0, 0x4, 0xff, 0xd0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xcf, 0xf7, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x8f, 0xfd, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7f,
    0xfe, 0x20, 0x0, 0x0, 0x0, 0x0, 0x7f, 0xff,
    0x30, 0x0, 0x0, 0x0, 0x0, 0x7f, 0xff, 0x30,
    0x0, 0x0, 0x0, 0x0, 0x7f, 0xff, 0x30, 0x0,
    0x0, 0x0, 0x0, 0x8f, 0xfe, 0x30, 0x0, 0x0,
    0x0, 0x0, 0x8f, 0xfe, 0x30, 0x0, 0x0, 0x0,
    0x0, 0x8f, 0xfe, 0x20, 0x0, 0x0, 0x0, 0x0,
    0x8f, 0xff, 0x85, 0x55, 0x55, 0x55, 0x51, 0xf,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x40, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf4,

    /* U+0033 "3" */
    0x4, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf4, 0x0,
    0x4f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x40, 0x1,
    0x55, 0x55, 0x55, 0x5d, 0xff, 0x90, 0x0, 0x0,
    0x0, 0x0, 0xa, 0xff, 0x70, 0x0, 0x0, 0x0,
    0x0, 0x1c, 0xff, 0x50, 0x0, 0x0, 0x0, 0x0,
    0x1d, 0xfe, 0x30, 0x0, 0x0, 0x0, 0x0, 0x2e,
    0xfd, 0x20, 0x0, 0x0, 0x0, 0x0, 0x3e, 0xff,
    0xff, 0xc7, 0x10, 0x0, 0x0, 0x3f, 0xff, 0xff,
    0xff, 0xfe, 0x40, 0x0, 0x0, 0xce, 0x73, 0x25,
    0xcf, 0xff, 0x20, 0x0, 0x1, 0x20, 0x0, 0x0,
    0x9f, 0xfb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xff, 0xf1, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb,
    0xff, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0xaf,
    0xf4, 0x0, 0x20, 0x0, 0x0, 0x0, 0xc, 0xff,
    0x32, 0xbf, 0x40, 0x0, 0x0, 0x2, 0xff, 0xe0,
    0x2f, 0xfe, 0x30, 0x0, 0x1, 0xcf, 0xf8, 0x0,
    0x8f, 0xff, 0xb7, 0x69, 0xef, 0xfd, 0x0, 0x0,
    0x8f, 0xff, 0xff, 0xff, 0xfb, 0x10, 0x0, 0x0,
    0x29, 0xdf, 0xfd, 0xa4, 0x0, 0x0,

    /* U+0034 "4" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0xaf, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x6, 0xff, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x2f, 0xff, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xdf, 0xff, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x9, 0xff, 0xff, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x5f, 0xf9, 0xcf, 0xf0, 0x0,
    0x0, 0x0, 0x2, 0xff, 0xd0, 0xcf, 0xf0, 0x0,
    0x0, 0x0, 0xc, 0xff, 0x20, 0xcf, 0xf0, 0x0,
    0x0, 0x0, 0x8f, 0xf5, 0x0, 0xcf, 0xf0, 0x0,
    0x0, 0x4, 0xff, 0x90, 0x0, 0xcf, 0xf0, 0x0,
    0x0, 0x1e, 0xfd, 0x0, 0x0, 0xcf, 0xf0, 0x0,
    0x0, 0xbf, 0xf2, 0x0, 0x0, 0xcf, 0xf0, 0x0,
    0x7, 0xff, 0x50, 0x0, 0x0, 0xcf, 0xf0, 0x0,
    0x2f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe,
    0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe,
    0x16, 0x66, 0x66, 0x66, 0x66, 0xdf, 0xf6, 0x65,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xcf, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xcf, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xcf, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xcf, 0xf0, 0x0,

    /* U+0035 "5" */
    0x0, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xf2, 0x0,
    0xb, 0xff, 0xff, 0xff, 0xff, 0xff, 0x20, 0x0,
    0xdf, 0xe6, 0x66, 0x66, 0x66, 0x60, 0x0, 0xf,
    0xfb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0xff,
    0x90, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xf6,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0xff, 0x40,
    0x46, 0x52, 0x0, 0x0, 0x0, 0x8f, 0xfa, 0xff,
    0xff, 0xfc, 0x30, 0x0, 0xa, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x50, 0x0, 0xcf, 0xfd, 0x51, 0x3,
    0xbf, 0xff, 0x20, 0x4, 0x9b, 0x0, 0x0, 0x0,
    0xbf, 0xf9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2,
    0xff, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xef,
    0xf1, 0x0, 0x10, 0x0, 0x0, 0x0, 0xf, 0xff,
    0x1, 0x9f, 0x50, 0x0, 0x0, 0x5, 0xff, 0xc0,
    0x2f, 0xff, 0x40, 0x0, 0x1, 0xef, 0xf6, 0x0,
    0x8f, 0xff, 0xb7, 0x69, 0xff, 0xfb, 0x0, 0x0,
    0x8f, 0xff, 0xff, 0xff, 0xfb, 0x10, 0x0, 0x0,
    0x29, 0xdf, 0xfd, 0xa4, 0x0, 0x0,

    /* U+0036 "6" */
    0x0, 0x0, 0x0, 0x9, 0xff, 0xb0, 0x0, 0x0,
    0x0, 0x0, 0x5, 0xff, 0xd0, 0x0, 0x0, 0x0,
    0x0, 0x2, 0xff, 0xe1, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xcf, 0xf3, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x9f, 0xf5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5f,
    0xf7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xf9,
    0x35, 0x53, 0x0, 0x0, 0x0, 0xc, 0xff, 0xdf,
    0xff, 0xfe, 0x80, 0x0, 0x5, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xc0, 0x0, 0xdf, 0xff, 0x61, 0x1,
    0x7f, 0xff, 0x80, 0x3f, 0xff, 0x30, 0x0, 0x0,
    0x4f, 0xff, 0x7, 0xff, 0x90, 0x0, 0x0, 0x0,
    0xbf, 0xf5, 0x9f, 0xf6, 0x0, 0x0, 0x0, 0x7,
    0xff, 0x79, 0xff, 0x50, 0x0, 0x0, 0x0, 0x6f,
    0xf8, 0x8f, 0xf7, 0x0, 0x0, 0x0, 0x8, 0xff,
    0x64, 0xff, 0xc0, 0x0, 0x0, 0x0, 0xef, 0xf2,
    0xe, 0xff, 0x90, 0x0, 0x0, 0xaf, 0xfc, 0x0,
    0x4f, 0xff, 0xd8, 0x79, 0xef, 0xff, 0x20, 0x0,
    0x5e, 0xff, 0xff, 0xff, 0xfd, 0x30, 0x0, 0x0,
    0x17, 0xce, 0xfe, 0xb6, 0x0, 0x0,

    /* U+0037 "7" */
    0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xcf,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x57, 0x77,
    0x77, 0x77, 0x77, 0xaf, 0xf8, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xcf, 0xf1, 0x0, 0x0, 0x0, 0x0,
    0x3, 0xff, 0x90, 0x0, 0x0, 0x0, 0x0, 0xb,
    0xff, 0x20, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xfa,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xbf, 0xf2, 0x0,
    0x0, 0x0, 0x0, 0x2, 0xff, 0xb0, 0x0, 0x0,
    0x0, 0x0, 0xa, 0xff, 0x30, 0x0, 0x0, 0x0,
    0x0, 0x2f, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xaf, 0xf4, 0x0, 0x0, 0x0, 0x0, 0x2, 0xff,
    0xd0, 0x0, 0x0, 0x0, 0x0, 0x9, 0xff, 0x50,
    0x0, 0x0, 0x0, 0x0, 0x1f, 0xfd, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x9f, 0xf6, 0x0, 0x0, 0x0,
    0x0, 0x1, 0xff, 0xe0, 0x0, 0x0, 0x0, 0x0,
    0x8, 0xff, 0x70, 0x0, 0x0, 0x0, 0x0, 0x1f,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8f, 0xf8,
    0x0, 0x0, 0x0, 0x0,

    /* U+0038 "8" */
    0x0, 0x0, 0x6b, 0xef, 0xec, 0x71, 0x0, 0x0,
    0x3, 0xdf, 0xff, 0xff, 0xff, 0xe4, 0x0, 0x1,
    0xef, 0xfd, 0x75, 0x7c, 0xff, 0xf3, 0x0, 0x8f,
    0xfb, 0x0, 0x0, 0x8, 0xff, 0xb0, 0xc, 0xff,
    0x30, 0x0, 0x0, 0xf, 0xfe, 0x0, 0xcf, 0xf3,
    0x0, 0x0, 0x0, 0xff, 0xe0, 0x7, 0xff, 0xa0,
    0x0, 0x0, 0x7f, 0xfa, 0x0, 0xc, 0xff, 0xc7,
    0x56, 0xbf, 0xfe, 0x10, 0x0, 0x9, 0xff, 0xff,
    0xff, 0xfb, 0x10, 0x0, 0x5, 0xef, 0xff, 0xff,
    0xff, 0xf7, 0x0, 0x6, 0xff, 0xe6, 0x10, 0x15,
    0xdf, 0xf8, 0x1, 0xff, 0xe2, 0x0, 0x0, 0x0,
    0xcf, 0xf3, 0x7f, 0xf8, 0x0, 0x0, 0x0, 0x4,
    0xff, 0x99, 0xff, 0x40, 0x0, 0x0, 0x0, 0x1f,
    0xfc, 0x9f, 0xf5, 0x0, 0x0, 0x0, 0x2, 0xff,
    0xc7, 0xff, 0xa0, 0x0, 0x0, 0x0, 0x7f, 0xf9,
    0x1f, 0xff, 0x60, 0x0, 0x0, 0x4f, 0xff, 0x30,
    0x6f, 0xff, 0xc7, 0x67, 0xbf, 0xff, 0x90, 0x0,
    0x6e, 0xff, 0xff, 0xff, 0xff, 0x80, 0x0, 0x0,
    0x17, 0xce, 0xfe, 0xc8, 0x20, 0x0,

    /* U+0039 "9" */
    0x0, 0x0, 0x49, 0xdf, 0xfd, 0xa4, 0x0, 0x0,
    0x0, 0xa, 0xff, 0xff, 0xff, 0xff, 0xa1, 0x0,
    0x0, 0xbf, 0xff, 0xa7, 0x79, 0xff, 0xfb, 0x0,
    0x5, 0xff, 0xe2, 0x0, 0x0, 0x1d, 0xff, 0x60,
    0xc, 0xff, 0x40, 0x0, 0x0, 0x2, 0xff, 0xc0,
    0xe, 0xff, 0x0, 0x0, 0x0, 0x0, 0xef, 0xf0,
    0xf, 0xff, 0x0, 0x0, 0x0, 0x0, 0xdf, 0xf1,
    0xe, 0xff, 0x10, 0x0, 0x0, 0x0, 0xff, 0xf1,
    0xa, 0xff, 0x90, 0x0, 0x0, 0x8, 0xff, 0xf0,
    0x3, 0xff, 0xfb, 0x41, 0x13, 0xaf, 0xff, 0xb0,
    0x0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x50,
    0x0, 0x5, 0xdf, 0xff, 0xff, 0xef, 0xfd, 0x0,
    0x0, 0x0, 0x3, 0x56, 0x52, 0xef, 0xf4, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xb, 0xff, 0x80, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7f, 0xfc, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x4, 0xff, 0xf2, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1e, 0xff, 0x50, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xbf, 0xf9, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x8, 0xff, 0xc0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x4f, 0xff, 0x20, 0x0, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 280, .box_w = 15, .box_h = 20, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 150, .adv_w = 192, .box_w = 8, .box_h = 20, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 230, .adv_w = 248, .box_w = 15, .box_h = 20, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 380, .adv_w = 250, .box_w = 15, .box_h = 20, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 530, .adv_w = 267, .box_w = 16, .box_h = 20, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 690, .adv_w = 263, .box_w = 15, .box_h = 20, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 840, .adv_w = 264, .box_w = 15, .box_h = 20, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 990, .adv_w = 253, .box_w = 14, .box_h = 20, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 1130, .adv_w = 275, .box_w = 15, .box_h = 20, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 1280, .adv_w = 263, .box_w = 16, .box_h = 20, .ofs_x = 0, .ofs_y = 1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 48, .range_length = 10, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    1, 8,
    2, 8,
    4, 2,
    4, 6,
    4, 8,
    4, 10,
    5, 2,
    5, 6,
    5, 8,
    5, 10,
    6, 2,
    6, 7,
    6, 8,
    6, 10,
    7, 2,
    7, 8,
    7, 10,
    8, 1,
    8, 5,
    8, 6,
    8, 7,
    8, 8,
    8, 9,
    9, 2,
    9, 8,
    9, 10,
    10, 4,
    10, 5,
    10, 6,
    10, 7,
    10, 8,
    10, 9
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -15, -6, -8, -4, -11, -7, -9, -8,
    -21, -8, -9, -2, -13, -9, -22, -30,
    -13, -11, -40, -8, -28, 3, -9, -7,
    -18, -4, -4, -17, -4, -13, -13, -3
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 32,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t game_2048_font_28 = {
#else
lv_font_t game_2048_font_28 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 20,          /*The maximum line height required by the font*/
    .base_line = -1,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if GAME_2048_FONT_28*/

