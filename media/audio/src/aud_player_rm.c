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
 * aud_player_rm.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary functions of Real Media (RM) player.
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
 *    RM Player
 * DESCRIPTION
 *    This module defines related function of RA Player.
 *  
 ******************************************************************/

#ifndef MED_NOT_PRESENT

/*-----------------------------------------------------------------------------
                    include files
-----------------------------------------------------------------------------*/
#include "kal_release.h"
#include "kal_trace.h"
//#include "stack_common.h"
//#include "stack_msgs.h"
//#include "app_ltlcom.h"      /* Task message communiction */
//#include "syscomp_config.h"
//#include "task_config.h"     /* Task creation */
//#include "stacklib.h"        /* Basic type for dll, evshed, stacktimer */
//#include "event_shed.h"      /* Event scheduler */
//#include "stack_timer.h"     /* Stack timer */

/* global includes */
#include "l1audio.h"
//#include "device.h"
//#include "resource_audio.h"
//#include "fat_fs.h"
//#include "drm_gprot.h"
//#include "nvram_enums.h"
//#include "nvram_struct.h"
//#include "nvram_user_defs.h"
//#include "nvram_data_items.h"
//#include "custom_nvram_editor_data_item.h"
//#include "custom_equipment.h"
#include "FSAL.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_utility.h"
#include "med_struct.h"
//#include "med_api.h"
//#include "med_context.h"
#include "med_main.h"
#include "aud_main.h"
#include "aud_player.h"
#include "mpl_player.h"
#include "media_session.h"

#include "kal_general_types.h"
#include "med_smalloc.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#if defined(__MTK_TARGET__) && defined(__RM_DEC_SUPPORT__)
/*-----------------------------------------------------------------------------
                    macros, defines, typedefs, enums
-----------------------------------------------------------------------------*/
#define _AUD_PLAYER_RM_TRACE(x, y, z)    AUD_PLAYER_RM_TRACE(x, y, z, __LINE__)

/* Media Player */
typedef struct
{
    med_aud_player_t              itf;                /* Player interfaces */
    mpl_player_t*                 mpl_player_p;       /* MPL player */
    mpl_player_client_t           mpl_client;         /* MPL client events */
    STFSAL                        fsal_handle;        /* file handle */
    kal_bool                      is_player_opened;   /* Indicate if a player handler is opened successfully */
    kal_bool                      is_file_opened;     /* Indicate if a file handler has been opened successfully */
    kal_uint8                     audio_path;         /* Audio path for audio output */
    kal_uint8                     state;              /* Player state */
    kal_uint16                    app_id;             /* App id (used if __MED_IN_ASM__ is defined) */
    kal_int16                     media_type;         /* Media type */
    kal_uint32                    start_time;         /* Start time */
    kal_uint32                    stop_time;          /* Stop time */
    kal_uint32                    async_result;       /* Result set in asynchronous callback (rm_on_xxx) */
    med_aud_player_cb_fct         cb_fct;             /* Callback when there is event arisen */
    void*                         cb_param;           /* Callback parameter */
} med_aud_player_rm_t;

/*-----------------------------------------------------------------------------
                    data declaraions
 ----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
                    function prototypes
 ----------------------------------------------------------------------------*/ 

/*-----------------------------------------------------------------------------
                    private function declarations
 ----------------------------------------------------------------------------*/

/*****************************************************************************
* FUNCTION
*  _aud_player_rm_mpl_to_med_result
* DESCRIPTION
*  This function remaps the result of MPL to MED's.
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static kal_int32 _aud_player_rm_mpl_to_med_result(media_error_t mpl_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (mpl_result == MED_S_ASYNC)
    {
        return MED_RES_OK_ASYNC;
    }
    else if (mpl_result == MED_S_TERMINATED)
    {
        return MED_RES_TERMINATED;
    }
    else if (mpl_result == MED_E_CORRUPTED_DATA)
    {
        return MED_RES_INVALID_FORMAT;
    }
    else if (mpl_result == MED_E_STREAM_UNSUPPORTED_BANDWIDTH)
    {
        return MED_RES_STREAM_UNSUPPORTED_BANDWIDTH;
    }
    else if (mpl_result == MED_E_NO_REQUIRED_TRACK)
    {
        return MED_RES_NO_REQUIRED_TRACK;
    }
    else if (mpl_result == MED_E_OVER_LIMIT || mpl_result == MED_E_DECODER_NOT_SUPPORT)
    {
        return MED_RES_DECODER_NOT_SUPPORT;
    }
    else if (mpl_result == MED_E_FRAME_RATE_TOO_HIGH)
    {
        return MED_RES_VIDEO_FRAME_RATE_TOO_HIGH;
    }
    else if (mpl_result == MED_E_INVALID_RESOLUTION)
    {
        return MED_RES_VIDEO_UNSUPPORT_DECODE_SIZE;
    }
    else if (mpl_result == MED_E_MEM_INSUFFICIENT)
    {
        return MED_RES_MEM_INSUFFICIENT;
    }
    else if (mpl_result == MED_E_BAD_FORMAT)
    {
        return MED_RES_BAD_FORMAT;
    }
    else if (mpl_result == MED_E_OPEN_FILE_FAIL)
    {
        return MED_RES_OPEN_FILE_FAIL;
    }
    else if (mpl_result == MED_E_AUDIO_ERROR)
    {
        return MED_RES_AUDIO_ERROR;
    }
    else if (mpl_result == MED_E_VIDEO_ERROR)
    {
        return MED_RES_VIDEO_ERROR;
    }    
    else if (mpl_result == MED_E_STOP_TIME_REACHED)
    {
        return MED_RES_STOP_TIME_REACHED;
    }
    else if (mpl_result == MED_S_PLAY_FINISH)
    {
        return MED_RES_PLAY_FINISH;
    }
    else if (mpl_result == MED_E_STREAM_BUFFER_UNDERFLOW)
    {
        return MED_RES_STREAM_BUFFER_UNDERFLOW;
    }
    else if (mpl_result == MED_E_PDL_AUDIO_UNDERFLOW)
    {
        return MED_RES_PDL_AUDIO_UNDERFLOW;
    } 
    else if (mpl_result == MED_E_PDL_VIDEO_UNDERFLOW)
    {
        return MED_RES_PDL_VIDEO_UNDERFLOW;
    }
    else if (mpl_result == MED_E_STREAM_BUFFER_OVERFLOW)
    {
        return MED_RES_STREAM_BUFFER_OVERFLOW;
    }
    else if (mpl_result == MED_E_MP4_NO_VIDEO_TRACK)
    {
        return MED_RES_MP4_NO_VIDEO_TRACK;
    }
    else if (mpl_result >= 0)
    {
        return MED_RES_OK;
    }

    return MED_RES_FAIL;
}

/*****************************************************************************
 * FUNCTION
 *  aud_player_rm_resume
 * DESCRIPTION
 *  This function is used to seek to a given time.
 * PARAMETERS
 *  player_p      [IN]        Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_rm_seek(med_aud_player_t* player_p, kal_uint32 time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_rm_t*       self_p;
    mpl_player_seek_t          seek_req;
    media_error_t              mpl_result;
    kal_int32                  med_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_rm_t, itf);
    
    /* Seek */
    kal_mem_set(&seek_req, 0, sizeof(mpl_player_seek_t));

    /* get default setting */
    self_p->mpl_player_p->get_default(self_p->mpl_player_p, MPL_SEEK_PARAM, &seek_req);
    
    seek_req.time     = (kal_uint32)time;

    mpl_result = self_p->mpl_player_p->seek(self_p->mpl_player_p, &seek_req);
    med_result = _aud_player_rm_mpl_to_med_result(mpl_result);
    _AUD_PLAYER_RM_TRACE(med_result, self_p->mpl_player_p, -1);
    
    if (med_result == MED_RES_OK_ASYNC) /* Seeking */
    {
        /* When the seeking is completed, the on_seek function will be called.
         * We have to check the seek result which is updated in the callback function.
         */
        med_result = self_p->async_result;
        _AUD_PLAYER_RM_TRACE(med_result, self_p->mpl_player_p, -1);
    }
    
    return med_result;
}


/*****************************************************************************
 * FUNCTION
 *  _aud_player_rm_on_open
 * DESCRIPTION
 *  This function is called when the RA player is opened.
 * PARAMETERS
 *  result      [IN]           Open result.              
 * RETURNS
 *  
 *****************************************************************************/
static void _aud_player_rm_on_open(mpl_player_client_t* client_p, media_error_t mpl_result)
{
    /* Do nothing because the opening of RA is a blocking call. */
}


/*****************************************************************************
 * FUNCTION
 *  _aud_player_rm_on_play
 * DESCRIPTION
 *  This function is called when there is play event arisen. Note that when
 *  the play is finished or there is some wrong, the player will be automatically
 *  stopped. Hence, we have to update player to IDLE state in these cases. When
 *  the player is asked to be stopped again, we could prevent any failure when
 *  we try to stop the player again.
 * PARAMETERS
 *  result      [IN]           Open result.              
 * RETURNS
 *  
 *****************************************************************************/
static void _aud_player_rm_on_play(mpl_player_client_t* client_p, media_error_t mpl_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_rm_t* self_p;
    Media_Event          event = MEDIA_NONE;
    kal_int32            med_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(client_p != NULL);
    self_p = PTHIS(client_p, med_aud_player_rm_t, mpl_client);

    med_result = _aud_player_rm_mpl_to_med_result(mpl_result);
    _AUD_PLAYER_RM_TRACE(med_result, client_p, -1);
    
    switch (med_result)
    {
        case MED_RES_PLAY_FINISH:
            event = MEDIA_END;
            break;
        case MED_RES_STOP_TIME_REACHED:
            event = MEDIA_STOP_TIME_UP;
            break;
        case MED_RES_FAIL:
        case MED_RES_AUDIO_ERROR:
            event = MEDIA_ERROR;
            break;
        default:
            event = MEDIA_ERROR;
            break;
    }

    self_p->state = AUD_MEDIA_IDLE;

    /* Callback event to player handler */
    if (self_p->cb_fct)
    {
        self_p->cb_fct(&self_p->itf, event, self_p->cb_param);
    }
}


/*****************************************************************************
 * FUNCTION
 *  _aud_player_rm_on_seek
 * DESCRIPTION
 *  This function is called when seeking is done.
 * PARAMETERS
 *  result      [IN]           Open result.              
 * RETURNS
 *  
 *****************************************************************************/
static void _aud_player_rm_on_seek(mpl_player_client_t* client_p, media_error_t mpl_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_rm_t* self_p;
    kal_int32            med_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(client_p != NULL);
    self_p = PTHIS(client_p, med_aud_player_rm_t, mpl_client);

    /* Update result */
    med_result = _aud_player_rm_mpl_to_med_result(mpl_result);
    self_p->async_result = med_result;
}


/*****************************************************************************
 * FUNCTION
 *  _aud_player_rm_on_close
 * DESCRIPTION
 *  This function is called when the player is closed.
 * PARAMETERS
 *  result      [IN]           Open result.              
 * RETURNS
 *  
 *****************************************************************************/
static void _aud_player_rm_on_close(mpl_player_client_t* client_p, media_error_t mpl_result)
{

}

/*****************************************************************************
 * FUNCTION
 *  _aud_player_rm_on_event
 * DESCRIPTION
 *  This function is called when the player is closed.
 * PARAMETERS
 *  result      [IN]           Open result.              
 * RETURNS
 *  
 *****************************************************************************/
static void _aud_player_rm_on_event(mpl_player_client_t *client, mpl_player_event_t event, media_error_t mpl_result)
{
    switch(event)
    {
        case MPL_PLAYER_EVENT_OPEN:
            _aud_player_rm_on_open(client, mpl_result);
            break;
        case MPL_PLAYER_EVENT_SEEK:
            _aud_player_rm_on_seek(client, mpl_result);
            break;
        case MPL_PLAYER_EVENT_PLAY:
            _aud_player_rm_on_play(client, mpl_result);
            break;
        case MPL_PLAYER_EVENT_CLOSE:
            _aud_player_rm_on_close(client, mpl_result);
            break;
        default:
            ASSERT(0);
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  _aud_player_rm_alloc_mem
 * DESCRIPTION
 *  This function is to allocate memory.
 * PARAMETERS
 *  client_p      [IN]          MPL handle    
 *  size          [IN]          Memory size
 *  type          [IN]          Memory type
 *  file          [IN]          File name       
 *  line          [IN]          The line number in the file
 * RETURNS
 *  
 *****************************************************************************/
static void* _aud_player_rm_alloc_mem(mpl_player_client_t *client_p, kal_int32 size, med_mem_type_enum type, char* file, long line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_rm_t* self_p;
    void* mem_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(client_p != NULL);
    self_p = PTHIS(client_p, med_aud_player_rm_t, mpl_client);

    switch (type)
    {
        case MED_MEM_NONCACHE:
            mem_p = med_alloc_mem(self_p->app_id, size, file, line);
            break;
        case MED_MEM_CACHE:
            mem_p = med_alloc_mem_cacheable(self_p->app_id, size, file, line);
            break;
        case MED_MEM_AUD_RINGBUFF:
            aud_util_alloc_ring_buffer_w_log(file, line, size, (kal_uint16**)&mem_p);
            break;
        default:
            break;
    }
    
    return mem_p;
}


/*****************************************************************************
 * FUNCTION
 *  _aud_player_rm_free_mem
 * DESCRIPTION
 *  This function is to free memory.
 * PARAMETERS
 *  client_p      [IN]          MPL handle    
 *  mem_p         [IN]          Memory pointer
 *  type          [IN]          Memory type
 *  file          [IN]          File name       
 *  line          [IN]          The line number in the file
 * RETURNS
 *  
 *****************************************************************************/
static void _aud_player_rm_free_mem(mpl_player_client_t *client_p, void** mem_p, med_mem_type_enum type, char* file, long line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_rm_t* self_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(client_p != NULL);
    self_p = PTHIS(client_p, med_aud_player_rm_t, mpl_client);

    switch (type)
    {
        case MED_MEM_NONCACHE:
        case MED_MEM_CACHE:
            med_free_mem(self_p->app_id, mem_p, file, line);
            break;
        case MED_MEM_AUD_RINGBUFF:
            aud_util_free_ring_buffer_w_log(file, line, (kal_uint16**)mem_p);
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_rm_close
 * DESCRIPTION
 *  This function is used to close an MP4 player.
 * PARAMETERS
 *  player_p      [IN]        Player handle.              
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_rm_close(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_rm_t* self_p;
    media_error_t        mpl_result;
    kal_int32            med_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_rm_t, itf);

    if (self_p->is_player_opened)
    {
        mpl_result = self_p->mpl_player_p->close(self_p->mpl_player_p);
        med_result = _aud_player_rm_mpl_to_med_result(mpl_result);
        _AUD_PLAYER_RM_TRACE(med_result, self_p->mpl_player_p, -1);

        self_p->is_player_opened = KAL_FALSE;
    }

    /* Free FSAL resources */
    if (self_p->is_file_opened)
    {
        /* Free buffer */
        if (self_p->fsal_handle.bBuffering && self_p->fsal_handle.pbBuf != NULL)
        {
        #if defined(AUD_PROC_USE_EXT_MEM)
            AUD_PLAYER_FREE_AUD_MEM(self_p->fsal_handle.pbBuf);
        #else
            AUD_PLAYER_FREE_CTRL_BUF(self_p->fsal_handle.pbBuf);
        #endif
        }
        
        /* Close FSAL handler */
        FSAL_Close(&self_p->fsal_handle);
        
        self_p->is_file_opened = KAL_FALSE;
    }
    
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_rm_open
 * DESCRIPTION
 *  This function is used to open a RA player.
 * PARAMETERS
 *  player_p       [IN]        Player handle.
 *  cfg            [IN]        Player configuration.  
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_rm_open(med_aud_player_t* player_p, med_aud_player_cfg_t* cfg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_rm_t*       self_p;
    mpl_player_open_t          open_req;
    FSAL_Status                fsal_result;
    kal_uint8*                 fsal_buf_p;
    media_error_t              mpl_result;
    kal_int32                  med_result = MED_RES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_rm_t, itf);
     
    /* Open from file */
    if (cfg_p->file_name != NULL)
    {
        self_p->media_type = med_get_media_type(cfg_p->file_name);

        /* Open a FSAL handle for content descriptor */
        if ((fsal_result = FSAL_Open(&self_p->fsal_handle, cfg_p->file_name, FSAL_READ_SHARED)) != FSAL_OK)
        {
            return MED_RES_OPEN_FILE_FAIL;
        }

        /* Set Buffer to increase read performance */
    #if defined(AUD_PROC_USE_EXT_MEM)
        fsal_buf_p = (kal_uint8*) med_alloc_aud_mem(sizeof(kal_uint8) * AUD_PROC_BUF_SIZE);
    #else
        fsal_buf_p = (kal_uint8*) get_ctrl_buffer(sizeof(kal_uint8) * AUD_PROC_BUF_SIZE);
    #endif
    
        FSAL_SetBuffer(&self_p->fsal_handle, AUD_PROC_BUF_SIZE, fsal_buf_p);
    }
    /* Open from buffer */
    else if (cfg_p->data_p != NULL)
    {
        self_p->media_type = (kal_int16)cfg_p->format;

        /* Open a FSAL handle for content descriptor */
        FSAL_Direct_SetRamFileSize(&self_p->fsal_handle, cfg_p->data_len);
        if ((fsal_result = FSAL_Open(&self_p->fsal_handle, cfg_p->data_p, FSAL_ROMFILE)) != FSAL_OK)
        {
            return MED_RES_OPEN_FILE_FAIL;
        }
    }
    else
    {
        ASSERT(0);
        return MED_RES_PARAM_ERROR;
    }

    self_p->is_file_opened = KAL_TRUE;

    /* Construct RM player only if the callback function is not NULL. This mechanism is to
     * allow a client to get content description by opening an RM player with NULL callback.
     * In this case, the app_id is not required.
     */
    if (cfg_p->cb_fct)
    {
        /* Keep app id */
        self_p->app_id = cfg_p->app_id;
        
        /* Construct a media session */
        self_p->mpl_player_p = construct_media_session(&self_p->mpl_client);
        MED_ASSERT(self_p->mpl_player_p != NULL);
        _AUD_PLAYER_RM_TRACE(self_p->mpl_player_p, -1, -1);

        /* Construct open struct */
        kal_mem_set(&open_req, 0, sizeof(mpl_player_open_t));

        self_p->mpl_player_p->get_default(self_p->mpl_player_p, MPL_OPEN_PARAM, &open_req);
        
        if (cfg_p->file_name != NULL)
        {
            open_req.media_mode      = MED_MODE_FILE;
            open_req.media_type      = (kal_uint8)med_get_media_type(cfg_p->file_name);
            open_req.data            = (void*)cfg_p->file_name;
            open_req.data_size       = (kal_uint32)kal_wstrlen(cfg_p->file_name);
            open_req.open_track      = MED_VID_AUDIO_ONLY;
            open_req.enable_aud_only = (kal_bool)KAL_TRUE;
        }
        else
        {
            open_req.media_mode      = MED_MODE_ARRAY;
            open_req.media_type      = (kal_uint8)cfg_p->format;
            open_req.data            = (void*)cfg_p->data_p;
            open_req.data_size       = (kal_uint32)cfg_p->data_len;
            open_req.open_track      = MED_VID_AUDIO_ONLY;
            open_req.enable_aud_only = (kal_bool)KAL_TRUE;
        }
        
        mpl_result = self_p->mpl_player_p->open(self_p->mpl_player_p, &open_req);
        med_result = _aud_player_rm_mpl_to_med_result(mpl_result);
        _AUD_PLAYER_RM_TRACE(med_result, open_req.media_type, player_p);

        if ((med_result == MED_RES_OK) || (med_result == MED_RES_MP4_NO_VIDEO_TRACK)) /* Open Successfully */
        {
            self_p->is_player_opened = KAL_TRUE;
            self_p->state            = AUD_MEDIA_IDLE;
            self_p->start_time       = 0;
            self_p->audio_path       = cfg_p->audio_path;
            self_p->cb_fct           = cfg_p->cb_fct;
            self_p->cb_param         = cfg_p->cb_param;
            
            /* Seek to the beginning */
            med_result = _aud_player_rm_seek(player_p, 0);
            _AUD_PLAYER_RM_TRACE(med_result, player_p, -1);
        }
        else
        {
            /* Overwrite return code to have consistent UI display */
            switch (med_result)
            {
                case MED_RES_NO_REQUIRED_TRACK:
                    med_result = MED_RES_MP4_NO_AUDIO_TRACK;
                    break;
                default:
                    med_result = MED_RES_BAD_FORMAT;
                    break;
            }
        }
    }

    /*------------------------ Error handling -------------------------------*/
rm_open_failed:
    if (med_result != MED_RES_OK)
    {
        /* Close the RM player */
        _aud_player_rm_close(player_p);
    }

    return med_result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_rm_play
 * DESCRIPTION
 *  This function is used to start RA playback.
 * PARAMETERS
 *  player_p      [IN]        Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_rm_play(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_rm_t*       self_p;
    mpl_player_play_t          play_req;
    media_error_t              mpl_result;
    kal_int32                  med_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_rm_t, itf);

    /* Directly return if the player is already in play state */
    if (self_p->state == AUD_MEDIA_PLAY)
    {
        return MED_RES_OK;
    }
    
    /* Configure parameters for audio playback */
    kal_mem_set(&play_req, 0, sizeof(mpl_player_play_t));

    /* get default setting */
    self_p->mpl_player_p->get_default(self_p->mpl_player_p, MPL_PLAY_PARAM, &play_req);
    
    play_req.play_speed = (kal_int16)100;
    play_req.play_audio = (kal_uint8)KAL_TRUE;
    play_req.audio_path = (kal_uint8)self_p->audio_path;
    
    /* Begin to play */
    mpl_result = self_p->mpl_player_p->play(self_p->mpl_player_p, &play_req);
    med_result = _aud_player_rm_mpl_to_med_result(mpl_result);
    _AUD_PLAYER_RM_TRACE(med_result, self_p->mpl_player_p, mpl_result);
    
    if (med_result == MED_RES_OK)
    {
        /* enter AUD_MEDIA_PLAY state */
        self_p->state = AUD_MEDIA_PLAY;
    }
    
    return med_result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_rm_stop
 * DESCRIPTION
 *  This function is used to stop RA playback.
 * PARAMETERS
 *  player_p      [IN]        Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_rm_stop(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_rm_t* self_p;
    media_error_t        mpl_result;
    kal_int32            med_result = MED_RES_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_rm_t, itf);

    /* It's important to check player state because the player will be
     * automatically closed when the play is finished or there is something
     * wrong. Once the player is stopped, any attempt to stop the player
     * again will get failure.
     */
    if (self_p->state != AUD_MEDIA_IDLE)
    {
        mpl_result = self_p->mpl_player_p->stop_play(self_p->mpl_player_p);  
        med_result = _aud_player_rm_mpl_to_med_result(mpl_result);

        _AUD_PLAYER_RM_TRACE(med_result, self_p->mpl_player_p, mpl_result);

        /* Seek to the beginning */
        med_result = _aud_player_rm_seek(player_p, 0);
        _AUD_PLAYER_RM_TRACE(med_result, player_p, -1);
        
        /* enter AUD_MEDIA_IDLE state */
        self_p->state = AUD_MEDIA_IDLE;
    }
    
    return med_result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_rm_pause
 * DESCRIPTION
 *  This function is used to pause RA playback.
 * PARAMETERS
 *  player_p      [IN]        Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_rm_pause(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_rm_t*          self_p;
    media_error_t                 mpl_result;
    kal_int32                     med_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_rm_t, itf);
    
    /* Stop the play */
    mpl_result = self_p->mpl_player_p->stop_play(self_p->mpl_player_p);  
    med_result = _aud_player_rm_mpl_to_med_result(mpl_result);
    _AUD_PLAYER_RM_TRACE(med_result, self_p->mpl_player_p, mpl_result);
    
    if (med_result == MED_RES_OK)
    {
        /* enter AUD_MEDIA_PLAY_PAUSED state */
        self_p->state = AUD_MEDIA_PLAY_PAUSED;
    }
    
    return med_result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_rm_resume
 * DESCRIPTION
 *  This function is used to resume RA playback.
 * PARAMETERS
 *  player_p      [IN]        Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_rm_resume(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_rm_t*       self_p;
    kal_int32                  med_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_rm_t, itf);
    
    /* Play from last stopped time. Note that we don't have to seek 
     * to last time because when RM player is stopped, it will stay
     * at last pasued position. When we try to play the RM player
     * again, it will resume playback from last position. I.e. we 
     * could save the time to seek to last time.
     */
    med_result = _aud_player_rm_play(player_p);
    _AUD_PLAYER_RM_TRACE(med_result, self_p->mpl_player_p, -1);
    
    if (med_result == MED_RES_OK)
    {
        /* enter AUD_MEDIA_PLAY state */
        self_p->state = AUD_MEDIA_PLAY;
    }
    
    return med_result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_rm_set
 * DESCRIPTION
 *  This function is used to set parameters to a RA player.
 * PARAMETERS
 *  player_p       [IN]        Player handle.
 *  set_type       [IN]        Set command.
 *  data_p         [IN]        The data relative to the command.
 *  data_len       [IN]        The length of the data.
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_rm_set(med_aud_player_t*     player_p,
                                    med_aud_player_set_t  set_type,
                                    void*                 data_p,
                                    kal_uint32            data_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_rm_t* self_p;
    kal_int32            med_result = MED_RES_UNSUPPORTED_OPERATION;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_rm_t, itf);

    _AUD_PLAYER_RM_TRACE(set_type, (kal_uint32)data_p, data_len);
    
    switch (set_type)
    {
        case AUD_PLAYER_SET_START_TIME:
        {
            kal_uint32 start_time = (kal_uint32)data_p;
            
            med_result = _aud_player_rm_seek(player_p, start_time);
            _AUD_PLAYER_RM_TRACE(med_result, self_p->mpl_player_p, -1);
            
            if (med_result == MED_RES_OK)
            {
                self_p->start_time = start_time;
            }
            
            break;
        }
        case AUD_PLAYER_SET_STOP_TIME:
        {
            kal_uint32 stop_time = (kal_uint32)data_p;
            
            if (med_result == MED_RES_OK)
            {
                self_p->stop_time = stop_time;
            }
            
            break;
        }
        case AUD_PLAYER_SET_LEVEL:
        {
            kal_uint8 volume = (kal_uint8)(kal_uint32)data_p;
            
            self_p->mpl_player_p->set_param(self_p->mpl_player_p, MPL_PARAM_AUD_VOLUME, (void*)&volume);
            
            break;
        }
        
        /* Unsupported commands */
        case AUD_PLAYER_SET_CACHE_TABLE:
        case AUD_PLAYER_SET_BUFFER:
        case AUD_PLAYER_SET_STORE_FLAG:
        case AUD_PLAYER_SET_FILE_OFFSET:
        default:
            med_result = MED_RES_UNSUPPORTED_OPERATION;
            break;
    }
    
    return med_result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_rm_get
 * DESCRIPTION
 *  This function is used to get parameters from a RA player.
 * PARAMETERS
 *  player_p       [IN]        Player handle.
 *  get_type       [IN]        Set command.
 *  data_p         [OUT]       The data relative to the command.
 *  data_len       [IN]        Indicats the length of the data buffer.
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_rm_get(med_aud_player_t*     player_p,
                                    med_aud_player_get_t  get_type,
                                    void*                 data_p,
                                    kal_uint32            data_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_rm_t* self_p;
    Media_Status         drv_result;
    kal_int32            med_result = MED_RES_PARAM_ERROR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL && data_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_rm_t, itf);
    
    switch (get_type)
    {
        case AUD_PLAYER_GET_START_TIME:
        {
            if (data_len >= sizeof(kal_uint32))
            {
                *((kal_uint32*)data_p) = self_p->start_time;
                med_result = MED_RES_OK;
            }
            
            break;
        }
        case AUD_PLAYER_GET_STOP_TIME:
        {
            if (data_len >= sizeof(kal_uint32))
            {
                *((kal_uint32*)data_p) = self_p->stop_time;
                med_result = MED_RES_OK;
            }
            
            break;
        }             
        case AUD_PLAYER_GET_CURRENT_TIME:
        case AUD_PLAYER_GET_LAST_TIME:
        { 
            if (data_len >= sizeof(kal_uint32))
            {
                kal_uint64 time;
                
                self_p->mpl_player_p->get_param(self_p->mpl_player_p, MPL_PARAM_CURRENT_PLAY_TIME, (void*)&time);
                
                *((kal_uint32*)data_p) = (kal_uint32)time;
                
                med_result = MED_RES_OK;
            }
            
            break;
        }
        case AUD_PLAYER_GET_DURATION:
        {
            mpl_player_get_media_info_t media_info;
            
            if (data_len >= sizeof(kal_uint32))
            {
                self_p->mpl_player_p->get_media_info(self_p->mpl_player_p, &media_info);
                
                *((kal_uint32*)data_p) = (kal_uint32)media_info.duration;
                
                med_result = MED_RES_OK;
            }
            
            break;
        }
        case AUD_PLAYER_GET_LEVEL:
        {
            kal_uint8 volume;
            
            if (data_len >= sizeof(kal_uint8))
            {
                self_p->mpl_player_p->get_param(self_p->mpl_player_p, MPL_PARAM_AUD_VOLUME, (void*)&volume);
                
                *((kal_uint8*)data_p) = volume;

                med_result = MED_RES_OK;
            }
            
            break;
        }
        case AUD_PLAYER_GET_CONTENT_DESC:
        {
            if (data_len >= sizeof(audInfoStruct))
            {
                drv_result = RM_GetContentDescInfo(&self_p->fsal_handle, (audInfoStruct*)data_p, (void*)self_p->app_id);
                med_result = aud_get_res(drv_result);
            }
            
            break;
        }
        
        /* Unsupported commands */
        default:
            med_result = MED_RES_UNSUPPORTED_OPERATION;
            break;
    }

    _AUD_PLAYER_RM_TRACE(get_type, med_result, *((kal_uint32*)data_p));
    
    return med_result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_rm_destroy
 * DESCRIPTION
 *  This function is used to destroy a RA player. Once called, all the 
 *  allocated interfaces of the player will be freed.
 * PARAMETERS
 *  player_p      [IN]        Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_rm_destroy(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_rm_t* self_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_rm_t, itf);
    
    /* Destroy the RA player */
    if (self_p->mpl_player_p)
    {
        self_p->mpl_player_p->destroy(self_p->mpl_player_p);
    }
    
    /* Free RA player resources */
    AUD_PLAYER_FREE_AUD_MEM(self_p);
    
    return MED_RES_OK;
}
#endif /* __MTK_TARGET__ && __RM_DEC_SUPPORT__ */


/*-----------------------------------------------------------------------------
                    public functions
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  aud_player_media_construct
 * DESCRIPTION
 *  This function is used to construct a media player.
 * PARAMETERS
 *  void
 * RETURNS
 *  Player handle.
 *****************************************************************************/
med_aud_player_t* aud_player_rm_construct(void)
{
#if defined(__MTK_TARGET__) && defined(__RM_DEC_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_rm_t* self_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = (med_aud_player_rm_t*) med_alloc_aud_mem(sizeof(med_aud_player_rm_t));
    MED_ASSERT(self_p != NULL);

    kal_mem_set(self_p, 0, sizeof(*self_p));

    self_p->itf.open    = _aud_player_rm_open;
    self_p->itf.close   = _aud_player_rm_close;
    self_p->itf.play    = _aud_player_rm_play;
    self_p->itf.stop    = _aud_player_rm_stop;
    self_p->itf.pause   = _aud_player_rm_pause;
    self_p->itf.resume  = _aud_player_rm_resume;
    self_p->itf.set     = _aud_player_rm_set;
    self_p->itf.get     = _aud_player_rm_get;
    self_p->itf.destroy = _aud_player_rm_destroy;
    
    self_p->mpl_client.mem_alloc_func = _aud_player_rm_alloc_mem;
    self_p->mpl_client.mem_free_func  = _aud_player_rm_free_mem;
    self_p->mpl_client.on_event       = _aud_player_rm_on_event;
    
    return &self_p->itf;
#else
    return NULL;
#endif /* __MTK_TARGET__ && __RM_DEC_SUPPORT__ */
}

#endif /* MED_NOT_PRESENT */ 

