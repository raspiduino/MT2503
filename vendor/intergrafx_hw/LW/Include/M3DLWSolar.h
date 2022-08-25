//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWSolar
// File        : M3DLWSolar.h
// Description : IGV5 LW Solar
// Author      : Ray
// Create      : 2011-08-25
// Update      : 2011-12-23
//==============================================================================

#ifndef __M3D_LW_SOLAR_H__
#define __M3D_LW_SOLAR_H__

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

#define IGLW_SOLAR_DELAY_TIME	3000

#ifdef __cplusplus
extern "C" {
#endif


typedef struct _M3DLWSolar
{
	float	m_GameTime;
	float	m_ElapsedTime;
	float	m_TimeFactor;

	M3D_Adaption	m_adaption;
	M3DRenderer		m_Renderer;
	M3DArrayPool	*m_EventMemPool;
	M3DQueue		*m_Event;

	M3DModel		*m_Scene;
	M3DModel		*m_Planet;
	M3DModel		*m_Tube;
	M3DSplitString	*m_SceneTextureNames;
	M3DSplitString	*m_PlanetTextureNames;
	M3DSplitString	*m_TubeTextureNames;

	M3DRotateCenter	m_RotateCamera;
	M3DRotateCenter	m_VerticalCamera;
	M3DLWPage		m_Page;
	M3DRotateSimple m_Revolution[8];
	float			m_RotateDegree;
	int				m_CameraStatus;
} M3DLWSolarApp;

extern M3DLWSolarApp M3DLWSolar;

extern int  M3DLWSolar_OnStartup(void *_pc);
extern void M3DLWSolar_OnShutdown(void);
extern void M3DLWSolar_OnResume(void);

extern void M3DLWSolar_PostEvent(unsigned long _Id, unsigned long _Time, unsigned long _Data1, unsigned long _Data2);

extern void M3DLWSolar_OnUpdate(int suspend);

extern void M3DLWSolar_LoadBackground2D(void);
extern void M3DLWSolar_RemoveBackground2D(void);

extern int  M3DLWSolar_Init(void);
extern int  M3DLWSolar_Init2(void);
extern void M3DLWSolar_Release(void);
extern void M3DLWSolar_Update(void);
extern int  M3DLWSolar_LoadContent(void);
extern void M3DLWSolar_ProcessTouch(int _mouseX, int _mouseY);

#ifdef __cplusplus
}
#endif

#endif /* __IGV5_PLAYER_H__ */


