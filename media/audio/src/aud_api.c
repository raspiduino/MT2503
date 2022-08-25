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
 *   aud_api.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary exported functions of audio module.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
//#include "kal_release.h"
#include "kal_trace.h"
//#include "stack_common.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
//#include "syscomp_config.h"
//#include "task_config.h"        /* Task creation */
//#include "app_buff_alloc.h"     /* Declaration of buffer management API */
//#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
//#include "event_shed.h" /* Event scheduler */
//#include "stack_timer.h"        /* Stack timer */

/* global includes */
#include "l1audio.h"
//#include "device.h"
//#include "resource_audio.h"
//#include "nvram_enums.h"
//#include "nvram_struct.h"
//#include "nvram_user_defs.h"
//#include "nvram_data_items.h"
//#include "custom_nvram_editor_data_item.h"
#include "nvram_default_audio.h"


/* local includes */
#include "med_global.h"
#include "med_main.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "aud_main.h"
#include "med_main.h"
#include "med_v_main.h"
#include "med_v_context.h"
#include "med_v_struct.h"
#include "med_utility.h"

#include "kal_general_types.h"
//#include "kal_active_module.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "string.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

static kal_int32 aud_result;
static kal_uint32 aud_value;

#ifdef __MED_MMA_MOD__
static kal_int32 mma_result;
static kal_int32 mma_handle;
#endif /* __MED_MMA_MOD__ */ 

#ifdef __MED_SND_MOD__
static kal_int32 bgsnd_result;
#endif 

#ifdef __MED_AUD_AUDIO_EFFECT__
static kal_int32 audio_effect_result;
#endif 

#ifdef __VOICE_CHANGER_SUPPORT__
static kal_bool voice_changer_result=KAL_TRUE;
#endif

#ifdef __VAD_SUPPORT__
static kal_bool vad_result = KAL_TRUE;
#endif


/*==== FUNCTIONS ===========*/

/*****************************************************************************
 * FUNCTION
 *  aud_wait_event
 * DESCRIPTION
 *  wait audio event
 * PARAMETERS
 *  evt           [IN]   wait audio event
 * RETURNS
 *  void
 *****************************************************************************/
void aud_wait_event(kal_uint32 evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 retrieved_events;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_retrieve_eg_events(
        aud_context_p->aud_event, 
        evt,
        KAL_OR_CONSUME, 
        &retrieved_events, 
        KAL_SUSPEND);
}

/*****************************************************************************
 * FUNCTION
 *  aud_set_event
 * DESCRIPTION
 *  set audio event
 * PARAMETERS
 *  evt           [IN]   set audio event
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_event(kal_uint32 evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_set_eg_events(aud_context_p->aud_event, evt ,KAL_OR);
}

#ifdef __GAIN_TABLE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  media_aud_speech_set_fir_coeff
 * DESCRIPTION
 *  This function is to set FIR coefficient of speech.
 * PARAMETERS
 *  input_idx            [IN]   Index of input FIR filter.
 *  output_idx           [IN]   Index of output FIR filter.
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_speech_set_fir_coeff(kal_int16 input_idx, kal_int16 output_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_set_speech_fir_coeff_req(kal_get_active_module_id(), input_idx, output_idx);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  media_aud_speech_set_rat_mode
 * DESCRIPTION
 *  This function is to the rat mode of speech
 * PARAMETERS
 *  speech_on            [IN]   Indicate if the speech is on
 *  rat_mode             [IN]   Rat mode
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_speech_set_rat_mode(kal_bool speech_on, kal_uint8 rat_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_set_speech_mode_req(speech_on, rat_mode);
}

/*****************************************************************************
 * FUNCTION
 *  media_aud_speech_set_enhance_mode
 * DESCRIPTION
 *  This function is to set speech enhancement mode. The available mode are
 *  defined in l1audio.h, such as SPH_MODE_NORMAL.
 * PARAMETERS
 *  mode            [IN]   Speech enhancement mode.
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_speech_set_enhance_mode(kal_uint8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_set_speech_enhance_mode_req(mode);
}

#ifdef __VOICE_CHANGER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  media_aud_set_voice_changer_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  mode     [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool media_aud_set_voice_changer_mode(SPH_VOICE_CHANGER_MODE mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_voice_changer_set_mode_req_struct *msg_p = (media_voice_changer_set_mode_req_struct*)
        construct_local_para(sizeof(media_voice_changer_set_mode_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->mode = mode;

    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_SET_VOICE_CHANGER_MODE_REQ, msg_p);

    AUD_WAIT_EVENT(AUD_VOICE_CHANGER_EVT_SET);
    return voice_changer_result;
}

/*****************************************************************************
 * FUNCTION
 *  aud_set_VC_result_and_event
 * DESCRIPTION
 *  This function is to set the result and event of voice changer 
 * PARAMETERS
 *  result      [IN]
 *  event       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_VC_result_and_event(kal_bool result, kal_uint32 evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    voice_changer_result = result;
    aud_set_event(evt);
}

#endif

#ifdef __LINE_IN_SUPPORT__
void media_send_enable_bt_box_linein_req(kal_bool on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	media_enable_bt_box_linein_req_struct *msg_p = (media_enable_bt_box_linein_req_struct*)
			construct_local_para(sizeof(media_enable_bt_box_linein_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	msg_p->on = on;
    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_ENABLE_BT_BOX_LINEIN_REQ, msg_p);
}

void media_send_force_use_linein_mic_req(kal_bool force_use)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	media_force_use_linein_mic_req_struct *msg_p = (media_force_use_linein_mic_req_struct*)
			construct_local_para(sizeof(media_force_use_linein_mic_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	msg_p->force_use = force_use;
    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_FORCE_USE_LINEIN_MIC_REQ, msg_p);
}

#endif

//#ifdef __MED_MEGA_PHONE__
/*****************************************************************************
 * FUNCTION
 *  media_aud_enable_megaphone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  on          [IN]            
 * RETURNS
 *  
 *****************************************************************************/
void media_aud_enable_megaphone(kal_bool on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_enable_megaphone_req_struct *msg_p = (media_enable_megaphone_req_struct*)
        construct_local_para(sizeof(media_enable_megaphone_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->on= on;

    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_ENABLE_MEGAPHONE_REQ, msg_p);
	AUD_WAIT_EVENT(AUD_EVT_WAIT);
}
//#endif

#ifdef __KARAOKE_SUPPORT__
void media_aud_set_karaoke_mode_req(Media_Kara_opt_mode mode,void *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	media_set_karaoke_mode_req_struct *msg_p = (media_set_karaoke_mode_req_struct*)
			construct_local_para(sizeof(media_set_karaoke_mode_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	msg_p->mode = mode;
	if(file_name != NULL)
	    kal_wstrncpy(msg_p->file_name, file_name, MAX_MEDIA_FILE_NAME);
	else
		memset(msg_p->file_name,0,sizeof(kal_wchar)*MAX_MEDIA_FILE_NAME);
	//msg_p->file_name = file_name;
    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_SET_KARAOKE_MODE_REQ, msg_p);
}

void media_aud_set_karaoke_channel_req(Media_KaraRec_Mix_CH channel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	media_set_karaoke_channel_req_struct *msg_p = (media_set_karaoke_channel_req_struct*)
			construct_local_para(sizeof(media_set_karaoke_channel_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	msg_p->channel = channel;
    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_SET_KARAOKE_CHANNEL_REQ, msg_p);
}

void media_aud_set_karaoke_digitgain_req(kal_uint16 unum, kal_uint16 uden)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	media_set_karaoke_digitgain_req_struct *msg_p = (media_set_karaoke_digitgain_req_struct*)
			construct_local_para(sizeof(media_set_karaoke_digitgain_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	msg_p->uDen = uden;
	msg_p->uNum = unum;
    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_SET_KARAOKE_DIGITGAIN_REQ, msg_p);
}


#ifdef __KARAOKE_NEED_KEEP_SRC_PATH__
static kal_uint32 karaoke_result=MED_RES_OK;

/*****************************************************************************
 * FUNCTION
 *  aud_set_karaoke_result_and_event
 * DESCRIPTION
 *  This function is to set the result and event of karaoke
 * PARAMETERS
 *  result      [IN]
 *  event       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_karaoke_result_and_event(kal_int32 result, kal_uint32 evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    karaoke_result = result;
    aud_set_event(evt);
}

kal_int32 media_aud_karaoke_remix_turn_on_req(kal_wchar* filename, kal_uint32 msRecordStartTime, kal_uint32 msAudioSeekTime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	media_karaoke_remix_turn_on_req_struct *msg_p = (media_karaoke_remix_turn_on_req_struct*)
			construct_local_para(sizeof(media_karaoke_remix_turn_on_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(filename != NULL)
	    kal_wstrncpy(msg_p->rec_path, filename, MAX_MEDIA_FILE_NAME);
	else
		memset(msg_p->rec_path ,0,sizeof(kal_wchar)*MAX_MEDIA_FILE_NAME);
	msg_p->msAudioSeekTime = msAudioSeekTime;
	msg_p->msRecordStartTime = msRecordStartTime;
    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_KARAOKE_REMIX_TURN_ON_REQ, msg_p);

	AUD_WAIT_EVENT(AUD_KARAOKE_EVT_SET);
    return karaoke_result;
}

void media_aud_karaoke_remix_turn_off_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	media_karaoke_remix_turn_off_req_struct *msg_p = (media_karaoke_remix_turn_off_req_struct*)
			construct_local_para(sizeof(media_karaoke_remix_turn_off_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_KARAOKE_REMIX_TURN_OFF_REQ, msg_p);
}

void media_aud_karaoke_set_remix_mode_req(Media_KaraRec_Mix_CH ch_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	media_karaoke_set_remix_mode_req_struct *msg_p = (media_karaoke_set_remix_mode_req_struct*)
			construct_local_para(sizeof(media_karaoke_set_remix_mode_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	msg_p->channelMode = ch_mode;
    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_KARAOKE_SET_REMIX_MODE_REQ, msg_p);
}

void media_aud_karaoke_set_remix_audio_gain_req(kal_uint16 audio_gain)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	media_karaoke_set_remix_audio_gain_req_struct *msg_p = (media_karaoke_set_remix_audio_gain_req_struct*)
			construct_local_para(sizeof(media_karaoke_set_remix_audio_gain_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	msg_p->audio_gain = audio_gain;
    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_KARAOKE_SET_REMIX_AUDIO_GAIN_REQ, msg_p);
}

void media_aud_karaoke_set_remix_voice_gain_req(kal_uint16 voice_gain)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	media_karaoke_set_remix_voice_gain_req_struct *msg_p = (media_karaoke_set_remix_voice_gain_req_struct*)
			construct_local_para(sizeof(media_karaoke_set_remix_voice_gain_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	msg_p->voice_gain = voice_gain;
    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_KARAOKE_SET_REMIX_VOICE_GAIN_REQ, msg_p);
}

#endif /*__KARAOKE_NEED_KEEP_SRC_PATH__*/

#endif/*__KARAOKE_SUPPORT__*/


#ifdef __VAD_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  media_aud_switch_vad_on_off
 * DESCRIPTION
 *  This funtion is used to switch on/off vad detect
 * PARAMETERS
 *  on          [IN]        
 *  param     [IN]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool media_aud_switch_vad_on_off(kal_bool on, void* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_switch_vad_on_off_req_struct *msg_p = (media_switch_vad_on_off_req_struct*)
        construct_local_para(sizeof(media_switch_vad_on_off_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->on = on;
	msg_p->param = param;

    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_SWITCH_VAD_ON_OFF_REQ, msg_p);

    AUD_WAIT_EVENT(AUD_VAD_EVT_SET);
    return vad_result;
}

/*****************************************************************************
 * FUNCTION
 *  aud_set_vad_level
 * DESCRIPTION
 *  This function is to set vad level 
 * PARAMETERS
 *  result      [IN]
 *  event       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool media_aud_set_vad_level(kal_uint8 level)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	media_set_vad_level_req_struct *msg_p = (media_set_vad_level_req_struct*)
		construct_local_para(sizeof(media_set_vad_level_req_struct), TD_CTRL);

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	msg_p->level= level;

	aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_SET_VAD_LEVEL_REQ, msg_p);

	AUD_WAIT_EVENT(AUD_VAD_EVT_SET);
    return vad_result;
}

/*****************************************************************************
 * FUNCTION
 *  aud_send_vad_detect_ind
 * DESCRIPTION
 *  This function is to send vad detect result to up layer 
 * PARAMETERS
 *  des_mod_id      [IN]
 *  result       [IN]
 * RETURNS
 *  void
 *****************************************************************************/

void aud_send_vad_detect_ind(module_type dst_mod_id, kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vad_detect_ind_struct *msg_p = (media_vad_detect_ind_struct*)
        construct_local_para(sizeof(media_vad_detect_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->result = result;

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_MEDIA_VAD_DETECT_IND, msg_p);
}

/*****************************************************************************
 * FUNCTION
 *  aud_set_vad_result_and_event
 * DESCRIPTION
 *  This function is to set the result and event of voice changer 
 * PARAMETERS
 *  result      [IN]
 *  event       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_vad_result_and_event(kal_bool result, kal_uint32 evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vad_result = result;
    aud_set_event(evt);
}

#endif

#ifdef __SPEECH_MODE_TABLE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  media_aud_speech_set_enhance_mode_ext
 * DESCRIPTION
 *  This function is to set speech enhancement mode. 
 * PARAMETERS
 *  mode            [IN]    Speech enhancement mode.
 *  param_p         [IN]    Speech enhancement parameters.
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_speech_set_enhance_mode_ext(kal_uint8 mode, kal_uint16* param_p, kal_uint16* wb_param_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_sp_set_enhance_mode_req_struct *msg_p = (media_aud_sp_set_enhance_mode_req_struct*)
        construct_local_para(sizeof(media_aud_sp_set_enhance_mode_req_struct), TD_CTRL);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->mode = mode;
    msg_p->is_with_param = KAL_TRUE;

    if (param_p)
    {
        memcpy(msg_p->param, param_p, sizeof(kal_uint16) * 16);
    }
    else
    {
        memset(msg_p->param, 0, sizeof(kal_uint16) * 16);
    }

    if (wb_param_p)
    {
        memcpy(msg_p->wb_param, wb_param_p, sizeof(kal_uint16) * 16);
    }
    else
    {
        memset(msg_p->wb_param, 0, sizeof(kal_uint16) * 16);
    }
    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_AUD_SP_SET_ENHANCE_MODE_REQ, msg_p);
}
#endif /* __SPEECH_MODE_TABLE_SUPPORT__ */

#ifdef __DUAL_MIC_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  media_aud_mic_set_dual_nr
 * DESCRIPTION
 *  This function is to enable/disable NR for dual microphone.
 * PARAMETERS
 *  is_enable            [IN]   Enable/disable NR
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_mic_set_dual_nr(kal_uint8 is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_set_mic_dual_nr_req(kal_get_active_module_id(), is_enable);
}
#endif /* __DUAL_MIC_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  media_aud_set_mute
 * DESCRIPTION
 *  This function is to send mute request message to MED task.
 * PARAMETERS
 *  vol_type            [IN]
 *  mute                [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_set_mute(kal_uint8 vol_type, kal_bool mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mute_req(vol_type,mute);
}

#ifdef __GAIN_TABLE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  media_aud_update_volume
 * DESCRIPTION
 *  This function is to send update volume request message to MED task.
 * PARAMETERS
 *  vol_type            [IN]
 *  volume              [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_update_volume(kal_uint8 vol_type, kal_uint64 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_update_volume_req(kal_get_active_module_id(),vol_type,volume);
}
#endif /*__GAIN_TABLE_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  media_aud_set_volume
 * DESCRIPTION
 *  This function is to send set volume request message to MED task.
 * PARAMETERS
 *  vol_type            [IN]
 *  volume              [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_set_volume(kal_uint8 vol_type, kal_uint64 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_set_volume_req(vol_type, volume, KAL_TRUE, KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_set_volume_ext
 * DESCRIPTION
 *  This function is to send set volume request message to MED task.
 * PARAMETERS
 *  vol_type            [IN]
 *  volume              [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_set_volume_ext(kal_uint8 vol_type, kal_uint64 volume, kal_bool apply, kal_bool blocking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_set_volume_req(vol_type, volume, apply, blocking);
}

/*****************************************************************************
 * FUNCTION
 *  media_aud_get_volume
 * DESCRIPTION
 *  This function is to get volume in synchronous way. Note that the caller 
 *  thread will be blocked until the request has been processed by MED.
 * PARAMETERS
 *  vol_type            [IN]
 *  volume              [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_get_volume(kal_uint8 vol_type, kal_uint8* volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_get_volume_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_aud_get_volume_req_struct *)
        construct_local_para(sizeof(media_aud_get_volume_req_struct ), TD_CTRL);

    msg_p->src_id = kal_get_active_module_id();
    msg_p->volume_type = vol_type;

    aud_send_msg_to_med(kal_get_active_module_id(),
                        (kal_uint16) MSG_ID_L4AUD_AUDIO_GET_VOLUME_IN_SYNC_REQ,
                        msg_p);

    aud_wait_event(AUD_EVT_GET_VOLUME);
    *volume = (kal_uint8)aud_result;
}

#if defined(__AUD_REC_INTENSITY__)
/*****************************************************************************
 * FUNCTION
 *  media_get_record_intensity
 * DESCRIPTION
 *  This function is for mdi to get mic intensity when record 
 * PARAMETERS
 *  channel            [IN]   first mic or second mic
 *  strength           [OUT]    the intensity of mic get from driver     
 * RETURNS
 *  void
 *****************************************************************************/
void media_get_record_intensity(kal_uint32 channel,kal_uint32* strength)
{	
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_get_intensity_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	msg_p = (media_aud_get_intensity_req_struct *)
        construct_local_para(sizeof(media_aud_get_intensity_req_struct ), TD_CTRL);

    msg_p->src_id = kal_get_active_module_id();
    msg_p->channel = channel;
	msg_p->p_strength = strength;
	aud_send_msg_to_med(kal_get_active_module_id(),
                        (kal_uint16) MSG_ID_L4AUD_AUDIO_GET_INTENSITY_REQ,
                        msg_p);
	
	aud_wait_event(AUD_EVT_WAIT);   
	
}

/*****************************************************************************
 * FUNCTION
 *  media_get_record_intensity_limit
 * DESCRIPTION
 *  This function is for mdi to get mic intensity max and min value when record 
 * PARAMETERS
 *  max_value            [IN]   max value point to get mic intensity  
 *  min_value           [IN]     min value point to get mic intensity      
 * RETURNS
 *  
 *****************************************************************************/
void media_get_record_intensity_limit(kal_uint32* max_value,kal_uint32* min_value)
{	
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_get_intensity_limit_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	msg_p = (media_aud_get_intensity_limit_req_struct *)
        construct_local_para(sizeof(media_aud_get_intensity_limit_req_struct ), TD_CTRL);

    msg_p->src_id = kal_get_active_module_id();
    msg_p->max_value= max_value;
	msg_p->min_value = min_value;
	aud_send_msg_to_med(kal_get_active_module_id(),
                        (kal_uint16) MSG_ID_L4AUD_AUDIO_GET_INTENSITY_LIMIT_REQ,
                        msg_p);
	
	aud_wait_event(AUD_EVT_WAIT);
	
}

#endif/*__AUD_REC_INTENSITY__*/


/*****************************************************************************
 * FUNCTION
 *  media_aud_get_max_volume
 * DESCRIPTION
 *  This function is to get max volume level in synchronous way. Note that
 *  the caller thread will be blocked until the request has been processed
 *  by MED.
 * PARAMETERS
 *  vol_type            [IN]
 *  volume              [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_get_max_volume(kal_uint8* max_volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_audio_get_max_volume_level_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (l4aud_audio_get_max_volume_level_req_struct *)
        construct_local_para(sizeof(l4aud_audio_get_max_volume_level_req_struct ), TD_CTRL);

    msg_p->src_id = kal_get_active_module_id();

    aud_send_msg_to_med(kal_get_active_module_id(),
                        (kal_uint16) MSG_ID_L4AUD_AUDIO_GET_MAX_VOLUME_LEVEL_IN_SYNC_REQ,
                        msg_p);
    
    aud_wait_event(AUD_EVT_GET_VOLUME);
    *max_volume = (kal_uint8)aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_set_audio_mode
 * DESCRIPTION
 *  This function is to send set volume request message to MED task.
 * PARAMETERS
 *  vol_type            [IN]
 *  volume              [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_set_audio_mode(kal_uint8 audio_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_set_audio_mode_req(audio_mode);
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_set_device
 * DESCRIPTION
 *  This function is to send set device request message to MED task.
 * PARAMETERS
 *  audio_type            [IN]
 *  device              [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_set_device(kal_uint8 audio_type, kal_uint8 device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_set_device_req(audio_type, device);
}


/*****************************************************************************
 * FUNCTION
 *  aud_debug_print_aud_drv_return
 * DESCRIPTION
 *  Print audio return cause
 * PARAMETERS
 *  aud_ret             [IN]        Media_Status
 *  line                [IN]        line
 * RETURNS
 *  void
 *****************************************************************************/
void aud_debug_print_aud_drv_return(kal_int32 aud_ret, kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __LOW_COST_SUPPORT_COMMON__
    switch(aud_ret)
    {
        case MEDIA_SUCCESS:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_SUCCESS, line);
            break;
            
        case MEDIA_FAIL:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_FAIL, line);
            break;
            
        case MEDIA_REENTRY:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_REENTRY, line);
            break;       

        case MEDIA_NOT_INITIALIZED:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_NOT_INITIALIZED, line);
            break;            

        case MEDIA_BAD_FORMAT:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_BAD_FORMAT, line);
            break;            

        case MEDIA_BAD_PARAMETER:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_BAD_PARAMETER, line);
            break;            

        case MEDIA_BAD_COMMAND:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_BAD_COMMAND, line);
            break;               

        case MEDIA_NO_HANDLER:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_NO_HANDLER, line);
            break;                    

        case MEDIA_UNSUPPORTED_CHANNEL:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_UNSUPPORTED_CHANNEL, line);
            break;                    

        case MEDIA_UNSUPPORTED_FREQ:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_UNSUPPORTED_FREQ, line);
            break;                    

        case MEDIA_UNSUPPORTED_TYPE:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_UNSUPPORTED_TYPE, line);
            break;                    

        case MEDIA_UNSUPPORTED_OPERATION:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_UNSUPPORTED_OPERATION, line);
            break;                    

        case MEDIA_SEEK_FAIL:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_SEEK_FAIL, line);
            break;                    

        case MEDIA_SEEK_EOF:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_SEEK_EOF, line);
            break;      

        case MEDIA_READ_FAIL:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_READ_FAIL, line);
            break;      

        case MEDIA_WRITE_FAIL:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_WRITE_FAIL, line);
            break;      

        case MEDIA_DISK_FULL:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_DISK_FULL, line);
            break;                  

        case MEDIA_MERGE_TYPE_MISMATCH:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_MERGE_TYPE_MISMATCH, line);
            break;       

        default:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_UNKNOWN_ENUM, aud_ret, line);
            break;
    }
#endif
}



/*****************************************************************************
 * FUNCTION
 *  aud_set_result
 * DESCRIPTION
 *  This function is to set the result of audio request.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_result(kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_RESULT_TRACE(result);
    aud_result = result;
}

/*****************************************************************************
 * FUNCTION
 *  aud_set_result_and_event
 * DESCRIPTION
 *  This function is to set the result and event of audio request 
 * PARAMETERS
 *  result      [IN]
 *  event       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_result_and_event(kal_int32 result, kal_uint32 evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_set_result(result);
    aud_set_event(evt);
}


/*****************************************************************************
 * FUNCTION
 *  aud_set_pair_results
 * DESCRIPTION
 *  This function is to set the result and the value of audio request.
 * PARAMETERS
 *  result      [IN]        
 *  value       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_pair_results(kal_int32 result, kal_uint32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_VALUE2_TRACE(result, value);
    aud_result = result;
    aud_value = value;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_play_id
 * DESCRIPTION
 *  This function is to play audio ID.
 * PARAMETERS
 *  src_mod_id      [IN]        void *id_param
 *  id_param        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_aud_play_id(module_type src_mod_id, void *id_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_play_id_req(id_param);
    /* AUD_WAIT_EVENT(AUD_EVT_PLAY); */
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_stop_id
 * DESCRIPTION
 *  This function is to stop audio ID.
 * PARAMETERS
 *  src_mod_id      [IN]        kal_uint8 audio_id
 *  audio_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_aud_stop_id(module_type src_mod_id, kal_uint8 audio_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_stop_id_req(audio_id);
    aud_wait_event(AUD_EVT_STOP);
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_play_string
 * DESCRIPTION
 *  This function is to play audio string.
 * PARAMETERS
 *  src_mod_id          [IN]        void *string_param
 *  string_param        [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_play_string(module_type src_mod_id, void *string_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_play_string_struct *data_p = (aud_play_string_struct*) string_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_play_string_req(string_param);
    if (data_p->blocking)
    {
        aud_wait_event(AUD_EVT_PLAY);		
		return aud_result;
    }
	else
	{
		return MED_RES_OK;
	}
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_stop_string
 * DESCRIPTION
 *  This function is to stop audio string.
 * PARAMETERS
 *  src_mod_id      [IN]        kal_uint8 src_id
 *  src_id          [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_stop_string(module_type src_mod_id, kal_uint8 src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_stop_string_req(src_id);
    aud_wait_event(AUD_EVT_STOP);
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_play_file
 * DESCRIPTION
 *  This function is to play audio file.
 * PARAMETERS
 *  src_mod_id      [IN]        void *file_param
 *  file_param      [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_play_file(module_type src_mod_id, void *file_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MED_AUD_FS_ACCESS__)
    aud_send_play_file_req(file_param);
    aud_wait_event(AUD_EVT_PLAY);
    return aud_result;
    
#else /*__MED_AUD_FS_ACCESS__*/
    return MED_RES_FAIL;
#endif /*__MED_AUD_FS_ACCESS__*/
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_stop_file
 * DESCRIPTION
 *  This function is to stop audio file.
 * PARAMETERS
 *  src_mod_id      [IN]        kal_uint8 src_id
 *  src_id          [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_stop_file(module_type src_mod_id, kal_uint8 src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MED_AUD_FS_ACCESS__)
    aud_send_stop_file_req(src_id);
    aud_wait_event(AUD_EVT_STOP);
    return MED_RES_OK;//aud_result;
    
#else /*__MED_AUD_FS_ACCESS__*/
    return MED_RES_FAIL;
#endif /*__MED_AUD_FS_ACCESS__*/    
}

#ifdef __SPECTRUM_DISPLAY_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  media_aud_get_spectrum
 * DESCRIPTION
 *  This function is to get the audio spectrum tops and vals:
 * PARAMETERS
 *  src_mod_id      [IN]        kal_uint8* top_p, kal_uint8* val_p
 *  top_p           [?]         
 *  val_p           [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_get_spectrum(module_type src_mod_id, kal_uint8 *top_p, kal_uint8 *val_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_get_spectrum_req(top_p, val_p);
    aud_wait_event(AUD_EVT_GET_SPECTRUM);
    return aud_result;
}
#endif /* __SPECTRUM_DISPLAY_SUPPORT__ */ 

/*****************************************************************************
 * FUNCTION
 *  media_aud_get_duration
 * DESCRIPTION
 *  This function is to get the audio file duration.
 * PARAMETERS
 *  src_mod_id      [IN]        void* file_name, kal_uint32* time_p
 *  file_name       [?]         
 *  time_p          [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_get_duration(module_type src_mod_id,
                                 void *file_name,
                                 kal_uint8 *audio_data,
                                 kal_uint32 len,
                                 kal_uint8 format,
                                 kal_uint32 *time_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *time_p = 0;

    aud_send_get_duration_req(KAL_FALSE, file_name, audio_data, len, format, KAL_FALSE);

    aud_wait_event(AUD_EVT_GET_DURATION);
    *time_p = aud_value;
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_get_duration
 * DESCRIPTION
 *  This function is to get the audio file duration.
 * PARAMETERS
 *  src_mod_id      [IN]        void* file_name, kal_uint32* time_p
 *  file_name       [?]         
 *  time_p          [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_get_mp4_duration(module_type src_mod_id,
                                 void *file_name,
                                 kal_uint8 *audio_data,
                                 kal_uint32 len,
                                 kal_uint8 format,
                                 kal_uint32 *time_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *time_p = 0;

    aud_send_get_duration_req(KAL_FALSE, file_name, audio_data, len, format, KAL_TRUE);

    aud_wait_event(AUD_EVT_GET_DURATION);
    *time_p = aud_value;
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_get_progress_time
 * DESCRIPTION
 *  This function is to get the progress time (milliseconds) of playing audio file
 * PARAMETERS
 *  src_mod_id          [IN]        kal_uint32* progress_time_p
 *  progress_time_p     [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_get_progress_time(module_type src_mod_id, kal_uint32 *progress_time_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *progress_time_p = 0;
    aud_send_get_progress_time_req();
    aud_wait_event(AUD_EVT_GET_PROGRESS_TIME);
    *progress_time_p = aud_value;
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_set_progress_time
 * DESCRIPTION
 *  This function is to set the progress time (milliseconds) of playing audio file
 * PARAMETERS
 *  src_mod_id          [IN]        kal_uint32 progress_time
 *  progress_time       [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_set_progress_time(module_type src_mod_id, kal_uint32 progress_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_set_progress_time_req(progress_time);
    aud_wait_event(AUD_EVT_SET_PROGRESS_TIME);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_check_is_pure_audio
 * DESCRIPTION
 *  This function is to check if a file pure audio file
 * PARAMETERS
 *  src_mod_id      [IN]
 *  file_name       [IN]         
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool media_aud_check_is_pure_audio(module_type src_mod_id, void *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_check_is_pure_audio_req(file_name);

    aud_wait_event(AUD_EVT_IS_PURE_AUDIO);
    return (kal_bool)aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_check_is_file_seekable
 * DESCRIPTION
 *  This function is to check if a file is seekable (AAC ADIF is not seekable)
 * PARAMETERS
 *  src_mod_id      [IN]
 *  file_name       [IN]         
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool media_aud_check_is_file_seekable(module_type src_mod_id, void *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_check_is_file_seekable_req(file_name);

    aud_wait_event(AUD_EVT_WAIT);
    return (kal_bool)aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_check_is_file_pausable
 * DESCRIPTION
 *  This function is to check if a file is pausable (AAC-ADIF is not pausable)
 * PARAMETERS
 *  src_mod_id      [IN]
 *  file_name       [IN]         
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool media_aud_check_is_file_pausable(module_type src_mod_id, void *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_check_is_file_pausable_req(file_name);

    aud_wait_event(AUD_EVT_WAIT);
    return (kal_bool)aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_check_is_resource_available
 * DESCRIPTION
 *  This function is to check if a given audio resource is available.
 * PARAMETERS
 *  resource    [IN]    Audio resource.     
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool media_aud_check_is_resource_available(aud_resource_enum resource)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_check_is_resource_available_req(resource);

    aud_wait_event(AUD_EVT_WAIT);
    return (kal_bool)aud_result;
}


#ifndef MED_V_NOT_PRESENT

/*****************************************************************************
 * FUNCTION
 *  media_aud_start_seek
 * DESCRIPTION
 *  This function is to start seeking to a given position.
 * PARAMETERS
 *  src_mod_id      [IN]    Source module ID.
 *  file_name       [IN]    The file to be sought.
 *  cache_p         [IN]    Cache table.
 *  cache_size      [IN]    The size of cable table.
 *  seek_pos        [IN]    The position to be sought to.
 *  cb_fct          [IN]    Callback function.
 *  cb_param        [IN]    Callback parameter.
 * RETURNS
 * 
 *****************************************************************************/
void media_aud_start_seek(module_type       src_mod_id,
                          void*             file_name,
                          void*             cache_p,
                          kal_int32         cache_size,
                          kal_uint32        seek_pos,
                          media_seek_cb_fct cb_fct,
                          void*             cb_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_audio_start_seek_req_struct *msg_p = (media_audio_start_seek_req_struct*)
            construct_local_para(sizeof(media_audio_start_seek_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wstrncpy(msg_p->file_name, file_name, MAX_MEDIA_FILE_NAME);
    msg_p->cache_p    = cache_p;
    msg_p->cache_size = cache_size;
    msg_p->proc_buf_p = NULL;
    msg_p->proc_buf_size = 0;
    msg_p->seek_pos   = seek_pos;
    msg_p->cb_fct     = cb_fct;
    msg_p->cb_param   = cb_param;

    aud_send_start_seek_req((void*)msg_p);
}

/*****************************************************************************
 * FUNCTION
 *  media_aud_stop_seek
 * DESCRIPTION
 *  This function is to stop seeking.
 * PARAMETERS
 *  src_mod_id          [IN]
 * RETURNS
 * 
 *****************************************************************************/
void media_aud_stop_seek(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_stop_seek_req();

    AUD_CACUE_WAIT_EVENT(AUD_CACHE_EVT_STOP_SEEK);
}

/*****************************************************************************
 * FUNCTION
 *  media_aud_start_build_cache_in_async
 * DESCRIPTION
 *  This function is to start building cache in asynchronous manner.
 * PARAMETERS
 *  src_mod_id          [IN]    Source module ID.
 *  file_name           [IN]    File name.
 *  cache_p             [IN]    Cache table.
 *  cache_size          [IN]    The size of cache table.
 *  cb_fct              [IN]    The function to be called back when build cache is done.
 *  cb_param            [IN]    Private data which will be brought back in the callback.
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_start_build_cache_in_async(module_type       src_mod_id,
                                          kal_wchar*        file_name,
                                          void*             cache_p,
                                          kal_int32         cache_size,
                                          media_seek_cb_fct cb_fct,
                                          void*             cb_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_audio_cache_async_req_struct *msg_p = (media_visual_audio_cache_async_req_struct*)
            construct_local_para(sizeof(media_visual_audio_cache_async_req_struct), TD_CTRL);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wstrncpy(msg_p->file_name, file_name, MAX_MEDIA_FILE_NAME);
    msg_p->cache_p    = cache_p;
    msg_p->cache_size = cache_size;
    msg_p->cb_fct = cb_fct;
    msg_p->cb_param = cb_param;

    aud_send_start_build_cache_async_req(msg_p);
}

/*****************************************************************************
 * FUNCTION
 *  media_aud_close_build_cache_in_async
 * DESCRIPTION
 *  This function is to close audio build cache in asynchronous manner.
 * PARAMETERS
 *  src_mod_id          [IN]
 * RETURNS
 * 
 *****************************************************************************/
void media_aud_close_build_cache_in_async(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    aud_send_close_build_cache_async_req();
}

/*****************************************************************************
 * FUNCTION
 *  media_aud_start_build_cache
 * DESCRIPTION
 *  This function is to start audio build cache
 * PARAMETERS
 *  src_mod_id          [IN]
 *  cache_parm          [IN]
 * RETURNS
 * 
 *****************************************************************************/
void media_aud_start_build_cache(module_type src_mod_id, void *cache_parm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    aud_send_start_build_cache_req(cache_parm);
    
    AUD_CACUE_WAIT_EVENT(AUD_CACHE_EVT_START);
}

/*****************************************************************************
 * FUNCTION
 *  media_aud_stop_build_cache
 * DESCRIPTION
 *  This function is to stop audio build cache
 * PARAMETERS
 *  src_mod_id          [IN]
 * RETURNS
 * 
 *****************************************************************************/
void media_aud_stop_build_cache(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_stop_build_cache_req();
    
    AUD_CACUE_WAIT_EVENT(AUD_CACHE_EVT_STOP);
}

/*****************************************************************************
 * FUNCTION
 *  media_aud_close_build_cache
 * DESCRIPTION
 *  This function is to close audio build cache
 * PARAMETERS
 *  src_mod_id          [IN]
 * RETURNS
 * 
 *****************************************************************************/
void media_aud_close_build_cache(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    aud_send_close_build_cache_req();
    AUD_CACUE_WAIT_EVENT(AUD_CACHE_EVT_CLOSE);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  media_aud_reset_build_cache_variables
 * DESCRIPTION
 *  This function is to reset audio build cache variables
 * PARAMETERS
 *  src_mod_id          [IN]
 * RETURNS
 * 
 *****************************************************************************/
void media_aud_reset_build_cache_variables(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    aud_send_reset_build_cache_vars_req();
    AUD_CACUE_WAIT_EVENT(AUD_CACHE_EVT_RESET);
    return;
}
#endif /*MED_V_NOT_PRESENT*/


/*****************************************************************************
 * FUNCTION
 *  media_aud_start_record
 * DESCRIPTION
 *  This function is to start recording audio.
 * PARAMETERS
 *  src_mod_id          [IN]        kal_wchar* file_name, kal_uint8 format
 *  file_name           [?]         
 *  format              [IN]        
 *  quality             [IN]        0: Low, >0: High
 *  default_input       [IN]        
 *  input_source        [IN]        
 *  size_limit          [IN]        Max record size in byte. 0: unlimited
 *  time_limit          [IN]        Max record time in sec.  0: unlimited
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_start_record(
            module_type src_mod_id,
            kal_wchar *file_name,
            kal_uint8 format,
            kal_uint8 quality,            
            kal_bool default_input,
            kal_uint8 input_source,
            kal_uint32 size_limit,
            kal_uint32 time_limit)            
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MED_AUD_REC_MOD__)
    aud_send_record_req(file_name, format, quality, default_input, input_source, size_limit, time_limit);
    aud_wait_event(AUD_EVT_RECORD);
    return aud_result;

#else /*__MED_AUD_REC_MOD__*/
    return MED_RES_FAIL;
#endif /*__MED_AUD_REC_MOD__*/
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_stop_record
 * DESCRIPTION
 *  This function is to stop recording audio.
 * PARAMETERS
 *  src_mod_id      [IN]        kal_uint8 src_id
 *  src_id          [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_stop_record(module_type src_mod_id, kal_uint8 src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MED_AUD_REC_MOD__)
    aud_send_stop_record_req(src_id);
    aud_wait_event(AUD_EVT_STOP);
    return MED_RES_OK;

#else /*__MED_AUD_REC_MOD__*/
    return MED_RES_FAIL;
#endif /*__MED_AUD_REC_MOD__*/
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_pause
 * DESCRIPTION
 *  This function is to pause audio.
 * PARAMETERS
 *  src_mod_id      [IN]        kal_uint8 src_id
 *  src_id          [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_pause(module_type src_mod_id, kal_uint8 src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_pause_req(src_id);
    aud_wait_event(AUD_EVT_PAUSE);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_resume
 * DESCRIPTION
 *  This function is to resume audio.
 * PARAMETERS
 *  src_mod_id      [IN]        kal_uint8 src_id
 *  src_id          [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_resume(module_type src_mod_id, kal_uint8 src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_resume_req(src_id);
    aud_wait_event(AUD_EVT_RESUME);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_store
 * DESCRIPTION
 *  This function is to pause audio and store play info.
 * PARAMETERS
 *  src_mod_id      [IN]        kal_uint8 src_id
 *  src_id          [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_store(module_type src_mod_id, kal_uint8 src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MED_AUD_FS_ACCESS__)
    aud_send_store_req(src_id);
    aud_wait_event(AUD_EVT_PAUSE);
    return aud_result;
    
#else /*__MED_AUD_FS_ACCESS__*/
    return MED_RES_FAIL;
#endif /*__MED_AUD_FS_ACCESS__*/
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_restore
 * DESCRIPTION
 *  This function is to resume audio.
 * PARAMETERS
 *  src_mod_id      [IN]        kal_uint8 src_id
 *  file_param      [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_restore(module_type src_mod_id, void *file_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MED_AUD_FS_ACCESS__)
    aud_send_restore_req(file_param);
    aud_wait_event(AUD_EVT_RESUME);
    return aud_result;
    
#else /*__MED_AUD_FS_ACCESS__*/
    return MED_RES_FAIL;
#endif /*__MED_AUD_FS_ACCESS__*/
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_set_headset_mode_output_path
 * DESCRIPTION
 *  This function is to set headset mode output path.
 * PARAMETERS
 *  src_mod_id      [IN]        kal_uint8 device
 *  device          [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_set_headset_mode_output_path(module_type src_mod_id, kal_uint8 device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_set_headset_mode_output_path_req(device);
    return MED_RES_OK;
}

#ifdef __VIBRATION_SPEAKER_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  media_aud_vib_spk_calibration
 * DESCRIPTION
 *  This function is to set vibrator current sensor
 * PARAMETERS
 *  src_mod_id      [IN]       
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_vib_spk_calibration(module_type src_mod_id)
{
      /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    aud_send_vib_spk_calibration();

}
#endif


/*****************************************************************************
 * FUNCTION
 *  media_aud_set_vibrator_enabled
 * DESCRIPTION
 *  This function is to set vibrator enabled
 * PARAMETERS
 *  src_mod_id      [IN]        kal_uint8 enable
 *  enable          [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_set_vibrator_enabled(module_type src_mod_id, kal_uint8 enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MED_IMY_EVENT__
    aud_send_set_vibrator_enabled_req(enable);
#endif /*__MED_IMY_EVENT__*/

    return MED_RES_OK;
}

/*****************************************************************************
 * FUNCTION
 *  media_aud_fmr_power_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  output_path     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_fmr_power_on(module_type src_mod_id, kal_uint8 output_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_fmr_power_on_req(output_path);
    aud_wait_event(AUD_EVT_FMR_ON);
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_fmr_power_off
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_fmr_power_off(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_fmr_power_off_req();
    aud_wait_event(AUD_EVT_FMR_OFF);
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_fmr_set_output_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  output_path     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_fmr_set_output_path(module_type src_mod_id, kal_uint8 output_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_fmr_set_output_path_req(output_path);
    aud_wait_event(AUD_EVT_FMR_SET);
    return MED_RES_OK;
}

#ifdef INTERNAL_ANTENNAL_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  media_audio_fmr_set_antenna
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  freq            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_audio_fmr_set_antenna(module_type src_mod_id, kal_bool is_short_antenna)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_fmr_set_antenna_req(is_short_antenna);
    aud_wait_event(AUD_EVT_FMR_SET);
    return MED_RES_OK;
}
#endif/* #ifdef INTERNAL_ANTENNAL_SUPPORT*/

/*****************************************************************************
 * FUNCTION
 *  media_aud_fmr_set_freq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  freq            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_fmr_set_freq(module_type src_mod_id, kal_uint16 freq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_fmr_set_freq_req(freq);
    aud_wait_event(AUD_EVT_FMR_SET);
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_fmr_mute
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mute            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_fmr_mute(module_type src_mod_id, kal_uint8 mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_fmr_mute_req(mute);
    aud_wait_event(AUD_EVT_FMR_MUTE);
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_fmr_evaluate_threshold
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_fmr_evaluate_threshold(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_fmr_set_channel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_fmr_set_channel(module_type src_mod_id, kal_bool is_mono)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_fmr_set_channel_req(is_mono);
    aud_wait_event(AUD_EVT_FMR_SET_CHANNEL);
    return MED_RES_OK;
}

#ifdef __FM_RADIO_HW_SCAN__
/*****************************************************************************
 * FUNCTION
 *  media_aud_fmr_hw_scan
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mute            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_fmr_hw_scan(module_type src_mod_id, kal_uint8 *scan_table)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_fmr_hw_scan_req(scan_table);
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_fmr_hw_scan_abort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mute            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_fmr_hw_scan_abort(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_fmr_hw_scan_abort_req();
    return MED_RES_OK;
}
#endif /* __FM_RADIO_HW_SCAN__ */


#ifdef __FM_RADIO_HW_SEARCH__
/*****************************************************************************
 * FUNCTION
 *  media_aud_fmr_seek_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mute            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_fmr_seek_start(module_type src_mod_id, kal_uint16 start_freq, kal_bool is_step_up, kal_bool is_preset, kal_int16 space_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_fmr_seek_start_req(src_mod_id, start_freq, is_step_up, is_preset, space_value);
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_fmr_seek_abort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mute            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_fmr_seek_abort(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_fmr_seek_abort_req(src_mod_id);
    return MED_RES_OK;
}

#else /* !__FM_RADIO_HW_SEARCH__ */

/*****************************************************************************
 * FUNCTION
 *  media_aud_fmr_check_is_valid_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mute            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_fmr_check_is_valid_stop(module_type src_mod_id, kal_uint16 freq, kal_uint8 is_step_up)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_fmr_check_is_valid_stop_req(src_mod_id, freq, is_step_up);
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_fmr_get_signal_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mute            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_fmr_get_signal_level(module_type src_mod_id, kal_uint16 freq, kal_uint8 is_step_up)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_fmr_get_signal_level_req(src_mod_id, freq, is_step_up);
    return MED_RES_OK;
}
#endif /* __FM_RADIO_HW_SEARCH__ */


#ifdef __FM_RADIO_RDS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  media_aud_fmr_rds_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  af_enable       [IN]        
 *  tp_enable       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_fmr_rds_enable(module_type src_mod_id, kal_bool af_enable, kal_bool tp_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_fmr_rds_enable_req(src_mod_id, af_enable, tp_enable);
    aud_wait_event(AUD_EVT_WAIT);
    return MED_RES_OK;
}

/*****************************************************************************
 * FUNCTION
 *  media_aud_fmr_rds_disable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_fmr_rds_disable(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_fmr_rds_disable_req(src_mod_id);
    aud_wait_event(AUD_EVT_WAIT);
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_fmr_rds_poll_rds_event_rds
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_fmr_rds_poll_rds_event_rds(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_fmr_rds_poll_rds_event_rds(src_mod_id);
    aud_wait_event(AUD_EVT_WAIT);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_fmr_rds_set_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_fmr_rds_set_buffer(kal_uint16 *RT_Data, kal_uint16 *PS_Data, kal_uint16 *AF_Data, kal_uint16 *TP_Data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_fmr_rds_set_buffer(RT_Data, PS_Data, AF_Data, TP_Data);
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_fmr_rds_reset_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_fmr_rds_reset_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_fmr_rds_reset_buffer();
}

#endif /* __FM_RADIO_RDS_SUPPORT__ */

#ifdef __MED_MMA_MOD__
/********** MMA *****************/


/*****************************************************************************
 * FUNCTION
 *  mma_set_result
 * DESCRIPTION
 *  This function is set the mma status.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_set_result(kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mma_result = result;
    AUD_VALUE1_TRACE(result);
}


/*****************************************************************************
 * FUNCTION
 *  mma_set_handle
 * DESCRIPTION
 *  This function is set the mma media handle.
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_set_handle(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mma_handle = handle;
    AUD_VALUE1_TRACE(mma_handle);
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_open
 * DESCRIPTION
 *  This function is to open mma resource.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  param           [IN]        
 *  result          [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_mma_aud_open(module_type src_mod_id, mma_player_struct *param, kal_int32 *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_open_req((kal_int32) param);
    MMA_WAIT_EVENT(MMA_EVT_OPEN);
    *result = mma_result;
    return mma_handle;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_set_cache_table
 * DESCRIPTION
 *  This function is to set cache buffer to driver
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  param           [IN]        
 *  result          [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_mma_set_cache_table(module_type src_mod_id, kal_int32 handle, kal_uint8 *cache_tbl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_set_cache_table_req(handle, cache_tbl);
    MMA_WAIT_EVENT(MMA_EVT_WAIT);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_close
 * DESCRIPTION
 *  This function is to close midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_close(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_close_req(media_type, handle);
    MMA_WAIT_EVENT(MMA_EVT_CLOSE);
    return mma_result;
}

/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_set_param
 * DESCRIPTION
 *  This function is to set param to current handle
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  handle          [IN]        
 *  param_type      [IN]        
 *  param_value     [IN]
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_mma_aud_set_param(module_type src_mod_id, kal_int32 handle, kal_uint8 param_type, void* param_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    aud_send_mma_set_param_req(param_type, param_value, handle);

    return MED_RES_OK;
}

/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_play
 * DESCRIPTION
 *  This function is to play midi.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  handle          [IN]        
 *  media_type      [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_play(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GAIN_TABLE_SUPPORT__
    if (src_mod_id != MOD_MMI) /* Request that are not from MDI(e.g.JAVA) */
    {
        /* Notify MMI that MMA playback is started */
        aud_send_state_change_ind(AUD_STATE_CHANGE_MMA_PLAYBACK_START, (void*)media_type);
    }
#endif /* __GAIN_TABLE_SUPPORT__ */

    aud_send_mma_play_req(media_type, handle);

    if(!aud_mma_is_async_mode(handle))
    {
        MMA_WAIT_EVENT(MMA_EVT_PLAY);
        return mma_result;
    }
    else
    {
        return MED_RES_OK;
    }
}

/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_stop
 * DESCRIPTION
 *  This function is to stop midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_stop(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_stop_req(media_type, handle);

    if(!aud_mma_is_async_mode(handle))
    {
        MMA_WAIT_EVENT(MMA_EVT_STOP);
        return mma_result;
    }
    else
    {
        return MED_RES_OK;
    }

}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_pause
 * DESCRIPTION
 *  This function is to pause midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_pause(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_pause_req(media_type, handle);
    MMA_WAIT_EVENT(MMA_EVT_PAUSE);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_resume
 * DESCRIPTION
 *  This function is to resume midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_resume(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_resume_req(media_type, handle);
    MMA_WAIT_EVENT(MMA_EVT_RESUME);
    return mma_result;
}

/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_audio_info
 * DESCRIPTION
 *  This function is to get audio information
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  kal_int32 : Is get audio info success
 *****************************************************************************/
kal_int32 media_mma_aud_get_audio_info(module_type src_mod_id, kal_uint16 app_id, kal_wchar* file_path, kal_uint8 media_type, kal_uint8* data, kal_uint32 data_len, void *audio_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_get_audio_info_req(app_id, file_path, media_type, data, data_len, audio_info);
    MMA_WAIT_EVENT(MMA_EVT_GET_AUD_INFO);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_duration
 * DESCRIPTION
 *  This function is to get duration of audio from content description
 * PARAMETERS
 *  handle          [IN]        MMA handle
 *  media_type      [IN]        Media type
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_mma_aud_get_duration(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_get_duration_req(media_type, handle, KAL_FALSE);
    MMA_WAIT_EVENT(MMA_EVT_GET_DURATION);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_duration_by_handle
 * DESCRIPTION
 *  This function is to get duration of audio by using audio handler.
 * PARAMETERS
 *  src_mod_id      [IN]        Source module ID
 *  handle          [IN]        MMA handle
 * RETURNS
 *  Duration
 *****************************************************************************/
kal_int32 media_mma_aud_get_updated_duration(module_type src_mod_id, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_get_duration_req(MMA_NO_OF_AUDIO_TYPE, handle, KAL_TRUE);
    MMA_WAIT_EVENT(MMA_EVT_GET_DURATION);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_current_time
 * DESCRIPTION
 *  This function is to get current time of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_mma_aud_get_current_time(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_get_current_time_req(media_type, handle);
    MMA_WAIT_EVENT(MMA_EVT_GET_CURR_TIME);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_set_start_time
 * DESCRIPTION
 *  This function is to set start time of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  start_time      [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_set_start_time(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, kal_int32 start_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_set_start_time_req(media_type, handle, start_time);
    MMA_WAIT_EVENT(MMA_EVT_SET_START_TIME);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_set_stop_time
 * DESCRIPTION
 *  This function is to set stop time of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  stop_time       [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_set_stop_time(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, kal_int32 stop_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_set_stop_time_req(media_type, handle, stop_time);
    MMA_WAIT_EVENT(MMA_EVT_SET_STOP_TIME);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_volume
 * DESCRIPTION
 *  This function is to get volume of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
kal_uint8 media_mma_aud_get_volume(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_get_volume_req(media_type, handle);
    MMA_WAIT_EVENT(MMA_EVT_GET_VOLUME);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_set_volume
 * DESCRIPTION
 *  This function is to set volume of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  volume          [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_set_volume(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, kal_uint8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_set_volume_req(media_type, handle, volume);
    MMA_WAIT_EVENT(MMA_EVT_SET_VOLUME);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_pdl_write_data_ind
 * DESCRIPTION
 *  This function is to indicate MMA progressive download has wrtie more data.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  param           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_pdl_write_data_ind(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, kal_bool is_finish)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_pdl_write_data_ind_req(media_type, handle, is_finish);
    MMA_WAIT_EVENT(MMA_EVT_WRITE_DATA_IND);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_pdl_percent
 * DESCRIPTION
 *  This function is to get MMA progressive download buffer percentage
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  param           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_pdl_get_buf_percent(module_type src_mod_id, kal_int32 handle, kal_uint32 cache_sec, kal_uint32 *percent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_pdl_get_buf_percent_req(handle, cache_sec, percent);
    MMA_WAIT_EVENT(MMA_EVT_GET_PDL_PERCENT);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_med_data_type
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  mma_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int16 media_mma_aud_get_med_data_type(kal_uint8 mma_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return med_get_media_type_from_mma_type(mma_type);
}


#ifdef __MED_MMA_EXTRA_CTRL__
/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_pitch
 * DESCRIPTION
 *  This function is to get pitch of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_mma_aud_get_pitch(kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 pitch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    aud_send_mma_get_pitch_req(handle, media_type, &pitch);
    MMA_WAIT_EVENT(MMA_EVT_WAIT);
    return pitch;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_set_pitch
 * DESCRIPTION
 *  This function is to set pitch of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  pitch           [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_set_pitch(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, kal_int32 pitch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_set_pitch_req(media_type, handle, pitch);
    MMA_WAIT_EVENT(MMA_EVT_SET_PITCH);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_rate_range
 * DESCRIPTION
 *  This function is to get rate range for a given media type
 * PARAMETERS     
 *  media_type      [IN]        
 *  max_rate_p      [OUT]       Maximum rate
 *  min_rate_p      [OUT]       Mininum rate
 * RETURNS
 *  kal_int32
 *****************************************************************************/
void media_mma_aud_get_rate_range(kal_uint8 media_type, kal_int32* max_rate_p, kal_int32* min_rate_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_get_rate_range_req(media_type, max_rate_p, min_rate_p);
    MMA_WAIT_EVENT(MMA_EVT_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_rate
 * DESCRIPTION
 *  This function is to get rate of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_mma_aud_get_rate(kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 rate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_get_rate_req(handle, media_type, &rate);
    MMA_WAIT_EVENT(MMA_EVT_WAIT);
    return rate;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_set_rate
 * DESCRIPTION
 *  This function is to set rate of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  rate            [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_set_rate(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, kal_int32 rate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_set_rate_req(media_type, handle, rate);
    MMA_WAIT_EVENT(MMA_EVT_SET_RATE);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_tempo
 * DESCRIPTION
 *  This function is to get tempo of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_mma_aud_get_tempo(kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 tempo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_get_tempo_req(handle, media_type, &tempo);
    MMA_WAIT_EVENT(MMA_EVT_WAIT);
    return tempo;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_set_tempo
 * DESCRIPTION
 *  This function is to set tempo of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  tempo           [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_set_tempo(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, kal_int32 tempo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_set_tempo_req(media_type, handle, tempo);
    MMA_WAIT_EVENT(MMA_EVT_SET_TEMPO);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_open_device
 * DESCRIPTION
 *  This function is to open device of midi.
 * PARAMETERS
 *  media_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_open_device(module_type src_mod_id, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_open_device_req(media_type, KAL_FALSE);
    MMA_WAIT_EVENT(MMA_EVT_OPEN_DEVICE);
    return mma_handle;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_open_device_ext
 * DESCRIPTION
 *  This function is to open device of midi.
 * PARAMETERS
 *  media_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_open_device_ext(module_type src_mod_id, kal_uint8 media_type, kal_bool fast_pass)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_open_device_req(media_type, fast_pass);
    MMA_WAIT_EVENT(MMA_EVT_OPEN_DEVICE);
    return mma_handle;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_close_device
 * DESCRIPTION
 *  This function is to close device of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_mma_aud_close_device(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_close_device_req(media_type, handle);
    MMA_WAIT_EVENT(MMA_EVT_CLOSE_DEVICE);
    return mma_result;
}

/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_send_long_msg
 * DESCRIPTION
 *  This function is to send long msg of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  buf             [?]         kal_uint16 len
 *  len             [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_send_long_msg(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, kal_uint8 *buf, kal_uint16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_send_long_msg_req(media_type, handle, buf, len);
    MMA_WAIT_EVENT(MMA_EVT_SEND_LONG_MSG);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_send_short_msg
 * DESCRIPTION
 *  This function is to send short msg of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  type            [IN]        kal_uint8 data1, kal_uint8 data2
 *  data1           [IN]        
 *  data2           [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_send_short_msg(
            module_type src_mod_id, 
            kal_int32 handle,
            kal_uint8 media_type,
            kal_uint8 type,
            kal_uint8 data1,
            kal_uint8 data2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_send_short_msg_req(media_type, handle, type, data1, data2);
    MMA_WAIT_EVENT(MMA_EVT_SEND_SHORT_MSG);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_channel_volume
 * DESCRIPTION
 *  This function is to get channel volume of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  channel         [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
kal_uint8 media_mma_aud_get_channel_volume(kal_int32 handle, kal_uint8 media_type, kal_uint8 channel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 volume;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_get_channel_volume_req(handle, media_type, channel, &volume);
    MMA_WAIT_EVENT(MMA_EVT_WAIT);
    return volume;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_set_channel_volume
 * DESCRIPTION
 *  This function is to set channel volume of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  channel         [IN]        kal_uint8 level
 *  level           [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_set_channel_volume(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, kal_uint8 channel, kal_uint8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_set_channel_volume_req(media_type, handle, channel, level);
    MMA_WAIT_EVENT(MMA_EVT_SET_CHANNEL_VOLUME);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_program
 * DESCRIPTION
 *  This function is to get program of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  channel         [IN]        kal_int16* bank, kal_int8* program
 *  bank            [?]         
 *  program         [?]         
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
void media_mma_aud_get_program(
        kal_int32 handle,
        kal_uint8 media_type,
        kal_uint8 channel,
        kal_int16 *bank,
        kal_int8 *program)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_get_program_req(handle, media_type, channel, bank, program);
    MMA_WAIT_EVENT(MMA_EVT_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_set_program
 * DESCRIPTION
 *  This function is to set program of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  channel         [IN]        kal_uint8 bank, kal_uint8 program
 *  bank            [IN]        
 *  program         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_set_program(
            module_type src_mod_id, 
            kal_int32 handle,
            kal_uint8 media_type,
            kal_uint8 channel,
            kal_uint8 bank,
            kal_uint8 program)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_set_program_req(media_type, handle, channel, bank, program);
    MMA_WAIT_EVENT(MMA_EVT_SET_PROGRAM);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_bank_support
 * DESCRIPTION
 *  This function is to check if bank query supported.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool media_mma_aud_bank_support(kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_bank_support = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_get_is_bank_support_req(handle, media_type, &is_bank_support);
    MMA_WAIT_EVENT(MMA_EVT_WAIT);
    return is_bank_support;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_bank_list
 * DESCRIPTION
 *  This function is to get the bank list of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  custom          [IN]        const kal_int16 **buf, kal_int16 *len
 *  buf             [IN]        
 *  len             [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void media_mma_aud_get_bank_list(
        kal_int32 handle,
        kal_uint8 media_type,
        kal_bool custom,
        const kal_int16 **buf,
        kal_int16 *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_get_bank_list_req(handle, media_type, custom, buf, len);
    MMA_WAIT_EVENT(MMA_EVT_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_program_list
 * DESCRIPTION
 *  This function is to get the program list of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  bank            [IN]        const kal_int8 **buf, kal_int16 *len
 *  buf             [IN]        
 *  len             [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void media_mma_aud_get_program_list(
        kal_int32 handle,
        kal_uint8 media_type,
        kal_int16 bank,
        const kal_int8 **buf,
        kal_int16 *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_get_program_list_req(handle, media_type, bank, buf, len);
    MMA_WAIT_EVENT(MMA_EVT_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_program_name
 * DESCRIPTION
 *  This function is to get the program name of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  bank            [IN]        const kal_int8 **buf, kal_int16 *len
 *  prog            [IN]        
 * RETURNS
 *  const kal_uint8*
 *****************************************************************************/
const kal_uint8 *media_mma_aud_get_program_name(kal_int32 handle, kal_uint8 media_type, kal_int16 bank, kal_int8 prog)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8* name_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_get_program_name_req(handle, media_type, bank, prog, (const kal_uint8**)&name_p);
    MMA_WAIT_EVENT(MMA_EVT_WAIT);
    return (const kal_uint8*)name_p;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_key_name
 * DESCRIPTION
 *  This function is to get the key name of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  bank            [IN]        const kal_int8 **buf, kal_int16 *len
 *  prog            [IN]        
 *  key             [IN]        
 * RETURNS
 *  const kal_uint8*
 *****************************************************************************/
const kal_uint8 *media_mma_aud_get_key_name(
                    kal_int32 handle,
                    kal_uint8 media_type,
                    kal_int16 bank,
                    kal_int8 prog,
                    kal_int8 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8* name_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_get_program_name_req(handle, media_type, bank, prog, (const kal_uint8**)&name_p);
    MMA_WAIT_EVENT(MMA_EVT_WAIT);
    return (const kal_uint8*)name_p;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_is_sp_midi
 * DESCRIPTION
 *  This function is to check if the midi type is sp-midi
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_mma_aud_is_sp_midi(kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_sp_midi = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_get_is_sp_midi_req(handle, media_type, &is_sp_midi);
    MMA_WAIT_EVENT(MMA_EVT_WAIT);
    return is_sp_midi;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_set_data
 * DESCRIPTION
 *  This function is to set data of tone.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  param           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_set_data(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, mma_player_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_set_data_req(media_type, handle, (kal_int32) param);
    MMA_WAIT_EVENT(MMA_EVT_SET_DATA);
    return mma_result;
}
#endif /* __MED_MMA_EXTRA_CTRL__ */
#endif /* __MED_MMA_MOD__ */ 


#ifdef __MED_VR_MOD__


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_get_version
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vr_get_version(module_type src_mod_id, kal_uint8 mode, kal_uint8 lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vr_get_version_req(src_mod_id, mode, lang);
    VR_WAIT_EVENT(AUD_EVT_VR_GET_VER);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_get_param
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 *  sim             [?]         
 *  diff            [?]         
 *  rej             [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vr_get_param(
            module_type src_mod_id,
            kal_uint8 mode,
            kal_uint8 lang,
            kal_int16 *sim,
            kal_int16 *diff,
            kal_int16 *rej)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vr_get_param_req(src_mod_id, mode, lang, sim, diff, rej);
    VR_WAIT_EVENT(AUD_EVT_VR_GET_PARAM);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_set_param
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 *  sim             [IN]        
 *  diff            [IN]        
 *  rej             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vr_set_param(
            module_type src_mod_id,
            kal_uint8 mode,
            kal_uint8 lang,
            kal_int16 sim,
            kal_int16 diff,
            kal_int16 rej)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vr_set_param_req(src_mod_id, mode, lang, sim, diff, rej);
    VR_WAIT_EVENT(AUD_EVT_VR_SET_PARAM);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_init_rcg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 *  group_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vr_init_rcg(
            module_type src_mod_id,
            kal_uint32 session_id,
            kal_uint8 mode,
            kal_uint8 lang,
            kal_uint8 group_id,
            kal_uint16 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vr_init_rcg_req(src_mod_id, session_id, mode, lang, group_id, app_id);
    VR_WAIT_EVENT(AUD_EVT_VR_INIT_RCG);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_init_trn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 *  group_id        [IN]        
 *  word_id         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vr_init_trn(
            module_type src_mod_id,
            kal_uint32 session_id,
            kal_uint8 mode,
            kal_uint8 lang,
            kal_uint8 group_id,
            kal_uint16 word_id,
            kal_uint16 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vr_init_trn_req(src_mod_id, session_id, mode, lang, group_id, word_id, app_id);
    VR_WAIT_EVENT(AUD_EVT_VR_INIT_TRN);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_voice_in
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 *  seq_no          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vr_voice_in(module_type src_mod_id, kal_uint32 session_id, kal_uint8 seq_no)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vr_voice_in_req(src_mod_id, session_id, seq_no);
    VR_WAIT_EVENT(AUD_EVT_VR_VOICE_IN);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_del_tag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 *  group_id        [IN]        
 *  word_id         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vr_del_tag(
            module_type src_mod_id,
            kal_uint8 mode,
            kal_uint8 lang,
            kal_uint8 group_id,
            kal_uint16 word_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vr_del_tag_req(src_mod_id, mode, lang, group_id, word_id);
    VR_WAIT_EVENT(AUD_EVT_VR_DEL_TAG);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_check_tag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 *  group_id        [IN]        
 *  word_id         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vr_check_tag(
            module_type src_mod_id,
            kal_uint8 mode,
            kal_uint8 lang,
            kal_uint8 group_id,
            kal_uint16 word_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vr_check_tag_req(src_mod_id, mode, lang, group_id, word_id);
    VR_WAIT_EVENT(AUD_EVT_VR_CHECK_TAG);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_sync_db
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 *  group_id        [IN]        
 *  id_length_p     [?]         
 *  id_array        [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vr_sync_db(
            module_type src_mod_id,
            kal_uint8 mode,
            kal_uint8 lang,
            kal_uint8 group_id,
            kal_uint16 *id_length_p,
            kal_uint16 *id_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vr_sync_db_req(src_mod_id, mode, lang, group_id, id_length_p, id_array);
    VR_WAIT_EVENT(AUD_EVT_VR_SYNC_DB);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_play_tag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 *  group_id        [IN]        
 *  word_id         [IN]        
 *  identifier      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vr_play_tag(
            module_type src_mod_id,
            kal_uint8 mode,
            kal_uint8 lang,
            kal_uint8 group_id,
            kal_uint16 word_id,
            kal_uint16 identifier)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vr_play_tag_req(src_mod_id, mode, lang, group_id, word_id, identifier);
    VR_WAIT_EVENT(AUD_EVT_VR_PLAY_TAG);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_get_dir
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 *  group_id        [IN]        
 *  folder_name     [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vr_get_dir(
            module_type src_mod_id,
            kal_uint8 mode,
            kal_uint8 lang,
            kal_uint8 group_id,
            kal_uint16 *folder_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vr_get_dir_req(src_mod_id, mode, lang, group_id, folder_name);
    VR_WAIT_EVENT(AUD_EVT_VR_GET_DIR);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_add_tag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 *  group_id        [IN]        
 *  id_length       [IN]        
 *  id_array        [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vr_add_tag(
            module_type src_mod_id,
            kal_uint8 mode,
            kal_uint8 lang,
            kal_uint8 group_id,
            kal_uint16 id_length,
            kal_uint16 *id_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vr_add_tag_req(src_mod_id, mode, lang, group_id, id_length, id_array);
    VR_WAIT_EVENT(AUD_EVT_VR_ADD_TAG);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_abort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_vr_abort(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vr_abort_req(src_mod_id);
    VR_WAIT_EVENT(AUD_EVT_VR_ABORT);
}
#endif /* __MED_VR_MOD__ */ 

#ifdef __MED_VRSI_MOD__


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_init(module_type src_mod_id, kal_uint16 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_init_req(src_mod_id, app_id);
    VR_WAIT_EVENT(VRSI_EVT_INIT);
    return aud_result;
}

/* kal_uint32 media_aud_vrsi_new_session_id(void); */


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_add_tags
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  session_id          [IN]        
 *  grammar             [?]         
 *  tag_num             [IN]        
 *  name_list           [IN]        
 *  long_list           [?]         
 *  is_name_list        [?]         
 *  id_list             [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_add_tags(
            module_type src_mod_id,
            kal_uint32 session_id,
            kal_uint8 *grammar,
            kal_uint16 tag_num,
            kal_uint16 **name_list,
            kal_int32 *long_list,
            kal_uint8 *is_name_list,
            kal_uint16 *id_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_add_tags_req(src_mod_id, session_id, grammar, tag_num, name_list, long_list, is_name_list, id_list);
    VR_WAIT_EVENT(VRSI_EVT_ADD_TAGS);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_start_cmd_trn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 *  grammar         [?]         
 *  tag_name        [?]         
 *  tag_long        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_start_cmd_trn(
            module_type src_mod_id,
            kal_uint32 session_id,
            kal_uint8 *grammar,
            kal_uint16 *tag_name,
            kal_int32 tag_long)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_start_cmd_trn_req(src_mod_id, session_id, grammar, tag_name, tag_long);
    VR_WAIT_EVENT(VRSI_EVT_START_CMD_TRN);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_start_cmd_rcg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 *  grammar         [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_start_cmd_rcg(module_type src_mod_id, kal_uint32 session_id, kal_uint8 *grammar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_start_cmd_rcg_req(src_mod_id, session_id, grammar);
    VR_WAIT_EVENT(VRSI_EVT_START_CMD_RCG);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_start_digit_rcg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 *  lang            [IN]        
 *  limit           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_start_digit_rcg(
            module_type src_mod_id,
            kal_uint32 session_id,
            kal_uint8 lang,
            kal_uint16 limit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_start_digit_rcg_req(src_mod_id, session_id, lang, limit);
    VR_WAIT_EVENT(VRSI_EVT_START_DIGIT_RCG);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_start_digit_adapt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 *  lang            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_start_digit_adapt(module_type src_mod_id, kal_uint32 session_id, kal_uint8 lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_start_digit_adapt_req(src_mod_id, session_id, lang);
    VR_WAIT_EVENT(VRSI_EVT_START_DIGIT_ADAPT);
    return aud_result;
}

/* void media_aud_vrsi_prompt_cnf(module_type src_mod_id, kal_uint32 session_id); */


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_play_tag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 *  grammar         [?]         
 *  tag_id          [IN]        
 *  volume          [IN]        
 *  output_path     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_play_tag(
            module_type src_mod_id,
            kal_uint32 session_id,
            kal_uint8 *grammar,
            kal_uint16 tag_id,
            kal_uint8 volume,
            kal_uint8 output_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_play_tag_req(src_mod_id, session_id, grammar, tag_id, volume, output_path);
    VR_WAIT_EVENT(VRSI_EVT_PLAY_TAG);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_play_TTS
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 *  text            [?]         
 *  volume          [IN]        
 *  output_path     [IN]        
 *  lang            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_play_TTS(
            module_type src_mod_id,
            kal_uint32 session_id,
            kal_uint16 *text,
            kal_uint8 volume,
            kal_uint8 output_path,
            kal_uint8 lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_play_TTS_req(src_mod_id, session_id, text, volume, output_path, lang);
    VR_WAIT_EVENT(VRSI_EVT_PLAY_TTS);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_get_tag_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  grammar         [?]         
 *  tag_num         [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_get_tag_num(module_type src_mod_id, kal_uint8 *grammar, kal_int32 *tag_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_get_tag_num_req(src_mod_id, grammar, tag_num);
    VR_WAIT_EVENT(VRSI_EVT_GET_TAG_NUM);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_get_tag_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  grammar         [?]         
 *  tag_num         [IN]        
 *  id_list         [?]         
 *  name_list       [IN]        
 *  long_list       [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_get_tag_info(
            module_type src_mod_id,
            kal_uint8 *grammar,
            kal_int32 tag_num,
            kal_uint16 *id_list,
            kal_uint16 **name_list,
            kal_int32 *long_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_get_tag_info_req(src_mod_id, grammar, tag_num, id_list, name_list, long_list);
    VR_WAIT_EVENT(VRSI_EVT_GET_TAG_INFO);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_del_tags
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  grammar         [?]         
 *  tag_num         [IN]        
 *  id_list         [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_del_tags(module_type src_mod_id, kal_uint8 *grammar, kal_int32 tag_num, kal_uint16 *id_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_del_tags_req(src_mod_id, grammar, tag_num, id_list);
    VR_WAIT_EVENT(VRSI_EVT_DEL_TAGS);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_reset_tags
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  grammar         [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_reset_tags(module_type src_mod_id, kal_uint8 *grammar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_reset_tags_req(src_mod_id, grammar);
    VR_WAIT_EVENT(VRSI_EVT_RESET_TAGS);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_sync_db
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  grammar         [?]         
 *  tag_num         [IN]        
 *  id_list         [?]         
 *  name_list       [IN]        
 *  sync_flag       [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_sync_db(
            module_type src_mod_id,
            kal_uint8 *grammar,
            kal_int32 tag_num,
            kal_uint16 *id_list,
            kal_uint16 **name_list,
            kal_uint8 *sync_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_sync_db_req(src_mod_id, grammar, tag_num, id_list, name_list, sync_flag);
    VR_WAIT_EVENT(VRSI_EVT_SYNC_DB);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_abort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_vrsi_abort(module_type src_mod_id, kal_uint32 session_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_abort_req(src_mod_id, session_id);
    VR_WAIT_EVENT(VRSI_EVT_ABORT);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_vrsi_close(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_close_req(src_mod_id);
    VR_WAIT_EVENT(VRSI_EVT_CLOSE);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_get_error_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_get_error_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return aud_vrsi_error();
}
#endif /* __MED_VRSI_MOD__ */ 

#ifdef __MED_SND_MOD__


/*****************************************************************************
 * FUNCTION
 *  aud_snd_set_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_snd_set_result(kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bgsnd_result = result;
    AUD_VALUE1_TRACE(result);
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_snd_check_byte_stream_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [?]         
 *  size            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_snd_check_byte_stream_format(module_type src_mod_id, kal_uint8 *data, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_snd_set_result(MED_RES_OK);
    aud_send_snd_check_byte_stream_format_req(src_mod_id, data, size);

    EFFECT_WAIT_EVENT(SND_EVT_CHECK);
    return bgsnd_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_snd_check_file_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  file_name       [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_snd_check_file_format(module_type src_mod_id, kal_wchar *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_snd_set_result(MED_RES_OK);
    aud_send_snd_check_file_format_req(src_mod_id, file_name);

    EFFECT_WAIT_EVENT(SND_EVT_CHECK);
    return bgsnd_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_snd_play_byte_stream
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [?]         
 *  size            [IN]        
 *  repeats         [IN]        
 *  volume          [IN]        
 *  output_path     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_snd_play_byte_stream(
            module_type src_mod_id,
            kal_uint8 *data,
            kal_int32 size,
            kal_int16 repeats,
            kal_uint8 format,
            kal_uint8 volume,
            kal_uint8 output_path,
            kal_uint16 idenfifier)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_snd_play_byte_stream_req(src_mod_id, data, size, repeats, format, volume, output_path, idenfifier);

    EFFECT_WAIT_EVENT(SND_EVT_PLAY);
    return bgsnd_result;

}


/*****************************************************************************
 * FUNCTION
 *  media_aud_snd_play_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  file_name       [?]         
 *  repeats         [IN]        
 *  volume          [IN]        
 *  output_path     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_snd_play_file(
            module_type src_mod_id,
            kal_wchar *file_name,
            kal_int16 repeats,
            kal_uint8 volume,
            kal_uint8 output_path,
            kal_uint16 identifier)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_snd_play_file_req(src_mod_id, file_name, repeats, volume, output_path, identifier);

    EFFECT_WAIT_EVENT(SND_EVT_PLAY);
    return bgsnd_result;

}


/*****************************************************************************
 * FUNCTION
 *  media_aud_snd_stop_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_snd_stop_play(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_snd_stop_play_req(src_mod_id);

    EFFECT_WAIT_EVENT(SND_EVT_STOP);
    return bgsnd_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_snd_set_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  volume          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_snd_set_volume(module_type src_mod_id, kal_uint8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_snd_set_volume_req(src_mod_id, volume);

    EFFECT_WAIT_EVENT(SND_EVT_SET);
    return bgsnd_result;
}

#endif /* __MED_SND_MOD__ */ 


#if defined(__MED_AUD_AUDIO_EFFECT__)
/*****************************************************************************
 * FUNCTION
 *  aud_app_set_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_app_set_result(kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    audio_effect_result = result;
    AUD_VALUE1_TRACE(result);
}
#endif /*#if defined(__MED_AUD_AUDIO_EFFECT__)*/


#if defined(__MED___BES_TS_SUPPORT____)
/*****************************************************************************
 * FUNCTION
 *  media_stretch_check_stream_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [?]         
 *  size            [IN]        
 *  format          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_stretch_check_stream_format(
            module_type src_mod_id,
            kal_uint8 *data,
            kal_uint32 size,
            kal_uint16 format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_stretch_check_stream_format_req_struct *msg_p = (media_stretch_check_stream_format_req_struct*)
        construct_local_para(sizeof(media_stretch_check_stream_format_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->data_p = data;
    msg_p->size = size;
    msg_p->format = format;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_AUD_STRETCH_CHECK_STREAM_FORMAT_REQ, msg_p);

    EFFECT_WAIT_EVENT(TS_EVT_CHECK);
    return audio_effect_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_stretch_check_file_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  file_path       [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_stretch_check_file_format(module_type src_mod_id, kal_wchar *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_stretch_check_file_format_req_struct *msg_p = (media_stretch_check_file_format_req_struct*)
        construct_local_para(sizeof(media_stretch_check_file_format_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->file_path = file_path;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_AUD_STRETCH_CHECK_FILE_FORMAT_REQ, msg_p);

    EFFECT_WAIT_EVENT(TS_EVT_CHECK);
    return audio_effect_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_stretch_set_speed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  speed           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_stretch_set_speed(module_type src_mod_id, kal_uint16 speed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_stretch_set_speed_req_struct *msg_p = (media_stretch_set_speed_req_struct*)
        construct_local_para(sizeof(media_stretch_set_speed_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->speed = speed;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_AUD_STRETCH_SET_SPEED_REQ, msg_p);

    EFFECT_WAIT_EVENT(TS_EVT_SET);
    return audio_effect_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_stretch_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_stretch_close(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_AUD_STRETCH_CLOSE_REQ, NULL);

    EFFECT_WAIT_EVENT(TS_EVT_CLOSE);
    return audio_effect_result;
}
#endif /* #if defined(__MED___BES_TS_SUPPORT____) */


#if defined(__MED___BES_LIVE_SUPPORT____)
/*****************************************************************************
 * FUNCTION
 *  media_aud_reverb_set_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  mode     [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_reverb_set_mode(kal_uint16 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_reverb_set_mode_req_struct *msg_p = (media_reverb_set_mode_req_struct*)
        construct_local_para(sizeof(media_reverb_set_mode_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->mode = mode;

    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA___BES_LIVE_SUPPORT___SET_MODE_REQ, msg_p);

    EFFECT_WAIT_EVENT(REVERB_EVT_SET);
    return audio_effect_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_reverb_turn_on_effect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_reverb_turn_on_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA___BES_LIVE_SUPPORT___TURN_ON_REQ, NULL);

    EFFECT_WAIT_EVENT(REVERB_EVT_ON);
    return audio_effect_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_reverb_turn_off_effect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_reverb_turn_off_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA___BES_LIVE_SUPPORT___TURN_OFF_REQ, NULL);

    EFFECT_WAIT_EVENT(REVERB_EVT_OFF);
    return audio_effect_result;
}
#endif /* #if defined(__MED___BES_LIVE_SUPPORT____) */ 

#if defined(__MED_AUD_SURROUND__)
/*****************************************************************************
 * FUNCTION
 *  media_aud_surround_turn_on_effect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_surround_turn_on_effect(kal_uint8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_surround_turn_on_req_struct *msg_p = (media_surround_turn_on_req_struct*)
        construct_local_para(sizeof(media_surround_turn_on_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->mode= mode;

    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_AUD_SURROUND_TURN_ON_REQ, msg_p);

    EFFECT_WAIT_EVENT(SURROUND_EVT_ON);
    return audio_effect_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_surround_turn_off_effect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_surround_turn_off_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_AUD_SURROUND_TURN_OFF_REQ, NULL);

    EFFECT_WAIT_EVENT(SURROUND_EVT_OFF);
    return audio_effect_result;
}
#endif /* #if defined(__MED_AUD_SURROUND__) */


#if defined(__MED_AUD_EQUALIZER__)
/*****************************************************************************
 * FUNCTION
 *  media_aud_eq_set_magnitude
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  coeff_table_ptr     [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_eq_set_magnitude(kal_int8 *magnitude)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_eq_set_magnitude_req_struct *msg_p = (media_aud_eq_set_magnitude_req_struct*)
        construct_local_para(sizeof(media_aud_eq_set_magnitude_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(msg_p->magnitude, magnitude, NVRAM_EF_AUDIO_EQUALIZER_BAND_NUM);

    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_AUD_EQ_SET_MAGNITUDE_REQ, msg_p);

    EFFECT_WAIT_EVENT(EQ_EVT_SET);
    return audio_effect_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_reverb_turn_on_effect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_eq_turn_on_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_AUD_EQ_TURN_ON_REQ, NULL);

    EFFECT_WAIT_EVENT(EQ_EVT_ON);
    return audio_effect_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_reverb_turn_off_effect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_eq_turn_off_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_AUD_EQ_TURN_OFF_REQ, NULL);

    EFFECT_WAIT_EVENT(EQ_EVT_OFF);
    return audio_effect_result;
}
#endif /* #if defined(__MED_AUD_EQUALIZER__) */ 


#if defined(__MED_AUD_BASS_ENHANCE__)
/*****************************************************************************
 * FUNCTION
 *  media_aud_bass_enhance_turn_on_effect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_bass_enhance_turn_on_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_AUD_BASS_ENHANCE_TURN_ON_REQ, NULL);

    EFFECT_WAIT_EVENT(AUD_PP_EVT_WAIT);
    return audio_effect_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_bass_enhance_turn_off_effect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_bass_enhance_turn_off_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_AUD_BASS_ENHANCE_TURN_OFF_REQ, NULL);

    EFFECT_WAIT_EVENT(AUD_PP_EVT_WAIT);
    return audio_effect_result;
}
#endif /* #if defined(__MED_AUD_BASS_ENHANCE__) */


#if defined(__MED_AUD_LOUDNESS__)
/*****************************************************************************
 * FUNCTION
 *  media_aud_loudness_turn_on_effect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_loudness_turn_on_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_AUD_LOUDNESS_TURN_ON_REQ, NULL);

    EFFECT_WAIT_EVENT(AUD_PP_EVT_WAIT);
    return audio_effect_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_loudness_turn_off_effect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_loudness_turn_off_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_AUD_LOUDNESS_TURN_OFF_REQ, NULL);

    EFFECT_WAIT_EVENT(AUD_PP_EVT_WAIT);
    return audio_effect_result;
}
#endif /* #if defined(__MED_AUD_LOUDNESS__) */


#ifdef __MED_GENERAL_TTS__
/*****************************************************************************
 * FUNCTION
 *  media_aud_tts_set_attr_req()
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_tts_set_attr_req(module_type src_mod_id, kal_uint32 attr_id, kal_uint32 attr_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_tts_set_attr_req(src_mod_id, attr_id, attr_value);
    TTS_WAIT_EVENT(TTS_EVT_SET_ATTR);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_tts_play_req()
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_tts_play_req(module_type src_mod_id, void *tts_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_tts_play_req(src_mod_id, tts_param);
    TTS_WAIT_EVENT(TTS_EVT_PLAY);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_tts_stop_req()
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_tts_stop_req(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_AUD_TTS_STOP_REQ, NULL);

    TTS_WAIT_EVENT(TTS_EVT_STOP);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_tts_pause_req()
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_tts_pause_req(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_AUD_TTS_PAUSE_REQ, NULL);

    TTS_WAIT_EVENT(TTS_EVT_PAUSE);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_tts_resume_req()
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_tts_resume_req(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_AUD_TTS_RESUME_REQ, NULL);

    TTS_WAIT_EVENT(TTS_EVT_RESUME);
    return aud_result;
}
#endif /*#ifdef __MED_GENERAL_TTS__*/

#ifdef __KEY_TONE_DETECTION__
/*****************************************************************************
 * FUNCTION
 *  media_aud_start_keytone_detect_req()
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_start_keytone_detect_req(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_AUD_KT_START_DETECT, NULL);
    aud_wait_event(AUD_EVT_START_KT_DETECT);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_stop_keytone_detect_req()
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
void media_aud_stop_keytone_detect_req(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_AUD_KT_STOP_DETECT, NULL);
    aud_wait_event(AUD_EVT_STOP_KT_DETECT);
}
#endif /*__KEY_TONE_DETECTION__*/


#ifdef __MED_BT_MOD__
/*****************************************************************************
 * FUNCTION
 *  media_aud_bt_audio_close
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
void media_aud_bt_audio_close(kal_uint8 profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_bt_audio_close_req(profile);

    aud_wait_event(AUD_EVT_BT_CLOSE_AUDIO);
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_bt_audio_close
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
void media_aud_bt_turn_off_audio(kal_uint8 profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_bt_audio_turn_off_req(profile);

    aud_wait_event(AUD_EVT_BT_TURN_OFF_AUDIO);
}
#endif /*#ifdef __MED_BT_MOD__*/


#ifdef __AUDIO_TRIM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  media_aud_trim_open
 * DESCRIPTION
 *  This function is to open a trimming handle
 * PARAMETERS
 *  file_name_in        [IN]    The file to be trimmed from.
 *  file_name_out       [IN]    The file to be trimmed to.
 *  handle_p            [OUT]   Trimming handle
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_aud_trim_open(kal_wchar* file_name_in, kal_wchar* file_name_out, kal_uint32* handle_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_trim_open_req(file_name_in, file_name_out, handle_p);
    aud_wait_event(AUD_EVT_WAIT);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_trim_close
 * DESCRIPTION
 *  This function is to close a trimming handle
 * PARAMETERS
 *  handle            [IN]   Trimming handle
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_aud_trim_close(kal_uint32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_trim_close_req(handle);
    aud_wait_event(AUD_EVT_WAIT);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_trim_start
 * DESCRIPTION
 *  This function is to start the trimming
 * PARAMETERS
 *  handle            [IN]   Trimming handle
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_aud_trim_start(kal_uint32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_trim_start_req(handle);
    aud_wait_event(AUD_EVT_WAIT);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_trim_stop
 * DESCRIPTION
 *  This function is to stop the trimming.
 * PARAMETERS
 *  handle            [IN]   Trimming handle
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_aud_trim_stop(kal_uint32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_trim_stop_req(handle);
    aud_wait_event(AUD_EVT_WAIT);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_set_param
 * DESCRIPTION
 *  This function is to set a request to set parameters of a given trimming handle.
 * PARAMETERS
 *  handle          [IN]    Trimming handle
 *  set_type        [IN]    The type to be set.
 *  data_p          [IN]    The data to be set.
 *  data_len        [IN]    The length of the data.
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_trim_set_param(kal_int32 handle, kal_uint8 set_type, void* data_p, kal_uint16 data_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_trim_set_param_req(handle, set_type, data_p, data_len);
    aud_wait_event(AUD_EVT_WAIT);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_trim_get_param_req
 * DESCRIPTION
 *  This function is to set a request to get parameters of a given trimming handle.
 * PARAMETERS
 *  handle          [IN]    Trimming handle
 *  get_type        [IN]    The type to be get.
 *  data_p          [OUT]   The data that store the result.
 *  data_len_p      [OUT]   The length of the data.
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_trim_get_param(kal_int32 handle, kal_uint8 get_type, void* data_p, kal_uint16* data_len_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_trim_get_param_req(handle, get_type, data_p, data_len_p);
    aud_wait_event(AUD_EVT_WAIT);
    return aud_result;
}
#endif /* __AUDIO_TRIM_SUPPORT__ */

#endif /* MED_NOT_PRESENT */ 

