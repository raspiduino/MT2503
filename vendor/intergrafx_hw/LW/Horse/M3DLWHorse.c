//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWHorse
// File        : M3DLWHorse.c
// Description : IGV5 LW Horse
// Author      : Ray
// Create      : 2011-09-20
// Update      : 2011-12-23
//==============================================================================

#include "M3DGameDef.h"
#include "M3DLWHorse.h"
#include "M3DTextureManager.h"
#include "M3DEventQueue.h"

#ifdef __cplusplus
extern "C" {
#endif

M3DLWHorseApp M3DLWHorse = {0};

//================== Interface Begin =========================
int M3DLWHorse_OnStartup(void *_pc)
{
	M3DConfig *PC = (M3DConfig *)_pc;
	int ret = 1;

	m3d_adaption_init(&M3DLWHorse.m_adaption, _pc);
	PC->m_pMemBuffer = m3d_alloc_engine_memory(&M3DLWHorse.m_adaption, PC->m_MemSize);

	ret = M3DRenderer_Init(&M3DLWHorse.m_Renderer, PC);
	M3DLWHorse.m_Renderer.m_CameraInfo.m_Near = 5.0f;

	M3DLWHorse_Init();
	m3d_time_resume(&M3DLWHorse.m_adaption);

	return ret;
}

void M3DLWHorse_OnShutdown(void)
{
	M3DLWHorse_Release();
	M3DRenderer_Del(&M3DLWHorse.m_Renderer);
	m3d_free_engine_memory(&M3DLWHorse.m_adaption);
}

void M3DLWHorse_OnResume(void)
{
	m3d_time_resume(&M3DLWHorse.m_adaption);
}

void M3DLWHorse_PostEvent(unsigned long _Id, unsigned long _Time, unsigned long _Data1, unsigned long _Data2)
{
	unsigned long Time = _Time;

	if (M3DLWHorse.m_GameTime < IGLW_HORSE_DELAY_TIME)
		return;

	if (Time == 0L)
		Time = (long) M3DLWHorse.m_GameTime;
	M3DEventQueue_PostEvent(M3DLWHorse.m_EventMemPool, M3DLWHorse.m_Event, _Id, Time, _Data1, _Data2);
}

static M3DEvent *pSE = NULL;

void M3DLWHorse_OnUpdate(int suspend)
{
	static long MouseX = 0L;

	if (M3DLWHorse.m_Event == NULL)
		return;

	M3DLWHorse.m_ElapsedTime = m3d_time_get_elapsed(&M3DLWHorse.m_adaption);
	M3DLWHorse.m_ElapsedTime = (float) (M3DLWHorse.m_ElapsedTime * M3DLWHorse.m_TimeFactor);

#if defined(M3D_DEBUG_FRAME)
	M3DLWHorse.m_ElapsedTime = 30L;	//for debug
#endif

    if (suspend)
    {
        M3DLWHorse.m_ElapsedTime = 0L; //real suspend animation and stop IG reference time
    }

	M3DLWHorse.m_GameTime = M3DLWHorse.m_GameTime + M3DLWHorse.m_ElapsedTime;
	M3DLWHorse.m_Renderer.m_GameTime = M3DLWHorse.m_GameTime;

	while ((pSE = (M3DEvent *) M3DQueue_Pop(M3DLWHorse.m_Event)) != NULL)
	{
		unsigned mem_used = M3DRenderer_GetUsedMemory(&M3DLWHorse.m_Renderer);

		//remove all event
		if (M3DLWHorse.m_GameTime < IGLW_HORSE_DELAY_TIME)
		{
			M3DEventQueue_Free(M3DLWHorse.m_EventMemPool, pSE);
			continue;
		}

		switch (pSE->m_uEventID)
		{
		case IGV5EID_BEGINTOUCH :
			M3DRotateCenter_SetTouch(&M3DLWHorse.m_RotateCamera, 1);
			M3DLWHorse_ProcessTouch(pSE->m_uData1, pSE->m_uData2);
			MouseX = pSE->m_uData1;
			break;
		case IGV5EID_TOUCH :
			if (M3DLWPage_IsLastPage(&M3DLWHorse.m_Page) == 1 && ((signed)pSE->m_uData1 - MouseX) < 0)
				M3DRotateCenter_Move(&M3DLWHorse.m_RotateCamera, 10.0f);
			if (M3DLWPage_IsFirstPage(&M3DLWHorse.m_Page) == 1 && ((signed)pSE->m_uData1 - MouseX) > 0)
				M3DRotateCenter_Move(&M3DLWHorse.m_RotateCamera, -10.0f);
			MouseX = pSE->m_uData1;
			break;
		case IGV5EID_ENDTOUCH :
			M3DRotateCenter_SetTouch(&M3DLWHorse.m_RotateCamera, 0);
			MouseX = pSE->m_uData1;
 			break;
		case  IGV5EID_LWBOUNDSCHANGED :
			M3DLWPage_Changed(&M3DLWHorse.m_Page, pSE->m_uData1);
			break;
		}

		M3DEventQueue_Free(M3DLWHorse.m_EventMemPool, pSE);
	}

	if (M3DLWHorse.m_GameTime > IGLW_2D_DELAY_TIME && M3DLWHorse.m_Scene->m_bLoaded == 0)
		M3DLWHorse_Init2();

	if (M3DLWHorse.m_GameTime <= IGLW_2D_DELAY_TIME)
		M3DRenderer_Render2D(&M3DLWHorse.m_Renderer, "bg2d.pvr");
	else
		M3DLWHorse_Update();
}

//================== Interface End ===========================
int M3DLWHorse_Init(void)
{
	M3DLWHorse.m_Scene = M3DModel_New(&M3DLWHorse.m_Renderer, "scene");
	M3DLWHorse.m_Butterfly   = M3DModel_New(&M3DLWHorse.m_Renderer, "butterfly");
	M3DLWHorse.m_Tree = M3DModel_New(&M3DLWHorse.m_Renderer, "tree");
	M3DLWHorse.m_Others = M3DModel_New(&M3DLWHorse.m_Renderer, "others");
	M3DLWHorse.m_Leaf = M3DModel_New(&M3DLWHorse.m_Renderer, "animal");
	M3DLWHorse.m_Fog    = M3DModel_New(&M3DLWHorse.m_Renderer, "fog");
	M3DLWHorse.m_Horse[0] = M3DModel_New(&M3DLWHorse.m_Renderer, "horse1");
	M3DLWHorse.m_Horse[1] = M3DModel_New(&M3DLWHorse.m_Renderer, "horse2");
	M3DLWHorse.m_Horse[2] = M3DModel_New(&M3DLWHorse.m_Renderer, "horse3");
	M3DLWHorse.m_Horse[3] = M3DModel_New(&M3DLWHorse.m_Renderer, "horse4");
	M3DLWHorse.m_Horse[4] = M3DModel_New(&M3DLWHorse.m_Renderer, "horse5");

	M3DLWHorse.m_SceneTextureNames     = NULL;
	M3DLWHorse.m_ButterflyTextureNames = NULL;
	M3DLWHorse.m_TreeTextureNames      = NULL;
	M3DLWHorse.m_OthersTextureNames    = NULL;
	M3DLWHorse.m_LeafTextureNames      = NULL;
	M3DLWHorse.m_FogTextureNames       = NULL;
	M3DLWHorse.m_HorseTextureNames[0]  = NULL;
	M3DLWHorse.m_HorseTextureNames[1]  = NULL;
	M3DLWHorse.m_HorseTextureNames[2]  = NULL;
	M3DLWHorse.m_HorseTextureNames[3]  = NULL;

	M3DLWHorse_LoadBackground2D();

	M3DLWHorse.m_EventMemPool = M3DEventQueue_New(MAX_ARRAY_POOL);
	M3DLWHorse.m_Event = M3DQueue_New(DEFAULT_QUEUE_SIZE);
	M3DLWHorse.m_TimeFactor = 1.0f;
	M3DLWHorse.m_GameTime = 0.0f;
	M3DLWHorse.m_GameTime_DelayLoad = IGLW_HORSE_DELAY_TIME;
	M3DLWHorse.m_Renderer.m_LoadState = 0;

	return 1;
}

int M3DLWHorse_Init2(void)
{
	M3DLWHorse_RemoveBackground2D();

	M3DLWHorse_LoadContent();

	M3DRotateCenter_InitPager(&M3DLWHorse.m_RotateCamera, &M3DLWHorse.m_Page, -580.0f, 0.0f);

	M3DModel_SetActiveCamera(M3DLWHorse.m_Scene);
	M3DModel_SetActiveLight(M3DLWHorse.m_Scene);

	//M3DLWPage_Init(&M3DLWHorse.m_Page, M3DLWHorse.m_Renderer.m_EngineRC.m_sEGLInfo.m_uWidth, 5);
	M3DRenderer_Shader_SetAlphaThreshold(&M3DLWHorse.m_Renderer, M3D_GOURAUD_SHADER, 0.01f);
	M3DRenderer_Shader_SetAlphaThreshold(&M3DLWHorse.m_Renderer, M3D_UV_DISPLACEMENT_SHADER, 0.05f);
	M3DRenderer_Shader_SetAlphaThreshold(&M3DLWHorse.m_Renderer, M3D_SKINNING_GOURAUD_SHADER, 0.01f);
	M3DRenderer_Shader_SetAlphaThreshold(&M3DLWHorse.m_Renderer, M3D_TEXTURE_SHADER, 0.01f);
	M3DRenderer_SetAlphaTestCmpValue(&M3DLWHorse.m_Renderer, 0.5f);

	/*
	M3DModel_EnableNode(M3DLWHorse.m_Tree, "Fog_front", IGV5_FALSE);
	M3DModel_EnableNode(M3DLWHorse.m_Tree, "Fog_back", IGV5_FALSE);
	*/
	
	M3DLWPage_Init(&M3DLWHorse.m_Page, M3DLWHorse.m_Renderer.m_EngineRC.m_sEGLInfo.m_uWidth, 5);
	M3DLWPage_Changed(&M3DLWHorse.m_Page, 0);

	M3DLWHorse.m_HorseState[0] = 0;
	M3DLWHorse.m_HorseState[2] = 0;
	return 1;
}

void M3DLWHorse_Release(void)
{
	M3DEventQueue_ClearPendingEvents(M3DLWHorse.m_EventMemPool, M3DLWHorse.m_Event);
	M3DEventQueue_Del(M3DLWHorse.m_EventMemPool);
	M3DLWHorse.m_EventMemPool = NULL;
	M3DQueue_Del(M3DLWHorse.m_Event);
	M3DLWHorse.m_Event = NULL;
	M3DLWHorse.m_GameTime = 0L;

	if (M3DLWHorse.m_Renderer.m_LoadState == 0)
		return;

	M3DSplitString_Del(M3DLWHorse.m_HorseTextureNames[3]);
	M3DSplitString_Del(M3DLWHorse.m_HorseTextureNames[2]);
	M3DSplitString_Del(M3DLWHorse.m_HorseTextureNames[1]);
	M3DSplitString_Del(M3DLWHorse.m_HorseTextureNames[0]);
	M3DSplitString_Del(M3DLWHorse.m_FogTextureNames);
	M3DSplitString_Del(M3DLWHorse.m_LeafTextureNames);
	M3DSplitString_Del(M3DLWHorse.m_OthersTextureNames);
	M3DSplitString_Del(M3DLWHorse.m_TreeTextureNames);
	M3DSplitString_Del(M3DLWHorse.m_ButterflyTextureNames);
	M3DSplitString_Del(M3DLWHorse.m_SceneTextureNames);

#if defined(IGLW_HORSE_REFLECTION)
	M3DRenderer_ReleaseReflection(&M3DLWHorse.m_Renderer);
#endif

	M3DModel_Del(M3DLWHorse.m_Horse[4]);
	M3DModel_Del(M3DLWHorse.m_Horse[3]);
	M3DModel_Del(M3DLWHorse.m_Horse[2]);
	M3DModel_Del(M3DLWHorse.m_Horse[1]);
	M3DModel_Del(M3DLWHorse.m_Horse[0]);
	M3DModel_Del(M3DLWHorse.m_Fog);
	M3DModel_Del(M3DLWHorse.m_Leaf);
	M3DModel_Del(M3DLWHorse.m_Others);
	M3DModel_Del(M3DLWHorse.m_Tree);
	M3DModel_Del(M3DLWHorse.m_Butterfly);
	M3DModel_Del(M3DLWHorse.m_Scene);
}

void M3DLWHorse_Update(void)
{
	CVector3f pos;
	CVector3f_Init(&pos, 0, 0, -100);

	if (M3DLWHorse.m_Horse[0]->m_bLoaded == 0 && M3DLWHorse.m_GameTime > M3DLWHorse.m_GameTime_DelayLoad)
	{
		M3DLWHorse_LoadContent2();

#if defined(IGLW_HORSE_REFLECTION)
		M3DModel_SetReflection(M3DLWHorse.m_Horse[2]);
		M3DModel_SetReflection(M3DLWHorse.m_Tree);
		M3DModel_InitReflector(M3DLWHorse.m_Fog, "River_02", 0.75f);
#endif

		M3DLWPage_Changed(&M3DLWHorse.m_Page, m3d_adaption_get_pageX());
	}

	M3DModel_AnimateLoop(M3DLWHorse.m_Scene, M3DLWHorse.m_ElapsedTime, 0);
	M3DModel_AnimateOnce(M3DLWHorse.m_Butterfly, M3DLWHorse.m_ElapsedTime);
	M3DModel_AnimateLoop(M3DLWHorse.m_Tree, M3DLWHorse.m_ElapsedTime, 0);
	M3DModel_AnimateLoop(M3DLWHorse.m_Fog, M3DLWHorse.m_ElapsedTime, 0);
	M3DModel_AnimateCurrent(M3DLWHorse.m_Horse[0], M3DLWHorse.m_ElapsedTime);
	M3DModel_AnimateLoop(M3DLWHorse.m_Horse[1], M3DLWHorse.m_ElapsedTime, 0);
	M3DModel_AnimateCurrent(M3DLWHorse.m_Horse[2], M3DLWHorse.m_ElapsedTime);
	M3DModel_AnimateLoop(M3DLWHorse.m_Horse[3], M3DLWHorse.m_ElapsedTime, 0);
	M3DModel_AnimateLoop(M3DLWHorse.m_Horse[4], M3DLWHorse.m_ElapsedTime, 0);
	M3DModel_AnimateOnce(M3DLWHorse.m_Leaf, M3DLWHorse.m_ElapsedTime);

	//M3DRenderer_SetCameraPan(rr, M3DRotateCenter_Update(&M3DLWHorse.m_RotateCamera, M3DLWHorse.m_GameTime));
	M3DRenderer_SetCameraPanZ(&M3DLWHorse.m_Renderer, M3DRotateCenter_UpdatePageX(&M3DLWHorse.m_RotateCamera, M3DLWHorse.m_ElapsedTime));
	M3DRenderer_UpdateCameraPan(&M3DLWHorse.m_Renderer);

	M3DRenderer_PrepareRender(&M3DLWHorse.m_Renderer);

#if defined(IGLW_HORSE_REFLECTION)
	M3DRenderer_PrepareReflection(&M3DLWHorse.m_Renderer);
#endif


   //CY begin
   
	
	M3DModel_Render(M3DLWHorse.m_Scene);	   

	
	M3DModel_Render(M3DLWHorse.m_Butterfly);
	M3DModel_Render(M3DLWHorse.m_Horse[0]);
	M3DModel_Render(M3DLWHorse.m_Horse[1]);
	M3DModel_Render(M3DLWHorse.m_Horse[2]);
	M3DModel_Render(M3DLWHorse.m_Horse[3]);
	M3DModel_Render(M3DLWHorse.m_Horse[4]);
	
	M3DModel_Render(M3DLWHorse.m_Leaf);
	
	M3DModel_Render(M3DLWHorse.m_Tree);
	

	
	M3DModel_Render(M3DLWHorse.m_Fog);	
	
	M3DModel_Render(M3DLWHorse.m_Others);	
	

	//CY end


	M3DRenderer_Render(&M3DLWHorse.m_Renderer);

	/* calculate FPS */
	m3d_time_update_FPS(&M3DLWHorse.m_adaption, &M3DLWHorse.m_Renderer.m_EngineRC.m_sPerformanceInfo);
}

void M3DLWHorse_ProcessTouch(int _mouseX, int _mouseY)
{
	int index = -1;
	CVector3f pos;

	index = M3DModel_PickNodeIndex(M3DLWHorse.m_Butterfly, _mouseX, _mouseY);
	if (index >= 0)
	{
		M3DModel_AnimateStart(M3DLWHorse.m_Butterfly);
		return;
	}

	index = M3DModel_PickNodeIndex(M3DLWHorse.m_Horse[0], _mouseX, _mouseY);
	if (index >= 0)
	{
		if (M3DLWHorse.m_HorseState[0] == 0)
		{
			M3DModel_SetDefaultAnimation(M3DLWHorse.m_Horse[0], 2, 1.0f);
			M3DModel_SetAnimation(M3DLWHorse.m_Horse[0], 1);
			M3DLWHorse.m_HorseState[0] = 1;
		}
		else
		{
			M3DModel_SetDefaultAnimation(M3DLWHorse.m_Horse[0], 0, 1.0f);
			M3DModel_SetAnimation(M3DLWHorse.m_Horse[0], 3);
			M3DLWHorse.m_HorseState[0] = 0;
		}
		return;
	}

	index = M3DModel_PickNodeIndex(M3DLWHorse.m_Horse[2], _mouseX, _mouseY);
	if (index >= 0)
	{
		//M3DModel_SetAnimation(M3DLWHorse.m_Horse[2], 1);
		if (M3DLWHorse.m_HorseState[2] == 0)
		{
			M3DModel_SetDefaultAnimation(M3DLWHorse.m_Horse[2], 1, 1.0f);
			M3DModel_SetAnimation(M3DLWHorse.m_Horse[2], 3);
			M3DLWHorse.m_HorseState[2] = 1;
		}
		else
		{
			M3DModel_SetDefaultAnimation(M3DLWHorse.m_Horse[2], 0, 1.0f);
			M3DModel_SetAnimation(M3DLWHorse.m_Horse[2], 2);
			M3DLWHorse.m_HorseState[2] = 0;
		}
		return;
	}

	M3DModel_SetAnimationStart(M3DLWHorse.m_Leaf, 0);
	CVector3f_Init(&pos, 0.0f, 0.0f, 0.0f);
	pos.z += M3DLWHorse.m_RotateCamera.m_Degree;
	//M3DModel_EnableNode(M3DLWHorse.m_Scene, "Leaves_ALL_01", 1);
	//M3DModel_EnableNode(M3DLWHorse.m_Scene, "Leaves_ALL_02", 1);
	M3DModel_SetNodePosition(M3DLWHorse.m_Leaf, "Leaves_ALL_01", &pos);
	M3DModel_SetNodePosition(M3DLWHorse.m_Leaf, "Leaves_ALL_02", &pos);
}

#ifdef __cplusplus
}
#endif

/* end of M3DLWHorse.c */

