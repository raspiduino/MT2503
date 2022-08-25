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
 * aud_player_mp4.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary functions of MP4 audio player.
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
 *    MP4 Audio Player
 * DESCRIPTION
 *    This module defines related function of MP4 Player.
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
#include "MP4_Parser.h"

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
#include "aud_defs.h"
#include "med_utility.h"
//#include "med_struct.h"
//#include "med_api.h"
//#include "med_context.h"
#include "med_main.h"
#include "aud_main.h"
#include "aud_player.h"
#include "aud_player_mp4.h"

#include "fs_type.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "stack_config.h"
#include "med_status.h"
#include "drv_features.h"
#include "string.h"
#include "med_smalloc.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#if defined(__MTK_TARGET__) && defined(MED_PURE_AUDIO)
/*-----------------------------------------------------------------------------
                    macros, defines, typedefs, enums
-----------------------------------------------------------------------------*/
#define _AUD_PLAYER_MP4_TRACE(x, y, z)    AUD_PLAYER_MP4_TRACE(x, y, z, __LINE__)
#define _AUD_PLAYER_MP4_CHECK_MEM(p, error)        \
    do {                                           \
        if (p == NULL)                             \
        {                                          \
            med_result = MED_RES_MEM_INSUFFICIENT; \
            goto error;                            \
        }                                          \
    } while(0)

#define AUD_DEC_SEEK_HINT_SIZE           (2047)
#ifdef __VENUS_UI_ENGINE__               
    #define AUD_MP4_FSAL_BUF_SIZE        (1536 / 4)
#else /* __VENUS_UI_ENGINE__ */          
    #define AUD_MP4_FSAL_BUF_SIZE        (1024 / 4)
#endif /* __VENUS_UI_ENGINE__ */         
#define AUD_MP4_STCO_BUF_SIZE            (512 / 4)
#define AUD_MP4_STSZ_BUF_SIZE            (512 / 4)
#define AUD_MP4_STBL_BUF_SIZE            (1024 / 4 * 8)
#define AUD_MP4_OBJ_BUF_SIZE             (1800)
#define AUD_MP4_BUF_FILL_SIZE            (4 * 1024) /* Maximum data length per fill */
#define AUD_MP4_BUF_THRESHOLD            (2 * 1024) /* Callback criteria */

/* MP4 Parser */
typedef struct
{
    STMp4Parser*                  mp4_aud_parser_p;
    STFSAL*                       mp4_aud_fsal_stsz_p;
    STFSAL*                       mp4_aud_fsal_stco_p;
    STFSAL*                       mp4_aud_fsal_data_p;
    FS_FileLocationHint*          mp4_aud_seek_hint_p;
    kal_uint32*                   mp4_aud_fsal_buf_p;
    kal_uint32*                   mp4_aud_data_buf_p;
    kal_uint32*                   mp4_aud_stco_buf_p;
    kal_uint32*                   mp4_aud_stsz_buf_p;
    kal_uint32*                   mp4_aud_stbl_buf_p;    
} med_aud_player_mp4_parser_t;

/* MP4 Event */
typedef struct
{
    MHdl*                         mhdl_handle_p;    /* L1audio handle */
    Media_Event                   event;            /* Event */
    med_aud_player_t*             player_p;         /* Player handle */
    kal_uint32                    time_stamp;       /* Time stamp of the callback event */
} med_aud_player_mp4_event_t;

/* MP4 Player */
typedef struct
{
    med_aud_player_t              itf;              /* Player interfaces */
    kal_uint32                    time_stamp;       /* Time stamp of the constructed player */
    med_aud_player_mp4_parser_t   mp4_parser;       /* MP4 parser */
    MHdl*                         mhdl_handle_p;    /* L1audio handle */
    void*                         mhdl_user_data_p; /* User data attached to a MHdl handler */
    STFSAL                        fsal_handle;      /* file handle */
    kal_bool                      is_file_opened;   /* Indicate if a file handler has been opened successfully */
    kal_uint8                     state;            /* Player state */
    Media_Format                  audio_format;     /* Audio format */
    kal_uint32                    start_time;       /* Start time */
    kal_uint32                    stop_time;        /* Stop time */
    kal_uint16*                   ring_buffer_p;    /* Ring buffer */
    med_aud_player_cb_fct         cb_fct;           /* Callback when there is event arisen */
    void*                         cb_param;         /* Callback parameter */
} med_aud_player_mp4_t;

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
 *  _aud_player_mp4_event_callback_hdlr
 * DESCRIPTION
 *  This function is used to handle the callback events from L1Audio.
 * PARAMETERS
 *  data_p            [IN]       MP4 event data.
 *  data_len          [IN]       The length of data.
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_player_mp4_event_callback_hdlr(void* data_p, kal_uint16 data_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_mp4_t*       self_p;
    med_aud_player_mp4_event_t* mp4_event_p = (med_aud_player_mp4_event_t*)data_p;
    MHdl*                       mhdl_handle_p;
    Media_Event                 event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(mp4_event_p->player_p, med_aud_player_mp4_t, itf);
    mhdl_handle_p = mp4_event_p->mhdl_handle_p;
    
    /* Validate event */
    if (self_p->state != AUD_MEDIA_PLAY ||
        self_p->mhdl_handle_p != mp4_event_p->mhdl_handle_p ||
        self_p->time_stamp != mp4_event_p->time_stamp)
    {
        _AUD_PLAYER_MP4_TRACE(self_p->state , self_p->mhdl_handle_p, self_p->time_stamp);
        return;
    }
    
    /* Process media data */
    event = mhdl_handle_p->Process(mhdl_handle_p, (Media_Event) mp4_event_p->event);
    _AUD_PLAYER_MP4_TRACE(event, mp4_event_p->event, mhdl_handle_p);

    /* Post processing */
    switch (event)
    {
        /* Fill data to ring buffer */
        case MEDIA_DATA_REQUEST:
        {
            kal_uint8* buf_p;
            kal_uint32 buf_len;
            kal_uint32 num_byte;
            MP4_Parser_Status mp4_status;

            /* Fill ring buffer up to AUD_MP4_BUF_FILL_SIZE */
            mhdl_handle_p->GetWriteBuffer(mhdl_handle_p, &buf_p, &buf_len);

            if (buf_len > AUD_MP4_BUF_FILL_SIZE)
            {
                buf_len = AUD_MP4_BUF_FILL_SIZE;
            }
            
            mp4_status = MP4_Audio_Read(self_p->mp4_parser.mp4_aud_parser_p, buf_p, buf_len, &num_byte);
            _AUD_PLAYER_MP4_TRACE(mp4_status, buf_len, num_byte);
            
            if (mp4_status == MP4_PARSER_READ_EOF)
            {
                mhdl_handle_p->DataFinished(mhdl_handle_p);
            }
            else if (mp4_status != MP4_PARSER_OK)
            {
                mhdl_handle_p->DataFinished(mhdl_handle_p);
                
                /* Callback error */
                if (self_p->cb_fct)
                {
                    self_p->cb_fct(&self_p->itf, MEDIA_ERROR, self_p->cb_param);
                }
                
                return;
            }
            
            /* Update write buffer pointer */
            mhdl_handle_p->WriteDataDone(mhdl_handle_p, num_byte);

            /* To inform audio driver to callback again when it requires more data */
            mhdl_handle_p->FinishWriteData(mhdl_handle_p);
            break;
        }        
        case MEDIA_NONE:
            /* Do nothing */
            break;
        case MEDIA_UPDATE_DUR:
        case MEDIA_END:        
        case MEDIA_STOP_TIME_UP:
        case MEDIA_ERROR:
        case MEDIA_DECODER_UNSUPPORT:
        default:
            /* Callback event to player handler */
            if (self_p->cb_fct)
            {
                self_p->cb_fct(mp4_event_p->player_p, event, self_p->cb_param);
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  _aud_player_mp4_event_callback_fct
 * DESCRIPTION
 *  This function is used to receive the callback events from L1Audio.
 * PARAMETERS
 *  handle_p      [IN]         MHdl handler.
 *  event         [IN]         Player event.
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_player_mp4_event_callback_fct(MHdl *handle_p, Media_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_mp4_event_t mp4_event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(handle_p != NULL);  

    /* Get player handle from attached user data */
    handle_p->GetUserData(handle_p, (void**)&mp4_event.player_p);
    
    mp4_event.mhdl_handle_p = handle_p;
    mp4_event.event = event;
    mp4_event.time_stamp = PTHIS(mp4_event.player_p, med_aud_player_mp4_t, itf)->time_stamp;
    
    aud_util_proc_in_med_ext(MOD_L1SP,
                             _aud_player_mp4_event_callback_hdlr,
                             (void*)&mp4_event,
                             sizeof(med_aud_player_mp4_event_t));
}


/*****************************************************************************
 * FUNCTION
 *  _aud_player_mp4_has_audio_track
 * DESCRIPTION
 *  This function is to used to check if there is audio track in a given MP4
 *  handler.
 * PARAMETERS
 *  parser_handle_p     [IN]    Parser handler.
 *  has_audio_track_p   [OUT]   Has audio track or not.
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_player_mp4_has_audio_track(STMp4Parser *parser_handle_p, kal_bool *has_audio_track_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool       audio_format_supported;
    kal_bool       has_aud_track;
    MP4_Audio_Type audio_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    audio_format_supported = KAL_FALSE;
    audio_type = MP4_GetAudioType(parser_handle_p);
    
    switch (audio_type)
    {
    #if defined(AAC_DECODE)
        case MP4_AUDIO_AAC:
    #endif /* AAC_DECODE */
    #if defined(AMR_DECODE)
        case MP4_AUDIO_AMR:
    #endif /* AMR_DECODE */
    #if defined(AMRWB_DECODE)
        case MP4_AUDIO_AMR_WB:
    #endif /* AMRWB_DECODE */
    #if defined(BSAC_DECODE)
/* under construction !*/
    #endif /* BSAC_DECODE */
            audio_format_supported = KAL_TRUE;
            break;
        default:
            break;
    }

    MP4_MetaHasAudioTrack(parser_handle_p, &has_aud_track);

    if (has_aud_track && audio_format_supported)
    {
        *has_audio_track_p = KAL_TRUE;
    }
    else
    {
        *has_audio_track_p = KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  _aud_player_mp4_has_video_track
 * DESCRIPTION
 *  This function is to used to check if there is video track in a given MP4
 *  handler.
 * PARAMETERS
 *  parser_handle_p     [IN]    Parser handler.
 *  has_video_track_p   [OUT]   Has video track or not.
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_player_mp4_has_video_track(STMp4Parser *parser_handle_p, kal_bool *has_video_track_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool       video_format_supported;
    kal_bool       has_vid_track;
    MP4_Video_Type video_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    video_format_supported = KAL_FALSE;
    video_type = MP4_GetVideoType(parser_handle_p);
    
    switch (video_type)
    {
        case MP4_VIDEO_MPEG4:                
        case MP4_VIDEO_H263:                
    #ifdef H264_DECODE
        case MP4_VIDEO_H264:
    #endif
            video_format_supported = KAL_TRUE;
            break;
        default:
            break;
    }

    MP4_MetaHasVideoTrack(parser_handle_p, &has_vid_track);

    if (has_vid_track && video_format_supported)
    {
        *has_video_track_p = KAL_TRUE;
    }
    else
    {
        *has_video_track_p = KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  _aud_player_mp4_get_duration
 * DESCRIPTION
 *  This function is used to get longer duration of audio/video track. Note that
 *  when playing an audio file, MMI may browse META information of the other 
 *  audio files in the playlist. To fulfill this scenario, we have to create
 *  a temporary MP4 parser for the need to retrieve the duartion, and release
 *  the temporary parser when the process is complete.
 * PARAMETERS
 *  player_p      [IN]         Player handle.
 *  event         [IN]         Player event.
 *  duration_p    [OUT]        Duration.
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
static kal_int32 _aud_player_mp4_get_duration(med_aud_player_t* player_p, MP4_Track_Type type, kal_uint32* duration_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_mp4_t* self_p;
    MP4_Parser_Status     mp4_parser_ret;
    kal_uint32            duration = 0;
    kal_uint32            med_duration, time_scale;
    kal_bool              has_aud_track, has_vid_track;
       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_mp4_t, itf);
    MED_ASSERT(self_p->mhdl_handle_p != NULL);
    
    *duration_p = 0;
    
    if (type == MP4_TRACK_AUDIO)
    {
        /* Check if there's audio track */
        _aud_player_mp4_has_audio_track(self_p->mp4_parser.mp4_aud_parser_p, &has_aud_track);
        if (!has_aud_track)
        {
            return MED_RES_MP4_NO_AUDIO_TRACK;
        }
        
        /* Get media duration */
        mp4_parser_ret = MP4_GetMediaDuration(self_p->mp4_parser.mp4_aud_parser_p, &med_duration, MP4_TRACK_AUDIO);
        if (mp4_parser_ret != MP4_PARSER_OK)
        {
            return MED_RES_FAIL;
        }
        
        /* Get time scale */
        mp4_parser_ret = MP4_GetMediaTimeScale(self_p->mp4_parser.mp4_aud_parser_p, &time_scale, MP4_TRACK_AUDIO);
        if (mp4_parser_ret != MP4_PARSER_OK)
        {
            return MED_RES_FAIL;
        }
        
        /* Calculate duration in milliseconds */
        if (time_scale > 0)
        {
            duration = (kal_uint32)(((kal_uint64)med_duration * (kal_uint64)1000) / (kal_uint64)time_scale);
        }
        else
        {
            return MED_RES_FAIL;
        }
    }
    else if (type == MP4_TRACK_VIDEO)
    {
        /* Check if there's video track */
        _aud_player_mp4_has_video_track(self_p->mp4_parser.mp4_aud_parser_p, &has_vid_track);
        if (!has_vid_track)
        {
            return MED_RES_MP4_NO_VIDEO_TRACK;
        }
        
        /* Get media duration */
        mp4_parser_ret = MP4_GetMediaDuration(self_p->mp4_parser.mp4_aud_parser_p, &med_duration, MP4_TRACK_VIDEO);
        if (mp4_parser_ret != MP4_PARSER_OK)
        {
            return MED_RES_FAIL;
        }
        
        /* Get time scale */
        mp4_parser_ret = MP4_GetMediaTimeScale(self_p->mp4_parser.mp4_aud_parser_p, &time_scale, MP4_TRACK_VIDEO);
        if (mp4_parser_ret != MP4_PARSER_OK)
        {
            return MED_RES_FAIL;
        }
        
        /* Calculate duration in milliseconds */
        if (time_scale > 0)
        {
            duration = (kal_uint32)(((kal_uint64)med_duration * (kal_uint64)1000) / (kal_uint64)time_scale);
        }
        else
        {
            return MED_RES_FAIL;
        }
    }
    
    _AUD_PLAYER_MP4_TRACE(duration, type, -1);
    
    *duration_p = duration;
    
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  _aud_player_mp4_free_buf
 * DESCRIPTION
 *  This function is used to free all the allocated buffers.
 * PARAMETERS
 *  player_p      [IN]        Player handle.
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
static void _aud_player_mp4_free_buf(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_mp4_t* self_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_mp4_t, itf);
    
    AUD_PLAYER_FREE_AUD_MEM(self_p->mp4_parser.mp4_aud_parser_p);
    AUD_PLAYER_FREE_AUD_MEM(self_p->mp4_parser.mp4_aud_fsal_stsz_p);
    AUD_PLAYER_FREE_AUD_MEM(self_p->mp4_parser.mp4_aud_fsal_stco_p);
    AUD_PLAYER_FREE_AUD_MEM(self_p->mp4_parser.mp4_aud_fsal_data_p);
    AUD_PLAYER_FREE_AUD_MEM(self_p->mp4_parser.mp4_aud_seek_hint_p);
    AUD_PLAYER_FREE_AUD_MEM(self_p->mp4_parser.mp4_aud_fsal_buf_p);
    AUD_PLAYER_FREE_AUD_MEM(self_p->mp4_parser.mp4_aud_data_buf_p);
    AUD_PLAYER_FREE_AUD_MEM(self_p->mp4_parser.mp4_aud_stco_buf_p);
    AUD_PLAYER_FREE_AUD_MEM(self_p->mp4_parser.mp4_aud_stsz_buf_p);
    AUD_PLAYER_FREE_AUD_MEM(self_p->mp4_parser.mp4_aud_stbl_buf_p);
    
    memset(&self_p->mp4_parser, 0, sizeof(med_aud_player_mp4_parser_t));
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_mp4_close
 * DESCRIPTION
 *  This function is used to close an MP4 player.
 * PARAMETERS
 *  player_p      [IN]        Player handle.              
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_mp4_close(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_mp4_t* self_p;
    FSAL_Status           fsal_result;
    Media_Status          drv_result = MEDIA_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_mp4_t, itf);
    
    /* Free player resources */
    if (self_p->mhdl_handle_p)
    {
        /* Close MHdl handler */
        drv_result = self_p->mhdl_handle_p->Close(self_p->mhdl_handle_p);
        _AUD_PLAYER_MP4_TRACE(drv_result, self_p->mhdl_handle_p, -1);
        
        self_p->mhdl_handle_p = NULL;
    }
    
    /* Free FSAL resources */
    if (self_p->is_file_opened)
    {
        /* Free buffers of MP4 parser */
        _aud_player_mp4_free_buf(player_p);
        
        /* Close FSAL handler */
        fsal_result = FSAL_Close(&self_p->fsal_handle);
        _AUD_PLAYER_MP4_TRACE(fsal_result, &self_p->fsal_handle, -1);
        
        self_p->is_file_opened = KAL_FALSE;
    }
    
    return aud_get_res(drv_result);
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_mp4_open
 * DESCRIPTION
 *  This function is used to open an MP4 player.
 * PARAMETERS
 *  player_p      [IN]        Player handle.
 *  cfg_p         [IN]        Player configuration.  
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_mp4_open(med_aud_player_t* player_p, med_aud_player_cfg_t* cfg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_mp4_t* self_p;
    MP4_Parser_Status     mp4_parser_ret;
    FSAL_Status           fsal_result;
    kal_int32             med_result = MED_RES_FAIL;
    kal_bool              is_file;
    kal_bool              has_aud_track;
    kal_uint32            file_size;
    kal_uint32            index;
    kal_uint64            temp;
    media_open_func_ptr   open_fct = NULL;
    Media_VM_PCM_Param    vp_param;
    void*                 param_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_mp4_t, itf);
  
    /*----------------------- Open a FSAL handler ---------------------------*/
    /* Open from file */
    if (cfg_p->file_name != NULL)
    {
        if ((fsal_result = FSAL_Open(&self_p->fsal_handle, cfg_p->file_name, FSAL_READ)) != FSAL_OK)
        {
            return MED_RES_OPEN_FILE_FAIL;
        }

        is_file = KAL_TRUE;
    }
    /* Open from buffer */
    else if (cfg_p->data_p != NULL)
    {
        FSAL_Direct_SetRamFileSize(&self_p->fsal_handle, cfg_p->data_len);
        if ((fsal_result = FSAL_Open(&self_p->fsal_handle, cfg_p->data_p, FSAL_ROMFILE)) != FSAL_OK)
        {
            return MED_RES_OPEN_FILE_FAIL;
        }

        is_file = KAL_FALSE;
    }
    else
    {
        ASSERT(0);
        return MED_RES_PARAM_ERROR;
    }
    
    self_p->is_file_opened = KAL_TRUE;

    /*--------------- Setup buffers for file read and seek -----------------------*/
    memset(&self_p->mp4_parser, 0, sizeof(med_aud_player_mp4_parser_t));
    
    /* MP4 parser */
    self_p->mp4_parser.mp4_aud_parser_p = (STMp4Parser*)med_alloc_aud_mem(sizeof(STMp4Parser));
    _AUD_PLAYER_MP4_CHECK_MEM(self_p->mp4_parser.mp4_aud_parser_p, mp4_open_failed);
        
    if (is_file)
    {
        /* Allocate buffers*/
        self_p->mp4_parser.mp4_aud_fsal_buf_p = (kal_uint32*)med_alloc_aud_mem(AUD_MP4_FSAL_BUF_SIZE*sizeof(kal_uint32));
        _AUD_PLAYER_MP4_CHECK_MEM(self_p->mp4_parser.mp4_aud_fsal_buf_p, mp4_open_failed);
        self_p->mp4_parser.mp4_aud_seek_hint_p  = (FS_FileLocationHint*)med_alloc_aud_mem( AUD_DEC_SEEK_HINT_SIZE*sizeof(FS_FileLocationHint));
        _AUD_PLAYER_MP4_CHECK_MEM(self_p->mp4_parser.mp4_aud_seek_hint_p, mp4_open_failed);
       
        /* Set file buffer */
        FSAL_SetBuffer(&self_p->fsal_handle, AUD_MP4_FSAL_BUF_SIZE, (kal_uint8*)self_p->mp4_parser.mp4_aud_fsal_buf_p);

        /* Set seek hint */
        fsal_result = FSAL_GetFileSize(&self_p->fsal_handle, &file_size);
        if (fsal_result != FSAL_OK)
        {
            med_result = MED_RES_OPEN_FILE_FAIL;
            goto mp4_open_failed;
        }

        for (index = 0; index < AUD_DEC_SEEK_HINT_SIZE; index++)
        {
            temp = ((kal_uint64) file_size * (kal_uint64) (index + 1)) / (kal_uint64) (AUD_DEC_SEEK_HINT_SIZE + 1);
            self_p->mp4_parser.mp4_aud_seek_hint_p[index].Index = (kal_uint32) temp;
        }
        
        DRM_set_seek_hint(self_p->fsal_handle.hFile, AUD_DEC_SEEK_HINT_SIZE, self_p->mp4_parser.mp4_aud_seek_hint_p);
    }
    /* No need to set buffer for ROM file */
    else
    {
        FSAL_SetBuffer(&self_p->fsal_handle, 0, NULL);
    }

    /*------------------------ Create MP4 parser ----------------------------*/
    mp4_parser_ret = MP4_Parse(self_p->mp4_parser.mp4_aud_parser_p, &self_p->fsal_handle);
    _AUD_PLAYER_MP4_TRACE(mp4_parser_ret, -1, -1);
    
    if (mp4_parser_ret != MP4_PARSER_OK && mp4_parser_ret != MP4_PARSER_WARNING_TRAILING_GARBAGE)
    {
        med_result = MED_RES_BAD_FORMAT;
        goto mp4_open_failed;
    }

    /* Check if there's audio track */
    _aud_player_mp4_has_audio_track(self_p->mp4_parser.mp4_aud_parser_p, &has_aud_track);
    if (!has_aud_track)
    {
        med_result = MED_RES_MP4_NO_AUDIO_TRACK;
        goto mp4_open_failed;
    }

    /*------------------------ Setup buffers for parser ---------------------*/
    /* Assign buffers for file read performance */
    if (is_file)
    {
        /* Allocate buffers */
        self_p->mp4_parser.mp4_aud_fsal_stsz_p = (STFSAL*)med_alloc_aud_mem(sizeof(STFSAL));
        _AUD_PLAYER_MP4_CHECK_MEM(self_p->mp4_parser.mp4_aud_fsal_stsz_p, mp4_open_failed);
        self_p->mp4_parser.mp4_aud_fsal_stco_p = (STFSAL*)med_alloc_aud_mem(sizeof(STFSAL));
        _AUD_PLAYER_MP4_CHECK_MEM(self_p->mp4_parser.mp4_aud_fsal_stco_p, mp4_open_failed);
        self_p->mp4_parser.mp4_aud_fsal_data_p = (STFSAL*)med_alloc_aud_mem(sizeof(STFSAL));
        _AUD_PLAYER_MP4_CHECK_MEM(self_p->mp4_parser.mp4_aud_fsal_data_p, mp4_open_failed);
        self_p->mp4_parser.mp4_aud_data_buf_p = (kal_uint32*)med_alloc_aud_mem(AUD_MP4_FSAL_BUF_SIZE*sizeof(kal_uint32));
        _AUD_PLAYER_MP4_CHECK_MEM(self_p->mp4_parser.mp4_aud_data_buf_p, mp4_open_failed);
        self_p->mp4_parser.mp4_aud_stco_buf_p = (kal_uint32*)med_alloc_aud_mem(AUD_MP4_STCO_BUF_SIZE*sizeof(kal_uint32));
        _AUD_PLAYER_MP4_CHECK_MEM(self_p->mp4_parser.mp4_aud_stco_buf_p, mp4_open_failed);
        self_p->mp4_parser.mp4_aud_stsz_buf_p = (kal_uint32*)med_alloc_aud_mem(AUD_MP4_STSZ_BUF_SIZE*sizeof(kal_uint32));
        _AUD_PLAYER_MP4_CHECK_MEM(self_p->mp4_parser.mp4_aud_stsz_buf_p, mp4_open_failed);
        self_p->mp4_parser.mp4_aud_stbl_buf_p = (kal_uint32*)med_alloc_aud_mem(AUD_MP4_STBL_BUF_SIZE*sizeof(kal_uint32));
        _AUD_PLAYER_MP4_CHECK_MEM(self_p->mp4_parser.mp4_aud_stbl_buf_p, mp4_open_failed);
       
        /* Assign buffer for cache table */
        mp4_parser_ret = MP4_STBL_CacheTablePreprocess(
                                  self_p->mp4_parser.mp4_aud_parser_p, 
                                  self_p->mp4_parser.mp4_aud_stbl_buf_p, 
                                  AUD_MP4_STBL_BUF_SIZE);
                            
        if (mp4_parser_ret != MP4_PARSER_OK)
        {
            _AUD_PLAYER_MP4_TRACE(mp4_parser_ret, -1, -1);
            med_result = MED_RES_BAD_FORMAT;
            goto mp4_open_failed;
        }    

        /* FSAL aud data */
        fsal_result = FSAL_Open_Attach(self_p->mp4_parser.mp4_aud_fsal_data_p, &self_p->fsal_handle);
        
        if (fsal_result != FSAL_OK)
        {
            med_result = MED_RES_OPEN_FILE_FAIL;
            goto mp4_open_failed;
        }
        FSAL_SetBuffer(self_p->mp4_parser.mp4_aud_fsal_data_p, AUD_MP4_FSAL_BUF_SIZE, (kal_uint8*)self_p->mp4_parser.mp4_aud_data_buf_p);

        /* FASL stco */
        fsal_result = FSAL_Open_Attach(self_p->mp4_parser.mp4_aud_fsal_stco_p, &self_p->fsal_handle);
        if (fsal_result != FSAL_OK)
        {
            med_result = MED_RES_OPEN_FILE_FAIL;
            goto mp4_open_failed;
        }
        FSAL_SetBuffer(self_p->mp4_parser.mp4_aud_fsal_stco_p, AUD_MP4_STCO_BUF_SIZE, (kal_uint8*)self_p->mp4_parser.mp4_aud_stco_buf_p);

        /* FSAL stsz */
        fsal_result = FSAL_Open_Attach(self_p->mp4_parser.mp4_aud_fsal_stsz_p, &self_p->fsal_handle);
        if (fsal_result != FSAL_OK)
        {
            med_result = MED_RES_OPEN_FILE_FAIL;
            goto mp4_open_failed;
        }
        FSAL_SetBuffer(self_p->mp4_parser.mp4_aud_fsal_stsz_p, AUD_MP4_STSZ_BUF_SIZE, (kal_uint8*)self_p->mp4_parser.mp4_aud_stsz_buf_p);

        /* Set FSAL to MP4 Parser */
        MP4_Audio_SetFSAL(self_p->mp4_parser.mp4_aud_parser_p, self_p->mp4_parser.mp4_aud_fsal_data_p);    
        MP4_SetFSAL_STCO(self_p->mp4_parser.mp4_aud_parser_p, MP4_TRACK_AUDIO, self_p->mp4_parser.mp4_aud_fsal_stco_p);
        MP4_SetFSAL_STSZ(self_p->mp4_parser.mp4_aud_parser_p, MP4_TRACK_AUDIO, self_p->mp4_parser.mp4_aud_fsal_stsz_p);
    }    

    MP4_UpdateSampleCount(self_p->mp4_parser.mp4_aud_parser_p, MP4_TRACK_AUDIO);

    /*------------------------ Open a handler ---------------------------*/
    /* Get audio type */
    self_p->audio_format = MP4_Audio_Type_To_Media_Format(MP4_GetAudioType(self_p->mp4_parser.mp4_aud_parser_p));
    _AUD_PLAYER_MP4_TRACE(self_p->audio_format, -1, -1);

    /* The audio format in 3GP/MP4 file */
    switch (self_p->audio_format)
    {
    #ifdef AMR_DECODE    
        case MEDIA_FORMAT_MP4_AMR:
    #ifdef AMRWB_DECODE        
        case MEDIA_FORMAT_MP4_AMR_WB:
    #endif         
            vp_param.mediaType = self_p->audio_format;
            vp_param.vmParam = (kal_uint32) MEDIA_VMP_AS_RINGTONE;
            param_p = &vp_param;        
            open_fct = AMR_Open;
            break;
    #endif /*AMR_DECODE*/
    #if defined(AAC_DECODE)            
        case MEDIA_FORMAT_MP4_AAC:
            open_fct = AAC_Open;
            break;
    #endif /*AAC_DECODE*/            
    #if defined(BSAC_DECODE)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        default:
            med_result = MED_RES_INVALID_FORMAT;
            goto mp4_open_failed;
    }

    /* Open a handler */
    if (cfg_p->cb_fct)
    {
        self_p->mhdl_handle_p = open_fct(_aud_player_mp4_event_callback_fct, NULL, param_p);
    }
    else
    {
        /* In case the client doesn't need to received callback events, we should not need to hook callback
         * function to l1audio. This is important especially when two MHdl handlers are possible to be opened
         * concurrently. e.g. Building cache. If we hook callback functions to two MHdl handlers, l1audio will 
         * not be able to distinguish which handler is being played and may fail to callback to correct handler.
         */
        self_p->mhdl_handle_p = open_fct(NULL, NULL, param_p);
    }
    
    if (self_p->mhdl_handle_p == NULL)
    {
        med_result = MED_RES_BAD_FORMAT;
        goto mp4_open_failed; 
    }
    
    _AUD_PLAYER_MP4_TRACE(player_p, self_p->audio_format, -1);
    
    /* Attach user data to MHdl handle */
    self_p->mhdl_handle_p->SetUserData(self_p->mhdl_handle_p, (void*)player_p);

    /*------------------------ Setup private data ---------------------------*/
    self_p->state = AUD_MEDIA_IDLE;
    self_p->start_time = 0;
    self_p->stop_time = 0;
    self_p->cb_fct = cfg_p->cb_fct;
    self_p->cb_param = cfg_p->cb_param;
    
    return MED_RES_OK;

    /*------------------------ Error handling -------------------------------*/
mp4_open_failed:
    /* Close the MP4 player */
    _aud_player_mp4_close(player_p);

    return med_result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_mp4_play
 * DESCRIPTION
 *  This function is used to start MP4 playback.
 * PARAMETERS
 *  player_p      [IN]        Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_mp4_play(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_mp4_t* self_p;
    MP4_Parser_Status     mp4_parser_ret;
    Media_Status          drv_result;
    kal_int32             med_result;
    kal_uint32            start_time;
    kal_uint32            duration;
    kal_bool              has_vid_track = KAL_FALSE;
    kal_bool              is_data_finish = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_mp4_t, itf);
    MED_ASSERT(self_p->mhdl_handle_p != NULL);

    /* Directly return if the player is not in idle state */
    if (self_p->state != AUD_MEDIA_IDLE)
    {
        return MED_RES_FAIL;
    }
    
    start_time = self_p->start_time;
    
    /* Get audio duration */
    med_result = _aud_player_mp4_get_duration(player_p, MP4_TRACK_AUDIO, &duration);
    _AUD_PLAYER_MP4_TRACE(med_result, duration, -1);
    
    if (med_result != MED_RES_OK)
    {
        return MED_RES_FAIL;
    }

    /* Seek to MP4 frame by using start time */
    {
        kal_uint32 sample_no = 0;
        
        mp4_parser_ret = MP4_Audio_TimeToSampleNo(self_p->mp4_parser.mp4_aud_parser_p, start_time, &sample_no);
        _AUD_PLAYER_MP4_TRACE(mp4_parser_ret, -1, -1);
        
        if((mp4_parser_ret == MP4_PARSER_NO_SUCH_SAMPLE) && (start_time >= duration))
        {
            return MED_RES_END_OF_FILE;
        }
        else if(mp4_parser_ret != MP4_PARSER_OK)
        {
            return MED_RES_FAIL;
        }

        mp4_parser_ret = MP4_Audio_Seek(self_p->mp4_parser.mp4_aud_parser_p, sample_no);
        _AUD_PLAYER_MP4_TRACE(mp4_parser_ret, -1, -1);
        
        if(mp4_parser_ret != MP4_PARSER_OK)
        {
            return MED_RES_FAIL;
        }
    }
    
    /* Allocate ring buffer */
    aud_util_alloc_ring_buffer_ext(AUD_RING_BUFFER_SIZE, &self_p->ring_buffer_p);
    self_p->mhdl_handle_p->SetBuffer(self_p->mhdl_handle_p, (kal_uint8*)self_p->ring_buffer_p, AUD_RING_BUFFER_SIZE);

    /* Configure data request criteria */
    self_p->mhdl_handle_p->SetDataRequestThreshold(self_p->mhdl_handle_p, MEDIA_DATA_COMSUME_MODE, AUD_MP4_BUF_THRESHOLD, NULL);
    
    /* Fill up ring buffer before play */
    {
        kal_uint8 *buf_p;
        kal_uint32 num_byte;
        kal_uint32 buf_len;

        /* Need to fill up header for amr/awb playback */
        if (self_p->audio_format == MEDIA_FORMAT_MP4_AMR)
        {
            self_p->mhdl_handle_p->GetWriteBuffer(self_p->mhdl_handle_p, &buf_p, &buf_len);
            kal_mem_cpy(buf_p, AMR_HEADER, strlen(AMR_HEADER));
            self_p->mhdl_handle_p->WriteDataDone(self_p->mhdl_handle_p, strlen(AMR_HEADER));
        }
        else if (self_p->audio_format == MEDIA_FORMAT_MP4_AMR_WB)
        {
            self_p->mhdl_handle_p->GetWriteBuffer(self_p->mhdl_handle_p, &buf_p, &buf_len);
            kal_mem_cpy(buf_p, AWB_HEADER, strlen(AWB_HEADER));
            self_p->mhdl_handle_p->WriteDataDone(self_p->mhdl_handle_p, strlen(AWB_HEADER));
        }
        
        /* Fill ring buffer up to AUD_MP4_BUF_FILL_SIZE */
        self_p->mhdl_handle_p->GetWriteBuffer(self_p->mhdl_handle_p, &buf_p, &buf_len);
        
        if (buf_len > AUD_MP4_BUF_FILL_SIZE)
        {
            buf_len = AUD_MP4_BUF_FILL_SIZE;
        }
        
        mp4_parser_ret = MP4_Audio_Read(self_p->mp4_parser.mp4_aud_parser_p, buf_p, buf_len, &num_byte);
        _AUD_PLAYER_MP4_TRACE(mp4_parser_ret, buf_len, num_byte);
    
        if ((num_byte == 0) && (start_time >= duration))
        {
            return MED_RES_END_OF_FILE;
        }
        
        if (mp4_parser_ret == MP4_PARSER_READ_EOF)
        {
            is_data_finish = KAL_TRUE;
        }
        else if (mp4_parser_ret != MP4_PARSER_OK)
        {
            return MED_RES_FAIL;
        }

        self_p->mhdl_handle_p->WriteDataDone(self_p->mhdl_handle_p, num_byte);
    } 
    
    /* Always disable Audio Post Processing no matter there is video track or not */
    AudioPP_DisableBesSound();
    
    /* Begin to play */
    drv_result = self_p->mhdl_handle_p->Play(self_p->mhdl_handle_p);
    _AUD_PLAYER_MP4_TRACE(drv_result, self_p->mhdl_handle_p, -1);
    
    if (drv_result == MEDIA_SUCCESS)
    {
        /* enter AUD_MEDIA_PLAY state */
        self_p->state = AUD_MEDIA_PLAY;
    
        /* To prevent EOF flag from being reset in the Play callback function, we should 
         * notify L1Audio with data-finished indicator here.
         */
        if (is_data_finish)
        {
            self_p->mhdl_handle_p->DataFinished(self_p->mhdl_handle_p);
        }
    }
    else
    {
        /* Free ring buffer if failed to play */
        AUD_PLAYER_FREE_RING_BUF(self_p->ring_buffer_p);
    }
    
    return aud_get_res(drv_result);
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_mp4_stop
 * DESCRIPTION
 *  This function is used to stop MP4 playback.
 * PARAMETERS
 *  player_p      [IN]        Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_mp4_stop(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_mp4_t* self_p;
    Media_Status          drv_result = MEDIA_NO_HANDLER;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_mp4_t, itf);
    MED_ASSERT(self_p->mhdl_handle_p != NULL);
    
    drv_result = self_p->mhdl_handle_p->Stop(self_p->mhdl_handle_p);  
    _AUD_PLAYER_MP4_TRACE(drv_result, self_p->mhdl_handle_p, -1);
    
    if (drv_result == MEDIA_SUCCESS)
    {      
        /* enter AUD_MEDIA_IDLE state */
        self_p->state = AUD_MEDIA_IDLE;
    }
    
    /* Free ring buffer */
    AUD_PLAYER_FREE_RING_BUF(self_p->ring_buffer_p);
    
    /* Remember to enable audio post-processing */
    AudioPP_EnableBesSound();
    
    return aud_get_res(drv_result);
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_mp4_pause
 * DESCRIPTION
 *  This function is used to pause MP4 playback.
 * PARAMETERS
 *  player_p      [IN]        Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_mp4_pause(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_mp4_t* self_p;
    Media_Status          drv_result = MEDIA_NO_HANDLER;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_mp4_t, itf);
    MED_ASSERT(self_p->mhdl_handle_p != NULL);

    /* Pause the playback */
    drv_result = self_p->mhdl_handle_p->Pause(self_p->mhdl_handle_p);
    _AUD_PLAYER_MP4_TRACE(drv_result, self_p->mhdl_handle_p, -1);

    /* Keep current time */
    self_p->start_time = self_p->mhdl_handle_p->GetCurrentTime(self_p->mhdl_handle_p);
    
    if (drv_result == MEDIA_SUCCESS)
    {
        /* enter AUD_MEDIA_PLAY_PAUSED state */
        self_p->state = AUD_MEDIA_PLAY_PAUSED;
    }
    
    return aud_get_res(drv_result);
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_mp4_resume
 * DESCRIPTION
 *  This function is used to resume MP4 playback.
 * PARAMETERS
 *  player_p      [IN]        Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_mp4_resume(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_mp4_t* self_p;
    kal_int32             med_result = MED_RES_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_mp4_t, itf);
    MED_ASSERT(self_p->mhdl_handle_p != NULL);

    /* Stop playback */
    med_result = _aud_player_mp4_stop(player_p);
    _AUD_PLAYER_MP4_TRACE(med_result, self_p->mhdl_handle_p, -1);

    /* Update start time */
    self_p->mhdl_handle_p->SetStartTime(self_p->mhdl_handle_p, self_p->start_time);

    /* Resume the playback */
    med_result = _aud_player_mp4_play(player_p);
    _AUD_PLAYER_MP4_TRACE(med_result, self_p->mhdl_handle_p, -1);
    
    if (med_result == MED_RES_OK)
    {
        /* enter AUD_MEDIA_PLAY state */
        self_p->state = AUD_MEDIA_PLAY;
    }
    
    return med_result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_mp4_set
 * DESCRIPTION
 *  This function is used to set parameters to an MP4 player.
 * PARAMETERS
 *  player_p      [IN]        Player handle.
 *  set_type      [IN]        Set command.
 *  data_p        [IN]        The data relative to the command.
 *  data_len      [IN]        The length of the data.
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_mp4_set(med_aud_player_t*    player_p,
                                     med_aud_player_set_t set_type,
                                     void*                data_p,
                                     kal_uint32           data_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_mp4_t* self_p;
    Media_Status          drv_result = MEDIA_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_mp4_t, itf);
    MED_ASSERT(self_p->mhdl_handle_p != NULL);

    _AUD_PLAYER_MP4_TRACE(set_type, (kal_uint32)data_p, data_len);
    
    switch (set_type)
    {
        case AUD_PLAYER_SET_CACHE_TABLE:
        {
            self_p->mhdl_handle_p->SetCacheTbl(self_p->mhdl_handle_p, (kal_uint8*)data_p, (kal_uint32)data_len);
            break;   
        }
        case AUD_PLAYER_SET_STORE_FLAG:
        {
            self_p->mhdl_handle_p->SetStoreFlag(self_p->mhdl_handle_p, (kal_bool)(kal_uint32)data_p);
            break;   
        }
        case AUD_PLAYER_SET_START_TIME:
        {
            kal_uint32 start_time = (kal_uint32)data_p;
            
            drv_result = self_p->mhdl_handle_p->SetStartTime(self_p->mhdl_handle_p, start_time);
            _AUD_PLAYER_MP4_TRACE(drv_result, start_time, self_p->mhdl_handle_p);
            
            if (drv_result == MEDIA_SUCCESS)
            {
                self_p->start_time = start_time;
            }
            
            break;
        }
        case AUD_PLAYER_SET_STOP_TIME:
        {
            kal_uint32 stop_time = (kal_uint32)data_p;
            
            drv_result = self_p->mhdl_handle_p->SetStopTime(self_p->mhdl_handle_p, stop_time);
            _AUD_PLAYER_MP4_TRACE(drv_result, stop_time, self_p->mhdl_handle_p);
            
            if (drv_result == MEDIA_SUCCESS)
            {
                self_p->stop_time = stop_time;
            }
            
            break;
        }
        case AUD_PLAYER_SET_LEVEL:
        {
            drv_result = self_p->mhdl_handle_p->SetLevel(self_p->mhdl_handle_p, (kal_uint8)(kal_uint32)data_p);
            break;
        }
        
        /* Unsupported commands. MP4 could quick jump to a specific time. 
         * There is no need to set buffer for building cache and restore file offset. 
         */
        /*
        case AUD_PLAYER_SET_BUFFER:
        case AUD_PLAYER_SET_FILE_OFFSET:
        */
        default:
            drv_result = MEDIA_UNSUPPORTED_OPERATION;
            break;
    }
    
    return aud_get_res(drv_result);
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_mp4_get
 * DESCRIPTION
 *  This function is used to get parameters from an MP4 player.
 * PARAMETERS
 *  player_p      [IN]        Player handle.
 *  get_type      [IN]        Set command.
 *  data_p        [OUT]       The data relative to the command.
 *  data_len      [IN]        Indicats the length of the data buffer.
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_mp4_get(med_aud_player_t*    player_p,
                                     med_aud_player_get_t get_type,
                                     void*                data_p,
                                     kal_uint32           data_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_mp4_t* self_p;
    kal_int32             med_result = MED_RES_PARAM_ERROR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL && data_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_mp4_t, itf);
    MED_ASSERT(self_p->mhdl_handle_p != NULL);
    
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
                *((kal_uint32*)data_p) = self_p->mhdl_handle_p->GetCurrentTime(self_p->mhdl_handle_p);
                med_result = MED_RES_OK;
            }
            
            break;
        }
        case AUD_PLAYER_GET_DURATION:
        {
            kal_uint32 duration;
            
            if (data_len >= sizeof(kal_uint32))
            {
                med_result = _aud_player_mp4_get_duration(player_p, MP4_TRACK_AUDIO, &duration);
                
                *((kal_uint32*)data_p) = duration;
                med_result = MED_RES_OK;
            }
            
            break;
        }
        case AUD_PLAYER_GET_LEVEL:
        {
            if (data_len >= sizeof(kal_uint8))
            {
                *((kal_uint8*)data_p) = self_p->mhdl_handle_p->GetLevel(self_p->mhdl_handle_p);
                med_result = MED_RES_OK;
            }

            break;
        }
        case AUD_PLAYER_GET_CONTENT_DESC:
        {
            if (data_len >= sizeof(audInfoStruct))
            {
                med_result = MP4_GetContentDescInfo(&self_p->fsal_handle, (audInfoStruct*)data_p, NULL);
            }
            
            break;
        }
        case AUD_PLAYER_GET_MHDL_HANDLE:
        {
            if (data_len >= sizeof(MHdl*))
            {
                *((MHdl**)data_p) = self_p->mhdl_handle_p;
                med_result = MED_RES_OK;
            }

            break;
        }
        
        /* MP4 player specific commands */
        case MP4_PLAYER_GET_VIDEO_DURATION:
        {
            kal_uint32 duration;
            
            if (data_len >= sizeof(kal_uint32))
            {
                med_result = _aud_player_mp4_get_duration(player_p, MP4_TRACK_VIDEO, &duration);
            
                *((kal_uint32*)data_p) = duration;
            }
            
            break;
        }
        case MP4_PLAYER_GET_IS_AUDIO_ONLY:
        {
            kal_bool is_aud_track_only = KAL_FALSE;
            kal_bool has_aud_track, has_vid_track;
            
            if (data_len >= sizeof(kal_bool))
            {
                _aud_player_mp4_has_audio_track(self_p->mp4_parser.mp4_aud_parser_p, &has_aud_track);
                _aud_player_mp4_has_video_track(self_p->mp4_parser.mp4_aud_parser_p, &has_vid_track);
                
                if (has_aud_track && (!has_vid_track))
                {
                    is_aud_track_only = KAL_TRUE;
                }
                
                *((kal_bool*)data_p) = is_aud_track_only;
                med_result = MED_RES_OK;
            }
            
            break;
        }
    #if defined(__BES_TS_SUPPORT__)        
        case MP4_PLAYER_GET_IS_POST_PROCESS_SUPPORT:
        {
            if (data_len >= sizeof(kal_bool))
            {
                *((kal_bool*)data_p) = AudioPP_TS_IsSupport(self_p->audio_format, &self_p->fsal_handle);
                med_result = MED_RES_OK;
            }
            
            break;
        }
    #endif /* __BES_TS_SUPPORT__) */
    
        /* Unsupported commands. MP4 could quick jump to a specific time. 
         * There is no need to build cache and store last offset. 
         */
        /*
        case AUD_PLAYER_GET_LAST_OFFSET:
        */
        default:
            med_result = MED_RES_UNSUPPORTED_OPERATION;
            break;
    }

    _AUD_PLAYER_MP4_TRACE(get_type, med_result, *((kal_uint32*)data_p));
    
    return med_result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_mp4_destroy
 * DESCRIPTION
 *  This function is used to destroy an MP4 player. Once called, all the 
 *  allocated interfaces of the player will be freed.
 * PARAMETERS
 *  player_p      [IN]        Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_mp4_destroy(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_mp4_t* self_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(player_p != NULL);
    self_p = PTHIS(player_p, med_aud_player_mp4_t, itf);
    
    AUD_PLAYER_FREE_AUD_MEM(self_p);
    
    return MED_RES_OK;
}
#endif /* __MTK_TARGET__ && MED_PURE_AUDIO */

/*-----------------------------------------------------------------------------
                    public functions
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  aud_player_mp4_construct
 * DESCRIPTION
 *  This function is used to construct a MP4 player.
 * PARAMETERS
 *  void
 * RETURNS
 *  Player handle.
 *****************************************************************************/
med_aud_player_t* aud_player_mp4_construct(void)
{
#if defined(__MTK_TARGET__) && defined(MED_PURE_AUDIO)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_mp4_t* self_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = (med_aud_player_mp4_t*) med_alloc_aud_mem(sizeof(med_aud_player_mp4_t));
    MED_ASSERT(self_p != NULL);

    kal_mem_set(self_p, 0, sizeof(*self_p));

    self_p->itf.open       = _aud_player_mp4_open;
    self_p->itf.close      = _aud_player_mp4_close;
    self_p->itf.play       = _aud_player_mp4_play;
    self_p->itf.stop       = _aud_player_mp4_stop;
    self_p->itf.pause      = _aud_player_mp4_pause;
    self_p->itf.resume     = _aud_player_mp4_resume;
    self_p->itf.set        = _aud_player_mp4_set;
    self_p->itf.get        = _aud_player_mp4_get;
    self_p->itf.destroy    = _aud_player_mp4_destroy;

    kal_get_time(&self_p->time_stamp);
    
    return &self_p->itf;
#else
    return NULL;
#endif /* __MTK_TARGET__ && MED_PURE_AUDIO */
}

#endif /* MED_NOT_PRESENT */ 

