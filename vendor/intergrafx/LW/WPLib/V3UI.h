//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved. 
// Project     : IGV3Retained
// File        : V3UI.h
// Description : V3 UI
// Author      : Ray
// Create      : 2011-01-26
// Update      : 2011-02-15
//==============================================================================

#ifndef __V3_UI_H__
#define __V3_UI_H__

#include "V3Retained.h"
#include "V3TextureManager.h"

#define V3_UI_COUNT		3

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

extern unsigned char png_WPLib_ui_return[];
extern unsigned char png_WPLib_ui_number[];
extern unsigned char png_WPLib_ui_back[];

struct _V3UI
{
	char			*m_bmp_name[V3_UI_COUNT];
	unsigned char	*m_bmp_array[V3_UI_COUNT];
	int				m_keycolor[V3_UI_COUNT];
	IGTexture		*m_Textures[V3_UI_COUNT];
};


#define V3UI_CORNER_LEFT_TOP		0
#define V3UI_CORNER_RIGHT_TOP		1
#define V3UI_CORNER_RIGHT_BOTTOM	2
#define V3UI_CORNER_LEFT_BOTTOM		3
#define V3UI_CORNER_CENTER			4

extern void V3UI_SetTargetColor(unsigned char *_pFrameBuffer, igcolor _color);
extern void V3UI_LoadSmallDigit(void);
extern void V3UI_LoadUI(const char *_name);
extern void V3UI_DrawSpriteCenter(const char *_name);
extern void V3UI_DrawSprite(const char *_name, int _corner, int _x, int _y, int _src_x, int _src_y, int _src_width, int _src_height, float _alpha);

extern void V3UI_DrawImage2DCenter(IGTexture *_pTexture, float _alpha);
extern void V3UI_DrawImage2D(int _x, int _y, IGTexture *_pTexture, float _alpha);
extern void V3UI_DrawImage2D_Corner(int _corner, int _x, int _y, IGTexture *_pTexture, float _alpha);
extern void V3UI_DrawDigit(int _x, int _y, int _digit, float _alpha);
extern void V3UI_DrawDigit_Corner(int _corner, int _x, int _y, int _digit, float _alpha);
extern void V3UI_DrawNumber(int _x, int _y, int _number, float _alpha);
extern void V3UI_DrawNumber0(int _x, int _y, int _length, int _number, float _alpha);
extern void V3UI_DrawNumber0_Corner(int _corner, int _x, int _y, int _length, int _number, float _alpha);

//CY: fast version of draw background
extern void V3UI_FastDrawBackground(IGTexture *_pTexture);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif