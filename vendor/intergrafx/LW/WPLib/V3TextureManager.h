//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : IGV3Retained
// File        : V3TextureManager.h
// Description : V3 Texture Manager : V3 引擎貼圖管理
// Author      : Ray
// Create      : 2011-01-26
// Update      : 2011-02-15
//==============================================================================

#ifndef __V3_TEXTURE_MANAGER_H__
#define __V3_TEXTURE_MANAGER_H__

#include "CUtils.h"
#include "IGTexture.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

//========== 使用方式 =========================================================================================================
// (1) 在 V3Retained_InitEngine 裡面會呼叫 V3TextureCollection_Init(), V3Retained_End 裡面會呼叫 V3TextureCollection_Release()
//     所以程式不需要起始或釋放貼圖
// (2) 一律用貼圖名稱 (檔名) 來存取貼圖, 名稱不要重複, 不過系統並不會檢查重複名稱
// (3) V3UI 那邊會放入一些共用貼圖, 名稱請參考 V3UI
// (4) 自行新增貼圖請用 V3TextureCollection_Add
// (5) 取得貼圖請用 V3TextureCollection_Get
//=============================================================================================================================

struct _V3TextureCollection
{
	CArray	*m_Textures;
};

extern struct _V3TextureCollection V3TextureCollection;

extern void V3TextureCollection_Init(void);
extern void V3TextureCollection_Add(const char *_name, unsigned char *_buf, int _keycolor);
extern void V3TextureCollection_Release(void);
extern IGTexture *V3TextureCollection_Get(const char *_name);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif