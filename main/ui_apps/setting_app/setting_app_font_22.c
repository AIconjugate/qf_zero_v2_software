/*******************************************************************************
 * Size: 22 px
 * Bpp: 4
 * Opts: --bpp 4 --size 22 --no-compress --font OPlusSans3-Medium.ttf --symbols 0123456789 --format lvgl -o setting_app_font_22.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef SETTING_APP_FONT_22
#define SETTING_APP_FONT_22 1
#endif

#if SETTING_APP_FONT_22

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0030 "0" */
    0x0, 0x8, 0xdf, 0xfc, 0x60, 0x0, 0x1, 0xdf,
    0xff, 0xff, 0xfb, 0x0, 0xb, 0xff, 0x50, 0x17,
    0xff, 0x70, 0x2f, 0xf5, 0x0, 0x0, 0x9f, 0xe0,
    0x6f, 0xf0, 0x0, 0x0, 0x3f, 0xf2, 0x8f, 0xd0,
    0x0, 0x0, 0xf, 0xf5, 0x9f, 0xb0, 0x0, 0x0,
    0xf, 0xf6, 0xaf, 0xb0, 0x0, 0x0, 0xe, 0xf6,
    0xaf, 0xb0, 0x0, 0x0, 0xe, 0xf6, 0xaf, 0xb0,
    0x0, 0x0, 0xf, 0xf6, 0x9f, 0xb0, 0x0, 0x0,
    0xf, 0xf6, 0x8f, 0xc0, 0x0, 0x0, 0xf, 0xf5,
    0x6f, 0xf0, 0x0, 0x0, 0x3f, 0xf2, 0x2f, 0xf5,
    0x0, 0x0, 0x8f, 0xe0, 0xa, 0xfe, 0x40, 0x6,
    0xff, 0x70, 0x1, 0xdf, 0xff, 0xff, 0xfb, 0x0,
    0x0, 0x8, 0xdf, 0xfc, 0x60, 0x0,

    /* U+0031 "1" */
    0x0, 0x1, 0x9f, 0xd0, 0x7, 0xff, 0xfd, 0xd,
    0xff, 0xff, 0xd1, 0xfe, 0x77, 0xfd, 0x19, 0x10,
    0x7f, 0xd0, 0x0, 0x7, 0xfd, 0x0, 0x0, 0x7f,
    0xd0, 0x0, 0x7, 0xfd, 0x0, 0x0, 0x7f, 0xd0,
    0x0, 0x7, 0xfd, 0x0, 0x0, 0x7f, 0xd0, 0x0,
    0x7, 0xfd, 0x0, 0x0, 0x7f, 0xd0, 0x0, 0x7,
    0xfd, 0x0, 0x0, 0x7f, 0xd0, 0x0, 0x7, 0xfd,
    0x0, 0x0, 0x7f, 0xd0,

    /* U+0032 "2" */
    0x0, 0x5, 0xcf, 0xfd, 0x70, 0x0, 0x0, 0xaf,
    0xff, 0xff, 0xfd, 0x0, 0x7, 0xff, 0x61, 0x6,
    0xff, 0x90, 0xe, 0xf6, 0x0, 0x0, 0x8f, 0xf0,
    0x7, 0xb0, 0x0, 0x0, 0x5f, 0xf1, 0x0, 0x0,
    0x0, 0x0, 0x5f, 0xf1, 0x0, 0x0, 0x0, 0x0,
    0x9f, 0xd0, 0x0, 0x0, 0x0, 0x2, 0xff, 0x70,
    0x0, 0x0, 0x0, 0x1d, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0xcf, 0xe2, 0x0, 0x0, 0x0, 0xb, 0xff,
    0x30, 0x0, 0x0, 0x0, 0xaf, 0xf4, 0x0, 0x0,
    0x0, 0x9, 0xff, 0x50, 0x0, 0x0, 0x0, 0x8f,
    0xf5, 0x0, 0x0, 0x0, 0x7, 0xff, 0x60, 0x0,
    0x0, 0x0, 0x2f, 0xff, 0xee, 0xee, 0xee, 0xe2,
    0x3f, 0xff, 0xff, 0xff, 0xff, 0xf3,

    /* U+0033 "3" */
    0xa, 0xff, 0xff, 0xff, 0xff, 0x70, 0x9, 0xee,
    0xee, 0xef, 0xff, 0x50, 0x0, 0x0, 0x0, 0x2e,
    0xf8, 0x0, 0x0, 0x0, 0x2, 0xef, 0x80, 0x0,
    0x0, 0x0, 0x1e, 0xf8, 0x0, 0x0, 0x0, 0x1,
    0xdf, 0x80, 0x0, 0x0, 0x0, 0x1d, 0xff, 0xb9,
    0x30, 0x0, 0x0, 0xcf, 0xff, 0xff, 0xf9, 0x0,
    0x0, 0x5c, 0x30, 0x29, 0xff, 0x70, 0x0, 0x0,
    0x0, 0x0, 0xaf, 0xe0, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0xf2, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xf3,
    0x1, 0x10, 0x0, 0x0, 0x3f, 0xf2, 0x5f, 0xb0,
    0x0, 0x0, 0xaf, 0xe0, 0x1f, 0xfa, 0x20, 0x18,
    0xff, 0x60, 0x5, 0xff, 0xff, 0xff, 0xf9, 0x0,
    0x0, 0x29, 0xdf, 0xeb, 0x40, 0x0,

    /* U+0034 "4" */
    0x0, 0x0, 0x0, 0x0, 0xdf, 0x40, 0x0, 0x0,
    0x0, 0x0, 0x9f, 0xf4, 0x0, 0x0, 0x0, 0x0,
    0x4f, 0xff, 0x40, 0x0, 0x0, 0x0, 0x1e, 0xff,
    0xf4, 0x0, 0x0, 0x0, 0xa, 0xfa, 0xff, 0x40,
    0x0, 0x0, 0x5, 0xfe, 0x1f, 0xf4, 0x0, 0x0,
    0x1, 0xef, 0x40, 0xff, 0x40, 0x0, 0x0, 0xaf,
    0x90, 0xf, 0xf4, 0x0, 0x0, 0x5f, 0xd0, 0x0,
    0xff, 0x40, 0x0, 0x1e, 0xf3, 0x0, 0xf, 0xf4,
    0x0, 0xb, 0xf8, 0x0, 0x0, 0xff, 0x40, 0x4,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0x5f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x80, 0x0, 0x0, 0x0,
    0xf, 0xf4, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
    0x40, 0x0, 0x0, 0x0, 0x0, 0xf, 0xf4, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xff, 0x40, 0x0,

    /* U+0035 "5" */
    0x5, 0xff, 0xff, 0xff, 0xff, 0x10, 0x6f, 0xff,
    0xff, 0xff, 0xf1, 0x8, 0xf9, 0x0, 0x0, 0x0,
    0x0, 0xaf, 0x70, 0x0, 0x0, 0x0, 0xc, 0xf4,
    0x0, 0x0, 0x0, 0x0, 0xef, 0x20, 0x0, 0x0,
    0x0, 0xf, 0xf6, 0xcf, 0xeb, 0x40, 0x2, 0xff,
    0xff, 0xff, 0xff, 0x60, 0x4f, 0xf8, 0x10, 0x2c,
    0xff, 0x20, 0x25, 0x0, 0x0, 0xe, 0xf9, 0x0,
    0x0, 0x0, 0x0, 0x9f, 0xc0, 0x0, 0x0, 0x0,
    0x8, 0xfd, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xc6,
    0xf8, 0x0, 0x0, 0xe, 0xf8, 0x4f, 0xf8, 0x10,
    0x2b, 0xff, 0x20, 0x8f, 0xff, 0xff, 0xff, 0x50,
    0x0, 0x4b, 0xef, 0xea, 0x20, 0x0,

    /* U+0036 "6" */
    0x0, 0x0, 0x6, 0xff, 0x30, 0x0, 0x0, 0x0,
    0x2f, 0xf7, 0x0, 0x0, 0x0, 0x0, 0xcf, 0xb0,
    0x0, 0x0, 0x0, 0x8, 0xfe, 0x10, 0x0, 0x0,
    0x0, 0x3f, 0xf3, 0x0, 0x0, 0x0, 0x0, 0xdf,
    0x70, 0x0, 0x0, 0x0, 0x8, 0xfe, 0xae, 0xec,
    0x60, 0x0, 0x1f, 0xff, 0xff, 0xff, 0xfb, 0x0,
    0x7f, 0xfc, 0x30, 0x29, 0xff, 0x70, 0xbf, 0xe0,
    0x0, 0x0, 0xaf, 0xe0, 0xef, 0x80, 0x0, 0x0,
    0x3f, 0xf1, 0xef, 0x60, 0x0, 0x0, 0x2f, 0xf2,
    0xcf, 0x80, 0x0, 0x0, 0x3f, 0xf1, 0x8f, 0xe0,
    0x0, 0x0, 0xaf, 0xd0, 0x2f, 0xfc, 0x30, 0x29,
    0xff, 0x60, 0x5, 0xff, 0xff, 0xff, 0xf9, 0x0,
    0x0, 0x29, 0xef, 0xeb, 0x40, 0x0,

    /* U+0037 "7" */
    0xf, 0xff, 0xff, 0xff, 0xff, 0xfa, 0xf, 0xff,
    0xff, 0xff, 0xff, 0xf9, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xf3, 0x0, 0x0, 0x0, 0x0, 0x7f, 0xc0,
    0x0, 0x0, 0x0, 0x0, 0xdf, 0x50, 0x0, 0x0,
    0x0, 0x5, 0xfe, 0x0, 0x0, 0x0, 0x0, 0xc,
    0xf7, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xf1, 0x0,
    0x0, 0x0, 0x0, 0xaf, 0xa0, 0x0, 0x0, 0x0,
    0x2, 0xff, 0x30, 0x0, 0x0, 0x0, 0x8, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xf5, 0x0, 0x0,
    0x0, 0x0, 0x7f, 0xe0, 0x0, 0x0, 0x0, 0x0,
    0xef, 0x70, 0x0, 0x0, 0x0, 0x5, 0xff, 0x10,
    0x0, 0x0, 0x0, 0xc, 0xf9, 0x0, 0x0, 0x0,
    0x0, 0x3f, 0xf2, 0x0, 0x0, 0x0,

    /* U+0038 "8" */
    0x0, 0x18, 0xdf, 0xeb, 0x50, 0x0, 0x2, 0xef,
    0xff, 0xff, 0xf8, 0x0, 0xc, 0xfd, 0x20, 0x7,
    0xff, 0x40, 0x2f, 0xf3, 0x0, 0x0, 0xbf, 0xa0,
    0x4f, 0xf0, 0x0, 0x0, 0x8f, 0xb0, 0x2f, 0xf4,
    0x0, 0x0, 0xcf, 0x90, 0xa, 0xfe, 0x40, 0x19,
    0xff, 0x20, 0x0, 0xaf, 0xff, 0xff, 0xe4, 0x0,
    0x3, 0xdf, 0xfe, 0xff, 0xf9, 0x0, 0x2f, 0xf9,
    0x10, 0x4, 0xef, 0x90, 0xaf, 0xb0, 0x0, 0x0,
    0x3f, 0xf2, 0xef, 0x70, 0x0, 0x0, 0xe, 0xf5,
    0xef, 0x70, 0x0, 0x0, 0xf, 0xf6, 0xbf, 0xc0,
    0x0, 0x0, 0x4f, 0xf3, 0x4f, 0xfa, 0x20, 0x5,
    0xef, 0xc0, 0x7, 0xff, 0xff, 0xff, 0xfd, 0x10,
    0x0, 0x39, 0xdf, 0xec, 0x70, 0x0,

    /* U+0039 "9" */
    0x0, 0x4, 0xbe, 0xfd, 0x92, 0x0, 0x0, 0x9f,
    0xff, 0xff, 0xff, 0x40, 0x6, 0xff, 0x81, 0x3,
    0xcf, 0xf1, 0xd, 0xf9, 0x0, 0x0, 0xe, 0xf8,
    0x1f, 0xf3, 0x0, 0x0, 0x9, 0xfc, 0x3f, 0xf1,
    0x0, 0x0, 0x7, 0xfd, 0x2f, 0xf3, 0x0, 0x0,
    0x9, 0xfd, 0xe, 0xf9, 0x0, 0x0, 0xe, 0xfb,
    0x8, 0xff, 0x92, 0x3, 0xcf, 0xf6, 0x0, 0xcf,
    0xff, 0xff, 0xff, 0xf0, 0x0, 0x7, 0xcf, 0xea,
    0xef, 0x70, 0x0, 0x0, 0x0, 0x7, 0xfd, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0xf3, 0x0, 0x0, 0x0,
    0x1, 0xef, 0x70, 0x0, 0x0, 0x0, 0xb, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0x7f, 0xf2, 0x0, 0x0,
    0x0, 0x3, 0xff, 0x60, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 220, .box_w = 12, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 102, .adv_w = 151, .box_w = 7, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 162, .adv_w = 195, .box_w = 12, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 264, .adv_w = 196, .box_w = 12, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 366, .adv_w = 210, .box_w = 13, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 477, .adv_w = 207, .box_w = 11, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 571, .adv_w = 207, .box_w = 12, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 673, .adv_w = 199, .box_w = 12, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 775, .adv_w = 216, .box_w = 12, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 877, .adv_w = 207, .box_w = 12, .box_h = 17, .ofs_x = 0, .ofs_y = 0}
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
    -12, -5, -6, -4, -9, -6, -7, -6,
    -16, -6, -7, -2, -11, -7, -18, -23,
    -11, -8, -32, -6, -22, 2, -7, -5,
    -14, -4, -3, -13, -3, -10, -10, -2
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
const lv_font_t setting_app_font_22 = {
#else
lv_font_t setting_app_font_22 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 17,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
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



#endif /*#if SETTING_APP_FONT_22*/

