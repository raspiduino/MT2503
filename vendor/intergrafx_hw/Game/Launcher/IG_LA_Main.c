/*
    Launcher.c 

      - This program demonstrate user controllable coverflow effect. it's RAW sample - showing how to do it almost by yourself.


    [Author]
        IG Team

      
    [History] 
        2010/04/11 - preparation of porting 
        2010/03/29 - first version 

    [Copyright]
        InterGrafx Inc, 2001-2011
*/


#include "IGV5Game.h"
#include "IGV5Shader.h"
#include "IGV5Matrix.h"
#include "IGV5Texture.h"
#include "IGV5Renderer.h"
#include "IGV5Camera.h"
#include "IGV5LoadPODModel.h"
#include "IG_LA_Function.h"
#include "IG_LA_Var.h"
#include "IG_LA_Define.h"
#include "IG_LA_LA.h"
#include "IG_LA_CW.h"
#include "IG_LA_DA5.h"
#include "IG_LA_TK.h"
#include "IG_LA_JE.h"

#ifdef IGV5_MTK_PHONE

#include "ig3d_adaptation56.h"
#endif


#ifdef __cplusplus
extern "C" {
#endif

/* Source and binary shaders */


//static IGV5Camera g_Camera;

IGV5PODModel g_World;

IGV5Err IGV5Game_Startup(IGV5InitInfoVer0101 *pOverride)
{
#ifndef IGV5_MTK_PHONE
    pOverride->m_EGL.m_uHeight = IG_Launcher_High;
    pOverride->m_EGL.m_uWidth = IG_Launcher_Width;
    pOverride->m_pPoolPtr = NULL;   /* let IGV5 Startup program or platform to supply memory buffer */
    pOverride->uSize = 32*1024*1024;
#endif
    return IGV5ERR_NONE;
}

IGV5Err IGV5Game_LoadContent(IGV5RC *pThisRC)
{

#ifdef IGV5_MTK_PHONE  

    IG_FS_HANDLE handle;
    int ret;
	//unsigned char readbuf[10];

#endif
#ifdef IGV5_MTK_PHONE
    IG_LA_UnloadFlag=0;
    handle = IGFS_Open((kal_uint16*)L"Z:\\@ig_save\\", FS_READ_ONLY | FS_OPEN_DIR);  //開啟目?看看成不成功
    if (handle >= FS_NO_ERROR)
    {
        FS_Close(handle);   // 成功，後面就可以去讀?資料檔
    }
    else
    {
        ret = FS_CreateDir((kal_uint16*)L"Z:\\@ig_save\\");  //不成功，自己建一?目?！
        if (ret < 0)
        {
			return IGV5ERR_FAIL;
        }        
    }

#endif
    IG_LA_Status = IG_LA_H_LAUNCHER;
    IG_LA_Launcher_Init(pThisRC);


    /* Initialize camera */

    //IGV5Camera_Create(&g_Camera, eCameraType_Perspective);

    return IGV5ERR_NONE;
}



void IGV5Game_Update(IGV5RC *pThisRC, float fFrameTime,unsigned uNumEvents, IGV5Event *pEventsArray)
{

    switch(IG_LA_Status){
        //case IG_OnPhoneCall:
        //    IG_LA_OnPhoneCall_onUpdate(uFrameInterval, uNumSysEvents, pSE);
        //    break;
        case IG_LA_H_LAUNCHER:
             IG_LA_Launcher_Update(pThisRC,fFrameTime,uNumEvents,pEventsArray);
            break;
#if _IG_TK_
        case IG_LA_H_TK:
#if !_LA_DEBUG_
            
            IG_LA_Tank_Update(pThisRC,fFrameTime,uNumEvents,pEventsArray);
            break;
#endif
#endif
#if _IG_DA5_
        case IG_LA_H_DA5:
#if !_LA_DEBUG_
            
            IG_LA_DA5_Update(pThisRC,fFrameTime,uNumEvents,pEventsArray);
            break;
#endif
#endif
#if _IG_JE_
        case IG_LA_H_JE:
#if !_LA_DEBUG_
        
            IG_LA_JE_Update(pThisRC,fFrameTime,uNumEvents,pEventsArray);
            break;
#endif
#endif
#if _IG_CW_
        case IG_LA_H_CW:
#if !_LA_DEBUG_
        
            IG_LA_CW_Update(pThisRC,fFrameTime,uNumEvents,pEventsArray);
            break;
#endif
#endif
        default:
            break;
    }

    /* calculate FPS */
    //IGV5Time_UpdateFPS(&pThisRC->m_sPerformanceInfo);
}

void IGV5Game_Unload(IGV5RC *pThisRC)
{
    if(IG_LA_UnloadFlag==0)
    {
        IG_LA_Launcher_Unload();
#if _IG_CW_
#if !_LA_DEBUG_
    if(IG_LA_Status==IG_LA_H_CW)
    {
        IG_LA_CW_Unload(pThisRC);
    }
#endif
#endif
#if _IG_DA5_
#if !_LA_DEBUG_
    if(IG_LA_Status==IG_LA_H_DA5)
    {
        IG_LA_DA5_Unload(pThisRC);
    }
#endif
#endif
#if _IG_JE_
#if !_LA_DEBUG_
    if(IG_LA_Status==IG_LA_H_JE)
    {
        IG_LA_JE_Unload(pThisRC);
    }
#endif
#endif
#if _IG_TK_
#if !_LA_DEBUG_
    if(IG_LA_Status==IG_LA_H_TK)
    {
        IG_LA_Tank_Unload(pThisRC);
    }
#endif
#endif
    }

}    

void IGV5Game_Shutdown(void)
{

}
void IGV5Game_Resume()
{
#if _IG_DA5_
#if !_LA_DEBUG_
    if(IG_LA_Status==IG_LA_H_DA5)
    {
        IG_LA_DA5_Resume();
    }
#endif
#endif
#if _IG_CW_
#if !_LA_DEBUG_
    if(IG_LA_Status==IG_LA_H_CW)
    {
        IG_LA_CW_Resume();
    }
#endif
#endif
#if _IG_JE_
#if !_LA_DEBUG_
    if(IG_LA_Status==IG_LA_H_JE)
    {
        IG_LA_JE_Resume();
    }
#endif
#endif
#if _IG_TK_
#if !_LA_DEBUG_
    if(IG_LA_Status==IG_LA_H_TK)
    {
        IG_LA_TK_Resume();
    }
#endif
#endif
}
void IGV5Game_Suspend()
{
#if _IG_DA5_
#if !_LA_DEBUG_
    if(IG_LA_Status==IG_LA_H_DA5)
    {
        IG_LA_DA5_Suspend();
    }
#endif
#endif
#if _IG_CW_
#if !_LA_DEBUG_
    if(IG_LA_Status==IG_LA_H_CW)
    {
        IG_LA_CW_Suspend();
    }
#endif
#endif
#if _IG_JE_
#if !_LA_DEBUG_
    if(IG_LA_Status==IG_LA_H_JE)
    {
        IG_LA_JE_Suspend();
    }
#endif
#endif
#if _IG_TK_
#if !_LA_DEBUG_
    if(IG_LA_Status==IG_LA_H_TK)
    {
        IG_LA_TK_Suspend();
    }
#endif
#endif
	if(IG_LA_Status==IG_LA_H_LAUNCHER)
    {
        IG_LA_LA_Suspend();
    }
}
    

#ifdef __cplusplus
}
#endif

/* end of IGV5Game.c */

