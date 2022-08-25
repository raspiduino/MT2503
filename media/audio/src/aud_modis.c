/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * aud_modis.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file simulates audio behavior in PC platform
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef __MTK_TARGET__
#ifndef MED_NOT_PRESENT

/*==== INCLUDES =========*/

/* system includes */
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "app_buff_alloc.h"     /* Declaration of buffer management API */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */

/* global includes */
#include "l1audio.h"

/* local includes */
#include "med_struct.h"
#include "aud_main.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#include <windows.h>
#include "w32_av_types.h"
#include "w32_av_lib.h"

/*==== DEFINES ===========*/
typedef struct mh_modis_internal
{
    MHdl    mh;
    AudioHandle aud_handle;
} ModisAudHdl;

#define MAX_MODIS_AUDIO_HANDLE 20

/*==== VARIABLES ===========*/
static ModisAudHdl* g_modis_aud_handle[MAX_MODIS_AUDIO_HANDLE];
static kal_uint8 g_modis_aud_handle_count;
static kal_bool g_modis_initialized;


/*==== FUNCTIONS ===========*/

/*****************************************************************************
 * FUNCTION
 *  Aud_Modis_Play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
static Media_Status Aud_Modis_Play( MHdl *hdl )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ModisAudHdl *ahdl = (ModisAudHdl*)hdl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!w32_Audio_Play(ahdl->aud_handle))
    {
        return MEDIA_FAIL;
    }

    return MEDIA_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  Aud_Modis_Stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
static Media_Status Aud_Modis_Stop( MHdl *hdl )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ModisAudHdl *ahdl = (ModisAudHdl*)hdl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w32_Audio_Stop(ahdl->aud_handle);

	return MEDIA_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  Aud_Modis_Pause
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
static Media_Status Aud_Modis_Pause( MHdl *hdl )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ModisAudHdl *ahdl = (ModisAudHdl*)hdl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w32_Audio_Stop(ahdl->aud_handle);

	return MEDIA_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  Aud_Modis_Resume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
static Media_Status Aud_Modis_Resume( MHdl *hdl )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ModisAudHdl *ahdl = (ModisAudHdl*)hdl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!w32_Audio_Play(ahdl->aud_handle))
    {
        return MEDIA_FAIL;
    }

    return MEDIA_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  Aud_Modis_Close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
static Media_Status Aud_Modis_Close( MHdl *hdl )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    ModisAudHdl *ahdl = (ModisAudHdl*)hdl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w32_Audio_CloseFile(ahdl->aud_handle);
    w32_AV_Uninitialize();

    for(i = 0 ; i < MAX_MODIS_AUDIO_HANDLE ; i++)
    {
        if((g_modis_aud_handle[i] != NULL) && (g_modis_aud_handle[i] == ahdl))
        {
            g_modis_aud_handle[i] = NULL;
            g_modis_aud_handle_count--;
            break;
        }
    }

    free_ctrl_buffer(ahdl);
    
	return MEDIA_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  Aud_Modis_SetStartTime
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
static Media_Status Aud_Modis_SetStartTime( MHdl *hdl, kal_uint32 msStartTime )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ModisAudHdl *ahdl = (ModisAudHdl*)hdl;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(w32_Audio_Seek(ahdl->aud_handle, (kal_int64) msStartTime*10000))
    {
    	return MEDIA_SUCCESS;
    }

    return MEDIA_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  Aud_Modis_GetCurrentTime
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
static kal_uint32 Aud_Modis_GetCurrentTime( MHdl *hdl )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int64 position;
    ModisAudHdl *ahdl = (ModisAudHdl*)hdl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(w32_Audio_GetCurrentPosition(ahdl->aud_handle, &position)) /* 100 nanoseconds? */
    {
        return (kal_uint32)(position/10000);
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  Aud_Modis_GetTotalDuration
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
static kal_uint32 Aud_Modis_GetTotalDuration( MHdl *hdl )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int64 duration;
    ModisAudHdl *ahdl = (ModisAudHdl*)hdl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(w32_Audio_GetDuration(ahdl->aud_handle, &duration))
    {
        return (kal_uint32)(duration/10000);
    }

    return 0;
}


static void Aud_Modis_SetBuffer(MHdl *hdl, kal_uint8 *buffer, kal_uint32 buf_len) {}
static void Aud_Modis_SetStoreFlag(MHdl *hdl, kal_bool fStoreLastFileOffset) {}
static void Aud_Modis_StoreFileOffset(MHdl *hdl) {}
static void Aud_Modis_SetFileOffset(MHdl *hdl, kal_uint32 uCurOffset) {}
static kal_uint32 Aud_Modis_GetFileOffset(MHdl *hdl) {return 0;}
static Media_Status Aud_Modis_SetLevel(MHdl *hdl, kal_uint8 level) {return MEDIA_SUCCESS;}
static kal_uint8 Aud_Modis_GetLevel(MHdl *hdl) {return 3;}
static Media_Status Aud_Modis_SetStopTime(MHdl *hdl, kal_uint32 msStopTime) {return MEDIA_SUCCESS;}
static void Aud_Modis_BuildCache(MHdl *hdl, Media_Status *eGetDurLastRet, kal_uint32 *uProgress) {}
static void Aud_Modis_SetCacheTbl(MHdl *hdl, kal_uint8 *ptr, void *param) {}
static kal_uint32 Aud_Modis_GetCacheDuration(MHdl *hdl) {return 0;}


/*****************************************************************************
 * FUNCTION
 *  Aud_Modis_Process
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
static Media_Event Aud_Modis_Process(MHdl *hdl, Media_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(event == MEDIA_END)
    {
        return MEDIA_END;
    }
    
    return MEDIA_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  Aud_Modis_Play_Callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
void Aud_Modis_Play_Callback(AudioHandle handle, w32_Audio_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    MHdl *hdl = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0 ; i < MAX_MODIS_AUDIO_HANDLE ; i++)
    {
        if((g_modis_aud_handle[i]!= NULL) && (g_modis_aud_handle[i]->aud_handle == handle))
        {
            hdl = (MHdl*)g_modis_aud_handle[i];
            break;
        }
    }

    if((hdl != NULL) && (hdl->handler != NULL))
    {
        if(event == w32_AudioEvent_PlaybackFinished)
        {
            hdl->handler(hdl, MEDIA_END);
        }
        else
        {
            hdl->handler(hdl, MEDIA_ERROR);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  Aud_Modis_Set_MHdl_Callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
static void Aud_Modis_Set_MHdl_Callback(MHdl *hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hdl->Play       = Aud_Modis_Play;
    hdl->Stop       = Aud_Modis_Stop;
    hdl->Pause      = Aud_Modis_Pause;
    hdl->Resume     = Aud_Modis_Resume;
    hdl->Close      = Aud_Modis_Close;
    hdl->Process    = Aud_Modis_Process; 

    hdl->SetBuffer          = Aud_Modis_SetBuffer;
    hdl->SetStoreFlag       = Aud_Modis_SetStoreFlag;
    hdl->StoreFileOffset    = Aud_Modis_StoreFileOffset;   
    hdl->SetFileOffset      = Aud_Modis_SetFileOffset;   
    hdl->GetFileOffset      = Aud_Modis_GetFileOffset;       
    
    hdl->SetLevel           = Aud_Modis_SetLevel;
    hdl->GetLevel           = Aud_Modis_GetLevel;
    hdl->SetStartTime       = Aud_Modis_SetStartTime;
    hdl->SetStopTime        = Aud_Modis_SetStopTime;
    hdl->GetCurrentTime     = Aud_Modis_GetCurrentTime;
    hdl->GetTotalDuration   = Aud_Modis_GetTotalDuration;
    hdl->BuildCache         = Aud_Modis_BuildCache;
    hdl->SetCacheTbl        = Aud_Modis_SetCacheTbl;
    hdl->GetCacheDuration   = Aud_Modis_GetCacheDuration;
}


/*****************************************************************************
 * FUNCTION
 *  Aud_Modis_Open_File
 * DESCRIPTION
 *  This function is to simulate audio driver's file function
 *  for all support media in windows
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
MHdl *Aud_Modis_Open_File(void(*handler)(MHdl *handle, Media_Event event), STFSAL *pstFSAL, void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MHdl *hdl;
    ModisAudHdl *ahdl;
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_modis_aud_handle_count >= (MAX_MODIS_AUDIO_HANDLE - 1))
    {
        return NULL;
    }

    /* Initialize */
    if(!g_modis_initialized)
    {
        for(i = 0 ; i < MAX_MODIS_AUDIO_HANDLE ; i++)
        {
            g_modis_aud_handle[i] = NULL;
        }
        g_modis_initialized = KAL_TRUE;
    }

    ahdl = (ModisAudHdl*)get_ctrl_buffer( sizeof(ModisAudHdl));
    memset(ahdl, 0, sizeof(ModisAudHdl));

    hdl = (MHdl*)ahdl;

    hdl->handler   = handler;
    Aud_Modis_Set_MHdl_Callback(hdl);

    w32_AV_Initialize();
    ahdl->aud_handle = w32_Audio_OpenFile((LPCWSTR)param, Aud_Modis_Play_Callback);

    if(ahdl->aud_handle == AudioHandle_Invalid)
    {
        free_ctrl_buffer(ahdl);
        return NULL;
    }

    for(i = 0 ; i < MAX_MODIS_AUDIO_HANDLE ; i++)
    {
        if(g_modis_aud_handle[i] == NULL)
        {
            g_modis_aud_handle[i] = ahdl;
            g_modis_aud_handle_count++;
            break;
        }
    }

    return hdl;
}


/*****************************************************************************
 * FUNCTION
 *  Aud_Modis_Open_String
 * DESCRIPTION
 *  This function is to simulate audio driver's open string function
 *  for all support media in windows
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
MHdl *Aud_Modis_Open_String(void(*handler)(MHdl *handle, Media_Event event), STFSAL *pstFSAL, void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MHdl *hdl;
    ModisAudHdl *ahdl;
    Modis_Aud_Param *maFormat = (Modis_Aud_Param*)param;
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_modis_aud_handle_count >= (MAX_MODIS_AUDIO_HANDLE - 1))
    {
        return NULL;
    }

    /* Initialize */
    if(!g_modis_initialized)
    {
        for(i = 0 ; i < MAX_MODIS_AUDIO_HANDLE ; i++)
        {
            g_modis_aud_handle[i] = NULL;
        }
        g_modis_initialized = KAL_TRUE;
    }

    ahdl = (ModisAudHdl*)get_ctrl_buffer( sizeof(ModisAudHdl));
    memset(ahdl, 0, sizeof(ModisAudHdl));

    hdl = (MHdl*)ahdl;

    hdl->handler   = handler;
    Aud_Modis_Set_MHdl_Callback(hdl);

    w32_AV_Initialize();
    ahdl->aud_handle = w32_Audio_OpenBuffer(maFormat->data, maFormat->size, Aud_Modis_Play_Callback);

    if(ahdl->aud_handle == AudioHandle_Invalid)
    {
        free_ctrl_buffer(ahdl);
        return NULL;
    }

    for(i = 0 ; i < MAX_MODIS_AUDIO_HANDLE ; i++)
    {
        if(g_modis_aud_handle[i] == NULL)
        {
            g_modis_aud_handle[i] = ahdl;
            g_modis_aud_handle_count++;
            break;
        }
    }

    return hdl;
}

#endif /*#ifndef MED_NOT_PRESENT*/
#endif /*#ifndef __MTK_TARGET__*/

