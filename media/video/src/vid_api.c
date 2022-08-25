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
 *  vid_api.c
 *
 * Project:
 * --------
 *  Maui
 *
 * Description:
 * ------------
 *  Media Task Video Interface
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

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
#include "device.h"
#include "resource_audio.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"


#ifdef MP4_DECODE
#include  "drv_comm.h"
#include  "visual_comm.h"
#include  "fsal.h"
#include  "mp4_parser.h"
#include  "lcd_if.h"
#include  "bmd.h"
#endif /* MP4_DECODE */ 

/* local includes */
#include "med_global.h"
#include "med_vid_clip_features.h"
#include "med_status.h"
#include "med_main.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_vid_clip_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_utility.h"
#include "med_v_context.h"
#include "vid_main.h"

#ifdef __VID_TRACE_ON__
#include "med_trc.h"
#endif 

#include "kal_general_types.h"
#include "stack_config.h"
#include "stack_ltlcom.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"

#if defined(__MED_VID_DEC_MOD__) || defined(__MED_VID_ENC_MOD__)

static kal_int32 vid_result;


#define CONSTRUCT_LOCAL_PARAM(st, name) \
    st* name = (st*) construct_local_para(sizeof(st), TD_CTRL)

void vid_send_outgoing_ilm(module_type dest_mod_id, kal_uint16 msg_id, void* local_param_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct* ilm = NULL;
    module_type src_mod_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    src_mod_id = stack_get_active_module_id();

    ilm = allocate_ilm(src_mod_id);
    ilm->src_mod_id = src_mod_id;
    ilm->sap_id = MED_SAP;

    ilm->msg_id = (msg_type) msg_id;
    ilm->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm->peer_buff_ptr = NULL;

    ilm->dest_mod_id = dest_mod_id;

    msg_send_ext_queue(ilm);
}


ilm_struct *vid_get_ilm(
        module_type src_mod_id,
        kal_uint16 msg_id,
        void* local_param_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(src_mod_id);
    ilm_ptr->src_mod_id = src_mod_id;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;
    ilm_ptr->msg_id = (msg_type) msg_id;

    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = NULL;
    return ilm_ptr;
}


void vid_send_incoming_ilm_with_data(
        module_type src_mod_id,
        kal_uint16 msg_id,
        void* local_param_ptr,
        void *data,
        kal_int32 struct_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = vid_get_ilm(src_mod_id, msg_id, local_param_ptr);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (data)
    {
        kal_mem_cpy(
            ((kal_uint8*) local_param_ptr) + sizeof(local_para_struct),
            ((kal_uint8*) data) + sizeof(local_para_struct),
            struct_size - sizeof(local_para_struct));
    }

    msg_send_ext_queue(ilm_ptr);
}

void vid_send_incoming_ilm(
        module_type src_mod_id,
        kal_uint16 msg_id,
        void* local_param_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = vid_get_ilm(src_mod_id, msg_id, local_param_ptr);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  vid_debug_print_cur_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void vid_debug_print_cur_state(kal_uint32 line)
{
    kal_trace(TRACE_GROUP_4, VID_TRC_STATE, vid_context_p->state, line);
}

/*****************************************************************************
 * FUNCTION
 *  vid_set_result
 * DESCRIPTION
 *  This function is to set the result.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vid_set_result(kal_int32 result, kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_SET_RESULT);    
    vid_debug_print_cur_state(line);
    med_debug_print_result(result, line);
    vid_result = result;
}


/*****************************************************************************
 * FUNCTION
 *  vid_enter_state
 * DESCRIPTION
 *  This function is to change state of media video module
 * PARAMETERS
 *  state      [IN]
 *  line         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_enter_state(kal_uint8 state, kal_uint32 line)
{
    kal_trace(TRACE_STATE, VID_TRC_ENTER_VID_STATE, state, line);
    vid_context_p->state = state;                                     
}


/*****************************************************************************
 * FUNCTION
 *  vid_wait_event
 * DESCRIPTION
 *  This function is to power on camera.
 * PARAMETERS
 *  src_mod_id      [IN]
 *  seq_num         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_wait_event(kal_uint32 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 retrieved_events;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VID_WAIT_EVT(event, 0);
    kal_retrieve_eg_events(
        vid_context_p->vid_event,
        event,
        KAL_OR_CONSUME,
        &retrieved_events,
        KAL_SUSPEND);
}

/*****************************************************************************
 * FUNCTION
 *  vid_set_event
 * DESCRIPTION
 *  This function is to power on camera.
 * PARAMETERS
 *  src_mod_id      [IN]
 *  seq_num         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_set_event(kal_uint32 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_set_eg_events(vid_context_p->vid_event, event, KAL_OR);
    VID_SET_EVT(event, 0);
}

/*****************************************************************************
 * FUNCTION
 *  vid_set_result_and_event
 * DESCRIPTION
 *  vid set result and event
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void vid_set_result_and_event(kal_int32 result, kal_uint32 event)
{
    vid_set_result(result, 0);
    vid_set_event(event);
}

#endif /* defined(__MED_VID_DEC_MOD__) || defined(__MED_VID_ENC_MOD__) */
#ifdef __MED_VID_ENC_MOD__
/*****************************************************************************
 * FUNCTION
 *  media_vid_power_up
 * DESCRIPTION
 *  This function is to power on camera.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  seq_num         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_MWREC_ROCODE", rodata = "DYNAMIC_CODE_MWREC_RODATA"
kal_int32 media_vid_power_up(module_type src_mod_id, media_vid_power_up_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_power_up_req_struct, msg_p);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_POWER_UP_REQ,
        msg_p, data, sizeof(media_vid_power_up_req_struct));

    vid_wait_event(VID_EVT_POWER_ON);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_power_up
 * DESCRIPTION
 *  This function is to power on camera.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  seq_num         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_vid_power_down(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_power_down_req_struct, msg_p);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vid_send_incoming_ilm(src_mod_id, MSG_ID_MEDIA_VID_POWER_DOWN_REQ,(void*)msg_p);

    // as camera, don't need to wait for stop.
    vid_wait_event(VID_EVT_POWER_ON);

    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_preview
 * DESCRIPTION
 *  This function is to start video preview.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  preview         [?]         
 *  vid_record_struct* record(?)
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_preview(module_type src_mod_id, media_vid_preview_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_preview_req_struct, msg_p);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_PREVIEW_REQ,
        msg_p, data, sizeof(media_vid_preview_req_struct));
    vid_wait_event(VID_EVT_PREVIEW);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_record
 * DESCRIPTION
 *  This function is to start video recording.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  record          [?]         
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_record(module_type src_mod_id, media_vid_record_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_record_req_struct, msg_p);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_RECORD_REQ,
        msg_p, data, sizeof(media_vid_record_req_struct));
    vid_wait_event(VID_EVT_RECORD);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_rec_stop
 * DESCRIPTION
 *  This function is to stop video recording.
 * PARAMETERS
 *  src_mod_id      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_vid_rec_stop(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_rec_stop_req_struct, msg_p);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;

    vid_send_incoming_ilm(src_mod_id, MSG_ID_MEDIA_VID_REC_STOP_REQ,(void*)msg_p);

    vid_wait_event(VID_EVT_STOP);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_file_merge
 * DESCRIPTION
 *  This function is to merge temp files to a video file.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  path            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void media_vid_file_merge(module_type src_mod_id, media_vid_file_merge_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_file_merge_req_struct, msg_p);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_FILE_MERGE_REQ,
        msg_p, data, sizeof(media_vid_file_merge_req_struct));
    vid_wait_event(VID_EVT_FILE_MERGE);
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_update_blt_pause
 * DESCRIPTION
 *  Pause for update blt parameters 
 * PARAMETERS
 *  src_mod_id                                  [IN]        
 *  media_vid_update_blt_pause_req_struct       [IN]        
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_update_blt_pause(module_type src_mod_id, media_vid_update_blt_pause_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_update_blt_pause_req_struct, msg_p);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_UPDATE_BLT_PAUSE_REQ,
        msg_p, data, sizeof(media_vid_update_blt_pause_req_struct));
    vid_wait_event(VID_EVT_BLOCK);
    return vid_result;
}

/*****************************************************************************
 * FUNCTION
 *  media_vid_update_blt_resume
 * DESCRIPTION
 *  Resume for update blt parameters 
 * PARAMETERS
 *  src_mod_id                                  [IN]        
 *  media_vid_update_blt_resume_req_struct      [IN]        
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_update_blt_resume(module_type src_mod_id, media_vid_update_blt_resume_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_update_blt_resume_req_struct, msg_p);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_UPDATE_BLT_RESUME_REQ,
        msg_p, data, sizeof(media_vid_update_blt_resume_req_struct));
    vid_wait_event(VID_EVT_BLOCK);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_rec_set_param
 * DESCRIPTION
 *  This function is to set video parameters.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  param           [?]         
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_rec_set_param(module_type src_mod_id, kal_uint32 param_id, kal_int16 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_rec_set_param_req_struct, msg_p);
    media_vid_rec_set_param_req_struct real_data;
    media_vid_rec_set_param_req_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;

    real_data.param_id = param_id;
    real_data.value = value;

    data = &real_data;

    vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_REC_SET_PARAM_REQ,
        msg_p, data, sizeof(media_vid_rec_set_param_req_struct));
    vid_wait_event(VID_EVT_SET_PARAM);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_check_unfinished_file
 * DESCRIPTION
 *  This function is to check unfinished video recording file.
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  True/False
 *****************************************************************************/
kal_bool media_vid_check_unfinished_file(module_type src_mod_id,kal_wchar* file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return vid_check_unfinished_file(file_path);
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_clean_temp_files
 * DESCRIPTION
 *  This function is to clean temp files.
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_vid_clean_temp_files(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_clean_file_req_struct, msg_p);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    vid_send_incoming_ilm(src_mod_id, MSG_ID_MEDIA_VID_CLEAN_FILE_REQ, msg_p);

    vid_wait_event(VID_EVT_BLOCK);

}


/*****************************************************************************
 * FUNCTION
 *  media_vid_get_current_record_size
 * DESCRIPTION
 *  This function is to get current record file size
 * PARAMETERS
 *  src_mod_id          [IN]            source module
 *  file_size           [OUT]           file size
 * RETURNS
 *  void
 *****************************************************************************/
void media_vid_get_current_record_size(module_type src_mod_id, kal_uint64 *file_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_get_record_size_req_struct, msg_p);
    media_vid_get_record_size_req_struct data_struct;
    media_vid_get_record_size_req_struct *data = &data_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (VID_IN_STATE(VID_RECORD) || 
        VID_IN_STATE(VID_RECORD_FINISH) ||
        VID_IN_STATE(VID_RECORD_PAUSED) ||
        VID_IN_STATE(VID_RECORD_STOP_VISUAL))
    {
        data->cur_size_p = file_size;
        vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_GET_RECORD_SIZE_REQ,
            msg_p, data, sizeof(media_vid_get_record_size_req_struct));
        vid_wait_event(VID_EVT_GET_INFO);
    }
    else
    {
        *file_size = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_get_current_record_time
 * DESCRIPTION
 *  This function is to get current time when video recording.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  time            [?]         
 * RETURNS
 *  The result of this action.(?)
 *****************************************************************************/
void media_vid_get_current_record_time(module_type src_mod_id, kal_uint64 *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_get_record_time_req_struct, msg_p);
    media_vid_get_record_time_req_struct data_struct;
    media_vid_get_record_time_req_struct *data = &data_struct;
    kal_uint32 cur_time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data->cur_time_p = time;
    vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_GET_RECORD_TIME_REQ,
            msg_p, data, sizeof(media_vid_get_record_time_req_struct));
    
    vid_wait_event(VID_EVT_GET_INFO);

    /* need change to kal_uint32 to be display on catcher */
    cur_time = *time;
    kal_trace(TRACE_GROUP_4, VID_MMI_TRC_CUR_TIME, cur_time, __LINE__);        

}


/*****************************************************************************
 * FUNCTION
 *  media_vid_get_current_record_frame_num
 * DESCRIPTION
 *  This function is to get current time when video recording.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  time            [?]         
 * RETURNS
 *  The result of this action.(?)
 *****************************************************************************/
void media_vid_get_current_record_frame_num(module_type src_mod_id, kal_uint64 *frame_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_get_record_frame_num_req_struct, msg_p);
    media_vid_get_record_frame_num_req_struct data_struct;
    media_vid_get_record_frame_num_req_struct *data = &data_struct;
    kal_uint32 cur_frame_num;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data->cur_frame_num_p = frame_num;
    vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_GET_RECORD_FRAME_NUM_REQ,
            msg_p, data, sizeof(media_vid_get_record_frame_num_req_struct));
    
    vid_wait_event(VID_EVT_GET_INFO);

    /* need change to kal_uint32 to be display on catcher */
    cur_frame_num = *frame_num;
    kal_trace(TRACE_GROUP_4, VID_MMI_TRC_CUR_FRAME_NUM, cur_frame_num, __LINE__);        

}


/*****************************************************************************
 * FUNCTION
 *  media_vid_recorder_get_bitrate
 * DESCRIPTION
 *  This function is to get current bitrate of recorder 
 * PARAMETERS
 *  void 
 * RETURNS
 *  Bitrate of current video recorder setting.
 *****************************************************************************/
kal_uint32 media_vid_recorder_get_bitrate(void)
{
    return vid_context_p->bitrate;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_start_fast_zoom
 * DESCRIPTION
 *  This function is to start fast zoom for camera.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  zoom_in         [IN]        
 *  zoom_limit      [IN]        
 *  zoom_step       [IN]        
 *  zoom_speed      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_vid_start_fast_zoom(
        module_type src_mod_id,
        kal_bool zoom_in,
        kal_uint8 zoom_limit,
        kal_uint8 zoom_step,
        kal_uint8 zoom_speed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_start_fast_zoom_req_struct,msg_p);

    msg_p->zoom_in = zoom_in;
    msg_p->zoom_limit = zoom_limit;
    msg_p->zoom_step = zoom_step;
    msg_p->zoom_speed = zoom_speed;

    vid_send_incoming_ilm(src_mod_id, MSG_ID_MEDIA_VID_START_FAST_ZOOM_REQ,(void*)msg_p);

    vid_wait_event(VID_EVT_FAST_ZOOM);
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_stop_fast_zoom
 * DESCRIPTION
 *  This function is to stop fast zoom for camera.
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_vid_stop_fast_zoom(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_stop_fast_zoom_req_struct,msg_p);
    vid_send_incoming_ilm(src_mod_id, MSG_ID_MEDIA_VID_STOP_FAST_ZOOM_REQ,(void*)msg_p);
    vid_wait_event(VID_EVT_FAST_ZOOM);
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_get_fast_zoom_factor
 * DESCRIPTION
 *  This function is to get the fast zoom factor for camera.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  factor          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void media_vid_get_fast_zoom_factor(module_type src_mod_id, kal_uint32 *factor, kal_uint32 *step)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_get_fast_zoom_factor_req_struct,msg_p);

    msg_p->factor = factor;
    msg_p->step = step;

    vid_send_incoming_ilm(src_mod_id, MSG_ID_MEDIA_VID_GET_FAST_ZOOM_FACTOR_REQ,(void*)msg_p);
    vid_wait_event(VID_EVT_GET_FAST_ZOOM_FACTOR);
}
#pragma arm section code, rodata

/*****************************************************************************
 * FUNCTION
 *  media_vid_get_focus_zone
 * DESCRIPTION
 *  This function is to get the focus zone.
 * PARAMETERS
 *  src_mod_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_vid_get_focus_zone(module_type src_mod_id, media_vid_af_zone_para_struct *zone_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_af_get_zone_struct,msg_p);
    msg_p->zone_para_p = zone_p;    
    vid_send_incoming_ilm(src_mod_id, MSG_ID_MEDIA_VID_GET_FOCUS_ZONE_REQ,(void*)msg_p);
    vid_wait_event(VID_EVT_BLOCK);
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_get_reserved_disc_size
 * DESCRIPTION
 *  This function is to get reserved disc size.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  factor          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void media_vid_get_reserved_disc_size(module_type src_mod_id, kal_uint32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_get_reserved_disc_size_struct,msg_p);

    msg_p->size = size;

    vid_send_incoming_ilm(src_mod_id, MSG_ID_MEDIA_VID_GET_RESERVED_DISC_SIZE_REQ,(void*)msg_p);
    vid_wait_event(VID_EVT_BLOCK);
}

#pragma arm section code = "DYNAMIC_CODE_MWREC_ROCODE", rodata = "DYNAMIC_CODE_MWREC_RODATA"
/*****************************************************************************
 * FUNCTION
 *  media_vid_pause
 * DESCRIPTION
 *  This function is to pause the video playing.
 * PARAMETERS
 *  src_mod_id      [IN]
 *  data            [IN]
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_pause(module_type src_mod_id,  media_vid_pause_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_pause_req_struct, msg_p);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_PAUSE_REQ,
        msg_p, data, sizeof(media_vid_pause_req_struct));
    vid_wait_event(VID_EVT_PAUSE);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_resume
 * DESCRIPTION
 *  This function is to resume the video playing.
 * PARAMETERS
 *  src_mod_id      [IN]
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_resume(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_resume_req_struct, msg_p);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;

    vid_send_incoming_ilm(src_mod_id, MSG_ID_MEDIA_VID_RESUME_REQ,(void*)msg_p);

    vid_wait_event(VID_EVT_RESUME);
    return vid_result;
}
#pragma arm section code, rodata

/*****************************************************************************
 * FUNCTION
 *  media_vid_get_max_digital_zoom_factor
 * DESCRIPTION
 *  This function is to get max digital zoom factor with given width and heigh.
 * PARAMETERS
 *  target_width        [IN]        
 *  target_height       [IN]        
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
kal_uint8 media_vid_get_max_digital_zoom_factor(module_type src_mod_id, kal_uint16 target_width, kal_uint16 target_height)
{
#ifdef ISP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* function called, src_mod_id not used */

    return 100;//get_max_digital_zoom_factor(target_width, target_height);
#else /* ISP_SUPPORT */ 
    return 0;
#endif /* ISP_SUPPORT */ 
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_set_em_mode
 * DESCRIPTION
 *  This function is to set engineer mode of video function.
 * PARAMETERS
 *  mode        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void media_vid_set_em_mode(kal_uint8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_context_p->em_mode = mode;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_get_em_mode
 * DESCRIPTION
 *  This function is to get engineer mode of video function.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8 mode
 *****************************************************************************/
kal_uint8 media_vid_get_em_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return vid_context_p->em_mode;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_set_record_yuv
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8 mode
 *****************************************************************************/
void media_vid_set_record_yuv(module_type src_mod_id, kal_bool is_yuv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_record_yuv_req_struct, msg_p);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->is_yuv = is_yuv;

    vid_send_incoming_ilm(src_mod_id, MSG_ID_MEDIA_VID_RECORD_YUV_REQ,(void*)msg_p);
    
    vid_wait_event(VID_EVT_BLOCK);
}


#if defined(__DIRECT_SENSOR_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  media_vid_alloc_limited_avi_res
 * DESCRIPTION
 *  allocate limited avi's resource
 * PARAMETERS
 *  src_mod_id      [IN]    module id
 * RETURNS
 *  void
 *****************************************************************************/
void media_vid_alloc_limited_avi_res(module_type src_mod_id)
{
    CONSTRUCT_LOCAL_PARAM(media_vid_alloc_limited_avi_res_req_struct, msg_p);

    vid_send_incoming_ilm(src_mod_id, MSG_ID_MEDIA_VID_ALLOC_LIMTED_AVI_RES_REQ,(void*)msg_p);

    vid_wait_event(VID_EVT_BLOCK);
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_free_limited_avi_res
 * DESCRIPTION
 *  free limited avi's resource
 * PARAMETERS
 *  src_mod_id      [IN]    module id
 * RETURNS
 *  void
 *****************************************************************************/
void media_vid_free_limited_avi_res(module_type src_mod_id)
{
    CONSTRUCT_LOCAL_PARAM(media_vid_free_limited_avi_res_req_struct, msg_p);

    vid_send_incoming_ilm(src_mod_id, MSG_ID_MEDIA_VID_FREE_LIMTED_AVI_RES_REQ,(void*)msg_p);

    vid_wait_event(VID_EVT_BLOCK);
}
#endif /* defined(__DIRECT_SENSOR_SUPPORT__) */

#endif /* __MED_VID_ENC_MOD__ */

#ifdef __MED_VID_DEC_MOD__
/*****************************************************************************
 * FUNCTION
 *  media_vid_stop
 * DESCRIPTION
 *  This function is to stop video playing.
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_vid_stop(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_stop_req_struct, msg_p);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;

    vid_send_incoming_ilm(src_mod_id, MSG_ID_MEDIA_VID_STOP_REQ,(void*)msg_p);

    vid_wait_event(VID_EVT_STOP);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_open
 * DESCRIPTION
 *  This function is to open a video file/array/stream.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  open            [?]         
 *  vid_open_file_struct* open_file(?)
 *  kal_uint16 seq_num(?)
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_open(module_type src_mod_id, media_vid_open_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_open_req_struct, msg_p);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vid_result = MED_RES_OK;
    vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_OPEN_REQ,
        msg_p, data, sizeof(media_vid_open_req_struct));

    vid_wait_event(VID_EVT_OPEN);
    
    if (data->image_width)
    {
        *data->image_width = vid_context_p->image_width;
    }
    if (data->image_height)
    {
        *data->image_height = vid_context_p->image_height;
    }
    if (data->total_time)
    {
        *data->total_time = vid_context_p->total_time;
    }
    
    if(data->file_handle)
    {
        *data->file_handle = vid_context_p->file_handle;
    }

    if(data->is_seekable)
    {
        *data->is_seekable = vid_context_p->is_seekable;
    }

#ifdef __VIDEO_CLIPPER_SUPPORT__ 
    if(data->is_proprietary)
    {
        *data->is_proprietary = vid_context_p->is_proprietary;
    }
#endif /* __VIDEO_CLIPPER_SUPPORT__ */

#ifdef __VIDEO_3D_ANAGLYPH__

    if(data->track_num)
    {        
        *data->track_num = vid_context_p->track_num;        
    }
    
    data->track_info = vid_context_p->track_info;
#endif  /* __VIDEO_3D_ANAGLYPH__ */  

#ifdef __VIDEO_SUBTITLE_SUPPORT__
    
    if(data->subtitle_num)
    {        
        *data->subtitle_num = vid_context_p->subtitle_num;        
    }
    
    data->subtitle_info = vid_context_p->subtitle_info;
#endif  /* __VIDEO_SUBTITLE_SUPPORT__ */ 

    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_close
 * DESCRIPTION
 *  This function is to close a video file/array/stream.
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  The result of this action.(?)
 *****************************************************************************/
void media_vid_close(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_close_req_struct,msg_p);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vid_send_incoming_ilm(src_mod_id, MSG_ID_MEDIA_VID_CLOSE_REQ,(void*)msg_p);

    vid_wait_event(VID_EVT_CLOSE);
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_play
 * DESCRIPTION
 *  This function is to start video playing.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  play            [?]         
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_play(module_type src_mod_id, media_vid_play_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_play_req_struct, msg_p);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_PLAY_REQ,
        msg_p, data, sizeof(media_vid_play_req_struct));
    vid_wait_event(VID_EVT_PLAY);
    return vid_result;
}

/*****************************************************************************
 * FUNCTION
 *  media_vid_get_frame
 * DESCRIPTION
 *  This function is to get frame to the given position.
 * PARAMETERS
 *  src_mod_id      [IN]
 *  get_frame            [?]
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_get_frame(module_type src_mod_id, media_vid_get_frame_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_get_frame_req_struct, msg_p);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_GET_FRAME_REQ,
        msg_p, data, sizeof(media_vid_get_frame_req_struct));
    vid_wait_event(VID_EVT_GET_FRAME);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_seek
 * DESCRIPTION
 *  This function is to seek to the given position.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  seek            [?]         
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_seek(module_type src_mod_id, media_vid_seek_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_seek_req_struct, msg_p);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_SEEK_REQ,
        msg_p, data, sizeof(media_vid_seek_req_struct));
    vid_wait_event(VID_EVT_SEEK);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_pause_visual_update
 * DESCRIPTION
 *  Pause for update layer parameters 
 * PARAMETERS
 *  src_mod_id                                  [IN]        
 *  media_vid_update_blt_pause_req_struct       [IN]        
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_pause_visual_update(module_type src_mod_id, media_vid_pause_visual_update_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_pause_visual_update_req_struct, msg_p);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_PAUSE_VISUAL_UPDATE_REQ,
        msg_p, data, sizeof(media_vid_pause_visual_update_req_struct));
    vid_wait_event(VID_EVT_BLOCK);
    return vid_result;
}

/*****************************************************************************
 * FUNCTION
 *  media_vid_resume_visual_update
 * DESCRIPTION
 *  Resume for update layer parameters 
 * PARAMETERS
 *  src_mod_id                                  [IN]        
 *  media_vid_update_layer_resume_req_struct      [IN]        
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_resume_visual_update(module_type src_mod_id, media_vid_resume_visual_update_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_resume_visual_update_req_struct, msg_p);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_RESUME_VISUAL_UPDATE_REQ,
        msg_p, data, sizeof(media_vid_resume_visual_update_req_struct));
    vid_wait_event(VID_EVT_BLOCK);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_set_param
 * DESCRIPTION
 *  This function is to set video parameters.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  param           [?]         
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_set_param(module_type src_mod_id, media_vid_set_param_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_set_param_req_struct, msg_p);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_SET_PARAM_REQ,
        msg_p, data, sizeof(media_vid_set_param_req_struct));
    vid_wait_event(VID_EVT_BLOCK);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_get_param
 * DESCRIPTION
 *  This function is to get video parameters.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  param           [?]         
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_get_param(module_type src_mod_id, media_vid_get_param_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_get_param_req_struct, msg_p);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_GET_PARAM_REQ,
        msg_p, data, sizeof(media_vid_get_param_req_struct));
    vid_wait_event(VID_EVT_GET_INFO);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_get_audio_profile
 * DESCRIPTION
 *  get audio profile
 * PARAMETERS
 *  channel_no        [IN]        
 *  sampling_rate       [IN]        
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
void media_vid_get_audio_profile(module_type src_mod_id, kal_uint8 *channel_no_p, kal_uint16 *sampling_rate_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* function called, src_mod_id not used */
    
	*channel_no_p = vid_context_p->audio_channel_no;
    *sampling_rate_p = vid_context_p->audio_sample_rate;  
}

/*****************************************************************************
 * FUNCTION
 *  media_vid_get_current_play_time
 * DESCRIPTION
 *  This function is to get current time when video playing. 
 *  This function will be call under MMI context
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  time            [?]         
 * RETURNS
 *  The result of this action.(?)
 *****************************************************************************/
void media_vid_get_current_play_time(module_type src_mod_id, kal_uint64 *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_get_play_time_req_struct, msg_p);
    media_vid_get_play_time_req_struct data_struct;
    media_vid_get_play_time_req_struct *data = &data_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data->cur_time_p = time;
    vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_GET_PLAY_TIME_REQ,
        msg_p, data, sizeof(media_vid_get_play_time_req_struct));
    vid_wait_event(VID_EVT_GET_INFO);
}

/*****************************************************************************
 * FUNCTION
 *  media_vid_set_volume_level
 * DESCRIPTION
 *  This function is to set volume
 * PARAMETERS
 *  src_mod_id      [IN]    module id
 *  volume_level    [IN]    volume level (From 0~100)
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_vid_set_volume_level(module_type src_mod_id, kal_uint8 volume_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(volume_level > 100)
    {
        return MED_RES_FAIL;
    }

    vid_set_vol_level(volume_level);
    return MED_RES_OK;
}

#if !defined(__MED_IN_ASM__)
/*****************************************************************************
 * FUNCTION
 *  media_vid_check_med_ready
 * DESCRIPTION
 *  This function is used to check if med is ready to play vid or not
 * PARAMETERS
 *  src_mod_id      [IN]        source module  
 *  data            [IN]        data
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_check_med_ready(module_type src_mod_id, media_vid_check_med_ready_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_check_med_ready_req_struct, msg_p);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;

    vid_send_incoming_ilm(src_mod_id, MSG_ID_MEDIA_VID_CHECK_MED_READY_REQ,(void*)msg_p);
    vid_wait_event(VID_EVT_BLOCK);
    return vid_result;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  media_vid_get_is_lcd_updated
 * DESCRIPTION
 *  This function is to get if lcd is updated when play fail
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8 mode
 *****************************************************************************/
kal_bool media_vid_get_is_lcd_updated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return vid_context_p->is_lcd_updated;
}


#if defined(__MED_VID_PDL_MOD__)
/*****************************************************************************
 * FUNCTION
 *  media_vid_get_pdl_percent
 * DESCRIPTION
 *  get progressive download's buffer percentage
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [IN]         
 * RETURNS
 *  The result of this action.(?)
 *****************************************************************************/
kal_int32 media_vid_get_pdl_percent(module_type src_mod_id, media_vid_get_pdl_percent_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_get_pdl_percent_req_struct, msg_p);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_GET_PDL_PRECENT_REQ,
        msg_p, data, sizeof(media_vid_get_pdl_percent_req_struct));
    vid_wait_event(VID_EVT_GET_INFO);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_get_pdl_max_play_time
 * DESCRIPTION
 *  get progressive download's max play time
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [IN]         
 * RETURNS
 *  The result of this action.(?)
 *****************************************************************************/
kal_int32 media_vid_get_pdl_max_time(module_type src_mod_id, media_vid_get_pdl_max_time_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_get_pdl_max_time_req_struct, msg_p);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_GET_PDL_MAX_TIME_REQ,
        msg_p, data, sizeof(media_vid_get_pdl_max_time_req_struct));
    vid_wait_event(VID_EVT_GET_INFO);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_check_is_pdl_file
 * DESCRIPTION
 *  get progressive download's max play time
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [IN]         
 * RETURNS
 *  The result of this action.(?)
 *****************************************************************************/
kal_int32 media_vid_check_is_pdl_file(module_type src_mod_id, media_vid_check_is_pdl_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_check_is_pdl_req_struct, msg_p);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_CHECK_IS_PDL_REQ,
        msg_p, data, sizeof(media_vid_check_is_pdl_req_struct));
    vid_wait_event(VID_EVT_GET_INFO);
    return vid_result;
}
#endif /* defined(__MED_VID_PDL_MOD__) */




#endif /* defined (__MED_VID_DEC_MOD__)  */

#ifdef __MED_VCALL_MOD__


/*****************************************************************************
 * FUNCTION
 *  media_vid_set_vt_mode
 * DESCRIPTION
 *  This function is to set engineer mode of video function.
 * PARAMETERS
 *  mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_vid_set_vt_mode(kal_uint8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_context_p->vt_mode = mode;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_get_vt_mode
 * DESCRIPTION
 *  This function is to get engineer mode of video function.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8 mode
 *****************************************************************************/
kal_uint8 media_vid_get_vt_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return vid_context_p->vt_mode;
}

#endif /* __MED_VCALL_MOD__ */

#ifdef __MED_VID_CLIP_MOD__
/*****************************************************************************
 * FUNCTION
 *  media_vid_clip_open
 * DESCRIPTION
 *  This function is to start video clipping function.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  preview         [?]         
 *  vid_record_struct* record(?)
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_clip_open(module_type src_mod_id, media_vid_clip_open_req_struct* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_clip_open_req_struct, msg_p);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    
    vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_CLIP_OPEN_REQ,
        msg_p, data, sizeof(media_vid_clip_open_req_struct));
    
    VID_WAIT_EVENT(VID_EVT_OPEN);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_clip_prepare
 * DESCRIPTION
 *  This function is to start video clipping function.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  preview         [?]         
 *  vid_record_struct* record(?)
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_clip_prepare(module_type src_mod_id, media_vid_clip_prepare_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_clip_prepare_req_struct, msg_p);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    
    vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_CLIP_PREPARE_REQ,
        msg_p, data, sizeof(media_vid_clip_prepare_req_struct));
    
    VID_WAIT_EVENT(VID_EVT_BLOCK);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_clip_start
 * DESCRIPTION
 *  This function is to start video clipping function.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  preview         [?]         
 *  vid_record_struct* record(?)
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_clip_start(module_type src_mod_id, media_vid_clip_start_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_clip_start_req_struct, msg_p);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;

    vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_CLIP_START_REQ,
        msg_p, data, sizeof(media_vid_clip_start_req_struct));
    
    VID_WAIT_EVENT(VID_EVT_START);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_clip_stop
 * DESCRIPTION
 *  This function is to stop video clipping function.
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_clip_stop(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_clip_stop_req_struct, msg_p);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    
    vid_send_incoming_ilm(src_mod_id, MSG_ID_MEDIA_VID_CLIP_STOP_REQ, (void*)msg_p);
    
    VID_WAIT_EVENT(VID_EVT_STOP);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_clip_stop
 * DESCRIPTION
 *  This function is to stop video clipping function.
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_clip_close(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_clip_close_req_struct, msg_p);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    vid_send_incoming_ilm(src_mod_id, MSG_ID_MEDIA_VID_CLIP_CLOSE_REQ, (void*)msg_p);    
    VID_WAIT_EVENT(VID_EVT_CLOSE);
    return vid_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vid_clip_get_param
 * DESCRIPTION
 *  This function is to get parameter.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  preview         [?]         
 *  vid_record_struct* record(?)
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
kal_int32 media_vid_clip_get_param(module_type src_mod_id, media_vid_clip_get_param_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_clip_get_param_req_struct, msg_p);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_result = MED_RES_OK;
    vid_send_incoming_ilm_with_data(src_mod_id, MSG_ID_MEDIA_VID_CLIP_GET_PARAM_REQ,
        msg_p, data, sizeof(media_vid_clip_get_param_req_struct));
    
    VID_WAIT_EVENT(VID_EVT_BLOCK);
    return vid_result;
}
#endif /* __MED_VID_CLIP_MOD__ */

#endif /* MED_NOT_PRESENT */ 

