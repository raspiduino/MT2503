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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   bitstream_ilm.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains BITSTREAM main procedures.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#ifdef WIN32
#include <stdio.h>
#endif 

/* KAL - RTOS Abstraction Layer */
#include "kal_release.h"
#include "kal_public_api.h"

/* Task Message Communication */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* local/peer struct */
#include "stack_ltlcom.h"

/* Task Management */
//#include "syscomp_config.h"
//#include "task_config.h"

/* Timer Management  */
//#include "stacklib.h"
//#include "event_shed.h" /* event schedulet */
//#include "stack_timer.h"

//#include "app_buff_alloc.h"     /* buffer management API */
//#include "lcd_cqueue.h" /* circular queue */
//#include "app2soc_struct.h"     /* interface with Applications */

//#include "stack_utils.h"

//#include "kal_trace.h"

#include "med_global.h"
#include "med_struct.h"
//#include "med_trc.h"

#ifdef __MED_BITSTREAM_MOD__

#include "bitstream_main.h"
#include "bitstream_api.h"

#include "kal_general_types.h"
#include "stack_config.h"
#include "kal_active_module.h"
    
/*****************************************************************************
 * FUNCTION
 *  bitstream_send_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
void bitstream_send_msg(module_type src_id, module_type dst_id, kal_uint16 msg_id, void *local_param_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = allocate_ilm(src_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr->src_mod_id = src_id;
    ilm_ptr->dest_mod_id = dst_id;
    ilm_ptr->sap_id = MED_SAP;
    ilm_ptr->msg_id = (msg_type) msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  media_bitstream_audio_open_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_bitstream_audio_open_handle(module_type src_mod_id, kal_int32 *handle, bitstream_audio_open_param_struct *open_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bitstream_audio_open_req_struct *msg_p = (media_bitstream_audio_open_req_struct*)
        construct_local_para(sizeof(media_bitstream_audio_open_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->handle = handle;
    msg_p->codec_type = open_param->codec_type;
    msg_p->isStereo = open_param->isStereo;
    msg_p->bitPerSample = open_param->bitPerSample;
    msg_p->sampleFreq = open_param->sampleFreq;

    bitstream_send_msg(src_mod_id, MOD_MED, MSG_ID_MEDIA_BITSTREAM_AUDIO_OPEN_REQ, msg_p);

    BITSTREAM_WAIT_EVENT(BITSTREAM_EVT_WAIT);
    return bitstream_cntx_p->return_status;
}


/*****************************************************************************
 * FUNCTION
 *  media_bitstream_audio_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_bitstream_audio_close(module_type src_mod_id, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bitstream_audio_close_req_struct *msg_p = (media_bitstream_audio_close_req_struct*)
        construct_local_para(sizeof(media_bitstream_audio_close_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->handle = handle;

    bitstream_send_msg(src_mod_id, MOD_MED, MSG_ID_MEDIA_BITSTREAM_AUDIO_CLOSE_REQ, msg_p);

    BITSTREAM_WAIT_EVENT(BITSTREAM_EVT_WAIT);
    return bitstream_cntx_p->return_status;
}


/*****************************************************************************
 * FUNCTION
 *  meida_bitstream_audio_get_buffer_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_bitstream_audio_get_buffer_status(module_type src_mod_id, kal_int32 handle, kal_uint32 *total_size, kal_uint32 *free_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bitstream_audio_get_buffer_status_req_struct *msg_p = (media_bitstream_audio_get_buffer_status_req_struct*)
        construct_local_para(sizeof(media_bitstream_audio_get_buffer_status_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->handle = handle;
    msg_p->total_size = total_size;
    msg_p->free_size = free_size;

    bitstream_send_msg(src_mod_id, MOD_MED, MSG_ID_MEDIA_BITSTREAM_AUDIO_GET_BUFFER_STATUS_REQ, msg_p);

    BITSTREAM_WAIT_EVENT(BITSTREAM_EVT_WAIT);
    return bitstream_cntx_p->return_status;
}


/*****************************************************************************
 * FUNCTION
 *  media_bitstream_audio_put_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_bitstream_audio_put_data(module_type src_mod_id, kal_int32 handle, kal_uint8 *app_buf, kal_uint32 app_buf_size, kal_uint32 *used_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bitstream_audio_put_data_req_struct *msg_p = (media_bitstream_audio_put_data_req_struct*)
        construct_local_para(sizeof(media_bitstream_audio_put_data_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->handle = handle;
    msg_p->p_app_buf = app_buf;
    msg_p->app_buf_size = app_buf_size;
    msg_p->p_used_size = used_size;

    bitstream_send_msg(src_mod_id, MOD_MED, MSG_ID_MEDIA_BITSTREAM_AUDIO_PUT_DATA_REQ, msg_p);

    BITSTREAM_WAIT_EVENT(BITSTREAM_EVT_WAIT);
    return bitstream_cntx_p->return_status;
}


/*****************************************************************************
 * FUNCTION
 *  media_bitstream_audio_put_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_bitstream_audio_put_frame(module_type src_mod_id, kal_int32 handle, kal_uint8 *app_buf, kal_uint32 app_buf_size, kal_uint64 timestamp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bitstream_audio_put_frame_req_struct *msg_p = (media_bitstream_audio_put_frame_req_struct*)
        construct_local_para(sizeof(media_bitstream_audio_put_frame_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->handle = handle;
    msg_p->p_app_buf = app_buf;
    msg_p->app_buf_size = app_buf_size;
    msg_p->timestamp= timestamp;

    bitstream_send_msg(src_mod_id, MOD_MED, MSG_ID_MEDIA_BITSTREAM_AUDIO_PUT_FRAME_REQ, msg_p);

    BITSTREAM_WAIT_EVENT(BITSTREAM_EVT_WAIT);
    return bitstream_cntx_p->return_status;
}


/*****************************************************************************
 * FUNCTION
 *  media_bitstream_audio_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_bitstream_audio_start(module_type src_mod_id, kal_int32 handle, kal_uint32 start_time, kal_uint8 audio_path, kal_uint8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bitstream_audio_start_req_struct *msg_p = (media_bitstream_audio_start_req_struct*)
        construct_local_para(sizeof(media_bitstream_audio_start_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->handle = handle;
    msg_p->start_time = start_time;
    msg_p->audio_path = audio_path;
    msg_p->volume = volume;

    bitstream_send_msg(src_mod_id, MOD_MED, MSG_ID_MEDIA_BITSTREAM_AUDIO_START_REQ, msg_p);

    BITSTREAM_WAIT_EVENT(BITSTREAM_EVT_WAIT);
    return bitstream_cntx_p->return_status;
}


/*****************************************************************************
 * FUNCTION
 *  media_bitstream_audio_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_bitstream_audio_stop(module_type src_mod_id, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bitstream_audio_stop_req_struct *msg_p = (media_bitstream_audio_stop_req_struct*)
        construct_local_para(sizeof(media_bitstream_audio_stop_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->handle = handle;

    bitstream_send_msg(src_mod_id, MOD_MED, MSG_ID_MEDIA_BITSTREAM_AUDIO_STOP_REQ, msg_p);

    BITSTREAM_WAIT_EVENT(BITSTREAM_EVT_WAIT);
    return bitstream_cntx_p->return_status;
}

/*****************************************************************************
 * FUNCTION
 *  media_bitstream_audio_finished
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_bitstream_audio_finished(module_type src_mod_id, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bitstream_audio_finished_req_struct *msg_p = (media_bitstream_audio_finished_req_struct*)
        construct_local_para(sizeof(media_bitstream_audio_finished_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->handle = handle;

    bitstream_send_msg(src_mod_id, MOD_MED, MSG_ID_MEDIA_BITSTREAM_AUDIO_FINISHED_REQ, msg_p);

    BITSTREAM_WAIT_EVENT(BITSTREAM_EVT_WAIT);
    return bitstream_cntx_p->return_status;
}

/*****************************************************************************
 * FUNCTION
 *  media_bitstream_audio_get_play_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_bitstream_audio_get_play_time(module_type src_mod_id, kal_int32 handle, kal_uint32 *play_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bitstream_audio_get_play_time_req_struct *msg_p = (media_bitstream_audio_get_play_time_req_struct*)
        construct_local_para(sizeof(media_bitstream_audio_get_play_time_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->handle = handle;
    msg_p->play_time = play_time;

    bitstream_send_msg(src_mod_id, MOD_MED, MSG_ID_MEDIA_BITSTREAM_AUDIO_GET_PLAY_TIME_REQ, msg_p);

    BITSTREAM_WAIT_EVENT(BITSTREAM_EVT_WAIT);
    return bitstream_cntx_p->return_status;
}


/*****************************************************************************
 * FUNCTION
 *  media_bitstream_record_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_bitstream_record_open(kal_uint8 codec_type, kal_uint8 quality, kal_int32 *handle_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bitstream_record_open_req_struct *msg_p = (media_bitstream_record_open_req_struct*)
        construct_local_para(sizeof(media_bitstream_record_open_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->codec_type = codec_type;
    msg_p->quality = quality;
    msg_p->handle_p = handle_p;

    bitstream_send_msg(kal_get_active_module_id(), MOD_MED, MSG_ID_MEDIA_BITSTREAM_RECORD_OPEN_REQ, msg_p);

    BITSTREAM_WAIT_EVENT(BITSTREAM_EVT_WAIT);
    return bitstream_cntx_p->return_status;
}


/*****************************************************************************
 * FUNCTION
 *  media_bitstream_record_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_bitstream_record_close(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bitstream_record_close_req_struct *msg_p = (media_bitstream_record_close_req_struct*)
        construct_local_para(sizeof(media_bitstream_record_close_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->handle = handle;

    bitstream_send_msg(kal_get_active_module_id(), MOD_MED, MSG_ID_MEDIA_BITSTREAM_RECORD_CLOSE_REQ, msg_p);

    BITSTREAM_WAIT_EVENT(BITSTREAM_EVT_WAIT);
    return bitstream_cntx_p->return_status;
}


/*****************************************************************************
 * FUNCTION
 *  media_bitstream_record_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_bitstream_record_start(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bitstream_record_start_req_struct *msg_p = (media_bitstream_record_start_req_struct*)
        construct_local_para(sizeof(media_bitstream_record_start_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->handle = handle;

    bitstream_send_msg(kal_get_active_module_id(), MOD_MED, MSG_ID_MEDIA_BITSTREAM_RECORD_START_REQ, msg_p);

    BITSTREAM_WAIT_EVENT(BITSTREAM_EVT_WAIT);
    return bitstream_cntx_p->return_status;
}


/*****************************************************************************
 * FUNCTION
 *  media_bitstream_record_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_bitstream_record_stop(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bitstream_record_stop_req_struct *msg_p = (media_bitstream_record_stop_req_struct*)
        construct_local_para(sizeof(media_bitstream_record_stop_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->handle = handle;

    bitstream_send_msg(kal_get_active_module_id(), MOD_MED, MSG_ID_MEDIA_BITSTREAM_RECORD_STOP_REQ, msg_p);

    BITSTREAM_WAIT_EVENT(BITSTREAM_EVT_WAIT);
    return bitstream_cntx_p->return_status;
}


/*****************************************************************************
 * FUNCTION
 *  media_bitstream_record_set
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_bitstream_record_set(kal_int32 handle, kal_uint8 set_type, void* data_p, kal_uint16 data_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bitstream_record_set_req_struct *msg_p = (media_bitstream_record_set_req_struct*)
        construct_local_para(sizeof(media_bitstream_record_set_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->handle = handle;
    msg_p->set_type = set_type;
    msg_p->data_p = data_p;
    msg_p->data_len = data_len;

    bitstream_send_msg(kal_get_active_module_id(), MOD_MED, MSG_ID_MEDIA_BITSTREAM_RECORD_SET_REQ, msg_p);

    BITSTREAM_WAIT_EVENT(BITSTREAM_EVT_WAIT);
    return bitstream_cntx_p->return_status;
}


/*****************************************************************************
 * FUNCTION
 *  media_bitstream_record_get
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_bitstream_record_get(kal_int32 handle, kal_uint8 get_type, void* data_p, kal_uint16* data_len_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bitstream_record_get_req_struct *msg_p = (media_bitstream_record_get_req_struct*)
        construct_local_para(sizeof(media_bitstream_record_get_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->handle = handle;
    msg_p->get_type = get_type;
    msg_p->data_p = data_p;
    msg_p->data_len_p = data_len_p;

    bitstream_send_msg(kal_get_active_module_id(), MOD_MED, MSG_ID_MEDIA_BITSTREAM_RECORD_GET_REQ, msg_p);

    BITSTREAM_WAIT_EVENT(BITSTREAM_EVT_WAIT);
    return bitstream_cntx_p->return_status;
}


#endif /* __MED_BITSTREAM_MOD__ */

