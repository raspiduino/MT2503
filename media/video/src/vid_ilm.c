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
 * vid_ilm.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes send-ilm related funcions of image module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES ===========*/

/* system includes */
//#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "drv_comm.h"
#include "med_global.h"
#include "med_vid_clip_features.h"
#include "med_vid_clip_struct.h"
#include "med_struct.h"
#include "med_context.h"
#include "med_trc.h"
#include "vid_main.h"

#define CONSTRUCT_LOCAL_PARAM(st, name) \
    st* name = (st*) construct_local_para(sizeof(st), TD_CTRL)


#include "med_v_struct.h"

#include "kal_general_types.h"
#include "stack_config.h"
#include "stack_ltlcom.h"

#if defined(__MED_VID_ENC_MOD__)

/*****************************************************************************
 * FUNCTION
 *  vid_send_record_finish_ind
 * DESCRIPTION
 *  This function is to send video record finished indication to the request module
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_record_finish_ind(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_record_finish_ind_struct, ind_p);
    
    ind_p->result = result;
    ind_p->seq_num = vid_context_p->seq_num;


    vid_send_outgoing_ilm(vid_context_p->src_mod, MSG_ID_MEDIA_VID_RECORD_FINISH_IND,(void*)ind_p);
}


/*****************************************************************************
 * FUNCTION
 *  vid_send_file_merge_done_ind
 * DESCRIPTION
 *  This function is to send video record finished indication to the request module
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_file_merge_done_ind(kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_file_merge_done_ind_struct, ind_p);
    
    ind_p->result = result;

    vid_send_outgoing_ilm(vid_context_p->src_mod, MSG_ID_MEDIA_VID_FILE_MERGE_DONE_IND,(void*)ind_p);

}


/*****************************************************************************
 * FUNCTION
 *  vid_send_autofocus_process_done_ind
 * DESCRIPTION
 *  This function is to send camera autofocus event indication message.
 * PARAMETERS
 *  event       [IN]
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_autofocus_process_done_ind(kal_uint8 result, kal_uint32 zone)
{
#ifdef __CAM_AUTO_FOCUS__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_af_ind_struct,ind_p);

    ind_p->af_search_result = result;
    ind_p->af_success_zone = zone;

    vid_send_outgoing_ilm(vid_context_p->src_mod,MSG_ID_MEDIA_VID_AF_PROCESS_DONE_IND,(void*)ind_p);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vid_send_event_ind
 * DESCRIPTION
 *  This function is to send camera event indication message.
 * PARAMETERS
 *  event       [IN]
 *  cause       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_event_ind(kal_uint32 event, kal_int32 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_event_ind_struct,ind_p);

    ind_p->event = event;
    ind_p->cause = cause;

    vid_send_outgoing_ilm(MOD_MED,MSG_ID_MEDIA_VID_EVENT_IND,(void*)ind_p);
}

#endif /* defined(__MED_VID_ENC_MOD__) */

#if defined(__MED_VID_DEC_MOD__)

/*****************************************************************************
 * FUNCTION
 *  vid_send_file_ready_ind
 * DESCRIPTION
 *  This function is to send video file ready indication to the request module
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_file_ready_ind(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_file_ready_ind_struct, ind_p);
#if defined (__VIDEO_3D_ANAGLYPH__) || defined(__VIDEO_SUBTITLE_SUPPORT__)    
    kal_int32 idx;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ind_p->result = result;
    ind_p->image_width = vid_context_p->image_width;
    ind_p->image_height = vid_context_p->image_height;
    ind_p->total_time = vid_context_p->total_time;
    ind_p->seq_num = vid_context_p->seq_num;
    ind_p->file_handle = vid_context_p->file_handle;
    ind_p->is_seekable = vid_context_p->is_seekable;
#ifdef __VIDEO_CLIPPER_SUPPORT__     
    ind_p->is_proprietary = vid_context_p->is_proprietary;
#endif
#ifdef __VIDEO_3D_ANAGLYPH__    
    ind_p->track_num = vid_context_p->track_num;

    ASSERT(vid_context_p->track_num <= VID_MAX_VIDEO_TRACK_NUM);        
    for (idx = 0; idx < vid_context_p->track_num; idx ++)
    {
        ind_p->track_info[idx] = vid_context_p->track_info[idx];
    }
#endif
#ifdef __VIDEO_SUBTITLE_SUPPORT__
    ind_p->subtitle_num = vid_context_p->subtitle_num;

    ASSERT(vid_context_p->subtitle_num <= VID_MAX_VIDEO_SUBTITLE_NUM);        
    for (idx = 0; idx < vid_context_p->subtitle_num; idx ++)
    {
        ind_p->subtitle_info[idx] = vid_context_p->subtitle_info[idx];
    }
#endif

    vid_send_outgoing_ilm(vid_context_p->src_mod, MSG_ID_MEDIA_VID_FILE_READY_IND,(void*)ind_p);
}


/*****************************************************************************
 * FUNCTION
 *  vid_send_play_finish_ind
 * DESCRIPTION
 *  This function is to send video play finish indication to the request module
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_play_finish_ind(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_play_finish_ind_struct,ind_p);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_SEND_PLAY_FINISH_IND);

    ind_p->result = result;
    ind_p->seq_num = vid_context_p->seq_num;

    vid_send_outgoing_ilm(vid_context_p->src_mod,MSG_ID_MEDIA_VID_PLAY_FINISH_IND,(void*)ind_p);

}


/*****************************************************************************
 * FUNCTION
 *  vid_send_seek_done_ind
 * DESCRIPTION
 *  This function is to send seek done indication to the request module
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_seek_done_ind(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_seek_done_ind_struct,ind_p);

    ind_p->result = result;
    ind_p->seq_num = vid_context_p->seq_num;

    vid_send_outgoing_ilm(vid_context_p->src_mod,MSG_ID_MEDIA_VID_SEEK_DONE_IND,(void*)ind_p);
}

#endif /* (__MED_VID_DEC_MOD__) */

#ifdef __MED_VID_CLIP_MOD__
/*****************************************************************************
 * FUNCTION
 *  vid_send_clip_finish_ind
 * DESCRIPTION
 *  This function is to send video clip finished indication to the request module
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_prepare_cnf_ind(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_clip_prepare_cnf_struct, ind_p);
    
    ind_p->result = result;


    vid_send_outgoing_ilm(vid_clip_context_p->src_mod, MSG_ID_MEDIA_VID_CLIP_PREPARE_CNF,(void*)ind_p);
}


/*****************************************************************************
 * FUNCTION
 *  vid_send_clip_finish_ind
 * DESCRIPTION
 *  This function is to send video clip finished indication to the request module
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_clip_finish_ind(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_clip_finish_ind_struct, ind_p);
    
    ind_p->result = result;
    ind_p->seq_num = vid_clip_context_p->seq_num;


    vid_send_outgoing_ilm(vid_clip_context_p->src_mod, MSG_ID_MEDIA_VID_CLIP_FINISH_IND,(void*)ind_p);
}


/*****************************************************************************
 * FUNCTION
 *  vid_send_clip_event_ind
 * DESCRIPTION
 *  This function is to send camera event indication message.
 * PARAMETERS
 *  event       [IN]
 *  cause       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_clip_event_ind(kal_uint32 event, kal_int32 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_vid_clip_event_ind_struct,ind_p);

    ind_p->event = event;
    ind_p->cause = cause;

    vid_send_outgoing_ilm(MOD_MED,MSG_ID_MEDIA_VID_CLIP_EVENT_IND,(void*)ind_p);
}
#endif /* __MED_VID_CLIP_MOD__ */

#endif /* MED_NOT_PRESENT */

