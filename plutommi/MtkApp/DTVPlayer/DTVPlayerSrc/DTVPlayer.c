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
 *  DTVPlayer.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
[Jiaowei, 02/24]Dear Ruoyao:   UI里面说明，当获取密钥失败时，提示信息为：“移动网络信号弱，获取订购信息失败，请稍后再试”，网络连接失败时提示“网络连接错误”。两个String都是有的，这条case的log里面返回的是MSK_Retrieve_down的param是-6019,所以需要你和Stella进一步确认。其它你需要的信息见Notes。


[Ruoyao, 02/24]Dear Jiaowei: 请先帮忙确认test case中的string是否和Spec有冲突，如果有冲突的话我们可以和smart phone/CMCC确认。thanks~
[Jiaowei, 02/24]Dear Ruoyao:    我这边看过了，我这边没有提示语“提示移动网络信号弱，获取订购信息失败，请稍后再试”，请看下，是否是MDI的error code对应的String，
[Ruoyao, 02/23]Dear Jiaowei: 请先帮忙看一下这个字串问题。thanks~

 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files
*****************************************************************************/
#include "MMI_features.h"

#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)

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
#include "mtv_comm.h"
#include "mmi_features_dtv_player.h"
#include "gui_font_size.h"
#include "gui_effect_oem.h"

#if defined(__MMI_DTV_A2DP_SUPPORT__)
#include "BTMMIScrGprots.h"
#include "av_bt.h"
#include "AudioPlayerProt.h"
#endif /* __MMI_DTV_A2DP_SUPPORT__ */

#include "BTMMIObexGprots.h"

#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif /* __MMI_TOUCH_SCREEN__ */

#ifdef __MMI_TVOUT__
#include "mdi_tv.h"
#endif
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "wgui_categories_multimedia.h"
#include "mdi_include.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_mtv.h"
#include "app_str.h"
#include "TimerEvents.h"
#include "CommonScreensResDef.h"
#include "DTVPlayerEnum.h"
#include "DTVPlayerGprot.h"
#include "DTVPlayer.h"
#include "DTVPlayerOSD.h"
#include "gdi_2d_engine.h"
#include "MMI_media_app_trc.h"
#include "ProfilesSrvGprot.h"

#include "mtv_esg_query_datatype.h"
#include "DateTimeType.h"

#ifdef __DM_LAWMO_SUPPORT__
#include "mmiapi_dm_struct.h"
#include "dmuigprot.h"
#endif
#include "UcmSrvGprot.h"
#include "UCMGProt.h"
#include "USBsrvgprot.h"
#include "IdleGProt.h"

/* removable */
#include "MainMenuDef.h"        /* Multimedia icon */
#ifndef __COSMOS_MMI_PACKAGE__
#include "mmi_rp_app_mainmenu_def.h"        /* Multimedia icon */
#endif
#include "mmi_rp_app_idle_def.h"
#include "SimCtrlSrvGprot.h"

/* GDI */
#include "gdi_include.h"
#include "custom_events_notify.h"
#include "Gui_effect_oem.h"
#include "ShutdownSrvGProt.h"
#include "Gpiosrvgprot.h"
#include "MenuCuiGProt.h"
#include "FileMgrCuiGProt.h"
#include "FSEditorCuiGProt.h"
#include "InlineCuiGProt.h"
#include "BTMMISCOPathGprots.h"
#include "DataAccountCUIGprot.h"
#include "wgui_inputs.h"
#include "mmi_rp_srv_prof_def.h"
#include "mmi_rp_app_usbsrv_def.h"

#include "MMI_features.h"
#include "mmi_rp_app_dtv_player_def.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"

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
#include "TimerEvents.h"
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
#include "GpioSrvGprot.h"
#include "mmi_frm_gprot.h"
#include "mmi_rp_app_idle_def.h"
#include "IdleAppResDef.h"
#include "gui_windows.h"
#include "custom_mmi_default_value.h"
#include "IdleAppResDef.h"
#include "common_nvram_editor_data_item.h"
#include "NwInfoSrvGprot.h"
#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
#include "ScrLockerGprot.h"
#endif

#ifdef __MBBMS_V30_OPERA__
#include "opera_webview_api.h"
#endif

#include "mmi_frm_app_launcher_gprot.h"


#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
#include "UCMGprot.h"
#include "cmmb_2gppadp.h"

static S8 CBC_Hotline_number[22]={0x34,0x00, /* CBC Service Number 4006005577 */
		                          0x30,0x00,
		                          0x30,0x00,
		                          0x36,0x00,
		                          0x30,0x00,
		                          0x30,0x00,
								  0x35,0x00,							  
		                          0x35,0x00,                              
		                          0x37,0x00,                              
		                          0x37,0x00,
		                          0x00,0x00};
#endif

U8 g_cmmb_test_mode = DTV_CMMB_TEST_MODE_OFF;
static S32 g_test_frequency = 0;
static mmi_dtv_player_context_struct g_mmi_dtv_player_cntx;
mmi_dtv_player_context_struct *dtv_player_p = &g_mmi_dtv_player_cntx;
static dtv_player_menu_context_struct g_mmi_dtv_player_setting_cntx;
dtv_player_menu_context_struct *dtv_player_setting_p = &g_mmi_dtv_player_setting_cntx;

/* Inline: caption string */
static const cui_inline_item_caption_struct g_dtv_brightness_caption =
{
    STR_ID_DTV_PLAYER_SETTING_BRIGHTNESS
};
static const cui_inline_item_caption_struct g_dtv_contrast_caption =
{
    STR_ID_DTV_PLAYER_SETTING_CONTRAST
};

/* Inline: selector string */
static const U16 g_dtv_adjust_str[] =
    {STR_ID_DTV_PLAYER_ADJUST_N5,
     STR_ID_DTV_PLAYER_ADJUST_N4,
     STR_ID_DTV_PLAYER_ADJUST_N3,
     STR_ID_DTV_PLAYER_ADJUST_N2,
     STR_ID_DTV_PLAYER_ADJUST_N1,
     STR_ID_DTV_PLAYER_ADJUST_0,
     STR_ID_DTV_PLAYER_ADJUST_P1,
     STR_ID_DTV_PLAYER_ADJUST_P2,
     STR_ID_DTV_PLAYER_ADJUST_P3,
     STR_ID_DTV_PLAYER_ADJUST_P4,
     STR_ID_DTV_PLAYER_ADJUST_P5};

/* Inline: selector structure */
static const cui_inline_item_select_struct g_dtv_brightness_selector =
{
    MMI_DTV_PLAYER_BRIGHTNESS_ADJ_LEVEL_COUNT,
    0,
    g_dtv_adjust_str
};
static const cui_inline_item_select_struct g_dtv_contrast_selector =
{
    MMI_DTV_PLAYER_CONTRAST_ADJ_LEVEL_COUNT,
    0,
    g_dtv_adjust_str
};

typedef enum
{
    MMI_DTV_IMG_BRIGHTNESS = IMG_GLOBAL_L1,
    MMI_DTV_IMG_CONTRAST
}dtv_player_set_item_enum;

static const cui_inline_set_item_struct g_dtv_setting_item[] =
{
    {MMI_DTV_BRIGHTNESS_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION,       MMI_DTV_IMG_BRIGHTNESS, (void*)&g_dtv_brightness_caption},
    {MMI_DTV_BRIGHTNESS_SELECTOR,       CUI_INLINE_ITEM_TYPE_SELECT,        0,                      (void*)&g_dtv_brightness_selector},
    {MMI_DTV_CONTRAST_CAPTION,          CUI_INLINE_ITEM_TYPE_CAPTION,       MMI_DTV_IMG_CONTRAST,   (void*)&g_dtv_contrast_caption},
    {MMI_DTV_CONTRAST_SELECTOR,         CUI_INLINE_ITEM_TYPE_SELECT,        0,                      (void*)&g_dtv_contrast_selector}
};

static const cui_inline_struct g_dtv_setting_inline =
{
    sizeof(g_dtv_setting_item)/sizeof(g_dtv_setting_item[0]),
    STR_GLOBAL_SETTINGS,
    0,
    CUI_INLINE_SCREEN_DEFAULT_TEXT,
    NULL,
    g_dtv_setting_item
};


/* Inline: caption string */
static const cui_inline_item_caption_struct g_dtv_frequency_setting_caption =
{
    STR_ID_DTV_PLAYER_FREQUENCY_SET
};

/* Inline: text edit */
static const cui_inline_item_text_edit_struct g_dtv_frequency_setting_edit =
{
    0,
    0,
    MMI_DTV_MAX_FREQUENCY_LEN,
    IMM_INPUT_TYPE_NUMERIC,
    IMM_INPUT_TYPE_NUMERIC,
    NULL
};



static const cui_inline_set_item_struct g_dtv_test_mode_setting_item[] =
{
	{MMI_DTV_TEST_MODE_SET_CAPTION,	CUI_INLINE_ITEM_TYPE_CAPTION,   0,  (void *)&g_dtv_frequency_setting_caption},
	{MMI_DTV_TEST_MODE_SET_EDIT,    CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0,  (void *)&g_dtv_frequency_setting_edit}
};


static const cui_inline_struct g_dtv_test_mode_setting =
{
	sizeof(g_dtv_test_mode_setting_item) / sizeof(g_dtv_test_mode_setting_item[0]),
	STR_ID_DTV_PLAYER_TEST_SET,
	0,
	CUI_INLINE_SCREEN_DEFAULT_TEXT,
	NULL,
	g_dtv_test_mode_setting_item
};

#ifdef __MBBMS_V30_OPERA__
static U16 Keys_Number[] =
{
	KEY_0,
	KEY_1,
	KEY_2,
	KEY_3,
	KEY_4,
	KEY_5,
	KEY_6,
	KEY_7,
	KEY_8,
	KEY_9
};
static U16 Keys_Direct[] =
{
	KEY_UP_ARROW, 
	KEY_DOWN_ARROW, 
	KEY_LEFT_ARROW, 
	KEY_RIGHT_ARROW
};


#define DTV_PLAYER_KEYS_NUMBER_LEN  (sizeof(Keys_Number) / sizeof(U16))
#define DTV_PLAYER_KEYS_DIRECT_LEN	(sizeof(Keys_Direct) / sizeof(U16))
#endif /* __MBBMS_V30__OPERA__ */



/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_set_flag
 * DESCRIPTION
 *  set flag bit on
 * PARAMETERS
 *  selected_flag [in] flags
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_set_flag(dtv_player_bool_status_enum selected_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->bool_state |= selected_flag;
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
		      MMI_TRC_DTV_SET_FLAG, 
		      selected_flag,
		      dtv_player_p->bool_state);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_unset_flag
 * DESCRIPTION
 *  set flat bit off
 * PARAMETERS
 *  selected_flag [in] flags
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_unset_flag(dtv_player_bool_status_enum selected_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->bool_state &= ~(selected_flag);
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
		      MMI_TRC_DTV_UNSET_FLAG, 
		      selected_flag,
		      dtv_player_p->bool_state);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_is_flag_set
 * DESCRIPTION
 *  usb mode handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 MMI_BOOL mmi_dtv_player_is_flag_set(dtv_player_bool_status_enum selected_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 != (dtv_player_p->bool_state & selected_flag))
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
 *  mmi_dtv_player_blt_previous
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
void mmi_dtv_player_blt_previous(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_blt_previous(x1, y1, x2, y2);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_kernel_enter_state
 * DESCRIPTION
 *  control of serviec state machine
 * PARAMETERS
 *  next state
 * RETURNS
 *  void
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_kernel_enter_state(mmi_dtv_player_kernel_state_enum next_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->kernel_next_state = next_state;
    ret = mmi_dtv_player_exit_current_state(MMI_DTV_KERNEL);

    if (ret < 0)
    {
        return ret;
    }
    ret = mmi_dtv_player_enter_next_state(MMI_DTV_KERNEL);

    if (ret >= 0)
    {
        dtv_player_p->kernel_prev_state = dtv_player_p->kernel_state;
        dtv_player_p->kernel_state = dtv_player_p->kernel_next_state;
        dtv_player_p->kernel_next_state = DTV_KERNEL_NULL;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_KERNEL_STATE, dtv_player_p->kernel_prev_state, dtv_player_p->kernel_state);
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_player_enter_state
 * DESCRIPTION
 *  control of player state machine
 * PARAMETERS
 *  next state
 * RETURNS
 *  void
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_player_enter_state(mmi_dtv_player_player_state_enum next_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = 0;
    U16 active_screen_id = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dtv_player_p->player_next_state = next_state;
    ret = mmi_dtv_player_exit_current_state(MMI_DTV_PLAYER);

    if (ret < 0)
    {
        return ret;
    }

    /* Enter connect state should be prior to calling av_bt_open_ex(),
       because av_bt_open_ex() may call open_callback() directly. */
    if (next_state == DTV_PLAYER_BT_CONNECT)
    {
        dtv_player_p->player_prev_state = dtv_player_p->player_state;
        dtv_player_p->player_state = dtv_player_p->player_next_state;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_DTV_PLAYER_STATE, dtv_player_p->player_prev_state, dtv_player_p->player_state);

        ret = mmi_dtv_player_enter_next_state(MMI_DTV_PLAYER);

        dtv_player_p->player_next_state = DTV_PLAYER_NULL;
    }
    else
    {
        ret = mmi_dtv_player_enter_next_state(MMI_DTV_PLAYER);

        if (ret >= 0)
        {
            dtv_player_p->player_prev_state = dtv_player_p->player_state;
            dtv_player_p->player_state = dtv_player_p->player_next_state;
            dtv_player_p->player_next_state = DTV_PLAYER_NULL;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_DTV_PLAYER_STATE, dtv_player_p->player_prev_state, dtv_player_p->player_state);

            if (active_screen_id == SCR_ID_DTV_PLAYER_APP &&
                dtv_player_p->player_state == DTV_PLAYER_PLAY)
            {
                /* If already fade out, keep all key handler as: mmi_dtv_player_fullscr_osd_show_up */
                if (dtv_player_p->fullscr_osd_opacity != 0)
                {
                    /* For snapshot icon */
                    mmi_dtv_player_register_key_hdlr();
                    mmi_dtv_player_draw_osd();
                    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
                }
            }
        }
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_recorder_enter_state
 * DESCRIPTION
 *  control of recorder state machine
 * PARAMETERS
 *  next state
 * RETURNS
 *  void
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_recorder_enter_state(mmi_dtv_player_recorder_state_enum next_state)
{
#ifdef __MMI_DTV_RECORD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->recorder_next_state = next_state;
    ret = mmi_dtv_player_exit_current_state(MMI_DTV_RECORDER);

    if (ret < 0)
    return ret;

    ret = mmi_dtv_player_enter_next_state(MMI_DTV_RECORDER);

    if (ret >= 0)
    {
        dtv_player_p->recorder_prev_state = dtv_player_p->recorder_state;
        dtv_player_p->recorder_state = dtv_player_p->recorder_next_state;
        dtv_player_p->recorder_next_state = DTV_RECORDER_NULL;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_RECORDER_STATE, dtv_player_p->recorder_prev_state, dtv_player_p->recorder_state);
    }

    return ret;
#else
    return 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_is_in_background_call
 * DESCRIPTION
 *  mmi_dtv_player_is_in_background_call
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MMI_BOOL mmi_dtv_player_is_in_background_call(void)
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
* External Functions Implementation
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_update_storage_status
 * DESCRIPTION
 *
 * PARAMETERS
 *  inMsg       [?]
 * RETURNS
 *
 *****************************************************************************/
 void mmi_dtv_player_update_storage_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen_id = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* check storage to enable or disable timeshift function dynamically */
    mmi_dtv_player_check_storage(MMI_FALSE, dtv_player_p->setting.storage);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL2, dtv_player_p->prev_storage_status, dtv_player_p->storage_status, __LINE__);

    if (dtv_player_p->prev_storage_status == dtv_player_p->storage_status)
    {
        return;
    }

    if (dtv_player_p->storage_status == DTV_PLAYER_STORAGE_OK)
    {
    #if defined(__MDI_DTV_TIME_SHIFT_SUPPORT__)
        mdi_mtv_enable_timeshift(dtv_player_p->mtv_handle, (PU8)dtv_player_p->storage_filepath);

        dtv_player_p->is_ready_to_ts = MMI_TRUE;
        if (!PLAYER_STATE_IN(DTV_PLAYER_STOPPED))
        {
            mmi_dtv_player_player_enter_state(DTV_PLAYER_STOPPED);
        }

        if (KERNEL_STATE_IN(DTV_KERNEL_READY) || KERNEL_STATE_IN(DTV_KERNEL_INIT))
        {
            mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);
            mmi_dtv_player_kernel_enter_state(DTV_KERNEL_INIT);
        }
    #elif defined(__MMI_DTV_RECORD_SUPPORT__)
        mdi_mtv_set_storage(dtv_player_p->mtv_handle, (PU8)dtv_player_p->storage_filepath);
    #endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */
    }
    else
    {
    #if defined(__MDI_DTV_TIME_SHIFT_SUPPORT__)
        mdi_mtv_disable_timeshift(dtv_player_p->mtv_handle);
    #endif
        dtv_player_p->is_ready_to_ts = MMI_FALSE;
        /* reset ts info */
        dtv_player_p->max_timeshift_delay = 0;
        dtv_player_p->play_delay = 0;
        dtv_player_p->max_delay = 0;
    }

#if defined(__MMI_DTV_RECORD_SUPPORT__) || defined(__MMI_DTV_SNAPSHOT_SUPPORT__)

    if (active_screen_id == SCR_ID_DTV_PLAYER_APP)
    {
        /* If already fade out, keep all key handler as: mmi_dtv_player_fullscr_osd_show_up */
        if (dtv_player_p->fullscr_osd_opacity != 0)
        {
            /* For snapshot icon */
            mmi_dtv_player_register_key_hdlr();
            mmi_dtv_player_draw_osd();
            mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
        }
    }
#endif /* __MMI_DTV_RECORD_SUPPORT__  || __MMI_DTV_SNAPSHOT_SUPPORT__*/

}

#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
/*****************************************************************************
 * FunctionName: mmi_dtv_player_scrLock_notify_handler
 * Description
 *    stop screen lock when play   
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-04-19
 *****************************************************************************/
mmi_ret mmi_dtv_player_scrLock_notify_handler(mmi_event_struct* evt)
{
	mmi_ret result = MMI_RET_OK;
	switch(evt->evt_id)
	{
		case EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING:
			{
				if (PLAYER_STATE_IN(DTV_PLAYER_PLAY))
				{
					result = MMI_RET_ERR;
				}
				break;
			}
		default :
			{
				break;
			}
	}
	
	return result;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_fmgr_notify_handler
 * DESCRIPTION
 *  usb mode handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dtv_player_fmgr_notify_handler(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_notification_format_event_struct *format_evt = NULL;
	mmi_ret result = MMI_RET_OK;
#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__	
	srv_fmgr_notification_set_def_storage_event_struct *storage_evt = NULL;
	S16 error = 0;
#endif	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (evt->evt_id)
	{
		case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT:
			{
				format_evt = (srv_fmgr_notification_format_event_struct*)evt;				
				if ((SRV_FMGR_NOTIFICATION_STATE_BEFORE == format_evt->state)
					&& (dtv_player_p->setting.storage == format_evt->drv_letter))
				{					
					mmi_dtv_player_terminate_app();
				}
				break;
			}
		case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
		case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN :
			{
				if ((DTV_KERNEL_CLOSED != dtv_player_p->kernel_state)
					&& (DTV_KERNEL_CLOSING != dtv_player_p->kernel_state)
					&& (SRV_FMGR_PUBLIC_DRV != dtv_player_p->setting.storage))
        		{
				    mmi_dtv_player_update_storage_status();
        		}
				break;
			}
		#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
		case EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE:
			{				
				storage_evt = (srv_fmgr_notification_set_def_storage_event_struct *)evt;
				if (SRV_FMGR_NOTIFICATION_STATE_QUERY == storage_evt->state)
		        {
		            /* Recording: change storage is prohibited */
		            if (!RECORDER_STATE_IN(DTV_RECORDER_STOPPED))
		            {
		                result = MMI_RET_ERR;
						break;
		            }
		        }
				else if (SRV_FMGR_NOTIFICATION_STATE_AFTER == storage_evt->state)
        		{
            		ASSERT(RECORDER_STATE_IN(DTV_RECORDER_STOPPED));
					mmi_dtv_player_load_setting();					
            		dtv_player_p->setting.storage = storage_evt->drv_letter;
            		/* storge setting to NVRAM */
            		WriteRecord(NVRAM_EF_DTV_PLAYER_SETTING_LID,
				                1,
				                (void*)&dtv_player_p->setting,
				                NVRAM_EF_DTV_PLAYER_SETTING_SIZE,
				                &error);
					MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL1, error, __LINE__);
        		}
				break;
			}
		#endif	/* __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__ */
        default :
			{
				break;
			}
	}
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_exit_usb_mode_callback
 * DESCRIPTION
 *  usb mode handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_exit_usb_mode_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen_id = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_EXIT_USB_MODE_CALLBACK);

    if (!mmi_frm_scrn_is_present(
            GRP_ID_DTV_PLAYER,
            SCR_ID_DTV_PLAYER_APP_BASE,
            MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        return;
    }
    /* Following: exit USB mode inside DTV application */

    /* USB_Deinit function has been invoked, but screen is not deleted up to Idle screen */
    if (KERNEL_STATE_IN(DTV_KERNEL_CLOSED) || KERNEL_STATE_IN(DTV_KERNEL_CLOSING))
    {
        mmi_frm_group_close(GRP_ID_DTV_PLAYER);
        return;
    }

    mmi_dtv_player_update_storage_status();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_enter_usb_mode_callback
 * DESCRIPTION
 *  usb mode handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_enter_usb_mode_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL popup = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_ENTER_USB_MODE_CALLBACK);

    if (!KERNEL_STATE_IN(DTV_KERNEL_CLOSED) && !KERNEL_STATE_IN(DTV_KERNEL_CLOSING))
    {
        if (RECORDER_STATE_IN(DTV_RECORDER_RECORD) &&
            !mmi_frm_scrn_is_present(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_APP_BASE, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
            popup = MMI_TRUE;
        }
		mmi_frm_group_close(GRP_ID_DTV_PLAYER);
        if (popup)
        {
            mmi_dtv_player_display_popup(
                STR_ID_DTV_PLAYER_NOTIFY_RECORDER_STOPPED,
                MMI_EVENT_FAILURE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_event_notify_handler
 * DESCRIPTION
 *  usb mode handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dtv_player_event_notify_handler(mmi_event_struct* evt)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    if (evt->evt_id == EVT_ID_SRV_PROF_IS_PLAYING ||
        evt->evt_id == EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN)
    {
        if (PLAYER_STATE_IN(DTV_PLAYER_PLAY))
        {
            return MMI_TRUE;
        }
    }
    else if (evt->evt_id == EVT_ID_SRV_SHUTDOWN_DEINIT)
    {
        mmi_dtv_player_terminate_app();
    }
#ifdef __MMI_USB_SUPPORT__
    else if (evt->evt_id == EVT_ID_USB_ENTER_MS_MODE)
    {
        mmi_dtv_player_enter_usb_mode_callback();
    }
    else if (evt->evt_id == EVT_ID_USB_EXIT_MS_MODE)
    {
        mmi_dtv_player_exit_usb_mode_callback();
    }
#endif /* __MMI_USB_SUPPORT__ */

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_terminate_app
 * DESCRIPTION
 *  to deinit app
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_terminate_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_TERMINATE_APP);

    if (!KERNEL_STATE_IN(DTV_KERNEL_CLOSED) && !KERNEL_STATE_IN(DTV_KERNEL_CLOSING))
    {
        /* Service enters CLOSED state will make player and recorder to reset state automatically */
        mmi_dtv_player_kernel_enter_state(DTV_KERNEL_CLOSING);

        wgui_status_icon_bar_hide_icon(STATUS_ICON_DTV_SIGNAL);

        StopTimer(DTV_PLAYER_UPDATE_SIGNAL_TIMER);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_stop_app_mem_callback
 * DESCRIPTION
 *  to stop mtv player for releasing app-based asm.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_stop_app_mem_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dtv_player_terminate_app();

    if (KERNEL_STATE_IN(DTV_KERNEL_CLOSING))
    {
        dtv_player_p->app_mem_force_release = KAL_TRUE;
    }
    else
    {
        /* Notify MMI that this application is already stopped */
        applib_mem_ap_notify_stop_finished(
            APPLIB_MEM_AP_ID_DTV_PLAYER, KAL_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_draw_osd_and_blt
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_draw_osd_and_blt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        mmi_dtv_player_fullscr_reset_osd_fade(MMI_TRUE);
    }
    else
    {
        mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
    }

    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_init_app
 * DESCRIPTION
 *  Mobile TV Player init function,
 *  which is called when MMI Task is initializing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*
#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
    applib_mem_ap_register(APPLIB_MEM_AP_ID_DTV_PLAYER,STR_ID_DTV_CMMB_2GPP_APP_NAME
                ,IMG_ID_DTV_PLAYER_APP_ICON ,mmi_dtv_player_stop_app_mem_callback);
#else
    applib_mem_ap_register(APPLIB_MEM_AP_ID_DTV_PLAYER,STR_ID_DTV_PLAYER_APP_NAME
                ,IMG_ID_DTV_PLAYER_APP_ICON ,mmi_dtv_player_stop_app_mem_callback);
#endif
*/
    dtv_player_p->storage_status = DTV_PLAYER_STORAGE_OK;

    dtv_player_p->ui_rotate = MMI_FRM_SCREEN_ROTATE_0;
    dtv_player_p->active_osd_cntx_p = &g_dtv_player_osd_cntx;

    mmi_dtv_player_reset_all_state();


    dtv_player_p->bool_state = DTV_PLAYER_IS_NORMAL_INIT;

    mmi_dtv_player_init_icon_info();

    /* temp setting */
    dtv_player_p->max_timeshift_delay = 100;
    dtv_player_p->num_services = 0;
    dtv_player_p->signal_strength = 0;

    dtv_player_p->services = NULL;

    /* The function only can be invoked once */
    dtv_player_p->te_ctrl_handle = gdi_lcd_get_te_ctrl_handle();


#ifdef __MMI_DTV_DISPLAY_MTS_MENU__
    dtv_player_p->display_mts_menu = MMI_TRUE;
#else /* __MMI_DTV_DISPLAY_MTS_MENU__ */

    if (mmi_dtv_player_if_mts_file_exist())
    {
        dtv_player_p->display_mts_menu = MMI_TRUE;
    }
    else
    {
        dtv_player_p->display_mts_menu = MMI_FALSE;
    }
#endif /* __MMI_DTV_DISPLAY_MTS_MENU__ */

    #ifdef __MBBMS_V30_OPERA__
    mmi_dtv_player_opera_engine_init_boot_up();
    #endif

/* ADD-S 20120417 FOR CMMBCAS2GPP*/
#ifdef CMMB_CAS_2GPP_V10
    mmi_cmmb_init_2gpp_adp();
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_DTV_VAL1, 11111111,__LINE__);
#endif
/* ADD-E 20120417 FOR CMMBCAS2GPP*/	
}


/*****************************************************************************
*  Functions Implementation
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_reset_all_state
 * DESCRIPTION
 *  reset all modules' states.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_reset_all_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->kernel_prev_state = DTV_KERNEL_CLOSED;
    dtv_player_p->kernel_state = DTV_KERNEL_CLOSED;
    dtv_player_p->kernel_next_state = DTV_KERNEL_CLOSED;

    dtv_player_p->player_prev_state = DTV_PLAYER_STOPPED;
    dtv_player_p->player_state = DTV_PLAYER_STOPPED;
    dtv_player_p->player_next_state = DTV_PLAYER_STOPPED;

    dtv_player_p->recorder_prev_state = DTV_RECORDER_STOPPED;
    dtv_player_p->recorder_state = DTV_RECORDER_STOPPED;
    dtv_player_p->recorder_next_state = DTV_RECORDER_STOPPED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_reset_all_icon
 * DESCRIPTION
 *  reset all icons' states.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_reset_all_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->active_osd_cntx_p->vol_inc.status = DTV_PLAYER_ICON_STATUS_ENABLE;
    dtv_player_p->active_osd_cntx_p->vol_dec.status = DTV_PLAYER_ICON_STATUS_ENABLE;
    dtv_player_p->active_osd_cntx_p->fullscreen.status = DTV_PLAYER_ICON_STATUS_ENABLE;
    dtv_player_p->active_osd_cntx_p->lsk.status = DTV_PLAYER_ICON_STATUS_ENABLE;
    dtv_player_p->active_osd_cntx_p->rsk.status = DTV_PLAYER_ICON_STATUS_ENABLE;
    dtv_player_p->active_osd_cntx_p->cycle.status = DTV_PLAYER_ICON_STATUS_ENABLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_select_channel_to_play
 * DESCRIPTION
 *  mobile tv player channel list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_select_channel_to_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_MBBMS_INIT ||
        dtv_player_p->ca_state == MMI_DTV_CA_STATE_MBBMS)
    {
        mmi_dtv_player_display_popup(
            STR_ID_DTV_PLAYER_SUBSCRIPTION_TABLE_UPDATING,
            MMI_EVENT_FAILURE);
        return;
    }

    if (PLAYER_STATE_IN(DTV_PLAYER_PLAY)||PLAYER_STATE_IN(DTV_PLAYER_BT_CONNECT))
    {
        mmi_dtv_player_player_enter_state(DTV_PLAYER_STOPPED);
    }

    mmi_dtv_player_entry_app_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_cancel_select_channel
 * DESCRIPTION
 *  back from mobile tv player channel list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_cancel_select_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PLAYER_STATE_IN(DTV_PLAYER_PLAY)||PLAYER_STATE_IN(DTV_PLAYER_BT_CONNECT))
    {
        mmi_dtv_player_player_enter_state(DTV_PLAYER_STOPPED);
    }

    if (RECORDER_STATE_IN(DTV_RECORDER_STOPPED))
    {
        mmi_dtv_player_kernel_enter_state(DTV_KERNEL_CLOSING);
        dtv_player_p->go_back_history = MMI_TRUE;
    }

    mmi_frm_group_close(GRP_ID_DTV_PLAYER);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_exit_channel_list_screen
 * DESCRIPTION
 *  mobile tv player channel list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_exit_channel_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    StopTimer(DTV_PLAYER_CHANNEL_LIST_DELAY_TIMER);
    if (KERNEL_STATE_IN(DTV_KERNEL_INIT))
    {
        /* Restore previous selected service */
        ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);
        ASSERT(ret == MDI_RES_MTV_SUCCEED);
    }


    if (PLAYER_STATE_IN(DTV_PLAYER_PLAY)||PLAYER_STATE_IN(DTV_PLAYER_BT_CONNECT))
    {
        mmi_dtv_player_player_enter_state(DTV_PLAYER_STOPPED);
    }

    /* De-register bt callback when midlet is terminated */
#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_clear_volume_sync_callback(APP_DTV_PLAYER);
#endif
    mmi_frm_end_scenario(MMI_SCENARIO_ID_HIGH_SCRN);

    /* Reset paramter */
    dtv_player_p->cl_preview_layer_handle = 0;
    dtv_player_p->cl_blt_layer_flag = 0;
    dtv_player_p->cl_preview_layer_flag = 0;
    dtv_player_p->cl_preview_layer_offset_x = 0;
    dtv_player_p->cl_preview_layer_offset_y = 0;
    dtv_player_p->cl_preview_layer_width = 0;
    dtv_player_p->cl_preview_layer_height = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_cl_option_screen
 * DESCRIPTION
 *  mobile tv player channel list option menu screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_entry_cl_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_MBBMS_INIT ||
        dtv_player_p->ca_state == MMI_DTV_CA_STATE_MBBMS)
    {
        mmi_dtv_player_display_popup(
                STR_ID_DTV_PLAYER_SUBSCRIPTION_TABLE_UPDATING,
                MMI_EVENT_FAILURE);
    }
    else
    {
        dtv_player_p->cl_option_menu_gid =
            cui_menu_create(
                GRP_ID_DTV_PLAYER,
                CUI_MENU_SRC_TYPE_RESOURCE,
                CUI_MENU_TYPE_OPTION,
                MENU_ID_DTV_PLAYER_CL_OPTION,
                MMI_FALSE,
                NULL);
        cui_menu_run(dtv_player_p->cl_option_menu_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_option_menu_screen
 * DESCRIPTION
 *  mobile tv player option menu screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_entry_option_menu_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dtv_player_p->option_menu_gid = cui_menu_create(GRP_ID_DTV_PLAYER,
													CUI_MENU_SRC_TYPE_RESOURCE,
													CUI_MENU_TYPE_OPTION,
													MENU_ID_DTV_PLAYER_OPTION,
													MMI_FALSE,
													NULL);
    cui_menu_run(dtv_player_p->option_menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_draw_preview_icon
 * DESCRIPTION
 *  hint user it is a broken channel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_draw_preview_icon(dtv_player_preview_icon_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Avoid draw animation on hw updating layer */
    if (PLAYER_STATE_IN(DTV_PLAYER_PLAY))
    {
        return;
    }
    mdi_util_hw_layer_switch_to_sw_layer(dtv_player_p->cl_preview_layer_handle);
    gdi_layer_push_and_set_active(dtv_player_p->cl_preview_layer_handle);
    gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
    gdi_layer_clear(GDI_COLOR_BLACK);

    switch (type)
    {
        case DTV_PLAYER_PREVIEW_ICON_BROKEN:
            gdi_image_draw_id(0,0,IMG_ID_DTV_BROKEN_CHANNEL);
            break;
        case DTV_PLAYER_PREVIEW_ICON_ACCESS_DENIED:
            gdi_image_draw_id(0,0,IMG_ID_DTV_LOCK);
            break;

        default:
            break;
    }

    gdi_layer_pop_and_restore_active();
    gdi_layer_blt_previous(
        dtv_player_p->cl_preview_layer_offset_x,
        dtv_player_p->cl_preview_layer_offset_y,
        dtv_player_p->cl_preview_layer_offset_x + dtv_player_p->cl_preview_layer_width - 1,
        dtv_player_p->cl_preview_layer_offset_y + dtv_player_p->cl_preview_layer_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_vol_inc
 * DESCRIPTION
 *  The function is to increase volume
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_vol_inc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dtv_player_p->setting.vol_level < DTV_PLAYER_VOL_16)
    {
        dtv_player_p->setting.vol_level ++;
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, (U8) MDI_AUD_VOL_EX_MUTE(dtv_player_p->setting.vol_level));

        dtv_player_p->setting.is_mute = KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_vol_dec
 * DESCRIPTION
 *  The function is to decrease volume
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_vol_dec(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_VOL_DEC;

    if (dtv_player_p->setting.vol_level > DTV_PLAYER_VOL_MUTE)
    {
        dtv_player_p->setting.vol_level --;
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, (U8) MDI_AUD_VOL_EX_MUTE(dtv_player_p->setting.vol_level));

        dtv_player_p->setting.is_mute = KAL_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_pre_highlight_handler
 * DESCRIPTION
 *  channel list pre-highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_pre_highlight_handler(S32 index, MMI_BOOL force_player_stop)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Change to total index first */
    if (dtv_player_p->service_list_type == DTV_PLAYER_FAVORITE_LIST)
    {
        index = mmi_dtv_player_favo_to_total_idx(index);
    }

    if (force_player_stop)
    {
        if (PLAYER_STATE_IN(DTV_PLAYER_PLAY)||PLAYER_STATE_IN(DTV_PLAYER_BT_CONNECT))
        {
            dtv_player_p->last_error = mmi_dtv_player_player_enter_state(DTV_PLAYER_STOPPED);
        }
        return;
    }

    /* When entry or go back to channel list, don't stop the service */
    if (dtv_player_p->setting.selected_channel == index)
    {
        return;
    }

    if ((KERNEL_STATE_IN(DTV_KERNEL_READY) || KERNEL_STATE_IN(DTV_KERNEL_INIT)))
    {
        /* if recorder is recording, don't channel channel */
        if (!RECORDER_STATE_IN(DTV_RECORDER_STOPPED))
        {
            return;
        }

        /* stop player and then stop service */
        if (PLAYER_STATE_IN(DTV_PLAYER_PLAY)||PLAYER_STATE_IN(DTV_PLAYER_BT_CONNECT))
        {
            dtv_player_p->last_error = mmi_dtv_player_player_enter_state(DTV_PLAYER_STOPPED);
        }

        ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);

        ASSERT(ret == MDI_RES_MTV_SUCCEED);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_start_play
 * DESCRIPTION
 *  start play
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_DTV_A2DP_SUPPORT__)
    if (mmi_dtv_player_is_output_to_bt())
    {
        mmi_dtv_player_player_enter_state(DTV_PLAYER_BT_CONNECT);
    }
    else
    {
        mmi_dtv_player_player_enter_state(DTV_PLAYER_PLAY);
    }
#else
    mmi_dtv_player_player_enter_state(DTV_PLAYER_PLAY);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_post_highlight_handler
 * DESCRIPTION
 *  channel list callback for redraw preview screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_post_highlight_handler(gdi_handle preview_handle, U32 blt_layer_flag, U32 preview_layer_flag, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen_id = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_POST_HILIGHT_HDLR);

    dtv_player_p->cl_preview_layer_handle = preview_handle;
    dtv_player_p->cl_blt_layer_flag = blt_layer_flag;
    dtv_player_p->cl_preview_layer_flag = preview_layer_flag;
    dtv_player_p->cl_preview_layer_offset_x = x;
    dtv_player_p->cl_preview_layer_offset_y = y;
    dtv_player_p->cl_preview_layer_width = width;
    dtv_player_p->cl_preview_layer_height = height;

#if !defined(__MTK_TARGET__)
    if (dtv_player_p->is_before_cat265==TRUE)
    {
        return;
    }
#endif

    /* Reset preview layer as black color and blt */
    if (PLAYER_STATE_IN(DTV_PLAYER_STOPPED))
    {
        mdi_util_hw_layer_switch_to_sw_layer(preview_handle);
        /* If player is PLAYING, Don't reset the layer */
        gdi_layer_push_and_set_active(preview_handle);
        gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
        gdi_layer_blt_previous(x, y, x + width-1, y + height - 1);
    }

    mmi_dtv_player_delay_post_highlight_handler();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_delay_post_highlight_handler
 * DESCRIPTION
 *  channel list callback for redraw preview screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_delay_post_highlight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dtv_player_service_info_struct *info_ptr;
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (KERNEL_STATE_IN(DTV_KERNEL_OPENED) && dtv_player_p->num_services > 0)
    {
        info_ptr = &dtv_player_p->services[dtv_player_p->setting.selected_channel];
        if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_MBBMS_INIT ||
            dtv_player_p->ca_state == MMI_DTV_CA_STATE_MBBMS)
        {
            return;
        }
        else if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_MBBMS_FAIL)
        {
            if (!(info_ptr->service_flags & MEDIA_MTV_SERVICE_CLEAR_TO_AIR))
            {
                /* don't know subscribed or unsubscribed */
                mmi_dtv_player_draw_preview_icon(DTV_PLAYER_PREVIEW_ICON_ACCESS_DENIED);
                return;
            }
        }
        else if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_MBBMS_READY)
        {
            if (info_ptr->service_flags & MEDIA_MTV_SERVICE_UNSUBSCRIBED)
            {
                return;
            }
        }

        ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_INIT);
        if (ret != MDI_RES_MTV_SUCCEED)
        {
            mmi_dtv_player_draw_preview_icon(DTV_PLAYER_PREVIEW_ICON_BROKEN);
        }
    }
    else if (KERNEL_STATE_IN(DTV_KERNEL_READY) && PLAYER_STATE_IN(DTV_PLAYER_STOPPED))
    {
        mmi_dtv_player_entry_play();

        if (dtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
        {
            mmi_dtv_player_draw_preview_icon(DTV_PLAYER_PREVIEW_ICON_BROKEN);
        }

        if (mmi_dtv_player_is_flag_set(DTV_PLAYER_ACCESS_DENIED))
        {
            /* Draw access denied icon */
            mmi_dtv_player_draw_preview_icon(DTV_PLAYER_PREVIEW_ICON_ACCESS_DENIED);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_active_channel_ptr
 * DESCRIPTION
 *  get current active channel pointer
 * PARAMETERS
 *  void
 * RETURNS
 *  S32 active channel idx
 *****************************************************************************/
dtv_player_service_info_struct *mmi_dtv_player_get_active_channel_ptr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    idx = dtv_player_p->setting.selected_channel;
    return &dtv_player_p->services[idx];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_set_selected_service
 * DESCRIPTION
 *  high light handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_set_selected_service(S32 service_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dtv_player_p->setting.selected_channel != service_idx)
    {
        dtv_player_p->prev_selected_service = dtv_player_p->setting.selected_channel;
        mmi_dtv_player_update_service_preview_data(service_idx);
    }
    dtv_player_p->setting.selected_channel = service_idx;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_SELECTED_SERVICE, service_idx, __LINE__);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_highlight_channel_hdlr
 * DESCRIPTION
 *  high light handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_highlight_channel_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dtv_player_service_info_struct* info_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_HILIGHT_HDLR, index);
    /* Change to total index first */
    if (dtv_player_p->service_list_type == DTV_PLAYER_FAVORITE_LIST)
    {
        index = mmi_dtv_player_favo_to_total_idx(index);
    }

    mmi_dtv_player_set_selected_service(index);

    info_ptr = &dtv_player_p->services[index];

    /* Center key */
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_dtv_player_select_channel_to_play, KEY_EVENT_UP);

    /* LSK */

	if (DTV_CMMB_TEST_MODE_OFF == g_cmmb_test_mode)
	{	
	    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
		SetLeftSoftkeyFunction(mmi_dtv_player_entry_cl_option_screen, KEY_EVENT_UP);
	}

    wgui_cat1008_set_preview_name_time((U8*)info_ptr->program_name, (U8*)info_ptr->program_time);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_cat265_get_async_items
 * DESCRIPTION
 *  ?
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_dtv_player_cat265_get_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    dtv_player_service_info_struct* info_ptr;
    CHAR buffer[10];
    CHAR UCS2_buffer[16];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    info_ptr = &dtv_player_p->services[start_indx];

    for (i = 0; i < num_item; ++i)
    {
        sprintf((CHAR *) buffer, "CH%2d", info_ptr->service_number);
        mmi_asc_to_ucs2((CHAR *) UCS2_buffer, (CHAR *) buffer);

        /* subject */
        mmi_ucs2cpy((CHAR*) menuData[i].item_list[0], (CHAR*) &UCS2_buffer[0]);
        mmi_ucs2cpy((CHAR*) menuData[i].item_list[1], (CHAR*) info_ptr->service_name);

        if (info_ptr->service_type == MEDIA_MTV_SERVICE_ANALOG_TV)
        {
            menuData[i].image_list[0] = (PU8) GetImage(IMG_ID_DTV_PLAYER_DTV);
        }

        info_ptr = info_ptr + 1;
    }
    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_channel_list_screen
 * DESCRIPTION
 *  mobile tv player entry channel list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_channel_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_frm_tab_struct *tab_ptr;
    mmi_frm_tab_struct tab_pages_info[DTV_PLAYER_SERVICE_LIST_TYPE_NUM];
    FuncPtr entry_func[DTV_PLAYER_SERVICE_LIST_TYPE_NUM] =
    {
        mmi_dtv_player_entry_tab_all_channel_screen,
        mmi_dtv_player_entry_tab_favorite_channel_screen,
	#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
		mmi_dtv_player_entry_tab_account_manage_screen
	#else /* __MMI_CMMB_CAS_2GPP_SUPPORT__ */ 
        mmi_dtv_player_entry_tab_program_reminder_screen        
	#endif /* __MMI_CMMB_CAS_2GPP_SUPPORT__ */      
    };
    U8 *tab_str[DTV_PLAYER_SERVICE_LIST_TYPE_NUM];
    S32 tab_num, sel_tab;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Assign tab string */
    tab_str[0] = (U8*)GetString(STR_ID_DTV_PLAYER_ALL_CHANNEL);
    tab_str[1] = (U8*)GetString(STR_ID_DTV_PLAYER_FAVORITE_CHANNEL);	
	#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
	tab_str[2] = (U8*)GetString(STR_ID_DTV_PLAYER_ACCOUNT_MANAGE);
	#else
    tab_str[2] = (U8*)GetString(STR_ID_DTV_PLAYER_PROGRAM_REMINDER);
	#endif /* __MMI_CMMB_CAS_2GPP_SUPPORT__ */ 

    for (i = 0; i < DTV_PLAYER_SERVICE_LIST_TYPE_NUM; i++)
    {
        tab_ptr = &tab_pages_info[i];
        tab_ptr->screen_id = SCR_ID_DTV_PLAYER_TAB_ALL_CHANNEL + i;
        tab_ptr->tab_entry_func = entry_func[i];
        tab_ptr->tab_icon = NULL;
        tab_ptr->tab_string = tab_str[i];
    }
	
	#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
		tab_num = DTV_PLAYER_SERVICE_LIST_TYPE_NUM;
	#else /* __MMI_CMMB_CAS_2GPP_SUPPORT__ */		
	    /* Assign tab num */
	    if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_CMMB)
	    {
	        tab_num = 2;
	    }
	    else
	    {
	        tab_num = DTV_PLAYER_SERVICE_LIST_TYPE_NUM;
	    }
	#endif /* __MMI_CMMB_CAS_2GPP_SUPPORT__ */

    if (DTV_CMMB_TEST_MODE_OFF != g_cmmb_test_mode)
    {
    	tab_num= 1;
    }
    if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_MBBMS ||
        dtv_player_p->ca_state == MMI_DTV_CA_STATE_MBBMS_INIT)
    {
        sel_tab = 0;
    }
    else /* MBBMS fail or MBBMS ready */
    {
        sel_tab = dtv_player_p->service_list_type;
    }

    mmi_frm_scrn_tab_enter(
        GRP_ID_DTV_PLAYER,
        SCR_ID_DTV_PLAYER_CHANNEL_LIST,
        NULL,
        mmi_dtv_player_entry_channel_list_screen,
        tab_pages_info,
        tab_num,
        sel_tab);
}
#ifdef __MBBMS_DUAL_SIM_SUPPORT__
/*****************************************************************************
 * FunctionName: mmi_dtv_player_cancel_change_simcard
 * Description
 *     
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-02-07
 *****************************************************************************/
void mmi_dtv_player_cancel_change_simcard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 SelectorItem = DTV_PLAYER_SIM1;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	if (MMI_SIM2 == dtv_player_p->cur_sim)
	{
		SelectorItem = DTV_PLAYER_SIM2;
	}
}

/*****************************************************************************
 * FunctionName: mmi_dtv_player_change_simcard
 * Description
 *     
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-02-07
 *****************************************************************************/
void mmi_dtv_player_change_simcard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	dtv_player_p->cur_sim = DTV_PLAYER_OTHER_SIM(dtv_player_p->cur_sim);
	dtv_player_p->setting.simcard = dtv_player_p->cur_sim;	
	mmi_dtv_player_store_setting();
	mmi_dtv_player_switch_to_mbbms_mode();
}

/*****************************************************************************
 * FunctionName: mmi_dtv_player_sim_support_mbbms
 * Description
 *     
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-02-07
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_sim_support_mbbms(U32 simcard)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL support_status = MMI_TRUE;
	mmi_sim_enum sim = MMI_SIM1;
	srv_nw_info_service_availability_enum avail = SRV_NW_INFO_SA_FULL_SERVICE;
		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (DTV_PLAYER_SIM2 == simcard)
	{
		sim = MMI_SIM2;
	}
#ifdef __MTK_TARGET__
	avail = srv_nw_info_get_service_availability(sim);
#endif
    if (SRV_NW_INFO_SA_FULL_SERVICE != avail)
    {
    	support_status = MMI_FALSE;
    }

	return support_status;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_setting_set_value
 * DESCRIPTION
 *  set DTV PLAYER setting values
 * PARAMETERS
 *  void
 *  idx(?)
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_setting_set_value(MMI_ID sender_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	kal_uint8 brightness = 0;
	kal_uint8 contrast = 0;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	/* Brightness */
	cui_inline_get_value(sender_id, MMI_DTV_BRIGHTNESS_SELECTOR, &brightness);		
	if (brightness != dtv_player_p->setting.brightness)
	{
		dtv_player_p->setting.brightness = brightness;
		mdi_mtv_set_brightness(dtv_player_p->setting.brightness);
	}

	/* Contrast */
	cui_inline_get_value(sender_id, MMI_DTV_CONTRAST_SELECTOR, &contrast);
	if (contrast != dtv_player_p->setting.contrast)
	{
		dtv_player_p->setting.contrast = contrast;
		mdi_mtv_set_contrast(dtv_player_p->setting.contrast);
	}            
	mmi_dtv_player_store_setting();
	mmi_dtv_player_display_popup(STR_GLOBAL_DONE,
								 MMI_EVENT_SUCCESS);
	cui_inline_close(sender_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_settings_screen
 * DESCRIPTION
 *  mobile tv player settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_entry_settings_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_id;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_id = cui_inline_create(GRP_ID_DTV_PLAYER, &g_dtv_setting_inline);
	dtv_player_p->ps_inline_gid = cui_id;

    /* Title icon */
    cui_inline_set_title_icon(
        cui_id,
        DTV_PLAYER_MENU_ICON);

    /* Brightness */
    cui_inline_set_value(
        cui_id,
        MMI_DTV_BRIGHTNESS_SELECTOR,
        (void*)dtv_player_p->setting.brightness);

    cui_inline_set_item_attributes(
        cui_id, MMI_DTV_BRIGHTNESS_SELECTOR, CUI_INLINE_SET_ATTRIBUTE,
        CUI_INLINE_ITEM_SELECT_NO_LOOP);

    /* Contrast */
    cui_inline_set_value(
        cui_id,
        MMI_DTV_CONTRAST_SELECTOR,
        (void*)dtv_player_p->setting.contrast);

    cui_inline_set_item_attributes(
        cui_id, MMI_DTV_CONTRAST_SELECTOR, CUI_INLINE_SET_ATTRIBUTE,
        CUI_INLINE_ITEM_SELECT_NO_LOOP);
	
    cui_inline_run(cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_check_and_restore_valid_drv
 * DESCRIPTION
 *  Check if desired path is ready or not. If not, will restore to valid path.
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
 MMI_BOOL mmi_dtv_player_check_and_restore_valid_drv(MMI_BOOL restore, U16 storage)
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
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL1, 0, __LINE__);
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
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL1, ret, __LINE__);
        if (restore == MMI_FALSE)
        {
            return MMI_FALSE;
        }

        ret = FS_GetDevStatus(SRV_FMGR_PUBLIC_DRV, FS_MOUNT_STATE_ENUM);
        if (ret == FS_NO_ERROR)
        {
            /* change storage to valid drive */
            dtv_player_p->setting.storage = (U16) SRV_FMGR_PUBLIC_DRV;
            mmi_dtv_player_store_setting();
            return MMI_TRUE;
        }
        else
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL1, ret, __LINE__);
            return MMI_FALSE;
        }
    }
}

#ifdef __COSMOS_MMI_PACKAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_set_storage_value
 * DESCRIPTION
 *  mobile tv player set storage value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_storage_select_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_drv_type_enum type;
    const WCHAR *drive;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(dtv_player_p->selected_storage < MMI_DTV_STORAGE_TOTAL_COUNT);
    type = dtv_player_p->storage_type[dtv_player_p->selected_storage];

    drive = srv_fmgr_drv_get_path_by_type(type);
    if (drive != NULL)
    {
        mmi_dtv_player_set_storage(*drive);
    }

    mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_STORAGE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_highlight_storage_hdlr
 * DESCRIPTION
 *  mobile tv player storage setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_highlight_storage_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dtv_player_p->selected_storage = idx;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_storage_screen
 * DESCRIPTION
 *  mobile tv player 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_storage_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 selected_storage = 0;
	S32 type, idx;
    U8 **string_list = NULL;

    S32 storage_num;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_scrn_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_STORAGE,
                NULL,
                mmi_dtv_player_entry_storage_screen,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }
    /* suspend background play */
    mdi_audio_suspend_background_play();

    RegisterHighlightHandler(mmi_dtv_player_highlight_storage_hdlr);

    /* Display phone and card */
    storage_num = 0;
    if (srv_fmgr_drv_is_accessible(
            srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_PHONE_TYPE)))
    {
        dtv_player_p->storage_type[storage_num] = SRV_FMGR_DRV_PHONE_TYPE;
        dtv_player_p->storage_str[storage_num++] = GetString(STR_GLOBAL_PHONE);
    }

    if (srv_fmgr_drv_is_accessible(
            srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
    {
        dtv_player_p->storage_type[storage_num] = SRV_FMGR_DRV_CARD_TYPE;
        dtv_player_p->storage_str[storage_num++] = GetString(STR_GLOBAL_MEMORY_CARD);
    }

    string_list = (U8 **)dtv_player_p->storage_str;

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    /* Hilight index */
    if (guiBuffer == NULL)
    {
         type = srv_fmgr_drv_get_type((U8)dtv_player_p->setting.storage);
         for (idx = 0; idx < MMI_DTV_STORAGE_TOTAL_COUNT; idx ++)
         {
            if (type == dtv_player_p->storage_type[idx])
            {
                selected_storage = idx;
                break;
            }
         }         
    }
    else
    {
         selected_storage = dtv_player_p->selected_storage;
    }

    /* Call enable before showCategory, call change after showCategory */
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory36Screen(
        STR_GLOBAL_STORAGE,
        DTV_PLAYER_MENU_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        storage_num,
        string_list,
        (U16)selected_storage,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_dtv_player_storage_select_handler, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_dtv_player_storage_select_handler, KEY_EVENT_UP);
}

#else /* __COSMOS_MMI_PACKAGE__ */
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_storage_screen
 * DESCRIPTION
 *  mobile tv player storage setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_entry_storage_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_id;
	U8  drive_letter = (U8)(dtv_player_p->setting.storage);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_id = cui_storage_selector_create(GRP_ID_DTV_PLAYER,
										 drive_letter,
                                         CUI_STORAGE_SELECTOR_DRV_TYPE_ACCESIBLE);
    cui_storage_selector_run(cui_id);
}
#endif /* __COSMOS_MMI_PACKAGE__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_update_channel_list
 * DESCRIPTION
 *  command: update channel list from channel list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_update_channel_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_DTV_BLOCK_BG_CALL__
    if (mmi_dtv_player_is_in_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return; /* return directly */
    }
#endif /* __MMI_DTV_BLOCK_BG_CALL__ */

#ifdef __MMI_DTV_UPDATE_SUBSCRIPTION_TABLE__
    if (KERNEL_STATE_IN(DTV_KERNEL_SUB_UPDATING))
    {
        ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);
        ASSERT(ret == MDI_RES_MTV_SUCCEED);
    }
#endif

    if (KERNEL_STATE_IN(DTV_KERNEL_READY)|| KERNEL_STATE_IN(DTV_KERNEL_INIT))
    {
        /* stop service */
        ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);
        ASSERT(ret == MDI_RES_MTV_SUCCEED);
    }

    /* Reset highlight index after stopping original service */
    dtv_player_p->setting.selected_channel = 0;
    dtv_player_p->prev_selected_service = 0;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_SELECTED_SERVICE, 0, __LINE__);

    /* Change service list to total list */
    dtv_player_p->service_list_type = DTV_PLAYER_TOTAL_LIST;

    dtv_player_p->setting.is_channel_list_init = MMI_FALSE;

    mmi_dtv_player_enter_scan_channel();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_remove_active_service
 * DESCRIPTION
 *  The function is to remove active service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_remove_active_service(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    dtv_player_service_info_struct *info_ptr = NULL;
    U8 service_index = 0;
    U32 service_id;
    MMI_BOOL remove_favorite = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info_ptr = mmi_dtv_player_get_active_channel_ptr();
    if (info_ptr->is_favorite == MMI_TRUE)
    {
        remove_favorite = MMI_TRUE;
        service_id = info_ptr->service_id;

        for (service_index = 0; 
		     service_index < dtv_player_p->num_services; 
			 service_index++)
        {
            if (dtv_player_p->services[service_index].service_id == service_id)
            {
                break;
            }
        }

        /* Must find out */
        ASSERT(service_index < dtv_player_p->num_services);
    }
    else
    {
        service_index = dtv_player_p->setting.selected_channel;
    }

    /* Shift the services by one */
    for (i = service_index; i < dtv_player_p->num_services - 1; i ++)
    {
        kal_mem_cpy(
            &dtv_player_p->services[i],
            &dtv_player_p->services[i+1],
            sizeof(dtv_player_service_info_struct));
    }

    /* Decrease the number of total services */
    dtv_player_p->num_services --;
    if (dtv_player_p->num_services == 0)
    {
        dtv_player_p->setting.is_channel_list_init = MMI_FALSE;
    }

    if (remove_favorite == MMI_TRUE)
    {
        /* Decrease the number of favorite services */
        dtv_player_p->num_favorite_services --;

        /* If favorite list is empty, go to service list automatically */
        if (dtv_player_p->num_favorite_services == 0)
        {
            dtv_player_p->head_of_favorite_service = NULL;
        }
        else
        {
            /* Re-assign favorite list double linked list again */
            mmi_dtv_player_assign_favorite_service_info();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_highlight_app
 * DESCRIPTION
 *  mobile tv player menu item highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_highlight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetLeftSoftkeyFunction(mmi_dtv_player_launch, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_dtv_player_launch, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_config_option_menu
 * DESCRIPTION
 *  mobile tv player configure option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_config_option_menu(MMI_ID send_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dtv_player_service_info_struct *info_ptr = NULL;
#if defined(__MMI_DTV_A2DP_SUPPORT__) && !defined(__MMI_A2DP_HIDE_BT_SETTINGS__)
    MMI_BOOL bt_menu = MMI_TRUE;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    info_ptr = &dtv_player_p->services[dtv_player_p->setting.selected_channel];

    /* check, hide, full display interactivity service */
#ifdef __MBBMS_INTER__  
    if (dtv_player_p->num_imd == 0)
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_OPTION_CHECK_INTER_SERVICE, MMI_TRUE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_OPTION_HIDE_INTER_SERVICE, MMI_TRUE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_OPTION_FULL_DISPLAY_INTER_SERVICE, MMI_TRUE);
    }
    else
    {
        if (dtv_player_p->int_state == DTV_PLAYER_INT_STATE_OFF)
        {
            /* check */
            cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_OPTION_CHECK_INTER_SERVICE, MMI_FALSE);
            cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_OPTION_HIDE_INTER_SERVICE, MMI_TRUE);
            cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_OPTION_FULL_DISPLAY_INTER_SERVICE, MMI_FALSE);
        }
        else if (dtv_player_p->int_state == DTV_PLAYER_INT_STATE_ONE_LINE)
        {
            /* check, hide */
            cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_OPTION_CHECK_INTER_SERVICE, MMI_FALSE);
            cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_OPTION_HIDE_INTER_SERVICE, MMI_FALSE);
            cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_OPTION_FULL_DISPLAY_INTER_SERVICE, MMI_FALSE);
     
        }
        else if (dtv_player_p->int_state == DTV_PLAYER_INT_STATE_HALF_SCREEN)
        {
            /* Full display */
            cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_OPTION_CHECK_INTER_SERVICE, MMI_TRUE);
            cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_OPTION_HIDE_INTER_SERVICE, MMI_TRUE);
            cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_OPTION_FULL_DISPLAY_INTER_SERVICE, MMI_FALSE);
     
        }
    }
    
#endif /* __MBBMS_INTER__ */

    /* Program list */
    if (dtv_player_p->has_esg_info == MMI_FALSE &&
        dtv_player_p->ca_state == MMI_DTV_CA_STATE_CMMB)
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_OPTION_PROGRAM_LIST, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_OPTION_PROGRAM_LIST, MMI_FALSE);
    }
    /* Add to favorite, delete from favorite */
    if (info_ptr->is_favorite == MMI_TRUE)
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_OPTION_ADD_TO_FAVORITES, MMI_TRUE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_OPTION_DEL_FROM_FAVORITES, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_OPTION_ADD_TO_FAVORITES, MMI_FALSE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_OPTION_DEL_FROM_FAVORITES, MMI_TRUE);
    }

    /* Emergency broadcast */
    cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_OPTION_EMERGENCY_BROADCAST, MMI_FALSE);

#if defined(__MMI_DTV_RECORD_SUPPORT__) || defined(__MMI_DTV_SNAPSHOT_SUPPORT__)
    /* if it is recording, hide some menu */
    if (!RECORDER_STATE_IN(DTV_RECORDER_STOPPED)
#ifdef __USB_IN_NORMAL_MODE__
        || srv_usb_is_in_mass_storage_mode()
#endif
        )
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_OPTION_STORAGE, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_OPTION_STORAGE, MMI_FALSE);
    }
#else
    cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_OPTION_STORAGE, MMI_TRUE);
#endif /* __MMI_DTV_RECORD_SUPPORT__ */


#if defined(__MMI_DTV_A2DP_SUPPORT__) && !defined(__MMI_A2DP_HIDE_BT_SETTINGS__)

    if (!mmi_bt_is_to_display_bt_menu())
    {
        bt_menu = MMI_FALSE;
    }

    if (bt_menu)
    {
        cui_menu_set_item_hidden(send_id, MENU_ID_DTV_PLAYER_OPTION_BLUETOOTH_SETTING, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(send_id, MENU_ID_DTV_PLAYER_OPTION_BLUETOOTH_SETTING, MMI_TRUE);
    }
#endif  /* __MMI_DTV_A2DP_SUPPORT__ && !__MMI_A2DP_HIDE_BT_SETTINGS__ */

#ifdef __MDI_MTV_VIDEO_PROCESSING_SUPPORT__
    cui_menu_set_item_hidden(send_id, MENU_ID_DTV_PLAYER_OPTION_SETTING, MMI_FALSE);
#else
    cui_menu_set_item_hidden(send_id, MENU_ID_DTV_PLAYER_OPTION_SETTING, MMI_TRUE);
#endif


}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_config_cl_option_menu
 * DESCRIPTION
 *  mobile tv player configure channel list option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_config_cl_option_menu(MMI_ID send_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dtv_player_service_info_struct *info_ptr = NULL;
    S32 num_menu_items = 0;
    S32 idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_MBBMS_MTS_SUPPORT__
    if (dtv_player_p->display_mts_menu)
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_MTS_SG_RETRIEVE, MMI_FALSE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_MTS_GBA, MMI_FALSE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_MTS_SUBSCRIPTION_UPDATE, MMI_FALSE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_MTS_MSK_RETRIEVE, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_MTS_SG_RETRIEVE, MMI_TRUE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_MTS_GBA, MMI_TRUE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_MTS_SUBSCRIPTION_UPDATE, MMI_TRUE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_MTS_MSK_RETRIEVE, MMI_TRUE);
    }
#endif /* __MMI_MBBMS_MTS_SUPPORT__ */
    /* Program list, channel details */
    if (!(dtv_player_p->ca_state == MMI_DTV_CA_STATE_CMMB &&
          dtv_player_p->has_esg_info == MMI_FALSE))
    {
        cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_CL_OPTION_PROGRAM_LIST, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_CL_OPTION_PROGRAM_LIST, MMI_TRUE);
    }

    /* Search program , setting, help */
    if (dtv_player_p->ca_state != MMI_DTV_CA_STATE_CMMB)
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_CL_OPTION_SEARCH_PROGRAM, MMI_FALSE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_CL_OPTION_MANAGE_ORDER, MMI_FALSE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_CL_OPTION_SETTING, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_CL_OPTION_SEARCH_PROGRAM, MMI_TRUE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_CL_OPTION_MANAGE_ORDER, MMI_TRUE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_CL_OPTION_SETTING, MMI_TRUE);
    }


    if (dtv_player_p->service_list_type == DTV_PLAYER_TOTAL_LIST)
    {
        num_menu_items = dtv_player_p->num_services;
    }
    else if (dtv_player_p->service_list_type == DTV_PLAYER_FAVORITE_LIST)
    {
        num_menu_items = dtv_player_p->num_favorite_services;
    }
#ifndef __MMI_CMMB_CAS_2GPP_SUPPORT__
    else if (dtv_player_p->service_list_type == DTV_PLAYER_PROG_REMINDER_LIST)
    {
        num_menu_items = dtv_player_p->num_schedules;
    }
#endif
    if(num_menu_items == 0)
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_CL_OPTION_PLAY, MMI_TRUE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_CL_OPTION_UPDATE, MMI_FALSE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_CL_OPTION_ADD_TO_FAVORITES, MMI_TRUE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_CL_OPTION_DEL_FROM_FAVORITES, MMI_TRUE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_CL_OPTION_CANCEL_REMINDER, MMI_TRUE);

        return;
    }

    ASSERT(num_menu_items > 0);

    /* play */
    cui_menu_set_item_hidden(
        send_id, MENU_ID_DTV_PLAYER_CL_OPTION_PLAY, MMI_FALSE);


    /* Band, Update, delete, rename */
    if (!RECORDER_STATE_IN(DTV_RECORDER_STOPPED))
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_CL_OPTION_UPDATE, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_CL_OPTION_UPDATE, MMI_FALSE);
    }

    if (dtv_player_p->service_list_type == DTV_PLAYER_PROG_REMINDER_LIST)
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_CL_OPTION_DEL_FROM_FAVORITES, MMI_TRUE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_CL_OPTION_ADD_TO_FAVORITES, MMI_TRUE);
    }
    else
    {
        idx = dtv_player_p->setting.selected_channel;
        info_ptr = &dtv_player_p->services[idx];
        if (info_ptr->is_favorite == MMI_TRUE)
        {
            cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_CL_OPTION_ADD_TO_FAVORITES, MMI_TRUE);
            cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_CL_OPTION_DEL_FROM_FAVORITES, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_CL_OPTION_ADD_TO_FAVORITES, MMI_FALSE);
            cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_CL_OPTION_DEL_FROM_FAVORITES, MMI_TRUE);
        }
    }


    /* Cancel reminder */
    if (dtv_player_p->ca_state != MMI_DTV_CA_STATE_CMMB &&
        dtv_player_p->service_list_type == DTV_PLAYER_PROG_REMINDER_LIST)
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_CL_OPTION_CANCEL_REMINDER, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_CL_OPTION_CANCEL_REMINDER, MMI_TRUE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_menu_entry_event_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_menu_entry_event_hdlr(cui_menu_event_struct* menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID sender_id = menu_evt->sender_id;
    MMI_ID menu_id = menu_evt->parent_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* suspend background play */
    mdi_audio_suspend_background_play();

    if (menu_id == MENU_ID_DTV_PLAYER_OPTION)
    {
        mmi_dtv_player_config_option_menu(sender_id);
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_CL_OPTION)
    {
        mmi_dtv_player_config_cl_option_menu(sender_id);
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_PL_OPTION)
    {
        mmi_dtv_player_config_pl_option_menu(sender_id);
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_PD_OPTION)
    {
        mmi_dtv_player_config_pd_option_menu(sender_id);
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_EBL_OPTION)
    {
        /* Do nothing */
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_SPECIFY_CITY_OPTION)
    {
        /* Do nothing */
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_SR_OPTION)
    {
        mmi_dtv_player_config_sr_option_menu(sender_id);
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_MO_OPTION)
    {
        mmi_dtv_player_config_mo_option_menu(sender_id);
    }
    cui_menu_set_currlist_title(sender_id,
							    (WCHAR*)GetString(STR_GLOBAL_OPTIONS),
							    (UI_image_type)GetImage(DTV_PLAYER_MENU_ICON));

#ifdef __MBBMS_V30_OPERA__
	if (MENU_ID_DTV_PLAYER_OPTION_FILE_DOWNLOAD == menu_id)
	{
		cui_menu_set_currlist_title(sender_id,
									(WCHAR*)GetString(STR_ID_DTV_PLAYER_INTER_DOWNLOAD),
									(UI_image_type)GetImage(DTV_PLAYER_MENU_ICON));
		cui_menu_set_item_image(sender_id,
			                    MENU_ID_DTV_PLAYER_OPTION_INTER_MANAGE,
			                    IMG_GLOBAL_L1);
		cui_menu_set_item_image(sender_id,
			                    MENU_ID_DTV_PLAYER_OPTION_INTER_PATH,
			                    IMG_GLOBAL_L2);
	}
#endif /* __MBBMS_V30_OPERA__ */
}

#ifdef __MBBMS_V30_OPERA__
/*****************************************************************************
 * FunctionName: mmi_dtv_player_entry_inter_file_download_screen
 * Description
 *     
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-02-23
 *****************************************************************************/
void mmi_dtv_player_entry_inter_file_download_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	cui_menu_create_and_run(GRP_ID_DTV_PLAYER,
	                        CUI_MENU_SRC_TYPE_RESOURCE,
	                        CUI_MENU_TYPE_APPSUB,
	                        MENU_ID_DTV_PLAYER_OPTION_FILE_DOWNLOAD,
	                        MMI_FALSE,
	                        NULL);
}
/*****************************************************************************
 * FunctionName: mmi_dtv_player_show_files_download_status
 * Description
 *     
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-02-23
 *****************************************************************************/
void mmi_dtv_player_show_files_download_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_da_wap_notify_ind_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    myMsgPtr = (mmi_da_wap_notify_ind_struct*) OslConstructDataPtr(sizeof(mmi_da_wap_notify_ind_struct));
    myMsgPtr->notify = MMI_DA_WAP_NOTIFY_DISPLAY_LIST;
    mmi_frm_send_ilm(MOD_MMI, 
		             MSG_ID_MMI_DA_WAP_NOTIFY_IND, 
		             (oslParaType*)myMsgPtr, 
		             NULL);
	#else
		mmi_dtv_player_display_popup(STR_GLOBAL_NOT_SUPPORTED,
							 	 	 MMI_EVENT_FAILURE);
	#endif
}

/*****************************************************************************
 * FunctionName: mmi_dtv_player_config_donwload_save_path
 * Description
 *     
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-02-23
 *****************************************************************************/
void mmi_dtv_player_config_donwload_save_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_id folder_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	folder_id = cui_folder_selector_create(GRP_ID_DTV_PLAYER,		                       			   
										   (WCHAR*)L"root",
										   CUI_FOLDER_SELECTOR_STYLE_WRITE,
										   CUI_FOLDER_SELECTOR_OPT_FOLDER_TRAVERSE_ALL);		                       			
	cui_folder_selector_set_title(folder_id,
		                          STR_ID_DTV_PLAYER_INTER_PATH,
		                          IMG_ID_DTV_PLAYER_NULL);
	cui_folder_selector_run(folder_id);
}

#endif /* __MBBMS_V30_OPERA__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_menu_select_event_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_menu_select_event_hdlr(cui_menu_event_struct* menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID menu_id = menu_evt->highlighted_menu_id;
    S32 idx;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Channel list option */
    if (menu_id == MENU_ID_DTV_PLAYER_CL_OPTION_PLAY)
    {
        if (dtv_player_p->service_list_type == DTV_PLAYER_PROG_REMINDER_LIST)
        {
            mmi_dtv_player_play_selected_content();
        }
        else
        {
            mmi_dtv_player_select_channel_to_play();
        }
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_CL_OPTION_UPDATE)
    {

        ASSERT(dtv_player_p->ca_state != MMI_DTV_CA_STATE_MBBMS &&
               dtv_player_p->ca_state != MMI_DTV_CA_STATE_MBBMS_INIT);

        if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_CMMB)
        {
            mmi_dtv_player_update_channel_list();
        }
        else /* MBBMS fail or MBBMS ready */
        {
            mmi_dtv_player_entry_update_approach_screen();
        }
    }
    /* Channel list option */
    else if (menu_id == MENU_ID_DTV_PLAYER_CL_OPTION_PROGRAM_LIST)
    {
        if (dtv_player_p->num_services == 0)
        {
            mmi_dtv_player_display_popup(STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE);
        }
        else
        {
            mmi_dtv_player_entry_program_list_screen();
        }
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_CL_OPTION_ADD_TO_FAVORITES)
    {
        mmi_dtv_player_add_favorite(dtv_player_p->setting.selected_channel);
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_CL_OPTION_DEL_FROM_FAVORITES)
    {
        mmi_dtv_player_delete_favorite(dtv_player_p->setting.selected_channel);
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_CL_OPTION_CANCEL_REMINDER)
    {
        mmi_dtv_player_cancel_reminder();
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_CL_OPTION_SEARCH_PROGRAM)
    {
        mmi_dtv_player_entry_search_program_screen();
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_CL_OPTION_MANAGE_ORDER)
    {
        dtv_player_p->mo_list_type = DTV_PLAYER_SUBSCRIBED_ORDER_LIST;
        dtv_player_p->process_type = DTV_PLAYER_PROCESS_TYPE_ACCOUNT_INQUIRY;
    #ifdef __MTK_TARGET__
        mmi_dtv_player_enter_process_screen();
    #else
        mmi_dtv_player_entry_manage_order_screen();
    #endif
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_CL_OPTION_EMERGENCY_BROADCAST)
    {
        mmi_dtv_player_entry_eb_msg_list_screen();
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_CL_OPTION_SETTING)
    {
        mmi_dtv_player_cl_setting_screen_entry();
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_CL_OPTION_HELP)
    {
	#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
		mmi_dtv_player_display_2gpp_help_items();
	#else
		mmi_dtv_player_entry_help_screen();
	#endif
    }
#ifdef __MMI_MBBMS_MTS_SUPPORT__
    else if (menu_id == MENU_ID_DTV_PLAYER_MTS_SG_RETRIEVE)
    {
        g_mtv_mts_command = MMI_TRUE;
        mmi_dtv_player_entry_update_approach_screen();
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_MTS_GBA)
    {
        g_mtv_mts_command = MMI_TRUE;
        dtv_player_p->process_type = DTV_PLAYER_PROCESS_TYPE_GBA;
        mmi_dtv_player_enter_process_screen();
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_MTS_SUBSCRIPTION_UPDATE)
    {
        g_mtv_mts_command = MMI_TRUE;
        dtv_player_p->process_type = DTV_PLAYER_PROCESS_TYPE_SUBSCRIPTION_UPDATE;
        mmi_dtv_player_enter_process_screen();
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_MTS_MSK_RETRIEVE)
    {
        g_mtv_mts_command = MMI_TRUE;
        dtv_player_p->process_type = DTV_PLAYER_PROCESS_TYPE_MSK_RETRIEVE;
        mmi_dtv_player_enter_process_screen();
    }
#endif /* __MMI_MBBMS_MTS_SUPPORT__ */
    /* Program list option */
    else if (menu_id == MENU_ID_DTV_PLAYER_PL_OPTION_PLAY)
    {
        mmi_dtv_player_play_selected_content();
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_PL_OPTION_ADD_REMINDER)
    {
        mmi_dtv_player_add_reminder();
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_PL_OPTION_CANCEL_REMINDER)
    {
        mmi_dtv_player_cancel_reminder();
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_PL_OPTION_ADD_TO_FAVORITES)
    {
        idx = mmi_dtv_player_service_id_to_idx(
                dtv_player_p->selected_content.service_id);
        mmi_dtv_player_add_favorite(idx);
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_PL_OPTION_DEL_FROM_FAVORITES)
    {
        idx = mmi_dtv_player_service_id_to_idx(
                dtv_player_p->selected_content.service_id);
        mmi_dtv_player_delete_favorite(idx);
    }
#ifdef __MBBMS_INTER__    
    else if (menu_id == MENU_ID_DTV_PLAYER_PL_OPTION_CHECK_INTER_SERVICE)
    {
        mmi_dtv_player_interactivity_retrieve();
    }
#endif    
    else if (menu_id == MENU_ID_DTV_PLAYER_PL_OPTION_PROGRAM_DETAILS)
    {
        mmi_dtv_player_entry_program_detail_screen();
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_PL_OPTION_SEARCH_PROGRAM)
    {
        mmi_dtv_player_entry_search_program_screen();
    }    
    /* program detail option */
    else if (menu_id == MENU_ID_DTV_PLAYER_PD_OPTION_PLAY)
    {
        mmi_dtv_player_play_selected_content();
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_PD_OPTION_ADD_REMINDER)
    {
        mmi_dtv_player_add_reminder();
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_PD_OPTION_CANCEL_REMINDER)
    {
        mmi_dtv_player_cancel_reminder();
    }
    /* Manage order option */
    else if (menu_id == MENU_ID_DTV_PLAYER_MO_OPTION_DETAILS)
    {
        mmi_dtv_player_entry_order_detail_screen();
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_MO_OPTION_SUBSCRIBE)
    {
        mmi_dtv_player_display_confirm(STR_ID_DTV_PLAYER_SUBSCRIBE_ASK);
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_MO_OPTION_UNSUBSCRIBE)
    {
        mmi_dtv_player_display_confirm(STR_ID_DTV_PLAYER_UNSUBSCRIBE_ASK);
    }
    /* Emergency broadcast option */
    else if (menu_id == MENU_ID_DTV_PLAYER_EBL_OPTION_OPEN)
    {
        mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_EB_MSG);
        mmi_dtv_player_entry_eb_msg_screen();
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_EBL_OPTION_DELETE)
    {
        mmi_dtv_player_delete_eb_confirm();
    }
    /* Main option */
#ifdef __MBBMS_INTER__
    else if (menu_id == MENU_ID_DTV_PLAYER_OPTION_CHECK_INTER_SERVICE)
    {
        /* Change as off */
        dtv_player_p->int_state = DTV_PLAYER_INT_STATE_OFF;
        
        if (dtv_player_p->num_imd > 1)
        {
            mmi_dtv_player_entry_service_inter_list_screen();
        }
        else
        {
            dtv_player_p->selected_imd = 0;
            mmi_dtv_player_entry_service_inter_screen();
        } 
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_OPTION_HIDE_INTER_SERVICE)
    {
        dtv_player_p->int_state = DTV_PLAYER_INT_STATE_OFF;
        cui_menu_close(dtv_player_p->option_menu_gid);
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_OPTION_FULL_DISPLAY_INTER_SERVICE)
    {   
		/* Change as off */
        dtv_player_p->int_state = DTV_PLAYER_INT_STATE_OFF;
        
        //TODO: pass in which int service
        mmi_dtv_player_entry_service_inter_screen();
    }
#endif /* __MBBMS_INTER__ */       
    else if (menu_id == MENU_ID_DTV_PLAYER_OPTION_PROGRAM_LIST)
    {
        if (dtv_player_p->num_services == 0)
        {
            mmi_dtv_player_display_popup(STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE);
        }
        else
        {
            mmi_dtv_player_entry_program_list_screen();
        }
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_OPTION_ADD_TO_FAVORITES)
    {
        mmi_dtv_player_add_favorite(dtv_player_p->setting.selected_channel);
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_OPTION_DEL_FROM_FAVORITES)
    {
        mmi_dtv_player_delete_favorite(dtv_player_p->setting.selected_channel);
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_OPTION_EMERGENCY_BROADCAST)
    {
        mmi_dtv_player_entry_eb_msg_list_screen();
    } 
#if defined(__MMI_DTV_A2DP_SUPPORT__) && !defined(__MMI_A2DP_HIDE_BT_SETTINGS__)
    else if (menu_id == MENU_ID_DTV_PLAYER_OPTION_BLUETOOTH_SETTING)
    {
        mmi_a2dp_entry_bluetooth_settings();
    }
#endif
    else if (menu_id == MENU_ID_DTV_PLAYER_OPTION_STORAGE)
    {
        mmi_dtv_player_entry_storage_screen();
    }    
    /* Specify city option */
    else if (menu_id == MENU_ID_DTV_PLAYER_SC_OPTION_UPDATE)
    {
        mmi_dtv_player_update_with_city_name();
    }
    /* Search result */
    else if (menu_id == MENU_ID_DTV_PLAYER_SR_OPTION_PLAY)
    {
        mmi_dtv_player_play_selected_content();
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_SR_OPTION_PROGRAM_DETAILS)
    {
        mmi_dtv_player_entry_program_detail_screen();
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_SR_OPTION_ADD_REMINDER)
    {
        mmi_dtv_player_add_reminder();
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_SR_OPTION_CANCEL_REMINDER)
    {
        mmi_dtv_player_cancel_reminder();
    }
    else if (menu_id == MENU_ID_DTV_PLAYER_OPTION_SETTING)
    {
        mmi_dtv_player_entry_settings_screen();
    }
#ifdef __MBBMS_V30_OPERA__
	else if (MENU_ID_DTV_PLAYER_OPTION_FILE_DOWNLOAD == menu_id)
	{
		mmi_dtv_player_entry_inter_file_download_screen();
	}
	else if (MENU_ID_DTV_PLAYER_OPTION_INTER_MANAGE == menu_id)
	{
		mmi_dtv_player_show_files_download_status();
		cui_menu_close(menu_evt->sender_id);
	}
	else if (MENU_ID_DTV_PLAYER_OPTION_INTER_PATH == menu_id)
	{
		mmi_dtv_player_config_donwload_save_path();		
		cui_menu_close(menu_evt->sender_id);
	}
	else if (MENU_ID_DTV_PLAYER_SI_OPTION_CHANGE_AS_HALF == menu_id)
	{
		mmi_dtv_player_half_inter_app_screen();
		cui_menu_close(menu_evt->sender_id);
	}
	
#endif /* __MBBMS_V30_OPERA__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_storage_selector_event_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_storage_selector_event_hdlr(
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
        mmi_dtv_player_set_storage(drive);
    }

    cui_storage_selector_close(storage_evt->sender_id);
}

/*****************************************************************************
 * FunctionName: mmi_dtv_player_snapshot_proc
 * Description
 *     
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-01-14
 *****************************************************************************/
void mmi_dtv_player_snapshot_proc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//FS_Delete(dtv_player_p->snapshot_filename);	
	mmi_frm_scrn_close_active_id();
	mmi_display_popup((UI_string_type) GetString(STR_GLOBAL_DELETED),MMI_EVENT_SUCCESS);
}

/*****************************************************************************
 * FunctionName: mmi_dtv_player_entry_image_view_screen
 * Description
 *    view the snapshot picture 
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-01-14
 *****************************************************************************/
void mmi_dtv_player_entry_image_view_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(GRP_ID_DTV_PLAYER,
				            SCR_ID_DTV_PLAYER_IMAGE_VIEWER,
				            NULL,
				            mmi_dtv_player_entry_image_view_screen,
				            MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }	
    ShowCategory222Screen(0, 0,
						  STR_ID_DTV_PLAYER_NULL, 
						  NULL,
						  STR_GLOBAL_BACK, 
						  IMG_GLOBAL_BACK,
						  GDI_COLOR_WHITE,
						  NULL,
						  (S8 *)dtv_player_p->snapshot_filename,
						  FALSE,
						  NULL,
						  GDI_IMAGE_SRC_FROM_FILE);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_group_proc
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dtv_player_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = NULL;
    cui_storage_selector_result_event_struct *storage_evt = NULL;
    cui_event_inline_common_struct *inline_evt = NULL;
    cui_dtcnt_select_event_struct *dtcnt_evt = NULL;
	#ifdef __MBBMS_V30_OPERA__
	cui_folder_selector_result_event_struct *folder_evt = NULL;
    S32 error_code = FS_NO_ERROR;
    srv_fmgr_fileinfo_struct info;
	#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    #ifdef __COSMOS_MMI_PACKAGE__ 
        case EVT_ID_ASM_FORCE_FREE:
            //TODO: how to do async close when receving the event ??
            mmi_dtv_player_terminate_app();
            break;
    #endif
        case EVT_ID_GROUP_FIRST_ENTRY:
        case EVT_ID_GROUP_ACTIVE:
        case EVT_ID_GROUP_INACTIVE:
            break;
		case EVT_ID_GROUP_GOBACK_IN_END_KEY:
			{
				mmi_dtv_player_display_confirm(STR_ID_DTV_EXIT_ASK);
				return MMI_RET_ERR;
			}
        case EVT_ID_GROUP_DEINIT:
            //maybe no need
            //mmi_dtv_player_del_app_main_scr_hdlr();
            break;
        /**********************************************
         *  Menu CUI
         **********************************************/
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            menu_evt = (cui_menu_event_struct*)evt;
            mmi_dtv_player_menu_entry_event_hdlr(menu_evt);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
        {
            menu_evt = (cui_menu_event_struct*)evt;
            mmi_dtv_player_menu_select_event_hdlr(menu_evt);
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            menu_evt = (cui_menu_event_struct*)evt;
            cui_menu_close(menu_evt->sender_id);
            if (menu_evt->sender_id == dtv_player_p->cl_option_menu_gid)
            {
                dtv_player_p->cl_option_menu_gid = GRP_ID_INVALID;
            }
            else if (menu_evt->sender_id == dtv_player_p->option_menu_gid)
            {
                dtv_player_p->option_menu_gid = GRP_ID_INVALID;
            }
            break;
        }
        /**********************************************
         *  Storage Selector CUI
         **********************************************/
        case EVT_ID_CUI_STORAGE_SELECTOR_RESULT:
        {
            storage_evt = (cui_storage_selector_result_event_struct *)evt;
            mmi_dtv_player_storage_selector_event_hdlr(storage_evt);
            break;
        }
        /**********************************************
         *  Inline Selector CUI
         **********************************************/
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
            if (inline_evt->sender_id == dtv_player_p->ps_inline_gid)
            {
                /* Player Setting */
                mmi_dtv_player_setting_set_value(inline_evt->sender_id);
				#ifndef __MBBMS_DUAL_SIM_SUPPORT__
                cui_inline_close(inline_evt->sender_id);
				#endif
            }
            else if (inline_evt->sender_id == dtv_player_p->setting_inline_gid)
            {
                /* Setting */
            }
            else if (inline_evt->sender_id == dtv_player_p->sp_inline_gid)
            {
                /* Search program */
                mmi_dtv_player_set_search_value(inline_evt->sender_id);
            }
            break;
        }
        /**********************************************
         *  Data Account Selector CUI
         **********************************************/
        case CUI_DTCNT_SELECT_EVENT_RESULT_OK:
        {
            break;
        }
        case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
        case CUI_DTCNT_SELECT_EVENT_CLOSE:
        {
            dtcnt_evt = (cui_dtcnt_select_event_struct*)evt;
        #ifdef __COSMOS_MMI_PACKAGE__
            vcui_dtcnt_select_close(dtcnt_evt->sender_id);
        #else
            cui_dtcnt_select_close(dtcnt_evt->sender_id);
        #endif
            break;
        }
        case CUI_DTCNT_SELECT_EVENT_RESULT_FAILED:
             {
			 	break;
        	 }
		case EVT_ID_CUI_FOLDER_SELECTOR_RESULT:
			{
				#ifdef __MBBMS_V30_OPERA__				
				folder_evt = (cui_folder_selector_result_event_struct *)evt;
				if (folder_evt->result > 0)
				{
                    error_code = cui_folder_selector_get_selected_filepath(folder_evt->sender_id, 
                                                              			   &info, 
                                                                           (WCHAR*)dtv_player_p->folder_path, 
                                                                           (SRV_FMGR_PATH_MAX_LEN+1));
				}
				MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_DTV_VAL2, folder_evt->result, error_code,__LINE__);								
				cui_folder_selector_close(folder_evt->sender_id);
				#endif
				break;
			}
        default:
            break;
    }

    if(cui_menu_is_menu_event(evt->evt_id))
    {
        wgui_inputs_options_menu_handler(evt, GRP_ID_DTV_PLAYER);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_deleting_popup_proc
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
mmi_ret mmi_dtv_player_deleting_popup_proc(mmi_event_struct *evt)
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
            mmi_dtv_player_display_popup(
                STR_GLOBAL_DELETED,
                MMI_EVENT_SUCCESS);

            break;
        }
        default:
        break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_confirm_proc
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
mmi_ret mmi_dtv_player_confirm_proc(mmi_event_struct *evt)
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

    if ((U16)alert->user_tag == STR_ID_DTV_PLAYER_SUBSCRIBE_ASK)
    {
        if (alert->result == MMI_ALERT_CNFM_OK)
        {
            dtv_player_p->process_type = DTV_PLAYER_PROCESS_TYPE_SUBSCRIBE;
            mmi_dtv_player_enter_process_screen();
        }
        else if (alert->result == MMI_ALERT_CNFM_CANCEL)
        {
            mmi_frm_scrn_close_active_id();
        }
    }
    else if ((U16)alert->user_tag == STR_ID_DTV_PLAYER_UNSUBSCRIBE_ASK)
    {
        if (alert->result == MMI_ALERT_CNFM_OK)
        {
            dtv_player_p->process_type = DTV_PLAYER_PROCESS_TYPE_UNSUBSCRIBE;
            mmi_dtv_player_enter_process_screen();
        }
        else if (alert->result == MMI_ALERT_CNFM_CANCEL)
        {
            mmi_frm_scrn_close_active_id();
        }
    }
    else if ((U16)alert->user_tag == STR_ID_DTV_PLAYER_ENTER_MANAGE_ORDER_CONFIRM)
    {
        if (alert->result == MMI_ALERT_CNFM_YES)
        {
            dtv_player_p->mo_list_type = DTV_PLAYER_UNSUBSCRIBED_ORDER_LIST;
            dtv_player_p->process_type = DTV_PLAYER_PROCESS_TYPE_ACCOUNT_INQUIRY;
            mmi_dtv_player_enter_process_screen();
        }
        else if (alert->result == MMI_ALERT_CNFM_NO)
        {
            mmi_dtv_player_set_flag(DTV_PLAYER_IS_SUBSCRIBE_CONFIRM_REJECTED);
            mmi_frm_scrn_close_active_id();
        }
    }
    else if ((U16)alert->user_tag == STR_ID_DTV_PLAYER_NEW_EB_ARRIVAL)
    {
        if (alert->result == MMI_ALERT_CNFM_YES)
        {
            mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_EB_MSG);
            mmi_dtv_player_entry_eb_msg_screen();
        }
        else if (alert->result == MMI_ALERT_CNFM_NO)
        {
            mmi_frm_scrn_close_active_id();
        }
    }
    else if ((U16)alert->user_tag == STR_ID_DTV_EXIT_ASK)
    {
        if (alert->result == MMI_ALERT_CNFM_OK)
        {        
			dtv_player_p->go_back_history = MMI_TRUE;
			mmi_frm_group_close(GRP_ID_DTV_PLAYER);
        }
        else if (alert->result == MMI_ALERT_CNFM_CANCEL)
        {
            mmi_frm_scrn_close_active_id();
        }
    }
	else if ((U16)alert->user_tag == STR_ID_DTV_CHECK_PIC)
	{
		if (alert->result == MMI_ALERT_CNFM_YES)
        {
            mmi_dtv_player_entry_image_view_screen();
        }
        else if (alert->result == MMI_ALERT_CNFM_NO)
        {
            mmi_frm_scrn_close_active_id();
        }
	}
#ifdef __MBBMS_DUAL_SIM_SUPPORT__
	else if ((U16)alert->user_tag == STR_ID_DTV_SIM_CHANGE_NOTIFY1)
	{
		if (alert->result == MMI_ALERT_CNFM_OK)
        {
        	mmi_dtv_player_change_simcard();
        }
        else if (alert->result == MMI_ALERT_CNFM_CANCEL)
        {
        	mmi_dtv_player_cancel_change_simcard();
        }
	}
	else if ((U16)alert->user_tag == STR_ID_DTV_SIM_CHOOSE_NOTIFY)
    {
        if ((alert->result == MMI_ALERT_CNFM_1)
			|| ((alert->result == MMI_ALERT_CNFM_2)))
        {
			dtv_player_p->setting.simcard = MMI_SIM1;
        }
        else if (alert->result == MMI_ALERT_CNFM_3)
        {
			dtv_player_p->setting.simcard = MMI_SIM2;
        }
		mmi_dtv_player_store_setting();
		mmi_dtv_player_enter_app_main();
    }	
#endif
#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
	else if ((U16)alert->user_tag == STR_ID_DTV_2GPP_RESCAN_NOTIFY)
	{		
        if (alert->result == MMI_ALERT_CNFM_1 ||
            alert->result == MMI_ALERT_CNFM_2)
        {           
            mmi_dtv_player_update_channel_list();
        }
        else if (alert->result == MMI_ALERT_CNFM_3)
        {
            mmi_frm_scrn_close_active_id();
        }
	}
#endif
#ifdef __MBBMS_UPGRADE__
    else if ((U16)alert->user_tag == STR_ID_DTV_UPGRADE_NEED_ASK)
    {
        if (alert->result == MMI_ALERT_CNFM_1 ||
            alert->result == MMI_ALERT_CNFM_2)
        {
            mmi_dtv_player_upgrade();
        }
        else if (alert->result == MMI_ALERT_CNFM_3)
        {
            mmi_frm_scrn_close_active_id();
        }
    }
    else if ((U16)alert->user_tag == STR_ID_DTV_UPGRADE_MANDATORY_ASK)
    {
        if (alert->result == MMI_ALERT_CNFM_1 ||
            alert->result == MMI_ALERT_CNFM_2)
        {
            mmi_dtv_player_upgrade();
        }
        else if (alert->result == MMI_ALERT_CNFM_3)
        {
            mmi_dtv_player_terminate_app();
        }
    }
#endif /* __MBBMS_UPGRADE__ */
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_display_confirm
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
void mmi_dtv_player_display_confirm(U16 str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    mmi_confirm_type_enum type = CNFM_TYPE_YESNO;
    WCHAR *str_ptr = NULL, *lsk_ptr = NULL, *rsk_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (str_id)
    {
        case STR_ID_DTV_PLAYER_SUBSCRIBE_ASK:
        {
            type = CNFM_TYPE_OKCANCEL;
            mmi_dtv_player_gen_separate_string(
                (WCHAR*)GetString(STR_ID_DTV_PLAYER_SUBSCRIBE_ASK),
                (WCHAR*)dtv_player_p->selected_order.name, NULL);
            str_ptr = dtv_player_p->info_str_buffer;
            break;
        }
        case STR_ID_DTV_PLAYER_UNSUBSCRIBE_ASK:
        {
            type = CNFM_TYPE_OKCANCEL;

            mmi_dtv_player_gen_separate_string(
                (WCHAR*)GetString(STR_ID_DTV_PLAYER_UNSUBSCRIBE_ASK),
                (WCHAR*)dtv_player_p->selected_order.name, NULL);
            str_ptr = dtv_player_p->info_str_buffer;
            break;
        }
        case STR_ID_DTV_PLAYER_ENTER_MANAGE_ORDER_CONFIRM:
        {
            type = CNFM_TYPE_YESNO;

            mmi_dtv_player_gen_separate_string(
                (WCHAR*)GetString(STR_ID_DTV_PLAYER_ENTER_MANAGE_ORDER_CONFIRM),
                (WCHAR*)dtv_player_p->services[dtv_player_p->setting.selected_channel].service_name,
                NULL);
            str_ptr = dtv_player_p->info_str_buffer;

            break;
        }
        case STR_ID_DTV_PLAYER_NEW_EB_ARRIVAL:
        {
            type = CNFM_TYPE_YESNO;
            str_ptr = get_string(str_id);
            break;
        }
        case STR_ID_DTV_EXIT_ASK:
        {
            type = CNFM_TYPE_OKCANCEL;
            str_ptr = get_string(str_id);
            break;
        }
        case STR_ID_DTV_UPGRADE_NEED_ASK:
        {
            type = CNFM_TYPE_USER_DEFINE;
            str_ptr = get_string(str_id);
            lsk_ptr = get_string(STR_ID_DTV_UPGRADE_NOW);
            rsk_ptr = get_string(STR_GLOBAL_CANCEL);
            break;
        }
	#ifdef __MBBMS_DUAL_SIM_SUPPORT__
		case STR_ID_DTV_SIM_CHOOSE_NOTIFY:
        {
            type = CNFM_TYPE_USER_DEFINE;
            str_ptr = get_string(str_id);
			lsk_ptr = get_string(STR_GLOBAL_SIM_1);
			rsk_ptr = get_string(STR_GLOBAL_SIM_2);
            break;
        }
		case STR_ID_DTV_SIM_CHANGE_NOTIFY1:
		{
			type = CNFM_TYPE_OKCANCEL;
			str_ptr = get_string(STR_ID_DTV_SIM_CHANGE_NOTIFY1 + (dtv_player_p->cur_sim - 1));
			break;
		}
	#endif
	#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
		case STR_ID_DTV_2GPP_RESCAN_NOTIFY:
		{
            type = CNFM_TYPE_USER_DEFINE;
            str_ptr = get_string(str_id);
			lsk_ptr = get_string(STR_ID_DTV_2GPP_RESCAN);
			rsk_ptr = get_string(STR_GLOBAL_BACK);
			break;
		}
	#endif
        case STR_ID_DTV_UPGRADE_MANDATORY_ASK:
        {
            type = CNFM_TYPE_USER_DEFINE;
            str_ptr = get_string(str_id);
            lsk_ptr = get_string(STR_ID_DTV_UPGRADE_NOW);
            rsk_ptr = get_string(STR_GLOBAL_EXIT);
            break;
        }
		case STR_ID_DTV_CHECK_PIC:
		{
			type = CNFM_TYPE_YESNO;
			str_ptr = dtv_player_p->info_str_buffer;
			break;
		}
        default:
            ASSERT(0);
            break;
    }

    mmi_confirm_property_init(&arg, type);
    arg.callback = mmi_dtv_player_confirm_proc;
    arg.user_tag = (void *)str_id;
    arg.f_auto_map_empty_softkey = MMI_TRUE;
    arg.f_msg_icon = MMI_FALSE;

    if (type == CNFM_TYPE_USER_DEFINE)
    {
        arg.softkey[0].str = lsk_ptr;
        arg.softkey[1].img = GetImage(IMG_GLOBAL_COMMON_CSK);
        arg.softkey[2].str = rsk_ptr;
    }


    mmi_confirm_display(
        str_ptr,
        MMI_EVENT_QUERY,
        &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_reset_to_channel_list_screen
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_reset_to_channel_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Avoid reentry */
    mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_CHANNEL_LIST);
    mmi_dtv_player_entry_channel_list_screen();

    if (dtv_player_p->cl_option_menu_gid != GRP_ID_INVALID)
    {
        cui_menu_close(dtv_player_p->cl_option_menu_gid);
        dtv_player_p->cl_option_menu_gid = GRP_ID_INVALID;
    }
    mmi_frm_scrn_multiple_close(
        GRP_ID_DTV_PLAYER,
        SCR_ID_DTV_PLAYER_CHANNEL_LIST,
        0,
        0,
        SCR_ID_DTV_PLAYER_APP_BASE,
        0);

    if (mmi_dtv_player_is_flag_set(DTV_PLAYER_DELAY_UPDATE_EB_MSG))
    {
        mmi_dtv_player_update_eb_msg();
        mmi_dtv_player_unset_flag(DTV_PLAYER_DELAY_UPDATE_EB_MSG);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_dummy
 * DESCRIPTION
 *  dummy function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_dummy(void)
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
 *  mmi_dtv_player_register_key_hdlr
 * DESCRIPTION
 *  register key event hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_register_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 left_arrow  = KEY_LEFT_ARROW;
    U16 right_arrow = KEY_RIGHT_ARROW;
    U16 up_arrow    = KEY_UP_ARROW;
    U16 key_type    = right_arrow;
	dtv_player_icon_status_enum status = DTV_PLAYER_ICON_STATUS_ENABLE;	
	dtv_player_icon_status_enum status2 = DTV_PLAYER_ICON_STATUS_ENABLE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifndef __MMI_DTV_LANDSCAPE_SUPPORT__
    if (MMI_FRM_SCREEN_ROTATE_270 == dtv_player_p->ui_rotate)
    {
        left_arrow = KEY_UP_ARROW;
        right_arrow = KEY_DOWN_ARROW;
        up_arrow = KEY_RIGHT_ARROW;
    }
#endif

    mmi_dtv_player_config_functions_by_state();
    ClearInputEventHandler(MMI_DEVICE_KEY);
    mmi_dtv_player_reset_key_handler(mmi_dtv_player_fade_in);

    if (DTV_PLAYER_ICON_STATUS_ENABLE == g_dtv_player_osd_cntx.lsk.status)
    {
        SetKeyHandler(mmi_dtv_player_lsk_icon_press, KEY_LSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_dtv_player_lsk_icon_release, KEY_LSK, KEY_EVENT_UP);
    }
    SetKeyHandler(mmi_dtv_player_rsk_icon_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_dtv_player_rsk_icon_release, KEY_RSK, KEY_EVENT_UP);
    SetKeyHandler(mmi_dtv_player_vol_inc_icon_press, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_dtv_player_vol_inc_icon_release, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(mmi_dtv_player_vol_dec_icon_press, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_dtv_player_vol_dec_icon_release, KEY_VOL_DOWN, KEY_EVENT_UP);

    /* fullscreen */
    if((DTV_PLAYER_ICON_STATUS_ENABLE == g_dtv_player_osd_cntx.fullscreen.status)
	   || (DTV_PLAYER_ICON_STATUS_CLICKED == g_dtv_player_osd_cntx.fullscreen.status))
    {
        /* If user long presses fullscreen icon, then time-shift is enabled. */
        SetKeyHandler(mmi_dtv_player_fullscreen_icon_press, KEY_STAR, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_dtv_player_dummy, KEY_STAR, KEY_EVENT_LONG_PRESS);
        SetKeyHandler(mmi_dtv_player_dummy, KEY_STAR, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_dtv_player_fullscreen_icon_release, KEY_STAR, KEY_EVENT_UP);
    }

    /* play */
    if ((DTV_PLAYER_ICON_STATUS_ENABLE == g_dtv_player_osd_cntx.play.status)
		&& (MMI_FRM_SCREEN_ROTATE_0 == dtv_player_p->ui_rotate))
    {
        SetKeyHandler(mmi_dtv_player_play_icon_press, KEY_CSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_dtv_player_dummy, KEY_CSK, KEY_EVENT_LONG_PRESS);
        SetKeyHandler(mmi_dtv_player_dummy, KEY_CSK, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_dtv_player_play_icon_release, KEY_CSK, KEY_EVENT_UP);
    }

#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
    /* change */
    if ((DTV_PLAYER_ICON_STATUS_ENABLE == g_dtv_player_osd_cntx.change.status)
		&& (MMI_FRM_SCREEN_ROTATE_0 == dtv_player_p->ui_rotate))
    {
        SetKeyHandler(mmi_dtv_player_change_icon_press, KEY_POUND, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_dtv_player_dummy, KEY_POUND, KEY_EVENT_LONG_PRESS);
        SetKeyHandler(mmi_dtv_player_dummy, KEY_POUND, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_dtv_player_change_icon_release, KEY_POUND, KEY_EVENT_UP);
    }

    /* forward */
    if ((DTV_PLAYER_ICON_STATUS_ENABLE == g_dtv_player_osd_cntx.forward.status)
		&& (MMI_DTV_OSD_MODE_TIME_SHIFT == dtv_player_p->osd_mode))
    {
        SetKeyHandler(mmi_dtv_player_forward_icon_press, right_arrow, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_dtv_player_dummy, right_arrow, KEY_EVENT_LONG_PRESS);
        SetKeyHandler(mmi_dtv_player_dummy, right_arrow, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_dtv_player_forward_icon_release, right_arrow, KEY_EVENT_UP);
    }
    else
    {
        gui_cancel_timer(mmi_dtv_player_forward_icon_press);
    }

    /* rewind */
    if ((DTV_PLAYER_ICON_STATUS_ENABLE == g_dtv_player_osd_cntx.rewind.status)
		&& (MMI_DTV_OSD_MODE_TIME_SHIFT == dtv_player_p->osd_mode))
    {
        SetKeyHandler(mmi_dtv_player_rewind_icon_press, left_arrow, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_dtv_player_dummy, left_arrow, KEY_EVENT_LONG_PRESS);
        SetKeyHandler(mmi_dtv_player_dummy, left_arrow, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_dtv_player_rewind_icon_release, left_arrow, KEY_EVENT_UP);
    }
    else
    {
        gui_cancel_timer(mmi_dtv_player_rewind_icon_press);
    }
#endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */

    SetKeyHandler(mmi_dtv_player_vol_status_icon_press, KEY_POUND, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_dtv_player_dummy, KEY_POUND, KEY_EVENT_LONG_PRESS);
    SetKeyHandler(mmi_dtv_player_dummy, KEY_POUND, KEY_EVENT_REPEAT);
    SetKeyHandler(mmi_dtv_player_vol_status_icon_release, KEY_POUND, KEY_EVENT_UP);

#if defined(__MMI_DTV_RECORD_SUPPORT__) || defined(__MMI_DTV_SNAPSHOT_SUPPORT__)
    /* record */
    if((DTV_PLAYER_ICON_STATUS_ENABLE == g_dtv_player_osd_cntx.record.status)
        && (MMI_FRM_SCREEN_ROTATE_0 == dtv_player_p->ui_rotate))
    {
        SetKeyHandler(mmi_dtv_player_record_icon_press, KEY_CAMERA, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_dtv_player_dummy, KEY_CAMERA, KEY_EVENT_LONG_PRESS);
        SetKeyHandler(mmi_dtv_player_dummy, KEY_CAMERA, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_dtv_player_record_icon_release, KEY_CAMERA, KEY_EVENT_UP);
    #if defined(MT6238_EVB) || defined(MT6223_CIF_BB)
        SetKeyHandler(mmi_dtv_player_record_icon_press, KEY_0, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_dtv_player_dummy, KEY_0, KEY_EVENT_LONG_PRESS);
        SetKeyHandler(mmi_dtv_player_dummy, KEY_0, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_dtv_player_record_icon_release, KEY_0, KEY_EVENT_UP);
    #endif
    }
#endif /* defined(__MMI_DTV_RECORD_SUPPORT__) || defined(__MMI_DTV_SNAPSHOT_SUPPORT__)*/

    if (dtv_player_p->num_services > 0)
    {
    	status = dtv_player_p->active_osd_cntx_p->channel_next.status;
        if ((DTV_PLAYER_ICON_STATUS_ENABLE == status)
            && (MMI_DTV_OSD_MODE_CHANNEL == dtv_player_p->osd_mode))
        {
            key_type = right_arrow;
            SetKeyHandler(mmi_dtv_player_channel_next_icon_press, 
				          key_type, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_dtv_player_dummy, key_type, KEY_EVENT_LONG_PRESS);
            SetKeyHandler(mmi_dtv_player_dummy, key_type, KEY_EVENT_REPEAT);
            SetKeyHandler(mmi_dtv_player_channel_next_icon_release, 
				          key_type, KEY_EVENT_UP);
        }
        else
        {
            gui_cancel_timer(mmi_dtv_player_channel_next_icon_press);
        }

	    status = dtv_player_p->active_osd_cntx_p->channel_prev.status;
        if (DTV_PLAYER_ICON_STATUS_ENABLE== status)
        {
            key_type = left_arrow;
            SetKeyHandler(mmi_dtv_player_channel_prev_icon_press, 
				          key_type, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_dtv_player_dummy, key_type, KEY_EVENT_LONG_PRESS);
            SetKeyHandler(mmi_dtv_player_dummy, key_type, KEY_EVENT_REPEAT);
            SetKeyHandler(mmi_dtv_player_channel_prev_icon_release, 
				          key_type, KEY_EVENT_UP);
        }
        else
        {
            gui_cancel_timer(mmi_dtv_player_channel_prev_icon_press);
        }
		
        if ((DTV_PLAYER_ICON_STATUS_ENABLE == g_dtv_player_osd_cntx.cycle.status)
            && (MMI_FRM_SCREEN_ROTATE_0 == dtv_player_p->ui_rotate))
        {
            SetKeyHandler(mmi_dtv_player_cycle_icon_press, up_arrow, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_dtv_player_dummy, up_arrow, KEY_EVENT_LONG_PRESS);
            SetKeyHandler(mmi_dtv_player_dummy, up_arrow, KEY_EVENT_REPEAT);
            SetKeyHandler(mmi_dtv_player_cycle_icon_release, up_arrow, KEY_EVENT_UP);
        }
		status  = dtv_player_p->active_osd_cntx_p->channel_next.status;
		status2 = dtv_player_p->active_osd_cntx_p->channel_prev.status;
        if ((DTV_PLAYER_ICON_STATUS_ENABLE ==  status) 
			|| (DTV_PLAYER_ICON_STATUS_ENABLE == status2))
        {
            SetKeyHandler(mmi_dtv_player_key_1_press,KEY_1,KEY_EVENT_DOWN);
            SetKeyHandler(mmi_dtv_player_key_2_press,KEY_2,KEY_EVENT_DOWN);
            SetKeyHandler(mmi_dtv_player_key_3_press,KEY_3,KEY_EVENT_DOWN);
            SetKeyHandler(mmi_dtv_player_key_4_press,KEY_4,KEY_EVENT_DOWN);
            SetKeyHandler(mmi_dtv_player_key_5_press,KEY_5,KEY_EVENT_DOWN);
            SetKeyHandler(mmi_dtv_player_key_6_press,KEY_6,KEY_EVENT_DOWN);
            SetKeyHandler(mmi_dtv_player_key_7_press,KEY_7,KEY_EVENT_DOWN);
            SetKeyHandler(mmi_dtv_player_key_8_press,KEY_8,KEY_EVENT_DOWN);
            SetKeyHandler(mmi_dtv_player_key_9_press,KEY_9,KEY_EVENT_DOWN);
        #if !defined(MT6238_EVB) && !defined(MT6223_CIF_BB)
            SetKeyHandler(mmi_dtv_player_key_0_press,KEY_0,KEY_EVENT_DOWN);
        #endif
        }
    }

    /* register AVRCP */
#if defined(__MMI_DTV_AVRCP_SUPPORT__)
    mmi_bt_avrcp_set_cmd_hdlr(mmi_dtv_player_bt_avrcp_cmd_hdlr);
#endif

#if defined(__MMI_TOUCH_SCREEN__)
    /* register pen down/up/move event */
    wgui_register_pen_down_handler(mmi_dtv_player_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_dtv_player_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_dtv_player_pen_move_hdlr);
#endif /* __MMI_TOUCH_SCREEN__  */

#ifdef __MBBMS_V30_OPERA__
	if ((MMI_FRM_SCREEN_ROTATE_0 == dtv_player_p->ui_rotate) 
		&& (DTV_PLAYER_INT_STATE_HALF_SCREEN == dtv_player_p->int_state))
	{
		mmi_dtv_player_opera_register_key_hdlr();
	}
#endif /* __MBBMS_INTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_config_functions_by_state
 * DESCRIPTION
 *  CONFIG functions according to states.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_config_functions_by_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 total_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* LSK */
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        mmi_dtv_player_disable_lsk_function();
    }
    else if (RECORDER_STATE_IN(DTV_RECORDER_RECORD))
    {
        mmi_dtv_player_disable_lsk_function();
    }
    else
    {
        mmi_dtv_player_enable_lsk_function();
    }

#if defined(__MMI_DTV_RECORD_SUPPORT__)
    if (RECORDER_STATE_IN(DTV_RECORDER_RECORD))
    {
        /* play icon */
        mmi_dtv_player_disable_play_function();
    }
    else
#endif  /* __MMI_DTV_RECORD_SUPPORT__ */      
    {
        /* play icon */
        mmi_dtv_player_enable_play_function();
    }
    
#ifdef __MBBMS_INTER__
    if (dtv_player_p->int_state == DTV_PLAYER_INT_STATE_HALF_SCREEN)
    {
        mmi_dtv_player_disable_view_function();			
        mmi_dtv_player_disable_play_function();
        mmi_dtv_player_disable_fullscreen_function();
        mmi_dtv_player_disable_switch_channel_function();
    #if defined(__MDI_DTV_TIME_SHIFT_SUPPORT__)
        mmi_dtv_player_disable_timeshift_function();
    #elif defined(__MMI_DTV_RECORD_SUPPORT__) || defined(__MMI_DTV_SNAPSHOT_SUPPORT__)
        mmi_dtv_player_disable_record_function();
    #endif
        return; /* DON NOT REMOVE */
    }

    if (dtv_player_p->int_state == DTV_PLAYER_INT_STATE_ONE_LINE &&
        dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        mmi_dtv_player_enable_view_function();
    }
    else
    {
        mmi_dtv_player_disable_view_function();
    }
#endif /* __MBBMS_INTER__ */    

    mmi_dtv_player_enable_fullscreen_function();
    total_num = dtv_player_p->num_services;

    if (KERNEL_STATE_IN(DTV_KERNEL_READY))
    {
        if (total_num > 1 && RECORDER_STATE_IN(DTV_RECORDER_STOPPED)
        #ifdef __MMI_DTV_BLOCK_BG_CALL__
            && mmi_dtv_player_is_in_background_call() == MMI_FALSE
        #endif /* __MMI_DTV_BLOCK_BG_CALL__ */
            )
        {
            mmi_dtv_player_enable_switch_channel_function();
        }
        else
        {
            mmi_dtv_player_disable_switch_channel_function();
        }

    #if defined(__MDI_DTV_TIME_SHIFT_SUPPORT__)
        if (RECORDER_STATE_IN(DTV_RECORDER_RECORD) ||
            mmi_dtv_player_is_flag_set(DTV_PLAYER_PLAYER_STARTED) &&
            dtv_player_p->is_timeshift_enable == MMI_TRUE &&
            dtv_player_p->is_ready_to_ts == MMI_TRUE &&
            mmi_dtv_player_is_in_background_call() == MMI_FALSE &&
            PLAYER_STATE_IN(DTV_PLAYER_PLAY))
        {
            mmi_dtv_player_enable_timeshift_function();
        }
        else
        {
            mmi_dtv_player_disable_timeshift_function();
        }
    #elif defined(__MMI_DTV_RECORD_SUPPORT__) || defined(__MMI_DTV_SNAPSHOT_SUPPORT__)
        /* No timeshift -> player don't have pause state. Only playing state support record, snapshot function */
        if (RECORDER_STATE_IN(DTV_RECORDER_RECORD) ||
            dtv_player_p->storage_status == DTV_PLAYER_STORAGE_OK &&
            mmi_dtv_player_is_flag_set(DTV_PLAYER_PLAYER_STARTED) &&
            mmi_dtv_player_is_in_background_call() == MMI_FALSE &&
            PLAYER_STATE_IN(DTV_PLAYER_PLAY))
        {
            mmi_dtv_player_enable_record_function();
        }
        else
        {
            mmi_dtv_player_disable_record_function();
        }
    #endif /* defined(__MMI_DTV_RECORD_SUPPORT__) || defined(__MMI_DTV_SNAPSHOT_SUPPORT__) */

    }
    else
    {
        if (total_num > 1
        #ifdef __MMI_DTV_BLOCK_BG_CALL__
            && mmi_dtv_player_is_in_background_call() == MMI_FALSE
        #endif /* __MMI_DTV_BLOCK_BG_CALL__ */
            )
        {
            mmi_dtv_player_enable_switch_channel_function();
        }
        else
        {
            mmi_dtv_player_disable_switch_channel_function();
        }
    #if defined(__MDI_DTV_TIME_SHIFT_SUPPORT__)
        mmi_dtv_player_disable_timeshift_function();
    #elif defined(__MMI_DTV_RECORD_SUPPORT__) || defined(__MMI_DTV_SNAPSHOT_SUPPORT__)
        mmi_dtv_player_disable_record_function();
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_set_blt_layer
 * DESCRIPTION
 *  The function sets blt layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_set_blt_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle layer_3 = GDI_NULL_HANDLE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 
                                   | GDI_LAYER_ENABLE_LAYER_1 
                                   | GDI_LAYER_ENABLE_LAYER_2;
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
    #ifdef __MBBMS_INTER__    
        if (dtv_player_p->int_state != DTV_PLAYER_INT_STATE_OFF)
        {
            layer_3 = dtv_player_p->dls_layer_handle;
            dtv_player_p->blt_layer_flag |= GDI_LAYER_ENABLE_LAYER_3;
        }
    #endif /* __MBBMS_INTER__ */  
    
        gdi_layer_set_blt_layer(
            dtv_player_p->display_layer_handle,
            dtv_player_p->osd_layer_handle,
            dtv_player_p->status_bar_layer_handle,
            layer_3);
    }
    else
    {
        gdi_layer_set_blt_layer(
            dtv_player_p->display_layer_handle,
            dtv_player_p->osd_layer_handle,
            dtv_player_p->dls_layer_handle,
            0);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_init_service_in_app_screen
 * DESCRIPTION
 *  mobile tv player entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_init_service_in_app_screen(MMI_BOOL avoid_infinite_pop)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR str_buf[MMI_DTV_NAME_STR_LENGTH] = {0};
    CHAR str_buf2[MMI_DTV_NAME_STR_LENGTH] = {0};
    dtv_player_service_info_struct *info_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    info_ptr = &dtv_player_p->services[dtv_player_p->setting.selected_channel];

    ASSERT(dtv_player_p->ca_state != MMI_DTV_CA_STATE_MBBMS_INIT &&
           dtv_player_p->ca_state != MMI_DTV_CA_STATE_MBBMS);

    if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_MBBMS_FAIL)
    {
        if (!(info_ptr->service_flags & MEDIA_MTV_SERVICE_CLEAR_TO_AIR))
        {
            /* don't know subscribed or unsubscribed */
            mmi_dtv_player_set_hint(
                (CHAR *) GetString((U16)(STR_ID_DTV_PLAYER_NOTIFY_UNKNOWN_STATE)),
				(CHAR *) NULL,
			    MMI_DTV_PLAYER_HINT_POPUP_NO_FADE,
                MMI_TRUE);
            return MMI_TRUE;
        }
    }
    else if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_MBBMS_READY)
    {
        if (info_ptr->service_flags & MEDIA_MTV_SERVICE_UNSUBSCRIBED)
        {
            if (avoid_infinite_pop && mmi_dtv_player_is_flag_set(DTV_PLAYER_IS_SUBSCRIBE_CONFIRM_REJECTED))
            {
                /* don't know subscribed or unsubscribed */
                mmi_dtv_player_set_hint(
                    (CHAR *) GetString((U16)(STR_ID_DTV_PLAYER_NOTIFY_ACCESS_DENIED)),
					(CHAR *) NULL,
				    MMI_DTV_PLAYER_HINT_POPUP_NO_FADE,
                    MMI_TRUE);
                return MMI_TRUE;
            }
            else
            {
            #ifdef __MMI_DTV_UPDATE_SUBSCRIPTION_TABLE__
                dtv_player_p->last_error = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_SUB_UPDATING);
                if (dtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
                {
                    mmi_dtv_player_display_confirm(STR_ID_DTV_PLAYER_ENTER_MANAGE_ORDER_CONFIRM);
                    return MMI_FALSE;
                }
                else
                {
                    mmi_dtv_player_set_hint(
                        (CHAR *) GetString((U16)(STR_ID_DTV_PLAYER_NOTIFY_LOADING)),
                        (CHAR *) NULL,
                        MMI_DTV_PLAYER_HINT_POPUP_NO_FADE,
                        MMI_TRUE);
                    return MMI_TRUE;
                }
            #else
                mmi_dtv_player_display_confirm(STR_ID_DTV_PLAYER_ENTER_MANAGE_ORDER_CONFIRM);
                return MMI_FALSE;
            #endif
            }
        }
    }

    /* enter initialize state */
    dtv_player_p->last_error = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_INIT);

    if (dtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
    {
        if (mmi_dtv_player_is_flag_set(DTV_PLAYER_UNAVAILABLE_IN_CALL))
        {
            mmi_dtv_player_set_hint(
                    (CHAR *) GetString((U16)(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL)),
					(CHAR *) NULL,
			        MMI_DTV_PLAYER_HINT_POPUP_NO_FADE,
                    MMI_TRUE);
        }
        else
        {
            /* if no services, show hint on screen */
            mmi_dtv_player_set_hint(
                (CHAR *) GetString((U16) (STR_ID_DTV_PLAYER_SERVICE_IS_NOT_AVAILABLE)),
				(CHAR *) NULL,
			     MMI_DTV_PLAYER_HINT_POPUP_NO_FADE,
                 MMI_TRUE);
            mmi_dtv_player_set_flag(DTV_PLAYER_SERVICE_UNAVAILABLE);
        }
    }
    else
    {
        mmi_dtv_player_prepare_channel_name_hint(str_buf, str_buf2);

        mmi_dtv_player_set_hint(
            (CHAR *) str_buf,
            (CHAR *) str_buf2,
            MMI_DTV_PLAYER_HINT_POPUP_FADE_TIME,
            MMI_FALSE);
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_app_screen
 * DESCRIPTION
 *  mobile tv player entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_entry_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    CHAR str_buf[MMI_DTV_NAME_STR_LENGTH] = {0};
    CHAR str_buf2[MMI_DTV_NAME_STR_LENGTH] = {0};
#ifdef __MMI_TVOUT__
    mdi_mtv_service_type_enum service_type;
#endif /* __MMI_TVOUT__ */
    MMI_BOOL ret, auto_connect = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_APP,
                mmi_dtv_player_exit_app_screen,
                mmi_dtv_player_entry_app_screen,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

#if defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
    gdi_bltdb_enable(GDI_BLTDB_ENABLE_ONLY_WHEN_HW_UPDATE);
#endif
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
    gui_screen_switch_effect_block(MMI_TRUE);
#endif
    mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGH_SCRN);

    /* set ther blt mode to make osd blt immediate */
    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    mmi_frm_scrn_set_leave_proc(
        GRP_ID_DTV_PLAYER,
        SCR_ID_DTV_PLAYER_APP,
        mmi_dtv_player_app_screen_leave_proc);

    mmi_dtv_player_unset_flag(DTV_PLAYER_UNAVAILABLE_IN_CALL);

    gdi_lcd_set_rotate_by_layer(TRUE);

    /* initialize flags */
    dtv_player_p->hint_state = DTV_PLAYER_HINT_STATE_HIDE;
    dtv_player_p->is_key_pressed = MMI_FALSE;
    dtv_player_p->is_ts_bar_enable = MMI_TRUE;
    dtv_player_p->anim_handle = 0;
    dtv_player_p->fullscr_osd_opacity = MMI_DTV_PLAYER_OSD_FADEOUT_FACTOR;
    dtv_player_p->is_changing_channel_by_key = MMI_FALSE;
    dtv_player_p->change_to_channel = 0;
    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_NONE;
#ifdef __MMI_TOUCH_SCREEN__
    dtv_player_p->is_pen_down = MMI_FALSE;
#endif

    dtv_player_p->dynamic_label_state = DTV_PLAYER_DYNAMIC_LABEL_OFF;
#ifdef __MBBMS_INTER__
    dtv_player_p->dynamic_inter_state = DTV_PLAYER_DYNAMIC_LABEL_OFF;
#endif
    /* Reset ui rotate */
    if (guiBuffer == NULL)
    {
        dtv_player_p->is_favorite_list_org = MMI_FALSE;
        dtv_player_p->osd_mode = MMI_DTV_OSD_MODE_CHANNEL;
        dtv_player_p->ui_rotate = MMI_FRM_SCREEN_ROTATE_0;
        mmi_dtv_player_unset_flag(DTV_PLAYER_DISBLE_AUTO_PLAY);
    }

    /* Turn on LCD TE */
    gdi_lcd_te_ctrl_push(KAL_TRUE, dtv_player_p->te_ctrl_handle);

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

    /* suspend background play */
    mdi_audio_suspend_background_play();

    /* Register bt callback */
#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_register_volume_sync_callback(
        APP_DTV_PLAYER,
        MDI_AUD_VOL_LEVEL_EXTEND_MUTE,
        mmi_dtv_player_bt_volume_sync_hdlr);
#endif

#ifdef __MBBMS_CITY_LIST__
    mmi_dtv_player_free_city_mem();
#endif 

    /* init adm related resource */
    mmi_dtv_player_alloc_adm_layer();
    /* init adm related resource */
    mmi_dtv_player_alloc_base_layer();

    /* init screen-based related resource */
    mmi_dtv_player_alloc_resource();

    /* clear drawing layer if player not in pause state */
    if (!PLAYER_STATE_IN(DTV_PLAYER_PAUSE))
    {
        mmi_dtv_player_clear_preview_layer();
    }

    mmi_dtv_player_config_functions_by_state();

    /* Config blt layer */
    mmi_dtv_player_set_blt_layer();

    /* check storage to handle the case that card plug in/out pop up on other screen */
    mmi_dtv_player_check_storage(MMI_FALSE, dtv_player_p->setting.storage);

    if (dtv_player_p->prev_storage_status != dtv_player_p->storage_status)
    {
        if (dtv_player_p->storage_status == DTV_PLAYER_STORAGE_OK)
        {
        #ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
            mdi_mtv_enable_timeshift(dtv_player_p->mtv_handle, (PU8)dtv_player_p->storage_filepath);
            dtv_player_p->is_ready_to_ts = MMI_TRUE;
            if (KERNEL_STATE_IN(DTV_KERNEL_READY))
            {
                /* It will draw signal icon, MUST put after layer is OK */
                mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);
            }
        #elif defined(__MMI_DTV_RECORD_SUPPORT__)
            mdi_mtv_set_storage(dtv_player_p->mtv_handle, (PU8)dtv_player_p->storage_filepath);
        #endif
        }
        else
        {
        #ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
            mdi_mtv_disable_timeshift(dtv_player_p->mtv_handle);
        #endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */
            dtv_player_p->is_ready_to_ts = MMI_FALSE;
            /* reset ts info */
            dtv_player_p->max_timeshift_delay = 0;
            dtv_player_p->play_delay = 0;
            dtv_player_p->max_delay = 0;
        }
    }

    /* Delay blt signal icon, cmmb logo, dynamic layer */
    gdi_layer_lock_frame_buffer();

    /* Update player status */
    if (KERNEL_STATE_IN(DTV_KERNEL_READY) && dtv_player_p->is_timeshift_enable)
    {
        mmi_dtv_player_player_update_cyclic();
    }

    mmi_dtv_player_draw_osd();

    /* Draw status icon */
    mmi_dtv_player_draw_signal_icon();

    gdi_layer_unlock_frame_buffer();


    gdi_layer_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

    /* For small screen: only draw osd */
    if (mmi_is_redrawing_bk_screens())
    {
        return;
    }
    mmi_dtv_player_display_eb_notification();

    mmi_dtv_player_update_service_preview_data(
        dtv_player_p->setting.selected_channel);

    /* Following: Check different state */
    if (KERNEL_STATE_IN(DTV_KERNEL_READY))
    {
        mmi_dtv_player_prepare_channel_name_hint(str_buf,str_buf2);

        mmi_dtv_player_set_hint(
            (CHAR *) str_buf,
            (CHAR *) str_buf2,
            MMI_DTV_PLAYER_HINT_POPUP_FADE_TIME,
            MMI_FALSE);

        mmi_dtv_player_register_key_hdlr();

        /* To make TV syncs with LCD, draw hint before play.  */
        mmi_dtv_player_draw_osd();
        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

        if (RECORDER_STATE_IN(DTV_RECORDER_SAVE_CONFIRM))
        {
            mmi_dtv_player_enter_save_confirm();
            return;
        }
        else if (PLAYER_STATE_IN(DTV_PLAYER_STOPPED) || PLAYER_STATE_IN(DTV_PLAYER_PAUSE))
        {
            if (mmi_dtv_player_is_flag_set(DTV_PLAYER_DISBLE_AUTO_PLAY))
            {
                return;
            }

            mmi_dtv_player_entry_play();
        }

        if (mmi_dtv_player_is_flag_set(DTV_PLAYER_UNAVAILABLE_IN_CALL))
        {
            mmi_dtv_player_set_hint(
                    (CHAR *) GetString((U16)(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL)),
					(CHAR *) NULL,
			        MMI_DTV_PLAYER_HINT_POPUP_NO_FADE,
                    MMI_TRUE);
        }

        mmi_dtv_player_draw_osd_and_blt();

        /* After the main screen is drawn, check if there is a delayed record error */
        mmi_dtv_player_check_and_display_delayed_record_error();
    }
    else if (KERNEL_STATE_IN(DTV_KERNEL_OPENED))
    {
        if (dtv_player_p->num_services == 0)
        {
            /* if no services, show hint on screen */
            mmi_dtv_player_set_hint(
                (CHAR *) GetString((U16) (STR_ID_DTV_PLAYER_NO_SERVICE_AVAILABLE)),
				(CHAR *) NULL,
			    MMI_DTV_PLAYER_HINT_POPUP_NO_FADE,
                MMI_TRUE);
        }
        else
        {
            if (mmi_dtv_player_is_flag_set(DTV_PLAYER_DISBLE_AUTO_PLAY))
            {
                auto_connect = MMI_FALSE;
            }

            if (auto_connect)
            {
                ret = mmi_dtv_player_init_service_in_app_screen(MMI_TRUE);
                if (ret == MMI_FALSE)
                {
                    return;
                }
            }
        }
        mmi_dtv_player_register_key_hdlr();
        mmi_dtv_player_draw_osd_and_blt();
    }
    else if (KERNEL_STATE_IN(DTV_KERNEL_INIT))
    {
        mmi_dtv_player_prepare_channel_name_hint(str_buf, str_buf2);
        mmi_dtv_player_set_hint(
            (CHAR *) str_buf,
            (CHAR *) str_buf2,
            MMI_DTV_PLAYER_HINT_POPUP_FADE_TIME,
            MMI_FALSE);
        mmi_dtv_player_register_key_hdlr();
        mmi_dtv_player_draw_osd();
        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }
    else
    {
        /* kernel is in wrong state when entering mtv player */
        ASSERT(0);
    }
#ifdef __MBBMS_INTER__
    /*update imd infor when entry app screen except first time*/
    mmi_dtv_player_update_imd_count();
#ifdef __MBBMS_V30_OPERA__
    if (dtv_player_p->int_state == DTV_PLAYER_INT_STATE_HALF_SCREEN)
    {
		mmi_dtv_player_opera_engine_restart(dtv_player_p->opera_layer_handle);
    }
#endif
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_exit_app_screen
 * DESCRIPTION
 *  mobile tv player exit screen handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_exit_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MBBMS_V30_OPERA__
    if (dtv_player_p->int_state == DTV_PLAYER_INT_STATE_HALF_SCREEN)
    {
        mmi_dtv_player_opera_engine_pause();
    }
#endif
#ifdef __MMI_DTV_UPDATE_SUBSCRIPTION_TABLE__
    if (KERNEL_STATE_IN(DTV_KERNEL_SUB_UPDATING))
    {
        ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);
        ASSERT(ret == MDI_RES_MTV_SUCCEED);
    }
#endif
    /* Avoid auto play */
    if (KERNEL_STATE_IN(DTV_KERNEL_INIT))
    {
        /* Restore previous selected service */
        ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);
        ASSERT(ret == MDI_RES_MTV_SUCCEED);
    }

    if (RECORDER_STATE_IN(DTV_RECORDER_RECORD))
    {
        /* Only stop recorder. Enter save_confirm screen when entry again */
        mmi_dtv_player_recorder_enter_state(DTV_RECORDER_SAVE_CONFIRM);
    }

    if (PLAYER_STATE_IN(DTV_PLAYER_PLAY) || PLAYER_STATE_IN(DTV_PLAYER_BT_CONNECT))
    {
        mmi_dtv_player_player_enter_state(DTV_PLAYER_STOPPED);
    }

    /* reset some icons which will not be checked when entering application screen */
    mmi_dtv_player_reset_all_icon();

    gdi_lcd_set_rotate_by_layer(FALSE);

#ifdef __MMI_TVOUT__
    if (dtv_player_p->is_tvout_fullscreen == MMI_TRUE)
    {
        /* change to normal screen */
        mdi_tvout_set_owner(MDI_TV_OWNER_GDI);

        /* restore back to mode 1 */
        mdi_tvout_set_mode(MDI_TV_MODE_LCD_SCR, 0, 0);

        dtv_player_p->is_tvout_fullscreen = MMI_FALSE;
    }
#endif /* __MMI_TVOUT__ */

    gui_cancel_timer(mmi_dtv_player_hide_hint);
    gui_cancel_timer(mmi_dtv_player_jump_to_channel);
    gui_cancel_timer(mmi_dtv_player_rewind_icon_press);
    gui_cancel_timer(mmi_dtv_player_forward_icon_press);
    gui_cancel_timer(mmi_dtv_player_record_start_record);
    gui_cancel_timer(mmi_dtv_player_fullscr_osd_fade_cyclic);
    gui_cancel_timer(mmi_dtv_player_channel_prev_icon_press);
    gui_cancel_timer(mmi_dtv_player_channel_next_icon_press);
    gui_cancel_timer(mmi_dtv_player_vol_inc_icon_press);
    gui_cancel_timer(mmi_dtv_player_vol_dec_icon_press);
    StopTimer(DTV_PLAYER_UPDATE_PLAYER_STATUS);
    StopTimer(DTV_PLAYER_VOLUME_ICON_TIMER);

	mmi_dtv_player_stop_eb_animation();
	mmi_dtv_player_unset_flag(DTV_PLAYER_DISPLAY_EB_WARNING_STRING);

    /* Stop scrolling */
    if (dtv_player_p->dynamic_label_state != DTV_PLAYER_DYNAMIC_LABEL_OFF)
    {
        mmi_dtv_player_clear_dynamic_label();
    }

#ifdef __MBBMS_INTER__
	if (DTV_PLAYER_DYNAMIC_LABEL_OFF != dtv_player_p->dynamic_inter_state)
	{
        mmi_dtv_player_clear_description();
	}
#endif
    /* Reset base layer here */
    mmi_dtv_player_free_base_layer();

    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
       /* clear base as black for TV out */
       gdi_layer_clear(GDI_COLOR_BLACK);
    }
    else
    {
      
       gdi_layer_flatten_to_base(
            dtv_player_p->display_layer_handle,
            dtv_player_p->osd_layer_handle,
            dtv_player_p->status_bar_layer_handle,
            GDI_NULL_HANDLE);
    }

#if defined(__MMI_DTV_AVRCP_SUPPORT__)
    mmi_bt_avrcp_clear_cmd_hdlr(mmi_dtv_player_bt_avrcp_cmd_hdlr);
#endif

    /* De-register bt callback when midlet is terminated */
#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_clear_volume_sync_callback(APP_DTV_PLAYER);
#endif

    /* resume alignment timer */
    UI_enable_alignment_timers();

    /* enable multi-layer */
    gdi_layer_multi_layer_disable();

    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    leave_full_screen();

    /* Restore LCD TE */
    gdi_lcd_te_ctrl_pop(dtv_player_p->te_ctrl_handle);

    /* Free layer and release memory */
    mmi_dtv_player_free_resource();

    mmi_dtv_player_free_adm_layer();

    /* save setting */
    mmi_dtv_player_store_setting();

    mmi_frm_end_scenario(MMI_SCENARIO_ID_HIGH_SCRN);
#if defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
    gdi_bltdb_disable();
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_display_popup_str
 * DESCRIPTION
 *
 * PARAMETERS
 *  S16     IN      stringid
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_display_popup_str(WCHAR *string, mmi_event_notify_enum event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;
    mmi_frm_screen_rotate_enum rotate = MMI_FRM_SCREEN_ROTATE_0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(mmi_frm_scrn_is_present(
        GRP_ID_DTV_PLAYER,
        SCR_ID_DTV_PLAYER_APP,
        MMI_FRM_NODE_ALL_FLAG))
    {
        rotate = dtv_player_p->ui_rotate;
    }

    mmi_popup_property_init(&arg);
#if defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_DTV_LANDSCAPE_SUPPORT__)
    arg.rotation = rotate;
#endif
#if !defined(__MMI_FTE_SUPPORT__)
    arg.f_msg_icon = MMI_FALSE;
#endif
    arg.parent_id = GRP_ID_DTV_PLAYER;
    mmi_popup_display(string, event_id, &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_display_success_popup
 * DESCRIPTION
 *
 * PARAMETERS
 *  S16     IN      stringid
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_display_popup(U16 string_id, mmi_event_notify_enum event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_dtv_player_display_popup_str((WCHAR*)get_string(string_id), event_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_display_failure_popup
 * DESCRIPTION
 *
 * PARAMETERS
 *  S16     IN      stringid
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_display_failure_popup(MDI_RESULT ret)
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
    mmi_dtv_player_display_popup((U16)string_id, popup_type);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_storage_file_path
 * DESCRIPTION
 *  get current active storage file path.
 * PARAMETERS
 *  filepath        [OUT]       File path
 * RETURNS
 * BOOL
 *****************************************************************************/
 MMI_BOOL mmi_dtv_player_get_storage_file_path(U16 storage, CHAR * filepath, dtv_player_storage_path_enum path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_wsprintf((WCHAR *) filepath, "%c:\\", (CHAR *)storage);

    if (path == DTV_PLAYER_STORAGE_PATH_VIDEO)
    {
        mmi_ucs2cat((CHAR *) filepath, (CHAR *) MMI_DTV_PLAYER_STORAGE_FILEPATH);
    }
    else if (path == DTV_PLAYER_STORAGE_PATH_PHOTO)
    {
        mmi_ucs2cat((CHAR *) filepath, 
			        (CHAR *) MMI_DTV_PLAYER_STORAGE_FILEPATH_PHOTOS);
    }
    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_create_file_dir
 * DESCRIPTION
 *  create directly from a file path (resursivly)
 * PARAMETERS
 *  filepath        [IN]        File path to create
 * RETURNS
 *  S32
 *****************************************************************************/
 S32 mmi_dtv_player_create_file_dir(CHAR *filepath)
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

    file_handle = FS_Open((WCHAR*) filepath, FS_OPEN_DIR | FS_READ_ONLY);

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

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_set_storage
 * DESCRIPTION
 *  set storage callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_set_storage(WCHAR drv_letter)
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
    if (drv_letter == dtv_player_p->setting.storage)
    {
        mmi_dtv_player_display_popup(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS);
    }
    else
    {
        event_type = mmi_dtv_player_check_storage(MMI_FALSE, drv_letter);

        if (dtv_player_p->storage_status == DTV_PLAYER_STORAGE_OK)
        {
            mmi_dtv_player_display_popup(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS);
        #if defined(__MDI_DTV_TIME_SHIFT_SUPPORT__)
            mdi_mtv_enable_timeshift(dtv_player_p->mtv_handle, (PU8)dtv_player_p->storage_filepath);
        #elif defined(__MMI_DTV_RECORD_SUPPORT__)
            mdi_mtv_set_storage(dtv_player_p->mtv_handle, (PU8)dtv_player_p->storage_filepath);
        #endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */

            dtv_player_p->setting.storage = (U16) drv_letter;
            /* storge setting to NVRAM */
            WriteRecord(NVRAM_EF_DTV_PLAYER_SETTING_LID,
                        1,
                        (void*)&dtv_player_p->setting,
                        NVRAM_EF_DTV_PLAYER_SETTING_SIZE, 
                        &error);
        }
        else
        {
            mmi_dtv_player_display_popup(dtv_player_p->err_str_id, event_type);
        #ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
            mdi_mtv_disable_timeshift(dtv_player_p->mtv_handle);
        #endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */
        }
    #ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
        /* NEED TO RECONFIGURE RECORD, so we let kernel enter open state and set prev_storage_status = reset. */
        if (KERNEL_STATE_IN(DTV_KERNEL_READY))
        {
            mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);
        }
    #endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_rsk_icon_press
 * DESCRIPTION
 *  mobile tv player rsk press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_rsk_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_RSK;
    dtv_player_p->active_osd_cntx_p->rsk.status = DTV_PLAYER_ICON_STATUS_CLICKED;
    mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_rsk_icon_release
 * DESCRIPTION
 *  mobile tv player rsk release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_rsk_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dtv_player_p->touch_object != DTV_PLAYER_TOUCH_RSK)
    {
        return;
    }

    dtv_player_p->active_osd_cntx_p->rsk.status = DTV_PLAYER_ICON_STATUS_ENABLE;
    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_NONE;

    mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

    if (RECORDER_STATE_IN(DTV_RECORDER_RECORD))
    {
        mmi_dtv_player_recorder_enter_state(DTV_RECORDER_SAVE_CONFIRM);
        mmi_dtv_player_enter_save_confirm();
    }
#ifdef __MBBMS_INTER__
    else if (dtv_player_p->int_state == DTV_PLAYER_INT_STATE_HALF_SCREEN)
    {
        /* Only normal screen can play inter service with half screen */
        ASSERT(dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0);
        
        dtv_player_p->int_state = DTV_PLAYER_INT_STATE_OFF;
        #ifdef __MBBMS_V30_OPERA__
        mmi_dtv_player_opera_engine_pause();
        #endif
        /* Update blt layer */
        mmi_dtv_player_set_blt_layer();
        mmi_dtv_player_register_key_hdlr();		
        mmi_dtv_player_update_imd_count();
        mmi_dtv_player_draw_osd();
        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }
#endif /* __MBBMS_INTER__ */
    else
    {
        mmi_frm_scrn_close_active_id();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_fade_in
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_fade_in(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* If normal screen, it's dummy function */
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        mmi_dtv_player_fullscr_reset_osd_fade(MMI_TRUE);
        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_lsk_icon_press
 * DESCRIPTION
 *  mobile tv player lsk press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_lsk_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (DTV_CMMB_TEST_MODE_OFF != g_cmmb_test_mode)
	{
		return;
	}
    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_LSK;
    dtv_player_p->active_osd_cntx_p->lsk.status = DTV_PLAYER_ICON_STATUS_CLICKED;
    mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_lsk_icon_release
 * DESCRIPTION
 *  mobile tv player lsk release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_lsk_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (DTV_CMMB_TEST_MODE_OFF != g_cmmb_test_mode)
	{
		return;
	}
    if (dtv_player_p->touch_object != DTV_PLAYER_TOUCH_LSK)
    {
        return;
    }
    dtv_player_p->active_osd_cntx_p->lsk.status = DTV_PLAYER_ICON_STATUS_ENABLE;
    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_NONE;

    mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

    mmi_dtv_player_entry_option_menu_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_record_icon_press
 * DESCRIPTION
 *  mobile tv player record icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_record_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_RECORD;

    if (dtv_player_p->active_osd_cntx_p->record.status == DTV_PLAYER_ICON_STATUS_CLICKED)
    {
        return;
    }
    if (RECORDER_STATE_IN(DTV_RECORDER_STOPPED) ||
        RECORDER_STATE_IN(DTV_RECORDER_RECORD))
    {
        dtv_player_p->touch_object = DTV_PLAYER_TOUCH_RECORD;
        dtv_player_p->active_osd_cntx_p->record.status = DTV_PLAYER_ICON_STATUS_CLICKED;
        mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

        if (RECORDER_STATE_IN(DTV_RECORDER_STOPPED))
        {
            dtv_player_p->is_capture = MMI_TRUE;
            /* Always snapshot even if long press */
        #if defined(__MMI_DTV_RECORD_SUPPORT__)
            gui_start_timer(2000, mmi_dtv_player_record_start_record);
        #endif /*defined(__MMI_DTV_RECORD_SUPPORT__) */
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_record_icon_release
 * DESCRIPTION
 *  mobile tv player record icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_record_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dtv_player_service_info_struct *info_ptr;
    MMI_BOOL ret = MMI_TRUE; /* Must initialize as true */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dtv_player_p->touch_object != DTV_PLAYER_TOUCH_RECORD)
    {
        return;
    }

    dtv_player_p->active_osd_cntx_p->record.status  = DTV_PLAYER_ICON_STATUS_ENABLE;
    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_NONE;

#ifdef __MMI_DTV_RECORD_SUPPORT__
    if (RECORDER_STATE_IN(DTV_RECORDER_RECORD))
    {
        mmi_dtv_player_draw_osd();
        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

        mmi_dtv_player_recorder_enter_state(DTV_RECORDER_SAVE_CONFIRM);
        mmi_dtv_player_enter_save_confirm();

    }
    else
#endif /* __MMI_DTV_RECORD_SUPPORT__ */
    {
        if( dtv_player_p->is_capture == TRUE)
        {
            gui_cancel_timer(mmi_dtv_player_record_start_record);

            /* DAB do not support Snapshot. */
            info_ptr = mmi_dtv_player_get_active_channel_ptr();

            if (info_ptr->service_type == MDI_MTV_SERVICE_TYPE_DIGITAL_TV ||
                info_ptr->service_type == MDI_MTV_SERVICE_TYPE_ANALOG_TV)
            {
                ret = mmi_dtv_player_snapshot();
            }
            else if (info_ptr->service_type == MDI_MTV_SERVICE_TYPE_DIGITAL_RADIO)
            {
                mmi_dtv_player_display_popup(STR_ID_DTV_PLAYER_NOTIFY_RADIO_CANT_SNAPSHOT, MMI_EVENT_FAILURE);

                ret = MMI_FALSE;
            }

            /* DAB or Snapshot success. If Snapshot fail, a pop up screen will display.
               layer will be freed. Don't draw OSD */
            if (ret == MMI_TRUE)
            {
                mmi_dtv_player_draw_osd_and_blt();
            }

            ClearKeyEvents();
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_change_icon_press
 * DESCRIPTION
 *  mobile tv player change icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_change_icon_press(void)
{
#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR str_buf[256];
    MDI_RESULT ret = MDI_RES_MTV_SUCCEED;
    U16 speed;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_CHANGE;
    dtv_player_p->active_osd_cntx_p->change.status = DTV_PLAYER_ICON_STATUS_CLICKED;
    mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
#endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_change_icon_release
 * DESCRIPTION
 *  mobile tv player change icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_change_icon_release(void)
{
#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dtv_player_p->touch_object != DTV_PLAYER_TOUCH_CHANGE)
    {
        return;
    }
    dtv_player_p->is_key_pressed = MMI_FALSE;
    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_NONE;

    if (dtv_player_p->osd_mode == MMI_DTV_OSD_MODE_CHANNEL)
    {
        dtv_player_p->osd_mode = MMI_DTV_OSD_MODE_TIME_SHIFT;
    }
    else
    {
        dtv_player_p->osd_mode = MMI_DTV_OSD_MODE_CHANNEL;
    }

    dtv_player_p->active_osd_cntx_p->change.status  = DTV_PLAYER_ICON_STATUS_ENABLE;
    mmi_dtv_player_draw_osd_and_blt();

    ClearKeyEvents();
#endif /*  __MDI_DTV_TIME_SHIFT_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_cycle_icon_press
 * DESCRIPTION
 *  mobile tv player cycle press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_cycle_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_CYCLE;
    dtv_player_p->active_osd_cntx_p->cycle.status = DTV_PLAYER_ICON_STATUS_CLICKED;

    /* Do nothing */
    mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_cycle_icon_release
 * DESCRIPTION
 *  mobile tv player cycle icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_cycle_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    S32 target_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dtv_player_p->touch_object != DTV_PLAYER_TOUCH_CYCLE)
    {
        return;
    }
    dtv_player_p->is_key_pressed = MMI_FALSE;
    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_NONE;
    dtv_player_p->active_osd_cntx_p->cycle.status  = DTV_PLAYER_ICON_STATUS_ENABLE;

    target_id = dtv_player_p->prev_selected_service;
    ret = mmi_dtv_player_change_channel(target_id);
    if (ret == MMI_FALSE)
    {
        return;
    }

    mmi_dtv_player_draw_osd_and_blt();

    ClearKeyEvents();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_play_icon_press
 * DESCRIPTION
 *  mobile tv player play icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_play_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_PLAY;
    dtv_player_p->active_osd_cntx_p->play.status = DTV_PLAYER_ICON_STATUS_CLICKED;
    mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_play_icon_release
 * DESCRIPTION
 *  mobile tv player play icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_play_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If user presses play key when play icon is disable,
       When user releases play key, touch object is TOUCH_NONE */
    if (dtv_player_p->touch_object != DTV_PLAYER_TOUCH_PLAY)
    {
        return;
    }
    dtv_player_p->active_osd_cntx_p->play.status  = DTV_PLAYER_ICON_STATUS_ENABLE;
    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_NONE;

    if (KERNEL_STATE_IN(DTV_KERNEL_READY))
    {
        if (PLAYER_STATE_IN(DTV_PLAYER_STOPPED))
        {
            mmi_dtv_player_entry_play();
        }
        else
        {
            mmi_dtv_player_set_flag(DTV_PLAYER_DISBLE_AUTO_PLAY);

            mmi_dtv_player_player_enter_state(DTV_PLAYER_STOPPED);
            /* Clear layer as black color */
            mmi_dtv_player_clear_preview_layer();
        }
    }
    else if (KERNEL_STATE_IN(DTV_KERNEL_INIT))
    {
        mmi_dtv_player_set_flag(DTV_PLAYER_DISBLE_AUTO_PLAY);

        mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);
        /* Clear layer as black color */
        mmi_dtv_player_clear_preview_layer();
    }
    else if (KERNEL_STATE_IN(DTV_KERNEL_OPENED))
    {
        ret = mmi_dtv_player_init_service_in_app_screen(MMI_FALSE);
        if (ret == MMI_FALSE)
        {
            return;
        }
    }
#ifdef __MMI_DTV_UPDATE_SUBSCRIPTION_TABLE__
    else if (KERNEL_STATE_IN(DTV_KERNEL_SUB_UPDATING))
    {
        mmi_dtv_player_set_flag(DTV_PLAYER_DISBLE_AUTO_PLAY);

        ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);
        ASSERT(ret == MDI_RES_MTV_SUCCEED);
    }
#endif


    if (dtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
    {
        mmi_dtv_player_display_failure_popup(dtv_player_p->last_error);
        return;
    }

    mmi_dtv_player_register_key_hdlr();

    mmi_dtv_player_draw_osd_and_blt();

    ClearKeyEvents();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_fullscreen_icon_press
 * DESCRIPTION
 *  mobile tv player fullscreen icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_fullscreen_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_FULLSCREEN;
    dtv_player_p->active_osd_cntx_p->fullscreen.status = DTV_PLAYER_ICON_STATUS_CLICKED;
    mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_fullscreen_icon_release
 * DESCRIPTION
 *  mobile tv player fullscreen icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_fullscreen_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    MMI_BOOL need_init = MMI_FALSE;
    MMI_BOOL pause_visual = MMI_FALSE;
    mdi_mtv_player_setting_struct video_setting;
    dtv_player_service_info_struct *info_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    info_ptr = mmi_dtv_player_get_active_channel_ptr();

    dtv_player_p->active_osd_cntx_p->fullscreen.status  = DTV_PLAYER_ICON_STATUS_ENABLE;
    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_NONE;

    /* Draw fullscreen icon at ENABLE state */
    mmi_dtv_player_draw_osd();
    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

#ifdef __MMI_DTV_UPDATE_SUBSCRIPTION_TABLE__
    if (KERNEL_STATE_IN(DTV_KERNEL_SUB_UPDATING))
    {
        ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);
        need_init = MMI_TRUE;
        ASSERT(ret == MDI_RES_MTV_SUCCEED);
    }
#endif
    /* Avoid auto play */
    if (KERNEL_STATE_IN(DTV_KERNEL_INIT))
    {
        /* Restore previous selected service */
        ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);
        ASSERT(ret == MDI_RES_MTV_SUCCEED);
        need_init = MMI_TRUE;
    }


    if (PLAYER_STATE_IN(DTV_PLAYER_PLAY))
    {
        if (info_ptr->service_type == MDI_MTV_SERVICE_TYPE_DIGITAL_TV)
        {
            ret = mdi_mtv_player_pause_visual_update(dtv_player_p->mtv_handle);
            if (ret == MDI_RES_MTV_SUCCEED)
            {
                PLAYER_ENTER_STATE(DTV_PLAYER_STOPPED);
                pause_visual = MMI_TRUE;
            }
            else
            {
                mmi_dtv_player_player_enter_state(DTV_PLAYER_STOPPED);
            }
        }
        else
        {
             mmi_dtv_player_player_enter_state(DTV_PLAYER_STOPPED);
        }
    }
    else if (PLAYER_STATE_IN(DTV_PLAYER_BT_CONNECT))
    {
        mmi_dtv_player_player_enter_state(DTV_PLAYER_STOPPED);
    }

    /* Stop scrolling */
    if (dtv_player_p->dynamic_label_state != DTV_PLAYER_DYNAMIC_LABEL_OFF)
    {
        mmi_dtv_player_clear_dynamic_label();
    }
    #ifdef __MBBMS_INTER__
    if ((MMI_FRM_SCREEN_ROTATE_0 == dtv_player_p->ui_rotate)
		&& (DTV_PLAYER_DYNAMIC_LABEL_OFF != dtv_player_p->dynamic_inter_state))
    {
        mmi_dtv_player_clear_description();		
	}
    #endif
	mmi_dtv_player_stop_eb_animation();
    /* change Rotate */
    dtv_player_p->ui_rotate =(dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)?MMI_FRM_SCREEN_ROTATE_270:MMI_FRM_SCREEN_ROTATE_0;


    /* config osd and dls layer size according to display mode */
    /* The function configures status icon and must put after screen_rotate() */
    mmi_dtv_player_config_layers();

    /* Re-config blt layer */
    mmi_dtv_player_set_blt_layer();

    /* Delay blt signal icon, cmmb logo, dynamic layer */
    gdi_layer_lock_frame_buffer();

    /* Draw DLS scrolling text */
	mmi_dtv_player_display_eb_notification();

    mmi_dtv_player_register_key_hdlr();

    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        mmi_dtv_player_fullscr_reset_osd_fade(MMI_TRUE);
    }
    else
    {
        mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
    }
    /* Draw signal icon */
    mmi_dtv_player_draw_signal_icon();

    gdi_layer_unlock_frame_buffer();

    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

    if (need_init && KERNEL_STATE_IN(DTV_KERNEL_OPENED))
    {
        ret = mmi_dtv_player_init_service_in_app_screen(MMI_FALSE);
        if (ret == MMI_FALSE)
        {
            return;
        }
    }
    else if (KERNEL_STATE_IN(DTV_KERNEL_READY))
    {
        if (PLAYER_STATE_IN(DTV_PLAYER_STOPPED) || PLAYER_STATE_IN(DTV_PLAYER_PAUSE))
        {
            if (pause_visual)
            {
                mmi_dtv_player_player_prepare_player_setting(&video_setting);
                ret = mdi_mtv_player_resume_visual_update(dtv_player_p->mtv_handle, &video_setting);
                if (ret != MDI_RES_MTV_SUCCEED)
                {
                    mdi_mtv_player_stop(dtv_player_p->mtv_handle);
                    mmi_dtv_player_handle_play_fail();
                }
                else
                {
                    PLAYER_ENTER_STATE(DTV_PLAYER_PLAY);
                    /* For snapshot icon */
                    mmi_dtv_player_register_key_hdlr();
                }
            }
            else
            {
                mmi_dtv_player_entry_play();
            }
        }

        if (mmi_dtv_player_is_flag_set(DTV_PLAYER_UNAVAILABLE_IN_CALL))
        {
            mmi_dtv_player_set_hint(
                    (CHAR *) GetString((U16)(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL)),
					(CHAR *) NULL,
			        MMI_DTV_PLAYER_HINT_POPUP_NO_FADE,
                    MMI_TRUE);
        }
    }
    mmi_dtv_player_draw_osd_and_blt();
    #ifdef __MBBMS_INTER__
    if (MMI_FRM_SCREEN_ROTATE_0 == dtv_player_p->ui_rotate)
    {
        mmi_dtv_player_update_imd_count();
	}
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_forward_icon_press
 * DESCRIPTION
 *  mobile tv player forward icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_forward_icon_press(void)
{
#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 delay;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_FORWARD;

    mmi_dtv_player_get_player_status(dtv_player_p->mtv_handle, NULL, &dtv_player_p->play_delay, &dtv_player_p->max_delay, &dtv_player_p->max_timeshift_delay, NULL);

    /* Make delay_step larger when long press */
    if (dtv_player_p->is_key_pressed)
    {
        dtv_player_p->delay_step += MMI_DTV_PLAYER_TS_DELAY_DURATION;
    }
    else /* first time press up arrow */
    {
        dtv_player_p->delay_step = MMI_DTV_PLAYER_TS_DELAY_DURATION;
    }

    delay = dtv_player_p->play_delay - dtv_player_p->delay_step;

    /* Avoid overflow */
    dtv_player_p->play_delay = (delay < 0) ? 0 : delay;

    /* Can not equal to 0. To avoid MED play automatically when player is at PAUSED state */
    if (!PLAYER_STATE_IN(DTV_PLAYER_PLAY) && delay < 1)
    {
        dtv_player_p->play_delay = 1;
    }

    dtv_player_p->last_error = mdi_mtv_player_seek(dtv_player_p->mtv_handle,dtv_player_p->play_delay);
    if (dtv_player_p->play_delay > 1)
    {
        /* Update play_delay */
        mmi_dtv_player_get_player_status(dtv_player_p->mtv_handle, NULL, &dtv_player_p->play_delay, &dtv_player_p->max_delay, &dtv_player_p->max_timeshift_delay, NULL);
    }

    dtv_player_p->active_osd_cntx_p->forward.status = DTV_PLAYER_ICON_STATUS_CLICKED;
    mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

    /* Show error pop up after re-drawing OSD */
    if (dtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
    {
        mmi_dtv_player_display_failure_popup(dtv_player_p->last_error);
        return;
    }

    if (dtv_player_p->play_delay > 1)
    {
        if (dtv_player_p->is_key_pressed)
        {
            gui_start_timer(100, mmi_dtv_player_forward_icon_press);
        }
        else
        {
            /* first time press up arrow, use longer time */
            gui_start_timer(300, mmi_dtv_player_forward_icon_press);
            dtv_player_p->is_key_pressed = MMI_TRUE;
        }
    }
    else /* play_delay <= 1 */
    {
        /* Start to play automatically when seek to end of content */
        if (PLAYER_STATE_IN(DTV_PLAYER_PAUSE))
        {
            mmi_dtv_player_entry_play();
        }
        /* Register play speed key handler */
        mmi_dtv_player_register_key_hdlr();

        /* When long press until seek to end of content, set status as enable */
        dtv_player_p->active_osd_cntx_p->forward.status = DTV_PLAYER_ICON_STATUS_ENABLE;
        mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }
#endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__   */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_forward_icon_release
 * DESCRIPTION
 *  mobile tv player forward icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_forward_icon_release(void)
{
#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dtv_player_p->touch_object != DTV_PLAYER_TOUCH_FORWARD)
    {
        return;
    }

    gui_cancel_timer(mmi_dtv_player_forward_icon_press);
    dtv_player_p->is_key_pressed = MMI_FALSE;
    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_NONE;

    dtv_player_p->active_osd_cntx_p->forward.status  = DTV_PLAYER_ICON_STATUS_ENABLE;
    mmi_dtv_player_draw_osd_and_blt();

    ClearKeyEvents();
#endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__  */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_rewind_icon_press
 * DESCRIPTION
 *  mobile tv player rewind icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_rewind_icon_press(void)
{
#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL begin_of_content = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_REWIND;

    mmi_dtv_player_get_player_status(dtv_player_p->mtv_handle, NULL, &dtv_player_p->play_delay, &dtv_player_p->max_delay, &dtv_player_p->max_timeshift_delay, NULL);

    /* Make delay_step larger when long press */
    if (dtv_player_p->is_key_pressed)
    {
        dtv_player_p->delay_step += MMI_DTV_PLAYER_TS_DELAY_DURATION;
    }
    else /* first time press up arrow */
    {
        dtv_player_p->delay_step = MMI_DTV_PLAYER_TS_DELAY_DURATION;
    }

    dtv_player_p->play_delay += dtv_player_p->delay_step;

    if (dtv_player_p->play_delay > dtv_player_p->max_delay)
    {
        dtv_player_p->play_delay = dtv_player_p->max_delay;
        dtv_player_p->last_error = mdi_mtv_player_seek(dtv_player_p->mtv_handle,(U32)0xFFFFFFFF);
        begin_of_content = MMI_TRUE;
    }
    else
    {
        dtv_player_p->last_error = mdi_mtv_player_seek(dtv_player_p->mtv_handle,dtv_player_p->play_delay);
        /* Update play_delay */
        mmi_dtv_player_get_player_status(dtv_player_p->mtv_handle, NULL, &dtv_player_p->play_delay, &dtv_player_p->max_delay, &dtv_player_p->max_timeshift_delay, NULL);
    }

    dtv_player_p->active_osd_cntx_p->rewind.status = DTV_PLAYER_ICON_STATUS_CLICKED;
    mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

    /* Show error pop up after re-drawing OSD */
    if (dtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
    {
        mmi_dtv_player_display_failure_popup(dtv_player_p->last_error);
        return;
    }

    if (dtv_player_p->play_delay < dtv_player_p->max_delay)
    {
        if (dtv_player_p->is_key_pressed)
        {
            gui_start_timer(100, mmi_dtv_player_rewind_icon_press);
        }
        else
        {
            /* first time press up arrow, use longer time */
            gui_start_timer(300, mmi_dtv_player_rewind_icon_press);
            dtv_player_p->is_key_pressed = MMI_TRUE;
        }
    }
    else
    {
        /* When long press until seek to begin of content, set status as enable */
        dtv_player_p->active_osd_cntx_p->rewind.status = DTV_PLAYER_ICON_STATUS_ENABLE;
        mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }
#endif /*  __MDI_DTV_TIME_SHIFT_SUPPORT__  */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_rewind_icon_release
 * DESCRIPTION
 *  mobile tv player rewind icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_rewind_icon_release(void)
{
#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dtv_player_p->touch_object != DTV_PLAYER_TOUCH_REWIND)
    {
        return;
    }

    gui_cancel_timer(mmi_dtv_player_rewind_icon_press);
    dtv_player_p->is_key_pressed = MMI_FALSE;
    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_NONE;

    /* Register play speed key handler */
    mmi_dtv_player_register_key_hdlr();

    dtv_player_p->active_osd_cntx_p->rewind.status  = DTV_PLAYER_ICON_STATUS_ENABLE;
    mmi_dtv_player_draw_osd_and_blt();

    ClearKeyEvents();
#endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__  */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_vol_inc_icon_press
 * DESCRIPTION
 *  mobile tv player vol_inc icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_vol_inc_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (DTV_PLAYER_VOL_16 > dtv_player_p->setting.vol_level)
    {
        dtv_player_p->setting.vol_level ++;		
		dtv_player_p->setting.is_mute = KAL_FALSE;
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, 
		                     (U8) MDI_AUD_VOL_EX_MUTE(dtv_player_p->setting.vol_level));
    }
	else
	{
		if (KAL_TRUE == dtv_player_p->setting.is_mute)
		{
			dtv_player_p->setting.is_mute = KAL_FALSE;			
			mdi_audio_set_volume(MDI_VOLUME_MEDIA, 
								 (U8) MDI_AUD_VOL_EX_MUTE(dtv_player_p->setting.vol_level));
		}
	}
	
    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_VOL_INC;
    dtv_player_p->active_osd_cntx_p->vol_inc.status = DTV_PLAYER_ICON_STATUS_CLICKED;
    mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
	
    if (dtv_player_p->setting.vol_level < DTV_PLAYER_VOL_16)
    {
        if (dtv_player_p->is_key_pressed)
        {
            gui_start_timer(100, mmi_dtv_player_vol_inc_icon_press);
        }
        else
        {
            /* first time press up arrow, use longer time */
            gui_start_timer(300, mmi_dtv_player_vol_inc_icon_press);
            dtv_player_p->is_key_pressed = MMI_TRUE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_vol_inc_icon_release
 * DESCRIPTION
 *  mobile tv player vol_inc icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_vol_inc_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_dtv_player_vol_inc_icon_press);
    dtv_player_p->is_key_pressed = MMI_FALSE;

    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_NONE;
    dtv_player_p->active_osd_cntx_p->vol_inc.status  = DTV_PLAYER_ICON_STATUS_ENABLE;

    mmi_dtv_player_draw_osd_and_blt();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_vol_dec_icon_press
 * DESCRIPTION
 *  mobile tv player vol_dec icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_vol_dec_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dtv_player_p->setting.vol_level > DTV_PLAYER_VOL_MUTE)
    {
        dtv_player_p->setting.vol_level--;
		if (dtv_player_p->setting.vol_level > DTV_PLAYER_VOL_MUTE)
        {
        	dtv_player_p->setting.is_mute = KAL_FALSE;
		}
		else
		{
			dtv_player_p->setting.is_mute = KAL_TRUE;
		}
		
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, 
			                 (U8) MDI_AUD_VOL_EX_MUTE(dtv_player_p->setting.vol_level));
    }

    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_VOL_DEC;
    dtv_player_p->active_osd_cntx_p->vol_dec.status = DTV_PLAYER_ICON_STATUS_CLICKED;
    mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
	
    if (dtv_player_p->setting.vol_level > DTV_PLAYER_VOL_MUTE)
    {
        if (dtv_player_p->is_key_pressed)
        {
            gui_start_timer(100, mmi_dtv_player_vol_dec_icon_press);
        }
        else
        {
            /* first time press up arrow, use longer time */
            gui_start_timer(300, mmi_dtv_player_vol_dec_icon_press);
            dtv_player_p->is_key_pressed = MMI_TRUE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_vol_dec_icon_release
 * DESCRIPTION
 *  mobile tv player vol_dec icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_vol_dec_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_dtv_player_vol_dec_icon_press);
    dtv_player_p->is_key_pressed = MMI_FALSE;

    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_NONE;

    dtv_player_p->active_osd_cntx_p->vol_dec.status = DTV_PLAYER_ICON_STATUS_ENABLE;

    mmi_dtv_player_draw_osd_and_blt();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_unmute
 * DESCRIPTION
 *  mobile tv player vol_dec icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_unmute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Mobile TV is not opened */
    if (KERNEL_STATE_IN(DTV_KERNEL_CLOSED) || KERNEL_STATE_IN(DTV_KERNEL_CLOSING))
    {
        return;
    }

    if (dtv_player_p->setting.is_mute)
    {
        dtv_player_p->setting.is_mute = MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_vol_status_icon_release
 * DESCRIPTION
 *  mobile tv player vol_dec icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_vol_status_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen;
    MMI_BOOL draw_osd = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Toggle between mute and unmute */
    dtv_player_p->setting.is_mute = 1 - dtv_player_p->setting.is_mute;

    if (dtv_player_p->setting.is_mute)
    {
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, (U8) MDI_AUD_VOL_EX_MUTE(DTV_PLAYER_VOL_MUTE));
    }
    else
    {
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, (U8) MDI_AUD_VOL_EX_MUTE(dtv_player_p->setting.vol_level));
    }

    active_screen = mmi_frm_scrn_get_active_id();
    if (active_screen != SCR_ID_DTV_PLAYER_APP)
    {
        return;
    }

    /* Draw OSD */
    if (draw_osd)
    {
        mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }


}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_vol_status_icon_release
 * DESCRIPTION
 *  mobile tv player vol_dec icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_vol_status_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_NONE;

    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        mmi_dtv_player_fullscr_reset_osd_fade(MMI_TRUE);
    }
    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_change_channel
 * DESCRIPTION
 *  mobile tv player channel channel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_change_channel(U8 target_channel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR str_buf[MMI_DTV_NAME_STR_LENGTH];
    CHAR str_buf2[MMI_DTV_NAME_STR_LENGTH];
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check if wwitch to differnt channel */
    if ((target_channel < dtv_player_p->num_services) 
		&&(target_channel != dtv_player_p->setting.selected_channel))
    { 
    #ifdef __MBBMS_INTER__	
		dtv_player_p->num_imd = 0;
	    dtv_player_p->num_unread_imd = 0;
        if ((MMI_FRM_SCREEN_ROTATE_0 == dtv_player_p->ui_rotate)
		    && (DTV_PLAYER_DYNAMIC_LABEL_OFF != dtv_player_p->dynamic_inter_state))
        {
            mmi_dtv_player_clear_description();		
	    }
	#endif
        if (PLAYER_STATE_IN(DTV_PLAYER_PLAY) || PLAYER_STATE_IN(DTV_PLAYER_BT_CONNECT)|| PLAYER_STATE_IN(DTV_PLAYER_PAUSE))
        {
            mmi_dtv_player_player_enter_state(DTV_PLAYER_STOPPED);
        }

        if (KERNEL_STATE_IN(DTV_KERNEL_READY) || KERNEL_STATE_IN(DTV_KERNEL_INIT))
        {
            mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);
        }
    #ifdef __MMI_DTV_UPDATE_SUBSCRIPTION_TABLE__
        if (KERNEL_STATE_IN(DTV_KERNEL_SUB_UPDATING))
        {
            ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);
            ASSERT(ret == MDI_RES_MTV_SUCCEED);
        }
    #endif

        /* Switch */
        mmi_dtv_player_set_selected_service(target_channel);

        mmi_dtv_player_clear_preview_layer();

        mmi_dtv_player_prepare_channel_name_hint(str_buf, str_buf2);

        mmi_dtv_player_set_hint(
            (CHAR *) str_buf,
            (CHAR *) str_buf2,
            MMI_DTV_PLAYER_HINT_POPUP_FADE_TIME,
            MMI_FALSE);

        /* Update icon state for refresh TV */
        mmi_dtv_player_config_functions_by_state();
        /* Blt out before entering init state: for refresh TV */
        mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
	#ifdef __MBBMS_INTER__
		#ifndef __MTK_TARGET__
		mmi_dtv_player_update_imd_count();
		#endif
	#endif
        ret = mmi_dtv_player_init_service_in_app_screen(MMI_FALSE);
        if (ret == MMI_FALSE)
        {
            return ret;
        }

        mmi_dtv_player_register_key_hdlr();
    }
    else
    {
        /* Only disply hint */
        mmi_dtv_player_prepare_channel_name_hint(str_buf, str_buf2);

        mmi_dtv_player_set_hint(
            (CHAR *) NULL, (CHAR *) str_buf2,
            MMI_DTV_PLAYER_HINT_POPUP_FADE_TIME,
            MMI_FALSE);
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_channel_prev_icon_press
 * DESCRIPTION
 *  mobile tv player channel prev icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_channel_prev_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 total_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dtv_player_reset_jump_to_channel();

    if (dtv_player_p->touch_object != DTV_PLAYER_TOUCH_CHANNEL_PREV)
    {
        dtv_player_p->temporal_channel = dtv_player_p->setting.selected_channel;
    }

    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_CHANNEL_PREV;

    total_num = dtv_player_p->num_services;

    if(dtv_player_p->temporal_channel == 0)
    {
        /* For wrap around to the last channel */
        dtv_player_p->temporal_channel = total_num - 1;
    }
    else
    {
        dtv_player_p->temporal_channel --;
    }

    if (dtv_player_p->is_key_pressed)
    {
        gui_start_timer(700, mmi_dtv_player_channel_prev_icon_press);
    }
    else
    {
        /* first time press up arrow, use longer time */
        gui_start_timer(1000, mmi_dtv_player_channel_prev_icon_press);
        dtv_player_p->is_key_pressed = MMI_TRUE;
    }

    dtv_player_p->active_osd_cntx_p->channel_prev.status = DTV_PLAYER_ICON_STATUS_CLICKED;
    mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_channel_prev_icon_release
 * DESCRIPTION
 *  mobile tv player prev icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_channel_prev_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dtv_player_p->touch_object != DTV_PLAYER_TOUCH_CHANNEL_PREV)
    {
        return;
    }

    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_NONE;
    dtv_player_p->is_key_pressed = MMI_FALSE;
    gui_cancel_timer(mmi_dtv_player_channel_prev_icon_press);
    dtv_player_p->active_osd_cntx_p->channel_prev.status  = DTV_PLAYER_ICON_STATUS_ENABLE;

    ret = mmi_dtv_player_change_channel(dtv_player_p->temporal_channel);
    if (ret == MMI_FALSE)
    {
        return;
    }

    mmi_dtv_player_draw_osd_and_blt();

    ClearKeyEvents();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_channel_next_icon_press
 * DESCRIPTION
 *  mobile tv player channel next icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_channel_next_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 total_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_dtv_player_reset_jump_to_channel();
    if (dtv_player_p->touch_object != DTV_PLAYER_TOUCH_CHANNEL_NEXT)
    {
        dtv_player_p->temporal_channel = dtv_player_p->setting.selected_channel;
    }
    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_CHANNEL_NEXT;
    total_num = dtv_player_p->num_services;
    if (dtv_player_p->temporal_channel == total_num - 1)
    {
        dtv_player_p->temporal_channel = 0;
    }
    else
    {
        dtv_player_p->temporal_channel++;
    }

    if (dtv_player_p->is_key_pressed)
    {
        gui_start_timer(700, mmi_dtv_player_channel_next_icon_press);
    }
    else
    {
        /* first time press up arrow, use longer time */
        gui_start_timer(1000, mmi_dtv_player_channel_next_icon_press);
        dtv_player_p->is_key_pressed = MMI_TRUE;
    }
    dtv_player_p->active_osd_cntx_p->channel_next.status = DTV_PLAYER_ICON_STATUS_CLICKED;
    mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_channel_next_icon_release
 * DESCRIPTION
 *  mobile tv player channel icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_channel_next_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dtv_player_p->touch_object != DTV_PLAYER_TOUCH_CHANNEL_NEXT)
    {
        return;
    }

    dtv_player_p->is_key_pressed = MMI_FALSE;
    gui_cancel_timer(mmi_dtv_player_channel_next_icon_press);
    dtv_player_p->active_osd_cntx_p->channel_next.status  = DTV_PLAYER_ICON_STATUS_ENABLE;

    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_NONE;

    ret = mmi_dtv_player_change_channel(dtv_player_p->temporal_channel);
    if (ret == MMI_FALSE)
    {
        return;
    }

    mmi_dtv_player_draw_osd_and_blt();

    ClearKeyEvents();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_key_1_press
 * DESCRIPTION
 *  mobile tv player key 1 pressed handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_key_1_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->is_changing_channel_by_key = MMI_TRUE;

    dtv_player_p->change_to_channel = (dtv_player_p->change_to_channel*10 + 1) % 100;
    mmi_dtv_player_check_and_jump_to_channel();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_key_2_press
 * DESCRIPTION
 *  mobile tv player key 2 pressed handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_key_2_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->is_changing_channel_by_key = MMI_TRUE;

    dtv_player_p->change_to_channel = (dtv_player_p->change_to_channel*10 + 2) % 100;
    mmi_dtv_player_check_and_jump_to_channel();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_key_3_press
 * DESCRIPTION
 *  mobile tv player key 3 pressed handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_key_3_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->is_changing_channel_by_key = MMI_TRUE;

    dtv_player_p->change_to_channel = (dtv_player_p->change_to_channel*10 + 3) % 100;
    mmi_dtv_player_check_and_jump_to_channel();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_key_4_press
 * DESCRIPTION
 *  mobile tv player key 4 pressed handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_key_4_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->is_changing_channel_by_key = MMI_TRUE;

    dtv_player_p->change_to_channel = (dtv_player_p->change_to_channel*10 + 4) % 100;
    mmi_dtv_player_check_and_jump_to_channel();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_key_5_press
 * DESCRIPTION
 *  mobile tv player key 5 pressed handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_key_5_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->is_changing_channel_by_key = MMI_TRUE;

    dtv_player_p->change_to_channel = (dtv_player_p->change_to_channel*10 + 5) % 100;
    mmi_dtv_player_check_and_jump_to_channel();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_key_6_press
 * DESCRIPTION
 *  mobile tv player key 6 pressed handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_key_6_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->is_changing_channel_by_key = MMI_TRUE;

    dtv_player_p->change_to_channel = (dtv_player_p->change_to_channel*10 + 6) % 100;
    mmi_dtv_player_check_and_jump_to_channel();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_key_7_press
 * DESCRIPTION
 *  mobile tv player key 7 pressed handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_key_7_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->is_changing_channel_by_key = MMI_TRUE;

    dtv_player_p->change_to_channel = (dtv_player_p->change_to_channel*10 + 7) % 100;
    mmi_dtv_player_check_and_jump_to_channel();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_key_8_press
 * DESCRIPTION
 *  mobile tv player key 8 pressed handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_key_8_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->is_changing_channel_by_key = MMI_TRUE;

    dtv_player_p->change_to_channel = (dtv_player_p->change_to_channel*10 + 8) % 100;
    mmi_dtv_player_check_and_jump_to_channel();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_key_9_press
 * DESCRIPTION
 *  mobile tv player key 9 pressed handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_key_9_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->is_changing_channel_by_key = MMI_TRUE;

    dtv_player_p->change_to_channel = (dtv_player_p->change_to_channel*10 + 9) % 100;

    mmi_dtv_player_check_and_jump_to_channel();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_key_0_press
 * DESCRIPTION
 *  mobile tv player key 0 pressed handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_key_0_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->is_changing_channel_by_key = MMI_TRUE;

    dtv_player_p->change_to_channel = (dtv_player_p->change_to_channel*10) % 100;

    mmi_dtv_player_check_and_jump_to_channel();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_check_and_jump_to_channel
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_check_and_jump_to_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dtv_player_p->change_to_channel < 10)
    {
        gui_cancel_timer(mmi_dtv_player_jump_to_channel);
        gui_start_timer(MMI_DTV_JUMP_TO_CHANNEL_DELAY, mmi_dtv_player_jump_to_channel);

        mmi_dtv_player_draw_osd_and_blt();
    }
    else
    {
        mmi_dtv_player_draw_osd();
        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
        mmi_dtv_player_jump_to_channel();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_reset_jump_to_channel
 * DESCRIPTION
 *  mobile tv player reset jump to channel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_reset_jump_to_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Reset jump to channel */
    dtv_player_p->is_changing_channel_by_key = MMI_FALSE;
    dtv_player_p->change_to_channel = 0;
    gui_cancel_timer(mmi_dtv_player_jump_to_channel);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_jump_to_channel
 * DESCRIPTION
 *  mobile tv player : jump to channel input by keypad.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_jump_to_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 service_index;
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->is_changing_channel_by_key = MMI_FALSE;

    for (service_index = 0; service_index < dtv_player_p->num_services; service_index ++)
    {
        if (dtv_player_p->services[service_index].service_number == dtv_player_p->change_to_channel)
        {
            break;
        }
    }

    ret = mmi_dtv_player_change_channel(service_index);
    if (ret == MMI_FALSE)
    {
        return;
    }

    mmi_dtv_player_draw_osd_and_blt();

    /* reset "change_to_channel" variable */
    dtv_player_p->change_to_channel = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_init_icon_info
 * DESCRIPTION
 *  mobile tv player init all icons info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_init_icon_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FTE_SUPPORT__
    CHAR * str_ptr = NULL;
    S32 truncated_width = 0;	
    MMI_BOOL is_truncated = MMI_TRUE;
#endif
    S32 width = 0;
    S32 height = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #define INIT_OSD_TOUCH_ICON(a,A)\
    do {\
        gdi_image_get_dimension_id(\
            (U16)(IMG_ID_DTV_PLAYER_##A##_UP),\
            &(dtv_player_p->active_osd_cntx_p->##a##.width),\
            &(dtv_player_p->active_osd_cntx_p->##a##.height)) ;\
    }while(0)


#if defined(__MMI_DTV_RECORD_SUPPORT__)
    INIT_OSD_TOUCH_ICON(record, RECORD);
#elif defined(__MMI_DTV_SNAPSHOT_SUPPORT__)
    INIT_OSD_TOUCH_ICON(record, SNAPSHOT);
#endif

    INIT_OSD_TOUCH_ICON(cycle,CYCLE);
    INIT_OSD_TOUCH_ICON(play,PLAY);

    INIT_OSD_TOUCH_ICON(fullscreen,FULLSCREEN);
#if defined(__MMI_DTV_LANDSCAPE_SUPPORT__)
    INIT_OSD_TOUCH_ICON(vol_inc,VOL_INC);
    INIT_OSD_TOUCH_ICON(vol_dec,VOL_DEC);
#endif

    INIT_OSD_TOUCH_ICON(channel_next,CHANNEL_NEXT);
    INIT_OSD_TOUCH_ICON(channel_prev,CHANNEL_PREV);

    /* Vol status */
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        gdi_image_get_dimension_id(
            (U16)(IMG_ID_DTV_PLAYER_VOL_STATUS_ON),
            &(dtv_player_p->active_osd_cntx_p->vol_status.width),
            &(dtv_player_p->active_osd_cntx_p->vol_status.height));
    }
    else
    {
        gdi_image_get_dimension_id(
            (U16)(IMG_ID_DTV_PLAYER_VOL_STATUS_ON_H),
            &(dtv_player_p->active_osd_cntx_p->vol_status.width),
            &(dtv_player_p->active_osd_cntx_p->vol_status.height)) ;
    }

#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
    INIT_OSD_TOUCH_ICON(change,CHANGE);
    INIT_OSD_TOUCH_ICON(forward,FORWARD);
    INIT_OSD_TOUCH_ICON(rewind,REWIND);

    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        gdi_image_get_dimension_id(
            (U16)(IMG_ID_DTV_PROGRESS_BAR),
            &(dtv_player_p->active_osd_cntx_p->ts_bar.width),
            &(dtv_player_p->active_osd_cntx_p->ts_bar.height));
    }
    else
    {
        gdi_image_get_dimension_id(
            (U16)(IMG_ID_DTV_PROGRESS_BAR_H),
            &(dtv_player_p->active_osd_cntx_p->ts_bar.width),
            &(dtv_player_p->active_osd_cntx_p->ts_bar.height)) ;
    }

    gdi_image_get_dimension_id(
        (U16)(IMG_ID_DTV_PROGRESS_IND),
        &(dtv_player_p->active_osd_cntx_p->ts_ind.width),
        &(dtv_player_p->active_osd_cntx_p->ts_ind.height)) ;
#endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */


    gdi_image_get_dimension_id(
        (U16)(IMG_ID_DTV_PLAYER_VOL_LEVEL),
        &(dtv_player_p->active_osd_cntx_p->volume.width),
        &(dtv_player_p->active_osd_cntx_p->volume.height));

#ifdef __MMI_FTE_SUPPORT__
    INIT_OSD_TOUCH_ICON(lsk,OPTION);
    INIT_OSD_TOUCH_ICON(rsk,BACK);

#else /* __MMI_FTE_SUPPORT__ */

#ifdef __MMI_DTV_LANDSCAPE_SUPPORT__
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        gdi_image_get_dimension_id(
            (U16)(IMG_ID_DTV_PLAYER_BACK_UP_H),
            &(dtv_player_p->active_osd_cntx_p->rsk.width),
            &(dtv_player_p->active_osd_cntx_p->rsk.height));

        return;
    }
#endif /*__MMI_DTV_LANDSCAPE_SUPPORT__ */
    /* Soft key */
    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_BUTTON));

    /* LSK */
    str_ptr = (CHAR *) GetString(STR_GLOBAL_OPTIONS);

    gui_measure_string(
        (UI_string_type) str_ptr,
        &(dtv_player_p->active_osd_cntx_p->lsk.width),
        &(dtv_player_p->active_osd_cntx_p->lsk.height));

    is_truncated = wgui_softkey_get_offset(
                       (UI_string_type)str_ptr,
                       &dtv_player_p->active_osd_cntx_p->lsk.offset_x,
                       &dtv_player_p->active_osd_cntx_p->lsk.offset_y,
                       &truncated_width,
                       MMI_LEFT_SOFTKEY,
                       dtv_player_p->ui_rotate);

    /* Restore the value wgui changes */
    if (r2lMMIFlag)
    {
        dtv_player_p->active_osd_cntx_p->lsk.offset_x -= dtv_player_p->active_osd_cntx_p->lsk.width;
    }

    /* RSK */
    str_ptr = (CHAR *) GetString(STR_GLOBAL_BACK);

    gui_measure_string(
        (UI_string_type) str_ptr,
        &(dtv_player_p->active_osd_cntx_p->rsk.width),
        &(dtv_player_p->active_osd_cntx_p->rsk.height));

    is_truncated = wgui_softkey_get_offset(
                       (UI_string_type)str_ptr,
                       &dtv_player_p->active_osd_cntx_p->rsk.offset_x,
                       &dtv_player_p->active_osd_cntx_p->rsk.offset_y,
                       &truncated_width,
                       MMI_RIGHT_SOFTKEY,
                       dtv_player_p->ui_rotate);

    /* Restore the value wgui changes */
    if (r2lMMIFlag)
    {
        dtv_player_p->active_osd_cntx_p->rsk.offset_x -= dtv_player_p->active_osd_cntx_p->rsk.width;
    }
#endif /* __MMI_FTE_SUPPORT__ */

    /* DLS fullscreen width */
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
    	gdi_image_get_dimension_id((U16)(IMG_ID_DTV_PLAYER_SIGNAL_LEVEL_0), &width, &height);
    	dtv_player_p->active_osd_cntx_p->title.offset_x = width + DTV_FULL_DLS_ICON_SPACE;


		gdi_image_get_dimension_id((U16)(IMG_ID_DTV_PLAYER_EB_WARNING), &width, &height);

		dtv_player_p->active_osd_cntx_p->title.offset_x += (width + DTV_FULL_DLS_ICON_SPACE);

        dtv_player_p->active_osd_cntx_p->title.width =
                dtv_player_p->active_osd_cntx_p->rsk.offset_x -
                DTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_X -
                dtv_player_p->active_osd_cntx_p->title.offset_x - 2;
    }
    else
    {
		gdi_image_get_dimension_id((U16)(IMG_ID_DTV_PLAYER_EB_WARNING), &width, &height);

		dtv_player_p->active_osd_cntx_p->title.offset_x = (width + DTV_FULL_DLS_ICON_SPACE);

        dtv_player_p->active_osd_cntx_p->title.offset_y = 
            dtv_player_p->active_osd_cntx_p->subject.offset_y +
            dtv_player_p->active_osd_cntx_p->subject.height;
        
        dtv_player_p->active_osd_cntx_p->title.width =
                LCD_WIDTH - dtv_player_p->active_osd_cntx_p->title.offset_x - 2;
    }

    /* Subject */
#ifdef __MBBMS_INTER__  
    if (dtv_player_p->ca_state != MMI_DTV_CA_STATE_CMMB)
    {
        /* Reserve the space for interactivity icon and unread number */
        g_dtv_player_osd_cntx.subject.width = LCD_WIDTH * 3 / 4;
    }

    /* Wiew icon */
    gdi_image_get_dimension_id(
            IMG_ID_DTV_PLAYER_VIEW_UP, &width, &height);
    /* View: 3(space)+width+3(space)*/
    dtv_player_p->active_osd_cntx_p->view.offset_x = DTV_PLAYER_INTER_LAYER_ONE_LINE_WIDTH + 3;
    dtv_player_p->active_osd_cntx_p->view.width = DTV_PLAYER_INTER_LAYER_ONE_LINE_VIEW_WIDTH;
    dtv_player_p->active_osd_cntx_p->view.height = height;    
    dtv_player_p->active_osd_cntx_p->view.offset_y = 
        DTV_PLAYER_INTER_LAYER_ONE_LINE_OFFSET_Y + ((DTV_PLAYER_INTER_LAYER_ONE_LINE_HEIGHT - height)>>1);
    
    
#endif
}


#if defined(__MMI_TOUCH_SCREEN__)
#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__

 void mmi_dtv_player_switch_ts_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->is_ts_bar_enable = ~dtv_player_p->is_ts_bar_enable;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_ts_bar_icon_press
 * DESCRIPTION
 *  mobile tv player channel_prev icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_ts_bar_icon_press(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 buf_width;
    S32 time_offset, offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_TS_BAR;
    gui_start_timer(300, mmi_dtv_player_switch_ts_bar);

    if (dtv_player_p->is_ts_bar_enable && dtv_player_p->max_timeshift_delay != 0)
    {
        mmi_dtv_player_get_player_status(dtv_player_p->mtv_handle, NULL, &dtv_player_p->play_delay, &dtv_player_p->max_delay, &dtv_player_p->max_timeshift_delay, NULL);

        offset = x - dtv_player_p->active_osd_cntx_p->ts_bar.offset_x;
        if (offset < 0)
        {
            return;
        }
        buf_width = dtv_player_p->active_osd_cntx_p->ts_bar.width;
        time_offset = dtv_player_p->max_timeshift_delay * offset / buf_width;
        if (time_offset > dtv_player_p->max_delay)
        {
            return;
        }
        dtv_player_p->play_delay = dtv_player_p->max_delay - time_offset;
        if (dtv_player_p->play_delay < 1)
        {
            dtv_player_p->play_delay = 1;
        }
        dtv_player_p->last_error = mdi_mtv_player_seek(dtv_player_p->mtv_handle, dtv_player_p->play_delay);

        if (dtv_player_p->play_delay != 1)
        {
            /* Update play_delay */
            mmi_dtv_player_get_player_status(dtv_player_p->mtv_handle, NULL, &dtv_player_p->play_delay, &dtv_player_p->max_delay, &dtv_player_p->max_timeshift_delay, NULL);
        }
        /* Show error pop up after re-drawing OSD */
        if (dtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
        {
            mmi_dtv_player_display_failure_popup(dtv_player_p->last_error);
            return;
        }

        mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_ts_bar_icon_release
 * DESCRIPTION
 *  mobile tv player channel_prev icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_ts_bar_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_NONE;
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        mmi_dtv_player_fullscr_reset_osd_fade(MMI_TRUE);
    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

    gui_cancel_timer(mmi_dtv_player_switch_ts_bar);
    dtv_player_p->is_ts_bar_enable = MMI_TRUE;
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_touch_scr_hit_test
 * DESCRIPTION
 *  mobile tv player check if icon is pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 MMI_BOOL mmi_dtv_player_touch_scr_hit_test(S32 pos_x, S32 pos_y, dtv_player_osd_icon_struct *touch_obj)
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
 *  mmi_dtv_player_pen_down_hdlr_fullscreen
 * DESCRIPTION
 *  mobile tv player pen down event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_pen_down_hdlr_fullscreen(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dtv_player_fullscr_osd_show_up();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_touch_feeback_down
 * DESCRIPTION
 *  mobile tv player pen down down
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_touch_feeback_down(void)
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
 *  mmi_dtv_player_pen_down_hdlr
 * DESCRIPTION
 *  mobile tv player pen down event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL hit = MMI_FALSE;
#define ICON_TOUCH_TEST(a,A)\
    do {\
        if(dtv_player_p->active_osd_cntx_p->##a##.status==DTV_PLAYER_ICON_STATUS_ENABLE)\
        {\
            if(mmi_dtv_player_touch_scr_hit_test(pos.x, pos.y, &(dtv_player_p->active_osd_cntx_p->##a##)) == MMI_TRUE)\
            {\
                mmi_dtv_player_##a##_icon_press();\
                dtv_player_p->touch_object = DTV_PLAYER_TOUCH_##A;\
                mmi_dtv_player_touch_feeback_down();\
                return;\
            }\
        }\
    } while(0)
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MBBMS_V30_OPERA__
    hit = mmi_dtv_player_opera_engine_pen_event(pos,OP_WEBVIEW_PENEVENT_DOWN);
    #endif
    if (MMI_TRUE == hit)
    {
    	/* Opear IMD page receive event and process */
    	return;
    }
#if !defined(__MMI_DTV_LANDSCAPE_SUPPORT__)
    /* idp rotate */
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        S32 tmp;

        tmp = pos.x;
        pos.x = pos.y;
        pos.y = (LCD_WIDTH - 1) - tmp;
    }
#endif /* !__MMI_DTV_LANDSCAPE_SUPPORT__ */

    dtv_player_p->is_pen_down = MMI_TRUE;
    dtv_player_p->pen_down_x = pos.x;
    dtv_player_p->pen_down_y = pos.y;
    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_NONE;

    ICON_TOUCH_TEST(vol_status, VOL_STATUS);

    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        ICON_TOUCH_TEST(lsk,LSK);
        ICON_TOUCH_TEST(cycle, CYCLE);
        ICON_TOUCH_TEST(play,PLAY);
    }
    ICON_TOUCH_TEST(rsk,RSK);

    ICON_TOUCH_TEST(fullscreen,FULLSCREEN);
    ICON_TOUCH_TEST(vol_inc,VOL_INC);
    ICON_TOUCH_TEST(vol_dec,VOL_DEC);

    if (dtv_player_p->osd_mode == MMI_DTV_OSD_MODE_CHANNEL)
    {
        ICON_TOUCH_TEST(channel_next,CHANNEL_NEXT);
        ICON_TOUCH_TEST(channel_prev,CHANNEL_PREV);
    }

#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
    ICON_TOUCH_TEST(change, CHANGE);

    if (dtv_player_p->osd_mode == MMI_DTV_OSD_MODE_TIME_SHIFT)
    {
        ICON_TOUCH_TEST(forward,FORWARD);
        ICON_TOUCH_TEST(rewind,REWIND);
        /* bar */
        if(dtv_player_p->is_ready_to_ts == MMI_TRUE)
        {
            if(dtv_player_p->active_osd_cntx_p->ts_bar.status==DTV_PLAYER_ICON_STATUS_ENABLE)
            {
                if(mmi_dtv_player_touch_scr_hit_test(pos.x, pos.y, &(dtv_player_p->active_osd_cntx_p->ts_bar)) == MMI_TRUE)
                {
                    mmi_dtv_player_ts_bar_icon_press(pos.x, pos.y);
                    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_TS_BAR;
                    mmi_dtv_player_touch_feeback_down();
                    return;
                }
            }
        }
    }
#endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */

#if defined(__MMI_DTV_SNAPSHOT_SUPPORT__) || defined(__MMI_DTV_RECORD_SUPPORT__)

    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        ICON_TOUCH_TEST(record,RECORD);
    }
#endif

#ifdef __MBBMS_INTER__
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        ICON_TOUCH_TEST(view, VIEW);
    }
#endif

    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        if (pos.y <= MMI_DTV_PLAYER_FULL_SCR_BG_OFFSET_Y)
        {
            hit = MMI_TRUE;
        }
    }
    else
    {
        if (pos.y >= DTV_PLAYER_DISPLAY_LAYER_OFFSET_Y &&
            pos.y <= DTV_PLAYER_DISPLAY_LAYER_OFFSET_Y + DTV_PLAYER_DISPLAY_LAYER_HEIGHT &&
            pos.x >= DTV_PLAYER_DISPLAY_LAYER_OFFSET_X &&
            pos.x <= DTV_PLAYER_DISPLAY_LAYER_OFFSET_X + DTV_PLAYER_DISPLAY_LAYER_WIDTH)
        {
            hit = MMI_TRUE;
        }
    }

    if (hit)
    {
        mmi_dtv_player_reinit_switch_screen();
    }
    else
    {
        /* Invalid region: make the play panel appear */
        mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_pen_up_hdlr
 * DESCRIPTION
 *  mobile tv player pen up event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL hit = MMI_FALSE;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MBBMS_V30_OPERA__
    hit = mmi_dtv_player_opera_engine_pen_event(pos,OP_WEBVIEW_PENEVENT_UP);
    #endif
    if (MMI_TRUE == hit)
    {
    	/* Opear IMD page receive event and process */
    	return;
    }
#if !defined(__MMI_DTV_LANDSCAPE_SUPPORT__)
    /* idp rotate */
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        S32 tmp;

        tmp = pos.x;
        pos.x = pos.y;
        pos.y = (LCD_WIDTH - 1) - tmp;
    }
#endif /*!defined(__MMI_DTV_LANDSCAPE_SUPPORT__) */
    dtv_player_p->is_pen_down = MMI_FALSE;

    switch(dtv_player_p->touch_object)
    {
        case DTV_PLAYER_TOUCH_RSK:
            mmi_dtv_player_rsk_icon_release();
            break;
        case DTV_PLAYER_TOUCH_LSK:
            mmi_dtv_player_lsk_icon_release();
            break;
        case DTV_PLAYER_TOUCH_FULLSCREEN:
            mmi_dtv_player_fullscreen_icon_release();
            break;
        case DTV_PLAYER_TOUCH_VOL_INC:
            mmi_dtv_player_vol_inc_icon_release();
            break;
        case DTV_PLAYER_TOUCH_VOL_DEC:
            mmi_dtv_player_vol_dec_icon_release();
            break;
        case DTV_PLAYER_TOUCH_CHANNEL_NEXT:
            mmi_dtv_player_channel_next_icon_release();
            break;
        case DTV_PLAYER_TOUCH_CHANNEL_PREV:
            mmi_dtv_player_channel_prev_icon_release();
            break;
        case DTV_PLAYER_TOUCH_CYCLE:
            mmi_dtv_player_cycle_icon_release();
            break;
        case DTV_PLAYER_TOUCH_PLAY:
            mmi_dtv_player_play_icon_release();
            break;
        case DTV_PLAYER_TOUCH_VOL_STATUS:
            mmi_dtv_player_vol_status_icon_release();
            break;
    #ifdef __MBBMS_INTER__
        case DTV_PLAYER_TOUCH_VIEW:
            mmi_dtv_player_view_icon_release();
            break;
    #endif /* __MBBMS_INTER__ */
    #ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
        case DTV_PLAYER_TOUCH_CHANGE:
            mmi_dtv_player_change_icon_release();
            break;
        case DTV_PLAYER_TOUCH_FORWARD:
            mmi_dtv_player_forward_icon_release();
            break;
        case DTV_PLAYER_TOUCH_REWIND:
            mmi_dtv_player_rewind_icon_release();
            break;
        case DTV_PLAYER_TOUCH_TS_BAR:
            mmi_dtv_player_ts_bar_icon_release();
    #endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */
    #if defined(__MMI_DTV_SNAPSHOT_SUPPORT__) || defined(__MMI_DTV_RECORD_SUPPORT__)
        case DTV_PLAYER_TOUCH_RECORD:
            mmi_dtv_player_record_icon_release();
            break;
    #endif /* defined(__MMI_DTV_SNAPSHOT_SUPPORT__) || defined(__MMI_DTV_RECORD_SUPPORT__) */
        default:
        {

            /* If not yet fade out, make it fade out.
               When moving to invalid region, play panel has faded out. */
            if (dtv_player_p->fullscr_osd_opacity == MMI_DTV_PLAYER_OSD_FADEOUT_FACTOR)
            {
                mmi_dtv_player_draw_osd_and_blt();
            }

            break;
        }

    }

    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_pen_move_hdlr
 * DESCRIPTION
 *  mobile tv player pen move event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dtv_player_osd_icon_struct *osd_icon_ptr = NULL;
    S32 tmp;
	MMI_BOOL hit = MMI_FALSE;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MBBMS_V30_OPERA__
    hit = mmi_dtv_player_opera_engine_pen_event(pos,OP_WEBVIEW_PENEVENT_MOVE);
    #endif 
    if (MMI_TRUE == hit)
    {
    	/* Opear IMD page receive event and process */
    	return;
    }
#if !defined(__MMI_DTV_LANDSCAPE_SUPPORT__)
    /* idp rotate */
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        tmp = pos.x;
        pos.x = pos.y;
        pos.y = (LCD_WIDTH - 1) - tmp;
    }
#endif /* !defined(__MMI_DTV_LANDSCAPE_SUPPORT__) */

    /* Assign osd icon pointer */
    switch(dtv_player_p->touch_object)
    {
        case DTV_PLAYER_TOUCH_RSK:
            osd_icon_ptr = &(dtv_player_p->active_osd_cntx_p->rsk);
            break;
        case DTV_PLAYER_TOUCH_LSK:
            osd_icon_ptr = &(dtv_player_p->active_osd_cntx_p->lsk);
            break;
        case DTV_PLAYER_TOUCH_FULLSCREEN:
            osd_icon_ptr = &(dtv_player_p->active_osd_cntx_p->fullscreen);
            break;
        case DTV_PLAYER_TOUCH_VOL_INC:
            osd_icon_ptr = &(dtv_player_p->active_osd_cntx_p->vol_inc);
            break;
        case DTV_PLAYER_TOUCH_VOL_DEC:
            osd_icon_ptr = &(dtv_player_p->active_osd_cntx_p->vol_dec);
            break;
        case DTV_PLAYER_TOUCH_CHANNEL_NEXT:
            osd_icon_ptr = &(dtv_player_p->active_osd_cntx_p->channel_next);
            break;
        case DTV_PLAYER_TOUCH_CHANNEL_PREV:
            osd_icon_ptr = &(dtv_player_p->active_osd_cntx_p->channel_prev);
            break;
        case DTV_PLAYER_TOUCH_CYCLE:
            osd_icon_ptr = &(dtv_player_p->active_osd_cntx_p->cycle);
            break;
        case DTV_PLAYER_TOUCH_PLAY:
            osd_icon_ptr = &(dtv_player_p->active_osd_cntx_p->play);
            break;
    #ifdef __MBBMS_INTER__
        case DTV_PLAYER_TOUCH_VIEW:
            osd_icon_ptr = &(dtv_player_p->active_osd_cntx_p->view);
            break;
    #endif /* __MBBMS_INTER__ */        
    #ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
        case DTV_PLAYER_TOUCH_CHANGE:
            osd_icon_ptr = &(dtv_player_p->active_osd_cntx_p->change);
            break;
        case DTV_PLAYER_TOUCH_FORWARD:
            osd_icon_ptr = &(dtv_player_p->active_osd_cntx_p->forward);
            break;
        case DTV_PLAYER_TOUCH_REWIND:
            osd_icon_ptr = &(dtv_player_p->active_osd_cntx_p->rewind);
            break;
        case DTV_PLAYER_TOUCH_TS_BAR:
            osd_icon_ptr = &(dtv_player_p->active_osd_cntx_p->ts_bar);
    #endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */
    #if defined(__MMI_DTV_SNAPSHOT_SUPPORT__) || defined(__MMI_DTV_RECORD_SUPPORT__)
        case DTV_PLAYER_TOUCH_RECORD:
            osd_icon_ptr = &(dtv_player_p->active_osd_cntx_p->record);
            break;
    #endif /* defined(__MMI_DTV_SNAPSHOT_SUPPORT__) || defined(__MMI_DTV_RECORD_SUPPORT__) */


        default:
            break;
    }

    /* Handle the case when move out of the icon */
    switch(dtv_player_p->touch_object)
    {
    case DTV_PLAYER_TOUCH_VOL_INC:
    {
        if(mmi_dtv_player_touch_scr_hit_test(pos.x, pos.y, osd_icon_ptr) != MMI_TRUE)
        {
            mmi_dtv_player_vol_inc_icon_release();
        }
        break;
    }
    case DTV_PLAYER_TOUCH_VOL_DEC:
    {
        if(mmi_dtv_player_touch_scr_hit_test(pos.x, pos.y, osd_icon_ptr) != MMI_TRUE)
        {
            mmi_dtv_player_vol_dec_icon_release();
        }
        break;
    }
    case DTV_PLAYER_TOUCH_CHANNEL_NEXT:
    {
        if(mmi_dtv_player_touch_scr_hit_test(pos.x, pos.y, osd_icon_ptr) != MMI_TRUE)
        {
            mmi_dtv_player_channel_next_icon_release();
        }
        break;
    }
    case DTV_PLAYER_TOUCH_CHANNEL_PREV:
    {
        if(mmi_dtv_player_touch_scr_hit_test(pos.x, pos.y, osd_icon_ptr) != MMI_TRUE)
        {
            mmi_dtv_player_channel_prev_icon_release();
        }
        break;
    }
    case DTV_PLAYER_TOUCH_CYCLE:
    {
        if(mmi_dtv_player_touch_scr_hit_test(pos.x, pos.y, osd_icon_ptr) != MMI_TRUE)
        {
            mmi_dtv_player_cycle_icon_release();
        }
        break;
    }
    case DTV_PLAYER_TOUCH_PLAY:
    {
        if(mmi_dtv_player_touch_scr_hit_test(pos.x, pos.y, osd_icon_ptr) != MMI_TRUE)
        {
            mmi_dtv_player_play_icon_release();
        }
        break;
    }
#ifdef __MBBMS_INTER__
    case DTV_PLAYER_TOUCH_VIEW:
        if(mmi_dtv_player_touch_scr_hit_test(pos.x, pos.y, osd_icon_ptr) != MMI_TRUE)
        {
            mmi_dtv_player_view_icon_release();
        }
        break;
#endif /* __MBBMS_INTER__ */   

#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
    case DTV_PLAYER_TOUCH_TS_BAR:
    {
        if(mmi_dtv_player_touch_scr_hit_test(pos.x, pos.y, osd_icon_ptr) != MMI_TRUE)
        {
            mmi_dtv_player_ts_bar_icon_release();
        }
        else
        {
            mmi_dtv_player_ts_bar_icon_press(pos.x,pos.y);
        }
        break;
    }
    /* Only need to change icon status as enable */
    /* Need to stop timer */
    case DTV_PLAYER_TOUCH_FORWARD:
    case DTV_PLAYER_TOUCH_REWIND:
#endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */
#if defined(__MMI_DTV_SNAPSHOT_SUPPORT__) || defined(__MMI_DTV_RECORD_SUPPORT__)
    case DTV_PLAYER_TOUCH_RECORD:
#endif
    /* Only need to change icon status as enable */
    case DTV_PLAYER_TOUCH_FULLSCREEN:
    case DTV_PLAYER_TOUCH_CHANGE:
    case DTV_PLAYER_TOUCH_RSK:
    case DTV_PLAYER_TOUCH_LSK:
    {
        if(mmi_dtv_player_touch_scr_hit_test(pos.x, pos.y, osd_icon_ptr) != MMI_TRUE)
        {
        #if defined(__MMI_DTV_RECORD_SUPPORT__)
            /* stop timer */
            if (dtv_player_p->touch_object == DTV_PLAYER_TOUCH_RECORD)
            {
                gui_cancel_timer(mmi_dtv_player_record_start_record);
            }
        #endif /* __MMI_DTV_RECORD_SUPPORT__ */
        #ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
            if (dtv_player_p->touch_object == DTV_PLAYER_TOUCH_FORWARD)
            {
                gui_cancel_timer(mmi_dtv_player_forward_icon_press);
            }
            else if (dtv_player_p->touch_object == DTV_PLAYER_TOUCH_REWIND)
            {
                gui_cancel_timer(mmi_dtv_player_rewind_icon_press);
            }
        #endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */
            /* Change icon status as enable */
            osd_icon_ptr->status = DTV_PLAYER_ICON_STATUS_ENABLE;
            dtv_player_p->touch_object = DTV_PLAYER_TOUCH_NONE;

            mmi_dtv_player_draw_osd_and_blt();
        }
        break;
    }
    default:
        break;
    }

}
#endif /* (__MMI_TOUCH_SCREEN__) */



/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_draw_style_text
 * DESCRIPTION
 *  draw style text
 * PARAMETERS
 *  str          [IN]        String to be draw
 *  offset_x     [IN]        x position
 *  offset_y     [IN]        y position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_draw_style_text(CHAR *str, S32 offset_x, S32 offset_y)
{
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
    gui_set_text_color(gui_color(255,255,255));
    gui_set_text_border_color(gui_color(0,0,0)); //67,87,153
    gui_print_bordered_text((UI_string_type) str);

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
 void mmi_dtv_player_draw_truncated_style_text(CHAR * str, S32 offset_x, S32 offset_y, S32 width)
{
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
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_draw_channel_name_text
 * DESCRIPTION
 *  mobile tv player draw channel name (truncated)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_draw_channel_name_text(
        WCHAR *str,
        dtv_player_osd_text_struct *osd,
        MMI_BOOL active,
        MMI_BOOL subject)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width, str_height;
    S32 offset_x;
    S32 offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (subject)
    {
	#ifdef __MMI_VECTOR_FONT_SUPPORT__
        gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_TITLE));
    #else /* __MMI_VECTOR_FONT_SUPPORT__ */
        gui_set_font(&MMI_medium_font);
    #endif /* __MMI_VECTOR_FONT_SUPPORT__ */
    }
    else
    {
    #ifdef __MMI_VECTOR_FONT_SUPPORT__
        gui_set_font(&MMI_small_font);
    #else /* __MMI_VECTOR_FONT_SUPPORT__ */
        gui_set_font(&MMI_medium_font);
    #endif /* __MMI_VECTOR_FONT_SUPPORT__ */
    }

    /* Center align */
    gui_measure_string((UI_string_type)str, &str_width, &str_height);

    offset_y = osd->offset_y + (osd->height - str_height + 1) / 2;
    if (osd->width - str_width > 0)
    {
        if (r2lMMIFlag)
        {
            offset_x = osd->width - (osd->width - str_width) / 2;
        }
        else
        {
            offset_x = osd->offset_x + (osd->width - str_width) / 2;
        }
    }
    else
    {
        if (r2lMMIFlag)
        {
            offset_x = osd->offset_x + osd->width;
        }
        else
        {
            offset_x = osd->offset_x;
        }
    }

    gui_move_text_cursor(offset_x, offset_y);

    if (!active || subject)
    {
        gui_set_text_color(gui_color(255,255, 255));
    }
    else
    {
        gui_set_text_color(gui_color(255,255, 0));
    }

    if (subject)
    {
        gui_print_truncated_text(
            offset_x, offset_y, osd->width, (UI_string_type) str);
    }
    else
    {
        gui_set_text_border_color(gui_color(0,0,0));
        gui_print_truncated_borderd_text(
            offset_x, offset_y, osd->width, (UI_string_type) str);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_draw_style_multiline_text
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_draw_multiline_style_text(CHAR* str, S32 offset_x, S32 offset_y, S32 width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width = 0;
    S32 str_height = 0;
    S32 str_len = 0;
    S32 line_height;

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

#if defined(__MMI_DTV_SMALL_HINT__)
	 MMI_multiline_inputbox.text_font = &MMI_small_font;
#else
	 MMI_multiline_inputbox.text_font = &MMI_medium_font;
#endif

    show_multiline_inputbox_no_draw();
    line_height = get_multiline_inputbox_line_height();

    /* Set multiline region */
    move_multiline_inputbox(offset_x, offset_y);
    resize_multiline_inputbox(
        width,
        (MMI_multiline_inputbox.n_lines * line_height) + MULTILINE_INPUTBOX_HEIGHT_PAD + MMI_multiline_inputbox.text_y);

    show_multiline_inputbox();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_draw_osd_softkey
 * DESCRIPTION
 *  mobile tv player draw osd softkey handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_draw_osd_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FTE_SUPPORT__
    S32 lsk_offset_x = 0;
    S32 lsk_offset_y = 0;
    S32 rsk_offset_x = 0;
    S32 rsk_offset_y = 0;
    CHAR *str_ptr = NULL;
#endif
    S32 offset = 0;
    U16 rsk_up_id, rsk_down_id;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	if (DTV_CMMB_TEST_MODE_OFF != g_cmmb_test_mode)
	{
		dtv_player_p->active_osd_cntx_p->lsk.status = DTV_PLAYER_ICON_STATUS_DISABLE;
	}
#ifdef __MMI_FTE_SUPPORT__
    if (dtv_player_p->active_osd_cntx_p->lsk.status != DTV_PLAYER_ICON_STATUS_DISABLE)
    {
        /* lsk */
        if(dtv_player_p->active_osd_cntx_p->lsk.status == DTV_PLAYER_ICON_STATUS_ENABLE)
        {
            gdi_image_draw_id(
                dtv_player_p->active_osd_cntx_p->lsk.offset_x,
                dtv_player_p->active_osd_cntx_p->lsk.offset_y,
                (U16)(IMG_ID_DTV_PLAYER_OPTION_UP));
        }
        else if(dtv_player_p->active_osd_cntx_p->lsk.status == DTV_PLAYER_ICON_STATUS_CLICKED)
        {
            gdi_image_draw_id(
                dtv_player_p->active_osd_cntx_p->lsk.offset_x,
                dtv_player_p->active_osd_cntx_p->lsk.offset_y,
                (U16)(IMG_ID_DTV_PLAYER_OPTION_DOWN));
        }
        offset = 0;
    }
    else if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        offset = 2;
    }

#ifdef __MMI_DTV_RECORD_SUPPORT__
    if (RECORDER_STATE_IN(DTV_RECORDER_RECORD))
    {
        rsk_up_id = IMG_ID_DTV_PLAYER_STOP_UP;
        rsk_down_id = IMG_ID_DTV_PLAYER_STOP_DOWN;
    }
    else
#endif /* __MMI_DTV_RECORD_SUPPORT__ */
#ifdef __MBBMS_INTER__
    if (dtv_player_p->int_state == DTV_PLAYER_INT_STATE_HALF_SCREEN)
    {
        rsk_up_id = IMG_ID_DTV_PLAYER_CLOSE_UP;
        rsk_down_id = IMG_ID_DTV_PLAYER_CLOSE_DOWN;
    }
    else
#endif /* __MBBMS_INTER__ */        
    {
        rsk_up_id = IMG_ID_DTV_PLAYER_BACK_UP;
        rsk_down_id = IMG_ID_DTV_PLAYER_BACK_DOWN;
    }
    /* rsk */
    if(dtv_player_p->active_osd_cntx_p->rsk.status == DTV_PLAYER_ICON_STATUS_ENABLE)
    {
        gdi_image_draw_id(
            dtv_player_p->active_osd_cntx_p->rsk.offset_x,
            dtv_player_p->active_osd_cntx_p->rsk.offset_y,
            (U16)(rsk_up_id + offset));
    }
    else if(dtv_player_p->active_osd_cntx_p->rsk.status == DTV_PLAYER_ICON_STATUS_CLICKED)
    {
        gdi_image_draw_id(
            dtv_player_p->active_osd_cntx_p->rsk.offset_x,
            dtv_player_p->active_osd_cntx_p->rsk.offset_y,
            (U16)(rsk_down_id + offset));
    }
#else /* __MMI_FTE_SUPPORT__ */

#ifdef __MMI_DTV_LANDSCAPE_SUPPORT__
    /* Only RSK icon */
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        if (RECORDER_STATE_IN(DTV_RECORDER_RECORD))
        {
            rsk_up_id = IMG_ID_DTV_PLAYER_STOP_UP_H;
            rsk_down_id = IMG_ID_DTV_PLAYER_STOP_DOWN_H;
        }
        else
        {
            rsk_up_id = IMG_ID_DTV_PLAYER_BACK_UP_H;
            rsk_down_id = IMG_ID_DTV_PLAYER_BACK_DOWN_H;
        }

        /* rsk */
        if(dtv_player_p->active_osd_cntx_p->rsk.status == DTV_PLAYER_ICON_STATUS_ENABLE)
        {
            gdi_image_draw_id(
                dtv_player_p->active_osd_cntx_p->rsk.offset_x,
                dtv_player_p->active_osd_cntx_p->rsk.offset_y,
                (U16)(rsk_up_id));
        }
        else if(dtv_player_p->active_osd_cntx_p->rsk.status == DTV_PLAYER_ICON_STATUS_CLICKED)
        {
            gdi_image_draw_id(
                dtv_player_p->active_osd_cntx_p->rsk.offset_x,
                dtv_player_p->active_osd_cntx_p->rsk.offset_y,
                (U16)(rsk_down_id));
        }
        return; /* Don't remove it */
    }
#endif /*__MMI_DTV_LANDSCAPE_SUPPORT__ */

    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    /* if is fullscreen display, or normal display but without mmi_softkey */
    gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_BUTTON));

    /* Full screen does not have LSK */
    if (dtv_player_p->active_osd_cntx_p->lsk.status != DTV_PLAYER_ICON_STATUS_DISABLE)
    {
        lsk_offset_x = dtv_player_p->active_osd_cntx_p->lsk.offset_x;
        lsk_offset_y = dtv_player_p->active_osd_cntx_p->lsk.offset_y;

        if (dtv_player_p->active_osd_cntx_p->lsk.status == DTV_PLAYER_ICON_STATUS_CLICKED)
        {
            lsk_offset_x++;
            lsk_offset_y++;
        }
        str_ptr = (CHAR *) GetString(STR_GLOBAL_OPTIONS);
        mmi_dtv_player_draw_style_text(str_ptr, lsk_offset_x, lsk_offset_y);
    }


    /* rsk */
    rsk_offset_x = dtv_player_p->active_osd_cntx_p->rsk.offset_x;
    rsk_offset_y = dtv_player_p->active_osd_cntx_p->rsk.offset_y;

    if (dtv_player_p->active_osd_cntx_p->rsk.status == DTV_PLAYER_ICON_STATUS_CLICKED)
    {
        rsk_offset_x ++;
        rsk_offset_y ++;
    }

    /* disable font alpha */
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        mmi_fe_set_antialias(MMI_FALSE);
    }
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */

    if (RECORDER_STATE_IN(DTV_RECORDER_RECORD))
    {
        str_ptr = (CHAR *) GetString(STR_GLOBAL_STOP);
    }
#ifdef __MBBMS_INTER__
    else if (dtv_player_p->int_state == DTV_PLAYER_INT_STATE_HALF_SCREEN)
    {
        str_ptr = (CHAR *) GetString(STR_GLOBAL_CLOSE);
    }
#endif /* __MBBMS_INTER__ */  
    else
    {
        str_ptr = (CHAR *) GetString(STR_GLOBAL_BACK);
    }

    mmi_dtv_player_draw_style_text(str_ptr, rsk_offset_x, rsk_offset_y);

    /* enable font alpha */
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        mmi_fe_set_antialias(MMI_TRUE);
    }
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */
#endif /* __MMI_FTE_SUPPORT__ */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_fullscr_osd_show_up
 * DESCRIPTION
 *  fade fullscr osd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_fullscr_osd_show_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dtv_player_register_key_hdlr();
    mmi_dtv_player_fullscr_reset_osd_fade(MMI_TRUE);
    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    ClearKeyEvents();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_reset_key_handler
 * DESCRIPTION
 *  fade fullscr osd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_reset_key_handler(void(*func_ptr)(void))
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
    SetKeyHandler(func_ptr, KEY_CLEAR, KEY_EVENT_DOWN);
    SetKeyHandler(func_ptr, KEY_CAMERA, KEY_EVENT_DOWN);
    /* Otherwise, arrow key is mapped as volume key */
#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
    SetKeyHandler(func_ptr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(func_ptr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_fullscr_osd_fade_cyclic
 * DESCRIPTION
 *  fade fullscr osd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_fullscr_osd_fade_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 left_rewind, right_forward, up_next_channel, down_prev_channel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_DTV_LANDSCAPE_SUPPORT__)
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
    if (dtv_player_p->fullscr_osd_opacity > MMI_DTV_PLAYER_OSD_FADE_OUT_VALUE)
    {
        dtv_player_p->fullscr_osd_opacity -= MMI_DTV_PLAYER_OSD_FADE_OUT_VALUE;

        gui_start_timer(100, mmi_dtv_player_fullscr_osd_fade_cyclic);
    }
    else
    {
        dtv_player_p->fullscr_osd_opacity = 0;

        /* if totally fade out, use any key to wake up */
        ClearInputEventHandler(MMI_DEVICE_ALL);

        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, KEY_1, KEY_EVENT_UP);
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, KEY_2, KEY_EVENT_UP);
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, KEY_3, KEY_EVENT_UP);
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, KEY_4, KEY_EVENT_UP);
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, KEY_5, KEY_EVENT_UP);
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, KEY_6, KEY_EVENT_UP);
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, KEY_7, KEY_EVENT_UP);
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, KEY_8, KEY_EVENT_UP);
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, KEY_9, KEY_EVENT_UP);
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, KEY_0, KEY_EVENT_UP);
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, KEY_STAR, KEY_EVENT_UP);
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, KEY_LSK, KEY_EVENT_UP);
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, KEY_RSK, KEY_EVENT_UP);
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, KEY_CSK, KEY_EVENT_UP);
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, up_next_channel, KEY_EVENT_UP);
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, down_prev_channel, KEY_EVENT_UP);
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, KEY_CLEAR, KEY_EVENT_UP);
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, KEY_CAMERA, KEY_EVENT_UP);
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, KEY_POUND, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, KEY_POUND, KEY_EVENT_UP);

    #if defined(__MDI_DTV_TIME_SHIFT_SUPPORT__)
        /* with timeshift || with volume icon */
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, left_rewind, KEY_EVENT_UP);
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, right_forward, KEY_EVENT_UP);
    #else /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, right_forward, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, left_rewind, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, right_forward, KEY_EVENT_UP);
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, left_rewind, KEY_EVENT_UP);
    #endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, KEY_VOL_UP, KEY_EVENT_UP);
        SetKeyHandler(mmi_dtv_player_fullscr_osd_show_up, KEY_VOL_DOWN, KEY_EVENT_UP);

    #ifdef __MMI_TOUCH_SCREEN__
        wgui_register_pen_down_handler(mmi_dtv_player_pen_down_hdlr_fullscreen);
    #endif
    }

    gdi_layer_push_and_set_active(dtv_player_p->osd_layer_handle);
    gdi_layer_set_opacity(MMI_TRUE, (U8) dtv_player_p->fullscr_osd_opacity);
    gdi_layer_pop_and_restore_active();

    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_fullscr_reset_osd_fade
 * DESCRIPTION
 *  fade fullscr osd
 * PARAMETERS
 *  sleep       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_fullscr_reset_osd_fade(BOOL sleep)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_dtv_player_fullscr_osd_fade_cyclic);

    if (dtv_player_p->fullscr_osd_opacity != MMI_DTV_PLAYER_OSD_FADEOUT_FACTOR)
    {
        dtv_player_p->fullscr_osd_opacity = MMI_DTV_PLAYER_OSD_FADEOUT_FACTOR;
        mmi_dtv_player_draw_osd();
        gdi_layer_push_and_set_active(dtv_player_p->osd_layer_handle);
        gdi_layer_set_opacity(MMI_TRUE, (U8) dtv_player_p->fullscr_osd_opacity);
        gdi_layer_pop_and_restore_active();
    }
    else
    {
        mmi_dtv_player_draw_osd();
    }


    if (sleep)
    {
        /* These cases does not allow fade out */
        if (mmi_dtv_player_is_flag_set(DTV_PLAYER_BAD_RECEPTION)||
            mmi_dtv_player_is_flag_set(DTV_PLAYER_SERVICE_UNAVAILABLE) ||
            mmi_dtv_player_is_flag_set(DTV_PLAYER_ACCESS_DENIED) ||
            mmi_dtv_player_is_flag_set(DTV_PLAYER_UNAVAILABLE_IN_CALL) ||
            dtv_player_p->touch_object != DTV_PLAYER_TOUCH_NONE)
        {
            return;
        }

        /* start fade out timer */
        gui_start_timer(MMI_DTV_PLAYER_OSD_FADE_OUT_TIME, mmi_dtv_player_fullscr_osd_fade_cyclic);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_draw_animation
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_draw_animation(
        S32 offset_x, S32 offset_y, S32 width, S32 height,
        U16 image_id, gdi_handle *anima_handle)
{
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
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        rotate = MMI_FALSE;
    }
    else
    {

    #if !defined(__MMI_DTV_LANDSCAPE_SUPPORT__)
        rotate = MMI_TRUE;
    #else /* !__MMI_DTV_LANDSCAPE_SUPPORT__ */
        rotate = MMI_FALSE;
    #endif /* !__MMI_DTV_LANDSCAPE_SUPPORT__*/
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
            layer = (gdi_layer_struct *) dtv_player_p->osd_layer_handle;

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
                mmi_dtv_player_animation_draw_after_hdlr);

            gdi_anim_draw_id(
                offset_x,
                offset_y,
                image_id,
                anima_handle);
        }
        else
        {
            layer = (gdi_layer_struct *) dtv_player_p->osd_layer_handle;
            drawing_layer = (gdi_layer_struct *) dtv_player_p->osd_drawing_layer_handle;

            icon_region.x1 = offset_x;
            icon_region.x2 = offset_x + width;
            icon_region.y1 = offset_y;
            icon_region.y2 = offset_y + height;

            mmi_dtv_player_counter_clockwise_rotate(
                drawing_layer->buf_ptr,
                layer->buf_ptr,
                drawing_layer->width,
                drawing_layer->height,
                &icon_region);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_animation_draw_after_hdlr
 * DESCRIPTION
 *  mobile tv player animation draw after handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_animation_draw_after_hdlr(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef GDI_USING_2D_ENGINE_V3
    PU8 dest;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270);

    /* Copy osd_drawing_layer to osd_layer */
    gdi_layer_push_and_set_active(dtv_player_p->osd_layer_handle);
#if !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
    gdi_layer_toggle_double();
#endif
#if defined(GDI_USING_2D_ENGINE_V3)
    gdi_2d_begin();
    gdi_2d_set_layer_as_dest_buffer(dtv_player_p->osd_layer_handle);
    gdi_2d_set_layer_as_src_bitblt_buffer(dtv_player_p->osd_drawing_layer_handle);
    gdi_2d_rotate(GDI_TRANSFORM_ROTATE_90);
    gdi_2d_end();
#else
    gdi_layer_get_buffer_ptr(&dest);
    /* toggle double buffer */
    mmi_dtv_player_sw_rotate(
        dest,
        dtv_player_p->osd_drawing_layer_buf_ptr,
        (U32) LCD_HEIGHT,
        (U32) LCD_WIDTH);
#endif
    gdi_layer_pop_and_restore_active();

    /* GDI only blt the animation icon region in protrait coordinate. So we need to blt */
    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_animation_draw_after_hdlr
 * DESCRIPTION
 *  mobile tv player animation draw after handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_radio_draw_after_hdlr(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width, str_height, x;
    CHAR *str_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gdi_layer_push_and_set_active(dtv_player_p->display_layer_handle);

    /* Draw radio string */
    str_ptr = GetString(STR_ID_DTV_PLAYER_RADIO);

#if defined(__MMI_DTV_SMALL_HINT__)
	gui_set_font(&MMI_small_font);
#else
	gui_set_font(&MMI_medium_font);
#endif
    gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);

    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        x = (DTV_PLAYER_DISPLAY_LAYER_WIDTH - str_width) >> 1;
        mmi_dtv_player_draw_style_text(str_ptr, x, 30);
    }
    else
    {
        x = (DTV_PLAYER_FULLSCREEN_DISPLAY_LAYER_WIDTH - str_width) >> 1;
        mmi_dtv_player_draw_style_text(str_ptr, x, 30);
    }

    gdi_layer_pop_and_restore_active();

    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

}
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_draw_radio_animation
 * DESCRIPTION
 *  mobile tv player draw radio animation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_draw_radio_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 screen_id = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dtv_player_p->radio_amin_handle != GDI_NULL_HANDLE)
    {
        return;
    }

    if (screen_id == SCR_ID_DTV_PLAYER_APP)
    {
        gdi_layer_push_and_set_active(dtv_player_p->display_layer_handle);
        gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
        gdi_layer_clear(GDI_COLOR_BLACK);

        gdi_anim_set_draw_after_callback(
            mmi_dtv_player_radio_draw_after_hdlr);

        if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
        {
            gdi_anim_draw_id(0, 0, IMG_ID_DTV_PLAYER_DAB_ANIMATION, &dtv_player_p->radio_amin_handle);
        }
        else
        {
            gdi_anim_draw_id(0, 0, IMG_ID_DTV_PLAYER_DAB_ANIMATION_H, &dtv_player_p->radio_amin_handle);
        }

        gdi_layer_pop_and_restore_active();
    }
    else if (screen_id == SCR_ID_DTV_PLAYER_CHANNEL_LIST)
    {
        gdi_layer_push_and_set_active(dtv_player_p->cl_preview_layer_handle);
        gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
        gdi_layer_clear(GDI_COLOR_BLACK);

        gdi_anim_draw_id(0, 0, IMG_ID_DTV_PLAYER_DAB_ANIMATION_PREVIEW, &dtv_player_p->radio_amin_handle);

        gdi_layer_pop_and_restore_active();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_stop_radio_animation
 * DESCRIPTION
 *  The funciton stops radio animation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_stop_radio_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dtv_player_p->radio_amin_handle != GDI_NULL_HANDLE)
    {
        gdi_image_stop_animation(dtv_player_p->radio_amin_handle);
        dtv_player_p->radio_amin_handle = GDI_NULL_HANDLE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_draw_time_shift_osd
 * DESCRIPTION
 *  mobile tv player draw timeshift osd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_draw_osd_time_shift(void)
{
#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 buf_width = 0;
    S16 ts_idx;
    S16 ts_buf_idx;
    U16 play_pause_id;
    S32 offset_3;
    U16 i = 0;
    dtv_player_osd_icon_struct *osd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Following: only draw when in tims shift mode */
    if (dtv_player_p->osd_mode != MMI_DTV_OSD_MODE_TIME_SHIFT)
    {
        return;
    }

    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        offset_3 = 0;
    }
    else
    {
        offset_3 = 3;
    }


    /* timeshift bar */
    /* when play just started, the max_timeshit_daley (from buffer_duration) may be 0 )*/
    if (RECORDER_STATE_IN(DTV_RECORDER_RECORD))
    {
        dtv_player_p->max_timeshift_delay = dtv_player_p->max_delay;
    }

    buf_width = dtv_player_p->active_osd_cntx_p->ts_bar.width;

    /* If time shift is not enable, don't draw ts-bar */
    if (dtv_player_p->is_timeshift_enable == MMI_FALSE ||
        dtv_player_p->is_ready_to_ts == MMI_FALSE)
    {
        ts_idx = 0;
        ts_buf_idx = 0;
    }
    else if (dtv_player_p->max_timeshift_delay == 0) /* To avoid devide by zero */
    {
        ts_idx = 0;
        ts_buf_idx = 0;
    }
    else
    {
        ts_idx = buf_width * (dtv_player_p->max_delay - dtv_player_p->play_delay) / dtv_player_p->max_timeshift_delay;
        ts_buf_idx = buf_width * dtv_player_p->max_delay / dtv_player_p->max_timeshift_delay;
    }

    /* Bar: background */
    osd = &dtv_player_p->active_osd_cntx_p->ts_bar;
    gdi_image_draw_id (osd->offset_x, osd->offset_y, IMG_ID_DTV_PROGRESS_BAR + offset_3);

    /*Bar: foreground */
    gdi_layer_set_clip(
        osd->offset_x,
        osd->offset_y,
        osd->offset_x + ts_buf_idx,
        osd->offset_y + osd->height);

    gdi_image_draw_id(osd->offset_x, osd->offset_y, IMG_ID_DTV_PROGRESS_FULL + offset_3);
    gdi_layer_reset_clip();

    /* draw indicator */
    if(ts_idx >= buf_width - dtv_player_p->active_osd_cntx_p->ts_ind.width)
    {
        gdi_image_draw_id(
            dtv_player_p->active_osd_cntx_p->ts_bar.offset_x + buf_width - dtv_player_p->active_osd_cntx_p->ts_ind.width,
            dtv_player_p->active_osd_cntx_p->ts_ind.offset_y,
            IMG_ID_DTV_PROGRESS_IND + offset_3);
    }
    else
    {
        gdi_image_draw_id(
            dtv_player_p->active_osd_cntx_p->ts_bar.offset_x + ts_idx,
            dtv_player_p->active_osd_cntx_p->ts_ind.offset_y,
            IMG_ID_DTV_PROGRESS_IND + offset_3);
    }

    /* Forward */
    if(dtv_player_p->active_osd_cntx_p->forward.status == DTV_PLAYER_ICON_STATUS_ENABLE)
    {
        gdi_image_draw_id(
            dtv_player_p->active_osd_cntx_p->forward.offset_x,
            dtv_player_p->active_osd_cntx_p->forward.offset_y,
            (U16)(IMG_ID_DTV_PLAYER_FORWARD_UP + offset_3));
    }
    else if(dtv_player_p->active_osd_cntx_p->forward.status == DTV_PLAYER_ICON_STATUS_CLICKED)
    {
        gdi_image_draw_id(
            dtv_player_p->active_osd_cntx_p->forward.offset_x,
            dtv_player_p->active_osd_cntx_p->forward.offset_y,
            (U16)(IMG_ID_DTV_PLAYER_FORWARD_DOWN + offset_3));
    }
    else if(dtv_player_p->active_osd_cntx_p->forward.status == DTV_PLAYER_ICON_STATUS_DISABLE)
    {
        gdi_image_draw_id(
            dtv_player_p->active_osd_cntx_p->forward.offset_x,
            dtv_player_p->active_osd_cntx_p->forward.offset_y,
            (U16)(IMG_ID_DTV_PLAYER_FORWARD_DISABLE + offset_3));
    }

    /* Rewind */
    if(dtv_player_p->active_osd_cntx_p->rewind.status == DTV_PLAYER_ICON_STATUS_ENABLE)
    {
        gdi_image_draw_id(
            dtv_player_p->active_osd_cntx_p->rewind.offset_x,
            dtv_player_p->active_osd_cntx_p->rewind.offset_y,
            (U16)(IMG_ID_DTV_PLAYER_REWIND_UP + offset_3));
    }
    else if(dtv_player_p->active_osd_cntx_p->rewind.status == DTV_PLAYER_ICON_STATUS_CLICKED)
    {
        gdi_image_draw_id(
            dtv_player_p->active_osd_cntx_p->rewind.offset_x,
            dtv_player_p->active_osd_cntx_p->rewind.offset_y,
            (U16)(IMG_ID_DTV_PLAYER_REWIND_DOWN + offset_3));
    }
    else if(dtv_player_p->active_osd_cntx_p->rewind.status == DTV_PLAYER_ICON_STATUS_DISABLE)
    {
        gdi_image_draw_id(
            dtv_player_p->active_osd_cntx_p->rewind.offset_x,
            dtv_player_p->active_osd_cntx_p->rewind.offset_y,
            (U16)(IMG_ID_DTV_PLAYER_REWIND_DISABLE + offset_3));
    }

    if (dtv_player_p->ui_rotate != MMI_FRM_SCREEN_ROTATE_0)
    {
        /* Don't need to draw play speed and play icon */
        return;
    }


#endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_draw_osd_other
 * DESCRIPTION
 *  mobile tv player draw osd other
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_draw_osd_other(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset = 0;
    U16 play_id = 0;
#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__	
    S32 offset_2 = 0;
#endif	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        offset = 0;
#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__	
        offset_2 = 0;
#endif
    }
    else if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        offset = 3;
#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__	
        offset_2 = 2;
#endif
    }

    /* Fullscreen */
    if(dtv_player_p->active_osd_cntx_p->fullscreen.status == DTV_PLAYER_ICON_STATUS_ENABLE)
    {
        gdi_image_draw_id(
            dtv_player_p->active_osd_cntx_p->fullscreen.offset_x,
            dtv_player_p->active_osd_cntx_p->fullscreen.offset_y,
            (U16)(IMG_ID_DTV_PLAYER_FULLSCREEN_UP + offset));
    }
    else if(dtv_player_p->active_osd_cntx_p->fullscreen.status == DTV_PLAYER_ICON_STATUS_CLICKED)
    {
        gdi_image_draw_id(
            dtv_player_p->active_osd_cntx_p->fullscreen.offset_x,
            dtv_player_p->active_osd_cntx_p->fullscreen.offset_y,
            (U16)(IMG_ID_DTV_PLAYER_FULLSCREEN_DOWN + offset));
    }
    else if(dtv_player_p->active_osd_cntx_p->fullscreen.status == DTV_PLAYER_ICON_STATUS_DISABLE)
    {
        gdi_image_draw_id(
            dtv_player_p->active_osd_cntx_p->fullscreen.offset_x,
            dtv_player_p->active_osd_cntx_p->fullscreen.offset_y,
            (U16)(IMG_ID_DTV_PLAYER_FULLSCREEN_DISABLE + offset));
    }


    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        /* Cycle */
        if(dtv_player_p->active_osd_cntx_p->cycle.status == DTV_PLAYER_ICON_STATUS_ENABLE)
        {
            gdi_image_draw_id(
                dtv_player_p->active_osd_cntx_p->cycle.offset_x,
                dtv_player_p->active_osd_cntx_p->cycle.offset_y,
                (U16)(IMG_ID_DTV_PLAYER_CYCLE_UP));
        }
        else if(dtv_player_p->active_osd_cntx_p->cycle.status == DTV_PLAYER_ICON_STATUS_CLICKED)
        {
            gdi_image_draw_id(
                dtv_player_p->active_osd_cntx_p->cycle.offset_x,
                dtv_player_p->active_osd_cntx_p->cycle.offset_y,
                (U16)(IMG_ID_DTV_PLAYER_CYCLE_DOWN));
        }
        else if(dtv_player_p->active_osd_cntx_p->cycle.status == DTV_PLAYER_ICON_STATUS_DISABLE)
        {
            gdi_image_draw_id(
                dtv_player_p->active_osd_cntx_p->cycle.offset_x,
                dtv_player_p->active_osd_cntx_p->cycle.offset_y,
                (U16)(IMG_ID_DTV_PLAYER_CYCLE_DISABLE));
        }

        /* play icon */
        if (KERNEL_STATE_IN(DTV_KERNEL_READY))
        {
            if (PLAYER_STATE_IN(DTV_PLAYER_STOPPED))
            {
                play_id = IMG_ID_DTV_PLAYER_PLAY_UP;
            }
            else
            {
                play_id = IMG_ID_DTV_PLAYER_PLAY_STOP_UP;
            }
        }
        else if (KERNEL_STATE_IN(DTV_KERNEL_INIT) ||
                 KERNEL_STATE_IN(DTV_KERNEL_SUB_UPDATING))
        {
            play_id = IMG_ID_DTV_PLAYER_PLAY_STOP_UP;
        }
        else if (KERNEL_STATE_IN(DTV_KERNEL_OPENED))
        {
            play_id = IMG_ID_DTV_PLAYER_PLAY_UP;
        }

        if(dtv_player_p->active_osd_cntx_p->play.status == DTV_PLAYER_ICON_STATUS_ENABLE)
        {
            gdi_image_draw_id(dtv_player_p->active_osd_cntx_p->play.offset_x,dtv_player_p->active_osd_cntx_p->play.offset_y,(U16)(play_id));
        }
        else if(dtv_player_p->active_osd_cntx_p->play.status == DTV_PLAYER_ICON_STATUS_CLICKED)
        {
            gdi_image_draw_id(dtv_player_p->active_osd_cntx_p->play.offset_x,dtv_player_p->active_osd_cntx_p->play.offset_y,(U16)(play_id+1));
        }
        else if(dtv_player_p->active_osd_cntx_p->play.status == DTV_PLAYER_ICON_STATUS_DISABLE)
        {
        	#ifdef __MBBMS_INTER__
			if (DTV_PLAYER_INT_STATE_HALF_SCREEN != dtv_player_p->int_state)
			#endif
			{				
				gdi_image_draw_id(dtv_player_p->active_osd_cntx_p->play.offset_x,dtv_player_p->active_osd_cntx_p->play.offset_y, IMG_ID_DTV_PLAYER_PLAY_STOP_DISABLE);
			}
        }

    }

    /* Change */
#if defined(__MDI_DTV_TIME_SHIFT_SUPPORT__ )
    if(dtv_player_p->active_osd_cntx_p->change.status == DTV_PLAYER_ICON_STATUS_ENABLE)
    {
        gdi_image_draw_id(
            dtv_player_p->active_osd_cntx_p->change.offset_x,
            dtv_player_p->active_osd_cntx_p->change.offset_y,
            (U16)(IMG_ID_DTV_PLAYER_CHANGE_UP + offset_2));
    }
    else if(dtv_player_p->active_osd_cntx_p->change.status == DTV_PLAYER_ICON_STATUS_CLICKED)
    {
        gdi_image_draw_id(
            dtv_player_p->active_osd_cntx_p->change.offset_x,
            dtv_player_p->active_osd_cntx_p->change.offset_y,
            (U16)(IMG_ID_DTV_PLAYER_CHANGE_DOWN + offset_2));
    }

    if (dtv_player_p->osd_mode != MMI_DTV_OSD_MODE_CHANNEL)
    {
        /* Don't draw channel next, prev */
        return;
    }
#endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__  */

    /* Channel next */
    if(dtv_player_p->active_osd_cntx_p->channel_next.status == DTV_PLAYER_ICON_STATUS_ENABLE)
    {
        gdi_image_draw_id(
            dtv_player_p->active_osd_cntx_p->channel_next.offset_x,
            dtv_player_p->active_osd_cntx_p->channel_next.offset_y,
            (U16)(IMG_ID_DTV_PLAYER_CHANNEL_NEXT_UP + offset));
    }
    else if(dtv_player_p->active_osd_cntx_p->channel_next.status == DTV_PLAYER_ICON_STATUS_CLICKED)
    {
        gdi_image_draw_id(
            dtv_player_p->active_osd_cntx_p->channel_next.offset_x,
            dtv_player_p->active_osd_cntx_p->channel_next.offset_y,
            (U16)(IMG_ID_DTV_PLAYER_CHANNEL_NEXT_DOWN + offset));
    }
    else if(dtv_player_p->active_osd_cntx_p->channel_next.status == DTV_PLAYER_ICON_STATUS_DISABLE)
    {
        gdi_image_draw_id(
            dtv_player_p->active_osd_cntx_p->channel_next.offset_x,
            dtv_player_p->active_osd_cntx_p->channel_next.offset_y,
            (U16)(IMG_ID_DTV_PLAYER_CHANNEL_NEXT_DISABLE + offset));
    }


    /* Channel prev */
    if(dtv_player_p->active_osd_cntx_p->channel_prev.status == DTV_PLAYER_ICON_STATUS_ENABLE)
    {
        gdi_image_draw_id(
            dtv_player_p->active_osd_cntx_p->channel_prev.offset_x,
            dtv_player_p->active_osd_cntx_p->channel_prev.offset_y,
            (U16)(IMG_ID_DTV_PLAYER_CHANNEL_PREV_UP + offset));
    }
    else if(dtv_player_p->active_osd_cntx_p->channel_prev.status == DTV_PLAYER_ICON_STATUS_CLICKED)
    {
        gdi_image_draw_id(
            dtv_player_p->active_osd_cntx_p->channel_prev.offset_x,
            dtv_player_p->active_osd_cntx_p->channel_prev.offset_y,
            (U16)(IMG_ID_DTV_PLAYER_CHANNEL_PREV_DOWN + offset));
    }
    else if(dtv_player_p->active_osd_cntx_p->channel_prev.status == DTV_PLAYER_ICON_STATUS_DISABLE)
    {
        gdi_image_draw_id(
            dtv_player_p->active_osd_cntx_p->channel_prev.offset_x,
            dtv_player_p->active_osd_cntx_p->channel_prev.offset_y,
            (U16)(IMG_ID_DTV_PLAYER_CHANNEL_PREV_DISABLE + offset));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_draw_osd_vol_inc_dec_icon
 * DESCRIPTION
 *  mobile tv player draw osd volume
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_draw_osd_vol_inc_dec_icon(void)
{
#if defined(__MMI_DTV_LANDSCAPE_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_DTV_LANDSCAPE_SUPPORT__
    if (dtv_player_p->ui_rotate != MMI_FRM_SCREEN_ROTATE_0)
    {
        return;
    }
#endif

    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        offset = 0;
    }
    else
    {
        offset = 2;
    }

    /* Volume key: up */
    if (dtv_player_p->setting.vol_level == DTV_PLAYER_VOL_16)
    {
    #ifdef __MMI_DTV_LANDSCAPE_SUPPORT__
        gdi_image_draw_id(dtv_player_p->active_osd_cntx_p->vol_inc.offset_x,dtv_player_p->active_osd_cntx_p->vol_inc.offset_y,(U16)(IMG_ID_DTV_PLAYER_VOL_INC_DISABLE));
    #endif
    }
    else if(dtv_player_p->active_osd_cntx_p->vol_inc.status == DTV_PLAYER_ICON_STATUS_ENABLE)
    {
        gdi_image_draw_id(dtv_player_p->active_osd_cntx_p->vol_inc.offset_x,dtv_player_p->active_osd_cntx_p->vol_inc.offset_y,(U16)(IMG_ID_DTV_PLAYER_VOL_INC_UP+offset));
    }
    else if(dtv_player_p->active_osd_cntx_p->vol_inc.status == DTV_PLAYER_ICON_STATUS_CLICKED)
    {
        gdi_image_draw_id(dtv_player_p->active_osd_cntx_p->vol_inc.offset_x,dtv_player_p->active_osd_cntx_p->vol_inc.offset_y,(U16)(IMG_ID_DTV_PLAYER_VOL_INC_DOWN+offset));
    }

    /* Volume key: down */
    if (dtv_player_p->setting.vol_level == DTV_PLAYER_VOL_MUTE)
    {
    #ifdef __MMI_DTV_LANDSCAPE_SUPPORT__
        gdi_image_draw_id(dtv_player_p->active_osd_cntx_p->vol_dec.offset_x,dtv_player_p->active_osd_cntx_p->vol_dec.offset_y,(U16)(IMG_ID_DTV_PLAYER_VOL_DEC_DISABLE));
    #endif
    }
    else if(dtv_player_p->active_osd_cntx_p->vol_dec.status == DTV_PLAYER_ICON_STATUS_ENABLE)
    {
        gdi_image_draw_id(dtv_player_p->active_osd_cntx_p->vol_dec.offset_x,dtv_player_p->active_osd_cntx_p->vol_dec.offset_y,(U16)(IMG_ID_DTV_PLAYER_VOL_DEC_UP+offset));
    }
    else if(dtv_player_p->active_osd_cntx_p->vol_dec.status == DTV_PLAYER_ICON_STATUS_CLICKED)
    {
        gdi_image_draw_id(dtv_player_p->active_osd_cntx_p->vol_dec.offset_x,dtv_player_p->active_osd_cntx_p->vol_dec.offset_y,(U16)(IMG_ID_DTV_PLAYER_VOL_DEC_DOWN+offset));
    }
#endif /* #if defined(__MMI_DTV_LANDSCAPE_SUPPORT__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_stop_hint_animation
 * DESCRIPTION
 *  mmi_dtv_player_stop_hint_animation
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_stop_hint_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dtv_player_p->anim_handle != 0)
    {
        gdi_anim_stop(dtv_player_p->anim_handle);
        dtv_player_p->anim_handle = 0;
    }

    if (dtv_player_p->preview_state == DTV_PLAYER_PREVIEW_STATE_DECODED)
    {
        dtv_player_p->preview_state = DTV_PLAYER_PREVIEW_STATE_WAIT_DECODE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_draw_hint_animation
 * DESCRIPTION
 *  mobile tv player draw hint animation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_draw_hint_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 bt_y, init_y;
    S32 width, height, x;
    S32 total_width;
    MMI_BOOL preview_drawn = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        total_width = LCD_WIDTH;
        bt_y = MMI_DTV_PLAYER_BT_CONNECT_ICON_Y;
        init_y = MMI_DTV_PLAYER_LOADING_ICON_Y;
    }
    else
    {
        total_width = LCD_HEIGHT;
        bt_y = MMI_DTV_PLAYER_FULL_SCR_BT_CONNECT_ICON_Y;
        init_y = MMI_DTV_PLAYER_FULL_SCR_LOADING_ICON_Y;
    }

    if (PLAYER_STATE_IN(DTV_PLAYER_BT_CONNECT))
    {
        /* Check if BT animation could be drawn */
        if (!IsMyTimerExist(DTV_PLAYER_BT_ANIMATION_TIMER))
        {
            gdi_image_get_dimension(
                (U8*)GetImage(IMG_ID_DTV_BT_CONNECT), &width, &height);
            x = ((total_width - width)>>1);
            mmi_dtv_player_draw_animation(
                x, bt_y, width, height, IMG_ID_DTV_BT_CONNECT,
                &dtv_player_p->bt_connect_amin_handle);
        }
    }
    else if (KERNEL_STATE_IN(DTV_KERNEL_INIT) ||
             KERNEL_STATE_IN(DTV_KERNEL_SUB_UPDATING))
    {
        gdi_image_get_dimension(
                (U8*)GetImage(IMG_ID_DTV_PLAYER_LOADING), &width, &height);
        x = ((total_width - width)>>1);
    #ifdef __MMI_CMMB_PREVIEW_PIC_SUPPORT__
        preview_drawn = mmi_dtv_player_draw_preview_image(x, init_y, width, height);
    #endif
        /* Draw loading animation */
        if (!preview_drawn)
        {
            mmi_dtv_player_draw_animation(x, init_y, width, height, 
				                          IMG_ID_DTV_PLAYER_LOADING, 
				                          &dtv_player_p->anim_handle);
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_draw_osd_volume_status
 * DESCRIPTION
 *  mobile tv player draw osd volume
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_draw_osd_volume_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dtv_player_layout_struct *osd_p = dtv_player_p->active_osd_cntx_p;
    S32 length, offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        offset = 4;
    }

    /* Status */
    if (dtv_player_p->setting.is_mute)
    {
        gdi_image_draw_id(
            osd_p->vol_status.offset_x,
            osd_p->vol_status.offset_y,
            IMG_ID_DTV_PLAYER_VOL_STATUS_OFF + offset);
    }
    else
    {
        gdi_image_draw_id(
            osd_p->vol_status.offset_x,
            osd_p->vol_status.offset_y,
            IMG_ID_DTV_PLAYER_VOL_STATUS_ON + offset);
    }

    /* Level: background */
    gdi_image_draw_id(
        osd_p->volume.offset_x,
        osd_p->volume.offset_y,
        IMG_ID_DTV_PLAYER_VOL_LEVEL + offset);

    length = ((osd_p->volume.width * dtv_player_p->setting.vol_level) >>4);
    if(length)
    {
        /* Level: Part of full level */
        gdi_layer_set_clip(
            osd_p->volume.offset_x,
            osd_p->volume.offset_y,
            osd_p->volume.offset_x + length,
            osd_p->volume.offset_y + osd_p->volume.height);
        gdi_image_draw_id(
            osd_p->volume.offset_x,
            osd_p->volume.offset_y,
            IMG_ID_DTV_PLAYER_VOL_LEVEL_FULL + offset);
        gdi_layer_reset_clip();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_draw_osd_channel_name
 * DESCRIPTION
 *  mobile tv player draw osd channel name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_draw_osd_channel_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dtv_player_layout_struct *cntx_p;
    S32 idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cntx_p = dtv_player_p->active_osd_cntx_p;

    /* Subject */
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        idx = dtv_player_p->setting.selected_channel;        
        
        mmi_dtv_player_draw_channel_name_text(
            dtv_player_p->services[idx].service_name,
            &cntx_p->subject,
            MMI_FALSE, MMI_TRUE);
    }

    if (dtv_player_p->osd_mode != MMI_DTV_OSD_MODE_CHANNEL)
    {
        return;
    }


    ASSERT(dtv_player_p->num_services >= 1);

    if (dtv_player_p->touch_object == DTV_PLAYER_TOUCH_CHANNEL_PREV ||
        dtv_player_p->touch_object == DTV_PLAYER_TOUCH_CHANNEL_NEXT)
    {
        idx = dtv_player_p->temporal_channel;
    }
    else
    {
        idx = dtv_player_p->setting.selected_channel;
    }

    /* Previous channel name */
    if (idx - 1 >= 0)
    {
        mmi_dtv_player_draw_channel_name_text(
            dtv_player_p->services[idx - 1].service_name,
            &cntx_p->prev_channel_name,
            MMI_FALSE, MMI_FALSE);
    }

    /* Current channel name */
    mmi_dtv_player_draw_channel_name_text(
        dtv_player_p->services[idx].service_name,
        &cntx_p->cur_channel_name,
        MMI_TRUE, MMI_FALSE);

    /* Next channel name */
    if (idx + 1 < dtv_player_p->num_services)
    {
        mmi_dtv_player_draw_channel_name_text(
            dtv_player_p->services[idx + 1].service_name,
            &cntx_p->next_channel_name,
            MMI_FALSE, MMI_FALSE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_draw_osd_record_snapshot
 * DESCRIPTION
 *  mobile tv player draw osd record snapshot
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_draw_osd_record_snapshot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_3 = 0;
    U16 img_id;
#ifdef __MMI_DTV_RECORD_SUPPORT__
    S32 offset = 0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
#ifdef __MMI_DTV_RECORD_SUPPORT__
        offset = 0;
#endif
        offset_3 = 0;
    }
    else if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
#ifdef __MMI_DTV_RECORD_SUPPORT__
        offset = 2;
#endif
        offset_3 = 3;
        /* Don't need to draw */
        return;
    }

#if defined(__MMI_DTV_RECORD_SUPPORT__)
    /* record icon */
    if (RECORDER_STATE_IN(DTV_RECORDER_RECORD))
    {
        img_id = IMG_ID_DTV_PLAYER_RECORD_STOP_UP;
    }
    else
    {
        img_id = IMG_ID_DTV_PLAYER_RECORD_UP;
    }

    if(dtv_player_p->active_osd_cntx_p->record.status == DTV_PLAYER_ICON_STATUS_ENABLE)
    {
        gdi_image_draw_id(dtv_player_p->active_osd_cntx_p->record.offset_x,dtv_player_p->active_osd_cntx_p->record.offset_y,(U16)(img_id+offset));
    }
    else if(dtv_player_p->active_osd_cntx_p->record.status == DTV_PLAYER_ICON_STATUS_CLICKED )
    {
        gdi_image_draw_id(dtv_player_p->active_osd_cntx_p->record.offset_x,dtv_player_p->active_osd_cntx_p->record.offset_y,(U16)(img_id+offset+1));
    }
    else if(dtv_player_p->active_osd_cntx_p->record.status == DTV_PLAYER_ICON_STATUS_DISABLE)
    {
        gdi_image_draw_id(dtv_player_p->active_osd_cntx_p->record.offset_x,dtv_player_p->active_osd_cntx_p->record.offset_y,(U16)(img_id+offset+2));
    }

#elif defined(__MMI_DTV_SNAPSHOT_SUPPORT__)

    img_id = IMG_ID_DTV_PLAYER_SNAPSHOT_UP;
    if(dtv_player_p->active_osd_cntx_p->record.status == DTV_PLAYER_ICON_STATUS_ENABLE)
    {
        gdi_image_draw_id(dtv_player_p->active_osd_cntx_p->record.offset_x,dtv_player_p->active_osd_cntx_p->record.offset_y,(U16)(img_id+offset_3));
    }
    else if(dtv_player_p->active_osd_cntx_p->record.status == DTV_PLAYER_ICON_STATUS_CLICKED)
    {
        gdi_image_draw_id(dtv_player_p->active_osd_cntx_p->record.offset_x,dtv_player_p->active_osd_cntx_p->record.offset_y,(U16)(img_id+offset_3+1));
    }
    else if(dtv_player_p->active_osd_cntx_p->record.status == DTV_PLAYER_ICON_STATUS_DISABLE)
    {
        gdi_image_draw_id(dtv_player_p->active_osd_cntx_p->record.offset_x,dtv_player_p->active_osd_cntx_p->record.offset_y,(U16)(img_id+offset_3+2));
    }

#endif /* __MMI_DTV_SNAPSHOT_SUPPORT__ */
}

#ifdef __MBBMS_INTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_clear_dynamic_inter_desc
 * DESCRIPTION
 *  Clear inter description in Singe Line Mode 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_clear_dynamic_inter_desc(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	S32 offset_x = 0; 
	S32 offset_y = 0;
	S32 width    = DTV_PLAYER_INTER_LAYER_ONE_LINE_WIDTH;
	S32 height   = DTV_PLAYER_INTER_LAYER_ONE_LINE_HEIGHT;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if (DTV_PLAYER_DYNAMIC_LABEL_OFF == dtv_player_p->dynamic_inter_state)
	{
		return;
	}
	
	if (DTV_PLAYER_DYNAMIC_LABEL_SCROLLING == dtv_player_p->dynamic_inter_state)
	{
		gui_scrolling_text_stop(&dtv_player_p->scrolling_inter_des);
	}
    else if (DTV_PLAYER_DYNAMIC_LABEL_ON == dtv_player_p->dynamic_inter_state)
    {
		gui_cancel_timer(mmi_dtv_player_display_next_inter_desc);
    }
	/* Set active layer */
	if (MMI_FRM_SCREEN_ROTATE_0 == dtv_player_p->ui_rotate)
	{
		gdi_layer_push_and_set_active(dtv_player_p->dls_layer_handle);
        #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
		gdi_layer_toggle_double();
		gdi_layer_copy_double();
        #endif
	}
	gdi_draw_solid_rect(offset_x, offset_y, 
		                offset_x + width, offset_y + height,
	                 	GDI_COLOR_TRANSPARENT);
	gdi_layer_pop_and_restore_active();
	dtv_player_p->dynamic_inter_state = DTV_PLAYER_DYNAMIC_LABEL_OFF;
	mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_draw_inter_dynamic
 * DESCRIPTION
 *  Inter Single Line Scroll Text Timer Call Back, Record Scroll times 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_draw_inter_dynamic(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ((0 == dtv_player_p->scrolling_inter_des.scroll_x)
		&& (0 == dtv_player_p->scrolling_inter_des.scroll_counter)) 
	{
		if (MMI_DTV_PLAYER_INTER_DESC_SCROLL_TIMES <= dtv_player_p->scroll_inter_times)
		{
			mmi_dtv_player_display_next_inter_desc();
			dtv_player_p->scroll_inter_times = 0;
			return;
		}
		else
		{
			dtv_player_p->scroll_inter_times++;
		}
	}
	
	gdi_layer_push_and_set_active(dtv_player_p->dls_layer_handle);
		
    #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    gdi_layer_toggle_double();
    #endif

	    /* disable font alpha */
    #ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_fe_set_antialias(MMI_FALSE);
    #endif /* __MMI_VECTOR_FONT_SUPPORT__ */

    /* The two function will scroll text and blt out */
    gui_handle_scrolling_text(&dtv_player_p->scrolling_inter_des);
    gui_redraw_scrolling_text(&dtv_player_p->scrolling_inter_des);
	
    /* enable font alpha */
    #ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_fe_set_antialias(MMI_TRUE);
    #endif /* __MMI_VECTOR_FONT_SUPPORT__ */
	
	gdi_layer_pop_and_restore_active();
	mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
}

/*****************************************************************************
 * FUNCTION                                                                  
 * 	mmi_dtv_player_display_next_inter_desc                                    
 * DESCRIPTION                                                               
 *    search next unread inter description to display in single line mode                                                 
 * PARAMETERS                                                                
 *  void                                                                     
 * RETURNS                                                                   
 *  void                                                                      
 *****************************************************************************/
void mmi_dtv_player_display_next_inter_desc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mdi_mtv_imd_desc_struct imd_desc = {0};	
	dtv_player_service_info_struct *info_ptr = NULL;
	MMI_BOOL if_read = MMI_TRUE;
	U32 imd_index = 0;
	MMI_BOOL found_flag = MMI_FALSE;
	U16 active_screen = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 	
    active_screen = mmi_frm_scrn_get_active_id();  
    info_ptr = mmi_dtv_player_get_active_channel_ptr();
	if ((SCR_ID_DTV_PLAYER_APP == active_screen)
	    && (MMI_FRM_SCREEN_ROTATE_0 == dtv_player_p->ui_rotate)
	    && (MMI_TRUE == dtv_player_p->setting.inter_auto_popup)
	    && (0 < dtv_player_p->num_unread_imd))
	{
		dtv_player_p->imd_display_desc++;
		for (imd_index = dtv_player_p->imd_display_desc;
		     imd_index < dtv_player_p->num_imd;
			 imd_index++)
		{
			imd_desc.desc_len = MMI_DTV_INFO_STR_LENGTH;
	    	imd_desc.desc = (WCHAR* )dtv_player_p->info_str_buffer;
			imd_desc.if_read = &if_read;
			imd_desc.imd_index = imd_index;
			mdi_mtv_get_imd_desc(dtv_player_p->mtv_handle, info_ptr->service_id, &imd_desc);		
			if (MMI_FALSE == if_read)
			{
				found_flag = MMI_TRUE;
				break;
			}
		}
		
		if (MMI_TRUE == found_flag)
		{
			dtv_player_p->imd_display_desc = imd_index;
			dtv_player_p->selected_imd = dtv_player_p->imd_display_desc;
			mmi_dtv_player_clear_dynamic_inter_desc();
			mmi_dtv_player_draw_inter_description();
			mmi_dtv_player_draw_osd_and_blt();
		}
		else
		{
			mmi_dtv_player_clear_description();
		}
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_clear_description
 * DESCRIPTION
 *  clear inter description with Single Line Mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_clear_description(void)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_CLEAR_INTER_DESC);
	if (DTV_PLAYER_DYNAMIC_LABEL_OFF == dtv_player_p->dynamic_inter_state)
	{
		return;
	}
	dtv_player_p->int_state = DTV_PLAYER_INT_STATE_OFF;
	mmi_dtv_player_clear_dynamic_inter_desc();
	mmi_dtv_player_config_functions_by_state();
	mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);    
	mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_draw_inter_description
 * DESCRIPTION
 *  Display Inter Description with Single Line, scroll 2 times or keep 5 seconds
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_draw_inter_description(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 str_width  = 0;
    S32 str_height = 0;
	S32 offset_x = 0;
	S32 offset_y = 0;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (DTV_PLAYER_DYNAMIC_LABEL_OFF == dtv_player_p->dynamic_inter_state)
    {
    	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_DRAW_INTER_DESC);
		
		#ifdef __MMI_DTV_SMALL_HINT__
   		gui_set_font(&MMI_small_font);
		#else
        gui_set_font(&MMI_medium_font);
		#endif

    	gdi_layer_push_and_set_active(dtv_player_p->dls_layer_handle);
        #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
        gdi_layer_toggle_double();
        #endif
	    gdi_layer_clear(GDI_COLOR_TRANSPARENT);    		
		
		gui_measure_string((UI_string_type)dtv_player_p->info_str_buffer, 
			                &str_width, &str_height);
 		offset_y = (DTV_PLAYER_INTER_LAYER_ONE_LINE_HEIGHT - str_height) / 2;
		if (str_width < DTV_PLAYER_INTER_LAYER_ONE_LINE_WIDTH)
		{			
	        mmi_dtv_player_draw_style_text((CHAR*)dtv_player_p->info_str_buffer, 
	                                       offset_x,  offset_y);
			dtv_player_p->dynamic_inter_state = DTV_PLAYER_DYNAMIC_LABEL_ON;
			gui_start_timer(MMI_DTV_PLAYER_INTER_DESC_DELAY_SECONDS,
				            mmi_dtv_player_display_next_inter_desc);
		}
		else
		{
			#ifdef __MMI_VECTOR_FONT_SUPPORT__
    		mmi_fe_set_antialias(MMI_FALSE);
   			#endif /* __MMI_VECTOR_FONT_SUPPORT__ */

			/* reset times counter to record scoll times */
			dtv_player_p->scroll_inter_times = 0;						
			gui_create_scrolling_text(
						&dtv_player_p->scrolling_inter_des,
						offset_x + 2, /* border text will be out of range -2X~+2X */
						offset_y + 1, /* border text will be out of range -1Y~+1Y */
						DTV_PLAYER_INTER_LAYER_ONE_LINE_WIDTH - 4,
						DTV_PLAYER_INTER_LAYER_ONE_LINE_HEIGHT - 2,
						(UI_string_type) dtv_player_p->info_str_buffer,
						mmi_dtv_player_draw_inter_dynamic,
						mmi_dtv_player_scrolling_text_draw_background_hdlr,
						gui_color(255, 255, 255),
						gui_color(0,0,0));
			dtv_player_p->scrolling_inter_des.scroll_gap = 20;
			dtv_player_p->scrolling_inter_des.flags |= UI_SCROLLING_TEXT_BORDERED_TEXT;
			/* Draw first frame into active layer and blt out */
			gui_show_scrolling_text(&dtv_player_p->scrolling_inter_des);
			dtv_player_p->dynamic_inter_state = DTV_PLAYER_DYNAMIC_LABEL_SCROLLING;
			
			#ifdef __MMI_VECTOR_FONT_SUPPORT__
    		mmi_fe_set_antialias(MMI_TRUE);
   			#endif /* __MMI_VECTOR_FONT_SUPPORT__ */
		}
		
		gdi_layer_pop_and_restore_active();
    }
}

#endif /*__MBBMS_INTER__ */
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_draw_osd
 * DESCRIPTION
 *  mobile tv player draw osd handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_draw_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_DTV_LANDSCAPE_SUPPORT__)
    #ifndef GDI_USING_2D_ENGINE_V3
    PU8 dest;
    #endif
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        gdi_layer_push_and_set_active(dtv_player_p->osd_layer_handle);
    #if !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
        gdi_layer_toggle_double();
    #endif /* !(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__) */
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);

        gdi_image_draw_id(
            MMI_DTV_PLAYER_BG_OFFSET_X,
            MMI_DTV_PLAYER_BG_OFFSET_Y,
            IMG_ID_DTV_PLAYER_BG);
    }
    else if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
    #if !defined(__MMI_DTV_LANDSCAPE_SUPPORT__)
        gdi_layer_push_and_set_active(dtv_player_p->osd_drawing_layer_handle);
    #else /*!__MMI_DTV_LANDSCAPE_SUPPORT__ */
        gdi_layer_push_and_set_active(dtv_player_p->osd_layer_handle);
    #if !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
        gdi_layer_toggle_double();
    #endif /* !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__) */
    #endif /* !__MMI_DTV_LANDSCAPE_SUPPORT__ */
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);

        gdi_image_draw_id(
            MMI_DTV_PLAYER_FULL_SCR_BG_OFFSET_X,
            MMI_DTV_PLAYER_FULL_SCR_BG_OFFSET_Y,
            IMG_ID_DTV_PLAYER_BG_H);

    }

    /* EB notification */
    mmi_dtv_player_copy_eb_region();
    
    /* hint animation */
    mmi_dtv_player_draw_hint_animation();

    /* soft key */
    mmi_dtv_player_draw_osd_softkey();

    /* Channel information */
    mmi_dtv_player_draw_osd_channel_name();

#ifdef __MBBMS_INTER__
    //for UT
    if (dtv_player_p->ca_state != MMI_DTV_CA_STATE_CMMB)
    {
        /* Interactivity icon */
        mmi_dtv_player_draw_service_inter_icon();
    }
#endif    
    /* Fullscreen, Change, Cycle, Channel_Prev, Channel_Next */
    mmi_dtv_player_draw_osd_other();

    /* Volume */
    mmi_dtv_player_draw_osd_volume_status();
#if defined(__MMI_DTV_LANDSCAPE_SUPPORT__)
    mmi_dtv_player_draw_osd_vol_inc_dec_icon();
#endif

    /* Hint */
    if (dtv_player_p->hint_state != DTV_PLAYER_HINT_STATE_HIDE)
    {
        mmi_dtv_player_draw_hint();
    }

#if defined(__MMI_DTV_RECORD_SUPPORT__) || defined(__MMI_DTV_SNAPSHOT_SUPPORT__)
    mmi_dtv_player_draw_osd_record_snapshot();
#endif /* __MMI_DTV_RECORD_SUPPORT__ || __MMI_DTV_SNAPSHOT_SUPPORT__ */

    /* Time shift */
#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
    mmi_dtv_player_draw_osd_time_shift();
#endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */

    gdi_layer_pop_and_restore_active();


#if !defined(__MMI_DTV_LANDSCAPE_SUPPORT__)

    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        gdi_layer_push_and_set_active(dtv_player_p->osd_layer_handle);
    #if !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
        gdi_layer_toggle_double();
    #endif
    #if defined(GDI_USING_2D_ENGINE_V3)
        gdi_2d_begin();
        gdi_2d_set_layer_as_dest_buffer(dtv_player_p->osd_layer_handle);
        gdi_2d_set_layer_as_src_bitblt_buffer(dtv_player_p->osd_drawing_layer_handle);
        gdi_2d_rotate(GDI_TRANSFORM_ROTATE_90);
        gdi_2d_end();
    #else
        gdi_layer_get_buffer_ptr(&dest);
        /* toggle double buffer */
        mmi_dtv_player_sw_rotate(
            dest,
            dtv_player_p->osd_drawing_layer_buf_ptr,
            (U32) LCD_HEIGHT,
            (U32) LCD_WIDTH);
    #endif
        gdi_layer_pop_and_restore_active();
    }
#endif /* !__MMI_DTV_LANDSCAPE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_app_mem_success_callback
 * DESCRIPTION
 *  mobile tv player app mem callback function, it is called after
 *  succeed allocating memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_app_mem_success_callback(void)
{
#ifndef __COSMOS_MMI_PACKAGE__    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->app_mem_pool
        = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_DTV_PLAYER, MMI_DTV_PLAYER_APP_MEM_SIZE);

    /* It should provide enough memory */
    ASSERT(dtv_player_p->app_mem_pool != NULL);
    mmi_dtv_player_enter_app_main();
#endif /* __COSMOS_MMI_PACKAGE__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_create_adm
 * DESCRIPTION
 *  Delete ADM memory pool and free memory allocated from ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_create_adm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Create MemoryPool */
    if (dtv_player_p->app_mem_pool != NULL && dtv_player_p->adm_pool_id == NULL)
    {
        dtv_player_p->adm_pool_id = kal_adm_create((void*)dtv_player_p->app_mem_pool,
                                                    MMI_DTV_PLAYER_APP_MEM_SIZE,
                                                    NULL,
                                                    KAL_FALSE);
        ASSERT(dtv_player_p->adm_pool_id != NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_delete_adm
 * DESCRIPTION
 *  Delete ADM memory pool and free memory allocated from ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_delete_adm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_status ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Delete ADM */
    if (dtv_player_p->adm_pool_id)
    {
        ret = kal_adm_delete(dtv_player_p->adm_pool_id);

        ASSERT(ret == KAL_SUCCESS);
        dtv_player_p->adm_pool_id = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_alloc_adm_structure
 * DESCRIPTION
 *  Delete ADM memory pool and free memory allocated from ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_alloc_adm_structure(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* services */
    ASSERT(sizeof(dtv_player_service_info_struct) <= MMI_DTV_MAX_SERVICE_INFO_STRUCTURE_SIZE);
    if (dtv_player_p->services == NULL)
    {
        dtv_player_p->services = (dtv_player_service_info_struct*) kal_adm_alloc(
                                    dtv_player_p->adm_pool_id,
                                    MMI_DTV_MAX_SERVICES * sizeof(dtv_player_service_info_struct));
        ASSERT(dtv_player_p->services != NULL);
        memset(dtv_player_p->services, 0, MMI_DTV_MAX_SERVICES * sizeof(dtv_player_service_info_struct));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_free_adm_structure
 * DESCRIPTION
 *  Delete ADM memory pool and free memory allocated from ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_free_adm_structure(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* services */
    if (dtv_player_p->services != NULL)
    {
        kal_adm_free(dtv_player_p->adm_pool_id,(void *) dtv_player_p->services);
        dtv_player_p->services = NULL;
    }

    if (dtv_player_p->account != NULL)
    {
        kal_adm_free(dtv_player_p->adm_pool_id,(void *) dtv_player_p->account);
        dtv_player_p->account = NULL;
    }

#ifdef __MBBMS_CITY_LIST__
    mmi_dtv_player_free_city_mem();
#endif /* __MBBMS_CITY_LIST__ */

    if (dtv_player_p->cat1023_his_buf != NULL)
    {
        kal_adm_free(dtv_player_p->adm_pool_id,(void *) dtv_player_p->cat1023_his_buf);
        dtv_player_p->cat1023_his_buf = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_alloc_adm_layer
 * DESCRIPTION
 *  Delete ADM memory pool and free memory allocated from ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_alloc_adm_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
     /* osd layer: single buffer */
    dtv_player_p->osd_layer_buf_ptr_2 =
            (PU8) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(dtv_player_p->adm_pool_id, MMI_DTV_PLAYER_OSD_BUFFER_SIZE);
#endif /* __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ */

    /* create status bar layer */
#ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    dtv_player_p->status_bar_buf_ptr =
                (PU8) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(dtv_player_p->adm_pool_id, MMI_DTV_PLAYER_STATUS_BAR_BUFFER_SIZE*3);
#else /* __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ */
    dtv_player_p->status_bar_buf_ptr =
                (PU8) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(dtv_player_p->adm_pool_id, MMI_DTV_PLAYER_STATUS_BAR_BUFFER_SIZE);
#endif /* __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ */
    ASSERT(dtv_player_p->status_bar_buf_ptr != NULL);

    gdi_layer_create_using_outside_memory(
        0,
        0,
        LCD_WIDTH,
        MMI_STATUS_BAR_HEIGHT,
        &dtv_player_p->status_bar_layer_handle,
        dtv_player_p->status_bar_buf_ptr,
        MMI_DTV_PLAYER_STATUS_BAR_BUFFER_SIZE);

#ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    gdi_bltdb_set_blt_buffer(
        dtv_player_p->status_bar_layer_handle,
        dtv_player_p->status_bar_buf_ptr + MMI_DTV_PLAYER_STATUS_BAR_BUFFER_SIZE,
        MMI_DTV_PLAYER_STATUS_BAR_BUFFER_SIZE,
        dtv_player_p->status_bar_buf_ptr + 2* MMI_DTV_PLAYER_STATUS_BAR_BUFFER_SIZE,
        MMI_DTV_PLAYER_STATUS_BAR_BUFFER_SIZE);
#endif /* __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ */

    gdi_layer_push_and_set_active(dtv_player_p->status_bar_layer_handle);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    wgui_status_icon_bar_set_target_layer(
        WGUI_STATUS_ICON_BAR_H_BAR, dtv_player_p->status_bar_layer_handle);

    /* dls layer */
#ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    dtv_player_p->dls_layer_buf_ptr =
            (PU8) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(dtv_player_p->adm_pool_id, MMI_DTV_PLAYER_DLS_BUFFER_SIZE*3);
#else /* __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ */
    dtv_player_p->dls_layer_buf_ptr =
            (PU8) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(dtv_player_p->adm_pool_id, MMI_DTV_PLAYER_DLS_BUFFER_SIZE*2);
#endif  /* __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ */
    ASSERT(dtv_player_p->dls_layer_buf_ptr != NULL);

#ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    gdi_layer_create_using_outside_memory(
        0,
        0,
        DTV_PLAYER_DLS_BUFFER_WIDTH,
        DTV_PLAYER_DLS_BUFFER_HEIGHT,
        &dtv_player_p->dls_layer_handle,
        (PU8) dtv_player_p->dls_layer_buf_ptr,
        (S32) MMI_DTV_PLAYER_DLS_BUFFER_SIZE);
    gdi_bltdb_set_blt_buffer(
        dtv_player_p->dls_layer_handle,
        dtv_player_p->dls_layer_buf_ptr + MMI_DTV_PLAYER_DLS_BUFFER_SIZE,
        MMI_DTV_PLAYER_DLS_BUFFER_SIZE,
        dtv_player_p->dls_layer_buf_ptr + 2* MMI_DTV_PLAYER_DLS_BUFFER_SIZE,
        MMI_DTV_PLAYER_DLS_BUFFER_SIZE);
#else /* __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ */
    gdi_layer_create_double_using_outside_memory(
        0,
        0,
        DTV_PLAYER_DLS_BUFFER_WIDTH,
        DTV_PLAYER_DLS_BUFFER_HEIGHT,
        &dtv_player_p->dls_layer_handle,
        (PU8) dtv_player_p->dls_layer_buf_ptr,
        (S32) MMI_DTV_PLAYER_DLS_BUFFER_SIZE*2);
#endif /* __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ */

#if !defined(__MMI_DTV_LANDSCAPE_SUPPORT__)
    /* dls drawing layer */
    dtv_player_p->dls_drawing_layer_buf_ptr =
        (PU8) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(dtv_player_p->adm_pool_id, MMI_DTV_PLAYER_DLS_DRAWING_BUFFER_SIZE);
    ASSERT(dtv_player_p->dls_drawing_layer_buf_ptr != NULL);

    if(dtv_player_p->dls_drawing_layer_handle == GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_create_using_outside_memory(0,
									          0,
									          DTV_PLAYER_DLS_DRAWING_BUFFER_WIDTH,
									          DTV_PLAYER_DLS_DRAWING_BUFFER_HEIGHT,
									          &dtv_player_p->dls_drawing_layer_handle,
									          (PU8) dtv_player_p->dls_drawing_layer_buf_ptr,
									          MMI_DTV_PLAYER_DLS_DRAWING_BUFFER_SIZE);
        gdi_layer_push_and_set_active(dtv_player_p->dls_drawing_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }

#endif /* !__MMI_DTV_LANDSCAPE_SUPPORT__ */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_free_adm_layer
 * DESCRIPTION
 *  callback function used by applib to free APP-Based Memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_free_adm_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    if (dtv_player_p->osd_layer_buf_ptr_2 != NULL)
    {
        kal_adm_free(dtv_player_p->adm_pool_id, (void*)dtv_player_p->osd_layer_buf_ptr_2);
        dtv_player_p->osd_layer_buf_ptr_2 = NULL;
    }
#endif

    /* free status bar layer */
    wgui_status_icon_bar_reset_alpha_blend_layer(WGUI_STATUS_ICON_BAR_H_BAR);

    if (dtv_player_p->status_bar_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        /* Reset status bar layer config */
        wgui_status_icon_bar_set_target_layer(
            WGUI_STATUS_ICON_BAR_H_BAR, GDI_ERROR_HANDLE);

        gdi_layer_free(dtv_player_p->status_bar_layer_handle);
        dtv_player_p->status_bar_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    if (dtv_player_p->status_bar_buf_ptr != NULL)
    {
        kal_adm_free(dtv_player_p->adm_pool_id, (void*)dtv_player_p->status_bar_buf_ptr);
        dtv_player_p->status_bar_buf_ptr = NULL;
    }

    /* free dls layer resource */
    if (dtv_player_p->dls_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(dtv_player_p->dls_layer_handle);
        dtv_player_p->dls_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    if (dtv_player_p->dls_layer_buf_ptr != NULL)
    {
        kal_adm_free(dtv_player_p->adm_pool_id, (void*)dtv_player_p->dls_layer_buf_ptr);
        dtv_player_p->dls_layer_buf_ptr = NULL;
    }

#if !defined(__MMI_DTV_LANDSCAPE_SUPPORT__)

    /* free dls drawing layer resource */
    if (dtv_player_p->dls_drawing_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(dtv_player_p->dls_drawing_layer_handle);
        dtv_player_p->dls_drawing_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    if (dtv_player_p->dls_drawing_layer_buf_ptr != NULL)
    {
        kal_adm_free(dtv_player_p->adm_pool_id, (void*)dtv_player_p->dls_drawing_layer_buf_ptr);
        dtv_player_p->dls_drawing_layer_buf_ptr = NULL;
    }
#endif /* !__MMI_DTV_LANDSCAPE_SUPPORT__) */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_alloc_resource
 * DESCRIPTION
 *  this function creates scr-based resource for mtv player
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_alloc_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->osd_layer_buf_ptr =
        (PU8) applib_asm_alloc_nc_r(GRP_ID_DTV_PLAYER, MMI_DTV_PLAYER_OSD_BUFFER_SIZE*2);

    ASSERT(dtv_player_p->osd_layer_buf_ptr != NULL);

#ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    gdi_layer_create_using_outside_memory(
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT,
        &dtv_player_p->osd_layer_handle,
        (PU8) dtv_player_p->osd_layer_buf_ptr,
        (S32) (MMI_DTV_PLAYER_OSD_BUFFER_SIZE));
    gdi_bltdb_set_blt_buffer(
        dtv_player_p->osd_layer_handle,
        dtv_player_p->osd_layer_buf_ptr + MMI_DTV_PLAYER_OSD_BUFFER_SIZE,
        MMI_DTV_PLAYER_OSD_BUFFER_SIZE,
        dtv_player_p->osd_layer_buf_ptr_2,  /* From ASM */
        MMI_DTV_PLAYER_OSD_BUFFER_SIZE);
#else /* __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ */
    gdi_layer_create_double_using_outside_memory(
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT,
        &dtv_player_p->osd_layer_handle,
        (PU8) dtv_player_p->osd_layer_buf_ptr,
        (S32) (MMI_DTV_PLAYER_OSD_BUFFER_SIZE*2));
#endif /* __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ */

    /* display layer: from base layer buffer */
    if (dtv_player_p->display_layer_handle == GDI_LAYER_EMPTY_HANDLE)
    {
        result = gdi_layer_create(
            0,
            0,
            LCD_WIDTH,
            LCD_HEIGHT,
            &dtv_player_p->display_layer_handle);

        ASSERT (result != GDI_FAILED);

        gdi_layer_push_and_set_active(dtv_player_p->display_layer_handle);
        gdi_layer_set_background(GDI_COLOR_BLACK);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }

    mmi_dtv_player_config_layers();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_free_resource
 * DESCRIPTION
 *  this function frees scr-based resource for mtv player
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_free_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* OSD layer */
    if (dtv_player_p->osd_layer_buf_ptr != NULL)
    {
        applib_asm_free_r(GRP_ID_DTV_PLAYER, (void *)dtv_player_p->osd_layer_buf_ptr);
        dtv_player_p->osd_layer_buf_ptr = NULL;
    }

    if (dtv_player_p->osd_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(dtv_player_p->osd_layer_handle);
        dtv_player_p->osd_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }
    /* Display layer handle */
    if (dtv_player_p->display_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(dtv_player_p->display_layer_handle);
        dtv_player_p->display_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_alloc_base_layer
 * DESCRIPTION
 *  Delete ADM memory pool and free memory allocated from ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_alloc_base_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if !defined(__MMI_DTV_LANDSCAPE_SUPPORT__)

    /* osd drawing layer */
    gdi_layer_get_base_handle(&dtv_player_p->osd_drawing_layer_handle);
    gdi_layer_push_and_set_active(dtv_player_p->osd_drawing_layer_handle);

    gdi_layer_get_buffer_ptr(&dtv_player_p->osd_drawing_layer_buf_ptr);
    gdi_layer_get_source_key(
        &dtv_player_p->source_key_enable,
        &dtv_player_p->source_key_value);
    gdi_layer_get_dimension(
        &dtv_player_p->base_layer_width,
        &dtv_player_p->base_layer_height);

    gdi_layer_resize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();

#endif /*!__MMI_DTV_LANDSCAPE_SUPPORT__ */


}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_free_base_layer
 * DESCRIPTION
 *  Delete ADM memory pool and free memory allocated from ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_free_base_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if !defined(__MMI_DTV_LANDSCAPE_SUPPORT__)

    /* osd drawing layer */
    gdi_layer_push_and_set_active(dtv_player_p->osd_drawing_layer_handle);
    gdi_layer_set_source_key(
        dtv_player_p->source_key_enable,
        dtv_player_p->source_key_value);
    gdi_layer_resize(
        dtv_player_p->base_layer_width,
        dtv_player_p->base_layer_height);
    gdi_layer_pop_and_restore_active();

    dtv_player_p->osd_drawing_layer_buf_ptr = NULL;
    dtv_player_p->osd_drawing_layer_handle = GDI_LAYER_EMPTY_HANDLE;
#endif /* !__MMI_DTV_LANDSCAPE_SUPPORT__ */

}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_alloc_detail_screen_memory
 * DESCRIPTION
 *  for first time init channel list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_alloc_detail_screen_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->detail_buf =
            (CHAR *) applib_asm_alloc_r(GRP_ID_DTV_PLAYER, MMI_DTV_PLAYER_DETAIL_BUF_SIZE);
    ASSERT(dtv_player_p->detail_buf != NULL);
    memset(dtv_player_p->detail_buf, 0, MMI_DTV_PLAYER_DETAIL_BUF_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_free_detail_screen_memory
 * DESCRIPTION
 *  for first time init channel list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_free_detail_screen_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dtv_player_p->detail_buf != NULL)
    {
        applib_asm_free_r(GRP_ID_DTV_PLAYER, (void *)dtv_player_p->detail_buf);
        dtv_player_p->detail_buf = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_app_screen_leave_proc
 * DESCRIPTION
 *  delete screen id callback handler of mtv player applications
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 mmi_ret mmi_dtv_player_app_screen_leave_proc(mmi_event_struct *para)
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
            mmi_dtv_player_unset_flag(DTV_PLAYER_IS_SUBSCRIBE_CONFIRM_REJECTED);

        #ifdef __MMI_DTV_UPDATE_SUBSCRIPTION_TABLE__
            if (KERNEL_STATE_IN(DTV_KERNEL_SUB_UPDATING))
            {
                ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);
                ASSERT(ret == MDI_RES_MTV_SUCCEED);
            }
        #endif
            /* Avoid auto play */
            if (KERNEL_STATE_IN(DTV_KERNEL_INIT))
            {
                ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);
                ASSERT(ret == MDI_RES_MTV_SUCCEED);
            }

            if (RECORDER_STATE_IN(DTV_RECORDER_RECORD))
            {
                /* Only stop recorder. Enter save_confirm screen when entry again */
                mmi_dtv_player_recorder_enter_state(DTV_RECORDER_SAVE_CONFIRM);
            }
            if (RECORDER_STATE_IN(DTV_RECORDER_SAVE_CONFIRM))
            {
                RECORDER_ENTER_STATE(DTV_RECORDER_STOPPED);
            }

            if (!PLAYER_STATE_IN(DTV_PLAYER_STOPPED))
            {
                mmi_dtv_player_player_enter_state(DTV_PLAYER_STOPPED);
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
 *  mmi_dtv_player_store_setting
 * DESCRIPTION
 *  set mobile tv player settings from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_store_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(NVRAM_EF_DTV_PLAYER_SETTING_LID,
		        1,
		        (void*)&(dtv_player_p->setting),
		        NVRAM_EF_DTV_PLAYER_SETTING_SIZE,
		        &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_load_setting
 * DESCRIPTION
 *  load mobile tv player settings from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_load_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if setting is already loaded from NVRAM, it is already exist in memory, do not loaded again */
    if (!dtv_player_p->is_setting_loaded)
    {
        ReadRecord( NVRAM_EF_DTV_PLAYER_SETTING_LID,
		            1,
		            (void*)&dtv_player_p->setting,
		            NVRAM_EF_DTV_PLAYER_SETTING_SIZE,
		            &error);

        /* first time init */
        if (dtv_player_p->setting.storage == 0xffff)
        {
            mmi_dtv_player_restore_setting();
        }

        dtv_player_p->is_setting_loaded = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_restore_setting
 * DESCRIPTION
 *  restore mobile tv player default settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_restore_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->setting.brightness = MDI_MTV_BRIGHTNESS_0;
    dtv_player_p->setting.contrast = MDI_MTV_CONTRAST_0;
    dtv_player_p->setting.saturation = MDI_MTV_SATURATION_0;
    dtv_player_p->setting.selected_channel = 0;
    dtv_player_p->setting.storage = SRV_FMGR_PUBLIC_DRV;
    dtv_player_p->setting.vol_level = DTV_PLAYER_VOL_7;
    dtv_player_p->setting.is_mute = KAL_FALSE;
    dtv_player_p->setting.band = -1;
    dtv_player_p->setting.is_channel_list_init = MMI_FALSE;
    dtv_player_p->setting.filename_seq_no = 0;
#ifdef __MBBMS_DUAL_SIM_SUPPORT__
	dtv_player_p->setting.simcard = MMI_SIM_NONE;
#endif

    /* restore cl setting */
    dtv_player_p->setting.pro_remind_time = 0;
    dtv_player_p->setting.manual_set_loc = MMI_FALSE;
    dtv_player_p->setting.inter_auto_popup = MMI_TRUE;
    kal_mem_set(dtv_player_p->setting.location, 0, MMI_DTV_CITY_STR_LEN + 1);
    /* Default record size for CMMB solution */
    dtv_player_p->setting.record_size = MDI_MTV_RECORDER_SIZE_QCIF;
    WriteRecord(NVRAM_EF_DTV_PLAYER_SETTING_LID, 1, (void*)&dtv_player_p->setting, NVRAM_EF_DTV_PLAYER_SETTING_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_restore_setting
 * DESCRIPTION
 *  restore mobile tv player default settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_set_hint(CHAR *hint_str1, CHAR *hint_str2, U16 fade_time, MMI_BOOL multiline)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wstrcpy((WCHAR *) &dtv_player_p->hint1_buf, L"");
    kal_wstrcpy((WCHAR *) &dtv_player_p->hint2_buf, L"");

    if (hint_str1 != NULL)
    {
        mmi_ucs2ncpy((CHAR *) dtv_player_p->hint1_buf, (CHAR *) hint_str1, MMI_DTV_NAME_STR_LENGTH);
    }

    if (hint_str2 != NULL)
    {
        mmi_ucs2ncpy((CHAR *) dtv_player_p->hint2_buf, (CHAR *) hint_str2, MMI_DTV_NAME_STR_LENGTH);
    }

    if (multiline)
    {
        dtv_player_p->hint_state = DTV_PLAYER_HINT_STATE_SHOW_MULTILINE;
    }
    else
    {
        dtv_player_p->hint_state = DTV_PLAYER_HINT_STATE_SHOW_TRUNCATED;
    }

    dtv_player_p->fade_time = fade_time;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_draw_hint
 * DESCRIPTION
 *  draw preview OSD panel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_draw_hint(void)
{
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
    U16 img_id = IMG_ID_DTV_PLAYER_NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hint_str1 = dtv_player_p->hint1_buf;
    hint_str2 = dtv_player_p->hint2_buf;

    loc_y = dtv_player_p->active_osd_cntx_p->hint_box.offset_y;
    if (PLAYER_STATE_IN(DTV_PLAYER_BT_CONNECT)
        && (!IsMyTimerExist(DTV_PLAYER_BT_ANIMATION_TIMER)))
    {
        img_id = IMG_ID_DTV_BT_CONNECT;
        gdi_image_get_dimension_id(img_id, &width, &height);
        if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
        {
            loc_y = MMI_DTV_PLAYER_BT_CONNECT_ICON_Y + height + spacing;
        }
        else
        {
            loc_y = MMI_DTV_PLAYER_FULL_SCR_BT_CONNECT_ICON_Y + height + spacing;
        }
    }
    else
    {
        img_id = IMG_ID_DTV_PLAYER_LOADING;
        gdi_image_get_dimension_id(img_id, &width, &height);
        if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
        {
            loc_y = MMI_DTV_PLAYER_LOADING_ICON_Y + height + spacing;
        }
        else
        {
            loc_y = MMI_DTV_PLAYER_FULL_SCR_LOADING_ICON_Y + height + spacing;
        }
    }

    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

#if defined(__MMI_DTV_SMALL_HINT__)
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
        str1_offset_x = (dtv_player_p->active_osd_cntx_p->hint_box.width - str1_width) >> 1;
        str1_offset_y = spacing;

		if (str1_offset_x > 0)
        {
            mmi_dtv_player_draw_style_text(
                (CHAR *)hint_str1,
                dtv_player_p->active_osd_cntx_p->hint_box.offset_x + str1_offset_x,
                loc_y + str1_offset_y);
        }
        /* Hint1 is too long: Multiline or Truncated */
        else
        {
            if (dtv_player_p->hint_state == DTV_PLAYER_HINT_STATE_SHOW_TRUNCATED ||
                dtv_player_p->hint_state == DTV_PLAYER_HINT_STATE_FADING_TRUNCATED)
            {
                mmi_dtv_player_draw_truncated_style_text(
                    (CHAR *)hint_str1,
                    dtv_player_p->active_osd_cntx_p->hint_box.offset_x,
                    loc_y + str1_offset_y,
                    dtv_player_p->active_osd_cntx_p->hint_box.width);
            }
            else /* SHOW_MULTILINE or FADING_MULTILINE */
            {
                mmi_dtv_player_draw_multiline_style_text(
                    (CHAR* )hint_str1,
                    dtv_player_p->active_osd_cntx_p->hint_box.offset_x,
                    loc_y + str1_offset_y,
                    dtv_player_p->active_osd_cntx_p->hint_box.width);
            }
        }
    }

    if(hint_str2 != NULL && mmi_ucs2strlen((CHAR *)hint_str2) > 0)
    {
        gui_measure_string((UI_string_type) hint_str2, &str2_width, &str2_height);

        str2_offset_x = (dtv_player_p->active_osd_cntx_p->hint_box.width - str2_width) >> 1;
        str2_offset_y = str1_offset_y + spacing + str1_height;

		mmi_dtv_player_draw_style_text(
            (CHAR *)hint_str2,
            dtv_player_p->active_osd_cntx_p->hint_box.offset_x + str2_offset_x,
            loc_y + str2_offset_y);
    }

    /* enable font alpha */
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_fe_set_antialias(MMI_TRUE);
#endif

    /* If hint is already at fading state, don't start fade-out timer again */
    if (dtv_player_p->hint_state == DTV_PLAYER_HINT_STATE_SHOW_MULTILINE ||
        dtv_player_p->hint_state == DTV_PLAYER_HINT_STATE_SHOW_TRUNCATED)
    {
        if (dtv_player_p->fade_time != MMI_DTV_PLAYER_HINT_POPUP_NO_FADE)
        {
            gui_start_timer(dtv_player_p->fade_time , mmi_dtv_player_hide_hint);

            if (dtv_player_p->hint_state == DTV_PLAYER_HINT_STATE_SHOW_MULTILINE)
            {
                dtv_player_p->hint_state = DTV_PLAYER_HINT_STATE_FADING_MULTILINE;
            }
            else
            {
                dtv_player_p->hint_state = DTV_PLAYER_HINT_STATE_FADING_TRUNCATED;
            }
        }
        else
        {
            gui_cancel_timer(mmi_dtv_player_hide_hint);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_restore_setting
 * DESCRIPTION
 *  restore mobile tv player default settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_hide_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->hint_state = DTV_PLAYER_HINT_STATE_HIDE;

    if (mmi_dtv_player_is_flag_set(DTV_PLAYER_BAD_RECEPTION))
    {
        mmi_dtv_player_set_hint(
            (CHAR *) GetString((U16) (STR_ID_DTV_PLAYER_SERVICE_IS_NOT_AVAILABLE)),
            (CHAR *) NULL,
            MMI_DTV_PLAYER_HINT_POPUP_NO_FADE,
            MMI_TRUE);
    }
    else if (mmi_dtv_player_is_flag_set(DTV_PLAYER_SERVICE_UNAVAILABLE))
    {
        mmi_dtv_player_set_hint(
            (CHAR *) GetString((U16) (STR_ID_DTV_PLAYER_SERVICE_IS_NOT_AVAILABLE)),
			(CHAR *) NULL,
		    MMI_DTV_PLAYER_HINT_POPUP_NO_FADE,
            MMI_TRUE);
    }
    else if (mmi_dtv_player_is_flag_set(DTV_PLAYER_ACCESS_DENIED))
    {    	
	#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
		mmi_dtv_player_cmmb_2gpp_display_hint();	
	#else
        mmi_dtv_player_set_hint(
            (CHAR *) GetString((U16) (STR_ID_DTV_PLAYER_NOTIFY_ACCESS_DENIED)),
			(CHAR *) NULL,
		    MMI_DTV_PLAYER_HINT_POPUP_NO_FADE,
            MMI_TRUE);
	#endif
    }
    else if (mmi_dtv_player_is_flag_set(DTV_PLAYER_UNAVAILABLE_IN_CALL))
    {
        mmi_dtv_player_set_hint(
            (CHAR *) GetString((U16) (STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL)),
			(CHAR *) NULL,
		    MMI_DTV_PLAYER_HINT_POPUP_NO_FADE,
            MMI_TRUE);
    }

    mmi_dtv_player_draw_osd();
    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_config_display_layer
 * DESCRIPTION
 *  config display layer's size / rotation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_config_display_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 rotate_value = 0;
    S32 width, height, offset_x, offset_y;
    MMI_BOOL rotate_by_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        rotate_value = GDI_LAYER_ROTATE_0;
        rotate_by_layer = MMI_FALSE;
        width = DTV_PLAYER_DISPLAY_LAYER_WIDTH;
        height = DTV_PLAYER_DISPLAY_LAYER_HEIGHT;
        offset_x = DTV_PLAYER_DISPLAY_LAYER_OFFSET_X;
        offset_y = DTV_PLAYER_DISPLAY_LAYER_OFFSET_Y;

    }
    else
    {
    #if defined(__MMI_DTV_LANDSCAPE_SUPPORT__)

        rotate_value = GDI_LAYER_ROTATE_0;
        rotate_by_layer = MMI_FALSE;
        width = DTV_PLAYER_FULLSCREEN_DISPLAY_LAYER_WIDTH;
        height = DTV_PLAYER_FULLSCREEN_DISPLAY_LAYER_HEIGHT;
        offset_x = DTV_PLAYER_FULLSCREEN_DISPLAY_LAYER_OFFSET_X;
        offset_y = DTV_PLAYER_FULLSCREEN_DISPLAY_LAYER_OFFSET_Y;

    #else /* __MMI_DTV_LANDSCAPE_SUPPORT__ */


        rotate_value = GDI_LAYER_ROTATE_90; /* Origin: the top-right corner of LCD */
        rotate_by_layer = MMI_TRUE;
        width = DTV_PLAYER_FULLSCREEN_DISPLAY_LAYER_WIDTH;
        height = DTV_PLAYER_FULLSCREEN_DISPLAY_LAYER_HEIGHT;
        offset_x = DTV_PLAYER_FULLSCREEN_DISPLAY_LAYER_OFFSET_X;
        offset_y = DTV_PLAYER_FULLSCREEN_DISPLAY_LAYER_OFFSET_Y;

    #endif /* __MMI_DTV_LANDSCAPE_SUPPORT__ */
    }


    /* Rotate and Resize Display Layer */
    if (PLAYER_STATE_IN(DTV_PLAYER_STOPPED)||PLAYER_STATE_IN(DTV_PLAYER_PAUSE))
    {
        mdi_util_hw_layer_switch_to_sw_layer(dtv_player_p->display_layer_handle);    
        gdi_layer_push_and_set_active(dtv_player_p->display_layer_handle);
        gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
        gdi_layer_resize(width, height);
        gdi_layer_set_position(offset_x, offset_y);
        gdi_layer_set_rotate(rotate_value);
        gdi_lcd_set_rotate_by_layer(rotate_by_layer);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_config_layers
 * DESCRIPTION
 *  config all layer's size / rotation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_config_layers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dls_layer_width = 0;
	S32 dls_layer_height = 0; 
    S32 dls_layer_offset_x = 0;
	S32 dls_layer_offset_y = 0;
    U8 rotate_value = GDI_LAYER_ROTATE_0;
    MMI_BOOL rotate_by_layer = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        dtv_player_p->active_osd_cntx_p = &g_dtv_player_osd_cntx;
        wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
    }
    else
    {
        dtv_player_p->active_osd_cntx_p = &g_dtv_player_osd_cntx_270;
        wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_H_BAR);
    }

    /*******************************************
     * Rotate and Resize display Layer
     ********************************************/
    mmi_dtv_player_config_display_layer();

    /*******************************************
     * Rotate and Resize OSD Layer
     ********************************************/
    gdi_layer_push_and_set_active(dtv_player_p->osd_layer_handle);
    gdi_layer_resize(LCD_WIDTH, LCD_HEIGHT);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    wgui_status_icon_bar_set_alpha_blend_layer(
        WGUI_STATUS_ICON_BAR_H_BAR,
        dtv_player_p->osd_layer_handle);


    /*******************************************
     * Rotate and Resize DLS Layer
     ********************************************/


#ifdef __MBBMS_INTER__ 
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {       
        mmi_dtv_player_config_inter_layer();       
    }
    else
#endif         
    {        
        gdi_layer_push_and_set_active(dtv_player_p->dls_layer_handle);
    #if defined(__MMI_DTV_LANDSCAPE_SUPPORT__)
        dls_layer_width = DTV_PLAYER_FULLSCREEN_DLS_LAYER_WIDTH;
        dls_layer_height = DTV_PLAYER_FULLSCREEN_DLS_LAYER_HEIGHT;
        dls_layer_offset_x = DTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_X;
        dls_layer_offset_y = DTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_Y;
        rotate_value = GDI_LAYER_ROTATE_0;
        rotate_by_layer = KAL_FALSE;
    #else /* __MMI_DTV_LANDSCAPE_SUPPORT__ */
        dls_layer_width = DTV_PLAYER_FULLSCREEN_DLS_LAYER_HEIGHT;
        dls_layer_height = DTV_PLAYER_FULLSCREEN_DLS_LAYER_WIDTH;
        dls_layer_offset_x = LCD_WIDTH - DTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_Y - DTV_PLAYER_FULLSCREEN_DLS_LAYER_HEIGHT;
        dls_layer_offset_y = DTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_X;
        rotate_value = GDI_LAYER_ROTATE_0;
        rotate_by_layer = KAL_FALSE;
    #endif /* __MMI_DTV_LANDSCAPE_SUPPORT__ */
	    gdi_layer_resize(dls_layer_width, dls_layer_height);
	    gdi_layer_set_position(dls_layer_offset_x, dls_layer_offset_y);
	    gdi_layer_set_rotate(rotate_value);
	    gdi_lcd_set_rotate_by_layer(rotate_by_layer);
	    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
	    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
	    /* temp solution: signal & dls should not use the same layer */
	#if !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
	    gdi_layer_toggle_double();
	#endif
	    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
	    gdi_layer_pop_and_restore_active();
	}
#if !defined(__MMI_DTV_LANDSCAPE_SUPPORT__)
    /*******************************************
     * Rotate and Resize OSD drawing Layer
     ********************************************/
    gdi_layer_push_and_set_active(dtv_player_p->osd_drawing_layer_handle);
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        gdi_layer_resize(LCD_WIDTH, LCD_HEIGHT);  /* No need ? */
    }
    else
    {
        gdi_layer_resize(LCD_HEIGHT, LCD_WIDTH);
    }
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    /*******************************************
     * Rotate and Resize DLS drawing Layer
     ********************************************/
    gdi_layer_push_and_set_active(dtv_player_p->dls_drawing_layer_handle);
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        gdi_layer_resize(DTV_PLAYER_FULLSCREEN_DLS_LAYER_WIDTH, DTV_PLAYER_FULLSCREEN_DLS_LAYER_HEIGHT);
    }

    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
#endif /* !__MMI_DTV_LANDSCAPE_SUPPORT__*/


    /* Initialize icon position for touch */
    mmi_dtv_player_init_icon_info();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_handle_service_removed
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_handle_service_removed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dtv_player_remove_active_service();

    if (mmi_frm_scrn_is_present(
            GRP_ID_DTV_PLAYER,
            SCR_ID_DTV_PLAYER_APP_BASE,
            MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_dtv_player_display_popup(
            STR_ID_DTV_PLAYER_SERVICE_IS_NOT_AVAILABLE,
            MMI_EVENT_FAILURE);

        /* delete player screen if exist */
        mmi_frm_scrn_multiple_close(
            GRP_ID_DTV_PLAYER,
            mmi_frm_scrn_get_active_id(),
            0,
            0,
            SCR_ID_DTV_PLAYER_CHANNEL_LIST,
            0);

        StopTimer(DTV_PLAYER_UPDATE_SIGNAL_TIMER);
        gui_cancel_timer(mmi_dtv_player_enable_ts_function);

        /* Re-draw signal icon to level 0 */
        dtv_player_p->signal_strength = 0;
        mmi_dtv_player_draw_signal_icon();
    }
    else
    {
        mmi_dtv_player_terminate_app();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_handle_service_aborted
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_handle_service_aborted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (active_screen == SCR_ID_DTV_PLAYER_APP)
    {
        mmi_dtv_player_set_hint(
            (CHAR *) GetString((U16) (STR_ID_DTV_PLAYER_SERVICE_IS_NOT_AVAILABLE)),
			(CHAR *) NULL,
		    MMI_DTV_PLAYER_HINT_POPUP_NO_FADE,
            MMI_TRUE);
        mmi_dtv_player_set_flag(DTV_PLAYER_SERVICE_UNAVAILABLE);

        mmi_dtv_player_register_key_hdlr();

        mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);

        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }
    else if (active_screen == SCR_ID_DTV_PLAYER_CHANNEL_LIST)
    {
        mmi_dtv_player_draw_preview_icon(DTV_PLAYER_PREVIEW_ICON_BROKEN);
    }
    else if (!mmi_frm_scrn_is_present(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_APP_BASE,
                MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_dtv_player_terminate_app();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_service_found_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_service_found_hdlr(mdi_mtv_service_info_struct *service_info, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dtv_player_p->num_services < MMI_DTV_MAX_SERVICES
       && (
       #ifdef  __MMI_DTV_AUDIO_CHANNEL_SUPPORT__
           service_info->service_type == MEDIA_MTV_SERVICE_DIGITAL_RADIO ||
       #endif
           service_info->service_type == MEDIA_MTV_SERVICE_DIGITAL_TV))
    {
        U16 i = dtv_player_p->num_services;

        dtv_player_p->services[i].service_id = service_info->service_id;
        mmi_ucs2cpy((CHAR*)dtv_player_p->services[i].service_name, (CHAR*)L"");

		MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_DTV_VAL2, 
			      service_info->service_id, 
			      service_info->service_name,
			      __LINE__);

        if (service_info->service_name != NULL)
        {
    		MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_DTV_VAL3, 
		      service_info->service_id, 
		      service_info->service_name,
		      mmi_ucs2strlen((CHAR *)service_info->service_name),
		      __LINE__);			
            mmi_ucs2cpy((CHAR *)dtv_player_p->services[i].service_name, (CHAR *)service_info->service_name);
            if (mmi_ucs2strlen((CHAR *)service_info->service_name) == 0)
            {
                CHAR * unknown_channel_name;
                S32 length;
                unknown_channel_name = GetString((U16)STR_ID_DTV_PLAYER_NOTIFY_CHANNAL_NAME_UNKNOWN);
                /**
                 * Assume string length of resource: unknown channel < 64
                 ***/
                length = mmi_ucs2strlen(unknown_channel_name);
                ASSERT(length<64);
                mmi_ucs2cpy((CHAR *)dtv_player_p->services[i].service_name,unknown_channel_name);
            }
        }

        dtv_player_p->services[i].service_number = service_info->service_number;
        dtv_player_p->services[i].service_flags = service_info->service_flags;
        dtv_player_p->services[i].service_type = service_info->service_type;
        dtv_player_p->num_services ++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_search_progress_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_search_progress_hdlr(S32 value, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    MDI_RESULT ret;
    MMI_BOOL rescan, need_init = MMI_FALSE;
    void *param = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* should only called when live scan */
    ASSERT(KERNEL_STATE_IN(DTV_KERNEL_SCANNING));

    if (value != 0)
    {
        StopTimer(DTV_PLAYER_UPDATE_SCAN_STATUS);
    }
    if (dtv_player_p->ca_state != MMI_DTV_CA_STATE_CMMB)
    {
        value = dtv_player_p->scan_progress + value * (100 - dtv_player_p->scan_progress) / 100;
    }

    mmi_dtv_player_update_scan_progress(value);

    if (value != 100)
    {
        return;
    }

    /* Following: value == 100 */
    rescan = MMI_FALSE;
    if (dtv_player_p->num_services == 0)
    {
        if (mmi_dtv_player_is_flag_set(DTV_PLAYER_IS_LIVE_SCANNING) == MMI_FALSE)
        {
            rescan = MMI_TRUE;
        }
        else
        {
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
			#endif
        }
    }

    if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_MBBMS &&
        mmi_dtv_player_is_flag_set(DTV_PLAYER_IS_LIVE_SCANNING) == MMI_FALSE &&
        !g_mtv_mts_command)
    {
        need_init = MMI_TRUE;
    }

    mmi_dtv_player_assign_service_number();

    /* Scan from database and found out service == 0 */
    if (rescan)
    {
        /* scan again from air */
        dtv_player_p->setting.is_channel_list_init = MMI_FALSE;
        ret = mmi_dtv_player_kernel_entry_scanning_state();
        if (ret != MDI_RES_MTV_SUCCEED)
        {
            mmi_dtv_player_reset_to_channel_list_screen();
        }
        return;
    }


    if (dtv_player_p->num_services > 0)
    {
        /* When scan next time, scan from database */
        dtv_player_p->setting.is_channel_list_init = MMI_TRUE;
    }

    WriteRecord(NVRAM_EF_DTV_PLAYER_SETTING_LID, 1, (void*)&dtv_player_p->setting, NVRAM_EF_DTV_PLAYER_SETTING_SIZE, &error);

    KERNEL_ENTER_STATE(DTV_KERNEL_OPENED);

    /* update and save setting */
    mmi_dtv_player_unset_flag(DTV_PLAYER_IS_LIVE_SCANNING);

    mmi_dtv_player_assign_favorite_service_info();

    if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_CMMB)
    {
    	/* Update EB */
        mmi_dtv_player_check_eb_list();
        if (mmi_dtv_player_is_flag_set(DTV_PLAYER_NEW_ESG_AVAILABLE))
        {
            mmi_dtv_player_enter_esg_download();
            mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_SCANNING);

            mmi_dtv_player_unset_flag(DTV_PLAYER_NEW_ESG_AVAILABLE);
            return; /* Must return */
        }
        else
        {
            mmi_dtv_player_update_esg();
            mmi_dtv_player_reset_to_channel_list_screen();
        }
    }
    else /* MBBMS, MBBMS init or MBBMS ready */
    {
        mmi_dtv_player_update_esg();

        if (need_init)
        {
        #ifdef __MMI_CMMB_PREVIEW_PIC_SUPPORT__
            /* Only for protection */
            mmi_dtv_player_stop_download_preview_data();
        #endif
        #ifndef __MTK_TARGET__
            dtv_player_p->ca_state = MMI_DTV_CA_STATE_MBBMS_FAIL;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_CA_STATE, dtv_player_p->ca_state);
        #else /* __MTK_TARGET__ */

        #ifdef __MBBMS_CITY_LIST__
            if (dtv_player_p->setting.manual_set_loc)
            {
                param = (void *)dtv_player_p->setting.location;
            }
        #endif /* __MBBMS_CITY_LIST__ */

            mdi_mtv_download_service_guide(dtv_player_p->mtv_handle, param);

            dtv_player_p->ca_state = MMI_DTV_CA_STATE_MBBMS_INIT;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_CA_STATE, dtv_player_p->ca_state);
        #endif /* __MTK_TARGET__ */
        }
        else
        {
            if (g_mtv_mts_command)
            {
                /* Let free, encryped channel as subscribed */
                mmi_dtv_player_get_service_flag();
                dtv_player_p->ca_state = MMI_DTV_CA_STATE_MBBMS_FAIL;
            }
            /* Copy local purchase item */
            {
                mdi_mtv_add_favorite(
                    dtv_player_p->mtv_handle, MDI_MTV_FAVO_LOCAL_PURCHASE_ITEM, 0, NULL);
            }
        #ifdef __MMI_CMMB_PREVIEW_PIC_SUPPORT__
            /* Don't let preview data slow down the first encypted channel playing  */
            gui_start_timer(10000, mmi_dtv_player_query_preview_data);
        #endif
            /* Update EB */
            mmi_dtv_player_check_eb_list();
        }

        mmi_dtv_player_reset_to_channel_list_screen();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_service_ready_hdlr
 * DESCRIPTION
 *  mmi_dtv_player_service_ready_hdlr
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_service_ready_hdlr(mdi_mtv_service_info_struct* service_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen;
    mdi_mtv_service_status_struct service_status;
    dtv_player_service_info_struct *info_ptr;
    mdi_mtv_service_type_enum service_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    active_screen = mmi_frm_scrn_get_active_id();
    info_ptr = mmi_dtv_player_get_active_channel_ptr();

    mdi_mtv_service_get_status(dtv_player_p->mtv_handle, &service_status);

    if (service_status.timeshift_available == TRUE)
    {
        dtv_player_p->is_timeshift_enable = MMI_TRUE;
    }
    else
    {
        dtv_player_p->is_timeshift_enable = MMI_FALSE;
    }

    /* ADD THIS TO DELAY 5 SECS TO ENABLE TS FUNCTION */
    dtv_player_p->is_ready_to_ts = MMI_FALSE;

    KERNEL_ENTER_STATE(DTV_KERNEL_READY);

    /* Update service type: original service type in service found hdlr may be wrong */
    service_type = service_info->service_type;

    if (info_ptr->service_type != service_type)
    {
        /* Service type is wrong. MED won't auto play */
        if (PLAYER_STATE_IN(DTV_PLAYER_PLAY))
        {
            if (info_ptr->service_type == MDI_MTV_SERVICE_TYPE_DIGITAL_TV ||
                info_ptr->service_type == MDI_MTV_SERVICE_TYPE_ANALOG_TV)
            {
                /* resume LED patten and let MMI can sleep */
                /* Merging 3 files takes time */
                srv_gpio_play_pattern((srv_gpio_pattern_id_enum)srv_led_pattern_get_bg_pattern(), SRV_GPIO_PATN_PLAY_START);
                srv_backlight_turn_off();
            }
            PLAYER_ENTER_STATE(DTV_PLAYER_STOPPED);
        }
        /* Update service type */
        info_ptr->service_type = service_type;

        /* Reconfigure layer */
        if (active_screen == SCR_ID_DTV_PLAYER_APP)
        {
            /* Reconfig display layer for drawing DAB animation or playing DTV */
            mmi_dtv_player_config_display_layer();
        }

        if (active_screen == SCR_ID_DTV_PLAYER_CHANNEL_LIST)
        {
            mmi_dtv_player_refresh_channel_list();
        }

    }

#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
    if (dtv_player_p->is_timeshift_enable)
    {
        gui_start_timer(MMI_DTV_PLAYER_TS_ENABLE_DURATION, mmi_dtv_player_enable_ts_function);
    }
#endif

#ifdef __MBBMS_INTER__
    if (dtv_player_p->ca_state != MMI_DTV_CA_STATE_CMMB)
    {
        /* Update IMD count when service is ready */
        mmi_dtv_player_update_imd_count();
    }
#endif
    /* Start to update signal when enter READY state */
    mmi_dtv_player_get_and_update_signal();

    if (active_screen == SCR_ID_DTV_PLAYER_APP)
    {
        /* Stop service init animation */
        mmi_dtv_player_stop_hint_animation();

        /* To make TV syncs with LCD, draw hint before play.  */
        mmi_dtv_player_draw_osd();
        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
        if (dtv_player_p->is_timeshift_enable)
        {
            mmi_dtv_player_player_update_cyclic();
        }
        if (PLAYER_STATE_IN(DTV_PLAYER_STOPPED))
        {
            mmi_dtv_player_entry_play();
        }
        else if (PLAYER_STATE_IN(DTV_PLAYER_PAUSE))
        {
            if (RECORDER_STATE_IN(DTV_RECORDER_SAVING))
            {
                mmi_dtv_player_entry_play();
            }
        }
        /* The player is auto play by MED */
        else if (PLAYER_STATE_IN(DTV_PLAYER_PLAY))
        {
            if (info_ptr->service_type == MDI_MTV_SERVICE_TYPE_DIGITAL_RADIO)
            {
                mmi_dtv_player_draw_radio_animation();
            }
        }
        else
        {
            ASSERT(0);
        }

        /* If already fade out, keep all key handler as: mmi_dtv_player_fullscr_osd_show_up */
        if (dtv_player_p->fullscr_osd_opacity != 0)
        {
            mmi_dtv_player_register_key_hdlr();
        }


        if (mmi_dtv_player_is_flag_set(DTV_PLAYER_UNAVAILABLE_IN_CALL))
        {
            mmi_dtv_player_set_hint(
                (CHAR *) GetString((U16)(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL)),
				(CHAR *) NULL,
			    MMI_DTV_PLAYER_HINT_POPUP_NO_FADE,
                MMI_TRUE);

            mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
        }
        else
        {
            mmi_dtv_player_draw_osd();
        }
        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }
    else if (active_screen == SCR_ID_DTV_PLAYER_CHANNEL_LIST)
    {
        if (PLAYER_STATE_IN(DTV_PLAYER_STOPPED))
        {
            mmi_dtv_player_entry_play();
            if (dtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
            {
                mmi_dtv_player_draw_preview_icon(DTV_PLAYER_PREVIEW_ICON_BROKEN);
            }
        }
        /* The player is auto play by MED */
        else if (PLAYER_STATE_IN(DTV_PLAYER_PLAY))
        {
            if (info_ptr->service_type == MDI_MTV_SERVICE_TYPE_DIGITAL_RADIO)
            {
                mmi_dtv_player_draw_radio_animation();
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_system_closed_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_system_closed_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(!KERNEL_STATE_IN(DTV_KERNEL_CLOSING))
    {
        return;
    }

    KERNEL_ENTER_STATE(DTV_KERNEL_CLOSED);

    mmi_dtv_player_free_adm_structure();
    /* Delete adm */
    mmi_dtv_player_delete_adm();

    if (dtv_player_p->app_mem_pool != NULL)
    {
        applib_asm_free_r(GRP_ID_DTV_PLAYER, (void *)dtv_player_p->app_mem_pool);
        dtv_player_p->app_mem_pool = NULL;
    }

    if (dtv_player_p->app_mem_force_release)
    {
        /* Notify MMI that this application is already stopped */
       // applib_mem_ap_notify_stop_finished(
       //     APPLIB_MEM_AP_ID_DTV_PLAYER, KAL_TRUE);
        mmi_frm_app_continue_to_close(APP_DTV_PLAYER);
        dtv_player_p->app_mem_force_release = KAL_FALSE;
    }


    active_screen = mmi_frm_scrn_get_active_id();
    if (active_screen == SCR_ID_DTV_PLAYER_APP_BASE)
    {
        mmi_frm_group_close(GRP_ID_DTV_PLAYER);

        if (!dtv_player_p->go_back_history)
        {
            mmi_frm_close_to_idle_group();
        }
    }
    else if (mmi_frm_scrn_is_present(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_APP_BASE,
                MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_frm_group_close(GRP_ID_DTV_PLAYER);
        if (!dtv_player_p->go_back_history)
        {
            mmi_frm_close_to_idle_group_with_start_id(
                SCR_ID_DTV_PLAYER_APP_BASE);
        }
    }

    if (dtv_player_p->auto_launch)
    {
        mmi_dtv_player_launch();
        dtv_player_p->auto_launch = MMI_FALSE;
        return;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_handle_record_discarded
 * DESCRIPTION
 *
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_handle_record_discarded(void)
{
#ifdef __MMI_DTV_RECORD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_scrn_set_leave_proc(
        GRP_ID_DTV_PLAYER,
        SCR_ID_DTV_PLAYER_DELETING,
        NULL);
    if (dtv_player_p->del_deleting_screen == MMI_TRUE)
    {
        mmi_idle_display();
    }
    else
    {
        /* delete save_confirm and saving screens */
        mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_SAVE_CONFIRM);
        mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_DELETING);
    }
#endif /* __MMI_DTV_RECORD_SUPPORT__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_system_event_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_system_event_hdlr(U32 event_id, S32 param, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event_id == MDI_MTV_SYSTEM_CLOSED)
    {
        mmi_dtv_player_system_closed_hdlr();
    }
#ifdef __MMI_DTV_RECORD_SUPPORT__
    else if(event_id == MDI_MTV_SYSTEM_UNSAVED_RECORDING_DISCARDED)
    {
        if(KERNEL_STATE_IN(DTV_KERNEL_DELETING))
        {
            KERNEL_ENTER_STATE(DTV_KERNEL_OPENED);
            mmi_dtv_player_handle_record_discarded();
        }
    }
#endif /*__MMI_DTV_RECORD_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_service_event_hdlr
 * DESCRIPTION
 *  callback function when save is done
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_service_event_hdlr(U32 event_id, S32 param, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen;
    dtv_player_service_info_struct *info_ptr;
    mdi_mtv_service_type_enum service_type;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    active_screen = mmi_frm_scrn_get_active_id();
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
		      MMI_TRC_DTV_MDI_NOTIFY_INFO, event_id, param);
    /* Service is closed */
    if (KERNEL_STATE_IN(DTV_KERNEL_CLOSED) || KERNEL_STATE_IN(DTV_KERNEL_CLOSING))
    {
        return;
    }

    if (event_id == MDI_MTV_SERVICE_READY)
    {
        StopTimer(DTV_PLAYER_SERVICE_TIMEOUT_TIMER);
        mmi_dtv_player_service_ready_hdlr((mdi_mtv_service_info_struct*)param);
    }
    else if (event_id == MDI_MTV_SERVICE_SG_UPDATE_RET)
    {
        mmi_dtv_player_sg_update_result_hdlr(param);
    }
    else if (event_id == MDI_MTV_SERVICE_GBA_RET ||
             event_id == MDI_MTV_SERVICE_MSK_RETRIEVE_DONE)
    {
        mmi_dtv_player_mbbms_update_hdlr(event_id, param);
    }
#ifdef __MBBMS_UPGRADE__
    else if (event_id == MDI_MTV_SERVICE_UPGRADE_RET)
    {
        mmi_dtv_player_upgrade_result_hdlr(param);
    }
#endif /* __MBBMS_UPGRADE__ */
#ifdef __MBBMS_CITY_LIST__
    else if (event_id == MDI_MTV_SERVICE_AREA_RETRIEVE_RET)
    {
        mmi_dtv_player_area_retrieve_result_hdlr(param);
    }
#endif /* __MBBMS_CITY_LIST__ */
#ifdef __MBBMS_INTER__
    else if (event_id == MDI_MTV_SERVICE_INTERACTIVITY_RETRIEVE_RET)
    {
        mmi_dtv_player_inter_retrieve_result_hdlr(param);
    }
    else if (event_id == MDI_MTV_SERVICE_IMD_READY)
    {
        mmi_dtv_player_imd_ready_hdlr(param);
    }
#endif /* __MBBMS_INTER__ */
    else if (event_id == MDI_MTV_SERVICE_SUBSCRIPTION_RET)
    {
        mmi_dtv_player_subscriptoin_update_result_hdlr(param);
    }
    else if (event_id == MDI_MTV_SERVICE_SUBSCRIBE_DONE)
    {
        mmi_dtv_player_purchase_done_hdlr(event_id, param);
    }
    else if (event_id == MDI_MTV_SERVICE_UNSUBSCRIBE_DONE)
    {
        mmi_dtv_player_purchase_done_hdlr(event_id, param);
    }
    else if (event_id == MDI_MTV_SERVICE_ACCOUNT_INQUIRY_DONE)
    {
        mmi_dtv_player_account_inquiry_done_hdlr(param);
    }
    else if (event_id == MDI_MTV_SERVICE_PROGRAM_INFO)
    {
        ret = mmi_dtv_player_check_and_copy_program_info((mdi_mtv_program_info_struct*)param);
        if (ret == MMI_TRUE)
        {
            mmi_dtv_player_update_program_info();
        }
    }
    else if (event_id == MDI_MTV_SERVICE_EMERGENCY_MSG)
    {
        if (KERNEL_STATE_IN(DTV_KERNEL_SCANNING) || KERNEL_STATE_IN(DTV_KERNEL_ESG_DOWNLOAD))
        {
            mmi_dtv_player_set_flag(DTV_PLAYER_DELAY_UPDATE_EB_MSG);
            return;
        }
        mmi_dtv_player_update_eb_msg();
    }
    else if (event_id == MDI_MTV_SERVICE_ESG_NEW_AVAILABLE)
    {
        mmi_dtv_player_new_esg_available_hdlr();
    }
    else if (event_id == MDI_MTV_SERVICE_ESG_DOWNLOADED)
    {
        /* should only called when at esg downloading state */
        if(!KERNEL_STATE_IN(DTV_KERNEL_ESG_DOWNLOAD))
        {
            return;
        }
        StopTimer(DTV_PLAYER_ESG_TIMEOUT_TIMER);
        StopTimer(DTV_PLAYER_UPDATE_SCAN_STATUS);
        KERNEL_ENTER_STATE(DTV_KERNEL_OPENED);

        mmi_dtv_player_update_scan_progress(100);

        mmi_dtv_player_reset_to_channel_list_screen();
    }
    else if (event_id == MDI_MTV_SERVICE_ESG_UPDATED)
    {
        mmi_dtv_player_update_esg();
    }
#ifdef	__MMI_CMMB_CAS_2GPP_SUPPORT__
    else if(event_id == MDI_MTV_SERVICE_SET_EMM_DONE)/* emm */
    {
        mmi_cmmb_2gpp_adp_notify(EVT_ID_CMMB_2GPP_MMI_EMM_DONE, param, NULL);
    }
    else if(event_id == MDI_MTV_SERVICE_GET_CA_DONE)/* Ca */
    {
        mdi_mtv_ca_info_struct *ca_temp = (mdi_mtv_ca_info_struct*) param;
        kal_prompt_trace(MOD_MMI_MEDIA_APP,"[fyl]mdi get ca info 1. [0x%x|0x%x],", 
                         ca_temp->randvalue[0], ca_temp->randvalue[1]);
        mmi_cmmb_2gpp_adp_notify(EVT_ID_CMMB_2GPP_MMI_CA_DONE, 0, (void*)param);
    }
#endif
    else if (event_id == MDI_MTV_SERVICE_ACCESS_DENIED)
    {
        mmi_dtv_player_service_access_denied_hdlr();
    }
    else if (event_id == MDI_MTV_SERVICE_ACCESS_GRANTED)
    {
        mmi_dtv_player_service_access_granted_hdlr();
    }
    else if (event_id == MDI_MTV_SERVICE_ABORTED ||  /* IO error */
             event_id == MDI_MTV_SERVICE_REMOVED)
    {
        StopTimer(DTV_PLAYER_SERVICE_TIMEOUT_TIMER);

        if (active_screen == SCR_ID_DTV_PLAYER_APP)
        {
            StopTimer(DTV_PLAYER_UPDATE_PLAYER_STATUS);
        }

        info_ptr = mmi_dtv_player_get_active_channel_ptr();

        service_type = info_ptr->service_type;

        if (PLAYER_STATE_IN(DTV_PLAYER_BT_CONNECT))
        {
        #if defined(__MMI_DTV_A2DP_SUPPORT__)
            mmi_dtv_player_disconnect_bt();
        #endif
        }
        else if (PLAYER_STATE_IN(DTV_PLAYER_PLAY))
        {
        #if defined(__MMI_DTV_A2DP_SUPPORT__)
            mmi_dtv_player_bt_close_codec();
            mmi_dtv_player_disconnect_bt();
        #endif

            if (service_type == MDI_MTV_SERVICE_TYPE_DIGITAL_TV ||
                service_type == MDI_MTV_SERVICE_TYPE_ANALOG_TV)
            {
                /* resume LED patten and let MMI can sleep */
                srv_gpio_play_pattern((srv_gpio_pattern_id_enum)srv_led_pattern_get_bg_pattern(), SRV_GPIO_PATN_PLAY_START);
                srv_backlight_turn_off();
            }
            else if (service_type == MDI_MTV_SERVICE_TYPE_DIGITAL_RADIO)
            {
                mmi_dtv_player_stop_radio_animation();
            }
        }

        /* MED has stopped the player */
        PLAYER_ENTER_STATE(DTV_PLAYER_STOPPED);

        if (RECORDER_STATE_IN(DTV_RECORDER_SAVING))
        {
            if (event_id == MDI_MTV_SERVICE_REMOVED)
            {
                mmi_dtv_player_set_flag(DTV_PLAYER_IS_SERVICE_REMOVED);
            }
            else
            {
                mmi_dtv_player_set_flag(DTV_PLAYER_IS_SERVICE_ABORTED);
            }
            /* Stop service when save result indication is received */
            return;
        }

        /* MED has stopped recorder */
        RECORDER_ENTER_STATE(DTV_RECORDER_STOPPED);

        /* MMI needs to stop service  */
        mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);

        if (event_id == MDI_MTV_SERVICE_REMOVED)
        {
            mmi_dtv_player_handle_service_removed();
        }
        else
        {
            mmi_dtv_player_handle_service_aborted();
        #if defined (__MBBMS_CITY_LIST__) && defined(__MTK_TARGET__)
            if (dtv_player_p->ca_state != MMI_DTV_CA_STATE_CMMB)
            {  
            	#ifndef __MBBMS_V30_OPERA__
                /* Don't display this screen in channel list */
                if (active_screen == SCR_ID_DTV_PLAYER_APP)
                {
                    mmi_dtv_player_entry_play_info_screen();
                }
				#endif
            }            
        #endif 
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_player_event_hdlr
 * DESCRIPTION
 *  callback function when any player event ind
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_player_event_hdlr(U32 event_id, S32 param, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen;	
    #ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
    dtv_player_service_info_struct *info_ptr;	
	mdi_mtv_service_type_enum service_type;
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    active_screen = mmi_frm_scrn_get_active_id();

    switch( event_id )
    {
    #ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
        case MDI_MTV_PLAYER_END_OF_CONTENT:
        case MDI_MTV_PLAYER_BEGINNING_OF_CONTENT:
        {
            MMI_BOOL need_to_update_osd = MMI_FALSE;

            if (active_screen == SCR_ID_DTV_PLAYER_APP)
            {
                /* BEGIN_OF_CONTENT: MMI must call play directly */
                if (PLAYER_STATE_IN(DTV_PLAYER_PAUSE))
                {
                    mmi_dtv_player_entry_play();
                    need_to_update_osd = MMI_TRUE;
                }

                if (need_to_update_osd == MMI_TRUE)
                {
                    mmi_dtv_player_draw_osd();
                    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
                }
            }
            break;
        }
        case MDI_MTV_PLAYER_TIMESHIFT_ERROR:
        {
            dtv_player_p->is_timeshift_enable = MMI_FALSE;

            /* check if in mobile tv application */
            if (!mmi_frm_scrn_is_present(
                    GRP_ID_DTV_PLAYER,
                    SCR_ID_DTV_PLAYER_APP_BASE,
                    MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
            {
                return;
            }

            mmi_dtv_player_display_failure_popup(MDI_RES_MTV_ERR_DISC_IO_ERROR);

            break;
        }
        case MDI_MTV_PLAYER_ERROR:
        {
            /**
             * Only when signal is not good, player may try to restart it by itself, if restart fail, it will send an indication to MMI.
             * when this happens, MED mtv player will in stopped state, so we need to update player's state also.
             **/
            info_ptr = mmi_dtv_player_get_active_channel_ptr();


            service_type = info_ptr->service_type;

            if (PLAYER_STATE_IN(DTV_PLAYER_PLAY))
            {
                if (service_type == MDI_MTV_SERVICE_TYPE_DIGITAL_TV ||
                    service_type == MDI_MTV_SERVICE_TYPE_ANALOG_TV)
                {
                    /* resume LED patten and let MMI can sleep */
                    srv_gpio_play_pattern((srv_gpio_pattern_id_enum)srv_led_pattern_get_bg_pattern(), SRV_GPIO_PATN_PLAY_START);
                    srv_backlight_turn_off();
                }
                else if (service_type == MDI_MTV_SERVICE_TYPE_DIGITAL_RADIO)
                {
                    mmi_dtv_player_stop_radio_animation();
                }
            #if defined(__MMI_DTV_A2DP_SUPPORT__)
                mmi_dtv_player_bt_close_codec();
                mmi_dtv_player_disconnect_bt();
            #endif
            }

            PLAYER_ENTER_STATE(DTV_PLAYER_STOPPED);

            dtv_player_p->is_ready_to_ts = MMI_FALSE;
            dtv_player_p->max_timeshift_delay = 0;
            dtv_player_p->play_delay = 0;
            dtv_player_p->max_delay = 0;
            if (dtv_player_p->is_timeshift_enable)
            {
                gui_start_timer(MMI_DTV_PLAYER_TS_ENABLE_DURATION, mmi_dtv_player_enable_ts_function);
            }
            //check if it is on mobile tv application screen
            if (active_screen != SCR_ID_DTV_PLAYER_APP)
            {
                return;
            }

            /* display popup callback */
            mmi_dtv_player_display_failure_popup(param);
            break;
        }
    #endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */
        case MDI_MTV_PLAYER_DYNAMIC_LABEL:
        {
            if (mmi_ucs2cmp((CHAR *)dtv_player_p->label_str,(CHAR *)param) == 0)
            {
                return;
            }
            mmi_ucs2ncpy((CHAR *)dtv_player_p->label_str,(CHAR *)param, MMI_DTV_TEXT_STR_LENGTH);

            if (active_screen == SCR_ID_DTV_PLAYER_APP)
            {
                if (mmi_ucs2strlen((CHAR *)dtv_player_p->label_str) != 0)
                {
                    mmi_dtv_player_draw_dynamic_label();
                }
            }

            break;
        }
        case MDI_MTV_PLAYER_STOPPED:
        {
            /* If player stopped cause access denied. don't display bad reception */
            if (mmi_dtv_player_is_flag_set(DTV_PLAYER_ACCESS_DENIED) == MMI_TRUE ||
                IsMyTimerExist(DTV_PLAYER_DISPLAY_ACCESS_DENIED_TIMER))
            {
                return;
            }

            /* Bad reception */
            if (param == MDI_RES_MTV_ERR_VIDEO_ERROR &&
                PLAYER_STATE_IN(DTV_PLAYER_PLAY))
            {
                mmi_dtv_player_set_flag(DTV_PLAYER_BAD_RECEPTION);

                if (active_screen == SCR_ID_DTV_PLAYER_APP)
                {
                    mmi_dtv_player_set_hint(
                        (CHAR *) GetString((U16) (STR_ID_DTV_PLAYER_SERVICE_IS_NOT_AVAILABLE)),
    					(CHAR *) NULL,
    				    MMI_DTV_PLAYER_HINT_POPUP_NO_FADE,
                        MMI_TRUE);

                    /* When all fade out, all key handler is mmi_dtv_player_fullscr_osd_show_up */
                    mmi_dtv_player_register_key_hdlr();
                    mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
                    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
                }
            }
            break;
        }
        case MDI_MTV_PLAYER_STARTED:
        {
            /* Unset bad reception */
            if (mmi_dtv_player_is_flag_set(DTV_PLAYER_BAD_RECEPTION))
            {
                mmi_dtv_player_unset_flag(DTV_PLAYER_BAD_RECEPTION);
                if (active_screen == SCR_ID_DTV_PLAYER_APP)
                {
                    mmi_dtv_player_hide_hint();                    
                    mmi_dtv_player_set_hint(
                        (CHAR *) GetString((U16) (STR_ID_DTV_PLAYER_RECOVERY)),
    					(CHAR *) NULL,
    				    MMI_DTV_PLAYER_HINT_POPUP_FADE_TIME,
                        MMI_TRUE);
                    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
                    {
                        mmi_dtv_player_fullscr_reset_osd_fade(MMI_TRUE);
                        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
                    }
					else
					{						
                        mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
                        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
					}
                }
            }

            if (!mmi_dtv_player_is_flag_set(DTV_PLAYER_PLAYER_STARTED))
            {
                /* For snapshot icon */
                mmi_dtv_player_set_flag(DTV_PLAYER_PLAYER_STARTED);

                if (active_screen == SCR_ID_DTV_PLAYER_APP)
                {
                    if (dtv_player_p->fullscr_osd_opacity != 0)
                    {
                        /* For snapshot icon */
                        mmi_dtv_player_register_key_hdlr();
                        mmi_dtv_player_draw_osd();
                        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
                    }
                }
            }

			#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
				if (active_screen == SCR_ID_DTV_PLAYER_APP)
			    {
			    	kal_prompt_trace(MOD_MMI, "MMI_MTV Yaling hide hint for play sucessed");
					mmi_dtv_player_hide_hint();
					 if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
                    {
                        mmi_dtv_player_fullscr_reset_osd_fade(MMI_TRUE);
                        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
                    }
					else
					{						
                        mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
                        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
					}
				}
			#endif
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_recorder_event_hdlr
 * DESCRIPTION
 *  callback function when any recorder event ind
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_recorder_event_hdlr(U32 event_id, S32 param, void *user_data)
{
#ifdef __MMI_DTV_RECORD_SUPPORT__
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

        RECORDER_ENTER_STATE(DTV_RECORDER_STOPPED);

        dtv_player_p->active_osd_cntx_p->channel_next.status = DTV_PLAYER_ICON_STATUS_ENABLE;
        dtv_player_p->active_osd_cntx_p->channel_prev.status = DTV_PLAYER_ICON_STATUS_ENABLE;

        dtv_player_p->is_ready_to_ts = MMI_FALSE;

        if (mmi_frm_scrn_is_present(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_APP_BASE,
                MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
        #ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
            gui_start_timer(MMI_DTV_PLAYER_TS_ENABLE_DURATION, mmi_dtv_player_enable_ts_function);
        #endif
            /* Follow the design in record_icon_release */
            if (!PLAYER_STATE_IN(DTV_PLAYER_STOPPED))
            {
                mmi_dtv_player_player_enter_state(DTV_PLAYER_STOPPED);
            }

            /* Including incoming call and outgoing call */
            if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||
                srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
            {
                mmi_dtv_player_set_flag(DTV_PLAYER_DELAY_DISPLAY_RECORD_ERROR);
            }

            if (!mmi_dtv_player_is_flag_set(DTV_PLAYER_DELAY_DISPLAY_RECORD_ERROR))
            {
                RECORDER_ENTER_STATE(DTV_RECORDER_SAVE_CONFIRM);
                if (!mmi_frm_scrn_enter(
                        GRP_ID_DTV_PLAYER,
                        SCR_ID_DTV_PLAYER_DUMMY,
                        NULL,
                        mmi_dtv_player_enter_save_confirm,
                        MMI_FRM_UNKNOW_SCRN))
                {
                    return;
                }
                ShowCategoryDummyScreen();
            }

            /* When record error, always delete screen upto Main screen or channel list */
            if (mmi_frm_scrn_is_present(
                    GRP_ID_DTV_PLAYER,
                    SCR_ID_DTV_PLAYER_APP,
                    MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
            {
                mmi_frm_scrn_multiple_close(
                    GRP_ID_DTV_PLAYER,
                    mmi_frm_scrn_get_active_id(),
                    0,
                    0,
                    SCR_ID_DTV_PLAYER_APP,
                    0);
            }
            else if (mmi_frm_scrn_is_present(
                        GRP_ID_DTV_PLAYER,
                        SCR_ID_DTV_PLAYER_CHANNEL_LIST,
                        MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
            {
                mmi_frm_scrn_multiple_close(
                    GRP_ID_DTV_PLAYER,
                    mmi_frm_scrn_get_active_id(),
                    0,
                    0,
                    SCR_ID_DTV_PLAYER_CHANNEL_LIST,
                    0);
            }

            if (!mmi_dtv_player_is_flag_set(DTV_PLAYER_DELAY_DISPLAY_RECORD_ERROR))
            {
                mmi_dtv_player_display_failure_popup(param);
            }
            else
            {
                /* Save the error */
                dtv_player_p->delayed_record_error = param;

            }

        }
        else
        {
            mmi_dtv_player_display_popup(
                STR_ID_DTV_PLAYER_NOTIFY_RECORDER_STOPPED,
                MMI_EVENT_FAILURE);

            /* Terminate application */
            mmi_dtv_player_terminate_app();
        }

    }
    else if (event_id == MDI_MTV_RECORDER_SAVING_SUCCEEDED ||
             event_id == MDI_MTV_RECORDER_SAVING_FAILED)
    {
        /* Only display pop up on the SAVING screen */
        if (active_screen == SCR_ID_DTV_PLAYER_SAVING)
        {
            if (event_id == MDI_MTV_RECORDER_SAVING_SUCCEEDED)
            {
                mmi_dtv_player_display_popup(STR_GLOBAL_SAVED, MMI_EVENT_SUCCESS);
            }
            else if (event_id == MDI_MTV_RECORDER_SAVING_FAILED)
            {
                mmi_dtv_player_display_popup(STR_GLOBAL_FAILED_TO_SAVE, MMI_EVENT_FAILURE);
            }
        }

        RECORDER_ENTER_STATE(DTV_RECORDER_STOPPED);

        /* delete save_confirm and saving screens */
        mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_SAVE_CONFIRM);
        mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_SAVING);

        if (!mmi_frm_scrn_is_present(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_APP_BASE,
                MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
            /* display popup callback */
            mmi_dtv_player_display_popup(
                STR_ID_DTV_PLAYER_NOTIFY_SAVING_FAIL,
                MMI_EVENT_FAILURE);

            mmi_dtv_player_terminate_app();
        }
        else
        {
            /* Service has been stopped. Delay stop service after save is done */
            if (mmi_dtv_player_is_flag_set(DTV_PLAYER_IS_SERVICE_ABORTED))
            {
                mmi_dtv_player_unset_flag(DTV_PLAYER_IS_SERVICE_ABORTED);
                mmi_dtv_player_service_event_hdlr(MDI_MTV_SERVICE_ABORTED, 0, NULL);
            }
            else if (mmi_dtv_player_is_flag_set(DTV_PLAYER_IS_SERVICE_REMOVED))
            {
                mmi_dtv_player_unset_flag(DTV_PLAYER_IS_SERVICE_REMOVED);
                mmi_dtv_player_service_event_hdlr(MDI_MTV_SERVICE_REMOVED, 0, NULL);
            }
        }
    }
    else if (event_id == MDI_MTV_RECORDER_RECORDING_DISCARDED)
    {
        if(RECORDER_STATE_IN(DTV_RECORDER_DELETING))
        {
            RECORDER_ENTER_STATE(DTV_RECORDER_STOPPED);;
            mmi_dtv_player_handle_record_discarded();
        }
    }
#endif /* __MMI_DTV_RECORD_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_complete_recovering_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_complete_recovering_hdlr(S32 result, void *user_data)
{
#ifdef __MMI_DTV_RECORD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    active_screen_id = mmi_frm_scrn_get_active_id();

    if (!KERNEL_STATE_IN(DTV_KERNEL_SAVING))
    {
        return;
    }

    /* Only display pop up on the SAVING screen */
    if (active_screen_id == SCR_ID_DTV_PLAYER_SAVING)
    {
        if (result >= 0)
        {
            mmi_dtv_player_display_popup(STR_GLOBAL_SAVED, MMI_EVENT_SUCCESS);
        }
        else if (result == MDI_RES_MTV_ERR_DISC_FULL)
        {
            mmi_dtv_player_display_failure_popup(result);
        }
        else
        {
            mmi_dtv_player_display_popup(STR_GLOBAL_FAILED_TO_SAVE, MMI_EVENT_FAILURE);
        }
    }

    KERNEL_ENTER_STATE(DTV_KERNEL_OPENED);

    /* delete save_confirm and saving screens */
    mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_SAVE_CONFIRM);
    mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_SAVING);
#endif /* __MMI_DTV_RECORD_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_check_and_display_delayed_record_error
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_check_and_display_delayed_record_error(void)
{
#ifdef __MMI_DTV_RECORD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_dtv_player_is_flag_set(DTV_PLAYER_DELAY_DISPLAY_RECORD_ERROR))
    {
        RECORDER_ENTER_STATE(DTV_RECORDER_SAVE_CONFIRM);
        if (!mmi_frm_scrn_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_DUMMY,
                NULL,
                mmi_dtv_player_enter_save_confirm,
                MMI_FRM_UNKNOW_SCRN))
        {
            return;
        }
        ShowCategoryDummyScreen();

        mmi_dtv_player_display_failure_popup(dtv_player_p->delayed_record_error);

        mmi_dtv_player_unset_flag(DTV_PLAYER_DELAY_DISPLAY_RECORD_ERROR);
    }
#endif /* __MMI_DTV_RECORD_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_handle_play_fail
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
void mmi_dtv_player_handle_play_fail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dtv_player_service_info_struct *info_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info_ptr = mmi_dtv_player_get_active_channel_ptr();

#if defined(__MMI_DTV_A2DP_SUPPORT__)
    mmi_dtv_player_bt_close_codec();
#endif /* __MMI_DTV_A2DP_SUPPORT__ */

    if (info_ptr->service_type == MDI_MTV_SERVICE_TYPE_DIGITAL_TV ||
        info_ptr->service_type == MDI_MTV_SERVICE_TYPE_ANALOG_TV)
    {
        /* resume LED patten and let MMI can sleep */
        srv_gpio_play_pattern((srv_gpio_pattern_id_enum)srv_led_pattern_get_bg_pattern(), SRV_GPIO_PATN_PLAY_START);
        srv_backlight_turn_off();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_open_engine
 * DESCRIPTION
 *  open mtv engine
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_open_engine(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_mtv_setting_struct mtv_setting;
    mdi_mtv_service_config_struct mtv_service_config;
    mdi_mtv_cas_sim_struct sim;
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mtv_setting.brightness = dtv_player_p->setting.brightness;
    mtv_setting.contrast = dtv_player_p->setting.contrast;
    mtv_setting.saturation = dtv_player_p->setting.saturation;
    mtv_setting.volume_level = dtv_player_p->setting.vol_level;
    mtv_setting.record_size = dtv_player_p->setting.record_size;
#if defined (__MDI_DTV_TIME_SHIFT_SUPPORT__)
    if (dtv_player_p->storage_status == DTV_PLAYER_STORAGE_OK)
    {
        mtv_setting.record_dir = (PU8)dtv_player_p->storage_filepath;
        mtv_setting.is_timeshift_enabled = dtv_player_p->is_timeshift_enable = MMI_TRUE;
        mmi_dtv_player_enable_timeshift_function();
    }
    else
#elif (defined(__MMI_DTV_RECORD_SUPPORT__) || defined(__MMI_DTV_SNAPSHOT_SUPPORT__))
    if (dtv_player_p->storage_status == DTV_PLAYER_STORAGE_OK)
    {
        mtv_setting.record_dir = (PU8)dtv_player_p->storage_filepath;
        mtv_setting.is_timeshift_enabled = dtv_player_p->is_timeshift_enable = MMI_FALSE;
        mmi_dtv_player_disable_timeshift_function();
    }
    else
#endif /* __MMI_DTV_RECORD_SUPPORT__ */
    {
        mtv_setting.record_dir = 0;
        mtv_setting.is_timeshift_enabled = dtv_player_p->is_timeshift_enable = MMI_FALSE;
        mmi_dtv_player_disable_timeshift_function();
    }

    mtv_service_config.complete_recovering_hdlr = mmi_dtv_player_complete_recovering_hdlr;
    mtv_service_config.search_progress_hdlr = mmi_dtv_player_search_progress_hdlr;
    mtv_service_config.service_found_hdlr = mmi_dtv_player_service_found_hdlr;
    mtv_service_config.system_event_hdlr = mmi_dtv_player_system_event_hdlr;
    mtv_service_config.service_event_hdlr = mmi_dtv_player_service_event_hdlr;
    mtv_service_config.recorder_event_hdlr = mmi_dtv_player_recorder_event_hdlr;
    mtv_service_config.player_event_hdlr = mmi_dtv_player_player_event_hdlr;
    mtv_service_config.user_data = NULL;
    mtv_service_config.account_inquiry_hdlr = mmi_dtv_player_account_inquiry_hdlr;
#ifdef __MBBMS_CITY_LIST__
    mtv_service_config.city_found_hdlr = mmi_dtv_player_city_found_hdlr;
#endif

	/*  CMMB_2GPP confict with MBBMS  */
#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__	
	ret = MMI_FALSE;
#else
    ret = mmi_dtv_cas_get_sim_struct(&sim);
#endif

    if (ret == MMI_TRUE)
    {
        mtv_setting.sim = &sim;
        dtv_player_p->ca_state = MMI_DTV_CA_STATE_MBBMS;
        mmi_dtv_player_unset_flag(DTV_PLAYER_DISPLAY_CMMB_MODE_CONFIRM);
        /* Init data account */
        mmi_dtv_player_cl_setting_init(MMI_TRUE);
    }
    else
    {
        mtv_setting.sim = NULL;
        dtv_player_p->ca_state = MMI_DTV_CA_STATE_CMMB;
#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
		mmi_dtv_player_unset_flag(DTV_PLAYER_DISPLAY_CMMB_MODE_CONFIRM);
#else
        mmi_dtv_player_set_flag(DTV_PLAYER_DISPLAY_CMMB_MODE_CONFIRM);
#endif
        mmi_dtv_player_cl_setting_init(MMI_FALSE);
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_CA_STATE, dtv_player_p->ca_state);

    return mdi_mtv_open(GRP_ID_DTV_PLAYER,
                        &dtv_player_p->mtv_handle,
                        &mtv_setting,
                        &mtv_service_config);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_enter_next_state
 * DESCRIPTION
 *  enter state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_enter_next_state(mmi_dtv_player_module_enum module)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (module == MMI_DTV_KERNEL)
    {
        switch (dtv_player_p->kernel_next_state)
        {
            case DTV_KERNEL_CLOSING:
                ret = mmi_dtv_player_kernel_entry_closing_state();
                break;
        #ifdef __MMI_DTV_RECORD_SUPPORT__
            case DTV_KERNEL_SAVING:
                ret = mmi_dtv_player_kernel_entry_saving_state();
                break;
            case DTV_KERNEL_DELETING:
                ret = mmi_dtv_player_kernel_entry_deleting_state();
                break;
        #endif /* __MMI_DTV_RECORD_SUPPORT__  */
            case DTV_KERNEL_ESG_DOWNLOAD:
                ret = mmi_dtv_player_kernel_entry_esg_download_state();
                break;
            case DTV_KERNEL_SUB_UPDATING:
                ret = mmi_dtv_player_kernel_entry_sub_updating_state();
                break;
            case DTV_KERNEL_PROCESS:
                ret = mmi_dtv_player_kernel_entry_process_state();
                break;
            case DTV_KERNEL_SCANNING:
                ret = mmi_dtv_player_kernel_entry_scanning_state();
                break;
            case DTV_KERNEL_OPENED:
                ret = mmi_dtv_player_kernel_entry_opened_state();
                break;
            case DTV_KERNEL_INIT:
                ret = mmi_dtv_player_kernel_entry_init_state();
                break;
            case DTV_KERNEL_READY:
                ret = mmi_dtv_player_kernel_entry_ready_state();
                break;
            default:
                break;

        }
    }
    else if (module == MMI_DTV_PLAYER)
    {
        switch (dtv_player_p->player_next_state)
        {
            case DTV_PLAYER_STOPPED:
                ret = mmi_dtv_player_player_entry_stopped_state();
                break;
            case DTV_PLAYER_PLAY:
                ret = mmi_dtv_player_player_entry_play_state();
                break;
        #ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
            case DTV_PLAYER_PAUSE:
                ret = mmi_dtv_player_player_entry_pause_state();
                break;
        #endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */
		#ifdef __MMI_DTV_A2DP_SUPPORT__
            case DTV_PLAYER_BT_CONNECT:
				{
                	ret = mmi_dtv_player_player_entry_bt_connect_state();
                	break;
            	}	
		#endif /* __MMI_DTV_A2DP_SUPPORT__ */	
        }
    }
    else if (module == MMI_DTV_RECORDER)
    {
    #ifdef __MMI_DTV_RECORD_SUPPORT__
        switch (dtv_player_p->recorder_next_state)
        {
            case DTV_RECORDER_STOPPED:
                ret = mmi_dtv_player_recorder_entry_stopped_state();
                break;
            case DTV_RECORDER_RECORD:
                ret = mmi_dtv_player_recorder_entry_record_state();
                break;
            case DTV_RECORDER_SAVE_CONFIRM:
                ret = mmi_dtv_player_recorder_entry_save_confirm_state();
                break;
            case DTV_RECORDER_SAVING:
                ret = mmi_dtv_player_recorder_entry_saving_state();
                break;
            case DTV_RECORDER_DELETING:
                ret = mmi_dtv_player_recorder_entry_deleting_state();
        }
    #endif /* #ifdef __MMI_DTV_RECORD_SUPPORT__  */
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_exit_current_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_exit_current_state(mmi_dtv_player_module_enum module)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (module == MMI_DTV_KERNEL)
    {
        switch (dtv_player_p->kernel_state)
        {
            case DTV_KERNEL_CLOSING:
                ret = mmi_dtv_player_kernel_exit_closing_state();
                break;
        #ifdef __MMI_DTV_RECORD_SUPPORT__
            case DTV_KERNEL_SAVING:
                ret = mmi_dtv_player_kernel_exit_saving_state();
                break;
            case DTV_KERNEL_DELETING:
                ret = mmi_dtv_player_kernel_exit_deleting_state();
                break;
        #endif /* __MMI_DTV_RECORD_SUPPORT__ */
            case DTV_KERNEL_SCANNING:
                ret = mmi_dtv_player_kernel_exit_scanning_state();
                break;
            case DTV_KERNEL_ESG_DOWNLOAD:
                ret = mmi_dtv_player_kernel_exit_esg_download_state();
                break;
            case DTV_KERNEL_PROCESS:
                ret = mmi_dtv_player_kernel_exit_process_state();
                break;
            case DTV_KERNEL_SUB_UPDATING:
                ret = mmi_dtv_player_kernel_exit_sub_updating_state();
                break;
            case DTV_KERNEL_OPENED:
                ret = mmi_dtv_player_kernel_exit_opened_state();
                break;
            case DTV_KERNEL_INIT:
                ret = mmi_dtv_player_kernel_exit_init_state();
                break;
            case DTV_KERNEL_READY:
                ret = mmi_dtv_player_kernel_exit_ready_state();
                break;
            default:
                break;
        }
    }
    else if (module == MMI_DTV_PLAYER)
    {
        switch (dtv_player_p->player_state)
        {
            case DTV_PLAYER_STOPPED:
                ret = mmi_dtv_player_player_exit_stopped_state();
                break;
            case DTV_PLAYER_PLAY:
                ret = mmi_dtv_player_player_exit_play_state();
                break;
        #ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
            case DTV_PLAYER_PAUSE:
                ret = mmi_dtv_player_player_exit_pause_state();
                break;
        #endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */
            case DTV_PLAYER_BT_CONNECT:
                ret = mmi_dtv_player_player_exit_bt_connect_state();
                break;
        }
    }
    else if (module == MMI_DTV_RECORDER)
    {
    #ifdef __MMI_DTV_RECORD_SUPPORT__
        switch (dtv_player_p->recorder_state)
        {
            case DTV_RECORDER_STOPPED:
                ret = mmi_dtv_player_recorder_exit_stopped_state();
                break;
            case DTV_RECORDER_RECORD:
                ret = mmi_dtv_player_recorder_exit_record_state();
                break;
            case DTV_RECORDER_SAVE_CONFIRM:
                ret = mmi_dtv_player_recorder_exit_save_confirm_state();
                break;
            case DTV_RECORDER_SAVING:
                ret = mmi_dtv_player_recorder_exit_saving_state();
                break;
            case DTV_RECORDER_DELETING:
                ret = mmi_dtv_player_recorder_exit_deleting_state();
                break;
        }
    #endif /* __MMI_DTV_RECORD_SUPPORT__ */
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_player_prepare_player_setting
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_player_prepare_player_setting(mdi_mtv_player_setting_struct *video_setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen_id = mmi_frm_scrn_get_active_id();
    dtv_player_service_info_struct *info_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    info_ptr = mmi_dtv_player_get_active_channel_ptr();
    if (active_screen_id == SCR_ID_DTV_PLAYER_APP)
    {
        if (info_ptr->service_type == MDI_MTV_SERVICE_TYPE_DIGITAL_TV ||
            info_ptr->service_type == MDI_MTV_SERVICE_TYPE_ANALOG_TV)
        {
            video_setting->is_visual_update = MMI_TRUE;
            video_setting->play_layer_handle = dtv_player_p->display_layer_handle;
            
            video_setting->blt_layer_flag = dtv_player_p->blt_layer_flag;
            
            video_setting->play_layer_flag = GDI_LAYER_ENABLE_LAYER_0;

        }
        else
        {
            video_setting->play_layer_handle = GDI_NULL_HANDLE;
            video_setting->blt_layer_flag = 0;
            video_setting->play_layer_flag = 0;
            video_setting->is_visual_update = MMI_FALSE;
        }
        
        video_setting->rotate = MDI_MTV_LCD_ROTATE_0;
    }
    else
    {    
        if (info_ptr->service_type == MDI_MTV_SERVICE_TYPE_DIGITAL_TV ||
            info_ptr->service_type == MDI_MTV_SERVICE_TYPE_ANALOG_TV)
        {
            video_setting->play_layer_handle = dtv_player_p->cl_preview_layer_handle;
            video_setting->blt_layer_flag = dtv_player_p->cl_blt_layer_flag;
            video_setting->play_layer_flag = dtv_player_p->cl_preview_layer_flag;
        }
        else
        {
            video_setting->play_layer_handle = GDI_NULL_HANDLE;
            video_setting->blt_layer_flag = 0;
            video_setting->play_layer_flag = 0;
        }

        video_setting->is_visual_update = MMI_TRUE;
        video_setting->rotate = MDI_MTV_LCD_ROTATE_0;
    }

    video_setting->play_audio = KAL_TRUE;
#if !defined(__MMI_DTV_BLOCK_BG_CALL__)
    if (mmi_dtv_player_is_in_background_call())
    {
        video_setting->play_audio = KAL_FALSE;
    }
#endif

    /* Set color format */
#ifdef __MDI_DISPLAY_YUYV422_SUPPORT__
    if (video_setting->play_layer_handle != GDI_NULL_HANDLE)
    {
        mdi_util_hw_layer_switch_to_sw_layer(video_setting->play_layer_handle);
        gdi_layer_push_and_set_active(video_setting->play_layer_handle);
        if (info_ptr->service_type == MDI_MTV_SERVICE_TYPE_DIGITAL_TV ||
            info_ptr->service_type == MDI_MTV_SERVICE_TYPE_ANALOG_TV)
        {
            gdi_layer_set_color_format(GDI_COLOR_FORMAT_UYVY422);
        }
        else
        {
            gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
        }
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
#endif /* __MDI_DISPLAY_YUYV422_SUPPORT__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_kernel_entry_closing_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_kernel_entry_closing_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
		mmi_cmmb_2gpp_adp_notify(EVT_ID_CMMB_2GPP_MMI_STOP, 0, NULL);
#endif

	
    if (!PLAYER_STATE_IN(DTV_PLAYER_STOPPED))
        mmi_dtv_player_player_enter_state(DTV_PLAYER_STOPPED);

    if (!RECORDER_STATE_IN(DTV_RECORDER_STOPPED))
    {
        mmi_dtv_player_recorder_enter_state(DTV_RECORDER_STOPPED);
    }

	#ifdef __MBBMS_V30_OPERA__
	mmi_dtv_player_opera_engine_stop();
	#else
    dtv_player_p->last_error = mdi_mtv_close(dtv_player_p->mtv_handle);
	#endif

    /* Reset dynamic label string and clear layer */
    if (dtv_player_p->dynamic_label_state != DTV_PLAYER_DYNAMIC_LABEL_OFF)
    {
        mmi_dtv_player_clear_dynamic_label();
    }
#ifdef __MBBMS_INTER__
	if (dtv_player_p->dynamic_inter_state != DTV_PLAYER_DYNAMIC_LABEL_OFF)
	{
        mmi_dtv_player_clear_description();
	}
#endif	
    mmi_ucs2cpy((CHAR *)dtv_player_p->label_str,(CHAR *)L"");

#ifdef __MMI_CMMB_PREVIEW_PIC_SUPPORT__
    mmi_dtv_player_stop_download_preview_data();
#endif
    mmi_dtv_player_cl_setting_deinit();



    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_kernel_exit_closing_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_kernel_exit_closing_state(void)
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
 *  mmi_dtv_player_kernel_entry_scanning_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_kernel_entry_scanning_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 band;
    void *param = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef  __MMI_DTV_BLOCK_BG_CALL__
    if (mmi_dtv_player_is_in_background_call())
    {
        dtv_player_p->last_error = MDI_RES_MTV_FAILED;
        return dtv_player_p->last_error;
    }
#endif /* __MMI_DTV_BLOCK_BG_CALL__ */

#ifdef __MBBMS_UPGRADE__
    /* Initialize parameter */
    dtv_player_p->upgrade_type = MDI_RES_MTV_UPGRADE_NONE;
#endif /* __MBBMS_UPGRADE__ */

#ifdef __MMI_CMMB_PREVIEW_PIC_SUPPORT__
    /* Stop download preview data */
    mmi_dtv_player_stop_download_preview_data();
#endif
    band = MDI_MTV_CMMB_U_BAND;
    if (dtv_player_p->ca_state != MMI_DTV_CA_STATE_CMMB)
    {
        if (dtv_player_p->update_approach == DTV_PLAYER_UPDATE_SPECIFY_CITY)
        {
            param = (void *)dtv_player_p->city;
        }
    #ifdef __MBBMS_CITY_LIST__
        else if (mmi_dtv_player_is_city_screen_presented())
        {
            param = (void *)dtv_player_p->selected_city[dtv_player_p->city_list_type].name;
        }
        else if (dtv_player_p->setting.manual_set_loc)
        {            
            param = (void *)dtv_player_p->setting.location;            
        }
    #endif /* __MBBMS_CITY_LIST__ */
    }

    if (dtv_player_p->setting.is_channel_list_init == MMI_FALSE)
    {
        /* Reset before scan on air */
        dtv_player_p->has_esg_info = MMI_TRUE;

        dtv_player_p->last_error = mdi_mtv_scan_services(
                                        dtv_player_p->mtv_handle,
                                        MDI_MTV_SOURCE_LIVE_SIGNAL,
                                        band,
                                        param);
        if (dtv_player_p->last_error == MDI_RES_MTV_SUCCEED)
        {
           mmi_dtv_player_set_flag(DTV_PLAYER_IS_LIVE_SCANNING);
        }
    }
    else
    {
        dtv_player_p->last_error = mdi_mtv_scan_services(
                                        dtv_player_p->mtv_handle,
                                        MDI_MTV_SOURCE_LOCAL_DATABASE,
                                        band,
                                        0);

        if (dtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
        {
            dtv_player_p->setting.is_channel_list_init = MMI_FALSE;
            /* Reset before scan on air */
            dtv_player_p->has_esg_info = MMI_FALSE;

            dtv_player_p->last_error = mdi_mtv_scan_services(
                                        dtv_player_p->mtv_handle,
                                        MDI_MTV_SOURCE_LIVE_SIGNAL,
                                        band,
                                        param);
            if (dtv_player_p->last_error == MDI_RES_MTV_SUCCEED)
            {
               mmi_dtv_player_set_flag(DTV_PLAYER_IS_LIVE_SCANNING);
            }
        }
        else
        {
            mmi_dtv_player_unset_flag(DTV_PLAYER_IS_LIVE_SCANNING);
        }
    }

#ifdef __MBBMS_CITY_LIST__
    if (dtv_player_p->last_error == MDI_RES_MTV_SUCCEED)
    {
        mmi_dtv_player_allocate_city_mem();
    }
#endif /* __MBBMS_CITY_LIST__ */

    return dtv_player_p->last_error;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_kernel_exit_scanning_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_kernel_exit_scanning_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (KERNEL_STATE_IN(DTV_KERNEL_SCANNING))
    {
        ret = mdi_mtv_abort_scan_services(dtv_player_p->mtv_handle);
        StopTimer(DTV_PLAYER_UPDATE_SCAN_STATUS);

        ASSERT(ret == MDI_RES_MTV_SUCCEED);
    }
    else
        ret = MDI_RES_MTV_SUCCEED;

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_kernel_entry_opened_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_kernel_entry_opened_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dtv_player_p->kernel_state == DTV_KERNEL_CLOSED)
    {
        MDI_RESULT ret = mmi_dtv_player_open_engine();
        return ret;
    }
    else
        return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_kernel_exit_opened_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_kernel_exit_opened_state(void)
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
 *  mmi_dtv_player_kernel_entry_init_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_kernel_entry_init_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dtv_player_service_info_struct *info_ptr;
    mdi_mtv_player_setting_struct video_setting = {0};
    U16 active_screen = mmi_frm_scrn_get_active_id();
#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
    cmmb_2gpp_event_switch_struct switch_info;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef  __MMI_DTV_BLOCK_BG_CALL__
    if (mmi_dtv_player_is_in_background_call())
    {
        mmi_dtv_player_set_flag(DTV_PLAYER_UNAVAILABLE_IN_CALL);
        dtv_player_p->last_error = MDI_RES_MTV_FAILED;
        return dtv_player_p->last_error;
    }
#endif /* __MMI_DTV_BLOCK_BG_CALL__ */

    info_ptr = mmi_dtv_player_get_active_channel_ptr();

    if (active_screen == SCR_ID_DTV_PLAYER_APP)
    {
        /* Reconfig display layer for drawing DAB animation or playing DTV */
        mmi_dtv_player_config_display_layer();
    }

    mmi_dtv_player_unset_flag(DTV_PLAYER_BAD_RECEPTION);
    mmi_dtv_player_unset_flag(DTV_PLAYER_SERVICE_UNAVAILABLE);
    mmi_dtv_player_unset_flag(DTV_PLAYER_ACCESS_DENIED);
    mmi_dtv_player_unset_flag(DTV_PLAYER_DISBLE_AUTO_PLAY);
    StopTimer(DTV_PLAYER_DISPLAY_ACCESS_DENIED_TIMER);

#if defined(__MMI_DTV_A2DP_SUPPORT__)
    if (mmi_dtv_player_is_output_to_bt())
    {
        /* Do not Auto play */
        dtv_player_p->last_error = mdi_mtv_start_service(
                                        dtv_player_p->mtv_handle,
                                        info_ptr->service_id,
                                        info_ptr->service_type,
                                        MMI_FALSE,
                                        NULL);
        if (dtv_player_p->last_error == MDI_RES_MTV_SUCCEED)
        {
            StartTimer(
                DTV_PLAYER_SERVICE_TIMEOUT_TIMER,
                MMI_DTV_PLAYER_SERVICE_TIMEOUT_DURATION,
                mmi_dtv_player_service_timeout_hdlr);
        }
    }
    else
#endif
    {
        mmi_dtv_player_player_prepare_player_setting(&video_setting);
        /* Auto play */


        /* stop MMI sleep and stop LED pattern beofore play */
        if (info_ptr->service_type == MDI_MTV_SERVICE_TYPE_DIGITAL_TV ||
            info_ptr->service_type == MDI_MTV_SERVICE_TYPE_ANALOG_TV)
        {
            srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
            srv_gpio_play_pattern((srv_gpio_pattern_id_enum)srv_led_pattern_get_bg_pattern(), SRV_GPIO_PATN_PLAY_STOP);
        }


        /* init aud volume */
        if (dtv_player_p->setting.is_mute)
        {
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, (U8) MDI_AUD_VOL_EX_MUTE(DTV_PLAYER_VOL_MUTE));
        }
        else
        {
            /* init aud volume */
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, (U8) MDI_AUD_VOL_EX_MUTE(dtv_player_p->setting.vol_level));
        }
  
        dtv_player_p->last_error = mdi_mtv_start_service(
            dtv_player_p->mtv_handle, 
            info_ptr->service_id, 
            info_ptr->service_type,
            MMI_TRUE, 
            &video_setting);


        if (dtv_player_p->last_error == MDI_RES_MTV_SUCCEED)
        {
            /* Change player state to PLAY directly */
            PLAYER_ENTER_STATE(DTV_PLAYER_PLAY);
            /* unset flag */
            mmi_dtv_player_unset_flag(DTV_PLAYER_PLAYER_STARTED);

            StartTimer(
                DTV_PLAYER_SERVICE_TIMEOUT_TIMER,
                MMI_DTV_PLAYER_SERVICE_TIMEOUT_DURATION,
                mmi_dtv_player_service_timeout_hdlr);
        }
        else
        {
            if (info_ptr->service_type == MDI_MTV_SERVICE_TYPE_DIGITAL_TV ||
                info_ptr->service_type == MDI_MTV_SERVICE_TYPE_ANALOG_TV)
            {
                /* resume LED patten and let MMI can sleep */
                srv_gpio_play_pattern((srv_gpio_pattern_id_enum)srv_led_pattern_get_bg_pattern(), SRV_GPIO_PATN_PLAY_START);
                srv_backlight_turn_off();
            }
        }
    }

	#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
	switch_info.frequecy   = info_ptr->frequency;
	switch_info.service_id = info_ptr->service_id;
	mmi_cmmb_2gpp_adp_notify(EVT_ID_CMMB_2GPP_MMI_SWITCH, 0, &switch_info);
	if (active_screen == SCR_ID_DTV_PLAYER_APP)
	{
	/*	if (MEDIA_MTV_SERVICE_CLEAR_TO_AIR == info_ptr->service_flags)
		{
			mmi_dtv_player_hide_hint();
		}
		else*/
		{			
			mmi_dtv_player_2gpp_display_athenticate_state(mmi_cmmb_2gpp_get_authen_status());
		}
	}

	MMI_TRACE(MMI_MEDIA_TRC_G2_APP,
		      MMI_TRC_DTV_VAL2, 
		      info_ptr->frequency, 
		      info_ptr->service_id,
		      __LINE__);
#endif

    return dtv_player_p->last_error;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_kernel_exit_init_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_kernel_exit_init_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dtv_player_service_info_struct *info_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (KERNEL_STATE_IN(DTV_KERNEL_INIT))
    {
        info_ptr = mmi_dtv_player_get_active_channel_ptr();
        dtv_player_p->last_error = mdi_mtv_stop_service(dtv_player_p->mtv_handle, info_ptr->service_id);
        ASSERT(dtv_player_p->last_error == MDI_RES_MTV_SUCCEED);

        StopTimer(DTV_PLAYER_SERVICE_TIMEOUT_TIMER);

        /* Stop service init animation */
        mmi_dtv_player_stop_hint_animation();

        /* Change player state to STOP directly */
        if (PLAYER_STATE_IN(DTV_PLAYER_PLAY))
        {
            PLAYER_ENTER_STATE(DTV_PLAYER_STOPPED);

            if (info_ptr->service_type == MDI_MTV_SERVICE_TYPE_DIGITAL_TV ||
                info_ptr->service_type == MDI_MTV_SERVICE_TYPE_ANALOG_TV)
            {
                /* resume LED patten and let MMI can sleep */
                srv_gpio_play_pattern((srv_gpio_pattern_id_enum)srv_led_pattern_get_bg_pattern(), SRV_GPIO_PATN_PLAY_START);
                srv_backlight_turn_off();
            }
        }


    }
    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_kernel_entry_ready_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_kernel_entry_ready_state(void)
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
 *  mmi_dtv_player_kernel_exit_ready_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_kernel_exit_ready_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dtv_player_service_info_struct *info_ptr;
    MMI_ID active_screen = mmi_frm_scrn_get_active_id();  
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(dtv_player_p->kernel_next_state!=DTV_KERNEL_READY);

    if (!PLAYER_STATE_IN(DTV_PLAYER_STOPPED))
    {
        mmi_dtv_player_player_enter_state(DTV_PLAYER_STOPPED);
    }

    dtv_player_p->play_delay = 0;
    dtv_player_p->max_delay = 0;
    dtv_player_p->max_timeshift_delay = 0;

    mmi_dtv_player_unset_flag(DTV_PLAYER_BAD_RECEPTION);

    if (!RECORDER_STATE_IN(DTV_RECORDER_STOPPED))
    {
        mmi_dtv_player_recorder_enter_state(DTV_RECORDER_STOPPED);
    }

    StopTimer(DTV_PLAYER_UPDATE_SIGNAL_TIMER);
    gui_cancel_timer(mmi_dtv_player_enable_ts_function);

    info_ptr = mmi_dtv_player_get_active_channel_ptr();
    dtv_player_p->last_error = mdi_mtv_stop_service(dtv_player_p->mtv_handle, info_ptr->service_id);
    ASSERT(dtv_player_p->last_error == MDI_RES_MTV_SUCCEED);

    /* Re-draw signal icon to level 0 */
    dtv_player_p->signal_strength = 0;
    mmi_dtv_player_draw_signal_icon();

    kal_mem_set((void*)&(dtv_player_p->prog_info), 0, sizeof(mdi_mtv_program_info_struct));
    StopTimer(DTV_PLAYER_DISPLAY_ACCESS_DENIED_TIMER);

#ifdef __MBBMS_INTER__ 
    if (dtv_player_p->ca_state != MMI_DTV_CA_STATE_CMMB)
    {
        dtv_player_p->num_imd = dtv_player_p->num_unread_imd = 0;
        dtv_player_p->selected_imd = 0;
        dtv_player_p->int_state = DTV_PLAYER_INT_STATE_OFF;

        if (active_screen == SCR_ID_DTV_PLAYER_APP &&
            dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
        {
            mmi_dtv_player_set_blt_layer();
        }
    }    
    
#endif /*__MBBMS_INTER__ */  

    return dtv_player_p->last_error;
}


/*player state management*/
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_player_entry_stopped_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_player_entry_stopped_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dtv_player_service_info_struct *info_ptr;
    mdi_mtv_service_type_enum service_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dtv_player_p->player_state == DTV_PLAYER_PLAY)
    {
        dtv_player_p->last_error = mdi_mtv_player_stop(dtv_player_p->mtv_handle);

    #if defined(__MMI_DTV_A2DP_SUPPORT__)
        mmi_dtv_player_bt_close_codec();
        mmi_dtv_player_disconnect_bt();
    #endif

        info_ptr = mmi_dtv_player_get_active_channel_ptr();
        service_type = info_ptr->service_type;
        if (service_type == MDI_MTV_SERVICE_TYPE_DIGITAL_TV ||
            service_type == MDI_MTV_SERVICE_TYPE_ANALOG_TV)
        {
            /* resume LED patten and let MMI can sleep */
            srv_gpio_play_pattern((srv_gpio_pattern_id_enum)srv_led_pattern_get_bg_pattern(), SRV_GPIO_PATN_PLAY_START);
            srv_backlight_turn_off();
        }
        else if (service_type == MDI_MTV_SERVICE_TYPE_DIGITAL_RADIO)
        {
            mmi_dtv_player_stop_radio_animation();
        }
    }
#if defined(__MMI_DTV_A2DP_SUPPORT__)
    else if (dtv_player_p->player_state == DTV_PLAYER_BT_CONNECT)
    {
        mmi_dtv_player_disconnect_bt();
    }
#endif

    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_player_exit_stopped_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_player_exit_stopped_state(void)
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
 *  mmi_dtv_player_player_entry_bt_connect_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_player_entry_bt_connect_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dtv_player_service_info_struct *info_ptr;
    MMI_BOOL is_stereo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dtv_player_unset_flag(DTV_PLAYER_DISBLE_AUTO_PLAY);
#if defined(__MMI_DTV_A2DP_SUPPORT__)
    if (mmi_dtv_player_is_output_to_bt())
    {
    #ifdef __MMI_DTV_BLOCK_BG_CALL__
        if (mmi_dtv_player_is_in_background_call())
        {
            mmi_dtv_player_set_flag(DTV_PLAYER_UNAVAILABLE_IN_CALL);
            dtv_player_p->last_error = MDI_RES_MTV_FAILED;
            return dtv_player_p->last_error;
        }
    #endif /* __MMI_DTV_BLOCK_BG_CALL__ */

        info_ptr = mmi_dtv_player_get_active_channel_ptr();

        mdi_mtv_get_audio_sample_rate(dtv_player_p->mtv_handle, info_ptr->service_id, &(dtv_player_p->aud_sample_rate));
        mdi_mtv_get_audio_channel_number(dtv_player_p->mtv_handle, info_ptr->service_id, &(dtv_player_p->aud_channel_num));

        if (dtv_player_p->aud_channel_num == 2)
        {
            is_stereo = MMI_TRUE;
        }
        else
        {
            is_stereo = MMI_FALSE;
        }

        /* For protection */
        if (!IsMyTimerExist(DTV_PLAYER_BT_ANIMATION_TIMER))
        {
            /* Draw BT connect animation after 600 ms */
            StartTimer(
                DTV_PLAYER_BT_ANIMATION_TIMER,
                600,
                mmi_dtv_player_bt_anim_timeout_hdlr);
        }

        av_bt_open_ex(
            mmi_dtv_player_get_bt_headset(),
            (kal_uint16)dtv_player_p->aud_sample_rate,
            (kal_uint8)is_stereo,
            mmi_dtv_player_bt_open_callback,
            KAL_TRUE);

        dtv_player_p->last_error = MDI_RES_MTV_SUCCEED;
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
 *  mmi_dtv_player_player_exit_bt_connect_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_player_exit_bt_connect_state(void)
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
 *  mmi_dtv_player_player_entry_play_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_player_entry_play_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen_id = mmi_frm_scrn_get_active_id();
    dtv_player_service_info_struct *info_ptr;
    mdi_mtv_player_setting_struct video_setting = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(!PLAYER_STATE_IN(DTV_PLAYER_PLAY));
    mmi_dtv_player_unset_flag(DTV_PLAYER_DISBLE_AUTO_PLAY);
#ifdef  __MMI_DTV_BLOCK_BG_CALL__
    if (mmi_dtv_player_is_in_background_call())
    {
        mmi_dtv_player_set_flag(DTV_PLAYER_UNAVAILABLE_IN_CALL);
        dtv_player_p->last_error = MDI_RES_MTV_FAILED;
        return dtv_player_p->last_error;
    }
#endif /* __MMI_DTV_BLOCK_BG_CALL__ */

    info_ptr = mmi_dtv_player_get_active_channel_ptr();
    /* stop MMI sleep and stop LED pattern beofore play */
    if (info_ptr->service_type == MDI_MTV_SERVICE_TYPE_DIGITAL_TV ||
        info_ptr->service_type == MDI_MTV_SERVICE_TYPE_ANALOG_TV)
    {
        srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
        srv_gpio_play_pattern((srv_gpio_pattern_id_enum)srv_led_pattern_get_bg_pattern(), SRV_GPIO_PATN_PLAY_STOP);
    }

        /* init aud volume */
    /* init aud volume */
    if (dtv_player_p->setting.is_mute)
    {
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, (U8) MDI_AUD_VOL_EX_MUTE(DTV_PLAYER_VOL_MUTE));
    }
    else
    {
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, (U8) MDI_AUD_VOL_EX_MUTE(dtv_player_p->setting.vol_level));
    }

    mmi_dtv_player_player_prepare_player_setting(&video_setting);

    dtv_player_p->last_error = mdi_mtv_player_play(dtv_player_p->mtv_handle, &video_setting);

    if (dtv_player_p->last_error == MDI_RES_MTV_SUCCEED)
    {
        if (info_ptr->service_type == MDI_MTV_SERVICE_TYPE_DIGITAL_RADIO)
        {
            mmi_dtv_player_draw_radio_animation();
        }
        /* unset flag */
        mmi_dtv_player_unset_flag(DTV_PLAYER_PLAYER_STARTED);

    }
    else
    {
        mmi_dtv_player_handle_play_fail();
    }

    return dtv_player_p->last_error;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_player_exit_play_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_player_exit_play_state(void)
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
 *  mmi_dtv_player_player_entry_pause_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_player_entry_pause_state(void)
{
#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_mtv_service_type_enum service_type;
    dtv_player_service_info_struct *info_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dtv_player_p->player_state == DTV_PLAYER_PLAY)
    {
        dtv_player_p->last_error = mdi_mtv_player_pause(dtv_player_p->mtv_handle);

    #if defined(__MMI_DTV_A2DP_SUPPORT__)
        mmi_dtv_player_bt_close_codec();
        mmi_dtv_player_disconnect_bt();
    #endif
        if (dtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
        {
            return dtv_player_p->last_error;
        }

        info_ptr = mmi_dtv_player_get_active_channel_ptr();
        service_type = info_ptr->service_type;
        if (service_type == MDI_MTV_SERVICE_TYPE_DIGITAL_RADIO)
        {
            mmi_dtv_player_stop_radio_animation();
        }
    }
#if defined(__MMI_DTV_A2DP_SUPPORT__)
    else if (dtv_player_p->player_state == DTV_PLAYER_BT_CONNECT)
    {
        mmi_dtv_player_disconnect_bt();
    }
#endif
#endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__  */
    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_player_exit_pause_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_player_exit_pause_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MDI_RES_MTV_SUCCEED;
}

#ifdef __MMI_DTV_RECORD_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_kernel_entry_saving_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_kernel_entry_saving_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mdi_mtv_recover_recording(dtv_player_p->mtv_handle);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_kernel_exit_saving_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_kernel_exit_saving_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mdi_mtv_abort_recovering(dtv_player_p->mtv_handle);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_kernel_entry_deleting_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_kernel_entry_deleting_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mdi_mtv_discard_unsaved_recording(dtv_player_p->mtv_handle);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_kernel_exit_deleting_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_kernel_exit_deleting_state(void)
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
 *  mmi_dtv_player_recorder_entry_stopped_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_recorder_entry_stopped_state(void)
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
 *  mmi_dtv_player_recorder_exit_stopped_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_recorder_exit_stopped_state(void)
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
 *  mmi_dtv_player_recorder_entry_record_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_recorder_entry_record_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dtv_player_service_info_struct *info_ptr;
    CHAR *file_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    info_ptr = mmi_dtv_player_get_active_channel_ptr();
    file_ptr = (CHAR*)info_ptr->program_name;

    if (RECORDER_STATE_IN(DTV_RECORDER_STOPPED))
    {
        dtv_player_p->last_error =
            mdi_mtv_recorder_start(dtv_player_p->mtv_handle, file_ptr);
    }
    else
    {
        dtv_player_p->last_error =
            mdi_mtv_recorder_resume(dtv_player_p->mtv_handle);
    }
    return dtv_player_p->last_error;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_recorder_exit_record_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_recorder_exit_record_state(void)
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
 *  mmi_dtv_player_recorder_entry_pause_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_recorder_entry_pause_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dtv_player_p->last_error = mdi_mtv_recorder_pause(dtv_player_p->mtv_handle);

    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_recorder_exit_pause_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_recorder_exit_pause_state(void)
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
 *  mmi_dtv_player_recorder_entry_save_confirm_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_recorder_entry_save_confirm_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dtv_player_p->last_error = mdi_mtv_recorder_stop(dtv_player_p->mtv_handle);
    dtv_player_p->active_osd_cntx_p->channel_next.status = DTV_PLAYER_ICON_STATUS_ENABLE;
    dtv_player_p->active_osd_cntx_p->channel_prev.status = DTV_PLAYER_ICON_STATUS_ENABLE;

    /* disable ts, due to use another buffer engine */
    dtv_player_p->is_ready_to_ts = MMI_FALSE;
#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
    gui_start_timer(MMI_DTV_PLAYER_TS_ENABLE_DURATION, mmi_dtv_player_enable_ts_function);
#endif
    active_screen_id = mmi_frm_scrn_get_active_id();
    if (active_screen_id == SCR_ID_DTV_PLAYER_APP)
    {
        /* If already fade out, keep all key handler as: mmi_dtv_player_fullscr_osd_show_up */
        if (dtv_player_p->fullscr_osd_opacity != 0)
        {
            mmi_dtv_player_register_key_hdlr();
        }
    }

    if (dtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
    {
        ASSERT(0);
    }
    return dtv_player_p->last_error ;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_recorder_exit_save_confirm_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_recorder_exit_save_confirm_state(void)
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
 *  mmi_dtv_player_recorder_exit_deleting_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_recorder_exit_deleting_state(void)
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
 *  mmi_dtv_player_recorder_entry_save_confirm_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_recorder_entry_deleting_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset ts info */
    dtv_player_p->max_timeshift_delay = 0;
    dtv_player_p->play_delay = 0;
    dtv_player_p->max_delay = 0;

    dtv_player_p->last_error = mdi_mtv_recorder_discard_recording(dtv_player_p->mtv_handle);

    return dtv_player_p->last_error;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_recorder_entry_saving_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_recorder_entry_saving_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* reset ts info */
    dtv_player_p->max_timeshift_delay = 0;
    dtv_player_p->play_delay = 0;
    dtv_player_p->max_delay = 0;

    dtv_player_p->last_error = mdi_mtv_recorder_save(dtv_player_p->mtv_handle, NULL);

    return dtv_player_p->last_error;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_recorder_exit_saving_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_recorder_exit_saving_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dtv_player_p->last_error = mdi_mtv_recorder_abort_saving(dtv_player_p->mtv_handle);

    return dtv_player_p->last_error;
}
#endif /* __MMI_DTV_RECORD_SUPPORT__  */

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_and_update_signal
 * DESCRIPTION
 *  udpate siangl api on common screen
 * PARAMETERS
 *  dummy_ptr       [?]
 * RETURNS
 *  U8
 *****************************************************************************/
 void mmi_dtv_player_get_and_update_signal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_mtv_service_status_struct service_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (KERNEL_STATE_IN(DTV_KERNEL_READY))
    {
        mdi_mtv_service_get_status(dtv_player_p->mtv_handle, &service_status);

        dtv_player_p->signal_strength = service_status.signal_strength;

        if (dtv_player_p->signal_strength <= 25)
        {
            dtv_player_p->signal_strength = 0;
        }
        else if (dtv_player_p->signal_strength <= 44)
        {
            dtv_player_p->signal_strength = 25;
        }
        else if (dtv_player_p->signal_strength <= 63)
        {
            dtv_player_p->signal_strength = 50;
        }
        else if (dtv_player_p->signal_strength <= 82)
        {
            dtv_player_p->signal_strength = 75;
        }
        else
        {
            dtv_player_p->signal_strength = 100;
        }
    }
    else
    {
        dtv_player_p->signal_strength = 0;
    }

    mmi_dtv_player_draw_signal_icon();

    StartTimer(
        DTV_PLAYER_UPDATE_SIGNAL_TIMER,
        MMI_DTV_PLAYER_UPDATE_SIGNAL_DURATION,
        mmi_dtv_player_get_and_update_signal);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_player_update_cyclic
 * DESCRIPTION
 *  display error popup.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_player_update_cyclic(void)
{
#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(DTV_PLAYER_UPDATE_PLAYER_STATUS);

    /* Return directly and do not start timer again */
    if (mmi_frm_scrn_get_active_id() != SCR_ID_DTV_PLAYER_APP ||
        !KERNEL_STATE_IN(DTV_KERNEL_READY))
    {
        return;
    }

    ASSERT(mmi_frm_scrn_get_active_id() == SCR_ID_DTV_PLAYER_APP);

    mmi_dtv_player_get_player_status(
            dtv_player_p->mtv_handle,
            NULL,
            &dtv_player_p->play_delay,
            &dtv_player_p->max_delay,
            &dtv_player_p->max_timeshift_delay,
            NULL);

    if (dtv_player_p->fullscr_osd_opacity != 0)
    {
        mmi_dtv_player_draw_osd();
        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }

    StartTimer(DTV_PLAYER_UPDATE_PLAYER_STATUS, 1000, mmi_dtv_player_player_update_cyclic);
#endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_service_timeout_hdlr
 * DESCRIPTION
 *  mmi_dtv_player_service_timeout_hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_service_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_SERVICE_TIMEOUT_HDLR);
    ASSERT(KERNEL_STATE_IN(DTV_KERNEL_INIT));

    if (mmi_dtv_player_is_flag_set(DTV_PLAYER_ACCESS_DENIED) == MMI_TRUE ||
        IsMyTimerExist(DTV_PLAYER_DISPLAY_ACCESS_DENIED_TIMER))
    {
        return;
    }

    /* start service timeout, so MMI automatically stops service. */
    if (KERNEL_STATE_IN(DTV_KERNEL_INIT))
    {
        ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);

        ASSERT(ret == MDI_RES_MTV_SUCCEED);
    }

    /* Display service unavailable */
    mmi_dtv_player_handle_service_aborted();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_draw_signal_icon
 * DESCRIPTION
 *  draw signal icon
 * PARAMETERS
 *  void
 * RETURNS
 *  S32 active channel idx
 *****************************************************************************/
 void mmi_dtv_player_draw_signal_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_DTV_LANDSCAPE_SUPPORT__) && !defined(GDI_USING_2D_ENGINE_V3)
    PU8 dest;
#endif
    U16 signal_level;
    S32 width, height;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_frm_scrn_get_active_id() == SCR_ID_DTV_PLAYER_APP &&
        dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        ASSERT(dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270);

    #if !defined(__MMI_DTV_LANDSCAPE_SUPPORT__)
        gdi_layer_push_and_set_active(dtv_player_p->dls_drawing_layer_handle);
    #else /* !__MMI_DTV_LANDSCAPE_SUPPORT__ */
        gdi_layer_push_and_set_active(dtv_player_p->dls_layer_handle);
    #if !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
        gdi_layer_toggle_double();
		gdi_layer_copy_double();
    #endif
    #endif /* _!__MMI_DTV_LANDSCAPE_SUPPORT__ */

        /* clear icon region as transparent */
        gdi_image_get_dimension_id(
            (U16)(IMG_ID_DTV_PLAYER_SIGNAL_LEVEL_0),
            &width,
            &height);

        gdi_draw_solid_rect(
            MMI_DTV_PLAYER_SIGNAL_ICON_OFFSET_X,
            MMI_DTV_PLAYER_SIGNAL_ICON_OFFSET_Y,
            MMI_DTV_PLAYER_SIGNAL_ICON_OFFSET_X + width,
            MMI_DTV_PLAYER_SIGNAL_ICON_OFFSET_Y + height,
            GDI_COLOR_TRANSPARENT);

        /* Draw signal icon */
        signal_level = dtv_player_p->signal_strength / 25;

        gdi_image_draw_id(
            MMI_DTV_PLAYER_SIGNAL_ICON_OFFSET_X,
            MMI_DTV_PLAYER_SIGNAL_ICON_OFFSET_Y,
            (U16)(IMG_ID_DTV_PLAYER_SIGNAL_LEVEL_0 + signal_level));
        gdi_layer_pop_and_restore_active();

    #if !defined(__MMI_DTV_LANDSCAPE_SUPPORT__)
        gdi_layer_push_and_set_active(dtv_player_p->dls_layer_handle);
    #if !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
        gdi_layer_toggle_double();
	    gdi_layer_copy_double();
    #endif
    #if defined(GDI_USING_2D_ENGINE_V3)
        gdi_2d_begin();
        gdi_2d_set_layer_as_dest_buffer(dtv_player_p->dls_layer_handle);
        gdi_2d_set_layer_as_src_bitblt_buffer(dtv_player_p->dls_drawing_layer_handle);
        gdi_2d_rotate(GDI_TRANSFORM_ROTATE_90);
        gdi_2d_end();
    #else
        gdi_layer_get_buffer_ptr(&dest);
        /* toggle double buffer */
        mmi_dtv_player_sw_rotate(
          dest,
          dtv_player_p->dls_drawing_layer_buf_ptr,
          (U32) DTV_PLAYER_FULLSCREEN_DLS_LAYER_WIDTH,
          (U32) DTV_PLAYER_FULLSCREEN_DLS_LAYER_HEIGHT);
    #endif
        gdi_layer_pop_and_restore_active();
    #endif /* !defined(__MMI_DTV_LANDSCAPE_SUPPORT__) */

        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

        /* Change status icon level: status bar is hided, the function won't blt out */
        wgui_status_icon_bar_change_icon_level(STATUS_ICON_DTV_SIGNAL, (U8) dtv_player_p->signal_strength);

    }
    else
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_DTV_PLAYER_APP)
        {
            gdi_layer_push_and_set_active(dtv_player_p->status_bar_layer_handle);
            wgui_status_icon_bar_register_hide_callback(
                WGUI_STATUS_ICON_BAR_H_BAR,
                hide_status_icons_bar0_by_transparent);
        }

        /* Change status icon level: if status bar is not hided, the function will blt out */
        wgui_status_icon_bar_change_icon_level(STATUS_ICON_DTV_SIGNAL, (U8) dtv_player_p->signal_strength);
        wgui_status_icon_bar_update();

        if (mmi_frm_scrn_get_active_id() == SCR_ID_DTV_PLAYER_APP)
        {
            gdi_layer_pop_and_restore_active();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_clear_dynamic_label
 * DESCRIPTION
 *  clear dls layer (called when 1.exit app 2.change channel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_clear_dynamic_label(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_DTV_LANDSCAPE_SUPPORT__) && !defined(GDI_USING_2D_ENGINE_V3)
    PU8 dest;
#endif
    S32 offset_x, offset_y, width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_CLEAR_DYNAMIC_LABEL);
    if (dtv_player_p->dynamic_label_state == DTV_PLAYER_DYNAMIC_LABEL_SCROLLING)
    {
        gui_scrolling_text_stop(&dtv_player_p->scrolling_label);
    }

    /* Set active layer */
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        gdi_layer_push_and_set_active(dtv_player_p->osd_layer_handle);
    #if !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
        gdi_layer_toggle_double();
	    gdi_layer_copy_double();
    #endif
    }
    else if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
    #if !defined(__MMI_DTV_LANDSCAPE_SUPPORT__)
        gdi_layer_push_and_set_active(dtv_player_p->dls_drawing_layer_handle);
    #else /* !__MMI_DTV_LANDSCAPE_SUPPORT__ */
        gdi_layer_push_and_set_active(dtv_player_p->dls_layer_handle);
    #if !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
        gdi_layer_toggle_double();
	    gdi_layer_copy_double();
    #endif
    #endif /* !__MMI_DTV_LANDSCAPE_SUPPORT__ */
    }

    /* clear dls region as transparent */
    offset_x = dtv_player_p->active_osd_cntx_p->title.offset_x;
    offset_y = dtv_player_p->active_osd_cntx_p->title.offset_y;
    width = dtv_player_p->active_osd_cntx_p->title.width;
    height = dtv_player_p->active_osd_cntx_p->title.height;

    gdi_draw_solid_rect(
        offset_x,
        offset_y,
        offset_x + width,
        offset_y + height,
        GDI_COLOR_TRANSPARENT);

    gdi_layer_pop_and_restore_active();

#if !defined(__MMI_DTV_LANDSCAPE_SUPPORT__)
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        gdi_layer_push_and_set_active(dtv_player_p->dls_layer_handle);
    #if !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
        gdi_layer_toggle_double();
	    gdi_layer_copy_double();
    #endif
    #if defined(GDI_USING_2D_ENGINE_V3)
        gdi_2d_begin();
        gdi_2d_set_layer_as_dest_buffer(dtv_player_p->dls_layer_handle);
        gdi_2d_set_layer_as_src_bitblt_buffer(dtv_player_p->dls_drawing_layer_handle);
        gdi_2d_rotate(GDI_TRANSFORM_ROTATE_90);
        gdi_2d_end();
    #else
        gdi_layer_get_buffer_ptr(&dest);
        /* toggle double buffer */
        mmi_dtv_player_sw_rotate(
            dest,
            dtv_player_p->dls_drawing_layer_buf_ptr,
            (U32) DTV_PLAYER_FULLSCREEN_DLS_LAYER_WIDTH,
            (U32) DTV_PLAYER_FULLSCREEN_DLS_LAYER_HEIGHT);
    #endif
        gdi_layer_pop_and_restore_active();
    }
#endif /*  !__MMI_DTV_LANDSCAPE_SUPPORT__*/
    dtv_player_p->dynamic_label_state = DTV_PLAYER_DYNAMIC_LABEL_OFF;

    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_scrolling_text_draw_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_scrolling_text_draw_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_DTV_LANDSCAPE_SUPPORT__) && !defined(GDI_USING_2D_ENGINE_V3)
    PU8 dest;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        gdi_layer_push_and_set_active(dtv_player_p->osd_layer_handle);
    #if !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
        gdi_layer_toggle_double();
		gdi_layer_copy_double();
    #endif
    }
    else if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
    #if !defined(__MMI_DTV_LANDSCAPE_SUPPORT__)
        gdi_layer_push_and_set_active(dtv_player_p->dls_drawing_layer_handle);
        /* Avoid gui_handle_scrolling_text and gui_redraw_scrolling_text blt out */
        gdi_layer_lock_frame_buffer();
    #else /* !__MMI_DTV_LANDSCAPE_SUPPORT__ */
        gdi_layer_push_and_set_active(dtv_player_p->dls_layer_handle);
    #if !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
        gdi_layer_toggle_double();
	    gdi_layer_copy_double();
    #endif
    #endif /* !__MMI_DTV_LANDSCAPE_SUPPORT__ */
    }

    /* disable font alpha */
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_fe_set_antialias(MMI_FALSE);
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */

    /* The two function will scroll text and blt out */
    gui_handle_scrolling_text(&dtv_player_p->scrolling_label);
    gui_redraw_scrolling_text(&dtv_player_p->scrolling_label);

    /* enable font alpha */
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_fe_set_antialias(MMI_TRUE);
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */

    gdi_layer_pop_and_restore_active();

#if !defined(__MMI_DTV_LANDSCAPE_SUPPORT__)
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        gdi_layer_unlock_frame_buffer();

        gdi_layer_push_and_set_active(dtv_player_p->dls_layer_handle);
    #if !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
        gdi_layer_toggle_double();
	    gdi_layer_copy_double();
    #endif
    #if defined(GDI_USING_2D_ENGINE_V3)
        gdi_2d_begin();
        gdi_2d_set_layer_as_dest_buffer(dtv_player_p->dls_layer_handle);
        gdi_2d_set_layer_as_src_bitblt_buffer(dtv_player_p->dls_drawing_layer_handle);
        gdi_2d_rotate(GDI_TRANSFORM_ROTATE_90);
        gdi_2d_end();
    #else
        gdi_layer_get_buffer_ptr(&dest);
        /* toggle double buffer */
        mmi_dtv_player_sw_rotate(
            dest,
            dtv_player_p->dls_drawing_layer_buf_ptr,
            (U32) DTV_PLAYER_FULLSCREEN_DLS_LAYER_WIDTH,
            (U32) DTV_PLAYER_FULLSCREEN_DLS_LAYER_HEIGHT);
    #endif
        gdi_layer_pop_and_restore_active();

        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }
#endif /* !__MMI_DTV_LANDSCAPE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_scrolling_text_draw_background_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_scrolling_text_draw_background_hdlr(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_draw_dynamic_label
 * DESCRIPTION
 *
 * PARAMETERS
 *  CHAR *
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_draw_dynamic_label(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width, str_height, str_x;
    S32 offset_x, offset_y, width, height;
#if !defined(__MMI_DTV_LANDSCAPE_SUPPORT__) && !defined(GDI_USING_2D_ENGINE_V3)
    PU8 dest;
#endif
    dtv_player_osd_text_struct *title_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_DRAW_DYNAMIC_LABEL);
    ASSERT(mmi_frm_scrn_get_active_id() == SCR_ID_DTV_PLAYER_APP);

#if defined(__MMI_DTV_SMALL_HINT__)
	gui_set_font(&MMI_small_font);
#else
	gui_set_font(&MMI_medium_font);
#endif

    gui_measure_string((UI_string_type) dtv_player_p->label_str, &str_width, &str_height);

    /* Stop scrolling text */
    if (dtv_player_p->dynamic_label_state == DTV_PLAYER_DYNAMIC_LABEL_SCROLLING)
    {
        gui_scrolling_text_stop(&dtv_player_p->scrolling_label);
    }

    title_p = &dtv_player_p->active_osd_cntx_p->title;
    /* Set active layer */
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        gdi_layer_push_and_set_active(dtv_player_p->osd_layer_handle);
    #if !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
        gdi_layer_toggle_double();
		gdi_layer_copy_double();
    #endif

		offset_y = title_p->offset_y + ((title_p->height - str_height) >> 1);
    }
    else
    {
    #if !defined(__MMI_DTV_LANDSCAPE_SUPPORT__)
        gdi_layer_push_and_set_active(dtv_player_p->dls_drawing_layer_handle);
    #else /* !__MMI_DTV_LANDSCAPE_SUPPORT__ */
        gdi_layer_push_and_set_active(dtv_player_p->dls_layer_handle);
    #if !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
        gdi_layer_toggle_double();
		gdi_layer_copy_double();
    #endif
    #endif /* !__MMI_DTV_LANDSCAPE_SUPPORT__ */
		offset_y = (DTV_PLAYER_FULLSCREEN_DLS_LAYER_HEIGHT - str_height) >> 1;
	}

    offset_x = title_p->offset_x;
    width = title_p->width;
    height = title_p->height;

    /* clear dls region as transparent */
    gdi_draw_solid_rect(
        offset_x,
        offset_y,
        offset_x + width,
        offset_y + height,
        GDI_COLOR_TRANSPARENT);

    /* disable font alpha */
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_fe_set_antialias(MMI_FALSE);
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */

    /* draw scrolling text */
    if (str_width + 2 > dtv_player_p->active_osd_cntx_p->title.width)
    {
        gui_create_scrolling_text(
            &dtv_player_p->scrolling_label,
            offset_x + 2, /* border text will be out of range -2X~+2X */
            offset_y + 1, /* border text will be out of range -1Y~+1Y */
            width - 4,
            height - 2,
            (UI_string_type) dtv_player_p->label_str,
            mmi_dtv_player_scrolling_text_draw_hdlr,
            mmi_dtv_player_scrolling_text_draw_background_hdlr,
            gui_color(255, 255, 255),
            gui_color(0,0,0));

        dtv_player_p->scrolling_label.flags |= UI_SCROLLING_TEXT_BORDERED_TEXT;
        /* Draw first frame into active layer and blt out */
        gui_show_scrolling_text(&dtv_player_p->scrolling_label);
        dtv_player_p->dynamic_label_state = DTV_PLAYER_DYNAMIC_LABEL_SCROLLING;

        gdi_layer_pop_and_restore_active();
    }
    else
    {
        str_x = title_p->offset_x + ((title_p->width - str_width - 2) >> 1);

        mmi_dtv_player_draw_style_text(
            (CHAR *)dtv_player_p->label_str,
            str_x, offset_y);

        dtv_player_p->dynamic_label_state = DTV_PLAYER_DYNAMIC_LABEL_ON;

        gdi_layer_pop_and_restore_active();
    }

/* disable font alpha */
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_fe_set_antialias(MMI_TRUE);
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */

#if !defined(__MMI_DTV_LANDSCAPE_SUPPORT__)
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        gdi_layer_push_and_set_active(dtv_player_p->dls_layer_handle);
    #if !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
        gdi_layer_toggle_double();
	    gdi_layer_copy_double();
    #endif
    #if defined(GDI_USING_2D_ENGINE_V3)
        gdi_2d_begin();
        gdi_2d_set_layer_as_dest_buffer(dtv_player_p->dls_layer_handle);
        gdi_2d_set_layer_as_src_bitblt_buffer(dtv_player_p->dls_drawing_layer_handle);
        gdi_2d_rotate(GDI_TRANSFORM_ROTATE_90);
        gdi_2d_end();
    #else
        gdi_layer_get_buffer_ptr(&dest);
        /* toggle double buffer */
        mmi_dtv_player_sw_rotate(
            dest,
            dtv_player_p->dls_drawing_layer_buf_ptr,
            (U32) DTV_PLAYER_FULLSCREEN_DLS_LAYER_WIDTH,
            (U32) DTV_PLAYER_FULLSCREEN_DLS_LAYER_HEIGHT);
    #endif
        gdi_layer_pop_and_restore_active();
    }
#endif /* !__MMI_DTV_LANDSCAPE_SUPPORT__ */

    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
}


#if defined(__MMI_DTV_A2DP_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_bt_power_off_notify_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_bt_power_off_notify_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_BT_POWER_OFF_NOTIFY_HDLR, dtv_player_p->player_state);
    if (!mmi_a2dp_is_output_to_bt())
    {
        /* switch output: ON -> OFF */
        if (PLAYER_STATE_IN(DTV_PLAYER_PLAY))
        {
            av_bt_close_codec();
            av_bt_close(KAL_FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_is_output_to_bt
 * DESCRIPTION
 *  a callback function invoked by av_bt_open apis
 * PARAMETERS
 *  result
 * RETURNS
 *  void
 *****************************************************************************/
 MMI_BOOL mmi_dtv_player_is_output_to_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_a2dp_is_output_to_bt())
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
 *  mmi_dtv_player_stop_bt_connecting_anim
 * DESCRIPTION
 *  draw title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_stop_bt_connecting_anim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dtv_player_p->bt_connect_amin_handle == GDI_NULL_HANDLE)
    {
        return;
    }

    screen_id = mmi_frm_scrn_get_active_id();

    /* Stop animation first */
    gdi_image_stop_animation(dtv_player_p->bt_connect_amin_handle);
    dtv_player_p->bt_connect_amin_handle = GDI_NULL_HANDLE;

    /* Clear layer */
    if (screen_id == SCR_ID_DTV_PLAYER_CHANNEL_LIST)
    {
        gdi_layer_push_and_set_active(dtv_player_p->cl_preview_layer_handle);
        gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();

        gdi_layer_blt_previous(
            dtv_player_p->cl_preview_layer_offset_x,
            dtv_player_p->cl_preview_layer_offset_y,
            dtv_player_p->cl_preview_layer_offset_x + dtv_player_p->cl_preview_layer_width - 1,
            dtv_player_p->cl_preview_layer_offset_y + dtv_player_p->cl_preview_layer_height - 1);

    }
    /* Do not draw_osd() again if screen_id == MAIN_SCREEN.
       Player state is at CONNECTING state so BT animation
       will be drawn again. */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_bt_anim_timeout_hdlr
 * DESCRIPTION
 *  draw bt connecting animation if wait > 600ms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_bt_anim_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 screen_id = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_BT_ANIM_TIMEOUT_HDLR);

    if (screen_id == SCR_ID_DTV_PLAYER_CHANNEL_LIST)
    {
        if (dtv_player_p->bt_connect_amin_handle == GDI_NULL_HANDLE)
        {
            gdi_layer_push_and_set_active(dtv_player_p->cl_preview_layer_handle);
            gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_anim_draw_id(
                0,
                0,
                IMG_ID_DTV_BT_CONNECT_PREVIEW,
                &dtv_player_p->bt_connect_amin_handle);

            gdi_layer_pop_and_restore_active();
        }
    }
    else if (screen_id == SCR_ID_DTV_PLAYER_APP)
    {
        mmi_dtv_player_draw_osd();
        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_bt_headset
 * DESCRIPTION
 *  retrieve the user selected bt headset
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_bt_cm_bt_addr*
 *****************************************************************************/
 srv_bt_cm_bt_addr *mmi_dtv_player_get_bt_headset(void)
{
    return mmi_a2dp_get_bt_headset();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_bt_open_callback
 * DESCRIPTION
 *  a callback function invoked by av_bt_open apis
 * PARAMETERS
 *  result
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_bt_open_callback(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_BT_OPEN_CALLBACK, result);

    StopTimer(DTV_PLAYER_BT_ANIMATION_TIMER);
    mmi_dtv_player_stop_bt_connecting_anim();

    switch (result)
    {
        case AV_BT_CALLBACK_EVENT_OPEN_OK:
            /*
             *  NOTICE: even after receive EVENT_OPEN_FAILED or EVENT_OPEN_STOPPED,
             *          bt driver may still send EVENT_OPEN_OK, this is due to driver
             *          has retry mechanism.
             */
            if (PLAYER_STATE_IN(DTV_PLAYER_BT_CONNECT))
            {
                U16 active_screen_id;
                active_screen_id = mmi_frm_scrn_get_active_id();

                av_bt_open_codec(KAL_FALSE);

                if (active_screen_id == SCR_ID_DTV_PLAYER_APP)
                {
                    mmi_dtv_player_player_enter_state(DTV_PLAYER_PLAY);
                    mmi_dtv_player_register_key_hdlr();

                    if (mmi_dtv_player_is_flag_set(DTV_PLAYER_UNAVAILABLE_IN_CALL))
                    {
                        mmi_dtv_player_set_hint(
                            (CHAR *) GetString((U16)(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL)),
							(CHAR *) NULL,
						     MMI_DTV_PLAYER_HINT_POPUP_NO_FADE,
                             MMI_TRUE);
                        mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
                    }
                    else
                    {
                        mmi_dtv_player_draw_osd();
                    }
                    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

                }
                else if (active_screen_id == SCR_ID_DTV_PLAYER_CHANNEL_LIST)
                {
                    mmi_dtv_player_player_enter_state(DTV_PLAYER_PLAY);
                    if (dtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
                    {
                        mmi_dtv_player_draw_preview_icon(DTV_PLAYER_PREVIEW_ICON_BROKEN);
                    }
                }
            }
            else if (PLAYER_STATE_IN(DTV_PLAYER_PLAY))
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
            if (PLAYER_STATE_IN(DTV_PLAYER_BT_CONNECT))
            {
                U16 active_screen_id;
                active_screen_id = mmi_frm_scrn_get_active_id();

                 /* connect failed - play the video */
                if (active_screen_id == SCR_ID_DTV_PLAYER_APP)
                {
                    mmi_dtv_player_player_enter_state(DTV_PLAYER_PLAY);
                    mmi_dtv_player_register_key_hdlr();

                    mmi_dtv_player_draw_osd();
                    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

                }
                else if (active_screen_id == SCR_ID_DTV_PLAYER_CHANNEL_LIST)
                {
                    mmi_dtv_player_player_enter_state(DTV_PLAYER_PLAY);
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
            if (PLAYER_STATE_IN(DTV_PLAYER_BT_CONNECT))
            {
                U16 active_screen_id;
                active_screen_id = mmi_frm_scrn_get_active_id();

                 /* connect failed - play the video */
                if (active_screen_id == SCR_ID_DTV_PLAYER_APP)
                {
                    mmi_dtv_player_player_enter_state(DTV_PLAYER_PLAY);
                    mmi_dtv_player_register_key_hdlr();

                    mmi_dtv_player_draw_osd();
                    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

                }
                else if (active_screen_id == SCR_ID_DTV_PLAYER_CHANNEL_LIST)
                {
                    mmi_dtv_player_player_enter_state(DTV_PLAYER_PLAY);
                }
            }
            break;

        case AV_BT_CALLBACK_EVENT_STREAM_START_IND:
        case AV_BT_CALLBACK_EVENT_INQUIRY_START_IND:
        case AV_BT_CALLBACK_EVENT_INQUIRY_STOP_IND:
            /* ignore */
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_disconnect_bt
 * DESCRIPTION
 *  start play video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_disconnect_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(DTV_PLAYER_BT_ANIMATION_TIMER);
    mmi_dtv_player_stop_bt_connecting_anim();

    if (mmi_dtv_player_is_output_to_bt())
    {
        av_bt_close(MMI_FALSE);
    }
    /* TODO: stop anim */
}



/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_bt_close_codec
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_bt_close_codec(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_dtv_player_is_output_to_bt())
    {
        av_bt_close_codec();
    }

}
#endif /* __MMI_DTV_A2DP_SUPPORT__ */


#if defined(__MMI_DTV_AVRCP_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_bt_avrcp_cmd_hdlr
 * DESCRIPTION
 *  ACRCP command handler
 * PARAMETERS
 *  command     [IN]     command type
 *  event       [IN]     key event
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
 U8 mmi_dtv_player_bt_avrcp_cmd_hdlr(U8 command, mmi_avrcp_key_events event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = MMI_AVRCP_CR_ACCEPT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (command)
    {
        case MMI_AVRCP_POP_PLAY:
        case MMI_AVRCP_POP_PAUSE:

            /* full screen */
            if (event == MMI_AVRCP_KEY_UP)
            {
                //mmi_vdoply_ck_release();
            }
            else if (event == MMI_AVRCP_KEY_DOWN)
            {
                //mmi_vdoply_ck_press();
            }
            else if (event == MMI_AVRCP_KEY_CANCELED)
            {
                //g_vdoply_cntx.touch_ck.is_press = MMI_FALSE;
                //mmi_vdoply_draw_fullscr_osd();
                //mmi_vdoply_blt_screen();
            }
            else
            {
                /* ingore others */
            }

            break;

        case MMI_AVRCP_POP_STOP:

            /*
           if (g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PLAY ||
                g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PAUSE ||
                g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_BT_CONNECTING ||
                g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_SEEKING ||
                g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PLAY_SEEKING ||
                g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_PLAY ||
                g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_CONNECTING ||
                g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_INTERRUPTED_CONNECTING ||
                g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_BUFFERING ||
                g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING)
                */

            {
                /* full screen */
                if (event == MMI_AVRCP_KEY_UP)
                {
                    //mmi_vdoply_rsk_release();
                }
                else if (event == MMI_AVRCP_KEY_DOWN)
                {
                    //mmi_vdoply_rsk_press();
                }
                else if (event == MMI_AVRCP_KEY_CANCELED)
                {
                    //g_vdoply_cntx.touch_rsk.is_press = MMI_FALSE;
                    //mmi_vdoply_draw_fullscr_osd();
                    //mmi_vdoply_blt_screen();
                }
                else
                {
                    /* ingore others */
                }
            }
            break;

        default:
            result = MMI_AVRCP_CR_NOT_IMPLEMENT;
            break;
    }

    return result;

}
#endif /* __MMI_AVRCP_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_enter_saving_screen
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_enter_saving_screen(void)
{
#ifdef __MMI_DTV_RECORD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_SAVING,
                NULL,
                mmi_dtv_player_enter_saving_screen,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    /* suspend background play */
    mdi_audio_suspend_background_play();

#if defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_DTV_LANDSCAPE_SUPPORT__)
    mmi_frm_screen_rotate(dtv_player_p->ui_rotate);
#endif /* defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_DTV_LANDSCAPE_SUPPORT__) */

    ShowCategory66Screen(
        STR_ID_DTV_PLAYER_APP_NAME,
        DTV_PLAYER_MENU_ICON,
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

    if (RECORDER_STATE_IN(DTV_RECORDER_SAVE_CONFIRM))
    {
        ret = mmi_dtv_player_recorder_enter_state(DTV_RECORDER_SAVING);
        if (ret != MDI_RES_MTV_SUCCEED)
        {
            mmi_dtv_player_display_popup(STR_GLOBAL_FAILED_TO_SAVE, MMI_EVENT_FAILURE);

            /* if has error, cant save, delete temp file */
            mdi_mtv_discard_unsaved_recording(dtv_player_p->mtv_handle);
            g_dtv_player_osd_cntx.record.status =  DTV_PLAYER_ICON_STATUS_DISABLE;
            g_dtv_player_osd_cntx_270.record.status =  DTV_PLAYER_ICON_STATUS_DISABLE;

            mmi_dtv_player_recorder_enter_state(DTV_RECORDER_STOPPED);

            /* delete save_confirm and saving screens */
            mmi_frm_scrn_multiple_close(
                GRP_ID_DTV_PLAYER,
                mmi_frm_scrn_get_active_id(),
                0,
                2,
                SCR_ID_INVALID,
                0);
        }

    }
    else
    {
        ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_SAVING);

        if (ret != MDI_RES_MTV_SUCCEED)
        {
            mmi_dtv_player_display_popup(STR_GLOBAL_FAILED_TO_SAVE, MMI_EVENT_FAILURE);
            /* if has error, cant save, delete temp file */
            mdi_mtv_discard_unsaved_recording(dtv_player_p->mtv_handle);

            /* Reset kernel to OPEN state */
            mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);

            /* delete save_confirm and saving screens */
            mmi_frm_scrn_multiple_close(
                GRP_ID_DTV_PLAYER,
                mmi_frm_scrn_get_active_id(),
                0,
                2,
                SCR_ID_INVALID,
                0);
        }
    }
#endif /* __MMI_DTV_RECORD_SUPPORT__  */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_deleting_screen_leave_proc
 * DESCRIPTION
 *  delete screen id callback handler of mtv player applications
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 mmi_ret mmi_dtv_player_deleting_screen_leave_proc(mmi_event_struct *para)
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
            if (KERNEL_STATE_IN(DTV_KERNEL_DELETING) ||
                RECORDER_STATE_IN(DTV_RECORDER_DELETING))
            {
                dtv_player_p->del_deleting_screen = MMI_TRUE;
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
 *  mmi_dtv_player_enter_deleting_screen
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_enter_deleting_screen(void)
{
#ifdef __MMI_DTV_RECORD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_DELETING,
                NULL,
                mmi_dtv_player_enter_deleting_screen,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    mmi_frm_scrn_set_leave_proc(
        GRP_ID_DTV_PLAYER,
        SCR_ID_DTV_PLAYER_DELETING,
        mmi_dtv_player_deleting_screen_leave_proc);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    /* suspend background play */
    mdi_audio_suspend_background_play();

#if defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_DTV_LANDSCAPE_SUPPORT__)
    mmi_frm_screen_rotate(dtv_player_p->ui_rotate);
#endif /* defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_DTV_LANDSCAPE_SUPPORT__) */

    ShowCategory66Screen(
        STR_ID_DTV_PLAYER_APP_NAME,
        DTV_PLAYER_MENU_ICON,
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

    dtv_player_p->del_deleting_screen = MMI_FALSE;
    if (KERNEL_STATE_IN(DTV_KERNEL_OPENED))
    {
        ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_DELETING);

        if (ret != MDI_RES_MTV_SUCCEED)
        {
            mmi_dtv_player_display_popup(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE);

            /* Reset kernel to OPEN state */
            mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);

            /* delete save_confirm and saving screens */
            mmi_frm_scrn_multiple_close(
                GRP_ID_DTV_PLAYER,
                mmi_frm_scrn_get_active_id(),
                0,
                2,
                SCR_ID_INVALID,
                0);
        }
    }
    else if (RECORDER_STATE_IN(DTV_RECORDER_SAVE_CONFIRM))
    {
        ret = mmi_dtv_player_recorder_enter_state(DTV_RECORDER_DELETING);
        if (ret != MDI_RES_MTV_SUCCEED)
        {
            mmi_dtv_player_display_popup(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE);

            mmi_dtv_player_recorder_enter_state(DTV_RECORDER_STOPPED);

            /* delete save_confirm and deleting screens */
            mmi_frm_scrn_multiple_close(
                GRP_ID_DTV_PLAYER,
                mmi_frm_scrn_get_active_id(),
                0,
                2,
                SCR_ID_INVALID,
                0);
        }
    }
#endif /* __MMI_DTV_RECORD_SUPPORT__  */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_exit_scan_channel
 * DESCRIPTION
 *  for first time init channel list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_exit_scan_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (KERNEL_STATE_IN(DTV_KERNEL_SCANNING))
    {
        mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);
        /* Reset service number as 0 because scan is aborted */
        dtv_player_p->num_services = 0;
    }

    mmi_dtv_player_free_detail_screen_memory();

    mmi_frm_end_scenario(MMI_SCENARIO_ID_HIGH_SCRN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_stop_scan
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_stop_scan(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(KERNEL_STATE_IN(DTV_KERNEL_SCANNING));

    mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);

    /* Reset service number as 0 because scan is aborted */
    dtv_player_p->num_services = 0;
    kal_mem_set(dtv_player_p->services, 0, MMI_DTV_MAX_SERVICES * sizeof(dtv_player_service_info_struct));



    dtv_player_p->num_favorite_services = 0;
    dtv_player_p->head_of_favorite_service = NULL;

    mmi_dtv_player_unset_flag(DTV_PLAYER_DELAY_UPDATE_EB_MSG);
    mmi_dtv_player_unset_flag(DTV_PLAYER_NEW_ESG_AVAILABLE);

    if (!mmi_frm_scrn_is_present(
            GRP_ID_DTV_PLAYER,
            SCR_ID_DTV_PLAYER_CHANNEL_LIST,
            MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_CLOSING);
        dtv_player_p->go_back_history = MMI_TRUE;
        ASSERT(ret==MDI_RES_MTV_SUCCEED);

        mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_APP_BASE);
    }

    mmi_frm_scrn_close_active_id();


}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_scan_str_ptr
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
void mmi_dtv_player_get_scan_str_ptr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
		mmi_ucs2cpy(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_2GPP_SCANNING));
		return;
    #endif


    if (dtv_player_p->ca_state != MMI_DTV_CA_STATE_CMMB)
    {
        if (mmi_frm_scrn_is_present(
            GRP_ID_DTV_PLAYER,
            SCR_ID_DTV_PLAYER_CHANNEL_LIST,
            MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
            mmi_ucs2cpy(
                dtv_player_p->detail_buf,
                GetString(STR_ID_DTV_PLAYER_NOTIFY_UPDATING));
        }
        else
        {
            if (mmi_ucs2strlen((CHAR*)dtv_player_p->info_str_buffer) == 0)
            {
                mmi_ucs2cpy(
                    dtv_player_p->detail_buf,
                    GetString(STR_ID_DTV_PLAYER_WELCOME_INFO));
            }
            else
            {
                mmi_ucs2cpy(
                    dtv_player_p->detail_buf,
                    (CHAR *)dtv_player_p->info_str_buffer);
            }
        }
    }
    else
    {
        if (dtv_player_p->setting.is_channel_list_init == MMI_FALSE)
        {
            mmi_ucs2cpy(
                dtv_player_p->detail_buf,
                GetString(STR_ID_DTV_PLAYER_NOTIFY_SCANNING));
        }
        else
        {
            mmi_ucs2cpy(
                dtv_player_p->detail_buf,
                GetString(STR_ID_DTV_PLAYER_NOTIFY_INITIALIZING));
        }
    }

    mmi_ucs2cat(
        dtv_player_p->detail_buf,
        (CHAR *)L"\n\n");

    /* pull out antenna */
    mmi_ucs2cat(
        dtv_player_p->detail_buf,
        (CHAR *)GetString(STR_ID_DTV_PULL_OUT_ANTENNA));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_update_scan_progress
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_update_scan_progress(S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen = mmi_frm_scrn_get_active_id();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Update progressive value */
    dtv_player_p->scan_progress = value;

    if (active_screen == SCR_ID_DTV_PLAYER_SCANNING)
    {
        Cat412UpdateList(
            (UI_string_type)dtv_player_p->detail_buf,
            dtv_player_p->scan_progress, 0, 0);
    }
    else if (active_screen == SCR_ID_DTV_PLAYER_ESG_DOWNLOAD)
    {
        Cat412UpdateList(
            (UI_string_type)GetString(STR_ID_DTV_PLAYER_DOWNLOADING_SERVICE_GUIDE),
            dtv_player_p->scan_progress, 0, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_enter_scan_channel
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_enter_scan_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 rsk_id = 0;
    MDI_RESULT ret;
    PU8 img_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_SCANNING,
                mmi_dtv_player_exit_scan_channel,
                mmi_dtv_player_enter_scan_channel,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    /* suspend background play */
    mdi_audio_suspend_background_play();

    mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGH_SCRN);

    /* Delete band screen */
    if (!mmi_frm_scrn_is_present(
            GRP_ID_DTV_PLAYER,
            SCR_ID_DTV_PLAYER_CHANNEL_LIST,
            MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_BAND);
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();   


    if (mmi_frm_scrn_is_present(
        GRP_ID_DTV_PLAYER,
        SCR_ID_DTV_PLAYER_CHANNEL_LIST,
        MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        rsk_id = 0; /* NO RSK */
    }
    else
    {
        /* Get welcome info */
        if (dtv_player_p->ca_state != MMI_DTV_CA_STATE_CMMB && guiBuffer == NULL)
        {
            mmi_dtv_player_query_sgdd_info(
                MMI_DTV_SGDD_WELCOME_INFO, dtv_player_p->info_str_buffer, MMI_DTV_INFO_STR_LENGTH);
        }
        rsk_id = STR_GLOBAL_CANCEL;
    }

    /* Allocate detail buffer */
    mmi_dtv_player_alloc_detail_screen_memory();

    mmi_dtv_player_get_scan_str_ptr();

    /* Initialize parameter */
    dtv_player_p->scan_progress = 0;


    img_ptr = (PU8)GetImage(IMG_ID_DTV_PLAYER_INITIALIZING);


    wgui_cat1040_show(
#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__		
        (UI_string_type)GetString(STR_ID_DTV_CMMB_2GPP_APP_NAME),
#else	
		(UI_string_type)GetString(STR_ID_DTV_PLAYER_APP_NAME),
#endif
        (PU8)GetImage(DTV_PLAYER_MENU_ICON),
        0,
        0,
        (UI_string_type)GetString(rsk_id),
        0,
        img_ptr,
        (UI_string_type)dtv_player_p->detail_buf,
        dtv_player_p->scan_progress,
        0,
        0,
        guiBuffer);

    /* Initialize parameter before entry service scanning state */
    dtv_player_p->num_favorite_services = 0;
    dtv_player_p->head_of_favorite_service = NULL;

    mmi_dtv_player_unset_flag(DTV_PLAYER_DELAY_UPDATE_EB_MSG);
    mmi_dtv_player_unset_flag(DTV_PLAYER_NEW_ESG_AVAILABLE);

    if (dtv_player_p->ca_state != MMI_DTV_CA_STATE_CMMB)
    {
        dtv_player_p->ca_state = MMI_DTV_CA_STATE_MBBMS;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_CA_STATE, dtv_player_p->ca_state);
    }
    dtv_player_p->num_services = 0;
    kal_mem_set(dtv_player_p->services, 0, MMI_DTV_MAX_SERVICES * sizeof(dtv_player_service_info_struct));

    ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_SCANNING);

    if (ret != MDI_RES_MTV_SUCCEED)
    {
        /* Close channel list screen first to avoid re-entry*/
        mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_CHANNEL_LIST);

        mmi_dtv_player_entry_channel_list_screen();

        if (dtv_player_p->cl_option_menu_gid != GRP_ID_INVALID)
        {
            cui_menu_close(dtv_player_p->cl_option_menu_gid);
            dtv_player_p->cl_option_menu_gid = GRP_ID_INVALID;
        }
        mmi_frm_scrn_multiple_close(
                GRP_ID_DTV_PLAYER,
                mmi_frm_scrn_get_active_id(),
                0,
                0,
                SCR_ID_DTV_PLAYER_APP_BASE,
                0);
    }
    else
    {
        if (dtv_player_p->ca_state != MMI_DTV_CA_STATE_CMMB)
        {
            StartTimer(
                DTV_PLAYER_UPDATE_SCAN_STATUS, 1000,
                mmi_dtv_player_gen_scan_progress);
        }

        if (rsk_id != 0)
        {
            SetRightSoftkeyFunction(mmi_dtv_player_stop_scan, KEY_EVENT_UP);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_save_confirm_screen_leave_proc
 * DESCRIPTION
 *  delete screen id callback handler of mtv player applications
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 mmi_ret mmi_dtv_player_save_confirm_screen_leave_proc(mmi_event_struct *para)
{
#ifdef __MMI_DTV_RECORD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (para->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
            /* reset parameter */
            if (RECORDER_STATE_IN(DTV_RECORDER_SAVE_CONFIRM))
            {
                RECORDER_ENTER_STATE(DTV_RECORDER_STOPPED);
            }
            break;
        }
        default:
            break;
    }
#endif /* __MMI_DTV_RECORD_SUPPORT__ */
    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mev_player_enter_save_confirm
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_enter_save_confirm(void)
{
#ifdef __MMI_DTV_RECORD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;
    U8* guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_SAVE_CONFIRM,
                NULL,
                mmi_dtv_player_enter_save_confirm,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    mmi_frm_scrn_set_leave_proc(
        GRP_ID_DTV_PLAYER,
        SCR_ID_DTV_PLAYER_SAVE_CONFIRM,
        mmi_dtv_player_save_confirm_screen_leave_proc);

    /* suspend background play */
    mdi_audio_suspend_background_play();

#if defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_DTV_LANDSCAPE_SUPPORT__)
    mmi_frm_screen_rotate(dtv_player_p->ui_rotate);
#endif /* defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_DTV_LANDSCAPE_SUPPORT__) */

    if (RECORDER_STATE_IN(DTV_RECORDER_SAVE_CONFIRM))
    {
        str_id = STR_ID_DTV_PLAYER_SAVE_RECORDING;
    }
    else
    {
        str_id = STR_ID_DTV_PLAYER_SAVE_UNSAVED_RECORDING;
    }

    /* Call enable before showCategory, call change after showCategory */
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory66Screen(
        STR_ID_DTV_PLAYER_APP_NAME,
        DTV_PLAYER_MENU_ICON,
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU8) GetString(str_id),
        mmi_get_event_based_image(MMI_EVENT_QUERY),
        guiBuffer);

#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
    /* Don't play tone when re-entry */
    if (guiBuffer == NULL)
    {
        /* Help MED to start time shift */
        if (RECORDER_STATE_IN(DTV_RECORDER_SAVE_CONFIRM) && PLAYER_STATE_IN(DTV_PLAYER_STOPPED))
        {
            mdi_mtv_start_timeshift(dtv_player_p->mtv_handle);
        }
    }
#endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */

    SetRightSoftkeyFunction(mmi_dtv_player_enter_deleting_screen, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_dtv_player_enter_saving_screen, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_dtv_player_enter_saving_screen, KEY_EVENT_UP);
#endif /* __MMI_DTV_RECORD_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_check_storage
 * DESCRIPTION
 *  mmi_dtv_player_check_storage
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 mmi_event_notify_enum mmi_dtv_player_check_storage(MMI_BOOL restore, U16 storage)
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

#if defined (__MMI_BT_SUPPORT__)
    if (mmi_bt_is_receiving())
    {
        dtv_player_p->storage_status = DTV_PLAYER_STORAGE_RESET;
        dtv_player_p->err_str_id = STR_ID_DTV_PLAYER_NOTIFY_BT_IS_WORKING;
        return MMI_EVENT_FAILURE;
    }
#endif /* __MMI_BT_SUPPORT__  */

    memset(dtv_player_p->storage_filepath , 0, SRV_FMGR_PATH_BUFFER_SIZE);

    dtv_player_p->prev_storage_status = dtv_player_p->storage_status;

    /* check storage */
    if (mmi_dtv_player_check_and_restore_valid_drv(restore, storage))
    {
    #if defined(__MDI_DTV_TIME_SHIFT_SUPPORT__) || defined(__MMI_DTV_RECORD_SUPPORT__)
        /* drv is valid, create video directory */
        mmi_dtv_player_get_storage_file_path(storage, dtv_player_p->storage_filepath, DTV_PLAYER_STORAGE_PATH_VIDEO);
        video_ret = mmi_dtv_player_create_file_dir(dtv_player_p->storage_filepath);
    #endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ || __MMI_DTV_RECORD_SUPPORT__ */
    #if defined(__MMI_DTV_SNAPSHOT_SUPPORT__)
        /* drv is valid, create video directory */
        mmi_dtv_player_get_storage_file_path(storage, tmp_filepath, DTV_PLAYER_STORAGE_PATH_PHOTO);
        photo_ret = mmi_dtv_player_create_file_dir(tmp_filepath);
    #endif
        if (video_ret == FS_NO_ERROR && photo_ret == FS_NO_ERROR)
        {
            dtv_player_p->storage_status = DTV_PLAYER_STORAGE_OK;
            dtv_player_p->last_error = MDI_RES_MTV_SUCCEED;
        }
        else
        {
            dtv_player_p->storage_status = DTV_PLAYER_STORAGE_NOT_READY;
            err_ret = (video_ret == FS_NO_ERROR) ? photo_ret : video_ret;
            dtv_player_p->err_str_id =
                srv_fmgr_fs_error_get_string_and_popup_type(err_ret, (S32*)&event_type);
        }
    }
    else
    {
        /* drv no valid, means card is plugged out (or phone FAT corrupted) */
        dtv_player_p->storage_status = DTV_PLAYER_STORAGE_RESET;
        dtv_player_p->last_error = MDI_RES_MTV_ERR_STORAGE_NOT_READY;
        dtv_player_p->err_str_id = mdi_util_get_mdi_error_info(dtv_player_p->last_error, &event_type);
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_CHECK_STORAGE, restore, dtv_player_p->prev_storage_status, dtv_player_p->storage_status);

    return event_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_enable_timeshift_function
 * DESCRIPTION
 *  mmi_dtv_player_enable_timeshift_function
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_enable_timeshift_function(void)
{
#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dtv_player_osd_cntx.forward.status =  DTV_PLAYER_ICON_STATUS_ENABLE;
    g_dtv_player_osd_cntx_270.forward.status =  DTV_PLAYER_ICON_STATUS_ENABLE;
    g_dtv_player_osd_cntx.rewind.status =  DTV_PLAYER_ICON_STATUS_ENABLE;
    g_dtv_player_osd_cntx_270.rewind.status =  DTV_PLAYER_ICON_STATUS_ENABLE;

    g_dtv_player_osd_cntx.record.status =  DTV_PLAYER_ICON_STATUS_ENABLE;
    g_dtv_player_osd_cntx_270.record.status =  DTV_PLAYER_ICON_STATUS_ENABLE;
#endif /* #ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__  */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_disable_timeshift_function
 * DESCRIPTION
 *  mmi_dtv_player_disable_timeshift_function
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_disable_timeshift_function(void)
{
#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dtv_player_osd_cntx.forward.status =  DTV_PLAYER_ICON_STATUS_DISABLE;
    g_dtv_player_osd_cntx_270.forward.status =  DTV_PLAYER_ICON_STATUS_DISABLE;
    g_dtv_player_osd_cntx.rewind.status =  DTV_PLAYER_ICON_STATUS_DISABLE;
    g_dtv_player_osd_cntx_270.rewind.status =  DTV_PLAYER_ICON_STATUS_DISABLE;
    g_dtv_player_osd_cntx.record.status =  DTV_PLAYER_ICON_STATUS_DISABLE;
    g_dtv_player_osd_cntx_270.record.status =  DTV_PLAYER_ICON_STATUS_DISABLE;

    /* Avoid snapshot when record key is released and avoid start record */
    if (dtv_player_p->touch_object == DTV_PLAYER_TOUCH_RECORD)
    {
        dtv_player_p->touch_object = DTV_PLAYER_TOUCH_NONE;
        gui_cancel_timer(mmi_dtv_player_record_start_record);
    }
#endif /* #ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_enable_play_function
 * DESCRIPTION
 *  mmi_dtv_player_enable_play_function
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_enable_play_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_DTV_BLOCK_BG_CALL__
    if (mmi_dtv_player_is_in_background_call())
    {
        g_dtv_player_osd_cntx.play.status =  DTV_PLAYER_ICON_STATUS_DISABLE;
        g_dtv_player_osd_cntx_270.play.status =  DTV_PLAYER_ICON_STATUS_DISABLE;
    }
    else
#endif /* __MMI_DTV_BLOCK_BG_CALL__ */
    {
        g_dtv_player_osd_cntx.play.status =  DTV_PLAYER_ICON_STATUS_ENABLE;
        g_dtv_player_osd_cntx_270.play.status =  DTV_PLAYER_ICON_STATUS_ENABLE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_disable_play_function
 * DESCRIPTION
 *  mmi_dtv_player_disable_play_function
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_disable_play_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_dtv_player_osd_cntx.play.status =  DTV_PLAYER_ICON_STATUS_DISABLE;
    g_dtv_player_osd_cntx_270.play.status =  DTV_PLAYER_ICON_STATUS_DISABLE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_enable_record_function
 * DESCRIPTION
 *  mmi_dtv_player_enable_record_function
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_enable_record_function(void)
{
#if defined(__MMI_DTV_RECORD_SUPPORT__) || defined(__MMI_DTV_SNAPSHOT_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dtv_player_osd_cntx.record.status =  DTV_PLAYER_ICON_STATUS_ENABLE;
    g_dtv_player_osd_cntx_270.record.status =  DTV_PLAYER_ICON_STATUS_ENABLE;
#endif /* __MMI_DTV_RECORD_SUPPORT__ || __MMI_DTV_SNAPSHOT_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_disable_record_function
 * DESCRIPTION
 *  mmi_dtv_player_disable_record_function
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_disable_record_function(void)
{
#if defined(__MMI_DTV_RECORD_SUPPORT__) || defined(__MMI_DTV_SNAPSHOT_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dtv_player_osd_cntx.record.status =  DTV_PLAYER_ICON_STATUS_DISABLE;
    g_dtv_player_osd_cntx_270.record.status =  DTV_PLAYER_ICON_STATUS_DISABLE;

    /* Avoid snapshot when record key is released and avoid start record */
    if (dtv_player_p->touch_object == DTV_PLAYER_TOUCH_RECORD)
    {
        dtv_player_p->touch_object = DTV_PLAYER_TOUCH_NONE;
        gui_cancel_timer(mmi_dtv_player_record_start_record);
    }
#endif /* __MMI_DTV_RECORD_SUPPORT__ || __MMI_DTV_SNAPSHOT_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_enable_switch_channel_function
 * DESCRIPTION
 *  mmi_dtv_player_enable_switch_channel_function
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_enable_switch_channel_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dtv_player_osd_cntx.channel_next.status =  DTV_PLAYER_ICON_STATUS_ENABLE;
    g_dtv_player_osd_cntx_270.channel_next.status =  DTV_PLAYER_ICON_STATUS_ENABLE;
    g_dtv_player_osd_cntx.channel_prev.status =  DTV_PLAYER_ICON_STATUS_ENABLE;
    g_dtv_player_osd_cntx_270.channel_prev.status =  DTV_PLAYER_ICON_STATUS_ENABLE;
    g_dtv_player_osd_cntx.cycle.status =  DTV_PLAYER_ICON_STATUS_ENABLE;
    g_dtv_player_osd_cntx_270.cycle.status =  DTV_PLAYER_ICON_STATUS_ENABLE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_disable_switch_channel_function
 * DESCRIPTION
 *  mmi_dtv_player_disable_switch_channel_function
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_disable_switch_channel_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dtv_player_osd_cntx.channel_next.status =  DTV_PLAYER_ICON_STATUS_DISABLE;
    g_dtv_player_osd_cntx_270.channel_next.status =  DTV_PLAYER_ICON_STATUS_DISABLE;
    g_dtv_player_osd_cntx.channel_prev.status =  DTV_PLAYER_ICON_STATUS_DISABLE;
    g_dtv_player_osd_cntx_270.channel_prev.status =  DTV_PLAYER_ICON_STATUS_DISABLE;
    g_dtv_player_osd_cntx.cycle.status =  DTV_PLAYER_ICON_STATUS_DISABLE;
    g_dtv_player_osd_cntx_270.cycle.status =  DTV_PLAYER_ICON_STATUS_DISABLE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_enable_fullscreen_function
 * DESCRIPTION
 *  mmi_dtv_player_enable_fullscreen_function
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_enable_fullscreen_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* If user long presses fullscreen icon, then time-shift is enabled.
       Don't change full screen status as enable */
    if (dtv_player_p->active_osd_cntx_p->fullscreen.status == DTV_PLAYER_ICON_STATUS_CLICKED)
    {
        return;
    }

    g_dtv_player_osd_cntx.fullscreen.status =  DTV_PLAYER_ICON_STATUS_ENABLE;
    g_dtv_player_osd_cntx_270.fullscreen.status =  DTV_PLAYER_ICON_STATUS_ENABLE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_enable_lsk_function
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_enable_lsk_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_dtv_player_osd_cntx.lsk.status =  DTV_PLAYER_ICON_STATUS_ENABLE;
    g_dtv_player_osd_cntx_270.lsk.status =  DTV_PLAYER_ICON_STATUS_ENABLE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_disable_lsk_function
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_disable_lsk_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_dtv_player_osd_cntx.lsk.status = DTV_PLAYER_ICON_STATUS_DISABLE;
    g_dtv_player_osd_cntx_270.lsk.status = DTV_PLAYER_ICON_STATUS_DISABLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_disable_fullscreen_function
 * DESCRIPTION
 *  mmi_dtv_player_disable_fullscreen_function
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_disable_fullscreen_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dtv_player_osd_cntx.fullscreen.status =  DTV_PLAYER_ICON_STATUS_DISABLE;
    g_dtv_player_osd_cntx_270.fullscreen.status =  DTV_PLAYER_ICON_STATUS_DISABLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_del_app_main_scr_hdlr
 * DESCRIPTION
 *  mmi_dtv_player_del_app_main_scr_hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_del_app_main_scr_hdlr(void *dummy_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_DEL_APP_MAIN_SCR_HDLR);

    if (!PLAYER_STATE_IN(DTV_PLAYER_STOPPED))
    {
        mmi_dtv_player_player_enter_state(DTV_PLAYER_STOPPED);
    }

    if (RECORDER_STATE_IN(DTV_RECORDER_STOPPED))
    {
        if (!KERNEL_STATE_IN(DTV_KERNEL_CLOSED) && !KERNEL_STATE_IN(DTV_KERNEL_CLOSING))
        {
            mmi_dtv_player_kernel_enter_state(DTV_KERNEL_CLOSING);
        }

        /* hide status icon */
        wgui_status_icon_bar_hide_icon(STATUS_ICON_DTV_SIGNAL);
        StopTimer(DTV_PLAYER_UPDATE_SIGNAL_TIMER);

    }

    /* save setting */
    mmi_dtv_player_store_setting();

    mmi_dtv_player_unset_flag(DTV_PLAYER_IS_STORAGE_CHECK);
    mmi_dtv_player_unset_flag(DTV_PLAYER_DELAY_DISPLAY_RECORD_ERROR);

    /* unmute */
    mdi_audio_set_mute(MDI_VOLUME_MEDIA, MMI_FALSE);

    StopTimer(DTV_PLAYER_NW_STATUS);

    /* resume background play only when exit mobile tv application */
    mdi_audio_resume_background_play();

    if (KERNEL_STATE_IN(DTV_KERNEL_CLOSING))
    {
        dtv_player_p->del_main_screen = MMI_TRUE;
        return MMI_TRUE;
    }
    else
    {
        mmi_frm_group_close(GRP_ID_DTV_PLAYER);
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_player_status
 * DESCRIPTION
 *  get player state.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_get_player_status(U32 mtv_handle, mdi_mtv_player_state_enum *state, U32* play_delay, U32* max_delay, U32* buf_duration, S32* play_rate)
{
#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_mtv_player_status_struct status;

    mdi_mtv_player_get_status(mtv_handle, &status);

    if (state != NULL)
        *state = status.state;

    if (play_delay != NULL)
        *play_delay = status.play_delay;

    if (max_delay != NULL)
        *max_delay = status.max_delay;

    if (buf_duration != NULL)
        *buf_duration = status.buffer_duration;

    if (play_rate != NULL)
        *play_rate = status.play_rate;
#endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */
}


#ifdef __BT_SPK_VOL_CONTROL__
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_bt_volume_sync_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_bt_volume_sync_hdlr(U8 volume, MMI_BOOL is_mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_BT_VOLUME_SYNC_HDLR, volume, is_mute);

    /* Active screen is mobile tv main screen or channel list screen */
    if (active_screen == SCR_ID_DTV_PLAYER_APP || active_screen == SCR_ID_DTV_PLAYER_CHANNEL_LIST)
    {
        dtv_player_p->setting.vol_level = volume;
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, (U8) MDI_AUD_VOL_EX_MUTE(dtv_player_p->setting.vol_level));
        dtv_player_p->setting.is_mute = KAL_FALSE;

        /* Update OSD */
        if (active_screen == SCR_ID_DTV_PLAYER_APP)
        {
            mmi_dtv_player_draw_osd_and_blt();
        }

        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}
#endif

/*****************************************************************************
 * FunctionName: mmi_dtv_player_test_frequency_proc
 * Description
 *     
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-02-13
 *****************************************************************************/
mmi_ret mmi_dtv_player_test_frequency_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cui_event_inline_submit_struct * submit_evt = NULL;
	cui_event_inline_abort_struct * abort_evt = NULL;
    U8 inline_frequency[(MMI_DTV_MAX_FREQUENCY_LEN)*ENCODING_LENGTH];
	cui_event_inline_common_struct * common_evt = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
			{
				common_evt = (cui_event_inline_common_struct *)evt;
				app_ucs2_itoa(g_test_frequency, (kal_int8 *)inline_frequency, 10);
		        cui_inline_set_value(common_evt->sender_id,
					                 MMI_DTV_TEST_MODE_SET_EDIT,
		                             (void *)inline_frequency);
				break;
        	}
        case EVT_ID_CUI_INLINE_SUBMIT:
	        {
				submit_evt = (cui_event_inline_submit_struct *)evt;				
				cui_inline_get_value(submit_evt->sender_id, 
					                 MMI_DTV_TEST_MODE_SET_EDIT, 
					                 (void *) inline_frequency);
				g_test_frequency = gui_atoi((UI_string_type)&inline_frequency);
				if (g_test_frequency > 0)
				{			
					mmi_dtv_player_enter_app_main();
					cui_inline_close(submit_evt->sender_id);				
				}
				else
				{				
					mmi_dtv_player_display_popup(STR_ID_DTV_INVALID_FREQUENCY, 
						                         MMI_EVENT_ERROR);
				}
				break;
    	    }
		case EVT_ID_CUI_INLINE_ABORT:
		case EVT_ID_CUI_INLINE_GROUP_DEINIT:
			{
				abort_evt = (cui_event_inline_abort_struct*)evt;				
				mmi_dtv_player_enter_app_main();
				cui_inline_close(abort_evt->sender_id);
			}
        default:
			{
            	break;
        	}
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FunctionName: mmi_dtv_player_set_test_frequency
 * Description
 *     
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-02-13
 *****************************************************************************/
void mmi_dtv_player_set_test_frequency(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID inline_id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    mmi_frm_group_create(GRP_ID_DTV_PLAYER, 
                         GRP_ID_DTV_PLAYER_FREQUENCY_MODE, 
                         mmi_dtv_player_test_frequency_proc, 
                         (void*)NULL);
    mmi_frm_group_enter(GRP_ID_DTV_PLAYER_FREQUENCY_MODE, 
		                MMI_FRM_NODE_SMART_CLOSE_FLAG);

    inline_id = cui_inline_create(GRP_ID_DTV_PLAYER_FREQUENCY_MODE, 
		                          &g_dtv_test_mode_setting);
    if (inline_id > GRP_ID_INVALID)
    {
		cui_inline_set_title_string(inline_id,
			                        get_string(STR_ID_DTV_PLAYER_TEST_SET));
		
        cui_inline_run(inline_id);
    }
    else
    {
        mmi_dtv_player_display_popup(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE);
    }
}

#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
/*****************************************************************************
 * FunctionName: mmi_dtv_player_2gpp_call_cbc_service_hotline
 * Description
 *     
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-05-09
 *****************************************************************************/
void mmi_dtv_player_2gpp_call_cbc_service_hotline(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_ucm_make_call_para_struct make_call_para;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	#ifdef __MMI_UCM__
	mmi_ucm_init_call_para_for_sendkey(&make_call_para);  
	make_call_para.adv_para.after_make_call_callback = NULL;
	make_call_para.dial_type = SRV_UCM_CALL_TYPE_ALL;
	make_call_para.ucs2_num_uri = (U16*)CBC_Hotline_number;
	mmi_ucm_call_launch(0, &make_call_para);
	#else
	MakeCall((CHAR*) CBC_Hotline_number);
	#endif
	
}



/*****************************************************************************
 * FunctionName: mmi_dtv_player_exit_tab_account_manage_screen
 * Description
 *     
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-04-23
 *****************************************************************************/
void mmi_dtv_player_exit_tab_account_manage_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    mmi_frm_end_scenario(MMI_SCENARIO_ID_HIGH_SCRN);	
	mmi_dtv_player_free_detail_screen_memory();
}



/*****************************************************************************
 * FunctionName: mmi_dtv_player_entry_tab_account_manage_screen
 * Description
 *     
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-04-23
 *****************************************************************************/
void mmi_dtv_player_entry_tab_account_manage_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 *guiBuffer = NULL;
	S32 error = 0;
	S32 state = 0;
	U16 serial[40];
	U8  result = 0;
	UI_string_type lsk = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!mmi_frm_scrn_tab_page_enter(GRP_ID_DTV_PLAYER,
								     SCR_ID_DTV_PLAYER_CHANNEL_LIST,
									 SCR_ID_DTV_PLAYER_TAB_ACCOUNT_MANAGE,
									 mmi_dtv_player_exit_tab_account_manage_screen,
									 mmi_dtv_player_entry_tab_account_manage_screen,
									 MMI_FRM_TAB_PAGE))
	{
		return;
	}

    guiBuffer = mmi_frm_scrn_tab_page_get_active_gui_buf();	
    mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGH_SCRN);
    /* suspend background play */
    mdi_audio_suspend_background_play();	

	dtv_player_p->service_list_type = DTV_PLAYER_ACCOUNT_MANAGE_TEXT;

	mmi_dtv_player_alloc_detail_screen_memory();

	result = mmi_cmmb_2gpp_adp_get_CaInfo(&state, serial);

	MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_DTV_VAL2, result, state,__LINE__);

	if (result)
	{
		if (state)
		{			
			mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_SERIAL_NUMBER));
			mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");
		}
		else
		{
			mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_INVALID_SERIAL_NUMBER));
			mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");
			lsk = (UI_string_type)GetString(STR_ID_DTV_2GPP_CALL);
		}
		
		mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)serial);
	}

	wgui_cat3002_show((UI_string_type)GetString(STR_ID_DTV_CMMB_2GPP_APP_NAME),
		              lsk,
		              (UI_string_type)GetString(STR_GLOBAL_EXIT),
		              DTV_PLAYER_ACCOUNT_MANAGE_TEXT,
		              MMI_FALSE,
		              (UI_buffer_type)dtv_player_p->detail_buf,
					  mmi_ucs2strlen((CHAR *)dtv_player_p->detail_buf),
		              guiBuffer);

	#ifdef __MMI_TOUCH_SCREEN__
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
	#endif /* __MMI_TOUCH_SCREEN__ */	
	SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);	

	if (NULL != lsk)
	{
		SetLeftSoftkeyFunction(mmi_dtv_player_2gpp_call_cbc_service_hotline, KEY_EVENT_UP);
	}
	SetRightSoftkeyFunction(mmi_dtv_player_exit_confirm, KEY_EVENT_UP);
}

/*****************************************************************************
 * FunctionName: mmi_dtv_player_exit_2gpp_service_terms_screen
 * Description
 *     
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-04-23
 *****************************************************************************/
void mmi_dtv_player_exit_2gpp_service_terms_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
/*****************************************************************************
 * FunctionName: mmi_dtv_player_2gpp_exit_app
 * Description
 *     
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-04-23
 *****************************************************************************/
void mmi_dtv_player_2gpp_exit_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_group_close(GRP_ID_DTV_PLAYER);
}
/*****************************************************************************
 * FunctionName: mmi_dtv_player_2gpp_service_terms_lsk_func
 * Description
 *     
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-05-14
 *****************************************************************************/
void mmi_dtv_player_2gpp_service_terms_lsk_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	mmi_cmmb_2gpp_adp_notify(EVT_ID_CMMB_2GPP_MMI_CONFIRM_PTL,0,NULL);
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_DTV_VAL1, 11111,__LINE__);
	mmi_dtv_player_enter_app_main();
}

/*****************************************************************************
 * FunctionName: mmi_dtv_player_entry_2gpp_service_terms_screen
 * Description
 *  Display the CMMB_CAS_2GPP service terms screen   
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-04-23
 *****************************************************************************/
void mmi_dtv_player_entry_2gpp_service_terms_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 *guiBuffer = NULL;
	WCHAR * Protocol_String = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(GRP_ID_DTV_PLAYER,
                			SCR_ID_DTV_PLAYER_CMMB_SERVICE_TERMS,
			                mmi_dtv_player_exit_2gpp_service_terms_screen,
            			    mmi_dtv_player_entry_2gpp_service_terms_screen,
			                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
	Protocol_String = mmi_cmmb_2gpp_adp_get_PTL_string();

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_DTV_VAL2, 2222222, Protocol_String,__LINE__);	

    wgui_cat3005_show((UI_string_type)GetString(STR_ID_DTV_CMMB_SERVICE_TERMS),
        			  NULL,
                      (UI_string_type)GetString(STR_GLOBAL_OK),
                      (PU8)GetImage(IMG_GLOBAL_OK),
        			  (UI_string_type)GetString(STR_GLOBAL_BACK),
                      (PU8)GetImage(IMG_GLOBAL_BACK),
                      (UI_buffer_type)Protocol_String,
					  mmi_ucs2strlen((CHAR *) Protocol_String),
                      guiBuffer);
#ifdef __MTK_TARGET__
	SetLeftSoftkeyFunction(mmi_dtv_player_2gpp_service_terms_lsk_func,KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_dtv_player_2gpp_service_terms_lsk_func,KEY_EVENT_UP);
#else
	SetLeftSoftkeyFunction(mmi_dtv_player_enter_app_main,KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_dtv_player_enter_app_main,KEY_EVENT_UP);
#endif
    SetRightSoftkeyFunction(mmi_dtv_player_2gpp_exit_app, KEY_EVENT_UP);
	
}
#endif /* __MMI_CMMB_CAS_2GPP_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_launch
 * DESCRIPTION
 *  functions to launch mobile tv player
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_launch_int(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(APP_DTV_PLAYER, GRP_ID_DTV_PLAYER, mmi_dtv_player_group_proc, NULL);
    mmi_frm_group_enter(GRP_ID_DTV_PLAYER, MMI_FRM_NODE_NONE_FLAG);

#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
    mmi_cmmb_init_2gpp_adp();
    result = mmi_cmmb_2gpp_adp_get_ShowServiceTerms();
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_DTV_VAL1, result,__LINE__);    
	if(result)
	{
		mmi_dtv_player_entry_2gpp_service_terms_screen();
	}
	else
	{		
		mmi_dtv_player_enter_app_main();		
	}
	return;
#endif

#ifdef __MBBMS_DUAL_SIM_SUPPORT__
	mmi_dtv_player_load_setting();
	if ((MMI_SIM_NONE == dtv_player_p->setting.simcard)
		&& (SRV_NW_INFO_SA_FULL_SERVICE == srv_nw_info_get_service_availability(MMI_SIM1))
		&& (SRV_NW_INFO_SA_FULL_SERVICE == srv_nw_info_get_service_availability(MMI_SIM2)))
	{
		mmi_dtv_player_display_confirm(STR_ID_DTV_SIM_CHOOSE_NOTIFY);
	}
#endif
    if (DTV_CMMB_TEST_MODE_ON_SITE == g_cmmb_test_mode)
    {
    	mmi_dtv_player_set_test_frequency();
	}
	else
	{
		mmi_dtv_player_enter_app_main();
	}
}

MMI_RET mmi_dtv_app_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_APP_POST_ENTER:
        {
			/* yaling	*/
            mmi_frm_asm_property_struct p;
            mmi_frm_asm_get_property(APP_DTV_PLAYER, &p);
            p.f_prepare_w_reserve = 0;
            mmi_frm_asm_set_property(APP_DTV_PLAYER, &p);
		

            mmi_dtv_player_launch_int();
            break;
        }

        case EVT_ID_APP_FORCE_CLOSE:
        {
            mmi_dtv_player_terminate_app();
            if (KERNEL_STATE_IN(DTV_KERNEL_CLOSING))
            {
                dtv_player_p->app_mem_force_release = KAL_TRUE;
                return MMI_APP_CLOSE_ANSWER_LATER;
            }
        }
    }
    return MMI_RET_OK;
}

void mmi_dtv_player_launch(void)
{
    mmi_frm_app_launch(APP_DTV_PLAYER, 0, 0, mmi_dtv_app_proc, NULL, 0);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_base_screen_leave_proc
 * DESCRIPTION
 *  This function is the callback funcion for deleting idle notify screen
 * PARAMETERS
 *  p
 * RETURNS
 *  U8
 *****************************************************************************/
 mmi_ret mmi_dtv_player_base_screen_leave_proc(mmi_event_struct *para)
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
            ret = mmi_dtv_player_del_app_main_scr_hdlr(NULL);
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
 *  mmi_dtv_player_hw_not_ready_popup_proc
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
 mmi_ret mmi_dtv_player_hw_not_ready_popup_proc(mmi_event_struct *evt)
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
            mmi_frm_group_close(GRP_ID_DTV_PLAYER);
            break;
        }
        default:
        break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_enter_app_main
 * DESCRIPTION
 *  mobile tv player entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_enter_app_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    mmi_popup_property_struct arg;
	MMI_BOOL restore = MMI_FALSE;
	MDI_RESULT ret =  MDI_RES_MTV_SUCCEED;
#ifdef	__MDI_DTV_TIME_SHIFT_SUPPORT__
	mmi_event_notify_enum event_type = MMI_EVENT_DEFAULT;
#endif
#ifdef __MBBMS_CITY_LIST__
	S32 idx;	
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef  __MMI_DTV_BLOCK_BG_CALL__
    if (mmi_dtv_player_is_in_background_call() && KERNEL_STATE_IN(DTV_KERNEL_CLOSED))
    {
        mmi_ucm_app_entry_error_message();
        return; /* return directly */
    }
#endif /* __MMI_DTV_BLOCK_BG_CALL__ */

    /* allocate memory from App-Based ASM */
    if (dtv_player_p->app_mem_pool==NULL)
    {
        dtv_player_p->app_mem_pool =
            (PU8) applib_asm_alloc_r(GRP_ID_DTV_PLAYER, MMI_DTV_PLAYER_APP_MEM_SIZE);
        ASSERT(dtv_player_p->app_mem_pool != NULL);
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_ENTER_APP_MAIN);

    result = mmi_frm_scrn_enter(
            GRP_ID_DTV_PLAYER,
            SCR_ID_DTV_PLAYER_APP_BASE,
            NULL,
            mmi_dtv_player_enter_app_main,
            MMI_FRM_UNKNOW_SCRN);

    if (result == MMI_FALSE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL1, result, __LINE__);
        return;
    }

    mmi_frm_scrn_set_leave_proc(
        GRP_ID_DTV_PLAYER,
        SCR_ID_DTV_PLAYER_APP_BASE,
        mmi_dtv_player_base_screen_leave_proc);

    if (KERNEL_STATE_IN(DTV_KERNEL_CLOSING))
    {
#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__			
		ShowCategory66Screen(STR_ID_DTV_CMMB_2GPP_APP_NAME,
 						     DTV_PLAYER_MENU_ICON,
 				             STR_ID_DTV_PLAYER_NULL,
 				             IMG_ID_DTV_PLAYER_NULL,
 				             STR_ID_DTV_PLAYER_NULL,
 				             IMG_ID_DTV_PLAYER_NULL,
 				             (PU8) GetString(STR_GLOBAL_PLEASE_WAIT),
 				             mmi_get_event_based_image(MMI_EVENT_PROGRESS),
 				             NULL);
#else
       ShowCategory66Screen(STR_ID_DTV_PLAYER_APP_NAME,
                    		DTV_PLAYER_MENU_ICON,
				            STR_ID_DTV_PLAYER_NULL,
				            IMG_ID_DTV_PLAYER_NULL,
				            STR_ID_DTV_PLAYER_NULL,
				            IMG_ID_DTV_PLAYER_NULL,
				            (PU8) GetString(STR_GLOBAL_PLEASE_WAIT),
				            mmi_get_event_based_image(MMI_EVENT_PROGRESS),
				            NULL);
#endif            

        return; /* Don't remove it */
    }
    else
    {
        ShowCategoryDummyScreen();
    }
/*yaling*/
/*
	#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
	mmi_cmmb_2gpp_adp_notify(EVT_ID_CMMB_2GPP_MMI_START,0,NULL);
	#endif
*/
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_DTV_SIGNAL);
    wgui_status_icon_bar_change_icon_level(STATUS_ICON_DTV_SIGNAL, (U8) dtv_player_p->signal_strength);

    /* Delete warning screen */
    mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_WARNING_MESSAGE);

    /* reset ui rotate when entering app again */
    dtv_player_p->ui_rotate = MMI_FRM_SCREEN_ROTATE_0;
	/* reset back for confirm screen */
	#ifdef __MBBMS_INTER__
	/* reset inter state */
	dtv_player_p->int_state = DTV_PLAYER_INT_STATE_OFF;
	#endif
	
    /* load mtv setting */
    mmi_dtv_player_load_setting();

	#ifdef __MBBMS_DUAL_SIM_SUPPORT__
	if (MMI_SIM2 == dtv_player_p->setting.simcard)
	{
		dtv_player_p->cur_sim = MMI_SIM2;
	}
	else
	#endif
	{
		dtv_player_p->cur_sim = MMI_SIM1;
	}

    mmi_dtv_player_get_language_type();

#if defined(__MMI_DTV_RECORD_SUPPORT__) || defined(__MMI_DTV_SNAPSHOT_SUPPORT__)
    if (!RECORDER_STATE_IN(DTV_RECORDER_STOPPED))
    {
    	restore = MMI_FALSE;        
    }
    else
    {
    	restore = MMI_TRUE;
    }
	#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
        /* check storage and don't restore */
        event_type = mmi_dtv_player_check_storage(restore,                                                   
                                                  dtv_player_p->setting.storage);
    #else		
        mmi_dtv_player_check_storage(restore, 
                                     dtv_player_p->setting.storage);
    #endif
#endif /* __MMI_DTV_RECORD_SUPPORT__ || __MMI_DTV_SNAPSHOT_SUPPORT__ */
#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
    if(mmi_dtv_player_is_flag_set(DTV_PLAYER_IS_STORAGE_CHECK) == MMI_FALSE &&
       dtv_player_p->storage_status != DTV_PLAYER_STORAGE_OK)
    {
        /* Show storage error message */
        mmi_dtv_player_display_popup(dtv_player_p->err_str_id, event_type);
        mmi_dtv_player_set_flag(DTV_PLAYER_IS_STORAGE_CHECK);
        return;
    }
#endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */

    /* suspend background play */
    mdi_audio_suspend_background_play();

    if (KERNEL_STATE_IN(DTV_KERNEL_CLOSED))
    {
        /* Create ADM */
        mmi_dtv_player_create_adm();

		#ifdef __MBBMS_V30_OPERA__
		mmi_dtv_player_opera_engine_start();
		#endif

        mmi_dtv_player_alloc_adm_structure();

        ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);

        /* reset application variable */
        dtv_player_p->max_timeshift_delay = 0;
        dtv_player_p->go_back_history = MMI_FALSE;
        dtv_player_p->del_main_screen = MMI_FALSE;
        dtv_player_p->play_delay = 0;
        dtv_player_p->max_delay = 0;
        dtv_player_p->is_ready_to_ts = MMI_FALSE;
        dtv_player_p->signal_strength = 0;
        dtv_player_p->scan_progress = 0;
        dtv_player_p->option_menu_gid = GRP_ID_INVALID;
        dtv_player_p->cl_option_menu_gid = GRP_ID_INVALID;
        dtv_player_p->num_eb_msg = 0;
        dtv_player_p->num_unread_ebs = 0;
        dtv_player_p->prev_selected_service = -1;	
		#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
		dtv_player_p->rescan_notify = MMI_TRUE;
		#endif
	#ifdef __MBBMS_CITY_LIST__
        for (idx = 0; idx < DTV_PLAYER_CITY_LIST_NUM; idx ++)
        {
            kal_mem_set(&dtv_player_p->selected_city[idx], 0, sizeof(dtv_player_display_city_struct));
        }
	#endif /* __MBBMS_CITY_LIST__ */
        mmi_dtv_player_unset_flag(DTV_PLAYER_DISPLAY_EB_WARNING_STRING);

        if (dtv_player_p->ca_state != MMI_DTV_CA_STATE_CMMB)
        {
            /* Always get previous DB first */
            dtv_player_p->setting.is_channel_list_init = MMI_TRUE;
        }

        if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_MBBMS)
        {
            /* Set net info to MED */
            mmi_dtv_cas_update_net_info();
        }

        /* Change service list to total list */
        dtv_player_p->service_list_type = DTV_PLAYER_TOTAL_LIST;

        switch (ret)
        {
	        case MDI_RES_MTV_SUCCEED:
						/* yaling */
				#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
				mmi_cmmb_2gpp_adp_notify(EVT_ID_CMMB_2GPP_MMI_START,0,NULL);
				#endif
				{
	        		#ifdef __CMMB_CAS_MBBMS_SUPPORT__
	            	if (mmi_dtv_player_is_flag_set(DTV_PLAYER_DISPLAY_CMMB_MODE_CONFIRM))
	            	{
	                	mmi_dtv_player_enter_cmmb_mode_confirm();
	                	return; /* Don't remove */
	            	}
	        		#endif /*  __CMMB_CAS_MBBMS_SUPPORT__ */
	            	dtv_player_p->update_approach = DTV_PLAYER_UPDATE_AUTO;
		            mmi_dtv_player_enter_scan_channel();
	            	break;
	        	}
	        case MDI_RES_MTV_UNSAVE_RECORDING_IND:
				{
	            	mmi_dtv_player_enter_save_confirm();
	            	break;
	        	}
	        default:
	            {
	                mmi_popup_property_init(&arg);
	                arg.callback = mmi_dtv_player_hw_not_ready_popup_proc;
	                arg.parent_id = GRP_ID_DTV_PLAYER;
	                mmi_popup_display(
	                    (WCHAR*)GetString(STR_ID_DTV_PLAYER_NOTIFY_HW_NOT_READY),
	                    MMI_EVENT_FAILURE,
	                    &arg);
	                mmi_dtv_player_free_adm_structure();
	                /* Delete adm */
	                mmi_dtv_player_delete_adm();
	                if (NULL != dtv_player_p->app_mem_pool)
                    {
                        applib_asm_free_r(GRP_ID_DTV_PLAYER, (void *)dtv_player_p->app_mem_pool);
                    dtv_player_p->app_mem_pool = NULL;
                }
	                break;
            }
        }

    }
    /* should back from (save_unsave_recording) or (discard_unsave_recording) */
    else if (KERNEL_STATE_IN(DTV_KERNEL_OPENED))
    {
    #if defined(__CMMB_CAS_MBBMS_SUPPORT__)
        if (mmi_dtv_player_is_flag_set(DTV_PLAYER_DISPLAY_CMMB_MODE_CONFIRM))
        {
            mmi_dtv_player_enter_cmmb_mode_confirm();
            return; /* Don't remove */
        }
    #endif /*  __CMMB_CAS_MBBMS_SUPPORT__ */
    #ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
        if (dtv_player_p->storage_status == DTV_PLAYER_STORAGE_OK)
        {
            mdi_mtv_enable_timeshift(dtv_player_p->mtv_handle, (PU8)dtv_player_p->storage_filepath);
        }
        else
        {
            mdi_mtv_disable_timeshift(dtv_player_p->mtv_handle);
        }
    #endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */

        dtv_player_p->update_approach = DTV_PLAYER_UPDATE_AUTO;

        mmi_dtv_player_enter_scan_channel();

    }
    /* (Recorder is at RECORD or SAVING state) or (back from video recorder's save confirm or saving screen) */
    else if (KERNEL_STATE_IN(DTV_KERNEL_READY))
    {
    #if defined(__MDI_DTV_TIME_SHIFT_SUPPORT__)
        if (dtv_player_p->storage_status != DTV_PLAYER_STORAGE_OK)
        {
            mdi_mtv_disable_timeshift(dtv_player_p->mtv_handle);
        }
    #endif /* defined(__MDI_DTV_TIME_SHIFT_SUPPORT__) */
        mmi_dtv_player_entry_channel_list_screen();
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_clear_preview_layer
 * DESCRIPTION
 *  clear preview layer hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_clear_preview_layer(void)
{
    if (dtv_player_p->display_layer_handle != GDI_NULL_HANDLE)
    {
        mdi_util_hw_layer_switch_to_sw_layer(dtv_player_p->display_layer_handle);
        gdi_layer_push_and_set_active(dtv_player_p->display_layer_handle);
        gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_enable_ts_function
 * DESCRIPTION
 *  check ts function ready or not hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_enable_ts_function(void)
{
#ifdef __MDI_DTV_TIME_SHIFT_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    active_screen_id = mmi_frm_scrn_get_active_id();

    mmi_dtv_player_get_player_status(dtv_player_p->mtv_handle, NULL, &dtv_player_p->play_delay, &dtv_player_p->max_delay, &dtv_player_p->max_timeshift_delay, NULL);

    if (dtv_player_p->max_delay > MMI_DTV_PLAYER_MINIMAL_MAX_DELAY_TO_START_TS)
    {
        dtv_player_p->is_ready_to_ts = MMI_TRUE;
        if (active_screen_id == SCR_ID_DTV_PLAYER_APP)
        {
            /* If already fade out, keep all key handler as: mmi_dtv_player_fullscr_osd_show_up */
            if (dtv_player_p->fullscr_osd_opacity != 0)
            {
                mmi_dtv_player_register_key_hdlr();
            }
        }
    }
    else
    {
        gui_start_timer(MMI_DTV_PLAYER_TS_ENABLE_DURATION, mmi_dtv_player_enable_ts_function);
    }
#endif /* __MDI_DTV_TIME_SHIFT_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_record_start_record
 * DESCRIPTION
 *  start record timer expired hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_record_start_record(void)
{
#ifdef __MMI_DTV_RECORD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (RECORDER_STATE_IN(DTV_RECORDER_STOPPED))
    {
        dtv_player_p->is_capture = MMI_FALSE;

        dtv_player_p->active_osd_cntx_p->record.status  = DTV_PLAYER_ICON_STATUS_ENABLE;
        dtv_player_p->touch_object = DTV_PLAYER_TOUCH_NONE;

    #ifdef __MDI_DTV_BLOCK_PHONE_DISK_RECORD__
        if (dtv_player_p->setting.storage == SRV_FMGR_PUBLIC_DRV)
        {
            mmi_dtv_player_display_popup(
                STR_ID_DTV_PLAYER_NOTIFY_SWITCH_TO_MEM_CARD,
                MMI_EVENT_FAILURE);
            return;
        }
    #endif /*__MDI_DTV_BLOCK_PHONE_DISK_RECORD__ */
    #ifdef __MMI_BT_SUPPORT__
        if (mmi_bt_is_receiving())
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL1, 1, __LINE__);
            mmi_dtv_player_display_popup(
                STR_ID_DTV_PLAYER_NOTIFY_BT_IS_WORKING,
                MMI_EVENT_FAILURE);
            return;
        }
    #endif /* __MMI_BT_SUPPORT__ */

        dtv_player_p->last_error = mmi_dtv_player_recorder_enter_state(DTV_RECORDER_RECORD);
        if (dtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
        {
            /* The same as receiving player event: time-shift error */
            dtv_player_p->is_timeshift_enable = MMI_FALSE;

            mmi_dtv_player_display_failure_popup(dtv_player_p->last_error);
            return;
        }
        else
        {
            U16 active_screen_id;
            active_screen_id = mmi_frm_scrn_get_active_id();
            if (active_screen_id == SCR_ID_DTV_PLAYER_APP)
            {
                mmi_dtv_player_register_key_hdlr();
            }
        }

        mmi_dtv_player_draw_osd_and_blt();
    }
#endif /* __MMI_DTV_RECORD_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_next_filename
 * DESCRIPTION
 *  get next file name for jpeg image
 * PARAMETERS
 *  file_buf_p      [IN]
 *  a(?)            [OUT]       Next filename
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_get_next_filename(CHAR *filename, CHAR *file_path_p)
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

    filename_seq_no = dtv_player_p->setting.filename_seq_no;
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

    sprintf((CHAR *) buffer, "TV%04d", filename_seq_no);
    mmi_asc_to_ucs2((CHAR *) UCS2_buffer, (CHAR *) buffer);

    while (1)
    {
        sprintf((CHAR *) buffer, "%c", 'A' + alpha_index);
        mmi_asc_to_ucs2((CHAR *) UCS2_alpha, (CHAR *) buffer);

        mmi_ucs2cpy(filename, UCS2_buffer);
        mmi_ucs2cat(filename, UCS2_alpha);
        mmi_ucs2cat(filename, (CHAR *) L".jpg");

        file_path_p[length << 1] = file_path_p[(length << 1) + 1] = 0;
        mmi_ucs2cat((CHAR *) file_path_p, (CHAR *) filename);

        file_handle = FS_Open((U16*) file_path_p, FS_READ_ONLY);

        if (file_handle >= 0)
        {
            /* file exist */
            FS_Close(file_handle);
            alpha_index++;
        }
        else
        {
            dtv_player_p->setting.filename_seq_no = filename_seq_no;
            mmi_dtv_player_store_setting();
            return;
        }

        /* exit condition - will get a IMGXXXXZ.jpg as file name */
        if (alpha_index >= alpha_count )
        {
            alpha_count = 'Z' - 'A' + 1;
            alpha_index = 0;
            filename_seq_no++;
            file_check++;
            if (filename_seq_no > 9999) /* more than 4 digits */
            {
                filename_seq_no = 1;
            }
            sprintf((CHAR *) buffer, "TV%04d", filename_seq_no);
            mmi_asc_to_ucs2((CHAR *) UCS2_buffer, (CHAR *) buffer);

            /* check if number of files are > 9999 * 26*/
            if (file_check >= 9999)
                return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_snapshot
 * DESCRIPTION
 *  snapshot screen.
 * PARAMETERS
 *  inMsg       [?]
 * RETURNS
 *
 *****************************************************************************/
 MMI_BOOL mmi_dtv_player_snapshot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR filename[50] = {0};
    CHAR buf_pathname[SRV_FMGR_PATH_BUFFER_SIZE] = {0};
    S32 result, len, offset;
    MDI_RESULT ret = MDI_RES_MTV_FAILED;
    S32 event_type;
	mmi_event_notify_enum event = MMI_EVENT_SUCCESS;
		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DTV_BLOCK_BG_CALL__
    if (mmi_dtv_player_is_in_background_call())
    {
        mmi_dtv_player_display_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL, 
			                         MMI_EVENT_FAILURE);
        return  MMI_FALSE;
    }
#endif /* __MMI_DTV_BLOCK_BG_CALL__ */

    /* Pause the player */
    if (PLAYER_STATE_IN(DTV_PLAYER_PLAY))
    {
        dtv_player_p->last_error = mmi_dtv_player_player_enter_state(DTV_PLAYER_STOPPED);
        if (dtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
        {
            mmi_dtv_player_display_failure_popup(dtv_player_p->last_error);
            return MMI_FALSE;
        }
    }
    mmi_dtv_player_get_storage_file_path(dtv_player_p->setting.storage, 
		                                  buf_pathname, 
		                                  DTV_PLAYER_STORAGE_PATH_PHOTO);
    /* check if storage path is valid or not */
    result = FS_GetDevStatus((U16)buf_pathname[0] ,FS_MOUNT_STATE_ENUM);
    if (FS_NO_ERROR == result)
    {
        /* if drv is valid, check if the folder is crated or not */
        result = mmi_dtv_player_create_file_dir(buf_pathname);
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL1, result, __LINE__);
        /* Change return value to get the correct error string. */
        result = FS_DRIVE_NOT_FOUND;
    }

    if (FS_NO_ERROR == result)
    {
        len = mmi_ucs2strlen(buf_pathname);
        mmi_dtv_player_get_next_filename(filename, buf_pathname);
        /* get snapshot */
        ret = mdi_mtv_get_snapshot(dtv_player_p->mtv_handle,
                                   dtv_player_p->display_layer_handle,
                                   (WCHAR*)buf_pathname);
		if (ret != MDI_RES_MTV_SUCCEED)
   		{
        	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL1, ret, __LINE__);
        	if (ret == MDI_RES_MTV_ERR_DISC_FULL)
        	{
            	mmi_dtv_player_display_popup(STR_GLOBAL_NOT_ENOUGH_MEMORY, 
					                         MMI_EVENT_FAILURE);
       		 }
        	else
        	{
            	mmi_dtv_player_display_popup(STR_ID_DTV_PLAYER_NOTIFY_FAILED_TO_SNAPSHOT, 
					                         MMI_EVENT_FAILURE);
        	}
        	return MMI_FALSE;
    	}
		else
	    {
	        offset = ((len - 1) << 1);
	        mmi_ucs2cpy((CHAR *)dtv_player_p->snapshot_filename, buf_pathname);
	        buf_pathname[offset] = buf_pathname[offset+1] = 0;
	        mmi_dtv_player_gen_separate_string(
	            (WCHAR*)GetString(STR_ID_DTV_PLAYER_SNAPSHOT_SUCCEED),
	            (WCHAR*)filename,
	            (WCHAR*)buf_pathname);			
            mmi_ucs2cat((CHAR*)dtv_player_p->info_str_buffer, (CHAR*)GetString(STR_ID_DTV_CHECK_PIC));			
			mmi_dtv_player_display_confirm(STR_ID_DTV_CHECK_PIC);
	        return MMI_FALSE;
	    }
    }
	else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL1, result, __LINE__);

        dtv_player_p->err_str_id = srv_fmgr_fs_error_get_string_and_popup_type(result, 
			                                                                  &event_type);
		if (MMI_EVENT_FAILURE == event_type)
		{
			event = MMI_EVENT_FAILURE;
		}
        mmi_dtv_player_display_popup(dtv_player_p->err_str_id, event);
        return MMI_FALSE;
    } 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_prepare_channel_name_hint
 * DESCRIPTION
 *
 * PARAMETERS
 *  inMsg       [?]
 * RETURNS
 *
 *****************************************************************************/
 void mmi_dtv_player_prepare_channel_name_hint(CHAR *str_buf, CHAR *str_buf2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR preview[MMI_DTV_MAX_PREVIEW_TEXT_LEN + 5] = {0};
    dtv_player_service_info_struct *info_ptr;
    S32 len, cat_len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    info_ptr = mmi_dtv_player_get_active_channel_ptr();

    /* Loading */
	if (!KERNEL_STATE_IN(DTV_KERNEL_READY))
    {
    	mmi_ucs2cpy((CHAR*) str_buf, (CHAR*) GetString(STR_ID_DTV_PLAYER_NOTIFY_LOADING));
	}
    len = mmi_ucs2strlen((CHAR*)str_buf);
    /* Preview text */
    if (mmi_ucs2strlen((CHAR*)dtv_player_p->preview_text) > 0)
    {
        mmi_ucs2cpy((CHAR*)preview, (CHAR*)L"(");
        mmi_ucs2cat((CHAR*)preview, (CHAR*)dtv_player_p->preview_text);
        mmi_ucs2cat((CHAR*)preview, (CHAR*)L")");

        cat_len = MMI_DTV_NAME_STR_LENGTH - 1 - len;
        if (cat_len > 0)
        {
            mmi_ucs2ncat((CHAR*)str_buf, (CHAR*) preview, cat_len);
        }
    }

    /* channel number & channel name  */
    kal_wsprintf((WCHAR*) str_buf2, "%2d ", info_ptr->service_number);
    mmi_ucs2cat((CHAR*) str_buf2, (CHAR*)info_ptr->service_name);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_is_bg_running
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_is_bg_running(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!RECORDER_STATE_IN(DTV_RECORDER_STOPPED))
        return MMI_TRUE;
    else
        return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_popup_mtv_is_running
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void mmi_dtv_player_popup_mtv_is_running(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_dtv_player_display_popup(
        STR_ID_DTV_PLAYER_NOTIFY_BG_RUNNING,
        MMI_EVENT_FAILURE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_notify_bg_running_str_id
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
U16 mmi_dtv_player_get_notify_bg_running_str_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return STR_ID_DTV_PLAYER_NOTIFY_BG_RUNNING;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_error_info
 * DESCRIPTION
 *  Function to get the error information includes popup type and string
 * PARAMETERS
 *  error_result:   [IN]    error result type
 *  popup_type:     [OUT]   get the error popup type
 * RETURNS
 *  Get the error popup string id.
 *****************************************************************************/
MMI_STR_ID mmi_dtv_player_get_error_info(S32 error_result, 
                                         mmi_event_notify_enum* popup_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID  str_id = STR_ID_DTV_PLAYER_NOTIFY_BG_RUNNING;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *popup_type = MMI_EVENT_FAILURE;
    if (error_result == MMI_DTV_PLAYER_ERR_IS_BG_RUNNING)
    {
        str_id = STR_ID_DTV_PLAYER_NOTIFY_BG_RUNNING;
    }
    return str_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_sw_rotate
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
void mmi_dtv_player_counter_clockwise_rotate(U8* pDst, U8* pSrc, 
                                             U32 const dst_width, U32 const dst_height,
                                             gdi_rect_struct *dest_rect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
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
}

#ifndef GDI_USING_2D_ENGINE_V3
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_sw_rotate
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
void mmi_dtv_player_sw_rotate(
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
#ifdef __MBBMS_V30_OPERA__
/*****************************************************************************
 * FunctionName: mmi_dtv_player_opera_engine_set_flag
 * Description
 *    set the opera engine state flag 
 * Input Parameter
 *    flag--Opera engine state
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2011-12-17
 *****************************************************************************/
void mmi_dtv_player_opera_engine_set_flag(dtv_player_opera_state_enum flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->opera_engine_state |= flag;
}
/*****************************************************************************
 * FunctionName: mmi_dtv_player_opera_engine_clear_flag
 * Description
 *  clear the opear engine state flag   
 * Input Parameter
 *    flag--opera engine state flag
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2011-12-17
 *****************************************************************************/
void mmi_dtv_player_opera_engine_clear_flag(dtv_player_opera_state_enum flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->opera_engine_state &= (~flag);
}

/*****************************************************************************
 * FunctionName: mmi_dtv_player_opera_engine_is_set_flag
 * Description
 *    check if the flag of opera engine is set 
 * Input Parameter
 *    flag--opera engine state
 * Output Parameter
 *    void
 * Return
 *    MMI_TRUE: the flag is set; MMI_FALSE: the flag isn't set
 * Date:  2011-12-17
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_opera_engine_is_set_flag(dtv_player_opera_state_enum flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 != (dtv_player_p->opera_engine_state & flag))
    {
        result = MMI_TRUE;
    }
    return result;
}

/*****************************************************************************
 * FunctionName: mmi_dtv_player_opera_engine_display_imd
 * Description
 *     mmi dtv player pass the selected imd url to opera engine
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2011-12-17
 *****************************************************************************/
void mmi_dtv_player_opera_engine_display_imd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_mtv_imd_detail_struct imd_detail;
    dtv_player_service_info_struct *info_ptr = NULL;
    MMI_ID group_id;
    MMI_ID active_scr_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imd_detail.path_len = ((MMI_DTV_PLAYER_DETAIL_BUF_SIZE >>1) - 2);
    imd_detail.path = (WCHAR* )dtv_player_p->detail_buf;

	if ((MMI_FALSE == dtv_player_p->need_open_url)
		&& (dtv_player_p->opera_display_imd_index == dtv_player_p->selected_imd))
	{
		return;
	}

    mmi_frm_get_active_scrn_id(&group_id, &active_scr_id);	
    if ((GRP_ID_DTV_PLAYER == group_id) /* content inter */
        && (SCR_ID_DTV_PLAYER_CONTENT_INTER == active_scr_id))
    {
        imd_detail.imd_type = MDI_MTV_IMD_TYPE_CONTENT;
        imd_detail.content_id = dtv_player_p->selected_content.cid;	
        mdi_mtv_get_imd_detail(dtv_player_p->mtv_handle, 
                               0, 
                               &imd_detail);
    }
    else /*servcie inter*/
    {
        info_ptr = mmi_dtv_player_get_active_channel_ptr(); 
        imd_detail.imd_type = MDI_MTV_IMD_TYPE_SERVICE;
        imd_detail.imd_index = dtv_player_p->selected_imd;
        imd_detail.content_id = dtv_player_p->selected_content.cid;
        mdi_mtv_get_imd_detail(dtv_player_p->mtv_handle, 
                               info_ptr->service_id, 
                               &imd_detail);    
    }

	dtv_player_p->need_open_url = MMI_FALSE;
    opera_webview_api_open_url((char *) dtv_player_p->detail_buf);
	dtv_player_p->opera_display_imd_index = dtv_player_p->selected_imd;
}

/*****************************************************************************
 * FunctionName: mmi_dtv_player_opera_engine_repaint_inter_page
 * Description
 *  Notify Opera engine to repaint Inter page   
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2011-12-17
 *****************************************************************************/
void mmi_dtv_player_opera_engine_repaint_inter_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gdi_layer_push_and_set_active(dtv_player_p->opera_layer_handle);
    #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    gdi_layer_toggle_double();
    gdi_layer_copy_double();
    #endif /* __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ */
	opera_webview_api_paint();
    gdi_layer_pop_and_restore_active();
    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH, LCD_HEIGHT);
	mmi_dtv_player_opera_engine_set_flag(DTV_PLAYER_OPERA_SHOW_PAGE);	
	dtv_player_p->opera_engine_blt_flag = MMI_FALSE;
}

/*****************************************************************************
 * FunctionName: mmi_dtv_player_opera_engine_event_processer
 * Description
 *     
 * Input Parameter
 *    opera_evt--Opera Event Type   event_data--Opera Event Data
 *    user_data--Future extends
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2011-12-16
 *****************************************************************************/
int mmi_dtv_player_opera_engine_event_processer(enum opera_webview_event opera_evt, 
                                                union opera_webview_evt_data * event_data,
                                                void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int result = OP_WEBVIEW_STATUS_OK;
    opera_webview_opera_jsex_data *p_jsex_data = NULL;
	char *key = NULL;
	int   dest_channel = 0; 
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (opera_evt)
    {
        case OP_WEBVIEW_EVENT_OPERA_STARTED:
             {
                mmi_dtv_player_opera_engine_set_flag(DTV_PLAYER_OPERA_START);
                break;
             }
        case OP_WEBVIEW_EVENT_OPERA_STOPPED:
             {                
                mmi_dtv_player_opera_engine_clear_flag(DTV_PLAYER_OPERA_START);
                kal_adm_free(dtv_player_p->adm_pool_id, 
                             (void*)dtv_player_p->opera_engine_context.mem_base);
                kal_adm_free(dtv_player_p->adm_pool_id, 
                             (void*)dtv_player_p->opera_engine_context.graphics_mem_base);
                dtv_player_p->opera_engine_context.size = 0;
                dtv_player_p->opera_engine_context.mem_base = NULL;
                dtv_player_p->opera_engine_context.graphics_mem_size = 0;
                dtv_player_p->opera_engine_context.graphics_mem_base = NULL;				
				dtv_player_p->last_error = mdi_mtv_close(dtv_player_p->mtv_handle);
                break;
             }
        case OP_WEBVIEW_EVENT_SCREEN_INVALID:
             { 
			 	if (MMI_FALSE == dtv_player_p->opera_engine_blt_flag)
			 	{
			 		dtv_player_p->opera_engine_blt_flag = MMI_TRUE;					
					gui_start_timer(20,mmi_dtv_player_opera_engine_repaint_inter_page);
			 	}
                break;
             }
        case OP_WEBVIEW_EVENT_IME_START:
             {
                mmi_dtv_player_opera_engine_set_flag(DTV_PLAYER_OPERA_IME);
				gdi_layer_get_active(&(dtv_player_p->restore_layer));
				gdi_layer_set_active(dtv_player_p->opera_layer_handle);

                break;
             }
        case OP_WEBVIEW_EVENT_IME_END:
             {
                mmi_dtv_player_opera_engine_clear_flag(DTV_PLAYER_OPERA_IME);
				gdi_layer_set_active(dtv_player_p->restore_layer);
				#ifdef __MMI_TOUCH_SCREEN__               
				if (SCR_ID_DTV_PLAYER_APP == mmi_frm_scrn_get_active_id())
				{					
					wgui_register_pen_down_handler(mmi_dtv_player_pen_down_hdlr);
					wgui_register_pen_up_handler(mmi_dtv_player_pen_up_hdlr);
					wgui_register_pen_move_handler(mmi_dtv_player_pen_move_hdlr);
					SetKeyHandler(mmi_dtv_player_lsk_icon_press, KEY_LSK, KEY_EVENT_DOWN);
					SetKeyHandler(mmi_dtv_player_lsk_icon_release, KEY_LSK, KEY_EVENT_UP);
					SetKeyHandler(mmi_dtv_player_rsk_icon_press, KEY_RSK, KEY_EVENT_DOWN);
					SetKeyHandler(mmi_dtv_player_rsk_icon_release, KEY_RSK, KEY_EVENT_UP);
				}
				else
				{
					wgui_register_pen_down_handler(mmi_dtv_player_inter_fullscreen_pen_down_hdlr);
					wgui_register_pen_up_handler(mmi_dtv_player_inter_fullscreen_pen_up_hdlr);
					wgui_register_pen_move_handler(mmi_dtv_player_inter_fullscreen_pen_move_hdlr);					
					SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
					if (SCR_ID_DTV_PLAYER_SERVICE_INTER == mmi_frm_scrn_get_active_id())
					{
						SetLeftSoftkeyFunction(mmi_dtv_player_half_inter_app_screen, KEY_EVENT_UP);
						SetCenterSoftkeyFunction(mmi_dtv_player_half_inter_app_screen, KEY_EVENT_UP);
					}
				}
				#endif /* __MMI_TOUCH_SCREEN__	*/			
                break;
             }
        case OP_WEBVIEW_EVENT_PAGE_LOAD_FINISHED:
             {
                /*  start timer of ActionTimeOut  */                
                break;
             }
        case OP_WEBVIEW_EVENT_JSEX_SET_VALUE:
			{
				if (NULL != event_data)
				{
					p_jsex_data = event_data->jsex_setvalue.args;					
					if (NULL != p_jsex_data)
					{	
						/* For future extends, need to map key */
						if ((p_jsex_data->data.num < dtv_player_p->num_services) 
							&&(p_jsex_data->data.num != dtv_player_p->setting.selected_channel))
						{
							dtv_player_p->setting.selected_channel = p_jsex_data->data.num;
							if (SCR_ID_DTV_PLAYER_APP == mmi_frm_scrn_get_active_id())
							{							
								/* exit half screen state */
								ASSERT(dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0);
								dtv_player_p->int_state = DTV_PLAYER_INT_STATE_OFF;
								mmi_dtv_player_opera_engine_pause();
								mmi_dtv_player_set_blt_layer();
								mmi_dtv_player_register_key_hdlr(); 	
								mmi_dtv_player_draw_osd();
								mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
								/* change channel */
								mmi_dtv_player_change_channel(dtv_player_p->setting.selected_channel);
							}
						}
					}
				}
				break;
        	}
		case OP_WEBVIEW_EVENT_JSEX_GET_VALUE:
			{
				if (NULL != event_data)
				{
					p_jsex_data = event_data->jsex_getvalue.args;
					if (NULL != p_jsex_data)
					{					
						/* For future extends, need to map key */
						p_jsex_data->data.num = dtv_player_p->setting.selected_channel;
					}
				}
				/* pass the current service id to Opera*/
				break;
			}
        case OP_WEBVIEW_DIALOG_TYPE_CERT_CONFIRM:
             {
                /*  Pop up confirm dialogue to user  */                
                break;
             }
        case OP_WEBVIEW_USER_ACTIVE:
             {
                /* stop timer of ActionTimeOut */
                break;
             }
        case OP_WEBVIEW_SET_RENDER_RECT_DONE:
             {
                mmi_dtv_player_opera_engine_display_imd();
				
                break;
             }
        case OP_WEBVIEW_EVENT_JSEX_CREATED:
             {
                /*  change channel for future extends  */                                
                break;
             }
        default :
             {
                break;
             }
    }
    return result;
}

/*****************************************************************************
 * FunctionName: mmi_dtv_player_opera_engine_start
 * Description
 *    Allocate Memory for opera engine and start engine 
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    MMI_TURE: success,   MMI_FALSE: fail
 * Date:  2011-12-17
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_opera_engine_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    void * ptr = NULL;
    int opera_result = OP_WEBVIEW_STATUS_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	dtv_player_p->need_open_url = MMI_TRUE;
    ptr = (void *) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(dtv_player_p->adm_pool_id, 
                                                 DTV_PLAYER_OPERA_ENGINE_MEM1);
    dtv_player_p->opera_engine_context.mem_base = ptr;
    dtv_player_p->opera_engine_context.size = DTV_PLAYER_OPERA_ENGINE_MEM1;
    if (NULL == ptr)
    {
        result = MMI_FALSE;
    }
    
    ptr = (void *) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(dtv_player_p->adm_pool_id, 
                                                 DTV_PLAYER_OPERA_ENGINE_MEM2);    
    dtv_player_p->opera_engine_context.graphics_mem_base = ptr;    
    dtv_player_p->opera_engine_context.graphics_mem_size = DTV_PLAYER_OPERA_ENGINE_MEM2;
    if (NULL == ptr)
    {
        result = MMI_FALSE;
    }    

    if (MMI_TRUE == result)
    {
        opera_result = opera_webview_api_start_opera(dtv_player_p->opera_engine_context, 
                                                     mmi_dtv_player_opera_engine_event_processer, 
                                                     NULL);
        if (OP_WEBVIEW_STATUS_OK != opera_result)
        {
            result = MMI_FALSE;
        }
    }
    return result;
}

/*****************************************************************************
 * FunctionName: mmi_dtv_player_opera_engine_stop
 * Description
 *     
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2011-12-17
 *****************************************************************************/
void mmi_dtv_player_opera_engine_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    opera_webview_api_stop_opera();
}

/*****************************************************************************
 * FunctionName: mmi_dtv_player_opera_engine_restart
 * Description
 *    restart opera engine with update opera paint layer	   
 * Input Parameter
 *    opera_layer--opera paint layer
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-01-07
 *****************************************************************************/
void mmi_dtv_player_opera_engine_restart(GDI_HANDLE opera_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    mmi_dtv_player_alloc_detail_screen_memory();
	opera_webview_api_update_ui_layer_handle(opera_layer);	
	opera_webview_api_set_render_rect(&(dtv_player_p->opera_page_rect));
	dtv_player_p->opera_engine_blt_flag = MMI_FALSE;
	mmi_dtv_player_opera_register_key_hdlr();
	if (mmi_dtv_player_opera_engine_is_set_flag(DTV_PLAYER_OPERA_IME))
	{
 		MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_DTV_VAL1, dtv_player_p->opera_engine_state,__LINE__);
		
		opera_webview_api_ime_enter_screen();
	}
}

/*****************************************************************************
 * FunctionName: mmi_dtv_player_opera_engine_pause
 * Description
 *    pause opera engine   
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-01-07
 *****************************************************************************/
void mmi_dtv_player_opera_engine_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_dtv_player_opera_engine_is_set_flag(DTV_PLAYER_OPERA_IME))
	{	
		MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_DTV_VAL1, dtv_player_p->opera_engine_state,__LINE__);
		opera_webview_api_ime_exit_screen();
	}
	mmi_dtv_player_opera_engine_clear_flag(DTV_PLAYER_OPERA_SHOW_PAGE);	
	dtv_player_p->opera_engine_blt_flag = MMI_TRUE;	
    mmi_dtv_player_free_detail_screen_memory();
	gui_cancel_timer(mmi_dtv_player_opera_engine_repaint_inter_page);
}
/*****************************************************************************
 * FunctionName: mmi_dtv_player_opera_engine_key_event
 * Description
 *     
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-02-08
 *****************************************************************************/
void mmi_dtv_player_opera_engine_key_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 keyCode = 0, keyType = 0;
	enum opera_webview_key_evt event = OP_WEBVIEW_KEYEVENT_DOWN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	

    GetkeyInfo(&keyCode, &keyType);
	
	switch(keyType)
	{
		case KEY_EVENT_UP:
			{
				event = OP_WEBVIEW_KEYEVENT_UP;
				break;
			}
		case KEY_EVENT_DOWN:
			{
				event = OP_WEBVIEW_KEYEVENT_DOWN;
				break;
			}
		default :
			{
				break;
			}
	}
	opera_webview_api_key_event(event,keyCode, 0);	                            
}
/*****************************************************************************
 * FunctionName: mmi_dtv_player_opera_register_key_hdlr
 * Description
 *     
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-02-17
 *****************************************************************************/
void mmi_dtv_player_opera_register_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* register Number Keys */
	SetGroupKeyHandler(mmi_dtv_player_opera_engine_key_event,
	                   Keys_Number,
	                   DTV_PLAYER_KEYS_NUMBER_LEN,
	                   KEY_EVENT_DOWN);
	SetGroupKeyHandler(mmi_dtv_player_opera_engine_key_event,
                       Keys_Number,
                       DTV_PLAYER_KEYS_NUMBER_LEN,
                       KEY_EVENT_UP);
	/* register Direct Keys */
	SetGroupKeyHandler(mmi_dtv_player_opera_engine_key_event,
	                   Keys_Direct,
	                   DTV_PLAYER_KEYS_DIRECT_LEN,
	                   KEY_EVENT_DOWN);
	SetGroupKeyHandler(mmi_dtv_player_opera_engine_key_event,
	                   Keys_Direct,
	                   DTV_PLAYER_KEYS_DIRECT_LEN,
	                   KEY_EVENT_UP);
}

/*****************************************************************************
 * FunctionName: mmi_dtv_player_opera_engine_pen_event
 * Description
 *  Pass the pen event to Opera Engine   
 * Input Parameter
 *    pen_point--Pen position; pen_event--pen event type 
 * Output Parameter
 *    void
 * Return
 *    MMI_TRUE: Opera engine need to process pen event
 *    MMI_FALSE: Opera engine don't process pen event
 * Date:  2011-12-17
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_opera_engine_pen_event(mmi_pen_point_struct pos,
                                               enum opera_webview_pen_evt event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    S16 x1 = dtv_player_p->opera_page_rect.x;
	S16 y1 = dtv_player_p->opera_page_rect.y;
	S16 x2 = dtv_player_p->opera_page_rect.x + dtv_player_p->opera_page_rect.w;
	S16 y2 = dtv_player_p->opera_page_rect.y + dtv_player_p->opera_page_rect.h;
	opera_webview_pen_point opera_pos;
    opera_pos.x = pos.x;
    opera_pos.y = pos.y;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_dtv_player_opera_engine_is_set_flag(DTV_PLAYER_OPERA_SHOW_PAGE))
    {
        if (mmi_dtv_player_opera_engine_is_set_flag(DTV_PLAYER_OPERA_IME))
        {
            result = MMI_TRUE;
        }
        else if ((x1 <= pos.x) && (x2 >= pos.x) && (y1 <= pos.y) && (y2 >= pos.y))
        {
            result = MMI_TRUE;
        }
    }
    if (MMI_TRUE == result)
    {
        opera_webview_api_pen_event(event,opera_pos);
    }
    
    return result;
}
/*****************************************************************************
 * FunctionName: mmi_dtv_player_opera_engine_init_boot_up
 * Description
 *    Init opera engine when phone boot up   
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2011-12-17
 *****************************************************************************/
void mmi_dtv_player_opera_engine_init_boot_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    opera_webview_api_init();
}

/*****************************************************************************
 * FunctionName: mmi_dtv_player_free_opera_layer_memory
 * Description
 *  free the opera layer memory    
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2011-12-19
 *****************************************************************************/
void mmi_dtv_player_free_opera_layer_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GDI_LAYER_EMPTY_HANDLE != dtv_player_p->opera_layer_handle)
    {
        gdi_layer_free(dtv_player_p->opera_layer_handle);
        dtv_player_p->opera_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }
    if (NULL != dtv_player_p->opera_layer_buf_ptr)
    {
        applib_asm_free_r(GRP_ID_DTV_PLAYER, (void *) dtv_player_p->opera_layer_buf_ptr);
        dtv_player_p->opera_layer_buf_ptr = NULL;
    }
}
/*****************************************************************************
 * FunctionName: mmi_dtv_player_alloc_opera_layer_memory
 * Description
 *     
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2011-12-19
 *****************************************************************************/
void mmi_dtv_player_alloc_opera_layer_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	dtv_player_p->opera_layer_buf_ptr = (PU8) applib_asm_alloc_nc_r(GRP_ID_DTV_PLAYER, 
			                                                    MMI_DTV_PLAYER_DLS_BUFFER_SIZE*2);
    ASSERT(NULL != dtv_player_p->opera_layer_buf_ptr);
    gdi_layer_create_double_using_outside_memory(0,
                                                 0,
                                                 DTV_PLAYER_DLS_BUFFER_WIDTH,
                                                 DTV_PLAYER_DLS_BUFFER_HEIGHT,
                                                 &dtv_player_p->opera_layer_handle,
                                                 (PU8) dtv_player_p->opera_layer_buf_ptr,
                                                 (S32) MMI_DTV_PLAYER_DLS_BUFFER_SIZE*2);
    gdi_layer_push_and_set_active(dtv_player_p->opera_layer_handle);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
}

/*****************************************************************************
 * FunctionName: mmi_dtv_player_inter_fullscreen_pen_down_hdlr
 * Description
 *  inter fullscreen pen down hdlr   
 * Input Parameter
 *    pos--pen position
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2011-12-20
 *****************************************************************************/
void mmi_dtv_player_inter_fullscreen_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result =  mmi_dtv_player_opera_engine_pen_event(pos,OP_WEBVIEW_PENEVENT_DOWN);
    if (MMI_FALSE == result)
    {
        wgui_general_pen_down_hdlr(pos);
    }
    
}
/*****************************************************************************
 * FunctionName: mmi_dtv_player_inter_fullscreen_pen_up_hdlr
 * Description
 *  inter full screen pen up hdlr   
 * Input Parameter
 *    pos--pen position
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2011-12-20
 *****************************************************************************/
void mmi_dtv_player_inter_fullscreen_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result =  mmi_dtv_player_opera_engine_pen_event(pos,OP_WEBVIEW_PENEVENT_UP);
    if (MMI_FALSE == result)
    {
        wgui_general_pen_up_hdlr(pos);
    }
}

/*****************************************************************************
 * FunctionName: mmi_dtv_player_inter_fullscreen_pen_move_hdlr
 * Description
 *  inter fullscreen pen move hdlr   
 * Input Parameter
 *    pos--pen position
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2011-12-20
 *****************************************************************************/
void mmi_dtv_player_inter_fullscreen_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result =  mmi_dtv_player_opera_engine_pen_event(pos,OP_WEBVIEW_PENEVENT_MOVE);
    if (MMI_FALSE == result)
    {
        wgui_general_pen_move_hdlr(pos);
    }
}

#endif /* __MBBMS_V30_OPERA__ */

#ifdef CMMB_CAS_2GPP_V10
S32 mmi_dtv_player_set_emm(U32 emm_len, U8* emm_data)
{
	kal_prompt_trace(MOD_MMI, "Yaling test Line = %d", __LINE__);
	
	return mdi_mtv_set_emm(dtv_player_p->mtv_handle, emm_len, emm_data);
}

S32 mmi_dtv_player_set_emm_done(U32 emm_len, U8* emm_data)
{
	kal_prompt_trace(MOD_MMI, "Yaling test Line = %d", __LINE__);
	return mdi_mtv_set_emm(dtv_player_p->mtv_handle, emm_len, emm_data);
}

S32 mmi_dtv_player_get_nit_time(void *nit_time)
{
	kal_prompt_trace(MOD_MMI, "Yaling test Line = %d", __LINE__);

	return mdi_mtv_get_nit_time(dtv_player_p->mtv_handle, (mdi_mtv_nit_time_struct*)nit_time);
}
S32 mmi_dtv_player_get_nit_area_code(U8* net_mode, U16* area_code)
{
	kal_prompt_trace(MOD_MMI, "Yaling test Line = %d", __LINE__);

	return mdi_mtv_get_nit_area_code(dtv_player_p->mtv_handle, net_mode, area_code);
}

S32 mmi_dtv_player_ca_query(U32 block_len , U32* block_data)
{
	S32 result = 0;
	kal_prompt_trace(MOD_MMI, "Yaling test block_len = %d, Line = %d", block_len, __LINE__);
#ifdef 	__MMI_CMMB_CAS_2GPP_SUPPORT__
	if(!KERNEL_STATE_IN(DTV_KERNEL_CLOSED) && !KERNEL_STATE_IN(DTV_KERNEL_CLOSING) &&
		!KERNEL_STATE_IN(DTV_KERNEL_INIT))
    {
    	kal_prompt_trace(MOD_MMI, "Yaling test Line = %d", __LINE__);
		result = mdi_mtv_ca_query(dtv_player_p->mtv_handle, block_len , block_data);
	}
	else
    {
    	kal_prompt_trace(MOD_MMI, "Yaling test Line = %d", __LINE__);
		result = -1;
		mmi_cmmb_2gpp_adp_notify(EVT_ID_CMMB_2GPP_MMI_CA_DONE, -1, NULL);
    }
#endif
    return result;
}

void** mmi_dtv_player_util_alloc_mem(S32 buf_size)
{
	kal_prompt_trace(MOD_MMI, "Yaling test Line = %d", __LINE__);

	return MMI_FRM_ADM_ALLOC_FRAMEBUFFER(dtv_player_p->adm_pool_id, buf_size);	
}

void mmi_dtv_player_util_free_mem(U8* ptr)
{
	kal_prompt_trace(MOD_MMI, "Yaling test Line = %d", __LINE__);

	kal_adm_free(dtv_player_p->adm_pool_id, ptr);
}
#endif


#endif /* __MMI_DTV_CMMB_SUPPORT__ */

