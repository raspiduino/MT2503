//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved. 
// Project     : IGV3Retained
// File        : V3UI.c
// Description : V3 UI
// Author      : Ray
// Create      : 2011-01-26
// Update      : 2011-02-15
//==============================================================================

#include "V3UI.h"

#include "IGComDef.h" 
#include "IGMemoryPool.h"
#include "IGMathUtil.h"

#include "IGBackground.h"
#include "IGScene.h"
#include "IGRenderer.h"
#include "IGNode.h"
#include "IGGroup.h"
#include "IGCamera.h"
#include "IGTexture.h"
#include "IGObjCache.h"
#include "IGSprite.h"

#include "CNodeStatus.h"
#include "CMemory.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

	struct _V3UI	V3UI = {
	//這是貼圖檔名, 用這個檔名來存取共用貼圖, 需要的時後貼圖才會載入
	{ "return.png", "icon_number.png", "common_back.png" },
	{ png_WPLib_ui_return, png_WPLib_ui_number, png_WPLib_ui_back },
	{ 0x00FF00, 0x00FF00, 0x00FF00 },
	{ 0, 0, 0 }
};

void V3UI_SetTargetColor(unsigned char *_pFrameBuffer, igcolor _color)
{
	long cn;
	V3Retained *rr = V3Retained_GetInstance();
	long count = rr->PC.m_uScrHeight * rr->PC.m_uScrWidth;
	igcolor *pFrameBuffer = (igcolor *) _pFrameBuffer;

	for (cn = 0; cn < count; cn = cn + 1)
	{
		pFrameBuffer[cn] = _color;
	}
}

void V3UI_LoadSmallDigit(void)
{
	//RAY::2011-01-25 icon_number.png 是一張 160x32 png 數字圖片
	V3TextureCollection_Add("icon_number.png", png_WPLib_ui_number, 0x00FF00);
}

void V3UI_LoadUI(const char *_name)
{
	int cn;

	for (cn = 0; cn < V3_UI_COUNT; cn = cn + 1)
	{
		if (CStrCmp(_name, V3UI.m_bmp_name[cn]) == 0)
		{
			V3TextureCollection_Add(_name, V3UI.m_bmp_array[cn], V3UI.m_keycolor[cn]);
			break;
		}
	}
}

void V3UI_DrawSpriteCenter(const char *_name)
{
	IGErr err;
	IGPoint pt;
	IGRect rect;
	IGTexture *pTexture = V3TextureCollection_Get(_name);
	V3Retained *rr = V3Retained_GetInstance();

	if (pTexture == NULL)
	{
		V3UI_LoadUI(_name);
		pTexture = V3TextureCollection_Get(_name);
	}

	if (pTexture == NULL)
		return;

	pt.x = (rr->PC.m_uScrWidth - pTexture->m_width) / 2;
	pt.y = (rr->PC.m_uScrHeight - pTexture->m_height) / 2;
	IGSetRect( &rect, 0, 0, pTexture->m_width-1, pTexture->m_height-1 );
	IGSprite_drawTrans(rr->m_Mem, rr->m_Renderer, &pt, pTexture, &rect, (igreal) (IG_ONE * 0.5f), &err);
}

//如果不指定 src 位置, 四個參數都給 -1
void V3UI_DrawSprite(const char *_name, int _corner, int _x, int _y, int _src_x, int _src_y, int _src_width, int _src_height, float _alpha)
{
	IGErr err;
	IGPoint pt;
	IGRect rect;
	IGTexture *pTexture = V3TextureCollection_Get(_name);
	V3Retained *rr = V3Retained_GetInstance();

	if (pTexture == NULL)
	{
		V3UI_LoadUI(_name);
		pTexture = V3TextureCollection_Get(_name);
	}

	if (pTexture == NULL)
		return;

	//設定 pt
	pt.x = _x;
	pt.y = _y;
	switch (_corner)
	{
	case V3UI_CORNER_RIGHT_TOP :
		pt.x = rr->PC.m_uScrWidth - _x;
		break;
	case V3UI_CORNER_RIGHT_BOTTOM :
		pt.x = rr->PC.m_uScrWidth - _x;
		pt.y = rr->PC.m_uScrHeight - _y;
		break;
	case V3UI_CORNER_LEFT_BOTTOM :
		pt.y = rr->PC.m_uScrHeight - _y;
		break;
	}

	//設定 rect
	if (_src_x == -1 || _src_y == -1)
	{
		IGSetRect( &rect, 0, 0, pTexture->m_width-1, pTexture->m_height-1 );
	}
	else
	{
		IGSetRect( &rect, _src_x, _src_y, _src_width, _src_height );
	}

	IGSprite_drawTrans(rr->m_Mem, rr->m_Renderer, &pt, pTexture, &rect, (igreal) (IG_ONE * _alpha), &err);
}

void V3UI_DrawImage2DCenter(IGTexture *_pTexture, float _alpha)
{
	IGErr err;
	IGPoint pt;
	IGRect rect;
	V3Retained *rr = V3Retained_GetInstance();

	if (_pTexture == NULL)
		return;

	pt.x = (rr->PC.m_uScrWidth - _pTexture->m_width) / 2;
	pt.y = (rr->PC.m_uScrHeight - _pTexture->m_height) / 2;
    IGSetRect( &rect, 0, 0, _pTexture->m_width, _pTexture->m_height);
	IGSprite_drawTrans(rr->m_Mem, rr->m_Renderer, &pt, _pTexture, &rect, (igreal) (IG_ONE * _alpha), &err);
}

//CY: assume pTexture has same size as background, use at your own risk.... :-)
void V3UI_FastDrawBackground(IGTexture *_pTexture)
{
	size_t bufsize, i;
	V3Retained *rr = V3Retained_GetInstance();

	if (_pTexture == NULL)
		return;

	bufsize = (_pTexture->m_width * _pTexture->m_height) * sizeof(igcolor);

	if (rr->m_Renderer->m_buffs.m_invertY) {
		for(i=0;i<_pTexture->m_height;i++) {
			memcpy(rr->m_Renderer->m_buffs.m_framebuffer+_pTexture->m_width*i, 
				_pTexture->m_texels+_pTexture->m_width*(_pTexture->m_height-i-1), 
				_pTexture->m_width*sizeof(igcolor));
		}		
	} else {
		memcpy(rr->m_Renderer->m_buffs.m_framebuffer, _pTexture->m_texels, bufsize);
	}
}

void V3UI_DrawImage2D(int _x, int _y, IGTexture *_pTexture, float _alpha)
{
	IGErr err;
	IGPoint pt;
	IGRect rect;
	V3Retained *rr = V3Retained_GetInstance();

	if (_pTexture == NULL)
		return;

	pt.x = _x;
	pt.y = _y;
	IGSetRect( &rect, 0, 0, _pTexture->m_width-1, _pTexture->m_height-1 );
	IGSprite_drawTrans(rr->m_Mem, rr->m_Renderer, &pt, _pTexture, &rect, (igreal) (IG_ONE * _alpha), &err);
}

void V3UI_DrawImage2D_Corner(int _corner, int _x, int _y, IGTexture *_pTexture, float _alpha)
{
	IGErr err;
	IGPoint pt;
	IGRect rect;
	V3Retained *rr = V3Retained_GetInstance();

	if (_pTexture == NULL)
		return;

	pt.x = _x;
	pt.y = _y;
	switch (_corner)
	{
	case V3UI_CORNER_RIGHT_TOP :
		pt.x = rr->PC.m_uScrWidth - _x;
		break;
	case V3UI_CORNER_RIGHT_BOTTOM :
		pt.x = rr->PC.m_uScrWidth - _x;
		pt.y = rr->PC.m_uScrHeight - _y;
		break;
	case V3UI_CORNER_LEFT_BOTTOM :
		pt.y = rr->PC.m_uScrHeight - _y;
		break;
	}

	IGSetRect( &rect, 0, 0, _pTexture->m_width-1, _pTexture->m_height-1 );
	IGSprite_drawTrans(rr->m_Mem, rr->m_Renderer, &pt, _pTexture, &rect, (igreal) (IG_ONE * _alpha), &err);
}

//RAY::2011-01-25
//用 icon_number.png 顯示一個數字, 必須先呼叫 V3TextureCollection_Init(), V3TextureCollection_AddSmallDigit()
void V3UI_DrawDigit(int _x, int _y, int _digit, float _alpha)
{
	IGErr err;
	IGPoint pt;
	IGRect rect;
	IGTexture *tex = V3TextureCollection_Get("icon_number.png");

	//RAY::2011-01-26 第一次顯示數字的時後要載入圖片
	if (tex == NULL)
	{
		V3UI_LoadSmallDigit();
		tex = V3TextureCollection_Get("icon_number.png");
	}

	if (tex != NULL)
	{
		pt.x = _x;
		pt.y = _y;
		IGSetRect( &rect, _digit * 16, 0, _digit * 16+15, tex->m_height-1 );
		IGSprite_drawTrans(V3Retained_GetMem(), V3Retained_GetRenderer(), &pt, tex, &rect, (igreal) (IG_ONE * _alpha), &err);
	}
}

static int CalcNumberLength(int _number)
{
	int iLength = 0, number = _number;

	while (number > 0)
	{
		iLength = iLength + 1;
		number = number / 10;
	}
	return iLength;
}

void V3UI_DrawNumber(int _x, int _y, int _number, float _alpha)
{
	int number = _number, number0 = _number, iDigit;
	int iLength = CalcNumberLength(_number);

	while (iLength > 0)
	{
		number = number0;
		number0 = number0 / 10;
		iDigit = number - number0*10;
		V3UI_DrawDigit(_x+16*iLength, _y, iDigit, _alpha);
		iLength = iLength - 1;
	}
}

void V3UI_DrawNumber0(int _x, int _y, int _length, int _number, float _alpha)
{
	int cn, number = _number, number0 = _number, iDigit;
	int iLength = CalcNumberLength(_number);

	if (_length < iLength)
		return;

	for (cn = _length; cn > 0; cn = cn - 1)
	{
		number = number0;
		number0 = number0 / 10;
		iDigit = number - number0*10;
		V3UI_DrawDigit(_x+16*(cn-1), _y, iDigit, _alpha);
	}
}

void V3UI_DrawNumber0_Corner(int _corner, int _x, int _y, int _length, int _number, float _alpha)
{
	int cn, number = _number, number0 = _number, iDigit;
	int iLength = CalcNumberLength(_number);
	int x, y;
	V3Retained *rr = V3Retained_GetInstance();

	if (_length < iLength)
		return;

	for (cn = _length; cn > 0; cn = cn - 1)
	{
		number = number0;
		number0 = number0 / 10;
		iDigit = number - number0*10;
		x = _x+16*(cn-1);
		y = _y;
		switch (_corner)
		{
		case V3UI_CORNER_RIGHT_TOP :
			x = rr->PC.m_uScrWidth - _x+16*(cn-1);
			break;
		case V3UI_CORNER_RIGHT_BOTTOM :
			x = rr->PC.m_uScrWidth - _x+16*(cn-1);
			y = rr->PC.m_uScrHeight - _y;
			break;
		case V3UI_CORNER_LEFT_BOTTOM :
			y = rr->PC.m_uScrHeight - _y;
			break;
		}
		V3UI_DrawDigit(x, y, iDigit, _alpha);
	}
}

void V3UI_DrawDigit_Corner(int _corner, int _x, int _y, int _digit, float _alpha)
{
	int x = _x, y = _y;
	V3Retained *rr = V3Retained_GetInstance();

	switch (_corner)
	{
	case V3UI_CORNER_RIGHT_TOP :
		x = rr->PC.m_uScrWidth - _x;
		break;
	case V3UI_CORNER_RIGHT_BOTTOM :
		x = rr->PC.m_uScrWidth - _x;
		y = rr->PC.m_uScrHeight - _y;
		break;
	case V3UI_CORNER_LEFT_BOTTOM :
		y = rr->PC.m_uScrHeight - _y;
		break;
	}
	V3UI_DrawDigit(x, y, _digit, _alpha);
}

#ifdef __cplusplus
}
#endif // __cplusplus
