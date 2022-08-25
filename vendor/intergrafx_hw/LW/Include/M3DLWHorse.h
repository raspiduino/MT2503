//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWHorse
// File        : M3DLWHorse.h
// Description : IGV5 LW Horse
// Author      : Ray
// Create      : 2011-09-20
// Update      : 2011-12-23
//==============================================================================

#ifndef __M3D_LW_HORSE_H__
#define __M3D_LW_HORSE_H__

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

#define IGLW_HORSE_DELAY_TIME	5000
#define IGLW_HORSE_REFLECTION  1

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _M3DLWHorse
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
	M3DModel		*m_Butterfly;
	M3DModel		*m_Tree;
	M3DModel		*m_Others;
	M3DModel		*m_Leaf;
	M3DModel		*m_Fog;
	M3DModel		*m_Horse[5];
	int				m_HorseState[5];
	M3DSplitString	*m_SceneTextureNames;
	M3DSplitString	*m_ButterflyTextureNames;
	M3DSplitString	*m_TreeTextureNames;
	M3DSplitString	*m_OthersTextureNames;
	M3DSplitString	*m_LeafTextureNames;
	M3DSplitString	*m_FogTextureNames;
	M3DSplitString	*m_HorseTextureNames[5];

	M3DRotateCenter	m_RotateCamera;
	M3DLWPage		m_Page;
	CVector3f		m_CameraPosition;
} M3DLWHorseApp;

extern M3DLWHorseApp M3DLWHorse;

extern int  M3DLWHorse_OnStartup(void *_pc);
extern void M3DLWHorse_OnShutdown(void);
extern void M3DLWHorse_OnResume(void);

extern void M3DLWHorse_PostEvent(unsigned long _Id, unsigned long _Time, unsigned long _Data1, unsigned long _Data2);

extern void M3DLWHorse_OnUpdate(int suspend);
extern void M3DLWHorse_LoadBackground2D(void);
extern void M3DLWHorse_RemoveBackground2D(void);

extern int  M3DLWHorse_Init(void);
extern int  M3DLWHorse_Init2(void);
extern int  M3DLWHorse_LoadContent(void);
extern void M3DLWHorse_LoadContent2(void);
extern void M3DLWHorse_Release(void);
extern void M3DLWHorse_Update(void);
extern void M3DLWHorse_ProcessTouch(int _mouseX, int _mouseY);

#ifdef __cplusplus
}
#endif

#endif /* __IGV5_PLAYER_H__ */


