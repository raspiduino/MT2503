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
 *   MediaPlayerSettingSrc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Media Player settings source code
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
#ifndef MMI_MEDIA_PLAYER_SETTINGS
#define MMI_MEDIA_PLAYER_SETTINGS

#include "MMI_features.h"
////#include "MMI_include.h"
////#include "FileMgrSrvGProt.h"
#ifdef __MMI_MEDIA_PLAYER__

    #include "wgui_inline_edit.h"
    #include "kal_general_types.h"
    #include "MMIDataType.h"
    #include "GlobalResDef.h"
#if defined(__MMI_SOUND_EFFECT__)
    #include "mmi_rp_app_soundeffect_def.h"
#endif
    #include "MediaPlayerEnumDef.h"
    #include "MMI_features_mediaplayer.h"
    #include "ImeGprot.h"
    #include "custom_mmi_default_value.h"
    #include "wgui_categories_util.h"
    #include "GlobalConstants.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "AlertScreen.h"
    #include "mmi_frm_events_gprot.h"
    #include "fs_func.h"
    #include "fs_type.h"
    #include "fs_errcode.h"
    #include "Unicodexdcl.h"
    #include "nvram_common_defs.h"
    #include "mmi_frm_nvram_gprot.h"
    #include "common_nvram_editor_data_item.h"
    #include "gui_data_types.h"
    #include "string.h"
    #include "CustDataRes.h"
    #include "DebugInitDef_Int.h"
    #include "mmi_media_app_trc.h"
    #include "MMI_media_app_trc.h"
    #include "stack_config.h"
    #include "kal_trace.h"
    #include "BTMMIA2DPScr.h"
    #include "gui_typedef.h"
    #include "CommonScreensResDef.h"
    #include "gdi_include.h"
    #include "wgui_categories_multimedia.h"
    #include "gdi_const.h"
    #include "gdi_features.h"
    #include "mmi_rp_file_type_def.h"
    #include "FileMgrType.h"
    #include "device.h"
    #include "wgui_touch_screen.h"
    #include "DataAccountGProt.h"
    #include "cbm_api.h"
    #include "wgui_categories_list.h"
    #include "gui_fixed_menuitems.h"
    #include "wgui_categories.h"
    #include "cbm_consts.h"
    #include "custom_data_account.h"



#include "CommonScreens.h"
#include "gui.h"                /* Gui functions */
#include "Mdi_datatype.h"
#include "Mdi_audio.h"
#include "Mdi_video.h"
////#include "FileManagerGProt.h"   /* file path / file error  */
////#include "FileManagerDef.h"     /* error string id */
////#include "FileMgr.h"
#include "Drm_def.h"
#include "Drm_gprot.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif
#include "dataaccountcuigprot.h"
#include "Dtcntsrvgprot.h"

////#include "Med_utility.h"
/* cui prot */
#include "FilemgrCuiGprot.h"
#include "menucuigprot.h"
#include "inlinecuigprot.h"


#if defined(__MMI_A2DP_SUPPORT__)
////#include "SimDetectionGprot.h"     /* power on flight mode check */
#include "BTMMIScrGprots.h"
////#include "av_bt.h"
////#include "app_str.h"
#include "BtcmSrvGprot.h"

#endif /* __MMI_A2DP_SUPPORT__ */

////#include "ConnectManageGProt.h"

#include "mmi_rp_app_medply_def.h"
//#include "MediaPlayerResDef.h"
#include "MediaPlayerProt.h"
#include "MediaPlayerSettings.h"
#include "MediaPlayerPlaylist.h"

#if defined(__MMI_MEDIA_PLAYER_VDOREC__)
#ifdef __MMI_CAMCORDER__
#include "mmi_features_camcorder.h"
#include "CamcorderGprot.h"
#else
////#include "VdoRecGprot.h"
#endif /* __MMI_CAMCORDER__ */
#endif /* __MMI_VIDEO_RECORDER__ && ! MJPG_SUPPORT*/

#if defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__) || defined(__MMI_AUDIO_BASS_ENHANCEMENT__)
////#include "SettingDefs.h"
////#include "SettingResDef.h"
#include "SoundEffect.h"
#endif /* defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__) */ 

#ifdef __MMI_VIDEO_3D_ANAGLYPH__
#define MMI_MEDPLY_SETTINGS_VIDEO_3D_SUPPORT
#endif

#ifdef __MMI_MEDIA_PLAYER_STREAM__
#include "CbmSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#endif

extern wgui_inline_item wgui_inline_items[];        /* wgui_inline_edit.c */

/***************************************************************************** 
 * Global variables
 *****************************************************************************/
static mmi_medply_settings_struct  g_mmi_medply_settings;
static mmi_medply_settings_play_context  g_mmi_medply_settings_player;
static mmi_medply_settings_audio_context  g_mmi_medply_settings_audio;
#if defined(__MMI_MEDIA_PLAYER_VIDEO_PROCESSING_SUPPORT__)  || defined(__MMI_MEDIA_PLAYER_VIDEO_SPEED__)  || defined(MMI_MEDPLY_SETTINGS_VIDEO_3D_SUPPORT)
static mmi_medply_settings_video_context  g_mmi_medply_settings_video;
#endif
#if defined(__MMI_MEDIA_PLAYER_STREAM__) 
static mmi_medply_settings_network_context g_mmi_medply_settings_network_profile; 
#endif /* __MMI_MEDIA_PLAYER_STREAM__ */
static MMI_BOOL g_selected_skin_changed = MMI_FALSE;
U8 g_skin_custom_path[SRV_FMGR_PATH_BUFFER_SIZE];
//static S32 g_medply_settings_highlight_item = 0;

#if defined(__MMI_AUDIO_EQUALIZER__) && defined(__MMI_EDITABLE_AUDIO_EQUALIZER__)
static audio_equalizer_struct g_settings_audio_equalizer_temp;
static U16 g_settings_eq_rename_flag_temp;
#endif

#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
static mmi_medply_settings_subtitle_subtitle g_mmi_medply_settings_subtitle;
#endif

extern MMI_ID g_gid_medply;

/*********************************** player settings inline ******************************************/


/* skin */
#if !defined (__MMI_MEDIA_PLAYER_FTE__) && !defined(__MMI_FTE_SUPPORT__)
#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
static const cui_inline_item_caption_struct settings_player_inline_caption_skin = 
{
    STR_ID_MEDPLY_SKIN
};
#endif
#endif /*__MMI_MEDIA_PLAYER_FTE__   __MMI_FTE_SUPPORT__*/


/* shuffle */
static const cui_inline_item_caption_struct settings_player_inline_caption_shuffle = 
{
    STR_ID_MEDPLY_SHUFFLE
};
static const U16 settings_player_shuffle_item_str[] =
{
    STR_GLOBAL_OFF, 
    STR_GLOBAL_ON
};
static const cui_inline_item_select_struct settings_player_inline_select_shuffle = 
{
    2, 0, (U16 *)&settings_player_shuffle_item_str[0]
};


/* repeat */
static const cui_inline_item_caption_struct settings_player_inline_caption_repeat = 
{
    STR_ID_MEDPLY_REPEAT
};
static const U16 settings_player_repeat_item_str[] =
{
    STR_GLOBAL_OFF, 
    STR_ID_MEDPLY_REPEAT_ONE,
    STR_ID_MEDPLY_REPEAT_ALL
};
static const cui_inline_item_select_struct settings_player_inline_select_repeat = 
{
    3, 0, (U16 *)&settings_player_repeat_item_str[0]
};


/* motion */
#ifdef MOTION_SENSOR_SUPPORT
static const cui_inline_item_caption_struct settings_player_inline_caption_motion = 
{
    STR_ID_MEDPLY_SETTINGS_AUTO_FULLSCR_BYSENSOR
};
static const U16 settings_player_motion_item_str[] =
{
    STR_GLOBAL_OFF, 
    STR_GLOBAL_ON
};
static const cui_inline_item_select_struct settings_player_inline_select_motion = 
{
    2, 0, (U16 *)&settings_player_motion_item_str[0]
};
#endif /* MOTION_SENSOR_SUPPORT */

/* background */
#if !defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__)   
static const cui_inline_item_caption_struct settings_player_inline_caption_background = 
{
    STR_ID_MEDPLY_BG_PLAY
};
static const U16 settings_player_background_item_str[] =
{
    STR_GLOBAL_OFF, 
    STR_GLOBAL_ON
};
static const cui_inline_item_select_struct settings_player_inline_select_background = 
{
    2, 0, (U16 *)&settings_player_background_item_str[0]
};
#endif /* !__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__ */


/* Sound effect */
#if defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
static const cui_inline_item_caption_struct settings_player_inline_caption_sound = 
{
    STR_ID_SETTING_SOUND_EFFECT
};
static const U16 settings_player_sound_item_str1[] =
{
    STR_GLOBAL_OFF, 
#ifdef __MMI_AUDIO_EQUALIZER__
    STR_ID_SETTING_AUDIO_EQUALIZER,
#endif
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    STR_ID_SETTING_AUDIO_REVERB_EFFECT,
#endif
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    STR_ID_SETTING_AUDIO_SURROUND_EFFECT
#endif
};
static const cui_inline_item_select_struct settings_player_inline_select_sound1 = 
{
    NO_OF_SETTINGS_SOUND_EFFECTS, 0, (U16 *)&settings_player_sound_item_str1[0]
};
#endif /* defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)*/


/* bass */
#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
static const cui_inline_item_caption_struct settings_player_inline_caption_bass = 
{
    STR_ID_SETTING_BASS_ENHANCEMENT
};
static const U16 settings_player_bass_item_str[] =
{
    STR_GLOBAL_OFF, 
    STR_GLOBAL_ON
};
static const cui_inline_item_select_struct settings_player_inline_select_bass = 
{
    2, 0, (U16 *)&settings_player_bass_item_str[0]
};
#endif /* __MMI_AUDIO_BASS_ENHANCEMENT__ */

 
static const cui_inline_set_item_struct mmi_medply_settings_player_inline_item[] = 
{
#if !defined (__MMI_MEDIA_PLAYER_FTE__) && !defined(__MMI_FTE_SUPPORT__)
#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
    {CUI_INLINE_ITEM_ID_BASE + SKIN_TYPE_CAPTION,         CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,       0,      (void*)&settings_player_inline_caption_skin},
    {CUI_INLINE_ITEM_ID_BASE + SKIN_TYPE_DISPLAY_ONLY,    CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_CENTER_JUSTIFY,  0,      NULL},
#endif
#endif /*__MMI_MEDIA_PLAYER_FTE__   __MMI_FTE_SUPPORT__*/
    {CUI_INLINE_ITEM_ID_BASE + SHUFFLE_TYPE_CAPTION,      CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,       0,      (void*)&settings_player_inline_caption_shuffle},
    {CUI_INLINE_ITEM_ID_BASE + SHUFFLE_TYPE_SELECT,       CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,        0,      (void*)&settings_player_inline_select_shuffle},
    {CUI_INLINE_ITEM_ID_BASE + REPEAT_TYPE_CAPTION,       CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,       0,      (void*)&settings_player_inline_caption_repeat},
    {CUI_INLINE_ITEM_ID_BASE + REPEAT_TYPE_SELECT,        CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,        0,      (void*)&settings_player_inline_select_repeat}
#ifdef MOTION_SENSOR_SUPPORT
   ,{CUI_INLINE_ITEM_ID_BASE + MOTION_TYPE_CAPTION,       CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,       0,      (void*)&settings_player_inline_caption_motion},
    {CUI_INLINE_ITEM_ID_BASE + MOTION_TYPE_SELECT,        CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,        0,      (void*)&settings_player_inline_select_motion}
#endif /* MOTION_SENSOR_SUPPORT */
#if !defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__)   
   ,{CUI_INLINE_ITEM_ID_BASE + BACKGROUND_TYPE_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,       0,      (void*)&settings_player_inline_caption_background},
    {CUI_INLINE_ITEM_ID_BASE + BACKGROUND_TYPE_SELECT,    CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,        0,      (void*)&settings_player_inline_select_background}
#endif /* !__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__ */
#if defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
   ,{CUI_INLINE_ITEM_ID_BASE + SOUND_TYPE_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,       0,      (void*)&settings_player_inline_caption_sound},
    {CUI_INLINE_ITEM_ID_BASE + SOUND_TYPE_SELECT1,        CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,        0,      (void*)&settings_player_inline_select_sound1},
    {CUI_INLINE_ITEM_ID_BASE + SOUND_TYPE_SELECT2,        CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,        0,      NULL}
#endif /* defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)*/
#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
   ,{CUI_INLINE_ITEM_ID_BASE + BASS_TYPE_CAPTION,         CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,       0,      (void*)&settings_player_inline_caption_bass},
    {CUI_INLINE_ITEM_ID_BASE + BASS_TYPE_SELECT,          CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,        0,      (void*)&settings_player_inline_select_bass}
#endif /* __MMI_AUDIO_BASS_ENHANCEMENT__ */
};


static const cui_inline_struct mmi_medply_settings_player_inline_screen = 
{
    MEDPLY_SETTINGS_PLAYER_INLINE_ITEM_NUM,
    STR_ID_MEDPLY_SETTINGS_PLAYER,
    0,
    CUI_INLINE_SCREEN_LOOP, 
    NULL,
    mmi_medply_settings_player_inline_item 
};

/*********************************** audio settings inline ******************************************/
#ifdef __MMI_MEDIA_PLAYER_AUDIO__

/* play speed */
#ifdef __MMI_AUDIO_TIME_STRETCH__
static const cui_inline_item_caption_struct settings_audio_inline_caption_speed = 
{
    STR_ID_MEDPLY_AUDIO_PLAY_SPEED
};

static const U16 settings_audio_speed_item_str[] =
{
    STR_ID_MEDPLY_SPEED_SLOW2,
    STR_GLOBAL_SLOW,
    STR_GLOBAL_NORMAL,
    STR_GLOBAL_FAST,
    STR_ID_MEDPLY_SPEED_FAST2
};
static const cui_inline_item_select_struct settings_audio_inline_select_speed = 
{
    MDI_AUDIO_MAX_SPEED_NUM, 0, (U16 *)&settings_audio_speed_item_str[0]
};
#endif /* __MMI_AUDIO_TIME_STRETCH__ */

/* display */
static const cui_inline_item_caption_struct settings_audio_inline_caption_display = 
{
    STR_ID_MEDPLY_MAINSCR_DISP
};
static const U16 settings_audio_display_item_str[] =
{
        STR_GLOBAL_DETAILS
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
        ,STR_ID_MEDPLY_SPECTRUM
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */
#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__
        ,STR_ID_MEDPLY_LYRICS
#endif /* __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__ */
};
static const cui_inline_item_select_struct settings_audio_inline_select_display = 
{
    MMI_MEDPLY_MAINSCR_DISP_ALL, 0, (U16 *)&settings_audio_display_item_str[0]
};



static const cui_inline_set_item_struct mmi_medply_settings_audio_inline_item[] = 
{
#ifdef __MMI_AUDIO_TIME_STRETCH__
    {CUI_INLINE_ITEM_ID_BASE + AUDIO_SPEED_TYPE_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,       0,      (void*)&settings_audio_inline_caption_speed},
    {CUI_INLINE_ITEM_ID_BASE + AUDIO_SPEED_TYPE_SELECT,         CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,        0,      (void*)&settings_audio_inline_select_speed},
#endif /* __MMI_AUDIO_TIME_STRETCH__ */
    {CUI_INLINE_ITEM_ID_BASE + AUDIO_DISPLAY_TYPE_CAPTION,      CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,       0,      (void*)&settings_audio_inline_caption_display},
    {CUI_INLINE_ITEM_ID_BASE + AUDIO_DISPLAY_TYPE_SELECT,       CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,        0,      (void*)&settings_audio_inline_select_display}
};

static const cui_inline_struct mmi_medply_settings_audio_inline_screen = 
{
    MEDPLY_SETTINGS_AUDIO_INLINE_ITEM_NUM,
    STR_ID_MEDPLY_SETTINGS_AUDIO,
    0,
    CUI_INLINE_SCREEN_LOOP, 
    NULL, 
    mmi_medply_settings_audio_inline_item 
};
#endif /*__MMI_MEDIA_PLAYER_AUDIO__*/


/*********************************** video settings inline ******************************************/
#ifdef __MMI_MEDIA_PLAYER_VIDEO__
#if defined(__MMI_MEDIA_PLAYER_VIDEO_PROCESSING_SUPPORT__)  || defined(__MMI_MEDIA_PLAYER_VIDEO_SPEED__) || defined(MMI_MEDPLY_SETTINGS_VIDEO_3D_SUPPORT) 

#if defined(__MMI_MEDIA_PLAYER_VIDEO_PROCESSING_SUPPORT__) 

static const U16 settings_video_adjust_item_str[] =
{
    STR_ID_MEDPLY_ADJUST_N5,
    STR_ID_MEDPLY_ADJUST_N4,
    STR_ID_MEDPLY_ADJUST_N3,
    STR_ID_MEDPLY_ADJUST_N2,
    STR_ID_MEDPLY_ADJUST_N1,
    STR_ID_MEDPLY_ADJUST_0,
    STR_ID_MEDPLY_ADJUST_P1,
    STR_ID_MEDPLY_ADJUST_P2,
    STR_ID_MEDPLY_ADJUST_P3,
    STR_ID_MEDPLY_ADJUST_P4,
    STR_ID_MEDPLY_ADJUST_P5
};

/* brightness */
static const cui_inline_item_caption_struct settings_video_inline_caption_brightness = 
{
    STR_ID_MEDPLY_BRIGHTNESS
};
static const cui_inline_item_select_struct settings_video_inline_select_brightness = 
{
    MMI_MEDPLY_BRIGHTNESS_ADJ_LEVEL_COUNT, 0, (U16 *)&settings_video_adjust_item_str[0]
};

/* contrast */
static const cui_inline_item_caption_struct settings_video_inline_caption_contrast = 
{
    STR_ID_MEDPLY_CONTRAST
};
static const cui_inline_item_select_struct settings_video_inline_select_contrast = 
{
    MMI_MEDPLY_CONTRAST_ADJ_LEVEL_COUNT, 0, (U16 *)&settings_video_adjust_item_str[0]
};
#endif

/* play speed */
#ifdef __MMI_MEDIA_PLAYER_VIDEO_SPEED__
static const cui_inline_item_caption_struct settings_video_inline_caption_speed = 
{
    STR_ID_MEDPLY_VIDEO_PLAY_SPEED
};
#ifdef  __MMI_MEDIA_PLAYER_VIDEO_SPEED_FULL_DEFINE__ 
static const U16 settings_video_speed_item_str[] =
{
    STR_ID_MEDPLY_VIDEO_SPEED0,
    STR_ID_MEDPLY_VIDEO_SPEED1,
    STR_ID_MEDPLY_VIDEO_SPEED2, 
    STR_ID_MEDPLY_VIDEO_SPEED3,
    STR_ID_MEDPLY_VIDEO_SPEED4,
    STR_ID_MEDPLY_VIDEO_SPEED5,
    STR_ID_MEDPLY_VIDEO_SPEED6,
    STR_ID_MEDPLY_VIDEO_SPEED7
};
#else /*__MMI_MEDIA_PLAYER_VIDEO_SPEED_FULL_DEFINE__*/
static const U16 settings_video_speed_item_str[] =
{
    STR_ID_MEDPLY_VIDEO_SPEED0,
    STR_ID_MEDPLY_VIDEO_SPEED2,
    STR_ID_MEDPLY_VIDEO_SPEED5,
    STR_ID_MEDPLY_VIDEO_SPEED6,
    STR_ID_MEDPLY_VIDEO_SPEED7
};
#endif /*__MMI_MEDIA_PLAYER_VIDEO_SPEED_FULL_DEFINE__*/
static const cui_inline_item_select_struct settings_video_inline_select_speed = 
{
    MMI_MEDPLY_PLAY_ADJ_SPEED_NUM, 0, (U16 *)&settings_video_speed_item_str[0]
};
#endif /* __MMI_MEDIA_PLAYER_VIDEO_SPEED__ */

#ifdef MMI_MEDPLY_SETTINGS_VIDEO_3D_SUPPORT
static const U16 settings_video_play_mode_item_str[] =
{
    STR_GLOBAL_OFF, 
    STR_GLOBAL_ON
};

/* play mode */
static const cui_inline_item_caption_struct settings_video_inline_caption_play_mode = 
{
    STR_ID_MEDPLY_PLAY_MODE
};

static const cui_inline_item_select_struct settings_video_inline_select_play_mode = 
{
    MMI_MEDPLY_PLAY_MODE_ITEM_NUM, 0, (U16 *)&settings_video_play_mode_item_str[0]
};
#endif

static const cui_inline_set_item_struct mmi_medply_settings_video_inline_item[] = 
{
#if defined(__MMI_MEDIA_PLAYER_VIDEO_PROCESSING_SUPPORT__) 
    {CUI_INLINE_ITEM_ID_BASE + VIDEO_BRIGHTNESS_TYPE_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,       0,      (void*)&settings_video_inline_caption_brightness},
    {CUI_INLINE_ITEM_ID_BASE + VIDEO_BRIGHTNESS_TYPE_SELECT,    CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,        0,      (void*)&settings_video_inline_select_brightness},
    {CUI_INLINE_ITEM_ID_BASE + VIDEO_CONTRAST_TYPE_CAPTION,     CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,       0,      (void*)&settings_video_inline_caption_contrast},
    {CUI_INLINE_ITEM_ID_BASE + VIDEO_CONTRAST_TYPE_SELECT,      CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,        0,      (void*)&settings_video_inline_select_contrast},
#endif
#ifdef __MMI_MEDIA_PLAYER_VIDEO_SPEED__
    {CUI_INLINE_ITEM_ID_BASE + VIDEO_SPEED_TYPE_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,       0,      (void*)&settings_video_inline_caption_speed},
    {CUI_INLINE_ITEM_ID_BASE + VIDEO_SPEED_TYPE_SELECT,         CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,        0,      (void*)&settings_video_inline_select_speed}
#endif /* __MMI_MEDIA_PLAYER_VIDEO_SPEED__ */
#ifdef MMI_MEDPLY_SETTINGS_VIDEO_3D_SUPPORT
    {CUI_INLINE_ITEM_ID_BASE + VIDEO_PLAY_MODE_TYPE_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,       0,      (void*)&settings_video_inline_caption_play_mode},
    {CUI_INLINE_ITEM_ID_BASE + VIDEO_PLAY_MODE_TYPE_SELECT,         CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,        0,      (void*)&settings_video_inline_select_play_mode}
#endif
};

static const cui_inline_struct mmi_medply_settings_video_inline_screen = 
{
    MEDPLY_SETTINGS_VIDEO_INLINE_ITEM_NUM,
    STR_ID_MEDPLY_SETTINGS_VIDEO,
    0,
    CUI_INLINE_SCREEN_LOOP, 
    NULL,
    mmi_medply_settings_video_inline_item 
};
#endif
#endif

/*********************************** profile edit inline ******************************************/
#if defined(__MMI_MEDIA_PLAYER_STREAM__) 
/* profile name */
static const cui_inline_item_caption_struct settings_profile_inline_caption_profile_name = 
{
    STR_ID_MEDPLY_PROFILE_NAME
};


static const cui_inline_item_fullscreen_edit_struct settings_profile_inline_fullscreen_edit_profile_name =
{
    0,          /* string id */
    0,    /*default text string id*/
    STR_ID_MEDPLY_PROFILE_NAME,              /* title string id */
    0,         /* title icon id */
    IMM_INPUT_TYPE_SENTENCE,   /* input extended type */
    IMM_INPUT_TYPE_SENTENCE,         /* input type */
    MMI_MEDPLY_MAX_PROFILE_NAME_LEN + 1,        /* string count */
    NULL
};

/* data account */
static const cui_inline_item_caption_struct settings_profile_inline_caption_data_account = 
{
    STR_GLOBAL_DATA_ACCOUNT
};
/* use proxy */
static const cui_inline_item_caption_struct settings_profile_inline_caption_use_proxy = 
{
    STR_ID_MEDPLY_USER_PROXY
};
static const U16 settings_profile_use_proxys_item_str[] =
{
    STR_GLOBAL_OFF, 
    STR_GLOBAL_ON
};
static const cui_inline_item_select_struct settings_profile_inline_select_use_proxy = 
{
    2, 0, (U16 *)&settings_profile_use_proxys_item_str[0]
};

/* proxy server */
static const cui_inline_item_caption_struct settings_profile_inline_caption_proxy_server = 
{
    STR_ID_MEDPLY_PROXY_SERVER
};

static const cui_inline_item_fullscreen_edit_struct settings_profile_inline_fullscreen_edit_proxy_server =
{
    0,          /* string id */
    0,    /*default text string id*/
    STR_ID_MEDPLY_PROXY_SERVER,              /* title string id */
    0,         /* title icon id */
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL | INPUT_TYPE_EXT_ASCII_ENCODING_BASE_LENGTH,  /* input extended type */
    IMM_INPUT_TYPE_URL,         /* input type */
    MMI_MEDPLY_MAX_PROXY_ADDR_LEN + 1,        /* string count */
    NULL
};

/* proxy port */
static const cui_inline_item_caption_struct settings_profile_inline_caption_proxy_port = 
{
    STR_ID_MEDPLY_PROXY_PORT
};
static const cui_inline_item_text_edit_struct settings_profile_inline_text_edit_proxy_port =
{
    0,  /* string id */
    0,    /*default text string id*/
    MMI_MEDPLY_MAX_PORT_LEN,    /* string count */
    IMM_INPUT_TYPE_NUMERIC, /* input type */
    IMM_INPUT_TYPE_NUMERIC,    /* input extended type */
    NULL   /* required input mode */
};
/* lowest udp */
static const cui_inline_item_caption_struct settings_profile_inline_caption_lowest_udp = 
{
    STR_ID_MEDPLY_LOWEST_UDP_PORT
};
static const cui_inline_item_text_edit_struct settings_profile_inline_text_edit_lowest_udp =
{
    0,  /* string id */
    0,    /*default text string id*/
    MMI_MEDPLY_MAX_PORT_LEN,    /* string count */
    IMM_INPUT_TYPE_NUMERIC, /* input type */
    IMM_INPUT_TYPE_NUMERIC,    /* input extended type */
    NULL   /* required input mode */
};
/* highest udp */
static const cui_inline_item_caption_struct settings_profile_inline_caption_highest_udp = 
{
    STR_ID_MEDPLY_HIGHEST_UDP_PORT
};
static const cui_inline_item_text_edit_struct settings_profile_inline_text_edit_highest_udp =
{
    0,  /* string id */
    0,    /*default text string id*/
    MMI_MEDPLY_MAX_PORT_LEN,    /* string count */
    IMM_INPUT_TYPE_NUMERIC, /* input type */
    IMM_INPUT_TYPE_NUMERIC,    /* input extended type */
    NULL   /* required input mode */
};



static const cui_inline_set_item_struct mmi_medply_settings_profile_inline_item[] = 
{
    {CUI_INLINE_ITEM_ID_BASE + PROFILE_NAME_TYPE_CAPTION,           CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,           0,      (void*)&settings_profile_inline_caption_profile_name},
    {CUI_INLINE_ITEM_ID_BASE + PROFILE_NAME_TYPE_FULLSCREEN_EDIT,   CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT | CUI_INLINE_ITEM_LEFT_JUSTIFY,   0,      (void*)&settings_profile_inline_fullscreen_edit_profile_name},
    {CUI_INLINE_ITEM_ID_BASE + DATA_ACCOUNT_TYPE_CAPTION,           CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,           0,      (void*)&settings_profile_inline_caption_data_account},
    {CUI_INLINE_ITEM_ID_BASE + DATA_ACCOUNT_TYPE_DISPLAY_ONLY,      CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_CENTER_JUSTIFY,      0,      NULL},
    {CUI_INLINE_ITEM_ID_BASE + USE_PROXY_TYPE_CAPTION,              CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,           0,      (void*)&settings_profile_inline_caption_use_proxy},
    {CUI_INLINE_ITEM_ID_BASE + USE_PROXY_TYPE_SELECT,               CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,            0,      (void*)&settings_profile_inline_select_use_proxy},
    {CUI_INLINE_ITEM_ID_BASE + PROXY_SERVER_TYPE_CAPTION,           CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,           0,      (void*)&settings_profile_inline_caption_proxy_server},
    {CUI_INLINE_ITEM_ID_BASE + PROXY_SERVER_TYPE_FULLSCREEN_EDIT,   CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT | CUI_INLINE_ITEM_LEFT_JUSTIFY,   0,      (void*)&settings_profile_inline_fullscreen_edit_proxy_server},
    {CUI_INLINE_ITEM_ID_BASE + PROXY_PORT_TYPE_CAPTION,             CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,           0,      (void*)&settings_profile_inline_caption_proxy_port},
    {CUI_INLINE_ITEM_ID_BASE + PROXY_PORT_TYPE_TEXT_EDIT,           CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_LEFT_JUSTIFY,         0,      (void*)&settings_profile_inline_text_edit_proxy_port},
    {CUI_INLINE_ITEM_ID_BASE + LOWEST_UDP_TYPE_CAPTION,             CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,           0,      (void*)&settings_profile_inline_caption_lowest_udp},
    {CUI_INLINE_ITEM_ID_BASE + LOWEST_UDP_TYPE_TEXT_EDIT,           CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_LEFT_JUSTIFY,         0,      (void*)&settings_profile_inline_text_edit_lowest_udp},
    {CUI_INLINE_ITEM_ID_BASE + HIGHEST_UDP_TYPE_CAPTION,            CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,           0,      (void*)&settings_profile_inline_caption_highest_udp},
    {CUI_INLINE_ITEM_ID_BASE + HIGHST_UDP_TYPE_TEXT_EDIT,           CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_LEFT_JUSTIFY,         0,      (void*)&settings_profile_inline_text_edit_highest_udp}
};


static const cui_inline_struct mmi_medply_settings_profile_inline_screen = 
{
    MEDPLY_SETTINGS_PROFILE_INLINE_ITEM_NUM,
    STR_GLOBAL_EDIT,
    0,
    CUI_INLINE_SCREEN_LOOP, 
    NULL,
    mmi_medply_settings_profile_inline_item 
};
#endif

//reserved
//static U16 g_mmi_medply_settings_hilite_item_id = 0;
/***************************************************************************** 
 * Extern function
 *****************************************************************************/
void mmi_medply_settings_highlight(void);

static void mmi_medply_settings_entry_player(void);
static void mmi_medply_settings_entry_audio(void);
#if defined(__MMI_MEDIA_PLAYER_VIDEO_PROCESSING_SUPPORT__)  || defined(__MMI_MEDIA_PLAYER_VIDEO_SPEED__) || defined(MMI_MEDPLY_SETTINGS_VIDEO_3D_SUPPORT)  
static void mmi_medply_settings_entry_video(void);
static S32 mmi_medply_settings_get_video_speed_index(U16 speed);
#endif
#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
static void mmi_medply_settings_subtitle_iso_hilite_hdlr(S32 index);
/* MAUI_03158737 - To make saving the settings consistent - display no confirm, This fxn is not needed anymore */
#if 0
/* under construction !*/
#endif
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) 
static void mmi_medply_settings_subtitle_iso_tap_callback(mmi_tap_type_enum tap_type,S32 index);
#endif
static MMI_BOOL mmi_medply_settings_subtitle_is_same_iso_with_active(U32 iso);
static void mmi_medply_settings_entry_subtitle_iso_srn(void);
#endif

#if defined(__MMI_MEDIA_PLAYER_STREAM__)
static MMI_BOOL mmi_medply_settings_set_data_account(U32 data_account);
static void mmi_medply_settings_pre_entry_network(void);
static void mmi_medply_settings_entry_network(void);
static void mmi_medply_settings_entry_edit_profile(void);
static void mmi_medply_settings_entry_data_accout_cui(void);
//static void mmi_medply_settings_after_check_network(void);
static void mmi_medply_settings_network_active_profile(void);
static void mmi_medply_settings_profile_edit_set_item_value(MMI_ID inline_id);
static MMI_BOOL mmi_medply_settings_network_profile_is_changed(void);
static void mmi_medply_settings_profile_save(void);
static srv_dtcnt_sim_type_enum mmi_medply_settings_get_data_account_sim_type(void);

#endif

#if !defined (__MMI_MEDIA_PLAYER_FTE__) && !defined(__MMI_FTE_SUPPORT__)
#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
static void mmi_medply_settings_entry_skin_select_option(void);
#endif
#endif

static void mmi_medply_settings_skin_view(void);
#if (!defined (__MMI_MEDIA_PLAYER_FTE__) && !defined(__MMI_FTE_SUPPORT__)) || defined (__MMI_EDITABLE_AUDIO_EQUALIZER__)
static void mmi_medply_settings_done(void);
#endif
#if defined(__MMI_MEDIA_PLAYER_VDOREC__)
void mmi_medply_entry_video_recoder(void);
void mmi_medply_highlight_video_recoder(void);
#endif
static void mmi_medply_settings_no_save(void);
//static void mmi_medply_settings_entry_skin_change(void);
#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
static void mmi_medply_settings_inline_set_audio_effect2(MMI_ID inline_id);
#endif
static void mmi_medply_settings_skin_select_config(cui_menu_event_struct *menu_evt);
static mmi_ret mmi_medply_settings_proc(mmi_event_struct *evt);
static void mmi_medlpy_settings_fmgr_file_selector_handle(cui_file_selector_result_event_struct *file_select);
#if !defined (__MMI_MEDIA_PLAYER_FTE__) && !defined(__MMI_FTE_SUPPORT__)
#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
static void mmi_medply_settings_entry_skin_select_file(void);
static void mmi_medply_settings_select_theme(void);
static void mmi_medply_settings_inline_set_skin(MMI_ID inline_id);

#endif
#endif

static void mmi_medply_settings_fmgr_select_result_callback(void * filepath, int is_short);

static void mmi_medply_settings_player_set_item_value(MMI_ID inline_id);
#if defined(__MMI_MEDIA_PLAYER_VIDEO_PROCESSING_SUPPORT__)  || defined(__MMI_MEDIA_PLAYER_VIDEO_SPEED__)  || defined(MMI_MEDPLY_SETTINGS_VIDEO_3D_SUPPORT)
static void mmi_medply_settings_video_set_item_value(MMI_ID inline_id);
#endif
static void mmi_medply_settings_audio_set_item_value(MMI_ID inline_id);
static MMI_BOOL mmi_medply_settings_player_is_changed(void);
#if (defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)) && defined(__MMI_EDITABLE_AUDIO_EQUALIZER__)
static void mmi_medply_settings_entry_audio_equalizer_setting_options(void);
static void mmi_medply_settings_entry_audio_equalizer_setting_edit(void);
static void mmi_medply_settings_entry_audio_equalizer_setting_rename(void);
static void mmi_medply_settings_audio_equalizer_restore_factory_default_confirm_yes(void);
static void mmi_medply_settings_audio_equalizer_restore_factory_default_confirm(void);
#endif
static void mmi_medply_settings_go_back_to_main(void);
#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
static void mmi_medply_settings_sound_effect_confirm_done(void);
#endif
static S32 mmi_medply_settings_get_audio_speed_index(U16 speed);
#ifdef  __MMI_MEDIA_PLAYER_AUDIO__
#ifdef __MMI_AUDIO_TIME_STRETCH__
static MMI_BOOL  mmi_medply_settings_apply_speed_changed_in_setting(void);
#endif
#endif

/***************************************************************************** 
* Local Function
*****************************************************************************/
#define __SETTINGS_MAIN__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_highlight
 * DESCRIPTION
 *  main settings highlight
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_settings_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_medply_settings_entry_main, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

#if (!defined (__MMI_MEDIA_PLAYER_FTE__) && !defined(__MMI_FTE_SUPPORT__)) || defined (__MMI_EDITABLE_AUDIO_EQUALIZER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_confirm(MMI_ID parent_id, WCHAR* string, mmi_medply_settings_alert_enum user_tag, mmi_confirm_type_enum type, MMI_BOOL no_csk_icon, mmi_event_notify_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct property;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&property, type);
    property.parent_id = parent_id;
    property.user_tag = (void*)user_tag;
    if (no_csk_icon)
    {
        property.f_auto_map_empty_softkey = 0;
    }
    mmi_confirm_display(string, event_type, &property);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_kuro_popup_with_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_popup_with_string(MMI_ID parent_gid, WCHAR* string, mmi_event_notify_enum event_id, mmi_proc_func callback, void* user_tag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID grp_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(parent_gid))
    {
        grp_id = parent_gid;
    }
    else
    {
        grp_id = GRP_ID_ROOT;
    }

    
    if (callback)
    {
        mmi_popup_property_struct arg;   
        
        mmi_popup_property_init(&arg);              
        arg.callback = callback;       
        arg.user_tag = (void*)user_tag;          
        arg.parent_id = grp_id;   
        
        mmi_popup_display(                          
            string,                                
            event_id,                                   
            &arg);                                      
    }
    else
    {
        mmi_popup_display_simple(                   
            string,                                
            event_id,                                   
            grp_id,                                 
            user_tag);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_kuro_popup_simple_with_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_popup_simple_with_string(WCHAR* string, mmi_event_notify_enum event_id)
{
    mmi_medply_settings_popup_with_string(g_gid_medply, string, event_id, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_save
 * DESCRIPTION
 *  save the settings changed    
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* player settings save */
    if (mmi_frm_group_is_present (GRP_ID_MEDPLY_SETTINGS_PLAYER))
    {
        g_mmi_medply_settings.is_theme_default = g_mmi_medply_settings_player.skin_select_id;
        g_mmi_medply_settings.is_bgplay = (U8)g_mmi_medply_settings_player.bg_play_id;
        if (g_mmi_medply_settings.is_shuffle != g_mmi_medply_settings_player.shuffle_play_id)
        {
            mmi_medply_shuffle_change_callback((U8)g_mmi_medply_settings_player.shuffle_play_id);
            g_mmi_medply_settings.is_shuffle = (U8)g_mmi_medply_settings_player.shuffle_play_id;
         #ifdef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
            mmi_medply_settings_shuff_change(g_mmi_medply_settings.is_shuffle);
         #endif
        }
        else
        {
            g_mmi_medply_settings.is_shuffle = (U8)g_mmi_medply_settings_player.shuffle_play_id;
        }
        if(g_mmi_medply_settings.repeat != g_mmi_medply_settings_player.repeat_play_id)
        {
            g_mmi_medply_settings.repeat = (U8)g_mmi_medply_settings_player.repeat_play_id;
         #ifdef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
            mmi_medply_settings_repeat_change(g_mmi_medply_settings.repeat);
         #endif
        }
        else
        {
            g_mmi_medply_settings.repeat = (U8)g_mmi_medply_settings_player.repeat_play_id;
        }
    #ifdef MOTION_SENSOR_SUPPORT
        g_mmi_medply_settings.is_autofulscr_by_sensor = g_mmi_medply_settings_player.is_autofulscr_bysensor;
    #endif  
        if (g_mmi_medply_settings.is_theme_default == MMI_MEDPLY_SKIN_DEFAULT)
        {
            g_skin_custom_path[0] = '\0';
            g_skin_custom_path[1] = '\0';
        }
        mmi_ucs2cpy((CHAR*)g_mmi_medply_settings.skin_custom_path, (CHAR*)g_skin_custom_path);
        
        if (mmi_ucs2strlen((CHAR*)g_mmi_medply_settings.skin_custom_path) == 0)
        {
            g_mmi_medply_settings.is_theme_default = 0;     
        }
        
        #if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
            #if defined(__MMI_AUDIO_EQUALIZER__) && defined(__MMI_EDITABLE_AUDIO_EQUALIZER__)
                g_mmi_medply_settings_player.is_restored_save = MMI_TRUE;
                mmi_settings_audio_eq_write_to_nvram();
            #endif 
            mmi_medply_settings_sound_effect_confirm_done();
            return;
        #endif
    }

#ifdef  __MMI_MEDIA_PLAYER_AUDIO__
    /* audio player settings save */
    if (mmi_frm_group_is_present (GRP_ID_MEDPLY_SETTINGS_AUDIO))
    {
    #ifdef __MMI_AUDIO_TIME_STRETCH__
        if (mmi_medply_settings_apply_speed_changed_in_setting() == MMI_FALSE)
        {
            mmi_medply_settings_popup_simple_with_string(
                (U16*)get_string(STR_ID_MEDPLY_ERR_NOT_SUPPORTED_SPEED), 
                MMI_EVENT_ERROR);
            return;
        }
    #endif
        g_mmi_medply_settings.mainscrdisp_index = g_mmi_medply_settings_audio.mainscr_disp_id;
    }
#endif /* __MMI_MEDIA_PLAYER_AUDIO__ */

#ifdef __MMI_MEDIA_PLAYER_VIDEO__
#if defined(__MMI_MEDIA_PLAYER_VIDEO_PROCESSING_SUPPORT__)  || defined(__MMI_MEDIA_PLAYER_VIDEO_SPEED__) || defined(MMI_MEDPLY_SETTINGS_VIDEO_3D_SUPPORT) 
    /* video player settings save */
    if (mmi_frm_group_is_present (GRP_ID_MEDPLY_SETTINGS_VIDEO))
    {
        g_mmi_medply_settings.brightness = g_mmi_medply_settings_video.video_brightness_id;
        g_mmi_medply_settings.contrast = g_mmi_medply_settings_video.video_contrast_id;	
    #ifdef __MMI_AUDIO_TIME_STRETCH__
        if (g_mmi_medply_settings.video_speed != g_mmi_medply_settings_video.video_speed_value)
        {
            g_mmi_medply_settings.video_speed = g_mmi_medply_settings_video.video_speed_value;
        }
    #endif
    #if defined(MMI_MEDPLY_SETTINGS_VIDEO_3D_SUPPORT) 
	    g_mmi_medply_settings.play_mode = g_mmi_medply_settings_video.video_play_mode;
    #endif
    }
#endif    
#endif /*  __MMI_MEDIA_PLAYER_VIDEO__ */

#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    g_mmi_medply_settings_subtitle.iso_active = g_mmi_medply_settings_subtitle.iso_list[g_mmi_medply_settings_subtitle.cur_sel_index];
    g_mmi_medply_settings_subtitle.track_index_active = g_mmi_medply_settings_subtitle.track_index_list[g_mmi_medply_settings_subtitle.cur_sel_index];
    g_mmi_medply_settings.subtitle_iso = g_mmi_medply_settings_subtitle.iso_active;
    g_mmi_medply_settings_subtitle.has_inited = MMI_TRUE;
#endif
    g_mmi_medply_settings_player.is_restored_save = MMI_TRUE;
    WriteRecord(NVRAM_EF_MEDPLY_SETTINGS_LID,1,(void*)&g_mmi_medply_settings,NVRAM_EF_MEDPLY_SETTINGS_SIZE, &pError);
/*bql: apply new UE design to avoid success popup */
#if 1
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    /* delete the screen and go back to GRP_ID_MEDPLY_SETTINGS_MAIN */
    mmi_medply_settings_go_back_to_main();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_pre_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_pre_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MEDIA_PLAYER_STREAM__) 
    if (mmi_frm_group_is_present(GRP_ID_MEDPLY_PROFILE_EDIT))
    {
        mmi_medply_settings_profile_save();
    }
    else
#endif /* defined(__MMI_MEDIA_PLAYER_STREAM__) */
    {
        mmi_medply_settings_save();
    }


}

#if defined(__MMI_MEDIA_PLAYER_STREAM__) 
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_profile_save
 * DESCRIPTION
 *  save the network settings changed    
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_profile_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 port;
    S32 highest_port;
    S32 lowest_port;
    S16 pError;
    U8 index;
    MMI_ID inline_gid = GRP_ID_INVALID;
    nvram_ef_medply_settings_profile_struct *profile_p;
    CHAR inline_profile_name[MMI_MEDPLY_MAX_PROFILE_NAME_BUF_SIZE]; 
    U8 inline_proxy_port[(MMI_MEDPLY_MAX_PORT_LEN)*ENCODING_LENGTH];
    U8 inline_highest_udp_port[(MMI_MEDPLY_MAX_PORT_LEN)*ENCODING_LENGTH];
    U8 inline_lowest_udp_port[(MMI_MEDPLY_MAX_PORT_LEN)*ENCODING_LENGTH];
    CHAR inline_proxy_addr[MMI_MEDPLY_MAX_PROXY_ADDR_BUF_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_gid = g_mmi_medply_settings_network_profile.inline_gid;
    
    /* check the data valid */
    cui_inline_get_value(inline_gid, CUI_INLINE_ITEM_ID_BASE + PROXY_PORT_TYPE_TEXT_EDIT, (void *) inline_proxy_port);

    port = gui_atoi((UI_string_type)&inline_proxy_port);
    if ((port >65535) ||(g_mmi_medply_settings_network_profile.inline_proxy_on_off && !port))
    {
        mmi_medply_settings_popup_simple_with_string(
            (U16*)get_string(STR_ID_MEDPLY_ERROR_VALID_PROXY), 
            MMI_EVENT_ERROR);
        return;
    }

    cui_inline_get_value(inline_gid, CUI_INLINE_ITEM_ID_BASE + PROXY_SERVER_TYPE_FULLSCREEN_EDIT, (void *) &inline_proxy_addr);
    if (g_mmi_medply_settings_network_profile.inline_proxy_on_off && inline_proxy_addr[0] =='\0' && inline_proxy_addr[1]=='\0')
    {
        mmi_medply_settings_popup_simple_with_string(
            (U16*)get_string(STR_ID_MEDPLY_ERROR_INVALID_PORT_ADDERSS), 
            MMI_EVENT_ERROR);
        return;
    }
    
    cui_inline_get_value(inline_gid, CUI_INLINE_ITEM_ID_BASE + LOWEST_UDP_TYPE_TEXT_EDIT, (void *) inline_lowest_udp_port);
    lowest_port = gui_atoi((UI_string_type)&inline_lowest_udp_port);
    if ((lowest_port < 6000) || (lowest_port > 65532))
    {
        mmi_medply_settings_popup_simple_with_string(
            (U16*)get_string(STR_ID_MEDPLY_ERROR_VALID_LOWEST_UDP), 
            MMI_EVENT_ERROR);
        return;
    }

    cui_inline_get_value(inline_gid, CUI_INLINE_ITEM_ID_BASE + HIGHST_UDP_TYPE_TEXT_EDIT, (void *) inline_highest_udp_port);
    highest_port = gui_atoi((UI_string_type)&inline_highest_udp_port);
    if ((highest_port < 6003) || (highest_port > 65535))
    {
        mmi_medply_settings_popup_simple_with_string(
            (U16*)get_string(STR_ID_MEDPLY_ERROR_VALID_HIGHEST_UDP), 
            MMI_EVENT_ERROR);
        return;
    }

    if ((highest_port - lowest_port) < 3 || 
        ((highest_port - lowest_port) == 3 && lowest_port % 2))
    {
        mmi_medply_settings_popup_simple_with_string(
            (U16*)get_string(STR_ID_MEDPLY_ERROR_VALID_UDP_PORT), 
            MMI_EVENT_ERROR);
        return;
    }

    /* save the updated data */
    index = g_mmi_medply_settings_network_profile.cur_sel_profile_idx;
    profile_p = &g_mmi_medply_settings_network_profile.network_profile[index];

    cui_inline_get_value(inline_gid, CUI_INLINE_ITEM_ID_BASE + PROFILE_NAME_TYPE_FULLSCREEN_EDIT, (void *) inline_profile_name);
    
    if (mmi_ucs2strlen((CHAR*)profile_p->profile_name) != 0  &&
        mmi_ucs2cmp((CHAR*) profile_p->profile_name, (CHAR*)inline_profile_name))
    {
        /* CCA RULE:  if change profile name, we shouldn't update profile, so clear provurl here */
        memset((CHAR*)&profile_p->provurl, 0, sizeof(profile_p->provurl));
    }
    mmi_ucs2cpy((CHAR*)profile_p->profile_name,(CHAR*)inline_profile_name);
    if (mmi_ucs2strlen((CHAR*)profile_p->profile_name) == 0
        || !mmi_ucs2cmp((CHAR*) profile_p->profile_name, (CHAR*)GetString((U16)STR_ID_MEDPLY_SETTINGS_PROFILE1 + index)))
    {
        mmi_ucs2cpy((CHAR*)profile_p->profile_name, (CHAR*) L"");
    }
    
    for (i = 0; i < MMI_MAX_SIM_NUM; i++)
    {
        profile_p->data_account_id[i] = g_mmi_medply_settings_network_profile.inline_data_account_id[i];
    }

    profile_p->proxy_on_off = g_mmi_medply_settings_network_profile.inline_proxy_on_off;
    profile_p->highest_udp_port = gui_atoi((UI_string_type)&inline_highest_udp_port);
    profile_p->lowest_udp_port = gui_atoi((UI_string_type)&inline_lowest_udp_port);
    profile_p->proxy_port = gui_atoi((UI_string_type)&inline_proxy_port);
    mmi_ucs2_to_asc(profile_p->proxy_addr, inline_proxy_addr);
    
    for(i = 0; i < NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_TOTAL; i++)
    {
        WriteRecord(NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_LID,
            i + 1,
            (void*)&(g_mmi_medply_settings_network_profile.network_profile[i]),
            NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_SIZE,
            &pError);
    }
/*bql: apply new UE design to avoid success popup */
#if 1
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    mmi_frm_group_close(GRP_ID_MEDPLY_PROFILE_EDIT);
}
#endif /* defined(__MMI_MEDIA_PLAYER_STREAM__)  */


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_no_save
 * DESCRIPTION
 *  not save settings changed    
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_no_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
    #ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
    U16 i= 0;
    U16 j = 0;
    #endif
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* player settings */
    if (mmi_frm_group_is_present(GRP_ID_MEDPLY_SETTINGS_PLAYER))
        {
    g_mmi_medply_settings_player.skin_select_id = g_mmi_medply_settings.is_theme_default;
    g_mmi_medply_settings_player.bg_play_id = g_mmi_medply_settings.is_bgplay;
    
    mmi_ucs2cpy((CHAR*)g_skin_custom_path,(CHAR*)g_mmi_medply_settings.skin_custom_path);
#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
    g_settings_current_audio_effect = g_settings_selected_audio_effect;
    #ifdef __MMI_AUDIO_EQUALIZER__
        current_audio_equalizer_index = (U16)g_settings_audio_equalizer.index;
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        current_audio_reverb_index = g_mmi_aud_3d_cntx.reverb_index;
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        current_audio_surround_index = g_mmi_aud_3d_cntx.surround_index;
    #endif
    #ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
        for( i = 0; i < MAX_EQUALIZER_NUM ; i++)
        {
            for (j = 0; j < NUM_OF_BARS_IN_A_SETTING; j++)
            {
                g_settings_audio_equalizer.magnitude[i][j] = g_settings_audio_equalizer_temp.magnitude[i][j]; 
            }
                mmi_ucs2cpy((CHAR*)g_settings_audio_equalizer.setting_name[i], (CHAR*) g_settings_audio_equalizer_temp.setting_name[i]);
        }
        g_settings_audio_equalizer.index = g_settings_audio_equalizer_temp.index;
        g_settings_eq_rename_flag = g_settings_eq_rename_flag_temp;
        
        mmi_settings_audio_eq_write_to_nvram();
        mdi_audio_eq_set_magnitude((CHAR*)g_settings_audio_equalizer.magnitude[g_settings_audio_equalizer.index]);
    #endif
#endif /*__MMI_AUDIO_EQUALIZER__ || __MMI_AUDIO_REVERB_EFFECT__ || __MMI_AUDIO_SURROUND_EFFECT__*/
        }
#ifdef __MMI_MEDIA_PLAYER_AUDIO__
        else if (mmi_frm_group_is_present(GRP_ID_MEDPLY_SETTINGS_AUDIO))
            {
    /* audio settings */
    g_mmi_medply_settings_audio.audio_speed_id = mmi_medply_settings_get_audio_speed_index(g_mmi_medply_settings.audio_speed);
    g_mmi_medply_settings_audio.mainscr_disp_id = g_mmi_medply_settings.mainscrdisp_index;
        }
#endif /* __MMI_MEDIA_PLAYER_AUDIO__ */

#ifdef __MMI_MEDIA_PLAYER_VIDEO__
        else if (mmi_frm_group_is_present(GRP_ID_MEDPLY_SETTINGS_VIDEO))
            {
#if defined(__MMI_MEDIA_PLAYER_VIDEO_PROCESSING_SUPPORT__)  || defined(__MMI_MEDIA_PLAYER_VIDEO_SPEED__)  || defined(MMI_MEDPLY_SETTINGS_VIDEO_3D_SUPPORT)
    /* video settings */
    g_mmi_medply_settings_video.video_brightness_id = g_mmi_medply_settings.brightness;
    g_mmi_medply_settings_video.video_contrast_id = g_mmi_medply_settings.contrast;
    g_mmi_medply_settings_video.video_speed_id = mmi_medply_settings_get_video_speed_index(g_mmi_medply_settings.video_speed);
    g_mmi_medply_settings_video.video_play_mode = g_mmi_medply_settings.play_mode;
#endif
            }
#endif /* __MMI_MEDIA_PLAYER_VIDEO__ */

#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    //g_mmi_medply_settings_subtitle.track_index_active = g_mmi_medply_settings_subtitle.old_track_index;
    //g_mmi_medply_settings_subtitle.iso_active = g_mmi_medply_settings.subtitle_iso;
#endif

    if (g_mmi_medply_settings_player.is_restored_save)
    {
        mmi_medply_settings_go_back_to_main();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_pre_no_save
 * DESCRIPTION
 *  pre_no_save    
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_pre_no_save(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_medply_settings_player.is_restored_save = MMI_TRUE; 
    mmi_medply_settings_no_save();
}


#if (!defined (__MMI_MEDIA_PLAYER_FTE__) && !defined(__MMI_FTE_SUPPORT__)) || defined (__MMI_EDITABLE_AUDIO_EQUALIZER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_done
 * DESCRIPTION
 *  settings save confirm    
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_settings_confirm(GRP_ID_MEDPLY_SETTINGS_MAIN,
        (WCHAR *)get_string(STR_GLOBAL_SAVE_ASK),
        MMI_MEDPLY_SETTINGS_COMFIRM_SAVE,
        CNFM_TYPE_YESNO,
        MMI_FALSE,
        MMI_EVENT_QUERY);     
}
#endif
    

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_entry_main_scr
 * DESCRIPTION
 *  entry settings main  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_settings_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_gid = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(g_gid_medply, GRP_ID_MEDPLY_SETTINGS_MAIN, mmi_medply_settings_proc, (void*)NULL); 
    
    mmi_frm_group_enter(GRP_ID_MEDPLY_SETTINGS_MAIN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    cui_gid = cui_menu_create(
                            GRP_ID_MEDPLY_SETTINGS_MAIN,
                            CUI_MENU_SRC_TYPE_RESOURCE,
                            CUI_MENU_TYPE_APPSUB,
                            MENU_ID_MEDPLY_SETTINGS,
                            MMI_FALSE, NULL);
    if (cui_gid > GRP_ID_INVALID)
    {
        cui_menu_set_default_title_image(cui_gid, (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)));
        cui_menu_run(cui_gid);
    }
    else
    {   
        mmi_medply_settings_popup_simple_with_string((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_inline_set_item_value
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_inline_set_item_value(cui_event_inline_common_struct *inline_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_MEDPLY_SETTINGS_PLAYER))
    {
        mmi_medply_settings_player_set_item_value(inline_evt->sender_id);
        if (mmi_medply_settings_player_is_changed())
        {
            cui_inline_set_screen_attributes(inline_evt->sender_id, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_SCREEN_CHANGED);
        }
    }
#ifdef __MMI_MEDIA_PLAYER_AUDIO__
    else if (mmi_frm_group_is_present(GRP_ID_MEDPLY_SETTINGS_AUDIO))
    {
        mmi_medply_settings_audio_set_item_value(inline_evt->sender_id);
    }
#endif /*__MMI_MEDIA_PLAYER_AUDIO__*/    
#ifdef __MMI_MEDIA_PLAYER_VIDEO__
#if defined(__MMI_MEDIA_PLAYER_VIDEO_PROCESSING_SUPPORT__)  || defined(__MMI_MEDIA_PLAYER_VIDEO_SPEED__) || defined(MMI_MEDPLY_SETTINGS_VIDEO_3D_SUPPORT) 
    else if (mmi_frm_group_is_present(GRP_ID_MEDPLY_SETTINGS_VIDEO))
    {
        mmi_medply_settings_video_set_item_value(inline_evt->sender_id);
    }
#endif
#endif /*__MMI_MEDIA_PLAYER_VIDEO__*/    
#if defined(__MMI_MEDIA_PLAYER_STREAM__)
    else if (mmi_frm_group_is_present(GRP_ID_MEDPLY_PROFILE_EDIT))
    {
        mmi_medply_settings_profile_edit_set_item_value(inline_evt->sender_id);
        if (mmi_medply_settings_network_profile_is_changed())
        {
            cui_inline_set_screen_attributes(inline_evt->sender_id, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_SCREEN_CHANGED);
        }
    }
#endif /*__MMI_MEDIA_PLAYER_STREAM__ */

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_inline_highlight_change
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_inline_highlight_change(cui_event_inline_notify_struct *inline_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S32 item = inline_evt->item_id - CUI_INLINE_ITEM_ID_BASE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //reserved
    //g_mmi_medply_settings_hilite_item_id = item;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_inline_focus_change
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_inline_focus_change(cui_event_inline_notify_struct *inline_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 item = inline_evt->item_id - CUI_INLINE_ITEM_ID_BASE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (mmi_frm_group_is_present(GRP_ID_MEDPLY_SETTINGS_PLAYER))
    {
        switch (item)
        {
        case SHUFFLE_TYPE_SELECT:
            {
                g_mmi_medply_settings_player.shuffle_play_id = inline_evt->param;
            }
            break;
        case REPEAT_TYPE_SELECT:
            {
                g_mmi_medply_settings_player.repeat_play_id = inline_evt->param;
            }
            break;
#ifdef MOTION_SENSOR_SUPPORT
        case MOTION_TYPE_SELECT:
            {
                g_mmi_medply_settings_player.is_autofulscr_bysensor = inline_evt->param;
            }
            break;
#endif /* MOTION_SENSOR_SUPPORT */
#if !defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__)   
        case BACKGROUND_TYPE_SELECT:
            {
                g_mmi_medply_settings_player.bg_play_id = inline_evt->param;
            }
            break;
#endif /* !__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__ */
#if defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
        case SOUND_TYPE_SELECT1:
            {
                if (g_settings_current_audio_effect_prev == inline_evt->param)
                {       
                    break ;
                }
                else
                {
                    g_settings_current_audio_effect_prev = inline_evt->param;
                    g_settings_current_audio_effect = inline_evt->param;
                }
                switch(g_settings_current_audio_effect)
                {
                    case SETTINGS_SOUND_EFFECTS_NONE:
                        break;
                        
            #ifdef __MMI_AUDIO_EQUALIZER__
                    case SETTINGS_SOUND_EFFECTS_EQ:
                    {
                        g_settings_current_effect_index = current_audio_equalizer_index ;
                        break;
                    }
            #endif
                        
            #ifdef __MMI_AUDIO_REVERB_EFFECT__
                    case SETTINGS_SOUND_EFFECTS_REVERB:
                    {
                        g_settings_current_effect_index = current_audio_reverb_index ;
                        break;
                    }
            #endif
                                                    
            #ifdef __MMI_AUDIO_SURROUND_EFFECT__
                    case SETTINGS_SOUND_EFFECTS_SURROUND:
                    {
                        g_settings_current_effect_index = current_audio_surround_index ;
                        break;
                    }
            #endif
                    default:
                        break;
                }
                cui_inline_redraw_screen(inline_evt->sender_id);
            }
            break;
        case SOUND_TYPE_SELECT2:
            {
                if(g_settings_current_audio_effect != SETTINGS_SOUND_EFFECTS_NONE)
                {
                    U16 index = (U16)inline_evt->param;
                    
                    switch (g_settings_current_audio_effect)
                    {
            #ifdef __MMI_AUDIO_EQUALIZER__
                        case SETTINGS_SOUND_EFFECTS_EQ :
                            current_audio_equalizer_index = index; 
                            break;
            #endif
            #ifdef __MMI_AUDIO_REVERB_EFFECT__
                        case SETTINGS_SOUND_EFFECTS_REVERB :
                            current_audio_reverb_index = index ;
                            break;
            #endif
            #ifdef __MMI_AUDIO_SURROUND_EFFECT__
                        case SETTINGS_SOUND_EFFECTS_SURROUND :
                            current_audio_surround_index = index ;
                            break;
            #endif
                        default :
                            break;
                    }
                }
            }
            break;
#endif /* defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)*/
#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
        case BASS_TYPE_SELECT:
            {
                g_settings_selected_bass_enhancement = inline_evt->param;
            }
            break;
#endif /* __MMI_AUDIO_BASS_ENHANCEMENT__ */
        }
    }
#ifdef __MMI_MEDIA_PLAYER_AUDIO__
    else if (mmi_frm_group_is_present(GRP_ID_MEDPLY_SETTINGS_AUDIO))
    {
        switch (item)
        {
#ifdef __MMI_AUDIO_TIME_STRETCH__
            case AUDIO_SPEED_TYPE_SELECT:
            {
                g_mmi_medply_settings_audio.audio_speed_id = inline_evt->param;
                switch (inline_evt->param)
                {
                    case 0:
                        g_mmi_medply_settings_audio.audio_speed_value = MDI_AUDIO_SPEED_SLOW2;
                        break;
                    case 1:
                        g_mmi_medply_settings_audio.audio_speed_value= MDI_AUDIO_SPEED_SLOW1;
                        break;
                    case 2:
                        g_mmi_medply_settings_audio.audio_speed_value= MDI_AUDIO_SPEED_NORMAL;
                        break;
                    case 3:
                        g_mmi_medply_settings_audio.audio_speed_value= MDI_AUDIO_SPEED_FAST1;
                        break;
                    case 4:
                        g_mmi_medply_settings_audio.audio_speed_value= MDI_AUDIO_SPEED_FAST2;
                        break;
                    default:
                        g_mmi_medply_settings_audio.audio_speed_value= MDI_AUDIO_SPEED_NORMAL;
                        break;
                }
                break;
            }
#endif /* __MMI_AUDIO_TIME_STRETCH__ */
            case AUDIO_DISPLAY_TYPE_SELECT:
            {
                g_mmi_medply_settings_audio.mainscr_disp_id = inline_evt->param;
                break;
            }
            default:
                break;
                
        }

    }
#endif /*__MMI_MEDIA_PLAYER_AUDIO__*/
#ifdef __MMI_MEDIA_PLAYER_VIDEO__
#if defined(__MMI_MEDIA_PLAYER_VIDEO_PROCESSING_SUPPORT__)  || defined(__MMI_MEDIA_PLAYER_VIDEO_SPEED__) || defined(MMI_MEDPLY_SETTINGS_VIDEO_3D_SUPPORT) 
    else if (mmi_frm_group_is_present(GRP_ID_MEDPLY_SETTINGS_VIDEO))
    {
        switch (item)
        {
        #if defined(__MMI_MEDIA_PLAYER_VIDEO_PROCESSING_SUPPORT__)  
            case VIDEO_BRIGHTNESS_TYPE_SELECT:
            {
               g_mmi_medply_settings_video.video_brightness_id = inline_evt->param;
                break;
            }
            case VIDEO_CONTRAST_TYPE_SELECT:
            {
                g_mmi_medply_settings_video.video_contrast_id = inline_evt->param;
                break;
            }
        #endif /*__MMI_MEDIA_PLAYER_VIDEO_PROCESSING_SUPPORT__ */

	#ifdef MMI_MEDPLY_SETTINGS_VIDEO_3D_SUPPORT
            case VIDEO_PLAY_MODE_TYPE_SELECT:
            {
                g_mmi_medply_settings_video.video_play_mode = inline_evt->param;
                break;
            }
	#endif

        #ifdef __MMI_MEDIA_PLAYER_VIDEO_SPEED__
            case VIDEO_SPEED_TYPE_SELECT:
            {
                g_mmi_medply_settings_video.video_speed_id = inline_evt->param;
                switch (inline_evt->param)
                {
                    case 0:
                        g_mmi_medply_settings_video.video_speed_value = MEDPLY_FEATURE_VIDEO_SPEED_0;
                        break;
                    case 1:
                        g_mmi_medply_settings_video.video_speed_value = MEDPLY_FEATURE_VIDEO_SPEED_1;
                        break;
                    case 2:
                        g_mmi_medply_settings_video.video_speed_value = MEDPLY_FEATURE_VIDEO_SPEED_2;
                        break;
                    case 3:
                        g_mmi_medply_settings_video.video_speed_value = MEDPLY_FEATURE_VIDEO_SPEED_3;
                        break;
                    case 4:
                        g_mmi_medply_settings_video.video_speed_value = MEDPLY_FEATURE_VIDEO_SPEED_4;
                        break;
                    #ifdef __MMI_MEDIA_PLAYER_VIDEO_SPEED_EIGHT_MAPPING__
                    case 5:
                        g_mmi_medply_settings_video.video_speed_value = MEDPLY_FEATURE_VIDEO_SPEED_5;
                        break;
                    case 6:
                        g_mmi_medply_settings_video.video_speed_value = MEDPLY_FEATURE_VIDEO_SPEED_6;
                        break;
                    case 7:
                        g_mmi_medply_settings_video.video_speed_value = MEDPLY_FEATURE_VIDEO_SPEED_7;
                        break;
                    #endif
                    default:
                        g_mmi_medply_settings_video.video_speed_value = 100;
                        break;
                }
                break;
            }
        #endif /* __MMI_MEDIA_PLAYER_VIDEO_SPEED__ */
            default:
                break;
                
        }
        
    }
#endif
#endif /*__MMI_MEDIA_PLAYER_VIDEO__*/    
#if defined(__MMI_MEDIA_PLAYER_STREAM__) 
    else if (mmi_frm_group_is_present(GRP_ID_MEDPLY_PROFILE_EDIT))
    {
        switch (item)
        {
            case USE_PROXY_TYPE_SELECT:
            {
                g_mmi_medply_settings_network_profile.inline_proxy_on_off = inline_evt->param;
                break;
            }
            default:
                break;
                
        }
    }
#endif /*__MMI_MEDIA_PLAYER_STREAM__ */    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_go_back_to_main
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_go_back_to_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(GRP_ID_MEDPLY_SETTINGS_PLAYER);
#ifdef __MMI_MEDIA_PLAYER_AUDIO__
    mmi_frm_group_close(GRP_ID_MEDPLY_SETTINGS_AUDIO);
#endif /*__MMI_MEDIA_PLAYER_AUDIO__*/
#ifdef __MMI_MEDIA_PLAYER_VIDEO__
#if defined(__MMI_MEDIA_PLAYER_VIDEO_PROCESSING_SUPPORT__)  || defined(__MMI_MEDIA_PLAYER_VIDEO_SPEED__) || defined(MMI_MEDPLY_SETTINGS_VIDEO_3D_SUPPORT) 
    mmi_frm_group_close(GRP_ID_MEDPLY_SETTINGS_VIDEO);
#endif
#endif /*__MMI_MEDIA_PLAYER_VIDEO__*/
#if defined(__MMI_A2DP_SUPPORT__) && !defined(__MMI_A2DP_HIDE_BT_SETTINGS__) 
    //@TODO:close bt 
#endif
#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    mmi_frm_scrn_close(GRP_ID_MEDPLY_SETTINGS_MAIN, SCR_ID_MEDPLY_SETTINGS_SUBTITLE_ISO);
#endif
#if defined(__MMI_MEDIA_PLAYER_STREAM__) 
    mmi_frm_scrn_close(GRP_ID_MEDPLY_SETTINGS_MAIN, SCR_ID_MEDPLY_SETTINGS_NETWORK);
    mmi_frm_group_close(GRP_ID_MEDPLY_PROFILE_EDIT);
#endif /*__MMI_MEDIA_PLAYER_STREAM__ */    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_mainmenu_config
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_mainmenu_config(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_medply_check_if_no_network_link())
    {
#if defined(__MMI_MEDIA_PLAYER_STREAM__) 
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_SETTINGS_NETWORK, MMI_TRUE);
#endif
    }
    else
    {
#if defined(__MMI_MEDIA_PLAYER_STREAM__) 
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_SETTINGS_NETWORK, MMI_FALSE);
#endif
    }
    
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_SETTINGS_AUDIO, MMI_FALSE);
#if !defined(__MMI_AUDIO_TIME_STRETCH__) 
    if (MMI_MEDPLY_MAINSCR_DISP_ALL == 1)
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_SETTINGS_AUDIO, MMI_TRUE);
    }
#endif

#if defined(__MMI_A2DP_SUPPORT__) && !defined(__MMI_A2DP_HIDE_BT_SETTINGS__)
    if (!mmi_bt_is_to_display_bt_menu())
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_SETTINGS_BLUETOOTH, MMI_TRUE);
    }
#endif

    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS );
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_cui_hdlr_menu
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_medply_settings_cui_hdlr_menu(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
/*************************Menu CUI event***************************/
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
            if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_SETTINGS)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_MENU_CUI_ENTRY_SELECT,menu_evt->parent_menu_id ,__LINE__);
                mmi_medply_settings_mainmenu_config(menu_evt);
                break;
            }
            else if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_SELECT_FILE_OPTION)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_MENU_CUI_ENTRY_SELECT,menu_evt->parent_menu_id ,__LINE__);
                mmi_medply_settings_skin_select_config(menu_evt);
                break;
            }

            break;
        }
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;

            if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_SETTINGS)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_MENU_CUI_ENTRY_SELECT, menu_evt->parent_menu_id, menu_evt->highlighted_menu_id, 0, __LINE__);
                switch(menu_evt->highlighted_menu_id)
                {
                    case MENU_ID_MEDPLY_SETTINGS_PLAYER:
                        mmi_medply_settings_entry_player();
                       break;
                #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                    case MENU_ID_MEDPLY_SETTINGS_AUDIO:
                        mmi_medply_settings_entry_audio();
                        break;
                #endif
                #ifdef __MMI_MEDIA_PLAYER_VIDEO__
                    #if defined(__MMI_MEDIA_PLAYER_VIDEO_PROCESSING_SUPPORT__)  || defined(__MMI_MEDIA_PLAYER_VIDEO_SPEED__)  || defined(MMI_MEDPLY_SETTINGS_VIDEO_3D_SUPPORT)
                    case MENU_ID_MEDPLY_SETTINGS_VIDEO:
                        mmi_medply_settings_entry_video();
                        break;
                    #endif
                #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/
                #if defined(__MMI_A2DP_SUPPORT__) && !defined(__MMI_A2DP_HIDE_BT_SETTINGS__) 
                    case MENU_ID_MEDPLY_SETTINGS_BLUETOOTH:
                        mmi_a2dp_entry_bluetooth_settings();
                        break;
                #endif
                #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
                    case MENU_ID_MEDPLY_SETTINGS_SUBTITLE:
                        mmi_medply_settings_entry_subtitle_iso_srn();
                        break;
                #endif
                #if defined(__MMI_MEDIA_PLAYER_STREAM__) 
                    case MENU_ID_MEDPLY_SETTINGS_NETWORK:
                        mmi_medply_settings_pre_entry_network();
                        break;
                #endif
                    default:
                        break;
                }
            }
        #if !defined (__MMI_MEDIA_PLAYER_FTE__) && !defined(__MMI_FTE_SUPPORT__)
        #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
            else if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_SELECT_FILE_OPTION)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_MENU_CUI_ENTRY_SELECT, menu_evt->parent_menu_id, menu_evt->highlighted_menu_id, 0, __LINE__);
                switch(menu_evt->highlighted_menu_id)
                {
                    case MENU_ID_MEDPLY_VIEW_SKIN:
                        mmi_medply_settings_select_theme();
                        break;
                    case MENU_ID_MEDPLY_SELECT_FROM_FILE:
                        mmi_medply_settings_entry_skin_select_file();
                        break;
                    case MENU_ID_MEDPLY_SETTINGS_DONE:
                        mmi_medply_settings_done();
                        break;
                    default:
                        break;
                }
            }
        #endif
        #endif
        #if defined(__MMI_MEDIA_PLAYER_STREAM__) 
            else if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_SETTINGS_NETWORK_OPTION)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_MENU_CUI_ENTRY_SELECT, menu_evt->parent_menu_id, menu_evt->highlighted_menu_id, 0, __LINE__);
                switch(menu_evt->highlighted_menu_id)
                {
                    case MENU_ID_MEDPLY_SETTINGS_NETWORK_ACTIVE_PROFILE:
                        mmi_medply_settings_network_active_profile();
                        break;
                    case MENU_ID_MEDPLY_SETTINGS_NETWORK_EDIT_PROFILE:
                        mmi_medply_settings_entry_edit_profile();
                        break;
                    default:
                        break;
                }
            }
        #endif /*__MMI_MEDIA_PLAYER_STREAM__ */    
        #if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
        #ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
            else if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_SOUNDEFFECT_OPTION)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_MENU_CUI_ENTRY_SELECT, menu_evt->parent_menu_id, menu_evt->highlighted_menu_id, 0, __LINE__);
                switch(menu_evt->highlighted_menu_id)
                {
                    case MENU_ID_MEDPLY_SOUNDEFFECT_OPTION_SAVE:
                        mmi_medply_settings_done();
                        break;
                    case MENU_ID_MEDPLY_SOUNDEFFECT_OPTION_EDIT:
                        mmi_medply_settings_entry_audio_equalizer_setting_edit();
                        break;
                    case MENU_ID_MEDPLY_SOUNDEFFECT_OPTION_RENAME:
                        mmi_medply_settings_entry_audio_equalizer_setting_rename();
                        break;
                    case MENU_ID_MEDPLY_SOUNDEFFECT_OPTION_RESTORE:
                        mmi_medply_settings_audio_equalizer_restore_factory_default_confirm();
                        break;
                    default:
                        break;
                }
            }
        #endif /*__MMI_EDITABLE_AUDIO_EQUALIZER__*/
        #endif
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_MENU_CUI_WANING,evt->evt_id ,menu_evt->parent_menu_id,0, __LINE__);
            break;
        }
        case EVT_ID_CUI_MENU_LIST_EXIT:
        {

            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
            
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_MENU_CUI_CLOSE,menu_evt->sender_id ,__LINE__);
            cui_menu_close(menu_evt->sender_id);
            break;
        }

    }
    
    return MMI_RET_OK;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_cui_hdlr_inline
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_medply_settings_cui_hdlr_inline(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_NOTIFY:
        {
            cui_event_inline_notify_struct *inline_evt = (cui_event_inline_notify_struct *)evt;
            
            switch(inline_evt->event_type)
            {
                case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_NOTIFY,inline_evt->sender_id ,inline_evt->event_type ,__LINE__);
                    mmi_medply_settings_inline_highlight_change(inline_evt);
                    break;
                }
                case CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED:
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_NOTIFY,inline_evt->sender_id ,inline_evt->event_type ,__LINE__);
                    mmi_medply_settings_inline_focus_change(inline_evt);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        {
            cui_event_inline_common_struct *inline_evt = (cui_event_inline_common_struct *)evt;
            
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_ACTIVE,inline_evt->sender_id ,__LINE__);
            mmi_medply_settings_inline_set_item_value(inline_evt);
            break;
        }
        
        case EVT_ID_CUI_INLINE_SET_KEY:
        {
            cui_event_inline_set_key_struct *inline_evt = (cui_event_inline_set_key_struct *)evt;
            U32 item = inline_evt->item_id - CUI_INLINE_ITEM_ID_BASE;
            
            if (mmi_frm_group_is_present(GRP_ID_MEDPLY_SETTINGS_PLAYER))
            {
                switch(item)
                {
                #if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
                #ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
                    case SOUND_TYPE_SELECT2:
                    {
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_SET_KEY,inline_evt->sender_id ,item ,__LINE__);
                        if(g_settings_current_audio_effect == SETTINGS_SOUND_EFFECTS_EQ)/* equalizer option */
                        {
                            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
                            cui_inline_set_softkey_icon(inline_evt->sender_id, 
                                CUI_INLINE_ITEM_ID_BASE + SOUND_TYPE_SELECT2, 
                                MMI_CENTER_SOFTKEY, 
                                IMG_GLOBAL_OPTION_CSK);
                            SetCenterSoftkeyFunction(mmi_medply_settings_entry_audio_equalizer_setting_options, KEY_EVENT_UP);
                        }  
                        break;
                    }
                #endif  /* __MMI_EDITABLE_AUDIO_EQUALIZER__ */
                #endif /* defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__) */
                #if !defined (__MMI_MEDIA_PLAYER_FTE__) && !defined(__MMI_FTE_SUPPORT__)
                #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
                    case SKIN_TYPE_DISPLAY_ONLY:
                    {
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_SET_KEY,inline_evt->sender_id ,item ,__LINE__);
                        cui_inline_set_softkey_text(inline_evt->sender_id, 
                            CUI_INLINE_ITEM_ID_BASE + SKIN_TYPE_DISPLAY_ONLY, 
                            MMI_LEFT_SOFTKEY, 
                            STR_GLOBAL_OPTIONS);//STR_GLOBAL_UPDATE);
                        wgui_inline_set_lsk_function(mmi_medply_settings_entry_skin_select_option);
                        cui_inline_set_softkey_icon(inline_evt->sender_id, 
                            CUI_INLINE_ITEM_ID_BASE + SKIN_TYPE_DISPLAY_ONLY, 
                            MMI_CENTER_SOFTKEY, 
                            IMG_GLOBAL_OPTION_CSK);
                        SetCenterSoftkeyFunction(mmi_medply_settings_entry_skin_select_option, KEY_EVENT_UP);
                        break;
                    }
                #endif
                #endif /*__MMI_FILE_MANAGER__ && __MMI_FILE_USEAS_SUPPORT__*/
                    default:
                        break;
                }
            }
        #if defined(__MMI_MEDIA_PLAYER_STREAM__) 
            else if (mmi_frm_group_is_present(GRP_ID_MEDPLY_PROFILE_EDIT))
            {
                switch(item)
                {
                    case DATA_ACCOUNT_TYPE_DISPLAY_ONLY:
                    {
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_SET_KEY,inline_evt->sender_id ,item ,__LINE__);
                        cui_inline_set_softkey_text(inline_evt->sender_id, 
                            CUI_INLINE_ITEM_ID_BASE + DATA_ACCOUNT_TYPE_DISPLAY_ONLY, 
                            MMI_LEFT_SOFTKEY, 
                            STR_GLOBAL_SELECT);
                        wgui_inline_set_lsk_function(mmi_medply_settings_entry_data_accout_cui);
                        cui_inline_set_softkey_icon(inline_evt->sender_id, 
                            CUI_INLINE_ITEM_ID_BASE + DATA_ACCOUNT_TYPE_DISPLAY_ONLY, 
                            MMI_CENTER_SOFTKEY, 
                            IMG_GLOBAL_COMMON_CSK);
                        SetCenterSoftkeyFunction(mmi_medply_settings_entry_data_accout_cui, KEY_EVENT_UP);
                        break;
                    }
                    default:
                        break;
                }
            }
        #endif /*__MMI_MEDIA_PLAYER_STREAM__ */
            
            break;
        }
        
        case EVT_ID_CUI_INLINE_CSK_PRESS: //only enabled when disable done
        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            #if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
            #ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
            cui_event_inline_submit_struct *inline_evt = (cui_event_inline_submit_struct *)evt;
            U32 item = inline_evt->item_id - CUI_INLINE_ITEM_ID_BASE;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_SUBMIT,inline_evt->sender_id ,__LINE__);

            if (mmi_frm_group_is_present(GRP_ID_MEDPLY_SETTINGS_PLAYER) &&
				g_settings_current_audio_effect == SETTINGS_SOUND_EFFECTS_EQ && item == SOUND_TYPE_SELECT2)
            {
                mmi_medply_settings_entry_audio_equalizer_setting_options();
            }
            else
            #endif
            #endif
            {
                /* MAUI_03158737 - To make saving the settings consistent - display no confirm */
                // mmi_medply_settings_done();
                mmi_medply_settings_pre_save();
            }
            break;
        }
        
        case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_abort_struct *inline_evt = (cui_event_inline_abort_struct*)evt;
            
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_ABORT,inline_evt->sender_id ,__LINE__);
            cui_inline_close(inline_evt->sender_id);
            break;
        }
    }
    return MMI_RET_OK;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_cui_hdlr_file_selector
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_medply_settings_cui_hdlr_file_selector(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
        {
            cui_file_selector_result_event_struct *selector_evt = (cui_file_selector_result_event_struct*) evt;
            
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_SELECTOR_CUI_RESULT,selector_evt->sender_id ,selector_evt->result, __LINE__);
            mmi_medlpy_settings_fmgr_file_selector_handle(selector_evt);
            break;
        }
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_cui_hdlr_alert
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_medply_settings_cui_hdlr_alert(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *confirm = (mmi_alert_result_evt_struct *)evt;

            switch (confirm->result)
            {
                case MMI_ALERT_NORMAL_EXIT:
                    break;
                case MMI_ALERT_CNFM_OK:  
                case MMI_ALERT_CNFM_YES:         
                {
                    switch ((S32)confirm->user_tag)
                    {
                        case MMI_MEDPLY_SETTINGS_COMFIRM_SAVE:
                        {
                            mmi_medply_settings_pre_save();
                            break;
                        }
                    #if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
                    #ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
                        case MMI_MEDPLY_SETTINGS_COMFIRM_RESTORE:
                        {
                            mmi_medply_settings_audio_equalizer_restore_factory_default_confirm_yes();
                            break;
                        }
                    #endif
                    #endif
                        default:
                            break;
                    }
                    break;
                }
                case MMI_ALERT_CNFM_NO:         
                case MMI_ALERT_CNFM_CANCEL:      
                {
                    switch ((S32)confirm->user_tag)
                    {
                        case MMI_MEDPLY_SETTINGS_COMFIRM_SAVE:
                        {
                            mmi_medply_settings_pre_no_save();
                            break;
                        }
                        case MMI_MEDPLY_SETTINGS_COMFIRM_RESTORE:
                        {
                            break;
                        }
                        
                        default:
                            break;
                    }
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_proc
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_medply_settings_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
/*************************Menu CUI event***************************/
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_LIST_EXIT:
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            return mmi_medply_settings_cui_hdlr_menu(evt);

/**********************Inline CUI event*************************/
        case EVT_ID_CUI_INLINE_NOTIFY:
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        case EVT_ID_CUI_INLINE_SET_KEY:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_ABORT:
            return mmi_medply_settings_cui_hdlr_inline(evt);
            
/**********************File selector CUI event*************************/
        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
            return mmi_medply_settings_cui_hdlr_file_selector(evt);
            
/**********************alert CUI event*************************/
        case EVT_ID_ALERT_QUIT:
            return mmi_medply_settings_cui_hdlr_alert(evt);
        
        default:
            break;
    }
    
    return MMI_RET_OK;
}


#define __SETTINGS_PLAYER__

#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_entry_audio_equalizer_setting_options
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_entry_audio_equalizer_setting_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID  cui_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_MEDPLY_SETTINGS_PLAYER, GRP_ID_MEDPLY_SETTINGS_SOUNDEFFECT_OPTION, mmi_medply_settings_proc, (void*)NULL); 

    mmi_frm_group_enter(GRP_ID_MEDPLY_SETTINGS_SOUNDEFFECT_OPTION, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_gid = cui_menu_create(
                    GRP_ID_MEDPLY_SETTINGS_SOUNDEFFECT_OPTION, 
                    CUI_MENU_SRC_TYPE_RESOURCE, 
                    CUI_MENU_TYPE_OPTION, 
                    MENU_ID_MEDPLY_SOUNDEFFECT_OPTION, 
                    MMI_FALSE, 
                    NULL);
    if (cui_gid > GRP_ID_INVALID)
    {
        cui_menu_set_default_title_image(cui_gid, (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)));
        cui_menu_run(cui_gid);
    }
    else
    {   
        mmi_medply_settings_popup_simple_with_string((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_entry_audio_equalizer_setting_edit
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_entry_audio_equalizer_setting_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_settings_entry_audio_equalizer_setting_edit(GRP_ID_MEDPLY_SETTINGS_PLAYER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_entry_audio_equalizer_setting_rename
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_entry_audio_equalizer_setting_rename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_settings_entry_audio_equalizer_setting_rename(GRP_ID_MEDPLY_SETTINGS_PLAYER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_audio_equalizer_restore_factory_default_confirm_yes
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_audio_equalizer_restore_factory_default_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_settings_audio_equalizer_restore_factory_default();
/*bql: apply new UE design to avoid success popup */
#if 1
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_audio_equalizer_restore_factory_default_confirm
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_audio_equalizer_restore_factory_default_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_settings_confirm(GRP_ID_MEDPLY_SETTINGS_PLAYER,
        (WCHAR *)get_string(STR_ID_SETTING_AUDIO_EQUALIZER_REST_FACT_DEFAULT_CONFIRM),
        MMI_MEDPLY_SETTINGS_COMFIRM_RESTORE,
        CNFM_TYPE_YESNO,
        MMI_FALSE,
        MMI_EVENT_QUERY);     

}
#endif
#endif



#if !defined (__MMI_MEDIA_PLAYER_FTE__) && !defined(__MMI_FTE_SUPPORT__)
#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_inline_set_skin
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_inline_set_skin(MMI_ID inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width;
    S32 height;
    FS_HANDLE result = FS_NO_ERROR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_ucs2strlen((CHAR*)g_skin_custom_path) == 0)
    {
        g_mmi_medply_settings_player.skin_file_selected = MMI_MEDPLY_SKIN_NO_SELECT;
    }
    else 
    {
        result = DRM_open_file((PU16)g_skin_custom_path, FS_READ_ONLY,DRM_PERMISSION_PLAY);
        if (result < FS_NO_ERROR)
        {
            g_mmi_medply_settings_player.skin_select_id = MMI_MEDPLY_SKIN_DEFAULT;
            g_mmi_medply_settings_player.skin_file_selected = MMI_MEDPLY_SKIN_NO_SELECT; 
            g_skin_custom_path[0] = '\0';
            g_skin_custom_path[1] = '\0';            
        }
        else
        {
            DRM_close_file(result);
            result = gdi_image_get_dimension_file((CHAR*) g_skin_custom_path, &width, &height);
            if ((4 * width) < UI_device_width   || 
             (4 * height) < UI_device_height ||
             (width > (2 * UI_device_width)) ||
             (height > (2 * UI_device_height)) ||
             !mmi_medply_setting_check_drm_display_perm((PU16) g_skin_custom_path))
            {
                g_mmi_medply_settings_player.skin_file_selected = MMI_MEDPLY_SKIN_NO_SELECT;

                g_mmi_medply_settings_player.skin_select_id = MMI_MEDPLY_SKIN_DEFAULT;
            }  
            else
            {
                g_mmi_medply_settings_player.skin_file_selected = MMI_MEDPLY_SKIN_FILE_SELECTED;
            }
        }
    }
    if (g_mmi_medply_settings_player.skin_file_selected == MMI_MEDPLY_SKIN_FILE_SELECTED &&
        g_mmi_medply_settings_player.skin_select_id != MMI_MEDPLY_SKIN_DEFAULT)
    {
        cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + SKIN_TYPE_DISPLAY_ONLY, (void*)GetString(STR_ID_MEDPLY_SKIN_FILE_SELECTED));
    }
    else
    {
        cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + SKIN_TYPE_DISPLAY_ONLY, (void*)GetString(STR_ID_MEDPLY_SKIN_THEME));
    }

}
#endif
#endif /*!defined (__MMI_MEDIA_PLAYER_FTE__) && !defined(__MMI_FTE_SUPPORT__)*/

/*****************************************************************************
 * FUNCTION
 *  mmi_medlpy_settings_fmgr_file_selector_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medlpy_settings_fmgr_file_selector_handle(cui_file_selector_result_event_struct *file_select)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp_path[MEDPLY_MAX_PATH_LEN + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_select->result > 0)
    {
        cui_file_selector_get_selected_filepath(
                                file_select->sender_id,
                                NULL,
                                (WCHAR *) temp_path,
                                (SRV_FMGR_PATH_MAX_LEN+1) * ENCODING_LENGTH);
        
        mmi_medply_settings_fmgr_select_result_callback(temp_path, MMI_FALSE);
    }
    else if (file_select->result == 0)
    {
        cui_file_selector_close(file_select->sender_id);
    }
    else
    {
        mmi_medply_settings_popup_simple_with_string(
            (U16*)get_string(srv_fmgr_fs_error_get_string(file_select->result)), 
            (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(file_select->result));
        cui_file_selector_close(file_select->sender_id);
    }
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_skin_select_config
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_skin_select_config(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_VIEW_SKIN, MMI_TRUE);
    
    if (g_mmi_medply_settings_player.skin_file_selected == MMI_MEDPLY_SKIN_FILE_SELECTED)
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_VIEW_SKIN, MMI_FALSE);
    }
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_SETTINGS_DONE, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_skin_preview_callback
 * DESCRIPTION
 *  preview skin callback
 * PARAMETERS
 *  result [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_skin_preview_callback(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result < 0)
    {
    #ifndef __MMI_WGUI_DISABLE_CSK__
        ChangeCenterSoftkey(0, 0);
    #endif
        SetCenterSoftkeyFunction(NULL, KEY_EVENT_UP);
        ChangeLeftSoftkey(0, 0);
        SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_select_skin_done
 * DESCRIPTION
 *  select skin done
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_select_skin_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2cmp((CHAR*)g_mmi_medply_settings.skin_custom_path, (CHAR*)g_skin_custom_path))
    {
        g_selected_skin_changed = MMI_TRUE;
    }
    g_mmi_medply_settings_player.skin_select_id = MMI_MEDPLY_SKIN_FROM_FILE;
    g_mmi_medply_settings_player.skin_file_selected = MMI_MEDPLY_SKIN_FILE_SELECTED;
    
    mmi_frm_group_close(GRP_ID_MEDPLY_SETTINGS_SELECT_FILE);
    mmi_frm_scrn_close(GRP_ID_MEDPLY_SETTINGS_PLAYER, SCR_ID_MEDPLY_SETTINGS_SKIN_VIEW);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_select_skin_back
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_select_skin_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_mmi_medply_settings_player.skin_file_selected != MMI_MEDPLY_SKIN_NO_SELECT)
    {
        mmi_ucs2cpy((CHAR*)g_skin_custom_path, (CHAR*)g_mmi_medply_settings.skin_custom_path);
    }
    else
    {
        g_skin_custom_path[0] = '\0';
        g_skin_custom_path[1] = '\0';
    }    
    mmi_frm_scrn_close(GRP_ID_MEDPLY_SETTINGS_PLAYER, SCR_ID_MEDPLY_SETTINGS_SKIN_VIEW);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_skin_view
 * DESCRIPTION
 *  view skin 
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_skin_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE result;
    S32 width;
    S32 height;
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = DRM_open_file((PU16)g_skin_custom_path, FS_READ_ONLY,DRM_PERMISSION_PLAY);
    if (result < FS_NO_ERROR)
    {
        if (!g_selected_skin_changed)
        {
            mmi_ucs2cpy((CHAR*)g_skin_custom_path, (CHAR*)g_mmi_medply_settings.skin_custom_path);
        }
        mmi_medply_settings_popup_simple_with_string(
            (U16*)get_string(srv_fmgr_fs_error_get_string(result)), 
            (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(result));
        return;
    }
    DRM_close_file(result);

    result = gdi_image_get_dimension_file((CHAR*) g_skin_custom_path, &width, &height);
    if (result < 0)
    {
        if (!g_selected_skin_changed)
        {
            mmi_ucs2cpy((CHAR*)g_skin_custom_path, (CHAR*)g_mmi_medply_settings.skin_custom_path);
        }
        mmi_medply_settings_popup_simple_with_string(
            (U16*)get_string(STR_GLOBAL_UNSUPPORTED_FORMAT), 
            MMI_EVENT_ERROR);
        return;
    }
    else if (((4 * width) < UI_device_width) || ((4 * height) < UI_device_height))
    {
        if (!g_selected_skin_changed)
        {
            mmi_ucs2cpy((CHAR*)g_skin_custom_path, (CHAR*)g_mmi_medply_settings.skin_custom_path);
        }
        mmi_medply_settings_popup_simple_with_string(
            (U16*)get_string(STR_ID_MEDPLY_ERROR_FILE_TOO_SMALL), 
            MMI_EVENT_ERROR);
        return;
    }
    else if ((width > (2 * UI_device_width)) || (height > (2 * UI_device_height)))
    {
        if (!g_selected_skin_changed)
        {
            mmi_ucs2cpy((CHAR*)g_skin_custom_path, (CHAR*)g_mmi_medply_settings.skin_custom_path);
        }
        mmi_medply_settings_popup_simple_with_string(
            (U16*)get_string(STR_ID_MEDPLY_ERROR_FILE_TOO_LARGE), 
            MMI_EVENT_ERROR);
        return;
    }
    
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_SETTINGS_PLAYER, SCR_ID_MEDPLY_SETTINGS_SKIN_VIEW, NULL, mmi_medply_settings_skin_view, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }    

#ifndef __MMI_WGUI_DISABLE_CSK__
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
    ShowCategory222Screen(
        STR_GLOBAL_VIEW,
        GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        GDI_COLOR_BLACK,
        (CHAR*) NULL,
        (CHAR*) g_skin_custom_path,
        FALSE,
        mmi_medply_settings_skin_preview_callback,
        GDI_IMAGE_SRC_FROM_FILE);
    SetCenterSoftkeyFunction(mmi_medply_settings_select_skin_done, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_medply_settings_select_skin_done, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_medply_settings_select_skin_back, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_check_valid_format
 * DESCRIPTION
 *  check valid format
 * PARAMETERS
 *  filepath [IN] file path of skin
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_medply_settings_check_valid_format(CHAR * filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 img_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    img_type = gdi_image_get_type_from_file((CHAR*) filepath);
    if ((img_type != GDI_IMAGE_TYPE_JPG_FILE)
#ifdef GDI_USING_PNG
        && (img_type != GDI_IMAGE_TYPE_PNG_FILE)
#endif 
        && (img_type != GDI_IMAGE_TYPE_BMP_FILE)
        && (img_type != GDI_IMAGE_TYPE_GIF_FILE)
        && (img_type != GDI_IMAGE_TYPE_WBMP_FILE)
        /*&& (img_type != GDI_IMAGE_TYPE_SVG_FILE)*/)
    {
        mmi_medply_settings_popup_simple_with_string(
            (U16*)get_string(STR_GLOBAL_INVALID_FORMAT), 
            MMI_EVENT_ERROR);
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_fmgr_select_result_callback
 * DESCRIPTION
 *  callback after select file from fmgr
 * PARAMETERS
 *  filepath [IN]  file path of skin
 *  is_short [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_fmgr_select_result_callback(void * filepath, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 strlen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strlen = mmi_ucs2strlen(filepath);
    if (strlen > SRV_FMGR_PATH_MAX_LEN)
    {
        mmi_medply_settings_popup_simple_with_string(
            (U16*)get_string(srv_fmgr_fs_error_get_string(FS_PATH_OVER_LEN_ERROR)), 
            MMI_EVENT_ERROR);
        return;
    }
    if (filepath != NULL)
    {
    #ifdef __DRM_SUPPORT__
		if (!mmi_medply_setting_check_drm_display_perm((PU16) filepath))
		{
            mmi_medply_settings_popup_simple_with_string(
                (U16*)get_string(STR_GLOBAL_DRM_PROHIBITED), 
                MMI_EVENT_ERROR);
            return;
        }
    #endif /* __DRM_SUPPORT__ */ 
        if (mmi_medply_settings_check_valid_format((CHAR*) filepath))
        {
            mmi_ucs2cpy((CHAR*)g_skin_custom_path, (CHAR*)filepath);
            mmi_medply_settings_skin_view();
        }
    }
}


#if !defined (__MMI_MEDIA_PLAYER_FTE__) && !defined(__MMI_FTE_SUPPORT__)
#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_entry_skin_select_file
 * DESCRIPTION
 *  select skin file 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_entry_skin_select_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    MMI_ID  cui_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
   
    FMGR_FILTER_INIT(&filter);
#ifdef __GDI_MEMORY_PROFILE_2__
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPG);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPEG);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
    FMGR_FILTER_SET(&filter, FMGR_TYPE_BMP);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_GIF);
#ifdef GDI_USING_PNG
    FMGR_FILTER_SET(&filter, FMGR_TYPE_PNG);
#endif 
    FMGR_FILTER_SET(&filter, FMGR_TYPE_WBMP);
    /*FMGR_FILTER_SET(&filter, FMGR_TYPE_SVG);*/
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);

    mmi_frm_group_create(GRP_ID_MEDPLY_SETTINGS_PLAYER, GRP_ID_MEDPLY_SETTINGS_SELECT_FILE,
                        mmi_medply_settings_proc, (void*)NULL); 
    
    mmi_frm_group_enter(GRP_ID_MEDPLY_SETTINGS_SELECT_FILE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    cui_gid = cui_file_selector_create(
                                    GRP_ID_MEDPLY_SETTINGS_SELECT_FILE,
                                    (WCHAR*) L"root",
                                    &filter,
                                    CUI_FILE_SELECTOR_STYLE_FILE_ONLY,
                                    CUI_FILE_SELECTOR_OPT_DRM_CHECK_SET_ON);
    cui_file_selector_set_title(cui_gid, 0, GetRootTitleIcon(MENU_ID_MEDPLY_MAIN));
    cui_file_selector_run(cui_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_select_theme
 * DESCRIPTION
 *  select theme done 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_select_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_medply_settings_player.skin_select_id != 0)
    {
        g_selected_skin_changed = MMI_TRUE;
    }
    g_mmi_medply_settings_player.skin_select_id = 0; /* select theme as skin */
	g_mmi_medply_settings_player.skin_file_selected = MMI_MEDPLY_SKIN_NO_SELECT;
    mmi_frm_group_close(GRP_ID_MEDPLY_SETTINGS_SKIN_OPTION);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_entry_skin_select_option
 * DESCRIPTION
 *  select skin option 
 * PARAMETERS
 *  type    [IN]  hide menuitem type
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_entry_skin_select_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID  cui_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_MEDPLY_SETTINGS_PLAYER, GRP_ID_MEDPLY_SETTINGS_SKIN_OPTION, mmi_medply_settings_proc, (void*)NULL); 
    
    mmi_frm_group_enter(GRP_ID_MEDPLY_SETTINGS_SKIN_OPTION, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    cui_gid = cui_menu_create(
                    GRP_ID_MEDPLY_SETTINGS_SKIN_OPTION, 
                    CUI_MENU_SRC_TYPE_RESOURCE, 
                    CUI_MENU_TYPE_OPTION, 
                    MENU_ID_MEDPLY_SELECT_FILE_OPTION, 
                    MMI_FALSE, 
                    NULL);
    if (cui_gid > GRP_ID_INVALID)
    {
        cui_menu_set_default_title_image(cui_gid, (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)));
        cui_menu_run(cui_gid);
    }
    else
    {   
        mmi_medply_settings_popup_simple_with_string((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
    }
}
#endif
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_setting_check_drm_display_perm
 * DESCRIPTION
 *  Check image drm permission of forward as background image 
 * PARAMETERS
 *  filepath    [IN]background image filepath
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_medply_setting_check_drm_display_perm(PU16 filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL is_perm = MMI_TRUE;
#ifdef __DRM_SUPPORT__
	FS_HANDLE handle;	
#endif /* __DRM_SUPPORT__ */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DRM_SUPPORT__
	handle = DRM_open_file((PU16)filepath, FS_READ_ONLY, DRM_PERMISSION_DISPLAY);
	if (handle >= FS_NO_ERROR)
    {
    	is_perm = DRM_validate_forward_rule(handle, DRM_PERMISSION_DISPLAY);
        DRM_close_file(handle);
	}
#endif /* __DRM_SUPPORT__ */

	return is_perm;
}

#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_sound_effect_confirm_done
 * DESCRIPTION
 *  sound effect selected done confirm 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_sound_effect_confirm_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_settings_selected_audio_effect != g_settings_current_audio_effect || 
       g_settings_current_audio_effect == SETTINGS_SOUND_EFFECTS_NONE)
    {
        mmi_settings_turn_off_audio_effect();
    }

    switch (g_settings_current_audio_effect)
    {
    #ifdef __MMI_AUDIO_EQUALIZER__
        case SETTINGS_SOUND_EFFECTS_EQ :
            mmi_settings_audio_eq_apply((S16) current_audio_equalizer_index);
            break;
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SETTINGS_SOUND_EFFECTS_REVERB :
            mmi_settings_audio_reverb_apply((U16) current_audio_reverb_index);
            break;
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SETTINGS_SOUND_EFFECTS_SURROUND :
            mmi_settings_audio_surround_apply((U16)current_audio_surround_index);
            break;
    #endif
        default :
            break;
    }

    g_settings_selected_audio_effect = g_settings_current_audio_effect;
    mmi_settings_audio_effect_write_nvram();

#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
    if(g_settings_bass_enhancement != g_settings_selected_bass_enhancement)
    {
        mmi_settings_bass_enhancement_apply(g_settings_selected_bass_enhancement);
    }
#endif

    WriteRecord(NVRAM_EF_MEDPLY_SETTINGS_LID,1,(void*)&g_mmi_medply_settings,NVRAM_EF_MEDPLY_SETTINGS_SIZE, &pError);
#ifdef __MMI_AUDIO_SURROUND_BIND_EARPHONE__
    if(g_settings_current_audio_effect == SETTINGS_SOUND_EFFECTS_SURROUND)
    {
        mmi_medply_settings_popup_simple_with_string(
            (U16*)get_string(STR_ID_SETTING_AUDIO_SURROUND_PLUG_EAPHONE), 
            MMI_EVENT_INFO);
    }
    else
    {
/*bql: apply new UE design to avoid success popup */
#if 1
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    }                
#else
/*bql: apply new UE design to avoid success popup */
#if 1
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
    /* delete the screen and go back to GRP_ID_MEDPLY_SETTINGS_MAIN */
    mmi_frm_group_close(GRP_ID_MEDPLY_SETTINGS_PLAYER);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_inline_set_audio_effect2
 * DESCRIPTION
 *  init the player audio effect settings 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_inline_set_audio_effect2(MMI_ID inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 inline_num = 0;
    U16 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_AUDIO_EQUALIZER__) && !defined(__MMI_EDITABLE_AUDIO_EQUALIZER__)
    MMI_ID_TYPE audio_equalizer_list_strings[] = 
    {
        STR_GLOBAL_NORMAL,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_2,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_3,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_4,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_5,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_6,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_7,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_8
    };
#endif /* defined(__MMI_AUDIO_EQUALIZER__) && !defined(__MMI_EDITABLE_AUDIO_EQUALIZER__) */ 
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    MMI_ID_TYPE medply_audio_reverb_list_strings[] = 
    {      
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET1,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET2,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET3,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET4,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET5,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET6
    };
#endif /* __MMI_AUDIO_REVERB_EFFECT__ */ 
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    MMI_ID_TYPE medply_audio_surround_list_strings[] = 
    {
        STR_ID_SETTING_AUDIO_SURROUND_MODE1,
        STR_ID_SETTING_AUDIO_SURROUND_MODE2
    };
#endif /* __MMI_AUDIO_SURROUND_EFFECT__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(g_settings_current_audio_effect)
    {
#ifdef __MMI_AUDIO_EQUALIZER__
        case SETTINGS_SOUND_EFFECTS_EQ :
            for (i = 0; i < g_settings_audio_equalizer.count; i++)
            {
        #ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
                g_settings_audio_effects_inline2[i] = (UI_string_type) g_settings_audio_equalizer.setting_name[i];
        #else 
                g_settings_audio_effects_inline2[i] = (UI_string_type) GetString(audio_equalizer_list_strings[i]);
        #endif
            }
            inline_num = g_settings_audio_equalizer.count;
            g_settings_current_effect_index = current_audio_equalizer_index ;
            break;
#endif
#ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SETTINGS_SOUND_EFFECTS_REVERB :
            for (i = 0; i < MAX_AUDIO_REVERB_EFFECT_NUM; i++)
            {
                g_settings_audio_effects_inline2[i] = (UI_string_type) GetString(medply_audio_reverb_list_strings[i]);
            }
            inline_num = MAX_AUDIO_REVERB_EFFECT_NUM ;
            g_settings_current_effect_index = current_audio_reverb_index ;
            break;
#endif
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SETTINGS_SOUND_EFFECTS_SURROUND :
            for(i = 0 ; i < AUD_SURROUND_TOTAL ; i++)
            {
                g_settings_audio_effects_inline2[i] = (UI_string_type) GetString(medply_audio_surround_list_strings[i]);
            }
            inline_num = AUD_SURROUND_TOTAL ;
            g_settings_current_effect_index = current_audio_surround_index ;
            break;
#endif
        default:
            break;
    }


    if(g_settings_current_audio_effect != SETTINGS_SOUND_EFFECTS_NONE)
    {
        cui_inline_set_item_attributes(inline_id, 
            CUI_INLINE_ITEM_ID_BASE + SOUND_TYPE_SELECT2, 
            CUI_INLINE_SET_ATTRIBUTE, 
            CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY);
        cui_inline_set_item_select(inline_id, 
            CUI_INLINE_ITEM_ID_BASE + SOUND_TYPE_SELECT2, 
            inline_num, 
            (U8 **) g_settings_audio_effects_inline2,
            (U8)g_settings_current_effect_index);
    }
    else
    {
        cui_inline_set_item_attributes(inline_id, 
            CUI_INLINE_ITEM_ID_BASE + SOUND_TYPE_SELECT2, 
            CUI_INLINE_SET_ATTRIBUTE, 
            CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY);
        cui_inline_set_value(inline_id, 
            CUI_INLINE_ITEM_ID_BASE + SOUND_TYPE_SELECT2, 
            (void *)GetString((U16)(STR_GLOBAL_EMPTY)));
    }


}

#endif /*__MMI_AUDIO_EQUALIZER__ || __MMI_AUDIO_REVERB_EFFECT__ || __MMI_AUDIO_SURROUND_EFFECT*/

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_player_is_changed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_medply_settings_player_is_changed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL sound_effect_change = MMI_FALSE;
#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
    U16 i, j;
#endif  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
    if (g_settings_eq_rename_flag_temp != g_settings_eq_rename_flag)
    {
        sound_effect_change = MMI_TRUE;
    }

    if (g_settings_audio_equalizer_temp.index != g_settings_audio_equalizer.index)
    {
        sound_effect_change = MMI_TRUE;
    }
    else
    {
        i = g_settings_audio_equalizer.index;
        for (j = 0; j < NUM_OF_BARS_IN_A_SETTING; j++)
        {
            if(g_settings_audio_equalizer_temp.magnitude[i][j] != g_settings_audio_equalizer.magnitude[i][j])
            {
                sound_effect_change = MMI_TRUE;
                break;
            }
        }
        if(mmi_ucs2cmp((CHAR*)g_settings_audio_equalizer_temp.setting_name[g_settings_audio_equalizer_temp.index],
                        (CHAR*) g_settings_audio_equalizer.setting_name[g_settings_audio_equalizer.index]))
        {
            sound_effect_change = MMI_TRUE;
        }
    }
#endif  

    if (g_selected_skin_changed || sound_effect_change)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }

}
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_player_set_item_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_player_set_item_value(MMI_ID inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/***********************************update******************************************/
/* Set skin */
#if !defined (__MMI_MEDIA_PLAYER_FTE__) && !defined(__MMI_FTE_SUPPORT__)
#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
    mmi_medply_settings_inline_set_skin(inline_id);   
#endif
#endif /*__MMI_MEDIA_PLAYER_FTE__   __MMI_FTE_SUPPORT__*/

/* set audio effect 2 */
#if defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
    mmi_medply_settings_inline_set_audio_effect2(inline_id);   
#endif /* defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)*/
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_player_init_item_value
 * DESCRIPTION
 *  entry the player settings 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_player_init_item_value(MMI_ID inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_icons[MEDPLY_SETTINGS_PLAYER_INLINE_ITEM_NUM];
    U16 item_count = 0;
    U16 trip_count = 0;
#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
    U16 i, j;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/***********************************initialize for first entry******************************************/
    g_selected_skin_changed = MMI_FALSE;
    g_mmi_medply_settings_player.skin_select_id = g_mmi_medply_settings.is_theme_default;
    g_mmi_medply_settings_player.bg_play_id = g_mmi_medply_settings.is_bgplay;
    g_mmi_medply_settings_player.repeat_play_id = g_mmi_medply_settings.repeat;
    g_mmi_medply_settings_player.shuffle_play_id = g_mmi_medply_settings.is_shuffle;
    g_mmi_medply_settings_player.is_restored_save = MMI_FALSE;//@TODO: re-check!
#ifdef MOTION_SENSOR_SUPPORT
    g_mmi_medply_settings_player.is_autofulscr_bysensor = g_mmi_medply_settings.is_autofulscr_by_sensor;
#endif   
    mmi_ucs2cpy((CHAR*)g_skin_custom_path,(CHAR*)g_mmi_medply_settings.skin_custom_path);
#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
    g_settings_selected_bass_enhancement = g_settings_bass_enhancement;
#endif

#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
    g_settings_current_audio_effect = g_settings_selected_audio_effect;
    #ifdef __MMI_AUDIO_EQUALIZER__
        current_audio_equalizer_index = (U16)g_settings_audio_equalizer.index;
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        current_audio_reverb_index = g_mmi_aud_3d_cntx.reverb_index;
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        current_audio_surround_index = g_mmi_aud_3d_cntx.surround_index;
    #endif

    #ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
         for( i = 0; i < MAX_EQUALIZER_NUM ; i++)
         {
            for (j = 0; j < NUM_OF_BARS_IN_A_SETTING; j++)
            {
                g_settings_audio_equalizer_temp.magnitude[i][j] = g_settings_audio_equalizer.magnitude[i][j]; 
            }
            mmi_ucs2cpy((CHAR*)g_settings_audio_equalizer_temp.setting_name[i], (CHAR*) g_settings_audio_equalizer.setting_name[i]);
         }
         g_settings_audio_equalizer_temp.index = g_settings_audio_equalizer.index;
         g_settings_eq_rename_flag_temp = g_settings_eq_rename_flag;
    #endif
#endif /*__MMI_AUDIO_EQUALIZER__ || __MMI_AUDIO_REVERB_EFFECT__ || __MMI_AUDIO_SURROUND_EFFECT__*/

/***********************************set/init select******************************************/

/* shuffer */
    cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + SHUFFLE_TYPE_SELECT, 
        (void *)g_mmi_medply_settings_player.shuffle_play_id);

/* repeat */
    cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + REPEAT_TYPE_SELECT, 
        (void *)g_mmi_medply_settings_player.repeat_play_id);

/* motion sensor tilt */
#ifdef MOTION_SENSOR_SUPPORT
    cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + MOTION_TYPE_SELECT, 
        (void *)g_mmi_medply_settings_player.is_autofulscr_bysensor);
#endif

/* Background play*/
#if !defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__)   
    cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + BACKGROUND_TYPE_SELECT, 
        (void *)g_mmi_medply_settings_player.bg_play_id);
#endif

/* set audio effect1 */
#if defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
    cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + SOUND_TYPE_SELECT1, 
        (void *)g_settings_current_audio_effect);
#endif /* defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)*/

/* set bass */
#ifdef __MMI_AUDIO_BASS_ENHANCEMENT__
    cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + BASS_TYPE_SELECT, 
        (void *)g_settings_selected_bass_enhancement);
#endif


/***********************************initialize icon******************************************/
    while (item_count < MEDPLY_SETTINGS_PLAYER_INLINE_ITEM_NUM)
    {
#if defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
        if (item_count == SOUND_TYPE_CAPTION)
        {
            item_icons[item_count] = IMG_GLOBAL_L1 + (item_count)/2;
            item_count++;
            item_icons[item_count++] = 0;
            item_icons[item_count++] = 0;
            trip_count++;
        }
        else
#endif /*defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)*/
        {
            item_icons[item_count] = IMG_GLOBAL_L1 + (item_count - trip_count)/2;
            item_count++;
            item_icons[item_count++] = 0;
        }
    }
    
    cui_inline_set_icon_list(inline_id, &item_icons[0]);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_entry_player
 * DESCRIPTION
 *  entry the player settings 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_entry_player(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID inline_id = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_MEDPLY_SETTINGS_MAIN, GRP_ID_MEDPLY_SETTINGS_PLAYER, mmi_medply_settings_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_SETTINGS_PLAYER, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    inline_id = cui_inline_create(GRP_ID_MEDPLY_SETTINGS_PLAYER, &mmi_medply_settings_player_inline_screen);
    cui_inline_set_title_icon(inline_id, GetRootTitleIcon(MENU_ID_MEDPLY_MAIN));
    mmi_medply_settings_player_init_item_value(inline_id);
    mmi_medply_settings_player_set_item_value(inline_id);
    cui_inline_run(inline_id);
}

#define __SETTINGS_AUDIO__

#ifdef __MMI_MEDIA_PLAYER_AUDIO__



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_get_audio_speed_index
 * DESCRIPTION
 *  get audio speed  index
 * PARAMETERS
 *  speed  [IN]  audio speed
 * RETURNS
 *  S32 
 *****************************************************************************/
static S32 mmi_medply_settings_get_audio_speed_index(U16 speed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (speed)
    {
        case MDI_AUDIO_SPEED_SLOW2:
            index = 0;
            break;
        case MDI_AUDIO_SPEED_SLOW1:
            index = 1;
            break;
        case MDI_AUDIO_SPEED_NORMAL:
            index = 2;
            break;
        case MDI_AUDIO_SPEED_FAST1:
            index = 3;
            break;
        case MDI_AUDIO_SPEED_FAST2:
            index = 4;
            break;
        default :
            index = 2;
            break;
    }
    return index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_audio_set_item_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_audio_set_item_value(MMI_ID inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_audio_init_item_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_audio_init_item_value(MMI_ID inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_icons[MEDPLY_SETTINGS_AUDIO_INLINE_ITEM_NUM];
    U16 item_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/***********************************initialize for first entry******************************************/
    g_mmi_medply_settings_audio.audio_speed_id = mmi_medply_settings_get_audio_speed_index(g_mmi_medply_settings.audio_speed);
    g_mmi_medply_settings_audio.audio_speed_value = g_mmi_medply_settings.audio_speed;
    g_mmi_medply_settings_audio.mainscr_disp_id = g_mmi_medply_settings.mainscrdisp_index;
    g_mmi_medply_settings_player.is_restored_save = MMI_FALSE;//@TODO: re-check!
/***********************************set select******************************************/
/* Set play speed */
#ifdef __MMI_AUDIO_TIME_STRETCH__
    cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + AUDIO_SPEED_TYPE_SELECT, 
        (void *)g_mmi_medply_settings_audio.audio_speed_id);
#endif /*__MMI_AUDIO_TIME_STRETCH__*/

/* Set main screen display */
    cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + AUDIO_DISPLAY_TYPE_SELECT, 
        (void *)g_mmi_medply_settings_audio.mainscr_disp_id);
/***********************************initialize icon******************************************/
    while (item_count < MEDPLY_SETTINGS_AUDIO_INLINE_ITEM_NUM)
    {
        item_icons[item_count] = IMG_GLOBAL_L1 + (item_count)/2;
        item_count++;
        item_icons[item_count++] = 0;
    }
    
    cui_inline_set_icon_list(inline_id, &item_icons[0]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_entry_audio
 * DESCRIPTION
 *  entry audio speed settings 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_entry_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID inline_id = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_MEDPLY_SETTINGS_MAIN, GRP_ID_MEDPLY_SETTINGS_AUDIO, mmi_medply_settings_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_SETTINGS_AUDIO, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    inline_id = cui_inline_create(GRP_ID_MEDPLY_SETTINGS_AUDIO, &mmi_medply_settings_audio_inline_screen);
    cui_inline_set_title_icon(inline_id, GetRootTitleIcon(MENU_ID_MEDPLY_MAIN));
    mmi_medply_settings_audio_init_item_value(inline_id);
    mmi_medply_settings_audio_set_item_value(inline_id);
    cui_inline_run(inline_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_speed_check_before_play
 * DESCRIPTION
 *  (Note) This function shold only be called before request to play a file.
 * PARAMETERS
 *  speed       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_medply_settings_speed_check_before_play(U16 speed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result = MDI_AUDIO_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check speed only when speed is not normal */
    if (speed != MDI_AUDIO_SPEED_NORMAL)
    {
    #ifdef __MMI_AUDIO_TIME_STRETCH__
        result = mdi_audio_stretch_check_file_format((void*)g_medply.filefullpath);
    #endif
    }

    /*in case DRM file can not open, only check for speed*/
    if(result != MDI_AUDIO_UNSUPPORTED_SPEED)
    {
        result = MDI_AUDIO_SUCCESS;
    }

    return (S32) result;
}


#ifdef __MMI_AUDIO_TIME_STRETCH__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_apply_speed_changed_in_setting
 * DESCRIPTION
 *  apply the speed change in settings when in bg play state
 * PARAMETERS
 *  index
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL  mmi_medply_settings_apply_speed_changed_in_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mdi_result set_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_mmi_medply_settings.audio_speed != g_mmi_medply_settings_audio.audio_speed_value)
    {
        if (g_medply.state == MEDPLY_STATE_AUDIO_PLAY || g_medply.state == MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING)
        {
          
            if ((g_mmi_medply_settings.audio_speed == MDI_AUDIO_SPEED_NORMAL) && (g_mmi_medply_settings_audio.audio_speed_value != MDI_AUDIO_SPEED_NORMAL))
            {
            #ifdef __MMI_AUDIO_TIME_STRETCH__
                if (mmi_medply_settings_speed_check_before_play(g_mmi_medply_settings_audio.audio_speed_value) != MDI_AUDIO_SUCCESS)
                {
                    return MMI_FALSE;
                }
            #endif
            }

            if (g_medply.state == MEDPLY_STATE_AUDIO_PLAY  || g_medply.state == MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING)
            {
            #ifdef __MMI_AUDIO_TIME_STRETCH__
                set_result = mdi_audio_stretch_set_speed(g_mmi_medply_settings_audio.audio_speed_value);
            
                if (set_result != MDI_AUDIO_SUCCESS)
                {
                    return MMI_FALSE;
                }

                /* Only increase once if turn on in setting menu while playing */
                if (g_medply.speed_set_times == 0)
                {
                    g_medply.speed_set_times ++ ;
                }
            #endif 
            }
        }

        g_mmi_medply_settings.audio_speed = g_mmi_medply_settings_audio.audio_speed_value;
    #if defined(__MMI_A2DP_SUPPORT__)
    #ifdef __MMI_AUDIO_TIME_STRETCH__
         mmi_medply_bt_sync_speed();
    #endif
    #endif    
    }

    return MMI_TRUE;
}
#endif
#endif /* __MMI_MEDIA_PLAYER_AUDIO__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_is_audio_speed_normal
 * DESCRIPTION
 *  return if the current play speed is normal
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_medply_settings_is_audio_speed_normal(void)
{
#ifdef __MMI_AUDIO_TIME_STRETCH__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_SETTINGS_AUDIO_SPEED_NORMAL,g_mmi_medply_settings.audio_speed);
 

    return (g_mmi_medply_settings.audio_speed == MDI_AUDIO_SPEED_NORMAL) ? MMI_TRUE : MMI_FALSE;

#else
    return MMI_TRUE;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_close_speed
 * DESCRIPTION
 *  check and close speed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_settings_close_speed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef  __MMI_AUDIO_TIME_STRETCH__
    if (g_medply.speed_set_times == 1)
    {
        mdi_audio_stretch_close();
    }

    if (g_medply.speed_set_times > 0)
    {
        g_medply.speed_set_times--;
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_check_and_set_audio_speed
 * DESCRIPTION
 *  check if speed applicable and set set if necessary
 * PARAMETERS
 *  
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mmi_medply_settings_check_and_set_audio_speed(void)
{
#ifdef __MMI_AUDIO_TIME_STRETCH__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    result = mmi_medply_settings_speed_check_before_play(g_mmi_medply_settings.audio_speed);
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_SETTINGS_CHECK_AND_SET_AUDIO_SPEED,g_mmi_medply_settings.audio_speed,result);
    
    if (  result != MDI_AUDIO_SUCCESS)
    {
        return MDI_AUDIO_UNSUPPORTED_SPEED;
    }

    mdi_audio_stretch_set_speed(g_mmi_medply_settings.audio_speed);
    g_medply.speed_set_times++;
#endif
    return MDI_AUDIO_SUCCESS;
    
}

#define __SETTINGS_VIDEO__

#ifdef __MMI_MEDIA_PLAYER_VIDEO__
#if defined(__MMI_MEDIA_PLAYER_VIDEO_PROCESSING_SUPPORT__)  || defined(__MMI_MEDIA_PLAYER_VIDEO_SPEED__) || defined(MMI_MEDPLY_SETTINGS_VIDEO_3D_SUPPORT)  
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_check_and_set_pure_audio_speed
 * DESCRIPTION
 *  check if speed applicable and set set if necessary
 * PARAMETERS
 *  
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mmi_medply_settings_check_and_set_pure_audio_speed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mdi_result result;
    U16 audio_speed = MDI_AUDIO_SPEED_NORMAL;
    S32 index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = mmi_medply_settings_get_video_speed_index(g_mmi_medply_settings.video_speed);
    switch(index)
    {
        case 0:
        {
            audio_speed = MDI_AUDIO_SPEED_SLOW2;
            break;
        }
        
    #ifdef __MMI_MEDIA_PLAYER_VIDEO_SPEED_EIGHT_MAPPING__    
        case 1:
        {
            audio_speed = MDI_AUDIO_SPEED_SLOW2;
            break;
        }
        case 2:
        {
            audio_speed = MDI_AUDIO_SPEED_NORMAL;
            break;
        }
        case 3:
        {
            audio_speed = MDI_AUDIO_SPEED_FAST1;                
            break;
        }
        case 4:
        {
            audio_speed = MDI_AUDIO_SPEED_FAST2;
            break;
        }
    #else  /* __MMI_MEDIA_PLAYER_VIDEO_SPEED_EIGHT_MAPPING__ */
        case 1:
        {
            audio_speed = MDI_AUDIO_SPEED_NORMAL;
            break;
        }
        
        case 2:
        {
            audio_speed = MDI_AUDIO_SPEED_FAST2;
            break;
        }
        case 3:
        case 4:            
    #endif /* __MMI_MEDIA_PLAYER_VIDEO_SPEED_EIGHT_MAPPING__ */

        case 5:
        case 6:
        case 7:
        case 8:
        {
            /*when video speed is too fast to support, we will still play 
            the audio but set mure*/
            audio_speed = MDI_AUDIO_SPEED_NORMAL;
            break;
        }
        default:
            audio_speed = MDI_AUDIO_SPEED_NORMAL;
            break;            
    }

#ifdef __MMI_MEDIA_PLAYER_AUDIO__
    result = mmi_medply_settings_speed_check_before_play(audio_speed);
#else
    result = MDI_AUDIO_ERROR;
#endif
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_SETTINGS_CHECK_SET_PURE_AUDIO,g_mmi_medply_settings.video_speed,audio_speed,result);
      
    if (result != MDI_AUDIO_SUCCESS)
    {
        return MDI_AUDIO_UNSUPPORTED_SPEED;
    }
    if (!g_medply.mute)
    {
        mdi_audio_set_mute(VOL_TYPE_MEDIA,MMI_FALSE);
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX_MUTE(g_medply.volume));
    }
#ifdef __MMI_AUDIO_TIME_STRETCH__
    mdi_audio_stretch_set_speed(audio_speed);
    g_medply.speed_set_times++;
#endif
    return MDI_AUDIO_SUCCESS;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_check_mute_from_video_speed
 * DESCRIPTION
 *  check if curernt video speed shall mute if switching to pure audio
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_medply_settings_check_mute_from_video_speed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S32 index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    index = mmi_medply_settings_get_video_speed_index(g_mmi_medply_settings.video_speed);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_SETTINGS_CHECK_MUTE_FROM_VIDEO_SPEED,g_mmi_medply_settings.video_speed,index);
 
    switch(index)
    {
        case 0:
        case 1:
        case 2:
    #ifdef  __MMI_MEDIA_PLAYER_VIDEO_SPEED_EIGHT_MAPPING__
        case 3:
        case 4:
    #endif /* __MMI_MEDIA_PLAYER_VIDEO_SPEED_EIGHT_MAPPING__ */
        {
            return MMI_FALSE;
        }
    #if !defined(__MMI_MEDIA_PLAYER_VIDEO_SPEED_EIGHT_MAPPING__)
        case 3:
        case 4:
    #endif /* __MMI_MEDIA_PLAYER_VIDEO_SPEED_EIGHT_MAPPING__ */
        case 5:
        case 6:
        case 7:
        case 8:
        {
            return MMI_TRUE;
        }

        default:
        {
            return MMI_TRUE;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_get_video_speed_index
 * DESCRIPTION
 *  get speed index from video speed 
 * PARAMETERS
 *  speed  [IN]  select speed 
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_settings_get_video_speed_index(U16 speed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = MEDPLY_DEFAULT_VIDEO_SPEED;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(speed)
    {
    #ifdef __MMI_MEDIA_PLAYER_VIDEO_SPEED__ 

        case MEDPLY_FEATURE_VIDEO_SPEED_0:
            index = 0;
            break;
        case MEDPLY_FEATURE_VIDEO_SPEED_1:
            index = 1;
            break;
        case MEDPLY_FEATURE_VIDEO_SPEED_2:
            index = 2;
            break;
        case MEDPLY_FEATURE_VIDEO_SPEED_3:
            index = 3;
            break;
        case MEDPLY_FEATURE_VIDEO_SPEED_4:
            index = 4;
            break;
    #ifdef __MMI_MEDIA_PLAYER_VIDEO_SPEED_EIGHT_MAPPING__
        case MEDPLY_FEATURE_VIDEO_SPEED_5:
            index = 5;
            break;
        case MEDPLY_FEATURE_VIDEO_SPEED_6:
            index = 6;
            break;
        case MEDPLY_FEATURE_VIDEO_SPEED_7:
            index  = 7;
            break;
    #endif
    #endif /* __MMI_MEDIA_PLAYER_VIDEO_SPEED__ */
        default:
            index = MEDPLY_DEFAULT_VIDEO_SPEED;
            break;
    }
    return index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_video_set_item_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_video_set_item_value(MMI_ID inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_video_init_item_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_video_init_item_value(MMI_ID inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_icons[MEDPLY_SETTINGS_VIDEO_INLINE_ITEM_NUM];
    U16 item_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/***********************************initialize for first entry******************************************/
    g_mmi_medply_settings_video.video_brightness_id = g_mmi_medply_settings.brightness;
    g_mmi_medply_settings_video.video_contrast_id = g_mmi_medply_settings.contrast;
    g_mmi_medply_settings_video.video_speed_id = mmi_medply_settings_get_video_speed_index(g_mmi_medply_settings.video_speed);
    g_mmi_medply_settings_video.video_speed_value = g_mmi_medply_settings.video_speed;
    g_mmi_medply_settings_video.video_play_mode = g_mmi_medply_settings.play_mode;
    g_mmi_medply_settings_player.is_restored_save = MMI_FALSE;//@TODO: re-check!
/***********************************set select******************************************/
/* Set play speed */
#if defined(__MMI_MEDIA_PLAYER_VIDEO_PROCESSING_SUPPORT__)  
    cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + VIDEO_BRIGHTNESS_TYPE_SELECT, 
        (void *)g_mmi_medply_settings_video.video_brightness_id);
    cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + VIDEO_CONTRAST_TYPE_SELECT, 
        (void *)g_mmi_medply_settings_video.video_contrast_id);
#endif /*__MMI_MEDIA_PLAYER_VIDEO_PROCESSING_SUPPORT__*/

#ifdef MMI_MEDPLY_SETTINGS_VIDEO_3D_SUPPORT
    cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + VIDEO_PLAY_MODE_TYPE_SELECT, 
        (void *)g_mmi_medply_settings_video.video_play_mode);
#endif

/* Set main screen display */
#ifdef __MMI_MEDIA_PLAYER_VIDEO_SPEED__
    cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + VIDEO_SPEED_TYPE_SELECT, 
        (void *)g_mmi_medply_settings_video.video_speed_id);
#endif /* __MMI_MEDIA_PLAYER_VIDEO_SPEED__ */
/***********************************initialize icon******************************************/
    while (item_count < MEDPLY_SETTINGS_VIDEO_INLINE_ITEM_NUM)
    {
        item_icons[item_count] = IMG_GLOBAL_L1 + (item_count)/2;
        item_count++;
        item_icons[item_count++] = 0;
    }
    
    cui_inline_set_icon_list(inline_id, &item_icons[0]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_entry_video
 * DESCRIPTION
 *  entry video settings 
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_entry_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID inline_id = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_MEDPLY_SETTINGS_MAIN, GRP_ID_MEDPLY_SETTINGS_VIDEO, mmi_medply_settings_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_SETTINGS_VIDEO, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    inline_id = cui_inline_create(GRP_ID_MEDPLY_SETTINGS_VIDEO, &mmi_medply_settings_video_inline_screen);
    cui_inline_set_title_icon(inline_id, GetRootTitleIcon(MENU_ID_MEDPLY_MAIN));
    mmi_medply_settings_video_init_item_value(inline_id);
    mmi_medply_settings_video_set_item_value(inline_id);
    cui_inline_run(inline_id);
}
#endif

#ifdef MMI_MEDPLY_SETTINGS_VIDEO_3D_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_toggle_play_mode
 * DESCRIPTION
 *  check if popup string id 
 * PARAMETERS
 *  MMI_BOOL       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_settings_toggle_play_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	if(g_mmi_medply_settings.play_mode == MDI_VIDEO_TRACK_3D)
    {
        g_mmi_medply_settings.play_mode = MDI_VIDEO_TRACK_2D_NORMAL;
    }
	else
    {
        g_mmi_medply_settings.play_mode = MDI_VIDEO_TRACK_3D;
    }
}
#endif


#endif /* __MMI_MEDIA_PLAYER_VIDEO__ */

#define __SETTINGS_BT__

#if defined(__MMI_A2DP_SUPPORT__)    


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_get_a2dp_popup_string
 * DESCRIPTION
 *  check if popup string id 
 * PARAMETERS
 *  MMI_BOOL       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_medply_settings_get_a2dp_popup_string(MMI_BOOL bt_a2dp_output)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    
    #if defined(__MMI_MEDIA_PLAYER_A2DP_BLOCK_SPECTRUM__) || defined(__MMI_MEDIA_PLAYER_A2DP_BLOCK_PITCH_SHIFT__)
        if(bt_a2dp_output && mmi_frm_group_is_present (GRP_ID_MEDPLY_SETTINGS_MAIN))
        {
            return STR_ID_MEDPLY_A2DP_BLOCK_DEF;
        }
        else
    #endif
        {
            return 0;
        }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_is_output_to_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_medply_settings_is_output_to_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
         
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
   
    return mmi_a2dp_is_output_to_bt();   
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_get_bt_headset
 * DESCRIPTION
 *  retrieve the user selected bt headset
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_bt_cm_bt_addr*
 *****************************************************************************/
srv_bt_cm_bt_addr* mmi_medply_settings_get_bt_headset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      

    return mmi_a2dp_get_bt_headset();
}
#endif /* defined(__MMI_A2DP_SUPPORT__)  */

#define __SETTINGS_SUBTITLE__
#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_subtitle_iso_hilite_hdlr
 * DESCRIPTION
 *  network settings highlight  index
 * PARAMETERS
 *  index  [in] highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_settings_subtitle_iso_startup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_mmi_medply_settings_subtitle.iso_count != 0)
    {
        g_mmi_medply_settings_subtitle.iso_count = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_subtitle_iso_hilite_hdlr
 * DESCRIPTION
 *  network settings highlight  index
 * PARAMETERS
 *  index  [in] highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_settings_subtitle_iso_shutdown(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mmi_medply_settings_subtitle.iso_count = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_subtitle_iso_hilite_hdlr
 * DESCRIPTION
 *  network settings highlight  index
 * PARAMETERS
 *  index  [in] highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_settings_subtitle_iso_add_iso_element(U32 track_index, U32 iso_element)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mmi_medply_settings_subtitle.iso_list[g_mmi_medply_settings_subtitle.iso_count] = iso_element;
    g_mmi_medply_settings_subtitle.track_index_list[g_mmi_medply_settings_subtitle.iso_count] = track_index;
    mmi_li_get_lang_name(iso_element,&(g_mmi_medply_settings_subtitle.lcc_name[g_mmi_medply_settings_subtitle.iso_count]));
    g_mmi_medply_settings_subtitle.iso_count++;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_subtitle_iso_set_active_iso
 * DESCRIPTION
 *  set active subtitle by control
 * PARAMETERS
 *  index  [in] highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_settings_subtitle_iso_set_active_iso(U32 track_index, U32 iso_element)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mmi_medply_settings_subtitle.track_index_active = track_index;
    g_mmi_medply_settings_subtitle.iso_active = iso_element;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_subtitle_iso_hilite_hdlr
 * DESCRIPTION
 *  network settings highlight  index
 * PARAMETERS
 *  index  [in] highlight index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_subtitle_iso_hilite_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_medply_settings_subtitle.cur_sel_index = index;
    /* If iso_active and track_index_active were changed on highlight pressing end key in subtitle screen makes them active */
    /* these will be changed when changed the subtitle only */
    //g_mmi_medply_settings_subtitle.iso_active = g_mmi_medply_settings_subtitle.iso_list[index];
    //g_mmi_medply_settings_subtitle.track_index_active = g_mmi_medply_settings_subtitle.track_index_list[index];
}

/* MAUI_03158737 - To make saving the settings consistent - display no confirm, this function is not needed anymore */
#if 0
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) 
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_subtitle_iso_tap_callback
 * DESCRIPTION
 *  active profile 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_subtitle_iso_tap_callback(mmi_tap_type_enum tap_type,S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM)
    {
        return;
    }

    /* MAUI_03158737 - To make saving the settings consistent - display no confirm */
    mmi_medply_settings_pre_save();
    
    return;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_subtitle_is_same_iso_with_active
 * DESCRIPTION
 *  active profile 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_medply_settings_subtitle_is_same_iso_with_active(U32 iso)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* iso_lcc;
    U8* phone_lcc;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        return g_mmi_medply_settings_subtitle.iso_active == iso;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_entry_subtitle_iso_srn
 * DESCRIPTION
 *  active profile 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_entry_subtitle_iso_srn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* gui_buffer;
    U8 *str_item_list[MDI_VIDEO_MAX_SUBTITLE_NUM];
    U16 icon_item_list[MDI_VIDEO_MAX_SUBTITLE_NUM];
    U32 i;
    U32 active_index = g_mmi_medply_settings_subtitle.iso_count;
    MMI_BOOL match_track_index = MMI_FALSE;
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if( g_mmi_medply_settings_subtitle.iso_count <= 0 )
    {
        mmi_medply_settings_popup_simple_with_string((U16*)get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE), MMI_EVENT_FAILURE);
        return;
    }
    
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_SETTINGS_MAIN, SCR_ID_MEDPLY_SETTINGS_SUBTITLE_ISO, NULL, 
                        mmi_medply_settings_entry_subtitle_iso_srn, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }    
    gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MEDPLY_SETTINGS_MAIN, SCR_ID_MEDPLY_SETTINGS_SUBTITLE_ISO);
    
    i = g_mmi_medply_settings_subtitle.iso_count;
    do
    {
        i--;
        icon_item_list[i] = 0;
        str_item_list[i] = g_mmi_medply_settings_subtitle.lcc_name[i];
        
        if(match_track_index == MMI_FALSE && mmi_medply_settings_subtitle_is_same_iso_with_active(g_mmi_medply_settings_subtitle.iso_list[i]))
        {
            active_index = i;
            if(g_mmi_medply_settings_subtitle.track_index_active == g_mmi_medply_settings_subtitle.track_index_list[i])
            {
                match_track_index = MMI_TRUE;
            }
        }
    }
    while(i!=0);

    if(active_index<g_mmi_medply_settings_subtitle.iso_count)
    {
        icon_item_list[active_index] = IMG_VICON;
        /* When entering the setting screen first time, set the highlighter to current active subtitle, if any matched */
        if(gui_buffer == NULL)
        {
            g_mmi_medply_settings_subtitle.cur_sel_index = active_index;
        }
    }
    else
    {
        icon_item_list[0] = IMG_VICON;
        /* When entering the setting screen first time, set the highlighter to 0 if not matched current active */
        if(gui_buffer == NULL)
        {
            g_mmi_medply_settings_subtitle.cur_sel_index = 0;
        }
    }
    /* old_track_index can be removed as it was used to restore the track_index_active in case of no save */
    //g_mmi_medply_settings_subtitle.old_track_index = g_mmi_medply_settings_subtitle.track_index_active;
    RegisterHighlightHandler(mmi_medply_settings_subtitle_iso_hilite_hdlr);
    
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ShowCategory73Screen(
        STR_ID_MEDPLY_SETTINGS_SUBTITLE_LANGUAGE,
        GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
        STR_GLOBAL_OK,
        STR_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_mmi_medply_settings_subtitle.iso_count,
        str_item_list,
        (U16*)icon_item_list,
        (U16*)gIndexIconsImageList,
        (S32)g_mmi_medply_settings_subtitle.cur_sel_index,
        gui_buffer,
        ICON_ICON_TEXT);
    #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) 
        wgui_register_tap_callback(mmi_medply_settings_subtitle_iso_tap_callback);
    #endif

    /* MAUI_03158737 - To make saving the settings consistent - display no confirm */
    SetCenterSoftkeyFunction(mmi_medply_settings_pre_save, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_medply_settings_pre_save,KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_medply_settings_pre_no_save,KEY_EVENT_UP);
    
}

#endif

#define __SETTINGS_NETWORK__

#if defined(__MMI_MEDIA_PLAYER_STREAM__) 

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_medply_settings_network_profile_tap_callback(mmi_tap_type_enum tap_type,S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM)
    {
        return;
    }

    mmi_medply_settings_network_active_profile();
    
    return;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_register_bear_event
 * DESCRIPTION
 *  network settings data account change handler
 * PARAMETERS
 *  param  [in] event struct
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_medply_register_bear_event(mmi_proc_func callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_result_error_enum ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_cbm_register_bearer_event(
                      SRV_CBM_BEARER_EVENT_SWITCH,
                      g_mmi_medply_settings_network_profile.cbm_app_id,
                      callback,
                      0);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_BEARER_REG, ret);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_register_bear_event
 * DESCRIPTION
 *  network settings data account change handler
 * PARAMETERS
 *  param  [in] event struct
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_medply_deregister_bear_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_result_error_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ret = srv_cbm_deregister_bearer_event(g_mmi_medply_settings_network_profile.cbm_app_id);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_BEARER_DEREG, ret);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_register_bear_info
 * DESCRIPTION
 *  network settings data account change handler
 * PARAMETERS
 *  param  [in] event struct
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_register_bear_info(mmi_proc_func callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_result_error_enum ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_cbm_register_bearer_info(
        g_mmi_medply_settings_network_profile.cbm_app_id, 
        CBM_DEACTIVATED | CBM_ACTIVATED, 
        CBM_PS | CBM_WIFI, 
        callback, 
        NULL);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_BEARER_REG, ret);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_deregister_bear_info
 * DESCRIPTION
 *  network settings data account change handler
 * PARAMETERS
 *  param  [in] event struct
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_medply_deregister_bear_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_result_error_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ret = srv_cbm_deregister_bearer_info(g_mmi_medply_settings_network_profile.cbm_app_id);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_BEARER_DEREG, ret);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_sim_unavailable_hdlr
 * DESCRIPTION
 *  network settings data account change handler
 * PARAMETERS
 *  event  [in] event struct
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_medply_settings_sim_unavailable_hdlr(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_SIM_UNAVAILABLE, param->evt_id);
    if (EVT_ID_SRV_SIM_CTRL_UNAVAILABLE == param->evt_id && 
    	  mmi_frm_group_is_present(GRP_ID_MEDPLY_PROFILE_EDIT))
    {
    	  MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_SIM_UNAVAILABLE, param->evt_id);
        mmi_frm_group_close(GRP_ID_MEDPLY_PROFILE_EDIT);
    }
        
    return MMI_RET_OK;
  }


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_dtcnt_changed_hdlr
 * DESCRIPTION
 *  network settings data account change handler
 * PARAMETERS
 *  param  [in] event struct
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_medply_settings_dtcnt_changed_hdlr(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_account_info_struct info;
    U32 data_acct;
    U32 i,j;
    nvram_ef_medply_settings_profile_struct *profile_p;
    U32 sim_id;
    U32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_DTCNT_CHANGED, param->evt_id);
    switch(param->evt_id)
    {
        case EVT_ID_SRV_DTCNT_ACCT_DELETE_IND:
        {
            for(index = 0; index < NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_TOTAL; index++)
            {
                profile_p = &(g_mmi_medply_settings_network_profile.network_profile[index]);
    
                for(sim_id = 0; sim_id < MMI_MAX_SIM_NUM; sim_id++)
                {
                    data_acct = cbm_set_app_id(profile_p->data_account_id[sim_id], g_mmi_medply_settings_network_profile.cbm_app_id);
                    if (cbm_decode_data_account_id_ext(data_acct, &info) == CBM_OK)
                    {
                        srv_dtcnt_acct_delete_ind_evt_struct *event = (srv_dtcnt_acct_delete_ind_evt_struct *)param;
                        for (i = 0; i < info.acct_num; i++)
                        {
                            for (j = 0; j < event->del_num; j++)
                            {
                                if (event->acc_id[j] == info.account[i].account_id)
                                {   
                                    data_acct = CBM_DEFAULT_ACCT_ID;
                                    mmi_medply_settings_set_data_account(data_acct);
                                }
                            }
       }         
    }
                 }
            }
        }
        break;
        
        case EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND:          
        {
            for(index = 0; index < NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_TOTAL; index++)
            {
                profile_p = &(g_mmi_medply_settings_network_profile.network_profile[index]);
    
                for(sim_id = 0; sim_id < MMI_MAX_SIM_NUM; sim_id++)
                {
                    data_acct = cbm_set_app_id(profile_p->data_account_id[sim_id], g_mmi_medply_settings_network_profile.cbm_app_id);
                    if (cbm_decode_data_account_id_ext(data_acct, &info) == CBM_OK)
                    {
                        srv_dtcnt_acct_update_ind_evt_struct *event = (srv_dtcnt_acct_update_ind_evt_struct *)param;
                        for (i = 0; i < info.acct_num; i++)
                        {
                            if (event->acc_id == info.account[i].account_id && event->cause ==  1)
                            {
                                srv_dtcnt_bearer_enum bearer = srv_dtcnt_get_bearer_type(event->acc_id, SRV_DTCNT_ACCOUNT_PRIMARY);
                                if (bearer != SRV_DTCNT_BEARER_GPRS && bearer != SRV_DTCNT_BEARER_WIFI)
                                {
                                    data_acct = CBM_DEFAULT_ACCT_ID;
                                    mmi_medply_settings_set_data_account(data_acct);
                                }
                            }
                        }
                    }
                }
            }
        }
        break;
        default: 
            break;
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_settings_set_data_account
* DESCRIPTION
*  set network profile data account
* PARAMETERS
*  void
* RETURNS           
*  void
*****************************************************************************/
static MMI_BOOL mmi_medply_settings_set_data_account(U32 data_account)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_medply_settings_profile_struct* prof_p;
    S16 error;
    U8 index;
    srv_dtcnt_sim_type_enum sim_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = g_mmi_medply_settings_network_profile.active_profile_idx;

    if (index >= NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_TOTAL)
    {
        index = 0;
    }
    
    prof_p = &(g_mmi_medply_settings_network_profile.network_profile[index]);

    sim_type = mmi_medply_settings_get_data_account_sim_type();
    prof_p->data_account_id[sim_type - SRV_DTCNT_SIM_TYPE_1] = data_account;

    WriteRecord(
         NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_LID, 
         index + 1,  /* id start from 1 */ 
         (void*)prof_p, 
         NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_SIZE, 
         &error);
     
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_network_highlight_hdlr
 * DESCRIPTION
 *  network settings highlight  index
 * PARAMETERS
 *  index  [in] highlight index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_network_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_medply_settings_network_profile.cur_sel_profile_idx = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_network_active_profile
 * DESCRIPTION
 *  active profile 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_network_active_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_medply_settings_network_profile.active_profile_idx = g_mmi_medply_settings_network_profile.cur_sel_profile_idx;
    WriteValue(NVRAM_EF_MEDPLY_SETTINGS_ACTIVE_PROFILE_INX, &g_mmi_medply_settings_network_profile.active_profile_idx,DS_BYTE,&error);
/*bql: apply new UE design to avoid success popup */
#if 1
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
	{
        mmi_id dummy_gid = 0; 
        dummy_gid = mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, NULL, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        mmi_frm_display_dummy_screen();
        mmi_frm_group_close(dummy_gid);
    }

#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


static mmi_ret mmi_medply_settings_dacnt_cui_proc(mmi_event_struct *evt) 
{

	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dtcnt_select_event_any_sim_selected_struct  *event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event = (cui_dtcnt_select_event_any_sim_selected_struct*)evt;

    switch (evt->evt_id)
    {
        case CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:
        {
            g_mmi_medply_settings_network_profile.inline_data_account_id[event->selectSim - CUI_DTCNT_SIM1] = 
                event->accountId;
            if(mmi_medply_settings_get_data_account_sim_type() - SRV_DTCNT_SIM_TYPE_1 == event->selectSim)
            {
                mmi_dtcnt_get_full_account_name(event->accountId,
                    (CHAR*)g_mmi_medply_settings_network_profile.data_account_name,
                    (MAX_DATA_ACCOUNT_NAME_LEN + DATA_ACCOUNT_NAME_SUFFIX_LEN + 1)*ENCODING_LENGTH, MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);              
            }                         
            break;
        }            

        case CUI_DTCNT_SELECT_EVENT_RESULT_OK:
        case CUI_DTCNT_SELECT_EVENT_RESULT_FAILED:
        case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
        case CUI_DTCNT_SELECT_EVENT_CLOSE:
            cui_dtcnt_select_close(event->sender_id);      
            break;

        default:
            break;
	}
    return MMI_RET_OK;
}


static void mmi_medply_settings_entry_data_accout_cui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dtcnt_select_run_struct para;
    MMI_ID gid = GRP_ID_INVALID;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    for (i = 0; i < MMI_MAX_SIM_NUM; i++)
    {
        para.sim_account_id[i] = g_mmi_medply_settings_network_profile.inline_data_account_id[i];
    }

    para.AppMenuID = MENU_ID_MEDPLY_MAIN;
    para.app_id =  g_mmi_medply_settings_network_profile.cbm_app_id;
    para.bearers = DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_WIFI;
    para.sim_selection = CUI_DTCNT_SELECT_SIM_ALL;
    para.option = CUI_DTCNT_SELECT_DEFAULT;
    para.type = CUI_DTCNT_SELECT_TYPE_NORMAL;
    para.str_id = STR_GLOBAL_DATA_ACCOUNT;
    para.icon_id = GetRootTitleIcon(MENU_ID_MEDPLY_MAIN);

    mmi_frm_group_create(GRP_ID_MEDPLY_PROFILE_EDIT, GRP_ID_MEDPLY_DATA_ACCOUNT, mmi_medply_settings_dacnt_cui_proc, NULL);
    mmi_frm_group_enter(GRP_ID_MEDPLY_DATA_ACCOUNT, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    gid = cui_dtcnt_select_create(GRP_ID_MEDPLY_DATA_ACCOUNT);
    if(gid != GRP_ID_INVALID)
    {
        cui_dtcnt_select_set_param(gid, &para);
        cui_dtcnt_select_run(gid);
    }
    else
    {
        mmi_frm_group_close(GRP_ID_MEDPLY_DATA_ACCOUNT);
    }
}

void mmi_medply_settings_get_data_account_id(U32 *data_account_id)
{
#if defined(__MMI_MEDIA_PLAYER_STREAM__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_medply_settings_profile_struct *profile_p;
    srv_dtcnt_sim_type_enum sim_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_PROFILE,(void*)&profile_p);
    
    sim_type = mmi_medply_settings_get_data_account_sim_type();
    *data_account_id = cbm_encode_data_account_id(
							  profile_p->data_account_id[sim_type-SRV_DTCNT_SIM_TYPE_1],
                                      (cbm_sim_id_enum)(sim_type - SRV_DTCNT_SIM_TYPE_1),
                                      g_mmi_medply_settings_network_profile.cbm_app_id,
                                      KAL_FALSE);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_CURRENT_DATA_ACCOUNT,*data_account_id);
#endif
}
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_network_profile_is_changed
 * DESCRIPTION
 *  check the network profile changed or not 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_medply_settings_network_profile_is_changed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_medply_settings_profile_struct *profile_p;
    S32 proxy_port;
    S32 highest_udp_port;
    S32 lowest_udp_port;
    CHAR temp_inline_profile_name[MMI_MEDPLY_MAX_PROFILE_NAME_BUF_SIZE];  
    CHAR inline_profile_name[MMI_MEDPLY_MAX_PROFILE_NAME_BUF_SIZE];  
    U8 inline_proxy_port[(MMI_MEDPLY_MAX_PORT_LEN)*ENCODING_LENGTH];
    U8 inline_highest_udp_port[(MMI_MEDPLY_MAX_PORT_LEN)*ENCODING_LENGTH];
    U8 inline_lowest_udp_port[(MMI_MEDPLY_MAX_PORT_LEN)*ENCODING_LENGTH];
    MMI_ID inline_gid = GRP_ID_INVALID;
    CHAR inline_proxy_name_asc[VIDEO_MAX_PROXY_ADDR_LEN];
    CHAR inline_proxy_name[MMI_MEDPLY_MAX_PROXY_ADDR_BUF_SIZE];
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_gid = g_mmi_medply_settings_network_profile.inline_gid;
    profile_p = &g_mmi_medply_settings_network_profile.network_profile[g_mmi_medply_settings_network_profile.cur_sel_profile_idx];
    
    cui_inline_get_value(inline_gid, CUI_INLINE_ITEM_ID_BASE + PROFILE_NAME_TYPE_FULLSCREEN_EDIT, (void *) inline_profile_name);
    if (mmi_ucs2strlen((CHAR*)profile_p->profile_name))
    {
        mmi_ucs2ncpy((CHAR*)temp_inline_profile_name, 
                 (CHAR*)profile_p->profile_name, 
                 MMI_MEDPLY_MAX_PROFILE_NAME_BUF_SIZE); 
    }
    else
    {
        mmi_ucs2ncpy((CHAR*)temp_inline_profile_name, 
                 (CHAR*)GetString((U16) STR_ID_MEDPLY_SETTINGS_PROFILE1 + g_mmi_medply_settings_network_profile.cur_sel_profile_idx), 
                 MMI_MEDPLY_MAX_PROFILE_NAME_BUF_SIZE);
    }
    
    if (mmi_ucs2cmp((CHAR*)inline_profile_name, (CHAR*)temp_inline_profile_name) != 0)
    {
        return MMI_TRUE;
    }

    for(i = 0; i < MMI_MAX_SIM_NUM; i++)
    {
        if (g_mmi_medply_settings_network_profile.inline_data_account_id[i] != profile_p->data_account_id[i])
        {
            return MMI_TRUE;
        }
    }

    if (g_mmi_medply_settings_network_profile.inline_proxy_on_off != profile_p->proxy_on_off)
    {
        return MMI_TRUE;
    }


    cui_inline_get_value(inline_gid, CUI_INLINE_ITEM_ID_BASE + PROXY_SERVER_TYPE_FULLSCREEN_EDIT, (void *) &inline_proxy_name);
    kal_sprintf(inline_proxy_name_asc, "%w", inline_proxy_name);
    if (app_stricmp((CHAR*)profile_p->proxy_addr, (CHAR*)inline_proxy_name_asc) != 0)
    {
        return MMI_TRUE;
    }

    cui_inline_get_value(inline_gid, CUI_INLINE_ITEM_ID_BASE + PROXY_PORT_TYPE_TEXT_EDIT, (void *) inline_proxy_port);
    cui_inline_get_value(inline_gid, CUI_INLINE_ITEM_ID_BASE + LOWEST_UDP_TYPE_TEXT_EDIT, (void *) inline_lowest_udp_port);
    cui_inline_get_value(inline_gid, CUI_INLINE_ITEM_ID_BASE + HIGHST_UDP_TYPE_TEXT_EDIT, (void *) inline_highest_udp_port);
    proxy_port = gui_atoi((UI_string_type)&inline_proxy_port);     
    lowest_udp_port = gui_atoi((UI_string_type)&inline_lowest_udp_port);     
    highest_udp_port = gui_atoi((UI_string_type)&inline_highest_udp_port);  

    if (profile_p->proxy_port != proxy_port ||
        profile_p->highest_udp_port!= highest_udp_port ||
        profile_p->lowest_udp_port != lowest_udp_port)

    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_network_option
 * DESCRIPTION
 *  network profile option  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_network_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_gid = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_MEDPLY_SETTINGS_MAIN, GRP_ID_MEDPLY_NETWORK_OPTION, mmi_medply_settings_proc, (void*)NULL); 
    
    mmi_frm_group_enter(GRP_ID_MEDPLY_NETWORK_OPTION, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    cui_gid = cui_menu_create(
                            GRP_ID_MEDPLY_NETWORK_OPTION,
                            CUI_MENU_SRC_TYPE_RESOURCE,
                            CUI_MENU_TYPE_OPTION,
                            MENU_ID_MEDPLY_SETTINGS_NETWORK_OPTION,
                            MMI_FALSE, NULL);
    if (cui_gid > GRP_ID_INVALID)
    {
        cui_menu_set_default_title_image(cui_gid, (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)));
        cui_menu_run(cui_gid);
    }
    else
    {   
        mmi_medply_settings_popup_simple_with_string((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_pre_entry_network
 * DESCRIPTION
 *  check the data account ready
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_pre_entry_network(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if(mmi_dtcnt_ready_check(mmi_medply_settings_entry_network, MMI_TRUE))
    {
        mmi_medply_settings_entry_network();
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_entry_network
 * DESCRIPTION
 *  entry network settings   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_entry_network(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* gui_buffer;
    U8 *str_item_list[NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_TOTAL];
    U16 icon_item_list[NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_TOTAL];
    S32 i;
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_SETTINGS_MAIN, SCR_ID_MEDPLY_SETTINGS_NETWORK, NULL, mmi_medply_settings_entry_network, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }    
    gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MEDPLY_SETTINGS_MAIN, SCR_ID_MEDPLY_SETTINGS_NETWORK);
    
    if (!gui_buffer)
    {
        g_mmi_medply_settings_network_profile.cur_sel_profile_idx = g_mmi_medply_settings_network_profile.active_profile_idx;
    }
    for (i = 0;i < NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_TOTAL;i++)
    {
        if (mmi_ucs2strlen((CHAR*)(U8*)g_mmi_medply_settings_network_profile.network_profile[i].profile_name))
        {
            str_item_list[i] = (U8*)g_mmi_medply_settings_network_profile.network_profile[i].profile_name;
        }
        else
        {
            str_item_list[i] = (U8*)GetString((U16)(STR_ID_MEDPLY_SETTINGS_PROFILE1 + i));
        }
        if( i == g_mmi_medply_settings_network_profile.active_profile_idx)
        {
            icon_item_list[i] = IMG_VICON;
        }
        else 
        {
            icon_item_list[i] = 0;
        }
    }
    RegisterHighlightHandler(mmi_medply_settings_network_highlight_hdlr);
    
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ShowCategory73Screen(
        STR_ID_MEDPLY_SETTINGS_NETWORK,
        GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_TOTAL,
        str_item_list,
        (U16*)icon_item_list,
        (U16*)gIndexIconsImageList,
        (S32)g_mmi_medply_settings_network_profile.cur_sel_profile_idx,
        NULL,
        ICON_ICON_TEXT);
	#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_tap_callback(mmi_medply_settings_network_profile_tap_callback);
    #endif
    
    SetCenterSoftkeyFunction(mmi_medply_settings_network_active_profile, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_medply_settings_network_option,KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id,KEY_EVENT_UP);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_profile_edit_set_item_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_profile_edit_set_item_value(MMI_ID inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_profile_edit_init_item_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_profile_edit_init_item_value(MMI_ID inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 encode_dtcnt_id;
    U16 item_icons[MEDPLY_SETTINGS_PROFILE_INLINE_ITEM_NUM];
    U16 item_count = 0;
    U16 item_total = MEDPLY_SETTINGS_PROFILE_INLINE_ITEM_NUM;
    U8 index = 0;
    nvram_ef_medply_settings_profile_struct *profile_p;
    cui_inline_item_ip4_struct proxy_server;
    CHAR inline_profile_name[MMI_MEDPLY_MAX_PROFILE_NAME_BUF_SIZE];
    U8 inline_proxy_port[(MMI_MEDPLY_MAX_PORT_LEN)*ENCODING_LENGTH];
    U8 inline_highest_udp_port[(MMI_MEDPLY_MAX_PORT_LEN)*ENCODING_LENGTH];
    U8 inline_lowest_udp_port[(MMI_MEDPLY_MAX_PORT_LEN)*ENCODING_LENGTH];
    CHAR inline_proxy_name[MMI_MEDPLY_MAX_PROXY_ADDR_BUF_SIZE];
    U32 i;
    srv_dtcnt_sim_type_enum sim_type;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
/***********************************initialize for first entry******************************************/
    index = g_mmi_medply_settings_network_profile.cur_sel_profile_idx;
    profile_p = &g_mmi_medply_settings_network_profile.network_profile[index];
    g_mmi_medply_settings_network_profile.inline_gid = inline_id;
    
    g_mmi_medply_settings_network_profile.inline_proxy_on_off = profile_p->proxy_on_off;

    for (i = 0; i < MMI_MAX_SIM_NUM; i++ )
    {
       g_mmi_medply_settings_network_profile.inline_data_account_id[i] = profile_p->data_account_id[i];
    }
    
    if (mmi_ucs2strlen((CHAR*) profile_p->profile_name))
    {
        mmi_ucs2ncpy(inline_profile_name, (CHAR*)profile_p->profile_name, MMI_MEDPLY_MAX_PROFILE_NAME_BUF_SIZE);
    }
    else
    {
        mmi_ucs2ncpy(inline_profile_name, 
            (CHAR*)GetString((U16) STR_ID_MEDPLY_SETTINGS_PROFILE1 + index ), MMI_MEDPLY_MAX_PROFILE_NAME_BUF_SIZE);
    }

    if (mmi_ucs2strlen((CHAR*)profile_p->proxy_addr))
    {
        kal_wsprintf((WCHAR *)inline_proxy_name, "%s", (CHAR*)profile_p->proxy_addr);
    }
    else
    {
        kal_wsprintf((WCHAR *)inline_proxy_name,  "0.0.0.0");
    }
    
    gui_itoa(profile_p->proxy_port, (UI_string_type)inline_proxy_port, 10);        
    gui_itoa(profile_p->highest_udp_port, (UI_string_type)inline_highest_udp_port, 10);
    gui_itoa(profile_p->lowest_udp_port, (UI_string_type)inline_lowest_udp_port, 10);
/***********************************set/init select******************************************/
/* Set profile name */
    cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + PROFILE_NAME_TYPE_FULLSCREEN_EDIT, 
        (void *)inline_profile_name);
    cui_inline_set_fullscreen_edit_title_icon(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + PROFILE_NAME_TYPE_FULLSCREEN_EDIT,
        GetRootTitleIcon(MENU_ID_MEDPLY_MAIN));

/* Set data account */
    /*mmi_dtcnt_get_single_account_name(
        g_mmi_medply_settings_network_profile.inline_data_account_id,
        (CHAR*)g_mmi_medply_settings_network_profile.data_account_name,
        MAX_DATA_ACCOUNT_NAME_LEN);*/

    for (i = 0; i < MMI_MAX_SIM_NUM; i++ )
    {
        encode_dtcnt_id = cbm_set_app_id(g_mmi_medply_settings_network_profile.inline_data_account_id[i], g_mmi_medply_settings_network_profile.cbm_app_id);      
        if(mmi_dtcnt_acct_is_valid(encode_dtcnt_id) == MMI_DTCNT_ACCT_VALID_NONE )
        {
            g_mmi_medply_settings_network_profile.inline_data_account_id[i] = CBM_DEFAULT_ACCT_ID;
            profile_p->data_account_id[i] = CBM_DEFAULT_ACCT_ID;
        }
    }
    
    sim_type = mmi_medply_settings_get_data_account_sim_type();
        
    encode_dtcnt_id = cbm_encode_data_account_id(
                          g_mmi_medply_settings_network_profile.inline_data_account_id[sim_type - SRV_DTCNT_SIM_TYPE_1],
                          (cbm_sim_id_enum)(sim_type - SRV_DTCNT_SIM_TYPE_1),
                          g_mmi_medply_settings_network_profile.cbm_app_id,
                          KAL_FALSE);
    
    mmi_dtcnt_get_full_account_name(encode_dtcnt_id,
        (CHAR*)g_mmi_medply_settings_network_profile.data_account_name,
        (MAX_DATA_ACCOUNT_NAME_LEN + DATA_ACCOUNT_NAME_SUFFIX_LEN + 1)*ENCODING_LENGTH, MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);  
    cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + DATA_ACCOUNT_TYPE_DISPLAY_ONLY, 
        (void *)g_mmi_medply_settings_network_profile.data_account_name);

/* Set use proxy */
    cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + USE_PROXY_TYPE_SELECT, 
        (void *)g_mmi_medply_settings_network_profile.inline_proxy_on_off);

/* Set proxy server */
    cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + PROXY_SERVER_TYPE_FULLSCREEN_EDIT, 
        (void *)inline_proxy_name);

/* Set proxy port */
    cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + PROXY_PORT_TYPE_TEXT_EDIT, 
        (void *)inline_proxy_port);

/* Set lowest udp */
    cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + LOWEST_UDP_TYPE_TEXT_EDIT, 
        (void *)inline_lowest_udp_port);

/* Set highest udp */
    cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + HIGHST_UDP_TYPE_TEXT_EDIT, 
        (void *)inline_highest_udp_port);
    

/***********************************initialize icon******************************************/
    ret = srv_dtcnt_get_sim_preference(&sim_type);
    if(SRV_DTCNT_SIM_TYPE_NONE == sim_type || ret == MMI_FALSE)
    {
        cui_inline_delete_item(inline_id, CUI_INLINE_ITEM_ID_BASE + DATA_ACCOUNT_TYPE_CAPTION);
        cui_inline_delete_item(inline_id, CUI_INLINE_ITEM_ID_BASE + DATA_ACCOUNT_TYPE_DISPLAY_ONLY);
        item_total -= 2;
    }

    while (item_count < item_total)
    {
        item_icons[item_count] = IMG_GLOBAL_L1 + (item_count)/2;
        item_count++;
        item_icons[item_count++] = 0;
    }
    
    cui_inline_set_icon_list(inline_id, &item_icons[0]);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_entry_edit_profile
 * DESCRIPTION
 *  entry profile edit   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_settings_entry_edit_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID inline_id = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_MEDPLY_SETTINGS_MAIN, GRP_ID_MEDPLY_PROFILE_EDIT, mmi_medply_settings_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_PROFILE_EDIT, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    inline_id = cui_inline_create(GRP_ID_MEDPLY_PROFILE_EDIT, &mmi_medply_settings_profile_inline_screen);
    cui_inline_set_title_icon(inline_id, GetRootTitleIcon(MENU_ID_MEDPLY_MAIN));
    mmi_medply_settings_profile_edit_init_item_value(inline_id);
    mmi_medply_settings_profile_edit_set_item_value(inline_id);
    cui_inline_run(inline_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_get_data_account_sim_type
 * DESCRIPTION
 *  entry profile edit   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_dtcnt_sim_type_enum mmi_medply_settings_get_data_account_sim_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    srv_dtcnt_sim_type_enum sim_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_dtcnt_get_sim_preference(&sim_type);
    if(ret == MMI_FALSE || sim_type == SRV_DTCNT_SIM_TYPE_NONE)
    {
        sim_type = SRV_DTCNT_SIM_TYPE_1;
    }
    return sim_type;
}

#endif /* __MMI_MEDIA_PLAYER_STREAM__ */
    

#ifdef __MMI_TOUCH_SCREEN__ 
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_toggle_repeat
 * DESCRIPTION
 *  toogle and save the repeat setting  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_settings_toggle_repeat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 repeat = g_mmi_medply_settings.repeat;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    repeat ++ ;

    if(repeat>2)
    {
        repeat = 0 ;
    }

   g_mmi_medply_settings.repeat = repeat;

#ifdef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
    mmi_medply_settings_repeat_change(g_mmi_medply_settings.repeat);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_toggle_shuffle
 * DESCRIPTION
 *  toogle and save the shuffle setting  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_settings_toggle_shuffle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 shuffle = g_mmi_medply_settings.is_shuffle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    shuffle ++ ;

    if(shuffle>1)
    {
        shuffle = 0 ;
    }

    g_mmi_medply_settings.is_shuffle = shuffle;

#ifdef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
    mmi_medply_settings_shuff_change(g_mmi_medply_settings.is_shuffle);
#endif
    mmi_medply_shuffle_change_callback(g_mmi_medply_settings.is_shuffle);
}
#endif /*__MMI_TOUCH_SCREEN__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_read_value
 * DESCRIPTION
 *  read value   
 * PARAMETERS
 *  enum_value    [IN]  read value enum
 *  data_value    [?]      
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_medply_settings_read_value(mmi_medply_settings_type_enum enum_value, void * data_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* on_off_flag;
    U8** skin_file_path;
    U8* drv_index;
    U16* play_speed;
    S16* index_value;
#if defined(__MMI_A2DP_SUPPORT__)
    srv_bt_cm_bt_addr** bt_value;
#endif
#if defined(__MMI_MEDIA_PLAYER_STREAM__) 
    nvram_ef_medply_settings_profile_struct** temp_profile;
    U32 encode_id;
    srv_dtcnt_sim_type_enum sim_type;
#endif

    #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    U32* iso;
    U32* track_index;
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (enum_value >= MMI_MEDPLY_SETTINGS_TYPE_ALL)
    {
        mmi_medply_settings_popup_simple_with_string(
            (U16*)get_string(STR_ID_MEDPLY_ERROR_TYPE_INDEX), 
            MMI_EVENT_ERROR);
        return MMI_FALSE;
    }
    
    switch(enum_value)
    {
        case MMI_MEDPLY_SETTINGS_SKIN_INDEX:
            on_off_flag = (U8*)data_value;
            *on_off_flag = g_mmi_medply_settings.is_theme_default;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_SETTINGS_SKIN_INDEX,*on_off_flag);
            break;
            
        case MMI_MEDPLY_SETTINGS_SKIN_PATH:
            skin_file_path = (U8**) data_value;
            mmi_ucs2cpy((CHAR *)skin_file_path , (CHAR *)g_mmi_medply_settings.skin_custom_path);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_SETTINGS_SKIN_PATH,*skin_file_path);
            break;
        
        case MMI_MEDPLY_SETTINGS_DEFAULT_STORAGE:
            drv_index = (U8*) data_value;
            *drv_index = g_mmi_medply_settings.default_storage_drv_letter;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_SETTINGS_CURRENT_DRV,g_mmi_medply_settings.default_storage_drv_letter );
            break;
            
        case MMI_MEDPLY_SETTINGS_BG_PLAY:
            on_off_flag = (U8 *)data_value;
            *on_off_flag = g_mmi_medply_settings.is_bgplay;
        #if defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__)
            *on_off_flag = 1;  
        #endif
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_SETTINGS_BACKGROUND_PLAY,*on_off_flag);
            break;
   
        case MMI_MEDPLY_SETTINGS_REPEAT:
            on_off_flag = (U8*)data_value;
            *on_off_flag = g_mmi_medply_settings.repeat;
             MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_SETTINGS_REPEAT,*on_off_flag);
            break;
            
        case MMI_MEDPLY_SETTINGS_SHUFFULE:
            on_off_flag = (U8*)data_value;
            *on_off_flag = g_mmi_medply_settings.is_shuffle;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_SETTINGS_SHUFFLE,*on_off_flag);
            break;
            
        case MMI_MEDPLY_SETTINGS_MOTIONSENSOR:
           on_off_flag = (U8*)data_value;

           #ifdef MOTION_SENSOR_SUPPORT
              *on_off_flag = g_mmi_medply_settings.is_autofulscr_by_sensor;
           #else
              *on_off_flag = 0;
           #endif 
           MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_SETTINGS_MOTION_FLAG, *on_off_flag);
           break;           
        case MMI_MEDPLY_SETTINGS_AUDIO_SPEED:

            if (g_mmi_medply_settings.audio_speed == 0)
            {
                g_mmi_medply_settings.audio_speed = MDI_AUDIO_SPEED_NORMAL;
            }
            play_speed = (U16*)data_value;
            *play_speed = g_mmi_medply_settings.audio_speed;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_SETTINGS_AUDIO_SPEED,*play_speed);
            break;
        
        case MMI_MEDPLY_SETTINGS_MAINSCR_DISP:
            on_off_flag = (U8*)data_value;
            *on_off_flag = g_mmi_medply_settings.mainscrdisp_index;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_SETTINGS_MAINSCR_DISPLAY,*on_off_flag);
            break;
        
        case MMI_MEDPLY_SETTINGS_BRIGHTNESS:
            index_value = (S16*)data_value;
            *index_value = g_mmi_medply_settings.brightness;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_SETTINGS_BRIGHTNESS,*index_value);
            break;
        
        case MMI_MEDPLY_SETTINGS_CONTRAST:
            index_value = (S16*)data_value;
            *index_value = g_mmi_medply_settings.contrast;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_SETTINGS_CONTRAST,*index_value);
            break;
        
        case MMI_MEDPLY_SETTINGS_VIDEO_SPEED:
            if (g_mmi_medply_settings.video_speed == 0)
            {
                g_mmi_medply_settings.video_speed = 100;
            }
            play_speed = (U16*)data_value;
            *play_speed = g_mmi_medply_settings.video_speed;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_SETTINGS_VIDEO_SPEED,*play_speed);
            break;
            
	    case MMI_MEDPLY_SETTINGS_PLAY_MODE:
            index_value = (S16*)data_value;
            *index_value = g_mmi_medply_settings.play_mode;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_SETTINGS_BRIGHTNESS,*index_value);
            break;
            
        case MMI_MEDPLY_SETTINGS_BT_OUTPUT:
        #if defined(__MMI_A2DP_SUPPORT__)
            on_off_flag = (U8*) data_value;
            *on_off_flag = mmi_medply_settings_is_output_to_bt();
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_SETTINGS_BT_OUTPUT,*on_off_flag);
        #endif
            break;
            
        case MMI_MEDPLY_SETTINGS_BT_HEADSET:
        #if defined(__MMI_A2DP_SUPPORT__)
            bt_value = (srv_bt_cm_bt_addr**)data_value;
            *bt_value = mmi_medply_settings_get_bt_headset();
        #endif
            break;
        
        case MMI_MEDPLY_SETTINGS_ACTIVE_PROFILE_IDX:
        #if defined(__MMI_MEDIA_PLAYER_STREAM__) 
            on_off_flag = (U8*)data_value;
            *on_off_flag = g_mmi_medply_settings_network_profile.active_profile_idx;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_SETTINGS_PROFILE_INDEX,*on_off_flag);
        #endif /*defined(__MMI_MEDIA_PLAYER_STREAM__) */
            break;
            
        case MMI_MEDPLY_SETTINGS_PROFILE:
        #if defined(__MMI_MEDIA_PLAYER_STREAM__) 
            temp_profile = (nvram_ef_medply_settings_profile_struct **)data_value;
            *temp_profile = &(g_mmi_medply_settings_network_profile.network_profile[g_mmi_medply_settings_network_profile.active_profile_idx]);
            sim_type = mmi_medply_settings_get_data_account_sim_type();
            encode_id = cbm_set_app_id((*temp_profile)->data_account_id[sim_type-SRV_DTCNT_SIM_TYPE_1], g_mmi_medply_settings_network_profile.cbm_app_id);
            if(mmi_dtcnt_acct_is_valid(encode_id) == MMI_DTCNT_ACCT_VALID_NONE )
            {
                (*temp_profile)->data_account_id[sim_type-SRV_DTCNT_SIM_TYPE_1] = CBM_DEFAULT_ACCT_ID;
            }
        #endif /* defined(__MMI_MEDIA_PLAYER_STREAM__)  */
            break;
        
         case MMI_MEDPLY_SETTINGS_SUBTITLE_LCC:
            #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
            if(g_mmi_medply_settings_subtitle.has_inited==MMI_FALSE)
            {
                return MMI_FALSE;
            }
            iso = data_value;
            *iso = g_mmi_medply_settings_subtitle.iso_active;
            #endif
            break;

        case MMI_MEDPLY_SETTINGS_SUBTITLE_TRACK_INDEX:
            #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
            if(g_mmi_medply_settings_subtitle.has_inited==MMI_FALSE || g_mmi_medply_settings_subtitle.iso_count == 0)
            {
                return MMI_FALSE;
            }
            track_index = data_value;
            *track_index = g_mmi_medply_settings_subtitle.track_index_active;
            #endif
            break;
        
        default:
             break;
            
        //return MMI_FALSE;
        }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_write_value
 * DESCRIPTION
 *  write value to NVRAM   
 * PARAMETERS
 *  enum_value    [IN]  read value enum
 *  data_value    [?]      
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_medply_settings_write_value(mmi_medply_settings_type_enum enum_value, void* data_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* index;
    S16 pError;
    #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
	U32 *iso;
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (enum_value)
    {
        case MMI_MEDPLY_SETTINGS_DEFAULT_STORAGE:
            index = (U8*)data_value;
            g_mmi_medply_settings.default_storage_drv_letter = *index;
            WriteRecord(NVRAM_EF_MEDPLY_SETTINGS_LID,1, (void*)&g_mmi_medply_settings, NVRAM_EF_MEDPLY_SETTINGS_SIZE, &pError);
            break;
            
        case MMI_MEDPLY_SETTINGS_REPEAT:
            index = (U8*)data_value;
            g_mmi_medply_settings.repeat = *index;
         #ifdef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
            mmi_medply_settings_repeat_change(g_mmi_medply_settings.repeat);
         #endif
            WriteRecord(NVRAM_EF_MEDPLY_SETTINGS_LID,1, (void*)&g_mmi_medply_settings, NVRAM_EF_MEDPLY_SETTINGS_SIZE, &pError);
            break;

        case MMI_MEDPLY_SETTINGS_SHUFFULE:
            index = (U8*)data_value;
            g_mmi_medply_settings.is_shuffle = *index;
         #ifdef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
            mmi_medply_settings_shuff_change(g_mmi_medply_settings.is_shuffle);
         #endif
            WriteRecord(NVRAM_EF_MEDPLY_SETTINGS_LID,1, (void*)&g_mmi_medply_settings, NVRAM_EF_MEDPLY_SETTINGS_SIZE, &pError);
            break;
#if defined(__MMI_MEDIA_PLAYER_FTE__)
        case MMI_MEDPLY_SETTINGS_MAINSCR_DISP:
            index = (U8*)data_value;
            g_mmi_medply_settings.mainscrdisp_index = *index;
            WriteRecord(NVRAM_EF_MEDPLY_SETTINGS_LID,1, (void*)&g_mmi_medply_settings, NVRAM_EF_MEDPLY_SETTINGS_SIZE, &pError);
            break;
#endif /*defined(__MMI_MEDIA_PLAYER_FTE__)*/

        case MMI_MEDPLY_SETTINGS_PLAY_MODE:
            index = (U8*)data_value;
            g_mmi_medply_settings.play_mode = *index;
            WriteRecord(NVRAM_EF_MEDPLY_SETTINGS_LID,1, (void*)&g_mmi_medply_settings, NVRAM_EF_MEDPLY_SETTINGS_SIZE, &pError);
            break;
            
        case MMI_MEDPLY_SETTINGS_SUBTITLE_LCC:
            #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
            iso = (U32*)data_value;
            *iso = g_mmi_medply_settings_subtitle.iso_active;
            #endif
            break;
            
        default:
            WriteRecord(NVRAM_EF_MEDPLY_SETTINGS_LID,1, (void*)&g_mmi_medply_settings, NVRAM_EF_MEDPLY_SETTINGS_SIZE, &pError);
            break;
    }
    return MMI_TRUE; 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_write_value_ext
 * DESCRIPTION
 *  Update settings data and write value to NVRAM   
 *    1)can be set by enum_value = MMI_MEDPLY_SETTINGS_TYPE_ALL and is_flush = MMI_TRUE (data_value = NULL)
 *      to sync NVRAM data with player settings data
 *    2)can be set by enum_value = MMI_MEDPLY_SETTINGS_REPEAT, is_flush = MMI_TRUE, data_value = &repeat
 *      to update player settings data and sync NVRAM data with player settings data
 *    3)can be set by enum_value = MMI_MEDPLY_SETTINGS_REPEAT, is_flush = MMI_FALSE, data_value = &repeat
 *      to update player settings data only
 *  User can flush player settings data to NVRAM only once, since settings data is synchronized with one NVRAM LID
 *
 * PARAMETERS
 *  enum_value      [IN]    write value enum
 *  data_value      [IN]    
 *  is_flush        [IN]    MMI_TRUE: flush settings data to NVRAM immediately. 
 *                          MMI_FALSE: update cooresponding settings data but no NVRAM re-writing
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_medply_settings_write_value_ext(mmi_medply_settings_type_enum enum_value, void* data_value, MMI_BOOL is_flush)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* index;
    S16 pError;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (enum_value)
    {
        case MMI_MEDPLY_SETTINGS_DEFAULT_STORAGE:
            index = (U8*)data_value;
            g_mmi_medply_settings.default_storage_drv_letter = *index;
            break;
            
        case MMI_MEDPLY_SETTINGS_REPEAT:
            index = (U8*)data_value;
            g_mmi_medply_settings.repeat = *index;
     #ifdef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
            mmi_medply_settings_repeat_change(g_mmi_medply_settings.repeat);
     #endif
            break;

        case MMI_MEDPLY_SETTINGS_SHUFFULE:
            index = (U8*)data_value;
            g_mmi_medply_settings.is_shuffle = *index;
     #ifdef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
            mmi_medply_settings_shuff_change(g_mmi_medply_settings.is_shuffle);
     #endif
            break;
     
#if defined(__MMI_MEDIA_PLAYER_FTE__)
        case MMI_MEDPLY_SETTINGS_MAINSCR_DISP:
            index = (U8*)data_value;
            g_mmi_medply_settings.mainscrdisp_index = *index;
            break;
#endif /*defined(__MMI_MEDIA_PLAYER_FTE__)*/

        case MMI_MEDPLY_SETTINGS_PLAY_MODE:
            index = (U8*)data_value;
            g_mmi_medply_settings.play_mode = *index;
            break;
			
        case MMI_MEDPLY_SETTINGS_TYPE_ALL:
            break;
        default:
            break;
    }

    if (is_flush)
    {
        WriteRecord(NVRAM_EF_MEDPLY_SETTINGS_LID,1, (void*)&g_mmi_medply_settings, NVRAM_EF_MEDPLY_SETTINGS_SIZE, &pError);
    }
    
    return MMI_TRUE; 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_init_settings
 * DESCRIPTION
 *  init settings   
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_init_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
#if defined(__MMI_MEDIA_PLAYER_STREAM__) 
    U16 i;
    cbm_app_info_struct app_info;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_MEDPLY_SETTINGS_LID,1, (void*)&g_mmi_medply_settings, NVRAM_EF_MEDPLY_SETTINGS_SIZE, &pError);
#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    g_mmi_medply_settings_subtitle.has_inited = MMI_TRUE;
    g_mmi_medply_settings_subtitle.iso_active = g_mmi_medply_settings.subtitle_iso;
#endif

#if defined(__MMI_MEDIA_PLAYER_STREAM__) 
    ReadValue(NVRAM_EF_MEDPLY_SETTINGS_ACTIVE_PROFILE_INX, &g_mmi_medply_settings_network_profile.active_profile_idx, DS_BYTE, &pError);
#endif /* defined(__MMI_MEDIA_PLAYER_STREAM__)  */
#if defined(__MMI_MEDIA_PLAYER_STREAM__) 
    for (i = 0;i < NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_TOTAL; i++)
    {
        ReadRecord(NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_LID,
            i + 1,
            (void*)&(g_mmi_medply_settings_network_profile.network_profile[i]),
            NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_SIZE,
            &pError);
    }
#endif /* defined(__MMI_MEDIA_PLAYER_STREAM__) */
#if defined(__MMI_MEDIA_PLAYER_STREAM__) 
    memset(&app_info, 0, sizeof(app_info));
    app_info.app_icon_id = GetRootTitleIcon(MENU_ID_MEDPLY_MAIN);
    app_info.app_str_id = STR_ID_MEDPLY_APP_TITLE;
    app_info.app_type = DTCNT_APPTYPE_PLAYER | DTCNT_APPTYPE_SKIP_CSD;
    cbm_register_app_id_with_app_info(&app_info, &(g_mmi_medply_settings_network_profile.cbm_app_id));
#endif

    if ((g_mmi_medply_settings.is_shuffle != 0) &&
        (g_mmi_medply_settings.is_shuffle != 1))
    {
        g_mmi_medply_settings.is_theme_default = 0;
        g_mmi_medply_settings.skin_custom_path[0] = '\0';
        g_mmi_medply_settings.skin_custom_path[1] = '\0';
        g_mmi_medply_settings.default_storage_drv_letter = SRV_FMGR_PUBLIC_DRV;
        g_mmi_medply_settings_player.skin_file_selected = MMI_MEDPLY_SKIN_NO_SELECT;
        g_mmi_medply_settings.is_bgplay = 1;
        g_mmi_medply_settings.repeat= 0;
        g_mmi_medply_settings.is_shuffle = 0;
        g_mmi_medply_settings.audio_speed = MDI_AUDIO_SPEED_NORMAL;
        g_mmi_medply_settings.mainscrdisp_index = 0;
        g_mmi_medply_settings.brightness = MDI_VIDEO_BRIGHTNESS_0;
        g_mmi_medply_settings.contrast = MDI_VIDEO_CONTRAST_0;
        g_mmi_medply_settings.video_speed = 100;
	g_mmi_medply_settings.play_mode = MDI_VIDEO_TRACK_2D_NORMAL;
        g_mmi_medply_settings.sms_sim = 0;
        g_mmi_medply_settings.is_autofulscr_by_sensor = 1;
        #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
        g_mmi_medply_settings_subtitle.has_inited = MMI_FALSE;
        #endif
    }    
    
    /* restore settings config if needed */
#if !defined (__MMI_MEDIA_PLAYER_AUDIO__) || !defined (__MMI_AUDIO_TIME_STRETCH__) 
    g_mmi_medply_settings.audio_speed = MDI_AUDIO_SPEED_NORMAL;
#endif
    
#if !defined (__MMI_MEDIA_PLAYER_AUDIO__) || !defined (__MMI_AUDIO_SPECTRUM_DISPLAY__) 
    if (g_mmi_medply_settings.mainscrdisp_index > 1)
    {
        g_mmi_medply_settings.mainscrdisp_index = 0;
    }
#endif
#if !defined (__MMI_MEDIA_PLAYER_AUDIO__) || !defined (__MMI_MEDIA_PLAYER_LYRIC_DISPLAY__) 
    if (g_mmi_medply_settings.mainscrdisp_index > 1)
    {
        g_mmi_medply_settings.mainscrdisp_index = 0;
    }
#endif

#if !defined(__MMI_MEDIA_PLAYER_VIDEO_PROCESSING_SUPPORT__) 
    g_mmi_medply_settings.brightness = MDI_VIDEO_BRIGHTNESS_0;
    g_mmi_medply_settings.contrast = MDI_VIDEO_CONTRAST_0;
#endif

#if !defined (__MMI_MEDIA_PLAYER_VIDEO_SPEED__)
    g_mmi_medply_settings.video_speed = 100;
#endif

    WriteRecord(NVRAM_EF_MEDPLY_SETTINGS_LID,1, (void*)&g_mmi_medply_settings, NVRAM_EF_MEDPLY_SETTINGS_SIZE, &pError);

 #if defined(__MMI_MEDIA_PLAYER_STREAM__) 
    if (g_mmi_medply_settings_network_profile.active_profile_idx >= NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_TOTAL)
    {
        g_mmi_medply_settings_network_profile.active_profile_idx = 0;
        WriteValue(NVRAM_EF_MEDPLY_SETTINGS_ACTIVE_PROFILE_INX, &g_mmi_medply_settings_network_profile.active_profile_idx, DS_BYTE, &pError);
    }
#endif  /*defined(__MMI_MEDIA_PLAYER_STREAM__) */
    g_medply.is_setting_init = MMI_TRUE;
}


#if defined(__MMI_MEDIA_PLAYER_VDOREC__)
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_highlight_video_recoder
 * DESCRIPTION
 *  init settings   
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_highlight_video_recoder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_medply_entry_video_recoder, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_entry_video_recoder
 * DESCRIPTION
 *  init settings   
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_entry_video_recoder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vdorec_lauch();
}
#endif /* __MMI_MEDIA_PLAYER_VDOREC__ */



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_setting_get_preview_file_drv_letter
 * DESCRIPTION
 *  
 * PARAMETERS
 *     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_medply_setting_get_preview_file_drv_letter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_skin_custom_path[0];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_setting_deinit_hdlr
 * DESCRIPTION
 *   
 * PARAMETERS
 *  data_account_id [OUT]    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_setting_deinit_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_del_all_app_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_init_settings
 * DESCRIPTION
 *  init settings   
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_del_all_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(GRP_ID_MEDPLY_SETTINGS_MAIN);

}


#ifdef __MMI_VIDEO_STREAM__
/* these interfaces are for mmi streaming OTAP */
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_init_settings
 * DESCRIPTION
 *  init settings   
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_set_active_profile(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_TOTAL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_OTAP_INDEX_ERROR); 
    }
    g_mmi_medply_settings_network_profile.active_profile_idx = index;
    WriteValue(NVRAM_EF_MEDPLY_SETTINGS_ACTIVE_PROFILE_INX, &g_mmi_medply_settings_network_profile.active_profile_idx, DS_BYTE, &error);        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_get_active_profile
 * DESCRIPTION
 *  init settings   
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_medply_get_active_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_EF_MEDPLY_SETTINGS_ACTIVE_PROFILE_INX, &index, DS_BYTE, &error); 
    if (index >= NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_TOTAL)
    {
        index = 0;
    }
    return index;
}


void mmi_medply_get_string_id_and_icon_id(U16 *string_id, U16 *icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

     /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    *icon_id = GetRootTitleIcon(MENU_ID_MEDPLY_MAIN);
    *string_id = STR_ID_MEDPLY_APP_TITLE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_init_settings
 * DESCRIPTION
 *  init settings   
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_medply_is_profile_in_use(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U16 state = g_medply.state;
    U8  active_prof_idx;  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (index >= NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_TOTAL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_OTAP_INDEX_ERROR); 
    }
    ReadValue(NVRAM_EF_MEDPLY_SETTINGS_ACTIVE_PROFILE_INX, &active_prof_idx, DS_BYTE, &error); 
    if (active_prof_idx == 0xff)
    {
        active_prof_idx = 0;
    }
    if (state == MEDPLY_STATE_STREAM_CONNECTED && index == active_prof_idx)
    {
        return MMI_TRUE; 
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_init_settings
 * DESCRIPTION
 *  init settings   
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_load_profile(U8 index, nvram_ef_medply_settings_profile_struct *prof_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_TOTAL || prof_p == NULL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_OTAP_INDEX_ERROR); 
        return;
    }
    ReadRecord(
          NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_LID, 
          index + 1,  /* id start from 1 */ 
          (void*)prof_p, 
          NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_SIZE, 
          &error);
    if (!mmi_ucs2strlen((CHAR*)prof_p->profile_name))
    {
        mmi_ucs2cpy((CHAR*)prof_p->profile_name, (CHAR*)GetString((U16)(STR_ID_MEDPLY_SETTINGS_PROFILE1 + index)));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_init_settings
 * DESCRIPTION
 *  init settings   
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_store_profile(U8 index,nvram_ef_medply_settings_profile_struct *prof_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_TOTAL || prof_p == NULL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_OTAP_INDEX_ERROR); 
        return;
    }
    WriteRecord(
         NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_LID, 
         index + 1,  /* id start from 1 */ 
         (void*)prof_p, 
         NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_SIZE, 
         &error);

    memcpy(&g_mmi_medply_settings_network_profile.network_profile[index],prof_p, sizeof(nvram_ef_medply_settings_profile_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_init_settings
 * DESCRIPTION
 *  init settings   
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_medply_get_cbm_app_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_OTAP_CBM_ID,g_mmi_medply_settings_network_profile.cbm_app_id); 
    
    return g_mmi_medply_settings_network_profile.cbm_app_id;
}
#endif

#endif /* __MMI_MEDIA_PLAYER__ */
#endif /* MMI_MEDIA_PLAYER_SETTINGS */
