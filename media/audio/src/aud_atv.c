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
 * aud_atv.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes auduio functions of analog TV.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/******************************************************************
 * MODULE
 *    AUD_TONE
 * DESCRIPTION
 *    This module defines the tone related function for Audio Manager.
 *
 ******************************************************************/

#ifndef MED_NOT_PRESENT
#ifdef __ATV_SUPPORT__
/*-----------------------------------------------------------------------------
                    include files
-----------------------------------------------------------------------------*/
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"     /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"    /* Task creation */
#include "stacklib.h"       /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"     /* Event scheduler */
#include "stack_timer.h"    /* Stack timer */

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "aud_main.h"
#include "med_main.h"
#include "aud_bt_hfp.h"
#include "atv_api.h"
#include "med_utility.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif

/*-----------------------------------------------------------------------------
                    macros, defines, typedefs, enums
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
                    data declaraions
 ----------------------------------------------------------------------------*/
static kal_bool g_is_mute = KAL_FALSE;
static kal_bool g_is_atv_open = KAL_FALSE;
extern kal_uint8 current_playing_melody_volume_level;   /* defined in aud_melody.c */

#ifdef __MM_DCM_SUPPORT__
extern kal_bool bMatv_powerOn;
#endif

/*-----------------------------------------------------------------------------
                    function prototypes
 ----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
                    publie function declarations
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  aud_atv_open
 * DESCRIPTION
 *  This function should be invoked hen ATV is opened.
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
void aud_atv_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Update input device */
#if !defined(__ATV_I2S_SUPPORT__)
    L1SP_SetInputSource(L1SP_LNA_FMRR);
#endif

#if defined(__BTMTK__) && defined(__MED_BT_A2DP_MOD__)
    aud_bt_a2dp_open_codec(MEDIA_FORMAT_UNKNOWN);
#endif

#if defined(__MED_BT_HFP_MOD__)
    /* Update BT SCO mode */
    aud_bt_hfp_set_sco_mode(AUD_BT_HFP_MODE_ATV_VIA_BT_SCO);
#endif

    ATV_AudioOpen();

#ifdef __GAIN_TABLE_SUPPORT__
    /* Notify MMI that ATV is on */
    aud_send_state_change_ind(AUD_STATE_CHANGE_ATV_ON, NULL);
#endif

	g_is_atv_open = KAL_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  aud_atv_close
 * DESCRIPTION
 *  This function should be invoked when ATV is closed.
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
void aud_atv_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

     ATV_AudioClose();

#if defined(__BTMTK__) && defined(__MED_BT_A2DP_MOD__)
    /* stop A2DP codec so that it can be opened again later */
    aud_bt_a2dp_close_codec_for_open();
#endif

#if defined(__MED_BT_HFP_MOD__)
    /* Reset BT SCO mode */
    aud_bt_hfp_reset_sco_mode(AUD_BT_HFP_MODE_ATV_VIA_BT_SCO);
#endif

    /* Restore input device */
#if !defined(__ATV_I2S_SUPPORT__)
    L1SP_SetInputSource(aud_context_p->input_device);
#endif

#ifdef __GAIN_TABLE_SUPPORT__
    /* Notify MMI that ATV is off */
    aud_send_state_change_ind(AUD_STATE_CHANGE_ATV_OFF, NULL);
#endif

	g_is_atv_open = KAL_FALSE;

}

/*****************************************************************************
 * FUNCTION
 *  aud_atv_is_open
 * DESCRIPTION
 *  to query if atv is open
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_bool aud_atv_is_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	return g_is_atv_open;
}


/*****************************************************************************
 * FUNCTION
 *  aud_atv_set_input_device
 * DESCRIPTION
 *  This function sets the input device of ATV. Note that before starting a 
 *  record, the input device should be updated. Otherwise, the ATV path may
 *  not be connected and there will be no sound when recording.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_atv_set_input_device(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__ATV_I2S_SUPPORT__)
    L1SP_SetInputSource(L1SP_LNA_FMRR);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  aud_atv_set_output_device
 * DESCRIPTION
 *  This function sets the output device of ATV.
 * PARAMETERS
 *  device      [IN]        Output device.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_atv_set_output_device(kal_uint8 device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_PATH(AUD_TYPE_ATV, device);

#ifdef __MM_DCM_SUPPORT__
    if(bMatv_powerOn)
#endif        
    {
        ATV_AudioSetOutputDevice(device);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_atv_mute
 * DESCRIPTION
 *  This function is used to mute/unmute the ATV.
 * PARAMETERS
 *  mute      [IN]        Mute/Unmute
 * RETURNS
 *  void
 *****************************************************************************/
void aud_atv_mute(kal_bool mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY1(AUD_TRC_SET_ATV_MUTE, mute);
    
    g_is_mute = mute;
    
#ifdef __MM_DCM_SUPPORT__
    if(bMatv_powerOn)
#endif        
    {
        ATV_AudioMute(mute);
    }

#if defined(__BT_A2DP_SUPPORT__) || defined(__BT_AUDIO_VIA_SCO__)
    BT_MuteSpeaker(mute);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  aud_atv_is_mute
 * DESCRIPTION
 *  This function is used to check if the ATV is being mute.
 * PARAMETERS
 *  void
 * RETURNS
 *  Mute state
 *****************************************************************************/
kal_bool aud_atv_is_mute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_is_mute;
}


/*****************************************************************************
 * FUNCTION
 *  aud_atv_set_output_volume
 * DESCRIPTION
 *  This function sets the volume of ATV.
 * PARAMETERS
 *  volume                  [IN]     Analog gain.
 *  digital_gain_index      [IN]     Digital gain.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_atv_set_output_volume(kal_uint8 volume, kal_int8 digital_gain_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_VOLUME(AUD_VOLUME_ATV, volume, digital_gain_index);

#ifdef __MM_DCM_SUPPORT__
    if(bMatv_powerOn)
#endif        
    {
        ATV_AudioSetOutputVolume(volume, digital_gain_index);
    }

    /* Mute digitial gain when volume is 0 */
    if (volume == 0)
    {
        aud_atv_mute(KAL_TRUE);
    }
    else
    {
        aud_atv_mute(KAL_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_atv_set_volume_by_mode
 * DESCRIPTION
 *  This function sets the volume of ATV. Note that since the LINE-IN mode ATV
 *  needs to have separated volume settings, we config the volume of ATV as 
 *  follows:
 *
 *      ATV              Normal mode           Headset mode
 *     ------------------------------------------------------
 *      Volume type      FMR                   Media
 *      Audio mode       Loudspeaker           Loudspeaker
 *
 *  The idea is we don't use the loudspeaker volume setting for FMR and Media
 *  for now. By using this configuration, the noraml mode ATV will use the
 *  loudspeaker volume setting of FMR, and the headset mode ATV will use the
 *  loudspeaker volume setting of Media.
 *
 * PARAMETERS
 *  mode      [IN]      Audio mode.
 *  level     [IN]      Volume level.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_atv_set_volume_by_mode(kal_uint8 mode, kal_uint8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 new_level;
    kal_uint8 analog_gain;

#ifdef __16_LEVEL_AUDIO_VOLUME__
#ifndef __ATV_I2S_SUPPORT__
    kal_uint8 volume_level = 0;
#endif
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY2(AUD_TRC_SET_ATV_VOLUME, mode, level);

    /* If the second bit(from MSB) is set, the level 0 means mute. */
    if (AUD_VOL_IS_MUTE(level))
    {
        aud_atv_set_output_volume(0, 0);
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

    /* 7 level volume (MSB bit is not set) */
    if (AUD_VOL_IS_7_LEVEL_VOLUME(level))
    {
#if defined(TV_OUT_SUPPORT)
        if (mode == VOL_TV_OUT)
        {
            analog_gain = aud_get_volume_gain(mode, AUD_VOLUME_TVO, new_level);
        }
        else
#endif /* TV_OUT_SUPPORT */
        {
        #if defined (__ATV_I2S_SUPPORT__)
            analog_gain = aud_get_volume_gain(mode, AUD_VOLUME_MEDIA, new_level);
        #else
            if (mode == AUD_MODE_NORMAL)
            {
                analog_gain = aud_get_volume_gain(AUD_MODE_LOUDSPK, AUD_VOLUME_FMR, new_level);
            }
            else
            {
                analog_gain = aud_get_volume_gain(AUD_MODE_LOUDSPK, AUD_VOLUME_MEDIA, new_level); 
            }
        #endif /* __ATV_I2S_SUPPORT__ */
        }

        aud_atv_set_output_volume(analog_gain, 0);

    #if defined(__BT_A2DP_SUPPORT__) || defined(__BT_AUDIO_VIA_SCO__)
        BT_SetLevelVolume(new_level+1,7);
    #endif

    }
    /* 16 level volume */
    else
    {
#ifdef __16_LEVEL_AUDIO_VOLUME__

        /* Un-mute digital gain in case it is turn off by set mute function */
        aud_atv_mute(KAL_FALSE);

    #if defined(__ATV_I2S_SUPPORT__)
        /* Use level volume adjustment */
        if (new_level < aud_context_p->melody_max_volume_level)
        {
        #ifdef __MM_DCM_SUPPORT__
			if(bMatv_powerOn)
		#endif 
			{
				ATV_AudioSetLevelVolume(aud_context_p->acoustic_data.max_melody_volume_gain[mode],
                aud_context_p->acoustic_data.melody_volume_gain_step[mode],
                aud_context_p->melody_max_volume_level - 1 - new_level);
			}
        #if defined(__BT_A2DP_SUPPORT__) || defined(__BT_AUDIO_VIA_SCO__)
            BT_SetLevelVolume(new_level+1,aud_context_p->melody_max_volume_level);
        #endif

        }
    #else
        /* Remapping to 7-level volume */
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

    #if defined(TV_OUT_SUPPORT)
        if (mode == VOL_TV_OUT)
        {
            analog_gain = aud_get_volume_gain(mode, AUD_VOLUME_TVO, volume_level);
        }
        else
    #endif /* TV_OUT_SUPPORT */
        {
            if (mode == AUD_MODE_NORMAL)
            {
                analog_gain = aud_get_volume_gain(AUD_MODE_LOUDSPK, AUD_VOLUME_FMR, volume_level);
            }
            else
            {
                analog_gain = aud_get_volume_gain(AUD_MODE_LOUDSPK, AUD_VOLUME_MEDIA, volume_level); 
            }
        }
    
        aud_atv_set_output_volume(analog_gain, 0);

    #if defined(__BT_A2DP_SUPPORT__) || defined(__BT_AUDIO_VIA_SCO__)
        BT_SetLevelVolume(volume_level,7);
    #endif
        
    #endif /* __ATV_I2S_SUPPORT__ */
#else
        ASSERT(0);
#endif /* __16_LEVEL_AUDIO_VOLUME__ */
    }
}

/*****************************************************************************
 * FUNCTION
 *  aud_set_active_atv_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_active_atv_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* incoming call ring, alarm, message use the same volume */
    kal_uint8 gain_audio_mode;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __GAIN_TABLE_SUPPORT__
    /* store playing melody volume level, atv is using media volume */
    current_playing_melody_volume_level = aud_get_volume_level(aud_context_p->audio_mode, AUD_VOLUME_MEDIA);

    /* if it's headset mode and output to both earphone & loud speaker, use normal mode gain value */
    if (aud_context_p->audio_mode == AUD_MODE_HEADSET &&
        aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
    {
        gain_audio_mode = VOL_NORMAL;
    }
    else
    {
        gain_audio_mode = aud_context_p->audio_mode;
    }

    aud_atv_set_volume_by_mode(gain_audio_mode, current_playing_melody_volume_level);
    
#else /* #ifdef __GAIN_TABLE_SUPPORT__ */
    kal_uint64 volume;

    volume = aud_context_p->volume_tbl[AUD_VOLUME_ATV];
    aud_volume_set_media_volume(volume);
#endif /* __GAIN_TABLE_SUPPORT__ */

    /* disable audio mute when the volume is set again */
    aud_context_p->audio_mute = KAL_FALSE;

}



/*****************************************************************************
 * FUNCTION
 *  aud_atv_is_recorder_resource_available
 * DESCRIPTION
 *  This function is used to check if the recorder resource is available.
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool aud_atv_is_recorder_resource_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_resource_available = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__ATV_I2S_SUPPORT__)
#if defined(__MED_BT_HFP_MOD__)
    /* Can not record in Line-in SCO mode */
    if (aud_bt_hfp_is_audio_path_on())
    {
        is_resource_available = KAL_FALSE;
    }
#endif /* __MED_BT_HFP_MOD__ */
#endif /* __ATV_I2S_SUPPORT__ */

    return is_resource_available;
}

#endif /* __ATV_SUPPORT__ */
#endif /* MED_NOT_PRESENT */

