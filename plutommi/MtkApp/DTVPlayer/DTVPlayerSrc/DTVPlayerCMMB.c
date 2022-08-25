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
 *  MobileTVPlayerCAS.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Mobile TV to support conditional access.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!

Dear Jiaowei:

 please help to resovle this issue, thanks~


[Jiaowei, 02/24]

Dear Ruoyao:

   UI里面说明，当获取密钥失败时，提示信息为：“移动网络信号弱，获取订购信息失败，请稍后再试”，网络连接失败时提示“网络连接错误”。两个String都是有的，这条case的log里面返回的是MSK_Retrieve_down的param是-6019,所以需要你和Stella进一步确认。其它你需要的信息见Notes。




[Ruoyao, 02/24]

Dear Jiaowei:

 请先帮忙确认test case中的string是否和Spec有冲突，如果有冲突的话我们可以和smart phone/CMCC确认。thanks~


[Jiaowei, 02/24]

Dear Ruoyao:

    我这边看过了，我这边没有提示语“提示移动网络信号弱，获取订购信息失败，请稍后再试”，请看下，是否是MDI的error code对应的String，


[Ruoyao, 02/23]

Dear Jiaowei:

 请先帮忙看一下这个字串问题。

thanks~

 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMI_include.h"
#include "mmi_features.h"

#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
#include "mmi_features_dtv_player.h"
#include "SettingDefs.h"        /* ST_NOTIFYDURATION define */
#include "SettingProfile.h"
#include "gui.h"                /* Gui functions */
#include "FileMgrSrvGProt.h"
#include "FileManagerGprot.h"
#include "ScreenRotationGprot.h"
#include "CommonScreens.h"
#include "FileManagerGProt.h"   /* file path / file error */
#include "FileManagerDef.h"     /* for ImageViewer's Screen ID - SCR_FMGR_EXPLORER */
#include "FileMgr.h"
#include "mmiapi_enum.h"                /* Stop LED */
#include "AlarmFrameworkProt.h"
#include "CallManagementGprot.h"
#include "GpioSrvGprot.h"
#include "USBDeviceGprot.h"
#include "cbm_api.h"
#include "cbm_consts.h"
#include "gdi_include.h"
#include "gdi_2d_engine.h"
#include "DtcntSrvIprot.h"

#include "gui_font_size.h"
#include "gui_effect_oem.h"
#include "ReminderSrvGprot.h"
#include "DataAccountCUIGprot.h"
#include "DataAccountGprot.h"
#include "app_md5.h"
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

#include "DTVPlayerEnum.h"
#include "DTVPlayerResDef.h"
#include "DTVPlayerGprot.h"
#include "DTVPlayer.h"
#include "DTVPlayerOSD.h"
#include "DTVPlayerMBBMS.h"

#include "MMI_media_app_trc.h"
#include "ProfilesSrvGprot.h"

#include "mtv_esg_query_datatype.h"
#include "DateTimeType.h"
#include "mtv_comm.h"
#ifdef __COSMOS_MMI_PACKAGE__
#include "mmi_rp_app_dtv_mbbms_esg_def.h"
#else
#include "mmi_rp_app_mainmenu_def.h"
#endif
#include "mmi_rp_srv_reminder_def.h"

#include "CommonScreensResDef.h"
#include "TimerEvents.h"

#ifdef __DM_LAWMO_SUPPORT__
#include "mmiapi_dm_struct.h"
#include "dmuigprot.h"
#endif
#include "UcmSrvGprot.h"
#include "UCMGProt.h"

/* removable */
#include "MainMenuDef.h"        /* Multimedia icon */

/* IMSI*/
#include "SimCtrlSrvGprot.h"

/* GDI */
#include "gdi_util.h"
#include "gdi_include.h"
#include "custom_events_notify.h"
#include "Gui_effect_oem.h"

#include "MenuCuiGProt.h"
#include "FileMgrCuiGProt.h"
#include "FSEditorCuiGProt.h"
#include "InlineCuiGProt.h"
#include "BTMMISCOPathGprots.h"
#include "DataAccountCUIGprot.h"
#include "NwInfoSrvGprot.h"
#include "BrowserSrvGprot.h"
#include "Cbm_api.h"

#include "DataAccountGProt.h"
#include "app_buff_alloc.h"
#ifdef __DM_FOTA_SUPPORT__
#include "DMSrvGprot.h"
#endif

/* Inline: caption string */
static const cui_inline_item_caption_struct g_dtv_program_remind_time_caption =
{
    STR_ID_DTV_PLAYER_PROGRAM_REMIND_TIME
};
static const cui_inline_item_caption_struct g_dtv_data_account_caption =
{
    STR_ID_DTV_PLAYER_APN
};
static const cui_inline_item_caption_struct g_dtv_use_proxy_caption =
{
    STR_ID_DTV_PLAYER_USE_PROXY
};
static const cui_inline_item_caption_struct g_dtv_proxy_server_caption =
{
    STR_ID_DTV_PLAYER_PROXY_SERVER
};
static const cui_inline_item_caption_struct g_dtv_proxy_port_caption =
{
    STR_ID_DTV_PLAYER_PROXY_PORT
};
static const cui_inline_item_caption_struct g_dtv_sg_proxy_server_caption =
{
    STR_ID_DTV_PLAYER_SG_PROXY_SERVER
};
static const cui_inline_item_caption_struct g_dtv_sg_proxy_port_caption =
{
    STR_ID_DTV_PLAYER_SG_PROXY_PORT
};
static const cui_inline_item_caption_struct g_dtv_keyword_caption =
{
    STR_ID_DTV_PLAYER_KEYWORD
};
static const cui_inline_item_caption_struct g_dtv_channel_caption =
{
    STR_ID_DTV_PLAYER_CHANNEL
};
static const cui_inline_item_caption_struct g_dtv_date_caption =
{
    STR_ID_DTV_PLAYER_DATE
};
#ifdef __MBBMS_INTER__
static const cui_inline_item_caption_struct g_dtv_inter_arrive_caption =
{
    STR_ID_DTV_WHEN_INTER_ARRIVE
};
#endif /* __MBBMS_INTER__ */
#ifdef __MBBMS_CITY_LIST__
static const cui_inline_item_caption_struct g_dtv_user_loc_info_caption =
{
    STR_ID_DTV_USER_LOCATION_INFO
};
#endif /* __MBBMS_CITY_LIST__ */
#ifdef __MBBMS_UPGRADE__
static const cui_inline_item_caption_struct g_dtv_client_upgrade_caption =
{
    STR_ID_DTV_CLIENT_UPGRADE
};
#endif /* __MBBMS_UPGRADE__ */
/* Inline: selector string */
static const U16 g_dtv_cl_remind_time_str[] =
    {STR_GLOBAL_OFF,
     STR_ID_DTV_PLAYER_2_MINS_ADV,
     STR_ID_DTV_PLAYER_5_MINS_ADV,
     STR_ID_DTV_PLAYER_10_MINS_ADV};


static const U16 g_dtv_cl_use_proxy_str[] =
    {STR_GLOBAL_OFF,
     STR_GLOBAL_ON};

static const U16 g_dtv_cl_search_date_str[] =
    {STR_ID_DTV_PLAYER_ALL,
     STR_ID_DTV_PLAYER_TODAY,
     STR_ID_DTV_PLAYER_TOMORROW,
     STR_ID_DTV_PLAYER_ADJUST_N1};

/* Inline: selector */
static const cui_inline_item_select_struct g_dtv_program_remind_time_selector =
{
    4,
    0,
    g_dtv_cl_remind_time_str
};

static const cui_inline_item_select_struct g_dtv_use_proxy_selector =
{
    2,
    0,
    g_dtv_cl_use_proxy_str
};

static const cui_inline_item_select_struct g_dtv_search_date_selector =
{
    4,
    0,
    g_dtv_cl_search_date_str
};

#ifdef __MBBMS_DUAL_SIM_SUPPORT__
static U16 g_dtv_simcard_str[] =
{    STR_ID_DTV_SIM1,
     STR_ID_DTV_SIM2
};

static const cui_inline_item_caption_struct g_dtv_simcard_caption =
{
	STR_ID_DTV_SIM_CARD_CAPTION
};

static cui_inline_item_select_struct g_dtv_simcard_selector =
{
	DTV_PLAYER_SIMCARD_NUM,
	0,
	g_dtv_simcard_str
};
#endif

#ifdef __MBBMS_CITY_LIST__
/* Inline: radio list */
static const cui_inline_item_radio_list_struct g_dtv_user_loc_info_radio_list =
{
    DTV_PLAYER_RADIO_NUM,
    0,
    NULL//g_dtv_cl_loc_info_str 
};
#endif /* __MBBMS_CITY_LIST__ */

#ifdef __MBBMS_INTER__
/* Inline: check box */
static const cui_inline_item_checkbox_struct g_dtv_inter_arrive_check_box =
{
    MMI_TRUE,
    NULL //g_dtv_cl_inter_arrive_str
};
#endif /* __MBBMS_INTER__ */

#ifdef __MBBMS_UPGRADE__
/* Inline: display only */
static const cui_inline_item_display_only_struct g_dtv_detect_new_disp_only =
{
    STR_ID_DTV_DETECT_NEW_VERSION,
    STR_ID_DTV_DETECT_NEW_VERSION
};
#endif /* __MBBMS_UPGRADE__ */

/* Inline: text edit */
static const cui_inline_item_text_edit_struct g_dtv_proxy_port_text_edit =
{
    0,
    0,
    MMI_DTV_MAX_PORT_LEN,
    IMM_INPUT_TYPE_NUMERIC,
    IMM_INPUT_TYPE_NUMERIC,
    NULL
};

static const cui_inline_item_text_edit_struct g_dtv_sg_proxy_addr_text_edit =
{
    0,
    0,
    MMI_DTV_MAX_SG_ADDR_LEN,
    IMM_INPUT_TYPE_URL,
    IMM_INPUT_TYPE_URL,
    NULL
};

static const cui_inline_item_text_edit_struct g_dtv_sg_proxy_port_text_edit =
{
    0,
    0,
    MMI_DTV_MAX_PORT_LEN,
    IMM_INPUT_TYPE_NUMERIC,
    IMM_INPUT_TYPE_NUMERIC,
    NULL
};

static const cui_inline_item_text_edit_struct g_dtv_keyword_text_edit =
{
    0,
    0,
    MMI_DTV_MAX_KEYWORD_LEN,
    IMM_INPUT_TYPE_SENTENCE,
    IMM_INPUT_TYPE_SENTENCE,
    NULL
};

/* Inline item struct */
static const cui_inline_set_item_struct g_dtv_cl_setting_item[] =
{
    {MMI_DTV_PROGRAM_REMIND_TIME_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION,       0, (void*)&g_dtv_program_remind_time_caption},
    {MMI_DTV_PROGRAM_REMIND_TIME_SELECTOR,  CUI_INLINE_ITEM_TYPE_SELECT,        0, (void*)&g_dtv_program_remind_time_selector},
#ifdef __MBBMS_DUAL_SIM_SUPPORT__
	{MMI_DTV_SIMCARD_CAPTION,			CUI_INLINE_ITEM_TYPE_CAPTION,		0, (void*)&g_dtv_simcard_caption},
	{MMI_DTV_SIMCARD_SELECTOR,			CUI_INLINE_ITEM_TYPE_SELECT,		0,						(void*)&g_dtv_simcard_selector},
#endif
#ifdef __MBBMS_INTER__
    {MMI_DTV_INTER_ARRIVE_CAPTION,      CUI_INLINE_ITEM_TYPE_CAPTION,       0, (void*)&g_dtv_inter_arrive_caption},
    {MMI_DTV_INTER_ARRIVE_CHECK_BOX,    CUI_INLINE_ITEM_TYPE_CHECKBOX,      0, (void*)&g_dtv_inter_arrive_check_box},
#endif /* __MBBMS_INTER__ */
#ifdef __MBBMS_CITY_LIST__
    {MMI_DTV_USER_LOC_INFO_CAPTION,     CUI_INLINE_ITEM_TYPE_CAPTION,       0, (void*)&g_dtv_user_loc_info_caption},
    {MMI_DTV_USER_LOC_INFO_RADIO_LIST,  CUI_INLINE_ITEM_TYPE_RADIO_LIST,    0, (void*)&g_dtv_user_loc_info_radio_list},
#endif /* __MBBMS_CITY_LIST__ */
#ifdef __MBBMS_UPGRADE__
    {MMI_DTV_CLIENT_UPGRADE_CAPTION,    CUI_INLINE_ITEM_TYPE_CAPTION,       0, (void*)&g_dtv_client_upgrade_caption},
    {MMI_DTV_DETECT_NEW_DISPLAY_ONLY,   CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,  0, (void*)&g_dtv_detect_new_disp_only},
#endif /* __MBBMS_UPGRADE__ */
    {MMI_DTV_DATA_ACCOUNT_CAPTION,          CUI_INLINE_ITEM_TYPE_CAPTION,       0, (void*)&g_dtv_data_account_caption},
    {MMI_DTV_DATA_ACCOUNT_SELECTOR,         CUI_INLINE_ITEM_TYPE_SELECT,        0, NULL},
    {MMI_DTV_USE_PROXY_CAPTION,             CUI_INLINE_ITEM_TYPE_CAPTION,       0, (void*)&g_dtv_use_proxy_caption},
    {MMI_DTV_USE_PROXY_SELECTOR,            CUI_INLINE_ITEM_TYPE_SELECT,        0, (void*)&g_dtv_use_proxy_selector},
    {MMI_DTV_PROXY_SERVER_CAPTION,          CUI_INLINE_ITEM_TYPE_CAPTION,       0, (void*)&g_dtv_proxy_server_caption},
    {MMI_DTV_PROXY_SERVER_IP4,              CUI_INLINE_ITEM_TYPE_IP4,           0, NULL},
    {MMI_DTV_PROXY_PORT_CAPTION,            CUI_INLINE_ITEM_TYPE_CAPTION,       0, (void*)&g_dtv_proxy_port_caption},
    {MMI_DTV_PROXY_PORT_TEXT_EDIT,          CUI_INLINE_ITEM_TYPE_TEXT_EDIT,     0, (void*)&g_dtv_proxy_port_text_edit},
    {MMI_DTV_SG_SERVER_CAPTION,             CUI_INLINE_ITEM_TYPE_CAPTION,       0, (void*)&g_dtv_sg_proxy_server_caption},
    {MMI_DTV_SG_SERVER_TEXT_EDIT,           CUI_INLINE_ITEM_TYPE_TEXT_EDIT,     0, (void*)&g_dtv_sg_proxy_addr_text_edit},
    {MMI_DTV_SG_SERVER_PORT_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION,       0, (void*)&g_dtv_sg_proxy_port_caption},
    {MMI_DTV_SG_SERVER_PORT_TEXT_EDIT,      CUI_INLINE_ITEM_TYPE_TEXT_EDIT,     0, (void*)&g_dtv_sg_proxy_port_text_edit}
};

static const cui_inline_set_item_struct g_dtv_search_program_item[] =
{
    {MMI_DTV_KEYWORD_CAPTION,       CUI_INLINE_ITEM_TYPE_CAPTION,       0, (void*)&g_dtv_keyword_caption},
    {MMI_DTV_KEYWORD_TEXT_EDIT,     CUI_INLINE_ITEM_TYPE_TEXT_EDIT,     0, (void*)&g_dtv_keyword_text_edit},
    {MMI_DTV_CHANNEL_CAPTION,       CUI_INLINE_ITEM_TYPE_CAPTION,       0, (void*)&g_dtv_channel_caption},
    {MMI_DTV_CHANNEL_SELECTOR,      CUI_INLINE_ITEM_TYPE_SELECT,        0, NULL},
    {MMI_DTV_DATE_CAPTION,          CUI_INLINE_ITEM_TYPE_CAPTION,       0, (void*)&g_dtv_date_caption},
    {MMI_DTV_DATE_SELECTOR,         CUI_INLINE_ITEM_TYPE_SELECT,        0, (void*)&g_dtv_search_date_selector}
};

/* cl setting softkey */
static const cui_inline_item_softkey_struct g_dtv_cl_setting_inline_softkey =
{
    {
        {STR_GLOBAL_OPTIONS, 0},                     /*MMI_LEFT_SOFTKEY*/
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},       /*MMI_RIGHT_SOFTKEY*/
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0}        /*MMI_CENTER_SOFTKEY*/
    }
};


/* Inline struct */
static const cui_inline_struct g_dtv_cl_setting_inline =
{
#ifdef __MBBMS_CITY_LIST__
    sizeof(g_dtv_cl_setting_item)/sizeof(g_dtv_cl_setting_item[0]) + (DTV_PLAYER_RADIO_NUM - 1),
#else 
    sizeof(g_dtv_cl_setting_item)/sizeof(g_dtv_cl_setting_item[0]),
#endif 
    STR_GLOBAL_SETTINGS,
    0,
    CUI_INLINE_SCREEN_DEFAULT_TEXT | CUI_INLINE_SCREEN_DISABLE_DONE,
    &g_dtv_cl_setting_inline_softkey,
     g_dtv_cl_setting_item
};

static const cui_inline_struct g_dtv_search_program_inline =
{
    sizeof(g_dtv_search_program_item)/sizeof(g_dtv_search_program_item[0]),
    STR_ID_DTV_PLAYER_SEARCH_PROGRAM,
    0,
    CUI_INLINE_SCREEN_DEFAULT_TEXT | CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    g_dtv_search_program_item
};

static U32 g_dtv_cl_setting_dcnt_id_list[SRV_DTCNT_PROF_MAX_ACCOUNT_NUM];
static U32 g_dtv_cl_setting_dcnt_id_list_count = 0;

static U32 mmi_dtv_player_default_dtcnt(CHAR *apn);

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_ip4_to_address
 * DESCRIPTION
 *  get the proxy address from ip4 format
 * PARAMETERS
 *  proxy_address, proxy_ip4
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_ip4_to_address(U8 * proxy_ip4, CHAR *proxy_address)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 temp1 = 0;
	U8 temp2 = 0;
	CHAR ch = '0';
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (temp1 = 0; temp1 < 4; temp1++)
	{
		temp2 = proxy_ip4[temp1];
		
		*proxy_address = ch + (temp2/100);
        proxy_address++;
		
		*proxy_address = ch + ((temp2/10)%10);
		proxy_address++;		
		
		*proxy_address = ch + (temp2%10);		
		proxy_address++;
		
		*proxy_address = '.';
		proxy_address++;
	}
		proxy_address--;
		*proxy_address = '\0';
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_address_to_ip4
 * DESCRIPTION
 *  get the proxy ip4 from address format
 * PARAMETERS
 *  proxy_address, proxy_ip4
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_dtv_player_address_to_ip4(CHAR *proxy_address, U8 *proxy_ip4)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U8 temp1 = 0;
	U8 temp2 = 0;
	U8 temp3 = 0;
	U8 ch = '0';
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	for (temp1 = 0; temp1 < 4; temp1++)
	{
		proxy_ip4[temp1] = 0;
		while(('.' != proxy_address[temp2])
			  && ('\0' != proxy_address[temp2]))
		{
			temp3 = proxy_address[temp2] - ch;
			proxy_ip4[temp1] = proxy_ip4[temp1] * 10 + temp3;
			temp2++;
		}
		temp2++;
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_hex_to_ascii
 * DESCRIPTION
 *  hex to ascii
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_hex_to_ascii(U8 *src, U8 *dest, U32 src_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i, j;
    kal_uint8 curr_byte[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < src_len; i++)
    {
        curr_byte[0] = (src[i] & 0xF0) >> 4;
        curr_byte[1] = src[i] & 0x0F;
        for (j = 0; j < 2; j++)
        {
            if (curr_byte[j] < 10)
            {
                curr_byte[j] += '0';
            }
            else if(curr_byte[j] < 16)
            {
                curr_byte[j] = curr_byte[j] - 10 + 'A';
            }
            *dest++ = curr_byte[j];
        }
    }
    *dest = '\0';
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_caculate_entity_body_md5
 * DESCRIPTION
 *  caculate md5(entity-body) for WPS/STK
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_to_md5(U8* entity_body, U32 body_len, U8 *hash_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_md5_ctx md5_ctx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_md5_init(&md5_ctx);
    applib_md5_update(&md5_ctx, entity_body, body_len);
    applib_md5_final(hash_result, &md5_ctx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_print_md5_string
 * DESCRIPTION
 *  get init param
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
void mmi_dtv_player_print_md5_string(U8 *previous, U8* current)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 md5_string[(MMI_DTV_MD5_LEN<<1) + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Print original one */
    mmi_dtv_player_hex_to_ascii(
        previous, md5_string, MMI_DTV_MD5_LEN);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_IMSI_MD5,
    md5_string[0], md5_string[1], md5_string[2], md5_string[3],
    md5_string[4], md5_string[5], md5_string[6], md5_string[7],
    md5_string[8], md5_string[9], md5_string[10], md5_string[11],
    md5_string[12], md5_string[13], md5_string[14], md5_string[15],
    md5_string[16], md5_string[17], md5_string[18], md5_string[19],
    md5_string[20], md5_string[21], md5_string[22], md5_string[23],
    md5_string[24], md5_string[25], md5_string[26], md5_string[27],
    md5_string[28], md5_string[29], md5_string[30], md5_string[31]);

    /* Print original one */
    mmi_dtv_player_hex_to_ascii(
        current, md5_string, MMI_DTV_MD5_LEN);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_IMSI_MD5,
    md5_string[0], md5_string[1], md5_string[2], md5_string[3],
    md5_string[4], md5_string[5], md5_string[6], md5_string[7],
    md5_string[8], md5_string[9], md5_string[10], md5_string[11],
    md5_string[12], md5_string[13], md5_string[14], md5_string[15],
    md5_string[16], md5_string[17], md5_string[18], md5_string[19],
    md5_string[20], md5_string[21], md5_string[22], md5_string[23],
    md5_string[24], md5_string[25], md5_string[26], md5_string[27],
    md5_string[28], md5_string[29], md5_string[30], md5_string[31]);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_cas_get_sim_struct
 * DESCRIPTION
 *  get init param
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MMI_BOOL mmi_dtv_cas_get_sim_struct(mdi_mtv_cas_sim_struct *sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_location_info_struct loc_info;
    CHAR plmn[SRV_MAX_PLMN_LEN + 1];
    CHAR mnc_digit3;
    srv_nw_info_service_availability_enum avail;
    MMI_BOOL dtcnt_ready;
    S32 cmp;
    CHAR imsi[17];
    U8 hash_result[MMI_DTV_MD5_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if !defined(__CMMB_CAS_MBBMS_SUPPORT__)
    return MMI_FALSE;
#endif /* !defined(__CMMB_CAS_MBBMS_SUPPORT__) */

#ifndef __MTK_TARGET__
    if (g_mtv_demod_sim == 1)
    {
        /* Use MFS file */
        return MMI_FALSE;
    }
    else
    {
        /* Use DB file to entry MBBMS mode */
        return MMI_TRUE;
    }
#endif /* !defined(__MTK_TARGET__) */

    avail = srv_nw_info_get_service_availability(dtv_player_p->cur_sim);
    if (avail != SRV_NW_INFO_SA_FULL_SERVICE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
			      MMI_TRC_DTV_VAL2, 
			      dtv_player_p->cur_sim, 
			      avail, 
			      __LINE__);
		#ifdef __MBBMS_DUAL_SIM_SUPPORT__
			avail = srv_nw_info_get_service_availability(DTV_PLAYER_OTHER_SIM(dtv_player_p->cur_sim));
			if (SRV_NW_INFO_SA_FULL_SERVICE == avail)
			{				
				dtv_player_p->cur_sim = DTV_PLAYER_OTHER_SIM(dtv_player_p->cur_sim); 					
				MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
					      MMI_TRC_DTV_VAL2, 
					      dtv_player_p->cur_sim, 
					      avail, 
					      __LINE__);
			}
			else
			{
				MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
					      MMI_TRC_DTV_VAL2, 
					      DTV_PLAYER_OTHER_SIM(dtv_player_p->cur_sim), 
					      avail, 
					      __LINE__);
				return MMI_FALSE;
			}		
		#else
        	return MMI_FALSE;
		#endif
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
	      MMI_TRC_DTV_VAL2, 
	      dtv_player_p->cur_sim, 
	      avail, 
	      __LINE__);
#ifdef __COSMOS_MMI_PACKAGE__
    dtcnt_ready = vapp_dtcnt_ready_check(
                    mmi_dtv_player_dtcnt_ready_calback, MMI_FALSE);
#else /*  __COSMOS_MMI_PACKAGE__ */
    dtcnt_ready = mmi_dtcnt_ready_check(
                    mmi_dtv_player_dtcnt_ready_calback, MMI_FALSE);
#endif /*  __COSMOS_MMI_PACKAGE__ */

    
    if (!dtcnt_ready)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL1, dtcnt_ready, __LINE__);
        return MMI_FALSE;
    }

    sim->is_usim = srv_sim_ctrl_is_usim(dtv_player_p->cur_sim);
    //ry
    sim->sim_id = dtv_player_p->cur_sim;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
		      MMI_TRC_DTV_VAL1, 
		      sim->is_usim, 
		      __LINE__);

    srv_sim_ctrl_get_home_plmn(dtv_player_p->cur_sim, plmn, SRV_MAX_PLMN_LEN + 1);
    srv_sim_ctrl_get_imsi(dtv_player_p->cur_sim, imsi, SRV_MAX_IMSI_LEN + 1);
    srv_nw_info_get_location_info(dtv_player_p->cur_sim, &loc_info);

    mmi_dtv_player_to_md5(imsi, SRV_MAX_IMSI_LEN, hash_result);

    mmi_dtv_player_print_md5_string(dtv_player_p->setting.imsi, hash_result);
    cmp = kal_mem_cmp(dtv_player_p->setting.imsi, hash_result, MMI_DTV_MD5_LEN);
    if (cmp)
    {
        kal_mem_cpy(dtv_player_p->setting.imsi, hash_result, MMI_DTV_MD5_LEN);

        mmi_dtv_player_store_setting();
        sim->same_imsi = MMI_FALSE;
    }
    else
    {
        sim->same_imsi = MMI_TRUE;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_SAME_IMSI, sim->same_imsi);

    kal_mem_cpy(sim->imsi, &imsi[1], SRV_MAX_IMSI_LEN);

    mnc_digit3 = (0 == loc_info.plmn[5])? '0' : loc_info.plmn[5];
	
    kal_sprintf(sim->bdscell_id, "1-%c%c%c%c%c%c%04x%04x",
        loc_info.plmn[1], loc_info.plmn[0], mnc_digit3,
        loc_info.plmn[2], loc_info.plmn[4], loc_info.plmn[3],
        loc_info.lac, loc_info.cell_id);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_BDSCELL_ID,
        loc_info.plmn[1], loc_info.plmn[0], mnc_digit3,
        loc_info.plmn[2], loc_info.plmn[4], loc_info.plmn[3],
        loc_info.lac, loc_info.cell_id, loc_info.lac, loc_info.cell_id);
    return MMI_TRUE;
}

/*****************************************************************************
 * FunctionName: mmi_dtv_player_check_dtcnt_id
 * Description
 *     
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-03-09
 *****************************************************************************/
void mmi_dtv_player_check_dtcnt_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_dtcnt_sim_type_enum simType = MMI_SIM1;
	U32 dtcnt_id = 0;	
	srv_dtcnt_prof_str_info_qry_struct out_apn;	
    CHAR  apn_string_ucs[MMI_DTV_PLAYER_APN_LENGTH*2];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (MMI_SIM1 == dtv_player_p->cur_sim)
	{
		dtcnt_id = dtv_player_p->setting.data_account_id;
	}
	else
	{
		dtcnt_id = dtv_player_p->setting.sim2_data_account_id;
	}

	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
				  MMI_TRC_DTV_VAL3, 
				  dtv_player_p->cur_sim, 
				  dtcnt_id, 
				  simType,
				  __LINE__);

	srv_dtcnt_get_sim_info(dtcnt_id, &simType);

	if (simType != dtv_player_p->cur_sim)
	{
        out_apn.dest = &apn_string_ucs[0];
        out_apn.dest_len = MMI_DTV_PLAYER_APN_LENGTH;
        out_apn.req_len = MMI_DTV_PLAYER_APN_LENGTH;
        if (srv_dtcnt_get_apn(dtcnt_id, &out_apn, SRV_DTCNT_ACCOUNT_PRIMARY))
        {        	
			dtcnt_id = mmi_dtv_player_default_dtcnt((CHAR *)out_apn.dest);			
			if (0 == dtcnt_id)
			{
				dtcnt_id = mmi_dtv_player_default_dtcnt(NULL);	
			}
        }
		if (MMI_SIM1 == dtv_player_p->cur_sim)
		{
			dtv_player_p->setting.data_account_id = dtcnt_id;
		}
		else
		{
			dtv_player_p->setting.sim2_data_account_id = dtcnt_id;
		}
	}

	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
			  MMI_TRC_DTV_VAL3, 
			  dtv_player_p->cur_sim, 
			  dtcnt_id, 
			  simType,
			  __LINE__);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_cas_get_sim_struct
 * DESCRIPTION
 *  get init param
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MMI_BOOL mmi_dtv_cas_update_net_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_mtv_cas_net_struct net = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_dtv_player_check_dtcnt_id();
	if (MMI_SIM1 == dtv_player_p->cur_sim)
	{
	    net.net_id = cbm_encode_data_account_id(dtv_player_p->setting.data_account_id,
			                        			CBM_SIM_ID_SIM1,
	                                			dtv_player_p->setting.cbm_app_id,
	                                			MMI_FALSE);

		MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
				  MMI_TRC_DTV_VAL2, 
				  dtv_player_p->cur_sim, 
				  net.net_id, 
				  __LINE__);
		
	    net.app_id = dtv_player_p->cl_setting.cbm_app_id;		
	    net.use_proxy = dtv_player_p->setting.use_proxy;
	    /* Proxy */
	    net.prx_port = dtv_player_p->setting.proxy_port;
	    kal_mem_cpy(net.prx_ip,
	        		dtv_player_p->setting.proxy_server,
	        		MMI_DTV_PLAYER_PROXY_IP_COUNT);
	    /* SG URL */
	    net.sg_port = dtv_player_p->setting.sg_proxy_port;
	    mmi_ucs2_n_to_asc(net.sg_url,
				          (CHAR*)dtv_player_p->setting.sg_proxy_server,
				          (MMI_DTV_MAX_SG_ADDR_LEN - 1) << 1);
	}
	else
	{
		net.net_id = cbm_encode_data_account_id(dtv_player_p->setting.sim2_data_account_id,
			                        			CBM_SIM_ID_SIM2,
	                                			dtv_player_p->setting.cbm_app_id,
	                                			MMI_FALSE);

		MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
			  MMI_TRC_DTV_VAL2, 
			  dtv_player_p->cur_sim, 
			  net.net_id, 
			  __LINE__);
		
	    net.app_id = dtv_player_p->cl_setting.cbm_app_id;		
	    net.use_proxy = dtv_player_p->setting.sim2_use_proxy;
	    /* Proxy */
	    net.prx_port = dtv_player_p->setting.sim2_proxy_port;
	    kal_mem_cpy(net.prx_ip,
	        		dtv_player_p->setting.sim2_proxy_server,
	        		MMI_DTV_PLAYER_PROXY_IP_COUNT);
	    /* SG URL */
	    net.sg_port = dtv_player_p->setting.sim2_sg_proxy_port;
	    mmi_ucs2_n_to_asc(net.sg_url,
	                      (CHAR*)dtv_player_p->setting.sim2_sg_proxy_server,
	                      (MMI_DTV_MAX_SG_ADDR_LEN - 1) << 1);
	}
		
    mdi_mtv_set_net_info(dtv_player_p->mtv_handle, &net);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_dtcnt_ready_calback
 * DESCRIPTION
 *  settings save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_dtcnt_ready_calback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_service_availability_enum avail;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!KERNEL_STATE_IN(DTV_KERNEL_CLOSED) && !KERNEL_STATE_IN(DTV_KERNEL_CLOSING))
    {
        if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_CMMB)
        {
            avail = srv_nw_info_get_service_availability(dtv_player_p->cur_sim);
            if (avail == SRV_NW_INFO_SA_FULL_SERVICE)
            {
                StopTimer(DTV_PLAYER_NW_STATUS);
                StartTimer(
                    DTV_PLAYER_NW_STATUS,
                    30000,
                    mmi_dtv_player_enter_mbbms_mode_timeout);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_network_status_changed
 * DESCRIPTION
 *  settings save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dtv_player_network_status_changed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_service_availability_changed_evt_struct *avail_evt;
    MMI_BOOL dtcnt_ready;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avail_evt = (srv_nw_info_service_availability_changed_evt_struct*)evt;

    if (!KERNEL_STATE_IN(DTV_KERNEL_CLOSED) && !KERNEL_STATE_IN(DTV_KERNEL_CLOSING))
    {

        if ((SRV_NW_INFO_SA_FULL_SERVICE == avail_evt->new_status)
			&& (MMI_DTV_CA_STATE_CMMB == dtv_player_p->ca_state))
        {
        	dtv_player_p->cur_sim = avail_evt->sim;
			
			MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
				      MMI_TRC_DTV_VAL2, 
				      avail_evt->sim, 
				      avail_evt->new_status, 
				      __LINE__);
			
            #ifdef __COSMOS_MMI_PACKAGE__
                dtcnt_ready = vapp_dtcnt_ready_check(mmi_dtv_player_dtcnt_ready_calback, 
                                                     MMI_FALSE);
            #else /*  __COSMOS_MMI_PACKAGE__ */
                dtcnt_ready = mmi_dtcnt_ready_check(mmi_dtv_player_dtcnt_ready_calback, 
                                                    MMI_FALSE);
            #endif /*  __COSMOS_MMI_PACKAGE__ */    

                if (dtcnt_ready)
                {
                    StopTimer(DTV_PLAYER_NW_STATUS);
                    StartTimer(DTV_PLAYER_NW_STATUS, 30000, mmi_dtv_player_enter_mbbms_mode_timeout);
                }
        }

    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_to_applib_time
 * DESCRIPTION
 *  settings save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_dtv_player_to_applib_time(WCHAR *time, applib_time_struct *output_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 out_num, read_len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* YYYY-MM-DD HH:MM:SS */

    /* YYYY */
    mmi_ucs2toi((CHAR *) time, &out_num, &read_len);
    if (read_len != 4)
        return MMI_FALSE;
    output_time->nYear = out_num;

    /* MM */
    mmi_ucs2toi((CHAR *) &time[5], &out_num, &read_len);
    if (read_len != 2)
        return MMI_FALSE;
    output_time->nMonth = out_num;

    /* DD */
    mmi_ucs2toi((CHAR *) &time[8], &out_num, &read_len);
    if (read_len != 2)
        return MMI_FALSE;
    output_time->nDay = out_num;

    /* HH */
    mmi_ucs2toi((CHAR *) &time[11], &out_num, &read_len);
    if (read_len != 2)
        return MMI_FALSE;
    output_time->nHour = out_num;

    /* MM */
    mmi_ucs2toi((CHAR *) &time[14], &out_num, &read_len);
    if (read_len != 2)
        return MMI_FALSE;
    output_time->nMin = out_num;

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_remind_offset_time
 * DESCRIPTION
 *  settings save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_dtv_player_get_remind_offset_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 remind_time = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (dtv_player_p->setting.pro_remind_time)
    {
        case DTV_PLAYER_PROG_REMIND_2:
            {
				remind_time =  2;
            	break;
        	}
        case DTV_PLAYER_PROG_REMIND_5:
			{
				remind_time =  5;
            	break;
        	}
        case DTV_PLAYER_PROG_REMIND_10:
			{
				remind_time = 10;
				break;
        	}
        default:
			{
            	break;
        	}
    }
    return remind_time;
}

#if defined (__COSMOS_MMI_PACKAGE__)

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_mbbms_esg_group_proc
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dtv_mbbms_esg_group_proc(mmi_event_struct *evt)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_mbbms_esg_launch
 * DESCRIPTION
 *  functions to launch mbbms ESG
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dtv_mbbms_esg_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_DTV_MBBMS_ESG, mmi_dtv_mbbms_esg_group_proc, NULL);
    if (id == GRP_ID_INVALID)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_mbbms_esg_launch
 * DESCRIPTION
 *  functions to launch mbbms ESG
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_mbbms_esg_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_group_close(GRP_ID_DTV_MBBMS_ESG);
}
#endif /* (__COSMOS_MMI_PACKAGE__) */

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_alarm_target
 * DESCRIPTION
 *  settings save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_get_alarm_target(
            MMI_BOOL include_now, mbbms_sg_query_content_struct **target, applib_time_struct *reminder_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct cur_time, offset_time = {0}, output_time, content_time;
    MDI_RESULT ret;
    mdi_mtv_query_struct query = {0};
    mbbms_sg_query_content_struct *content_p = NULL;
    S32 status;
    MMI_BOOL t_ret, found = MMI_FALSE;
    WCHAR time[15]; /* HH:MM-HH:MM */
    U32 db_handle = dtv_player_p->mtv_handle;
    MMI_BOOL stand_alone_db = MMI_FALSE;
    media_mtv_esg_source_enum source = MEDIA_MTV_ESG_SOURCE_DEFAULT;
#ifdef __COSMOS_MMI_PACKAGE__    
    MMI_BOOL launch_ret;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_GET_ALARM_TARGET);
    if (dtv_player_p->setting.pro_remind_time == DTV_PLAYER_PROG_REMIND_0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL1, 0, __LINE__);
        return MMI_FALSE;
    }

    mmi_dtv_player_get_current_system_time(&cur_time);
    offset_time.nMin = mmi_dtv_player_get_remind_offset_time();
    applib_dt_increase_time(&cur_time, &offset_time, &output_time);

    if (KERNEL_STATE_IN(DTV_KERNEL_CLOSED) ||
        KERNEL_STATE_IN(DTV_KERNEL_CLOSING) ||
        dtv_player_p->ca_state == MMI_DTV_CA_STATE_CMMB)
    {
        stand_alone_db = MMI_TRUE;
    }

    if (stand_alone_db)
    {
    #if defined (__COSMOS_MMI_PACKAGE__) 
        launch_ret = mmi_dtv_mbbms_esg_launch();
        if (!launch_ret)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL1, 0, __LINE__);
            return MMI_FALSE;
        }

        ret = mdi_mtv_open_stand_alone_db(GRP_ID_DTV_MBBMS_ESG, &db_handle);
    #else
        ret = mdi_mtv_open_stand_alone_db(0, &db_handle);
    #endif /* __COSMOS_MMI_PACKAGE__ */
    
        
        if (ret != MDI_RES_MTV_SUCCEED)
        {
        #if defined (__COSMOS_MMI_PACKAGE__)
            mmi_dtv_mbbms_esg_close();
        #endif      
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL1, 0, __LINE__);
            return MMI_FALSE;
        }
        source = MEDIA_MTV_ESG_SOURCE_MBBMS;
    }

    ret = mdi_mtv_esg_query(
            db_handle, source, ESG_QUERY_REMINDER_LIST, &query);

    if (ret != MDI_RES_MTV_SUCCEED)
    {
        /* handle error case */
        if (stand_alone_db)
        {
            mdi_mtv_close_stand_alone_db(db_handle);

        #if defined (__COSMOS_MMI_PACKAGE__)
            mmi_dtv_mbbms_esg_close();
        #endif     
        }
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL1, 0, __LINE__);
        return MMI_FALSE;
    }

    while(!found)
    {
        ret = mdi_mtv_esg_get_result(db_handle, source, ESG_QUERY_REMINDER_LIST, (void **)&content_p);
        if (content_p == NULL)
        {
            break;
        }

        while (content_p != NULL)
        {
            kal_mem_set(time, 0, sizeof(time));
            mmi_ucs2ncpy((CHAR*)time, (CHAR*)&content_p->start_time[11], 5);
            mmi_ucs2cat((CHAR*)time, (CHAR*)L"-");
            mmi_ucs2ncat((CHAR*)time, (CHAR*)&content_p->end_time[11], 5);

            if(include_now)
            {
                status = mmi_dtv_player_check_time_to_alarm_status(
                     &output_time, content_p->start_time, time);
            }
            else
            {
                status = mmi_dtv_player_check_time_status(
                    &output_time, content_p->start_time, time);
            }

            if (status == 1 || (include_now && status == 0))
            {
                /* Remind time */
                t_ret = mmi_dtv_player_to_applib_time(
                            content_p->start_time, &content_time);

                if (t_ret == MMI_TRUE)
                {
                    if (reminder_time)
                    {
                        applib_dt_decrease_time(
                            &content_time, &offset_time, reminder_time);
                        /* Only compare YYYY-MM-DD HH:MM */
                        reminder_time->nSec = 0;
                    }

                    if (target != NULL)
                    {
                        *target = content_p;
                    }

                    found = MMI_TRUE;
                    break;
                }
            }

            content_p = content_p->next_p;
        }
    }

    if (stand_alone_db)
    {
        mdi_mtv_close_stand_alone_db(db_handle);
    #if defined (__COSMOS_MMI_PACKAGE__) 
        mmi_dtv_mbbms_esg_close();
    #endif     
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL1, found, __LINE__);
    return found;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_enter_info_confirm_fullscreen
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_enter_info_confirm_fullscreen
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
void mmi_dtv_player_enter_info_confirm_fullscreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_scrn_enter(
                GRP_ID_ROOT,
                SCR_ID_DTV_PLAYER_CONFIRM,
                NULL,
                mmi_dtv_player_enter_info_confirm_fullscreen,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    /* suspend background play */
    mdi_audio_suspend_background_play();

    /* Call enable before showCategory, call change after showCategory */
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();


    ShowCategory151Screen(
        STR_ID_DTV_PLAYER_APP_NAME,
        DTV_PLAYER_MENU_ICON,
        STR_GLOBAL_OK,
        0,
        0,
        0,
        (U8*)dtv_player_p->info_str_buffer,
        NULL,
        guiBuffer);


    SetLeftSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_alarm_expiry
 * DESCRIPTION
 *  CallBack handler to execute todolist expiry.
 * PARAMETERS
 *  index           [IN]
 *  period          [?]
 *  power_on        [IN]
 *  BOOL(?)         [IN]        Power status
 *  U8(?)           [IN]        Index of alarm item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_alarm_expiry(BOOL power_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mbbms_sg_query_content_struct *output;
    MMI_BOOL ret;

    S32 mins;
    mmi_confirm_property_struct arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_ALARM_EXPIRY, power_on);
    /* Don't display the current alarm if not power on */
    if (!power_on)
    {
        return;
    }
    /* Init nvram first */
    mmi_dtv_player_load_setting();


    /* Already power on */
    ret = mmi_dtv_player_get_alarm_target(MMI_TRUE, &output, NULL);
    if (!ret && output != NULL)
    {
        return;
    }

    /* Time is up */
    mins = mmi_dtv_player_get_remind_offset_time();
    mmi_dtv_player_gen_separate_string(
            (WCHAR*)GetString(STR_ID_DTV_PLAYER_REMIND_TIME_UP),
            (WCHAR*)output->name,
            (WCHAR*)GetString(STR_GLOBAL_0 + mins));

    /* Display pop up in root */
/*
    mmi_confirm_property_init(&arg, CNFM_TYPE_OK);
    arg.callback = mmi_dtv_player_dummy_proc;
    arg.f_auto_map_empty_softkey = MMI_FALSE;

    mmi_confirm_display(
        dtv_player_p->info_str_buffer,
        MMI_EVENT_INFO,
        &arg);
*/

    mmi_dtv_player_enter_info_confirm_fullscreen();

    /* Update the next reminder time */
    srv_reminder_notify_finish(MMI_FALSE);
    mmi_dtv_player_update_alarm();
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_reinit_alarm
 * DESCRIPTION
 *  settings save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_reinit_alarm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    MYTIME alarm_time = {0};
    applib_time_struct reminder_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_REINIT_ALARM);

    /* Init nvram first */
    mmi_dtv_player_load_setting();

    ret = mmi_dtv_player_get_alarm_target(MMI_FALSE, NULL, &reminder_time);
    if (ret)
    {
        alarm_time.nYear = reminder_time.nYear;
        alarm_time.nMonth = reminder_time.nMonth;
        alarm_time.nDay = reminder_time.nDay;
        alarm_time.nHour = reminder_time.nHour;
        alarm_time.nMin = reminder_time.nMin;
        alarm_time.nSec = reminder_time.nSec;
        alarm_time.DayIndex = reminder_time.DayIndex; /* 0=Sunday */

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_ALARM_CALLBACK,
            reminder_time.nYear, reminder_time.nMonth, reminder_time.nDay,
            reminder_time.nHour, reminder_time.nMin, reminder_time.nSec);

        srv_reminder_set(SRV_REMINDER_TYPE_DTV, &alarm_time, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_update_alarm
 * DESCRIPTION
 *  settings save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_update_alarm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    MYTIME alarm_time = {0};
    applib_time_struct reminder_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_UPDATE_ALARM);

    srv_reminder_cancel(SRV_REMINDER_TYPE_DTV, 0);
    ret = mmi_dtv_player_get_alarm_target(MMI_FALSE, NULL, &reminder_time);
    if (MMI_TRUE == ret)
    {
        alarm_time.nYear = reminder_time.nYear;
        alarm_time.nMonth = reminder_time.nMonth;
        alarm_time.nDay = reminder_time.nDay;
        alarm_time.nHour = reminder_time.nHour;
        alarm_time.nMin = reminder_time.nMin;
        alarm_time.nSec = reminder_time.nSec;
        alarm_time.DayIndex = reminder_time.DayIndex; /* 0=Sunday */

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_ALARM_CALLBACK,
            reminder_time.nYear, reminder_time.nMonth, reminder_time.nDay,
            reminder_time.nHour, reminder_time.nMin, reminder_time.nSec);

        srv_reminder_set(SRV_REMINDER_TYPE_DTV, &alarm_time, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_alarm_event_handler
 * DESCRIPTION
 *  settings save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dtv_player_reminder_event_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	srv_reminder_evt_struct *reminder;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	if (evt->evt_id != EVT_ID_SRV_REMINDER_NOTIFY)
	{
		return MMI_RET_OK;
	}

	reminder = (srv_reminder_evt_struct *)evt;
	if (reminder->reminder_type != SRV_REMINDER_TYPE_DTV &&
		reminder->reminder_type != SRV_REMINDER_TYPE_TOTAL)
	{
		return MMI_RET_OK;
	}

	switch(reminder->notify)
	{
		case SRV_REMINDER_NOTIFY_EXPIRY:
			mmi_dtv_player_alarm_expiry(!reminder->pwr_off);
			break;
		case SRV_REMINDER_NOTIFY_REINIT:
			mmi_dtv_player_reinit_alarm();
			break;
		default:
			break;
	}

	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_default_dtcnt
 * DESCRIPTION
 *  mmi_dtv_player_default_dtcnt
 * PARAMETERS
 *  apn         :   [IN]        APN string (UCS2 string with NULL terminated)
 * RETURNS
 *  data account id
 *****************************************************************************/
static U32 mmi_dtv_player_default_dtcnt(CHAR *apn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR  apn_string_default[MMI_DTV_PLAYER_APN_LENGTH*2];
    CHAR  apn_string_ucs[MMI_DTV_PLAYER_APN_LENGTH*2];
    U32 i;
	srv_dtcnt_sim_type_enum simType = MMI_SIM1;
		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == apn)
    {
        memcpy(apn_string_default, L"cmwap", MMI_DTV_PLAYER_APN_LENGTH*2);
    }
    else
    {
        memcpy(apn_string_default, apn, MMI_DTV_PLAYER_APN_LENGTH*2);
    }
    for (i = 0; i < g_dtv_cl_setting_dcnt_id_list_count; i++)
    {
        srv_dtcnt_prof_str_info_qry_struct out_apn;

        out_apn.dest = &apn_string_ucs[0];
        out_apn.dest_len = MMI_DTV_PLAYER_APN_LENGTH;
        out_apn.req_len = MMI_DTV_PLAYER_APN_LENGTH;
        if (srv_dtcnt_get_apn(g_dtv_cl_setting_dcnt_id_list[i], &out_apn, SRV_DTCNT_ACCOUNT_PRIMARY))
        {
            if(!mmi_ucs2nicmp((CHAR *)out_apn.dest, (CHAR *)apn_string_default, MMI_DTV_PLAYER_APN_LENGTH))
            {
            	srv_dtcnt_get_sim_info(g_dtv_cl_setting_dcnt_id_list[i], &simType);
				if (simType == dtv_player_p->cur_sim)
				{
                	break;
				}
            }
        }
    }
	
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,
              MMI_TRC_DTV_VAL2, 
              i, 
              g_dtv_cl_setting_dcnt_id_list_count, 
              __LINE__);

    if (i == g_dtv_cl_setting_dcnt_id_list_count)
    {
        dtv_player_p->cl_setting.data_account_idx = 0;
        return 0;
    }
    else
    {
        dtv_player_p->cl_setting.data_account_idx = i;
        return g_dtv_cl_setting_dcnt_id_list[i];
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_cl_setting_load
 * DESCRIPTION
 *  mobile tv player cl setting load value from player main settings
 * PARAMETERS
 *  void
 * RETURNS
 *  error code
 *****************************************************************************/
static S32 mmi_dtv_player_cl_setting_load(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialize cl settings context by main settings */
    dtv_player_p->cl_setting.remind_time = dtv_player_p->setting.pro_remind_time;
    dtv_player_p->cl_setting.cbm_app_id = dtv_player_p->setting.cbm_app_id;
    dtv_player_p->cl_setting.inter_auto_popup = dtv_player_p->setting.inter_auto_popup;
    dtv_player_p->cl_setting.manual_set_loc = dtv_player_p->setting.manual_set_loc;

	if (MMI_SIM1 == dtv_player_p->cur_sim)
	{
	    dtv_player_p->cl_setting.data_account_id = dtv_player_p->setting.data_account_id;
	    dtv_player_p->cl_setting.use_proxy = dtv_player_p->setting.use_proxy;
	    dtv_player_p->cl_setting.proxy_port = dtv_player_p->setting.proxy_port;
	    dtv_player_p->cl_setting.sg_proxy_port = dtv_player_p->setting.sg_proxy_port;
	    memcpy(dtv_player_p->cl_setting.proxy_server, 
			   dtv_player_p->setting.proxy_server, 
			   MMI_DTV_PLAYER_PROXY_IP_COUNT);
	    memcpy(dtv_player_p->cl_setting.sg_proxy_server, 
			   dtv_player_p->setting.sg_proxy_server, 
			   MMI_DTV_MAX_SG_ADDR_LEN <<1);
	}
	else
	{		
	    dtv_player_p->cl_setting.data_account_id = dtv_player_p->setting.sim2_data_account_id;
	    dtv_player_p->cl_setting.use_proxy = dtv_player_p->setting.sim2_use_proxy;
	    dtv_player_p->cl_setting.proxy_port = dtv_player_p->setting.sim2_proxy_port;
	    dtv_player_p->cl_setting.sg_proxy_port = dtv_player_p->setting.sim2_sg_proxy_port;
	    memcpy(dtv_player_p->cl_setting.proxy_server, 
			   dtv_player_p->setting.sim2_proxy_server, 
			   MMI_DTV_PLAYER_PROXY_IP_COUNT);
	    memcpy(dtv_player_p->cl_setting.sg_proxy_server, 
			   dtv_player_p->setting.sim2_sg_proxy_server, 
			   MMI_DTV_MAX_SG_ADDR_LEN <<1);
	}

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_cl_setting_deinit
 * DESCRIPTION
 *  mobile tv player cl setting de-initialize: de-regist cbm app id
 * PARAMETERS
 *  void
 * RETURNS
 *  error code
 *****************************************************************************/
S32 mmi_dtv_player_cl_setting_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //@TODO: add trace
    if (dtv_player_p->cl_setting.cbm_app_id != 0xff)
    {
        cbm_deregister_app_id(dtv_player_p->cl_setting.cbm_app_id);
        dtv_player_p->cl_setting.cbm_app_id = 0xff;
        dtv_player_p->setting.cbm_app_id = 0xff;
        WriteRecord(NVRAM_EF_DTV_PLAYER_SETTING_LID, 1, (void*)&dtv_player_p->setting, NVRAM_EF_DTV_PLAYER_SETTING_SIZE, &error);
    }
    else
    {
        //@TODO: add trace
    }

    if (dtv_player_p->cl_setting.mem_buff)
    {
        //@TODO: add log
        applib_mem_screen_free(dtv_player_p->cl_setting.mem_buff);
        dtv_player_p->cl_setting.mem_buff = NULL;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_data_account_default_setting
 * DESCRIPTION
 *  mobile tv player get data account default setting
 * PARAMETERS
 *  void
 * RETURNS
 *  error code
 *****************************************************************************/
S32 mmi_dtv_player_get_data_account_default_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16                 error = 0;
    MMI_BOOL            result = MMI_FALSE;
    srv_dtcnt_prof_proxy_info_struct  dtcnt_proxy_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
              MMI_TRC_DTV_GET_DTCNT_DEFAULT_SETTING,
              g_dtv_cl_setting_dcnt_id_list_count);

	if (0 == g_dtv_cl_setting_dcnt_id_list_count)
    {
        return 0;
    }
    else
    {
		if (MMI_SIM1 == dtv_player_p->cur_sim)
		{
        	dtv_player_p->setting.data_account_id = mmi_dtv_player_default_dtcnt(NULL);			
			MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
					  MMI_TRC_DTV_VAL1,
					  dtv_player_p->setting.data_account_id, 
					  __LINE__);			
			result = srv_dtcnt_get_proxy_info(dtv_player_p->setting.data_account_id,
											  &dtcnt_proxy_info,
											  SRV_DTCNT_ACCOUNT_PRIMARY);
			if (result)
			{
				dtv_player_p->setting.use_proxy = dtcnt_proxy_info.use_proxy;
				dtv_player_p->setting.proxy_port = (U32)dtcnt_proxy_info.px_port;
				memcpy(&(dtv_player_p->setting.proxy_server[0]), 
					   &(dtcnt_proxy_info.px_addr[0]), 
					   MMI_DTV_PLAYER_PROXY_IP_COUNT);
			}
		}
		else
		{			
			dtv_player_p->setting.sim2_data_account_id = mmi_dtv_player_default_dtcnt(NULL);			
			MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
					  MMI_TRC_DTV_VAL1,
					  dtv_player_p->setting.sim2_data_account_id, 
					  __LINE__);
			result = srv_dtcnt_get_proxy_info(dtv_player_p->setting.sim2_data_account_id,
											  &dtcnt_proxy_info,
											  SRV_DTCNT_ACCOUNT_PRIMARY);
			if (result)
			{
				dtv_player_p->setting.sim2_use_proxy = dtcnt_proxy_info.use_proxy;
				dtv_player_p->setting.sim2_proxy_port = (U32)dtcnt_proxy_info.px_port;
				memcpy(&(dtv_player_p->setting.sim2_proxy_server[0]), 
					   &(dtcnt_proxy_info.px_addr[0]), 
					   MMI_DTV_PLAYER_PROXY_IP_COUNT);
			}
		}				
    }
	
	if (MMI_SIM1 == dtv_player_p->cur_sim)
	{
    	kal_wsprintf(dtv_player_p->setting.sg_proxy_server, "sg.mbbms.chinamobile.com");
    	dtv_player_p->setting.sg_proxy_port = 80;
	}
	else
	{
		kal_wsprintf(dtv_player_p->setting.sim2_sg_proxy_server, "sg.mbbms.chinamobile.com");
		dtv_player_p->setting.sim2_sg_proxy_port = 80;		
	}
		
    /* write back to nvram */
    WriteRecord(NVRAM_EF_DTV_PLAYER_SETTING_LID, 
                1, 
                (void*)&dtv_player_p->setting, 
                NVRAM_EF_DTV_PLAYER_SETTING_SIZE, 
                &error);

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_cl_setting_init
 * DESCRIPTION
 *  mobile tv player cl setting initialize: init cl_settings and regist cbm
 * PARAMETERS
 *  void
 * RETURNS
 *  error code
 *****************************************************************************/
S32 mmi_dtv_player_cl_setting_init(MMI_BOOL sim_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_app_info_struct app_info;
    MMI_BOOL            result = MMI_FALSE;
    U32                 i;
    MMI_BOOL invalid = KAL_FALSE;
	U32 dtcnt_id = 0xFFFFFFFF;
	srv_dtcnt_sim_type_enum simType;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!sim_valid)
    {
        memset(&dtv_player_p->cl_setting, 0, sizeof(dtv_player_cl_setting_struct));
        mmi_dtv_player_cl_setting_load();
        return 0;
    }
    /* Following: SIM valid */
    
    /* reset cl setting data */
    memset(&dtv_player_p->cl_setting, 0, sizeof(dtv_player_cl_setting_struct));
    memset(g_dtv_cl_setting_dcnt_id_list, 0, sizeof(U32) * SRV_DTCNT_PROF_MAX_ACCOUNT_NUM);
    g_dtv_cl_setting_dcnt_id_list_count = 0;
    /* register cbm app id */
    memset(&app_info, 0, sizeof(app_info));
    app_info.app_icon_id = DTV_PLAYER_MENU_ICON;
    app_info.app_str_id = STR_GLOBAL_DATA_ACCOUNT;
    app_info.app_type = DTCNT_APPTYPE_PLAYER | DTCNT_APPTYPE_SKIP_CSD | DTCNT_APPTYPE_SKIP_WIFI;
    // cbm_app_id doesn't need to put in NVRAM
    cbm_register_app_id_with_app_info(&app_info, &(dtv_player_p->setting.cbm_app_id));

#ifdef __COSMOS_MMI_PACKAGE__    
    result = vapp_dtcnt_get_apn_list_ids(g_dtv_cl_setting_dcnt_id_list, 
                                         &g_dtv_cl_setting_dcnt_id_list_count,
                                         dtv_player_p->cur_sim);
    
#else    
    /* load data account list */
    result = mmi_dtcnt_get_apn_list_ids(g_dtv_cl_setting_dcnt_id_list, 
                                        &g_dtv_cl_setting_dcnt_id_list_count,
                                        dtv_player_p->cur_sim);
#endif
    if (!result)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL1, result, __LINE__);
        mmi_dtv_player_get_data_account_default_setting();
        return -1;
    }

	if (MMI_SIM1 == dtv_player_p->cur_sim)
	{
		dtcnt_id = dtv_player_p->setting.data_account_id;
	}
	else
	{
		dtcnt_id = dtv_player_p->setting.sim2_data_account_id;
	}

	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
			  MMI_TRC_DTV_VAL2, 
			  dtv_player_p->cur_sim, 
			  dtcnt_id, 
			  __LINE__);
	
    if ((0xFFFFFFFF != dtcnt_id) && (0 != g_dtv_cl_setting_dcnt_id_list_count))
    {
        for (i = 0; i < g_dtv_cl_setting_dcnt_id_list_count; i++)
        {
            if (dtcnt_id == g_dtv_cl_setting_dcnt_id_list[i])
            {
            	srv_dtcnt_get_sim_info(dtcnt_id, &simType);
				if (simType == dtv_player_p->cur_sim)
				{	
					MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
							  MMI_TRC_DTV_VAL2, 
							  dtv_player_p->cur_sim, 
							  dtcnt_id, 
							  __LINE__);
					break;
				}
            }
        }
        if (i == g_dtv_cl_setting_dcnt_id_list_count)
        {
            invalid = MMI_TRUE;
        }
        else
        {
            dtv_player_p->cl_setting.data_account_idx = i;
        }
    }
    else
    {
        invalid = MMI_TRUE;
    }

	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
			  MMI_TRC_DTV_VAL2, 
			  dtv_player_p->cur_sim, 
			  invalid, 
			  __LINE__);

    if (invalid)
    {
        mmi_dtv_player_get_data_account_default_setting();
    }

    mmi_dtv_player_cl_setting_load();
	
    return 0;
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
static void mmi_dtv_player_cl_setting_inline_highlight_change(cui_event_inline_notify_struct *inline_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 item = inline_evt->item_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->cl_setting.hilite = item;

}

#ifdef __MBBMS_CITY_LIST__
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
static void mmi_dtv_player_cl_setting_inline_radio_selected(cui_event_inline_notify_struct *inline_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 item = inline_evt->item_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (item)
    {
        case MMI_DTV_USER_LOC_INFO_RADIO_LIST:
        {
			if (0 == inline_evt->param)	
			{
	        	dtv_player_p->cl_setting.manual_set_loc = MMI_FALSE;
			}
			else
			{
				dtv_player_p->cl_setting.manual_set_loc = MMI_TRUE;
			}
	        if (MMI_TRUE == dtv_player_p->cl_setting.manual_set_loc)
	        {        
	            dtv_player_p->process_type = DTV_PLAYER_PROCESS_TYPE_AREA_SET_RETRIEVE;
	            mmi_dtv_player_enter_process_screen();
	        }
	        break;
	    }

        default:
		{
            break;
        }
    }
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_cl_setting_option_config
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_cl_setting_option_config(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 item = dtv_player_p->cl_setting.hilite;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(item)
    {
        case MMI_DTV_PROGRAM_REMIND_TIME_SELECTOR:
	#ifdef __MBBMS_DUAL_SIM_SUPPORT__
		case MMI_DTV_SIMCARD_SELECTOR:
	#endif
    #ifdef __MBBMS_INTER__
        case MMI_DTV_INTER_ARRIVE_CHECK_BOX:
	#endif
	#ifdef __MBBMS_CITY_LIST__
        case MMI_DTV_USER_LOC_INFO_RADIO_LIST:
	#endif
	#ifdef __MBBMS_UPGRADE__
        case MMI_DTV_DETECT_NEW_DISPLAY_ONLY:
    #endif
        case MMI_DTV_USE_PROXY_SELECTOR:
        case MMI_DTV_DATA_ACCOUNT_SELECTOR:
        case MMI_DTV_PROXY_SERVER_IP4:
        case MMI_DTV_PROXY_PORT_TEXT_EDIT:
        case MMI_DTV_SG_SERVER_TEXT_EDIT:
        case MMI_DTV_SG_SERVER_PORT_TEXT_EDIT:
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_DTV_PLAYER_SETTING_OPTION_SELECT, MMI_TRUE);
            break;
        }
        default:
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_cl_setting_option_entry
 * DESCRIPTION
 *  mobile tv player entry cl setting option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_cl_setting_option_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_gid = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_DTV_PLAYER_CL_SETTING, GRP_ID_DTV_PLAYER_CL_SETTING_OPTION, mmi_dtv_player_cl_setting_proc, (void*)NULL);
    mmi_frm_group_enter(GRP_ID_DTV_PLAYER_CL_SETTING_OPTION, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    cui_gid = cui_menu_create(
                    GRP_ID_DTV_PLAYER_CL_SETTING_OPTION,
                    CUI_MENU_SRC_TYPE_RESOURCE,
                    CUI_MENU_TYPE_OPTION,
                    MENU_ID_DTV_PLAYER_CL_SETTING_OPTION,
                    MMI_FALSE,
                    NULL);
    if (cui_gid > GRP_ID_INVALID)
    {
        cui_menu_set_default_title_image(cui_gid, (UI_image_type)get_image(DTV_PLAYER_MENU_ICON));
        cui_menu_run(cui_gid);
    }
    else
    {
        mmi_dtv_player_display_popup(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE);

        mmi_frm_group_close(GRP_ID_DTV_PLAYER_CL_SETTING_OPTION);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_cl_setting_restore
 * DESCRIPTION
 *  cl settings and related main setting restore
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_cl_setting_restore(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* restore settings */
    dtv_player_p->setting.pro_remind_time = 0;
    dtv_player_p->setting.inter_auto_popup = MMI_TRUE;
    dtv_player_p->setting.manual_set_loc = MMI_FALSE;
    mmi_dtv_player_get_data_account_default_setting();

    /* storge setting to NVRAM */
    WriteRecord(NVRAM_EF_DTV_PLAYER_SETTING_LID,
				1,
				(void*)&dtv_player_p->setting,
				NVRAM_EF_DTV_PLAYER_SETTING_SIZE,
				&pError);
    
    /* Set net info to MED */
    mmi_dtv_cas_update_net_info();

    /* Update alarm */
    mmi_dtv_player_update_alarm();

    mmi_dtv_player_display_popup(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS);

    mmi_frm_group_close(GRP_ID_DTV_PLAYER_CL_SETTING);
    mmi_frm_group_close(GRP_ID_DTV_PLAYER_CL_SETTING_RESTORE_CONFIRM);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_cl_setting_restore_confirm
 * DESCRIPTION
 *  settings restore
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_cl_setting_restore_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct property;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_DTV_PLAYER_CL_SETTING, GRP_ID_DTV_PLAYER_CL_SETTING_RESTORE_CONFIRM, mmi_dtv_player_cl_setting_proc, (void*)NULL);
    mmi_frm_group_enter(GRP_ID_DTV_PLAYER_CL_SETTING_RESTORE_CONFIRM, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_confirm_property_init(&property, CNFM_TYPE_YESNO);
    property.parent_id = GRP_ID_DTV_PLAYER_CL_SETTING_RESTORE_CONFIRM;
    property.user_tag = (void*)mmi_dtv_player_cl_setting_restore;
#if !defined(__MMI_FTE_SUPPORT__)
    property.f_msg_icon = MMI_FALSE;
#endif

    mmi_confirm_display(
        (WCHAR *)get_string(STR_ID_DTV_RESTORE_ASK),
        MMI_EVENT_QUERY,
        &property);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_cl_setting_save
 * DESCRIPTION
 *  settings save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_cl_setting_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID inline_gid = GRP_ID_INVALID;
    S32 port;
    S16 pError;
    U8 inline_proxy_port[(MMI_DTV_MAX_PORT_LEN)*ENCODING_LENGTH];
    cui_inline_item_ip4_struct inline_proxy_addr;
    U8 inline_sg_proxy_port[(MMI_DTV_MAX_PORT_LEN)*ENCODING_LENGTH];
    WCHAR sg_proxy_addr[MMI_DTV_MAX_SG_ADDR_LEN];
    nvram_dtv_player_setting_struct *set = &dtv_player_p->setting;
	U8 temp[4];
#ifdef __MBBMS_CITY_LIST__
	S32 radio_idx;
#endif
	#ifdef __MBBMS_DUAL_SIM_SUPPORT__
	U8 simcard = 0;
	#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_gid = dtv_player_p->cl_setting.inline_gid;

    /* Program reminder time */
    cui_inline_get_value(
        inline_gid,
        MMI_DTV_PROGRAM_REMIND_TIME_SELECTOR,
        &dtv_player_p->cl_setting.remind_time);
    set->pro_remind_time = dtv_player_p->cl_setting.remind_time;

    if (dtv_player_p->ca_state != MMI_DTV_CA_STATE_CMMB)
    {
	#ifdef __MBBMS_INTER__
        /* interactor auto popup */
        cui_inline_get_value(
            inline_gid,
            MMI_DTV_INTER_ARRIVE_CHECK_BOX,
            &dtv_player_p->cl_setting.inter_auto_popup);
        set->inter_auto_popup = dtv_player_p->cl_setting.inter_auto_popup;
	#endif /* __MBBMS_INTER__ */

	#ifdef __MBBMS_CITY_LIST__
        /* Auto detect location */
        cui_inline_get_value(
            inline_gid,
            MMI_DTV_USER_LOC_INFO_RADIO_LIST,
            &radio_idx);
		dtv_player_p->cl_setting.manual_set_loc = (MMI_BOOL)radio_idx;
        set->manual_set_loc = dtv_player_p->cl_setting.manual_set_loc;
	#endif /* __MBBMS_CITY_LIST__ */
    }
    if (0 != g_dtv_cl_setting_dcnt_id_list_count)
    {
        /* Proxy server*/
        cui_inline_get_value(inline_gid, MMI_DTV_PROXY_SERVER_IP4, (void *) &inline_proxy_addr);
        if (dtv_player_p->cl_setting.use_proxy &&
            !(inline_proxy_addr.b1 || inline_proxy_addr.b2 || inline_proxy_addr.b3 || inline_proxy_addr.b4))
        {
            mmi_dtv_player_display_popup(STR_ID_DTV_INVALID_PROXY_ADDR, MMI_EVENT_ERROR);

            return;
        }
        /* Porxy port*/
        cui_inline_get_value(inline_gid, MMI_DTV_PROXY_PORT_TEXT_EDIT, (void *) inline_proxy_port);
        port = gui_atoi((UI_string_type)&inline_proxy_port);
        if ((port >65535) ||(dtv_player_p->cl_setting.use_proxy && !port))
        {
            mmi_dtv_player_display_popup(STR_ID_DTV_INVALID_PROXY_PORT, MMI_EVENT_FAILURE);

            return;
        }

        /* SG Porxy Server */
        cui_inline_get_value(inline_gid, MMI_DTV_SG_SERVER_TEXT_EDIT, &sg_proxy_addr);
        if (mmi_ucs2strlen((CHAR*)sg_proxy_addr) == 0)
        {
            mmi_dtv_player_display_popup(STR_ID_DTV_INVALID_PROXY_ADDR, MMI_EVENT_FAILURE);
            return;
        }

        /* SG Porxy port*/
        cui_inline_get_value(inline_gid, MMI_DTV_SG_SERVER_PORT_TEXT_EDIT, (void *) inline_sg_proxy_port);
        port = gui_atoi((UI_string_type)&inline_sg_proxy_port);
        if ((port >65535) ||(dtv_player_p->cl_setting.use_proxy && !port))
        {
            mmi_dtv_player_display_popup(STR_ID_DTV_INVALID_PROXY_PORT, MMI_EVENT_ERROR);

            return;
        }

		if (MMI_SIM1 == dtv_player_p->cur_sim)
		{
	        /* save the updated data */
	        set->use_proxy         = dtv_player_p->cl_setting.use_proxy;
	        set->data_account_id   = dtv_player_p->cl_setting.data_account_id;
			temp[0]   = inline_proxy_addr.b1;
			temp[1]   = inline_proxy_addr.b2;
			temp[2]   = inline_proxy_addr.b3;
			temp[3]   = inline_proxy_addr.b4;
			mmi_dtv_player_ip4_to_address((U8 *)temp,(CHAR *)(set->proxy_server));			
	        set->proxy_port        = gui_atoi((UI_string_type)&inline_proxy_port);
	        mmi_ucs2ncpy((CHAR*)set->sg_proxy_server, 
				         (CHAR*)sg_proxy_addr, 
				         MMI_DTV_MAX_SG_ADDR_LEN - 1);
	        set->sg_proxy_port     = gui_atoi((UI_string_type)&inline_sg_proxy_port);
		}
		else
		{
			/* save the updated data */
	        set->sim2_use_proxy    = dtv_player_p->cl_setting.use_proxy;
	        set->sim2_data_account_id   = dtv_player_p->cl_setting.data_account_id;
		    temp[0]   = inline_proxy_addr.b1;
	        temp[1]   = inline_proxy_addr.b2;
	        temp[2]   = inline_proxy_addr.b3;
	        temp[3]   = inline_proxy_addr.b4;
		    mmi_dtv_player_ip4_to_address((U8 *)temp,(CHAR *)(set->sim2_proxy_server));
	        set->sim2_proxy_port        = gui_atoi((UI_string_type)&inline_proxy_port);
	        mmi_ucs2ncpy((CHAR*)set->sim2_sg_proxy_server, 
				         (CHAR*)sg_proxy_addr, 
				         MMI_DTV_MAX_SG_ADDR_LEN - 1);
	        set->sim2_sg_proxy_port     = gui_atoi((UI_string_type)&inline_sg_proxy_port);
		}
        mmi_dtv_player_cl_setting_load();
    }


	/* storge setting to NVRAM */
    WriteRecord(NVRAM_EF_DTV_PLAYER_SETTING_LID,
		        1,
		        (void*)&dtv_player_p->setting,
		        NVRAM_EF_DTV_PLAYER_SETTING_SIZE,
		        &pError);

    /* Set net info to MED */
    mmi_dtv_cas_update_net_info();

    /* Update alarm */
    mmi_dtv_player_update_alarm();
    
	#ifdef __MBBMS_DUAL_SIM_SUPPORT__	
	cui_inline_get_value(inline_gid, MMI_DTV_SIMCARD_SELECTOR, &simcard);

	if (simcard != (dtv_player_p->cur_sim - 1))
	{
		if (MMI_TRUE == mmi_dtv_player_sim_support_mbbms(simcard))
		{			
			mmi_dtv_player_display_confirm(STR_ID_DTV_SIM_CHANGE_NOTIFY1);
		}
		else
		{			
			mmi_dtv_player_display_popup(STR_ID_DTV_SIM_NOTIFY1 + simcard,
										 MMI_EVENT_FAILURE);							
		}			
		return;
	}
	else
	#endif
	{
		mmi_dtv_player_display_popup(STR_GLOBAL_SAVED,MMI_EVENT_SUCCESS);
	}

	mmi_frm_group_close(GRP_ID_DTV_PLAYER_CL_SETTING);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_cl_setting_save_confirm
 * DESCRIPTION
 *  settings save confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_cl_setting_save_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct property;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&property, CNFM_TYPE_YESNO);
    property.parent_id = GRP_ID_DTV_PLAYER_CL_SETTING;
    property.user_tag = (void*)mmi_dtv_player_cl_setting_save;
#if !defined(__MMI_FTE_SUPPORT__)
    property.f_msg_icon = MMI_FALSE;
#endif

    mmi_confirm_display(
        (WCHAR *)get_string(STR_GLOBAL_SAVE_ASK),
        MMI_EVENT_QUERY,
        &property);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_cl_setting_config_item
 * DESCRIPTION
 *  mmi_dtv_player_cl_setting_config_item
 * PARAMETERS
 *  [IN]: inline cui id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_cl_setting_config_item(MMI_ID inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_CMMB)
    {
	#ifdef __MBBMS_INTER__
        cui_inline_delete_item(inline_id, MMI_DTV_INTER_ARRIVE_CAPTION);
        cui_inline_delete_item(inline_id, MMI_DTV_INTER_ARRIVE_CHECK_BOX);
	#endif /* __MBBMS_INTER__ */
	#ifdef __MBBMS_CITY_LIST__
        cui_inline_delete_item(inline_id, MMI_DTV_USER_LOC_INFO_CAPTION);
        cui_inline_delete_item(inline_id, MMI_DTV_USER_LOC_INFO_RADIO_LIST);
	#endif /* __MBBMS_CITY_LIST__ */
	#ifdef __MBBMS_UPGRADE__
        cui_inline_delete_item(inline_id, MMI_DTV_CLIENT_UPGRADE_CAPTION);
        cui_inline_delete_item(inline_id, MMI_DTV_DETECT_NEW_DISPLAY_ONLY);        
	#endif /* __MBBMS_UPGRADE__ */
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_profile_edit_init_item_value
 * DESCRIPTION
 *  mmi_medply_settings_profile_edit_init_item_value
 * PARAMETERS
 *  [IN]: inline cui id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_cl_setting_init_item_value(MMI_ID inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8      inline_proxy_port[(MMI_DTV_MAX_PORT_LEN) * ENCODING_LENGTH];
    cui_inline_item_ip4_struct  inline_proxy_server;
    WCHAR sg_server[MMI_DTV_MAX_SG_ADDR_LEN];
    U16     item_icons[sizeof(g_dtv_cl_setting_item)/sizeof(g_dtv_cl_setting_item[0]) + DTV_PLAYER_RADIO_NUM];
    U16     item_count = 0;
    U16     item_total = 0;
	U8 proxy_server[4];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->cl_setting.inline_gid = inline_id;
/***********************************initialize values******************************************/
    item_count = IMG_GLOBAL_L1;
    /* Program remind time */
    cui_inline_set_value(
        inline_id,
        MMI_DTV_PROGRAM_REMIND_TIME_SELECTOR,
        (void*)dtv_player_p->cl_setting.remind_time);
	item_icons[item_total] = item_count;
	item_count++;
    item_total += 2;

	#ifdef __MBBMS_DUAL_SIM_SUPPORT__	
		if ((MMI_DTV_CA_STATE_CMMB == dtv_player_p->ca_state)
			|| (MMI_FALSE == srv_sim_ctrl_is_available(MMI_SIM1))
			|| (MMI_FALSE == srv_sim_ctrl_is_available(MMI_SIM2)))
		 {
			 cui_inline_delete_item(inline_id, MMI_DTV_SIMCARD_CAPTION);
			 cui_inline_delete_item(inline_id, MMI_DTV_SIMCARD_SELECTOR);
		 }
		 else
		 {			
			cui_inline_set_value(inline_id, MMI_DTV_SIMCARD_SELECTOR, (void*)(dtv_player_p->cur_sim - 1));
			cui_inline_set_item_attributes(inline_id,MMI_DTV_SIMCARD_SELECTOR,
										   CUI_INLINE_SET_ATTRIBUTE,CUI_INLINE_ITEM_SELECT_NO_LOOP);
			item_icons[item_total] = item_count;
			item_count++;
			item_total += 2;
		 }
	#endif


    if (MMI_DTV_CA_STATE_CMMB != dtv_player_p->ca_state)
    {	
	#ifdef __MBBMS_INTER__
        /* interative auto popup */
        cui_inline_set_value(
            inline_id,
            MMI_DTV_INTER_ARRIVE_CHECK_BOX,
            (void*)dtv_player_p->cl_setting.inter_auto_popup);
    	item_icons[item_total] = item_count;
    	item_count++;
        item_total += 2;
	#endif /* __MBBMS_INTER__ */
        
        /* user location detect */
        mmi_dtv_player_set_radio_list_string(inline_id);
	
	#ifdef __MBBMS_CITY_LIST__        
        cui_inline_set_value(
            inline_id,
            MMI_DTV_USER_LOC_INFO_RADIO_LIST,
            (void*)((S32)dtv_player_p->cl_setting.manual_set_loc));
    	item_icons[item_total] = item_count;
    	item_count++;
        item_total += 3;
	#endif /* __MBBMS_CITY_LIST__ */

	#ifdef __MBBMS_UPGRADE__
        /* Detect new version */
    	item_icons[item_total] = item_count;
    	item_count++;
        item_total += 2;
	#endif /* __MBBMS_UPGRADE__ */
    }

    /* Data account */
	item_icons[item_total] = item_count;
	item_count++;
    item_total += 2;
    /* Use proxy */
    if (0 == g_dtv_cl_setting_dcnt_id_list_count)
    {
        cui_inline_delete_item(inline_id,  MMI_DTV_USE_PROXY_CAPTION);
        cui_inline_delete_item(inline_id,  MMI_DTV_USE_PROXY_SELECTOR);
    }
    else
    {
        cui_inline_set_value(
            inline_id,
            MMI_DTV_USE_PROXY_SELECTOR,
            (void*)dtv_player_p->cl_setting.use_proxy);
		item_icons[item_total] = item_count;
		item_count++;
        item_total += 2;
    }
    /* Proxy server */
    if (0 == g_dtv_cl_setting_dcnt_id_list_count)
    {
        cui_inline_delete_item(inline_id,  MMI_DTV_PROXY_SERVER_CAPTION);
        cui_inline_delete_item(inline_id,  MMI_DTV_PROXY_SERVER_IP4);
    }
    else
    {    
		mmi_dtv_player_address_to_ip4((CHAR *)(dtv_player_p->cl_setting.proxy_server),
									  (U8 *)proxy_server);
		inline_proxy_server.b1 = proxy_server[0];
        inline_proxy_server.b2 = proxy_server[1];
        inline_proxy_server.b3 = proxy_server[2];
        inline_proxy_server.b4 = proxy_server[3];
        cui_inline_set_value(
            inline_id,
            MMI_DTV_PROXY_SERVER_IP4,
            (void *)&inline_proxy_server);
		item_icons[item_total] = item_count;
		item_count++;
        item_total += 2;
    }
    /* Porxy port */
    if (0 == g_dtv_cl_setting_dcnt_id_list_count)
    {
        cui_inline_delete_item(inline_id,  MMI_DTV_PROXY_PORT_CAPTION);
        cui_inline_delete_item(inline_id,  MMI_DTV_PROXY_PORT_TEXT_EDIT);
    }
    else
    {
        app_ucs2_itoa(dtv_player_p->cl_setting.proxy_port, (kal_int8 *)inline_proxy_port, 10);
        cui_inline_set_value(
            inline_id,
            MMI_DTV_PROXY_PORT_TEXT_EDIT,
            (void *)inline_proxy_port);
		item_icons[item_total] = item_count;
		item_count++;
        item_total += 2;
    }
    /* SG proxy server */
    if (0 == g_dtv_cl_setting_dcnt_id_list_count)
    {
        cui_inline_delete_item(inline_id,  MMI_DTV_SG_SERVER_CAPTION);
        cui_inline_delete_item(inline_id,  MMI_DTV_SG_SERVER_TEXT_EDIT);
    }
    else
    {
        kal_mem_cpy(sg_server, dtv_player_p->cl_setting.sg_proxy_server, MMI_DTV_MAX_SG_ADDR_LEN << 1);
        cui_inline_set_value(
            inline_id,
            MMI_DTV_SG_SERVER_TEXT_EDIT,
            (void *)&sg_server);
		item_icons[item_total] = item_count;
		item_count++;
        item_total += 2;
    }
    /* SG proxy port */
    if (0 == g_dtv_cl_setting_dcnt_id_list_count)
    {
        cui_inline_delete_item(inline_id,  MMI_DTV_SG_SERVER_PORT_CAPTION);
        cui_inline_delete_item(inline_id,  MMI_DTV_SG_SERVER_PORT_TEXT_EDIT);
    }
    else
    {
        app_ucs2_itoa(dtv_player_p->cl_setting.sg_proxy_port, (kal_int8 *)inline_proxy_port, 10);
        cui_inline_set_value(inline_id,
            MMI_DTV_SG_SERVER_PORT_TEXT_EDIT,
            (void *)inline_proxy_port);
		item_icons[item_total] = item_count;
		item_count++;
        item_total += 2;
    }
/***********************************initialize icon******************************************/
	item_icons[item_total] = 0;

    cui_inline_set_icon_list(inline_id, item_icons);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_cl_setting_set_item_value
 * DESCRIPTION
 *   reserved for enable done style is required
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_cl_setting_set_item_value(MMI_ID inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32     i;
    U8      *da_apn_list_p[SRV_DTCNT_PROF_MAX_ACCOUNT_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((0 == g_dtv_cl_setting_dcnt_id_list_count)
		|| (MMI_FALSE == srv_sim_ctrl_is_available(dtv_player_p->cur_sim)))
    {
        cui_inline_set_item_attributes(
            inline_id,
            MMI_DTV_DATA_ACCOUNT_SELECTOR,
            CUI_INLINE_SET_ATTRIBUTE,
            CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY);
        cui_inline_set_value(
            inline_id,
            MMI_DTV_DATA_ACCOUNT_SELECTOR,
            (void *)GetString((U16)(STR_GLOBAL_EMPTY)));
    }
    else
    {
        MMI_ASSERT(g_dtv_cl_setting_dcnt_id_list_count < SRV_DTCNT_PROF_MAX_ACCOUNT_NUM);
        dtv_player_p->cl_setting.mem_buff = (U8*)applib_mem_screen_alloc_framebuffer(SRV_DTCNT_PROF_MAX_ACCOUNT_NUM*MMI_DTV_PLAYER_APN_LENGTH*2);
        MMI_ASSERT(dtv_player_p->cl_setting.mem_buff);
        for (i = 0; i < SRV_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
        {
            da_apn_list_p[i] = dtv_player_p->cl_setting.mem_buff + i*MMI_DTV_PLAYER_APN_LENGTH*2;
        }
        for (i = 0; i < g_dtv_cl_setting_dcnt_id_list_count; i ++)
        {
            srv_dtcnt_prof_str_info_qry_struct out_apn;

            out_apn.dest = da_apn_list_p[i];
            out_apn.dest_len = MMI_DTV_PLAYER_APN_LENGTH;
            out_apn.req_len = MMI_DTV_PLAYER_APN_LENGTH;
            if (srv_dtcnt_get_apn(g_dtv_cl_setting_dcnt_id_list[i], &out_apn, SRV_DTCNT_ACCOUNT_PRIMARY))
            {
                continue;
            }
            else
            {
				MMI_TRACE(MMI_MEDIA_TRC_G2_APP,
					      MMI_TRC_DTV_VAL2, 
					      i, 
					      g_dtv_cl_setting_dcnt_id_list_count, 
					      __LINE__);
            }
        }
        cui_inline_set_item_attributes(
            inline_id,
            MMI_DTV_DATA_ACCOUNT_SELECTOR,
            CUI_INLINE_SET_ATTRIBUTE,
            CUI_INLINE_ITEM_TYPE_SELECT);
        cui_inline_set_item_select(
            inline_id,
            MMI_DTV_DATA_ACCOUNT_SELECTOR,
            (S32)g_dtv_cl_setting_dcnt_id_list_count,
            (PU8 *)da_apn_list_p,
            dtv_player_p->cl_setting.data_account_idx);
    }

    /* Re-assign dtv_player_p->info_str_buffer */
    mmi_dtv_player_set_radio_list_string(inline_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_cl_setting_update_item_value
 * DESCRIPTION
 *   reserved for enable done style is required
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_cl_setting_update_item_value(MMI_ID inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    srv_dtcnt_prof_proxy_info_struct  dtcnt_proxy_info;
    cui_inline_item_ip4_struct  inline_proxy_server;
    U8      inline_proxy_port[(MMI_DTV_MAX_PORT_LEN) * ENCODING_LENGTH];
	U8      proxy_server[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* load the proxy values from system */
    result = srv_dtcnt_get_proxy_info(
        dtv_player_p->cl_setting.data_account_id,
        &dtcnt_proxy_info,
        SRV_DTCNT_ACCOUNT_PRIMARY);
    if (result)
    {
        dtv_player_p->cl_setting.use_proxy = dtcnt_proxy_info.use_proxy;
        dtv_player_p->cl_setting.proxy_port = (U32)dtcnt_proxy_info.px_port;
        memcpy(&(dtv_player_p->cl_setting.proxy_server[0]), &(dtcnt_proxy_info.px_addr[0]), MMI_DTV_PLAYER_PROXY_IP_COUNT);
    }
    else
    {
        //@TODO: add trace
        dtv_player_p->cl_setting.data_account_idx = 0;
        dtv_player_p->cl_setting.use_proxy = 0;
        dtv_player_p->cl_setting.proxy_port= 0;
        memset(&(dtv_player_p->cl_setting.proxy_server[0]), 0, MMI_DTV_PLAYER_PROXY_IP_COUNT);
    }

    /* Use proxy */
    cui_inline_set_value(
        inline_id,
        MMI_DTV_USE_PROXY_SELECTOR,
        (void*)dtv_player_p->cl_setting.use_proxy);
    /* Proxy server */
	mmi_dtv_player_address_to_ip4((CHAR *)(dtv_player_p->cl_setting.proxy_server),
								  (U8 *)proxy_server);
    inline_proxy_server.b1 = proxy_server[0];
    inline_proxy_server.b2 = proxy_server[1];
    inline_proxy_server.b3 = proxy_server[2];
    inline_proxy_server.b4 = proxy_server[3];
    cui_inline_set_value(
        inline_id,
        MMI_DTV_PROXY_SERVER_IP4,
        (void *)&inline_proxy_server);
    /* Porxy port */
    app_ucs2_itoa(dtv_player_p->cl_setting.proxy_port, (kal_int8 *)inline_proxy_port, 10);
    cui_inline_set_value(
        inline_id,
        MMI_DTV_PROXY_PORT_TEXT_EDIT,
        (void *)inline_proxy_port);

}

//bql: apn
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_cl_setting_inline_focus_change
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_cl_setting_inline_focus_change(cui_event_inline_notify_struct *inline_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 item = inline_evt->item_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (item)
    {
    case MMI_DTV_PROGRAM_REMIND_TIME_SELECTOR:
        {
            dtv_player_p->cl_setting.remind_time = inline_evt->param;
        }
        break;
    case MMI_DTV_USE_PROXY_SELECTOR:
        {
            dtv_player_p->cl_setting.use_proxy = inline_evt->param;
        }
        break;
    case MMI_DTV_DATA_ACCOUNT_SELECTOR:
        {
            if (dtv_player_p->cl_setting.data_account_idx != inline_evt->param)
            {
                dtv_player_p->cl_setting.data_account_idx = inline_evt->param;
                dtv_player_p->cl_setting.data_account_id = g_dtv_cl_setting_dcnt_id_list[inline_evt->param];
                mmi_dtv_player_cl_setting_update_item_value(inline_evt->sender_id);
                cui_inline_redraw_screen(inline_evt->sender_id);
            }
			break;
        }   
    default:
        break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_cl_setting_inline_set_key
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_cl_setting_inline_set_key(cui_event_inline_set_key_struct *inline_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 item = inline_evt->item_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* regist */
    switch(item)
    {
        case MMI_DTV_PROGRAM_REMIND_TIME_SELECTOR:
        case MMI_DTV_USE_PROXY_SELECTOR:
        case MMI_DTV_DATA_ACCOUNT_SELECTOR:
        case MMI_DTV_PROXY_SERVER_IP4:
        case MMI_DTV_PROXY_PORT_TEXT_EDIT:
        case MMI_DTV_SG_SERVER_TEXT_EDIT:
        case MMI_DTV_SG_SERVER_PORT_TEXT_EDIT:
	#ifdef __MBBMS_DUAL_SIM_SUPPORT__	
		case MMI_DTV_SIMCARD_SELECTOR:
	#endif
        {
            /* set CSK as save */
            cui_inline_set_softkey_icon(
                inline_evt->sender_id,
                item,
                MMI_CENTER_SOFTKEY,
                IMG_GLOBAL_SAVE_CSK);
            SetCenterSoftkeyFunction(mmi_dtv_player_cl_setting_save, KEY_EVENT_UP);
            /* set LSK*/
            cui_inline_set_softkey_text(
                inline_evt->sender_id,
                item,
                MMI_LEFT_SOFTKEY,
                STR_GLOBAL_OPTIONS);
            SetLeftSoftkeyFunction(mmi_dtv_player_cl_setting_option_entry, KEY_EVENT_UP);
            break;
        }
	#ifdef __MBBMS_UPGRADE__
        case MMI_DTV_DETECT_NEW_DISPLAY_ONLY:
        {
            /* set CSK as save */
            cui_inline_set_softkey_icon(
                inline_evt->sender_id,
                item,
                MMI_CENTER_SOFTKEY,
                IMG_GLOBAL_OK);
            SetCenterSoftkeyFunction(mmi_dtv_player_display_upgrade_query, KEY_EVENT_UP);
            /* set LSK*/
            cui_inline_set_softkey_text(
                inline_evt->sender_id,
                item,
                MMI_LEFT_SOFTKEY,
                STR_GLOBAL_OK);
            SetLeftSoftkeyFunction(mmi_dtv_player_display_upgrade_query, KEY_EVENT_UP);               
        }
	#endif /* __MBBMS_UPGRADE__ */
        default:
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_cl_setting_inline_cui_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
static mmi_ret mmi_dtv_player_cl_setting_inline_cui_hdlr(mmi_event_struct *evt)
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
                case CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED:                
			#ifdef __MBBMS_INTER__
                case CUI_INLINE_NOTIFY_CHECKBOX_CHANGED:
			#endif /* __MBBMS_INTER__ */
                {
                    mmi_dtv_player_cl_setting_inline_focus_change(inline_evt);
                    break;
                }
              
                case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
                {
                    mmi_dtv_player_cl_setting_inline_highlight_change(inline_evt);
		            break;
                }
			#ifdef __MBBMS_CITY_LIST__
                case CUI_INLINE_NOTIFY_RADIO_SELECTED:
                {
                    mmi_dtv_player_cl_setting_inline_radio_selected(inline_evt);
                    break;
                }
			#endif /* __MBBMS_CITY_LIST__ */
                default:
                {
                    break;
				}
            }
            break;
        }
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        {
            cui_event_inline_common_struct *inline_evt = (cui_event_inline_common_struct *)evt;

            mmi_dtv_player_cl_setting_set_item_value(inline_evt->sender_id);
            break;
        }

        case EVT_ID_CUI_INLINE_MAIN_SCREEN_INACTIVE:
        {
            if (dtv_player_p->cl_setting.mem_buff)
            {
                applib_mem_screen_free(dtv_player_p->cl_setting.mem_buff);
                dtv_player_p->cl_setting.mem_buff = NULL;
            }
            break;
        }
        case EVT_ID_CUI_INLINE_SET_KEY:
        {
            cui_event_inline_set_key_struct *inline_evt = (cui_event_inline_set_key_struct *)evt;
            mmi_dtv_player_cl_setting_inline_set_key(inline_evt);
            break;
        }

        case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            mmi_dtv_player_cl_setting_save();
            break;
        }

        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            mmi_dtv_player_cl_setting_save_confirm();
            break;
        }

        case EVT_ID_CUI_INLINE_ABORT:
        case EVT_ID_CUI_INLINE_GROUP_DEINIT:
        {
            cui_event_inline_abort_struct *inline_evt = (cui_event_inline_abort_struct*)evt;
            /* reload setting to cl_setting */
            mmi_dtv_player_cl_setting_load();
            cui_inline_close(inline_evt->sender_id);
            break;
        }
    }
    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_cl_setting_menu_cui_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  result
 *****************************************************************************/
static mmi_ret mmi_dtv_player_cl_setting_menu_cui_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;

            if (menu_evt->parent_menu_id == MENU_ID_DTV_PLAYER_CL_SETTING_OPTION)
            {
                mmi_dtv_player_cl_setting_option_config(menu_evt);
            }
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;

            if (menu_evt->parent_menu_id == MENU_ID_DTV_PLAYER_CL_SETTING_OPTION)
            {
                switch(menu_evt->highlighted_menu_id)
                {
                    case MENU_ID_DTV_PLAYER_SETTING_OPTION_SELECT:
//bql: apn
                        //mmi_dtv_player_cl_setting_dtcnt_cui_entry();
                        break;
                    case MENU_ID_DTV_PLAYER_SETTING_OPTION_SAVE:
                        mmi_dtv_player_cl_setting_save();
                        break;
                    case MENU_ID_DTV_PLAYER_SETTING_OPTION_RESTORE:
                        mmi_dtv_player_cl_setting_restore_confirm();
                        break;
                }
            }
            else
            {
                //@TODO: add error log
            }

            break;

        }
        case EVT_ID_CUI_MENU_LIST_EXIT:
            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;

            cui_menu_close(menu_evt->sender_id);
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_cl_setting_alert_cui_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_dtv_player_cl_setting_alert_cui_hdlr(mmi_event_struct *evt)
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
                    ((FuncPtr)confirm->user_tag)();
                    break;
                }
                case MMI_ALERT_CNFM_NO:
                case MMI_ALERT_CNFM_CANCEL:
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
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_cl_setting_proc
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_dtv_player_cl_setting_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
/*************************Screen Group event***************************/
        case EVT_ID_GROUP_DEINIT:
        {
            break;
        }
        case EVT_ID_SCRN_INACTIVE:
        {
            break;
        }
/**********************Inline CUI event*************************/
        case EVT_ID_CUI_INLINE_NOTIFY:
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
//bql: apn
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_INACTIVE:
        case EVT_ID_CUI_INLINE_SET_KEY:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_ABORT:
        case EVT_ID_CUI_INLINE_GROUP_DEINIT:
        {
            return mmi_dtv_player_cl_setting_inline_cui_hdlr(evt);
        }
//bql: apn
/*************************Menu CUI event***************************/
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_LIST_EXIT:
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            return mmi_dtv_player_cl_setting_menu_cui_hdlr(evt);
        }

/**********************alert CUI event*************************/
        case EVT_ID_ALERT_QUIT:
        {
            return mmi_dtv_player_cl_setting_alert_cui_hdlr(evt);
        }

        default:
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_set_radio_list_string
 * DESCRIPTION
 *  mobile tv player get radio list string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_set_radio_list_string(MMI_ID inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MBBMS_CITY_LIST__
    WCHAR loc_str[MMI_DTV_CITY_STR_LEN + 2 + 1] = {0}; /* Add "(" and ")" */
#endif /* __MBBMS_CITY_LIST__ */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MBBMS_INTER__
    /* Check box string */
    cui_inline_set_item_checkbox_string(
        inline_id,
        MMI_DTV_INTER_ARRIVE_CHECK_BOX,
        (kal_uint8 *)GetString(STR_ID_DTV_AUTO_POPUP_INTER));
	#endif /* __MBBMS_INTER__ */
    
	#ifdef __MBBMS_CITY_LIST__
    /* Radio 0: auto select location */
    cui_inline_set_item_radio_string(
        inline_id,
        MMI_DTV_USER_LOC_INFO_RADIO_LIST,
        DTV_PLAYER_RADIO_LIST_AUTO,
        (kal_uint8 *)GetString(STR_ID_DTV_AUTO_DETECT_LOCATION));

    /* Radio 1: manual select location + location string */    
    mmi_ucs2cpy((CHAR *)dtv_player_p->info_str_buffer, 
                 GetString(STR_ID_DTV_MANUALLY_SET_LOCATION));
    
    if (mmi_ucs2strlen((CHAR *)dtv_player_p->setting.location) > 0)
    {
        mmi_ucs2cpy((CHAR *)loc_str, (CHAR *)L"(");
        mmi_ucs2ncat((CHAR *)loc_str, (CHAR *)dtv_player_p->setting.location, MMI_DTV_CITY_STR_LEN);
        mmi_ucs2cat((CHAR *)loc_str, (CHAR *)L")");
        mmi_ucs2cat((CHAR *)dtv_player_p->info_str_buffer, (CHAR *)loc_str);
    }    

    cui_inline_set_item_radio_string(
        inline_id,
        MMI_DTV_USER_LOC_INFO_RADIO_LIST,
        DTV_PLAYER_RADIO_LIST_MANUAL,
        (PU8)dtv_player_p->info_str_buffer);
	#endif /* __MBBMS_CITY_LIST__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_cl_setting_screen_entry
 * DESCRIPTION
 *  mobile tv player entry cl setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_cl_setting_screen_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID inline_id = GRP_ID_INVALID;
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Stop service */
    if (KERNEL_STATE_IN(DTV_KERNEL_READY))
    {
        ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);
        ASSERT(ret == MDI_RES_MTV_SUCCEED);
    }
	
    mmi_frm_group_create(GRP_ID_DTV_PLAYER, 
		                 GRP_ID_DTV_PLAYER_CL_SETTING, 
		                 mmi_dtv_player_cl_setting_proc, 
		                 (void*)NULL);
    mmi_frm_group_enter(GRP_ID_DTV_PLAYER_CL_SETTING, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    inline_id = cui_inline_create(GRP_ID_DTV_PLAYER_CL_SETTING, &g_dtv_cl_setting_inline);

	if (inline_id > GRP_ID_INVALID)
    {
        cui_inline_set_title_icon(inline_id, DTV_PLAYER_MENU_ICON);
        mmi_dtv_player_cl_setting_config_item(inline_id);
        mmi_dtv_player_cl_setting_init_item_value(inline_id);
        cui_inline_run(inline_id);
    }
    else
    {
        mmi_dtv_player_display_popup(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_search_program_screen
 * DESCRIPTION
 *  mobile tv player entry search program screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_search_program_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_id;
    S32 i;
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Stop service */
    if (KERNEL_STATE_IN(DTV_KERNEL_READY))
    {
        ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);
        ASSERT(ret == MDI_RES_MTV_SUCCEED);
    }

    cui_id = cui_inline_create(GRP_ID_DTV_PLAYER, &g_dtv_search_program_inline);
    dtv_player_p->sp_inline_gid = cui_id;

    cui_inline_set_title_icon(cui_id, DTV_PLAYER_MENU_ICON);

    /* Service name */
    dtv_player_setting_p->service_name_str[0] = GetString(STR_ID_DTV_PLAYER_ALL);
    for (i = 0; i < dtv_player_p->num_services; i ++)
    {
        dtv_player_setting_p->service_name_str[i+1] = (CHAR*)dtv_player_p->services[i].service_name;
    }

    cui_inline_set_item_select(
            cui_id,
            MMI_DTV_CHANNEL_SELECTOR,
            dtv_player_p->num_services + 1,
            (PU8*)dtv_player_setting_p->service_name_str,
            0);

    /* Date */
    dtv_player_setting_p->search_date_str[0] = GetString(STR_ID_DTV_PLAYER_ALL);
    dtv_player_setting_p->search_date_str[1] = GetString(STR_ID_DTV_PLAYER_TODAY);
    dtv_player_setting_p->search_date_str[2] = GetString(STR_ID_DTV_PLAYER_TOMORROW);
    dtv_player_setting_p->search_date_str[3] = GetString(STR_ID_DTV_PLAYER_AFTER_TOMORROW);

    cui_inline_set_item_select(
            cui_id,
            MMI_DTV_DATE_SELECTOR,
            MMI_DTV_MAX_SEARCH_DATE,
            (PU8*)dtv_player_setting_p->search_date_str,
            0);

    cui_inline_set_softkey_text(
        cui_id, MMI_DTV_KEYWORD_TEXT_EDIT, MMI_LEFT_SOFTKEY, STR_GLOBAL_SEARCH);
	cui_inline_set_softkey_text(
        cui_id, MMI_DTV_CHANNEL_SELECTOR, MMI_LEFT_SOFTKEY, STR_GLOBAL_SEARCH);
    cui_inline_set_softkey_text(
        cui_id, MMI_DTV_DATE_SELECTOR, MMI_LEFT_SOFTKEY,STR_GLOBAL_SEARCH);

    cui_inline_run(cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_exit_help_screen
 * DESCRIPTION
 *  mobile tv player exit help screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_exit_help_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_dtv_player_free_detail_screen_memory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_construct_help
 * DESCRIPTION
 *  mobile tv player entry help screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_construct_help(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
	U16 serial[40];
	U8	result = 0;
	S32 state = 0;
	U16 help_items = STR_ID_DTV_2GPP_HELP1_CONTENT_ITEM1;
#else /* __MMI_CMMB_CAS_2GPP_SUPPORT__ */
	wgui_color_buffer_writer_struct writer;
#endif /* __MMI_CMMB_CAS_2GPP_SUPPORT__ */


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_CMMB_CAS_2GPP_SUPPORT__
    /* Help */
    mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_HELP1));
    mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");

    mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_HELP2));
    mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");

    /* Set bold */
    wgui_color_buffer_create_writer(&writer, (U8*)dtv_player_p->detail_buf, MMI_DTV_PLAYER_DETAIL_BUF_SIZE);
    wgui_color_buffer_write_char(&writer, GUI_INPUT_MARKER_BOLD);
    mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_HELP3));
    mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");
    wgui_color_buffer_create_writer(&writer, (U8*)dtv_player_p->detail_buf, MMI_DTV_PLAYER_DETAIL_BUF_SIZE);
    wgui_color_buffer_write_char(&writer, GUI_INPUT_MARKER_RESET_ALL);

    mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_HELP4));
    mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");

    /* Set bold */
    wgui_color_buffer_create_writer(&writer, (U8*)dtv_player_p->detail_buf, MMI_DTV_PLAYER_DETAIL_BUF_SIZE);
    wgui_color_buffer_write_char(&writer, GUI_INPUT_MARKER_BOLD);
    mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_PROGRAM_REMINDER));
    mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");
    wgui_color_buffer_create_writer(&writer, (U8*)dtv_player_p->detail_buf, MMI_DTV_PLAYER_DETAIL_BUF_SIZE);
    wgui_color_buffer_write_char(&writer, GUI_INPUT_MARKER_RESET_ALL);

    mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_HELP5));
    mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");

    /* Set bold */
    wgui_color_buffer_create_writer(&writer, (U8*)dtv_player_p->detail_buf, MMI_DTV_PLAYER_DETAIL_BUF_SIZE);
    wgui_color_buffer_write_char(&writer, GUI_INPUT_MARKER_BOLD);
    mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_EMERGENCY_BROADCAST));
    mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");
    wgui_color_buffer_create_writer(&writer, (U8*)dtv_player_p->detail_buf, MMI_DTV_PLAYER_DETAIL_BUF_SIZE);
    wgui_color_buffer_write_char(&writer, GUI_INPUT_MARKER_RESET_ALL);

    mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_HELP6));
    mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");
#else /* __MMI_CMMB_CAS_2GPP_SUPPORT__ */
	if (MENU_ID_DTV_2GPP_HELP1 == dtv_player_p->help_2gpp_select_item)
	{		
		mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_2GPP_HELP1_CONTENT));
		for (help_items = STR_ID_DTV_2GPP_HELP1_CONTENT_ITEM1; help_items <= STR_ID_DTV_2GPP_HELP1_CONTENT_ITEM6; help_items++)
		{
			mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n\n");		
			mmi_ucs2cat(dtv_player_p->detail_buf, GetString(help_items));
		}	
	}
	else if (MENU_ID_DTV_2GPP_HELP2 == dtv_player_p->help_2gpp_select_item)
	{		
		mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_2GPP_HELP2));		
		mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");
		result = mmi_cmmb_2gpp_adp_get_CaInfo(&state, serial);
		mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)serial);		
		mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");
	    mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_2GPP_HELP2_CONTENT));		
	}
	else
	{		
		mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_2GPP_HELP3_CONTENT));
	}
#endif
    ASSERT(mmi_ucs2strlen((CHAR *) dtv_player_p->detail_buf) <= MMI_DTV_PLAYER_DETAIL_BUF_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_help_screen
 * DESCRIPTION
 *  mobile tv player entry help screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_help_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
	#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
	U16 title_strId = STR_ID_DTV_2GPP_HELP1;
	UI_string_type lsk= 0;
	#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_HELP,
                mmi_dtv_player_exit_help_screen,
                mmi_dtv_player_entry_help_screen,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    /* suspend background play */
    mdi_audio_suspend_background_play();

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();


    /* Allocate detail buffer */
    mmi_dtv_player_alloc_detail_screen_memory();

    mmi_dtv_player_construct_help();
	
#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
	if (MENU_ID_DTV_2GPP_HELP1 == dtv_player_p->help_2gpp_select_item)
	{
		title_strId = STR_ID_DTV_2GPP_HELP1;
	}
	else if (MENU_ID_DTV_2GPP_HELP2 == dtv_player_p->help_2gpp_select_item)
	{
		title_strId = STR_ID_DTV_2GPP_HELP2;
	}
	else
	{		
		title_strId = STR_ID_DTV_2GPP_HELP3;
		lsk =  (UI_string_type)GetString(STR_ID_DTV_2GPP_CALL);
	}
    wgui_cat3005_show((UI_string_type)GetString(title_strId),
			          (PU8)GetImage(DTV_PLAYER_MENU_ICON),
                      lsk,
                      0,
                      (UI_string_type)GetString(STR_GLOBAL_BACK),
                      (PU8)GetImage(IMG_GLOBAL_BACK),
                      (PU8) dtv_player_p->detail_buf,
                      mmi_ucs2strlen((CHAR *) dtv_player_p->detail_buf),
                      guiBuffer);
#else
	wgui_cat3005_show(
			(UI_string_type)GetString(STR_GLOBAL_HELP),
			(PU8)GetImage(DTV_PLAYER_MENU_ICON),
			0,
			0,
			(UI_string_type)GetString(STR_GLOBAL_BACK),
			(PU8)GetImage(IMG_GLOBAL_BACK),
			(PU8) dtv_player_p->detail_buf,
			mmi_ucs2strlen((CHAR *) dtv_player_p->detail_buf),
			guiBuffer);
	
#endif

#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
	if (MENU_ID_DTV_2GPP_HELP3 == dtv_player_p->help_2gpp_select_item)
	{
		SetLeftSoftkeyFunction(mmi_dtv_player_2gpp_call_cbc_service_hotline, KEY_EVENT_UP);
	}
#endif	
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_pl_option_screen
 * DESCRIPTION
 *  mobile tv player program list option menu screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_pl_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dtv_player_p->pl_option_menu_gid =
        cui_menu_create(
            GRP_ID_DTV_PLAYER,
            CUI_MENU_SRC_TYPE_RESOURCE,
            CUI_MENU_TYPE_OPTION,
            MENU_ID_DTV_PLAYER_PL_OPTION,
            MMI_FALSE,
            NULL);
    cui_menu_run(dtv_player_p->pl_option_menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_pd_option_screen
 * DESCRIPTION
 *  mobile tv player program details option menu screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_pd_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dtv_player_p->pd_option_menu_gid =
        cui_menu_create(
            GRP_ID_DTV_PLAYER,
            CUI_MENU_SRC_TYPE_RESOURCE,
            CUI_MENU_TYPE_OPTION,
            MENU_ID_DTV_PLAYER_PD_OPTION,
            MMI_FALSE,
            NULL);
    cui_menu_run(dtv_player_p->pd_option_menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_service_id_to_idx
 * DESCRIPTION
 *  mobile tv player configure program list option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_dtv_player_service_id_to_idx(S32 service_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for(i = 0; i < dtv_player_p->num_services; i ++)
    {
        if (dtv_player_p->services[i].service_id == service_id)
        {
            break;
        }
    }
    ASSERT(i < dtv_player_p->num_services);

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_config_pl_option_menu
 * DESCRIPTION
 *  mobile tv player configure program list option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_config_pl_option_menu(MMI_ID send_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dtv_player_service_info_struct *info_ptr = NULL;
    dtv_player_schedule_info_struct *con_p = &dtv_player_p->selected_content;
    S32 i, ret;
    applib_time_struct cur_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cui_menu_set_item_hidden(
        send_id, MENU_ID_DTV_PLAYER_PL_OPTION_PLAY, MMI_FALSE);
    cui_menu_set_item_hidden(
        send_id, MENU_ID_DTV_PLAYER_PL_OPTION_PROGRAM_DETAILS, MMI_FALSE);
    cui_menu_set_item_hidden(
        send_id, MENU_ID_DTV_PLAYER_PL_OPTION_SEARCH_PROGRAM, MMI_FALSE);

    if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_CMMB)
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_PL_OPTION_ADD_REMINDER, MMI_TRUE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_PL_OPTION_CANCEL_REMINDER, MMI_TRUE);
    }
    else
    {
        if (con_p->if_reminder)
        {
            cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_PL_OPTION_ADD_REMINDER, MMI_TRUE);
            cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_PL_OPTION_CANCEL_REMINDER, MMI_FALSE);
        }
        else
        {
            mmi_dtv_player_get_current_system_time(&cur_time);
            ret = mmi_dtv_player_check_time_status(&cur_time, con_p->date, con_p->time);
            if (ret <= 0)
            {
                cui_menu_set_item_hidden(
                    send_id, MENU_ID_DTV_PLAYER_PL_OPTION_ADD_REMINDER, MMI_TRUE);
            }
            else
            {
                cui_menu_set_item_hidden(
                    send_id, MENU_ID_DTV_PLAYER_PL_OPTION_ADD_REMINDER, MMI_FALSE);
            }
            cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_PL_OPTION_CANCEL_REMINDER, MMI_TRUE);
        }
    }

    i = mmi_dtv_player_service_id_to_idx(con_p->service_id);
    info_ptr = &dtv_player_p->services[i];

    if (info_ptr->is_favorite)
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_PL_OPTION_ADD_TO_FAVORITES, MMI_TRUE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_PL_OPTION_DEL_FROM_FAVORITES, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_PL_OPTION_ADD_TO_FAVORITES, MMI_FALSE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_PL_OPTION_DEL_FROM_FAVORITES, MMI_TRUE);
    }   
#ifdef __MBBMS_INTER__
    if (con_p->has_inter_data)
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_PL_OPTION_CHECK_INTER_SERVICE, MMI_FALSE);        
    }
    else
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_PL_OPTION_CHECK_INTER_SERVICE, MMI_TRUE);
    }
#endif /* __MBBMS_INTER__ */    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_config_pd_option_menu
 * DESCRIPTION
 *  mobile tv player configure program list option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_config_pd_option_menu(MMI_ID send_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    applib_time_struct cur_time;

    /*----------------------------------------------------------------*/
    /* Code Bodparpary                                                */
    /*----------------------------------------------------------------*/

    if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_CMMB)
    {
        cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_PD_OPTION_PLAY, MMI_FALSE);
        cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_PD_OPTION_ADD_REMINDER, MMI_TRUE);
        cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_PD_OPTION_CANCEL_REMINDER, MMI_TRUE);
        return;
    }

    cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_PD_OPTION_PLAY, MMI_FALSE);


    if (dtv_player_p->selected_content.if_reminder)
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_PD_OPTION_ADD_REMINDER, MMI_TRUE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_PD_OPTION_CANCEL_REMINDER, MMI_FALSE);
    }
    else
    {
        mmi_dtv_player_get_current_system_time(&cur_time);
        ret = mmi_dtv_player_check_time_status(&cur_time, 
			                                   dtv_player_p->selected_content.date, 
			                                   dtv_player_p->selected_content.time);
        if (ret <= 0)
        {
            cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_PD_OPTION_ADD_REMINDER, MMI_TRUE);
        }
        else
        {
            cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_PD_OPTION_ADD_REMINDER, MMI_FALSE);
        }
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_PD_OPTION_CANCEL_REMINDER, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_config_mo_option_menu
 * DESCRIPTION
 *  mobile tv player configure manage order option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_config_mo_option_menu(MMI_ID send_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dtv_player_p->selected_order.subscribed)
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_MO_OPTION_SUBSCRIBE, MMI_TRUE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_MO_OPTION_UNSUBSCRIBE, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_MO_OPTION_SUBSCRIBE, MMI_FALSE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_MO_OPTION_UNSUBSCRIBE, MMI_TRUE);
    }

    cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_MO_OPTION_DETAILS, MMI_FALSE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_config_sr_option_menu
 * DESCRIPTION
 *  mobile tv player configure search result option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_config_sr_option_menu(MMI_ID send_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct cur_time;
    dtv_player_schedule_info_struct *con_p = &dtv_player_p->selected_content;
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_SR_OPTION_PLAY, MMI_FALSE);
    cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_SR_OPTION_PROGRAM_DETAILS, MMI_FALSE);

    if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_CMMB)
    {
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_SR_OPTION_ADD_REMINDER, MMI_TRUE);
        cui_menu_set_item_hidden(
            send_id, MENU_ID_DTV_PLAYER_SR_OPTION_CANCEL_REMINDER, MMI_TRUE);
    }
    else
    {
        if (dtv_player_p->selected_content.if_reminder)
        {
            cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_SR_OPTION_ADD_REMINDER, MMI_TRUE);
            cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_SR_OPTION_CANCEL_REMINDER, MMI_FALSE);
        }
        else
        {
            mmi_dtv_player_get_current_system_time(&cur_time);
            ret = mmi_dtv_player_check_time_status(&cur_time, con_p->date, con_p->time);
            if (ret <= 0)
            {
                cui_menu_set_item_hidden(
                    send_id, MENU_ID_DTV_PLAYER_SR_OPTION_ADD_REMINDER, MMI_TRUE);
            }
            else
            {
                cui_menu_set_item_hidden(
                    send_id, MENU_ID_DTV_PLAYER_SR_OPTION_ADD_REMINDER, MMI_FALSE);
            }
            cui_menu_set_item_hidden(
                send_id, MENU_ID_DTV_PLAYER_SR_OPTION_CANCEL_REMINDER, MMI_TRUE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_sr_option_screen
 * DESCRIPTION
 *  mobile tv player search result option menu screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_sr_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dtv_player_p->sr_option_menu_gid =
        cui_menu_create(
            GRP_ID_DTV_PLAYER,
            CUI_MENU_SRC_TYPE_RESOURCE,
            CUI_MENU_TYPE_OPTION,
            MENU_ID_DTV_PLAYER_SR_OPTION,
            MMI_FALSE,
            NULL);
    cui_menu_run(dtv_player_p->sr_option_menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_cmmb_search_result
 * DESCRIPTION
 *  mobile tv player query search result
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_dtv_player_get_cmmb_search_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    esg_query_schedule_struct *sche_ptr = NULL;
    dtv_player_schedule_info_struct *schedule_ptr;
    S32 idx = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    while(idx < MMI_DTV_MAX_SCHEDULES)
    {
        mdi_mtv_esg_get_result(dtv_player_p->mtv_handle, 
			                   MEDIA_MTV_ESG_SOURCE_DEFAULT, 
			                   ESG_QUERY_CONTENT_BY_KEYWORD, 
			                   (void **)&sche_ptr);
        if (sche_ptr == NULL)
        {
            break;
        }

        while (sche_ptr != NULL)
        {
            schedule_ptr = &dtv_player_p->schedules[idx];

            schedule_ptr->content_id = sche_ptr->content_ref_id;
            schedule_ptr->service_id = sche_ptr->service_ref_id;

            /* Name */
            mmi_ucs2cpy((CHAR*) schedule_ptr->name, (CHAR*) sche_ptr->title);

            /* Date */
            mmi_ucs2ncpy((CHAR*)schedule_ptr->date, 
                         (CHAR*)sche_ptr->start_date_time, 10);

            /* Time */
            if (mmi_ucs2strlen((CHAR*)sche_ptr->start_date_time) > 0)
            {
                mmi_ucs2ncpy((CHAR *)schedule_ptr->time, 
					         (CHAR *)&(sche_ptr->start_date_time[11]), 5);
            }
            else
            {
                mmi_ucs2ncpy((CHAR *)schedule_ptr->time, (CHAR *)L"     ", 5); 
            }
            mmi_ucs2cat((CHAR*)schedule_ptr->time, (CHAR*)L"-");
            if (mmi_ucs2strlen((CHAR*)sche_ptr->end_date_time) > 0)
            {
                mmi_ucs2ncat((CHAR *)schedule_ptr->time, 
					         (CHAR *)&(sche_ptr->end_date_time[11]), 5);
            }

            /* Not supported */
            schedule_ptr->if_reminder = MMI_FALSE;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_TRC_DTV_SERVICE_ID,
                sche_ptr->service_ref_id, idx, __LINE__);

            idx ++;
            sche_ptr = sche_ptr->next_p;
            if (idx >= MMI_DTV_MAX_SCHEDULES)
            {
                break;
            }
        }
    }

    return idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_mbbms_search_result
 * DESCRIPTION
 *  mobile tv player query search result
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_dtv_player_get_mbbms_search_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mbbms_sg_query_content_struct *content_p = NULL;
    dtv_player_schedule_info_struct *sche_ptr;
    S32 idx = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    while(idx < MMI_DTV_MAX_SCHEDULES)
    {
        mdi_mtv_esg_get_result(dtv_player_p->mtv_handle, 
			                   MEDIA_MTV_ESG_SOURCE_DEFAULT, 
			                   ESG_QUERY_CONTENT_BY_KEYWORD, 
			                   (void **)&content_p);
        if (content_p == NULL)
        {
            break;
        }

        while (content_p != NULL)
        {
            sche_ptr = &dtv_player_p->schedules[idx];
            /* ID */
            strcpy(sche_ptr->cid, content_p->id);

            /* Service ID */
            sche_ptr->service_id = content_p->sid;

            /* Name */
            mmi_ucs2ncpy((CHAR*) sche_ptr->name, 
                         (CHAR*) content_p->name, 
                         MMI_DTV_NAME_STR_LENGTH);

            /* Date */
            mmi_ucs2ncpy((CHAR*)sche_ptr->date, (CHAR*)content_p->start_time, 10);

            /* Time */
            mmi_ucs2ncpy((CHAR*)sche_ptr->time, (CHAR*)&content_p->start_time[11], 5);
            mmi_ucs2cat((CHAR*)sche_ptr->time, (CHAR*)L"-");
            mmi_ucs2ncat((CHAR*)sche_ptr->time, (CHAR*)&content_p->end_time[11], 5);

            sche_ptr->if_reminder = content_p->in_reminder;						
		#ifdef __MBBMS_INTER__
            sche_ptr->has_inter_data = content_p->has_inter_data;
		#endif /* __MBBMS_INTER__ */
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_TRC_DTV_SERVICE_ID,
                sche_ptr->service_id, idx, __LINE__);

            idx ++;
            content_p = content_p->next_p;
            if (idx >= MMI_DTV_MAX_SCHEDULES)
            {
                break;
            }
        }
    }

    return idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_search_query
 * DESCRIPTION
 *  mobile tv player query search result
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_get_search_query(mdi_mtv_query_struct *query, U32 start_idx, U32 query_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct offset_time;
	applib_time_struct output_time;
    S32 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Keyword*/
    if (mmi_ucs2strlen((CHAR*)dtv_player_p->keyword) > 0)
    {
        query->keyword = dtv_player_p->keyword;
    }

    /* Channel index */
    idx = dtv_player_p->search_channel_idx;
    if (idx == 0)
    {
        query->id = MTV_ESG_INVALID_SID;
    }
    else
    {
        query->id = dtv_player_p->services[idx - 1].service_id;
    }
    /* Date. Today:1, Tomorrow:2, After tomorrow:3 */
    idx = dtv_player_p->search_date_idx;

    if (idx >= 1)
    {
        memset(&offset_time, 0, sizeof(applib_time_struct));
        offset_time.nDay = idx - 1;
        applib_dt_increase_time(&dtv_player_p->search_time, &offset_time, &output_time);
        output_time.nHour = output_time.nMin = output_time.nSec = 0;
        *(query->time) = output_time;
    }
    else
    {
        /* Set as NULL */
        query->time = NULL;
    }

    query->start_idx = start_idx;
    query->query_num = query_num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_query_search_result
 * DESCRIPTION
 *  mobile tv player query search result
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_query_search_result(U32 start_idx, U32 query_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    mdi_mtv_query_struct query = {0};
    applib_time_struct query_time = {0};
    S32 num;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    query.time = &query_time;
    mmi_dtv_player_get_search_query(&query, start_idx, query_num);

    memset(dtv_player_p->schedules, 0, MMI_DTV_MAX_SCHEDULES * sizeof(dtv_player_schedule_info_struct));


    ret = mdi_mtv_esg_query(
            dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_CONTENT_BY_KEYWORD, &query);

    if (ret != MDI_RES_MTV_SUCCEED)
    {
        /* handle error case */
        return;
    }

    dtv_player_p->sche_start_idx = start_idx;

    if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_CMMB)
    {
        num = mmi_dtv_player_get_cmmb_search_result();
    }
    else /* MBBMS or MBBMS ready */
    {
        num = mmi_dtv_player_get_mbbms_search_result();
    }

    dtv_player_p->sche_end_idx = start_idx + num - 1;

    ASSERT(dtv_player_p->sche_end_idx < dtv_player_p->num_schedules);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_update_schedule_range
 * DESCRIPTION
 *  mobile tv player query search result
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_update_schedule_range(
            S32 start_idx, S32 num_item, S32 *query_idx, S32 *query_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 center_idx, over_num;
    S32 total_num = MMI_DTV_MAX_SCHEDULES;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Don't need to update */
    if (start_idx >= dtv_player_p->sche_start_idx &&
        start_idx + num_item -1 <= dtv_player_p->sche_end_idx)
    {
        return MMI_FALSE;
    }

    /* Assign range */
    center_idx = start_idx + num_item / 2;
    *query_idx = center_idx - total_num / 2;
    if (*query_idx < 0)
    {
        *query_idx = 0;
    }
    *query_num = total_num;

    over_num = *query_idx + total_num - dtv_player_p->num_schedules;
    if (over_num > 0)
    {
        *query_idx -= over_num;
        if (*query_idx < 0)
        {
            *query_idx = 0;
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_query_search_total_num
 * DESCRIPTION
 *  mobile tv player query search result
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_query_search_total_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    mdi_mtv_query_struct query = {0};
    applib_time_struct query_time = {0};
    mtv_esg_query_record_count *count_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    query.time = &query_time;
    mmi_dtv_player_get_search_query(&query, 0, (U32)-1);

    dtv_player_p->num_schedules = 0;

    ret = mdi_mtv_esg_query(dtv_player_p->mtv_handle, 
		                    MEDIA_MTV_ESG_SOURCE_DEFAULT, 
		                    ESG_QUERY_CONTENT_BY_KEYWORD_COUNT, 
		                    &query);

    if (ret != MDI_RES_MTV_SUCCEED)
    {
        /* handle error case */
        return;
    }

    ret = mdi_mtv_esg_get_result(dtv_player_p->mtv_handle, 
		                         MEDIA_MTV_ESG_SOURCE_DEFAULT, 
		                         ESG_QUERY_CONTENT_BY_KEYWORD_COUNT, 
		                         (void **)&count_ptr);

    if (count_ptr != NULL)
    {
        dtv_player_p->num_schedules = count_ptr->number;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
		      MMI_TRC_DTV_VAL1, 
		      dtv_player_p->num_schedules, 
		      __LINE__);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_exit_search_result_screen
 * DESCRIPTION
 *  mobile tv player exit search result screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_exit_search_result_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dtv_player_p->schedules != NULL)
    {
    #ifdef __COSMOS_MMI_PACKAGE__
        applib_asm_free_r(GRP_ID_DTV_PLAYER, (void *)dtv_player_p->schedules);
    #else /* __COSMOS_MMI_PACKAGE__ */    
        mmi_frm_scrmem_free((void *) dtv_player_p->schedules);
    #endif  /* __COSMOS_MMI_PACKAGE__ */      
        dtv_player_p->schedules = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_search_result_screen
 * DESCRIPTION
 *  set DTV PLAYER setting values
 * PARAMETERS
 *  void
 *  idx(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_search_result_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
	applib_time_struct cur_time;
    S32 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_SEARCH_RESULT,
                mmi_dtv_player_exit_search_result_screen,
                mmi_dtv_player_entry_search_result_screen,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    /* suspend background play */
    mdi_audio_suspend_background_play();

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    /* Allocate schedule list buffer */
    ASSERT(sizeof(dtv_player_schedule_info_struct) <= MMI_DTV_MAX_SCHEDULE_INFO_STRUCTURE_SIZE);
#ifdef __COSMOS_MMI_PACKAGE__    
        dtv_player_p->schedules =
                (dtv_player_schedule_info_struct *) applib_asm_alloc_nc_r(GRP_ID_DTV_PLAYER, MMI_DTV_MAX_SCHEDULES * sizeof(dtv_player_schedule_info_struct));
#else /* __COSMOS_MMI_PACKAGE__ */

    dtv_player_p->schedules = (dtv_player_schedule_info_struct*) mmi_frm_scrmem_alloc(MMI_DTV_MAX_SCHEDULES * sizeof(dtv_player_schedule_info_struct));

#endif /* __COSMOS_MMI_PACKAGE__ */

    ASSERT(dtv_player_p->schedules != NULL);
    memset(dtv_player_p->schedules, 0, MMI_DTV_MAX_SCHEDULES * sizeof(dtv_player_schedule_info_struct));

    dtv_player_p->sche_start_idx = -1;
    dtv_player_p->sche_end_idx = -1;


    if (dtv_player_p->ca_state != MMI_DTV_CA_STATE_CMMB)
    {
        /* Purify reminder list before query content */
        mmi_dtv_player_get_current_system_time(&cur_time);
        mdi_mtv_purify_program_reminder(dtv_player_p->mtv_handle, &cur_time);
        mmi_dtv_player_update_alarm();
    }

    mmi_dtv_player_get_current_system_time(&dtv_player_p->search_time);
    mmi_dtv_player_get_current_system_time(&dtv_player_p->play_status_time);	

    dtv_player_p->search_time.nHour = 0;
    dtv_player_p->search_time.nMin = 0;
    dtv_player_p->search_time.nSec = 0;

    mmi_dtv_player_query_search_total_num();

    if (dtv_player_p->num_schedules > 0)
    {
        /* Call enable before showCategory, call change after showCategory */
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }

    RegisterHighlightHandler(mmi_dtv_player_content_highlight_hdlr);

    wgui_cat1022_show(
        (WCHAR *) GetString(STR_ID_DTV_PLAYER_SEARCH_RESULT),
        (PU8)GetImage(DTV_PLAYER_MENU_ICON),
        (WCHAR *) GetString(STR_GLOBAL_OPTIONS),
        (PU8)GetImage(IMG_GLOBAL_OPTIONS),
        (WCHAR *) GetString(STR_GLOBAL_BACK),
        (PU8)GetImage(IMG_GLOBAL_BACK),
        dtv_player_p->num_schedules,
        mmi_dtv_player_get_content_async_items,
        NULL,
        0,
        guiBuffer,
        &error);

    if (dtv_player_p->num_schedules > 0)
    {
        SetLeftSoftkeyFunction(mmi_dtv_player_entry_sr_option_screen, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_dtv_player_play_selected_content, KEY_EVENT_UP);
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_register_tap_callback(mmi_dtv_player_content_tap_callback);
    #endif /* __MMI_TOUCH_SCREEN__ */
    }
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);


}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_set_search_value
 * DESCRIPTION
 *  set DTV PLAYER setting values
 * PARAMETERS
 *  void
 *  idx(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_set_search_value(MMI_ID sender_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Keyword */
    cui_inline_get_value(
        sender_id, MMI_DTV_KEYWORD_TEXT_EDIT, dtv_player_p->keyword);

    /* Channel */
    cui_inline_get_value(
        sender_id, MMI_DTV_CHANNEL_SELECTOR, &dtv_player_p->search_channel_idx);

    /* Date */
    cui_inline_get_value(
        sender_id, MMI_DTV_DATE_SELECTOR, &dtv_player_p->search_date_idx);

    mmi_dtv_player_entry_search_result_screen();

    /* Display empty warning */
    if (dtv_player_p->num_schedules == 0)
    {
        mmi_dtv_player_gen_separate_string(
            (WCHAR*)GetString(STR_ID_DTV_PLAYER_SEARCH_RESULT_WARNING),
            (WCHAR*)dtv_player_p->keyword, NULL);

        mmi_dtv_player_enter_info_confirm_screen();
        /* Close search result screen */
        mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_SEARCH_RESULT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_update_with_city_name
 * DESCRIPTION
 *  rename channel
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
void mmi_dtv_player_update_with_city_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_ucs2strlen((CHAR*)dtv_player_p->city) == 0)
    {
        mmi_dtv_player_display_popup(
            STR_GLOBAL_INVALID_INPUT,
            MMI_EVENT_FAILURE);

         return;
    }

    mmi_dtv_player_update_channel_list();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_sc_option_screen
 * DESCRIPTION
 *  Entry specify city option
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void mmi_dtv_player_entry_sc_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->sc_option_menu_gid =
        cui_menu_create(
            GRP_ID_DTV_PLAYER,
            CUI_MENU_SRC_TYPE_RESOURCE,
            CUI_MENU_TYPE_OPTION,
            MENU_ID_DTV_PLAYER_SPECIFY_CITY_OPTION,
            MMI_FALSE,
            NULL);
    cui_menu_run(dtv_player_p->sc_option_menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_specify_city_screen
 * DESCRIPTION
 *  mobile tv player specify city screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_specify_city_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_scrn_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_SPECIFY_CITY,
                NULL,
                mmi_dtv_player_entry_specify_city_screen,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    /* suspend background play */
    mdi_audio_suspend_background_play();

    /* Call enable before showCategory, call change after showCategory */
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    if (guiBuffer == NULL)
    {
        /* Reset memory */
        mmi_ucs2cpy((CHAR*)dtv_player_p->city, (CHAR*)L"");
    }

    wgui_cat2003_show(
        (WCHAR *) GetString(STR_ID_DTV_PLAYER_SPECIFY_CITY),
		(PU8)GetImage(DTV_PLAYER_MENU_ICON),
        (WCHAR *) GetString(STR_GLOBAL_OPTIONS),
        (PU8)GetImage(IMG_GLOBAL_OPTIONS),
        (WCHAR *) GetString(STR_GLOBAL_BACK),
        (PU8)GetImage(IMG_GLOBAL_BACK),
        (WCHAR *) GetString(STR_ID_DTV_PLAYER_SPECIFY_CITY_GUIDE),
        (UI_buffer_type)dtv_player_p->city,
        MMI_DTV_CITY_STR_LEN + 1,
        IMM_INPUT_TYPE_SENTENCE,
        guiBuffer);

	wgui_inputs_category_set_rsk_func(mmi_frm_scrn_close_active_id);
    SetLeftSoftkeyFunction(mmi_dtv_player_entry_sc_option_screen, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_dtv_player_update_with_city_name, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_highlight_update_approach_hdlr
 * DESCRIPTION
 *  mobile tv player highlight update approach hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_highlight_update_approach_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dtv_player_p->update_approach = idx;
    if (DTV_PLAYER_UPDATE_AUTO == idx) /* Automatic */
    {
        SetCenterSoftkeyFunction(mmi_dtv_player_update_channel_list, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_dtv_player_update_channel_list, KEY_EVENT_UP);
    }
    else /* Specify city name */
    {
        SetCenterSoftkeyFunction(mmi_dtv_player_entry_specify_city_screen, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_dtv_player_entry_specify_city_screen, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_update_approach_screen_leave_proc
 * DESCRIPTION
 *  This function is the callback funcion for deleting idle notify screen
 * PARAMETERS
 *  p
 * RETURNS
 *  U8
 *****************************************************************************/
 mmi_ret mmi_dtv_player_update_approach_screen_leave_proc(mmi_event_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mtv_mts_command = MMI_FALSE;

    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_update_select_screen
 * DESCRIPTION
 *  mobile tv player update select screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_update_approach_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
	U32 i = 0;
    U8 *image_list[DTV_PLAYER_UPDATE_APPROACH_NUM];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_scrn_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_UPDATE_APPROACH,
                NULL,
                mmi_dtv_player_entry_update_approach_screen,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }
    /* suspend background play */
    mdi_audio_suspend_background_play();

    mmi_frm_scrn_set_leave_proc(
        GRP_ID_DTV_PLAYER,
        SCR_ID_DTV_PLAYER_UPDATE_APPROACH,
        mmi_dtv_player_update_approach_screen_leave_proc);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    RegisterHighlightHandler(mmi_dtv_player_highlight_update_approach_hdlr);

    dtv_player_setting_p->update_approach_str[0] =
        GetString((U16) STR_GLOBAL_AUTOMATIC);
    dtv_player_setting_p->update_approach_str[1] =
        GetString((U16) STR_ID_DTV_PLAYER_SPECIFY_CITY);

    /* Call enable before showCategory, call change after showCategory */
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    for (i = 0; i < DTV_PLAYER_UPDATE_APPROACH_NUM; i++)
    {
        image_list[i] = (U8*) GetImage(IMG_GLOBAL_L1 + i);
    }

    if (guiBuffer == NULL)
    {
        dtv_player_p->update_approach = DTV_PLAYER_UPDATE_AUTO;
    }

    ShowCategory32Screen(
        (PU8) GetString(STR_ID_DTV_PLAYER_CHOOSE_UPDATE_APPROACH),
        NULL,
        (PU8) GetString(STR_GLOBAL_OK),
        (PU8) GetImage(IMG_GLOBAL_OK),
        (PU8) GetString(STR_GLOBAL_BACK),
        (PU8) GetImage(IMG_GLOBAL_BACK),
        DTV_PLAYER_UPDATE_APPROACH_NUM,
        dtv_player_setting_p->update_approach_str,
        image_list,
        0,
        dtv_player_p->update_approach,
        guiBuffer);


    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_display_order_confirm
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
void mmi_dtv_player_display_order_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dtv_player_p->selected_order.subscribed)
    {
        mmi_dtv_player_display_confirm(STR_ID_DTV_PLAYER_UNSUBSCRIBE_ASK);
    }
    else
    {
        mmi_dtv_player_display_confirm(STR_ID_DTV_PLAYER_SUBSCRIBE_ASK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_enter_cmmb_mode_confirm
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
void mmi_dtv_player_enter_cmmb_mode_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* guiBuffer;
    PU8 str;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* CMMB_2GPP need confirm */
	#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
		return;
	#endif
	
    if (!mmi_frm_scrn_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_CMMB_MODE_CONFIRM,
                NULL,
                mmi_dtv_player_enter_cmmb_mode_confirm,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    /* No sim */
#ifdef __MBBMS_DUAL_SIM_SUPPORT__
    if ((srv_sim_ctrl_is_available(MMI_SIM1) == MMI_FALSE)
		&& (srv_sim_ctrl_is_available(MMI_SIM2) == MMI_FALSE))
#else	
	if (srv_sim_ctrl_is_available(MMI_SIM1) == MMI_FALSE)
#endif
    {
        str = (PU8)GetString(STR_ID_DTV_PLAYER_CMMB_MODE_NO_SIM);
    }
    else
    {
        str = (PU8)GetString(STR_ID_DTV_PLAYER_CMMB_MODE_NO_NW);
    }

    /* Call enable before showCategory, call change after showCategory */
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#ifdef __MMI_FTE_SUPPORT__
    ShowCategory66Screen(
        STR_ID_DTV_PLAYER_APP_NAME,
        DTV_PLAYER_MENU_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_ID_DTV_PLAYER_NULL,
        IMG_ID_DTV_PLAYER_NULL,
        str,
        0,
        guiBuffer);
#else /* __MMI_FTE_SUPPORT__ */
    ShowCategory74Screen(
        STR_ID_DTV_PLAYER_APP_NAME,
        DTV_PLAYER_MENU_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        NULL,
        NULL,
        (PU8) str,
        mmi_ucs2strlen((CHAR *) str),
        guiBuffer);
#endif /* __MMI_FTE_SUPPORT__ */

    mmi_dtv_player_unset_flag(DTV_PLAYER_DISPLAY_CMMB_MODE_CONFIRM);

    SetLeftSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_switch_to_mbbms_mode
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
void mmi_dtv_player_switch_to_mbbms_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->auto_launch = MMI_TRUE;
    dtv_player_p->go_back_history = MMI_TRUE;

    if (!KERNEL_STATE_IN(DTV_KERNEL_OPENED))
    {
        ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);
        ASSERT(ret == MDI_RES_MTV_SUCCEED);
    }

    mmi_dtv_player_kernel_enter_state(DTV_KERNEL_CLOSING);

    mmi_frm_group_close(GRP_ID_DTV_PLAYER);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_enter_mbbms_mode_confirm
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
void mmi_dtv_player_enter_mbbms_mode_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* guiBuffer;
    PU8 str;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_scrn_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_MBBMS_MODE_CONFIRM,
                NULL,
                mmi_dtv_player_enter_mbbms_mode_confirm,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    str = (PU8)GetString(STR_ID_DTV_PLAYER_MBBMS_MODE);

    /* Call enable before showCategory, call change after showCategory */
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory66Screen(STR_ID_DTV_PLAYER_APP_NAME,
				         DTV_PLAYER_MENU_ICON,
        				 STR_GLOBAL_OK,
				         IMG_ID_DTV_PLAYER_NULL,
                         STR_GLOBAL_CANCEL,
                         IMG_ID_DTV_PLAYER_NULL,
                         str,
                         IMG_ID_DTV_PLAYER_NULL,
                         guiBuffer);

	SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	SetLeftSoftkeyFunction(mmi_dtv_player_switch_to_mbbms_mode, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_dtv_player_switch_to_mbbms_mode, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_enter_mbbms_mode_timeout
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
void mmi_dtv_player_enter_mbbms_mode_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_service_availability_enum avail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (KERNEL_STATE_IN(DTV_KERNEL_CLOSED) || KERNEL_STATE_IN(DTV_KERNEL_CLOSING))
    {
        return;
    }

    if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_CMMB)
    {
        avail = srv_nw_info_get_service_availability(dtv_player_p->cur_sim);
        if (avail != SRV_NW_INFO_SA_FULL_SERVICE)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL1, avail, __LINE__);
            return;
        }

        mmi_dtv_player_enter_mbbms_mode_confirm();

        mmi_frm_scrn_close(GRP_ID_DTV_PLAYER,
                           SCR_ID_DTV_PLAYER_CMMB_MODE_CONFIRM);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_gen_scan_progress
 * DESCRIPTION
 *  enter subscribing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_gen_scan_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 value;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    value = dtv_player_p->scan_progress + (100 - dtv_player_p->scan_progress) / 40;
    mmi_dtv_player_update_scan_progress(value);

    StartTimer(
        DTV_PLAYER_UPDATE_SCAN_STATUS, 1000,
        mmi_dtv_player_gen_scan_progress);

}
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_mbbms_update_screen_leave_proc
 * DESCRIPTION
 *  This function is delete callback
 * PARAMETERS
 *  p
 * RETURNS
 *  U8
 *****************************************************************************/
 mmi_ret mmi_dtv_player_mbbms_update_screen_leave_proc(mmi_event_struct *para)
{
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
            break;
        }
        default:
		{
            break;
        }
    }
    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_service_flag
 * DESCRIPTION
 *  service update handler
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_get_service_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    U32 flag = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < dtv_player_p->num_services; i ++)
    {
        mdi_mtv_get_services_ca(dtv_player_p->mtv_handle,
                                dtv_player_p->services[i].service_id, 
                                &flag, 
                                NULL);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_TRC_MTV_SERVICE_FLAG,
                  i, dtv_player_p->services[i].service_id, flag);

        dtv_player_p->services[i].service_flags = (S32)flag;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_display_mbbms_init_fail
 * DESCRIPTION
 *  service update handler
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_display_mbbms_init_fail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_service_availability_enum avail;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avail = srv_nw_info_get_service_availability(dtv_player_p->cur_sim);
    if (avail == SRV_NW_INFO_SA_FULL_SERVICE)
    {
        mmi_ucs2ncpy(
            (CHAR*)dtv_player_p->info_str_buffer,
            (CHAR*)GetString(STR_ID_DTV_PLAYER_FAIL_TO_UPDATE_ESG),
            MMI_DTV_INFO_STR_LENGTH);
    }
    else
    {
        mmi_ucs2ncpy(
            (CHAR*)dtv_player_p->info_str_buffer,
            (CHAR*)GetString(STR_ID_DTV_PLAYER_FAIL_TO_CONNECT_NETWORK),
            MMI_DTV_INFO_STR_LENGTH);
    }
    /* Display confirm */
    mmi_dtv_player_enter_info_confirm_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_set_mts_display
 * DESCRIPTION
 *  Mobile TV Player init function,
 *  which is called when MMI Task is initializing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_set_mts_display(MMI_BOOL display)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 handle;
    WCHAR path[30] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->display_mts_menu = display;

    mmi_ucs2cpy((CHAR *)path, (CHAR *)MTV_SETTING_PATH);
    mmi_ucs2cat((CHAR *)path, (CHAR *)L"mts");

    if (display)
    {
        handle = FS_Open(path, FS_READ_WRITE | FS_CREATE_ALWAYS);
        if (handle > 0)
        {
            FS_Close(handle);
        }
    }
    else
    {
        FS_Delete(path);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_mts_display
 * DESCRIPTION
 *  Mobile TV Player init function,
 *  which is called when MMI Task is initializing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_get_mts_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return dtv_player_p->display_mts_menu;
}

#ifdef __MBBMS_INTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_disable_view_function
 * DESCRIPTION
 *  mmi_dtv_player_disable_view_function
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_disable_view_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dtv_player_osd_cntx.view.status =  DTV_PLAYER_ICON_STATUS_DISABLE;
    g_dtv_player_osd_cntx_270.view.status =  DTV_PLAYER_ICON_STATUS_DISABLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_enable_view_function
 * DESCRIPTION
 *  mmi_dtv_player_enable_view_function
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_enable_view_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dtv_player_osd_cntx.view.status =  DTV_PLAYER_ICON_STATUS_ENABLE;
    g_dtv_player_osd_cntx_270.view.status =  DTV_PLAYER_ICON_STATUS_DISABLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_view_icon_press
 * DESCRIPTION
 *  mobile tv player view press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_view_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_VIEW;
    dtv_player_p->active_osd_cntx_p->view.status = DTV_PLAYER_ICON_STATUS_CLICKED;

    /* Do nothing */
    mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_view_icon_release
 * DESCRIPTION
 *  mobile tv player view icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_view_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dtv_player_p->touch_object != DTV_PLAYER_TOUCH_VIEW)
    {
        return;
    }
    dtv_player_p->is_key_pressed = MMI_FALSE;
    dtv_player_p->touch_object = DTV_PLAYER_TOUCH_NONE;
    dtv_player_p->active_osd_cntx_p->view.status  = DTV_PLAYER_ICON_STATUS_ENABLE;

    ASSERT(dtv_player_p->int_state == DTV_PLAYER_INT_STATE_ONE_LINE);        
    ASSERT(dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0);
    
    dtv_player_p->int_state = DTV_PLAYER_INT_STATE_HALF_SCREEN;	
    mmi_dtv_player_config_inter_layer(); 
    mmi_dtv_player_set_blt_layer();

    mmi_dtv_player_register_key_hdlr();
    mmi_dtv_player_draw_osd();
    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

#ifdef __MBBMS_V30_OPERA__
    mmi_dtv_player_opera_engine_restart(dtv_player_p->opera_layer_handle);
#endif
    //TODO: ask browser to draw one-line layer 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_half_inter_app_screen
 * DESCRIPTION
 *  display inter in half mode in app play screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_half_inter_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->int_state = DTV_PLAYER_INT_STATE_HALF_SCREEN;	
	/*  Go back to app play screen  */	
    mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, 
		               SCR_ID_DTV_PLAYER_SERVICE_INTER_LIST);
    mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, 
		               SCR_ID_DTV_PLAYER_SERVICE_INTER);    
}
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_si_option_screen
 * DESCRIPTION
 *  mobile tv player service's interactivity service option menu screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_entry_si_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_create_and_run(GRP_ID_DTV_PLAYER,
						    CUI_MENU_SRC_TYPE_RESOURCE,
						    CUI_MENU_TYPE_OPTION,
						    MENU_ID_DTV_PLAYER_SI_OPTION,
						    MMI_FALSE,
						    NULL);    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_inter_detail_display
 * DESCRIPTION
 *  Nofity the Opera Browser to display inter details
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_inter_detail_display(S16 x, S16 y, S16 width, S16 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(x, y, x + width, y + height - 1);
    gdi_draw_solid_rect(x, y, x + width, y + height - 1, GDI_COLOR_GRAY);
    gdi_layer_pop_clip();
	
#ifdef __MBBMS_V30_OPERA__
	dtv_player_p->opera_page_rect.x = x;	
	dtv_player_p->opera_page_rect.y = y;
	dtv_player_p->opera_page_rect.w = width;
	dtv_player_p->opera_page_rect.h = height;
#endif /* __MBBMS_V30_OPERA__ */

}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_cat6001_dummy
 * DESCRIPTION
 *  Just dummy function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_cat6001_dummy(mmi_pen_event_type_enum pen_event, 
	                                  mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/		
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_reset_detail_button_state
 * DESCRIPTION
 *  mobile tv player reset detail button state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_reset_detail_button_state(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (0 == dtv_player_p->selected_imd)
	{
		wgui_icon_bar_set_item_enable_state(DTV_PLAYER_INTER_DETAIL_PRE, MMI_FALSE);				
	}
	else
	{		
		wgui_icon_bar_set_item_enable_state(DTV_PLAYER_INTER_DETAIL_PRE, MMI_TRUE);				
	}
	
	if ((dtv_player_p->num_imd - 1) == dtv_player_p->selected_imd)
	{
		wgui_icon_bar_set_item_enable_state(DTV_PLAYER_INTER_DETAIL_NEXT, MMI_FALSE);
	}
	else
	{
		wgui_icon_bar_set_item_enable_state(DTV_PLAYER_INTER_DETAIL_NEXT, MMI_TRUE);
	}	
	
	wgui_icon_bar_update();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_exit_inter_detail_screen
 * DESCRIPTION
 *  mobile tv player exit inter detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_exit_service_inter_screen(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MBBMS_V30_OPERA__
    mmi_dtv_player_opera_engine_pause();
    mmi_dtv_player_free_opera_layer_memory();
#endif /* __MBBMS_V30_OPERA__ */
}
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_service_inter_detail_button_process
 * DESCRIPTION
 *  mmi_dtv_player_service_inter_detail_button_process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_service_inter_detail_button_process(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
    CHAR imd_unread_str[20];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    switch (index)
    {
    	case DTV_PLAYER_INTER_DETAIL_PRE:
			{				
				dtv_player_p->selected_imd--;
				break;
    		}
		case DTV_PLAYER_INTER_DETAIL_NEXT:
			{				
				dtv_player_p->selected_imd++;
				break;
			}
		default:
			{
				break;
			}
    }
	ASSERT(dtv_player_p->selected_imd < dtv_player_p->num_imd);
	/* update button state */
	mmi_dtv_player_reset_detail_button_state();
	
	/* update title of category */
	kal_wsprintf((WCHAR *)imd_unread_str, "%d", dtv_player_p->selected_imd + 1);
	mmi_ucs2ncpy((CHAR * )dtv_player_p->info_str_buffer,
		         (CHAR *)GetString(STR_ID_DTV_INTERACTIVITY),
		        mmi_ucs2strlen((PS8)GetString(STR_ID_DTV_INTERACTIVITY)));
	mmi_ucs2ncat((CHAR * )dtv_player_p->info_str_buffer,
		         (CHAR *)imd_unread_str,
		         mmi_ucs2strlen((PS8)imd_unread_str));
	
	ChangeTitleString((CHAR *)dtv_player_p->info_str_buffer);
	draw_title();

	/* update imd web page */
	#ifdef __MBBMS_V30_OPERA__
	mmi_dtv_player_opera_engine_display_imd();
	#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_service_inter_screen
 * DESCRIPTION
 *  mobile tv player entry service inter detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_service_inter_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 config_info = 0;
	PU8 icon_bar_fg[DTV_PLAYER_INTER_DETAIL_TOTAL] = {NULL, NULL};
	PU8 icon_bar_disable[DTV_PLAYER_INTER_DETAIL_TOTAL] = {NULL, NULL};
	PU8 icon_bar_string[DTV_PLAYER_INTER_DETAIL_TOTAL] = {NULL, NULL};	
    CHAR imd_unread_str[20];
#ifdef __MBBMS_V30_OPERA__	
    gdi_handle layer1, layer2, layer3, layer4;
#endif	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	if (!mmi_frm_scrn_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_SERVICE_INTER,
                mmi_dtv_player_exit_service_inter_screen,
                mmi_dtv_player_entry_service_inter_screen,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    } 
	/* suspend background play */
	mdi_audio_suspend_background_play();	
#ifdef __MBBMS_V30_OPERA__	
    mmi_dtv_player_alloc_opera_layer_memory();
#endif		
	config_info = WGUI_CAT6001_NEED_SCR_BG | WGUI_CAT6001_NEED_SOFTKEY 
		         | WGUI_CAT6001_NEED_STATUS_ICON | WGUI_CAT6001_NEED_TITLE;
	
	icon_bar_string[DTV_PLAYER_INTER_DETAIL_PRE] = (PU8)get_string(STR_ID_DTV_INTER_DETAIL_PRE);
	icon_bar_string[DTV_PLAYER_INTER_DETAIL_NEXT] = (PU8)get_string(STR_ID_DTV_INTER_DETAIL_NEXT);
	wgui_icon_bar_setup(DTV_PLAYER_INTER_DETAIL_TOTAL,
		                icon_bar_fg,
		                icon_bar_disable,
		                icon_bar_string,
		                mmi_dtv_player_service_inter_detail_button_process);
	wgui_icon_bar_set_flags_on(GUI_ICON_BAR_FLAG_DRAW_HINT_AS_TEXT);
	wgui_icon_bar_set_flags_off(GUI_ICON_BAR_FLAG_ENABLE_HINT);
	mmi_dtv_player_reset_detail_button_state();
	
    kal_wsprintf((WCHAR *)imd_unread_str, "%d", dtv_player_p->selected_imd + 1);	
	
	mmi_ucs2ncpy((CHAR * )dtv_player_p->info_str_buffer,
		        (const CHAR *)GetString(STR_ID_DTV_INTERACTIVITY),
		        mmi_ucs2strlen((const PS8)GetString(STR_ID_DTV_INTERACTIVITY)));
	
	mmi_ucs2ncat((CHAR * )dtv_player_p->info_str_buffer,
		         (const CHAR *)imd_unread_str,
		         mmi_ucs2strlen((const PS8)imd_unread_str));
	
	wgui_cat6001_show((UI_string_type)dtv_player_p->info_str_buffer,
			          get_image(IMG_ID_DTV_PLAYER_NULL),
			          get_string(STR_GLOBAL_OPTIONS),
			          get_image(IMG_ID_DTV_PLAYER_NULL),
			          get_string(STR_GLOBAL_BACK),
			          get_image(IMG_ID_DTV_PLAYER_NULL),
			          config_info,
                      mmi_dtv_player_inter_detail_display,
                      mmi_dtv_player_cat6001_dummy);
	draw_title_left_align();
	SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_dtv_player_entry_si_option_screen, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_dtv_player_entry_si_option_screen, KEY_EVENT_UP);

#ifdef __MBBMS_V30_OPERA__
	#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_pen_down_handler(mmi_dtv_player_inter_fullscreen_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_dtv_player_inter_fullscreen_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_dtv_player_inter_fullscreen_pen_move_hdlr);
	#endif /* __MMI_TOUCH_SCREEN__  */

    gdi_layer_get_blt_layer(&layer1, &layer2, &layer3, &layer4);
    if (GDI_NULL_HANDLE == layer2)
    {
        gdi_layer_set_blt_layer(layer1, dtv_player_p->opera_layer_handle,layer3, layer4);
    }
    else if (GDI_NULL_HANDLE == layer3)
    {
        gdi_layer_set_blt_layer(layer1, layer2, dtv_player_p->opera_layer_handle,layer4);
    }else if (GDI_NULL_HANDLE == layer4)
    {
        gdi_layer_set_blt_layer(layer1, layer2, layer3, dtv_player_p->opera_layer_handle);
    }
    mmi_dtv_player_opera_engine_restart(dtv_player_p->opera_layer_handle);
#endif /* __MBBMS_V30_OPEREA__ */

}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_inter_tap_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_inter_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_dtv_player_entry_service_inter_screen();
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_async_service_inter_item
 * DESCRIPTION
 *  mobile tv player get async service inter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_dtv_player_get_async_service_inter(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item)
{
  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
	U32 imd_idx = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < num_item; i ++)
    {
        imd_idx = start_indx + i;
        ASSERT((imd_idx < dtv_player_p->num_imd) && (imd_idx < MMI_DTV_MAX_INTER_LIST));
        mmi_ucs2ncpy(
            (CHAR*)menuData[i].item_list[0],
            (CHAR*)dtv_player_p->inter_list[imd_idx].desc,
            MAX_SUBMENU_CHARACTERS * 2); /* Two lines */

        if (dtv_player_p->inter_list[imd_idx].read)
        {
            menuData[i].image_list[0] = GetImage(IMG_ID_DTV_PLAYER_MENU_READ);
        }
        else
        {
            menuData[i].image_list[0] = GetImage(IMG_ID_DTV_PLAYER_MENU_UNREAD);
        }
        
    }

    return num_item;
 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_service_inter_list
 * DESCRIPTION
 *  mobile tv player get service inter list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_get_service_inter_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 idx = 0;
    dtv_player_service_info_struct *info_ptr;
    mdi_mtv_imd_desc_struct imd_desc;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    info_ptr = mmi_dtv_player_get_active_channel_ptr();  
    for (idx = 0; 
         idx < dtv_player_p->num_imd && idx < MMI_DTV_MAX_INTER_LIST; 
         idx ++)
    {
        imd_desc.imd_index = idx;
        imd_desc.desc_len = MMI_DTV_TEXT_STR_LENGTH;
        imd_desc.desc = dtv_player_p->inter_list[idx].desc;
        imd_desc.if_read = &dtv_player_p->inter_list[idx].read;
        mdi_mtv_get_imd_desc(dtv_player_p->mtv_handle,              
                             info_ptr->service_id, 
                             &imd_desc);  
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_service_inter_highlight_hdlr
 * DESCRIPTION
 *  mobile tv player service inter highlight hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_service_inter_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dtv_player_p->selected_imd = index;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_exit_service_inter_list_screen
 * DESCRIPTION
 *  mobile tv player exit service list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_exit_service_inter_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dtv_player_p->inter_list != NULL)
    {
        mmi_frm_scrmem_free(dtv_player_p->inter_list);
        dtv_player_p->inter_list = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_service_inter_list_screen
 * DESCRIPTION
 *  mobile tv player entry service inter list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_service_inter_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 error;
    dtv_player_service_info_struct *info_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_SERVICE_INTER_LIST,
                mmi_dtv_player_exit_service_inter_list_screen,
                mmi_dtv_player_entry_service_inter_list_screen,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    
    /* Emergency broadcast message */
    ASSERT(sizeof(dtv_player_inter_list_struct) <= MMI_DTV_MAX_INTER_LIST_STRUCTURE_SIZE);

    dtv_player_p->inter_list = (dtv_player_inter_list_struct*) mmi_frm_scrmem_alloc(MMI_DTV_MAX_INTER_LIST * sizeof(dtv_player_inter_list_struct));
    ASSERT(dtv_player_p->inter_list != NULL);
    memset(dtv_player_p->inter_list, 0, MMI_DTV_MAX_INTER_LIST * sizeof(dtv_player_inter_list_struct));

    mmi_dtv_player_get_service_inter_list();
    
    /* suspend background play */
    mdi_audio_suspend_background_play();

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    RegisterHighlightHandler(mmi_dtv_player_service_inter_highlight_hdlr);

    /* Generate title */
    info_ptr = mmi_dtv_player_get_active_channel_ptr();    
    mmi_dtv_player_gen_separate_string(
        (WCHAR*)GetString(STR_ID_DTV_INTERACTIVITY_CONTENT),
        (WCHAR*)info_ptr->service_name, NULL);

    /* Call enable before showCategory, call change after showCategory */
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
	if (NULL != guiBuffer)
    {
        change_list_menu_category_history(guiBuffer,            
                                          dtv_player_p->selected_imd,
                                          dtv_player_p->num_imd,
                                          0);
    }
    wgui_cat1050_show(
        (CHAR *)dtv_player_p->info_str_buffer,
        GetImage(DTV_PLAYER_MENU_ICON),
        STR_GLOBAL_VIEW,
        STR_GLOBAL_BACK,
        dtv_player_p->num_imd,
        mmi_dtv_player_get_async_service_inter,
        dtv_player_p->selected_imd,
        guiBuffer,
        &error);

    SetLeftSoftkeyFunction(mmi_dtv_player_entry_service_inter_screen, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_dtv_player_entry_service_inter_screen, KEY_EVENT_UP);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_tap_callback(mmi_dtv_player_inter_tap_callback);
#endif /* __MMI_TOUCH_SCREEN__ */
    
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_exit_content_inter_screen
 * DESCRIPTION
 *  mobile tv player exit inter screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_exit_content_inter_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MBBMS_V30_OPERA__
		mmi_dtv_player_opera_engine_pause();
		mmi_dtv_player_free_opera_layer_memory();
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_content_inter_detail_display
 * DESCRIPTION
 *  mobile tv player display inter part of Opera
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_content_inter_detail_display(S16 x, S16 y, S16 width, S16 height)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	gdi_layer_push_clip();
	gdi_layer_set_clip(x, y, x + width, y + height - 1);
	gdi_draw_solid_rect(x, y, x + width, y + height - 1, GDI_COLOR_GRAY);
	gdi_layer_pop_clip();
	
#ifdef __MBBMS_V30_OPERA__
    dtv_player_p->opera_page_rect.x = x;
    dtv_player_p->opera_page_rect.y = y;
    dtv_player_p->opera_page_rect.w = width;
    dtv_player_p->opera_page_rect.h = height;	
#endif /* __MBBMS_V30_OPERA__ */
	
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_content_inter_screen
 * DESCRIPTION
 *  mobile tv player entry inter screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_content_inter_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 config_info = 0;
#ifdef __MBBMS_V30_OPERA__	
    gdi_handle layer1, layer2, layer3, layer4;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_CONTENT_INTER,
                mmi_dtv_player_exit_content_inter_screen,
                mmi_dtv_player_entry_content_inter_screen,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }
    /* suspend background play */
    mdi_audio_suspend_background_play();
    /* Allocate detail buffer */
#ifdef __MBBMS_V30_OPERA__	
    mmi_dtv_player_alloc_opera_layer_memory();
#endif	
	config_info = WGUI_CAT6001_NEED_SCR_BG | WGUI_CAT6001_NEED_SOFTKEY 
					 | WGUI_CAT6001_NEED_STATUS_ICON | WGUI_CAT6001_NEED_TITLE;
	
	wgui_cat6001_show(get_string(STR_ID_DTV_INTERACTIVITY),
			          get_image(IMG_ID_DTV_PLAYER_NULL),
			          get_string(STR_ID_DTV_PLAYER_INTER_DOWNLOAD),
			          get_image(IMG_ID_DTV_PLAYER_NULL),
			          get_string(STR_GLOBAL_BACK),
			          get_image(IMG_ID_DTV_PLAYER_NULL),
			          config_info,
                      mmi_dtv_player_content_inter_detail_display,
                      mmi_dtv_player_cat6001_dummy);
	draw_title_left_align();
	SetLeftSoftkeyFunction(mmi_dtv_player_entry_inter_file_download_screen,KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_dtv_player_entry_inter_file_download_screen,KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	
#ifdef __MBBMS_V30_OPERA__
	#ifdef __MMI_TOUCH_SCREEN__
	/* register pen down/up/move event */
	wgui_register_pen_down_handler(mmi_dtv_player_inter_fullscreen_pen_down_hdlr);
	wgui_register_pen_up_handler(mmi_dtv_player_inter_fullscreen_pen_up_hdlr);
	wgui_register_pen_move_handler(mmi_dtv_player_inter_fullscreen_pen_move_hdlr);
	#endif /* __MMI_TOUCH_SCREEN__  */
	gdi_layer_get_blt_layer(&layer1, &layer2, &layer3, &layer4);
	if (GDI_NULL_HANDLE == layer2)
	{
		gdi_layer_set_blt_layer(layer1, dtv_player_p->opera_layer_handle,layer3, layer4);
	}
	else if (GDI_NULL_HANDLE == layer3)
	{
		gdi_layer_set_blt_layer(layer1, layer2, dtv_player_p->opera_layer_handle,layer4);
	}else if (GDI_NULL_HANDLE == layer4)
	{
		gdi_layer_set_blt_layer(layer1, layer2, layer3, dtv_player_p->opera_layer_handle);
	}
    mmi_dtv_player_opera_engine_restart(dtv_player_p->opera_layer_handle);
#endif /* __MBBMS_V30_OPERA__ */

}
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_interactivity_retrieve
 * DESCRIPTION
 *  mobile tv player play info click callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_interactivity_retrieve(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    dtv_player_p->process_type = DTV_PLAYER_PROCESS_TYPE_INTERACTIVITY_RETRIEVE;
    mmi_dtv_player_enter_process_screen();
#else
	mmi_dtv_player_entry_content_inter_screen();
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_pd_hilite_callback
 * DESCRIPTION
 *  mobile tv player program detail hilite callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_pd_hilite_callback(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* There is only one selection string. So always set CSK function handler */
    SetCenterSoftkeyFunction(mmi_dtv_player_interactivity_retrieve, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_pd_click_callback
 * DESCRIPTION
 *  mobile tv player play info click callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_pd_click_callback(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dtv_player_interactivity_retrieve();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_inter_retrieve_result_hdlr
 * DESCRIPTION
 *  service update handler
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_inter_retrieve_result_hdlr(S32 param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (KERNEL_STATE_IN(DTV_KERNEL_PROCESS))
    {
        ASSERT(dtv_player_p->process_type == DTV_PLAYER_PROCESS_TYPE_INTERACTIVITY_RETRIEVE);

        KERNEL_ENTER_STATE(DTV_KERNEL_OPENED);

        if (param < 0)
        {
            mmi_dtv_player_display_failure_popup(param);
        }
        else
        {            
            mmi_dtv_player_entry_content_inter_screen();
        }

        /* delete process screens */
        mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_PROCESS);

    }    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_config_inter_layer
 * DESCRIPTION
 *  config all layer's size / rotation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_config_inter_layer(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dls_height = 0;
	S32 dls_width = 0;
    S32 dls_offset_y = 0;
    dtv_player_service_info_struct *active_service = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    /* DLS layer is not used */
    if (dtv_player_p->int_state == DTV_PLAYER_INT_STATE_OFF ||
        dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        return;
    }   
    
    if (dtv_player_p->int_state == DTV_PLAYER_INT_STATE_HALF_SCREEN)
    {
        dls_offset_y = 0;
        dls_width = DTV_PLAYER_INTER_BUFFER_WIDTH;
        dls_height = DTV_PLAYER_INTER_BUFFER_HEIGHT;
#ifdef __MBBMS_V30_OPERA__
        active_service = mmi_dtv_player_get_active_channel_ptr();
        if (MDI_MTV_SERVICE_TYPE_DIGITAL_TV == active_service->service_type)
        {
            dtv_player_p->opera_page_rect.x = 0;
            dtv_player_p->opera_page_rect.y = DTV_PLAYER_INTER_LAYER_HALF_SCREEN_OFFSET_Y;
            dtv_player_p->opera_page_rect.w = DTV_PLAYER_INTER_LAYER_HALF_SCREEN_WIDTH;
            dtv_player_p->opera_page_rect.h = DTV_PLAYER_INTER_LAYER_HALF_SCREEN_HEIGHT;
        }
        else if (MDI_MTV_SERVICE_TYPE_DIGITAL_RADIO == active_service->service_type)
        {
            dtv_player_p->opera_page_rect.x = 0;
            dtv_player_p->opera_page_rect.y = DTV_PLAYER_DISPLAY_LAYER_OFFSET_Y;
            dtv_player_p->opera_page_rect.w = DTV_PLAYER_INTER_LAYER_HALF_SCREEN_WIDTH;
            dtv_player_p->opera_page_rect.h = LCD_HEIGHT - MMI_SOFTKEY_HEIGHT - DTV_PLAYER_DISPLAY_LAYER_OFFSET_Y;
        }
        dtv_player_p->opera_layer_handle = dtv_player_p->dls_layer_handle;
#endif
		/* stop one line scrolling before config inter layer */
		if (DTV_PLAYER_DYNAMIC_LABEL_OFF != dtv_player_p->dynamic_inter_state)
		{
			mmi_dtv_player_clear_dynamic_inter_desc();
			mmi_dtv_player_config_functions_by_state();
		}
    }
    else if (dtv_player_p->int_state == DTV_PLAYER_INT_STATE_ONE_LINE)
    {
        dls_offset_y = DTV_PLAYER_INTER_LAYER_ONE_LINE_OFFSET_Y;
        dls_width = DTV_PLAYER_INTER_LAYER_ONE_LINE_WIDTH;
        dls_height = DTV_PLAYER_INTER_LAYER_ONE_LINE_HEIGHT;
    }
    
    gdi_layer_push_and_set_active(dtv_player_p->dls_layer_handle);
    gdi_layer_resize(dls_width, dls_height);
    gdi_layer_set_position(0, dls_offset_y);
    gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
    gdi_lcd_set_rotate_by_layer(KAL_FALSE);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);    
    gdi_layer_set_opacity(MMI_TRUE, 200);
    if (dtv_player_p->int_state == DTV_PLAYER_INT_STATE_HALF_SCREEN)
    {  
    	gdi_layer_clear(GDI_COLOR_TRANSPARENT); 
        gdi_draw_solid_rect(0, DTV_PLAYER_INTER_LAYER_HALF_SCREEN_OFFSET_Y, 
		                DTV_PLAYER_INTER_LAYER_HALF_SCREEN_WIDTH, DTV_PLAYER_INTER_LAYER_HALF_SCREEN_OFFSET_Y + DTV_PLAYER_INTER_LAYER_HALF_SCREEN_HEIGHT,
	                 	GDI_COLOR_GRAY);
    }
	else
	{
		gdi_layer_clear(GDI_COLOR_TRANSPARENT);
	}
    gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_update_imd_count
 * DESCRIPTION
 *  service update handler
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_update_imd_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dtv_player_service_info_struct *info_ptr;
    U16 active_screen;
    mdi_mtv_imd_desc_struct imd_desc;
    MMI_BOOL if_read = MMI_TRUE;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    active_screen = mmi_frm_scrn_get_active_id();        
    info_ptr = mmi_dtv_player_get_active_channel_ptr();
    /* Update IMD count */
    mdi_mtv_get_imd_count(dtv_player_p->mtv_handle, 
                          info_ptr->service_id,
                          &dtv_player_p->num_imd, 
                          &dtv_player_p->num_unread_imd, 
                          &dtv_player_p->imd_display_desc);
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
		      MMI_TRC_DTV_UPDATE_SERVICE_IMD, 
		      dtv_player_p->num_imd,
		      dtv_player_p->num_unread_imd, 
		      dtv_player_p->imd_display_desc);
	if ((SCR_ID_DTV_PLAYER_APP == active_screen)
		&& (MMI_FRM_SCREEN_ROTATE_0 == dtv_player_p->ui_rotate)
		&& (MMI_TRUE == dtv_player_p->setting.inter_auto_popup)
		&& (DTV_PLAYER_INT_STATE_OFF == dtv_player_p->int_state)
		&& (0 < dtv_player_p->num_unread_imd))
	{		
		dtv_player_p->int_state = DTV_PLAYER_INT_STATE_ONE_LINE;
		mmi_dtv_player_config_inter_layer();       
    	mmi_dtv_player_set_blt_layer();

		imd_desc.desc_len = MMI_DTV_INFO_STR_LENGTH;
		imd_desc.desc = (WCHAR* )dtv_player_p->info_str_buffer;
		imd_desc.if_read = &if_read;
		imd_desc.imd_index = dtv_player_p->imd_display_desc;
		mdi_mtv_get_imd_desc(dtv_player_p->mtv_handle, info_ptr->service_id, &imd_desc);		
		dtv_player_p->selected_imd = dtv_player_p->imd_display_desc;
		mmi_dtv_player_draw_inter_description();
            /* draw view icon and blt */
        mmi_dtv_player_register_key_hdlr();
        mmi_dtv_player_draw_osd_and_blt();
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_draw_service_inter_icon
 * DESCRIPTION
 *  mobile tv player draw service inter icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_draw_service_inter_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width, height, str_width, str_height;
    S32 offset_x, offset_y;
    dtv_player_osd_text_struct *osd;
    dtv_player_osd_icon_struct *icon;
    WCHAR imd_unread_str[30];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* No need to draw IMD icon */
    if (dtv_player_p->num_imd == 0)
    {
        return;
    }   

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL1, dtv_player_p->num_imd, __LINE__);
	
    /* String */        
    kal_wsprintf(imd_unread_str, "%d", dtv_player_p->num_unread_imd);
	mmi_ucs2ncat((CHAR *)imd_unread_str,
		         (CHAR *)get_string(STR_ID_DTV_INTERACTIVITY),
		         mmi_ucs2strlen((PS8)get_string(STR_ID_DTV_INTERACTIVITY)));
    gui_set_font(&MMI_medium_font);
    gui_measure_string((UI_string_type) imd_unread_str, &str_width, &str_height);
    
    gdi_image_get_dimension_id(IMG_ID_DTV_PLAYER_MENU_INTE_DATA, &width, &height);
       
    /* Subject */
    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {     
        /* Icon */  
        osd = &dtv_player_p->active_osd_cntx_p->subject;
        
        offset_x = LCD_WIDTH * 3 / 4;
        offset_y = osd->offset_y + ((osd->height - height)>>1);

        gdi_image_draw_id(offset_x, offset_y, IMG_ID_DTV_PLAYER_MENU_INTE_DATA);

        /* Interactivity string */     
        offset_x += (width + 3);        
        offset_y = osd->offset_y + ((osd->height - str_height)>>1);
        mmi_dtv_player_draw_style_text((CHAR *)imd_unread_str, offset_x, offset_y);


        /* View icon */
        icon = &dtv_player_p->active_osd_cntx_p->view;
        if(dtv_player_p->active_osd_cntx_p->view.status == DTV_PLAYER_ICON_STATUS_ENABLE)
        {            
            gdi_image_draw_resized_id(
                icon->offset_x, icon->offset_y, 
                DTV_PLAYER_INTER_LAYER_ONE_LINE_VIEW_WIDTH, icon->height, 
                IMG_ID_DTV_PLAYER_VIEW_UP);
        }
        else if(dtv_player_p->active_osd_cntx_p->view.status == DTV_PLAYER_ICON_STATUS_CLICKED)
        {
            gdi_image_draw_resized_id(
                icon->offset_x, icon->offset_y, 
                DTV_PLAYER_INTER_LAYER_ONE_LINE_VIEW_WIDTH, icon->height, 
                IMG_ID_DTV_PLAYER_VIEW_DOWN);
        }

        if(dtv_player_p->active_osd_cntx_p->view.status != DTV_PLAYER_ICON_STATUS_DISABLE)
        {
            /* View string */
            gui_measure_string((UI_string_type) GetString(STR_GLOBAL_VIEW), &str_width, &str_height);
            mmi_dtv_player_draw_style_text(
                (CHAR *)GetString(STR_GLOBAL_VIEW),
                icon->offset_x + ((icon->width - str_width) >>1), 
                icon->offset_y + ((icon->height - str_height) >>1));   
        }
    }  
    else
    {     
        /* interactivity icon */        
        offset_x = 3;       
        offset_y = DTV_PLAYER_FULLSCREEN_DLS_LAYER_HEIGHT + 3;        
        if (height < str_height)
        {
            offset_y += ((str_height - height)>>1);
        }
        gdi_image_draw_id(offset_x, offset_y, IMG_ID_DTV_PLAYER_MENU_INTE_DATA);

        /* Interactivity string */     
        offset_x += (width + 3);
        offset_y = DTV_PLAYER_FULLSCREEN_DLS_LAYER_HEIGHT + 3;        
        if (height > str_height)
        {
            offset_y += ((height - str_height)>>1);
        }
        mmi_dtv_player_draw_style_text((CHAR *)imd_unread_str, offset_x, offset_y);       
    } 
  
        
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_imd_ready_hdlr
 * DESCRIPTION
 *  service update handler
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_imd_ready_hdlr(S32 param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dtv_player_update_imd_count();
}

#endif /* __MBBMS_INTER__ */

#ifdef __MBBMS_UPGRADE__
#ifdef __DM_FOTA_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_upgrade_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
void mmi_dtv_player_upgrade_callback(srv_dm_fota_query_result_enum result,
                                     void *user_data)                                    
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 string_id = STR_ID_DTV_PLAYER_NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_alert_dismiss(dtv_player_p->upgrade_confirm_id);
    switch (result)
    {
        case SRV_DM_FOTA_QUERY_RESULT_OK:
             {
                 break;
             }
        case SRV_DM_FOTA_QUERY_RESULT_FAIL:
             {
                 break;
             }
		case SRV_DM_FOTA_QUERY_RESULT_CANCEL:
             {
                 break;
             }
        case SRV_DM_FOTA_QUERY_RESULT_NOT_READY:
             {
			 	 string_id = STR_GLOBAL_NOT_AVAILABLE;
                 break;
             }
        case SRV_DM_FOTA_QUERY_RESULT_ON_OPERATING:
             {
			 	 string_id = STR_GLOBAL_UPDATE;
                 break;
             }
        case SRV_DM_FOTA_QUERY_RESULT_NO_UPDATE_PKG:
             {
			 	 string_id = STR_ID_DTV_UPGRADE_NONE;
                 break;
             }
        default :
             {
                 break;
             }
    }
	if (STR_ID_DTV_PLAYER_NULL != string_id)
	{
	    mmi_popup_display((WCHAR*)get_string(string_id), MMI_EVENT_INFO, NULL);		
	}	
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_upgrade_cancel_proc
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
mmi_ret mmi_dtv_player_upgrade_cancel_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_FOTA_SUPPORT__	
	srv_dm_fota_query_cancel();
#endif
	return MMI_RET_OK;
}
/*****************************************************************************
 * FunctionName: mmi_dtv_player_entry_upgrade_process_screen
 * Description
 *     
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-03-01
 *****************************************************************************/
void mmi_dtv_player_entry_upgrade_process_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_CANCEL);
    arg.callback = mmi_dtv_player_upgrade_cancel_proc;
    arg.f_auto_map_empty_softkey = MMI_FALSE;
#if !defined(__MMI_FTE_SUPPORT__)
    arg.f_msg_icon = MMI_FALSE;
#endif
    dtv_player_p->upgrade_confirm_id = mmi_confirm_display((WCHAR *)GetString(STR_GLOBAL_PLEASE_WAIT),
                                                           MMI_EVENT_PROGRESS, &arg);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_upgrade
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
void mmi_dtv_player_upgrade(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_dtv_player_entry_upgrade_process_screen();
#ifdef __DM_FOTA_SUPPORT__	
    srv_dm_fota_query_update(mmi_dtv_player_upgrade_callback,
                             NULL);
#endif
}
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_display_upgrade_confirm
 * DESCRIPTION
 *  service update handler
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_display_upgrade_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dtv_player_p->upgrade_type == MDI_RES_MTV_UPGRADE_NONE)
    {
        mmi_dtv_player_display_popup(STR_ID_DTV_UPGRADE_NONE, MMI_EVENT_SUCCESS);
    }
    else if (dtv_player_p->upgrade_type == MDI_RES_MTV_UPGRADE_NEED)
    {
        mmi_dtv_player_display_confirm(STR_ID_DTV_UPGRADE_NEED_ASK);
    }
    else if (dtv_player_p->upgrade_type == MDI_RES_MTV_UPGRADE_MANDATORY)
    {
        mmi_dtv_player_display_confirm(STR_ID_DTV_UPGRADE_MANDATORY_ASK);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_display_upgrade_query
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_display_upgrade_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    dtv_player_p->process_type = DTV_PLAYER_PROCESS_TYPE_UPGRADE_QUERY;
    mmi_dtv_player_enter_process_screen(); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_upgrade_result_hdlr
 * DESCRIPTION
 *  service update handler
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_upgrade_result_hdlr(S32 param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Set variable */
    if (param >= 0)
    {
        dtv_player_p->upgrade_type = param;
    }

    /* If not in upgrade query status, postpone upgrade confirm to subscription update result */
    if (!mmi_frm_scrn_is_present(
            GRP_ID_DTV_PLAYER,
            SCR_ID_DTV_PLAYER_PROCESS,
            MMI_FRM_NODE_ALL_FLAG))
    {
        return;
    }

    ASSERT(dtv_player_p->process_type == DTV_PLAYER_PROCESS_TYPE_UPGRADE_QUERY);
    KERNEL_ENTER_STATE(DTV_KERNEL_OPENED);

    if (param < 0)
    {
        mmi_dtv_player_display_failure_popup(param);
    }
    else
    {
        mmi_dtv_player_display_upgrade_confirm();
    }    

    /* delete upgrade query screens */
    mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_PROCESS);
}

#endif /* __MBBMS_UPGRADE__ */
#ifdef __MBBMS_CITY_LIST__
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_allocate_city_mem
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_allocate_city_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_ALLOC_CITY_MEM);

    ASSERT(sizeof(dtv_player_city_struct) <= MMI_DTV_MAX_CITY_STRUCTURE_SIZE);
    if (dtv_player_p->recommend_city == NULL)
    {
        dtv_player_p->recommend_city = (dtv_player_city_struct*) kal_adm_alloc(
                                    dtv_player_p->adm_pool_id,
                                    MMI_DTV_MAX_RECOMMEND_CITY * sizeof(dtv_player_city_struct));
        ASSERT(dtv_player_p->recommend_city != NULL);
        memset(dtv_player_p->recommend_city, 0, MMI_DTV_MAX_RECOMMEND_CITY * sizeof(dtv_player_city_struct));
    }

    dtv_player_p->num_recommend_city = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_free_city_mem
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_free_city_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_FREE_CITY_MEM);
    if (dtv_player_p->recommend_city != NULL)
    {
        kal_adm_free(dtv_player_p->adm_pool_id,(void *) dtv_player_p->recommend_city);
        dtv_player_p->recommend_city = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_area_set_retrieve
 * DESCRIPTION
 *  mobile tv player area set retrieve
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_area_set_retrieve(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    dtv_player_p->process_type = DTV_PLAYER_PROCESS_TYPE_AREA_SET_RETRIEVE;
    mmi_dtv_player_enter_process_screen(); 

    /* Close play info screen */
    mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_PLAY_INFO);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_play_info_hilite_callback
 * DESCRIPTION
 *  mobile tv player play info hilite callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_play_info_hilite_callback(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    SetCenterSoftkeyFunction(mmi_dtv_player_area_set_retrieve, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_play_info_click_callback
 * DESCRIPTION
 *  mobile tv player play info click callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_play_info_click_callback(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_dtv_player_area_set_retrieve();    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_construct_play_info
 * DESCRIPTION
 *  mobile tv player construct play info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_construct_play_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HILITE_STR *hilite_ptr;
    WCHAR area_name[MBBMS_SG_NAME_LEN + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ucs2cpy(dtv_player_p->detail_buf, GetString(STR_ID_DTV_CANNOT_WATCH_REASON1));
    mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n\n");

    mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_CANNOT_WATCH_REASON2));
    mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n\n");

    mmi_dtv_player_query_sgdd_info(MMI_DTV_SGDD_AREA_NAME, area_name, MBBMS_SG_NAME_LEN);
    mmi_dtv_player_gen_separate_string(
        (WCHAR *)GetString(STR_ID_DTV_CANNOT_WATCH_REASON3), area_name, area_name);
    mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)dtv_player_p->info_str_buffer);
    
    kal_mem_set(&dtv_player_p->hilite_str, 0, sizeof(HILITE_STR));
        
    /* Hilite string: choose to modify */
    hilite_ptr = &dtv_player_p->hilite_str;
    hilite_ptr->hilite_type = EDITOR_HILITE_URL;
    hilite_ptr->length = mmi_ucs2strlen(GetString(STR_ID_DTV_CHOOSE_TO_MODIFY));
    hilite_ptr->str_addr = dtv_player_p->detail_buf + 2 * mmi_ucs2strlen(dtv_player_p->detail_buf);

    /* Choose to modify */
    mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_CHOOSE_TO_MODIFY));
    mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n\n");    


    ASSERT(mmi_ucs2strlen((CHAR *) dtv_player_p->detail_buf) <= MMI_DTV_PLAYER_DETAIL_BUF_SIZE);


}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_exit_play_info_screen
 * DESCRIPTION
 *  mobile tv player exit play info screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_exit_play_info_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dtv_player_free_detail_screen_memory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_play_info_screen
 * DESCRIPTION
 *  mobile tv player entry play info screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_play_info_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_PLAY_INFO,
                mmi_dtv_player_exit_play_info_screen,
                mmi_dtv_player_entry_play_info_screen,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    /* suspend background play */
    mdi_audio_suspend_background_play();

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    /* Allocate detail buffer */
    mmi_dtv_player_alloc_detail_screen_memory();

    mmi_dtv_player_construct_play_info();

    /* Call enable before showCategory, call change after showCategory */
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);


    ShowCategory228Screen(
        STR_ID_DTV_PLAYER_APP_NAME,
		DTV_PLAYER_MENU_ICON,
        STR_GLOBAL_OK,
        STR_GLOBAL_OK,
        STR_ID_DTV_PLAYER_NULL,
        IMG_ID_DTV_PLAYER_NULL,
        (PU8)dtv_player_p->detail_buf,
        mmi_ucs2strlen((CHAR *) dtv_player_p->detail_buf),
        &dtv_player_p->hilite_str,
        1,
        mmi_dtv_player_play_info_hilite_callback,
        guiBuffer);

    wgui_cat_text_viewer_set_highlight_click_callback(
        mmi_dtv_player_play_info_click_callback);
        
    SetLeftSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_city_found_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
void mmi_dtv_player_city_found_hdlr(mdi_mtv_city_info_struct *city,void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 idx;
    dtv_player_city_struct *city_p;
    mdi_mtv_city_struct *source_city_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (idx = 0;
         idx < city->city_count && dtv_player_p->num_recommend_city < MMI_DTV_MAX_RECOMMEND_CITY;
         idx ++)
    {
        city_p = &dtv_player_p->recommend_city[dtv_player_p->num_recommend_city];
        source_city_p = &city->city_info[idx];

        mmi_ucs2ncpy((CHAR*)city_p->name, (CHAR*)source_city_p->city_name, MMI_DTV_CITY_STR_LEN);

        dtv_player_p->num_recommend_city ++;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_display_city_list
 * DESCRIPTION
 *
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_display_city_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dtv_player_p->num_recommend_city > 0)
    {
        mmi_dtv_player_entry_city_list_recommend_screen();
    }
    else
    {
        mmi_dtv_player_entry_city_list_level_1_screen();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_area_retrieve_result_hdlr
 * DESCRIPTION
 *  service update handler
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_area_retrieve_result_hdlr(S32 param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (KERNEL_STATE_IN(DTV_KERNEL_PROCESS))
    {
        ASSERT(dtv_player_p->process_type == DTV_PLAYER_PROCESS_TYPE_AREA_SET_RETRIEVE);

        KERNEL_ENTER_STATE(DTV_KERNEL_OPENED);

        if (param < 0)
        {
            mmi_dtv_player_display_failure_popup(param);
        }
        else
        {            
            mmi_dtv_player_unset_flag(DTV_PLAYER_SG_RET_LOCATION_DETECT_FAIL);
            mmi_dtv_player_display_city_list();

        }

        /* delete process screens */
        mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_PROCESS);

    }
    /* During SG retrieve */
    else if (KERNEL_STATE_IN(DTV_KERNEL_SCANNING))
    {
        StopTimer(DTV_PLAYER_UPDATE_SCAN_STATUS);
        KERNEL_ENTER_STATE(DTV_KERNEL_OPENED);

        dtv_player_p->ca_state = MMI_DTV_CA_STATE_MBBMS_FAIL;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_CA_STATE, MMI_DTV_CA_STATE_MBBMS_FAIL);

        if (param < 0)
        {
            mmi_dtv_player_display_failure_popup(param);
        }
        else
        {
            mmi_dtv_player_set_flag(DTV_PLAYER_SG_RET_LOCATION_DETECT_FAIL);
            mmi_dtv_player_display_city_list();

        }

        mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_SCANNING);

    }
    /* During MBBMS init */
    else
    {
        mmi_dtv_player_finalize_mbbms_init(param);


        dtv_player_p->ca_state = MMI_DTV_CA_STATE_MBBMS_FAIL;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_CA_STATE, MMI_DTV_CA_STATE_MBBMS_FAIL);

        if (param < 0)
        {
            mmi_dtv_player_display_failure_popup(param);
        }
        else
        {
            mmi_dtv_player_set_flag(DTV_PLAYER_SG_RET_LOCATION_DETECT_FAIL);
            mmi_dtv_player_display_city_list();
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_close_all_city_list_screen
 * DESCRIPTION
 *  mobile tv player close all city list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_close_all_city_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Close city list screens */    
    mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_CITY_LIST_RECOMMEND);
    mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_CITY_LIST_LEVEL_1);
    mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_CITY_LIST_LEVEL_2);
    mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_CITY_LIST_LEVEL_3);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_city_select_hdlr
 * DESCRIPTION
 *  mobile tv player city select handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_city_select_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* If user chooses to remember location or come from setting screen, 
       save the selected city to NVRAM */
    if (dtv_player_p->if_rememeber_location ||
        mmi_frm_group_is_present(GRP_ID_DTV_PLAYER_CL_SETTING))
    {
        dtv_player_p->setting.manual_set_loc = MMI_TRUE;
        
        mmi_ucs2ncpy(
            (CHAR *)dtv_player_p->setting.location,
            (CHAR *)dtv_player_p->selected_city[dtv_player_p->city_list_type].name,
            MMI_DTV_CITY_STR_LEN);

        WriteRecord(NVRAM_EF_DTV_PLAYER_SETTING_LID, 1, (void*)&dtv_player_p->setting, NVRAM_EF_DTV_PLAYER_SETTING_SIZE, &error);
    }

    dtv_player_p->update_approach = DTV_PLAYER_UPDATE_AUTO;
    mmi_dtv_player_update_channel_list();

    mmi_dtv_player_close_all_city_list_screen();

    /* Close setting inline CUI */
    mmi_frm_group_close(GRP_ID_DTV_PLAYER_CL_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_next_level_screen
 * DESCRIPTION
 *  mobile tv player entry next level screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_next_level_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr entry_func[DTV_PLAYER_CITY_LIST_NUM] =
    {
        mmi_dtv_player_entry_city_list_recommend_screen,
        mmi_dtv_player_entry_city_list_level_1_screen,
        mmi_dtv_player_entry_city_list_level_2_screen,
        mmi_dtv_player_entry_city_list_level_3_screen
    };
    U32 city_num;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(dtv_player_p->city_list_type == DTV_PLAYER_CITY_LIST_LEVEL_1 ||
           dtv_player_p->city_list_type == DTV_PLAYER_CITY_LIST_LEVEL_2);

    city_num = mmi_dtv_player_query_display_city_num();
    if (city_num > 0)
    {
        entry_func[dtv_player_p->city_list_type + 1]();
    }
    else
    {
        mmi_dtv_player_city_select_hdlr();
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_config_city_list_title
 * DESCRIPTION
 *  mobile tv player entry city list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_config_city_list_title(MMI_BOOL is_inited)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = 0;
    WCHAR full_city[MMI_DTV_CITY_STR_LEN * 2 + 2] = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_mem_set(dtv_player_p->info_str_buffer, 0, sizeof(dtv_player_p->info_str_buffer));

    switch (dtv_player_p->city_list_type)
    {
        case DTV_PLAYER_CITY_LIST_RECOMMEND:
            if (is_inited && mmi_dtv_player_is_flag_set(DTV_PLAYER_SG_RET_LOCATION_DETECT_FAIL))
            {
                mmi_ucs2ncpy(
                    (CHAR *)dtv_player_p->info_str_buffer,
                    GetString(STR_ID_DTV_FAIL_TO_DETECT_LOCATION),
                    MMI_DTV_INFO_STR_LENGTH);
            }
            len = mmi_ucs2strlen((CHAR *)dtv_player_p->info_str_buffer);
            mmi_ucs2ncat(
                (CHAR *)dtv_player_p->info_str_buffer,
                GetString(STR_ID_DTV_RECOMMEND_CITY_TITLE),
                MMI_DTV_INFO_STR_LENGTH - len);
            break;
            
        case DTV_PLAYER_CITY_LIST_LEVEL_1:
            if (is_inited && mmi_dtv_player_is_flag_set(DTV_PLAYER_SG_RET_LOCATION_DETECT_FAIL))
            {
                mmi_ucs2ncpy(
                    (CHAR *)dtv_player_p->info_str_buffer,
                    GetString(STR_ID_DTV_FAIL_TO_DETECT_LOCATION),
                    MMI_DTV_INFO_STR_LENGTH);
            }
            len = mmi_ucs2strlen((CHAR *)dtv_player_p->info_str_buffer);
            mmi_ucs2ncat(
                (CHAR *)dtv_player_p->info_str_buffer,
                GetString(STR_ID_DTV_LEVEL1_CITY_TITLE),
                MMI_DTV_INFO_STR_LENGTH - len);

            break;
            
        case DTV_PLAYER_CITY_LIST_LEVEL_2:
            mmi_dtv_player_gen_separate_string(
                (WCHAR *)GetString(STR_ID_DTV_LEVEL2_CITY_TITLE),
                dtv_player_p->selected_city[DTV_PLAYER_CITY_LIST_LEVEL_1].name,
                NULL);
            break;
            
        case DTV_PLAYER_CITY_LIST_LEVEL_3:
            mmi_ucs2cpy((CHAR*)full_city, (CHAR*)dtv_player_p->selected_city[DTV_PLAYER_CITY_LIST_LEVEL_1].name);
            mmi_ucs2cat((CHAR*)full_city, (CHAR*)L"-");
            mmi_ucs2cat((CHAR*)full_city, (CHAR*)dtv_player_p->selected_city[DTV_PLAYER_CITY_LIST_LEVEL_2].name);
            
            mmi_dtv_player_gen_separate_string(
                (WCHAR *)GetString(STR_ID_DTV_LEVEL2_CITY_TITLE),
                full_city,
                NULL);
            
            break;
        default:
            break;
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_async_city_list
 * DESCRIPTION
 *  mobile tv player get async city list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_dtv_player_get_async_city_list(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, city_idx;
    dtv_player_display_city_struct *city_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < num_item; i ++)
    {
        city_idx = start_indx + i;
        ASSERT(city_idx < dtv_player_p->num_display_citys);
        city_ptr =  &dtv_player_p->display_city[city_idx];

        mmi_ucs2cpy(
            (CHAR*)menuData[i].item_list[0],
            (CHAR*)city_ptr->name);
    }

    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_highlight_city_hdlr
 * DESCRIPTION
 *  mobile tv player highlight city handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_highlight_city_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Store selected city */
    dtv_player_p->selected_city[dtv_player_p->city_list_type] 
        = dtv_player_p->display_city[idx];    
    
    /* Update lsk handler */
    if (dtv_player_p->city_list_type == DTV_PLAYER_CITY_LIST_RECOMMEND)
    {
        if (idx == 0)
        {
            SetLeftSoftkeyFunction(mmi_dtv_player_entry_city_list_level_1_screen, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(mmi_dtv_player_entry_city_list_level_1_screen, KEY_EVENT_UP);
        }
        else
        {
            SetLeftSoftkeyFunction(mmi_dtv_player_city_select_hdlr, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(mmi_dtv_player_city_select_hdlr, KEY_EVENT_UP);
        }
    }    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_query_display_city_list
 * DESCRIPTION
 *  The function is to query display city list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_query_display_city_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    mbbms_sg_query_city_list_struct *city_p = NULL;
    mdi_mtv_query_struct query = {0};
    dtv_player_display_city_struct *dst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dtv_player_p->num_display_citys = 0;

    if (dtv_player_p->city_list_type == DTV_PLAYER_CITY_LIST_LEVEL_1)
    {
        query.id = MTV_ESG_INVALID_SID;
    }
    else if (dtv_player_p->city_list_type == DTV_PLAYER_CITY_LIST_LEVEL_2 ||
             dtv_player_p->city_list_type == DTV_PLAYER_CITY_LIST_LEVEL_3)
    {
        query.id = dtv_player_p->selected_city[dtv_player_p->city_list_type - 1].id;
    }
    else
    {
        ASSERT(0);
    }

    query.query_num = MMI_DTV_MAX_DISPLAY_CITY;
    ret = mdi_mtv_esg_query(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_CITY_LIST, &query);

    if (ret != MDI_RES_MTV_SUCCEED)
    {
        /* handle error case */
        return;
    }

    while(dtv_player_p->num_display_citys < MMI_DTV_MAX_DISPLAY_CITY)
    {
        city_p = NULL;
        ret = mdi_mtv_esg_get_result(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_CITY_LIST, (void **)&city_p);
        if (city_p == NULL)
        {
            break;
        }

        while (city_p != NULL)
        {
            dst = &dtv_player_p->display_city[dtv_player_p->num_display_citys];
            dst->id = city_p->city_id;
            mmi_ucs2ncpy((CHAR*)dst->name, (CHAR*)city_p->city_name, MMI_DTV_CITY_STR_LEN);

            dtv_player_p->num_display_citys ++;
            city_p = city_p->next_p;

            /* Over the limitation */
            if (dtv_player_p->num_display_citys >= MMI_DTV_MAX_DISPLAY_CITY)
            {
                break;
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_query_display_city_num
 * DESCRIPTION
 *  The function is to query display city num
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_dtv_player_query_display_city_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    mdi_mtv_query_struct query = {0};
    mtv_esg_query_record_count *count_ptr = NULL;
    U32 city_num = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    query.id = dtv_player_p->selected_city[dtv_player_p->city_list_type].id;

    ret = mdi_mtv_esg_query(
           dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_CITY_LIST_COUNT, &query);

    if (ret != MDI_RES_MTV_SUCCEED)
    {
        /* handle error case */
        return city_num;
    }


    ret = mdi_mtv_esg_get_result(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_CITY_LIST_COUNT, (void **)&count_ptr);

    if (count_ptr != NULL)
    {
        city_num = count_ptr->number;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL1, city_num, __LINE__);
    
    return city_num;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_recommend_city_list
 * DESCRIPTION
 *  The function is to get recommend city list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_get_recommend_city_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* "list all city" */
    mmi_ucs2ncpy(
        (CHAR *)dtv_player_p->display_city[0].name,
        (CHAR *)GetString(STR_ID_DTV_LIST_ALL_CITY),
        MMI_DTV_CITY_STR_LEN);

    /* recommended city list */
    for (idx = 0;
         idx < dtv_player_p->num_recommend_city && idx + 1 < MMI_DTV_MAX_DISPLAY_CITY;
         idx ++)
    {
        mmi_ucs2ncpy(
            (CHAR *)dtv_player_p->display_city[idx + 1].name,
            (CHAR *)dtv_player_p->recommend_city[idx].name,
            MMI_DTV_CITY_STR_LEN);
    }

    dtv_player_p->num_display_citys = idx + 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_exit_city_list_screen
 * DESCRIPTION
 *  mobile tv player exit city list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_exit_city_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dtv_player_p->display_city != NULL)
    {
    #ifdef __COSMOS_MMI_PACKAGE__
        applib_asm_free_r(GRP_ID_DTV_PLAYER, (void *)dtv_player_p->display_city);
    #else /* __COSMOS_MMI_PACKAGE__ */    
        mmi_frm_scrmem_free((void*)dtv_player_p->display_city);
    #endif  /* __COSMOS_MMI_PACKAGE__ */       

        dtv_player_p->display_city = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_city_list_screen_leave_proc
 * DESCRIPTION
 *  This function is the callback funcion for deleting idle notify screen
 * PARAMETERS
 *  p
 * RETURNS
 *  U8
 *****************************************************************************/
mmi_ret mmi_dtv_player_city_list_screen_leave_proc(mmi_event_struct *para)
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
            break;
        }
        default:
            break;
    }
    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_is_city_list_screen_inited
 * DESCRIPTION
 *  mobile tv player is city list screen inited
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_is_city_list_screen_inited(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (dtv_player_p->city_list_type == DTV_PLAYER_CITY_LIST_RECOMMEND ||
        (dtv_player_p->city_list_type == DTV_PLAYER_CITY_LIST_LEVEL_1 &&
         !mmi_frm_scrn_is_present(
            GRP_ID_DTV_PLAYER,
            SCR_ID_DTV_PLAYER_CITY_LIST_RECOMMEND,
            MMI_FRM_NODE_ALL_FLAG)))
    {
        return MMI_TRUE;
    }
    
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_is_city_list_screens_presented
 * DESCRIPTION
 *  mobile tv player is city list screen presented
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_is_city_screen_presented(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_is_present(
            GRP_ID_DTV_PLAYER,
            SCR_ID_DTV_PLAYER_CITY_LIST_RECOMMEND,
            MMI_FRM_NODE_ALL_FLAG) ||
        mmi_frm_scrn_is_present(
            GRP_ID_DTV_PLAYER,
            SCR_ID_DTV_PLAYER_CITY_LIST_LEVEL_1,
            MMI_FRM_NODE_ALL_FLAG) ||
        mmi_frm_scrn_is_present(
            GRP_ID_DTV_PLAYER,
            SCR_ID_DTV_PLAYER_CITY_LIST_LEVEL_2,
            MMI_FRM_NODE_ALL_FLAG) ||
        mmi_frm_scrn_is_present(
            GRP_ID_DTV_PLAYER,
            SCR_ID_DTV_PLAYER_CITY_LIST_LEVEL_3,
            MMI_FRM_NODE_ALL_FLAG))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_city_list_screen
 * DESCRIPTION
 *  mobile tv player entry city list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_city_list_screen(dtv_player_city_list_type_enum city_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 error = 0;
	S32 *check_box_ptr = NULL;
    MMI_BOOL is_inited;
    U16 csk_id;
    FuncPtr entry_func[DTV_PLAYER_CITY_LIST_NUM] =
    {
        mmi_dtv_player_entry_city_list_recommend_screen,
        mmi_dtv_player_entry_city_list_level_1_screen,
        mmi_dtv_player_entry_city_list_level_2_screen,
        mmi_dtv_player_entry_city_list_level_3_screen
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_scrn_enter(
            GRP_ID_DTV_PLAYER,
            SCR_ID_DTV_PLAYER_CITY_LIST_RECOMMEND + city_type,
            mmi_dtv_player_exit_city_list_screen,
            entry_func[city_type],
            MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    dtv_player_p->city_list_type = city_type;

    /* suspend background play */
    mdi_audio_suspend_background_play();

    RegisterHighlightHandler(mmi_dtv_player_highlight_city_hdlr);


    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    mmi_frm_scrn_set_leave_proc(
        GRP_ID_DTV_PLAYER,
        SCR_ID_DTV_PLAYER_CITY_LIST_RECOMMEND + city_type,
        mmi_dtv_player_city_list_screen_leave_proc);

    is_inited = mmi_dtv_player_is_city_list_screen_inited();

    /* Title */
    mmi_dtv_player_config_city_list_title(is_inited); 

    /* Initialize if_rememeber_location */
    if (is_inited && guiBuffer == NULL)
    {        
        dtv_player_p->if_rememeber_location = MMI_FALSE;               
    }
    
    /* If from setting screen. Don't display check box: follow UI spec */    
    if (mmi_frm_group_is_present(GRP_ID_DTV_PLAYER_CL_SETTING))
    {
        check_box_ptr = NULL;        
    } 
    else
    {
        check_box_ptr = &dtv_player_p->if_rememeber_location;
    }   

    /* Allocate city list buffer */
    ASSERT(sizeof(dtv_player_display_city_struct) <= MMI_DTV_MAX_DISPLAY_CITY_STRUCTURE_SIZE);

#ifdef __COSMOS_MMI_PACKAGE__
        
    dtv_player_p->display_city =
                    (dtv_player_display_city_struct *) applib_asm_alloc_nc_r(GRP_ID_DTV_PLAYER, MMI_DTV_MAX_DISPLAY_CITY * sizeof(dtv_player_display_city_struct));
#else /* __COSMOS_MMI_PACKAGE__ */

    dtv_player_p->display_city = (dtv_player_display_city_struct*) mmi_frm_scrmem_alloc(MMI_DTV_MAX_DISPLAY_CITY * sizeof(dtv_player_display_city_struct));
#endif

    ASSERT(dtv_player_p->display_city != NULL);
    memset(dtv_player_p->display_city, 0, MMI_DTV_MAX_DISPLAY_CITY * sizeof(dtv_player_display_city_struct));

    /* Get display city list */
    if (city_type == DTV_PLAYER_CITY_LIST_RECOMMEND)
    {
        mmi_dtv_player_get_recommend_city_list();
    }
    else
    {
        mmi_dtv_player_query_display_city_list();
    }

    if (is_inited)
    {        
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        csk_id = 0;
    }
    else
    {    
        /* FTE project doesn't have CSK. */
     #ifndef __MMI_FTE_SUPPORT__    
        EnableCenterSoftkey(STR_ID_DTV_LAST_STEP, 0);
     #endif
        csk_id = STR_ID_DTV_LAST_STEP;
    }
    
    wgui_cat1048_show(
        (CHAR *)dtv_player_p->info_str_buffer,
        (PU8)GetImage(DTV_PLAYER_MENU_ICON),
        STR_GLOBAL_OK,
        csk_id,
        STR_GLOBAL_CANCEL,
        GetString(STR_ID_DTV_REMEMBER_LOCATION),
        check_box_ptr,
        dtv_player_p->num_display_citys,
        mmi_dtv_player_get_async_city_list,
        NULL,
        0,
        guiBuffer,
        &error);
    
    SetRightSoftkeyFunction(mmi_dtv_player_close_all_city_list_screen, KEY_EVENT_UP);
    
    if (dtv_player_p->city_list_type == DTV_PLAYER_CITY_LIST_LEVEL_1)
    {   
        SetLeftSoftkeyFunction(mmi_dtv_player_entry_next_level_screen, KEY_EVENT_UP);
        if (is_inited)
        {
            SetCenterSoftkeyFunction(mmi_dtv_player_entry_next_level_screen, KEY_EVENT_UP);
        }
        else
        {
        #ifndef __MMI_FTE_SUPPORT__     
            /* Last step */
            SetCenterSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        #else
            /* Category screen will register CSK handler in FTE project */
            wgui_cat1048_register_ckey_func(mmi_frm_scrn_close_active_id);
        #endif
        }        
    }
    else if (dtv_player_p->city_list_type == DTV_PLAYER_CITY_LIST_LEVEL_2)
    {        
        SetLeftSoftkeyFunction(mmi_dtv_player_entry_next_level_screen, KEY_EVENT_UP);        
    #ifndef __MMI_FTE_SUPPORT__     
        /* Last step */
        SetCenterSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    #else
        wgui_cat1048_register_ckey_func(mmi_frm_scrn_close_active_id);
    #endif        
    }
    else if (dtv_player_p->city_list_type == DTV_PLAYER_CITY_LIST_LEVEL_3)
    {        
        SetLeftSoftkeyFunction(mmi_dtv_player_city_select_hdlr, KEY_EVENT_UP);        
    #ifndef __MMI_FTE_SUPPORT__     
        /* Last step */
        SetCenterSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    #else
        wgui_cat1048_register_ckey_func(mmi_frm_scrn_close_active_id);
    #endif       
    }    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_city_list_xxx_screen
 * DESCRIPTION
 *  mobile tv player entry city list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_city_list_recommend_screen(void)
{
    mmi_dtv_player_entry_city_list_screen(DTV_PLAYER_CITY_LIST_RECOMMEND);
}
void mmi_dtv_player_entry_city_list_level_1_screen(void)
{
    mmi_dtv_player_entry_city_list_screen(DTV_PLAYER_CITY_LIST_LEVEL_1);
}
void mmi_dtv_player_entry_city_list_level_2_screen(void)
{
    mmi_dtv_player_entry_city_list_screen(DTV_PLAYER_CITY_LIST_LEVEL_2);
}
void mmi_dtv_player_entry_city_list_level_3_screen(void)
{
    mmi_dtv_player_entry_city_list_screen(DTV_PLAYER_CITY_LIST_LEVEL_3);
}
#endif /* __MBBMS_CITY_LIST__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_finalize_mbbms_init
 * DESCRIPTION
 *  service update handler
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_finalize_mbbms_init(S32 param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    applib_time_struct cur_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((dtv_player_p->ca_state == MMI_DTV_CA_STATE_MBBMS_INIT)
		|| (MMI_FALSE == g_mtv_mts_command))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
			      MMI_TRC_DTV_VAL1, 
			      dtv_player_p->ca_state,
			      __LINE__);
        /* Update MED service list: Must before Update MMI list */
        mdi_mtv_update_service_guide(dtv_player_p->mtv_handle);
        /* Update MMI service list */
        mmi_dtv_player_query_access_list();
		
        mmi_dtv_player_assign_service_number();

        /* Update MMI favorite service list */
        mmi_dtv_player_assign_favorite_service_info();
        /* Update MMI service name & scheulde name */
        mmi_dtv_player_update_esg();
		
		if (0xFF == param)
		{
			return;
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
		#endif

        /* Update reminder time */
        mmi_dtv_player_get_current_system_time(&cur_time);
        mdi_mtv_purify_program_reminder(dtv_player_p->mtv_handle, &cur_time);
        mmi_dtv_player_update_alarm();

        mdi_mtv_add_favorite(dtv_player_p->mtv_handle, 
			                 MDI_MTV_FAVO_LOCAL_PURCHASE_ITEM, 
			                 0, 
			                 NULL);
    #ifdef __MMI_CMMB_PREVIEW_PIC_SUPPORT__
        /* Don't let preview data slow down the first encypted channel playing  */
        gui_start_timer(10000, mmi_dtv_player_query_preview_data);
    #endif
        /* Update EB */
        mmi_dtv_player_check_eb_list();
    }    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_subscriptoin_update_result_hdlr
 * DESCRIPTION
 *  service update handler
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_subscriptoin_update_result_hdlr(S32 param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen = mmi_frm_scrn_get_active_id();
#ifdef __MMI_DTV_UPDATE_SUBSCRIPTION_TABLE__
    dtv_player_service_info_struct *info_ptr;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DTV_UPDATE_SUBSCRIPTION_TABLE__
    /* start service */
    if (KERNEL_STATE_IN(DTV_KERNEL_SUB_UPDATING))
    {
        KERNEL_ENTER_STATE(DTV_KERNEL_OPENED);
        mmi_dtv_player_get_service_flag();
        if (active_screen == SCR_ID_DTV_PLAYER_APP)
        {
            info_ptr = &dtv_player_p->services[dtv_player_p->setting.selected_channel];
            if (info_ptr->service_flags & MEDIA_MTV_SERVICE_UNSUBSCRIBED)
            {
                mmi_dtv_player_display_confirm(STR_ID_DTV_PLAYER_ENTER_MANAGE_ORDER_CONFIRM);
            }
            else
            {
                mmi_dtv_player_init_service_in_app_screen(MMI_FALSE);
            }
        }
        return;
    }
#endif /* __MMI_DTV_UPDATE_SUBSCRIPTION_TABLE__ */

    mmi_dtv_player_finalize_mbbms_init(param);
    
    if (param < 0)
    {
    	mmi_dtv_player_get_service_flag();
        dtv_player_p->ca_state = MMI_DTV_CA_STATE_MBBMS_READY;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_CA_STATE, MMI_DTV_CA_STATE_MBBMS_FAIL);
  
	  if (100 == dtv_player_p->scan_progress)	
	  {
		  mmi_dtv_player_display_mbbms_init_fail();
	  }
    }
    else
    {
        dtv_player_p->ca_state = MMI_DTV_CA_STATE_MBBMS_READY;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_CA_STATE, MMI_DTV_CA_STATE_MBBMS_READY);
        mmi_dtv_player_get_service_flag();
	#ifdef __MBBMS_UPGRADE__
        if (dtv_player_p->upgrade_type != MDI_RES_MTV_UPGRADE_NONE)
        {
            mmi_dtv_player_display_upgrade_confirm();
        }        
        else 
	#endif /* __MBBMS_UPGRADE__ */
        {    
            mdi_mtv_get_mbbms_description(dtv_player_p->mtv_handle,
			                              0,
			                              (WCHAR * )dtv_player_p->info_str_buffer,
			                              MMI_DTV_INFO_STR_LENGTH);
			if (0 < mmi_ucs2strlen((CHAR *)dtv_player_p->info_str_buffer))
			{
				mmi_dtv_player_enter_info_confirm_screen();
			}
			else
			{
				mmi_dtv_player_display_popup(STR_ID_DTV_PLAYER_SUBSCRIPTION_TABLE_UPDATED,
                                             MMI_EVENT_SUCCESS);
			}
        }
    }
    /* For MTS */
    if (g_mtv_mts_command)
    {
        KERNEL_ENTER_STATE(DTV_KERNEL_OPENED);
        mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_PROCESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_sg_update_result_hdlr
 * DESCRIPTION
 *  service update handler
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_sg_update_result_hdlr(S32 param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (param < 0)
    {
        if (!KERNEL_STATE_IN(DTV_KERNEL_SCANNING))
        {
            /* if state is READY, don't let SG update fail be the reason to update again */
            if (dtv_player_p->ca_state != MMI_DTV_CA_STATE_MBBMS_READY)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
					      MMI_TRC_DTV_CA_STATE, 
					      MMI_DTV_CA_STATE_MBBMS_FAIL);
            }

            /* Spec said popup the string */
            mmi_dtv_player_display_mbbms_init_fail();
        }
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_mbbms_update_hdlr
 * DESCRIPTION
 *  service update handler
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_mbbms_update_hdlr(U32 event_id, S32 param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen = mmi_frm_scrn_get_active_id();
    S16 error;
    mmi_event_notify_enum popup_type;
    MMI_ID_TYPE string_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (event_id)
    {
#ifdef __MMI_MBBMS_MTS_SUPPORT__
    case MDI_MTV_SERVICE_GBA_RET:

        if (param < 0)
        {
            dtv_player_p->ca_state = MMI_DTV_CA_STATE_MBBMS_FAIL;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
				      MMI_TRC_DTV_CA_STATE, 
				      MMI_DTV_CA_STATE_MBBMS_FAIL);

            /* reset IMSI when GBA fails */
            kal_mem_cpy(dtv_player_p->setting.imsi, 0, SRV_MAX_IMSI_LEN);
            WriteRecord(NVRAM_EF_DTV_PLAYER_SETTING_LID, 1, 
				        (void*)&dtv_player_p->setting, 
				        NVRAM_EF_DTV_PLAYER_SETTING_SIZE, 
				        &error);

            /* Spec said popup the string */
            mmi_dtv_player_display_mbbms_init_fail();
			if (MMI_FALSE == g_mtv_mts_command)
			{				
				mmi_dtv_player_finalize_mbbms_init(0xFF);
			}
        }

        if (g_mtv_mts_command)
        {
            if (param == MDI_RES_MTV_SUCCEED)
            {
                mmi_dtv_player_display_popup(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS);
            }
            KERNEL_ENTER_STATE(DTV_KERNEL_OPENED);
            mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_PROCESS);
        }
        break;
    case MDI_MTV_SERVICE_MSK_RETRIEVE_DONE:

	if(param == MDI_RES_MTV_ERR_MSK_RETRIEVE_FAIL)
        {
            /* Stop player and service: make LCD turn off */
            if (!PLAYER_STATE_IN(DTV_PLAYER_STOPPED))
            {
                mmi_dtv_player_player_enter_state(DTV_PLAYER_STOPPED);
            }
            if (!KERNEL_STATE_IN(DTV_KERNEL_OPENED))
            {
                mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);				
            }
        }
		
        if (g_mtv_mts_command)
        {
            if (param != MDI_RES_MTV_SUCCEED)
            {
                mmi_dtv_player_display_failure_popup(param);
            }
            else
            {
                mmi_dtv_player_display_popup(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS);
            }

            KERNEL_ENTER_STATE(DTV_KERNEL_OPENED);
            mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_PROCESS);
        }
        else
        {
            if (param != MDI_RES_MTV_SUCCEED &&
                active_screen == SCR_ID_DTV_PLAYER_APP)
            {
                /* If player plays normally, don't notify user */
                if ((param != MDI_RES_MTV_ERR_MSK_RETRIEVE_FAIL) && 
                   mmi_dtv_player_is_flag_set(DTV_PLAYER_ACCESS_DENIED) != MMI_TRUE &&
                    !IsMyTimerExist(DTV_PLAYER_DISPLAY_ACCESS_DENIED_TIMER))
                {
                	kal_prompt_trace(MOD_MMI, "Yaling test 1");
                    return;
                }
				kal_prompt_trace(MOD_MMI, "Yaling test 2");

				if ((MDI_RES_MTV_ERR_MSK_RETRIEVE_FAIL == param)
					&& (SRV_NW_INFO_SA_FULL_SERVICE != srv_nw_info_get_service_availability(MMI_SIM1)))
			    {
				   string_id = STR_ID_DTV_PLAYER_FAIL_TO_UPDATE_SUBSCRIPTION;
			    }
			    else
			    {
			    	string_id = mdi_util_get_mdi_error_info(param, &popup_type);
                	if (string_id == STR_GLOBAL_ERROR)
                	{
                   		string_id = STR_ID_DTV_PLAYER_NOTIFY_ACCESS_DENIED;
                	}
			    }
                mmi_dtv_player_set_hint(
                    (CHAR *) GetString(string_id),
                    (CHAR *) NULL,
                    MMI_DTV_PLAYER_HINT_POPUP_NO_FADE,
                    MMI_TRUE);
                mmi_dtv_player_draw_osd();
                mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
            }
        }
        break;
#endif /* __MMI_MBBMS_MTS_SUPPORT__ */

    default:
        break;
    }

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
void mmi_dtv_player_display_failure_confirm(MDI_RESULT ret)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_event_notify_enum popup_type;
	MMI_ID_TYPE string_id;
	mdi_mtv_purchase_desc_struct * notify = NULL;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	/* Display confirm */
	notify = (mdi_mtv_purchase_desc_struct * )ret;
	kal_mem_set(dtv_player_p->info_str_buffer, 
				0, 
				sizeof(dtv_player_p->info_str_buffer));

	if (0 == mmi_ucs2strlen((CHAR *)notify->desc))
	{
		string_id = mdi_util_get_mdi_error_info(notify->ret, &popup_type);
		mmi_ucs2ncpy((CHAR *)dtv_player_p->info_str_buffer,
					 GetString(string_id),
					 MMI_DTV_INFO_STR_LENGTH);

	}
	else
	{
		mmi_ucs2ncpy((CHAR *)dtv_player_p->info_str_buffer,
					 (CHAR *)notify->desc,
					 MMI_DTV_INFO_STR_LENGTH);
	}
	mmi_dtv_player_enter_info_confirm_screen();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_purchase_done_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_purchase_done_hdlr(U32 event_id, S32 param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U16 active_screen = mmi_frm_scrn_get_active_id();
	mdi_mtv_purchase_desc_struct * notify = (mdi_mtv_purchase_desc_struct * )param;
	WCHAR *str = NULL;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if (event_id == MDI_MTV_SERVICE_SUBSCRIBE_DONE &&
		dtv_player_p->process_type == DTV_PLAYER_PROCESS_TYPE_SUBSCRIBE)
	{
		str = (WCHAR *) GetString(STR_ID_DTV_PLAYER_SUBSCRIBE_SUCCEED);
	}
	else if (event_id == MDI_MTV_SERVICE_UNSUBSCRIBE_DONE &&
			 dtv_player_p->process_type == DTV_PLAYER_PROCESS_TYPE_UNSUBSCRIBE)
	{
		str = (WCHAR *) GetString(STR_ID_DTV_PLAYER_UNSUBSCRIBE_SUCCEED);
	}
	else
	{
		ASSERT(0);
	}

	/* Only display pop up on the process screen */
	if (active_screen == SCR_ID_DTV_PLAYER_PROCESS)
	{
		if (MDI_RES_MTV_SUCCEED == notify->ret) 
		{
			if (0 == mmi_ucs2strlen((CHAR *)notify->desc))
			{
				mmi_dtv_player_gen_separate_string(str, 
												   (WCHAR*)dtv_player_p->selected_order.name, 
												   NULL);
			}
			else
			{
				mmi_ucs2ncpy((CHAR *)dtv_player_p->info_str_buffer,
					 		 (CHAR *)notify->desc,
					 		 MMI_DTV_INFO_STR_LENGTH);
			}
			mmi_dtv_player_enter_info_confirm_screen();
		}
		else
		{
			mmi_dtv_player_display_failure_confirm(param);
		}
	}

	KERNEL_ENTER_STATE(DTV_KERNEL_OPENED);

	if (notify->ret == MDI_RES_MTV_SUCCEED)
	{
		/* Update flag */
		mmi_dtv_player_get_service_flag();
	}
	/* delete subscribing screens */
	mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_MANAGE_ORDER);
	mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_PROCESS);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_account_inquiry_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 void mmi_dtv_player_account_inquiry_hdlr(mdi_mtv_account_inquiry_struct *account, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 idx = 0;
    dtv_player_account_struct *acc_p;
    mdi_mtv_account_item_struct *item_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_scrn_is_present(
            GRP_ID_DTV_PLAYER,
            SCR_ID_DTV_PLAYER_PROCESS,
            MMI_FRM_NODE_ALL_FLAG))
    {
        return;
    }

    ASSERT(dtv_player_p->process_type == DTV_PLAYER_PROCESS_TYPE_ACCOUNT_INQUIRY);
    ASSERT(dtv_player_p->account != NULL);

    for (idx = 0;
         idx < account->purchase_count && dtv_player_p->num_accounts < MMI_DTV_MAX_ACCOUNT;
         idx ++)
    {
        acc_p = &dtv_player_p->account[dtv_player_p->num_accounts];
        item_p = &account->purchase_info[idx];

        strncpy(acc_p->id, (const CHAR *)item_p->fragment_id, MBBMS_SG_ID_LEN);
        strncpy(acc_p->gid,(const CHAR *)item_p->purchaseitem_id, MBBMS_SG_ID_LEN);
        mmi_ucs2ncpy((CHAR*)acc_p->name, (CHAR*)item_p->purchaseitem_name, MMI_DTV_NAME_STR_LENGTH);

        acc_p->type = item_p->type;
        acc_p->price = item_p->price;
        acc_p->period = item_p->period;

        dtv_player_p->num_accounts ++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_account_inquiry_done_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_account_inquiry_done_hdlr(S32 param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(dtv_player_p->process_type == DTV_PLAYER_PROCESS_TYPE_ACCOUNT_INQUIRY);

    KERNEL_ENTER_STATE(DTV_KERNEL_OPENED);

    /* Only display pop up on the process screen */
    if (param == MDI_RES_MTV_SUCCEED)
    {
        mmi_dtv_player_entry_manage_order_screen();
    }
    else
    {
        mmi_dtv_player_display_failure_popup(param);
    }


    /* delete account inquiry screens */
    mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_PROCESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_exit_order_detail_screen
 * DESCRIPTION
 *  mobile tv player exit order detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_exit_order_detail_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_dtv_player_free_detail_screen_memory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_query_purchase_item
 * DESCRIPTION
 *  The function is to query order details
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_query_purchase_item(MMI_BOOL local)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_mtv_query_struct query = {0};
    MDI_RESULT ret;
    MMI_BOOL found = MMI_FALSE;
    esg_query_type_enum type;
    mbbms_sg_query_purchase_item_struct *item = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    strcpy(query.rid, dtv_player_p->selected_order.id);

    if (local)
    {
        type = ESG_QUERY_PURCHASE_ITEM_BY_RID_CURRENT_PLACE;
    }
    else
    {
        type = ESG_QUERY_PURCHASE_ITEM_BY_RID;
    }

    ret = mdi_mtv_esg_query(dtv_player_p->mtv_handle, 
		                    MEDIA_MTV_ESG_SOURCE_DEFAULT, 
		                    type, 
		                    &query);
    if (ret != MDI_RES_MTV_SUCCEED)
    {
        /* handle error case */
        return found;
    }

    while (1)
    {
        mdi_mtv_esg_get_result(dtv_player_p->mtv_handle, 
			                   MEDIA_MTV_ESG_SOURCE_DEFAULT, 
			                   type, 
			                   (void **)&item);
        if (item == NULL)
        {
            break;
        }
        while (item != NULL)
        {
            found = MMI_TRUE;
            /* Put channel name */
            mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR*)(item->service_name));
            mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR*)L"\n");
            item = item->next_p;
        }
    }
    return found;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_assign_order_details
 * DESCRIPTION
 *  The function is to assign order details
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_assign_order_description(MMI_BOOL local)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_mtv_query_struct query = {0};
    MDI_RESULT ret;
    esg_query_type_enum type;
    mbbms_sg_query_purchase_item_struct *item = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    strcpy(query.rid, dtv_player_p->selected_order.id);

    if (local)
    {
        type = ESG_QUERY_PURCHASE_ITEM_BY_RID_CURRENT_PLACE;
    }
    else
    {
        type = ESG_QUERY_PURCHASE_ITEM_BY_RID;
    }

    ret = mdi_mtv_esg_query(dtv_player_p->mtv_handle, 
		                    MEDIA_MTV_ESG_SOURCE_DEFAULT, 
		                    type, 
		                    &query);
    if (ret != MDI_RES_MTV_SUCCEED)
    {
        /* handle error case */
        return;
    }


    mdi_mtv_esg_get_result(dtv_player_p->mtv_handle, 
		                   MEDIA_MTV_ESG_SOURCE_DEFAULT, 
		                   type, 
		                   (void **)&item);
    if (item != NULL)
    {			
        mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR*)(item->description));
	}
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_query_order_details
 * DESCRIPTION
 *  The function is to query order details
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_query_order_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = 0;
    U8 type;
    wgui_color_buffer_writer_struct writer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* non-local order warning */
    if (MMI_FALSE == dtv_player_p->selected_order.local)
    {
        /* Set blue color */
        wgui_color_buffer_create_writer(&writer, 
                                        (U8*)dtv_player_p->detail_buf, 
                                        MMI_DTV_PLAYER_DETAIL_BUF_SIZE);		
        wgui_color_buffer_write_char(&writer, GUI_INPUT_COLOR_BLUE);

        mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_NON_LOCAL_ORDER));
        mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");

        /* Reset blue color */
        wgui_color_buffer_create_writer(&writer, 
                                        (U8*)dtv_player_p->detail_buf, 
                                        MMI_DTV_PLAYER_DETAIL_BUF_SIZE);
        wgui_color_buffer_write_char(&writer, GUI_INPUT_MARKER_RESET_ALL);
    }
	else
	{
    	mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_INCLUDE_CHANNELS));
    	mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");
        mmi_dtv_player_query_purchase_item(MMI_TRUE);
	}
	
    /* Type */
    type = dtv_player_p->selected_order.type;
    /* program by once, channel & order by one month */
    if (type == 128 || type == 129 || type == 130)
    {
        mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_TIME));
    }
    /* order by months */
    else if (type == 131)
    {
        mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_ORDER_VALID_DURATION));
    }

    len = mmi_ucs2strlen(dtv_player_p->detail_buf);
    mmi_dtv_player_get_order_type_string(
        &dtv_player_p->selected_order, (WCHAR*)&dtv_player_p->detail_buf[len<<1]);
    mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");

    /* Price */
    if (type == 131)
    {
        mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_TOTAL_PRICE));
    }
    else
    {
        mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_PRICE));
    }

    len = mmi_ucs2strlen(dtv_player_p->detail_buf);
    mmi_dtv_player_get_order_price_string(&dtv_player_p->selected_order, 
		                                  (WCHAR*)&dtv_player_p->detail_buf[len<<1]);
	
    mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");

	mmi_dtv_player_assign_order_description(dtv_player_p->selected_order.local);
	
    ASSERT(mmi_ucs2strlen((CHAR *) dtv_player_p->detail_buf) * 2 + 2 <= MMI_DTV_PLAYER_DETAIL_BUF_SIZE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_order_detail_screen
 * DESCRIPTION
 *  mobile tv player entry order detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_order_detail_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_PROGRAM_DETAIL,
                mmi_dtv_player_exit_order_detail_screen,
                mmi_dtv_player_entry_order_detail_screen,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    /* suspend background play */
    mdi_audio_suspend_background_play();

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();


    /* Allocate detail buffer */
    mmi_dtv_player_alloc_detail_screen_memory();

    mmi_dtv_player_query_order_details();

    wgui_cat3005_show(
        (UI_string_type)GetString(STR_ID_DTV_PLAYER_ORDER_DETAILS),
        (PU8)GetImage(DTV_PLAYER_MENU_ICON),
        0,
        0,
        (UI_string_type)GetString(STR_GLOBAL_BACK),
        (PU8)GetImage(IMG_GLOBAL_BACK),
        (PU8) dtv_player_p->detail_buf,
        mmi_ucs2strlen((CHAR *) dtv_player_p->detail_buf),
        guiBuffer);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_process_screen_leave_proc
 * DESCRIPTION
 *  This function is the callback funcion for deleting idle notify screen
 * PARAMETERS
 *  p
 * RETURNS
 *  U8
 *****************************************************************************/
 mmi_ret mmi_dtv_player_process_screen_leave_proc(mmi_event_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mtv_mts_command = MMI_FALSE;
    /* Don't release ASM because manage order screen needs the memory. */
    if (mmi_frm_scrn_is_present(
            GRP_ID_DTV_PLAYER,
            SCR_ID_DTV_PLAYER_MANAGE_ORDER,
            MMI_FRM_NODE_ALL_FLAG))
    {
        return MMI_RET_ALLOW_CLOSE;
    }

    switch (para->evt_id)
    {
        case EVT_ID_SCRN_GOBACK:
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        {
            if (dtv_player_p->account != NULL)
            {
                kal_adm_free(dtv_player_p->adm_pool_id,(void *) dtv_player_p->account);
                dtv_player_p->account = NULL;
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
 *  mmi_dtv_player_enter_process_screen
 * DESCRIPTION
 *  enter subscribing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_enter_process_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    MDI_RESULT ret;
    PU8 str_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_PROCESS,
                NULL,
                mmi_dtv_player_enter_process_screen,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    /* suspend background play */
    mdi_audio_suspend_background_play();

    mmi_frm_scrn_set_leave_proc(
        GRP_ID_DTV_PLAYER,
        SCR_ID_DTV_PLAYER_PROCESS,
        mmi_dtv_player_process_screen_leave_proc);


    switch (dtv_player_p->process_type)
    {
        case DTV_PLAYER_PROCESS_TYPE_SUBSCRIBE:

            str_id = (PU8)GetString(STR_ID_DTV_PLAYER_SUBSCRIBING_PLEASE_WAIT);
            break;
        case DTV_PLAYER_PROCESS_TYPE_UNSUBSCRIBE:

            str_id = (PU8)GetString(STR_ID_DTV_PLAYER_UNSUBSCRIBING_PLEASE_WAIT);
            break;
        case DTV_PLAYER_PROCESS_TYPE_ACCOUNT_INQUIRY:
            /* Allocate memory */
            ASSERT(sizeof(dtv_player_account_struct) <= MMI_DTV_MAX_ACCOUNT_STRUCTURE_SIZE);
            if (dtv_player_p->account == NULL)
            {
			#ifdef __MBBMS_CITY_LIST__
                mmi_dtv_player_free_city_mem();
			#endif /* __MBBMS_CITY_LIST__ */
                dtv_player_p->num_accounts = 0;
                dtv_player_p->account = (dtv_player_account_struct*) kal_adm_alloc(
                                            dtv_player_p->adm_pool_id,
                                            MMI_DTV_MAX_ACCOUNT * sizeof(dtv_player_account_struct));
                ASSERT(dtv_player_p->account != NULL);
                memset(dtv_player_p->account, 0, MMI_DTV_MAX_ACCOUNT * sizeof(dtv_player_account_struct));
            }
            str_id = (PU8)GetString(STR_ID_DTV_PLAYER_NOTIFY_UPDATING);
            break;
	#ifdef __MBBMS_UPGRADE__
        case DTV_PLAYER_PROCESS_TYPE_UPGRADE_QUERY:
			{
            	str_id = (PU8)GetString(STR_GLOBAL_PLEASE_WAIT);
            	break;
        	}
	#endif /* __MBBMS_UPGRADE__ */
	#ifdef __MBBMS_CITY_LIST__
        case DTV_PLAYER_PROCESS_TYPE_AREA_SET_RETRIEVE:
            {
            	mmi_dtv_player_allocate_city_mem();
            	str_id = (PU8)GetString(STR_GLOBAL_PLEASE_WAIT);
            	break;
        	}
	#endif /* __MBBMS_CITY_LIST__ */
	#ifdef __MBBMS_INTER__
        case DTV_PLAYER_PROCESS_TYPE_INTERACTIVITY_RETRIEVE:
            {
				str_id = (PU8)GetString(STR_GLOBAL_PLEASE_WAIT);
            	break;   
        	}
	#endif /* __MBBMS_INTER__ */
    #ifdef __MMI_MBBMS_MTS_SUPPORT__
        case DTV_PLAYER_PROCESS_TYPE_SUBSCRIPTION_UPDATE:
        case DTV_PLAYER_PROCESS_TYPE_GBA:
        case DTV_PLAYER_PROCESS_TYPE_MSK_RETRIEVE:
            str_id = (PU8)GetString(STR_GLOBAL_PLEASE_WAIT);
            break;
    #endif
        default:
            ASSERT(0);
    }
    ShowCategory66Screen(
        STR_ID_DTV_PLAYER_APP_NAME,
        DTV_PLAYER_MENU_ICON,
        STR_ID_DTV_PLAYER_NULL,
        IMG_ID_DTV_PLAYER_NULL,
        STR_ID_DTV_PLAYER_NULL,
        IMG_ID_DTV_PLAYER_NULL,
        str_id,
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    /* clear end key, this action cant be abort */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);

    if (guiBuffer != NULL)
    {
        return;
    }

    ASSERT(guiBuffer == NULL);

    ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_PROCESS);
#ifdef __MBBMS_INTER__
    if (dtv_player_p->process_type == DTV_PLAYER_PROCESS_TYPE_INTERACTIVITY_RETRIEVE)
    {
        if (ret == MDI_RES_MTV_FILE_EXISTED)
        {
            KERNEL_ENTER_STATE(DTV_KERNEL_OPENED);
            mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_PROCESS);
            mmi_dtv_player_entry_content_inter_screen();
            return; /* Don't remove */
        }
    }
#endif /* __MBBMS_INTER__ */
    if (ret != MDI_RES_MTV_SUCCEED)
    {
        mmi_dtv_player_display_popup(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE);

        /* Close subscribing screen */
        mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_PROCESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_pl_screen_leave_proc
 * DESCRIPTION
 *  This function is the callback funcion for deleting idle notify screen
 * PARAMETERS
 *  p
 * RETURNS
 *  U8
 *****************************************************************************/
 mmi_ret mmi_dtv_player_pl_screen_leave_proc(mmi_event_struct *para)
{
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
            if (dtv_player_p->cat1023_his_buf != NULL)
            {
                kal_adm_free(dtv_player_p->adm_pool_id,
					         (void *) dtv_player_p->cat1023_his_buf);
                dtv_player_p->cat1023_his_buf = NULL;
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
 *  mmi_dtv_player_prog_list_get_tab_num
 * DESCRIPTION
 *  mobile tv player get tab num
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_dtv_player_prog_list_get_tab_num(S32 date_index, S32 *tab_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    *tab_count = dtv_player_p->num_services;
    return *tab_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_cat1023_get_tab_text
 * DESCRIPTION
 *  mobile tv player get tab text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_dtv_player_prog_list_get_tab_text(S32 start_index, S32 tab_count, WCHAR **data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for(i = start_index; i < start_index + tab_count; ++i)
	{
		data[i] = (WCHAR*)dtv_player_p->services[i].service_name;
	}

	return tab_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_query_prog_list
 * DESCRIPTION
 *  The function is to query schedule list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_query_prog_list(S32 service_id, applib_time_struct *time, U32 start_idx, U32 query_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    mtv_esg_query_program_struct *prog_ptr = NULL;
    mdi_mtv_query_struct query = {0};
    dtv_player_schedule_info_struct *sche_ptr;
    S32 idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    query.time = time;
    query.id = service_id;
    query.start_idx = start_idx;
    query.query_num = query_num;
    ret = mdi_mtv_esg_query(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_PROGRAM_OF_DAY, &query);

    if (ret != MDI_RES_MTV_SUCCEED)
    {
        /* handle error case */
        return;
    }

    dtv_player_p->sche_start_idx = start_idx;

    while(idx < MMI_DTV_MAX_SCHEDULES)
    {
        prog_ptr = NULL;
        ret = mdi_mtv_esg_get_result(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_PROGRAM_OF_DAY, (void **)&prog_ptr);
        if (prog_ptr == NULL)
        {
            break;
        }

        while (prog_ptr != NULL)
        {
            sche_ptr = &dtv_player_p->schedules[idx];
            sche_ptr->content_id = prog_ptr->ref_id;
            strncpy(sche_ptr->cid, prog_ptr->id, MBBMS_SG_ID_LEN);

            /* ID */
            sche_ptr->service_id = query.id;
            /* Name */
            mmi_ucs2cpy((CHAR*) sche_ptr->name, (CHAR*) prog_ptr->name);

            /* Date */
            mmi_ucs2ncpy((CHAR*)sche_ptr->date, (CHAR*)prog_ptr->start_time, 10);

            /* Time */
            if (mmi_ucs2strlen((CHAR*)prog_ptr->start_time) > 0)
            {
                mmi_ucs2ncpy((CHAR *)sche_ptr->time, (CHAR *)&(prog_ptr->start_time[11]), 5);
            }
            else
            {
                mmi_ucs2ncpy((CHAR *)sche_ptr->time, (CHAR *)L"     ", 5); /* 5 space */
            }
            mmi_ucs2cat((CHAR*)sche_ptr->time, (CHAR*)L"-");
            if (mmi_ucs2strlen((CHAR*)prog_ptr->end_time) > 0)
            {
                mmi_ucs2ncat((CHAR *)sche_ptr->time, (CHAR *)&(prog_ptr->end_time[11]), 5);
            }

            /* In reminder */
            sche_ptr->if_reminder = prog_ptr->in_reminder;
		#ifdef __MBBMS_INTER__
            sche_ptr->has_inter_data = prog_ptr->has_inter_data;
		#endif /* __MBBMS_INTER__ */
            idx ++;
            prog_ptr = prog_ptr->next_p;

            /* Over the limitation */
            if (idx >= MMI_DTV_MAX_SCHEDULES)
            {
                break;
            }
        }
    }

    dtv_player_p->sche_end_idx = start_idx + idx - 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_query_prog_total_num
 * DESCRIPTION
 *  The function is to query schedule list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_query_prog_total_num(S32 service_id, applib_time_struct *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    mdi_mtv_query_struct query = {0};
    mtv_esg_query_record_count *count_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dtv_player_p->prog_list_hilight_idx = 0;
    dtv_player_p->sche_start_idx = -1;
    dtv_player_p->sche_end_idx = -1;
    dtv_player_p->num_schedules = 0;
    memset(dtv_player_p->schedules, 0, 
		   MMI_DTV_MAX_SCHEDULES * sizeof(dtv_player_schedule_info_struct));

    query.time = time;
    query.id = service_id;
    ret = mdi_mtv_esg_query(dtv_player_p->mtv_handle, 
		                    MEDIA_MTV_ESG_SOURCE_DEFAULT, 
		                    ESG_QUERY_PROGRAM_OF_DAY_COUNT, 
		                    &query);
    if (MDI_RES_MTV_SUCCEED == ret)
    {
        ret = mdi_mtv_esg_get_result(dtv_player_p->mtv_handle, 
		                         MEDIA_MTV_ESG_SOURCE_DEFAULT, 
		                         ESG_QUERY_PROGRAM_OF_DAY_COUNT, 
		                         (void **)&count_ptr);
	    if (NULL != count_ptr)
	    {
	        dtv_player_p->num_schedules = count_ptr->number;
	        dtv_player_p->prog_list_hilight_idx = count_ptr->index;
	        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL2, 
				      count_ptr->number, count_ptr->index, 
				      __LINE__);
	    }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_prog_list_get_menu_num
 * DESCRIPTION
 *  mobile tv player entry program list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_dtv_player_prog_list_get_menu_num(S32 date_index, S32 tab_index, S32 *item_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct offset_time, output_time, cur_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_mem_set(&offset_time, 0, sizeof(applib_time_struct));
    offset_time.nDay = date_index;
    applib_dt_increase_time(
        &dtv_player_p->entry_prog_list_time, &offset_time, &output_time);

    /* For highlight index */
    mmi_dtv_player_get_current_system_time(&cur_time);
    output_time.nHour = cur_time.nHour;
    output_time.nMin = cur_time.nMin;
    output_time.nSec = cur_time.nSec;

    if (dtv_player_p->ca_state != MMI_DTV_CA_STATE_CMMB)
    {
        /* Purify reminder list before query content */
        mdi_mtv_purify_program_reminder(dtv_player_p->mtv_handle, &cur_time);
        mmi_dtv_player_update_alarm();
    }

    /* Get total num */
    mmi_dtv_player_query_prog_total_num(
            dtv_player_p->services[tab_index].service_id, &output_time);

    *item_count = dtv_player_p->num_schedules;


    if (dtv_player_p->num_schedules > 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetLeftSoftkeyFunction(mmi_dtv_player_entry_pl_option_screen, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_dtv_player_play_selected_content, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
        SetLeftSoftkeyFunction(mmi_dtv_player_dummy, KEY_EVENT_UP);

        ChangeCenterSoftkey(0, 0);
        SetCenterSoftkeyFunction(mmi_dtv_player_dummy, KEY_EVENT_UP);
    }

    return *item_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_prog_list_get_hilight_idx
 * DESCRIPTION
 *  mobile tv player get highlight callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_dtv_player_prog_list_get_hilight_idx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return dtv_player_p->prog_list_hilight_idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_prog_list_get_menu_text
 * DESCRIPTION
 *  mobile tv player entry program list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_dtv_player_prog_list_get_menu_text(S32 date_index, S32 tab_index, S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx, ret, sche_idx, query_idx, query_num;
    dtv_player_schedule_info_struct *sche_p;
    applib_time_struct cur_time;
    applib_time_struct offset_time, output_time;
    MMI_BOOL updated;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_mem_set(&offset_time, 0, sizeof(applib_time_struct));
    offset_time.nDay = date_index;
    applib_dt_increase_time(
            &dtv_player_p->entry_prog_list_time, &offset_time, &output_time);

    updated = mmi_dtv_player_update_schedule_range(
                start_index, num_item, &query_idx, &query_num);

    if (updated)
    {
        mmi_dtv_player_query_prog_list(
            dtv_player_p->services[tab_index].service_id,
            &output_time, query_idx, query_num);
    }

    for (idx = 0; idx < num_item; idx ++)
    {
        sche_idx = idx + start_index - dtv_player_p->sche_start_idx;
        ASSERT(sche_idx >=0 && sche_idx < MMI_DTV_MAX_SCHEDULES);

        sche_p = &dtv_player_p->schedules[sche_idx];
        mmi_ucs2cpy(
            (CHAR*) menu_data[idx].item_list[0], (CHAR*) sche_p->time);
        mmi_ucs2cpy((
            CHAR*) menu_data[idx].item_list[1], (CHAR*) sche_p->name);

        /* Reminder icon */
        if (sche_p->if_reminder)
        {
            menu_data[idx].image_list[0] = (PU8)GetImage(IMG_ID_DTV_PLAYER_MENU_REMINDER);
        }
        else
        {
            menu_data[idx].image_list[0] = NULL;
        }

        /* Time icon */
        mmi_dtv_player_get_current_system_time(&cur_time);
        ret = mmi_dtv_player_check_time_status(&cur_time, sche_p->date, sche_p->time);
        if (ret < 0)
        {
            menu_data[idx].image_list[1] = (PU8)GetImage(IMG_ID_DTV_PLAYER_MENU_TIME_EXPIRED);
        }
        else if (ret == 0)
        {
            menu_data[idx].image_list[1] = (PU8)GetImage(IMG_ID_DTV_PLAYER_MENU_PLAY);
        }
        else
        {
            menu_data[idx].image_list[1] = (PU8)GetImage(IMG_ID_DTV_PLAYER_MENU_TIME_PLAY);
        }

        /* Interactivity icon */
        if (sche_p->has_inter_data)
        {
            menu_data[idx].image_list[2] = (PU8)GetImage(IMG_ID_DTV_PLAYER_MENU_INTE_DATA);
        }
        else
        {
            menu_data[idx].image_list[2] = NULL;
        }
    }
    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_content_highlight_hdlr
 * DESCRIPTION
 *  mobile tv player content highlight hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_content_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sche_idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    sche_idx = index - dtv_player_p->sche_start_idx;
    ASSERT(sche_idx >=0 && sche_idx < MMI_DTV_MAX_SCHEDULES);
    dtv_player_p->selected_content = dtv_player_p->schedules[sche_idx];

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_TRC_DTV_SERVICE_ID,
        dtv_player_p->selected_content.service_id, index, __LINE__);
}

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_content_tap_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_content_tap_callback(mmi_tap_type_enum tap_type,S32 index)
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

    mmi_dtv_player_play_selected_content();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_reinit_switch_screen
 * DESCRIPTION
 *  mobile tv player pen down event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_reinit_switch_screen(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* reinit or replay */
    if (KERNEL_STATE_IN(DTV_KERNEL_OPENED) || PLAYER_STATE_IN(DTV_PLAYER_STOPPED))
    {
        ret = mmi_dtv_player_init_service_in_app_screen(MMI_TRUE);
        if (ret == MMI_FALSE)
        {
            return;
        }

        mmi_dtv_player_register_key_hdlr();
        mmi_dtv_player_draw_osd_and_blt();
    }
    /* switch screen */
    else
    {
        mmi_dtv_player_fullscreen_icon_release();
    }
}

#endif /* __MMI_TOUCH_SCREEN__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_exit_program_list_screen
 * DESCRIPTION
 *  mobile tv player exit program list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_exit_program_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dtv_player_p->schedules != NULL)
    {
    #ifdef __COSMOS_MMI_PACKAGE__
        applib_asm_free_r(GRP_ID_DTV_PLAYER, (void *)dtv_player_p->schedules);
    #else /* __COSMOS_MMI_PACKAGE__ */    
        mmi_frm_scrmem_free((void *) dtv_player_p->schedules);
    #endif  /* __COSMOS_MMI_PACKAGE__ */      

        dtv_player_p->schedules = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_program_list_screen
 * DESCRIPTION
 *  mobile tv player entry program list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_program_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *pGuiBuffer;
    U8 tab_idx;
    U8 i;
    MDI_RESULT ret;
    S32 idx = 0;
    applib_time_struct offset_time, output_time;
    dtv_player_service_info_struct *info_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_scrn_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_PROGRAM_LIST,
                mmi_dtv_player_exit_program_list_screen,
                mmi_dtv_player_entry_program_list_screen,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    mmi_frm_scrn_set_leave_proc(
        GRP_ID_DTV_PLAYER,
        SCR_ID_DTV_PLAYER_PROGRAM_LIST,
        mmi_dtv_player_pl_screen_leave_proc);

    /* ASM memory for category history buffer */
    if (dtv_player_p->cat1023_his_buf == NULL)
    {
	#ifdef __MBBMS_CITY_LIST__
        mmi_dtv_player_free_city_mem();
	#endif /* __MBBMS_CITY_LIST__ */
        dtv_player_p->cat1023_his_buf = (U8*) kal_adm_alloc(dtv_player_p->adm_pool_id, 
                                                            MMI_DTV_CAT1023_HISTORY_SIZE);
        ASSERT(dtv_player_p->cat1023_his_buf != NULL);
    }

    /* Must call to initialize category1023 */
    pGuiBuffer =  mmi_frm_scrn_get_active_gui_buf();
    if(pGuiBuffer == NULL)
    {
        wgui_cat1023_set_history_buffer(MMI_DTV_CAT1023_HISTORY_SIZE, 
			                            (void*)dtv_player_p->cat1023_his_buf);
        wgui_cat1023_initialize_history_buffer();
    }

    /* Allocate schedule list buffer */
    ASSERT(sizeof(dtv_player_schedule_info_struct) <= MMI_DTV_MAX_SCHEDULE_INFO_STRUCTURE_SIZE);
#ifdef __COSMOS_MMI_PACKAGE__            
    dtv_player_p->schedules = (dtv_player_schedule_info_struct *) applib_asm_alloc_nc_r(GRP_ID_DTV_PLAYER, MMI_DTV_MAX_SCHEDULES * sizeof(dtv_player_schedule_info_struct));
#else /* __COSMOS_MMI_PACKAGE__ */
    dtv_player_p->schedules = (dtv_player_schedule_info_struct*) mmi_frm_scrmem_alloc(MMI_DTV_MAX_SCHEDULES * sizeof(dtv_player_schedule_info_struct));
#endif

    ASSERT(dtv_player_p->schedules != NULL);
    memset(dtv_player_p->schedules, 0, MMI_DTV_MAX_SCHEDULES * sizeof(dtv_player_schedule_info_struct));

    dtv_player_p->sche_start_idx = -1;
    dtv_player_p->sche_end_idx = -1;
    dtv_player_p->num_schedules = 0;
    dtv_player_p->prog_list_hilight_idx = 0;

    /* Assign date */
    /* Assign date */
    for (i = 0; i < MMI_DTV_PROG_LIST_DAY_NUM; i ++)
    {
        kal_mem_set(dtv_player_p->pl_date[i], 0, MMI_DTV_PROG_LIST_DAY_LEN * 2);
    }
    mmi_dtv_player_get_current_system_time(&dtv_player_p->entry_prog_list_time);
    dtv_player_p->entry_prog_list_time.nHour = 0;
    dtv_player_p->entry_prog_list_time.nMin = 0;
    dtv_player_p->entry_prog_list_time.nSec = 0;

    kal_wstrncpy(dtv_player_p->pl_date[0], 
		         (WCHAR*)GetString(STR_ID_DTV_PLAYER_TODAY), 
		         MMI_DTV_PROG_LIST_DAY_LEN);
    kal_wstrncpy(dtv_player_p->pl_date[1], 
		         (WCHAR*)GetString(STR_ID_DTV_PLAYER_TOMOR), 
		         MMI_DTV_PROG_LIST_DAY_LEN);
    kal_wstrncpy(dtv_player_p->pl_date[2], 
		         (WCHAR*)GetString(STR_ID_DTV_PLAYER_AFT_TOMO), 
		         MMI_DTV_PROG_LIST_DAY_LEN);
    for (i = 3; i < MMI_DTV_PROG_LIST_DAY_NUM; i++)
    {
        /* Reset again because increase_time and decrease_time will modify offset_time */
        memset(&offset_time, 0, sizeof(applib_time_struct));
        offset_time.nDay = i;
        applib_dt_increase_time(
            &dtv_player_p->entry_prog_list_time,
            &offset_time,
            &output_time);
        kal_wsprintf(dtv_player_p->pl_date[i], "%02d-%02d", output_time.nMonth, output_time.nDay);
    }

    for (i = 0; i < MMI_DTV_PROG_LIST_DAY_NUM; i++)
    {
        dtv_player_p->pl_date_ptr[i] = dtv_player_p->pl_date[i];
    }
    /* Asssign highlighted tab index */
    idx = dtv_player_p->setting.selected_channel;
    info_ptr = &dtv_player_p->services[idx];
    for (tab_idx = 0; tab_idx < dtv_player_p->num_services; tab_idx++)
    {
        if (dtv_player_p->services[tab_idx].service_id ==
            info_ptr->service_id)
        {
            break;
        }
    }
    ASSERT(tab_idx < dtv_player_p->num_services);


    RegisterHighlightHandler(mmi_dtv_player_content_highlight_hdlr);
    wgui_cat1023_register_get_highlight_callback(
        mmi_dtv_player_prog_list_get_hilight_idx);

    /* Stop service */
    if (KERNEL_STATE_IN(DTV_KERNEL_READY))
    {
        ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);
        ASSERT(ret == MDI_RES_MTV_SUCCEED);
    }

    wgui_cat1023_show(
        (WCHAR*)GetString(STR_ID_DTV_PLAYER_PROG_L),
        (PU8)GetImage(DTV_PLAYER_MENU_ICON),
        (WCHAR *) GetString(STR_GLOBAL_OPTIONS),
        (PU8)GetImage(IMG_GLOBAL_OPTIONS),
        (WCHAR *) GetString(STR_GLOBAL_BACK),
        (PU8)GetImage(IMG_GLOBAL_BACK),
        MMI_DTV_PROG_LIST_DAY_NUM,
        (WCHAR**)dtv_player_p->pl_date_ptr,
        0, /* Today */
        mmi_dtv_player_prog_list_get_tab_num,
        mmi_dtv_player_prog_list_get_tab_text,
        tab_idx, /* Highlighted channel */
        mmi_dtv_player_prog_list_get_menu_num,
        mmi_dtv_player_prog_list_get_menu_text,
        NULL,
        0,
        pGuiBuffer);

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_tap_callback(mmi_dtv_player_content_tap_callback);
#endif /* __MMI_TOUCH_SCREEN__ */

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

    if (pGuiBuffer == NULL && dtv_player_p->ca_state == MMI_DTV_CA_STATE_CMMB)
    {
        mmi_dtv_player_display_popup(
            STR_ID_DTV_PLAYER_SG_PROVIDED_BY_CMMB,
            MMI_EVENT_SUCCESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_tab_channel_async_items
 * DESCRIPTION
 *  ?
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_dtv_player_get_tab_channel_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item)
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

    /* Change to total index first */
    if (dtv_player_p->service_list_type == DTV_PLAYER_FAVORITE_LIST)
    {
        start_indx = mmi_dtv_player_favo_to_total_idx(start_indx);
    }

    info_ptr = &dtv_player_p->services[start_indx];

    for (i = 0; i < num_item; ++i)
    {
        sprintf((CHAR *) buffer, "CH%2d", info_ptr->service_number);
        mmi_asc_to_ucs2((CHAR *) UCS2_buffer, (CHAR *) buffer);

        /* subject */
        mmi_ucs2cpy((CHAR*) menuData[i].item_list[0], (CHAR*) &UCS2_buffer[0]);
        mmi_ucs2cpy((CHAR*) menuData[i].item_list[1], (CHAR*) info_ptr->service_name);

        mmi_ucs2cpy((CHAR*) menuData[i].item_list[2], (CHAR*) info_ptr->program_time);
        mmi_ucs2cpy((CHAR*) menuData[i].item_list[3], (CHAR*) info_ptr->program_name);

        /* Favorite */
        if (info_ptr->is_favorite)
        {
            menuData[i].image_list[0] = (PU8) GetImage(IMG_ID_DTV_PLAYER_MENU_FAVORITE);
        }
        else
        {
            menuData[i].image_list[0] = NULL;
        }

        /* Lock or unlock */
        if (info_ptr->service_flags == MEDIA_MTV_SERVICE_CLEAR_TO_AIR)
        {
            menuData[i].image_list[1] = NULL;
        }
        else if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_MBBMS ||
                 dtv_player_p->ca_state == MMI_DTV_CA_STATE_MBBMS_INIT)
        {
            menuData[i].image_list[1] = (PU8) GetImage(IMG_ID_DTV_PLAYER_MENU_LOCK);
        }
        else if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_MBBMS_READY ||
                 dtv_player_p->ca_state == MMI_DTV_CA_STATE_MBBMS_FAIL)
        {
            if (info_ptr->service_flags == MEDIA_MTV_SERVICE_UNSUBSCRIBED)
            {
                menuData[i].image_list[1] = (PU8) GetImage(IMG_ID_DTV_PLAYER_MENU_LOCK);
            }
            else if (info_ptr->service_flags == MEDIA_MTV_SERVICE_SUBSCRIBED)
            {
                menuData[i].image_list[1] = (PU8) GetImage(IMG_ID_DTV_PLAYER_MENU_UNLOCK);
            }
        }

        if (dtv_player_p->service_list_type == DTV_PLAYER_FAVORITE_LIST)
        {
            info_ptr = info_ptr->next;
        }
        else
        {
            info_ptr = info_ptr + 1;
        }
    }
    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_favo_to_total_idx
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_dtv_player_favo_to_total_idx(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dtv_player_service_info_struct *info_ptr;
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT (dtv_player_p->service_list_type == DTV_PLAYER_FAVORITE_LIST);
    ASSERT(dtv_player_p->head_of_favorite_service != NULL);

    /* Find out the favorite service pointer */
    info_ptr = dtv_player_p->head_of_favorite_service;
    for (i = 0; i < idx; i ++)
    {
        info_ptr = info_ptr->next;
    }
    ASSERT(info_ptr != NULL);

    /* Calculate the index of the favorite service */
    for (i =0; i < dtv_player_p->num_services; i ++)
    {
        if (dtv_player_p->services[i].service_id == info_ptr->service_id)
        {
            break;
        }
    }
    ASSERT(i < dtv_player_p->num_services);
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_total_to_favo_idx
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_dtv_player_total_to_favo_idx(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dtv_player_service_info_struct *info_ptr, *target;
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT (dtv_player_p->service_list_type == DTV_PLAYER_FAVORITE_LIST);
    if (dtv_player_p->head_of_favorite_service == NULL)
    {
        return 0; /* Not found */
    }

    target = &dtv_player_p->services[idx];
    if (target->is_favorite != MMI_TRUE)
    {
        return 0; /* Not found */
    }

    /* Find out the favorite service pointer */
    info_ptr = dtv_player_p->head_of_favorite_service;
    for (i = 0; i < dtv_player_p->num_favorite_services; i ++)
    {
        if (info_ptr->service_id == target->service_id)
        {
            break;
        }
        info_ptr = info_ptr->next;
    }
    ASSERT(i < dtv_player_p->num_favorite_services);
    return i;
}

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_channel_list_tap_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_channel_list_tap_callback(mmi_tap_type_enum tap_type,S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_CHANNEL_LIST_TAP_CALLBACK, tap_type, index);
    if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_MBBMS_INIT ||
        dtv_player_p->ca_state == MMI_DTV_CA_STATE_MBBMS)
    {
        mmi_dtv_player_display_popup(
                STR_ID_DTV_PLAYER_SUBSCRIPTION_TABLE_UPDATING,
                MMI_EVENT_FAILURE);
        return;
    }

    /* Change to total index first */
    if (dtv_player_p->service_list_type == DTV_PLAYER_FAVORITE_LIST)
    {
        index = mmi_dtv_player_favo_to_total_idx(index);
    }

    /* Error handling, avoid category doesn't call pre-hilight first */
    if (dtv_player_p->setting.selected_channel != index)
    {
        if ((KERNEL_STATE_IN(DTV_KERNEL_READY) || KERNEL_STATE_IN(DTV_KERNEL_INIT)))
        {
            /* stop player and then stop service */
            if (PLAYER_STATE_IN(DTV_PLAYER_PLAY)||PLAYER_STATE_IN(DTV_PLAYER_BT_CONNECT))
            {
                dtv_player_p->last_error = mmi_dtv_player_player_enter_state(DTV_PLAYER_STOPPED);
            }

            ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);

            ASSERT(ret == MDI_RES_MTV_SUCCEED);
        }
    }

    mmi_dtv_player_set_selected_service(index);
    mmi_dtv_player_select_channel_to_play();
    return;
}
#endif /* __MMI_TOUCH_SCREEN__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_exit_confirm
 * DESCRIPTION
 *  mobile tv player exit confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_exit_confirm(void)
{
    mmi_dtv_player_display_confirm(STR_ID_DTV_EXIT_ASK);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_set_tab_attribute
 * DESCRIPTION
 *  mobile tv player entry tab channel screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_set_tab_attribute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Only two tabs. Always enable */
    if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_CMMB)
    {
        return;
    }

    if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_MBBMS ||
        dtv_player_p->ca_state == MMI_DTV_CA_STATE_MBBMS_INIT)
    {
        mmi_frm_scrn_tab_page_set_attribute(
            GRP_ID_DTV_PLAYER,
            SCR_ID_DTV_PLAYER_CHANNEL_LIST,
            SCR_ID_DTV_PLAYER_TAB_FAVORITE_CHANNEL,
            MMI_TAB_PAGE_DISABLE);
        mmi_frm_scrn_tab_page_set_attribute(
            GRP_ID_DTV_PLAYER,
            SCR_ID_DTV_PLAYER_CHANNEL_LIST,
            SCR_ID_DTV_PLAYER_TAB_PROGRAM_REMINDER,
            MMI_TAB_PAGE_DISABLE);
    }
    else
    {
        mmi_frm_scrn_tab_page_clear_attribute(
            GRP_ID_DTV_PLAYER,
            SCR_ID_DTV_PLAYER_CHANNEL_LIST,
            SCR_ID_DTV_PLAYER_TAB_FAVORITE_CHANNEL,
            MMI_TAB_PAGE_DISABLE);
        mmi_frm_scrn_tab_page_clear_attribute(
            GRP_ID_DTV_PLAYER,
            SCR_ID_DTV_PLAYER_CHANNEL_LIST,
            SCR_ID_DTV_PLAYER_TAB_PROGRAM_REMINDER,
            MMI_TAB_PAGE_DISABLE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_tab_channel_screen
 * DESCRIPTION
 *  mobile tv player entry tab channel screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_entry_tab_channel_screen(dtv_player_service_list_type_enum list_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 num_menu_items = 0, str_id;
    S32 error;
    MDI_RESULT ret;
    S32 sel_channel = 0;
    FuncPtr entry_func[2] =
    {
        mmi_dtv_player_entry_tab_all_channel_screen,
        mmi_dtv_player_entry_tab_favorite_channel_screen
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(list_type <= 2);
    if (!mmi_frm_scrn_tab_page_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_CHANNEL_LIST,
                (U16)(SCR_ID_DTV_PLAYER_TAB_ALL_CHANNEL + list_type),
                mmi_dtv_player_exit_channel_list_screen,
                entry_func[list_type],
                MMI_FRM_TAB_PAGE))
    {
        return;
    }

    /* Set tab attribute */
    mmi_dtv_player_set_tab_attribute();

    mmi_dtv_player_unset_flag(DTV_PLAYER_UNAVAILABLE_IN_CALL);

    /* suspend background play */
    mdi_audio_suspend_background_play();

    mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGH_SCRN);

    /* Register bt callback */
#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_register_volume_sync_callback(
        APP_DTV_PLAYER,
        MDI_AUD_VOL_LEVEL_EXTEND_MUTE,
        mmi_dtv_player_bt_volume_sync_hdlr);
#endif

    ClearInputEventHandler(MMI_DEVICE_KEY);

    guiBuffer = mmi_frm_scrn_tab_page_get_active_gui_buf();

    /* Set preview title */
    RegisterHighlightHandler(mmi_dtv_player_highlight_channel_hdlr);

    dtv_player_p->service_list_type = list_type;
    if (list_type == DTV_PLAYER_TOTAL_LIST)
    {
        num_menu_items = dtv_player_p->num_services;
        sel_channel = dtv_player_p->setting.selected_channel;
    }
    else if (list_type == DTV_PLAYER_FAVORITE_LIST)
    {
        num_menu_items = dtv_player_p->num_favorite_services;

        /* Stop original channel first */
        if (num_menu_items == 0)
        {
            if (KERNEL_STATE_IN(DTV_KERNEL_READY))
            {
                ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);
                ASSERT(ret == MDI_RES_MTV_SUCCEED);
            }
            sel_channel = 0;
        }
        else
        {
            sel_channel = mmi_dtv_player_total_to_favo_idx(dtv_player_p->setting.selected_channel);
        }
    }
    else
    {
        ASSERT(0);
    }

    /* Change history */
    if (guiBuffer != NULL)
    {
        change_list_menu_category_history(
            guiBuffer,
            sel_channel,
            num_menu_items,
            0);
    }

    if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_MBBMS ||
        dtv_player_p->ca_state == MMI_DTV_CA_STATE_MBBMS_INIT)
    {
        str_id = STR_ID_DTV_PLAYER_APP_NAME_UPDATING;
    }
    else
    {
		#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
		str_id = STR_ID_DTV_CMMB_2GPP_APP_NAME;
		#else
        str_id = STR_ID_DTV_PLAYER_APP_NAME;
		#endif
    }
	if (DTV_CMMB_TEST_MODE_OFF == g_cmmb_test_mode)
	{		
		wgui_cat1008_show(
			(WCHAR *) GetString(str_id),
			(PU8)GetImage(DTV_PLAYER_MENU_ICON),
			(WCHAR *) GetString(STR_GLOBAL_OPTIONS),
			(PU8)GetImage(IMG_GLOBAL_OPTIONS),
			(WCHAR *) GetString(STR_GLOBAL_EXIT),
			(PU8)GetImage(IMG_GLOBAL_BACK),
			MMI_TRUE,
			num_menu_items,
			mmi_dtv_player_get_tab_channel_async_items,
			NULL,
			mmi_dtv_player_pre_highlight_handler,	/* Stop the last preview */
			mmi_dtv_player_post_highlight_handler,	/* Start the current preview */
			sel_channel,
			list_type,
			guiBuffer,
			&error);
	}
	else
	{		
		wgui_cat1008_show(
			(WCHAR *) GetString(str_id),
			(PU8)GetImage(DTV_PLAYER_MENU_ICON),
			NULL,
			NULL,
			(WCHAR *) GetString(STR_GLOBAL_EXIT),
			(PU8)GetImage(IMG_GLOBAL_BACK),
			MMI_TRUE,
			num_menu_items,
			mmi_dtv_player_get_tab_channel_async_items,
			NULL,
			mmi_dtv_player_pre_highlight_handler,	/* Stop the last preview */
			mmi_dtv_player_post_highlight_handler,	/* Start the current preview */
			sel_channel,
			list_type,
			guiBuffer,
			&error);
	}

#ifdef __MMI_TOUCH_SCREEN__
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
    wgui_register_tap_callback(mmi_dtv_player_channel_list_tap_callback);
#endif /* __MMI_TOUCH_SCREEN__ */


    SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    //SetRightSoftkeyFunction(mmi_dtv_player_cancel_select_channel, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_dtv_player_exit_confirm, KEY_EVENT_UP);
	
	if (DTV_CMMB_TEST_MODE_OFF == g_cmmb_test_mode)
	{    
		SetLeftSoftkeyFunction(mmi_dtv_player_entry_cl_option_screen, KEY_EVENT_UP);
	}

#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
    if ((0 == dtv_player_p->num_services) && (MMI_TRUE == dtv_player_p->rescan_notify))
    {
    	dtv_player_p->rescan_notify = MMI_FALSE;
    	mmi_dtv_player_display_confirm(STR_ID_DTV_2GPP_RESCAN_NOTIFY);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_tab_all_channel_screen
 * DESCRIPTION
 *  mobile tv player entry tab all channel screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_tab_all_channel_screen(void)
{
    mmi_dtv_player_entry_tab_channel_screen(DTV_PLAYER_TOTAL_LIST);
}

void mmi_dtv_player_entry_tab_favorite_channel_screen(void)
{
    mmi_dtv_player_entry_tab_channel_screen(DTV_PLAYER_FAVORITE_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_content_async_items
 * DESCRIPTION
 *  ?
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_dtv_player_get_content_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, idx;
    dtv_player_service_info_struct* info_ptr;
    CHAR buffer[10];
    CHAR UCS2_buffer[16];
    S32 ret, sche_idx;
    applib_time_struct cur_time;
    dtv_player_schedule_info_struct *sche_ptr;
    U16 active_screen_id = mmi_frm_scrn_get_active_id();
    MMI_BOOL updated;
    S32 query_idx, query_num;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (active_screen_id == SCR_ID_DTV_PLAYER_SEARCH_RESULT)
    {
        updated = mmi_dtv_player_update_schedule_range(
                    start_indx, num_item, &query_idx, &query_num);

        if (updated)
        {
            mmi_dtv_player_query_search_result(query_idx, query_num);
        }
    }

    for (i = 0; i < num_item; ++i)
    {
        sche_idx = i + start_indx - dtv_player_p->sche_start_idx;
        ASSERT(sche_idx >=0 && sche_idx < MMI_DTV_MAX_SCHEDULES);

        sche_ptr = &dtv_player_p->schedules[sche_idx];

        /* Schedule name */
        mmi_ucs2cpy((CHAR*) menuData[i].item_list[0], (CHAR*)sche_ptr->name);

        /* Schedule date */
        mmi_ucs2cpy((CHAR*) menuData[i].item_list[1], (CHAR*)sche_ptr->date);

        /* Schedule Time */
        mmi_ucs2cpy((CHAR*) menuData[i].item_list[2], (CHAR*)sche_ptr->time);

        for (idx = 0; idx < dtv_player_p->num_services; idx ++)
        {
            if (sche_ptr->service_id == dtv_player_p->services[idx].service_id)
            {
                break;
            }
        }

        if (idx < dtv_player_p->num_services)
        {
            info_ptr = &dtv_player_p->services[idx];

            sprintf((CHAR *) buffer, "CH%2d ", info_ptr->service_number);
            mmi_asc_to_ucs2((CHAR *) UCS2_buffer, (CHAR *) buffer);
            mmi_ucs2cpy((CHAR*) menuData[i].item_list[3], (CHAR*) &UCS2_buffer[0]);
            mmi_ucs2cat((CHAR*) menuData[i].item_list[3], (CHAR*) info_ptr->service_name);
        }

        /* Reminder icon */
        if (sche_ptr->if_reminder)
        {
            menuData[i].image_list[0] = (PU8)GetImage(IMG_ID_DTV_PLAYER_MENU_REMINDER);
        }
        else
        {
            menuData[i].image_list[0] = NULL;
        }

        /* Time icon */
        /* mmi_dtv_player_get_current_system_time(&cur_time); */

		ret = mmi_dtv_player_check_time_status(&dtv_player_p->play_status_time, sche_ptr->date, sche_ptr->time);
        if (ret < 0)
        {
            menuData[i].image_list[1] = (PU8)GetImage(IMG_ID_DTV_PLAYER_MENU_TIME_EXPIRED);
        }
        else if (ret == 0)
        {
            menuData[i].image_list[1] = (PU8)GetImage(IMG_ID_DTV_PLAYER_MENU_PLAY);
        }
        else
        {
            menuData[i].image_list[1] = (PU8)GetImage(IMG_ID_DTV_PLAYER_MENU_TIME_PLAY);
        }
        
        /* Interactivity icon */
        if (sche_ptr->has_inter_data)
        {
            menuData[i].image_list[2] = (PU8)GetImage(IMG_ID_DTV_PLAYER_MENU_INTE_DATA);
        }
        else
        {
            menuData[i].image_list[2] = NULL;
        } 
        
    }
    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_query_program_reminder
 * DESCRIPTION
 *  mobile tv player entry program list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_query_program_reminder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    mdi_mtv_query_struct query = {0};
    mbbms_sg_query_content_struct *content_p = NULL;
    dtv_player_schedule_info_struct *sche_ptr;
    applib_time_struct cur_time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dtv_player_p->num_schedules = 0;
    memset(dtv_player_p->schedules, 0, MMI_DTV_MAX_SCHEDULES * sizeof(dtv_player_schedule_info_struct));

    /* If there is no service, we shouldn't display program reminder */
    if (dtv_player_p->num_services == 0)
    {
        dtv_player_p->num_schedules = 0;
        return;
    }

    /* Purify reminder list before query content */
    mmi_dtv_player_get_current_system_time(&cur_time);
    mdi_mtv_purify_program_reminder(dtv_player_p->mtv_handle, &cur_time);

    ret = mdi_mtv_esg_query(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_REMINDER_LIST, &query);

    if (ret != MDI_RES_MTV_SUCCEED)
    {
        /* handle error case */
        return;
    }

    while(dtv_player_p->num_schedules < MMI_DTV_MAX_SCHEDULES)
    {
        ret = mdi_mtv_esg_get_result(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_REMINDER_LIST, (void **)&content_p);
        if (content_p == NULL)
        {
            break;
        }

        while (content_p != NULL)
        {
            sche_ptr = &dtv_player_p->schedules[dtv_player_p->num_schedules];
            /* ID */
            strcpy(sche_ptr->cid, content_p->id);

            /* Service ID */
            sche_ptr->service_id = content_p->sid;

            /* Name */
            mmi_ucs2cpy((CHAR*) sche_ptr->name, (CHAR*) content_p->name);

            /* Date */
            mmi_ucs2ncpy((CHAR*)sche_ptr->date, (CHAR*)content_p->start_time, 10);

            /* Time */
            mmi_ucs2ncpy((CHAR*)sche_ptr->time, (CHAR*)&content_p->start_time[11], 5);
            mmi_ucs2cat((CHAR*)sche_ptr->time, (CHAR*)L"-");
            mmi_ucs2ncat((CHAR*)sche_ptr->time, (CHAR*)&content_p->end_time[11], 5);

            sche_ptr->if_reminder = MMI_TRUE;
		#ifdef __MBBMS_INTER__
            sche_ptr->has_inter_data = content_p->has_inter_data;
		#endif /* __MBBMS_INTER__ */
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_TRC_DTV_SERVICE_ID,
                sche_ptr->service_id, dtv_player_p->num_schedules, __LINE__);
            dtv_player_p->num_schedules ++;
            content_p = content_p->next_p;
            if (dtv_player_p->num_schedules >= MMI_DTV_MAX_SCHEDULES)
            {
                break;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_exit_tab_program_reminder_screen
 * DESCRIPTION
 *  mobile tv player exit tab program reminder screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_exit_tab_program_reminder_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dtv_player_p->schedules != NULL)
    {
    #ifdef __COSMOS_MMI_PACKAGE__
        applib_asm_free_r(GRP_ID_DTV_PLAYER, (void *)dtv_player_p->schedules);
    #else /* __COSMOS_MMI_PACKAGE__ */    
        mmi_frm_scrmem_free((void *) dtv_player_p->schedules);
    #endif  /* __COSMOS_MMI_PACKAGE__ */          

        dtv_player_p->schedules = NULL;
    }
    mmi_frm_end_scenario(MMI_SCENARIO_ID_HIGH_SCRN);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_tab_program_reminder_screen
 * DESCRIPTION
 *  mobile tv player entry tab program reminder screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_tab_program_reminder_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 error;
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_tab_page_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_CHANNEL_LIST,
                SCR_ID_DTV_PLAYER_TAB_PROGRAM_REMINDER,
                mmi_dtv_player_exit_tab_program_reminder_screen,
                mmi_dtv_player_entry_tab_program_reminder_screen,
                MMI_FRM_TAB_PAGE))
    {
        return;
    }

    mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGH_SCRN);

    mmi_dtv_player_unset_flag(DTV_PLAYER_UNAVAILABLE_IN_CALL);

    /* suspend background play */
    mdi_audio_suspend_background_play();

    /* Register bt callback */
#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_register_volume_sync_callback(
        APP_DTV_PLAYER,
        MDI_AUD_VOL_LEVEL_EXTEND_MUTE,
        mmi_dtv_player_bt_volume_sync_hdlr);
#endif

    ClearInputEventHandler(MMI_DEVICE_KEY);

    guiBuffer = mmi_frm_scrn_tab_page_get_active_gui_buf();

    /* Allocate schedule list buffer */
    ASSERT(sizeof(dtv_player_schedule_info_struct) <= MMI_DTV_MAX_SCHEDULE_INFO_STRUCTURE_SIZE);

#ifdef __COSMOS_MMI_PACKAGE__
                
    dtv_player_p->schedules = (dtv_player_schedule_info_struct *) applib_asm_alloc_nc_r(GRP_ID_DTV_PLAYER, MMI_DTV_MAX_SCHEDULES * sizeof(dtv_player_schedule_info_struct));
#else /* __COSMOS_MMI_PACKAGE__ */

    dtv_player_p->schedules = (dtv_player_schedule_info_struct*) mmi_frm_scrmem_alloc(MMI_DTV_MAX_SCHEDULES * sizeof(dtv_player_schedule_info_struct));
#endif

    ASSERT(dtv_player_p->schedules != NULL);
    memset(dtv_player_p->schedules, 0, MMI_DTV_MAX_SCHEDULES * sizeof(dtv_player_schedule_info_struct));

    dtv_player_p->sche_start_idx = 0;

    /* Query program reminder */
    mmi_dtv_player_query_program_reminder();
    /* Set preview title */
    RegisterHighlightHandler(mmi_dtv_player_content_highlight_hdlr);

    /* Stop service */
    if (KERNEL_STATE_IN(DTV_KERNEL_READY))
    {
        ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);

        ASSERT(ret == MDI_RES_MTV_SUCCEED);
    }

    /* Update alarm */
    mmi_dtv_player_update_alarm();

    if (dtv_player_p->num_schedules > 0)
    {
        /* Call enable before showCategory, call change after showCategory */
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }

    dtv_player_p->service_list_type = DTV_PLAYER_PROG_REMINDER_LIST;
    mmi_dtv_player_get_current_system_time(&dtv_player_p->play_status_time);	
	
    wgui_cat1009_show(
        (WCHAR *) GetString(STR_ID_DTV_PLAYER_APP_NAME),
        (PU8)GetImage(DTV_PLAYER_MENU_ICON),
        (WCHAR *) GetString(STR_GLOBAL_OPTIONS),
        (PU8)GetImage(IMG_GLOBAL_OPTIONS),
        (WCHAR *) GetString(STR_GLOBAL_EXIT),
        (PU8)GetImage(IMG_GLOBAL_BACK),
        dtv_player_p->num_schedules,
        mmi_dtv_player_get_content_async_items,
        NULL,
        0,
        DTV_PLAYER_PROG_REMINDER_LIST,
        guiBuffer,
        &error);

#ifdef __MMI_TOUCH_SCREEN__
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
#endif /* __MMI_TOUCH_SCREEN__ */

    SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetLeftSoftkeyFunction(mmi_dtv_player_entry_cl_option_screen, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(mmi_dtv_player_cancel_select_channel, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_dtv_player_exit_confirm, KEY_EVENT_UP);
    if (dtv_player_p->num_schedules > 0)
    {
        SetCenterSoftkeyFunction(mmi_dtv_player_play_selected_content, KEY_EVENT_UP);
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_register_tap_callback(mmi_dtv_player_content_tap_callback);
    #endif /* __MMI_TOUCH_SCREEN__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_mo_option_screen
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
 void mmi_dtv_player_entry_mo_option_screen(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->mo_option_menu_gid =
        cui_menu_create(
            GRP_ID_DTV_PLAYER,
            CUI_MENU_SRC_TYPE_RESOURCE,
            CUI_MENU_TYPE_OPTION,
            MENU_ID_DTV_PLAYER_MO_OPTION,
            MMI_FALSE,
            NULL);
    cui_menu_run(dtv_player_p->mo_option_menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_order_name_string
 * DESCRIPTION
 *  ?
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_get_order_name_string(dtv_player_order_struct *order_p, WCHAR *name_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ucs2ncpy((CHAR *)name_str, (CHAR *)order_p->name, MAX_SUBMENU_CHARACTERS);
    len = MAX_SUBMENU_CHARACTERS - mmi_ucs2strlen((CHAR *)name_str);

    if (len <= 0)
    {
        return;
    }
    if (order_p->subscribed)
    {
        mmi_ucs2ncat(
            (CHAR *)name_str,
            (CHAR*)GetString(STR_ID_DTV_PLAYER_SUBSCRIBED),
            len);
    }
    else
    {
        mmi_ucs2ncat(
            (CHAR *)name_str,
            (CHAR*)GetString(STR_ID_DTV_PLAYER_UNSUBSCRIBED),
            len);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_order_type_string
 * DESCRIPTION
 *  ?
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_get_order_type_string(dtv_player_order_struct *order_p, WCHAR *type_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR num_str[20];
    S32 len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* program by once */
    if (order_p->type == 128)
    {
        mmi_ucs2ncpy(
            (CHAR *)type_str,
            (CHAR*)GetString(STR_ID_DTV_PLAYER_ONCE),
            MAX_SUBMENU_CHARACTERS);
    }
    /* channel & order by one month */
    else if (order_p->type == 129 || order_p->type == 130)
    {
        mmi_ucs2ncpy(
            (CHAR *)type_str,
            GetString(STR_ID_DTV_PLAYER_INCLUDE_MONTH),
            MAX_SUBMENU_CHARACTERS);
    }
    /* order by months */
    else if (order_p->type == 131)
    {
        kal_wsprintf(num_str, "%d", order_p->period);
        mmi_ucs2ncpy(
            (CHAR *)type_str,
            (CHAR*)num_str,
            MAX_SUBMENU_CHARACTERS);
        len = MAX_SUBMENU_CHARACTERS - mmi_ucs2strlen((CHAR *)type_str);
        if (len > 0)
        {
            mmi_ucs2ncat(
                (CHAR *)type_str,
                (CHAR*)GetString(STR_ID_DTV_PLAYER_MONTHS), len);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_order_price_string
 * DESCRIPTION
 *  ?
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_get_order_price_string(dtv_player_order_struct *order_p, WCHAR *price_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len;
    CHAR tmp_buf[20];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Price */
    kal_sprintf(tmp_buf, "%.1f", order_p->price);

    mmi_asc_n_to_ucs2(
        (CHAR *)price_str,
        (CHAR *)tmp_buf,
        MAX_SUBMENU_CHARACTERS << 1);

    len = MAX_SUBMENU_CHARACTERS - mmi_ucs2strlen((CHAR *)price_str);
    if (len > 0)
    {
        mmi_ucs2ncat(
            (CHAR*)price_str,
            (CHAR*)GetString(STR_ID_DTV_PLAYER_YUAN),
            len);
    }

    if (order_p->type == 129 || order_p->type == 130)
    {
        len = MAX_SUBMENU_CHARACTERS - mmi_ucs2strlen((CHAR *)price_str);
        if (len > 0)
        {
            mmi_ucs2ncat(
                (CHAR*)price_str,
                (CHAR*)GetString(STR_ID_DTV_PLAYER_SLASH_MONTH), len);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_order_async_callback
 * DESCRIPTION
 *  ?
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_dtv_player_get_order_async_callback(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 order_start_idx = 0, idx;
    S32 i = 0;
    dtv_player_order_struct *order_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dtv_player_p->mo_list_type == DTV_PLAYER_SUBSCRIBED_ORDER_LIST)
    {
        order_start_idx = start_indx;
    }
    else if (dtv_player_p->mo_list_type == DTV_PLAYER_UNSUBSCRIBED_ORDER_LIST)
    {
        order_start_idx = start_indx + dtv_player_p->num_subscribed_orders;
    }

    idx = order_start_idx;
    for (i = 0; i < num_item; ++i)
    {
        order_p = &dtv_player_p->orders[idx];

        /* Name */
        mmi_dtv_player_get_order_name_string(
            order_p, (WCHAR*)menuData[i].item_list[0]);

        /* Type */
        mmi_dtv_player_get_order_type_string(
            order_p, (WCHAR*)menuData[i].item_list[1]);

        /* Price */
        mmi_dtv_player_get_order_price_string(
            order_p, (WCHAR*)menuData[i].item_list[2]);

        menuData[i].image_list[0] = (PU8)GetImage(IMG_ID_DTV_PLAYER_MENU_TIME);
        menuData[i].image_list[1] = (PU8)GetImage(IMG_ID_DTV_PLAYER_MENU_PRICE);

        idx ++;
    }
    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_order_highlight_hdlr
 * DESCRIPTION
 *  mobile tv player order highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_order_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 order_idx = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dtv_player_p->highlighted_order = index;

    if (dtv_player_p->mo_list_type == DTV_PLAYER_SUBSCRIBED_ORDER_LIST)
    {
        order_idx = index;
    }
    else if (dtv_player_p->mo_list_type == DTV_PLAYER_UNSUBSCRIBED_ORDER_LIST)
    {
        order_idx = index + dtv_player_p->num_subscribed_orders;
    }

    /* Save selected order */
    dtv_player_p->selected_order = dtv_player_p->orders[order_idx];

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_exit_tab_order_screen
 * DESCRIPTION
 *  mobile tv player exit tab order screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_exit_tab_order_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dtv_player_p->orders != NULL)
    {
    #ifdef __COSMOS_MMI_PACKAGE__
        applib_asm_free_r(GRP_ID_DTV_PLAYER, (void *)dtv_player_p->orders);
    #else /* __COSMOS_MMI_PACKAGE__ */    
        mmi_frm_scrmem_free((void*)dtv_player_p->orders);
    #endif  /* __COSMOS_MMI_PACKAGE__ */     
    
        dtv_player_p->orders = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_tab_order_screen
 * DESCRIPTION
 *  mobile tv player entry tab order screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtv_player_entry_tab_order_screen(dtv_player_mo_list_type_enum list_type)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 num_menu_items = 0;
    S32 tab_index = list_type;
    S32 error;
	UI_string_type string = NULL;
    WCHAR *lsk_str;
    PU8 lsk_img;
    FuncPtr entry_func[2] =
    {
        mmi_dtv_player_entry_tab_subscribed_order_screen,
        mmi_dtv_player_entry_tab_unsubscribed_order_screen
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_scrn_tab_page_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_MANAGE_ORDER,
                (U16)(SCR_ID_DTV_PLAYER_TAB_SUBSCRIBED_ORDER + tab_index),
                mmi_dtv_player_exit_tab_order_screen,
                entry_func[tab_index],
                MMI_FRM_TAB_PAGE))
    {
        return;
    }

    dtv_player_p->mo_list_type = list_type;

    mmi_dtv_player_unset_flag(DTV_PLAYER_UNAVAILABLE_IN_CALL);

    /* suspend background play */
    mdi_audio_suspend_background_play();

    /* Register bt callback */
#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_register_volume_sync_callback(
        APP_DTV_PLAYER,
        MDI_AUD_VOL_LEVEL_EXTEND_MUTE,
        mmi_dtv_player_bt_volume_sync_hdlr);
#endif

    ClearInputEventHandler(MMI_DEVICE_KEY);

    guiBuffer = mmi_frm_scrn_tab_page_get_active_gui_buf();

    RegisterHighlightHandler(mmi_dtv_player_order_highlight_hdlr);

    /* Allocate schedule list buffer */
    ASSERT(sizeof(dtv_player_order_struct) <= MMI_DTV_MAX_ORDER_STRUCTURE_SIZE);

#ifdef __COSMOS_MMI_PACKAGE__
                    
    dtv_player_p->orders = (dtv_player_order_struct *) applib_asm_alloc_nc_r(GRP_ID_DTV_PLAYER, MMI_DTV_MAX_ORDERS * sizeof(dtv_player_order_struct));
#else /* __COSMOS_MMI_PACKAGE__ */

    dtv_player_p->orders = (dtv_player_order_struct*) mmi_frm_scrmem_alloc(MMI_DTV_MAX_ORDERS * sizeof(dtv_player_order_struct));
#endif

    ASSERT(dtv_player_p->orders != NULL);
    memset(dtv_player_p->orders, 0, MMI_DTV_MAX_ORDERS * sizeof(dtv_player_order_struct));

    /* Fill order structure */
    mmi_dtv_player_query_order_list();

    if (dtv_player_p->mo_list_type == DTV_PLAYER_SUBSCRIBED_ORDER_LIST)
    {
        num_menu_items = dtv_player_p->num_subscribed_orders;
    }
    else if (dtv_player_p->mo_list_type == DTV_PLAYER_UNSUBSCRIBED_ORDER_LIST)
    {
        ASSERT(dtv_player_p->num_orders >= dtv_player_p->num_subscribed_orders);
        num_menu_items = dtv_player_p->num_orders - dtv_player_p->num_subscribed_orders;
    }
    else
    {
        ASSERT(0);
    }

    /* LSK */
    if (num_menu_items == 0)
    {
        lsk_str = NULL;
        lsk_img = NULL;
    }
    else
    {
        lsk_str = (WCHAR *) GetString(STR_GLOBAL_OPTIONS);
        lsk_img = (PU8)GetImage(IMG_GLOBAL_OPTIONS);

        /* Call enable before showCategory, call change after showCategory */
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }

	if (DTV_PLAYER_SUBSCRIBED_ORDER_LIST == tab_index)
	{
		string = (UI_string_type)GetString(STR_ID_DTV_PLAYER_ONLY_CAN_WATCH_LOCAL_ORDER);
	}
	
    wgui_cat1020_show(
        (WCHAR *) GetString(STR_ID_DTV_PLAYER_MANAGE_ORDER),
		(PU8)GetImage(DTV_PLAYER_MENU_ICON),
        lsk_str,
        lsk_img,
        (WCHAR *) GetString(STR_GLOBAL_BACK),
        (PU8)GetImage(IMG_GLOBAL_BACK),
        num_menu_items,
		string,
        mmi_dtv_player_get_order_async_callback,
        NULL,
        dtv_player_p->highlighted_order,
        tab_index,
        guiBuffer,
        &error);

#ifdef __MMI_TOUCH_SCREEN__
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
#endif /* __MMI_TOUCH_SCREEN__ */

    SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

    if (num_menu_items > 0)
    {
        SetCenterSoftkeyFunction(mmi_dtv_player_display_order_confirm, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_dtv_player_entry_mo_option_screen, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_tab_subscribed_order_screen
 * DESCRIPTION
 *  mobile tv player entry tab all channel screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_tab_subscribed_order_screen(void)
{
    mmi_dtv_player_entry_tab_order_screen(DTV_PLAYER_SUBSCRIBED_ORDER_LIST);
}

void mmi_dtv_player_entry_tab_unsubscribed_order_screen(void)
{
    mmi_dtv_player_entry_tab_order_screen(DTV_PLAYER_UNSUBSCRIBED_ORDER_LIST);
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
 mmi_ret mmi_dtv_player_mo_screen_leave_proc(mmi_event_struct *para)
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
            if (NULL != dtv_player_p->account)
            {
                kal_adm_free(dtv_player_p->adm_pool_id,
					         (void *) dtv_player_p->account);
                dtv_player_p->account = NULL;
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
 *  mmi_dtv_player_entry_manage_order_screen
 * DESCRIPTION
 *  mobile tv player entry manage order screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_manage_order_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_frm_tab_struct *tab_ptr;
    MDI_RESULT ret;
    mmi_frm_tab_struct tab_pages_info[DTV_PLAYER_MO_LIST_TYPE_NUM];
    FuncPtr entry_func[DTV_PLAYER_MO_LIST_TYPE_NUM] =
    {
        mmi_dtv_player_entry_tab_subscribed_order_screen,
        mmi_dtv_player_entry_tab_unsubscribed_order_screen
    };
    U8 *tab_str[DTV_PLAYER_MO_LIST_TYPE_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Stop service */
    if (KERNEL_STATE_IN(DTV_KERNEL_READY))
    {
        ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);

        ASSERT(ret == MDI_RES_MTV_SUCCEED);
    }

    /* Assign tab string */
    tab_str[0] = (U8*)GetString(STR_ID_DTV_PLAYER_SUBSCRIBED_ORDER);
    tab_str[1] = (U8*)GetString(STR_ID_DTV_PLAYER_UNSUBSCRIBED_ORDER);

    for (i = 0; i < DTV_PLAYER_MO_LIST_TYPE_NUM; i++)
    {
        tab_ptr = &tab_pages_info[i];
        tab_ptr->screen_id = SCR_ID_DTV_PLAYER_TAB_SUBSCRIBED_ORDER + i;
        tab_ptr->tab_entry_func = entry_func[i];
        tab_ptr->tab_icon = NULL;
        tab_ptr->tab_string = tab_str[i];
    }

    mmi_frm_scrn_tab_enter(GRP_ID_DTV_PLAYER,
					       SCR_ID_DTV_PLAYER_MANAGE_ORDER,
					       NULL,
					       mmi_dtv_player_entry_manage_order_screen,
					       tab_pages_info,
					       DTV_PLAYER_MO_LIST_TYPE_NUM,
                           dtv_player_p->mo_list_type);

    mmi_frm_scrn_set_leave_proc(
        GRP_ID_DTV_PLAYER,
        SCR_ID_DTV_PLAYER_MANAGE_ORDER,
        mmi_dtv_player_mo_screen_leave_proc);
}

#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
/*****************************************************************************
 * FunctionName: mmi_dtv_player_cmmb_2gpp_display_hint
 * Description
 *     
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-05-18
 *****************************************************************************/
void mmi_dtv_player_cmmb_2gpp_display_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
    dtv_player_service_info_struct *info_ptr;
	CHAR *hint_str1 = NULL;
	CHAR *hint_str2 = NULL;
	CMMB_2GPP_STATUS_ENUM status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_prompt_trace(MOD_MMI, "MMI_MTV yaling mmi_dtv_player_cmmb_2gpp_display_hint");
    info_ptr = mmi_dtv_player_get_active_channel_ptr();
  /*  if (info_ptr->service_flags & MEDIA_MTV_SERVICE_CLEAR_TO_AIR)
    {
    	return;
    }
*/
	status = mmi_cmmb_2gpp_get_authen_status();

	kal_prompt_trace(MOD_MMI, "MMI_MTV yaling mmi_dtv_player_cmmb_2gpp_display_hint state = %d", status);
	
	switch (status)
	{
		case CMMB_2GPP_NONE:					   /* 初始状态*/
			{
				break;
			}
		case CMMB_2GPP_CA_ERR:						   /* CA Error*/
			{
				hint_str1 = (CHAR*)GetString((U16) (STR_ID_DTV_PLAYER_CA_ERR));
				hint_str2 =  (CHAR*)GetString((U16) (STR_ID_DTV_PLAYER_CA_ERR2));
				break;
			}
		case CMMB_2GPP_INSERT_SIM:					   /* 请插入手机卡*/
			{				
				hint_str1 = (CHAR*)GetString((U16) (STR_ID_DTV_PLAYER_INSERT_SIM));
				break;
			}			
		case CMMB_2GPP_GETTING_AUTH:				       /* 正在刷新授权...*/
			{				
				hint_str1 = (CHAR*)GetString((U16) (STR_ID_DTV_PLAYER_AUTH_REFRESHING));
				break;
			}
		case CMMB_2GPP_WAITING_AUTH:				      /* 正在接收授权*/
			{
				hint_str1 = (CHAR*)GetString((U16) (STR_ID_DTV_PLAYER_AUTH_RECVING));
				hint_str2 =  (CHAR*)GetString((U16) (STR_ID_DTV_PLAYER_AUTH_RECVING2));
				break;
			}
		case CMMB_2GPP_NET_ERR:						   /* GPRS网络故障或GPRS未开通*/
			{
				hint_str1 = (CHAR*)GetString((U16) (STR_ID_DTV_PLAYER_AUTH_FAILED));
				hint_str2 =  (CHAR*)GetString((U16) (STR_ID_DTV_PLAYER_AUTH_FAILED2));
				break;
			}
		case CMMB_2GPP_TIMER_EXPIRE: 				       /* 授权超时*/
			{
				hint_str1 = (CHAR*)GetString((U16) (STR_ID_DTV_PLAYER_AUTH_TIMER_EXPIRE));
				hint_str2 =  (CHAR*)GetString((U16) (STR_ID_DTV_PLAYER_AUTH_TIMER_EXPIRE2));
				break;
			}
		case CMMB_2GPP_UNKOWN_ERR:					   /* 授权出错*/
			{
				hint_str1 = (CHAR*)GetString((U16) (STR_ID_DTV_PLAYER_AUTH_ERROR));
				hint_str2 =  (CHAR*)GetString((U16) (STR_ID_DTV_PLAYER_AUTH_ERROR2));
				break;
			}
		default:
			{
				break;
			}		
	}	
	mmi_dtv_player_set_hint((CHAR *) hint_str1,
							(CHAR *) hint_str2,
							MMI_DTV_PLAYER_HINT_POPUP_NO_FADE,
							MMI_TRUE);
}


/*****************************************************************************
 * FunctionName: mmi_dtv_player_2gpp_display_athenticate_state
 * Description
 *     
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-05-07
 *****************************************************************************/
void mmi_dtv_player_2gpp_display_athenticate_state(int status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen = mmi_frm_scrn_get_active_id();
    dtv_player_service_info_struct *info_ptr;
	CHAR *hint_str1 = NULL;
	CHAR *hint_str2 = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_DTV_VAL1, status,__LINE__);
	
	switch (status)
	{
		case CMMB_2GPP_NONE:					   /* 初始状态*/
			{
				break;
			}
		case CMMB_2GPP_CA_ERR:						   /* CA Error*/
			{
				hint_str1 = (CHAR*)GetString((U16) (STR_ID_DTV_PLAYER_CA_ERR));
				hint_str2 =  (CHAR*)GetString((U16) (STR_ID_DTV_PLAYER_CA_ERR2));
				break;
			}
		case CMMB_2GPP_INSERT_SIM:					   /* 请插入手机卡*/
			{				
				hint_str1 = (CHAR*)GetString((U16) (STR_ID_DTV_PLAYER_INSERT_SIM));
				break;
			}			
		case CMMB_2GPP_GETTING_AUTH:				       /* 正在刷新授权...*/
			{				
				hint_str1 = (CHAR*)GetString((U16) (STR_ID_DTV_PLAYER_AUTH_REFRESHING));
				break;
			}
		case CMMB_2GPP_WAITING_AUTH:				      /* 正在接收授权*/
			{
				hint_str1 = (CHAR*)GetString((U16) (STR_ID_DTV_PLAYER_AUTH_RECVING));
				hint_str2 =  (CHAR*)GetString((U16) (STR_ID_DTV_PLAYER_AUTH_RECVING2));
				break;
			}
		case CMMB_2GPP_NET_ERR:						   /* GPRS网络故障或GPRS未开通*/
			{
				hint_str1 = (CHAR*)GetString((U16) (STR_ID_DTV_PLAYER_AUTH_FAILED));
				hint_str2 =  (CHAR*)GetString((U16) (STR_ID_DTV_PLAYER_AUTH_FAILED2));
				break;
			}
		case CMMB_2GPP_TIMER_EXPIRE: 				       /* 授权超时*/
			{
				hint_str1 = (CHAR*)GetString((U16) (STR_ID_DTV_PLAYER_AUTH_TIMER_EXPIRE));
				hint_str2 =  (CHAR*)GetString((U16) (STR_ID_DTV_PLAYER_AUTH_TIMER_EXPIRE2));
				break;
			}
		case CMMB_2GPP_UNKOWN_ERR:					   /* 授权出错*/
			{
				hint_str1 = (CHAR*)GetString((U16) (STR_ID_DTV_PLAYER_AUTH_ERROR));
				hint_str2 =  (CHAR*)GetString((U16) (STR_ID_DTV_PLAYER_AUTH_ERROR2));
				break;
			}
		default:
			{
				break;
			}		
	}
	
    /* Set the flag */
  //  mmi_dtv_player_set_flag(DTV_PLAYER_ACCESS_DENIED);

    /* Stop animation */
    info_ptr = mmi_dtv_player_get_active_channel_ptr();
    if (info_ptr->service_type == MDI_MTV_SERVICE_TYPE_DIGITAL_RADIO)
    {
        mmi_dtv_player_stop_radio_animation();
    }

    /* To stop BT connecting action and BT animation */
    if (PLAYER_STATE_IN(DTV_PLAYER_BT_CONNECT))
    {
        mmi_dtv_player_player_enter_state(DTV_PLAYER_STOPPED);
    }

    if (active_screen == SCR_ID_DTV_PLAYER_APP)
    {
        mmi_dtv_player_set_hint(hint_str1,
            					hint_str2,
            					MMI_DTV_PLAYER_HINT_POPUP_NO_FADE,
            					MMI_TRUE);
        mmi_dtv_player_register_key_hdlr();
        mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }
    else if (active_screen == SCR_ID_DTV_PLAYER_CHANNEL_LIST)
    {
		    
    }
}
	

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_display_access_denied
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
void mmi_dtv_player_display_access_denied(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen = mmi_frm_scrn_get_active_id();
    dtv_player_service_info_struct *info_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_DISPLAY_ACCESS_DENIED);
    /* Set the flag */
    mmi_dtv_player_set_flag(DTV_PLAYER_ACCESS_DENIED);

    /* Stop animation */
    info_ptr = mmi_dtv_player_get_active_channel_ptr();
    if (info_ptr->service_type == MDI_MTV_SERVICE_TYPE_DIGITAL_RADIO)
    {
        mmi_dtv_player_stop_radio_animation();
    }

    /* To stop BT connecting action and BT animation */
    if (PLAYER_STATE_IN(DTV_PLAYER_BT_CONNECT))
    {
        mmi_dtv_player_player_enter_state(DTV_PLAYER_STOPPED);
    }

    if (active_screen == SCR_ID_DTV_PLAYER_APP)
    {
        mmi_dtv_player_set_hint(
            (CHAR *) GetString((U16) (STR_ID_DTV_PLAYER_NOTIFY_ACCESS_DENIED)),
            (CHAR *) NULL,
            MMI_DTV_PLAYER_HINT_POPUP_NO_FADE,
            MMI_TRUE);

        /* When all fade out, all key handler is mmi_dtv_player_fullscr_osd_show_up */
        mmi_dtv_player_register_key_hdlr();
        mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }
    else if (active_screen == SCR_ID_DTV_PLAYER_CHANNEL_LIST)
    {
        // still in hw update state, can't draw anything on the video layer
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_service_access_granted_hdlr
 * DESCRIPTION
 *  mmi_dtv_player_service_access_granted_hdlr
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_service_access_granted_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dtv_player_service_info_struct *info_ptr;
    U16 active_screen = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Always stop timer for safe */
    StopTimer(DTV_PLAYER_DISPLAY_ACCESS_DENIED_TIMER);


    if (mmi_dtv_player_is_flag_set(DTV_PLAYER_ACCESS_DENIED))
    {
        mmi_dtv_player_unset_flag(DTV_PLAYER_ACCESS_DENIED);

        if (active_screen != SCR_ID_DTV_PLAYER_CHANNEL_LIST &&
            active_screen != SCR_ID_DTV_PLAYER_APP)
        {
            return;
        }

        if (active_screen == SCR_ID_DTV_PLAYER_APP)
        {
            /* If the hint has been displayed, hide the hint */
            mmi_dtv_player_hide_hint();
            if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
            {
                mmi_dtv_player_fullscr_reset_osd_fade(MMI_TRUE);
                mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
            }
        }

        if (PLAYER_STATE_IN(DTV_PLAYER_STOPPED))
        {
            mmi_dtv_player_entry_play();
        }
        else if (PLAYER_STATE_IN(DTV_PLAYER_PLAY))
        {
            /* Resume radio animation */
            info_ptr = mmi_dtv_player_get_active_channel_ptr();
            if (info_ptr->service_type == MDI_MTV_SERVICE_TYPE_DIGITAL_RADIO)
            {
                mmi_dtv_player_draw_radio_animation();
            }
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_service_access_denied_hdlr
 * DESCRIPTION
 *  mmi_dtv_player_service_access_denied_hdlr
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_service_access_denied_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen = mmi_frm_scrn_get_active_id();
    MDI_RESULT ret;
#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
	cmmb_2gpp_event_access_deny_struct access_struct;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

#if defined(__CMMB_CAS_MBBMS_SUPPORT__)
    if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_CMMB)
    {
        /* Stop player and service: make LCD turn off */
        if (!PLAYER_STATE_IN(DTV_PLAYER_STOPPED))
        {
            mmi_dtv_player_player_enter_state(DTV_PLAYER_STOPPED);
        }
        if (!KERNEL_STATE_IN(DTV_KERNEL_OPENED))
        {
            ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);
            ASSERT(ret == MDI_RES_MTV_SUCCEED);
        }

        mmi_dtv_player_display_access_denied();

        if (active_screen == SCR_ID_DTV_PLAYER_APP)
        {
            mmi_dtv_player_fullscr_reset_osd_fade(MMI_FALSE);
            mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
        }
        else if (active_screen == SCR_ID_DTV_PLAYER_CHANNEL_LIST)
        {
            /* Draw access denied icon */
            mmi_dtv_player_draw_preview_icon(DTV_PLAYER_PREVIEW_ICON_ACCESS_DENIED);
        }
    }
    else
#endif /* __CMMB_CAS_MBBMS_SUPPORT__ */      
    {

	#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
	    /* Set the flag */
        mmi_dtv_player_set_flag(DTV_PLAYER_ACCESS_DENIED);
		access_struct.call_back = mmi_dtv_player_2gpp_display_athenticate_state;
		mmi_cmmb_2gpp_adp_notify(EVT_ID_CMMB_2GPP_MMI_ACCESS_DENY,0,&access_struct);
		//mmi_dtv_player_2gpp_display_athenticate_state(CMMB_2GPP_NONE);
	#else
        /* start timer, set ACCESS_DENIED flag after time out */
        if (!IsMyTimerExist(DTV_PLAYER_DISPLAY_ACCESS_DENIED_TIMER))
        {
            StartTimer(
                DTV_PLAYER_DISPLAY_ACCESS_DENIED_TIMER,
                MMI_DTV_PLAYER_DISPLAY_ACCESS_DENIED_DURATION,
                mmi_dtv_player_display_access_denied);
        }
	#endif
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_exit_esg_download
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_exit_esg_download(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (KERNEL_STATE_IN(DTV_KERNEL_ESG_DOWNLOAD))
    {
        mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);
    }

    mmi_frm_end_scenario(MMI_SCENARIO_ID_HIGH_SCRN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_stop_esg_download
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
void mmi_dtv_player_stop_esg_download(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(KERNEL_STATE_IN(DTV_KERNEL_ESG_DOWNLOAD));

    mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);

    mmi_dtv_player_reset_to_channel_list_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_enter_esg_download
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
void mmi_dtv_player_enter_esg_download(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    U8 *guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_ESG_DOWNLOAD,
                mmi_dtv_player_exit_esg_download,
                mmi_dtv_player_enter_esg_download,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    /* suspend background play */
    mdi_audio_suspend_background_play();

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGH_SCRN);
    dtv_player_p->scan_progress = 0;
    //ShowCategory412Screen
    wgui_cat1040_show(
        (UI_string_type)GetString(STR_ID_DTV_PLAYER_APP_NAME),
        (PU8)GetImage(DTV_PLAYER_MENU_ICON),
        0,
        0,
        (UI_string_type)GetString(STR_GLOBAL_CANCEL),
        0,
        (PU8)GetImage(IMG_ID_DTV_PLAYER_INITIALIZING),
        (UI_string_type)GetString(STR_ID_DTV_PLAYER_DOWNLOADING_SERVICE_GUIDE),
        dtv_player_p->scan_progress,
        0,
        0,
        guiBuffer);

    ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_ESG_DOWNLOAD);

    if (ret != MDI_RES_MTV_SUCCEED)
    {
        /* Close channel list screen first to avoid re-entry*/
        mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_CHANNEL_LIST);
        mmi_dtv_player_entry_channel_list_screen();
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
        StartTimer(
            DTV_PLAYER_UPDATE_SCAN_STATUS, 1000,
            mmi_dtv_player_gen_scan_progress);
        SetRightSoftkeyFunction(mmi_dtv_player_stop_esg_download, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_new_esg_available_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_new_esg_available_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* TODO: confirm if MobileTV CUI is in active screen case */
    if (mmi_frm_group_get_active_id() != GRP_ID_DTV_PLAYER)
    {
        mmi_dtv_player_set_flag(DTV_PLAYER_NEW_ESG_AVAILABLE);
        return;
    }

    /* Set flag only: when scan finish, enter ESG downloading screen */
    if (KERNEL_STATE_IN(DTV_KERNEL_SCANNING))
    {
        mmi_dtv_player_set_flag(DTV_PLAYER_NEW_ESG_AVAILABLE);
        return;
    }

    /* Following: Prepare to enter ESG downloading screen */
    if (KERNEL_STATE_IN(DTV_KERNEL_READY) || KERNEL_STATE_IN(DTV_KERNEL_INIT))
    {
        /* if recorder is recording, don't channel channel */
        if (!RECORDER_STATE_IN(DTV_RECORDER_STOPPED))
        {
            mmi_dtv_player_set_flag(DTV_PLAYER_NEW_ESG_AVAILABLE);
            return;
        }

        if (PLAYER_STATE_IN(DTV_PLAYER_PLAY) || PLAYER_STATE_IN(DTV_PLAYER_BT_CONNECT)|| PLAYER_STATE_IN(DTV_PLAYER_PAUSE))
        {
            mmi_dtv_player_player_enter_state(DTV_PLAYER_STOPPED);
        }

        mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);
    }
    mmi_dtv_player_enter_esg_download();
    mmi_dtv_player_unset_flag(DTV_PLAYER_NEW_ESG_AVAILABLE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_favorite_service_index
 * DESCRIPTION
 *  index
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_dtv_player_get_favorite_service_index(dtv_player_service_info_struct *info_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dtv_player_service_info_struct* tmp_ptr;
    S32 favorite_service_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(dtv_player_p->head_of_favorite_service != 0);
    tmp_ptr = dtv_player_p->head_of_favorite_service;

    favorite_service_index = 0;
    while (tmp_ptr != info_ptr)
    {
        tmp_ptr = tmp_ptr->next;
        favorite_service_index ++;
        ASSERT(favorite_service_index < dtv_player_p->num_favorite_services);
    }

    return favorite_service_index;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_exit_card_info_screen
 * DESCRIPTION
 *  mobile tv player exit card info screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_exit_card_info_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_dtv_player_free_detail_screen_memory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_compare_apptime
 * DESCRIPTION
 *  The function is to compare apptime
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
S32 mmi_dtv_player_compare_apptime(applib_time_struct *time1, applib_time_struct *time2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 time[2][6];
    applib_time_struct *apptime[2];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Put time1 and time2 into a 2D array */
    apptime[0] = time1;
    apptime[1] = time2;
    for (i = 0; i< 2; i++)
    {
        time[i][0] = apptime[i]->nYear;
        time[i][1] = apptime[i]->nMonth;
        time[i][2] = apptime[i]->nDay;
        time[i][3] = apptime[i]->nHour;
        time[i][4] = apptime[i]->nMin;
        time[i][5] = apptime[i]->nSec;
    }

    /* Compare Year first, and then Month, ... */
    for (i = 0; i < 6; i++)
    {
        if (time[0][i] > time[1][i])
        {
            return 1;
        }
        else if (time[0][i] < time[1][i])
        {
            return -1;
        }
    }

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_current_system_time
 * DESCRIPTION
 *  The function is to get current system time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_get_current_system_time(applib_time_struct *current_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetDateTime(current_time);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_DATE_TIME,
                current_time->nYear,
                current_time->nMonth,
                current_time->nDay,
                current_time->nHour,
                current_time->nMin,
                current_time->nSec);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_update_channel_list
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_refresh_channel_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_num = 0;
    dtv_player_service_info_struct* info_ptr;
    S32 idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dtv_player_p->service_list_type == DTV_PLAYER_FAVORITE_LIST)
    {
        item_num = dtv_player_p->num_favorite_services;
    }
    else if (dtv_player_p->service_list_type == DTV_PLAYER_TOTAL_LIST)
    {
        item_num = dtv_player_p->num_services;
    }
    else
    {
        /* Don't need to refresh */
        return;
    }

    if (item_num > 0)
    {
        /* Set active channel name to cat265 */
        if (dtv_player_p->service_list_type == DTV_PLAYER_FAVORITE_LIST)
        {
            idx = mmi_dtv_player_total_to_favo_idx(dtv_player_p->setting.selected_channel);
        }
	else
        {
            idx = dtv_player_p->setting.selected_channel;
        }
        info_ptr = &dtv_player_p->services[idx];

        wgui_cat265_refresh_list(item_num, idx, MMI_FALSE);

        wgui_cat1008_set_preview_name_time(
            (U8*)info_ptr->program_name, (U8*)info_ptr->program_time);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_dummy_proc
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
mmi_ret mmi_dtv_player_dummy_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_date_time_update_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
void mmi_dtv_player_date_time_update_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_DATE_TIME_UPDATE_HDLR,
       dtv_player_p->has_esg_info);


    /* Mobile TV is not opened */
    if (KERNEL_STATE_IN(DTV_KERNEL_CLOSED) || KERNEL_STATE_IN(DTV_KERNEL_CLOSING))
    {
        return;
    }

    active_screen = mmi_frm_scrn_get_active_id();
    if (active_screen == SCR_ID_DTV_PLAYER_CHANNEL_LIST)
    {
        if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_CMMB &&
            dtv_player_p->has_esg_info == MMI_FALSE)
        {
            return;
        }

        if (dtv_player_p->num_services == 0)
        {
            return;
        }

        /* Update program info from ESG */
        mmi_dtv_player_assign_program_info();
        mmi_dtv_player_refresh_channel_list();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_check_and_copy_program_info
 * DESCRIPTION
 *  The function is to check
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_check_and_copy_program_info(mdi_mtv_program_info_struct* prog_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_mtv_program_info_struct *orig = &dtv_player_p->prog_info;
    U32 i;
    MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (prog_info->record_num != orig->record_num)
    {
        ret = MMI_TRUE;
    }

    for (i = 0; i < prog_info->record_num; i++)
    {
        if (prog_info->records[i].date != orig->records[i].date ||
            prog_info->records[i].time != orig->records[i].time ||
            prog_info->records[i].duration != orig->records[i].duration ||
            mmi_ucs2cmp((CHAR*)prog_info->records[i].title, (CHAR*)orig->records[i].title) != 0)
        {
            ret = MMI_TRUE;
            break;
        }
    }

    if (ret == MMI_TRUE)
    {
       kal_mem_cpy(&dtv_player_p->prog_info, prog_info, sizeof(mdi_mtv_program_info_struct));
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_update_program_info
 * DESCRIPTION
 *  The function is to update program info
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
void mmi_dtv_player_update_program_info(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dtv_player_service_info_struct *info_ptr;
    applib_time_struct start_time, end_time, offset_time, cur_time, tmp_time;
    MMI_BOOL updated = MMI_FALSE;
    U16 active_screen = mmi_frm_scrn_get_active_id();
    CHAR tmp[(MMI_DTV_TIME_STR_LENGTH + 1) <<1];
    S32 result, record_index = 0;
    mdi_mtv_program_info_struct *prog_info = &dtv_player_p->prog_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    info_ptr = mmi_dtv_player_get_active_channel_ptr();

    /* Get system time */
    mmi_dtv_player_get_current_system_time(&cur_time);

    /* Programe start time */
    mmi_dtv_player_compute_mjd_to_apptime(
        prog_info->records[0].date,
        prog_info->records[0].time,
        &start_time);

    /* Programe end time */
    mmi_dtv_player_compute_seconds_to_apptime(prog_info->records[0].duration, &offset_time);
    applib_dt_increase_time(&start_time, &offset_time, &end_time);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_PROGRAM_INFO,
            0,
            start_time.nYear,
            start_time.nMonth,
            start_time.nDay,
            start_time.nHour,
            start_time.nMin,
            start_time.nSec,
            prog_info->records[0].duration);

    /* Do error handing */
    if (start_time.nMonth > 12 || start_time.nDay > 31 || start_time.nHour > 24 ||
        start_time.nMin > 60 || start_time.nSec > 60)
    {
        return;
    }

    result = mmi_dtv_player_compare_apptime(
                &cur_time,
                &start_time);

    /* Check if need to use record[1] */
    if (prog_info->record_num == 2)
    {
        /* Programe start time */
        mmi_dtv_player_compute_mjd_to_apptime(
            prog_info->records[1].date,
            prog_info->records[1].time,
            &tmp_time);

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_PROGRAM_INFO,
                1,
                tmp_time.nYear,
                tmp_time.nMonth,
                tmp_time.nDay,
                tmp_time.nHour,
                tmp_time.nMin,
                tmp_time.nSec,
                prog_info->records[1].duration);

        result = mmi_dtv_player_compare_apptime(&cur_time, &tmp_time);
        if (result >= 0)
        {
            record_index = 1;

            /* Update Program start time and end time as record[1] */
            kal_mem_cpy(&start_time, &tmp_time, sizeof(applib_time_struct));

            /* Programe end time */
            mmi_dtv_player_compute_seconds_to_apptime(prog_info->records[record_index].duration, &offset_time);
            applib_dt_increase_time(&start_time, &offset_time, &end_time);
        }
    }

    /* Program time: hh:mm - hh:mm */
    kal_wsprintf((WCHAR *)tmp, "%02d:%02d-%02d:%02d",
                  start_time.nHour, start_time.nMin, end_time.nHour, end_time.nMin);

    if (mmi_ucs2cmp((CHAR *)info_ptr->program_time, tmp) != 0)
    {
        mmi_ucs2ncpy((CHAR *)info_ptr->program_time, (CHAR *)tmp, MMI_DTV_TIME_STR_LENGTH);
        updated = MMI_TRUE;
    }

    /* Program name */
    if (prog_info->records[record_index].title != NULL &&
        mmi_ucs2cmp((CHAR *)info_ptr->program_name, (CHAR *)prog_info->records[record_index].title) != 0)
    {
        mmi_ucs2ncpy((CHAR *)info_ptr->program_name, (CHAR *)prog_info->records[record_index].title, MMI_DTV_NAME_STR_LENGTH);
        updated = MMI_TRUE;
    }

    /* Program name and program time does not update */
    if (updated == MMI_FALSE)
    {
        return;
    }

    ASSERT(updated == MMI_TRUE);

    if (active_screen == SCR_ID_DTV_PLAYER_CHANNEL_LIST)
    {
        mmi_dtv_player_refresh_channel_list();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_assign_service_number
 * DESCRIPTION
 *  mobile tv player entry tab channel screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_assign_service_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (idx = 0; idx < dtv_player_p->num_services; idx ++)
    {
        dtv_player_p->services[idx].service_number = idx + 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_update_esg
 * DESCRIPTION
 *  The function is to update esg
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
void mmi_dtv_player_update_esg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen = mmi_frm_scrn_get_active_id();
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If abort scanning, or no service, no need to update esg */
    if (dtv_player_p->num_services == 0)
    {
        return;
    }

    ret = mmi_dtv_player_assign_service_info();

    if (ret == MMI_TRUE)
    {
        dtv_player_p->has_esg_info = MMI_TRUE;

        /* Assign has_preview_data */
        mmi_dtv_player_assign_if_have_preview_data();

        mmi_dtv_player_assign_program_info();
    }
    else /* No ESG */
    {
        dtv_player_p->has_esg_info = MMI_FALSE;
        return;
    }

    /* Update screen */
    if (active_screen == SCR_ID_DTV_PLAYER_CHANNEL_LIST)
    {
        mmi_dtv_player_refresh_channel_list();
    }
    else if (active_screen == SCR_ID_DTV_PLAYER_APP)
    {
        mmi_dtv_player_draw_osd();
        mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_enter_info_confirm_screen
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_enter_info_confirm_screen
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
void mmi_dtv_player_enter_info_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_scrn_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_CONFIRM,
                NULL,
                mmi_dtv_player_enter_info_confirm_screen,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    /* suspend background play */
    mdi_audio_suspend_background_play();

    /* Call enable before showCategory, call change after showCategory */
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();


    ShowCategory151Screen(
        STR_ID_DTV_PLAYER_APP_NAME,
        DTV_PLAYER_MENU_ICON,
        STR_GLOBAL_OK,
        0,
        0,
        0,
        (U8*)dtv_player_p->info_str_buffer,
        NULL,
        guiBuffer);


    SetLeftSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_check_eb_list
 * DESCRIPTION
 *  The function is to check eb list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_check_eb_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 msg_num;
    MDI_RESULT ret;
    MMI_BOOL direct_prompt = MMI_FALSE;
    mtv_eb_msg_current_network_struct *network_ptr = NULL;
    mdi_mtv_query_struct query = {0};
    U32 last_eb_id = 0, prompt_eb_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dtv_player_p->num_unread_ebs = 0;
    dtv_player_p->num_eb_msg = 0;

    ret = mdi_mtv_esg_query(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, EB_QUERY_MSG_CURRENT_NETWORK_LIST, &query);

    if (ret != MDI_RES_MTV_SUCCEED)
    {
        /* handle error case */
        return MMI_FALSE;
    }

    msg_num = 0;
    while(msg_num < MMI_DTV_MAX_EB_MSG)
    {
        network_ptr = NULL;
        ret = mdi_mtv_esg_get_result(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, EB_QUERY_MSG_CURRENT_NETWORK_LIST, (void **)&network_ptr);
        if (network_ptr == NULL)
        {
            break;
        }

        while (network_ptr != NULL)
        {
            /* Save EB list */
            if (network_ptr->is_new)
            {
                dtv_player_p->num_unread_ebs ++;

                last_eb_id = network_ptr->id;

                if (network_ptr->msg_level == 1 || network_ptr->msg_level == 2)
                {
                    direct_prompt = MMI_TRUE;
                    prompt_eb_id = network_ptr->id;
                }
            }

            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL4,
                      network_ptr->id, 
                      network_ptr->msg_level, 
                      network_ptr->is_new, 
                      dtv_player_p->num_unread_ebs, 
                      __LINE__);


            network_ptr = network_ptr->next_p;
            msg_num ++;

            /* Over the limitation */
            if (msg_num >= MMI_DTV_MAX_EB_MSG)
            {
                break;
            }
        }
    }

    if (direct_prompt)
    {
        dtv_player_p->selected_eb_id = prompt_eb_id;
    }
    else
    {
        dtv_player_p->selected_eb_id = last_eb_id;
    }

    dtv_player_p->num_eb_msg = msg_num;
    return direct_prompt;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_display_eb_notification
 * DESCRIPTION
 *  The function is to update emergency broadcast message
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
void mmi_dtv_player_display_eb_notification(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen = mmi_frm_scrn_get_active_id();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (active_screen != SCR_ID_DTV_PLAYER_APP)
    {
        return;
    }

    if (dtv_player_p->num_unread_ebs > 0)
    {
	    mmi_dtv_player_draw_eb_animation();
		/* Draw DLS scrolling text */
	    mmi_dtv_player_set_eb_dls_string();
	    if (mmi_dtv_player_is_flag_set(DTV_PLAYER_DISPLAY_EB_WARNING_STRING) &&
			mmi_ucs2strlen((CHAR *)dtv_player_p->label_str) != 0 &&
	        dtv_player_p->dynamic_label_state == DTV_PLAYER_DYNAMIC_LABEL_OFF)
	    {
	        mmi_dtv_player_draw_dynamic_label();
	    }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_set_eb_dls_string
 * DESCRIPTION
 *  The function is to update emergency broadcast message
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
void mmi_dtv_player_set_eb_dls_string(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_mem_set(dtv_player_p->label_str, 0, (MMI_DTV_TEXT_STR_LENGTH + 1)<<1);
    if (dtv_player_p->num_unread_ebs > 0)
    {
        mmi_ucs2ncpy((CHAR *)dtv_player_p->label_str,
                     (CHAR *)GetString(STR_ID_DTV_PLAYER_NOTIFY_UNREAD_EB),
                      MMI_DTV_TEXT_STR_LENGTH);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_update_eb_msg
 * DESCRIPTION
 *  The function is to update emergency broadcast message
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
void mmi_dtv_player_update_eb_msg(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen = mmi_frm_scrn_get_active_id();
    MMI_BOOL prompt_direct;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    prompt_direct = mmi_dtv_player_check_eb_list();

    if (prompt_direct)
    {
        /* Close the previous one first */
        mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_EB_MSG);
        mmi_dtv_player_entry_eb_msg_screen();
        return;
    }

    if (dtv_player_p->num_unread_ebs > 0)
    {
    	mmi_dtv_player_set_flag(DTV_PLAYER_DISPLAY_EB_WARNING_STRING);
	    mmi_dtv_player_display_eb_notification();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_construct_eb_msg
 * DESCRIPTION
 *  mobile tv player construct eb msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_dtv_player_construct_eb_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mtv_eb_msg_current_network_struct *network_ptr = NULL;
    mdi_mtv_query_struct query = {0};
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    query.id = dtv_player_p->selected_eb_id;

    ret = mdi_mtv_esg_query(
            dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, EB_QUERY_MSG_CURRENT_NETWORK_DETAIL, &query);

    if (ret != MDI_RES_MTV_SUCCEED)
    {
        /* handle error case */
        return MMI_FALSE;
    }

    ret = mdi_mtv_esg_get_result(
            dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, EB_QUERY_MSG_CURRENT_NETWORK_DETAIL, (void **)&network_ptr);
    if (network_ptr == NULL)
    {
        return 0;
    }

    if(network_ptr->is_new)
    {
        dtv_player_p->num_unread_ebs --;
    }
    /* Text */
    mmi_ucs2cpy(dtv_player_p->detail_buf, (CHAR*)network_ptr->text);
    mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");

    /* Receive time */
    mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_RECIEVE_TIME));
    mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");

    mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR*)network_ptr->receive_time);
    mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");

    ASSERT(mmi_ucs2strlen((CHAR *) dtv_player_p->detail_buf) * 2 + 2 <= MMI_DTV_PLAYER_DETAIL_BUF_SIZE);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL4,
        dtv_player_p->selected_eb_id, network_ptr->msg_level, network_ptr->is_new,dtv_player_p->num_unread_ebs, __LINE__);

    return network_ptr->msg_level;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_exit_eb_msg_screen
 * DESCRIPTION
 *  mobile tv player exit channel detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_exit_eb_msg_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_dtv_player_free_detail_screen_memory();
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
mmi_ret mmi_dtv_player_delete_eb_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert;
	mmi_ret result = MMI_RET_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id != EVT_ID_ALERT_QUIT)
    {
        return MMI_RET_OK;
    }
    alert = (mmi_alert_result_evt_struct *)evt;
    if (alert->result == MMI_ALERT_CNFM_YES)
    {
        mmi_dtv_player_delete_eb();
    }
    else if (alert->result == MMI_ALERT_CNFM_NO)
    {
        mmi_frm_scrn_close_active_id();
    }
	else
	{
		result = MMI_RET_ERR;
    }
	return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_delete_eb_confirm
 * DESCRIPTION
 *  mobile tv player entry emergency boradcast message screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_delete_eb_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = mmi_dtv_player_delete_eb_proc;
    arg.f_auto_map_empty_softkey = MMI_FALSE;
#if !defined(__MMI_FTE_SUPPORT__)
    arg.f_msg_icon = MMI_FALSE;
#endif

    mmi_confirm_display(
        (WCHAR *)GetString(STR_ID_DTV_PLAYER_DELETE_ASK),
        MMI_EVENT_QUERY,
        &arg);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_eb_msg_screen
 * DESCRIPTION
 *  mobile tv player entry emergency boradcast message screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_eb_msg_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 img_id;
    U8 msg_level;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_EB_MSG,
                mmi_dtv_player_exit_eb_msg_screen,
                mmi_dtv_player_entry_eb_msg_screen,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    /* suspend background play */
    mdi_audio_suspend_background_play();

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();


    /* Allocate detail buffer */
    mmi_dtv_player_alloc_detail_screen_memory();

    msg_level = mmi_dtv_player_construct_eb_msg();
    if (msg_level < 1 || msg_level > 4)
    {
        msg_level = 4;
    }
    img_id = IMG_ID_DTV_PLAYER_MENU_EB_L1 + msg_level - 1;

    ShowCategory74Screen(
        STR_ID_DTV_PLAYER_EMERGENCY_BROADCAST,
        img_id,
        STR_GLOBAL_DELETE,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) dtv_player_p->detail_buf,
        mmi_ucs2strlen((CHAR *) dtv_player_p->detail_buf),
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_dtv_player_delete_eb_confirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_eb_msg_highlight_hdlr
 * DESCRIPTION
 *  mobile tv player eb msg highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_eb_msg_highlight_hdlr(S32 index)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dtv_player_eb_msg_struct *eb_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    eb_ptr = &dtv_player_p->eb_msg[index];

    dtv_player_p->selected_eb_id = eb_ptr->id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_ebl_option_screen
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
 void mmi_dtv_player_entry_ebl_option_screen(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->eb_option_menu_gid =
        cui_menu_create(
            GRP_ID_DTV_PLAYER,
            CUI_MENU_SRC_TYPE_RESOURCE,
            CUI_MENU_TYPE_OPTION,
            MENU_ID_DTV_PLAYER_EBL_OPTION,
            MMI_FALSE,
            NULL);
    cui_menu_run(dtv_player_p->eb_option_menu_gid);
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
S32 mmi_dtv_player_get_async_eb_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, eb_idx;
    U8 level;
    dtv_player_eb_msg_struct *eb_ptr;
    WCHAR num_str[10];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < num_item; i ++)
    {
        eb_idx = start_indx + i;
        ASSERT(eb_idx < dtv_player_p->num_eb_msg);
        eb_ptr =  &dtv_player_p->eb_msg[eb_idx];

        mmi_ucs2cpy(
            (CHAR*)menuData[i].item_list[0],
            (CHAR*)GetString(STR_ID_DTV_PLAYER_EMERGENCY_BROADCAST));
        kal_wsprintf(num_str, "%d", eb_ptr->id);
        mmi_ucs2cat((CHAR*)menuData[i].item_list[0], (CHAR*)num_str);

        /* yyyy-mm-dd HH:MM:SS */
        mmi_ucs2cpy((CHAR*) menuData[i].item_list[1], (CHAR*) eb_ptr->receive_time);

        if (eb_ptr->msg_level < 1 || eb_ptr->msg_level > 4)
        {
            level = 4;
        }
        else
        {
            level = eb_ptr->msg_level;
        }
        menuData[i].image_list[0] = (PU8)GetImage(IMG_ID_DTV_PLAYER_MENU_EB_L1 + level - 1);

        if (eb_ptr->is_new)
        {
            menuData[i].image_list[1] = (PU8)GetImage(IMG_ID_DTV_PLAYER_MENU_UNREAD);
        }
        else
        {
            menuData[i].image_list[1] = (PU8)GetImage(IMG_ID_DTV_PLAYER_MENU_READ);
        }
    }

    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_query_eb_msg_list
 * DESCRIPTION
 *  The function is to query emergency broadcast message list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_query_eb_msg_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 eb_msg_index;
    MDI_RESULT ret;
    mtv_eb_msg_current_network_struct *network_ptr = NULL;
    dtv_player_eb_msg_struct *eb_msg_ptr;
    mdi_mtv_query_struct query = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(dtv_player_p->eb_msg, 0, MMI_DTV_MAX_EB_MSG * sizeof(dtv_player_eb_msg_struct));
    dtv_player_p->num_eb_msg = 0;
    dtv_player_p->num_unread_ebs = 0;

    ret = mdi_mtv_esg_query(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, EB_QUERY_MSG_CURRENT_NETWORK_LIST, &query);

    if (ret != MDI_RES_MTV_SUCCEED)
    {
        /* handle error case */
        return;
    }

    eb_msg_index = 0;
    while(eb_msg_index < MMI_DTV_MAX_EB_MSG)
    {
        network_ptr = NULL;
        ret = mdi_mtv_esg_get_result(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, EB_QUERY_MSG_CURRENT_NETWORK_LIST, (void **)&network_ptr);
        if (network_ptr == NULL)
        {
            break;
        }

        while (network_ptr != NULL)
        {
            eb_msg_ptr = &(dtv_player_p->eb_msg[eb_msg_index]);

            /* Save EB list */
            eb_msg_ptr->id = network_ptr->id;
            eb_msg_ptr->is_new = network_ptr->is_new;
            eb_msg_ptr->msg_level = network_ptr->msg_level;
            mmi_ucs2ncpy((CHAR *)eb_msg_ptr->text, (CHAR*)network_ptr->text, MMI_DTV_TEXT_STR_LENGTH);
            mmi_ucs2ncpy((CHAR *)eb_msg_ptr->receive_time, (CHAR*)network_ptr->receive_time, MMI_DTV_DATE_TIME_STR_LENGTH);

            if (eb_msg_ptr->is_new)
            {
                dtv_player_p->num_unread_ebs ++;
            }

            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL4,
                eb_msg_ptr->id, eb_msg_ptr->msg_level, eb_msg_ptr->is_new, dtv_player_p->num_unread_ebs, __LINE__);


            network_ptr = network_ptr->next_p;
            eb_msg_index ++;

            /* Over the limitation */
            if (eb_msg_index >= MMI_DTV_MAX_EB_MSG)
            {
                break;
            }
        }
    }

    dtv_player_p->num_eb_msg = eb_msg_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_exit_eb_msg_list_screen
 * DESCRIPTION
 *  mobile tv player exit eb msg list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_exit_eb_msg_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dtv_player_p->eb_msg != NULL)
    {
    #ifdef __COSMOS_MMI_PACKAGE__
        applib_asm_free_r(GRP_ID_DTV_PLAYER, (void *)dtv_player_p->eb_msg);
    #else /* __COSMOS_MMI_PACKAGE__ */    
        mmi_frm_scrmem_free((void *) dtv_player_p->eb_msg);
    #endif  /* __COSMOS_MMI_PACKAGE__ */         
 
        dtv_player_p->eb_msg = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_eb_msg_list_screen
 * DESCRIPTION
 *  mobile tv player entry eb message list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_eb_msg_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 error_flag;
    WCHAR *lsk_str;
    PU8 lsk_img;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_OPTION_EB_MSG_LIST,
                mmi_dtv_player_exit_eb_msg_list_screen,
                mmi_dtv_player_entry_eb_msg_list_screen,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    /* Emergency broadcast message */
    ASSERT(sizeof(dtv_player_eb_msg_struct) <= MMI_DTV_MAX_EB_MSG_STRUCTURE_SIZE);

#ifdef __COSMOS_MMI_PACKAGE__
                        
    dtv_player_p->eb_msg = (dtv_player_eb_msg_struct *) applib_asm_alloc_nc_r(GRP_ID_DTV_PLAYER, MMI_DTV_MAX_EB_MSG * sizeof(dtv_player_eb_msg_struct));
#else /* __COSMOS_MMI_PACKAGE__ */

    dtv_player_p->eb_msg = (dtv_player_eb_msg_struct*) mmi_frm_scrmem_alloc(MMI_DTV_MAX_EB_MSG * sizeof(dtv_player_eb_msg_struct));
#endif
    
    ASSERT(dtv_player_p->eb_msg != NULL);
    memset(dtv_player_p->eb_msg, 0, MMI_DTV_MAX_EB_MSG * sizeof(dtv_player_eb_msg_struct));

    /* suspend background play */
    mdi_audio_suspend_background_play();

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    RegisterHighlightHandler(mmi_dtv_player_eb_msg_highlight_hdlr);

    mmi_dtv_player_query_eb_msg_list();

    if (dtv_player_p->num_eb_msg > 0)
    {
        lsk_str = (WCHAR*)GetString(STR_GLOBAL_OPTIONS);
        lsk_img = (U8*)GetImage(IMG_GLOBAL_OK);

        /* Call enable before showCategory, call change after showCategory */
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
    else
    {
        lsk_str = NULL;
        lsk_img = NULL;
    }


    wgui_cat1021_show(
        (WCHAR*)GetString(STR_ID_DTV_PLAYER_EMERGENCY_BROADCAST),
        (U8*)GetImage(DTV_PLAYER_MENU_ICON),
        lsk_str,
        lsk_img,
        (WCHAR*)GetString(STR_GLOBAL_BACK),
        (U8*)GetImage(IMG_GLOBAL_BACK),
        dtv_player_p->num_eb_msg,
        mmi_dtv_player_get_async_eb_items,
        NULL,
        0,
        guiBuffer,
        &error_flag);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

    if (dtv_player_p->num_eb_msg > 0)
    {
        SetLeftSoftkeyFunction(mmi_dtv_player_entry_ebl_option_screen, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_dtv_player_entry_eb_msg_screen, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_check_time_to_alarm_status
 * DESCRIPTION
 *  mobile tv player play selected content add this function for resolve issue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_dtv_player_check_time_to_alarm_status(applib_time_struct *target_time, WCHAR *date, WCHAR *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR cur_str[20], start_str[20] = {0}, end_str[20] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(cur_str, "%04d-%02d-%02d %02d:%02d",
        target_time->nYear, target_time->nMonth, target_time->nDay, target_time->nHour, target_time->nMin);

    mmi_ucs2ncpy((CHAR*)start_str, (CHAR*)date, 10); /* yyyy-mm-dd */
    mmi_ucs2cat((CHAR*)start_str, (CHAR*)L" ");
    mmi_ucs2ncat((CHAR*)start_str, (CHAR*)time, 5); /* HH:MM-HH:MM */


    mmi_ucs2ncpy((CHAR*)end_str, (CHAR*)date, 10);
    mmi_ucs2cat((CHAR*)end_str, (CHAR*)L" ");
    mmi_ucs2ncat((CHAR*)end_str, (CHAR*)&time[6], 5);


    /* Not yet */
    if (mmi_ucs2cmp((CHAR *)cur_str, (CHAR *)start_str) < 0)
    {
        return 1;
    }
    /* Out of date */
    else if (mmi_ucs2cmp((CHAR *)cur_str, (CHAR *)end_str) > 0)
    {
        return -1;
    }
    /* Out of date: start time < end time = current time */
    else if (mmi_ucs2cmp((CHAR *)cur_str, (CHAR *)end_str) == 0 &&
             mmi_ucs2cmp((CHAR *)start_str, (CHAR *)end_str) != 0)
    {
        return -1;
    }
    else
    {
    	/* playing not alarm two alarm: one is 07:00 - 07:30 second: 07:05 - 07:30*/
        if (mmi_ucs2cmp((CHAR *)cur_str, (CHAR *)start_str) > 0)
        {
            return -1;
        }
        /* OK */
        return 0;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_check_time_status
 * DESCRIPTION
 *  mobile tv player play selected content
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_dtv_player_check_time_status(applib_time_struct *target_time, WCHAR *date, WCHAR *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR cur_str[20], start_str[20] = {0}, end_str[20] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(cur_str, "%04d-%02d-%02d %02d:%02d",
        target_time->nYear, target_time->nMonth, target_time->nDay, target_time->nHour, target_time->nMin);

    mmi_ucs2ncpy((CHAR*)start_str, (CHAR*)date, 10); /* yyyy-mm-dd */
    mmi_ucs2cat((CHAR*)start_str, (CHAR*)L" ");
    mmi_ucs2ncat((CHAR*)start_str, (CHAR*)time, 5); /* HH:MM-HH:MM */


    mmi_ucs2ncpy((CHAR*)end_str, (CHAR*)date, 10);
    mmi_ucs2cat((CHAR*)end_str, (CHAR*)L" ");
    mmi_ucs2ncat((CHAR*)end_str, (CHAR*)&time[6], 5);


    /* Not yet */
    if (mmi_ucs2cmp((CHAR *)cur_str, (CHAR *)start_str) < 0)
    {
        return 1;
    }
    /* Out of date */
    else if (mmi_ucs2cmp((CHAR *)cur_str, (CHAR *)end_str) > 0)
    {
        return -1;
    }
    /* Out of date: start time < end time = current time */
    else if (mmi_ucs2cmp((CHAR *)cur_str, (CHAR *)end_str) == 0 &&
             mmi_ucs2cmp((CHAR *)start_str, (CHAR *)end_str) != 0)
    {
        return -1;
    }
    else
    {
        /* OK */
        return 0;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_play_selected_content
 * DESCRIPTION
 *  mobile tv player play selected content
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_play_selected_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL check_time = MMI_TRUE;
    S32 i, status;
    applib_time_struct cur_time;
    dtv_player_schedule_info_struct *selected_p;
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    selected_p = &dtv_player_p->selected_content;

    for (i = 0; i < dtv_player_p->num_services; i ++)
    {
        if (selected_p->service_id == dtv_player_p->services[i].service_id)
        {
            break;
        }
    }

    if (i >= dtv_player_p->num_services)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_TRC_DTV_SERVICE_ID,
            selected_p->service_id, -1, __LINE__);

        mmi_dtv_player_display_popup(
            STR_ID_DTV_PLAYER_NOTIFY_CHANNEL_NOT_FOUND, MMI_EVENT_FAILURE);
        return;
    }

    mmi_dtv_player_set_selected_service(i);

    /* Follow UI spec, in order to display subscribe confirm directly */
    if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_MBBMS_READY)
    {
        if (dtv_player_p->services[i].service_flags & MEDIA_MTV_SERVICE_UNSUBSCRIBED)
        {
            check_time = MMI_FALSE;
        }
    }

    if (check_time)
    {
        /* Check if display time warning popup */
        mmi_dtv_player_get_current_system_time(&cur_time);
        status = mmi_dtv_player_check_time_status(&cur_time, selected_p->date, selected_p->time);
        if (status < 0)
        {
            str_id = STR_ID_DTV_PLAYER_TIME_WARNING_OVER;
        }
        else if (status > 0)
        {
            str_id = STR_ID_DTV_PLAYER_TIME_WARNING_NOT_YET;
        }
    }

    /* Avoid re-entry */
    mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_APP);

    /* Display time warning */
    if (str_id != 0)
    {
        if (!mmi_frm_scrn_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_DUMMY,
                NULL,
                mmi_dtv_player_entry_app_screen,
                MMI_FRM_UNKNOW_SCRN))
        {
            return;
        }
        ShowCategoryDummyScreen();
        mmi_dtv_player_display_popup(str_id, MMI_EVENT_FAILURE);
    }
    else
    {
        /* Enter play screen */
        mmi_dtv_player_entry_app_screen();
    }

    /* Close screens */
    mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_PROGRAM_LIST);
    mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_PROGRAM_DETAIL);
    mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_SEARCH_RESULT);
    cui_inline_close(dtv_player_p->sp_inline_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_exit_program_detail_screen
 * DESCRIPTION
 *  mobile tv player exit program detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_exit_program_detail_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_dtv_player_free_detail_screen_memory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_entry_program_detail_screen
 * DESCRIPTION
 *  mobile tv player entry program detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_entry_program_detail_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U32 icon_pos = 0, detail_len;
    U8 *icon_ptr = NULL;
    HILITE_STR *hilite_str = NULL;
    U16 hilite_num = 0;
    void (*hilite_cb)(S32) = NULL;
    void (*click_cb)(S32) = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                GRP_ID_DTV_PLAYER,
                SCR_ID_DTV_PLAYER_PROGRAM_DETAIL,
                mmi_dtv_player_exit_program_detail_screen,
                mmi_dtv_player_entry_program_detail_screen,
                MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    /* suspend background play */
    mdi_audio_suspend_background_play();

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();


    /* Allocate detail buffer */
    mmi_dtv_player_alloc_detail_screen_memory();

    if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_CMMB)
    {
        mmi_dtv_player_query_cmmb_content_details();
    }
    else /* MBBMS or MBBMS ready */
    {
        mmi_dtv_player_query_mbbms_content_details();
        if (dtv_player_p->selected_content.has_inter_data)
        {
            icon_ptr = (PU8)GetImage(IMG_ID_DTV_PLAYER_MENU_INTE_DATA);

            hilite_num = 1;

            kal_mem_set(&dtv_player_p->hilite_str, 0, sizeof(HILITE_STR));
            hilite_str = &dtv_player_p->hilite_str;
            hilite_str->hilite_type = EDITOR_HILITE_URL;
            hilite_str->length = mmi_ucs2strlen(GetString(STR_ID_DTV_CHECK_INTER_SERVICE));
            detail_len = mmi_ucs2strlen(dtv_player_p->detail_buf) - hilite_str->length;
            hilite_str->str_addr = dtv_player_p->detail_buf + detail_len * 2;
            icon_pos = detail_len;
		#ifdef __MBBMS_INTER__
            hilite_cb = mmi_dtv_player_pd_hilite_callback;
            click_cb = mmi_dtv_player_pd_click_callback;
		#endif /* __MBBMS_INTER__ */
        }
    }

    /* Call enable before showCategory, call change after showCategory */
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    wgui_cat3006_show(
        (WCHAR *) GetString(STR_ID_DTV_PLAYER_PROGRAM_DETAILS),
		(PU8)GetImage(DTV_PLAYER_MENU_ICON),
        (WCHAR *) GetString(STR_GLOBAL_OPTIONS),
        (PU8)GetImage(IMG_GLOBAL_OPTIONS),
        (WCHAR *) GetString(STR_GLOBAL_BACK),
        (PU8)GetImage(IMG_GLOBAL_BACK),
        (PU8) dtv_player_p->detail_buf,
        guiBuffer,
        (UI_string_type)dtv_player_p->selected_content.name,
        (UI_string_type)dtv_player_p->selected_content.time,
        (PU8)GetImage(IMG_ID_DTV_PLAYER_PREVIEW_BG),
        icon_pos,
        icon_ptr,
        hilite_str,
        hilite_num,
        hilite_cb,
        click_cb);

    SetLeftSoftkeyFunction(mmi_dtv_player_entry_pd_option_screen, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_dtv_player_play_selected_content, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_gen_separate_string
 * DESCRIPTION
 *  The function is to delete favorite
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_gen_separate_string(WCHAR *str, WCHAR *insert_str, WCHAR *insert_str2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len;
    WCHAR *out, *out2;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* generate popup string */
    kal_mem_set(dtv_player_p->info_str_buffer, 0, sizeof(dtv_player_p->info_str_buffer));

    out = (WCHAR*)mmi_ucs2chr((CHAR*)str, L'%');
    if (out == NULL)
    {
        return;
    }

    len = out - str;
    mmi_ucs2ncpy(
        (CHAR*)dtv_player_p->info_str_buffer, (CHAR*)str, len);
    mmi_ucs2cat((CHAR*)dtv_player_p->info_str_buffer, (CHAR*)insert_str);

    if (insert_str2 == NULL)
    {
        mmi_ucs2cat((CHAR*)dtv_player_p->info_str_buffer, (CHAR*)&out[1]);
    }
    else
    {
        out2 = (WCHAR*)mmi_ucs2chr((CHAR*)&out[1], L'%');
        if (out2 != NULL)
        {
            len = out2 - 1 - out;
            ASSERT(len >= 0);
            mmi_ucs2ncat((CHAR*)dtv_player_p->info_str_buffer, (CHAR*)&out[1], len);
            mmi_ucs2cat((CHAR*)dtv_player_p->info_str_buffer, (CHAR*)insert_str2);
            mmi_ucs2cat((CHAR*)dtv_player_p->info_str_buffer, (CHAR*)&out2[1]);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_add_favorite
 * DESCRIPTION
 *  The function is to delete favorite
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_add_favorite(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 service_id = 0;
    MDI_RESULT ret;
    dtv_player_service_info_struct *info_ptr, *tmp_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    info_ptr = &dtv_player_p->services[idx];
    service_id = info_ptr->service_id;
    ret = mdi_mtv_add_favorite(dtv_player_p->mtv_handle, MDI_MTV_FAVO_CHANNEL, service_id, NULL);
    if (ret != MDI_RES_MTV_SUCCEED)
    {
        mmi_dtv_player_display_failure_popup(ret);
        return;
    }

    if (dtv_player_p->num_favorite_services == 0)
    {
        dtv_player_p->head_of_favorite_service = info_ptr;
        info_ptr->next = NULL;
    }
    else
    {
        tmp_ptr = dtv_player_p->head_of_favorite_service;
        ASSERT(tmp_ptr != NULL);
        while(tmp_ptr)
        {
            if (tmp_ptr->service_number > info_ptr->service_number ||
                tmp_ptr->next == NULL)
            {
                break;
            }
            tmp_ptr = tmp_ptr->next;
            ASSERT(tmp_ptr != NULL);
        }

        /* Insert as the next of tmp_ptr */
        if (tmp_ptr->service_number < info_ptr->service_number)
        {
            if (tmp_ptr->next)
            {
                info_ptr->next = tmp_ptr->next;
                tmp_ptr->next->prev = info_ptr;
                info_ptr->prev = tmp_ptr;
                tmp_ptr->next = info_ptr;
            }
            else
            {
                tmp_ptr->next = info_ptr;
                info_ptr->prev = tmp_ptr;
                info_ptr->next = NULL;
            }
        }
        else /* Insert as the prev of tmp_ptr */
        {
            if (tmp_ptr == dtv_player_p->head_of_favorite_service)
            {
                info_ptr->next = tmp_ptr;
                tmp_ptr->prev = info_ptr;
                dtv_player_p->head_of_favorite_service = info_ptr;
            }
            else
            {
                info_ptr->next = tmp_ptr;
                info_ptr->prev = tmp_ptr->prev;
                info_ptr->prev->next = info_ptr;
                info_ptr->next->prev = info_ptr;
            }
        }
    }

    info_ptr->is_favorite = MMI_TRUE;
    dtv_player_p->num_favorite_services ++;

    ClearInputEventHandler(MMI_DEVICE_KEY);

    /* generate popup string */
    mmi_dtv_player_gen_separate_string(
        (WCHAR*)GetString(STR_ID_DTV_PLAYER_ADD_FAVO_SUCCEED),
        (WCHAR*)info_ptr->service_name, NULL);
    mmi_dtv_player_display_popup_str(
        dtv_player_p->info_str_buffer,
        MMI_EVENT_SUCCESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_delete_favorite
 * DESCRIPTION
 *  The function is to delete favorite
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_delete_favorite(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 service_id;
    MDI_RESULT ret;
    dtv_player_service_info_struct *info_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    info_ptr = &dtv_player_p->services[idx];
    service_id = info_ptr->service_id;

    ret = mdi_mtv_delete_favorite(dtv_player_p->mtv_handle, MDI_MTV_FAVO_CHANNEL, service_id, NULL);
    if (ret != MDI_RES_MTV_SUCCEED)
    {
        mmi_dtv_player_display_failure_popup(ret);
        return;
    }

    info_ptr->is_favorite = MMI_FALSE;
    dtv_player_p->num_favorite_services --;

    /* If favorite list has no service */
    if (dtv_player_p->num_favorite_services == 0)
    {
        dtv_player_p->head_of_favorite_service = NULL;
    }
    else
    {
        if (info_ptr == dtv_player_p->head_of_favorite_service)
        {
            dtv_player_p->head_of_favorite_service = info_ptr->next;
            info_ptr->next->prev = dtv_player_p->head_of_favorite_service;
        }
        else
        {
            info_ptr->prev->next = info_ptr->next;
            if (info_ptr->next)
            {
                info_ptr->next->prev = info_ptr->prev;
            }
        }
    }

    ClearInputEventHandler(MMI_DEVICE_KEY);

    /* generate popup string */
    mmi_dtv_player_gen_separate_string(
        (WCHAR*)GetString(STR_ID_DTV_PLAYER_DEL_FAVO_SUCCEED),
        (WCHAR*)info_ptr->service_name, NULL);
    mmi_dtv_player_display_popup_str(
        dtv_player_p->info_str_buffer,
        MMI_EVENT_SUCCESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_delete_eb
 * DESCRIPTION
 *  The function is to delete emergency broadcast
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_delete_eb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mdi_mtv_delete_favorite(dtv_player_p->mtv_handle, 
                                  MDI_MTV_FAVO_EB, 
                                  dtv_player_p->selected_eb_id, 
                                  NULL);
    if (ret != MDI_RES_MTV_SUCCEED)
    {
        mmi_dtv_player_display_failure_popup(ret);
    }
    else
    {
        dtv_player_p->num_eb_msg --;
        mmi_dtv_player_display_popup(STR_GLOBAL_DELETED, MMI_EVENT_SUCCESS);
    }
    /* Close msg screen */
    mmi_frm_scrn_close(GRP_ID_DTV_PLAYER, SCR_ID_DTV_PLAYER_EB_MSG);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_add_reminder
 * DESCRIPTION
 *  The function is to add reminder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_add_reminder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ret = mdi_mtv_add_favorite(dtv_player_p->mtv_handle, MDI_MTV_FAVO_CONTENT, 0, dtv_player_p->selected_content.cid);
    if (ret != MDI_RES_MTV_SUCCEED)
    {
        mmi_dtv_player_display_failure_popup(ret);
        return;
    }

    dtv_player_p->selected_content.if_reminder = MMI_TRUE;
    ClearInputEventHandler(MMI_DEVICE_KEY);

    if (dtv_player_p->setting.pro_remind_time != DTV_PLAYER_PROG_REMIND_0)
    {
        mmi_dtv_player_update_alarm();
    }

    mmi_dtv_player_display_popup(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_cancel_reminder
 * DESCRIPTION
 *  The function is to cancel reminder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_cancel_reminder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ret = mdi_mtv_delete_favorite(dtv_player_p->mtv_handle, MDI_MTV_FAVO_CONTENT, 0, dtv_player_p->selected_content.cid);
    if (ret != MDI_RES_MTV_SUCCEED)
    {
        mmi_dtv_player_display_failure_popup(ret);
        return;
    }
    dtv_player_p->selected_content.if_reminder = MMI_FALSE;

    ClearInputEventHandler(MMI_DEVICE_KEY);

    if (dtv_player_p->setting.pro_remind_time != DTV_PLAYER_PROG_REMIND_0)
    {
        mmi_dtv_player_update_alarm();
    }

    mmi_dtv_player_display_popup(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_mbbms_service_info
 * DESCRIPTION
 *  The function is to get service info to service list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_get_mbbms_service_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 service_index;
    CHAR * unknown_name;
    mbbms_sg_query_service_struct *service_ptr = NULL;
    dtv_player_service_info_struct *info_ptr;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    while(1)
    {
        service_ptr = NULL;
        mdi_mtv_esg_get_result(dtv_player_p->mtv_handle, 
			                   MEDIA_MTV_ESG_SOURCE_DEFAULT, 
			                   ESG_QUERY_SERVICES_ALL, 
			                   (void **)&service_ptr);
        if (service_ptr == NULL)
        {
            break;
        }

        while (service_ptr != NULL)
        {
            /* Find the service */
            for (service_index = 0; service_index < dtv_player_p->num_services; service_index++)
            {
                info_ptr = &(dtv_player_p->services[service_index]);
                if (info_ptr->service_id == service_ptr->sid)
                {
                    break;
                }
            }

            /* found out */
            if (service_index < dtv_player_p->num_services)
            {
                info_ptr = &(dtv_player_p->services[service_index]);

                /* Service type */
                if (service_ptr->type == 1) /* TV */
                {
                    info_ptr->service_type = MDI_MTV_SERVICE_TYPE_DIGITAL_TV;
                }
                else if (service_ptr->type == 2) /* Radio */
                {
                    info_ptr->service_type = MDI_MTV_SERVICE_TYPE_DIGITAL_RADIO;
                }

                /* Service name */
                if (mmi_ucs2strlen((CHAR *)service_ptr->name) == 0)
                {
                    unknown_name = GetString((U16)STR_ID_DTV_PLAYER_NOTIFY_CHANNAL_NAME_UNKNOWN);
                    mmi_ucs2ncpy((CHAR *)info_ptr->service_name, unknown_name, MMI_DTV_NAME_STR_LENGTH);
                }
                else
                {
                    mmi_ucs2ncpy((CHAR *)info_ptr->service_name, (CHAR *)service_ptr->name, MMI_DTV_NAME_STR_LENGTH);
                }

                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL4,
                    info_ptr->service_number,
                    info_ptr->service_id,
                    info_ptr->service_type,
                    info_ptr->is_favorite,
                    __LINE__);
                result = MMI_TRUE;
            }

            service_ptr = service_ptr->next_p;
        }
    }

    /* MMI_FALSE: there is no matched service */
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_cmmb_service_info
 * DESCRIPTION
 *  The function is to get service info to service list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_get_cmmb_service_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 service_index;
    CHAR * unknown_name;
    esg_query_service_struct *service_ptr = NULL;
    dtv_player_service_info_struct *info_ptr;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    while(1)
    {
        service_ptr = NULL;
        mdi_mtv_esg_get_result(dtv_player_p->mtv_handle, 
			                   MEDIA_MTV_ESG_SOURCE_DEFAULT, 
			                   ESG_QUERY_SERVICES_ALL, 
			                   (void **)&service_ptr);
        if (service_ptr == NULL)
        {
            break;
        }

        while (service_ptr != NULL)
        {
            /* Find the service */
            for (service_index = 0; service_index < dtv_player_p->num_services; service_index++)
            {
                info_ptr = &(dtv_player_p->services[service_index]);
                if (info_ptr->service_id == service_ptr->ref_id)
                {
                    break;
                }
            }

            /* found out */
            if (service_index < dtv_player_p->num_services)
            {
                info_ptr = &(dtv_player_p->services[service_index]);

                /* Service type */
                if (service_ptr->class == 1) /* TV */
                {
                    info_ptr->service_type = MDI_MTV_SERVICE_TYPE_DIGITAL_TV;
                }
                else if (service_ptr->class == 2) /* Radio */
                {
                    info_ptr->service_type = MDI_MTV_SERVICE_TYPE_DIGITAL_RADIO;
                }

                /* Service name */
                if (mmi_ucs2strlen((CHAR *)service_ptr->name) == 0)
                {
                    unknown_name = GetString((U16)STR_ID_DTV_PLAYER_NOTIFY_CHANNAL_NAME_UNKNOWN);
                    mmi_ucs2ncpy((CHAR *)info_ptr->service_name, unknown_name, MMI_DTV_NAME_STR_LENGTH);
                }
                else
                {
                    mmi_ucs2ncpy((CHAR *)info_ptr->service_name, (CHAR *)service_ptr->name, MMI_DTV_NAME_STR_LENGTH);
                }

                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL4,
                    info_ptr->service_number,
                    info_ptr->service_id,
                    info_ptr->service_type,
                    info_ptr->is_favorite,
                    __LINE__);

				#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
				info_ptr->frequency = service_ptr->fpid;
				#endif
				
                result = MMI_TRUE;
            }

            service_ptr = service_ptr->next_p;
        }
    }

    /* MMI_FALSE: there is no matched service */
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_assign_service_info
 * DESCRIPTION
 *  The function is to assign service info to service list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_assign_service_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT mdi_ret;
    MMI_BOOL ret;
    mdi_mtv_query_struct query = {0};
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_ASSIGN_SERVICE_INFO);


    query.lang_type = dtv_player_p->language_type;
    mdi_ret = mdi_mtv_esg_query(dtv_player_p->mtv_handle, 
		                        MEDIA_MTV_ESG_SOURCE_DEFAULT, 
		                        ESG_QUERY_SERVICES_ALL, 
		                        &query);

    if (mdi_ret != MDI_RES_MTV_SUCCEED)
    {
        /* handle error case */
        return MMI_FALSE;
    }

    if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_CMMB)
    {
        ret = mmi_dtv_player_get_cmmb_service_info();
    }
    else /* MBBMS or MBBMS ready */
    {
        /* Otherwise, query and get_result won't be pair */
        ret = mmi_dtv_player_get_mbbms_service_info();
    }

    /* MMI_FALSE: there is no matched service */
    return ret;
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
 void mmi_dtv_player_copy_eb_region(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_layer_struct *layer;
    S32 offset_x, offset_y, width, height;
    dtv_player_osd_text_struct *title_p;
    gdi_rect_struct dest_clip = {0, 0, LCD_WIDTH-1, LCD_HEIGHT-1};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Only normal screen needs to copy */
    if (dtv_player_p->ui_rotate != MMI_FRM_SCREEN_ROTATE_0)
    {
        return;
    }

    /* There is no EB animation. So no need to copy */
    if (GDI_NULL_HANDLE == dtv_player_p->eb_amin_handle)
    {
        return;
    }

    layer = (gdi_layer_struct *) dtv_player_p->osd_layer_handle;
    title_p = &dtv_player_p->active_osd_cntx_p->title;
    
    offset_x = 0;
    offset_y = title_p->offset_y;
    width = LCD_WIDTH;
    height = title_p->height;
        
    
    
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


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_eb_animation_draw_after_hdlr
 * DESCRIPTION
 *  mobile tv player animation draw after handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_eb_animation_draw_after_hdlr(GDI_RESULT result)
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

    /* GDI only blt the animation icon region in protrait coordinate. So we need to blt */
    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_draw_eb_animation
 * DESCRIPTION
 *  The function is to draw eb warning icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_draw_eb_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width, height, offset_x, offset_y, eb_width, eb_height;
    dtv_player_osd_text_struct *title_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (GDI_NULL_HANDLE != dtv_player_p->eb_amin_handle)
    {
        return;
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
    #else 
        gdi_layer_push_and_set_active(dtv_player_p->dls_layer_handle);
        #if !defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
        gdi_layer_toggle_double();
	    gdi_layer_copy_double();
        #endif
    #endif /* __MMI_DTV_LANDSCAPE_SUPPORT__ */
    }

    title_p = &dtv_player_p->active_osd_cntx_p->title;


    gdi_image_get_dimension_id((U16)(IMG_ID_DTV_PLAYER_EB_WARNING), &eb_width, &eb_height);

    if (dtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
    	gdi_image_get_dimension_id((U16)(IMG_ID_DTV_PLAYER_SIGNAL_LEVEL_0), &width, &height);
    	offset_x = width + DTV_FULL_DLS_ICON_SPACE;
    #if !defined(__MMI_DTV_LANDSCAPE_SUPPORT__)
	    gdi_anim_set_draw_after_callback(mmi_dtv_player_eb_animation_draw_after_hdlr);
    #endif
        offset_y = ((DTV_PLAYER_FULLSCREEN_DLS_LAYER_HEIGHT - eb_height) >> 1);
	}
	else
	{
		offset_x = DTV_FULL_DLS_ICON_SPACE;
        offset_y = title_p->offset_y + ((title_p->height - eb_height) >> 1);
	}

	gdi_anim_draw_id(offset_x, 
		             offset_y, 
		             IMG_ID_DTV_PLAYER_EB_WARNING, 
		             &dtv_player_p->eb_amin_handle);

	gdi_layer_pop_and_restore_active();
    mmi_dtv_player_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_stop_eb_animation
 * DESCRIPTION
 *  mmi dtv player stop eb animation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dtv_player_stop_eb_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GDI_NULL_HANDLE != dtv_player_p->eb_amin_handle)
    {
    	gdi_image_stop_animation(dtv_player_p->eb_amin_handle);
	    dtv_player_p->eb_amin_handle = GDI_NULL_HANDLE;
    }
}

#ifdef __MMI_CMMB_PREVIEW_PIC_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_preview_data_dl_callback
 * DESCRIPTION
 *  The function is to get preview data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_preview_data_dl_callback(mmi_dtv_mbbms_ret_enum ret, U16 *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL query_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_PREVIEW_DATA_DL_CALLBACK, ret, dtv_player_p->dl_state);

    if (dtv_player_p->dl_state != DTV_PLAYER_DL_STATE_DOWNLOADING)
    {
        return;
    }
	dtv_player_p->dl_state = DTV_PLAYER_DL_STATE_OPENED;

    if (ret == MMI_DTV_MBBMS_OK)
    {
        mdi_mtv_set_preview_data_downloaded(
            dtv_player_p->mtv_handle, file_path, MMI_TRUE);

	    /* Download the next URL */
	    query_ret = mmi_dtv_player_query_preview_data();

		if (query_ret == MMI_FALSE)
		{
			mmi_dtv_player_stop_download_preview_data();
	    }
    }
	else
	{
		mmi_dtv_player_stop_download_preview_data();
	}

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_stop_download_preview_data
 * DESCRIPTION
 *  The function is to get preview data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_stop_download_preview_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_dtv_mbbms_dcnt_struct dcnt;
    mmi_dtv_mbbms_ret_enum dl_ret;
    mmi_dtv_mbbms_download_req_struct *dl_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_STOP_DOWNLOAD_PREVIEW_DATA, dtv_player_p->dl_state);

    gui_cancel_timer(mmi_dtv_player_query_preview_data);

    if (dtv_player_p->dl_state == DTV_PLAYER_DL_STATE_DOWNLOADING)
    {
        mmi_dtv_mbbms_cancel_download();
        dtv_player_p->dl_state = DTV_PLAYER_DL_STATE_OPENED;
    }

    if (dtv_player_p->dl_state == DTV_PLAYER_DL_STATE_OPENED)
    {
        mmi_dtv_mbbms_close();
        dtv_player_p->dl_state = DTV_PLAYER_DL_STATE_CLOSED;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_download_preview_data
 * DESCRIPTION
 *  The function is to get preview data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_download_preview_data(mbbms_sg_query_preview_data_struct *preview_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_dtv_mbbms_dcnt_struct dcnt;
    mmi_dtv_mbbms_ret_enum dl_ret;
    mmi_dtv_mbbms_download_req_struct *dl_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_DOWNLOAD_PREVIEW_DATA, dtv_player_p->dl_state);
    ASSERT(preview_data != NULL);
    if (dtv_player_p->dl_state == DTV_PLAYER_DL_STATE_CLOSED)
    {
        dcnt.net_id = cbm_set_app_id(
                dtv_player_p->setting.data_account_id,
                dtv_player_p->setting.cbm_app_id);
        dcnt.app_id = dtv_player_p->cl_setting.cbm_app_id;
        dcnt.prx_port = dtv_player_p->setting.proxy_port;
        kal_mem_cpy(
            dcnt.prx_ip,
            dtv_player_p->setting.proxy_server,
            MMI_DTV_PLAYER_PROXY_IP_COUNT);

        /* SG URL */
        dcnt.use_proxy = dtv_player_p->setting.use_proxy;
        dl_ret = mmi_dtv_mbbms_open(mmi_dtv_player_preview_data_dl_callback, &dcnt);
        if (dl_ret == MMI_DTV_MBBMS_OK)
        {
            dtv_player_p->dl_state = DTV_PLAYER_DL_STATE_OPENED;
        }
    }

    if (dtv_player_p->dl_state == DTV_PLAYER_DL_STATE_OPENED)
    {
        dl_req = get_ctrl_buffer(sizeof(mmi_dtv_mbbms_download_req_struct));
        kal_mem_set(dl_req, 0, sizeof(mmi_dtv_mbbms_download_req_struct));
        mmi_ucs2ncpy((CHAR*)dl_req->file_path, (CHAR*)preview_data->pic_path, MMI_DTV_MBBMS_MAX_FILE_LEN);
        strncpy(dl_req->req_url, preview_data->pic_uri, MMI_DTV_MBBMS_REQ_URL_LEN);

        dl_ret = mmi_dtv_mbbms_download(dl_req);
        if (dl_ret == MMI_DTV_MBBMS_OK)
        {
            dtv_player_p->dl_state = DTV_PLAYER_DL_STATE_DOWNLOADING;
        }
        free_ctrl_buffer(dl_req);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_create_folder
 * DESCRIPTION
 *  The function is to get preview data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_create_folder(WCHAR *pic_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 file_handle, ret;
    WCHAR pic_dir[128 + 1];
    CHAR *slash;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ucs2ncpy((CHAR*)pic_dir, (CHAR*)pic_path, 128);

    slash = kal_dchar_strrchr((CHAR *) pic_dir, '\\');
    *((kal_int16*)slash) = 0;

    /* Create DIR again */
    if (FS_GetAttributes(pic_dir) < 0)
    {
        ret = FS_CreateDir(pic_dir);
        if (ret >= 0)
        {
            FS_SetAttributes(pic_dir, FS_ATTR_DIR | FS_ATTR_HIDDEN);
        }
        else
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL1, ret, __LINE__);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_find_undownload_pic
 * DESCRIPTION
 *  The function is to get preview data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_find_undownload_pic(mbbms_sg_query_preview_data_struct *preview_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_ucs2strlen(preview_data->pic_uri) == 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL1, 0, __LINE__);
        return MMI_FALSE;
    }
    /* Following: there is pictureURI */

    if (!preview_data->dl_completed)
    {
        mmi_dtv_player_create_folder(preview_data->pic_path);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL1, 1, __LINE__);
        return MMI_TRUE;
    }

    /* Following: pictureURI is downloaded */
    file_handle = FS_Open(preview_data->pic_path, FS_READ_ONLY);
    if (file_handle > 0) /* Check if file exist */
    {
        FS_Close(file_handle);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL1, 0, __LINE__);
        return MMI_FALSE;
    }

    /* Following: picture is deleted, need download again */
    preview_data->dl_completed = MMI_FALSE;

    /* Update to MED */
    mdi_mtv_set_preview_data_downloaded(
        dtv_player_p->mtv_handle, preview_data->pic_path, MMI_FALSE);

    mmi_dtv_player_create_folder(preview_data->pic_path);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL1, 1, __LINE__);
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_query_preview_data
 * DESCRIPTION
 *  The function is to get preview data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_query_preview_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mbbms_sg_query_preview_data_struct *preview_data = NULL;
    mdi_mtv_query_struct query = {0};
    MMI_BOOL found;

    MDI_RESULT ret;
    S32 len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(dtv_player_p->dl_state != DTV_PLAYER_DL_STATE_DOWNLOADING);
    ret = mdi_mtv_esg_query(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_PREVIEW_DATA_ALL, &query);

    if (ret != MDI_RES_MTV_SUCCEED)
    {
        /* handle error case */
        return MMI_FALSE;
    }

    found = MMI_FALSE;
    while(!found)
    {
        ret = mdi_mtv_esg_get_result(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_PREVIEW_DATA_ALL, (void **)&preview_data);
        if (preview_data == NULL)
        {
            break;
        }

        while (preview_data != NULL)
        {
            found = mmi_dtv_player_find_undownload_pic(preview_data);
            if (found)
            {
                break;
            }
            preview_data = preview_data->next_p;
        }
    }

    if (found)
    {
        mmi_dtv_player_download_preview_data(preview_data);
		return MMI_TRUE;
    }
	else
	{
		return MMI_FALSE;
	}

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_draw_preview_image
 * DESCRIPTION
 *  mobile tv player draw preview image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_draw_preview_image(S32 region_x, S32 region_y, S32 region_width, S32 region_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 img_width, img_height, idx;
    S32 resized_x, resized_y, resized_w, resized_h;
    GDI_RESULT ret;
    gdi_handle invalid_handle = 0xFFFFFFFF;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_DRAW_PREVIEW_IMAGE, dtv_player_p->preview_state);
    /* No preview image */
    if (dtv_player_p->preview_state == DTV_PLAYER_PREVIEW_STATE_NONE)
    {
        return MMI_FALSE;
    }

    if (dtv_player_p->preview_state == DTV_PLAYER_PREVIEW_STATE_WAIT_DECODE)
    {
        gdi_image_get_dimension_file(
            (CHAR*)dtv_player_p->info_str_buffer, &img_width, &img_height);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL2, img_width, img_height, __LINE__);

        gdi_util_fit_box(
            GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
            region_width, region_height, img_width, img_height,
            &resized_x, &resized_y, &resized_w, &resized_h);
        resized_x += region_x;
        resized_y += region_y;

        ret = gdi_image_draw_resized_file(
            resized_x, resized_y, resized_w, resized_h, (CHAR*)dtv_player_p->info_str_buffer);
        if (ret != GDI_SUCCEED)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL1, ret, __LINE__);
            dtv_player_p->preview_state = DTV_PLAYER_PREVIEW_STATE_NONE;
            return MMI_FALSE;
        }
        dtv_player_p->preview_state = DTV_PLAYER_PREVIEW_STATE_DECODED;
    }
    else
    {
        /* Copy hint animation */
        mmi_dtv_player_draw_animation(
            region_x, region_y, region_width, region_height, 0, &invalid_handle);
    }

    return MMI_TRUE;
}

#endif /* __MMI_CMMB_PREVIEW_PIC_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_assign_if_have_preview_data
 * DESCRIPTION
 *  The function is to get preview data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_assign_if_have_preview_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mbbms_sg_query_preview_data_struct *preview_data = NULL;
    mdi_mtv_query_struct query = {0};
    dtv_player_service_info_struct *info_ptr;
    MDI_RESULT ret;
    S32 idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_CMMB)
    {
        return;
    }

    for (idx = 0; idx < dtv_player_p->num_services; idx++)
    {
        info_ptr = &(dtv_player_p->services[idx]);
        query.id = info_ptr->service_id;

        ret = mdi_mtv_esg_query(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_PREVIEW_DATA_BY_SID, &query);

        if (ret != MDI_RES_MTV_SUCCEED)
        {
            info_ptr->has_preview_data = MMI_FALSE;
            continue;
        }
        preview_data = NULL;
        ret = mdi_mtv_esg_get_result(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_PREVIEW_DATA_BY_SID, (void **)&preview_data);
        if (preview_data == NULL)
        {
            info_ptr->has_preview_data = MMI_FALSE;
        }
        else
        {
            info_ptr->has_preview_data = MMI_TRUE;
        }
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL2, idx, info_ptr->has_preview_data, __LINE__);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_update_service_preview_data
 * DESCRIPTION
 *  The function is to get preview data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_update_service_preview_data(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mbbms_sg_query_preview_data_struct *preview_data = NULL;
    U16 active_screen = mmi_frm_scrn_get_active_id();
    mdi_mtv_query_struct query = {0};
    MDI_RESULT ret;
    MMI_BOOL has_preview;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_UPDATE_SERVICE_PREVIEW_DATA, idx, dtv_player_p->dl_state);

    ASSERT(idx < dtv_player_p->num_services);

    /* Initialize */
    kal_mem_set(dtv_player_p->preview_text,0, sizeof(dtv_player_p->preview_text));	
	#ifdef __MMI_CMMB_PREVIEW_PIC_SUPPORT__
    kal_mem_set(dtv_player_p->info_str_buffer, 0, sizeof(dtv_player_p->info_str_buffer));
    #endif
    dtv_player_p->preview_state = DTV_PLAYER_PREVIEW_STATE_NONE;


    /* Validate first: for performance */
    has_preview = dtv_player_p->services[idx].has_preview_data;
    if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_CMMB ||
        active_screen != SCR_ID_DTV_PLAYER_APP || !has_preview)
    {
        return;
    }

    query.id = dtv_player_p->services[idx].service_id;
    ret = mdi_mtv_esg_query(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_PREVIEW_DATA_BY_SID, &query);

    if (ret != MDI_RES_MTV_SUCCEED)
    {
        /* handle error case */
        return;
    }

    ret = mdi_mtv_esg_get_result(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_PREVIEW_DATA_BY_SID, (void **)&preview_data);

    while (preview_data != NULL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL4,
            preview_data->text[0], preview_data->dl_completed, preview_data->pic_uri[0], preview_data->pic_path[0], __LINE__);

        /* Preveiw text */
        if (mmi_ucs2strlen((CHAR*)preview_data->text) > 0)
        {
            mmi_ucs2ncpy((CHAR*)dtv_player_p->preview_text, (CHAR*)preview_data->text, MMI_DTV_MAX_PREVIEW_TEXT_LEN);
        }
    #ifdef __MMI_CMMB_PREVIEW_PIC_SUPPORT__
        /* Preview image */
        if (dtv_player_p->dl_state == DTV_PLAYER_DL_STATE_CLOSED)
        {
            if (preview_data->dl_completed &&
                mmi_ucs2strlen((CHAR*)preview_data->pic_uri) > 0 &&
                mmi_ucs2strlen((CHAR*)preview_data->pic_path) > 0)
            {
                mmi_ucs2ncpy((CHAR*)dtv_player_p->info_str_buffer, (CHAR*)preview_data->pic_path, MMI_DTV_INFO_STR_LENGTH);
                dtv_player_p->preview_state = DTV_PLAYER_PREVIEW_STATE_WAIT_DECODE;
            }
        }
    #endif
        preview_data = preview_data->next_p;
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_query_access_list
 * DESCRIPTION
 *  The function is to get service list from access list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_query_access_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mbbms_sg_query_access_all_struct *access_ptr = NULL;
    dtv_player_service_info_struct *info_ptr;
    mdi_mtv_query_struct query = {0};
    MDI_RESULT ret;
    MMI_BOOL skip;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtv_player_p->num_services = 0;
    memset(dtv_player_p->services, 0, MMI_DTV_MAX_SERVICES * sizeof(dtv_player_service_info_struct));
    ret = mdi_mtv_esg_query(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_ACCESS_ALL, &query);
    if (ret != MDI_RES_MTV_SUCCEED)
    {
        return MMI_FALSE;
    }
    while(dtv_player_p->num_services < MMI_DTV_MAX_SERVICES)
    {
        ret = mdi_mtv_esg_get_result(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_ACCESS_ALL, (void **)&access_ptr);
        if (access_ptr == NULL)
        {
            break;
        }
        while (access_ptr != NULL)
        {
            skip = MMI_TRUE;
			
			if (2 == access_ptr->type)
			{				
				skip = MMI_FALSE;
			}
        	#ifdef __MMI_DTV_AUDIO_CHANNEL_SUPPORT__
            if (1 == access_ptr->type)
            {
                skip = MMI_FALSE;
            }
        	#endif /* __MMI_MTV_AUDIO_CHANNEL_SUPPORT__ */
            if (!skip)
            {
                info_ptr = &dtv_player_p->services[dtv_player_p->num_services];

                info_ptr->service_id = access_ptr->sid;
                info_ptr->service_number = info_ptr->service_id + 1;

                if (access_ptr->type == 1)
                {
                    info_ptr->service_type = MDI_MTV_SERVICE_TYPE_DIGITAL_TV;
                }
                else
                {
                    info_ptr->service_type = MDI_MTV_SERVICE_TYPE_DIGITAL_RADIO;
                }

                if (access_ptr->encrypted)
                {
                    info_ptr->service_flags = MEDIA_MTV_SERVICE_UNSUBSCRIBED;
                }
                else
                {
                    info_ptr->service_flags = MEDIA_MTV_SERVICE_CLEAR_TO_AIR;
                }

                dtv_player_p->num_services ++;
            }

            access_ptr = access_ptr->next_p;
            if (dtv_player_p->num_services >= MMI_DTV_MAX_SERVICES)
            {
                break;
            }
        }
    }
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_schedule_now
 * DESCRIPTION
 *  The function is to assign program info to service list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_get_schedule_now(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 service_index;
    MDI_RESULT ret;
    esg_query_schedule_struct *schedule_ptr = NULL;
    dtv_player_service_info_struct *info_ptr;
    mdi_mtv_query_struct query = {0};
    applib_time_struct cur_time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_dtv_player_get_current_system_time(&cur_time);
    query.lang_type = dtv_player_p->language_type;
    query.time = &cur_time;
    ret = mdi_mtv_esg_query(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_SCHEDULES_NOW, &query);

    if (ret != MDI_RES_MTV_SUCCEED)
    {
        /* handle error case */
        return MMI_FALSE;
    }

    while(1)
    {
        schedule_ptr = NULL;
        ret = mdi_mtv_esg_get_result(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_SCHEDULES_NOW, (void **)&schedule_ptr);
        if (schedule_ptr == NULL)
        {
            break;
        }

        while (schedule_ptr != NULL)
        {
            /* Find the service */
            for (service_index = 0; service_index < dtv_player_p->num_services; service_index++)
            {
                if (dtv_player_p->services[service_index].service_id == schedule_ptr->service_ref_id)
                {
                    break;
                }
            }
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL3, service_index, schedule_ptr->service_ref_id, schedule_ptr->content_ref_id, __LINE__);
            /* found out */
            if (service_index < dtv_player_p->num_services)
            {
                info_ptr = &(dtv_player_p->services[service_index]);

                /* Program name */
                mmi_ucs2ncpy((CHAR *)info_ptr->program_name, (CHAR *)schedule_ptr->title, MMI_DTV_NAME_STR_LENGTH);

                /* If original time: "xx:xx - xx:xx", incoming ESG time does not have end time, don't update the time */
                if (!(mmi_ucs2strlen((CHAR*)info_ptr->program_time) == 13 &&
                      mmi_ucs2strlen((CHAR*)schedule_ptr->end_date_time) == 0))
                {
                    /* Program time: [yyyy-mm-dd hh:mm:ss] -> [hh:mm] */
                    if (mmi_ucs2strlen((CHAR*)schedule_ptr->start_date_time) > 0)
                    {
                        mmi_ucs2ncpy((CHAR *)info_ptr->program_time, (CHAR *)&(schedule_ptr->start_date_time[11]), 5);
                    }
                    else
                    {
                        mmi_ucs2ncpy((CHAR *)info_ptr->program_time, (CHAR *)L"     ", 5); /* 5 space */
                    }
                    mmi_ucs2cat((CHAR *)info_ptr->program_time, (CHAR *)L"-");

                    if (mmi_ucs2strlen((CHAR*)schedule_ptr->end_date_time) > 0)
                    {
                        mmi_ucs2ncat((CHAR *)info_ptr->program_time, (CHAR *)&(schedule_ptr->end_date_time[11]), 5);
                    }
                }
            }
            schedule_ptr = schedule_ptr->next_p;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_content_now
 * DESCRIPTION
 *  The function is to assign program info to service list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_get_content_now(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 service_index;
    MDI_RESULT ret;
    dtv_player_service_info_struct *info_ptr;
    mbbms_sg_query_content_struct *content_ptr = NULL;
    mdi_mtv_query_struct query = {0};
    applib_time_struct cur_time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_dtv_player_get_current_system_time(&cur_time);
    query.time = &cur_time;

    ret = mdi_mtv_esg_query(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_CONTENT_NOW, &query);

    if (ret != MDI_RES_MTV_SUCCEED)
    {
        /* handle error case */
        return MMI_FALSE;
    }

    while(1)
    {
        content_ptr = NULL;
        ret = mdi_mtv_esg_get_result(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT,  ESG_QUERY_CONTENT_NOW, (void **)&content_ptr);
        if (content_ptr == NULL)
        {
            break;
        }

        while (content_ptr != NULL)
        {
            /* Find the service */
            for (service_index = 0; service_index < dtv_player_p->num_services; service_index++)
            {
                if (dtv_player_p->services[service_index].service_id == content_ptr->sid)
                {
                    break;
                }
            }
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL3, service_index, content_ptr->sid, 0, __LINE__);

            /* found out */
            if (service_index < dtv_player_p->num_services)
            {
                info_ptr = &(dtv_player_p->services[service_index]);

                /* Program name */
                mmi_ucs2ncpy((CHAR *)info_ptr->program_name, (CHAR *)content_ptr->name, MMI_DTV_NAME_STR_LENGTH);

                mmi_ucs2ncpy((CHAR*)info_ptr->program_time, (CHAR*)&content_ptr->start_time[11], 5);
                mmi_ucs2cat((CHAR*)info_ptr->program_time, (CHAR*)L"-");
                mmi_ucs2ncat((CHAR*)info_ptr->program_time, (CHAR*)&content_ptr->end_time[11], 5);

            }
            content_ptr = content_ptr->next_p;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_assign_program_info
 * DESCRIPTION
 *  The function is to assign program info to service list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_assign_program_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_ASSIGN_PROGRAM_INFO);

    if (dtv_player_p->num_services <= 0)
    {
        return MMI_TRUE;
    }

    /* We will use program name and time from ESG. So reset program info as 0 and
       at the next time in service_event_hdlr(), MMI will receive program info again */
    kal_mem_set((void*)&(dtv_player_p->prog_info), 0, sizeof(mdi_mtv_program_info_struct));

    if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_CMMB)
    {
        ret = mmi_dtv_player_get_schedule_now();
    }
    else /* MBBMS or MBBMS ready */
    {
        ret = mmi_dtv_player_get_content_now();
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_assign_favorite_service_info
 * DESCRIPTION
 *  The function is to assign favorite service info to service list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_assign_favorite_service_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 service_index;
    dtv_player_service_info_struct *info_ptr;
    dtv_player_service_info_struct *prev_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_ASSIGN_FAVORITE_SERVICE_INFO);

    /* Initialize */
    dtv_player_p->head_of_favorite_service = NULL;
    for (service_index = 0; service_index < dtv_player_p->num_services; service_index ++)
    {
        dtv_player_p->services[service_index].prev = NULL;
        dtv_player_p->services[service_index].next = NULL;
        dtv_player_p->services[service_index].is_favorite = MMI_FALSE;
    }

    /* Query favorite service */
    mmi_dtv_player_query_favorite_service();
    if (dtv_player_p->num_favorite_services == 0)
    {
        return MMI_FALSE;
    }

    /* Assign double linked list */
    for (service_index = 0; service_index < dtv_player_p->num_services; service_index ++)
    {
        info_ptr = &(dtv_player_p->services[service_index]);
        if (info_ptr->is_favorite == MMI_TRUE)
        {
            if (dtv_player_p->head_of_favorite_service == NULL)
            {
                dtv_player_p->head_of_favorite_service = info_ptr;
                info_ptr->next = NULL;
            }
            else
            {
                ASSERT(prev_ptr != NULL);
                info_ptr->prev = prev_ptr;
                prev_ptr->next = info_ptr;
                info_ptr->next = NULL;
            }

            prev_ptr = info_ptr;
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_query_sgdd_info
 * DESCRIPTION
 *  The function is to query favorite service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_query_sgdd_info(
        dtv_player_sgdd_info_enum sgdd_info, 
        WCHAR *str_buffer,
        S32 str_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mbbms_sg_query_sgdd_struct *sgdd_ptr = NULL;
    mdi_mtv_query_struct query = {0};    
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_mem_set(dtv_player_p->info_str_buffer, 0, sizeof(dtv_player_p->info_str_buffer));

    ret = mdi_mtv_esg_query(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_SGDD, &query);

    if (ret != MDI_RES_MTV_SUCCEED)
    {
        /* handle error case */
        return;
    }

    ret = mdi_mtv_esg_get_result(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_SGDD, (void **)&sgdd_ptr);
    if (sgdd_ptr != NULL)
    {
        if (sgdd_info == MMI_DTV_SGDD_WELCOME_INFO)
        {
            /* Copy welcome info */
            mmi_ucs2ncpy((CHAR*)str_buffer, (CHAR*)sgdd_ptr->welcome_info, str_len);
        }
        else if (sgdd_info == MMI_DTV_SGDD_AREA_NAME)
        {
            /* Copy area name */
            mmi_ucs2ncpy((CHAR*)str_buffer, (CHAR*)sgdd_ptr->area_name, str_len);
        }
        else
        {
            ASSERT(0);
        }
    }


}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_query_favorite_service
 * DESCRIPTION
 *  The function is to query favorite service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_query_favorite_service(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 service_index;
    MDI_RESULT ret;
    void *service_ptr = NULL;
    dtv_player_service_info_struct *info_ptr;
    mdi_mtv_query_struct query = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dtv_player_p->num_favorite_services = 0;
    query.lang_type = dtv_player_p->language_type;
    ret = mdi_mtv_esg_query(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_FAVORITE_LIST, &query);

    if (ret != MDI_RES_MTV_SUCCEED)
    {
        /* handle error case */
        return;
    }

    while(1)
    {
        service_ptr = NULL;
        ret = mdi_mtv_esg_get_result(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_FAVORITE_LIST, (void **)&service_ptr);
        if (service_ptr == NULL)
        {
            break;
        }

        while (service_ptr != NULL)
        {
            if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_CMMB)
            {
                for (service_index = 0; service_index < dtv_player_p->num_services; service_index++)
                {
                    info_ptr = &dtv_player_p->services[service_index];
                    if (info_ptr->service_id == ((esg_query_service_struct*)service_ptr)->ref_id)
                    {
                        break;
                    }
                }
            }
            else /* MBBMS or MBBMS ready */
            {
                for (service_index = 0; service_index < dtv_player_p->num_services; service_index++)
                {
                    info_ptr = &dtv_player_p->services[service_index];
                    if (info_ptr->service_id == ((mbbms_sg_query_service_struct*)service_ptr)->sid)
                    {
                        break;
                    }
                }
            }


            /* found out */
            if (service_index < dtv_player_p->num_services)
            {
                info_ptr = &(dtv_player_p->services[service_index]);

                /* Error handling */
                if (info_ptr->is_favorite == MMI_FALSE)
                {
                    /* is favorite */
                    info_ptr->is_favorite = MMI_TRUE;
                    dtv_player_p->num_favorite_services ++;

                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_VAL4,
                        info_ptr->service_number,
                        info_ptr->service_id,
                        info_ptr->service_type,
                        info_ptr->is_favorite,
                        __LINE__);
                }
            }


            if (dtv_player_p->ca_state == MMI_DTV_CA_STATE_CMMB)
            {
                service_ptr = ((esg_query_service_struct*)service_ptr)->next_p;
            }
            else /* MBBMS or MBBMS ready */
            {
                service_ptr = ((mbbms_sg_query_service_struct*)service_ptr)->next_p;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_query_schedule_details
 * DESCRIPTION
 *  The function is to query schedule details
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_query_cmmb_content_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    esg_query_content_struct *content_ptr = NULL;
    kal_wchar duration_string[10]; /* HH:MM:SS */
    kal_uint16 hour, min, sec, tmp_dur;
    MDI_RESULT ret;
    mdi_mtv_query_struct query = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    query.id = dtv_player_p->selected_content.content_id;
    query.lang_type = dtv_player_p->language_type;
    ret = mdi_mtv_esg_query(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_CONTENT, &query);
    if (ret != MDI_RES_MTV_SUCCEED)
    {
        /* handle error case */
        return;
    }

    mdi_mtv_esg_get_result(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_CONTENT, (void **)&content_ptr);

    /* Content title */
    mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_CONTENT_TITLE));
    if (content_ptr != NULL)
    {
        mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)content_ptr->title);
    }

    mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");

    /* Content class */
    mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_CONTENT_CLASS));
    if (content_ptr != NULL)
    {
        if (mmi_ucs2cmp((CHAR*)content_ptr->class, (CHAR*)L"video") == 0)
        {
            mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_GLOBAL_VIDEO));
        }
        else if (mmi_ucs2cmp((CHAR*)content_ptr->class, (CHAR*)L"audio") == 0)
        {
            mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_CONTENT_CLASS_AUDIO));
        }
        else if (mmi_ucs2cmp((CHAR*)content_ptr->class, (CHAR*)L"text") == 0)
        {
            mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_GLOBAL_TEXT));
        }
        else if (mmi_ucs2cmp((CHAR*)content_ptr->class, (CHAR*)L"image") == 0)
        {
            mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_CONTENT_CLASS_IMAGE));
        }
        else if (mmi_ucs2cmp((CHAR*)content_ptr->class, (CHAR*)L"application") == 0)
        {
            mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_CONTENT_CLASS_APPLICATION));
        }
        else if (mmi_ucs2cmp((CHAR*)content_ptr->class, (CHAR*)L"multipart") == 0)
        {
            mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_CONTENT_CLASS_MULTIPART));
        }

    }
    mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");

    /* Digest info */
    mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_DIGEST_INFO));
    if (content_ptr != NULL)
    {
        mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)content_ptr->description);
    }
    mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");

    /* Duration */
    mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_DURATION));
    if (content_ptr != NULL)
    {
        tmp_dur = content_ptr->duration;
        sec = tmp_dur % 60;
        tmp_dur /= 60;
        min = tmp_dur % 60;
        tmp_dur /= 60;
        hour = tmp_dur % 60;
        kal_wsprintf(duration_string, "%02d:%02d:%02d", hour, min, sec);
        mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)duration_string);
    }
    mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");

    /* Keyword */
    mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_KEYWORD));
    if (content_ptr != NULL)
    {
        mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)content_ptr->keyword);
    }
    mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");

    //for free
    ASSERT(mmi_ucs2strlen((CHAR *) dtv_player_p->detail_buf) * 2 + 2 <= MMI_DTV_PLAYER_DETAIL_BUF_SIZE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_query_mbbms_content_details
 * DESCRIPTION
 *  The function is to query schedule details
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_query_mbbms_content_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mbbms_sg_query_content_struct *content_ptr = NULL;
    MDI_RESULT ret;
    mdi_mtv_query_struct query = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    strcpy(query.rid, dtv_player_p->selected_content.cid);
    ret = mdi_mtv_esg_query(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_CONTENT, &query);
    if (ret != MDI_RES_MTV_SUCCEED)
    {
        /* handle error case */
        return;
    }

    mdi_mtv_esg_get_result(dtv_player_p->mtv_handle, MEDIA_MTV_ESG_SOURCE_DEFAULT, ESG_QUERY_CONTENT, (void **)&content_ptr);

    /* Date */
    mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_DATE));

    if (content_ptr != NULL)
    {
        /* yyyy-mm-dd xx:xx-xx:xx */
        content_ptr->start_time[10] = 0;
        mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)content_ptr->start_time);
        mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");
    }

    /* Content class */
    mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_CONTENT_CLASS));
    if (content_ptr != NULL)
    {
        if (mmi_ucs2cmp((CHAR*)content_ptr->class, (CHAR*)L"video") == 0)
        {
            mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_GLOBAL_VIDEO));
        }
        else if (mmi_ucs2cmp((CHAR*)content_ptr->class, (CHAR*)L"audio") == 0)
        {
            mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_CONTENT_CLASS_AUDIO));
        }
        else if (mmi_ucs2cmp((CHAR*)content_ptr->class, (CHAR*)L"text") == 0)
        {
            mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_GLOBAL_TEXT));
        }
        else if (mmi_ucs2cmp((CHAR*)content_ptr->class, (CHAR*)L"image") == 0)
        {
            mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_CONTENT_CLASS_IMAGE));
        }
        else if (mmi_ucs2cmp((CHAR*)content_ptr->class, (CHAR*)L"application") == 0)
        {
            mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_CONTENT_CLASS_APPLICATION));
        }
        else if (mmi_ucs2cmp((CHAR*)content_ptr->class, (CHAR*)L"multipart") == 0)
        {
            mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_CONTENT_CLASS_MULTIPART));
        }

    }
    mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");

    /* Details */
    mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_PLAYER_DESCRIPTION));
    if (content_ptr != NULL)
    {
        mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)content_ptr->description);
    }
    mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");
    mmi_ucs2cat(dtv_player_p->detail_buf, (CHAR *)L"\n");

    if (dtv_player_p->selected_content.has_inter_data)
    {
        mmi_ucs2cat(dtv_player_p->detail_buf, GetString(STR_ID_DTV_CHECK_INTER_SERVICE));

        /* 4 byte is for category screen to add icon */
        ASSERT(mmi_ucs2strlen((CHAR *) dtv_player_p->detail_buf) * 2 + 2 + 4 <= MMI_DTV_PLAYER_DETAIL_BUF_SIZE);
    }
    else
    {
        ASSERT(mmi_ucs2strlen((CHAR *) dtv_player_p->detail_buf) * 2 + 2 <= MMI_DTV_PLAYER_DETAIL_BUF_SIZE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_query_local_order
 * DESCRIPTION
 *  The function is to query order list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_query_local_order(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    mbbms_sg_query_purchase_item_struct *order_ptr = NULL;
    S32 i;
    mdi_mtv_query_struct query = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ret = mdi_mtv_esg_query(dtv_player_p->mtv_handle, 
                            MEDIA_MTV_ESG_SOURCE_DEFAULT, 
                            ESG_QUERY_PURCHASE_ITEM_ALL_CURRENT_PLACE, 
                            &query);

    if (ret != MDI_RES_MTV_SUCCEED)
    {
        return;
    }

    while(1)
    {
        order_ptr = NULL;
        ret = mdi_mtv_esg_get_result(dtv_player_p->mtv_handle, 
			                         MEDIA_MTV_ESG_SOURCE_DEFAULT, 
			                         ESG_QUERY_PURCHASE_ITEM_ALL_CURRENT_PLACE, 
			                         (void **)&order_ptr);
        if (order_ptr == NULL)
        {
            break;
        }

        while (order_ptr != NULL)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
				      MMI_TRC_DTV_VAL1, 
				      order_ptr->gid,  
				      __LINE__);
            /* Find order */
            for (i = 0; i < dtv_player_p->num_orders; i ++)
            {
                if (!strcmp(order_ptr->gid, dtv_player_p->orders[i].gid))
                {
                    dtv_player_p->orders[i].local = MMI_TRUE;
                    if (dtv_player_p->orders[i].type == 0)
                    {
                        dtv_player_p->orders[i].type = order_ptr->type;
                        dtv_player_p->orders[i].period = order_ptr->period;
                        dtv_player_p->orders[i].price = order_ptr->price;
                    }
                    break;
                }
            }
            order_ptr = order_ptr->next_p;
        }
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_query_order_list
 * DESCRIPTION
 *  The function is to query order list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_query_order_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    mbbms_sg_query_purchase_item_struct *order_ptr = NULL;
    S32 i, j, extra_num, idx;
    dtv_player_order_struct tmp_order;
    dtv_player_account_struct *acc_p;
    mdi_mtv_query_struct query = {0};
    dtv_player_order_struct *dst;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dtv_player_p->num_orders = 0;

    ret = mdi_mtv_esg_query(dtv_player_p->mtv_handle, 
		                    MEDIA_MTV_ESG_SOURCE_DEFAULT, 
		                    ESG_QUERY_PURCHASE_ITEM_ALL, 
		                    &query);

    if (ret != MDI_RES_MTV_SUCCEED)
    {
        /* handle error case */
        return;
    }

    while(dtv_player_p->num_orders < MMI_DTV_MAX_ORDERS)
    {
        order_ptr = NULL;
        ret = mdi_mtv_esg_get_result(dtv_player_p->mtv_handle, 
			                         MEDIA_MTV_ESG_SOURCE_DEFAULT, 
			                         ESG_QUERY_PURCHASE_ITEM_ALL, 
			                         (void **)&order_ptr);
        if (order_ptr == NULL)
        {
            break;
        }

        while (order_ptr != NULL)
        {
            dst = &dtv_player_p->orders[dtv_player_p->num_orders];
            strncpy(dst->id, order_ptr->id, MBBMS_SG_ID_LEN);
            strncpy(dst->gid, order_ptr->gid, MBBMS_SG_ID_LEN);
            mmi_ucs2ncpy((CHAR*)dst->name, 
				         (CHAR*)order_ptr->name, 
				         MMI_DTV_NAME_STR_LENGTH);

            dst->type = order_ptr->type;
            dst->period = order_ptr->period;
            dst->price = order_ptr->price;

            dtv_player_p->num_orders ++;
            order_ptr = order_ptr->next_p;

            /* Over the limitation */
            if (dtv_player_p->num_orders >= MMI_DTV_MAX_ORDERS)
            {
                break;
            }
        }
    }

    extra_num = 0;
    dtv_player_p->num_subscribed_orders = 0;
    for (i = 0; i < dtv_player_p->num_accounts; i ++)
    {
        acc_p = &dtv_player_p->account[i];
        for (j = 0; j < dtv_player_p->num_orders; j ++)
        {
            if (!strcmp(acc_p->gid, dtv_player_p->orders[j].gid))
            {
                break;
            }
        }

        /* Found */
        if (j < dtv_player_p->num_orders)
        {
            dtv_player_p->orders[j].subscribed = MMI_TRUE;
            dtv_player_p->num_subscribed_orders ++;
        }
        /* Not Found */
        else
        {
            idx = dtv_player_p->num_orders + extra_num;
            if (idx >= MMI_DTV_MAX_ORDERS)
            {
                continue;
            }

            strncpy(dtv_player_p->orders[idx].gid, acc_p->gid, MBBMS_SG_ID_LEN);
            strncpy(dtv_player_p->orders[idx].id, acc_p->id, MBBMS_SG_ID_LEN);
            mmi_ucs2ncpy((CHAR*)dtv_player_p->orders[idx].name, 
				         (CHAR*)acc_p->name, 
				         MMI_DTV_NAME_STR_LENGTH);
            dtv_player_p->orders[idx].type = acc_p->type;
            dtv_player_p->orders[idx].price = acc_p->price;
            dtv_player_p->orders[idx].period = acc_p->period;

            dtv_player_p->orders[idx].subscribed = MMI_TRUE;
            dtv_player_p->num_subscribed_orders ++;

            extra_num ++;
        }
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_ORDER_NUM,
        dtv_player_p->num_accounts,
        dtv_player_p->num_subscribed_orders,
        extra_num,
        dtv_player_p->num_orders);

    dtv_player_p->num_orders += extra_num;

    /* Sort: Subscribed, then Unsubscribed */
    for (i = 0; i < dtv_player_p->num_subscribed_orders; i++)
    {
        if (!dtv_player_p->orders[i].subscribed)
        {
            /* Found Subscribed channel */
            for (j = dtv_player_p->num_subscribed_orders; 
			     j < dtv_player_p->num_orders; 
				 j++)
            {
                if (dtv_player_p->orders[j].subscribed)
                {
                    break;
                }
            }

            ASSERT(j < dtv_player_p->num_orders);

            /* Exchange*/
            tmp_order = dtv_player_p->orders[i];
            dtv_player_p->orders[i] = dtv_player_p->orders[j];
            dtv_player_p->orders[j] = tmp_order;
        }
    }

    /* Assign if the purchase item is local order */
    mmi_dtv_player_query_local_order();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_esg_timeout_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_esg_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_DTV_ESG_TIMEOUT_HDLR);
    ASSERT(KERNEL_STATE_IN(DTV_KERNEL_ESG_DOWNLOAD));

    /* start service timeout, so MMI automatically stops service. */
    if (KERNEL_STATE_IN(DTV_KERNEL_ESG_DOWNLOAD))
    {
        ret = mmi_dtv_player_kernel_enter_state(DTV_KERNEL_OPENED);

        ASSERT(ret == MDI_RES_MTV_SUCCEED);
    }

    /* Handle screen flow */
    mmi_dtv_player_reset_to_channel_list_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_compute_mjd_to_apptime
 * DESCRIPTION
 *  The function is to compute mjd to apptime
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_compute_mjd_to_apptime(kal_uint32 mjd, kal_uint32 bcd, applib_time_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int Z, A, B, C, D, E, X1;
    double rJD = mjd + 2400000.5;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* 16 bits: Caculate year, month, day */
    Z = (kal_int32)(rJD + 0.5);
    A = (kal_int32)((Z - 1867216.25) / 36524.25);
    A = Z + 1 + A - (A / 4);
    B = A + 1524;
    C = (kal_int32)((B - 122.1) / 365.25);
    D = (kal_int32)(365.25 * C);
    E = (kal_int32)((B - D) / 30.6001);
    X1 = (kal_int32)(30.6001 * E);
    p->nDay = B - D - X1;
    p->nMonth = E < 14 ? E - 1 : E - 13;
    p->nYear = p->nMonth > 2 ? C - 4716 : C - 4715;
    p->DayIndex = (((kal_uint32)rJD % 7) + 1) % 7;

    /* 24 bits: Calcuate hour, minute, second */
    p->nHour = ((bcd >>20) & 0xf)* 10 + ((bcd >>16) & 0xf);
    p->nMin  = ((bcd >>12) & 0xf)* 10 + ((bcd >>8) & 0xf);
    p->nSec  = ((bcd >>4 ) & 0xf)* 10 + (bcd & 0xf);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_compute_seconds_to_apptime
 * DESCRIPTION
 *  The function is to compute second to apptime
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
void mmi_dtv_player_compute_seconds_to_apptime(U32 seconds, applib_time_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 minutes, hours, days;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_mem_set(p, 0, sizeof(applib_time_struct));

    minutes = 0;
    while (seconds >= DT_SEC_PER_MIN)
    {
        seconds -= DT_SEC_PER_MIN;
        minutes ++;
    }

    hours = 0;
    while (minutes >= DT_MIN_PER_HR)
    {
        minutes -= DT_MIN_PER_HR;
        hours ++;
    }

    days = 0;
    while (hours >= DT_HRS_PRE_DAY)
    {
        hours -= DT_HRS_PRE_DAY;
        days ++;
    }

    p->nDay = days;
    p->nHour = hours;
    p->nMin = minutes;
    p->nSec = seconds;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_get_language_type
 * DESCRIPTION
 *  The function is to get language type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtv_player_get_language_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* lang_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Get language type */
    lang_ptr = Get_Current_Lang_CountryCode();

    if (strcmp((kal_char*)lang_ptr, "en-US") == 0)
    {
        dtv_player_p->language_type = MDI_MTV_LANG_ENG;
    }
    else if (strcmp((kal_char*)lang_ptr, "zh-CN") == 0 || strcmp((kal_char*)lang_ptr, "zh-TW") == 0)
    {
        dtv_player_p->language_type = MDI_MTV_LANG_ZHO;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_kernel_entry_esg_download_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_kernel_entry_esg_download_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef  __MMI_DTV_BLOCK_BG_CALL__
    if (mmi_dtv_player_is_in_background_call())
    {
        dtv_player_p->last_error = MDI_RES_DTV_FAILED;
        return dtv_player_p->last_error;
    }
#endif /* __MMI_DTV_BLOCK_BG_CALL__ */


    dtv_player_p->last_error = mdi_mtv_start_esg_download(
                                    dtv_player_p->mtv_handle);

    if (dtv_player_p->last_error == MDI_RES_MTV_SUCCEED)
    {
        StartTimer(
            DTV_PLAYER_ESG_TIMEOUT_TIMER,
            MMI_DTV_PLAYER_ESG_TIMEOUT_DURATION,
            mmi_dtv_player_esg_timeout_hdlr);
    }

    return dtv_player_p->last_error;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_kernel_exit_esg_download_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_kernel_exit_esg_download_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (KERNEL_STATE_IN(DTV_KERNEL_ESG_DOWNLOAD))
    {
        ret = mdi_mtv_abort_esg_download(dtv_player_p->mtv_handle);
        ASSERT(ret == MDI_RES_MTV_SUCCEED);

        StopTimer(DTV_PLAYER_ESG_TIMEOUT_TIMER);
        StopTimer(DTV_PLAYER_UPDATE_SCAN_STATUS);
    }
    else
        ret = MDI_RES_MTV_SUCCEED;

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_kernel_entry_subscribing_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_kernel_entry_process_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_MTV_SUCCEED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (dtv_player_p->process_type)
    {
        case DTV_PLAYER_PROCESS_TYPE_SUBSCRIBE:
			{
	            ret = mdi_mtv_subscribe_purchase_item(dtv_player_p->mtv_handle,
								                      dtv_player_p->selected_order.id,
								                      dtv_player_p->selected_order.gid);
	            break;
        	}
        case DTV_PLAYER_PROCESS_TYPE_UNSUBSCRIBE:
			{
	            ret = mdi_mtv_unsubscribe_purchase_item(dtv_player_p->mtv_handle,
								                        dtv_player_p->selected_order.id,
	                        							dtv_player_p->selected_order.gid);
	            break;
        	}
        case DTV_PLAYER_PROCESS_TYPE_ACCOUNT_INQUIRY:
			{
            	ret = mdi_mtv_account_inquiry(dtv_player_p->mtv_handle);
	            break;
        	}
        case DTV_PLAYER_PROCESS_TYPE_SUBSCRIPTION_UPDATE:
			{
            	ret = mdi_mtv_subscription_update(dtv_player_p->mtv_handle);
            	break;
        	}
	#ifdef __MBBMS_UPGRADE__
        case DTV_PLAYER_PROCESS_TYPE_UPGRADE_QUERY:
            {
				ret = mdi_mtv_upgrade_query(dtv_player_p->mtv_handle);
	            break;
        	}
	#endif /* __MBBMS_UPGRADE__ */
	#ifdef __MBBMS_CITY_LIST__
        case DTV_PLAYER_PROCESS_TYPE_AREA_SET_RETRIEVE:
			{
            	ret = mdi_mtv_area_set_retrieve(dtv_player_p->mtv_handle);
	            break;
        	}
	#endif /* __MBBMS_CITY_LIST__ */
	#ifdef __MBBMS_INTER__
        case DTV_PLAYER_PROCESS_TYPE_INTERACTIVITY_RETRIEVE:
            {
				ret = mdi_mtv_interactivity_retrieve(dtv_player_p->mtv_handle, dtv_player_p->selected_content.cid);
	            break;    
        	}
	#endif /* __MBBMS_INTER__ */
    #ifdef __MMI_MBBMS_MTS_SUPPORT__
        case DTV_PLAYER_PROCESS_TYPE_GBA:

            ret = mdi_mtv_mts_test(
                    dtv_player_p->mtv_handle,
                    MDI_MTV_MTS_TYPE_GBA,
                    0);
            break;
        case DTV_PLAYER_PROCESS_TYPE_MSK_RETRIEVE:

            ret = mdi_mtv_mts_test(
                    dtv_player_p->mtv_handle,
                    MDI_MTV_MTS_TYPE_MSK_RETRIEVE,
                    (S32)dtv_player_p->setting.selected_channel);
            break;
    #endif /* __MMI_MBBMS_MTS_SUPPORT__ */
    }

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_kernel_exit_process_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_kernel_exit_process_state(void)
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
 *  mmi_dtv_player_kernel_entry_sub_updating_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_kernel_entry_sub_updating_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ret = mdi_mtv_subscription_update(dtv_player_p->mtv_handle);

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_kernel_exit_sub_updating_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
 MDI_RESULT mmi_dtv_player_kernel_exit_sub_updating_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mdi_mtv_cancel_subscription_update(dtv_player_p->mtv_handle);

    /* Stop service init animation */
    mmi_dtv_player_stop_hint_animation();

    return MDI_RES_MTV_SUCCEED;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtv_player_if_mts_file_exist
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_dtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MMI_BOOL mmi_dtv_player_if_mts_file_exist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 handle;
    WCHAR path[30] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ucs2cpy((CHAR *)path, (CHAR *)MTV_SETTING_PATH);
    mmi_ucs2cat((CHAR *)path, (CHAR *)L"mts");

    handle = FS_Open(path, FS_READ_ONLY);
    if (handle > 0)
    {
        FS_Close(handle);
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

/*****************************************************************************
 * FunctionName: mmi_dtv_player_get_setting_account_id
 * Description
 *     
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-03-09
 *****************************************************************************/
U32 mmi_dtv_player_get_setting_account_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 dtcnt_id = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (MMI_SIM1 == dtv_player_p->cur_sim)
	{
		dtcnt_id = dtv_player_p->setting.data_account_id;
	}
	else
	{
		dtcnt_id = dtv_player_p->setting.sim2_data_account_id;
	}
	
    return dtcnt_id;	
}

#ifdef __MMI_CMMB_CAS_2GPP_SUPPORT__
/*****************************************************************************
 * FunctionName: mmi_dtv_player_cmmb_2gpp_help_group_proc
 * Description
 *     
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-05-04
 *****************************************************************************/
mmi_ret mmi_dtv_player_cmmb_2gpp_help_group_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cui_menu_event_struct* menu_evt = (cui_menu_event_struct *)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(param->evt_id)
	{
		case EVT_ID_CUI_MENU_LIST_ENTRY:
			{
				cui_menu_set_item_image(menu_evt->sender_id, 
					                    MENU_ID_DTV_2GPP_HELP1, 
					                    IMG_GLOBAL_L1);				
				cui_menu_set_item_image(menu_evt->sender_id, 
					                    MENU_ID_DTV_2GPP_HELP2, 
					                    IMG_GLOBAL_L2);				
				cui_menu_set_item_image(menu_evt->sender_id, 
					                    MENU_ID_DTV_2GPP_HELP3, 
					                    IMG_GLOBAL_L3);				
				break;
			}
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
        	{
				dtv_player_p->help_2gpp_select_item = menu_evt->highlighted_menu_id;
				mmi_dtv_player_entry_help_screen();				
				cui_menu_close(menu_evt->sender_id);
            	break;
        	}
		case EVT_ID_CUI_MENU_CLOSE_REQUEST:
			{
				cui_menu_close(menu_evt->sender_id);
				break;
			}
		default:
			{
				break;
			}
	}

	return MMI_RET_OK;	
}


/*****************************************************************************
 * FunctionName: mmi_dtv_player_display_2gpp_help_items
 * Description
 *  display 2gpp help items screen   
 * Input Parameter
 *    void
 * Output Parameter
 *    void
 * Return
 *    void
 * Date:  2012-05-04
 *****************************************************************************/
void mmi_dtv_player_display_2gpp_help_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_id cui_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_group_create(GRP_ID_DTV_PLAYER,GRP_ID_DTV_CMMB_2GPP_HELP,mmi_dtv_player_cmmb_2gpp_help_group_proc,NULL);
	mmi_frm_group_enter(GRP_ID_DTV_CMMB_2GPP_HELP,MMI_FRM_NODE_SMART_CLOSE_FLAG);

	cui_id = cui_menu_create_and_run(GRP_ID_DTV_CMMB_2GPP_HELP,
		     		                 CUI_MENU_SRC_TYPE_RESOURCE,
		                             CUI_MENU_TYPE_APPSUB,
		                             MENU_ID_DTV_2GPP_HELP,
		                             MMI_TRUE,
		                             NULL);	
	cui_menu_set_currlist_left_softkey(cui_id,(WCHAR *)GetString(STR_GLOBAL_OK));
	cui_menu_set_currlist_right_softkey(cui_id,(WCHAR *)GetString(STR_GLOBAL_BACK));
}
#endif

#endif /* __MMI_MOBILE_TV_CMMB_SUPPORT__ */

