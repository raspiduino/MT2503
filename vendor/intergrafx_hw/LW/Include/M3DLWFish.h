//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWFish
// File        : M3DLWFish.h
// Description : IGV5 LW Fish
// Author      : Ray
// Create      : 2011-08-24
// Update      : 2011-12-23
//==============================================================================

#ifndef __M3D_LW_FISH_H__
#define __M3D_LW_FISH_H__

#include "IGV5RuntimeContext.h"
#include "IGV5Font.h"
#include "IGV5Camera.h"
#include "M3D_Adaption.h"
#include "M3DRenderer.h"
#include "M3DModel.h"
#include "M3DPhysics.h"
#include "M3DDummyGroup.h"

#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
#include "win32_runtime.h"
#else
#include "6256_runtime.h"
#endif

#define IGLW_FISH_DELAY_TIME	1000

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _M3DLWFish
{
	float	m_GameTime;
	float	m_ElapsedTime;
	float	m_TimeFactor;
	float	m_GameTime_DelayLoad;

	M3D_Adaption	m_adaption;
	M3DRenderer		m_Renderer;
	M3DArrayPool	*m_EventMemPool;
	M3DQueue		*m_Event;

	M3DModel		*m_Scene;
	M3DModel		*m_Coral;
	M3DModel		*m_Fish1;
	M3DModel		*m_Fish2;
	M3DModel		*m_Bubble;
	M3DModel		*m_Bubble_b;
	M3DModel		*m_Bubble_c;
	M3DModel		*m_BubbleTouch;
	M3DModel		*m_BubbleTouch_b;
	M3DModel		*m_BubbleTouch_c;
	M3DSplitString	*m_SceneTextureNames;
	M3DSplitString	*m_CoralTextureNames;
	M3DSplitString	*m_Fish1TextureNames;
	M3DSplitString	*m_Fish2TextureNames;
	M3DSplitString	*m_BubbleTextureNames;

	M3DDummyGroup	*m_BubbleDummy;
	M3DDummyGroup	*m_BubbleDummyTouch;

	M3DRotateCenter	m_RotateCamera;
	M3DRotateCenter	m_VerticalCamera;
	M3DLWPage		m_Page;
} M3DLWFishApp;

extern M3DLWFishApp M3DLWFish;

extern int  M3DLWFish_OnStartup(void *_pc);
extern void M3DLWFish_OnShutdown(void);
extern void M3DLWFish_OnResume(void);

extern void M3DLWFish_PostEvent(unsigned long _Id, unsigned long _Time, unsigned long _Data1, unsigned long _Data2);

extern void M3DLWFish_OnUpdate(int isSuspend);
extern void M3DLWFish_LoadBackground2D(void);
extern void M3DLWFish_RemoveBackground2D(void);

extern int  M3DLWFish_Init(void);
extern int  M3DLWFish_Init2(void);
extern int  M3DLWFish_LoadContent(void);
extern void M3DLWFish_LoadContent2(void);
extern void M3DLWFish_Release(void);
extern void M3DLWFish_Update(void);
extern void M3DLWFish_ProcessTouch(int _mouseX, int _mouseY);

#ifdef __cplusplus
}
#endif

#endif /* __IGV5_PLAYER_H__ */


