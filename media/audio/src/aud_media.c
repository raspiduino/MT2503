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
 *   aud_media.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes media related functions of audio manager task.
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
 * removed!
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
 *    AUD_MEDIA
 * DESCRIPTION
 *    This module defines the media related function for Audio Manager.
 *  
 ******************************************************************/

#ifndef MED_NOT_PRESENT

/*-----------------------------------------------------------------------------
                    include files
-----------------------------------------------------------------------------*/
//#include "kal_release.h"
#include "kal_trace.h"
//#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
//#include "syscomp_config.h"
//#include "task_config.h"        /* Task creation */
//#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
//#include "event_shed.h" /* Event scheduler */
//#include "stack_timer.h"        /* Stack timer */
//#include "app_buff_alloc.h"

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
//#include "fat_fs.h"
/* DRM_REPLACE */
//#include "drm_gprot.h"

//#include "nvram_enums.h"
//#include "nvram_struct.h"
//#include "nvram_user_defs.h"
//#include "nvram_data_items.h"
//#include "custom_nvram_editor_data_item.h"
//#include "custom_equipment.h"

#include "FSAL.h"
//#include "MP4_Parser.h"

#ifdef MP4_DECODE
//#include "MP4_Producer_Audio.h"
//#include "MP4_Sample_Data_Audio.h"
//#include "drv_comm.h"
//#include "visual_comm.h"
//#include "lcd_if.h"
//#include "rtc_sw.h"
//#include "bmd.h"
//#include "video_enc_glb.h"
//#include "video_dec_glb.h"
//#include "video_comm_glb.h" 
#endif /* MP4_DECODE */ 

/* local includes */
#include "med_global.h"
//#include "med_status.h"
#include "aud_defs.h"
#include "med_struct.h"
//#include "med_v_struct.h"
#include "med_v_main.h"
#include "med_api.h"
#include "med_context.h"
#include "med_main.h"
#include "aud_main.h"
#include "med_utility.h"
#include "aud_player.h"
#include "aud_player_mp4.h"
#include "aud_bt_hfp.h"

#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
//#include "kal_active_module.h"
#include "stack_config.h"
//#include "kurotypedef.h"
#include "common_nvram_editor_data_item.h"

#if defined(__MED_VID_DEC_MOD__)
#include "vid_main.h"
#endif /* defined(__MED_VID_DEC_MOD__) */

#if defined(__MED_STREAM_MOD__)
#include "stream.h"
#endif /* __MED_STREAM_MOD__ */

#if defined(__MED_MTV_MOD__) || defined(__MED_ATV_MOD__) || defined(__STREAM_REC_SUPPORT__)
#include "mtv_main.h"
#endif /* defined(__MED_MTV_MOD__) || defined(__MED_ATV_MOD__) || defined(__STREAM_REC_SUPPORT__) */

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

//#include "aud_daf_parser.h"
//#include "aud_amr_parser.h"
#ifdef __RICH_AUDIO_PROFILE__
extern volatile kal_mutexid audio_input_stream_mutex;   /* from aud_input_stream.c */
#endif 

kal_bool notify_poweroff= KAL_FALSE;

/*-----------------------------------------------------------------------------
                    macros, defines, typedefs, enums
-----------------------------------------------------------------------------*/
#define _AUD_MODULE_MEDIA_TRACE(x, y, z)   AUD_MODULE_MEDIA_TRACE(x, y, z, __LINE__)
#define _AUD_MODULE_MEDIA2_TRACE(x, y)   AUD_MODULE_MEDIA2_TRACE(x, y, __LINE__)


/* Player configuration */
#define PLAYER_CFG_NONE               (kal_uint32) 0x00000000 /* None of the configurations will be applied. */
#define PLAYER_CFG_ALL                (kal_uint32) 0xffffffff /* All the the configurations will be applied. */
#define PLAYER_CFG_START_TIME         (kal_uint32) 0x00000001 /* To set start time, this flag must be on. */
#define PLAYER_CFG_STOP_TIME          (kal_uint32) 0x00000002 /* To set end time, this falg must be on. */
#define PLAYER_CFG_CRESCENDO_TIMER    (kal_uint32) 0x00000004 /* If on, the crescendo timer will be triggered when starting the playback. */
#define PLAYER_CFG_RESTORE            (kal_uint32) 0x00000008 /* If on, the saved offset/time will be restored before playback. */
#define PLAYER_CFG_CACHE_TABLE        (kal_uint32) 0x00000010 /* To set cache table, this flag must be on. */

typedef struct
{
    kal_uint32  flag;              /* Specify the fields to be applied */
    kal_uint32  start_time;        /* Specify the start time. 0 means play from the beginning. Valid only if PLAYER_CFG_START_TIME is on. */
    kal_uint32  stop_time;         /* Specify the end time. 0 means play until EOF. Valid only if PLAYER_CFG_STOP_TIME in on. */
    void*       cache_p;           /* Cache table. Valid only if PLAYER_CFG_CACHE_TABLE is on. */
    
} aud_media_player_cfg_t;

typedef struct
{
    kal_uint8   play_style;
    kal_uint8   play_mode;
    kal_int16   current_format;
    kal_uint32  last_time;
    kal_uint32  last_offset;
    kal_uint32  temp_last_time;    /* for store/restore */
    kal_uint32  temp_last_offset;  /* for store/restore */
    void*       cache_p;
} aud_media_context_struct;

/*-----------------------------------------------------------------------------
                    data declaraions
 ----------------------------------------------------------------------------*/
static aud_media_context_struct aud_media_ctx;

/*-----------------------------------------------------------------------------
                    function prototypes
 ----------------------------------------------------------------------------*/ 
#ifdef __MED_IMY_EVENT__
extern void aud_melody_event_hdlr(med_aud_player_t* player_p, Media_Event e_event);
#endif

static kal_int32 _aud_media_player_play(med_aud_player_t* player_p, aud_media_player_cfg_t* cfg_p);
static kal_int32 _aud_media_player_stop(med_aud_player_t* player_p);
static kal_int32 _aud_media_player_pause(med_aud_player_t* player_p);
static kal_int32 _aud_media_player_resume(med_aud_player_t* player_p);
static kal_int32 _aud_media_player_close(med_aud_player_t* player_p);

/*-----------------------------------------------------------------------------
                    private function declarations
 ----------------------------------------------------------------------------*/

/*****************************************************************************
 * FUNCTION
 *  _aud_media_player_close
 * DESCRIPTION
 *  This function is a general handler to close a given opened player and 
 *  release allocated resources for the player.
 * PARAMETERS
 *  player_p           [IN]    Player handler 
 * RETURNS
 *****************************************************************************/
static kal_int32 _aud_media_player_close(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Special handling for active player */
    if (player_p == aud_context_p->player_p)
    {
        /* Reset player */
        aud_context_p->player_p = NULL;
    }

    /* Close the player */
    player_p->close(player_p);
    player_p->destroy(player_p);

    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  _aud_media_player_stop
 * DESCRIPTION
 *  This function is to stop the currently opened player. Note that only the
 *  currently opened player is allowed to be stopped because we don't support
 *  multiple playbacks.
 * PARAMETERS
 *  player_p         [IN]     Player handle.
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_media_player_stop(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Store last time/file offset */
    player_p->get(player_p, AUD_PLAYER_GET_LAST_TIME, &aud_media_ctx.temp_last_time);//, sizeof(kal_uint32));
    player_p->get(player_p, AUD_PLAYER_GET_LAST_OFFSET, &aud_media_ctx.temp_last_offset);//, sizeof(kal_uint32));    

    /* Stop the play */
    result = player_p->stop(player_p);
    _AUD_MODULE_MEDIA2_TRACE(result, player_p);

#if !defined(MED_V_NOT_PRESENT) && defined(__MTK_TARGET__)

    /* Stop building cache in non-blocking manner. This is to prevent MED from being
     * blocked by the MED-V. However, we have to signal the MED-V that the build cache
     * is already stopped here. Othewise, the MED-V may keep processing queued events
     * and result in unexpected side effects.
     */
    if (aud_media_ctx.cache_p != NULL)
    {
        /* Stop previous build cache process */
        aud_build_cache_stop();

        /* Close build cache in non-blocking way */
        media_aud_close_build_cache_in_async(kal_get_active_module_id());
        
        aud_media_ctx.cache_p = NULL;
    }

#endif /* ! MED_V_NOT_PRESENT && __MTK_TARGET__ */

#ifdef __MED_IMY_EVENT__
    /* Special handler for iMelody playback */
    if (aud_media_ctx.current_format == MED_TYPE_IMELODY ||
        aud_media_ctx.current_format == MED_TYPE_SMF)
    {
        aud_melody_stop_driver();
    }
#endif

    /* Enter IDLE state */
    aud_enter_state(AUD_MEDIA_IDLE);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  _aud_media_player_stop_and_close
 * DESCRIPTION
 *  This function is to stop and close at the same time
 * PARAMETERS
 *  player_p         [IN]     Player handle.
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_media_player_stop_and_close(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    _aud_media_player_stop(player_p);
    _aud_media_player_close(player_p);

}


/*****************************************************************************
 * FUNCTION
 *  _aud_media_player_stop_req_hdlr
 * DESCRIPTION
 *  This function is to handle the stop request for currently opened player/
 *  recorder.
 * PARAMETERS
 *  is_stop_unfinished    [IN]    Indicate if it's to stop unfinished task.
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_media_player_stop_req_hdlr(kal_bool is_stop_unfinished)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    _AUD_MODULE_MEDIA_TRACE(aud_context_p->state, aud_context_p->source_type, is_stop_unfinished);
    
    switch (aud_context_p->state)
    {
        case AUD_MEDIA_PLAY:
        case AUD_MEDIA_PLAY_PAUSED:
        case AUD_MEDIA_SEEK_PAUSED:
        {
            /* Check source type */
            if (aud_context_p->source_type > AUD_STRING)
            {
            #ifdef __MED_GENERAL_TTS__
                if (aud_context_p->source_type == AUD_TTS)
                {
                    aud_tts_stop();
                }
            #endif
            }
            else
            {
                /* Stop and close the player */
                _aud_media_player_stop_and_close(aud_context_p->player_p);
            }
            
            break;
        }
#if defined(__MED_AUD_REC_MOD__)
    #ifdef VM_LOG
        case AUD_VM_RECORD:
        {
            /* Stop VM logging */
            aud_vm_stop_logging();
            break;
        }
    #endif /* VM_LOG */
        case AUD_MEDIA_RECORD:
        case AUD_MEDIA_RECORD_PAUSED:
    #ifdef __MED_VCALL_MOD__
        case AUD_MEDIA_WAIT_RECORD:
    #endif /*__MED_VCALL_MOD__*/
        {

            /* Stop recording. If the record is stopped by interruption,
             * MMI will get notify if it's in record state.
             */
            aud_rec_stop_record(is_stop_unfinished);
            
            break;
        }
#endif /*__MED_AUD_REC_MOD__*/
        default:
        {
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  _aud_media_player_event_hdlr
 * DESCRIPTION
 *  This function is called back by player when end-of-play or something error.
 *  This function should notify MMI with interested events, e.g. play error,
 *  play end, etc. Also note that this function is executed by using MED thread,
 *  i.e. no context switch is requried.
 * PARAMETERS
 *  player_p           [IN]    Player handler
 *  event              [IN]    Media event
 *  param              [IN]    User data (the pv_callback_param of med_aud_player_cfg_t)
 * RETURNS
 *****************************************************************************/
static void _aud_media_player_event_hdlr(med_aud_player_t* player_p, Media_Event event, void* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32  result;
    kal_uint16 id = (kal_uint16)(kal_uint32)param;
    kal_uint32 duration;
    aud_media_player_cfg_t cfg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (aud_context_p->state != AUD_MEDIA_PLAY)
    {
        _AUD_MODULE_MEDIA2_TRACE(aud_context_p->state, player_p);
        return;
    }

    _AUD_MODULE_MEDIA_TRACE(event, aud_media_ctx.play_style, player_p);

    switch (event)
    {
        case MEDIA_NONE:
        case MEDIA_BUFFER_UNDERFLOW:
            /* do nothing */
            break;
        case MEDIA_UPDATE_DUR: /* update duration */
        {
            if (aud_media_ctx.cache_p == NULL)
            {
                return;
            }
            
            switch (aud_media_ctx.current_format)
            {
                case MED_TYPE_WAV:
                case MED_TYPE_WAV_DVI_ADPCM:
                case MED_TYPE_AMR:
                case MED_TYPE_AMR_WB:
                case MED_TYPE_DAF:
                case MED_TYPE_KURO:
                case MED_TYPE_MUSICAM:
                case MED_TYPE_AAC:
                case MED_TYPE_BSAC:
                    player_p->get(player_p, AUD_PLAYER_GET_DURATION, &duration);

                    /* Send update duration indicator to MMI */
                    aud_send_update_duration_ind(duration);
                    break;
                default:
                    break;
            }
            break;
        }
        case MEDIA_REPEATED: /* play repeated */
        #ifdef __MED_IMY_EVENT__
            /* Stop iMelody driver */
            if (aud_media_ctx.current_format == MED_TYPE_IMELODY ||
                aud_media_ctx.current_format == MED_TYPE_SMF)
            {
                aud_melody_stop_driver();
            }
        #endif
            break;
    #ifdef __MED_IMY_EVENT__
        case MEDIA_EXTENDED_EVENT:
        case MEDIA_LED_ON:
        case MEDIA_LED_OFF:
        case MEDIA_VIBRATOR_ON:
        case MEDIA_VIBRATOR_OFF:
        case MEDIA_BACKLIGHT_ON:
        case MEDIA_BACKLIGHT_OFF:
            /* Call melody event handler */
            aud_melody_event_hdlr(player_p, event);
            break;
    #endif
        
        default: /* other events */
        {
            /* Stop the player */
            _aud_media_player_stop(aud_context_p->player_p);

            /* Replay if required */       
            if ((event == MEDIA_END || event == MEDIA_STOP_TIME_UP) && (aud_media_ctx.play_style != DEVICE_AUDIO_PLAY_ONCE))
            {
                cfg.flag = PLAYER_CFG_NONE;

                if (!aud_context_p->audio_mute)
                {
                    /* Update ring tone volume */
                    aud_set_active_ring_tone_volume();
                }
                
                result = _aud_media_player_play(player_p, &cfg);

                if (result == MED_RES_OK)
                {
                    return; /* Directly return if replay successfully */
                }

                /* If replay failed, we should send play-indicator to MMI. Hence, continue the codes. */
            }
            else /* No replay */
            {
                /* Close the player */
                _aud_media_player_close(aud_context_p->player_p);
            }

            /* Send play-indicator to MMI */
            if ((event == MEDIA_END || event == MEDIA_STOP_TIME_UP) && (aud_media_ctx.play_style == DEVICE_AUDIO_PLAY_ONCE))
            {
                result = MED_RES_END_OF_FILE;
            }
            else if (event == MEDIA_DECODER_UNSUPPORT)
            {
                result = MED_RES_DECODER_NOT_SUPPORT;
            }
            else
            {
                result = MED_RES_ERROR;
            }

            aud_send_audio_play_finish_ind((kal_uint8)result, id);

            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  _aud_media_player_get_repeat_count_by_play_style
 * DESCRIPTION
 *  
 * PARAMETERS
 *  play_style      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint8 _aud_media_player_get_repeat_count_by_play_style(kal_uint8 ui1_play_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 repeat_count = 1;  /* Play once */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ui1_play_style)
    {
        case DEVICE_AUDIO_PLAY_CRESCENDO:
        case DEVICE_AUDIO_PLAY_INFINITE:
            repeat_count = 0;    /* Play infinitely */
            break;
    }

    return repeat_count;
}


/*****************************************************************************
 * FUNCTION
 *  _aud_media_player_open
 * DESCRIPTION
 *  This function is to open a handler for all the types of playback, 
 *  including play-by-file and play-by-data-string.
 * PARAMETERS
 * file_name        [IN]      File name. If not NULL, the pui1_data will be ignored.
 * data_p           [IN]      Media data. If ws_file_name is NULL, this pointer must not be NULL.
 * data_len         [IN]      The length of media data. Valid only if pui1_data is not NULL.
 * format           [IN]      Media format.
 * play_style       [IN]      Play style(audio_play_style_enum).
 * audio_path       [IN]      Audio path.
 * cb_fct           [IN]      Callback function.
 * cb_param         [IN]      Callback parameter.
 * player_pp        [OUT]     Player handle.
 * RETURNS
 *  MED_RES_OK                Successful.
 *  Others                    Failed.
 *****************************************************************************/
static kal_int32 _aud_media_player_open(kal_wchar*            file_name,
                                        kal_uint8*            data_p,
                                        kal_uint32            data_len,
                                        kal_int16             format,
                                        kal_uint8             play_style,
                                        kal_uint8             audio_path,
                                        med_aud_player_cb_fct cb_fct,
                                        void*                 cb_param,
                                        med_aud_player_t**    player_pp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_cfg_t player_cfg;
    med_aud_player_t* player_p = NULL;
    kal_int32 result = MED_RES_FAIL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    
    /* Construct a player */
    switch (format)
    {
    #ifdef __VM_CODEC_SUPPORT__    
        case MED_TYPE_GSM_FR:
        case MED_TYPE_GSM_HR:
        case MED_TYPE_GSM_EFR:
        case MED_TYPE_VR:
    #endif /*__VM_CODEC_SUPPORT__*/

    #ifdef WAV_CODEC
        case MED_TYPE_PCM_8K:
        case MED_TYPE_PCM_16K:
        case MED_TYPE_G711_ALAW:
        case MED_TYPE_G711_ULAW:
        case MED_TYPE_DVI_ADPCM:
        case MED_TYPE_WAV:
        case MED_TYPE_WAV_ALAW:
        case MED_TYPE_WAV_ULAW:
        case MED_TYPE_WAV_DVI_ADPCM:
    #endif /* WAV_CODEC */
    
    #ifdef DAF_DECODE
        case MED_TYPE_DAF:
    #ifdef MUSICAM_DECODE
        case MED_TYPE_MUSICAM:
    #endif /* MUSICAM_DECODE */
    #endif /* DAF_DECODE */
        
    #ifdef AMR_DECODE
        case MED_TYPE_AMR:
    #ifdef AMRWB_DECODE
        case MED_TYPE_AMR_WB:
    #endif /* AMRWB_DECODE */
    #endif /* AMR_DECODE */
    
    #ifdef AIFF_DECODE
        case MED_TYPE_AIFF:
    #endif /* AIFF_DECODE */
    
    #ifdef AU_DECODE
        case MED_TYPE_AU:
    #endif /* AU_DECODE */ 
    
    #ifdef AAC_DECODE
        case MED_TYPE_AAC:
    #endif /* AAC_DECODE */
    
    #ifdef BSAC_DECODE
/* under construction !*/
    #endif /* BSAC_DECODE */
    
    #ifdef WMA_DECODE
        case MED_TYPE_WMA:
    #endif /* WMA_DECODE */

    #ifdef __APE_DECODE__
        case MED_TYPE_APE:
    #endif /* __APE_DECODE__ */

    #ifdef __VORBIS_DECODE__
        case MED_TYPE_VORBIS:
    #endif /*__VORBIS_DECODE__*/
    #ifdef __FLAC_DECODE__
        case MED_TYPE_FLAC:
    #endif
            player_p = aud_player_media_construct();
            break;

        case MED_TYPE_SMF:
        case MED_TYPE_MMF:
        case MED_TYPE_IMELODY:
            player_p = aud_player_mma_construct();
            break;

#ifdef __MED_MPL_PLAYER__
#if defined(MED_PURE_AUDIO) //|| defined(MP4_DECODE)
        case MED_TYPE_3GP:
        case MED_TYPE_MP4:
#endif /* MED_PURE_AUDIO || MP4_DECODE */
#ifdef M4A_DECODE
        case MED_TYPE_M4A:
#endif /* M4A_DECODE */

    /* If __MED_IN_ASM__ is defined, we should use MMA interface to play PML files */
#if !defined(__MED_IN_ASM__) || (defined(__MED_IN_ASM__) && defined(__PLUTO_MMI_PACKAGE__))
    #ifdef __RM_DEC_SUPPORT__
        case MED_TYPE_RA:
        case MED_TYPE_RM:
        case MED_TYPE_RMVB:
        case MED_TYPE_RV:
    #endif /*__RM_DEC_SUPPORT */

    #ifdef __FLV_FILE_FORMAT_SUPPORT__
        case MED_TYPE_FLV:
        case MED_TYPE_F4V:
        case MED_TYPE_F4A:
    #endif /*__FLV_FILE_FORMAT_SUPPORT__*/
#endif /*!__MED_IN_ASM__ || __MED_IN_ASM__ && __PLUTO_MMI_PACKAGE__ */
            player_p = aud_player_mpl_construct();
            break;
#endif /*__MED_MPL_PLAYER__*/

        default:
            break;
    }
    
#else /*__MTK_TARGET__*/

    player_p = aud_player_modis_construct();

#endif  /*__MTK_TARGET__*/
    
    if (player_p != NULL)
    {    
        /* Configure the player */
        player_cfg.file_name   = file_name;
        player_cfg.data_p      = data_p;
        player_cfg.data_len    = data_len;
        player_cfg.format      = (kal_uint8)format;
        player_cfg.repeat      = _aud_media_player_get_repeat_count_by_play_style(play_style);
        player_cfg.audio_path  = audio_path;
        player_cfg.fast_pass   = KAL_FALSE;
        player_cfg.cb_fct      = cb_fct;
        player_cfg.cb_param    = cb_param;

        /* Open a player */
        result = player_p->open(player_p, &player_cfg);
        _AUD_MODULE_MEDIA2_TRACE(result, player_p);

        /* Remember to destroy the player if failed to open */
        if (result != MED_RES_OK)
        {
            player_p->destroy(player_p);
            player_p = NULL;
        }
    }

    /* Copy out player handler */
    *player_pp = player_p;
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  _aud_media_player_play
 * DESCRIPTION
 *  This function is to play the currently opened player. Note that only the
 *  currently opened player is allowed to be played because we don't support
 *  multiple playbacks.
 * PARAMETERS
 *  player_p         [IN]     Player handle.
 *  cfg_p            [IN]     Play configuration.
 * RETURNS
 *  MED_RES_OK            Successful.
 *  Others                Failed.
 *****************************************************************************/
static kal_int32 _aud_media_player_play(med_aud_player_t* player_p, aud_media_player_cfg_t* cfg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /*--------------- Configure the player ------------------------*/
    /* Set cache table */
    if ((cfg_p->flag & PLAYER_CFG_CACHE_TABLE) && cfg_p->cache_p)
    {
        med_aud_player_set_cache_t set_cache_p;
        set_cache_p.cache_p = cfg_p->cache_p;
        set_cache_p.cache_size = AUD_CACHE_TABLE_SIZE;
        player_p->set(player_p, AUD_PLAYER_SET_CACHE_TABLE, (void*)&set_cache_p);
    }
    
    /* Restore */
    if (cfg_p->flag & PLAYER_CFG_RESTORE)
    {
        /* This is tricky. For the file formats(MP3/AAC) that support both file offset and start 
         * time settings, the file offset will take priority. For other formats (MP4, WMA, ...) 
         * Only the start time will take effect.
         */
        player_p->set(player_p, AUD_PLAYER_SET_STORE_FLAG,  (void*)KAL_TRUE);
        player_p->set(player_p, AUD_PLAYER_SET_FILE_OFFSET, (void*)aud_media_ctx.last_offset);
        player_p->set(player_p, AUD_PLAYER_SET_START_TIME,  (void*)aud_media_ctx.last_time);
    }
    else
    {
        /* Turn off store-flag to avoid unexpected restore. */
        player_p->set(player_p, AUD_PLAYER_SET_STORE_FLAG, (void*)KAL_FALSE);
    }
    
    /* Set start time */
    if ((cfg_p->flag & PLAYER_CFG_START_TIME) && (cfg_p->start_time != 0))
    {
        player_p->set(player_p, AUD_PLAYER_SET_START_TIME, (void*)cfg_p->start_time);
    }
    
    /* Set stop time */
    if ((cfg_p->flag & PLAYER_CFG_STOP_TIME) && (cfg_p->stop_time != 0))
    {
        player_p->set(player_p, AUD_PLAYER_SET_STOP_TIME, (void*)cfg_p->stop_time);
    }
    
    /*--------------- Enf of configuration ------------------------*/

    /* Start the play */
    result = player_p->play(player_p);
    _AUD_MODULE_MEDIA2_TRACE(result, player_p);
    
    if (result == MED_RES_OK)
    {
        /* Enter PLAY state */
        aud_enter_state(AUD_MEDIA_PLAY);
    }
    else
    {
        /* Stop and close the player if failed to play. Note that the stop command is required
         * because we may fail to play from the seek-paused state.
         */
        _aud_media_player_stop_and_close(player_p);
    }
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  _aud_media_player_pause
 * DESCRIPTION
 *  This function is to pause the currently opened handler. Note that only the
 *  currently opened player is allowed to be paused because we don't support
 *  multiple playbacks.
 * PARAMETERS
 *  player_p         [IN]     Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_media_player_pause(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_UNSUPPORTED_OPERATION;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (aud_context_p->state == AUD_MEDIA_PLAY)
    {
        result = player_p->pause(player_p);
        _AUD_MODULE_MEDIA2_TRACE(result, player_p);

    #ifdef __MED_IMY_EVENT__
        /* Special handler for iMelody playback */
        if (aud_media_ctx.current_format == MED_TYPE_IMELODY ||
            aud_media_ctx.current_format == MED_TYPE_SMF)
        {
            aud_store_driver_status();
            aud_melody_stop_driver();
        }
    #endif    

        if (result == MED_RES_OK)
        {
            /* Enter PLAY_PAUSED state */
            aud_enter_state(AUD_MEDIA_PLAY_PAUSED);
        }
        else if (result == MED_RES_UNSUPPORTED_OPERATION) /* Some formats do not support PAUSE function, e.g AAC-ADIF */
        {
            /* Do nothing because the player state is not changed */
        }
        else
        {
            /* Stop and close the player if failed to pause */
            _aud_media_player_stop_and_close(player_p);
        }
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  _aud_media_player_resume
 * DESCRIPTION
 *  This function is to resume the currently opened handler. Note that only the
 *  currently opened player is allowed to be resumed because we don't support
 *  multiple playbacks.
 * PARAMETERS
 *  player_p         [IN]     Player handle.  
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_media_player_resume(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_FAIL;
    aud_media_player_cfg_t cfg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MED_IMY_EVENT__
    /* Special handler for IMY playback */
    if (aud_media_ctx.current_format == MED_TYPE_IMELODY ||
        aud_media_ctx.current_format == MED_TYPE_SMF)
    {
        aud_restore_driver_status();
    }
#endif
    
    if (aud_context_p->state == AUD_MEDIA_SEEK_PAUSED)
    {
        /* Play from seek position */
        cfg.flag = PLAYER_CFG_NONE;
        
        result = _aud_media_player_play(player_p, &cfg);
    }
    else if (aud_context_p->state == AUD_MEDIA_PLAY_PAUSED)
    {
        /* Resume from paused position */
        result = player_p->resume(player_p);
        _AUD_MODULE_MEDIA_TRACE(result, player_p, aud_context_p->state);
        
        if (result == MED_RES_OK)
        {
            /* Enter PLAY state */
            aud_enter_state(AUD_MEDIA_PLAY);
        }
        else
        {
            /* Stop and close the player if failed to resume */
            _aud_media_player_stop_and_close(player_p);
        }
    }

    return result;
}

/*-----------------------------------------------------------------------------
                    public functions
 ----------------------------------------------------------------------------*/

#if defined(__MED_AUD_REC_MOD__)

/*****************************************************************************
 * FUNCTION
 *  aud_media_record_req_hdlr
 * DESCRIPTION
 *  This function is to handle the audio record request.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_record_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_media_record_req_struct *msg_p = (l4aud_media_record_req_struct*) ilm_ptr->local_para_ptr;
    kal_uint8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_MEDIA_RECORD_REQ_HDLR);
    
    aud_context_p->src_mod = ilm_ptr->src_mod_id;
    aud_context_p->src_id = msg_p->src_id;

    result = aud_rec_start_record(ilm_ptr);

    aud_set_result_and_event((kal_int32)result,AUD_EVT_RECORD);
    
    /* send confirm message to L4 */
    if (aud_context_p->src_mod != MOD_MMI)
    {
        aud_send_media_record_cnf(result);
    }
}

#endif /* __MED_AUD_REC_MOD__ */


/*****************************************************************************
 * FUNCTION
 *  aud_stop_unfinished_process
 * DESCRIPTION
 *  This function is to stop unfinished media process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_stop_unfinished_process(void)
{
    _aud_media_player_stop_req_hdlr(KAL_TRUE);
}

/*****************************************************************************
 * FUNCTION
 *  aud_stop_unfinished_audio
 * DESCRIPTION
 *  Stop unfinished audio.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_stop_unfinished_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_MEDIA_STOP_UNFINISHED_AUDIO);

    /* if keytone is playing, stop it */
    aud_keytone_stop();

    /* if tone is playing, stop it */
    if (aud_context_p->tone_playing)
    {
        aud_tone_stop();
    }

#if defined( __MED_MMA_MOD__)&&(!defined(__MED_SLIM_MMA__))
    /* close all mma tasks */
    aud_mma_close_all();
#endif /* __MED_MMA_MOD__ */ 

    aud_stop_unfinished_process();

}



/*****************************************************************************
 * FUNCTION
 *  aud_media_player_play_req
 * DESCRIPTION
 *  This function is a general handler to handle various play requests.
 * PARAMETERS
 *  req_p        [IN]     Play request.
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 aud_media_player_play_req(aud_media_player_play_req_t* req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_BUSY;
    aud_media_player_cfg_t cfg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->speech_on == KAL_TRUE ||
        aud_context_p->state == AUD_MEDIA_RECORD ||
        aud_context_p->state == AUD_MEDIA_RECORD_PAUSED ||
        aud_context_p->state == AUD_MEDIA_WAIT_RECORD ||
        aud_context_p->state == AUD_VM_RECORD)
    {
        return MED_RES_BUSY;
    }
    
    if (! aud_media_is_resource_available(AUD_RESOURCE_AUDIO))
    {
        return MED_RES_BUSY;
    }

    aud_stop_unfinished_audio();

    aud_context_p->source_type   = (aud_source_type_enum)req_p->source_type;
    aud_media_ctx.play_mode      = req_p->play_mode;
    aud_media_ctx.play_style     = req_p->play_style;
    aud_media_ctx.current_format = req_p->format;
    aud_context_p->identifier    = req_p->identifier;
    aud_media_ctx.cache_p        = req_p->cache_p;

    /* Set media volume and output path */
    SET_CURRENT_VOLUME_LEVEL(AUD_VOLUME_MEDIA, req_p->volume);
    aud_get_active_device_path_by_mode(req_p->output_path,aud_melody_set_output_device);

    /* Update volume */
    aud_set_active_ring_tone_volume();
    
    switch (aud_media_ctx.current_format)
    {
        case MED_TYPE_SMF:
        case MED_TYPE_MMF:
        case MED_TYPE_IMELODY:

    #ifdef __VM_CODEC_SUPPORT__
        case MED_TYPE_GSM_FR:
        case MED_TYPE_GSM_HR:
        case MED_TYPE_GSM_EFR:
        case MED_TYPE_VR:
    #endif /*__VM_CODEC_SUPPORT__*/

    #ifdef WAV_CODEC
        case MED_TYPE_PCM_8K:
        case MED_TYPE_PCM_16K:
        case MED_TYPE_G711_ALAW:
        case MED_TYPE_G711_ULAW:
        case MED_TYPE_DVI_ADPCM:
        case MED_TYPE_WAV:
        case MED_TYPE_WAV_ALAW:
        case MED_TYPE_WAV_ULAW:
        case MED_TYPE_WAV_DVI_ADPCM:
    #endif /* WAV_CODEC */
    
    #ifdef DAF_DECODE
        case MED_TYPE_DAF:
    #ifdef MUSICAM_DECODE
        case MED_TYPE_MUSICAM:
    #endif /* MUSICAM_DECODE */
    #endif /* DAF_DECODE */
        
    #ifdef AMR_DECODE
        case MED_TYPE_AMR:
    #ifdef AMRWB_DECODE
        case MED_TYPE_AMR_WB:
    #endif /* AMRWB_DECODE */
    #endif /* AMR_DECODE */
    
    #ifdef AIFF_DECODE
        case MED_TYPE_AIFF:
    #endif /* AIFF_DECODE */
    
    #ifdef AU_DECODE
        case MED_TYPE_AU:
    #endif /* AU_DECODE */ 
    
    #ifdef AAC_DECODE
        case MED_TYPE_AAC:
    #endif /* AAC_DECODE */
    
    #ifdef BSAC_DECODE
/* under construction !*/
    #endif /* BSAC_DECODE */
    
    #ifdef WMA_DECODE
        case MED_TYPE_WMA:
    #endif /* WMA_DECODE */
    
    #ifdef M4A_DECODE
        case MED_TYPE_M4A:
    #endif /* M4A_DECODE */

#if defined(MED_PURE_AUDIO) //|| defined(MP4_DECODE)
        case MED_TYPE_3GP:
        case MED_TYPE_MP4:
#endif /* MED_PURE_AUDIO || MP4_DECODE */

    #ifdef __APE_DECODE__
        case MED_TYPE_APE:
    #endif /* __APE_DECODE__ */

    #ifdef __VORBIS_DECODE__
        case MED_TYPE_VORBIS:
    #endif /*__VORBIS_DECODE__*/
    #ifdef __FLAC_DECODE__
        case MED_TYPE_FLAC:
    #endif

/* If __MED_IN_ASM__ is defined, we should use MMA interface to play mpl files */
#if !defined(__MED_IN_ASM__) || (defined(__MED_IN_ASM__) && defined(__PLUTO_MMI_PACKAGE__))
    #ifdef __RM_DEC_SUPPORT__
        case MED_TYPE_RA:
        case MED_TYPE_RM:
        case MED_TYPE_RMVB:
        case MED_TYPE_RV:
    #endif /* __RM_DEC_SUPPORT */
            
    #ifdef __FLV_FILE_FORMAT_SUPPORT__
        case MED_TYPE_FLV:
        case MED_TYPE_F4V:
        case MED_TYPE_F4A:
    #endif /*__FLV_FILE_FORMAT_SUPPORT__*/
#endif /* !__MED_IN_ASM__ || __MED_IN_ASM__) && __PLUTO_MMI_PACKAGE__ */
            result = _aud_media_player_open(req_p->file_name,
                                            req_p->data_p,
                                            req_p->data_len,
                                            aud_media_ctx.current_format,
                                            aud_media_ctx.play_style,
                                            req_p->output_path,
                                            _aud_media_player_event_hdlr,
                                            (void*)aud_context_p->identifier,
                                            &aud_context_p->player_p);
            
            _AUD_MODULE_MEDIA_TRACE(result, aud_context_p->player_p, aud_media_ctx.current_format);
									
            if (result == MED_RES_OK)
            {
                /* Configure the player */
                cfg.flag = PLAYER_CFG_NONE;

                if (req_p->is_restore)
                {
                    cfg.flag |= PLAYER_CFG_RESTORE;
                }
                if (req_p->start_offset > 0)
                {
                    cfg.flag |= PLAYER_CFG_START_TIME;
                    cfg.start_time = req_p->start_offset;
                }
                if (req_p->end_offset > 0)
                {
                    cfg.flag |= PLAYER_CFG_STOP_TIME;
                    cfg.stop_time = req_p->end_offset;
                }
                if (req_p->cache_p != NULL)
                {
                    cfg.flag |= PLAYER_CFG_CACHE_TABLE;
                    cfg.cache_p = req_p->cache_p;
                }

            #if defined(__MED_BT_A2DP_MOD__) && defined(__BTMTK__)
                aud_bt_a2dp_open_codec((kal_int32)aud_media_ctx.current_format);
            #endif

                /* Start playback */
                result = _aud_media_player_play(aud_context_p->player_p, &cfg);
                _AUD_MODULE_MEDIA2_TRACE(result, aud_context_p->player_p);

				/*fix power off 3-5 delay*/
				if(notify_poweroff==KAL_TRUE)
           		{				
					Media_PowerOff();
					notify_poweroff=KAL_FALSE;
				}
                /* DO NOT auto build cache for low cost project because the build cache process requires
                 * both CPU and memory resource. With limited resources, to auto build cache may dramatically
                 * drag down the performance [MAUI_02862998].
                 */
            #if !defined(MED_V_NOT_PRESENT) && defined(__MTK_TARGET__)
                if (result == MED_RES_OK && aud_media_ctx.cache_p != NULL)
                {
                    if (aud_media_is_build_cache_required(req_p->file_name))
                    {
                        /* Start build cache in non-blocking way */
                        media_aud_start_build_cache_in_async(kal_get_active_module_id(),
                                                             req_p->file_name,
                                                             req_p->cache_p,
                                                             AUD_CACHE_TABLE_SIZE,
                                                             NULL,
                                                             NULL);
                    }
                    else
                    {
                        aud_media_ctx.cache_p = NULL; /* No need to build cache */
                    }
                }
            #endif /* ! MED_V_NOT_PRESENT && __MTK_TARGET__ */
            }
            break;

        default:
            result = MED_RES_INVALID_FORMAT;
            break;
    }

    return result;
}


#if defined(__MED_AUD_FS_ACCESS__)
/*****************************************************************************
 * FUNCTION
 *  aud_media_play_req_hdlr
 * DESCRIPTION
 *  This function is to handle the audio play request.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_play_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    aud_media_player_play_req_t req;
    media_aud_play_by_file_req_struct *msg_p = (media_aud_play_by_file_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_MEDIA_PLAY_REQ_HDLR);

    aud_context_p->src_mod = ilm_ptr->src_mod_id;
    aud_context_p->src_id = msg_p->src_id;

    /* Configure play request */
    req.source_type  = AUD_FILE;
    req.play_mode    = AUD_MEDIA_PLAY_AS_SONG;
    req.file_name    = msg_p->file_name;
    req.data_p       = NULL;
    req.data_len     = 0;
    req.format       = med_get_media_type(msg_p->file_name);
    req.play_style   = msg_p->play_style;
    req.volume       = msg_p->volume;
    req.output_path  = msg_p->output_path;
    req.identifier   = msg_p->identifier;
    req.start_offset = msg_p->start_offset;
    req.end_offset   = msg_p->end_offset;
    req.cache_p      = msg_p->cache_p;
    req.is_restore   = KAL_FALSE;

    /* Play with the request */
    result = aud_media_player_play_req(&req);

    aud_set_result_and_event(result,AUD_EVT_PLAY);
    
    if (aud_context_p->src_mod != MOD_MMI)
    {
        aud_send_media_play_cnf(result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_stop_req_hdlr
 * DESCRIPTION
 *  This function is to handle the audio stop request.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 res = MED_RES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->src_mod = ilm_ptr->src_mod_id;

    _aud_media_player_stop_req_hdlr(KAL_FALSE);
    
    /* set event to let caller go */
    aud_set_event(AUD_EVT_STOP);

    /* send confirm message to L4 */
    if (aud_context_p->src_mod != MOD_MMI)
    {
        aud_send_media_stop_cnf(res, NULL);
    }
}
#endif /* __MED_AUD_FS_ACCESS__ */


/*****************************************************************************
 * FUNCTION
 *  aud_media_pause_req_hdlr
 * DESCRIPTION
 *  This function is to handle the audio pause request.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_pause_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    l4aud_media_pause_req_struct *msg_p = (l4aud_media_pause_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_MEDIA_PAUSE_REQ_HDLR);

    aud_context_p->src_mod = ilm_ptr->src_mod_id;
    aud_context_p->src_id = msg_p->src_id;

    switch (aud_context_p->state)
    {
#if defined(__MED_AUD_REC_MOD__)
        case AUD_MEDIA_RECORD:
        {
            /* Pause record */
            result = aud_rec_pause_record();
            
            break;
        }
#endif /*__MED_AUD_REC_MOD__*/

        case AUD_MEDIA_PLAY:
        {
            /* Pause play */
            result = _aud_media_player_pause(aud_context_p->player_p);
            
            break;
        }
        default:
        {
            result = MED_RES_FAIL;
            break;
        }
    }

    aud_set_result_and_event(result,AUD_EVT_PAUSE);
    
    /* send confirm message to L4 */
    if (aud_context_p->src_mod != MOD_MMI)
    {
        aud_send_media_pause_cnf((kal_uint8)result, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_resume_req_hdlr
 * DESCRIPTION
 *  This function is to handle the audio resume request.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_resume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    l4aud_media_resume_req_struct *msg_p = (l4aud_media_resume_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_MEDIA_RESUME_REQ_HDLR);

    aud_context_p->src_mod = ilm_ptr->src_mod_id;
    aud_context_p->src_id = msg_p->src_id;

    switch (aud_context_p->state)
    {
#if defined(__MED_AUD_REC_MOD__)
        case AUD_MEDIA_RECORD_PAUSED:
        {
        /* Change speech to BT earphone in case BT turn off by keytone */
        #if defined(__MED_BT_AUDIO_VIA_SCO__) || defined(__MED_BT_FM_VIA_SCO__)
            if (aud_bt_hfp_is_audio_path_on() && !aud_bt_hfp_is_speech_path_on())
            {
                aud_bt_hfp_set_speech_path_on();
            }
        #endif /* #ifdef __BT_AUDIO_VIA_SCO__ */
        
            result = aud_rec_resume_record();
            break;
        }
#endif /*__MED_AUD_REC_MOD__*/

        case AUD_MEDIA_PLAY_PAUSED:
        case AUD_MEDIA_SEEK_PAUSED:
        {
            /* Update media volume and output path */            
            aud_get_active_device_path_by_mode(aud_context_p->melody_output_device, aud_melody_set_output_device);
            aud_set_active_ring_tone_volume();

        #if defined(__MED_BT_A2DP_MOD__) && defined(__BTMTK__)
            aud_bt_a2dp_open_codec((kal_int32)aud_media_ctx.current_format);
        #endif

            /* Resume the play */
            result = _aud_media_player_resume(aud_context_p->player_p);
        
            break;
        }
        default:
        {
            result = MED_RES_FAIL;
            break;
        }
    }

    aud_set_result_and_event(result,AUD_EVT_RESUME);

    /* send confirm message to L4 */
    if (aud_context_p->src_mod != MOD_MMI)
    {
        aud_send_media_resume_cnf((kal_uint8)result);
    }
}


#if defined(__MED_AUD_FS_ACCESS__)
/*****************************************************************************
 * FUNCTION
 *  aud_media_store_req_hdlr
 * DESCRIPTION
 *  This function is to handle the audio pause request.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_store_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_OK;
    l4aud_media_store_req_struct *msg_p = (l4aud_media_store_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->src_mod = ilm_ptr->src_mod_id;
    aud_context_p->src_id = msg_p->src_id;

    switch (aud_context_p->state)
    {
        case AUD_MEDIA_PLAY:
        case AUD_MEDIA_PLAY_PAUSED:
        case AUD_MEDIA_SEEK_PAUSED:
        {
            /* Stop and close the player */
            _aud_media_player_stop_and_close(aud_context_p->player_p);

            /* Store last time/offset */
            aud_media_ctx.last_time   = aud_media_ctx.temp_last_time;
            aud_media_ctx.last_offset = aud_media_ctx.temp_last_offset;
            
            break;
        }
        case AUD_MEDIA_IDLE:
        {
            /* Store last time/offset */
            aud_media_ctx.last_time   = aud_media_ctx.temp_last_time;
            aud_media_ctx.last_offset = aud_media_ctx.temp_last_offset;
            
            break;
        }
        default:
        {
            result = MED_RES_FAIL;
            break;
        }

    }

    aud_set_result_and_event(result,AUD_EVT_PAUSE);
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_restore_req_hdlr
 * DESCRIPTION
 *  This function is to handle the audio resume request.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_restore_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    l4aud_media_restore_req_struct *msg_p = (l4aud_media_restore_req_struct*) ilm_ptr->local_para_ptr;
    aud_media_player_play_req_t req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->src_mod = ilm_ptr->src_mod_id;
    aud_context_p->src_id = msg_p->src_id;

    /* Configure play request */
    req.source_type  = AUD_FILE;
    req.play_mode    = AUD_MEDIA_PLAY_AS_SONG;
    req.file_name    = msg_p->file_name;
    req.data_p       = NULL;
    req.data_len     = 0;
    req.format       = med_get_media_type(msg_p->file_name);
    req.play_style   = msg_p->play_style;
    req.volume       = msg_p->volume;
    req.output_path  = msg_p->output_path;
    req.identifier   = msg_p->identifier;
    req.start_offset = msg_p->start_offset;
    req.end_offset   = msg_p->end_offset;
    req.cache_p      = msg_p->cache_p;
    req.is_restore   = KAL_TRUE;

    /* Play with the request */
    result = aud_media_player_play_req(&req);

    aud_set_result_and_event(result,AUD_EVT_RESUME);

}
#endif /*__MED_AUD_FS_ACCESS__*/

/*****************************************************************************
 * FUNCTION
 *  aud_media_get_desc_func_pointer
 * DESCRIPTION
 *  This function is to get the drscription function provided by driver
 * PARAMETERS
 *  file_name     [IN]    filename
 *  duration      [OUT]   output duration
 * RETURNS
 * kal_uint8   result
 *****************************************************************************/
void* aud_media_get_desc_func_pointer(kal_int16 format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_get_info_func_ptr getdesFunc = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (format)
    {
    #ifdef __MED_DSP_WT_SYN__
        case MED_TYPE_SMF:
            getdesFunc = JSmf_GetContentDescInfo;
            break;
        case MED_TYPE_IMELODY:
            getdesFunc = JImy_GetContentDescInfo;
            break;
    #endif

    #ifdef DAF_DECODE
        case MED_TYPE_DAF:
    #ifdef MUSICAM_DECODE
        case MED_TYPE_MUSICAM:
    #endif
            getdesFunc = DAF_GetContentDescInfo;
            break;
    #endif /* DAF_DECODE */
    #ifdef AMR_DECODE
        case MED_TYPE_AMR:
        case MED_TYPE_AMR_WB:
            getdesFunc = AMR_GetContentDescInfo;
            break;
    #endif /* AMR_DECODE */
    #ifdef WAV_CODEC
        case MED_TYPE_WAV:
        case MED_TYPE_WAV_DVI_ADPCM:
            getdesFunc = WAV_GetContentDescInfo;
            break;
    #endif /*WAV_CODEC*/
    #ifdef AIFF_DECODE
        case MED_TYPE_AIFF:
            getdesFunc = AIFF_GetContentDescInfo;
            break;
    #endif /* AIFF_DECODE */
    #ifdef AU_DECODE
        case MED_TYPE_AU:
            getdesFunc = AU_GetContentDescInfo;
            break;
    #endif /* AU_DECODE */
    #ifdef AAC_DECODE
        case MED_TYPE_AAC:
        case MED_TYPE_BSAC:
            getdesFunc = AAC_GetContentDescInfo;
            break;
    #endif /* AAC_DECODE */
    #ifdef WMA_DECODE
        case MED_TYPE_WMA:
            getdesFunc = WMA_GetContentDescInfo;
            break;
    #endif /* WMA_DECODE */

    #if defined(MED_PURE_AUDIO) //|| defined(MP4_DECODE)
        case MED_TYPE_MP4:
        case MED_TYPE_3GP:
            getdesFunc = MP4S_GetContentDescInfo;
            break;
    #endif /* MED_PURE_AUDIO || MP4_DECODE */

    #ifdef M4A_DECODE
        case MED_TYPE_M4A:
            getdesFunc = MP4S_GetContentDescInfo;
            break;
    #endif /* M4A_DECODE */
    
     /* If __MED_IN_ASM__ is defined, we should use MMA interface to get the duration of MPL files */
    #ifdef __RM_DEC_SUPPORT__
        case MED_TYPE_RA:
        case MED_TYPE_RM:
        case MED_TYPE_RMVB:
        case MED_TYPE_RV:
            getdesFunc = RM_GetContentDescInfo;
            break;
    #endif /* defined(__RM_DEC_SUPPORT__) */

    #ifdef __FLV_FILE_FORMAT_SUPPORT__
        case MED_TYPE_FLV:
        case MED_TYPE_F4V:
        case MED_TYPE_F4A:
            getdesFunc = FLV_GetContentDescInfo;
            break;
    #endif /*__FLV_FILE_FORMAT_SUPPORT__*/

    #ifdef WAV_CODEC
        case MED_TYPE_PCM_8K:
        case MED_TYPE_PCM_16K:
            getdesFunc = PCM_GetContentDescInfo;
            break;
    #endif /*WAV_CODEC*/
    #ifdef __VM_CODEC_SUPPORT__
        case MED_TYPE_GSM_EFR:
            getdesFunc = VM_GetContentDescInfo;
            break;
    #endif /*__VM_CODEC_SUPPORT__*/
    #ifdef __APE_DECODE__
        case MED_TYPE_APE:
            getdesFunc = APE_GetContentDescInfo;
            break;
    #endif /* __APE_DECODE__ */
    #ifdef __VORBIS_DECODE__
        case MED_TYPE_VORBIS:
            getdesFunc = VORBIS_GetContentDescInfo;
            break;
    #endif /*__VORBIS_DECODE__*/
    #ifdef __FLAC_DECODE__
         case MED_TYPE_FLAC:
            getdesFunc = FLAC_GetContentDescInfo;
            break;
    #endif


        default:
            break;
    }

    return (void*)getdesFunc;
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_get_duration_req_hdlr
 * DESCRIPTION
 *  This function is to get the data length of the audio file playing
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  
 *****************************************************************************/
void aud_media_get_duration_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_get_duration_req_struct* msg_p = (media_aud_get_duration_req_struct*) ilm_ptr->local_para_ptr;
    kal_int32                          result = MED_RES_FAIL;
    med_aud_player_t*                  player_p = NULL;
    kal_uint32                         duration = 0;
    kal_int16                          format = MED_TYPE_NONE;
    audInfoStruct*                     aud_info_p = NULL;
    kal_wchar*                         file_name = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__

    if (msg_p->use_default_handle == KAL_FALSE)
    {
    #if defined(LOW_COST_SUPPORT)
        /* This is important because we may not have sufficient memory to open two MP4 handlers. */
        if (aud_context_p->state != AUD_MEDIA_IDLE)
        {
            result = MED_RES_BUSY;
            goto get_duration_result;
        }
    #endif /* LOW_COST_SUPPORT */
        
        /* Determine file format */
        if (msg_p->audio_data != NULL)
        {
            format = msg_p->format;
        }
        else
        {
            format = med_get_media_type(msg_p->file_name);
            file_name = msg_p->file_name;
        }
        
        /* Note that when playing an audio file, MMI may browse META information
         * of the other audio files in the playlist. To fulfill this scenario,
         * we have to create a temporary player for retrieving the duartion, 
         * and release the temporary player when the process is complete.
         */
        result = _aud_media_player_open(file_name,
                                        msg_p->audio_data,
                                        msg_p->len,
                                        format,
                                        0, /* play style - don't care */
                                        0, /* audio path - don't care */
                                        NULL,
                                        NULL,
                                        &player_p);

        if (result == MED_RES_OK && player_p != NULL)
        {
            switch (format)
            {
                case MED_TYPE_SMF:
                case MED_TYPE_MMF:
                case MED_TYPE_IMELODY:
                {
                    result = player_p->get(player_p, AUD_PLAYER_GET_DURATION, &duration);
                    _AUD_MODULE_MEDIA2_TRACE(result, player_p);
                    
                    break;
                }
                    

            #ifdef __RM_DEC_SUPPORT__
                case MED_TYPE_RA:
                case MED_TYPE_RM:
                case MED_TYPE_RMVB:
                case MED_TYPE_RV:
            #endif /* __RM_DEC_SUPPORT */

            #ifdef __FLV_FILE_FORMAT_SUPPORT__
                case MED_TYPE_FLV:
                case MED_TYPE_F4V:
                case MED_TYPE_F4A:
            #endif /*__FLV_FILE_FORMAT_SUPPORT__*/
            /* If __MED_IN_ASM__ is defined, we should use MMA interface to get the duration 
             * of MPL files (app_id is required). If __MED_IN_ASM__ is not defined, we could 
             * get the duration of MPL files from content descriptor.
             */
                #if defined(__MED_IN_ASM__) && !defined(__PLUTO_MMI_PACKAGE__) && (defined(__RM_DEC_SUPPORT__) || defined(__FLV_FILE_FORMAT_SUPPORT__))
                    break;
                #endif /* __MED_IN_ASM__ && !__PLUTO_MMI_PACKAGE__*/
            
                default:
                {
                    /* Allocate buffer for content description */
                    aud_info_p = (audInfoStruct*) get_ctrl_buffer(sizeof(audInfoStruct));

                    /* Get duration from content descriptor */
                    result = player_p->get(player_p, AUD_PLAYER_GET_CONTENT_DESC, aud_info_p);//, sizeof(audInfoStruct));
                    _AUD_MODULE_MEDIA2_TRACE(result, player_p);

                    if (result == MED_RES_OK)
                    {
                        duration = aud_info_p->time;
                    }

                    /* Remember to free the buffer */
                    free_ctrl_buffer(aud_info_p);
                    
                    break;
                }
            }

            _AUD_MODULE_MEDIA2_TRACE(duration, player_p);

            /* Remember to close the temporary handler */
            _aud_media_player_close(player_p);
        }
    }
    else /* Get duration by using current-opened player handle */
    {
        if (aud_context_p->player_p) /* Audio may have been stopped when MMI tries to get duration. */
        {
            result = aud_context_p->player_p->get(aud_context_p->player_p, AUD_PLAYER_GET_DURATION, &duration);
            _AUD_MODULE_MEDIA2_TRACE(result, aud_context_p->player_p);
        }
    }

#else /* #ifndef __MTK_TARGET__ */

    /* Open a temporary MoDIS */
    result = _aud_media_player_open(msg_p->file_name,
                                    msg_p->audio_data,
                                    msg_p->len,
                                    format,
                                    0, /* play style - don't care */
                                    0, /* audio path - don't care */
                                    NULL,
                                    NULL,
                                    &player_p);

    if (result == MED_RES_OK && player_p != NULL)
    {
        result = player_p->get(player_p, AUD_PLAYER_GET_DURATION, &duration);
        _AUD_MODULE_MEDIA2_TRACE(result, player_p);

        /* Remember to close the temporary player */
        _aud_media_player_close(player_p);
    }
    
#endif /* __MTK_TARGET__ */

#ifdef LOW_COST_SUPPORT
get_duration_result:
#endif
    aud_set_pair_results(result, duration);
    aud_set_event(AUD_EVT_GET_DURATION);
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_get_progress_time_req_hdlr
 * DESCRIPTION
 *  This function is to get the progress of the audio file playing
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  kal_uint8(?)
 *****************************************************************************/
void aud_media_get_progress_time_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_FAIL;
    kal_uint32 crnt_time = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (aud_context_p->state)
    {
        case AUD_MEDIA_PLAY:
        case AUD_MEDIA_PLAY_PAUSED:
            /*if (aud_media_ctx.play_mode == AUD_MEDIA_PLAY_AS_SONG)*/
            {
                switch( aud_media_ctx.current_format )
                {
                #ifdef __MED_DSP_WT_SYN__
                    case MED_TYPE_SMF:
                    case MED_TYPE_MMF:
                    case MED_TYPE_IMELODY:
                #endif /* __MED_DSP_WT_SYN__ */
                #ifdef DAF_DECODE
                    case MED_TYPE_DAF:
                #ifdef MUSICAM_DECODE
                    case MED_TYPE_MUSICAM:
                #endif
                #endif /* DAF_DECODE */
                #ifdef AMR_DECODE
                    case MED_TYPE_AMR:
                #ifdef AMRWB_DECODE
                    case MED_TYPE_AMR_WB:
                #endif 
                #endif /* AMR_DECODE */ 
                #ifdef __VM_CODEC_SUPPORT__
                    case MED_TYPE_GSM_EFR:
                #endif /*__VM_CODEC_SUPPORT__*/
                #ifdef WAV_CODEC
                    case MED_TYPE_PCM_8K:
                    case MED_TYPE_PCM_16K:
                    case MED_TYPE_DVI_ADPCM:
                    case MED_TYPE_WAV:
                    case MED_TYPE_WAV_DVI_ADPCM:
                #endif /* WAV_CODEC */
                #ifdef AIFF_DECODE
                    case MED_TYPE_AIFF:
                #endif
                #ifdef AU_DECODE
                    case MED_TYPE_AU:
                #endif
                #ifdef AAC_DECODE
                    case MED_TYPE_AAC:
                #endif 
                #if defined(BSAC_DECODE)
/* under construction !*/
                #endif
                #ifdef WMA_DECODE
                    case MED_TYPE_WMA:
                #endif
                #if defined(M4A_DECODE)
                    case MED_TYPE_M4A:
                #endif
                #ifdef __APE_DECODE__
                    case MED_TYPE_APE:
                #endif
                #ifdef __VORBIS_DECODE__
                    case MED_TYPE_VORBIS:
                #endif
                #ifdef __FLAC_DECODE__
                    case MED_TYPE_FLAC:
                #endif
                #if defined(MED_PURE_AUDIO) //|| defined(MP4_DECODE)
                    case MED_TYPE_3GP:
                    case MED_TYPE_MP4:
                #endif /* MED_PURE_AUDIO || MP4_DECODE */
                
                /* If __MED_IN_ASM__ is defined, we should use MMA interface to get the duration of MPL files */
                #if !defined(__MED_IN_ASM__) || (defined(__MED_IN_ASM__) && defined(__PLUTO_MMI_PACKAGE__))
                  #ifdef __RM_DEC_SUPPORT__
                    case MED_TYPE_RA:
                    case MED_TYPE_RM:
                    case MED_TYPE_RMVB:
                    case MED_TYPE_RV:
                #endif /* __RM_DEC_SUPPORT */

                  #ifdef __FLV_FILE_FORMAT_SUPPORT__
                    case MED_TYPE_FLV:
                    case MED_TYPE_F4V:
                    case MED_TYPE_F4A:
                  #endif /*__FLV_FILE_FORMAT_SUPPORT__*/
                #endif /* !__MED_IN_ASM__ || __MED_IN_ASM__ &&  __PLUTO_MMI_PACKAGE__ */

                        result = aud_context_p->player_p->get(aud_context_p->player_p, AUD_PLAYER_GET_CURRENT_TIME, &crnt_time);//, sizeof(kal_uint32));
                        break;
                        
                    default:
                        break;
                }
            }
            break;
        default:
            break;
    }

    aud_set_pair_results(result, crnt_time);
    aud_set_event(AUD_EVT_GET_PROGRESS_TIME);
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_set_progress_time_req_hdlr
 * DESCRIPTION
 *  This function is to set the progress of the audio file playing
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  kal_uint8(?)
 *****************************************************************************/
void aud_media_set_progress_time_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_FAIL;
    kal_uint8 state;
    media_aud_set_progress_time_req_struct *msg_p = (media_aud_set_progress_time_req_struct*) ilm_ptr->local_para_ptr;
    aud_media_player_cfg_t cfg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* This is important because the aud_context_p->state will be changed to IDLE state when stopping the play */
    state = aud_context_p->state;
    
    switch (state)
    {
        case AUD_MEDIA_PLAY:
        case AUD_MEDIA_PLAY_PAUSED:
        case AUD_MEDIA_SEEK_PAUSED:
        {
            /*if (aud_media_ctx.play_mode == AUD_MEDIA_PLAY_AS_SONG)*/
            {
                /* Stop the play first */
                result = _aud_media_player_stop(aud_context_p->player_p);
                _AUD_MODULE_MEDIA2_TRACE(result, aud_context_p->player_p);

                if (result == MED_RES_OK)
                {
                    /* Set start time */
                    result = aud_context_p->player_p->set(aud_context_p->player_p,
                                                          AUD_PLAYER_SET_START_TIME,
                                                          (void*)msg_p->progress);
                    _AUD_MODULE_MEDIA2_TRACE(result, aud_context_p->player_p);

                    if (state == AUD_MEDIA_PLAY)
                    {
                        /* Continue the play from seek position */
                        cfg.flag = PLAYER_CFG_NONE;

                        result = _aud_media_player_play(aud_context_p->player_p, &cfg);
                        _AUD_MODULE_MEDIA2_TRACE(result, aud_context_p->player_p);
                    }
                    else if (state == AUD_MEDIA_PLAY_PAUSED)
                    {
                        /* Enter seek-paused state */
                        aud_enter_state(AUD_MEDIA_SEEK_PAUSED);
                    }
                }
                else
                {
                    /* Close the player */
                    _aud_media_player_close(aud_context_p->player_p);
                }
            }
            break;
        }
        default:
            break;
    }

    aud_set_result_and_event(result,AUD_EVT_SET_PROGRESS_TIME);

}


/*****************************************************************************
 * FUNCTION
 *  aud_media_play_by_id_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_play_by_id_req_hdlr(ilm_struct *ilm_ptr)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    kal_uint8 audio_id;
    kal_uint8 audio_out_device;    
    kal_uint8 volume;
    media_aud_play_by_id_req_struct *req_p = (media_aud_play_by_id_req_struct*) ilm_ptr->local_para_ptr;
#ifdef DUMMY_CNF
    media_aud_play_by_id_cnf_struct *cnf_p = NULL;
#endif /* DUMMY_CNF */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    audio_id = req_p->audio_id;

#ifdef __GAIN_TABLE_SUPPORT__
    /* Use user-specified path */
    audio_out_device = req_p->output_path;
#else
    if (req_p->output_path == AUDIO_DEVICE_SPEAKER2)
    {
        /* Use default configuration */
        aud_cfg_audio_out_device(audio_id, &audio_out_device);
    }
    else
    {
        /* Use user-specified path */
        audio_out_device = req_p->output_path;
    }
#endif /* __GAIN_TABLE_SUPPORT__ */

    if (audio_id <= TONE_KEY_CLICK)
    {
        aud_keytone_stop();

        /* Update keytone volume */
    #ifndef __GAIN_TABLE_SUPPORT__
	
    	volume = aud_get_volume_gain(aud_context_p->audio_mode, AUD_VOLUME_KEY, req_p->volume);
	
		if((aud_context_p->speech_on == KAL_TRUE)&&(volume != 0))
		{	
			/* add speech tone and voice mix, so when speech the tone volume should same as voice*/
			volume = aud_get_volume_gain(aud_context_p->audio_mode, AUD_VOLUME_SPH, aud_get_volume_level(aud_context_p->audio_mode,AUD_VOLUME_SPH));
		}
	
        aud_keytone_set_output_volume(volume, 0);
    #else
        aud_volume_set_keytone_volume(req_p->volume);
    #endif /* __GAIN_TABLE_SUPPORT__ */
    
        aud_keytone_play(audio_id, audio_out_device, req_p->play_style);
    }
    else if ((audio_id > TONE_KEY_CLICK) && (audio_id <= MAX_TONE_ID))
    {
        /* if keytone is playing, stop it */
        aud_keytone_stop();

        if (req_p->play_style == DEVICE_AUDIO_PLAY_INFINITE)
        {
            aud_context_p->tone_playing = KAL_TRUE;
        }

        /* Update tone volume */
    #ifndef __GAIN_TABLE_SUPPORT__
	
        volume = aud_get_volume_gain(aud_context_p->audio_mode, AUD_VOLUME_CTN, req_p->volume);
	
		/*when speech ctn volume same as speech volume ,we should not to set voume here,and set volume when change mode or set voume */
		if(aud_context_p->speech_on == KAL_FALSE)
		{
			aud_tone_set_output_volume(volume,0);
		}
    #else
        aud_volume_set_tone_volume(req_p->volume);
    #endif /* __GAIN_TABLE_SUPPORT__ */
        
        aud_tone_play(audio_id, audio_out_device);
    }

#ifdef DUMMY_CNF
    cnf_p = (media_aud_play_by_id_cnf_struct*)
        construct_local_para(sizeof(media_aud_play_by_id_cnf_struct), TD_CTRL);

    cnf_p->result = MED_RES_OK;

    aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_MEDIA_AUD_PLAY_BY_ID_CNF, cnf_p, NULL);
#endif /* DUMMY_CNF */
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_stop_by_id_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_stop_by_id_req_hdlr(ilm_struct *ilm_ptr)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 audio_id;
    media_aud_stop_by_id_req_struct *req_p = (media_aud_stop_by_id_req_struct*) ilm_ptr->local_para_ptr;
#ifdef DUMMY_CNF
    media_aud_stop_by_id_cnf_struct *cnf_p = NULL;
#endif /* DUMMY_CNF */ 
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->src_mod = ilm_ptr->src_mod_id;

    audio_id = req_p->audio_id;

    if (audio_id <= TONE_KEY_CLICK)
    {
        aud_keytone_stop();
    }
    else if ((audio_id > TONE_KEY_CLICK) && (audio_id <= MAX_TONE_ID))
    {
        aud_tone_stop();
    }
    
    /* set event to let caller go */
    aud_set_event(AUD_EVT_STOP);

#ifdef DUMMY_CNF
    cnf_p = (media_aud_stop_by_id_cnf_struct*)
        construct_local_para(sizeof(media_aud_stop_by_id_cnf_struct), TD_CTRL);

    cnf_p->result = MED_RES_OK;

    aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_MEDIA_AUD_STOP_BY_ID_CNF, cnf_p, NULL);
#endif /* DUMMY_CNF */

}

/*****************************************************************************
 * FUNCTION
 *  aud_media_play_by_string_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_play_by_string_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_BUSY;
    aud_media_player_play_req_t req;
    media_aud_play_by_string_req_struct *req_p = (media_aud_play_by_string_req_struct*) ilm_ptr->local_para_ptr;
    media_aud_play_by_string_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->src_mod = ilm_ptr->src_mod_id;

    /* Configure play request */
    req.source_type  = AUD_STRING;
    req.play_mode    = AUD_MEDIA_PLAY_AS_RING;
    req.file_name    = NULL;
    req.data_p       = (kal_uint8*)req_p->melody;
    req.data_len     = req_p->len;
    req.format       = req_p->format;
    req.play_style   = req_p->play_style;
    req.volume       = req_p->volume;
    req.output_path  = req_p->output_path;
    req.identifier   = req_p->identifier;
    req.start_offset = req_p->start_offset;
    req.end_offset   = req_p->end_offset;;
    req.cache_p      = NULL;
    req.is_restore   = KAL_FALSE;

    /* Play with the request */
    result = aud_media_player_play_req(&req);
    _AUD_MODULE_MEDIA2_TRACE(result, -1);

    if (req_p->blocking)
    {
		aud_set_result(result);
		aud_set_event(AUD_EVT_PLAY);
    }
	else if(result != MED_RES_OK)
	{
		kal_sleep_task(1);
		aud_send_audio_play_finish_ind(result,req.identifier);
	}

    if (!(aud_context_p->src_mod == MOD_MMI /*&& req_p->blocking*/))
    {
        cnf_p = (media_aud_play_by_string_cnf_struct*)
            construct_local_para(sizeof(media_aud_play_by_string_cnf_struct), TD_CTRL);

        cnf_p->src_id = req_p->src_id;
        cnf_p->result = (kal_uint8)result;

        aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_MEDIA_AUD_PLAY_BY_STRING_CNF, cnf_p, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_stop_by_string_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_stop_by_string_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_stop_by_string_req_struct *req_p = (media_aud_stop_by_string_req_struct*) ilm_ptr->local_para_ptr;
    media_aud_stop_by_string_cnf_struct *cnf_p = NULL;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->src_mod = ilm_ptr->src_mod_id;

    /* Since this is a request to stop a "Player". Hence, if the "Recorder"
     * is active, we should do nothing.
     */
    if (!(aud_context_p->state == AUD_MEDIA_RECORD ||
          aud_context_p->state == AUD_MEDIA_RECORD_PAUSED ||
          aud_context_p->state == AUD_MEDIA_WAIT_RECORD ||
          aud_context_p->state == AUD_VM_RECORD))
    {
        _aud_media_player_stop_req_hdlr(KAL_FALSE);
    }

    /* set event to let caller go */
    aud_set_event(AUD_EVT_STOP);

    if (aud_context_p->src_mod != MOD_MMI)
    {
        cnf_p = (media_aud_stop_by_string_cnf_struct*)
            construct_local_para(sizeof(media_aud_stop_by_string_cnf_struct), TD_CTRL);

        cnf_p->src_id = req_p->src_id;
        cnf_p->result = MED_RES_OK;

        aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_MEDIA_AUD_STOP_BY_STRING_CNF, cnf_p, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_is_pure_audio_req_hdlr
 * DESCRIPTION
 *  This function is to check if the file is pure audio file. Note that when 
 *  playing an audio file, MMI may query if another audio file in the playlist 
 *  is audio only or not. To fulfill this scenario, we have to create a temporary 
 *  MP4 parser to query if a given MP4 file contains audio track only, and 
 *  release the temporary parser when the process is complete.
 * PARAMETERS
 * RETURNS
 * void
 *****************************************************************************/
void aud_media_is_pure_audio_req_hdlr(ilm_struct *ilm_ptr)
{
#if defined(MED_PURE_AUDIO) //|| defined(MP4_DECODE)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_check_is_pure_audio_req_struct *msg_p = (media_aud_check_is_pure_audio_req_struct*) ilm_ptr->local_para_ptr;
    med_aud_player_t* player_p = NULL;
    kal_bool is_audio_only = KAL_FALSE;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    result = _aud_media_player_open(msg_p->file_name,
                                    NULL,
                                    0,
                                    MED_TYPE_NONE, /* media format - don't care */
                                    0, /* play style - don't care */
                                    0, /* audio path - don't care */
                                    NULL,
                                    NULL,
                                    &player_p);
                
    if (result == MED_RES_OK && player_p != NULL)
    {
        player_p->get(player_p, MP4_PLAYER_GET_IS_AUDIO_ONLY, &is_audio_only);

        /* Remember to close the temporary handler */
        _aud_media_player_close(player_p);
    }

    aud_set_result_and_event(is_audio_only,AUD_EVT_IS_PURE_AUDIO);
    
#else

    aud_set_result_and_event(KAL_FALSE,AUD_EVT_IS_PURE_AUDIO);
    
#endif /* MED_PURE_AUDIO || MP4_DECODE */
}

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar file_name[MAX_MEDIA_FILE_NAME];
}
media_aud_query_ability_req_struct;

/*****************************************************************************
 * FUNCTION
 *  aud_media_query_ability_req_hdlr
 * DESCRIPTION
 *  This function is to query file's ability.
 *  - seekable
 *  - pauseable
 * PARAMETERS
 *
 * RETURNS
 * void
 *****************************************************************************/
void aud_media_query_ability_req_hdlr(aud_media_query_abilty_enum ability_type, ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_query_ability_req_struct *msg_p = (media_aud_query_ability_req_struct*) ilm_ptr->local_para_ptr;
    STFSAL stFSAL_aud;
    FSAL_Status eFSALRet;
    kal_int16 format;
    kal_bool ability = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MTK_TARGET__
    format = med_get_media_type(msg_p->file_name);

    /* Open file handle */
    eFSALRet = FSAL_Open(&stFSAL_aud, (void*)msg_p->file_name, FSAL_READ);
    
    if (eFSALRet == FSAL_OK)
    {
        switch( ability_type )
        {
            case AUD_MEDIA_QUERY_SEEKABLE:
                ability = Media_IsSeekable(&stFSAL_aud, (Media_Format) format);
                break;
            case AUD_MEDIA_QUERY_PAUSABLE:
                ability = Media_IsPauseable(&stFSAL_aud, (Media_Format) format);
                break;
        }

        FSAL_Close(&stFSAL_aud);
    }
#endif /*__MTK_TARGET__*/

    aud_set_result_and_event(ability,AUD_EVT_WAIT);

}

#if !defined(MED_V_NOT_PRESENT) && defined(__MTK_TARGET__)
/*****************************************************************************
 * FUNCTION
 *  aud_media_is_build_cache_required
 * DESCRIPTION
 *  This function is to check if building cache is required.
 * PARAMETERS
 *  file_name      [IN]        File name.
 * RETURNS
 *  KAL_TRUE       Build cache is required.
 *  KAL_FALSE      Build cache is not required.
 *****************************************************************************/
kal_bool aud_media_is_build_cache_required(kal_wchar* file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_seeking_required = KAL_FALSE;
    kal_int16 format;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Validate file name */
    if (file_name == NULL)
    {
        return KAL_FALSE;
    }
    
    format = med_get_media_type(file_name);;
    
    switch (format)
    {
    #ifdef AMR_DECODE
        case MED_TYPE_AMR:       /* AMR */
    #ifdef AMRWB_DECODE
        case MED_TYPE_AMR_WB:    /* AWB */
    #endif /* AMRWB_DECODE */
    #endif /* AMR_DECODE */
    
    #ifdef DAF_DECODE
        case MED_TYPE_DAF:       /* DAF */
    #ifdef MUSICAM_DECODE
        case MED_TYPE_MUSICAM:   /* MUSICAM */
    #endif /* MUSICAM_DECODE */
    #endif /* DAF_DECODE */
    
    #ifdef AAC_DECODE
        case MED_TYPE_AAC:       /* AAC */
    #ifdef BSAC_DECODE
/* under construction !*/
    #endif /* BSAC_DECODE */
    #endif /* AAC_DECODE */
    
    #ifdef WAV_CODEC
        case MED_TYPE_WAV:       /* WAV */
    #endif /* WAV_CODEC */
            is_seeking_required = KAL_TRUE;
            break;
           
        default:
            break;
    }

    return is_seeking_required;
}
#endif /* ! MED_V_NOT_PRESENT && __MTK_TARGET__ */


/*****************************************************************************
 * FUNCTION
 *  aud_media_is_resource_available
 * DESCRIPTION
 *  This function is to check if a given audio resource is available.
 * PARAMETERS
 *  resource        [IN]        Audio resource.
 * RETURNS
 * void
 *****************************************************************************/
kal_bool aud_media_is_resource_available(kal_uint8 resource)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_resource_available = KAL_FALSE;
	
#if defined( __MED_BT_HFP_MOD__) || defined(__MED_BT_HF_MOD__) 
    kal_uint16 sco_mode;
#endif /*#if defined( __MED_BT_HFP_MOD__) || defined(__MED_BT_HF_MOD__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    _AUD_MODULE_MEDIA_TRACE(resource, aud_context_p->speech_on, aud_context_p->state);

#if defined( __MED_BT_HFP_MOD__) || defined(__MED_BT_HF_MOD__) 
#ifdef __BT_DIALER_SUPPORT__
    aud_bt_hfp_get_sco_mode(&sco_mode);
    _AUD_MODULE_MEDIA2_TRACE(aud_bt_hfp_is_speech_path_on(),AUD_BT_HFP_IS_BT_DIALER_SCO(sco_mode));
	  if(aud_bt_hfp_is_speech_path_on()&& AUD_BT_HFP_IS_BT_DIALER_SCO(sco_mode))
	  {
		  switch(resource)
		  {
			  case AUD_RESOURCE_PLAYER:
			  case AUD_RESOURCE_FMR_RECORD:
			  case AUD_RESOURCE_MMA:
			  case AUD_RESOURCE_AUDIO:
				  return KAL_FALSE;  //When BT dialer is on, playback & Record should be forbidden 
			  default:
				break;
		  }
	  }
#endif /*__BT_DIALER_SUPPORT__*/
#endif /*#if defined( __MED_BT_HFP_MOD__) || defined(__MED_BT_HF_MOD__) */

#if defined (__MED_BT_A2DP_MOD__) && defined (__BTMTK__)
#ifdef __BT_SPEAKER_SUPPORT__
    if(NULL != aud_bt_get_a2dp_sink_codec())
		return KAL_FALSE;  //When BT A2DP Sink is on, playback & Record should be forbidden
#endif
#endif
    if (resource == AUD_RESOURCE_PLAYER)
    {
        /* Check if player resource is available */
        do
        {
            /* Video */
        #if defined(__MED_VID_DEC_MOD__)
            if (! vid_is_audio_channel_available())
            {
                break;
            }
        #endif /* defined(__MED_VID_DEC_MOD__) */
        
            /* Audio */
            if (aud_context_p->speech_on                     /* Speech is on */
                || aud_context_p->state != AUD_MEDIA_IDLE    /* Play, record, play_paused, record_paused, TTS, ... */
        #if defined(__MED_FMR_MOD__)
                || aud_fmr_is_power_on()                     /* FM Radio is on */
        #endif /* defined(__MED_FMR_MOD__) */
        #if defined(__MED_MMA_MOD__)&&(!defined (__MED_SLIM_MMA__))
                || aud_mma_is_playing(AUD_MMA_CHECK_MODE_ALL)/* MMA player(s) is being used */
        #endif /* defined(__MED_MMA_MOD__) */
        #if defined(__MED_VRSI_MOD__)
                || aud_vrsi_is_active()                      /* VRSI is active */
        #endif /* defined(__MED_VRSI_MOD__) */
        #if defined(__MED_VR_MOD__)
                || aud_vr_sd_is_active()                     /* VRSD is active */
        #endif /* defined(__MED_VR_MOD__) */
               )
            {
                break;
            }
        
            /* Streaming */
        #if defined(__MED_STREAM_MOD__)
            if (! stream_is_audio_channel_available())
            {
                break;
            }
        #endif /* defined(__MED_STREAM_MOD__) */
        
            /* MobileTV */
        #if defined(__MED_MTV_MOD__) || defined(__MED_ATV_MOD__) || defined(__STREAM_REC_SUPPORT__)
            if (! mtv_is_audio_channel_available())
            {
                break;
            }
        #endif /* defined(__MED_MTV_MOD__) || defined(__MED_ATV_MOD__) || defined(__STREAM_REC_SUPPORT__) */
        
            /* Go here if resource is available */
            is_resource_available = KAL_TRUE;
            
        } while (0);
    }
    else if (resource == AUD_RESOURCE_FMR_RECORD)
    {
        /* Check if FM record is available */
        do
        {
            /* Video */
        #if defined(__MED_VID_DEC_MOD__)
            if (! vid_is_audio_channel_available())
            {
                break;
            }
        #endif /* defined(__MED_VID_DEC_MOD__) */
        
            /* Audio */
            if (aud_context_p->state == AUD_MEDIA_RECORD ||
                aud_context_p->state == AUD_MEDIA_RECORD_PAUSED ||
                aud_context_p->state == AUD_MEDIA_WAIT_RECORD ||
                aud_context_p->state == AUD_VM_RECORD)
            {
                break;
            }

            /* Check if it's in SCO mode */
        #if defined(__MED_BT_HFP_MOD__)
            if (aud_bt_hfp_is_audio_path_on())
            {
                aud_bt_hfp_get_sco_mode(&sco_mode);
                
                if (AUD_BT_HFP_IS_FM_VIA_BT_SCO(sco_mode) ||
                    AUD_BT_HFP_IS_ATV_VIA_BT_SCO(sco_mode))
                {
                    break;
                }
            }
        #endif /* defined(__MED_BT_HFP_MOD__) */

        #ifdef __MED_BT_A2DP_MOD__
            if (aud_bt_a2dp_is_codec_opened())
            {
                break;
            }
        #endif

            /* Go here if resource is available */
            is_resource_available = KAL_TRUE;
            
        } while (0);
    }
    else if (resource == AUD_RESOURCE_SND_RECORD)
    {
        /* Check if sound record is available */
        do
        {
            /* Video */
        #if defined(__MED_VID_DEC_MOD__)
            if (! vid_is_audio_channel_available())
            {
                break;
            }
        #endif /* defined(__MED_VID_DEC_MOD__) */
        
            /* Audio */
            if (aud_context_p->state == AUD_MEDIA_RECORD ||
                aud_context_p->state == AUD_MEDIA_RECORD_PAUSED ||
                aud_context_p->state == AUD_MEDIA_WAIT_RECORD ||
                aud_context_p->state == AUD_VM_RECORD)
            {
                break;
            }
        
            /* Go here if resource is available */
            is_resource_available = KAL_TRUE;
            
        } while (0);
    }
    else if (resource == AUD_RESOURCE_SCO)
    {
        /* Check if SCO resource is available */
        do
        {
            if (aud_context_p->state == AUD_MEDIA_RECORD ||
                aud_context_p->state == AUD_MEDIA_RECORD_PAUSED)
            {
                if (aud_fmr_is_power_on()) /* FM record */
                {
                    break;
                }
            }

            /* MobileTV */
        #if defined(__MED_MTV_MOD__) || defined(__MED_ATV_MOD__)
            if (! mtv_is_audio_record_resource_available())
            {
                break;
            }
        #endif /* defined(__MED_MTV_MOD__) || defined(__MED_ATV_MOD__) */
        
            /* Go here if resource is available */
            is_resource_available = KAL_TRUE;
            
        } while (0);
    }
    else if (resource == AUD_RESOURCE_MMA)
    {
        do
        {
            /* Video */
        #if defined(__MED_VID_DEC_MOD__)
            if (! vid_is_audio_channel_available())
            {
                break;
            }
        #endif /* defined(__MED_VID_DEC_MOD__) */
        
            /* Audio */
            if (aud_context_p->speech_on                     /* Speech is on */
                || aud_context_p->state != AUD_MEDIA_IDLE    /* Play, record, play_paused, record_paused, TTS, ... */
        #if defined(__MED_FMR_MOD__)
                || aud_fmr_is_power_on()                     /* FM Radio is on */
        #endif /* defined(__MED_FMR_MOD__) */
        #if defined(__MED_MMA_MOD__)&&(!defined (__MED_SLIM_MMA__))
                || aud_mma_is_playing(AUD_MMA_CHECK_MODE_SINGLE)/* MMA single player is being used */
        #endif /* defined(__MED_MMA_MOD__) */
        #if defined(__MED_VRSI_MOD__)
                || aud_vrsi_is_active()                      /* VRSI is active */
        #endif /* defined(__MED_VRSI_MOD__) */
        #if defined(__MED_VR_MOD__)
                || aud_vr_sd_is_active()                     /* VRSD is active */
        #endif /* defined(__MED_VR_MOD__) */
               )
            {
                break;
            }
        
            /* Streaming */
        #if defined(__MED_STREAM_MOD__)
            if (! stream_is_audio_channel_available())
            {
                break;
            }
        #endif /* defined(__MED_STREAM_MOD__) */
        
            /* MobileTV */
        #if defined(__MED_MTV_MOD__) || defined(__MED_ATV_MOD__) || defined(__STREAM_REC_SUPPORT__)
            if (! mtv_is_audio_channel_available())
            {
                break;
            }
        #endif /* defined(__MED_MTV_MOD__) || defined(__MED_ATV_MOD__) || defined(__STREAM_REC_SUPPORT__) */
        
            /* Go here if resource is available */
            is_resource_available = KAL_TRUE;
            
        } while (0);
    }
    else if (resource == AUD_RESOURCE_AUDIO)
    {
        do
        {
            /* Video */
        #if defined(__MED_VID_DEC_MOD__)
            if (! vid_is_audio_channel_available())
            {
                break;
            }
        #endif /* defined(__MED_VID_DEC_MOD__) */
        
            /* Audio */
            if (aud_context_p->speech_on)
            {
                break;
            }
        
            /* Streaming */
        #if defined(__MED_STREAM_MOD__)
            if (! stream_is_audio_channel_available())
            {
                break;
            }
        #endif /* defined(__MED_STREAM_MOD__) */
        
            /* MobileTV */
        #if defined(__MED_MTV_MOD__) || defined(__MED_ATV_MOD__) || defined(__STREAM_REC_SUPPORT__)
            if (! mtv_is_audio_channel_available())
            {
                break;
            }
        #endif /* defined(__MED_MTV_MOD__) || defined(__MED_ATV_MOD__) || defined(__STREAM_REC_SUPPORT__) */
        
            /* Go here if resource is available */
            is_resource_available = KAL_TRUE;
            
        } while (0);
    }

    return is_resource_available;
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_is_resource_available_req_hdlr
 * DESCRIPTION
 *  This function is to check if a given audio resource is available.
 * PARAMETERS
 *
 * RETURNS
 * void
 *****************************************************************************/
void aud_media_is_resource_available_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_check_is_resource_available_req_struct *msg_p = (media_aud_check_is_resource_available_req_struct*) ilm_ptr->local_para_ptr;
    kal_bool is_resource_available;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    is_resource_available = aud_media_is_resource_available(msg_p->resource);

    aud_set_result_and_event(is_resource_available,AUD_EVT_WAIT);
}

#endif /* MED_NOT_PRESENT */ 

