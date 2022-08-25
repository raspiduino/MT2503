//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DPlayer
// File        : M3DPlayer.h
// Description : IGV5 Mali ´ú¸Õ±M®×
// Author      : Ray
// Create      : 2011-06-20
// Update      : 2011-06-20
//==============================================================================

#ifndef __IGV5_PLAYER_H__
#define __IGV5_PLAYER_H__

#include "IGV5RuntimeContext.h"
#include "IGV5Font.h"
#include "IGV5Camera.h"
#include "M3D_Adaption.h"
#include "M3DRenderer.h"

#include "win32_runtime.h"

#ifdef __cplusplus
extern "C" {
#endif

extern char texture_p1[];
extern char texture_p2[];

typedef struct _M3DPlayer
{
	long m_GameTime;
	M3D_Adaption	m_adaption;
	M3DRenderer		m_Renderer;
	//CArrayPool		*m_EventMemPool;
	//CQueue			*m_Event;

	//IGModel			m_Puppy;
} M3DPlayerApp;

extern M3DPlayerApp M3DPlayer;

extern int  M3DPlayer_OnStartup(void *_pc);
extern void M3DPlayer_OnShutdown(void);

extern void M3DPlayer_OnUpdate(void);

extern int M3DPlayer_LoadContent(void);
void M3DPlayer_Unload(void);
void M3DPlayer_Cleanup(void);

#ifdef __cplusplus
}
#endif

#endif /* __IGV5_PLAYER_H__ */


