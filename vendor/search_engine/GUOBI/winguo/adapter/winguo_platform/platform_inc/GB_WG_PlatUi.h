
#ifndef GB_WG_UI_DEFINE_FOR_PLATFORM_KNIGHTNIU_2010_05_24_H
#define GB_WG_UI_DEFINE_FOR_PLATFORM_KNIGHTNIU_2010_05_24_H

#include "GB_DataTypeDef.h"

enum{
	g_GB_WG_IMG_TYPE_ERR = 0,
	g_GB_WG_IMG_TYPE_BMP,
	g_GB_WG_IMG_TYPE_PNG,
	g_GB_WG_IMG_TYPE_GIF,
	g_GB_WG_IMG_TYPE_JPG
};

////////////////////////

GB_INT GB_WG_UI_MeasureImgSize(GB_BYTE * pData,GB_INT nSize,GB_INT*pWidth,GB_INT* pHeight,GB_WG_GDIHANDLE *pHandle);
GB_INT GB_WG_UI_DrawImg(GB_BYTE * pData,GB_INT nSize,
	GB_INT offsetX,GB_INT offsetY,GB_INT dispW,GB_INT dispH,
	GB_INT width,GB_INT height,
	GB_INT xPos,GB_INT yPos,GB_Rect *pClipRect,GB_WG_GDIHANDLE *pHandle,GB_BOOL bClip);

/////////////////////////
GB_VOID GB_WG_Fill_Rect_Gradual(GB_INT x1, GB_INT y1, GB_INT x2, GB_INT y2, GB_COLOR color1,GB_COLOR color2);
////////////////////////////////////////////////////
	
GB_VOID GB_WG_Draw_Line(GB_INT startX,GB_INT startY,GB_INT endX,GB_INT endY,GB_COLOR color);

//add by bryantwu 2008-09-18
GB_VOID GB_WG_Draw_RoundRect(GB_INT x,GB_INT y,GB_INT width,GB_INT height,GB_COLOR color);

GB_VOID GB_WG_Fill_Triangle(GB_INT x1,GB_INT y1,GB_INT x2,GB_INT y2,
	GB_INT x3,GB_INT y3,GB_COLOR color);

typedef enum
{
	GB_DIRECT_UP = 0,
	GB_DIRECT_DOWN,
	GB_DIRECT_LEFT,
	GB_DIRECT_RIGHT
}GB_WG_Direct;

GB_VOID GB_WG_Draw_Delta(GB_INT x,GB_INT y,GB_INT h,GB_COLOR fillColor,GB_INT flag);
GB_BOOL GB_WG_UI_Measure_GetDefault(GB_INT* pWidth,GB_INT *pHeight);
GB_BOOL GB_WG_UI_Measure_GetDefaultSmallFont(GB_INT* pWidth,GB_INT *pHeight);
GB_INT GB_WG_GetImgWH(GB_BYTE * pData,GB_INT nSize,GB_INT* pWidth,GB_INT* pHeight);


extern GB_VOID gb_wg_gui_push_clip(GB_VOID);
extern GB_VOID gb_wg_gui_pop_clip(GB_VOID);
#define GB_WG_PUSH_CLIP						gb_wg_gui_push_clip()
#define GB_WG_POP_CLIP						gb_wg_gui_pop_clip()

extern GB_VOID gb_wg_gui_lock_double_buffer();

extern GB_VOID gb_wg_gui_unlock_double_buffer();

extern GB_VOID gb_wg_gui_BLT_double_buffer(GB_INT x1,GB_INT y1,GB_INT x2,GB_INT y2);

extern GB_VOID gb_wg_gui_get_clip(GB_INT *x1,GB_INT *y1,GB_INT*x2,GB_INT*y2);

extern GB_VOID gb_wg_gui_set_font(GB_WG_FONT text_font);

extern GB_VOID gb_wg_gui_set_text_color(GB_COLOR color);

extern GB_INT gb_wg_gui_get_string_width(GB_STRTYPE str, GB_WG_FONT text_font);

GB_INT gb_wg_gui_get_string_height(GB_STRTYPE text, GB_WG_FONT text_font);

extern GB_VOID gb_wg_gui_measure_character(GB_CHARTYPE character,GB_INT *width,GB_INT*height, GB_WG_FONT text_font);

extern GB_INT gb_wg_gui_get_baseline_height(GB_WCHAR *pstr);

extern GB_INT gb_wg_gui_get_char_defult_Height(GB_VOID);

//extern GB_INT gb_wg_gui_get_char_width(GB_CHARTYPE c);

extern GB_VOID gb_wg_gui_measure_string(GB_STRTYPE str,GB_INT *width,GB_INT *height, GB_WG_FONT text_font);

extern GB_VOID gb_wg_gui_measure_string_n(GB_STRTYPE str,GB_UINT num,GB_INT *width,GB_INT *height, GB_WG_FONT text_font);

//extern GB_VOID gb_wg_gui_move_text_cursor(GB_UINT x,GB_UINT y);

//extern GB_VOID gb_wg_gui_print_text(GB_STRTYPE str);

//extern GB_VOID gb_wg_gui_draw_line(GB_UINT x1,GB_UINT y1,GB_UINT x2,GB_UINT y2,GB_COLOR color);

extern GB_VOID gb_wg_gui_draw_rectangle(GB_UINT x1,GB_UINT y1,GB_UINT x2,GB_UINT y2,GB_COLOR color);

extern GB_VOID gb_wg_gui_fill_rectangle(GB_UINT x1,GB_UINT y1,GB_UINT x2,GB_UINT y2,GB_COLOR color);

extern GB_VOID gb_wg_ShowString_n(GB_UINT x,GB_UINT y,GB_WG_FONT font,GB_STRTYPE str,GB_INT len,GB_INT height);

extern GB_VOID gb_wg_ShowString(GB_UINT x,GB_UINT y,GB_WG_FONT font,GB_STRTYPE str,GB_INT height);

extern GB_VOID gb_wg_ShowString_n_baseline(GB_UINT x,GB_UINT y,GB_WG_FONT font,GB_STRTYPE str,GB_INT len,GB_INT baseline);

extern GB_VOID gb_wg_gdi_image_get_dimension(GB_U8 *img_src,GB_INT *width,GB_INT *height);

extern GB_VOID gb_wg_gdi_image_get_dimension_id(GB_INT img_id,GB_INT*width,GB_INT *height);

extern GB_VOID gb_wg_gdi_draw_round_rect(GB_INT x1, GB_INT y1, GB_INT x2, GB_INT y2, GB_COLOR rect_color, GB_COLOR frame_color, GB_INT frame_width);

//extern GB_VOID gb_wg_gdi_draw_solid_rect(GB_INT x1, GB_INT y1, GB_INT x2, GB_INT y2, GB_COLOR rect_color);

//extern GB_VOID gb_wg_gdi_layer_push_clip();

//extern GB_VOID gb_wg_gdi_layer_set_clip(GB_INT x1,GB_INT y1,GB_INT x2,GB_INT y2);

//extern GB_VOID gb_wg_gdi_layer_pop_clip();

extern GB_VOID gb_wg_gdi_draw_rect(GB_INT x1, GB_INT y1, GB_INT x2, GB_INT y2, GB_COLOR rect_color);

extern GB_PU8 gb_wg_get_image(GB_INT img_id);

extern GB_VOID gb_wg_gui_show_image(GB_INT x,GB_INT y,GB_PU8 img_src);

extern GB_VOID gb_wg_gui_measure_image(GB_PU8 img_str,GB_INT*width,GB_INT*heigth);

extern GB_VOID gb_wg_gui_set_clip(GB_INT x1, GB_INT y1, GB_INT x2, GB_INT y2);

extern GB_STRTYPE gb_wg_get_string(GB_INT str_id);

//extern GB_USHORT gb_wg_get_screenID(GB_USHORT screenID);

extern GB_VOID gb_wg_print_text(GB_INT x, GB_INT y,GB_U16* str_ptr);

extern GB_VOID gb_wg_print_Char(GB_INT x, GB_INT y, GB_U16 str_ptr);

extern GB_UINT gb_wg_get_bottombar_hight(GB_VOID);
#endif 
