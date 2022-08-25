//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : WP1-A-Jason
// File        : GameDef.h
// Description : ¹CÀ¸¥D¬[ºc
// Author      : Ray
// Create      : 2010-10-20
// Update      : 2011-02-15
//==============================================================================

#ifndef __GAME_DEF_H__
#define __GAME_DEF_H__

#include "IGExtDef.h"

#define IGGAME_RESET			0x000000FF

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {

	IGU32 m_uScrWidth;
	IGU32 m_uScrHeight;
	IGU8 *m_pFrameBuffer;
	IGU8 *m_pMemBuffer;
	int m_MemSize;
	int m_MaskR, m_MaskG, m_MaskB;
	int m_IsTopDown;

} IGV3Config;


#ifdef __cplusplus
}
#endif


#endif //__GAME_APP_H__
