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
 *   media_session.c
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features_video.h"
#if defined(__VIDEO_ARCHI_V2__)
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "kal_trace.h"
#include "stack_config.h"

//#include "med_global.h" // TODO:

#include "mpl_common.h" // mpl common type definition
#include "mpl_player.h" // mpl player interface definition
#include "mpl_utility.h"

#include "media_provider.h"
#include "media_player.h"
#include "media_session_prot.h"

#include "fsal.h"
#include "l1audio.h"

#include "vcodec_v2_trc.h"
/*=============out of HAL==================*/

#include "stream.h" // for streaming, removed ?
#include "med_smalloc.h"



#define MSES_ASSERT(exp) if(!(exp)) {ASSERT(0);}
#define mpl_player_alloc_ext_mem(client, size, type) (((mpl_player_client_t*)client)->mem_alloc_func(client, size, type, __FILE__, __LINE__))
#define mpl_player_free_ext_mem(client, p, type) (((mpl_player_client_t*)client)->mem_free_func(client, p, type, __FILE__, __LINE__))
/***************************************************************************** 
 * Private Function
 *****************************************************************************/
static media_session_struct *media_session_cntx_p[MEDIA_SESSION_MAX_CONTEXT]; 

/*****************************************************************************
* FUNCTION
*  media_session_init
* DESCRIPTION
*  This function is to initialize media session when boot up
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
kal_bool media_session_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return KAL_TRUE;
}

#if 0
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
* FUNCTION
*  provider_event_to_med_result_enum
* DESCRIPTION
*  
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t provider_event_to_med_result_enum(media_provider_event_t event, media_error_t error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (event >= 0)
    {
        return MED_S_OK;
    }

    switch (event)
    {
        case MEDIA_PROVIDER_EVENT_MEMORY_INSUFFICIENT: 
            //return MED_RES_MEM_INSUFFICIENT;
            return MED_E_MEM_INSUFFICIENT;
        case MEDIA_PROVIDER_EVENT_CORRUPTED_DATA:    
            //return MED_RES_BAD_FORMAT;
            return MED_E_BAD_FORMAT;
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        case MEDIA_PROVIDER_EVENT_OPEN_FAIL: 
            //return (error >= 0) ? MED_RES_OPEN_FILE_FAIL : to_med_result_enum(error);
            return (error >= 0) ? MED_E_OPEN_FILE_FAIL : error;
        case MEDIA_PROVIDER_EVENT_START_FAIL: 
            //return (error >= 0) ? MED_RES_FAIL : to_med_result_enum(error);
            return (error >= 0) ? MED_E_FAIL : error;
        default:
            break;
    }
    return MED_E_FAIL;
    
}


/*****************************************************************************
* FUNCTION
*  player_event_to_med_result_enum
* DESCRIPTION
*  
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
media_error_t player_event_to_med_result_enum(mpl_player_t* mpl, media_player_event_t event, media_error_t error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (event)
    {
        case MEDIA_PLAYER_EVENT_AUDIO_PLAY_ERROR:   
            //return MED_RES_AUDIO_ERROR;
            return MED_E_AUDIO_ERROR;
        case MEDIA_PLAYER_EVENT_VIDEO_PLAY_ERROR: 
            //return (error >= 0) ? MED_RES_VIDEO_ERROR : to_med_result_enum(error);
            return (error >= 0) ? MED_E_VIDEO_ERROR : error;
        case MEDIA_PLAYER_EVENT_VIDEO_DECODER_NOT_SUPPORT:
            //return MED_RES_DECODER_NOT_SUPPORT;
            return MED_E_DECODER_NOT_SUPPORT;
        case MEDIA_PLAYER_EVENT_STOP_TIME_REACHED: 
            //return MED_RES_STOP_TIME_REACHED;
            return MED_E_STOP_TIME_REACHED;
        case MEDIA_PLAYER_EVENT_END_OF_MEDIA: 
        {
            if (MSES_IS_FLAG_SET(MSES_PLAYER_FLAG_IS_PROVIDER_VIDEO_ERROR) &&
                MSES_IS_FLAG_SET(MSES_PLAYER_FLAG_IS_PROVIDER_AUDIO_ERROR))
            {
                //return MED_RES_VIDEO_ERROR;
                return MED_E_VIDEO_ERROR;
            }
            /* Pure audio and audio error */
            else if (MSES_IS_FLAG_SET(MSES_PLAYER_FLAG_IS_PROVIDER_AUDIO_ERROR) &&
                     self->vid_stream_index == MEDIA_SESSION_INVALID_INDEX)
            {
                return MED_E_AUDIO_ERROR;                
            }
            /* Pure video and video error */
            else if (MSES_IS_FLAG_SET(MSES_PLAYER_FLAG_IS_PROVIDER_VIDEO_ERROR) &&
                     self->aud_stream_index == MEDIA_SESSION_INVALID_INDEX)
            {
                return MED_E_VIDEO_ERROR;                
            }
            else
            {
                //return MED_RES_PLAY_FINISH; 
                return MED_S_PLAY_FINISH; 
            }
            break;
        }
        case MEDIA_PLAYER_EVENT_AUDIO_UNDERFLOW: 
        {
            if (self->media_mode == MED_MODE_STREAM)
            {
                //return MED_RES_STREAM_BUFFER_UNDERFLOW;
                return MED_E_STREAM_BUFFER_UNDERFLOW;
            }
            else if (self->media_mode == MED_MODE_PDL_FILE)
            {
                //return MED_RES_PDL_AUDIO_UNDERFLOW;
                return MED_E_PDL_AUDIO_UNDERFLOW;
            }
            break;
        }
        case MEDIA_PLAYER_EVENT_RECOVER_STOP_AUDIO:
        case MEDIA_PLAYER_EVENT_RECOVER_JUMP_TO_I:    
        {
            if (self->media_mode == MED_MODE_STREAM)
            {
                //return MED_RES_STREAM_BUFFER_UNDERFLOW;
                return MED_E_STREAM_BUFFER_UNDERFLOW;
            }
            else if (self->media_mode == MED_MODE_PDL_FILE)
            {
                //return MED_RES_PDL_VIDEO_UNDERFLOW;
                return MED_E_PDL_VIDEO_UNDERFLOW;
            }
            break;
        }        
        default:
            break;
    }
    return MED_E_FAIL;
}


/*****************************************************************************
* FUNCTION
*  media_session_set_global_context
* DESCRIPTION
*  This function is to set global context
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static void media_session_set_global_context(mpl_player_t* mpl, kal_bool init)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (init)
    {
        if (media_session_cntx_p[0] == NULL)
        {
            media_session_cntx_p[0] = self;
        }
        else if (media_session_cntx_p[1] == NULL)
        {
            media_session_cntx_p[1] = self;
        }
        else
        {
            MSES_ASSERT(0);
        }
    }
    else
    {
        if (self == media_session_cntx_p[0])
        {
            media_session_cntx_p[0] = NULL;
        }
        else if (self == media_session_cntx_p[1])
        {
            media_session_cntx_p[1] = NULL;
        }
        else
        {
            MSES_ASSERT(0);
        }
    }
}


/*****************************************************************************
* FUNCTION
*  media_session_get_provider_mem_size
* DESCRIPTION
*  This function is to get custom memory size
* PARAMETERS
*  media_type       [IN]      media type.
*  media_mode       [IN]      media mode.
*  mem_type         [IN]      memory type.
* RETURNS
*  kal_uint32
*****************************************************************************/
kal_uint32 media_session_get_provider_mem_size(kal_uint8 media_type, kal_uint8 media_mode, media_provider_memory_type_t mem_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_session_struct *self = media_session_cntx_p[0];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(MP4_DECODE)
    if (media_type == MED_TYPE_MP4 || media_type == MED_TYPE_3GP)
    {
    #ifdef __VE_STREAM_SUPPORT__    
        if (media_mode == MEDIA_PROVIDER_OPEN_CONNECT)
        {
            if (mem_type == MEDIA_PROVIDER_MEM_CORE)
            {
                return STREAMING_MP_CORE_MEM_SIZE;
            }
            else if (mem_type == MEDIA_PROVIDER_MEM_AUDIO)
            {
                if (self->media_scenario == MPL_PREVIEW)
                {
                    return STREAMING_MP_AUDIO_MEM_SIZE;
                }
                else
                {
                    return STREAMING_MP_AUDIO_MEM_SIZE;
                }
            }
            else if (mem_type == MEDIA_PROVIDER_MEM_VIDEO)
            {
                return STREAMING_MP_VIDEO_MEM_SIZE;
            }
            else
            {
                return 0;
            }
        }
        else
    #endif /* __VE_STREAM_SUPPORT__ */        
        {
            if (mem_type == MEDIA_PROVIDER_MEM_CORE)
            {
                return MP4_MP_CORE_MEM_SIZE;
            }
            else if (mem_type == MEDIA_PROVIDER_MEM_AUDIO)
            {
                if (self->media_scenario == MPL_PREVIEW)
                {
                    return MP4_MP_AUDIO_PREVIEW_MEM_SIZE;
                }
                else
                {
                    return MP4_MP_AUDIO_MEM_SIZE;
                }
            }
            else if (mem_type == MEDIA_PROVIDER_MEM_VIDEO)
            {
                if (self->media_scenario == MPL_PREVIEW)
                {
                    return MP4_MP_VIDEO_PREVIEW_MEM_SIZE;
                }
                else
                {
                    return MP4_MP_VIDEO_MEM_SIZE;
                }
            }
            else
            {
                return 0;
            }
        }    
    }
#endif /* defined(MP4_DECODE) */  

#if defined(MJPG_DECODE)
    if (media_type == MED_TYPE_MJPG || media_type == MED_TYPE_AVI)
    {
        if (mem_type == MEDIA_PROVIDER_MEM_CORE)
        {
            return AVI_MP_CORE_MEM_SIZE;
        }
        else if (mem_type == MEDIA_PROVIDER_MEM_AUDIO)
        {
            if (self->media_scenario == MPL_PREVIEW)
            {
                return AVI_MP_AUDIO_PREVIEW_MEM_SIZE;
            }
            else
            {
                return AVI_MP_AUDIO_MEM_SIZE;
            }
        }
        else if (mem_type == MEDIA_PROVIDER_MEM_VIDEO)
        {
            if (self->media_scenario == MPL_PREVIEW)
            {
                return AVI_MP_VIDEO_PREVIEW_MEM_SIZE;
            }
            else
            {
                return AVI_MP_VIDEO_MEM_SIZE;
            }
        }
        else
        {
            return 0;
        }
    }
#endif /* defined(MJPG_DECODE) */

#if defined(__RM_DEC_SUPPORT__)
    if (media_type == MED_TYPE_RM || media_type == MED_TYPE_RV ||
        media_type == MED_TYPE_RA || media_type == MED_TYPE_RMVB)
    {
        if (mem_type == MEDIA_PROVIDER_MEM_CORE)
        {
            return RM_MP_CORE_MEM_SIZE;
        }
        else if (mem_type == MEDIA_PROVIDER_MEM_AUDIO)
        {
            if (self->media_scenario == MPL_PREVIEW)
            {
                return RM_MP_AUDIO_PREVIEW_MEM_SIZE;
            }
            else
            {
                return RM_MP_AUDIO_MEM_SIZE;
            }
        }
        else if (mem_type == MEDIA_PROVIDER_MEM_VIDEO)
        {
            if (self->media_scenario == MPL_PREVIEW)
            {
                return RM_MP_VIDEO_PREVIEW_MEM_SIZE;
            }
            else
            {
                return RM_MP_VIDEO_MEM_SIZE;
            }
        }
        else
        {
            return 0;
        }
    }
#endif /* defined(__RM_DEC_SUPPORT__) */

#ifdef __VE_FLV_FILE_FORMAT_SUPPORT__
    if (media_type == MED_TYPE_FLV)
    {
        if (mem_type == MEDIA_PROVIDER_MEM_CORE)
        {
            return FLV_MP_CORE_MEM_SIZE;
        }
        else if (mem_type == MEDIA_PROVIDER_MEM_AUDIO)
        {
            if (self->media_scenario == MPL_PREVIEW)
            {
                return FLV_MP_AUDIO_PREVIEW_MEM_SIZE;
            }
            else
            {
                return FLV_MP_AUDIO_MEM_SIZE;
            }
        }
        else if (mem_type == MEDIA_PROVIDER_MEM_VIDEO)
        {
            if (self->media_scenario == MPL_PREVIEW)
            {
                return FLV_MP_VIDEO_PREVIEW_MEM_SIZE;
            }
            else
            {
                return FLV_MP_VIDEO_MEM_SIZE;
            }
        }
        else
        {
            return 0;
        }
    }
#endif /* __VE_FLV_FILE_FORMAT_SUPPORT__ */

    return 0;
}
/*****************************************************************************
* FUNCTION
*  media_session_update_play_time
* DESCRIPTION
*  This function is update play time
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
media_time_t media_session_get_play_time(mpl_player_t* mpl)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);
    media_player_t *player = self->player;
    media_player_param_t player_param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    player_param.type = MEDIA_PLAYER_PARAM_TYPE_PLAY_TIME;
    player->get_param(player, &player_param);            
 
    if (player_param.val.time < self->curr_time)
    {
        return self->curr_time;
    }
    else
    {
        return player_param.val.time;
    }
}

/*****************************************************************************
* FUNCTION
*  media_session_player_alloc_mem
* DESCRIPTION
*  This function is to allocate player memory
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
void* media_session_player_alloc_mem(media_player_client_t *client, kal_int32 size, med_mem_type_enum type, char* file_p, long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct* self = SELF(client, media_session_struct, player_client);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mpl_player_alloc_ext_mem(self->mpl_client, size, type);
}

/*****************************************************************************
* FUNCTION
*  media_session_player_free_mem
* DESCRIPTION
*  This function is to free player memory
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
void media_session_player_free_mem(media_player_client_t *client, void** p, med_mem_type_enum type, char* file_p, long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct* self = SELF(client, media_session_struct, player_client);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mpl_player_free_ext_mem(self->mpl_client, p, type);
}

/*****************************************************************************
* FUNCTION
*  media_session_player_is_underflow
* DESCRIPTION
*  
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
kal_bool media_session_player_is_underflow(mpl_player_t* mpl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);
    kal_uint32 percent;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Always don't handle recover */
    if (self->media_mode == MED_MODE_STREAM)
    {
        return KAL_TRUE;
    }
    else if (self->media_mode == MED_MODE_PDL_FILE)
    {
        media_session_get_buffer_percent(&self->dl_control, &percent);
        if (percent != 100)
        {
            return KAL_TRUE;
        }
    }
    return KAL_FALSE;
}

/*****************************************************************************
* FUNCTION
*  media_session_init_player
* DESCRIPTION
*  This function is to open and prepare media player
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_init_player(mpl_player_t* mpl)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);
    media_player_t *player;
    media_error_t ret;  
    kal_uint32 dummy;
    media_player_param_t set_param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MSES_ASSERT(!self->player);
    /* Open Media Player */
    player = self->player = construct_media_player(&self->player_client);
    if (!player)
    {
        kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_FAIL, MED_E_FAIL, __LINE__);
        return MED_E_FAIL;
    }
    
    ret = player->open(player, self->media_scenario, self->media_mode, self->fgSeekable);
    if (ret < 0)
    {
        player->destroy(player);
        self->player = NULL;
        return ret;
    }
    
    /* Add stream */
//    if (self->media_mode != MED_MODE_STREAM)
//    {
    if (self->vid_stream_index != MEDIA_SESSION_INVALID_INDEX &&
        self->media_track != MED_VID_AUDIO_ONLY)
    {
        player->add_video_stream(player, &self->vid_stream, &dummy);
    }
    
    if (self->aud_stream_index != MEDIA_SESSION_INVALID_INDEX &&
        self->media_track != MED_VID_VISUAL_ONLY)
    {
        player->add_audio_stream(player, &self->aud_stream, &dummy);
    }
            
    /* Prepare Media Player */
    ret = player->prepare(player);
    if (ret < 0)
    {
        kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_FAIL, ret, __LINE__);
        player->close(player);
        player->destroy(player);
        self->player = NULL;
        return ret;
    }
//    }

    /* Set parameter to player */
    if(self->bit_flag & MSES_PLAYER_FLAG_IS_AUD_VOLUME_SET)
    {
        set_param.type = MEDIA_PLAYER_PARAM_TYPE_VOLUME;
        set_param.val.volume = self->aud_volume;
        player->set_param(player, &set_param); 
    }
    /*
    if(self->bit_flag & MSES_PLAYER_FLAG_IS_STOP_TIME_SET)
    {
        set_param.type = MEDIA_PLAYER_PARAM_TYPE_STOP_TIME;
        set_param.val.volume = self->stop_time;
        player->set_param(player, &set_param);  
    } 
    */

    if(self->bit_flag & MSES_PLAYER_FLAG_IS_SLEEP_TIME_SET)
    {
        set_param.type = MEDIA_PLAYER_PARAM_TYPE_SLEEP_TIME;
        set_param.val.sleep_time.elapse_ticks = self->elapse_ticks;
        set_param.val.sleep_time.sleep_ticks = self->sleep_ticks;
        player->set_param(player, &set_param);  
    }

    if (self->vid_stream_index != MEDIA_SESSION_INVALID_INDEX &&
        self->media_track != MED_VID_AUDIO_ONLY)
    {
        set_param.type = MEDIA_PLAYER_PARAM_TYPE_BRIGHTNESS;
        set_param.val.brightness = self->brightness;
        player->set_param(player, &set_param);

        set_param.type = MEDIA_PLAYER_PARAM_TYPE_CONTRAST;
        set_param.val.contrast = self->brightness;
        player->set_param(player, &set_param);
    }

    return MED_S_OK;
}


/*****************************************************************************
* FUNCTION
*  media_session_provider_alloc_mem
* DESCRIPTION
*  This function is to allocate provider memory
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
void* media_session_provider_alloc_mem(media_provider_client_t *client, kal_int32 size, med_mem_type_enum type, char* file_p, long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct* self = SELF(client, media_session_struct, provider_client);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mpl_player_alloc_ext_mem(self->mpl_client, size, type);
}

/*****************************************************************************
* FUNCTION
*  media_session_provider_free_mem
* DESCRIPTION
*  This function is to free provider memory
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
void media_session_provider_free_mem(media_provider_client_t *client, void** p, med_mem_type_enum type, char* file_p, long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct* self = SELF(client, media_session_struct, provider_client);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mpl_player_free_ext_mem(self->mpl_client, p, type);
}

/*****************************************************************************
* FUNCTION
*  media_session_provider_on_stream_found
* DESCRIPTION
*  
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static void media_session_provider_on_stream_found(media_provider_client_t* client, media_stream_t* stream)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(client, media_session_struct, provider_client);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MSES_ASSERT(self->media_mode != MED_MODE_STREAM);

    if (!stream->selected)
    {
        return;
    }   

    if (stream->type == MEDIA_STREAM_TYPE_VIDEO)
    {
        self->vid_stream = *stream;
        self->vid_stream_index = stream->index;
    }
    else if (stream->type == MEDIA_STREAM_TYPE_AUDIO)
    {
        self->aud_stream = *stream;
        self->aud_stream_index = stream->index;
    }
    
}


/*****************************************************************************
* FUNCTION
*  media_session_provider_on_media_data
* DESCRIPTION
*  
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static void media_session_provider_on_media_data(
                media_provider_client_t* client, 
                kal_uint32 stream_index, 
                media_data_t* media_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct* self = SELF(client, media_session_struct, provider_client);
    media_player_t *player = self->player;
    media_error_t ret;

        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSES_ASSERT(self->media_mode != MED_MODE_STREAM);

    MSES_ASSERT(self->state == MEDIA_SESSION_STATE_SEEKING ||
           self->state == MEDIA_SESSION_STATE_STARTED);
    
    ret = player->deliver(player, stream_index, media_data);
    MSES_ASSERT(ret >= 0);
}


/*****************************************************************************
* FUNCTION
*  media_session_pretend_eos
* DESCRIPTION
*  
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
void media_session_pretend_eos(mpl_player_t* mpl, kal_uint32 stream_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);
    media_player_param_t set_param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_PRETEND_EOS, stream_index, self->state);
    /* Send error msg to MMI until the corrupted stream is fully consumed */
    if (stream_index == self->vid_stream_index)
    {
        MSES_SET_FLAG(MSES_PLAYER_FLAG_IS_PROVIDER_VIDEO_ERROR);

        /* Update duration first to avoid play to the pre-defined duration */
        set_param.type = MEDIA_PLAYER_PARAM_TYPE_UPDATE_VID_DURATION;
        self->player->set_param(self->player, &set_param); 

        self->player->notify_eos(self->player, self->vid_stream_index);
    }
    else if (stream_index == self->aud_stream_index)
    {
        MSES_SET_FLAG(MSES_PLAYER_FLAG_IS_PROVIDER_AUDIO_ERROR);
        self->player->notify_eos(self->player, self->aud_stream_index);
    }
}

/*****************************************************************************
* FUNCTION
*  media_session_provider_error_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static void media_session_provider_error_hdlr(media_provider_client_t* client, media_provider_event_t event, kal_uint32 event_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct* self = SELF(client, media_session_struct, provider_client);
    media_provider_t *provider = self->provider;
    media_error_t result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSES_ASSERT(self->media_mode != MED_MODE_STREAM);

    if (self->state == MEDIA_SESSION_STATE_OPENING)
    {
        provider->destroy(provider);
        self->provider = NULL;
        
        self->state = MEDIA_SESSION_STATE_CLOSED;

        result = provider_event_to_med_result_enum(event, (media_error_t)event_param);
        self->mpl_client->on_event(self->mpl_client, MPL_PLAYER_EVENT_OPEN, result);
        
    }
    else if (self->state == MEDIA_SESSION_STATE_STARTED)
    {       
        if ((event == MEDIA_PROVIDER_EVENT_CORRUPTED_DATA ||
             event == MEDIA_PROVIDER_EVENT_MEMORY_INSUFFICIENT) &&
             self->media_mode != MED_MODE_STREAM)
        {
            media_session_pretend_eos(&self->mpl, event_param);            
        }
        else
        {
            media_session_stop_play(&self->mpl);

            result = provider_event_to_med_result_enum(event, (media_error_t)event_param);            
            self->mpl_client->on_event(self->mpl_client, MPL_PLAYER_EVENT_PLAY, result);
        }    
    }
    else if (self->state == MEDIA_SESSION_STATE_SEEKING)
    {
        media_session_stop_seek(&self->mpl);

        result = provider_event_to_med_result_enum(event, (media_error_t)event_param);
        self->mpl_client->on_event(self->mpl_client, MPL_PLAYER_EVENT_SEEK, result); 
        
    }
    else if (self->state == MEDIA_SESSION_STATE_OPENED)
    {
        result = provider_event_to_med_result_enum(event, (media_error_t)event_param);
        /* Receive streaming disconnect event on OPENED state */
        self->mpl_client->on_event(self->mpl_client, MPL_PLAYER_EVENT_OPEN, result);
    }
}

/*****************************************************************************
* FUNCTION
*  media_session_provider_on_event
* DESCRIPTION
*  
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_provider_on_event(media_provider_client_t* client, media_provider_event_t event, kal_uint32 event_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct* self = SELF(client, media_session_struct, provider_client);
    media_provider_t *provider = self->provider;
    media_player_t *player = self->player;
    media_error_t ret;
    media_player_param_t set_param;
    kal_uint32 capability;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_PROVIDER_ON_EVENT, self->state, event);

    MSES_ASSERT(self->media_mode != MED_MODE_STREAM);

    if (event < 0)
    {
        media_session_provider_error_hdlr(client, event, event_param);        
    }   
    else if (event == MEDIA_PROVIDER_EVENT_STARTED)
    {
        if (self->media_mode == MED_MODE_STREAM &&
            self->state == MEDIA_SESSION_STATE_SEEKING)
        {
            MSES_SET_FLAG(MSES_PLAYER_FLAG_IS_PROVIDER_STARTED);
            self->mpl_client->on_event(self->mpl_client, MPL_PLAYER_EVENT_SEEK, MED_S_ASYNC);
        }
    } 
    else if (event == MEDIA_PROVIDER_EVENT_BUFFER_OVERFLOW)
    {
        self->mpl_client->on_event(self->mpl_client, MPL_PLAYER_EVENT_SEEK, MED_E_STREAM_BUFFER_OVERFLOW);
    }
    else if (event == MEDIA_PROVIDER_EVENT_OPENED)
    {       
        self->fs_handle = ((STFSAL*)event_param)->hFile;

        if (self->state == MEDIA_SESSION_STATE_OPENING)
        {
            /* provider opened*/
            provider->get_characteristics(provider, &capability);
            if(capability & MEDIA_PROVIDER_CAN_SEEK)
            {
                self->fgSeekable = KAL_TRUE;
            }
            else
            {
                self->fgSeekable = KAL_FALSE;
            }

            if (self->media_mode != MED_MODE_STREAM)
            {
                ret = media_session_init_player(&self->mpl);
                player = self->player;
                if (ret < 0)
                {
                    provider->close(provider);   
                    provider->destroy(provider);
                    self->provider = NULL;

                    self->state = MEDIA_SESSION_STATE_CLOSED;

                    self->mpl_client->on_event(self->mpl_client, MPL_PLAYER_EVENT_OPEN, MED_E_FAIL);
                    return MED_S_OK;
                }               
            }
            
            /* Initialize parameter */
            self->force_seek = KAL_TRUE;  

            self->state = MEDIA_SESSION_STATE_OPENED;
            
            if (self->vid_stream_index != MEDIA_SESSION_INVALID_INDEX)
            {
                self->mpl_client->on_event(self->mpl_client, MPL_PLAYER_EVENT_OPEN, MED_S_OK);
            }
            else
            {
                self->mpl_client->on_event(self->mpl_client, MPL_PLAYER_EVENT_OPEN, MED_E_MP4_NO_VIDEO_TRACK);
            }          
        }
    }    
    else if (event == MEDIA_PROVIDER_EVENT_END_OF_STREAM)
    {
        if (self->state == MEDIA_SESSION_STATE_SEEKING ||
            self->state == MEDIA_SESSION_STATE_STARTED)
        {
            self->player->notify_eos(self->player, event_param);
            if (event_param == self->aud_stream_index)
            {
                MSES_SET_FLAG(MSES_PLAYER_FLAG_IS_RECEIVE_AUDIO_EOS);
            }
        }
    }
    else if (event == MEDIA_PROVIDER_EVENT_AUDIO_TIME_DIFF_ACQUIRED)
    {
        if(self->player != NULL)
        {
            set_param.type = MEDIA_PLAYER_PARAM_TYPE_AUD_TIME_DIFF;
            set_param.val.aud_time_diff = event_param;
            player->set_param(player, &set_param); 
        }
    }
    else if (event == MEDIA_PROVIDER_EVENT_ONE_FRAME_SENT)
    {
        /* video preview only*/
        if (self->media_mode != MED_MODE_STREAM)
        {
            media_session_pretend_eos(&self->mpl, self->vid_stream_index);
        }
    }
    
    return MED_S_OK;
}


/*****************************************************************************
* FUNCTION
*  media_session_player_stop_audio_event_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static void media_session_player_stop_audio_event_hdlr(media_player_client_t* client, media_player_event_t event, kal_uint32 event_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct* self = SELF(client, media_session_struct, player_client);
    media_player_t *player = self->player;
    media_error_t ret;        
    media_player_param_t player_param;
    media_error_t result;
    kal_bool underflow;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MSES_ASSERT(self->state == MEDIA_SESSION_STATE_STARTED);

    /* Get current time */
    self->curr_time = media_session_get_play_time(&self->mpl);  

    /* Stop play first */
    media_session_stop_play(&self->mpl);

    underflow = media_session_player_is_underflow(&self->mpl);
    if (underflow)
    {      
        result = player_event_to_med_result_enum(&self->mpl, event, (media_error_t)event_param);
        self->mpl_client->on_event(self->mpl_client, MPL_PLAYER_EVENT_PLAY, result);
        return; /* CANNOT remove */
    }
            
    /* Play again */
    player_param.type = MEDIA_PLAYER_PARAM_TYPE_PLAY_SPEED;
    player->get_param(player, &player_param);
    ret = media_session_play_internal(&self->mpl, player_param.val.play_speed, KAL_TRUE);
    if (ret < 0)
    {
        self->mpl_client->on_event(self->mpl_client, MPL_PLAYER_EVENT_PLAY, MED_E_VIDEO_ERROR);
    }
    else if (ret == MED_S_TERMINATED)
    {
        self->mpl_client->on_event(self->mpl_client, MPL_PLAYER_EVENT_PLAY, MED_S_PLAY_FINISH);
    } 

}


/*****************************************************************************
* FUNCTION
*  media_session_player_start_event_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static void media_session_player_start_event_hdlr(media_player_client_t* client, media_player_event_t event, kal_uint32 event_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct* self = SELF(client, media_session_struct, player_client);
    media_player_t *player = self->player;
    media_provider_t *provider = self->provider;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MSES_ASSERT(self->state == MEDIA_SESSION_STATE_SEEKING);

    if(self->media_mode == MED_MODE_STREAM) 
    {
        //self->seek_state = MSES_SEEK_STATE_PLAYER_DONE;
        self->seek_state = MSES_SEEK_STATE_BUFFER_DONE;
    }
    else
    {
        provider->stop(provider);
        player->stop(player);
    }

    self->force_seek = KAL_FALSE;

    self->state = MEDIA_SESSION_STATE_OPENED;
    
    self->mpl_client->on_event(self->mpl_client, MPL_PLAYER_EVENT_SEEK, MED_S_OK);

}


/*****************************************************************************
* FUNCTION
*  media_session_player_on_event
* DESCRIPTION
*  
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static void media_session_player_on_event(media_player_client_t* client, media_player_event_t event, kal_uint32 event_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct* self = SELF(client, media_session_struct, player_client);
    media_provider_t *provider = self->provider;
    media_error_t result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_PLAYER_ON_EVENT, self->state, event);

    if (event == MEDIA_PLAYER_EVENT_STARTED || event == MEDIA_PLAYER_EVENT_AUDIO_FRAME_READY)
    {        
        if(self->state != MEDIA_SESSION_STATE_SEEKING)
        {
            return;
        }

        if (event == MEDIA_PLAYER_EVENT_STARTED)
        {
            MSES_SET_FLAG(MSES_PLAYER_FLAG_IS_VID_BUFFERED);
        }

        if (event == MEDIA_PLAYER_EVENT_AUDIO_FRAME_READY)
        {
            MSES_SET_FLAG(MSES_PLAYER_FLAG_IS_AUD_BUFFERED);
        }

        if (self->media_mode != MED_MODE_STREAM)
        {
            media_session_player_start_event_hdlr(client, event, event_param);
        }
        else
        {
            if (self->seek_state != MSES_SEEK_STATE_BUFFER_DONE)
            {
                if ((MSES_IS_FLAG_SET(MSES_PLAYER_FLAG_IS_VID_BUFFERED) && self->aud_stream_index == MEDIA_SESSION_INVALID_INDEX) ||
                    (MSES_IS_FLAG_SET(MSES_PLAYER_FLAG_IS_AUD_BUFFERED) && self->vid_stream_index == MEDIA_SESSION_INVALID_INDEX) ||
                    (MSES_IS_FLAG_SET(MSES_PLAYER_FLAG_IS_VID_BUFFERED) && MSES_IS_FLAG_SET(MSES_PLAYER_FLAG_IS_AUD_BUFFERED)))
                {
                    media_session_notify_stream_seek_done(&self->mpl);
                }
            }
        }
        
    }
    else if (event == MEDIA_PLAYER_EVENT_RECOVER_JUMP_TO_I)
    {
        if (self->media_mode == MED_MODE_STREAM)
        {
            self->mpl_client->on_event(self->mpl_client, MPL_PLAYER_EVENT_PLAY, MED_E_STREAM_AV_UNSYNC);
        }
        else
        {
            media_session_do_recover(client, event, event_param);
        }
    }
    else if (event == MEDIA_PLAYER_EVENT_RECOVER_STOP_AUDIO)
    {
        if (self->media_mode == MED_MODE_STREAM)
        {
            self->mpl_client->on_event(self->mpl_client, MPL_PLAYER_EVENT_PLAY, MED_E_STREAM_AV_UNSYNC);
        }
        else
        {
            media_session_player_stop_audio_event_hdlr(client, event, event_param);
        }
    }
    else if (event == MEDIA_PLAYER_EVENT_AUDIO_DATA_REQUEST)
    {
        if(self->media_mode != MED_MODE_STREAM)
        {
            provider->dispatch(provider);
        }
    }
    else if (event == MEDIA_PLAYER_EVENT_AUDIO_PLAY_ERROR ||
             event == MEDIA_PLAYER_EVENT_VIDEO_PLAY_ERROR ||
             event == MEDIA_PLAYER_EVENT_VIDEO_DECODER_NOT_SUPPORT ||
             event == MEDIA_PLAYER_EVENT_STOP_TIME_REACHED ||
             event == MEDIA_PLAYER_EVENT_AUDIO_UNDERFLOW ||
             event == MEDIA_PLAYER_EVENT_END_OF_MEDIA)
    {    
        /* Local playback: ignore audio underflow */
        if ((self->media_mode == MED_MODE_FILE || 
             self->media_mode == MED_MODE_ARRAY) &&
            event == MEDIA_PLAYER_EVENT_AUDIO_UNDERFLOW)
        {
            return;
        }

        if (event == MEDIA_PLAYER_EVENT_STOP_TIME_REACHED)
        {
            MSES_UNSET_FLAG(MSES_PLAYER_FLAG_IS_STOP_TIME_SET);
        }
        
        if (self->state == MEDIA_SESSION_STATE_SEEKING)
        {
            media_session_stop_seek(&self->mpl);
            
            result = player_event_to_med_result_enum(&self->mpl, event, (media_error_t)event_param);
            self->mpl_client->on_event(self->mpl_client, MPL_PLAYER_EVENT_SEEK, result);
        }
        else if (self->state == MEDIA_SESSION_STATE_STARTED)
        {
            media_session_stop_play(&self->mpl);

            result = player_event_to_med_result_enum(&self->mpl, event, (media_error_t)event_param);            
            self->mpl_client->on_event(self->mpl_client, MPL_PLAYER_EVENT_PLAY, result);
            
        }
    }
}


/*****************************************************************************
* FUNCTION
*  media_session_get_avail_time
* DESCRIPTION
*  This function is to get buffer percent
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
media_time_t media_session_get_avail_time(
                mpl_player_t* mpl, 
                media_time_t avail_aud, 
                media_time_t avail_vid, 
                media_time_t aud_dur, 
                media_time_t vid_dur)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_time_t avail_time;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_GET_AVAIL_TIME, 
        (kal_uint32)avail_aud, (kal_uint32)avail_vid, (kal_uint32)aud_dur, (kal_uint32)vid_dur);

    /* Live streaming. No duration */
    if (aud_dur == 0 && vid_dur == 0)
    {
        avail_time = (avail_aud > avail_vid) ? avail_vid : avail_aud;
    }
    /* A & V finish downloading */    
    else if (avail_aud >= aud_dur && avail_vid >= vid_dur)
    {
        avail_time = (vid_dur > aud_dur) ? vid_dur : aud_dur;
    }
    /* No A | A finish downloading */
    else if ( aud_dur == 0 || avail_aud >= aud_dur)
    {
        avail_time = avail_vid;
    }
    /* No V | V finish downloading */
    else if (vid_dur == 0 || avail_vid >= vid_dur)
    {
        avail_time = avail_aud;
    }
    /* A & V are downloading */
    else if (avail_aud < avail_vid)
    {
        avail_time = avail_aud;
    }
    else
    {
        avail_time = avail_vid;
    }
    kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_AVAIL_TIME, (kal_uint32)avail_time);
    return avail_time;    
}


/*****************************************************************************
* FUNCTION
*  media_session_set_play_video_config
* DESCRIPTION
*  This function is to set video configuration
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_set_play_video_config(
                            mpl_player_t* mpl, 
                            mpl_player_play_t* play_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);
    media_player_t *player = self->player;
    media_player_video_config_t video_config = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* local playback support switch between VISUAL_ONLY and BOTH in play */
    if (self->media_track == MED_VID_BOTH && !play_struct->play_audio)
    {
        self->media_track = MED_VID_VISUAL_ONLY;
    }
    else if (self->media_track == MED_VID_VISUAL_ONLY && play_struct->play_audio)
    {
        self->media_track = MED_VID_BOTH;
    }
    
    if (self->vid_stream_index != MEDIA_SESSION_INVALID_INDEX &&
        self->media_track != MED_VID_AUDIO_ONLY)
    {
        /* Prepare configuration */  
        video_config.brightness = self->brightness;
        video_config.contrast = self->contrast;
        video_config.display_width = play_struct->display_width;
        video_config.display_height = play_struct->display_height;        
        video_config.image_buffer_p = play_struct->image_buffer_p;        
        video_config.display_device = play_struct->display_device; 
        video_config.lcd_id = play_struct->lcd_id;
        video_config.update_layer = play_struct->update_layer;
        video_config.hw_update_layer = play_struct->hw_update_layer;
        video_config.force_lcd_hw_trigger = play_struct->force_lcd_hw_trigger;
        video_config.image_data_format = play_struct->image_data_format;
        video_config.idp_rotate = play_struct->idp_rotate;
        video_config.layer_element = play_struct->layer_element;
        video_config.blt_ctx = play_struct->blt_ctx;
        video_config.blt_dev = play_struct->blt_dev;
        /* Currently, only support stretch mode for playback */
        video_config.frame_mode = play_struct->frame_mode;
        player->set_video_config(player, self->vid_stream_index, &video_config);
    }
    return MED_S_OK;
}


/*****************************************************************************
* FUNCTION
*  media_session_set_seek_video_config
* DESCRIPTION
*  This function is to set video configuration
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_set_seek_video_config(
                            mpl_player_t* mpl, 
                            mpl_player_seek_t* seek_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);
    media_player_t *player = self->player;
    media_player_video_config_t video_config = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (self->vid_stream_index != MEDIA_SESSION_INVALID_INDEX &&
        seek_struct->get_frame)
    {
        /* Prepare configuration */ 
        video_config.brightness = self->brightness;
        video_config.contrast = self->contrast;
        video_config.display_width = seek_struct->display_width;
        video_config.display_height = seek_struct->display_height;        
        video_config.image_buffer_p = seek_struct->image_buffer_p;
        video_config.image_data_format = seek_struct->image_data_format;
        video_config.idp_rotate = seek_struct->idp_rotate;
        
        video_config.frame_mode = seek_struct->frame_mode;
        player->set_video_config(player, self->vid_stream_index, &video_config);
    }
    return MED_S_OK;
}


/*****************************************************************************
* FUNCTION
*  media_session_notify_stream_seek_done
* DESCRIPTION
*  This function is to notify stream seek done
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
media_error_t media_session_notify_stream_seek_done(mpl_player_t* mpl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (self->state == MEDIA_SESSION_STATE_SEEKING)
    {
        self->seek_state = MSES_SEEK_STATE_BUFFER_DONE;

        self->force_seek = KAL_FALSE;

        self->mpl_client->on_event(self->mpl_client, MPL_PLAYER_EVENT_SEEK, MED_S_OK);
    }
    return MED_S_OK;
}

/*****************************************************************************
* FUNCTION
*  media_session_reset_parameter
* DESCRIPTION
*  This function is to init parameter
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static void media_session_reset_parameter(mpl_player_t* mpl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    self->vid_stream_index = MEDIA_SESSION_INVALID_INDEX;
    self->aud_stream_index = MEDIA_SESSION_INVALID_INDEX;
    self->bit_flag = 0;
    self->seek_state = MSES_SEEK_STATE_IDLE;
    self->fgSeekable = KAL_TRUE;

    self->brightness = 128;
    self->contrast = 128;    
}


/*****************************************************************************
* FUNCTION
*  media_session_open
* DESCRIPTION
*  This function is to open media session
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_open(
                            mpl_player_t* mpl, 
                            mpl_player_open_t* open_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);
    media_provider_t *provider = NULL;
    media_error_t ret = MED_S_OK;    
    kal_uint8 media_type;
    media_provider_mode_t mode = MEDIA_PROVIDER_MODE_NORMAL;
    media_provider_open_source_t source = MEDIA_PROVIDER_OPEN_FILE;
    kal_uint32 capability;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_OPEN, self->state);

    if (self->state != MEDIA_SESSION_STATE_CLOSED)
    {
        return MED_E_WRONG_STATE;
    }    

    /* Reset parameter */
    media_session_reset_parameter(mpl);

    /* Assign scenario */
    self->media_scenario = (mpl_scenario_enum)open_struct->scenario_id;
    kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_SCENARIO, self->media_scenario);
    
    /* Assign mode */
    self->media_track = open_struct->open_track;
    switch (open_struct->open_track)
    {
        case MED_VID_BOTH:
            mode = MEDIA_PROVIDER_MODE_NORMAL;
            break;
        case MED_VID_VISUAL_ONLY:
            mode = MEDIA_PROVIDER_MODE_VIDEO;
            break;
        case MED_VID_AUDIO_ONLY:
            mode = MEDIA_PROVIDER_MODE_AUDIO;
            break; 
        default:
            MSES_ASSERT(0);
            break;
    }
    
    /* Assign source */
    self->media_mode = (med_mode_enum)open_struct->media_mode;
    switch (open_struct->media_mode)
    {
        case MED_MODE_FILE:
            source = MEDIA_PROVIDER_OPEN_FILE;
            break;
        case MED_MODE_ARRAY:
            source = MEDIA_PROVIDER_OPEN_BUFFER;
            break; 
        case MED_MODE_PDL_FILE:
            source = MEDIA_PROVIDER_OPEN_PDL;
            break;
        case MED_MODE_STREAM:
            source = MEDIA_PROVIDER_OPEN_CONNECT;
            break;
        default:
            MSES_ASSERT(0);
            break;
    }

    /* Media provider */
    MSES_ASSERT(!self->provider);
    media_type = open_struct->media_type;

#ifdef __VE_FLV_FILE_FORMAT_SUPPORT__
    if (media_type == MED_TYPE_F4V)
    {
        kal_bool validate;

        validate = ValidateF4VFormat(open_struct->data);
        if(validate == KAL_TRUE)
        {
            media_type = MED_TYPE_F4V;
        }
        validate = ValidateFLVFormat(open_struct->data);
        if(validate == KAL_TRUE)
        {
            media_type = MED_TYPE_FLV;
        }
    }

    if(media_type == MED_TYPE_F4V)
    {
        provider = self->provider = construct_mp4_media_provider(&self->provider_client, mode);
    }
    else if(media_type == MED_TYPE_FLV)
    {
        provider = self->provider = construct_flv_media_provider(&self->provider_client, mode);
    }
#endif

#if defined(MP4_DECODE)
    if (media_type == MED_TYPE_MP4 || media_type == MED_TYPE_3GP)
    {
    #ifdef __VE_STREAM_SUPPORT__    
        if (open_struct->media_mode == MED_MODE_STREAM)
        {
            //provider = self->provider = construct_streaming_provider(mode, self->app_id);
        }
        else
    #endif /* __VE_STREAM_SUPPORT__ */        
        {
            provider = self->provider = construct_mp4_media_provider(&self->provider_client, mode);
        }
    }
#endif /* MP4_DECODE */       
#if defined(__RM_DEC_SUPPORT__)
    if (media_type == MED_TYPE_RM || media_type == MED_TYPE_RV ||
        media_type == MED_TYPE_RA || media_type == MED_TYPE_RMVB)
    {
        provider = self->provider = construct_rm_media_provider(&self->provider_client, mode);
    }
#endif /* defined(__RM_DEC_SUPPORT__) */  
#if defined(MJPG_DECODE)
    if (media_type == MED_TYPE_MJPG)
    {
        provider = self->provider = construct_avi_media_provider(&self->provider_client, mode);
    }
#endif /*MJPG_DECODE */

    if (open_struct->media_mode != MED_MODE_STREAM)
    {
        /* The only failed case is insufficient memory */
        if (provider == NULL)
        {
            return MED_E_OUT_OF_MEMORY;
        }

        ret = provider->open(
                provider, 
                source,
                (const kal_uint8*) open_struct->data,
                open_struct->data_size,
                &self->provider_client);    

        if (ret < 0)
        {
            kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_FAIL, ret, __LINE__);
            provider->destroy(provider);
            self->provider = NULL;    

            return ret;
        }

        if (!open_struct->enable_aud_only && self->vid_stream_index == MEDIA_SESSION_INVALID_INDEX)
        {
            provider->close(provider);  
            provider->destroy(provider);
            self->provider = NULL;    

            return MED_E_CORRUPTED_DATA;
        }

        if (ret == MED_S_ASYNC)
        {
            self->state = MEDIA_SESSION_STATE_OPENING;
            return ret;
        }

        /* provider opened*/
        provider->get_characteristics(provider, &capability);
        if(capability & MEDIA_PROVIDER_CAN_SEEK)
        {
            self->fgSeekable = KAL_TRUE;
        }
        else
        {
            self->fgSeekable = KAL_FALSE;
        }

        /* Open player */

        ret = media_session_init_player(mpl);
        if (ret < 0)
        {
            if (open_struct->media_mode != MED_MODE_STREAM)
            {
                provider->close(provider);   
                provider->destroy(provider);
                self->provider = NULL;  
            }
        }
        else
        {
            /* Initialize parameter */
                self->force_seek = KAL_TRUE; 

                self->state = MEDIA_SESSION_STATE_OPENED;
                
            if (self->vid_stream_index != MEDIA_SESSION_INVALID_INDEX)
            {
                self->mpl_client->on_event(self->mpl_client, MPL_PLAYER_EVENT_OPEN, MED_S_OK);
            }
            else
            {
                self->mpl_client->on_event(self->mpl_client, MPL_PLAYER_EVENT_OPEN, MED_E_MP4_NO_VIDEO_TRACK);
            }
        }

    }

    return ret;

}


/*****************************************************************************
* FUNCTION
*  media_session_init_stream_seek_param
* DESCRIPTION
*  This function is to init stream seek param
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_init_stream_seek_param(
                            mpl_player_t* mpl, 
                            mpl_player_seek_t* seek_struct,
                            media_time_t *aud_start_time,
                            kal_uint8 *flush_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Streaming don't need to get_frame when seek */
    MSES_ASSERT(!seek_struct->get_frame);
        
    /* Only video streaming can update track in seek */
    self->media_track = seek_struct->seek_track;
    
    *aud_start_time = self->curr_time = seek_struct->time;
    *flush_buffer = KAL_TRUE;
    
    return MED_S_OK;
}


/*****************************************************************************
* FUNCTION
*  media_session_init_seek_param
* DESCRIPTION
*  This function is to init seek param
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_init_seek_param(
                            mpl_player_t* mpl, 
                            mpl_player_seek_t *seek_struct,
                            media_time_t *aud_start_time,
                            kal_uint8 *flush_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);
    media_provider_t *provider = self->provider;
    media_error_t ret;
    media_time_t curr_time, start_time, key_frame_time;
    media_provider_frame_positioning_t *fpc;
    kal_uint32 audio_frame_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(self->media_mode == MED_MODE_STREAM) 
    {
        ASSERT(0);
    }

    /* Get current time */
    curr_time = media_session_get_play_time(mpl);  
    
    /* If seek time is the same as current time. Don't need to seek */
    if (!self->force_seek && curr_time == seek_struct->time)
    {
        #if 0 // need to add player-> pointer, media_player_param_t player_param;
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
/* under construction !*/
        #endif
        return MED_S_FALSE;
    }    

    start_time = self->curr_time = seek_struct->time;

    /* Local playback seek does not need audio frame */
    if (self->aud_stream_index != MEDIA_SESSION_INVALID_INDEX)
    {
        provider->deselect_stream(provider, self->aud_stream_index);
    }

    /* get control for get audio frame start time & video key frame time */
    provider->get_control(
        provider, MEDIA_PROVIDER_CONTROL_FRAME_POSITIONING, (void**)&fpc);

    /* Check if need to flush video frame */
    *flush_buffer = KAL_TRUE;
    if (self->vid_stream_index != MEDIA_SESSION_INVALID_INDEX && 
        !self->force_seek && fpc)
    {
        ret = fpc->get_key_frame_time(
                fpc, 
                self->vid_stream_index, 
                MEDIA_SEARCH_BACKWARD, 
                start_time,
                &key_frame_time);        
        kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_FLUSH_BUFFER_INFO, ret,
            (kal_uint32)key_frame_time, (kal_uint32)curr_time, (kal_uint32) start_time);
        if (ret == MED_S_OK && 
            key_frame_time <= curr_time && curr_time <= start_time)
        {
            *flush_buffer = KAL_FALSE;
        }
    }
    
    if (self->aud_stream_index != MEDIA_SESSION_INVALID_INDEX &&
        start_time <= self->aud_stream.duration)
    {        
        if (fpc)
        {
            ret = fpc->map_time_to_frame(
                fpc, self->aud_stream_index, start_time, &audio_frame_number);
            if (ret < 0)
            {
                start_time = seek_struct->time;
            }
            else
            {
                ret = fpc->map_frame_to_time(
                    fpc, self->aud_stream_index, audio_frame_number, &start_time);
                if (ret < 0)
                {
                    start_time = seek_struct->time;
                }
            }
            kal_trace(TRACE_FUNC, AUD_TRC_MEDIA_SESSION_TIME_TO_FRAME_TO_TIME,
               (kal_uint32)seek_struct->time, audio_frame_number, (kal_uint32)start_time);
        }
    }

    *aud_start_time = start_time;

    media_session_set_seek_video_config(mpl, seek_struct);
    
    return MED_S_OK;    
}

/*****************************************************************************
* FUNCTION
*  media_session_seek
* DESCRIPTION
*  This function is to seek
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_seek(
                            mpl_player_t* mpl, 
                            mpl_player_seek_t* seek_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);
    media_provider_t *provider = self->provider;
    media_player_t *player;
    media_error_t ret;
    media_player_start_params_t start_param = {0};    
    kal_uint32 flag;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_SEEK, self->state, seek_struct->time, seek_struct->seek_track, seek_struct->get_frame, self->fgSeekable);
    if (self->state != MEDIA_SESSION_STATE_OPENED)
    {
        return MED_E_WRONG_STATE;
    }   
        
    /* Initialize parameter */
    self->seek_state = MSES_SEEK_STATE_IDLE;   
    self->retry_count = 0;
    MSES_UNSET_FLAG(MSES_PLAYER_FLAG_IS_RECEIVE_AUDIO_EOS);
    MSES_UNSET_FLAG(MSES_PLAYER_FLAG_IS_PROVIDER_VIDEO_ERROR);
    MSES_UNSET_FLAG(MSES_PLAYER_FLAG_IS_PROVIDER_AUDIO_ERROR);
    MSES_UNSET_FLAG(MSES_PLAYER_FLAG_IS_PROVIDER_STARTED);
    MSES_UNSET_FLAG(MSES_PLAYER_FLAG_IS_AUD_BUFFERED);
    MSES_UNSET_FLAG(MSES_PLAYER_FLAG_IS_VID_BUFFERED);
    
    /* Initialize start param */
    start_param.start_mode = MEDIA_PLAYER_SEEK_MODE;
    start_param.get_frame = seek_struct->get_frame;
    start_param.live_stream = (self->media_mode == MED_MODE_STREAM) ? KAL_TRUE : KAL_FALSE;
    
    /* Video streaming */
    if (self->media_mode == MED_MODE_STREAM)
    {
        ret = media_session_init_stream_seek_param(
                mpl, seek_struct, &start_param.audio_start_time, &start_param.flush_buffer);               
    }
    else
    {
        ret = media_session_init_seek_param(
                mpl, seek_struct, &start_param.audio_start_time, &start_param.flush_buffer);    
    }

    /* Don't need to seek or error happens */
    if (ret == MED_S_FALSE || ret < 0)
    {
        return ret;
    }  

    /* Allocated in init_stream_seek_param() */
    player = self->player;

    /* Initialize parameter */
    self->force_seek = KAL_TRUE;
    
    /* Start player */    
    ret = player->start(player, &start_param);    

    /* ret may be changed as MED_S_ASYNC in the if */
    if (ret == MED_S_OK)
    {   
        if (self->media_mode != MED_MODE_STREAM)
        {
            self->force_seek = KAL_FALSE;

            /* Stop the player to reset player state to PREPARED */
            player->stop(player);            
            self->state = MEDIA_SESSION_STATE_OPENED;
            return MED_S_OK;
        }
        else
        {
            /* video stream seek should wait until buffer_done */
            self->seek_state = MSES_SEEK_STATE_PLAYER_DONE;          
            ret = MED_S_ASYNC;
        }
    }
    
    if (ret == MED_S_ASYNC)
    {
        if (self->media_mode != MED_MODE_STREAM)
        {
            /* Start provider */
            flag = (start_param.flush_buffer) ? 0 : MP_START_VIDEO_RESUME;
            if (self->media_scenario == MPL_PREVIEW)
            {
                flag |= MP_START_ONE_FRAME_ONLY;
                start_param.stop_time = start_param.audio_start_time+10;
                ret = provider->start(provider, &start_param.audio_start_time, &start_param.stop_time, flag);
            }
            else
            {
                ret = provider->start(provider, &start_param.audio_start_time, NULL, flag);
            }
               
            if (ret < 0)
            {
                kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_FAIL, ret, __LINE__);
                /* Stop player */
                player->stop(player);
                if (self->media_mode == MED_MODE_STREAM)
                {
                    player->close(player);
                    player->destroy(player);
                    self->player = NULL;
                }
                return ret;
            }       
        }
        self->state = MEDIA_SESSION_STATE_SEEKING;
        return MED_S_ASYNC;
    }
    else if (ret < 0)
    {
        return ret;
    }

    return MED_S_OK;
}


/*****************************************************************************
* FUNCTION
*  media_session_stop_seek
* DESCRIPTION
*  This function is to stop seek
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_stop_seek(mpl_player_t* mpl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);
    media_provider_t *provider = self->provider;
    media_player_t *player = self->player;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (self->state != MEDIA_SESSION_STATE_SEEKING)
    {
        return MED_E_WRONG_STATE;
    }
    
    player->stop(player);
    if (self->media_mode == MED_MODE_STREAM)
    {
        player->close(player);
        player->destroy(player);
        self->player = NULL;
    }
    else
    {
        /* Destroy player before stop provider */
        provider->stop(provider);
    }
    
    self->force_seek = KAL_TRUE;

    self->state = MEDIA_SESSION_STATE_OPENED;
    return MED_S_OK;
}


/*****************************************************************************
* FUNCTION
*  media_session_get_frame
* DESCRIPTION
*  This function is to get frame
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_get_frame(
                        mpl_player_t* mpl, mpl_player_get_frame_t* frame_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);
    media_player_t *player = self->player;
    media_player_video_config_t video_config = {0};
    media_error_t ret;
    media_player_param_t player_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (self->state != MEDIA_SESSION_STATE_OPENED)
    {
        return MED_E_WRONG_STATE;
    }

    if (self->vid_stream_index == MEDIA_SESSION_INVALID_INDEX)
    {
        return MED_E_FAIL;
    }

    /* Prepare configuration */
    video_config.brightness = self->brightness;
    video_config.contrast = self->contrast;
    video_config.display_width = frame_struct->display_width;
    video_config.display_height = frame_struct->display_height;
    video_config.image_buffer_p = frame_struct->image_buffer_p;
    video_config.image_data_format = frame_struct->image_data_format;
    video_config.idp_rotate = frame_struct->idp_rotate;
    video_config.frame_mode = frame_struct->frame_mode;

    player->set_video_config(player, self->vid_stream_index, &video_config);

    player_param.type = MEDIA_PLAYER_PARAM_TYPE_FRAME;
    ret = player->get_param(player, &player_param);
    return ret;
}


/*****************************************************************************
* FUNCTION
*  media_session_play_internal
* DESCRIPTION
*  This function is to play
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_play_internal(mpl_player_t* mpl, kal_uint32 play_speed, kal_bool close_bt_codec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);
    media_provider_t *provider = self->provider;
    media_player_t *player = self->player;
    media_error_t ret;   
    media_provider_frame_positioning_t *fpc;    
    media_time_t play_time, input_time, key_frame_time = 0, resume_time;
    media_player_param_t player_param;
    kal_uint32 audio_frame_number, flag;
    media_player_start_params_t start_param = {0};
    media_player_param_t param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(self->media_mode == MED_MODE_STREAM) 
    {
        ASSERT(0);
    }

    /* Get audio frame start time */
    provider->get_control(
            provider, MEDIA_PROVIDER_CONTROL_FRAME_POSITIONING, (void**)&fpc);
    
    if (self->aud_stream_index == MEDIA_SESSION_INVALID_INDEX ||
        self->media_track == MED_VID_VISUAL_ONLY ||
        self->media_mode == MED_MODE_STREAM ||
        self->curr_time > self->aud_stream.duration)
    {
        play_time = start_param.audio_start_time = self->curr_time;
    }
    else
    {
        param.type = MEDIA_PLAYER_PARAM_TYPE_PLAY_TIME;
        player->get_param(player, &param);
        play_time = param.val.time;
        
        if (fpc)
        {
            input_time = play_time;
            ret = fpc->map_time_to_frame(
                fpc, self->aud_stream_index, input_time, &audio_frame_number);
            if (ret < 0)
            {
                play_time = param.val.time;
            }
            else
            {
                ret = fpc->map_frame_to_time(
                    fpc, self->aud_stream_index, audio_frame_number, &play_time);
                if (ret < 0)
                {
                    play_time = param.val.time;
                }
            }
            kal_trace(TRACE_FUNC, AUD_TRC_MEDIA_SESSION_TIME_TO_FRAME_TO_TIME,
               (kal_uint32)input_time, audio_frame_number, (kal_uint32)play_time);
        }

        start_param.audio_start_time = play_time;
    }

    if(self->bit_flag & MSES_PLAYER_FLAG_IS_STOP_TIME_SET)
    {
        start_param.stop_time= self->stop_time;
    }
    start_param.play_speed = play_speed;
    start_param.close_bt_codec = close_bt_codec;
    start_param.start_mode = MEDIA_PLAYER_PLAY_MODE;
    start_param.live_stream = (self->media_mode == MED_MODE_STREAM) ? KAL_TRUE : KAL_FALSE;
        
    /* Start player*/
    if (self->force_seek)
    {
        kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_FAIL, MED_E_FAIL, __LINE__);
        return MED_E_FAIL;
    }
    
    ret = player->start(player, &start_param);
    if (ret < 0 || ret == MED_S_TERMINATED)
    {
        if (ret == MED_S_TERMINATED)
        {
            player->stop(player);
        }
        
        if (self->media_mode == MED_MODE_STREAM)
        {           
            player->close(player);
            player->destroy(player);
            self->player = NULL;

            /* Destroy player before stop provider */
            provider->stop(provider);
            
            /* reset state to opened */
            self->state = MEDIA_SESSION_STATE_OPENED;
        }        

        return ret;
    }

    if (self->state == MEDIA_SESSION_STATE_OPENED)
    {
        /* Select stream first */
        if (self->aud_stream_index != MEDIA_SESSION_INVALID_INDEX)        
        {
            /* get buffer status from player: must call after player is started */
            param.type = MEDIA_PLAYER_PARAM_TYPE_NEED_AUD_FRAME;
            player->get_param(player, &param);    
            if (param.val.need_aud_frame)
            {
                provider->select_stream(provider, self->aud_stream_index);
            }
            else
            {
                provider->deselect_stream(provider, self->aud_stream_index);
            }
        }

        /* Check if resume mode or start mode for video track */
        flag = MP_START_VIDEO_RESUME;        
        if (self->vid_stream_index != MEDIA_SESSION_INVALID_INDEX && fpc && self->fgSeekable)
        {
            ret = fpc->get_key_frame_time(
                    fpc, 
                    self->vid_stream_index, 
                    MEDIA_SEARCH_BACKWARD, 
                    play_time,
                    &key_frame_time); 

            /* Get resume_time */
            player_param.type = MEDIA_PLAYER_PARAM_TYPE_MAX_VID_FRAME_TIME;
            player->get_param(player, &player_param);
            resume_time = player_param.val.time;
    
            kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_RESUME_BUFFER_INFO, ret,
                (kal_uint32)resume_time, (kal_uint32)key_frame_time, (kal_uint32) play_time);

            if (ret == MED_S_OK && resume_time < key_frame_time)
            {
                flag = 0;
                /* Flush P, B frame */
                player->jump_to_i_frame(player, key_frame_time);
            }
        }

        /* Start provider */
        ret = provider->start(provider, &play_time, NULL, flag);
        
        if (ret < 0)
        {
            kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_FAIL, ret, __LINE__);
            player->stop(player);
            if (self->media_mode == MED_MODE_STREAM)
            {
                player->close(player);
                player->destroy(player);
                self->player = NULL;
            }
            return ret;
        }       

        self->state = MEDIA_SESSION_STATE_STARTED;  
    }
    else if (self->state == MEDIA_SESSION_STATE_SEEKING)
    {
        self->state = MEDIA_SESSION_STATE_STARTED; 
    }
    return MED_S_OK;
}

/*****************************************************************************
* FUNCTION
*  media_session_play_stream_internal
* DESCRIPTION
*  This function is to play
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_play_stream_internal(mpl_player_t* mpl, kal_uint32 play_speed, kal_bool close_bt_codec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);
    media_player_t *player = self->player;
    media_error_t ret;   
    media_player_start_params_t start_param = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    start_param.audio_start_time = self->curr_time;
    if(self->bit_flag & MSES_PLAYER_FLAG_IS_STOP_TIME_SET)
    {
        start_param.stop_time= self->stop_time;
    }

    start_param.play_speed = play_speed;
    start_param.close_bt_codec = close_bt_codec;
    start_param.start_mode = MEDIA_PLAYER_PLAY_MODE;
    start_param.live_stream = (self->media_mode == MED_MODE_STREAM) ? KAL_TRUE : KAL_FALSE;
        
    /* Start player*/
    if (self->force_seek)
    {
        kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_FAIL, MED_E_FAIL, __LINE__);
        return MED_E_FAIL;
    }
    
    ret = player->start(player, &start_param);
    if (ret < 0 || ret == MED_S_TERMINATED)
    {
        if (ret == MED_S_TERMINATED)
        {
            player->stop(player);
        }
        
        if (self->media_mode == MED_MODE_STREAM)
        {           
            player->close(player);
            player->destroy(player);
            self->player = NULL;

            /* reset state to opened */
            self->state = MEDIA_SESSION_STATE_OPENED;
        }        

        return ret;
    }

    if (self->state == MEDIA_SESSION_STATE_OPENED)
    {
        self->state = MEDIA_SESSION_STATE_STARTED;  
    }
    else if (self->state == MEDIA_SESSION_STATE_SEEKING)
    {
        self->state = MEDIA_SESSION_STATE_STARTED; 
    }
    return MED_S_OK;
}

/*****************************************************************************
* FUNCTION
*  media_session_play
* DESCRIPTION
*  This function is to play
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_play(
                            mpl_player_t* mpl, 
                            mpl_player_play_t* play_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);
    media_player_t *player = self->player;
    
    media_player_audio_config_t audio_config = {0};
    media_error_t ret;   
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_PLAY, self->state);

    if (self->media_scenario == MPL_PREVIEW)
    {
        ASSERT(0);
    }

    if (self->state != MEDIA_SESSION_STATE_OPENED &&
        self->state != MEDIA_SESSION_STATE_SEEKING)
    {
        return MED_E_WRONG_STATE;
    }

    if (self->state == MEDIA_SESSION_STATE_SEEKING)
    {
        if (self->seek_state != MSES_SEEK_STATE_BUFFER_DONE)
        {
            return MED_E_WRONG_STATE;
        }
    }

    /* Error handling: streaming doesn't follow state transition */
    if (player == NULL)
    {
        return MED_E_WRONG_STATE;
    }

    MSES_UNSET_FLAG(MSES_PLAYER_FLAG_IS_PROVIDER_VIDEO_ERROR);
    MSES_UNSET_FLAG(MSES_PLAYER_FLAG_IS_PROVIDER_AUDIO_ERROR);
    /* Set video parameter to player */
    media_session_set_play_video_config(mpl, play_struct);

    /* Set audio parameter to player */    
    audio_config.play_audio = play_struct->play_audio;
    audio_config.audio_path = play_struct->audio_path;

    player->set_audio_config(player, self->aud_stream_index, &audio_config);

    if (self->media_mode == MED_MODE_STREAM )
    {
        ret = media_session_play_stream_internal(mpl, play_struct->play_speed, KAL_FALSE);
    }
    else
    {
        ret = media_session_play_internal(mpl, play_struct->play_speed, KAL_FALSE);
    }
    
    return ret;   
}


/*****************************************************************************
* FUNCTION
*  media_session_stop_play
* DESCRIPTION
*  This function is to stop
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
media_error_t media_session_stop_play(mpl_player_t* mpl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);
    media_provider_t *provider = self->provider;
    media_player_t *player = self->player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (self->state != MEDIA_SESSION_STATE_STARTED)
    {
        return MED_E_WRONG_STATE;
    }    

    if (self->state == MEDIA_SESSION_STATE_STARTED)
    {        
        player->stop(player);
        /* Get current time */
        self->curr_time = media_session_get_play_time(mpl);  
        
        if (self->media_mode == MED_MODE_STREAM)
        {
            player->close(player);
            player->destroy(player);
            self->player = NULL;
        }
        else
        {
            /* Destroy player before stop provider */
            provider->stop(provider);
        }
        
        self->state = MEDIA_SESSION_STATE_OPENED;
    }

    return MED_S_OK;
}


/*****************************************************************************
* FUNCTION
*  media_session_get_buff_percent
* DESCRIPTION
*  This function is to get buffer percent
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_get_buffer_percent(mpl_player_ctrl_dl_t* dl, kal_uint32* percent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(dl, media_session_struct, dl_control);
    media_provider_t *provider = self->provider; 
    media_player_t *player = self->player;
    media_provider_download_t *dl_control;
    media_provider_buf_status_t buf_status;
    media_time_t remain_time, aud_dur, vid_dur, dur, avail_aud, avail_vid, avail_time, need_time, diff;
    media_player_param_t size_param;
    media_player_param_t num_param;
    kal_uint32 size_percent = 0, num_percent = 0, aud_percent = 0, buff_percent;
    kal_uint32 avail_aud_size, aud_ring_size;
    kal_uint32 avail_aud_num, aud_ring_num;
    media_time_t pre_buffer_time;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_GET_BUFFER_PERCENT, (kal_uint32)self->curr_time, self->state);
    if (self->state == MEDIA_SESSION_STATE_OPENING ||
        self->state == MEDIA_SESSION_STATE_CLOSED)
    {
        *percent = 0;
        return MED_E_WRONG_STATE;
    }

    if (self->media_mode == MED_MODE_STREAM && self->fgBuffSupplier == KAL_FALSE)
    {
        ASSERT(0);
    }
    
    provider->get_control(provider, MEDIA_PROVIDER_CONTROL_DOWNLOAD, (void**)&dl_control);
    if (dl_control == NULL)
    {
        *percent = 0;
        return MED_S_OK;
    }   
    
    vid_dur = self->vid_stream.duration;
    aud_dur = self->aud_stream.duration;

    /* Streaming: seek with specific track */
    if (self->media_track == MED_VID_AUDIO_ONLY)
    {
        vid_dur = 0;
    }
    if (self->media_track == MED_VID_VISUAL_ONLY)
    {
        aud_dur = 0;
    }

    dur = (vid_dur > aud_dur) ? vid_dur : aud_dur;
    /* get buffer status from provider */
    dl_control->get_buf_status(dl_control, self->curr_time, &buf_status);  
    kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_PROVIDER_BUFFER_STATUS,
        (kal_uint32)buf_status.avail_dur_a, 
        (kal_uint32)buf_status.avail_dur_v, 
        buf_status.rest_bitstream_size_a,
        buf_status.buf_percentage_a,
        buf_status.buf_percentage_v);

    /* get buffer size from player */
    size_param.type = MEDIA_PLAYER_PARAM_TYPE_AUD_BUFFER_SIZE;
    player->get_param(player, &size_param);    
    kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_PLAYER_AUD_BUFFER_SIZE,
            size_param.val.aud_buffer.size, size_param.val.aud_buffer.ring_size);

    avail_aud = buf_status.avail_dur_a;
    avail_vid = buf_status.avail_dur_v;
    avail_aud_size = size_param.val.aud_buffer.size + buf_status.rest_bitstream_size_a;
    aud_ring_size = size_param.val.aud_buffer.ring_size;
    
    /* get buffer num from player */
    num_param.type = MEDIA_PLAYER_PARAM_TYPE_AUD_BUFFER_NUM;
    player->get_param(player, &num_param);    
    kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_PLAYER_AUD_BUFFER_NUM,
            num_param.val.aud_buffer.size, num_param.val.aud_buffer.ring_size);
    avail_aud_num = num_param.val.aud_buffer.size;
    aud_ring_num = num_param.val.aud_buffer.ring_size;   

    /* get availble time */
    avail_time = media_session_get_avail_time(&self->mpl, avail_aud, avail_vid, aud_dur, vid_dur);

    /* PDL: Finish downloading */
    if (self->media_mode == MED_MODE_PDL_FILE && dur != 0 && avail_time >= dur)
    {
        *percent = 100;
        kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_PERCENT, *percent, __LINE__);
   
        return MED_S_OK;
    }
    
    /* remain time */
    if (avail_time > self->curr_time)
    {
        remain_time = avail_time - self->curr_time;
    }
    else
    {
        remain_time = 0;
    }

    if (self->media_mode == MED_MODE_STREAM)
    {
        pre_buffer_time = STREAM_BUFFER_PRE_DL_LEN;
    }
    else
    {
        pre_buffer_time = MSES_BUFFER_TIME_FOR_PLAY;
    }
    
    /* need time. dur == 0 (live streaming) */    
    if (dur >= self->curr_time && dur != 0)
    {
        diff = dur - self->curr_time;
        need_time = (diff < pre_buffer_time) ? diff : pre_buffer_time;
    }
    else
    {
        need_time = pre_buffer_time;
    }
    
    if (remain_time >= need_time || need_time == 0)
    {
        buff_percent = 100;
    }
    else
    {
        buff_percent = (kal_uint32)(100 * remain_time / need_time);           
    }
    
    /* Buffer percent */
    if (self->media_mode == MED_MODE_STREAM)
    {
        if (buf_status.buf_percentage_a > 50 || buf_status.buf_percentage_v > 50)
        {
            *percent = 100;
        }
        else
        {
            /* max(buf_percentage_a, buf_percentage_v, buff_percent)*/
            *percent = buff_percent;
            if (buf_status.buf_percentage_a > *percent)
            {
                *percent = buf_status.buf_percentage_a;
            }
            if (buf_status.buf_percentage_v > *percent)
            {
                *percent = buf_status.buf_percentage_v;
            }
        }        
    }
    else
    {
        *percent = buff_percent;
    }

    /* Has audio track & want to play audio & audio is still at downloading */    
    if (self->aud_stream_index != MEDIA_SESSION_INVALID_INDEX &&
        self->media_track != MED_VID_VISUAL_ONLY &&
        (aud_dur != 0 && avail_aud < aud_dur))
    {
        /* Streaming: when seek to end, avail_aud_size is 0. */
        if (MSES_IS_FLAG_SET(MSES_PLAYER_FLAG_IS_RECEIVE_AUDIO_EOS))
        {
            /* percent don't need to be bounded by aud_percent */
        }
        else
        {
            size_percent = 100 * avail_aud_size / aud_ring_size;
            num_percent = 100 * avail_aud_num / aud_ring_num;

            aud_percent = (size_percent > num_percent) ? size_percent : num_percent;
            if (aud_percent < *percent)
            {
                *percent = aud_percent;
            }
        }        
    }
    kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_BUFFER_INFO, 
        (kal_uint32)remain_time, 
        (kal_uint32)need_time, 
        buff_percent, 
        size_percent,
        num_percent, 
        MSES_IS_FLAG_SET(MSES_PLAYER_FLAG_IS_RECEIVE_AUDIO_EOS));
    
    if (self->media_mode == MED_MODE_STREAM && *percent == 100)
    {        
        if (self->seek_state != MSES_SEEK_STATE_PLAYER_DONE ||
            !MSES_IS_FLAG_SET(MSES_PLAYER_FLAG_IS_PROVIDER_STARTED))
        {
            *percent = 99;            
        }

        if (*percent == 100)
        {        
            media_session_notify_stream_seek_done(&self->mpl);        
        }
    }
    
    kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_PERCENT, *percent, __LINE__);    
    
    return MED_S_OK;    
}


/*****************************************************************************
* FUNCTION
*  media_session_get_max_time
* DESCRIPTION
*  This function is to get max time
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_get_max_time(mpl_player_ctrl_dl_t* dl, kal_uint64 *max_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(dl, media_session_struct, dl_control);
    media_time_t aud_dur, vid_dur, dur, avail_aud, avail_vid, avail_time;
    media_provider_download_t *dl_control;
    media_provider_buf_status_t buf_status;
    media_provider_t *provider = self->provider; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_GET_MAX_TIME, self->state);

    if (self->state == MEDIA_SESSION_STATE_OPENING ||
        self->state == MEDIA_SESSION_STATE_CLOSED)
    {
        return MED_E_WRONG_STATE;
    }    

    if (self->media_mode == MED_MODE_STREAM && self->fgBuffSupplier == KAL_FALSE)
    {
        ASSERT(0);
    }

    provider->get_control(provider, MEDIA_PROVIDER_CONTROL_DOWNLOAD, (void**)&dl_control);
    if (dl_control == NULL)
    {
        *max_time = 0;
        return MED_S_OK;
    }

    vid_dur = self->vid_stream.duration;
    aud_dur = self->aud_stream.duration;

    /* Streaming: seek with specific track */
    if (self->media_track == MED_VID_AUDIO_ONLY)
    {
        vid_dur = 0;
    }
    if (self->media_track == MED_VID_VISUAL_ONLY)
    {
        aud_dur = 0;
    }
    dur = (vid_dur > aud_dur) ? vid_dur : aud_dur;
   
    /* get buffer status from provider */
    dl_control->get_buf_status(dl_control, self->curr_time, &buf_status); 
    kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_PROVIDER_BUFFER_STATUS,
        (kal_uint32)buf_status.avail_dur_a, 
        (kal_uint32)buf_status.avail_dur_v, 
        buf_status.rest_bitstream_size_a,
        buf_status.buf_percentage_a,
        buf_status.buf_percentage_v);
     
    avail_aud = buf_status.avail_dur_a;
    avail_vid = buf_status.avail_dur_v;

    avail_time = media_session_get_avail_time(&self->mpl, avail_aud, avail_vid, aud_dur, vid_dur);

    /* Assign value */
    *max_time = (avail_time > dur) ? dur : avail_time;
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    return MED_S_OK;
}


/*****************************************************************************
* FUNCTION
*  media_session_pause_visual_update
* DESCRIPTION
*  This function is to pause visual update
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_pause_visual_update(mpl_player_t* mpl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);    
    media_player_t *player = self->player;
    media_error_t ret = MED_E_FAIL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (self->state != MEDIA_SESSION_STATE_STARTED)
    {
        return MED_S_FALSE;
    }

    if (self->vid_stream_index == MEDIA_SESSION_INVALID_INDEX)
    {
        return MED_S_FALSE;
    }
        
    if (player != NULL)
    {
        ret = player->pause_visual_update(player);
    }
    
    return ret;
}


/*****************************************************************************
* FUNCTION
*  media_session_resume_visual_update
* DESCRIPTION
*  This function is to resume visual update
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_resume_visual_update(mpl_player_t* mpl, mpl_player_play_t* play_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);    
    media_player_t *player = self->player;
    media_error_t ret = MED_E_FAIL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    
    if (self->state != MEDIA_SESSION_STATE_STARTED)
    {
        return MED_S_FALSE;
    }

    if (self->vid_stream_index == MEDIA_SESSION_INVALID_INDEX)
    {
        return MED_S_FALSE;
    }    

    /* Set video parameter to player */
    media_session_set_play_video_config(mpl, play_struct);
    
    ret = player->resume_visual_update(player);  
    
    return ret;
}



/*****************************************************************************
* FUNCTION
*  media_session_stop_visual_update
* DESCRIPTION
*  This function is to stop visual update
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_stop_visual_update(mpl_player_t* mpl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);    
    media_provider_t *provider = self->provider;
    media_player_t *player = self->player;
    media_error_t ret = MED_E_FAIL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (self->state != MEDIA_SESSION_STATE_STARTED)
    {
        return MED_E_WRONG_STATE;
    }

    if (self->vid_stream_index == MEDIA_SESSION_INVALID_INDEX)
    {
        return MED_S_FALSE;
    }

    MSES_ASSERT(self->media_track != MED_VID_VISUAL_ONLY);
    self->media_track = MED_VID_AUDIO_ONLY;    
    /* stop_visual_update before deselect provider stream */
    if (player != NULL)
    {
        ret = player->release_visual(player);
    }

    if(self->media_mode != MED_MODE_STREAM) 
    {
        provider->deselect_stream(provider, self->vid_stream_index);
    }    
    
    return ret;
}


/*****************************************************************************
* FUNCTION
*  media_session_get_media_info
* DESCRIPTION
*  This function is to get media information
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_get_media_info(
                            mpl_player_t* mpl, 
                            mpl_player_get_media_info_t *media_info_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);    
    media_player_t *player = self->player; 
    media_player_param_t param;
    media_stream_t *stream_p;
    media_codec_type_t codec_type;
    media_video_info_t *info_ptr;
    media_error_t ret = MED_S_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (self->state == MEDIA_SESSION_STATE_OPENING ||
        self->state == MEDIA_SESSION_STATE_CLOSED)
    {
        return MED_E_WRONG_STATE;
    }

    media_info_struct->track_info = MED_NO_TRACK;
    /* Video information */
    if (self->vid_stream_index != MEDIA_SESSION_INVALID_INDEX)
    {       
        stream_p = &self->vid_stream;        
    
        media_info_struct->vid_duration = stream_p->duration;
        media_info_struct->track_info |= MED_VISUAL_TRACK;

        info_ptr = &(stream_p->info.video);
        /* Update from player */
        if (info_ptr->width == 0 || info_ptr->height == 0)
        {
            if (player != NULL && self->media_track != MED_VID_AUDIO_ONLY)
            {
                /* get buffer status from player */
                param.type = MEDIA_PLAYER_PARAM_TYPE_VIDEO_RESOLUTION;
                player->get_param(player, &param); 
                info_ptr->width = param.val.video_size.width;
                info_ptr->height = param.val.video_size.height;
            }            
        }
        media_info_struct->total_frame_num = info_ptr->frame_count;
        media_info_struct->width = info_ptr->width;
        media_info_struct->height = info_ptr->height;        
    }
    else
    {
        media_info_struct->width = 0;
        media_info_struct->height = 0;
        media_info_struct->total_frame_num = 0;
        media_info_struct->vid_duration = 0;
    }
    /* Audio information */
    if (self->aud_stream_index != MEDIA_SESSION_INVALID_INDEX)
    {
        stream_p = &self->aud_stream;
        
        media_info_struct->audio_channel_num = stream_p->info.audio.channels;
        media_info_struct->audio_sampling_rate = stream_p->info.audio.sample_rate;
        media_info_struct->aud_duration = stream_p->duration; 
        media_info_struct->track_info |= MED_AUDIO_TRACK;

        codec_type = self->aud_stream.dec_config.codec;
        media_info_struct->aud_format = (kal_uint32)mpl_get_media_format_from_codec_type((kal_uint16)codec_type);
    }  
    else
    {
        media_info_struct->audio_channel_num = 0;
        media_info_struct->aud_duration = 0;
        media_info_struct->aud_format = MEDIA_FORMAT_UNKNOWN;
    }
    
    /* Total Duration */
    if (media_info_struct->vid_duration > media_info_struct->aud_duration)
    {
        media_info_struct->duration = media_info_struct->vid_duration;
    }
    else
    {
        media_info_struct->duration = media_info_struct->aud_duration;
    }
    /* FS handle */
    media_info_struct->file_handle = self->fs_handle;
    
    return ret;
}


/*****************************************************************************
* FUNCTION
*  media_session_get_param
* DESCRIPTION
*  This function is to get parameter
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_get_param(
                            mpl_player_t* mpl, mpl_player_param_enum param, void *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);
    media_player_t *player = self->player;
    media_provider_t *provider = self->provider;

    mpl_player_param_time_and_frame_mapping_t *map_param_p;
    media_codec_type_t codec_type;
    media_player_param_t player_param;
    media_provider_frame_positioning_t *fpc;
    media_error_t ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (self->state == MEDIA_SESSION_STATE_OPENING ||
        self->state == MEDIA_SESSION_STATE_CLOSED)
    {
        return MED_E_WRONG_STATE;
    }
    
    if (param == MPL_PARAM_AUD_FORMAT)
    {        
        codec_type = self->aud_stream.dec_config.codec;
        (*(kal_uint16*)value) = mpl_get_media_format_from_codec_type((kal_uint16)codec_type);
    }
    else if (param == MPL_PARAM_FILE_HANDLE)
    {
         (*(kal_uint32*)value) = self->fs_handle;
    }
    else if (param == MPL_PARAM_CURRENT_PLAY_TIME)
    {
        if (self->state == MEDIA_SESSION_STATE_STARTED)
        { 
            (*(kal_uint64*)value) = media_session_get_play_time(mpl);
        }
        else
        {
            (*(kal_uint64*)value) = self->curr_time;
        }
    }
    else if (param == MPL_PARAM_DUMMY_AUD_PLAYING)
    {
        if (player == NULL)
        {
            (*(kal_bool*)value) = KAL_FALSE;
        }
        else
        {
            player_param.type = MEDIA_PLAYER_PARAM_TYPE_DUMMY_AUD_PLAYING;
            player->get_param(player, &player_param);
            (*(kal_bool*)value)  = player_param.val.playing;
        }       
    }
    else if (param == MPL_PARAM_MAX_VID_FRAME_TIME)
    {
        if (player == NULL)
        {
            (*(kal_uint64*)value) = 0;
        }
        else
        {
            player_param.type = MEDIA_PLAYER_PARAM_TYPE_MAX_VID_FRAME_TIME;
            player->get_param(player, &player_param);
            (*(kal_uint64*)value) = player_param.val.time;
        }
    }
    else if (param == MPL_PARAM_AUD_PLAYING)
    {
        if (player == NULL)
        {
            (*(kal_bool*)value) = KAL_FALSE;
        }
        else
        {
            player_param.type = MEDIA_PLAYER_PARAM_TYPE_AUD_PLAYING;
            player->get_param(player, &player_param);
            (*(kal_bool*)value) = player_param.val.playing;
        }
    }
    else if (param == MPL_PARAM_TIME_TO_FRAME)
    {
        map_param_p = (mpl_player_param_time_and_frame_mapping_t*) value;
        provider->get_control(
            provider, MEDIA_PROVIDER_CONTROL_FRAME_POSITIONING, (void**)&fpc);
        if (!fpc || self->vid_stream_index == MEDIA_SESSION_INVALID_INDEX)
        {
            return MED_E_FAIL;
        }        
        ret = fpc->map_time_to_frame(
            fpc, self->vid_stream_index, map_param_p->time, &map_param_p->frame);
        if (ret < 0)
        {
            return MED_E_FAIL;
        }
    }
    else if (param == MPL_PARAM_FRAME_TO_TIME)
    {
        map_param_p = (mpl_player_param_time_and_frame_mapping_t*) value;
        provider->get_control(
            provider, MEDIA_PROVIDER_CONTROL_FRAME_POSITIONING, (void**)&fpc);
        if (!fpc || self->vid_stream_index == MEDIA_SESSION_INVALID_INDEX)
        {
            return MED_E_FAIL;
        }
        ret = fpc->map_frame_to_time(
            fpc, self->vid_stream_index, map_param_p->frame, &map_param_p->time);
        if (ret < 0)
        {
            return MED_E_FAIL;           
        }
    }
    else if (param == MPL_PARAM_IS_SEEKABLE)
    {
        (*(kal_bool*)value) = self->fgSeekable;
    }
    return MED_S_OK;
}


/*****************************************************************************
* FUNCTION
*  media_session_set_param
* DESCRIPTION
*  This function is to set parameter
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_set_param(
                            mpl_player_t* mpl, mpl_player_param_enum param, void *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);
    media_player_t *player = self->player;
    media_player_param_t set_param;
    mpl_player_param_sleep_time_t *time_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param == MPL_PARAM_AUD_VOLUME)
    {   
        if (self->state == MEDIA_SESSION_STATE_OPENING ||
            self->state == MEDIA_SESSION_STATE_CLOSED)
        {
            return MED_E_WRONG_STATE;
        }
        
        if(self->player != NULL)
        {
            set_param.type = MEDIA_PLAYER_PARAM_TYPE_VOLUME;
            set_param.val.volume = (*(kal_uint8*) value);
            player->set_param(player, &set_param); 
        }
        else
        {            
            self->aud_volume = (*(kal_uint8*) value);
        }
        self->bit_flag |= MSES_PLAYER_FLAG_IS_AUD_VOLUME_SET;
    }
    else if (param == MPL_PARAM_STOP_TIME)
    {
        if(self->player != NULL)
        {
            set_param.type = MEDIA_PLAYER_PARAM_TYPE_STOP_TIME;
            set_param.val.time = (*(kal_uint64*)value);
            player->set_param(player, &set_param);  
        }
        self->stop_time = (*(kal_uint64*)value);
        self->bit_flag |= MSES_PLAYER_FLAG_IS_STOP_TIME_SET;
    }
    else if (param == MPL_PARAM_SLEEP_TIME)
    {
        if(self->player != NULL)
        {
            set_param.type = MEDIA_PLAYER_PARAM_TYPE_SLEEP_TIME;
            time_ptr = (mpl_player_param_sleep_time_t*) param;
            set_param.val.sleep_time.elapse_ticks = time_ptr->elapse_ticks;
            set_param.val.sleep_time.sleep_ticks = time_ptr->sleep_ticks;
            player->set_param(player, &set_param);  
        }
           
        time_ptr = (mpl_player_param_sleep_time_t*) param;
        self->elapse_ticks = time_ptr->elapse_ticks;
        self->sleep_ticks = time_ptr->sleep_ticks;
        self->bit_flag |= MSES_PLAYER_FLAG_IS_SLEEP_TIME_SET;
    }
    else if (param == MPL_PARAM_BRIGHTNESS)
    {        
        if(self->player != NULL)
        {
            set_param.type = MEDIA_PLAYER_PARAM_TYPE_BRIGHTNESS;
            set_param.val.brightness = (*(kal_uint8*) value);
            player->set_param(player, &set_param);  
        }
        self->brightness = (*(kal_uint8*)value);              
    }
    else if (param == MPL_PARAM_CONTRAST)
    {
        if(self->player != NULL)
        {
            set_param.type = MEDIA_PLAYER_PARAM_TYPE_CONTRAST;
            set_param.val.contrast =  (*(kal_uint8*)value);  
            player->set_param(player, &set_param);  
        }
        self->contrast = (*(kal_uint8*)value);                 
    }
    else if (param == MPL_PARAM_AUD_TIME_DIFF)
    {
        if(self->player != NULL)
        {
            set_param.type = MEDIA_PLAYER_PARAM_TYPE_AUD_TIME_DIFF;
            set_param.val.aud_time_diff = (*(kal_uint32*)value);  
            player->set_param(player, &set_param);  
        }
    }
    else if (param == MPL_PARAM_DISPLAY)
    {
        /* I don't understand why should support it. 
           I think AP should set the parameter in play() */
        ASSERT(0);
    }
    return MED_S_OK;
}


/*****************************************************************************
* FUNCTION
*  media_session_get_meta
* DESCRIPTION
*  This function is to get meta info
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_get_meta(mpl_player_t* mpl, mpl_player_get_meta_t *meta_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);
    media_provider_t *provider = self->provider;
    media_provider_metadata_t *mdc;
    const kal_wchar *string_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(self->media_mode == MED_MODE_STREAM) 
    {
        // TODO:
        ASSERT(0);
    }

    if (self->state == MEDIA_SESSION_STATE_OPENING ||
        self->state == MEDIA_SESSION_STATE_CLOSED)
    {
        return MED_E_WRONG_STATE;
    }
    
    provider->get_control(
                provider, MEDIA_PROVIDER_CONTROL_METADATA, (void**)&mdc);

    if (mdc == NULL)
    {
        return MED_E_FAIL;
    }
    /* Author */
    string_ptr = mdc->get_string(mdc, METADATA_ITEM_AUTHOR);
    if (string_ptr != NULL)
    {
        kal_wstrncpy(meta_struct->title_desc_ptr, string_ptr, meta_struct->title_desc_len);
    }
    /* Artist */
    string_ptr = mdc->get_string(mdc, METADATA_ITEM_ARTIST);
    if (string_ptr != NULL)
    {
        kal_wstrncpy(meta_struct->artist_desc_ptr, string_ptr, meta_struct->artist_desc_len);
    }
    /* Title */
    string_ptr = mdc->get_string(mdc, METADATA_ITEM_TITLE);
    if (string_ptr != NULL)
    {
        kal_wstrncpy(meta_struct->title_desc_ptr, string_ptr, meta_struct->title_desc_len);
    }
    /* Album */
    string_ptr = mdc->get_string(mdc, METADATA_ITEM_ALBUM);
    if (string_ptr != NULL)
    {
        kal_wstrncpy(meta_struct->album_desc_ptr, string_ptr, meta_struct->album_desc_len);
    }
    /* Copyright */
    string_ptr = mdc->get_string(mdc, METADATA_ITEM_COPYRIGHT);
    if (string_ptr != NULL)
    {
        kal_wstrncpy(meta_struct->copyright_desc_ptr, string_ptr, meta_struct->copyright_desc_len);
    }
    /* Data */
    string_ptr = mdc->get_string(mdc, METADATA_ITEM_DATE);
    if (string_ptr != NULL)
    {
        kal_wstrncpy(meta_struct->date_desc_ptr, string_ptr, meta_struct->date_desc_len);
    }
    return MED_S_OK;
}


/*****************************************************************************
* FUNCTION
*  media_session_get_control
* DESCRIPTION
*  This function is to get control
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_get_control(
                            mpl_player_t* mpl, 
                            mpl_player_control_t control_id, 
                            void** control)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *control = NULL; 

    switch (control_id)
    {
    #if defined(__VE_PGDL_SUPPORT__) || defined(__VE_STREAM_SUPPORT__)
        case PLAYER_CONTROL_DL:
            *control = &self->dl_control;
            return MED_S_OK;
            break;
    #endif /* __VE_PGDL_SUPPORT__ || __VE_STREAM_SUPPORT__ */
        default:
            break;
    }    
    return MED_E_FAIL;    
}


/*****************************************************************************
* FUNCTION
*  media_session_close
* DESCRIPTION
*  This function is to stop
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_close(mpl_player_t* mpl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_CLOSE, self->state);

    /* For streaming: seek done, and then close directly */
    if (self->state == MEDIA_SESSION_STATE_SEEKING)
    {
        media_session_stop_seek(mpl);
    }
    
    if (self->state != MEDIA_SESSION_STATE_OPENED &&
        self->state != MEDIA_SESSION_STATE_OPENING)
    {
        return MED_E_WRONG_STATE;
    }   
    
    if (self->state != MEDIA_SESSION_STATE_OPENING &&
        self->media_mode != MED_MODE_STREAM)
    {
        /* Close and destroy player */
        self->player->close(self->player);
        self->player->destroy(self->player);
        self->player = NULL;  
    }
    else
    {
        MSES_ASSERT(self->player == NULL);
    }

    if (self->media_mode != MED_MODE_STREAM)
    {
        /* Close provider */
        self->provider->close(self->provider);    
        self->provider->destroy(self->provider);
        self->provider = NULL;
    }

    self->state = MEDIA_SESSION_STATE_CLOSED;

    return MED_S_OK;
}


/*****************************************************************************
* FUNCTION
*  media_session_destroy
* DESCRIPTION
*  This function is to destroy media session
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static void media_session_destroy(mpl_player_t* mpl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* For Debug Use */
    media_session_set_global_context(mpl, KAL_FALSE); 

    MSES_ASSERT(self->state == MEDIA_SESSION_STATE_CLOSED);
    mpl_player_free_ext_mem(self->mpl_client, (void**)&self, MED_MEM_NONCACHE);
}

/*****************************************************************************
* FUNCTION
*  media_session_live_add_video_stream
* DESCRIPTION
*  This function is to add video stream to session
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_live_add_video_stream(mpl_player_t* mpl, media_stream_t* prStream, kal_uint32* pu4Stream_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Add stream */
    self->vid_stream = *prStream;
    self->vid_stream_index = *pu4Stream_index;
    
    return MED_S_OK;
}

/*****************************************************************************
* FUNCTION
*  media_session_live_add_audio_stream
* DESCRIPTION
*  This function is to add audio stream to session
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_live_add_audio_stream(mpl_player_t* mpl, media_stream_t* prStream, kal_uint32* pu4Stream_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Add stream */
    self->aud_stream = *prStream;
    self->aud_stream_index = *pu4Stream_index;
    return MED_S_OK;
}

/*****************************************************************************
* FUNCTION
*  media_session_live_prepare
* DESCRIPTION
*  This function is to prepare play
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_live_prepare(mpl_player_t* mpl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);
    media_error_t ret;  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (self->media_mode == MED_MODE_STREAM)
    {
        /* Open player */
        ret = media_session_init_player(mpl);
        if (ret < 0)
        {
            return MED_E_FAIL;
        }
        else
        {
            /* Initialize parameter */
            self->force_seek = KAL_TRUE; 

            self->state = MEDIA_SESSION_STATE_OPENED;
        }
    }
    else
    {
        ASSERT(0);
    }
    
    return MED_S_OK;
}

/*****************************************************************************
* FUNCTION
*  media_session_live_deliver
* DESCRIPTION
*  This function is to push a media data into session
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_live_deliver(mpl_player_t* mpl, kal_uint32 stream_index, media_data_t* media_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);
    media_player_t *player = self->player;
    media_error_t ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = player->deliver(player, stream_index, media_data);
    //MSES_ASSERT(ret >= 0);

    return ret;
}

/*****************************************************************************
* FUNCTION
*  media_session_live_notify_eos
* DESCRIPTION
*  This function is to notify end of stream
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_live_notify_eos(mpl_player_t* mpl, kal_uint32 stream_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct *self = SELF(mpl, media_session_struct, mpl);
    media_player_t *player = self->player;
    media_error_t ret = MED_S_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Notify player eos coming */
    if (stream_index == self->vid_stream_index)
    {
        ret = player->notify_eos(player, self->vid_stream_index);
    }
    else if (stream_index == self->aud_stream_index)
    {
        ret = player->notify_eos(player, self->aud_stream_index);
    }
    //MSES_ASSERT(ret >= 0);
    
    return ret;
}

/*****************************************************************************
* FUNCTION
*  media_session_get_default
* DESCRIPTION
*  This function is to get default value of parameter
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
static media_error_t media_session_get_default(mpl_player_t* mpl, mpl_player_param_type_enum param_id, void* default_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    //media_session_struct *self = SELF(mpl, media_session_struct, mpl);
    media_error_t ret = MED_S_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (param_id)
    {
        case MPL_OPEN_PARAM:
            kal_mem_set((mpl_player_open_t*)default_param, 0, sizeof(mpl_player_open_t));
            break;
        case MPL_SEEK_PARAM:
            kal_mem_set((mpl_player_seek_t*)default_param, 0, sizeof(mpl_player_seek_t));
            break;
        case MPL_GET_FRAME_PARAM:
            kal_mem_set((mpl_player_get_frame_t*)default_param, 0, sizeof(mpl_player_get_frame_t));
            break;
        case MPL_PLAY_PARAM:
            kal_mem_set((mpl_player_play_t*)default_param, 0, sizeof(mpl_player_play_t));
            break; 
        default:
            MSES_ASSERT(0);
            break;
    }
    
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  query_mpl_capability
 * DESCRIPTION
 *  The function is to construct media session
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
media_error_t* query_mpl_player_capability(mpl_player_capability_t* capability)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    //kal_trace(TRACE_FUNC, VID_TRC_MEDIA_SESSION_CONSTRUCT, g_media_session_mem.ref_count);

    capability->b_IsBitstreamMemInternal = KAL_FALSE;

    return MED_S_OK;
}

/*****************************************************************************
 * FUNCTION
 *  construct_media_session
 * DESCRIPTION
 *  The function is to construct media session
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mpl_player_t* construct_media_session(mpl_player_client_t* client)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    media_session_struct* ms;
    mpl_player_capability_t capability;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    
    ms = (media_session_struct*)mpl_player_alloc_ext_mem(client, sizeof(media_session_struct), MED_MEM_NONCACHE);
    if (!ms)
    {
        return NULL;
    }

    /* Initialize parameter */
    kal_mem_set(ms, 0, sizeof(media_session_struct));
    ms->vid_stream_index = MEDIA_SESSION_INVALID_INDEX;
    ms->aud_stream_index = MEDIA_SESSION_INVALID_INDEX;

    // TODO: need to have a compile option?
    query_mpl_player_capability(&capability);
    ms->fgBuffSupplier = capability.b_IsBitstreamMemInternal;

    ms->mpl_client = client;
    
    /* Assign exported function */
    ms->mpl.open = media_session_open;
    ms->mpl.play = media_session_play;
    ms->mpl.stop_play = media_session_stop_play;
    ms->mpl.seek = media_session_seek;
    ms->mpl.stop_seek = media_session_stop_seek;
    ms->mpl.get_frame = media_session_get_frame;
    ms->mpl.get_param = media_session_get_param;
    ms->mpl.set_param = media_session_set_param;
    ms->mpl.get_meta = media_session_get_meta;
    ms->mpl.get_media_info = media_session_get_media_info;    
    ms->mpl.get_control = media_session_get_control;
    ms->mpl.pause_visual_update = media_session_pause_visual_update;
    ms->mpl.resume_visual_update = media_session_resume_visual_update;
    ms->mpl.release_visual = media_session_stop_visual_update;
    ms->mpl.add_video_stream = media_session_live_add_video_stream;
    ms->mpl.add_audio_stream = media_session_live_add_audio_stream;
    ms->mpl.prepare = media_session_live_prepare;
    ms->mpl.deliver = media_session_live_deliver;
    ms->mpl.notify_eos = media_session_live_notify_eos;
    ms->mpl.close = media_session_close;
    ms->mpl.get_default = media_session_get_default;
    ms->mpl.destroy = media_session_destroy;

    /* Assign pdl control */
#if defined(__VE_PGDL_SUPPORT__) || defined(__VE_STREAM_SUPPORT__)
    ms->dl_control.get_percent = media_session_get_buffer_percent;
    ms->dl_control.get_max_time = media_session_get_max_time;
#endif /* defined(__VE_PGDL_SUPPORT__) || defined(__VE_STREAM_SUPPORT__) */

    /* Assign provider client */
    ms->provider_client.mem_alloc_func = media_session_provider_alloc_mem;
    ms->provider_client.mem_free_func  = media_session_provider_free_mem;
    ms->provider_client.on_stream_found = media_session_provider_on_stream_found;
    ms->provider_client.on_media_data = media_session_provider_on_media_data;
    ms->provider_client.on_event = media_session_provider_on_event;

    /* Assign player client */
    ms->player_client.mem_alloc_func = media_session_player_alloc_mem;
    ms->player_client.mem_free_func  = media_session_player_free_mem;
    ms->player_client.on_event = media_session_player_on_event;

    ms->state = MEDIA_SESSION_STATE_CLOSED;

    /* For Debug Use */
    media_session_set_global_context(&ms->mpl, KAL_TRUE);    
    
    return &ms->mpl;
}
#endif /* defined (__VIDEO_ARCHI_V2__) */

