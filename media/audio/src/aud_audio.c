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
 * aud_audio.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes audio functions of audio manager task.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *    AUD_AUDIO
 * DESCRIPTION
 *    This module defines the audio related function for Audio Manager.
 *  
 ******************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =======*/

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
//#include "app_buff_alloc.h"

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
#include "custom_equipment.h"
//#include "nvram_enums.h"
//#include "nvram_struct.h"
//#include "nvram_user_defs.h"
#include "audio_nvram_def.h"
//#include "custom_nvram_editor_data_item.h"

/* local includes */
#include "med_global.h"
//#include "med_status.h"
#include "aud_defs.h"
#include "med_struct.h"
//#include "med_api.h"
#include "med_context.h"
#include "med_main.h"
#include "aud_main.h"
#include "med_utility.h"

//#include "nvram_data_items.h"
//#include "nvram_struct.h"
#include "device.h"
#include "Drvsignals.h"

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "aud_common_config.h"
#include "kal_public_defs.h"
#if defined(__MTK_TARGET__)
#include "accdet_sw.h"
#endif

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 
#ifdef __MED_CAM_MOD__
//#include "cam_main.h"
#endif 
#if defined(__MED_VID_DEC_MOD__)
#include "vid_main.h"
#endif 

/*==== TYPE DEFINE =======*/
typedef enum
{
    AUD_MEDIA_PATH_BT_A2DP,
    AUD_MEDIA_PATH_BT_HFP,
    AUD_MEDIA_PATH_BT_BOTH
}aud_media_check_bt_path_enum;

/*==== VARIABLES =======*/
//kal_uint8 current_playing_fmradio_volume_level = 0;
extern kal_uint8 current_playing_melody_volume_level;   /* defined in aud_melody.c */

#if defined(TV_OUT_SUPPORT)
kal_bool audio_tv_cable_in = KAL_FALSE;
kal_bool audio_tv_loud_speaker = KAL_FALSE;
#endif

typedef void (*aud_set_output_device_handler) (kal_uint8 device);
typedef void (*aud_set_output_volume_handler) (kal_uint8 volume, kal_int8 digital_gain_index);
typedef void (*aud_set_output_volume_by_mode_handler) (kal_uint8 mode, kal_uint8 level);


static kal_uint16 g_aud_mute_digital_gain_app;

/*we just open one compile option ,we will use classK cp in mt6260*/
#if defined(__CLASSK_CP_SUPPORT__)
    #define BATTERY_LOW_THRESHOLD      (4000000) /* 4.0V */
    #define BATTERY_RECOVERY_THRESHOLD     (4050000) /* 4.05V */
    static kal_uint32 g_classk_battery = 4200000 ;
    static kal_bool g_is_classk_battery_low = KAL_FALSE;
#elif defined(__CLASSAB_VOLUME_PROTECTION__)
    #define BATTERY_LOW_THRESHOLD      (3600000) /* 3.6V */
    #define BATTERY_RECOVERY_THRESHOLD (3650000) /* 3.65V */
    static kal_bool g_is_battery_low = KAL_FALSE;
#endif /* __CLASSK_CP_SUPPORT__ */


#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 

/*****************************************************************************
 * FUNCTION
 *  aud_audio_init
 * DESCRIPTION
 *  This function is used to init audio module for audio manager.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_audio_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __BT_BOX_SUPPORT__
	aud_context_p->audio_mode = AUD_MODE_LOUDSPK;
	#else
    aud_context_p->audio_mode = AUD_MODE_NORMAL;
	#endif
    aud_context_p->identifier = 0;
    aud_context_p->melody_output_device = AUDIO_DEVICE_SPEAKER2;
    aud_context_p->audio_mute = KAL_FALSE;
    aud_context_p->melody_max_volume_level = 16; /* 16-level */
    return;
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

/*****************************************************************************
 * FUNCTION
 *  aud_set_audio_mode_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_audio_mode_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef DUMMY_CNF
    media_aud_set_audio_mode_cnf_struct *cnf_p = NULL;
#endif 

    media_aud_set_audio_mode_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_SET_AUDIO_MODE_REQ_HDLR);

    req_p = (media_aud_set_audio_mode_req_struct*) ilm_ptr->local_para_ptr;
	
#ifdef __BT_BOX_SUPPORT__
    if(req_p->mode != AUD_MODE_HEADSET)
	    req_p->mode = AUD_MODE_LOUDSPK;
#endif

    aud_context_p->audio_mode = req_p->mode;
    aud_set_aud_path_volume(req_p->mode);

#ifdef DUMMY_CNF
    cnf_p = (media_aud_set_audio_mode_cnf_struct*) construct_local_para(sizeof(media_aud_set_audio_mode_cnf_struct), TD_CTRL);

    cnf_p->src_id = req_p->src_id;
    cnf_p->result = KAL_TRUE;
    cnf_p->cause = MED_RES_OK;

    aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_MEDIA_AUD_SET_AUDIO_MODE_CNF, cnf_p, NULL);
#endif /* DUMMY_CNF */ 

}

#ifdef __LINE_IN_SUPPORT__
kal_bool g_is_bt_box_linein_enable 	=KAL_FALSE;
kal_bool g_is_force_use_linein_mic		=KAL_FALSE;

kal_bool aud_is_bt_box_linein_enable(void)
{
    AUD_LINEIN_FUNC_ENTRY1(AUD_IS_LINEIN_ENABLE,g_is_bt_box_linein_enable);
    return g_is_bt_box_linein_enable;
}


/*****************************************************************************
 * FUNCTION
 *  aud_linein_set_volume_by_mode
 * DESCRIPTION
 *  This function sets the volume of linein for a given audio mode.
 * PARAMETERS
 *  mode      [IN]      Audio mode.
 *  level     [IN]      Volume level.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_linein_set_volume_by_mode(kal_uint8 mode, kal_uint8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 new_level;
    kal_uint8 analog_gain;
	kal_uint8 volume_level = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_LINEIN_FUNC_ENTRY2(AUD_SET_LINEIN_VOLUME,mode,level);

    /* If the second bit(from MSB) is set, the level 0 means mute. */
    if (AUD_VOL_IS_MUTE(level))
    {
        AFE_SetOutputVolume(L1SP_LINEIN,0,0);
        return;
    }

    if (AUD_VOL_IS_MUTE_AT_LEVEL_0(level))
    {
        new_level = AUD_VOL_GET_VOLUME_LEVEL(level) - 1;
    }
    else
    {
        new_level = AUD_VOL_GET_VOLUME_LEVEL(level);
    }

    if (AUD_VOL_IS_7_LEVEL_VOLUME(level))  /* N level volume (MSB bit is set) */
    {
	    if (0<=new_level && new_level<7)
        {
             AFE_SetOutputVolume(L1SP_LINEIN,aud_context_p->acoustic_data.linein_volume_gain[new_level],0);
        }
    }
	else if (AUD_VOL_IS_N_LEVEL_VOLUME(level))  /* N level volume (MSB bit is set) */
    {
	    switch (new_level)
        {
            case 0:
                volume_level = 0;
                break;
            case 1: case 2: case 3:
                volume_level = 1;
                break;
            case 4: case 5: case 6:
                volume_level = 2;
                break;
            case 7: case 8: case 9:
                volume_level = 3;
                break;
            case 10: case 11: case 12:
                volume_level = 4;
                break;
            case 13: case 14:            
                volume_level = 5;
                break;
            case 15:
                volume_level = 6;
                break;
            default:
                ASSERT(0);
        }
		
        AFE_SetOutputVolume(L1SP_LINEIN,aud_context_p->acoustic_data.linein_volume_gain[volume_level],0);
    }
		
}


/*****************************************************************************
 * FUNCTION
 *  aud_enable_bt_box_linein_req_hdlr
 * DESCRIPTION
 *  This function is used to enable/disable bt box linein.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_enable_bt_box_linein_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_enable_bt_box_linein_req_struct *req_p = (media_enable_bt_box_linein_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	AUD_LINEIN_FUNC_ENTRY1(AUD_SET_LINEIN_ENABLE,req_p->on);
    if(req_p->on)
    {
        g_is_bt_box_linein_enable = 1;
		#ifdef __MTK_TARGET__
		kal_sleep_task(3);//wait for normal AFE path shut down
		
		#if defined(EXT_DAC_SUPPORT) && defined(__BTBOX_NOLCD_TEST__)
        EXT_DAC_TurnOnSpeaker(EXT_DAC_LINEIN, L1SP_LOUD_SPEAKER);
		#else
		AFE_SetOutputDevice(L1SP_LINEIN,L1SP_LOUD_SPEAKER);
		LINEIN_Open();
		#endif

		AFE_SwitchExtAmplifier(KAL_TRUE);
		#endif
	}
	else
	{
	    #if defined(EXT_DAC_SUPPORT) && defined(__BTBOX_NOLCD_TEST__)
        EXT_DAC_TurnOffSpeaker(L1SP_LOUD_SPEAKER);
		#else
		LINEIN_Close();
		#endif
	    g_is_bt_box_linein_enable = 0;
		#ifdef __MTK_TARGET__
		AFE_SwitchExtAmplifier(KAL_FALSE);
		#endif
	}
}

kal_bool aud_is_force_use_linein_mic(void)
{
    AUD_LINEIN_FUNC_ENTRY1(AUD_IS_FORCE_LINEIN_MIC,g_is_force_use_linein_mic);
    return g_is_force_use_linein_mic;
}

/*****************************************************************************
 * FUNCTION
 *  aud_enable_bt_box_linein_req_hdlr
 * DESCRIPTION
 *  This function is used to enable/disable bt box linein.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_force_use_linein_mic_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_force_use_linein_mic_req_struct *req_p = (media_force_use_linein_mic_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	AUD_LINEIN_FUNC_ENTRY1(AUD_FORCE_USE_LINEIN_MIC,req_p->force_use);
    if(req_p->force_use)
    {
		aud_audio_set_melody_path_volume(AUD_MODE_LOUDSPK);
		g_is_force_use_linein_mic = KAL_TRUE;
	}
	else
	{
	    g_is_force_use_linein_mic = KAL_FALSE;
		/* Restore audio settings*/
		aud_set_aud_path_volume(aud_context_p->audio_mode);
	}
}
#endif

#ifdef __KARAOKE_SUPPORT__
Media_Kara_opt_mode g_karaoke_mode =0;
kal_wchar g_record_file_name[MAX_MEDIA_FILE_NAME];
FS_HANDLE g_karaoke_fs_handle;
#ifdef __MTK_TARGET__
extern kal_bool g_karaoke_mono;
#endif


Media_Kara_opt_mode aud_get_karaoke_mode(void)
{
    return g_karaoke_mode;
}

/*****************************************************************************
 * FUNCTION
 *  aud_set_karaoke_mode_req_hdlr
 * DESCRIPTION
 *  This function is used to enable/disable bt box linein.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_karaoke_mode_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_set_karaoke_mode_req_struct *req_p = (media_set_karaoke_mode_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	AUD_KARAOKE_FUNC_ENTRY1(AUD_SET_KARAOKE_MODE,req_p->mode);
    if(req_p->mode)  //karaoke mode not none
    {
        Media_SetKaraoke(KAL_TRUE);
	}
	else
	{
	    Media_SetKaraoke(KAL_FALSE);
	}
	g_karaoke_mode = req_p->mode;
	Media_SetKaraOperationMode(req_p->mode);
	kal_wstrncpy(g_record_file_name, req_p->file_name, MAX_MEDIA_FILE_NAME);
	#ifndef __MTK_TARGET__
	g_karaoke_fs_handle = FS_Open(g_record_file_name,FS_CREATE);
	FS_Close(g_karaoke_fs_handle);
	#endif
}

/*****************************************************************************
 * FUNCTION
 *  aud_set_karaoke_channel_req_hdlr
 * DESCRIPTION
 *  This function is used to enable/disable bt box linein.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_karaoke_channel_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_set_karaoke_channel_req_struct *req_p = (media_set_karaoke_channel_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MTK_TARGET__
	if(g_karaoke_mono==KAL_TRUE) //wxw
	{
		req_p->channel=MEDIA_KARAREC_MIX_MONO;
	}
	#endif
	AUD_KARAOKE_FUNC_ENTRY1(AUD_SET_KARAOKE_CHANNEL,req_p->channel);
	Media_SetKaraRecMixChannel(req_p->channel);
}

/*****************************************************************************
 * FUNCTION
 *  aud_set_karaoke_digitgain_req_hdlr
 * DESCRIPTION
 *  This function is used to enable/disable bt box linein.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_karaoke_digitgain_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_set_karaoke_digitgain_req_struct *req_p = (media_set_karaoke_digitgain_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	AUD_KARAOKE_FUNC_ENTRY2(AUD_SET_KARAOKE_DIGITGAIN,req_p->uNum,req_p->uDen);
	//Media_set_karaoke_digitalgain(req_p->uNum,req_p->uDen);
	#ifdef __MTK_TARGET__
	Karaoke_DL_SetGain(req_p->uNum);
	Karaoke_UL_SetGain(req_p->uDen);
	#endif
}

#ifdef __KARAOKE_NEED_KEEP_SRC_PATH__
STFSAL fremixfile;
kal_bool g_remix_is_on=KAL_FALSE;
/*****************************************************************************
 * FUNCTION
 *  aud_karaoke_remix_turn_on_req_hdlr
 * DESCRIPTION
 *  This function is used to turn on karaoke remix.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_karaoke_remix_turn_on_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_karaoke_remix_turn_on_req_struct *req_p = (media_karaoke_remix_turn_on_req_struct*) ilm_ptr->local_para_ptr;
	kal_int32 med_result=MED_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(req_p->rec_path != NULL)
	{
		if(FSAL_Open(&fremixfile, req_p->rec_path, FSAL_READ_SHARED) != FSAL_OK)
		{
		    med_result = MED_RES_OPEN_FILE_FAIL;
		}
		else
		{
            med_result = AudioPP_Remix_TurnOn(&fremixfile,req_p->msRecordStartTime,req_p->msAudioSeekTime);
			med_result = aud_get_res(med_result);
			g_remix_is_on = KAL_TRUE;
		}
	}
	AUD_KARAOKE_FUNC_ENTRY1(AUD_KARAOKE_REMIX_TURN_ON,med_result);
	aud_set_karaoke_result_and_event(med_result,AUD_KARAOKE_EVT_SET);//NEED TO DO deal with the med_result
}


/*****************************************************************************
 * FUNCTION
 *  aud_karaoke_remix_turn_off
 * DESCRIPTION
 *  This function is used to turn off karaoke remix.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_karaoke_remix_turn_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	AUD_KARAOKE_FUNC_ENTRY1(AUD_KARAOKE_REMIX_TURN_OFF,g_remix_is_on);
	if(!g_remix_is_on)
		return;
	AudioPP_Remix_TurnOff();
	FSAL_Close(&fremixfile); 
	g_remix_is_on = KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_karaoke_remix_turn_off_req_hdlr
 * DESCRIPTION
 *  This function is used to turn off karaoke remix.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_karaoke_remix_turn_off_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_karaoke_remix_turn_off_req_struct *req_p = (media_karaoke_remix_turn_off_req_struct*) ilm_ptr->local_para_ptr;
	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	aud_karaoke_remix_turn_off();
}


/*****************************************************************************
 * FUNCTION
 *  aud_karaoke_set_remix_mode_req_hdlr
 * DESCRIPTION
 *  This function is used to set karaoke remix mode.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_karaoke_set_remix_mode_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_karaoke_set_remix_mode_req_struct *req_p = (media_karaoke_set_remix_mode_req_struct*) ilm_ptr->local_para_ptr;
	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	AUD_KARAOKE_FUNC_ENTRY1(AUD_KARAOKE_REMIX_MODE,req_p->channelMode);
	AudioPP_Remix_SetMode(req_p->channelMode);
}


/*****************************************************************************
 * FUNCTION
 *  aud_karaoke_set_remix_audio_gain_req_hdlr
 * DESCRIPTION
 *  This function is used to set karaoke audio gain.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_karaoke_set_remix_audio_gain_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_karaoke_set_remix_audio_gain_req_struct *req_p = (media_karaoke_set_remix_audio_gain_req_struct*) ilm_ptr->local_para_ptr;
	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	AUD_KARAOKE_FUNC_ENTRY1(AUD_KARAOKE_REMIX_AUDIO_GAIN,req_p->audio_gain);
	AudioPP_Remix_SetAudioGain(req_p->audio_gain);
}


/*****************************************************************************
 * FUNCTION
 *  aud_karaoke_set_remix_voice_gain_req_hdlr
 * DESCRIPTION
 *  This function is used to set karaoke voice gain.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_karaoke_set_remix_voice_gain_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_karaoke_set_remix_voice_gain_req_struct *req_p = (media_karaoke_set_remix_voice_gain_req_struct*) ilm_ptr->local_para_ptr;
	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	AUD_KARAOKE_FUNC_ENTRY1(AUD_KARAOKE_REMIX_VOICE_GAIN,req_p->voice_gain);
	AudioPP_Remix_SetVoiceGain(req_p->voice_gain);
}
#endif
#endif


#ifdef __VIBRATION_SPEAKER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  aud_vib_spk_calibration_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vib_spk_calibration_hdlr(ilm_struct *ilm_ptr)
{

	Media_Vibrate_CF_Check();	
}
#endif

#if defined(__AUDIO_DC_CALIBRATION_SUPPORT__) || defined(__VIBRATION_SPEAKER_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  aud_get_calibration_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr
 * RETURNS
 *  void
 *****************************************************************************/
void aud_get_calibration_hdlr(ilm_struct *ilm_ptr)
{
    switch (ilm_ptr->msg_id){
        case MSG_ID_BMT_ADC_MEASURE_DONE_CONF:
        {
            Media_CaliType type = Media_GetCalibrationType();
            bmt_adc_measure_done_conf_struct *result = (bmt_adc_measure_done_conf_struct *)ilm_ptr->local_para_ptr;
            if(type==MEDIA_CALI_DC)
            {
               AFE_Retrieve_DC_Cali_Data((kal_int32)result->adc_value);
            }
            else if(MEDIA_CALI_VIB)
            {
               AFE_Retrieve_VIB_CF_Data((kal_int32)result->adc_value);
            }
            break;
        }
    }
}
#endif /*__AUDIO_DC_CALIBRATION_SUPPORT__ __VIBRATION_SPEAKER_SUPPORT__*/



#if defined( __CLASSAB_VOLUME_PROTECTION__) || defined(__CLASSK_CP_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  aud_battery_voltage_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_battery_voltage_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    l4audio_batt_voltage_ind_struct* ind_p = (l4audio_batt_voltage_ind_struct*)ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__CLASSK_CP_SUPPORT__) 

    g_classk_battery=ind_p->voltage;

    if (ind_p->voltage < BATTERY_LOW_THRESHOLD)
    {    
        if (!g_is_classk_battery_low) /* Transition to voltage lower than 3.6V */
        {
            /* Notify L1audio to set charge pump */
            Media_SetChargePump(KAL_TRUE,MEDIA_VCP_MED);

        }

        g_is_classk_battery_low = KAL_TRUE;
    }
    else if (ind_p->voltage > BATTERY_RECOVERY_THRESHOLD)
    {      
       if (g_is_classk_battery_low) /* Transition to voltage higher than 3.65V */
        {
            /* Notify L1audio to disable charge pump */
           Media_SetChargePump(KAL_FALSE,MEDIA_VCP_MED);
        }

        g_is_classk_battery_low = KAL_FALSE;
    }

#elif defined(__CLASSAB_VOLUME_PROTECTION__)
    if (ind_p->voltage < BATTERY_LOW_THRESHOLD)
    {
        if (!g_is_battery_low) /* Transition to voltage lower than 3.6V */
        {
            /* Notify L1audio to enable volume protection */
            Media_EnableVolumeProtection(KAL_TRUE);

            /* Notify MMI to enter power-saving mode */
            aud_send_battery_state_ind(KAL_TRUE);
        }

        g_is_battery_low = KAL_TRUE;
    }
    else if (ind_p->voltage > BATTERY_RECOVERY_THRESHOLD)
    {
        if (g_is_battery_low) /* Transition to voltage higher than 3.65V */
        {
            /* Notify L1audio to disable volume protection */
            Media_EnableVolumeProtection(KAL_FALSE);

            /* Notify MMI to leave power-saving mode */
            aud_send_battery_state_ind(KAL_FALSE);
        }

        g_is_battery_low = KAL_FALSE;
    }
#endif/*__CLASSK_CP_SUPPORT__*/
}
/*****************************************************************************
 * FUNCTION
 *  aud_get_vbat_value
 * DESCRIPTION
 *  This function is a callback of l1audio provide vbat value for class k .
 * PARAMETERS
 *  g_classk_battery      [OUT]     The battery value to driver .
 * RETURNS
 *  void
 *****************************************************************************/
 kal_uint32 aud_get_vbat_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    return g_classk_battery;
}

#endif /* defined( __CLASSAB_VOLUME_PROTECTION__) || defined(__CLASSK_CP_SUPPORT__) */



/*****************************************************************************
 * FUNCTION
 *  aud_get_audio_profile_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_get_audio_profile_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_get_audio_profile_req_struct *req_p;
    media_aud_get_audio_profile_cnf_struct *cnf_p = NULL;
    kal_uint8 mode;
    audio_profile_struct *profile_p;
    custom_acoustic_struct *data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_GET_AUDIO_PROFILE_REQ_HDLR);
    req_p = (media_aud_get_audio_profile_req_struct*) ilm_ptr->local_para_ptr;

    cnf_p = (media_aud_get_audio_profile_cnf_struct*)
        construct_local_para(sizeof(media_aud_get_audio_profile_cnf_struct), TD_CTRL);

    cnf_p->src_id = req_p->src_id;
    mode = req_p->mode;
    profile_p = &cnf_p->audio_profile;
    data_p = &aud_context_p->acoustic_data;
    profile_p->mode = mode;

    if (mode < MAX_VOL_CATE)
    {
        kal_mem_cpy(
            profile_p->speech,
            data_p->volume_gain[mode][AUD_VOLUME_SPH],
            sizeof(data_p->volume_gain[mode][AUD_VOLUME_SPH]));
        kal_mem_cpy(
            profile_p->keytone,
            data_p->volume_gain[mode][AUD_VOLUME_KEY],
            sizeof(data_p->volume_gain[mode][AUD_VOLUME_KEY]));
        kal_mem_cpy(
            profile_p->melody,
            data_p->volume_gain[mode][AUD_VOLUME_MEDIA],
            sizeof(data_p->volume_gain[mode][AUD_VOLUME_MEDIA]));
        kal_mem_cpy(
            profile_p->sound,
            data_p->volume_gain[mode][AUD_VOLUME_FMR],
            sizeof(data_p->volume_gain[mode][AUD_VOLUME_FMR]));
        kal_mem_cpy(
            profile_p->mic,
            data_p->volume_gain[mode][AUD_VOLUME_MIC],
            sizeof(data_p->volume_gain[mode][AUD_VOLUME_MIC]));
        profile_p->sidetone = data_p->volume_gain[mode][AUD_VOLUME_SID][data_p->volume[mode][AUD_VOLUME_SID]];
    #ifdef __16_LEVEL_AUDIO_VOLUME__
        /* get 16-level audio volume settings */
        profile_p->max_melody_volume_gain = data_p->max_melody_volume_gain[mode];
        profile_p->melody_volume_gain_step = data_p->melody_volume_gain_step[mode];
    #endif /* __16_LEVEL_AUDIO_VOLUME__ */
        cnf_p->result = KAL_TRUE;
    }
#if defined(TV_OUT_SUPPORT)
    else if(mode == VOL_TV_OUT)
    {
        memset(profile_p, 0 , sizeof(audio_profile_struct));
    #ifdef __16_LEVEL_AUDIO_VOLUME__
        /* get 16-level audio volume settings */
        profile_p->max_melody_volume_gain = data_p->max_melody_volume_gain[mode];
        profile_p->melody_volume_gain_step = data_p->melody_volume_gain_step[mode];
    #endif /* __16_LEVEL_AUDIO_VOLUME__ */
        kal_mem_cpy(
            profile_p->tv_out_volume_gain,
            data_p->tv_out_volume_gain,
            sizeof(data_p->tv_out_volume_gain));    
        cnf_p->result = KAL_TRUE;
    }
#endif /* TV_OUT_SUPPORT */
    else
    {
        cnf_p->result = KAL_FALSE;
    }

    aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_MEDIA_AUD_GET_AUDIO_PROFILE_CNF, cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  aud_set_audio_profile_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_audio_profile_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    media_aud_set_audio_profile_req_struct *req_p = NULL;
    audio_profile_struct *profile_p;
    custom_acoustic_struct *data_p;
    kal_uint8 mode;
    kal_uint8 result = MED_RES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_aud_set_audio_profile_req_struct*) ilm_ptr->local_para_ptr;

    AUD_FUNC_ENTRY(AUD_SET_AUDIO_PROFILE_REQ_HDLR);

    if (req_p)
    {
        aud_context_p->src_id = req_p->src_id;
        profile_p = &req_p->audio_profile;
        data_p = &aud_context_p->acoustic_data;
        mode = profile_p->mode;

        if (mode < MAX_VOL_CATE)
        {
            kal_mem_cpy(
                data_p->volume_gain[mode][AUD_VOLUME_SPH],
                profile_p->speech,
                sizeof(data_p->volume_gain[mode][AUD_VOLUME_SPH]));
            kal_mem_cpy(
                data_p->volume_gain[mode][AUD_VOLUME_KEY],
                profile_p->keytone,
                sizeof(data_p->volume_gain[mode][AUD_VOLUME_KEY]));
            kal_mem_cpy(
                data_p->volume_gain[mode][AUD_VOLUME_MEDIA],
                profile_p->melody,
                sizeof(data_p->volume_gain[mode][AUD_VOLUME_MEDIA]));
            kal_mem_cpy(
                data_p->volume_gain[mode][AUD_VOLUME_FMR],
                profile_p->sound,
                sizeof(data_p->volume_gain[mode][AUD_VOLUME_FMR]));
            kal_mem_cpy(
                data_p->volume_gain[mode][AUD_VOLUME_MIC],
                profile_p->mic,
                sizeof(data_p->volume_gain[mode][AUD_VOLUME_MIC]));
            kal_mem_set(
                data_p->volume_gain[mode][AUD_VOLUME_SID],
                profile_p->sidetone,
                sizeof(data_p->volume_gain[mode][AUD_VOLUME_SID]));
    #ifdef __16_LEVEL_AUDIO_VOLUME__
            /* set 16-level audio volume settings */
            data_p->max_melody_volume_gain[mode] = profile_p->max_melody_volume_gain;
            data_p->melody_volume_gain_step[mode] = profile_p->melody_volume_gain_step;
    #endif /* __16_LEVEL_AUDIO_VOLUME__ */
            aud_set_aud_path_volume(aud_context_p->audio_mode);
        }
#if defined(TV_OUT_SUPPORT)
        else if(mode == VOL_TV_OUT)
        {
    #ifdef __16_LEVEL_AUDIO_VOLUME__
            /* set 16-level audio volume settings */
            data_p->max_melody_volume_gain[mode] = profile_p->max_melody_volume_gain;
            data_p->melody_volume_gain_step[mode] = profile_p->melody_volume_gain_step;
    #endif /* __16_LEVEL_AUDIO_VOLUME__ */
            kal_mem_cpy(
                data_p->tv_out_volume_gain,
                profile_p->tv_out_volume_gain,
                sizeof(data_p->tv_out_volume_gain));
        }
#endif /* TV_OUT_SUPPORT */

        if (req_p->update_nvram)
        {
            if(med_context_p->nvram_state == MED_POWERON_READING_NVRAM_FINISH)
            {
                aud_context_p->src_mod = ilm_ptr->src_mod_id;
                aud_send_msg_to_nvram(
                    MSG_ID_NVRAM_WRITE_REQ,
                    NVRAM_EF_CUST_ACOUSTIC_DATA_LID,
                    &(aud_context_p->acoustic_data),
                    sizeof(custom_acoustic_struct));
                return;
            }
            else
            {
                result = MED_RES_FAIL;
            }
        }

        aud_send_set_audio_profile_cnf(result);


    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_get_audio_param_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_get_audio_param_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_get_audio_param_req_struct *req_p;
    media_aud_get_audio_param_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_GET_AUDIO_PARAM_REQ_HDLR);

    req_p = (media_aud_get_audio_param_req_struct*) ilm_ptr->local_para_ptr;

    /* MED start finish, send message to get value from NVRAM */
    if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM_FINISH)
    {
        aud_context_p->src_id = req_p->src_id;
        aud_context_p->src_mod = ilm_ptr->src_mod_id;
        aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_PARAM_LID, 0, 0);
    }
    else
    {
        cnf_p = (media_aud_get_audio_param_cnf_struct*)
            construct_local_para(sizeof(media_aud_get_audio_param_cnf_struct), TD_CTRL);

        cnf_p->src_id = req_p->src_id;
        cnf_p->result = KAL_FALSE;

        aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_MEDIA_AUD_GET_AUDIO_PARAM_CNF, cnf_p, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_get_audio_param_from_nvram_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_get_audio_param_from_nvram_rsp(void* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_get_audio_param_cnf_struct *cnf_p;
    audio_param_struct *nvram_param_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_param_p = (audio_param_struct*)param;

    cnf_p = (media_aud_get_audio_param_cnf_struct*)
        construct_local_para(sizeof(media_aud_get_audio_param_cnf_struct), TD_CTRL);

    cnf_p->src_id = aud_context_p->src_id;
    cnf_p->result = KAL_TRUE;
    kal_mem_cpy(&cnf_p->audio_param, nvram_param_p, sizeof(audio_param_struct));

    aud_send_ilm(aud_context_p->src_mod, MSG_ID_MEDIA_AUD_GET_AUDIO_PARAM_CNF, cnf_p, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  aud_set_audio_param_to_driver
 * DESCRIPTION
 *  set parameters to audio drvier
 * PARAMETERS
 *  param_p     [IN]    audio parameter pointer
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_audio_param_to_driver(audio_param_struct *param_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Apply change to driver */
    L1SP_LoadCommonSpeechPara(param_p->speech_common_para);
    Media_SetMelodyFilter(MELODY_FIR_COEFF_NUM, param_p->Melody_FIR_Coeff_Tbl);
    aud_set_aud_path_volume(aud_context_p->audio_mode);
    //aud_melody_set_max_swing(param_p->max_swing);

    /* Set compensation filter to driver */
#ifdef AUDIO_COMPENSATION_ENABLE
    Media_SetAudioCompensation(MEDIA_AUD_COMP_LOUDSPEAKER, param_p->audio_compensation_coeff[0]);
    Media_SetAudioCompensation(MEDIA_AUD_COMP_EARPHONE, param_p->audio_compensation_coeff[1]);
    Media_SetAudioCompensation(MEDIA_AUD_COMP_LOUDSPEAKER_RINGTONE, param_p->audio_compensation_coeff[2]);
#endif /* AUDIO_COMPENSATION_ENABLE */


}

/*****************************************************************************
 * FUNCTION
 *  aud_set_audio_param_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_audio_param_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    media_aud_set_audio_param_req_struct *req_p = NULL;
    audio_param_struct *param_p;
    kal_uint8 *nvram_data;
    kal_uint8 result = MED_RES_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_SET_AUDIO_PARAM_REQ_HDLR);

    aud_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_aud_set_audio_param_req_struct*) ilm_ptr->local_para_ptr;

    if (req_p)
    {
        param_p = &req_p->audio_param;

        /*set to L1SP directly*/
        L1SP_SetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX_PARAM,(kal_uint8*)param_p, sizeof(audio_param_struct));

        /* Apply change to driver */
        aud_set_audio_param_to_driver(param_p);

        /* Write to NVRAM */
        if(req_p->update_nvram)
        {
            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM_FINISH)
            {
                nvram_data = (kal_uint8*)get_ctrl_buffer(sizeof(audio_param_struct));

                if (nvram_data)
                {
                    kal_mem_cpy(nvram_data, param_p, sizeof(audio_param_struct));
                    aud_send_msg_to_nvram(MSG_ID_NVRAM_WRITE_REQ, NVRAM_EF_AUDIO_PARAM_LID, nvram_data, sizeof(audio_param_struct));
                    free_ctrl_buffer((void*)nvram_data);
                    return;
                }
            }
        }
        else
        {
            result = MED_RES_OK;
        }

        aud_send_set_audio_param_cnf(result);
    
    }
}

#ifdef __AMRWB_LINK_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  aud_get_audio_wb_input_fir_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_get_audio_wb_input_fir_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    media_aud_get_audio_wb_input_fir_param_req_struct *req_p = NULL;
    media_aud_get_audio_wb_input_fir_param_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY1(AUD_GET_AUDIO_WB_PARAM_REQ_HDLR,0);
    req_p = (media_aud_get_audio_wb_input_fir_param_req_struct*) ilm_ptr->local_para_ptr;

    cnf_p = (media_aud_get_audio_wb_input_fir_param_cnf_struct*)
        construct_local_para(sizeof(media_aud_get_audio_wb_input_fir_param_cnf_struct), TD_CTRL);

    cnf_p->src_id = req_p->src_id;

    cnf_p->result = KAL_TRUE;

    L1SP_GetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX_WB_SPEECH_INPUT_FIR,(void*) &(cnf_p->fir_param),sizeof(audio_wb_speech_fir_struct));

    aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_MEDIA_AUD_GET_AUDIO_WB_INPUT_FIR_PARAM_CNF, cnf_p, NULL);

}

/*****************************************************************************
 * FUNCTION
 *  aud_get_audio_wb_output_fir_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_get_audio_wb_output_fir_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_get_audio_wb_output_fir_param_req_struct *req_p = NULL;
    media_aud_get_audio_wb_output_fir_param_cnf_struct *cnf_p = NULL;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY1(AUD_GET_AUDIO_WB_PARAM_REQ_HDLR,1);
    req_p = (media_aud_get_audio_wb_output_fir_param_req_struct*) ilm_ptr->local_para_ptr;

    cnf_p = (media_aud_get_audio_wb_output_fir_param_cnf_struct*)
        construct_local_para(sizeof(media_aud_get_audio_wb_output_fir_param_cnf_struct), TD_CTRL);

    cnf_p->src_id = req_p->src_id;

    cnf_p->result = KAL_TRUE;

    L1SP_GetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX_WB_SPEECH_OUTPUT_FIR,(void*) &(cnf_p->fir_param),sizeof(audio_wb_speech_fir_struct));

    aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_MEDIA_AUD_GET_AUDIO_WB_OUTPUT_FIR_PARAM_CNF, cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  aud_get_audio_wb_mode_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_get_audio_wb_mode_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_get_audio_wb_mode_param_req_struct *req_p = NULL;
    media_aud_get_audio_wb_mode_param_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY1(AUD_GET_AUDIO_WB_PARAM_REQ_HDLR,2);
    
    req_p = (media_aud_get_audio_wb_mode_param_req_struct*) ilm_ptr->local_para_ptr;

    cnf_p = (media_aud_get_audio_wb_mode_param_cnf_struct*)
        construct_local_para(sizeof(media_aud_get_audio_wb_mode_param_cnf_struct), TD_CTRL);

    cnf_p->src_id = req_p->src_id;

    cnf_p->result = KAL_TRUE;

    L1SP_GetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX_WB_SPEECH_MODE_PARAM,(void*) &(cnf_p->fir_param),sizeof(audio_wb_speech_mode_struct));

    aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_MEDIA_AUD_GET_AUDIO_WB_MODE_PARAM_CNF, cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  aud_set_audio_wb_input_fir_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_audio_wb_input_fir_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_audio_wb_input_fir_param_req_struct *req_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_aud_set_audio_wb_input_fir_param_req_struct*) ilm_ptr->local_para_ptr;

    AUD_FUNC_ENTRY1(AUD_SET_AUDIO_WB_PARAM_REQ_HDLR,0);

    if(req_p == NULL)
    {
        return ;
    }

    aud_context_p->src_id = req_p->src_id;

    /*set to L1SP directly*/
    L1SP_SetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX_WB_SPEECH_INPUT_FIR,(kal_uint8*) (&req_p->fir_param), sizeof(audio_wb_speech_fir_struct));

    aud_set_aud_path_volume(aud_context_p->audio_mode);

    if (req_p->update_nvram)
    {
        if(med_context_p->nvram_state == MED_POWERON_READING_NVRAM_FINISH)
        {
            aud_context_p->src_mod = ilm_ptr->src_mod_id;

            aud_send_msg_to_nvram(
                MSG_ID_NVRAM_WRITE_REQ,
                NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_LID,
                &(req_p->fir_param),
                sizeof(audio_wb_speech_fir_struct));
        }
        else
        {
            aud_send_set_audio_wb_input_fir_cnf(MED_RES_FAIL);
        }
    }
    else
    {
        aud_send_set_audio_wb_input_fir_cnf(MED_RES_OK);
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  aud_set_audio_wb_output_fir_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_audio_wb_output_fir_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_audio_wb_output_fir_param_req_struct *req_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_aud_set_audio_wb_output_fir_param_req_struct*) ilm_ptr->local_para_ptr;

    AUD_FUNC_ENTRY1(AUD_SET_AUDIO_WB_PARAM_REQ_HDLR,1);

    if(req_p == NULL)
    {
        return ;
    }

    aud_context_p->src_id = req_p->src_id;

    /*set to L1SP directly*/
    L1SP_SetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX_WB_SPEECH_OUTPUT_FIR,(kal_uint8*) (&req_p->fir_param), sizeof(audio_wb_speech_fir_struct));


    aud_set_aud_path_volume(aud_context_p->audio_mode);

    if (req_p->update_nvram)
    {
        if(med_context_p->nvram_state == MED_POWERON_READING_NVRAM_FINISH)
        {
            aud_context_p->src_mod = ilm_ptr->src_mod_id;

            aud_send_msg_to_nvram(
                MSG_ID_NVRAM_WRITE_REQ,
                NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_LID,
                &(req_p->fir_param),
                sizeof(audio_wb_speech_fir_struct));
        }
        else
        {
            aud_send_set_audio_wb_output_fir_cnf(MED_RES_FAIL);
        }
    }
    else
    {
        aud_send_set_audio_wb_output_fir_cnf(MED_RES_OK);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  aud_set_audio_wb_mode_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_audio_wb_mode_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_audio_wb_mode_param_req_struct *req_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_aud_set_audio_wb_mode_param_req_struct*) ilm_ptr->local_para_ptr;

    AUD_FUNC_ENTRY1(AUD_SET_AUDIO_WB_PARAM_REQ_HDLR,2);

    if(req_p == NULL)
    {
        return ;
    }

    aud_context_p->src_id = req_p->src_id;

    /*set to L1SP directly*/
    L1SP_SetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX_WB_SPEECH_MODE_PARAM,(kal_uint8*) (&req_p->mode), sizeof(audio_wb_speech_mode_struct));

    aud_set_aud_path_volume(aud_context_p->audio_mode);

    if (req_p->update_nvram)
    {
        if(med_context_p->nvram_state == MED_POWERON_READING_NVRAM_FINISH)
        {
            aud_context_p->src_mod = ilm_ptr->src_mod_id;

            aud_send_msg_to_nvram(
                MSG_ID_NVRAM_WRITE_REQ,
                NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_LID,
                &(req_p->mode),
                sizeof(audio_wb_speech_mode_struct));
        }
        else
        {
            aud_send_set_audio_wb_mode_cnf(MED_RES_FAIL);
        }
    }
    else
    {
        aud_send_set_audio_wb_mode_cnf(MED_RES_OK);
    }
    
}



#endif /*__AMRWB_LINK_SUPPORT__*/

#ifdef __AUDIO_AT_CMD__
/*****************************************************************************
 * FUNCTION
 *  aud_set_pcm_info_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_speech_info_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_speech_info_req_struct *req_p = NULL;
	audio_speech_info_struct *speech_info;
	kal_bool state;
	kal_uint8 bclk;
	kal_uint8 sync_type;
	kal_bool AEC_state;
	kal_bool DLNR_state;
	kal_bool ULNR_state;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_aud_set_speech_info_req_struct*) ilm_ptr->local_para_ptr;
	if(req_p == NULL)
	{
		return ;
	}

	speech_info = &req_p->speech_info;
	if(med_context_p->nvram_state == MED_POWERON_READING_NVRAM_FINISH)
	{
		aud_context_p->src_mod = ilm_ptr->src_mod_id;
	
		aud_send_msg_to_nvram(
			MSG_ID_NVRAM_WRITE_REQ,
			NVRAM_EF_AUDIO_AT_SPEECH_INFO_LID,
			&(req_p->speech_info),
			sizeof(audio_speech_info_struct));
	}
	
}

#endif
/*****************************************************************************
 * FUNCTION
 *  aud_get_volume_gain
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [IN]        
 *  type        [IN]        
 *  level       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 aud_get_volume_gain(kal_uint8 mode, kal_uint8 type, kal_uint8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 apply_level = level;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Check if it should be muted at level 0 */
    if (level & 0x40)
    {
        /* Mute at level 0 */
        if (level & 0x3F == 0)
        {
            return 0;
        }

        /* Decrease one level for the actually applied level */
        apply_level = (level & 0x3F) - 1;
    }

#if defined(TV_OUT_SUPPORT)
    if (type == AUD_VOLUME_TVO)
    {
        if (apply_level >= MAX_VOL_LEVEL)
        {
            return 0;
        }
        else
        {
            return aud_context_p->acoustic_data.tv_out_volume_gain[apply_level];
        }
    }
#endif /* TV_OUT_SUPPORT */

    /* Validate index */
    if ((mode >= MAX_VOL_CATE) || (type >= MAX_VOL_TYPE) || (apply_level >= MAX_VOL_LEVEL))
    {
        return 0;
    }

    return aud_context_p->acoustic_data.volume_gain[mode][type][apply_level];
}


/*****************************************************************************
 * FUNCTION
 *  aud_get_volume_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [IN]        
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 aud_get_volume_level(kal_uint8 mode, kal_uint8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mode >= MAX_VOL_CATE) || (type >= MAX_VOL_TYPE))
    {
        return 0;
    }
    
#ifndef __GAIN_TABLE_SUPPORT__
    return aud_context_p->acoustic_data.volume[mode][type];
#else
    return MED_AUD_VOL_GET_VOLUME_LEVEL(aud_context_p->volume_tbl[type]);
#endif /* __GAIN_TABLE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  aud_is_set_melody_path_volume_by_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool aud_is_set_melody_path_volume_by_bt(kal_uint8 check_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MED_BT_A2DP_MOD__
    if(check_mode == AUD_MEDIA_PATH_BT_A2DP || check_mode == AUD_MEDIA_PATH_BT_BOTH)
    {
    #if defined(__BTMTK__)
        if (aud_bt_a2dp_is_mute_phone())
    #endif
        {
            return KAL_TRUE;
        }
    }
#endif

#if defined(__MED_BT_HFP_MOD__) && defined(__MED_BT_AUDIO_VIA_SCO__)
    if(check_mode == AUD_MEDIA_PATH_BT_HFP || check_mode == AUD_MEDIA_PATH_BT_BOTH)
    {
        if(aud_bt_hfp_is_audio_path_on())
        {
            return KAL_TRUE;
        }
    }
#endif

    return KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  aud_audio_set_melody_path_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_mode      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_audio_set_melody_path_volume(kal_uint8 audio_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 audio_path = 0;    
    kal_uint8 gain_audio_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_AUDIO_SET_MELODY_PATH_VOLUME);

    switch (audio_mode)
    {
        /*------------------ Normal Mode & Loud Speaker Mode ---------------------*/
        case AUD_MODE_NORMAL:
        case AUD_MODE_LOUDSPK:
        #if defined(AUDIO_COMPENSATION_ENABLE) || defined(__AUDIO_COMPENSATION_SW_VERSION__)
            /* Update compensation filter */
            if (aud_context_p->loudness_on)
            {
                Media_SelectAudioCompensation(MEDIA_AUD_COMP_LOUDSPEAKER_RINGTONE);
            }
            else
            {
                Media_SelectAudioCompensation(MEDIA_AUD_COMP_LOUDSPEAKER);
            }
        #endif /* AUDIO_COMPENSATION_ENABLE || __AUDIO_COMPENSATION_SW_VERSION__ */
        
            /* Set media path */
            if (!aud_is_set_melody_path_volume_by_bt(AUD_MEDIA_PATH_BT_BOTH))
            {
            #if defined(TV_OUT_SUPPORT)
                if (audio_tv_cable_in)
                {
                    if(audio_tv_loud_speaker)  /* Set output path to both TV out and mobile device */
                    {
                        audio_path = AUDIO_DEVICE_SPEAKER_BOTH;
                    }
                    else  /* Set output path to earphone to let it play through TV only. */
                    {
                        audio_path = AUDIO_DEVICE_SPEAKER2;
                    }
                }
                else
            #endif /* TV_OUT_SUPPORT */
                {
                    audio_path = AUDIO_DEVICE_LOUDSPEAKER;
                }
                aud_melody_set_output_device(custom_cfg_hw_aud_output_path(audio_path));                
            }
            
    #ifndef __GAIN_TABLE_SUPPORT__        
            /* Set media volume, use playing melody volume level */
        #if defined(TV_OUT_SUPPORT)
            if (audio_tv_cable_in &&   /* TV out is on, and audio output to TV only */
                !audio_tv_loud_speaker &&
                aud_context_p->melody_output_device != AUDIO_DEVICE_SPEAKER_BOTH)
            {
                gain_audio_mode = VOL_TV_OUT;
            }
            else
        #endif /* TV_OUT_SUPPORT */
            {
                if (audio_mode == AUD_MODE_NORMAL)
                {
                    gain_audio_mode = VOL_NORMAL;
                }
                else /* AUD_MODE_LOUDSPK */
                {
                    gain_audio_mode = VOL_HANDFREE;
                }
            }

            if(!aud_context_p->audio_mute)
            {
                aud_melody_set_volume_by_mode(gain_audio_mode, current_playing_melody_volume_level);
            }
    #endif /* __GAIN_TABLE_SUPPORT__ */
    
            break;
           
        /*---------------------- Headset Mode -----------------------*/
        case AUD_MODE_HEADSET:
        #if defined(AUDIO_COMPENSATION_ENABLE) || defined(__AUDIO_COMPENSATION_SW_VERSION__)
            /* Update compensation filter */
            Media_SelectAudioCompensation(MEDIA_AUD_COMP_EARPHONE);
        #endif /* AUDIO_COMPENSATION_ENABLE || __AUDIO_COMPENSATION_SW_VERSION__ */
        
            /* Set media path */
            if (!aud_is_set_melody_path_volume_by_bt(AUD_MEDIA_PATH_BT_BOTH))
            {
                aud_melody_set_output_device(custom_cfg_hw_aud_output_path(aud_context_p->melody_output_device));
            }
    #ifndef __GAIN_TABLE_SUPPORT__
            /* if it's headset mode and output to both earphone & loud speaker, use normal mode gain value */

            if (aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
            {
                gain_audio_mode = VOL_NORMAL;
            }
            else
            {
                gain_audio_mode = VOL_HEADSET;
            }

            if(!aud_context_p->audio_mute)
            {
                aud_melody_set_volume_by_mode(gain_audio_mode, current_playing_melody_volume_level);
            }
    #endif /* __GAIN_TABLE_SUPPORT__ */
    
            break;

        default:
            ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_is_using_fmr_source
 * DESCRIPTION
 *  This function is to check if the FM Radio source is being used.
 * PARAMETERS
 *  void
 * RETURNS
 *  KAL_TRUE    FMR source is being used.
 *  KAL_FALSE   FMR source is not used.
 *****************************************************************************/
static kal_bool aud_is_using_fmr_source(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_using_fmr = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* For FM record, not use default input device during record phase, so don't apply input path right away */
    if ((AUD_IN_STATE(AUD_MEDIA_RECORD) || AUD_IN_STATE(AUD_MEDIA_RECORD_PAUSED) || AUD_IN_STATE(AUD_MEDIA_WAIT_RECORD)) 
        && (aud_fmr_is_power_on()))
    {
        is_using_fmr = KAL_TRUE;
    }

#if defined(__MED_BT_HFP_MOD__) && defined(__MED_BT_FM_VIA_SCO__)
    if (aud_bt_hfp_is_audio_path_on())
    {
        is_using_fmr = KAL_TRUE;
    }
#endif

    return is_using_fmr;

}


/*****************************************************************************
 * FUNCTION
 *  aud_audio_set_fmrdo_path_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_mode      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_audio_set_fmrdo_path_volume(kal_uint8 audio_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 audio_path = 0;
    kal_uint8 gain_audio_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_AUDIO_SET_FMRDO_PATH_VOLUME);

    if (!aud_fmr_is_power_on())
    {
        /* Directly return if FMR is off. This is important because the FM I2S may
         * incorrectly update the volume of media path when audio mode is changed.
         */
        return;
    }
    
    switch (audio_mode)
    {
        /*------------------ Normal Mode & Loud Speaker Mode ---------------------*/
        case AUD_MODE_NORMAL:
        case AUD_MODE_LOUDSPK:

            /* Set FM Radio path */
            if(!aud_is_set_melody_path_volume_by_bt(AUD_MEDIA_PATH_BT_BOTH))
            {
            #if defined(TV_OUT_SUPPORT)
                if (audio_tv_cable_in)
                {
                    if(audio_tv_loud_speaker)  /* Set output path to both TV out and mobile device */
                    {
                        audio_path = AUDIO_DEVICE_SPEAKER_BOTH;
                    }
                    else  /* Set output path to earphone to let it play through TV only. */
                    {
                        audio_path = AUDIO_DEVICE_SPEAKER2;
                    }            
                }
                else
            #endif /* TV_OUT_SUPPORT */
                {
                    audio_path = AUDIO_DEVICE_LOUDSPEAKER;
                }
                aud_fmr_set_output_device(custom_cfg_hw_aud_output_path(audio_path));
            }

        #ifndef __GAIN_TABLE_SUPPORT__
            /* Set FM radio volume */
        #if defined(TV_OUT_SUPPORT)
            if (audio_tv_cable_in &&   /* TV out is on, and audio output to TV only */
                !audio_tv_loud_speaker &&
                aud_context_p->melody_output_device != AUDIO_DEVICE_SPEAKER_BOTH)
            {
                gain_audio_mode = VOL_TV_OUT;
            }
            else
        #endif /* TV_OUT_SUPPORT */
            {
                if(audio_mode == AUD_MODE_NORMAL)
                {
                    gain_audio_mode = VOL_NORMAL;
                }
                else
                {
                    gain_audio_mode = VOL_HANDFREE;
                }
            }
   
            if(!aud_context_p->audio_mute)
            {
                aud_fmr_set_volume_by_mode(gain_audio_mode, current_playing_melody_volume_level);
                //aud_fmr_set_volume_by_mode(gain_audio_mode, current_playing_fmradio_volume_level);
            }
        #endif /* __GAIN_TABLE_SUPPORT__ */
        
            break;
           
        /*---------------------- Headset Mode -----------------------*/
        case AUD_MODE_HEADSET:
            if(!aud_is_set_melody_path_volume_by_bt(AUD_MEDIA_PATH_BT_BOTH))
            {
                aud_fmr_set_output_device(custom_cfg_hw_aud_output_path(aud_context_p->melody_output_device));
            }

        #ifndef __GAIN_TABLE_SUPPORT__
            /* if it's headset mode and output to both earphone & loud speaker, use normal mode gain value */

            if (aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
            {
                gain_audio_mode = VOL_NORMAL;
            }
            else
            {
                gain_audio_mode = VOL_HEADSET;
            }

            /* set fm radio volume, use playing fm radio volume level */
            if(!aud_context_p->audio_mute)
            {
                aud_fmr_set_volume_by_mode(gain_audio_mode, current_playing_melody_volume_level);
                //aud_fmr_set_volume_by_mode(gain_audio_mode, current_playing_fmradio_volume_level);
            }
        #endif /* __GAIN_TABLE_SUPPORT__ */

            break;

        default:
            ASSERT(0);
            break;
    }
}

#ifdef __ATV_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  aud_audio_set_atv_path_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_mode      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_audio_set_atv_path_volume(kal_uint8 audio_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 audio_path = 0;    
    kal_uint8 gain_audio_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_AUDIO_SET_ATV_PATH_VOLUME);

    switch (audio_mode)
    {
        /*------------------ Normal Mode & Loud Speaker Mode ---------------------*/
        case AUD_MODE_NORMAL:
        case AUD_MODE_LOUDSPK:
            /* Set media path */
            if (!aud_is_set_melody_path_volume_by_bt(AUD_MEDIA_PATH_BT_BOTH))
            {
        #if defined(TV_OUT_SUPPORT)
                if (audio_tv_cable_in)
                {
                    if(audio_tv_loud_speaker)  /* Set output path to both TV out and mobile device */
                    {
                        audio_path = AUDIO_DEVICE_SPEAKER_BOTH;
                    }
                    else  /* Set output path to earphone to let it play through TV only. */
                    {
                        audio_path = AUDIO_DEVICE_SPEAKER2;
                    }
                }
                else
        #endif /* TV_OUT_SUPPORT */
                {
                    audio_path = AUDIO_DEVICE_LOUDSPEAKER;
                }
                aud_atv_set_output_device(custom_cfg_hw_aud_output_path(audio_path));                
            }
            
   #ifndef __GAIN_TABLE_SUPPORT__     
            /* Set media volume, use playing melody volume level */
        #if defined(TV_OUT_SUPPORT)
            if (audio_tv_cable_in &&   /* TV out is on, and audio output to TV only */
                !audio_tv_loud_speaker &&
                aud_context_p->melody_output_device != AUDIO_DEVICE_SPEAKER_BOTH)
            {
                gain_audio_mode = VOL_TV_OUT;
            }
            else
        #endif /* TV_OUT_SUPPORT */
            {
                if (audio_mode == AUD_MODE_NORMAL)
                {
                    gain_audio_mode = VOL_NORMAL;
                }
                else /* AUD_MODE_LOUDSPK */
                {
                    gain_audio_mode = VOL_HANDFREE;
                }
            }

            if(!aud_context_p->audio_mute)
            {
                aud_atv_set_volume_by_mode(gain_audio_mode, current_playing_melody_volume_level);
            }
    #endif /* __GAIN_TABLE_SUPPORT__ */
    
            break;
           
        /*---------------------- Headset Mode -----------------------*/
        case AUD_MODE_HEADSET:
            /* Set media path */
            if (!aud_is_set_melody_path_volume_by_bt(AUD_MEDIA_PATH_BT_BOTH))
            {
                aud_atv_set_output_device(custom_cfg_hw_aud_output_path(aud_context_p->melody_output_device));
            }

    #ifndef __GAIN_TABLE_SUPPORT__
            /* if it's headset mode and output to both earphone & loud speaker, use normal mode gain value */

            if (aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
            {
                gain_audio_mode = VOL_NORMAL;
            }
            else
            {
                gain_audio_mode = VOL_HEADSET;
            }

            if(!aud_context_p->audio_mute)
            {
                aud_atv_set_volume_by_mode(gain_audio_mode, current_playing_melody_volume_level);
            }
    #endif /* __GAIN_TABLE_SUPPORT__ */
        
            break;

        default:
            ASSERT(0);
            break;
    }
}
#endif /* __ATV_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  aud_get_active_audio_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 aud_get_active_audio_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return aud_context_p->audio_mode;
}

/*****************************************************************************
 * FUNCTION
 *  _aud_apply_path_and_volume_by_mode
 * DESCRIPTION
 *  to apply path and volume by mode
 * PARAMETERS
 *  audio_mode      [IN]
 *  speech_mode     [IN]
 *  speech_volume_level     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void _aud_apply_path_and_volume_by_mode(kal_uint8 audio_mode, kal_uint8 speech_mode, kal_uint8 speech_volume_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 speaker_id, device_speaker_id;
#ifdef __MED_SND_MOD__
    kal_uint8 snd_speaker_id, device_snd_speaker_id;
#endif
    kal_uint8 mic_id, device_mic_id;

    kal_uint8 volume_mode;
    kal_uint8 volume;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(audio_mode)
    {
        case AUD_MODE_NORMAL:
        {
            speaker_id = AUDIO_DEVICE_SPEAKER;
        #ifdef __MED_SND_MOD__
            snd_speaker_id = AUDIO_DEVICE_LOUDSPEAKER;
        #endif
            mic_id = AUDIO_DEVICE_MIC1;
            volume_mode = VOL_NORMAL;
            break;
        }

        case AUD_MODE_HEADSET:
        {
            speaker_id = AUDIO_DEVICE_SPEAKER2;
        #ifdef __MED_SND_MOD__
            snd_speaker_id = aud_context_p->melody_output_device;
        #endif
			#if defined(__MTK_TARGET__)
           	#if defined(__ACCDET_SUPPORT__)
            if(!ACCDET_Is_Earphone_With_MIC())
            {
                mic_id = AUDIO_DEVICE_MIC1;
            }
            else
			#endif 
            {
                mic_id = AUDIO_DEVICE_MIC2;
            }
			#else
			mic_id = AUDIO_DEVICE_MIC2;
			#endif
			
            volume_mode = VOL_HEADSET;
#if defined( __GPS_TRACK__)//wangqi20150818
            kal_prompt_trace(2,"_aud_apply_path_and_volume_by_mode()=======MIC1");
            mic_id = AUDIO_DEVICE_MIC1;
#endif /* __GPS_TRACK__ */

			
            break;
        }

        case AUD_MODE_LOUDSPK:
        {
            speaker_id = AUDIO_DEVICE_LOUDSPEAKER;
        #ifdef __MED_SND_MOD__
            snd_speaker_id = AUDIO_DEVICE_LOUDSPEAKER;
        #endif
            mic_id = AUDIO_DEVICE_MIC3;
            volume_mode = VOL_HANDFREE;
            break;
        }

        default:
            return;
    }

    device_speaker_id = custom_cfg_hw_aud_output_path(speaker_id);
#ifdef __MED_SND_MOD__
    device_snd_speaker_id = custom_cfg_hw_aud_output_path(snd_speaker_id);
#endif
    device_mic_id = custom_cfg_hw_aud_input_path(mic_id);


    /* Set output device */
#ifndef __MED_CTM_MOD__
#if defined( __MED_BT_HFP_MOD__) || defined(__MED_BT_HF_MOD__)
    if (!aud_bt_hfp_is_audio_path_on())
#endif        
    {
       aud_speech_set_output_device(device_speaker_id);
    }
#endif /* #ifndef __MED_CTM_MOD__ */

#if defined( __MED_BT_HFP_MOD__) || defined(__MED_BT_HF_MOD__)
    if (!aud_bt_hfp_is_audio_path_on() || audio_mode == AUD_MODE_HEADSET)
#endif
    {
        aud_keytone_set_output_device(device_speaker_id);
        aud_tone_set_output_device(device_speaker_id);
    }

#ifdef __MED_SND_MOD__
    aud_snd_set_output_device(device_snd_speaker_id);
#endif /* __MED_SND_MOD__ */

    /* Should not change input source if FMR source is being used */
    if (aud_is_using_fmr_source())
    {
        aud_mic_set_device_no_apply(device_mic_id);
    }
    else
    {
    #ifndef __MED_CTM_MOD__
        aud_mic_set_device(device_mic_id);
    #endif 
    }

#ifndef __GAIN_TABLE_SUPPORT__
#ifndef __MED_CTM_MOD__
    /* set mic volume */
    if(!aud_context_p->audio_mute)
    {
        volume = aud_get_volume_gain(volume_mode, AUD_VOLUME_MIC, aud_get_volume_level(volume_mode, AUD_VOLUME_MIC));
        aud_mic_set_volume(volume, volume);
    }
#endif /* __MED_CTM_MOD__ */ 
    /* set speech volume */
    volume = aud_get_volume_gain(volume_mode, AUD_VOLUME_SPH, speech_volume_level);
#ifndef __MED_CTM_MOD__
    aud_speech_set_output_volume(volume, 0);
#endif 
    aud_speech_set_volume_level_param(speech_volume_level, speech_mode);
    /* set general tone volume, use keypad tone volume level */
    if (!aud_context_p->speech_on)
    {
        volume = aud_get_volume_gain(volume_mode, AUD_VOLUME_CTN, aud_get_volume_level(volume_mode, AUD_VOLUME_KEY));
    }
    aud_tone_set_output_volume(volume, 0);
    /* set key tone volume */
    volume = aud_get_volume_gain(volume_mode, AUD_VOLUME_KEY, aud_get_volume_level(volume_mode, AUD_VOLUME_KEY));
    aud_keytone_set_output_volume(volume, 0);
    /* set loopback volume */
    volume = aud_get_volume_gain(volume_mode, AUD_VOLUME_SID, aud_get_volume_level(volume_mode, AUD_VOLUME_SID));
    aud_side_tone_set_volume(volume, 0);
#endif /* __GAIN_TABLE_SUPPORT__ */

}


/*****************************************************************************
 * FUNCTION
 *  aud_set_aud_path_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_mode      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_aud_path_volume(kal_uint8 audio_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_mute;
    kal_uint8 speech_mode;
    kal_uint8 speech_volume_level;
#ifdef __MED_CTM_MOD__
    kal_bool need_protect = KAL_FALSE;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* To avoid noise when changing audio mode */
    if(aud_context_p->speech_on)
    {
    #ifdef __MED_CTM_MOD__
        if (aud_ctm_is_tty_on())
        {
            /* When TTY is on, don't turn off speech/microphone */
            need_protect = KAL_TRUE;
            L1Ctm_Close();
        }
    #endif
    
        /* Store mute state because the mute flag will be cleared when speech is off */
        is_mute = L1SP_IsMicrophoneMuted();
        L1SP_Speech_Off();
        kal_sleep_task(5);
        L1SP_MuteMicrophone(is_mute);
    }

#ifndef __GAIN_TABLE_SUPPORT__

    speech_mode = aud_speech_get_param_mode(audio_mode);
    speech_volume_level = aud_get_volume_level(audio_mode, AUD_VOLUME_SPH);

	/*when  use 2in1 speaker  and btdialer ,it will cause BT call loudspeaker mode have no sound so first set device*/
	#ifdef __BT_DIALER_SUPPORT__ 
		_aud_apply_path_and_volume_by_mode(audio_mode, speech_mode, speech_volume_level);
	#endif

    /* Special handle for volume and path in CTM mode */
#ifdef __MED_CTM_MOD__
    aud_ctm_set_speech_vol_and_path(audio_mode);
#else
    /* Set speech FIR coefficient */
    aud_speech_set_fir_index_by_mode(audio_mode);
#endif /* __MED_CTM_MOD__ */

#else /* #ifdef __GAIN_TABLE_SUPPORT */

    /* Special handle for volume and path in CTM mode */
#ifdef __MED_CTM_MOD__
    aud_ctm_set_speech_vol_and_path(audio_mode);
#endif /* __MED_CTM_MOD__ */

#endif /* __GAIN_TABLE_SUPPORT__*/

    /* Set output path and volume for melody and FM radio */
    aud_audio_set_melody_path_volume(audio_mode);
#ifdef __ATV_SUPPORT__
    aud_audio_set_atv_path_volume(audio_mode);
#endif
    aud_audio_set_fmrdo_path_volume(audio_mode);

    _aud_apply_path_and_volume_by_mode(audio_mode, speech_mode, speech_volume_level);

    /* Restore speech state */
    if(aud_context_p->speech_on)
    {
        L1SP_Speech_On(aud_context_p->rat_mode);
    #ifdef __MED_CTM_MOD__
        if (need_protect)
        {
            aud_ctm_resume();
        }
    #endif
    }
}


#if defined(TV_OUT_SUPPORT)
/*****************************************************************************
 * FUNCTION
 *  aud_set_tv_out_aud_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tv_on       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_tv_out_aud_path(kal_uint8 tv_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 gain_audio_mode;
    kal_uint8 output_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    AUD_FUNC_ENTRY(AUD_SET_TV_OUT_AUD_PATH);
    AUD_VALUE_TRACE(tv_on, aud_context_p->audio_mode, audio_tv_cable_in);

    if(audio_tv_cable_in == tv_on)
    {
        return;
    }

    /* No need to change in headset mode when TV out enable/disable */
    if (aud_context_p->audio_mode == AUD_MODE_NORMAL || aud_context_p->audio_mode == AUD_MODE_LOUDSPK)
    {
        /* TV cable in*/
        if (tv_on)
        {
            /* Get hardware audio output path setting parameter. */
            if(audio_tv_loud_speaker ||
               aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
            {
                output_path = custom_cfg_hw_aud_output_path(AUDIO_DEVICE_SPEAKER_BOTH);
            }
            else /* Set output path to earphone to avoid hear sound from handset */
            {
                output_path = custom_cfg_hw_aud_output_path(AUDIO_DEVICE_SPEAKER2);
            }

            /* Melody */
            if (!aud_is_set_melody_path_volume_by_bt(AUD_MEDIA_PATH_BT_BOTH))
            {
                aud_melody_set_output_device(output_path);
            }

            /* FM Radio */
        #if defined(__MED_BT_HFP_MOD__) && defined(__MED_BT_FM_VIA_SCO__)
            if(!aud_bt_hfp_is_audio_path_on())            
        #endif
            {
                aud_fmr_set_output_device(output_path);
            }

            /* Background Sound Effect */
        #ifdef __MED_SND_MOD__
            aud_snd_set_output_device(output_path);
        #endif

        #ifndef __GAIN_TABLE_SUPPORT__
            /* Set volume by using TV out gain value */
            if(!aud_context_p->audio_mute)
            {
                /* Melody */
                if(audio_tv_loud_speaker ||
                   aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
                {
                    aud_melody_set_volume_by_mode(aud_context_p->audio_mode, current_playing_melody_volume_level);
                }
                else
                {
                    aud_melody_set_volume_by_mode(VOL_TV_OUT, current_playing_melody_volume_level);
                }            

                /* FM Radio */
                if(audio_tv_loud_speaker ||
                   aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
                {
                    aud_fmr_set_volume_by_mode(aud_context_p->audio_mode, current_playing_melody_volume_level);
                    //aud_fmr_set_volume_by_mode(aud_context_p->audio_mode, current_playing_fmradio_volume_level);
                }
                else
                {
                    aud_fmr_set_volume_by_mode(VOL_TV_OUT, current_playing_melody_volume_level);
                    //aud_fmr_set_volume_by_mode(VOL_TV_OUT, current_playing_fmradio_volume_level);
                }
            }
        #endif /* __GAIN_TABLE_SUPPORT__ */

        #ifdef __GAIN_TABLE_SUPPORT__
            /* Notify MMI that TV-OUT is on */
            aud_send_state_change_ind(AUD_STATE_CHANGE_TV_OUT_PLUG_IN, NULL);
        #endif
        }
        /* TV cable out*/
        else
        {
            /* Set output path back to load speaker for melody and FM radio */
            output_path = custom_cfg_hw_aud_output_path(AUDIO_DEVICE_LOUDSPEAKER);

            /* Melody */
            if (!aud_is_set_melody_path_volume_by_bt(AUD_MEDIA_PATH_BT_BOTH))
            {
                aud_melody_set_output_device(output_path);
            }

            /* FM Radio */
        #if defined(__MED_BT_HFP_MOD__) && defined(__MED_BT_FM_VIA_SCO__)
            if(!aud_bt_hfp_is_audio_path_on())
        #endif
            {
                aud_fmr_set_output_device(output_path);
            }

            /* Background Sound Effect */
        #ifdef __MED_SND_MOD__
            aud_snd_set_output_device(output_path);
        #endif

        #ifndef __GAIN_TABLE_SUPPORT__
            /* Set volume by using TV out gain value */
            if(!aud_context_p->audio_mute)
            {
                /* Melody */
                if (aud_context_p->audio_mode == AUD_MODE_NORMAL)
                {
                    gain_audio_mode = VOL_NORMAL;
                }
                else
                {
                    gain_audio_mode = VOL_HANDFREE;
                }
                aud_melody_set_volume_by_mode(gain_audio_mode, current_playing_melody_volume_level);

                /* FM Radio */
                aud_fmr_set_volume_by_mode(gain_audio_mode, current_playing_melody_volume_level);
                //aud_fmr_set_volume_by_mode(gain_audio_mode, current_playing_fmradio_volume_level);
            }

            /* Notify MMI that TV-OUT is off */
            aud_send_state_change_ind(AUD_STATE_CHANGE_TV_OUT_PLUG_OUT, NULL);
        #endif /*__GAIN_TABLE_SUPPORT__*/
        }
    }

    /* Change TV out status for audio path */
    if (tv_on)
    {
        audio_tv_cable_in = KAL_TRUE;
    }
    else
    {
        audio_tv_cable_in = KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_set_tv_out_param
 * DESCRIPTION
 *  
 * PARAMETERS
 *  enable_loud_spk       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_tv_out_param(kal_uint8 enable_loud_spk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool change_path = KAL_FALSE;
    kal_uint8 output_path = 0;
    kal_uint8 volume;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    AUD_FUNC_ENTRY(AUD_SET_TV_OUT_PARAM);
    AUD_VALUE2_TRACE(enable_loud_spk, audio_tv_loud_speaker);

    /* Check if we need to change audio path when change tv-out audio setting */
    if(enable_loud_spk != audio_tv_loud_speaker)
    {
        change_path = KAL_TRUE;
    }

    if(enable_loud_spk)
    {
        audio_tv_loud_speaker = KAL_TRUE;
    }
    else
    {
        audio_tv_loud_speaker = KAL_FALSE;
    }

    /* Change audio path right away if TV cable in */
    if(change_path &&
       audio_tv_cable_in &&
       (aud_context_p->audio_mode == AUD_MODE_NORMAL || aud_context_p->audio_mode == AUD_MODE_LOUDSPK))
    {
        /* Get hardware audio output path setting parameter. */
        if(audio_tv_loud_speaker)
        {
            output_path = custom_cfg_hw_aud_output_path(AUDIO_DEVICE_SPEAKER_BOTH);
        }
        else /* Set output path to earphone to avoid hear sound from handset */
        {
            output_path = custom_cfg_hw_aud_output_path(AUDIO_DEVICE_SPEAKER2);
        }
    
        /* Melody */
        if (!aud_is_set_melody_path_volume_by_bt(AUD_MEDIA_PATH_BT_BOTH))
        {
            aud_melody_set_output_device(output_path);
        }

        /* FM Radio */
    #if defined(__MED_BT_HFP_MOD__) && defined(__MED_BT_FM_VIA_SCO__)
        if(!aud_bt_hfp_is_audio_path_on())
    #endif
        {
            aud_fmr_set_output_device(output_path);
        }

        /* Background Sound Effect */
    #ifdef __MED_SND_MOD__
        aud_snd_set_output_device(output_path);
    #endif

    #ifndef __GAIN_TABLE_SUPPORT__
        /* Set volume by using TV out gain value */
        if(!aud_context_p->audio_mute)
        {
            /* Melody */
            if(audio_tv_loud_speaker ||
               aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
            {
                aud_melody_set_volume_by_mode(VOL_NORMAL, current_playing_melody_volume_level);
            }
            else
            {
                aud_melody_set_volume_by_mode(VOL_TV_OUT, current_playing_melody_volume_level);
            }

            /* FM Radio */
            if(audio_tv_loud_speaker ||
               aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
            {
                aud_fmr_set_volume_by_mode(VOL_NORMAL, current_playing_melody_volume_level);
                //aud_fmr_set_volume_by_mode(VOL_NORMAL, current_playing_fmradio_volume_level);
            }
            else
            {
                aud_fmr_set_volume_by_mode(VOL_TV_OUT, current_playing_melody_volume_level);
                //aud_fmr_set_volume_by_mode(VOL_TV_OUT, current_playing_fmradio_volume_level);
            }
        }
    #endif /* __GAIN_TABLE_SUPPORT__ */
    }
}
#endif /* TV_OUT_SUPPORT */

/*****************************************************************************
 * FUNCTION
 *  aud_audio_set_device_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_audio_set_device_req_hdlr(ilm_struct *ilm_ptr)
{
#ifdef DUMMY_CNF
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 cnf_msg_id;
    void *cnf_p = NULL;
#endif /* DUMMY_CNF */ 

    media_aud_set_device_req_struct *req_p;

    aud_set_output_device_handler handler = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_aud_set_device_req_struct*) ilm_ptr->local_para_ptr;

    switch (req_p->audio_type)
    {
        case AUD_TYPE_SPEECH:
            handler = aud_speech_set_output_device;
            break;
        case AUD_TYPE_VM:
        case AUD_TYPE_VR:
            break;
        case AUD_TYPE_TONE:
            handler = aud_tone_set_output_device;
            break;
        case AUD_TYPE_KEYTONE:
            handler = aud_keytone_set_output_device;
            break;
        case AUD_TYPE_MELODY:
            handler = aud_melody_set_output_device;
            break;
        case AUD_TYPE_MIC:
            handler = aud_mic_set_device;
            break;
        case AUD_TYPE_FMR:
            handler = aud_fmr_set_output_device;
            break;
    #ifdef __MED_SND_MOD__
        case AUD_TYPE_BGSND:
            handler = aud_snd_set_output_device;
            break;
    #endif /* __MED_SND_MOD__ */ 
        default:
            break;

    }

    if(handler != NULL)
    {
        handler(req_p->device);
    }

#ifdef DUMMY_CNF
    cnf_p = (media_aud_set_device_cnf_struct*)
        construct_local_para(sizeof(media_aud_set_device_cnf_struct), TD_CTRL);

    cnf_msg_id = MSG_ID_MEDIA_AUD_SET_DEVICE_CNF;

    aud_send_ilm(ilm_ptr->src_mod_id, cnf_msg_id, cnf_p, NULL);
#endif /* DUMMY_CNF */ 
}

/*****************************************************************************
 * FUNCTION
 *  aud_audio_get_volume_in_sync_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_audio_get_volume_in_sync_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_get_volume_req_struct *req_p;
    kal_int32 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_aud_get_volume_req_struct*) ilm_ptr->local_para_ptr;

#ifndef __GAIN_TABLE_SUPPORT__
    result = aud_context_p->acoustic_data.volume[aud_context_p->audio_mode][req_p->volume_type];
#else
    result = MED_AUD_VOL_GET_VOLUME_LEVEL(aud_context_p->volume_tbl[req_p->volume_type]);
#endif /* __GAIN_TABLE_SUPPORT__ */

    aud_set_result_and_event(result,AUD_EVT_GET_VOLUME);

}


/*****************************************************************************
 * FUNCTION
 *  aud_audio_get_volume_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_audio_get_volume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_get_volume_req_struct *req_p;
    media_aud_get_volume_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_aud_get_volume_req_struct*) ilm_ptr->local_para_ptr;

    cnf_p = (media_aud_get_volume_cnf_struct*) construct_local_para(sizeof(media_aud_get_volume_cnf_struct), TD_CTRL);

    cnf_p->src_id = req_p->src_id;
    cnf_p->volume_type = req_p->volume_type;
    cnf_p->result = KAL_TRUE;
#ifndef __GAIN_TABLE_SUPPORT__
    cnf_p->volume = aud_context_p->acoustic_data.volume[aud_context_p->audio_mode][req_p->volume_type];
#else
    cnf_p->volume = MED_AUD_VOL_GET_VOLUME_LEVEL(aud_context_p->volume_tbl[req_p->volume_type]);
#endif /* __GAIN_TABLE_SUPPORT__ */

    aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_MEDIA_AUD_GET_VOLUME_CNF, cnf_p, NULL);
}

#ifdef __GAIN_TABLE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  aud_audio_update_volume_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_audio_update_volume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_volume_update_volume_req_hdlr(ilm_ptr);
}
#endif /* __GAIN_TABLE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  aud_audio_set_volume_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_audio_set_volume_req_hdlr(ilm_struct *ilm_ptr)
{
#ifndef __GAIN_TABLE_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef DUMMY_CNF
    media_aud_set_volume_cnf_struct *cnf_p = NULL;
#endif 
    kal_uint8 volume;
    kal_uint8 audio_type;
    kal_uint8 speech_mode;

    media_aud_set_volume_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_aud_set_volume_req_struct*) ilm_ptr->local_para_ptr;

    /* Treat ATV volume type as MEDIA volume type */
    audio_type = (req_p->audio_type == AUD_VOLUME_ATV) ? AUD_VOLUME_MEDIA : req_p->audio_type;
    
    aud_context_p->acoustic_data.volume[AUD_MODE_NORMAL][audio_type] = req_p->volume;
    aud_context_p->acoustic_data.volume[AUD_MODE_HEADSET][audio_type] = req_p->volume;
    aud_context_p->acoustic_data.volume[AUD_MODE_LOUDSPK][audio_type] = req_p->volume;

    /* get volume gain from table */
    volume = aud_get_volume_gain(aud_context_p->audio_mode, audio_type, req_p->volume);

    /* call the corresponding handler */
    switch (req_p->audio_type)
    {
        case AUD_VOLUME_SPH:
            /* Use speech volume as tone volume when in-call */
            if (aud_context_p->speech_on)
            {
                aud_tone_set_output_volume(volume, 0);

			#if defined( __MED_BT_HFP_MOD__) || defined(__MED_BT_HF_MOD__)
                if (volume == 0)
                {
                    BT_MuteSpeaker(KAL_TRUE);
                }
                else
                {
                    BT_MuteSpeaker(KAL_FALSE);
                }
            #endif

            }
            aud_speech_set_output_volume(volume, 0);
            speech_mode = aud_speech_get_param_mode(aud_context_p->audio_mode);
            aud_speech_set_volume_level_param(req_p->volume, speech_mode);
            break;

        case AUD_VOLUME_KEY:
            /* set keytone volume */
            aud_keytone_set_output_volume(volume, 0);
            
            /* set general tone volume, use key tone volume level */
            if (!aud_context_p->speech_on)
            {
                volume = aud_get_volume_gain(aud_context_p->audio_mode, AUD_VOLUME_CTN, req_p->volume);
                aud_tone_set_output_volume(volume, 0);
            }
            break;
        case AUD_VOLUME_FMR:
            /* if it's headset mode and output to both earphone & loud speaker, use normal mode gain value */
            if (aud_context_p->audio_mode == AUD_MODE_HEADSET &&
                aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
            {
                aud_fmr_set_volume_by_mode(AUD_MODE_NORMAL, req_p->volume);
            }
        #if defined(TV_OUT_SUPPORT)
            else if (audio_tv_cable_in  &&  /* TV out is on, and audio output to TV only */
                    !audio_tv_loud_speaker &&
                    aud_context_p->melody_output_device != AUDIO_DEVICE_SPEAKER_BOTH)
            {
                aud_fmr_set_volume_by_mode(VOL_TV_OUT, req_p->volume);
            }
        #endif /* TV_OUT_SUPPORT */
            else
            {
                aud_fmr_set_volume_by_mode(aud_context_p->audio_mode, req_p->volume);
            }

            current_playing_melody_volume_level = req_p->volume;
            //current_playing_fmradio_volume_level = req_p->volume;

            /* disable audio mute when the volume is set again */
            aud_context_p->audio_mute = KAL_FALSE;
            break;
        case AUD_VOLUME_MEDIA:
            if (req_p->apply)
            {            
        #ifdef __MED_VID_DEC_MOD__
                if (vid_is_dummy_aud_playing() == KAL_FALSE)
        #endif /* __MED_VID_DEC_MOD__ */
                {
                    /* if it's headset mode and output to both earphone & loud speaker, use normal mode gain value */
                    if (aud_context_p->audio_mode == AUD_MODE_HEADSET &&
                        aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
                    {
                        aud_melody_set_volume_by_mode(VOL_NORMAL, req_p->volume);
                    }
                #if defined(TV_OUT_SUPPORT)
                    /* TV out is on, and audio output to TV only */                
                    else if (audio_tv_cable_in  &&
                             !audio_tv_loud_speaker &&
                             aud_context_p->melody_output_device != AUDIO_DEVICE_SPEAKER_BOTH)
                    {
                        aud_melody_set_volume_by_mode(VOL_TV_OUT, req_p->volume);
                    }
                #endif /* TV_OUT_SUPPORT */
                    else
                    {
                        aud_melody_set_volume_by_mode(aud_context_p->audio_mode, req_p->volume);
                    }
                    current_playing_melody_volume_level = req_p->volume;
                }
                
                /* disable audio mute when the volume is set again */
                aud_context_p->audio_mute = KAL_FALSE;
            }
            break;
        case AUD_VOLUME_MIC:
            aud_mic_set_volume(volume, 0);
            
            /* disable audio mute when the volume is set again */
            aud_context_p->audio_mute = KAL_FALSE;
            break;
        case AUD_VOLUME_SID:
            aud_side_tone_set_volume(volume, 0);
            break;
            
    #ifdef __ATV_SUPPORT__
        case AUD_VOLUME_ATV:
            /* if it's headset mode and output to both earphone & loud speaker, use normal mode gain value */
            if (aud_context_p->audio_mode == AUD_MODE_HEADSET &&
                aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
            {
                aud_atv_set_volume_by_mode(VOL_NORMAL, req_p->volume);
            }
        #if defined(TV_OUT_SUPPORT)
            /* TV out is on, and audio output to TV only */                
            else if (audio_tv_cable_in  &&
                     !audio_tv_loud_speaker &&
                     aud_context_p->melody_output_device != AUDIO_DEVICE_SPEAKER_BOTH)
            {
                aud_atv_set_volume_by_mode(VOL_TV_OUT, req_p->volume);
            }
        #endif /* TV_OUT_SUPPORT */
            else
            {
                aud_atv_set_volume_by_mode(aud_context_p->audio_mode, req_p->volume);
            }
            current_playing_melody_volume_level = req_p->volume;

            /* disable audio mute when the volume is set again */
            aud_context_p->audio_mute = KAL_FALSE;
            break;
    #endif /* __ATV_SUPPORT__ */
    
        default:
            break;

    }

    /* Set event to let caller go */
    if (req_p->blocking)
    {
        aud_set_event(AUD_EVT_SET_VOLUME);
    }

#ifdef DUMMY_CNF
    cnf_p = (media_aud_set_volume_cnf_struct*)
        construct_local_para(sizeof(media_aud_set_volume_cnf_struct), TD_CTRL);

    cnf_p->result = MED_RES_OK;

    aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_MEDIA_AUD_SET_VOLUME_CNF, cnf_p, NULL);
#endif /* DUMMY_CNF */ 

    /* Store default volumn level to NVRAM for MODEM project */
#ifdef MED_MODEM
    if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM_FINISH)
    {
        aud_context_p->no_cnf = KAL_TRUE; /* Indicate that the confirm message is not required */
        aud_context_p->src_mod = ilm_ptr->src_mod_id;
        aud_send_msg_to_nvram(
            MSG_ID_NVRAM_WRITE_REQ,
            NVRAM_EF_CUST_ACOUSTIC_DATA_LID,
            &(aud_context_p->acoustic_data),
            sizeof(custom_acoustic_struct));
    }
#endif /* MED_MODEM */

#else /* #ifdef __GAIN_TABLE_SUPPORT__ */
    aud_volume_set_volume_req_hdlr(ilm_ptr);
#endif /* __GAIN_TABLE_SUPPORT */
}

/*****************************************************************************
 * FUNCTION
 *  aud_audio_mute_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_audio_mute_req_hdlr(ilm_struct *ilm_ptr)
{
#ifdef DUMMY_CNF
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 cnf_msg_id;
    void *cnf_p = NULL;
#endif /* DUMMY_CNF */ 

    media_aud_mute_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_aud_mute_req_struct*) ilm_ptr->local_para_ptr;

    switch (req_p->device)
    {
        case AUDIO_DEVICE_MICROPHONE:
            /* call L1AUD to set microphone mute */
            aud_mic_mute(req_p->mute);
            aud_context_p->audio_mute = req_p->mute;
            break;
        default:
            break;
    }

#ifdef DUMMY_CNF
    cnf_p = (media_aud_mute_cnf_struct*) construct_local_para(sizeof(media_aud_mute_cnf_struct), TD_CTRL);

    cnf_msg_id = MSG_ID_MEDIA_AUD_MUTE_CNF;

    aud_send_ilm(ilm_ptr->src_mod_id, cnf_msg_id, cnf_p, NULL);
#endif /* DUMMY_CNF */ 
}

/*****************************************************************************
 * FUNCTION
 *  aud_audio_get_mute_status_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_audio_get_mute_status_req_hdlr(ilm_struct *ilm_ptr){
	media_aud_mute_status_req_struct *req_p; 
	media_aud_get_mute_status_cnf_struct *cnf = NULL;
	kal_uint16 cnf_msg_id;
	
	req_p = (media_aud_mute_status_req_struct*) ilm_ptr->local_para_ptr;
	cnf = (media_aud_get_mute_status_cnf_struct*) construct_local_para(sizeof(media_aud_get_mute_status_cnf_struct), TD_CTRL);
	cnf_msg_id = MSG_ID_GET_MEDIA_MUTE_STATUS_CNF;
	cnf->src_id = req_p->src_id;
	cnf->result = aud_context_p->audio_mute;
	aud_send_ilm(ilm_ptr->src_mod_id, cnf_msg_id, cnf, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  aud_set_mute_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_mute_req_hdlr(ilm_struct *ilm_ptr)
{
#ifndef __GAIN_TABLE_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_mute_req_struct *req_p;
    aud_set_output_volume_handler set_output_vol_hdlr = NULL;
    aud_set_output_volume_by_mode_handler set_vol_by_mode_hdlr = NULL;

    kal_uint8 volume = 0;
    kal_uint8 level = current_playing_melody_volume_level;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_aud_set_mute_req_struct*) ilm_ptr->local_para_ptr;


    aud_context_p->audio_mute = req_p->mute;
    if (req_p->mute)
    {
        switch (req_p->vol_type)
        {
            case AUD_VOLUME_CTN:
                set_output_vol_hdlr = aud_tone_set_output_volume;
                /* if tone is playing, stop it */
                if (aud_context_p->tone_playing)
                {
                    aud_tone_stop();
                }
                break;
            case AUD_VOLUME_KEY:
                set_output_vol_hdlr = aud_keytone_set_output_volume;
                
                /* if keytone is playing, stop it */
                aud_keytone_stop();
                break;
            case AUD_VOLUME_MIC:
                aud_mic_mute(req_p->mute);
                break;
            case AUD_VOLUME_SPH:
                set_output_vol_hdlr = aud_speech_set_output_volume;
                break;
            case AUD_VOLUME_MEDIA:
                set_output_vol_hdlr = aud_melody_set_output_volume;
                break;
            case AUD_VOLUME_FMR:
                set_output_vol_hdlr = aud_fmr_set_output_volume;
                break;
            case AUD_VOLUME_SID:
                break;
        #ifdef __ATV_SUPPORT__
            case AUD_VOLUME_ATV:
                set_output_vol_hdlr = aud_atv_set_output_volume;
                break;
        #endif /* __ATV_SUPPORT__ */
            default:
                break;
        }
    }
    else
    {

        volume = aud_get_volume_gain(
                    aud_context_p->audio_mode,
                    req_p->vol_type,
                    aud_get_volume_level(aud_context_p->audio_mode, req_p->vol_type));
        switch (req_p->vol_type)
        {
            case AUD_VOLUME_CTN:
                set_output_vol_hdlr = aud_tone_set_output_volume;
                break;
            case AUD_VOLUME_KEY:
                set_output_vol_hdlr = aud_keytone_set_output_volume;
                break;
            case AUD_VOLUME_MIC:
                aud_mic_mute(req_p->mute);
                break;
            case AUD_VOLUME_SPH:
                set_output_vol_hdlr = aud_speech_set_output_volume;
                break;
            case AUD_VOLUME_MEDIA:
        #ifdef __MED_VID_DEC_MOD__
            if (vid_is_dummy_aud_playing() == KAL_FALSE)
        #endif /* __MED_VID_DEC_MOD__ */
            {
                set_vol_by_mode_hdlr = aud_melody_set_volume_by_mode;
                break;
            }

            case AUD_VOLUME_FMR:

                set_vol_by_mode_hdlr = aud_fmr_set_volume_by_mode;
                //level = current_playing_fmradio_volume_level;
                break;
            case AUD_VOLUME_SID:
                break;
                
        #ifdef __ATV_SUPPORT__
            case AUD_VOLUME_ATV:

                set_vol_by_mode_hdlr = aud_atv_set_volume_by_mode;
                break;
        #endif /* __ATV_SUPPORT__ */
            default:
                break;
        }
    }

    if(set_output_vol_hdlr != NULL)
    {
        set_output_vol_hdlr(volume, 0);
    }

    if(set_vol_by_mode_hdlr != NULL)
    {
        kal_uint8 mode = aud_context_p->audio_mode;
        
        /* if it's headset mode and output to both earphone & loud speaker, use normal mode gain value */
        if (aud_context_p->audio_mode == AUD_MODE_HEADSET &&
            aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
        {
            mode = VOL_NORMAL;
        }
    #if defined(TV_OUT_SUPPORT)
        /* TV out is on, and audio output to TV only */
        else if (audio_tv_cable_in &&
                 !audio_tv_loud_speaker &&
                 aud_context_p->melody_output_device != AUDIO_DEVICE_SPEAKER_BOTH)
        {
            mode = VOL_TV_OUT;
        }
    #endif

        set_vol_by_mode_hdlr(mode, level);

    }

#else /* #ifdef __GAIN_TABLE_SUPPORT__ */
    aud_volume_set_mute_req_hdlr(ilm_ptr);
#endif /* __GAIN_TABLE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  aud_audio_mute_digital_gain
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void aud_audio_mute_digital_gain(kal_bool set_mute, kal_uint16 mute_app)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY2(AUD_TRC_AUDIO_MUTE_DIGITAL_GAIN, set_mute, g_aud_mute_digital_gain_app);

    /* Only set mute for music volume in idle mode */
    if(aud_context_p->speech_on)
    {
        return;
    }

    if(set_mute)
    {
        g_aud_mute_digital_gain_app |= mute_app;
        Media_MuteSpeaker(KAL_TRUE);
    #if defined(__BT_A2DP_SUPPORT__) || defined(__BT_AUDIO_VIA_SCO__)
        BT_MuteSpeaker(KAL_TRUE);
    #endif 
    }
    else
    {
        g_aud_mute_digital_gain_app &= ~mute_app;
        if(g_aud_mute_digital_gain_app == 0)
        {
            Media_MuteSpeaker(KAL_FALSE);
        #if defined(__BT_A2DP_SUPPORT__) || defined(__BT_AUDIO_VIA_SCO__)
            BT_MuteSpeaker(KAL_FALSE);
        #endif
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_cfg_audio_out_device
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_sound_id      [IN]        
 *  out_device_path     [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_cfg_audio_out_device(kal_uint8 audio_sound_id, kal_uint8 *out_device_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* if there is no change, it will use the default value at PS */
    /* specially for connect tone */
    if ((audio_sound_id == TONE_CALL_CONNECT) || (audio_sound_id == TONE_WARNING2) || (audio_sound_id == TONE_ERROR2))
    {
        switch (aud_context_p->audio_mode)
        {
            case AUD_MODE_NORMAL:
                *out_device_path = AUDIO_DEVICE_SPEAKER;
                break;
            case AUD_MODE_HEADSET:
                *out_device_path = AUDIO_DEVICE_SPEAKER2;
                break;
            default:
                *out_device_path = AUDIO_DEVICE_LOUDSPEAKER;
                break;
        }
    }
    else if (audio_sound_id <= TONE_NEGATIVE_ACK)
    {
        switch (aud_context_p->audio_mode)
        {
            case AUD_MODE_LOUDSPK:
                *out_device_path = AUDIO_DEVICE_LOUDSPEAKER;
                break;
            case AUD_MODE_HEADSET:
                *out_device_path = AUDIO_DEVICE_SPEAKER2;
                break;
            default:
                *out_device_path = AUDIO_DEVICE_SPEAKER;
                break;
        }
    }
    else if ((audio_sound_id > TONE_NEGATIVE_ACK) && (audio_sound_id <= MAX_TONE_ID))
    {
        switch (aud_context_p->audio_mode)
        {
            case AUD_MODE_LOUDSPK:
                *out_device_path = AUDIO_DEVICE_LOUDSPEAKER;
                break;
            case AUD_MODE_HEADSET:
                *out_device_path = AUDIO_DEVICE_SPEAKER2;
                break;
            default:
                /* if speech on, tone shall output via speaker1 */
                if (aud_context_p->speech_on)
                {
                    *out_device_path = AUDIO_DEVICE_SPEAKER;
                }
                else
                {
                    *out_device_path = AUDIO_DEVICE_LOUDSPEAKER;
                }
                break;
        }
    }
    else
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_set_headset_mode_output_path_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_headset_mode_output_path_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_headset_mode_output_path_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_aud_set_headset_mode_output_path_struct*) ilm_ptr->local_para_ptr;

    aud_context_p->melody_output_device = msg_p->device;

#if defined( __MED_BT_HFP_MOD__) || defined(__MED_BT_HF_MOD__)
    if (aud_bt_hfp_is_audio_path_on())
    {
        if(aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
        {
            aud_melody_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_LOUDSPEAKER));            
        }
        else
        {
            aud_melody_set_output_device(0);
        }
        return;
    }
#endif

    if (aud_context_p->audio_mode == AUD_MODE_HEADSET)
    {
        aud_melody_set_output_device(custom_cfg_hw_aud_output_path(msg_p->device));
    }
}

/*****************************************************************************
 * FUNCTION
 *  aud_set_headset_mode_output_path_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_headset_mode_mic_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_headset_mode_mic_struct *msg_p;

#ifndef __MED_CTM_MOD__
    /* headset with mic */
    kal_uint8 mic_device = AUDIO_DEVICE_MIC2;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_aud_set_headset_mode_mic_struct*) ilm_ptr->local_para_ptr;

    if(aud_context_p->audio_mode != AUD_MODE_HEADSET)
    {
        return;
    }
    
#ifdef __MED_CTM_MOD__
    aud_ctm_headset_mode_update_mic(msg_p->with_mic);
#else

    if(!msg_p->with_mic)
    {
        mic_device = AUDIO_DEVICE_MIC1;
    }

    aud_mic_set_device(mic_device);
#endif

}



#ifdef EXT_DAC_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  aud_get_melody_volume_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void aud_get_melody_volume_setting(kal_uint8 mode, kal_uint8 *MaxAnalogGain, kal_uint8 *step)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   *MaxAnalogGain =  aud_context_p->acoustic_data.max_melody_volume_gain[mode];
   *step = aud_context_p->acoustic_data.melody_volume_gain_step[mode];
}
#endif /* EXT_DAC_SUPPORT */

#endif /* MED_NOT_PRESENT */ 

