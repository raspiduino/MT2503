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
 * aud_speech.c
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/******************************************************************
 * MODULE
 *    AUD_SPEECH
 * DESCRIPTION
 *    This module defines the speech related function for Audio Manager.
 *  
 ******************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES ===========*/

//#include "kal_release.h"
#include "kal_trace.h"
//#include "stack_common.h"
#include "stack_msgs.h"
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
//#include "nvram_enums.h"
//#include "nvram_struct.h"
//#include "nvram_user_defs.h"
//#include "nvram_data_items.h"
//#include "custom_nvram_editor_data_item.h"

/* local includes */
#include "med_global.h"
//#include "med_status.h"
#include "aud_defs.h"
#include "med_struct.h"
//#include "med_api.h"
#include "med_context.h"
#include "aud_main.h"
#include "med_main.h"
#include "med_utility.h"
#include "aud_bt_hfp.h"

#if defined(__MED_VID_DEC_MOD__)
#include "vid_main.h"
#endif 

#include "kal_general_types.h"
#include "string.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#ifdef __MED_RTP_MOD__
extern kal_uint8 voip_curr_encoding_or_decoding(void); /* To check if rtp is running */
#endif /*__MED_RTP_MOD__*/

/* TEMP, shall revise */
extern void vcall_open_speech_codec(void);
extern void vcall_close_speech_codec(void);

#ifdef __MED_MEGA_PHONE__
kal_bool aud_speech_is_megaphone_on(void);
#endif

/*****************************************************************************
 * FUNCTION
 *  aud_speech_init
 * DESCRIPTION
 *  This function is used to init this module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->speech_on = KAL_FALSE;
    aud_context_p->rat_mode = 0xFF;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_set_output_device
 * DESCRIPTION
 *  
 * PARAMETERS
 *  device      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_set_output_device(kal_uint8 device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_PATH(AUD_TYPE_SPEECH, device);
#ifdef __MED_MEGA_PHONE__
	if(aud_speech_is_megaphone_on())
		return;
#endif

    L1SP_SetOutputDevice(device);
}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_set_output_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume1                 [IN]        
 *  digital_gain_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_set_output_volume(kal_uint8 volume1, kal_int8 digital_gain_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_VOLUME(AUD_VOLUME_SPH, volume1, digital_gain_index);
    L1SP_SetOutputVolume(volume1, digital_gain_index);
}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_set_volume_level_param
 * DESCRIPTION
 *  
 * PARAMETERS
 *  speech_volume    [IN]        
 *  speech_mode      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_set_volume_level_param(kal_uint8 speech_volume_level, kal_uint8 speech_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 param_index = 0;
	kal_uint8 speech_demute_level = speech_volume_level;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (speech_mode)
    {
        case SPH_MODE_BT_CARKIT:
            param_index = 1;
            break;
        case SPH_MODE_AUX1:
            param_index = 2;
            break;
    }

   if (speech_volume_level & 0x40)
   {   
	   /* Decrease one level for the actually applied level */
	   speech_demute_level = (speech_volume_level & 0x3F) - 1;
   }

   L1SP_SetSpeechVolumeLevelByIndex(speech_demute_level,param_index);

}


/*****************************************************************************
 * FUNCTION
 *  aud_mic_set_device
 * DESCRIPTION
 *  
 * PARAMETERS
 *  device      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mic_set_device(kal_uint8 device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_PATH(AUD_TYPE_MIC, device);
    aud_context_p->input_device = device;
    L1SP_SetInputSource(device);
}

/* Set input device to media task context only, apply to device later */


/*****************************************************************************
 * FUNCTION
 *  aud_mic_set_device_no_apply
 * DESCRIPTION
 *  
 * PARAMETERS
 *  device      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mic_set_device_no_apply(kal_uint8 device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_PATH(AUD_TYPE_MIC, device);
    aud_context_p->input_device = device;
}


/*****************************************************************************
 * FUNCTION
 *  aud_mic_set_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume1     [IN]        
 *  volume2     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mic_set_volume(kal_uint8 volume1, kal_uint8 volume2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_VOLUME(AUD_VOLUME_MIC, volume1, volume2);
    L1SP_SetMicrophoneVolume(volume1);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mic_mute
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mute        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mic_mute(kal_bool mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    L1SP_MuteMicrophone(mute);
}


#ifdef __DUAL_MIC_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  aud_mic_set_dual_nr_req_hdlr
 * DESCRIPTION
 *  This function is to enable/disable NR for dual microphone.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mic_set_dual_nr_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_mic_set_dual_nr_req_struct *req_p = (l4aud_mic_set_dual_nr_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    L1SP_Speech_Off();

    L1SP_SetDualMicNR(req_p->is_enable);

    if (aud_context_p->speech_on)
    {
        L1SP_Speech_On(aud_context_p->rat_mode);
    }
    
}
#endif /* __DUAL_MIC_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  aud_side_tone_set_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume1                 [IN]        
 *  digital_gain_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_side_tone_set_volume(kal_uint8 volume1, kal_int8 digital_gain_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_VOLUME(AUD_VOLUME_SID, volume1, digital_gain_index);
    L1SP_SetSidetoneVolume(volume1);
}

/*****************************************************************************
 * FUNCTION
 *  aud_speech_query_speech_scenario_by_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
SPH_ENH_AND_FIR_SCENE aud_speech_query_speech_scenario_by_mode(kal_uint8 audio_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SPH_ENH_AND_FIR_SCENE scene;
#ifdef __MED_RTP_MOD__
    kal_bool voip_on = (kal_bool)voip_curr_encoding_or_decoding();
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (audio_mode)
    {
        case AUD_MODE_HEADSET:
        {
            scene = SPH_ENH_AND_FIR_SCENE_EARPHONE;
            break;
        }

        case AUD_MODE_LOUDSPK:
        {
    #ifdef __MED_RTP_MOD__
            if(voip_on)
                scene = SPH_ENH_AND_FIR_SCENE_VOIP_LOADSPK;
            else
    #endif
	#ifdef __MED_MEGA_PHONE__
	        if(aud_speech_is_megaphone_on())
				scene = SPH_ENH_AND_FIR_SCENE_AUX2;
			else
	#endif
                scene = SPH_ENH_AND_FIR_SCENE_LOUDSPK;
            break;
        }

        /*AUD_MODE_NORMAL*/
        default:
        {
    #ifdef __MED_RTP_MOD__
            if(voip_on)
                scene = SPH_ENH_AND_FIR_SCENE_VOIP_NORMAL;
            else
    #endif
                scene = SPH_ENH_AND_FIR_SCENE_NORMAL;
            break;
        }

    }

    return scene;
}

/*****************************************************************************
 * FUNCTION
 *  aud_speech_set_fir_index_by_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_set_fir_index_by_mode(kal_uint8 audio_mode)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SPH_ENH_AND_FIR_SCENE scene;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined( __MED_BT_HFP_MOD__) || defined(__MED_BT_HF_MOD__)
    if (aud_bt_hfp_is_speech_path_on())
    {
        scene = aud_bt_hfp_query_bt_speech_scenario();
    }
    else
#endif /* __MED_BT_HFP_MOD__ */ 
    {
        scene = aud_speech_query_speech_scenario_by_mode(audio_mode);
    }

    L1SP_SetSpeechEnhanceAndFir(scene,SPH_ENH_AND_FIR_UPDATE_TYPE_ALL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_set_fir_index
 * DESCRIPTION
 *  Use current audio mode to set FIR coefficient
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_set_fir_index(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_speech_set_fir_index_by_mode(aud_context_p->audio_mode);
}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_on(kal_uint8 rat_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY2(AUD_TRC_SPEECH_ON, rat_mode, aud_context_p->state);

    /* Un-mute digital gain in case it is turn off by set mute function */
    aud_audio_mute_digital_gain(KAL_FALSE, AUD_DIGITAL_GAIN_AUDIO);

#ifdef __MED_AUD_REC_MOD__
    aud_rec_speech_event_nfy(AUD_SPEECH_EVENT_PRE_ON);
#endif

    L1SP_Speech_On(rat_mode);
    aud_context_p->speech_on = KAL_TRUE;

#ifdef __MED_AUD_REC_MOD__
    aud_rec_speech_event_nfy(AUD_SPEECH_EVENT_POST_ON);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_off
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_TRC_SPEECH_OFF);

#ifdef __MED_AUD_REC_MOD__
    aud_rec_speech_event_nfy(AUD_SPEECH_EVENT_PRE_OFF);
#endif

    L1SP_Speech_Off();
    aud_context_p->speech_on = KAL_FALSE;

#ifdef __MED_AUD_REC_MOD__
    aud_rec_speech_event_nfy(AUD_SPEECH_EVENT_POST_OFF);
#endif
}

#ifdef __GAIN_TABLE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  aud_speech_set_fir_coefficient_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_set_fir_coeff_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_sp_set_fir_coeff_req_struct *req_p = (media_aud_sp_set_fir_coeff_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    L1SP_Write_Audio_Coefficients_ByFirIndex(req_p->input_idx,req_p->output_idx);

    AUD_FUNC_ENTRY2(AUD_TRC_SPEECH_SET_FIR_COEFF,req_p->input_idx,req_p->output_idx);

    L1SP_SetFIR(KAL_TRUE);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  aud_speech_set_enhance_mode_req_hdlr
 * DESCRIPTION
 *  This function is used to set speech enhancement mode.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_set_enhance_mode_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_sp_set_enhance_mode_req_struct *req_p = (media_aud_sp_set_enhance_mode_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->speech_on)
    {
        L1SP_Speech_Off();
    }
    
    if (req_p->is_with_param == KAL_FALSE)
    {
        if(req_p->mode <= SPH_MODE_LINEIN_VIA_BT_CORDLESS)
        {
            SPH_ENH_AND_FIR_SCENE scene = (SPH_ENH_AND_FIR_SCENE)req_p->mode;
            L1SP_SetSpeechEnhanceAndFir(scene, SPH_ENH_AND_FIR_UPDATE_TYPE_NB_ENH_MODE | SPH_ENH_AND_FIR_UPDATE_TYPE_WB_ENH_MODE);
        }
    }
    else
    {
    #ifdef __AMRWB_LINK_SUPPORT__
        L1SP_SetWbSpeechPara(req_p->wb_param);
    #endif /* __AMRWB_LINK_SUPPORT__ */
        L1SP_SetSpeechMode(req_p->mode, req_p->param);
    }

    if (aud_context_p->speech_on)
    {
        L1SP_Speech_On(aud_context_p->rat_mode);
    }
}

/*****************************************************************************
 * FUNCTION
 *  aud_speech_set_mode_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_set_mode_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef DUMMY_CNF
    kal_uint16 cnf_msg_id;
    media_aud_sp_set_mode_cnf_struct *cnf_p = NULL;
#endif /* DUMMY_CNF */ 
    meida_aud_sp_set_mode_req_struct *req_p;
    kal_uint8 volume;
    kal_uint8 vol_gain_type = AUD_VOLUME_SPH;
    kal_uint8 vol_level_type = AUD_VOLUME_SPH;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (meida_aud_sp_set_mode_req_struct*) ilm_ptr->local_para_ptr;

    AUD_FUNC_ENTRY1(AUD_TRC_SPEECH_SET_MODE_REQ_HDLR, aud_context_p->state);

    /* if keytone is playing, stop it */
    aud_keytone_stop();

    /* if tone is playing, stop it */
    /* Remove in case that busy tone is stopped by speech off */
    //if (aud_context_p->tone_playing)
    //aud_tone_stop();

#if defined( __MED_MMA_MOD__)&&(!defined(__MED_SLIM_MMA__))
    /* close all mma tasks */
    aud_mma_close_all();
#endif /* __MED_MMA_MOD__ */ 

#if defined(__MED_VID_DEC_MOD__)
    vid_stop_unfinished_task();
#endif 

    /* Don't stop record when 2G/3G speech handover */
    if ((aud_context_p->state != AUD_MEDIA_IDLE) &&
        (aud_context_p->state != AUD_MEDIA_RECORD) &&
        (aud_context_p->state != AUD_MEDIA_RECORD_PAUSED) &&
        (aud_context_p->state != AUD_MEDIA_WAIT_RECORD))
    {
        aud_stop_unfinished_process();
    }

#ifndef __GAIN_TABLE_SUPPORT__

    /* set general tone volume */
    if( !req_p->speech_on)
    {
        /* reset tone volume level, use key tone volume level */

        vol_gain_type = AUD_VOLUME_CTN;
        vol_level_type = AUD_VOLUME_KEY;

    }

    volume = aud_get_volume_gain(
                aud_context_p->audio_mode,
                vol_gain_type,
                aud_get_volume_level(aud_context_p->audio_mode, vol_level_type));    
    aud_tone_set_output_volume(volume, 0);
#endif /* __GAIN_TABLE_SUPPORT__ */

    if (req_p->speech_on)
    {
        aud_context_p->rat_mode = req_p->rat_mode;

        if (req_p->rat_mode == RAT_3G324M_MODE)
        {
        #ifdef __MED_VCALL_MOD__
            vcall_open_speech_codec();
        #endif 
        }
        else
        {
            aud_speech_on(aud_context_p->rat_mode);
        #ifdef VM_LOG
            aud_vm_start_logging();
        #endif
        }
    }
    else
    {
        if (req_p->rat_mode == RAT_3G324M_MODE)
        {
        #ifdef __MED_VCALL_MOD__            
            vcall_close_speech_codec();
        #endif
        }
        else
        {
        #ifdef VM_LOG
            aud_vm_stop_logging();
        #endif 
            aud_speech_off();
        }

        aud_context_p->rat_mode = 0xFF;
    }
#ifdef DUMMY_CNF
    cnf_msg_id = MSG_ID_MEDIA_AUD_SP_SET_MODE_CNF;
    cnf_p = (media_aud_sp_set_mode_cnf_struct*) construct_local_para(sizeof(media_aud_sp_set_mode_cnf_struct), TD_CTRL);

    cnf_p->result = MED_RES_OK;

    aud_send_ilm(ilm_ptr->src_mod_id, cnf_msg_id, cnf_p, NULL);
#endif /* DUMMY_CNF */ 
}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_get_param_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_mode             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 aud_speech_get_param_mode(kal_uint8 audio_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 speech_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined( __MED_BT_HFP_MOD__) || defined(__MED_BT_HF_MOD__)
    if (aud_bt_hfp_is_audio_path_on())
    {
    #ifdef __MED_BT_FM_VIA_SCO__
        if(aud_fmr_is_power_on())
        {
            speech_mode = SPH_MODE_LINEIN_VIA_BT_CORDLESS;    
        }
        else
    #endif /* __MED_BT_FM_VIA_SCO__ */   
        {
            speech_mode = SPH_MODE_BT_EARPHONE;
        }
    }
    else
#endif /* __MED_BT_HFP_MOD__ */ 
    {
        speech_mode = audio_mode;
    }

    return speech_mode;
}

#ifdef __VOICE_CHANGER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  aud_speech_set_voice_changer_mode_req_hdlr
 * DESCRIPTION
 *  This function is used to set voice changer mode.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_set_voice_changer_mode_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_voice_changer_set_mode_req_struct *req_p = (media_voice_changer_set_mode_req_struct*) ilm_ptr->local_para_ptr;
	kal_bool result = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = L1SP_SetVoiceChangerMode(req_p->mode);

	med_voice_changer_write_nvram(req_p->mode);
	
	aud_set_VC_result_and_event(result,AUD_VOICE_CHANGER_EVT_SET);
}

#endif

#ifdef __MED_MEGA_PHONE__

kal_bool is_megaphone_on = KAL_FALSE;
kal_bool is_normal_megaphone_on = KAL_FALSE;
static kal_int16      PCM_UL_BUF[160] ={ 0};

void megaphone_pcm2way_hisrHdl()
{
#ifdef __MTK_TARGET__
  PCM2WAY_PutToSpk((const kal_uint16*)PCM_UL_BUF);
  PCM2WAY_GetFromMic((kal_uint16*)PCM_UL_BUF);  
#endif /*__MTK_TARGET__*/
}

kal_bool aud_speech_is_megaphone_on(void)
{
    return is_megaphone_on;
}

void aud_speech_enable_normal_megaphone(kal_bool on)
{
    if(is_normal_megaphone_on == on)
		return;
    is_normal_megaphone_on = on;
#ifdef __MTK_TARGET__
    if(on)
    {
        kal_bool mic_muted = KAL_FALSE;

		mic_muted = L1SP_IsMicrophoneMuted();

		if(!mic_muted )
		{
            L1SP_MuteMicrophone(KAL_TRUE);
		}
		PCM2WAY_Start(megaphone_pcm2way_hisrHdl,P2W_APP_TYPE_VOIP);

		if(!mic_muted)
		{
		    kal_sleep_task(5);
            L1SP_MuteMicrophone(KAL_FALSE);
		}
    }
	else
		PCM2WAY_Stop(P2W_APP_TYPE_VOIP);
#endif /*__MTK_TARGET__*/
}

/*****************************************************************************
 * FUNCTION
 *  aud_speech_enable_megaphone_req_hdlr
 * DESCRIPTION
 *  This function is used to enable/disable megaphone.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_enable_megaphone_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_enable_megaphone_req_struct *req_p = (media_enable_megaphone_req_struct*) ilm_ptr->local_para_ptr;
	aud_keytone_stop();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(req_p->on)
	{
	    if(!is_megaphone_on) 
	    {
	       #if defined( __MED_BT_HFP_MOD__) || defined(__MED_BT_HF_MOD__)
		    if(!aud_bt_hfp_is_audio_path_on())
			#endif
	            aud_speech_enable_normal_megaphone(KAL_TRUE);

			L1SP_SetOutputDevice(L1SP_LOUD_SPEAKER);
			is_megaphone_on = KAL_TRUE;
			if(aud_context_p->audio_mode != AUD_MODE_HEADSET)
				aud_set_aud_path_volume(AUD_MODE_LOUDSPK);
			#if defined( __MED_BT_HFP_MOD__) || defined(__MED_BT_HF_MOD__)
			aud_bt_hfp_set_sco_mode(AUD_BT_HFP_MODE_MEGAPHONE_SCO);
			#endif
	    }
	}
	else
	{   
		if(is_megaphone_on) 
		{
		    kal_uint8 output_device = 0;

		    if(is_normal_megaphone_on)
	            aud_speech_enable_normal_megaphone(KAL_FALSE);
			is_megaphone_on = KAL_FALSE;
			#if defined( __MED_BT_HFP_MOD__) || defined(__MED_BT_HF_MOD__)
            aud_bt_hfp_reset_sco_mode(AUD_BT_HFP_MODE_MEGAPHONE_SCO);
			#endif
		    /* Restore audio settings*/
		    aud_set_aud_path_volume(aud_context_p->audio_mode);
		}
	}

	aud_set_event(AUD_EVT_WAIT);
}

#endif

#ifdef __MED_POC_MOD__

typedef void (*media_handler) (Media_Handle *handle, Media_Event event);


/*****************************************************************************
 * FUNCTION
 *  aud_speech_amr_encode_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vocoder             [IN]        
 *  media_handler       [IN]        
 *  frame_threshold     [IN]        
 *  buffer_size         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_speech_amr_encode_start(
            kal_uint8 vocoder,
            void (*media_handler) (void),
            kal_int32 frame_threshold,
            kal_uint32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(buffer_size <= AUD_RING_BUFFER_LEN);

#ifndef __MTK_TARGET__
    {
        extern kal_int32 poc_encode_start(void);

        result = poc_encode_start();
    }
#else /* __MTK_TARGET__ */ 
    aud_util_alloc_ring_buffer();
    PoC_AMR_SetBuffer(aud_context_p->ring_buf, buffer_size);
    result = PoC_AMR_EncodeStart(vocoder, media_handler, frame_threshold);
#endif /* __MTK_TARGET__ */ 

    return (kal_int32) result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_amr_encode_get_payload
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf             [?]         
 *  max_len         [IN]        
 *  frame_thres     [IN]        
 *  len_p           [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_speech_amr_encode_get_payload(
            kal_uint8 *buf,
            kal_int32 max_len,
            kal_int32 frame_thres,
            kal_int32 *len_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 frames;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
    *len_p = 42;
    {
        const kal_uint8 test_rtp_payload[] = 
        {
            0x80, 0xed, 0x03, 0x0a, 0x00, 0x00, 0x49, 0xf4, 0x00, 0x00, 0x00, 0xff, 0x31, 0x32, 0x33, 0x34,
            0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30,
            0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30
        };

        memcpy(buf, test_rtp_payload, sizeof(test_rtp_payload));
    }
#else /* __MTK_TARGET__ */ 
    frames = PoC_AMR_GetFrameCount();
    /* *len_p = PoC_AMR_GetPayload( buf, max_len, frames ); */
    *len_p = PoC_AMR_GetPayload(buf, max_len, frame_thres);
    AUD_MODULE_SPEECH_TRACE(frames, frame_thres, *len_p, __LINE__);
#endif /* __MTK_TARGET__ */ 

    return MED_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_amr_encode_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_speech_amr_encode_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
    {
        extern kal_int32 poc_encode_stop(void);

        result = poc_encode_stop();
    }
#else /* __MTK_TARGET__ */ 
    result = PoC_AMR_EncodeStop();
    aud_util_free_ring_buffer();
#endif /* __MTK_TARGET__ */ 

    return (kal_int32) result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_amr_decode_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer_size     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_speech_amr_decode_start(kal_uint32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(buffer_size <= AUD_RING_BUFFER_LEN);

#ifndef __MTK_TARGET__
    result = 0;
#else /* __MTK_TARGET__ */ 
    aud_util_alloc_ring_buffer();
    PoC_AMR_SetBuffer(aud_context_p->ring_buf, buffer_size);
    result = PoC_AMR_DecodeStart();
#endif /* __MTK_TARGET__ */ 

    return (kal_int32) result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_amr_decode_put_payload
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf     [?]         
 *  len     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_speech_amr_decode_put_payload(kal_uint8 *buf, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
    result = 0;
#else 
    result = PoC_AMR_PutPayload(buf, len);
#endif 

    return (kal_int32) result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_amr_decode_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_speech_amr_decode_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
    result = 0;
#else 
    result = PoC_AMR_DecodeStop();
    aud_util_free_ring_buffer();
#endif 

    return (kal_int32) result;
}

#endif /* __MED_POC_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

