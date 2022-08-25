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
 * aud_ilm.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes send-ilm related funcions of audio manager task.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/*==== INCLUDES ===========*/

/* system includes */
//#include "kal_release.h"

//#include "kal_trace.h"

#include "stack_common.h"
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
//#include "fat_fs.h"
//#include "nvram_enums.h"
#include "nvram_struct.h"
//#include "nvram_user_defs.h"
#include "audio_nvram_def.h"
//#include "custom_nvram_editor_data_item.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_v_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "aud_main.h"
#include "med_utility.h"

#include "kal_general_types.h"
#include "stack_config.h"
#include "kal_public_api.h"
//#include "kal_active_module.h"
#include "stack_ltlcom.h"
#include "kal_public_defs.h"
#include "string.h"

#if defined(__MMI_SUPPORT_BACKLIGHT_SYNC__) || defined(__MMI_SUPPORT_LED_SYNC__) || defined(__MMI_SUPPORT_VIBRATOR_SYNC__)
/* -- added for turn on/off backlight by MMI task -- */
#include "mmiapi_enum.h"
#include "mmiapi_struct.h"
#endif

#ifdef __BT_SPEAKER_SUPPORT__
#include "bluetooth_a2dp_struct.h"
#endif

#ifdef __BT_HF_PROFILE__
#include "bt_hfadp_struct.h"
#endif 

#ifdef __BT_HFG_PROFILE__
#include "bluetooth_hfg_struct.h"
#endif
/*****************************************************************************
 * FUNCTION
 *  aud_send_ilm
 * DESCRIPTION
 *  This function is used to send ilm.
 * PARAMETERS
 *  dest_id             [IN]        
 *  msg_id              [IN]        
 *  local_param_ptr     [?]         
 *  peer_buf_ptr        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_ilm(module_type dest_id, kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    module_type src_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Check destination module ID */
    if (dest_id == MOD_NIL)
    {
        return;
    }

    /* Get source module ID */
    if (kal_if_hisr())
    {
        src_id = MOD_VISUAL_HISR;
    }
    else
    {
        src_id = kal_get_active_module_id();
    }
    
    ilm_ptr = allocate_ilm(src_id);
    ilm_ptr->src_mod_id = src_id;
    ilm_ptr->dest_mod_id = dest_id;
    
    switch (dest_id)
    {
        case MOD_NVRAM:
            ilm_ptr->sap_id = PS_NVRAM_SAP;
            break;
    #ifndef MED_V_NOT_PRESENT
        case MOD_MED_V:
            ilm_ptr->sap_id = MED_V_SAP;
            break;
    #endif /*MED_V_NOT_PRESENT*/
        case MOD_FMR:
            ilm_ptr->sap_id = FMR_SAP;
            break;	
        default: /*MOD_MED, MOD_UEM*/
            ilm_ptr->sap_id = MED_SAP;
            break;
    }
    
    ilm_ptr->msg_id = (msg_type) msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buf_ptr;

    msg_send_ext_queue(ilm_ptr);
}

#ifdef __CLASSAB_VOLUME_PROTECTION__
/*****************************************************************************
 * FUNCTION
 *  aud_send_battery_state_ind
 * DESCRIPTION
 *  This function sends a battery state indicator to the MMI.
 * PARAMETERS
 *  is_battery_low      [IN]      Indicate if the battery is low.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_battery_state_ind(kal_bool is_battery_low)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4audio_batt_state_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (l4audio_batt_state_ind_struct*)
        construct_local_para(sizeof(l4audio_batt_state_ind_struct), TD_CTRL);

    ind_p->is_battery_low = is_battery_low;

    aud_send_ilm(MOD_MMI, MSG_ID_L4AUD_BATTERY_STATE_IND, ind_p, NULL);
}
#endif /* __CLASSAB_VOLUME_PROTECTION__ */

#ifdef __CLASSK_CP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  aud_send_classk_state
 * DESCRIPTION
 *  This function sends a battery state indicator to the MMI.
 * PARAMETERS
 *  classk_state      [IN]      Indicate if the battery is low if true should 
enhance detect frequency.
 *                                     else we should reduce frequency
 * RETURNS
 *  void
 *****************************************************************************/

void aud_send_classk_state(kal_bool classk_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4audio_classk_state_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (l4audio_classk_state_ind_struct*)
        construct_local_para(sizeof(l4audio_classk_state_ind_struct), TD_CTRL);

    ind_p->classk_state= classk_state;

    aud_send_ilm(MOD_UEM, MSG_ID_L4AUD_CLASSK_STATE_IND, ind_p, NULL);
}

#endif /* __CLASSK_CP_SUPPORT__ */


#ifdef __VIBRATION_SPEAKER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  aud_send_vib_spk_calibration
 * DESCRIPTION
 *  This function sends a the msg of vibration current sensor  to MED.
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vib_spk_calibration()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_vib_spk_calibration_req_struct *msg_p = (media_aud_vib_spk_calibration_req_struct*)
        construct_local_para(sizeof(media_aud_vib_spk_calibration_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_AUD_VIB_SPK_CALIBRATION_REQ, msg_p);
}

/*****************************************************************************
 * FUNCTION
 *  aud_send_vib_spk_is_calib
 * DESCRIPTION
 *  This function sends a the confirm of vibration current sensor  MMI.
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vib_spk_is_calib()
{
	aud_send_ilm(MOD_MMI, MSG_ID_L4AUD_VIB_SPK_CALIBRATION_IND, NULL, NULL);

}
#endif

/*****************************************************************************
 * FUNCTION
 *  aud_send_mute_req
 * DESCRIPTION
 *  
 * PARAMETERS       
 *  vol_type            [IN]
 *  mute                [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mute_req(kal_uint8 vol_type, kal_bool mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_mute_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_aud_set_mute_req_struct*)
        construct_local_para(sizeof(media_aud_set_mute_req_struct), TD_CTRL);

    msg_p->mute = mute;
    msg_p->vol_type = vol_type;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_AUD_SET_MUTE_REQ, msg_p);
}

#ifdef __GAIN_TABLE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  aud_send_update_volume_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  vol_type            [IN]
 *  volume              [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_update_volume_req(module_type src_mod_id, kal_uint8 vol_type, kal_uint64 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_audio_update_volume_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (l4aud_audio_update_volume_req_struct *)
        construct_local_para(sizeof(l4aud_audio_update_volume_req_struct ), TD_CTRL);

    msg_p->audio_type = vol_type;
    msg_p->volume= volume;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_L4AUD_AUDIO_UPDATE_VOLUME_REQ, msg_p);
}
#endif /*__GAIN_TABLE_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  aud_send_set_volume_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vol_type            [IN]    Indicate the volume type to be set.
 *  volume              [IN]    Indicate the volume level to be set.
 *  apply               [IN]    Indicate if the volume should be applied immediately.
 *  blocking            [IN]    Indicate if it's a blocking way.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_set_volume_req(kal_uint8 vol_type, kal_uint64 volume, kal_bool apply, kal_bool blocking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_volume_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_aud_set_volume_req_struct *)
        construct_local_para(sizeof(media_aud_set_volume_req_struct ), TD_CTRL);

    msg_p->volume= volume;
    msg_p->aux_volume= volume;
    msg_p->audio_type = vol_type;
    msg_p->apply = apply;
    msg_p->blocking = blocking;

    aud_send_msg_to_med(NULL,(kal_uint16) MSG_ID_MEDIA_AUD_SET_VOLUME_REQ, msg_p);

    if (blocking)
    {
        aud_wait_event(AUD_EVT_SET_VOLUME);
    }
}

/*****************************************************************************
 * FUNCTION
 *  aud_send_set_audio_mode_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_mode          [IN]               
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_set_audio_mode_req(kal_uint8 audio_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_audio_mode_req_struct *msg_p = (media_aud_set_audio_mode_req_struct*)
        construct_local_para(sizeof(media_aud_set_audio_mode_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->src_id = 0;
    msg_p->mode = audio_mode;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_AUD_SET_AUDIO_MODE_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_set_device_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_type          [IN]
 *  device          [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_set_device_req(kal_uint8 audio_type, kal_uint8 device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_device_req_struct *msg_p = (media_aud_set_device_req_struct*)
        construct_local_para(sizeof(media_aud_set_device_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->audio_type = audio_type;
    msg_p->device = device;
    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_AUD_SET_DEVICE_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_audio_play_finish_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_audio_play_finish_ind(kal_uint8 result, kal_uint16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_play_finish_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* send indication message to L4 */
    ind_p = (media_aud_play_finish_ind_struct*)
        construct_local_para(sizeof(media_aud_play_finish_ind_struct), TD_CTRL);

    ind_p->result = result;
    ind_p->identifier = id;

    aud_send_ilm(aud_context_p->src_mod, MSG_ID_MEDIA_AUD_PLAY_FINISH_IND, ind_p, NULL);
}


#ifdef __GAIN_TABLE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  aud_send_state_change_ind
 * DESCRIPTION
 *  This function sends a state-changed indicator to the MMI.
 * PARAMETERS
 *  reason      [IN]      aud_state_change_reason_enum.  
 *  data_p      [IN]      Data of the indicator.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_state_change_ind(kal_uint8 reason, void* data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_audio_state_change_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* send indication message to L4 */
    ind_p = (l4aud_audio_state_change_ind_struct*)
        construct_local_para(sizeof(l4aud_audio_state_change_ind_struct), TD_CTRL);

    ind_p->reason = reason;
    ind_p->data_p = data_p;

    aud_send_ilm(MOD_MMI, MSG_ID_L4AUD_AUDIO_STATE_CHANGE_IND, ind_p, NULL);
}
#endif /*__GAIN_TABLE_SUPPORT__*/


/*****************************************************************************
 * FUNCTION
 *  aud_send_msg_to_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_name        [IN]        
 *  ef_id           [IN]        
 *  data_ptr        [?]         
 *  length          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_msg_to_nvram(msg_type msg_name, kal_uint16 ef_id, void *data_ptr, kal_uint16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    peer_buff_struct *data_stream;
    local_para_struct *parm_stream;
    kal_uint16 pdu_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_name)
    {
        case MSG_ID_NVRAM_WRITE_REQ:
            switch (ef_id)
            {
                case NVRAM_EF_CUST_ACOUSTIC_DATA_LID:
                case NVRAM_EF_AUDIO_PARAM_LID:
                case NVRAM_EF_AUDIO_DC_CALIBRATION_LID:
					
			#ifdef __VIBRATION_SPEAKER_SUPPORT__
				case NVRAM_EF_AUDIO_VIBR_LID:
			#endif 
            #ifdef __AMRWB_LINK_SUPPORT__
                case NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_LID:
                case NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_LID:
                case NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_LID:
            #endif /* __AMRWB_LINK_SUPPORT__ */
			#ifdef __VOICE_CHANGER_SUPPORT__
				case NVRAM_EF_AUDIO_VOICE_CHANGER_LID:
			#endif 
			#ifdef __AUDIO_AT_CMD__
				case NVRAM_EF_AUDIO_AT_SPEECH_INFO_LID:
			#endif
                    parm_stream = construct_local_para(sizeof(nvram_write_req_struct), TD_CTRL);
                    data_stream = construct_peer_buff(length, 0, 0, TD_CTRL);

                    ((nvram_write_req_struct*) parm_stream)->file_idx = (kal_uint16) ef_id;
                    ((nvram_write_req_struct*) parm_stream)->para = 1;
                    ((nvram_write_req_struct*) parm_stream)->access_id = 0;

                    pdu_len = length;
                    kal_mem_cpy(get_pdu_ptr(data_stream, &pdu_len), data_ptr, length);

                    aud_send_ilm(MOD_NVRAM, MSG_ID_NVRAM_WRITE_REQ, parm_stream, data_stream);
                    break;
                default:
                    /* error write */
                    break;
            }
            break;
        case MSG_ID_NVRAM_READ_REQ:
            switch (ef_id)
            {
                case NVRAM_EF_CUST_ACOUSTIC_DATA_LID:
                case NVRAM_EF_AUDIO_PARAM_LID:
                case NVRAM_EF_AUDIO_DC_CALIBRATION_LID:
            #ifdef __GAIN_TABLE_SUPPORT__
                case NVRAM_EF_AUDIO_GAIN_TABLE_LID:
            #endif /* __GAIN_TABLE_SUPPORT__ */
            #ifdef __SPEECH_MODE_TABLE_SUPPORT__
                case NVRAM_EF_AUDIO_SPEECH_MODE_TABLE_LID:
            #endif /* __SPEECH_MODE_TABLE_SUPPORT__ */
            #ifdef __AMRWB_LINK_SUPPORT__
                case NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_LID:
                case NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_LID:
                case NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_LID:
            #endif /* __AMRWB_LINK_SUPPORT__ */
            #ifdef __DUAL_MIC_SUPPORT__
                case NVRAM_EF_AUDIO_DUAL_MIC_PARAM_LID:
            #endif
            #ifdef __AUDIO_COMPENSATION_SW_VERSION__
                case NVRAM_EF_AUDIO_SWFIR_LID:
            #endif
            #ifdef __BES_LOUDNESS_SUPPORT__
                case NVRAM_EF_AUDIO_BESLOUDNESS_LID:
            #endif
            #ifdef __BES_EQ_SUPPORT__
                case NVRAM_EF_AUDIO_BES_EQ_FLEXIBLE_LID:
            #endif			
			#ifdef __VIBRATION_SPEAKER_SUPPORT__
                case NVRAM_EF_AUDIO_VIBR_LID:
			#endif
            #ifdef __HD_RECORD__
                case NVRAM_EF_AUDIO_HD_RECORD_LID:
            #endif
            #ifdef __VOICE_CHANGER_SUPPORT__
				case NVRAM_EF_AUDIO_VOICE_CHANGER_LID:
            #endif
			#ifdef __AUDIO_AT_CMD__
			    case NVRAM_EF_AUDIO_AT_SPEECH_INFO_LID:
            #endif 
                    parm_stream = construct_local_para(sizeof(nvram_read_req_struct), TD_CTRL);

                    ((nvram_read_req_struct*) parm_stream)->file_idx = (kal_uint16) ef_id;
                    ((nvram_read_req_struct*) parm_stream)->para = 1;

                    aud_send_ilm(MOD_NVRAM, MSG_ID_NVRAM_READ_REQ, parm_stream, NULL);
                    break;
                default:
                    /* error read */
                    break;
            }
            break;
        default:
            break;
    }   /* End Switch */

    return;
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_startup_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_startup_cnf(kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_startup_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_p = (med_startup_cnf_struct*) construct_local_para(sizeof(med_startup_cnf_struct), TD_CTRL);

    /* send confirm message to L4 */
    cnf_p->result = result;

    aud_send_ilm(aud_context_p->src_mod, MSG_ID_MED_STARTUP_CNF, cnf_p, NULL);

}

typedef enum
{
    AUD_SET_COMMON_CNF_1,
    AUD_SET_COMMON_CNF_2
} aus_set_common_struct_enum;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    kal_uint16 cause;
}
aud_set_common_cnf1_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
aud_set_common_cnf2_struct;


/*****************************************************************************
 * FUNCTION
 *  _aud_send_set_common_struct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]  
 * RETURNS
 *  kal_bool
 *****************************************************************************/
static void _aud_send_set_common_struct(aus_set_common_struct_enum style ,void* msg_p, kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(style)
    {
        case AUD_SET_COMMON_CNF_1:
        {
            ((aud_set_common_cnf1_struct*)msg_p)->src_id = aud_context_p->src_id;

            if(result == 0) /* MED_RES_OK */
            {
                ((aud_set_common_cnf1_struct*)msg_p)->result = KAL_TRUE;
            }
            else
            {
                ((aud_set_common_cnf1_struct*)msg_p)->result = KAL_FALSE;
            }
            
            ((aud_set_common_cnf1_struct*)msg_p)->cause = result;

            break;
        }

        case AUD_SET_COMMON_CNF_2:
        {
            ((aud_set_common_cnf2_struct*)msg_p)->src_id = aud_context_p->src_id;
            ((aud_set_common_cnf2_struct*)msg_p)->result = result;
            break;
        }
    }


}

/*****************************************************************************
 * FUNCTION
 *  aud_send_set_audio_profile_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_set_audio_profile_cnf(kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_audio_profile_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_p = (media_aud_set_audio_profile_cnf_struct*)
        construct_local_para(sizeof(media_aud_set_audio_profile_cnf_struct), TD_CTRL);

    _aud_send_set_common_struct(AUD_SET_COMMON_CNF_1,(void*)cnf_p,result);


    aud_send_ilm(aud_context_p->src_mod, MSG_ID_MEDIA_AUD_SET_AUDIO_PROFILE_CNF, cnf_p, NULL);

}

#ifdef __AMRWB_LINK_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  aud_send_set_audio_wb_input_fir_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_set_audio_wb_input_fir_cnf(kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_audio_wb_input_fir_param_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_p = (media_aud_set_audio_wb_input_fir_param_cnf_struct*)
        construct_local_para(sizeof(media_aud_set_audio_wb_input_fir_param_cnf_struct), TD_CTRL);

    _aud_send_set_common_struct(AUD_SET_COMMON_CNF_1,(void*)cnf_p,result);

    aud_send_ilm(aud_context_p->src_mod, MSG_ID_MEDIA_AUD_SET_AUDIO_WB_INPUT_FIR_PARAM_CNF, cnf_p, NULL);

}

/*****************************************************************************
 * FUNCTION
 *  aud_send_set_audio_wb_output_fir_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input       [IN]
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_set_audio_wb_output_fir_cnf(kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    media_aud_set_audio_wb_output_fir_param_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_p = (media_aud_set_audio_wb_output_fir_param_cnf_struct*)
        construct_local_para(sizeof(media_aud_set_audio_wb_output_fir_param_cnf_struct), TD_CTRL);

    _aud_send_set_common_struct(AUD_SET_COMMON_CNF_1,(void*)cnf_p,result);

    aud_send_ilm(aud_context_p->src_mod, MSG_ID_MEDIA_AUD_SET_AUDIO_WB_OUTPUT_FIR_PARAM_CNF, cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  aud_send_set_audio_wb_mode_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_set_audio_wb_mode_cnf(kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_audio_wb_mode_param_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_p = (media_aud_set_audio_wb_mode_param_cnf_struct*)
        construct_local_para(sizeof(media_aud_set_audio_wb_mode_param_cnf_struct), TD_CTRL);

    _aud_send_set_common_struct(AUD_SET_COMMON_CNF_1,(void*)cnf_p,result);

    aud_send_ilm(aud_context_p->src_mod, MSG_ID_MEDIA_AUD_SET_AUDIO_WB_MODE_PARAM_CNF, cnf_p, NULL);

}

#endif /*__AMRWB_LINK_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  aud_send_set_audio_param_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_set_audio_param_cnf(kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_audio_param_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_p = (media_aud_set_audio_param_cnf_struct*)
        construct_local_para(sizeof(media_aud_set_audio_param_cnf_struct), TD_CTRL);

    _aud_send_set_common_struct(AUD_SET_COMMON_CNF_1,(void*)cnf_p,result);

    aud_send_ilm(aud_context_p->src_mod, MSG_ID_MEDIA_AUD_SET_AUDIO_PARAM_CNF, cnf_p, NULL);

}

#if defined(__MED_AUD_REC_MOD__)

/*****************************************************************************
 * FUNCTION
 *  aud_send_media_record_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_media_record_cnf(kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_media_record_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_p = (l4aud_media_record_cnf_struct*) construct_local_para(sizeof(l4aud_media_record_cnf_struct), TD_CTRL);
    
    _aud_send_set_common_struct(AUD_SET_COMMON_CNF_2,(void*)cnf_p,result);

    aud_send_ilm(aud_context_p->src_mod, MSG_ID_L4AUD_MEDIA_RECORD_CNF, cnf_p, NULL);

}

#endif /*__MED_AUD_REC_MOD__*/

/*****************************************************************************
 * FUNCTION
 *  aud_send_media_play_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_media_play_cnf(kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_play_by_file_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_p = (media_aud_play_by_file_cnf_struct*) construct_local_para(sizeof(media_aud_play_by_file_cnf_struct), TD_CTRL);

    _aud_send_set_common_struct(AUD_SET_COMMON_CNF_2,(void*)cnf_p,result);

    aud_send_ilm(aud_context_p->src_mod, MSG_ID_MEDIA_AUD_PLAY_BY_FILE_CNF, cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  aud_send_media_stop_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  file_name       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_media_stop_cnf(kal_uint8 result, kal_wchar *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_stop_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_p = (media_aud_stop_cnf_struct*) construct_local_para(sizeof(media_aud_stop_cnf_struct), TD_CTRL);

    _aud_send_set_common_struct(AUD_SET_COMMON_CNF_2,(void*)cnf_p,result);

    aud_send_ilm(aud_context_p->src_mod, MSG_ID_MEDIA_AUD_STOP_CNF, cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  aud_send_media_pause_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  file_name       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_media_pause_cnf(kal_uint8 result, kal_wchar *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_media_pause_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_p = (l4aud_media_pause_cnf_struct*) construct_local_para(sizeof(l4aud_media_pause_cnf_struct), TD_CTRL);

    _aud_send_set_common_struct(AUD_SET_COMMON_CNF_2,(void*)cnf_p,result);

    aud_send_ilm(aud_context_p->src_mod, MSG_ID_L4AUD_MEDIA_PAUSE_CNF, cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  aud_send_media_resume_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_media_resume_cnf(kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_media_resume_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_p = (l4aud_media_resume_cnf_struct*) construct_local_para(sizeof(l4aud_media_resume_cnf_struct), TD_CTRL);

    _aud_send_set_common_struct(AUD_SET_COMMON_CNF_2,(void*)cnf_p,result);

    aud_send_ilm(aud_context_p->src_mod, MSG_ID_L4AUD_MEDIA_RESUME_CNF, cnf_p, NULL);

}

#if defined(__MED_AUD_REC_MOD__)

/*****************************************************************************
 * FUNCTION
 *  aud_send_media_record_finish_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_media_record_finish_ind(kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_media_record_finish_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* send indication message to L4 */
    ind_p = (l4aud_media_record_finish_ind_struct*)
        construct_local_para(sizeof(l4aud_media_record_finish_ind_struct), TD_CTRL);

    _aud_send_set_common_struct(AUD_SET_COMMON_CNF_2,(void*)ind_p,result);

    aud_send_ilm(aud_context_p->src_mod, MSG_ID_L4AUD_MEDIA_RECORD_FINISH_IND, ind_p, NULL);
}

#endif /* __MED_AUD_REC_MOD__ */

/* for aud_api.c, to send message to media task */


/*****************************************************************************
 * FUNCTION
 *  aud_send_play_id_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  id_param        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_play_id_req(void *id_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_play_id_struct *data_p = (aud_play_id_struct*) id_param;
    media_aud_play_by_id_req_struct *msg_p = (media_aud_play_by_id_req_struct*)
        construct_local_para(sizeof(media_aud_play_by_id_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->audio_id = data_p->audio_id;
    msg_p->play_style = data_p->play_style;
    msg_p->volume = data_p->volume;
    msg_p->output_path = data_p->output_path;
    msg_p->identifier = data_p->identifier;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_AUD_PLAY_BY_ID_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_stop_id_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  audio_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_stop_id_req(kal_uint8 audio_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_stop_by_id_req_struct *msg_p = (media_aud_stop_by_id_req_struct*)
        construct_local_para(sizeof(media_aud_stop_by_id_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->audio_id = audio_id;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_AUD_STOP_BY_ID_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_play_string_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  string_param        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_play_string_req(void *string_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_play_string_struct *data_p = (aud_play_string_struct*) string_param;
    media_aud_play_by_string_req_struct *msg_p = (media_aud_play_by_string_req_struct*)
        construct_local_para(sizeof(media_aud_play_by_string_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->src_id = 0;
    msg_p->melody = (const kal_uint8*)data_p->data_p;
    msg_p->format = data_p->format;
    msg_p->len = data_p->len;
    msg_p->play_style = data_p->play_style;
    msg_p->volume = data_p->volume;
    msg_p->output_path = data_p->output_path;
    msg_p->identifier = data_p->identifier;
    msg_p->blocking = data_p->blocking;
    msg_p->start_offset = data_p->start_offset;
    msg_p->end_offset = data_p->end_offset;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_AUD_PLAY_BY_STRING_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_stop_string_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  src_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_stop_string_req(kal_uint8 src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_stop_by_string_req_struct *msg_p = (media_aud_stop_by_string_req_struct*)
        construct_local_para(sizeof(media_aud_stop_by_string_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->src_id = src_id;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_AUD_STOP_BY_STRING_REQ, msg_p);
}


#if defined(__MED_AUD_FS_ACCESS__)
/*****************************************************************************
 * FUNCTION
 *  aud_send_play_file_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  file_param      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_play_file_req(void *file_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_play_file_struct *data_p = (aud_play_file_struct*) file_param;
    media_aud_play_by_file_req_struct *msg_p = (media_aud_play_by_file_req_struct*)
        construct_local_para(sizeof(media_aud_play_by_file_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->src_id = 0;
    kal_wstrncpy(msg_p->file_name, data_p->file_name_p, MAX_MEDIA_FILE_NAME);
    //kal_mem_cpy(msg_p->file_name, data_p->file_name_p, MAX_MEDIA_FILE_NAME * 2);
    msg_p->play_style = data_p->play_style;
    msg_p->volume = data_p->volume;
    msg_p->output_path = data_p->output_path;
    msg_p->identifier = data_p->identifier;
    msg_p->start_offset = data_p->start_offset;
    msg_p->end_offset = data_p->end_offset;
    msg_p->cache_p = data_p->cache_p;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_AUD_PLAY_BY_FILE_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_stop_file_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  src_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_stop_file_req(kal_uint8 src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_stop_req_struct *msg_p = (media_aud_stop_req_struct*)
        construct_local_para(sizeof(media_aud_stop_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->src_id = src_id;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_AUD_STOP_REQ, msg_p);
}
#endif /*__MED_AUD_FS_ACCESS__*/


#if defined(__MED_AUD_REC_MOD__)

/*****************************************************************************
 * FUNCTION
 *  aud_send_record_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name           [?]         
 *  format              [IN]        
 *  default_input       [IN]        
 *  input_source        [IN]        
 *  size_limit          [IN]        Max record size in byte. 0: unlimited
 *  time_limit          [IN]        Max record time in sec.  0: unlimited
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_record_req(
        //module_type src_mod_id,
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
    l4aud_media_record_req_struct *msg_p = (l4aud_media_record_req_struct*)
        construct_local_para(sizeof(l4aud_media_record_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wstrncpy(msg_p->file_name, file_name, MAX_MEDIA_FILE_NAME);
    //kal_mem_cpy(msg_p->file_name, file_name, MAX_MEDIA_FILE_NAME * ENCODE_BYTE);
    msg_p->format = format;
    msg_p->quality = quality;
    msg_p->default_input = default_input;
    msg_p->input_source = input_source;
    msg_p->size_limit = size_limit;
    msg_p->time_limit = time_limit;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_L4AUD_MEDIA_RECORD_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_stop_record_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_stop_record_req(kal_uint8 src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_stop_req_struct *msg_p = (media_aud_stop_req_struct*)
        construct_local_para(sizeof(media_aud_stop_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->src_id = src_id;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_AUD_STOP_REQ, msg_p);
}

#endif /* __MED_AUD_REC_MOD__ */

/*****************************************************************************
 * FUNCTION
 *  aud_send_pause_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_pause_req(kal_uint8 src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_media_pause_req_struct *msg_p = (l4aud_media_pause_req_struct*)
        construct_local_para(sizeof(l4aud_media_pause_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->src_id = src_id;
    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_L4AUD_MEDIA_PAUSE_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_resume_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_resume_req(kal_uint8 src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_media_resume_req_struct *msg_p = (l4aud_media_resume_req_struct*)
        construct_local_para(sizeof(l4aud_media_resume_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->src_id = src_id;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_L4AUD_MEDIA_RESUME_REQ, msg_p);
}


#if defined(__MED_AUD_FS_ACCESS__)
/*****************************************************************************
 * FUNCTION
 *  aud_send_store_req
 * DESCRIPTION
 *  
 * PARAMETERS      
 *  src_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_store_req(kal_uint8 src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_media_store_req_struct *msg_p = (l4aud_media_store_req_struct*)
        construct_local_para(sizeof(l4aud_media_store_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->src_id = src_id;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_L4AUD_MEDIA_STORE_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_restore_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_param      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_restore_req(void *file_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_play_file_struct *data_p = (aud_play_file_struct*) file_param;
    l4aud_media_restore_req_struct *msg_p = (l4aud_media_restore_req_struct*)
        construct_local_para(sizeof(l4aud_media_restore_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->src_id = 0;
    //kal_mem_cpy(msg_p->file_name, data_p->file_name_p, MAX_MEDIA_FILE_NAME * 2);
    kal_wstrncpy(msg_p->file_name, data_p->file_name_p, MAX_MEDIA_FILE_NAME);
    msg_p->play_style = data_p->play_style;
    msg_p->volume = data_p->volume;
    msg_p->output_path = data_p->output_path;
    msg_p->identifier = data_p->identifier;
    msg_p->start_offset = data_p->start_offset;
    msg_p->end_offset = data_p->end_offset;
    msg_p->cache_p = data_p->cache_p ;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_L4AUD_MEDIA_RESTORE_REQ, msg_p);
}
#endif /*__MED_AUD_FS_ACCESS__*/


/*****************************************************************************
 * FUNCTION
 *  aud_send_set_headset_mode_output_path_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  device          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_set_headset_mode_output_path_req(kal_uint8 device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_headset_mode_output_path_struct *msg_p = (media_aud_set_headset_mode_output_path_struct*)
        construct_local_para(sizeof(media_aud_set_headset_mode_output_path_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->device = device;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_AUD_SET_HEADSET_MODE_OUTPUT_PATH, msg_p);
}

#ifdef __MED_IMY_EVENT__
/*****************************************************************************
 * FUNCTION
 *  aud_send_set_vibrator_enabled_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  enable          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_set_vibrator_enabled_req(kal_uint8 enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_vibrator_enabled_req_struct *msg_p = (media_aud_set_vibrator_enabled_req_struct*)
        construct_local_para(sizeof(media_aud_set_vibrator_enabled_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->enabled = enable;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_AUD_SET_VIBRATOR_ENABLED_REQ, msg_p);
}
#endif /*__MED_IMY_EVENT__*/

#ifdef __SPECTRUM_DISPLAY_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  aud_send_start_calc_spectrum_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_start_calc_spectrum_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_start_calc_spectrum_req_struct *msg_p = (media_aud_start_calc_spectrum_req_struct*)
        construct_local_para(sizeof(media_aud_start_calc_spectrum_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_AUD_START_CALC_SPECTRUM_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_stop_calc_spectrum_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_stop_calc_spectrum_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_stop_calc_spectrum_req_struct *msg_p = (media_aud_stop_calc_spectrum_req_struct*)
        construct_local_para(sizeof(media_aud_stop_calc_spectrum_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_AUD_STOP_CALC_SPECTRUM_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_get_spectrum_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  top_p           [?]         
 *  val_p           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_get_spectrum_req(kal_uint8 *top_p, kal_uint8 *val_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_get_spectrum_req_struct *msg_p = (media_aud_get_spectrum_req_struct*)
        construct_local_para(sizeof(media_aud_get_spectrum_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->top_p = top_p;
    msg_p->val_p = val_p;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_AUD_GET_SPECTRUM_REQ, msg_p);
}
#endif /* __SPECTRUM_DISPLAY_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  aud_send_get_duration_req
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_get_duration_req(kal_bool default_handle,
                               void *file_name,
                               kal_uint8 *audio_data,
                               kal_uint32 len,
                               kal_uint8 format,
                               kal_bool full_duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_get_duration_req_struct *msg_p = (media_aud_get_duration_req_struct*)
        construct_local_para(sizeof(media_aud_get_duration_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* Must either file name or data string */
	MED_ASSERT(!default_handle && 
	       ((audio_data != NULL && file_name == NULL) || (audio_data == NULL && file_name != NULL)));

    kal_mem_set(msg_p->file_name, 0, (MAX_MEDIA_FILE_PATH_LEN + 1) * sizeof(kal_wchar));
    msg_p->use_default_handle = KAL_FALSE;
    msg_p->audio_data = NULL;
    msg_p->len = 0;
    msg_p->format = 0;

    if(default_handle)
    {
        msg_p->use_default_handle = KAL_TRUE;		
    }
    else if(file_name != NULL)
    {
        kal_wstrncpy(msg_p->file_name, file_name, (MAX_MEDIA_FILE_PATH_LEN + 1));
        msg_p->use_default_handle = KAL_FALSE;
    }
    else
    {
        msg_p->audio_data = audio_data;
        msg_p->len = len;
        msg_p->format = format;    
    }
    msg_p->full_duration = full_duration;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_AUD_GET_DURATION_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_get_progress_time_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_get_progress_time_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_get_progress_time_req_struct *msg_p = (media_aud_get_progress_time_req_struct*)
        construct_local_para(sizeof(media_aud_get_progress_time_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_AUD_GET_PROGRESS_TIME_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_set_progress_time_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  progress        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_set_progress_time_req(kal_uint32 progress)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_progress_time_req_struct *msg_p = (media_aud_set_progress_time_req_struct*)
        construct_local_para(sizeof(media_aud_set_progress_time_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->progress = progress;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_AUD_SET_PROGRESS_TIME_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_check_is_pure_audio_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_check_is_pure_audio_req(void *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_check_is_pure_audio_req_struct *msg_p = (media_aud_check_is_pure_audio_req_struct*)
        construct_local_para(sizeof(media_aud_check_is_pure_audio_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //kal_mem_cpy(msg_p->file_name, file_name, MAX_MEDIA_FILE_NAME * 2);
    kal_wstrncpy(msg_p->file_name, file_name, MAX_MEDIA_FILE_NAME);

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_AUD_CHECK_IS_PURE_AUDIO_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_check_is_file_seekable_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_check_is_file_seekable_req(void *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_check_is_file_seekable_req_struct *msg_p = (media_aud_check_is_file_seekable_req_struct*)
        construct_local_para(sizeof(media_aud_check_is_file_seekable_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //kal_mem_cpy(msg_p->file_name, file_name, MAX_MEDIA_FILE_NAME * 2);
    kal_wstrncpy(msg_p->file_name, file_name, MAX_MEDIA_FILE_NAME);

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_AUD_CHECK_IS_FILE_SEEKABLE_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_check_is_file_pausable_req
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_check_is_file_pausable_req(void *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_check_is_file_pausable_req_struct *msg_p = (media_aud_check_is_file_pausable_req_struct*)
        construct_local_para(sizeof(media_aud_check_is_file_pausable_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wstrncpy(msg_p->file_name, file_name, MAX_MEDIA_FILE_NAME);

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_AUD_CHECK_IS_FILE_PAUSABLE_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_check_is_resource_available_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  resource    [IN]    Audio resource.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_check_is_resource_available_req(aud_resource_enum resource)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_check_is_resource_available_req_struct *msg_p = (media_aud_check_is_resource_available_req_struct*)
        construct_local_para(sizeof(media_aud_check_is_resource_available_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->resource = (kal_uint8)resource;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_AUD_CHECK_IS_RESOURCE_AVAILABLE_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_fmr_seek_continue
 * DESCRIPTION
 *  send message to med_v to start fm seeking
 * PARAMETERS
 *  src_id          [IN]        
 *  local_param_ptr [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_fmr_seek_continue(module_type src_id, void *local_param_ptr)
{
#ifndef MED_V_NOT_PRESENT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_ilm(MOD_MED_V, MSG_ID_MEDIA_FMR_SEEK_CALLBACK_IND, local_param_ptr, NULL); 
#endif /* MED_V_NOT_PRESENT */
}

#ifndef MED_V_NOT_PRESENT
/*****************************************************************************
 * FUNCTION
 *  aud_send_start_seek_req
 * DESCRIPTION
 *  send message to med_v to start audio build cache
 * PARAMETERS
 *  local_param_ptr [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_start_seek_req(void *local_param_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_ilm(MOD_MED_V, MSG_ID_MEDIA_AUDIO_START_SEEK_REQ, local_param_ptr, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  aud_send_stop_seek_req
 * DESCRIPTION
 *  send message to med_v to start audio build cache
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_stop_seek_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_ilm(MOD_MED_V, MSG_ID_MEDIA_AUDIO_STOP_SEEK_REQ, NULL, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  aud_send_start_build_cache_req
 * DESCRIPTION
 *  send message to med_v to start building cache in asynchronous manner.
 * PARAMETERS
 *  local_param_ptr [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_start_build_cache_async_req(void *local_param_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_ilm(MOD_MED_V, MSG_ID_MEDIA_AUDIO_START_BUILD_CACHE_ASYNC_REQ, local_param_ptr, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  aud_send_close_build_cache_async_req
 * DESCRIPTION
 *  Send message to med_v to close the build cache context
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_close_build_cache_async_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_ilm(MOD_MED_V, MSG_ID_MEDIA_AUDIO_CLOSE_BUILD_CACHE_ASYNC_REQ, NULL, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  aud_send_start_build_cache_req
 * DESCRIPTION
 *  send message to med_v to start audio build cache
 * PARAMETERS
 *  local_param_ptr [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_start_build_cache_req(void *local_param_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_ilm(MOD_MED_V, MSG_ID_MEDIA_AUDIO_START_BUILD_CACHE_REQ, local_param_ptr, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  aud_send_stop_build_cache_req
 * DESCRIPTION
 *  Send message to med_v to stop the building process
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_stop_build_cache_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_ilm(MOD_MED_V, MSG_ID_MEDIA_AUDIO_STOP_BUILD_CACHE_REQ, NULL, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  aud_send_close_build_cache_req
 * DESCRIPTION
 *  Send message to med_v to close the build cache context
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_close_build_cache_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_ilm(MOD_MED_V, MSG_ID_MEDIA_AUDIO_CLOSE_BUILD_CACHE_REQ, NULL, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  aud_send_reset_build_cache_vars_req
 * DESCRIPTION
 *  Send message to med_v to reset build cache variables
 * PARAMETERS
 *  void  
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_reset_build_cache_vars_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_ilm(MOD_MED_V, MSG_ID_MEDIA_AUDIO_RESET_BUILD_CACHE_VARS_REQ, NULL, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  aud_send_build_cache_fail_ind
 * DESCRIPTION
 *  send message to MMI to inform build cache fail
 * PARAMETERS
 *       
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_build_cache_fail_ind()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_ilm(MOD_MMI, MSG_ID_MEDIA_AUDIO_BUILD_CACHE_FAIL_IND, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_run_low_priority_in_medv_req
 * DESCRIPTION
 *  send message to MEDV to execute the function requested
 * PARAMETERS
 *       
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_run_low_priority_in_medv_req(module_type src_id, void (*func_p)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_run_low_priority_process_struct *msg_p = (media_visual_run_low_priority_process_struct*)
        construct_local_para(sizeof(media_visual_run_low_priority_process_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->func_p = func_p;

    aud_send_ilm(MOD_MED_V, MSG_ID_MEDIA_V_RUN_LOW_PRIORITY_REQ, msg_p, NULL); 
}

/*****************************************************************************
 * FUNCTION
 *  aud_send_run_low_priority_in_medv_cnf
 * DESCRIPTION
 *  send message to des_id to inform the low priority action has been done
 * PARAMETERS
 *       
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_run_low_priority_in_medv_cnf(module_type des_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_ilm(des_id, MSG_ID_MEDIA_V_RUN_LOW_PRIORITY_CNF, NULL, NULL);
}

#if defined(__MED_AUD_REC_MOD__)
/*****************************************************************************
 * FUNCTION
 *  aud_send_med_v_start_record_req
 * DESCRIPTION
 * 
 * PARAMETERS
 *       
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_med_v_start_record_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_ilm(MOD_MED_V, MSG_ID_MEDIA_V_AUDIO_START_RECORD_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_med_v_stop_record_req
 * DESCRIPTION
 * 
 * PARAMETERS
 *       
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_med_v_stop_record_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_ilm(MOD_MED_V, MSG_ID_MEDIA_V_AUDIO_STOP_RECORD_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_med_v_pause_record_req
 * DESCRIPTION
 * 
 * PARAMETERS
 *       
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_med_v_pause_record_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_ilm(MOD_MED_V, MSG_ID_MEDIA_V_AUDIO_PAUSE_RECORD_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_med_v_resume_record_req
 * DESCRIPTION
 * 
 * PARAMETERS
 *       
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_med_v_resume_record_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_ilm(MOD_MED_V, MSG_ID_MEDIA_V_AUDIO_RESUME_RECORD_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_med_v_read_data_ind
 * DESCRIPTION
 * 
 * PARAMETERS
 *       
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_med_v_read_data_ind(kal_uint8 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_v_audio_read_data_ind_struct *ind_p = NULL;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_v_audio_read_data_ind_struct*) construct_local_para(sizeof(media_v_audio_read_data_ind_struct), TD_CTRL);
    ind_p->event = event;

    aud_send_ilm(MOD_MED_V, MSG_ID_MEDIA_V_AUDIO_READ_DATA_IND, ind_p, NULL);
}
#endif /*__MED_AUD_REC_MOD__*/

#ifdef AUD_BGSND_PLAY_FROM_MEDV
/*****************************************************************************
 * FUNCTION
 *  aud_send_med_v_bgsnd_play_req
 * DESCRIPTION
 * 
 * PARAMETERS
 *       
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_med_v_bgsnd_play_req(kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_v_audio_bgsnd_play_req_struct *ind_p = NULL;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_v_audio_bgsnd_play_req_struct*) 
                construct_local_para(sizeof(media_v_audio_bgsnd_play_req_struct), TD_CTRL);
    ind_p->result = result;

    aud_send_ilm(MOD_MED_V, MSG_ID_MEDIA_V_AUDIO_BGSND_PLAY_REQ, ind_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_med_v_bgsnd_stop_req
 * DESCRIPTION
 * 
 * PARAMETERS
 *       
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_med_v_bgsnd_stop_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_ilm(MOD_MED_V, MSG_ID_MEDIA_V_AUDIO_BGSND_STOP_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_med_v_bgsnd_process_data_ind
 * DESCRIPTION
 * 
 * PARAMETERS
 *       
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_med_v_bgsnd_process_data_ind(kal_uint8 event, kal_uint32 snd_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_v_audio_bgsnd_process_event_ind_struct *ind_p = NULL;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_v_audio_bgsnd_process_event_ind_struct*) 
                construct_local_para(sizeof(media_v_audio_bgsnd_process_event_ind_struct), TD_CTRL);
    
    ind_p->event = event;
    ind_p->snd_handle = snd_handle;

    aud_send_ilm(MOD_MED_V, MSG_ID_MEDIA_V_AUDIO_BGSND_PROCESS_EVENT_IND, ind_p, NULL);
}
#endif /* #ifdef AUD_BGSND_PLAY_FROM_MEDV */

#endif /* MED_V_NOT_PRESENT*/

/*****************************************************************************
 * FUNCTION
 *  aud_send_update_duration_ind
 * DESCRIPTION
 *  send message to MMI to invoke update duration
 * PARAMETERS
 *       
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_update_duration_ind(kal_uint32 duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_media_play_update_dur_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (l4aud_media_play_update_dur_ind_struct*)
      construct_local_para(sizeof(l4aud_media_play_update_dur_ind_struct), TD_CTRL);

    ind_p->duration = duration;
    ind_p->identifier = aud_context_p->identifier;

    aud_send_ilm(MOD_MMI, MSG_ID_L4AUD_MEDIA_UPDATE_DUR_IND, ind_p, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  aud_send_fmr_power_on_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  output_path     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_fmr_power_on_req(kal_uint8 output_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_power_on_req_struct *msg_p = (media_fmr_power_on_req_struct*)
        construct_local_para(sizeof(media_fmr_power_on_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->output_path = output_path;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_FMR_POWER_ON_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_fmr_power_off_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_fmr_power_off_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_power_off_req_struct *msg_p = (media_fmr_power_off_req_struct*)
        construct_local_para(sizeof(media_fmr_power_off_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_FMR_POWER_OFF_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_fmr_set_output_path_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  output_path     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_fmr_set_output_path_req(kal_uint8 output_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_set_output_path_req_struct *msg_p = (media_fmr_set_output_path_req_struct*)
        construct_local_para(sizeof(media_fmr_set_output_path_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->output_path = output_path;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_FMR_SET_OUTPUT_PATH_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_fmr_set_freq_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  freq            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_fmr_set_freq_req(kal_uint16 freq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_set_freq_req_struct *msg_p = (media_fmr_set_freq_req_struct*)
        construct_local_para(sizeof(media_fmr_set_freq_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->freq = freq;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_FMR_SET_FREQ_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_fmr_mute_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mute            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_fmr_mute_req(kal_uint8 mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_mute_req_struct *msg_p = (media_fmr_mute_req_struct*)
        construct_local_para(sizeof(media_fmr_mute_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->mute = mute;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_FMR_MUTE_REQ, msg_p);
}

/*****************************************************************************
 * FUNCTION
 *  aud_send_fmr_set_channel_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_fmr_set_channel_req(kal_bool is_mono)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_set_channel_req_struct *msg_p = (media_fmr_set_channel_req_struct*)
        construct_local_para(sizeof(media_fmr_set_channel_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->is_mono = is_mono;
    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_FMR_SET_CHANNEL_REQ, msg_p);
}


#ifdef INTERNAL_ANTENNAL_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  aud_send_fmr_set_antenna_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  freq            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_fmr_set_antenna_req(kal_bool is_short_antenna)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_set_antenna_req_struct *msg_p = (media_fmr_set_antenna_req_struct*)
        construct_local_para(sizeof(media_fmr_set_antenna_req_struct), TD_CTRL);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->is_short_antenna = is_short_antenna;
    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_FMR_SET_ANTENNA_REQ, msg_p);
}
#endif /* INTERNAL_ANTENNAL_SUPPORT */


#ifdef __FM_RADIO_HW_SCAN__
/*****************************************************************************
 * FUNCTION
 *  aud_send_fmr_hw_scan_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mute            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_fmr_hw_scan_req(kal_uint8 *scan_table)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_hw_scan_req_struct *msg_p = (media_fmr_hw_scan_req_struct*)
        construct_local_para(sizeof(media_fmr_hw_scan_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->scan_table = scan_table;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_FMR_HW_SCAN_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_fmr_hw_abort_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mute            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_fmr_hw_scan_abort_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_hw_scan_abort_req_struct *msg_p = (media_fmr_hw_scan_abort_req_struct*)
        construct_local_para(sizeof(media_fmr_hw_scan_abort_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_FMR_HW_SCAN_ABORT_REQ, msg_p);
}
#endif /* __FM_RADIO_HW_SCAN__ */


#ifdef __FM_RADIO_HW_SEARCH__
/*****************************************************************************
 * FUNCTION
 *  aud_send_fmr_seek_start_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mute            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_fmr_seek_start_req(module_type src_mod_id, kal_uint16 start_freq, kal_bool is_step_up, kal_bool is_preset, kal_int16 space_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_seek_start_req_struct *msg_p = (media_fmr_seek_start_req_struct*)
        construct_local_para(sizeof(media_fmr_seek_start_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->start_freq = start_freq;
    msg_p->is_step_up = is_step_up;
    msg_p->is_preset = is_preset;
    msg_p->space = space_value;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_FMR_SEEK_START_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_fmr_seek_abort_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mute            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_fmr_seek_abort_req(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_seek_abort_req_struct *msg_p = (media_fmr_seek_abort_req_struct*)
        construct_local_para(sizeof(media_fmr_seek_abort_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_FMR_SEEK_ABORT_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_fmr_seek_result_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_valid        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_fmr_seek_result_ind(kal_uint16 stop_freq, kal_uint8 signal_level, kal_bool is_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_seek_result_ind_struct *ind_p = (media_fmr_seek_result_ind_struct*)
        construct_local_para(sizeof(media_fmr_seek_result_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p->stop_freq = stop_freq;
    ind_p->signal_level = signal_level;
    ind_p->is_valid = is_valid;

    aud_send_msg_from_med(aud_context_p->src_mod, MSG_ID_MEDIA_FMR_SEEK_RESULT_IND, ind_p);
}

#else /* __FM_RADIO_HW_SEARCH__ */
    
/*****************************************************************************
 * FUNCTION
 *  aud_send_fmr_check_is_valid_stop_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mute            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_fmr_check_is_valid_stop_req(module_type src_mod_id, kal_uint16 freq, kal_uint8 is_step_up)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_check_is_valid_stop_req_struct *msg_p = (media_fmr_check_is_valid_stop_req_struct*)
        construct_local_para(sizeof(media_fmr_check_is_valid_stop_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->freq = freq;
    msg_p->is_step_up = is_step_up;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_FMR_CHECK_IS_VALID_STOP_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_fmr_check_is_valid_stop_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_valid        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_fmr_check_is_valid_stop_cnf(kal_uint8 is_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_check_is_valid_stop_cnf_struct *cnf_p = (media_fmr_check_is_valid_stop_cnf_struct*)
        construct_local_para(sizeof(media_fmr_check_is_valid_stop_cnf_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_p->is_valid = is_valid;
    aud_send_msg_from_med(aud_context_p->src_mod, MSG_ID_MEDIA_FMR_CHECK_IS_VALID_STOP_CNF, cnf_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_fmr_get_signal_level_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mute            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_fmr_get_signal_level_req(module_type src_mod_id, kal_uint16 freq, kal_uint8 is_step_up)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_get_signal_level_req_struct *msg_p = (media_fmr_get_signal_level_req_struct*)
        construct_local_para(sizeof(media_fmr_get_signal_level_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->freq = freq;
    msg_p->is_step_up = is_step_up;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_FMR_GET_SIGNAL_LEVEL_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_fmr_get_signal_level_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sig_lvl     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_fmr_get_signal_level_cnf(kal_uint8 sig_lvl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_get_signal_level_cnf_struct *cnf_p = (media_fmr_get_signal_level_cnf_struct*)
        construct_local_para(sizeof(media_fmr_get_signal_level_cnf_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_p->signal_level = sig_lvl;
    aud_send_msg_from_med(aud_context_p->src_mod, MSG_ID_MEDIA_FMR_GET_SIGNAL_LEVEL_CNF, cnf_p);
}
#endif /* __FM_RADIO_HW_SEARCH__ */


#ifdef __FM_RADIO_RDS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  aud_send_fmr_rds_enable_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_fmr_rds_enable_req(module_type src_mod_id, kal_bool af_enable, kal_bool tp_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_rds_enable_req_struct *msg_p = (media_fmr_rds_enable_req_struct*)
        construct_local_para(sizeof(media_fmr_rds_enable_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->af = af_enable;
    msg_p->ta = tp_enable;
    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_FMR_RDS_ENABLE_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_fmr_rds_disable_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_fmr_rds_disable_req(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_rds_disable_req_struct *msg_p = (media_fmr_rds_disable_req_struct*)
        construct_local_para(sizeof(media_fmr_rds_disable_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_FMR_RDS_DISABLE_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_fmr_rds_poll_rds_event_rds
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_fmr_rds_poll_rds_event_rds(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_FMR_POLL_RDS_EVENT_RDS, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_rds_send_event_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_rds_send_event_ind(kal_uint16 event, kal_uint16 flag, kal_uint16 *data, kal_uint16 data_len, kal_uint16 freq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_rds_event_ind_struct *msg_p = (media_fmr_rds_event_ind_struct*)
        construct_local_para(sizeof(media_fmr_rds_event_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(msg_p->data, data, sizeof(kal_uint16) * FM_RDS_MAX_DATA_BUFF_SIZE);
    msg_p->data_len = data_len;
    msg_p->flag = flag;
    msg_p->event = event;   
    msg_p->frequency = freq;
	
    aud_send_msg_from_med(MOD_MMI, MSG_ID_MEDIA_FMR_RDS_EVENT_IND, msg_p);
}
#endif /* __FM_RADIO_RDS_SUPPORT__ */


#ifdef __MED_MMA_MOD__

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 media_type;
}
aud_set_mma_common_req_struct;;

/*****************************************************************************
 * FUNCTION
 *  _aud_send_set_mma_common_struct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]  
 * RETURNS
 *  kal_bool
 *****************************************************************************/
static void _aud_send_set_mma_common_struct(void* msg_p, kal_uint8 media_type, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ((aud_set_mma_common_req_struct*)msg_p)->media_type = media_type;
    ((aud_set_mma_common_req_struct*)msg_p)->handle = handle;
}



/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_open_req
 * DESCRIPTION
 *  This function is to send mma open request.
 * PARAMETERS
 *  param           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_open_req(kal_int32 param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_open_req_struct *msg_p = NULL;
    mma_player_struct *param_p = (mma_player_struct*) param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if(kal_get_active_module_id()!=src_mod_id)
    //ASSERT(kal_get_active_module_id()!=src_mod_id);

    msg_p = (media_mma_open_req_struct*) construct_local_para(sizeof(media_mma_open_req_struct), TD_CTRL);

    msg_p->app_id = param_p->app_id;
    msg_p->handler = (kal_int32)param_p->handler;
    msg_p->media_type = param_p->media_type;
    msg_p->data = param_p->data;
    msg_p->size = param_p->size;
    msg_p->file_path = param_p->file_path;
    msg_p->repeats = param_p->repeats;
    msg_p->progressive_dl = param_p->progressive_dl;
    msg_p->output_path = param_p->output_path;
    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_OPEN_REQ, msg_p);
}

/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_open_async_req
 * DESCRIPTION
 *  This function is to send mma open request aysnc
 * PARAMETERS
 *  param           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_open_async_req(kal_int32 param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_open_async_req_struct *msg_p = NULL; 
    mma_player_async_struct *param_p = (mma_player_async_struct*) param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    msg_p = (media_mma_open_async_req_struct*) construct_local_para(sizeof(media_mma_open_async_req_struct), TD_CTRL);

    msg_p->app_id = param_p->app_id;
    msg_p->handler = (kal_int32)param_p->handler;
    msg_p->media_type = param_p->media_type;
    msg_p->data = param_p->data;
    msg_p->size = param_p->size;
    msg_p->file_path = param_p->file_path;
    msg_p->repeats = param_p->repeats;
    msg_p->progressive_dl = param_p->progressive_dl;
    msg_p->output_path = param_p->output_path;
    msg_p->user_data = param_p->user_data;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_AYNC_OPEN_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_set_cache_table_req
 * DESCRIPTION
 *  This function is to send mma set cache table request
 * PARAMETERS
 *  handle          [IN]        
 *  cache_tbl       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_set_cache_table_req(kal_int32 handle, kal_uint8 *cache_tbl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_cache_table_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg_p = (media_mma_set_cache_table_req_struct*) construct_local_para(sizeof(media_mma_set_cache_table_req_struct), TD_CTRL);

    msg_p->handle = handle;
    msg_p->cache_tbl = cache_tbl;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_SET_CACHE_TABLE_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_close_req
 * DESCRIPTION
 *  This function is to send mma close request.
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_close_req(kal_uint8 media_type, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_close_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg_p = (media_mma_close_req_struct*) construct_local_para(sizeof(media_mma_close_req_struct), TD_CTRL);

    _aud_send_set_mma_common_struct(msg_p,media_type,handle);

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_CLOSE_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_set_param_req
 * DESCRIPTION
 *  This function is to send mma parameter request
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_set_param_req(kal_uint8 param_type, void* param_value, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_param_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg_p = (media_mma_set_param_req_struct*) construct_local_para(sizeof(media_mma_set_param_req_struct), TD_CTRL);

    msg_p->param_type = param_type;
    msg_p->param_value = param_value;
    msg_p->handle = handle;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_SET_PARAM_REQ, msg_p);
}

/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_build_BLISRC_table
 * DESCRIPTION
 *  This function is to send mma build BLISRC table request
 * PARAMETERS
 *  turn_on         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_build_BLISRC_table(kal_bool turn_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_build_BLISRC_table_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg_p = (media_mma_build_BLISRC_table_req_struct*) construct_local_para(sizeof(media_mma_build_BLISRC_table_req_struct), TD_CTRL);

    msg_p->turn_on = turn_on;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_BUILD_BLISRC_TABLE, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_play_req
 * DESCRIPTION
 *  This function is to send mma play request.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  media_type      [IN]        
 *  handle          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_play_req(kal_uint8 media_type, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_play_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg_p = (media_mma_play_req_struct*) construct_local_para(sizeof(media_mma_play_req_struct), TD_CTRL);

    _aud_send_set_mma_common_struct(msg_p,media_type,handle);

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_PLAY_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_stop_req
 * DESCRIPTION
 *  This function is to send mma stop request.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  media_type      [IN]        
 *  handle          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_stop_req(kal_uint8 media_type, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_stop_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg_p = (media_mma_stop_req_struct*) construct_local_para(sizeof(media_mma_stop_req_struct), TD_CTRL);

    _aud_send_set_mma_common_struct(msg_p,media_type,handle);

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_STOP_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_pause_req
 * DESCRIPTION
 *  This function is to send mma pause request.
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_pause_req(kal_uint8 media_type, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_pause_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg_p = (media_mma_pause_req_struct*) construct_local_para(sizeof(media_mma_pause_req_struct), TD_CTRL);

    _aud_send_set_mma_common_struct(msg_p,media_type,handle);

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_PAUSE_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_resume_req
 * DESCRIPTION
 *  This function is to send mma resume request.
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_resume_req(kal_uint8 media_type, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_resume_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg_p = (media_mma_resume_req_struct*) construct_local_para(sizeof(media_mma_resume_req_struct), TD_CTRL);

    _aud_send_set_mma_common_struct(msg_p,media_type,handle);

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_RESUME_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_get_audio_info_req
 * DESCRIPTION
 *  This function is to send mma get audio info request.
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_get_audio_info_req(//module_type src_mod_id, 
                                     kal_uint16 app_id,
                                     kal_wchar* file_path,
                                     kal_uint8 media_type,
                                     kal_uint8* data,
                                     kal_uint32 data_len,
                                     void *audio_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_audio_info_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_get_audio_info_req_struct*)
        construct_local_para(sizeof(media_mma_get_audio_info_req_struct), TD_CTRL);

    MED_ASSERT((file_path != NULL && data == NULL) || (file_path == NULL && data != NULL));

    msg_p->app_id = app_id;
    msg_p->file_path = file_path;
    msg_p->media_type = media_type;
    msg_p->data = data;
    msg_p->data_len = data_len;
    msg_p->audio_info = audio_info;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_GET_AUDIO_INFO_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_get_duration_req
 * DESCRIPTION
 *  This function is to send mma get duration request.
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 *  use_default_handle [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_get_duration_req(kal_uint8 media_type, kal_int32 handle, kal_bool use_default_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_duration_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_get_duration_req_struct*)
        construct_local_para(sizeof(media_mma_get_duration_req_struct), TD_CTRL);

    msg_p->media_type = media_type;
    msg_p->handle = handle;
    msg_p->use_default_handle = use_default_handle;
    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_GET_DURATION_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_get_current_time_req
 * DESCRIPTION
 *  This function is to send mma get current time request.
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_get_current_time_req(kal_uint8 media_type, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_current_time_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_get_current_time_req_struct*)
        construct_local_para(sizeof(media_mma_get_current_time_req_struct), TD_CTRL);

    _aud_send_set_mma_common_struct(msg_p,media_type,handle);

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_GET_CURRENT_TIME_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_set_start_time_req
 * DESCRIPTION
 *  This function is to send mma set start time request.
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 *  start_time      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_set_start_time_req(
        kal_uint8 media_type,
        kal_int32 handle,
        kal_int32 start_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_start_time_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_set_start_time_req_struct*)
        construct_local_para(sizeof(media_mma_set_start_time_req_struct), TD_CTRL);

    msg_p->media_type = media_type;
    msg_p->handle = handle;
    msg_p->start_time = start_time;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_SET_START_TIME_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_set_stop_time_req
 * DESCRIPTION
 *  This function is to send mma set stop time request.
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 *  stop_time       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_set_stop_time_req(kal_uint8 media_type, kal_int32 handle, kal_int32 stop_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_stop_time_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_set_stop_time_req_struct*)
        construct_local_para(sizeof(media_mma_set_stop_time_req_struct), TD_CTRL);

    msg_p->media_type = media_type;
    msg_p->handle = handle;
    msg_p->stop_time = stop_time;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_SET_STOP_TIME_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_get_volume_req
 * DESCRIPTION
 *  This function is to send mma get volume request.
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 *  volume          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_get_volume_req(kal_uint8 media_type, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_volume_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_get_volume_req_struct*) construct_local_para(sizeof(media_mma_get_volume_req_struct), TD_CTRL);

    _aud_send_set_mma_common_struct(msg_p,media_type,handle);

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_GET_VOLUME_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_set_volume_req
 * DESCRIPTION
 *  This function is to send mma set volume request.
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 *  volume          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_set_volume_req(kal_uint8 media_type, kal_int32 handle, kal_uint8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_volume_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_set_volume_req_struct*) construct_local_para(sizeof(media_mma_set_volume_req_struct), TD_CTRL);

    msg_p->media_type = media_type;
    msg_p->handle = handle;
    msg_p->volume = volume;
    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_SET_VOLUME_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_pdl_write_data_ind_req
 * DESCRIPTION
 *  This function is to send mma write data request.
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_pdl_write_data_ind_req(kal_uint8 media_type, kal_int32 handle, kal_bool is_finish)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_pdl_write_data_ind_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg_p = (media_mma_pdl_write_data_ind_req_struct*) construct_local_para(sizeof(media_mma_pdl_write_data_ind_req_struct), TD_CTRL);

    msg_p->media_type = media_type;
    msg_p->handle = handle;
    msg_p->is_finish = is_finish;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_PDL_WRITE_DATA_IND_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_get_pdl_percent_req
 * DESCRIPTION
 *  This function is to send mma write data request.
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_pdl_get_buf_percent_req(kal_int32 handle, kal_uint32 cache_sec, kal_uint32* percent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_pdl_get_buf_percent_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg_p = (media_mma_pdl_get_buf_percent_req_struct*) construct_local_para(sizeof(media_mma_pdl_get_buf_percent_req_struct), TD_CTRL);

    msg_p->handle = handle;
    msg_p->cache_sec = cache_sec;
    msg_p->percent = percent;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_PDL_GET_BUF_PERCENT_REQ, msg_p);
}


#ifdef __MED_MMA_EXTRA_CTRL__
/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_set_rate_req
 * DESCRIPTION
 *  This function is to send mma set rate request.
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 *  rate            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_set_rate_req(kal_uint8 media_type, kal_int32 handle, kal_int32 rate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_rate_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_set_rate_req_struct*) construct_local_para(sizeof(media_mma_set_rate_req_struct), TD_CTRL);

    msg_p->media_type = media_type;
    msg_p->handle = handle;
    msg_p->rate = rate;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_SET_RATE_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_set_tempo_req
 * DESCRIPTION
 *  This function is to send mma set tempo request.
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 *  tempo           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_set_tempo_req(kal_uint8 media_type, kal_int32 handle, kal_int32 tempo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_tempo_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_set_tempo_req_struct*) construct_local_para(sizeof(media_mma_set_tempo_req_struct), TD_CTRL);

    msg_p->media_type = media_type;
    msg_p->handle = handle;
    msg_p->tempo = tempo;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_SET_TEMPO_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_set_pitch_req
 * DESCRIPTION
 *  This function is to send mma set pitch request.
 * PARAMETERS   
 *  media_type      [IN]        
 *  handle          [IN]        
 *  pitch           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_set_pitch_req(kal_uint8 media_type, kal_int32 handle, kal_int32 pitch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_pitch_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_set_pitch_req_struct*) construct_local_para(sizeof(media_mma_set_pitch_req_struct), TD_CTRL);

    msg_p->media_type = media_type;
    msg_p->handle = handle;
    msg_p->pitch = pitch;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_SET_PITCH_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_send_long_msg_req
 * DESCRIPTION
 *  This function is to send mma send long msg request.
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 *  buf             [?]         kal_uint16 len
 *  len             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_send_long_msg_req(
        kal_uint8 media_type,
        kal_int32 handle,
        kal_uint8 *buf,
        kal_uint16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_send_long_msg_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_send_long_msg_req_struct*)
        construct_local_para(sizeof(media_mma_send_long_msg_req_struct), TD_CTRL);

    msg_p->media_type = media_type;
    msg_p->handle = handle;
    msg_p->buf = buf;
    msg_p->len = len;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_SEND_LONG_MSG_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_send_short_msg_req
 * DESCRIPTION
 *  This function is to send mma send short msg request.
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 *  type            [IN]        kal_uint8 data1, kal_uint8 data2
 *  data1           [IN]        
 *  data2           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_send_short_msg_req(
        kal_uint8 media_type,
        kal_int32 handle,
        kal_uint8 type,
        kal_uint8 data1,
        kal_uint8 data2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_send_short_msg_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_send_short_msg_req_struct*)
        construct_local_para(sizeof(media_mma_send_short_msg_req_struct), TD_CTRL);

    msg_p->media_type = media_type;
    msg_p->handle = handle;
    msg_p->type = type;
    msg_p->data1 = data1;
    msg_p->data2 = data2;
    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_SEND_SHORT_MSG_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_open_device_req
 * DESCRIPTION
 *  This function is to send mma open device request.
 * PARAMETERS
 *  media_type      [IN]      
 *  fast_pass       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_open_device_req(kal_uint8 media_type, kal_bool fast_pass)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_open_device_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if(kal_get_active_module_id()!=src_mod_id)
    //ASSERT(kal_get_active_module_id()!=src_mod_id);

    msg_p = (media_mma_open_device_req_struct*)
        construct_local_para(sizeof(media_mma_open_device_req_struct), TD_CTRL);

    msg_p->handler = NULL;
    msg_p->data = NULL;
    msg_p->size = 0;
    msg_p->repeats = 0;

    msg_p->media_type = media_type;
    msg_p->fast_pass = fast_pass;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_OPEN_DEVICE_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_close_device_req
 * DESCRIPTION
 *  This function is to send mma close device request.
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_close_device_req(kal_uint8 media_type, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_close_device_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_close_device_req_struct*)
        construct_local_para(sizeof(media_mma_close_device_req_struct), TD_CTRL);

    _aud_send_set_mma_common_struct(msg_p,media_type,handle);

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_CLOSE_DEVICE_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_set_channel_volume_req
 * DESCRIPTION
 *  This function is to send mma set channel volume request.
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 *  channel         [IN]        kal_uint8 level
 *  level           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_set_channel_volume_req(
        kal_uint8 media_type,
        kal_int32 handle,
        kal_uint8 channel,
        kal_uint8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_channel_volume_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_set_channel_volume_req_struct*)
        construct_local_para(sizeof(media_mma_set_channel_volume_req_struct), TD_CTRL);

    msg_p->media_type = media_type;
    msg_p->handle = handle;
    msg_p->channel = channel;
    msg_p->level = level;
    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_SET_CHANNEL_VOLUME_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_set_program_req
 * DESCRIPTION
 *  This function is to send mma set program request.
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 *  channel         [IN]        kal_uint8 bank, kal_uint8 program
 *  bank            [IN]        
 *  program         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_set_program_req(
        kal_uint8 media_type,
        kal_int32 handle,
        kal_uint8 channel,
        kal_uint8 bank,
        kal_uint8 program)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_program_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_set_program_req_struct*)
        construct_local_para(sizeof(media_mma_set_program_req_struct), TD_CTRL);

    msg_p->media_type = media_type;
    msg_p->handle = handle;
    msg_p->channel = channel;
    msg_p->bank = bank;
    msg_p->program = program;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_SET_PROGRAM_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_set_data_req
 * DESCRIPTION
 *  This function is to send mma set data request.
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 *  param           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_set_data_req(kal_uint8 media_type, kal_int32 handle, kal_int32 param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_data_req_struct *msg_p = NULL;
    mma_player_struct *param_p = (mma_player_struct*) param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if(kal_get_active_module_id()!=src_mod_id)
    //ASSERT(kal_get_active_module_id()!=src_mod_id);

    msg_p = (media_mma_set_data_req_struct*) construct_local_para(sizeof(media_mma_set_data_req_struct), TD_CTRL);

    msg_p->media_type = media_type;
    msg_p->handle = handle;
    msg_p->data = param_p->data;
    msg_p->size = param_p->size;
    msg_p->repeats = param_p->repeats;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_SET_DATA_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_get_pitch_req
 * DESCRIPTION
 *  This function is to get pitch.
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 *  pitch_p         [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_get_pitch_req(kal_int32 handle, kal_uint8 media_type, kal_int32* pitch_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_pitch_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_get_pitch_req_struct*) construct_local_para(sizeof(media_mma_get_pitch_req_struct), TD_CTRL);

    msg_p->handle = handle;
    msg_p->media_type = media_type;
    msg_p->pitch_p = pitch_p;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_GET_PITCH_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_get_rate_range_req
 * DESCRIPTION
 *  This function is to get rate range
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 *  rate_p          [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_get_rate_range_req(kal_uint8 media_type, kal_int32* max_rate_p, kal_int32* min_rate_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_rate_range_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_get_rate_range_req_struct*) construct_local_para(sizeof(media_mma_get_rate_range_req_struct), TD_CTRL);
    
    msg_p->media_type = media_type;
    msg_p->max_rate_p = max_rate_p;
    msg_p->min_rate_p = min_rate_p;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_GET_RATE_RANGE_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_get_rate_req
 * DESCRIPTION
 *  This function is to get rate.
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 *  rate_p          [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_get_rate_req(kal_int32 handle, kal_uint8 media_type, kal_int32* rate_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_rate_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_get_rate_req_struct*) construct_local_para(sizeof(media_mma_get_rate_req_struct), TD_CTRL);

    msg_p->handle = handle;
    msg_p->media_type = media_type;
    msg_p->rate_p = rate_p;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_GET_RATE_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_get_tempo_req
 * DESCRIPTION
 *  This function is to get tempo.
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 *  tempo_p         [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_get_tempo_req(kal_int32 handle, kal_uint8 media_type, kal_int32* tempo_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_tempo_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_get_tempo_req_struct*) construct_local_para(sizeof(media_mma_get_tempo_req_struct), TD_CTRL);

    msg_p->handle = handle;
    msg_p->media_type = media_type;
    msg_p->tempo_p = tempo_p;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_GET_TEMPO_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_get_channel_volume_req
 * DESCRIPTION
 *  This function is to get channel volume.
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 *  param           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_get_channel_volume_req(kal_int32 handle, kal_uint8 media_type, kal_uint8 channel, kal_uint8* volume_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_channel_volume_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_get_channel_volume_req_struct*) construct_local_para(sizeof(media_mma_get_channel_volume_req_struct), TD_CTRL);

    msg_p->handle = handle;
    msg_p->media_type = media_type;
    msg_p->channel = channel;
    msg_p->volume_p = volume_p;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_GET_CHANNEL_VOLUME_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_get_program_req
 * DESCRIPTION
 *  This function is to get program.
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 *  channel         [IN]
 *  bank_p          [OUT]
 *  program_p       [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_get_program_req(kal_int32 handle, kal_uint8 media_type, kal_uint8 channel, kal_int16* bank_p, kal_int8* program_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_program_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_get_program_req_struct*) construct_local_para(sizeof(media_mma_get_program_req_struct), TD_CTRL);

    msg_p->handle = handle;
    msg_p->media_type = media_type;
    msg_p->channel = channel;
    msg_p->bank_p = bank_p;
    msg_p->program_p = program_p;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_GET_PROGRAM_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_get_is_bank_support_req
 * DESCRIPTION
 *  This function is to check if the bank is supported.
 * PARAMETERS
 *  media_type          [IN]        
 *  handle              [IN]        
 *  is_bank_support_p   [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_get_is_bank_support_req(kal_int32 handle, kal_uint8 media_type, kal_bool* is_bank_support_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_is_bank_support_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_get_is_bank_support_req_struct*) construct_local_para(sizeof(media_mma_get_is_bank_support_req_struct), TD_CTRL);

    msg_p->handle = handle;
    msg_p->media_type = media_type;
    msg_p->is_bank_support_p = is_bank_support_p;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_GET_IS_BANK_SUPPORT_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_get_bank_list_req
 * DESCRIPTION
 *  This function is to get bank list.
 * PARAMETERS
 *  media_type          [IN]        
 *  handle              [IN]        
 *  custom              [IN]  
 *  buf_p               [OUT]
 *  len_p               [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_get_bank_list_req(kal_int32 handle, kal_uint8 media_type, kal_bool custom, const kal_int16** buf_p, kal_int16* len_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_bank_list_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_get_bank_list_req_struct*) construct_local_para(sizeof(media_mma_get_bank_list_req_struct), TD_CTRL);

    msg_p->handle = handle;
    msg_p->media_type = media_type;
    msg_p->custom = custom;
    msg_p->buf_p = buf_p;
    msg_p->len_p = len_p;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_GET_BANK_LIST_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_get_program_list_req
 * DESCRIPTION
 *  This function is to get program list.
 * PARAMETERS
 *  media_type          [IN]        
 *  handle              [IN]        
 *  bank                [IN]
 *  buf_p               [OUT]
 *  len_p               [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_get_program_list_req(kal_int32 handle, kal_uint8 media_type, kal_int16 bank, const kal_int8** buf_p, kal_int16* len_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_program_list_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_get_program_list_req_struct*) construct_local_para(sizeof(media_mma_get_program_list_req_struct), TD_CTRL);

    msg_p->handle = handle;
    msg_p->media_type = media_type;
    msg_p->bank = bank;
    msg_p->buf_p = buf_p;
    msg_p->len_p = len_p;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_GET_PROGRAM_LIST_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_get_program_name_req
 * DESCRIPTION
 *  This function is to get program name.
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  media_type          [IN]        
 *  handle              [IN]        
 *  is_bank_support_p   [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_get_program_name_req(kal_int32 handle, kal_uint8 media_type, kal_int16 bank, kal_int8 program, const kal_uint8** name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_program_name_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_get_program_name_req_struct*) construct_local_para(sizeof(media_mma_get_program_name_req_struct), TD_CTRL);

    msg_p->handle = handle;
    msg_p->media_type = media_type;
    msg_p->bank = bank;
    msg_p->program = program;
    msg_p->name_p = name_p;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_GET_PROGRAM_NAME_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_get_key_name_req
 * DESCRIPTION
 *  This function is to get program name.
 * PARAMETERS 
 *  media_type          [IN]        
 *  handle              [IN]        
 *  is_bank_support_p   [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_get_key_name_req(kal_int32 handle, kal_uint8 media_type, kal_int16 bank, kal_int8 program, kal_int8 key, const kal_uint8** name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_key_name_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_get_key_name_req_struct*) construct_local_para(sizeof(media_mma_get_key_name_req_struct), TD_CTRL);

    msg_p->handle = handle;
    msg_p->media_type = media_type;
    msg_p->bank = bank;
    msg_p->program = program;
    msg_p->key = key;
    msg_p->name_p = name_p;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_GET_KEY_NAME_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_get_is_sp_midi_req
 * DESCRIPTION
 *  This function is to check if it's SP MIDI.
 * PARAMETERS
 *  media_type          [IN]        
 *  handle              [IN]        
 *  is_bank_support_p   [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_mma_get_is_sp_midi_req(kal_int32 handle, kal_uint8 media_type, kal_bool* is_sp_midi_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_is_sp_midi_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_mma_get_is_sp_midi_req_struct*) construct_local_para(sizeof(media_mma_get_is_sp_midi_req_struct), TD_CTRL);

    msg_p->handle = handle;
    msg_p->media_type = media_type;
    msg_p->is_sp_midi_p = is_sp_midi_p;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_MMA_GET_IS_SP_MIDI_REQ, msg_p);
}
#endif /* __MED_MMA_EXTRA_CTRL__ */
#endif /* __MED_MMA_MOD__ */ 

#ifdef __MED_VR_MOD__


/*****************************************************************************
 * FUNCTION
 *  aud_send_vr_get_version_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vr_get_version_req(module_type src_mod_id, kal_uint8 mode, kal_uint8 lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vr_get_version_req_struct *msg_p = (media_vr_get_version_req_struct*)
        construct_local_para(sizeof(media_vr_get_version_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->mode = mode;
    msg_p->language = lang;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VR_GET_VERSION_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vr_get_param_req
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
 *  void
 *****************************************************************************/
void aud_send_vr_get_param_req(
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
    media_vr_get_param_req_struct *msg_p = (media_vr_get_param_req_struct*)
        construct_local_para(sizeof(media_vr_get_param_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->mode = mode;
    msg_p->language = lang;
    msg_p->sim = sim;
    msg_p->diff = diff;
    msg_p->rej = rej;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VR_GET_PARAM_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vr_set_param_req
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
 *  void
 *****************************************************************************/
void aud_send_vr_set_param_req(
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
    media_vr_set_param_req_struct *msg_p = (media_vr_set_param_req_struct*)
        construct_local_para(sizeof(media_vr_set_param_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->mode = mode;
    msg_p->language = lang;
    msg_p->sim = sim;
    msg_p->diff = diff;
    msg_p->rej = rej;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VR_SET_PARAM_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vr_init_rcg_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 *  group_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vr_init_rcg_req(
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
    media_vr_init_rcg_req_struct *msg_p = (media_vr_init_rcg_req_struct*)
        construct_local_para(sizeof(media_vr_init_rcg_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->session_id = session_id;
    msg_p->mode = mode;
    msg_p->language = lang;
    msg_p->group_id = group_id;
    msg_p->app_id = app_id;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VR_INIT_RCG_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vr_init_trn_req
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
 *  void
 *****************************************************************************/
void aud_send_vr_init_trn_req(
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
    media_vr_init_trn_req_struct *msg_p = (media_vr_init_trn_req_struct*)
        construct_local_para(sizeof(media_vr_init_trn_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->session_id = session_id;
    msg_p->mode = mode;
    msg_p->language = lang;
    msg_p->group_id = group_id;
    msg_p->word_id = word_id;
    msg_p->app_id = app_id;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VR_INIT_TRN_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vr_voice_in_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 *  seq_no          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vr_voice_in_req(module_type src_mod_id, kal_uint32 session_id, kal_uint8 seq_no)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vr_voice_in_req_struct *msg_p = (media_vr_voice_in_req_struct*)
        construct_local_para(sizeof(media_vr_voice_in_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->session_id = session_id;
    msg_p->seq_no = seq_no;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VR_VOICE_IN_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vr_rcg_result_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_mod_id      [IN]        
 *  session_id      [IN]        
 *  result          [IN]        
 *  id_length       [IN]        
 *  id_array        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vr_rcg_result_ind(
        module_type dst_mod_id,
        kal_uint32 session_id,
        kal_int32 result,
        kal_uint16 id_length,
        kal_uint16 *id_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vr_rcg_result_ind_struct *msg_p = (media_vr_rcg_result_ind_struct*)
        construct_local_para(sizeof(media_vr_rcg_result_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->session_id = session_id;
    msg_p->result = result;
    msg_p->id_length = id_length;
    kal_mem_cpy(msg_p->id_array, id_array, VR_MAX_RCG_RESULT_NUM * 2);

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_MEDIA_VR_RCG_RESULT_IND, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vr_trn_result_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_mod_id      [IN]        
 *  session_id      [IN]        
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vr_trn_result_ind(module_type dst_mod_id, kal_uint32 session_id, kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vr_rcg_result_ind_struct *msg_p = (media_vr_rcg_result_ind_struct*)
        construct_local_para(sizeof(media_vr_rcg_result_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->session_id = session_id;
    msg_p->result = result;

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_MEDIA_VR_TRN_RESULT_IND, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vr_del_tag_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 *  group_id        [IN]        
 *  word_id         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vr_del_tag_req(
        module_type src_mod_id,
        kal_uint8 mode,
        kal_uint8 lang,
        kal_uint8 group_id,
        kal_uint16 word_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vr_del_tag_req_struct *msg_p = (media_vr_del_tag_req_struct*)
        construct_local_para(sizeof(media_vr_del_tag_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->mode = mode;
    msg_p->language = lang;
    msg_p->group_id = group_id;
    msg_p->word_id = word_id;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VR_DEL_TAG_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vr_check_tag_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 *  group_id        [IN]        
 *  word_id         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vr_check_tag_req(
        module_type src_mod_id,
        kal_uint8 mode,
        kal_uint8 lang,
        kal_uint8 group_id,
        kal_uint16 word_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vr_check_tag_req_struct *msg_p = (media_vr_check_tag_req_struct*)
        construct_local_para(sizeof(media_vr_check_tag_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->mode = mode;
    msg_p->language = lang;
    msg_p->group_id = group_id;
    msg_p->word_id = word_id;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VR_CHECK_TAG_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vr_sync_db_req
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
 *  void
 *****************************************************************************/
void aud_send_vr_sync_db_req(
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
    media_vr_sync_db_req_struct *msg_p = (media_vr_sync_db_req_struct*)
        construct_local_para(sizeof(media_vr_sync_db_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->mode = mode;
    msg_p->language = lang;
    msg_p->group_id = group_id;
    msg_p->id_length_p = id_length_p;
    msg_p->id_array = id_array;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VR_SYNC_DB_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vr_play_tag_req
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
 *  void
 *****************************************************************************/
void aud_send_vr_play_tag_req(
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
    media_vr_play_tag_req_struct *msg_p = (media_vr_play_tag_req_struct*)
        construct_local_para(sizeof(media_vr_play_tag_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->mode = mode;
    msg_p->language = lang;
    msg_p->group_id = group_id;
    msg_p->word_id = word_id;
    msg_p->identifier = identifier;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VR_PLAY_TAG_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vr_get_dir_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 *  group_id        [IN]        
 *  folder_name     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vr_get_dir_req(
        module_type src_mod_id,
        kal_uint8 mode,
        kal_uint8 lang,
        kal_uint8 group_id,
        kal_uint16 *folder_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vr_get_dir_req_struct *msg_p = (media_vr_get_dir_req_struct*)
        construct_local_para(sizeof(media_vr_get_dir_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->mode = mode;
    msg_p->language = lang;
    msg_p->group_id = group_id;
    msg_p->folder_name = folder_name;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VR_GET_DIR_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vr_add_tag_req
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
 *  void
 *****************************************************************************/
void aud_send_vr_add_tag_req(
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
    media_vr_add_tag_req_struct *msg_p = (media_vr_add_tag_req_struct*)
        construct_local_para(sizeof(media_vr_add_tag_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->mode = mode;
    msg_p->language = lang;
    msg_p->group_id = group_id;
    msg_p->id_length = id_length;
    kal_mem_cpy(msg_p->id_array, id_array, VR_MAX_ADD_ONCE_NUM * 2);

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VR_ADD_TAG_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vr_abort_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vr_abort_req(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vr_abort_req_struct *msg_p = (media_vr_abort_req_struct*)
        construct_local_para(sizeof(media_vr_abort_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VR_ABORT_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vr_abort_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_mod_id      [IN]        
 *  session_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vr_abort_ind(module_type dst_mod_id, kal_uint32 session_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vr_abort_ind_struct *msg_p = (media_vr_abort_ind_struct*)
        construct_local_para(sizeof(media_vr_abort_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->session_id = session_id;

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_MEDIA_VR_ABORT_IND, msg_p);
}
#endif /* __MED_VR_MOD__ */ 

#ifdef __MMI_SUPPORT_BACKLIGHT_SYNC__
/*****************************************************************************
 * FUNCTION
 *  aud_send_backlight_ctrl_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_mod_id          [IN]        
 *  on_off              [IN]        
 *  disable_timer       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_backlight_ctrl_req(module_type dst_mod_id, kal_uint8 on_off, kal_uint8 disable_timer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_backlight_control_req_struct *msg_p = (mmiapi_backlight_control_req_struct*)
        construct_local_para(sizeof(mmiapi_backlight_control_req_struct), TD_CTRL);
    module_type src_mod_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->on_off = on_off;
    msg_p->disable_timer = disable_timer;
    src_mod_id = kal_get_active_module_id();

    aud_send_ilm(dst_mod_id, (kal_uint16) MSG_ID_MMIAPI_BACKLIGHT_CONTROL_REQ, msg_p, NULL);
    
}
#endif /* __MMI_SUPPORT_BACKLIGHT_SYNC__ */ 

#ifdef __MMI_SUPPORT_LED_SYNC__
/*****************************************************************************
 * FUNCTION
 *  aud_send_led_ctrl_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_mod_id      [IN]        
 *  on_off          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_led_ctrl_req(module_type dst_mod_id, kal_uint8 on_off)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_led_control_req_struct *msg_p = (mmiapi_led_control_req_struct*)
        construct_local_para(sizeof(mmiapi_led_control_req_struct), TD_CTRL);
    module_type src_mod_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->on_off = on_off;
    src_mod_id = kal_get_active_module_id();

    aud_send_ilm(dst_mod_id, (kal_uint16) MSG_ID_MMIAPI_LED_CONTROL_REQ, msg_p, NULL);
}
#endif /* __MMI_SUPPORT_LED_SYNC__ */ 


#ifdef __MMI_SUPPORT_VIBRATOR_SYNC__
/*****************************************************************************
 * FUNCTION
 *  aud_send_vibrator_ctrl_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_mod_id      [IN]        
 *  on_off          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vibrator_ctrl_req(module_type dst_mod_id, kal_uint8 on_off)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_device_get_ctrl_req_struct *msg_p_ctrl = (mmiapi_device_get_ctrl_req_struct*)
        construct_local_para(sizeof(mmiapi_device_get_ctrl_req_struct), TD_CTRL);

    mmiapi_device_play_req_struct *msg_p_play = (mmiapi_device_play_req_struct*)
        construct_local_para(sizeof(mmiapi_device_play_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p_ctrl->src_mod_id = msg_p_play->src_mod_id = MOD_MED;
    
    msg_p_play->type = MMIAPI_DEV_TYPE_VIBRATOR;

    if (on_off)
    {
        /* Turn on vibrator, Lock MMI control then turn on */
        msg_p_ctrl->action = MMIAPI_DEV_CTRL_GET;
        msg_p_play->level = MMIAPI_DEV_LEVEL_1;

        aud_send_ilm(dst_mod_id, (kal_uint16) MSG_ID_MMIAPI_DEVICE_GET_CTRL_REQ, msg_p_ctrl, NULL);
        aud_send_ilm(dst_mod_id, (kal_uint16) MSG_ID_MMIAPI_DEVICE_PLAY_REQ, msg_p_play, NULL);
    }
    else
    {
       /* Turn off vibrator, turn off then release Lock MMI */
        msg_p_ctrl->action = MMIAPI_DEV_CTRL_RELEASE;
        msg_p_play->level = MMIAPI_DEV_LEVEL_0;

        aud_send_ilm(dst_mod_id, (kal_uint16) MSG_ID_MMIAPI_DEVICE_PLAY_REQ, msg_p_play, NULL);
        aud_send_ilm(dst_mod_id, (kal_uint16) MSG_ID_MMIAPI_DEVICE_GET_CTRL_REQ, msg_p_ctrl, NULL);
    }

}
#endif /* __MMI_SUPPORT_VIBRATOR_SYNC__ */


#ifdef __MED_VRSI_MOD__
/*****************************************************************************
 * FUNCTION
 *  aud_send_vrsi_init_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vrsi_init_req(module_type src_mod_id, kal_uint16 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_init_req_struct *msg_p = (media_vrsi_init_req_struct*)
        construct_local_para(sizeof(media_vrsi_init_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->app_id = app_id;
    
    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VRSI_INIT_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vrsi_add_tags_req
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
 *  void
 *****************************************************************************/
void aud_send_vrsi_add_tags_req(
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
    media_vrsi_add_tags_req_struct *msg_p = (media_vrsi_add_tags_req_struct*)
        construct_local_para(sizeof(media_vrsi_add_tags_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->session_id = session_id;
    msg_p->grammar = grammar;
    msg_p->tag_num = tag_num;
    msg_p->name_list = name_list;
    msg_p->long_list = long_list;
    msg_p->is_name_list = is_name_list;
    msg_p->id_list = id_list;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VRSI_ADD_TAGS_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vrsi_start_cmd_trn_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 *  grammar         [?]         
 *  tag_name        [?]         
 *  tag_long        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vrsi_start_cmd_trn_req(
        module_type src_mod_id,
        kal_uint32 session_id,
        kal_uint8 *grammar,
        kal_uint16 *tag_name,
        kal_int32 tag_long)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_start_trn_req_struct *msg_p = (media_vrsi_start_trn_req_struct*)
        construct_local_para(sizeof(media_vrsi_start_trn_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->session_id = session_id;
    msg_p->grammar = grammar;
    msg_p->tag_name = tag_name;
    msg_p->tag_long = tag_long;
    msg_p->lang = NULL;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VRSI_START_TRN_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vrsi_start_cmd_rcg_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 *  grammar         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vrsi_start_cmd_rcg_req(module_type src_mod_id, kal_uint32 session_id, kal_uint8 *grammar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_start_rcg_req_struct *msg_p = (media_vrsi_start_rcg_req_struct*)
        construct_local_para(sizeof(media_vrsi_start_rcg_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->session_id = session_id;
    msg_p->grammar = grammar;
    msg_p->lang = NULL;
    msg_p->limit = NULL;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VRSI_START_RCG_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vrsi_start_digit_rcg_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 *  lang            [IN]        
 *  limit           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vrsi_start_digit_rcg_req(module_type src_mod_id, kal_uint32 session_id, kal_uint8 lang, kal_uint16 limit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_start_rcg_req_struct *msg_p = (media_vrsi_start_rcg_req_struct*)
        construct_local_para(sizeof(media_vrsi_start_rcg_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->session_id = session_id;
    msg_p->grammar = NULL;
    msg_p->lang = lang;
    msg_p->limit = limit;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VRSI_START_RCG_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vrsi_start_digit_adapt_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 *  lang            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vrsi_start_digit_adapt_req(module_type src_mod_id, kal_uint32 session_id, kal_uint8 lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_start_trn_req_struct *msg_p = (media_vrsi_start_trn_req_struct*)
        construct_local_para(sizeof(media_vrsi_start_trn_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->session_id = session_id;
    msg_p->grammar = NULL;
    msg_p->tag_name = NULL;
    msg_p->tag_long = NULL;
    msg_p->lang = lang;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VRSI_START_TRN_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vrsi_play_tag_req
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
 *  void
 *****************************************************************************/
void aud_send_vrsi_play_tag_req(
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
    media_vrsi_play_tag_req_struct *msg_p = (media_vrsi_play_tag_req_struct*)
        construct_local_para(sizeof(media_vrsi_play_tag_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->session_id = session_id;
    msg_p->grammar = grammar;
    msg_p->tag_id = tag_id;
    msg_p->volume = volume;
    msg_p->output_path = output_path;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VRSI_PLAY_TAG_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vrsi_play_TTS_req
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
 *  void
 *****************************************************************************/
void aud_send_vrsi_play_TTS_req(
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
    media_vrsi_play_tts_req_struct *msg_p = (media_vrsi_play_tts_req_struct*)
        construct_local_para(sizeof(media_vrsi_play_tts_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->session_id = session_id;
    msg_p->text = text;
    msg_p->volume = volume;
    msg_p->output_path = output_path;
    msg_p->lang = lang;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VRSI_PLAY_TTS_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vrsi_get_tag_num_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  grammar         [?]         
 *  tag_num         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vrsi_get_tag_num_req(module_type src_mod_id, kal_uint8 *grammar, kal_int32 *tag_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_get_tagnum_req_struct *msg_p = (media_vrsi_get_tagnum_req_struct*)
        construct_local_para(sizeof(media_vrsi_get_tagnum_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->grammar = grammar;
    msg_p->tag_num = tag_num;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VRSI_GET_TAGNUM_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vrsi_get_tag_info_req
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
 *  void
 *****************************************************************************/
void aud_send_vrsi_get_tag_info_req(
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
    media_vrsi_get_taginfo_req_struct *msg_p = (media_vrsi_get_taginfo_req_struct*)
        construct_local_para(sizeof(media_vrsi_get_taginfo_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->grammar = grammar;
    msg_p->tag_num = tag_num;
    msg_p->id_list = id_list;
    msg_p->name_list = name_list;
    msg_p->long_list = long_list;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VRSI_GET_TAGINFO_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vrsi_del_tags_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  grammar         [?]         
 *  tag_num         [IN]        
 *  id_list         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vrsi_del_tags_req(module_type src_mod_id, kal_uint8 *grammar, kal_int32 tag_num, kal_uint16 *id_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_del_tags_req_struct *msg_p = (media_vrsi_del_tags_req_struct*)
        construct_local_para(sizeof(media_vrsi_del_tags_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->grammar = grammar;
    msg_p->tag_num = tag_num;
    msg_p->id_list = id_list;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VRSI_DEL_TAGS_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vrsi_reset_tags_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  grammar         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vrsi_reset_tags_req(module_type src_mod_id, kal_uint8 *grammar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_reset_tags_req_struct *msg_p = (media_vrsi_reset_tags_req_struct*)
        construct_local_para(sizeof(media_vrsi_reset_tags_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->grammar = grammar;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VRSI_RESET_TAGS_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vrsi_sync_db_req
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
 *  void
 *****************************************************************************/
void aud_send_vrsi_sync_db_req(
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
    media_vrsi_sync_db_req_struct *msg_p = (media_vrsi_sync_db_req_struct*)
        construct_local_para(sizeof(media_vrsi_sync_db_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->grammar = grammar;
    msg_p->tag_num = tag_num;
    msg_p->id_list = id_list;
    msg_p->name_list = name_list;
    msg_p->sync_flag = sync_flag;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VRSI_SYNC_DB_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vrsi_abort_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vrsi_abort_req(module_type src_mod_id, kal_uint32 session_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_abort_req_struct *msg_p = (media_vrsi_abort_req_struct*)
        construct_local_para(sizeof(media_vrsi_abort_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->session_id = session_id;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VRSI_ABORT_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vrsi_close_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vrsi_close_req(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_close_req_struct *msg_p = (media_vrsi_close_req_struct*)
        construct_local_para(sizeof(media_vrsi_close_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_VRSI_CLOSE_REQ, msg_p);
}

/* MED -> MED */


/*****************************************************************************
 * FUNCTION
 *  aud_send_vrsi_process_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_mod_id      [IN]        
 *  session_id      [IN]        
 *  proc_type       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vrsi_process_ind(module_type dst_mod_id, kal_uint32 session_id, kal_uint8 proc_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_process_ind_struct *msg_p = (media_vrsi_process_ind_struct*)
        construct_local_para(sizeof(media_vrsi_process_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->session_id = session_id;
    msg_p->proc_type = proc_type;

    aud_send_ilm(dst_mod_id, MSG_ID_MEDIA_VRSI_PROCESS_IND, msg_p, NULL);
}

/* MED -> MMI */


/*****************************************************************************
 * FUNCTION
 *  aud_send_vrsi_trn_prompt_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_mod_id      [IN]        
 *  session_id      [IN]        
 *  pmp_mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vrsi_trn_prompt_req(module_type dst_mod_id, kal_uint32 session_id, kal_uint8 pmp_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_trn_prompt_req_struct *msg_p = (media_vrsi_trn_prompt_req_struct*)
        construct_local_para(sizeof(media_vrsi_trn_prompt_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->session_id = session_id;
    msg_p->pmp_mode = pmp_mode;

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_MEDIA_VRSI_TRN_PROMPT_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vrsi_trn_result_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_mod_id      [IN]        
 *  session_id      [IN]        
 *  tag_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vrsi_trn_result_ind(module_type dst_mod_id, kal_uint32 session_id, kal_uint16 tag_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_trn_result_ind_struct *msg_p = (media_vrsi_trn_result_ind_struct*)
        construct_local_para(sizeof(media_vrsi_trn_result_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->session_id = session_id;
    msg_p->tag_id = tag_id;

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_MEDIA_VRSI_TRN_RESULT_IND, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vrsi_rcg_prompt_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_mod_id      [IN]        
 *  session_id      [IN]        
 *  pmp_mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vrsi_rcg_prompt_req(module_type dst_mod_id, kal_uint32 session_id, kal_uint8 pmp_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_rcg_prompt_req_struct *msg_p = (media_vrsi_rcg_prompt_req_struct*)
        construct_local_para(sizeof(media_vrsi_rcg_prompt_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->session_id = session_id;
    msg_p->pmp_mode = pmp_mode;

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_MEDIA_VRSI_RCG_PROMPT_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vrsi_rcg_result_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_mod_id      [IN]        
 *  session_id      [IN]        
 *  res_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vrsi_rcg_result_ind(module_type dst_mod_id, kal_uint32 session_id, kal_uint16 res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_rcg_result_ind_struct *msg_p = (media_vrsi_rcg_result_ind_struct*)
        construct_local_para(sizeof(media_vrsi_rcg_result_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->session_id = session_id;
    msg_p->res_type = res_type;

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_MEDIA_VRSI_RCG_RESULT_IND, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vrsi_err_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_mod_id      [IN]        
 *  session_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vrsi_err_ind(module_type dst_mod_id, kal_uint32 session_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_err_ind_struct *msg_p = (media_vrsi_err_ind_struct*)
        construct_local_para(sizeof(media_vrsi_err_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->session_id = session_id;

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_MEDIA_VRSI_ERR_IND, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vrsi_play_tag_finish_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_mod_id      [IN]        
 *  session_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vrsi_play_tag_finish_ind(module_type dst_mod_id, kal_uint32 session_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_play_tag_finish_ind_struct *msg_p = (media_vrsi_play_tag_finish_ind_struct*)
        construct_local_para(sizeof(media_vrsi_play_tag_finish_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->session_id = session_id;

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_MEDIA_VRSI_PLAY_TAG_FINISH_IND, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_vrsi_play_tts_finish_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_mod_id      [IN]        
 *  session_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_vrsi_play_tts_finish_ind(module_type dst_mod_id, kal_uint32 session_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_play_tts_finish_ind_struct *msg_p = (media_vrsi_play_tts_finish_ind_struct*)
        construct_local_para(sizeof(media_vrsi_play_tts_finish_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->session_id = session_id;

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_MEDIA_VRSI_PLAY_TTS_FINISH_IND, msg_p);
}

#endif /* __MED_VRSI_MOD__ */ 

#ifdef __MED_CTM_MOD__


/*****************************************************************************
 * FUNCTION
 *  aud_send_ctm_open_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  ctm_interface       [IN]        
 *  ctm_param           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_ctm_open_req(module_type src_mod_id, kal_uint8 ctm_interface, ctm_param_struct *ctm_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_ctm_open_req_struct *msg_p = (media_ctm_open_req_struct*)
        construct_local_para(sizeof(media_ctm_open_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->ctm_interface = ctm_interface;
    memcpy(&(msg_p->ctm_param), ctm_param, sizeof(ctm_param_struct));

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_CTM_OPEN_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_ctm_open_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_mod_id      [IN]        
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_ctm_open_cnf(module_type dst_mod_id, kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_ctm_open_cnf_struct *msg_p = (media_ctm_open_cnf_struct*)
        construct_local_para(sizeof(media_ctm_open_cnf_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->result = result;

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_MEDIA_CTM_OPEN_CNF, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_ctm_close_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_ctm_close_req(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_ctm_close_req_struct *msg_p = (media_ctm_close_req_struct*)
        construct_local_para(sizeof(media_ctm_close_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_CTM_CLOSE_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_ctm_close_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_mod_id      [IN]        
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_ctm_close_cnf(module_type dst_mod_id, kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_ctm_close_cnf_struct *msg_p = (media_ctm_close_cnf_struct*)
        construct_local_para(sizeof(media_ctm_close_cnf_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->result = result;

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_MEDIA_CTM_CLOSE_CNF, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_ctm_connect_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_ctm_connect_req(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_ctm_connect_req_struct *msg_p = (media_ctm_connect_req_struct*)
        construct_local_para(sizeof(media_ctm_connect_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_CTM_CONNECT_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_ctm_connect_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_mod_id      [IN]        
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_ctm_connect_cnf(module_type dst_mod_id, kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_ctm_connect_cnf_struct *msg_p = (media_ctm_connect_cnf_struct*)
        construct_local_para(sizeof(media_ctm_connect_cnf_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->result = result;

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_MEDIA_CTM_CONNECT_CNF, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_ctm_connected_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_ctm_connected_ind(module_type dst_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_ctm_connected_ind_struct *msg_p = (media_ctm_connected_ind_struct*)
        construct_local_para(sizeof(media_ctm_connected_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_MEDIA_CTM_CONNECTED_IND, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_ctm_send_text_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  num_of_char     [IN]        
 *  text            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_ctm_send_text_req(module_type src_mod_id, kal_uint16 num_of_char, void *text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_ctm_send_text_req_struct *msg_p = (media_ctm_send_text_req_struct*)
        construct_local_para(sizeof(media_ctm_send_text_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->num_of_char = num_of_char;
    MED_ASSERT(num_of_char > 0 && num_of_char <= CTM_SEND_TEXT_CHAR_MAX_NUM);
    memcpy(msg_p->text, text, num_of_char << 1);    /* copy UCS2 text from src */
    msg_p->text[num_of_char] = 0;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_CTM_SEND_TEXT_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_ctm_send_text_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_mod_id      [IN]        
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_ctm_send_text_cnf(module_type dst_mod_id, kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_ctm_send_text_cnf_struct *msg_p = (media_ctm_send_text_cnf_struct*)
        construct_local_para(sizeof(media_ctm_send_text_cnf_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->result = result;

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_MEDIA_CTM_SEND_TEXT_CNF, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_ctm_recv_text_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_mod_id      [IN]        
 *  num_of_char     [IN]        
 *  text            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_ctm_recv_text_ind(module_type dst_mod_id, kal_uint16 num_of_char, void *text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_ctm_recv_text_ind_struct *msg_p = (media_ctm_recv_text_ind_struct*)
        construct_local_para(sizeof(media_ctm_recv_text_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->num_of_char = num_of_char;
    MED_ASSERT(num_of_char > 0 && num_of_char <= CTM_SEND_TEXT_CHAR_MAX_NUM);
    memcpy(msg_p->text, text, num_of_char << 1);    /* copy UCS2 text from src */
    msg_p->text[num_of_char] = 0;

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_MEDIA_CTM_RECV_TEXT_IND, msg_p);
}
#endif /* __MED_CTM_MOD__ */ 

#ifdef __MED_SND_MOD__


/*****************************************************************************
 * FUNCTION
 *  aud_send_snd_check_byte_stream_format_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [?]         
 *  size            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_snd_check_byte_stream_format_req(module_type src_mod_id, kal_uint8 *data, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_snd_check_byte_stream_format_req_struct *msg_p = (media_snd_check_byte_stream_format_req_struct*)
        construct_local_para(sizeof(media_snd_check_byte_stream_format_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->data_p = data;
    msg_p->size = size;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_SND_CHECK_BYTE_STREAM_FORMAT_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_snd_check_file_format_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  file_name       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_snd_check_file_format_req(module_type src_mod_id, kal_wchar *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_snd_check_file_format_req_struct *msg_p = (media_snd_check_file_format_req_struct*)
        construct_local_para(sizeof(media_snd_check_file_format_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->file_name_p = file_name;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_SND_CHECK_FILE_FORMAT_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_snd_play_byte_stream_req
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
 *  void
 *****************************************************************************/
void aud_send_snd_play_byte_stream_req(
        module_type src_mod_id,
        kal_uint8 *data,
        kal_int32 size,
        kal_int16 repeats,
        kal_uint8 format,
        kal_uint8 volume,
        kal_uint8 output_path,
        kal_uint16 identifier)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_snd_play_byte_stream_req_struct *msg_p = (media_snd_play_byte_stream_req_struct*)
        construct_local_para(sizeof(media_snd_play_byte_stream_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->data_p = data;
    msg_p->size = size;
    msg_p->repeats = repeats;
	msg_p->format = format;
    msg_p->volume = volume;
    msg_p->output_path = output_path;
    msg_p->identifier = identifier;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_SND_PLAY_BYTE_STREAM_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_snd_play_file_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  file_name       [?]         
 *  repeats         [IN]        
 *  volume          [IN]        
 *  output_path     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_snd_play_file_req(
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
    media_snd_play_file_req_struct *msg_p = (media_snd_play_file_req_struct*)
        construct_local_para(sizeof(media_snd_play_file_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->file_name_p = file_name;
    msg_p->repeats = repeats;
    msg_p->volume = volume;
    msg_p->output_path = output_path;
    msg_p->identifier = identifier;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_SND_PLAY_FILE_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_snd_play_finish_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_mod_id      [IN]        
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_snd_play_finish_ind(module_type dst_mod_id, kal_uint16 identifier, kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_snd_play_finish_ind_struct *msg_p = (media_snd_play_finish_ind_struct*)
        construct_local_para(sizeof(media_snd_play_finish_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->result = result;
    msg_p->identifier = identifier;

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_MEDIA_SND_PLAY_FINISH_IND, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_snd_stop_play_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_snd_stop_play_req(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_SND_STOP_PLAY_REQ, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_snd_set_volume_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  volume          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_snd_set_volume_req(module_type src_mod_id, kal_uint8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_snd_set_volume_req_struct *msg_p = (media_snd_set_volume_req_struct*)
        construct_local_para(sizeof(media_snd_set_volume_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->volume = volume;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_SND_SET_VOLUME_REQ, msg_p);
}

#endif /* __MED_SND_MOD__ */ 

#ifdef __MED_GENERAL_TTS__
/*****************************************************************************
 * FUNCTION
 *  aud_send_tts_set_attr_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_tts_set_attr_req(module_type src_mod_id, kal_uint32 attr_id, kal_uint32 attr_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_tts_set_attr_req_struct *msg_p = (media_aud_tts_set_attr_req_struct*)
        construct_local_para(sizeof(media_aud_tts_set_attr_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->attr_id = attr_id;
    msg_p->attr_value = attr_value;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_AUD_TTS_SET_ATTR_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_play_file_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  file_param      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_tts_play_req(module_type src_mod_id, void *tts_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_tts_struct *data_p = (aud_tts_struct*) tts_param;
    media_aud_tts_play_req_struct *msg_p = (media_aud_tts_play_req_struct*)
        construct_local_para(sizeof(media_aud_tts_play_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->tts_string = data_p->text_string;
    msg_p->str_type = data_p->str_type;
    msg_p->lang = data_p->lang;
    msg_p->app_type = data_p->app_type;
    msg_p->gander = data_p->gander;
    msg_p->identifier = data_p->identifier;
    msg_p->app_id = data_p->app_id;
    msg_p->volume = data_p->volume;
    msg_p->output_path = data_p->path;
    msg_p->pitch = data_p->pitch;
    msg_p->speed = data_p->speed;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_AUD_TTS_PLAY_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_tts_update_info_ind
 * DESCRIPTION
 *  send message to MMI to invoke tts update infomation
 * PARAMETERS
 *       
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_tts_update_info_ind(kal_uint8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_tts_update_info_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_aud_tts_update_info_ind_struct*)
      construct_local_para(sizeof(media_aud_tts_update_info_ind_struct), TD_CTRL);

    kal_mem_cpy(ind_p->data, data, AUD_TTS_MAX_PROCESS_DATA_SIZE);

    aud_send_ilm(MOD_MMI, MSG_ID_MEDIA_AUD_TTS_UPDATE_INFO_IND, ind_p, NULL);
}
#endif /*#ifdef __MED_GENERAL_TTS__*/


#ifdef __MED_BT_MOD__
/* open */


/*****************************************************************************
 * FUNCTION
 *  aud_send_bt_audio_open_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  profile         [IN]        
 *  mode            [IN]        
 *  connect_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_bt_audio_open_req(module_type src_mod_id, 
										kal_uint8 profile, 
										kal_uint8 mode, 
										kal_uint16 connect_id,
										void* pContext,
										void* req_context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_audio_open_req_struct *msg_p = (media_bt_audio_open_req_struct*)
        construct_local_para(sizeof(media_bt_audio_open_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->profile = profile;
    msg_p->mode = mode;
    msg_p->connect_id = connect_id;
	msg_p->pContext = pContext;
	msg_p->req_context = req_context;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_BT_AUDIO_OPEN_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_bt_audio_open_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_mod_id      [IN]        
 *  profile         [IN]        
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_bt_audio_open_cnf(module_type dst_mod_id, kal_uint16 result, kal_uint16 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_audio_open_cnf_struct *msg_p = (media_bt_audio_open_cnf_struct*)
        construct_local_para(sizeof(media_bt_audio_open_cnf_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->profile = BT_HFP;
    msg_p->result = result;
    msg_p->error_cause = error_cause;

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_MEDIA_BT_AUDIO_OPEN_CNF, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_bt_audio_open_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_bt_audio_open_ind(module_type dst_mod_id,kal_uint8 profile,kal_uint8 connect_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_audio_open_ind_struct *msg_p = (media_bt_audio_open_ind_struct*)
        construct_local_para(sizeof(media_bt_audio_open_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	msg_p->profile = profile;	
	msg_p->connect_id = connect_id;

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_MEDIA_BT_AUDIO_OPEN_IND, msg_p);
}

/* close */


/*****************************************************************************
 * FUNCTION
 *  aud_send_bt_audio_close_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  profile         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_bt_audio_close_req(kal_uint8 profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_audio_close_req_struct *msg_p = (media_bt_audio_close_req_struct*)
        construct_local_para(sizeof(media_bt_audio_close_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->profile = profile;

    aud_send_msg_to_med(NULL,(kal_uint16) MSG_ID_MEDIA_BT_AUDIO_CLOSE_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_bt_audio_close_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_mod_id      [IN]        
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_bt_audio_close_cnf(module_type dst_mod_id, kal_uint16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_audio_close_cnf_struct *msg_p = (media_bt_audio_close_cnf_struct*)
        construct_local_para(sizeof(media_bt_audio_close_cnf_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->profile = BT_HFP;
    msg_p->result = result;

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_MEDIA_BT_AUDIO_CLOSE_CNF, msg_p);
}

/* close */


/*****************************************************************************
 * FUNCTION
 *  aud_send_bt_audio_close_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_mod_id      [IN]        
 *  cause           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_bt_audio_close_ind(module_type dst_mod_id, kal_uint16 cause, kal_uint8 profile ,kal_uint8 connect_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_audio_close_ind_struct *msg_p = (media_bt_audio_close_ind_struct*)
        construct_local_para(sizeof(media_bt_audio_close_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg_p->cause = cause;	
    msg_p->profile = profile;
	msg_p->connect_id = connect_id;

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_MEDIA_BT_AUDIO_CLOSE_IND, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_bt_audio_turn_on_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  profile         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_bt_audio_turn_on_req(module_type src_mod_id, kal_uint8 profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_audio_turn_on_req_struct *msg_p = (media_bt_audio_turn_on_req_struct*)
        construct_local_para(sizeof(media_bt_audio_turn_on_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->profile = profile;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_BT_AUDIO_TURN_ON_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_bt_audio_turn_off_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  profile         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_bt_audio_turn_off_req(kal_uint8 profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_audio_turn_off_req_struct *msg_p = (media_bt_audio_turn_off_req_struct*)
        construct_local_para(sizeof(media_bt_audio_turn_off_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->profile = profile;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_BT_AUDIO_TURN_OFF_REQ, msg_p);
}

//#ifdef __MED_BT_HFP_MOD__

/*****************************************************************************
 * FUNCTION
 *  aud_send_bt_audio_set_sco_mode_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  profile         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_bt_audio_set_sco_mode_req(module_type src_mod_id, kal_uint8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_audio_set_sco_mode_req_struct *msg_p = (media_bt_audio_set_sco_mode_req_struct*)
        construct_local_para(sizeof(media_bt_audio_set_sco_mode_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->mode = mode;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_BT_AUDIO_SET_SCO_MODE_REQ, msg_p);
}


//#endif /*__MED_BT_HFP_MOD__*/

#endif /* __MED_BT_MOD__ */ 


#ifdef __AUDIO_TRIM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  aud_send_trim_result_ind
 * DESCRIPTION
 *  This function is to send an indicator to MMI for signal the trimming result.
 * PARAMETERS
 *  handle          [IN]      Trimming handle
 *  result          [IN]      Trimming result         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_trim_result_ind(module_type dst_mod_id, kal_uint32 handle, kal_uint32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_trim_result_ind_struct *ind_p = (l4aud_trim_result_ind_struct*)
        construct_local_para(sizeof(l4aud_trim_result_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p->handle = handle;
    ind_p->result = result;

    aud_send_msg_from_med(dst_mod_id, MSG_ID_L4AUD_TRIM_RESULT_IND, ind_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_trim_open_req
 * DESCRIPTION
 *  This function is to send a request to open a trimming handle.
 * PARAMETERS
 *  file_name_in        [IN]    The file to be trimmed from.
 *  file_name_out       [IN]    The file to be trimmed to.
 *  handle_p            [OUT]   Trimming handle        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_trim_open_req(kal_wchar* file_name_in, kal_wchar* file_name_out, kal_uint32* handle_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_trim_open_req_struct *msg_p = (l4aud_trim_open_req_struct*)
        construct_local_para(sizeof(l4aud_trim_open_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->file_name_in = file_name_in;
    msg_p->file_name_out = file_name_out;
    msg_p->handle_p = handle_p;

    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_L4AUD_TRIM_OPEN_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_trim_close_req
 * DESCRIPTION
 *  This function is to send a request to close a trimming handle.
 * PARAMETERS
 *  handle          [IN]      Trimming handle         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_trim_close_req(kal_uint32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_trim_close_req_struct *msg_p = (l4aud_trim_close_req_struct*)
        construct_local_para(sizeof(l4aud_trim_close_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->handle = handle;

    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_L4AUD_TRIM_CLOSE_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_trim_start_req
 * DESCRIPTION
 *  This function is to send a request to start a trimming.
 * PARAMETERS
 *  handle          [IN]      Trimming handle         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_trim_start_req(kal_uint32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_trim_start_req_struct *msg_p = (l4aud_trim_start_req_struct*)
        construct_local_para(sizeof(l4aud_trim_start_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->handle = handle;

    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_L4AUD_TRIM_START_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_trim_stop_req
 * DESCRIPTION
 *  This function is to send a request to stop the trimming.
 * PARAMETERS
 *  handle          [IN]      Trimming handle         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_trim_stop_req(kal_uint32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_trim_stop_req_struct *msg_p = (l4aud_trim_stop_req_struct*)
        construct_local_para(sizeof(l4aud_trim_stop_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->handle = handle;

    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_L4AUD_TRIM_STOP_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_trim_set_param_req
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
void aud_send_trim_set_param_req(kal_int32 handle, kal_uint8 set_type, void* data_p, kal_uint16 data_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_trim_set_param_req_struct *msg_p = (l4aud_trim_set_param_req_struct*)
        construct_local_para(sizeof(l4aud_trim_set_param_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->handle = handle;
    msg_p->set_type = set_type;
    msg_p->data_p = data_p;
    msg_p->data_len = data_len;

    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_L4AUD_TRIM_SET_PARAM_REQ, msg_p);
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
void aud_send_trim_get_param_req(kal_int32 handle, kal_uint8 get_type, void* data_p, kal_uint16* data_len_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_trim_get_param_req_struct *msg_p = (l4aud_trim_get_param_req_struct*)
        construct_local_para(sizeof(l4aud_trim_get_param_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->handle = handle;
    msg_p->get_type = get_type;
    msg_p->data_p = data_p;
    msg_p->data_len_p = data_len_p;

    aud_send_msg_to_med(kal_get_active_module_id(), (kal_uint16) MSG_ID_L4AUD_TRIM_GET_PARAM_REQ, msg_p);
}
#endif /* __AUDIO_TRIM_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  aud_send_in_proc_call_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  func            [IN]        
 *  func_arg1       [IN]        
 *  func_arg2       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_in_proc_call_req(
        module_type src_mod_id,
        media_in_proc_call_type func,
        kal_uint32 func_arg1,
        void *func_arg2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_in_proc_call_req_struct *msg_p = (media_in_proc_call_req_struct*)
        construct_local_para(sizeof(media_in_proc_call_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->func = func;
    msg_p->func_arg1 = func_arg1;
    msg_p->func_arg2 = func_arg2;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_IN_PROC_CALL_REQ, msg_p);
}

/*****************************************************************************
 * FUNCTION
 *  aud_send_in_proc_call_ext_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  func            [IN]        
 *  func_arg1       [IN]        
 *  func_arg2       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_in_proc_call_ext_req(
        module_type src_mod_id,
        media_in_proc_call_ext_type pf_func,
        void* pv_data,
        kal_uint16 ui2_data_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_in_proc_call_ext_req_struct *msg_p = (media_in_proc_call_ext_req_struct*)
        construct_local_para(sizeof(media_in_proc_call_ext_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ui2_data_len <= IN_PROC_CALL_MAX_DATA_LEN)
    {
        msg_p->pf_func = pf_func;
        memcpy(msg_p->pui1_data, pv_data, ui2_data_len);
        msg_p->ui2_data_len = ui2_data_len;

        aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_IN_PROC_CALL_EXT_REQ, msg_p);
    }
}

void aud_send_bt_open_codec_req(module_type src_mod_id, bt_a2dp_audio_cap_struct *cfg, 
    kal_uint8 stream_handle, kal_bool immediate, kal_uint32 seq_no)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_open_codec_req_struct *msg_p = (media_bt_open_codec_req_struct*)
        construct_local_para(sizeof(media_bt_open_codec_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&msg_p->cfg, cfg, sizeof(bt_a2dp_audio_cap_struct));
    msg_p->stream_handle = stream_handle;
    msg_p->immediate = immediate;
    msg_p->seq_no = seq_no;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_BT_OPEN_CODEC_REQ, msg_p);
}

void aud_send_bt_close_codec_req(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_BT_CLOSE_CODEC_REQ, NULL);
}

void aud_send_bt_close_codec_ind(module_type dst_mod_id, kal_uint8 stream_handle, kal_uint32 seq_no)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_close_codec_ind_struct *msg_p = (media_bt_close_codec_ind_struct*)
        construct_local_para(sizeof(media_bt_close_codec_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->seq_no = seq_no;
    msg_p->stream_handle = stream_handle;

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_MEDIA_BT_CLOSE_CODEC_IND, msg_p);
}

#ifdef __BT_SPEAKER_SUPPORT__
void aud_send_bt_open_sink_codec_req(module_type src_mod_id, bt_a2dp_audio_cap_struct *cfg, 
    kal_uint8 stream_handle, kal_bool immediate, kal_uint32 seq_no)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_open_sink_codec_req_struct *msg_p = (media_bt_open_sink_codec_req_struct*)
        construct_local_para(sizeof(media_bt_open_sink_codec_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&msg_p->cfg, cfg, sizeof(bt_a2dp_audio_cap_struct));
    msg_p->stream_handle = stream_handle;
    msg_p->immediate = immediate;
    msg_p->seq_no = seq_no;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_BT_OPEN_SINK_CODEC_REQ, msg_p);
}

void aud_send_bt_close_sink_codec_req(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_BT_CLOSE_SINK_CODEC_REQ, NULL);
}

void aud_send_bt_open_sink_codec_cnf(module_type dst_mod_id,  kal_uint8 stream_handle, kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//MMI Do not want the CNF message

}

void aud_send_bt_close_sink_codec_cnf(module_type dst_mod_id,  kal_uint8 stream_handle, kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//MMI Do not want the CNF message
}

void aud_send_bt_sink_codec_ind(module_type dst_mod_id, kal_uint8 stream_handle, kal_uint8 events)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_sink_codec_ind_struct *msg_p = (media_bt_sink_codec_ind_struct*)
        construct_local_para(sizeof(media_bt_sink_codec_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->events= events;
    msg_p->stream_handle = stream_handle;

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_MEDIA_BT_SINK_CODEC_IND, msg_p);
}

void aud_send_bt_start_sink_codec_cnf(module_type dst_mod_id, kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_a2dp_start_codec_cnf_struct *msg_p = (bt_a2dp_start_codec_cnf_struct*)
        construct_local_para(sizeof(bt_a2dp_start_codec_cnf_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->result = result;

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_MEDIA_BT_START_SINK_CODEC_CNF, msg_p);
}

void aud_send_bt_stop_sink_codec_cnf(module_type dst_mod_id, kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_a2dp_stop_codec_cnf_struct *msg_p = (bt_a2dp_stop_codec_cnf_struct*)
        construct_local_para(sizeof(bt_a2dp_stop_codec_cnf_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->result = result;

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_MEDIA_BT_STOP_SINK_CODEC_CNF, msg_p);
}

#endif

#ifdef __BT_HF_PROFILE__
void aud_send_bt_hf_sco_connect_req(module_type dst_mod_id, kal_uint8 connection_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_sco_connect_req_struct *msg_p = (bt_hf_sco_connect_req_struct*)
        construct_local_para(sizeof(bt_hf_sco_connect_req_struct), TD_UL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->connection_id= connection_id;

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_BT_HF_SCO_CONNECT_REQ, msg_p);
}

void aud_send_bt_hf_sco_disconnect_req(module_type dst_mod_id, kal_uint8 connection_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_sco_connect_req_struct *msg_p = (bt_hf_sco_connect_req_struct*)
        construct_local_para(sizeof(bt_hf_sco_connect_req_struct), TD_UL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->connection_id = connection_id;

    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_BT_HF_SCO_DISCONNECT_REQ, msg_p);
}
#endif

#ifdef __BT_HFG_PROFILE__
void aud_send_bt_hfg_sco_connect_req(module_type dst_mod_id,void* pContext ,void* req_context )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hfg_sco_connect_req_struct *msg_p = (bt_hfg_sco_connect_req_struct*)
        construct_local_para(sizeof(bt_hfg_sco_connect_req_struct), TD_UL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //msg_p->connection_id= connection_id;
	msg_p->pContext = pContext;
	msg_p->req_context = req_context;
	
    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_BT_HFG_SCO_CONNECT_REQ, msg_p);
}

void aud_send_bt_hfg_sco_disconnect_req(module_type dst_mod_id,void* pContext,void* req_context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hfg_sco_connect_req_struct *msg_p = (bt_hfg_sco_connect_req_struct*)
        construct_local_para(sizeof(bt_hfg_sco_connect_req_struct), TD_UL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // msg_p->connection_id = connection_id;
	msg_p->pContext = pContext;
	msg_p->req_context = req_context;
	
    aud_send_msg_from_med(dst_mod_id, (kal_uint16) MSG_ID_BT_HFG_SCO_DISCONNECT_REQ, msg_p);
}
#endif
void aud_send_in_proc_call_req2(
        module_type src_mod_id,
        media_in_proc_call_type func,
        kal_uint32 func_arg1,
        void *func_arg2)
{
#ifndef MED_V_NOT_PRESENT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_in_proc_call_req_struct *msg_p = (media_in_proc_call_req_struct*)
        construct_local_para(sizeof(media_in_proc_call_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->func = func;
    msg_p->func_arg1 = func_arg1;
    msg_p->func_arg2 = func_arg2;

    aud_send_ilm(MOD_MED_V, (kal_uint16) MSG_ID_MEDIA_IN_PROC_CALL_REQ, msg_p, NULL);
#else
    ASSERT(0);
#endif /* MED_V_NOT_PRESENT */
}


void aud_send_in_proc_call_ext_req2(
        module_type src_mod_id,
        media_in_proc_call_ext_type pf_func,
        void* pv_data,
        kal_uint16 ui2_data_len)
{
#ifndef MED_V_NOT_PRESENT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_in_proc_call_ext_req_struct *msg_p = (media_in_proc_call_ext_req_struct*)
        construct_local_para(sizeof(media_in_proc_call_ext_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ui2_data_len <= IN_PROC_CALL_MAX_DATA_LEN)
    {
        msg_p->pf_func = pf_func;
        memcpy(msg_p->pui1_data, pv_data, ui2_data_len);
        msg_p->ui2_data_len = ui2_data_len;

        aud_send_ilm(MOD_MED_V, (kal_uint16) MSG_ID_MEDIA_IN_PROC_CALL_EXT_REQ, msg_p, NULL);
    }
#else
    ASSERT(0);
#endif /* MED_V_NOT_PRESENT */
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_speech_on_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  ctm_interface       [IN]        
 *  ctm_param           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_set_speech_mode_req(kal_bool speech_on, kal_uint8 rat_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    meida_aud_sp_set_mode_req_struct *msg_p = (meida_aud_sp_set_mode_req_struct*)
        construct_local_para(sizeof(meida_aud_sp_set_mode_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->speech_on = speech_on;
    msg_p->rat_mode = rat_mode;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_AUD_SP_SET_MODE_REQ, msg_p);    
}

#ifdef __GAIN_TABLE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  aud_send_set_speech_fir_coeff_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  ctm_interface       [IN]        
 *  ctm_param           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_set_speech_fir_coeff_req(module_type src_mod_id, kal_int16 input_idx, kal_int16 output_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_sp_set_fir_coeff_req_struct *msg_p = (media_aud_sp_set_fir_coeff_req_struct*)
        construct_local_para(sizeof(media_aud_sp_set_fir_coeff_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->input_idx = input_idx;
    msg_p->output_idx = output_idx;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_AUD_SP_SET_FIR_COEFF_REQ, msg_p);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  aud_send_set_speech_enhance_mode_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ctm_interface       [IN]        
 *  ctm_param           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_set_speech_enhance_mode_req(kal_uint8 mode)
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
    msg_p->is_with_param = KAL_FALSE;

    aud_send_msg_to_med(NULL, (kal_uint16) MSG_ID_MEDIA_AUD_SP_SET_ENHANCE_MODE_REQ, msg_p);
}

#ifdef __DUAL_MIC_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  aud_send_set_mic_dual_nr_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  ctm_interface       [IN]        
 *  ctm_param           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_set_mic_dual_nr_req(module_type src_mod_id, kal_bool is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_mic_set_dual_nr_req_struct *msg_p = (l4aud_mic_set_dual_nr_req_struct*)
        construct_local_para(sizeof(l4aud_mic_set_dual_nr_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->is_enable = is_enable;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_L4AUD_MIC_SET_DUAL_NR_REQ, msg_p);
}
#endif /* __DUAL_MIC_SUPPORT__ */

#endif /* MED_NOT_PRESENT */ 

