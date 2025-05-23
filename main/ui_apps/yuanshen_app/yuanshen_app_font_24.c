/*******************************************************************************
 * Size: 24 px
 * Bpp: 4
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef YUANSHEN_APP_FONT_24
#define YUANSHEN_APP_FONT_24 1
#endif

#if YUANSHEN_APP_FONT_24

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+539F "原" */
    0x0, 0x0, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x10, 0x0, 0x5, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0,
    0x0, 0x5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf0, 0x0, 0x5, 0xfe, 0x0,
    0x0, 0x0, 0xe, 0xf8, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x5, 0xfe, 0x0, 0x0, 0x0, 0x4f, 0xf4,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0xfe, 0x2,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf2, 0x0,
    0x0, 0x5, 0xfe, 0x2, 0xff, 0xcc, 0xcc, 0xcc,
    0xcc, 0xcf, 0xf2, 0x0, 0x0, 0x5, 0xfe, 0x2,
    0xff, 0x0, 0x0, 0x0, 0x0, 0xe, 0xf2, 0x0,
    0x0, 0x5, 0xfe, 0x2, 0xff, 0xcc, 0xcc, 0xcc,
    0xcc, 0xcf, 0xf2, 0x0, 0x0, 0x5, 0xfe, 0x2,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf2, 0x0,
    0x0, 0x5, 0xfd, 0x2, 0xff, 0x0, 0x0, 0x0,
    0x0, 0xe, 0xf2, 0x0, 0x0, 0x6, 0xfd, 0x2,
    0xff, 0x0, 0x0, 0x0, 0x0, 0xe, 0xf2, 0x0,
    0x0, 0x6, 0xfc, 0x2, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf2, 0x0, 0x0, 0x7, 0xfb, 0x1,
    0xee, 0xee, 0xef, 0xff, 0xee, 0xee, 0xe2, 0x0,
    0x0, 0x9, 0xf9, 0x0, 0x1, 0x0, 0x5, 0xfe,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xc, 0xf8, 0x0,
    0xd, 0xc1, 0x5, 0xfe, 0x3, 0xe4, 0x0, 0x0,
    0x0, 0xf, 0xf5, 0x0, 0xaf, 0xf2, 0x5, 0xfe,
    0x8, 0xff, 0x50, 0x0, 0x0, 0x4f, 0xf1, 0x8,
    0xff, 0x50, 0x5, 0xfe, 0x0, 0x9f, 0xf5, 0x0,
    0x0, 0xaf, 0xc0, 0x7f, 0xf8, 0x0, 0x5, 0xfe,
    0x0, 0x9, 0xff, 0x50, 0x2, 0xff, 0x67, 0xff,
    0xa0, 0x33, 0x39, 0xfe, 0x0, 0x0, 0xaf, 0xf2,
    0xa, 0xff, 0x5, 0xfa, 0x0, 0xaf, 0xff, 0xfb,
    0x0, 0x0, 0xc, 0x70, 0x8, 0xf7, 0x0, 0x40,
    0x0, 0x7f, 0xfd, 0xa2, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,

    /* U+795E "神" */
    0x0, 0x0, 0x21, 0x0, 0x0, 0x0, 0x0, 0x46,
    0x10, 0x0, 0x0, 0x0, 0x7, 0xfa, 0x0, 0x0,
    0x0, 0x0, 0xcf, 0x40, 0x0, 0x0, 0x0, 0x2,
    0xff, 0x0, 0x0, 0x0, 0x0, 0xcf, 0x40, 0x0,
    0x0, 0x0, 0x0, 0xcf, 0x50, 0x0, 0x0, 0x0,
    0xcf, 0x50, 0x0, 0x0, 0x0, 0x11, 0x8f, 0x71,
    0xe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x8,
    0xff, 0xff, 0xff, 0xe, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xfe, 0x8, 0xff, 0xff, 0xff, 0xe, 0xf2,
    0x0, 0xcf, 0x40, 0x1, 0xfe, 0x0, 0x11, 0x19,
    0xfc, 0xe, 0xf2, 0x0, 0xcf, 0x40, 0x1, 0xfe,
    0x0, 0x0, 0x1f, 0xf5, 0xe, 0xf2, 0x0, 0xcf,
    0x40, 0x1, 0xfe, 0x0, 0x0, 0x9f, 0xd0, 0xe,
    0xf2, 0x11, 0xcf, 0x51, 0x12, 0xfe, 0x0, 0x3,
    0xff, 0xa0, 0xe, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xfe, 0x0, 0xd, 0xff, 0xfa, 0xe, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfe, 0x0, 0xaf, 0xff, 0xff,
    0xbe, 0xf2, 0x0, 0xcf, 0x40, 0x1, 0xfe, 0x8,
    0xff, 0xff, 0x4e, 0xff, 0xf2, 0x0, 0xcf, 0x40,
    0x1, 0xfe, 0x5f, 0xf8, 0xef, 0x22, 0x5e, 0xf2,
    0x0, 0xcf, 0x40, 0x1, 0xfe, 0x2f, 0xa0, 0xef,
    0x20, 0xe, 0xf3, 0x22, 0xcf, 0x62, 0x23, 0xfe,
    0x3, 0x0, 0xef, 0x20, 0xe, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfe, 0x0, 0x0, 0xef, 0x20, 0xe,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x0, 0x0,
    0xef, 0x20, 0x0, 0x0, 0x0, 0xcf, 0x40, 0x0,
    0x0, 0x0, 0x0, 0xef, 0x20, 0x0, 0x0, 0x0,
    0xcf, 0x40, 0x0, 0x0, 0x0, 0x0, 0xef, 0x20,
    0x0, 0x0, 0x0, 0xcf, 0x40, 0x0, 0x0, 0x0,
    0x0, 0xef, 0x20, 0x0, 0x0, 0x0, 0xcf, 0x40,
    0x0, 0x0, 0x0, 0x0, 0xde, 0x20, 0x0, 0x0,
    0x0, 0xcf, 0x40, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 384, .box_w = 24, .box_h = 23, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 276, .adv_w = 384, .box_w = 22, .box_h = 23, .ofs_x = 0, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x25bf
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 21407, .range_length = 9664, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 2, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t yuanshen_app_font_24 = {
#else
lv_font_t yuanshen_app_font_24 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 24,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if YUANSHEN_APP_FONT_24*/

