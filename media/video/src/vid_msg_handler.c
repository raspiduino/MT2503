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
 *   vid_msg_handler.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes message handle functions of video module.
 *
 * Author:
 * -------
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef MED_NOT_PRESENT

/*****************************************************************************
 * Include
 *****************************************************************************/
/* system includes */
#include "kal_trace.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"         /* Task message communiction */

/* global includes */
//#include "l1audio.h"
//#include "custom_video.h"

#include "visual_comm.h"

/* local includes */
#include "med_global.h"
#include "med_status.h"
#include "med_main.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_utility.h"
#include "med_smalloc.h"
#include "vid_main.h"
#include "aud_main.h"
#include "lcd_if.h"


#if defined(__MED_TVO_MOD__)
#include "tv_out.h"
#endif

#include "img_common_enum.h"

#ifdef __VID_TRACE_ON__
#include "med_trc.h"
#endif

#include "Fs_errcode.h"

#if defined(__MED_VID_DEC_MOD__)

#include "vid_if.h"

#include "kal_general_types.h"
#include "mpl_player.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "stack_config.h"
#include "mp4_common.h"
#include "string.h"
#include "drv_sw_features_video.h"

#ifdef __MM_DCM_SUPPORT__ 
#include "dcmgr.h"
#endif

/*****************************************************************************
 * Define
 *****************************************************************************/

#define VID_DEC_SEEK_HINT_SIZE          (2047)

typedef MHdl *(*vid_aud_open_func_ptr) (void (*handler) (MHdl *hdl, Media_Event event), STFSAL *pstFSAL, void *param);

/* stop time */
#define VID_STOP_DELAY_OPEN_ELAPSE  (2000)
#define VID_THUMBNAIL_TIME (200)

/*****************************************************************************
 * Typedef
 *****************************************************************************/

/*****************************************************************************
 * Variable
 *****************************************************************************/
/*****************/
/*    DECODER    */
/*****************/
kal_int32 vid_play_mem[2] = {0, MAX_MED_VID_DEC_EXT_MEM_SIZE};


mpl_player_t *player_p;
mpl_player_client_t mpl_player_client;



/*****************************************************************************
 * Local Functions
 *****************************************************************************/
void vid_get_info(kal_bool file_mode);
void vid_destroy_player(void);
kal_bool vid_delay_open_internal(void);
kal_bool vid_open_req_internal_hdlr(ilm_struct *ilm_ptr);
kal_bool vid_close_req_internal_hdlr(ilm_struct *ilm_ptr);
#ifdef __MM_DCM_SUPPORT__
void vid_dcm_load(void);
void vid_dcm_unload(void);
#endif

/*****************************************************************************
 * FUNCTION
 *  vid_check_camera_is_idle
 * DESCRIPTION
 *  Check camera is idle or not
 * PARAMETERS
 *  void
 * RETURNS
 *  Idle or not
 *****************************************************************************/
kal_bool vid_chcek_camera_is_idle(void)
{
#if defined(__MED_CAM_MOD__)
    return (kal_bool)CAM_IN_STATE(CAM_IDLE);
#else
    return KAL_TRUE;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  vid_delay_open_timeout_hdlr
 * DESCRIPTION
 *  cancel delay open
 * PARAMETERS
 *  arg         [IN]        not used
 * RETURNS
 *  void
 *****************************************************************************/
void vid_delay_open_timeout_hdlr(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (VID_IN_STATE(VID_DELAY_OPEN))
    {
        /* delay open timeout, treat it as open fail case */
        VID_ENTER_STATE(VID_FILE_MERGE);
        vid_set_result_and_event(MED_RES_BUSY, VID_EVT_OPEN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_delay_open
 * DESCRIPTION
 *  vid delay open
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void vid_delay_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MM_DCM_SUPPORT__    
    vid_dcm_load();
#endif
    
    if (!vid_delay_open_internal())
    {
    #ifdef __MM_DCM_SUPPORT__    
        vid_dcm_unload();
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_open_req_hdlr
 * DESCRIPTION
 *  Handle open video request.
 * PARAMETERS
 *  ilm_ptr     [IN]        msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_open_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_open_req_struct *req_p;
    mpl_player_open_t open_struct;
    kal_int32 result;
    media_error_t ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_OPEN_REQ_HDLR, vid_context_p->state);

    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_vid_open_req_struct*) ilm_ptr->local_para_ptr;

    /* reserve some parameters for delay-open */
    vid_context_p->seq_num = req_p->seq_num;
    vid_context_p->media_mode = req_p->media_mode;
    vid_context_p->open_track = req_p->open_track;
    vid_context_p->media_type = req_p->media_type;
    vid_context_p->current_time = 0;
    vid_context_p->blocking = req_p->blocking;
    vid_context_p->is_enable_aud_only = req_p->enable_aud_only;

    vid_context_p->scenario_id = req_p->scenario;
#ifdef __VIDEO_SUBTITLE_SUPPORT__    
    vid_context_p->extern_api.prFontEngineApi = req_p->extern_api.prFontEngineApi;
    vid_context_p->extern_api.pfnIsLCCSupported = req_p->extern_api.pfnIsLCCSupported;
#endif

#if defined(__MED_CAM_MOD__)
    //cam_abort_to_idle();
#endif

    if (vid_chcek_camera_is_idle() && VID_IN_STATE(VID_IDLE))
    {
    #ifdef __MM_DCM_SUPPORT__    
        vid_dcm_load();
    #endif

        if (!vid_open_req_internal_hdlr(ilm_ptr))
        {
        #ifdef __MM_DCM_SUPPORT__    
            vid_dcm_unload();
        #endif
        }
    }
    else if (VID_IN_STATE(VID_FILE_MERGE))
    {
        vid_context_p->app_id = req_p->app_id;

        if (vid_context_p->media_mode == MED_MODE_FILE)
        {
            kal_mem_cpy(vid_context_p->current_file_name, (void*)req_p->data, MAX_FILE_NAME_LEN * 2);
        }
        else if (vid_context_p->media_mode == MED_MODE_ARRAY)
        {
            vid_context_p->file_buffer_address = (kal_uint32) req_p->data;
            vid_context_p->file_size = req_p->data_size;
        }
        VID_ENTER_STATE(VID_DELAY_OPEN);
        /* after file merge done, we will open file */
        med_start_timer(VID_DELAY_OPEN_TIMER, VID_STOP_DELAY_OPEN_ELAPSE, vid_delay_open_timeout_hdlr, 0);

        return;
    }
    else
    {
        vid_set_result_and_event(MED_RES_BUSY, VID_EVT_OPEN);
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_close_req_hdlr
 * DESCRIPTION
 *  Handle close video request.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_close_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_CLOSE_REQ_HDLR, vid_context_p->state);

    if (vid_close_req_internal_hdlr(ilm_ptr))
    {
    #ifdef __MM_DCM_SUPPORT__    
        vid_dcm_unload();
    #endif
    }
}

void vid_on_open_callback(mpl_player_client_t *client, media_error_t ret)
{
    kal_int32 result = med_error_to_result_enum(ret);

    if (VID_IN_STATE(VID_OPEN_FILE)||VID_IN_STATE(VID_FILE_READY))
    {
        if (result == MED_RES_OK || result == MED_RES_MP4_NO_VIDEO_TRACK)
        {
            vid_get_info(KAL_TRUE);

            VID_ENTER_STATE(VID_FILE_READY);
        }
        else
        {
            vid_destroy_player();
        #ifdef __MM_DCM_SUPPORT__    
            vid_dcm_unload();
        #endif      
        }

        if (!vid_context_p->blocking)
        {
            vid_send_file_ready_ind(result);
        }
    }
}


void vid_on_close_callback(mpl_player_client_t *client, media_error_t ret)
{
    kal_int32 result = med_error_to_result_enum(ret);
    if (VID_IN_STATE(VID_PLAY_CLOSE_VISUAL))
    {
        switch (result)
        {
            case MED_RES_OK:
                vid_destroy_player();
                vid_set_result_and_event(result, VID_EVT_CLOSE);
            #ifdef __MM_DCM_SUPPORT__    
                vid_dcm_unload();
            #endif    
                break;
            default:
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_is_audio_channel_available
 * DESCRIPTION
 *  Check if the audio channel is avaiable.
 * PARAMETERS
 *  void
 * RETURNS
 *  Avaialbe or not
 *****************************************************************************/
kal_bool vid_is_audio_channel_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool if_playing;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_IS_AUDIO_CHANNEL_AVAILABLE, vid_context_p->state);


    if (VID_IN_STATE(VID_RECORD) ||
        VID_IN_STATE(VID_RECORD_FINISH) ||
        VID_IN_STATE(VID_RECORD_PAUSED) ||
        VID_IN_STATE(VID_RECORD_STOP_VISUAL))
    {
        return KAL_FALSE;
    }

    if (player_p)
    {
        player_p->get_param(player_p, MPL_PARAM_AUD_PLAYING, (void*)&if_playing);

        if (if_playing)
        {
            return KAL_FALSE;
        }
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  vid_is_dummy_aud_playing
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  is dummy aud play nor not
 *****************************************************************************/
kal_bool vid_is_dummy_aud_playing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool if_playing;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (player_p)
    {
        player_p->get_param(player_p, MPL_PARAM_DUMMY_AUD_PLAYING, (void*)&if_playing);
        return if_playing;
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  vid_stop_unfinished_task
 * DESCRIPTION
 *  This function is to stop video play.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_stop_unfinished_task(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_result_enum result;
    media_error_t ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_STOP_UNFINISHED_TASK, vid_context_p->state);

    if (VID_IN_STATE(VID_PLAY))
    {
        ret = player_p->stop_play(player_p);
        result = med_error_to_result_enum(ret);

        VID_ENTER_STATE(VID_FILE_READY);
        vid_send_play_finish_ind(MED_RES_AUDIO_ERROR);

    }
    else
    {
        //do nothing
    }
}


#ifdef __MED_VID_PDL_MOD__

/*****************************************************************************
 * FUNCTION
 *  vid_check_is_pdl_req_hdlr
 * DESCRIPTION
 *  Get pdl max play time.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_check_is_pdl_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_check_is_pdl_req_struct *msg_p =
        (media_vid_check_is_pdl_req_struct*) ilm_ptr->local_para_ptr;

    kal_bool is_pdl = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_CHECK_IS_PDL_REQ_HDLR, vid_context_p->state);

    #if defined(__M3GPMP4_FILE_FORMAT_SUPPORT__)
    	mp4_mp_is_prog_dl_file(msg_p->file_buf_p, msg_p->buf_size, &is_pdl);
    #endif
	
    if (is_pdl)
    {
        vid_set_result(MED_RES_OK, __LINE__);
    }
    else
    {
        vid_set_result(MED_RES_FAIL, __LINE__);
    }

    vid_set_event(VID_EVT_GET_INFO);
}
#endif /* __MED_VID_PDL_MOD__ */

/*****************************************************************************
 * FUNCTION
 *  vid_set_param_req_hdlr
 * DESCRIPTION
 *  Set Video parameter request.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_set_param_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_set_param_req_struct *req_p;
    kal_uint32 value;
    kal_uint8 val;
    media_error_t error;
    med_result_enum result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    req_p = (media_vid_set_param_req_struct*) ilm_ptr->local_para_ptr;

    switch (req_p->param_id)
    {
    #if defined(VA2_RENDERER_VP_VIDEO_PROCESSING_SUPPORTED)
        case VID_PARAM_CONTRAST:
            value = (kal_uint32)req_p->value;
            player_p->set_param(player_p,MPL_PARAM_CONTRAST, (void*)&value);
            break;
        case VID_PARAM_BRIGHTNESS:
            value = (kal_uint32) req_p->value;
            player_p->set_param(player_p,MPL_PARAM_BRIGHTNESS, (void*)&value);
            break;
    #endif  /* VA2_RENDERER_VP_VIDEO_PROCESSING_SUPPORTED */

    #ifdef __VIDEO_3D_ANAGLYPH__
        case VID_PARAM_TRACK_INDEX:
            value = (kal_uint32) req_p->value;
            player_p->set_param(player_p,MPL_PARAM_VID_TRACK, (void*)&value);
            break;
    #endif /* __VIDEO_3D_ANAGLYPH__ */

    #ifdef __VIDEO_SUBTITLE_SUPPORT__
        case VID_PARAM_SUBTITLE_TRACK:
            value = (kal_uint32) req_p->value;
            player_p->set_param(player_p,MPL_PARAM_SET_SUBTITLE_TRACKS, (void*)&value);
            break;
        case VID_PARAM_SUBTITLE_FONT_SIZE:
            val = (kal_uint8) req_p->value;
            player_p->set_param(player_p,MPL_PARAM_SET_FONT_SIZE, (void*)&val);
            break;
    #endif /* __VIDEO_SUBTITLE_SUPPORT__ */

    #if defined (SUPPORT_MMAPI)
        case VID_PARAM_SLEEP_TIME:
        {
            mpl_player_param_sleep_time_t *sleep = (mpl_player_param_sleep_time_t *)req_p->value;

            /* READY or PLAYING state */
            if (!VID_IN_STATE(VID_IDLE) && !VID_IN_STATE(VID_OPEN_FILE))
            {
                player_p->set_param(player_p, MPL_PARAM_SLEEP_TIME, (void*)sleep);
            }
            break;
        }


        case VID_PARAM_STOP_TIME:
        {
            media_vid_stop_time_struct *stop = (media_vid_stop_time_struct *)req_p->value;
            player_p->set_param(player_p, MPL_PARAM_STOP_TIME, (void*)&stop->stop_time);
            break;
        }
    #endif /* SUPPORT_MMAPI */

    #if (defined(PGDL_SUPPORT_YOUTUBE)&& defined(__M3GPMP4_FILE_FORMAT_SUPPORT__))  
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif    
        default:
            break;
    }
    vid_set_event(VID_EVT_BLOCK);
}


#ifdef __MM_DCM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  vid_dcm_load
 * DESCRIPTION
 *  This function is to load DCM
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void vid_dcm_load(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    DCM_Load(DYNAMIC_CODE_COMPRESS_VIDMSG, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  vid_dcm_unload
 * DESCRIPTION
 *  This function is to unload DCM
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void vid_dcm_unload(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DCM_Unload(DYNAMIC_CODE_COMPRESS_VIDMSG);
}

#pragma arm section code = "DYNAMIC_CODE_VIDMSG_ROCODE", rodata = "DYNAMIC_CODE_VIDMSG_RODATA"

#endif

/*****************************************************************************
 * FUNCTION
 *  vid_stop_req_hdlr
 * DESCRIPTION
 *  This function is to handle video stop request
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    media_error_t ret = MED_S_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_STOP_REQ_HDLR, vid_context_p->state);

    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    if (VID_IN_STATE(VID_PLAY))
    {
        ret = player_p->stop_play(player_p);
        result = med_error_to_result_enum(ret);

        vid_set_result_and_event(result, VID_EVT_STOP);
        VID_ENTER_STATE(VID_FILE_READY);

        return;
    }
    else if (VID_IN_STATE(VID_SEEK))
    {
        player_p->stop_seek(player_p);

        VID_ENTER_STATE(VID_FILE_READY);
        vid_set_event(VID_EVT_STOP);
        return;
    }
    else
    {
        /**
         * When doing nothing in stop request handler, we set result as ALREADY_STOPPED,
         * In other case, we use default MED_RES_OK in vid_api.c.
         */
        vid_set_result_and_event(MED_RES_VIDEO_ALREADY_STOPPED, VID_EVT_STOP);

        return;
    }
}

void vid_get_info(kal_bool file_mode)
{
    kal_int32 handle, idx;
    kal_bool is_seekable;
#ifdef __VIDEO_CLIPPER_SUPPORT__
    kal_bool is_proprietary;
#endif
    mpl_player_get_media_info_t media_info;
    mpl_player_track_info_t track_info;
    mpl_player_video_track_info_t *track_p;
#ifdef __VIDEO_SUBTITLE_SUPPORT__
    mpl_player_subtitle_track_info_t *subtitle_p;
#endif
    if (file_mode)
    {
        player_p->get_param(player_p, MPL_PARAM_FILE_HANDLE, (void*)&handle);
        vid_context_p->file_handle = handle;
    }

    player_p->get_param(player_p, MPL_PARAM_IS_SEEKABLE, (void*)&is_seekable);
    vid_context_p->is_seekable = is_seekable;

#ifdef __VIDEO_CLIPPER_SUPPORT__
    player_p->get_param(player_p, MPL_PARAM_IS_PROPRIETARY_FORMAT, (void*)&is_proprietary);
    vid_context_p->is_proprietary = is_proprietary;
#endif /* __VIDEO_CLIPPER_SUPPORT__ */

    player_p->get_media_info(player_p, &media_info);
    vid_context_p->total_time = media_info.duration;
    vid_context_p->image_width = media_info.width;
    vid_context_p->image_height = media_info.height;
    vid_context_p->audio_sample_rate = media_info.audio_sampling_rate;
    vid_context_p->audio_channel_no = media_info.audio_channel_num;

#ifdef __VIDEO_3D_ANAGLYPH__
    /* Get track info */
    kal_mem_set(&track_info, 0, sizeof(mpl_player_track_info_t));
    player_p->get_param(player_p, MPL_PARAM_VID_TRACK, (void*)&track_info);

    vid_context_p->track_num = track_info.u4Num;
    track_p = (mpl_player_video_track_info_t *)track_info.pvTrackInfo;
    for (idx = 0; idx < track_info.u4Num && idx < VID_MAX_VIDEO_TRACK_NUM; idx ++)
    {
        vid_context_p->track_info[idx] = track_p[idx];
    }
#endif /* __VIDEO_3D_ANAGLYPH__ */

#ifdef __VIDEO_SUBTITLE_SUPPORT__
    /* Get subtitle track info */
    kal_mem_set(&track_info, 0, sizeof(mpl_player_track_info_t));
    player_p->get_param(player_p, MPL_PARAM_GET_SUBTITLE_TRACKS, (void*)&track_info);

    vid_context_p->subtitle_num = track_info.u4Num;
    subtitle_p = (mpl_player_subtitle_track_info_t *)track_info.pvTrackInfo;
    for (idx = 0; idx < track_info.u4Num && idx < VID_MAX_VIDEO_SUBTITLE_NUM; idx ++)
    {
        vid_context_p->subtitle_info[idx] = subtitle_p[idx];
    }
#endif
}

void vid_destroy_player(void)
{
    if (player_p)
    {
        player_p->destroy(player_p);
        player_p = NULL;
        VID_ENTER_STATE(VID_IDLE);
    }  
}

void vid_on_play_callback(mpl_player_client_t *client, media_error_t ret)
{
    kal_int32 result = med_error_to_result_enum(ret);

    if (VID_IN_STATE(VID_PLAY))
    {
        switch (result)
        {
            case MED_RES_PLAY_FINISH:
                vid_send_play_finish_ind(MED_RES_OK);
                VID_ENTER_STATE(VID_FILE_READY);
                break;
            case MED_RES_VIDEO_TRACK_ERROR:
            case MED_RES_AUDIO_TRACK_ERROR:

                /* Don't change state */
                vid_send_play_finish_ind(result);
                break;
            default:
                vid_send_play_finish_ind(result);
                VID_ENTER_STATE(VID_FILE_READY);
                break;
        }
    }
}

void vid_on_seek_callback(mpl_player_client_t *client, media_error_t ret)
{
    kal_int32 result = med_error_to_result_enum(ret);
    if (VID_IN_STATE(VID_SEEK))
    {
        if (vid_context_p->blocking)
        {
            vid_set_result_and_event(result, VID_EVT_SEEK);
        }
        else
        {
            vid_send_seek_done_ind(result);
        }

        VID_ENTER_STATE(VID_FILE_READY);
    }
}

void vid_on_event_callback(mpl_player_client_t *client, mpl_player_event_t event, media_error_t result)
{

    switch(event)
    {
        case MPL_PLAYER_EVENT_OPEN:
            vid_on_open_callback(client, result);
            break;
        case MPL_PLAYER_EVENT_SEEK:
            vid_on_seek_callback(client, result);
            break;
        case MPL_PLAYER_EVENT_PLAY:
            vid_on_play_callback(client, result);
            break;
        case MPL_PLAYER_EVENT_CLOSE:
            vid_on_close_callback(client, result);
            break;
        default:
            break;
    }

}


void *vid_on_alloc_callback(mpl_player_client_t *client, kal_uint32 size, med_mem_type_enum type, char* file_p, long line_p)
{
    void *mem_ptr = NULL;

    if (type == MED_MEM_NONCACHE)
    {
        mem_ptr = med_alloc_mem(vid_context_p->app_id, size, file_p, line_p);
    }
    else if (type == MED_MEM_CACHE)
    {
        mem_ptr = med_alloc_mem_cacheable(vid_context_p->app_id, size, file_p, line_p);
    }
    else if (type == MED_MEM_AUD_RINGBUFF)
    {
        aud_util_alloc_ring_buffer_w_log(file_p, line_p, size, (kal_uint16**)&mem_ptr);
    }

    return mem_ptr;
}


void vid_on_free_callback(mpl_player_client_t *client, void** p, med_mem_type_enum type, char* file_p, long line_p)
{
    if (*p == NULL)
    {
        return;
    }

    if (type == MED_MEM_NONCACHE)
    {
        med_free_mem(vid_context_p->app_id, p, file_p, line_p);
    }
    else if (type == MED_MEM_CACHE)
    {
        med_free_mem(vid_context_p->app_id, p, file_p, line_p);
    }
    else if (type == MED_MEM_AUD_RINGBUFF)
    {
        aud_util_free_ring_buffer_w_log(file_p, line_p, (kal_uint16**)p);
    }
    else
    {
        ASSERT(0);
    }

    *p = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  vid_construct_player
 * DESCRIPTION
 *  Construct player.
 * PARAMETERS
 *  ilm_ptr     [IN]        msg data
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 vid_construct_player(kal_uint8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (player_p != NULL)
    {
        ASSERT(0);
    }
    ret = MED_RES_MEM_INSUFFICIENT;

    mpl_player_client.on_event = vid_on_event_callback;
    mpl_player_client.mem_alloc_func = vid_on_alloc_callback;
    mpl_player_client.mem_free_func = vid_on_free_callback;

    switch(type)
    {
    #if defined(MP4_DECODE) || defined(MJPG_DECODE) || defined(__RM_DEC_SUPPORT__) || defined(__FLV_FILE_FORMAT_SUPPORT__) || defined(__MKV_FILE_FORMAT_SUPPORT__) || defined(__MOT_SUPPORT__) || defined(PGDL_SUPPORT_YOUTUBE)
#if defined(MP4_DECODE)
        case MED_TYPE_MP4:
        case MED_TYPE_3GP:
#endif /* MP4_DECODE */
#if defined(MJPG_DECODE)
        case MED_TYPE_MJPG:
#endif /* MJPG_DECODE */
#if defined(__RM_DEC_SUPPORT__)
        case MED_TYPE_RM:
        case MED_TYPE_RV:
        case MED_TYPE_RMVB:
    #endif /* __RM_DEC_SUPPORT__ */
    #if defined(__FLV_FILE_FORMAT_SUPPORT__)
        case MED_TYPE_FLV:
        case MED_TYPE_F4V:
    #endif /* __FLV_FILE_FORMAT_SUPPORT__ */
    #ifdef __MKV_FILE_FORMAT_SUPPORT__
        case MED_TYPE_MKV:
    #endif /* __MKV_FILE_FORMAT_SUPPORT__ */
    #ifdef __MOT_SUPPORT__
        case MED_TYPE_MOT:
    #endif
    #ifdef PGDL_SUPPORT_YOUTUBE
/* under construction !*/
    #endif /* PGDL_SUPPORT_YOUTUBE */
    #ifdef __KMV_SUPPORT__
        case MED_TYPE_KMV:
    #endif
        player_p = construct_media_session(&mpl_player_client);
            break;
    #endif /* All formats */
        default:
        ret = MED_RES_UNSUPPORTED_TYPE;
    }

    if (player_p)
    {
        return MED_RES_OK;
    }
    else
    {
        return ret;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_delay_open
 * DESCRIPTION
 *  vid delay open
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool vid_delay_open_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_result_enum ret;
    mpl_player_open_t open_struct;
    media_error_t result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* cancel check delay open timer */
    med_stop_timer(VID_DELAY_OPEN_TIMER);

    memset(&open_struct, 0, sizeof(mpl_player_open_t));

    open_struct.media_mode = vid_context_p->media_mode;

    if (vid_context_p->media_mode == MED_MODE_FILE)
    {
        open_struct.data = (void*)vid_context_p->current_file_name;
    }
    else if (vid_context_p->media_mode == MED_MODE_ARRAY)
    {
        open_struct.data = (void*)vid_context_p->file_buffer_address;
        open_struct.data_size = vid_context_p->file_size;
    }

    open_struct.media_type = vid_context_p->media_type;
    open_struct.open_track = vid_context_p->open_track;
    open_struct.enable_aud_only = vid_context_p->is_enable_aud_only;
    open_struct.app_id = vid_context_p->app_id;


    open_struct.scenario_id = vid_context_p->scenario_id;
#ifdef __VIDEO_SUBTITLE_SUPPORT__    
    open_struct.rExternalAPI.prFontEngineApi = vid_context_p->extern_api.prFontEngineApi;
    open_struct.rExternalAPI.pfnIsLCCSupported = vid_context_p->extern_api.pfnIsLCCSupported;
#endif
    
    /* construct player */
    ret = (med_result_enum) vid_construct_player(
                open_struct.media_type);
    if (ret != MED_RES_OK)
    {
        vid_set_result_and_event(ret, VID_EVT_OPEN);
        return KAL_FALSE;
    }

    VID_ENTER_STATE(VID_OPEN_FILE);

    result = player_p->open(player_p,&open_struct);

    ret = med_error_to_result_enum(result);


    if (ret == MED_RES_OK||ret == MED_RES_MP4_NO_VIDEO_TRACK)
    {
        vid_get_info(KAL_TRUE);

        VID_ENTER_STATE(VID_FILE_READY);
        vid_set_result_and_event(ret, VID_EVT_OPEN);
        return KAL_TRUE;
    }
    else
    {
        vid_destroy_player();    
        vid_set_result_and_event(ret, VID_EVT_OPEN);
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_open_req_hdlr
 * DESCRIPTION
 *  Handle open video request.
 * PARAMETERS
 *  ilm_ptr     [IN]        msg data
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool vid_open_req_internal_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_open_req_struct *req_p;
    mpl_player_open_t open_struct;
    kal_int32 result;
    media_error_t ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    req_p = (media_vid_open_req_struct*) ilm_ptr->local_para_ptr;
    
    vid_context_p->app_id = req_p->app_id;
    /* construct player */
    result = vid_construct_player(req_p->media_type);

    if (result != MED_RES_OK)
    {
        vid_set_result_and_event(result, VID_EVT_OPEN);
        return KAL_FALSE;
    }

    VID_ENTER_STATE(VID_OPEN_FILE);

    /* get default setting */
    player_p->get_default(player_p, MPL_OPEN_PARAM, &open_struct);

    open_struct.media_mode = req_p->media_mode;
    open_struct.media_type = req_p->media_type;
    open_struct.data = req_p->data;
    open_struct.data_size = req_p->data_size;
    open_struct.open_track = req_p->open_track;
    open_struct.enable_aud_only = req_p->enable_aud_only;
    open_struct.scenario_id = req_p->scenario;
#ifdef __VIDEO_SUBTITLE_SUPPORT__    
    open_struct.rExternalAPI.prFontEngineApi = req_p->extern_api.prFontEngineApi;
    open_struct.rExternalAPI.pfnIsLCCSupported = req_p->extern_api.pfnIsLCCSupported;
#endif    
    ret = player_p->open(player_p, &open_struct);
    result = med_error_to_result_enum(ret);

    if( result == MED_RES_OK_ASYNC)
    {
        result = MED_RES_OK;
        vid_set_result_and_event(result, VID_EVT_OPEN);
        return KAL_TRUE;
    }
    else if (result == MED_RES_OK || result == MED_RES_MP4_NO_VIDEO_TRACK)
    {
        vid_get_info(KAL_TRUE);

        VID_ENTER_STATE(VID_FILE_READY);
        vid_set_result_and_event(result, VID_EVT_OPEN);
        return KAL_TRUE;
    }
    else
    {
        vid_destroy_player();
        vid_set_result_and_event(result, VID_EVT_OPEN);
        return KAL_FALSE;
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  vid_close_req_hdlr
 * DESCRIPTION
 *  Handle close video request.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool vid_close_req_internal_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_result_enum result;
    media_error_t ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_CLOSE_REQ_HDLR, vid_context_p->state);

    vid_context_p->src_mod = ilm_ptr->src_mod_id;


    if (VID_IN_STATE(VID_FILE_READY) || VID_IN_STATE(VID_OPEN_FILE)
#ifdef __MED_VID_PDL_MOD__
     //   || VID_IN_STATE(VID_PDL_META_BUFFERING)
#endif
        )
    {
        ret = player_p->close(player_p);
        result = med_error_to_result_enum(ret);

        if (result == MED_RES_OK_ASYNC)
        {
            VID_ENTER_STATE(VID_PLAY_CLOSE_VISUAL);
            return KAL_FALSE;
        }
        else
        {
            vid_destroy_player();
            vid_set_event(VID_EVT_CLOSE);
            return KAL_TRUE;
        }
        
    }
    else if (VID_IN_STATE(VID_DELAY_OPEN))
    {
        VID_ENTER_STATE(VID_IDLE);
        vid_set_event(VID_EVT_CLOSE);
        return KAL_FALSE;
    }
    else
    {
        vid_set_result(MED_RES_BUSY, __LINE__);
        vid_set_event(VID_EVT_CLOSE);
        return KAL_FALSE;
    }


    
}


void vid_get_current_play_time(kal_uint64 *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (player_p != NULL)
    {
        player_p->get_param(player_p, MPL_PARAM_CURRENT_PLAY_TIME, (void*)&vid_context_p->current_time);
    }
    else
    {
        vid_context_p->current_time = 0;
    }

    /* avoid cur time > total time */
    if (vid_context_p->current_time > vid_context_p->total_time)
    {
        vid_context_p->current_time = vid_context_p->total_time;
    }

    *time = vid_context_p->current_time;

    kal_trace(TRACE_GROUP_4, VID_MMI_TRC_CUR_TIME, (kal_uint32)(*time), __LINE__);

}


/*****************************************************************************
 * FUNCTION
 *  vid_get_play_time_req_hdlr
 * DESCRIPTION
 *  Set stop time
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_get_play_time_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_get_play_time_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    req_p = (media_vid_get_play_time_req_struct*) ilm_ptr->local_para_ptr;

    vid_get_current_play_time(req_p->cur_time_p);

    vid_set_event(VID_EVT_GET_INFO);
}

/*****************************************************************************
 * FUNCTION
 *  vid_play_req_hdlr
 * DESCRIPTION
 *  Handle video play request
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_set_play_struct(media_vid_play_req_struct *req_p, mpl_player_play_t *play_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    play_struct->display_width = req_p->display_width;
    play_struct->display_height = req_p->display_height;
    play_struct->image_buffer_p = req_p->image_buffer_p;
#if defined(VA2_RENDERER_VP_VIDEO_PROCESSING_SUPPORTED)
    play_struct->contrast = req_p->contrast;
    play_struct->brightness = req_p->brightness;
#endif
    play_struct->play_speed = req_p->play_speed;
    play_struct->play_audio = req_p->play_audio;
    play_struct->display_device = req_p->display_device;
    play_struct->audio_path = req_p->audio_path;
    play_struct->lcd_id = req_p->lcd_id;
    play_struct->update_layer = req_p->update_layer;
    play_struct->hw_update_layer = req_p->hw_update_layer;
    play_struct->idp_rotate = req_p->idp_rotate;
    play_struct->image_data_format = req_p->image_data_format;
    play_struct->force_lcd_hw_trigger = req_p->force_lcd_hw_trigger;
    play_struct->layer_element = req_p->layer_element;
    play_struct->blt_ctx = req_p->blt_ctx;
    play_struct->blt_dev = req_p->blt_dev;
    play_struct->frame_mode = req_p->frame_mode;
    play_struct->e3DMode = req_p->mode_3d;
#ifdef __VIDEO_SUBTITLE_SUPPORT__
    /* Subtitle */
    play_struct->subtitle_width = req_p->subtitle_width;
    play_struct->subtitle_height = req_p->subtitle_height;
    play_struct->subtitle_image_buffer_p = req_p->subtitle_buffer_p;
    play_struct->subtitle_data_format = req_p->subtitle_data_format;
    play_struct->subtitle_layer_element = req_p->subtitle_layer_element;
    play_struct->subtitle_blt_ctx = req_p->subtitle_blt_ctx;
    play_struct->subtitle_blt_dev = req_p->subtitle_blt_dev;
#endif /* __VIDEO_SUBTITLE_SUPPORT__ */
}

/*****************************************************************************
 * FUNCTION
 *  vid_play_req_hdlr
 * DESCRIPTION
 *  Handle video play request
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_play_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_play_req_struct *req_p;
    mpl_player_play_t play_struct;
    med_result_enum result;
    kal_uint64 cur_time;
    media_error_t ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_PLAY_REQ_HDLR, vid_context_p->state);

    req_p = (media_vid_play_req_struct*) ilm_ptr->local_para_ptr;

    vid_context_p->src_mod = ilm_ptr->src_mod_id;
    vid_context_p->seq_num = req_p->seq_num;

    /* stop other audio */
    if (req_p->play_audio)
    {
        aud_stop_unfinished_audio();
    }

    vid_get_current_play_time(&cur_time);

    if (vid_chcek_camera_is_idle() && VID_IN_STATE(VID_FILE_READY))
    {
        /* get default setting */
        player_p->get_default(player_p, MPL_PLAY_PARAM, &play_struct);

        /* start to play */
        vid_set_play_struct(req_p, &play_struct);

        ret = player_p->play(player_p, &play_struct);
        result = med_error_to_result_enum(ret);

        vid_context_p->is_lcd_updated = KAL_TRUE;

        if (result == MED_RES_OK)
        {
            VID_ENTER_STATE(VID_PLAY);
        }
        else if (result == MED_RES_TERMINATED)
        {
            vid_send_play_finish_ind(MED_RES_OK);
            result = MED_RES_OK;
        }
        /* Fail: check if lcd is updated */
        else
        {
            player_p->get_param(
                player_p,
                MPL_PARAM_IS_LCD_UPDATED,
                (void*)&vid_context_p->is_lcd_updated);
        }
    }
    else
    {
        vid_context_p->is_lcd_updated = KAL_FALSE;
        result = MED_RES_BUSY;
    }
    vid_set_result_and_event(result, VID_EVT_PLAY);
}


/*****************************************************************************
 * FUNCTION
 *  vid_seek_req_hdlr
 * DESCRIPTION
 *  Handle video seek request.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_seek_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_seek_req_struct *req_p;
    mpl_player_seek_t seek_struct;
    med_result_enum result = MED_RES_BUSY;
    media_error_t ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_SEEK_REQ_HDLR, vid_context_p->state);

    req_p = (media_vid_seek_req_struct*) ilm_ptr->local_para_ptr;

    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    if (vid_chcek_camera_is_idle() && VID_IN_STATE(VID_FILE_READY))
    {
        vid_context_p->blocking = req_p->blocking;
        vid_context_p->seq_num = req_p->seq_num;

        /* get default setting */
        player_p->get_default(player_p, MPL_SEEK_PARAM, &seek_struct);

        seek_struct.get_frame = req_p->get_frame;
        seek_struct.time = req_p->time;
        seek_struct.display_width = req_p->display_width;
        seek_struct.display_height = req_p->display_height;
        seek_struct.image_buffer_p = req_p->image_buffer_p;
        seek_struct.force_seek = req_p->force_seek;
        seek_struct.seek_track = req_p->seek_track;
        seek_struct.idp_rotate = req_p->idp_rotate;
        seek_struct.image_data_format = req_p->image_data_format;
        seek_struct.frame_mode = req_p->frame_mode;
        seek_struct.stop_on_decode_errors = (req_p->blocking) ? KAL_TRUE : KAL_FALSE;
        ret = player_p->seek(player_p, &seek_struct);
        result = med_error_to_result_enum(ret);

        if (result == MED_RES_OK_ASYNC)
        {
            VID_ENTER_STATE(VID_SEEK);

            if (!vid_context_p->blocking)
            {
                vid_set_result_and_event(MED_RES_OK, VID_EVT_SEEK);
            }
        }
        else
        {
            if (result == MED_RES_OK)
            {
                if (!vid_context_p->blocking)
                {
                    vid_send_seek_done_ind(result);
                }
            }
            vid_set_result_and_event(result, VID_EVT_SEEK);
        }
    }
    else
    {
        vid_set_result_and_event(MED_RES_BUSY, VID_EVT_SEEK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_get_frame_req_hdlr
 * DESCRIPTION
 *  Handle video seek request.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_get_frame_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_get_frame_req_struct *req_p;
    mpl_player_get_frame_t frame_struct;
    med_result_enum result = MED_RES_BUSY;
    media_error_t ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    req_p = (media_vid_get_frame_req_struct*) ilm_ptr->local_para_ptr;

    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    if (vid_chcek_camera_is_idle() && VID_IN_STATE(VID_FILE_READY))
    {
        /* get default setting */
        player_p->get_default(player_p, MPL_GET_FRAME_PARAM, &frame_struct);

        frame_struct.display_width = req_p->display_width;
        frame_struct.display_height = req_p->display_height;
        frame_struct.image_buffer_p = req_p->image_buffer_p;
        frame_struct.idp_rotate = req_p->idp_rotate;
        frame_struct.image_data_format = req_p->image_data_format;
        frame_struct.frame_mode = req_p->frame_mode;
        frame_struct.e3DMode = req_p->mode_3d;
    #ifdef __VIDEO_SUBTITLE_SUPPORT__
        frame_struct.subtitle_width = req_p->subtitle_width;
        frame_struct.subtitle_height = req_p->subtitle_height;
        frame_struct.subtitle_image_buffer_p = req_p->subtitle_buffer_p;
        frame_struct.subtitle_data_format = req_p->subtitle_data_format;
    #endif /* __VIDEO_SUBTITLE_SUPPORT__ */
        ret = player_p->get_frame(player_p, &frame_struct);
        result = med_error_to_result_enum(ret);


    }
    vid_set_result_and_event(result, VID_EVT_GET_FRAME);

}

/*****************************************************************************
 * FUNCTION
 *  vid_pause_visual_update_req_hdlr
 * DESCRIPTION
 *  Pause for update video layer parameter for video recroding
 * PARAMETERS
 *  ilm_ptr     [IN]        msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_pause_visual_update_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    player_p->pause_visual_update(player_p);

    vid_set_event(VID_EVT_BLOCK);

}


/*****************************************************************************
 * FUNCTION
 *  vid_resume_visual_update_req_hdlr
 * DESCRIPTION
 *  Pause for update video layer parameter for video recroding
 * PARAMETERS
 *  ilm_ptr     [IN]        msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_resume_visual_update_req_hdlr(ilm_struct *ilm_ptr)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_result_enum result;
    media_error_t ret;
    media_vid_play_req_struct *req_p;
    mpl_player_play_t play_struct;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    req_p = (media_vid_play_req_struct*) ilm_ptr->local_para_ptr;

    /* get default setting */
    player_p->get_default(player_p, MPL_PLAY_PARAM, &play_struct);

    vid_set_play_struct(req_p, &play_struct);
    ret = player_p->resume_visual_update(player_p, &play_struct);
    result = med_error_to_result_enum(ret);

    vid_set_result_and_event(result, VID_EVT_BLOCK);
}





/*****************************************************************************
 * FUNCTION
 *  vid_get_param_req_hdlr
 * DESCRIPTION
 *  Get Video parameter request.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_get_param_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_get_param_req_struct *req_p;
    kal_uint32 value;
    med_result_enum result;
    media_error_t ret = MED_E_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    req_p = (media_vid_get_param_req_struct*) ilm_ptr->local_para_ptr;

    switch (req_p->param_id)
    {
    #ifdef __VIDEO_CLIPPER_SUPPORT__
        case VID_PARAM_KEY_FRAME_TIME:
        {
            mpl_player_param_query_keyframe_time_t *keyframe = (mpl_player_param_query_keyframe_time_t *)req_p->value;
            ret = player_p->get_param(player_p,MPL_PARAM_GET_KEYFRAME_TIME, (void*)keyframe);
            break;
        }
    #endif /* __VIDEO_CLIPPER_SUPPORT__ */

    #ifdef SUPPORT_MMAPI
        case VID_PARAM_TIME_TO_FRAME:
        {
            mpl_player_param_time_and_frame_mapping_t *info_p = (mpl_player_param_time_and_frame_mapping_t*) req_p->value;
            ret = player_p->get_param(player_p, MPL_PARAM_TIME_TO_FRAME, (void*)info_p);
            break;
        }

        case VID_PARAM_FRAME_TO_TIME:
        {
            mpl_player_param_time_and_frame_mapping_t *info_p = (mpl_player_param_time_and_frame_mapping_t*) req_p->value;
            ret = player_p->get_param(player_p, MPL_PARAM_FRAME_TO_TIME, (void*)info_p);
            break;
        }
    #endif /* SUPPORT_MMAPI */
    #ifdef __MOT_SUPPORT__
        case VID_PARAM_MOT_META:
        {
            mpl_player_get_mot_meta_t *meta = (mpl_player_get_mot_meta_t*) req_p->value;
            ret = player_p->get_mot_meta(player_p, meta);
            break;
        }

    #endif /*__MOT_SUPPORT__ */
        case VID_PARAM_CONTENT_DESC:
        {
            mpl_player_get_meta_t *meta = (mpl_player_get_meta_t *)req_p->value;

            if (VID_IN_STATE(VID_FILE_READY))
            {
                ret = player_p->get_meta(player_p, meta);
            }
            break;
        }
        default:
            break;
    }

    result = med_error_to_result_enum(ret);
    vid_set_result_and_event(result, VID_EVT_GET_INFO);
}


#if !defined(__MED_IN_ASM__)

/*****************************************************************************
 * FUNCTION
 *  vid_check_med_ready_req_hdlr
 * DESCRIPTION
 *  Set Video parameter request.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_check_med_ready_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 mem_add;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* check external memory */
    if (vid_play_mem[1]!=0)
    {
        if (VID_IN_STATE(VID_FILE_MERGE))
        {
            mem_add = (kal_uint32)med_alloc_ext_mem(vid_play_mem[1] - MED_VID_ENCODE_FSAL_BUFFER_SIZE - MED_VID_ENCODE_FW_BUFFER_SIZE);
        }
        else
        {
            mem_add = (kal_uint32)med_alloc_ext_mem(vid_play_mem[1]);
        }

        if (mem_add == NULL)
        {
            vid_set_result_and_event(MED_RES_MEM_INSUFFICIENT, VID_EVT_BLOCK);
            return;
        }
        else
        {
            med_free_ext_mem((void**)&mem_add);
        }
    }

    vid_set_event(VID_EVT_BLOCK);
}
#endif /* __MED_IN_ASM__ */


/*****************************************************************************
 * FUNCTION
 *  vid_set_vol_level
 * DESCRIPTION
 *  set vol level
 * PARAMETERS
 *  vol_level       [IN]        vol level
 * RETURNS
 *
 *****************************************************************************/
void vid_set_vol_level(kal_uint8 vol_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    player_p->set_param(player_p, MPL_PARAM_AUD_VOLUME, (void*)&vol_level);
}

#ifdef __MED_VID_PDL_MOD__
/*****************************************************************************
 * FUNCTION
 *  vid_get_pdl_percent_req_hdlr
 * DESCRIPTION
 *  Get pdl buffering percentage.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_get_pdl_percent_req_hdlr(ilm_struct *ilm_ptr)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_get_pdl_percent_req_struct *msg_p =
        (media_vid_get_pdl_percent_req_struct*) ilm_ptr->local_para_ptr;
    med_result_enum result = MED_RES_OK;
    media_error_t ret;
    mpl_player_ctrl_dl_t *pdl_control_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_GET_PDL_PERCENT_REQ_HDLR, vid_context_p->state);

    if (VID_IN_STATE(VID_FILE_READY))
    {
        if (player_p->get_control(player_p, PLAYER_CONTROL_DL, (void**)&pdl_control_p)==MED_S_OK)
        {

            ret = pdl_control_p->get_percent(pdl_control_p, msg_p->percent_p);
            result = med_error_to_result_enum(ret);
            kal_trace(TRACE_GROUP_4, VID_TRC_PERCENT, *(msg_p->percent_p), __LINE__);

            if (result != MED_RES_OK)
            {
                vid_set_result(MED_RES_PARSER_ERROR, __LINE__);
            }
            else if ((*msg_p->percent_p) == 100)
            {
                VID_ENTER_STATE(VID_FILE_READY);
            }
        }
    }
    else
    {
        /* META still not ready */
        *(msg_p->percent_p) = 0;          /* 0 % */
        kal_trace(TRACE_GROUP_4, VID_TRC_PERCENT, *(msg_p->percent_p), __LINE__);
    }

    vid_set_event(VID_EVT_GET_INFO);
}



/*****************************************************************************
 * FUNCTION
 *  vid_get_pdl_max_time_req_hdlr
 * DESCRIPTION
 *  Get pdl max play time
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_get_pdl_max_time_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_get_pdl_max_time_req_struct *msg_p =
        (media_vid_get_pdl_max_time_req_struct*) ilm_ptr->local_para_ptr;
    med_result_enum result = MED_RES_OK;
    mpl_player_ctrl_dl_t *pdl_control_p;
    media_error_t ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_GET_PDL_MAX_TIME_REQ_HDLR, vid_context_p->state);

    if (VID_IN_STATE(VID_OPEN_FILE /*VID_PDL_META_BUFFERING*/))
    {
        /* META still not ready */
        *(msg_p->max_time_p) = 0;
        kal_trace(TRACE_GROUP_4, VID_TRC_MAX_TIME, (kal_uint32)(*(msg_p->max_time_p)), __LINE__);
        vid_set_event(VID_EVT_GET_INFO);
        return;
    }

    if (player_p->get_control(player_p, PLAYER_CONTROL_DL, (void**)&pdl_control_p)==MED_S_OK)
    {
        ret = pdl_control_p->get_max_time(pdl_control_p, msg_p->max_time_p);
        result = med_error_to_result_enum(ret);
        if (result != MED_RES_OK)
        {
            vid_set_result(result,__LINE__);
        }
    }

    kal_trace(TRACE_GROUP_4, VID_TRC_MAX_TIME, (kal_uint32)(*(msg_p->max_time_p)), __LINE__);
    vid_set_event(VID_EVT_GET_INFO);

}
#endif /* __MED_VID_PDL_MOD__ */

#ifdef __MM_DCM_SUPPORT__
#pragma arm section code, rodata
#endif

#endif /* defined(__MED_VID_DEC_MOD__) */

#endif /* MED_NOT_PRESENT */

