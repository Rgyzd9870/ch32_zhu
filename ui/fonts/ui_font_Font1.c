/*******************************************************************************
 * Size: 20 px
 * Bpp: 1
 * Opts: --bpp 1 --size 20 --font F:/ui/ui5/assets/PingFangHeiFangTi-2.ttf -o F:/ui/ui5/assets\ui_font_Font1.c --format lvgl -r 0x20-0x7f --symbols 心率传感器 --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_FONT1
#define UI_FONT_FONT1 1
#endif

#if UI_FONT_FONT1

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xff, 0xf6, 0xc3, 0x7e,

    /* U+0022 "\"" */
    0xde, 0xf6,

    /* U+0023 "#" */
    0x30, 0x3f, 0x36, 0xff, 0xff, 0x3c, 0xff, 0xff,
    0x6c, 0x48, 0x48,

    /* U+0024 "$" */
    0x18, 0xff, 0xff, 0xd8, 0xd8, 0xff, 0xff, 0x1b,
    0xfb, 0xff, 0xff, 0x18,

    /* U+0025 "%" */
    0x0, 0x1e, 0x3b, 0xc7, 0x69, 0xcd, 0x31, 0xee,
    0x3f, 0x80, 0x70, 0x1f, 0xe3, 0x7c, 0xed, 0x99,
    0xf6, 0x3e, 0xc0, 0x0,

    /* U+0026 "&" */
    0x7e, 0xf, 0xc1, 0x98, 0x33, 0x7, 0xe8, 0xff,
    0x9f, 0x67, 0x3c, 0xc3, 0xd8, 0x3f, 0xfd, 0x7f,
    0x80,

    /* U+0027 "'" */
    0xfb, 0x60,

    /* U+0028 "(" */
    0x39, 0x8c, 0xe6, 0x31, 0x8c, 0x63, 0x18, 0xe3,
    0x18,

    /* U+0029 ")" */
    0xe3, 0x18, 0xe3, 0x18, 0xc6, 0x31, 0x8c, 0xe6,
    0x30,

    /* U+002A "*" */
    0x33, 0xff, 0xde, 0xff, 0xb4, 0x80,

    /* U+002B "+" */
    0x18, 0xc, 0x6, 0x1f, 0xff, 0xf8, 0xfc, 0x60,
    0x30, 0x18, 0x0,

    /* U+002C "," */
    0x27, 0x77, 0x70,

    /* U+002D "-" */
    0xff, 0xc6,

    /* U+002E "." */
    0xff, 0x80,

    /* U+002F "/" */
    0x6, 0xe, 0xe, 0xc, 0x1c, 0x18, 0x38, 0x30,
    0x30, 0x70, 0x60, 0x60, 0xc0,

    /* U+0030 "0" */
    0xff, 0xff, 0xf3, 0xcf, 0x3c, 0xf3, 0xcf, 0xff,
    0xff,

    /* U+0031 "1" */
    0xff, 0xff, 0xff,

    /* U+0032 "2" */
    0xe0, 0xfe, 0xfe, 0x8e, 0x1c, 0x18, 0x38, 0x70,
    0xe0, 0xef, 0xff, 0xff,

    /* U+0033 "3" */
    0xff, 0xff, 0xf8, 0x31, 0xef, 0xdc, 0x3f, 0x7,
    0xcf, 0xff, 0xf0,

    /* U+0034 "4" */
    0x0, 0x1, 0x80, 0xe0, 0x7c, 0x3f, 0x1e, 0xc7,
    0xb3, 0xcf, 0xff, 0xff, 0xf0, 0x70, 0x1c, 0x7,
    0x0,

    /* U+0035 "5" */
    0xff, 0xff, 0xfe, 0xc, 0x1f, 0xff, 0x83, 0x7,
    0xff, 0xff, 0xf0,

    /* U+0036 "6" */
    0xff, 0xff, 0xff, 0xe, 0x1f, 0xff, 0xf3, 0xe7,
    0xff, 0xff, 0xf0,

    /* U+0037 "7" */
    0xff, 0xff, 0xff, 0x6, 0x6, 0xe, 0xc, 0x1c,
    0x1c, 0x18, 0x38, 0x38,

    /* U+0038 "8" */
    0xff, 0xff, 0x9f, 0x3f, 0xef, 0x8f, 0x7f, 0xe7,
    0xcf, 0xff, 0xf0,

    /* U+0039 "9" */
    0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0x87, 0xf,
    0xff, 0xff, 0xf0,

    /* U+003A ":" */
    0xff, 0x80, 0x3f, 0xe0,

    /* U+003B ";" */
    0x77, 0x70, 0x6, 0x6e, 0xe2,

    /* U+003C "<" */
    0x2, 0x1c, 0xfb, 0xce, 0x7, 0x87, 0x83, 0x0,

    /* U+003D "=" */
    0xff, 0xff, 0xc0, 0x0, 0xf, 0xff, 0xfc,

    /* U+003E ">" */
    0x81, 0xc3, 0xe1, 0xe0, 0xef, 0x3c, 0x60, 0x0,

    /* U+003F "?" */
    0xff, 0xf0, 0xc7, 0x18, 0xc3, 0xc, 0x30, 0x3,
    0xc,

    /* U+0040 "@" */
    0x3, 0x81, 0xfe, 0x1f, 0xb8, 0xc0, 0xe6, 0xfb,
    0xb7, 0xcd, 0xb6, 0xcd, 0xf6, 0xff, 0xf3, 0xc3,
    0x8f, 0xe0, 0x1f, 0x0,

    /* U+0041 "A" */
    0xe, 0x1, 0xc0, 0x7c, 0xf, 0x81, 0xb8, 0x77,
    0xe, 0xe1, 0xfe, 0x7f, 0xcf, 0xf9, 0xc3, 0xf0,
    0x70,

    /* U+0042 "B" */
    0xff, 0xff, 0xc7, 0xc7, 0xff, 0xfe, 0xff, 0xff,
    0xdf, 0xc7, 0xff, 0xff,

    /* U+0043 "C" */
    0x1, 0xff, 0xff, 0xff, 0xc0, 0xc0, 0xc0, 0xc0,
    0xff, 0xff, 0xff,

    /* U+0044 "D" */
    0xf8, 0xff, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xff,
    0xff, 0xff, 0xc0,

    /* U+0045 "E" */
    0xf, 0xff, 0xff, 0xc0, 0xc0, 0xfe, 0xfe, 0xfe,
    0xc0, 0xc7, 0xff, 0xff,

    /* U+0046 "F" */
    0x1f, 0xff, 0xfe, 0xc, 0x1f, 0xff, 0xff, 0xc1,
    0x83, 0x6, 0x4, 0x0,

    /* U+0047 "G" */
    0x1f, 0xff, 0xff, 0xc0, 0xdc, 0xdf, 0xdf, 0xc3,
    0xff, 0xff, 0xff,

    /* U+0048 "H" */
    0xc1, 0xe0, 0xf0, 0x7f, 0xff, 0xff, 0xff, 0x7,
    0x83, 0xc1, 0xe0, 0xc0,

    /* U+0049 "I" */
    0xfd, 0xff, 0xff, 0xf3, 0x6, 0xc, 0x18, 0x31,
    0xff, 0xff, 0xf0,

    /* U+004A "J" */
    0xff, 0xff, 0xff, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c,
    0x1c, 0x7c, 0x7c, 0x7c, 0x40,

    /* U+004B "K" */
    0xc2, 0xc6, 0xcf, 0xde, 0xf8, 0xe0, 0xf0, 0xff,
    0xdf, 0xcf, 0xc3, 0xc0,

    /* U+004C "L" */
    0xe1, 0xc3, 0x87, 0xe, 0x1c, 0x38, 0x70, 0xe1,
    0xff, 0xff, 0xf0,

    /* U+004D "M" */
    0xf3, 0xfc, 0xff, 0x3f, 0xcf, 0xf3, 0xf6, 0xfd,
    0xaf, 0x7b, 0xce, 0xfb, 0xbe, 0xcf, 0x93,

    /* U+004E "N" */
    0xe3, 0xe3, 0xf3, 0xf3, 0xd3, 0xdb, 0xdb, 0xdf,
    0xcf, 0xcf, 0xcf, 0xc7,

    /* U+004F "O" */
    0xff, 0xff, 0xff, 0xfc, 0x7e, 0x3f, 0x1f, 0x8f,
    0xc7, 0xff, 0xff, 0xff, 0xe0,

    /* U+0050 "P" */
    0xff, 0xff, 0xfe, 0x3c, 0x7f, 0xff, 0xe0, 0xc1,
    0x83, 0x6, 0x0,

    /* U+0051 "Q" */
    0xff, 0x7f, 0xbf, 0xdc, 0xee, 0x77, 0x3b, 0xfd,
    0xfe, 0xff, 0x6, 0x3, 0xe1, 0xf0,

    /* U+0052 "R" */
    0xff, 0xff, 0xc7, 0xc7, 0xff, 0xff, 0xf0, 0xdc,
    0xde, 0xcf, 0xc7, 0xc2,

    /* U+0053 "S" */
    0xff, 0xff, 0xfe, 0xc, 0x1f, 0xff, 0xe3, 0x7,
    0xff, 0xff, 0xf0,

    /* U+0054 "T" */
    0xff, 0xff, 0xff, 0xe3, 0x1, 0x80, 0xc0, 0x60,
    0x30, 0x18, 0xc, 0x6, 0x3, 0x0,

    /* U+0055 "U" */
    0xe3, 0xf1, 0xf8, 0xfc, 0x7e, 0x3f, 0x1f, 0x8f,
    0xc7, 0x7f, 0xbf, 0xdf, 0xe0,

    /* U+0056 "V" */
    0xf0, 0xee, 0x19, 0xc7, 0x38, 0xe3, 0x98, 0x73,
    0x6, 0xe0, 0xd8, 0x1f, 0x1, 0xe0, 0x3c, 0x0,

    /* U+0057 "W" */
    0xcd, 0xf3, 0x7d, 0xdf, 0x73, 0xde, 0xf5, 0xbf,
    0x6f, 0xcf, 0xf3, 0xfc, 0xff, 0x3f, 0xcf,

    /* U+0058 "X" */
    0xe7, 0xe7, 0x7e, 0x3c, 0x3c, 0x3c, 0x3c, 0x7e,
    0xe7, 0xc3, 0x42,

    /* U+0059 "Y" */
    0xf3, 0x9c, 0xe3, 0xf0, 0xf8, 0x1e, 0x3, 0x0,
    0xc0, 0x30, 0xc, 0x3, 0x0, 0xc0, 0x30,

    /* U+005A "Z" */
    0xe0, 0xfe, 0xfe, 0x8e, 0x1c, 0x18, 0x38, 0x70,
    0xe0, 0xff, 0xff, 0xff,

    /* U+005B "[" */
    0x1f, 0xff, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0xff,
    0xfc,

    /* U+005C "\\" */
    0xe1, 0xc1, 0x83, 0x87, 0x6, 0xe, 0xc, 0x18,
    0x18, 0x30, 0x60, 0x60,

    /* U+005D "]" */
    0xcf, 0xf3, 0x33, 0x33, 0x33, 0x3f, 0xff,

    /* U+005E "^" */
    0x0, 0x18, 0x18, 0x3c, 0x66, 0x66, 0xe7,

    /* U+005F "_" */
    0xff, 0xfc,

    /* U+0060 "`" */
    0x4e, 0x62,

    /* U+0061 "a" */
    0xff, 0xfd, 0xd8, 0x3f, 0xff, 0xf1, 0xe3, 0xff,
    0xfc,

    /* U+0062 "b" */
    0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xff, 0xff, 0xff,
    0xc7, 0xc7, 0xff, 0xff,

    /* U+0063 "c" */
    0x1f, 0xff, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xff,
    0xff, 0xff,

    /* U+0064 "d" */
    0x1, 0x3, 0x3, 0x3, 0x3, 0xff, 0xff, 0xff,
    0xe3, 0xe3, 0xff, 0xff,

    /* U+0065 "e" */
    0xff, 0xff, 0x1f, 0xff, 0xf8, 0x3f, 0xff, 0xfe,

    /* U+0066 "f" */
    0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xc3, 0xc,
    0x0,

    /* U+0067 "g" */
    0x7f, 0x7f, 0x63, 0x63, 0x7f, 0x7f, 0x3, 0x3,
    0x43, 0x7f, 0x7f,

    /* U+0068 "h" */
    0xc1, 0x83, 0x6, 0xf, 0xff, 0xfd, 0xe3, 0xc7,
    0x8f, 0x1e, 0x30,

    /* U+0069 "i" */
    0xfd, 0x86, 0xdf, 0xff, 0xf0,

    /* U+006A "j" */
    0x33, 0x30, 0x33, 0x33, 0x33, 0x33, 0x3f, 0xf8,

    /* U+006B "k" */
    0xc9, 0x9b, 0x77, 0xef, 0x9c, 0x38, 0x7f, 0xff,
    0x9b, 0x16, 0x0,

    /* U+006C "l" */
    0xff, 0xff, 0xfc,

    /* U+006D "m" */
    0xc0, 0x3f, 0xff, 0xff, 0x33, 0xcc, 0xf3, 0x3c,
    0xcf, 0x33, 0xcc, 0xc0,

    /* U+006E "n" */
    0xc1, 0xff, 0xfe, 0x3c, 0x78, 0xf1, 0xe3, 0xc6,

    /* U+006F "o" */
    0xff, 0xff, 0xfe, 0x3c, 0x78, 0xff, 0xff,

    /* U+0070 "p" */
    0xff, 0xff, 0xfe, 0x3c, 0x7f, 0xff, 0xe0, 0xc1,
    0x83, 0x0,

    /* U+0071 "q" */
    0xff, 0xff, 0xfe, 0x3c, 0x78, 0xff, 0xff, 0x6,
    0xc, 0x18, 0x30,

    /* U+0072 "r" */
    0xc3, 0x3f, 0xff, 0xff, 0xc, 0x30, 0xc0,

    /* U+0073 "s" */
    0xff, 0xff, 0x87, 0xf, 0xff, 0xc1, 0xfb, 0xff,
    0xfc,

    /* U+0074 "t" */
    0x38, 0x73, 0xff, 0xf3, 0xe6, 0xc, 0x18, 0x30,
    0x78, 0xf0,

    /* U+0075 "u" */
    0xe3, 0xe3, 0xe3, 0x63, 0x63, 0x63, 0x63, 0x7f,
    0x7f,

    /* U+0076 "v" */
    0xe1, 0xb1, 0xdc, 0xe6, 0x63, 0x31, 0x98, 0x78,
    0x3c, 0xe, 0x0,

    /* U+0077 "w" */
    0xcc, 0xf3, 0x3c, 0xcf, 0x33, 0xcc, 0xf3, 0x3c,
    0xcf, 0xff, 0xff, 0xc0, 0x30,

    /* U+0078 "x" */
    0x44, 0xe6, 0xfe, 0x7c, 0x7c, 0x38, 0x3c, 0x7e,
    0xee, 0xc6,

    /* U+0079 "y" */
    0x22, 0x73, 0x9d, 0xc7, 0xe3, 0xe0, 0xf0, 0x70,
    0x38, 0x38, 0x1c, 0x4, 0x0,

    /* U+007A "z" */
    0xfd, 0xff, 0xf8, 0x61, 0xcf, 0x3c, 0x77, 0xff,
    0xfc,

    /* U+007B "{" */
    0x7b, 0xd8, 0xc6, 0x31, 0x98, 0x63, 0x18, 0xc6,
    0x38, 0x40,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xff,

    /* U+007D "}" */
    0xf7, 0x8c, 0x63, 0x18, 0xc3, 0x31, 0x8c, 0x63,
    0x39, 0x0,

    /* U+007E "~" */
    0xf3, 0xff, 0x8f,

    /* U+4F20 "传" */
    0x30, 0x60, 0x38, 0x70, 0x7f, 0xfe, 0x77, 0xfe,
    0x71, 0xc0, 0xff, 0xff, 0x7f, 0xff, 0x33, 0xff,
    0x33, 0xfe, 0x33, 0xfe, 0x30, 0x1c, 0x31, 0xfc,
    0x31, 0xfc, 0x30, 0x3c, 0x0, 0x8,

    /* U+5668 "器" */
    0x7e, 0xfd, 0x9b, 0x36, 0x6c, 0xdf, 0xb3, 0x7e,
    0xfc, 0x1f, 0xc7, 0xff, 0xdf, 0x3f, 0xf8, 0x3d,
    0xfb, 0xf7, 0xef, 0x9d, 0xb6, 0x7e, 0xf9, 0xfb,
    0xe0,

    /* U+5FC3 "心" */
    0x1, 0x80, 0x1, 0xc0, 0xe, 0xe0, 0xe, 0xe0,
    0x2e, 0x5c, 0x6e, 0xe, 0x6e, 0xe, 0x6e, 0x7,
    0xee, 0x6, 0xee, 0x18, 0x2e, 0x18, 0xf, 0xf8,
    0xf, 0xf8,

    /* U+611F "感" */
    0x0, 0x2c, 0x0, 0xec, 0x7f, 0xfe, 0x7f, 0xfe,
    0x7f, 0xf7, 0x7f, 0xfe, 0x7f, 0xbc, 0x7d, 0xb8,
    0x7f, 0xbe, 0x70, 0x7e, 0x70, 0xdc, 0x36, 0xc6,
    0x76, 0xff, 0x77, 0xff, 0x7, 0xf8,

    /* U+7387 "率" */
    0x1, 0x0, 0x1c, 0xf, 0xff, 0xbf, 0xfe, 0x4f,
    0xbb, 0xbe, 0xe7, 0xf0, 0x3d, 0xff, 0xef, 0xdf,
    0x1c, 0xf, 0xff, 0xbf, 0xfe, 0xff, 0xf8, 0xc,
    0x0, 0x30, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 80, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 100, .box_w = 3, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 6, .adv_w = 117, .box_w = 5, .box_h = 3, .ofs_x = 1, .ofs_y = 11},
    {.bitmap_index = 8, .adv_w = 172, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 19, .adv_w = 175, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 31, .adv_w = 208, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 51, .adv_w = 205, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 68, .adv_w = 74, .box_w = 3, .box_h = 4, .ofs_x = 1, .ofs_y = 10},
    {.bitmap_index = 70, .adv_w = 98, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 79, .adv_w = 100, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 88, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 94, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 105, .adv_w = 81, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 108, .adv_w = 108, .box_w = 5, .box_h = 3, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 110, .adv_w = 78, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 112, .adv_w = 124, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 125, .adv_w = 169, .box_w = 6, .box_h = 12, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 134, .adv_w = 169, .box_w = 2, .box_h = 12, .ofs_x = 4, .ofs_y = 1},
    {.bitmap_index = 137, .adv_w = 169, .box_w = 8, .box_h = 12, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 149, .adv_w = 169, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 160, .adv_w = 169, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 177, .adv_w = 169, .box_w = 7, .box_h = 12, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 188, .adv_w = 169, .box_w = 7, .box_h = 12, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 199, .adv_w = 169, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 211, .adv_w = 169, .box_w = 7, .box_h = 12, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 222, .adv_w = 169, .box_w = 7, .box_h = 12, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 233, .adv_w = 92, .box_w = 3, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 237, .adv_w = 97, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 242, .adv_w = 145, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 250, .adv_w = 185, .box_w = 9, .box_h = 6, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 257, .adv_w = 145, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 265, .adv_w = 127, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 274, .adv_w = 229, .box_w = 13, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 294, .adv_w = 184, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 311, .adv_w = 172, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 323, .adv_w = 172, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 334, .adv_w = 183, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 345, .adv_w = 165, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 357, .adv_w = 157, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 369, .adv_w = 176, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 380, .adv_w = 192, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 392, .adv_w = 138, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 403, .adv_w = 144, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 416, .adv_w = 180, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 428, .adv_w = 148, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 439, .adv_w = 212, .box_w = 10, .box_h = 12, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 454, .adv_w = 185, .box_w = 8, .box_h = 12, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 466, .adv_w = 186, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 479, .adv_w = 165, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 490, .adv_w = 185, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 504, .adv_w = 172, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 516, .adv_w = 160, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 527, .adv_w = 146, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 541, .adv_w = 189, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 554, .adv_w = 178, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 570, .adv_w = 213, .box_w = 10, .box_h = 12, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 585, .adv_w = 160, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 596, .adv_w = 155, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 611, .adv_w = 162, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 623, .adv_w = 126, .box_w = 5, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 632, .adv_w = 168, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 644, .adv_w = 126, .box_w = 4, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 651, .adv_w = 192, .box_w = 8, .box_h = 7, .ofs_x = 2, .ofs_y = 8},
    {.bitmap_index = 658, .adv_w = 162, .box_w = 7, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 660, .adv_w = 117, .box_w = 4, .box_h = 4, .ofs_x = 2, .ofs_y = 10},
    {.bitmap_index = 662, .adv_w = 153, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 671, .adv_w = 160, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 683, .adv_w = 158, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 693, .adv_w = 163, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 705, .adv_w = 160, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 713, .adv_w = 130, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 722, .adv_w = 151, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 733, .adv_w = 163, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 744, .adv_w = 86, .box_w = 3, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 749, .adv_w = 94, .box_w = 4, .box_h = 16, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 757, .adv_w = 151, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 768, .adv_w = 86, .box_w = 2, .box_h = 11, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 771, .adv_w = 196, .box_w = 10, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 783, .adv_w = 160, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 791, .adv_w = 154, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 798, .adv_w = 156, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 808, .adv_w = 157, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 819, .adv_w = 132, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 826, .adv_w = 145, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 835, .adv_w = 132, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 845, .adv_w = 167, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 854, .adv_w = 153, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 865, .adv_w = 194, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 878, .adv_w = 147, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 888, .adv_w = 143, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 901, .adv_w = 154, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 910, .adv_w = 120, .box_w = 5, .box_h = 15, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 920, .adv_w = 92, .box_w = 2, .box_h = 16, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 924, .adv_w = 120, .box_w = 5, .box_h = 15, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 934, .adv_w = 190, .box_w = 8, .box_h = 3, .ofs_x = 2, .ofs_y = 12},
    {.bitmap_index = 937, .adv_w = 320, .box_w = 16, .box_h = 15, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 967, .adv_w = 320, .box_w = 14, .box_h = 14, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 992, .adv_w = 320, .box_w = 16, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1018, .adv_w = 320, .box_w = 16, .box_h = 15, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 1048, .adv_w = 320, .box_w = 14, .box_h = 15, .ofs_x = 3, .ofs_y = -1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0x748, 0x10a3, 0x11ff, 0x2467
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 20256, .range_length = 9320, .glyph_id_start = 96,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 5, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 2, 2, 3, 2, 4,
    2, 5, 2, 6, 7, 8, 2, 5,
    2, 4, 2, 7, 2, 6, 2, 6,
    2, 9, 10, 11, 0, 0, 0, 0,
    0, 0, 12, 13, 14, 15, 12, 16,
    12, 12, 14, 14, 17, 14, 12, 12,
    12, 18, 2, 19, 14, 14, 12, 20,
    12, 17, 20, 12, 0, 0, 0, 0,
    0, 0, 0, 0, 0
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 2, 3, 2, 2, 2,
    3, 4, 5, 5, 2, 4, 2, 2,
    3, 2, 4, 2, 4, 6, 4, 7,
    4, 8, 9, 5, 0, 0, 0, 0,
    0, 0, 10, 11, 10, 10, 12, 13,
    14, 11, 13, 15, 11, 11, 12, 12,
    10, 12, 13, 12, 12, 16, 14, 16,
    10, 14, 17, 13, 0, 0, 0, 0,
    0, 0, 0, 0, 0
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    -33, -25, -28, -33, -30, -61, -67, -38,
    -77, -28, -31, -25, -27, -37, -39, -52,
    -57, -26, 0, -11, -12, -13, -26, -31,
    -20, -39, -13, -10, 0, 0, -20, -32,
    -25, -34, -31, 0, -12, -13, -17, -30,
    -34, -22, -48, -16, -13, -11, -11, -21,
    -41, -25, -32, -51, -13, -20, -15, -20,
    -23, -28, -28, -32, -25, -13, -20, -18,
    -27, -45, -27, -35, -37, 0, -14, -12,
    -17, -24, -28, -23, -35, -20, -12, -14,
    -13, -24, -41, -24, -32, -58, -18, -28,
    -21, -21, -20, -28, -31, -29, -35, -20,
    -32, -25, -38, -50, -33, -48, -34, -14,
    -17, -17, -20, -31, -36, -24, -47, -20,
    -17, -17, -16, -28, -44, -33, -44, -24,
    -16, -16, -24, -21, -58, -64, -25, -73,
    -17, -24, -15, -14, -28, -33, -50, -55,
    -36, -17, -23, -21, -19, -30, -35, -27,
    -42, -25, -20, -24, -21, -35, -47, -38,
    -52, -77, -33, -47, -35, -33, -31, -35,
    -42, -35, -54, -33, -53, -40, -57, -59,
    -49, -66, -26, -13, -18, -17, -14, -30,
    -36, -21, -41, -18, -15, -16, -15, -27,
    -34, -32, -44, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -18, -18, -13, -13,
    -24, -35, -30, -37, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -19, -18, -13,
    -14, -25, -38, -33, -37, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -18, -16,
    -15, -16, -24, -35, -27, -34, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -16,
    0, -11, -11, -20, -33, -23, -32, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -32, -19, -22, -24, -30, -50, -32, -34,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -26, -22, -23, -22, -33, -51, -34,
    -48, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -20, -16, -13, -16, -24, -47,
    -25, -32, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -30, -20, -20, -22, -27,
    -51, -28, -31, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -37, -27, -29, -30,
    -36, -60, -34, -39
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 20,
    .right_class_cnt     = 17,
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
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 1,
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
const lv_font_t ui_font_Font1 = {
#else
lv_font_t ui_font_Font1 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 18,          /*The maximum line height required by the font*/
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



#endif /*#if UI_FONT_FONT1*/

