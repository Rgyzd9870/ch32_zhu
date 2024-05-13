/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --font F:/ui/ui5/assets/PingFangHeiFangTi-2.ttf -o F:/ui/ui5/assets\ui_font_Font2.c --format lvgl -r 0x20-0x7f --symbols 步数 --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_FONT2
#define UI_FONT_FONT2 1
#endif

#if UI_FONT_FONT2

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xfc, 0xf0,

    /* U+0022 "\"" */
    0x5a, 0xd6,

    /* U+0023 "#" */
    0x2c, 0xbf, 0xff, 0xff, 0xf5, 0x14, 0x0,

    /* U+0024 "$" */
    0x33, 0xff, 0xec, 0xb3, 0xff, 0xcf, 0xff, 0xf3,
    0x0,

    /* U+0025 "%" */
    0x2, 0x79, 0xbd, 0x96, 0xcf, 0xc7, 0xe0, 0x60,
    0x2f, 0x37, 0x92, 0xd9, 0xe8, 0x0,

    /* U+0026 "&" */
    0x7c, 0x3e, 0x1b, 0xd, 0x87, 0xf1, 0x99, 0xbd,
    0x8f, 0xcf, 0xff, 0x0,

    /* U+0027 "'" */
    0xf8,

    /* U+0028 "(" */
    0x66, 0x64, 0xcc, 0xcc, 0xc4, 0x66,

    /* U+0029 ")" */
    0x66, 0x62, 0x33, 0x33, 0x32, 0x66,

    /* U+002A "*" */
    0x67, 0xbf, 0xed, 0x0,

    /* U+002B "+" */
    0x18, 0x18, 0x18, 0xff, 0xff, 0x18, 0x18, 0x18,

    /* U+002C "," */
    0x6d, 0xb0,

    /* U+002D "-" */
    0x7f, 0x10,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0xc, 0x71, 0x86, 0x30, 0xc3, 0x18, 0x61, 0xc,
    0x0,

    /* U+0030 "0" */
    0xff, 0xf7, 0xbd, 0xef, 0x7f, 0xff, 0xc0,

    /* U+0031 "1" */
    0xff, 0xff, 0xf0,

    /* U+0032 "2" */
    0xc3, 0xff, 0xc6, 0x38, 0xc6, 0x39, 0xff, 0xf0,

    /* U+0033 "3" */
    0xff, 0xf0, 0x4f, 0x7d, 0xf1, 0xc3, 0xff, 0xf0,

    /* U+0034 "4" */
    0x0, 0x18, 0x18, 0x3c, 0x7c, 0x6c, 0xcf, 0xff,
    0xff, 0xc, 0xc,

    /* U+0035 "5" */
    0xff, 0xff, 0xf0, 0xff, 0xf0, 0xc3, 0xff, 0xf0,

    /* U+0036 "6" */
    0xff, 0xfc, 0x30, 0xff, 0xfc, 0xf3, 0xff, 0xf0,

    /* U+0037 "7" */
    0xff, 0xf8, 0xc2, 0x18, 0x63, 0x8c, 0x31, 0xc0,

    /* U+0038 "8" */
    0xff, 0xfc, 0xf3, 0x79, 0xec, 0xf3, 0xff, 0xf0,

    /* U+0039 "9" */
    0xff, 0xfc, 0xf3, 0xff, 0xf0, 0xc3, 0xff, 0xf0,

    /* U+003A ":" */
    0xf0, 0xf,

    /* U+003B ";" */
    0x33, 0x0, 0x66, 0x60,

    /* U+003C "<" */
    0x4, 0x73, 0xf0, 0x3c, 0x70, 0x40,

    /* U+003D "=" */
    0xff, 0xfc, 0x7, 0xff, 0xe0,

    /* U+003E ">" */
    0x83, 0x8f, 0x3, 0xf3, 0x88, 0x0,

    /* U+003F "?" */
    0xff, 0xc6, 0x63, 0x18, 0xc0, 0x23, 0x80,

    /* U+0040 "@" */
    0x1e, 0x1f, 0xc4, 0x19, 0x7b, 0xde, 0xf7, 0xbd,
    0xf9, 0x86, 0x3e, 0x7, 0x0,

    /* U+0041 "A" */
    0x1c, 0xe, 0x7, 0x7, 0xc3, 0x61, 0xb1, 0xfc,
    0xfe, 0x63, 0x71, 0xc0,

    /* U+0042 "B" */
    0xff, 0xfc, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xf0,

    /* U+0043 "C" */
    0x3f, 0xff, 0xfe, 0xc, 0x18, 0x33, 0xff, 0xfe,

    /* U+0044 "D" */
    0xf1, 0xff, 0x7e, 0x3c, 0x78, 0xff, 0xff, 0xf0,

    /* U+0045 "E" */
    0x1f, 0xff, 0xf0, 0xff, 0xfc, 0x33, 0xff, 0xf0,

    /* U+0046 "F" */
    0xff, 0xfc, 0x30, 0xff, 0xfc, 0x30, 0xc3, 0x0,

    /* U+0047 "G" */
    0x3f, 0xff, 0xfe, 0xd, 0xfb, 0xf1, 0xff, 0xfe,

    /* U+0048 "H" */
    0xc7, 0x8f, 0x1f, 0xff, 0xf8, 0xf1, 0xe3,

    /* U+0049 "I" */
    0xfb, 0xff, 0xcc, 0x30, 0xc3, 0xf, 0xff, 0xf0,

    /* U+004A "J" */
    0xff, 0xf3, 0xc, 0x30, 0xc3, 0x3c, 0xf1, 0x0,

    /* U+004B "K" */
    0xc5, 0x9b, 0x7f, 0xcf, 0x1c, 0x3f, 0xef, 0xc5,
    0x80,

    /* U+004C "L" */
    0xe3, 0x8e, 0x38, 0xe3, 0xc, 0x3f, 0xff, 0xf0,

    /* U+004D "M" */
    0xe7, 0xe7, 0xef, 0xef, 0xef, 0xff, 0xfb, 0xdb,
    0xdb, 0xd3,

    /* U+004E "N" */
    0xe7, 0xcf, 0x9f, 0xbd, 0x7a, 0xf7, 0xef, 0xcf,
    0x9c,

    /* U+004F "O" */
    0xff, 0xff, 0x1e, 0x3c, 0x78, 0xff, 0xff,

    /* U+0050 "P" */
    0xff, 0xfc, 0xf3, 0xff, 0xfc, 0x30, 0xc3, 0x0,

    /* U+0051 "Q" */
    0xfe, 0xfe, 0xc6, 0xc6, 0xc6, 0xfe, 0xfe, 0x1d,
    0xf, 0xf,

    /* U+0052 "R" */
    0xfd, 0xfb, 0x37, 0xef, 0xde, 0x3e, 0x6e, 0xcd,
    0x80,

    /* U+0053 "S" */
    0xff, 0xfc, 0x38, 0xff, 0xf0, 0xfb, 0xff, 0xf0,

    /* U+0054 "T" */
    0xff, 0xfc, 0xc1, 0x83, 0x6, 0xc, 0x18, 0x30,
    0x60,

    /* U+0055 "U" */
    0xe7, 0xcf, 0x9f, 0x3e, 0x7c, 0xf9, 0xbf, 0x7e,

    /* U+0056 "V" */
    0xe3, 0xb1, 0x98, 0xce, 0x63, 0x61, 0xb0, 0xd8,
    0x38, 0x1c, 0x0,

    /* U+0057 "W" */
    0xcb, 0xdb, 0xdb, 0xdf, 0xff, 0xf7, 0xf7, 0xf7,
    0xe7, 0xe7,

    /* U+0058 "X" */
    0xcf, 0x37, 0x9e, 0x31, 0xef, 0xf3, 0x4,

    /* U+0059 "Y" */
    0xe7, 0x66, 0x7c, 0x3c, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18,

    /* U+005A "Z" */
    0xc3, 0xff, 0xc6, 0x38, 0xc6, 0x39, 0xff, 0xf0,

    /* U+005B "[" */
    0xff, 0xcc, 0xcc, 0xcc, 0xcf, 0xf0,

    /* U+005C "\\" */
    0xe1, 0x86, 0xc, 0x30, 0xc1, 0x86, 0x8, 0x30,
    0xc0,

    /* U+005D "]" */
    0xff, 0x33, 0x33, 0x33, 0x3f, 0xf0,

    /* U+005E "^" */
    0x10, 0x30, 0xb3, 0x66, 0x60,

    /* U+005F "_" */
    0x7d, 0xf0,

    /* U+0060 "`" */
    0x6, 0x62,

    /* U+0061 "a" */
    0xfd, 0xf0, 0xff, 0xff, 0x3f, 0xff,

    /* U+0062 "b" */
    0xc3, 0xc, 0x30, 0xff, 0xfc, 0xf3, 0xff, 0xf0,

    /* U+0063 "c" */
    0x3f, 0xff, 0xf0, 0xc3, 0x1f, 0xff,

    /* U+0064 "d" */
    0x6, 0xc, 0x18, 0x3f, 0xff, 0xf9, 0xf3, 0xff,
    0xfc,

    /* U+0065 "e" */
    0xff, 0xff, 0xff, 0xc3, 0xff, 0xc0,

    /* U+0066 "f" */
    0x3f, 0xff, 0x8f, 0xff, 0x18, 0xc6, 0x0,

    /* U+0067 "g" */
    0xff, 0xfc, 0xff, 0xfc, 0x30, 0xff, 0xfc,

    /* U+0068 "h" */
    0xc3, 0xc, 0x3f, 0xff, 0x3c, 0xf3, 0xcf, 0x30,

    /* U+0069 "i" */
    0xf0, 0xff, 0xf0,

    /* U+006A "j" */
    0x33, 0x3, 0x33, 0x33, 0x33, 0xf7,

    /* U+006B "k" */
    0xc3, 0x6d, 0xfe, 0xe3, 0x8f, 0xf7, 0xcb, 0x0,

    /* U+006C "l" */
    0xff, 0xff, 0xc0,

    /* U+006D "m" */
    0x80, 0xff, 0xff, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb,

    /* U+006E "n" */
    0xc3, 0xff, 0xf3, 0xcf, 0x3c, 0xc0,

    /* U+006F "o" */
    0xff, 0xfc, 0xf3, 0xcf, 0xff, 0xc0,

    /* U+0070 "p" */
    0xff, 0xfc, 0xf3, 0xff, 0xfc, 0x30, 0xc0,

    /* U+0071 "q" */
    0xff, 0xfc, 0xf3, 0xff, 0xf0, 0xc3, 0xc,

    /* U+0072 "r" */
    0xc6, 0xff, 0xfc, 0x63, 0x18,

    /* U+0073 "s" */
    0xff, 0xfc, 0x3f, 0xfc, 0x3f, 0xff,

    /* U+0074 "t" */
    0x30, 0xcf, 0xff, 0x30, 0xc3, 0xe, 0x38,

    /* U+0075 "u" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x3f, 0xff,

    /* U+0076 "v" */
    0xc6, 0xcd, 0x9b, 0x32, 0x47, 0x8f, 0xc,

    /* U+0077 "w" */
    0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xff, 0xff, 0x3,

    /* U+0078 "x" */
    0x4b, 0x3f, 0x9e, 0x71, 0xef, 0xb7, 0x0,

    /* U+0079 "y" */
    0x4f, 0xdd, 0xf1, 0xe1, 0x87, 0xc, 0x18, 0x20,

    /* U+007A "z" */
    0xff, 0xf9, 0xce, 0x73, 0x9f, 0xff,

    /* U+007B "{" */
    0x37, 0x66, 0x66, 0xc6, 0x66, 0x67, 0x10,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xc0,

    /* U+007D "}" */
    0xce, 0x66, 0x66, 0x36, 0x66, 0x6e, 0x80,

    /* U+007E "~" */
    0x72, 0xff, 0x78,

    /* U+6570 "数" */
    0x10, 0x6, 0xac, 0x1d, 0x7f, 0xfb, 0xf7, 0xda,
    0x7b, 0xf1, 0xf7, 0x9f, 0x9c, 0x6c, 0xe3, 0xff,
    0xbb, 0x6c, 0x3, 0x40,

    /* U+6B65 "步" */
    0x6, 0x6, 0xf8, 0xdf, 0x1b, 0xe3, 0x61, 0xff,
    0xff, 0xf9, 0xb0, 0x66, 0xec, 0xf8, 0xfc, 0x3e,
    0x7, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 64, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 80, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 93, .box_w = 5, .box_h = 3, .ofs_x = 0, .ofs_y = 9},
    {.bitmap_index = 6, .adv_w = 137, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 13, .adv_w = 140, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 22, .adv_w = 166, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 36, .adv_w = 164, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 48, .adv_w = 59, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 49, .adv_w = 78, .box_w = 4, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 55, .adv_w = 80, .box_w = 4, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 61, .adv_w = 102, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 65, .adv_w = 134, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 73, .adv_w = 65, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 75, .adv_w = 87, .box_w = 4, .box_h = 3, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 77, .adv_w = 62, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 78, .adv_w = 99, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 87, .adv_w = 135, .box_w = 5, .box_h = 10, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 94, .adv_w = 135, .box_w = 2, .box_h = 10, .ofs_x = 3, .ofs_y = 1},
    {.bitmap_index = 97, .adv_w = 135, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 105, .adv_w = 135, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 113, .adv_w = 135, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 124, .adv_w = 135, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 132, .adv_w = 135, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 140, .adv_w = 135, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 148, .adv_w = 135, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 156, .adv_w = 135, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 164, .adv_w = 73, .box_w = 2, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 166, .adv_w = 78, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 170, .adv_w = 116, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 176, .adv_w = 148, .box_w = 7, .box_h = 5, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 181, .adv_w = 116, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 187, .adv_w = 102, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 194, .adv_w = 183, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 207, .adv_w = 147, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 219, .adv_w = 138, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 227, .adv_w = 138, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 235, .adv_w = 147, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 243, .adv_w = 132, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 251, .adv_w = 126, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 259, .adv_w = 141, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 267, .adv_w = 154, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 274, .adv_w = 110, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 282, .adv_w = 115, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 290, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 299, .adv_w = 118, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 307, .adv_w = 170, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 317, .adv_w = 148, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 326, .adv_w = 149, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 333, .adv_w = 132, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 341, .adv_w = 148, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 351, .adv_w = 137, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 360, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 368, .adv_w = 116, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 377, .adv_w = 151, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 385, .adv_w = 143, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 396, .adv_w = 170, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 406, .adv_w = 128, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 413, .adv_w = 124, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 423, .adv_w = 130, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 431, .adv_w = 101, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 437, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 446, .adv_w = 101, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 452, .adv_w = 153, .box_w = 7, .box_h = 5, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 457, .adv_w = 130, .box_w = 6, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 459, .adv_w = 94, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 461, .adv_w = 122, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 467, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 475, .adv_w = 126, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 481, .adv_w = 130, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 490, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 496, .adv_w = 104, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 503, .adv_w = 121, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 510, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 518, .adv_w = 69, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 521, .adv_w = 75, .box_w = 4, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 527, .adv_w = 121, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 535, .adv_w = 69, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 538, .adv_w = 157, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 546, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 552, .adv_w = 123, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 558, .adv_w = 125, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 565, .adv_w = 126, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 572, .adv_w = 106, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 577, .adv_w = 116, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 583, .adv_w = 105, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 590, .adv_w = 133, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 596, .adv_w = 123, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 603, .adv_w = 155, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 611, .adv_w = 118, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 618, .adv_w = 114, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 626, .adv_w = 123, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 632, .adv_w = 96, .box_w = 4, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 639, .adv_w = 74, .box_w = 2, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 643, .adv_w = 96, .box_w = 4, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 650, .adv_w = 152, .box_w = 7, .box_h = 3, .ofs_x = 1, .ofs_y = 10},
    {.bitmap_index = 653, .adv_w = 256, .box_w = 13, .box_h = 12, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 673, .adv_w = 256, .box_w = 11, .box_h = 13, .ofs_x = 2, .ofs_y = -1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0x5f5
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 25968, .range_length = 1526, .glyph_id_start = 96,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 2, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
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
    0, 0
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
    0, 0
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    -26, -20, -23, -27, -24, -49, -53, -30,
    -62, -22, -25, -20, -21, -29, -31, -41,
    -46, -20, 0, -8, -10, -11, -21, -25,
    -16, -31, -11, -8, 0, 0, -16, -25,
    -20, -27, -25, 0, -9, -11, -14, -24,
    -27, -18, -38, -13, -11, -9, -9, -17,
    -33, -20, -26, -40, -11, -16, -12, -16,
    -18, -22, -22, -26, -20, -11, -16, -15,
    -22, -36, -22, -28, -30, 0, -11, -9,
    -13, -19, -22, -18, -28, -16, -9, -11,
    -11, -19, -33, -19, -26, -47, -15, -23,
    -17, -17, -16, -22, -25, -23, -28, -16,
    -26, -20, -30, -40, -26, -38, -27, -11,
    -14, -14, -16, -25, -29, -19, -38, -16,
    -14, -14, -13, -22, -35, -26, -35, -19,
    -13, -13, -19, -17, -46, -51, -20, -58,
    -14, -19, -12, -12, -22, -26, -40, -44,
    -29, -14, -18, -17, -15, -24, -28, -22,
    -33, -20, -16, -19, -17, -28, -38, -30,
    -42, -62, -26, -38, -28, -26, -25, -28,
    -33, -28, -44, -26, -42, -32, -46, -47,
    -39, -52, -20, -11, -14, -14, -11, -24,
    -29, -17, -33, -15, -12, -13, -12, -22,
    -27, -26, -35, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -14, -14, -10, -11,
    -19, -28, -24, -30, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -15, -14, -10,
    -12, -20, -30, -27, -29, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -14, -13,
    -12, -13, -19, -28, -22, -27, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -13,
    0, -9, -8, -16, -26, -19, -26, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -26, -15, -17, -19, -24, -40, -25, -27,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -21, -18, -18, -18, -27, -41, -27,
    -38, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -16, -13, -11, -13, -19, -38,
    -20, -26, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -24, -16, -16, -18, -22,
    -41, -22, -25, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -30, -22, -24, -24,
    -29, -48, -27, -31
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
const lv_font_t ui_font_Font2 = {
#else
lv_font_t ui_font_Font2 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 14,          /*The maximum line height required by the font*/
    .base_line = 1,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UI_FONT_FONT2*/

