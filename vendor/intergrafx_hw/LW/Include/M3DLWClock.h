//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWClock
// File        : M3DLWClock.h
// Description : IGV5 Mali ´ú¸Õ±M®×
// Author      : Ray
// Create      : 2011-06-20
// Update      : 2011-12-23
//==============================================================================

#ifndef __M3D_LW_CLOCK_H__
#define __M3D_LW_CLOCK_H__

#include "IGV5RuntimeContext.h"
#include "IGV5Font.h"
#include "IGV5Camera.h"
#include "M3D_Adaption.h"
#include "M3DRenderer.h"
#include "M3DModel.h"
#include "M3DPhysics.h"

#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
#include "win32_runtime.h"
#else
#include "6256_runtime.h"
#endif

#define IGLW_CLOCK_DELAY_TIME	2000

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _M3DLWClock
{
	float	m_GameTime;
	float	m_ElapsedTime;
	float	m_TimeFactor;

	M3D_Adaption	m_adaption;
	M3DRenderer		m_Renderer;
	M3DArrayPool	*m_EventMemPool;
	M3DQueue		*m_Event;

	M3DModel		*m_Scene;
	M3DModel		*m_Face;
	M3DModel		*m_Gear;
	M3DModel		*m_Gear2;
	M3DModel		*m_Hand;
	M3DSplitString	*m_SceneTextureNames;
	M3DSplitString	*m_FaceTextureNames;
	M3DSplitString	*m_GearTextureNames;
	M3DSplitString	*m_Gear2TextureNames;
	M3DSplitString	*m_HandTextureNames;

	M3DRotateCenter	m_RotateCamera;
	M3DLWPage		m_Page;
} M3DLWClockApp;

extern M3DLWClockApp M3DLWClock;

extern int  M3DLWClock_OnStartup(void *_pc);
extern void M3DLWClock_OnShutdown(void);
extern void M3DLWClock_OnResume(void);

extern void M3DLWClock_PostEvent(unsigned long _Id, unsigned long _Time, unsigned long _Data1, unsigned long _Data2);

extern void M3DLWClock_OnUpdate(int suspend);

extern void M3DLWClock_LoadBackground2D(void);
extern void M3DLWClock_RemoveBackground2D(void);

extern int  M3DLWClock_Init(void);
extern int  M3DLWClock_Init2(void);
extern void M3DLWClock_Release(void);
extern void M3DLWClock_MoveHand(void);
extern int  M3DLWClock_LoadContent(void);
extern void M3DLWClock_LoadContent2(void);
extern void M3DLWClock_Update(void);
extern void M3DLWClock_ProcessTouch(int _mouseX, int _mouseY);

#ifdef __cplusplus
}
#endif

#endif /* __IGV5_PLAYER_H__ */


