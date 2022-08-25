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
 *   media_session_sec.c
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

#include "media_session.h"
#include "media_provider.h"
#include "media_player.h"
#include "media_session_prot.h"

#include "med_utility.h"
//#include "custom_sw_video.h"
#include "vcodec_v2_trc.h"

 /*****************************************************************************
 * FUNCTION
 *  media_session_do_recover
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
 void media_session_do_recover(media_player_client_t* client, media_player_event_t event, kal_uint32 event_param)
 {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct* self = SELF(client, media_session_struct, player_client);
    media_player_t *player = self->player;
    media_provider_t *provider = self->provider;
    media_provider_frame_positioning_t *fpc;
    media_error_t ret;        
    media_player_param_t player_param;
    kal_int32 result;
    kal_bool underflow;
    media_time_t key_frame_time = 0, start_time;
    kal_uint64 diff, end_time, cur_time;
    media_codec_type_t codec_type;
    kal_uint32 format_index;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
            
    ASSERT(self->state == MEDIA_SESSION_STATE_STARTED);

    underflow = media_session_player_is_underflow(&self->mpl);
    if (underflow)
    {
        media_session_stop_play(&self->mpl);
        
        result = player_event_to_med_result_enum(&self->mpl, event, event_param);            
        self->mpl_client->on_event(self->mpl_client, MPL_PLAYER_EVENT_PLAY, result);
        return; /* CANNOT remove. */
    }            
     
    provider->get_control(
     provider, MEDIA_PROVIDER_CONTROL_FRAME_POSITIONING, (void**)&fpc);
    if (!fpc)
    {
        /* jump to I from buffer */
        player->jump_to_i_frame(player, 0);
        return; /* CANNOT remove. */
    }

    /* Get end_time */      
    cur_time = media_session_get_play_time(&self->mpl);

    codec_type = self->vid_stream.dec_config.codec;
    format_index = mpl_get_vid_custom_format_index(codec_type);

    diff = mply_custom_get_cust(format_index, 2);
    end_time = cur_time + diff;

    /* Get start_time */
    player_param.type = MEDIA_PLAYER_PARAM_TYPE_MAX_VID_FRAME_TIME;
    player->get_param(player, &player_param);
    start_time = player_param.val.time;

    if (start_time >= end_time)
    {
        /* jump to I from buffer */
        player->jump_to_i_frame(player, 0);
        return; /* CANNOT remove. */
    }

    /* Stop decoder to make provider to get key frame quickly */
    player_param.type = MEDIA_PLAYER_PARAM_TYPE_STOP_DECODER;
    player->set_param(player, &player_param);

    ret = fpc->get_key_frame_time(
             fpc, 
             self->vid_stream_index, 
             MEDIA_SEARCH_BACKWARD, 
             end_time,
             &key_frame_time);    

    /* Run decoder */
    player_param.type = MEDIA_PLAYER_PARAM_TYPE_RUN_DECODER;
    player->set_param(player, &player_param);

    kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_GET_KEY_FRAME_TIME, ret,
        (kal_uint32) start_time, (kal_uint32) end_time, (kal_uint32)key_frame_time);
    if (ret == MED_S_OK && start_time < key_frame_time)
    {
        ASSERT(key_frame_time != 0);
        ASSERT(key_frame_time <= end_time);
     
        /* jump to I from file */
        player->jump_to_i_frame(player, key_frame_time);
        /* Call after player releases all the frame */
        ret = fpc->seek(fpc, self->vid_stream_index, key_frame_time); 
        kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_FAIL, ret, __LINE__);
        if (ret < 0)
        {
            media_session_pretend_eos(&self->mpl, self->vid_stream_index);
        }
    }
    else
    {
        /* jump to I from buffer */
        player->jump_to_i_frame(player, 0);
    }     
}
#endif /* __VIDEO_ARCHI_V2__ */

