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
*  ProfilesApp.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Profiles app.
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
*
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "MMI_features.h"

#ifndef __OP01_FWPBW__

#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "GlobalResDef.h"
#include "ProfilesSrvGprot.h"
#include "app_mem.h"
#include "wgui_categories_util.h"
#include "nvram_common_defs.h"
#include "common_nvram_editor_data_item.h"
#include "mmi_frm_nvram_gprot.h"
#include "CustDataRes.h"
#include "Unicodexdcl.h"
#include "CustMenuRes.h"
#include "mmi_rp_file_type_def.h"
#include "mmi_frm_events_gprot.h"
#include "gui_data_types.h"
#include "AlertScreen.h"
#include "MMI_media_app_trc.h"
#include "mmi_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "gui_typedef.h"
#include "Wgui_inputs.h"
#include "wgui_inline_edit.h"
#include "kal_public_api.h"
#include "device.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_timer_gprot.h"
#include "CommonScreensResDef.h"
#include "ImeGprot.h"
#include "fs_type.h"
#include "drm_def.h"
#include "fs_errcode.h"

#include "custom_mmi_default_value.h"
#include "mmi_media_app_trc.h"
#include "mmi_theme_mgr.h"
/*  END RHR*/

//#include "MMI_include.h"

//#include "MainMenuDef.h"
#include "menucuigprot.h"
//#include "FileMgrGProt.h"
#include "Filemgrsrvgprot.h"

#ifdef __MMI_FILE_MANAGER__
#include "mmi_rp_app_filemanager_def.h"
#endif 
//#include "UCMGProt.h"
#include "UcmSrvGprot.h"
//#include "CommonScreens.h"
#include "inlinecuigprot.h"
#include "fseditorcuigprot.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "DRM_gprot.h"
#include "bootupsrvgprot.h"
#include "custom_equipment.h"

//#include "GeneralDeviceGprot.h"
//#include "Gpiosrvgprot.h"

#include "ProfilesSrv.h"
#include "custom_srv_prof_defs.h"

#include "mmi_rp_app_profiles_def.h"
#include "Mmi_rp_srv_prof_def.h"

#include "ToneSelectorCuiGprot.h"
#include "ProfilesAppGprot.h"
#include "gui_touch_feedback.h"
#include "VolumeHandler.h"

// TODO: Should be remove the following include statement?
#include "resource_audio.h"

// Dynamic UI related
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
#include "NetsetAppGprot.h"
#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGProt.h"
#endif

//Profiles DCM header file
#if defined (__DCM_WITH_COMPRESSION_MMI_AP__) && defined(__MTK_TARGET__)
#include "MMI_ap_dcm_config.h"
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
/*#ifndef HARDWARE_LED_NOT_SUPPORT
#define HARDWARE_LED_NOT_SUPPORT
#endif*/
/*conflict with HAL rules,  to compatible with previous versions, 
*  define HW_LED_NOT_SUPPORT insdead
* any project need support Hardware led, modify this define
*/
#define HW_LED_NOT_SUPPORT 1

/*
  Call alerts and msg alerts support
*/
#if defined(__MMI_TELEPHONY_SUPPORT__) || defined(__MMI_BT_CALL_SUPPORT__)
    #define __MMI_PROF_CALL_ALERTS_SUPPORT__
#endif

#if defined(__MMI_TELEPHONY_SUPPORT__)
    #define __MMI_PROF_MSG_ALERTS_SUPPORT__
#endif

/* This enum defined the ring type */
typedef enum
{
    MMI_PROF_RING_TYPE_REPEAT,         /* Ringing */
#ifdef __MMI_AUDIO_CRESCENDO_SUPPORT__        
    MMI_PROF_RING_TYPE_ASCENDING,      /* Acending */
#endif    
    MMI_PROF_RING_TYPE_BEEP_ONCE,      /* Beep once */
    MMI_PROF_RING_TYPE_NUM     /* End of enum */
}mmi_prof_ring_type_enum;

typedef enum
{
    MMI_PROF_ALERT_TYPE_RING,           /* Ringing */
    MMI_PROF_ALERT_TYPE_VIB_ONLY,       /* Vibrate only */
    MMI_PROF_ALERT_TYPE_VIB_AND_RING,   /* Vibrate and ring */
    MMI_PROF_ALERT_TYPE_VIB_THEN_RING,  /* Vibrate then ring */
    MMI_PROF_ALERT_TYPE_NUM     /* End of enum */
}mmi_prof_alert_type_enum;

typedef enum
{
    MMI_PROF_TOUCH_VIB_OFF,         /* off */
    MMI_PROF_TOUCH_VIB_LEVEL_1,     
    MMI_PROF_TOUCH_VIB_LEVEL_2,     
    MMI_PROF_TOUCH_VIB_LEVEL_3,    
    MMI_PROF_TOUCH_VIB_LEVEL_TOTAL  
}mmi_prof_touch_vib_level_enum;

typedef enum
{
    MMI_PROF_ON,
    MMI_PROF_OFF
}mmi_prof_on_off_setting_enum;


#define MMI_PROF_ON_OFF_ITEM_NUM            (2)
#define MMI_PROF_PROFILE_NAME_LENGTH        (20)
#define MMI_PROF_TOUCH_VOL_MAX_VALUE        (4)


#if !defined(HW_LED_NOT_SUPPORT)    
#define MMI_PROF_STATUS_LED_NUM             (SRV_PROF_LED_PATTERN_END_OF_ENUM)
#endif

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
typedef enum
{
    MMI_PROF_TONE_ID_BEGIN      = AUD_ID_PROF_TONE_BEGIN + 1, 
    MMI_PROF_TONE_ID_END        = AUD_ID_PROF_TONE_END,
    MMI_PROF_TONE_ID_NUM        = MMI_PROF_TONE_ID_END - MMI_PROF_TONE_ID_BEGIN,
    MMI_PROF_RING_ID_BEGIN      = AUD_ID_PROF_RING_BEGIN + 1, 
    MMI_PROF_RING_ID_END        = AUD_ID_PROF_RING_END,
    MMI_PROF_RING_ID_NUM        = MMI_PROF_RING_ID_END - MMI_PROF_RING_ID_BEGIN,
    MMI_PROF_EXT_AUDIO_ID_BEGIN = AUD_ID_PROF_EXT_BEGIN + 1, 
    MMI_PROF_EXT_AUDIO_ID_END   = AUD_ID_PROF_EXT_END,
    MMI_PROF_EXT_AUDIO_ID_NUM   = MMI_PROF_EXT_AUDIO_ID_END - MMI_PROF_EXT_AUDIO_ID_BEGIN,
} mmi_prof_audio_id_enum;

/* This enum defined the keypad tone type for UI*/
typedef enum
{
    MMI_PROF_KEYPAD_SILENT,             /*silent*/
    MMI_PROF_KEYPAD_CLICK,              /* Click */
    MMI_PROF_KEYPAD_TONE,               /* Tone */
#if defined( __MMI_HUMAN_VOICE_KEYPAD_TONE__ )    
    MMI_PROF_KEYPAD_NUM_1,              /* Special number key 1 */
#endif
#if defined( __MMI_CUST_KEYPAD_TONE__ )
    MMI_PROF_KEYPAD_CUST_1,             /* Customer 1 */
#endif
    MMI_PROF_KEYPAD_TONE_NUM 
}mmi_prof_keypad_tone_type_enum;


typedef enum
{
#ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__
    ALERT_TYPE_CAPTION   = 0, 
    ALERT_TYPE_ITEM,

    RING_TYPE_CAPTION,
    RING_TYPE_ITEM,

    SIM1_RING_TONE_CAPTION,
    SIM1_RING_TONE_ITEM,

#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
    SIM2_RING_TONE_CAPTION,
    SIM2_RING_TONE_ITEM,
#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
    SIM3_RING_TONE_CAPTION,
    SIM3_RING_TONE_ITEM,
#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
    SIM4_RING_TONE_CAPTION,
    SIM4_RING_TONE_ITEM,
#endif
#endif
#endif

#ifdef __MMI_VIDEO_TELEPHONY__    
    VIDEO_CALL_TONE_CAPTION,
    VIDEO_CALL_TONE_ITEM,
#endif

    RING_VOL_CAPTION,
    RING_VOL_ITEM,
#endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */

#ifdef __MMI_PROF_MSG_ALERTS_SUPPORT__
#ifndef __MMI_PROF_SPLIT_MSG_TONES__    
    SIM1_MSG_TONE_CAPTION,
    SIM1_MSG_TONE_ITEM,
#else /*__MMI_PROF_SPLIT_MSG_TONES__*/
    SMS_TONE_CAPTION,
    SMS_TONE_ITEM,
    #ifdef MMS_SUPPORT    
    MMS_TONE_CAPTION,
    MMS_TONE_ITEM,
    #endif
    #ifdef __MMI_EMAIL__
    EMAIL_TONE_CAPTION,
    EMAIL_TONE_ITEM,
    #endif
    #ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
/* under construction !*/
    #endif
#endif /*__MMI_PROF_SPLIT_MSG_TONES__*/

#if (SRV_PROF_SMS_TONE_AMOUNT > 1)
    SIM2_MSG_TONE_CAPTION,
    SIM2_MSG_TONE_ITEM,
#if (SRV_PROF_SMS_TONE_AMOUNT > 2)
    SIM3_MSG_TONE_CAPTION,
    SIM3_MSG_TONE_ITEM,
#if (SRV_PROF_SMS_TONE_AMOUNT > 3)
    SIM4_MSG_TONE_CAPTION,
    SIM4_MSG_TONE_ITEM,
#endif
#endif
#endif

#if !(defined(__MMI_MAINLCD_96X64__) || defined(__MMI_PROF_SLIM_PROFILES__))
    MSG_VOL_CAPTION,
    MSG_VOL_ITEM,
#endif    // __MMI_MAINLCD_96X64__

#endif /* __MMI_PROF_MSG_ALERTS_SUPPORT__ */

    KEYPAD_TONE_CAPTION,
    KEYPAD_TONE_ITEM,
    KEYPAD_VOL_CAPTION,
    KEYPAD_VOL_ITEM,

#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if !defined(__MMI_POWER_ON_OFF_MUTE__) && !defined(__MMI_POWER_ON_OFF_NO_CUSTOMIZE__)
    POWER_ON_TONE_CAPTION,
    POWER_ON_TONE_ITEM,
    POWER_OFF_TONE_CAPTION,
    POWER_OFF_TONE_ITEM,
#endif

#ifdef __MMI_CLAMSHELL__
    COVER_OPEN_TONE_CAPTION,
    COVER_OPEN_TONE_ITEM,
    COVER_CLOSE_TONE_CAPTION,
    COVER_CLOSE_TONE_ITEM,
#endif

#if !(defined(__MMI_MAINLCD_96X64__) || defined(__MMI_PROF_SLIM_PROFILES__))
    SYSTEM_ALERT_CAPTION,
    SYSTEM_ALERT_ITEM,
#endif    // __MMI_MAINLCD_96X64__

#ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__

#if defined(__MMI_INTELLIGENT_CALL_ALERT__)    
    INTELLIGENT_CALL_ALERT_CAPTION,
    INTELLIGENT_CALL_ALERT_ITEM,
#endif

#endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */

#if !defined(HW_LED_NOT_SUPPORT)    
    STATUS_LED_CAPTION,
    STATUS_LED_ITEM,
#endif

    INLINE_ITEM_END,
    PROFILE_INLINE_ITEM_NUM = INLINE_ITEM_END
} profile_app_item_enum;

typedef struct
{
    U16 ring_tone[SRV_PROF_MT_CALL_TONE_AMOUNT];

#ifdef __MMI_VIDEO_TELEPHONY__    
    U16 video_tone;
#endif

    U16 alert_type;
    U16 ring_type;

    U16 ring_vol;
#ifndef __MMI_PROF_SPLIT_MSG_TONES__
    U16 msg_tone[SRV_PROF_SMS_TONE_AMOUNT];
#else /*__MMI_PROF_SPLIT_MSG_TONES__*/
    U16 sms_tone;
    #ifdef MMS_SUPPORT    
    U16 mms_tone;
    #endif
    #ifdef __MMI_EMAIL__
    U16 email_tone;
    #endif
    #ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
    #endif
#endif /*__MMI_PROF_SPLIT_MSG_TONES__*/

#if !(defined(__MMI_MAINLCD_96X64__) || defined(__MMI_PROF_SLIM_PROFILES__))
    U16 msg_vol;
#endif    // __MMI_MAINLCD_96X64__

    U16 keypad_tone;
    U16 keypad_vol;

#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif
    
#if !defined(__MMI_POWER_ON_OFF_MUTE__) && !defined(__MMI_POWER_ON_OFF_NO_CUSTOMIZE__)
    U16 power_on_tone;
    U16 power_off_tone;
#endif

#ifdef __MMI_CLAMSHELL__
    U16 cover_open_tone;
    U16 cover_close_tone;
#endif

#if !(defined(__MMI_MAINLCD_96X64__) || defined(__MMI_PROF_SLIM_PROFILES__))
    U16 system_alert;
#endif    // __MMI_MAINLCD_96X64__

#if defined(__MMI_INTELLIGENT_CALL_ALERT__)    
    U16 intelligent_call_alert;
#endif
#if !defined(HW_LED_NOT_SUPPORT)    
    U16 status_led;
#endif
} profile_setting_struct;


typedef struct
{
    profile_setting_struct cur_setting;

#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
    WCHAR	ring_tone_path[SRV_PROF_MT_CALL_TONE_AMOUNT][SRV_FMGR_PATH_MAX_LEN + 1];
    WCHAR	ring_filename[SRV_PROF_MT_CALL_TONE_AMOUNT][SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
    
#ifdef __MMI_VIDEO_TELEPHONY__
    WCHAR	video_call_tone_path[SRV_FMGR_PATH_MAX_LEN + 1];
    WCHAR	video_call_filename[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
#endif
#endif    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */
    U16	    item_id;
    U16     volume;
    U16     playing_audio_id;
    mmi_id  inline_gid;
    MMI_BOOL	is_playing;
#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
#ifdef __MMI_TOUCH_FEEDBACK_VIBRATE_LEVEL_SUPPORT__
/* under construction !*/
#endif
#endif
} profile_mem_struct;

typedef struct
{
#if !defined(__MMI_PROF_BASIC_UI_STYLE__) && !defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
    WCHAR       my_style_name[MMI_PROF_PROFILE_NAME_LENGTH + 1];
    MMI_BOOL    is_default_name;
#elif defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
    WCHAR new_name[10][MMI_PROF_PROFILE_NAME_LENGTH + 1];
    U8 flag[10];
    MMI_BOOL add_flag;
#endif
    U8  curr_profile;
    U8  activated_profile;
} profile_cntx_struct;


/***************************************************************************** 
 * Local Variable
 *****************************************************************************/
#ifdef __MMI_AP_DCM_PROFILE__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif

static profile_mem_struct * g_prof_mem_p = NULL;
static profile_cntx_struct g_prof;
#ifdef __GAIN_TABLE_SUPPORT__
static U16 g_curr_tone_setting_type =MMI_PROF_TYPE_OTHERS;
#endif
static const cui_inline_item_caption_struct prof_item_caption[PROFILE_INLINE_ITEM_NUM / 2] = 
{
#ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__
    STR_ID_PROF_ALERT_TYPE,                     //ALERT_TYPE_CAPTION 
    STR_ID_PROF_RING_TYPE,                      //RING_TYPE_CAPTION,

#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)   
    STR_ID_PROF_SIM1_RING_TONE,
#else
    STR_ID_PROF_RING_TONE,                      //SIM1_RING_TONE_CAPTION,
#endif

#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
    STR_ID_PROF_SIM2_RING_TONE,                 //SIM2_RING_TONE_CAPTION,
#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
    STR_ID_PROF_SIM3_RING_TONE,                 //SIM2_RING_TONE_CAPTION,
#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
    STR_ID_PROF_SIM4_RING_TONE,                 //SIM2_RING_TONE_CAPTION,
#endif
#endif
#endif

#ifdef __MMI_VIDEO_TELEPHONY__    
    STR_GLOBAL_DIAL_VIDEO_CALL,                //VIDEO_CALL_TONE_CAPTION,
#endif

    STR_ID_PROF_RING_VOL,                       //RING_VOL_CAPTION,

#endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */

#ifdef __MMI_PROF_MSG_ALERTS_SUPPORT__
#ifndef __MMI_PROF_SPLIT_MSG_TONES__ 

    #if SRV_PROF_SMS_TONE_AMOUNT > 1   
    STR_ID_PROF_SIM1_MSG_TONE,                  //SIM1_MSG_TONE_CAPTION,
    #else
    STR_GLOBAL_MESSAGE,                       //SIM1_MSG_TONE_CAPTION,
    #endif
    
#else /*__MMI_PROF_SPLIT_MSG_TONES__*/
    STR_GLOBAL_TEXT_MESSAGE,                    //SMS_TONE_CAPTION,

    #ifdef MMS_SUPPORT    
    STR_GLOBAL_MMS,                       //MMS_TONE_CAPTION,
    #endif
    
    #ifdef __MMI_EMAIL__
    STR_GLOBAL_EMAIL,                           //EMAIL_TONE_CAPTION,
    #endif
    #ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
    #endif
#endif /*__MMI_PROF_SPLIT_MSG_TONES__*/

#if (SRV_PROF_SMS_TONE_AMOUNT > 1)
    STR_ID_PROF_SIM2_MSG_TONE,             //SIM2_MSG_TONE_CAPTION,
#if (SRV_PROF_SMS_TONE_AMOUNT > 2)
		STR_ID_PROF_SIM3_MSG_TONE, 				//SIM2_MSG_TONE_CAPTION,
#if (SRV_PROF_SMS_TONE_AMOUNT > 3)
		STR_ID_PROF_SIM4_MSG_TONE, 				//SIM2_MSG_TONE_CAPTION,
#endif
#endif
#endif


#if !(defined(__MMI_MAINLCD_96X64__) || defined(__MMI_PROF_SLIM_PROFILES__))
    STR_ID_PROF_MSG_VOL,                    //MSG_VOL_CAPTION,
#endif    // __MMI_MAINLCD_96X64__

#endif /* __MMI_PROF_MSG_ALERTS_SUPPORT__ */

    STR_ID_PROF_KEYPAD_TONE,                //KEYPAD_TONE_CAPTION,
    STR_ID_PROF_KEYPAD_VOL                 //KEYPAD_VOL_CAPTION,

#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
#endif

#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
#endif

#if !defined(__MMI_POWER_ON_OFF_MUTE__) && !defined(__MMI_POWER_ON_OFF_NO_CUSTOMIZE__)
    ,STR_ID_PROF_POWER_ON_TONE,              //POWER_ON_TONE_CAPTION,
    STR_ID_PROF_POWER_OFF_TONE             //POWER_OFF_TONE_CAPTION,
#endif

#ifdef __MMI_CLAMSHELL__
    ,STR_ID_PROF_COVER_OPEN_TONE,            //COVER_OPEN_TONE_CAPTION,
    STR_ID_PROF_COVER_CLOSE_TONE           //COVER_CLOSE_TONE_CAPTION,
#endif

#if !(defined(__MMI_MAINLCD_96X64__) || defined(__MMI_PROF_SLIM_PROFILES__))
    ,STR_ID_PROF_SYSTEM_ALERT                //SYSTEM_ALERT_CAPTION,
#endif    // __MMI_MAINLCD_96X64__

#ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__

#if defined(__MMI_INTELLIGENT_CALL_ALERT__)    
    ,STR_ID_PROF_INTELLIGENT_CALL_ALERT    //INTELLIGENT_CALL_ALERT_CAPTION,
#endif

#endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */

#if !defined(HW_LED_NOT_SUPPORT)    
    ,STR_ID_PROF_STATUS_LED                 //STATUS_LED_CAPTION,
#endif
};


#ifndef __MMI_PROF_BASIC_UI_STYLE__
static const U16 alert_type_item_str[] =
{
    STR_ID_PROF_RING_ONLY, STR_ID_PROF_VIB_ONLY, STR_ID_PROF_VIB_AND_RING, STR_ID_PROF_VIB_THEN_RING
};

static const cui_inline_item_select_struct alert_type_item_struct= 
{
    MMI_PROF_ALERT_TYPE_NUM, 0, (U16 *)&alert_type_item_str[0]
};

static const U16 ring_type_item_str[] =
{
    STR_ID_PROF_RINGING, 
#ifdef __MMI_AUDIO_CRESCENDO_SUPPORT__
    STR_ID_PROF_ASCENDING,
#endif    
    STR_ID_PROF_BEEP_ONCE
};

static const cui_inline_item_select_struct ring_type_item_struct = 
{
    MMI_PROF_RING_TYPE_NUM, 0, (U16 *)&ring_type_item_str[0]
};

static const U16 on_off_str[] =
{
    STR_GLOBAL_ON, STR_GLOBAL_OFF
};

static const cui_inline_item_select_struct onoff_item_struct = 
{
    MMI_PROF_ON_OFF_ITEM_NUM, 0, (U16 *)&on_off_str[0]
};


static const U16 keypad_item_str[] =
{
    STR_GLOBAL_SILENT,
    STR_ID_PROF_CLICK, 
    STR_ID_PROF_TONE
#if defined( __MMI_HUMAN_VOICE_KEYPAD_TONE__ )
    ,STR_ID_PROF_KEYPAD_HUMAN_VOICE_1
#endif
#if defined( __MMI_CUST_KEYPAD_TONE__ )
    ,STR_ID_PROF_KEYPAD_TONE_CUST_1
#endif
};

static const cui_inline_item_select_struct keypad_item_struct = 
{
    MMI_PROF_KEYPAD_TONE_NUM, 0, (U16 *)&keypad_item_str[0]
};
#endif /*#ifndef __MMI_PROF_BASIC_UI_STYLE__*/


#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
#ifdef __MMI_TOUCH_FEEDBACK_VIBRATE_LEVEL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif


static const cui_inline_item_display_only_struct display_null = 
{
    STR_GLOBAL_NONE
};

#if !defined(HW_LED_NOT_SUPPORT)    
static const U16 status_led_item_str[] =
{
    STR_GLOBAL_NONE, 
    STR_ID_PROF_COLOR_PATTERN_1, 
    STR_ID_PROF_COLOR_PATTERN_2, 
    STR_ID_PROF_COLOR_PATTERN_3, 
    STR_ID_PROF_COLOR_PATTERN_4,
    STR_ID_PROF_COLOR_PATTERN_5,
    STR_ID_PROF_COLOR_PATTERN_6
};

static const cui_inline_item_select_struct status_led_item_struct = 
{
    MMI_PROF_STATUS_LED_NUM, 0, (U16 *)&status_led_item_str[0]
};
#endif

#ifndef __MMI_PROF_BASIC_UI_STYLE__
static const cui_inline_item_progress_bar_struct vol_item_struct = 
{
    0, MDI_MAX_VOLUME_LEVEL, 1 
};
#endif

#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

static const cui_inline_item_softkey_struct prof_inline_softkey = 
{
    {
        {STR_GLOBAL_OPTIONS, 0},
        {STR_GLOBAL_BACK, 0},
        {0, IMG_GLOBAL_COMMON_CSK}
    }
};

static const cui_inline_set_item_struct prof_inline_item[] = 
{
#ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__
#ifndef  __MMI_MAINLCD_96X64__
    {CUI_INLINE_ITEM_ID_BASE + ALERT_TYPE_CAPTION,  CUI_INLINE_ITEM_TYPE_CAPTION, 0,  (void*)&prof_item_caption[ALERT_TYPE_CAPTION / 2]},
#endif
#ifndef __MMI_PROF_BASIC_UI_STYLE__
    {CUI_INLINE_ITEM_ID_BASE + ALERT_TYPE_ITEM,     CUI_INLINE_ITEM_TYPE_SELECT, 0,   (void*)&alert_type_item_struct},
#else
    {CUI_INLINE_ITEM_ID_BASE + ALERT_TYPE_ITEM,     CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0,   (void*)&display_null},
#endif

#ifndef  __MMI_MAINLCD_96X64__
    {CUI_INLINE_ITEM_ID_BASE + RING_TYPE_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION, 0,  (void*)&prof_item_caption[RING_TYPE_CAPTION / 2]},
#endif
#ifndef __MMI_PROF_BASIC_UI_STYLE__
    {CUI_INLINE_ITEM_ID_BASE + RING_TYPE_ITEM,      CUI_INLINE_ITEM_TYPE_SELECT, 0,   (void*)&ring_type_item_struct},
#else
    {CUI_INLINE_ITEM_ID_BASE + RING_TYPE_ITEM,      CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0,   (void*)&display_null},
#endif

#ifndef  __MMI_MAINLCD_96X64__
    {CUI_INLINE_ITEM_ID_BASE + SIM1_RING_TONE_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION, 0,  (void*)&prof_item_caption[SIM1_RING_TONE_CAPTION / 2]},
#endif
    {CUI_INLINE_ITEM_ID_BASE + SIM1_RING_TONE_ITEM,      CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, (void*)&display_null},

#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
#ifndef  __MMI_MAINLCD_96X64__
    {CUI_INLINE_ITEM_ID_BASE + SIM2_RING_TONE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0,        (void*)&prof_item_caption[SIM2_RING_TONE_CAPTION / 2]},
#endif
    {CUI_INLINE_ITEM_ID_BASE + SIM2_RING_TONE_ITEM,    CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0,   (void*)&display_null},
#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
#ifndef  __MMI_MAINLCD_96X64__
    {CUI_INLINE_ITEM_ID_BASE + SIM3_RING_TONE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0,        (void*)&prof_item_caption[SIM3_RING_TONE_CAPTION / 2]},
#endif
    {CUI_INLINE_ITEM_ID_BASE + SIM3_RING_TONE_ITEM,    CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0,   (void*)&display_null},
#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
#ifndef  __MMI_MAINLCD_96X64__
    {CUI_INLINE_ITEM_ID_BASE + SIM4_RING_TONE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0,        (void*)&prof_item_caption[SIM4_RING_TONE_CAPTION / 2]},
#endif
    {CUI_INLINE_ITEM_ID_BASE + SIM4_RING_TONE_ITEM,    CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0,   (void*)&display_null},
#endif
#endif
#endif

#ifdef __MMI_VIDEO_TELEPHONY__    
#ifndef  __MMI_MAINLCD_96X64__
    {CUI_INLINE_ITEM_ID_BASE + VIDEO_CALL_TONE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0,        (void*)&prof_item_caption[VIDEO_CALL_TONE_CAPTION / 2]},
#endif
    {CUI_INLINE_ITEM_ID_BASE + VIDEO_CALL_TONE_ITEM,    CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0,   (void*)&display_null},
#endif

#ifndef  __MMI_MAINLCD_96X64__    
    {CUI_INLINE_ITEM_ID_BASE + RING_VOL_CAPTION,    CUI_INLINE_ITEM_TYPE_CAPTION, 0,       (void*)&prof_item_caption[RING_VOL_CAPTION / 2]},
#endif
#ifndef __MMI_PROF_BASIC_UI_STYLE__
    {CUI_INLINE_ITEM_ID_BASE + RING_VOL_ITEM,       CUI_INLINE_ITEM_TYPE_PROGRESS_BAR, 0,  (void*)&vol_item_struct},
#else
    {CUI_INLINE_ITEM_ID_BASE + RING_VOL_ITEM,       CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0,  (void*)&display_null},
#endif

#endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */

#ifdef __MMI_PROF_MSG_ALERTS_SUPPORT__

#ifndef __MMI_PROF_SPLIT_MSG_TONES__    
#ifndef  __MMI_MAINLCD_96X64__ 
    {CUI_INLINE_ITEM_ID_BASE + SIM1_MSG_TONE_CAPTION,    CUI_INLINE_ITEM_TYPE_CAPTION, 0,       (void*)&prof_item_caption[SIM1_MSG_TONE_CAPTION / 2]},
#endif
    {CUI_INLINE_ITEM_ID_BASE + SIM1_MSG_TONE_ITEM,       CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0,  (void*)&display_null},
#else
#ifndef  __MMI_MAINLCD_96X64__
    {CUI_INLINE_ITEM_ID_BASE + SMS_TONE_CAPTION,    CUI_INLINE_ITEM_TYPE_CAPTION, 0,       (void*)&prof_item_caption[SMS_TONE_CAPTION / 2]},
#endif
    {CUI_INLINE_ITEM_ID_BASE + SMS_TONE_ITEM,       CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0,  (void*)&display_null},

    #ifdef MMS_SUPPORT   
    #ifndef  __MMI_MAINLCD_96X64__
    {CUI_INLINE_ITEM_ID_BASE + MMS_TONE_CAPTION,    CUI_INLINE_ITEM_TYPE_CAPTION, 0,       (void*)&prof_item_caption[MMS_TONE_CAPTION / 2]},
    #endif
    {CUI_INLINE_ITEM_ID_BASE + MMS_TONE_ITEM,       CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0,  (void*)&display_null},
    #endif
    
    #ifdef __MMI_EMAIL__
    #ifndef  __MMI_MAINLCD_96X64__
    {CUI_INLINE_ITEM_ID_BASE + EMAIL_TONE_CAPTION,  CUI_INLINE_ITEM_TYPE_CAPTION, 0,         (void*)&prof_item_caption[EMAIL_TONE_CAPTION / 2]},
    #endif
    {CUI_INLINE_ITEM_ID_BASE + EMAIL_TONE_ITEM,     CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0,    (void*)&display_null},
    #endif
    
    #ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
    #ifndef  __MMI_MAINLCD_96X64__
/* under construction !*/
    #endif
/* under construction !*/
    #endif
#endif

#if (SRV_PROF_SMS_TONE_AMOUNT > 1)
    #ifndef  __MMI_MAINLCD_96X64__
    {CUI_INLINE_ITEM_ID_BASE + SIM2_MSG_TONE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, 	   (void*)&prof_item_caption[SIM2_MSG_TONE_CAPTION / 2]},
    #endif
    {CUI_INLINE_ITEM_ID_BASE + SIM2_MSG_TONE_ITEM,     CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0,    (void*)&display_null},
#if (SRV_PROF_SMS_TONE_AMOUNT > 2)
    #ifndef  __MMI_MAINLCD_96X64__
	{CUI_INLINE_ITEM_ID_BASE + SIM3_MSG_TONE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, 	   (void*)&prof_item_caption[SIM3_MSG_TONE_CAPTION / 2]},
    #endif
	{CUI_INLINE_ITEM_ID_BASE + SIM3_MSG_TONE_ITEM,    CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0,   (void*)&display_null},
#if (SRV_PROF_SMS_TONE_AMOUNT > 3)
    #ifndef  __MMI_MAINLCD_96X64__
	{CUI_INLINE_ITEM_ID_BASE + SIM4_MSG_TONE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, 	   (void*)&prof_item_caption[SIM4_MSG_TONE_CAPTION / 2]},
    #endif
	{CUI_INLINE_ITEM_ID_BASE + SIM4_MSG_TONE_ITEM,    CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0,   (void*)&display_null},
#endif
#endif
#endif

#if !(defined(__MMI_MAINLCD_96X64__) || defined(__MMI_PROF_SLIM_PROFILES__))
    {CUI_INLINE_ITEM_ID_BASE + MSG_VOL_CAPTION,     CUI_INLINE_ITEM_TYPE_CAPTION, 0,        (void*)&prof_item_caption[MSG_VOL_CAPTION / 2]},
#ifndef __MMI_PROF_BASIC_UI_STYLE__
    {CUI_INLINE_ITEM_ID_BASE + MSG_VOL_ITEM,        CUI_INLINE_ITEM_TYPE_PROGRESS_BAR, 0,   (void*)&vol_item_struct},
#else
    {CUI_INLINE_ITEM_ID_BASE + MSG_VOL_ITEM,        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0,   (void*)&display_null},
#endif
#endif

#endif /* __MMI_PROF_MSG_ALERTS_SUPPORT__ */

#ifndef  __MMI_MAINLCD_96X64__
    {CUI_INLINE_ITEM_ID_BASE + KEYPAD_TONE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0,        (void*)&prof_item_caption[KEYPAD_TONE_CAPTION / 2]},
#endif
#ifndef __MMI_PROF_BASIC_UI_STYLE__
    {CUI_INLINE_ITEM_ID_BASE + KEYPAD_TONE_ITEM,    CUI_INLINE_ITEM_TYPE_SELECT, 0,         (void*)&keypad_item_struct},
#else
    {CUI_INLINE_ITEM_ID_BASE + KEYPAD_TONE_ITEM,    CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0,         (void*)&display_null},
#endif

#ifndef  __MMI_MAINLCD_96X64__
    {CUI_INLINE_ITEM_ID_BASE + KEYPAD_VOL_CAPTION,  CUI_INLINE_ITEM_TYPE_CAPTION, 0,        (void*)&prof_item_caption[KEYPAD_VOL_CAPTION / 2]},
#endif
#ifndef __MMI_PROF_BASIC_UI_STYLE__
    {CUI_INLINE_ITEM_ID_BASE + KEYPAD_VOL_ITEM,     CUI_INLINE_ITEM_TYPE_PROGRESS_BAR, 0,   (void*)&vol_item_struct},
#else
    {CUI_INLINE_ITEM_ID_BASE + KEYPAD_VOL_ITEM,     CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0,   (void*)&display_null},
#endif

#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
    #ifndef  __MMI_MAINLCD_96X64__
/* under construction !*/
    #endif
/* under construction !*/
    #ifndef  __MMI_MAINLCD_96X64__
/* under construction !*/
    #endif
/* under construction !*/
#endif

#if !defined(__MMI_POWER_ON_OFF_MUTE__) && !defined(__MMI_POWER_ON_OFF_NO_CUSTOMIZE__)
    #ifndef  __MMI_MAINLCD_96X64__
    {CUI_INLINE_ITEM_ID_BASE + POWER_ON_TONE_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION, 0,        (void*)&prof_item_caption[POWER_ON_TONE_CAPTION / 2]},
    #endif
    {CUI_INLINE_ITEM_ID_BASE + POWER_ON_TONE_ITEM,      CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0,   (void*)&display_null},
    #ifndef  __MMI_MAINLCD_96X64__
    {CUI_INLINE_ITEM_ID_BASE + POWER_OFF_TONE_CAPTION,  CUI_INLINE_ITEM_TYPE_CAPTION, 0,        (void*)&prof_item_caption[POWER_OFF_TONE_CAPTION / 2]},
    #endif
    {CUI_INLINE_ITEM_ID_BASE + POWER_OFF_TONE_ITEM,     CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0,   (void*)&display_null},
#endif

#ifdef __MMI_CLAMSHELL__
    #ifndef  __MMI_MAINLCD_96X64__
    {CUI_INLINE_ITEM_ID_BASE + COVER_OPEN_TONE_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION, 0,        (void*)&prof_item_caption[COVER_OPEN_TONE_CAPTION / 2]},
    #endif
    {CUI_INLINE_ITEM_ID_BASE + COVER_OPEN_TONE_ITEM,      CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0,   (void*)&display_null},
    #ifndef  __MMI_MAINLCD_96X64__
    {CUI_INLINE_ITEM_ID_BASE + COVER_CLOSE_TONE_CAPTION,  CUI_INLINE_ITEM_TYPE_CAPTION, 0,        (void*)&prof_item_caption[COVER_CLOSE_TONE_CAPTION / 2]},
    #endif
    {CUI_INLINE_ITEM_ID_BASE + COVER_CLOSE_TONE_ITEM,     CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0,   (void*)&display_null},
#endif

#if !(defined(__MMI_MAINLCD_96X64__) || defined(__MMI_PROF_SLIM_PROFILES__))
    {CUI_INLINE_ITEM_ID_BASE + SYSTEM_ALERT_CAPTION,    CUI_INLINE_ITEM_TYPE_CAPTION, 0,    (void*)&prof_item_caption[SYSTEM_ALERT_CAPTION / 2]},
#ifndef __MMI_PROF_BASIC_UI_STYLE__
    {CUI_INLINE_ITEM_ID_BASE + SYSTEM_ALERT_ITEM,       CUI_INLINE_ITEM_TYPE_SELECT, 0,     (void*)&onoff_item_struct}
#else
    {CUI_INLINE_ITEM_ID_BASE + SYSTEM_ALERT_ITEM,       CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0,     (void*)&display_null}
#endif
#endif

#ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__

#if defined(__MMI_INTELLIGENT_CALL_ALERT__) 
#ifndef  __MMI_MAINLCD_96X64__
   , {CUI_INLINE_ITEM_ID_BASE + INTELLIGENT_CALL_ALERT_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0,    (void*)&prof_item_caption[INTELLIGENT_CALL_ALERT_CAPTION / 2]}
#endif
   ,{CUI_INLINE_ITEM_ID_BASE + INTELLIGENT_CALL_ALERT_ITEM,     CUI_INLINE_ITEM_TYPE_SELECT, 0,     (void*)&onoff_item_struct}
#endif

#endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */

#if !defined(HW_LED_NOT_SUPPORT)
#ifndef  __MMI_MAINLCD_96X64__
   , {CUI_INLINE_ITEM_ID_BASE + STATUS_LED_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0,    (void*)&prof_item_caption[STATUS_LED_CAPTION / 2]}
#endif
   ,{CUI_INLINE_ITEM_ID_BASE + STATUS_LED_ITEM,     CUI_INLINE_ITEM_TYPE_SELECT, 0,     (void*)&status_led_item_struct}
#endif
};

static const cui_inline_struct prof_inline_screen = 
{
#ifndef  __MMI_MAINLCD_96X64__ 
    PROFILE_INLINE_ITEM_NUM,
#else    // __MMI_MAINLCD_96X64__
    PROFILE_INLINE_ITEM_NUM/2,
#endif    // __MMI_MAINLCD_96X64__
    STR_ID_PROF_CUSTOMIZE,
    0,
    CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE, 
    &prof_inline_softkey, 
    prof_inline_item 
};


#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    #define MMI_PROFILE_CAPTION_NAME_MAX_LEN (MMI_NETSET_SIM_NAME_MAX_LEN+20)
    static WCHAR sim_name[MMI_NETSET_SIM_NAME_MAX_LEN];
    static WCHAR ring_caption_string[SRV_PROF_MT_CALL_TONE_AMOUNT][MMI_PROFILE_CAPTION_NAME_MAX_LEN];
    static WCHAR message_caption_string[SRV_PROF_SMS_TONE_AMOUNT][MMI_PROFILE_CAPTION_NAME_MAX_LEN];
    static MMI_BOOL ring_item_exist[SRV_PROF_MT_CALL_TONE_AMOUNT];
    static MMI_BOOL message_item_exist[SRV_PROF_SMS_TONE_AMOUNT];
#endif

#ifdef __MMI_AP_DCM_PROFILE__
#pragma arm section rodata , code
#endif

/***************************************************************************** 
 * Local Function
 *****************************************************************************/
static void mmi_profiles_set_inline_item(mmi_id inline_id);
static void mmi_prof_entry_options_scrn(void);

static void mmi_prof_entry_main_scrn_internal(void);
static void mmi_prof_entry_customize_scrn(void);
static void mmi_prof_entry_customize_option_scrn(void);

#ifndef  __MMI_MAINLCD_96X64__
static void mmi_prof_entry_reset_confirm_scrn(void);
static void mmi_prof_entry_reset_scrn(void);
#endif

static void mmi_prof_customize_scrn_csk_hdlr(void);

static void mmi_prof_activate_current_profile(void);

static mmi_id mmi_prof_run_tone_selector(mmi_id parent_gid, U16 tone_filter, mmi_id str_id, mmi_id curr_audio_id);
#ifndef __MMI_PROF_BASIC_UI_STYLE__
static mmi_id mmi_prof_run_fseditor_cui(void);
#endif
static void mmi_prof_app_mem_stop_callback(void);

static void mmi_prof_get_cur_settings(void);
static void mmi_prof_save_cur_settings(void);

static void mmi_prof_preview_key_tone(void);
static void mmi_prof_preview_play_tone(void);
#ifndef __MMI_PROF_BASIC_UI_STYLE__
static void mmi_prof_preview_stop_tone(void);
#endif
static void mmi_prof_preview_tone_callback(mdi_result result, void *user_data);
static void mmi_prof_inline_item_highlight_hdlr(mmi_event_struct* evt);
#ifndef __MMI_PROF_BASIC_UI_STYLE__
static void mmi_prof_progress_bar_value_change_hdlr(void);
#endif
static mmi_ret mmi_prof_group_proc(mmi_event_struct* evt);
static U8 mmi_prof_srv_event_handler(srv_prof_cb_enum event, void* input, void* output);
#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
static MMI_BOOL mmi_prof_get_ext_file_slot(U16 profile_id, srv_prof_settings_enum setting, U8 * slot);
#endif    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */

static void mmi_prof_show_alert_status_icon(void);
#ifdef __BT_SPK_VOL_CONTROL__
static MMI_BOOL mmi_prof_handfree_volume_sync_callback(U8 volume, MMI_BOOL is_mute);
#endif
static void mmi_prof_util_display_srv_fail_popup(srv_prof_ret srv_result);

static void mmi_prof_menu_item_highlight(mmi_event_struct* evt);
#ifndef __MMI_PROF_BASIC_UI_STYLE__
static void mmi_prof_reset_my_style_name(void);
#endif
static void mmi_prof_display_activate_profile_popup(mmi_prof_id_enum profile_id);

static U16 mmi_prof_get_string_id_from_audio_id(U16 audio_id);

#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
#ifdef __MMI_TOUCH_FEEDBACK_VIBRATE_LEVEL_SUPPORT__ 
/* under construction !*/
#endif
#endif

static void mmi_prof_get_ring_tong_list(mmi_id str_id, U16 tone);
#ifdef __MMI_PROF_BASIC_UI_STYLE__
static void mmi_prof_set_volume_level(void);
#endif

#ifdef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
static void mmi_prof_add_new_profile(void);
static void mmi_prof_delete_profile(void);
static void mmi_prof_create_main_menu(mmi_id menu_gid);
static void mmi_prof_entry_delete_confirm_scrn();
#endif

void mmi_profiles_entry_main_screen(void);
#ifdef __MMI_APP_MANAGER_SUPPORT__
MMI_ID mmi_profiles_launch_function(void *param, U32 param_size);
#endif

static MMI_BOOL mmi_prof_activate_profile_int(mmi_prof_id_enum profile_id, MMI_BOOL need_popup);
static MMI_BOOL mmi_prof_deactivate_silent_profile_int(MMI_BOOL need_popup);

/* For Build warning - declared implicitly */
void cui_inline_set_item_caption(mmi_id gid, U16 item_id, PU8 text_p);

/*****************************************************************************
 * FUNCTION Body
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_launch_function
 * DESCRIPTION
 *  launch profile for cosmos_fte
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_APP_MANAGER_SUPPORT__
MMI_ID mmi_profiles_launch_function(void *param, U32 param_size)
{
    mmi_profiles_entry_main_screen();
    if(MMI_TRUE == mmi_frm_group_is_present(GRP_ID_PROFILES))
    {
        return GRP_ID_PROFILES;
    }
    return GRP_ID_INVALID;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_app_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_prof_app_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_PROF_BASIC_UI_STYLE__
    S16 error;
#endif

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    U16 i;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AP_DCM_PROFILE__
    mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_SETTINGS);
#endif

    applib_mem_ap_register(APPLIB_MEM_AP_ID_USER_PROF,
        STR_ID_PROF_CAPTION, 
        GetRootTitleIcon(MAIN_MENU_PROFILES_MENUID),
        mmi_prof_app_mem_stop_callback);

    srv_prof_register_app_callback((srv_profiles_notify_callback)mmi_prof_srv_event_handler);

    mmi_prof_show_alert_status_icon();

#if !defined(__MMI_PROF_BASIC_UI_STYLE__) && !defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
    ReadRecord(NVRAM_EF_MMI_PROF_SETTING_LID,
               1,
               (void*)g_prof.my_style_name,
               (MMI_PROF_PROFILE_NAME_LENGTH + 1) * ENCODING_LENGTH,
               &error);
    if (g_prof.my_style_name[0] == L'\0')
    {
        mmi_ucs2ncpy((CHAR*)g_prof.my_style_name, (CHAR*)GetString(STR_ID_PROF_MY_STYLE), MMI_PROF_PROFILE_NAME_LENGTH);
        g_prof.is_default_name = MMI_TRUE;
    }
    else
    {
        g_prof.is_default_name = MMI_FALSE;
    }
#elif defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
    ReadRecord(NVRAM_EF_MMI_PROF_NEW_NAME_LID,
               1,
               (void*)g_prof.new_name,
               NVRAM_MMI_PROF_NEW_RECORD_SIZE,
               &error);
    ReadRecord(NVRAM_EF_MMI_PROF_NEW_FLAG_LID,
               1,
               (void*)g_prof.flag,
               NVRAM_MMI_PROF_FLAG_RECORD_SIZE,
               &error);
#endif

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    for(i=0;i<SRV_PROF_MT_CALL_TONE_AMOUNT;i++)
    {
    	ring_item_exist[i] = MMI_TRUE;
   	}
   	
   	for(i=0;i<SRV_PROF_SMS_TONE_AMOUNT;i++)
   	{
   		message_item_exist[i] = MMI_TRUE;
   	}
#endif

#ifdef __MMI_AP_DCM_PROFILE__
    if(!mmi_frm_app_is_launched(APP_SETTING_NEW))
    {
        mmi_ap_send_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_SETTINGS);
    }
#endif

	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_srv_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_prof_srv_event_handler(srv_prof_cb_enum event, void* input, void* output)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = SRV_PROF_RET_SUCCESS;
    srv_prof_settings_enum setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PROF_TRC_SRV_EVENT, *(U16*)input);
    switch (event)
    {
        case SRV_PROF_CB_PROFILE_SWITCHED:
        {
            g_prof.activated_profile = srv_prof_get_activated_profile();
            mmi_prof_show_alert_status_icon();
            break;
        }
    #ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
        case SRV_PROF_CB_SLOT_QUERY:
        {
            setting = (srv_prof_settings_enum)*(U16*)input;
            if (srv_prof_get_activated_profile() == MMI_PROFILE_SILENT)
            {
                return (U8)SRV_PROF_RET_SETTING_NOT_SUPPORTED;
            }
            if (setting == SRV_PROF_SETTINGS_MT_CALL_TONE
                || setting == SRV_PROF_SETTINGS_MT_CALL_CARD2_TONE
                || setting == SRV_PROF_SETTINGS_MT_CALL_CARD3_TONE
                || setting == SRV_PROF_SETTINGS_MT_CALL_CARD4_TONE
                || setting == SRV_PROF_SETTINGS_VT_CALL_TONE
                )
            {
                mmi_prof_get_ext_file_slot(srv_prof_get_activated_profile(), setting, (U8*)output);
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PROF_TRC_SRV_EVENT_OUTPUT, *(U8*)output);
            }
            else
            {
                result = (U8)SRV_PROF_RET_SETTING_NOT_SUPPORTED;
            }
            break;
        }
    #endif    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */
        default:
            break;
    }
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_show_alert_status_icon
 * DESCRIPTION
 *  show/switch alert status icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_show_alert_status_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_alert_type_enum alert_type; 
    static S16 currentStatusIcon;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bootup_get_booting_mode() != SRV_BOOTUP_MODE_NORMAL && !srv_bootup_is_exception_mode())
    {
        return;
    }

    if (currentStatusIcon != 0)
    {
        wgui_status_icon_bar_reset_icon_display(currentStatusIcon);
    }

    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_ALERT_TYPE, (void*)&alert_type);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PROF_TRC_GET_ALERT_TYPE, alert_type);
    switch (alert_type)
    {
        case SRV_PROF_ALERT_TYPE_RING:
            currentStatusIcon = STATUS_ICON_RING;
             break;
        
        case SRV_PROF_ALERT_TYPE_VIB_ONLY:
            currentStatusIcon = STATUS_ICON_VIBRATION;
            break;
        
        case SRV_PROF_ALERT_TYPE_VIB_AND_RING:
            currentStatusIcon = STATUS_ICON_VIBRATE_AND_RING;
            break;
        
        case SRV_PROF_ALERT_TYPE_VIB_THEN_RING:
            currentStatusIcon = STATUS_ICON_VIBRATE_THEN_RING;
            break;

        case SRV_PROF_ALERT_TYPE_SILENT:
            currentStatusIcon = STATUS_ICON_SILENT;
            break;
        
        default:
            if (currentStatusIcon != 0)
            {
                currentStatusIcon = STATUS_ICON_RING;
            }
            break;      
    }
    
    wgui_status_icon_bar_set_icon_display(currentStatusIcon);
    wgui_status_icon_bar_update();
}

#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_prof_app_filemgr_option_enabler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prof_app_filemgr_option_enabler(mmi_menu_id item_id, 
                                         const WCHAR* filepath, 
                                         const srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mdi_type = MDI_FORMAT_SMF;
	
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
		S32 sim_num;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_prof_get_activated_profile() == MMI_PROFILE_SILENT)
    {
        /*hide use as in silent profile mode.*/
        mmi_frm_hide_menu_item(item_id);
        return;
    }
    if(fileinfo->type == FMGR_TYPE_IMY || fileinfo->type == FMGR_TYPE_MIDI || fileinfo->type == FMGR_TYPE_MID)
    {
        if(fileinfo->type == FMGR_TYPE_IMY)
        {
            mdi_type = MDI_FORMAT_IMELODY;
        }
        
        if (fileinfo->size > mdi_audio_get_size_limit(mdi_type))
        {
            mmi_frm_hide_menu_item(item_id);
            return;
        }
    }

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
		sim_num = srv_sim_ctrl_get_num_of_inserted();
	
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT <= 1)
			switch(item_id)
			{
				case MENU_ID_PROF_USE_AS_SIM1_RINGTONE:
				case MENU_ID_PROF_USE_AS_SIM2_RINGTONE:
				case MENU_ID_PROF_USE_AS_SIM3_RINGTONE:
				case MENU_ID_PROF_USE_AS_SIM4_RINGTONE:
					mmi_frm_hide_menu_item(item_id);
					break;
				default:
					break;
			}
    #elif (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
			if((sim_num == 0) || (sim_num == 1))
			{
				switch(item_id)
				{
					case MENU_ID_PROF_USE_AS_SIM1_RINGTONE:
					case MENU_ID_PROF_USE_AS_SIM2_RINGTONE:
					case MENU_ID_PROF_USE_AS_SIM3_RINGTONE:
					case MENU_ID_PROF_USE_AS_SIM4_RINGTONE:
						mmi_frm_hide_menu_item(item_id);
						break;
					default:
						break;
				}
			}
			else if(sim_num > 1)
			{
			    switch(item_id)
				{
				case MENU_ID_PROF_USE_AS_RINGTONE:
					mmi_frm_hide_menu_item(item_id);
					break;
				case MENU_ID_PROF_USE_AS_SIM1_RINGTONE:
					if (!srv_sim_ctrl_is_inserted(MMI_SIM1))
					{
						mmi_frm_hide_menu_item(item_id);
					}
					break;
			   #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
				case MENU_ID_PROF_USE_AS_SIM2_RINGTONE:
					if (!srv_sim_ctrl_is_inserted(MMI_SIM2))
					{
						mmi_frm_hide_menu_item(item_id);
					}
					break;
				#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
				case MENU_ID_PROF_USE_AS_SIM3_RINGTONE:
					if (!srv_sim_ctrl_is_inserted(MMI_SIM3))
					{
						mmi_frm_hide_menu_item(item_id);
					}
					break;
				#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
				case MENU_ID_PROF_USE_AS_SIM4_RINGTONE:
					if (!srv_sim_ctrl_is_inserted(MMI_SIM4))
					{
						mmi_frm_hide_menu_item(item_id);
					}
					break;
				#else
				    case MENU_ID_PROF_USE_AS_SIM4_RINGTONE:
                        mmi_frm_hide_menu_item(item_id);
					    break;
                #endif
				#else
				    case MENU_ID_PROF_USE_AS_SIM3_RINGTONE:
                        mmi_frm_hide_menu_item(item_id);
					    break;
				case MENU_ID_PROF_USE_AS_SIM4_RINGTONE:
                        mmi_frm_hide_menu_item(item_id);
					    break;
                #endif
				#endif
				default:
					break;
			    }
			}
    #endif
#else /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
	switch(item_id)
	{
        
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
        case MENU_ID_PROF_USE_AS_RINGTONE:
            mmi_frm_hide_menu_item(item_id);
            break;
    #endif
		   
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT == 1)
        case MENU_ID_PROF_USE_AS_SIM1_RINGTONE:
            mmi_frm_hide_menu_item(item_id);
	    break;
    #endif  
        
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT <= 1)
        case MENU_ID_PROF_USE_AS_SIM2_RINGTONE:
            mmi_frm_hide_menu_item(item_id);
	    break;
    #endif
    
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT <= 2)
    	case MENU_ID_PROF_USE_AS_SIM3_RINGTONE:
            mmi_frm_hide_menu_item(item_id);
            break;
    #endif

    #if (SRV_PROF_MT_CALL_TONE_AMOUNT <= 3)
        case MENU_ID_PROF_USE_AS_SIM4_RINGTONE:
            mmi_frm_hide_menu_item(item_id);
    	    break;
	#endif
		default:
			break;
	}
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_app_filemgr_option_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prof_app_filemgr_option_hdlr(mmi_menu_id item_id, 
                                      const WCHAR* filepath, 
                                      const srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_settings_enum setting;
    srv_prof_ret srv_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(item_id)
    {
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT == 1)
        case MENU_ID_PROF_USE_AS_RINGTONE:
            setting = SRV_PROF_SETTINGS_MT_CALL_TONE;
            break;
    #else
	#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
	    case MENU_ID_PROF_USE_AS_RINGTONE:
			if(srv_sim_ctrl_is_inserted(MMI_SIM1))
			{
			    setting = SRV_PROF_SETTINGS_MT_CALL_TONE;
			    break;
			}
			#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
			else if(srv_sim_ctrl_is_inserted(MMI_SIM2))
			{
			    setting = SRV_PROF_SETTINGS_MT_CALL_CARD2_TONE;
			    break;
			}
			#endif
			#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
			else if(srv_sim_ctrl_is_inserted(MMI_SIM3))
			{
			    setting = SRV_PROF_SETTINGS_MT_CALL_CARD3_TONE;
			    break;
			}
			#endif
			#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
			else if(srv_sim_ctrl_is_inserted(MMI_SIM4))
			{
			    setting = SRV_PROF_SETTINGS_MT_CALL_CARD4_TONE;
			    break;
			}
			#endif
			else
			{
			    setting = SRV_PROF_SETTINGS_MT_CALL_TONE;
			    break;
			}
	#endif
        case MENU_ID_PROF_USE_AS_SIM1_RINGTONE:
            setting = SRV_PROF_SETTINGS_MT_CALL_TONE;
            break;
    #endif
    
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
        case MENU_ID_PROF_USE_AS_SIM2_RINGTONE:
            setting = SRV_PROF_SETTINGS_MT_CALL_CARD2_TONE;
            break;
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
        case MENU_ID_PROF_USE_AS_SIM3_RINGTONE:
            setting = SRV_PROF_SETTINGS_MT_CALL_CARD3_TONE;
            break;
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
        case MENU_ID_PROF_USE_AS_SIM4_RINGTONE:
            setting = SRV_PROF_SETTINGS_MT_CALL_CARD4_TONE;
            break;
    #endif
    #endif
    #endif
            
    #ifdef __MMI_VIDEO_TELEPHONY__ 
        case MENU_ID_PROF_USE_AS_VIDEO_TONE:
            setting = SRV_PROF_SETTINGS_VT_CALL_TONE;
            break;
    #endif
        default:
            return;
    }
    
    srv_result = srv_prof_set_current_profile_tone_with_file_path(setting, (WCHAR*)filepath);

    if (srv_result == SRV_PROF_RET_SUCCESS || srv_result == SRV_PROF_RET_EXT_MELODY_REPLACED)
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
    }
    else
    {
        mmi_prof_util_display_srv_fail_popup(srv_result);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_get_ext_file_slot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_prof_get_ext_file_slot(U16 profile_id, srv_prof_settings_enum setting, U8 * slot)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (setting)
    {
        case SRV_PROF_SETTINGS_MT_CALL_TONE:
        {
            i = 0;
            break;
        }
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
        case SRV_PROF_SETTINGS_MT_CALL_CARD2_TONE:
        {
            i++;
            break;
        }
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
        case SRV_PROF_SETTINGS_MT_CALL_CARD3_TONE:
        {
            i++;
            break;
        }
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
        case SRV_PROF_SETTINGS_MT_CALL_CARD4_TONE:
        {
            i++;
            break;
        }
    #endif
    #endif
    #endif
    #ifdef __MMI_VIDEO_TELEPHONY__
        case SRV_PROF_SETTINGS_VT_CALL_TONE:
        {
            i++;   
            break;
        }
    #endif
        default:
            return MMI_FALSE;
    }

    /* Use MMI_PROF_PROF_ID_NUM for total number of profiles instead of SRV_PROF_PROFILES_TOTAL_NUM */
    if (profile_id < MMI_PROFILE_SILENT)
    {
        *slot = (profile_id - MMI_PROF_PROF_ID_BEGIN) * SRV_PROF_EXT_MELODY_NUM / (MMI_PROF_PROF_ID_NUM-1) + i;
    }
    else if (profile_id > MMI_PROFILE_SILENT)
    {
        *slot = (profile_id - MMI_PROF_PROF_ID_BEGIN - 1) * SRV_PROF_EXT_MELODY_NUM / (MMI_PROF_PROF_ID_NUM-1) + i;
    }
    else
    {
        return MMI_FALSE;
    }
    
    return MMI_TRUE;
}

#endif    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_util_display_srv_fail_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_util_display_srv_fail_popup(srv_prof_ret srv_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (srv_result)
    {
        case SRV_PROF_RET_MIDI_CHECK_FILE_FAIL:
            string_id = STR_GLOBAL_DRM_FS_ERROR;
            break;
            
        case SRV_PROF_RET_MIDI_FILE_TOO_LARGE:
            string_id = STR_ID_PROF_FILE_TOO_LARGE;
            break;

        case SRV_PROF_RET_DRM_NOT_FORWARDABLE:
            string_id = STR_GLOBAL_DRM_PROHIBITED;
            break;
            
        default:
            string_id = STR_GLOBAL_NOT_SUPPORTED;
    }
    mmi_popup_display_simple_ext(string_id, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prof_get_profile_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
WCHAR * mmi_prof_get_profile_name(mmi_prof_id_enum profile_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (profile_id >= MMI_PROFILE_GENERAL && profile_id <= MMI_PROFILE_OUTDOOR)
    {
        return (WCHAR*)GetString(profile_id - MMI_PROFILE_GENERAL + STR_ID_PROF_GENERAL); 
    }
#if !defined(__MMI_PROF_BASIC_UI_STYLE__) && !defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
    else if (profile_id == MMI_PROFILE_MY_STYLE)
    {
        if (g_prof.is_default_name)
        {
            mmi_ucs2ncpy((CHAR*)g_prof.my_style_name, (CHAR*)GetString(STR_ID_PROF_MY_STYLE), MMI_PROF_PROFILE_NAME_LENGTH);
        }
        return g_prof.my_style_name;
    }
    else
    {
        return NULL;
    }
#elif defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
    else
    {
        return g_prof.new_name[profile_id-MMI_PROFILE_NEW_1];
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_get_profiles_enum_list_for_shell
 * DESCRIPTION
 *  fill profiles enum list for shell app
 * PARAMETERS
 *  enum_ptr: address of enum list
 *  length: length of enum list
 * RETURNS
 *  U8: number of filled enum
 *****************************************************************************/
U8 mmi_prof_get_profiles_enum_list_for_shell(U8* enum_ptr, U8 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 num = 0;
#if defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
    U8 j;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i<length; i++)
    {
        *(enum_ptr + i) = 0;
    }
    
    for(i=0; i<4; i++)
    {
        *(enum_ptr + i) = MMI_PROF_PROF_ID_BEGIN + i;
        num = num + 1;
    }

#if !defined(__MMI_PROF_BASIC_UI_STYLE__) && !defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
    *(enum_ptr + 4) = MMI_PROFILE_MY_STYLE;
    num = num + 1;
#elif defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
    for(i=4; i<length; i++)
    for(j=0; j<10; j++)
    {
        if (g_prof.new_name[j][0] == L'\0')
        {
            continue;
        }
        
        if(g_prof.flag[j] == (i-4))
        {
            *(enum_ptr  + i) = MMI_PROFILE_NEW_1 + j;
            num = num + 1;
        }
    }
#endif

    return num;
}

#ifdef __GAIN_TABLE_SUPPORT__
U16 mmi_prof_get_current_set_item(void)
{
    return g_curr_tone_setting_type;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_activate_profile
 * DESCRIPTION
 *  Activate profile
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: Successed
 *  MMI_FALSE: Failed
 *****************************************************************************/
MMI_BOOL mmi_prof_activate_profile(mmi_prof_id_enum profile_id, MMI_BOOL need_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AP_DCM_PROFILE__
    mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_SETTINGS);
#endif

    result = mmi_prof_activate_profile_int(profile_id,need_popup);

#ifdef __MMI_AP_DCM_PROFILE__
    if(!mmi_frm_app_is_launched(APP_SETTING_NEW))
    {
        mmi_ap_send_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_SETTINGS);
    }
#endif

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_deactivate_silent_profile
 * DESCRIPTION
 *  Deactivate silent profile
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: Successed
 *  MMI_FALSE: Failed
 *****************************************************************************/
MMI_BOOL mmi_prof_deactivate_silent_profile(MMI_BOOL need_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AP_DCM_PROFILE__
    mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_SETTINGS);
#endif

    result = mmi_prof_deactivate_silent_profile_int(need_popup);

#ifdef __MMI_AP_DCM_PROFILE__
    if(!mmi_frm_app_is_launched(APP_SETTING_NEW))
    {
        mmi_ap_send_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_SETTINGS);
    }
#endif

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_entry_main_screen
 * DESCRIPTION
 *  Entry function for main profile screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_entry_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AP_DCM_PROFILE__
    mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_SETTINGS);
#endif

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_TRC_ENTRY_PROFILE);
    g_prof.activated_profile = srv_prof_get_activated_profile();

#if !defined(__MMI_PROF_BASIC_UI_STYLE__) && !defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
    if (g_prof.is_default_name)
    {
        mmi_ucs2ncpy((CHAR*)g_prof.my_style_name, (CHAR*)GetString(STR_ID_PROF_MY_STYLE), MMI_PROF_PROFILE_NAME_LENGTH);
    }
#endif    
    mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_PROFILES, mmi_prof_group_proc, NULL,MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_prof_entry_main_scrn_internal();
}

#if (defined(__MMI_MAINLCD_96X64__) || defined(__MMI_PROF_SLIM_PROFILES__))
/*****************************************************************************
 * FUNCTION
 *  mmi_prof_volume_change_hdlr
 * DESCRIPTION
 *  The volume change event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_prof_volume_change_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_evt_vol_change_struct* vol_evt;
    U8 vol_level;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vol_evt = (srv_prof_evt_vol_change_struct*)evt;

    if (vol_evt->vol_type == SRV_PROF_VOL_RING)
    {
        /* Sync message volume with ring volume */
        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_RING_VOL_LEVEL, &vol_level);
        vol_level &= ~(vol_level & 0x40);
        srv_prof_set_current_profile_value(SRV_PROF_SETTINGS_MESSAGE_VOL_LEVEL, &vol_level);
    }

    return MMI_TRUE;
}
#endif

/* Above are external functions,  below are  in DCM functions */
#ifdef __MMI_AP_DCM_PROFILE__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_activate_profile_int
 * DESCRIPTION
 *  Activate profile
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: Successed
 *  MMI_FALSE: Failed
 *****************************************************************************/
static MMI_BOOL mmi_prof_activate_profile_int(mmi_prof_id_enum profile_id, MMI_BOOL need_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_ret result = SRV_PROF_RET_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (profile_id >= MMI_PROF_PROF_ID_BEGIN && profile_id <= MMI_PROF_PROF_ID_END)
    {
        result =  srv_prof_activate_profile((srv_prof_internal_profile_enum)profile_id);
        if (result == SRV_PROF_RET_SUCCESS)
        {
            if (need_popup)
            {
                mmi_prof_display_activate_profile_popup((mmi_prof_id_enum)profile_id);
            }
            return (MMI_BOOL)result;
        }
    }
        return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_deactivate_silent_profile_int
 * DESCRIPTION
 *  Deactivate silent profile
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: Successed
 *  MMI_FALSE: Failed
 *****************************************************************************/
static MMI_BOOL mmi_prof_deactivate_silent_profile_int(MMI_BOOL need_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_ret result;
    U16 profile_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_prof_deactivate_profile_by_external_module(SRV_PROF_SILENT_MODE);
    if (result == SRV_PROF_RET_SUCCESS)
    {
        profile_id = srv_prof_get_activated_profile();
        mmi_prof_display_activate_profile_popup((mmi_prof_id_enum)profile_id);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_get_string_id_from_audio_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_prof_get_string_id_from_audio_id(U16 audio_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    DYNAUDIOINFO *DownloadThemeTones;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (audio_id == 0)
    {
        return STR_GLOBAL_SILENT;
    }
    
    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    if (GetThemeV2TonesInfo(&DownloadThemeTones) != 0 && mmi_tm_get_current_theme_ringtone())
    {
        if ((U16)DownloadThemeTones[0].AudioId == audio_id)
        {
            return STR_ID_PROF_CURR_THEME;
        }
    }
    #endif
    
    return srv_prof_get_string_id_from_srv_audio_id(audio_id);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prof_display_activate_profile_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_display_activate_profile_popup(mmi_prof_id_enum profile_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PROF_SLIM_PROFILES__
    WCHAR popup_text[41];
#endif

#ifndef __MMI_PROF_BASIC_UI_STYLE__
    WCHAR title[41]; /*should bigger than MMI_PROF_PROFILE_NAME_LENGTH + mode activated + 1*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
    if (profile_id == MMI_PROFILE_MY_STYLE)
    {
        if (g_prof.is_default_name)
        {
            mmi_ucs2ncpy((CHAR*)g_prof.my_style_name, (CHAR*)GetString(STR_ID_PROF_MY_STYLE), MMI_PROF_PROFILE_NAME_LENGTH);
        }
        mmi_ucs2cpy((CHAR*)title, (CHAR *)g_prof.my_style_name);
        mmi_ucs2cat((CHAR*)title, GetString(STR_ID_PROF_MODE_ACTIVATED));
        mmi_popup_display_simple((WCHAR*)title, 
                                 MMI_EVENT_SUCCESS, 
                                 GRP_ID_ROOT, 
                                 NULL);
    }
#else
    if (profile_id >= MMI_PROFILE_NEW_1)
    {
        mmi_ucs2cpy((CHAR*)title, (CHAR *)g_prof.new_name[profile_id - MMI_PROFILE_NEW_1]);
        mmi_ucs2cat((CHAR*)title, GetString(STR_ID_PROF_MODE_ACTIVATED));
        mmi_popup_display_simple((WCHAR*)title, 
                                 MMI_EVENT_SUCCESS, 
                                 GRP_ID_ROOT, 
                                 NULL);
    }
#endif
    else
#endif    	
    {
    #ifndef __MMI_PROF_SLIM_PROFILES__
        mmi_popup_display_simple_ext(profile_id - MMI_PROFILE_GENERAL + STR_ID_PROF_GENERAL_ACTIVATED, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
    #else
        mmi_ucs2ncpy((CHAR*)popup_text, (CHAR *)GetString(profile_id - MMI_PROFILE_GENERAL + STR_ID_PROF_GENERAL), MMI_PROF_PROFILE_NAME_LENGTH);
        mmi_ucs2cat((CHAR*)popup_text, GetString(STR_ID_PROF_MODE_ACTIVATED));
        mmi_popup_display_simple((WCHAR*)popup_text, 
                                 MMI_EVENT_SUCCESS, 
                                 GRP_ID_ROOT, 
                                 NULL);
    #endif
    }

}

#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_prof_get_display_name_from_filepath
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_get_display_name_from_filepath(WCHAR* path, WCHAR* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR * filename_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filename_p = srv_fmgr_path_get_filename_ptr(path);
    if (filename_p != NULL)
    {
        mmi_wcscpy(filename, filename_p);
        srv_fmgr_path_hide_extension(filename);
    }
}
#endif    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_set_inline_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_profiles_set_inline_item(mmi_id inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 icon_list[PROFILE_INLINE_ITEM_NUM] = {0};
    U32 i = 0;
#ifdef __MMI_PROF_BASIC_UI_STYLE__
    U16 str_id;
#endif

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    S32 sim_num;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__    
    /*********************ALERT_TYPE_ITEM*************************/
#ifndef __MMI_PROF_BASIC_UI_STYLE__
	cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + ALERT_TYPE_ITEM, (void *)(g_prof_mem_p->cur_setting.alert_type));
#else
    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + ALERT_TYPE_ITEM, (void *)GetString(g_prof_mem_p->cur_setting.alert_type + STR_ID_PROF_RING_ONLY));
#endif

    /*********************RING_TYPE_ITEM*************************/
#ifndef __MMI_PROF_BASIC_UI_STYLE__
    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + RING_TYPE_ITEM, (void *)(g_prof_mem_p->cur_setting.ring_type));
#else
    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + RING_TYPE_ITEM, (void *)GetString(g_prof_mem_p->cur_setting.ring_type + STR_ID_PROF_RINGING));
#endif
    /*****************SIM1_RING_TONE_ITEM to SIM N***************/
    for (i = 0; i < SRV_PROF_MT_CALL_TONE_AMOUNT; i++)
    {
    #ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
        if (g_prof_mem_p->cur_setting.ring_tone[i] >= MMI_PROF_EXT_AUDIO_ID_BEGIN && g_prof_mem_p->cur_setting.ring_tone[i] < MMI_PROF_EXT_AUDIO_ID_END)
        {
            /* SIM2_RING_TONE_ITEM - SIM1_RING_TONE_ITEM =2 */
            cui_inline_set_value(inline_id, 
                             CUI_INLINE_ITEM_ID_BASE + SIM1_RING_TONE_ITEM+i*2, 
                             (void *)(g_prof_mem_p->ring_filename[i]));
        }
        else
    #endif    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */
        {
        	#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        	    if(ring_item_exist[i] == MMI_TRUE)
        	#endif
            cui_inline_set_value(inline_id, 
                             CUI_INLINE_ITEM_ID_BASE + SIM1_RING_TONE_ITEM+i*2, 
                             (void *)GetString(mmi_prof_get_string_id_from_audio_id((U16)g_prof_mem_p->cur_setting.ring_tone[i])));
        }
    }

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    sim_num = srv_sim_ctrl_get_num_of_inserted();
    if ((sim_num > 1) && (SRV_PROF_MT_CALL_TONE_AMOUNT > 1))
    {
        for (i=0; i < SRV_PROF_MT_CALL_TONE_AMOUNT; i++)
        {
        memset(sim_name,0, sizeof(sim_name));
        memset(ring_caption_string[i],0, sizeof(ring_caption_string[i]));
        mmi_ucs2cpy((CHAR *) sim_name, (CHAR *)mmi_netset_get_sim_name(MMI_SIM1 << i));
		if(*sim_name != 0 )
        {
            kal_wsprintf(ring_caption_string[i],"%w %w (%w)", GetString(STR_ID_PROF_SIM1 + i), GetString(STR_ID_PROF_RING_TONE), sim_name);
        }
		else
		{
		    kal_wsprintf(ring_caption_string[i],"%w %w", GetString(STR_ID_PROF_SIM1 + i), GetString(STR_ID_PROF_RING_TONE));
		}
        if(ring_item_exist[i] == MMI_TRUE)
        {
        cui_inline_set_item_caption(inline_id, 
                             CUI_INLINE_ITEM_ID_BASE + SIM1_RING_TONE_CAPTION + i*2, 
                             (PU8)ring_caption_string[i]);
        }
    }
    }
#endif

    /*********************VIDEO_CALL_TONE_ITEM*************************/
#ifdef __MMI_VIDEO_TELEPHONY__    
#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
    if (g_prof_mem_p->cur_setting.video_tone >= MMI_PROF_EXT_AUDIO_ID_BEGIN && g_prof_mem_p->cur_setting.video_tone < MMI_PROF_EXT_AUDIO_ID_END)
    {
        cui_inline_set_value(inline_id, 
                         CUI_INLINE_ITEM_ID_BASE + VIDEO_CALL_TONE_ITEM, 
                         (void*)(g_prof_mem_p->video_call_filename));
    }
    else
#endif    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */
    {
        cui_inline_set_value(inline_id, 
                         CUI_INLINE_ITEM_ID_BASE + VIDEO_CALL_TONE_ITEM, 
                         (void*)GetString(mmi_prof_get_string_id_from_audio_id((U16)g_prof_mem_p->cur_setting.video_tone)));
    }
#endif

    /*********************RING_VOL_ITEM*************************/
#ifndef __MMI_PROF_BASIC_UI_STYLE__
    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + RING_VOL_ITEM, (void*)g_prof_mem_p->cur_setting.ring_vol);
#else
    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + RING_VOL_ITEM, (void*)GetString(STR_GLOBAL_0+g_prof_mem_p->cur_setting.ring_vol));
#endif

#endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */

#ifdef __MMI_PROF_MSG_ALERTS_SUPPORT__
    /*********************SIM1_MSG_TONE_ITEM*************************/
#ifndef __MMI_PROF_SPLIT_MSG_TONES__    

#if !defined(__MMI_BT_DIALER_SUPPORT__) || defined(__MMI_BT_DIALER_WITH_GSM__)
for (i = 0; i < SRV_PROF_SMS_TONE_AMOUNT; i++)
{
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    if(message_item_exist[i] == MMI_TRUE)
#endif
    cui_inline_set_value(inline_id, 
                         CUI_INLINE_ITEM_ID_BASE + SIM1_MSG_TONE_ITEM+i*2, 
                         (void*)GetString(mmi_prof_get_string_id_from_audio_id((U16)g_prof_mem_p->cur_setting.msg_tone[i])));
}
#endif

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    sim_num = srv_sim_ctrl_get_num_of_inserted();
    if ((sim_num > 1) && (SRV_PROF_SMS_TONE_AMOUNT > 1))
    {
        for (i=0; i < SRV_PROF_SMS_TONE_AMOUNT; i++)
        {
        memset(sim_name,0, sizeof(sim_name));
        memset(message_caption_string[i],0, sizeof(message_caption_string[i]));
        mmi_ucs2cpy((CHAR *) sim_name, (CHAR *)mmi_netset_get_sim_name(MMI_SIM1 << i));
		if(*sim_name != 0 )
        {
            kal_wsprintf(message_caption_string[i],"%w %w (%w)", GetString(STR_ID_PROF_SIM1 + i), GetString(STR_GLOBAL_MESSAGE), sim_name);
        }
		else
		{
		    kal_wsprintf(message_caption_string[i],"%w %w", GetString(STR_ID_PROF_SIM1 + i), GetString(STR_GLOBAL_MESSAGE));
		}
        
        if(message_item_exist[i] == MMI_TRUE)
        {
        cui_inline_set_item_caption(inline_id, 
                             CUI_INLINE_ITEM_ID_BASE + SIM1_MSG_TONE_CAPTION + i*2, 
                             (PU8)message_caption_string[i]);
        }
    }
    }
#endif

// TODO: 如下几个地方需要考虑
#else /*__MMI_PROF_SPLIT_MSG_TONES__*/

    /*********************SMS_TONE_ITEM*************************/
    cui_inline_set_value(inline_id, 
                         CUI_INLINE_ITEM_ID_BASE + SMS_TONE_ITEM, 
                         (void*)GetString(mmi_prof_get_string_id_from_audio_id((U16)g_prof_mem_p->cur_setting.sms_tone)));
    
    /*********************MMS_TONE_ITEM*************************/
    #ifdef MMS_SUPPORT
    cui_inline_set_value(inline_id, 
                         CUI_INLINE_ITEM_ID_BASE + MMS_TONE_ITEM, 
                         (void*)GetString(mmi_prof_get_string_id_from_audio_id((U16)g_prof_mem_p->cur_setting.mms_tone)));
    #endif

    /*********************EMAIL_TONE_ITEM*************************/
    #ifdef __MMI_EMAIL__
    cui_inline_set_value(inline_id, 
                         CUI_INLINE_ITEM_ID_BASE + EMAIL_TONE_ITEM, 
                         (void*)GetString(mmi_prof_get_string_id_from_audio_id((U16)g_prof_mem_p->cur_setting.email_tone)));
    #endif

    /*********************VOICE_TONE_ITEM*************************/
    #ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
#endif /*__MMI_PROF_SPLIT_MSG_TONES__*/

    /*********************SIM2_MSG_TONE_ITEM*************************/

/*
#if SRV_PROF_SMS_TONE_AMOUNT == 2      
    cui_inline_set_value(inline_id, 
                         CUI_INLINE_ITEM_ID_BASE + SIM2_MSG_TONE_ITEM, 
                         (void*)GetString(mmi_prof_get_string_id_from_audio_id((U16)g_prof_mem_p->cur_setting.sim2_msg_tone)));
#endif
*/

    /*********************MSG_VOL_ITEM*************************/
#if !(defined(__MMI_MAINLCD_96X64__) || defined(__MMI_PROF_SLIM_PROFILES__))
#ifndef __MMI_PROF_BASIC_UI_STYLE__
    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + MSG_VOL_ITEM, (void*)g_prof_mem_p->cur_setting.msg_vol);
#else
    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + MSG_VOL_ITEM, (void*)GetString(STR_GLOBAL_0+g_prof_mem_p->cur_setting.msg_vol));
#endif
#endif    // __MMI_MAINLCD_96X64__

#endif /* __MMI_PROF_MSG_ALERTS_SUPPORT__ */

    /*********************KEYPAD_TONE_ITEM*************************/
#ifdef __MMI_PROF_BASIC_UI_STYLE__
    if (g_prof_mem_p->cur_setting.keypad_tone == MMI_PROF_KEYPAD_SILENT)
        str_id = STR_GLOBAL_SILENT;
    else
        str_id = g_prof_mem_p->cur_setting.keypad_tone-1 + STR_ID_PROF_CLICK;
    
    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + KEYPAD_TONE_ITEM, (void *)GetString(str_id));
#else
    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + KEYPAD_TONE_ITEM, (void *)g_prof_mem_p->cur_setting.keypad_tone);
#endif
    /*********************KEYPAD_VOL_ITEM*************************/
#ifndef __MMI_PROF_BASIC_UI_STYLE__
    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + KEYPAD_VOL_ITEM, (void*)g_prof_mem_p->cur_setting.keypad_vol);
#else
    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + KEYPAD_VOL_ITEM, (void*)GetString(STR_GLOBAL_0+g_prof_mem_p->cur_setting.keypad_vol));
#endif
    
#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if !defined(__MMI_POWER_ON_OFF_MUTE__) && !defined(__MMI_POWER_ON_OFF_NO_CUSTOMIZE__)
    /*********************POWER_ON_TONE_ITEM*************************/
    cui_inline_set_value(inline_id, 
                         CUI_INLINE_ITEM_ID_BASE + POWER_ON_TONE_ITEM, 
                         (void*)GetString(mmi_prof_get_string_id_from_audio_id((U16)g_prof_mem_p->cur_setting.power_on_tone)));
    
    /*********************POWER_OFF_TONE_ITEM*************************/
    cui_inline_set_value(inline_id, 
                         CUI_INLINE_ITEM_ID_BASE + POWER_OFF_TONE_ITEM, 
                         (void*)GetString(mmi_prof_get_string_id_from_audio_id((U16)g_prof_mem_p->cur_setting.power_off_tone)));
#endif

#ifdef __MMI_CLAMSHELL__
    /*********************COVER_OPEN_TONE_ITEM*************************/
    cui_inline_set_value(inline_id, 
                         CUI_INLINE_ITEM_ID_BASE + COVER_OPEN_TONE_ITEM, 
                         (void*)GetString(mmi_prof_get_string_id_from_audio_id((U16)g_prof_mem_p->cur_setting.cover_open_tone)));
    
    /*********************COVER_CLOSE_TONE_ITEM*************************/
    cui_inline_set_value(inline_id, 
                         CUI_INLINE_ITEM_ID_BASE + COVER_CLOSE_TONE_ITEM, 
                         (void*)GetString(mmi_prof_get_string_id_from_audio_id((U16)g_prof_mem_p->cur_setting.cover_close_tone)));
   #endif

    /*********************SYSTEM_ALERT_ITEM*************************/
#if !(defined(__MMI_MAINLCD_96X64__) || defined(__MMI_PROF_SLIM_PROFILES__))
#ifdef __MMI_PROF_BASIC_UI_STYLE__
    if (g_prof_mem_p->cur_setting.system_alert == MMI_PROF_ON)
        str_id = STR_GLOBAL_ON;
    else
        str_id = STR_GLOBAL_OFF;

    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + SYSTEM_ALERT_ITEM, (void *)GetString(str_id));
#else
	cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + SYSTEM_ALERT_ITEM, (void *)g_prof_mem_p->cur_setting.system_alert);
#endif
#endif    // __MMI_MAINLCD_96X64__

#ifndef __MMI_PROF_BASIC_UI_STYLE__
#ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__

    /*********************INTELLIGENT_CALL_ALERT_ITEM*************************/
#if defined(__MMI_INTELLIGENT_CALL_ALERT__)    
    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + INTELLIGENT_CALL_ALERT_ITEM, (void *)g_prof_mem_p->cur_setting.intelligent_call_alert);
#endif

#endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */

    /*********************STATUS_LED_ITEM*************************/
#if !defined(HW_LED_NOT_SUPPORT)    
    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + STATUS_LED_ITEM, (void *)g_prof_mem_p->cur_setting.status_led);
#endif
#endif /*#ifndef __MMI_PROF_BASIC_UI_STYLE__    */

    for (i = 0; i < PROFILE_INLINE_ITEM_NUM; i++)
    {
        icon_list[i] = IMG_GLOBAL_L1 + i/2;
        icon_list[++i] = 0;
    }
    cui_inline_set_icon_list(inline_id, &icon_list[0]);

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
    {
        sim_num = srv_sim_ctrl_get_num_of_inserted();

        if (sim_num == 0)
        {
            cui_inline_set_item_caption(inline_id, 
                    CUI_INLINE_ITEM_ID_BASE + SIM1_RING_TONE_CAPTION, 
                    (PU8)GetString(STR_ID_PROF_RING_TONE));
            ring_item_exist[0] = MMI_TRUE;

            for(i=1; i<SRV_PROF_MT_CALL_TONE_AMOUNT; i++)
            {
                cui_inline_delete_item(inline_id, CUI_INLINE_ITEM_ID_BASE + SIM1_RING_TONE_CAPTION + i*2);
                cui_inline_delete_item(inline_id, CUI_INLINE_ITEM_ID_BASE + SIM1_RING_TONE_ITEM + i*2);
                ring_item_exist[i] = MMI_FALSE;
            }
        }
        else if(sim_num == 1)
        {
            for(i=0; i<SRV_PROF_MT_CALL_TONE_AMOUNT; i++)
            {
                if (!srv_sim_ctrl_is_inserted(MMI_SIM1 << i))
                {
                    cui_inline_delete_item(inline_id, CUI_INLINE_ITEM_ID_BASE + SIM1_RING_TONE_CAPTION + i*2);
                    cui_inline_delete_item(inline_id, CUI_INLINE_ITEM_ID_BASE + SIM1_RING_TONE_ITEM + i*2);
                    ring_item_exist[i] = MMI_FALSE;
                }
                else
                {
                    cui_inline_set_item_caption(inline_id, 
                             CUI_INLINE_ITEM_ID_BASE + SIM1_RING_TONE_CAPTION + i*2, 
                             (PU8)GetString(STR_ID_PROF_RING_TONE));
                    ring_item_exist[i] = MMI_TRUE;
                }
            }
        }
        else
        {
            for(i=0; i<SRV_PROF_MT_CALL_TONE_AMOUNT; i++)
            {
                if (!srv_sim_ctrl_is_inserted(MMI_SIM1 << i))
                {
                    cui_inline_delete_item(inline_id, CUI_INLINE_ITEM_ID_BASE + SIM1_RING_TONE_CAPTION + i*2);
                    cui_inline_delete_item(inline_id, CUI_INLINE_ITEM_ID_BASE + SIM1_RING_TONE_ITEM + i*2);
                    ring_item_exist[i] = MMI_FALSE;
                }
                else
                {
                    ring_item_exist[i] = MMI_TRUE;
                }
            }
        }
    }

    if (SRV_PROF_SMS_TONE_AMOUNT > 1)
    {
        sim_num = srv_sim_ctrl_get_num_of_inserted();

        if (sim_num == 0)
        {
            cui_inline_set_item_caption(inline_id, 
                             CUI_INLINE_ITEM_ID_BASE + SIM1_MSG_TONE_CAPTION, 
                             (PU8)GetString(STR_GLOBAL_MESSAGE));
            message_item_exist[0] = MMI_TRUE;

            for(i=1; i<SRV_PROF_SMS_TONE_AMOUNT; i++)
            {
                cui_inline_delete_item(inline_id, CUI_INLINE_ITEM_ID_BASE + SIM1_MSG_TONE_CAPTION + i*2);
                cui_inline_delete_item(inline_id, CUI_INLINE_ITEM_ID_BASE + SIM1_MSG_TONE_ITEM + i*2);
                message_item_exist[i] = MMI_FALSE;
            }
        }
        else if(sim_num == 1)
        {
            for(i=0; i<SRV_PROF_SMS_TONE_AMOUNT; i++)
            {
                if (!srv_sim_ctrl_is_inserted(MMI_SIM1 << i))
                {
                    cui_inline_delete_item(inline_id, CUI_INLINE_ITEM_ID_BASE + SIM1_MSG_TONE_CAPTION + i*2);
                    cui_inline_delete_item(inline_id, CUI_INLINE_ITEM_ID_BASE + SIM1_MSG_TONE_ITEM + i*2);
                    message_item_exist[i] = MMI_FALSE;
                }
                else
                {
                    cui_inline_set_item_caption(inline_id, 
                             CUI_INLINE_ITEM_ID_BASE + SIM1_MSG_TONE_CAPTION + i*2, 
                             (PU8)GetString(STR_GLOBAL_MESSAGE));
                    message_item_exist[i] = MMI_TRUE;
                }
            }
        }
        else
        {
            for(i=0; i<SRV_PROF_MT_CALL_TONE_AMOUNT; i++)
            {
                if (!srv_sim_ctrl_is_inserted(MMI_SIM1 << i))
                {
                    cui_inline_delete_item(inline_id, CUI_INLINE_ITEM_ID_BASE + SIM1_MSG_TONE_CAPTION + i*2);
                    cui_inline_delete_item(inline_id, CUI_INLINE_ITEM_ID_BASE + SIM1_MSG_TONE_ITEM + i*2);
                    message_item_exist[i] = MMI_FALSE;
                }
                else
                {
                    message_item_exist[i] = MMI_TRUE;
                }
            }
        }
    }
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_entry_customize_scrn
 * DESCRIPTION
 *  Entry function for personalise screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_entry_customize_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id inline_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_prof_mem_p == NULL)
    {
        g_prof_mem_p = (profile_mem_struct*)applib_mem_ap_alloc(APPLIB_MEM_AP_ID_USER_PROF, sizeof(profile_mem_struct));
        if (g_prof_mem_p == NULL)
        {
            mmi_frm_appmem_prompt_to_release_mem(
                APPLIB_MEM_AP_ID_USER_PROF,
                GetRootTitleIcon(MAIN_MENU_PROFILES_MENUID),
                sizeof(profile_mem_struct),
                mmi_prof_entry_customize_scrn);
            return;
        }
    }
    mmi_prof_get_cur_settings();

#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
#ifdef __MMI_TOUCH_FEEDBACK_VIBRATE_LEVEL_SUPPORT__
/* under construction !*/
#endif
#endif
    g_prof_mem_p->is_playing = MMI_FALSE;
    
    inline_id = cui_inline_create(GRP_ID_PROFILES, &prof_inline_screen);
    if (inline_id != GRP_ID_INVALID)
    {
        g_prof_mem_p->inline_gid = inline_id;

/* When profiles is not BASIC UI. Do not support 96X64. For 96X64 title is not required as it is the settings name */
#ifndef  __MMI_MAINLCD_96X64__
    #ifndef __MMI_PROF_BASIC_UI_STYLE__
    #ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__
        cui_inline_set_softkey_icon(inline_id, 
                                    CUI_INLINE_ITEM_ID_BASE + RING_VOL_ITEM, 
                                    MMI_CENTER_SOFTKEY, 
                                    IMG_GLOBAL_SAVE_CSK);
    #endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */
    #ifdef __MMI_PROF_MSG_ALERTS_SUPPORT__
    #ifndef __MMI_PROF_SLIM_PROFILES__
        cui_inline_set_softkey_icon(inline_id, 
                                    CUI_INLINE_ITEM_ID_BASE + MSG_VOL_ITEM, 
                                    MMI_CENTER_SOFTKEY, 
                                    IMG_GLOBAL_SAVE_CSK);
    #endif    // __MMI_PROF_SLIM_PROFILES__  
    #endif /* __MMI_PROF_MSG_ALERTS_SUPPORT__ */
        cui_inline_set_softkey_icon(inline_id, 
                                    CUI_INLINE_ITEM_ID_BASE + KEYPAD_VOL_ITEM, 
                                    MMI_CENTER_SOFTKEY, 
                                    IMG_GLOBAL_SAVE_CSK);
    #endif

    #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    #ifndef __MMI_PROF_BASIC_UI_STYLE__
    #ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__
        cui_inline_set_item_attributes(inline_id,  
                                       CUI_INLINE_ITEM_ID_BASE + RING_VOL_ITEM, 
                                       CUI_INLINE_SET_EXT_ATTRIBUTE,
                                       INLINE_PBAR_DIVIDED | INLINE_PBAR_FILL_GRADIENT);
    #endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */
    #ifdef __MMI_PROF_MSG_ALERTS_SUPPORT__
    #ifndef __MMI_PROF_SLIM_PROFILES__
        cui_inline_set_item_attributes(inline_id, 
                                       CUI_INLINE_ITEM_ID_BASE + MSG_VOL_ITEM, 
                                       CUI_INLINE_SET_EXT_ATTRIBUTE, 
                                       INLINE_PBAR_DIVIDED | INLINE_PBAR_FILL_GRADIENT);
    #endif    // #ifndef __MMI_PROF_SLIM_PROFILES__
    #endif /* __MMI_PROF_MSG_ALERTS_SUPPORT__ */
        cui_inline_set_item_attributes(inline_id, 
                                       CUI_INLINE_ITEM_ID_BASE + KEYPAD_VOL_ITEM, 
                                       CUI_INLINE_SET_EXT_ATTRIBUTE, 
                                       INLINE_PBAR_DIVIDED | INLINE_PBAR_FILL_GRADIENT);
    #endif

    #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    #ifndef __MMI_PROF_BASIC_UI_STYLE__
      #ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__
        cui_inline_set_softkey_text(inline_id, CUI_INLINE_ITEM_ID_BASE + RING_VOL_ITEM, MMI_LEFT_SOFTKEY, STR_GLOBAL_SAVE);
      #endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */
      #ifdef __MMI_PROF_MSG_ALERTS_SUPPORT__
      #ifndef __MMI_PROF_SLIM_PROFILES__
        cui_inline_set_softkey_text(inline_id, CUI_INLINE_ITEM_ID_BASE + MSG_VOL_ITEM, MMI_LEFT_SOFTKEY, STR_GLOBAL_SAVE);
      #endif    // __MMI_PROF_SLIM_PROFILES__
      #endif /* __MMI_PROF_MSG_ALERTS_SUPPORT__ */
        cui_inline_set_softkey_text(inline_id, CUI_INLINE_ITEM_ID_BASE + KEYPAD_VOL_ITEM, MMI_LEFT_SOFTKEY, STR_GLOBAL_SAVE);
    #endif /* __MMI_PROF_BASIC_UI_STYLE__ */
    #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
    #endif /* __MMI_TOUCH_FEEDBACK_SUPPORT__ */

    #if !defined(__MMI_PROF_BASIC_UI_STYLE__) && !defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
        if (g_prof.curr_profile != MMI_PROFILE_MY_STYLE)
        {
            cui_inline_set_title_string(inline_id, (WCHAR*)GetString(g_prof.curr_profile - MMI_PROF_PROF_ID_BEGIN + STR_ID_PROF_GENERAL));
        }
        else
        {
            cui_inline_set_title_string(inline_id, (WCHAR*)g_prof.my_style_name);
        }
    #elif defined(__MMI_PROF_BASIC_UI_STYLE__)
        cui_inline_set_title_string(inline_id, (WCHAR*)GetString(g_prof.curr_profile - MMI_PROF_PROF_ID_BEGIN + STR_ID_PROF_GENERAL));
    #elif defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
        if (g_prof.curr_profile <= MMI_PROFILE_OUTDOOR)
        {
            cui_inline_set_title_string(inline_id, (WCHAR*)GetString(g_prof.curr_profile - MMI_PROF_PROF_ID_BEGIN + STR_ID_PROF_GENERAL));
        }
        else
        {
            cui_inline_set_title_string(inline_id, (WCHAR*)g_prof.new_name[g_prof.curr_profile - MMI_PROFILE_NEW_1]);
        }
    #endif        
        cui_inline_set_title_icon(inline_id, GetRootTitleIcon(MAIN_MENU_PROFILES_MENUID));
#endif    //  __MMI_MAINLCD_96X64__
        cui_inline_run(inline_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prof_get_cur_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_get_cur_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_setting_struct settings;
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    srv_prof_get_profile_values((srv_prof_internal_profile_enum)g_prof.curr_profile, &settings);
    
    for (i = 0; i < SRV_PROF_MT_CALL_TONE_AMOUNT; i++)
    {
        g_prof_mem_p->cur_setting.ring_tone[i] = settings.mt_call_tone[i];
    }
    
#ifdef __MMI_VIDEO_TELEPHONY__    
    g_prof_mem_p->cur_setting.video_tone = settings.vt_call_tone[0];
#endif

    g_prof_mem_p->cur_setting.ring_vol = settings.ring_vol;
#ifndef __MMI_PROF_SPLIT_MSG_TONES__
    for(i=0; i<SRV_PROF_SMS_TONE_AMOUNT; i++)
    {
        g_prof_mem_p->cur_setting.msg_tone[i] = settings.sms_tone[i];
    }
#else /*__MMI_PROF_SPLIT_MSG_TONES__*/
    g_prof_mem_p->cur_setting.sms_tone = settings.sms_tone[0];
    #ifdef MMS_SUPPORT    
    g_prof_mem_p->cur_setting.mms_tone = settings.mms_tone[0];
    #endif
    #ifdef __MMI_EMAIL__
    g_prof_mem_p->cur_setting.email_tone = settings.email_tone[0];
    #endif
    #ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
    #endif
#endif /*__MMI_PROF_SPLIT_MSG_TONES__*/

#if !(defined(__MMI_MAINLCD_96X64__) || defined(__MMI_PROF_SLIM_PROFILES__))
    g_prof_mem_p->cur_setting.msg_vol = settings.msg_vol;
#endif    // __MMI_MAINLCD_96X64__
    g_prof_mem_p->cur_setting.keypad_vol = settings.keypad_vol;

#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
#endif

#if !defined(__MMI_POWER_ON_OFF_MUTE__) && !defined(__MMI_POWER_ON_OFF_NO_CUSTOMIZE__)
    g_prof_mem_p->cur_setting.power_on_tone = settings.power_on_tone;
    g_prof_mem_p->cur_setting.power_off_tone = settings.power_off_tone;
#endif

#ifdef __MMI_CLAMSHELL__
    g_prof_mem_p->cur_setting.cover_open_tone = settings.cover_open_tone;
    g_prof_mem_p->cur_setting.cover_close_tone = settings.cover_close_tone;
#endif

#if !defined(HW_LED_NOT_SUPPORT)    
    g_prof_mem_p->cur_setting.status_led = settings.led_pattern;
#endif

#if !(defined(__MMI_MAINLCD_96X64__) || defined(__MMI_PROF_SLIM_PROFILES__))
    if (settings.system_alert)
    {
        g_prof_mem_p->cur_setting.system_alert = MMI_PROF_ON;
    }
    else
    {
        g_prof_mem_p->cur_setting.system_alert = MMI_PROF_OFF;
    }
#endif    // __MMI_MAINLCD_96X64__
    
#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    if (settings.intelligent_call_alert)
    {
            g_prof_mem_p->cur_setting.intelligent_call_alert = MMI_PROF_ON;
    }
    else
    {
        g_prof_mem_p->cur_setting.intelligent_call_alert = MMI_PROF_OFF;
    }
#endif

    switch (settings.ring_type)
    {
        case SRV_PROF_RING_TYPE_REPEAT:
    #ifdef __MMI_AUDIO_CRESCENDO_SUPPORT__        
        case SRV_PROF_RING_TYPE_ASCENDING:
    #endif        
        {
            g_prof_mem_p->cur_setting.ring_type = settings.ring_type + MMI_PROF_RING_TYPE_REPEAT;
            break;
        }
        case SRV_PROF_RING_TYPE_BEEP_ONCE:
        {
            g_prof_mem_p->cur_setting.ring_type = MMI_PROF_RING_TYPE_BEEP_ONCE;
            break;
        }
        default:
        {
            g_prof_mem_p->cur_setting.ring_type = MMI_PROF_RING_TYPE_REPEAT;
            break;
        }
    }

    switch (settings.alert_type)
    {
        case SRV_PROF_ALERT_TYPE_RING:
        case SRV_PROF_ALERT_TYPE_VIB_ONLY:
        case SRV_PROF_ALERT_TYPE_VIB_AND_RING:
        case SRV_PROF_ALERT_TYPE_VIB_THEN_RING:
        {
            g_prof_mem_p->cur_setting.alert_type = settings.alert_type - 1 + MMI_PROF_ALERT_TYPE_RING;
            break;
        }
        default:
        {
            g_prof_mem_p->cur_setting.alert_type = MMI_PROF_ALERT_TYPE_RING;
            break;
        }
    }
    
#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
#ifdef __MMI_TOUCH_FEEDBACK_VIBRATE_LEVEL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
    
    switch (settings.keypad_tone_type)
    {
        case SRV_PROF_KEYPAD_SILENT:
        case SRV_PROF_KEYPAD_CLICK:
        case SRV_PROF_KEYPAD_TONE:
    #if defined( __MMI_HUMAN_VOICE_KEYPAD_TONE__ )    
        case SRV_PROF_KEYPAD_NUM_1: 
    #endif
        {
            g_prof_mem_p->cur_setting.keypad_tone = settings.keypad_tone_type + MMI_PROF_KEYPAD_SILENT;
            break;
        }
    #if defined( __MMI_CUST_KEYPAD_TONE__ )
        case SRV_PROF_KEYPAD_CUST_1:             /* Customer 1 */
        {
            g_prof_mem_p->cur_setting.keypad_tone = MMI_PROF_KEYPAD_CUST_1;
            break;
        }
    #endif
        default:
            g_prof_mem_p->cur_setting.keypad_tone = MMI_PROF_KEYPAD_TONE;
            break;

    }

#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
    for (i = 0; i < SRV_PROF_MT_CALL_TONE_AMOUNT; i++)
    {
        if (g_prof_mem_p->cur_setting.ring_tone[i] >= MMI_PROF_EXT_AUDIO_ID_BEGIN && 
            g_prof_mem_p->cur_setting.ring_tone[i] < MMI_PROF_EXT_AUDIO_ID_END)
        {
            if (srv_prof_get_file_path_by_audio_id(g_prof_mem_p->ring_tone_path[i], g_prof_mem_p->cur_setting.ring_tone[i]) == SRV_PROF_RET_SUCCESS)
            {
                mmi_prof_get_display_name_from_filepath(g_prof_mem_p->ring_tone_path[i], g_prof_mem_p->ring_filename[i]);
            }
        }
    }

#ifdef __MMI_VIDEO_TELEPHONY__    
    if (g_prof_mem_p->cur_setting.video_tone >= MMI_PROF_EXT_AUDIO_ID_BEGIN && 
        g_prof_mem_p->cur_setting.video_tone < MMI_PROF_EXT_AUDIO_ID_END)
    {
        if (srv_prof_get_file_path_by_audio_id(g_prof_mem_p->video_call_tone_path, g_prof_mem_p->cur_setting.video_tone) == SRV_PROF_RET_SUCCESS)
        {
            mmi_prof_get_display_name_from_filepath(g_prof_mem_p->video_call_tone_path, g_prof_mem_p->video_call_filename);
        }
        else
        {
            // TODO: update sim2 ring tone
        }
    }
#endif
#endif    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */

}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_save_cur_settings
 * DESCRIPTION
 *  Save settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_save_cur_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_setting_struct settings;
    U8 slot;
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    /*get old settings, if some old settings have not changed, save it as original*/
    srv_prof_get_profile_values((srv_prof_internal_profile_enum)g_prof.curr_profile, &settings);
    
#ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__
    settings.ring_vol = g_prof_mem_p->cur_setting.ring_vol;
#endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */

#ifdef __MMI_PROF_MSG_ALERTS_SUPPORT__
#ifndef __MMI_PROF_SPLIT_MSG_TONES__
    for (i=0; i<SRV_PROF_SMS_TONE_AMOUNT; i++)
	{
        settings.sms_tone[i] = g_prof_mem_p->cur_setting.msg_tone[i];
	}
#else /*__MMI_PROF_SPLIT_MSG_TONES__*/
    settings.sms_tone[0] = g_prof_mem_p->cur_setting.sms_tone;
    #ifdef MMS_SUPPORT    
    settings.mms_tone[0] = g_prof_mem_p->cur_setting.mms_tone;
    #endif
    #ifdef __MMI_EMAIL__
    settings.email_tone[0] = g_prof_mem_p->cur_setting.email_tone;
    #endif
    #ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
    #endif
#endif /*__MMI_PROF_SPLIT_MSG_TONES__*/

#if !(defined(__MMI_MAINLCD_96X64__) || defined(__MMI_PROF_SLIM_PROFILES__))
    settings.msg_vol = g_prof_mem_p->cur_setting.msg_vol;
#else
    settings.msg_vol = g_prof_mem_p->cur_setting.ring_vol;
#endif    // __MMI_MAINLCD_96X64__

#endif /* __MMI_PROF_MSG_ALERTS_SUPPORT__ */

    settings.keypad_vol = g_prof_mem_p->cur_setting.keypad_vol;

#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
#endif
    
#if !defined(__MMI_POWER_ON_OFF_MUTE__) && !defined(__MMI_POWER_ON_OFF_NO_CUSTOMIZE__)
    settings.power_on_tone = g_prof_mem_p->cur_setting.power_on_tone;
    settings.power_off_tone = g_prof_mem_p->cur_setting.power_off_tone;
#endif

#ifdef __MMI_CLAMSHELL__
    settings.cover_open_tone = g_prof_mem_p->cur_setting.cover_open_tone;
    settings.cover_close_tone = g_prof_mem_p->cur_setting.cover_close_tone;
#endif

#if !defined(HW_LED_NOT_SUPPORT)    
    settings.led_pattern = g_prof_mem_p->cur_setting.status_led;
#endif

#if !(defined(__MMI_MAINLCD_96X64__) || defined(__MMI_PROF_SLIM_PROFILES__))
    if (g_prof_mem_p->cur_setting.system_alert == MMI_PROF_ON)
    {
        settings.system_alert = MMI_TRUE;
    }
    else
    {
        settings.system_alert = MMI_FALSE;
    }
#endif    // __MMI_MAINLCD_96X64__
    
#ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__

#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    if (g_prof_mem_p->cur_setting.intelligent_call_alert == MMI_PROF_ON)
    {
        settings.intelligent_call_alert = MMI_TRUE;
    }
    else
    {
        settings.intelligent_call_alert = MMI_FALSE;
    }
#endif

    switch (g_prof_mem_p->cur_setting.ring_type)
    {
        case MMI_PROF_RING_TYPE_REPEAT:
    #ifdef __MMI_AUDIO_CRESCENDO_SUPPORT__        
        case MMI_PROF_RING_TYPE_ASCENDING:
    #endif
        {
            settings.ring_type = (srv_prof_ring_type_enum)(g_prof_mem_p->cur_setting.ring_type + SRV_PROF_RING_TYPE_REPEAT);
            break;
        }       
        case MMI_PROF_RING_TYPE_BEEP_ONCE:
        {
            settings.ring_type = SRV_PROF_RING_TYPE_BEEP_ONCE;
            break;
        }
        default:
        {
            settings.ring_type = SRV_PROF_RING_TYPE_REPEAT;
            break;
        }
    }

#endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */

    switch (g_prof_mem_p->cur_setting.alert_type)
    {
        case MMI_PROF_ALERT_TYPE_RING:
        case MMI_PROF_ALERT_TYPE_VIB_ONLY:
        case MMI_PROF_ALERT_TYPE_VIB_AND_RING:
        case MMI_PROF_ALERT_TYPE_VIB_THEN_RING:
        {
            settings.alert_type = (srv_prof_alert_type_enum)(g_prof_mem_p->cur_setting.alert_type + SRV_PROF_ALERT_TYPE_RING);
            break;
        }
        default:
        {
            settings.alert_type = SRV_PROF_ALERT_TYPE_RING;
            break;
        }
    }

#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__ 
#ifdef __MMI_TOUCH_FEEDBACK_VIBRATE_LEVEL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

    switch (g_prof_mem_p->cur_setting.keypad_tone)
    {
        case MMI_PROF_KEYPAD_SILENT:
        case MMI_PROF_KEYPAD_CLICK:
        case MMI_PROF_KEYPAD_TONE:
    #if defined( __MMI_HUMAN_VOICE_KEYPAD_TONE__ )    
        case MMI_PROF_KEYPAD_NUM_1:              /* Special number key 1 */
    #endif
        {
            settings.keypad_tone_type = (srv_prof_keypad_tone_type_enum)(g_prof_mem_p->cur_setting.keypad_tone + SRV_PROF_KEYPAD_SILENT);
            break;
        }
    #if defined( __MMI_CUST_KEYPAD_TONE__ )
        case MMI_PROF_KEYPAD_CUST_1:             /* Customer 1 */
        {
            settings.keypad_tone_type = SRV_PROF_KEYPAD_CUST_1;
            break;
        }
    #endif
        default:
        {
            settings.keypad_tone_type = SRV_PROF_KEYPAD_TONE;
            break;
        }
    }

#ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__

#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
    for (i = 0; i < SRV_PROF_MT_CALL_TONE_AMOUNT; i++)
    {
        if (g_prof_mem_p->cur_setting.ring_tone[i] >= MMI_PROF_EXT_AUDIO_ID_BEGIN && g_prof_mem_p->cur_setting.ring_tone[i] < MMI_PROF_EXT_AUDIO_ID_END)
    {
            mmi_prof_get_ext_file_slot((U16)g_prof.curr_profile, (srv_prof_settings_enum)(SRV_PROF_SETTINGS_MT_CALL_TONE+i), &slot);//the id of card i = SRV_PROF_SETTINGS_MT_CALL_TONE+i 
            g_prof_mem_p->cur_setting.ring_tone[i] = MMI_PROF_EXT_AUDIO_ID_BEGIN + slot;
            srv_prof_set_file_path_to_ext_melody(slot, g_prof_mem_p->ring_tone_path[i]);
        }
    }

#ifdef __MMI_VIDEO_TELEPHONY__    
    if (g_prof_mem_p->cur_setting.video_tone >= MMI_PROF_EXT_AUDIO_ID_BEGIN && g_prof_mem_p->cur_setting.video_tone < MMI_PROF_EXT_AUDIO_ID_END)
    {
        mmi_prof_get_ext_file_slot(g_prof.curr_profile, SRV_PROF_SETTINGS_VT_CALL_TONE, &slot);
        g_prof_mem_p->cur_setting.video_tone = MMI_PROF_EXT_AUDIO_ID_BEGIN + slot;
        srv_prof_set_file_path_to_ext_melody(slot, g_prof_mem_p->video_call_tone_path);
    }
#endif
#endif    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */

    for (i = 0; i < SRV_PROF_MT_CALL_TONE_AMOUNT; i++)
    {
        settings.mt_call_tone[i] = g_prof_mem_p->cur_setting.ring_tone[i];
    }
    
#ifdef __MMI_VIDEO_TELEPHONY__    
    settings.vt_call_tone[0] = g_prof_mem_p->cur_setting.video_tone;
#endif

#endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */

    srv_prof_set_profile_values((srv_prof_internal_profile_enum)g_prof.curr_profile, &settings);
    if (g_prof.curr_profile == g_prof.activated_profile)
    {
        mmi_prof_show_alert_status_icon();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prof_app_mem_stop_callback
 * DESCRIPTION
 *  Entry function for main profile screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_app_mem_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prof_mem_p != NULL)
    {
        applib_mem_ap_free(g_prof_mem_p);
        g_prof_mem_p = NULL;
        mmi_frm_group_close(GRP_ID_PROFILES);
     }
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_USER_PROF, KAL_TRUE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_entry_main_scrn_internal
 * DESCRIPTION
 *  Entry function for main profile screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_entry_main_scrn_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_id menu_gid;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
    menu_gid = cui_menu_create(
                    GRP_ID_PROFILES, 
                    CUI_MENU_SRC_TYPE_RESOURCE, 
                    CUI_MENU_TYPE_APPMAIN, 
                    MAIN_MENU_PROFILES_MENUID, 
                    MMI_TRUE, 
                    NULL);
#else
    menu_gid = cui_menu_create(
                    GRP_ID_PROFILES, 
                    CUI_MENU_SRC_TYPE_APPCREATE,
                    CUI_MENU_TYPE_APPMAIN, 
                    MAIN_MENU_PROFILES_MENUID, 
                    MMI_FALSE,
                    NULL);
#endif

    if (menu_gid == GRP_ID_INVALID)
    {
        return;
    }
    cui_menu_set_default_title_image_by_id(menu_gid, GetRootTitleIcon(MAIN_MENU_PROFILES_MENUID));
#ifndef  __MMI_MAINLCD_96X64__ 
    cui_menu_set_currlist_highlighted_id(menu_gid, (mmi_menu_id)(g_prof.activated_profile - MMI_PROF_PROF_ID_BEGIN + MENU_ID_PROF_GENERAL));
#else
    cui_menu_set_currlist_highlighted_id(menu_gid, (mmi_menu_id)MENU_ID_PROF_GENERAL);
#endif
    cui_menu_run(menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prof_entry_options_scrn
 * DESCRIPTION
 *  Entry function for Profiles Options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_entry_options_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_id menu_gid;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_gid = cui_menu_create(
                    GRP_ID_PROFILES, 
                    CUI_MENU_SRC_TYPE_RESOURCE, 
                    CUI_MENU_TYPE_OPTION, 
                    MENU_ID_PROF_MAIN_OPTIONS, 
                    MMI_TRUE, 
                    NULL);
    if (menu_gid != GRP_ID_INVALID)
    {
        cui_menu_set_default_title_image_by_id(menu_gid, GetRootTitleIcon(MAIN_MENU_PROFILES_MENUID));
        switch (g_prof.curr_profile)
        {
            case MMI_PROFILE_GENERAL:
            case MMI_PROFILE_MEETING:
            case MMI_PROFILE_OUTDOOR:
            {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PROF_CUSTOMIZE, MMI_FALSE);
            #ifndef  __MMI_MAINLCD_96X64__
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PROF_RESET, MMI_FALSE);
            #endif    // __MMI_MAINLCD_96X64__
            #ifndef __MMI_PROF_BASIC_UI_STYLE__
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PROF_RENAME, MMI_TRUE);
            #endif    
            #ifdef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PROF_DELETE, MMI_TRUE);
            #endif
                break;
            }

            case MMI_PROFILE_SILENT:
            {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PROF_CUSTOMIZE, MMI_TRUE);
            #ifndef  __MMI_MAINLCD_96X64__
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PROF_RESET, MMI_TRUE);
            #endif    // __MMI_MAINLCD_96X64__
            #ifndef __MMI_PROF_BASIC_UI_STYLE__
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PROF_RENAME, MMI_TRUE);
            #endif
            #ifdef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PROF_DELETE, MMI_TRUE);
            #endif
                break;
            }
        
        #if !defined(__MMI_PROF_BASIC_UI_STYLE__) && !defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
            case MMI_PROFILE_MY_STYLE:
            {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PROF_CUSTOMIZE, MMI_FALSE);
            #ifndef  __MMI_MAINLCD_96X64__
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PROF_RESET, MMI_FALSE);
            #endif    // __MMI_MAINLCD_96X64__
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PROF_RENAME, MMI_FALSE);
                break;
            }
        #endif

        #ifdef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
            case MMI_PROFILE_ADD_NEW_PROF:
            {
	        cui_menu_set_item_hidden(menu_gid, MENU_ID_PROF_ACTIVATE, MMI_TRUE);
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PROF_CUSTOMIZE, MMI_TRUE);
             #ifndef  __MMI_MAINLCD_96X64__
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PROF_RESET, MMI_TRUE);
             #endif    // __MMI_MAINLCD_96X64__
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PROF_RENAME, MMI_TRUE);
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PROF_DELETE, MMI_TRUE);
                break;
            }
        #endif

            default:
            {
            #ifdef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PROF_ACTIVATE, MMI_FALSE);
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PROF_CUSTOMIZE, MMI_FALSE);
            #ifndef  __MMI_MAINLCD_96X64__
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PROF_RESET, MMI_FALSE);
            #endif    // __MMI_MAINLCD_96X64__
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PROF_RENAME, MMI_FALSE);
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PROF_DELETE, MMI_FALSE);
            #endif
                break;
            }
        }
        cui_menu_run(menu_gid);
    }    
}


#ifndef  __MMI_MAINLCD_96X64__
/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_entry_reset_confirm
 * DESCRIPTION
 *  Activates the Highlighted profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_entry_reset_confirm_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type str_reset[10];
    mmi_confirm_property_struct arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf((WCHAR*)str_reset,"%w%w", GetString(STR_GLOBAL_RESET), GetString(STR_ID_PROF_QUESTION_MARK));

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = mmi_prof_group_proc;
    arg.parent_id = GRP_ID_PROFILES;
    
    mmi_confirm_display((WCHAR *)str_reset, MMI_EVENT_QUERY, &arg);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_entry_reset_scrn
 * DESCRIPTION
 *  Activates the Highlighted profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_entry_reset_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
     S16 error;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if !defined(__MMI_PROF_BASIC_UI_STYLE__) && !defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
    if(g_prof.curr_profile == MMI_PROFILE_MY_STYLE)
    {
        mmi_prof_reset_my_style_name();    
    }
#endif    
#ifdef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
    if (g_prof.curr_profile >= MMI_PROFILE_NEW_1 && g_prof.curr_profile <= MMI_PROFILE_NEW_10)
    {
        mmi_ucs2ncpy((CHAR*)g_prof.new_name[g_prof.curr_profile - MMI_PROFILE_NEW_1], 
                                 (CHAR*)GetString(STR_ID_PROF_NEW_PROF), MMI_PROF_PROFILE_NAME_LENGTH);

        WriteRecord(NVRAM_EF_MMI_PROF_NEW_NAME_LID,
                                    1,
                                    (void*)g_prof.new_name,
                                    NVRAM_MMI_PROF_NEW_RECORD_SIZE,
                                    &error);
    }
#endif
    srv_prof_reset_to_default((srv_prof_internal_profile_enum)g_prof.curr_profile);
    if(g_prof.curr_profile == g_prof.activated_profile)
    {
        mmi_prof_show_alert_status_icon();
    }
#ifndef __MMI_PROF_BASIC_UI_STYLE__
    mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, GRP_ID_PROFILES, NULL);
#endif
}
#endif    // __MMI_MAINLCD_96X64__

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_entry_reset_scrn
 * DESCRIPTION
 *  Activates the Highlighted profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_activate_current_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_TRC_ACTIVATE_PROFILE, g_prof.curr_profile);

    if (mmi_prof_activate_profile_int((mmi_prof_id_enum)g_prof.curr_profile, MMI_TRUE))
    {
        g_prof.activated_profile = g_prof.curr_profile;
        mmi_prof_show_alert_status_icon();
    }
}


#if !defined(__MMI_PROF_BASIC_UI_STYLE__) && !defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_prof_reset_my_style_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_reset_my_style_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_prof.my_style_name[0] = L'\0';
    g_prof.is_default_name = MMI_TRUE;
    WriteRecord(NVRAM_EF_MMI_PROF_SETTING_LID,
                1,
                (void*)g_prof.my_style_name,
                (MMI_PROF_PROFILE_NAME_LENGTH + 1) * ENCODING_LENGTH,
                &error);
    mmi_ucs2ncpy((CHAR*)g_prof.my_style_name, (CHAR*)GetString(STR_ID_PROF_MY_STYLE), MMI_PROF_PROFILE_NAME_LENGTH);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_entry_customize_option_scrn
 * DESCRIPTION
 *  Activates the Highlighted profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_entry_customize_option_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_id menu_gid;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_PROF_BASIC_UI_STYLE__
#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_clear_volume_sync_callback(PROFILES_BASE);
#endif
    mdi_audio_resume_background_play();
#endif

    menu_gid = cui_menu_create(
                    GRP_ID_PROFILES, 
                    CUI_MENU_SRC_TYPE_RESOURCE, 
                    CUI_MENU_TYPE_OPTION, 
                    MENU_ID_PROF_CUSTOMIZE_OPTIONS, 
                    MMI_TRUE, 
                    NULL);
    if (menu_gid != GRP_ID_INVALID)
    {
        cui_menu_set_default_title_image_by_id(menu_gid, GetRootTitleIcon(MAIN_MENU_PROFILES_MENUID));

        cui_menu_run(menu_gid);
    }    

}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_entry_customize_option_scrn
 * DESCRIPTION
 *  Activates the Highlighted profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_customize_scrn_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id  root_menu_id = 0;
    mmi_menu_id  menu_id = 0;
    U16  str_id = 0;
    /*need to highlight tone id or ring tone id*/
    U16  tone_id = 0;
    /* flag =0 means need to create menu; 
          * flag =1 means need to create tone list 
          * flag =2 means need to create ring list
          */
    U32 flag = 0;
    U32 tone_flag = 0;/*0 means msg tone and 1 means power on/off tone and cover open/close tone*/

	#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
	    S32 sim_num;
	#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_prof_mem_p->item_id >= CUI_INLINE_ITEM_ID_BASE);
    
	#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
	    sim_num = srv_sim_ctrl_get_num_of_inserted();
	#endif
    
    switch(g_prof_mem_p->item_id - CUI_INLINE_ITEM_ID_BASE)
    {
    #ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__
        case ALERT_TYPE_ITEM:
        {
            root_menu_id = MENU_ID_PROF_ALERT_TYPE;
            menu_id = (mmi_menu_id)(g_prof_mem_p->cur_setting.alert_type + MENU_ID_PROF_RING_ONLY);
            flag = 0;
            break;
        }    
        case RING_TYPE_ITEM:
        {
            root_menu_id = MENU_ID_PROF_RING_TYPE;
            menu_id = (mmi_menu_id)(g_prof_mem_p->cur_setting.ring_type + MENU_ID_PROF_RINGING);
            flag = 0;
            break;
        }    
        case SIM1_RING_TONE_ITEM:
        {
            #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1) 
                str_id = STR_ID_PROF_SIM1_RING_TONE;
            #else
                str_id = STR_ID_PROF_RING_TONE;
            #endif
            tone_id = g_prof_mem_p->cur_setting.ring_tone[0];
            flag = 2;
            break;
        }    
     #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
        case SIM2_RING_TONE_ITEM:
        {
            str_id = STR_ID_PROF_SIM2_RING_TONE;
            tone_id = g_prof_mem_p->cur_setting.ring_tone[1];
            flag = 2;
            break;
        }
     #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
        case SIM3_RING_TONE_ITEM:
        {
            str_id = STR_ID_PROF_SIM3_RING_TONE;
            tone_id = g_prof_mem_p->cur_setting.ring_tone[2];
            flag = 2;
            break;
        }
     #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
        case SIM4_RING_TONE_ITEM:
        {
            str_id = STR_ID_PROF_SIM4_RING_TONE;
            tone_id = g_prof_mem_p->cur_setting.ring_tone[3];
            flag = 2;
            break;
        }
    #endif
    #endif
    #endif

    #ifdef __MMI_VIDEO_TELEPHONY__    
        case VIDEO_CALL_TONE_ITEM:
        {
            str_id = STR_GLOBAL_DIAL_VIDEO_CALL;
            tone_id = g_prof_mem_p->cur_setting.video_tone;
            flag = 2;
            break;
        }    
    #endif

        case RING_VOL_ITEM:
    #endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */
    #ifdef __MMI_PROF_MSG_ALERTS_SUPPORT__
    #if !(defined(__MMI_MAINLCD_96X64__) || defined(__MMI_PROF_SLIM_PROFILES__))
        case MSG_VOL_ITEM:
    #endif    // __MMI_MAINLCD_96X64__
    #endif /* __MMI_PROF_MSG_ALERTS_SUPPORT__ */
        case KEYPAD_VOL_ITEM:
        {
        #ifndef __MMI_PROF_BASIC_UI_STYLE__
            mmi_prof_entry_customize_option_scrn();
        #else
            mmi_prof_set_volume_level();
        #endif
            flag = 3;
            break;
        }

#ifdef __MMI_PROF_MSG_ALERTS_SUPPORT__
    #ifndef __MMI_PROF_SPLIT_MSG_TONES__    
        case SIM1_MSG_TONE_ITEM:
        {
            #if SRV_PROF_SMS_TONE_AMOUNT > 1  
                str_id = STR_ID_PROF_SIM1_MSG_TONE;
            #else
                str_id = STR_GLOBAL_MESSAGE;
            #endif
            #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                if(sim_num <= 1)
                {
                    str_id = STR_GLOBAL_MESSAGE;
                }
            #endif
            tone_id = g_prof_mem_p->cur_setting.msg_tone[0];
            flag = 1;
            break;
        }    
	 #if (SRV_PROF_SMS_TONE_AMOUNT > 1)
        case SIM2_MSG_TONE_ITEM:
        {
            str_id = STR_ID_PROF_SIM2_MSG_TONE;
            tone_id = g_prof_mem_p->cur_setting.msg_tone[1];
            #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                if(sim_num <= 1)
                {
                    str_id = STR_GLOBAL_MESSAGE;
                }
            #endif
            flag = 1;
            break;
        }
     #if (SRV_PROF_SMS_TONE_AMOUNT > 2)
        case SIM3_MSG_TONE_ITEM:
        {
            str_id = STR_ID_PROF_SIM3_MSG_TONE;
            tone_id = g_prof_mem_p->cur_setting.msg_tone[2];
            #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                if(sim_num <= 1)
                {
                    str_id = STR_GLOBAL_MESSAGE;
                }
            #endif
            flag = 1;
            break;
        }
     #if (SRV_PROF_SMS_TONE_AMOUNT > 3)
        case SIM4_MSG_TONE_ITEM:
        {
            str_id = STR_ID_PROF_SIM4_MSG_TONE;
            tone_id = g_prof_mem_p->cur_setting.msg_tone[3];
            #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                if(sim_num <= 1)
                {
                    str_id = STR_GLOBAL_MESSAGE;
                }
            #endif
            flag = 1;
            break;
        }
    #endif
    #endif
    #endif
    #else /*__MMI_PROF_SPLIT_MSG_TONES__*/
        case SMS_TONE_ITEM:
        {
            str_id = STR_GLOBAL_TEXT_MESSAGE;
            tone_id = g_prof_mem_p->cur_setting.sms_tone;
            flag = 1;
            break;
        }    
        #ifdef MMS_SUPPORT    
        case MMS_TONE_ITEM:
        {
            str_id = STR_GLOBAL_MMS;
            tone_id = g_prof_mem_p->cur_setting.mms_tone;
            flag = 1;
            break;
        }    
        #endif
        #ifdef __MMI_EMAIL__
        case EMAIL_TONE_ITEM:
        {
            str_id = STR_GLOBAL_EMAIL;
            tone_id = g_prof_mem_p->cur_setting.email_tone;
            flag = 1;
            break;
        }    
        #endif
        #ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
    #endif /*__MMI_PROF_SPLIT_MSG_TONES__*/

    /*
    #if SRV_PROF_SMS_TONE_AMOUNT == 2       
        case SIM2_MSG_TONE_ITEM:
        {
            str_id = STR_ID_PROF_SIM2_MSG_TONE;
            tone_id = g_prof_mem_p->cur_setting.sim2_msg_tone;
            flag = 1;
            break;
        }    
    #endif 
    */
#endif /*__MMI_PROF_MSG_ALERTS_SUPPORT__*/

        case KEYPAD_TONE_ITEM:
        {
            root_menu_id = MENU_ID_PROF_KEYPAD_TONE; 
            menu_id = (mmi_menu_id)(g_prof_mem_p->cur_setting.keypad_tone + MENU_ID_PROF_SILENT_TONE);
            flag = 0;
            break;
        }
#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__      
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #ifdef __MMI_TOUCH_FEEDBACK_VIBRATE_LEVEL_SUPPORT__
/* under construction !*/
                #else
/* under construction !*/
                #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if !defined(__MMI_POWER_ON_OFF_MUTE__) && !defined(__MMI_POWER_ON_OFF_NO_CUSTOMIZE__)
        case POWER_ON_TONE_ITEM:
        {
            str_id = STR_ID_PROF_POWER_ON_TONE;
            tone_id = g_prof_mem_p->cur_setting.power_on_tone;
            flag = 1;
            tone_flag = 1;
            break;
        }    
        case POWER_OFF_TONE_ITEM:
        {
            str_id = STR_ID_PROF_POWER_OFF_TONE;
            tone_id = g_prof_mem_p->cur_setting.power_off_tone;
            flag = 1;
            tone_flag = 1;
            break;
        }    
#endif
#ifdef __MMI_CLAMSHELL__
        case COVER_OPEN_TONE_ITEM:
        {
            str_id = STR_ID_PROF_COVER_OPEN_TONE;
            tone_id = g_prof_mem_p->cur_setting.cover_open_tone;
            flag = 1;
            tone_flag = 1;
            break;
        }
        case COVER_CLOSE_TONE_ITEM:
        {
            str_id = STR_ID_PROF_COVER_CLOSE_TONE;
            tone_id = g_prof_mem_p->cur_setting.cover_close_tone;
            flag = 1;
            tone_flag = 1;
            break;
        }
#endif

#if !(defined(__MMI_MAINLCD_96X64__) || defined(__MMI_PROF_SLIM_PROFILES__))
        case SYSTEM_ALERT_ITEM:
        {
            root_menu_id = MENU_ID_PROF_SYSTEM_ALERT; 
            menu_id = (mmi_menu_id)(g_prof_mem_p->cur_setting.system_alert + MENU_ID_PROF_SYSTEM_ALERT_ON);
            flag = 0;   
            break;
        }
#endif    // __MMI_MAINLCD_96X64__

#ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__
    #if defined(__MMI_INTELLIGENT_CALL_ALERT__)    
        case INTELLIGENT_CALL_ALERT_ITEM:
        {
            root_menu_id = MENU_ID_PROF_INTELLIGENT_CALL_ALERT; 
            menu_id = (mmi_menu_id)(g_prof_mem_p->cur_setting.intelligent_call_alert + MENU_ID_PROF_INTELLIGENT_CALL_ALERT_ON);
            flag = 0;
            break;
        }    
    #endif
#endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */

#if !defined(HW_LED_NOT_SUPPORT)    
        case STATUS_LED_ITEM:
        {
            root_menu_id = MENU_ID_PROF_STATUE_LED; 
            menu_id = (mmi_menu_id)(g_prof_mem_p->cur_setting.status_led + MENU_ID_PROF_ITEM_NONE);
            flag = 0;    
            break;
        }    
    #endif
        default:
            break;

    }

    if (flag == 0)
    {
        mmi_id menu_gid;
            menu_gid = cui_menu_create(
                            GRP_ID_PROFILES, 
                            CUI_MENU_SRC_TYPE_RESOURCE, 
                            CUI_MENU_TYPE_APPSUB, 
                            root_menu_id, 
                            MMI_TRUE, 
                            NULL);
            if (menu_gid != GRP_ID_INVALID)
            {
                cui_menu_set_currlist_highlighted_id(menu_gid, menu_id);
                cui_menu_set_default_title_image_by_id(menu_gid, GetRootTitleIcon(MAIN_MENU_PROFILES_MENUID));
                cui_menu_run(menu_gid);
            }    
        }    
    else if (flag == 1)
    {
        U16 filter = 0;
        if (tone_flag == 1)
        {
            CUI_TONE_SELECTOR_FILTER_SET(filter, CUI_TONE_SELECTOR_FILTER_SILENT);
        }
        CUI_TONE_SELECTOR_FILTER_SET(filter, CUI_TONE_SELECTOR_FILTER_TONE);
        mmi_prof_run_tone_selector(GRP_ID_PROFILES, filter, str_id, tone_id);
    }
    else if (flag == 2)
    {
    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        if(sim_num <= 1)
        {
            str_id = STR_ID_PROF_RING_TONE;
        }
    #endif
        mmi_prof_get_ring_tong_list(str_id, tone_id);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_menu_item_highlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_menu_item_highlight(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;

#if !defined(__MMI_PROF_BASIC_UI_STYLE__) && !defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
    mmi_menu_id end_id = MENU_ID_PROF_MY_STYLE;
#elif defined(__MMI_PROF_BASIC_UI_STYLE__)
#ifndef  __MMI_MAINLCD_96X64__  
    mmi_menu_id end_id = MENU_ID_PROF_OUTDOOR;
#else    // __MMI_MAINLCD_96X64__
    mmi_menu_id end_id = MENU_ID_PROF_GENERAL;
#endif    // __MMI_MAINLCD_96X64__
#else
    mmi_menu_id end_id = MENU_ID_PROF_NEW_10;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
    if (menu_evt->highlighted_menu_id >= MENU_ID_PROF_GENERAL && menu_evt->highlighted_menu_id <= end_id)
    {
        g_prof.curr_profile = menu_evt->highlighted_menu_id - MENU_ID_PROF_GENERAL + MMI_PROF_PROF_ID_BEGIN;
    }
#else
    if (menu_evt->highlighted_menu_id >= MENU_ID_PROF_ADD_PROF && menu_evt->highlighted_menu_id <= end_id)
    {
        g_prof.curr_profile = menu_evt->highlighted_menu_id - MENU_ID_PROF_ADD_PROF + MMI_PROF_PROF_ID_BEGIN - 1;
        if (menu_evt->highlighted_menu_id == MENU_ID_PROF_ADD_PROF)
        {
            cui_menu_change_left_softkey_string(menu_evt->sender_id, (WCHAR*)GetString(STR_GLOBAL_SELECT));
        }
    }
#endif
    
    #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
    #ifdef __MMI_TOUCH_FEEDBACK_VIBRATE_LEVEL_SUPPORT__ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    #endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_menu_item_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_menu_item_select(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
    MMI_BOOL close_menu_cui = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PROF_TRC_MENU_ITEM_SELECTED, menu_evt->highlighted_menu_id);
    switch(menu_evt->highlighted_menu_id)
    {
        /*profile item selection*/
        case MENU_ID_PROF_GENERAL:
    #ifndef  __MMI_MAINLCD_96X64__
        case MENU_ID_PROF_SILENT:
        case MENU_ID_PROF_MEETING:
        case MENU_ID_PROF_OUTDOOR:
    #endif    //    __MMI_MAINLCD_96X64__
    
    #if !defined(__MMI_PROF_BASIC_UI_STYLE__) && !defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
        case MENU_ID_PROF_MY_STYLE:
    #endif
    #ifdef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
        case MENU_ID_PROF_NEW_1:
        case MENU_ID_PROF_NEW_2:
        case MENU_ID_PROF_NEW_3:
        case MENU_ID_PROF_NEW_4:
        case MENU_ID_PROF_NEW_5:
        case MENU_ID_PROF_NEW_6:
        case MENU_ID_PROF_NEW_7:
        case MENU_ID_PROF_NEW_8:                   
        case MENU_ID_PROF_NEW_9:
        case MENU_ID_PROF_NEW_10:
    #endif        
        {
            if (evt->evt_id == EVT_ID_CUI_MENU_ITEM_TAP)
            {
                mmi_prof_activate_current_profile();
            }
            else if (evt->evt_id == EVT_ID_CUI_MENU_ITEM_CSK_SELECT)
            {
                mmi_prof_activate_current_profile();
            }
            else
            {
                mmi_prof_entry_options_scrn();
            }            
            close_menu_cui = MMI_FALSE;
            break;
        }
    #ifdef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
        case MENU_ID_PROF_ADD_PROF:
        {
            g_prof.add_flag = MMI_TRUE;
            mmi_prof_run_fseditor_cui();
            close_menu_cui = MMI_FALSE;
            break;
        }
    #endif      
        case MENU_ID_PROF_ACTIVATE:
        {
            cui_menu_close(menu_evt->sender_id);
            mmi_prof_activate_current_profile();
            close_menu_cui = MMI_FALSE;
            break;
        }

        case MENU_ID_PROF_CUSTOMIZE:
        {
            mmi_prof_entry_customize_scrn();
            close_menu_cui = MMI_FALSE;
            break;
        }
    #ifndef  __MMI_MAINLCD_96X64__
        case MENU_ID_PROF_RESET:
        {
            mmi_prof_entry_reset_confirm_scrn();
            close_menu_cui = MMI_FALSE;
            break;
        }
    #endif    // __MMI_MAINLCD_96X64__
        case MENU_ID_PROF_CHANGE:
        {
            cui_menu_close(menu_evt->sender_id);
            mmi_prof_customize_scrn_csk_hdlr();
            close_menu_cui = MMI_FALSE;
            break;
        }
        case MENU_ID_PROF_SAVE:            
        {
            mmi_prof_save_cur_settings();
            mmi_popup_display_simple_ext(STR_GLOBAL_SAVED, MMI_EVENT_SUCCESS, GRP_ID_PROFILES, NULL);
            cui_inline_close(g_prof_mem_p->inline_gid);
            close_menu_cui = MMI_FALSE;
            break;
        }
        #ifdef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
        case MENU_ID_PROF_DELETE:
        {
            mmi_prof_entry_delete_confirm_scrn();
            break;
        }
        #endif
        /*Alert type selection*/
        case MENU_ID_PROF_RING_ONLY:
        {
            g_prof_mem_p->cur_setting.alert_type = MMI_PROF_ALERT_TYPE_RING;
            break;
        }
        case MENU_ID_PROF_VIB_ONLY:
        {
            g_prof_mem_p->cur_setting.alert_type = MMI_PROF_ALERT_TYPE_VIB_ONLY;
            break;
        }
        case MENU_ID_PROF_VIB_AND_RING:
        {
            g_prof_mem_p->cur_setting.alert_type = MMI_PROF_ALERT_TYPE_VIB_AND_RING;
            break;
        }
        case MENU_ID_PROF_VIB_THEN_RING:
        {
            g_prof_mem_p->cur_setting.alert_type = MMI_PROF_ALERT_TYPE_VIB_THEN_RING;
            break;
        }

        /*Ring type selection*/
        case MENU_ID_PROF_RINGING:
        {
            g_prof_mem_p->cur_setting.ring_type = MMI_PROF_RING_TYPE_REPEAT;
            break;
        }
    #ifdef __MMI_AUDIO_CRESCENDO_SUPPORT__    
        case MENU_ID_PROF_ASCENDING:
        {
            g_prof_mem_p->cur_setting.ring_type = MMI_PROF_RING_TYPE_ASCENDING;
            break;
        }
    #endif    
        case MENU_ID_PROF_BEEP_ONCE:
        {
            g_prof_mem_p->cur_setting.ring_type = MMI_PROF_RING_TYPE_BEEP_ONCE;
            break;
        }
        
        /*keypad tone selection*/
		case MENU_ID_PROF_SILENT_TONE:
        {
            g_prof_mem_p->cur_setting.keypad_tone = MMI_PROF_KEYPAD_SILENT;
            break;
        }
        case MENU_ID_PROF_CLICK:
        {
            g_prof_mem_p->cur_setting.keypad_tone = MMI_PROF_KEYPAD_CLICK;
            break;
        }
        case MENU_ID_PROF_TONE:
        {
            g_prof_mem_p->cur_setting.keypad_tone = MMI_PROF_KEYPAD_TONE;
            break;
        }
    #if defined( __MMI_HUMAN_VOICE_KEYPAD_TONE__ )
        case MENU_ID_PROF_KEYPAD_HUMAN_VOICE_1:
        {
            g_prof_mem_p->cur_setting.keypad_tone = MMI_PROF_KEYPAD_NUM_1;
            break;
        }
    #endif
    
    #if defined( __MMI_CUST_KEYPAD_TONE__ )
        case MENU_ID_PROF_KEYPAD_TONE_CUST_1:
        {
            g_prof_mem_p->cur_setting.keypad_tone = MMI_PROF_KEYPAD_CUST_1;
            break;
        }
    #endif
        
    #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
    #ifdef __MMI_TOUCH_FEEDBACK_VIBRATE_LEVEL_SUPPORT__ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    #endif
    #if !(defined(__MMI_MAINLCD_96X64__) || defined(__MMI_PROF_SLIM_PROFILES__))
        /*system alert selection*/
        case MENU_ID_PROF_SYSTEM_ALERT_ON:
        {
            g_prof_mem_p->cur_setting.system_alert = MMI_PROF_ON;
            break;
        }
        case MENU_ID_PROF_SYSTEM_ALERT_OFF:
        {
            g_prof_mem_p->cur_setting.system_alert = MMI_PROF_OFF;
            break;
        }
    #endif    // __MMI_MAINLCD_96X64__
        /*intelligent call alert selection*/
    #if defined(__MMI_INTELLIGENT_CALL_ALERT__)    
        case MENU_ID_PROF_INTELLIGENT_CALL_ALERT_ON:
        {
            g_prof_mem_p->cur_setting.intelligent_call_alert = MMI_PROF_ON;
            break;
        }
        case MENU_ID_PROF_INTELLIGENT_CALL_ALERT_OFF:
        {
            g_prof_mem_p->cur_setting.intelligent_call_alert = MMI_PROF_OFF;
            break;
        }
    #endif

    #if !defined(HW_LED_NOT_SUPPORT)    
        case MENU_ID_PROF_ITEM_NONE:
        case MENU_ID_PROF_COLOR_PATTERN_1:
        case MENU_ID_PROF_COLOR_PATTERN_2:
        case MENU_ID_PROF_COLOR_PATTERN_3:
        case MENU_ID_PROF_COLOR_PATTERN_4:
        case MENU_ID_PROF_COLOR_PATTERN_5:
        case MENU_ID_PROF_COLOR_PATTERN_6:
        {
            g_prof_mem_p->cur_setting.status_led = menu_evt->highlighted_menu_id - MENU_ID_PROF_ITEM_NONE + SRV_PROF_LED_NONE;
            break;
        }
    #endif
    #ifndef __MMI_PROF_BASIC_UI_STYLE__
        case MENU_ID_PROF_RENAME:
        {
            mmi_prof_run_fseditor_cui();
            close_menu_cui = MMI_FALSE;
            break;
        }
    #endif
        default:
        {
            close_menu_cui = MMI_FALSE;
            break;
    }
    }
    
    if (close_menu_cui)
    {
        cui_menu_close(menu_evt->sender_id);
    }
}

#ifndef __MMI_PROF_BASIC_UI_STYLE__
/*****************************************************************************
 * FUNCTION
 *  mmi_prof_select_item_focus_changed_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_select_item_focus_changed_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 item_index;
    cui_event_inline_notify_struct *inline_evt = (cui_event_inline_notify_struct *)evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_prof_mem_p->item_id >= CUI_INLINE_ITEM_ID_BASE);
    item_index = g_prof_mem_p->item_id - CUI_INLINE_ITEM_ID_BASE;
    switch(item_index)
    {
        case ALERT_TYPE_ITEM:
        {
            g_prof_mem_p->cur_setting.alert_type = inline_evt->param;
            break;
        }
        case RING_TYPE_ITEM:
        {
            g_prof_mem_p->cur_setting.ring_type = inline_evt->param;
            break;
        }
        case KEYPAD_TONE_ITEM:
        {
            g_prof_mem_p->cur_setting.keypad_tone = inline_evt->param;
            break;
        }

    #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_TOUCH_FEEDBACK_VIBRATE_LEVEL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
         #endif
/* under construction !*/
/* under construction !*/
    #endif

        case SYSTEM_ALERT_ITEM:
        {
            g_prof_mem_p->cur_setting.system_alert = inline_evt->param;
            break;
        }
    #if defined(__MMI_INTELLIGENT_CALL_ALERT__)    
        case INTELLIGENT_CALL_ALERT_ITEM:
        {
            g_prof_mem_p->cur_setting.intelligent_call_alert = inline_evt->param;
            break;
        }
    #endif
    #if !defined(HW_LED_NOT_SUPPORT)    
        case STATUS_LED_ITEM:
        {
            g_prof_mem_p->cur_setting.status_led = inline_evt->param;
            break;
        }
    #endif
        default:
            break;
    }

}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_menu_item_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_update_tone_setting(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_tone_selector_evt_struct * evt_cui = (cui_tone_selector_evt_struct *)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* When no external file support then cannot set it in profiles */
#ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__
#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
    if (evt_cui->is_default_sound == MMI_FALSE)
    {
        WCHAR*  path_buffer = NULL;
        WCHAR*  filename_p = NULL;
        switch(g_prof_mem_p->item_id - CUI_INLINE_ITEM_ID_BASE)
        {
            case SIM1_RING_TONE_ITEM:
            {
                g_prof_mem_p->cur_setting.ring_tone[0] = MMI_PROF_EXT_AUDIO_ID_BEGIN;
                path_buffer = g_prof_mem_p->ring_tone_path[0];
                filename_p = g_prof_mem_p->ring_filename[0];
                break;
            }
        #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
            case SIM2_RING_TONE_ITEM:
            {
                g_prof_mem_p->cur_setting.ring_tone[1] = MMI_PROF_EXT_AUDIO_ID_BEGIN;
                path_buffer = g_prof_mem_p->ring_tone_path[1];
                filename_p = g_prof_mem_p->ring_filename[1];
                break;
            }
        #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
            case SIM3_RING_TONE_ITEM:
            {
                g_prof_mem_p->cur_setting.ring_tone[2] = MMI_PROF_EXT_AUDIO_ID_BEGIN;
                path_buffer = g_prof_mem_p->ring_tone_path[2];
                filename_p = g_prof_mem_p->ring_filename[2];
                break;
            }
        #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
            case SIM4_RING_TONE_ITEM:
            {
                g_prof_mem_p->cur_setting.ring_tone[3] = MMI_PROF_EXT_AUDIO_ID_BEGIN;
                path_buffer = g_prof_mem_p->ring_tone_path[3];
                filename_p = g_prof_mem_p->ring_filename[3];
                break;
            }
        #endif
        #endif
        #endif

        #ifdef __MMI_VIDEO_TELEPHONY__
            case VIDEO_CALL_TONE_ITEM:
            {
                g_prof_mem_p->cur_setting.video_tone = MMI_PROF_EXT_AUDIO_ID_BEGIN;
                path_buffer = g_prof_mem_p->video_call_tone_path;
                filename_p = g_prof_mem_p->video_call_filename;
                break;
            }
        #endif
        }
        if (path_buffer != NULL)
        {
            if (0 == cui_tone_selector_get_selected_filepath(
                            evt_cui->sender_id, 
                            NULL, 
                            (WCHAR*)path_buffer, 
                            SRV_FMGR_PATH_BUFFER_SIZE))
            {
                mmi_prof_get_display_name_from_filepath(path_buffer, filename_p);
            }
        }
        return;
    }
#endif /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */
#endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */    
    switch(g_prof_mem_p->item_id - CUI_INLINE_ITEM_ID_BASE)
    {
    #ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__
        case SIM1_RING_TONE_ITEM:
        {
            g_prof_mem_p->cur_setting.ring_tone[0] = evt_cui->selected_tone;
            break;     
        }    
        #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
            case SIM2_RING_TONE_ITEM:
        {
            g_prof_mem_p->cur_setting.ring_tone[1] = evt_cui->selected_tone;
            break;     
        }    
        #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
            case SIM3_RING_TONE_ITEM:
        {
            g_prof_mem_p->cur_setting.ring_tone[2] = evt_cui->selected_tone;
            break;     
        }    
        #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
            case SIM4_RING_TONE_ITEM:
        {
            g_prof_mem_p->cur_setting.ring_tone[3] = evt_cui->selected_tone;
            break;     
        }    
        #endif
        #endif
        #endif
        
    #ifdef __MMI_VIDEO_TELEPHONY__
        case VIDEO_CALL_TONE_ITEM:
        {
            g_prof_mem_p->cur_setting.video_tone = evt_cui->selected_tone;
            break;     
        }    
    #endif
    #endif    /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */

    #if !defined(__MMI_POWER_ON_OFF_MUTE__) && !defined(__MMI_POWER_ON_OFF_NO_CUSTOMIZE__)
        case POWER_ON_TONE_ITEM:
        {
            g_prof_mem_p->cur_setting.power_on_tone = evt_cui->selected_tone;
            break;     
        }    

        case POWER_OFF_TONE_ITEM:
        {
            g_prof_mem_p->cur_setting.power_off_tone = evt_cui->selected_tone;
            break;     
        }    
    #endif /*__MMI_POWER_ON_OFF_MUTE__*/
    
    #ifdef __MMI_CLAMSHELL__
        case COVER_OPEN_TONE_ITEM:
        {
            g_prof_mem_p->cur_setting.cover_open_tone = evt_cui->selected_tone;
            break;     
        }    

        case COVER_CLOSE_TONE_ITEM:
        {
            g_prof_mem_p->cur_setting.cover_close_tone = evt_cui->selected_tone;
            break;     
        }    
    #endif /*__MMI_CLAMSHELL__*/

    #ifdef __MMI_PROF_MSG_ALERTS_SUPPORT__
    #ifndef __MMI_PROF_SPLIT_MSG_TONES__
        case SIM1_MSG_TONE_ITEM:
        {
            g_prof_mem_p->cur_setting.msg_tone[0] = evt_cui->selected_tone;
            break;     
        }    
	#if (SRV_PROF_SMS_TONE_AMOUNT > 1)
            case SIM2_MSG_TONE_ITEM:
        {
            g_prof_mem_p->cur_setting.msg_tone[1] = evt_cui->selected_tone;
            break;     
        }    
    #if (SRV_PROF_SMS_TONE_AMOUNT > 2)
            case SIM3_MSG_TONE_ITEM:
        {
            g_prof_mem_p->cur_setting.msg_tone[2] = evt_cui->selected_tone;
            break;     
        }    
    #if (SRV_PROF_SMS_TONE_AMOUNT > 3)
            case SIM4_MSG_TONE_ITEM:
        {
            g_prof_mem_p->cur_setting.msg_tone[3] = evt_cui->selected_tone;
            break;     
        }    
    #endif
    #endif
    #endif
		
    #else /*__MMI_PROF_SPLIT_MSG_TONES__*/
        #ifdef MMS_SUPPORT
        case MMS_TONE_ITEM:
        {
            g_prof_mem_p->cur_setting.mms_tone = evt_cui->selected_tone;
            break;     
        }    
        #endif
        case SMS_TONE_ITEM:
        {
            g_prof_mem_p->cur_setting.sms_tone = evt_cui->selected_tone;
            break;     
        }    
        #ifdef __MMI_EMAIL__
        case EMAIL_TONE_ITEM:
        {
            g_prof_mem_p->cur_setting.email_tone = evt_cui->selected_tone;
            break;     
        }    
        #endif
        #ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
    #endif /*__MMI_PROF_SPLIT_MSG_TONES__*/
    #endif /* __MMI_PROF_MSG_ALERTS_SUPPORT__ */

/*   
    #if SRV_PROF_SMS_TONE_AMOUNT == 2 
        case SIM2_MSG_TONE_ITEM:
        {
            g_prof_mem_p->cur_setting.sim2_msg_tone = evt_cui->selected_tone;
            break;     
        }    
    #endif  
*/
    
        default:
            break;
    }

}

#ifndef __MMI_PROF_BASIC_UI_STYLE__
/*****************************************************************************
 * FUNCTION
 *  mmi_prof_progress_bar_value_change_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_progress_bar_value_change_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_index;
    U16 vol;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_index = g_prof_mem_p->item_id - CUI_INLINE_ITEM_ID_BASE;
    cui_inline_get_value(g_prof_mem_p->inline_gid, g_prof_mem_p->item_id, &vol);

    if (vol == g_prof_mem_p->volume)
    {
        return;
    }
    g_prof_mem_p->volume = vol;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_TRC_PROGRESSBAR_CHANGE, item_index, g_prof_mem_p->volume);
    switch(item_index)
    {
    #ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__
        case RING_VOL_ITEM:
        {
        #ifdef __GAIN_TABLE_SUPPORT__
            mdi_audio_set_audio_type(MDI_AUDIO_TYPE_RING);
        #endif
            g_prof_mem_p->cur_setting.ring_vol = g_prof_mem_p->volume;
            
            if (g_prof_mem_p->is_playing == MMI_FALSE)
            {
                StartTimer(TIMER_PROFILES_TONE_PLAY, 1000, mmi_prof_preview_play_tone);
            }
            
            break;
        }
    #endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */
    #ifdef __MMI_PROF_MSG_ALERTS_SUPPORT__
        case MSG_VOL_ITEM:
        {
        #ifdef __GAIN_TABLE_SUPPORT__
            mdi_audio_set_audio_type(MDI_AUDIO_TYPE_MESSAGE);
        #endif
            g_prof_mem_p->cur_setting.msg_vol = g_prof_mem_p->volume;
            
            if (g_prof_mem_p->is_playing == MMI_FALSE)
            {
                StartTimer(TIMER_PROFILES_TONE_PLAY, 1000, mmi_prof_preview_play_tone);
            }
            
            break;
        }
    #endif /* __MMI_PROF_MSG_ALERTS_SUPPORT__ */
        case KEYPAD_VOL_ITEM:
        {
            g_prof_mem_p->cur_setting.keypad_vol = g_prof_mem_p->volume;
            mmi_prof_preview_key_tone();
            return;
        }
    #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        default:
        {
            break;
        }

    }

    if (g_prof_mem_p->is_playing == MMI_TRUE)
    {
        mdi_audio_set_volume(VOL_TYPE_MEDIA, MDI_AUD_VOL_MUTE((U8)g_prof_mem_p->volume));
    }
}
#endif

#ifdef __BT_SPK_VOL_CONTROL__
/*****************************************************************************
 * FUNCTION
 *  mmi_prof_handfree_volume_sync_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_prof_handfree_volume_sync_callback(U8 volume, MMI_BOOL is_mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(volume <= MDI_AUD_VOL_NUM);
    g_prof_mem_p->volume = volume;
    
    item_index = g_prof_mem_p->item_id - CUI_INLINE_ITEM_ID_BASE;
    switch(item_index)
    {
    #ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__
        case RING_VOL_ITEM:
        {
        #ifdef __GAIN_TABLE_SUPPORT__
            mdi_audio_set_audio_type(MDI_AUDIO_TYPE_RING);
        #endif
            g_prof_mem_p->cur_setting.ring_vol = g_prof_mem_p->volume;
            break;
        }
    #endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */
    #ifdef __MMI_PROF_MSG_ALERTS_SUPPORT__
    #if !(defined(__MMI_MAINLCD_96X64__) || defined(__MMI_PROF_SLIM_PROFILES__))
        case MSG_VOL_ITEM:
        {
        #ifdef __GAIN_TABLE_SUPPORT__
            mdi_audio_set_audio_type(MDI_AUDIO_TYPE_MESSAGE);
        #endif
            g_prof_mem_p->cur_setting.msg_vol = g_prof_mem_p->volume;
            break;
        }
    #endif    // __MMI_MAINLCD_96X64__
    #endif /* __MMI_PROF_MSG_ALERTS_SUPPORT__ */
        case KEYPAD_VOL_ITEM:
        {
            g_prof_mem_p->cur_setting.keypad_vol = g_prof_mem_p->volume;
            break;
        }
        default:
        {
            return MMI_TRUE;
        }

    }

    if (MMI_TRUE == mmi_frm_group_is_present(g_prof_mem_p->inline_gid))
    {
        cui_inline_set_value(g_prof_mem_p->inline_gid, g_prof_mem_p->item_id, (void*)g_prof_mem_p->volume);
    }
 
    if (g_prof_mem_p->is_playing)
    {
        mdi_audio_set_volume(VOL_TYPE_MEDIA, MDI_AUD_VOL_MUTE(g_prof_mem_p->volume));
    }
    return MMI_TRUE;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_inline_item_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_inline_item_highlight_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
    #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    
    #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
    #ifdef __MMI_TOUCH_FEEDBACK_VIBRATE_LEVEL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    #endif

    item_index = g_prof_mem_p->item_id - CUI_INLINE_ITEM_ID_BASE;
    switch(item_index)
    {
    #ifndef __MMI_PROF_BASIC_UI_STYLE__
    #ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__
        case RING_VOL_ITEM:
    #endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */
    #ifdef __MMI_PROF_MSG_ALERTS_SUPPORT__
        case MSG_VOL_ITEM:
    #endif /* __MMI_PROF_MSG_ALERTS_SUPPORT__ */
    #if defined(__MMI_PROF_CALL_ALERTS_SUPPORT__) || defined(__MMI_PROF_MSG_ALERTS_SUPPORT__)
        {
            cui_inline_get_value(g_prof_mem_p->inline_gid, g_prof_mem_p->item_id, &g_prof_mem_p->volume);
            StartTimer(TIMER_PROFILES_TONE_PLAY, 1000, mmi_prof_preview_play_tone);
        #ifdef __BT_SPK_VOL_CONTROL__
            mdi_audio_bt_register_volume_sync_callback(PROFILES_BASE, MDI_AUD_VOL_LEVEL_NORMAL_MUTE, mmi_prof_handfree_volume_sync_callback);
        #endif
            break;
        }
    #endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ || __MMI_PROF_MSG_ALERTS_SUPPORT__ */
        case KEYPAD_VOL_ITEM:
        {
            cui_inline_get_value(g_prof_mem_p->inline_gid, g_prof_mem_p->item_id, &g_prof_mem_p->volume);
            mdi_audio_suspend_background_play();
            mmi_frm_kbd_set_tone_state(MMI_KEY_VOL_UP_DOWN_RIGHT_LEFT_ARROW_DISABLE);

            #ifdef __BT_SPK_VOL_CONTROL__
                mdi_audio_bt_register_volume_sync_callback(PROFILES_BASE, MDI_AUD_VOL_LEVEL_NORMAL_MUTE, mmi_prof_handfree_volume_sync_callback);
            #endif
            break;
        }
    #else
    #ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__
        case RING_VOL_ITEM:
        {
            g_prof_mem_p->volume = g_prof_mem_p->cur_setting.ring_vol;
            break;
        }
    #endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */
    #ifdef __MMI_PROF_MSG_ALERTS_SUPPORT__
    #if !(defined(__MMI_MAINLCD_96X64__) || defined(__MMI_PROF_SLIM_PROFILES__))
        case MSG_VOL_ITEM:
        {
            g_prof_mem_p->volume = g_prof_mem_p->cur_setting.msg_vol;
            break;
        }
    #endif    // __MMI_MAINLCD_96X64__
    #endif /* __MMI_PROF_MSG_ALERTS_SUPPORT__ */
        case KEYPAD_VOL_ITEM:
        {
            g_prof_mem_p->volume = g_prof_mem_p->cur_setting.keypad_vol;
            break;
        }
    #endif
        #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifdef __BT_SPK_VOL_CONTROL__
/* under construction !*/
            #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif

        #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
        #ifdef __MMI_TOUCH_FEEDBACK_VIBRATE_LEVEL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifdef __BT_SPK_VOL_CONTROL__
/* under construction !*/
            #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        #endif

#ifdef __GAIN_TABLE_SUPPORT__
    #ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__
        case SIM1_RING_TONE_ITEM:
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
        case SIM2_RING_TONE_ITEM:
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
        case SIM3_RING_TONE_ITEM:
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
        case SIM4_RING_TONE_ITEM:
    #endif
    #endif
    #endif
        {
            g_curr_tone_setting_type = MMI_PROF_TYPE_RING;
            break;
        }
    #ifdef __MMI_VIDEO_TELEPHONY__    
        case VIDEO_CALL_TONE_ITEM:
        {
            g_curr_tone_setting_type = MMI_PROF_TYPE_VIDEO_CALL;
            break;
        }
    #endif
    #endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */
    #ifdef __MMI_PROF_MSG_ALERTS_SUPPORT__
    #ifndef __MMI_PROF_SPLIT_MSG_TONES__    
        case SIM1_MSG_TONE_ITEM:
    #else
        case SMS_TONE_ITEM:
        #ifdef MMS_SUPPORT    
        case MMS_TONE_ITEM:
        #endif
        #ifdef __MMI_EMAIL__
        case EMAIL_TONE_ITEM:
        #endif 
    #endif
    #if SRV_PROF_SMS_TONE_AMOUNT == 2
        case SIM2_MSG_TONE_ITEM
    #endif
        {
            g_curr_tone_setting_type = MMI_PROF_TYPE_MESSAGE;
            break;
        }
    #endif /* __MMI_PROF_MSG_ALERTS_SUPPORT__ */
    #if !defined(__MMI_POWER_ON_OFF_MUTE__) && !defined(__MMI_POWER_ON_OFF_NO_CUSTOMIZE__)
        case POWER_ON_TONE_ITEM:
        {
            g_curr_tone_setting_type = MMI_PROF_TYPE_POWER_ON;
            break;
        }
        case POWER_OFF_TONE_ITEM:
        {
            g_curr_tone_setting_type = MMI_PROF_TYPE_POWER_OFF;
            break;
        }
    #endif 
#endif /*#ifdef __GAIN_TABLE_SUPPORT__*/
        default:
        {
        #ifndef __MMI_PROF_BASIC_UI_STYLE__
            mmi_prof_preview_stop_tone();
        #ifdef __BT_SPK_VOL_CONTROL__
            mdi_audio_bt_clear_volume_sync_callback(PROFILES_BASE);
        #endif
        #endif
            break;
        }
    }

#ifdef  __MMI_MAINLCD_96X64__
    cui_inline_set_title_string(g_prof_mem_p->inline_gid, (WCHAR*)GetString(prof_item_caption[(g_prof_mem_p->item_id- CUI_INLINE_ITEM_ID_BASE)/2].string_id));
#endif    // __MMI_MAINLCD_96X64__

}

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_prof_tap_callback_hdlr
 * DESCRIPTION
 *  call back function for tap
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_tap_callback_hdlr(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 flag;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        U16 item_id = cui_inline_get_item_id_by_index(g_prof_mem_p->inline_gid,(U16)index);
        flag = cui_inline_get_item_attributes(g_prof_mem_p->inline_gid,item_id);
        if(flag & CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY)
        {
            mmi_prof_customize_scrn_csk_hdlr();
        }    
    }
    return;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_prof_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_prof_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_tone_selector_evt_struct * evt_cui;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        {
            if (g_prof_mem_p != NULL)
            {
                applib_mem_ap_free(g_prof_mem_p);
                g_prof_mem_p = NULL;
            }
        #ifdef __MMI_AP_DCM_PROFILE__
            if(!mmi_frm_app_is_launched(APP_SETTING_NEW))
            {
                mmi_ap_send_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_SETTINGS);
            }
        #endif
            break;
        }
    #ifndef  __MMI_MAINLCD_96X64__
        /*************************reset confirm event***************************/
        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct* alert_evt = (mmi_alert_result_evt_struct*)evt;
            if (alert_evt->result == MMI_ALERT_CNFM_YES)
                {
                    mmi_prof_entry_reset_scrn();
                }
            break;
        }
    #endif    // __MMI_MAINLCD_96X64__

        /*************************Menu CUI event***************************/
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
            /* For basic UI also CSK will activate profiles */
        //#ifndef __MMI_PROF_BASIC_UI_STYLE__
            cui_menu_override_center_softkey(
                    menu_evt->sender_id, 
                    (WCHAR *)NULL, 
                    (UI_image_type) GetImage(IMG_GLOBAL_COMMON_CSK));
        //#endif
            switch(menu_evt->parent_menu_id)
            {
                case MAIN_MENU_PROFILES_MENUID:
                {
                    cui_menu_enable_tap_to_highlight(menu_evt->sender_id);
                
                #if !defined(__MMI_PROF_BASIC_UI_STYLE__) && !defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
                    cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_PROF_MY_STYLE, g_prof.my_style_name);
                #elif defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
                    cui_menu_set_currlist_title(menu_evt->sender_id, (WCHAR*)GetString(STR_ID_PROF_CAPTION), NULL);
                    mmi_prof_create_main_menu(menu_evt->sender_id);
                #endif
                    cui_menu_set_currlist_left_softkey(menu_evt->sender_id, (UI_string_type)GetString(STR_GLOBAL_OPTIONS));
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_ICON_TEXT_ICON);
                    cui_menu_set_item_second_image(menu_evt->sender_id, 
                                                   MENU_ID_PROF_GENERAL + g_prof.activated_profile - MMI_PROF_PROF_ID_BEGIN, 
                                                   IMG_ID_PROF_ACTIVATED);
                    break;
                }
                
                case MENU_ID_PROF_ALERT_TYPE:
            #ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__
                case MENU_ID_PROF_RING_TYPE:
            #endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */
                case MENU_ID_PROF_KEYPAD_TONE:
            #if !(defined(__MMI_MAINLCD_96X64__) || defined(__MMI_PROF_SLIM_PROFILES__))
                case MENU_ID_PROF_SYSTEM_ALERT:
            #endif    // __MMI_MAINLCD_96X64__
            #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
            #endif
            #ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__
            #if defined(__MMI_INTELLIGENT_CALL_ALERT__)
                case MENU_ID_PROF_INTELLIGENT_CALL_ALERT:
            #endif
            #endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */
            #if !defined(HW_LED_NOT_SUPPORT)
                case MENU_ID_PROF_STATUE_LED:
            #endif
                {
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                    break;
                }
                default:
                    break;
            }     
            break;
        }
        
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        {
            mmi_prof_menu_item_select(evt);
            break;
        }    

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
            mmi_prof_menu_item_highlight(evt);
            break;
        }

        /**********************Inline CUI event*************************/
        case EVT_ID_CUI_INLINE_NOTIFY:
        {
            cui_event_inline_notify_struct *inline_evt = (cui_event_inline_notify_struct *)evt;
            if (inline_evt->event_type == CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM)
            {
            #ifndef __MMI_PROF_BASIC_UI_STYLE__
                if (g_prof_mem_p->item_id != inline_evt->item_id)
                {
                    mmi_prof_preview_stop_tone();
                }
            #endif
                g_prof_mem_p->item_id = inline_evt->item_id;
                mmi_prof_inline_item_highlight_hdlr(evt);
            }
            #ifndef __MMI_PROF_BASIC_UI_STYLE__
            else if (inline_evt->event_type == CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED)
            {
                mmi_prof_select_item_focus_changed_hdlr(evt);
            }
            else if (inline_evt->event_type == CUI_INLINE_NOTIFY_PROGRESS_BAR_VALUE_CHANGED)
            {
                mmi_prof_progress_bar_value_change_hdlr();
            }
        #endif
           break;
        }
        
        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PROF_TRC_INLINE_SUBMIT);
            #ifndef __MMI_PROF_BASIC_UI_STYLE__
                if (g_prof_mem_p->item_id == CUI_INLINE_ITEM_ID_BASE + KEYPAD_VOL_ITEM
                #ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__
                    || g_prof_mem_p->item_id == CUI_INLINE_ITEM_ID_BASE + RING_VOL_ITEM
                #endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */
                #ifdef __MMI_PROF_MSG_ALERTS_SUPPORT__
                #if !(defined(__MMI_MAINLCD_96X64__) || defined(__MMI_PROF_SLIM_PROFILES__))
                    || g_prof_mem_p->item_id == CUI_INLINE_ITEM_ID_BASE + MSG_VOL_ITEM
                #endif    // __MMI_MAINLCD_96X64__
                #endif /* __MMI_PROF_MSG_ALERTS_SUPPORT__ */
                #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
                #endif
                    )
                {
                    mmi_prof_save_cur_settings();
                    mmi_popup_display_simple_ext(STR_GLOBAL_SAVED, MMI_EVENT_SUCCESS, GRP_ID_PROFILES, NULL);
                    cui_inline_close(g_prof_mem_p->inline_gid);
                }
                else
                {
            mmi_prof_entry_customize_option_scrn();
                }
            #else
                mmi_prof_entry_customize_option_scrn();
            #endif
            break;
        }
        
        case EVT_ID_CUI_INLINE_GROUP_DEINIT:
        {
        #ifndef __MMI_PROF_BASIC_UI_STYLE__
        #ifdef __BT_SPK_VOL_CONTROL__
            mdi_audio_bt_clear_volume_sync_callback(PROFILES_BASE);
        #endif
            mdi_audio_resume_background_play();
        #endif
            break;
        }
        
        case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_submit_struct *inline_evt = (cui_event_inline_submit_struct *)evt;
        #ifndef __MMI_PROF_BASIC_UI_STYLE__
            #ifdef __BT_SPK_VOL_CONTROL__
            mdi_audio_bt_clear_volume_sync_callback(PROFILES_BASE);
            #endif
            mdi_audio_resume_background_play();
        #endif
            cui_inline_close(inline_evt->sender_id);
            break;
        }
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PROF_TRC_INLINE_CSK_EVT);
            
            #ifndef __MMI_PROF_BASIC_UI_STYLE__
                if (g_prof_mem_p->item_id == CUI_INLINE_ITEM_ID_BASE + KEYPAD_VOL_ITEM
                #ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__
                    || g_prof_mem_p->item_id == CUI_INLINE_ITEM_ID_BASE + RING_VOL_ITEM
                #endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */
                #ifdef __MMI_PROF_MSG_ALERTS_SUPPORT__
                #if !(defined(__MMI_MAINLCD_96X64__) || defined(__MMI_PROF_SLIM_PROFILES__))
                    || g_prof_mem_p->item_id == CUI_INLINE_ITEM_ID_BASE + MSG_VOL_ITEM
                #endif    // __MMI_MAINLCD_96X64__
                #endif /* __MMI_PROF_MSG_ALERTS_SUPPORT__ */
                #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
                #endif
                    )
                {
                    mmi_prof_save_cur_settings();
                    mmi_popup_display_simple_ext(STR_GLOBAL_SAVED, MMI_EVENT_SUCCESS, GRP_ID_PROFILES, NULL);
                    cui_inline_close(g_prof_mem_p->inline_gid);
                }
                else
                {
            mmi_prof_customize_scrn_csk_hdlr();
                }
            #else
			    mmi_prof_customize_scrn_csk_hdlr();
            #endif /* __MMI_PROF_BASIC_UI_STYLE__ */

            break;
        }
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        {
            cui_event_inline_submit_struct *inline_evt = (cui_event_inline_submit_struct *)evt;
            mmi_profiles_set_inline_item(inline_evt->sender_id);
		#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
			wgui_register_tap_callback(mmi_prof_tap_callback_hdlr);
		#endif
            break;
        }
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_INACTIVE:
        {
        #ifndef __MMI_PROF_BASIC_UI_STYLE__
            mmi_prof_preview_stop_tone();
        #endif    
            #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            
            #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
            #ifdef __MMI_TOUCH_FEEDBACK_VIBRATE_LEVEL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            #endif
            
            break;
        }
        /**********************FS editor CUI event*************************/
        #ifndef __MMI_PROF_BASIC_UI_STYLE__
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        {
            S16 error;
            WCHAR name[MMI_PROF_PROFILE_NAME_LENGTH + 1];
	    WCHAR *name_ptr;

            cui_fseditor_evt_struct *editor_evt = (cui_fseditor_evt_struct *)evt;
       
            if (0 == cui_fseditor_get_text(editor_evt->sender_id, (WCHAR *)name, (MMI_PROF_PROFILE_NAME_LENGTH + 1) * ENCODING_LENGTH))
            {
                mmi_popup_display_simple_ext(STR_ID_PROF_NAME_EMPTY, MMI_EVENT_FAILURE, GRP_ID_PROFILES, NULL);
            	break;	
            }

		name_ptr = (WCHAR *)name;

		while(*name_ptr)
    		{
        		if(*name_ptr != ' ')
            	break;	
        		name_ptr++;
            }
     
		if (0 == mmi_ucs2strlen((const CHAR*)name_ptr))
            {
                mmi_popup_display_simple_ext(STR_ID_PROF_NAME_EMPTY, MMI_EVENT_FAILURE, GRP_ID_PROFILES, NULL);
            	break;	
            }
		

	     
            if (0 < cui_fseditor_get_text(editor_evt->sender_id, (WCHAR *)name, (MMI_PROF_PROFILE_NAME_LENGTH + 1) * ENCODING_LENGTH))
            {
            #ifndef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
                if (mmi_ucs2cmp((const CHAR*)g_prof.my_style_name, (const CHAR*)name) != 0)
                {
                    if (mmi_ucs2cmp((const CHAR*)name, (const CHAR *)GetString(STR_ID_PROF_MY_STYLE)) == 0)
                    {   
                        /*user set to default name*/
                        mmi_prof_reset_my_style_name();    
                    }
                    else
                    {
                        g_prof.is_default_name = MMI_FALSE;
                        mmi_ucs2ncpy((CHAR*)g_prof.my_style_name, (CHAR*)name, MMI_PROF_PROFILE_NAME_LENGTH);
                        WriteRecord(NVRAM_EF_MMI_PROF_SETTING_LID,
                                    1,
                                    (void*)g_prof.my_style_name,
                                    (MMI_PROF_PROFILE_NAME_LENGTH + 1) * ENCODING_LENGTH,
                                    &error);
                    }
                }
            #else
                if (g_prof.add_flag == MMI_TRUE)
                {
                    mmi_prof_add_new_profile();
                    g_prof.add_flag = MMI_FALSE;
                }
                mmi_ucs2ncpy((CHAR*)g_prof.new_name[g_prof.curr_profile-MMI_PROFILE_NEW_1], (CHAR*)name, MMI_PROF_PROFILE_NAME_LENGTH);
                
                WriteRecord(NVRAM_EF_MMI_PROF_NEW_NAME_LID,
                                    1,
                                    (void*)g_prof.new_name,
                                    NVRAM_MMI_PROF_NEW_RECORD_SIZE,
                                    &error);
                WriteRecord(NVRAM_EF_MMI_PROF_NEW_FLAG_LID,
                                    1,
                                    (void*)g_prof.flag,
                                    NVRAM_MMI_PROF_FLAG_RECORD_SIZE,
                                    &error);
            #endif
                mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_PROFILES, NULL);
            }
            cui_fseditor_close(editor_evt->sender_id);
            break;
        }
        case EVT_ID_CUI_FSEDITOR_ABORT:
        {
            cui_fseditor_evt_struct *editor_evt = (cui_fseditor_evt_struct *)evt;
            cui_fseditor_close(editor_evt->sender_id);
        #ifdef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
            g_prof.add_flag = MMI_FALSE;
        #endif
            break;
        }
    #endif
        
        /**********************Tone selector event*************************/
        case EVT_ID_CUI_TONE_SELECTOR_CLOSE_REQUEST:
        {
            evt_cui = (cui_tone_selector_evt_struct *)evt;        
            cui_tone_selector_close(evt_cui->sender_id);
            break;
        }
        case EVT_ID_CUI_TONE_SELECTOR_RESULT:
        {
            mmi_prof_update_tone_setting(evt);
            break;
        }
    }
    return MMI_RET_OK;
}

#ifndef __MMI_PROF_BASIC_UI_STYLE__
/*****************************************************************************
 * FUNCTION
 *  mmi_prof_run_fseditor_cui
 * DESCRIPTION
 *  run tone selector CUI
 * PARAMETERS
 *  
 * RETURNS
 *  tone selector CUI group id
 *****************************************************************************/
static mmi_id mmi_prof_run_fseditor_cui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id editor_gid;
    WCHAR* name;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifndef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
        name = g_prof.my_style_name;
    #else
        name = g_prof.new_name[g_prof.curr_profile - MMI_PROFILE_NEW_1];
        if (g_prof.curr_profile == MMI_PROFILE_ADD_NEW_PROF)
        {
            mmi_ucs2ncpy((CHAR*)name, (CHAR*)GetString(STR_ID_PROF_NEW_PROF), MMI_PROF_PROFILE_NAME_LENGTH);
        }
    #endif
    if ((editor_gid = cui_fseditor_create(GRP_ID_PROFILES)) != GRP_ID_INVALID)
    {
        cui_fseditor_set_title(editor_gid, STR_GLOBAL_RENAME, GetRootTitleIcon(MAIN_MENU_PROFILES_MENUID));
        cui_fseditor_set_default_options_menu(editor_gid, STR_GLOBAL_DONE, STR_GLOBAL_CANCEL);
        cui_fseditor_set_text(editor_gid, 
                              name, 
                              (MMI_PROF_PROFILE_NAME_LENGTH + 1) * ENCODING_LENGTH, 
                              MMI_PROF_PROFILE_NAME_LENGTH);
	cui_fseditor_set_characters_filter(editor_gid, MMI_FALSE, (const UI_character_type *)srv_fmgr_path_get_invalid_chars());
        cui_fseditor_set_input_method(editor_gid, IMM_INPUT_TYPE_SENTENCE, NULL, INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
        cui_fseditor_run(editor_gid);
        return editor_gid;
    }
    else
    {
        return GRP_ID_INVALID;
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_run_tone_selector
 * DESCRIPTION
 *  run tone selector CUI
 * PARAMETERS
 *  
 * RETURNS
 *  tone selector CUI group id
 *****************************************************************************/
static mmi_id mmi_prof_run_tone_selector(mmi_id parent_gid, U16 tone_filter, mmi_id str_id, mmi_id curr_audio_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id ts_gid;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((ts_gid = cui_tone_selector_create(parent_gid)) != GRP_ID_INVALID)
    {
        cui_tone_selector_set_filter(ts_gid, tone_filter);
        cui_tone_selector_set_title_id(ts_gid, str_id, GetRootTitleIcon(MAIN_MENU_PROFILES_MENUID));
        cui_tone_selector_set_highlight_tone(ts_gid, curr_audio_id);
        cui_tone_selector_run(ts_gid);
        return ts_gid;
    }
    else
    {
        return GRP_ID_INVALID;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_check_allow_play_tone
 * DESCRIPTION
 *  preview tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_prof_check_allow_play_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_prof_get_activated_profile() == MMI_PROFILE_SILENT || g_prof_mem_p == NULL)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_preview_key_tone
 * DESCRIPTION
 *  preview tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_preview_key_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 audio_id = TONE_KEY_CLICK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PROF_TRC_PREVIEW_KEY_TONE, g_prof_mem_p->volume);
    if (!mmi_prof_check_allow_play_tone() || g_prof_mem_p->volume == 0 
                || g_prof_mem_p->cur_setting.keypad_tone == MMI_PROF_KEYPAD_SILENT)
    {
        return;
    }
    
    if (g_prof_mem_p->cur_setting.keypad_tone == MMI_PROF_KEYPAD_TONE)
    {
        audio_id = TONE_KEY_NORMAL; 
    }
    
        mdi_audio_play_id_with_vol_path(
            audio_id, 
            DEVICE_AUDIO_PLAY_ONCE,
            g_prof_mem_p->volume - 1,
            MDI_DEVICE_SPEAKER2);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_preview_touch_tone
 * DESCRIPTION
 *  preview tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_TOUCH_FEEDBACK_VIBRATE_LEVEL_SUPPORT__ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

#if defined(__MMI_PROF_CALL_ALERTS_SUPPORT__) || defined(__MMI_PROF_MSG_ALERTS_SUPPORT__)
#if defined(__MMI_BT_MUSIC__) || defined(__MMI_AUDIO_PLAYER_BT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_prof_bt_music_disconnect_callback
 * DESCRIPTION
 *  callback for BT music disconnect
 * PARAMETERS
 *  MMI_BOOL result - MMI_TRUE if BT music disconnected
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_bt_music_disconnect_callback(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        /* Call the appropriate function to execute when BT disconnected */
        mmi_prof_preview_play_tone();
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_preview_play_tone
 * DESCRIPTION
 *  preview tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_preview_play_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
    WCHAR* path_file_name = NULL;
#endif    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */
    mdi_result result = MDI_AUDIO_FAIL;
    U16 audio_id;
    MMI_BOOL is_DRM_support = MMI_TRUE;

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
	U16 i;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PROF_TRC_PREVIEW_PLAY_TONE, g_prof_mem_p->volume);

#if (defined(__MMI_BT_MUSIC__) || defined(__MMI_AUDIO_PLAYER_BT__) || defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__))
    /* Test if BT Music play is connected */
    if (mmi_bt_music_check_connection())
    {
        mmi_bt_music_disconnect(mmi_prof_bt_music_disconnect_callback);
        //return;
    }
#endif

    mdi_audio_suspend_background_play();
    StopTimer(TIMER_PROFILES_TONE_PLAY);

    if (!mmi_prof_check_allow_play_tone() || 
        srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        return;
    }

#ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__
    if ((g_prof_mem_p->item_id - CUI_INLINE_ITEM_ID_BASE) == RING_VOL_ITEM)
    {
    #ifdef __GAIN_TABLE_SUPPORT__
        mdi_audio_set_audio_type(MDI_AUDIO_TYPE_RING);
    #endif
    #ifndef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        audio_id = g_prof_mem_p->cur_setting.ring_tone[0];
    #ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
        path_file_name = g_prof_mem_p->ring_tone_path[0];
    #endif    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */
    #else
        audio_id = g_prof_mem_p->cur_setting.ring_tone[0];
    #ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
        path_file_name = g_prof_mem_p->ring_tone_path[0];
    #endif    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */
        for (i = 0; i<SRV_PROF_MT_CALL_TONE_AMOUNT; i++)
        {
            if(ring_item_exist[i] == MMI_TRUE)
            {
                audio_id = g_prof_mem_p->cur_setting.ring_tone[i];
            #ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
                path_file_name = g_prof_mem_p->ring_tone_path[i];
            #endif    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */
                break;
            }
        }
	#endif
    }
    else
#endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */
    {
#ifdef __MMI_PROF_MSG_ALERTS_SUPPORT__
    #ifdef __GAIN_TABLE_SUPPORT__
        mdi_audio_set_audio_type(MDI_AUDIO_TYPE_MESSAGE);
    #endif
    #ifndef __MMI_PROF_SPLIT_MSG_TONES__
      #ifndef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        audio_id = g_prof_mem_p->cur_setting.msg_tone[0];
      #else
        audio_id = g_prof_mem_p->cur_setting.msg_tone[0];  
        for (i = 0; i<SRV_PROF_SMS_TONE_AMOUNT; i++)
        {
            if(message_item_exist[i] == MMI_TRUE)
            {
                audio_id = g_prof_mem_p->cur_setting.msg_tone[i];
                break;
            }
        }
      #endif
    #else
        audio_id = g_prof_mem_p->cur_setting.sms_tone;
    #endif
#endif /* __MMI_PROF_MSG_ALERTS_SUPPORT__ */
    }

#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
    if (audio_id >= MMI_PROF_EXT_AUDIO_ID_BEGIN && audio_id < MMI_PROF_EXT_AUDIO_ID_END)
    {
    #if defined(__DRM_SUPPORT__)
        FS_HANDLE handle;
        handle = DRM_open_file((PU16)path_file_name, FS_READ_ONLY, DRM_PERMISSION_PLAY);
        if (handle >= FS_NO_ERROR)
        {
            if(!DRM_validate_forward_rule(handle, DRM_PERMISSION_PLAY))
            {
                DRM_close_file(handle);
                is_DRM_support = MMI_FALSE;
            }
            else
            {
            DRM_close_file(handle);
            mdi_audio_drm_disable_consume_all();
            }
        }
        else
        {
            is_DRM_support = MMI_FALSE;
        }
    #endif /*__DRM_SUPPORT__*/
        if (is_DRM_support == MMI_FALSE)
        {
            audio_id = SRV_PROF_AUD_RING11;
        }

        if (is_DRM_support == MMI_TRUE)
        {
            result = mdi_audio_play_file_with_vol_path(
                        (void *)path_file_name,
                        DEVICE_AUDIO_PLAY_INFINITE,
                        NULL,
                        mmi_prof_preview_tone_callback,
                        NULL,
                        MDI_AUD_VOL_MUTE((U8)g_prof_mem_p->volume),
                        MDI_DEVICE_SPEAKER2);
        }
        else
        {  /* if current file can not be played, we play default ring tone. Now no interface 
                           to let us get default ring, so we specific it, but it is not good and need to modify. */              
            U8 audio_type;
            U32 audio_len;
            U8 *audio_data;
            
            audio_data = get_audio(SRV_PROF_AUD_RING11, &audio_type, &audio_len);
            if (audio_data != NULL)
            {
                result = mdi_audio_play_string_with_vol_path(
                            (void*)audio_data,
                            audio_len,
                            audio_type,
                            DEVICE_AUDIO_PLAY_INFINITE,
                            mmi_prof_preview_tone_callback,
                            NULL,
                            MDI_AUD_VOL_MUTE((U8)g_prof_mem_p->volume),
                            MDI_DEVICE_SPEAKER2);
            }
        }        
    }
    else
#endif    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */
    {
        U8 audio_type;
        U32 audio_len;
        U8 *audio_data;
    
        audio_data = get_audio(audio_id, &audio_type, &audio_len);
        if (audio_data != NULL)
        {
            result = mdi_audio_play_string_with_vol_path(
                            (void*)audio_data,
                            audio_len,
                            audio_type,
                            DEVICE_AUDIO_PLAY_INFINITE,
                            mmi_prof_preview_tone_callback,
                            NULL,
                            MDI_AUD_VOL_MUTE((U8)g_prof_mem_p->volume),
                            MDI_DEVICE_SPEAKER2);
        }
    }

    if (result == MDI_AUDIO_SUCCESS)
    {
        g_prof_mem_p->is_playing = MMI_TRUE;
        g_prof_mem_p->playing_audio_id = audio_id;
    }
}
#endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ || __MMI_PROF_MSG_ALERTS_SUPPORT__  */

#ifndef __MMI_PROF_BASIC_UI_STYLE__
/*****************************************************************************
 * FUNCTION
 *  mmi_prof_preview_stop_tone
 * DESCRIPTION
 *  stop preview tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_preview_stop_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_resume_background_play();
    StopTimer(TIMER_PROFILES_TONE_PLAY);
 
    if (g_prof_mem_p->is_playing)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PROF_TRC_PREVIEW_STOP_TONE);
    #ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
        if (g_prof_mem_p->playing_audio_id >= MMI_PROF_EXT_AUDIO_ID_BEGIN && g_prof_mem_p->playing_audio_id < MMI_PROF_EXT_AUDIO_ID_END)
        {
            mdi_audio_stop_file();
        }
        else
    #endif    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */
        {
            mdi_audio_stop_string();
        }
        g_prof_mem_p->is_playing = MMI_FALSE;
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_preview_tone_callback
 * DESCRIPTION
 *  play default tone callback
 * PARAMETERS
 *  MDI result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_preview_tone_callback(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PROF_TRC_PLAY_CALLBACK, result);
    if (g_prof_mem_p != NULL && result == MDI_AUDIO_TERMINATED)
    {
        g_prof_mem_p->is_playing = MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_get_ring_tong_list
 * DESCRIPTION
 *  get ring tong list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_get_ring_tong_list(mmi_id str_id, U16 tone)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    U16 filter = 0;
    U16 tone_id;
    /*----------------------------------------------------------------*/
    /* code body                                                */
    /*----------------------------------------------------------------*/

    CUI_TONE_SELECTOR_FILTER_SET(filter, CUI_TONE_SELECTOR_FILTER_RING);
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    CUI_TONE_SELECTOR_FILTER_SET(filter, CUI_TONE_SELECTOR_FILTER_DLT_RING);
#endif
#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
    CUI_TONE_SELECTOR_FILTER_SET(filter, CUI_TONE_SELECTOR_FILTER_EXT_FILE);
    if (tone >= MMI_PROF_EXT_AUDIO_ID_BEGIN && tone < MMI_PROF_EXT_AUDIO_ID_END)
    {
        tone_id = 0;
    }
    else
#endif    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */
    {
        tone_id = tone;
    }
    mmi_prof_run_tone_selector(GRP_ID_PROFILES, filter, str_id, (U16)tone_id);    
}

#ifdef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_prof_add_new_profile
 * DESCRIPTION
 *  add new prof.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_add_new_profile(void)
{
    U32 i, j = 0;
    for (i = 0; i < 10; i++)
    {
        if (g_prof.new_name[i][0] != L'\0')
        {
            j++; /* record the order of the new add profile which will be show in the main screen*/
        }
    }
    
    for (i = 0; i < 10; i++)
    {
        /*find the first empty name and fill "new profile" in it*/
        if (g_prof.new_name[i][0] == L'\0')
        {
            mmi_ucs2ncpy((CHAR*)g_prof.new_name[i], (CHAR*)GetString(STR_ID_PROF_NEW_PROF), MMI_PROF_PROFILE_NAME_LENGTH);
            g_prof.flag[i] = j;  /*set the order of the new add profile, the flag[i] record the order of new_name[i] */
            g_prof.curr_profile = MMI_PROFILE_NEW_1 + i;
            break;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_delete_profile
 * DESCRIPTION
 *  del new prof.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_delete_profile(void)
{
    S16 error;
    U32 i;

    if (g_prof.activated_profile == g_prof.curr_profile)
    {
        g_prof.activated_profile = MMI_PROFILE_GENERAL;
        srv_prof_activate_profile((srv_prof_internal_profile_enum)MMI_PROFILE_GENERAL);
    }
    
    /*delete a profile,  only need set empty string to its name*/
    g_prof.new_name[g_prof.curr_profile - MMI_PROFILE_NEW_1][0] = L'\0';

    for(i = 0; i < 10; i++)
    {
        if (g_prof.flag[i] - g_prof.flag[g_prof.curr_profile - MMI_PROFILE_NEW_1] > 0)
        {
            g_prof.flag[i] -=1; /*all flag which larger than the delete profile flag need  reduce one*/
        }
    }
    g_prof.flag[g_prof.curr_profile - MMI_PROFILE_NEW_1] = 0; /*set the delete prof flag to 0*/
    
    WriteRecord(NVRAM_EF_MMI_PROF_NEW_FLAG_LID,
                                    1,
                                    (void*)g_prof.flag,
                                    NVRAM_MMI_PROF_FLAG_RECORD_SIZE,
                                    &error);
    
    WriteRecord(NVRAM_EF_MMI_PROF_NEW_NAME_LID,
                                    1,
                                    (void*)g_prof.new_name,
                                    NVRAM_MMI_PROF_NEW_RECORD_SIZE,
                                    &error);
    mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_DELETED), 
                                 MMI_EVENT_SUCCESS, 
                                 GRP_ID_ROOT, 
                                 NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_delete_proc
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_prof_delete_proc(mmi_event_struct* evt)
{
    mmi_alert_result_evt_struct* alert_evt = (mmi_alert_result_evt_struct*)evt;
    switch(alert_evt->result)
    {
        case MMI_ALERT_CNFM_OK:
        case MMI_ALERT_CNFM_YES:
        {
            mmi_prof_delete_profile();
            break;
        }
        case MMI_ALERT_CNFM_NO:
        case MMI_ALERT_CNFM_CANCEL:
        {
            mmi_frm_scrn_close_active_id();
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_entry_delete_confirm_scrn
 * DESCRIPTION
 * .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_entry_delete_confirm_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type str_delete[10];
    mmi_confirm_property_struct arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf((WCHAR*)str_delete,"%w", GetString(STR_GLOBAL_DELETE_ASK));
    
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = mmi_prof_delete_proc;
    arg.parent_id = GRP_ID_PROFILES;
    
    mmi_confirm_display((WCHAR *)str_delete, MMI_EVENT_QUERY, &arg);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_create_main_menu
 * DESCRIPTION
 *  create main menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_create_main_menu(mmi_id menu_gid)
{
    mmi_menu_id temp_menu_id, last_menu_id;
    U32 i,j;

    /*add "add profile" menu as the first menu in main screen*/
    temp_menu_id = MENU_ID_PROF_ADD_PROF;
    cui_menu_set_currlist(menu_gid, 1, &temp_menu_id);
    cui_menu_set_item_string(menu_gid, MENU_ID_PROF_ADD_PROF, (WCHAR*)GetString(STR_ID_PROF_ADD_PROFILE));
    cui_menu_set_item_image(menu_gid, MENU_ID_PROF_ADD_PROF, IMG_ID_PROF_ADD);

    /*add the fixed four profile as the second to fifth menu*/
    for (i = 0; i < 4; i++)
    {
        temp_menu_id = MENU_ID_PROF_GENERAL+i;
        cui_menu_insert_currlist(menu_gid, 1, &temp_menu_id, MENU_ID_PROF_ADD_PROF+i);
        cui_menu_set_item_string(menu_gid, temp_menu_id, (WCHAR*)GetString(STR_ID_PROF_GENERAL+i));
        cui_menu_set_item_image(menu_gid, temp_menu_id, IMG_ID_PROF_GENERAL+i);
    }

    /*the value of the flag[] means the order of  the new_name[], the valume of 0~9, 0 shoud be add first, 1 is second,  ..., 9 is the last */
    last_menu_id = MENU_ID_PROF_NEW_1 - 1;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            /*if the new_name is empty string, we will ignore it*/
            if (g_prof.new_name[j][0] == L'\0')
            {
                continue;
            }

            if (g_prof.flag[j] == i)
            {
                temp_menu_id = MENU_ID_PROF_NEW_1+j;
                cui_menu_insert_currlist(menu_gid, 1, &temp_menu_id, last_menu_id);
                last_menu_id = temp_menu_id;
                cui_menu_set_item_string(menu_gid, temp_menu_id, g_prof.new_name[j]);
                cui_menu_set_item_image(menu_gid, temp_menu_id, IMG_ID_PROF_MY_STYLE);
            }
        }
    }

    j = 0;
    for (i = 0; i < 10; i++)
    {
        if (g_prof.new_name[i][0] != L'\0')
        {
            j++; /*record the number of add new profile*/
        }
    }

    /*if we add 10 new profile, we will hide the menu "add profile", else not.*/
    if (j == 10)
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PROF_ADD_PROF, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PROF_ADD_PROF, MMI_FALSE);
    }
}
#endif /*#ifdef __MMI_PROF_ADD_DEL_PROF_SUPPORT__*/


#ifdef __MMI_PROF_BASIC_UI_STYLE__
extern S32 volume_level_UI;

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_exit_set_volume
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_exit_set_volume(void)
{
    #ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_clear_volume_sync_callback(PROFILES_BASE);
    #endif
    StopTimer(KEY_VOL_TIMER_ID);
    if ((g_prof_mem_p->item_id - CUI_INLINE_ITEM_ID_BASE) != KEYPAD_VOL_ITEM)
    {
        mdi_audio_stop_file();
        mdi_audio_stop_string();
        mdi_audio_resume_background_play();
    }
    if (SCR_KEY_TONE_VOLUME == mmi_frm_scrn_get_active_id())
    {
        mmi_frm_scrn_close_active_id();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_vol_down
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_vol_up_down(void)
{
	U16 item_index;
    
    StopTimer(KEY_VOL_TIMER_ID);
    g_prof_mem_p->volume = volume_level_UI;
    
    if (g_prof_mem_p->is_playing == MMI_TRUE)
    {
        mdi_audio_set_volume(VOL_TYPE_MEDIA, MDI_AUD_VOL_MUTE((U8)g_prof_mem_p->volume));
    }
    mmi_prof_preview_key_tone();

    item_index = g_prof_mem_p->item_id - CUI_INLINE_ITEM_ID_BASE;
      
#ifdef __MMI_PROF_CALL_ALERTS_SUPPORT__
    if(item_index == RING_VOL_ITEM)
    {
        g_prof_mem_p->cur_setting.ring_vol = g_prof_mem_p->volume;
    }
#endif /* __MMI_PROF_CALL_ALERTS_SUPPORT__ */
#ifdef __MMI_PROF_MSG_ALERTS_SUPPORT__
#if !(defined(__MMI_MAINLCD_96X64__) || defined(__MMI_PROF_SLIM_PROFILES__))
    else if (item_index == MSG_VOL_ITEM)
    {
        g_prof_mem_p->cur_setting.msg_vol = g_prof_mem_p->volume;
    }
#endif    // __MMI_MAINLCD_96X64__
    else
#endif /* __MMI_PROF_MSG_ALERTS_SUPPORT__ */
    {
        g_prof_mem_p->cur_setting.keypad_vol = g_prof_mem_p->volume;
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_set_volume_level
 * DESCRIPTION
 *  Set all Voulem screen handler functions and call the general entry screen of volume level.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_set_volume_level(void)
{
    S32 init_vol;
    VOLUMEHANDLER_TYPE volume_type;
    
    if (MDI_AUD_VOL_IS_MUTE_LEVEL(g_prof_mem_p->volume))
    {
        init_vol = g_prof_mem_p->volume & 0x0F;
    }
    else
    {
        init_vol = g_prof_mem_p->volume;
    }

    if ((g_prof_mem_p->item_id - CUI_INLINE_ITEM_ID_BASE) != KEYPAD_VOL_ITEM)
    {
        StartTimer(TIMER_PROFILES_TONE_PLAY, 100, mmi_prof_preview_play_tone);
        /* When Message or Ring volume items */
        volume_type = VOLUMEHANDLER_RING_TONE;
    }
    else
    {
        /* In case of Keypad tone current behaviour do not preview */
        volume_type = VOLUMEHANDLER_KEY_TONE;
    }

    SetVolumeKeyHandlerFunctions(
                mmi_prof_vol_up_down,
                mmi_prof_vol_up_down,
                mmi_prof_vol_up_down,
                mmi_prof_vol_up_down,
                0,
                &init_vol,
                STR_GLOBAL_OK,
                0,
                mmi_prof_exit_set_volume, 
                NULL,
                0,
                mmi_prof_exit_set_volume,
                1,
                (VOLUMEHANDLER_TYPE)volume_type);
    EntryScrSetKeyPadVolumeLevel();
#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_register_volume_sync_callback(PROFILES_BASE, MDI_AUD_VOL_LEVEL_NORMAL_MUTE, mmi_prof_handfree_volume_sync_callback);
#endif
}
#endif

#ifdef __MMI_AP_DCM_PROFILE__
#pragma arm section rodata , code
#endif

#endif /*#ifndef __OP01_FWPBW__*/

