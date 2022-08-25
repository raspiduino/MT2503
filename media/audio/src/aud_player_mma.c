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
 * aud_player_mma.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary functions of MMA player.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/******************************************************************
 * MODULE
 *    MMA Audio Player
 * DESCRIPTION
 *    This module defines related function of MMA Player.
 *  
 ******************************************************************/

#ifndef MED_NOT_PRESENT

/*-----------------------------------------------------------------------------
                    include files
-----------------------------------------------------------------------------*/
//#include "kal_release.h"
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
#include "drm_gprot.h"
//#include "nvram_enums.h"
//#include "nvram_struct.h"
//#include "nvram_user_defs.h"
//#include "nvram_data_items.h"
//#include "custom_nvram_editor_data_item.h"
//#include "custom_equipment.h"
#include "FSAL.h"

/* local includes */
#include "med_global.h"
//#include "aud_defs.h"
#include "med_utility.h"
//#include "med_struct.h"
//#include "med_api.h"
//#include "med_context.h"
#include "med_main.h"
#include "aud_main.h"
#include "aud_player.h"
#include "aud_player_mma.h"

#include "kal_general_types.h"
#include "fs_type.h"
#include "kal_public_api.h"
#include "stack_config.h"
#include "drm_def.h"
#include "fs_errcode.h"
#include "med_smalloc.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#if defined(__MTK_TARGET__) && defined(__MED_DSP_WT_SYN__)
/*-----------------------------------------------------------------------------
                    macros, defines, typedefs, enums
-----------------------------------------------------------------------------*/
#define _AUD_PLAYER_MMA_TRACE(x, y, z)   AUD_PLAYER_MMA_TRACE(x, y, z, __LINE__)
#define _AUD_PLAYER_MMA2_TRACE(x, y)     AUD_PLAYER_MMA2_TRACE(x, y, __LINE__)


/* MMA Event */
typedef struct
{
    Media_Handle*                 media_handle_p;       /* Media handle */
    Media_Event                   event;                /* Event */
    med_aud_player_t*             player_p;             /* Player handle */
    kal_uint32                    time_stamp;           /* Time stamp of the callback event */
} med_aud_player_mma_event_t;

/* MMA Player */
typedef struct
{
    med_aud_player_t              itf;                  /* Player interfaces */
    kal_uint32                    time_stamp;           /* Time stamp of the constructed player */
    Media_Handle*                 media_handle_p;       /* Media handle */
    FS_HANDLE                     fs_memory_playback;   /* file handle used for loading file data into memory */
#ifdef MIDFILE_PLAY_SUPPORT
    STFSAL                        fs_direct_playback;   /* file handle used for direct file playback */
#endif /* MIDFILE_PLAY_SUPPORT */
    kal_uint8*                    data_p;               /* Data buffer for storing file data */
    kal_uint32                    data_len;             /* The length of data */
    kal_uint8*                    working_buffer_p;     /* Working buffer for processing MMA data */
#if defined(JTONE_SUPPORT) && defined(__MED_MMA_MOD__)
    Media_ToneSeq_Param*          toneseq_param_p;      /* JTone parameter */
#endif /* JTONE_SUPPORT && __MED_MMA_MOD__ */
    kal_bool                      is_memory_fs_opened;  /* Indicate if a FSAL handler has been opened */
    kal_bool                      is_direct_fs_opened;  /* Indicate if a DRM file handle has been opened */
    kal_uint8                     state;                /* Player state */
    med_type_enum                 media_type;           /* Media type */
    kal_uint32                    start_time;           /* Start time */
    kal_uint32                    stop_time;            /* Stop time */
    med_aud_player_cb_fct         cb_fct;               /* Callback when there is event arisen */
    void*                         cb_param;             /* Callback parameter */
} med_aud_player_mma_t;

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
 *  _aud_player_mma_event_callback_hdlr
 * DESCRIPTION
 *  This function is used to handle the callback events from L1Audio.
 * PARAMETERS
 *  data_p            [IN]       MMA event data.
 *  data_len          [IN]       The length of data.
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_player_mma_event_callback_hdlr(void* data_p, kal_uint16 data_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_mma_t*       self_p;
    med_aud_player_mma_event_t* mma_event_p = (med_aud_player_mma_event_t*)data_p;
    Media_Event                 event = mma_event_p->event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(mma_event_p->player_p, med_aud_player_mma_t, itf);

    _AUD_PLAYER_MMA_TRACE(self_p->state , event, mma_event_p->media_handle_p);
    
    /* Validate event */
    if (self_p->state != AUD_MEDIA_PLAY ||
        self_p->media_handle_p != mma_event_p->media_handle_p ||
        self_p->time_stamp != mma_event_p->time_stamp)
    {
        return;
    }
    
    /* Post processing */
    switch (event)
    {      
        case MEDIA_NONE:
            /* Do nothing */
            break;
        case MEDIA_REPEATED: /* Client has to stop melody driver */
        default:
            /* Callback event to player handler */
            if (self_p->cb_fct)
            {
                self_p->cb_fct(mma_event_p->player_p, event, self_p->cb_param);
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  _aud_player_mma_event_callback_fct
 * DESCRIPTION
 *  This function is used to receive the callback events from L1Audio.
 * PARAMETERS
 *  handle_p      [IN]         MHdl handler.
 *  event         [IN]         Player event.
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_player_mma_event_callback_fct(Media_Handle *handle_p, Media_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_mma_t*      self_p;
    med_aud_player_mma_event_t mma_event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Get player handle from attached user data */
    Media_GetUserData(handle_p, (void**)&mma_event.player_p);
    
    self_p = PTHIS(mma_event.player_p, med_aud_player_mma_t, itf);
    
    _AUD_PLAYER_MMA_TRACE(event, mma_event.player_p, handle_p);
    
    /* The following events could be sent in high frequence rate. To avoid overflow 
     * on the messageQ of MED. We have to callback these events directly. Note that
     * the callback of these events are using thread context of L1audio. Concurrent
     * protection may be required when accessing to global context.
     */
    switch (event)
    {
#ifdef __MED_IMY_EVENT__    
        case MEDIA_EXTENDED_EVENT:
        case MEDIA_LED_ON:
        case MEDIA_LED_OFF:
        case MEDIA_VIBRATOR_ON:
        case MEDIA_VIBRATOR_OFF:
        case MEDIA_BACKLIGHT_ON:
        case MEDIA_BACKLIGHT_OFF:
            if (self_p->state == AUD_MEDIA_PLAY)
            {
                if (self_p->cb_fct)
                {
                    self_p->cb_fct(&self_p->itf, event, self_p->cb_param);
                }
                return; /* Directly return */
            }

            /* Some events (e.g. MEDIA_VIBRATOR_ON) may be send before the player enters PLAY state.
             * Hence, we need to context switch the event to MED first. Othewise, the events will be
             * dropped directly.
             */
            break;
#endif

        default:
            break;
    }
    
    mma_event.media_handle_p = handle_p;
    mma_event.event = event;
    mma_event.time_stamp = self_p->time_stamp;
    
    aud_util_proc_in_med_ext(MOD_L1SP,
                             _aud_player_mma_event_callback_hdlr,
                             (void*)&mma_event,
                             sizeof(med_aud_player_mma_event_t));
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_mma_close
 * DESCRIPTION
 *  This function is used to close an MMA player.
 * PARAMETERS
 *  player_p      [IN]        Player handle.              
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_mma_close(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_mma_t* self_p;
    Media_Status          drv_result = MEDIA_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(player_p, med_aud_player_mma_t, itf);
    
    /* Free player resources */
    if (self_p->media_handle_p)
    {
        /* Close by media type */
        switch (self_p->media_type)
        {
            case MED_TYPE_SMF:
                drv_result = JSmf_Close(self_p->media_handle_p);
                break;
            case MED_TYPE_IMELODY:
                drv_result = JImy_Close(self_p->media_handle_p);
                break;
        #if defined(__MED_MMA_EXTRA_CTRL__) && defined(__MED_MMA_MOD__)
            case MED_TYPE_MIDI:
                drv_result = JMidi_CloseDevice(self_p->media_handle_p);
                break;
        #endif /* __MED_MMA_EXTRA_CTRL__ && __MED_MMA_MOD__ */
        #if defined(JTONE_SUPPORT) && defined(__MED_MMA_MOD__)
            case MED_TYPE_TONE:
                drv_result = JTone_Close(self_p->media_handle_p);
                break;
        #endif /* JTONE_SUPPORT && __MED_MMA_MOD__ */
        #if defined(WAV_CODEC) && defined(__MED_MMA_MOD__)
            case MED_TYPE_WAV:
                drv_result = JWav_Close(self_p->media_handle_p);
                break;
        #endif /* WAV_CODEC && __MED_MMA_MOD__ */
        
            default:
                break;
        }
        _AUD_PLAYER_MMA2_TRACE(drv_result, self_p->media_handle_p);
        
        self_p->media_handle_p = NULL;
    }
    
    /* Free working buffer */
    if (self_p->working_buffer_p)
    {
        AUD_PLAYER_FREE_AUD_MEM(self_p->working_buffer_p);
    }
    
    /* Free resources for direct playback */
#ifdef MIDFILE_PLAY_SUPPORT    
    if (self_p->is_direct_fs_opened)
    {
        /* Free buffer */
        if (self_p->fs_direct_playback.bBuffering && self_p->fs_direct_playback.pbBuf != NULL)
        {
        #if defined(AUD_PROC_USE_EXT_MEM)
            AUD_PLAYER_FREE_AUD_MEM(self_p->fs_direct_playback.pbBuf);
        #else
            AUD_PLAYER_FREE_CTRL_BUF(self_p->fs_direct_playback.pbBuf);
        #endif
        }
        
        /* Close FSAL handler */
        FSAL_Close(&self_p->fs_direct_playback);
        
        self_p->is_direct_fs_opened = KAL_FALSE;
    }
#endif /* MIDFILE_PLAY_SUPPORT */    
    
    /* Free resources for memory playback */
    if (self_p->is_memory_fs_opened)
    {
        /* Free buffer of file data */
        AUD_PLAYER_FREE_AUD_MEM(self_p->data_p);
        
        /* Close DRM handler */
        DRM_close_file(self_p->fs_memory_playback);
        
        self_p->is_memory_fs_opened = KAL_FALSE;
    }
    
    return aud_get_res(drv_result);
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_mma_open
 * DESCRIPTION
 *  This function is used to open a MMA player.
 * PARAMETERS
 *  player_p      [IN]        Player handle.
 *  cfg_p         [IN]        Player configuration.  
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_mma_open(med_aud_player_t* player_p, med_aud_player_cfg_t* cfg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_mma_t*   self_p;
    kal_int32               fs_result;
    kal_uint32              file_size;
    kal_uint32              buffer_size;
    kal_uint32              read;
    kal_int32               med_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(player_p, med_aud_player_mma_t, itf);
  
    /*---------- Open a FSAL handler or load file data to memory ------*/
    /* Open from file */
    if (cfg_p->file_name != NULL)
    {
        /* Determine media format per file extension */
        self_p->media_type =  (med_type_enum)med_get_media_type(cfg_p->file_name);
        
    #ifdef MIDFILE_PLAY_SUPPORT
        if (self_p->media_type == MED_TYPE_SMF)
        {
            /* Play from file directly */
            if (FSAL_Open(&self_p->fs_direct_playback, cfg_p->file_name, FSAL_READ_SHARED) != FSAL_OK)
            {
                return MED_RES_OPEN_FILE_FAIL;
            }
            
            /* Check file size limitation */ 
            if (FSAL_GetFileSize(&self_p->fs_direct_playback, &file_size) == FSAL_OK)
            {
                if (file_size > AUD_MIDI_FILE_SIZE)
                {
                    /* Remember to close file handle */
                    FSAL_Close(&self_p->fs_direct_playback);
                    return MED_RES_MEM_INSUFFICIENT;
                }
            }
            else
            {
                /* Remember to close file handle */
                FSAL_Close(&self_p->fs_direct_playback);
                return MED_RES_OPEN_FILE_FAIL;
            }
            
            /* Indicate that a file handle is opened for direct playback */
            self_p->is_direct_fs_opened = KAL_TRUE;
        }
        else
    #endif /* MIDFILE_PLAY_SUPPORT */
        {
            /* Currently, only SMF/IMY support playback from file. */
            if (self_p->media_type == MED_TYPE_SMF || 
                self_p->media_type == MED_TYPE_IMELODY)
            {
                /* Load file data into memory */
                self_p->fs_memory_playback = DRM_open_file(cfg_p->file_name, FS_READ_ONLY | FS_OPEN_NO_DIR | FS_NOBUSY_CHECK_MODE, DRM_PERMISSION_PLAY);
        
                if (self_p->fs_memory_playback < 0)
                {
                    return MED_RES_OPEN_FILE_FAIL;
                }
                
                fs_result = DRM_file_size(self_p->fs_memory_playback, &file_size);
                
                if (fs_result != FS_NO_ERROR || file_size == 0)
                {
                    DRM_close_file(self_p->fs_memory_playback);
                    return MED_RES_OPEN_FILE_FAIL;
                }
                else if (file_size > AUD_MELODY_BUFFER_LEN)
                {
                    DRM_close_file(self_p->fs_memory_playback);
                    return MED_RES_MEM_INSUFFICIENT;
                }
                
                self_p->data_p = med_alloc_aud_mem(file_size);
                
                if (self_p->data_p == NULL)
                {
                    DRM_close_file(self_p->fs_memory_playback);      
                    return MED_RES_MEM_INSUFFICIENT;
                }
                
                /* read data from file to buffer */
                DRM_read_file(self_p->fs_memory_playback, self_p->data_p, file_size, &read);
                
                if (read == 0)
                {
                    /* free file buffer */
                    AUD_PLAYER_FREE_AUD_MEM(self_p->data_p);
                    DRM_close_file(self_p->fs_memory_playback);
                    
                    return MED_RES_OPEN_FILE_FAIL;
                }
                
                self_p->data_len = file_size;
                
                /* Indicate that a file handle is opened for memory playback */
                self_p->is_memory_fs_opened = KAL_TRUE;
            }
            else
            {
                /* We should play JMidi/JTone/JWav from buffer */
                return MED_RES_INVALID_FORMAT;
            }
        }
    }
    /* Open from buffer */
    else
    {
        switch (cfg_p->format)
        {
        #if defined(__MED_MMA_EXTRA_CTRL__) && defined(__MED_MMA_MOD__)
            case MED_TYPE_MIDI:    /* JMidi */
                /* The data could be set later */
                break;
        #endif /* __MED_MMA_EXTRA_CTRL__ && __MED_MMA_MOD__ */
        #if defined(JTONE_SUPPORT) && defined(__MED_MMA_MOD__)
            case MED_TYPE_TONE:    /* JTone */
                /* The data could be set later */
                break;
        #endif /* JTONE_SUPPORT && __MED_MMA_MOD__ */
        
            case MED_TYPE_SMF:     /* JSmf */
            case MED_TYPE_IMELODY: /* JImy */
        #if defined(WAV_CODEC) && defined(__MED_MMA_MOD__)
            case MED_TYPE_WAV:     /* JWav */
        #endif /* WAV_CODEC && __MED_MMA_MOD__ */
            default:
                /* For other types, we should guarantee there are data to open. */
                MED_ASSERT(cfg_p->data_p != NULL);
                break;
        }
        
        /* Update media type and data buffer */
        self_p->media_type =  (med_type_enum)cfg_p->format;
        self_p->data_p     = cfg_p->data_p;
        self_p->data_len   = cfg_p->data_len;
    }

    _AUD_PLAYER_MMA2_TRACE(self_p->is_direct_fs_opened , self_p->is_memory_fs_opened);
    
    /*-------------------------- Setup buffers  -----------------------------*/
#ifdef MIDFILE_PLAY_SUPPORT
    {
        kal_uint8* fsal_buf_p;
        
        /* Set Buffer to increase read performance for FSAL */
        if (self_p->is_direct_fs_opened)
        {
        #if defined(AUD_PROC_USE_EXT_MEM)
            fsal_buf_p = (kal_uint8*) med_alloc_aud_mem(sizeof(kal_uint8) * AUD_PROC_BUF_SIZE);
        #else
            fsal_buf_p = (kal_uint8*) get_ctrl_buffer(sizeof(kal_uint8) * AUD_PROC_BUF_SIZE);
        #endif
        
            FSAL_SetBuffer(&self_p->fs_direct_playback, AUD_PROC_BUF_SIZE, fsal_buf_p);
        }
    }
#endif /* MIDFILE_PLAY_SUPPORT */    
    
    /*------------------- Open a handler by media type  ---------------------*/
    switch (self_p->media_type)
    {
        case MED_TYPE_SMF:
        {
            Media_SMF_Param* pt_smf_param;
            
            /* Open a JSmf handler */
            if ((self_p->media_handle_p = JSmf_Open(_aud_player_mma_event_callback_fct, &buffer_size)) == NULL)
            {
                med_result = MED_RES_OPEN_FILE_FAIL;
                goto mma_open_failed;
            }
            
            /* Allocate working buffer */
            self_p->working_buffer_p = (kal_uint8*)med_alloc_aud_mem(buffer_size);

            if (self_p->working_buffer_p == NULL)
            {
                med_result = MED_RES_MEM_INSUFFICIENT;
                goto mma_open_failed;
            }
            
            /* Set buffer and parameters */
            JSmf_SetBuffer(self_p->media_handle_p, (kal_int8*)self_p->working_buffer_p, buffer_size, &pt_smf_param);

        #ifdef MIDFILE_PLAY_SUPPORT
            if (self_p->is_direct_fs_opened)
            {
                /* Play file */
                pt_smf_param->pstFSAL  = &self_p->fs_direct_playback;
                pt_smf_param->smffile  = NULL;
                pt_smf_param->filesize = 0;
                pt_smf_param->repeats  = cfg_p->repeat;
            }
            else
        #endif /* MIDFILE_PLAY_SUPPORT */
            {
                /* Play memory data */
                pt_smf_param->pstFSAL  = NULL;
                pt_smf_param->smffile  = self_p->data_p;
                pt_smf_param->filesize = self_p->data_len;
                pt_smf_param->repeats  = cfg_p->repeat;
            }
            
            break;
        }
        
        case MED_TYPE_IMELODY:
        {
            Media_iMelody_Param* pt_imy_param;
            
            /* Open a JImy handler */
            if ((self_p->media_handle_p = JImy_Open(_aud_player_mma_event_callback_fct, &pt_imy_param)) == NULL)
            {
                med_result = MED_RES_OPEN_FILE_FAIL;
                goto mma_open_failed;
            }
            
            /* Set parameters */
            pt_imy_param->imyfile  = (const kal_uint8*)self_p->data_p;
            pt_imy_param->filesize = self_p->data_len;
            pt_imy_param->repeats  = cfg_p->repeat;
            pt_imy_param->default_instrument = IMY_DEFAULT_INSTRUMENT;
            
            break;
        }

    #if defined( __MED_MMA_EXTRA_CTRL__) && defined(__MED_MMA_MOD__)
        case MED_TYPE_MIDI:
        {
            /* Open a JMidi handler */
            if ((self_p->media_handle_p = JMidi_OpenDevice(&buffer_size)) == NULL)
            {
                med_result = MED_RES_OPEN_FILE_FAIL;
                goto mma_open_failed;
            }

            /* Setup fast pass mode */
            if (cfg_p->fast_pass)
            {
                Media_FastPassMode((void*)self_p->media_handle_p, MEDIA_FORMAT_SMF);
            }
            
            /* Allocate working buffer */
            self_p->working_buffer_p = (kal_uint8*)med_alloc_aud_mem(buffer_size);

            if (self_p->working_buffer_p == NULL)
            {
                med_result = MED_RES_MEM_INSUFFICIENT;
                goto mma_open_failed;
            }

            /* Set buffer */
            JMidi_SetBuffer(self_p->media_handle_p , (kal_int8*)self_p->working_buffer_p, buffer_size);
            
            break;
        }
    #endif /* __MED_MMA_EXTRA_CTRL__ && __MED_MMA_MOD__ */

    #if defined(JTONE_SUPPORT) && defined(__MED_MMA_MOD__)
        case MED_TYPE_TONE:
        {
            /* Open a JTone handler */
            if ((self_p->media_handle_p = JTone_Open(_aud_player_mma_event_callback_fct, (Media_ToneSeq_Param**)&self_p->toneseq_param_p)) == NULL)
            {
                med_result = MED_RES_OPEN_FILE_FAIL;
                goto mma_open_failed;
            }
            
            break;
        }
    #endif /* JTONE_SUPPORT && __MED_MMA_MOD__ */

    #if defined(WAV_CODEC) && defined(__MED_MMA_MOD__)
        case MED_TYPE_WAV:
        {
            Media_Status     drv_result;
            kal_uint32       buffer_len;
            Media_Wav_Param* wav_param_p;
            
            /* Open a JWav handler */
            if ((self_p->media_handle_p = JWav_Open(_aud_player_mma_event_callback_fct, (Media_Wav_Param**)&wav_param_p)) == NULL)
            {
                med_result = MED_RES_OPEN_FILE_FAIL;
                goto mma_open_failed;
            }

            wav_param_p->wavefile = (const kal_uint8*)self_p->data_p;;
            wav_param_p->filesize = self_p->data_len;
            wav_param_p->repeats  = cfg_p->repeat;

            /* Load wave */
            if ((drv_result = JWav_Load(self_p->media_handle_p, &buffer_len)) != MEDIA_SUCCESS)
            {
                med_result = aud_get_res(drv_result);
                goto mma_open_failed;
            }

            /* Allocate working buffer */
            self_p->working_buffer_p = (kal_uint8*)med_alloc_aud_mem(buffer_len * sizeof(kal_uint16));

            if (self_p->working_buffer_p == NULL)
            {
                med_result = MED_RES_MEM_INSUFFICIENT;
                goto mma_open_failed;
            }
            
            /* Set buffer */
            JWav_SetBuffer(self_p->media_handle_p, (kal_int16*)self_p->working_buffer_p, buffer_len);  
            
            break;
        }
    #endif /* WAV_CODEC && __MED_MMA_MOD__ */
    
        default:
            med_result = MED_RES_INVALID_FORMAT;
            goto mma_open_failed;
    }

    _AUD_PLAYER_MMA2_TRACE(player_p, self_p->media_type);
    
    /* Attach user data to media handle */
    Media_SetUserData(self_p->media_handle_p, (void*)player_p);

    /*------------------------ Setup private data ---------------------------*/
    self_p->state      = AUD_MEDIA_IDLE;
    self_p->start_time = 0;
    self_p->stop_time  = 0;
    self_p->cb_fct     = cfg_p->cb_fct;
    self_p->cb_param   = cfg_p->cb_param;
    
    return MED_RES_OK;

    /*------------------------ Error handling -------------------------------*/
mma_open_failed:
    /* Close the MMA player */
    _aud_player_mma_close(player_p);

    return med_result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_mma_play
 * DESCRIPTION
 *  This function is used to start MMA playback.
 * PARAMETERS
 *  player_p      [IN]        Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_mma_play(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_mma_t* self_p;
    Media_Status          drv_result = MEDIA_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(player_p, med_aud_player_mma_t, itf);

    /* Directly return if the player is not in idle state */
    if (self_p->state != AUD_MEDIA_IDLE)
    {
        return MED_RES_FAIL;
    }
    
    /* Play by media type */
    switch (self_p->media_type)
    {
        case MED_TYPE_SMF:
        case MED_TYPE_MIDI:
            drv_result = JSmf_Play(self_p->media_handle_p);
            break;
        case MED_TYPE_IMELODY:
            drv_result = JImy_Play(self_p->media_handle_p);
            break;         
    #if defined(JTONE_SUPPORT) && defined(__MED_MMA_MOD__)
        case MED_TYPE_TONE:
            drv_result = JTone_Play(self_p->media_handle_p);
            break;
    #endif /* JTONE_SUPPORT && __MED_MMA_MOD__ */
    #if defined(WAV_CODEC) && defined(__MED_MMA_MOD__)
        case MED_TYPE_WAV:
            drv_result = JWav_Play(self_p->media_handle_p);
            break;
    #endif /* WAV_CODEC && __MED_MMA_MOD__ */
        default:
            drv_result = MEDIA_UNSUPPORTED_OPERATION;
            break;
    }

    _AUD_PLAYER_MMA_TRACE(drv_result, self_p->media_type, self_p->media_handle_p);

    if (drv_result == MEDIA_SUCCESS)
    {
        /* enter AUD_MEDIA_PLAY state */
        self_p->state = AUD_MEDIA_PLAY;
    }
    
    return aud_get_res(drv_result);
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_mma_stop
 * DESCRIPTION
 *  This function is used to stop MMA playback.
 * PARAMETERS
 *  player_p      [IN]        Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_mma_stop(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_mma_t* self_p;
    Media_Status          drv_result = MEDIA_FAIL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(player_p, med_aud_player_mma_t, itf);
    
    /* Stop by media type */
    switch (self_p->media_type)
    {
        case MED_TYPE_SMF:
        case MED_TYPE_MIDI:
            drv_result = JSmf_Stop(self_p->media_handle_p);
            break;
        case MED_TYPE_IMELODY:
            drv_result = JImy_Stop(self_p->media_handle_p);
            break;
    #if defined(JTONE_SUPPORT) && defined(__MED_MMA_MOD__)
        case MED_TYPE_TONE:
            drv_result = JTone_Stop(self_p->media_handle_p);
            break;
    #endif /* JTONE_SUPPORT && __MED_MMA_MOD__ */
    #if defined(WAV_CODEC) && defined(__MED_MMA_MOD__)
        case MED_TYPE_WAV:
            drv_result = JWav_Stop(self_p->media_handle_p);
            break;
    #endif /* WAV_CODEC && __MED_MMA_MOD__ */
        default:
            drv_result = MEDIA_UNSUPPORTED_OPERATION;
            break;
    }

    _AUD_PLAYER_MMA_TRACE(drv_result, self_p->media_type, self_p->media_handle_p);
    
    if (drv_result == MEDIA_SUCCESS)
    {      
        /* enter AUD_MEDIA_IDLE state */
        self_p->state = AUD_MEDIA_IDLE;
    }
    
    return aud_get_res(drv_result);
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_mma_pause
 * DESCRIPTION
 *  This function is used to pause MMA playback.
 * PARAMETERS
 *  player_p      [IN]        Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_mma_pause(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_mma_t* self_p;
    Media_Status          drv_result = MEDIA_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(player_p, med_aud_player_mma_t, itf);
    
    /* Pause by media type */
    switch (self_p->media_type)
    {
        case MED_TYPE_SMF:
        case MED_TYPE_MIDI:
            drv_result = JSmf_Pause(self_p->media_handle_p);
            break;
        case MED_TYPE_IMELODY:
            drv_result = JImy_Pause(self_p->media_handle_p);
            break;     
    #if defined(JTONE_SUPPORT) && defined(__MED_MMA_MOD__)
        case MED_TYPE_TONE:
            drv_result = JTone_Pause(self_p->media_handle_p);
            break;
    #endif /* JTONE_SUPPORT && __MED_MMA_MOD__ */
    #if defined(WAV_CODEC) && defined(__MED_MMA_MOD__)
        case MED_TYPE_WAV:
            drv_result = JWav_Pause(self_p->media_handle_p);
            break;
    #endif /* WAV_CODEC && __MED_MMA_MOD__ */
        default:
            drv_result = MEDIA_UNSUPPORTED_OPERATION;
            break;
    }
    
    _AUD_PLAYER_MMA_TRACE(drv_result, self_p->media_type, self_p->media_handle_p);
    
    if (drv_result == MEDIA_SUCCESS)
    {
        /* enter AUD_MEDIA_PLAY_PAUSED state */
        self_p->state = AUD_MEDIA_PLAY_PAUSED;
    }
    
    return aud_get_res(drv_result);
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_mma_resume
 * DESCRIPTION
 *  This function is used to resume MMA playback.
 * PARAMETERS
 *  player_p      [IN]        Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_mma_resume(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_mma_t* self_p;
    Media_Status          drv_result = MEDIA_NO_HANDLER;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(player_p, med_aud_player_mma_t, itf);
    
    /* Resume by media type */
    switch (self_p->media_type)
    {
        case MED_TYPE_SMF:
        case MED_TYPE_MIDI:
            drv_result = JSmf_Resume(self_p->media_handle_p);
            break;
        case MED_TYPE_IMELODY:
            drv_result = JImy_Resume(self_p->media_handle_p);
            break;     
    #if defined(JTONE_SUPPORT) && defined(__MED_MMA_MOD__)
        case MED_TYPE_TONE:
            drv_result = JTone_Resume(self_p->media_handle_p);
            break;
    #endif /* JTONE_SUPPORT && __MED_MMA_MOD__ */
    #if defined(WAV_CODEC) && defined(__MED_MMA_MOD__)
        case MED_TYPE_WAV:
            drv_result = JWav_Resume(self_p->media_handle_p);
            break;
    #endif /* WAV_CODEC && __MED_MMA_MOD__ */
        default:
            drv_result = MEDIA_UNSUPPORTED_OPERATION;
            break;
    }

    _AUD_PLAYER_MMA_TRACE(drv_result, self_p->media_type, self_p->media_handle_p);
    
    if (drv_result == MEDIA_SUCCESS)
    {
        /* enter AUD_MEDIA_PLAY state */
        self_p->state = AUD_MEDIA_PLAY;
    }
    
    return aud_get_res(drv_result);
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_mma_set
 * DESCRIPTION
 *  This function is used to set parameters to an MMA player.
 * PARAMETERS
 *  player_p      [IN]        Player handle.
 *  set_type      [IN]        Set command.
 *  data_p        [IN]        The data relative to the command.
 *  data_len      [IN]        The length of the data.
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_mma_set(med_aud_player_t*    player_p,
                                     med_aud_player_set_t set_type,
                                     void*                data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_mma_t* self_p;
    Media_Status          drv_result = MEDIA_UNSUPPORTED_OPERATION;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(player_p, med_aud_player_mma_t, itf);

    _AUD_PLAYER_MMA_TRACE(set_type, (kal_uint32)data_p, self_p->media_type);
    
    switch (set_type)
    {
        case AUD_PLAYER_SET_START_TIME:
        {
            kal_int32 start_time = (kal_int32)data_p;
            
            /* Set start time by media type */
            switch (self_p->media_type)
            {
                case MED_TYPE_SMF:
                case MED_TYPE_MIDI:
                    drv_result = JSmf_SetStartTime(self_p->media_handle_p, start_time);
                    break;
                case MED_TYPE_IMELODY:
                    drv_result = JImy_SetStartTime(self_p->media_handle_p, start_time);
                    break;
            #if defined(JTONE_SUPPORT) && defined(__MED_MMA_MOD__)
                case MED_TYPE_TONE:
                    drv_result = JTone_SetStartTime(self_p->media_handle_p, start_time);
                    break;
            #endif /* JTONE_SUPPORT && __MED_MMA_MOD__ */
            #if defined(WAV_CODEC) && defined(__MED_MMA_MOD__)
                case MED_TYPE_WAV:
                    drv_result = JWav_SetStartTime(self_p->media_handle_p, start_time);
                    break;
            #endif /* WAV_CODEC && __MED_MMA_MOD__ */
                default:
                    break;
            } 

            _AUD_PLAYER_MMA2_TRACE(drv_result, start_time);
            
            if (drv_result == MEDIA_SUCCESS)
            {
                self_p->start_time = start_time;
            }
            
            break;
        }
        case AUD_PLAYER_SET_STOP_TIME:
        {
            kal_int32 stop_time = (kal_int32)data_p;
            
            /* Set stop time by media type */
            switch (self_p->media_type)
            {
                case MED_TYPE_SMF:
                case MED_TYPE_MIDI:
                    drv_result = JSmf_SetStopTime(self_p->media_handle_p, stop_time);
                    break;
                case MED_TYPE_IMELODY:
                    drv_result = JImy_SetStopTime(self_p->media_handle_p, stop_time);
                    break;
            #if defined(JTONE_SUPPORT) && defined(__MED_MMA_MOD__)
                case MED_TYPE_TONE:
                    drv_result = JTone_SetStopTime(self_p->media_handle_p, stop_time);
                    break;
            #endif /* JTONE_SUPPORT && __MED_MMA_MOD__ */
            #if defined(WAV_CODEC) && defined(__MED_MMA_MOD__)
                case MED_TYPE_WAV:
                    drv_result = JWav_SetStopTime(self_p->media_handle_p, stop_time);
                    break;
            #endif /* WAV_CODEC && __MED_MMA_MOD__ */
                default:
                    break;
            } 

            _AUD_PLAYER_MMA2_TRACE(drv_result, stop_time);
            
            if (drv_result == MEDIA_SUCCESS)
            {
                self_p->stop_time = stop_time;
            }
            
            break;
        }
        
    #if defined(__MED_MMA_MOD__)
        case AUD_PLAYER_SET_LEVEL:
        {
            kal_uint8 level = (kal_uint8)(kal_uint32)data_p;

            /* Set level by media type */
            switch (self_p->media_type)
            {
                case MED_TYPE_SMF:
                case MED_TYPE_MIDI:
                    drv_result = JMidi_SetLevel(self_p->media_handle_p, level);
                    break;
                case MED_TYPE_IMELODY:
                    drv_result = JImy_SetLevel(self_p->media_handle_p, level);
                    break;
            #if defined(JTONE_SUPPORT) && defined(__MED_MMA_MOD__)
                case MED_TYPE_TONE:
                    drv_result = JTone_SetLevel(self_p->media_handle_p, level);
                    break;
            #endif /* JTONE_SUPPORT && __MED_MMA_MOD__ */
            #if defined(WAV_CODEC) && defined(__MED_MMA_MOD__)
                case MED_TYPE_WAV:
                    drv_result = JWav_SetLevel(self_p->media_handle_p, level);
                    break;
            #endif /* WAV_CODEC && __MED_MMA_MOD__ */
                default:
                    break;
            } 
            
            break;
        }

        /* MMA player specific commands */
        case MMA_PLAYER_SET_DATA:            /* Set data (JTone) */
        {
            med_aud_player_mma_set_data_t* req_p = (med_aud_player_mma_set_data_t*)data_p;
            
            switch (self_p->media_type)
            {
            #if defined(JTONE_SUPPORT)
                case MED_TYPE_TONE:
                    self_p->toneseq_param_p->toneSeq    = req_p->data_p;
                    self_p->toneseq_param_p->toneSeqLen = req_p->size;
                    self_p->toneseq_param_p->repeats    = req_p->repeats;
                    drv_result = MEDIA_SUCCESS;
                    break;
            #endif /* JTONE_SUPPORT */
                default:
                    break;
            }
            break;
        }
        case MMA_PLAYER_SET_PITCH:           /* Set pitch (JTone, JMidi) */
        {
            switch (self_p->media_type)
            {
            #if defined(__MED_MMA_EXTRA_CTRL__)
                case MED_TYPE_SMF:
                case MED_TYPE_MIDI:
                    drv_result = JMidi_SetPitchTranspose(self_p->media_handle_p, (kal_int32)data_p);
                    break;
            #endif /* __MED_MMA_EXTRA_CTRL__ */
            #if defined(JTONE_SUPPORT)
                case MED_TYPE_TONE:
                    drv_result = JTone_SetPitchShift(self_p->media_handle_p, (kal_int8)(kal_int32)data_p);
                    break;
            #endif /* JTONE_SUPPORT */
                default:
                    break;
            }
            
            break;
        }
        case MMA_PLAYER_SET_RATE:            /* Set rate (JTone, JMidi) */
        {
            switch (self_p->media_type)
            {
            #if defined(__MED_MMA_EXTRA_CTRL__)
                case MED_TYPE_SMF:
                case MED_TYPE_MIDI:
                    drv_result = JMidi_SetRate(self_p->media_handle_p, (kal_int32)data_p);
                    break;
            #endif /* __MED_MMA_EXTRA_CTRL__ */
            #if defined(JTONE_SUPPORT)
                case MED_TYPE_TONE:
                    drv_result = JTone_SetRate(self_p->media_handle_p, (kal_int32)data_p);
                    break;
            #endif /* JTONE_SUPPORT */
                default:
                    break;
            }
            
            break;
        }
        case MMA_PLAYER_SET_CHANNEL_VOLUME:  /* Set channel volume (JTone, JMidi) */
        {

		#if defined(__MED_MMA_EXTRA_CTRL__)
           med_aud_player_mma_set_channel_volume_t* req_p = (med_aud_player_mma_set_channel_volume_t*)data_p;
                
            switch (self_p->media_type)
            {
                case MED_TYPE_SMF:
                case MED_TYPE_MIDI:
                    drv_result = JMidi_SetChannelVolume(self_p->media_handle_p, 
                                                        (kal_int8)req_p->channel,
                                                        (kal_uint8)req_p->level);
                    break;
                default:
                    break;
            }
		#endif /* #if defined(__MED_MMA_EXTRA_CTRL__) */
            
            break;
        }
        case MMA_PLAYER_SET_PROGRAM:         /* Set program (JMidi) */
        {
		#if defined(__MED_MMA_EXTRA_CTRL__)
            med_aud_player_mma_set_program_t* req_p = (med_aud_player_mma_set_program_t*)data_p;

            switch (self_p->media_type)
            {
                case MED_TYPE_SMF:
                case MED_TYPE_MIDI:
                    drv_result = JMidi_SetProgram(self_p->media_handle_p,
                                                  (kal_int8)req_p->channel,
                                                  (kal_int16)req_p->bank,
                                                  (kal_int8)req_p->program);
                    break;
                default:
                    break;
            }
		#endif /* #if defined(__MED_MMA_EXTRA_CTRL__) */
            
            break;
        }
        case MMA_PLAYER_SET_TEMPO:           /* Set tempo (JMidi) */
        {
            switch (self_p->media_type)
            {
            #if defined(__MED_MMA_EXTRA_CTRL__)
                case MED_TYPE_SMF:
                case MED_TYPE_MIDI:
                    drv_result = JMidi_SetTempo(self_p->media_handle_p, (kal_int32)data_p);
                    break;
            #endif /* #if defined(__MED_MMA_EXTRA_CTRL__) */
                default:
                    break;
            }
            
            break;
        }
        case MMA_PLAYER_SET_LONG_MSG:        /* Set long message (JMidi) */
        {
		#if defined(__MED_MMA_EXTRA_CTRL__)
            med_aud_player_mma_set_long_msg_t* req_p = (med_aud_player_mma_set_long_msg_t*)data_p;

            switch (self_p->media_type)
            {
                case MED_TYPE_SMF:
                case MED_TYPE_MIDI:
                    drv_result = JMidi_SendLongMsg(self_p->media_handle_p,
                                                   (const kal_uint8*)req_p->buf_p,
                                                   (kal_uint16)req_p->len);
                    break;
                default:
                    break;
            }
		#endif /* #if defined(__MED_MMA_EXTRA_CTRL__) */
            
            break;
        }
        case MMA_PLAYER_SET_SHORT_MSG:       /* Set short message (JMidi) */
        {
		#if defined(__MED_MMA_EXTRA_CTRL__)
            med_aud_player_mma_set_short_msg_t* req_p = (med_aud_player_mma_set_short_msg_t*)data_p;

            switch (self_p->media_type)
            {
                case MED_TYPE_SMF:
                case MED_TYPE_MIDI:
                    drv_result = JMidi_SendShortMsg(self_p->media_handle_p,
                                                    (kal_uint8)req_p->type,
                                                    (kal_uint8)req_p->data1,
                                                    (kal_uint8)req_p->data2);
                    break;
                default:
                    break;
            }
		#endif /* #if defined(__MED_MMA_EXTRA_CTRL__) */
            
            break;
        }
    #endif /* __MED_MMA_MOD__ */
    
        /* Unsupported commands */
        default:
            drv_result = MEDIA_UNSUPPORTED_OPERATION;
            break;
    }
    
    return aud_get_res(drv_result);
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_mma_get
 * DESCRIPTION
 *  This function is used to get parameters from an MMA player.
 * PARAMETERS
 *  player_p      [IN]        Player handle.
 *  get_type      [IN]        Set command.
 *  data_p        [OUT]       The data relative to the command.
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_mma_get(med_aud_player_t*    player_p,
                                     med_aud_player_get_t get_type,
                                     void*                data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_mma_t* self_p;
    kal_int32             med_result = MED_RES_PARAM_ERROR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(player_p, med_aud_player_mma_t, itf);
    
    switch (get_type)
    {
        case AUD_PLAYER_GET_START_TIME:
        {
            {
                *((kal_uint32*)data_p) = self_p->start_time;
                med_result = MED_RES_OK;
            }
            
            break;
        }
        case AUD_PLAYER_GET_STOP_TIME:
        {
            {
                *((kal_uint32*)data_p) = self_p->stop_time;
                med_result = MED_RES_OK;
            }
            
            break;
        }
        case AUD_PLAYER_GET_CURRENT_TIME:
        case AUD_PLAYER_GET_LAST_TIME:
        {
            {
                med_result = MED_RES_OK;
                
                /* Get current time by media type */
                switch (self_p->media_type)
                {
                    case MED_TYPE_SMF:
                    case MED_TYPE_MIDI:
                        *((kal_uint32*)data_p) = JSmf_GetCurrentTime(self_p->media_handle_p);
                        break;
                    case MED_TYPE_IMELODY:
                        *((kal_uint32*)data_p) = JImy_GetCurrentTime(self_p->media_handle_p);
                        break;
                #if defined(JTONE_SUPPORT) && defined(__MED_MMA_MOD__)
                    case MED_TYPE_TONE:
                        *((kal_uint32*)data_p) = JTone_GetCurrentTime(self_p->media_handle_p);
                        break;
                #endif /* JTONE_SUPPORT && __MED_MMA_MOD__ */
                #if defined(WAV_CODEC) && defined(__MED_MMA_MOD__)
                    case MED_TYPE_WAV:
                        *((kal_uint32*)data_p) = JWav_GetCurrentTime(self_p->media_handle_p);
                        break;
                #endif /* WAV_CODEC && __MED_MMA_MOD__ */
                    default:
                        med_result = MED_RES_UNSUPPORTED_OPERATION;
                        break;
                }
            }
            
            break;
        }
        case AUD_PLAYER_GET_DURATION:
        {
            kal_int32 duration = 0;

            {
                med_result = MED_RES_OK;
                
                /* Get duration by media type */
                switch (self_p->media_type)
                {
                    case MED_TYPE_SMF:
                    #ifdef MIDFILE_PLAY_SUPPORT
                        if (self_p->is_direct_fs_opened)
                        {
                            /* We don't support get duration when playing MMA file directly. */
                            med_result = MED_RES_UNSUPPORTED_OPERATION;
                        }
                        else
                    #endif /* MIDFILE_PLAY_SUPPORT */
                        {
                            duration = JSmf_GetDuration(self_p->media_handle_p);
                        }
                        break;
                    case MED_TYPE_MIDI:
                        duration = JSmf_GetDuration(self_p->media_handle_p);
                        break;
                    case MED_TYPE_IMELODY:
                        duration = JImy_GetDuration(self_p->media_handle_p);
                        break;
                #if defined(JTONE_SUPPORT) && defined(__MED_MMA_MOD__)
                    case MED_TYPE_TONE:
                        duration = JTone_GetDuration(self_p->media_handle_p);
                        break;
                #endif /* JTONE_SUPPORT && __MED_MMA_MOD__ */
                #if defined(WAV_CODEC) && defined(__MED_MMA_MOD__)
                    case MED_TYPE_WAV:
                        duration = JWav_GetDuration(self_p->media_handle_p);
                        break;
                #endif /* WAV_CODEC && __MED_MMA_MOD__ */
                    default:
                        med_result = MED_RES_UNSUPPORTED_OPERATION;
                        break;
                }
                
                /* Error handling */
                if (duration < 0)
                {
                    duration = 0;
                    med_result = MED_RES_FAIL;
                }

                *((kal_uint32*)data_p) = (kal_uint32)duration;
            }
            
            break;
        }

    #if defined(__MED_MMA_MOD__)
        case AUD_PLAYER_GET_LEVEL:
        {          
            {
                med_result = MED_RES_OK;
                
                /* Set level by media type */
                switch (self_p->media_type)
                {
                    case MED_TYPE_SMF:
                    case MED_TYPE_MIDI:
                        *((kal_uint8*)data_p) = JMidi_GetLevel(self_p->media_handle_p);
                        break;
                    case MED_TYPE_IMELODY:
                        *((kal_uint8*)data_p) = JImy_GetLevel(self_p->media_handle_p);
                        break;
                #if defined(JTONE_SUPPORT)
                    case MED_TYPE_TONE:
                        *((kal_uint8*)data_p) = JTone_GetLevel(self_p->media_handle_p);
                        break;
                #endif /* JTONE_SUPPORT */
                #if defined(WAV_CODEC)
                    case MED_TYPE_WAV:
                        *((kal_uint8*)data_p) = JWav_GetLevel(self_p->media_handle_p);
                        break;
                #endif /* WAV_CODEC */
                    default:
                        med_result = MED_RES_UNSUPPORTED_OPERATION;
                        break;
                }
            }
            
            break;
        }
        
    #if defined(__MED_MMA_EXTRA_CTRL__)
        case MMA_PLAYER_GET_CHANNEL_VOLUME:
        {
            kal_uint8 volume = 0;
            med_aud_player_mma_get_channel_volume_t* channel_volume_p = (med_aud_player_mma_get_channel_volume_t*)data_p;

            {
                med_result = MED_RES_OK;
                
                switch (self_p->media_type)
                {
                    case MED_TYPE_SMF:
                    case MED_TYPE_MIDI:
                        volume = JMidi_GetChannelVolume(self_p->media_handle_p, channel_volume_p->channel);
                        break;
                    default:
                        med_result = MED_RES_UNSUPPORTED_OPERATION;
                        break;
                }

                *(channel_volume_p->volume_p) = volume;
            }

            break;
        }
        case MMA_PLAYER_GET_PITCH:
        {
            kal_int32 pitch = 0;

            {
                med_result = MED_RES_OK;
                
                switch (self_p->media_type)
                {
                    case MED_TYPE_SMF:
                    case MED_TYPE_MIDI:
                        pitch = JMidi_GetPitchTranspose(self_p->media_handle_p);
                        break;
                #ifdef JTONE_SUPPORT
                    case MED_TYPE_TONE:
                        pitch = (kal_int32)JTone_GetPitchShift(self_p->media_handle_p);
                        break;
                #endif /* JTONE_SUPPORT */
                    default:
                        med_result = MED_RES_UNSUPPORTED_OPERATION;
                        break;
                }

                *((kal_int32*)data_p) = pitch;
            }
            
            break;
        }

        case MMA_PLAYER_GET_RATE:
        {
            kal_int32 rate = 0;

            {
                med_result = MED_RES_OK;
                
                switch (self_p->media_type)
                {
                    case MED_TYPE_SMF:
                    case MED_TYPE_MIDI:
                        rate = JMidi_GetRate(self_p->media_handle_p);
                        break;
                #ifdef JTONE_SUPPORT
                    case MED_TYPE_TONE:
                        rate = JTone_GetRate(self_p->media_handle_p);
                        break;
                #endif /* JTONE_SUPPORT */
                    default:
                        med_result = MED_RES_UNSUPPORTED_OPERATION;
                        break;
                }

                *((kal_int32*)data_p) = rate;
            }
            
            break;
        }

        case MMA_PLAYER_GET_TEMPO:
        {
            kal_int32 tempo = 0;

            {
                med_result = MED_RES_OK;
                
                switch (self_p->media_type)
                {
                    case MED_TYPE_SMF:
                    case MED_TYPE_MIDI:
                        tempo = JMidi_GetTempo(self_p->media_handle_p);
                        break;
                    default:
                        med_result = MED_RES_UNSUPPORTED_OPERATION;
                        break;
                }

                *((kal_int32*)data_p) = tempo;
            }
            
            break;
        }

        case MMA_PLAYER_GET_PROGRAM:
        {
            med_aud_player_mma_get_program_t* program_p = (med_aud_player_mma_get_program_t*)data_p;

            {
                med_result = MED_RES_OK;
                
                switch (self_p->media_type)
                {
                    case MED_TYPE_SMF:
                    case MED_TYPE_MIDI:
                        JMidi_GetProgram(self_p->media_handle_p,
                                         program_p->channel,
                                         program_p->bank_p,
                                         program_p->program_p);
                        break;
                    default:
                        med_result = MED_RES_UNSUPPORTED_OPERATION;
                        break;
                }
            }
            
            break;
        }

        case MMA_PLAYER_GET_BANK_LIST:
        {
            med_aud_player_mma_get_bank_list_t* bank_list_p = (med_aud_player_mma_get_bank_list_t*)data_p;

            {
                med_result = MED_RES_OK;
                
                switch (self_p->media_type)
                {
                    case MED_TYPE_SMF:
                    case MED_TYPE_MIDI:
                        JMidi_GetBankList(bank_list_p->custom,
                                          bank_list_p->buf_p,
                                          bank_list_p->len_p);
                        break;
                    default:
                        med_result = MED_RES_UNSUPPORTED_OPERATION;
                        break;
                }
            }
            
            break;
        }


        case MMA_PLAYER_GET_PROGRAM_LIST:
        {
            med_aud_player_mma_get_program_list_t* program_list_p = (med_aud_player_mma_get_program_list_t*)data_p;

            {
                med_result = MED_RES_OK;
                
                switch (self_p->media_type)
                {
                    case MED_TYPE_SMF:
                    case MED_TYPE_MIDI:
                        JMidi_GetProgramList(program_list_p->bank,
                                             program_list_p->buf_p,
                                             program_list_p->len_p);
                        break;
                    default:
                        med_result = MED_RES_UNSUPPORTED_OPERATION;
                        break;
                }
            }
            
            break;
        }
        case MMA_PLAYER_GET_PROGRAM_NAME:
        {
            const kal_uint8* name_p = NULL;
            med_aud_player_mma_get_program_name_t* program_name_p = (med_aud_player_mma_get_program_name_t*)data_p;

            {
                med_result = MED_RES_OK;
                
                switch (self_p->media_type)
                {
                    case MED_TYPE_SMF:
                    case MED_TYPE_MIDI:
                        name_p = JMidi_GetProgramName(program_name_p->bank,
                                                      program_name_p->program);
                        break;
                    default:
                        med_result = MED_RES_UNSUPPORTED_OPERATION;
                        break;
                }

                *(program_name_p->name_p) = name_p;
            }
            
            break;
        }

        case MMA_PLAYER_GET_KEY_NAME:
        {
            const kal_uint8* name_p = NULL;
            med_aud_player_mma_get_key_name_t* key_name_p = (med_aud_player_mma_get_key_name_t*)data_p;

            {
                med_result = MED_RES_OK;
                
                switch (self_p->media_type)
                {
                    case MED_TYPE_SMF:
                    case MED_TYPE_MIDI:
                        name_p = JMidi_GetKeyName(key_name_p->bank,
                                                  key_name_p->program,
                                                  key_name_p->key);
                        break;
                    default:
                        med_result = MED_RES_UNSUPPORTED_OPERATION;
                        break;
                }

                *(key_name_p->name_p) = name_p;
            }
            
            break;
        }

        case MMA_PLAYER_GET_IS_BANK_SUPPORT:
        {
            kal_bool is_bank_support = KAL_FALSE;

            {
                med_result = MED_RES_OK;
                
                switch (self_p->media_type)
                {
                    case MED_TYPE_SMF:
                    case MED_TYPE_MIDI:
                        is_bank_support = JMidi_isBankQuerySupported();
                        break;
                    default:
                        med_result = MED_RES_UNSUPPORTED_OPERATION;
                        break;
                }

                *((kal_bool*)data_p) = is_bank_support;
            }
            
            break;
        }

        case MMA_PLAYER_GET_IS_SP_MIDI:
        {
            kal_bool is_sp_midi = KAL_FALSE;

            {
                med_result = MED_RES_OK;
                
                switch (self_p->media_type)
                {
                    case MED_TYPE_SMF:
                    case MED_TYPE_MIDI:
                        is_sp_midi = JSmf_isSpMidi(self_p->media_handle_p);
                        break;
                    default:
                        med_result = MED_RES_UNSUPPORTED_OPERATION;
                        break;
                }

                *((kal_bool*)data_p) = is_sp_midi;
            }
            
            break;
        }
    #endif /* __MED_MMA_EXTRA_CTRL__ */
    #endif /* __MED_MMA_MOD__ */

#ifdef __MED_IMY_EVENT__        
        /* MMA player specific commands */
        case MMA_PLAYER_GET_EXT_EVENT:  /* Extended event (JSmf) */
        {
            Media_Event event;
            kal_int32   note;

            {
                event = JSmf_QueryExtEvent(self_p->media_handle_p, &note);
                
                _AUD_PLAYER_MMA_TRACE(self_p->media_handle_p, event, note);
                
                *((Media_Event*)data_p) = event;

                med_result = MED_RES_OK;
            }
            
            break;
        }
#endif

        /* Unsupported commands */
        default:
            med_result = MED_RES_UNSUPPORTED_OPERATION;
            break;
    }

    _AUD_PLAYER_MMA_TRACE(get_type, med_result, *((kal_uint32*)data_p));
    
    return med_result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_mma_destroy
 * DESCRIPTION
 *  This function is used to destroy a MMA player. Once called, all the 
 *  allocated interfaces of the player will be freed.
 * PARAMETERS
 *  player_p      [IN]        Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_mma_destroy(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_mma_t* self_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(player_p, med_aud_player_mma_t, itf);
    
    AUD_PLAYER_FREE_AUD_MEM(self_p);
    
    return MED_RES_OK;
}
#endif /* __MTK_TARGET__ && __MED_DSP_WT_SYN__ */

/*-----------------------------------------------------------------------------
                    public functions
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  aud_player_mma_construct
 * DESCRIPTION
 *  This function is used to construct a MMA player.
 * PARAMETERS
 *  void
 * RETURNS
 *  Player handle.
 *****************************************************************************/
med_aud_player_t* aud_player_mma_construct(void)
{
#if defined(__MTK_TARGET__) && defined(__MED_DSP_WT_SYN__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_mma_t* self_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = (med_aud_player_mma_t*) med_alloc_aud_mem(sizeof(med_aud_player_mma_t));
    MED_ASSERT(self_p != NULL);

    kal_mem_set(self_p, 0, sizeof(*self_p));

    self_p->itf.open      = _aud_player_mma_open;
    self_p->itf.close     = _aud_player_mma_close;
    self_p->itf.play      = _aud_player_mma_play;
    self_p->itf.stop      = _aud_player_mma_stop;
    self_p->itf.pause     = _aud_player_mma_pause;
    self_p->itf.resume    = _aud_player_mma_resume;
    self_p->itf.set       = _aud_player_mma_set;
    self_p->itf.get       = _aud_player_mma_get;
    self_p->itf.destroy   = _aud_player_mma_destroy;

    kal_get_time(&self_p->time_stamp);

    return &self_p->itf;
#else
    return NULL;
#endif /* __MTK_TARGET__ && __MED_DSP_WT_SYN__ */
}

#endif /* MED_NOT_PRESENT */ 

