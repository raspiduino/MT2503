//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWDaydream
// File        : M3DLWDaydream.c
// Description : IGV5 LW Daydream
// Author      : Ray
// Create      : 2011-09-18
// Update      : 2011-12-22
//==============================================================================

#include "M3DGameDef.h"
#include "M3DLWDaydream.h"
#include "M3DTextureManager.h"
#include "M3DEventQueue.h"

#ifdef __cplusplus
extern "C" {
#endif

M3DLWDaydreamApp M3DLWDaydream = {0};
static M3DRenderer *rr = NULL;

//================== Interface Begin =========================
int M3DLWDaydream_OnStartup(void *_pc)
{
	M3DConfig *PC = (M3DConfig *)_pc;
	int ret = 1;

	rr = &M3DLWDaydream.m_Renderer;

	m3d_adaption_init(&M3DLWDaydream.m_adaption, _pc);
	PC->m_pMemBuffer = m3d_alloc_engine_memory(&M3DLWDaydream.m_adaption, PC->m_MemSize);

	ret = M3DRenderer_Init(&M3DLWDaydream.m_Renderer, PC);

	M3DLWDaydream_Init();

	return ret;
}

void M3DLWDaydream_OnShutdown(void)
{
	M3DLWDaydream_Release();
	M3DRenderer_Del(rr);
	m3d_free_engine_memory(&M3DLWDaydream.m_adaption);
}

void M3DLWDaydream_OnResume(void)
{
	m3d_time_resume(&M3DLWDaydream.m_adaption);
}

void M3DLWDaydream_PostEvent(unsigned long _Id, unsigned long _Time, unsigned long _Data1, unsigned long _Data2)
{
	unsigned long Time = _Time;

	if (M3DLWDaydream.m_GameTime < IGLW_DAYDREAM_DELAY_TIME)
		return;

	if (Time == 0L)
		Time = (long) M3DLWDaydream.m_GameTime;
	M3DEventQueue_PostEvent(M3DLWDaydream.m_EventMemPool, M3DLWDaydream.m_Event, _Id, Time, _Data1, _Data2);
}

static M3DEvent *pSE = NULL;

void M3DLWDaydream_OnUpdate(int suspend)
{
	static long MouseX = 0L;

	M3DLWDaydream.m_ElapsedTime = m3d_time_get_elapsed(&M3DLWDaydream.m_adaption);
	M3DLWDaydream.m_ElapsedTime = (float) (M3DLWDaydream.m_ElapsedTime * M3DLWDaydream.m_TimeFactor);

#if defined(M3D_DEBUG_FRAME)
	M3DLWDaydream.m_ElapsedTime = 10L;	//for debug
#endif

    if (suspend)
    {
        M3DLWDaydream.m_ElapsedTime = 0L; //real suspend animation and stop IG reference time
    }

	M3DLWDaydream.m_GameTime = M3DLWDaydream.m_GameTime + M3DLWDaydream.m_ElapsedTime;
	M3DLWDaydream.m_Renderer.m_GameTime = M3DLWDaydream.m_GameTime;

	while ((pSE = (M3DEvent *) M3DQueue_Pop(M3DLWDaydream.m_Event)) != NULL)
	{
		unsigned mem_used = M3DRenderer_GetUsedMemory(&M3DLWDaydream.m_Renderer);

		//remove all event
		if (M3DLWDaydream.m_GameTime < IGLW_DAYDREAM_DELAY_TIME)
		{
			M3DEventQueue_Free(M3DLWDaydream.m_EventMemPool, pSE);
			continue;
		}

		switch (pSE->m_uEventID)
		{
		case IGV5EID_BEGINTOUCH :
			M3DRotateCenter_SetTouch(&M3DLWDaydream.m_RotateCamera, 1);
			M3DLWDaydream.m_iTouched = 1;
			M3DLWDaydream.m_iTouchX = pSE->m_uData1;
			M3DLWDaydream.m_iTouchY = pSE->m_uData2;
			//M3DLWDaydream_ProcessTouch(pSE->m_uData1, pSE->m_uData2);
			MouseX = pSE->m_uData1;
			break;
		case IGV5EID_TOUCH :	
			if (M3DLWPage_IsLastPage(&M3DLWDaydream.m_Page) == 1 && ((signed)pSE->m_uData1 - MouseX) < 0)
				M3DRotateCenter_MoveOut(&M3DLWDaydream.m_RotateCamera, 5.0f, 5.0f);
			if (M3DLWPage_IsFirstPage(&M3DLWDaydream.m_Page) == 1 && ((signed)pSE->m_uData1 - MouseX) > 0)
				M3DRotateCenter_MoveOut(&M3DLWDaydream.m_RotateCamera, -5.0f, 5.0f);
			MouseX = pSE->m_uData1;
			break;
		case IGV5EID_ENDTOUCH :
			M3DRotateCenter_SetTouch(&M3DLWDaydream.m_RotateCamera, 0);
			MouseX = pSE->m_uData1;
			break;
		case  IGV5EID_LWBOUNDSCHANGED :
			M3DLWPage_Changed(&M3DLWDaydream.m_Page, pSE->m_uData1);
			break;
		}

		M3DEventQueue_Free(M3DLWDaydream.m_EventMemPool, pSE);
	}

	if (M3DLWDaydream.m_GameTime > IGLW_2D_DELAY_TIME && M3DLWDaydream.m_Scene->m_bLoaded == 0)
		M3DLWDaydream_Init2();

	if (M3DLWDaydream.m_GameTime <= IGLW_2D_DELAY_TIME)
		M3DRenderer_Render2D(&M3DLWDaydream.m_Renderer, "bg2d.pvr");
	else
		M3DLWDaydream_Update();
}

//================== Interface End ===========================
int M3DLWDaydream_Init(void)
{
	M3DLWDaydream.m_Scene = M3DModel_New(&M3DLWDaydream.m_Renderer, "scene");
	M3DLWDaydream.m_Cloud = M3DModel_New(&M3DLWDaydream.m_Renderer, "cloud");
	M3DLWDaydream.m_Plane = M3DModel_New(&M3DLWDaydream.m_Renderer, "Plane");
	M3DLWDaydream.m_Cash =  M3DModel_New(&M3DLWDaydream.m_Renderer, "cash");
	M3DLWDaydream.m_SceneTextureNames = NULL;
	M3DLWDaydream.m_CloudTextureNames = NULL;
	M3DLWDaydream.m_PlaneTextureNames = NULL;
	M3DLWDaydream.m_CashTextureNames  = NULL;

	M3DLWDaydream.m_Node100[0] = NULL;
	M3DLWDaydream.m_Node100[1] = NULL;
	M3DLWDaydream.m_Node100[2] = NULL;
	M3DLWDaydream.m_iNode100 = 0;

	M3DLWDaydream_LoadBackground2D();

	M3DLWDaydream.m_EventMemPool = M3DEventQueue_New(MAX_ARRAY_POOL);
	M3DLWDaydream.m_Event = M3DQueue_New(DEFAULT_QUEUE_SIZE);
	M3DLWDaydream.m_TimeFactor = 0.5f;
	M3DLWDaydream.m_GameTime = 0L;
	M3DLWDaydream.m_GameTime_DelayLoad = IGLW_DAYDREAM_DELAY_TIME;
	M3DLWDaydream.m_StartPlane = -1;
	M3DLWDaydream.m_StartCash = -1;

	return 1;
}

int M3DLWDaydream_Init2(void)
{
	M3DLWDaydream_RemoveBackground2D();

	M3DLWDaydream_LoadContent();

	M3DLWDaydream.m_Node100[0] = M3DNode_NewParent(M3DLWDaydream.m_Scene, "100_1");
	M3DLWDaydream.m_Node100[1] = M3DNode_NewParent(M3DLWDaydream.m_Scene, "100_2");
	M3DLWDaydream.m_Node100[2] = M3DNode_NewParent(M3DLWDaydream.m_Scene, "100_3");
	M3DLWDaydream.m_iNode100 = 0;

	M3DRotateCenter_InitPager(&M3DLWDaydream.m_RotateCamera, &M3DLWDaydream.m_Page, -45.0f, 45.0f);

	M3DModel_SetActiveCamera(M3DLWDaydream.m_Scene);
	M3DModel_SetActiveLight(M3DLWDaydream.m_Scene);

	M3DRenderer_Shader_SetAlphaThreshold(&M3DLWDaydream.m_Renderer, M3D_GOURAUD_SHADER, 0.01f);
	M3DRenderer_Shader_SetAlphaThreshold(&M3DLWDaydream.m_Renderer, M3D_UV_DISPLACEMENT_SHADER, 0.01f);
	M3DRenderer_SetAlphaTestCmpValue(&M3DLWDaydream.m_Renderer, 0.01f);
	
	M3DLWPage_Init(&M3DLWDaydream.m_Page, M3DLWDaydream.m_Renderer.m_EngineRC.m_sEGLInfo.m_uWidth, 5);
	
	return 1;
}

void M3DLWDaydream_Release(void)
{
	M3DEventQueue_ClearPendingEvents(M3DLWDaydream.m_EventMemPool, M3DLWDaydream.m_Event);
	M3DEventQueue_Del(M3DLWDaydream.m_EventMemPool);
	M3DLWDaydream.m_EventMemPool = NULL;
	M3DQueue_Del(M3DLWDaydream.m_Event);
	M3DLWDaydream.m_Event = NULL;
	M3DLWDaydream.m_GameTime = 0L;

	M3DSplitString_Del(M3DLWDaydream.m_CashTextureNames);
	M3DSplitString_Del(M3DLWDaydream.m_PlaneTextureNames);
	M3DSplitString_Del(M3DLWDaydream.m_CloudTextureNames);
	M3DSplitString_Del(M3DLWDaydream.m_SceneTextureNames);

	M3DNode_Del(M3DLWDaydream.m_Node100[0]);
	M3DNode_Del(M3DLWDaydream.m_Node100[1]);
	M3DNode_Del(M3DLWDaydream.m_Node100[2]);

	M3DModel_Del(M3DLWDaydream.m_Cash);
	M3DModel_Del(M3DLWDaydream.m_Plane);
	M3DModel_Del(M3DLWDaydream.m_Cloud);
	M3DModel_Del(M3DLWDaydream.m_Scene);
}

void M3DLWDaydream_CheckAndStartPlane(void)
{
	if (M3DLWDaydream.m_GameTime > IGLW_DAYDREAM_DELAY_TIME && M3DLWDaydream.m_StartPlane == -1)
	{
		int iAni = m3d_adaption_rand() % 3;

		M3DLWDaydream.m_StartPlane = M3DLWDaydream.m_GameTime;
		M3DModel_SetAnimationStart(M3DLWDaydream.m_Plane, iAni);
		M3DModel_AnimateStop(M3DLWDaydream.m_Cash);
		M3DLWDaydream.m_iCashPicked = 0;
		M3DModel_EnableAllNode(M3DLWDaydream.m_Cash, 0);

		switch (iAni)
		{
		case 0 :
			M3DLWDaydream.m_StartCash = M3DLWDaydream.m_StartPlane + (75 * 1000) / 30;
			break;
		case 1 :
			M3DLWDaydream.m_StartCash = M3DLWDaydream.m_StartPlane + (87 * 1000) / 30;
			break;
		case 2 :
			M3DLWDaydream.m_StartCash = M3DLWDaydream.m_StartPlane + (60 * 1000) / 30;
			break;
		}
	}

	if (M3DLWDaydream.m_StartPlane > 0 && M3DLWDaydream.m_StartCash > 0 && M3DLWDaydream.m_GameTime > M3DLWDaydream.m_StartCash)
	{
		int iTex = m3d_adaption_rand() % 2;
		M3DLWDaydream.m_StartCash = -1;
		M3DModel_AnimateStart(M3DLWDaydream.m_Cash);
		M3DModel_EnableAllNode(M3DLWDaydream.m_Cash, 1);
#if defined(IGLW_DAYDREAM_CHANGE_TEXTURE)
		switch (iTex)
		{
		case 0 :
			M3DModel_ChangeSingleTexture(M3DLWDaydream.m_Cash, "Cash_01.pvr");
			//M3DModel_ChangeTexture(M3DLWDaydream.m_Cash, "Cash_01.pvr", "Cash_01.pvr");
			break;
		case 1 :
			M3DModel_ChangeSingleTexture(M3DLWDaydream.m_Cash, "Cash_02.pvr");
			//M3DModel_ChangeTexture(M3DLWDaydream.m_Cash, "Cash_01.pvr", "Cash_02.pvr");
			break;
		}
#endif
	}

	if (M3DLWDaydream.m_StartCash == -1 && M3DLWDaydream.m_Cash->m_Stop == 1)
	{
		M3DLWDaydream.m_StartPlane = -1;
		M3DModel_AnimateStop(M3DLWDaydream.m_Plane);
		M3DModel_AnimateStop(M3DLWDaydream.m_Cash);
		M3DLWDaydream.m_iCashPicked = 0;
	}
}

void M3DLWDaydream_Update(void)
{
	if (M3DLWDaydream.m_Cash->m_bLoaded == 0 && M3DLWDaydream.m_GameTime > M3DLWDaydream.m_GameTime_DelayLoad)
	{
		M3DLWDaydream_LoadContent2();
	}

	M3DLWDaydream_CheckAndStartPlane();
	//M3DModel_AnimateLoop(M3DLWDaydream.m_Scene, M3DLWDaydream.m_ElapsedTime, 0);
	M3DModel_AnimateLoop(M3DLWDaydream.m_Cloud, M3DLWDaydream.m_ElapsedTime, 0);
	//M3DModel_AnimateLoop(M3DLWDaydream.m_Plane, M3DLWDaydream.m_ElapsedTime, 0);
	M3DModel_AnimateOnce(M3DLWDaydream.m_Cash, M3DLWDaydream.m_ElapsedTime);
	M3DModel_AnimateCurrentOnce(M3DLWDaydream.m_Plane, M3DLWDaydream.m_ElapsedTime);

	M3DNode_AnimateChildsOnce(M3DLWDaydream.m_Node100[0], M3DLWDaydream.m_ElapsedTime);
	M3DNode_AnimateChildsOnce(M3DLWDaydream.m_Node100[1], M3DLWDaydream.m_ElapsedTime);
	M3DNode_AnimateChildsOnce(M3DLWDaydream.m_Node100[2], M3DLWDaydream.m_ElapsedTime);

	M3DRenderer_SetCameraRotation(rr, M3DRotateCenter_UpdatePage(&M3DLWDaydream.m_RotateCamera, M3DLWDaydream.m_ElapsedTime));
	M3DRenderer_UpdateCameraRotation(rr);

	M3DRenderer_PrepareRender(&M3DLWDaydream.m_Renderer);

	//CY
	M3DModel_Render(M3DLWDaydream.m_Plane);
	M3DModel_Render(M3DLWDaydream.m_Cash);	
	M3DModel_Render(M3DLWDaydream.m_Scene);
	IGV5Renderer_SetZWrite(IGV5_FALSE);
	M3DModel_Render(M3DLWDaydream.m_Cloud);
	IGV5Renderer_SetZWrite(IGV5_TRUE);


	M3DRenderer_Render(&M3DLWDaydream.m_Renderer);
	//M3DRenderer_Animate(&M3DLWDaydream.m_Renderer, M3DLWDaydream.m_GameTime);
	//M3DRenderer_Update(&M3DLWDaydream.m_Renderer, M3DLWDaydream.m_GameTime);

	if (M3DLWDaydream.m_iTouched == 1)
	{
		M3DLWDaydream_ProcessTouch(M3DLWDaydream.m_iTouchX, M3DLWDaydream.m_iTouchY);
		M3DLWDaydream.m_iTouched = 0;
	}

	/* calculate FPS */
	m3d_time_update_FPS(&M3DLWDaydream.m_adaption, &M3DLWDaydream.m_Renderer.m_EngineRC.m_sPerformanceInfo);
}

void M3DLWDaydream_ProcessTouch(int _mouseX, int _mouseY)
{
	char *node_name = NULL;

	node_name = M3DModel_PickLastNode(M3DLWDaydream.m_Cash, _mouseX, _mouseY);
	if (node_name != NULL)
	{
		M3DModel_EnableNode(M3DLWDaydream.m_Cash, node_name, 0);
		M3DLWDaydream.m_iCashPicked++;

		switch (M3DLWDaydream.m_iNode100)
		{
		case 0 :
			M3DNode_AnimateStart(M3DLWDaydream.m_Node100[0], 0.0f);
			M3DLWDaydream.m_iNode100 = 1;
			break;
		case 1:
			M3DNode_AnimateStart(M3DLWDaydream.m_Node100[1], 0.0f);
			M3DLWDaydream.m_iNode100 = 2;
			break;
		case 2:
			M3DNode_AnimateStart(M3DLWDaydream.m_Node100[2], 0.0f);
			M3DLWDaydream.m_iNode100 = 0;
			break;
		}
	}

	/*
	if (M3DLWDaydream.m_iCashPicked >= 20)
	{
		M3DLWDaydream.m_StartPlane = -1;
		M3DModel_AnimateStop(M3DLWDaydream.m_Plane);
		M3DModel_AnimateStop(M3DLWDaydream.m_Cash);
		M3DLWDaydream.m_iCashPicked = 0;
	}
	*/
}

#ifdef __cplusplus
}
#endif

/* end of M3DLWDaydream.c */

