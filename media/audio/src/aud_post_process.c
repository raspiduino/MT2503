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
 *   aud_post_process.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is to handle all messages for post audio process
 *   (include time stretch and 3D effect currently)
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
//#include "stack_msgs.h"
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
//#include "custom_equipment.h"
//#include "custom_nvram_editor_data_item.h"

/* local includes */
#include "med_global.h"
#include "med_main.h"
//#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "aud_main.h"
#include "med_main.h"
#include "med_utility.h"
//#include "MP4_Parser.h"
//#include "drm_gprot.h"
#include "aud_player.h"
#include "aud_player_mp4.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "fsal.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#ifdef __SPECTRUM_DISPLAY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  aud_start_calc_spectrum_req_hdlr
 * DESCRIPTION
 *  This function is to handle the request to start to calculate audio spectrum tops and vals.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_start_calc_spectrum_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SPT_Open();
}


/*****************************************************************************
 * FUNCTION
 *  aud_stop_calc_spectrum_req_hdlr
 * DESCRIPTION
 *  This function is to handle the request to stop calculating audio spectrum tops and vals.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_stop_calc_spectrum_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SPT_Close();
}


/*****************************************************************************
 * FUNCTION
 *  aud_get_spectrum_req_hdlr
 * DESCRIPTION
 *  This function is to handle the request to get latest audio spectrum tops and vals.
 *  tops and vals are two arrays of 16 uint8 values
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_get_spectrum_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_get_spectrum_req_struct *msg_p = (media_aud_get_spectrum_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SPT_GetSpectrum(msg_p->top_p, msg_p->val_p);

    aud_set_result_and_event((kal_int32)MED_RES_OK,AUD_EVT_GET_SPECTRUM);
}
#endif /* __SPECTRUM_DISPLAY_SUPPORT__ */


#if defined(__MED_AUD_AUDIO_EFFECT__)

#if defined(__MED___BES_TS_SUPPORT____) || defined(__MED___BES_LIVE_SUPPORT____) || defined(__MED_AUD_SURROUND__) || defined(__MED_AUD_EQUALIZER__)
static aud_app_context_struct g_aud_pp;
#endif

/*****************************************************************************
 * FUNCTION
 *  aud_post_process_startup
 * DESCRIPTION
 *  This function is to initialize the audio post process interface in media task
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool aud_post_process_startup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MED___BES_TS_SUPPORT____)
    g_aud_pp.state_stretch = AUD_EFFECT_OFF;
#endif

#if defined(__MED___BES_LIVE_SUPPORT____) || defined(__MED_AUD_SURROUND__) || defined(__MED_AUD_EQUALIZER__)
    g_aud_pp.state_surround = AUD_EFFECT_OFF; 
    g_aud_pp.state_reverb = AUD_EFFECT_UNSET;
    g_aud_pp.state_eq = AUD_EFFECT_UNSET;
#endif 

    return KAL_TRUE;
}

#if defined(__MED___BES_TS_SUPPORT____)

/*****************************************************************************
 * FUNCTION
 *  aud_stretch_get_mode_from_speed
 * DESCRIPTION
 *  This function is to convert play speed to the mode provide by l1 audio
 * PARAMETERS
 *  speed       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static kal_uint16 aud_stretch_get_mode_from_speed(kal_uint16 speed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 mode = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (speed)
    {
        case 50:
            mode = 1;
            break;
        case 80:
            mode = 2;
            break;
        case 125:
        case 128:
            mode = 3;
            break;
        case 160:
            mode = 4;
            break;
        default:
            break;
    }

    return mode;
}


/*****************************************************************************
 * FUNCTION
 *  aud_stretch_set_speed
 * DESCRIPTION
 *  This function is the interface of setting play speed for all audio for media task
 * PARAMETERS
 *  speed       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 aud_stretch_set_speed(kal_uint16 speed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 mode;
    Media_Status ts_result;
    kal_int32 set_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Convert speed to mode */
    if ((mode = aud_stretch_get_mode_from_speed(speed)) != 0)
    {
        /* Set time stretch mode and turn on it */
        ts_result = AudioPP_TS_SetSpeed(mode);

        if (ts_result == MEDIA_SUCCESS)
        {
            g_aud_pp.state_stretch = AUD_EFFECT_ON;
            set_result = MED_RES_OK;
        }
        else
        {
            set_result = MED_RES_FAIL;
        }
    }
    /* Unsupport speed mode */
    else
    {
        set_result = MED_RES_PARAM_ERROR;
    }

    return set_result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_stretch_check_stream_format_req_hdlr
 * DESCRIPTION
 *  This function is to check format for audio data stream
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_stretch_check_stream_format_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_support;
    STFSAL ext_file;
    FSAL_Status fsal_ret;
    media_stretch_check_stream_format_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_stretch_check_stream_format_req_struct*) ilm_ptr->local_para_ptr;

    FSAL_Direct_SetRamFileSize(&ext_file, msg_p->size);
    fsal_ret = FSAL_Open(&ext_file, (void*)msg_p->data_p, FSAL_ROMFILE);

    if (fsal_ret == FSAL_OK)
    {
        /* Check if the file can play with time stretch on */
        is_support = AudioPP_TS_IsSupport((Media_Format) msg_p->format, &ext_file);        

        FSAL_Close(&ext_file);

        if (is_support)
        {
            aud_app_set_result(MED_RES_OK);
            EFFECT_SET_EVENT(TS_EVT_CHECK);
            return;
        }
    }

    aud_app_set_result(MED_RES_FAIL);
    EFFECT_SET_EVENT(TS_EVT_CHECK);

}


/*****************************************************************************
 * FUNCTION
 *  aud_stretch_check_file_format_req_hdlr
 * DESCRIPTION
 *  This function is to check format for audio file
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_stretch_check_file_format_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_stretch_check_file_format_req_struct *msg_p;
    kal_int32 result = MED_RES_INVALID_FORMAT;
    kal_int16 format;
    kal_bool is_pp_support = KAL_FALSE;
    STFSAL fsal_handle;
    FSAL_Status fsal_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_stretch_check_file_format_req_struct*) ilm_ptr->local_para_ptr;

    /* Get file audio type from extension */
    format = med_get_media_type(msg_p->file_path);

    switch(format)
    {
        case MED_TYPE_3GP:
        case MED_TYPE_MP4:
        case MED_TYPE_M4A:
        case MED_TYPE_FLV:
        case MED_TYPE_F4V:
        case MED_TYPE_F4A:
        case MED_TYPE_RV:
        case MED_TYPE_RMVB:
        case MED_TYPE_RM:
        case MED_TYPE_RA:
            result = MED_RES_UNSUPPORTED_SPEED;
            break;

        default:
        {
        fsal_ret = FSAL_Open(&fsal_handle, (void*)msg_p->file_path, FSAL_READ_SHARED);

        if (fsal_ret == FSAL_OK)
        {
            /* Check if the file can be played with time stretch effect */
            is_pp_support = AudioPP_TS_IsSupport((Media_Format)format, &fsal_handle);
            
            FSAL_Close(&fsal_handle);
            
            if (is_pp_support)
            {
                result = MED_RES_OK;
            }
            else
            {
                result = MED_RES_UNSUPPORTED_SPEED;
            }
        }
        else if (fsal_ret == FSAL_OPEN_ERROR)
        {
            result = MED_RES_OPEN_FILE_FAIL;
        }
        else
        {
            result = MED_RES_FAIL;
        }
            break;
        }
    }
    
    aud_app_set_result(result);
    EFFECT_SET_EVENT(TS_EVT_CHECK);
}


/*****************************************************************************
 * FUNCTION
 *  aud_stretch_set_speed_req_hdlr
 * DESCRIPTION
 *  This function is the request hanlder of setting play speed for all audio
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_stretch_set_speed_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_stretch_set_speed_req_struct *msg_p;
    kal_int32 set_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_stretch_set_speed_req_struct*) ilm_ptr->local_para_ptr;

    /* Set time stretch speed */
    set_result = aud_stretch_set_speed(msg_p->speed);

    aud_app_set_result(set_result);
    EFFECT_SET_EVENT(TS_EVT_SET);
}


/*****************************************************************************
 * FUNCTION
 *  aud_stretch_close_req_hdlr
 * DESCRIPTION
 *  This function is the request handler of turning off play speed and play as normal speed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_stretch_close_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_stretch_close();

    aud_app_set_result(MED_RES_OK);
    EFFECT_SET_EVENT(TS_EVT_CLOSE);
}


/*****************************************************************************
 * FUNCTION
 *  aud_stretch_close
 * DESCRIPTION
 *  This function is the interface of turning off play speed for media task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_stretch_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_aud_pp.state_stretch == AUD_EFFECT_ON)
    {
        AudioPP_TS_Close();
    }

    g_aud_pp.state_stretch = AUD_EFFECT_OFF;
}
#endif /*#if defined(__MED___BES_TS_SUPPORT____)*/


#if defined(__MED___BES_LIVE_SUPPORT____)
/*****************************************************************************
 * FUNCTION
 *  aud_reverb_set_mode_req_hdlr
 * DESCRIPTION
 *  This function is to set the 3D effect coefficient
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_reverb_set_mode_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_reverb_set_mode_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY1(AUD_REVERB_SET_MODE_REQ_HDLR, g_aud_pp.state_reverb);

    msg_p = (media_reverb_set_mode_req_struct*) ilm_ptr->local_para_ptr;

    AudioPP_Reverb_SetMode(msg_p->mode);

    /* First time set parameter. If not first time set, keep current state */
    if (g_aud_pp.state_reverb == AUD_EFFECT_UNSET)
    {
        g_aud_pp.state_reverb = AUD_EFFECT_OFF;
    }

    aud_app_set_result(MED_RES_OK);
    EFFECT_SET_EVENT(REVERB_EVT_SET);
}


/*****************************************************************************
 * FUNCTION
 *  aud_reverb_turn_on_req_hdlr
 * DESCRIPTION
 *  This function is to turn on 3D sound effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_reverb_turn_on_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY3(AUD_REVERB_TURN_ON_REQ_HDLR, g_aud_pp.state_eq, g_aud_pp.state_reverb, g_aud_pp.state_surround);


    /* Parameter is not set */
    if (g_aud_pp.state_reverb == AUD_EFFECT_UNSET)
    {
        aud_app_set_result(MED_RES_FAIL);
    }
    /* Can not turn on with surround or equalizer at the same time */
    else if(g_aud_pp.state_surround == AUD_EFFECT_ON || g_aud_pp.state_eq == AUD_EFFECT_ON)
    {
        aud_app_set_result(MED_RES_BUSY);
    }
    /* Parameter is already set but not turn on or being paused by other feature. */
    else if (g_aud_pp.state_reverb == AUD_EFFECT_OFF)
    {
        result = AudioPP_Reverb_TurnOn();
        aud_app_set_result((kal_int32) aud_get_res((kal_uint8) result));

        if (result == MEDIA_SUCCESS)
        {
            g_aud_pp.state_reverb = AUD_EFFECT_ON;
        }
    }

    EFFECT_SET_EVENT(REVERB_EVT_ON);
}


/*****************************************************************************
 * FUNCTION
 *  aud_reverb_turn_off_req_hdlr
 * DESCRIPTION
 *  This function is to turn off 3D sound effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_reverb_turn_off_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY3(AUD_REVERB_TURN_OFF_REQ_HDLR, g_aud_pp.state_eq, g_aud_pp.state_reverb, g_aud_pp.state_surround);

    if (g_aud_pp.state_reverb == AUD_EFFECT_ON)
    {
        AudioPP_Reverb_TurnOff();
    }

    /* If 3D effect is not set, do not change its state. */
    if (g_aud_pp.state_reverb != AUD_EFFECT_UNSET)
    {
        g_aud_pp.state_reverb = AUD_EFFECT_OFF;
    }

    aud_app_set_result(MED_RES_OK);
    EFFECT_SET_EVENT(REVERB_EVT_OFF);
}

#endif /* #if defined(__MED___BES_LIVE_SUPPORT____) */


#if defined(__MED_AUD_SURROUND__)
/*****************************************************************************
 * FUNCTION
 *  aud_surround_turn_on_req_hdlr
 * DESCRIPTION
 *  This function is to turn on 3d surround sound
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_surround_turn_on_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_surround_turn_on_req_struct *msg_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY3(AUD_SURROUND_TURN_ON_REQ_HDLR, g_aud_pp.state_eq, g_aud_pp.state_reverb, g_aud_pp.state_surround);

    msg_p = (media_surround_turn_on_req_struct*) ilm_ptr->local_para_ptr;

    /* Can not turn on with reverb or surround at the same time */
    if(g_aud_pp.state_reverb == AUD_EFFECT_ON || g_aud_pp.state_eq == AUD_EFFECT_ON)
    {
        aud_app_set_result(MED_RES_BUSY);
    }
    else if(g_aud_pp.state_surround == AUD_EFFECT_OFF)
    {
        AudioPP_Surround_Enable();
        AudioPP_Surround_ModeSelect(msg_p->mode);
        g_aud_pp.state_surround = AUD_EFFECT_ON;
        g_aud_pp.mode_surround = msg_p->mode;
        aud_app_set_result(MED_RES_OK);
    }
    else if((g_aud_pp.state_surround == AUD_EFFECT_ON) &&
            (g_aud_pp.mode_surround != msg_p->mode))
    {
        AudioPP_Surround_ModeSelect(msg_p->mode);
        g_aud_pp.mode_surround = msg_p->mode;
        aud_app_set_result(MED_RES_OK);
    }

    EFFECT_SET_EVENT(SURROUND_EVT_ON);
}


/*****************************************************************************
 * FUNCTION
 *  aud_surround_turn_off_req_hdlr
 * DESCRIPTION
 *  This function is to turn off 3d surround sound
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_surround_turn_off_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY3(AUD_SURROUND_TURN_OFF_REQ_HDLR, g_aud_pp.state_eq, g_aud_pp.state_reverb, g_aud_pp.state_surround);

    if(g_aud_pp.state_surround == AUD_EFFECT_ON)
    {
        AudioPP_Surround_Disable();
        g_aud_pp.state_surround = AUD_EFFECT_OFF;
    }

    aud_app_set_result(MED_RES_OK);
    EFFECT_SET_EVENT(SURROUND_EVT_OFF);
}
#endif /* #if defined(__MED_AUD_SURROUND__) */


#if defined(__MED_AUD_EQUALIZER__)
/*****************************************************************************
 * FUNCTION
 *  aud_eq_set_magnitude_req_hdlr
 * DESCRIPTION
 *  This function is to set the equalizer magnitude
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_eq_set_magnitude_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_eq_set_magnitude_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY1(AUD_EQ_SET_MAGNITUDE_REQ_HDLR, g_aud_pp.state_eq);

    msg_p = (media_aud_eq_set_magnitude_req_struct*) ilm_ptr->local_para_ptr;

    AudioPP_Equalizer_SetMag_Flexible(msg_p->magnitude);

    /* First time set parameter. If not first time set, keep current state */
    if (g_aud_pp.state_eq == AUD_EFFECT_UNSET)
    {
        g_aud_pp.state_eq = AUD_EFFECT_OFF;
    }

    aud_app_set_result(MED_RES_OK);
    EFFECT_SET_EVENT(EQ_EVT_SET);
}


/*****************************************************************************
 * FUNCTION
 *  aud_eq_turn_on_req_hdlr
 * DESCRIPTION
 *  This function is to turn on equalizer sound effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_eq_turn_on_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY3(AUD_EQ_TURN_ON_REQ_HDLR, g_aud_pp.state_eq, g_aud_pp.state_reverb, g_aud_pp.state_surround);

    /* Parameter is not set */
    if (g_aud_pp.state_eq == AUD_EFFECT_UNSET)
    {
        aud_app_set_result(MED_RES_FAIL);
    }
    /* Can not turn on with reverb or surround at the same time */
    else if(g_aud_pp.state_reverb == AUD_EFFECT_ON || g_aud_pp.state_surround == AUD_EFFECT_ON)
    {
        aud_app_set_result(MED_RES_BUSY);
    }
    /* Parameter is already set but not turn on */
    else if (g_aud_pp.state_eq == AUD_EFFECT_OFF)
    {
        AudioPP_Equalizer_TurnOn();
        g_aud_pp.state_eq = AUD_EFFECT_ON;
        aud_app_set_result(MED_RES_OK);
    }

    EFFECT_SET_EVENT(EQ_EVT_ON);
}


/*****************************************************************************
 * FUNCTION
 *  aud_eq_turn_off_req_hdlr
 * DESCRIPTION
 *  This function is to turn off equalizer sound effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_eq_turn_off_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY3(AUD_EQ_TURN_OFF_REQ_HDLR, g_aud_pp.state_eq, g_aud_pp.state_reverb, g_aud_pp.state_surround);

    if (g_aud_pp.state_eq == AUD_EFFECT_ON)
    {
        AudioPP_Equalizer_TurnOff();
    }

    /* If 3D effect is not set, do not change its state. */
    if (g_aud_pp.state_eq != AUD_EFFECT_UNSET)
    {
        g_aud_pp.state_eq = AUD_EFFECT_OFF;
    }

    aud_app_set_result(MED_RES_OK);
    EFFECT_SET_EVENT(EQ_EVT_OFF);
}
#endif /* #if defined(__MED_AUD_EQUALIZER__) */


#if defined(__MED_AUD_BASS_ENHANCE__)
/*****************************************************************************
 * FUNCTION
 *  aud_bass_enhance_turn_on_req_hdlr
 * DESCRIPTION
 *  This function is to turn on bass enhancement effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bass_enhance_turn_on_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_BASS_ENHANCE_TURN_ON_REQ_HDLR);

    AudioPP_BassEnhance_Enable();

    aud_app_set_result(MED_RES_OK);
    EFFECT_SET_EVENT(AUD_PP_EVT_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  aud_bass_enhance_turn_off_req_hdlr
 * DESCRIPTION
 *  This function is to turn off bass enhancement effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_bass_enhance_turn_off_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_BASS_ENHANCE_TURN_OFF_REQ_HDLR);

    AudioPP_BassEnhance_Disable();

    aud_app_set_result(MED_RES_OK);
    EFFECT_SET_EVENT(AUD_PP_EVT_WAIT);
}
#endif /* #if defined(__MED_AUD_BASS_ENHANCE__) */


#if defined(__MED_AUD_LOUDNESS__)
/*****************************************************************************
 * FUNCTION
 *  aud_loudness_turn_on_req_hdlr
 * DESCRIPTION
 *  This function is to turn on loudness effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_loudness_turn_on_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_LOUDNESS_TURN_ON_REQ_HDLR);

    if (! aud_context_p->loudness_on)
    {
        aud_context_p->loudness_on = KAL_TRUE;
        
    #if defined(AUDIO_COMPENSATION_ENABLE) || (__AUDIO_COMPENSATION_SW_VERSION__)
        /* Update compensation filer */
        aud_audio_set_melody_path_volume(aud_context_p->audio_mode);
    #endif /* AUDIO_COMPENSATION_ENABLE || __AUDIO_COMPENSATION_SW_VERSION__ */
        
        AudioPP_Loudness_Enable();
    }

    aud_app_set_result(MED_RES_OK);
    EFFECT_SET_EVENT(AUD_PP_EVT_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  aud_loudness_turn_off_req_hdlr
 * DESCRIPTION
 *  This function is to turn off loudness effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_loudness_turn_off_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_LOUDNESS_TURN_OFF_REQ_HDLR);

    if (aud_context_p->loudness_on)
    {
        aud_context_p->loudness_on = KAL_FALSE;
        
        AudioPP_Loudness_Disable();

    #if defined(AUDIO_COMPENSATION_ENABLE) || (__AUDIO_COMPENSATION_SW_VERSION__)
        /* Update compensation filer */
        aud_audio_set_melody_path_volume(aud_context_p->audio_mode);
    #endif /* AUDIO_COMPENSATION_ENABLE || __AUDIO_COMPENSATION_SW_VERSION__ */
    }

    aud_app_set_result(MED_RES_OK);
    EFFECT_SET_EVENT(AUD_PP_EVT_WAIT);
}
#endif /* #if defined(__MED_AUD_LOUDNESS__) */
#endif /* #if defined(__MED_AUD_AUDIO_EFFECT__)*/
#endif /* MED_NOT_PRESENT */

