//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : IGV4 Game Framework
// File        : IGV4GameDef.h
// Description : ¹CÀ¸¥D¬[ºc
// Author      : Ray
// Create      : 2011-05-30
// Update      : 2011-12-22
//==============================================================================

#ifndef __M3D_GAME_DEF_H__
#define __M3D_GAME_DEF_H__

#include "IGV5RuntimeContext.h"
#include "IGV5Game.h"

#define M3D_DEFAULT_NAME_LENGTH	16

#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
#define M3D_DEBUG_FRAME			10
#endif

#define M3D_ENABLE_SHADOW		1
//#define M3D_SHOW_MEMORY			1
#define IGLW_2D_DELAY_TIME		1000.0f

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {

	long m_Width;
	long m_Height;
	void *m_Handle;
	unsigned char *m_pFrameBuffer;
	unsigned char *m_pMemBuffer;
	long m_MemSize;
	int m_ColorFormat;
	int m_IsTopDown;

} M3DConfig;

typedef struct {

	unsigned long m_uEventID;
	unsigned long m_uTime;
	unsigned long m_uData1;
	unsigned long m_uData2;

} M3DEvent;

#ifdef __cplusplus
}
#endif


#endif //__GAME_APP_H__
