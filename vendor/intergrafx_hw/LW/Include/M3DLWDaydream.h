//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWDaydream
// File        : M3DLWDaydream.h
// Description : IGV5 LW Daydream
// Author      : Ray
// Create      : 2011-09-18
// Update      : 2011-12-22
//==============================================================================

#ifndef __M3D_LW_DAYDREAM_H__
#define __M3D_LW_DAYDREAM_H__

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

#define IGLW_DAYDREAM_DELAY_TIME	5000
#define IGLW_DAYDREAM_CHANGE_TEXTURE	1

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _M3DLWDaydream
{
	float	m_GameTime;
	float	m_ElapsedTime;
	float	m_TimeFactor;
	float	m_GameTime_DelayLoad;

	float	m_StartPlane;
	float	m_StartCash;

	M3D_Adaption	m_adaption;
	M3DRenderer		m_Renderer;
	M3DArrayPool	*m_EventMemPool;
	M3DQueue		*m_Event;

	M3DModel		*m_Scene;
	M3DModel		*m_Cloud;
	M3DModel		*m_Plane;
	M3DModel		*m_Cash;

	M3DNode			*m_Node100[3];
	int				m_iNode100;

	M3DSplitString	*m_SceneTextureNames;
	M3DSplitString	*m_CloudTextureNames;
	M3DSplitString	*m_PlaneTextureNames;
	M3DSplitString	*m_CashTextureNames;

	M3DRotateCenter	m_RotateCamera;
	M3DLWPage		m_Page;
	int				m_iCashPicked;
	int				m_iTouched;
	int				m_iTouchX, m_iTouchY;
} M3DLWDaydreamApp;

extern M3DLWDaydreamApp M3DLWDaydream;

extern int  M3DLWDaydream_OnStartup(void *_pc);
extern void M3DLWDaydream_OnShutdown(void);
extern void M3DLWDaydream_OnResume(void);

extern void M3DLWDaydream_PostEvent(unsigned long _Id, unsigned long _Time, unsigned long _Data1, unsigned long _Data2);

extern void M3DLWDaydream_OnUpdate(int suspend);

extern void M3DLWDaydream_LoadBackground2D(void);
extern void M3DLWDaydream_RemoveBackground2D(void);

extern int  M3DLWDaydream_Init(void);
extern int  M3DLWDaydream_Init2(void);
extern void M3DLWDaydream_Release(void);
extern int  M3DLWDaydream_LoadContent(void);
extern void M3DLWDaydream_LoadContent2(void);
extern void M3DLWDaydream_Update(void);
extern void M3DLWDaydream_ProcessTouch(int _mouseX, int _mouseY);

#ifdef __cplusplus
}
#endif

#endif /* __IGV5_PLAYER_H__ */


