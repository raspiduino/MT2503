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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * VolumeHandler.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Volume Key Handlers
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : VolumeHandler.c

   PURPOSE     : Volume Key Handlers

   REMARKS     : nil

   AUTHOR      : Deepali, NEERAJ SHARMA

   DATE     : July 22,03

**************************************************************/
#include "MMI_features.h"
//#include "MMI_include.h"
#include "VolumeHandler.h"
#include "mmi_rp_app_profiles_def.h"
#include "resource_audio.h"
//#include "mdi_datatype.h"
#include "mdi_audio.h"
//#include "CallManagementStruct.h"
//#include "CallManagementGProt.h"
#ifdef __MMI_VOIP__
#include "VoIPGProt.h"
#endif
//#include "gpioInc.h"
//#include "IdleAppDef.h"
//#include "SimDetectionDef.h"
#include "Gpiosrvgprot.h"
#include "IdleGprot.h"

#ifdef __MMI_BT_SUPPORT__
//#include "BTMMIScrGprots.h"
#endif 

#ifdef __J2ME__
#include "jma_interface.h"
#include "j2me_custom_option.h"
#include "jam_interface.h"
#include "jvm_interface.h"
#endif /* __J2ME__ */

#ifdef __MMI_MEDIA_PLAYER__
#include "MediaPlayerGProt.h"
#endif

#include "UCMGProt.h"
#include "UcmSrvGprot.h"

//#include "ScrLockerGprot.h"
#include "ProfilesSrvGProt.h"
//#include "GeneralDeviceGprot.h"
#include "GpioSrvGprot.h"
#include "mmi_frm_input_gprot.h"
#include "MMIDataType.h"
#include "wgui_categories_list.h"
#include "custom_srv_prof_defs.h"
#include "device.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "mmi_frm_history_gprot.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_profiles_def.h"
#include "mmi_frm_timer_gprot.h"
#ifdef __MMI_HF_SUPPORT__
#include "UcmBTSrvGprot.h"
#endif // __MMI_HF_SUPPORT__
/*static mmi_frm_kbd_tone_state_enum key_tone_state = MMI_KEY_TONE_INVALID;*/

#ifdef __MMI_AUDIO_PLAYER__
BOOL mmi_audply_is_playing(void);
void mmi_audply_press_inc_volume(void);
void mmi_audply_press_dec_volume(void);
#endif /* __MMI_AUDIO_PLAYER__ */ 

#if defined(__MMI_BT_MUSIC__) || defined(__MMI_AUDIO_PLAYER_BT__)
extern BOOL mmi_bt_music_is_playing(void);
extern void mmi_bt_music_inc_vol(void);
extern void mmi_bt_music_dec_vol(void);
#endif

#ifdef __MMI_FM_RADIO__
BOOL mmi_fmrdo_is_power_on(void);
void mmi_fmrdo_inc_volume(void);
void mmi_fmrdo_dec_volume(void);
#endif /* __MMI_FM_RADIO__ */ 

#ifdef __A8BOX_SUPPORT__
extern BOOL mmi_a8box_is_playing(void);
extern void mmi_a8box_volume_down(void);
extern void mmi_a8box_volume_up(void);
#endif /* __A8BOX_SUPPORT__ */

#ifdef __GADGET_SUPPORT__
extern int gadget_adp_audio_service_audio_playing(void);
extern void gadget_adp_audio_service_adjust_volume(int increase);
#endif /* __GADGET_SUPPORT__ */

static MMI_BOOL mmi_volume_hdlr_check_app_status();
static void mmi_volume_hdlr_key_pad_vol(MMI_BOOL is_vol_button_up, MMI_BOOL is_long_press);
static void mmi_volume_hdlr_show_vertical_bar(mmi_volume_hdlr_vertical_bar_type bar_type);

extern S32 volume_level_UI;
FuncPtr volumeDecreaseFunction;
FuncPtr volumeIncreaseFunction;
FuncPtr volumeMinFunction;
FuncPtr volumeMaxFunction;
FuncPtr hardwareVolumeFunction;
U16 volumeCaption;
S32 *initialVolume;
U16 LSKCaption;
U16 RSKCaption;
FuncPtr LSKCallback;
FuncPtr RSKCallback;
FuncPtr ExitCallback;
U32 volumeTimer;
U8 updownFlag;
S32 volLevel;
FuncPtr EndKeyFuncPtr;

VOLUMEHANDLER_TYPE volume_type;        // This is to keep track which type of volume is applied by volume handler

/* PMT HIMANSHU START 20050729 */
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WALLPAPER_ON_BOTTOM__)

#define LONGPRESS_DELAY 6

/* variable for synchronizing the time of KEY_LONG_PRESS event with MMI_PEN_EVENT_LONG_TAP event */
U16 callback_timer = 0;

#endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
/* PMT HIMANSHU END 20050729 */

/*****************************************************************************
 * FUNCTION
 *  play_keypad_tone
 * DESCRIPTION
 *  play current profile keypad tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void play_keypad_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_keypad_tone_type_enum keypad_tone;
    U8 keypad_vol = volume_level_UI;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (volume_level_UI <= 0)
    {
        return;
    }
    if (srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) != SRV_PROF_RET_PROFILE_ACTIVATED)
    {
#ifdef __MMI_SILENT_MEETING_PROFILE__
        if (srv_prof_is_profile_activated(SRV_PROF_MEETING_MODE) != SRV_PROF_RET_PROFILE_ACTIVATED)
#endif 
        {
            srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_KEYPAD_TONE_TYPE, (void*)&keypad_tone);

            if (keypad_tone == SRV_PROF_KEYPAD_CLICK)
            {
                mdi_audio_play_id_with_vol_path(
                    TONE_KEY_CLICK, 
                    DEVICE_AUDIO_PLAY_ONCE, 
                    MDI_AUD_VOL_MUTE(keypad_vol),
                    MDI_DEVICE_SPEAKER2);
            }
            else if (keypad_tone != SRV_PROF_KEYPAD_SILENT)
            {
                mdi_audio_play_id_with_vol_path(
                    TONE_KEY_NORMAL, 
                    DEVICE_AUDIO_PLAY_ONCE, 
                    MDI_AUD_VOL_MUTE(keypad_vol),
                    MDI_DEVICE_SPEAKER2);
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  SetDefaultVolumeKeyHandlers
 * DESCRIPTION
 *  Sets Default Volume Handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetDefaultVolumeKeyHandlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 isValid = 0;
    mmi_frm_kbd_tone_state_enum currKeyToneState;
    U8 volume_level;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_RING_VOL_LEVEL,&volume_level);
        if (MDI_AUD_VOL_IS_MUTE_LEVEL(volume_level))
        {
            volume_level = volume_level & 0x0F;
        }
        volLevel = volume_level;
        
        SetVolumeKeyHandlerFunctions(
            NULL,
            NULL,
            NULL,
            NULL,
            STR_GLOBAL_RINGTONE,
            &volLevel,
            0,
            STR_GLOBAL_BACK,
            NULL,
            ExitScrSetKeyPadVolumeLevel,
            1000,
            RingVolumeExitFunction,
            0,
            VOLUMEHANDLER_RING_TONE);
        isValid = 1;
    }
    else if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 &&
             srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CSD_CALL_TYPE_ALL, NULL) <= 0)
    {
        volume_level = srv_speech_get_mode_volume();
        if (MDI_AUD_VOL_IS_MUTE_LEVEL(volume_level))
        {
            volume_level = volume_level & 0x0F;
        }
        volLevel = volume_level;
        SetVolumeKeyHandlerFunctions(
            NULL,
            NULL,
            NULL,
            NULL,
            STR_GLOBAL_VOLUME,
            &volLevel,
            0,
            STR_GLOBAL_BACK,
            NULL,
            ExitScrSetKeyPadVolumeLevel,
            1000,
            SpeechVolumeExitFunction,
            0,
            VOLUMEHANDLER_SPEECH_TONE);
        isValid = 1;
    }

#ifdef __MMI_HF_SUPPORT__
    if (srv_ucm_bt_query_call_count(SRV_UCM_BT_INCOMING_STATE, NULL) > 0)
    {
        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_RING_VOL_LEVEL,&volume_level);
        if (MDI_AUD_VOL_IS_MUTE_LEVEL(volume_level))
        {
            volume_level = volume_level & 0x0F;
        }
        volLevel = volume_level;
        
        SetVolumeKeyHandlerFunctions(
            NULL,
            NULL,
            NULL,
            NULL,
            STR_GLOBAL_RINGTONE,
            &volLevel,
            0,
            STR_GLOBAL_BACK,
            NULL,
            ExitScrSetKeyPadVolumeLevel,
            1000,
            RingVolumeExitFunction,
            0,
            VOLUMEHANDLER_RING_TONE);
        isValid = 1;
    }
    else if(srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_CONNECTED, NULL) > 0)
    {
        volume_level = srv_speech_get_mode_volume();
        if (MDI_AUD_VOL_IS_MUTE_LEVEL(volume_level))
        {
            volume_level = volume_level & 0x0F;
        }
        volLevel = volume_level;
        SetVolumeKeyHandlerFunctions(
            NULL,
            NULL,
            NULL,
            NULL,
            STR_GLOBAL_VOLUME,
            &volLevel,
            0,
            STR_GLOBAL_BACK,
            NULL,
            ExitScrSetKeyPadVolumeLevel,
            1000,
            SpeechVolumeExitFunction,
            0,
            VOLUMEHANDLER_SPEECH_TONE);
        isValid = 1;
    }
#endif

    /* setup volume key handler when entering related screens */    
    if(mmi_idle_is_active())
    {
        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_RING_VOL_LEVEL,&volume_level);
        if (MDI_AUD_VOL_IS_MUTE_LEVEL(volume_level))
        {
            volume_level = volume_level & 0x0F;
        }
        volLevel = volume_level;
        
        SetVolumeKeyHandlerFunctions(
            play_keypad_tone,
            play_keypad_tone,
            NULL,
            NULL,
            STR_GLOBAL_RINGTONE,
            &volLevel,
            0,
            STR_GLOBAL_BACK,
            NULL,
            ExitScrSetKeyPadVolumeLevel,
            2000,
            RingVolumeExitFunction,
            0,
            VOLUMEHANDLER_RING_TONE);
        isValid = 1;

        /* disable side key keytone played by framework */
        currKeyToneState = mmi_frm_kbd_get_key_tone_state();
        if (currKeyToneState != MMI_KEY_VOL_TONE_DISABLED)
        {
            /*key_tone_state = currKeyToneState;*/
            mmi_frm_kbd_set_tone_state(MMI_KEY_VOL_TONE_DISABLED);
        }
    }
    
    if (isValid)
    {
/*
        if (updownFlag)
        {
            SetKeyHandler(SetKeyPadVolUp, KEY_UP_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(SetKeyPadVolMaxLongPress, KEY_UP_ARROW, KEY_LONG_PRESS);
            SetKeyHandler(SetKeyPadVolDown, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(SetKeyPadVolMinLongPress, KEY_DOWN_ARROW, KEY_LONG_PRESS);
        }
*/
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

        SetKeyDownHandler(SetKeyPadVolUp, KEY_VOL_UP);
        SetKeyLongpressHandler(SetKeyPadVolMaxLongPress, KEY_VOL_UP);
        SetKeyDownHandler(SetKeyPadVolDown, KEY_VOL_DOWN);
        SetKeyLongpressHandler(SetKeyPadVolMinLongPress, KEY_VOL_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetVolumeKeyHandlerFunctions
 * DESCRIPTION
 *  Init Function to be called before using Volume Screen
 * PARAMETERS
 *  decreaseFunction        [IN]        Function to be called when volume down key is pressed.
 *  increaseFunction        [IN]        
 *  minFunction             [IN]        
 *  maxFunction             [IN]        
 *  caption                 [IN]        
 *  volume                  [?]         
 *  captionLSK              [IN]        
 *  captionRSK              [IN]        
 *  callbackLSK             [IN]        
 *  callbackRSK             [IN]        
 *  timerDuration           [IN]        
 *  callbackExit            [IN]        
 *  updown                  [IN]        
 *  type                    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetVolumeKeyHandlerFunctions(
        FuncPtr decreaseFunction,
        FuncPtr increaseFunction,
        FuncPtr minFunction,
        FuncPtr maxFunction,
        U16 caption,
        S32 *volume,
        U16 captionLSK,
        U16 captionRSK,
        FuncPtr callbackLSK,
        FuncPtr callbackRSK,
        U32 timerDuration,
        FuncPtr callbackExit,
        U8 updown,
        VOLUMEHANDLER_TYPE type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    volumeDecreaseFunction = decreaseFunction;
    volumeIncreaseFunction = increaseFunction;
    volumeMinFunction = minFunction;
    volumeMaxFunction = maxFunction;
    volumeCaption = caption;
    initialVolume = volume;
    LSKCaption = captionLSK;
    RSKCaption = captionRSK;
    LSKCallback = callbackLSK;
    RSKCallback = callbackRSK;
    volumeTimer = timerDuration;
    ExitCallback = callbackExit;
    updownFlag = updown;
    if (type == VOLUMEHANDLER_RING_TONE)
    {
        volume_type = VOLUMEHANDLER_RING_TONE;
        hardwareVolumeFunction = RingToneVolumeFunction;
    }
    else if (type == VOLUMEHANDLER_SPEECH_TONE)
    {
        volume_type = VOLUMEHANDLER_SPEECH_TONE;
        hardwareVolumeFunction = SpeechVolumeFunction;
    }
    else if (type == VOLUMEHANDLER_KEY_TONE)
    {
        volume_type = VOLUMEHANDLER_KEY_TONE;
        hardwareVolumeFunction = KeyToneVolumeFunction;
    }
    else
    {
        volume_type = VOLUMEHANDLER_RING_TONE;
        hardwareVolumeFunction = RingToneVolumeFunction;
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrSetKeyPadVolumeLevel
 * DESCRIPTION
 *  To Increase Volume level of keypad tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrSetKeyPadVolumeLevel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    /*FuncPtr EndKeyFuncPtr;*/
    mmi_id cur_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur_gid = mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, NULL, NULL,MMI_FRM_NODE_SMART_CLOSE_FLAG);

    if (!mmi_frm_scrn_enter(
	    cur_gid, 
	    SCR_KEY_TONE_VOLUME, 
	    StopKeyPadVolumeLevelTimer, 
	    NULL, 
	    MMI_FRM_FULL_SCRN))
    {
        return;
    }
    
    mmi_frm_send_incomplete_key_event_to_new_screen(MMI_TRUE);
    guiBuffer = mmi_frm_scrn_get_gui_buf(cur_gid, SCR_KEY_TONE_VOLUME);
    ShowCategory105Screen(
        volumeCaption,
            0,
        LSKCaption,
        0,
        RSKCaption,
        0,
        (S32*) initialVolume,
        guiBuffer);

    mmi_frm_kbd_set_tone_state(MMI_KEY_VOL_UP_DOWN_TONE_DISABLED);
    
    EndKeyFuncPtr = GetKeyHandler(KEY_END, KEY_EVENT_DOWN);

    if (volumeTimer)
    {
        SetGroupKeyHandler(ExitScrSetKeyPadVolumeLevel, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, (U16) KEY_EVENT_DOWN);
    }

    /*SetKeyHandler(EndKeyFuncPtr, KEY_END, KEY_EVENT_DOWN);*/

    SetLeftSoftkeyFunction(LSKCallback, KEY_EVENT_UP);
    SetRightSoftkeyFunction(RSKCallback, KEY_EVENT_UP);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#ifdef __MMI_BTD_BOX_UI_STYLE__
    SetKeyDownHandler(ShowVerticalBarUp, KEY_UP_ARROW);
    SetKeyLongpressHandler(ShowVerticalBarUp, KEY_UP_ARROW);
    SetKeyRepeatHandler(ShowVerticalBarUp, KEY_UP_ARROW);
    SetKeyDownHandler(ShowVerticalBarDown, KEY_DOWN_ARROW);
    SetKeyRepeatHandler(ShowVerticalBarDown, KEY_DOWN_ARROW);
    SetKeyLongpressHandler(ShowVerticalBarDown, KEY_DOWN_ARROW);
#else /* __MMI_BTD_BOX_UI_STYLE__ */
    SetKeyDownHandler(ShowVerticalBarUp, KEY_VOL_UP);
    SetKeyLongpressHandler(ShowVerticalBarMax, KEY_VOL_UP);
    SetKeyDownHandler(ShowVerticalBarDown, KEY_VOL_DOWN);
    SetKeyLongpressHandler(ShowVerticalBarMin, KEY_VOL_DOWN);
#endif /*__MMI_BTD_BOX_UI_STYLE__ */

    if (!mmi_frm_kbd_is_key_supported(KEY_VOL_UP) && !mmi_frm_kbd_is_key_supported(KEY_VOL_DOWN))
    {
        updownFlag = 1;
    }

    if (updownFlag)
    {
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    #ifdef __MMI_BTD_BOX_UI_STYLE__    
        SetKeyLongpressHandler(ShowVerticalBarUp, KEY_UP_ARROW);
        SetKeyRepeatHandler(ShowVerticalBarUp, KEY_UP_ARROW);
        SetKeyRepeatHandler(ShowVerticalBarDown, KEY_DOWN_ARROW);
        SetKeyLongpressHandler(ShowVerticalBarDown, KEY_DOWN_ARROW);
    #else /* __MMI_BTD_BOX_UI_STYLE__ */
        SetKeyDownHandler(ShowVerticalBarUp, KEY_RIGHT_ARROW);
        SetKeyLongpressHandler(ShowVerticalBarMax, KEY_RIGHT_ARROW);
        SetKeyDownHandler(ShowVerticalBarDown, KEY_LEFT_ARROW);
        SetKeyLongpressHandler(ShowVerticalBarMin, KEY_LEFT_ARROW);
    #endif /* __MMI_BTD_BOX_UI_STYLE__ */
    }

    if (volumeTimer)
    {
        StartTimer(KEY_VOL_TIMER_ID, KEY_VOLUME_TIMEOUT, ExitScrSetKeyPadVolumeLevel);
    }

    /* SetExitHandler(SCR_KEY_TONE_VOLUME,StopKeyPadVolumeLevelTimer); */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_volume_hdlr_key_pad_vol
 * DESCRIPTION
 *  To Increase/decrease Volume level of keypad tone and pass the key event to other app if they are activated
 * PARAMETERS
 *  is_vol_button_up [IN]    TRUE means volume button up pressed FALSE means volume button down pressed
 *  is_long_press    [IN]    TRUE means key long press
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_volume_hdlr_key_pad_vol(MMI_BOOL is_vol_up_button, MMI_BOOL is_long_press)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AUDIO_PLAYER__
    if (mmi_audply_is_playing())
    {
        if (is_vol_up_button == MMI_TRUE)
        {
            mmi_audply_press_inc_volume();
        }
        else
        {
            mmi_audply_press_dec_volume();
        }
    }
    else
#endif /* __MMI_AUDIO_PLAYER__ */ 
#ifdef __MMI_MEDIA_PLAYER__
    if (mmi_medply_is_play_activated())
    {
        if (is_vol_up_button == MMI_TRUE)
        {
            mmi_medply_inc_volume();
        }
        else
        {
            mmi_medply_dec_volume();
        }
    }
    else
#endif /*__MMI_MEDIA_PLAYER__*/
#ifdef __MMI_FM_RADIO__
    if (mmi_fmrdo_is_power_on())
    {
        if (is_vol_up_button == MMI_TRUE)
        {
            mmi_fmrdo_inc_volume();
        }
        else
        {
            mmi_fmrdo_dec_volume();
        }
    }
    else
#endif /* __MMI_FM_RADIO__ */ 
#if defined(__J2ME__) && defined(J2ME_SUPPORT_BACKGROUND)
    if (jma_audio_player_is_really_active())
    {
        if (is_vol_up_button == MMI_TRUE)
        {
            jam_press_inc_volume_level();
        }
        else
        {
             jam_press_dec_volume_level();
        }
    }
    else
#endif /* defined(__J2ME__) && defined(J2ME_SUPPORT_BACKGROUND) */
#ifdef __A8BOX_SUPPORT__
    if(mmi_a8box_is_playing())
    {
        if (is_vol_up_button == MMI_TRUE)
        {
            mmi_a8box_volume_up();
        }
        else
        {
            mmi_a8box_volume_down();
        }
    }
    else
#endif /* __A8BOX_SUPPORT__ */
#ifdef __GADGET_SUPPORT__
    if (gadget_adp_audio_service_audio_playing())
    {
        if (is_vol_up_button == MMI_TRUE)
        {
            gadget_adp_audio_service_adjust_volume(1);
        }
        else
        {
            gadget_adp_audio_service_adjust_volume(0);
        }
    }
    else
#endif /* __GADGET_SUPPORT__ */
#if defined(__MMI_BT_MUSIC__) || defined(__MMI_AUDIO_PLAYER_BT__)
    if (mmi_bt_music_is_playing())
    {
        if (is_vol_up_button == MMI_TRUE)
        {
            mmi_bt_music_inc_vol();
        }
        else
        {
            mmi_bt_music_dec_vol();
        }
    }
    else
#endif
    {
        if (srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) != SRV_PROF_RET_PROFILE_ACTIVATED ||
            hardwareVolumeFunction == SpeechVolumeFunction)
        {
            if (mmi_frm_scrn_get_active_id() != SCR_KEY_TONE_VOLUME)
                EntryScrSetKeyPadVolumeLevel();

        #ifndef __MMI_BTD_BOX_UI_STYLE__
            if(is_long_press == MMI_TRUE)
            {
                if (is_vol_up_button == MMI_TRUE)
                {
                    ShowVerticalBarMax();
                }
                else
                {
                     ShowVerticalBarMin();
                }
            }
            else
        #endif /* __MMI_BTD_BOX_UI_STYLE__ */
            {
                if (is_vol_up_button == MMI_TRUE)
                {
                    ShowVerticalBarUp();
                }
                else
                {
                    ShowVerticalBarDown();
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetKeyPadVolDown
 * DESCRIPTION
 *  To Increase Volume level of keypad tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetKeyPadVolDown(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* call the volume key pad down function with volume up button false and long press false */
    mmi_volume_hdlr_key_pad_vol(MMI_FALSE, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  SetKeyPadVolUp
 * DESCRIPTION
 *  To Increase Volume level of keypad tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetKeyPadVolUp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* call the volume key pad up function with volume up button true and long press false */
    mmi_volume_hdlr_key_pad_vol(MMI_TRUE, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  SetKeyPadVolMinLongPress
 * DESCRIPTION
 *  To Increase Volume level of keypad tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetKeyPadVolMinLongPress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* call the volume key pad down function with volume up button false and long press true */
    mmi_volume_hdlr_key_pad_vol(MMI_FALSE, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  SetKeyPadVolMaxLongPress
 * DESCRIPTION
 *  To Increase Volume level of keypad tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetKeyPadVolMaxLongPress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* call the volume key pad up function with volume up button true and long press true */
    mmi_volume_hdlr_key_pad_vol(MMI_TRUE, MMI_TRUE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_volume_hdlr_check_app_status
 * DESCRIPTION
 *  Gives the status of apps, if any app is active returns MMI_TRUE
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_volume_hdlr_check_app_status()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL app_status = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AUDIO_PLAYER__
    if (mmi_audply_is_playing())
    {
        app_status = MMI_TRUE;
    }
    else
#endif /* __MMI_AUDIO_PLAYER__ */ 
#ifdef __MMI_MEDIA_PLAYER__
    if (mmi_medply_is_play_activated())
    {
        app_status = MMI_TRUE;
    }
    else
#endif /*__MMI_MEDIA_PLAYER__*/
#ifdef __MMI_FM_RADIO__
    if (mmi_fmrdo_is_power_on())
    {
        app_status = MMI_TRUE;
    }
    else
#endif /* __MMI_FM_RADIO__ */ 
#if defined(__J2ME__) && defined(J2ME_SUPPORT_BACKGROUND)
    if (jma_audio_player_is_really_active())
    {
        app_status = MMI_TRUE;
    }
    else
#endif /* defined(__J2ME__) && defined(J2ME_SUPPORT_BACKGROUND) */
#ifdef __A8BOX_SUPPORT__
    if(mmi_a8box_is_playing())
    {
        app_status = MMI_TRUE;
    }
    else
#endif /* __A8BOX_SUPPORT__ */
#ifdef __GADGET_SUPPORT__
    if (gadget_adp_audio_service_audio_playing())
    {
        app_status = MMI_TRUE;
    }
    else
#endif /* __GADGET_SUPPORT__ */
    {
        app_status = MMI_FALSE;
    }

    return app_status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_volume_hdlr_show_vertical_bar
 * DESCRIPTION
 *  To Increase/decrease Volume level of keypad tone (mics) on key volume key UP/DOWN and show the volume bar
 * PARAMETERS
 *  mmi_volume_hdlr_vertical_bar_type    [IN]    represent the type of verical bar to show
 *                                               VERTICAL_BAR_UP    Volume key up
 *                                               VERTICAL_BAR_DOWN    Volume key down
 *                                               VERTICAL_BAR_MAX    Volume key up long press [?]
 *                                               VERTICAL_BAR_MIN    Volume key long press [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_volume_hdlr_show_vertical_bar(mmi_volume_hdlr_vertical_bar_type bar_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (volumeTimer)
    {
        StopTimer(KEY_VOL_TIMER_ID);
    }

    switch (bar_type)
    {
        case VERTICAL_BAR_UP:
            show_vertical_bar_next();
            break;
        case VERTICAL_BAR_DOWN:
            show_vertical_bar_previous();
            break;
        case VERTICAL_BAR_MAX:
            show_vertical_bar(MDI_AUD_VOL_6 + 1);
            break;
        case VERTICAL_BAR_MIN:
            show_vertical_bar(MDI_AUD_VOL_0); // MDI_AUD_VOL_0 is mute here
            break;
        default :
            /* return in case not in above */
            return;
    }
    
    *initialVolume = volume_level_UI;
    
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        RingVolumeExitFunction();
    }
    else if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 &&
             srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CSD_CALL_TYPE_ALL, NULL) <= 0)
    {
        SpeechVolumeExitFunction();
    }
#ifdef __MMI_HF_SUPPORT__
    if (srv_ucm_bt_query_call_count(SRV_UCM_BT_INCOMING_STATE, NULL) > 0)
    {
        RingVolumeExitFunction();
    }
    else if(srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_CONNECTED, NULL) > 0)
    {
        SpeechVolumeExitFunction();
    }
#endif // __MMI_HF_SUPPORT__
    /* check if any app is active in meanwhile, if not then only call volume set */
    /* But if the volume type is Key then need to call volume set - currently Key will only be called from Profiles - Idle is Ring */
    if(mmi_volume_hdlr_check_app_status() == MMI_FALSE || volume_type == VOLUMEHANDLER_KEY_TONE)
    {
        hardwareVolumeFunction();
        switch (bar_type)
        {
            case VERTICAL_BAR_UP:
                {
                    if (volumeIncreaseFunction)
                    {
                        volumeIncreaseFunction();
                    }
                }
                break;
            case VERTICAL_BAR_DOWN:
                {
                    if (volumeDecreaseFunction)
                    {
                        volumeDecreaseFunction();
                    }
                }
                break;
            case VERTICAL_BAR_MAX:
                {
                    if (volumeMaxFunction)
                    {
                        volumeMaxFunction();
                    }
                }
                break;
            case VERTICAL_BAR_MIN:
                {
                    if (volumeMinFunction)
                    {
                        volumeMinFunction();
                    }
                }
                break;
            default :
                /* return in case not in above */
                return;
            }
    }

    if (volumeTimer)
    {
        StartTimer(KEY_VOL_TIMER_ID, KEY_VOLUME_TIMEOUT, ExitScrSetKeyPadVolumeLevel);
    }
}

/*****************************************************************************
 * FUNCTION
 *  ShowVerticalBarUp
 * DESCRIPTION
 *  To Increase Volume level of keypad tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowVerticalBarUp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_volume_hdlr_show_vertical_bar(VERTICAL_BAR_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ShowVerticalBarDown
 * DESCRIPTION
 *  To Increase Volume level of keypad tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowVerticalBarDown(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_volume_hdlr_show_vertical_bar(VERTICAL_BAR_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  ShowVerticalBarMax
 * DESCRIPTION
 *  To Increase Volume level of keypad tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowVerticalBarMax(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_volume_hdlr_show_vertical_bar(VERTICAL_BAR_MAX);
}


/*****************************************************************************
 * FUNCTION
 *  ShowVerticalBarMin
 * DESCRIPTION
 *  To Increase Volume level of keypad tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowVerticalBarMin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_volume_hdlr_show_vertical_bar(VERTICAL_BAR_MIN);
}


/*****************************************************************************
 * FUNCTION
 *  StopKeyPadVolumeLevelTimer
 * DESCRIPTION
 *  To Increase Volume level of keypad tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StopKeyPadVolumeLevelTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
    if (volumeTimer)
    {
        StopTimer(KEY_VOL_TIMER_ID);
    }
    if (ExitCallback)
    {
        ExitCallback();
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitScrSetKeyPadVolumeLevel
 * DESCRIPTION
 *  To Increase Volume level of keypad tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrSetKeyPadVolumeLevel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (volumeTimer)
    {
        StopTimer(KEY_VOL_TIMER_ID);
    }
#if 0
/* under construction !*/
#endif

    SetKeyDownHandler(EndKeyFuncPtr, KEY_END);
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  SpeechVolumeFunction
 * DESCRIPTION
 *  Sets Default Volume Handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SpeechVolumeFunction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_set_volume(MDI_VOLUME_SPH,(U8)MDI_AUD_VOL_MUTE((U8)volume_level_UI));
#ifdef __MMI_VIDEO_TELEPHONY__
    mmi_ucm_vt_volume_change_cb();
#endif		
//#ifdef __MMI_BT_SUPPORT__
//    mmi_bt_set_headset_speaker_volume(volume_level_UI);
//#endif 

}


/*****************************************************************************
 * FUNCTION
 *  RingToneVolumeFunction
 * DESCRIPTION
 *  Ring Tone Volume Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RingToneVolumeFunction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_set_volume(VOL_TYPE_MEDIA, (U8)MDI_AUD_VOL_MUTE((U8)volume_level_UI));

//#ifdef __MMI_BT_SUPPORT__
//    mmi_bt_set_headset_speaker_volume(volume_level_UI);
//#endif 

}

/*****************************************************************************
 * FUNCTION
 *  KeyToneVolumeFunction
 * DESCRIPTION
 *  Key Tone Volume Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void KeyToneVolumeFunction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_set_volume(VOL_TYPE_KEY, (U8)MDI_AUD_VOL_MUTE((U8)volume_level_UI));

//#ifdef __MMI_BT_SUPPORT__
//    mmi_bt_set_headset_speaker_volume(volume_level_UI);
//#endif 

}

/*****************************************************************************
 * FUNCTION
 *  mmi_vol_set_speech_vol
 * DESCRIPTION
 *  get speech vol
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_vol_get_speech_vol(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MDI_AUD_VOL_GET_EX_LEVEL(srv_speech_get_mode_volume());
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vol_set_speech_vol
 * DESCRIPTION
 *  set speech vol
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vol_set_speech_vol(U8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_speech_set_volume(MDI_AUD_VOL_MUTE(volume));
    srv_speech_save_mode_volume(MDI_AUD_VOL_MUTE(volume));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vol_set_ring_vol
 * DESCRIPTION
 *  set ring vol
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vol_set_ring_vol(U8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_set_volume(VOL_TYPE_MEDIA, (U8)MDI_AUD_VOL_MUTE(volume));
    srv_prof_set_current_profile_value(SRV_PROF_SETTINGS_RING_VOL_LEVEL, (void*)&volume);
}

/*****************************************************************************
 * FUNCTION
 *  SpeechVolumeExitFunction
 * DESCRIPTION
 *  Speech volume Exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SpeechVolumeExitFunction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_speech_save_mode_volume((U8)MDI_AUD_VOL_MUTE((U8)volume_level_UI));
}


/*****************************************************************************
 * FUNCTION
 *  RingVolumeExitFunction
 * DESCRIPTION
 *  Ring volume Exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RingVolumeExitFunction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 volume = volume_level_UI;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_prof_set_current_profile_value(SRV_PROF_SETTINGS_RING_VOL_LEVEL, (void*)&volume);
}


/*****************************************************************************
 * FUNCTION
 *  KeyPadVolumeFunction
 * DESCRIPTION
 *  Keypad volume function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void KeyPadVolumeFunction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (volume_level_UI > 0)
    {
        srv_gpio_set_keypad_volume(volume_level_UI - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  KeyPadVolumeExitFunction
 * DESCRIPTION
 *  KeyPad Volume Exit Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void KeyPadVolumeExitFunction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 volume = volume_level_UI;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_prof_set_current_profile_value(SRV_PROF_SETTINGS_KEYPAD_VOL_LEVEL, (void*)&volume);
}

/* PMT HIMANSHU START 20050729 */
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WALLPAPER_ON_BOTTOM__)


/*****************************************************************************
 * FUNCTION
 *  CallShowVerticalBarMax
 * DESCRIPTION
 *  Callback function for time synchronization of KEY_LONG_PRESS
 *  and MMI_PEN_EVENT_LONG_TAP event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CallShowVerticalBarMax(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (volumeTimer)
    {
        StopTimer(KEY_VOL_TIMER_ID);
    }
    callback_timer++;
    if (callback_timer >= LONGPRESS_DELAY)
    {
        ShowVerticalBarMax();
        callback_timer = 0;
    }
    if (volumeTimer)
    {
        StartTimer(KEY_VOL_TIMER_ID, KEY_VOLUME_TIMEOUT, ExitScrSetKeyPadVolumeLevel);
    }
}


/*****************************************************************************
 * FUNCTION
 *  CallShowVerticalBarMin
 * DESCRIPTION
 *  Callback function for time synchronization of KEY_LONG_PRESS
 *  and MMI_PEN_EVENT_LONG_TAP event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CallShowVerticalBarMin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (volumeTimer)
    {
        StopTimer(KEY_VOL_TIMER_ID);
    }
    callback_timer++;
    if (callback_timer >= LONGPRESS_DELAY)
    {
        ShowVerticalBarMin();
        callback_timer = 0;
    }
    if (volumeTimer)
    {
        StartTimer(KEY_VOL_TIMER_ID, KEY_VOLUME_TIMEOUT, ExitScrSetKeyPadVolumeLevel);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ResetCallbackTimer
 * DESCRIPTION
 *  Callback function of PEN_EVENT_UP event for reseting the
 *  synchronization variable.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetCallbackTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callback_timer = 0;
}

#endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
/* PMT HIMANSHU END 20050729 */

