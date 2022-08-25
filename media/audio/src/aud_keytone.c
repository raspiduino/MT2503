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
 * aud_keytone.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes keytone related functions of audio manager task.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *    AUD_KEYTONE
 * DESCRIPTION
 *    This module defines the keytone related function for Audio Manager.
 *  
 ******************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES ========*/

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
#include "resource_audio.h"
//#include "nvram_enums.h"
//#include "nvram_struct.h"
//#include "nvram_user_defs.h"
//#include "nvram_data_items.h"
//#include "custom_nvram_editor_data_item.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
//#include "med_api.h"
#include "med_context.h"
#include "aud_main.h"
#include "med_main.h"

#include "kal_general_types.h"
#include "stack_config.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#ifdef __VOIP__
extern kal_bool AM_IsVoIPOn(void);
#endif


/*****************************************************************************
 * FUNCTION
 *  aud_keytone_set_output_device
 * DESCRIPTION
 *  
 * PARAMETERS
 *  device      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_keytone_set_output_device(kal_uint8 device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_PATH(AUD_TYPE_KEYTONE, device);
    KT_SetOutputDevice(device);
    KT_SetFIR(KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  aud_keytone_set_output_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume1                 [IN]        
 *  digital_gain_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_keytone_set_output_volume(kal_uint8 volume1, kal_int8 digital_gain_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_VOLUME(AUD_VOLUME_KEY, volume1, digital_gain_index);
    KT_SetOutputVolume(volume1, digital_gain_index);
}


/*****************************************************************************
 * FUNCTION
 *  aud_keytone_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_id                [IN]        
 *  audio_out_device        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_keytone_play(kal_uint8 audio_id, kal_uint8 audio_out_device, kal_uint8 play_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 duration;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Change speech path to phone to let keypad tone play in phone */
#if (defined(__MED_BT_AUDIO_VIA_SCO__) || defined(__MED_BT_FM_VIA_SCO__)) && !defined(__MED_BT_SCO_KEYTONE__)
    if(aud_bt_hfp_is_audio_path_on()
       && !aud_context_p->speech_on
       && aud_bt_hfp_is_speech_path_on()
       && KT_IsPlayable()
    #ifdef __VOIP__
       && !AM_IsVoIPOn()
    #endif
      )
    {
        aud_bt_hfp_set_speech_path_off();

    }
#endif /* #if (defined(__MED_BT_AUDIO_VIA_SCO__) || defined(__MED_BT_FM_VIA_SCO__)) && !defined(__MED_BT_SCO_KEYTONE__) */

    /* Overwrite duration if play infinitely */
    duration = (play_style == DEVICE_AUDIO_PLAY_INFINITE) ? 0 : resource_tones[audio_id - MIN_TONE_ID]->on_duration;

    KT_Play(resource_tones[audio_id - MIN_TONE_ID]->freq1,
            resource_tones[audio_id - MIN_TONE_ID]->freq2,
            duration);

    AUD_MODULE_KEYTONE_TRACE(resource_tones[audio_id - MIN_TONE_ID]->freq1,
                             resource_tones[audio_id - MIN_TONE_ID]->freq2,
                             duration);
}


/*****************************************************************************
 * FUNCTION
 *  aud_keytone_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_keytone_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    KT_Stop();
    
    /* Stop keytone in blocking way. This could prevent losing key tones when quickly pressing keys.
     * However, since the play tone request is NOT a blocking call, the queue of MED may be full
     * if MMI keeps sending the requests to play keytones.
     */
    /*KT_StopAndWait();*/

    /* Change audio path to BT to let music play in earphone */
#if (defined(__MED_BT_AUDIO_VIA_SCO__) || defined(__MED_BT_FM_VIA_SCO__)) && !defined(__MED_BT_SCO_KEYTONE__)
    if(aud_bt_hfp_is_audio_path_on()
       && !aud_context_p->speech_on
       && !aud_bt_hfp_is_speech_path_on()
    #ifdef __VOIP__
       && !AM_IsVoIPOn()
    #endif
      )
    {
        aud_bt_hfp_set_speech_path_on();
    }
#endif /* #if (defined(__MED_BT_AUDIO_VIA_SCO__) || defined(__MED_BT_FM_VIA_SCO__)) && !defined(__MED_BT_SCO_KEYTONE__) */
}


#ifdef __KEY_TONE_DETECTION__
/*****************************************************************************
 * FUNCTION
 *  aud_keytone_detect_start_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_keytone_detect_process_callback_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_kt_detect_ind_struct *ind_p;
    media_aud_kt_process_callback_struct *callback_p =
        (media_aud_kt_process_callback_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_aud_kt_detect_ind_struct*)
        construct_local_para(sizeof(media_aud_kt_detect_ind_struct), TD_CTRL);

    ind_p->key = callback_p->key;
	ind_p->keyLength = callback_p->keyLength;
   // kal_trace(MOD_MED,"dtmf key tone length = %d",ind_p->keyLength);
    aud_send_ilm(aud_context_p->src_mod, MSG_ID_MEDIA_AUD_KT_DETECT_IND, ind_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_keytone_detect_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_keytone_detect_callback(kal_int16 key,kal_int32 keyLength)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_kt_process_callback_struct *ind_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_aud_kt_process_callback_struct*)
        construct_local_para(sizeof(media_aud_kt_process_callback_struct), TD_CTRL);

    ind_p->key = key;
	ind_p->keyLength = keyLength;
    kal_prompt_trace(MOD_MED,"key=%d,key Length = %d",key,keyLength);
    aud_send_ilm(MOD_MED, MSG_ID_MEDIA_AUD_KT_PROCESS_CALLBACK, ind_p, NULL);
}

//Add for DTMF length detect.
void aud_keytone_detect_start(void) {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//kal_uint32 result = MED_RES_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	KtDetectStart(aud_keytone_detect_callback);

}
//Add for DTMF length detect.
void aud_keytone_detect_stop(void) {
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	KtDetectStop();
	
}

/*****************************************************************************
 * FUNCTION
 *  aud_keytone_detect_start_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_keytone_detect_start_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 result = MED_RES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->src_mod = ilm_ptr->src_mod_id;

    if (!aud_context_p->speech_on ||
        aud_context_p->state == AUD_MEDIA_RECORD ||
        aud_context_p->state == AUD_MEDIA_RECORD_PAUSED ||
        aud_context_p->state == AUD_MEDIA_WAIT_RECORD)
    {
        result = MED_RES_FAIL;
    }

#ifdef __MTK_TARGET__
    KtDetectStart(aud_keytone_detect_callback);
#endif

    aud_set_result_and_event((kal_int32)result,AUD_EVT_START_KT_DETECT);
}


/*****************************************************************************
 * FUNCTION
 *  aud_keytone_detect_stop_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_keytone_detect_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    KtDetectStop();
#endif

    aud_set_event(AUD_EVT_STOP_KT_DETECT);
}
#endif /*__KEY_TONE_DETECTION__*/


#endif /* MED_NOT_PRESENT */ 

