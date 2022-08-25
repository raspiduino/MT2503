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
 *  MobileTVPlayer.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Mobile TV Player Applications v0.1
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/****************************************************************************
* Include Files
*****************************************************************************/
#include "MMI_features.h"

#if defined(__MMI_ATV_SUPPORT__)

#include "SettingDefs.h"        /* ST_NOTIFYDURATION define */
#include "SettingProfile.h"
#include "gui.h"                /* Gui functions */
#include "FileMgrSrvGProt.h"
#include "FileManagerGprot.h"
#include "ScreenRotationGprot.h"
#include "CommonScreens.h"
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"

#include "gdi_include.h"
#include "gdi_2d_engine.h"

#include "mmi_features_mtv_player.h"
#include "gui_font_size.h"
#include "gui_effect_oem.h"

#if defined(__MMI_MTV_A2DP_SUPPORT__)
#include "BTMMIScrGprots.h"
#include "av_bt.h"
#include "AudioPlayerProt.h"
#endif /* __MMI_MTV_A2DP_SUPPORT__ */

#if defined(__MMI_BT_SUPPORT__)
#include "BtcmSrvGprot.h"
#endif

#include "BTMMIObexGprots.h"

#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif /* __MMI_TOUCH_SCREEN__ */
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "wgui_categories_multimedia.h"
#include "mdi_include.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_mtv.h"
#include "app_str.h"
#include "CommonScreensResDef.h"
#include "MobileTVPlayerEnum.h"
#include "MobileTVPlayerGprot.h"
#include "MobileTVPlayer.h"
#include "MobileTVPlayerOSD.h"
#include "gdi_2d_engine.h"
#include "MMI_media_app_trc.h"
#include "ProfilesSrvGprot.h"

#ifdef __DM_LAWMO_SUPPORT__
#include "mmiapi_dm_struct.h"
#include "dmuigprot.h"
#endif
#include "UcmSrvGprot.h"
#include "UCMGProt.h"
#include "USBsrvgprot.h"
#include "IdleGProt.h"

#include "MainMenuDef.h"        /* Multimedia icon */
#include "mmi_rp_app_mainmenu_def.h"        /* Multimedia icon */
#include "mmi_rp_app_idle_def.h"
#include "SimCtrlSrvGprot.h"

/* GDI */
#include "gdi_include.h"
#include "custom_events_notify.h"
#include "Gui_effect_oem.h"
#include "ShutdownSrvGProt.h"

#include "MenuCuiGProt.h"
#include "FileMgrCuiGProt.h"
#include "FSEditorCuiGProt.h"
#include "InlineCuiGProt.h"
#include "BTMMISCOPathGprots.h"
#include "DataAccountCUIGprot.h"
#ifdef __ATV_SMS_SUPPORT__
#include "mtvsmsgprot.h"
#endif
#include "wgui_inputs.h"
#include "Gpiosrvgprot.h"
#include "mmi_rp_srv_prof_def.h"
#include "mmi_rp_app_usbsrv_def.h"

#include "MMI_features.h"
#include "mmi_rp_app_mobile_tv_player_def.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "mmi_frm_scenario_gprot.h"
#include "lcd_sw_inc.h"
#include "kal_public_api.h"
#include "mmi_frm_nvram_gprot.h"
#include "nvram_common_defs.h"
#include "fs_type.h"
#include "fs_func.h"
#include "AlertScreen.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "gui_typedef.h"
#include "mmi_frm_timer_gprot.h"
#include "app_mem.h"
#include "mmi_res_range_def.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "GlobalConstants.h"
#include "stdio.h"
#include "Unicodexdcl.h"
#include "med_struct.h"
#include "mmi_frm_input_gprot.h"
#include "gui_data_types.h"
#include "fs_errcode.h"
#include "BTMMIA2DPScr.h"
#include "CommonScreensResDef.h"
#include "mdi_enum.h"
#include "wgui_categories_popup.h"
#include "gui_themes.h"
#include "mmi_frm_mem_gprot.h"
#include "string.h"
#include "wgui_categories_text_viewer.h"
#include "app_datetime.h"
#include "mmi_frm_history_gprot.h"
#include "wgui_include.h"
#include "cmmb_eb.h"
#include "PixcomFontEngine.h"
#include "mtv_esg_define.h"
#include "gdi_features.h"
#include "g2d_enum.h"
#include "FileMgrType.h"
#include "wgui_inputs.h"
#include "gui_inputs.h"
#include "wgui_categories_inputs.h"
#include "lcd_sw_rnd.h"
#include "gdi_lcd_config.h"
#include "kal_public_defs.h"
#include "gui_switch.h"
#include "wgui.h"
#include "lcd_if.h"
#include "Gpiosrvgprot.h"
#include "mmi_frm_gprot.h"
#include "mmi_rp_app_idle_def.h"
#include "IdleAppResDef.h"
#include "gui_windows.h"
#include "custom_mmi_default_value.h"
#include "IdleAppResDef.h"
#ifdef __MMI_MATV_ESD_RECOVERY_SUPPORT__
#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)
#include "kal_public_defs.h"
#include "kal_public_api.h"
#endif
#endif/*__MATV_ESD_RECOVERY_SUPPORT__*/

#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
#include "ScrLockerGprot.h"
#endif
#include "MMI_ap_dcm_config.h"
#ifdef __MM_DCM_SUPPORT__   
#include "dcmgr.h"
MMI_BOOL g_is_engine_paused;
#endif


#if defined(__MMI_MAINLCD_320X480__)||defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)|| defined(__MMI_MAINLCD_320X240__)
#define __MMI_MTV_FTE2_LAYOUT__
#endif

#ifdef __MMI_AP_DCM_MATV__
#pragma arm section rodata = "DYNAMIC_CODE_MATV_RODATA" , code = "DYNAMIC_CODE_MATV_ROCODE"
#endif

#ifndef __MTK_TARGET__
#undef __CAMERA_MATV_ESD_RECOVERY_SUPPORT__
#endif

#ifdef __MMI_MATV_ESD_RECOVERY_SUPPORT__
#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)
extern volatile kal_timerid matv_resz_cp_ESD_timeout_timer;
extern volatile kal_bool resz_esd_check_flag;
MMI_BOOL matv_resz_timer_seted;
static void resz_cp_ESD_timeout_timer_hdlr(void);
extern void CalLcdFroceAutoUpdate(void);    
#endif
#endif/*__MATV_ESD_RECOVERY_SUPPORT__*/

static mmi_mtv_player_context_struct g_mmi_mtv_player_cntx;
mmi_mtv_player_context_struct *mtv_player_p = &g_mmi_mtv_player_cntx;
static mtv_player_menu_context_struct g_mmi_mtv_player_setting_cntx;
mtv_player_menu_context_struct *mtv_player_setting_p = &g_mmi_mtv_player_setting_cntx;

/* Inline: caption string */
static const cui_inline_item_caption_struct g_mtv_brightness_caption =
{
    STR_ID_MOBILE_TV_PLAYER_SETTING_BRIGHTNESS
};
static const cui_inline_item_caption_struct g_mtv_contrast_caption =
{
    STR_ID_MOBILE_TV_PLAYER_SETTING_CONTRAST
};
static const cui_inline_item_caption_struct g_mtv_saturation_caption =
{
    STR_ID_MOBILE_TV_PLAYER_SETTING_SATURATION
};
static const cui_inline_item_caption_struct g_mtv_audio_mode_caption =
{
    STR_ID_MOBILE_TV_PLAYER_SETTING_AUD_MODE
};
#ifdef __MMI_MTV_RECORD_SUPPORT__
static const cui_inline_item_caption_struct g_mtv_record_size_caption =
{
    STR_ID_MOBILE_TV_PLAYER_SETTING_RECORD_SIZE
};
#endif

/* Inline: selector string */
static const U16 g_mtv_adjust_str[] =
    {STR_ID_MOBILE_TV_PLAYER_ADJUST_N5,
     STR_ID_MOBILE_TV_PLAYER_ADJUST_N4,
     STR_ID_MOBILE_TV_PLAYER_ADJUST_N3,
     STR_ID_MOBILE_TV_PLAYER_ADJUST_N2,
     STR_ID_MOBILE_TV_PLAYER_ADJUST_N1,
     STR_ID_MOBILE_TV_PLAYER_ADJUST_0,
     STR_ID_MOBILE_TV_PLAYER_ADJUST_P1,
     STR_ID_MOBILE_TV_PLAYER_ADJUST_P2,
     STR_ID_MOBILE_TV_PLAYER_ADJUST_P3,
     STR_ID_MOBILE_TV_PLAYER_ADJUST_P4,
     STR_ID_MOBILE_TV_PLAYER_ADJUST_P5};

/* Inline: selector structure */
static const cui_inline_item_select_struct g_mtv_brightness_selector =
{
    MMI_MOBILE_TV_PLAYER_BRIGHTNESS_ADJ_LEVEL_COUNT,
    0,
    g_mtv_adjust_str
};
static const cui_inline_item_select_struct g_mtv_contrast_selector =
{
    MMI_MOBILE_TV_PLAYER_CONTRAST_ADJ_LEVEL_COUNT,
    0,
    g_mtv_adjust_str
};
static const cui_inline_item_select_struct g_mtv_saturation_selector =
{
    MMI_MOBILE_TV_PLAYER_CONTRAST_ADJ_LEVEL_COUNT,
    0,
    g_mtv_adjust_str
};


typedef enum
{
    MMI_MTV_IMG_BRIGHTNESS = IMG_GLOBAL_L1,
    MMI_MTV_IMG_CONTRAST,
    MMI_MTV_IMG_SATURATION,
    MMI_MTV_IMG_AUD_MODE
#ifdef __MMI_MTV_RECORD_SUPPORT__
    ,
    MMI_MTV_IMG_RECORD_SIZE
#endif /* __MMI_MTV_RECORD_SUPPORT__ */
}mmi_mtv_inline_item_enum;

static const cui_inline_set_item_struct g_mtv_setting_item[] =
{
    {MMI_MTV_BRIGHTNESS_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION,       MMI_MTV_IMG_BRIGHTNESS, (void*)&g_mtv_brightness_caption},
    {MMI_MTV_BRIGHTNESS_SELECTOR,       CUI_INLINE_ITEM_TYPE_SELECT,        0,                      (void*)&g_mtv_brightness_selector},
    {MMI_MTV_CONTRAST_CAPTION,          CUI_INLINE_ITEM_TYPE_CAPTION,       MMI_MTV_IMG_CONTRAST,   (void*)&g_mtv_contrast_caption},
    {MMI_MTV_CONTRAST_SELECTOR,         CUI_INLINE_ITEM_TYPE_SELECT,        0,                      (void*)&g_mtv_contrast_selector},
    {MMI_MTV_SATURATION_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION,       MMI_MTV_IMG_SATURATION, (void*)&g_mtv_saturation_caption},
    {MMI_MTV_SATURATION_SELECTOR,       CUI_INLINE_ITEM_TYPE_SELECT,        0,                      (void*)&g_mtv_saturation_selector},
    {MMI_MTV_AUDIO_MODE_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION,       MMI_MTV_IMG_AUD_MODE,   (void*)&g_mtv_audio_mode_caption},
    {MMI_MTV_AUDIO_MODE_SELECTOR,       CUI_INLINE_ITEM_TYPE_SELECT,        0,                      NULL},
    {MMI_MTV_AUDIO_MODE_DISPLAY_ONLY,   CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY  | CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW,  0, NULL}
#ifdef __MMI_MTV_RECORD_SUPPORT__
    ,
    {MMI_MTV_RECORD_SIZE_CAPTION,       CUI_INLINE_ITEM_TYPE_CAPTION,       MMI_MTV_IMG_RECORD_SIZE,(void*)&g_mtv_record_size_caption},
    {MMI_MTV_RECORD_SIZE_SELECTOR,      CUI_INLINE_ITEM_TYPE_SELECT,        0,                      NULL}
#endif /*__MMI_MTV_RECORD_SUPPORT__ */

};

static const cui_inline_struct g_mtv_setting_inline =
{
    sizeof(g_mtv_setting_item)/sizeof(g_mtv_setting_item[0]),
    STR_GLOBAL_SETTINGS,
    0,
    CUI_INLINE_SCREEN_DEFAULT_TEXT,
    NULL,
    g_mtv_setting_item
};


/* NOTE: the sequence should be the same as the order of menu string */
const U8 mmi_atv_country_map[] =
{
    MDI_MTV_ATV_AFGHANISTAN,
    MDI_MTV_ATV_ARGENTINA,
    MDI_MTV_ATV_AUSTRALIA,
    MDI_MTV_ATV_BRAZIL,
    MDI_MTV_ATV_CAMBODIA,
    MDI_MTV_ATV_CANADA,
    MDI_MTV_ATV_CHILE,
    MDI_MTV_ATV_CHINA,
    MDI_MTV_ATV_CHINA_HONGKONG,
    MDI_MTV_ATV_CHINA_SHENZHEN,
    MDI_MTV_ATV_CONGO,
    MDI_MTV_ATV_EUROPE_EASTERN,
    MDI_MTV_ATV_FRANCE,
    MDI_MTV_ATV_GABON,
    MDI_MTV_ATV_INDIA,
    MDI_MTV_ATV_INDONESIA,
    MDI_MTV_ATV_IRAN,
    MDI_MTV_ATV_IRELAND,
    MDI_MTV_ATV_ITALY,
    MDI_MTV_ATV_IVORYCOAST,
    MDI_MTV_ATV_JAPAN,
    MDI_MTV_ATV_KOREA,
    MDI_MTV_ATV_LAOS,
    MDI_MTV_ATV_MADAGASCAR,
    MDI_MTV_ATV_MALAYSIA,
    MDI_MTV_ATV_MEXICO,
    MDI_MTV_ATV_MOROCCO,
    MDI_MTV_ATV_BURMA, /* String: MYANMAR */    
    MDI_MTV_ATV_NEWZEALAND,
    MDI_MTV_ATV_PAKISTAN,
    MDI_MTV_ATV_PARAGUAY,
    MDI_MTV_ATV_PHILIPPINES,
    MDI_MTV_ATV_PORTUGAL,
    MDI_MTV_ATV_REUNION,
    MDI_MTV_ATV_RUSSIA,
    MDI_MTV_ATV_RWANDA,
    MDI_MTV_ATV_SENEGAL,
    MDI_MTV_ATV_SINGAPORE,
    MDI_MTV_ATV_SOUTHAFRICA,
    MDI_MTV_ATV_SPAIN,
    MDI_MTV_ATV_TAIWAN,
    MDI_MTV_ATV_THAILAND,
    MDI_MTV_ATV_TURKEY,
    MDI_MTV_ATV_UNITED_ARAB_EMIRATES,
    MDI_MTV_ATV_UNITED_KINGDOM,
    MDI_MTV_ATV_USA,
    MDI_MTV_ATV_URUGUAY,
    MDI_MTV_ATV_VENEZUELA,
    MDI_MTV_ATV_VIETNAM,
    MDI_MTV_ATV_EUROPE_WESTERN
};
/* NOTE: the sequence should be the same as the order of string */
const U32 mmi_atv_aud_mode[] =
{
   MDI_ATV_MONO,
   MDI_ATV_MTS_STEREO,
   MDI_ATV_MTS_SAP,

   MDI_ATV_MPX_MONO,
   MDI_ATV_MPX_STEREO,
   MDI_ATV_MPX_SUB,
   MDI_ATV_MPX_MAIN_SUB,
   MDI_ATV_MPX_MAIN,

   MDI_ATV_FM_MONO,
   MDI_ATV_A2_STEREO,
   MDI_ATV_A2_DUAL1,
   MDI_ATV_A2_DUAL2,
   MDI_ATV_NICAM_MONO,
   MDI_ATV_NICAM_STEREO,
   MDI_ATV_NICAM_DUAL1,
   MDI_ATV_NICAM_DUAL2
};

#define MTV_VOLUME_TYPE	MDI_VOLUME_ATV
static void mmi_mtv_player_interrupt_hdlr(mdi_result result, void *user_data);
MMI_BOOL mmi_mtv_player_is_in_background_call(void);
void gui_screen_switch_effect_block(MMI_BOOL enable);


#ifdef __MMI_MATV_ESD_RECOVERY_SUPPORT__
#ifdef __CAMERA_MATV_ESD_RECOVERY_SUPPORT__
void mmi_mtv_player_send_msg_to_restart(void);
#endif
#endif/*__MMI_MATV_ESD_RECOVERY_SUPPORT__*/


void mmi_mtv_player_check_bg_snd(void)
{
 if((MMI_FALSE == mmi_mtv_player_is_in_background_call()) && (MMI_FALSE == mtv_player_p->is_suspend))
	 {
		 /* suspend background play */
		 mdi_audio_suspend_background_play();
		 mdi_audio_register_interrupt_callback(mmi_mtv_player_interrupt_hdlr, NULL);
		 mtv_player_p->is_suspend = MMI_TRUE;
	 }
}

void mmi_mtv_player_reset_osd_by_rotate(void)
{
	if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        mmi_mtv_player_fullscr_reset_osd_fade(MMI_TRUE);
    else
        mmi_mtv_player_fullscr_reset_osd_fade(MMI_FALSE);

}

void mmi_mtv_player_start_timer(U32 init_value, U32 step, void (*callback) (void))
{
    gui_start_timer(init_value + (U32)mtv_player_p->is_key_pressed * step, callback);
	mtv_player_p->is_key_pressed = MMI_TRUE;
}


void mmi_mtv_player_turn_on_backlight(void)
{
	//info_ptr = mmi_mtv_player_get_active_channel_ptr();

	if (mmi_mtv_player_get_active_channel_ptr()->service_type == MDI_MTV_SERVICE_TYPE_ANALOG_TV)
			{
				srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
				srv_gpio_play_pattern((srv_gpio_pattern_id_enum)srv_led_pattern_get_bg_pattern(), SRV_GPIO_PATN_PLAY_STOP);
			}

}

void mmi_mtv_player_turn_off_backlight(void)
{

	//info_ptr = mmi_mtv_player_get_active_channel_ptr();

	if (mmi_mtv_player_get_active_channel_ptr()->service_type == MDI_MTV_SERVICE_TYPE_ANALOG_TV)
				{
					/* resume LED patten and let MMI can sleep */
					srv_gpio_play_pattern((srv_gpio_pattern_id_enum)srv_led_pattern_get_bg_pattern(), SRV_GPIO_PATN_PLAY_START);
					srv_backlight_turn_off();
				}

}

void mmi_mtv_player_set_volume(void)
{
#if !defined(__MMI_FTE_SUPPORT__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MTV_FTE2_LAYOUT__))
		/* init aud volume */
		if (mtv_player_p->setting.is_mute)
		{
			mdi_audio_set_volume(MTV_VOLUME_TYPE, (U8) MDI_AUD_VOL_EX_MUTE(MTV_PLAYER_VOL_MUTE));
		}
		else
#endif /* !defined(__MMI_FTE_SUPPORT__) */
		{
			mdi_audio_set_volume(MTV_VOLUME_TYPE, (U8) MDI_AUD_VOL_EX_MUTE(mtv_player_p->setting.vol_level));
		}

}


 /*****************************************************************************
  * FUNCTION
  *  mmi_mtv_player_set_flag
  * DESCRIPTION
  *  set flag bit on
  * PARAMETERS
  *  selected_flag [in] flags
  * RETURNS
  *  void
  *****************************************************************************/

 void mmi_mtv_player_set_flag(mtv_player_bool_status_enum selected_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->bool_state |= selected_flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_unset_flag
 * DESCRIPTION
 *  set flat bit off
 * PARAMETERS
 *  selected_flag [in] flags
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_unset_flag(mtv_player_bool_status_enum selected_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->bool_state &= ~(selected_flag);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_is_flag_set
 * DESCRIPTION
 *  usb mode handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 MMI_BOOL mmi_mtv_player_is_flag_set(mtv_player_bool_status_enum selected_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return (MMI_BOOL)!!(mtv_player_p->bool_state & selected_flag);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_blt_previous
 * DESCRIPTION
 *
 * PARAMETERS
 *  x1      [IN]
 *  y1      [IN]
 *  x2      [IN]
 *  y2      [IN]
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
void mmi_mtv_player_blt_previous(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_ATV_OSD_SUPPORT__)
    gdi_layer_blt_previous(x1, y1, x2, y2);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_enter_state
 * DESCRIPTION
 *  control of serviec state machine
 * PARAMETERS
 *  next state
 * RETURNS
 *  void
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_kernel_enter_state(mmi_mtv_player_kernel_state_enum next_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->kernel_next_state = next_state;
    ret = mmi_mtv_player_exit_current_state(MMI_MTV_KERNEL);

    if (ret < 0)
    {
        return ret;
    }
    ret = mmi_mtv_player_enter_next_state(MMI_MTV_KERNEL);

    if (ret >= 0)
    {
        mtv_player_p->kernel_prev_state = mtv_player_p->kernel_state;
        mtv_player_p->kernel_state = mtv_player_p->kernel_next_state;
        mtv_player_p->kernel_next_state = MTV_KERNEL_NULL;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_KERNEL_STATE, mtv_player_p->kernel_prev_state, mtv_player_p->kernel_state);
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_player_enter_state
 * DESCRIPTION
 *  control of player state machine
 * PARAMETERS
 *  next state
 * RETURNS
 *  void
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_player_enter_state(mmi_mtv_player_player_state_enum next_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = 0;
    U16 active_screen_id = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mtv_player_p->player_next_state = next_state;
    ret = mmi_mtv_player_exit_current_state(MMI_MTV_PLAYER);

    if (ret < 0)
    {
        return ret;
    }

    /* Enter connect state should be prior to calling av_bt_open_ex(),
       because av_bt_open_ex() may call open_callback() directly. */
    if (next_state == MTV_PLAYER_BT_CONNECT)
    {
        mtv_player_p->player_prev_state = mtv_player_p->player_state;
        mtv_player_p->player_state = mtv_player_p->player_next_state;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MTV_PLAYER_STATE, mtv_player_p->player_prev_state, mtv_player_p->player_state);

        ret = mmi_mtv_player_enter_next_state(MMI_MTV_PLAYER);

        mtv_player_p->player_next_state = MTV_PLAYER_NULL;
    }
    else
    {
        ret = mmi_mtv_player_enter_next_state(MMI_MTV_PLAYER);

        if (ret >= 0)
        {
            mtv_player_p->player_prev_state = mtv_player_p->player_state;
            mtv_player_p->player_state = mtv_player_p->player_next_state;
            mtv_player_p->player_next_state = MTV_PLAYER_NULL;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MTV_PLAYER_STATE, mtv_player_p->player_prev_state, mtv_player_p->player_state);

            if (active_screen_id == SCR_ID_MOBILE_TV_PLAYER_APP &&
                mtv_player_p->player_state == MTV_PLAYER_PLAY)
            {
#ifdef   __MMI_ATV_OSD_SUPPORT__
                /* If already fade out, keep all key handler as: mmi_mtv_player_fullscr_osd_show_up */
                if (mtv_player_p->fullscr_osd_opacity != 0)
                {
#endif

                    /* For snapshot icon */
                    mmi_mtv_player_register_key_hdlr();
#ifdef   __MMI_ATV_OSD_SUPPORT__

                    mmi_mtv_player_draw_osd();
                    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
                }
#endif

            }
        }
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_recorder_enter_state
 * DESCRIPTION
 *  control of recorder state machine
 * PARAMETERS
 *  next state
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mmi_mtv_player_recorder_enter_state(mmi_mtv_player_recorder_state_enum next_state)
{
#ifdef __MMI_MTV_RECORD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->recorder_next_state = next_state;
    ret = mmi_mtv_player_exit_current_state(MMI_MTV_RECORDER);

    if (ret < 0)
    return ret;

    ret = mmi_mtv_player_enter_next_state(MMI_MTV_RECORDER);

    if (ret >= 0)
    {
        mtv_player_p->recorder_prev_state = mtv_player_p->recorder_state;
        mtv_player_p->recorder_state = mtv_player_p->recorder_next_state;
        mtv_player_p->recorder_next_state = MTV_RECORDER_NULL;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_RECORDER_STATE, mtv_player_p->recorder_prev_state, mtv_player_p->recorder_state);
    }

    return ret;
#else
    return 0;
#endif
}

/*****************************************************************************
* External Functions Implementation
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_update_storage_status
 * DESCRIPTION
 *
 * PARAMETERS
 *  inMsg       [?]
 * RETURNS
 *
 *****************************************************************************/
 void mmi_mtv_player_update_storage_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen_id = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifndef __ATV_NO_PHONE_STORAGE__
    /* check storage to enable or disable timeshift function dynamically */
    mmi_mtv_player_check_storage(MMI_FALSE, mtv_player_p->setting.storage);
#else
    mmi_mtv_player_check_storage();
#endif

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_VAL2, mtv_player_p->prev_storage_status, mtv_player_p->storage_status, __LINE__);

#ifndef __ATV_NO_PHONE_STORAGE__
    if (mtv_player_p->prev_storage_status == mtv_player_p->storage_status)
    {
        return;
    }
#endif
#ifdef   __MMI_MTV_RECORD_SUPPORT__
    if (mtv_player_p->storage_status == MTV_PLAYER_STORAGE_OK)
    {
    //#if defined(__MMI_MTV_RECORD_SUPPORT__)
        mdi_mtv_set_storage(mtv_player_p->mtv_handle, (PU8)mtv_player_p->storage_filepath);
    //#endif
    }
#endif


#if defined(__MMI_MTV_RECORD_SUPPORT__) || defined(__MMI_MTV_SNAPSHOT_SUPPORT__)

    if (active_screen_id == SCR_ID_MOBILE_TV_PLAYER_APP)
    {
#ifdef   __MMI_ATV_OSD_SUPPORT__
        /* If already fade out, keep all key handler as: mmi_mtv_player_fullscr_osd_show_up */
        if (mtv_player_p->fullscr_osd_opacity != 0)
        {
            /* For snapshot icon */
#endif
            mmi_mtv_player_register_key_hdlr();
#ifdef   __MMI_ATV_OSD_SUPPORT__
            mmi_mtv_player_draw_osd();
            mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
        }
#endif
    }
#endif /* __MMI_MTV_RECORD_SUPPORT__  || __MMI_MTV_SNAPSHOT_SUPPORT__*/

}



/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_exit_usb_mode_callback
 * DESCRIPTION
 *  usb mode handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_exit_usb_mode_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen_id = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_EXIT_USB_MODE_CALLBACK);

    if (!mmi_frm_scrn_is_present(
            GRP_ID_MOBILE_TV_PLAYER,
            SCR_ID_MOBILE_TV_PLAYER_APP_BASE,
            MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        return;
    }
    /* Following: exit USB mode inside MTV application */

    /* USB_Deinit function has been invoked, but screen is not deleted up to Idle screen */
    if (KERNEL_STATE_IN(MTV_KERNEL_CLOSED) || KERNEL_STATE_IN(MTV_KERNEL_CLOSING))
    {
        mmi_frm_group_close(GRP_ID_MOBILE_TV_PLAYER);
        return;
    }

    mmi_mtv_player_update_storage_status();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_terminate_app
 * DESCRIPTION
 *  to deinit app
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_terminate_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_TERMINATE_APP);

    if (!KERNEL_STATE_IN(MTV_KERNEL_CLOSED) && !KERNEL_STATE_IN(MTV_KERNEL_CLOSING))
    {
        /* Service enters CLOSED state will make player and recorder to reset state automatically */
        mmi_mtv_player_kernel_enter_state(MTV_KERNEL_CLOSING);
        wgui_status_icon_bar_hide_icon(STATUS_ICON_MTV_SIGNAL);
        StopTimer(MTV_PLAYER_UPDATE_SIGNAL_TIMER);
    }
}





/*****************************************************************************
*  Functions Implementation
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_reset_all_icon
 * DESCRIPTION
 *  reset all icons' states.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_reset_all_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->active_osd_cntx_p->vol_inc.status = MTV_PLAYER_ICON_STATUS_ENABLE;
    mtv_player_p->active_osd_cntx_p->vol_dec.status = MTV_PLAYER_ICON_STATUS_ENABLE;
    mtv_player_p->active_osd_cntx_p->fullscreen.status = MTV_PLAYER_ICON_STATUS_ENABLE;
    mtv_player_p->active_osd_cntx_p->lsk.status = MTV_PLAYER_ICON_STATUS_ENABLE;
    mtv_player_p->active_osd_cntx_p->rsk.status = MTV_PLAYER_ICON_STATUS_ENABLE;
 #if defined(__MMI_FTE_SUPPORT__)
    mtv_player_p->active_osd_cntx_p->vol_bg.status = MTV_PLAYER_ICON_STATUS_DISABLE;
    mtv_player_p->active_osd_cntx_p->vol_idx.status = MTV_PLAYER_ICON_STATUS_DISABLE;
#endif /* __MMI_FTE_SUPPORT__  */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_select_channel_to_play
 * DESCRIPTION
 *  mobile tv player channel list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_select_channel_to_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PLAYER_STATE_IN(MTV_PLAYER_PLAY)||PLAYER_STATE_IN(MTV_PLAYER_BT_CONNECT))
    {
        mmi_mtv_player_player_enter_state(MTV_PLAYER_STOPPED);
    }

    mmi_mtv_player_entry_app_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_cancel_select_channel
 * DESCRIPTION
 *  back from mobile tv player channel list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_cancel_select_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PLAYER_STATE_IN(MTV_PLAYER_PLAY)||PLAYER_STATE_IN(MTV_PLAYER_BT_CONNECT))
    {
        mmi_mtv_player_player_enter_state(MTV_PLAYER_STOPPED);
    }
#ifdef   __MMI_MTV_RECORD_SUPPORT__
    if (RECORDER_STATE_IN(MTV_RECORDER_STOPPED))
#endif
    {
        mmi_mtv_player_kernel_enter_state(MTV_KERNEL_CLOSING);
        mtv_player_p->go_back_history = MMI_TRUE;
    }

    mmi_frm_group_close(GRP_ID_MOBILE_TV_PLAYER);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_exit_channel_list_screen
 * DESCRIPTION
 *  mobile tv player channel list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_exit_channel_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 #ifdef __MMI_MTV_PREVIEW_SUPPORT__
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MTV_PLAYER_CHANNEL_LIST_DELAY_TIMER);
    if (KERNEL_STATE_IN(MTV_KERNEL_INIT))
    {
        /* Restore previous selected service */
        ret = mmi_mtv_player_kernel_enter_state(MTV_KERNEL_OPENED);
        ASSERT(ret == MDI_RES_MTV_SUCCEED);
    }

    if (PLAYER_STATE_IN(MTV_PLAYER_PLAY)||PLAYER_STATE_IN(MTV_PLAYER_BT_CONNECT))
    {
        mmi_mtv_player_player_enter_state(MTV_PLAYER_STOPPED);
    }

    /* De-register bt callback when midlet is terminated */
#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_clear_volume_sync_callback(APP_MOBILE_TV_PLAYER);
#endif
#endif/*__MMI_MTV_PREVIEW_SUPPORT__*/
    mmi_frm_end_scenario(MMI_SCENARIO_ID_HIGH_SCRN);

#ifdef __MMI_MTV_PREVIEW_SUPPORT__
    /* Reset paramter */
    mtv_player_p->cl_preview_layer_handle = 0;
    mtv_player_p->cl_blt_layer_flag = 0;
    mtv_player_p->cl_preview_layer_flag = 0;
    mtv_player_p->cl_preview_layer_offset_x = 0;
    mtv_player_p->cl_preview_layer_offset_y = 0;
    mtv_player_p->cl_preview_layer_width = 0;
    mtv_player_p->cl_preview_layer_height = 0;
#endif/*__MMI_MTV_PREVIEW_SUPPORT__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_entry_cl_option_screen
 * DESCRIPTION
 *  mobile tv player channel list option menu screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_entry_cl_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->cl_option_menu_gid =
        cui_menu_create(
            GRP_ID_MOBILE_TV_PLAYER,
            CUI_MENU_SRC_TYPE_RESOURCE,
            CUI_MENU_TYPE_OPTION,
            MENU_ID_MOBILE_TV_PLAYER_CL_OPTION,
            MMI_FALSE,
            NULL);
    cui_menu_run(mtv_player_p->cl_option_menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_entry_option_menu_screen
 * DESCRIPTION
 *  mobile tv player option menu screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 #if  !defined (__DISABLE_MTV_SETTINGS__) || !defined (__ATV_NO_PHONE_STORAGE__) ||(defined(__MMI_MTV_A2DP_SUPPORT__) && !defined(__MMI_A2DP_HIDE_BT_SETTINGS__))
 void mmi_mtv_player_entry_option_menu_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->option_menu_gid =
        cui_menu_create(
            GRP_ID_MOBILE_TV_PLAYER,
            CUI_MENU_SRC_TYPE_RESOURCE,
            CUI_MENU_TYPE_OPTION,
            MENU_ID_MOBILE_TV_PLAYER_OPTION,
            MMI_FALSE,
            NULL);
    cui_menu_run(mtv_player_p->option_menu_gid);
}
#endif/*settings & storage & bluetooth all turn off*/


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_draw_preview_icon
 * DESCRIPTION
 *  hint user it is a broken channel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_MTV_PREVIEW_SUPPORT__ 
 void mmi_mtv_player_draw_preview_icon(mtv_player_preview_icon_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Avoid draw animation on hw updating layer */
    if (PLAYER_STATE_IN(MTV_PLAYER_PLAY))
    {
        return;
    }
    mdi_util_hw_layer_switch_to_sw_layer(mtv_player_p->cl_preview_layer_handle);
    gdi_layer_push_and_set_active(mtv_player_p->cl_preview_layer_handle);
    gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
    gdi_layer_clear(GDI_COLOR_BLACK);

    switch (type)
    {
        case MTV_PLAYER_PREVIEW_ICON_BROKEN:
            gdi_image_draw_id(0,0,IMG_ID_MOBILE_TV_BROKEN_CHANNEL);
            break;
        default:
            break;
    }


    gdi_layer_pop_and_restore_active();
    gdi_layer_blt_previous(
        mtv_player_p->cl_preview_layer_offset_x,
        mtv_player_p->cl_preview_layer_offset_y,
        mtv_player_p->cl_preview_layer_offset_x + mtv_player_p->cl_preview_layer_width - 1,
        mtv_player_p->cl_preview_layer_offset_y + mtv_player_p->cl_preview_layer_height - 1);
}
#endif/*__MMI_MTV_PREVIEW_SUPPORT__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_vol_inc
 * DESCRIPTION
 *  The function is to increase volume
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_vol_inc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mtv_player_p->setting.vol_level < MTV_PLAYER_VOL_16)
    {
        mtv_player_p->setting.vol_level ++;
        mdi_audio_set_volume(MTV_VOLUME_TYPE, (U8) MDI_AUD_VOL_EX_MUTE(mtv_player_p->setting.vol_level));

        mtv_player_p->setting.is_mute = KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_vol_dec
 * DESCRIPTION
 *  The function is to decrease volume
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_vol_dec(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_VOL_DEC;

    if (mtv_player_p->setting.vol_level > MTV_PLAYER_VOL_MUTE)
    {
        mtv_player_p->setting.vol_level --;
        mtv_player_p->setting.is_mute = !mtv_player_p->setting.vol_level;
        mdi_audio_set_volume(MTV_VOLUME_TYPE, (U8) MDI_AUD_VOL_EX_MUTE(mtv_player_p->setting.vol_level));

      //  mtv_player_p->setting.is_mute = KAL_FALSE;
    }
}

#ifdef __ATV_SMS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_stop_video_handler
 * DESCRIPTION
 *  channel list stop video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_stop_video_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((KERNEL_STATE_IN(MTV_KERNEL_READY) || KERNEL_STATE_IN(MTV_KERNEL_INIT)))
    {
#ifdef   __MMI_MTV_RECORD_SUPPORT__
        /* if recorder is recording, don't channel channel */
        if (!RECORDER_STATE_IN(MTV_RECORDER_STOPPED))
        {
            return;
        }
#endif
        /* stop player and then stop service */
        if (PLAYER_STATE_IN(MTV_PLAYER_PLAY)||PLAYER_STATE_IN(MTV_PLAYER_BT_CONNECT))
        {
            mtv_player_p->last_error = mmi_mtv_player_player_enter_state(MTV_PLAYER_STOPPED);
        }

        ret = mmi_mtv_player_kernel_enter_state(MTV_KERNEL_OPENED);

        ASSERT(ret == MDI_RES_MTV_SUCCEED);
    }
}
#endif

#ifdef __MMI_MTV_PREVIEW_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_pre_highlight_handler
 * DESCRIPTION
 *  channel list pre-highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_pre_highlight_handler(S32 index, MMI_BOOL force_player_stop)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (force_player_stop)
    {
        if (PLAYER_STATE_IN(MTV_PLAYER_PLAY)||PLAYER_STATE_IN(MTV_PLAYER_BT_CONNECT))
        {
            mtv_player_p->last_error = mmi_mtv_player_player_enter_state(MTV_PLAYER_STOPPED);
        }
        return;
    }

    /* When entry or go back to channel list, don't stop the service */
    if (mtv_player_p->setting.selected_channel == index)
    {
        return;
    }

    if ((KERNEL_STATE_IN(MTV_KERNEL_READY) || KERNEL_STATE_IN(MTV_KERNEL_INIT)))
    {
#ifdef   __MMI_MTV_RECORD_SUPPORT__
        /* if recorder is recording, don't channel channel */
        if (!RECORDER_STATE_IN(MTV_RECORDER_STOPPED))
        {
            return;
        }
#endif
        /* stop player and then stop service */
        if (PLAYER_STATE_IN(MTV_PLAYER_PLAY)||PLAYER_STATE_IN(MTV_PLAYER_BT_CONNECT))
        {
            mtv_player_p->last_error = mmi_mtv_player_player_enter_state(MTV_PLAYER_STOPPED);
        }

        ret = mmi_mtv_player_kernel_enter_state(MTV_KERNEL_OPENED);

        ASSERT(ret == MDI_RES_MTV_SUCCEED);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_post_highlight_handler
 * DESCRIPTION
 *  channel list callback for redraw preview screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_post_highlight_handler(gdi_handle preview_handle, U32 blt_layer_flag, U32 preview_layer_flag, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen_id = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_POST_HILIGHT_HDLR);

    mtv_player_p->cl_preview_layer_handle = preview_handle;
    mtv_player_p->cl_blt_layer_flag = blt_layer_flag;
    mtv_player_p->cl_preview_layer_flag = preview_layer_flag;
    mtv_player_p->cl_preview_layer_offset_x = x;
    mtv_player_p->cl_preview_layer_offset_y = y;
    mtv_player_p->cl_preview_layer_width = width;
    mtv_player_p->cl_preview_layer_height = height;

#if !defined(__MTK_TARGET__)
    if (mtv_player_p->is_before_cat265==TRUE)
    {
        return;
    }
#endif

    /* Reset preview layer as black color and blt */
    if (PLAYER_STATE_IN(MTV_PLAYER_STOPPED))
    {
        mdi_util_hw_layer_switch_to_sw_layer(preview_handle);
        /* If player is PLAYING, Don't reset the layer */
        gdi_layer_push_and_set_active(preview_handle);
        gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
        gdi_layer_blt_previous(x, y, x + width-1, y + height - 1);
    }

    if (active_screen_id == SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST && !mtv_player_p->is_frist)
    {
        StopTimer(MTV_PLAYER_CHANNEL_LIST_DELAY_TIMER);
        StartTimer(
            MTV_PLAYER_CHANNEL_LIST_DELAY_TIMER,
            200,
            mmi_mtv_player_delay_post_highlight_handler);
    }
    else
    {
        mmi_mtv_player_delay_post_highlight_handler();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_delay_post_highlight_handler
 * DESCRIPTION
 *  channel list callback for redraw preview screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_delay_post_highlight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->is_frist = MMI_FALSE;
    if (KERNEL_STATE_IN(MTV_KERNEL_OPENED) && mtv_player_p->num_services > 0)
    {
        ret = mmi_mtv_player_kernel_enter_state(MTV_KERNEL_INIT);
        if (ret != MDI_RES_MTV_SUCCEED)
        {
            mmi_mtv_player_draw_preview_icon(MTV_PLAYER_PREVIEW_ICON_BROKEN);
        }
    }
    else if (KERNEL_STATE_IN(MTV_KERNEL_READY) && PLAYER_STATE_IN(MTV_PLAYER_STOPPED))
    {
    #if defined(__MMI_MTV_A2DP_SUPPORT__)
        if (mmi_mtv_player_is_output_to_bt()&& !mmi_mtv_player_is_in_background_call())
        {
            mmi_mtv_player_player_enter_state(MTV_PLAYER_BT_CONNECT);
        }
        else
        {
            mmi_mtv_player_player_enter_state(MTV_PLAYER_PLAY);
        }
    #else
        mmi_mtv_player_player_enter_state(MTV_PLAYER_PLAY);
    #endif
        if (mtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
        {
            mmi_mtv_player_draw_preview_icon(MTV_PLAYER_PREVIEW_ICON_BROKEN);
        }
    }
}
#endif/*__MMI_MTV_PREVIEW_SUPPORT__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_get_active_channel_ptr
 * DESCRIPTION
 *  get current active channel pointer
 * PARAMETERS
 *  void
 * RETURNS
 *  S32 active channel idx
 *****************************************************************************/
mtv_player_service_info_struct *mmi_mtv_player_get_active_channel_ptr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    idx = mtv_player_p->setting.selected_channel;
    return &mtv_player_p->services[idx];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_set_selected_service
 * DESCRIPTION
 *  high light handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_set_selected_service(S32 service_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mtv_player_p->setting.selected_channel != service_idx)
    {
        mtv_player_p->prev_selected_service = mtv_player_p->setting.selected_channel;
    }
    mtv_player_p->setting.selected_channel = service_idx;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_SELECTED_SERVICE, service_idx, __LINE__);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_highlight_channel_hdlr
 * DESCRIPTION
 *  high light handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_highlight_channel_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mtv_player_service_info_struct* info_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_HILIGHT_HDLR, index);

    mmi_mtv_player_set_selected_service(index);

 #ifdef __MMI_MTV_PREVIEW_SUPPORT__
    info_ptr = &mtv_player_p->services[index];

    /* Center key */
    #ifndef __MMI_WGUI_DISABLE_CSK__
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    #endif
    SetCenterSoftkeyFunction(mmi_mtv_player_select_channel_to_play, KEY_EVENT_UP);

    /* LSK */
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
    SetLeftSoftkeyFunction(mmi_mtv_player_entry_cl_option_screen, KEY_EVENT_UP);

    wgui_cat265_set_preview_name((U8*)info_ptr->service_name);
 #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_cat265_get_async_items
 * DESCRIPTION
 *  ?
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_mtv_player_cat265_get_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    mtv_player_service_info_struct* info_ptr;
    CHAR buffer[10];
    CHAR UCS2_buffer[16];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    info_ptr = &mtv_player_p->services[start_indx];

    for (i = 0; i < num_item; ++i)
    {
        sprintf((CHAR*) buffer, "CH%2d", info_ptr->service_number);
        mmi_asc_to_ucs2((CHAR*) UCS2_buffer, (CHAR*) buffer);

        /* subject */
        mmi_ucs2cpy((CHAR*) menuData[i].item_list[0], (CHAR*) &UCS2_buffer[0]);
        mmi_ucs2cpy((CHAR*) menuData[i].item_list[1], (CHAR*) info_ptr->service_name);

        if (info_ptr->service_type == MEDIA_MTV_SERVICE_ANALOG_TV)
        {
            menuData[i].image_list[0] = (PU8) GetImage(IMG_ID_MOBILE_TV_PLAYER_DTV);
        }

        info_ptr = info_ptr + 1;
    }
    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_entry_channel_list_screen
 * DESCRIPTION
 *  mobile tv player channel list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_entry_channel_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    MMI_BOOL is_double_line = MMI_FALSE;
    U16 title_string_id;
    S32 num_menu_items;
  #ifndef __MMI_MTV_PREVIEW_SUPPORT__
	MDI_RESULT ret = 0;//add;
	S32 error = 0;
  #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MM_DCM_SUPPORT__
    //  for atv drv share pool with ime
    if (MMI_TRUE == g_is_engine_paused)
    {
        mdi_mtv_resume_engine();
        g_is_engine_paused = MMI_FALSE;
    }
#endif

    if (!mmi_frm_scrn_enter(
                GRP_ID_MOBILE_TV_PLAYER,
                SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST,
                mmi_mtv_player_exit_channel_list_screen,
                mmi_mtv_player_entry_channel_list_screen,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    gui_screen_switch_effect_block(MMI_TRUE);
    mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGH_SCRN);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    mmi_mtv_player_unset_flag(MTV_PLAYER_UNAVAILABLE_IN_CALL);

    mmi_mtv_player_check_bg_snd();

    /* Register bt callback */
#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_register_volume_sync_callback(
        APP_MOBILE_TV_PLAYER,
        MDI_AUD_VOL_LEVEL_EXTEND_MUTE,
        mmi_mtv_player_bt_volume_sync_hdlr);
#endif

    ClearInputEventHandler(MMI_DEVICE_KEY);

    /* Set preview title */
    RegisterHighlightHandler(mmi_mtv_player_highlight_channel_hdlr);

    title_string_id = STR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST;
    num_menu_items = mtv_player_p->num_services;


    /* Change highlight index */
    if (guiBuffer != NULL)
    {
        change_list_menu_category_history(
            guiBuffer,
            mtv_player_p->setting.selected_channel,
            num_menu_items,
            0);
    }
    mtv_player_p->is_frist = MMI_TRUE;
#ifdef __MMI_MTV_PREVIEW_SUPPORT__
    mtv_player_p->is_before_cat265 = MMI_TRUE;
    ShowCategory265Screen(
        (UI_string_type) GetString(title_string_id),
		(PU8)get_image(GetRootTitleIcon(MENU_ID_MOBILE_TV_PLAYER_APP)),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        is_double_line,
        num_menu_items,
        mmi_mtv_player_cat265_get_async_items,
        NULL,
        mmi_mtv_player_pre_highlight_handler,   /* Stop the last preview */
        mmi_mtv_player_post_highlight_handler,  /* Start the current preview */
        mtv_player_p->setting.selected_channel,
        guiBuffer);

    mtv_player_p->is_before_cat265 = MMI_FALSE;

#if !defined(__MTK_TARGET__)
    if (num_menu_items != 0)
    {
        mmi_mtv_player_post_highlight_handler(
            mtv_player_p->cl_preview_layer_handle,
            mtv_player_p->cl_blt_layer_flag,
            mtv_player_p->cl_preview_layer_flag,
            mtv_player_p->cl_preview_layer_offset_x,
            mtv_player_p->cl_preview_layer_offset_y,
            mtv_player_p->cl_preview_layer_width,
            mtv_player_p->cl_preview_layer_height);
    }
#endif

#else  /*__MMI_ATV_OSD_SUPPORT__ */
    /* For go back from main screen */
    if (KERNEL_STATE_IN(MTV_KERNEL_READY))
    {
        ret = mmi_mtv_player_kernel_enter_state(MTV_KERNEL_OPENED);

        ASSERT(ret == MDI_RES_MTV_SUCCEED);
    }
    wgui_cat1007_show(
        (WCHAR*)GetString(title_string_id),
        (PU8)get_image(GetRootTitleIcon(MENU_ID_MOBILE_TV_PLAYER_APP)),
        (WCHAR*)GetString(STR_GLOBAL_OPTIONS),
        (PU8)get_image(IMG_GLOBAL_OPTIONS),
        (WCHAR*)GetString(STR_GLOBAL_BACK),
        (PU8)get_image(IMG_GLOBAL_BACK),
        is_double_line,
        num_menu_items,
        mmi_mtv_player_cat265_get_async_items,
        NULL,
        mtv_player_p->setting.selected_channel,
        guiBuffer,
        &error);
#endif  /*__MMI_ATV_OSD_SUPPORT__ */

    SetLeftSoftkeyFunction(mmi_mtv_player_entry_cl_option_screen, KEY_EVENT_UP);

    if(0!=mtv_player_p->num_services)
    {
#ifndef __MMI_WGUI_DISABLE_CSK__
       ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
       SetCenterSoftkeyFunction(mmi_mtv_player_select_channel_to_play, KEY_EVENT_UP);
    }
    else
    {
#ifndef __MMI_WGUI_DISABLE_CSK__
       ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
       SetCenterSoftkeyFunction(mmi_mtv_player_entry_cl_option_screen, KEY_EVENT_UP);
    }

    /* RSK */
    SetRightSoftkeyFunction(mmi_mtv_player_cancel_select_channel, KEY_EVENT_UP);

    SetKeyHandler(mmi_mtv_player_vol_inc, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_vol_dec, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(mmi_mtv_player_vol_inc, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_vol_inc, KEY_VOL_UP, KEY_EVENT_LONG_PRESS);
    SetKeyHandler(mmi_mtv_player_vol_inc, KEY_VOL_UP, KEY_EVENT_REPEAT);

    SetKeyHandler(mmi_mtv_player_vol_dec, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_vol_dec, KEY_VOL_DOWN, KEY_EVENT_LONG_PRESS);
    SetKeyHandler(mmi_mtv_player_vol_dec, KEY_VOL_DOWN, KEY_EVENT_REPEAT);

#if !(defined(__MMI_ATV_SUPPORT__) && defined(__MMI_FTE_SUPPORT__))
    SetKeyHandler(mmi_mtv_player_vol_status_icon_press, KEY_POUND, KEY_EVENT_DOWN);
#endif /* defined(__MMI_ATV_SUPPORT__) && !defined(__MMI_FTE_SUPPORT__) */

}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_setting_set_value
 * DESCRIPTION
 *  set MTV PLAYER setting values
 * PARAMETERS
 *  void
 *  idx(?)
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __DISABLE_MTV_SETTINGS__
 void mmi_mtv_player_setting_set_value(MMI_ID sender_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_id;
    S32 mode_index;
    U8 selected_index;
    mtv_player_service_info_struct *info_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Brightness */
    cui_inline_get_value(
        sender_id,
        MMI_MTV_BRIGHTNESS_SELECTOR,
        &mtv_player_p->setting.brightness);
    mdi_mtv_set_brightness(mtv_player_p->setting.brightness);

    /* Contrast */
    cui_inline_get_value(
        sender_id,
        MMI_MTV_CONTRAST_SELECTOR,
        &mtv_player_p->setting.contrast);
    mdi_mtv_set_contrast(mtv_player_p->setting.contrast);

    /* Saturation */
    cui_inline_get_value(
        sender_id,
        MMI_MTV_SATURATION_SELECTOR,
        &mtv_player_p->setting.saturation);
    mdi_mtv_set_saturation(mtv_player_p->setting.saturation);

    /* Audio mode */
    item_id = cui_inline_get_item_id_by_index(sender_id, 7);
    if (item_id == MMI_MTV_AUDIO_MODE_SELECTOR)
    {
        cui_inline_get_value(
            sender_id,
            MMI_MTV_AUDIO_MODE_SELECTOR,
            &selected_index);

        mode_index = mmi_mtv_player_get_audio_mode_index(selected_index);

        info_ptr = mmi_mtv_player_get_active_channel_ptr();
        info_ptr->audio_mode = mmi_atv_aud_mode[mode_index];

        mdi_mtv_set_audio_mode(mtv_player_p->mtv_handle, info_ptr->service_id, mmi_atv_aud_mode[mode_index]);
    }

#ifdef __MMI_MTV_RECORD_SUPPORT__
    /* Record size */
    cui_inline_get_value(
        sender_id,
        MMI_MTV_RECORD_SIZE_SELECTOR,
        &selected_index);

    mtv_player_p->setting.record_size =
        mmi_mtv_player_get_record_size(selected_index);

    mdi_mtv_set_record_size(mtv_player_p->setting.record_size);
#endif

    mmi_mtv_player_store_setting();
   // mmi_mtv_player_display_popup(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS);
    mmi_frm_scrn_close_active_id();

}
#endif/*__DISABLE_MTV_SETTINGS__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_entry_settings_screen
 * DESCRIPTION
 *  mobile tv player settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __DISABLE_MTV_SETTINGS__
 void mmi_mtv_player_entry_settings_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 mode_num = 0, mode_index = 0;
    MMI_ID cui_id;
#ifdef __MMI_MTV_RECORD_SUPPORT__
    U8 selected_idx;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cui_id = cui_inline_create(GRP_ID_MOBILE_TV_PLAYER, &g_mtv_setting_inline);
    mtv_player_p->ps_inline_gid = cui_id;

    /* Brightness */
    cui_inline_set_value(
        cui_id,
        MMI_MTV_BRIGHTNESS_SELECTOR,
        (void*)mtv_player_p->setting.brightness);
#ifndef __MMI_INLINE_SLIM__
    cui_inline_set_item_attributes(
        cui_id, MMI_MTV_BRIGHTNESS_SELECTOR, CUI_INLINE_SET_ATTRIBUTE,
        CUI_INLINE_ITEM_SELECT_NO_LOOP);
#endif
    /* Contrast */
    cui_inline_set_value(
        cui_id,
        MMI_MTV_CONTRAST_SELECTOR,
        (void*)mtv_player_p->setting.contrast);
#ifndef __MMI_INLINE_SLIM__
    cui_inline_set_item_attributes(
        cui_id, MMI_MTV_CONTRAST_SELECTOR, CUI_INLINE_SET_ATTRIBUTE,
        CUI_INLINE_ITEM_SELECT_NO_LOOP);
#endif
    /* Saturation */
    cui_inline_set_value(
        cui_id,
        MMI_MTV_SATURATION_SELECTOR,
        (void*)mtv_player_p->setting.saturation);
#ifndef __MMI_INLINE_SLIM__
    cui_inline_set_item_attributes(
        cui_id, MMI_MTV_SATURATION_SELECTOR, CUI_INLINE_SET_ATTRIBUTE,
        CUI_INLINE_ITEM_SELECT_NO_LOOP);
#endif
    /* Audio mode */
    mmi_mtv_player_prepare_audio_mode_list(&mode_num, &mode_index);

    if (mode_num == 0)
    {
        cui_inline_delete_item(cui_id, MMI_MTV_AUDIO_MODE_CAPTION);
        cui_inline_delete_item(cui_id, MMI_MTV_AUDIO_MODE_DISPLAY_ONLY);
        cui_inline_delete_item(cui_id, MMI_MTV_AUDIO_MODE_SELECTOR);
    }
    else if (mode_num == 1)
    {
        cui_inline_set_value(
            cui_id,
            MMI_MTV_AUDIO_MODE_DISPLAY_ONLY,
            mtv_player_setting_p->aud_mode_str[0]);

        cui_inline_delete_item(cui_id, MMI_MTV_AUDIO_MODE_SELECTOR);
    }
    else
    {
        cui_inline_set_item_select(
            cui_id,
            MMI_MTV_AUDIO_MODE_SELECTOR,
            mode_num,
            (PU8*)mtv_player_setting_p->aud_mode_str,
            mode_index);
        cui_inline_delete_item(
            cui_id, MMI_MTV_AUDIO_MODE_DISPLAY_ONLY);
    }

#ifdef __MMI_MTV_RECORD_SUPPORT__
    /* Record size */
    if (mode_num == 0)
    {
        cui_inline_set_item_icon(
            cui_id,
            MMI_MTV_RECORD_SIZE_CAPTION,
            MMI_MTV_IMG_RECORD_SIZE - 1);
    }

    selected_idx = (U8)mmi_mtv_player_get_record_size_index((mdi_mtv_recorder_size_enum)mtv_player_p->setting.record_size);

    cui_inline_set_item_select(
            cui_id,
            MMI_MTV_RECORD_SIZE_SELECTOR,
            mtv_player_p->record_size_num,
            (PU8*)mtv_player_setting_p->record_size_str,
            selected_idx);

#endif

    cui_inline_run(cui_id);
}
#endif/*__DISABLE_MTV_SETTINGS__*/
#ifndef __ATV_NO_PHONE_STORAGE__


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_check_and_restore_valid_drv
 * DESCRIPTION
 *  Check if desired path is ready or not. If not, will restore to valid path.
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
 MMI_BOOL mmi_mtv_player_check_and_restore_valid_drv(MMI_BOOL restore, U16 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    /* In exit_usb_mode_callback, is_in_mass_storage_mode() will return true */
    if (srv_usb_is_in_mass_storage_mode() && !srv_usb_is_leaving_ms_mode())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_VAL1, 0, __LINE__);
        return MMI_FALSE;
    }
#endif

    /* check if the drive exist */
    ret = FS_GetDevStatus(storage, FS_MOUNT_STATE_ENUM);
    if (ret == FS_NO_ERROR)
    {
        return MMI_TRUE;
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_VAL1, ret, __LINE__);
        if (restore == MMI_FALSE)
        {
            return MMI_FALSE;
        }

        ret = FS_GetDevStatus(SRV_FMGR_PUBLIC_DRV, FS_MOUNT_STATE_ENUM);
        if (ret == FS_NO_ERROR)
        {
            /* change storage to valid drive */
            mtv_player_p->setting.storage = (U16) SRV_FMGR_PUBLIC_DRV;
            mmi_mtv_player_store_setting();
            return MMI_TRUE;
        }
        else
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_VAL1, ret, __LINE__);
            return MMI_FALSE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_entry_storage_screen
 * DESCRIPTION
 *  mobile tv player storage setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_entry_storage_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cui_id = cui_storage_selector_create(
                GRP_ID_MOBILE_TV_PLAYER,
                mtv_player_p->setting.storage,
                CUI_STORAGE_SELECTOR_DRV_TYPE_ACCESIBLE);
    cui_storage_selector_run(cui_id);

#if 0
/* under construction !*/
/* under construction !*/
#endif
}
 #endif


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_update_channel_list
 * DESCRIPTION
 *  command: update channel list from channel list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_update_channel_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_mtv_player_is_in_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return; /* return directly */
    }


    if (KERNEL_STATE_IN(MTV_KERNEL_READY)|| KERNEL_STATE_IN(MTV_KERNEL_INIT))
    {
        /* stop service */
        ret = mmi_mtv_player_kernel_enter_state(MTV_KERNEL_OPENED);
        ASSERT(ret == MDI_RES_MTV_SUCCEED);
    }

    /* Reset highlight index after stopping original service */
    mtv_player_p->setting.selected_channel = 0;
    mtv_player_p->prev_selected_service = 0;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_SELECTED_SERVICE, 0, __LINE__);

    mtv_player_p->setting.is_channel_list_init = MMI_FALSE;

    mmi_mtv_player_enter_scan_channel();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_remove_active_service
 * DESCRIPTION
 *  The function is to remove active service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __DISABLE_MTV_DELETE_CHANNEL__
 void mmi_mtv_player_remove_active_service(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 service_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    service_index = mtv_player_p->setting.selected_channel;

    /* Shift the services by one */
    for (i = service_index; i < mtv_player_p->num_services - 1; i ++)
    {
        kal_mem_cpy(
            &mtv_player_p->services[i],
            &mtv_player_p->services[i+1],
            sizeof(mtv_player_service_info_struct));
    }

    /* Decrease the number of total services */
    mtv_player_p->num_services --;
    if (mtv_player_p->num_services == 0)
    {
        mtv_player_p->setting.is_channel_list_init = MMI_FALSE;
    }
}
#endif/*__DISABLE_MTV_DELETE_CHANNEL__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_config_option_menu
 * DESCRIPTION
 *  mobile tv player configure option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_config_option_menu(MMI_ID send_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 #if defined(__MMI_MTV_A2DP_SUPPORT__) && !defined(__MMI_A2DP_HIDE_BT_SETTINGS__)
    MMI_BOOL bt_menu = MMI_TRUE;
 #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifndef __ATV_NO_PHONE_STORAGE__

#if defined(__MMI_MTV_RECORD_SUPPORT__) || defined(__MMI_MTV_SNAPSHOT_SUPPORT__)
    /* if it is recording, hide some menu */
    if (!RECORDER_STATE_IN(MTV_RECORDER_STOPPED)
#ifdef __USB_IN_NORMAL_MODE__
        || srv_usb_is_in_mass_storage_mode()
#endif
        )
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_MOBILE_TV_PLAYER_OPTION_STORAGE, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_MOBILE_TV_PLAYER_OPTION_STORAGE, MMI_FALSE);
    }
#else
    cui_menu_set_item_hidden(
            send_id, MENU_ID_MOBILE_TV_PLAYER_OPTION_STORAGE, MMI_TRUE);
#endif /* __MMI_MTV_RECORD_SUPPORT__ */
#endif


#if defined(__MMI_MTV_A2DP_SUPPORT__) && !defined(__MMI_A2DP_HIDE_BT_SETTINGS__)
#if !defined(__ATV_I2S_SUPPORT__)
    /* BT: In ATV, only I2S supports A2DP */
    bt_menu = MMI_FALSE;
#else /* !defined(__ATV_I2S_SUPPORT__) */
    if (!mmi_bt_is_to_display_bt_menu())
    {
        bt_menu = MMI_FALSE;
    }
#endif /* !defined(__ATV_I2S_SUPPORT__) */
    if (bt_menu)
    {
        cui_menu_set_item_hidden(send_id, MENU_ID_MOBILE_TV_PLAYER_OPTION_BLUETOOTH_SETTING, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(send_id, MENU_ID_MOBILE_TV_PLAYER_OPTION_BLUETOOTH_SETTING, MMI_TRUE);
    }
#endif  /* __MMI_MTV_A2DP_SUPPORT__ && !__MMI_A2DP_HIDE_BT_SETTINGS__ */

#if defined(__ATV_SMS_SUPPORT__)
    cui_menu_set_item_hidden(
            send_id, MENU_ID_MOBILE_TV_PLAYER_OPTION_WRITE_MESSAGE, MMI_FALSE);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_config_cl_option_menu
 * DESCRIPTION
 *  mobile tv player configure channel list option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_config_cl_option_menu(MMI_ID send_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num_menu_items;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    num_menu_items = mtv_player_p->num_services;

    if(num_menu_items == 0)
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_MOBILE_TV_PLAYER_CL_OPTION_PLAY, MMI_TRUE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_MOBILE_TV_PLAYER_CL_OPTION_UPDATE, MMI_FALSE);

      #ifndef __DISABLE_MTV_RENAME_CHANNEL__
        cui_menu_set_item_hidden(
            send_id, MENU_ID_MOBILE_TV_PLAYER_CL_OPTION_RENAME, MMI_TRUE);
	  #endif/*__DISABLE_MTV_RENAME_CHANNEL__*/
	  #ifndef __DISABLE_MTV_DELETE_CHANNEL__
        cui_menu_set_item_hidden(
            send_id, MENU_ID_MOBILE_TV_PLAYER_CL_OPTION_DELETE, MMI_TRUE);
      #endif/*__DISABLE_MTV_DELETE_CHANNEL__*/
        return;
    }

    ASSERT(num_menu_items > 0);

    /* play */
    cui_menu_set_item_hidden(
        send_id, MENU_ID_MOBILE_TV_PLAYER_CL_OPTION_PLAY, MMI_FALSE);


    /* Band, Update, delete, rename */
#ifdef   __MMI_MTV_RECORD_SUPPORT__
    if (!RECORDER_STATE_IN(MTV_RECORDER_STOPPED))
    {
      #ifndef __DISABLE_MTV_DELETE_CHANNEL__
        cui_menu_set_item_hidden(
            send_id, MENU_ID_MOBILE_TV_PLAYER_CL_OPTION_DELETE, MMI_TRUE);
	  #endif/*__DISABLE_MTV_DELETE_CHANNEL__*/
        cui_menu_set_item_hidden(
            send_id, MENU_ID_MOBILE_TV_PLAYER_CL_OPTION_UPDATE, MMI_TRUE);
    }
    else
#endif
    {
      #ifndef __DISABLE_MTV_DELETE_CHANNEL__
        cui_menu_set_item_hidden(
            send_id, MENU_ID_MOBILE_TV_PLAYER_CL_OPTION_DELETE, MMI_FALSE);
	  #endif/*__DISABLE_MTV_DELETE_CHANNEL__*/
        cui_menu_set_item_hidden(
                send_id, MENU_ID_MOBILE_TV_PLAYER_CL_OPTION_UPDATE, MMI_FALSE);
    }

  #ifndef __DISABLE_MTV_RENAME_CHANNEL__
    cui_menu_set_item_hidden(
            send_id, MENU_ID_MOBILE_TV_PLAYER_CL_OPTION_RENAME, MMI_FALSE);
  #endif/*__DISABLE_MTV_RENAME_CHANNEL__*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_menu_entry_event_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_menu_entry_event_hdlr(cui_menu_event_struct* menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID sender_id = menu_evt->sender_id;
    MMI_ID menu_id = menu_evt->parent_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mtv_player_check_bg_snd();	
    if (menu_id == MENU_ID_MOBILE_TV_PLAYER_OPTION)
    {
        mmi_mtv_player_config_option_menu(sender_id);
    }
    else if (menu_id == MENU_ID_MOBILE_TV_PLAYER_CL_OPTION)
    {
        mmi_mtv_player_config_cl_option_menu(sender_id);
    }
    cui_menu_set_currlist_title(
        sender_id,
        (WCHAR*)GetString(STR_GLOBAL_OPTIONS),
        (UI_image_type)GetImage(GetRootTitleIcon(MAIN_MENU_MULTIMEDIA_MENUID)));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_menu_select_event_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_menu_select_event_hdlr(cui_menu_event_struct* menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID menu_id = menu_evt->highlighted_menu_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Channel list option */
    if (menu_id == MENU_ID_MOBILE_TV_PLAYER_CL_OPTION_PLAY)
    {
        mmi_mtv_player_select_channel_to_play();

    }
    else if (menu_id == MENU_ID_MOBILE_TV_PLAYER_CL_OPTION_UPDATE)
    {
        mmi_mtv_player_entry_band_screen();
    }
#ifndef __DISABLE_MTV_RENAME_CHANNEL__
    else if (menu_id == MENU_ID_MOBILE_TV_PLAYER_CL_OPTION_RENAME)
    {
        mmi_mtv_player_entry_rename_screen();
    }
#endif/*__DISABLE_MTV_RENAME_CHANNEL__*/
#ifndef __DISABLE_MTV_DELETE_CHANNEL__
    else if (menu_id == MENU_ID_MOBILE_TV_PLAYER_CL_OPTION_DELETE)
    {
        mmi_mtv_player_display_confirm(STR_ID_MOBILE_TV_PLAYER_DELETE_ASK);
    }
#endif/*__DISABLE_MTV_DELETE_CHANNEL__*/
#ifdef __ATV_SMS_SUPPORT__
    else if(menu_id == MENU_ID_MOBILE_TV_PLAYER_OPTION_WRITE_MESSAGE)
    {
        mmi_mtv_sms_launch(
            mtv_player_p->adm_pool_id,
            mmi_mtv_player_post_highlight_handler,
            mmi_mtv_player_stop_video_handler);
    }
#endif /* __ATV_SMS_SUPPORT__ */
#ifndef __DISABLE_MTV_SETTINGS__
    else if (menu_id == MENU_ID_MOBILE_TV_PLAYER_OPTION_SETTING)
    {
        mmi_mtv_player_entry_settings_screen();
    }
#endif/*__DISABLE_MTV_SETTINGS__*/
#if defined(__MMI_MTV_A2DP_SUPPORT__) && !defined(__MMI_A2DP_HIDE_BT_SETTINGS__)
    else if (menu_id == MENU_ID_MOBILE_TV_PLAYER_OPTION_BLUETOOTH_SETTING)
    {
        mmi_a2dp_entry_bluetooth_settings();
    }
#endif
#ifndef __ATV_NO_PHONE_STORAGE__
    else if (menu_id == MENU_ID_MOBILE_TV_PLAYER_OPTION_STORAGE)
    {
        mmi_mtv_player_entry_storage_screen();
    }
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_storage_selector_event_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 #ifndef __ATV_NO_PHONE_STORAGE__
void mmi_mtv_player_storage_selector_event_hdlr(
        cui_storage_selector_result_event_struct* storage_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR drive;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* User chooses a storage */
    if (storage_evt->result > 0)
    {
        /* User chooses a storage */
        drive = cui_storage_selector_get_selected_drive_letter(
                    storage_evt->sender_id);
        mmi_mtv_player_set_storage(drive);
    }

    cui_storage_selector_close(storage_evt->sender_id);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_group_proc
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_mtv_player_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;
#ifndef __ATV_NO_PHONE_STORAGE__
    cui_storage_selector_result_event_struct *storage_evt;
#endif
    cui_fseditor_evt_struct *editor_evt;
    cui_event_inline_common_struct *inline_evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_FIRST_ENTRY:
        case EVT_ID_GROUP_ACTIVE:
        case EVT_ID_GROUP_INACTIVE:
            break;

        case EVT_ID_GROUP_DEINIT:
            //maybe no need
            //mmi_mtv_player_del_app_main_scr_hdlr();

            if(KERNEL_STATE_IN(MTV_KERNEL_CLOSED))
            {
                mmi_mtv_player_free_adm_structure();
               /* Delete adm */
                mmi_mtv_player_delete_adm();

                if (mtv_player_p->app_mem_pool != NULL)
                {
                    /* free app-based memory */
                    applib_mem_ap_free((void*)mtv_player_p->app_mem_pool);
                    mtv_player_p->app_mem_pool = NULL;
                }
            }
#ifdef __MMI_AP_DCM_MATV__
            mmi_ap_post_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_MATV);
#endif
            break;

        /**********************************************
         *  Menu CUI
         **********************************************/
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            menu_evt = (cui_menu_event_struct*)evt;
            mmi_mtv_player_menu_entry_event_hdlr(menu_evt);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
        {
            menu_evt = (cui_menu_event_struct*)evt;
            mmi_mtv_player_menu_select_event_hdlr(menu_evt);
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            menu_evt = (cui_menu_event_struct*)evt;
            cui_menu_close(menu_evt->sender_id);
            if (menu_evt->sender_id == mtv_player_p->cl_option_menu_gid)
            {
                mtv_player_p->cl_option_menu_gid = GRP_ID_INVALID;
            }
            else if (menu_evt->sender_id == mtv_player_p->option_menu_gid)
            {
                mtv_player_p->option_menu_gid = GRP_ID_INVALID;
            }
            break;
        }
        /**********************************************
         *  Storage Selector CUI
         **********************************************/
#ifndef __ATV_NO_PHONE_STORAGE__
        case EVT_ID_CUI_STORAGE_SELECTOR_RESULT:
        {
            storage_evt = (cui_storage_selector_result_event_struct *)evt;
            mmi_mtv_player_storage_selector_event_hdlr(storage_evt);
            break;
        }
#endif
        /**********************************************
         *  Inline Selector CUI
         **********************************************/
    #ifndef __DISABLE_MTV_SETTINGS__
        case EVT_ID_CUI_INLINE_ABORT:
        {
            inline_evt = (cui_event_inline_common_struct *)evt;
            cui_inline_close(inline_evt->sender_id);
            break;
        }
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            inline_evt = (cui_event_inline_common_struct *)evt;
            if (inline_evt->sender_id == mtv_player_p->ps_inline_gid)
            {
                /* Player Setting */
                mmi_mtv_player_setting_set_value(inline_evt->sender_id);
                cui_inline_close(inline_evt->sender_id);
            }

            break;
        }
	 #endif/*__DISABLE_MTV_SETTINGS__*/

        /**********************************************
         *  Editor Selector CUI
         **********************************************/
     #ifndef __DISABLE_MTV_RENAME_CHANNEL__
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        {
            editor_evt = (cui_fseditor_evt_struct *)evt;
            cui_fseditor_get_text(
                editor_evt->sender_id,
                mtv_player_p->edit_service_name,
                (S32)((MMI_MTV_NAME_STR_LENGTH + 1) <<1));
            if (mmi_mtv_player_rename_channel())
            {
                cui_fseditor_close(editor_evt->sender_id);
            }
            break;
        }
        case EVT_ID_CUI_FSEDITOR_ABORT:
        {
            editor_evt = (cui_fseditor_evt_struct *)evt;
            cui_fseditor_close(editor_evt->sender_id);
            break;
        }
	 #endif/*__DISABLE_MTV_RENAME_CHANNEL__*/
        default:
            break;


    }

    if(cui_menu_is_menu_event(evt->evt_id))
    {
 /*
 *   Editor Options related menu item handle PROC function.
 *  It should be called after App's menu PROC. It will handle editor's menu item
 *  App need to add these edit related menu item in it's menu tree (both resource or runtime create)
 *  App needn't to handle these menu item in it's PROC and only pass the evt to 
 *  wgui_inputs_options_menu_handler to let editor handle it. Editor will return MMI_RET_OK if the menu
 *  is handled.
 */
        wgui_inputs_options_menu_handler(evt, GRP_ID_MOBILE_TV_PLAYER);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_confirm_proc
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
#ifndef __DISABLE_MTV_DELETE_CHANNEL__
mmi_ret mmi_mtv_player_confirm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (evt->evt_id != EVT_ID_ALERT_QUIT)
    {
        return MMI_RET_OK;
    }

    alert = (mmi_alert_result_evt_struct *)evt;

    if ((U32)alert->user_tag == (U32)STR_ID_MOBILE_TV_PLAYER_DELETE_ASK)
    {
        if (alert->result == MMI_ALERT_CNFM_YES)
        {
            mmi_mtv_player_delete_channel();
        }
        else if (alert->result == MMI_ALERT_CNFM_NO)
        {
            mmi_frm_scrn_close_active_id();
        }
    }

    return MMI_RET_OK;
}
#endif/*__DISABLE_MTV_DELETE_CHANNEL__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_display_confirm
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
#ifndef __DISABLE_MTV_DELETE_CHANNEL__
void mmi_mtv_player_display_confirm(U16 str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    mmi_confirm_type_enum type = CNFM_TYPE_YESNO;
    WCHAR *str_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (str_id)
    {
        case STR_ID_MOBILE_TV_PLAYER_DELETE_ASK:
            type = CNFM_TYPE_YESNO;
            str_ptr = get_string(str_id);
            break;
        default:
            ASSERT(0);
            break;
    }

    mmi_confirm_property_init(&arg, type);
    arg.callback = mmi_mtv_player_confirm_proc;
    arg.user_tag = (void *)str_id;
    arg.parent_id = GRP_ID_MOBILE_TV_PLAYER;
    arg.f_auto_map_empty_softkey = MMI_FALSE;
    mmi_confirm_display(
        str_ptr,
        MMI_EVENT_QUERY,
        &arg);
}
#endif/*__DISABLE_MTV_DELETE_CHANNEL__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_reset_to_channel_list_screen
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_reset_to_channel_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Avoid reentry */
    mmi_frm_scrn_close(GRP_ID_MOBILE_TV_PLAYER, SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST);
    mmi_mtv_player_entry_channel_list_screen();

    if (mtv_player_p->cl_option_menu_gid != GRP_ID_INVALID)
    {
        cui_menu_close(mtv_player_p->cl_option_menu_gid);
        mtv_player_p->cl_option_menu_gid = GRP_ID_INVALID;
    }
    mmi_frm_scrn_multiple_close(
        GRP_ID_MOBILE_TV_PLAYER,
        SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST,
        0,
        0,
        SCR_ID_MOBILE_TV_PLAYER_APP_BASE,
        0);

}



/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_dummy
 * DESCRIPTION
 *  dummy function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_dummy(void)
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
 *  mmi_mtv_player_register_key_hdlr
 * DESCRIPTION
 *  register key event hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_register_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 left_arrow,right_arrow,up_arrow, down_arrow, key_type;
    MMI_BOOL key_0 = KAL_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if !defined(__MMI_MTV_LANDSCAPE_SUPPORT__)
#ifdef   __MMI_ATV_OSD_SUPPORT__
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
#endif
        #if (defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__))
        left_arrow = KEY_LEFT_ARROW;
        right_arrow = KEY_RIGHT_ARROW;
        up_arrow = KEY_UP_ARROW;
        down_arrow = KEY_DOWN_ARROW;
        #else
        left_arrow = KEY_UP_ARROW;
        right_arrow = KEY_DOWN_ARROW;
        up_arrow = KEY_RIGHT_ARROW;
        down_arrow = KEY_LEFT_ARROW;
        #endif
#ifdef   __MMI_ATV_OSD_SUPPORT__
    }
    else
#endif
    {
        left_arrow = KEY_LEFT_ARROW;
        right_arrow = KEY_RIGHT_ARROW;
        up_arrow = KEY_UP_ARROW;
        down_arrow = KEY_DOWN_ARROW;
    }
#endif

    mmi_mtv_player_config_functions_by_state();

#if defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_MTV_FTE2_LAYOUT__)
    /* keep all key handler as mmi_mtv_player_hide_fte_vol_icon */
    if (mtv_player_p->active_osd_cntx_p->vol_bg.status == MTV_PLAYER_ICON_STATUS_ENABLE)
    {
        return;
    }
#endif

    ClearInputEventHandler(MMI_DEVICE_KEY);
    /* Reset key handler first */
#ifdef   __MMI_ATV_OSD_SUPPORT__
    mmi_mtv_player_reset_key_handler(mmi_mtv_player_fade_in);
#endif

 #if  !defined (__DISABLE_MTV_SETTINGS__) || !defined (__ATV_NO_PHONE_STORAGE__) ||(defined(__MMI_MTV_A2DP_SUPPORT__) && !defined(__MMI_A2DP_HIDE_BT_SETTINGS__))
    if (g_mtv_player_osd_cntx.lsk.status == MTV_PLAYER_ICON_STATUS_ENABLE)
    {
        SetKeyHandler(mmi_mtv_player_lsk_icon_press, KEY_LSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_mtv_player_lsk_icon_release, KEY_LSK, KEY_EVENT_UP);
    }
 #endif/*settings & storage & bluetooth all turn off*/

    SetKeyHandler(mmi_mtv_player_rsk_icon_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_rsk_icon_release, KEY_RSK, KEY_EVENT_UP);

    SetKeyHandler(mmi_mtv_player_vol_inc_icon_press, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_vol_inc_icon_release, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(mmi_mtv_player_vol_dec_icon_press, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_vol_dec_icon_release, KEY_VOL_DOWN, KEY_EVENT_UP);

#if defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__)

#if defined(__MMI_ATV_OSD_SUPPORT__)
#if !defined(__MMI_MTV_LANDSCAPE_SUPPORT__)
    /* fullscreen */
    if (g_mtv_player_osd_cntx.fullscreen.status == MTV_PLAYER_ICON_STATUS_ENABLE ||
        g_mtv_player_osd_cntx.fullscreen.status == MTV_PLAYER_ICON_STATUS_CLICKED)
    {
        /* 2nd condition: If user long presses fullscreen icon, then time-shift is enabled. */
        SetKeyHandler(mmi_mtv_player_fullscreen_icon_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_mtv_player_dummy, KEY_UP_ARROW, KEY_EVENT_LONG_PRESS);
        SetKeyHandler(mmi_mtv_player_dummy, KEY_UP_ARROW, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_mtv_player_fullscreen_icon_release, KEY_UP_ARROW, KEY_EVENT_UP);
    }
#else
    /* fullscreen */
    if (g_mtv_player_osd_cntx.fullscreen.status == MTV_PLAYER_ICON_STATUS_ENABLE ||
        g_mtv_player_osd_cntx.fullscreen.status == MTV_PLAYER_ICON_STATUS_CLICKED)
    {
        /* 2nd condition: If user long presses fullscreen icon, then time-shift is enabled. */
        SetKeyHandler(mmi_mtv_player_fullscreen_icon_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_mtv_player_dummy, KEY_DOWN_ARROW, KEY_EVENT_LONG_PRESS);
        SetKeyHandler(mmi_mtv_player_dummy, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_mtv_player_fullscreen_icon_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
    }
#endif

#endif /* defined(__MMI_ATV_OSD_SUPPORT__)  */

    SetKeyHandler(mmi_mtv_player_vol_dec_icon_press, KEY_STAR, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_dummy, KEY_STAR, KEY_EVENT_LONG_PRESS);
    SetKeyHandler(mmi_mtv_player_dummy, KEY_STAR, KEY_EVENT_REPEAT);
    SetKeyHandler(mmi_mtv_player_vol_dec_icon_release, KEY_STAR, KEY_EVENT_UP);
    SetKeyHandler(mmi_mtv_player_vol_inc_icon_press, KEY_POUND, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_dummy, KEY_POUND, KEY_EVENT_LONG_PRESS);
    SetKeyHandler(mmi_mtv_player_dummy, KEY_POUND, KEY_EVENT_REPEAT);
    SetKeyHandler(mmi_mtv_player_vol_inc_icon_release, KEY_POUND, KEY_EVENT_UP);

#if defined(__MMI_MTV_RECORD_SUPPORT__) || defined(__MMI_MTV_SNAPSHOT_SUPPORT__)
#if !defined (__ATV_NO_PHONE_STORAGE__) && !defined (__ATV_NO_SNAPSHOT__)
    if (mtv_player_p->storage_status == MTV_PLAYER_STORAGE_OK)  
    	{
#endif
#if !defined(__MMI_MTV_LANDSCAPE_SUPPORT__)
    /* record */
  #if !defined (__ATV_NO_SNAPSHOT__) || defined(__MMI_MTV_RECORD_SUPPORT__)
    if (g_mtv_player_osd_cntx.record.status == MTV_PLAYER_ICON_STATUS_ENABLE)
    {
        SetKeyHandler(mmi_mtv_player_record_icon_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_mtv_player_dummy, KEY_DOWN_ARROW, KEY_EVENT_LONG_PRESS);
        SetKeyHandler(mmi_mtv_player_dummy, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_mtv_player_record_icon_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
    }
  #endif/*__ATV_NO_SNAPSHOT__  && __MMI_MTV_RECORD_SUPPORT__*/
#else /* !defined(__MMI_MTV_LANDSCAPE_SUPPORT__) */
    /* record */
   #if !defined (__ATV_NO_SNAPSHOT__) || defined(__MMI_MTV_RECORD_SUPPORT__)
    if (g_mtv_player_osd_cntx.record.status == MTV_PLAYER_ICON_STATUS_ENABLE)
    {
	    SetKeyHandler(mmi_mtv_player_record_icon_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
	    SetKeyHandler(mmi_mtv_player_dummy, KEY_UP_ARROW, KEY_EVENT_LONG_PRESS);
	    SetKeyHandler(mmi_mtv_player_dummy, KEY_UP_ARROW, KEY_EVENT_REPEAT);
	    SetKeyHandler(mmi_mtv_player_record_icon_release, KEY_UP_ARROW, KEY_EVENT_UP);
    }
   #endif/*__ATV_NO_SNAPSHOT__  && __MMI_MTV_RECORD_SUPPORT__*/
#endif /* !defined(__MMI_MTV_LANDSCAPE_SUPPORT__) */
#if !defined (__ATV_NO_PHONE_STORAGE__) && !defined (__ATV_NO_SNAPSHOT__)
    	}
#endif
#endif /* defined(__MMI_MTV_RECORD_SUPPORT__) || defined(__MMI_MTV_SNAPSHOT_SUPPORT__) */

    #if defined(__MMI_MTV_RECORD_SUPPORT__) || defined(__MMI_MTV_SNAPSHOT_SUPPORT__)
    /* record */
  #if !defined (__ATV_NO_SNAPSHOT__) || defined(__MMI_MTV_RECORD_SUPPORT__)
    if (g_mtv_player_osd_cntx.record.status == MTV_PLAYER_ICON_STATUS_ENABLE)
    {
        SetKeyHandler(mmi_mtv_player_record_icon_press, KEY_CAMERA, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_mtv_player_dummy, KEY_CAMERA, KEY_EVENT_LONG_PRESS);
        SetKeyHandler(mmi_mtv_player_dummy, KEY_CAMERA, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_mtv_player_record_icon_release, KEY_CAMERA, KEY_EVENT_UP);
    }
  #endif/*__ATV_NO_SNAPSHOT__  && __MMI_MTV_RECORD_SUPPORT__*/
#endif /* defined(__MMI_MTV_RECORD_SUPPORT__) || defined(__MMI_MTV_SNAPSHOT_SUPPORT__) */
#else

#if defined(__MMI_ATV_OSD_SUPPORT__)
    /* fullscreen */
    if (g_mtv_player_osd_cntx.fullscreen.status == MTV_PLAYER_ICON_STATUS_ENABLE ||
        g_mtv_player_osd_cntx.fullscreen.status == MTV_PLAYER_ICON_STATUS_CLICKED)
    {
        /* 2nd condition: If user long presses fullscreen icon, then time-shift is enabled. */
        SetKeyHandler(mmi_mtv_player_fullscreen_icon_press, KEY_STAR, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_mtv_player_dummy, KEY_STAR, KEY_EVENT_LONG_PRESS);
        SetKeyHandler(mmi_mtv_player_dummy, KEY_STAR, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_mtv_player_fullscreen_icon_release, KEY_STAR, KEY_EVENT_UP);
    }

#endif /* defined(__MMI_ATV_OSD_SUPPORT__)  */

    SetKeyHandler(mmi_mtv_player_vol_dec_icon_press, left_arrow, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_vol_dec_icon_release, left_arrow, KEY_EVENT_UP);
    SetKeyHandler(mmi_mtv_player_vol_inc_icon_press, right_arrow, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_vol_inc_icon_release, right_arrow, KEY_EVENT_UP);

#if !defined(__MMI_FTE_SUPPORT__)
    SetKeyHandler(mmi_mtv_player_vol_status_icon_press, KEY_POUND, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_dummy, KEY_POUND, KEY_EVENT_LONG_PRESS);
    SetKeyHandler(mmi_mtv_player_dummy, KEY_POUND, KEY_EVENT_REPEAT);
    SetKeyHandler(mmi_mtv_player_dummy, KEY_POUND, KEY_EVENT_UP);
#endif /* !defined(__MMI_FTE_SUPPORT__) */

#ifndef __ATV_NO_SNAPSHOT__

#if defined(__MMI_MTV_RECORD_SUPPORT__) || defined(__MMI_MTV_SNAPSHOT_SUPPORT__)
    /* record */
    if (g_mtv_player_osd_cntx.record.status == MTV_PLAYER_ICON_STATUS_ENABLE)
    {
        SetKeyHandler(mmi_mtv_player_record_icon_press, KEY_CAMERA, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_mtv_player_dummy, KEY_CAMERA, KEY_EVENT_LONG_PRESS);
        SetKeyHandler(mmi_mtv_player_dummy, KEY_CAMERA, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_mtv_player_record_icon_release, KEY_CAMERA, KEY_EVENT_UP);

        if (!mmi_frm_kbd_is_key_supported(KEY_CAMERA))
        {
            SetKeyHandler(mmi_mtv_player_record_icon_press, KEY_0, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_mtv_player_dummy, KEY_0, KEY_EVENT_LONG_PRESS);
            SetKeyHandler(mmi_mtv_player_dummy, KEY_0, KEY_EVENT_REPEAT);
            SetKeyHandler(mmi_mtv_player_record_icon_release, KEY_0, KEY_EVENT_UP);
        }
    }
#endif /* defined(__MMI_MTV_RECORD_SUPPORT__) || defined(__MMI_MTV_SNAPSHOT_SUPPORT__) */
#endif
#endif

    if (mtv_player_p->num_services > 0)
    {
        #if defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__)
        if (mtv_player_p->active_osd_cntx_p->channel_next.status == MTV_PLAYER_ICON_STATUS_ENABLE)
        {
            SetKeyHandler(mmi_mtv_player_channel_next_icon_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_mtv_player_dummy, KEY_RIGHT_ARROW, KEY_EVENT_LONG_PRESS);
            SetKeyHandler(mmi_mtv_player_dummy, KEY_RIGHT_ARROW, KEY_EVENT_REPEAT);
            SetKeyHandler(mmi_mtv_player_channel_next_icon_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        }
        else
        {
            gui_cancel_timer(mmi_mtv_player_channel_next_icon_press);
        }

        if (mtv_player_p->active_osd_cntx_p->channel_prev.status == MTV_PLAYER_ICON_STATUS_ENABLE)
        {
            SetKeyHandler(mmi_mtv_player_channel_prev_icon_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_mtv_player_dummy, KEY_LEFT_ARROW, KEY_EVENT_LONG_PRESS);
            SetKeyHandler(mmi_mtv_player_dummy, KEY_LEFT_ARROW, KEY_EVENT_REPEAT);
            SetKeyHandler(mmi_mtv_player_channel_prev_icon_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
        }
        else
        {
            gui_cancel_timer(mmi_mtv_player_channel_prev_icon_press);
        }
        #else
        if (mtv_player_p->active_osd_cntx_p->channel_next.status == MTV_PLAYER_ICON_STATUS_ENABLE)
        {
            key_type = up_arrow;
            SetKeyHandler(mmi_mtv_player_channel_next_icon_press, key_type, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_mtv_player_dummy, key_type, KEY_EVENT_LONG_PRESS);
            SetKeyHandler(mmi_mtv_player_dummy, key_type, KEY_EVENT_REPEAT);
            SetKeyHandler(mmi_mtv_player_channel_next_icon_release, key_type, KEY_EVENT_UP);
        }
        else
        {
            gui_cancel_timer(mmi_mtv_player_channel_next_icon_press);
        }

        if (mtv_player_p->active_osd_cntx_p->channel_prev.status == MTV_PLAYER_ICON_STATUS_ENABLE)
        {
            key_type = down_arrow;
            SetKeyHandler(mmi_mtv_player_channel_prev_icon_press, key_type, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_mtv_player_dummy, key_type, KEY_EVENT_LONG_PRESS);
            SetKeyHandler(mmi_mtv_player_dummy, key_type, KEY_EVENT_REPEAT);
            SetKeyHandler(mmi_mtv_player_channel_prev_icon_release, key_type, KEY_EVENT_UP);
        }
        else
        {
            gui_cancel_timer(mmi_mtv_player_channel_prev_icon_press);
        }
        #endif
	#ifndef __DISABLE_MTV_JUMP_TO_CHANNEL__
        if (mtv_player_p->active_osd_cntx_p->channel_next.status == MTV_PLAYER_ICON_STATUS_ENABLE ||
            mtv_player_p->active_osd_cntx_p->channel_prev.status == MTV_PLAYER_ICON_STATUS_ENABLE)
        {
            SetKeyHandler(mmi_mtv_player_key_1_press,KEY_1,KEY_EVENT_DOWN);
            SetKeyHandler(mmi_mtv_player_key_2_press,KEY_2,KEY_EVENT_DOWN);
            SetKeyHandler(mmi_mtv_player_key_3_press,KEY_3,KEY_EVENT_DOWN);
            SetKeyHandler(mmi_mtv_player_key_4_press,KEY_4,KEY_EVENT_DOWN);
            SetKeyHandler(mmi_mtv_player_key_5_press,KEY_5,KEY_EVENT_DOWN);
            SetKeyHandler(mmi_mtv_player_key_6_press,KEY_6,KEY_EVENT_DOWN);
            SetKeyHandler(mmi_mtv_player_key_7_press,KEY_7,KEY_EVENT_DOWN);
            SetKeyHandler(mmi_mtv_player_key_8_press,KEY_8,KEY_EVENT_DOWN);
            SetKeyHandler(mmi_mtv_player_key_9_press,KEY_9,KEY_EVENT_DOWN);
        #if defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__)
            key_0 = MMI_TRUE;
        #else        
        #if defined(__MMI_MTV_RECORD_SUPPORT__) || defined(__MMI_MTV_SNAPSHOT_SUPPORT__)
            if (!mmi_frm_kbd_is_key_supported(KEY_CAMERA))
            {
                key_0 = MMI_FALSE;
            }
        #endif
        #endif
            if (key_0)
            {
                SetKeyHandler(mmi_mtv_player_key_0_press,KEY_0,KEY_EVENT_DOWN);
            }
        }
	#endif/*__DISABLE_MTV_JUMP_TO_CHANNEL__*/
    }

#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_ATV_OSD_SUPPORT__)
    /* register pen down/up/move event */
    wgui_register_pen_down_handler(mmi_mtv_player_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_mtv_player_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_mtv_player_pen_move_hdlr);
#endif /* __MMI_TOUCH_SCREEN__  && __MMI_ATV_OSD_SUPPORT__ */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_set_band_value
 * DESCRIPTION
 *  mobile tv player set band value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_set_band_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mtv_player_p->setting.band = mtv_player_p->selected_band;
    mmi_mtv_player_store_setting();

    mmi_mtv_player_update_channel_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_highlight_band_hdlr
 * DESCRIPTION
 *  mobile tv player band setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_highlight_band_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mtv_player_p->selected_band = idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_cancel_set_band
 * DESCRIPTION
 *  mobile tv player cancel set band
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_cancel_set_band(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_scrn_is_present(
            GRP_ID_MOBILE_TV_PLAYER,
            SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST,
            MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        ret = mmi_mtv_player_kernel_enter_state(MTV_KERNEL_CLOSING);
        mtv_player_p->go_back_history = MMI_TRUE;
        ASSERT(ret==MDI_RES_MTV_SUCCEED);

        mmi_frm_scrn_close(GRP_ID_MOBILE_TV_PLAYER, SCR_ID_MOBILE_TV_PLAYER_APP_BASE);
    }

    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_entry_band_screen
 * DESCRIPTION
 *  mobile tv player band setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_entry_band_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 selected_band;
    S32 i, menu_num = 0;
    U16 title = 0;
    U8 **string_list = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_scrn_enter(
                GRP_ID_MOBILE_TV_PLAYER,
                SCR_ID_MOBILE_TV_PLAYER_BAND,
                NULL,
                mmi_mtv_player_entry_band_screen,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }
	mmi_mtv_player_check_bg_snd();

    RegisterHighlightHandler(mmi_mtv_player_highlight_band_hdlr);

    /* Initialize the string pointer */
    for (i = 0; i < MMI_ATV_COUNTRY_TOTAL_COUNT; i++)
    {
        mtv_player_setting_p->country_str[i] =
            GetString((U16) (STR_ID_ATV_COUNTRY_START + 1 + i));
    }

    title = STR_ID_MOBILE_TV_PLAYER_SELECT_LOCATION;

    menu_num = MMI_ATV_COUNTRY_TOTAL_COUNT;
    string_list = (U8 **)mtv_player_setting_p->country_str;

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    if (guiBuffer == NULL)
    {
         selected_band = mtv_player_p->setting.band;
    }
    else
    {
         selected_band = mtv_player_p->selected_band;
    }
#ifndef __MMI_WGUI_DISABLE_CSK__
    /* Call enable before showCategory, call change after showCategory */
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
    ShowCategory36Screen(
        title,
        GetRootTitleIcon(MENU_ID_MOBILE_TV_PLAYER_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        menu_num,
        string_list,
        (U16)selected_band,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_mtv_player_cancel_set_band, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mtv_player_set_band_value, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_mtv_player_set_band_value, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_config_functions_by_state
 * DESCRIPTION
 *  CONFIG functions according to states.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_config_functions_by_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 total_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_ATV_OSD_SUPPORT__)
#if defined(__MMI_MTV_RECORD_SUPPORT__) && defined(__MMI_MTV_A2DP_SUPPORT__)
    if (!RECORDER_STATE_IN(MTV_RECORDER_STOPPED) && mmi_mtv_player_is_output_to_bt())
    {
        mmi_mtv_player_disable_fullscreen_function();
    }
    else
#endif /* __MMI_MTV_RECORD_SUPPORT__ */
    {
        mmi_mtv_player_enable_fullscreen_function();
    }
#else /* __MMI_ATV_OSD_SUPPORT__ */
    mmi_mtv_player_disable_fullscreen_function();
#endif /* __MMI_ATV_OSD_SUPPORT__ */

#if defined(__MMI_ATV_OSD_SUPPORT__)
    /* LSK */
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        mmi_mtv_player_disable_lsk_function();
    }
	#ifdef   __MMI_MTV_RECORD_SUPPORT__
    else if (RECORDER_STATE_IN(MTV_RECORDER_RECORD) || RECORDER_STATE_IN(MTV_RECORDER_PAUSE))
    {
        mmi_mtv_player_disable_lsk_function();
    }
	#endif
    else
    {
        mmi_mtv_player_enable_lsk_function();
    }
#else /* __MMI_ATV_OSD_SUPPORT__ */
    mmi_mtv_player_enable_lsk_function();
#endif /* __MMI_ATV_OSD_SUPPORT__ */

#if defined(__MMI_ATV_OSD_SUPPORT__) && defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__)
    /* Vol */
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
       g_mtv_player_osd_cntx.vol_status.status = MTV_PLAYER_ICON_STATUS_DISABLE;
    }
    else
    {
        g_mtv_player_osd_cntx.vol_status.status = MTV_PLAYER_ICON_STATUS_ENABLE;
    }
#endif /* __MMI_ATV_OSD_SUPPORT__ */
    total_num = mtv_player_p->num_services;

    if (KERNEL_STATE_IN(MTV_KERNEL_READY))
    {
        if (total_num > 1 
			#ifdef   __MMI_MTV_RECORD_SUPPORT__
			&& RECORDER_STATE_IN(MTV_RECORDER_STOPPED)
			#endif
                    && mmi_mtv_player_is_in_background_call() == MMI_FALSE
            )
        {
            mmi_mtv_player_enable_switch_channel_function();
        }
        else
        {
            mmi_mtv_player_disable_switch_channel_function();
        }

    #if defined(__MMI_MTV_RECORD_SUPPORT__) || defined(__MMI_MTV_SNAPSHOT_SUPPORT__)
        /* No timeshift -> player don't have pause state. Only playing state support record, snapshot function */
        if (RECORDER_STATE_IN(MTV_RECORDER_RECORD) ||
            RECORDER_STATE_IN(MTV_RECORDER_PAUSE) ||
        #if defined(__MMI_ATV_OSD_SUPPORT__)
            mtv_player_p->storage_status == MTV_PLAYER_STORAGE_OK &&
        #endif /*__MMI_ATV_OSD_SUPPORT__ */
            mmi_mtv_player_is_in_background_call() == MMI_FALSE &&
            PLAYER_STATE_IN(MTV_PLAYER_PLAY))
        {
            mmi_mtv_player_enable_record_function();
        }
        else
        {
            mmi_mtv_player_disable_record_function();
        }
    #endif /* defined(__MMI_MTV_RECORD_SUPPORT__) || defined(__MMI_MTV_SNAPSHOT_SUPPORT__) */

    }
    else
    {
        if (total_num > 1
           && mmi_mtv_player_is_in_background_call() == MMI_FALSE
            )
        {
            mmi_mtv_player_enable_switch_channel_function();
        }
        else
        {
            mmi_mtv_player_disable_switch_channel_function();
        }
    #if defined(__MMI_MTV_RECORD_SUPPORT__) || defined(__MMI_MTV_SNAPSHOT_SUPPORT__)
        mmi_mtv_player_disable_record_function();
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_set_blt_layer
 * DESCRIPTION
 *  The function sets blt layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_set_blt_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_ATV_OSD_SUPPORT__) && !defined (GDI_2_LAYERS)
    gdi_handle layer_3;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* MUST sync with mmi_mtv_player_player_prepare_player_setting() */
#if !defined(__MMI_ATV_OSD_SUPPORT__)
    gdi_layer_set_blt_layer(
        mtv_player_p->display_layer_handle,
        NULL,
        NULL,
        NULL);
#elif defined(GDI_2_LAYERS)

    gdi_layer_set_blt_layer(
        mtv_player_p->display_layer_handle,
        mtv_player_p->osd_layer_handle,
        NULL,
        NULL);

#else /* GDI_2_LAYERS */

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
    #if defined(__MMI_FTE_SUPPORT__)
        layer_3 = mtv_player_p->vol_layer_handle;
    #else /* __MMI_FTE_SUPPORT__ */
        layer_3 = mtv_player_p->dls_layer_handle;
    #endif /* __MMI_FTE_SUPPORT__ */
        gdi_layer_set_blt_layer(
            mtv_player_p->display_layer_handle,
            mtv_player_p->osd_layer_handle,
            mtv_player_p->status_bar_layer_handle,
            layer_3);

    }
    else
    {
        gdi_layer_set_blt_layer(
            mtv_player_p->display_layer_handle,
            mtv_player_p->osd_layer_handle,
            mtv_player_p->dls_layer_handle,
            0);
    }

#endif /* GDI_2_LAYERS */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_init_service_in_app_screen
 * DESCRIPTION
 *  mobile tv player entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_mtv_player_init_service_in_app_screen(MMI_BOOL avoid_infinite_pop)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* enter initialize state */
    mtv_player_p->last_error = mmi_mtv_player_kernel_enter_state(MTV_KERNEL_INIT);
#ifdef   __MMI_ATV_OSD_SUPPORT__
    if (mtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
    {
        if (mmi_mtv_player_is_flag_set(MTV_PLAYER_UNAVAILABLE_IN_CALL))
        {
            mmi_mtv_player_set_hint(
                    (CHAR *) GetString((U16)(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL)),
					(CHAR *) NULL,
			        MMI_MOBILE_TV_PLAYER_HINT_POPUP_NO_FADE,
                    MMI_TRUE);
        }
        else
        {
            /* if no services, show hint on screen */
            mmi_mtv_player_set_hint(
                (CHAR *) GetString((U16) (STR_ID_MOBILE_TV_PLAYER_SERVICE_IS_NOT_AVAILABLE)),
				(CHAR *) NULL,
			     MMI_MOBILE_TV_PLAYER_HINT_POPUP_NO_FADE,
                 MMI_TRUE);
            mmi_mtv_player_set_flag(MTV_PLAYER_SERVICE_UNAVAILABLE);
        }
    }
#endif
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_entry_app_screen
 * DESCRIPTION
 *  mobile tv player entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_entry_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef   __MMI_ATV_OSD_SUPPORT__
    U8 *guiBuffer;
#endif
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                GRP_ID_MOBILE_TV_PLAYER,
                SCR_ID_MOBILE_TV_PLAYER_APP,
                mmi_mtv_player_exit_app_screen,
                mmi_mtv_player_entry_app_screen,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

#if defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
    gdi_bltdb_enable(GDI_BLTDB_ENABLE_ONLY_WHEN_HW_UPDATE);
#endif
    gui_screen_switch_effect_block(MMI_TRUE);
    mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGH_SCRN);

    /* set ther blt mode to make osd blt immediate */
    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
#ifdef   __MMI_ATV_OSD_SUPPORT__
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
#endif
    mmi_frm_scrn_set_leave_proc(
        GRP_ID_MOBILE_TV_PLAYER,
        SCR_ID_MOBILE_TV_PLAYER_APP,
        mmi_mtv_player_app_screen_leave_proc);

    mmi_mtv_player_unset_flag(MTV_PLAYER_UNAVAILABLE_IN_CALL);

    gdi_lcd_set_rotate_by_layer(TRUE);

    /* initialize flags */
    mtv_player_p->is_key_pressed = MMI_FALSE;
    mtv_player_p->is_changing_channel_by_key = MMI_FALSE;
    mtv_player_p->change_to_channel = 0;
    
#ifdef   __MMI_ATV_OSD_SUPPORT__
    mtv_player_p->hint_state = MTV_PLAYER_HINT_STATE_HIDE;
    mtv_player_p->fullscr_osd_opacity = MMI_MOBILE_TV_PLAYER_OSD_FADEOUT_FACTOR;
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;
    /* Reset ui rotate */
    if (guiBuffer == NULL)
    {
        mtv_player_p->ui_rotate = MMI_FRM_SCREEN_ROTATE_0;
    }
#endif

    /* Always display full screen */
#if !defined(__MMI_ATV_OSD_SUPPORT__)
    mtv_player_p->ui_rotate = MMI_FRM_SCREEN_ROTATE_270;
#endif


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    /* entry full screen app */
    entry_full_screen();

    /* force all playing keypad tone off */
    srv_profiles_stop_tone(SRV_PROF_TONE_KEYPAD);

    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

    /* disalbe align timer  */
    UI_disable_alignment_timers();

    /* enable multi-layer */
    gdi_layer_multi_layer_enable();

    mmi_mtv_player_check_bg_snd();

    /* Register bt callback */
#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_register_volume_sync_callback(
        APP_MOBILE_TV_PLAYER,
        MDI_AUD_VOL_LEVEL_EXTEND_MUTE,
        mmi_mtv_player_bt_volume_sync_hdlr);
#endif

    /* init adm related resource */
    mmi_mtv_player_alloc_adm_layer();
    /* init adm related resource */
    mmi_mtv_player_alloc_base_layer();

    /* init screen-based related resource */
    mmi_mtv_player_alloc_resource();

    /* clear drawing layer */
    mmi_mtv_player_clear_preview_layer();


    mmi_mtv_player_config_functions_by_state();

    /* Config blt layer */
    mmi_mtv_player_set_blt_layer();
#ifndef __ATV_NO_SNAPSHOT__
#if  defined (__ATV_NO_PHONE_STORAGE__)  
		/*	no phone storage in MT6260, so we just check t flash*/
		mmi_mtv_player_check_storage(); //TODO	use api to find tf name

#else
    /* check storage to handle the case that card plug in/out pop up on other screen */
    mmi_mtv_player_check_storage(MMI_FALSE, mtv_player_p->setting.storage);
#ifdef   __MMI_MTV_RECORD_SUPPORT__
    if (mtv_player_p->prev_storage_status != mtv_player_p->storage_status)
    {
        if (mtv_player_p->storage_status == MTV_PLAYER_STORAGE_OK)
        {
        #if defined(__MMI_MTV_RECORD_SUPPORT__)
            mdi_mtv_set_storage(mtv_player_p->mtv_handle, (PU8)mtv_player_p->storage_filepath);
        #endif
        }
    }
#endif		
#endif
#endif

    /* Delay blt signal icon, cmmb logo, dynamic layer */
    gdi_layer_lock_frame_buffer();

#ifdef   __MMI_ATV_OSD_SUPPORT__
    mmi_mtv_player_draw_osd();
#endif

    /* Draw status icon */
    mmi_mtv_player_draw_signal_icon();

    gdi_layer_unlock_frame_buffer();

    /* just for back from other screen and save */
	if (KERNEL_STATE_IN(MTV_KERNEL_READY))
    {
#ifdef   __MMI_MTV_RECORD_SUPPORT__
        if (RECORDER_STATE_IN(MTV_RECORDER_SAVE_CONFIRM))
        {
            mmi_mtv_player_enter_save_confirm();
            return;
        }
#endif
	}

    gdi_layer_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    /* Following: Check different state */
    if (KERNEL_STATE_IN(MTV_KERNEL_READY))
    {
        mmi_mtv_player_register_key_hdlr();
#ifdef   __MMI_ATV_OSD_SUPPORT__
        /* To make TV syncs with LCD, draw hint before play.  */
        mmi_mtv_player_draw_osd();
        mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif
#ifdef   __MMI_MTV_RECORD_SUPPORT__
        if (RECORDER_STATE_IN(MTV_RECORDER_SAVE_CONFIRM))
        {
            mmi_mtv_player_enter_save_confirm();
            return;
        }
        else
#endif
	if (PLAYER_STATE_IN(MTV_PLAYER_STOPPED))
        {
        #if defined(__MMI_MTV_A2DP_SUPPORT__)
            if (mmi_mtv_player_is_output_to_bt() && !mmi_mtv_player_is_in_background_call())
            {
                mmi_mtv_player_player_enter_state(MTV_PLAYER_BT_CONNECT);
            }
            else
            {
                mmi_mtv_player_player_enter_state(MTV_PLAYER_PLAY);
            }
        #else
            mmi_mtv_player_player_enter_state(MTV_PLAYER_PLAY);
        #endif
        }
#ifdef   __MMI_ATV_OSD_SUPPORT__

        if (mmi_mtv_player_is_flag_set(MTV_PLAYER_UNAVAILABLE_IN_CALL))
        {
            mmi_mtv_player_set_hint(
                    (CHAR *) GetString((U16)(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL)),
					(CHAR *) NULL,
			        MMI_MOBILE_TV_PLAYER_HINT_POPUP_NO_FADE,
                    MMI_TRUE);
        }
	mmi_mtv_player_reset_osd_by_rotate();

        mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif
    }
    else if (KERNEL_STATE_IN(MTV_KERNEL_OPENED))
    {
#ifdef   __MMI_ATV_OSD_SUPPORT__
        if (mtv_player_p->num_services == 0)
        {
            /* if no services, show hint on screen */
            mmi_mtv_player_set_hint(
                (CHAR *) GetString((U16) (STR_ID_MOBILE_TV_PLAYER_NO_SERVICE_AVAILABLE)),
				(CHAR *) NULL,
			    MMI_MOBILE_TV_PLAYER_HINT_POPUP_NO_FADE,
                MMI_TRUE);
        }
        else
#endif
        {
            ret = mmi_mtv_player_init_service_in_app_screen(MMI_TRUE);
            if (ret == MMI_FALSE)
            {
                return;
            }
        }
        mmi_mtv_player_register_key_hdlr();
#ifdef   __MMI_ATV_OSD_SUPPORT__
	mmi_mtv_player_reset_osd_by_rotate();
        mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif	
    }
    else if (KERNEL_STATE_IN(MTV_KERNEL_INIT))
    {
        mmi_mtv_player_register_key_hdlr();
#ifdef   __MMI_ATV_OSD_SUPPORT__
        mmi_mtv_player_draw_osd();
        mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif
    }
    else
    {
        /* kernel is in wrong state when entering mtv player */
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_exit_app_screen
 * DESCRIPTION
 *  mobile tv player exit screen handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_exit_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Avoid auto play */
    if (KERNEL_STATE_IN(MTV_KERNEL_INIT))
    {
        /* Restore previous selected service */
        ret = mmi_mtv_player_kernel_enter_state(MTV_KERNEL_OPENED);
        ASSERT(ret == MDI_RES_MTV_SUCCEED);
    }
#ifdef   __MMI_MTV_RECORD_SUPPORT__
    if (RECORDER_STATE_IN(MTV_RECORDER_RECORD) || RECORDER_STATE_IN(MTV_RECORDER_PAUSE))
    {
        /* Only stop recorder. Enter save_confirm screen when entry again */
        mmi_mtv_player_recorder_enter_state(MTV_RECORDER_SAVE_CONFIRM);
    }
#endif

    if (PLAYER_STATE_IN(MTV_PLAYER_PLAY) || PLAYER_STATE_IN(MTV_PLAYER_BT_CONNECT))
    {
        mmi_mtv_player_player_enter_state(MTV_PLAYER_STOPPED);
    }

    /* reset some icons which will not be checked when entering application screen */
    mmi_mtv_player_reset_all_icon();

    gdi_lcd_set_rotate_by_layer(FALSE);

#ifdef   __MMI_ATV_OSD_SUPPORT__
    gui_cancel_timer(mmi_mtv_player_fullscr_osd_fade_cyclic);
    gui_cancel_timer(mmi_mtv_player_hide_hint);
#endif
#ifndef __DISABLE_MTV_JUMP_TO_CHANNEL__
    gui_cancel_timer(mmi_mtv_player_jump_to_channel);
#endif/*__DISABLE_MTV_JUMP_TO_CHANNEL__*/
     gui_cancel_timer(mmi_mtv_player_record_start_record);
    gui_cancel_timer(mmi_mtv_player_channel_prev_icon_press);
    gui_cancel_timer(mmi_mtv_player_channel_next_icon_press);
    gui_cancel_timer(mmi_mtv_player_vol_inc_icon_press);
    gui_cancel_timer(mmi_mtv_player_vol_dec_icon_press);
    StopTimer(MTV_PLAYER_UPDATE_PLAYER_STATUS);
    StopTimer(MTV_PLAYER_VOLUME_ICON_TIMER);

    /* Reset base layer here */
    mmi_mtv_player_free_base_layer();

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
       /* clear base as black for TV out */
       gdi_layer_clear(GDI_COLOR_BLACK);
    }
    else
    {
        gdi_layer_flatten_previous_to_base();
    }

    /* De-register bt callback when midlet is terminated */
#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_clear_volume_sync_callback(APP_MOBILE_TV_PLAYER);
#endif

    /* resume alignment timer */
    UI_enable_alignment_timers();

    /* enable multi-layer */
    gdi_layer_multi_layer_disable();

    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    leave_full_screen();

#if 0
/* under construction !*/
/* under construction !*/
#endif
    /* Free layer and release memory */
    mmi_mtv_player_free_resource();

    mmi_mtv_player_free_adm_layer();

    /* save setting */
    mmi_mtv_player_store_setting();

    mmi_frm_end_scenario(MMI_SCENARIO_ID_HIGH_SCRN);
#if defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
    gdi_bltdb_disable();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_display_success_popup
 * DESCRIPTION
 *
 * PARAMETERS
 *  S16     IN      stringid
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_display_popup(U16 string_id, mmi_event_notify_enum event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_MTV_LANDSCAPE_SUPPORT__)
    mmi_popup_property_struct arg;
    mmi_frm_screen_rotate_enum rotate = MMI_FRM_SCREEN_ROTATE_0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_MTV_LANDSCAPE_SUPPORT__)
    if(mmi_frm_scrn_is_present(
        GRP_ID_MOBILE_TV_PLAYER,
        SCR_ID_MOBILE_TV_PLAYER_APP,
        MMI_FRM_NODE_ALL_FLAG))
    {
        rotate = mtv_player_p->ui_rotate;
    }
    mmi_popup_property_init(&arg);
    arg.rotation = rotate;
    arg.parent_id = GRP_ID_MOBILE_TV_PLAYER;
    mmi_popup_display(
        (WCHAR*)get_string(string_id),
        event_id,
        &arg);
#else /* defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_MTV_LANDSCAPE_SUPPORT__) */
    mmi_popup_display_simple(
        (WCHAR*)get_string(string_id),
        event_id,
        GRP_ID_MOBILE_TV_PLAYER,
        NULL);
#endif /* defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_MTV_LANDSCAPE_SUPPORT__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_display_failure_popup
 * DESCRIPTION
 *
 * PARAMETERS
 *  S16     IN      stringid
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_display_failure_popup(MDI_RESULT ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_notify_enum popup_type;
    MMI_ID_TYPE string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    string_id = mdi_util_get_mdi_error_info(ret, &popup_type);
    mmi_mtv_player_display_popup((U16)string_id, popup_type);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_get_storage_file_path
 * DESCRIPTION
 *  get current active storage file path.
 * PARAMETERS
 *  filepath        [OUT]       File path
 * RETURNS
 * BOOL
 *****************************************************************************/
 MMI_BOOL mmi_mtv_player_get_storage_file_path(U16 storage, CHAR *filepath, mtv_player_storage_path_enum path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_wsprintf((WCHAR *) filepath, "%c:\\", (U8)storage);

#ifdef   __MMI_MTV_RECORD_SUPPORT__
    if (path == MTV_PLAYER_STORAGE_PATH_VIDEO)
    {
        mmi_ucs2cat((CHAR *) filepath, (CHAR *) MMI_MTV_PLAYER_STORAGE_FILEPATH);
    }
    else 
#endif
    if (path == MTV_PLAYER_STORAGE_PATH_PHOTO)
    {
        mmi_ucs2cat((CHAR *) filepath, (CHAR *) MMI_MTV_PLAYER_STORAGE_FILEPATH_PHOTOS);
    }
    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_create_file_dir
 * DESCRIPTION
 *  create directly from a file path (resursivly)
 * PARAMETERS
 *  filepath        [IN]        File path to create
 * RETURNS
 *  S32
 *****************************************************************************/
 S32 mmi_mtv_player_create_file_dir(CHAR *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret, len;
    FS_HANDLE file_handle;
    CHAR *loc;
    CHAR folder_path[200];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_ret = 0;

    file_handle = FS_Open((kal_uint16*) filepath, FS_OPEN_DIR | FS_READ_ONLY);

    /* path already exist */
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
        return 0;   /* already exist , 0 measn success in FS */
    }

    /* For OP1 C:\Images\Photos\ */
    mmi_ucs2cpy(folder_path, filepath);
    loc = mmi_ucs2rchr(folder_path, L'\\');
    len = loc - folder_path;
    folder_path[len] = folder_path[len + 1] = 0;

    loc = mmi_ucs2rchr(folder_path, L'\\');
    len = loc - folder_path;
    if (len != 4)
    {
        folder_path[len] = 0;
        folder_path[len + 1] = 0;
        fs_ret = FS_CreateDir((PU16) folder_path);
    }

    /* create directory if it is not there */
    fs_ret = FS_CreateDir((PU16) filepath);

    return fs_ret;
}

#ifndef __ATV_NO_PHONE_STORAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_set_storage
 * DESCRIPTION
 *  set storage callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_set_storage(WCHAR drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    mmi_event_notify_enum event_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /***************************************************
     * for new storage error handling machenism
     ***************************************************/
    if (drv_letter == mtv_player_p->setting.storage)
    {
       mmi_frm_scrn_close_active_id();
    }
    else
    {
        event_type = mmi_mtv_player_check_storage(MMI_FALSE, drv_letter);

        if (mtv_player_p->storage_status == MTV_PLAYER_STORAGE_OK)
        {
        #if defined(__MMI_MTV_RECORD_SUPPORT__)
            mdi_mtv_set_storage(mtv_player_p->mtv_handle, (PU8)mtv_player_p->storage_filepath);
        #endif

            mtv_player_p->setting.storage = (U16) drv_letter;
            /* storge setting to NVRAM */
            WriteRecord(
                NVRAM_EF_MOBILE_TV_PLAYER_SETTING_LID,
                1,
                (void*)&mtv_player_p->setting,
                NVRAM_EF_MOBILE_TV_PLAYER_SETTING_SIZE, &error);
            mmi_frm_scrn_close_active_id();
        }
        else
        {
            mmi_mtv_player_display_popup(mtv_player_p->err_str_id, event_type);

        }
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_rsk_icon_press
 * DESCRIPTION
 *  mobile tv player rsk press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_rsk_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_RSK;
    mtv_player_p->active_osd_cntx_p->rsk.status = MTV_PLAYER_ICON_STATUS_CLICKED;
#ifdef   __MMI_ATV_OSD_SUPPORT__
    mmi_mtv_player_fullscr_reset_osd_fade(MMI_FALSE);
    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_rsk_icon_release
 * DESCRIPTION
 *  mobile tv player rsk release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_rsk_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mtv_player_p->touch_object != MTV_PLAYER_TOUCH_RSK)
    {
        return;
    }

    mtv_player_p->active_osd_cntx_p->rsk.status = MTV_PLAYER_ICON_STATUS_ENABLE;
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;
#ifdef   __MMI_ATV_OSD_SUPPORT__
    mmi_mtv_player_fullscr_reset_osd_fade(MMI_FALSE);
    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif
#ifdef   __MMI_MTV_RECORD_SUPPORT__
    if (RECORDER_STATE_IN(MTV_RECORDER_RECORD) || RECORDER_STATE_IN(MTV_RECORDER_PAUSE))
    {
        mmi_mtv_player_recorder_enter_state(MTV_RECORDER_SAVE_CONFIRM);
        mmi_mtv_player_enter_save_confirm();
    }
    else
#endif
    {
        mmi_frm_scrn_close_active_id();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_fade_in
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_fade_in(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef   __MMI_ATV_OSD_SUPPORT__
    /* If normal screen, it's dummy function */
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        mmi_mtv_player_fullscr_reset_osd_fade(MMI_TRUE);
        mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_lsk_icon_press
 * DESCRIPTION
 *  mobile tv player lsk press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if  !defined (__DISABLE_MTV_SETTINGS__) || !defined (__ATV_NO_PHONE_STORAGE__) ||(defined(__MMI_MTV_A2DP_SUPPORT__) && !defined(__MMI_A2DP_HIDE_BT_SETTINGS__))
 void mmi_mtv_player_lsk_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_LSK;
    mtv_player_p->active_osd_cntx_p->lsk.status = MTV_PLAYER_ICON_STATUS_CLICKED;
#ifdef   __MMI_ATV_OSD_SUPPORT__
    mmi_mtv_player_fullscr_reset_osd_fade(MMI_FALSE);
    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_lsk_icon_release
 * DESCRIPTION
 *  mobile tv player lsk release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_lsk_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mtv_player_p->touch_object != MTV_PLAYER_TOUCH_LSK)
    {
        return;
    }
    mtv_player_p->active_osd_cntx_p->lsk.status = MTV_PLAYER_ICON_STATUS_ENABLE;
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;
#ifdef   __MMI_ATV_OSD_SUPPORT__
    mmi_mtv_player_fullscr_reset_osd_fade(MMI_FALSE);
    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif
    mmi_mtv_player_entry_option_menu_screen();
}
#endif/*settings & storage & bluetooth all turn off*/


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_record_icon_press
 * DESCRIPTION
 *  mobile tv player record icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if !defined (__ATV_NO_SNAPSHOT__) || defined(__MMI_MTV_RECORD_SUPPORT__)
 void mmi_mtv_player_record_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __ATV_NO_PHONE_STORAGE__
    /*for we dont have phone storage, check t-flash firstly*/
	if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM))
	{
	    //  may need a new string res here
        mmi_mtv_player_display_popup(STR_GLOBAL_FAILED_TO_SAVE, MMI_EVENT_FAILURE); 
	}
#endif
	
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_RECORD;

    if (mtv_player_p->active_osd_cntx_p->record.status == MTV_PLAYER_ICON_STATUS_CLICKED)
    {
        return;
    }
#ifdef   __MMI_MTV_RECORD_SUPPORT__
    if (RECORDER_STATE_IN(MTV_RECORDER_STOPPED) ||
        RECORDER_STATE_IN(MTV_RECORDER_RECORD) ||
        RECORDER_STATE_IN(MTV_RECORDER_PAUSE))
    {
        mtv_player_p->touch_object = MTV_PLAYER_TOUCH_RECORD;
#endif
        mtv_player_p->active_osd_cntx_p->record.status = MTV_PLAYER_ICON_STATUS_CLICKED;
#ifdef   __MMI_ATV_OSD_SUPPORT__
        mmi_mtv_player_fullscr_reset_osd_fade(MMI_FALSE);
        mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif
#ifdef   __MMI_MTV_RECORD_SUPPORT__

        if (RECORDER_STATE_IN(MTV_RECORDER_STOPPED))
        {
#endif
            mtv_player_p->is_capture = MMI_TRUE;
            /* Always snapshot even if long press */
        #if defined(__MMI_MTV_RECORD_SUPPORT__)
            gui_start_timer(2000, mmi_mtv_player_record_start_record);
        #endif /*defined(__MMI_MTV_RECORD_SUPPORT__) */

#ifdef   __MMI_MTV_RECORD_SUPPORT__

        }
#endif
#ifdef   __MMI_MTV_RECORD_SUPPORT__

    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_record_icon_release
 * DESCRIPTION
 *  mobile tv player record icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_record_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mtv_player_service_info_struct *info_ptr;
#ifdef __MMI_ATV_OSD_SUPPORT__
    MMI_BOOL ret = MMI_TRUE; /* Must initialize as true */
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mtv_player_p->touch_object != MTV_PLAYER_TOUCH_RECORD)
    {
        return;
    }

    mtv_player_p->active_osd_cntx_p->record.status  = MTV_PLAYER_ICON_STATUS_ENABLE;
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;

#ifdef __MMI_MTV_RECORD_SUPPORT__
    if (RECORDER_STATE_IN(MTV_RECORDER_RECORD))
    {
        MDI_RESULT result = MDI_RES_MTV_SUCCEED;
        result = mmi_mtv_player_recorder_enter_state(MTV_RECORDER_PAUSE);

        if(result != MDI_RES_MTV_SUCCEED)
        {
            mmi_mtv_player_draw_osd();
            mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

            mmi_mtv_player_display_failure_popup(result);
            mmi_mtv_player_recorder_enter_state(MTV_RECORDER_SAVE_CONFIRM);
            mmi_mtv_player_enter_save_confirm();
        }
        else
        {
	    mmi_mtv_player_reset_osd_by_rotate();

            mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
        }
    }
    else if (RECORDER_STATE_IN(MTV_RECORDER_PAUSE))
    {
        mtv_player_p->last_error =
            mmi_mtv_player_recorder_enter_state(MTV_RECORDER_RECORD);
        if (mtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
        {
            mmi_mtv_player_draw_osd();
            mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

            mmi_mtv_player_display_failure_popup(mtv_player_p->last_error);
            mmi_mtv_player_recorder_enter_state(MTV_RECORDER_SAVE_CONFIRM);
            mmi_mtv_player_enter_save_confirm();
        }
        else
        {
	    mmi_mtv_player_reset_osd_by_rotate();

            mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
        }
    }
    else
#endif /* __MMI_MTV_RECORD_SUPPORT__ */
    {
        if( mtv_player_p->is_capture == TRUE)
        {
#ifdef   __MMI_MTV_RECORD_SUPPORT__
            gui_cancel_timer(mmi_mtv_player_record_start_record);
#endif
            /* DAB do not support Snapshot. */
            info_ptr = mmi_mtv_player_get_active_channel_ptr();

            if (info_ptr->service_type == MDI_MTV_SERVICE_TYPE_ANALOG_TV)
            {
#if !defined (__ATV_NO_SNAPSHOT__) 
#if defined (__MMI_ATV_OSD_SUPPORT__)
                ret = mmi_mtv_player_snapshot();
#else
                mmi_mtv_player_snapshot();
#endif
#endif
            }

#if  defined( __MMI_ATV_OSD_SUPPORT__) 
            /* DAB or Snapshot success. If Snapshot fail, a pop up screen will display.
               layer will be freed. Don't draw OSD */
            if (ret == MMI_TRUE)
            {
		        mmi_mtv_player_reset_osd_by_rotate();
                mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
            }
#endif

            ClearKeyEvents();
        }
    }

}
#endif/*__ATV_NO_SNAPSHOT__  && __MMI_MTV_RECORD_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_fullscreen_icon_press
 * DESCRIPTION
 *  mobile tv player fullscreen icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_fullscreen_icon_press(void)
{
#if defined(__MMI_ATV_OSD_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_FULLSCREEN;
    mtv_player_p->active_osd_cntx_p->fullscreen.status = MTV_PLAYER_ICON_STATUS_CLICKED;
    mmi_mtv_player_fullscr_reset_osd_fade(MMI_FALSE);
    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif /* defined(__MMI_ATV_OSD_SUPPORT__)  */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_fullscreen_icon_release
 * DESCRIPTION
 *  mobile tv player fullscreen icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_fullscreen_icon_release(void)
{
#if defined(__MMI_ATV_OSD_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    MMI_BOOL need_init = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    mtv_player_p->active_osd_cntx_p->fullscreen.status  = MTV_PLAYER_ICON_STATUS_ENABLE;
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;

    /* Draw fullscreen icon at ENABLE state */
    mmi_mtv_player_draw_osd();
    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

    /* Avoid auto play */
    if (KERNEL_STATE_IN(MTV_KERNEL_INIT))
    {
        /* Restore previous selected service */
        ret = mmi_mtv_player_kernel_enter_state(MTV_KERNEL_OPENED);
        ASSERT(ret == MDI_RES_MTV_SUCCEED);
        need_init = MMI_TRUE;
    }


    if (PLAYER_STATE_IN(MTV_PLAYER_PLAY))
    {
    #if defined(__MMI_MTV_A2DP_SUPPORT__)
        if (mmi_mtv_player_is_output_to_bt() && !mmi_mtv_player_is_in_background_call())
        {
            mmi_mtv_player_player_enter_state(MTV_PLAYER_STOPPED);
        }
        else
    #endif
        {
             mmi_mtv_player_player_enter_state(MTV_PLAYER_STOPPED);
        }
    }
    else if (PLAYER_STATE_IN(MTV_PLAYER_BT_CONNECT))
    {
        mmi_mtv_player_player_enter_state(MTV_PLAYER_STOPPED);
    }

    /* change Rotate */
    mtv_player_p->ui_rotate =(mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)?MMI_FRM_SCREEN_ROTATE_270:MMI_FRM_SCREEN_ROTATE_0;

    /* config osd and dls layer size according to display mode */
    /* The function configures status icon and must put after screen_rotate() */
    mmi_mtv_player_config_layers();

    /* Re-config blt layer */
    mmi_mtv_player_set_blt_layer();

    /* Delay blt signal icon, cmmb logo, dynamic layer */
    gdi_layer_lock_frame_buffer();

    mmi_mtv_player_register_key_hdlr();

    mmi_mtv_player_reset_osd_by_rotate();

    /* Draw signal icon */
    mmi_mtv_player_draw_signal_icon();

    gdi_layer_unlock_frame_buffer();

    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

    if (need_init && KERNEL_STATE_IN(MTV_KERNEL_OPENED))
    {
        ret = mmi_mtv_player_init_service_in_app_screen(MMI_FALSE);
        if (ret == MMI_FALSE)
        {
            return;
        }
    }
    else if (KERNEL_STATE_IN(MTV_KERNEL_READY))
    {
        if (PLAYER_STATE_IN(MTV_PLAYER_STOPPED))
        {
        #if defined(__MMI_MTV_A2DP_SUPPORT__)
            if (mmi_mtv_player_is_output_to_bt() && !mmi_mtv_player_is_in_background_call())
            {
                mmi_mtv_player_player_enter_state(MTV_PLAYER_BT_CONNECT);
            }
            else
            {
                mmi_mtv_player_player_enter_state(MTV_PLAYER_PLAY);
            }
        #else
            mmi_mtv_player_player_enter_state(MTV_PLAYER_PLAY);
        #endif

        }

        if (mmi_mtv_player_is_flag_set(MTV_PLAYER_UNAVAILABLE_IN_CALL))
        {
            mmi_mtv_player_set_hint(
                    (CHAR *) GetString((U16)(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL)),
					(CHAR *) NULL,
			        MMI_MOBILE_TV_PLAYER_HINT_POPUP_NO_FADE,
                    MMI_TRUE);
        }
    }

    mmi_mtv_player_reset_osd_by_rotate();

    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif /* defined(__MMI_ATV_OSD_SUPPORT__)  */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_vol_inc_icon_press
 * DESCRIPTION
 *  mobile tv player vol_inc icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_vol_inc_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_ATV_OSD_SUPPORT__) && (!defined(__MMI_FTE_SUPPORT__) ||(defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MTV_FTE2_LAYOUT__)))
    MMI_BOOL draw_osd;
    MMI_BOOL level_update = KAL_FALSE;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mtv_player_p->setting.vol_level < MTV_PLAYER_VOL_16)
    {
        mtv_player_p->setting.vol_level ++;
        mtv_player_p->setting.is_mute = KAL_FALSE;//!!mtv_player_p->setting.vol_level;
    #if defined(__MMI_ATV_OSD_SUPPORT__) && (!defined(__MMI_FTE_SUPPORT__)||(defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MTV_FTE2_LAYOUT__)))
        level_update = KAL_TRUE;
    #endif
        mdi_audio_set_volume(MTV_VOLUME_TYPE, (U8) MDI_AUD_VOL_EX_MUTE(mtv_player_p->setting.vol_level));
    }

#if defined(__MMI_ATV_OSD_SUPPORT__)
#if defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_MTV_FTE2_LAYOUT__)
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        mmi_mtv_player_reset_key_handler(mmi_mtv_player_hide_fte_vol_icon);
        StopTimer(MTV_PLAYER_VOLUME_ICON_TIMER);
        mtv_player_p->active_osd_cntx_p->vol_bg.status = MTV_PLAYER_ICON_STATUS_ENABLE;
        mtv_player_p->active_osd_cntx_p->vol_idx.status = MTV_PLAYER_ICON_STATUS_ENABLE;
        mmi_mtv_player_draw_fte_vol_icon();
    }
#else /* defined(__MMI_FTE_SUPPORT__) */
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_VOL_INC;
    mtv_player_p->active_osd_cntx_p->vol_inc.status = MTV_PLAYER_ICON_STATUS_CLICKED;

    if (level_update && mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        mmi_mtv_player_fullscr_reset_osd_fade(MMI_FALSE);
        mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }
#endif /* defined(__MMI_FTE_SUPPORT__) */
#endif /* defined(__MMI_ATV_OSD_SUPPORT__) */

    if (mtv_player_p->setting.vol_level < MTV_PLAYER_VOL_16)
    {
        mmi_mtv_player_start_timer(100, 200, mmi_mtv_player_vol_inc_icon_press);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_vol_inc_icon_release
 * DESCRIPTION
 *  mobile tv player vol_inc icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_vol_inc_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_mtv_player_vol_inc_icon_press);
    mtv_player_p->is_key_pressed = MMI_FALSE;

#if defined(__MMI_ATV_OSD_SUPPORT__)

#if defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_MTV_FTE2_LAYOUT__)
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        StartTimer(
            MTV_PLAYER_VOLUME_ICON_TIMER,
            MMI_MOBILE_TV_PLAYER_VOL_ICON_DURATION,
            mmi_mtv_player_hide_fte_vol_icon);
    }
#else /* defined(__MMI_FTE_SUPPORT__) */
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;
    mtv_player_p->active_osd_cntx_p->vol_inc.status  = MTV_PLAYER_ICON_STATUS_ENABLE;


    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        mmi_mtv_player_fullscr_reset_osd_fade(MMI_FALSE);
        mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }
#endif /* defined(__MMI_FTE_SUPPORT__)  */
#endif /* #if defined(__MMI_ATV_OSD_SUPPORT__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_vol_dec_icon_press
 * DESCRIPTION
 *  mobile tv player vol_dec icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_vol_dec_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_ATV_OSD_SUPPORT__) && (!defined(__MMI_FTE_SUPPORT__) ||(defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MTV_FTE2_LAYOUT__)))
    MMI_BOOL draw_osd;
    MMI_BOOL level_update = KAL_FALSE;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mtv_player_p->setting.vol_level > MTV_PLAYER_VOL_MUTE)
    {
        mtv_player_p->setting.vol_level--;

        if(!mtv_player_p->setting.vol_level)
        {
            mtv_player_p->setting.is_mute = KAL_TRUE;
        }
        else
        {
            mtv_player_p->setting.is_mute = KAL_FALSE;
        }
        
    #if defined(__MMI_ATV_OSD_SUPPORT__) && (!defined(__MMI_FTE_SUPPORT__) ||(defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MTV_FTE2_LAYOUT__)))
        level_update = KAL_TRUE;
    #endif
        mdi_audio_set_volume(MTV_VOLUME_TYPE, (U8) MDI_AUD_VOL_EX_MUTE(mtv_player_p->setting.vol_level));
    }

#if defined(__MMI_ATV_OSD_SUPPORT__)

#if defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_MTV_FTE2_LAYOUT__)
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        mmi_mtv_player_reset_key_handler(mmi_mtv_player_hide_fte_vol_icon);
        StopTimer(MTV_PLAYER_VOLUME_ICON_TIMER);
        mtv_player_p->active_osd_cntx_p->vol_bg.status = MTV_PLAYER_ICON_STATUS_ENABLE;
        mtv_player_p->active_osd_cntx_p->vol_idx.status = MTV_PLAYER_ICON_STATUS_ENABLE;

        mmi_mtv_player_draw_fte_vol_icon();
    }
#else /* defined(__MMI_FTE_SUPPORT__ */
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_VOL_DEC;
    mtv_player_p->active_osd_cntx_p->vol_dec.status = MTV_PLAYER_ICON_STATUS_CLICKED;

    if (level_update && mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        draw_osd = MMI_TRUE;
    }
    else
    {
        draw_osd = MMI_FALSE;
    }

    if (draw_osd)
    {
        mmi_mtv_player_fullscr_reset_osd_fade(MMI_FALSE);
        mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }

#endif /* defined(__MMI_FTE_SUPPORT__) */
#endif /* defined(__MMI_ATV_OSD_SUPPORT__) */
    if (mtv_player_p->setting.vol_level > MTV_PLAYER_VOL_MUTE)
    {
        mmi_mtv_player_start_timer(100, 200, mmi_mtv_player_vol_dec_icon_press);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_vol_dec_icon_release
 * DESCRIPTION
 *  mobile tv player vol_dec icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_vol_dec_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_mtv_player_vol_dec_icon_press);
    mtv_player_p->is_key_pressed = MMI_FALSE;

#if defined(__MMI_ATV_OSD_SUPPORT__)
#if defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_MTV_FTE2_LAYOUT__)
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        StartTimer(
            MTV_PLAYER_VOLUME_ICON_TIMER,
            MMI_MOBILE_TV_PLAYER_VOL_ICON_DURATION,
            mmi_mtv_player_hide_fte_vol_icon);
    }
#else /* defined(__MMI_FTE_SUPPORT__) */
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;

    mtv_player_p->active_osd_cntx_p->vol_dec.status = MTV_PLAYER_ICON_STATUS_ENABLE;

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        mmi_mtv_player_fullscr_reset_osd_fade(MMI_FALSE);
        mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }

#endif /* defined(__MMI_FTE_SUPPORT__) */
#endif /* defined(__MMI_ATV_OSD_SUPPORT__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_unmute
 * DESCRIPTION
 *  mobile tv player vol_dec icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_unmute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Mobile TV is not opened */
    if (KERNEL_STATE_IN(MTV_KERNEL_CLOSED) || KERNEL_STATE_IN(MTV_KERNEL_CLOSING))
    {
        return;
    }
    mtv_player_p->setting.is_mute = MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_vol_status_icon_release
 * DESCRIPTION
 *  mobile tv player vol_dec icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_vol_status_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_FTE_SUPPORT__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MTV_FTE2_LAYOUT__))
    U16 active_screen;
#ifdef   __MMI_ATV_OSD_SUPPORT__
    MMI_BOOL draw_osd = MMI_TRUE;
#endif
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_FTE_SUPPORT__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MTV_FTE2_LAYOUT__))
    /* Toggle between mute and unmute */
    mtv_player_p->setting.is_mute = 1 - mtv_player_p->setting.is_mute;

    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_VOL_STATUS;
    mtv_player_p->active_osd_cntx_p->vol_status.status = MTV_PLAYER_ICON_STATUS_CLICKED;
	
    mmi_mtv_player_set_volume();

    active_screen = mmi_frm_scrn_get_active_id();
    if (active_screen != SCR_ID_MOBILE_TV_PLAYER_APP)
    {
        return;
    }

#ifdef   __MMI_ATV_OSD_SUPPORT__
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        draw_osd = MMI_FALSE;
    }

    /* Draw OSD */
    if (draw_osd)
    {
        mmi_mtv_player_fullscr_reset_osd_fade(MMI_FALSE);
        mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }
#endif
#endif /* !defined(__MMI_FTE_SUPPORT__) */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_vol_status_icon_press
 * DESCRIPTION
 *  mobile tv player vol_dec icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_vol_status_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;
    mtv_player_p->active_osd_cntx_p->vol_status.status = MTV_PLAYER_ICON_STATUS_ENABLE;
#ifdef   __MMI_ATV_OSD_SUPPORT__
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        mmi_mtv_player_fullscr_reset_osd_fade(MMI_TRUE);
    }
    
    mmi_mtv_player_draw_osd();
    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif   
#if 0
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_change_channel
 * DESCRIPTION
 *  mobile tv player channel channel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_mtv_player_change_channel(U8 target_channel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check if wwitch to differnt channel */
    if (target_channel < mtv_player_p->num_services &&
        target_channel != mtv_player_p->setting.selected_channel)
    {
        if (PLAYER_STATE_IN(MTV_PLAYER_PLAY) || PLAYER_STATE_IN(MTV_PLAYER_BT_CONNECT))
        {
            mmi_mtv_player_player_enter_state(MTV_PLAYER_STOPPED);
        }

        if (KERNEL_STATE_IN(MTV_KERNEL_READY) || KERNEL_STATE_IN(MTV_KERNEL_INIT))
        {
            mmi_mtv_player_kernel_enter_state(MTV_KERNEL_OPENED);
        }

        /* Switch */
        mmi_mtv_player_set_selected_service(target_channel);

        mmi_mtv_player_clear_preview_layer();

        /* Update icon state for refresh TV */
        mmi_mtv_player_config_functions_by_state();
#ifdef   __MMI_ATV_OSD_SUPPORT__
        /* Blt out before entering init state: for refresh TV */
        mmi_mtv_player_fullscr_reset_osd_fade(MMI_FALSE);
        mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif
        ret = mmi_mtv_player_init_service_in_app_screen(MMI_FALSE);
        if (ret == MMI_FALSE)
        {
            return ret;
        }

        mmi_mtv_player_register_key_hdlr();
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_channel_prev_icon_press
 * DESCRIPTION
 *  mobile tv player channel prev icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_channel_prev_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 total_num;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 #ifndef __DISABLE_MTV_JUMP_TO_CHANNEL__
    mmi_mtv_player_reset_jump_to_channel();
 #endif/*__DISABLE_MTV_JUMP_TO_CHANNEL__*/

    if (mtv_player_p->touch_object != MTV_PLAYER_TOUCH_CHANNEL_PREV)
    {
        mtv_player_p->temporal_channel = mtv_player_p->setting.selected_channel;
    }

    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_CHANNEL_PREV;

    total_num = mtv_player_p->num_services;

    if(mtv_player_p->temporal_channel == 0)
    {
        /* For wrap around to the last channel */
        mtv_player_p->temporal_channel = total_num - 1;
    }
    else
    {
        mtv_player_p->temporal_channel --;
    }

    mmi_mtv_player_start_timer(700, 300, mmi_mtv_player_channel_prev_icon_press);

    mtv_player_p->active_osd_cntx_p->channel_prev.status = MTV_PLAYER_ICON_STATUS_CLICKED;
#ifdef   __MMI_ATV_OSD_SUPPORT__
    mmi_mtv_player_fullscr_reset_osd_fade(MMI_FALSE);
    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_channel_prev_icon_release
 * DESCRIPTION
 *  mobile tv player prev icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_channel_prev_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mtv_player_p->touch_object != MTV_PLAYER_TOUCH_CHANNEL_PREV)
    {
        return;
    }

    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;

    mtv_player_p->is_key_pressed = MMI_FALSE;
    gui_cancel_timer(mmi_mtv_player_channel_prev_icon_press);
    mtv_player_p->active_osd_cntx_p->channel_prev.status  = MTV_PLAYER_ICON_STATUS_ENABLE;

    ret = mmi_mtv_player_change_channel(mtv_player_p->temporal_channel);
    if (ret == MMI_FALSE)
    {
        return;
    }
#ifdef   __MMI_ATV_OSD_SUPPORT__
    mmi_mtv_player_reset_osd_by_rotate();

    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif
    ClearKeyEvents();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_channel_next_icon_press
 * DESCRIPTION
 *  mobile tv player channel next icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_channel_next_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U16 total_num;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  #ifndef __DISABLE_MTV_JUMP_TO_CHANNEL__
    mmi_mtv_player_reset_jump_to_channel();
  #endif/*__DISABLE_MTV_JUMP_TO_CHANNEL__*/

    if (mtv_player_p->touch_object != MTV_PLAYER_TOUCH_CHANNEL_NEXT)
    {
        mtv_player_p->temporal_channel = mtv_player_p->setting.selected_channel;
    }

    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_CHANNEL_NEXT;
    mtv_player_p->temporal_channel = (mtv_player_p->temporal_channel + 1) % mtv_player_p->num_services;
    mmi_mtv_player_start_timer(700, 300, mmi_mtv_player_channel_next_icon_press);
    mtv_player_p->active_osd_cntx_p->channel_next.status = MTV_PLAYER_ICON_STATUS_CLICKED;
#ifdef   __MMI_ATV_OSD_SUPPORT__
    mmi_mtv_player_fullscr_reset_osd_fade(MMI_FALSE);
    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_channel_next_icon_release
 * DESCRIPTION
 *  mobile tv player channel icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_channel_next_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mtv_player_p->touch_object != MTV_PLAYER_TOUCH_CHANNEL_NEXT)
    {
        return;
    }

    mtv_player_p->is_key_pressed = MMI_FALSE;
    gui_cancel_timer(mmi_mtv_player_channel_next_icon_press);
    mtv_player_p->active_osd_cntx_p->channel_next.status  = MTV_PLAYER_ICON_STATUS_ENABLE;

    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;

    ret = mmi_mtv_player_change_channel(mtv_player_p->temporal_channel);
    if (ret == MMI_FALSE)
    {
        return;
    }
#ifdef   __MMI_ATV_OSD_SUPPORT__
    mmi_mtv_player_reset_osd_by_rotate();

    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif
    ClearKeyEvents();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_key_num_press
 * DESCRIPTION
 *  mobile tv player key num pressed handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 #ifndef __DISABLE_MTV_JUMP_TO_CHANNEL__
void mmi_mtv_player_key_num_press(S32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->is_changing_channel_by_key = MMI_TRUE;

    mtv_player_p->change_to_channel = (mtv_player_p->change_to_channel*10 + num) % 100;
    mmi_mtv_player_check_and_jump_to_channel();
}

void mmi_mtv_player_key_1_press(void)
{
    mmi_mtv_player_key_num_press(1);
}
void mmi_mtv_player_key_2_press(void)
{
    mmi_mtv_player_key_num_press(2);
}
void mmi_mtv_player_key_3_press(void)
{
    mmi_mtv_player_key_num_press(3);
}
void mmi_mtv_player_key_4_press(void)
{
    mmi_mtv_player_key_num_press(4);
}
void mmi_mtv_player_key_5_press(void)
{
    mmi_mtv_player_key_num_press(5);
}
void mmi_mtv_player_key_6_press(void)
{
    mmi_mtv_player_key_num_press(6);
}
void mmi_mtv_player_key_7_press(void)
{
    mmi_mtv_player_key_num_press(7);
}
void mmi_mtv_player_key_8_press(void)
{
    mmi_mtv_player_key_num_press(8);
}
void mmi_mtv_player_key_9_press(void)
{
    mmi_mtv_player_key_num_press(9);
}
void mmi_mtv_player_key_0_press(void)
{
    mmi_mtv_player_key_num_press(0);
}
#endif/*__DISABLE_MTV_JUMP_TO_CHANNEL__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_check_and_jump_to_channel
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __DISABLE_MTV_JUMP_TO_CHANNEL__
 void mmi_mtv_player_check_and_jump_to_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mtv_player_p->change_to_channel < 10)
    {
        gui_cancel_timer(mmi_mtv_player_jump_to_channel);
        gui_start_timer(MMI_MTV_JUMP_TO_CHANNEL_DELAY, mmi_mtv_player_jump_to_channel);
#ifdef   __MMI_ATV_OSD_SUPPORT__
	mmi_mtv_player_reset_osd_by_rotate();

        mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif
    }
    else
    {
#ifdef   __MMI_ATV_OSD_SUPPORT__
        mmi_mtv_player_draw_osd();
        mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif
        mmi_mtv_player_jump_to_channel();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_reset_jump_to_channel
 * DESCRIPTION
 *  mobile tv player reset jump to channel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_reset_jump_to_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Reset jump to channel */
    mtv_player_p->is_changing_channel_by_key = MMI_FALSE;
    mtv_player_p->change_to_channel = 0;
    gui_cancel_timer(mmi_mtv_player_jump_to_channel);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_jump_to_channel
 * DESCRIPTION
 *  mobile tv player : jump to channel input by keypad.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_jump_to_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 service_index;
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->is_changing_channel_by_key = MMI_FALSE;

    for (service_index = 0; service_index < mtv_player_p->num_services; service_index ++)
    {
        if (mtv_player_p->services[service_index].service_number == mtv_player_p->change_to_channel)
        {
            break;
        }
    }

    ret = mmi_mtv_player_change_channel(service_index);
    if (ret == MMI_FALSE)
    {
        return;
    }
#ifdef   __MMI_ATV_OSD_SUPPORT__
    mmi_mtv_player_reset_osd_by_rotate();

    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif
    /* reset "change_to_channel" variable */
    mtv_player_p->change_to_channel = 0;
}
#endif/*__DISABLE_MTV_JUMP_TO_CHANNEL__*/



#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_ATV_OSD_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_touch_scr_hit_test
 * DESCRIPTION
 *  mobile tv player check if icon is pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 MMI_BOOL mmi_mtv_player_touch_scr_hit_test(S32 pos_x, S32 pos_y, mtv_player_osd_icon_struct *touch_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pos_x >= touch_obj->offset_x) &&
        (pos_x < touch_obj->offset_x + touch_obj->width) &&
        (pos_y >= touch_obj->offset_y) && (pos_y < touch_obj->offset_y + touch_obj->height))
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
 *  mmi_mtv_player_pen_down_hdlr_fullscreen
 * DESCRIPTION
 *  mobile tv player pen down event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_pen_down_hdlr_fullscreen(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mtv_player_fullscr_osd_show_up();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_touch_feeback_down
 * DESCRIPTION
 *  mobile tv player pen down down
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_touch_feeback_down(void)
{
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
/* under construction !*/
#endif /* __MMI_TOUCH_FEEDBACK_SUPPORT__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_pen_down_hdlr
 * DESCRIPTION
 *  mobile tv player pen down event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL ret;
	S32 icon_id;
	wgui_status_icon_bar_pen_enum event_type;

#define ICON_TOUCH_TEST(a,A)\
    do {\
        if(mtv_player_p->active_osd_cntx_p->##a##.status==MTV_PLAYER_ICON_STATUS_ENABLE)\
        {\
            if(mmi_mtv_player_touch_scr_hit_test(pos.x, pos.y, &(mtv_player_p->active_osd_cntx_p->##a##)) == MMI_TRUE)\
            {\
                mmi_mtv_player_##a##_icon_press();\
                mtv_player_p->touch_object = MTV_PLAYER_TOUCH_##A;\
                mmi_mtv_player_touch_feeback_down();\
                return;\
            }\
        }\
    } while(0)
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if !defined(__MMI_MTV_LANDSCAPE_SUPPORT__)
    /* idp rotate */
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        S32 tmp;

        tmp = pos.x;
        pos.x = pos.y;
        pos.y = (LCD_WIDTH - 1) - tmp;
    }
#endif /* !__MMI_MTV_LANDSCAPE_SUPPORT__ */


    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;

	ret = wgui_status_icon_bar_translate_pen_event(MMI_PEN_EVENT_DOWN,
	                                               pos.x,
												   pos.y,
												   &icon_id,
												   &event_type
                                                   );

	if (MMI_TRUE == ret)
	{
		return;
	}

#if defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_MTV_FTE2_LAYOUT__)
    ICON_TOUCH_TEST(vol_idx,VOL_IDX);
    ICON_TOUCH_TEST(vol_bg,VOL_BG);
    if (mtv_player_p->active_osd_cntx_p->vol_bg.status == MTV_PLAYER_ICON_STATUS_ENABLE)
    {
        mmi_mtv_player_hide_fte_vol_icon();
        return;
    }
#else /* defined(__MMI_FTE_SUPPORT__) */
    ICON_TOUCH_TEST(vol_status, VOL_STATUS);
#endif /* defined(__MMI_FTE_SUPPORT__) */

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        ICON_TOUCH_TEST(lsk,LSK);
    }

    #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_MTV_RECORD_SUPPORT__)
    if(RECORDER_STATE_IN(MTV_RECORDER_PAUSE) ||
        RECORDER_STATE_IN(MTV_RECORDER_RECORD))
    {
        if(mtv_player_p->active_osd_cntx_p->rsk.status==MTV_PLAYER_ICON_STATUS_ENABLE)
        {
            mtv_player_osd_icon_struct touch_obj;
            S32 str_w, str_h, str_x1, str_y1, dim_x1, dim_y1;
            S32 width, height, trunc_w;
            MMI_BOOL is_trunc;
            gui_measure_string((UI_string_type) GetString(STR_GLOBAL_STOP), &str_w, &str_h);
            wgui_softkey_get_dimension(MMI_RIGHT_SOFTKEY, &dim_x1, &dim_y1);
            is_trunc = wgui_softkey_get_offset(
                        (UI_string_type) GetString(STR_GLOBAL_STOP), 
                        &str_x1, 
                        &str_y1, 
                        &trunc_w, 
                        MMI_RIGHT_SOFTKEY,
                        mmi_frm_get_screen_rotate());
            gdi_image_get_dimension_id(IMG_ID_MTV_PLAYER_STOP_BUTTON_BG_DOWN, &width, &height);
            if(mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
            {
                #if !defined(__MMI_MTV_LANDSCAPE_SUPPORT__)
                str_x1 = LCD_HEIGHT - (LCD_WIDTH-str_x1);
                #endif
                str_y1 = dim_y1 - (LCD_HEIGHT-str_y1);
            }
            if(mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
            {
                touch_obj.offset_x = str_x1 - 6;
                touch_obj.offset_y = str_y1 - ((height - str_h)/2);
                touch_obj.width = str_w + 12;
                touch_obj.height = height;
            }
            else
            {
                touch_obj.offset_x = str_x1;
                //touch_obj.offset_y = str_y1;
                touch_obj.offset_y = mtv_player_p->active_osd_cntx_p->rsk.offset_y;
                touch_obj.width = str_w;
                touch_obj.height = mtv_player_p->active_osd_cntx_p->rsk.height;
            }

            if(mmi_mtv_player_touch_scr_hit_test(pos.x, pos.y, &touch_obj) == MMI_TRUE)
            {
                mmi_mtv_player_rsk_icon_press();
                mtv_player_p->touch_object = MTV_PLAYER_TOUCH_RSK;
                mmi_mtv_player_touch_feeback_down();
            }
        }
    }
    else
    {
    ICON_TOUCH_TEST(rsk,RSK);
    }
    #else    
    ICON_TOUCH_TEST(rsk,RSK);
    #endif

    ICON_TOUCH_TEST(fullscreen,FULLSCREEN);
    ICON_TOUCH_TEST(vol_inc,VOL_INC);
    ICON_TOUCH_TEST(vol_dec,VOL_DEC);

    ICON_TOUCH_TEST(channel_next,CHANNEL_NEXT);
    ICON_TOUCH_TEST(channel_prev,CHANNEL_PREV);


#if defined(__MMI_MTV_SNAPSHOT_SUPPORT__) || defined(__MMI_MTV_RECORD_SUPPORT__)
    ICON_TOUCH_TEST(record,RECORD);
#endif
#ifdef   __MMI_ATV_OSD_SUPPORT__
    /* Invalid region: make the play panel appear */
    mmi_mtv_player_fullscr_reset_osd_fade(MMI_FALSE);
    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_pen_up_hdlr
 * DESCRIPTION
 *  mobile tv player pen up event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL ret;
	S32 icon_id;
	wgui_status_icon_bar_pen_enum event_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if !defined(__MMI_MTV_LANDSCAPE_SUPPORT__)
    /* idp rotate */
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        S32 tmp;

        tmp = pos.x;
        pos.x = pos.y;
        pos.y = (LCD_WIDTH - 1) - tmp;
    }
#endif /*!defined(__MMI_MTV_LANDSCAPE_SUPPORT__) */


    switch(mtv_player_p->touch_object)
    {
        case MTV_PLAYER_TOUCH_RSK:
            mmi_mtv_player_rsk_icon_release();
            break;
        case MTV_PLAYER_TOUCH_LSK:
            mmi_mtv_player_lsk_icon_release();
            break;
        case MTV_PLAYER_TOUCH_FULLSCREEN:
            mmi_mtv_player_fullscreen_icon_release();
            break;
        case MTV_PLAYER_TOUCH_VOL_INC:
            mmi_mtv_player_vol_inc_icon_release();
            break;
        case MTV_PLAYER_TOUCH_VOL_DEC:
            mmi_mtv_player_vol_dec_icon_release();
            break;
        case MTV_PLAYER_TOUCH_CHANNEL_NEXT:
            mmi_mtv_player_channel_next_icon_release();
            break;
        case MTV_PLAYER_TOUCH_CHANNEL_PREV:
            mmi_mtv_player_channel_prev_icon_release();
            break;
    #if defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_MTV_FTE2_LAYOUT__)

        case MTV_PLAYER_TOUCH_VOL_BG:
            mmi_mtv_player_vol_bg_icon_release();
            break;
        case MTV_PLAYER_TOUCH_VOL_IDX:
            mmi_mtv_player_vol_idx_icon_release();
            break;
    #else
        case MTV_PLAYER_TOUCH_VOL_STATUS:
            mmi_mtv_player_vol_status_icon_release();
            break;
    #endif /* defined(__MMI_FTE_SUPPORT__) */

    #if defined(__MMI_MTV_SNAPSHOT_SUPPORT__) || defined(__MMI_MTV_RECORD_SUPPORT__)
        case MTV_PLAYER_TOUCH_RECORD:
            mmi_mtv_player_record_icon_release();
            break;
    #endif /* defined(__MMI_MTV_SNAPSHOT_SUPPORT__) || defined(__MMI_MTV_RECORD_SUPPORT__) */
        default:
        {
        	ret = wgui_status_icon_bar_translate_pen_event(MMI_PEN_EVENT_UP,
                                               pos.x,
											   pos.y,
											   &icon_id,
											   &event_type
                                               );
            if (MMI_TRUE == ret)
            {
            	break;
            }

            /* If not yet fade out, make it fade out.
               When moving to invalid region, play panel has faded out. */
            if (mtv_player_p->fullscr_osd_opacity == MMI_MOBILE_TV_PLAYER_OSD_FADEOUT_FACTOR)
            {
		mmi_mtv_player_reset_osd_by_rotate();

                mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
            }

            break;
        }

    }

    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_pen_move_hdlr
 * DESCRIPTION
 *  mobile tv player pen move event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mtv_player_osd_icon_struct *osd_icon_ptr = NULL;
    S32 tmp;
	MMI_BOOL ret;
	S32 icon_id;
	wgui_status_icon_bar_pen_enum event_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if !defined(__MMI_MTV_LANDSCAPE_SUPPORT__)
    /* idp rotate */
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        tmp = pos.x;
        pos.x = pos.y;
        pos.y = (LCD_WIDTH - 1) - tmp;
    }
#endif /* !defined(__MMI_MTV_LANDSCAPE_SUPPORT__) */

    /* Assign osd icon pointer */
    switch(mtv_player_p->touch_object)
    {
        case MTV_PLAYER_TOUCH_RSK:
            osd_icon_ptr = &(mtv_player_p->active_osd_cntx_p->rsk);
            break;
        case MTV_PLAYER_TOUCH_LSK:
            osd_icon_ptr = &(mtv_player_p->active_osd_cntx_p->lsk);
            break;
        case MTV_PLAYER_TOUCH_FULLSCREEN:
            osd_icon_ptr = &(mtv_player_p->active_osd_cntx_p->fullscreen);
            break;
        case MTV_PLAYER_TOUCH_VOL_INC:
            osd_icon_ptr = &(mtv_player_p->active_osd_cntx_p->vol_inc);
            break;
        case MTV_PLAYER_TOUCH_VOL_DEC:
            osd_icon_ptr = &(mtv_player_p->active_osd_cntx_p->vol_dec);
            break;
        case MTV_PLAYER_TOUCH_VOL_STATUS:
            osd_icon_ptr = &(mtv_player_p->active_osd_cntx_p->vol_status);
            break;
        case MTV_PLAYER_TOUCH_CHANNEL_NEXT:
            osd_icon_ptr = &(mtv_player_p->active_osd_cntx_p->channel_next);
            break;
        case MTV_PLAYER_TOUCH_CHANNEL_PREV:
            osd_icon_ptr = &(mtv_player_p->active_osd_cntx_p->channel_prev);
            break;
    #if defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_MTV_FTE2_LAYOUT__)

        case MTV_PLAYER_TOUCH_VOL_BG:
            osd_icon_ptr = &(mtv_player_p->active_osd_cntx_p->vol_bg);
            break;
        case MTV_PLAYER_TOUCH_VOL_IDX:
            osd_icon_ptr = &(mtv_player_p->active_osd_cntx_p->vol_idx);
            break;
    #endif /* defined(__MMI_FTE_SUPPORT__) */

    #if defined(__MMI_MTV_SNAPSHOT_SUPPORT__) || defined(__MMI_MTV_RECORD_SUPPORT__)
        case MTV_PLAYER_TOUCH_RECORD:
            osd_icon_ptr = &(mtv_player_p->active_osd_cntx_p->record);
            break;
    #endif /* defined(__MMI_MTV_SNAPSHOT_SUPPORT__) || defined(__MMI_MTV_RECORD_SUPPORT__) */


        default:
        	ret = wgui_status_icon_bar_translate_pen_event(MMI_PEN_EVENT_MOVE,
	                                               pos.x,
												   pos.y,
												   &icon_id,
												   &event_type
                                                   );
             break;
    }

    /* Handle the case when move out of the icon */
    switch(mtv_player_p->touch_object)
    {
    case MTV_PLAYER_TOUCH_VOL_INC:
    {
        if(mmi_mtv_player_touch_scr_hit_test(pos.x, pos.y, osd_icon_ptr) != MMI_TRUE)
        {
            mmi_mtv_player_vol_inc_icon_release();
        }
        break;
    }
    case MTV_PLAYER_TOUCH_VOL_DEC:
    {
        if(mmi_mtv_player_touch_scr_hit_test(pos.x, pos.y, osd_icon_ptr) != MMI_TRUE)
        {
            mmi_mtv_player_vol_dec_icon_release();
        }
        break;
    }
    case MTV_PLAYER_TOUCH_VOL_STATUS:
    {
        if(mmi_mtv_player_touch_scr_hit_test(pos.x, pos.y, osd_icon_ptr) != MMI_TRUE)
        {          
            mmi_mtv_player_vol_status_icon_release();
        }
        break;
    }
    case MTV_PLAYER_TOUCH_CHANNEL_NEXT:
    {
        if(mmi_mtv_player_touch_scr_hit_test(pos.x, pos.y, osd_icon_ptr) != MMI_TRUE)
        {
            mmi_mtv_player_channel_next_icon_release();
        }
        break;
    }
    case MTV_PLAYER_TOUCH_CHANNEL_PREV:
    {
        if(mmi_mtv_player_touch_scr_hit_test(pos.x, pos.y, osd_icon_ptr) != MMI_TRUE)
        {
            mmi_mtv_player_channel_prev_icon_release();
        }
        break;
    }
#if defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_MTV_FTE2_LAYOUT__)

    case MTV_PLAYER_TOUCH_VOL_BG:
    {
        if(mmi_mtv_player_touch_scr_hit_test(pos.x, pos.y, osd_icon_ptr) != MMI_TRUE)
        {
            mmi_mtv_player_vol_bg_icon_release();
        }
        break;
    }
    case MTV_PLAYER_TOUCH_VOL_IDX:
    {
        /* Update volume level */
        mmi_mtv_player_update_vol_level(pos.x);
        break;
    }
#endif /* defined(__MMI_FTE_SUPPORT__) */

#if defined(__MMI_MTV_SNAPSHOT_SUPPORT__) || defined(__MMI_MTV_RECORD_SUPPORT__)
    case MTV_PLAYER_TOUCH_RECORD:
        mmi_mtv_player_record_icon_release();
        break;
#endif
    /* Only need to change icon status as enable */
    case MTV_PLAYER_TOUCH_RSK:
        #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_MTV_RECORD_SUPPORT__)
        if(RECORDER_STATE_IN(MTV_RECORDER_PAUSE) ||
            RECORDER_STATE_IN(MTV_RECORDER_RECORD))
        {
            if(mtv_player_p->active_osd_cntx_p->rsk.status == MTV_PLAYER_ICON_STATUS_ENABLE)
            {
                mtv_player_osd_icon_struct touch_obj;
                S32 str_w, str_h, str_x1, str_y1, dim_x1,dim_y1;
                S32 width, height, trunc_w;
                MMI_BOOL is_trunc;
                gui_measure_string((UI_string_type) GetString(STR_GLOBAL_STOP), &str_w, &str_h);
                wgui_softkey_get_dimension(MMI_RIGHT_SOFTKEY, &dim_x1, &dim_y1);
                is_trunc = wgui_softkey_get_offset(
                            (UI_string_type) GetString(STR_GLOBAL_STOP), 
                            &str_x1, 
                            &str_y1, 
                            &trunc_w, 
                            MMI_RIGHT_SOFTKEY,
                            mmi_frm_get_screen_rotate());
                if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
                {
                    #if !defined(__MMI_MTV_LANDSCAPE_SUPPORT__)
                    str_x1 = LCD_HEIGHT - (LCD_WIDTH-str_x1);
                    #endif
                    str_y1 = dim_y1 - (LCD_HEIGHT-str_y1);
                }

                gdi_image_get_dimension_id(IMG_ID_MTV_PLAYER_STOP_BUTTON_BG_DOWN, &width, &height);
                if(mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
                {
                    touch_obj.offset_x = str_x1 - 6;
                    touch_obj.offset_y = str_y1 - ((height - str_h)/2);
                    touch_obj.width = str_w + 12;
                    touch_obj.height = height;
                }
                else
                {
                    touch_obj.offset_x = str_x1;
                    touch_obj.offset_y = mtv_player_p->active_osd_cntx_p->rsk.offset_y;
                    touch_obj.width = str_w;
                    touch_obj.height = mtv_player_p->active_osd_cntx_p->rsk.height;
                }

                if(mmi_mtv_player_touch_scr_hit_test(pos.x, pos.y, &touch_obj) != MMI_TRUE)
                {
                    /* Change icon status as enable */
                    osd_icon_ptr->status = MTV_PLAYER_ICON_STATUS_ENABLE;
                    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;
		    mmi_mtv_player_reset_osd_by_rotate();
                    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);                    
                }
            }  
            break;
        }
        #endif
    case MTV_PLAYER_TOUCH_LSK:
    case MTV_PLAYER_TOUCH_FULLSCREEN:
    {
        if(mmi_mtv_player_touch_scr_hit_test(pos.x, pos.y, osd_icon_ptr) != MMI_TRUE)
        {
            /* Change icon status as enable */
            osd_icon_ptr->status = MTV_PLAYER_ICON_STATUS_ENABLE;
            mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;
	    mmi_mtv_player_reset_osd_by_rotate();
            mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
        }
        break;
    }
    default:
        break;
    }

}
#endif /* (__MMI_TOUCH_SCREEN__) && (__MMI_ATV_OSD_SUPPORT__) */

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_draw_style_text
 * DESCRIPTION
 *  draw style text
 * PARAMETERS
 *  str          [IN]        String to be draw
 *  offset_x     [IN]        x position
 *  offset_y     [IN]        y position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_draw_style_text_with_color(
        CHAR *str, S32 offset_x, S32 offset_y, color text_color, color border_color)
{
#ifdef __MMI_ATV_OSD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (r2lMMIFlag)
    {
        offset_x += gui_get_string_width((UI_string_type) str);
    }

    gui_move_text_cursor(offset_x, offset_y);
    gui_set_text_color(text_color);
    #if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MTV_FTE2_LAYOUT__))    
    gui_print_text((UI_string_type) str);
    #else
    gui_set_text_border_color(border_color); //67,87,153
    gui_print_bordered_text((UI_string_type) str);
    #endif
#endif /*  __MMI_ATV_OSD_SUPPORT__  */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_draw_style_text
 * DESCRIPTION
 *  draw style text
 * PARAMETERS
 *  str          [IN]        String to be draw
 *  offset_x     [IN]        x position
 *  offset_y     [IN]        y position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_draw_style_text(CHAR * str, S32 offset_x, S32 offset_y)
{
#ifdef __MMI_ATV_OSD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_mtv_player_draw_style_text_with_color(
        str, offset_x, offset_y, gui_color(255,255,255), gui_color(0,0,0));

#endif /*  __MMI_ATV_OSD_SUPPORT__  */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_draw_truncated_style_text
 * DESCRIPTION
 *  mobile tv player draw channel name (truncated)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_draw_truncated_style_text(CHAR* str, S32 offset_x, S32 offset_y, S32 width)
{
#ifdef __MMI_ATV_OSD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (r2lMMIFlag)
    {
        offset_x += width;
    }

    gui_move_text_cursor(offset_x, offset_y);
    gui_set_text_color(gui_color(255,255,255));
    gui_set_text_border_color(gui_color(0,0,0));
    gui_print_truncated_borderd_text(offset_x, offset_y, width, (UI_string_type) str);
#endif /*  __MMI_ATV_OSD_SUPPORT__  */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_draw_style_multiline_text
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_draw_multiline_style_text(CHAR* str, S32 offset_x, S32 offset_y, S32 width)
{
#ifdef __MMI_ATV_OSD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width = 0;
    S32 str_height = 0;
    S32 str_len = 0;
    S32 line_height;
	S32 w,h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gui_measure_string((UI_string_type)str, &str_width, &str_height);

    str_len = mmi_ucs2strlen((CHAR*) str);

    create_multiline_inputbox_set_buffer((UI_string_type)str, str_len, str_len, 0);

    /* Set border flag */
    MMI_multiline_inputbox.normal_text_color = gui_color(255,255,255);
    MMI_multiline_inputbox.border_color = gui_color(0,0,0);
    MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_USE_BORDER_FONT;

    /* Set as center alignment & other parameters */
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW
                                 | UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY
                                 | UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND
                                 | UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR;

#if defined(__MMI_MTV_SMALL_HINT__)
	 MMI_multiline_inputbox.text_font = &MMI_small_font;
#else
	 MMI_multiline_inputbox.text_font = &MMI_medium_font;
#endif

    line_height = get_multiline_inputbox_line_height();

    /* Set multiline region */
    move_multiline_inputbox(offset_x, offset_y);

	wgui_inputs_ml_resize_fit(
		width,
        (MMI_multiline_inputbox.n_lines * line_height) + MULTILINE_INPUTBOX_HEIGHT_PAD + MMI_multiline_inputbox.text_y,
		&w,
		&h);
    
    show_multiline_inputbox();
#endif /*  __MMI_ATV_OSD_SUPPORT__  */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_draw_osd_softkey
 * DESCRIPTION
 *  mobile tv player draw osd softkey handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_draw_osd_softkey(void)
{
#if defined(__MMI_ATV_OSD_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    S32 offset = 0;
    U16 rsk_up_id, rsk_down_id;    
    S32 lsk_offset_x = 0;
    S32 lsk_offset_y = 0;
    S32 rsk_offset_x = 0;
    S32 rsk_offset_y = 0;
    CHAR *str_ptr;
    color sk_color, sk_border_color;

    S32 dim_x1, dim_x2, dim_y1, dim_y2;
    S32 str_w, str_h;
    S32  str_x1, str_y1;
    S32  trunc_w;
    MMI_BOOL is_trunc;
#else 
    S32 lsk_offset_x = 0;
    S32 lsk_offset_y = 0;
    S32 rsk_offset_x = 0;
    S32 rsk_offset_y = 0;
    CHAR *str_ptr;
#ifdef __MMI_MTV_LANDSCAPE_SUPPORT__
    U16 rsk_up_id, rsk_down_id;
#endif
    color sk_color, sk_border_color;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    if (mtv_player_p->active_osd_cntx_p->lsk.status != MTV_PLAYER_ICON_STATUS_DISABLE)
    {
        /* lsk */
        if(mtv_player_p->active_osd_cntx_p->lsk.status == MTV_PLAYER_ICON_STATUS_ENABLE)
        {
            gdi_image_draw_id(
                mtv_player_p->active_osd_cntx_p->lsk.offset_x,
                mtv_player_p->active_osd_cntx_p->lsk.offset_y,
                (U16)(IMG_ID_MTV_PLAYER_OPTION_UP));
        }
        else if(mtv_player_p->active_osd_cntx_p->lsk.status == MTV_PLAYER_ICON_STATUS_CLICKED)
        {
            gdi_image_draw_id(
                mtv_player_p->active_osd_cntx_p->lsk.offset_x,
                mtv_player_p->active_osd_cntx_p->lsk.offset_y,
                (U16)(IMG_ID_MTV_PLAYER_OPTION_DOWN));
        }
        offset = 0;
    }
    else if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        offset = 2;
    }

#ifdef __MMI_MTV_RECORD_SUPPORT__
    if (RECORDER_STATE_IN(MTV_RECORDER_RECORD) || RECORDER_STATE_IN(MTV_RECORDER_PAUSE))
    {
        rsk_up_id = IMG_ID_MTV_PLAYER_STOP_UP;
        #if defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__)
        rsk_down_id = IMG_ID_MTV_PLAYER_STOP_UP;

        gdi_layer_reset_clip();
        gdi_layer_reset_text_clip();

        /* if is fullscreen display, or normal display but without mmi_softkey */
        gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_BUTTON));

        /* rsk */
        rsk_offset_x = mtv_player_p->active_osd_cntx_p->rsk.offset_x;
        rsk_offset_y = mtv_player_p->active_osd_cntx_p->rsk.offset_y;

        if (mtv_player_p->active_osd_cntx_p->rsk.status == MTV_PLAYER_ICON_STATUS_CLICKED)
        {
            rsk_offset_x ++;
            rsk_offset_y ++;

            sk_color = *(current_MMI_theme->LSK_down_text_color);
            sk_border_color = *(current_MMI_theme->softkey_down_text_border_color);
        }
        else
        {
            sk_color = *(current_MMI_theme->LSK_up_text_color);
            sk_border_color = *(current_MMI_theme->softkey_text_border_color);
        }

        str_ptr = (CHAR*) GetString(STR_GLOBAL_STOP);
        gui_measure_string((UI_string_type) GetString(STR_GLOBAL_STOP), &str_w, &str_h);
        wgui_softkey_get_position(MMI_RIGHT_SOFTKEY, &dim_x1, &dim_y1);
        wgui_softkey_get_dimension(MMI_RIGHT_SOFTKEY, &dim_x2, &dim_y2);
        is_trunc = wgui_softkey_get_offset(
                        (UI_string_type) GetString(STR_GLOBAL_STOP), 
                        &str_x1, 
                        &str_y1, 
                        &trunc_w, 
                        MMI_RIGHT_SOFTKEY,
                        mmi_frm_get_screen_rotate());
        if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        {
            #if !defined(__MMI_MTV_LANDSCAPE_SUPPORT__)
            str_x1 = LCD_HEIGHT - (LCD_WIDTH-str_x1);
            #endif
            str_y1 = dim_y2 - (LCD_HEIGHT-str_y1);
        }

        if(r2lMMIFlag)
        {
            str_x1 -=str_w;
        }
        if (mtv_player_p->active_osd_cntx_p->rsk.status == MTV_PLAYER_ICON_STATUS_CLICKED)
        {
            str_x1++;
            str_y1++;
        }
        if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        {
            S32 width, height;
            sk_color = gui_color(255,255,255);
            gdi_image_get_dimension_id(IMG_ID_MTV_PLAYER_STOP_BUTTON_BG_DOWN, &width, &height);
            if (mtv_player_p->active_osd_cntx_p->rsk.status == MTV_PLAYER_ICON_STATUS_CLICKED)
            {
                 gdi_image_draw_resized(
                    str_x1 - 6,
                    str_y1 - ((height - str_h)/2),
                    str_w + 12,
                    height,
                    (PU8)GetImage(IMG_ID_MTV_PLAYER_STOP_BUTTON_BG_DOWN));
            }
            else
            {
                   gdi_image_draw_resized(
                    str_x1 - 6,
                    str_y1 - ((height - str_h)/2),
                    str_w + 12,
                    height,
                    (PU8)GetImage(IMG_ID_MTV_PLAYER_STOP_BUTTON_BG_UP));
            }
        }
        else
        {
            if (mtv_player_p->active_osd_cntx_p->rsk.status == MTV_PLAYER_ICON_STATUS_CLICKED)
            {
                sk_color = gui_color(69,203,227); // 45cbe3
            }
            else
            {
                sk_color = gui_color(255,255,255);
            }
        }
        
        mmi_mtv_player_draw_style_text_with_color(
                str_ptr, str_x1, str_y1, sk_color, sk_border_color);

        return ;
        
        #else
        rsk_down_id = IMG_ID_MTV_PLAYER_STOP_DOWN;
        #endif
    }
    else
#endif /* __MMI_MTV_RECORD_SUPPORT__ */
    {
        rsk_up_id = IMG_ID_MTV_PLAYER_BACK_UP;
        rsk_down_id = IMG_ID_MTV_PLAYER_BACK_DOWN;

        #if defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__)
        /* rsk */
        if(mtv_player_p->active_osd_cntx_p->rsk.status == MTV_PLAYER_ICON_STATUS_ENABLE)
        {
            gdi_image_draw_id(
                mtv_player_p->active_osd_cntx_p->rsk.offset_x,
                mtv_player_p->active_osd_cntx_p->rsk.offset_y,
                (U16)(IMG_ID_MTV_PLAYER_BACK_UP + offset));
        }
        else if(mtv_player_p->active_osd_cntx_p->rsk.status == MTV_PLAYER_ICON_STATUS_CLICKED)
        {
            gdi_image_draw_id(
                mtv_player_p->active_osd_cntx_p->rsk.offset_x,
                mtv_player_p->active_osd_cntx_p->rsk.offset_y,
                (U16)(IMG_ID_MTV_PLAYER_BACK_DOWN + offset));     
        }
        return ;
        #endif
    }
    /* rsk */
    if(mtv_player_p->active_osd_cntx_p->rsk.status == MTV_PLAYER_ICON_STATUS_ENABLE)
    {
        gdi_image_draw_id(
            mtv_player_p->active_osd_cntx_p->rsk.offset_x,
            mtv_player_p->active_osd_cntx_p->rsk.offset_y,
            (U16)(rsk_up_id + offset));
    }
    else if(mtv_player_p->active_osd_cntx_p->rsk.status == MTV_PLAYER_ICON_STATUS_CLICKED)
    {
        #if defined(__MMI_MTV_RECORD_SUPPORT__) 
        if (RECORDER_STATE_IN(MTV_RECORDER_RECORD) || RECORDER_STATE_IN(MTV_RECORDER_PAUSE))
        {
            gdi_image_draw_id(
               mtv_player_p->active_osd_cntx_p->rsk.offset_x,
                mtv_player_p->active_osd_cntx_p->rsk.offset_y,
                (U16)(rsk_down_id + offset));
        }
        #else        
        gdi_image_draw_id(
            mtv_player_p->active_osd_cntx_p->rsk.offset_x,
            mtv_player_p->active_osd_cntx_p->rsk.offset_y,
            (U16)(rsk_down_id + offset));
        #endif
    }
#else /* __MMI_FTE_SUPPORT__ */

#ifdef __MMI_MTV_LANDSCAPE_SUPPORT__
    /* Only RSK icon */
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
    #ifdef __MMI_MTV_RECORD_SUPPORT__
        if (RECORDER_STATE_IN(MTV_RECORDER_RECORD) || RECORDER_STATE_IN(MTV_RECORDER_PAUSE))
        {
            rsk_up_id = IMG_ID_MTV_PLAYER_STOP_UP_H;
            rsk_down_id = IMG_ID_MTV_PLAYER_STOP_DOWN_H;
        }
        else
    #endif
        {
            rsk_up_id = IMG_ID_MTV_PLAYER_BACK_UP_H;
            rsk_down_id = IMG_ID_MTV_PLAYER_BACK_DOWN_H;
        }

        /* rsk */
        if(mtv_player_p->active_osd_cntx_p->rsk.status == MTV_PLAYER_ICON_STATUS_ENABLE)
        {
            gdi_image_draw_id(
                mtv_player_p->active_osd_cntx_p->rsk.offset_x,
                mtv_player_p->active_osd_cntx_p->rsk.offset_y,
                (U16)(rsk_up_id));
        }
        else if(mtv_player_p->active_osd_cntx_p->rsk.status == MTV_PLAYER_ICON_STATUS_CLICKED)
        {
            gdi_image_draw_id(
                mtv_player_p->active_osd_cntx_p->rsk.offset_x,
                mtv_player_p->active_osd_cntx_p->rsk.offset_y,
                (U16)(rsk_down_id));
        }
        return; /* Don't remove it */
    }
#endif /*__MMI_MTV_LANDSCAPE_SUPPORT__ */

    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    /* if is fullscreen display, or normal display but without mmi_softkey */
    gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_BUTTON));

    /* Full screen does not have LSK */
    if (mtv_player_p->active_osd_cntx_p->lsk.status != MTV_PLAYER_ICON_STATUS_DISABLE)
    {
        lsk_offset_x = mtv_player_p->active_osd_cntx_p->lsk.offset_x;
        lsk_offset_y = mtv_player_p->active_osd_cntx_p->lsk.offset_y;

        if (mtv_player_p->active_osd_cntx_p->lsk.status == MTV_PLAYER_ICON_STATUS_CLICKED)
        {
            lsk_offset_x++;
            lsk_offset_y++;

            sk_color = *(current_MMI_theme->LSK_down_text_color);
            sk_border_color = *(current_MMI_theme->softkey_down_text_border_color);
        }
        else
        {
            sk_color = *(current_MMI_theme->LSK_up_text_color);
            sk_border_color = *(current_MMI_theme->softkey_text_border_color);
        }
        str_ptr = (CHAR*) GetString(STR_GLOBAL_OPTIONS);

        mmi_mtv_player_draw_style_text_with_color(
            str_ptr, lsk_offset_x, lsk_offset_y, sk_color, sk_border_color);
    }


    /* rsk */
    rsk_offset_x = mtv_player_p->active_osd_cntx_p->rsk.offset_x;
    rsk_offset_y = mtv_player_p->active_osd_cntx_p->rsk.offset_y;

    if (mtv_player_p->active_osd_cntx_p->rsk.status == MTV_PLAYER_ICON_STATUS_CLICKED)
    {
        rsk_offset_x ++;
        rsk_offset_y ++;

        sk_color = *(current_MMI_theme->LSK_down_text_color);
        sk_border_color = *(current_MMI_theme->softkey_down_text_border_color);
    }
    else
    {
        sk_color = *(current_MMI_theme->LSK_up_text_color);
        sk_border_color = *(current_MMI_theme->softkey_text_border_color);
    }

    /* disable font alpha */
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        mmi_fe_set_antialias(MMI_FALSE);
    }
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */

    if (RECORDER_STATE_IN(MTV_RECORDER_RECORD) || RECORDER_STATE_IN(MTV_RECORDER_PAUSE))
    {
        str_ptr = (CHAR*) GetString(STR_GLOBAL_STOP);
    }
    else
    {
        str_ptr = (CHAR*) GetString(STR_GLOBAL_BACK);
    }

    mmi_mtv_player_draw_style_text_with_color(
            str_ptr, rsk_offset_x, rsk_offset_y, sk_color, sk_border_color);

    /* enable font alpha */
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        mmi_fe_set_antialias(MMI_TRUE);
    }
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */
#endif /* __MMI_FTE_SUPPORT__ */

#endif /* defined(__MMI_ATV_OSD_SUPPORT__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_fullscr_osd_show_up
 * DESCRIPTION
 *  fade fullscr osd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_fullscr_osd_show_up(void)
{
#ifdef __MMI_ATV_OSD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mtv_player_register_key_hdlr();
    mmi_mtv_player_fullscr_reset_osd_fade(MMI_TRUE);
    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    ClearKeyEvents();
#endif /* __MMI_ATV_OSD_SUPPORT__  */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_reset_key_handler
 * DESCRIPTION
 *  fade fullscr osd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_reset_key_handler(void(*func_ptr)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetKeyHandler(func_ptr, KEY_1, KEY_EVENT_DOWN);
    SetKeyHandler(func_ptr, KEY_2, KEY_EVENT_DOWN);
    SetKeyHandler(func_ptr, KEY_3, KEY_EVENT_DOWN);
    SetKeyHandler(func_ptr, KEY_4, KEY_EVENT_DOWN);
    SetKeyHandler(func_ptr, KEY_5, KEY_EVENT_DOWN);
    SetKeyHandler(func_ptr, KEY_6, KEY_EVENT_DOWN);
    SetKeyHandler(func_ptr, KEY_7, KEY_EVENT_DOWN);
    SetKeyHandler(func_ptr, KEY_8, KEY_EVENT_DOWN);
    SetKeyHandler(func_ptr, KEY_9, KEY_EVENT_DOWN);
    SetKeyHandler(func_ptr, KEY_0, KEY_EVENT_DOWN);
    SetKeyHandler(func_ptr, KEY_POUND, KEY_EVENT_DOWN);
    SetKeyHandler(func_ptr, KEY_STAR, KEY_EVENT_DOWN);
    SetKeyHandler(func_ptr, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(func_ptr, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(func_ptr, KEY_CSK, KEY_EVENT_DOWN);
    SetKeyHandler(func_ptr, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(func_ptr, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    #if (defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__))
    SetKeyHandler(func_ptr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(func_ptr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    #endif
    SetKeyHandler(func_ptr, KEY_CLEAR, KEY_EVENT_DOWN);
    SetKeyHandler(func_ptr, KEY_CAMERA, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_fullscr_osd_fade_cyclic
 * DESCRIPTION
 *  fade fullscr osd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_fullscr_osd_fade_cyclic(void)
{
#ifdef __MMI_ATV_OSD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 left_rewind, right_forward, up_next_channel, down_prev_channel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_MTV_LANDSCAPE_SUPPORT__) || (defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__))
    left_rewind = KEY_LEFT_ARROW;
    right_forward = KEY_RIGHT_ARROW;
    up_next_channel = KEY_UP_ARROW;
    down_prev_channel = KEY_DOWN_ARROW;
#else
    left_rewind = KEY_UP_ARROW;
    right_forward = KEY_DOWN_ARROW;
    up_next_channel = KEY_RIGHT_ARROW;
    down_prev_channel = KEY_LEFT_ARROW;
#endif

    /* reset fullscreen osd fade out timer */
    if (mtv_player_p->fullscr_osd_opacity > MMI_MOBILE_TV_PLAYER_OSD_FADE_OUT_VALUE)
    {
        mtv_player_p->fullscr_osd_opacity -= MMI_MOBILE_TV_PLAYER_OSD_FADE_OUT_VALUE;

        gui_start_timer(100, mmi_mtv_player_fullscr_osd_fade_cyclic);
    }
    else if(mtv_player_p->touch_object != MTV_PLAYER_TOUCH_NONE)
    {
        mtv_player_p->fullscr_osd_opacity = 0;
        gui_start_timer(100, mmi_mtv_player_fullscr_osd_fade_cyclic);
    }
    else
    {
        mtv_player_p->fullscr_osd_opacity = 0;

        /* if totally fade out, use any key to wake up */
        ClearInputEventHandler(MMI_DEVICE_ALL);

        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_1, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_2, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_3, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_4, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_5, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_6, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_7, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_8, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_9, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_0, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_STAR, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_LSK, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_RSK, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_CSK, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, up_next_channel, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, down_prev_channel, KEY_EVENT_UP);
    #if (defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__))
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, left_rewind, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, right_forward, KEY_EVENT_UP);
      
    #endif
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_CLEAR, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_CAMERA, KEY_EVENT_UP);
    #if !defined(__MMI_FTE_SUPPORT__)
        SetKeyHandler(mmi_mtv_player_vol_status_icon_press, KEY_POUND, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_mtv_player_dummy, KEY_POUND, KEY_EVENT_UP);
    #else /* !defined(__MMI_FTE_SUPPORT__) */
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_POUND, KEY_EVENT_UP);
    #endif /* defined(__MMI_FTE_SUPPORT__) */

        #if !(defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__))
        SetKeyHandler(mmi_mtv_player_vol_inc_icon_press, right_forward, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_mtv_player_vol_inc_icon_release, right_forward, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_vol_dec_icon_press, left_rewind, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_mtv_player_vol_dec_icon_release, left_rewind, KEY_EVENT_UP);
        #endif

    #if defined(__MMI_FTE_SUPPORT__) 
        SetKeyHandler(mmi_mtv_player_vol_inc_icon_press, KEY_VOL_UP, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_mtv_player_vol_inc_icon_release, KEY_VOL_UP, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_vol_dec_icon_press, KEY_VOL_DOWN, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_mtv_player_vol_dec_icon_release, KEY_VOL_DOWN, KEY_EVENT_UP);
    #else /* defined(__MMI_FTE_SUPPORT__) */
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_VOL_UP, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_VOL_DOWN, KEY_EVENT_UP);
    #endif /* defined(__MMI_FTE_SUPPORT__) */
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_register_pen_down_handler(mmi_mtv_player_pen_down_hdlr_fullscreen);
    #endif
    }

    gdi_layer_push_and_set_active(mtv_player_p->osd_layer_handle);
    gdi_layer_set_opacity(MMI_TRUE, (U8) mtv_player_p->fullscr_osd_opacity);
    gdi_layer_pop_and_restore_active();

    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif /* __MMI_ATV_OSD_SUPPORT__  */
}



/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_fullscr_reset_osd_fade
 * DESCRIPTION
 *  fade fullscr osd
 * PARAMETERS
 *  sleep       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_fullscr_reset_osd_fade(BOOL sleep)
{
#if defined(__MMI_ATV_OSD_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_mtv_player_fullscr_osd_fade_cyclic);

    if (mtv_player_p->fullscr_osd_opacity != MMI_MOBILE_TV_PLAYER_OSD_FADEOUT_FACTOR)
    {

        mtv_player_p->fullscr_osd_opacity = MMI_MOBILE_TV_PLAYER_OSD_FADEOUT_FACTOR;

        mmi_mtv_player_draw_osd();

        gdi_layer_push_and_set_active(mtv_player_p->osd_layer_handle);
        gdi_layer_set_opacity(MMI_TRUE, (U8) mtv_player_p->fullscr_osd_opacity);
        gdi_layer_pop_and_restore_active();
    }
    else
    {
        mmi_mtv_player_draw_osd();
    }


    if (sleep)
    {
        /* These cases does not allow fade out */
        if (mmi_mtv_player_is_flag_set(MTV_PLAYER_SERVICE_UNAVAILABLE) ||
            mmi_mtv_player_is_flag_set(MTV_PLAYER_UNAVAILABLE_IN_CALL) ||
            mtv_player_p->touch_object != MTV_PLAYER_TOUCH_NONE)
        {
            return;
        }

        /* start fade out timer */
        gui_start_timer(MMI_MOBILE_TV_PLAYER_OSD_FADE_OUT_TIME, mmi_mtv_player_fullscr_osd_fade_cyclic);
    }
#endif /* defined(__MMI_ATV_OSD_SUPPORT__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_draw_animation
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_draw_animation(
        S32 offset_x, S32 offset_y, S32 width, S32 height,
        U16 image_id, gdi_handle *anima_handle)
{
#ifdef __MMI_ATV_OSD_SUPPORT__
#if !defined(GDI_2_LAYERS)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_layer_struct *layer, *drawing_layer;
    gdi_rect_struct dest_clip = {0, 0, LCD_WIDTH-1, LCD_HEIGHT-1};
    gdi_rect_struct icon_region;
    MMI_BOOL rotate;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Assign rotate value */
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        rotate = MMI_FALSE;
    }
    else
    {

    #if defined(__MDI_MTV_HW_ROTATOR_SUPPORT__) && !defined(__MMI_MTV_LANDSCAPE_SUPPORT__)
        rotate = MMI_TRUE;
    #else /* __MDI_MTV_HW_ROTATOR_SUPPORT__ && !__MMI_MTV_LANDSCAPE_SUPPORT__ */
        rotate = MMI_FALSE;
    #endif /* __MDI_MTV_HW_ROTATOR_SUPPORT__ && !__MMI_MTV_LANDSCAPE_SUPPORT__*/
    }

    if (!rotate)
    {
        if (*anima_handle == 0)
        {
            gdi_anim_draw_id(
                offset_x,
                offset_y,
                image_id,
                anima_handle);
        }
        else
        {
            layer = (gdi_layer_struct *) mtv_player_p->osd_layer_handle;

            gdi_2d_memory_blt_without_transpant_check(
                layer->buf_ptr1,
                layer->width,
                offset_x,
                offset_y,
                width,
                height,
                layer->buf_ptr,
                layer->width,
                offset_x,
                offset_y,
                dest_clip,
                layer->bits_per_pixel);
        }
    }
    else /* App screen: rotate 270 */
    {
        if (*anima_handle == 0)
        {
            gdi_anim_set_draw_after_callback(
                mmi_mtv_player_animation_draw_after_hdlr);

            gdi_anim_draw_id(
                offset_x,
                offset_y,
                image_id,
                anima_handle);
        }
        else
        {
            layer = (gdi_layer_struct *) mtv_player_p->osd_layer_handle;
            drawing_layer = (gdi_layer_struct *) mtv_player_p->osd_drawing_layer_handle;

            icon_region.x1 = offset_x;
            icon_region.x2 = offset_x + width;
            icon_region.y1 = offset_y;
            icon_region.y2 = offset_y + height;

            mmi_mtv_player_counter_clockwise_rotate(
                drawing_layer->buf_ptr,
                layer->buf_ptr,
                drawing_layer->width,
                drawing_layer->height,
                &icon_region);
        }
    }
#endif /* !defined(GDI_2_LAYERS) */
#endif /* __MMI_ATV_OSD_SUPPORT__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_animation_draw_after_hdlr
 * DESCRIPTION
 *  mobile tv player animation draw after handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_animation_draw_after_hdlr(GDI_RESULT result)
{
#ifdef __MMI_ATV_OSD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef GDI_USING_2D_ENGINE_V3
    PU8 dest;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270);

    /* Copy osd_drawing_layer to osd_layer */
    gdi_layer_push_and_set_active(mtv_player_p->osd_layer_handle);
#if !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
    gdi_layer_toggle_double();
#endif
#if defined(GDI_USING_2D_ENGINE_V3)
    gdi_2d_begin();
    gdi_2d_set_layer_as_dest_buffer(mtv_player_p->osd_layer_handle);
    gdi_2d_set_layer_as_src_bitblt_buffer(mtv_player_p->osd_drawing_layer_handle);
    gdi_2d_rotate(GDI_TRANSFORM_ROTATE_90);
    gdi_2d_end();
#else
    gdi_layer_get_buffer_ptr(&dest);
    /* toggle double buffer */
    mmi_mtv_player_sw_rotate(
        dest,
        mtv_player_p->osd_drawing_layer_buf_ptr,
        (U32) LCD_HEIGHT,
        (U32) LCD_WIDTH);
#endif
    gdi_layer_pop_and_restore_active();

    /* GDI only blt the animation icon region in protrait coordinate. So we need to blt */
    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif /* __MMI_ATV_OSD_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_draw_osd_other
 * DESCRIPTION
 *  mobile tv player draw osd other
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_draw_osd_other(void)
{
#if defined(__MMI_ATV_OSD_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset = 0;
    S32 offset1 = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        offset = 0;
        offset1 = offset;
    }
    else if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        #if defined(__MMI_MTV_FTE2_LAYOUT__)&& defined(__MMI_FTE_SUPPORT__)
        offset1 = 2;
        #else        
        offset = 3;
        offset1 = offset;
        #endif
    }

    /* Fullscreen */
    if(mtv_player_p->active_osd_cntx_p->fullscreen.status == MTV_PLAYER_ICON_STATUS_ENABLE)
    {
        gdi_image_draw_id(
            mtv_player_p->active_osd_cntx_p->fullscreen.offset_x,
            mtv_player_p->active_osd_cntx_p->fullscreen.offset_y,
            (U16)(IMG_ID_MTV_PLAYER_FULLSCREEN_UP + offset1));
    }
    else if(mtv_player_p->active_osd_cntx_p->fullscreen.status == MTV_PLAYER_ICON_STATUS_CLICKED)
    {
        #if defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__)
        gdi_image_draw_id(
            mtv_player_p->active_osd_cntx_p->fullscreen.offset_x,
            mtv_player_p->active_osd_cntx_p->fullscreen.offset_y,
            (U16)(IMG_ID_MTV_PLAYER_FULLSCREEN_UP + offset1));
        gdi_image_draw_id(
            mtv_player_p->active_osd_cntx_p->fullscreen.offset_x,
            mtv_player_p->active_osd_cntx_p->fullscreen.offset_y,
            (U16)(IMG_ID_MTV_PLAYER_PRESS_HIGHT));

        #else
        gdi_image_draw_id(
            mtv_player_p->active_osd_cntx_p->fullscreen.offset_x,
            mtv_player_p->active_osd_cntx_p->fullscreen.offset_y,
            (U16)(IMG_ID_MTV_PLAYER_FULLSCREEN_DOWN + offset));
        #endif
    }
    else if(mtv_player_p->active_osd_cntx_p->fullscreen.status == MTV_PLAYER_ICON_STATUS_DISABLE)
    {
        gdi_image_draw_id(
            mtv_player_p->active_osd_cntx_p->fullscreen.offset_x,
            mtv_player_p->active_osd_cntx_p->fullscreen.offset_y,
            (U16)(IMG_ID_MTV_PLAYER_FULLSCREEN_DISABLE + offset));
    }

    /* Channel next */
    if(mtv_player_p->active_osd_cntx_p->channel_next.status == MTV_PLAYER_ICON_STATUS_ENABLE)
    {
        gdi_image_draw_id(
            mtv_player_p->active_osd_cntx_p->channel_next.offset_x,
            mtv_player_p->active_osd_cntx_p->channel_next.offset_y,
            (U16)(IMG_ID_MTV_PLAYER_CHANNEL_NEXT_UP + offset));
    }
    else if(mtv_player_p->active_osd_cntx_p->channel_next.status == MTV_PLAYER_ICON_STATUS_CLICKED)
    {
        #if defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__)
        gdi_image_draw_id(
            mtv_player_p->active_osd_cntx_p->channel_next.offset_x,
            mtv_player_p->active_osd_cntx_p->channel_next.offset_y,
            (U16)(IMG_ID_MTV_PLAYER_CHANNEL_NEXT_UP + offset));
        gdi_image_draw_id(
            mtv_player_p->active_osd_cntx_p->channel_next.offset_x,
            mtv_player_p->active_osd_cntx_p->channel_next.offset_y,
            (U16)(IMG_ID_MTV_PLAYER_PRESS_HIGHT));

        #else
        gdi_image_draw_id(
            mtv_player_p->active_osd_cntx_p->channel_next.offset_x,
            mtv_player_p->active_osd_cntx_p->channel_next.offset_y,
            (U16)(IMG_ID_MTV_PLAYER_CHANNEL_NEXT_DOWN + offset));
        #endif
    }
    else if(mtv_player_p->active_osd_cntx_p->channel_next.status == MTV_PLAYER_ICON_STATUS_DISABLE)
    {
        gdi_image_draw_id(
            mtv_player_p->active_osd_cntx_p->channel_next.offset_x,
            mtv_player_p->active_osd_cntx_p->channel_next.offset_y,
            (U16)(IMG_ID_MTV_PLAYER_CHANNEL_NEXT_DISABLE + offset));
    }


    /* Channel prev */
    if(mtv_player_p->active_osd_cntx_p->channel_prev.status == MTV_PLAYER_ICON_STATUS_ENABLE)
    {
        gdi_image_draw_id(
            mtv_player_p->active_osd_cntx_p->channel_prev.offset_x,
            mtv_player_p->active_osd_cntx_p->channel_prev.offset_y,
            (U16)(IMG_ID_MTV_PLAYER_CHANNEL_PREV_UP + offset));
    }
    else if(mtv_player_p->active_osd_cntx_p->channel_prev.status == MTV_PLAYER_ICON_STATUS_CLICKED)
    {
        #if defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__)
        gdi_image_draw_id(
            mtv_player_p->active_osd_cntx_p->channel_prev.offset_x,
            mtv_player_p->active_osd_cntx_p->channel_prev.offset_y,
            (U16)(IMG_ID_MTV_PLAYER_CHANNEL_PREV_UP + offset));
        gdi_image_draw_id(
            mtv_player_p->active_osd_cntx_p->channel_prev.offset_x,
            mtv_player_p->active_osd_cntx_p->channel_prev.offset_y,
            (U16)(IMG_ID_MTV_PLAYER_PRESS_HIGHT));

        #else
        gdi_image_draw_id(
            mtv_player_p->active_osd_cntx_p->channel_prev.offset_x,
            mtv_player_p->active_osd_cntx_p->channel_prev.offset_y,
            (U16)(IMG_ID_MTV_PLAYER_CHANNEL_PREV_DOWN + offset));
        #endif
    }
    else if(mtv_player_p->active_osd_cntx_p->channel_prev.status == MTV_PLAYER_ICON_STATUS_DISABLE)
    {
        gdi_image_draw_id(
            mtv_player_p->active_osd_cntx_p->channel_prev.offset_x,
            mtv_player_p->active_osd_cntx_p->channel_prev.offset_y,
            (U16)(IMG_ID_MTV_PLAYER_CHANNEL_PREV_DISABLE + offset));
    }
#endif /* defined(__MMI_ATV_OSD_SUPPORT__)  */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_draw_osd_vol_inc_dec_icon
 * DESCRIPTION
 *  mobile tv player draw osd volume
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_draw_osd_vol_inc_dec_icon(void)
{
#if defined(__MMI_ATV_OSD_SUPPORT__)
#if defined(__MMI_MTV_LANDSCAPE_SUPPORT__) && !defined(__MMI_FTE_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_MTV_LANDSCAPE_SUPPORT__
    if (mtv_player_p->ui_rotate != MMI_FRM_SCREEN_ROTATE_0)
    {
        return;
    }
#endif

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        offset = 0;
    }
    else
    {
        offset = 2;
    }

    /* Volume key: up */
    if (mtv_player_p->setting.vol_level == MTV_PLAYER_VOL_16)
    {
    #if defined(__MMI_MTV_LANDSCAPE_SUPPORT__)  && !defined(__MMI_FTE_SUPPORT__)
        gdi_image_draw_id(mtv_player_p->active_osd_cntx_p->vol_inc.offset_x,mtv_player_p->active_osd_cntx_p->vol_inc.offset_y,(U16)(IMG_ID_MTV_PLAYER_VOL_INC_DISABLE));
    #endif
    }
    else if(mtv_player_p->active_osd_cntx_p->vol_inc.status == MTV_PLAYER_ICON_STATUS_ENABLE)
    {
        gdi_image_draw_id(mtv_player_p->active_osd_cntx_p->vol_inc.offset_x,mtv_player_p->active_osd_cntx_p->vol_inc.offset_y,(U16)(IMG_ID_MTV_PLAYER_VOL_INC_UP+offset));
    }
    else if(mtv_player_p->active_osd_cntx_p->vol_inc.status == MTV_PLAYER_ICON_STATUS_CLICKED)
    {
        gdi_image_draw_id(mtv_player_p->active_osd_cntx_p->vol_inc.offset_x,mtv_player_p->active_osd_cntx_p->vol_inc.offset_y,(U16)(IMG_ID_MTV_PLAYER_VOL_INC_DOWN+offset));
    }

    /* Volume key: down */
    if (mtv_player_p->setting.vol_level == MTV_PLAYER_VOL_MUTE)
    {
    #if defined(__MMI_MTV_LANDSCAPE_SUPPORT__) && !defined(__MMI_FTE_SUPPORT__)
        gdi_image_draw_id(mtv_player_p->active_osd_cntx_p->vol_dec.offset_x,mtv_player_p->active_osd_cntx_p->vol_dec.offset_y,(U16)(IMG_ID_MTV_PLAYER_VOL_DEC_DISABLE));
    #endif
    }
    else if(mtv_player_p->active_osd_cntx_p->vol_dec.status == MTV_PLAYER_ICON_STATUS_ENABLE)
    {
        gdi_image_draw_id(mtv_player_p->active_osd_cntx_p->vol_dec.offset_x,mtv_player_p->active_osd_cntx_p->vol_dec.offset_y,(U16)(IMG_ID_MTV_PLAYER_VOL_DEC_UP+offset));
    }
    else if(mtv_player_p->active_osd_cntx_p->vol_dec.status == MTV_PLAYER_ICON_STATUS_CLICKED)
    {
        gdi_image_draw_id(mtv_player_p->active_osd_cntx_p->vol_dec.offset_x,mtv_player_p->active_osd_cntx_p->vol_dec.offset_y,(U16)(IMG_ID_MTV_PLAYER_VOL_DEC_DOWN+offset));
    }
#endif /* #if defined(__MMI_MTV_LANDSCAPE_SUPPORT__) */
#endif /* #if defined(__MMI_ATV_OSD_SUPPORT__)  */
}


#if !defined(__MMI_FTE_SUPPORT__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MTV_FTE2_LAYOUT__))
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_draw_osd_volume_status
 * DESCRIPTION
 *  mobile tv player draw osd volume
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_draw_osd_volume_status(void)
{
#if defined(__MMI_ATV_OSD_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mtv_player_layout_struct *osd_p = mtv_player_p->active_osd_cntx_p;
    S32 length, offset = 0;
    S32 w,h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        return;
    }

    gui_measure_image((PU8)GetImage(IMG_ID_MTV_PLAYER_VOL_STATUS_ON), &w, &h);

    /* Status */
    if (mtv_player_p->setting.is_mute)
    {
    	#if defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__)
        if(osd_p->vol_status.status == MTV_PLAYER_ICON_STATUS_CLICKED)
        {
        gdi_image_draw_resized_id(
            osd_p->vol_status.offset_x,
            osd_p->vol_status.offset_y,
            w,h,
            (U16)(IMG_ID_MTV_PLAYER_PRESS_HIGHT));
        }
      #endif
        gdi_image_draw_id(
            osd_p->vol_status.offset_x,
            osd_p->vol_status.offset_y,
            IMG_ID_MTV_PLAYER_VOL_STATUS_OFF + offset);
    }
    else
    {
    	#if defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__)
        if(osd_p->vol_status.status == MTV_PLAYER_ICON_STATUS_CLICKED)
        {
        gdi_image_draw_resized_id(
            osd_p->vol_status.offset_x,
            osd_p->vol_status.offset_y,
            w,h,
            (U16)(IMG_ID_MTV_PLAYER_PRESS_HIGHT));
        }
        #endif
        gdi_image_draw_id(
            osd_p->vol_status.offset_x,
            osd_p->vol_status.offset_y,
            IMG_ID_MTV_PLAYER_VOL_STATUS_ON + offset);
    }

    /* Level: background */
    gdi_image_draw_id(
        osd_p->volume.offset_x,
        osd_p->volume.offset_y,
        IMG_ID_MTV_PLAYER_VOL_LEVEL + offset);

    if(mtv_player_p->setting.vol_level > 0)
    {
    length = ((osd_p->volume.width * mtv_player_p->setting.vol_level) >>4);

    /* Level: Part of full level */
    gdi_layer_set_clip(
        osd_p->volume.offset_x,
        osd_p->volume.offset_y,
        osd_p->volume.offset_x + length,
        osd_p->volume.offset_y + osd_p->volume.height);
    gdi_image_draw_id(
        osd_p->volume.offset_x,
        osd_p->volume.offset_y,
        IMG_ID_MTV_PLAYER_VOL_LEVEL_FULL + offset);
    gdi_layer_reset_clip();
    }
#endif /* defined(__MMI_ATV_OSD_SUPPORT__)  */
}
#endif /* !defined(__MMI_FTE_SUPPORT__) */

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_ATV_OSD_SUPPORT__) && !defined(__MMI_MTV_FTE2_LAYOUT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_vol_idx_icon_press
 * DESCRIPTION
 *  mobile tv player vol_idx icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_vol_idx_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->is_key_pressed = MMI_TRUE;
    StopTimer(MTV_PLAYER_VOLUME_ICON_TIMER);
    mmi_mtv_player_draw_fte_vol_icon(); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_vol_idx_icon_release
 * DESCRIPTION
 *  mobile tv player vol_idx icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_vol_idx_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->is_key_pressed = MMI_FALSE;
    mmi_mtv_player_draw_fte_vol_icon(); 
    StartTimer(
        MTV_PLAYER_VOLUME_ICON_TIMER,
        MMI_MOBILE_TV_PLAYER_VOL_ICON_DURATION,
        mmi_mtv_player_hide_fte_vol_icon);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_vol_bg_icon_press
 * DESCRIPTION
 *  mobile tv player vol_bg icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_vol_bg_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->is_key_pressed = MMI_TRUE;
    StopTimer(MTV_PLAYER_VOLUME_ICON_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_vol_bg_icon_release
 * DESCRIPTION
 *  mobile tv player vol_bg icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_vol_bg_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->is_key_pressed = MMI_FALSE;
    StartTimer(
        MTV_PLAYER_VOLUME_ICON_TIMER,
        MMI_MOBILE_TV_PLAYER_VOL_ICON_DURATION,
        mmi_mtv_player_hide_fte_vol_icon);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_hide_fte_vol_icon
 * DESCRIPTION
 *  mmi_mtv_player_vol_icon_timeout_hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_hide_fte_vol_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    StopTimer(MTV_PLAYER_VOLUME_ICON_TIMER);

    mtv_player_p->active_osd_cntx_p->vol_bg.status = MTV_PLAYER_ICON_STATUS_DISABLE;
    mtv_player_p->active_osd_cntx_p->vol_idx.status = MTV_PLAYER_ICON_STATUS_DISABLE;

    gdi_layer_push_and_set_active(mtv_player_p->vol_layer_handle);
#if !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
    gdi_layer_toggle_double();
#endif
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);

    gdi_layer_pop_and_restore_active();

    /* Must put after set vol_bg status as disable */
    mmi_mtv_player_register_key_hdlr();
    ClearKeyEvents();

    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_update_vol_level
 * DESCRIPTION
 *  mobile tv player update vol level
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_update_vol_level(S32 pos_x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mtv_player_layout_struct *osd_p = mtv_player_p->active_osd_cntx_p;
    S32 width, level;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    width = osd_p->vol_bar.width - osd_p->vol_idx.width;
    if (pos_x < osd_p->vol_bar.offset_x)
    {
        mtv_player_p->setting.vol_level = MTV_PLAYER_VOL_MUTE;
    }
    else if (pos_x >= osd_p->vol_bar.offset_x + width)
    {
        mtv_player_p->setting.vol_level = MTV_PLAYER_VOL_16;
    }
    else
    {
        level = (pos_x - osd_p->vol_bar.offset_x) / (width >> 4);
        ASSERT(level <= MTV_PLAYER_VOL_16);
        ASSERT(level >= MTV_PLAYER_VOL_MUTE);
        mtv_player_p->setting.vol_level = level;
    }

    mmi_mtv_player_draw_fte_vol_icon();

    mdi_audio_set_volume(MTV_VOLUME_TYPE, (U8) MDI_AUD_VOL_EX_MUTE(mtv_player_p->setting.vol_level));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_draw_fte_vol_icon
 * DESCRIPTION
 *  mobile tv player draw fte volume
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_draw_fte_vol_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 step, length;
    mtv_player_layout_struct *osd_p = mtv_player_p->active_osd_cntx_p;
    S32 origin_x = osd_p->vol_bg.offset_x;
    S32 origin_y = osd_p->vol_bg.offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mtv_player_p->ui_rotate != MMI_FRM_SCREEN_ROTATE_0)
    {
        return;
    }
    if (mtv_player_p->active_osd_cntx_p->vol_bg.status != MTV_PLAYER_ICON_STATUS_ENABLE)
    {
        return;
    }
    gdi_layer_push_and_set_active(mtv_player_p->vol_layer_handle);

    gdi_push_and_set_alpha_blending_source_layer(mtv_player_p->vol_layer_handle);

#if !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
    gdi_layer_toggle_double();
#endif
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);

    /* Background */
    #if defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__)
    gdi_image_draw_resized(
        osd_p->vol_bg.offset_x - origin_x,
        osd_p->vol_bg.offset_y - origin_y,
        osd_p->vol_bg.width,
        osd_p->vol_bg.height,
        (PU8)GetImage(IMG_ID_MTV_PLAYER_VOL_BG));
    #else
    gdi_image_draw_id(
        osd_p->vol_bg.offset_x - origin_x,
        osd_p->vol_bg.offset_y - origin_y,
        (U16)IMG_ID_MTV_PLAYER_VOL_BG);
    #endif
    /* Status */
    if (mtv_player_p->setting.vol_level == MTV_PLAYER_VOL_MUTE)
    {
        gdi_image_draw_id(
            osd_p->vol_status.offset_x - origin_x,
            osd_p->vol_status.offset_y - origin_y,
            IMG_ID_MTV_PLAYER_VOL_OFF);
    }
    else
    {
        gdi_image_draw_id(
            osd_p->vol_status.offset_x - origin_x,
            osd_p->vol_status.offset_y - origin_y,
            IMG_ID_MTV_PLAYER_VOL_ON);
    }

    /* Bar: background */
    #if defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__)
    gdi_image_draw_resized(
            osd_p->vol_bar.offset_x - origin_x,
            osd_p->vol_bar.offset_y - origin_y,
            osd_p->vol_bar.width,
            osd_p->vol_bar.height,
            (PU8)GetImage(IMG_ID_MTV_PLAYER_VOL_BAR));
    #else
    gdi_image_draw_id(
            osd_p->vol_bar.offset_x - origin_x,
            osd_p->vol_bar.offset_y - origin_y,
            IMG_ID_MTV_PLAYER_VOL_BAR);
    #endif
    step = osd_p->vol_bar.width - osd_p->vol_idx.width;
    length = ((step * mtv_player_p->setting.vol_level) >> 4);

    /* Bar: foreground */
    #if defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__)
    gdi_image_draw_resized(
            osd_p->vol_bar.offset_x - origin_x,
            osd_p->vol_bar.offset_y - origin_y,
            length + osd_p->vol_idx.width / 2,
            osd_p->vol_bar.height,
            (PU8)GetImage(IMG_ID_MTV_PLAYER_VOL_BAR_FULL));
    #else
    gdi_layer_set_clip(
        osd_p->vol_bar.offset_x - origin_x,
        osd_p->vol_bar.offset_y - origin_y,
        osd_p->vol_bar.offset_x - origin_x + length,
        osd_p->vol_bar.offset_y - origin_y + osd_p->vol_bar.width);
    gdi_image_draw_id(
            osd_p->vol_bar.offset_x - origin_x,
            osd_p->vol_bar.offset_y - origin_y,
            IMG_ID_MTV_PLAYER_VOL_BAR_FULL);
    gdi_layer_reset_clip();
    #endif
    /* index */
    osd_p->vol_idx.offset_x = osd_p->vol_bar.offset_x + length;
    #if defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__)
    if(mtv_player_p->touch_object == MTV_PLAYER_TOUCH_VOL_IDX && mtv_player_p->is_key_pressed)
    {
        gdi_image_draw_id(
            osd_p->vol_idx.offset_x - origin_x,
            osd_p->vol_idx.offset_y - origin_y,
            IMG_ID_MTV_PLAYER_VOL_INDEX_DOWN);
    }
    else
    {
        gdi_image_draw_id(
            osd_p->vol_idx.offset_x - origin_x,
            osd_p->vol_idx.offset_y - origin_y,
            IMG_ID_MTV_PLAYER_VOL_INDEX_UP);
    }
 
    #else
    if(mtv_player_p->touch_object == MTV_PLAYER_TOUCH_VOL_IDX && mtv_player_p->is_key_pressed)
    {
        if(mtv_player_p->setting.vol_level == MTV_PLAYER_VOL_MUTE)
        {
            gdi_image_draw_id(
                osd_p->vol_idx.offset_x - origin_x,
                osd_p->vol_idx.offset_y - origin_y,
                IMG_ID_MTV_PLAYER_VOL_INDEX_DOWN_L);
        }
        else if(mtv_player_p->setting.vol_level == MTV_PLAYER_VOL_16)
        {
            gdi_image_draw_id(
                osd_p->vol_idx.offset_x - origin_x,
                osd_p->vol_idx.offset_y - origin_y,
                IMG_ID_MTV_PLAYER_VOL_INDEX_DOWN_R);
        }
        else
        {
            gdi_image_draw_id(
                osd_p->vol_idx.offset_x - origin_x,
                osd_p->vol_idx.offset_y - origin_y,
                IMG_ID_MTV_PLAYER_VOL_INDEX_DOWN_M);
        }
    }
    else   
    {
        if(mtv_player_p->setting.vol_level == MTV_PLAYER_VOL_MUTE)
        {
            gdi_image_draw_id(
                osd_p->vol_idx.offset_x - origin_x,
                osd_p->vol_idx.offset_y - origin_y,
                IMG_ID_MTV_PLAYER_VOL_INDEX_UP_L);
        }
        else if(mtv_player_p->setting.vol_level == MTV_PLAYER_VOL_16)
        {
            gdi_image_draw_id(
                osd_p->vol_idx.offset_x - origin_x,
                osd_p->vol_idx.offset_y - origin_y,
                IMG_ID_MTV_PLAYER_VOL_INDEX_UP_R);
        }
        else
        {
            gdi_image_draw_id(
                osd_p->vol_idx.offset_x - origin_x,
                osd_p->vol_idx.offset_y - origin_y,
                IMG_ID_MTV_PLAYER_VOL_INDEX_UP_M);
        }
    }
    #endif
    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();
    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
}
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_ATV_OSD_SUPPORT__) */

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_draw_osd_channel_num
 * DESCRIPTION
 *  mobile tv player draw osd channel num
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_draw_osd_channel_num(void)
{
#if defined(__MMI_ATV_OSD_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 tmp_digit;
    S16 tmp_channel_number;
    S16 position_x;
    mtv_player_service_info_struct *info_ptr;
    U16 base_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    info_ptr = mmi_mtv_player_get_active_channel_ptr();

    /* Channel number */
    position_x = mtv_player_p->active_osd_cntx_p->channel_number.offset_x;
    if (mtv_player_p->is_changing_channel_by_key == MMI_TRUE)
    {
        tmp_channel_number = mtv_player_p->change_to_channel;
    }
    else if (mtv_player_p->touch_object == MTV_PLAYER_TOUCH_CHANNEL_PREV ||
             mtv_player_p->touch_object == MTV_PLAYER_TOUCH_CHANNEL_NEXT)
    {
        info_ptr = &mtv_player_p->services[mtv_player_p->temporal_channel];
        tmp_channel_number = info_ptr->service_number;
    }
    else
    {
        tmp_channel_number = info_ptr->service_number;
    }

    base_id = IMG_ID_MTV_PLAYER_NUM_0;
#if ((LCD_WIDTH == 320) && (LCD_HEIGHT == 240))
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        base_id = IMG_ID_MTV_PLAYER_NUM_0_H;
    }
#endif /* ((LCD_WIDTH == 320) && (LCD_HEIGHT == 240)) */

    do
    {
        tmp_digit = tmp_channel_number % 10;
        tmp_channel_number = tmp_channel_number / 10;

        gdi_image_draw_id(
            position_x,
            mtv_player_p->active_osd_cntx_p->channel_number.offset_y,
            (U16) (base_id + tmp_digit));
        #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MTV_FTE2_LAYOUT__)
        position_x = position_x - mtv_player_p->active_osd_cntx_p->channel_number.width - 3;
        #else
        position_x = position_x - mtv_player_p->active_osd_cntx_p->channel_number.width;
        #endif
    } while (tmp_channel_number > 0);

#endif /* #if defined(__MMI_ATV_OSD_SUPPORT__)  */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_draw_osd_record_snapshot
 * DESCRIPTION
 *  mobile tv player draw osd record snapshot
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_draw_osd_record_snapshot(void)
{
#if defined(__MMI_ATV_OSD_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset = 0;
#if !defined(__MMI_MTV_RECORD_SUPPORT__) && defined(__MMI_MTV_SNAPSHOT_SUPPORT__)
    S32 offset_3 = 0;
#endif
    U16 img_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        offset = 0;
    #if !defined(__MMI_MTV_RECORD_SUPPORT__) && defined(__MMI_MTV_SNAPSHOT_SUPPORT__)
        offset_3 = 0;
    #endif
    }
    else if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
     #if defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__)
        offset = 0;
     #else
        offset = 2;
     #endif
    #if !defined(__MMI_MTV_RECORD_SUPPORT__) && defined(__MMI_MTV_SNAPSHOT_SUPPORT__)
       #if defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__)
        offset_3 = 0;
       #else
        offset_3 = 3;
    #endif
    #endif
    }

#if defined(__MMI_MTV_RECORD_SUPPORT__)
    /* record icon */
    if (RECORDER_STATE_IN(MTV_RECORDER_RECORD))
    {
        img_id = IMG_ID_MTV_PLAYER_RECORD_PAUSE_UP;
    }
    else
    {
        img_id = IMG_ID_MTV_PLAYER_RECORD_UP;
        if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        {
            #if defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__)
            offset = 0;
            #else            
            offset = 3;
            #endif
        }
    }

    if(mtv_player_p->active_osd_cntx_p->record.status == MTV_PLAYER_ICON_STATUS_ENABLE)
    {
        gdi_image_draw_id(mtv_player_p->active_osd_cntx_p->record.offset_x,mtv_player_p->active_osd_cntx_p->record.offset_y,(U16)(img_id+offset));
    }
    else if(mtv_player_p->active_osd_cntx_p->record.status == MTV_PLAYER_ICON_STATUS_CLICKED )
    {
        #if defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__)
        gdi_image_draw_id(mtv_player_p->active_osd_cntx_p->record.offset_x,mtv_player_p->active_osd_cntx_p->record.offset_y,(U16)(img_id+offset));
        gdi_image_draw_id(mtv_player_p->active_osd_cntx_p->record.offset_x,mtv_player_p->active_osd_cntx_p->record.offset_y,(U16)(IMG_ID_MTV_PLAYER_PRESS_HIGHT));
        #else
        gdi_image_draw_id(mtv_player_p->active_osd_cntx_p->record.offset_x,mtv_player_p->active_osd_cntx_p->record.offset_y,(U16)(img_id+offset+1));
        #endif
    }
    else if(mtv_player_p->active_osd_cntx_p->record.status == MTV_PLAYER_ICON_STATUS_DISABLE)
    {
        #if defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__)
        gdi_image_draw_id(mtv_player_p->active_osd_cntx_p->record.offset_x,mtv_player_p->active_osd_cntx_p->record.offset_y,(U16)(img_id+offset+1));
        #else
        gdi_image_draw_id(mtv_player_p->active_osd_cntx_p->record.offset_x,mtv_player_p->active_osd_cntx_p->record.offset_y,(U16)(img_id+offset+2));
        #endif
    }

#elif defined(__MMI_MTV_SNAPSHOT_SUPPORT__)

    img_id = IMG_ID_MTV_PLAYER_SNAPSHOT_UP;
    if(mtv_player_p->active_osd_cntx_p->record.status == MTV_PLAYER_ICON_STATUS_ENABLE)
    {
        gdi_image_draw_id(mtv_player_p->active_osd_cntx_p->record.offset_x,mtv_player_p->active_osd_cntx_p->record.offset_y,(U16)(img_id+offset_3));
    }
    else if(mtv_player_p->active_osd_cntx_p->record.status == MTV_PLAYER_ICON_STATUS_CLICKED)
    {
        #if defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__)
            gdi_image_draw_id(mtv_player_p->active_osd_cntx_p->record.offset_x,mtv_player_p->active_osd_cntx_p->record.offset_y,(U16)(img_id+offset_3));
            gdi_image_draw_id(mtv_player_p->active_osd_cntx_p->record.offset_x,mtv_player_p->active_osd_cntx_p->record.offset_y,(U16)(IMG_ID_MTV_PLAYER_PRESS_HIGHT));
        #else
        gdi_image_draw_id(mtv_player_p->active_osd_cntx_p->record.offset_x,mtv_player_p->active_osd_cntx_p->record.offset_y,(U16)(img_id+offset_3+1));
        #endif
    }
    else if(mtv_player_p->active_osd_cntx_p->record.status == MTV_PLAYER_ICON_STATUS_DISABLE)
    {
        #if defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__)
        gdi_image_draw_id(mtv_player_p->active_osd_cntx_p->record.offset_x,mtv_player_p->active_osd_cntx_p->record.offset_y,(U16)(img_id+offset_3+1));
        #else
        gdi_image_draw_id(mtv_player_p->active_osd_cntx_p->record.offset_x,mtv_player_p->active_osd_cntx_p->record.offset_y,(U16)(img_id+offset_3+2));
        #endif
    }

#endif /* __MMI_MTV_SNAPSHOT_SUPPORT__ */
#endif /* #if defined(__MMI_ATV_OSD_SUPPORT__)  */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_draw_hint_animation
 * DESCRIPTION
 *  mobile tv player draw hint animation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_draw_hint_animation(void)
{
#if defined(__MMI_ATV_OSD_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 bt_y;
    S32 width, height, x;
    S32 total_width;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        total_width = LCD_WIDTH;
        bt_y = MMI_MTV_PLAYER_BT_CONNECT_ICON_Y;
    }
    else
    {
        total_width = LCD_HEIGHT;
        bt_y = MMI_MTV_PLAYER_FULL_SCR_BT_CONNECT_ICON_Y;
    }

    if (PLAYER_STATE_IN(MTV_PLAYER_BT_CONNECT))
    {
        /* Check if BT animation could be drawn */
        if (!IsMyTimerExist(MTV_PLAYER_BT_ANIMATION_TIMER))
        {
            gdi_image_get_dimension(
                (U8*)GetImage(IMG_ID_MOBILE_TV_BT_CONNECT), &width, &height);
            x = ((total_width - width)>>1);
            mmi_mtv_player_draw_animation(
                x, bt_y, width, height, IMG_ID_MOBILE_TV_BT_CONNECT,
                &mtv_player_p->bt_connect_amin_handle);
        }
    }
#endif /* __MMI_ATV_OSD_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_draw_osd
 * DESCRIPTION
 *  mobile tv player draw osd handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_draw_osd(void)
{
#if defined(__MMI_ATV_OSD_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifndef GDI_USING_2D_ENGINE_V3
    PU8 dest;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        gdi_layer_push_and_set_active(mtv_player_p->osd_layer_handle);
    #if !defined(GDI_2_LAYERS) && !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
        gdi_layer_toggle_double();
    #endif /* GDI_2_LAYERS && !(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__) */
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);

		gdi_push_and_set_alpha_blending_source_layer(mtv_player_p->osd_layer_handle);

        gdi_image_draw_id(
            MMI_MTV_PLAYER_BG_OFFSET_X,
            MMI_MTV_PLAYER_BG_OFFSET_Y,
            IMG_ID_MOBILE_TV_PLAYER_BG);

    }
    else if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
    #if defined(__MDI_MTV_HW_ROTATOR_SUPPORT__) && !defined(__MMI_MTV_LANDSCAPE_SUPPORT__)
        gdi_layer_push_and_set_active(mtv_player_p->osd_drawing_layer_handle);
        gdi_push_and_set_alpha_blending_source_layer(mtv_player_p->osd_drawing_layer_handle);
    #else /* __MDI_MTV_HW_ROTATOR_SUPPORT__ && !__MMI_MTV_LANDSCAPE_SUPPORT__ */
        gdi_layer_push_and_set_active(mtv_player_p->osd_layer_handle);
        gdi_push_and_set_alpha_blending_source_layer(mtv_player_p->osd_layer_handle);

    #if !defined(GDI_2_LAYERS) && !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
        gdi_layer_toggle_double();
    #endif /* GDI_2_LAYERS && !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__) */
    #endif /* __MDI_MTV_HW_ROTATOR_SUPPORT__ && !__MMI_MTV_LANDSCAPE_SUPPORT__ */
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_image_draw_id(
            MMI_MTV_PLAYER_FULL_SCR_BG_OFFSET_X,
            MMI_MTV_PLAYER_FULL_SCR_BG_OFFSET_Y,
            IMG_ID_MOBILE_TV_PLAYER_BG_H);
    }

    /* hint animation */
    mmi_mtv_player_draw_hint_animation();

    /* soft key */
    mmi_mtv_player_draw_osd_softkey();

    /* Channel information */
    mmi_mtv_player_draw_osd_channel_num();
    /* Fullscreen, Channel_Prev, Channel_Next */
    mmi_mtv_player_draw_osd_other();

    /* Volume */
#if !defined(__MMI_FTE_SUPPORT__) ||(defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MTV_FTE2_LAYOUT__))
    mmi_mtv_player_draw_osd_volume_status();
#if defined(__MMI_MTV_LANDSCAPE_SUPPORT__) && !defined(__MMI_FTE_SUPPORT__)
    mmi_mtv_player_draw_osd_vol_inc_dec_icon();
#endif
#endif /* !defined(__MMI_FTE_SUPPORT__) */

    /* Hint */
    if (mtv_player_p->hint_state != MTV_PLAYER_HINT_STATE_HIDE)
    {
        mmi_mtv_player_draw_hint();
    }

#if defined(__MMI_MTV_RECORD_SUPPORT__) || defined(__MMI_MTV_SNAPSHOT_SUPPORT__)
    mmi_mtv_player_draw_osd_record_snapshot();
#endif /* __MMI_MTV_RECORD_SUPPORT__ || __MMI_MTV_SNAPSHOT_SUPPORT__ */

    gdi_layer_pop_and_restore_active();
    gdi_pop_and_restore_alpha_blending_source_layer();

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MTV_FTE2_LAYOUT__)
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        gdi_layer_push_and_set_active(mtv_player_p->osd_layer_handle);
        gdi_layer_set_opacity(MMI_TRUE, 229);
        gdi_layer_pop_and_restore_active();
    }
    else
    {
        gdi_layer_push_and_set_active(mtv_player_p->osd_layer_handle);
        gdi_layer_set_opacity(MMI_TRUE, 255);
        gdi_layer_pop_and_restore_active();
    }
#endif

    /* Draw signal icon after pop_and_restore_active() */
#if defined(GDI_2_LAYERS)
    mmi_mtv_player_draw_signal_icon();
#endif /* GDI_2_LAYERS */

#if defined(__MDI_MTV_HW_ROTATOR_SUPPORT__) && !defined(__MMI_MTV_LANDSCAPE_SUPPORT__)

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        gdi_layer_push_and_set_active(mtv_player_p->osd_layer_handle);
    #if !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
        gdi_layer_toggle_double();
    #endif
    #if defined(GDI_USING_2D_ENGINE_V3)
        gdi_2d_begin();
        gdi_2d_set_layer_as_dest_buffer(mtv_player_p->osd_layer_handle);
        gdi_2d_set_layer_as_src_bitblt_buffer(mtv_player_p->osd_drawing_layer_handle);
        gdi_2d_rotate(GDI_TRANSFORM_ROTATE_90);
        gdi_2d_end();
    #else
        gdi_layer_get_buffer_ptr(&dest);
        /* toggle double buffer */
        mmi_mtv_player_sw_rotate(
            dest,
            mtv_player_p->osd_drawing_layer_buf_ptr,
            (U32) LCD_HEIGHT,
            (U32) LCD_WIDTH);
    #endif
        gdi_layer_pop_and_restore_active();
    }
#endif /* __MDI_MTV_HW_ROTATOR_SUPPORT__ && !__MMI_MTV_LANDSCAPE_SUPPORT__ */
#endif /* defined(__MMI_ATV_OSD_SUPPORT__) */
}

static MMI_RET post_enter_main(mmi_event_struct *evt)
{
    mmi_mtv_player_enter_app_main();
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_app_mem_success_callback
 * DESCRIPTION
 *  mobile tv player app mem callback function, it is called after
 *  succeed allocating memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_app_mem_success_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->app_mem_pool
        = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_MTV_PLAYER, MMI_MTV_PLAYER_APP_MEM_SIZE);

    /* It should provide enough memory */
    ASSERT(mtv_player_p->app_mem_pool != NULL);
    MMI_FRM_INIT_EVENT(&evt, 0);
    MMI_FRM_POST_EVENT(&evt, post_enter_main, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_create_adm
 * DESCRIPTION
 *  Delete ADM memory pool and free memory allocated from ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_create_adm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Create MemoryPool */
    if (mtv_player_p->app_mem_pool != NULL && mtv_player_p->adm_pool_id == NULL)
    {
        mtv_player_p->adm_pool_id = kal_adm_create((void*)mtv_player_p->app_mem_pool,
                                                    MMI_MTV_PLAYER_APP_MEM_SIZE,
                                                    NULL,
                                                    KAL_FALSE);
        ASSERT(mtv_player_p->adm_pool_id != NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_delete_adm
 * DESCRIPTION
 *  Delete ADM memory pool and free memory allocated from ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_delete_adm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_status ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Delete ADM */
    if (mtv_player_p->adm_pool_id)
    {
        ret = kal_adm_delete(mtv_player_p->adm_pool_id);

        ASSERT(ret == KAL_SUCCESS);
        mtv_player_p->adm_pool_id = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_alloc_adm_structure
 * DESCRIPTION
 *  Delete ADM memory pool and free memory allocated from ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_alloc_adm_structure(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* services */
    ASSERT(sizeof(mtv_player_service_info_struct) <= MMI_MTV_MAX_SERVICE_INFO_STRUCTURE_SIZE);
    if (mtv_player_p->services == NULL)
    {
        mtv_player_p->services = (mtv_player_service_info_struct*) kal_adm_alloc(
                                    mtv_player_p->adm_pool_id,
                                    MMI_MTV_MAX_SERVICES * sizeof(mtv_player_service_info_struct));
        ASSERT(mtv_player_p->services != NULL);
        memset(mtv_player_p->services, 0, MMI_MTV_MAX_SERVICES * sizeof(mtv_player_service_info_struct));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_free_adm_structure
 * DESCRIPTION
 *  Delete ADM memory pool and free memory allocated from ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_free_adm_structure(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* services */
    if (mtv_player_p->services != NULL)
    {
        kal_adm_free(mtv_player_p->adm_pool_id,(void *) mtv_player_p->services);
        mtv_player_p->services = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_alloc_adm_layer
 * DESCRIPTION
 *  Delete ADM memory pool and free memory allocated from ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_alloc_adm_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* display layer: from gdi layer buffer */
    result = gdi_layer_create(
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT,
        &mtv_player_p->display_layer_handle);
    ASSERT (result != GDI_FAILED);

    gdi_layer_push_and_set_active(mtv_player_p->display_layer_handle);
    gdi_layer_set_background(GDI_COLOR_BLACK);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
#if defined(__MMI_ATV_OSD_SUPPORT__)
#ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
     /* osd layer: single buffer */
    mtv_player_p->osd_layer_buf_ptr_2 =
            (PU8) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(mtv_player_p->adm_pool_id, MMI_MTV_PLAYER_OSD_BUFFER_SIZE);
#endif /* __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ */

#if !defined(GDI_2_LAYERS)
    /* create status bar layer */
#ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    mtv_player_p->status_bar_buf_ptr =
                (PU8) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(mtv_player_p->adm_pool_id, MMI_MTV_PLAYER_STATUS_BAR_BUFFER_SIZE*3);
#else /* __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ */
    mtv_player_p->status_bar_buf_ptr =
                (PU8) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(mtv_player_p->adm_pool_id, MMI_MTV_PLAYER_STATUS_BAR_BUFFER_SIZE);
#endif /* __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ */
    ASSERT(mtv_player_p->status_bar_buf_ptr != NULL);

    gdi_layer_create_using_outside_memory(
        0,
        0,
        LCD_WIDTH,
        MMI_STATUS_BAR_HEIGHT,
        &mtv_player_p->status_bar_layer_handle,
        mtv_player_p->status_bar_buf_ptr,
        MMI_MTV_PLAYER_STATUS_BAR_BUFFER_SIZE);

#ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    gdi_bltdb_set_blt_buffer(
        mtv_player_p->status_bar_layer_handle,
        mtv_player_p->status_bar_buf_ptr + MMI_MTV_PLAYER_STATUS_BAR_BUFFER_SIZE,
        MMI_MTV_PLAYER_STATUS_BAR_BUFFER_SIZE,
        mtv_player_p->status_bar_buf_ptr + 2* MMI_MTV_PLAYER_STATUS_BAR_BUFFER_SIZE,
        MMI_MTV_PLAYER_STATUS_BAR_BUFFER_SIZE);
#endif /* __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ */

    gdi_layer_push_and_set_active(mtv_player_p->status_bar_layer_handle);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    wgui_status_icon_bar_set_target_layer(
        WGUI_STATUS_ICON_BAR_H_BAR, mtv_player_p->status_bar_layer_handle);

    /* dls layer */
#ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    mtv_player_p->dls_layer_buf_ptr =
            (PU8) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(mtv_player_p->adm_pool_id, MMI_MTV_PLAYER_DLS_BUFFER_SIZE*3);
#else /* __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ */
    mtv_player_p->dls_layer_buf_ptr =
            (PU8) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(mtv_player_p->adm_pool_id, MMI_MTV_PLAYER_DLS_BUFFER_SIZE*2);
#endif  /* __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ */
    ASSERT(mtv_player_p->dls_layer_buf_ptr != NULL);

#ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    gdi_layer_create_using_outside_memory(
        0,
        0,
        MTV_PLAYER_DLS_BUFFER_WIDTH,
        MTV_PLAYER_DLS_BUFFER_HEIGHT,
        &mtv_player_p->dls_layer_handle,
        (PU8) mtv_player_p->dls_layer_buf_ptr,
        (S32) MMI_MTV_PLAYER_DLS_BUFFER_SIZE);
    gdi_bltdb_set_blt_buffer(
        mtv_player_p->dls_layer_handle,
        mtv_player_p->dls_layer_buf_ptr + MMI_MTV_PLAYER_DLS_BUFFER_SIZE,
        MMI_MTV_PLAYER_DLS_BUFFER_SIZE,
        mtv_player_p->dls_layer_buf_ptr + 2* MMI_MTV_PLAYER_DLS_BUFFER_SIZE,
        MMI_MTV_PLAYER_DLS_BUFFER_SIZE);
#else /* __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ */
    gdi_layer_create_double_using_outside_memory(
        0,
        0,
        MTV_PLAYER_DLS_BUFFER_WIDTH,
        MTV_PLAYER_DLS_BUFFER_HEIGHT,
        &mtv_player_p->dls_layer_handle,
        (PU8) mtv_player_p->dls_layer_buf_ptr,
        (S32) MMI_MTV_PLAYER_DLS_BUFFER_SIZE*2);
#endif /* __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ */


#if defined(__MMI_FTE_SUPPORT__)
    /* volume layer */
#ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    mtv_player_p->vol_layer_buf_ptr =
            (PU8) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(mtv_player_p->adm_pool_id, MTV_PLAYER_VOL_BUFFER_SIZE*3);
#else
    mtv_player_p->vol_layer_buf_ptr =
            (PU8) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(mtv_player_p->adm_pool_id, MTV_PLAYER_VOL_BUFFER_SIZE*2);
#endif

    ASSERT(mtv_player_p->vol_layer_buf_ptr != NULL);
#ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    gdi_layer_create_cf_using_outside_memory(
        GDI_COLOR_FORMAT_32,
        0,
        0,
        MTV_PLAYER_VOL_BUFFER_WIDTH,
        MTV_PLAYER_VOL_BUFFER_HEIGHT,
        &mtv_player_p->vol_layer_handle,
        (PU8) mtv_player_p->vol_layer_buf_ptr,
        (S32) MTV_PLAYER_VOL_BUFFER_SIZE);
    gdi_bltdb_set_blt_buffer(
        mtv_player_p->vol_layer_handle,
        mtv_player_p->vol_layer_buf_ptr + MTV_PLAYER_VOL_BUFFER_SIZE,
        MTV_PLAYER_VOL_BUFFER_SIZE,
        mtv_player_p->vol_layer_buf_ptr + 2* MTV_PLAYER_VOL_BUFFER_SIZE,
        MTV_PLAYER_VOL_BUFFER_SIZE);
#else

    gdi_layer_create_cf_double_using_outside_memory(
        GDI_COLOR_FORMAT_32,
        0,
        0,
        MTV_PLAYER_VOL_BUFFER_WIDTH,
        MTV_PLAYER_VOL_BUFFER_HEIGHT,
        &mtv_player_p->vol_layer_handle,
        (PU8) mtv_player_p->vol_layer_buf_ptr,
        (S32) MTV_PLAYER_VOL_BUFFER_SIZE,
        (PU8) (mtv_player_p->vol_layer_buf_ptr + MTV_PLAYER_VOL_BUFFER_SIZE),
        (S32) MTV_PLAYER_VOL_BUFFER_SIZE);
#endif
#endif /* defined(__MMI_FTE_SUPPORT__) */

#if defined(__MDI_MTV_HW_ROTATOR_SUPPORT__) && !defined(__MMI_MTV_LANDSCAPE_SUPPORT__)
    /* dls drawing layer */
    mtv_player_p->dls_drawing_layer_buf_ptr =
        (PU8) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(mtv_player_p->adm_pool_id, MMI_MTV_PLAYER_DLS_DRAWING_BUFFER_SIZE);
    ASSERT(mtv_player_p->dls_drawing_layer_buf_ptr != NULL);

    if(mtv_player_p->dls_drawing_layer_handle == GDI_LAYER_EMPTY_HANDLE)
    {
        result = gdi_layer_create_using_outside_memory(
            0,
            0,
            MTV_PLAYER_DLS_BUFFER_WIDTH,
            MTV_PLAYER_DLS_BUFFER_HEIGHT,
            &mtv_player_p->dls_drawing_layer_handle,
            (PU8) mtv_player_p->dls_drawing_layer_buf_ptr,
            MMI_MTV_PLAYER_DLS_DRAWING_BUFFER_SIZE);

        ASSERT (result != GDI_FAILED);

        gdi_layer_push_and_set_active(mtv_player_p->dls_drawing_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }

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
    #endif
#endif /* __MDI_MTV_HW_ROTATOR_SUPPORT__ && !__MMI_MTV_LANDSCAPE_SUPPORT__ */
#endif /* GDI_2_LAYERS */
#endif /* defined(__MMI_ATV_OSD_SUPPORT__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_free_adm_layer
 * DESCRIPTION
 *  callback function used by applib to free APP-Based Memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_free_adm_layer(void)
{
#if defined(__MMI_ATV_OSD_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    if (mtv_player_p->osd_layer_buf_ptr_2 != NULL)
    {
        kal_adm_free(mtv_player_p->adm_pool_id, (void*)mtv_player_p->osd_layer_buf_ptr_2);
        mtv_player_p->osd_layer_buf_ptr_2 = NULL;
    }
#endif

#if !defined(GDI_2_LAYERS)
    /* free status bar layer */
    wgui_status_icon_bar_reset_alpha_blend_layer(WGUI_STATUS_ICON_BAR_H_BAR);

    if (mtv_player_p->status_bar_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        /* Reset status bar layer config */
        wgui_status_icon_bar_set_target_layer(
            WGUI_STATUS_ICON_BAR_H_BAR, GDI_ERROR_HANDLE);

        gdi_layer_free(mtv_player_p->status_bar_layer_handle);
        mtv_player_p->status_bar_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    if (mtv_player_p->status_bar_buf_ptr != NULL)
    {
        kal_adm_free(mtv_player_p->adm_pool_id, (void*)mtv_player_p->status_bar_buf_ptr);
        mtv_player_p->status_bar_buf_ptr = NULL;
    }

    /* free dls layer resource */
    if (mtv_player_p->dls_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(mtv_player_p->dls_layer_handle);
        mtv_player_p->dls_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    if (mtv_player_p->dls_layer_buf_ptr != NULL)
    {
        kal_adm_free(mtv_player_p->adm_pool_id, (void*)mtv_player_p->dls_layer_buf_ptr);
        mtv_player_p->dls_layer_buf_ptr = NULL;
    }

#if defined(__MMI_FTE_SUPPORT__)
    /* free volume layer resource */
    if (mtv_player_p->vol_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(mtv_player_p->vol_layer_handle);
        mtv_player_p->vol_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    if (mtv_player_p->vol_layer_buf_ptr != NULL)
    {
        kal_adm_free(mtv_player_p->adm_pool_id, (void*)mtv_player_p->vol_layer_buf_ptr);
        mtv_player_p->vol_layer_buf_ptr = NULL;
    }
#endif /* defined(__MMI_FTE_SUPPORT__) */
#if defined(__MDI_MTV_HW_ROTATOR_SUPPORT__) && !defined(__MMI_MTV_LANDSCAPE_SUPPORT__)
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
    #endif

    /* free dls drawing layer resource */
    if (mtv_player_p->dls_drawing_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(mtv_player_p->dls_drawing_layer_handle);
        mtv_player_p->dls_drawing_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    if (mtv_player_p->dls_drawing_layer_buf_ptr != NULL)
    {
        kal_adm_free(mtv_player_p->adm_pool_id, (void*)mtv_player_p->dls_drawing_layer_buf_ptr);
        mtv_player_p->dls_drawing_layer_buf_ptr = NULL;
    }
#endif /* __MDI_MTV_HW_ROTATOR_SUPPORT__) && !__MMI_MTV_LANDSCAPE_SUPPORT__) */
#endif /* !defined(GDI_2_LAYERS) */
#endif /* defined(__MMI_ATV_OSD_SUPPORT__) */

    /* Display layer handle */
    if (mtv_player_p->display_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(mtv_player_p->display_layer_handle);
        mtv_player_p->display_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_alloc_resource
 * DESCRIPTION
 *  this function creates scr-based resource for mtv player
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_alloc_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_ATV_OSD_SUPPORT__)
#if defined(GDI_2_LAYERS)
    /* osd layer: single buffer */
#ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    mtv_player_p->osd_layer_buf_ptr =
            (PU8) applib_mem_screen_alloc_framebuffer(MMI_MTV_PLAYER_OSD_BUFFER_SIZE*2);
#else /* __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ */
    mtv_player_p->osd_layer_buf_ptr =
            (PU8) applib_mem_screen_alloc_framebuffer(MMI_MTV_PLAYER_OSD_BUFFER_SIZE);
#endif /* __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ */
    ASSERT(mtv_player_p->osd_layer_buf_ptr != NULL);

    gdi_layer_create_using_outside_memory(
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT,
        &mtv_player_p->osd_layer_handle,
        (PU8) mtv_player_p->osd_layer_buf_ptr,
        (S32) (MMI_MTV_PLAYER_OSD_BUFFER_SIZE));

#ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    gdi_bltdb_set_blt_buffer(
        mtv_player_p->osd_layer_handle,
        mtv_player_p->osd_layer_buf_ptr + MMI_MTV_PLAYER_OSD_BUFFER_SIZE,
        MMI_MTV_PLAYER_OSD_BUFFER_SIZE,
        mtv_player_p->osd_layer_buf_ptr_2, /* From ASM */
        MMI_MTV_PLAYER_OSD_BUFFER_SIZE);
#endif /* __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ */

    wgui_status_icon_bar_set_target_layer(
            WGUI_STATUS_ICON_BAR_H_BAR, mtv_player_p->osd_layer_handle);
#else  /* GDI_2_LAYERS */
    /* osd layer: double buffer */
    mtv_player_p->osd_layer_buf_ptr =
        (PU8) applib_mem_screen_alloc_framebuffer(MMI_MTV_PLAYER_OSD_BUFFER_SIZE*2);

    ASSERT(mtv_player_p->osd_layer_buf_ptr != NULL);

#ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    gdi_layer_create_using_outside_memory(
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT,
        &mtv_player_p->osd_layer_handle,
        (PU8) mtv_player_p->osd_layer_buf_ptr,
        (S32) (MMI_MTV_PLAYER_OSD_BUFFER_SIZE));
    gdi_bltdb_set_blt_buffer(
        mtv_player_p->osd_layer_handle,
        mtv_player_p->osd_layer_buf_ptr + MMI_MTV_PLAYER_OSD_BUFFER_SIZE,
        MMI_MTV_PLAYER_OSD_BUFFER_SIZE,
        mtv_player_p->osd_layer_buf_ptr_2,  /* From ASM */
        MMI_MTV_PLAYER_OSD_BUFFER_SIZE);
#else /* __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ */
    gdi_layer_create_double_using_outside_memory(
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT,
        &mtv_player_p->osd_layer_handle,
        (PU8) mtv_player_p->osd_layer_buf_ptr,
        (S32) (MMI_MTV_PLAYER_OSD_BUFFER_SIZE*2));
#endif /* __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ */
#endif  /* GDI_2_LAYERS */
#endif /* (__MMI_ATV_OSD_SUPPORT__) */
    /* display layer: from base layer buffer */
    if (mtv_player_p->display_layer_handle == GDI_LAYER_EMPTY_HANDLE)
    {
        result = gdi_layer_create(
            0,
            0,
            LCD_WIDTH,
            LCD_HEIGHT,
            &mtv_player_p->display_layer_handle);

        ASSERT (result != GDI_FAILED);

        gdi_layer_push_and_set_active(mtv_player_p->display_layer_handle);
        gdi_layer_set_background(GDI_COLOR_BLACK);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }

    mmi_mtv_player_config_layers();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_free_resource
 * DESCRIPTION
 *  this function frees scr-based resource for mtv player
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_free_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_ATV_OSD_SUPPORT__)
#if defined(GDI_2_LAYERS)

    /* Reset status bar layer config */
    wgui_status_icon_bar_set_target_layer(
        WGUI_STATUS_ICON_BAR_H_BAR, GDI_ERROR_HANDLE);
#endif

    /* OSD layer */
    if (mtv_player_p->osd_layer_buf_ptr != NULL)
    {
        mmi_frm_scrmem_free((void *) mtv_player_p->osd_layer_buf_ptr);
        mtv_player_p->osd_layer_buf_ptr = NULL;
    }

    if (mtv_player_p->osd_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(mtv_player_p->osd_layer_handle);
        mtv_player_p->osd_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }
#endif /* defined(__MMI_ATV_OSD_SUPPORT__) */
    /* Display layer handle */
    if (mtv_player_p->display_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(mtv_player_p->display_layer_handle);
        mtv_player_p->display_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_alloc_base_layer
 * DESCRIPTION
 *  Delete ADM memory pool and free memory allocated from ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_alloc_base_layer(void)
{
#if defined(__MMI_ATV_OSD_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if !defined(GDI_2_LAYERS)
#if defined(__MDI_MTV_HW_ROTATOR_SUPPORT__) && !defined(__MMI_MTV_LANDSCAPE_SUPPORT__)

    /* osd drawing layer */
    gdi_layer_get_base_handle(&mtv_player_p->osd_drawing_layer_handle);
    gdi_layer_push_and_set_active(mtv_player_p->osd_drawing_layer_handle);

    gdi_layer_get_buffer_ptr(&mtv_player_p->osd_drawing_layer_buf_ptr);
    gdi_layer_get_source_key(
        &mtv_player_p->source_key_enable,
        &mtv_player_p->source_key_value);
    gdi_layer_get_dimension(
        &mtv_player_p->base_layer_width,
        &mtv_player_p->base_layer_height);

    gdi_layer_resize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();

#endif /* __MDI_MTV_HW_ROTATOR_SUPPORT__ && !__MMI_MTV_LANDSCAPE_SUPPORT__ */
#endif /* GDI_2_LAYERS */
#endif /* defined(__MMI_ATV_OSD_SUPPORT__) */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_free_base_layer
 * DESCRIPTION
 *  Delete ADM memory pool and free memory allocated from ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_free_base_layer(void)
{
#if defined(__MMI_ATV_OSD_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if !defined(GDI_2_LAYERS)
#if defined(__MDI_MTV_HW_ROTATOR_SUPPORT__) && !defined(__MMI_MTV_LANDSCAPE_SUPPORT__)

    /* osd drawing layer */
    gdi_layer_push_and_set_active(mtv_player_p->osd_drawing_layer_handle);
    gdi_layer_set_source_key(
        mtv_player_p->source_key_enable,
        mtv_player_p->source_key_value);
    gdi_layer_resize(
        mtv_player_p->base_layer_width,
        mtv_player_p->base_layer_height);
    gdi_layer_pop_and_restore_active();

    mtv_player_p->osd_drawing_layer_buf_ptr = NULL;
    mtv_player_p->osd_drawing_layer_handle = GDI_LAYER_EMPTY_HANDLE;
#endif /* __MDI_MTV_HW_ROTATOR_SUPPORT__ && !__MMI_MTV_LANDSCAPE_SUPPORT__ */
#endif /* GDI_2_LAYERS */
#endif /* defined(__MMI_ATV_OSD_SUPPORT__) */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_app_screen_leave_proc
 * DESCRIPTION
 *  delete screen id callback handler of mtv player applications
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 mmi_ret mmi_mtv_player_app_screen_leave_proc(mmi_event_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_MTV_SUCCEED;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (para->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
            /* Avoid auto play */
            if (KERNEL_STATE_IN(MTV_KERNEL_INIT))
            {
                ret = mmi_mtv_player_kernel_enter_state(MTV_KERNEL_OPENED);
                ASSERT(ret == MDI_RES_MTV_SUCCEED);
            }
#ifdef   __MMI_MTV_RECORD_SUPPORT__
            if (RECORDER_STATE_IN(MTV_RECORDER_RECORD) || RECORDER_STATE_IN(MTV_RECORDER_PAUSE))
            {
                /* Only stop recorder. Enter save_confirm screen when entry again */
                mmi_mtv_player_recorder_enter_state(MTV_RECORDER_SAVE_CONFIRM);
            }
            if (RECORDER_STATE_IN(MTV_RECORDER_SAVE_CONFIRM))
            {
                RECORDER_ENTER_STATE(MTV_RECORDER_STOPPED);
            }
#endif

            if (!PLAYER_STATE_IN(MTV_PLAYER_STOPPED))
            {
                mmi_mtv_player_player_enter_state(MTV_PLAYER_STOPPED);
            }
            break;
        }
        default:
            break;
    }
    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_store_setting
 * DESCRIPTION
 *  set mobile tv player settings from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_store_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(
        NVRAM_EF_MOBILE_TV_PLAYER_SETTING_LID,
        1,
        (void*)&(mtv_player_p->setting),
        NVRAM_EF_MOBILE_TV_PLAYER_SETTING_SIZE,
        &error);

}



/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_restore_setting
 * DESCRIPTION
 *  restore mobile tv player default settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_set_hint(CHAR *hint_str1, CHAR *hint_str2, U16 fade_time, MMI_BOOL multiline)
{
#ifdef __MMI_ATV_OSD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wstrcpy((WCHAR *) &mtv_player_p->hint1_buf, L"");
    kal_wstrcpy((WCHAR *) &mtv_player_p->hint2_buf, L"");

    if (hint_str1 != NULL)
    {
        mmi_ucs2ncpy((CHAR*) mtv_player_p->hint1_buf, (CHAR*) hint_str1, MMI_MTV_NAME_STR_LENGTH);
    }

    if (hint_str2 != NULL)
    {
        mmi_ucs2ncpy((CHAR*) mtv_player_p->hint2_buf, (CHAR*) hint_str2, MMI_MTV_NAME_STR_LENGTH);
    }

    if (multiline)
    {
        mtv_player_p->hint_state = MTV_PLAYER_HINT_STATE_SHOW_MULTILINE;
    }
    else
    {
        mtv_player_p->hint_state = MTV_PLAYER_HINT_STATE_SHOW_TRUNCATED;
    }

    mtv_player_p->fade_time = fade_time;
#endif /*  __MMI_ATV_OSD_SUPPORT__   */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_draw_hint
 * DESCRIPTION
 *  draw preview OSD panel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_draw_hint(void)
{
#if defined(__MMI_ATV_OSD_SUPPORT__)
#if !defined(GDI_2_LAYERS)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str1_width;
    S32 str1_height = 0;
    S32 str2_width;
    S32 str2_height;
    S32 str1_offset_x = 0;
    S32 str1_offset_y = 0;
    S32 str2_offset_x = 0;
    S32 str2_offset_y = 0;
    S32 spacing = 5;
    S32 width, height;
    WCHAR *hint_str1;
    WCHAR *hint_str2;
    S32 loc_y;
    U16 img_id = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hint_str1 = mtv_player_p->hint1_buf;
    hint_str2 = mtv_player_p->hint2_buf;

    loc_y = mtv_player_p->active_osd_cntx_p->hint_box.offset_y;
    if (PLAYER_STATE_IN(MTV_PLAYER_BT_CONNECT))
    {
        img_id = IMG_ID_MOBILE_TV_BT_CONNECT;
        gdi_image_get_dimension_id(img_id, &width, &height);
        if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
        {
            loc_y = MMI_MTV_PLAYER_BT_CONNECT_ICON_Y + height + spacing;
        }
        else
        {
            loc_y = MMI_MTV_PLAYER_FULL_SCR_BT_CONNECT_ICON_Y + height + spacing;
        }
    }

    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

#if defined(__MMI_MTV_SMALL_HINT__)
	gui_set_font(&MMI_small_font);
#else
	gui_set_font(&MMI_medium_font);
#endif

    /* disable font alpha */
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_fe_set_antialias(MMI_FALSE);
#endif
    if(hint_str1 != NULL && mmi_ucs2strlen((CHAR *)hint_str1) > 0)
    {
        gui_measure_string((UI_string_type) hint_str1, &str1_width, &str1_height);
        str1_offset_x = (mtv_player_p->active_osd_cntx_p->hint_box.width - str1_width) >> 1;
        str1_offset_y = spacing;

		if (str1_offset_x > 0)
        {
            mmi_mtv_player_draw_style_text(
                (CHAR*)hint_str1,
                mtv_player_p->active_osd_cntx_p->hint_box.offset_x + str1_offset_x,
                loc_y + str1_offset_y);
        }
        /* Hint1 is too long: Multiline or Truncated */
        else
        {
            if (mtv_player_p->hint_state == MTV_PLAYER_HINT_STATE_SHOW_TRUNCATED ||
                mtv_player_p->hint_state == MTV_PLAYER_HINT_STATE_FADING_TRUNCATED)
            {
                mmi_mtv_player_draw_truncated_style_text(
                    (CHAR* )hint_str1,
                    mtv_player_p->active_osd_cntx_p->hint_box.offset_x,
                    loc_y + str1_offset_y,
                    mtv_player_p->active_osd_cntx_p->hint_box.width);
            }
            else /* SHOW_MULTILINE or FADING_MULTILINE */
            {
                mmi_mtv_player_draw_multiline_style_text(
                    (CHAR*)hint_str1,
                    mtv_player_p->active_osd_cntx_p->hint_box.offset_x,
                    loc_y + str1_offset_y,
                    mtv_player_p->active_osd_cntx_p->hint_box.width);
            }
        }
    }

    if(hint_str2 != NULL && mmi_ucs2strlen((CHAR *)hint_str2) > 0)
    {
        gui_measure_string((UI_string_type) hint_str2, &str2_width, &str2_height);

        str2_offset_x = (mtv_player_p->active_osd_cntx_p->hint_box.width - str2_width) >> 1;
        str2_offset_y = str1_offset_y + spacing + str1_height;

		mmi_mtv_player_draw_style_text(
            (CHAR*)hint_str2,
            mtv_player_p->active_osd_cntx_p->hint_box.offset_x + str2_offset_x,
            loc_y + str2_offset_y);
    }

    /* enable font alpha */
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_fe_set_antialias(MMI_TRUE);
#endif

    /* If hint is already at fading state, don't start fade-out timer again */
    if (mtv_player_p->hint_state == MTV_PLAYER_HINT_STATE_SHOW_MULTILINE ||
        mtv_player_p->hint_state == MTV_PLAYER_HINT_STATE_SHOW_TRUNCATED)
    {
        if (mtv_player_p->fade_time != MMI_MOBILE_TV_PLAYER_HINT_POPUP_NO_FADE)
        {
            gui_start_timer(mtv_player_p->fade_time , mmi_mtv_player_hide_hint);

            if (mtv_player_p->hint_state == MTV_PLAYER_HINT_STATE_SHOW_MULTILINE)
            {
                mtv_player_p->hint_state = MTV_PLAYER_HINT_STATE_FADING_MULTILINE;
            }
            else
            {
                mtv_player_p->hint_state = MTV_PLAYER_HINT_STATE_FADING_TRUNCATED;
            }
        }
        else
        {
            gui_cancel_timer(mmi_mtv_player_hide_hint);
        }
    }
#endif /* !defined(GDI_2_LAYERS) */
#endif /* defined(__MMI_ATV_OSD_SUPPORT__)  */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_restore_setting
 * DESCRIPTION
 *  restore mobile tv player default settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_hide_hint(void)
{
#if defined(__MMI_ATV_OSD_SUPPORT__)
#if !defined(GDI_2_LAYERS)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->hint_state = MTV_PLAYER_HINT_STATE_HIDE;

    if (mmi_mtv_player_is_flag_set(MTV_PLAYER_SERVICE_UNAVAILABLE))
    {
        mmi_mtv_player_set_hint(
            (CHAR *) GetString((U16) (STR_ID_MOBILE_TV_PLAYER_SERVICE_IS_NOT_AVAILABLE)),
			(CHAR *) NULL,
		    MMI_MOBILE_TV_PLAYER_HINT_POPUP_NO_FADE,
            MMI_TRUE);
    }
    else if (mmi_mtv_player_is_flag_set(MTV_PLAYER_UNAVAILABLE_IN_CALL))
    {
        mmi_mtv_player_set_hint(
            (CHAR *) GetString((U16) (STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL)),
			(CHAR *) NULL,
		    MMI_MOBILE_TV_PLAYER_HINT_POPUP_NO_FADE,
            MMI_TRUE);
    }

    mmi_mtv_player_draw_osd();
    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif /* !defined(GDI_2_LAYERS) */
#endif /* #if defined(__MMI_ATV_OSD_SUPPORT__) */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_get_display_layer_pos_size
 * DESCRIPTION
 *  config display layer's size / rotation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_get_display_layer_pos_size(
    S32 ori_x, S32 ori_y, S32 ori_width, S32 ori_height,
    S32 *x, S32 *y, S32 *width, S32 *height)
{
    /* Default ratio */
    S32 ratio_w = 4, ratio_h = 3;

#ifdef __MMI_MTV_RECORD_SUPPORT__
    /* ratio should be the same as record ratio */
    switch (mtv_player_p->setting.record_size)
    {
        case MDI_MTV_RECORDER_SIZE_QCIF:
            ratio_w = 176;
            ratio_h = 144;
            break;
        case MDI_MTV_RECORDER_SIZE_QVGA:
            ratio_w = 320;
            ratio_h = 240;
            break;
        case MDI_MTV_RECORDER_SIZE_HVGA:
            ratio_w = 480;
            ratio_h = 320;
            break;
        default:
            break;
    }
#endif

    if (ori_width * ratio_h > ori_height * ratio_w)
    {
        *y = ori_y;
        *height = ori_height;
        *width = ori_height * ratio_w / ratio_h;
        *x = ori_x + ((ori_width - *width) >> 1);
    }
    else
    {
        *x = ori_x;
        *width = ori_width;
        *height = ori_width * ratio_h / ratio_w;
        *y = ori_y + ((ori_height - *height) >> 1);
    }

    /* even number */
    *x = (*x % 2) ? (*x + 1): (*x);
    *y = (*y % 2) ? (*y + 1): (*y);
    *width = (*width % 2) ? (*width + 1): (*width);
    *height = (*height % 2) ? (*height + 1): (*height);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_config_display_layer
 * DESCRIPTION
 *  config display layer's size / rotation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_config_display_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 rotate_value = 0;
    S32 ori_w, ori_h, ori_x, ori_y;
    S32 width, height, offset_x, offset_y;
    MMI_BOOL rotate_by_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef   __MMI_ATV_OSD_SUPPORT__
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        rotate_value = GDI_LAYER_ROTATE_0;
        rotate_by_layer = MMI_FALSE;
        ori_w = MTV_PLAYER_DISPLAY_LAYER_WIDTH;
        ori_h = MTV_PLAYER_DISPLAY_LAYER_HEIGHT;
        ori_x = MTV_PLAYER_DISPLAY_LAYER_OFFSET_X;
        ori_y = MTV_PLAYER_DISPLAY_LAYER_OFFSET_Y;

    }
    else
    {
#endif
    #if defined(__MMI_MTV_LANDSCAPE_SUPPORT__)
        rotate_value = GDI_LAYER_ROTATE_0;
        rotate_by_layer = MMI_FALSE;
        ori_w = LCD_WIDTH;
        ori_h = LCD_HEIGHT;
    #else /* __MMI_MTV_LANDSCAPE_SUPPORT__ */
        rotate_value = GDI_LAYER_ROTATE_90; /* Origin: the top-right corner of LCD */
        rotate_by_layer = MMI_TRUE;
        ori_w = LCD_HEIGHT;
        ori_h = LCD_WIDTH;
    #endif /* __MMI_MTV_LANDSCAPE_SUPPORT__ */
        ori_x = 0;
        ori_y = 0;
#ifdef   __MMI_ATV_OSD_SUPPORT__
    }
#endif

    mmi_mtv_player_get_display_layer_pos_size(
        ori_x, ori_y, ori_w, ori_h,
        &offset_x, &offset_y, &width, &height);


    /* Rotate and Resize Display Layer */
    if (PLAYER_STATE_IN(MTV_PLAYER_STOPPED))
    {
        mdi_util_hw_layer_switch_to_sw_layer(mtv_player_p->display_layer_handle);
        gdi_layer_push_and_set_active(mtv_player_p->display_layer_handle);
        gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
        gdi_layer_resize(width, height);
        gdi_layer_set_position(offset_x, offset_y);
        gdi_layer_set_rotate(rotate_value);
        gdi_lcd_set_rotate_by_layer(rotate_by_layer);
        gdi_layer_clear_background(GDI_COLOR_BLACK);
        gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_config_layers
 * DESCRIPTION
 *  config all layer's size / rotation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_config_layers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(GDI_2_LAYERS) && defined(__MMI_ATV_OSD_SUPPORT__)
    S32 dls_layer_width,dls_layer_height,dls_layer_offset_x,dls_layer_offset_y;
    U8 rotate_value;
    MMI_BOOL rotate_by_layer;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef   __MMI_ATV_OSD_SUPPORT__
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        mtv_player_p->active_osd_cntx_p = &g_mtv_player_osd_cntx;
        wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
    }
    else
    {
        mtv_player_p->active_osd_cntx_p = &g_mtv_player_osd_cntx_270;
        wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_H_BAR);
    }
#endif

    /*******************************************
     * Rotate and Resize display Layer
     ********************************************/
    mmi_mtv_player_config_display_layer();

#if defined(__MMI_ATV_OSD_SUPPORT__)
    /*******************************************
     * Rotate and Resize OSD Layer
     ********************************************/
    gdi_layer_push_and_set_active(mtv_player_p->osd_layer_handle);
#if defined(__MDI_MTV_HW_ROTATOR_SUPPORT__) || defined(__MMI_MTV_LANDSCAPE_SUPPORT__)
    gdi_layer_resize(LCD_WIDTH, LCD_HEIGHT);
#else /* __MDI_MTV_HW_ROTATOR_SUPPORT__ || __MMI_MTV_LANDSCAPE_SUPPORT__ */
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        gdi_layer_resize(LCD_WIDTH, LCD_HEIGHT);
        gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
        gdi_lcd_set_rotate_by_layer(KAL_FALSE);
    }
    else
    {
        gdi_layer_resize(LCD_HEIGHT, LCD_WIDTH);
        gdi_layer_set_rotate(GDI_LAYER_ROTATE_90);
        gdi_lcd_set_rotate_by_layer(KAL_TRUE);
    }
#endif /* __MDI_MTV_HW_ROTATOR_SUPPORT__ || __MMI_MTV_LANDSCAPE_SUPPORT__  */
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    wgui_status_icon_bar_set_alpha_blend_layer(
        WGUI_STATUS_ICON_BAR_H_BAR,
        mtv_player_p->osd_layer_handle);

#if !defined(GDI_2_LAYERS)
    /*******************************************
     * Rotate and Resize Volume Layer
     ********************************************/
#if defined(__MMI_FTE_SUPPORT__)
    gdi_layer_push_and_set_active(mtv_player_p->vol_layer_handle);
    gdi_layer_set_position(
        mtv_player_p->active_osd_cntx_p->vol_bg.offset_x,
        mtv_player_p->active_osd_cntx_p->vol_bg.offset_y);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
#endif /* defined(__MMI_FTE_SUPPORT__) */

    /*******************************************
     * Rotate and Resize DLS Layer
     ********************************************/
    gdi_layer_push_and_set_active(mtv_player_p->dls_layer_handle);


    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        dls_layer_width = MTV_PLAYER_DLS_LAYER_WIDTH;
        dls_layer_height = MTV_PLAYER_DLS_LAYER_HEIGHT;
        dls_layer_offset_x = MTV_PLAYER_DLS_LAYER_OFFSET_X;
        dls_layer_offset_y = MTV_PLAYER_DLS_LAYER_OFFSET_Y;
        rotate_value = GDI_LAYER_ROTATE_0;
        rotate_by_layer = KAL_FALSE;
    }
    else
    {
    #if defined(__MMI_MTV_LANDSCAPE_SUPPORT__)
        dls_layer_width = MTV_PLAYER_FULLSCREEN_DLS_LAYER_WIDTH;
        dls_layer_height = MTV_PLAYER_FULLSCREEN_DLS_LAYER_HEIGHT;
        dls_layer_offset_x = MTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_X;
        dls_layer_offset_y = MTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_Y;
        rotate_value = GDI_LAYER_ROTATE_0;
        rotate_by_layer = KAL_FALSE;
    #else /* __MMI_MTV_LANDSCAPE_SUPPORT__ */

    #ifdef __MDI_MTV_HW_ROTATOR_SUPPORT__
        dls_layer_width = MTV_PLAYER_FULLSCREEN_DLS_LAYER_HEIGHT;
        dls_layer_height = MTV_PLAYER_FULLSCREEN_DLS_LAYER_WIDTH;
        dls_layer_offset_x = LCD_WIDTH - MTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_Y - MTV_PLAYER_FULLSCREEN_DLS_LAYER_HEIGHT;
        dls_layer_offset_y = MTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_X;
        rotate_value = GDI_LAYER_ROTATE_0;
        rotate_by_layer = KAL_FALSE;
    #else /* __MDI_MTV_HW_ROTATOR_SUPPORT__ */
        dls_layer_width = MTV_PLAYER_FULLSCREEN_DLS_LAYER_WIDTH;
        dls_layer_height = MTV_PLAYER_FULLSCREEN_DLS_LAYER_HEIGHT;
        dls_layer_offset_x = MTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_X;
        dls_layer_offset_y = MTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_Y;
        rotate_value = GDI_LAYER_ROTATE_90;
        rotate_by_layer = KAL_TRUE;
    #endif /* __MDI_MTV_HW_ROTATOR_SUPPORT__ */

    #endif /* __MMI_MTV_LANDSCAPE_SUPPORT__ */
    }


    gdi_layer_resize(dls_layer_width, dls_layer_height);
    gdi_layer_set_position(dls_layer_offset_x, dls_layer_offset_y);
    gdi_layer_set_rotate(rotate_value);
    gdi_lcd_set_rotate_by_layer(rotate_by_layer);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    /* temp solution: signal & dls should not use the same layer */
#if !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
    gdi_layer_toggle_double();
#endif
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

#if defined(__MDI_MTV_HW_ROTATOR_SUPPORT__) && !defined(__MMI_MTV_LANDSCAPE_SUPPORT__)
    /*******************************************
     * Rotate and Resize OSD drawing Layer
     ********************************************/
    gdi_layer_push_and_set_active(mtv_player_p->osd_drawing_layer_handle);
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        gdi_layer_resize(LCD_WIDTH, LCD_HEIGHT);  /* No need ? */
    }
    else
    {
        gdi_layer_resize(LCD_HEIGHT, LCD_WIDTH);
    }
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    /*******************************************
     * Rotate and Resize DLS drawing Layer
     ********************************************/
    gdi_layer_push_and_set_active(mtv_player_p->dls_drawing_layer_handle);
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        gdi_layer_resize(MTV_PLAYER_DLS_LAYER_WIDTH, MTV_PLAYER_DLS_LAYER_HEIGHT);  /* No need ? */
    }
    else
    {
        gdi_layer_resize(MTV_PLAYER_FULLSCREEN_DLS_LAYER_WIDTH, MTV_PLAYER_FULLSCREEN_DLS_LAYER_HEIGHT);
    }

    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
#endif /* __MDI_MTV_HW_ROTATOR_SUPPORT__ && !__MMI_MTV_LANDSCAPE_SUPPORT__*/
#endif /* !defined(GDI_2_LAYERS) */

    /* Initialize icon position for touch */
    mmi_mtv_player_init_icon_info();
#endif /* defined(__MMI_ATV_OSD_SUPPORT__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_service_found_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_mtv_player_service_found_hdlr(mdi_mtv_service_info_struct *service_info, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mtv_player_p->num_services < MMI_MTV_MAX_SERVICES
       && (service_info->service_type == MEDIA_MTV_SERVICE_DIGITAL_RADIO ||
           service_info->service_type == MEDIA_MTV_SERVICE_DIGITAL_TV ||
           service_info->service_type == MEDIA_MTV_SERVICE_ANALOG_TV))
    {
        U16 i = mtv_player_p->num_services;

        mtv_player_p->services[i].service_id = service_info->service_id;
        mmi_ucs2cpy((CHAR*)mtv_player_p->services[i].service_name, (CHAR*)L"");

        if (service_info->service_name != NULL)
        {
            mmi_ucs2cpy((CHAR*)mtv_player_p->services[i].service_name, (CHAR*)service_info->service_name);
        }

        mtv_player_p->services[i].service_number = service_info->service_number;
        mtv_player_p->services[i].service_flags = service_info->service_flags;
        mtv_player_p->services[i].service_type = service_info->service_type;
        mtv_player_p->num_services ++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_search_progress_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_mtv_player_search_progress_hdlr(S32 value, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    MDI_RESULT ret;
    MMI_BOOL rescan;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* should only called when live scan */
    ASSERT(KERNEL_STATE_IN(MTV_KERNEL_SCANNING));

    mmi_mtv_player_update_scan_progress(value);

    if (value != 100)
    {
        return;
    }

#if defined(__MMI_MTV_RECORD_SUPPORT__)
    /* Query record resolution after scan */
    mmi_mtv_player_prepare_record_size_list();
#endif

    /* Following: value == 100 */
    rescan = MMI_FALSE;
    if (mtv_player_p->num_services == 0)
    {
        if (mmi_mtv_player_is_flag_set(MTV_PLAYER_IS_LIVE_SCANNING) == MMI_FALSE)
        {
            rescan = MMI_TRUE;
        }
    }

    /* Scan from database and found out service == 0 */
    if (rescan)
    {
        /* scan again from air */
        mtv_player_p->setting.is_channel_list_init = MMI_FALSE;
        ret = mmi_mtv_player_kernel_entry_scanning_state();
        if (ret != MDI_RES_MTV_SUCCEED)
        {
            mmi_mtv_player_reset_to_channel_list_screen();
        }
        return;
    }


    if (mtv_player_p->num_services > 0)
    {
        /* When scan next time, scan from database */
        mtv_player_p->setting.is_channel_list_init = MMI_TRUE;
    }

    WriteRecord(NVRAM_EF_MOBILE_TV_PLAYER_SETTING_LID, 1, (void*)&mtv_player_p->setting, NVRAM_EF_MOBILE_TV_PLAYER_SETTING_SIZE, &error);

    KERNEL_ENTER_STATE(MTV_KERNEL_OPENED);

    /* update and save setting */
    mmi_mtv_player_unset_flag(MTV_PLAYER_IS_LIVE_SCANNING);

    mmi_mtv_player_reset_to_channel_list_screen();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_service_update_hdlr
 * DESCRIPTION
 *  service update handler
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_service_update_hdlr(mdi_mtv_service_info_struct* service_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mtv_player_service_info_struct *info_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info_ptr = mmi_mtv_player_get_active_channel_ptr();

    /* Update audio mode */
    info_ptr->audio_mode = service_info->audio_mode;
    info_ptr->supported_audio_mode = service_info->supported_audio_mode;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_service_ready_hdlr
 * DESCRIPTION
 *  mmi_mtv_player_service_ready_hdlr
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_service_ready_hdlr(mdi_mtv_service_info_struct* service_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen;
    mdi_mtv_service_status_struct service_status;
    mtv_player_service_info_struct *info_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    active_screen = mmi_frm_scrn_get_active_id();
    info_ptr = mmi_mtv_player_get_active_channel_ptr();

    mdi_mtv_service_get_status(mtv_player_p->mtv_handle, &service_status);

    KERNEL_ENTER_STATE(MTV_KERNEL_READY);

    /* Store audio mode */
    info_ptr->audio_mode = service_info->audio_mode;
    info_ptr->supported_audio_mode = service_info->supported_audio_mode;

    /* Start to update signal when enter READY state */
    mmi_mtv_player_get_and_update_signal();
#ifdef __MMI_MATV_ESD_RECOVERY_SUPPORT__
#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)
    if(MMI_FALSE == matv_resz_timer_seted)
    {
        kal_prompt_trace(MOD_ENG, "mmi_mtv_player_service_ready_hdlr craeat and set timer");
        //resz_cp_ESD_timeout_timer = kal_create_timer("MDP_ESD_CP_CRZ_TIMEOUT");
        kal_set_timer(matv_resz_cp_ESD_timeout_timer, (kal_timer_func_ptr)resz_cp_ESD_timeout_timer_hdlr,NULL, KAL_TICKS_3_SEC, KAL_TICKS_3_SEC);
        matv_resz_timer_seted = MMI_TRUE;        
    }
#endif
#endif/*__MMI_MATV_ESD_RECOVERY_SUPPORT__*/

    if (active_screen == SCR_ID_MOBILE_TV_PLAYER_APP)
    {
#ifdef   __MMI_ATV_OSD_SUPPORT__
        /* To make TV syncs with LCD, draw hint before play.  */
        mmi_mtv_player_draw_osd();
        mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif
        if (PLAYER_STATE_IN(MTV_PLAYER_STOPPED))
        {
        #if defined(__MMI_MTV_A2DP_SUPPORT__)
            if (mmi_mtv_player_is_output_to_bt() && !mmi_mtv_player_is_in_background_call())
            {
                mmi_mtv_player_player_enter_state(MTV_PLAYER_BT_CONNECT);
            }
            else
            {
                mmi_mtv_player_player_enter_state(MTV_PLAYER_PLAY);
            }
        #else
            mmi_mtv_player_player_enter_state(MTV_PLAYER_PLAY);
        #endif
        }
#ifdef   __MMI_ATV_OSD_SUPPORT__
        /* If already fade out, keep all key handler as: mmi_mtv_player_fullscr_osd_show_up */
        if (mtv_player_p->fullscr_osd_opacity != 0)
#endif
        {
            mmi_mtv_player_register_key_hdlr();
        }

#ifdef   __MMI_ATV_OSD_SUPPORT__

        if (mmi_mtv_player_is_flag_set(MTV_PLAYER_UNAVAILABLE_IN_CALL))
        {
            mmi_mtv_player_set_hint(
                (CHAR *) GetString((U16)(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL)),
				(CHAR *) NULL,
			    MMI_MOBILE_TV_PLAYER_HINT_POPUP_NO_FADE,
                MMI_TRUE);

            mmi_mtv_player_fullscr_reset_osd_fade(MMI_FALSE);
        }
        else
        {
            mmi_mtv_player_draw_osd();
        }
        mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif
    }
 #ifdef __MMI_MTV_PREVIEW_SUPPORT__
    else if (active_screen == SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST)
    {
        if (PLAYER_STATE_IN(MTV_PLAYER_STOPPED))
        {
        #if defined(__MMI_MTV_A2DP_SUPPORT__)
            if (mmi_mtv_player_is_output_to_bt() && !mmi_mtv_player_is_in_background_call())
            {
                mmi_mtv_player_player_enter_state(MTV_PLAYER_BT_CONNECT);
            }
            else
            {
                mmi_mtv_player_player_enter_state(MTV_PLAYER_PLAY);
            }
        #else
            mmi_mtv_player_player_enter_state(MTV_PLAYER_PLAY);
        #endif
            if (mtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
            {
                mmi_mtv_player_draw_preview_icon(MTV_PLAYER_PREVIEW_ICON_BROKEN);
            }
        }
    }
 #endif/*__MMI_MTV_PREVIEW_SUPPORT__*/
    else if(mmi_frm_scrn_is_present(GRP_ID_MOBILE_TV_PLAYER, SCR_ID_MOBILE_TV_PLAYER_APP, MMI_FRM_NODE_ALL_FLAG))/* in matv sms screen */
    {
        if (PLAYER_STATE_IN(MTV_PLAYER_STOPPED))
        {
        #if defined(__MMI_MTV_A2DP_SUPPORT__)
            if (mmi_mtv_player_is_output_to_bt() && !mmi_mtv_player_is_in_background_call())
            {
                mmi_mtv_player_player_enter_state(MTV_PLAYER_BT_CONNECT);
            }
            else
            {
                mmi_mtv_player_player_enter_state(MTV_PLAYER_PLAY);
            }
        #else
            mmi_mtv_player_player_enter_state(MTV_PLAYER_PLAY);
        #endif
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_system_closed_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_system_closed_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(!KERNEL_STATE_IN(MTV_KERNEL_CLOSING))
    {
        return;
    }

    KERNEL_ENTER_STATE(MTV_KERNEL_CLOSED);

    mmi_mtv_player_free_adm_structure();

#ifdef __ATV_SMS_SUPPORT__
    mmi_mtv_sms_release_app_mem();
#endif /* __ATV_SMS_SUPPORT__ */

    /* Delete adm */
    mmi_mtv_player_delete_adm();

    if (mtv_player_p->app_mem_pool != NULL)
    {
        /* free app-based memory */
        applib_mem_ap_free((void*)mtv_player_p->app_mem_pool);
        mtv_player_p->app_mem_pool = NULL;
    }

    if (mtv_player_p->app_mem_force_release)
    {
        /* Notify MMI that this application is already stopped */
        applib_mem_ap_notify_stop_finished(
            APPLIB_MEM_AP_ID_MTV_PLAYER, KAL_TRUE);
        mtv_player_p->app_mem_force_release = KAL_FALSE;
    }


    active_screen = mmi_frm_scrn_get_active_id();
    if (active_screen == SCR_ID_MOBILE_TV_PLAYER_APP_BASE)
    {
        mmi_frm_group_close(GRP_ID_MOBILE_TV_PLAYER);

        if (!mtv_player_p->go_back_history)
        {
             mmi_frm_close_to_idle_group();
        }
    }
    else if (mmi_frm_scrn_is_present(
                GRP_ID_MOBILE_TV_PLAYER,
                SCR_ID_MOBILE_TV_PLAYER_APP_BASE,
                MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_frm_group_close(GRP_ID_MOBILE_TV_PLAYER);
        if (!mtv_player_p->go_back_history)
        {
            mmi_frm_close_to_idle_group_with_start_id(
                SCR_ID_MOBILE_TV_PLAYER_APP_BASE);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_handle_record_discarded
 * DESCRIPTION
 *
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_handle_record_discarded(void)
{
#ifdef __MMI_MTV_RECORD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_scrn_set_leave_proc(
        GRP_ID_MOBILE_TV_PLAYER,
        SCR_ID_MOBILE_TV_PLAYER_DELETING,
        NULL);
    if (mtv_player_p->del_deleting_screen == MMI_TRUE)
    {
        mmi_idle_display();
    }
    else
    {
        /* delete save_confirm and saving screens */
        mmi_frm_scrn_close(GRP_ID_MOBILE_TV_PLAYER, SCR_ID_MOBILE_TV_PLAYER_SAVE_CONFIRM);
        mmi_frm_scrn_close(GRP_ID_MOBILE_TV_PLAYER, SCR_ID_MOBILE_TV_PLAYER_DELETING);
    }
#endif /* __MMI_MTV_RECORD_SUPPORT__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_system_event_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_system_event_hdlr(U32 event_id, S32 param, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event_id == MDI_MTV_SYSTEM_CLOSED)
    {
        mmi_mtv_player_system_closed_hdlr();
    }
#ifdef __MMI_MTV_RECORD_SUPPORT__
    else if(event_id == MDI_MTV_SYSTEM_UNSAVED_RECORDING_DISCARDED)
    {
        if(KERNEL_STATE_IN(MTV_KERNEL_DELETING))
        {
            KERNEL_ENTER_STATE(MTV_KERNEL_OPENED);
            mmi_mtv_player_handle_record_discarded();
        }
    }
#endif /*__MMI_MTV_RECORD_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_service_event_hdlr
 * DESCRIPTION
 *  callback function when save is done
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_service_event_hdlr(U32 event_id, S32 param, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Service is closed */
    if (KERNEL_STATE_IN(MTV_KERNEL_CLOSED) || KERNEL_STATE_IN(MTV_KERNEL_CLOSING))
    {
        return;
    }

    if (event_id == MDI_MTV_SERVICE_READY)
    {
        StopTimer(MTV_PLAYER_SERVICE_TIMEOUT_TIMER);
        mmi_mtv_player_service_ready_hdlr((mdi_mtv_service_info_struct*)param);
    }
    else if (event_id == MDI_MTV_SERVICE_UPDATED)
    {
        mmi_mtv_player_service_update_hdlr((mdi_mtv_service_info_struct*)param);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_player_event_hdlr
 * DESCRIPTION
 *  callback function when any player event ind
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_player_event_hdlr(U32 event_id, S32 param, void *user_data)
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
 *  mmi_mtv_player_recorder_event_hdlr
 * DESCRIPTION
 *  callback function when any recorder event ind
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_recorder_event_hdlr(U32 event_id, S32 param, void *user_data)
{
#ifdef __MMI_MTV_RECORD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    active_screen = mmi_frm_scrn_get_active_id();

    if (event_id == MDI_MTV_RECORDER_ERROR)
    {
        /* When there is record error from MED, MED will stop recorder. */

        RECORDER_ENTER_STATE(MTV_RECORDER_STOPPED);

        mtv_player_p->active_osd_cntx_p->channel_next.status = MTV_PLAYER_ICON_STATUS_ENABLE;
        mtv_player_p->active_osd_cntx_p->channel_prev.status = MTV_PLAYER_ICON_STATUS_ENABLE;

        if (mmi_frm_scrn_is_present(
                GRP_ID_MOBILE_TV_PLAYER,
                SCR_ID_MOBILE_TV_PLAYER_APP_BASE,
                MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {

            /* Follow the design in record_icon_release */
            if (!PLAYER_STATE_IN(MTV_PLAYER_STOPPED))
            {
                mmi_mtv_player_player_enter_state(MTV_PLAYER_STOPPED);
            }

            RECORDER_ENTER_STATE(MTV_RECORDER_SAVE_CONFIRM);
            if (!mmi_frm_scrn_enter(
                    GRP_ID_MOBILE_TV_PLAYER,
                    SCR_ID_MOBILE_TV_PLAYER_DUMMY,
                    NULL,
                    mmi_mtv_player_enter_save_confirm,
                    MMI_FRM_UNKNOW_SCRN))
            {
                return;
            }
            ShowCategoryDummyScreen();


            /* When record error, always delete screen upto Main screen or channel list */
            if (mmi_frm_scrn_is_present(
                    GRP_ID_MOBILE_TV_PLAYER,
                    SCR_ID_MOBILE_TV_PLAYER_APP,
                    MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
            {
                mmi_frm_scrn_multiple_close(
                    GRP_ID_MOBILE_TV_PLAYER,
                    mmi_frm_scrn_get_active_id(),
                    0,
                    0,
                    SCR_ID_MOBILE_TV_PLAYER_APP,
                    0);
            }
            else if (mmi_frm_scrn_is_present(
                        GRP_ID_MOBILE_TV_PLAYER,
                        SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST,
                        MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
            {
                mmi_frm_scrn_multiple_close(
                    GRP_ID_MOBILE_TV_PLAYER,
                    mmi_frm_scrn_get_active_id(),
                    0,
                    0,
                    SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST,
                    0);
            }

            mmi_mtv_player_display_failure_popup(param);

        }
        else
        {
            mmi_popup_display_simple(
                (WCHAR*) GetString(STR_ID_MOBILE_TV_PLAYER_NOTIFY_RECORDER_STOPPED),
                MMI_EVENT_FAILURE,
                GRP_ID_MOBILE_TV_PLAYER,
                NULL);

            /* Terminate application */
            mmi_mtv_player_terminate_app();
        }

    }
    else if (event_id == MDI_MTV_RECORDER_SAVING_SUCCEEDED ||
             event_id == MDI_MTV_RECORDER_SAVING_FAILED)
    {
        /* Only display pop up on the SAVING screen */
        if (active_screen == SCR_ID_MOBILE_TV_PLAYER_SAVING)
        {
            if (event_id == MDI_MTV_RECORDER_SAVING_SUCCEEDED)
            {
               // mmi_mtv_player_display_popup(STR_GLOBAL_SAVED, MMI_EVENT_SUCCESS);
            }
            else if (event_id == MDI_MTV_RECORDER_SAVING_FAILED)
            {
                mmi_mtv_player_display_popup(STR_GLOBAL_FAILED_TO_SAVE, MMI_EVENT_FAILURE);
            }
        }

        RECORDER_ENTER_STATE(MTV_RECORDER_STOPPED);

        /* delete save_confirm and saving screens */
        mmi_frm_scrn_close(GRP_ID_MOBILE_TV_PLAYER, SCR_ID_MOBILE_TV_PLAYER_SAVE_CONFIRM);
        mmi_frm_scrn_close(GRP_ID_MOBILE_TV_PLAYER, SCR_ID_MOBILE_TV_PLAYER_SAVING);

        if (!mmi_frm_scrn_is_present(
                GRP_ID_MOBILE_TV_PLAYER,
                SCR_ID_MOBILE_TV_PLAYER_APP_BASE,
                MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
            /* display popup callback */
            mmi_popup_display_simple(
                (WCHAR*) GetString(STR_ID_MOBILE_TV_PLAYER_NOTIFY_SAVING_FAIL),
                MMI_EVENT_FAILURE,
                GRP_ID_MOBILE_TV_PLAYER,
                NULL);

            mmi_mtv_player_terminate_app();
        }
    }
    else if (event_id == MDI_MTV_RECORDER_RECORDING_DISCARDED)
    {
        if(RECORDER_STATE_IN(MTV_RECORDER_DELETING))
        {
            RECORDER_ENTER_STATE(MTV_RECORDER_STOPPED);;
            mmi_mtv_player_handle_record_discarded();
        }
    }
#endif /* __MMI_MTV_RECORD_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_complete_recovering_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_mtv_player_complete_recovering_hdlr(S32 result, void *user_data)
{
#ifdef __MMI_MTV_RECORD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    active_screen_id = mmi_frm_scrn_get_active_id();

    if (!KERNEL_STATE_IN(MTV_KERNEL_SAVING))
    {
        return;
    }

    /* Only display pop up on the SAVING screen */
    if (active_screen_id == SCR_ID_MOBILE_TV_PLAYER_SAVING)
    {
        if (result >= 0)
        {
           // mmi_mtv_player_display_popup(STR_GLOBAL_SAVED, MMI_EVENT_SUCCESS);
        }
        else if (result == MDI_RES_MTV_ERR_DISC_FULL)
        {
            mmi_mtv_player_display_failure_popup(result);
        }
        else
        {
            mmi_mtv_player_display_popup(STR_GLOBAL_FAILED_TO_SAVE, MMI_EVENT_FAILURE);
        }
    }

    KERNEL_ENTER_STATE(MTV_KERNEL_OPENED);

    /* delete save_confirm and saving screens */
    mmi_frm_scrn_close(GRP_ID_MOBILE_TV_PLAYER, SCR_ID_MOBILE_TV_PLAYER_SAVE_CONFIRM);
    mmi_frm_scrn_close(GRP_ID_MOBILE_TV_PLAYER, SCR_ID_MOBILE_TV_PLAYER_SAVING);
#endif /* __MMI_MTV_RECORD_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_handle_play_fail
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mmi_mtv_player_handle_play_fail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mtv_player_service_info_struct *info_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MTV_A2DP_SUPPORT__)
    mmi_mtv_player_bt_close_codec();
#endif /* __MMI_MTV_A2DP_SUPPORT__ */

    mmi_mtv_player_turn_off_backlight();
    return MDI_RES_MTV_SUCCEED;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_open_engine
 * DESCRIPTION
 *  open mtv engine
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_open_engine(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_mtv_setting_struct mtv_setting = {0};
    mdi_mtv_service_config_struct mtv_service_config;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mtv_setting.brightness = mtv_player_p->setting.brightness;
    mtv_setting.contrast = mtv_player_p->setting.contrast;
    mtv_setting.saturation = mtv_player_p->setting.saturation;
    mtv_setting.volume_level = mtv_player_p->setting.vol_level;
    mtv_setting.record_size = mtv_player_p->setting.record_size;

#ifdef   __MMI_MTV_RECORD_SUPPORT__
    if (mtv_player_p->storage_status == MTV_PLAYER_STORAGE_OK)
    {
        mtv_setting.record_dir = (PU8)mtv_player_p->storage_filepath;
    }
    else
#endif
    {
        mtv_setting.record_dir = 0;
    }

    mtv_service_config.complete_recovering_hdlr = mmi_mtv_player_complete_recovering_hdlr;
    mtv_service_config.search_progress_hdlr = mmi_mtv_player_search_progress_hdlr;
    mtv_service_config.service_found_hdlr = mmi_mtv_player_service_found_hdlr;
    mtv_service_config.system_event_hdlr = mmi_mtv_player_system_event_hdlr;
    mtv_service_config.service_event_hdlr = mmi_mtv_player_service_event_hdlr;
    mtv_service_config.recorder_event_hdlr = mmi_mtv_player_recorder_event_hdlr;
    mtv_service_config.player_event_hdlr = mmi_mtv_player_player_event_hdlr;
    mtv_service_config.user_data = NULL;

    mtv_setting.sim = NULL;

    return mdi_mtv_open(0,
                        &mtv_player_p->mtv_handle,
                        &mtv_setting,
                        &mtv_service_config);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_enter_next_state
 * DESCRIPTION
 *  enter state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_enter_next_state(mmi_mtv_player_module_enum module)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (module == MMI_MTV_KERNEL)
    {
        switch (mtv_player_p->kernel_next_state)
        {
            case MTV_KERNEL_CLOSING:
                ret = mmi_mtv_player_kernel_entry_closing_state();
                break;
        #ifdef __MMI_MTV_RECORD_SUPPORT__
            case MTV_KERNEL_SAVING:
                ret = mmi_mtv_player_kernel_entry_saving_state();
                break;
            case MTV_KERNEL_DELETING:
                ret = mmi_mtv_player_kernel_entry_deleting_state();
                break;
        #endif /* __MMI_MTV_RECORD_SUPPORT__  */
            case MTV_KERNEL_SCANNING:
                ret = mmi_mtv_player_kernel_entry_scanning_state();
                break;
            case MTV_KERNEL_OPENED:
                ret = mmi_mtv_player_kernel_entry_opened_state();
                break;
            case MTV_KERNEL_INIT:
                ret = mmi_mtv_player_kernel_entry_init_state();
                break;
            case MTV_KERNEL_READY:
                ret = mmi_mtv_player_kernel_entry_ready_state();
                break;
            default:
                break;

        }
    }
    else if (module == MMI_MTV_PLAYER)
    {
        switch (mtv_player_p->player_next_state)
        {
            case MTV_PLAYER_STOPPED:
                ret = mmi_mtv_player_player_entry_stopped_state();
                break;
            case MTV_PLAYER_PLAY:
                ret = mmi_mtv_player_player_entry_play_state();
                break;
            case MTV_PLAYER_BT_CONNECT:
                ret = mmi_mtv_player_player_entry_bt_connect_state();
                break;
        }
    }
    else if (module == MMI_MTV_RECORDER)
    {
    #ifdef __MMI_MTV_RECORD_SUPPORT__
        switch (mtv_player_p->recorder_next_state)
        {
            case MTV_RECORDER_STOPPED:
                ret = mmi_mtv_player_recorder_entry_stopped_state();
                break;
            case MTV_RECORDER_RECORD:
                ret = mmi_mtv_player_recorder_entry_record_state();
                break;
            case MTV_RECORDER_PAUSE:
                ret = mmi_mtv_player_recorder_entry_pause_state();
                break;
            case MTV_RECORDER_SAVE_CONFIRM:
                ret = mmi_mtv_player_recorder_entry_save_confirm_state();
                break;
            case MTV_RECORDER_SAVING:
                ret = mmi_mtv_player_recorder_entry_saving_state();
                break;
            case MTV_RECORDER_DELETING:
                ret = mmi_mtv_player_recorder_entry_deleting_state();
        }
    #endif /* #ifdef __MMI_MTV_RECORD_SUPPORT__  */
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_exit_current_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_exit_current_state(mmi_mtv_player_module_enum module)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (module == MMI_MTV_KERNEL)
    {
        switch (mtv_player_p->kernel_state)
        {
            case MTV_KERNEL_CLOSING:
                ret = mmi_mtv_player_kernel_exit_closing_state();
                break;
        #ifdef __MMI_MTV_RECORD_SUPPORT__
            case MTV_KERNEL_SAVING:
                ret = mmi_mtv_player_kernel_exit_saving_state();
                break;
            case MTV_KERNEL_DELETING:
                ret = mmi_mtv_player_kernel_exit_deleting_state();
                break;
        #endif /* __MMI_MTV_RECORD_SUPPORT__ */
            case MTV_KERNEL_SCANNING:
                ret = mmi_mtv_player_kernel_exit_scanning_state();
                break;
            case MTV_KERNEL_OPENED:
                ret = mmi_mtv_player_kernel_exit_opened_state();
                break;
            case MTV_KERNEL_INIT:
                ret = mmi_mtv_player_kernel_exit_init_state();
                break;
            case MTV_KERNEL_READY:
                ret = mmi_mtv_player_kernel_exit_ready_state();
                break;
            default:
                break;
        }
    }
    else if (module == MMI_MTV_PLAYER)
    {
        switch (mtv_player_p->player_state)
        {
            case MTV_PLAYER_STOPPED:
                ret = mmi_mtv_player_player_exit_stopped_state();
                break;
            case MTV_PLAYER_PLAY:
                ret = mmi_mtv_player_player_exit_play_state();
                break;
            case MTV_PLAYER_BT_CONNECT:
                ret = mmi_mtv_player_player_exit_bt_connect_state();
                break;
        }
    }
    else if (module == MMI_MTV_RECORDER)
    {
    #ifdef __MMI_MTV_RECORD_SUPPORT__
        switch (mtv_player_p->recorder_state)
        {
            case MTV_RECORDER_STOPPED:
                ret = mmi_mtv_player_recorder_exit_stopped_state();
                break;
            case MTV_RECORDER_RECORD:
                ret = mmi_mtv_player_recorder_exit_record_state();
                break;
            case MTV_RECORDER_PAUSE:
                ret = mmi_mtv_player_recorder_exit_pause_state();
                break;
            case MTV_RECORDER_SAVE_CONFIRM:
                ret = mmi_mtv_player_recorder_exit_save_confirm_state();
                break;
            case MTV_RECORDER_SAVING:
                ret = mmi_mtv_player_recorder_exit_saving_state();
                break;
            case MTV_RECORDER_DELETING:
                ret = mmi_mtv_player_recorder_exit_deleting_state();
                break;
        }
    #endif /* __MMI_MTV_RECORD_SUPPORT__ */
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_player_prepare_player_setting
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_mtv_player_player_prepare_player_setting(mdi_mtv_player_setting_struct *video_setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen_id = mmi_frm_scrn_get_active_id();
    mtv_player_service_info_struct *info_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    info_ptr = mmi_mtv_player_get_active_channel_ptr();
    if (active_screen_id == SCR_ID_MOBILE_TV_PLAYER_APP)
    {
    #if defined(__MDI_MTV_HW_ROTATOR_SUPPORT__)
    #if defined(__MMI_MTV_LANDSCAPE_SUPPORT__)
        mdi_mtv_player_set_hw_rotator(MDI_MTV_LCD_ROTATE_0);
    #else /* __MMI_MTV_LANDSCAPE_SUPPORT__ */
        if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        {
            mdi_mtv_player_set_hw_rotator(MDI_MTV_LCD_ROTATE_90);
        }
        else
        {
            mdi_mtv_player_set_hw_rotator(MDI_MTV_LCD_ROTATE_0);
        }
    #endif /* __MMI_MTV_LANDSCAPE_SUPPORT__ */
    #endif /* __MDI_MTV_HW_ROTATOR_SUPPORT__ */
        if (info_ptr->service_type == MDI_MTV_SERVICE_TYPE_ANALOG_TV)
        {
            video_setting->play_layer_handle = mtv_player_p->display_layer_handle;
        #if !defined(__MMI_ATV_OSD_SUPPORT__)
            video_setting->blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
        #elif defined(GDI_2_LAYERS)
            video_setting->blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
        #else
            if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
            {
            #if defined(__MMI_FTE_SUPPORT__)
                video_setting->blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2 | GDI_LAYER_ENABLE_LAYER_3;
            #else /* defined(__MMI_FTE_SUPPORT__) */
                video_setting->blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2 | GDI_LAYER_ENABLE_LAYER_3;
            #endif /* defined(__MMI_FTE_SUPPORT__) */
            }
            else
            {
                video_setting->blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;
            }
        #endif
            video_setting->play_layer_flag = GDI_LAYER_ENABLE_LAYER_0;

        }
        else
        {
            video_setting->play_layer_handle = NULL;
            video_setting->blt_layer_flag = 0;
            video_setting->play_layer_flag = 0;
        }

        video_setting->is_visual_update = MMI_TRUE;
        video_setting->rotate = MDI_MTV_LCD_ROTATE_0;
    #if !defined(__MDI_MTV_HW_ROTATOR_BY_IDP__) && !defined(__MMI_MTV_LANDSCAPE_SUPPORT__)
        if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        {
            video_setting->rotate = MDI_MTV_LCD_ROTATE_270;
        }
    #endif /* !defined(__MDI_MTV_HW_ROTATOR_BY_IDP__) &&  && !defined(__MMI_MTV_LANDSCAPE_SUPPORT__) */
    }
    else
    {
    #if defined(__MDI_MTV_HW_ROTATOR_SUPPORT__)
        mdi_mtv_player_set_hw_rotator(MDI_MTV_LCD_ROTATE_0);
    #endif /* __MDI_MTV_HW_ROTATOR_SUPPORT__ */
        if (info_ptr->service_type == MDI_MTV_SERVICE_TYPE_ANALOG_TV)
        {
            video_setting->play_layer_handle = mtv_player_p->cl_preview_layer_handle;
            video_setting->blt_layer_flag = mtv_player_p->cl_blt_layer_flag;
            video_setting->play_layer_flag = mtv_player_p->cl_preview_layer_flag;
        }
        else
        {
            video_setting->play_layer_handle = NULL;
            video_setting->blt_layer_flag = 0;
            video_setting->play_layer_flag = 0;
        }

        video_setting->is_visual_update = MMI_TRUE;
        video_setting->rotate = MDI_MTV_LCD_ROTATE_0;
    }

    video_setting->play_audio = KAL_TRUE;
    if (mmi_mtv_player_is_in_background_call())
    {
        video_setting->play_audio = KAL_FALSE;
    }

#ifdef __MMI_MTV_RECORD_SUPPORT__
    if (mtv_player_p->setting.storage == (U16) SRV_FMGR_PUBLIC_DRV)
    {
        video_setting->storage = MDI_MTV_RECORDER_STORAGE_PHONE;
    }
    else
    {
        video_setting->storage = MDI_MTV_RECORDER_STORAGE_CARD;
    }
#endif /* __MMI_MTV_RECORD_SUPPORT__ */

    /* Set color format */
#ifdef __MDI_DISPLAY_YUYV422_SUPPORT__
    if (video_setting->play_layer_handle != NULL)
    {
        mdi_util_hw_layer_switch_to_sw_layer(video_setting->play_layer_handle);
        gdi_layer_push_and_set_active(video_setting->play_layer_handle);
        if (info_ptr->service_type == MDI_MTV_SERVICE_TYPE_ANALOG_TV)
        {
            gdi_layer_set_color_format(GDI_COLOR_FORMAT_UYVY422);
        }
        else
        {
            gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
        }
        gdi_layer_clear_background(GDI_COLOR_BLACK);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
#endif /* __MDI_DISPLAY_YUYV422_SUPPORT__ */
}

#ifdef __MMI_MATV_ESD_RECOVERY_SUPPORT__
#ifdef __CAMERA_MATV_ESD_RECOVERY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_send_msg_to_restart
 * DESCRIPTION
 *  mmi send msg to restart atv chip.
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_mtv_player_send_msg_to_restart(void)
{
		/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_mtv_msg_restart(mtv_player_p->mtv_handle);
}
#endif
#endif/*__MMI_MATV_ESD_RECOVERY_SUPPORT__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_entry_closing_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_kernel_entry_closing_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!PLAYER_STATE_IN(MTV_PLAYER_STOPPED))
        mmi_mtv_player_player_enter_state(MTV_PLAYER_STOPPED);
#ifdef   __MMI_MTV_RECORD_SUPPORT__
    if (!RECORDER_STATE_IN(MTV_RECORDER_STOPPED))
    {
        mmi_mtv_player_recorder_enter_state(MTV_RECORDER_STOPPED);
    }
#endif
    mtv_player_p->last_error = mdi_mtv_close(mtv_player_p->mtv_handle);


    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_exit_closing_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_kernel_exit_closing_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_entry_scanning_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_kernel_entry_scanning_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 band;
    void *param = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_mtv_player_is_in_background_call())
    {
        mtv_player_p->last_error = MDI_RES_MTV_FAILED;
        return mtv_player_p->last_error;
    }


    band = mmi_mtv_player_select_band();


    if (mtv_player_p->setting.is_channel_list_init == MMI_FALSE)
    {
        mtv_player_p->last_error = mdi_mtv_scan_services(
                                        mtv_player_p->mtv_handle,
                                        MDI_MTV_SOURCE_LIVE_SIGNAL,
                                        band,
                                        param);
        if (mtv_player_p->last_error == MDI_RES_MTV_SUCCEED)
        {
           mmi_mtv_player_set_flag(MTV_PLAYER_IS_LIVE_SCANNING);
        }
    }

    else
    {
        mtv_player_p->last_error = mdi_mtv_scan_services(
                                        mtv_player_p->mtv_handle,
                                        MDI_MTV_SOURCE_LOCAL_DATABASE,
                                        band,
                                        0);

        if (mtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
        {
            mtv_player_p->setting.is_channel_list_init = MMI_FALSE;

            mtv_player_p->last_error = mdi_mtv_scan_services(
                                        mtv_player_p->mtv_handle,
                                        MDI_MTV_SOURCE_LIVE_SIGNAL,
                                        band,
                                        param);
            if (mtv_player_p->last_error == MDI_RES_MTV_SUCCEED)
            {
               mmi_mtv_player_set_flag(MTV_PLAYER_IS_LIVE_SCANNING);
            }
        }
        else
        {
            mmi_mtv_player_unset_flag(MTV_PLAYER_IS_LIVE_SCANNING);
        }
    }

    return mtv_player_p->last_error;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_exit_scanning_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_kernel_exit_scanning_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (KERNEL_STATE_IN(MTV_KERNEL_SCANNING))
    {
        ret = mdi_mtv_abort_scan_services(mtv_player_p->mtv_handle);
        ASSERT(ret == MDI_RES_MTV_SUCCEED);
    }
    else
    {
        ret = MDI_RES_MTV_SUCCEED;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_entry_opened_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_kernel_entry_opened_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mtv_player_p->kernel_state == MTV_KERNEL_CLOSED)
    {
        MDI_RESULT ret = mmi_mtv_player_open_engine();
        return ret;
    }
    else
    {
        return MDI_RES_MTV_SUCCEED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_exit_opened_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_kernel_exit_opened_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_entry_init_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_kernel_entry_init_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mtv_player_service_info_struct *info_ptr;
    mdi_mtv_player_setting_struct video_setting = {0};
    U16 active_screen = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_mtv_player_is_in_background_call())
    {
        mmi_mtv_player_set_flag(MTV_PLAYER_UNAVAILABLE_IN_CALL);
        mtv_player_p->last_error = MDI_RES_MTV_FAILED;
        return mtv_player_p->last_error;
    }

    info_ptr = mmi_mtv_player_get_active_channel_ptr();

    if (active_screen == SCR_ID_MOBILE_TV_PLAYER_APP)
    {
        /* Reconfig display layer for drawing DAB animation or playing DTV */
        mmi_mtv_player_config_display_layer();
    }
#ifdef   __MMI_ATV_OSD_SUPPORT__
    mmi_mtv_player_unset_flag(MTV_PLAYER_SERVICE_UNAVAILABLE);
#endif
#if defined(__MMI_MTV_A2DP_SUPPORT__)
    if (mmi_mtv_player_is_output_to_bt())
    {
        /* Do not Auto play */
        mtv_player_p->last_error = mdi_mtv_start_service(
                                        mtv_player_p->mtv_handle,
                                        info_ptr->service_id,
                                        info_ptr->service_type,
                                        MMI_FALSE,
                                        NULL);

    }
    else
#endif
    {
        mmi_mtv_player_player_prepare_player_setting(&video_setting);
        /* Auto play */


        /* stop MMI sleep and stop LED pattern beofore play */
	mmi_mtv_player_turn_on_backlight();
        mmi_mtv_player_set_volume();
        mtv_player_p->last_error = mdi_mtv_start_service(
                                        mtv_player_p->mtv_handle,
                                        info_ptr->service_id,
                                        info_ptr->service_type,
                                        MMI_TRUE,
                                        &video_setting);

        if (mtv_player_p->last_error == MDI_RES_MTV_SUCCEED)
        {
            /* Change player state to PLAY directly */
            PLAYER_ENTER_STATE(MTV_PLAYER_PLAY);
        }
        else
        {
	    mmi_mtv_player_turn_off_backlight();
        }
    }
    return mtv_player_p->last_error;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_exit_init_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_kernel_exit_init_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mtv_player_service_info_struct *info_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (KERNEL_STATE_IN(MTV_KERNEL_INIT))
    {
        info_ptr = mmi_mtv_player_get_active_channel_ptr();
        mtv_player_p->last_error = mdi_mtv_stop_service(mtv_player_p->mtv_handle, info_ptr->service_id);
        ASSERT(mtv_player_p->last_error == MDI_RES_MTV_SUCCEED);

        StopTimer(MTV_PLAYER_SERVICE_TIMEOUT_TIMER);

        /* Change player state to STOP directly */
        if (PLAYER_STATE_IN(MTV_PLAYER_PLAY))
        {
            PLAYER_ENTER_STATE(MTV_PLAYER_STOPPED);
            mmi_mtv_player_turn_off_backlight();
        }
    }
    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_entry_ready_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_kernel_entry_ready_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_exit_ready_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_kernel_exit_ready_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mtv_player_service_info_struct *info_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mtv_player_p->kernel_next_state!=MTV_KERNEL_READY);

    if (!PLAYER_STATE_IN(MTV_PLAYER_STOPPED))
    {
        mmi_mtv_player_player_enter_state(MTV_PLAYER_STOPPED);
    }
#ifdef   __MMI_MTV_RECORD_SUPPORT__
    if (!RECORDER_STATE_IN(MTV_RECORDER_STOPPED))
    {
        mmi_mtv_player_recorder_enter_state(MTV_RECORDER_STOPPED);
    }
#endif
    StopTimer(MTV_PLAYER_UPDATE_SIGNAL_TIMER);

    info_ptr = mmi_mtv_player_get_active_channel_ptr();
    mtv_player_p->last_error = mdi_mtv_stop_service(mtv_player_p->mtv_handle, info_ptr->service_id);
    ASSERT(mtv_player_p->last_error == MDI_RES_MTV_SUCCEED);

    /* Re-draw signal icon to level 0 */
    mtv_player_p->signal_strength = 0;
    mmi_mtv_player_draw_signal_icon();

    return mtv_player_p->last_error;
}


/*player state management*/
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_player_entry_stopped_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_player_entry_stopped_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //v_player_service_info_struct *info_ptr;
    //mdi_mtv_service_type_enum service_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MATV_ESD_RECOVERY_SUPPORT__
#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)
    kal_prompt_trace(MOD_ENG, "mmi_mtv_player_player_entry_stopped_state cancel timer");
    if (MMI_TRUE == matv_resz_timer_seted)
    {
        kal_cancel_timer(matv_resz_cp_ESD_timeout_timer); 
        matv_resz_timer_seted = MMI_FALSE;
    }
#endif
#endif/*__MMI_MATV_ESD_RECOVERY_SUPPORT__*/

    if (mtv_player_p->player_state == MTV_PLAYER_PLAY)
    {
        mtv_player_p->last_error = mdi_mtv_player_stop(mtv_player_p->mtv_handle);

    #if defined(__MMI_MTV_A2DP_SUPPORT__)
        mmi_mtv_player_bt_close_codec();
        mmi_mtv_player_disconnect_bt();
    #endif
    mmi_mtv_player_turn_off_backlight();
    }
#if defined(__MMI_MTV_A2DP_SUPPORT__)
    else if (mtv_player_p->player_state == MTV_PLAYER_BT_CONNECT)
    {
        mmi_mtv_player_disconnect_bt();
    }
#endif

    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_player_exit_stopped_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_player_exit_stopped_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_player_entry_bt_connect_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_player_entry_bt_connect_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MTV_A2DP_SUPPORT__)

    mtv_player_service_info_struct *info_ptr;
    MMI_BOOL is_stereo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_mtv_player_is_output_to_bt())
    {
        if (mmi_mtv_player_is_in_background_call())
        {
            mmi_mtv_player_set_flag(MTV_PLAYER_UNAVAILABLE_IN_CALL);
            mtv_player_p->last_error = MDI_RES_MTV_FAILED;
            return mtv_player_p->last_error;
        }

        info_ptr = mmi_mtv_player_get_active_channel_ptr();

        mdi_mtv_get_audio_sample_rate(mtv_player_p->mtv_handle, info_ptr->service_id, &(mtv_player_p->aud_sample_rate));
        mdi_mtv_get_audio_channel_number(mtv_player_p->mtv_handle, info_ptr->service_id, &(mtv_player_p->aud_channel_num));

        if (mtv_player_p->aud_channel_num == 2)
        {
            is_stereo = MMI_TRUE;
        }
        else
        {
            is_stereo = MMI_FALSE;
        }

        /* For protection */
        if (!IsMyTimerExist(MTV_PLAYER_BT_ANIMATION_TIMER))
        {
            /* Draw BT connect animation after 600 ms */
            StartTimer(
                MTV_PLAYER_BT_ANIMATION_TIMER,
                600,
                mmi_mtv_player_bt_anim_timeout_hdlr);
        }

        av_bt_open_ex(
            mmi_mtv_player_get_bt_headset(),
            (kal_uint16)mtv_player_p->aud_sample_rate,
            (kal_uint8)is_stereo,
            mmi_mtv_player_bt_open_callback,
            KAL_TRUE);

        mtv_player_p->last_error = MDI_RES_MTV_SUCCEED;
        return MDI_RES_MTV_SUCCEED;
    }
    else
    {
        /* shall not enter here */
        MMI_ASSERT(0);
        return MDI_RES_MTV_FAILED;
    }
#else
    ASSERT(0);
    return MDI_RES_MTV_FAILED;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_player_exit_bt_connect_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_player_exit_bt_connect_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_player_entry_play_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_player_entry_play_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen_id = mmi_frm_scrn_get_active_id();
    //mtv_player_service_info_struct *info_ptr;
    mdi_mtv_player_setting_struct video_setting = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(!PLAYER_STATE_IN(MTV_PLAYER_PLAY));

    if (mmi_mtv_player_is_in_background_call())
    {
        mmi_mtv_player_set_flag(MTV_PLAYER_UNAVAILABLE_IN_CALL);
        mtv_player_p->last_error = MDI_RES_MTV_FAILED;
        return mtv_player_p->last_error;
    }
#ifdef __MMI_MATV_ESD_RECOVERY_SUPPORT__
#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)
    if(MMI_FALSE == matv_resz_timer_seted)
    {
        //resz_cp_ESD_timeout_timer = kal_create_timer("MDP_ESD_CP_CRZ_TIMEOUT");
        kal_set_timer(matv_resz_cp_ESD_timeout_timer, (kal_timer_func_ptr)resz_cp_ESD_timeout_timer_hdlr,NULL, KAL_TICKS_3_SEC, KAL_TICKS_3_SEC);
        matv_resz_timer_seted = MMI_TRUE;
    }
#endif
#endif/*__MMI_MATV_ESD_RECOVERY_SUPPORT__*/

    /* stop MMI sleep and stop LED pattern beofore play */
	mmi_mtv_player_turn_off_backlight();
        /* init aud volume */
    mmi_mtv_player_set_volume();

    mmi_mtv_player_player_prepare_player_setting(&video_setting);

    mtv_player_p->last_error =
        mdi_mtv_player_play(mtv_player_p->mtv_handle, &video_setting);

    if (mtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
    {
        mmi_mtv_player_handle_play_fail();
    }

    return mtv_player_p->last_error;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_player_exit_play_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_player_exit_play_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MDI_RES_MTV_SUCCEED;
}

#ifdef __MMI_MTV_RECORD_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_entry_saving_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_kernel_entry_saving_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mdi_mtv_recover_recording(mtv_player_p->mtv_handle);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_exit_saving_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_kernel_exit_saving_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mdi_mtv_abort_recovering(mtv_player_p->mtv_handle);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_entry_deleting_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_kernel_entry_deleting_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mdi_mtv_discard_unsaved_recording(mtv_player_p->mtv_handle);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_exit_deleting_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_kernel_exit_deleting_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_recorder_entry_stopped_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_recorder_entry_stopped_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_recorder_exit_stopped_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_recorder_exit_stopped_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_recorder_entry_record_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_recorder_entry_record_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mtv_player_service_info_struct *info_ptr;
    CHAR *file_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    info_ptr = mmi_mtv_player_get_active_channel_ptr();
    if (RECORDER_STATE_IN(MTV_RECORDER_STOPPED))
    {
        mtv_player_p->last_error =
            mdi_mtv_recorder_start(mtv_player_p->mtv_handle, (CHAR*)info_ptr->service_name);
    }
    else
    {
        mtv_player_p->last_error =
            mdi_mtv_recorder_resume(mtv_player_p->mtv_handle);
    }
    return mtv_player_p->last_error;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_recorder_exit_record_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_recorder_exit_record_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_recorder_entry_pause_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_recorder_entry_pause_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mtv_player_p->last_error = mdi_mtv_recorder_pause(mtv_player_p->mtv_handle);

    return mtv_player_p->last_error;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_recorder_exit_pause_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_recorder_exit_pause_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_recorder_entry_save_confirm_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_recorder_entry_save_confirm_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mtv_player_p->last_error = mdi_mtv_recorder_stop(mtv_player_p->mtv_handle);
    mtv_player_p->active_osd_cntx_p->channel_next.status = MTV_PLAYER_ICON_STATUS_ENABLE;
    mtv_player_p->active_osd_cntx_p->channel_prev.status = MTV_PLAYER_ICON_STATUS_ENABLE;

    active_screen_id = mmi_frm_scrn_get_active_id();
    if (active_screen_id == SCR_ID_MOBILE_TV_PLAYER_APP)
    {
        /* If already fade out, keep all key handler as: mmi_mtv_player_fullscr_osd_show_up */
#ifdef   __MMI_ATV_OSD_SUPPORT__
        if (mtv_player_p->fullscr_osd_opacity != 0)
#endif
        {
            mmi_mtv_player_register_key_hdlr();
        }
    }

    if (mtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
    {
        ASSERT(0);
    }
    return mtv_player_p->last_error ;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_recorder_exit_save_confirm_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_recorder_exit_save_confirm_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_recorder_exit_deleting_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_recorder_exit_deleting_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_recorder_entry_save_confirm_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_recorder_entry_deleting_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mtv_player_p->last_error = mdi_mtv_recorder_discard_recording(mtv_player_p->mtv_handle);

    return mtv_player_p->last_error;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_recorder_entry_saving_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_recorder_entry_saving_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mtv_player_p->last_error = mdi_mtv_recorder_save(mtv_player_p->mtv_handle, NULL);

    return mtv_player_p->last_error;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_recorder_exit_saving_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_mtv_player_recorder_exit_saving_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mtv_player_p->last_error = mdi_mtv_recorder_abort_saving(mtv_player_p->mtv_handle);

    return mtv_player_p->last_error;
}
#endif /* __MMI_MTV_RECORD_SUPPORT__  */

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_get_and_update_signal
 * DESCRIPTION
 *  udpate siangl api on common screen
 * PARAMETERS
 *  dummy_ptr       [?]
 * RETURNS
 *  U8
 *****************************************************************************/
 
void mmi_mtv_player_get_and_update_signal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_mtv_service_status_struct service_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MM_DCM_SUPPORT__
    if (MMI_FALSE == g_is_engine_paused)
#endif
    {
        if (KERNEL_STATE_IN(MTV_KERNEL_READY))
        {
            mdi_mtv_service_get_status(mtv_player_p->mtv_handle, &service_status);
            mtv_player_p->signal_strength = service_status.signal_strength;
        }

        mmi_mtv_player_draw_signal_icon();
    }
    StartTimer(
        MTV_PLAYER_UPDATE_SIGNAL_TIMER,
        MMI_MOBILE_TV_PLAYER_UPDATE_SIGNAL_DURATION,
        mmi_mtv_player_get_and_update_signal);
}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_draw_signal_icon
 * DESCRIPTION
 *  draw signal icon
 * PARAMETERS
 *  void
 * RETURNS
 *  S32 active channel idx
 *****************************************************************************/
 void mmi_mtv_player_draw_signal_icon(void)
{
#if defined(__MMI_ATV_OSD_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef GDI_USING_2D_ENGINE_V3
    PU8 dest;
#endif
    U16 signal_level;
    S32 width, height;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_frm_scrn_get_active_id() == SCR_ID_MOBILE_TV_PLAYER_APP &&
        mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        ASSERT(mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270);
#if defined(GDI_2_LAYERS)
        gdi_layer_push_and_set_active(mtv_player_p->osd_layer_handle);
#else /* GDI_2_LAYERS */
    #if defined(__MDI_MTV_HW_ROTATOR_SUPPORT__) && !defined(__MMI_MTV_LANDSCAPE_SUPPORT__)
        gdi_layer_push_and_set_active(mtv_player_p->dls_drawing_layer_handle);
    #else /* __MDI_MTV_HW_ROTATOR_SUPPORT__ && !__MMI_MTV_LANDSCAPE_SUPPORT__ */
        gdi_layer_push_and_set_active(mtv_player_p->dls_layer_handle);
    #if !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
        gdi_layer_toggle_double();
		gdi_layer_copy_double();
    #endif
    #endif /* __MDI_MTV_HW_ROTATOR_SUPPORT__ && !__MMI_MTV_LANDSCAPE_SUPPORT__ */
#endif /* GDI_2_LAYERS */
        /* clear icon region as transparent */
        gdi_image_get_dimension_id(
            (U16)(IMG_ID_MTV_PLAYER_SIGNAL_LEVEL_0),
            &width,
            &height);

        gdi_draw_solid_rect(
            MMI_MTV_PLAYER_SIGNAL_ICON_OFFSET_X,
            MMI_MTV_PLAYER_SIGNAL_ICON_OFFSET_Y,
            MMI_MTV_PLAYER_SIGNAL_ICON_OFFSET_X + width,
            MMI_MTV_PLAYER_SIGNAL_ICON_OFFSET_Y + height,
            GDI_COLOR_TRANSPARENT);

        /* Draw signal icon */
        signal_level = mtv_player_p->signal_strength / 25;
        gdi_image_draw_id(
            MMI_MTV_PLAYER_SIGNAL_ICON_OFFSET_X,
            MMI_MTV_PLAYER_SIGNAL_ICON_OFFSET_Y,
            (U16)(IMG_ID_MTV_PLAYER_SIGNAL_LEVEL_0 + signal_level));
        gdi_layer_pop_and_restore_active();

    #if defined(__MDI_MTV_HW_ROTATOR_SUPPORT__) && !defined(__MMI_MTV_LANDSCAPE_SUPPORT__)
        gdi_layer_push_and_set_active(mtv_player_p->dls_layer_handle);
    #if !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
        gdi_layer_toggle_double();
	    gdi_layer_copy_double();
    #endif
    #if defined(GDI_USING_2D_ENGINE_V3)
        gdi_2d_begin();
        gdi_2d_set_layer_as_dest_buffer(mtv_player_p->dls_layer_handle);
        gdi_2d_set_layer_as_src_bitblt_buffer(mtv_player_p->dls_drawing_layer_handle);
        gdi_2d_rotate(GDI_TRANSFORM_ROTATE_90);
        gdi_2d_end();
    #else
        gdi_layer_get_buffer_ptr(&dest);
        /* toggle double buffer */
        mmi_mtv_player_sw_rotate(
          dest,
          mtv_player_p->dls_drawing_layer_buf_ptr,
          (U32) MTV_PLAYER_FULLSCREEN_DLS_LAYER_WIDTH,
          (U32) MTV_PLAYER_FULLSCREEN_DLS_LAYER_HEIGHT);
    #endif
        gdi_layer_pop_and_restore_active();
    #endif /* defined(__MDI_MTV_HW_ROTATOR_SUPPORT__) && !defined(__MMI_MTV_LANDSCAPE_SUPPORT__) */

        mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

        /* Change status icon level: status bar is hided, the function won't blt out */
        wgui_status_icon_bar_change_icon_level(STATUS_ICON_MTV_SIGNAL, (U8) mtv_player_p->signal_strength);

    }
    else
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_MOBILE_TV_PLAYER_APP)
        {
        #if defined(GDI_2_LAYERS)
            gdi_layer_push_and_set_active(mtv_player_p->osd_layer_handle);
        #else
            gdi_layer_push_and_set_active(mtv_player_p->status_bar_layer_handle);
        #endif
            wgui_status_icon_bar_register_hide_callback(
                WGUI_STATUS_ICON_BAR_H_BAR,
                hide_status_icons_bar0_by_transparent);
        }

        /* Change status icon level: if status bar is not hided, the function will blt out */
        wgui_status_icon_bar_change_icon_level(STATUS_ICON_MTV_SIGNAL, (U8) mtv_player_p->signal_strength);
        wgui_status_icon_bar_update();

        if (mmi_frm_scrn_get_active_id() == SCR_ID_MOBILE_TV_PLAYER_APP)
        {
            gdi_layer_pop_and_restore_active();
        }
    }
#else /* defined(__MMI_ATV_OSD_SUPPORT__) */
    if (mmi_frm_scrn_get_active_id() == SCR_ID_MOBILE_TV_PLAYER_APP)
    {
        /* Change status icon level: status bar is hided, the function won't blt out */
        wgui_status_icon_bar_change_icon_level(STATUS_ICON_MTV_SIGNAL, (U8) mtv_player_p->signal_strength);
    }
    else
    {
        /* Change status icon level: if status bar is not hided, the function will blt out */
        wgui_status_icon_bar_change_icon_level(STATUS_ICON_MTV_SIGNAL, (U8) mtv_player_p->signal_strength);
        wgui_status_icon_bar_update();
    }
#endif /* defined(__MMI_ATV_OSD_SUPPORT__) */
}


#if defined(__MMI_MTV_A2DP_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_bt_power_off_notify_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_bt_power_off_notify_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_BT_POWER_OFF_NOTIFY_HDLR, mtv_player_p->player_state);
    if (!mmi_a2dp_is_output_to_bt())
    {
        /* switch output: ON -> OFF */
        if (PLAYER_STATE_IN(MTV_PLAYER_PLAY))
        {
            av_bt_close_codec();
            av_bt_close(KAL_FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_is_output_to_bt
 * DESCRIPTION
 *  a callback function invoked by av_bt_open apis
 * PARAMETERS
 *  result
 * RETURNS
 *  void
 *****************************************************************************/
 MMI_BOOL mmi_mtv_player_is_output_to_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__ATV_I2S_SUPPORT__)
    return MMI_FALSE;
#else
    if (mmi_a2dp_is_output_to_bt())
    {
    #ifdef __MMI_MTV_RECORD_SUPPORT__
        if(RECORDER_STATE_IN(MTV_RECORDER_SAVE_CONFIRM) ||
            RECORDER_STATE_IN(MTV_RECORDER_PAUSE) ||
            RECORDER_STATE_IN(MTV_RECORDER_RECORD) ||
            RECORDER_STATE_IN(MTV_RECORDER_SAVING))
        {
            return MMI_FALSE;
        }
        else
    #endif
        {
            return MMI_TRUE;
        }
    }
    else
    {
        return MMI_FALSE;
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_stop_bt_connecting_anim
 * DESCRIPTION
 *  draw title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_stop_bt_connecting_anim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mtv_player_p->bt_connect_amin_handle == GDI_NULL_HANDLE)
    {
        return;
    }

    screen_id = mmi_frm_scrn_get_active_id();

    /* Stop animation first */
    gdi_image_stop_animation(mtv_player_p->bt_connect_amin_handle);
    mtv_player_p->bt_connect_amin_handle = GDI_NULL_HANDLE;

    /* Clear layer */
    if (screen_id == SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST)
    {
        gdi_layer_push_and_set_active(mtv_player_p->cl_preview_layer_handle);
        gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();

        gdi_layer_blt_previous(
            mtv_player_p->cl_preview_layer_offset_x,
            mtv_player_p->cl_preview_layer_offset_y,
            mtv_player_p->cl_preview_layer_offset_x + mtv_player_p->cl_preview_layer_width - 1,
            mtv_player_p->cl_preview_layer_offset_y + mtv_player_p->cl_preview_layer_height - 1);

    }
    /* Do not draw_osd() again if screen_id == MAIN_SCREEN.
       Player state is at CONNECTING state so BT animation
       will be drawn again. */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_bt_anim_timeout_hdlr
 * DESCRIPTION
 *  draw bt connecting animation if wait > 600ms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_bt_anim_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 screen_id = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_BT_ANIM_TIMEOUT_HDLR);

    if (screen_id == SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST)
    {
        if (mtv_player_p->bt_connect_amin_handle == GDI_NULL_HANDLE)
        {
            gdi_layer_push_and_set_active(mtv_player_p->cl_preview_layer_handle);
            gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_anim_draw_id(
                0,
                0,
                IMG_ID_MOBILE_TV_BT_CONNECT_PREVIEW,
                &mtv_player_p->bt_connect_amin_handle);

            gdi_layer_pop_and_restore_active();
        }
    }
#ifdef   __MMI_ATV_OSD_SUPPORT__
    else if (screen_id == SCR_ID_MOBILE_TV_PLAYER_APP)
    {
        mmi_mtv_player_draw_osd();
        mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_get_bt_headset
 * DESCRIPTION
 *  retrieve the user selected bt headset
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_bt_cm_bt_addr*
 *****************************************************************************/
 srv_bt_cm_bt_addr *mmi_mtv_player_get_bt_headset(void)
{
    return mmi_a2dp_get_bt_headset();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_bt_open_callback
 * DESCRIPTION
 *  a callback function invoked by av_bt_open apis
 * PARAMETERS
 *  result
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_bt_open_callback(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_BT_OPEN_CALLBACK, result);

    StopTimer(MTV_PLAYER_BT_ANIMATION_TIMER);
    mmi_mtv_player_stop_bt_connecting_anim();

    switch (result)
    {
        case AV_BT_CALLBACK_EVENT_OPEN_OK:
            /*
             *  NOTICE: even after receive EVENT_OPEN_FAILED or EVENT_OPEN_STOPPED,
             *          bt driver may still send EVENT_OPEN_OK, this is due to driver
             *          has retry mechanism.
             */
            if (PLAYER_STATE_IN(MTV_PLAYER_BT_CONNECT))
            {
                U16 active_screen_id;
                active_screen_id = mmi_frm_scrn_get_active_id();

                av_bt_open_codec(KAL_FALSE);

                if (active_screen_id == SCR_ID_MOBILE_TV_PLAYER_APP)
                {
                    mmi_mtv_player_player_enter_state(MTV_PLAYER_PLAY);
                    mmi_mtv_player_register_key_hdlr();
#ifdef   __MMI_ATV_OSD_SUPPORT__
                    if (mmi_mtv_player_is_flag_set(MTV_PLAYER_UNAVAILABLE_IN_CALL))
                    {
                        mmi_mtv_player_set_hint(
                            (CHAR *) GetString((U16)(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL)),
							(CHAR *) NULL,
						     MMI_MOBILE_TV_PLAYER_HINT_POPUP_NO_FADE,
                             MMI_TRUE);
                        mmi_mtv_player_fullscr_reset_osd_fade(MMI_FALSE);
                    }
                    else
                    {
                        mmi_mtv_player_draw_osd();
                    }
                    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif
                }
			  #ifdef __MMI_MTV_PREVIEW_SUPPORT__
                else if (active_screen_id == SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST)
                {
                    mmi_mtv_player_player_enter_state(MTV_PLAYER_PLAY);
                    if (mtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
                    {
                        mmi_mtv_player_draw_preview_icon(MTV_PLAYER_PREVIEW_ICON_BROKEN);
                    }
                }
			  #endif/*__MMI_MTV_PREVIEW_SUPPORT__*/
                else
                {
                    mmi_mtv_player_player_enter_state(MTV_PLAYER_PLAY);
                 }
            }
            else if (PLAYER_STATE_IN(MTV_PLAYER_PLAY))
            {
                /*
                 * since it is already play, we may set TRUE, which will directly
                 * change output to BT
                 */
                av_bt_open_codec(KAL_TRUE);
            }
            break;

        case AV_BT_CALLBACK_EVENT_OPEN_FAILED:
        case AV_BT_CALLBACK_EVENT_OPEN_STOPPED:
    #ifdef __MMI_BT_AUDIO_VIA_SCO__
        case AV_BT_CALLBACK_EVENT_OPEN_SCO:
    #endif
            if (PLAYER_STATE_IN(MTV_PLAYER_BT_CONNECT))
            {
                U16 active_screen_id;
                active_screen_id = mmi_frm_scrn_get_active_id();

                 /* connect failed - play the video */
                if (active_screen_id == SCR_ID_MOBILE_TV_PLAYER_APP)
                {
                    mmi_mtv_player_player_enter_state(MTV_PLAYER_PLAY);
                    mmi_mtv_player_register_key_hdlr();
#ifdef   __MMI_ATV_OSD_SUPPORT__
                    mmi_mtv_player_draw_osd();
                    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif
                }
                else if (active_screen_id == SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST)
                {
                    mmi_mtv_player_player_enter_state(MTV_PLAYER_PLAY);
                }
            }
            else
            {
                /* already connected, driver abort */
                av_bt_close_codec();
            }
            break;

        case AV_BT_CALLBACK_EVENT_OPEN_CANCELED:
            /* no need handle */
            break;

        case AV_BT_CALLBACK_EVENT_STREAM_ABORT_IND:
        case AV_BT_CALLBACK_EVENT_STREAM_CLOSE_IND:
        case AV_BT_CALLBACK_EVENT_STREAM_SUSPEND_IND:
        case AV_BT_CALLBACK_EVENT_UNEXPECTED_DISCONNECT_IND:
            /* TODO: display popup to show BT disconnect */
            av_bt_close_codec();
            if (PLAYER_STATE_IN(MTV_PLAYER_BT_CONNECT))
            {
                U16 active_screen_id;
                active_screen_id = mmi_frm_scrn_get_active_id();

                 /* connect failed - play the video */
                if (active_screen_id == SCR_ID_MOBILE_TV_PLAYER_APP)
                {
                    mmi_mtv_player_player_enter_state(MTV_PLAYER_PLAY);
                    mmi_mtv_player_register_key_hdlr();
#ifdef   __MMI_ATV_OSD_SUPPORT__
                    mmi_mtv_player_draw_osd();
                    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif
                }
                else if (active_screen_id == SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST)
                {
                    mmi_mtv_player_player_enter_state(MTV_PLAYER_PLAY);
                }
            }
            break;

        case AV_BT_CALLBACK_EVENT_INQUIRY_START_IND:
        case AV_BT_CALLBACK_EVENT_INQUIRY_STOP_IND:
             /* ignore */
            break;

        case AV_BT_CALLBACK_EVENT_STREAM_START_IND:
            if(PLAYER_STATE_IN(MTV_PLAYER_PLAY))
            {
                mmi_mtv_player_player_enter_state(MTV_PLAYER_STOPPED);
                mmi_mtv_player_player_enter_state(MTV_PLAYER_BT_CONNECT);
            }
            
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_disconnect_bt
 * DESCRIPTION
 *  start play video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_disconnect_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MTV_PLAYER_BT_ANIMATION_TIMER);
    mmi_mtv_player_stop_bt_connecting_anim();

    if (mmi_mtv_player_is_output_to_bt())
    {
        av_bt_close(MMI_FALSE);
    }
    /* TODO: stop anim */
}



/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_bt_close_codec
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_bt_close_codec(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_mtv_player_is_output_to_bt())
    {
        av_bt_close_codec();
    }

}
#endif /* __MMI_MTV_A2DP_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_enter_saving_screen
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_mtv_player_enter_saving_screen(void)
{
#ifdef __MMI_MTV_RECORD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                GRP_ID_MOBILE_TV_PLAYER,
                SCR_ID_MOBILE_TV_PLAYER_SAVING,
                NULL,
                mmi_mtv_player_enter_saving_screen,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    mmi_mtv_player_check_bg_snd();

#if defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_MTV_LANDSCAPE_SUPPORT__)
    mmi_frm_screen_rotate(mtv_player_p->ui_rotate);
#endif /* defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_MTV_LANDSCAPE_SUPPORT__) */

    ShowCategory66Screen(
        STR_ID_MOBILE_TV_PLAYER_APP_NAME,
        GetRootTitleIcon(MAIN_MENU_MULTIMEDIA_MENUID),
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_GLOBAL_SAVING),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    /* clear end key, this action cant be abort */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);

    if (guiBuffer != NULL)
    {
        return;
    }

    ASSERT(guiBuffer == NULL);

    if (RECORDER_STATE_IN(MTV_RECORDER_SAVE_CONFIRM))
    {
        ret = mmi_mtv_player_recorder_enter_state(MTV_RECORDER_SAVING);
        if (ret != MDI_RES_MTV_SUCCEED)
        {
            mmi_mtv_player_display_popup(STR_GLOBAL_FAILED_TO_SAVE, MMI_EVENT_FAILURE);

            /* if has error, cant save, delete temp file */
            mdi_mtv_discard_unsaved_recording(mtv_player_p->mtv_handle);
            g_mtv_player_osd_cntx.record.status =  MTV_PLAYER_ICON_STATUS_DISABLE;
            g_mtv_player_osd_cntx_270.record.status =  MTV_PLAYER_ICON_STATUS_DISABLE;

            mmi_mtv_player_recorder_enter_state(MTV_RECORDER_STOPPED);

            /* delete save_confirm and saving screens */
            mmi_frm_scrn_multiple_close(
                GRP_ID_MOBILE_TV_PLAYER,
                mmi_frm_scrn_get_active_id(),
                0,
                2,
                SCR_ID_INVALID,
                0);
        }

    }
    else
    {
        ret = mmi_mtv_player_kernel_enter_state(MTV_KERNEL_SAVING);

        if (ret != MDI_RES_MTV_SUCCEED)
        {
            mmi_mtv_player_display_popup(STR_GLOBAL_FAILED_TO_SAVE, MMI_EVENT_FAILURE);
            /* if has error, cant save, delete temp file */
            mdi_mtv_discard_unsaved_recording(mtv_player_p->mtv_handle);

            /* Reset kernel to OPEN state */
            mmi_mtv_player_kernel_enter_state(MTV_KERNEL_OPENED);

            /* delete save_confirm and saving screens */
            mmi_frm_scrn_multiple_close(
                GRP_ID_MOBILE_TV_PLAYER,
                mmi_frm_scrn_get_active_id(),
                0,
                2,
                SCR_ID_INVALID,
                0);
        }
    }
#endif /* __MMI_MTV_RECORD_SUPPORT__  */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_deleting_screen_leave_proc
 * DESCRIPTION
 *  delete screen id callback handler of mtv player applications
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 mmi_ret mmi_mtv_player_deleting_screen_leave_proc(mmi_event_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (para->evt_id)
    {
        case EVT_ID_SCRN_GOBACK:
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        {
            if (KERNEL_STATE_IN(MTV_KERNEL_DELETING)
				#ifdef   __MMI_MTV_RECORD_SUPPORT__
				||RECORDER_STATE_IN(MTV_RECORDER_DELETING)
				#endif
				)
            {
                mtv_player_p->del_deleting_screen = MMI_TRUE;
                return MMI_RET_ERR;
            }
            break;
        }
        default:
            break;
    }
    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_enter_deleting_screen
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_mtv_player_enter_deleting_screen(void)
{
#ifdef __MMI_MTV_RECORD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                GRP_ID_MOBILE_TV_PLAYER,
                SCR_ID_MOBILE_TV_PLAYER_DELETING,
                NULL,
                mmi_mtv_player_enter_deleting_screen,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    mmi_frm_scrn_set_leave_proc(
        GRP_ID_MOBILE_TV_PLAYER,
        SCR_ID_MOBILE_TV_PLAYER_DELETING,
        mmi_mtv_player_deleting_screen_leave_proc);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    mmi_mtv_player_check_bg_snd();

#if defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_MTV_LANDSCAPE_SUPPORT__)
    mmi_frm_screen_rotate(mtv_player_p->ui_rotate);
#endif /* defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_MTV_LANDSCAPE_SUPPORT__) */

    ShowCategory66Screen(
        STR_ID_MOBILE_TV_PLAYER_APP_NAME,
        GetRootTitleIcon(MAIN_MENU_MULTIMEDIA_MENUID),
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_GLOBAL_PLEASE_WAIT),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    /* clear end key, this action cant be abort */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);

    if (guiBuffer != NULL)
    {
        return;
    }

    ASSERT(guiBuffer == NULL);

    mtv_player_p->del_deleting_screen = MMI_FALSE;
    if (KERNEL_STATE_IN(MTV_KERNEL_OPENED))
    {
        ret = mmi_mtv_player_kernel_enter_state(MTV_KERNEL_DELETING);

        if (ret != MDI_RES_MTV_SUCCEED)
        {
            mmi_mtv_player_display_popup(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE);

            /* Reset kernel to OPEN state */
            mmi_mtv_player_kernel_enter_state(MTV_KERNEL_OPENED);

            /* delete save_confirm and saving screens */
            mmi_frm_scrn_multiple_close(
                GRP_ID_MOBILE_TV_PLAYER,
                mmi_frm_scrn_get_active_id(),
                0,
                2,
                SCR_ID_INVALID,
                0);
        }
    }
    else if (RECORDER_STATE_IN(MTV_RECORDER_SAVE_CONFIRM))
    {
        ret = mmi_mtv_player_recorder_enter_state(MTV_RECORDER_DELETING);
        if (ret != MDI_RES_MTV_SUCCEED)
        {
            mmi_mtv_player_display_popup(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE);

            mmi_mtv_player_recorder_enter_state(MTV_RECORDER_STOPPED);

            /* delete save_confirm and deleting screens */
            mmi_frm_scrn_multiple_close(
                GRP_ID_MOBILE_TV_PLAYER,
                mmi_frm_scrn_get_active_id(),
                0,
                2,
                SCR_ID_INVALID,
                0);
        }
    }
#endif /* __MMI_MTV_RECORD_SUPPORT__  */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_exit_scan_channel
 * DESCRIPTION
 *  for first time init channel list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_exit_scan_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (KERNEL_STATE_IN(MTV_KERNEL_SCANNING))
    {
        mmi_mtv_player_kernel_enter_state(MTV_KERNEL_OPENED);
        /* Reset service number as 0 because scan is aborted */
        mtv_player_p->num_services = 0;

        mmi_frm_scrn_close(GRP_ID_MOBILE_TV_PLAYER, SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST);
    }

    mmi_frm_end_scenario(MMI_SCENARIO_ID_HIGH_SCRN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_stop_scan
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_mtv_player_stop_scan(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(KERNEL_STATE_IN(MTV_KERNEL_SCANNING));

    mmi_mtv_player_kernel_enter_state(MTV_KERNEL_OPENED);

    /* Reset service number as 0 because scan is aborted */
    mtv_player_p->num_services = 0;
    kal_mem_set(mtv_player_p->services, 0, MMI_MTV_MAX_SERVICES * sizeof(mtv_player_service_info_struct));

    mmi_mtv_player_get_service_list();
    if (mtv_player_p->num_services > 0)
    {
        /* When scan next time, scan from database */
        mtv_player_p->setting.is_channel_list_init = MMI_TRUE;
    }

#if defined(__MMI_MTV_RECORD_SUPPORT__)
    /* Query record resolution after scan */
    mmi_mtv_player_prepare_record_size_list();
#endif
    mmi_mtv_player_reset_to_channel_list_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_get_scan_str_ptr
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
#ifndef __REMOVE_SCANNING_CHANNEL_STRING__
WCHAR *mmi_mtv_player_get_scan_str_ptr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *str_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mtv_player_p->setting.is_channel_list_init == MMI_FALSE)
    {
        str_ptr = (WCHAR *)GetString(STR_ID_MOBILE_TV_PLAYER_NOTIFY_SCANNING);
    }
    else
    {
        str_ptr = (WCHAR *)GetString(STR_ID_MOBILE_TV_PLAYER_NOTIFY_INITIALIZING);
    }

    return str_ptr;
}
#endif/*__REMOVE_SCANNING_CHANNEL_STRING__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_update_scan_progress
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_mtv_player_update_scan_progress(S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen = mmi_frm_scrn_get_active_id();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Update progressive value */

    if (active_screen == SCR_ID_MOBILE_TV_PLAYER_SCANNING)
    {
        Cat412UpdateList(
		  #ifndef __REMOVE_SCANNING_CHANNEL_STRING__
            (UI_string_type)mmi_mtv_player_get_scan_str_ptr(),
          #else
		    (UI_string_type)NULL,
		  #endif/*__REMOVE_SCANNING_CHANNEL_STRING__*/
            value, 0, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_enter_scan_channel
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_mtv_player_enter_scan_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 rsk_id = 0;
 #ifndef __REMOVE_SCANNING_CHANNEL_STRING__
    WCHAR *str_ptr = NULL;
 #endif/*__REMOVE_SCANNING_CHANNEL_STRING__*/
    MDI_RESULT ret;
    PU8 img_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((MMI_TRUE == mmi_mtv_player_is_in_background_call()) && (MMI_TRUE == mmi_frm_is_in_backward_scenario()))
    {
        mmi_mtv_player_reset_to_channel_list_screen();
        return;
    }

    mmi_frm_scrn_close(GRP_ID_MOBILE_TV_PLAYER, SCR_ID_MOBILE_TV_PLAYER_SCANNING);

    if (!mmi_frm_scrn_enter(
                GRP_ID_MOBILE_TV_PLAYER,
                SCR_ID_MOBILE_TV_PLAYER_SCANNING,
                mmi_mtv_player_exit_scan_channel,
                mmi_mtv_player_enter_scan_channel,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    mmi_mtv_player_check_bg_snd();

    mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGH_SCRN);

    /* Delete band screen */
    if (!mmi_frm_scrn_is_present(
            GRP_ID_MOBILE_TV_PLAYER,
            SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST,
            MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_MOBILE_TV_PLAYER, SCR_ID_MOBILE_TV_PLAYER_BAND);
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();


    rsk_id = STR_GLOBAL_CANCEL;

  #ifndef __REMOVE_SCANNING_CHANNEL_STRING__
    str_ptr = mmi_mtv_player_get_scan_str_ptr();
  #endif/*__REMOVE_SCANNING_CHANNEL_STRING__*/

#if !defined(__ATV_SLIM_VERSION__)
    img_ptr = (PU8)GetImage(IMG_ID_MOBILE_TV_SCANNING);
#endif

    wgui_cat1040_show(
        (UI_string_type)GetString(STR_ID_MOBILE_TV_PLAYER_APP_NAME),
        (PU8)GetImage(GetRootTitleIcon(MAIN_MENU_MULTIMEDIA_MENUID)),
        0,
        0,
        (UI_string_type)GetString(rsk_id),
        0,
        img_ptr,
     #ifndef __REMOVE_SCANNING_CHANNEL_STRING__
        (UI_string_type)str_ptr,
     #else
	    (UI_string_type)NULL,
	 #endif/*__REMOVE_SCANNING_CHANNEL_STRING__*/
        0,
        0,
        0,
        guiBuffer);

    /* Initialize parameter before entry service scanning state */

    mtv_player_p->num_services = 0;
    kal_mem_set(mtv_player_p->services, 0, MMI_MTV_MAX_SERVICES * sizeof(mtv_player_service_info_struct));

    ret = mmi_mtv_player_kernel_enter_state(MTV_KERNEL_SCANNING);

    if (ret != MDI_RES_MTV_SUCCEED)
    {
        /* Close channel list screen first to avoid re-entry*/
        mmi_frm_scrn_close(GRP_ID_MOBILE_TV_PLAYER, SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST);

        mmi_mtv_player_entry_channel_list_screen();

        if (mtv_player_p->cl_option_menu_gid != GRP_ID_INVALID)
        {
            cui_menu_close(mtv_player_p->cl_option_menu_gid);
            mtv_player_p->cl_option_menu_gid = GRP_ID_INVALID;
        }
        mmi_frm_scrn_multiple_close(
                GRP_ID_MOBILE_TV_PLAYER,
                mmi_frm_scrn_get_active_id(),
                0,
                0,
                SCR_ID_MOBILE_TV_PLAYER_APP_BASE,
                0);
    }
    else
    {
        if (rsk_id != 0)
        {
            SetRightSoftkeyFunction(mmi_mtv_player_stop_scan, KEY_EVENT_UP);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_save_confirm_screen_leave_proc
 * DESCRIPTION
 *  delete screen id callback handler of mtv player applications
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 mmi_ret mmi_mtv_player_save_confirm_screen_leave_proc(mmi_event_struct *para)
{
#ifdef __MMI_MTV_RECORD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (para->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
            /* reset parameter */
            if (RECORDER_STATE_IN(MTV_RECORDER_SAVE_CONFIRM))
            {
                RECORDER_ENTER_STATE(MTV_RECORDER_STOPPED);
            }
            break;
        }
        default:
            break;
    }
#endif /* __MMI_MTV_RECORD_SUPPORT__ */
    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mev_player_enter_save_confirm
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_mtv_player_enter_save_confirm(void)
{
#ifdef __MMI_MTV_RECORD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;
    U8* guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                GRP_ID_MOBILE_TV_PLAYER,
                SCR_ID_MOBILE_TV_PLAYER_SAVE_CONFIRM,
                NULL,
                mmi_mtv_player_enter_save_confirm,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    mmi_frm_scrn_set_leave_proc(
        GRP_ID_MOBILE_TV_PLAYER,
        SCR_ID_MOBILE_TV_PLAYER_SAVE_CONFIRM,
        mmi_mtv_player_save_confirm_screen_leave_proc);

    mmi_mtv_player_check_bg_snd();

#if defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_MTV_LANDSCAPE_SUPPORT__)
    mmi_frm_screen_rotate(mtv_player_p->ui_rotate);
#endif /* defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_MTV_LANDSCAPE_SUPPORT__) */

    if (RECORDER_STATE_IN(MTV_RECORDER_SAVE_CONFIRM))
    {
        str_id = STR_ID_MOBILE_TV_PLAYER_SAVE_RECORDING;
    }
    else
    {
        str_id = STR_ID_MOBILE_TV_PLAYER_SAVE_UNSAVED_RECORDING;
    }

    /* Call enable before showCategory, call change after showCategory */
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory66Screen(
        STR_ID_MOBILE_TV_PLAYER_APP_NAME,
        GetRootTitleIcon(MAIN_MENU_MULTIMEDIA_MENUID),
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU8) GetString(str_id),
        mmi_get_event_based_image(MMI_EVENT_QUERY),
        guiBuffer);

    SetRightSoftkeyFunction(mmi_mtv_player_enter_deleting_screen, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_mtv_player_enter_saving_screen, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mtv_player_enter_saving_screen, KEY_EVENT_UP);
#endif /* __MMI_MTV_RECORD_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_check_storage
 * DESCRIPTION
 *  mmi_mtv_player_check_storage
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 #ifndef __ATV_NO_PHONE_STORAGE__
 mmi_event_notify_enum mmi_mtv_player_check_storage(MMI_BOOL restore, U16 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_notify_enum event_type = MMI_EVENT_SUCCESS;
    S32 video_ret = FS_NO_ERROR, photo_ret = FS_NO_ERROR, err_ret;
    CHAR tmp_filepath[SRV_FMGR_PATH_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef   __MMI_MTV_RECORD_SUPPORT__
    memset(mtv_player_p->storage_filepath , 0, SRV_FMGR_PATH_BUFFER_SIZE);
#endif
    mtv_player_p->prev_storage_status = mtv_player_p->storage_status;

    /* check storage */
    if (mmi_mtv_player_check_and_restore_valid_drv(restore, storage))
    {
    #if defined(__MMI_MTV_RECORD_SUPPORT__)
        /* drv is valid, create video directory */
        mmi_mtv_player_get_storage_file_path(storage, mtv_player_p->storage_filepath, MTV_PLAYER_STORAGE_PATH_VIDEO);
        video_ret = mmi_mtv_player_create_file_dir(mtv_player_p->storage_filepath);
    #endif
    #if defined(__MMI_MTV_SNAPSHOT_SUPPORT__)
        /* drv is valid, create video directory */
        mmi_mtv_player_get_storage_file_path(storage, tmp_filepath, MTV_PLAYER_STORAGE_PATH_PHOTO);
        photo_ret = mmi_mtv_player_create_file_dir(tmp_filepath);
    #endif
        if (video_ret == FS_NO_ERROR && photo_ret == FS_NO_ERROR)
        {
            mtv_player_p->storage_status = MTV_PLAYER_STORAGE_OK;
            mtv_player_p->last_error = MDI_RES_MTV_SUCCEED;
        }
        else
        {
            mtv_player_p->storage_status = MTV_PLAYER_STORAGE_NOT_READY;
            err_ret = (video_ret == FS_NO_ERROR) ? photo_ret : video_ret;
            mtv_player_p->err_str_id = srv_fmgr_fs_error_get_string_and_popup_type(err_ret, (S32*)&event_type);
        }
    }
    else
    {
        /* drv no valid, means card is plugged out (or phone FAT corrupted) */
        mtv_player_p->storage_status = MTV_PLAYER_STORAGE_RESET;
        mtv_player_p->last_error = MDI_RES_MTV_ERR_STORAGE_NOT_READY;
        mtv_player_p->err_str_id = mdi_util_get_mdi_error_info(mtv_player_p->last_error, &event_type);
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_CHECK_STORAGE, restore, mtv_player_p->prev_storage_status, mtv_player_p->storage_status);

    return event_type;
}
 #else



 mmi_event_notify_enum mmi_mtv_player_check_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_notify_enum event_type = MMI_EVENT_SUCCESS;
    S32 video_ret = FS_NO_ERROR, photo_ret = FS_NO_ERROR, err_ret;
#if defined(__MMI_MTV_SNAPSHOT_SUPPORT__) && !defined (__ATV_NO_SNAPSHOT__)
    CHAR tmp_filepath[SRV_FMGR_PATH_BUFFER_SIZE];
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef   __MMI_MTV_RECORD_SUPPORT__
    memset(mtv_player_p->storage_filepath , 0, SRV_FMGR_PATH_BUFFER_SIZE);
#endif
#ifndef __ATV_NO_PHONE_STORAGE__
    mtv_player_p->prev_storage_status = mtv_player_p->storage_status;
#endif

    /* check storage */
    if (FS_NO_ERROR == FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM))
    {
    #if defined(__MMI_MTV_RECORD_SUPPORT__)
        /* drv is valid, create video directory */
        mmi_mtv_player_get_storage_file_path(SRV_FMGR_CARD_DRV, mtv_player_p->storage_filepath, MTV_PLAYER_STORAGE_PATH_VIDEO);
        video_ret = mmi_mtv_player_create_file_dir(mtv_player_p->storage_filepath);
    #endif
	#ifndef __ATV_NO_SNAPSHOT__
    #if defined(__MMI_MTV_SNAPSHOT_SUPPORT__)
        /* drv is valid, create video directory */
        mmi_mtv_player_get_storage_file_path(SRV_FMGR_CARD_DRV, tmp_filepath, MTV_PLAYER_STORAGE_PATH_PHOTO);
        photo_ret = mmi_mtv_player_create_file_dir(tmp_filepath);
    #endif
	#endif
        if (video_ret == FS_NO_ERROR && photo_ret == FS_NO_ERROR)
        {
            mtv_player_p->storage_status = MTV_PLAYER_STORAGE_OK;
            mtv_player_p->last_error = MDI_RES_MTV_SUCCEED;
        }
        else
        {
            mtv_player_p->storage_status = MTV_PLAYER_STORAGE_NOT_READY;
            err_ret = (video_ret == FS_NO_ERROR) ? photo_ret : video_ret;
            mtv_player_p->err_str_id =
                srv_fmgr_fs_error_get_string_and_popup_type(err_ret, (S32*)&event_type);
        }
    }
    else
    {
        /* drv no valid, means card is plugged out (or phone FAT corrupted) */

        mtv_player_p->storage_status = MTV_PLAYER_STORAGE_RESET;

        mtv_player_p->last_error = MDI_RES_MTV_ERR_STORAGE_NOT_READY;
        mtv_player_p->err_str_id = mdi_util_get_mdi_error_info(mtv_player_p->last_error, &event_type);

    }
	kal_prompt_trace(MOD_ENG, "[ATV] mmi_mtv_player_check_storage storage_status : %d", mtv_player_p->storage_status);
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_CHECK_STORAGE, restore, mtv_player_p->prev_storage_status, mtv_player_p->storage_status);

    return event_type;
}
 #endif


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_enable_record_function
 * DESCRIPTION
 *  mmi_mtv_player_enable_record_function
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_mtv_player_enable_record_function(void)
{
#if defined(__MMI_MTV_RECORD_SUPPORT__) || defined(__MMI_MTV_SNAPSHOT_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mtv_player_osd_cntx.record.status =  MTV_PLAYER_ICON_STATUS_ENABLE;
    g_mtv_player_osd_cntx_270.record.status =  MTV_PLAYER_ICON_STATUS_ENABLE;
#endif /* __MMI_MTV_RECORD_SUPPORT__ || __MMI_MTV_SNAPSHOT_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_disable_record_function
 * DESCRIPTION
 *  mmi_mtv_player_disable_record_function
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_mtv_player_disable_record_function(void)
{
#if defined(__MMI_MTV_RECORD_SUPPORT__) || defined(__MMI_MTV_SNAPSHOT_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mtv_player_osd_cntx.record.status =  MTV_PLAYER_ICON_STATUS_DISABLE;
    g_mtv_player_osd_cntx_270.record.status =  MTV_PLAYER_ICON_STATUS_DISABLE;

    /* Avoid snapshot when record key is released and avoid start record */
    if (mtv_player_p->touch_object == MTV_PLAYER_TOUCH_RECORD)
    {
        mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;
        gui_cancel_timer(mmi_mtv_player_record_start_record);
    }
#endif /* __MMI_MTV_RECORD_SUPPORT__ || __MMI_MTV_SNAPSHOT_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_enable_switch_channel_function
 * DESCRIPTION
 *  mmi_mtv_player_enable_switch_channel_function
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_mtv_player_enable_switch_channel_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mtv_player_osd_cntx.channel_next.status =  MTV_PLAYER_ICON_STATUS_ENABLE;
    g_mtv_player_osd_cntx_270.channel_next.status =  MTV_PLAYER_ICON_STATUS_ENABLE;
    g_mtv_player_osd_cntx.channel_prev.status =  MTV_PLAYER_ICON_STATUS_ENABLE;
    g_mtv_player_osd_cntx_270.channel_prev.status =  MTV_PLAYER_ICON_STATUS_ENABLE;


}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_disable_switch_channel_function
 * DESCRIPTION
 *  mmi_mtv_player_disable_switch_channel_function
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_mtv_player_disable_switch_channel_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mtv_player_osd_cntx.channel_next.status =  MTV_PLAYER_ICON_STATUS_DISABLE;
    g_mtv_player_osd_cntx_270.channel_next.status =  MTV_PLAYER_ICON_STATUS_DISABLE;
    g_mtv_player_osd_cntx.channel_prev.status =  MTV_PLAYER_ICON_STATUS_DISABLE;
    g_mtv_player_osd_cntx_270.channel_prev.status =  MTV_PLAYER_ICON_STATUS_DISABLE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_enable_fullscreen_function
 * DESCRIPTION
 *  mmi_mtv_player_enable_fullscreen_function
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_mtv_player_enable_fullscreen_function(void)
{
#if defined(__MMI_ATV_OSD_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* If user long presses fullscreen icon, then time-shift is enabled.
       Don't change full screen status as enable */
    if (mtv_player_p->active_osd_cntx_p->fullscreen.status == MTV_PLAYER_ICON_STATUS_CLICKED)
    {
        return;
    }

    g_mtv_player_osd_cntx.fullscreen.status =  MTV_PLAYER_ICON_STATUS_ENABLE;
    g_mtv_player_osd_cntx_270.fullscreen.status =  MTV_PLAYER_ICON_STATUS_ENABLE;
#endif /* defined(__MMI_ATV_OSD_SUPPORT__) */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_enable_lsk_function
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_mtv_player_enable_lsk_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mtv_player_osd_cntx.lsk.status =  MTV_PLAYER_ICON_STATUS_ENABLE;
    g_mtv_player_osd_cntx_270.lsk.status =  MTV_PLAYER_ICON_STATUS_ENABLE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_disable_lsk_function
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_mtv_player_disable_lsk_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mtv_player_osd_cntx.lsk.status = MTV_PLAYER_ICON_STATUS_DISABLE;
    g_mtv_player_osd_cntx_270.lsk.status = MTV_PLAYER_ICON_STATUS_DISABLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_disable_fullscreen_function
 * DESCRIPTION
 *  mmi_mtv_player_disable_fullscreen_function
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_mtv_player_disable_fullscreen_function(void)
{
#if defined(__MMI_ATV_OSD_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mtv_player_osd_cntx.fullscreen.status =  MTV_PLAYER_ICON_STATUS_DISABLE;
    g_mtv_player_osd_cntx_270.fullscreen.status =  MTV_PLAYER_ICON_STATUS_DISABLE;
#endif /*  __MMI_ATV_OSD_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_del_app_main_scr_hdlr
 * DESCRIPTION
 *  mmi_mtv_player_del_app_main_scr_hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 U8 mmi_mtv_player_del_app_main_scr_hdlr(void *dummy_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_DEL_APP_MAIN_SCR_HDLR);

    if (!PLAYER_STATE_IN(MTV_PLAYER_STOPPED))
    {
        mmi_mtv_player_player_enter_state(MTV_PLAYER_STOPPED);
    }
#ifdef   __MMI_MTV_RECORD_SUPPORT__
    if (RECORDER_STATE_IN(MTV_RECORDER_STOPPED))
#endif
    {
        if (!KERNEL_STATE_IN(MTV_KERNEL_CLOSED) && !KERNEL_STATE_IN(MTV_KERNEL_CLOSING))
        {
            mmi_mtv_player_kernel_enter_state(MTV_KERNEL_CLOSING);
        }

        /* hide status icon */
        wgui_status_icon_bar_hide_icon(STATUS_ICON_MTV_SIGNAL);
        StopTimer(MTV_PLAYER_UPDATE_SIGNAL_TIMER);

    }

    /* save setting */
    mmi_mtv_player_store_setting();
#if 0
/* under construction !*/
#endif
    /* unmute */
    mdi_audio_set_mute(MTV_VOLUME_TYPE, MMI_FALSE);

    if(MMI_TRUE == mtv_player_p->is_suspend)
    {
        /* resume background play only when exit mobile tv application */
        mdi_audio_clear_interrupt_callback();
        mdi_audio_resume_background_play();
        mtv_player_p->is_suspend = MMI_FALSE;
    }

    if (KERNEL_STATE_IN(MTV_KERNEL_CLOSING))
    {
        mtv_player_p->del_main_screen = MMI_TRUE;
        return MMI_TRUE;
    }
    else
    {
        mmi_frm_group_close(GRP_ID_MOBILE_TV_PLAYER);
        return MMI_FALSE;
    }
}



#ifdef __BT_SPK_VOL_CONTROL__
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_bt_volume_sync_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
MMI_BOOL mmi_mtv_player_bt_volume_sync_hdlr(U8 volume, MMI_BOOL is_mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_BT_VOLUME_SYNC_HDLR, volume, is_mute);

    /* Active screen is mobile tv main screen or channel list screen */
    if (active_screen == SCR_ID_MOBILE_TV_PLAYER_APP || active_screen == SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST)
    {
        mtv_player_p->setting.vol_level = volume;
        mdi_audio_set_volume(MTV_VOLUME_TYPE, (U8) MDI_AUD_VOL_EX_MUTE(mtv_player_p->setting.vol_level));
        mtv_player_p->setting.is_mute = KAL_FALSE;
#ifdef   __MMI_ATV_OSD_SUPPORT__
        /* Update OSD */
        if (active_screen == SCR_ID_MOBILE_TV_PLAYER_APP)
        {
	    mmi_mtv_player_reset_osd_by_rotate();

            mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
        }
#endif
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_base_screen_leave_proc
 * DESCRIPTION
 *  This function is the callback funcion for deleting idle notify screen
 * PARAMETERS
 *  p
 * RETURNS
 *  U8
 *****************************************************************************/
 mmi_ret mmi_mtv_player_base_screen_leave_proc(mmi_event_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (para->evt_id)
    {
        case EVT_ID_SCRN_GOBACK:
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        {
#ifdef __MM_DCM_SUPPORT__   
            //  for atv drv shares pool with ime
            if (MMI_TRUE == g_is_engine_paused)
            {
                mdi_mtv_resume_engine();
                g_is_engine_paused = MMI_FALSE;
//                if (!DCM_Isloaded(DYNAMIC_CODE_COMPRESS_CAMCAL))
//                {
//                    DCM_Load(DYNAMIC_CODE_COMPRESS_CAMCAL, 0,0);
//                }
            }
#endif
            ret = (MMI_BOOL)mmi_mtv_player_del_app_main_scr_hdlr(NULL);
            if (ret == MMI_TRUE)
            {
                return MMI_RET_ERR;
            }
            break;
        }
        default:
            break;
    }
    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_hw_not_ready_popup_proc
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
 mmi_ret mmi_mtv_player_hw_not_ready_popup_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            mmi_frm_group_close(GRP_ID_MOBILE_TV_PLAYER);
            break;
        }
        default:
        break;
    }

    return MMI_RET_OK;
}

static void mmi_mtv_player_interrupt_hdlr(mdi_result result, void *user_data)
{
    if (mmi_frm_group_get_top_parent_group_id(mmi_frm_group_get_active_id()) != GRP_ID_MOBILE_TV_PLAYER)
    {
        if(MMI_TRUE == mtv_player_p->is_suspend)
        {
		    mdi_audio_clear_interrupt_callback();
            mdi_audio_resume_background_play();
            mtv_player_p->is_suspend = MMI_FALSE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_enter_app_main
 * DESCRIPTION
 *  mobile tv player entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_enter_app_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    mmi_popup_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_mtv_player_is_in_background_call() && KERNEL_STATE_IN(MTV_KERNEL_CLOSED))
    {
        mmi_ucm_app_entry_error_message();
        return; /* return directly */
    }

    /* allocate memory from App-Based ASM */
    if (mtv_player_p->app_mem_pool==NULL)
    {
        mtv_player_p->app_mem_pool
            = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_MTV_PLAYER, MMI_MTV_PLAYER_APP_MEM_SIZE);

        if (mtv_player_p->app_mem_pool== NULL)
        {
            mmi_frm_appmem_prompt_to_release_mem(
                APPLIB_MEM_AP_ID_MTV_PLAYER,
                IMG_ID_MOBILE_TV_PLAYER_APP_ICON,
                MMI_MTV_PLAYER_APP_MEM_SIZE,
                mmi_mtv_player_app_mem_success_callback);
            return;
        }
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_ENTER_APP_MAIN);

    ret = mmi_frm_scrn_enter(
            GRP_ID_MOBILE_TV_PLAYER,
            SCR_ID_MOBILE_TV_PLAYER_APP_BASE,
            NULL,
            mmi_mtv_player_enter_app_main,
            MMI_FRM_UNKNOW_SCRN);

    if (ret == MMI_FALSE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_VAL1, ret, __LINE__);
        return;
    }

    mmi_frm_scrn_set_leave_proc(
        GRP_ID_MOBILE_TV_PLAYER,
        SCR_ID_MOBILE_TV_PLAYER_APP_BASE,
        mmi_mtv_player_base_screen_leave_proc);

    ShowCategoryDummyScreen();
#ifdef __MMI_MATV_ESD_RECOVERY_SUPPORT__
#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)
    SetProtocolEventHandler(mmi_mtv_player_send_msg_to_restart,MSG_ID_MATV_ESD_TIME_OUT_IND);
#endif
#endif/*__MMI_MATV_ESD_RECOVERY_SUPPORT__*/

    if (KERNEL_STATE_IN(MTV_KERNEL_CLOSING))
    {
        return;
    }


    wgui_status_icon_bar_set_icon_display(STATUS_ICON_MTV_SIGNAL);
    wgui_status_icon_bar_change_icon_level(STATUS_ICON_MTV_SIGNAL, (U8) mtv_player_p->signal_strength);

#ifdef   __MMI_ATV_OSD_SUPPORT__
    /* reset ui rotate when entering app again */
    mtv_player_p->ui_rotate = MMI_FRM_SCREEN_ROTATE_0;
#endif

    /* load mtv setting */
    mmi_mtv_player_load_setting();

#ifndef __ATV_NO_SNAPSHOT__

#if defined(__MMI_MTV_RECORD_SUPPORT__) || defined(__MMI_MTV_SNAPSHOT_SUPPORT__)
#ifndef __ATV_NO_PHONE_STORAGE__
#ifdef   __MMI_MTV_RECORD_SUPPORT__
    if (!RECORDER_STATE_IN(MTV_RECORDER_STOPPED))
    {
        /* check storage and don't restore */
        mmi_mtv_player_check_storage(MMI_FALSE, mtv_player_p->setting.storage);
    }
    else
#endif
    {
        /* check storage and restore */
        mmi_mtv_player_check_storage(MMI_TRUE, mtv_player_p->setting.storage);
    }
#else
    mmi_mtv_player_check_storage();
#endif
#endif /* __MMI_MTV_RECORD_SUPPORT__ || __MMI_MTV_SNAPSHOT_SUPPORT__ */
#endif
    mtv_player_p->is_suspend = MMI_FALSE;

    mmi_mtv_player_check_bg_snd();

    if (KERNEL_STATE_IN(MTV_KERNEL_CLOSED))
    {
        MDI_RESULT ret ;

        /* Create ADM */
        mmi_mtv_player_create_adm();

        mmi_mtv_player_alloc_adm_structure();

        ret = mmi_mtv_player_kernel_enter_state(MTV_KERNEL_OPENED);

        /* reset application variable */

        mtv_player_p->go_back_history = MMI_FALSE;
        mtv_player_p->del_main_screen = MMI_FALSE;
        mtv_player_p->signal_strength = 0;
        mtv_player_p->option_menu_gid = GRP_ID_INVALID;
        mtv_player_p->cl_option_menu_gid = GRP_ID_INVALID;

        switch (ret)
        {
        case MDI_RES_MTV_SUCCEED:

            if (mtv_player_p->setting.is_channel_list_init == MMI_FALSE)
            {
                mmi_mtv_player_entry_band_screen();
            }
            else
            {
                mmi_mtv_player_enter_scan_channel();
            }
            break;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        default:
            {
                mmi_popup_property_init(&arg);
                arg.callback = mmi_mtv_player_hw_not_ready_popup_proc;
                arg.parent_id = GRP_ID_MOBILE_TV_PLAYER;
                mmi_popup_display(
                    (WCHAR*)GetString(STR_ID_MOBILE_TV_PLAYER_NOTIFY_HW_NOT_READY),
                    MMI_EVENT_FAILURE,
                    &arg);

                mmi_mtv_player_free_adm_structure();
                /* Delete adm */
                mmi_mtv_player_delete_adm();

                if (mtv_player_p->app_mem_pool != NULL)
                {
                    /* free app-based memory */
                    applib_mem_ap_free((void*)mtv_player_p->app_mem_pool);
                    mtv_player_p->app_mem_pool = NULL;
                }
                return;
            }
        }

    }
    /* should back from (save_unsave_recording) or (discard_unsave_recording) */
    else if (KERNEL_STATE_IN(MTV_KERNEL_OPENED))
    {
        if (mtv_player_p->setting.is_channel_list_init == MMI_FALSE)
        {
            mmi_mtv_player_entry_band_screen();
        }
        else
        {
            mmi_mtv_player_enter_scan_channel();
        }
    }
    /* (Recorder is at RECORD or SAVING state) or (back from video recorder's save confirm or saving screen) */
    else if (KERNEL_STATE_IN(MTV_KERNEL_READY))
    {
        mmi_mtv_player_entry_channel_list_screen();
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_clear_preview_layer
 * DESCRIPTION
 *  clear preview layer hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_clear_preview_layer(void)
{
    if (mtv_player_p->display_layer_handle != GDI_NULL_HANDLE)
    {
        mdi_util_hw_layer_switch_to_sw_layer(mtv_player_p->display_layer_handle);
        gdi_layer_push_and_set_active(mtv_player_p->display_layer_handle);
        gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_record_start_record
 * DESCRIPTION
 *  start record timer expired hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_mtv_player_record_start_record(void)
{
#ifdef __MMI_MTV_RECORD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (RECORDER_STATE_IN(MTV_RECORDER_STOPPED))
    {
        mtv_player_p->is_capture = MMI_FALSE;

        mtv_player_p->active_osd_cntx_p->record.status  = MTV_PLAYER_ICON_STATUS_ENABLE;
        mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;

    #ifdef __MDI_MTV_BLOCK_PHONE_DISK_RECORD__
        if (mtv_player_p->setting.storage == SRV_FMGR_PUBLIC_DRV)
        {
            mmi_mtv_player_display_popup(
                STR_ID_MOBILE_TV_PLAYER_NOTIFY_SWITCH_TO_MEM_CARD,
                MMI_EVENT_FAILURE);
            return;
        }
    #endif /*__MDI_MTV_BLOCK_PHONE_DISK_RECORD__ */
    #ifdef __MMI_BT_SUPPORT__
        if (mmi_bt_is_receiving())
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_VAL1, 1, __LINE__);
            mmi_mtv_player_display_popup(
                STR_ID_MOBILE_TV_PLAYER_NOTIFY_BT_IS_WORKING,
                MMI_EVENT_FAILURE);
            return;
        }
    #endif /* __MMI_BT_SUPPORT__ */
    #if defined(__MMI_MTV_A2DP_SUPPORT__)
        if (mmi_mtv_player_is_output_to_bt())
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_VAL1, 1, __LINE__);
            mmi_mtv_player_display_popup(
                STR_ID_MOBILE_TV_PLAYER_NOTIFY_BT_IS_WORKING,
                MMI_EVENT_FAILURE);
            return;
        }
    #endif /* __MMI_MTV_A2DP_SUPPORT__ */
    #if defined(__MMI_BT_AUDIO_SUPPORT__)
        if (mmi_bt_sco_is_connected(MMI_BT_SCO_HFP_SCO))
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_VAL1, 1, __LINE__);
            mmi_mtv_player_display_popup(
                STR_ID_MOBILE_TV_PLAYER_NOTIFY_BT_IS_WORKING,
                MMI_EVENT_FAILURE);
            return;
        }
    #endif /* __MMI_BT_AUDIO_SUPPORT__ */

        mtv_player_p->last_error = mmi_mtv_player_recorder_enter_state(MTV_RECORDER_RECORD);
        if (mtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
        {
            mmi_mtv_player_display_failure_popup(mtv_player_p->last_error);
            return;
        }
        else
        {
            U16 active_screen_id;
            active_screen_id = mmi_frm_scrn_get_active_id();
            if (active_screen_id == SCR_ID_MOBILE_TV_PLAYER_APP)
            {
                mmi_mtv_player_register_key_hdlr();
            }
        }
#ifdef   __MMI_ATV_OSD_SUPPORT__
	mmi_mtv_player_reset_osd_by_rotate();

        mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif
    }
#endif /* __MMI_MTV_RECORD_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_get_next_filename
 * DESCRIPTION
 *  get next file name for jpeg image
 * PARAMETERS
 *  file_buf_p      [IN]
 *  a(?)            [OUT]       Next filename
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_get_next_filename(CHAR *filename, CHAR *file_path_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR buffer[25];
    CHAR UCS2_buffer[50];
    CHAR UCS2_alpha[10];
    U16 filename_seq_no;
    U16 alpha_count;
    U16 alpha_index;
    FS_HANDLE file_handle;
    U16 file_check = 0;
    S32 length;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    filename_seq_no = mtv_player_p->setting.filename_seq_no;
    if (filename_seq_no == 0xffff)
    {
        filename_seq_no = 1;    /* init value */
    }
    else
    {
        filename_seq_no++;
        if (filename_seq_no > 9999) /* more than 4 digits */
        {
            filename_seq_no = 1;
        }
    }
    length = mmi_ucs2strlen(file_path_p);

    alpha_count = 'Z' - 'A' + 1;
    alpha_index = 0;

    sprintf((CHAR*) buffer, "TV%04d", filename_seq_no);
    mmi_asc_to_ucs2((CHAR*) UCS2_buffer, (CHAR*) buffer);

    while (1)
    {
        sprintf((CHAR*) buffer, "%c", 'A' + alpha_index);
        mmi_asc_to_ucs2((CHAR*) UCS2_alpha, (CHAR*) buffer);

        mmi_ucs2cpy(filename, UCS2_buffer);
        mmi_ucs2cat(filename, UCS2_alpha);
        mmi_ucs2cat(filename, (CHAR*) L".jpg");

        file_path_p[length << 1] = file_path_p[(length << 1) + 1] = 0;
        mmi_ucs2cat((CHAR*) file_path_p, (CHAR*) filename);

        file_handle = FS_Open((U16*) file_path_p, FS_READ_ONLY);

        if (file_handle >= 0)
        {
            /* file exist */
            FS_Close(file_handle);
            alpha_index++;
        }
        else
        {
            mtv_player_p->setting.filename_seq_no = filename_seq_no;
            mmi_mtv_player_store_setting();
            return;
        }

        /* exit condition - will get a IMGXXXXZ.jpg as file name */
        if (alpha_index >= alpha_count )
        {
#if 0
/* under construction !*/
#endif
            alpha_index = 0;
            filename_seq_no++;
            file_check++;
            if (filename_seq_no > 9999) /* more than 4 digits */
            {
                filename_seq_no = 1;
            }
            sprintf((CHAR*) buffer, "TV%04d", filename_seq_no);
            mmi_asc_to_ucs2((CHAR*) UCS2_buffer, (CHAR*) buffer);

            /* check if number of files are > 9999 * 26*/
            if (file_check >= 9999)
                return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_snapshot
 * DESCRIPTION
 *  snapshot screen.
 * PARAMETERS
 *  inMsg       [?]
 * RETURNS
 *
 *****************************************************************************/
 MMI_BOOL mmi_mtv_player_snapshot(void)
{
#ifndef __ATV_NO_SNAPSHOT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL need_to_resume_play = MMI_FALSE;
    CHAR filename[50] = {0};
    CHAR buf_pathname[SRV_FMGR_PATH_BUFFER_SIZE] = {0};
    gdi_handle snap_handle = GDI_LAYER_EMPTY_HANDLE;
    S32 result;
    MDI_RESULT ret = MDI_RES_MTV_FAILED;
    S32 event_type;
    PU8 snap_buf = NULL;
    S32 width, height;
    gdi_color_format format;
    MMI_BOOL val = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_mtv_player_is_in_background_call())
    {
        mmi_mtv_player_display_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL, MMI_EVENT_FAILURE);
        return  MMI_FALSE;
    }

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        snap_handle = mtv_player_p->display_layer_handle;
    }
    else
    {
        /* get width, height, format */
        gdi_layer_push_and_set_active(mtv_player_p->display_layer_handle);
        gdi_layer_get_dimension(&width, &height);
        gdi_layer_get_color_format(&format);
        gdi_layer_pop_and_restore_active();

        /* Allocate buffer & layer handle */
        snap_buf = (PU8) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(
                            mtv_player_p->adm_pool_id,
                            MMI_MTV_PLAYER_SNAPSHOT_BUFFER_SIZE);
        ASSERT(snap_buf != NULL);

        gdi_layer_create_using_outside_memory(
            0, 0, width, height, &snap_handle, snap_buf,
            MMI_MTV_PLAYER_SNAPSHOT_BUFFER_SIZE);
        ASSERT(snap_handle != GDI_LAYER_EMPTY_HANDLE);

        gdi_layer_push_and_set_active(snap_handle);
        gdi_layer_set_color_format(format);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();

        /* get snapshot */
        ret = mdi_mtv_get_hw_layer_buffer_content(
                snap_handle, snap_buf, MMI_MTV_PLAYER_SNAPSHOT_BUFFER_SIZE);
        if (ret != MDI_RES_MTV_SUCCEED)
        {
            mmi_mtv_player_display_popup(STR_ID_MOBILE_TV_PLAYER_NOTIFY_FAILED_TO_SNAPSHOT, MMI_EVENT_FAILURE);
            goto release;
        }
    }

    /* Pause the player */
    if (PLAYER_STATE_IN(MTV_PLAYER_PLAY))
    {
        need_to_resume_play = MMI_TRUE;

        mtv_player_p->last_error = mmi_mtv_player_player_enter_state(MTV_PLAYER_STOPPED);

        if (mtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
        {
            mmi_mtv_player_display_failure_popup(mtv_player_p->last_error);
            goto release;
        }
    }

    mmi_mtv_player_get_storage_file_path(
        mtv_player_p->setting.storage, buf_pathname, MTV_PLAYER_STORAGE_PATH_PHOTO);

    /* check if storage path is valid or not */
    result = FS_GetDevStatus((U16)buf_pathname[0] ,FS_MOUNT_STATE_ENUM);
    if (result == FS_NO_ERROR)
    {
        /* if drv is valid, check if the folder is crated or not */
        result = mmi_mtv_player_create_file_dir(buf_pathname);
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_VAL1, result, __LINE__);
        /* Change return value to get the correct error string. */
        result = FS_DRIVE_NOT_FOUND;
    }

    if (result == FS_NO_ERROR)
    {
        mmi_mtv_player_get_next_filename(filename, buf_pathname);
        /* get snapshot */
        ret = mdi_mtv_get_snapshot(
                mtv_player_p->mtv_handle, snap_handle, (WCHAR*)buf_pathname);
    }

    /* Display error popup */
    if (result != FS_NO_ERROR)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_VAL1, result, __LINE__);

        mtv_player_p->err_str_id = srv_fmgr_fs_error_get_string_and_popup_type(result, &event_type);
        mmi_mtv_player_display_popup(mtv_player_p->err_str_id, (mmi_event_notify_enum)event_type);
        goto release;
    }
    else if (ret != MDI_RES_MTV_SUCCEED)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_VAL1, ret, __LINE__);
        if (ret == MDI_RES_MTV_ERR_DISC_FULL)
        {
            mmi_mtv_player_display_popup(STR_GLOBAL_NOT_ENOUGH_MEMORY, MMI_EVENT_FAILURE);
        }
        else
        {
            mmi_mtv_player_display_popup(STR_ID_MOBILE_TV_PLAYER_NOTIFY_FAILED_TO_SNAPSHOT, MMI_EVENT_FAILURE);
        }
        goto release;
    }
    else
    {
        /* Resume */
        if(need_to_resume_play == MMI_TRUE)
        {
            #if defined(__MMI_MTV_A2DP_SUPPORT__)
                if (mmi_mtv_player_is_output_to_bt() && !mmi_mtv_player_is_in_background_call())
                {
                    mtv_player_p->last_error = mmi_mtv_player_player_enter_state(MTV_PLAYER_BT_CONNECT);
                }
                else
                {
                    mtv_player_p->last_error = mmi_mtv_player_player_enter_state(MTV_PLAYER_PLAY);
                }
            #else
                mtv_player_p->last_error = mmi_mtv_player_player_enter_state(MTV_PLAYER_PLAY);
            #endif

            if (mtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
            {
                mmi_mtv_player_display_failure_popup(mtv_player_p->last_error);
                goto release;
            }
        #if defined(__MMI_MTV_A2DP_SUPPORT__)
            if (PLAYER_STATE_IN(MTV_PLAYER_BT_CONNECT))
            {
#ifdef   __MMI_ATV_OSD_SUPPORT__
                if (mtv_player_p->fullscr_osd_opacity != 0)
                {
#endif
                    /* For snapshot icon */
                    mmi_mtv_player_register_key_hdlr();
#ifdef   __MMI_ATV_OSD_SUPPORT__
                    mmi_mtv_player_draw_osd();
                    mmi_mtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
                }
#endif
            }
        #endif
        }

    }
    val = MMI_TRUE;

release:
    if (mtv_player_p->ui_rotate != MMI_FRM_SCREEN_ROTATE_0)
    {
        if (snap_handle != GDI_LAYER_EMPTY_HANDLE)
        {
            gdi_layer_free(snap_handle);
            snap_handle = GDI_LAYER_EMPTY_HANDLE;
        }

        if (snap_buf != NULL)
        {
            kal_adm_free(mtv_player_p->adm_pool_id, (void*)snap_buf);
            snap_buf = NULL;
        }
    }
    return val;
#else
    return MMI_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_is_bg_running
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
MMI_BOOL mmi_mtv_player_is_bg_running(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef   __MMI_MTV_RECORD_SUPPORT__
    if (!RECORDER_STATE_IN(MTV_RECORDER_STOPPED))
        return MMI_TRUE;
    else
#endif
        return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_popup_mtv_is_running
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void mmi_mtv_player_popup_mtv_is_running(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_popup_display_simple(
        (WCHAR*) GetString(STR_ID_MOBILE_TV_PLAYER_NOTIFY_BG_RUNNING),
        MMI_EVENT_FAILURE,
        GRP_ID_MOBILE_TV_PLAYER,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_get_notify_bg_running_str_id
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
U16 mmi_mtv_player_get_notify_bg_running_str_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return STR_ID_MOBILE_TV_PLAYER_NOTIFY_BG_RUNNING;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_get_error_info
 * DESCRIPTION
 *  Function to get the error information includes popup type and string
 * PARAMETERS
 *  error_result:   [IN]    error result type
 *  popup_type:     [OUT]   get the error popup type
 * RETURNS
 *  Get the error popup string id.
 *****************************************************************************/
MMI_STR_ID mmi_mtv_player_get_error_info(S32 error_result, mmi_event_notify_enum* popup_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID  str_id = STR_ID_MOBILE_TV_PLAYER_NOTIFY_BG_RUNNING;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *popup_type = MMI_EVENT_FAILURE;
    if (error_result == MMI_MTV_PLAYER_ERR_IS_BG_RUNNING)
    {
        str_id = STR_ID_MOBILE_TV_PLAYER_NOTIFY_BG_RUNNING;
    }
    return str_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_sw_rotate
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
void mmi_mtv_player_counter_clockwise_rotate(
    U8* pDst,
    U8* pSrc,
    U32 const dst_width,
    U32 const dst_height,
    gdi_rect_struct *dest_rect)
{
#ifdef __MMI_ATV_OSD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j;
    U8 *dst_point, *src_point;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = dest_rect->y1; i < dest_rect->y2 ; i++)
    {
        for (j = dest_rect->x1; j < dest_rect->x2; j++)
        {
            dst_point = pDst + (i * dst_width * 2) + (j * 2);
            src_point = pSrc + (j * dst_height * 2) + ((dst_height - i - 1) * 2);

            *dst_point = *src_point;
            *(dst_point + 1) = *(src_point + 1);
        }
    }
#endif /* __MMI_ATV_OSD_SUPPORT__ */
}

#ifndef GDI_USING_2D_ENGINE_V3
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_sw_rotate
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
void mmi_mtv_player_sw_rotate(
    U8* pDst,
    U8* pSrc,
    U32 const src_width,
    U32 const src_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < src_height ; i++)
    {
        for (j = 0; j < src_width; j++)
        {
            *(pDst+(j*src_height*2)+((src_height-i-1)*2)) = *(pSrc++);
            *(pDst+(j*src_height*2)+((src_height-i-1)*2+1)) = *(pSrc++);
        }
    }
}

#endif

#if defined(__MMI_MTV_RECORD_SUPPORT__)

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_prepare_record_size_list
 * DESCRIPTION
 *  get record size list
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
void mmi_mtv_player_prepare_record_size_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mdi_mtv_recorder_size_enum list[MDI_MTV_RECORDER_SIZE_COUNT];
    MMI_BOOL supported = MMI_FALSE;
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(MDI_MTV_RECORDER_SIZE_COUNT <= MMI_MOBILE_TV_PLAYER_RECORD_SIZE_ADJ_COUNT);

    /* Query supported record num and list */
    mdi_mtv_get_supported_record_size(mtv_player_p->mtv_handle, &mtv_player_p->record_size_num, list);
    ASSERT(mtv_player_p->record_size_num > 0 &&
           mtv_player_p->record_size_num <= MDI_MTV_RECORDER_SIZE_COUNT);

    /* Assign record size string */
    for (i = 0; i < mtv_player_p->record_size_num; i ++)
    {
        switch (list[i])
        {
            case MDI_MTV_RECORDER_SIZE_QCIF:
                mtv_player_setting_p->record_size_str[i] =
                    GetString(STR_ID_MOBILE_TV_PLAYER_SETTING_176X144);
                break;
            case MDI_MTV_RECORDER_SIZE_QVGA:
                mtv_player_setting_p->record_size_str[i] =
                    GetString(STR_ID_MOBILE_TV_PLAYER_SETTING_320X240);
                break;
            case MDI_MTV_RECORDER_SIZE_HVGA:
                mtv_player_setting_p->record_size_str[i] =
                    GetString(STR_ID_MOBILE_TV_PLAYER_SETTING_480X320);
                break;
            default:
                ASSERT(0);
                break;
        }

        if (mtv_player_p->setting.record_size == list[i])
        {
            supported = MMI_TRUE;
        }
    }

    if (!supported)
    {
        mtv_player_p->setting.record_size =
            mmi_mtv_player_get_record_size(mtv_player_p->record_size_num - 1);
        mdi_mtv_set_record_size(mtv_player_p->setting.record_size);
        WriteRecord(NVRAM_EF_MOBILE_TV_PLAYER_SETTING_LID, 1, (void*)&mtv_player_p->setting, NVRAM_EF_MOBILE_TV_PLAYER_SETTING_SIZE, &error);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_get_record_size
 * DESCRIPTION
 *  get record size list
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
mdi_mtv_recorder_size_enum mmi_mtv_player_get_record_size(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(idx < mtv_player_p->record_size_num);


    str = mtv_player_setting_p->record_size_str[idx];
    if (str == GetString(STR_ID_MOBILE_TV_PLAYER_SETTING_176X144))
    {
        return MDI_MTV_RECORDER_SIZE_QCIF;
    }
    else if (str == GetString(STR_ID_MOBILE_TV_PLAYER_SETTING_320X240))
    {
        return MDI_MTV_RECORDER_SIZE_QVGA;
    }
    else if (str == GetString(STR_ID_MOBILE_TV_PLAYER_SETTING_480X320))
    {
        return MDI_MTV_RECORDER_SIZE_HVGA;
    }
    else
    {
        ASSERT(0);
        return MDI_MTV_RECORDER_SIZE_QVGA;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_get_record_size_index
 * DESCRIPTION
 *  get record size list
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
S32 mmi_mtv_player_get_record_size_index(mdi_mtv_recorder_size_enum size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *str;
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < mtv_player_p->record_size_num; i ++)
    {
        str = mtv_player_setting_p->record_size_str[i];
        if (str == GetString(STR_ID_MOBILE_TV_PLAYER_SETTING_176X144) &&
            size == MDI_MTV_RECORDER_SIZE_QCIF)
        {
	    break;
        }
        else if (str == GetString(STR_ID_MOBILE_TV_PLAYER_SETTING_320X240) &&
                 size == MDI_MTV_RECORDER_SIZE_QVGA)
        {
            break;
        }
        else if (str == GetString(STR_ID_MOBILE_TV_PLAYER_SETTING_480X320) &&
                 size == MDI_MTV_RECORDER_SIZE_HVGA)
        {
            break;
        }
    }


    ASSERT(i < mtv_player_p->record_size_num);
    return i;
}

#endif /* __MMI_MTV_RECORD_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_prepare_audio_mode_list
 * DESCRIPTION
 *  get audio mode list
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
#ifndef __DISABLE_MTV_SETTINGS__
 void mmi_mtv_player_prepare_audio_mode_list(U32 *num, U32 *highlighted_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mtv_player_service_info_struct *info_ptr;
    S32 index;
    S32 mode_num;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    *num = *highlighted_index = 0;

    if (!KERNEL_STATE_IN(MTV_KERNEL_READY))
    {
        return;
    }

    info_ptr = mmi_mtv_player_get_active_channel_ptr();
    if (info_ptr->supported_audio_mode == 0)
    {
        return;
    }

    *num = 0;
    mode_num = sizeof(mmi_atv_aud_mode)/sizeof(mmi_atv_aud_mode[0]);
    for (index = 0; index < mode_num; index ++)
    {
        if ((info_ptr->supported_audio_mode & mmi_atv_aud_mode[index]) != 0)
        {
            mtv_player_setting_p->aud_mode_str[*num] =
                GetString(STR_ID_ATV_AUDIO_MODE_START + 1 + index);

            if ((info_ptr->audio_mode & mmi_atv_aud_mode[index]) != 0)
            {
                *highlighted_index = *num;
            }
            (*num) ++;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_get_audio_mode_index
 * DESCRIPTION
 *  get audio mode list
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 S32 mmi_mtv_player_get_audio_mode_index(S32 selected_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0, mode_num;
    CHAR *str_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    str_ptr = mtv_player_setting_p->aud_mode_str[selected_index];

    mode_num = sizeof(mmi_atv_aud_mode)/sizeof(mmi_atv_aud_mode[0]);
    for (index = 0; index < mode_num; index ++)
    {
        if (str_ptr == GetString((U16)STR_ID_ATV_AUDIO_MODE_START + 1 + index))
        {
            break;
        }
    }

    return index;
}
#endif/*__DISABLE_MTV_SETTINGS__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_auto_select_band
 * DESCRIPTION
 *  auto select band
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 U8 mmi_mtv_player_select_band(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 band;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    band = mmi_atv_country_map[mtv_player_p->setting.band];

    return band;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_delete_channel
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 #ifndef __DISABLE_MTV_DELETE_CHANNEL__
 void mmi_mtv_player_delete_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    mtv_player_service_info_struct *info_ptr;
    U32 service_id;
    S32 idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Stop service */
    if ((KERNEL_STATE_IN(MTV_KERNEL_READY) || KERNEL_STATE_IN(MTV_KERNEL_INIT)))
    {
        ASSERT(PLAYER_STATE_IN(MTV_PLAYER_STOPPED));

        ret = mmi_mtv_player_kernel_enter_state(MTV_KERNEL_OPENED);

        ASSERT(ret == MDI_RES_MTV_SUCCEED);
    }

    /* Find the deleted channel */
    idx = mtv_player_p->setting.selected_channel;
    info_ptr = &mtv_player_p->services[idx];
    service_id = info_ptr->service_id;

    ret = mdi_mtv_delete_channel(mtv_player_p->mtv_handle, service_id);

    if (ret != MDI_RES_MTV_SUCCEED)
    {
        mmi_mtv_player_display_failure_popup(ret);
        if (mtv_player_p->cl_option_menu_gid != GRP_ID_INVALID)
        {
            cui_menu_close(mtv_player_p->cl_option_menu_gid);
            mtv_player_p->cl_option_menu_gid = GRP_ID_INVALID;
        }
        return;
    }

    /* Arrange service array and decrease num_services by one */
    mmi_mtv_player_remove_active_service();

    if (mtv_player_p->num_services > 0 &&
        mtv_player_p->setting.selected_channel == mtv_player_p->num_services)
    {
        mtv_player_p->setting.selected_channel --;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_SELECTED_SERVICE,
            mtv_player_p->setting.selected_channel, __LINE__);

    }

    ClearInputEventHandler(MMI_DEVICE_KEY);
/*
    mmi_popup_display_simple(
        (WCHAR*) GetString(STR_GLOBAL_DELETED),
        MMI_EVENT_SUCCESS,
        GRP_ID_MOBILE_TV_PLAYER,
        NULL);
*/
    mmi_frm_scrn_close_active_id();
    if (mtv_player_p->cl_option_menu_gid != GRP_ID_INVALID)
    {
        cui_menu_close(mtv_player_p->cl_option_menu_gid);
        mtv_player_p->cl_option_menu_gid = GRP_ID_INVALID;
    }

}
#endif/*__DISABLE_MTV_DELETE_CHANNEL__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_get_service_list
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_get_service_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    mdi_mtv_service_info_struct service_info;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < MMI_MTV_MAX_SERVICES; i ++)
    {
        ret = mdi_mtv_get_service_by_index(mtv_player_p->mtv_handle, i, &service_info);
        if (ret != MDI_RES_MTV_SUCCEED)
        {
            break;
        }
        mmi_mtv_player_service_found_hdlr(&service_info, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_highlight_input_method
 * DESCRIPTION
 *  mobile tv player menu item highlight handler for input method
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_highlight_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_rename_channel
 * DESCRIPTION
 *  rename channel
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
#ifndef __DISABLE_MTV_RENAME_CHANNEL__
  MMI_BOOL mmi_mtv_player_rename_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    mtv_player_service_info_struct *info_ptr;
    U32 service_id;
    S32 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_ucs2strlen((CHAR*)mtv_player_p->edit_service_name) == 0)
    {
        mmi_popup_display_simple(
            (WCHAR*) GetString(STR_GLOBAL_INVALID_INPUT),
            MMI_EVENT_FAILURE,
            GRP_ID_MOBILE_TV_PLAYER,
            NULL);
         return MMI_FALSE;
    }
    idx = mtv_player_p->setting.selected_channel;
    info_ptr = &mtv_player_p->services[idx];
    service_id = info_ptr->service_id;
     
    ret = mdi_mtv_rename_channel(mtv_player_p->mtv_handle, service_id, (CHAR*)mtv_player_p->edit_service_name);
    ret = MDI_RES_MTV_SUCCEED;
     
    if (ret == MDI_RES_MTV_SUCCEED)
    {
        mmi_ucs2cpy((CHAR*)info_ptr->service_name, (CHAR*)mtv_player_p->edit_service_name);
     
      //  mmi_mtv_player_display_popup(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS);
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        mmi_popup_display_simple(
            (WCHAR*) GetString(STR_ID_MOBILE_TV_PLAYER_NOTIFY_FAIL_TO_RENAME),
            MMI_EVENT_FAILURE,
            GRP_ID_MOBILE_TV_PLAYER,
            NULL);
    }
    return MMI_TRUE;

    
}


 


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_entry_rename_screen
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_entry_rename_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mtv_player_service_info_struct *info_ptr;
    MMI_ID cui_id;
    S32 idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MM_DCM_SUPPORT__
    //  for atv drv shares pool with ime
    if (MMI_FALSE == g_is_engine_paused)
    {
        mdi_mtv_pause_engine();  //  add for atcv drv dcm
        g_is_engine_paused = MMI_TRUE;
//        if (DCM_Isloaded(DYNAMIC_CODE_COMPRESS_CAMCAL))
//        {
//            DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMCAL);
//        }
    }
#endif

    cui_id = cui_fseditor_create(GRP_ID_MOBILE_TV_PLAYER);

    cui_fseditor_set_title(cui_id, STR_GLOBAL_EDIT, GetRootTitleIcon(MAIN_MENU_MULTIMEDIA_MENUID));

    idx = mtv_player_p->setting.selected_channel;
    info_ptr = &mtv_player_p->services[idx];
    mmi_ucs2cpy((CHAR*)mtv_player_p->edit_service_name, (CHAR*)info_ptr->service_name);

    cui_fseditor_set_input_method(
        cui_id,
        IMM_INPUT_TYPE_SENTENCE,
        NULL,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);

    /* editor cui uses its own buffer when buffer length is less than 256 */
    cui_fseditor_set_text(
        cui_id,
        mtv_player_p->edit_service_name,
        (MMI_MTV_NAME_STR_LENGTH + 1) <<1,
        MMI_MTV_NAME_STR_LENGTH);

    cui_fseditor_run(cui_id);
}
#endif/*__DISABLE_MTV_RENAME_CHANNEL__*/

#ifdef __MMI_AP_DCM_MATV__
#pragma arm section rodata , code
#endif
    

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_enter_usb_mode_callback
 * DESCRIPTION
 *  usb mode handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_enter_usb_mode_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL popup = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MTV_ENTER_USB_MODE_CALLBACK);

    if (!KERNEL_STATE_IN(MTV_KERNEL_CLOSED) && !KERNEL_STATE_IN(MTV_KERNEL_CLOSING))
    {
#ifdef   __MMI_MTV_RECORD_SUPPORT__
        if (RECORDER_STATE_IN(MTV_RECORDER_RECORD) &&
            !mmi_frm_scrn_is_present(GRP_ID_MOBILE_TV_PLAYER, SCR_ID_MOBILE_TV_PLAYER_APP_BASE, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
            popup = MMI_TRUE;
        }
#endif

        mmi_mtv_player_terminate_app();
        if (popup)
        {
            mmi_popup_display_simple(
                (WCHAR*) GetString(STR_ID_MOBILE_TV_PLAYER_NOTIFY_RECORDER_STOPPED),
                MMI_EVENT_FAILURE,
                GRP_ID_MOBILE_TV_PLAYER,
                NULL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_restore_setting
 * DESCRIPTION
 *  restore mobile tv player default settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_restore_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->setting.brightness = MDI_MTV_BRIGHTNESS_0;
    mtv_player_p->setting.contrast = MDI_MTV_CONTRAST_0;
    mtv_player_p->setting.saturation = MDI_MTV_SATURATION_0;
    mtv_player_p->setting.selected_channel = 0;
	#ifdef __ATV_NO_PHONE_STORAGE__
    mtv_player_p->setting.storage = SRV_FMGR_CARD_DRV;//SRV_FMGR_PUBLIC_DRV;
    #else
	mtv_player_p->setting.storage = SRV_FMGR_PUBLIC_DRV;//SRV_FMGR_PUBLIC_DRV;
	#endif
    mtv_player_p->setting.vol_level = MTV_PLAYER_VOL_7;
    mtv_player_p->setting.is_mute = KAL_FALSE;
    mtv_player_p->setting.band = 0;
    mtv_player_p->setting.is_channel_list_init = MMI_FALSE;
    mtv_player_p->setting.filename_seq_no = 0;


#if defined(__MMI_MTV_RECORD_SUPPORT__)
    mtv_player_p->setting.record_size = MDI_MTV_RECORDER_SIZE_HVGA;
#endif

    WriteRecord(NVRAM_EF_MOBILE_TV_PLAYER_SETTING_LID, 1, (void*)&mtv_player_p->setting, NVRAM_EF_MOBILE_TV_PLAYER_SETTING_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_load_setting
 * DESCRIPTION
 *  load mobile tv player settings from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_load_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if setting is already loaded from NVRAM, it is already exist in memory, do not loaded again */
    if (!mtv_player_p->is_setting_loaded)
    {
        ReadRecord(
            NVRAM_EF_MOBILE_TV_PLAYER_SETTING_LID,
            1,
            (void*)&mtv_player_p->setting,
            NVRAM_EF_MOBILE_TV_PLAYER_SETTING_SIZE,
            &error);

        /* first time init */
        if (mtv_player_p->setting.storage == 0xffff)
        {
            mmi_mtv_player_restore_setting();
        }

        mtv_player_p->is_setting_loaded = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_stop_app_mem_callback
 * DESCRIPTION
 *  to stop mtv player for releasing app-based asm.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_stop_app_mem_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!KERNEL_STATE_IN(MTV_KERNEL_CLOSED) && !KERNEL_STATE_IN(MTV_KERNEL_CLOSING))
        mmi_mtv_player_terminate_app();
    
    if (KERNEL_STATE_IN(MTV_KERNEL_CLOSING))
    {
        mtv_player_p->app_mem_force_release = KAL_TRUE;
    }
    else
    {
        /* Notify MMI that this application is already stopped */
        applib_mem_ap_notify_stop_finished(
            APPLIB_MEM_AP_ID_MTV_PLAYER, KAL_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_reset_all_state
 * DESCRIPTION
 *  reset all modules' states.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_reset_all_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->kernel_prev_state = MTV_KERNEL_CLOSED;
    mtv_player_p->kernel_state = MTV_KERNEL_CLOSED;
    mtv_player_p->kernel_next_state = MTV_KERNEL_CLOSED;

    mtv_player_p->player_prev_state = MTV_PLAYER_STOPPED;
    mtv_player_p->player_state = MTV_PLAYER_STOPPED;
    mtv_player_p->player_next_state = MTV_PLAYER_STOPPED;

    mtv_player_p->recorder_prev_state = MTV_RECORDER_STOPPED;
    mtv_player_p->recorder_state = MTV_RECORDER_STOPPED;
    mtv_player_p->recorder_next_state = MTV_RECORDER_STOPPED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_init_icon_info
 * DESCRIPTION
 *  mobile tv player init all icons info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_player_init_icon_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_ATV_OSD_SUPPORT__
#ifndef __MMI_FTE_SUPPORT__
    CHAR* str_ptr;
    S32 truncated_width;
#else
    S32 width = 0;
#endif
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #define INIT_OSD_TOUCH_ICON(a,A)\
    do {\
        gdi_image_get_dimension_id(\
            (U16)(IMG_ID_MTV_PLAYER_##A##_UP),\
            &(mtv_player_p->active_osd_cntx_p->##a##.width),\
            &(mtv_player_p->active_osd_cntx_p->##a##.height)) ;\
    }while(0)

#ifdef __MMI_ATV_OSD_SUPPORT__


#if defined(__MMI_MTV_RECORD_SUPPORT__)
    INIT_OSD_TOUCH_ICON(record, RECORD);
#elif defined(__MMI_MTV_SNAPSHOT_SUPPORT__)
    INIT_OSD_TOUCH_ICON(record, SNAPSHOT);
#endif

    /* Channel number */
    gdi_image_get_dimension_id(
        (U16)(IMG_ID_MTV_PLAYER_NUM_0),
        &(mtv_player_p->active_osd_cntx_p->channel_number.width),
        &(mtv_player_p->active_osd_cntx_p->channel_number.height));

#if ((LCD_WIDTH == 320) && (LCD_HEIGHT == 240))
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        gdi_image_get_dimension_id(
            (U16)(IMG_ID_MTV_PLAYER_NUM_0_H),
            &(mtv_player_p->active_osd_cntx_p->channel_number.width),
            &(mtv_player_p->active_osd_cntx_p->channel_number.height));
    }
#endif /* (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) */


    INIT_OSD_TOUCH_ICON(fullscreen,FULLSCREEN);
#if defined(__MMI_MTV_LANDSCAPE_SUPPORT__) && !defined(__MMI_FTE_SUPPORT__)
    INIT_OSD_TOUCH_ICON(vol_inc,VOL_INC);
    INIT_OSD_TOUCH_ICON(vol_dec,VOL_DEC);
#endif

    INIT_OSD_TOUCH_ICON(channel_next,CHANNEL_NEXT);
    INIT_OSD_TOUCH_ICON(channel_prev,CHANNEL_PREV);

#if !defined(__MMI_FTE_SUPPORT__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MTV_FTE2_LAYOUT__))
    /* Vol status */
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        gdi_image_get_dimension_id(
            (U16)(IMG_ID_MTV_PLAYER_VOL_STATUS_ON),
            &(mtv_player_p->active_osd_cntx_p->vol_status.width),
            &(mtv_player_p->active_osd_cntx_p->vol_status.height));
    }
    else
    {
        gdi_image_get_dimension_id(
            (U16)(IMG_ID_MTV_PLAYER_VOL_STATUS_ON_H),
            &(mtv_player_p->active_osd_cntx_p->vol_status.width),
            &(mtv_player_p->active_osd_cntx_p->vol_status.height)) ;
    }
#endif


#if defined(__MMI_FTE_SUPPORT__)
#if !defined(__MMI_MTV_FTE2_LAYOUT__)
    gdi_image_get_dimension_id(
        (U16)(IMG_ID_MTV_PLAYER_VOL_BG),
        &(mtv_player_p->active_osd_cntx_p->vol_bg.width),
        &(mtv_player_p->active_osd_cntx_p->vol_bg.height));
#endif
    gdi_image_get_dimension_id(
        (U16)(IMG_ID_MTV_PLAYER_VOL_ON),
        &(mtv_player_p->active_osd_cntx_p->vol_status.width),
        &(mtv_player_p->active_osd_cntx_p->vol_status.height));
    gdi_image_get_dimension_id(
        (U16)(IMG_ID_MTV_PLAYER_VOL_BAR),
        &(width),
        &(mtv_player_p->active_osd_cntx_p->vol_bar.height));

    #if !defined(__MMI_MTV_FTE2_LAYOUT__)
        mtv_player_p->active_osd_cntx_p->vol_bar.width = width;
    #endif
    #if defined(__MMI_MTV_FTE2_LAYOUT__) && defined(__MMI_FTE_SUPPORT__)
    gdi_image_get_dimension_id(
        (U16)(IMG_ID_MTV_PLAYER_VOL_INDEX_UP),
        &(mtv_player_p->active_osd_cntx_p->vol_idx.width),
        &(mtv_player_p->active_osd_cntx_p->vol_idx.height));
    #else
    gdi_image_get_dimension_id(
        (U16)(IMG_ID_MTV_PLAYER_VOL_INDEX_UP_L),
        &(mtv_player_p->active_osd_cntx_p->vol_idx.width),
        &(mtv_player_p->active_osd_cntx_p->vol_idx.height));
    #endif
     gdi_image_get_dimension_id(
        (U16)(IMG_ID_MTV_PLAYER_VOL_LEVEL),
        &(mtv_player_p->active_osd_cntx_p->volume.width),
        &(mtv_player_p->active_osd_cntx_p->volume.height));
#else /* defined(__MMI_FTE_SUPPORT__) */

    gdi_image_get_dimension_id(
        (U16)(IMG_ID_MTV_PLAYER_VOL_LEVEL),
        &(mtv_player_p->active_osd_cntx_p->volume.width),
        &(mtv_player_p->active_osd_cntx_p->volume.height));

#endif /* defined(__MMI_FTE_SUPPORT__) */
#ifdef __MMI_FTE_SUPPORT__
    INIT_OSD_TOUCH_ICON(lsk,OPTION);
    INIT_OSD_TOUCH_ICON(rsk,BACK);

#else /* __MMI_FTE_SUPPORT__ */

#ifdef __MMI_MTV_LANDSCAPE_SUPPORT__
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        gdi_image_get_dimension_id(
            (U16)(IMG_ID_MTV_PLAYER_BACK_UP_H),
            &(mtv_player_p->active_osd_cntx_p->rsk.width),
            &(mtv_player_p->active_osd_cntx_p->rsk.height));

        return;
    }
#endif /*__MMI_MTV_LANDSCAPE_SUPPORT__ */
    /* Soft key */
    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_BUTTON));

    /* LSK */
    str_ptr = (CHAR*) GetString(STR_GLOBAL_OPTIONS);

    gui_measure_string(
        (UI_string_type) str_ptr,
        &(mtv_player_p->active_osd_cntx_p->lsk.width),
        &(mtv_player_p->active_osd_cntx_p->lsk.height));

    wgui_softkey_get_offset(
                       (UI_string_type)str_ptr,
                       &mtv_player_p->active_osd_cntx_p->lsk.offset_x,
                       &mtv_player_p->active_osd_cntx_p->lsk.offset_y,
                       &truncated_width,
                       MMI_LEFT_SOFTKEY,
                       mtv_player_p->ui_rotate);

    /* Restore the value wgui changes */
    if (r2lMMIFlag)
    {
        mtv_player_p->active_osd_cntx_p->lsk.offset_x -= mtv_player_p->active_osd_cntx_p->lsk.width;
    }

    /* RSK */
    str_ptr = (CHAR*) GetString(STR_GLOBAL_BACK);

    gui_measure_string(
        (UI_string_type) str_ptr,
        &(mtv_player_p->active_osd_cntx_p->rsk.width),
        &(mtv_player_p->active_osd_cntx_p->rsk.height));

    wgui_softkey_get_offset(
                       (UI_string_type)str_ptr,
                       &mtv_player_p->active_osd_cntx_p->rsk.offset_x,
                       &mtv_player_p->active_osd_cntx_p->rsk.offset_y,
                       &truncated_width,
                       MMI_RIGHT_SOFTKEY,
                       mtv_player_p->ui_rotate);

    /* Restore the value wgui changes */
    if (r2lMMIFlag)
    {
        mtv_player_p->active_osd_cntx_p->rsk.offset_x -= mtv_player_p->active_osd_cntx_p->rsk.width;
    }
#endif /* __MMI_FTE_SUPPORT__ */
#endif /* __MMI_ATV_OSD_SUPPORT__ */
}


/*****************************************************************************
* FUNCTION
*  mmi_mtv_player_is_in_background_call
* DESCRIPTION
*  mmi_mtv_player_is_in_background_call
* PARAMETERS
*  void
* RETURNS
*  MDI_RESULT
*****************************************************************************/
 MMI_BOOL mmi_mtv_player_is_in_background_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||
        srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||
        srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
#else /* __MMI_BACKGROUND_CALL__ */
    return MMI_FALSE;
#endif /* __MMI_BACKGROUND_CALL__ */
}

    
/*****************************************************************************
* FUNCTION
*  mmi_mtv_player_event_notify_handler
* DESCRIPTION
*  usb mode handler.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
 mmi_ret mmi_mtv_player_event_notify_handler(mmi_event_struct* evt)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        case EVT_ID_SRV_PROF_IS_PLAYING:
        case EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN:
        if (PLAYER_STATE_IN(MTV_PLAYER_PLAY) && !mmi_mtv_player_is_in_background_call())
        {
            return MMI_TRUE;
        }
            break;
        case EVT_ID_SRV_SHUTDOWN_DEINIT:
            if (!KERNEL_STATE_IN(MTV_KERNEL_CLOSED) && !KERNEL_STATE_IN(MTV_KERNEL_CLOSING))
        mmi_mtv_player_terminate_app();
            break;
#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
        case EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING:
        if(mmi_frm_scrn_is_present(GRP_ID_MOBILE_TV_PLAYER, SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST,MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG) ||
        mmi_frm_scrn_is_present(GRP_ID_MOBILE_TV_PLAYER, SCR_ID_MOBILE_TV_PLAYER_APP, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
            mmi_scr_locker_pre_lock_evt_struct* lock_event = (mmi_scr_locker_pre_lock_evt_struct*)evt;
            if(lock_event->lock_mode == MMI_SCR_LOCKER_LOCK_MODE_AUTO_LOCK)
            {
                return MMI_RET_ERR;
            }
            else if(lock_event->lock_mode == MMI_SCR_LOCKER_LOCK_MODE_POWER_KEY)
            {
                return MMI_RET_OK;
            }            
        }
        return MMI_RET_OK;
            break;
#endif
#ifdef __MMI_USB_SUPPORT__
        case EVT_ID_USB_ENTER_MS_MODE:
        mmi_mtv_player_enter_usb_mode_callback();
            break;
        case EVT_ID_USB_EXIT_MS_MODE:
            if (KERNEL_STATE_IN(MTV_KERNEL_CLOSED) || KERNEL_STATE_IN(MTV_KERNEL_CLOSING))
            {
                return MMI_RET_OK;
            }
            mmi_mtv_player_exit_usb_mode_callback();
            break;
#endif
        default:
            break;
    }
    
    return MMI_RET_OK;
}
    
    
/*****************************************************************************
* FUNCTION
*  mmi_mtv_player_launch
* DESCRIPTION
*  functions to launch mobile tv player
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
 void mmi_mtv_player_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//#ifdef __MM_DCM_SUPPORT__
//    if (KAL_FALSE == (DCM_Isloaded(DYNAMIC_CODE_COMPRESS_CAMCAL)))
//    {
//        DCM_Load(DYNAMIC_CODE_COMPRESS_CAMCAL, 0, 0);
//    }
//#endif
#ifdef __MMI_AP_DCM_MATV__
    mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_MATV);
#endif
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_MOBILE_TV_PLAYER, mmi_mtv_player_group_proc, NULL);
    mmi_frm_group_enter(GRP_ID_MOBILE_TV_PLAYER, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_mtv_player_enter_app_main();
}
    
/*****************************************************************************
* FUNCTION
*  mmi_mtv_player_init_app
* DESCRIPTION
*  Mobile TV Player init function,
*  which is called when MMI Task is initializing
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
 void mmi_mtv_player_init_app(void)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
    applib_mem_ap_register(APPLIB_MEM_AP_ID_MTV_PLAYER,STR_ID_MOBILE_TV_PLAYER_APP_NAME
               ,IMG_ID_MOBILE_TV_PLAYER_APP_ICON ,mmi_mtv_player_stop_app_mem_callback);
    
    mtv_player_p->storage_status = MTV_PLAYER_STORAGE_OK;
    
    mtv_player_p->ui_rotate = MMI_FRM_SCREEN_ROTATE_0;
    mtv_player_p->active_osd_cntx_p = &g_mtv_player_osd_cntx;
    
    mmi_mtv_player_reset_all_state();
    
    mtv_player_p->bool_state = MTV_PLAYER_BOOL_START;
    
    mmi_mtv_player_init_icon_info();
    
    /* temp setting */
    
    mtv_player_p->num_services = 0;
    mtv_player_p->signal_strength = 0;
    
    mtv_player_p->services = NULL;
    
#if 0
/* under construction !*/
/* under construction !*/
#endif
    
}
    
/*****************************************************************************
* FUNCTION
*  mmi_mtv_player_fmgr_notify_handler
* DESCRIPTION
*  usb mode handler.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
 mmi_ret mmi_mtv_player_fmgr_notify_handler(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_notification_format_event_struct *format_evt;
#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
    srv_fmgr_notification_set_def_storage_event_struct *storage_evt;
    S16 error;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* pre-format */
    if (evt->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT)
    {
        format_evt = (srv_fmgr_notification_format_event_struct*)evt;
        if (format_evt->state == SRV_FMGR_NOTIFICATION_STATE_BEFORE)
        {
                if (mtv_player_p->setting.storage == format_evt->drv_letter &&
                    (!KERNEL_STATE_IN(MTV_KERNEL_CLOSED) && !KERNEL_STATE_IN(MTV_KERNEL_CLOSING)))
            {
                mmi_mtv_player_terminate_app();
            }
        }
    }
#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
    /* set storage */
    else if (evt->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE)
    {
        storage_evt = (srv_fmgr_notification_set_def_storage_event_struct *)evt;
#ifdef   __MMI_MTV_RECORD_SUPPORT__
        if (storage_evt->state == SRV_FMGR_NOTIFICATION_STATE_QUERY)
        {
            /* Recording: change storage is prohibited */
            if (!RECORDER_STATE_IN(MTV_RECORDER_STOPPED))
            {
                return MMI_RET_ERR;
            }
        }
        else 
#endif
        if (storage_evt->state == SRV_FMGR_NOTIFICATION_STATE_AFTER)
        {
#ifdef   __MMI_MTV_RECORD_SUPPORT__
            ASSERT(RECORDER_STATE_IN(MTV_RECORDER_STOPPED));
#endif
            mmi_mtv_player_load_setting();
            mtv_player_p->setting.storage = storage_evt->drv_letter;
    
            /* storge setting to NVRAM */
            WriteRecord(
            NVRAM_EF_MOBILE_TV_PLAYER_SETTING_LID,
            1,
            (void*)&mtv_player_p->setting,
            NVRAM_EF_MOBILE_TV_PLAYER_SETTING_SIZE,
            &error);
        }
    }
#endif /* __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__ */
    /* card plut out or plug in */
    else if (evt->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT ||
            evt->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN)
    {
        if (KERNEL_STATE_IN(MTV_KERNEL_CLOSED) || KERNEL_STATE_IN(MTV_KERNEL_CLOSING))
        {
            return MMI_RET_OK;
        }
#ifndef __ATV_NO_PHONE_STORAGE__
        /* Storage is phone. Ignore */
        if (mtv_player_p->setting.storage == SRV_FMGR_PUBLIC_DRV)
        {
            return MMI_RET_OK;
        }
#endif
        mmi_mtv_player_update_storage_status();
    }

    
    return MMI_RET_OK;
}
    
    
/*****************************************************************************
* FUNCTION
*  mmi_mtv_player_highlight_app
* DESCRIPTION
*  mobile tv player menu item highlight handler
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_mtv_player_highlight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    SetLeftSoftkeyFunction(mmi_mtv_player_launch, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mtv_player_launch, KEY_EVENT_UP);
    
}

#ifdef __MMI_MATV_ESD_RECOVERY_SUPPORT__
#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)
static void resz_cp_ESD_timeout_timer_hdlr(void)
{
   ilm_struct *ilm = NULL;
   module_type src_mod_id;
     
	 if(resz_esd_check_flag)
	 {
        resz_esd_check_flag = KAL_FALSE;
	 }
	 else
	 {
        CalLcdFroceAutoUpdate();
        if (matv_resz_timer_seted)
        {
            matv_resz_timer_seted = MMI_FALSE;
		  	kal_cancel_timer(matv_resz_cp_ESD_timeout_timer);  
        }

          src_mod_id = MOD_TIMER_HISR;
          ilm = allocate_ilm(src_mod_id); 
          ilm->src_mod_id = src_mod_id;
          ilm->sap_id = 0;
          ilm->msg_id = (msg_type)MSG_ID_MATV_ESD_TIME_OUT_IND;
          ilm->dest_mod_id = MOD_MMI;
          msg_send_ext_queue(ilm);
	 }
}
#endif
#endif/*__MMI_MATV_ESD_RECOVERY_SUPPORT__*/

#endif /* __MMI_ATV_SUPPORT__ */

