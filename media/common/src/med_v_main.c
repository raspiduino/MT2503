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
 *   med_v_main.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary functions of media v task.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef MED_V_NOT_PRESENT

/*==== INCLUDES =========*/

/* system includes */
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */

/* local include */
#include "med_global.h"
#include "med_v_context.h"
#include "med_v_main.h"

#include "cam_v_main.h"

#if defined(__MED_MTV_MOD__) || defined(__MED_ATV_MOD__)
#include "mtv_main.h"
#include "mtv_comm.h"
#endif

#ifdef __STREAM_REC_MOD__
#include "mtv_buffer_engine.h"
#include "stream_vis_api.h"
#endif

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "stack_ltlcom.h"
#include "stack_config.h"
#include "kal_internal_api.h"

#include "mpl_recorder.h"

#include "meta_tag_api.h"

/* global variables */
med_v_context_struct med_v_context;
med_v_context_struct *med_v_context_p = &med_v_context;

/*==== FUNCTIONS ===========*/
extern void aud_util_in_proc_call_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_util_in_proc_call_ext_req_hdlr(ilm_struct * ilm_ptr);
extern void medv_run_low_priority_api(ilm_struct *ilm_ptr);
extern void med_mpl_async_callback_req_hdlr(ilm_struct *ilm);

#ifdef __MED_VID_ENC_MOD__
#if defined(MP4_ENCODE)
extern void mp4_recorder_main(ilm_struct *ilm_ptr);
#endif
#if defined(MJPG_ENCODE)
extern void avi_recorder_main(ilm_struct *ilm_ptr);
#endif
#endif /* __MED_VID_ENC_MOD__*/

/*****************************************************************************
 * FUNCTION
 *  med_v_timer_expiry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MED_MTV_MOD__)
static void med_v_timer_expiry_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stack_timer_struct *stack_timer_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_timer_ptr = (stack_timer_struct*) ilm_ptr->local_para_ptr;

    mtv_process_time_out(stack_timer_ptr);
}
#endif // #if defined(__MED_MTV_MOD__)

/*****************************************************************************
 * FUNCTION
 *  med_v_start_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timer_id            [IN]        
 *  period              [IN]        
 *  timer_expiry        [IN]        
 *  arg                 [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void med_v_start_timer(kal_uint8 timer_id, kal_uint32 period, kal_timer_func_ptr timer_expiry, void *arg)
{
}


/*****************************************************************************
 * FUNCTION
 *  med_v_stop_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timer_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void med_v_stop_timer(kal_uint8 timer_id)
{
}

/*****************************************************************************
 * FUNCTION
 *  med_v_startup_hdlr
 * DESCRIPTION
 *  This function is handle startup procedure of media v task.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_v_startup_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
}


/*****************************************************************************
 * FUNCTION
 *  med_v_main
 * DESCRIPTION
 *  This function is main message dispatching function of media v task.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_v_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(MJPG_ENCODE)
    if ((ilm_ptr->msg_id >= MSG_ID_MEDIA_AVI_RECORDER_BEGIN  && ilm_ptr->msg_id <= MSG_ID_MEDIA_AVI_RECORDER_ENG))
    {
        avi_recorder_main(ilm_ptr);
        return;
    }
#endif

    switch (ilm_ptr->msg_id)
    {
    #ifdef __FM_RADIO_HW_SEARCH__
        case MSG_ID_MEDIA_FMR_SEEK_CALLBACK_IND:
            aud_fmr_seek_callback_ind_hdlr(ilm_ptr);
            break;
    #endif /* __FM_RADIO_HW_SEARCH__ */

	#if defined( __META_DATA_PARSE_API__) && (!defined(MED_LOW))
        case MSG_ID_MEDIA_META_PARSE_REQ:
            meta_parser_file_parse_hdlr(ilm_ptr);
            break;
    #endif /* __META_DATA_PARSE_API__ */

    #if defined(__MED_MTV_MOD__)
        case MSG_ID_TIMER_EXPIRY:
            med_v_timer_expiry_hdlr(ilm_ptr);
            break;
    #endif // #if defined(__MED_MTV_MOD__)

        case MSG_ID_MEDIA_IN_PROC_CALL_REQ:
            aud_util_in_proc_call_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_IN_PROC_CALL_EXT_REQ:
            aud_util_in_proc_call_ext_req_hdlr(ilm_ptr);
            break;
    
    #ifdef __RICH_AUDIO_PROFILE__
        case MSG_ID_MEDIA_AUDIO_START_SEEK_REQ:
            aud_build_cache_start_seek_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUDIO_STOP_SEEK_REQ:
            aud_build_cache_stop_seek_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUDIO_START_BUILD_CACHE_ASYNC_REQ:
            aud_build_cache_async_start_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUDIO_CLOSE_BUILD_CACHE_ASYNC_REQ:
            aud_build_cache_async_close_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUDIO_START_BUILD_CACHE_REQ:
            aud_build_cache_start_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUDIO_STOP_BUILD_CACHE_REQ:
            aud_build_cache_stop_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUDIO_CLOSE_BUILD_CACHE_REQ:
            aud_build_cache_close_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUDIO_RESET_BUILD_CACHE_VARS_REQ:
            aud_build_cache_reset_req_hdlr(ilm_ptr);
            break;
    #endif /*__RICH_AUDIO_PROFILE__*/
    
        case MSG_ID_MEDIA_V_RUN_LOW_PRIORITY_REQ:
           medv_run_low_priority_api(ilm_ptr);
           break;

    #ifdef AUD_BGSND_PLAY_FROM_MEDV
        case MSG_ID_MEDIA_V_AUDIO_BGSND_PLAY_REQ:
            med_v_aud_bgsnd_play_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_V_AUDIO_BGSND_STOP_REQ:
            med_v_aud_bgsnd_stop_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_V_AUDIO_BGSND_PROCESS_EVENT_IND:
            med_v_aud_bgsnd_process_event_ind_hdlr(ilm_ptr);
            break;
    #endif /*AUD_BGSND_PLAY_FROM_MEDV*/

        case MSG_ID_MEDIA_MPL_ASYNC_CALLBACK_REQ:
            {
                med_mpl_async_callback_req_hdlr(ilm_ptr);
                break;
            }

        default:
        #if defined(MP4_ENCODE)
            if ((ilm_ptr->msg_id >= MSG_ID_MEDIA_MP4_RECORDER_BEGIN  && ilm_ptr->msg_id <= MSG_ID_MEDIA_MP4_RECORDER_ENG))
            {
                mp4_recorder_main(ilm_ptr);
                return;
            }
        #endif
        #if defined(MP4_DECODE) && defined(__VIDEO_ARCHI_V1__)
            if ((ilm_ptr->msg_id >= MSG_ID_MEDIA_VID_MTK_MP4_BEGIN && ilm_ptr->msg_id <= MSG_ID_MEDIA_VID_MTK_MP4_END)
                ||(ilm_ptr->msg_id >= MSG_ID_MEDIA_VISUAL_MTK_MP4_BEGIN && ilm_ptr->msg_id <= MSG_ID_MEDIA_VISUAL_MTK_MP4_END))
            {
                mp4_player_main(ilm_ptr);
                return;
            }
        #endif
        #if defined(__MED_MTV_MOD__)
            if ((ilm_ptr->msg_id >= MSG_ID_MEDIA_MTV_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MEDIA_MTV_CODE_END) ||
                (ilm_ptr->msg_id >= MSG_ID_TDMB_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_TDMB_CODE_END) ||
                (ilm_ptr->msg_id >= MSG_ID_ATV_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_ATV_CODE_END))
            {
                mtv_main(ilm_ptr);
            }
        #endif /* __MED_MTV_MOD__ */
        #ifdef __STREAM_REC_MOD__
            if (ilm_ptr->msg_id >= MSG_ID_MEDIA_V_STREAM_REC_BEGIN && ilm_ptr->msg_id <= MSG_ID_MEDIA_V_STREAM_REC_END)
            {
                stream_vis_main(ilm_ptr);
            }
        #endif /* __STREAM_REC_MOD__ */
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  med_v_task_main
 * DESCRIPTION
 *  This function is main function of media v task.
 * PARAMETERS
 *  task_entry_ptr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_v_task_main(task_entry_struct *task_entry_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;
    kal_uint32 my_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_my_task_index(&my_index);

    while (1)
    {
        receive_msg_ext_q_for_stack(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
        stack_set_active_module_id(my_index, current_ilm.dest_mod_id);

        med_v_main((void*)&current_ilm);

        free_ilm(&current_ilm);
    }

}


#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif

/*****************************************************************************
 * FUNCTION
 *  med_v_init
 * DESCRIPTION
 *  This function is used to init media v task.
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool med_v_init(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    med_v_context_p->aud_cache_event = kal_create_event_group("aud_cache_events");


#ifdef AUD_BGSND_PLAY_FROM_MEDV
    /* Init BGSND process data in low priority task */
    med_v_aud_bgsnd_init();
#endif


#ifdef __STREAM_REC_MOD__
    stream_vis_init();
#endif
    return KAL_TRUE;
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

/*****************************************************************************
 * FUNCTION
 *  med_v_reset
 * DESCRIPTION
 *  This function is used to reset media v task.
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool med_v_reset(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  med_v_create
 * DESCRIPTION
 *  This function is used to create media v task configuration info.
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool med_v_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct med_v_handler_info = 
    {
        med_v_task_main,    /* task entry function */
        med_v_init,         /* task initialization function */
        NULL,               /* task configuration function */
        med_v_reset,        /* task reset handler */
        NULL,               /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*) & med_v_handler_info;

    return KAL_TRUE;
}

#endif /* MED_V_NOT_PRESENT */ 

