/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
*  dmuiapp.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  Tethering application for plutommi.
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
*
*****************************************************************************/
#include "mmi_features.h"
#ifdef __MMI_TETHERING__
#include "MMI_include.h"
#include "Wgui_categories_util.h"
#include "mmi_rp_srv_tethering_def.h"
#include "mmi_rp_app_tethering_def.h"

#include "TetheringSrvIprot.h"
#include "TetheringSrvGprot.h"

#include "TetheringAppDef.h"
#include "TetheringAppProt.h"

#include "menucuigprot.h"
#include "InlineCuiGprot.h"
#include "SimCtrlSrvGprot.h"
#include "CommonScreens.h"
#include "CommonScreensResDef.h"
#include "DataAccountGprot.h"
#include "DataAccountCUIGprot.h"
#include "DtcntSrvGprot.h"
#include "ConnectManageGProt.h"
#include "CbmSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "mmi2abm_struct.h"

/***************************************************************************** 
* define
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/

// for prevent the input characters on VK.
static const UI_character_type g_tethering_key_extra_chars[] = L"\'+\\\\_\\-.@!#$%&*/=?(),:;[]<>\"^`{|}~A-Za-z0-9";

mmi_tethering_cntx_struct tethering_cntx;

static const MMI_STR_ID wifi_switch_sel_str[] = {STR_GLOBAL_OFF, STR_GLOBAL_ON};
static const MMI_STR_ID wifi_auth_mode_sel_str[] = {STR_ID_SRV_TETHERING_WIFI_HS_AUTH_MODE_OPEN, STR_ID_SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK};
static const MMI_STR_ID wifi_switch_auto_turn_off_sel_str[] = {STR_GLOBAL_OFF, STR_GLOBAL_ON};

static const cui_inline_item_caption_struct     wifi_inline_switch_cap = {STR_ID_APP_TETHERING_SWITCH};
static const cui_inline_item_select_struct      wifi_inline_switch_sel = {sizeof(wifi_switch_sel_str)/sizeof(wifi_switch_sel_str[0]), TETHERING_WIFI_SETTINGS_SWITCH_ITEM_OFF, wifi_switch_sel_str};
static const cui_inline_item_caption_struct     wifi_inline_auto_turn_off_cap = {STR_ID_SRV_TETHERING_AUTO_TURN_OFF};
static const cui_inline_item_select_struct      wifi_inline_auto_turn_off_sel = {sizeof(wifi_switch_auto_turn_off_sel_str)/sizeof(wifi_switch_auto_turn_off_sel_str[0]), TETHERING_WIFI_SETTINGS_AUTO_TURN_OFF_ITEM_OFF, wifi_switch_auto_turn_off_sel_str};
static const cui_inline_item_caption_struct     wifi_inline_ssid_cap = {STR_ID_SRV_TETHERING_WIFI_HS_SSID};
static const cui_inline_item_display_only_struct   wifi_inline_ssid_edit = {0, 0};
static const cui_inline_item_caption_struct     wifi_inline_auth_mode_cap = {STR_ID_SRV_TETHERING_WIFI_HS_AUTH_MODE};
static const cui_inline_item_select_struct      wifi_inline_auth_mode_sel = {SRV_TETHERING_WIFI_HS_AUTH_MODE_TOTAL, SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK, wifi_auth_mode_sel_str};
static const cui_inline_item_caption_struct     wifi_inline_psk_cap = {STR_ID_SRV_TETHERING_WIFI_PW_CAPTION};
static const cui_inline_item_text_edit_struct   wifi_inline_psk_edit = {0, 0, SRV_TETHERING_HOSTAP_PSK_MAX_BUF_LEN, IMM_INPUT_TYPE_ASCII_PASSWORD, 0, NULL};

static const cui_inline_set_item_struct g_tethering_wifi_hs_settings_inline_items[] =
{
    {
        TETHERING_WIFI_INLINE_ITEM_SWITCH_CAP,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        IMG_GLOBAL_L1,
        (void*)&wifi_inline_switch_cap
    },
    {
        TETHERING_WIFI_INLINE_ITEM_SWITCH_SEL,
        CUI_INLINE_ITEM_TYPE_SELECT,
        0,
        (void*)&wifi_inline_switch_sel
    },
    {
        TETHERING_WIFI_INLINE_ITEM_AUTO_TURN_OFF_CAP,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        IMG_GLOBAL_L2,
        (void*)&wifi_inline_auto_turn_off_cap
    },
    {
        TETHERING_WIFI_INLINE_ITEM_AUTO_TURN_OFF_SEL,
        CUI_INLINE_ITEM_TYPE_SELECT,
        0,
        (void*)&wifi_inline_auto_turn_off_sel
    },
    {
        TETHERING_WIFI_INLINE_ITEM_SSID_CAP,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        IMG_GLOBAL_L3,
        (void*)&wifi_inline_ssid_cap},
    {
        TETHERING_WIFI_INLINE_ITEM_SSID_EDIT,
        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_DISPLAY_NO_RESPONSE_NUMKEY,
        0,
        (void*)&wifi_inline_ssid_edit
    },
    {
        TETHERING_WIFI_INLINE_ITEM_AUTH_MODE_CAP,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        IMG_GLOBAL_L4,
        (void*)&wifi_inline_auth_mode_cap
    },
    {
        TETHERING_WIFI_INLINE_ITEM_AUTH_MODE_SEL,
        CUI_INLINE_ITEM_TYPE_SELECT,
        0,
        (void*)&wifi_inline_auth_mode_sel
    },
    {
        TETHERING_WIFI_INLINE_ITEM_PSK_CAP,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        IMG_GLOBAL_L5,
        (void*)&wifi_inline_psk_cap
    },
    {
        TETHERING_WIFI_INLINE_ITEM_PSK_EDIT,
        CUI_INLINE_ITEM_TYPE_TEXT_EDIT,
        0,
        (void*)&wifi_inline_psk_edit
    }
};

static const cui_inline_item_caption_struct      conn_info_inline_used_sim_cap = {STR_ID_SRV_TETHERING_CONN_INFO_CURR_USED_SIM};
static const cui_inline_item_display_only_struct conn_info_inline_used_sim_display = {0, 0};
static const cui_inline_item_caption_struct      conn_info_inline_proxy_cap = {STR_GLOBAL_PROXY};
static const cui_inline_item_display_only_struct conn_info_inline_proxy_display = {0, 0};
static const cui_inline_item_caption_struct      conn_info_inline_apn_cap = {STR_ID_SRV_TETHERING_CONN_INFO_APN};
static const cui_inline_item_display_only_struct conn_info_inline_apn_display = {0, 0};
static const cui_inline_item_caption_struct      conn_info_inline_wifi_hs_sta_num_cap = {STR_ID_SRV_TETHERING_CONN_INFO_STA_NUM};
static const cui_inline_item_display_only_struct conn_info_inline_wifi_hs_sta_num_display = {0, 0};
static const cui_inline_item_caption_struct      conn_info_inline_usb_status_cap = {STR_ID_SRV_TETHERING_USB};
static const cui_inline_item_display_only_struct conn_info_inline_usb_status_display = {0, 0};

static const cui_inline_set_item_struct g_tethering_conn_info_inline_items[] =
{
    {
        TETHERING_CONN_INFO_INLINE_ITEM_USED_SIM_CAP,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        0,
        (void*)&conn_info_inline_used_sim_cap
    },
    {
        TETHERING_CONN_INFO_INLINE_ITEM_USED_SIM_DISPLAY,
        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW,
        0,
        (void*)&conn_info_inline_used_sim_display
    },
    {
        TETHERING_CONN_INFO_INLINE_ITEM_PROXY_CAP,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        0,
        (void*)&conn_info_inline_proxy_cap
    },
    {
        TETHERING_CONN_INFO_INLINE_ITEM_PROXY_DISPLAY,
        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW,
        0,
        (void*)&conn_info_inline_proxy_display
    },
    {
        TETHERING_CONN_INFO_INLINE_ITEM_APN_CAP,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        0,
        (void*)&conn_info_inline_apn_cap
    },
    {
        TETHERING_CONN_INFO_INLINE_ITEM_APN_DISPLAY,
        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW,
        0,
        (void*)&conn_info_inline_apn_display
    },
    {
        TETHERING_CONN_INFO_INLINE_ITEM_WIFI_HS_STA_NUM_CAP,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        0,
        (void*)&conn_info_inline_wifi_hs_sta_num_cap
    },
    {
        TETHERING_CONN_INFO_INLINE_ITEM_WIFI_HS_STA_NUM_DISPLAY,
        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW,
        0,
        (void*)&conn_info_inline_wifi_hs_sta_num_display
    },
    {
        TETHERING_CONN_INFO_INLINE_ITEM_USB_STATUS_CAP,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        0,
        (void*)&conn_info_inline_usb_status_cap
    },
    {
        TETHERING_CONN_INFO_INLINE_ITEM_USB_STATUS_DISPLAY,
        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW,
        0,
        (void*)&conn_info_inline_usb_status_display
    }
};
/***************************************************************************** 
* Global Function
*****************************************************************************/

/***************************************************************************** 
* External Variable
*****************************************************************************/

/***************************************************************************** 
* External Function
*****************************************************************************/

/*****************************************************************************
* Local Function 
*****************************************************************************/
mmi_ret mmi_tethering_scr_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    cui_event_inline_common_struct *inline_common = (cui_event_inline_common_struct*)evt;
    cui_dtcnt_select_event_any_sim_selected_struct *dtcnt_select = (cui_dtcnt_select_event_any_sim_selected_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
        #ifdef __MMI_TETHERING_WIFI__
            MMI_STR_ID hint_str = 0;
            srv_tethering_status_enum status = srv_tethering_get_status(SRV_TETHERING_TYPE_WIFI_HS);
            if (status == SRV_TETHERING_STATUS_SRV_ON)
            {
                hint_str = STR_GLOBAL_ON;
            }
            else if (status == SRV_TETHERING_STATUS_SRV_OFF)
            {
                hint_str = STR_GLOBAL_OFF;
            }

            if (hint_str != 0)
            {
                cui_menu_set_item_hint(
                    tethering_cntx.main_scr_cui_menu_id,
                    MENU_ID_TETHERING_WIFI_HS,
                    (WCHAR*)GetString(hint_str));
            }
        #endif

            if (srv_tethering_any_type_is_on() == MMI_FALSE)
            {
                cui_menu_set_item_disabled(
                    tethering_cntx.main_scr_cui_menu_id,
                    MENU_ID_TETHERING_DATA_ACCOUNT,
                    MMI_FALSE);
                cui_menu_set_item_disabled(
                    tethering_cntx.main_scr_cui_menu_id,
                    MENU_ID_TETHERING_CONN_INFO,
                    MMI_TRUE);
            }
            else
            {
                cui_menu_set_item_disabled(
                    tethering_cntx.main_scr_cui_menu_id,
                    MENU_ID_TETHERING_DATA_ACCOUNT,
                    MMI_TRUE);
                cui_menu_set_item_disabled(
                    tethering_cntx.main_scr_cui_menu_id,
                    MENU_ID_TETHERING_CONN_INFO,
                    MMI_FALSE);
            }
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            switch(menu_evt->highlighted_menu_id)
            {
            #ifdef __MMI_TETHERING_WIFI__
                case MENU_ID_TETHERING_WIFI_HS:
                {
                    srv_tethering_status_enum curr_status = srv_tethering_get_status(SRV_TETHERING_TYPE_WIFI_HS);
                    if (curr_status != SRV_TETHERING_STATUS_SRV_ON &&
                        curr_status != SRV_TETHERING_STATUS_SRV_OFF)
                    {
                        mmi_popup_display_simple(
                            (WCHAR*)GetString(STR_GLOBAL_BUSY_TRY_LATER),
                            MMI_EVENT_FAILURE,
                            GRP_ID_ROOT,
                            NULL);
                    }
                    else
                    {
                        srv_tethering_wifi_hs_settings_struct curr_settings;

                        srv_tethering_wifi_hs_get_settings(&curr_settings);
                        tethering_cntx.ssid_display_buf =
                            OslMalloc(SRV_TETHERING_HOSTAP_SSID_MAX_BUF_LEN * 2);
                        mmi_chset_utf8_to_ucs2_string(
                            (kal_uint8*)tethering_cntx.ssid_display_buf,
                            SRV_TETHERING_HOSTAP_SSID_MAX_BUF_LEN * 2,
                            (kal_uint8*)curr_settings.ssid);
                        
                        tethering_cntx.ssid_edit_buf =
                            OslMalloc(SRV_TETHERING_HOSTAP_SSID_MAX_BUF_LEN * 2);

                        mmi_tethering_entry_wifi();
                    }
                    break;
                }

                case MENU_ID_TETHERING_WIFI_SSID_EDITOR_OPTION_DONE:
                {
                    mmi_tethering_wifi_ssid_full_editor_option_done_hdlr();
                    break;
                }
            #endif
                case MENU_ID_TETHERING_DATA_ACCOUNT:
                {
                    mmi_tethering_entry_data_account();
                    break;
                }

                case MENU_ID_TETHERING_CONN_INFO:
                {
                    mmi_tethering_entry_conn_info();
                    break;
                }

                case MENU_ID_TETHERING_HELP:
                {
                    mmi_tethering_entry_help();
                    break;
                }

                default:
                    break;
            }
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;

        default:
            break;
    }

    if (evt->evt_id > INLINE_EDITOR_BASE && evt->evt_id < EVT_ID_CUI_INLINE_MAX)
    {
    #ifdef __MMI_TETHERING_WIFI__
        if (inline_common->sender_id == tethering_cntx.wifi_hs_settings_scr_cui_inline_id)
        {
            U8 status_index;
            U8 auth_mode_index;
            tethering_wifi_settings_switch_item_enum status;
            srv_tethering_wifi_hs_auth_mode_enum curr_auth_mode;
            cui_inline_get_value(
                inline_common->sender_id,
                TETHERING_WIFI_INLINE_ITEM_SWITCH_SEL,
                &status_index);
            status = (tethering_wifi_settings_switch_item_enum)status_index;
            cui_inline_get_value(
                inline_common->sender_id,
                TETHERING_WIFI_INLINE_ITEM_AUTH_MODE_SEL,
                &auth_mode_index);
            curr_auth_mode = (srv_tethering_wifi_hs_auth_mode_enum)auth_mode_index;

            switch(evt->evt_id)
            {
                case EVT_ID_CUI_INLINE_SET_KEY:
                {
                    cui_event_inline_set_key_struct *set_key_evt =
                        (cui_event_inline_set_key_struct*)evt;
                    if (set_key_evt->item_id == TETHERING_WIFI_INLINE_ITEM_SSID_EDIT)
                    {
                        cui_inline_set_softkey_text(
                            set_key_evt->sender_id,
                            TETHERING_WIFI_INLINE_ITEM_SSID_EDIT,
                            MMI_LEFT_SOFTKEY,
                            STR_GLOBAL_EDIT);
                        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
                        wgui_inline_set_lsk_function(mmi_tethering_wifi_entry_ssid_editor);
                        SetCenterSoftkeyFunction(mmi_tethering_wifi_entry_ssid_editor, KEY_EVENT_UP);
                    }
                    break;
                }

                case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
                {
                    if (status == TETHERING_WIFI_SETTINGS_SWITCH_ITEM_OFF)
                    {
                        cui_inline_set_item_attributes(
                            inline_common->sender_id,
                            TETHERING_WIFI_INLINE_ITEM_SSID_EDIT,
                            CUI_INLINE_SET_ATTRIBUTE,
                            CUI_INLINE_ITEM_DISABLE);
                        cui_inline_set_item_attributes(
                            inline_common->sender_id,
                            TETHERING_WIFI_INLINE_ITEM_AUTH_MODE_SEL,
                            CUI_INLINE_SET_ATTRIBUTE,
                            CUI_INLINE_ITEM_DISABLE);
                        cui_inline_set_item_attributes(
                            inline_common->sender_id,
                            TETHERING_WIFI_INLINE_ITEM_PSK_EDIT,
                            CUI_INLINE_SET_ATTRIBUTE,
                            CUI_INLINE_ITEM_DISABLE);
                    }

                    if (curr_auth_mode == SRV_TETHERING_WIFI_HS_AUTH_MODE_OPEN)
                    {
                        cui_inline_delete_item(
                            inline_common->sender_id,
                            TETHERING_WIFI_INLINE_ITEM_PSK_CAP);
                        cui_inline_delete_item(
                            inline_common->sender_id,
                            TETHERING_WIFI_INLINE_ITEM_PSK_EDIT);
                    }
                    break;
                }

                case EVT_ID_CUI_INLINE_NOTIFY:
                {
                    cui_event_inline_notify_struct *inline_notify = (cui_event_inline_notify_struct*)evt;

                    if (inline_notify->event_type == CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED)
                    {
                        if (inline_notify->param == inline_notify->param_ext)
                        {
                            // no change
                            break;
                        }

                        if (inline_notify->item_id == TETHERING_WIFI_INLINE_ITEM_SWITCH_SEL)
                        {
                            if (inline_notify->param == TETHERING_WIFI_SETTINGS_SWITCH_ITEM_OFF)
                            {
                                cui_inline_set_item_attributes(
                                    inline_notify->sender_id,
                                    TETHERING_WIFI_INLINE_ITEM_SSID_EDIT,
                                    CUI_INLINE_SET_ATTRIBUTE,
                                    CUI_INLINE_ITEM_DISABLE);
                                cui_inline_set_item_attributes(
                                    inline_notify->sender_id,
                                    TETHERING_WIFI_INLINE_ITEM_AUTH_MODE_SEL,
                                    CUI_INLINE_SET_ATTRIBUTE,
                                    CUI_INLINE_ITEM_DISABLE);
                                cui_inline_set_item_attributes(
                                    inline_notify->sender_id,
                                    TETHERING_WIFI_INLINE_ITEM_PSK_EDIT,
                                    CUI_INLINE_SET_ATTRIBUTE,
                                    CUI_INLINE_ITEM_DISABLE);
                            }
                            else
                            {
                                cui_inline_set_item_attributes(
                                    inline_notify->sender_id,
                                    TETHERING_WIFI_INLINE_ITEM_SSID_EDIT,
                                    CUI_INLINE_RESET_ATTRIBUTE,
                                    CUI_INLINE_ITEM_DISABLE);
                                cui_inline_set_item_attributes(
                                    inline_notify->sender_id,
                                    TETHERING_WIFI_INLINE_ITEM_AUTH_MODE_SEL,
                                    CUI_INLINE_RESET_ATTRIBUTE,
                                    CUI_INLINE_ITEM_DISABLE);
                                if (curr_auth_mode == SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK)
                                {
                                    cui_inline_set_item_attributes(
                                        inline_notify->sender_id,
                                        TETHERING_WIFI_INLINE_ITEM_PSK_EDIT,
                                        CUI_INLINE_RESET_ATTRIBUTE,
                                        CUI_INLINE_ITEM_DISABLE);
                                }
                            }
                        }
                        else if (inline_notify->item_id == TETHERING_WIFI_INLINE_ITEM_AUTH_MODE_SEL)
                        {
                            static WCHAR w_psk[SRV_TETHERING_HOSTAP_PSK_MAX_BUF_LEN];
                            srv_tethering_wifi_hs_auth_mode_enum new_auth_mode;
                            new_auth_mode = (srv_tethering_wifi_hs_auth_mode_enum)inline_notify->param;

                            if (new_auth_mode == SRV_TETHERING_WIFI_HS_AUTH_MODE_OPEN)
                            {
                                cui_inline_get_value(
                                    inline_notify->sender_id,
                                    TETHERING_WIFI_INLINE_ITEM_PSK_EDIT,
                                    w_psk);
                                cui_inline_delete_item(
                                    inline_notify->sender_id,
                                    TETHERING_WIFI_INLINE_ITEM_PSK_CAP);
                                cui_inline_delete_item(
                                    inline_notify->sender_id,
                                    TETHERING_WIFI_INLINE_ITEM_PSK_EDIT);
                            }
                            else if (new_auth_mode == SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK)
                            {
                                cui_inline_set_item_struct *psk_cap_item =
                                    (cui_inline_set_item_struct*)&g_tethering_wifi_hs_settings_inline_items[TETHERING_WIFI_INLINE_ITEM_PSK_CAP - CUI_INLINE_ITEM_ID_BASE];
                                cui_inline_set_item_struct *psk_edit_item =
                                    (cui_inline_set_item_struct*)&g_tethering_wifi_hs_settings_inline_items[TETHERING_WIFI_INLINE_ITEM_PSK_EDIT - CUI_INLINE_ITEM_ID_BASE];

                                cui_inline_insert_item(
                                    inline_notify->sender_id,
                                    CUI_INLINE_INSERT_TAIL,
                                    psk_cap_item);

                                cui_inline_insert_item(
                                    inline_notify->sender_id,
                                    CUI_INLINE_INSERT_TAIL,
                                    psk_edit_item);

                                cui_inline_set_value(
                                    inline_notify->sender_id,
                                    TETHERING_WIFI_INLINE_ITEM_PSK_EDIT,
                                    w_psk);
                            }
                        }
                    }

                    if (inline_notify->event_type == CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM)
                    {
                        // prevent to display the unmatched characters on VK
                        if (inline_notify->item_id == TETHERING_WIFI_INLINE_ITEM_PSK_EDIT)
                        {
                            cui_inline_set_characters_filter(
                                    inline_common->sender_id,
                                    MMI_TRUE,
                                    g_tethering_key_extra_chars);
                        }
                    }
                    break;
                }

                case EVT_ID_CUI_INLINE_SUBMIT:
                case EVT_ID_CUI_INLINE_CSK_PRESS:
                {
                    mmi_tethering_wifi_hs_settings_save_hdlr();
                    break;
                }

                case EVT_ID_CUI_INLINE_ABORT:
                {
                    cui_event_inline_abort_struct *inline_abort = (cui_event_inline_abort_struct*)evt;
                    cui_inline_close(inline_abort->sender_id);
                    break;
                }

                case EVT_ID_CUI_INLINE_GROUP_DEINIT:
                {
                    if (tethering_cntx.wifi_hs_temp_settings != NULL)
                    {
                        OslMfree(tethering_cntx.wifi_hs_temp_settings);
                        tethering_cntx.wifi_hs_temp_settings = NULL;
                    }
                    if (tethering_cntx.ssid_display_buf != NULL)
                    {
                        OslMfree(tethering_cntx.ssid_display_buf);
                    }
                    if (tethering_cntx.ssid_edit_buf != NULL)
                    {
                        OslMfree(tethering_cntx.ssid_edit_buf);
                    }
                    tethering_cntx.wifi_hs_settings_scr_cui_inline_id = 0;
                    break;
                }

                default:
                    break;
            }
        }
    #endif /* __MMI_TETHERING_WIFI__ */

        if (inline_common->sender_id == tethering_cntx.conn_info_cui_inline_id)
        {
            switch(evt->evt_id)
            {
                case EVT_ID_CUI_INLINE_SET_KEY:
                {
                    cui_event_inline_set_key_struct *set_key_evt = (cui_event_inline_set_key_struct*)evt;
                    if (set_key_evt->item_id == TETHERING_CONN_INFO_INLINE_ITEM_PROXY_DISPLAY)
                    {
                        ChangeLeftSoftkey(STR_GLOBAL_VIEW, IMG_GLOBAL_OK);
                        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
                        SetLeftSoftkeyFunction(mmi_tethering_entry_proxy, KEY_EVENT_UP);
                        SetCenterSoftkeyFunction(mmi_tethering_entry_proxy, KEY_EVENT_UP);
                    }
                    break;
                }

                case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
                {
                    if (MMI_SIM_TOTAL == 1)
                    {
                        cui_inline_delete_item(
                            inline_common->sender_id,
                            TETHERING_CONN_INFO_INLINE_ITEM_USED_SIM_CAP);
                        cui_inline_delete_item(
                            inline_common->sender_id,
                            TETHERING_CONN_INFO_INLINE_ITEM_USED_SIM_DISPLAY);
                    }
                    break;
                }
                
                case EVT_ID_CUI_INLINE_ABORT:
                {
                    cui_event_inline_abort_struct *inline_abort = (cui_event_inline_abort_struct*)evt;
                    cui_inline_close(inline_abort->sender_id);
                    break;
                }

                case EVT_ID_CUI_INLINE_GROUP_DEINIT:
                {
                    OslMfree(tethering_cntx.conn_info_display);
                    tethering_cntx.conn_info_cui_inline_id = 0;
                    break;
                }

                default:
                    break;
            }
        }
    }

    switch (dtcnt_select->evt_id)
    {
        case CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:
        {            
            cui_dtcnt_sim_enum sim = dtcnt_select->selectSim;
            srv_tethering_save_dtcnt(
                (srv_dtcnt_sim_type_enum)(sim+1),
                dtcnt_select->accountId);
            break;
        }

        case CUI_DTCNT_SELECT_EVENT_RESULT_OK:
        case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
        case CUI_DTCNT_SELECT_EVENT_RESULT_FAILED:
        case CUI_DTCNT_SELECT_EVENT_CLOSE:
        {
            cui_dtcnt_select_close(dtcnt_select->sender_id);
            break;
        }
        
        default:
            break;
    }

    wgui_inputs_options_menu_handler(
        (mmi_event_struct*)menu_evt,
        GRP_ID_TETHERING_MAIN);

    return MMI_RET_OK;
}


void mmi_tethering_highlight_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(mmi_tethering_launch, KEY_EVENT_UP);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_tethering_launch, KEY_EVENT_UP);
}


void mmi_tethering_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tethering_status_enum curr_status_wifi = srv_tethering_get_status(SRV_TETHERING_TYPE_WIFI_HS);
    srv_tethering_status_enum curr_status_usb = srv_tethering_get_status(SRV_TETHERING_TYPE_USB);
    MMI_BOOL flag = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_tethering_check_launch_main_menu_capab() != SRV_TETHERING_LAUNCH_RESULT_OK)
    {
        mmi_popup_display_simple(
            (WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
            MMI_EVENT_FAILURE,
            GRP_ID_ROOT,
            NULL);
        return;
    }

#ifdef __MMI_TETHERING_WIFI__
    if (curr_status_wifi == SRV_TETHERING_STATUS_ON_SWITCHING_OFF ||
        curr_status_wifi == SRV_TETHERING_STATUS_ON_SWITCHING_ON)
    {
        flag = MMI_TRUE;
    }
#endif
#ifdef __USB_TETHERING__
    if (curr_status_usb == SRV_TETHERING_STATUS_ON_SWITCHING_OFF ||
        curr_status_usb == SRV_TETHERING_STATUS_ON_SWITCHING_ON)
    {
        flag = MMI_TRUE;
    }
#endif

    if (flag)
    {
        mmi_popup_display_simple(
            (WCHAR*)GetString(STR_GLOBAL_BUSY_TRY_LATER),
            MMI_EVENT_FAILURE,
            GRP_ID_ROOT,
            NULL);
        return;
    }

    srv_tethering_reg_app_avail_status_change_cb(mmi_tethering_avail_status_change_cb_hdlr, NULL);

    mmi_frm_group_create(
        GRP_ID_ROOT,
        GRP_ID_TETHERING_MAIN,
        mmi_tethering_scr_group_proc,
        (void*)NULL);
    mmi_frm_group_enter(GRP_ID_TETHERING_MAIN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_tethering_entry_main();
}


void mmi_tethering_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tethering_cntx.main_scr_cui_menu_id = cui_menu_create(
                                            GRP_ID_TETHERING_MAIN,
                                            CUI_MENU_SRC_TYPE_RESOURCE,
                                            CUI_MENU_TYPE_APPMAIN,
                                            MENU_ID_TETHERING,
                                            MMI_TRUE,
                                            NULL);

    cui_menu_set_default_title_image(
        tethering_cntx.main_scr_cui_menu_id,
        (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_TETHERING)));
    cui_menu_run(tethering_cntx.main_scr_cui_menu_id);
}


#ifdef __MMI_TETHERING_WIFI__
void mmi_tethering_entry_wifi(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_struct settings_inline;
    srv_tethering_wifi_hs_settings_struct curr_settings;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_tethering_wifi_hs_get_settings(&curr_settings);

    settings_inline.items_count =
        TETHERING_WIFI_INLINE_ITEM_TOTAL -
        CUI_INLINE_ITEM_ID_BASE;
    settings_inline.title = STR_ID_SRV_TETHERING_WIFI_HS;
    settings_inline.title_icon = GetRootTitleIcon(MENU_ID_TETHERING);
    settings_inline.screen_flag = CUI_INLINE_SCREEN_LOOP;
    settings_inline.softkey = NULL;
    settings_inline.items = g_tethering_wifi_hs_settings_inline_items;
    tethering_cntx.wifi_hs_settings_scr_cui_inline_id =
        cui_inline_create(GRP_ID_TETHERING_MAIN, &settings_inline);

    // set switch selection
    {
        // set U8 type to change the selection, 0 is off, 1 is on
        //also refer to wifi_switch_sel_str
        U8 switch_index = 0;
        srv_tethering_status_enum status =
            srv_tethering_get_status(SRV_TETHERING_TYPE_WIFI_HS);

        if (status == SRV_TETHERING_STATUS_SRV_OFF)
        {
            switch_index = (U8)TETHERING_WIFI_SETTINGS_SWITCH_ITEM_OFF;
        }
        else if (status == SRV_TETHERING_STATUS_SRV_ON)
        {
            switch_index = (U8)TETHERING_WIFI_SETTINGS_SWITCH_ITEM_ON;
        }
        else
        {
            MMI_ASSERT(0);
        }

        cui_inline_set_value(
            tethering_cntx.wifi_hs_settings_scr_cui_inline_id,
            TETHERING_WIFI_INLINE_ITEM_SWITCH_SEL,
            (void*)switch_index);
    }

    // set auto turn off selection
    {
        MMI_BOOL auto_turn_off_flag = srv_tethering_check_auto_turn_off_flag();
        U8 auto_turn_off_index = 0;
        if (auto_turn_off_flag == MMI_TRUE)
        {
            auto_turn_off_index = (U8)TETHERING_WIFI_SETTINGS_AUTO_TURN_OFF_ITEM_ON;
        }
        else
        {
            auto_turn_off_index = (U8)TETHERING_WIFI_SETTINGS_AUTO_TURN_OFF_ITEM_OFF;
        }

        cui_inline_set_value(
            tethering_cntx.wifi_hs_settings_scr_cui_inline_id,
            TETHERING_WIFI_INLINE_ITEM_AUTO_TURN_OFF_SEL,
            (void*)auto_turn_off_index);
    }

    // set auth mode selection
    {
        // set U8 type to change the selection, 0 is off, 1 is on
        //also refer to wifi_auth_mode_sel_str
        U8 auth_mode_index = 0;

        if (curr_settings.auth_mode == SRV_TETHERING_WIFI_HS_AUTH_MODE_OPEN)
        {
            auth_mode_index = (U8)SRV_TETHERING_WIFI_HS_AUTH_MODE_OPEN;
        }
        else if (curr_settings.auth_mode == SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK)
        {
            auth_mode_index = (U8)SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK;
        }
        else
        {
            MMI_ASSERT(0);
        }

        cui_inline_set_value(
            tethering_cntx.wifi_hs_settings_scr_cui_inline_id,
            TETHERING_WIFI_INLINE_ITEM_AUTH_MODE_SEL,
            (void*)auth_mode_index);
    }

    // set ssid editor
    {
        cui_inline_set_value(
            tethering_cntx.wifi_hs_settings_scr_cui_inline_id,
            TETHERING_WIFI_INLINE_ITEM_SSID_EDIT,
            tethering_cntx.ssid_display_buf);
    }

    // set psk editor
    {
        WCHAR w_psk[SRV_TETHERING_HOSTAP_PSK_MAX_BUF_LEN];
        mmi_asc_to_wcs(w_psk, (CHAR*)curr_settings.psk);
        cui_inline_set_value(
            tethering_cntx.wifi_hs_settings_scr_cui_inline_id,
            TETHERING_WIFI_INLINE_ITEM_PSK_EDIT,
            w_psk);
    }

    tethering_cntx.wifi_hs_temp_settings = OslMalloc(sizeof(mmi_tethering_wifi_hs_settings_struct));
    cui_inline_run(tethering_cntx.wifi_hs_settings_scr_cui_inline_id);
}


void mmi_tethering_wifi_entry_ssid_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_TETHERING_MAIN, 
                        SCR_ID_TETHERING_WIFI_SSID_EDITOR,
                        NULL,
                        (FuncPtr)mmi_tethering_wifi_entry_ssid_editor, 
                        MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        if (gui_buffer == NULL)
        {
            mmi_wcscpy(
                tethering_cntx.ssid_edit_buf,
                tethering_cntx.ssid_display_buf);
        }

        wgui_cat_editor_disable_new_line_symbol(MMI_TRUE);
        ShowCategory215Screen(
            STR_ID_SRV_TETHERING_WIFI_HS_SSID,
            GetRootTitleIcon(MENU_ID_TETHERING),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            IMM_INPUT_TYPE_SENTENCE,
            (U8*)tethering_cntx.ssid_edit_buf,
            SRV_TETHERING_HOSTAP_SSID_MAX_BUF_LEN,
            gui_buffer);

        SetLeftSoftkeyFunction(mmi_tethering_wifi_ssid_entry_full_editor_option, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_tethering_wifi_ssid_entry_full_editor_option, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
        //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
}



void mmi_tethering_wifi_ssid_entry_full_editor_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_id = cui_menu_create(
                    GRP_ID_TETHERING_MAIN,
                    CUI_MENU_SRC_TYPE_RESOURCE,
                    CUI_MENU_TYPE_OPTION,
                    MENU_ID_TETHERING_WIFI_SSID_EDITOR_OPTION,
                    MMI_TRUE,
                    NULL);

    cui_menu_set_default_title_image(
        cui_menu_id,
        (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_TETHERING)));
    cui_menu_run(cui_menu_id);
}


void mmi_tethering_wifi_ssid_full_editor_option_done_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy(tethering_cntx.ssid_display_buf, tethering_cntx.ssid_edit_buf);
    mmi_frm_scrn_close_active_id();
    mmi_frm_scrn_close(GRP_ID_TETHERING_MAIN, SCR_ID_TETHERING_WIFI_SSID_EDITOR);
}


void mmi_tehering_wifi_hs_get_value_from_settings_inline(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 switch_index;
    U8 auth_mode_index;
    WCHAR w_ssid[SRV_TETHERING_HOSTAP_SSID_MAX_BUF_LEN];
    WCHAR w_psk[SRV_TETHERING_HOSTAP_PSK_MAX_BUF_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(tethering_cntx.wifi_hs_temp_settings, 0x00, sizeof(mmi_tethering_wifi_hs_settings_struct));
    srv_tethering_wifi_hs_get_settings(&tethering_cntx.wifi_hs_temp_settings->srv_wifi_hs_settings);
    cui_inline_get_value(
        tethering_cntx.wifi_hs_settings_scr_cui_inline_id,
        TETHERING_WIFI_INLINE_ITEM_SWITCH_SEL,
        &switch_index);
    cui_inline_get_value(
        tethering_cntx.wifi_hs_settings_scr_cui_inline_id,
        TETHERING_WIFI_INLINE_ITEM_SSID_EDIT,
        w_ssid);
    cui_inline_get_value(
        tethering_cntx.wifi_hs_settings_scr_cui_inline_id,
        TETHERING_WIFI_INLINE_ITEM_AUTH_MODE_SEL,
        &auth_mode_index);
    if ((srv_tethering_wifi_hs_auth_mode_enum)auth_mode_index == SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK)
    {
        cui_inline_get_value(
            tethering_cntx.wifi_hs_settings_scr_cui_inline_id,
            TETHERING_WIFI_INLINE_ITEM_PSK_EDIT,
            w_psk);
    }

    tethering_cntx.wifi_hs_temp_settings->srv_wifi_hs_settings.auth_mode =
        (srv_tethering_wifi_hs_auth_mode_enum)auth_mode_index;

    mmi_chset_ucs2_to_utf8_string(
        (kal_uint8*)tethering_cntx.wifi_hs_temp_settings->srv_wifi_hs_settings.ssid,
        SRV_TETHERING_HOSTAP_SSID_MAX_BUF_LEN,
        (kal_uint8*)w_ssid);

    if (tethering_cntx.wifi_hs_temp_settings->srv_wifi_hs_settings.auth_mode == SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK)
    {
        mmi_wcs_to_asc(
            tethering_cntx.wifi_hs_temp_settings->srv_wifi_hs_settings.psk,
            w_psk);
    }

    if ((tethering_wifi_settings_switch_item_enum)switch_index == TETHERING_WIFI_SETTINGS_SWITCH_ITEM_OFF)
    {
        tethering_cntx.wifi_hs_temp_settings->is_switch_on = MMI_FALSE;
    }
    else if ((tethering_wifi_settings_switch_item_enum)switch_index == TETHERING_WIFI_SETTINGS_SWITCH_ITEM_ON)
    {
        tethering_cntx.wifi_hs_temp_settings->is_switch_on = MMI_TRUE;
    }
}


void mmi_tethering_wifi_hs_settings_save_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_TETHERING__    
    if (srv_tethering_get_status(SRV_TETHERING_TYPE_USB) == SRV_TETHERING_STATUS_SRV_ON)
    {
        mmi_popup_property_struct arg;
        mmi_popup_property_init(&arg);
        
        arg.parent_id = GRP_ID_TETHERING_MAIN;
        arg.f_msg_icon = MMI_FALSE;

        mmi_popup_display(
            (WCHAR*)GetString(STR_ID_SRV_TETHERING_USB_TETHERING_ACTIVATED_WARNNING),
            MMI_EVENT_FAILURE,
            &arg);
        return;
    }
#endif

    mmi_tehering_wifi_hs_get_value_from_settings_inline();

    if (tethering_cntx.wifi_hs_temp_settings->is_switch_on == MMI_FALSE)
    {
        // only status is on should switch off the tethering
        if (srv_tethering_get_status(SRV_TETHERING_TYPE_WIFI_HS) == SRV_TETHERING_STATUS_SRV_ON)
        {
            mmi_tethering_display_waiting_screen(GRP_ID_TETHERING_MAIN);
            srv_tethering_switch_off(
                SRV_TETHERING_TYPE_WIFI_HS,
                mmi_tethering_wifi_hs_switch_hdlr,
                NULL);
        }

        // mmi_tethering_wifi_hs_save_settings should be in front of cui_inline_close
        // as when close inline screen it will free the setting temp buffer
        mmi_tethering_wifi_hs_save_settings();
        cui_inline_close(tethering_cntx.wifi_hs_settings_scr_cui_inline_id);
    }
    else if (tethering_cntx.wifi_hs_temp_settings->is_switch_on == MMI_TRUE)
    {
        if (strlen(tethering_cntx.wifi_hs_temp_settings->srv_wifi_hs_settings.ssid) == 0)
        {
            mmi_popup_display_simple(
                (WCHAR*)GetString(STR_ID_SRV_TETHERING_WIFI_SSID_EMPTY_WARNING),
                MMI_EVENT_FAILURE,
                GRP_ID_TETHERING_MAIN,
                NULL);
            return;
        }

        if (tethering_cntx.wifi_hs_temp_settings->srv_wifi_hs_settings.auth_mode == SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK &&
            strlen(tethering_cntx.wifi_hs_temp_settings->srv_wifi_hs_settings.psk) < HOSTAP_PSK_MIN_LEN)
        {
            mmi_popup_display_simple(
                (WCHAR*)GetString(STR_ID_SRV_TETHERING_WIFI_PW_LENGTH_WARNING_SHORT),
                MMI_EVENT_FAILURE,
                GRP_ID_TETHERING_MAIN,
                NULL);
            return;
        }

        mmi_tethering_entry_switch_on_cnf_popup();
    }
}


void mmi_tethering_wifi_hs_save_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 auto_turn_off_index;
    MMI_BOOL auto_turn_off_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(tethering_cntx.wifi_hs_temp_settings != NULL);
    cui_inline_get_value(
        tethering_cntx.wifi_hs_settings_scr_cui_inline_id,
        TETHERING_WIFI_INLINE_ITEM_AUTO_TURN_OFF_SEL,
        &auto_turn_off_index);
    if (auto_turn_off_index == (U8)TETHERING_WIFI_SETTINGS_AUTO_TURN_OFF_ITEM_ON)
    {
        auto_turn_off_flag = MMI_TRUE;
    }
    else
    {
        auto_turn_off_flag = MMI_FALSE;
    }
    srv_tethering_enable_auto_turn_off(auto_turn_off_flag);
    srv_tethering_wifi_hs_save_settings(&tethering_cntx.wifi_hs_temp_settings->srv_wifi_hs_settings);
}


void mmi_tethering_wifi_hs_switch_hdlr(srv_tethering_type_enum tethering_type, MMI_BOOL result, srv_tethering_status_enum des_status, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL has_proxy = MMI_FALSE;
    srv_dtcnt_prof_proxy_info_struct proxy_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_TETHERING_MAIN) == MMI_TRUE)
    {
        mmi_alert_dismiss(tethering_cntx.waiting_screen_id);
        if (result == MMI_TRUE)
        {
            if (SRV_TETHERING_STATUS_SRV_ON == des_status)
            {
                has_proxy = srv_dtcnt_get_proxy_info(
                    srv_tethering_get_used_dtcnt(),
                    &proxy_info,
                    SRV_DTCNT_ACCOUNT_PRIMARY) && proxy_info.use_proxy;

                if (has_proxy)
                {
                    mmi_frm_nmgr_popup(
                        MMI_SCENARIO_ID_DEFAULT,
                        MMI_EVENT_SUCCESS,
                        (WCHAR*)GetString(STR_ID_SRV_TETHERING_PROXY_PROMPT));
                }
                else
                {
                    mmi_popup_display_simple(
                        (WCHAR*)GetString(STR_GLOBAL_OK),
                        MMI_EVENT_SUCCESS,
                        GRP_ID_TETHERING_MAIN,
                        NULL);
                }
            }
            else
            {
                mmi_popup_display_simple(
                    (WCHAR*)GetString(STR_GLOBAL_OK),
                    MMI_EVENT_SUCCESS,
                    GRP_ID_TETHERING_MAIN,
                    NULL);

                cui_inline_close(tethering_cntx.conn_info_cui_inline_id);
            }
        }
        else
        {
            mmi_popup_display_simple(
                (WCHAR*)GetString(STR_GLOBAL_FAILED),
                MMI_EVENT_FAILURE,
                GRP_ID_TETHERING_MAIN,
                NULL);
        }
    }
    else if (result == MMI_FALSE)
    {
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_GLOBAL_FAILED));
    }
}


mmi_ret mmi_tethering_switch_on_cnf_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert_result_evt = (mmi_alert_result_evt_struct*)evt;
    U32 acct_id = mmi_tethering_get_curr_sim_match_acct();
    mmi_sim_enum mmi_sim_id = mmi_frm_index_to_sim((U32)cbm_get_sim_id(acct_id));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (alert_result_evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (alert_result_evt->result)
        {
            case MMI_ALERT_CNFM_YES:
            {
                if (SRV_TETHERING_LAUNCH_RESULT_INVALID_ACCOUNT ==
                        srv_tethering_check_launch_capab_acct(
                            SRV_TETHERING_TYPE_WIFI_HS,
                            mmi_tethering_get_curr_sim_match_acct()))
                {
                    mmi_popup_display_simple(
                        (WCHAR*)GetString(STR_ID_SRV_TETHERING_INVALID_DATA_ACCOUNT),
                        MMI_EVENT_FAILURE,
                        GRP_ID_TETHERING_MAIN,
                        NULL);
                    break;
                }

                if (srv_tethering_check_launch_capab_nw(mmi_sim_id) != SRV_TETHERING_LAUNCH_RESULT_OK)
                {
                    mmi_popup_display_simple(
                        (WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
                        MMI_EVENT_FAILURE,
                        GRP_ID_TETHERING_MAIN,
                        NULL);
                    break;
                }

                // wlan not off
                if (srv_dtcnt_wlan_state() != SRV_DTCNT_WLAN_STATE_NULL)
                {
                    mmi_tethering_wifi_entry_turn_off_wlan_cnf_popup();
                    break;
                }

                // mmi_tethering_wifi_hs_save_settings should be in front of cui_inline_close
                // as when close inline screen it will free the setting temp buffer
                mmi_tethering_wifi_hs_save_settings();
                cui_inline_close(tethering_cntx.wifi_hs_settings_scr_cui_inline_id);
                mmi_tethering_display_waiting_screen(GRP_ID_TETHERING_MAIN);

                mmi_tethering_switch_on(SRV_TETHERING_TYPE_WIFI_HS);

                break;
            }

            case MMI_ALERT_CNFM_NO:
            {
                break;
            }

            default:
                break;
        }
    }
    return MMI_RET_OK;
}


void mmi_tethering_wifi_entry_turn_off_wlan_cnf_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = GRP_ID_TETHERING_MAIN;
    arg.callback = mmi_tethering_wifi_turn_off_wlan_cnf_hdlr;
    arg.f_enter_history = MMI_TRUE;
    mmi_confirm_display(
        (WCHAR*)GetString(STR_ID_SRV_TETHERING_WIFI_TURN_OFF_WLAN_CNF),
        MMI_EVENT_QUERY,
        &arg);
}


mmi_ret mmi_tethering_wifi_turn_off_wlan_cnf_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert_result_evt = (mmi_alert_result_evt_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (alert_result_evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (alert_result_evt->result)
        {
            case MMI_ALERT_CNFM_YES:
            {
                // mmi_tethering_wifi_hs_save_settings should be in front of cui_inline_close
                // as when close inline screen it will free the setting temp buffer
                mmi_tethering_wifi_hs_save_settings();
                cui_inline_close(tethering_cntx.wifi_hs_settings_scr_cui_inline_id);
                mmi_tethering_display_waiting_screen(GRP_ID_TETHERING_MAIN);

                mmi_tethering_switch_on(SRV_TETHERING_TYPE_WIFI_HS);
                break;
            }

            case MMI_ALERT_CNFM_NO:
            {
                break;
            }

            default:
                break;
        }
    }
    return MMI_RET_OK;
}


MMI_BOOL mmi_tethering_wifi_hs_reconnect(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tethering_conn_info_struct conn_info;
    srv_tethering_launch_result_enum  result;
    srv_dtcnt_sim_type_enum sim_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // need to check before entry screen group
    //MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, MMI_TETHERING_USB_RECONNECT, 4);
    if (mmi_frm_group_is_present(GRP_ID_TETHERING_MAIN))
    {
        mmi_frm_group_close(GRP_ID_TETHERING_MAIN);
    }

    srv_dtcnt_get_sim_preference(&sim_type);
    conn_info.common_account_id = srv_tethering_get_dtcnt(sim_type);
    conn_info.used_sim = sim_type - 1;
    conn_info.conn_info_notify.funcptr = mmi_tethering_conn_info_notify_hdlr;
    conn_info.disconnect_notify.funcptr = mmi_tethering_disconnect_notify_hdlr;
    srv_tethering_set_conn_info(&conn_info);

    result = srv_tethering_check_launch_capab(SRV_TETHERING_TYPE_WIFI_HS);

    if (result == SRV_TETHERING_LAUNCH_RESULT_OK ||
        result == SRV_TETHERING_LAUNCH_RESULT_NETWORK_NOT_READY)
    {
        mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_TETHERING_MAIN, NULL, NULL);
        mmi_frm_group_enter(GRP_ID_TETHERING_MAIN, MMI_FRM_NODE_SMART_CLOSE_FLAG);    
        mmi_tethering_wifi_hs_reconnect_confirm();
    }
    else
    {
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_ID_SRV_TETHERING_WIFI_DISCONNECT));
    }
    return MMI_TRUE;
}


void mmi_tethering_wifi_hs_reconnect_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img_id;
    U8* gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            GRP_ID_TETHERING_MAIN, 
            SCR_ID_TETHERING_WIFI_HS_RECONNECT, 
            NULL, 
            mmi_tethering_wifi_hs_reconnect_confirm, 
            MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_gui_buf(
                        GRP_ID_TETHERING_MAIN, 
                        SCR_ID_TETHERING_WIFI_HS_RECONNECT);
        if (!gui_buffer)
        {
            // here call only once
            //MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, MMI_TETHERING_USB_RECONNECT_CONFIRM);
            srv_tethering_switch_on(
                SRV_TETHERING_TYPE_WIFI_HS,
                mmi_tethering_wifi_hs_reconnect_hdlr,
                NULL);
        }
        img_id = mmi_get_event_based_image(MMI_EVENT_PROGRESS);
        ShowCategory66Screen(
            STR_ID_SRV_TETHERING_WIFI_HS,
            GetRootTitleIcon(MENU_ID_TETHERING),
            0,
            0,
            STR_GLOBAL_CANCEL,
            0,
            (U8*)GetString(STR_ID_SRV_TETHERING_WIFI_RECONNECT),
            img_id,
            gui_buffer);
        //MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, MMI_TETHERING_USB_RECONNECT_CONFIRM);
        SetRightSoftkeyFunction(mmi_tethering_wifi_hs_cancel_reconnect, KEY_EVENT_UP);
        mmi_frm_scrn_set_leave_proc(GRP_ID_TETHERING_MAIN, SCR_ID_TETHERING_WIFI_HS_RECONNECT, mmi_tethering_wifi_hs_reconnect_screen_leave_proc);
    }
}


void mmi_tethering_wifi_hs_cancel_reconnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, MMI_TETHERING_USB_CANCEL_RECONNECT);
    srv_tethering_stop(SRV_TETHERING_TYPE_WIFI_HS, NULL, NULL);
    if (mmi_frm_group_is_present(GRP_ID_TETHERING_MAIN))
    {
        mmi_frm_group_close(GRP_ID_TETHERING_MAIN);
    }
}


mmi_ret mmi_tethering_wifi_hs_reconnect_screen_leave_proc(mmi_event_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (para->evt_id)
    {        
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:        
            //MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, MMI_TETHERING_USB_RECONNECT_SCREEN_LEAVE_PROC);
            srv_tethering_stop(SRV_TETHERING_TYPE_WIFI_HS, NULL, NULL);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


void mmi_tethering_wifi_hs_reconnect_hdlr(srv_tethering_type_enum tethering_type, MMI_BOOL result, srv_tethering_status_enum des_status, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL has_proxy = MMI_FALSE;
    srv_dtcnt_prof_proxy_info_struct proxy_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, MMI_TETHERING_USB_SWITCH_HDLR, result);
    if (mmi_frm_group_is_present(GRP_ID_TETHERING_MAIN) == MMI_TRUE)
    {
        mmi_frm_group_close(GRP_ID_TETHERING_MAIN);
    }

    if (SRV_TETHERING_STATUS_SRV_ON == des_status &&
        result == MMI_TRUE)
    {
        has_proxy = srv_dtcnt_get_proxy_info(
                        srv_tethering_get_used_dtcnt(),
                        &proxy_info,
                        SRV_DTCNT_ACCOUNT_PRIMARY) && proxy_info.use_proxy;

        if (has_proxy)
        {
            mmi_frm_nmgr_popup(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_SUCCESS,
                (WCHAR*)GetString(STR_ID_SRV_TETHERING_PROXY_PROMPT));
        }
        else
        {
            mmi_frm_nmgr_popup(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_SUCCESS,
                (WCHAR*)GetString(STR_GLOBAL_OK));
        }
    }

    if (result == MMI_FALSE)
    {        
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_GLOBAL_FAILED));
    }
}


void mmi_tethering_entry_switch_on_cnf_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = GRP_ID_TETHERING_MAIN;
    arg.callback = mmi_tethering_switch_on_cnf_hdlr;
    arg.f_enter_history = MMI_TRUE;
    mmi_confirm_display(
        (WCHAR*)GetString(STR_ID_SRV_TETHERING_SAVE_ACTIVATE_ASK),
        MMI_EVENT_QUERY,
        &arg);
}


void mmi_tethering_switch_on(srv_tethering_type_enum tethering_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TETHERING_WIFI__
    srv_tethering_conn_info_struct conn_info;
    srv_dtcnt_sim_type_enum sim_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_dtcnt_get_sim_preference(&sim_type);
    conn_info.common_account_id = srv_tethering_get_dtcnt(sim_type);
    conn_info.used_sim = sim_type - 1;
    conn_info.conn_info_notify.funcptr = mmi_tethering_conn_info_notify_hdlr;
    conn_info.disconnect_notify.funcptr = mmi_tethering_disconnect_notify_hdlr;
    srv_tethering_set_conn_info(&conn_info);
    srv_tethering_reg_reactivate_demand_cb_hdlr(
        SRV_TETHERING_TYPE_WIFI_HS,
        mmi_tethering_reactivate_demand_hdlr);
    if (srv_tethering_get_status(SRV_TETHERING_TYPE_WIFI_HS) == SRV_TETHERING_STATUS_SRV_OFF)
    {
        srv_tethering_switch_on(
            SRV_TETHERING_TYPE_WIFI_HS,
            mmi_tethering_wifi_hs_switch_hdlr,
            NULL);
    }
    else if (srv_tethering_get_status(SRV_TETHERING_TYPE_WIFI_HS) == SRV_TETHERING_STATUS_SRV_ON)
    {
        srv_tethering_abm_update_settings(
            SRV_TETHERING_TYPE_WIFI_HS,
            mmi_tethering_wifi_hs_switch_hdlr,
            NULL);
    }
#endif
}


void mmi_tethering_display_update_settings_cnf_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = GRP_ID_TETHERING_MAIN;
    arg.callback = mmi_tethering_update_settings_cnf_cb;
    arg.f_enter_history = MMI_TRUE;
    mmi_confirm_display(
        (WCHAR*)GetString(STR_ID_SRV_TETHERING_SAVE_ACTIVATE_ASK),
        MMI_EVENT_QUERY,
        &arg);
}


mmi_ret mmi_tethering_update_settings_cnf_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert_result_evt = (mmi_alert_result_evt_struct*)evt;
    srv_tethering_conn_info_struct conn_info;
    srv_tethering_type_enum tethering_type = (srv_tethering_type_enum)0;
    srv_dtcnt_sim_type_enum sim_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (alert_result_evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (alert_result_evt->result)
        {
            case MMI_ALERT_CNFM_YES:
            {
                srv_dtcnt_get_sim_preference(&sim_type);
                srv_tethering_save_dtcnt(sim_type, tethering_cntx.dtcnt_info->data_account_id);
                mmi_tethering_display_waiting_screen(GRP_ID_TETHERING_MAIN);

                conn_info.common_account_id = tethering_cntx.dtcnt_info->data_account_id;
                conn_info.used_sim = cbm_get_sim_id(tethering_cntx.dtcnt_info->data_account_id);
                conn_info.conn_info_notify.funcptr = mmi_tethering_conn_info_notify_hdlr;
                conn_info.disconnect_notify.funcptr = mmi_tethering_disconnect_notify_hdlr;
                srv_tethering_set_conn_info(&conn_info);
                for (tethering_type = (srv_tethering_type_enum)0; tethering_type < SRV_TETHERING_TYPE_ALL; tethering_type++)
                {
                    if (srv_tethering_get_status(tethering_type) == SRV_TETHERING_STATUS_SRV_ON)
                    {
                        srv_tethering_abm_update_settings(
                            tethering_type,
                            mmi_tethering_wifi_hs_switch_hdlr,
                            NULL);
                    }
                }

                break;
            }

            case MMI_ALERT_CNFM_NO:
            {
                break;
            }

            default:
                break;
        }
    }

    cui_inline_close(tethering_cntx.dtcnt_info->data_account_cui_id);
    OslMfree(tethering_cntx.dtcnt_info);
    return MMI_RET_OK;
}


#endif /* __MMI_TETHERING_WIFI__ */


void mmi_tethering_entry_data_account(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID dtcnt_id;
    cui_dtcnt_select_run_struct select_run_info;
    S32 i;
    cbm_app_info_struct cbm_app_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&select_run_info, 0x00, sizeof(cui_dtcnt_select_run_struct));
    
    cbm_app_info.app_str_id = STR_ID_SRV_TETHERING;
    cbm_app_info.app_icon_id = 0;
    cbm_app_info.app_type =
        DTCNT_APPTYPE_TETHERING |
        DTCNT_APPTYPE_SKIP_CSD;

    dtcnt_id = cui_dtcnt_select_create(GRP_ID_TETHERING_MAIN);
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        select_run_info.sim_account_id[i] = srv_tethering_get_dtcnt(i+1);
    }
    select_run_info.str_id = STR_ID_SRV_TETHERING;
    select_run_info.icon_id = GetRootTitleIcon(MENU_ID_TETHERING);
    select_run_info.app_id = srv_tethering_get_common_cbm_app_id();
    select_run_info.bearers = DATA_ACCOUNT_BEARER_GPRS;
    select_run_info.option = CUI_DTCNT_SELECT_NOT_SUBSCRIBE_ACCOUNT;
    select_run_info.type = CUI_DTCNT_SELECT_TYPE_NORMAL;
    select_run_info.sim_selection = CUI_DTCNT_SELECT_DUAL_SIM;
    cui_dtcnt_select_set_param(dtcnt_id, &select_run_info);
    cui_dtcnt_select_run(dtcnt_id);
}


void mmi_tethering_entry_conn_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_struct settings_inline;
    srv_tethering_conn_info_struct conn_info;    
    MMI_BOOL has_proxy = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_tethering_get_conn_info(&conn_info);
    
    settings_inline.items_count =
        TETHERING_CONN_INFO_INLINE_ITEM_TOTAL -
        CUI_INLINE_ITEM_ID_BASE;
    settings_inline.title = STR_ID_SRV_TETHERING_CONN_INFO;
    settings_inline.title_icon = GetRootTitleIcon(MENU_ID_TETHERING);
    settings_inline.screen_flag = CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE;
    settings_inline.softkey = NULL;
    settings_inline.items = g_tethering_conn_info_inline_items;
    tethering_cntx.conn_info_cui_inline_id =
        cui_inline_create(GRP_ID_TETHERING_MAIN, &settings_inline);
    tethering_cntx.conn_info_display =
        (mmi_tethering_conn_info_inline_items_display_struct*)OslMalloc(sizeof(mmi_tethering_conn_info_inline_items_display_struct));

    {
        WCHAR *used_sim = NULL;
        MMI_STR_ID str_id = STR_GLOBAL_SIM_1;
        // damn, the sim string index is not continuous...
        switch (conn_info.used_sim)
        {
            case CBM_SIM_ID_SIM1:
                str_id = STR_GLOBAL_SIM_1;
                break;
        
            case CBM_SIM_ID_SIM2:
                str_id = STR_GLOBAL_SIM_2;
                break;
        
            case CBM_SIM_ID_SIM3:
                str_id = STR_GLOBAL_SIM_3;
                break;
        
            case CBM_SIM_ID_SIM4:
                str_id = STR_GLOBAL_SIM_4;
                break;
        
            default:
                ASSERT(0);
                break;
        }
        used_sim = (WCHAR*)GetString(str_id);

        mmi_wcscpy(
            tethering_cntx.conn_info_display->w_used_sim_str,
            used_sim);
        cui_inline_set_value(
            tethering_cntx.conn_info_cui_inline_id,
            TETHERING_CONN_INFO_INLINE_ITEM_USED_SIM_DISPLAY,
            (void*)tethering_cntx.conn_info_display->w_used_sim_str);
    }

    {
        U32 acct_id = srv_tethering_get_used_dtcnt();
        srv_dtcnt_prof_proxy_info_struct proxy_info;

        has_proxy = srv_dtcnt_get_proxy_info(
                        srv_tethering_get_used_dtcnt(),
                        &proxy_info,
                        SRV_DTCNT_ACCOUNT_PRIMARY) && proxy_info.use_proxy;

        if (has_proxy)
        {
            mmi_asc_to_wcs(tethering_cntx.conn_info_display->w_proxy_info_str, proxy_info.px_addr);
            cui_inline_set_value(
                tethering_cntx.conn_info_cui_inline_id,
                TETHERING_CONN_INFO_INLINE_ITEM_PROXY_DISPLAY,
                (void*)tethering_cntx.conn_info_display->w_proxy_info_str);
        }
    }

    {
        srv_tethering_get_used_dtcnt_apn(
            tethering_cntx.conn_info_display->w_apn_str,
            SRV_DTCNT_PROF_MAX_APN_LEN + 1);
        cui_inline_set_value(
            tethering_cntx.conn_info_cui_inline_id,
            TETHERING_CONN_INFO_INLINE_ITEM_APN_DISPLAY,
            (void*)tethering_cntx.conn_info_display->w_apn_str);
    }

    {
        CHAR sta_num_str[32];
        U8 sta_num = srv_tethering_get_sta_num(SRV_TETHERING_TYPE_WIFI_HS);
        sprintf(sta_num_str, "%d", sta_num);
        mmi_asc_to_wcs(tethering_cntx.conn_info_display->w_sta_num_str, sta_num_str);
        cui_inline_set_value(
            tethering_cntx.conn_info_cui_inline_id,
            TETHERING_CONN_INFO_INLINE_ITEM_WIFI_HS_STA_NUM_DISPLAY,
            (void*)tethering_cntx.conn_info_display->w_sta_num_str);
    }

    {
        cui_inline_set_value(
            tethering_cntx.conn_info_cui_inline_id,
            TETHERING_CONN_INFO_INLINE_ITEM_USB_STATUS_DISPLAY,
            (void*)GetString(STR_GLOBAL_ON));
    }

    if (!has_proxy)
    {    
        cui_inline_delete_item(tethering_cntx.conn_info_cui_inline_id, TETHERING_CONN_INFO_INLINE_ITEM_PROXY_CAP);
        cui_inline_delete_item(tethering_cntx.conn_info_cui_inline_id, TETHERING_CONN_INFO_INLINE_ITEM_PROXY_DISPLAY);
    }
    if (srv_tethering_get_status(SRV_TETHERING_TYPE_WIFI_HS) != SRV_TETHERING_STATUS_SRV_ON)
    {        
        cui_inline_delete_item(tethering_cntx.conn_info_cui_inline_id, TETHERING_CONN_INFO_INLINE_ITEM_WIFI_HS_STA_NUM_CAP);
        cui_inline_delete_item(tethering_cntx.conn_info_cui_inline_id, TETHERING_CONN_INFO_INLINE_ITEM_WIFI_HS_STA_NUM_DISPLAY);
    }
    if (srv_tethering_get_status(SRV_TETHERING_TYPE_USB) != SRV_TETHERING_STATUS_SRV_ON)
    {        
        cui_inline_delete_item(tethering_cntx.conn_info_cui_inline_id, TETHERING_CONN_INFO_INLINE_ITEM_USB_STATUS_CAP);
        cui_inline_delete_item(tethering_cntx.conn_info_cui_inline_id, TETHERING_CONN_INFO_INLINE_ITEM_USB_STATUS_DISPLAY);
    }

    cui_inline_set_all_items_softkey_text(
        tethering_cntx.conn_info_cui_inline_id,
        MMI_LEFT_SOFTKEY,
        0);
    cui_inline_run(tethering_cntx.conn_info_cui_inline_id);
}


void mmi_tethering_entry_proxy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    WCHAR *proxy = (WCHAR*)subMenuData;
    srv_dtcnt_prof_proxy_info_struct proxy_info;
    CHAR star_char_pw[SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN + 1];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (!mmi_frm_scrn_enter(
            GRP_ID_TETHERING_MAIN,
            SCR_ID_TETHERING_PROXY,
            NULL,
            mmi_tethering_entry_proxy,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }
    
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    srv_dtcnt_get_proxy_info(
        srv_tethering_get_used_dtcnt(),
        &proxy_info,
        SRV_DTCNT_ACCOUNT_PRIMARY);

    for (i = 0; i < strlen(proxy_info.px_authpw); i++)
    {
        star_char_pw[i] = '*';
    }
    star_char_pw[i] = 0;

    kal_wsprintf(
        proxy,
        "%w\n\n%w\n%s\n\n%w\n%d\n\n%w\n%s\n\n%w\n%s",
        GetString(STR_ID_SRV_TETHERING_PROXY_GUIDE),
        GetString(STR_GLOBAL_ADDRESS),
        proxy_info.px_addr,
        GetString(STR_ID_SRV_TETHERING_PROXY_PORT),
        proxy_info.px_port,
        GetString(STR_GLOBAL_USERNAME),
        proxy_info.px_authid,
        GetString(STR_GLOBAL_PASSWORD),
        star_char_pw);

    ShowCategory74Screen(
        STR_GLOBAL_PROXY,
        GetRootTitleIcon(MENU_ID_TETHERING),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*)proxy,
        mmi_wcslen(proxy) + 1,
        gui_buffer);

    ChangeCenterSoftkey(0, 0);
    SetLeftSoftkeyFunction(0, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(0, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


void mmi_tethering_entry_help(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *help_buf;
    WCHAR *common_help_str;
#ifdef __MMI_TETHERING_WIFI__
    WCHAR *hospot_title;
    WCHAR *hostpot_help_str;
#endif
#ifdef __USB_TETHERING__
    WCHAR *usb_title;
    WCHAR *usb_help_str;
#endif
    S32 len = 0, size;
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (!mmi_frm_scrn_enter(
        GRP_ID_TETHERING_MAIN,
        SCR_ID_TETHERING_HELP,
        NULL,
        mmi_tethering_entry_help,
        MMI_FRM_FULL_SCRN))
    {
        return;
    }
    gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_TETHERING_USB, SCR_ID_TETHERING_USB_CONFIRM);

    // prepare display string
    common_help_str = (WCHAR*)GetString(STR_ID_SRV_TETHERING_HELP_CONTENT);
    len += mmi_wcslen(common_help_str);
#ifdef __MMI_TETHERING_WIFI__
    hospot_title = (WCHAR*)GetString(STR_ID_SRV_TETHERING_WIFI_HS);
    len += mmi_wcslen(hospot_title);

    hostpot_help_str = (WCHAR*)GetString(STR_ID_SRV_TETHERING_HELP_WIFI_CONTENT);
    len += mmi_wcslen(hostpot_help_str);

#endif
#ifdef __USB_TETHERING__
    usb_title = (WCHAR*)GetString(STR_ID_SRV_TETHERING_USB);
    len += mmi_wcslen(usb_title);

    usb_help_str = (WCHAR*)GetString(STR_ID_SRV_TETHERING_HELP_USB_CONTENT);
    len += mmi_wcslen(usb_help_str);
#endif
    size = (len + 10) * sizeof(WCHAR);
    //help_buf = (WCHAR*)mmi_frm_temp_alloc(size);
    help_buf  = (WCHAR *)subMenuData;
    mmi_wcscpy(help_buf, common_help_str);
#ifdef __MMI_TETHERING_WIFI__
    mmi_wcscat(help_buf, (WCHAR*)L"\n\n");
    mmi_wcscat(help_buf, hospot_title);
    mmi_wcscat(help_buf, (WCHAR*)L"\n");
    mmi_wcscat(help_buf, hostpot_help_str);
#endif
#ifdef __USB_TETHERING__
    mmi_wcscat(help_buf, (WCHAR*)L"\n\n");
    mmi_wcscat(help_buf, usb_title);
    mmi_wcscat(help_buf, (WCHAR*)L"\n");
    mmi_wcscat(help_buf, usb_help_str);
#endif
    
    ShowCategory74Screen(
        STR_GLOBAL_HELP,
        GetRootTitleIcon(MENU_ID_TETHERING),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8 *)help_buf,
        size,
        gui_buffer);

    ChangeCenterSoftkey(0, 0);
    SetLeftSoftkeyFunction(0, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(0, KEY_EVENT_UP);       
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    //mmi_frm_temp_free(help_buf);
}


void mmi_tethering_display_waiting_screen(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_USER_DEFINE);
    arg.parent_id = parent_id;
    arg.callback = mmi_tethering_display_waiting_screen_cb;
    arg.f_enter_history = MMI_TRUE;
    arg.softkey[0].str = (WCHAR*)GetString(STR_ID_APP_TETHERING_MINIMIZE);
    arg.softkey[0].img = GetImage(IMG_GLOBAL_YES);
    arg.softkey[1].img = GetImage(IMG_GLOBAL_COMMON_CSK);
    arg.softkey[2].str = 0;
    arg.user_tag = (void*)parent_id;
    tethering_cntx.waiting_screen_id = mmi_confirm_display(
                                        (WCHAR*)GetString(STR_GLOBAL_PLEASE_WAIT),
                                        MMI_EVENT_PROGRESS,
                                        &arg);
}


mmi_ret mmi_tethering_display_waiting_screen_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert_result_evt = (mmi_alert_result_evt_struct*)evt;
    MMI_ID group_id = (MMI_ID)(alert_result_evt->user_tag);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (alert_result_evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (alert_result_evt->result)
        {
            case MMI_ALERT_CNFM_1:
            case MMI_ALERT_CNFM_2:
                mmi_frm_group_close(GRP_ID_TETHERING_MAIN);
                mmi_frm_group_close(group_id);
                break;

            default:
                break;
        }
    }
    return MMI_RET_OK;
}


void mmi_tethering_conn_info_notify_hdlr(srv_tethering_type_enum tethering_type, void *info_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (tethering_type)
    {
        case SRV_TETHERING_TYPE_WIFI_HS:
        {
            if (tethering_cntx.conn_info_cui_inline_id)
            {
                U8 sta_num = srv_tethering_get_sta_num(SRV_TETHERING_TYPE_WIFI_HS);
                CHAR sta_num_str[32];
                sprintf(sta_num_str, "%d", sta_num);
                mmi_asc_to_wcs(tethering_cntx.conn_info_display->w_sta_num_str, sta_num_str);
                cui_inline_set_value(
                    tethering_cntx.conn_info_cui_inline_id,
                    TETHERING_CONN_INFO_INLINE_ITEM_WIFI_HS_STA_NUM_DISPLAY,
                    (void*)tethering_cntx.conn_info_display->w_sta_num_str);
                cui_inline_redraw_screen(tethering_cntx.conn_info_cui_inline_id);
            }
        }

        default:
            break;
    }
}


void mmi_tethering_disconnect_notify_hdlr(srv_tethering_type_enum tethering_type, srv_tethering_disconn_cause_enum cause, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tethering_type == SRV_TETHERING_TYPE_WIFI_HS)
    {
    #ifdef __MMI_TETHERING_WIFI__
        MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, MMI_TETHERING_DISCONNECT_NOTIFY_HDLR, 1);
    #endif
    }
    else if (tethering_type == SRV_TETHERING_TYPE_USB)
    {
    #ifdef __USB_TETHERING__
        MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, MMI_TETHERING_DISCONNECT_NOTIFY_HDLR, 2);
        mmi_tethering_usb_group_close();
    #endif
    }

    mmi_frm_group_close(GRP_ID_TETHERING_MAIN);
}


void mmi_tethering_avail_status_change_cb_hdlr(MMI_BOOL enable_flag, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (enable_flag == MMI_FALSE)
    {
        mmi_frm_group_close(GRP_ID_TETHERING_MAIN);
    }
}


// error handling
void mmi_tethering_display_popup(srv_tethering_launch_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;
    MMI_STR_ID str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_property_init(&arg);
    
    arg.parent_id = GRP_ID_TETHERING_USB;
    arg.f_msg_icon = MMI_FALSE;

    switch (result)
    {
        case SRV_TETHERING_LAUNCH_RESULT_WIFI_TETHERING_ACTIVATED:
            str_id = STR_ID_SRV_TETHERING_WIFI_TETHERING_ACTIVATED_WARNNING;
            break;
            
        case SRV_TETHERING_LAUNCH_RESULT_USB_TETHERING_ACTIVATED:
            str_id = STR_ID_SRV_TETHERING_USB_TETHERING_ACTIVATED_WARNNING;
            break;

        case SRV_TETHERING_LAUNCH_RESULT_DIALUP_ACTIVATED:
            str_id = STR_ID_SRV_TETHERING_DIALUP_ACTIVATED_WARNNING;
            break;

        case SRV_TETHERING_LAUNCH_RESULT_UNAVAILABLE_SIM:
            str_id = STR_GLOBAL_UNAVAILABLE_SIM;
            break;

        case SRV_TETHERING_LAUNCH_RESULT_FLIGHT_MODE:
            str_id = STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE;
            break;

        default:
            str_id = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE;
            break;
    }
    mmi_popup_display(
        (WCHAR*)GetString(str_id),
        MMI_EVENT_FAILURE,
        &arg);
}


void mmi_tethering_reactivate_demand_hdlr(srv_tethering_type_enum tethering_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tethering_conn_info_struct conn_info;
    srv_dtcnt_sim_type_enum sim_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_dtcnt_get_sim_preference(&sim_type);
    conn_info.common_account_id = srv_tethering_get_dtcnt(sim_type);
    conn_info.used_sim = sim_type - 1;
    conn_info.conn_info_notify.funcptr = mmi_tethering_conn_info_notify_hdlr;
    conn_info.disconnect_notify.funcptr = mmi_tethering_disconnect_notify_hdlr;
    srv_tethering_set_conn_info(&conn_info);
    srv_tethering_switch_on(
        tethering_type,
        NULL,
        NULL);
}


U32 mmi_tethering_get_curr_sim_match_acct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_sim_type_enum sim_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_dtcnt_get_sim_preference(&sim_type);
    return srv_tethering_get_dtcnt(sim_type);
}


mmi_ret mmi_tethering_no_sim_available_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(GRP_ID_TETHERING_MAIN);
#ifdef __USB_TETHERING__
    mmi_tethering_usb_group_close();
#endif /* __USB_TETHERING__ */

    return MMI_RET_OK;
}


//USB_TETHERING
#ifdef __USB_TETHERING__
mmi_ret mmi_tethering_usb_scr_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_RET_OK;
}


// this api used for usb
void mmi_tethering_usb_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, MMI_TETHERING_USB_LAUNCH);
    if (mmi_frm_group_is_present(GRP_ID_TETHERING_USB))
    {
        mmi_frm_group_close(GRP_ID_TETHERING_USB);
    }
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_TETHERING_USB, mmi_tethering_usb_scr_group_proc, NULL);
    mmi_frm_group_enter(GRP_ID_TETHERING_USB, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    srv_tethering_usb_reg_cable_disconnect_cb_hdlr((FuncPtr)mmi_tethering_usb_group_close);
    srv_tethering_reg_reactivate_demand_cb_hdlr(SRV_TETHERING_TYPE_USB, (srv_tethering_reactivate_demand_ind_func_ptr_type)mmi_tethering_reactivate_demand_hdlr);
    mmi_tethering_usb_entry_confirm();
}


void mmi_tethering_usb_entry_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *help_buf;
    S32 len = 0, size;
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, MMI_TETHERING_USB_ENTRY_CONFIRM);
    if (!mmi_frm_scrn_enter(
        GRP_ID_TETHERING_USB,
        SCR_ID_TETHERING_USB_CONFIRM,
        NULL,
        mmi_tethering_usb_entry_confirm,
        MMI_FRM_FULL_SCRN))
    {
        return;
    }
    gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_TETHERING_USB, SCR_ID_TETHERING_USB_CONFIRM);
    
    // prepare display string
    help_buf = (WCHAR*)GetString(STR_ID_SRV_TETHERING_USB_REMIND_SHORT);

    size = mmi_wcslen(help_buf);

    ShowCategory74Screen(
        STR_ID_SRV_TETHERING_USB,
        GetRootTitleIcon(MENU_ID_TETHERING),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_BACK,
        (U8 *)help_buf,
        size,
        gui_buffer);

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetLeftSoftkeyFunction(mmi_tethering_usb_turn_on, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_tethering_usb_turn_on, KEY_EVENT_UP);       
    SetRightSoftkeyFunction(mmi_tethering_usb_group_close, KEY_EVENT_UP);    
}


// this api is used for reconnect to USB
MMI_BOOL mmi_tethering_usb_reconnect(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    srv_tethering_conn_info_struct conn_info;
    srv_tethering_launch_result_enum  result;
    srv_dtcnt_sim_type_enum sim_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // need to check before entry screen group
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
#endif
    MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, MMI_TETHERING_USB_RECONNECT, 4);
    if (mmi_frm_group_is_present(GRP_ID_TETHERING_USB))
    {
        mmi_frm_group_close(GRP_ID_TETHERING_USB);
    }

    srv_dtcnt_get_sim_preference(&sim_type);
    conn_info.common_account_id = srv_tethering_get_dtcnt(sim_type);
    conn_info.used_sim = sim_type - 1;
    conn_info.conn_info_notify.funcptr = mmi_tethering_conn_info_notify_hdlr;
    conn_info.disconnect_notify.funcptr = mmi_tethering_disconnect_notify_hdlr;
    srv_tethering_set_conn_info(&conn_info);

    result = srv_tethering_check_launch_capab(SRV_TETHERING_TYPE_USB);

    if (result == SRV_TETHERING_LAUNCH_RESULT_OK ||
        result == SRV_TETHERING_LAUNCH_RESULT_NETWORK_NOT_READY)
    {
        mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_TETHERING_USB, mmi_tethering_usb_scr_group_proc, NULL);
        mmi_frm_group_enter(GRP_ID_TETHERING_USB, MMI_FRM_NODE_SMART_CLOSE_FLAG);    
        srv_tethering_usb_reg_cable_disconnect_cb_hdlr((FuncPtr)mmi_tethering_usb_group_close);
        mmi_tethering_usb_reconnect_confirm();
    }
    else
    {
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_ID_SRV_TETHERING_USB_DISCONNECT));
    }

    return MMI_TRUE;
}


void mmi_tethering_usb_reconnect_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img_id;
    U8* gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            GRP_ID_TETHERING_USB, 
            SCR_ID_TETHERING_USB_RECONNECT, 
            NULL, 
            mmi_tethering_usb_reconnect_confirm, 
            MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_gui_buf(
                        GRP_ID_TETHERING_USB, 
                        SCR_ID_TETHERING_USB_RECONNECT);
        if (!gui_buffer)
        {
            // here call only once
            MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, MMI_TETHERING_USB_RECONNECT_CONFIRM);
            srv_tethering_switch_on(
                SRV_TETHERING_TYPE_USB,
                mmi_tethering_usb_switch_hdlr,
                NULL);
        }
        img_id = mmi_get_event_based_image(MMI_EVENT_PROGRESS);
        ShowCategory66Screen(
            STR_ID_SRV_TETHERING_USB,
            GetRootTitleIcon(MENU_ID_TETHERING),
            0,
            0,
            STR_GLOBAL_CANCEL,
            0,
            (U8*)GetString(STR_ID_SRV_TETHERING_USB_RECONNECT),
            img_id,
            gui_buffer);
        MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, MMI_TETHERING_USB_RECONNECT_CONFIRM);
        SetRightSoftkeyFunction(mmi_tethering_usb_cancel_reconnect, KEY_EVENT_UP);
        mmi_frm_scrn_set_leave_proc(GRP_ID_TETHERING_USB, SCR_ID_TETHERING_USB_RECONNECT, mmi_tethering_usb_reconnect_screen_leave_proc);
    }
}


void mmi_tethering_usb_cancel_reconnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, MMI_TETHERING_USB_CANCEL_RECONNECT);
    srv_tethering_stop(SRV_TETHERING_TYPE_USB, NULL, NULL);
    mmi_tethering_usb_group_close();
}


mmi_ret mmi_tethering_usb_reconnect_screen_leave_proc(mmi_event_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (para->evt_id)
    {        
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:        
            MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, MMI_TETHERING_USB_RECONNECT_SCREEN_LEAVE_PROC);
            srv_tethering_stop(SRV_TETHERING_TYPE_USB, NULL, NULL);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


void mmi_tethering_usb_turn_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tethering_conn_info_struct conn_info;
    cbm_sim_id_enum cbm_sim_id = CBM_SIM_ID_SIM1;
    mmi_sim_enum mmi_sim_id;
    srv_tethering_launch_result_enum result = SRV_TETHERING_LAUNCH_RESULT_OK;
    U32 acct_id = mmi_tethering_get_curr_sim_match_acct();
    srv_dtcnt_sim_type_enum sim_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, MMI_TETHERING_USB_TURN_ON);
    // check status from service, if it isn't OK, return;
    result = srv_tethering_check_launch_capab_common(SRV_TETHERING_TYPE_USB);
    if (SRV_TETHERING_LAUNCH_RESULT_OK != result)
    {
        mmi_tethering_display_popup(result);
        return;
    }

    if (cbm_get_original_account(acct_id) != CBM_DEFAULT_ACCT_ID)
    {
        cbm_sim_id = cbm_get_sim_id(acct_id);
        mmi_sim_id = mmi_frm_index_to_sim((U32)cbm_sim_id);
        
        if (srv_tethering_check_launch_capab_nw(mmi_sim_id) != SRV_TETHERING_LAUNCH_RESULT_OK)
        {
            mmi_popup_display_simple(
                (WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
                MMI_EVENT_FAILURE,
                GRP_ID_TETHERING_USB,
                NULL);
            return;
        }
    }

    if (srv_tethering_check_launch_capab_acct(SRV_TETHERING_TYPE_USB, acct_id) != SRV_TETHERING_LAUNCH_RESULT_OK)
    {
        mmi_popup_display_simple(
            (WCHAR*)GetString(STR_ID_SRV_TETHERING_INVALID_DATA_ACCOUNT),
            MMI_EVENT_FAILURE,
            GRP_ID_TETHERING_USB,
            NULL);
        return;
    }

    // reuse waiting screen
    mmi_tethering_display_waiting_screen(GRP_ID_TETHERING_USB);

    srv_dtcnt_get_sim_preference(&sim_type);
    conn_info.common_account_id = acct_id;
    conn_info.used_sim = sim_type - 1;
    conn_info.conn_info_notify.funcptr = mmi_tethering_conn_info_notify_hdlr;
    conn_info.disconnect_notify.funcptr = mmi_tethering_disconnect_notify_hdlr;
    srv_tethering_set_conn_info(&conn_info);
    if (srv_tethering_get_status(SRV_TETHERING_TYPE_USB) == SRV_TETHERING_STATUS_SRV_OFF)
    {
        srv_tethering_switch_on(
            SRV_TETHERING_TYPE_USB,
            mmi_tethering_usb_switch_hdlr,
            NULL);
    }
}


void mmi_tethering_usb_switch_hdlr(srv_tethering_type_enum tethering_type, MMI_BOOL result, srv_tethering_status_enum des_status, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL has_proxy = MMI_FALSE;
    srv_dtcnt_prof_proxy_info_struct proxy_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, MMI_TETHERING_USB_SWITCH_HDLR, result);
    if (mmi_frm_group_is_present(GRP_ID_TETHERING_USB) == MMI_TRUE)
    {
        mmi_tethering_usb_group_close();
    }
    // here need to popup proxy address and port
    if (SRV_TETHERING_STATUS_SRV_ON == des_status &&
        result == MMI_TRUE)
    {
        has_proxy = srv_dtcnt_get_proxy_info(
                        srv_tethering_get_used_dtcnt(),
                        &proxy_info,
                        SRV_DTCNT_ACCOUNT_PRIMARY) && proxy_info.use_proxy;

        if (has_proxy)
        {
            mmi_frm_nmgr_popup(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_SUCCESS,
                (WCHAR*)GetString(STR_ID_SRV_TETHERING_PROXY_PROMPT));
        }
        mmi_frm_group_close(GRP_ID_TETHERING_MAIN);
    }

    if (result == MMI_FALSE)
    {
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_GLOBAL_FAILED));
    }
}


void mmi_tethering_usb_group_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, MMI_TETHERING_USB_GROUP_CLOSE);
    mmi_frm_group_close(GRP_ID_TETHERING_USB);
    mmi_frm_group_close(GRP_ID_TETHERING_MAIN);
}

#endif

#endif /* __MMI_TETHERING__ */
