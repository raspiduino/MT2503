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
 * aud_player_modis.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary functions of MoDIS player.
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
 *
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

/******************************************************************
 * MODULE
 *    MoDIS Player
 * DESCRIPTION
 *    This module defines related function of MoDIS Player.
 *  
 ******************************************************************/

#ifndef MED_NOT_PRESENT

/*-----------------------------------------------------------------------------
                    include files
-----------------------------------------------------------------------------*/
/* system includes */
//#include "kal_release.h"
#include "kal_trace.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
//#include "stack_common.h"
//#include "stack_msgs.h"
//#include "app_ltlcom.h"     /* Task message communiction */
//#include "syscomp_config.h"
//#include "task_config.h"    /* Task creation */
//#include "app_buff_alloc.h" /* Declaration of buffer management API */
//#include "stacklib.h"       /* Basic type for dll, evshed, stacktimer */
//#include "event_shed.h"     /* Event scheduler */
//#include "stack_timer.h"    /* Stack timer */
    
/* global includes */
//#include "l1audio.h"
    
/* local includes */
#include "med_global.h"
#include "med_main.h"
#include "med_utility.h"
#include "aud_player.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif

#if !defined(__MTK_TARGET__)

/* win32 */
#include <windows.h>
#include "w32_av_types.h"
#include "w32_av_lib.h"

/*-----------------------------------------------------------------------------
                    macros, defines, typedefs, enums
-----------------------------------------------------------------------------*/
#define _AUD_PLAYER_MODIS_TRACE(x, y, z)   AUD_PLAYER_MODIS_TRACE(x, y, z, __LINE__)
#define MAX_MODIS_AUDIO_HANDLE             (10)

/* MoDIS Player */
typedef struct
{
    med_aud_player_t              itf;            /* Player interfaces */
    kal_uint32                    time_stamp;     /* Time stamp of the constructed player */
    AudioHandle                   aud_handle;     /* Audio handle */
    kal_uint8                     state;          /* Player state */
    kal_uint32                    start_time;     /* Start time */
    med_aud_player_cb_fct         cb_fct;         /* Callback when there is event arisen */
    void*                         cb_param;       /* Callback parameter */
} med_aud_player_modis_t;

/* MoDIS Event */
typedef struct
{
    AudioHandle                   handle;         /* Player handle */
    w32_Audio_Event               event;          /* Event */
    kal_uint32                    time_stamp;     /* Time stamp of the callback event */
} med_aud_player_modis_event_t;

typedef struct
{
    med_aud_player_t*             player_p;       /* Player handle */
    AudioHandle                   aud_handle;     /* Audio handle */
    kal_bool                      is_used;        /* Indicate if the slot is used */
} med_aud_player_modis_handle_t;

/*-----------------------------------------------------------------------------
                    data declaraions
 ----------------------------------------------------------------------------*/
static med_aud_player_modis_handle_t g_player_handle[MAX_MODIS_AUDIO_HANDLE] = { 0 };
static kal_uint8 g_player_count = 0;

/*-----------------------------------------------------------------------------
                    function prototypes
 ----------------------------------------------------------------------------*/ 

/*-----------------------------------------------------------------------------
                    private function declarations
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  _aud_player_modis_store_player_handle
 * DESCRIPTION
 *  This function is used store a player handle for a given audio handle.
 * PARAMETERS
 *  player_p       [IN]        Player handle. 
 *  aud_handle     [IN]        Audio handle.
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_player_modis_store_player_handle(med_aud_player_t* player_p, AudioHandle aud_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Put the paired handles to an empty slot */
    for (i = 0; i < MAX_MODIS_AUDIO_HANDLE; i ++)
    {
        if (g_player_handle[i].is_used == KAL_FALSE)
        {
            g_player_handle[i].player_p = player_p;
            g_player_handle[i].aud_handle = aud_handle;
            g_player_handle[i].is_used = KAL_TRUE;
            
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  _aud_player_modis_delete_player_handle
 * DESCRIPTION
 *  This function is used delete the player handle for a given audio handle.
 * PARAMETERS
 *  player_p       [IN]      Player handle. 
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_player_modis_delete_player_handle(AudioHandle aud_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Delete player handle per the given player handle */
    for (i = 0; i < MAX_MODIS_AUDIO_HANDLE; i ++)
    {
        if (g_player_handle[i].is_used &&
            g_player_handle[i].aud_handle == aud_handle)
        {
            g_player_handle[i].player_p = NULL;
            g_player_handle[i].aud_handle = AudioHandle_Invalid;
            g_player_handle[i].is_used = KAL_FALSE;
            
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  _aud_player_modis_get_player_handle
 * DESCRIPTION
 *  This function is used get the player handle for a given audio handle.
 * PARAMETERS
 *  aud_handle       [IN]      Audio handle. 
 * RETURNS
 *  void
 *****************************************************************************/
static med_aud_player_t* _aud_player_modis_get_player_handle(AudioHandle aud_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Get player handle for the given audio handle */
    for (i = 0; i < MAX_MODIS_AUDIO_HANDLE; i ++)
    {
        if (g_player_handle[i].is_used &&
            g_player_handle[i].aud_handle == aud_handle)
        {
            return g_player_handle[i].player_p;
        }
    }
    
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  _aud_player_modis_event_callback_hdlr
 * DESCRIPTION
 *  This function is used to handle the callback events from AV Library.
 * PARAMETERS
 *  data_p             [IN]       Media event data.
 *  date_len           [IN]       The length of data.
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_player_modis_event_callback_hdlr(void* data_p, kal_uint16 date_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_t* player_p;
    med_aud_player_modis_t* self_p;
    med_aud_player_modis_event_t* modis_event_p = (med_aud_player_modis_event_t*)data_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(modis_event_p->handle != AudioHandle_Invalid);
    
    _AUD_PLAYER_MODIS_TRACE(modis_event_p->handle, modis_event_p->event, -1);
    
    /* Get player handle */
    player_p = _aud_player_modis_get_player_handle(modis_event_p->handle);
    MED_ASSERT(player_p != NULL);

    self_p = PTHIS(player_p, med_aud_player_modis_t, itf);

    /* Validate event */
    if (self_p->state != AUD_MEDIA_PLAY ||
        self_p->aud_handle != modis_event_p->handle ||
        self_p->time_stamp != modis_event_p->time_stamp)
    {
        _AUD_PLAYER_MODIS_TRACE(self_p->state, self_p->aud_handle , self_p->time_stamp);
        return;
    }

    /* Callback client */
    if (self_p->cb_fct)
    {    
        switch (modis_event_p->event)
        {
            case w32_AudioEvent_PlaybackFinished:
                self_p->cb_fct(player_p, MEDIA_END, self_p->cb_param);
                break;
            default:
                self_p->cb_fct(player_p, MEDIA_ERROR, self_p->cb_param);
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  _aud_player_modis_event_callback_fct
 * DESCRIPTION
 *  This function is used to receive the callback events from L1Audio.
 * PARAMETERS
 *  handle         [IN]        Audio handle. 
 *  event          [IN]        Audio event.
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_player_modis_event_callback_fct(AudioHandle handle, w32_Audio_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_t* player_p;
    med_aud_player_modis_t* self_p;
    med_aud_player_modis_event_t modis_event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(handle != AudioHandle_Invalid);

    /* Get player handle */
    player_p = _aud_player_modis_get_player_handle(handle);
    MED_ASSERT(player_p != NULL);

    self_p = PTHIS(player_p, med_aud_player_modis_t, itf);
    
    modis_event.handle = handle;
    modis_event.event = event;
    modis_event.time_stamp = self_p->time_stamp;

    aud_util_proc_in_med_ext(kal_get_active_module_id(),
                             _aud_player_modis_event_callback_hdlr,
                             (void*)&modis_event,
                             sizeof(med_aud_player_modis_event_t));
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_modis_close
 * DESCRIPTION
 *  This function is used to close a MoDIS player.
 * PARAMETERS
 *  player_p      [IN]        Player handle.              
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_modis_close(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_modis_t* self_p;
    kal_bool                b_success = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_modis_t, itf);

    /* Free player resources */
    if (self_p->aud_handle != AudioHandle_Invalid)
    {
        /* Close MoDIS player */
        b_success = w32_Audio_CloseFile(self_p->aud_handle);
        _AUD_PLAYER_MODIS_TRACE(b_success, self_p->aud_handle, -1);

        /* Delete player handler */
        _aud_player_modis_delete_player_handle(self_p->aud_handle);

        self_p->aud_handle = AudioHandle_Invalid;
        
        /* Decrease player count */
        g_player_count --;
    }
    
    /* Deinitialize AV when there is no MoDIS player */
    if (g_player_count == 0)
    {
        w32_AV_Uninitialize();
    }

    return (b_success) ? MED_RES_OK : MED_RES_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_modis_open
 * DESCRIPTION
 *  This function is used to open a MoDIS player.
 * PARAMETERS
 *  player_p      [IN]        Player handle.
 *  cfg_p         [IN]        Player configuration.  
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_modis_open(med_aud_player_t* player_p, med_aud_player_cfg_t* cfg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_modis_t* self_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_modis_t, itf);

    /* Initialize */
    if (g_player_count == 0)
    {
        /* Initalize AV */
        w32_AV_Initialize();
    }
    
    /* Open from file */
    if (cfg_p->file_name != NULL)
    {
        self_p->aud_handle = w32_Audio_OpenFile((LPCWSTR)cfg_p->file_name, _aud_player_modis_event_callback_fct);
        _AUD_PLAYER_MODIS_TRACE(self_p->aud_handle, g_player_count, -1);
        
        if (self_p->aud_handle == AudioHandle_Invalid)
        {
            return MED_RES_FAIL;
        }
    }
    /* Open from buffer */
    else if (cfg_p->data_p != NULL)
    {
        self_p->aud_handle = w32_Audio_OpenBuffer((const char*)cfg_p->data_p,
                                                  (int)cfg_p->data_len,
                                                  _aud_player_modis_event_callback_fct);
        _AUD_PLAYER_MODIS_TRACE(self_p->aud_handle, g_player_count, -1);
        
        if (self_p->aud_handle == AudioHandle_Invalid)
        {
            return MED_RES_FAIL;
        }
    }
    else
    {
        self_p->aud_handle = AudioHandle_Invalid;
        return MED_RES_FAIL;
    }

    /* Increase player count */
    g_player_count ++;
    
    /* Check if reach maximum player count */
    if (g_player_count > MAX_MODIS_AUDIO_HANDLE)
    {
        return MED_RES_FAIL;
    }
    
    /* Store paried player handle and audio handle */
    _aud_player_modis_store_player_handle(player_p, self_p->aud_handle);
    
    /*------------------------ Setup private data ---------------------------*/
    self_p->state      = AUD_MEDIA_IDLE;
    self_p->start_time = 0;
    self_p->cb_fct     = cfg_p->cb_fct;
    self_p->cb_param   = cfg_p->cb_param;
    
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_modis_play
 * DESCRIPTION
 *  This function is used to start MoDIS playback.
 * PARAMETERS
 *  player_p      [IN]        Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_modis_play(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_modis_t* self_p;
    kal_bool                b_success;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_modis_t, itf);
    MED_ASSERT(self_p->aud_handle != AudioHandle_Invalid);

    /* Directly return if the player is not in idle state */
    if (self_p->state != AUD_MEDIA_IDLE)
    {
        return MED_RES_FAIL;
    }

    b_success = w32_Audio_Play(self_p->aud_handle);
    _AUD_PLAYER_MODIS_TRACE(b_success, self_p->aud_handle, -1);

    if (b_success)
    {
        self_p->state = AUD_MEDIA_PLAY;
    }
    
    return (b_success) ? MED_RES_OK : MED_RES_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_modis_stop
 * DESCRIPTION
 *  This function is used to stop MoDIS playback.
 * PARAMETERS
 *  player_p      [IN]        Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_modis_stop(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_modis_t* self_p;
    kal_bool                b_success;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_modis_t, itf);
    MED_ASSERT(self_p->aud_handle != AudioHandle_Invalid);

    b_success = w32_Audio_Stop(self_p->aud_handle);
    _AUD_PLAYER_MODIS_TRACE(b_success, self_p->aud_handle, -1);

    if (b_success)
    {
        /* Seek to the beginning */
        b_success = w32_Audio_Seek(self_p->aud_handle, 0);
        _AUD_PLAYER_MODIS_TRACE(b_success, self_p->aud_handle, -1);
        
        self_p->state = AUD_MEDIA_IDLE;
    }
    
    return (b_success) ? MED_RES_OK : MED_RES_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_modis_pause
 * DESCRIPTION
 *  This function is used to pause MoDIS playback.
 * PARAMETERS
 *  player_p      [IN]        Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_modis_pause(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_modis_t* self_p;
    kal_int64               position;
    kal_bool                b_success;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_modis_t, itf);
    MED_ASSERT(self_p->aud_handle != AudioHandle_Invalid);

    /* Get current time */
    b_success = w32_Audio_GetCurrentPosition(self_p->aud_handle, &position);

    if (b_success)
    {
        self_p->state = AUD_MEDIA_PLAY_PAUSED;
    }

    /* Stop the play */
    b_success = w32_Audio_Stop(self_p->aud_handle);
    _AUD_PLAYER_MODIS_TRACE(b_success, self_p->aud_handle, -1);
    
    return (b_success) ? MED_RES_OK : MED_RES_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_modis_resume
 * DESCRIPTION
 *  This function is used to resume MoDIS playback.
 * PARAMETERS
 *  player_p      [IN]        Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_modis_resume(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_modis_t* self_p;
    kal_bool                b_success;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_modis_t, itf);
    MED_ASSERT(self_p->aud_handle != AudioHandle_Invalid);
    
    /* Start the play. The player will auto resume from last stopped
     * position. I.e. no seeking is requried.
     */
    b_success = w32_Audio_Play(self_p->aud_handle);
    _AUD_PLAYER_MODIS_TRACE(b_success, self_p->aud_handle, -1);

    if (b_success)
    {
        self_p->state = AUD_MEDIA_PLAY;
    }
    
    return (b_success) ? MED_RES_OK : MED_RES_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_modis_set
 * DESCRIPTION
 *  This function is used to set parameters to an MoDIS player.
 * PARAMETERS
 *  player_p      [IN]        Player handle.
 *  set_type      [IN]        Set command.
 *  data_p        [IN]        The data relative to the command.
 *  date_len      [IN]        The length of the data.
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_modis_set(med_aud_player_t*    player_p,
                                       med_aud_player_set_t set_type,
                                       void*                data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_modis_t* self_p;
    kal_bool                b_success;
    kal_int32               result = MED_RES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_modis_t, itf);
    MED_ASSERT(self_p->aud_handle != AudioHandle_Invalid);

    _AUD_PLAYER_MODIS_TRACE(set_type, (kal_uint32)data_p, -1);
    
    switch (set_type)
    {
        case AUD_PLAYER_SET_START_TIME:
        {
            kal_uint32 start_time = (kal_uint32)data_p;
            
            b_success = w32_Audio_Seek(self_p->aud_handle, (kal_int64)start_time * 10000);
            _AUD_PLAYER_MODIS_TRACE(b_success, start_time, self_p->aud_handle);
            
            if (b_success)
            {
                self_p->start_time = start_time;
                result = MED_RES_OK;
            }
            else
            {
                result = MED_RES_FAIL;
            }
            
            break;
        }
        /* Unsupported commands */
        case AUD_PLAYER_SET_CACHE_TABLE:
        case AUD_PLAYER_SET_BUFFER:
        case AUD_PLAYER_SET_STOP_TIME:
        case AUD_PLAYER_SET_LEVEL:
        case AUD_PLAYER_SET_STORE_FLAG:
        case AUD_PLAYER_SET_FILE_OFFSET:
        default:
            result = MED_RES_UNSUPPORTED_OPERATION;
            break;
    }
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_modis_get
 * DESCRIPTION
 *  This function is used to get parameters from an MoDIS player.
 * PARAMETERS
 *  player_p      [IN]        Player handle.
 *  get_type      [IN]        Get command.
 *  data_p        [OUT]       The data relative to the command.
 *  data_len      [IN]        Indicats the length of the data buffer.
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_modis_get(med_aud_player_t*    player_p,
                                       med_aud_player_get_t get_type,
                                       void*                data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_modis_t* self_p;
    kal_int32               result = MED_RES_PARAM_ERROR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL && data_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_modis_t, itf);
    MED_ASSERT(self_p->aud_handle != AudioHandle_Invalid);

    switch (get_type)
    {
        case AUD_PLAYER_GET_START_TIME:
        {
            {
                *((kal_uint32*)data_p) = self_p->start_time;
                result = MED_RES_OK;
            }
            
            break;
        }            
        case AUD_PLAYER_GET_CURRENT_TIME:
        case AUD_PLAYER_GET_LAST_TIME:
        {
            kal_int64 position = 0;

            {
                w32_Audio_GetCurrentPosition(self_p->aud_handle, &position);
                _AUD_PLAYER_MODIS_TRACE(position, self_p->aud_handle, -1);
                
                *((kal_uint32*)data_p) = (kal_uint32)(position / 10000);

                result = MED_RES_OK;
            }
                
            break;
        }
        case AUD_PLAYER_GET_DURATION:
        {
            kal_int64 duration = 0;

            {
                w32_Audio_GetDuration(self_p->aud_handle, &duration);
                _AUD_PLAYER_MODIS_TRACE(duration, self_p->aud_handle, -1);
                
                *((kal_uint32*)data_p) = (kal_uint32)(duration / 10000);

                result = MED_RES_OK;
            }
            
            break;
        }
        /* Unsupported commands */
        case AUD_PLAYER_GET_STOP_TIME:
        case AUD_PLAYER_GET_LEVEL:
        case AUD_PLAYER_GET_CONTENT_DESC:
        case AUD_PLAYER_GET_LAST_OFFSET:
        default:
            result = MED_RES_UNSUPPORTED_OPERATION;
            break;
    }

    _AUD_PLAYER_MODIS_TRACE(get_type, result, *((kal_uint32*)data_p));
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_modis_destroy
 * DESCRIPTION
 *  This function is used to destroy a MoDIS player. Once called, all the 
 *  allocated interfaces of the player will be freed.
 * PARAMETERS
 *  player_p      [IN]        Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_modis_destroy(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_modis_t* self_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_modis_t, itf);
    
    AUD_PLAYER_FREE_AUD_MEM(self_p);
    
    return MED_RES_OK;
}
#endif /* __MTK_TARGET__ */

/*-----------------------------------------------------------------------------
                    public functions
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  aud_player_modis_construct
 * DESCRIPTION
 *  This function is used to construct a MoDIS player.
 * PARAMETERS
 *  void
 * RETURNS
 *  Player handle.
 *****************************************************************************/
med_aud_player_t* aud_player_modis_construct(void)
{
#if !defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_modis_t* self_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = (med_aud_player_modis_t*) med_alloc_aud_mem(sizeof(med_aud_player_modis_t));
    MED_ASSERT(self_p != NULL);

    kal_mem_set(self_p, 0, sizeof(*self_p));

    self_p->itf.open     = _aud_player_modis_open;
    self_p->itf.close    = _aud_player_modis_close;
    self_p->itf.play     = _aud_player_modis_play;
    self_p->itf.stop     = _aud_player_modis_stop;
    self_p->itf.pause    = _aud_player_modis_pause;
    self_p->itf.resume   = _aud_player_modis_resume;
    self_p->itf.set      = _aud_player_modis_set;
    self_p->itf.get      = _aud_player_modis_get;
    self_p->itf.destroy  = _aud_player_modis_destroy;

    kal_get_time(&self_p->time_stamp);

    return &self_p->itf;
#else
    return NULL;
#endif /* __MTK_TARGET__ */
}

#endif /* MED_NOT_PRESENT */ 

