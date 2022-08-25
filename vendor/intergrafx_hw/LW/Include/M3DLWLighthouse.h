//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWLighthouse
// File        : M3DLWLighthouse.h
// Description : IGV5 LW Lighthouse
// Author      : Ray
// Create      : 2011-08-12
// Update      : 2011-12-23
//==============================================================================

#ifndef __M3D_LW_LIGHTHOUSE_H__
#define __M3D_LW_LIGHTHOUSE_H__

#include "IGV5RuntimeContext.h"
#include "IGV5Font.h"
#include "IGV5Camera.h"
#include "M3D_Adaption.h"
#include "M3DRenderer.h"
#include "M3DModel.h"
#include "M3DDummyGroup.h"

#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
#include "win32_runtime.h"
#else
#include "6256_runtime.h"
#endif

#define IGLW_LIGHTHOUSE_DELAY_TIME	2000

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _M3DLWLighthouse
{
	float	m_GameTime;
	float	m_ElapsedTime;
	float	m_TimeFactor;

	M3D_Adaption	m_adaption;
	M3DRenderer		m_Renderer;
	M3DArrayPool	*m_EventMemPool;
	M3DQueue		*m_Event;

	M3DModel		*m_Scene;
	M3DModel		*m_Ray;
	M3DModel		*m_Birds;
	M3DModel		*m_Whale;
	M3DModel		*m_Ray2;

	M3DDummyGroup	*m_BirdsPath;
	M3DDummyGroup	*m_WhalePath;

	M3DSplitString	*m_SceneTextureNames;
	M3DSplitString	*m_RayTextureNames;
	M3DSplitString	*m_BirdsTextureNames;
	M3DSplitString	*m_WhaleTextureNames;
	M3DSplitString	*m_Ray2TextureNames;

	M3DRotateSimple m_RotateRay;
	M3DRotateCenter	m_RotateCamera;
	M3DRotateCenter	m_VerticalCamera;
	M3DLWPage		m_Page;
	CLinear			m_CameraEnterLookAt;
} M3DLWLighthouseApp;

extern M3DLWLighthouseApp M3DLWLighthouse;

extern int M3DLWLighthouse_OnStartup(void *_pc);
extern void M3DLWLighthouse_OnShutdown(void);
extern void M3DLWLighthouse_OnResume(void);

extern void M3DLWLighthouse_PostEvent(unsigned long _Id, unsigned long _Time, unsigned long _Data1, unsigned long _Data2);

extern void M3DLWLighthouse_OnUpdate(int suspend);
extern void M3DLWLighthouse_LoadBackground2D(void);
extern void M3DLWLighthouse_RemoveBackground2D(void);

extern int M3DLWLighthouse_Init(void);
extern int M3DLWLighthouse_Init2(void);
extern void M3DLWLighthouse_Release(void);
extern int M3DLWLighthouse_LoadContent(void);
extern void M3DLWLighthouse_Update(void);
extern void M3DLWLighthouse_ProcessTouch(int _mouseX, int _mouseY);

#ifdef __cplusplus
}
#endif

#endif /* __IGV5_PLAYER_H__ */


