//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWPuppy
// File        : M3DLWPuppy.h
// Description : IGV5 LW Puppy
// Author      : Ray
// Create      : 2011-08-23
// Update      : 2011-12-23
//==============================================================================

#ifndef __M3D_LW_PUPPY_H__
#define __M3D_LW_PUPPY_H__

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

#define IGLW_PUPPY_DELAY_TIME	2000

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _M3DLWPuppy
{
	float	m_GameTime;
	float	m_ElapsedTime;
	float	m_TimeFactor;

	M3D_Adaption	m_adaption;
	M3DRenderer		m_Renderer;
	M3DArrayPool	*m_EventMemPool;
	M3DQueue		*m_Event;

	M3DModel		*m_Scene;
	M3DModel		*m_Cloud;
	M3DModel		*m_Window;
	M3DModel		*m_Dog;
	M3DSplitString	*m_SceneTextureNames;
	M3DSplitString	*m_CloudTextureNames;
	M3DSplitString	*m_WindowTextureNames;
	M3DSplitString	*m_DogTextureNames;

	float			m_IdleStartTime;

	M3DRotateCenter	m_RotateCamera;
	M3DLWPage		m_Page;
} M3DLWPuppyApp;

extern M3DLWPuppyApp M3DLWPuppy;

extern int  M3DLWPuppy_OnStartup(void *_pc);
extern void M3DLWPuppy_OnShutdown(void);
extern void M3DLWPuppy_OnResume(void);

extern void M3DLWPuppy_PostEvent(unsigned long _Id, unsigned long _Time, unsigned long _Data1, unsigned long _Data2);

extern void M3DLWPuppy_OnUpdate(int suspend);

extern void M3DLWPuppy_LoadBackground2D(void);
extern void M3DLWPuppy_RemoveBackground2D(void);

extern int  M3DLWPuppy_Init(void);
extern int  M3DLWPuppy_Init2(void);
extern void M3DLWPuppy_Release(void);
extern void M3DLWPuppy_Update(void);
extern int  M3DLWPuppy_LoadContent(void);
extern void M3DLWPuppy_LoadContent2(void);
extern void M3DLWPuppy_ProcessTouch(int _mouseX, int _mouseY);

#ifdef __cplusplus
}
#endif

#endif /* __IGV5_PLAYER_H__ */


