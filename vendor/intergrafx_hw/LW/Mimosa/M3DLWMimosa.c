//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWMimosa
// File        : M3DLWMimosa.c
// Description : IGV5 LW Mimosa
// Author      : Ray
// Create      : 2011-09-18
// Update      : 2012-01-16
//==============================================================================

#include "M3DGameDef.h"
#include "M3DLWMimosa.h"
#include "M3DTextureManager.h"
#include "M3DEventQueue.h"

#ifdef __cplusplus
extern "C" {
#endif

M3DLWMimosaApp M3DLWMimosa = {0};
static M3DRenderer *rr = NULL;

//================== Interface Begin =========================
int M3DLWMimosa_OnStartup(void *_pc)
{
	M3DConfig *PC = (M3DConfig *)_pc;
	int ret = 1;

	rr = &M3DLWMimosa.m_Renderer;

	m3d_adaption_init(&M3DLWMimosa.m_adaption, _pc);
	PC->m_pMemBuffer = m3d_alloc_engine_memory(&M3DLWMimosa.m_adaption, PC->m_MemSize);

	ret = M3DRenderer_Init(&M3DLWMimosa.m_Renderer, PC);

	M3DLWMimosa_Init();
	m3d_time_resume(&M3DLWMimosa.m_adaption);

	return ret;
}

void M3DLWMimosa_OnShutdown(void)
{
	M3DLWMimosa_Release();
	M3DRenderer_Del(rr);
	m3d_free_engine_memory(&M3DLWMimosa.m_adaption);
}

void M3DLWMimosa_OnResume(void)
{
	m3d_time_resume(&M3DLWMimosa.m_adaption);
}


void M3DLWMimosa_PostEvent(unsigned long _Id, unsigned long _Time, unsigned long _Data1, unsigned long _Data2)
{
	unsigned long Time = _Time;

	if (M3DLWMimosa.m_GameTime < IGLW_MIMOSA_DELAY_TIME)
		return;

	if (Time == 0L)
		Time = (long) M3DLWMimosa.m_GameTime;
	M3DEventQueue_PostEvent(M3DLWMimosa.m_EventMemPool, M3DLWMimosa.m_Event, _Id, Time, _Data1, _Data2);
}

static M3DEvent *pSE = NULL;

void M3DLWMimosa_OnUpdate(int suspend)
{
	M3DLWMimosa.m_ElapsedTime = m3d_time_get_elapsed(&M3DLWMimosa.m_adaption);
	M3DLWMimosa.m_ElapsedTime = (float) (M3DLWMimosa.m_ElapsedTime * M3DLWMimosa.m_TimeFactor);

#if defined(M3D_DEBUG_FRAME)
	M3DLWMimosa.m_ElapsedTime = 30L;	//for debug
#endif

    if (suspend)
    {
        M3DLWMimosa.m_ElapsedTime = 0L; //real suspend animation and stop IG reference time
    }

	M3DLWMimosa.m_GameTime = M3DLWMimosa.m_GameTime + M3DLWMimosa.m_ElapsedTime;

	while ((pSE = (M3DEvent *) M3DQueue_Pop(M3DLWMimosa.m_Event)) != NULL)
	{
		unsigned mem_used = M3DRenderer_GetUsedMemory(&M3DLWMimosa.m_Renderer);

		//remove all event
		if (M3DLWMimosa.m_GameTime < IGLW_MIMOSA_DELAY_TIME)
		{
			M3DEventQueue_Free(M3DLWMimosa.m_EventMemPool, pSE);
			continue;
		}

		switch (pSE->m_uEventID)
		{
		case IGV5EID_BEGINTOUCH :
			M3DRotateCenter_SetTouch(&M3DLWMimosa.m_RotateCamera, 1);
			M3DLWMimosa_ProcessTouch(pSE->m_uData1, pSE->m_uData2);
			break;
		case IGV5EID_TOUCH :	
			//if (M3DLWPage_IsLastPage(&M3DLWMimosa.m_Page) == 1 && ((signed)pSE->m_uData1 - MouseX) < 0)
			//	M3DRotateCenter_MoveOut(&M3DLWMimosa.m_RotateCamera, 10.0f, 10.0f);
			//if (M3DLWPage_IsFirstPage(&M3DLWMimosa.m_Page) == 1 && ((signed)pSE->m_uData1 - MouseX) > 0)
			//	M3DRotateCenter_MoveOut(&M3DLWMimosa.m_RotateCamera, -10.0f, 10.0f);
			break;
		case IGV5EID_ENDTOUCH :
			M3DRotateCenter_SetTouch(&M3DLWMimosa.m_RotateCamera, 0);
			break;
		case  IGV5EID_LWBOUNDSCHANGED :
			M3DLWMimosa_ProcessChangePage(pSE->m_uData1);
			break;
		}

		M3DEventQueue_Free(M3DLWMimosa.m_EventMemPool, pSE);
	}

	if (M3DLWMimosa.m_GameTime > IGLW_2D_DELAY_TIME && M3DLWMimosa.m_Scene->m_bLoaded == 0)
		M3DLWMimosa_Init2();

	if (M3DLWMimosa.m_GameTime <= IGLW_2D_DELAY_TIME)
		M3DRenderer_Render2D(&M3DLWMimosa.m_Renderer, "bg2d.pvr");
	else
		M3DLWMimosa_Update();
}

//================== Interface End ===========================

int M3DLWMimosa_Init(void)
{
	M3DLWMimosa.m_Scene     = M3DModel_New(&M3DLWMimosa.m_Renderer, "scene");
	M3DLWMimosa.m_CameraPod = M3DModel_New(&M3DLWMimosa.m_Renderer, "camerapod");
	M3DLWMimosa.m_Flowerpot = M3DModel_New(&M3DLWMimosa.m_Renderer, "flowerpot");
	M3DLWMimosa.m_Butterfly = M3DModel_New(&M3DLWMimosa.m_Renderer, "butterfly");
	M3DLWMimosa.m_Window    = M3DModel_New(&M3DLWMimosa.m_Renderer, "Window");
	M3DLWMimosa.m_Plant     = M3DModel_New(&M3DLWMimosa.m_Renderer, "Plant");
	M3DLWMimosa.m_SceneTextureNames     = NULL;
	M3DLWMimosa.m_FlowerpotTextureNames = NULL;
	M3DLWMimosa.m_WindowTextureNames    = NULL;
	M3DLWMimosa.m_ButterflyTextureNames = NULL;
	M3DLWMimosa.m_PlantTextureNames     = NULL;

	M3DLWMimosa_LoadBackground2D();

	M3DLWMimosa.m_EventMemPool = M3DEventQueue_New(MAX_ARRAY_POOL);
	M3DLWMimosa.m_Event = M3DQueue_New(DEFAULT_QUEUE_SIZE);
	M3DLWMimosa.m_TimeFactor = 0.5f;
	M3DLWMimosa.m_GameTime = 0.0f;
	M3DLWMimosa.m_GameTime_DelayLoad = IGLW_MIMOSA_DELAY_TIME;
	M3DLWMimosa.m_FlowerTime[0] = 0.0f;
	M3DLWMimosa.m_FlowerTime[1] = 0.0f;
	M3DLWMimosa.m_FlowerTime[2] = 0.0f;

	return 1;
}

int M3DLWMimosa_Init2(void)
{
	M3DLWMimosa_RemoveBackground2D();

	M3DLWMimosa_LoadContent();

	M3DRotateCenter_InitPager(&M3DLWMimosa.m_RotateCamera, &M3DLWMimosa.m_Page, -85.0f, -30.0f);

	M3DModel_SetActiveCamera(M3DLWMimosa.m_CameraPod);
	M3DModel_SetActiveLight(M3DLWMimosa.m_Scene);

	M3DLWPage_Init(&M3DLWMimosa.m_Page, M3DLWMimosa.m_Renderer.m_EngineRC.m_sEGLInfo.m_uWidth, 5);
	//M3DModel_AnimateStart(M3DLWMimosa.m_CameraPod);
	M3DModel_SetDefaultAnimation(M3DLWMimosa.m_Plant, 1, 1.0f);
	M3DModel_SetAnimation(M3DLWMimosa.m_Plant, 1);
	//M3DModel_SetAnimation(M3DLWMimosa.m_Butterfly, 0);
	M3DRenderer_Shader_SetAlphaThreshold(&M3DLWMimosa.m_Renderer, M3D_GOURAUD_SHADER, 0.01f);
	M3DRenderer_Shader_SetAlphaThreshold(&M3DLWMimosa.m_Renderer, M3D_SKINNING_GOURAUD_SHADER, 0.01f);
	M3DRenderer_Shader_SetAlphaThreshold(&M3DLWMimosa.m_Renderer, M3D_TEXTURE_SHADER, 0.01f);
	M3DRenderer_Shader_SetAlphaThreshold(&M3DLWMimosa.m_Renderer, M3D_SKINNING_TEXTURE_SHADER, 0.01f);	
	M3DRenderer_SetAlphaTestCmpValue(&M3DLWMimosa.m_Renderer, 0.01f);

	return 1;
}

void M3DLWMimosa_Release(void)
{
	int cn = 0;
	M3DEventQueue_ClearPendingEvents(M3DLWMimosa.m_EventMemPool, M3DLWMimosa.m_Event);
	M3DEventQueue_Del(M3DLWMimosa.m_EventMemPool);
	M3DLWMimosa.m_EventMemPool = NULL;
	M3DQueue_Del(M3DLWMimosa.m_Event);
	M3DLWMimosa.m_Event = NULL;
	M3DLWMimosa.m_GameTime = 0L;

	for(cn = 0; cn < 9; cn++)
	{
		M3DNode_Del(M3DLWMimosa.m_Leaf[cn]);
		M3DLWMimosa.m_Leaf[cn] = NULL;
	}
	for(cn = 0; cn < 3; cn++)
	{
		M3DNode_Del(M3DLWMimosa.m_Flower[cn]);
		M3DLWMimosa.m_Flower[cn] = NULL;
	}

#if defined(IGLW_MIMOSA_REFLECTION)
	M3DRenderer_ReleaseReflection(&M3DLWMimosa.m_Renderer);
#endif

	M3DSplitString_Del(M3DLWMimosa.m_PlantTextureNames);
	M3DSplitString_Del(M3DLWMimosa.m_WindowTextureNames);
	M3DSplitString_Del(M3DLWMimosa.m_ButterflyTextureNames);
	M3DSplitString_Del(M3DLWMimosa.m_FlowerpotTextureNames);
	M3DSplitString_Del(M3DLWMimosa.m_SceneTextureNames);

	M3DModel_Del(M3DLWMimosa.m_Plant);
	M3DModel_Del(M3DLWMimosa.m_Window);
	M3DModel_Del(M3DLWMimosa.m_Butterfly);
	M3DModel_Del(M3DLWMimosa.m_Flowerpot);
	M3DModel_Del(M3DLWMimosa.m_CameraPod);
	M3DModel_Del(M3DLWMimosa.m_Scene);
}

void M3DLWMimosa_CheckFlowerTime(void)
{
	if (M3DLWMimosa.m_GameTime - M3DLWMimosa.m_FlowerTime[0] > 3000)
	{
		M3DNode_AnimateStart(M3DLWMimosa.m_Flower[0], 200.0f*1000.0f/30.0f);
		M3DLWMimosa.m_FlowerTime[0] = M3DLWMimosa.m_GameTime;
	}

	if (M3DLWMimosa.m_GameTime - M3DLWMimosa.m_FlowerTime[1] > 5000)
	{
		M3DNode_AnimateStart(M3DLWMimosa.m_Flower[1], 200.0f*1000.0f/30.0f);
		M3DLWMimosa.m_FlowerTime[1] = M3DLWMimosa.m_GameTime;
	}

	if (M3DLWMimosa.m_GameTime - M3DLWMimosa.m_FlowerTime[2] > 10000)
	{
		M3DNode_AnimateStart(M3DLWMimosa.m_Flower[2], 200.0f*1000.0f/30.0f);
		M3DLWMimosa.m_FlowerTime[2] = M3DLWMimosa.m_GameTime;
	}
}

void M3DLWMimosa_Update(void)
{
	int cn = 0;

	if (M3DLWMimosa.m_Plant->m_bLoaded == 0 && M3DLWMimosa.m_GameTime > M3DLWMimosa.m_GameTime_DelayLoad)
	{
		M3DLWMimosa_LoadContent2();

#if defined(IGLW_MIMOSA_REFLECTION)
		M3DModel_SetReflection(M3DLWMimosa.m_Flowerpot);
		M3DModel_SetReflection(M3DLWMimosa.m_Plant);
		M3DModel_SetReflection(M3DLWMimosa.m_Butterfly);
		M3DModel_InitReflector(M3DLWMimosa.m_Window, "Glass", 0.5f);
#endif

		M3DLWMimosa.m_Leaf[0] = M3DNode_NewBone(M3DLWMimosa.m_Plant, "Leaf_01");
		M3DLWMimosa.m_Leaf[1] = M3DNode_NewBone(M3DLWMimosa.m_Plant, "Leaf_02");
		M3DLWMimosa.m_Leaf[2] = M3DNode_NewBone(M3DLWMimosa.m_Plant, "Leaf_04");
		M3DLWMimosa.m_Leaf[3] = M3DNode_NewBone(M3DLWMimosa.m_Plant, "Leaf_05");
		M3DLWMimosa.m_Leaf[4] = M3DNode_NewBone(M3DLWMimosa.m_Plant, "Leaf_06");
		M3DLWMimosa.m_Leaf[5] = M3DNode_NewBone(M3DLWMimosa.m_Plant, "Leaf_07");
		M3DLWMimosa.m_Leaf[6] = M3DNode_NewBone(M3DLWMimosa.m_Plant, "Leaf_10");
		M3DLWMimosa.m_Leaf[7] = M3DNode_NewBone(M3DLWMimosa.m_Plant, "Leaf_11");
		M3DLWMimosa.m_Leaf[8] = M3DNode_NewBone(M3DLWMimosa.m_Plant, "Leaf_12");

		M3DLWMimosa.m_Flower[0] = M3DNode_New(M3DLWMimosa.m_Plant, "FlowerR");
		M3DLWMimosa.m_Flower[1] = M3DNode_New(M3DLWMimosa.m_Plant, "FlowerY01");
		M3DLWMimosa.m_Flower[2] = M3DNode_New(M3DLWMimosa.m_Plant, "FlowerY02");

		M3DLWPage_Changed(&M3DLWMimosa.m_Page, m3d_adaption_get_pageX());
	}

	M3DLWMimosa_CheckFlowerTime();
	M3DModel_AnimateLoop(M3DLWMimosa.m_Flowerpot, M3DLWMimosa.m_ElapsedTime, 0);

	//if (M3DLWMimosa.m_GameTime > (200.0f / 30.0f * 1000.0f))
	if (M3DLWMimosa.m_CameraPod->m_Stop == 1)
	{
		M3DLWMimosa_ProcessChangePage(M3DLWMimosa.m_Page.m_CurrentX);
	}
	else
	{
		M3DModel_AnimateCurrentOnce(M3DLWMimosa.m_CameraPod, M3DLWMimosa.m_ElapsedTime);
		if (M3DLWMimosa.m_CameraPod->m_Stop == 1)
		{
			M3DLWMimosa_ProcessChangePage(M3DLWMimosa.m_Page.m_CurrentX);
		}
	}
	M3DModel_SetActiveCamera(M3DLWMimosa.m_CameraPod);

	M3DModel_AnimateCurrent(M3DLWMimosa.m_Butterfly, M3DLWMimosa.m_ElapsedTime);
	M3DModel_AnimateCurrentLoop(M3DLWMimosa.m_Plant, M3DLWMimosa.m_ElapsedTime, 1);

	for(cn = 0; cn < 9; cn++)
	{
		//M3DNode_AnimateChildsOnce(M3DLWMimosa.m_Leaf[cn], M3DLWMimosa.m_ElapsedTime);
		M3DNode_AnimateOnce(M3DLWMimosa.m_Leaf[cn], M3DLWMimosa.m_ElapsedTime);
	}
	for(cn = 0; cn < 3; cn++)
	{
		M3DNode_AnimateOnce(M3DLWMimosa.m_Flower[cn], M3DLWMimosa.m_ElapsedTime);
	}

	//if (M3DLWMimosa.m_CameraPod->m_Stop == 0)
	//	M3DModel_SetActiveCamera(M3DLWMimosa.m_CameraPod);
	//else
	//{
	//	if (M3DLWMimosa.m_Page.m_CurrentPage == 2)
	//	{
	//		M3DModel_SetAnimationStart(M3DLWMimosa.m_CameraPod, 1);
	//	}
	//}
	//else
	//{
		//M3DRenderer_SetCameraRotation(rr, M3DRotateCenter_UpdatePage(&M3DLWMimosa.m_RotateCamera, M3DLWMimosa.m_ElapsedTime));
		//M3DRenderer_UpdateCameraRotation(rr);
	//}

	M3DRenderer_PrepareRender(&M3DLWMimosa.m_Renderer);

#if defined(IGLW_MIMOSA_REFLECTION)
	M3DModel_SetMaterialOpacity(M3DLWMimosa.m_Flowerpot, 0.5f);
	M3DModel_SetMaterialOpacity(M3DLWMimosa.m_Plant, 0.5f);
	M3DModel_SetMaterialOpacity(M3DLWMimosa.m_Butterfly, 0.5f);
	M3DRenderer_PrepareReflection(&M3DLWMimosa.m_Renderer);
	M3DModel_SetMaterialOpacity(M3DLWMimosa.m_Flowerpot, 1.0f);
	M3DModel_SetMaterialOpacity(M3DLWMimosa.m_Plant, 1.0f);
	M3DModel_SetMaterialOpacity(M3DLWMimosa.m_Butterfly, 1.0f);
#endif

	//M3DModel_Render(M3DLWMimosa.m_Butterfly);
	//M3DModel_Render(M3DLWMimosa.m_Plant);	   //CY end

	//M3DModel_Render(M3DLWMimosa.m_Flowerpot);  //CY begin

	M3DModel_Render(M3DLWMimosa.m_Scene);
	M3DModel_Render(M3DLWMimosa.m_Window);
	
	M3DModel_Render(M3DLWMimosa.m_Flowerpot);
	M3DModel_Render(M3DLWMimosa.m_Butterfly);
	M3DModel_Render(M3DLWMimosa.m_Plant);	

	M3DRenderer_Render(&M3DLWMimosa.m_Renderer);

	/* calculate FPS */
	m3d_time_update_FPS(&M3DLWMimosa.m_adaption, &M3DLWMimosa.m_Renderer.m_EngineRC.m_sPerformanceInfo);
}

void M3DLWMimosa_ProcessTouch(int _mouseX, int _mouseY)
{
	int cn;
	//int index = -1;
	char *node_name = NULL;

	//index = M3DModel_PickNodeIndex(M3DLWMimosa.m_Plant, _mouseX, _mouseY);
	node_name = M3DModel_PickNodeByNamePrefix(M3DLWMimosa.m_Plant, _mouseX, _mouseY, "Leaf");

	if (node_name == NULL)
		return;

	for (cn = 0; cn < 9; cn++)
	{
		if (strcmp(node_name, M3DLWMimosa.m_Leaf[cn]->m_Name) == 0)
		{
			M3DNode_AnimateStart(M3DLWMimosa.m_Leaf[cn], 100.0f*1000.0f/30.0f);
			break;
		}
	}
}

void M3DLWMimosa_ProcessTouch2(int _mouseX, int _mouseY)
{
	int cn;
	int index = -1;
	char *node_name = NULL;

	//index = M3DModel_PickNodeIndex(M3DLWMimosa.m_Plant, _mouseX, _mouseY);
	node_name = M3DModel_PickNodeByNamePrefix(M3DLWMimosa.m_Plant, _mouseX, _mouseY, "Leaf");

	if (node_name == NULL)
		return;

	for (cn = 0; cn < 9; cn++)
	{
		int len = strlen(M3DLWMimosa.m_Leaf[cn]->m_Name);
		if (M3DLWMimosa.m_Leaf[cn]->m_ParentNodeIndex >= 0 && strncmp(node_name, M3DLWMimosa.m_Leaf[cn]->m_Name, len) == 0)
		{
			M3DNode_AnimateStart(M3DLWMimosa.m_Leaf[cn], 8.0f*1000.0f/30.0f);
			break;
		}
	}

	switch (index)
	{
	case 0:
		//M3DModel_SetAnimation(M3DLWMimosa.m_Plant, 3);
		break;
	case 2:
		//M3DModel_SetAnimation(M3DLWMimosa.m_Plant, 3);
		break;
	}
}

void M3DLWMimosa_ProcessChangePage(int _left)
{
	int iPrevPage = M3DLWMimosa.m_Page.m_CurrentPage;
	int iCurrPage = iPrevPage;
	int ds = 0;
	float perc = 0.0f;

	M3DLWPage_Changed(&M3DLWMimosa.m_Page, _left);
	iCurrPage = M3DLWMimosa.m_Page.m_CurrentPage;

	ds = _left - iCurrPage * M3DLWMimosa.m_Page.m_PageWidth;
	perc = (float) ds / (float) M3DLWMimosa.m_Page.m_PageWidth;

	switch (iCurrPage)
	{
	case 0:
		M3DModel_SetAnimationPercent(M3DLWMimosa.m_CameraPod, 4, perc);
		break;
	case 1:
		M3DModel_SetAnimationPercent(M3DLWMimosa.m_CameraPod, 5, perc);
		break;
	case 2:
		M3DModel_SetAnimationPercent(M3DLWMimosa.m_CameraPod, 6, perc);
		break;
	case 3:
		M3DModel_SetAnimationPercent(M3DLWMimosa.m_CameraPod, 7, perc);
		break;
	case 4:
		M3DModel_SetAnimationPercent(M3DLWMimosa.m_CameraPod, 8, perc);
		break;
	}
}

void M3DLWMimosa_ProcessChangePage2(int _left)
{
	int iPrevPage = M3DLWMimosa.m_Page.m_CurrentPage;
	int iCurrPage = iPrevPage;
	M3DLWPage_Changed(&M3DLWMimosa.m_Page, _left);
	iCurrPage = M3DLWMimosa.m_Page.m_CurrentPage;

	if (iPrevPage == 2 && iCurrPage == 1)
	{
		M3DModel_SetAnimationStart(M3DLWMimosa.m_CameraPod, 2);
	}
	if (iPrevPage == 1 && iCurrPage == 0)
	{
		M3DModel_SetAnimationStart(M3DLWMimosa.m_CameraPod, 3);
	}
	if (iPrevPage == 0 && iCurrPage == 1)
	{
		M3DModel_SetAnimationStart(M3DLWMimosa.m_CameraPod, 4);
	}
	if (iPrevPage == 1 && iCurrPage == 2)
	{
		M3DModel_SetAnimationStart(M3DLWMimosa.m_CameraPod, 5);
	}
	if (iPrevPage == 2 && iCurrPage == 3)
	{
		M3DModel_SetAnimationStart(M3DLWMimosa.m_CameraPod, 6);
	}
	if (iPrevPage == 3 && iCurrPage == 4)
	{
		M3DModel_SetAnimationStart(M3DLWMimosa.m_CameraPod, 7);
	}
	if (iPrevPage == 4 && iCurrPage == 3)
	{
		M3DModel_SetAnimationStart(M3DLWMimosa.m_CameraPod, 8);
	}
	if (iPrevPage == 3 && iCurrPage == 2)
	{
		M3DModel_SetAnimationStart(M3DLWMimosa.m_CameraPod, 9);
	}
}


#ifdef __cplusplus
}
#endif

/* end of M3DLWMimosa.c */

