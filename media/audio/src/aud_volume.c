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
 * aud_volume.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary functions of audio volume settings.
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
#ifdef __GAIN_TABLE_SUPPORT__
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
#include "gain_table.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "aud_main.h"
#include "med_main.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif

#if defined(__MED_VID_DEC_MOD__)
#include "vid_main.h"
#endif
/*-----------------------------------------------------------------------------
                    macros, defines, typedefs, enums
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
                    data declaraions
 ----------------------------------------------------------------------------*/
 
/*-----------------------------------------------------------------------------
                    function prototypes
 ----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
                    privdate function declarations
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  aud_volume_set_linein_volume
 * DESCRIPTION
 *  This function sets the volume of LINE-IN path.
 * PARAMETERS
 *  volume      [IN]        Volume data.
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_volume_set_linein_volume(kal_uint64 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 volume_data;
    kal_uint8  volume_gain;
    kal_uint8  volume_level;
    kal_uint8  gain_max, gain_step;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (MED_AUD_VOL_CTRL_IS_RAW_DATA(volume)) /* raw data */
    {
        volume_data = MED_AUD_VOL_GET_RAW_VOLUME_DATA(volume);
        FMR_SetOutputGainControl(volume_data);
        FMR_SetDualPathGainControl(volume_data);
    }
    else if (MED_AUD_VOL_CTRL_IS_N_LEVEL(volume)) /* n-level */
    {
        gain_max     = MED_AUD_VOL_GET_N_LEVEL_MAX_GAIN(volume);
        gain_step    = MED_AUD_VOL_GET_N_LEVEL_GAIN_STEP(volume);
        volume_level = MED_AUD_VOL_GET_N_LEVEL_VOLUME_LEVEL(volume);

        if (volume_level < aud_context_p->melody_max_volume_level)
        {
            AFE_SetLevelVolume(L1SP_LINEIN,
                               gain_max,
                               gain_step,
                               aud_context_p->melody_max_volume_level - 1 - volume_level);
        }
    }
    else if (MED_AUD_VOL_CTRL_IS_PURE_GAIN(volume)) /* pure gain */
    {
        volume_gain = MED_AUD_VOL_GET_PURE_VOLUME_GAIN(volume);
        FMR_SetOutputVolume(volume_gain, 0);
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  _aud_volume_set_media_volume
 * DESCRIPTION
 *  This function sets the volume of Media path.
 * PARAMETERS
 *  volume      [IN]        Volume data.
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_volume_set_media_volume(kal_uint64 volume)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 volume_data;
    kal_uint8  volume_gain;
    kal_uint8  volume_level;
    kal_uint8  gain_max, gain_step;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (MED_AUD_VOL_CTRL_IS_RAW_DATA(volume)) /* Raw data */
    {
        volume_data = MED_AUD_VOL_GET_RAW_VOLUME_DATA(volume);
        Media_SetOutputGainControl(volume_data, MED_AUD_VOL_GET_RAW_VOLUME_DUAL_AUX(volume));
    }
    else if (MED_AUD_VOL_CTRL_IS_N_LEVEL(volume)) /* n-level */
    {
        gain_max     = MED_AUD_VOL_GET_N_LEVEL_MAX_GAIN(volume);
        gain_step    = MED_AUD_VOL_GET_N_LEVEL_GAIN_STEP(volume);
        volume_level = MED_AUD_VOL_GET_N_LEVEL_VOLUME_LEVEL(volume);

        if (volume_level < aud_context_p->melody_max_volume_level)
        {
            Media_SetLevelVolume(gain_max,
                                 gain_step,
                                 aud_context_p->melody_max_volume_level - 1 - volume_level);
        }
    }
    else if (MED_AUD_VOL_CTRL_IS_PURE_GAIN(volume)) /* Pure gain */
    {
        volume_gain = MED_AUD_VOL_GET_PURE_VOLUME_GAIN(volume);
        
        Media_SetOutputVolume(volume_gain, 0);
    }
    else
    {
        ASSERT(0);
    }

    /* Mute/unmute digital gain */
    if (MED_AUD_VOL_CTRL_IS_MUTE(volume))
    {
    #if defined(__MED_BT_A2DP_MOD__) && defined(__BTMTK__)
        if (! aud_bt_a2dp_is_mute_phone()) /* We should not mute digital gain if BT is on */
    #endif /* __MED_BT_A2DP_MOD__ && __BTMTK__ */
        {
            aud_audio_mute_digital_gain(KAL_TRUE, AUD_DIGITAL_GAIN_AUDIO);
        }
    }
    else
    {
        aud_audio_mute_digital_gain(KAL_FALSE, AUD_DIGITAL_GAIN_AUDIO);
    }
}


/*-----------------------------------------------------------------------------
                    publie function declarations
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  aud_volume_mute_mic
 * DESCRIPTION
 *  This function is used to mute/unmute the microphone.
 * PARAMETERS
 *  mute        [IN]        mute/unmute
 * RETURNS
 *  void
 *****************************************************************************/
void aud_volume_mute_mic(kal_bool mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    L1SP_MuteMicrophone(mute);
}


/*****************************************************************************
 * FUNCTION
 *  aud_volume_set_tone_volume
 * DESCRIPTION
 *  This function sets the volume of tone.
 * PARAMETERS
 *  volume      [IN]        Volume data.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_volume_set_tone_volume(kal_uint64 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 volume_data;
    kal_uint8  volume_gain;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_VOLUME(AUD_VOLUME_CTN, MED_AUD_VOL_GET_VOLUME_DATA(volume), MED_AUD_VOL_GET_VOLUME_CONTROL(volume));

    /* For backward compatiable with legacy 7-level volume */
    if (MED_AUD_VOL_GET_VOLUME_CONTROL(volume) == 0)
    {
        volume = gain_table_get_volume(AUD_VOLUME_CTN, MED_AUD_VOL_GET_VOLUME_LEVEL(volume));
    }
    
    if (MED_AUD_VOL_CTRL_IS_RAW_DATA(volume)) /* Raw data */
    {
        volume_data = MED_AUD_VOL_GET_RAW_VOLUME_DATA(volume);
        TONE_SetOutputGainControl(volume_data);
    }
    else if (MED_AUD_VOL_CTRL_IS_PURE_GAIN(volume)) /* Pure gain */
    {
        volume_gain = MED_AUD_VOL_GET_PURE_VOLUME_GAIN(volume);
        TONE_SetOutputVolume(volume_gain, 0);
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_volume_setkeytone_volume
 * DESCRIPTION
 *  This function sets volume of keytone.
 * PARAMETERS
 *  volume      [IN]        Volume data.       
 * RETURNS
 *  void
 *****************************************************************************/
void aud_volume_set_keytone_volume(kal_uint64 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 volume_data;
    kal_uint8  volume_gain;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_VOLUME(AUD_VOLUME_KEY, MED_AUD_VOL_GET_VOLUME_DATA(volume), MED_AUD_VOL_GET_VOLUME_CONTROL(volume));   

    if (MED_AUD_VOL_CTRL_IS_RAW_DATA(volume)) /* Raw data */
    {
        volume_data = MED_AUD_VOL_GET_RAW_VOLUME_DATA(volume);
        KT_SetOutputGainControl(volume_data);
    }
    else if (MED_AUD_VOL_CTRL_IS_PURE_GAIN(volume)) /* Pure gain */
    {
        volume_gain = MED_AUD_VOL_GET_PURE_VOLUME_GAIN(volume);
        KT_SetOutputVolume(volume_gain, 0);
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_volume_set_mic_volume
 * DESCRIPTION
 *  This function sets the volume of microphone.
 * PARAMETERS
 *  volume      [IN]        Volume data.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_volume_set_mic_volume(kal_uint64 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 volume_data;
    kal_uint8  volume_gain;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_VOLUME(AUD_VOLUME_MIC, MED_AUD_VOL_GET_VOLUME_DATA(volume), MED_AUD_VOL_GET_VOLUME_CONTROL(volume));
    
    if (MED_AUD_VOL_CTRL_IS_RAW_DATA(volume)) /* Raw data */
    {
        volume_data = MED_AUD_VOL_GET_RAW_VOLUME_DATA(volume);
        L1SP_SetMicGainControl(volume_data);
    }
    else if (MED_AUD_VOL_CTRL_IS_PURE_GAIN(volume)) /* Pure gain */
    {
        volume_gain = MED_AUD_VOL_GET_PURE_VOLUME_GAIN(volume);
        L1SP_SetMicrophoneVolume(volume_gain);
    }
    else
    {
        ASSERT(0);
    }
    
    /* Mute/unmute microphone */
    if (MED_AUD_VOL_CTRL_IS_MUTE(volume))
    {
        L1SP_MuteMicrophone(KAL_TRUE);
    }
    else
    {
        L1SP_MuteMicrophone(KAL_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_volume_set_fmr_volume
 * DESCRIPTION
 *  This function sets the volume of FM Radio.
 * PARAMETERS
 *  volume      [IN]        Volume data.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_volume_set_fmr_volume(kal_uint64 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_VOLUME(AUD_VOLUME_FMR, MED_AUD_VOL_GET_VOLUME_DATA(volume), MED_AUD_VOL_GET_VOLUME_CONTROL(volume));

#if defined(__FMRADIO_I2S_SUPPORT__)
    _aud_volume_set_media_volume(volume);
#else
    _aud_volume_set_linein_volume(volume);
#endif /* __FMRADIO_I2S_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  aud_volume_set_speech_volume
 * DESCRIPTION
 *  This function sets the volume of speech.
 * PARAMETERS
 *  volume      [IN]        Volume data.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_volume_set_speech_volume(kal_uint64 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 volume_data;
    kal_uint8  volume_gain;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_VOLUME(AUD_VOLUME_SPH, MED_AUD_VOL_GET_VOLUME_DATA(volume), MED_AUD_VOL_GET_VOLUME_CONTROL(volume));
     
    if (MED_AUD_VOL_CTRL_IS_RAW_DATA(volume)) /* Raw data */
    {
        volume_data = MED_AUD_VOL_GET_RAW_VOLUME_DATA(volume);
        L1SP_SetOutputGainControl(volume_data);
    }
    else if (MED_AUD_VOL_CTRL_IS_PURE_GAIN(volume)) /* Pure gain */
    {
        volume_gain = MED_AUD_VOL_GET_PURE_VOLUME_GAIN(volume);
        L1SP_SetOutputVolume(volume_gain, 0);
    }
    else
    {
        ASSERT(0);
    }

    /* Mute/unmute speaker */
    if (MED_AUD_VOL_CTRL_IS_MUTE(volume))
    {
        L1SP_MuteSpeaker(KAL_TRUE);
    }
    else
    {
        L1SP_MuteSpeaker(KAL_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_volume_set_sidetone_volume
 * DESCRIPTION
 *  This function sets the volume of side-tone.
 * PARAMETERS
 *  volume      [IN]        Volume data.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_volume_set_sidetone_volume(kal_uint64 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8  volume_gain;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_VOLUME(AUD_VOLUME_SID, MED_AUD_VOL_GET_VOLUME_DATA(volume), MED_AUD_VOL_GET_VOLUME_CONTROL(volume));

    volume_gain = MED_AUD_VOL_GET_PURE_VOLUME_GAIN(volume);
    
    L1SP_SetSidetoneVolume(volume_gain);
}


/*****************************************************************************
 * FUNCTION
 *  aud_volume_set_media_volume
 * DESCRIPTION
 *  This function sets the volume of Media.
 * PARAMETERS
 *  volume      [IN]        Volume data.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_volume_set_media_volume(kal_uint64 volume)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 volume_data;
    kal_uint8  volume_gain;
    kal_uint8  volume_level;
    kal_uint8  gain_max, gain_step;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_VOLUME(AUD_VOLUME_MEDIA, MED_AUD_VOL_GET_VOLUME_DATA(volume), MED_AUD_VOL_GET_VOLUME_CONTROL(volume));

#ifdef __MED_VID_DEC_MOD__
    if (vid_is_dummy_aud_playing())
    {
        return;
    }
#endif /* __MED_VID_DEC_MOD__ */

    /* For backward compatiable with legacy 7-level volume */
    if (MED_AUD_VOL_GET_VOLUME_CONTROL(volume) == 0)
    {
        volume = gain_table_get_volume(AUD_VOLUME_MEDIA, MED_AUD_VOL_GET_VOLUME_LEVEL(volume));
    }

    /* Set media volume */
    _aud_volume_set_media_volume(volume);
}


#ifdef __ATV_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  aud_volume_set_atv_volume
 * DESCRIPTION
 *  This function sets the volume of ATV.
 * PARAMETERS
 *  volume      [IN]        Volume data.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_volume_set_atv_volume(kal_uint64 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_VOLUME(AUD_VOLUME_ATV, MED_AUD_VOL_GET_VOLUME_DATA(volume), MED_AUD_VOL_GET_VOLUME_CONTROL(volume));
    
#if defined(__ATV_I2S_SUPPORT__)
    _aud_volume_set_media_volume(volume);
#else
    _aud_volume_set_linein_volume(volume);
#endif /* __ATV_I2S_SUPPORT__ */
}
#endif /* #ifdef __ATV_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  aud_volume_set_volume_req_hdlr
 * DESCRIPTION
 *  This function is used to set the volume of a given volume type.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_volume_set_volume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint64 volume;
    media_aud_set_volume_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_aud_set_volume_req_struct*) ilm_ptr->local_para_ptr;
    
    /* For backward compatiable with legacy 7-level volume */
    if (MED_AUD_VOL_GET_VOLUME_CONTROL(req_p->volume) == 0)
    {
        volume = gain_table_get_volume(req_p->audio_type, MED_AUD_VOL_GET_VOLUME_LEVEL(req_p->volume));
    }
    else
    {
        volume = req_p->volume;
    }
    
    aud_context_p->volume_tbl[req_p->audio_type] = volume;

    /* Call the corresponding handler */
    switch (req_p->audio_type)
    {
        case AUD_VOLUME_CTN:
            aud_volume_set_tone_volume(volume);
            break;
        case AUD_VOLUME_KEY:
            aud_volume_set_keytone_volume(volume);
            break;
        case AUD_VOLUME_MIC:
            aud_volume_set_mic_volume(volume);
            /* Disable audio mute when the volume is set again */
            aud_context_p->audio_mute = KAL_FALSE;
            break;
        case AUD_VOLUME_FMR:
            aud_volume_set_fmr_volume(volume);
            /* Disable audio mute when the volume is set again */
            aud_context_p->audio_mute = KAL_FALSE;
            break;
        case AUD_VOLUME_SPH:
            aud_volume_set_speech_volume(volume);
            break;
        case AUD_VOLUME_SID:
            aud_volume_set_sidetone_volume(volume);
            break;
        case AUD_VOLUME_MEDIA:
            if (req_p->apply)
            {
                aud_volume_set_media_volume(volume);
                /* Disable audio mute when the volume is set again */
                aud_context_p->audio_mute = KAL_FALSE;
            }
            break;
    #ifdef __ATV_SUPPORT__
        case AUD_VOLUME_ATV:
            aud_volume_set_atv_volume(volume);
            
            /* Disable audio mute when the volume is set again */
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
}


/*****************************************************************************
 * FUNCTION
 *  aud_volume_update_volume_req_hdlr
 * DESCRIPTION
 *  This function is used to update the volume of a given volume type. In case
 *  the audio is being muted, the update of FMR/MEDIA will do nothing.
 * PARAMETERS
 *  ilm_ptr     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_volume_update_volume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint64 volume;
    l4aud_audio_update_volume_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (l4aud_audio_update_volume_req_struct*) ilm_ptr->local_para_ptr;

    volume = req_p->volume;
    aud_context_p->volume_tbl[req_p->audio_type] = volume;

    /* Call the corresponding handler */
    switch (req_p->audio_type)
    {
        case AUD_VOLUME_CTN:
            aud_volume_set_tone_volume(volume);
            break;
        case AUD_VOLUME_KEY:
            aud_volume_set_keytone_volume(volume);
            break;
        case AUD_VOLUME_MIC:
            if (! aud_context_p->audio_mute)
            {
                aud_volume_set_mic_volume(volume);
            }
            break;
        case AUD_VOLUME_FMR:
            if (! aud_context_p->audio_mute)
            {
                aud_volume_set_fmr_volume(volume);
            }
            break;
        case AUD_VOLUME_SPH:
            aud_volume_set_speech_volume(volume);
            break;
        case AUD_VOLUME_SID:
            aud_volume_set_sidetone_volume(volume);
            break;
        case AUD_VOLUME_MEDIA:
            if (! aud_context_p->audio_mute)
            {
                aud_volume_set_media_volume(volume);
            }
            break;
    #ifdef __ATV_SUPPORT__
        case AUD_VOLUME_ATV:
            if (! aud_context_p->audio_mute)
            {
                aud_volume_set_atv_volume(volume);
            }
            break;
    #endif /* __ATV_SUPPORT__ */
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_volume_set_mute_req_hdlr
 * DESCRIPTION
 *  This function is used to mute/unmute a given volume type. Note that the
 *  side-tone could not be mtued/unmuted.
 * PARAMETERS
 *  ilm_ptr     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_volume_set_mute_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint64 volume;
    media_aud_set_mute_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_aud_set_mute_req_struct*) ilm_ptr->local_para_ptr;

    aud_context_p->audio_mute = req_p->mute;
    
    if (req_p->mute) /* Mute */
    {
        volume = MED_AUD_VOL_GEN_RAW_DATA(0, 0, 0);
        volume = MED_AUD_VOL_SET_MUTE(volume);
        
        switch (req_p->vol_type)
        {
            case AUD_VOLUME_CTN:
                aud_volume_set_tone_volume(volume);
                break;
            case AUD_VOLUME_KEY:
                aud_volume_set_keytone_volume(volume);
                break;
            case AUD_VOLUME_MIC:
                aud_volume_mute_mic(KAL_TRUE);
                break;
            case AUD_VOLUME_FMR:
                aud_volume_set_fmr_volume(volume);
                break;
            case AUD_VOLUME_SPH:
                aud_volume_set_speech_volume(volume);
                break;
            case AUD_VOLUME_SID:
                break;
            case AUD_VOLUME_MEDIA:
                aud_volume_set_media_volume(volume);
                break;
        #ifdef __ATV_SUPPORT__
            case AUD_VOLUME_ATV:
                aud_volume_set_atv_volume(volume);
                break;
        #endif /* __ATV_SUPPORT__ */
            default:
                break;
        }
    }
    else /* Unmute */
    {
        volume = aud_context_p->volume_tbl[req_p->vol_type];
        
        switch (req_p->vol_type)
        {
            case AUD_VOLUME_CTN:
                aud_volume_set_tone_volume(volume);
                break;
            case AUD_VOLUME_KEY:
                aud_volume_set_keytone_volume(volume);
                break;
            case AUD_VOLUME_MIC:
                aud_volume_mute_mic(KAL_FALSE);
                break;
            case AUD_VOLUME_FMR:
                aud_volume_set_fmr_volume(volume);
                break;
            case AUD_VOLUME_SPH:
                aud_volume_set_speech_volume(volume);
                break;
            case AUD_VOLUME_SID:
                break;
            case AUD_VOLUME_MEDIA:
                aud_volume_set_media_volume(volume);
                break;
        #ifdef __ATV_SUPPORT__
            case AUD_VOLUME_ATV:
                aud_volume_set_atv_volume(volume);
                break;
        #endif /* __ATV_SUPPORT__ */
            default:
                break;
        }
    }
}

#endif /* __GAIN_TABLE_SUPPORT__ */
#endif /* MED_NOT_PRESENT */ 

