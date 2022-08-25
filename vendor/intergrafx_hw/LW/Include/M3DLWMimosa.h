//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWMimosa
// File        : M3DLWMimosa.h
// Description : IGV5 LW Mimosa
// Author      : Ray
// Create      : 2011-09-18
// Update      : 2011-11-04
//==============================================================================

#ifndef __M3D_LW_MIMOSA_H__
#define __M3D_LW_MIMOSA_H__

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

#define IGLW_MIMOSA_DELAY_TIME	3000
//#define IGLW_MIMOSA_REFLECTION  1

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _M3DLWMimosa
{
	float	m_GameTime;
	float	m_ElapsedTime;
	float	m_TimeFactor;
	float	m_GameTime_DelayLoad;

	float	m_FlowerTime[3];

	M3D_Adaption	m_adaption;
	M3DRenderer		m_Renderer;
	M3DArrayPool	*m_EventMemPool;
	M3DQueue		*m_Event;

	M3DModel		*m_Scene;
	M3DModel		*m_CameraPod;
	M3DModel		*m_Flowerpot;
	M3DModel		*m_Butterfly;
	M3DModel		*m_Window;
	M3DModel		*m_Plant;

	M3DNode			*m_Leaf[12];
	M3DNode			*m_Flower[3];
	M3DSplitString	*m_SceneTextureNames;
	M3DSplitString	*m_FlowerpotTextureNames;
	M3DSplitString	*m_ButterflyTextureNames;
	M3DSplitString	*m_WindowTextureNames;
	M3DSplitString	*m_PlantTextureNames;

	M3DRotateCenter	m_RotateCamera;
	M3DLWPage		m_Page;
} M3DLWMimosaApp;

extern M3DLWMimosaApp M3DLWMimosa;

extern int  M3DLWMimosa_OnStartup(void *_pc);
extern void M3DLWMimosa_OnShutdown(void);
extern void M3DLWMimosa_OnResume(void);

extern void M3DLWMimosa_PostEvent(unsigned long _Id, unsigned long _Time, unsigned long _Data1, unsigned long _Data2);

extern void M3DLWMimosa_OnUpdate(int suspend);
extern void M3DLWMimosa_LoadBackground2D(void);
extern void M3DLWMimosa_RemoveBackground2D(void);

extern int  M3DLWMimosa_Init(void);
extern int  M3DLWMimosa_Init2(void);
extern void M3DLWMimosa_Release(void);
extern int  M3DLWMimosa_LoadContent(void);
extern void M3DLWMimosa_LoadContent2(void);
extern void M3DLWMimosa_CheckFlowerTime(void);
extern void M3DLWMimosa_Update(void);
extern void M3DLWMimosa_ProcessTouch(int _mouseX, int _mouseY);
extern void M3DLWMimosa_ProcessChangePage(int _left);

#ifdef __cplusplus
}
#endif

#endif /* __IGV5_PLAYER_H__ */


