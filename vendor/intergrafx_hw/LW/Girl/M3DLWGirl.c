//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWGirl
// File        : M3DLWGirl.c
// Description : IGV5 LW Girl
// Author      : Ray
// Create      : 2011-06-20
// Update      : 2011-12-20
//==============================================================================

#include "M3DGameDef.h"
#include "M3DLWGirl.h"
#include "M3DTextureManager.h"
#include "M3DEventQueue.h"

#ifdef __cplusplus
extern "C" {
#endif

M3DLWGirlApp M3DLWGirl = {0};

//================== Interface Begin =========================
int M3DLWGirl_OnStartup(void *_pc)
{
	M3DConfig *PC = (M3DConfig *)_pc;
	int ret = 1;

	m3d_adaption_init(&M3DLWGirl.m_adaption, _pc);
	m3d_adaption_before_startup();
	PC->m_pMemBuffer = m3d_alloc_engine_memory(&M3DLWGirl.m_adaption, PC->m_MemSize);

	ret = M3DRenderer_Init(&M3DLWGirl.m_Renderer, PC);

	M3DLWGirl_Init();
	m3d_time_resume(&M3DLWGirl.m_adaption);

	return ret;
}

void M3DLWGirl_OnShutdown(void)
{
	M3DLWGirl_Release();
	M3DRenderer_Del(&M3DLWGirl.m_Renderer);
	m3d_free_engine_memory(&M3DLWGirl.m_adaption);
}

void M3DLWGirl_OnResume(void)
{
	m3d_time_resume(&M3DLWGirl.m_adaption);
}

void M3DLWGirl_PostEvent(unsigned long _Id, unsigned long _Time, unsigned long _Data1, unsigned long _Data2)
{
	unsigned long Time = _Time;

	if (M3DLWGirl.m_GameTime < IGLW_GIRL_DELAY_TIME)
		return;

	if (Time == 0L)
		Time = (long) M3DLWGirl.m_GameTime;
	M3DEventQueue_PostEvent(M3DLWGirl.m_EventMemPool, M3DLWGirl.m_Event, _Id, Time, _Data1, _Data2);
}

static M3DEvent *pSE = NULL;

void M3DLWGirl_OnUpdate(int suspend)
{
	M3DLWGirl.m_ElapsedTime = m3d_time_get_elapsed(&M3DLWGirl.m_adaption);
	
	M3DLWGirl.m_ElapsedTime = (float) (M3DLWGirl.m_ElapsedTime * M3DLWGirl.m_TimeFactor);

#if defined(M3D_DEBUG_FRAME)
	M3DLWGirl.m_ElapsedTime = 10L;	//for debug
#endif

    if (suspend)
    {
        M3DLWGirl.m_ElapsedTime = 0L; //real suspend animation and stop IG reference time
    }

	M3DLWGirl.m_GameTime = M3DLWGirl.m_GameTime + M3DLWGirl.m_ElapsedTime;

	while ((pSE = (M3DEvent *) M3DQueue_Pop(M3DLWGirl.m_Event)) != NULL)
	{
		unsigned mem_used = M3DRenderer_GetUsedMemory(&M3DLWGirl.m_Renderer);

		//remove all event
		if (M3DLWGirl.m_GameTime < IGLW_GIRL_DELAY_TIME)
		{
			M3DEventQueue_Free(M3DLWGirl.m_EventMemPool, pSE);
			continue;
		}

		switch (pSE->m_uEventID)
		{
		case IGV5EID_BEGINTOUCH :
			M3DRotateCenter_SetTouch(&M3DLWGirl.m_RotateCamera, 1);
			M3DLWGirl_ProcessTouch(pSE->m_uData1, pSE->m_uData2);
			break;
		case IGV5EID_TOUCH :	
			//M3DRotateCenter_MoveByPixel(&M3DLWGirl.m_RotateCamera, (signed)pSE->m_uData2 - MouseY, -1.0);
			//if (M3DLWPage_IsLastPage(&M3DLWGirl.m_Page) == 1 && ((signed)pSE->m_uData1 - MouseX) < 0)
			//	M3DRotateCenter_MoveOut(&M3DLWGirl.m_RotateCamera, -10.0f, 10.0f);
			//if (M3DLWPage_IsFirstPage(&M3DLWGirl.m_Page) == 1 && ((signed)pSE->m_uData1 - MouseX) > 0)
			//	M3DRotateCenter_MoveOut(&M3DLWGirl.m_RotateCamera, 10.0f, 10.0f);
			break;
		case IGV5EID_ENDTOUCH :
			M3DRotateCenter_SetTouch(&M3DLWGirl.m_RotateCamera, 0);
			break;
		case  IGV5EID_LWBOUNDSCHANGED :
			if (M3DLWGirl.m_bMatchPage == 1)
				M3DLWPage_Changed(&M3DLWGirl.m_Page, pSE->m_uData1);
			break;
		}

		M3DEventQueue_Free(M3DLWGirl.m_EventMemPool, pSE);
	}

	if (M3DLWGirl.m_GameTime > IGLW_2D_DELAY_TIME && M3DLWGirl.m_Scene->m_bLoaded == 0)
		M3DLWGirl_Init2();

	if (M3DLWGirl.m_GameTime <= IGLW_2D_DELAY_TIME)
		M3DRenderer_Render2D(&M3DLWGirl.m_Renderer, "bg2d.pvr");
	else
		M3DLWGirl_Update();
}

//================== Interface End ===========================

int M3DLWGirl_Init(void)
{
	M3DLWGirl.m_Scene = M3DModel_New(&M3DLWGirl.m_Renderer, "scene");
	M3DLWGirl.m_Girl = M3DModel_New(&M3DLWGirl.m_Renderer, "girl");
	M3DLWGirl.m_SceneTextureNames = NULL;
	M3DLWGirl.m_GirlTextureNames = NULL;

	M3DLWGirl_LoadBackground2D();

	M3DLWGirl.m_EventMemPool = M3DEventQueue_New(MAX_ARRAY_POOL);
	M3DLWGirl.m_Event = M3DQueue_New(DEFAULT_QUEUE_SIZE);
	M3DLWGirl.m_TimeFactor = 1.0f;
	M3DLWGirl.m_GameTime = 0L;
	M3DLWGirl.m_GameTime_DelayLoad = IGLW_GIRL_DELAY_TIME;
	M3DLWGirl.m_bMatchPage = 0;
	M3DLWGirl.m_Renderer.m_LoadState = 0;

	return 1;
}

int M3DLWGirl_Init2(void)
{
	M3DLWGirl_RemoveBackground2D();

	M3DLWGirl_LoadContent();

	M3DRotateCenter_InitPager(&M3DLWGirl.m_RotateCamera, &M3DLWGirl.m_Page, -16.0f, 16.0f);
	//M3DRotateCenter_InitPager(&M3DLWGirl.m_RotateCamera, &M3DLWGirl.m_Page, -65.0f, -45.0f);
	//M3DRotateCenter_Init2(&M3DLWGirl.m_RotateCamera, 30.0f, 45.0f);

	M3DModel_SetActiveCamera(M3DLWGirl.m_Scene);
	M3DModel_SetActiveLight(M3DLWGirl.m_Scene);

	M3DLWPage_Init(&M3DLWGirl.m_Page, M3DLWGirl.m_Renderer.m_EngineRC.m_sEGLInfo.m_uWidth, 5);
	return 1;
}

void M3DLWGirl_Release(void)
{
	M3DEventQueue_ClearPendingEvents(M3DLWGirl.m_EventMemPool, M3DLWGirl.m_Event);
	M3DEventQueue_Del(M3DLWGirl.m_EventMemPool);
	M3DLWGirl.m_EventMemPool = NULL;
	M3DQueue_Del(M3DLWGirl.m_Event);
	M3DLWGirl.m_Event = NULL;
	M3DLWGirl.m_GameTime = 0L;

	if (M3DLWGirl.m_Renderer.m_LoadState == 0)
		return;

	M3DSplitString_Del(M3DLWGirl.m_GirlTextureNames);
	M3DSplitString_Del(M3DLWGirl.m_SceneTextureNames);

	M3DModel_Del(M3DLWGirl.m_Girl);
	M3DModel_Del(M3DLWGirl.m_Scene);
}

void M3DLWGirl_Update(void)
{
	if (M3DLWGirl.m_Girl->m_bLoaded == 0 && M3DLWGirl.m_GameTime > M3DLWGirl.m_GameTime_DelayLoad)
	{
		M3DLWGirl_LoadContent2();
		M3DModel_SetShadow(M3DLWGirl.m_Girl);
	}

	if (M3DLWGirl.m_GameTime > 7000.0f && M3DLWGirl.m_bMatchPage == 0)
	{
		M3DLWPage_Changed(&M3DLWGirl.m_Page, m3d_adaption_get_pageX());
		M3DLWGirl.m_bMatchPage = 1;
	}

	M3DModel_AnimateLoop(M3DLWGirl.m_Scene, M3DLWGirl.m_ElapsedTime, 0);
	M3DModel_AnimateCurrent(M3DLWGirl.m_Girl, M3DLWGirl.m_ElapsedTime);

	//M3DRenderer_SetCameraRotation(rr, M3DRotateCenter_Update(&M3DLWGirl.m_RotateCamera, M3DLWGirl.m_ElapsedTime));
	//M3DRenderer_UpdateVerticalCameraRotation(rr);
	M3DRenderer_SetCameraRotation(&M3DLWGirl.m_Renderer, M3DRotateCenter_UpdatePageX(&M3DLWGirl.m_RotateCamera, M3DLWGirl.m_ElapsedTime));
	M3DRenderer_UpdateCameraRotation(&M3DLWGirl.m_Renderer);

	M3DRenderer_PrepareRender(&M3DLWGirl.m_Renderer);
	M3DRenderer_PrepareShadow(&M3DLWGirl.m_Renderer);
	M3DModel_RenderWithShadow(M3DLWGirl.m_Scene);

	//RAY::2011-10-06 Girl 不要 RenderWidhShadow, 免得身上的影子有問題
	M3DModel_Render(M3DLWGirl.m_Girl);
	M3DRenderer_Render(&M3DLWGirl.m_Renderer);
	//M3DRenderer_Animate(&M3DLWGirl.m_Renderer, M3DLWGirl.m_GameTime);
	//M3DRenderer_Update(&M3DLWGirl.m_Renderer, M3DLWGirl.m_GameTime);
	M3DRenderer_ReleaseShadow(&M3DLWGirl.m_Renderer);

	/* calculate FPS */
	m3d_time_update_FPS(&M3DLWGirl.m_adaption, &M3DLWGirl.m_Renderer.m_EngineRC.m_sPerformanceInfo);
}

int  M3DLWGirl_TestPick(char *_test_node, int _nPicked, int *_Picked)
{
	int bIsPicked = 0;
	int iPickedNodeIdx = -1;
	int cn = 0;
	char *node_name = NULL;

	for (cn = 0; cn < _nPicked; cn++)
	{
		iPickedNodeIdx = _Picked[cn];
		node_name = M3DLWGirl.m_Girl->m_Node.m_Scene.m_POD.pNode[iPickedNodeIdx].pszName;
		if (strcmp(node_name, _test_node) == 0)
		{
			bIsPicked = 1;
			break;
		}
	}

	return bIsPicked;
}

void M3DLWGirl_ProcessTouch(int _mouseX, int _mouseY)
{
	int Picked[16], nPicked;

	if (M3DModel_IsDefaultAnimation(M3DLWGirl.m_Girl) == 1)
	{
		nPicked = M3DModel_Pick(M3DLWGirl.m_Girl, Picked, _mouseX, _mouseY);
		if (M3DLWGirl_TestPick("Left_Arm", nPicked, Picked) == 1)
		{
			M3DModel_SetAnimation(M3DLWGirl.m_Girl, 2);
			return;
		}
		if (M3DLWGirl_TestPick("Right_Arm", nPicked, Picked) == 1)
		{
			M3DModel_SetAnimation(M3DLWGirl.m_Girl, 3);
			return;
		}
		if (M3DLWGirl_TestPick("Leg", nPicked, Picked) == 1)
		{
			M3DModel_SetAnimation(M3DLWGirl.m_Girl, 5);
			return;
		}
		if (M3DLWGirl_TestPick("Head-submesh0", nPicked, Picked) == 1)
		{
			M3DModel_SetAnimation(M3DLWGirl.m_Girl, 4);
			return;
		}
		if (M3DLWGirl_TestPick("Head-submesh1", nPicked, Picked) == 1)
		{
			M3DModel_SetAnimation(M3DLWGirl.m_Girl, 4);
			return;
		}
		if (M3DLWGirl_TestPick("Head-submesh2", nPicked, Picked) == 1)
		{
			M3DModel_SetAnimation(M3DLWGirl.m_Girl, 4);
			return;
		}
		if (M3DLWGirl_TestPick("Bady", nPicked, Picked) == 1)
		{
			M3DModel_SetAnimation(M3DLWGirl.m_Girl, 1);
			return;
		}
	}
}

#ifdef __cplusplus
}
#endif

/* end of M3DLWGirl.c */

