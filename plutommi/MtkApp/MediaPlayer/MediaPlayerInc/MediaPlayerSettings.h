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
 *   MediaPlayerSettings.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Media Player data Define
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef MMI_MEDIA_PLAYER_SETTINGS_H
#define MMI_MEDIA_PLAYER_SETTINGS_H
/***************************************************************************** 
 * include                                                     
 *****************************************************************************/
#include "MMI_features.h"
#include "mmi_features_mediaplayer.h"
////#include "MediaplayerProt.h"
#include "DataAccountGProt.h"
#ifdef __MMI_MEDIA_PLAYER__


    #include "MMIDataType.h"
    #include "MediaPlayerPlayList.h"
    #include "FileMgrSrvGProt.h"
    #include "kal_general_types.h"
    #include "DtcntSrvGprot.h"
    #include "nvram_common_defs.h"
    #include "common_nvram_editor_data_item.h"

/*****************************************************************************
 * define                                                     
 *****************************************************************************/
#define MMI_MEDPLY_BRIGHTNESS_ADJ_LEVEL_COUNT    (11)       /* -5, -4, ...0 , +4, +5 */
#define MMI_MEDPLY_CONTRAST_ADJ_LEVEL_COUNT      (11)       /* -5, -4, ...0 , +4, +5 */
#define MMI_MEDPLY_PLAY_ADJ_SPEED_NUM            (MEDPLY_FEATURE_VIDEO_SPEED_COUNT)
#define MMI_MEDPLY_PLAY_DEFAULT_SPEED            (MEDPLY_DEFAULT_VIDEO_SPEED)
#define MMI_MEDPLY_MAX_PORT_LEN                  (6)        /* 0 - 65535 */
#define MMI_MEDPLY_MAX_IP_LEN                    (3)        /* xxx */
#define MMI_MEDPLY_MAX_MENU_ITEM_NUM             (32)
#define MMI_MEDPLY_PLAY_MODE_ITEM_NUM            (2)


#if defined(__MMI_MEDIA_PLAYER_A2DP_BLOCK_SPECTRUM__) || defined(__MMI_MEDIA_PLAYER_A2DP_BLOCK_PITCH_SHIFT__)

#if defined(__MMI_MEDIA_PLAYER_A2DP_BLOCK_SPECTRUM__) && defined(__MMI_MEDIA_PLAYER_A2DP_BLOCK_PITCH_SHIFT__)
#define STR_ID_MEDPLY_A2DP_BLOCK_DEF STR_ID_MEDPLY_A2DP_BLOCK_SPECTRUM_PITCH
#elif defined(__MMI_MEDIA_PLAYER_A2DP_BLOCK_SPECTRUM__)
#define STR_ID_MEDPLY_A2DP_BLOCK_DEF STR_ID_MEDPLY_A2DP_BLOCK_SPECTRUM
#else
#define STR_ID_MEDPLY_A2DP_BLOCK_DEF STR_ID_MEDPLY_A2DP_BLOCK_PITCH
#endif

#endif

/*****************************************************************************
 * enum                                                     
 *****************************************************************************/
typedef enum
{
    MMI_MEDPLY_SKIN_NO_SELECT,
    MMI_MEDPLY_SKIN_FILE_SELECTED,
    MMI_MEDPLY_SKIN_SELECT_ENUM_NUM
}mmi_medply_settings_skin_selected_enum;

typedef enum
{
    MMI_MEDPLY_SETTINGS_SKIN_OPTION_VIEW,
    MMI_MEDPLY_SETTINGS_SKIN_OPTION_SELECT,
    MMI_MEDPLY_SETTINGS_SKIN_OPTION_DELETE,
    MMI_MEDPLY_SETTINGS_SKIN_OPTION
}mmi_medply_settings_skin_option_enum;


typedef enum
{
    MMI_MEDPLY_SETTINGS_COMFIRM_SAVE,
    MMI_MEDPLY_SETTINGS_COMFIRM_RESTORE,

    MMI_MEDPLY_SETTINGS_ALERT_ALL
}mmi_medply_settings_alert_enum;




typedef enum
{
#ifndef __MMI_FTE_SUPPORT__
    MMI_MEDPLY_PLAY_SKIN,
#endif

    MMI_MEDPLY_PLAY_SHUFFULE,
    MMI_MEDPLY_PLAY_REPEAT,
#if !defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__)
    MMI_MEDPLY_PLAY_BG,
#endif
#ifdef MOTION_SENSOR_SUPPORT
    MMI_MEDPLY_PLAY_MOSTION,
#endif
#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
    MMI_MEDPLY_PLAY_SOUND_EFFECT,
#endif 
    MMI_MEDPLY_PLAYER_SETTINGS_ENUM_NUM
}mmi_medply_settings_play_num_enum;


typedef enum
{
   MMI_MEDPLY_SKIN_MENU_UNHIDE,
   MMI_MEDPLY_SKIN_MENU_HIDE,
   MMI_MEDPLY_SKIN_MENU_NUM
}mmi_medply_settings_skin_menu_enum;

typedef enum
{
    MMI_MEDPLY_PROFILE_NAME,
    MMI_MEDPLY_PROFILE_DATAACCOUNT,
    MMI_MEDPLY_PROFILE_PROXY_ONOFF,
    MMI_MEDPLY_PROFILE_PROXY_SERVER,
    MMI_MEDPLY_PROFILE_PROXY_PORT,
    MMI_MEDPLY_PROFILE_LOWEST_UDP,
    MMI_MEDPLY_PROFILE_HIGHEST_UDP,
    MMI_MEDPLY_PROFILE_ENUM_NUM
}mmi_medply_settings_profile_enum;

typedef enum
{
    MMI_MEDPLY_AUDIO_PLAY_SLOW2,
    MMI_MEDPLY_AUDIO_PLAY_SLOW1,
    MMI_MEDPLY_AUDIO_PLAY_NORMAL,
    MMI_MEDPLY_AUDIO_PLAY_FAST1,
    MMI_MEDPLY_AUDIO_PLAY_FAST2,
    MMI_MEDPLY_AUDIO_PLAY_SPEED
}mmi_medply_settings_audply_speed_enum;

/*****************************************************************************
 * enum for inline cui                                                    
 *****************************************************************************/

typedef enum
{
#if !defined (__MMI_MEDIA_PLAYER_FTE__) && !defined(__MMI_FTE_SUPPORT__)
#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
    SKIN_TYPE_CAPTION   = 0, 
    SKIN_TYPE_DISPLAY_ONLY,
#endif
#endif /*__MMI_MEDIA_PLAYER_FTE__   __MMI_FTE_SUPPORT__*/

    SHUFFLE_TYPE_CAPTION,
    SHUFFLE_TYPE_SELECT,
    REPEAT_TYPE_CAPTION,
    REPEAT_TYPE_SELECT,
#ifdef MOTION_SENSOR_SUPPORT
    MOTION_TYPE_CAPTION,
    MOTION_TYPE_SELECT,
#endif /* MOTION_SENSOR_SUPPORT */
#if !defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__)   
    BACKGROUND_TYPE_CAPTION,
    BACKGROUND_TYPE_SELECT,
#endif /* !__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__ */
#if defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
    SOUND_TYPE_CAPTION,
    SOUND_TYPE_SELECT1,
    SOUND_TYPE_SELECT2,
#endif /* defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)*/
#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
    BASS_TYPE_CAPTION,
    BASS_TYPE_SELECT,
#endif /* __MMI_AUDIO_BASS_ENHANCEMENT__ */

    MEDPLY_SETTINGS_PLAYER_INLINE_ITEM_END,
    MEDPLY_SETTINGS_PLAYER_INLINE_ITEM_NUM = (MEDPLY_SETTINGS_PLAYER_INLINE_ITEM_END - 0)
} mmi_medply_settings_player_inline_item_enum;

typedef enum
{
#ifdef __MMI_AUDIO_TIME_STRETCH__
    AUDIO_SPEED_TYPE_CAPTION   = 0, 
    AUDIO_SPEED_TYPE_SELECT,
#endif /* __MMI_AUDIO_TIME_STRETCH__ */
    AUDIO_DISPLAY_TYPE_CAPTION,
    AUDIO_DISPLAY_TYPE_SELECT,

    MEDPLY_SETTINGS_AUDIO_INLINE_ITEM_END,
    MEDPLY_SETTINGS_AUDIO_INLINE_ITEM_NUM = (MEDPLY_SETTINGS_AUDIO_INLINE_ITEM_END - 0)
} mmi_medply_settings_audio_inline_item_enum;


typedef enum
{
#if defined(__MMI_MEDIA_PLAYER_VIDEO_PROCESSING_SUPPORT__)  
    VIDEO_BRIGHTNESS_TYPE_CAPTION   = 0, 
    VIDEO_BRIGHTNESS_TYPE_SELECT,
    VIDEO_CONTRAST_TYPE_CAPTION,
    VIDEO_CONTRAST_TYPE_SELECT,
#endif /*__MMI_MEDIA_PLAYER_VIDEO_PROCESSING_SUPPORT__*/

#ifdef __MMI_MEDIA_PLAYER_VIDEO_SPEED__
    VIDEO_SPEED_TYPE_CAPTION, 
    VIDEO_SPEED_TYPE_SELECT,
#endif /* __MMI_AUDIO_TIME_STRETCH__ */
#ifdef __MMI_VIDEO_3D_ANAGLYPH__
    VIDEO_PLAY_MODE_TYPE_CAPTION, 
    VIDEO_PLAY_MODE_TYPE_SELECT,
#endif
    MEDPLY_SETTINGS_VIDEO_INLINE_ITEM_END,
    MEDPLY_SETTINGS_VIDEO_INLINE_ITEM_NUM = (MEDPLY_SETTINGS_VIDEO_INLINE_ITEM_END - 0)
} mmi_medply_settings_video_inline_item_enum;

typedef enum
{
    PROFILE_NAME_TYPE_CAPTION   = 0, 
    PROFILE_NAME_TYPE_FULLSCREEN_EDIT,
    DATA_ACCOUNT_TYPE_CAPTION,
    DATA_ACCOUNT_TYPE_DISPLAY_ONLY,
    USE_PROXY_TYPE_CAPTION, 
    USE_PROXY_TYPE_SELECT,
    PROXY_SERVER_TYPE_CAPTION, 
    PROXY_SERVER_TYPE_FULLSCREEN_EDIT,
    PROXY_PORT_TYPE_CAPTION, 
    PROXY_PORT_TYPE_TEXT_EDIT,
    LOWEST_UDP_TYPE_CAPTION, 
    LOWEST_UDP_TYPE_TEXT_EDIT,
    HIGHEST_UDP_TYPE_CAPTION, 
    HIGHST_UDP_TYPE_TEXT_EDIT,
    
    MEDPLY_SETTINGS_PROFILE_INLINE_ITEM_END,
    MEDPLY_SETTINGS_PROFILE_INLINE_ITEM_NUM = (MEDPLY_SETTINGS_PROFILE_INLINE_ITEM_END - 0)
} mmi_medply_settings_profile_inline_item_enum;

/*****************************************************************************
 * Typedef struct : define for nvram storage  structure                                             
 *****************************************************************************/
typedef struct
{
    U16 audio_speed;
    U16 brightness;
    U16 contrast;
    U16 video_speed;    
    U16 play_mode;
    U8 skin_custom_path[MEDPLY_MAX_PATH_SIZE];
    U8 is_theme_default;
    U8 is_shuffle;
    U8 repeat;
    U8 is_bgplay;
    U8 mainscrdisp_index;
    U8 default_storage_drv_letter;
    U8 sms_sim;
    U8 is_autofulscr_by_sensor;
    U32 subtitle_iso;
}mmi_medply_settings_struct;



/*****************************************************************************
 * Typedef struct : define for inline            
 *****************************************************************************/

/*  media player settings - player settings */
typedef struct
{
    S32 skin_select_id;
    S32 default_storage_id;
    S32 bg_play_id;
    S32 repeat_play_id;
    S32 shuffle_play_id;    
    //UI_string_type settings_on_off_str_list[2];	//can be delete
    //UI_string_type shuffle_on_off_str_list[2];//can be delete
    //UI_string_type repeat_str_list[3];//can be delete
    //UI_string_type sim_string[2];//can be delete
    //UI_string_type motion_sensor_tilt_string[2];//can be delete
    //UI_string_type settings_skin_list[MMI_MEDPLY_SKIN_NUM_ALL];//can be delete
    S32 sms_sim_id;
    S32 is_autofulscr_bysensor;
    U8 skin_file_selected;
    MMI_BOOL is_restored_save;
}mmi_medply_settings_play_context;

/* media player settings - audio settings */
typedef struct
{
    S32 audio_speed_id;    
    S32 mainscr_disp_id;
    U16 audio_speed_value;
    //UI_string_type audio_speed[MDI_AUDIO_MAX_SPEED_NUM];//can be delete
    //UI_string_type mainscr_disp[MMI_MEDPLY_MAINSCR_DISP_ALL];//can be delete
}mmi_medply_settings_audio_context;

/* media player settings - video settings */
typedef struct
{
    S32 video_brightness_id;    
    S32 video_contrast_id;    
    S32 video_speed_id; 
    S32 auto_fulscr_play_id;
    S32 play_frame_id;
    U16 video_speed_value;
    S32 video_play_mode; 
    //UI_string_type settings_onoff_str_list[2];//can be delete
    //UI_string_type video_brightness[MMI_MEDPLY_BRIGHTNESS_ADJ_LEVEL_COUNT];//can be delete
    //UI_string_type video_contrast[MMI_MEDPLY_CONTRAST_ADJ_LEVEL_COUNT];//can be delete
    //UI_string_type video_speed[MMI_MEDPLY_PLAY_ADJ_SPEED_NUM];//can be delete
}mmi_medply_settings_video_context;

#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
typedef struct
{
    U32 iso_count;
    U32 iso_list[MDI_VIDEO_MAX_SUBTITLE_NUM];
    U32 track_index_list[MDI_VIDEO_MAX_SUBTITLE_NUM];
    U32 iso_active;
    U32 track_index_active;
    U32 cur_sel_index;
    U32 old_track_index;
    PU8  lcc_name[MDI_VIDEO_MAX_SUBTITLE_NUM];
    MMI_BOOL has_inited;
}mmi_medply_settings_subtitle_subtitle;
#endif


/* media player settings - network settings */
#if defined(__MMI_MEDIA_PLAYER_STREAM__) || defined(__MMI_KURO_DOWNLOAD_SUPPORT__)
typedef struct
{
    MMI_ID inline_gid;
    S32 inline_proxy_on_off; 
    U32 inline_data_account_id[MMI_MAX_SIM_NUM];    
    CHAR data_account_name[(MAX_DATA_ACCOUNT_NAME_LEN + DATA_ACCOUNT_NAME_SUFFIX_LEN + 1)*ENCODING_LENGTH]; 
    U8 active_profile_idx;
    U8 cur_sel_profile_idx;	
    U8 cbm_app_id;
    nvram_ef_medply_settings_profile_struct network_profile[NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_TOTAL];
}mmi_medply_settings_network_context;

#endif/* defined(__MMI_MEDIA_PLAYER_STREAM__) || defined(__MMI_KURO_DOWNLOAD_SUPPORT__) */


/*****************************************************************************
 * Global Function                                                     
 *****************************************************************************/

#endif /* __MMI_MEDIA_PLAYER__*/
#endif /* MMI_MEDIA_PLAYER_SETTINGS_H */
