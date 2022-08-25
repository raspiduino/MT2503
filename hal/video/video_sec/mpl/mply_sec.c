/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   media_player_sec.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/

#if defined(__VIDEO_ARCHI_V2__)
#include "kal_release.h"
//#include "med_global.h"
#include "media_player.h"

/* Audio */
#include "L1audio.h"

#include "aud_main.h"
/* Video */
#include "Video_types_v2.h"
#include "video_render_component_v2.h"
#include "video_decoder_component_v2.h"
#include "video_decoder_il_if_v2.h"
#include "video_decscheduler_component_if_v2.h"
#include "video_buffer_management_v2.h"
#include "video_decoder_demuxer_if_v2.h"

#include "visual_comm.h"

/* LCD */
#include "lcd_if.h"

#include "media_enum.h"

#include "media_player_prot.h"

#include "img_common_enum.h"
#include "hal_custom_video.h"
#include "mpl_utility.h"
#include "vcodec_v2_trc.h"


/*****************************************************************************
 * FUNCTION
 *  media_player_do_recover
 * DESCRIPTION
 *  The function is to do recover 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
media_error_t media_player_do_recover(media_player_t* mp, media_time_t key_frame_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_player_cntx_struct* self = SELF(mp, media_player_cntx_struct, itf);
    VIDEO_DECODER_QUERY_I_FRM_T query;
    VIDEO_ERROR_TYPE_T error;
    kal_bool found;
    kal_uint64 decode_time, diff;
    media_data_t *node = NULL, *head = NULL, *found_node = NULL;
    VIDEO_COMPONENT_TYPE_T *dec_handle = self->decoder_handle;
    kal_uint32 event_group, format_index;
    media_codec_type_t codec_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, VID_TRC_MEDIA_PLAYER_JUMP_TO_I_FRAME, self->state, (kal_uint32)key_frame_time);

    if (self->state == MPLY_STATE_CLOSED ||
        self->state == MPLY_STATE_OPENED ||
        self->state == MPLY_STATE_PREPARED ||
        self->state == MPLY_STATE_SEEKING || 
        self->state == MPLY_STATE_SEEK_DONE)
    {
        return MED_E_WRONG_STATE;
    }

    ASSERT(self->vid_stream_index != MEDIA_PLAYER_INVALID_INDEX);
    kal_take_mutex(media_player_mutex);
    /**************************************************
     ** Jump to I frame in file
     **************************************************/
    if (key_frame_time > 0)
    {   
        /* Flush frame */
        error = dec_handle->pfnSetParameter(VIDEO_PARAM_FLUSH_FRM, NULL);
        ASSERT(error == VIDEO_ERROR_NONE ||
               error == VIDEO_ERROR_NO_FRAME_TO_FLUSH);

        /* Wait until flush frame is done */
        if (error == VIDEO_ERROR_NONE)
        {   
            /* release mutex for decoder to release frame */
            kal_give_mutex(media_player_mutex);
            MPLY_SET_FLAG(MPLY_FLAG_WAIT_FLUSH_FRAME);
            kal_retrieve_eg_events(media_player_comp_eg, MEDIA_PLAYER_EG_DECODER_FLUSH_FRAME_DONE, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
            MPLY_UNSET_FLAG(MPLY_FLAG_WAIT_FLUSH_FRAME);
            kal_take_mutex(media_player_mutex);
        }
        
        /* Flush frame in queue */
        media_player_reset_queue(mp, MPLY_QUEUE_VIDEO_WRITTEN);
        media_player_reset_queue(mp, MPLY_QUEUE_VIDEO);
        self->vid_life_cycle_id ++; 
        self->vid_queue_num = 0;
        MPLY_UNSET_FLAG(MPLY_FLAG_VID_BUFF_FULL);        

        /* Enable skip non-I frame */
        MPLY_SET_FLAG(MPLY_FLAG_SKIP_NON_I_FRAME);
        self->key_frame_time = key_frame_time;
        goto finish;
    }  

    /**************************************************
     ** Jump to I frame in queue
     **************************************************/  
    codec_type = self->vid_stream.dec_config.codec;
    format_index = mpl_get_vid_custom_format_index(codec_type);

    diff = mply_custom_get_cust(format_index, 2);
    ASSERT(diff > 0);
    error = self->decoder_handle->pfnGetParameter(VIDEO_PARAM_QUERY_DECODE_TIME, &decode_time);
    decode_time = MEDIA_PLAYER_COMPTIME_TO_TIME(decode_time);  
    found = KAL_FALSE;
    
    /* Search I frame with max T from queue's head */ 
    if (self->video_queue)
    {        
        node = head = self->video_queue->next;        
        do
        {   
            if ((node->flags & MEDIA_DATA_FLAG_KEY_FRAME) &&
                (node->display_time <= decode_time + diff))
            {
                found = KAL_TRUE;
                found_node = node;
            }
            node = node->next;
        }
        while (node != head);
    }

    kal_trace(TRACE_FUNC, VID_TRC_MEDIA_PLAYER_JUMP_INFO, 
        found, (kal_uint32)decode_time, (kal_uint32)diff);
    
    /* If I frame is found, drop P, B frame */ 
    if (found && found_node != NULL)
    {
        /* Flush all the frame in decoder */
        error = dec_handle->pfnSetParameter(VIDEO_PARAM_FLUSH_FRM, NULL);
        ASSERT(error == VIDEO_ERROR_NONE ||
               error == VIDEO_ERROR_NO_FRAME_TO_FLUSH);

        /* Wait until flush frame is done */
        if (error == VIDEO_ERROR_NONE)
        {   
            kal_give_mutex(media_player_mutex);
            MPLY_SET_FLAG(MPLY_FLAG_WAIT_FLUSH_FRAME);
            kal_retrieve_eg_events(media_player_comp_eg, MEDIA_PLAYER_EG_DECODER_FLUSH_FRAME_DONE, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
            MPLY_UNSET_FLAG(MPLY_FLAG_WAIT_FLUSH_FRAME);
            kal_take_mutex(media_player_mutex);
        }        
        
        /* Flush frame in queue */
        media_player_reset_queue(mp, MPLY_QUEUE_VIDEO_WRITTEN);
        self->vid_life_cycle_id ++; 
        self->vid_queue_num = 0;
        MPLY_UNSET_FLAG(MPLY_FLAG_VID_BUFF_FULL);
        
        /* Flush P, B frame in queue */
        head = self->video_queue->next; 
        while(head != found_node)
        {       
            media_player_remove_from_queue(&self->video_queue, head);
            head->release(head);
            self->vid_queue_num --;
            
            head = self->video_queue->next;
        }        
        goto finish;
    }

    /**************************************************
     ** Jump to I frame in decoder
     **************************************************/

    /* Check if decoder input queue has I frame */
    query.u8TimeDifference = MEDIA_PLAYER_TIME_TO_COMPTIME(diff);
    query.fgRet = KAL_FALSE;    

    error = self->decoder_handle->pfnGetParameter(VIDEO_PARAM_IS_I_FRM_IN_QUEUE, &query);
    ASSERT(error == VIDEO_ERROR_NONE);

    if (query.fgRet)
    {
        error = self->decoder_handle->pfnSetParameter(VIDEO_PARAM_FLUSH_FRM_BEFORE_I, NULL);
        goto finish;
    }
    
finish:    
    mpl_start_timer(
        MPL_PLAYER_RECOVER_TIMER, MPLY_RESET_RECOVER_ELAPSE, 
        media_player_reset_recover, self);

    kal_give_mutex(media_player_mutex);
    return MED_S_OK;
} 




#endif /* (__VIDEO_ARCHI_V2__) */
