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
 *   aud_main.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary functions of audio manager task.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "audio_nvram_def.h"
//#include "custom_nvram_editor_data_item.h"
#include "nvram_interface.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
//#include "med_api.h"
#include "med_context.h"
//#include "med_main.h"
#include "aud_main.h"
#include "aud_input_stream.h"

#include "aud_daf_parser.h"

#include "kal_general_types.h"
#include "kal_public_api.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#include "mpl_player.h"


aud_context_struct *aud_context_p = &(med_context.aud_context);

/* ring buffer for VM recording/playback or DAF playing */
/*kal_uint16 ring_buffer[AUD_RING_BUFFER_LEN];*/

#ifdef __MED_BT_MOD__
extern kal_bool aud_bt_main(ilm_struct *ilm_ptr);
extern void aud_bt_init(void);
#endif /* __MED_BT_MOD__ */

/*****************************************************************************
 * FUNCTION
 *  aud_enter_state
 * DESCRIPTION
 *  This function is to log audio state transition
 * PARAMETERS
 *   
 * RETURNS
 *  void
 *****************************************************************************/
void aud_enter_state(kal_uint8 aud_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  

    AUD_STATE_TRACE(aud_state);
    aud_context_p->state = aud_state;

}


/*****************************************************************************
 * FUNCTION
 *  aud_startup_hdlr
 * DESCRIPTION
 *  This function is handle startup procedure of audio module.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_startup_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    aud_context_p->src_mod = ilm_ptr->src_mod_id;

#if defined( __MED_MMA_MOD__)&&(!defined(__MED_SLIM_MMA__))
    aud_mma_startup();
#endif 

#ifdef __MED_VR_MOD__
    aud_vr_startup();
#endif 

#ifdef __MED_VRSI_MOD__
    aud_vrsi_startup();
#endif 

    /* Initialize background sound effect */
#ifdef __MED_SND_MOD__
    aud_snd_startup();
#endif 

    /* Initialize audio post process */
#if defined(__MED_AUD_AUDIO_EFFECT__)
    aud_post_process_startup();
#endif 

#ifdef __MED_GENERAL_TTS__
    aud_tts_startup();
#endif 
#if defined (__MED_FMR_MOD__) && defined (__FM_RADIO_RDS_SUPPORT__)
    aud_fmr_rds_init();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  aud_startup_read_nvram_data
 * DESCRIPTION
 *  This function is to read audio nvram data when startup.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_startup_read_nvram_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_STARTUP_READ_NVRAM_DATA);

    med_context_p->nvram_state = MED_POWERON_READING_NVRAM;
    aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_CUST_ACOUSTIC_DATA_LID, 0, 0);
}


/*****************************************************************************
 * FUNCTION
 *  aud_main
 * DESCRIPTION
 *  This function is main message dispatching function of audio module.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

/* The following message is not use in MODEM project */
#ifndef MED_MODEM
#ifdef __MED_BT_MOD__
    if (aud_bt_main(ilm_ptr))
    {
        return;
    }
#endif /* __MED_BT_MOD__ */ 

#endif /* MED_MODEM */

#ifdef __MED_ECALL_MOD__
    if (ilm_ptr->msg_id >= MSG_ID_MEDIA_AUD_EMSD_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MEDIA_AUD_EMSD_CODE_END)
    {
        aud_ecall_main(ilm_ptr);
        return;
    }
#endif /*__MED_ECALL_MOD__*/


    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_L4AUD_GET_AUDIO_MODE_REQ:
            break;
        case MSG_ID_MEDIA_AUD_SET_AUDIO_MODE_REQ:
            aud_set_audio_mode_req_hdlr(ilm_ptr);
            break;    
	#if defined (__CLASSAB_VOLUME_PROTECTION__) || defined (__CLASSK_CP_SUPPORT__)  
        case MSG_ID_L4AUD_BATTERY_VOLTAGE_IND:
            aud_battery_voltage_ind_hdlr(ilm_ptr);
            break;    
	#endif /* defined (__CLASSAB_VOLUME_PROTECTION__) || defined (__CLASSK_CP_SUPPORT__) */    
        case MSG_ID_MEDIA_AUD_GET_AUDIO_PROFILE_REQ:
            aud_get_audio_profile_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_SET_AUDIO_PROFILE_REQ:
            aud_set_audio_profile_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_GET_AUDIO_PARAM_REQ:
            aud_get_audio_param_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_SET_AUDIO_PARAM_REQ:
            aud_set_audio_param_req_hdlr(ilm_ptr);
            break;
    #ifdef __AMRWB_LINK_SUPPORT__
        case MSG_ID_MEDIA_AUD_GET_AUDIO_WB_INPUT_FIR_PARAM_REQ:
            aud_get_audio_wb_input_fir_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_GET_AUDIO_WB_OUTPUT_FIR_PARAM_REQ:
            aud_get_audio_wb_output_fir_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_GET_AUDIO_WB_MODE_PARAM_REQ:
            aud_get_audio_wb_mode_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_SET_AUDIO_WB_INPUT_FIR_PARAM_REQ:
            aud_set_audio_wb_input_fir_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_SET_AUDIO_WB_OUTPUT_FIR_PARAM_REQ:
            aud_set_audio_wb_output_fir_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_SET_AUDIO_WB_MODE_PARAM_REQ:
            aud_set_audio_wb_mode_req_hdlr(ilm_ptr);
            break;
    #endif
	#ifdef __AUDIO_AT_CMD__
		case MSG_ID_MEDIA_AUD_SET_AT_AUDIO_SPEECH_INFO_REQ:
			aud_set_speech_info_req_hdlr(ilm_ptr);
			break;
	#endif

        case MSG_ID_L4AUD_SP_SET_INPUT_MODE_REQ:
            break;
        case MSG_ID_MEDIA_AUD_SP_SET_MODE_REQ:
            aud_speech_set_mode_req_hdlr(ilm_ptr);
            break;    
			
#ifdef __VOICE_CHANGER_SUPPORT__
		case MSG_ID_MEDIA_SET_VOICE_CHANGER_MODE_REQ:
            aud_speech_set_voice_changer_mode_req_hdlr(ilm_ptr);
            break;
#endif

#ifdef __LINE_IN_SUPPORT__
		case MSG_ID_MEDIA_ENABLE_BT_BOX_LINEIN_REQ:
			aud_enable_bt_box_linein_req_hdlr(ilm_ptr);
			break;
		case MSG_ID_MEDIA_FORCE_USE_LINEIN_MIC_REQ:
			aud_force_use_linein_mic_req_hdlr(ilm_ptr);
			break;
#endif

	#ifdef __MED_MEGA_PHONE__
		case MSG_ID_MEDIA_ENABLE_MEGAPHONE_REQ:
			aud_speech_enable_megaphone_req_hdlr(ilm_ptr);
			break;
	#endif

#ifdef __KARAOKE_SUPPORT__
		case MSG_ID_MEDIA_SET_KARAOKE_MODE_REQ:
			aud_set_karaoke_mode_req_hdlr(ilm_ptr);
			break;
		case MSG_ID_MEDIA_SET_KARAOKE_CHANNEL_REQ:
			aud_set_karaoke_channel_req_hdlr(ilm_ptr);
			break;
		case MSG_ID_MEDIA_SET_KARAOKE_DIGITGAIN_REQ:
			aud_set_karaoke_digitgain_req_hdlr(ilm_ptr);
			break;
#ifdef __KARAOKE_NEED_KEEP_SRC_PATH__
		case MSG_ID_MEDIA_KARAOKE_REMIX_TURN_ON_REQ:
			aud_karaoke_remix_turn_on_req_hdlr(ilm_ptr);
			break;
		case MSG_ID_MEDIA_KARAOKE_REMIX_TURN_OFF_REQ:
			aud_karaoke_remix_turn_off_req_hdlr(ilm_ptr);
			break;
		case MSG_ID_MEDIA_KARAOKE_SET_REMIX_MODE_REQ:
			aud_karaoke_set_remix_mode_req_hdlr(ilm_ptr);
			break;
		case MSG_ID_MEDIA_KARAOKE_SET_REMIX_AUDIO_GAIN_REQ:
			aud_karaoke_set_remix_audio_gain_req_hdlr(ilm_ptr);
			break;
		case MSG_ID_MEDIA_KARAOKE_SET_REMIX_VOICE_GAIN_REQ:
			aud_karaoke_set_remix_voice_gain_req_hdlr(ilm_ptr);
			break;
#endif

#endif

#ifdef __VAD_SUPPORT__
		case MSG_ID_MEDIA_SET_VAD_LEVEL_REQ:
			aud_set_vad_level_req_hdlr(ilm_ptr);
			break;
		case MSG_ID_MEDIA_SWITCH_VAD_ON_OFF_REQ:
			aud_switch_vad_on_off_req_hdlr(ilm_ptr);
			break;
#endif

        case MSG_ID_MEDIA_AUD_SP_SET_FIR_COEFF_REQ:
        #ifdef __GAIN_TABLE_SUPPORT__ 
            aud_speech_set_fir_coeff_req_hdlr(ilm_ptr);
        #endif
            break;
        case MSG_ID_MEDIA_AUD_SP_SET_ENHANCE_MODE_REQ:
            aud_speech_set_enhance_mode_req_hdlr(ilm_ptr);
            break;
    #ifdef __DUAL_MIC_SUPPORT__
        case MSG_ID_L4AUD_MIC_SET_DUAL_NR_REQ:
            aud_mic_set_dual_nr_req_hdlr(ilm_ptr);
            break;
    #endif /* __DUAL_MIC_SUPPORT__ */
        case MSG_ID_L4AUD_AUDIO_SET_FIR_REQ:
            break;
        case MSG_ID_MEDIA_AUD_SET_DEVICE_REQ:
            aud_audio_set_device_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_AUDIO_GET_MAX_VOLUME_LEVEL_IN_SYNC_REQ:
            break;
        case MSG_ID_L4AUD_AUDIO_GET_MAX_VOLUME_LEVEL_REQ:
            break;
        case MSG_ID_L4AUD_AUDIO_SET_MAX_VOLUME_LEVEL_REQ:
            break;
        case MSG_ID_L4AUD_AUDIO_GET_VOLUME_IN_SYNC_REQ:
            aud_audio_get_volume_in_sync_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_GET_VOLUME_REQ:
            aud_audio_get_volume_req_hdlr(ilm_ptr);
            break;
	#if defined(__AUD_REC_INTENSITY__)
		case MSG_ID_L4AUD_AUDIO_GET_INTENSITY_REQ:
            aud_record_get_intensity_req_hdlr(ilm_ptr);
			break;
		case MSG_ID_L4AUD_AUDIO_GET_INTENSITY_LIMIT_REQ:
			aud_record_get_intensity_limit_req_hdlr(ilm_ptr);
			break;
	#endif/*__AUD_REC_INTENSITY__*/
        case MSG_ID_L4AUD_AUDIO_UPDATE_VOLUME_REQ:
        #ifdef __GAIN_TABLE_SUPPORT__
            aud_audio_update_volume_req_hdlr(ilm_ptr);
        #endif
            break;
        case MSG_ID_MEDIA_AUD_SET_VOLUME_REQ:
            aud_audio_set_volume_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_PLAY_BY_ID_REQ:
            aud_media_play_by_id_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_STOP_BY_ID_REQ:
            aud_media_stop_by_id_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_MUTE_REQ:
            aud_audio_mute_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_SET_MUTE_REQ:
            aud_set_mute_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_GET_MEDIA_MUTE_STATUS_REQ:
            aud_audio_get_mute_status_req_hdlr(ilm_ptr);
            break;
	#ifdef __VIBRATION_SPEAKER_SUPPORT__
		case MSG_ID_MEDIA_AUD_VIB_SPK_CALIBRATION_REQ:
			aud_vib_spk_calibration_hdlr(ilm_ptr);
			break;
	#endif
    #if defined(__AUDIO_DC_CALIBRATION_SUPPORT__) || defined(__VIBRATION_SPEAKER_SUPPORT__)
        case MSG_ID_BMT_ADC_MEASURE_DONE_CONF:
            aud_get_calibration_hdlr(ilm_ptr);
            break;
    #endif
	
/* The following message is not use in MODEM project */
#ifndef MED_MODEM
        case MSG_ID_MEDIA_AUD_PLAY_BY_STRING_REQ:
            aud_media_play_by_string_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_STOP_BY_STRING_REQ:
            aud_media_stop_by_string_req_hdlr(ilm_ptr);
            break;
    #if defined(__MED_AUD_REC_MOD__)
        case MSG_ID_L4AUD_MEDIA_RECORD_REQ:
            aud_media_record_req_hdlr(ilm_ptr);
            break;
    #endif /*__MED_AUD_REC_MOD__*/
    #if defined(__MED_AUD_FS_ACCESS__)
        case MSG_ID_MEDIA_AUD_PLAY_BY_FILE_REQ:
            aud_media_play_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_STOP_REQ:
            aud_media_stop_req_hdlr(ilm_ptr);
            break;
    #endif /*__MED_AUD_FS_ACCESS__*/
        case MSG_ID_L4AUD_MEDIA_PAUSE_REQ:
            aud_media_pause_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_MEDIA_RESUME_REQ:
            aud_media_resume_req_hdlr(ilm_ptr);
            break;
    #if defined(__MED_AUD_FS_ACCESS__)
        case MSG_ID_L4AUD_MEDIA_STORE_REQ:
            aud_media_store_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_MEDIA_RESTORE_REQ:
            aud_media_restore_req_hdlr(ilm_ptr);
            break;
    #endif /*__MED_AUD_FS_ACCESS__*/

        case MSG_ID_MEDIA_AUD_SET_VIBRATOR_ENABLED_REQ:
        #ifdef __MED_IMY_EVENT__
            aud_set_vibrator_enabled_req_hdlr(ilm_ptr);
        #endif /*__MED_IMY_EVENT__*/
            break;

    #ifdef __MMI_SUPPORT_VIBRATOR_SYNC__
            /* -- added for turn on/off vibrator by MMI task -- */
        case MSG_ID_MMIAPI_DEVICE_GET_CTRL_RSP:
            break;
        case MSG_ID_MMIAPI_DEVICE_PLAY_RSP:
        #ifdef __MED_IMY_EVENT__
            aud_vibrator_ctrl_rsp_hdlr(ilm_ptr);
        #endif /*__MED_IMY_EVENT__*/
            break;
    #endif /* __MMI_SUPPORT_VIBRATOR_SYNC__ */ 


    #ifdef __MMI_SUPPORT_BACKLIGHT_SYNC__
            /* -- added for turn on/off backlight by MMI task -- */
        case MSG_ID_MMIAPI_BACKLIGHT_CONTROL_RSP:
        #ifdef __MED_IMY_EVENT__
            aud_backlight_ctrl_rsp_hdlr(ilm_ptr);
        #endif
            break;
    #endif /* __MMI_SUPPORT_BACKLIGHT_SYNC__ */

        case MSG_ID_MEDIA_AUD_SET_HEADSET_MODE_OUTPUT_PATH:
            aud_set_headset_mode_output_path_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_SET_HEADSET_MODE_MIC_REQ:
            aud_set_headset_mode_mic_req_hdlr(ilm_ptr);
            break;

    #ifdef __MMI_SUPPORT_LED_SYNC__
            /* -- added for turn on/off backlight by MMI task -- */
        case MSG_ID_MMIAPI_LED_CONTROL_RSP:
        #ifdef __MED_IMY_EVENT__            
            aud_led_ctrl_rsp_hdlr(ilm_ptr);
        #endif
            break;
    #endif /* __MMI_SUPPORT_LED_SYNC__ */ 

    #ifdef __SPECTRUM_DISPLAY_SUPPORT__
        case MSG_ID_MEDIA_AUD_START_CALC_SPECTRUM_REQ:
            aud_start_calc_spectrum_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_STOP_CALC_SPECTRUM_REQ:
            aud_stop_calc_spectrum_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_GET_SPECTRUM_REQ:
            aud_get_spectrum_req_hdlr(ilm_ptr);
            break;
    #endif /* __SPECTRUM_DISPLAY_SUPPORT__ */ 

            /* play file portion related function */
        case MSG_ID_MEDIA_AUD_GET_DURATION_REQ:
            aud_media_get_duration_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_GET_PROGRESS_TIME_REQ:
            aud_media_get_progress_time_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_SET_PROGRESS_TIME_REQ:
            aud_media_set_progress_time_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_CHECK_IS_PURE_AUDIO_REQ:
            aud_media_is_pure_audio_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_CHECK_IS_FILE_SEEKABLE_REQ:
            aud_media_query_ability_req_hdlr(AUD_MEDIA_QUERY_SEEKABLE, ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_CHECK_IS_FILE_PAUSABLE_REQ:
            aud_media_query_ability_req_hdlr(AUD_MEDIA_QUERY_PAUSABLE, ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_CHECK_IS_RESOURCE_AVAILABLE_REQ:
            aud_media_is_resource_available_req_hdlr(ilm_ptr);
            break;

    #ifdef __AUDIO_TRIM_SUPPORT__
            /* Audio trim */
        case MSG_ID_L4AUD_TRIM_EVENT_CALLBACK_IND:
            aud_trim_event_callback_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_TRIM_OPEN_REQ:
            aud_trim_open_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_TRIM_CLOSE_REQ:
            aud_trim_close_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_TRIM_START_REQ:
            aud_trim_start_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_TRIM_STOP_REQ:
            aud_trim_stop_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_TRIM_SET_PARAM_REQ:
            aud_trim_set_param_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_TRIM_GET_PARAM_REQ:
            aud_trim_get_param_req_hdlr(ilm_ptr);
            break;
    #endif /* __AUDIO_TRIM_SUPPORT__ */

            /* FM Radio Begin */
        case MSG_ID_MEDIA_FMR_POWER_ON_REQ:
            aud_fmr_power_on_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_FMR_POWER_OFF_REQ:
            aud_fmr_power_off_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_FMR_SET_OUTPUT_PATH_REQ:
            aud_fmr_set_output_path_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_FMR_SET_FREQ_REQ:
            aud_fmr_set_freq_req_hdlr(ilm_ptr);
            break;
    #ifdef INTERNAL_ANTENNAL_SUPPORT
        case MSG_ID_MEDIA_FMR_SET_ANTENNA_REQ:
            aud_fmr_set_antenna_req_hdlr(ilm_ptr);
            break;
    #endif/* #ifdef INTERNAL_ANTENNAL_SUPPORT*/
        case MSG_ID_MEDIA_FMR_MUTE_REQ:
            aud_fmr_mute_req_hdlr(ilm_ptr);
            break;
    #ifdef __FM_RADIO_HW_SCAN__
        case MSG_ID_MEDIA_FMR_HW_SCAN_REQ:
            aud_fmr_hw_scan_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_FMR_HW_SCAN_ABORT_REQ:
            aud_fmr_hw_scan_abort_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_FMR_HW_SCAN_CALLBACK_IND:
            aud_fmr_hw_scan_callback_ind_hdlr(ilm_ptr);
            break;
    #endif /* __FM_RADIO_HW_SCAN__ */ 
    #ifdef __FM_RADIO_HW_SEARCH__
        case MSG_ID_MEDIA_FMR_SEEK_CALLBACK_IND:
            aud_fmr_seek_process_callback_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_FMR_SEEK_START_REQ:
            aud_fmr_seek_start_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_FMR_SEEK_ABORT_REQ:
            aud_fmr_seek_abort_req_hdlr(ilm_ptr);
            break;            
    #else /* FM_RADIO_HW_SEARCH */
        case MSG_ID_MEDIA_FMR_CHECK_IS_VALID_STOP_REQ:
            aud_fmr_check_is_valid_stop_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_FMR_GET_SIGNAL_LEVEL_REQ:
            aud_fmr_get_signal_level_req_hdlr(ilm_ptr);
            break;
    #endif /* __FM_RADIO_HW_SEARCH__ */

        case MSG_ID_MEDIA_FMR_SET_CHANNEL_REQ:
            aud_fmr_set_channel_req_hdlr(ilm_ptr);
            break;
    #ifdef __FM_RADIO_RDS_SUPPORT__
        case MSG_ID_MEDIA_FMR_RDS_ENABLE_REQ:
            aud_fmr_rds_enable_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_FMR_RDS_DISABLE_REQ:
            aud_fmr_rds_disable_req_hdlr(ilm_ptr);
            break;
	 case MSG_ID_MEDIA_FMR_RDS_CALLBACK_IND:
	     aud_fmr_rds_callback_ind_hdlr(ilm_ptr);
			break;
	 case MSG_ID_MEDIA_FMR_POLL_RDS_EVENT_RDS:
	     aud_fmr_rds_poll_rds_event_rds_hdlr(ilm_ptr);
			break;
    #endif /* __FM_RADIO_RDS_SUPPORT__ */ 
            /* FM Radio End */

            /* VR Begin */
    #ifdef __MED_VR_MOD__
        case MSG_ID_MEDIA_VR_GET_VERSION_REQ:
        case MSG_ID_MEDIA_VR_GET_PARAM_REQ:
        case MSG_ID_MEDIA_VR_SET_PARAM_REQ:
        case MSG_ID_MEDIA_VR_INIT_RCG_REQ:
        case MSG_ID_MEDIA_VR_INIT_TRN_REQ:
        case MSG_ID_MEDIA_VR_RCG_PROCESS_REQ:
        case MSG_ID_MEDIA_VR_TRN_PROCESS_REQ:
        case MSG_ID_MEDIA_VR_VOICE_IN_REQ:
        case MSG_ID_MEDIA_VR_DEL_TAG_REQ:
        case MSG_ID_MEDIA_VR_CHECK_TAG_REQ:
        case MSG_ID_MEDIA_VR_SYNC_DB_REQ:
        case MSG_ID_MEDIA_VR_PLAY_TAG_REQ:
        case MSG_ID_MEDIA_VR_GET_DIR_REQ:
        case MSG_ID_MEDIA_VR_ADD_TAG_REQ:
        case MSG_ID_MEDIA_VR_ABORT_REQ:
            aud_vr_main(ilm_ptr);
            break;
    #endif /* __MED_VR_MOD__ */ 
            /* VR End */

    #ifdef __MED_VRSI_MOD__
        case MSG_ID_MEDIA_VRSI_INIT_REQ:
        case MSG_ID_MEDIA_VRSI_ADD_TAGS_REQ:
        case MSG_ID_MEDIA_VRSI_START_TRN_REQ:
        case MSG_ID_MEDIA_VRSI_START_RCG_REQ:
        case MSG_ID_MEDIA_VRSI_PROCESS_IND:
        case MSG_ID_MEDIA_VRSI_PLAY_TAG_REQ:
        case MSG_ID_MEDIA_VRSI_PLAY_TTS_REQ:
        case MSG_ID_MEDIA_VRSI_GET_TAGNUM_REQ:
        case MSG_ID_MEDIA_VRSI_GET_TAGINFO_REQ:
        case MSG_ID_MEDIA_VRSI_DEL_TAGS_REQ:
        case MSG_ID_MEDIA_VRSI_RESET_TAGS_REQ:
        case MSG_ID_MEDIA_VRSI_SYNC_DB_REQ:
        case MSG_ID_MEDIA_VRSI_ABORT_REQ:
        case MSG_ID_MEDIA_VRSI_CLOSE_REQ:
            aud_vrsi_main(ilm_ptr);
            break;
    #endif /* __MED_VRSI_MOD__ */

    #ifdef __MED_MMA_MOD__
            /* MMA */
	#ifndef __MED_SLIM_MMA__
        case MSG_ID_MEDIA_MMA_OPEN_REQ:
            aud_mma_open_req_hdlr(ilm_ptr,KAL_FALSE);
            break;
        case MSG_ID_MEDIA_MMA_AYNC_OPEN_REQ:
            aud_mma_open_req_hdlr(ilm_ptr,KAL_TRUE);
            break;
        case MSG_ID_MEDIA_MMA_SET_CACHE_TABLE_REQ:
            aud_mma_set_cache_table_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_CLOSE_REQ:
            aud_mma_close_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_SET_PARAM_REQ:
            aud_mma_set_param_req_hdlr(ilm_ptr);
            break;

        case MSG_ID_MEDIA_MMA_BUILD_BLISRC_TABLE:
            aud_mma_build_BLISRC_table_req_hdlr(ilm_ptr);
            break;

        case MSG_ID_MEDIA_MMA_PLAY_REQ:
            aud_mma_play_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_STOP_REQ:
            aud_mma_stop_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_PAUSE_REQ:
            aud_mma_pause_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_RESUME_REQ:
            aud_mma_resume_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_GET_AUDIO_INFO_REQ:
            aud_mma_get_audio_info_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_GET_DURATION_REQ:
            aud_mma_get_duration_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_GET_CURRENT_TIME_REQ:
            aud_mma_get_current_time_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_SET_START_TIME_REQ:
            aud_mma_set_start_time_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_SET_STOP_TIME_REQ:
            aud_mma_set_stop_time_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_GET_VOLUME_REQ:
            aud_mma_get_volume_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_SET_VOLUME_REQ:
            aud_mma_set_volume_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_PDL_WRITE_DATA_IND_REQ:
            aud_mma_pdl_write_data_ind_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_PDL_GET_BUF_PERCENT_REQ:
            aud_mma_pdl_get_buf_percent_req_hdlr(ilm_ptr);
            break;
	#endif
    #ifdef __MED_MMA_EXTRA_CTRL__
        case MSG_ID_MEDIA_MMA_SET_RATE_REQ:
            aud_mma_set_rate_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_SET_TEMPO_REQ:
            aud_mma_set_tempo_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_SET_PITCH_REQ:
            aud_mma_set_pitch_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_SEND_LONG_MSG_REQ:
            aud_mma_send_long_msg_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_SEND_SHORT_MSG_REQ:
            aud_mma_send_short_msg_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_OPEN_DEVICE_REQ:
            aud_mma_open_device_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_CLOSE_DEVICE_REQ:
            aud_mma_close_device_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_SET_CHANNEL_VOLUME_REQ:
            aud_mma_set_channel_volume_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_SET_PROGRAM_REQ:
            aud_mma_set_program_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_SET_DATA_REQ:
            aud_mma_set_data_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_GET_CHANNEL_VOLUME_REQ:
            aud_mma_get_channel_volume_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_GET_PITCH_REQ:
            aud_mma_get_pitch_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_GET_PROGRAM_REQ:
            aud_mma_get_program_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_GET_RATE_RANGE_REQ:
            aud_mma_get_rate_range_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_GET_RATE_REQ:
            aud_mma_get_rate_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_GET_TEMPO_REQ:
            aud_mma_get_tempo_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_GET_BANK_LIST_REQ:
            aud_mma_get_bank_list_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_GET_PROGRAM_LIST_REQ:
            aud_mma_get_program_list_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_GET_PROGRAM_NAME_REQ:
            aud_mma_get_program_name_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_GET_KEY_NAME_REQ:
            aud_mma_get_key_name_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_GET_IS_BANK_SUPPORT_REQ:
            aud_mma_get_is_bank_support_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_GET_IS_SP_MIDI_REQ:
            aud_mma_get_is_sp_midi_req_hdlr(ilm_ptr);
            break;
    #endif /* __MED_MMA_EXTRA_CTRL__ */
    #endif /* __MED_MMA_MOD__ */ 

    #ifdef __MED_SND_MOD__
        case MSG_ID_MEDIA_SND_CHECK_BYTE_STREAM_FORMAT_REQ:
            aud_snd_check_byte_stream_format_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_SND_CHECK_FILE_FORMAT_REQ:
            aud_snd_check_file_format_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_SND_PLAY_BYTE_STREAM_REQ:
            aud_snd_play_byte_stream_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_SND_PLAY_FILE_REQ:
            aud_snd_play_file_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_SND_PROCESS_EVENT_IND:
            aud_snd_process_event(ilm_ptr);
            break;
        case MSG_ID_MEDIA_SND_STOP_PLAY_REQ:
            aud_snd_stop_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_SND_SET_VOLUME_REQ:
            aud_snd_set_volume_req_hdlr(ilm_ptr);
            break;
    #endif /* __MED_SND_MOD__ */ 

    #if defined(__MED___BES_TS_SUPPORT____)
        case MSG_ID_MEDIA_AUD_STRETCH_CHECK_STREAM_FORMAT_REQ:
            aud_stretch_check_stream_format_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_STRETCH_CHECK_FILE_FORMAT_REQ:
            aud_stretch_check_file_format_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_STRETCH_SET_SPEED_REQ:
            aud_stretch_set_speed_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_STRETCH_CLOSE_REQ:
            aud_stretch_close_req_hdlr();
            break;
   #endif /* #if defined(__MED___BES_TS_SUPPORT____) */
   #if defined(__MED___BES_LIVE_SUPPORT____)
        case MSG_ID_MEDIA___BES_LIVE_SUPPORT___SET_MODE_REQ:
            aud_reverb_set_mode_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA___BES_LIVE_SUPPORT___TURN_ON_REQ:
            aud_reverb_turn_on_req_hdlr();
            break;
        case MSG_ID_MEDIA___BES_LIVE_SUPPORT___TURN_OFF_REQ:
            aud_reverb_turn_off_req_hdlr();
            break;
    #endif /* #ifdef defined(__MED___BES_LIVE_SUPPORT____) */ 
    #if defined(__MED_AUD_SURROUND__)
        case MSG_ID_MEDIA_AUD_SURROUND_TURN_ON_REQ:
            aud_surround_turn_on_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_SURROUND_TURN_OFF_REQ:
            aud_surround_turn_off_req_hdlr();
            break;
    #endif /* #if defined(__MED_AUD_SURROUND__) */
   #if defined(__MED_AUD_EQUALIZER__)
        case MSG_ID_MEDIA_AUD_EQ_SET_MAGNITUDE_REQ:
            aud_eq_set_magnitude_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_EQ_TURN_ON_REQ:
            aud_eq_turn_on_req_hdlr();
            break;
        case MSG_ID_MEDIA_AUD_EQ_TURN_OFF_REQ:
            aud_eq_turn_off_req_hdlr();
            break;
    #endif /* #ifdef defined(__MED_AUD_EQUALIZER__) */ 
    #if defined(__MED_AUD_BASS_ENHANCE__)
        case MSG_ID_MEDIA_AUD_BASS_ENHANCE_TURN_ON_REQ:
            aud_bass_enhance_turn_on_req_hdlr();
            break;
        case MSG_ID_MEDIA_AUD_BASS_ENHANCE_TURN_OFF_REQ:
            aud_bass_enhance_turn_off_req_hdlr();
            break;
    #endif /* #if defined(__MED_AUD_BASS_ENHANCE__)*/
    #if defined(__MED_AUD_LOUDNESS__)
        case MSG_ID_MEDIA_AUD_LOUDNESS_TURN_ON_REQ:
            aud_loudness_turn_on_req_hdlr();
            break;
        case MSG_ID_MEDIA_AUD_LOUDNESS_TURN_OFF_REQ:
            aud_loudness_turn_off_req_hdlr();
            break;
    #endif /* #if defined(__MED_AUD_LOUDNESS__)*/

    #ifdef __MED_GENERAL_TTS__
        case MSG_ID_MEDIA_AUD_TTS_SET_ATTR_REQ:
            aud_tts_set_attr_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_TTS_PLAY_EVENT_IND:
            aud_tts_process_event_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_TTS_PLAY_REQ:
            aud_tts_play_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_TTS_STOP_REQ:
            aud_tts_stop_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_TTS_PAUSE_REQ:
            aud_tts_pause_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_TTS_RESUME_REQ:
            aud_tts_resume_req_hdlr(ilm_ptr);
            break;
    #endif /*#ifdef __MED_GENERAL_TTS__*/

    #ifdef __KEY_TONE_DETECTION__
        case MSG_ID_MEDIA_AUD_KT_PROCESS_CALLBACK:
            aud_keytone_detect_process_callback_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_KT_START_DETECT:
            aud_keytone_detect_start_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_KT_STOP_DETECT:
            aud_keytone_detect_stop_req_hdlr(ilm_ptr);
            break;
    #endif /*__KEY_TONE_DETECTION__*/

    #ifndef MED_V_NOT_PRESENT
    #ifdef __MED_SND_MOD__
        case MSG_ID_MEDIA_V_AUDIO_BGSND_STOP_PLAY_CNF:
            aud_snd_med_v_stop_cnf_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_V_AUDIO_BGSND_FINISH_IND:
            aud_snd_med_v_finish_ind_hdlr(ilm_ptr);
            break;
    #endif /* #ifdef __MED_SND_MOD__ */
    #endif /* #ifndef MED_V_NOT_PRESENT */    

        case MSG_ID_MEDIA_IN_PROC_CALL_EXT_REQ:
            aud_util_in_proc_call_ext_req_hdlr(ilm_ptr);
            break;
#endif /* MED_MODEM */
        case MSG_ID_MEDIA_IN_PROC_CALL_REQ:
            aud_util_in_proc_call_req_hdlr(ilm_ptr);
            break;
        default:
            /* assert */
            break;
    }
    return;

}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 

/*****************************************************************************
 * FUNCTION
 *  aud_init
 * DESCRIPTION
 *  This function is used to init audio task.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Func_Reg_Type media_func;
#ifdef __VIDEO_ARCHI_V2__
    MED_AUD_CALLBACK_FUNC_T mpl_func;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    aud_context_p->ring_buf = NULL;
    aud_context_p->state = AUD_IDLE;
    aud_context_p->loudness_on = KAL_FALSE;
    aud_context_p->aud_event = kal_create_event_group("aud_events");
    aud_context_p->mma_event = kal_create_event_group("mma_events");
#if defined(__MED_VR_MOD__) || defined(__MED_VRSI_MOD__)
    aud_context_p->vr_event = kal_create_event_group("vr_events");
#endif
#if defined(__MED_SND_MOD__) || defined(__MED_AUD_AUDIO_EFFECT__)
    aud_context_p->effect_event = kal_create_event_group("effect_events");
#endif

    nvram_ltable_register(logical_data_item_table_audio);

    /* Register callback functions to L1audio */
    media_func.alloc_mem           = aud_util_alloc_aud_toppest_cacheable_mem;   //modif for driver alloc buffer toppest mode
    media_func.alloc_mem_cacheable = aud_util_alloc_aud_cacheable_mem;
    media_func.free_mem            = aud_util_free_aud_mem;
    media_func.set_path_volume     = aud_set_aud_path_volume;
    media_func.get_active_mode     = aud_get_active_audio_mode;
    media_func.send_proc_call      = aud_send_in_proc_call_req;
    media_func.send_proc_call2     = aud_send_in_proc_call_req2;
	
#ifdef __CLASSK_CP_SUPPORT__
    media_func.get_vbat_value      = aud_get_vbat_value;
    media_func.send_classk_state=  aud_send_classk_state;
#endif

#ifdef __VIBRATION_SPEAKER_SUPPORT__
	media_func.send_vib_spk_is_calib = aud_send_vib_spk_is_calib;
#endif    
    Audio_MedFuncReg(&media_func);

#ifdef __VIDEO_ARCHI_V2__
  #ifdef __MED___BES_TS_SUPPORT____
    mpl_func.pfn_aud_stretch_close           = aud_stretch_close;
    mpl_func.pfn_aud_stretch_set_speed       = aud_stretch_set_speed;
  #endif
  #ifdef __MED_BT_A2DP_MOD__
    mpl_func.pfn_aud_bt_a2dp_open_codec      = aud_bt_a2dp_open_codec;
    mpl_func.pfn_aud_bt_a2dp_close_codec_for_open = aud_bt_a2dp_close_codec_for_open;
  #endif
    mpl_func.pfn_aud_get_active_device_path_by_mode = aud_get_active_device_path_by_mode;
    mpl_func.pfn_aud_melody_set_output_device = aud_melody_set_output_device;

    mpl_session_set_med_audio_callback(&mpl_func);
#endif //__VIDEO_ARCHI_V2__

    aud_speech_init();

    aud_audio_init();


    aud_tone_init();

    aud_melody_init();

#if defined(VM_SUPPORT) && defined(VM_LOG)
    aud_vm_init();
#endif /* defined(VM_SUPPORT) && defined(VM_LOG) */ 


#ifdef __MED_CTM_MOD__
    aud_ctm_init();
#endif /* __MED_CTM_MOD__ */ 

#ifdef __MED_BT_MOD__
    aud_bt_init();
#endif 

#ifdef __RICH_AUDIO_PROFILE__
    audio_input_stream_init();
#endif

    return KAL_TRUE;
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

#endif /* MED_NOT_PRESENT */ 

