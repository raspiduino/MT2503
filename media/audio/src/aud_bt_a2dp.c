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
 * aud_bt_a2dp.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes BT A2DP service functions
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =========*/
//#include "kal_release.h"
#include "kal_trace.h"
//#include "stack_common.h"
//#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
//#include "syscomp_config.h"
//#include "task_config.h"        /* Task creation */
//#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
//#include "event_shed.h" /* Event scheduler */
//#include "stack_timer.h"        /* Stack timer */

/* global includes */
#include "l1audio.h"
#include "device.h"
//#include "resource_audio.h"
//#include "fat_fs.h"
//#include "nvram_enums.h"
//#include "nvram_struct.h"
//#include "nvram_user_defs.h"
//#include "nvram_data_items.h"
//#include "custom_nvram_editor_data_item.h"
#include "custom_equipment.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
//#include "med_api.h"
#include "med_context.h"
//#include "med_main.h"
#include "aud_main.h"
#include "med_utility.h"
#include "aud_player.h"

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "bluetooth_a2dp_struct.h"
#include "stack_msgs.h"
#include "stack_config.h"
//#include "kal_active_module.h"
#include "string.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#if defined (__MED_BT_A2DP_MOD__) && defined (__BTMTK__)
//#include "bt_a2dp_struct.h"
#include "bt_a2dp.h"

#define SBC_ENCODE_MEM_SIZE (16*1024)
#define MP3_ENCODE_MEM_SIZE (4*1024)

static kal_bool mute_phone;
static kal_uint8 stream_handle;
static kal_bool need_open_codec;
static A2DP_codec_struct *codec;
static kal_uint32 codec_seq_no = 0;
static bt_a2dp_audio_cap_struct audio_config;
static kal_uint8* codec_buf = NULL;
static volatile kal_mutexid codec_mutex;

#ifdef __BT_SPEAKER_SUPPORT__
typedef enum
{
    A2DP_SINK_CODEC_STATE_IDLE,
	A2DP_SINK_CODEC_STATE_OPEN,
    A2DP_SINK_CODEC_STATE_PLAY,
    
    A2DP_SINK_CODEC_STATE_TOTAL
} a2dp_sink_codec_state_enum;

static MHdl *a2dp_sink_handle;
a2dp_sink_codec_state_enum a2dp_sink_state;
#endif

extern aud_context_struct *aud_context_p;
extern kal_uint8 current_playing_melody_volume_level;
#if defined(TV_OUT_SUPPORT)
extern kal_bool audio_tv_cable_in;
extern kal_bool audio_tv_loud_speaker;
#endif

A2DP_codec_struct* aud_bt_a2dp_get_codec(void)
{
    return codec;
}

void aud_bt_a2dp_lock_codec(void)
{
    kal_take_mutex(codec_mutex);
}

void aud_bt_a2dp_unlock_codec(void)
{
    kal_give_mutex(codec_mutex);
}

/*****************************************************************************
 * FUNCTION
 *  aud_bt_a2dp_is_codec_opened
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool aud_bt_a2dp_is_codec_opened(void)
{
    return (kal_bool)(codec!=NULL);
}

/*****************************************************************************
 * FUNCTION
 *  aud_bt_a2dp_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_a2dp_init(void)
{
    codec = NULL;
    need_open_codec = KAL_FALSE;
    mute_phone = KAL_FALSE;
    codec_mutex = kal_create_mutex("a2dp_codec_mutex");
	#ifdef __BT_SPEAKER_SUPPORT__
	a2dp_sink_handle = NULL;
	a2dp_sink_state = A2DP_SINK_CODEC_STATE_IDLE;
	#endif
}

/*****************************************************************************
 * FUNCTION
 *  aud_bt_a2dp_is_mute_phone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool aud_bt_a2dp_is_mute_phone(void)
{
    return mute_phone;
}

/*****************************************************************************
 * FUNCTION
 *  aud_bt_a2dp_is_media_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_bt_a2dp_is_media_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_present = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_STATE_TRACE(aud_context_p->state);

    if (aud_context_p->state == AUD_MEDIA_PLAY || 
        aud_context_p->state == AUD_MEDIA_PLAY_PAUSED 
        #if defined( __MED_MMA_MOD__)&&(!defined (__MED_SLIM_MMA__))
        	||aud_mma_is_playing(AUD_MMA_CHECK_MODE_SINGLE)
        #endif
        )
    {
        is_present = KAL_TRUE;
    }
    
    return is_present;
}

/*****************************************************************************
 * FUNCTION
 *  aud_bt_a2dp_set_mute_phone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  on      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_a2dp_set_mute_phone(kal_bool on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 output_device;
    kal_uint8 audio_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (on)
    {
        if (!mute_phone)
        {
            aud_melody_set_output_device(0);
        #ifdef __MED_FMR_MOD__
            aud_fmr_set_output_device(0);
        #endif

        }
    }
    else
    {
        if (mute_phone)
        {
            switch (aud_context_p->audio_mode)
            {
                case AUD_MODE_NORMAL:
                case AUD_MODE_LOUDSPK:
            #ifdef TV_OUT_SUPPORT
                    if (audio_tv_cable_in)
                    {
                        if(audio_tv_loud_speaker ||
                           (aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH))
                        {
                            output_device = AUDIO_DEVICE_SPEAKER_BOTH;
                        }
                        else
                        {
                            output_device = AUDIO_DEVICE_SPEAKER2;
                        }
                    }
                    else
            #endif /* TV_OUT_SUPPORT */
                    {
                        output_device = AUDIO_DEVICE_LOUDSPEAKER;
                    }
                    break;
                case AUD_MODE_HEADSET:
                    output_device = aud_context_p->melody_output_device;
                    break;
                default:
                    output_device = 0;
                    ASSERT(0);
            }

            aud_melody_set_output_device(custom_cfg_hw_aud_output_path(output_device));
        #ifdef __MED_FMR_MOD__
            aud_fmr_set_output_device(custom_cfg_hw_aud_output_path(output_device));
        #endif

        #ifndef __GAIN_TABLE_SUPPORT__
            /*if (aud_bt_a2dp_is_media_present())*/
            {
                /* it is not redundant code becoz aud_set_meldoy_volume will check 
                  media_output_on */
                mute_phone = on;

            #ifdef TV_OUT_SUPPORT
                /* TV out is on, and audio output to TV only */
                if (audio_tv_cable_in && !audio_tv_loud_speaker)
                {
                    audio_mode = VOL_TV_OUT;
                }
                else
            #endif /* TV_OUT_SUPPORT */
                if (aud_context_p->audio_mode == AUD_MODE_HEADSET &&
                    aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
                {
                    audio_mode = VOL_NORMAL;
                }
                else
                {
                    audio_mode = aud_context_p->audio_mode;
                }

                if(!aud_context_p->audio_mute 
                #ifdef __ATV_SUPPORT__
                   && !aud_atv_is_mute()
                #endif
                )
                {
                    aud_melody_set_volume_by_mode(audio_mode, current_playing_melody_volume_level);
                }
            }
        #endif /* __GAIN_TABLE_SUPPORT__ */
        }
    }

    mute_phone = on;
}

/*****************************************************************************
 * FUNCTION
 *  aud_bt_a2dp_stream_qos_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_a2dp_stream_qos_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_a2dp_stream_qos_ind_struct *msg_p = (bt_a2dp_stream_qos_ind_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (codec != NULL)
    {
        codec->AdjustBitRateFromQos(msg_p->qos);
    }
}

/*****************************************************************************
 * FUNCTION
 *  _send_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_id              [IN]        
 *  dst_id              [IN]        
 *  sap_id              [IN]        
 *  msg_id              [IN]        
 *  local_param_ptr     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void _send_msg(module_type src_id, module_type dst_id, U16 sap_id, U16 msg_id, void *local_param_ptr)
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
    ilm_ptr->sap_id = (sap_type)sap_id;
    ilm_ptr->msg_id = (msg_type) msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_ptr);
}

#define _send_msg_to_bt(src_id, msg_id, local_param_ptr) _send_msg( (src_id), MOD_BT, BT_A2DP_SAP, (msg_id), (local_param_ptr) )


/*****************************************************************************
 * FUNCTION
 *  bt_a2dp_send_stream_data_send_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  stream_handle       [IN]        
 *  codec               [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void bt_a2dp_send_stream_data_send_req(module_type src_mod_id, U8 stream_handle, A2DP_codec_struct *codec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_a2dp_stream_data_send_req_struct *msg_p = (bt_a2dp_stream_data_send_req_struct*)
        construct_local_para(sizeof(bt_a2dp_stream_data_send_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->stream_handle = stream_handle;
    /* memcpy( &msg_p->codec, codec, sizeof(A2DP_codec_struct) ); YS fixed */
    msg_p->codec = (void*)codec;

    _send_msg_to_bt(src_mod_id, (U16) MSG_ID_BT_A2DP_STREAM_DATA_SEND_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_a2dp_codec_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event       [IN]        
 *  param       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_a2dp_codec_callback(A2DP_Event event, void *param)
{
    A2DP_codec_struct* codec_p = (A2DP_codec_struct*)param;
    module_type src_mod_id;
    
    if(kal_if_hisr() != KAL_FALSE)
        src_mod_id = MOD_L1SPHISR;
    else
        src_mod_id = stack_get_active_module_id();
    bt_a2dp_send_stream_data_send_req(src_mod_id, stream_handle, codec_p);
}

/*****************************************************************************
 * FUNCTION
 *  aud_bt_a2dp_open_codec
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_format    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_a2dp_open_codec(kal_int32 audio_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MHdl* mhdl_handle_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!need_open_codec)
        return;

    AUD_BT_A2DP_FUNC_ENTRY(AUD_BT_A2DP_OPEN_CODEC)

    ASSERT(codec == NULL);

    switch (audio_config.codec_type)
    {
        case BT_A2DP_SBC:
        	  // stop tone first to avoid memory fragment
        	  DTMF_MCU_StopAndWait();
            KT_StopAndWait();
            TONE_StopAndWait();
            
            codec_buf = med_alloc_aud_mem(sizeof(kal_uint8) * SBC_ENCODE_MEM_SIZE);

            if (codec_buf)
            {
                codec = SBC_Open((Media_Format)audio_format,
                    aud_bt_a2dp_codec_callback,
                    &audio_config.codec_cap.sbc,
                    codec_buf,
                    SBC_ENCODE_MEM_SIZE);
            }
            break;
    #if defined(DAF_DECODE) && !defined(__LOW_COST_SUPPORT_COMMON__)
        case BT_A2DP_MP3:
            if (aud_context_p->player_p)
            {
                aud_context_p->player_p->get(aud_context_p->player_p,
                                             AUD_PLAYER_GET_MHDL_HANDLE,
                                             &mhdl_handle_p);
            }

            codec_buf = med_alloc_aud_mem(sizeof(kal_uint8) * MP3_ENCODE_MEM_SIZE);

            if (codec_buf)
            {
                codec = A2DP_DAF_Open(mhdl_handle_p,
                    aud_bt_a2dp_codec_callback,
                    &audio_config.codec_cap.mp3,
                    codec_buf,
                    MP3_ENCODE_MEM_SIZE);
            }
            break;
    #endif
        default:
            ASSERT(0);
    }
    need_open_codec = KAL_FALSE;

    aud_bt_a2dp_set_mute_phone(KAL_TRUE);

#ifdef __GAIN_TABLE_SUPPORT__
    /* Notify MMI that A2DP is connected */
    aud_send_state_change_ind(AUD_STATE_CHANGE_A2DP_CONNECT, NULL);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  aud_bt_a2dp_close_codec
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_a2dp_close_codec(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MHdl* mhdl_handle_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (codec == NULL)
        return;

    AUD_BT_A2DP_FUNC_ENTRY(AUD_BT_A2DP_CLOSE_CODEC);
    
    aud_bt_a2dp_lock_codec();

    switch (audio_config.codec_type)
    {
        case BT_A2DP_SBC:
            SBC_Close();
            break;
    #if defined(DAF_DECODE) && !defined(__LOW_COST_SUPPORT_COMMON__)
        case BT_A2DP_MP3:
            if (aud_context_p->player_p)
            {
                aud_context_p->player_p->get(aud_context_p->player_p,
                                             AUD_PLAYER_GET_MHDL_HANDLE,
                                             &mhdl_handle_p);
            }
            
            A2DP_DAF_Close(mhdl_handle_p);
            break;
    #endif
        default:
            ASSERT(0);
    }
    codec = NULL;

    /* Remember to free codec buffer */
    if (codec_buf)
    {
        med_free_aud_mem((void **)&codec_buf);
    }

    aud_bt_a2dp_unlock_codec();

    aud_bt_a2dp_set_mute_phone(KAL_FALSE);

#ifdef __GAIN_TABLE_SUPPORT__
    /* Notify MMI that A2DP is disconnected */
    aud_send_state_change_ind(AUD_STATE_CHANGE_A2DP_DISCONNECT, NULL);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  aud_bt_a2dp_close_codec_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_a2dp_close_codec_ind(void)
{
    if (codec != NULL)
    {
        aud_bt_a2dp_close_codec();
    }

    if (need_open_codec)
    {
        aud_send_bt_close_codec_ind(MOD_MMI, stream_handle, codec_seq_no);
        need_open_codec = KAL_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  aud_bt_a2dp_close_codec_for_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_a2dp_close_codec_for_open(void)
{
    if (codec != NULL)
    {
        aud_bt_a2dp_close_codec();
        need_open_codec = KAL_TRUE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  aud_bt_a2dp_open_codec_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_a2dp_open_codec_req_hdlr(ilm_struct *ilm_ptr)
{
    media_bt_open_codec_req_struct *msg_p = (media_bt_open_codec_req_struct*)ilm_ptr->local_para_ptr;

    stream_handle = msg_p->stream_handle;
    memcpy(&audio_config, &msg_p->cfg, sizeof(bt_a2dp_audio_cap_struct));
    need_open_codec = KAL_TRUE;
    codec_seq_no = msg_p->seq_no;

    if (msg_p->immediate)
    {
        if(Media_IsPlaybackOn())
        {
            aud_bt_a2dp_open_codec(MEDIA_FORMAT_NONE);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  aud_bt_a2dp_close_codec_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_a2dp_close_codec_req_hdlr(ilm_struct *ilm_ptr)
{
    if (codec != NULL)
    {
        aud_bt_a2dp_close_codec();
    }
    need_open_codec = KAL_FALSE;
}

#ifdef __BT_SPEAKER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  aud_bt_get_a2dp_sink_codec
 *
 * DESCRIPTION
 *  For BT Driver to get the audio driver handle to write A2DP data into ringbuf
 *
 * PARAMETERS
 * void
 *
 * RETURNS
 *  audio driver handle
 *****************************************************************************/
MHdl *aud_bt_get_a2dp_sink_codec(void)
{
  return a2dp_sink_handle;
}

/*****************************************************************************
 * FUNCTION
 *  aud_bt_a2dp_sink_codec_event_hdlr
 * DESCRIPTION
 *  This function is used to handle the callback events from L1Audio.
 * PARAMETERS
 *  data_p             [IN]       Media event data.
 *  date_len           [IN]       The length of data.
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_bt_a2dp_sink_codec_event_hdlr(void* data_p, kal_uint16 date_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Event* media_event_p = (Media_Event*)data_p;
	Media_Event                   event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	AUD_BT_A2DP_FUNC_TRACE1(AUD_BT_A2DP_SINK_CODEC_EVENT_HDLR,a2dp_sink_state);

	if((a2dp_sink_state == A2DP_SINK_CODEC_STATE_PLAY)&&(a2dp_sink_handle != NULL))
    {
        event = a2dp_sink_handle->Process(a2dp_sink_handle,(Media_Event)*media_event_p);
		    /* Post processing */
	    switch (event)
	    {
	        case MEDIA_NONE:
			case MEDIA_DATA_REQUEST:
			case MEDIA_BUFFER_UNDERFLOW:
	            /* Do nothing */
	            break;
	        default:
	            /* Notify MMI related Events */
	            aud_send_bt_sink_codec_ind(MOD_MMI,stream_handle,event);
	            break;
	    }
	}
}


/*****************************************************************************
 * FUNCTION
 *  aud_bt_a2dp_sink_codec_callback
 * DESCRIPTION
 *  This function is used to send L1Audio events to MED.
 * PARAMETERS
 *  handle_p       [IN]        MHdl handle. 
 *  event          [IN]        Play event.
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_bt_a2dp_sink_codec_callback(MHdl *handle_p, Media_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    aud_util_proc_in_med_ext(MOD_L1SP,
                             aud_bt_a2dp_sink_codec_event_hdlr,
                             (void*)&event,
                             sizeof(Media_Event));
}

/*****************************************************************************
 * FUNCTION
 *  aud_bt_open_a2dp_sink_codec_req_hdlr
 * DESCRIPTION
 * This function is used to Open A2DP Sink Codec
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bt_open_a2dp_sink_codec_req_hdlr(ilm_struct * ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *param = NULL;
	kal_uint8	result=0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_bt_open_sink_codec_req_struct *msg_p = (media_bt_open_sink_codec_req_struct*)ilm_ptr->local_para_ptr;

    if(a2dp_sink_handle != NULL)
		return; 

	// stop tone first to avoid memory fragment
	DTMF_MCU_StopAndWait();
    KT_StopAndWait();
    TONE_StopAndWait();
	ASSERT(aud_context_p->ring_buf == NULL); /* Assert the ring buffer was freed before being allocated. */
    if (aud_context_p->ring_buf == NULL)
    {
        aud_util_alloc_ring_buffer_ext(MED_RING_BUFFER_SIZE, &aud_context_p->ring_buf);
        ASSERT(aud_context_p->ring_buf != NULL);
    }	
	
    stream_handle = msg_p->stream_handle;
    memcpy(&audio_config, &msg_p->cfg, sizeof(bt_a2dp_audio_cap_struct));
    codec_seq_no = msg_p->seq_no;
	param = &audio_config;
	
	#ifdef __KARAOKE_SUPPORT__ //if sbc codec is mono, we need to set mono for karaoke
	{
		extern kal_bool g_karaoke_mono;
	    if(0x08 == audio_config.codec_cap.sbc.channel_mode)
	    {
	        g_karaoke_mono = KAL_TRUE;
			Media_SetKaraRecMixChannel(MEDIA_KARAREC_MIX_MONO);
		}
	}
	#endif/*__KARAOKE_SUPPORT__*/

    switch (audio_config.codec_type)
    {
        case BT_A2DP_SBC:
            a2dp_sink_handle = A2DPDec_Strm_Open(aud_bt_a2dp_sink_codec_callback,NULL,param);
		    if(a2dp_sink_handle == NULL)
				ASSERT(0);
            break;
    #if defined(DAF_DECODE)
        case BT_A2DP_MP3:
            a2dp_sink_handle = DAF_Open(aud_bt_a2dp_sink_codec_callback,NULL,param);
		    if(a2dp_sink_handle == NULL)
				ASSERT(0);
            break;
    #endif /*if defined(DAF_DECODE) */
    #if defined(AAC_DECODE)
        case BT_A2DP_AAC:
            a2dp_sink_handle = AAC_Open(aud_bt_a2dp_sink_codec_callback,NULL,param);
		    if(a2dp_sink_handle == NULL)
				ASSERT(0);
            break;
    #endif /*defined(AAC_DECODE)*/
        default:
            ASSERT(0);
    }   
	
	a2dp_sink_handle->SetBuffer(a2dp_sink_handle, (kal_uint8*) aud_context_p->ring_buf, MED_RING_BUFFER_SIZE);

    a2dp_sink_state = A2DP_SINK_CODEC_STATE_OPEN;
	
	AUD_BT_A2DP_FUNC_TRACE1(AUD_BT_A2DP_OPEN_SINK_CODEC,result);
    aud_send_bt_open_sink_codec_cnf(MOD_MMI,stream_handle,result);
}

/*****************************************************************************
 * FUNCTION
 *  aud_bt_start_a2dp_sink_codec_req_hdlr
 * DESCRIPTION
 * This function is to start A2DP Sink Codec
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/

void aud_bt_start_a2dp_sink_codec_req_hdlr(ilm_struct * ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8	result=0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((a2dp_sink_state == A2DP_SINK_CODEC_STATE_OPEN)&&(a2dp_sink_handle != NULL))
    {
        /* Set output path */
        aud_get_active_device_path_by_mode(AUDIO_DEVICE_SPEAKER2, aud_melody_set_output_device);

        /* Set output volume */
        aud_set_active_ring_tone_volume();
	
        result = a2dp_sink_handle->Play(a2dp_sink_handle);
		if(result == MEDIA_SUCCESS)
		{
			a2dp_sink_state = A2DP_SINK_CODEC_STATE_PLAY;
			aud_enter_state(AUD_MEDIA_PLAY);
		}
    }
	else
	{
        result = 1;
	}

    aud_send_bt_start_sink_codec_cnf(MOD_BT,result);
}

/*****************************************************************************
 * FUNCTION
 *  aud_bt_stop_a2dp_sink_codec_req_hdlr
 * DESCRIPTION
 * This function is used to Stop A2DP Sink Codec
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/

void aud_bt_stop_a2dp_sink_codec_req_hdlr(ilm_struct * ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8	result=0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((a2dp_sink_state == A2DP_SINK_CODEC_STATE_PLAY)&&(a2dp_sink_handle != NULL))
    {
        result = a2dp_sink_handle->Stop(a2dp_sink_handle);
		a2dp_sink_handle->ResetMediaBuf(a2dp_sink_handle);//reset ringbuffer as BT stream is stop
		
        a2dp_sink_state = A2DP_SINK_CODEC_STATE_OPEN;
		aud_enter_state(AUD_MEDIA_IDLE);
    }
	else
	{
        result = 1;
	}

    aud_send_bt_stop_sink_codec_cnf(MOD_BT,result);
}

/*****************************************************************************
 * FUNCTION
 *  aud_bt_close_a2dp_sink_codec_req_hdlr
 * DESCRIPTION
 * this function is used to close A2DP Sink Codec
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/

void aud_bt_close_a2dp_sink_codec_req_hdlr(ilm_struct * ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8	result=0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	aud_bt_a2dp_lock_codec();
	if((a2dp_sink_state == A2DP_SINK_CODEC_STATE_PLAY)&&(a2dp_sink_handle != NULL))
	{
        result = a2dp_sink_handle->Stop(a2dp_sink_handle);
		result = a2dp_sink_handle->Close(a2dp_sink_handle);
	}
	else if((a2dp_sink_state == A2DP_SINK_CODEC_STATE_OPEN)&&(a2dp_sink_handle != NULL))
	{
	    result = a2dp_sink_handle->Close(a2dp_sink_handle);
	}
	else
	{
        result = 1;
		aud_bt_a2dp_unlock_codec();
        AUD_BT_A2DP_FUNC_TRACE1(AUD_BT_A2DP_CLOSE_SIND_CODEC,result);
	    aud_send_bt_close_sink_codec_cnf(MOD_MMI,stream_handle,result);
		return;
	}
	
	if (aud_context_p->ring_buf)
    {
        aud_util_free_ring_buffer_ext((kal_uint16**)&aud_context_p->ring_buf);
        aud_context_p->ring_buf = NULL;
    }

	a2dp_sink_state = A2DP_SINK_CODEC_STATE_IDLE;
	a2dp_sink_handle = NULL;
	aud_enter_state(AUD_MEDIA_IDLE);
	
	aud_bt_a2dp_unlock_codec();

	AUD_BT_A2DP_FUNC_TRACE1(AUD_BT_A2DP_CLOSE_SIND_CODEC,result);
	aud_send_bt_close_sink_codec_cnf(MOD_MMI,stream_handle,result);
}

#else
/*****************************************************************************
 * FUNCTION
 *  aud_bt_get_a2dp_sink_codec
 *
 * DESCRIPTION
 *  To Avoid BT driver link error when BT Speaker support is not define
 *
 * PARAMETERS
 * void
 *
 * RETURNS
 *  NULL
 *****************************************************************************/
MHdl *aud_bt_get_a2dp_sink_codec(void)
{
  return NULL;
}

#endif

#else /*dummy function for turn off A2DP in customer side*/

void aud_bt_a2dp_open_codec(kal_int32 audio_format)
{
    return;
}

A2DP_codec_struct* aud_bt_a2dp_get_codec(void)
{
    return NULL;
}

void aud_bt_a2dp_lock_codec(void)
{
    return;
}

void aud_bt_a2dp_unlock_codec(void)
{
    return;
}

#endif /* __MED_BT_A2DP_MOD__ && __BTMTK__*/

#endif /* MED_NOT_PRESENT */ 

