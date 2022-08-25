//==============================================================================
// Copyright (c)2011 InterGrafx, Inc. All rights reserved.
// Project     : M3DLWTransformer
// File        : M3DLWTransformer.c
// Description : IGV5 LW Transformer
// Author      : Ray
// Create      : 2011-06-20
// Update      : 2012-01-11
//==============================================================================

#include "M3DGameDef.h"
#include "M3DLWTransformer.h"
#include "M3DTextureManager.h"
#include "M3DEventQueue.h"

#ifdef __cplusplus
extern "C" {
#endif

M3DLWTransformerApp M3DLWTransformer = {0};
static M3DRenderer *rr = NULL;

//================== Interface Begin =========================
int M3DLWTransformer_OnStartup(void *_pc)
{
	M3DConfig *PC = (M3DConfig *)_pc;
	int ret = 1;

	rr = &M3DLWTransformer.m_Renderer;

	m3d_adaption_init(&M3DLWTransformer.m_adaption, _pc);
	PC->m_pMemBuffer = m3d_alloc_engine_memory(&M3DLWTransformer.m_adaption, PC->m_MemSize);

	ret = M3DRenderer_Init(&M3DLWTransformer.m_Renderer, PC);

	M3DLWTransformer_Init();
	m3d_time_resume(&M3DLWTransformer.m_adaption);

	return ret;
}

void M3DLWTransformer_OnShutdown(void)
{
	M3DLWTransformer_Release();
	M3DRenderer_Del(rr);
	m3d_free_engine_memory(&M3DLWTransformer.m_adaption);
}

void M3DLWTransformer_OnResume(void)
{
	m3d_time_resume(&M3DLWTransformer.m_adaption);
}

void M3DLWTransformer_PostEvent(unsigned long _Id, unsigned long _Time, unsigned long _Data1, unsigned long _Data2)
{
	unsigned long Time = _Time;

	if (M3DLWTransformer.m_GameTime < IGLW_TRANSFORMER_DELAY_TIME)
		return;

	if (Time == 0L)
		Time = (long) M3DLWTransformer.m_GameTime;
	M3DEventQueue_PostEvent(M3DLWTransformer.m_EventMemPool, M3DLWTransformer.m_Event, _Id, Time, _Data1, _Data2);
}

static M3DEvent *pSE = NULL;

void M3DLWTransformer_OnUpdate(int suspend)
{
	static int MouseY = 0;
	M3DLWTransformer.m_ElapsedTime = m3d_time_get_elapsed(&M3DLWTransformer.m_adaption);
	M3DLWTransformer.m_ElapsedTime = (float) (M3DLWTransformer.m_ElapsedTime * M3DLWTransformer.m_TimeFactor);

#if defined(M3D_DEBUG_FRAME)
	//M3DLWTransformer.m_ElapsedTime = 10L;	//for debug
#endif

    if (suspend)
    {
        M3DLWTransformer.m_ElapsedTime = 0L; //real suspend animation and stop IG reference time
    }

	M3DLWTransformer.m_GameTime = M3DLWTransformer.m_GameTime + M3DLWTransformer.m_ElapsedTime;

	while ((pSE = (M3DEvent *) M3DQueue_Pop(M3DLWTransformer.m_Event)) != NULL)
	{
		unsigned mem_used = M3DRenderer_GetUsedMemory(&M3DLWTransformer.m_Renderer);

		//remove all event
		if (M3DLWTransformer.m_GameTime < IGLW_TRANSFORMER_DELAY_TIME)
		{
			M3DEventQueue_Free(M3DLWTransformer.m_EventMemPool, pSE);
			continue;
		}

		switch (pSE->m_uEventID)
		{
		case IGV5EID_BEGINTOUCH :
			M3DRotateCenter_SetTouch(&M3DLWTransformer.m_RotateCamera, 1);
			M3DRotateCenter_SetTouch(&M3DLWTransformer.m_VerticalCamera, 1);
			MouseY = pSE->m_uData2;
			break;
		case IGV5EID_TOUCH :	
			M3DRotateCenter_MoveByPixel(&M3DLWTransformer.m_VerticalCamera, (signed)pSE->m_uData2 - MouseY, -1.0);
			//if (MouseX != 0L)
			//{
			//	if (((signed)pSE->m_uData1 - MouseX) > 0)
			//		M3DRebond_Move(&M3DLWTransformer.m_RebondCamera, 5.0f);
			//	else
			//		M3DRebond_Move(&M3DLWTransformer.m_RebondCamera, -5.0f);
			//}
			MouseY = pSE->m_uData2;
			break;
		case IGV5EID_ENDTOUCH :
			{
				int bTouchMove = M3DRotateCenter_GetTouchMove(&M3DLWTransformer.m_VerticalCamera);
				M3DRotateCenter_SetTouch(&M3DLWTransformer.m_RotateCamera, 0);
				if (bTouchMove == 1 || M3DLWTransformer.m_Page.m_Status == 1)
					M3DLWPage_SetStatus(&M3DLWTransformer.m_Page, 0);
				else
					M3DLWTransformer_ProcessTouch(pSE->m_uData1, pSE->m_uData2);
				M3DRotateCenter_SetTouch(&M3DLWTransformer.m_RotateCamera, 0);
				M3DRotateCenter_SetTouch(&M3DLWTransformer.m_VerticalCamera, 0);
			}
			MouseY = pSE->m_uData2;
			break;
		case  IGV5EID_LWBOUNDSCHANGED :
			M3DLWPage_Changed(&M3DLWTransformer.m_Page, pSE->m_uData1);
			break;
		}

		M3DEventQueue_Free(M3DLWTransformer.m_EventMemPool, pSE);
	}

	if (M3DLWTransformer.m_GameTime > IGLW_2D_DELAY_TIME && M3DLWTransformer.m_Scene->m_bLoaded == 0)
		M3DLWTransformer_Init2();

	if (M3DLWTransformer.m_GameTime <= IGLW_2D_DELAY_TIME)
		M3DRenderer_Render2D(&M3DLWTransformer.m_Renderer, "bg2d.pvr");
	else
  	M3DLWTransformer_Update();
}

//================== Interface End ===========================

int M3DLWTransformer_Init(void)
{
	M3DLWTransformer.m_Scene = M3DModel_New(&M3DLWTransformer.m_Renderer, "scene");
	M3DLWTransformer.m_Transformer = M3DModel_New(&M3DLWTransformer.m_Renderer, "transformer");
	
	//M3DRotateSimple_InitRandom(&M3DLWTransformer.m_RotScene, 0.3f);
	
	M3DLWTransformer.m_SceneTextureNames       = NULL;
	M3DLWTransformer.m_TransformerTextureNames = NULL;

	M3DLWTransformer_LoadBackground2D();

	M3DLWTransformer.m_EventMemPool = M3DEventQueue_New(MAX_ARRAY_POOL);
	M3DLWTransformer.m_Event = M3DQueue_New(DEFAULT_QUEUE_SIZE);
	M3DLWTransformer.m_TimeFactor = 1.0f;
	M3DLWTransformer.m_GameTime = 0.0f;
	M3DLWTransformer.m_LightTime = 0.0f;
	
	return 1;
}

int M3DLWTransformer_Init2(void)
{
	M3DLWTransformer_RemoveBackground2D();
	
	M3DLWTransformer_LoadContent();
	M3DLWTransformer_LoadContent2();

	M3DRotateCenter_Init2(&M3DLWTransformer.m_VerticalCamera, -70.0f, 20.0f);
	M3DRotateCenter_InitPager(&M3DLWTransformer.m_RotateCamera, &M3DLWTransformer.m_Page, -50.0f, 50.0f);

	M3DModel_SetActiveCamera(M3DLWTransformer.m_Transformer);
	M3DModel_SetActiveLight(M3DLWTransformer.m_Scene);
	

	M3DRenderer_SetAlphaTestCmpValue(&M3DLWTransformer.m_Renderer, 0.01f);
	M3DRenderer_Shader_SetAlphaThreshold(&M3DLWTransformer.m_Renderer, M3D_GOURAUD_SHADER, 0.01f);
	M3DLWPage_Init(&M3DLWTransformer.m_Page, M3DLWTransformer.m_Renderer.m_EngineRC.m_sEGLInfo.m_uWidth, 5);

//#if defined(M3D_ENABLE_SHADOW)
	M3DModel_SetReflection(M3DLWTransformer.m_Transformer);
	M3DModel_InitReflector(M3DLWTransformer.m_Scene, "Sphere01", 0.5f);
//#endif
	M3DLWPage_Changed(&M3DLWTransformer.m_Page, m3d_adaption_get_pageX());

	return 1;
}

void M3DLWTransformer_Release(void)
{
	M3DEventQueue_ClearPendingEvents(M3DLWTransformer.m_EventMemPool, M3DLWTransformer.m_Event);
	M3DEventQueue_Del(M3DLWTransformer.m_EventMemPool);
	M3DLWTransformer.m_EventMemPool = NULL;
	M3DQueue_Del(M3DLWTransformer.m_Event);
	M3DLWTransformer.m_Event = NULL;
	M3DLWTransformer.m_GameTime = 0.0f;

#if defined(M3D_ENABLE_SHADOW)
	M3DRenderer_ReleaseReflection(&M3DLWTransformer.m_Renderer);
#endif

	M3DSplitString_Del(M3DLWTransformer.m_TransformerTextureNames);
	M3DSplitString_Del(M3DLWTransformer.m_SceneTextureNames);

	M3DModel_Del(M3DLWTransformer.m_Transformer);
	M3DModel_Del(M3DLWTransformer.m_Scene);
}

void M3DLWTransformer_EnableObjects(void)
{
	float frame = M3DModel_GetCurrentFrame(M3DLWTransformer.m_Transformer);

	if ((frame >= 0.0f && frame < 2.0f) || (frame > 13.0f && frame < 658.0f))
	{
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "light_r", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "light_l", 0);
	}
	else
	{
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "light_r", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "light_l", 1);
	}

	//RAY::2011-10-11 要加上這個判斷, 這樣在預設動作的時候才不會一直出現破綻
	if (M3DLWTransformer.m_Transformer->m_iCurrentAnimation == 0)
		return;

	if (frame > 53.0f && frame < 632)
	{
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object39", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object38", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object53", 0);
		
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Box01", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Box02", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Box03", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Box04", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Box05", 1);		
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Box10", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Box11", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Box12", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Box13", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Box14", 1);		
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object01", 1);	
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object02", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object03", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object04", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object05", 1);	
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object06", 1);	
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object09", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object10", 1);		
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object12", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object13", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object14", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object15", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object16", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object17", 1);		
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object19", 1);	
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object22", 1);	
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object24", 1);	
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object26", 1);	
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object27", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object28", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object29", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object30", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object31", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object77", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object78", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object79", 1);		
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object80", 1);		
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object81", 1);		
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object255", 1);			
	}
	else
	{
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object39", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object38", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object53", 1);
		
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Box01", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Box02", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Box03", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Box04", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Box05", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Box10", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Box11", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Box12", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Box13", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Box14", 0);		
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object01", 0);	
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object02", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object03", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object04", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object05", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object06", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object09", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object10", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object12", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object13", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object14", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object15", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object16", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object17", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object19", 0);	
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object22", 0);	
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object24", 0);	
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object26", 0);	
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object27", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object28", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object29", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object30", 0);		
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object31", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object77", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object78", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object79", 0);	
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object80", 0);		
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object81", 0);		
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object255", 0);			
	}
	if (frame > 63.0f && frame < 612)
	{
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object40", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object70", 0);
	}
	else
	{
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object40", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object70", 1);
	}
	if (frame > 66.0f && frame < 632)
	{
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object25", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object41", 0);
	}
	else
	{
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object25", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object41", 1);
	}
	if (frame > 73.0f && frame < 630)
	{
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object52", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Group01",  0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object49",  0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object48",  0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object42",  0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object43",  0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object44",  0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object50",  0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object25",  0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object41",  0);
	}
	else
	{
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object52", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Group01",  1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object49",  1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object48",  1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object42",  1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object43",  1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object44",  1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object50",  1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object25",  1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object41",  1);
	}
	if (frame > 75.0f && frame < 632)
	{
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object83", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object36", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object56", 0);
	}
	else
	{
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object83", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object36", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object56", 1);
	}
	if (frame > 78.0f && frame < 632)
	{
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object47", 0);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Box06", 0);
	}
	else
	{
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Object47", 1);
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Box06", 1);
	}
	if (frame > 53.0f && frame < 632.0f)
	{
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Box08", 0);
	}
	else
	{
		M3DModel_EnableNode(M3DLWTransformer.m_Transformer, "Box08", 1);
	}
}

void M3DLWTransformer_CheckLightTime(void)
{
	int rnd = m3d_adaption_rand() % 2;

	if ((M3DLWTransformer.m_GameTime - M3DLWTransformer.m_LightTime) > 5000.0f && M3DModel_IsDefaultAnimation(M3DLWTransformer.m_Transformer) == 1)
	{
		switch (M3DLWTransformer.m_Transformer->m_iCurrentAnimation)
		{
		case 0:
			M3DModel_SetDefaultAnimation(M3DLWTransformer.m_Transformer, 2, 1.0f);
			if (rnd == 0)
				M3DModel_SetAnimationStart(M3DLWTransformer.m_Transformer, 1);
			else
				M3DModel_SetAnimationStart(M3DLWTransformer.m_Transformer, 4);
			M3DLWTransformer.m_LightTime = M3DLWTransformer.m_GameTime;
			break;
		case 2:
			M3DModel_SetDefaultAnimation(M3DLWTransformer.m_Transformer, 0, 1.0f);
			M3DModel_SetAnimationStart(M3DLWTransformer.m_Transformer, 3);
			M3DLWTransformer.m_LightTime = M3DLWTransformer.m_GameTime;
			break;
		}
	}
}

void M3DLWTransformer_Update(void)
{
	/* 攝影機在 m_Transformer , 所以必須先載入
	if (M3DLWTransformer.m_Transformer->m_bLoaded == 0 && M3DLWTransformer.m_GameTime > IGLW_TRANSFORMER_DELAY_TIME)
	{
		M3DLWTransformer_LoadContent2();
	}
	*/

	//M3DModel_AnimateLoop(M3DLWTransformer.m_Scene, M3DLWTransformer.m_ElapsedTime, 0);
	if (M3DModel_IsDefaultAnimation(M3DLWTransformer.m_Transformer) == 1)
	{
		M3DModel_AnimateCurrentLoop(M3DLWTransformer.m_Transformer, M3DLWTransformer.m_ElapsedTime, 0);
		if (M3DLWTransformer.m_Transformer->m_iCurrentAnimation == 6)
		{
			int rnd = m3d_adaption_rand() % 100;
			if (rnd == 0)
				M3DModel_SetAnimationStart(M3DLWTransformer.m_Transformer, 7);	//Fire
		}
	}
	else
	{
		M3DModel_AnimateCurrentOnce(M3DLWTransformer.m_Transformer, M3DLWTransformer.m_ElapsedTime);
		if (M3DLWTransformer.m_Transformer->m_Stop == 1)
			M3DLWTransformer.m_Transformer->m_iCurrentAnimation = M3DLWTransformer.m_Transformer->m_iDefaultAnimation;
	}

	M3DLWTransformer_EnableObjects();
	M3DLWTransformer_CheckLightTime();

	//M3DModel_SetActiveCamera(M3DLWTransformer.m_Transformer);
	M3DRenderer_SetCameraRotation(rr, M3DRotateCenter_Update(&M3DLWTransformer.m_VerticalCamera, M3DLWTransformer.m_ElapsedTime));
	M3DRenderer_UpdateVerticalCameraRotation(rr);
	M3DRenderer_SetCameraRotation(rr, M3DRotateCenter_UpdatePageX(&M3DLWTransformer.m_RotateCamera, M3DLWTransformer.m_ElapsedTime));
	M3DRenderer_UpdateCameraRotation(rr);
	
	//M3DModel_SetNodeYRotation(M3DLWTransformer.m_Scene, "Sphere01", M3DRotateSimple_Update(&M3DLWTransformer.m_RotScene, M3DLWTransformer.m_ElapsedTime * 0.1f));

	M3DRenderer_PrepareRender(&M3DLWTransformer.m_Renderer);
//#if defined(M3D_ENABLE_SHADOW)
	M3DRenderer_PrepareReflection(&M3DLWTransformer.m_Renderer);
//#endif
  M3DRenderer_SetAlphaTestCmpValue(&M3DLWTransformer.m_Renderer, 0.01f);
	M3DModel_Render(M3DLWTransformer.m_Scene);
	M3DModel_Render(M3DLWTransformer.m_Transformer);
	M3DRenderer_Render(&M3DLWTransformer.m_Renderer);
	/* calculate FPS */
	m3d_time_update_FPS(&M3DLWTransformer.m_adaption, &M3DLWTransformer.m_Renderer.m_EngineRC.m_sPerformanceInfo);
}

void M3DLWTransformer_ProcessTouch(int _mouseX, int _mouseY)
{
	int rnd = m3d_adaption_rand() % 3;
	int bIsMoving = M3DRotateCenter_IsMoving(&M3DLWTransformer.m_RotateCamera);
	int index = -1;

	//if (bIsMoving == 1)
	//	return;

	index = M3DModel_PickNodeIndex(M3DLWTransformer.m_Transformer, _mouseX, _mouseY);
	if (index < 0)
		return;

	if (M3DModel_IsDefaultAnimation(M3DLWTransformer.m_Transformer) == 0)
		return;


	switch (M3DLWTransformer.m_Transformer->m_iCurrentAnimation)
	{
	case 0:
	case 1:
	case 2:
	case 3:		
		if (rnd == 0)
		{
			M3DModel_SetDefaultAnimation(M3DLWTransformer.m_Transformer, 0, 1.0f);
			M3DModel_SetAnimationStart(M3DLWTransformer.m_Transformer, 9);
		}
		else
		{
			M3DModel_SetDefaultAnimation(M3DLWTransformer.m_Transformer, 6, 1.0f);
			M3DModel_SetAnimationStart(M3DLWTransformer.m_Transformer, 5);
			M3DLWTransformer.m_Status = 1;
		}
		break;
	case 6:
		M3DModel_SetDefaultAnimation(M3DLWTransformer.m_Transformer, 0, 1.0f);
		M3DModel_SetAnimationStart(M3DLWTransformer.m_Transformer, 8);
		M3DLWTransformer.m_Status = 0;
		break;
	}
}

#ifdef __cplusplus
}
#endif

/* end of M3DLWTransformer.c */

