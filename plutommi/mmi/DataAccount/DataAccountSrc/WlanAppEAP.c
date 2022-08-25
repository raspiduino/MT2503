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
 * DataAccountEAP.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   EAP modules implementations for Data Account WLAN authentication.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __TCPIP__
#include "MMI_features.h"
#ifdef __CERTMAN_SUPPORT__
#include "CertManMMIGprots.h"
#endif
#ifdef __MMI_WLAN_FEATURES__
#include "DtcntSrvIprot.h"
#include "MMIDataType.h"
#include "DataAccountStruct.h"
#include "mmi_rp_app_dataaccount_def.h"
#include "supc_abm_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "DataAccountProt.h"
#include "DataAccountDef.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "gui_data_types.h"
#include "AlertScreen.h"
#include "stack_config.h"
#include "wgui_categories_util.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_categories_list.h"
#include "DtcntSrvIntEnum.h"
#include "DtcntSrvIntDef.h"
#include "DtcntSrvIntStruct.h"
#include "DtcntSrvWlan.h"
#include "mmi_rp_app_uiframework_def.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "mmi_rp_file_type_def.h"
#include "CommonScreens.h"
#include "gui_fixed_menuitems.h"
#include "DataAccountEnum.h"
#include "Unicodexdcl.h"
#include "ImeGprot.h"
#include "wgui_categories_inputs.h"
#include "string.h"
/*------------------------------ suggest Add ------------------------------*/
#include "stack_msgs.h"
#include "mmi_conn_app_trc.h"
#include "wgui_touch_screen.h"
#include "wgui_categories.h"

//remove for option slim
#if 0
#ifndef __OPTR_NONE__
/* under construction !*/
#endif
#endif
#include "DataAccountCore.h"

extern U32 modified3;
extern U8 wgui_inline_list_menu_changed;
extern mmi_id wlan_parent_group_id;
extern mmi_wlan_display_struct g_wlan_display_context;

// EAP TTLS SETTINGS INLINE CUI
static const cui_inline_item_caption_struct eap_ttls_ca_cert_caption = {STR_ID_DTCNT_WLAN_CA_CERT};
static const cui_inline_item_display_only_struct eap_ttls_ca_cert_disp_only = {0};
static const cui_inline_item_display_only_struct eap_ttls_tunneled_auth_prot_disp_only = {0};

static const cui_inline_set_item_struct eap_ttls_inline_items[WLAN_EAP_TTLS_SETTINGS_INLINE_TOTAL] = 
{
    {CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TTLS_SETTINGS_CA_CERT_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, (const void*)&eap_ttls_ca_cert_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TTLS_SETTINGS_CA_CERT, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, (const void*)&eap_ttls_ca_cert_disp_only},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TTLS_SETTINGS_TUNNELED_AUTH_PROTOCOL, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, IMG_GLOBAL_L2, (const void*)&eap_ttls_tunneled_auth_prot_disp_only}
};
static const cui_inline_struct eap_ttls_inline_struct = 
{
    WLAN_EAP_TTLS_SETTINGS_INLINE_TOTAL,
    STR_ID_DTCNT_WLAN_EAP_TTLS_SETTINGS,
    0,
    CUI_INLINE_SCREEN_LOOP,
    NULL,
    eap_ttls_inline_items
};
// EAP PEAP SETTINGS INLINE CUI
static const cui_inline_item_caption_struct eap_peap_ca_cert_caption = {STR_ID_DTCNT_WLAN_CA_CERT};
static const cui_inline_item_display_only_struct eap_peap_ca_cert_disp_only = {0};
static const cui_inline_item_display_only_struct eap_peap_tunneled_auth_prot_disp_only = {0};

static const cui_inline_set_item_struct eap_peap_inline_items[WLAN_EAP_PEAP_SETTINGS_INLINE_TOTAL] = 
{
    {CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_PEAP_SETTINGS_CA_CERT_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, (const void*)&eap_peap_ca_cert_caption},    
    {CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_PEAP_SETTINGS_CA_CERT, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, (const void*)&eap_peap_ca_cert_disp_only},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_PEAP_SETTINGS_TUNNELED_AUTH_PROTOCOL, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, IMG_GLOBAL_L2, (const void*)&eap_peap_tunneled_auth_prot_disp_only}
};
static const cui_inline_struct eap_peap_inline_struct =
{
    WLAN_EAP_PEAP_SETTINGS_INLINE_TOTAL,
    STR_ID_DTCNT_WLAN_EAP_PEAP_SETTINGS,
    0,
    CUI_INLINE_SCREEN_LOOP,
    NULL,
    eap_peap_inline_items
};
// EAP TLS SETTINGS INLINE CUI
static const cui_inline_item_caption_struct eap_tls_ca_cert_caption = {STR_ID_DTCNT_WLAN_CA_CERT};
static const cui_inline_item_display_only_struct eap_tls_ca_cert_disp_only = {0};
static const cui_inline_item_caption_struct eap_tls_user_cert_caption = {STR_ID_DTCNT_WLAN_USER_CERT};
static const cui_inline_item_display_only_struct eap_tls_user_cert_disp_only = {0};
#ifndef __CERTMAN_SUPPORT__
static const cui_inline_item_caption_struct eap_tls_private_key_caption = {STR_ID_DTCNT_WLAN_PRIV_KEY};
static const cui_inline_item_display_only_struct eap_tls_private_key_disp_only = {0};
#endif
static const cui_inline_item_caption_struct eap_tls_password_caption = {STR_ID_DTCNT_WLAN_PRIV_KEY_PASSWD};
static const cui_inline_item_fullscreen_edit_struct eap_tls_password_edit = 
{
    0,
    0,
    STR_ID_DTCNT_WLAN_PRIV_KEY_PASSWD,
    0,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD,
    MAX_PASSWORD_LEN,
    NULL
};
static const cui_inline_item_caption_struct eap_tls_user_name_caption = {STR_GLOBAL_USERNAME};
static const cui_inline_item_fullscreen_edit_struct eap_tls_user_name_edit = 
{
    0,
    0,
    STR_GLOBAL_USERNAME,
    0,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    IMM_INPUT_TYPE_ASCII_CHAR,
    MAX_USERNAME_LEN,
    NULL
};

static const cui_inline_set_item_struct eap_tls_inline_items[WLAN_EAP_TLS_SETTINGS_INLINE_TOTAL] = 
{
    {CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_CA_CERT_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, (const void*)&eap_tls_ca_cert_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_CA_CERT, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, (const void*)&eap_tls_ca_cert_disp_only},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_USER_CERT_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, (const void*)&eap_tls_user_cert_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_USER_CERT, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, (const void*)&eap_tls_user_cert_disp_only},
#ifndef __CERTMAN_SUPPORT__    
    {CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_PRIV_KEY_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L3, (const void*)&eap_tls_private_key_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_PRIV_KEY, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, (const void*)&eap_tls_private_key_disp_only},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_PRIV_KEY_PASSWD_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L4, (const void*)&eap_tls_password_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_PRIV_KEY_PASSWD, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (const void*)&eap_tls_password_edit},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_USERNAME_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L5, (const void*)&eap_tls_user_name_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_USERNAME, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (const void*)&eap_tls_user_name_edit}
#else
    {CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_PRIV_KEY_PASSWD_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L3, (const void*)&eap_tls_password_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_PRIV_KEY_PASSWD, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (const void*)&eap_tls_password_edit},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_USERNAME_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L4, (const void*)&eap_tls_user_name_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_USERNAME, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (const void*)&eap_tls_user_name_edit}
#endif    
};

static const cui_inline_struct eap_tls_inline_struct =
{
    WLAN_EAP_TLS_SETTINGS_INLINE_TOTAL,
    STR_ID_DTCNT_WLAN_EAP_TLS_SETTINGS,
    0,
    CUI_INLINE_SCREEN_LOOP,
    NULL,
    eap_tls_inline_items
};

// EAP USER INFO INLINE CUI
static const cui_inline_item_caption_struct eap_user_info_user_name_caption = {STR_GLOBAL_USERNAME};
static const cui_inline_item_fullscreen_edit_struct eap_user_info_user_name_edit =
{
    0,
    0,
    STR_GLOBAL_USERNAME,
    0,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    IMM_INPUT_TYPE_ASCII_CHAR,
    MAX_USERNAME_LEN,
    NULL
};
static const cui_inline_item_caption_struct eap_user_info_password_caption = {STR_GLOBAL_PASSWORD};
static const cui_inline_item_fullscreen_edit_struct eap_user_info_password_edit =
{
    0,
    0,
    STR_GLOBAL_PASSWORD,
    0,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD,
    MAX_PASSWORD_LEN,
    NULL
};

static const cui_inline_set_item_struct eap_user_info_inline_items[WLAN_USER_INFO_INLINE_TOTAL] =
{
    {CUI_INLINE_ITEM_ID_BASE + WLAN_USER_INFO_USERNAME_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, (const void*)&eap_user_info_user_name_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_USER_INFO_USERNAME, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (const void*)&eap_user_info_user_name_edit},    
    {CUI_INLINE_ITEM_ID_BASE + WLAN_USER_INFO_PASSWORD_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, (const void*)&eap_user_info_password_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_USER_INFO_PASSWORD, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (const void*)&eap_user_info_password_edit}
};
static const cui_inline_struct eap_user_info_inline_struct =
{
    WLAN_USER_INFO_INLINE_TOTAL,
    STR_ID_DTCNT_WLAN_USER_INFO,
    0,
    CUI_INLINE_SCREEN_LOOP,
    NULL,
    eap_user_info_inline_items
};
// EAP DEFAULT SETTINGS INLINE CUI
static const cui_inline_item_caption_struct eap_default_user_name_caption = {STR_GLOBAL_USERNAME};
static const cui_inline_item_fullscreen_edit_struct eap_default_user_name_full_editor = 
{
    0,
    0,
    STR_GLOBAL_USERNAME,
    0,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    IMM_INPUT_TYPE_ASCII_CHAR,
    MAX_USERNAME_LEN,
    NULL
};
static const cui_inline_item_caption_struct eap_default_password_caption = {STR_GLOBAL_PASSWORD};
static const cui_inline_item_fullscreen_edit_struct eap_default_password_full_editor =
{
    0,
    0,
    STR_GLOBAL_PASSWORD,
    0,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD,
    MAX_PASSWORD_LEN,
    NULL
};
static const cui_inline_set_item_struct eap_default_inline_items[WLAN_USER_INFO_INLINE_TOTAL] =
{
    {CUI_INLINE_ITEM_ID_BASE + WLAN_USER_INFO_USERNAME_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, (const void*)&eap_default_user_name_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_USER_INFO_USERNAME, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (const void*)&eap_default_user_name_full_editor},    
    {CUI_INLINE_ITEM_ID_BASE + WLAN_USER_INFO_PASSWORD_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, (const void*)&eap_default_password_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_USER_INFO_PASSWORD, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (const void*)&eap_default_password_full_editor}
};
static const cui_inline_struct eap_default_inline_struct =
{
    WLAN_USER_INFO_INLINE_TOTAL,
    STR_ID_DTCNT_WLAN_USER_INFO,
    0,
    CUI_INLINE_SCREEN_LOOP,
    NULL,
    eap_default_inline_items
};

#ifndef __CERTMAN_SUPPORT__
static void mmi_wlan_entry_user_cert_list_callback(void *filePath, int is_short);
static void mmi_wlan_entry_ca_cert_list_callback(void *filePath, int is_short);
static void mmi_wlan_entry_private_key_list_callback(void *, int);
#endif /* __CERTMAN_SUPPORT__ */

static void mmi_wlan_entry_user_info(void);
static void mmi_wlan_eap_type_highlight_hdlr(S32 nIndex);

#ifdef WLAN_EAP_TTLS_SUPPORT
static void mmi_wlan_eap_ttls_settings_auth_type_highlight_hdlr(S32 nIndex);
static void mmi_wlan_entry_eap_ttls_settings(void);

#endif /* WLAN_EAP_TTLS_SUPPORT */ 

#ifdef WLAN_EAP_PEAP_SUPPORT
void mmi_wlan_eap_peap_settings_eap_type_center(void);
static void mmi_wlan_eap_peap_settings_eap_type_highlight_hdlr(S32 nIndex);
static void mmi_wlan_entry_eap_peap_settings(void);

#endif /* WLAN_EAP_PEAP_SUPPORT */ 

#ifdef WLAN_EAP_TLS_SUPPORT
static void mmi_wlan_entry_eap_tls_settings(void);
#endif /* WLAN_EAP_TLS_SUPPORT */ 

auth_plugin_struct g_wlan_auth_module[] = 
{
#ifdef WLAN_EAP_TLS_SUPPORT
    {WLAN_EAP_TLS, STR_ID_DTCNT_WLAN_EAP_TLS, mmi_wlan_entry_eap_tls_settings},
#endif 
#ifdef WLAN_EAP_MD5_SUPPORT
    {WLAN_EAP_MD5, STR_ID_DTCNT_WLAN_EAP_MD5, mmi_wlan_entry_user_info},
#endif 
#ifdef WLAN_EAP_PEAP_SUPPORT
    {WLAN_EAP_PEAP, STR_ID_DTCNT_WLAN_EAP_PEAP, mmi_wlan_entry_eap_peap_settings},
#endif 
#ifdef WLAN_EAP_TTLS_SUPPORT
    {WLAN_EAP_TTLS, STR_ID_DTCNT_WLAN_EAP_TTLS, mmi_wlan_entry_eap_ttls_settings},
#endif 
#ifdef WLAN_EAP_SIM_SUPPORT
    {WLAN_EAP_SIM, STR_ID_DTCNT_WLAN_EAP_SIM, mmi_wlan_entry_user_info},
#endif 
#ifdef WLAN_EAP_FAST_SUPPORT
    {0, STR_ID_DTCNT_WLAN_EAP_FAST, NULL},
#endif 
#ifdef WLAN_EAP_MSCHAP2_SUPPORT
    {WLAN_EAP_MSCHAV2, STR_ID_DTCNT_WLAN_EAP_MSCHAP2, mmi_wlan_entry_user_info},
#endif 
#ifdef WLAN_EAP_GTC_SUPPORT
    {WLAN_EAP_GTC, STR_ID_DTCNT_WLAN_EAP_GTC, mmi_wlan_entry_user_info},
#endif 
#ifdef WLAN_PAP_SUPPORT
    {WLAN_PAP, STR_ID_DTCNT_WLAN_PAP, mmi_wlan_entry_user_info},
#endif 
#ifdef WLAN_CHAP_SUPPORT
    {WLAN_CHAP, STR_ID_DTCNT_WLAN_CHAP, mmi_wlan_entry_user_info},
#endif 
#ifdef WLAN_MSCHAP_SUPPORT
    {WLAN_MSCHAP, STR_ID_DTCNT_WLAN_MSCHAP, mmi_wlan_entry_user_info},
#endif 
#ifdef WLAN_MSCHAP2_SUPPORT
    {WLAN_MSCHAPV2, STR_ID_DTCNT_WLAN_MSCHAP2, mmi_wlan_entry_user_info},
#endif 
    {WLAN_EAP_AKA, STR_ID_DTCNT_WLAN_EAP_AKA, NULL},
    {0, 0, NULL},
};

#ifdef __CERTMAN_SUPPORT__
void mmi_wlan_select_cert_rsp(void *rsp);
void mmi_wlan_select_user_cert_rsp(void *rsp);


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_select_user_cert_rsp
 * DESCRIPTION
 *  Callback function when finish selecting an file for attachment
 * PARAMETERS
 *  filePath        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_select_user_cert_rsp(void *rsp)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_select_cert_rsp_struct *cert_rsp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(MSG_ID_MMI_CERTMAN_SELECT_CERT_RSP);
    cert_rsp = (mmi_certman_select_cert_rsp_struct *)rsp;
    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_SELECT_USER_CERT_RSP, cert_rsp->result);
	
    if(cert_rsp->result)
    {
        g_wlan_display_context.client_ca_id = cert_rsp->cert_ids[0];
        mmi_certman_get_cert_label(g_wlan_display_context.client_ca_id, (U8*)g_wlan_display_context.client_user_name, MAX_USERNAME_LEN *ENCODING_LENGTH);
        mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_DONE)), MMI_EVENT_SUCCESS, wlan_parent_group_id, NULL);

        g_wlan_display_context.modified2 = TRUE;

        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_SELECT_USER_CERT_RSP_ID, g_wlan_display_context.client_ca_id);
    }
    else
    {
        g_wlan_display_context.modified2 = FALSE;
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_select_cert_rsp
 * DESCRIPTION
 *  Callback function when finish selecting an file for attachment
 * PARAMETERS
 *  filePath        [IN]       
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_select_cert_rsp(void *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_select_cert_rsp_struct *cert_rsp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ClearProtocolEventHandler(MSG_ID_MMI_CERTMAN_SELECT_CERT_RSP);

    cert_rsp = (mmi_certman_select_cert_rsp_struct *)rsp;
    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_SELECT_USER_CERT_RSP, cert_rsp->result);
	
    if(cert_rsp->result)
    {
        g_wlan_display_context.root_ca_id = cert_rsp->cert_ids[0];
        mmi_certman_get_cert_label(g_wlan_display_context.root_ca_id, (U8*)g_wlan_display_context.root_ca_name, MAX_USERNAME_LEN *ENCODING_LENGTH);
        mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_DONE)), MMI_EVENT_SUCCESS, wlan_parent_group_id, NULL);

        g_wlan_display_context.modified2 = TRUE;

        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_SELECT_USER_CERT_RSP_ID, g_wlan_display_context.root_ca_id);
    }
    else
    {
        g_wlan_display_context.modified2 = FALSE;
    }
}

#endif /*__CERTMAN_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_get_auth_type_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  auth_type       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static CHAR* mmi_wlan_get_auth_type_name(U8 auth_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetString(g_wlan_auth_module[auth_type].name_string_id);
}


#ifndef __CERTMAN_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_private_key_list
 * DESCRIPTION
 *  WLAN TCP/IP settings editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_private_key_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef  WIFI_AUTH_PSK_ONLY
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.modified2 = FALSE;

    g_wlan_display_context.top_screen = mmi_frm_scrn_get_active_id();
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_ALL(&filter);
    mmi_fmgr_select_path_and_enter(
        APP_DATAACCOUNT,
        FMGR_SELECT_FILE,
        filter,
        (CHAR*) L"root",
        mmi_wlan_entry_private_key_list_callback);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_private_key_list_callback
 * DESCRIPTION
 *  Callback function when finish selecting an file for attachment
 * PARAMETERS
 *  filePath        [IN]        Path and name of selected file
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_private_key_list_callback(void *filePath, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 file_handle = 0;
    U32 file_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filePath != NULL)
    {
        file_handle = FS_Open(filePath,  FS_READ_ONLY);
        
        if(file_handle <= 0)
        {

            mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_ID_WLAN_ERROR_FILE_OPEN_FAIL)), MMI_EVENT_FAILURE, wlan_parent_group_id, NULL);

            return ;
        }
        
        FS_GetFileSize( file_handle, &file_size );
        
        FS_Close(file_handle);
        
        if(file_size >= MMI_DTCNT_WIFI_FILE_LIMIT)
        {

            mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_ID_WLAN_ERROR_FILE_TOO_BIG)), MMI_EVENT_FAILURE, wlan_parent_group_id, NULL);

            return;
        }
        /* copy source file path+name */
        mmi_ucs2cpy((CHAR*)g_wlan_display_context.private_key_path, (const CHAR*)filePath);
        g_wlan_display_context.modified2 = TRUE;
    }

    mmi_frm_scrn_multiple_close(g_wlan_display_context.inline_setting_cui_id, mmi_frm_scrn_get_active_id(), 1, 0, g_wlan_display_context.top_screen, 1);

}
#endif /* __CERTMAN_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_user_cert_list
 * DESCRIPTION
 *  WLAN TCP/IP settings editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_user_cert_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __CERTMAN_SUPPORT__
    FMGR_FILTER filter;
#endif /* __CERTMAN_SUPPORT__ */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.modified2 = FALSE;
#ifdef __CERTMAN_SUPPORT__
    SetProtocolEventHandler(mmi_wlan_select_user_cert_rsp, MSG_ID_MMI_CERTMAN_SELECT_CERT_RSP);
//    mmi_certman_select_certificates_ind(MOD_MMI, MMI_CERTMAN_OPEN, FALSE, 0, MMI_CERTMAN_CERT_GROUP_PERSONAL);
    /* For WAPI new cert API */

    mmi_certman_select_certificates_ind(
        MOD_MMI, 
        (kal_bool)MMI_CERTMAN_OPEN, 
        KAL_FALSE, 
        0, 
        MMI_CERTMAN_CERT_GROUP_PERSONAL, 	
        MMI_CERTMAN_CERT_TYPE_RSA_SIGN |
        MMI_CERTMAN_CERT_TYPE_DSA_SIGN |
        MMI_CERTMAN_CERT_TYPE_DH_ANSI_SIGN |
        MMI_CERTMAN_CERT_TYPE_DH_PKCS3_SIGN);


#else
#ifndef  WIFI_AUTH_PSK_ONLY
    g_wlan_display_context.top_screen = mmi_frm_scrn_get_active_id();
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_ALL(&filter);
    mmi_fmgr_select_path_and_enter(
        APP_DATAACCOUNT,
        FMGR_SELECT_FILE,
        filter,
        (CHAR*)L"root",
        mmi_wlan_entry_user_cert_list_callback);
#endif
#endif /* __CERTMAN_SUPPORT__ */
}

#ifndef __CERTMAN_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_user_cert_list_callback
 * DESCRIPTION
 *  Callback function when finish selecting an file for attachment
 * PARAMETERS
 *  filePath        [IN]        Path and name of selected file
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_user_cert_list_callback(void *filePath, int is_short)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 file_handle = 0;
    U32 file_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filePath != NULL)
    {
        file_handle = FS_Open(filePath,  FS_READ_ONLY);
        
        if(file_handle <= 0)
        {

            mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_ID_WLAN_ERROR_FILE_OPEN_FAIL)), MMI_EVENT_FAILURE, wlan_parent_group_id, NULL);

            return ;
        }
        
        FS_GetFileSize( file_handle, &file_size );
        
        FS_Close(file_handle);
        
        if(file_size >= MMI_DTCNT_WIFI_FILE_LIMIT)
        {
            mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_ID_WLAN_ERROR_FILE_TOO_BIG)), MMI_EVENT_FAILURE, wlan_parent_group_id, NULL);

            return;
        }
        /* copy source file path+name */
        mmi_ucs2cpy((CHAR*)g_wlan_display_context.client_ca_path, (const CHAR*)filePath);
        g_wlan_display_context.modified2 = TRUE;
    }

    mmi_frm_scrn_multiple_close(g_wlan_display_context.inline_setting_cui_id, mmi_frm_scrn_get_active_id(), 1, 0, g_wlan_display_context.top_screen, 1);

}
#endif /* __CERTMAN_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_ca_cert_list
 * DESCRIPTION
 *  WLAN TCP/IP settings editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_ca_cert_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __CERTMAN_SUPPORT__
    FMGR_FILTER filter;
#endif /* __CERTMAN_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.modified2 = FALSE;
#ifdef __CERTMAN_SUPPORT__

    SetProtocolEventHandler(mmi_wlan_select_cert_rsp, MSG_ID_MMI_CERTMAN_SELECT_CERT_RSP);
//    mmi_certman_select_certificates_ind(MOD_MMI, MMI_CERTMAN_OPEN, FALSE, 0, MMI_CERTMAN_CERT_GROUP_ROOT_CA);
    /* For WAPI new cert API */
    mmi_certman_select_certificates_ind(
        MOD_MMI, 
        (kal_bool)MMI_CERTMAN_OPEN, 
        KAL_FALSE, 
        0, 
        MMI_CERTMAN_CERT_GROUP_ROOT_CA,     
        MMI_CERTMAN_CERT_TYPE_RSA_SIGN |
        MMI_CERTMAN_CERT_TYPE_DSA_SIGN |
        MMI_CERTMAN_CERT_TYPE_DH_ANSI_SIGN |
        MMI_CERTMAN_CERT_TYPE_DH_PKCS3_SIGN);

#else
#ifndef  WIFI_AUTH_PSK_ONLY
    g_wlan_display_context.top_screen = mmi_frm_scrn_get_active_id();
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_ALL(&filter);
    mmi_fmgr_select_path_and_enter(
        APP_DATAACCOUNT,
        FMGR_SELECT_FILE,
        filter,
        (CHAR*)L"root",
        mmi_wlan_entry_ca_cert_list_callback);
#endif    
#endif /* __CERTMAN_SUPPORT__ */
}

#ifndef __CERTMAN_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_ca_cert_list_callback
 * DESCRIPTION
 *  Callback function when finish selecting an file for attachment
 * PARAMETERS
 *  filePath        [IN]        Path and name of selected file
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_ca_cert_list_callback(void *filePath, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     U32 file_handle = 0;
     U32 file_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filePath != NULL)
    {
        file_handle = FS_Open(filePath,  FS_READ_ONLY);
        
        if(file_handle <= 0)
        {
            mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_ID_WLAN_ERROR_FILE_OPEN_FAIL)), MMI_EVENT_FAILURE, wlan_parent_group_id, NULL);

            return ;
        }
        
        FS_GetFileSize( file_handle, &file_size );
 
        FS_Close(file_handle);

        if(file_size >= MMI_DTCNT_WIFI_FILE_LIMIT)
        {
            mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_ID_WLAN_ERROR_FILE_TOO_BIG)), MMI_EVENT_FAILURE, wlan_parent_group_id, NULL);

            return;
        }
        /* copy source file path+name */
        mmi_ucs2cpy((CHAR*)g_wlan_display_context.root_ca_path, (const CHAR*)filePath);
        g_wlan_display_context.modified2 = TRUE;
    }
    mmi_frm_scrn_multiple_close(g_wlan_display_context.inline_setting_cui_id, mmi_frm_scrn_get_active_id(), 1, 0, g_wlan_display_context.top_screen, 1);

}
#endif /* __CERTMAN_SUPPORT__ */


#ifdef WLAN_EAP_TTLS_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_ttls_types_opt_activate
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_ttls_types_opt_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_wlan_eap_ttls_settings_auth_type_ok, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_eap_ttls_settings_auth_type_ok, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_ttls_types_opt_edit
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_ttls_types_opt_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr auth_settings_hdlr;
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = srv_dtcnt_wlan_eap_ttls_types(g_wlan_display_context.sel_eap_ttls_auth_type);
    auth_settings_hdlr = g_wlan_auth_module[index].entry_func;

    ASSERT(auth_settings_hdlr != NULL);

    SetLeftSoftkeyFunction(auth_settings_hdlr, KEY_EVENT_UP);
    SetKeyHandler(auth_settings_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_ttls_settings_auth_type_ok
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_ttls_settings_auth_type_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx;
    U32 val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx = srv_dtcnt_wlan_eap_ttls_types(g_wlan_display_context.sel_eap_ttls_auth_type);
    val = g_wlan_auth_module[idx].val;
    
    if (g_wlan_display_context.eap_ttls_auth_type & val)
    {
        g_wlan_display_context.eap_ttls_auth_type &= ~val;
    }
    else
    {
        g_wlan_display_context.eap_ttls_auth_type |= val;
    }

    g_wlan_display_context.modified2 = TRUE;
    mmi_frm_scrn_close_active_id();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_ttls_settings_auth_type_center
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listed item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_ttls_settings_auth_type_center(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx;
    U32 val;
    U16 iconStates;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx = srv_dtcnt_wlan_eap_ttls_types(g_wlan_display_context.sel_eap_ttls_auth_type);
    val = g_wlan_auth_module[idx].val;
    
    if (g_wlan_display_context.eap_ttls_auth_type & val)
    {
        g_wlan_display_context.eap_ttls_auth_type &= ~val;
        iconStates = CHECKBOX_OFF_IMAGE_ID;
    }
    else
    {
        g_wlan_display_context.eap_ttls_auth_type |= val;
        iconStates = CHECKBOX_ON_IMAGE_ID;
    }
    
    g_wlan_display_context.modified2 = TRUE;
    
    Category73ChangeItemIcon(g_wlan_display_context.sel_eap_ttls_auth_type, 1, (PU8)get_image(iconStates));
    Category73RedrawScreen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_ttls_settings_auth_type_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_ttls_settings_auth_type_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.sel_eap_ttls_auth_type = nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_eap_ttls_settings_auth_type_opt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_eap_ttls_settings_auth_type_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx;
    mmi_id wlan_menu_cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    idx = srv_dtcnt_wlan_eap_ttls_types(g_wlan_display_context.sel_eap_ttls_auth_type);
    if (g_wlan_auth_module[idx].entry_func == NULL)
    {
        wlan_menu_cui_id = cui_menu_create(
            wlan_parent_group_id, 
            CUI_MENU_SRC_TYPE_APPCREATE, 
            CUI_MENU_TYPE_OPTION, 
            MENU_ID_WLAN_EAP_TTLS_TYPES_OPT2, 
            MMI_TRUE, 
            NULL);

    }
    else
    {
        wlan_menu_cui_id = cui_menu_create(
            wlan_parent_group_id, 
            CUI_MENU_SRC_TYPE_APPCREATE, 
            CUI_MENU_TYPE_OPTION, 
            MENU_ID_WLAN_EAP_TTLS_TYPES_OPT, 
            MMI_TRUE, 
            NULL);
    }

    cui_menu_run(wlan_menu_cui_id);

}




/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_eap_peap_settings_eap_type
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_eap_ttls_settings_auth_type_ok(void)
{
    if (g_wlan_display_context.eap_ttls_auth_type == 0)
    {
        mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_ERROR_ONE_EAP_NEEDED)), MMI_EVENT_FAILURE, wlan_parent_group_id, NULL);

        return;
    }
    mmi_frm_scrn_close_active_id();
}

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_ttls_settings_callback
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_ttls_settings_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM) 
    {
        /* only change highlight.  do nothing in tap callback function */
        return;
    }
    
    if (!wgui_category_if_pop_option_menu())
    {
        mmi_wlan_eap_ttls_settings_auth_type_center();
    }
	
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_eap_ttls_settings_auth_type
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_eap_ttls_settings_auth_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *nStrList[SRV_DTCNT_WLAN_EAP_TTLS_TYPES_TOTAL];
    U16 iconStates[SRV_DTCNT_WLAN_EAP_TTLS_TYPES_TOTAL];
    U8 i, idx;
    S32 num_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
        wlan_parent_group_id,
        SCR_ID_DTCNT_WLAN_EAP_TTLS_SETTINGS_TUNNELED_AUTH_PROTOCOL,
        NULL,
        mmi_wlan_entry_eap_ttls_settings_auth_type,
        MMI_FRM_FULL_SCRN))
    {
        return;
    } 
	
    guiBuffer = mmi_frm_scrn_get_gui_buf(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_EAP_TTLS_SETTINGS_TUNNELED_AUTH_PROTOCOL);

    SetParentHandler(0);
    RegisterHighlightHandler(mmi_wlan_eap_ttls_settings_auth_type_highlight_hdlr);

    for (i = 0; i < SRV_DTCNT_WLAN_EAP_TTLS_TYPES_TOTAL; i++)
    {
        idx = srv_dtcnt_wlan_eap_ttls_types(i);

        if (idx == MMI_DTCNT_WLAN_AUTH_TYPE_END)
            break;

        num_type++;
        nStrList[i] = (PU8) mmi_wlan_get_auth_type_name(idx);
        if (g_wlan_display_context.eap_ttls_auth_type & (g_wlan_auth_module[idx].val))
        {
            iconStates[i] = CHECKBOX_ON_IMAGE_ID;
        }
        else
        {
            iconStates[i] = CHECKBOX_OFF_IMAGE_ID;
        }
    }

    ShowCategory73Screen(
        STR_ID_DTCNT_WLAN_TUNNELED_AUTH_PROTOCOL,
        GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_type,
        nStrList,
        (U16*) gIndexIconsImageList,
        iconStates,
        g_wlan_display_context.sel_eap_ttls_auth_type,
        guiBuffer,
        ICON_TEXT_ICON);
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_wlan_eap_ttls_settings_callback);
#endif
//#ifndef __MMI_WGUI_DISABLE_CSK__
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	SetCenterSoftkeyFunction(mmi_wlan_eap_ttls_settings_auth_type_center, KEY_EVENT_UP);
//#endif

    SetLeftSoftkeyFunction(mmi_wlan_entry_eap_ttls_settings_auth_type_opt, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_entry_eap_ttls_settings_auth_type_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_wlan_entry_eap_ttls_settings_auth_type_ok, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_entry_eap_ttls_settings_auth_type_ok, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_ttls_settings_save
 * DESCRIPTION
 *  LSK handler for profile editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_ttls_settings_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.modified = TRUE;
    mmi_frm_scrn_multiple_close(g_wlan_display_context.inline_setting_cui_id, mmi_frm_scrn_get_active_id(), 1, 0, SCR_ID_DTCNT_WLAN_EAP_TYPE, 1);

}

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
* FUNCTION
*  mmi_wlan_eap_ttls_settings_tap_callback
* DESCRIPTION
*  Execute correspoding function of selected shortcuts.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_wlan_eap_ttls_settings_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (index)
    {
    case WLAN_EAP_TTLS_SETTINGS_CA_CERT:
        mmi_wlan_entry_ca_cert_list();
        break;
    case WLAN_EAP_TTLS_SETTINGS_TUNNELED_AUTH_PROTOCOL:
        mmi_wlan_entry_eap_ttls_settings_auth_type();
        break;
    }
	
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_eap_ttls_settings
 * DESCRIPTION
 *  It download a theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_eap_ttls_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *pString = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.inline_eap_ttls_cui_id = cui_inline_create(
                                wlan_parent_group_id,
                                &eap_ttls_inline_struct);

    pString = (U8*) GetString(STR_GLOBAL_NONE);

#ifdef __CERTMAN_SUPPORT__
    if (mmi_ucs2strlen(g_wlan_display_context.root_ca_name) > 0)
    {
        pString = (U8*)g_wlan_display_context.root_ca_name;
    }
#else
    if (mmi_ucs2strlen(g_wlan_display_context.root_ca_path) > 0)
    {
        pString = (U8*) g_wlan_display_context.root_ca_path;
    }
#endif /* __CERTMAN_SUPPORT__ */
    else
    {
        pString = (U8*) GetString(STR_GLOBAL_NONE);
    }
    cui_inline_set_value(g_wlan_display_context.inline_eap_ttls_cui_id, CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TTLS_SETTINGS_CA_CERT, pString); 

    pString = (U8*) GetString(STR_ID_DTCNT_WLAN_EAP_TYPES);
    cui_inline_set_value(g_wlan_display_context.inline_eap_ttls_cui_id, CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TTLS_SETTINGS_TUNNELED_AUTH_PROTOCOL, pString); 

    /* Reset change flag the first time entry settings */
    g_wlan_display_context.modified2 = FALSE;
    modified3 = FALSE;
    cui_inline_set_title_icon(g_wlan_display_context.inline_eap_ttls_cui_id, GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));
    cui_inline_run(g_wlan_display_context.inline_eap_ttls_cui_id);
}


#endif /* WLAN_EAP_TTLS_SUPPORT */ 

#ifdef WLAN_EAP_PEAP_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_peap_types_opt_activate
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_peap_types_opt_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_wlan_eap_peap_settings_eap_type_ok, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_eap_peap_settings_eap_type_ok, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_peap_types_opt_edit
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_peap_types_opt_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr auth_settings_hdlr;
    U8 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx = srv_dtcnt_wlan_eap_peap_types(g_wlan_display_context.sel_eap_peap_auth_type);
    auth_settings_hdlr = g_wlan_auth_module[idx].entry_func;

    ASSERT(auth_settings_hdlr != NULL);

    SetLeftSoftkeyFunction(auth_settings_hdlr, KEY_EVENT_UP);
    SetKeyHandler(auth_settings_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_peap_settings_eap_type_ok
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_peap_settings_eap_type_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx;
    U32 val;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx = srv_dtcnt_wlan_eap_peap_types(g_wlan_display_context.sel_eap_peap_auth_type);
    val = g_wlan_auth_module[idx].val;

    if (g_wlan_display_context.eap_peap_auth_type & val)
    {
        g_wlan_display_context.eap_peap_auth_type &= ~val;
    }
    else
    {
        g_wlan_display_context.eap_peap_auth_type |= val;
    }

    g_wlan_display_context.modified2 = TRUE;
    mmi_frm_scrn_close_active_id();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_peap_settings_eap_type_ok
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_peap_settings_eap_type_center(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx;
    U32 val;
    U16 iconStates;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx = srv_dtcnt_wlan_eap_peap_types(g_wlan_display_context.sel_eap_peap_auth_type);
    val = g_wlan_auth_module[idx].val;

    if (g_wlan_display_context.eap_peap_auth_type & val)
    {
        g_wlan_display_context.eap_peap_auth_type &= ~val;
        iconStates = CHECKBOX_OFF_IMAGE_ID;
    }
    else
    {
        g_wlan_display_context.eap_peap_auth_type |= val;
        iconStates = CHECKBOX_ON_IMAGE_ID;
    }

    g_wlan_display_context.modified2 = TRUE;
    
    Category73ChangeItemIcon(g_wlan_display_context.sel_eap_peap_auth_type, 1, (PU8)get_image(iconStates));
    Category73RedrawScreen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_peap_settings_eap_type_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_peap_settings_eap_type_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.sel_eap_peap_auth_type = nIndex;
    /*
     * FuncPtr auth_settings_hdlr;
     * 
     * g_wlan_display_context.sel_auth_type2 = g_wlan_eap_peap_types[nIndex];
     * auth_settings_hdlr = g_wlan_auth_module[g_wlan_display_context.sel_auth_type2].entry_func;
     * 
     * if(auth_settings_hdlr == NULL)
     * {
     * ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
     * SetLeftSoftkeyFunction(mmi_wlan_eap_peap_settings_eap_type_ok, KEY_EVENT_UP);
     * }
     * else
     * {
     * ChangeLeftSoftkey(STR_ID_DTCNT_WLAN_CONFIGURE, 0);
     * SetLeftSoftkeyFunction(auth_settings_hdlr, KEY_EVENT_UP);
     * }
     */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_eap_peap_settings_eap_type_opt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_eap_peap_settings_eap_type_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx;
    mmi_id wlan_menu_cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    idx = srv_dtcnt_wlan_eap_peap_types(g_wlan_display_context.sel_eap_peap_auth_type);
    if (g_wlan_auth_module[idx].entry_func == NULL)
    {

        wlan_menu_cui_id = cui_menu_create(
            wlan_parent_group_id, 
            CUI_MENU_SRC_TYPE_APPCREATE, 
            CUI_MENU_TYPE_OPTION, 
            MENU_ID_WLAN_EAP_PEAP_TYPES_OPT2, 
            MMI_TRUE, 
            NULL);

    }
    else
    {
        wlan_menu_cui_id = cui_menu_create(
            wlan_parent_group_id, 
            CUI_MENU_SRC_TYPE_APPCREATE, 
            CUI_MENU_TYPE_OPTION, 
            MENU_ID_WLAN_EAP_PEAP_TYPES_OPT, 
            MMI_TRUE, 
            NULL);
    }

    cui_menu_run(wlan_menu_cui_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_eap_peap_settings_eap_type
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_eap_peap_settings_eap_type_ok(void)
{
    if (g_wlan_display_context.eap_peap_auth_type == 0)
    {

        mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_ERROR_ONE_EAP_NEEDED)), MMI_EVENT_FAILURE, wlan_parent_group_id, NULL);

        return;
    }
    mmi_frm_scrn_close_active_id();
}
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_eap_peap_fte_callback
 * DESCRIPTION
 *  fte tap callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_eap_peap_fte_callback(mmi_tap_type_enum tap_type, S32 index)
{

/*----------------------------------------------------------------*/
/* Local Variables												  */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body													  */
/*----------------------------------------------------------------*/

    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM) 
    {
    	/* only change highlight.  do nothing in tap callback function */
    	return;
    }

    if (!wgui_category_if_pop_option_menu())
    {
        mmi_wlan_eap_peap_settings_eap_type_center();
    }
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_eap_peap_settings_eap_type
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_eap_peap_settings_eap_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *nStrList[SRV_DTCNT_WLAN_EAP_PEAP_TYPES_TOTAL];
    U16 iconStates[SRV_DTCNT_WLAN_EAP_PEAP_TYPES_TOTAL];
    U8 i, idx;
    S32 num_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
        wlan_parent_group_id,
        SCR_ID_DTCNT_WLAN_EAP_PEAP_SETTINGS_EAP_TYPE,
        NULL,
        mmi_wlan_entry_eap_peap_settings_eap_type,
        MMI_FRM_FULL_SCRN))
    {
        return;
    } 
	
    guiBuffer = mmi_frm_scrn_get_gui_buf(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_EAP_PEAP_SETTINGS_EAP_TYPE);

    SetParentHandler(0);
    RegisterHighlightHandler(mmi_wlan_eap_peap_settings_eap_type_highlight_hdlr);

    for (i = 0; i < SRV_DTCNT_WLAN_EAP_PEAP_TYPES_TOTAL; i++)
    {
        idx = srv_dtcnt_wlan_eap_peap_types(i);

        if (idx == MMI_DTCNT_WLAN_AUTH_TYPE_END)
            break;
        
        num_type++;
        nStrList[i] = (PU8) mmi_wlan_get_auth_type_name(idx);
        if (g_wlan_display_context.eap_peap_auth_type & (g_wlan_auth_module[idx].val))
        {
            iconStates[i] = CHECKBOX_ON_IMAGE_ID;
        }
        else
        {
            iconStates[i] = CHECKBOX_OFF_IMAGE_ID;
        }
    }

    ShowCategory73Screen(
        STR_ID_DTCNT_WLAN_EAP_TYPES,
        GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_type,
        nStrList,
        (U16*) gIndexIconsImageList,
        iconStates,
        g_wlan_display_context.sel_eap_peap_auth_type,
        guiBuffer,
        ICON_TEXT_ICON);
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_wlan_entry_eap_peap_fte_callback);
#endif
//#ifndef __MMI_WGUI_DISABLE_CSK__
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	SetCenterSoftkeyFunction(mmi_wlan_eap_peap_settings_eap_type_center, KEY_EVENT_UP);
//#endif

    SetLeftSoftkeyFunction(mmi_wlan_entry_eap_peap_settings_eap_type_opt, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_entry_eap_peap_settings_eap_type_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_wlan_entry_eap_peap_settings_eap_type_ok, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_entry_eap_peap_settings_eap_type_ok, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_peap_settings_save
 * DESCRIPTION
 *  LSK handler for profile editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_peap_settings_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.modified = TRUE;
    mmi_frm_scrn_multiple_close(g_wlan_display_context.inline_setting_cui_id, mmi_frm_scrn_get_active_id(), 1, 0, SCR_ID_DTCNT_WLAN_EAP_TYPE, 1);

}

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
* FUNCTION
*  mmi_wlan_eap_peap_settings_tap_callback
* DESCRIPTION
*  Execute correspoding function of selected shortcuts.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_wlan_eap_peap_settings_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (index)
    {
    case WLAN_EAP_PEAP_SETTINGS_CA_CERT:
        mmi_wlan_entry_ca_cert_list();
        break;
    case WLAN_EAP_PEAP_SETTINGS_TUNNELED_AUTH_PROTOCOL:
        mmi_wlan_entry_eap_peap_settings_eap_type();
        break;
    }
	
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_eap_peap_settings
 * DESCRIPTION
 *  It download a theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_eap_peap_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *pString = NULL;
    g_wlan_display_context.inline_eap_peap_cui_id = cui_inline_create(
                                 wlan_parent_group_id,
                                 &eap_peap_inline_struct);

    pString = (U8*) GetString(STR_GLOBAL_NONE);

#ifdef __CERTMAN_SUPPORT__
    if (mmi_ucs2strlen(g_wlan_display_context.root_ca_name) > 0)
    {
        pString = (U8*)g_wlan_display_context.root_ca_name;
    }
#else
    if (mmi_ucs2strlen(g_wlan_display_context.root_ca_path) > 0)
    {
        pString = (U8*) g_wlan_display_context.root_ca_path;
    }
#endif /* __CERTMAN_SUPPORT__ */
    else
    {
        pString = (U8*) GetString(STR_GLOBAL_NONE);
    }
    cui_inline_set_value(g_wlan_display_context.inline_eap_peap_cui_id, CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_PEAP_SETTINGS_CA_CERT, pString); 

    pString = (U8*) GetString(STR_ID_DTCNT_WLAN_EAP_TYPES);
    cui_inline_set_value(g_wlan_display_context.inline_eap_peap_cui_id, CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_PEAP_SETTINGS_TUNNELED_AUTH_PROTOCOL, pString); 

    /* Reset change flag the first time entry settings */
    g_wlan_display_context.modified2 = FALSE;
    modified3 = FALSE;
    cui_inline_set_title_icon(g_wlan_display_context.inline_eap_peap_cui_id, GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));
    cui_inline_run(g_wlan_display_context.inline_eap_peap_cui_id);

}


#endif /* WLAN_EAP_PEAP_SUPPORT */ 

#ifdef WLAN_EAP_TLS_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_tls_settings_save
 * DESCRIPTION
 *  LSK handler for profile editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_tls_settings_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.modified = TRUE;
    /* modified2: made RSK as BACK when enter settings next time */
    g_wlan_display_context.modified2 = FALSE;
    mmi_frm_scrn_multiple_close(
        g_wlan_display_context.inline_setting_cui_id, 
        mmi_frm_scrn_get_active_id(), 1, 2, SCR_ID_INVALID, 0);

}

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
* FUNCTION
*  mmi_wlan_eap_tls_settings_tap_callback
* DESCRIPTION
*  Execute correspoding function of selected shortcuts.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_wlan_eap_tls_settings_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (index)
    {
    case WLAN_EAP_TLS_SETTINGS_USER_CERT:
        mmi_wlan_entry_user_cert_list();
        break;
    case WLAN_EAP_TLS_SETTINGS_CA_CERT:
        mmi_wlan_entry_ca_cert_list();
        break;
#ifndef __CERTMAN_SUPPORT__
    case WLAN_EAP_TLS_SETTINGS_PRIV_KEY:
        mmi_wlan_entry_private_key_list();
        break;
#endif
    }

}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_eap_tls_settings
 * DESCRIPTION
 *  It download a theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_eap_tls_settings(void)
{
    g_wlan_display_context.inline_eap_tls_cui_id = cui_inline_create(
                                wlan_parent_group_id,
                                &eap_tls_inline_struct);
		
#ifdef __CERTMAN_SUPPORT__
    if (mmi_ucs2strlen(g_wlan_display_context.root_ca_name) > 0)
    {
        cui_inline_set_value(g_wlan_display_context.inline_eap_tls_cui_id, CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_CA_CERT, g_wlan_display_context.root_ca_name); 
    }
#else
    if (mmi_ucs2strlen(g_wlan_display_context.root_ca_path) > 0)
    {
        cui_inline_set_value(g_wlan_display_context.inline_eap_tls_cui_id, CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_CA_CERT, g_wlan_display_context.root_ca_path); 
    }
#endif /* __CERTMAN_SUPPORT__ */
    else
    {
        cui_inline_set_value(g_wlan_display_context.inline_eap_tls_cui_id, CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_CA_CERT, (U8*)GetString(STR_GLOBAL_NONE)); 
    }


#ifdef __CERTMAN_SUPPORT__   
    if (mmi_ucs2strlen(g_wlan_display_context.client_user_name) > 0)
    {
        cui_inline_set_value(g_wlan_display_context.inline_eap_tls_cui_id, CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_USER_CERT, g_wlan_display_context.client_user_name); 
    }
#else
    if (mmi_ucs2strlen(g_wlan_display_context.client_ca_path) > 0)
    {
    	cui_inline_set_value(g_wlan_display_context.inline_eap_tls_cui_id, CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_USER_CERT, g_wlan_display_context.client_ca_path); 
    }
#endif /* __CERTMAN_SUPPORT__ */
    else
    {
    	cui_inline_set_value(g_wlan_display_context.inline_eap_tls_cui_id, CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_USER_CERT, (U8*)GetString(STR_GLOBAL_NONE)); 
    }

    cui_inline_set_value(g_wlan_display_context.inline_eap_tls_cui_id, CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_PRIV_KEY_PASSWD, g_wlan_display_context.private_key_passwd_str); 
    cui_inline_set_value(g_wlan_display_context.inline_eap_tls_cui_id, CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_USERNAME, g_wlan_display_context.username_str); 
    cui_inline_set_fullscreen_edit_title_icon(
		g_wlan_display_context.inline_eap_tls_cui_id, 
		CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_PRIV_KEY_PASSWD, 
		GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));
	cui_inline_set_fullscreen_edit_title_icon(
		g_wlan_display_context.inline_eap_tls_cui_id, 
		CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_USERNAME, 
		GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));
    /* Reset change flag the first time entry settings */
    g_wlan_display_context.modified2 = FALSE;
    cui_inline_set_title_icon(g_wlan_display_context.inline_eap_tls_cui_id, GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));
    cui_inline_run(g_wlan_display_context.inline_eap_tls_cui_id);
}


#endif /* WLAN_EAP_TLS_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_user_info_save
 * DESCRIPTION
 *  LSK handler for profile editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_user_info_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_is_present(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_EAP_PEAP_SETTINGS_EAP_TYPE, MMI_FRM_NODE_ALL_FLAG))
    {
        g_wlan_display_context.modified2 = TRUE;
        modified3 = TRUE;
    }
    else if (mmi_frm_scrn_is_present(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_EAP_TTLS_SETTINGS_TUNNELED_AUTH_PROTOCOL, MMI_FRM_NODE_ALL_FLAG))
    {
        g_wlan_display_context.modified2 = TRUE;
        modified3 = TRUE;
    }
    else
    {
        g_wlan_display_context.modified = TRUE;
    }
    mmi_frm_scrn_multiple_close(g_wlan_display_context.inline_setting_cui_id, mmi_frm_scrn_get_active_id(), 1, 2, SCR_ID_INVALID, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_user_info
 * DESCRIPTION
 *  It download a theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_user_info(void)
{
    g_wlan_display_context.inline_eap_user_info_cui_id = cui_inline_create(
                                wlan_parent_group_id,
                                &eap_user_info_inline_struct);

    cui_inline_set_value(g_wlan_display_context.inline_eap_user_info_cui_id, CUI_INLINE_ITEM_ID_BASE + WLAN_USER_INFO_USERNAME, g_wlan_display_context.username_str); 
	cui_inline_set_fullscreen_edit_title_icon(
		g_wlan_display_context.inline_eap_user_info_cui_id, 
		CUI_INLINE_ITEM_ID_BASE + WLAN_USER_INFO_USERNAME, 
		GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));
	cui_inline_set_fullscreen_edit_title_icon(
		g_wlan_display_context.inline_eap_user_info_cui_id, 
		CUI_INLINE_ITEM_ID_BASE + WLAN_USER_INFO_PASSWORD, 
		GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));
    cui_inline_set_value(g_wlan_display_context.inline_eap_user_info_cui_id, CUI_INLINE_ITEM_ID_BASE + WLAN_USER_INFO_PASSWORD, g_wlan_display_context.password_str); 
    cui_inline_set_title_icon(g_wlan_display_context.inline_eap_user_info_cui_id, GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));
    cui_inline_run(g_wlan_display_context.inline_eap_user_info_cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_type_activate
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_type_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx;
    U32 val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx = srv_dtcnt_wlan_eap_types(g_wlan_display_context.sel_auth_type1);
    val = g_wlan_auth_module[idx].val;

    if (g_wlan_display_context.auth_type1 & val)
    {
        g_wlan_display_context.auth_type1 &= ~val;
    }
    else
    {
        g_wlan_display_context.auth_type1 |= val;
    }

    g_wlan_display_context.modified = TRUE;
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_type_activate_center
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_type_activate_center(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx;
    U32 val;
    U16 iconStates;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx = srv_dtcnt_wlan_eap_types(g_wlan_display_context.sel_auth_type1);
    val = g_wlan_auth_module[idx].val;

    if (g_wlan_display_context.auth_type1 & val)
    {
        g_wlan_display_context.auth_type1 &= ~val;
        iconStates = CHECKBOX_OFF_IMAGE_ID;
    }
    else
    {
        g_wlan_display_context.auth_type1 |= val;
        iconStates = CHECKBOX_ON_IMAGE_ID;
    }

    g_wlan_display_context.modified = TRUE;

    Category73ChangeItemIcon(g_wlan_display_context.sel_auth_type1, 1, (PU8)get_image(iconStates));
    Category73RedrawScreen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_type_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_type_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.sel_auth_type1 = nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_eap_type_opt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_eap_type_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx;
    mmi_id wlan_menu_cui_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    idx = srv_dtcnt_wlan_eap_types(g_wlan_display_context.sel_auth_type1);
    if (g_wlan_auth_module[idx].entry_func == NULL)
    {
        wlan_menu_cui_id = cui_menu_create(
            wlan_parent_group_id, 
            CUI_MENU_SRC_TYPE_APPCREATE, 
            CUI_MENU_TYPE_OPTION, 
            MENU_ID_WLAN_EAP_TYPES_OPT2, 
            MMI_TRUE, 
            NULL);

    }
    else
    {

        wlan_menu_cui_id = cui_menu_create(
            wlan_parent_group_id, 
            CUI_MENU_SRC_TYPE_APPCREATE, 
            CUI_MENU_TYPE_OPTION, 
            MENU_ID_WLAN_EAP_TYPES_OPT, 
            MMI_TRUE, 
            NULL);

    }

    cui_menu_run(wlan_menu_cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_eap_type_ok
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_eap_type_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_wlan_display_context.auth_type1 == 0)
    {
        mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_ERROR_ONE_EAP_NEEDED)), MMI_EVENT_FAILURE, wlan_parent_group_id, NULL);

        return;
    }
    mmi_frm_scrn_close_active_id();
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
* FUNCTION
*  mmi_wlan_eap_type_tap_callback
* DESCRIPTION
*  Execute correspoding function of selected shortcuts.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_wlan_eap_type_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM) 
    {
        /* only change highlight.  do nothing in tap callback function */
        return;
    }
    
    if (!wgui_category_if_pop_option_menu())
    {
        mmi_wlan_eap_type_activate_center();
    }
	
}
#endif
//remove for option slim
#if 0
/* under construction !*/
/* under construction !*/
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_eap_type
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_eap_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *nStrList[SRV_DTCNT_WLAN_EAP_TYPES_TOTAL];
    U16 iconStates[SRV_DTCNT_WLAN_EAP_TYPES_TOTAL];
    U8 i;
    U8 idx;
    S32 num_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
        wlan_parent_group_id,
        SCR_ID_DTCNT_WLAN_EAP_TYPE,
        NULL,
        mmi_wlan_entry_eap_type,
        MMI_FRM_FULL_SCRN))
    {
        return;
    } 
	
    guiBuffer = mmi_frm_scrn_get_gui_buf(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_EAP_TYPE);


    if (guiBuffer == NULL)
    {
        g_wlan_display_context.sel_auth_type1 = 0;
        ASSERT(g_wlan_display_context.auth_type1 > 0);
    }

    SetParentHandler(0);
    RegisterHighlightHandler(mmi_wlan_eap_type_highlight_hdlr);

    for (i = 0; i < SRV_DTCNT_WLAN_EAP_TYPES_TOTAL; i++)
    {
        idx = srv_dtcnt_wlan_eap_types(i);

        if (idx == MMI_DTCNT_WLAN_AUTH_TYPE_END)
            break;
        
        num_type++;
        nStrList[i] = (PU8) mmi_wlan_get_auth_type_name(idx);
        if (g_wlan_display_context.auth_type1 & (g_wlan_auth_module[idx].val))
        {
            iconStates[i] = CHECKBOX_ON_IMAGE_ID;
        }
        else
        {
            iconStates[i] = CHECKBOX_OFF_IMAGE_ID;
        }
    }

    ShowCategory73Screen(
        STR_ID_DTCNT_WLAN_EAP_TYPES,
        GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_type,
        nStrList,
        (U16*) gIndexIconsImageList,
        iconStates,
        g_wlan_display_context.sel_auth_type1,
        guiBuffer,
        ICON_TEXT_ICON);
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_wlan_eap_type_tap_callback);
#endif
//#ifndef __MMI_WGUI_DISABLE_CSK__
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	SetCenterSoftkeyFunction(mmi_wlan_eap_type_activate_center, KEY_EVENT_UP);
//#endif

    SetLeftSoftkeyFunction(mmi_wlan_entry_eap_type_opt, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_entry_eap_type_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_wlan_entry_eap_type_ok, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_entry_eap_type_ok, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_eap_types_opt_activate
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_eap_types_opt_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_wlan_eap_type_activate, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_eap_type_activate, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_eap_types_opt_edit
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_eap_types_opt_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr auth_settings_hdlr;
    U8 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx = srv_dtcnt_wlan_eap_types(g_wlan_display_context.sel_auth_type1);
    auth_settings_hdlr = g_wlan_auth_module[idx].entry_func;

    ASSERT(auth_settings_hdlr != NULL);

    SetLeftSoftkeyFunction(auth_settings_hdlr, KEY_EVENT_UP);
    SetKeyHandler(auth_settings_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


#define WLAN_WIZARD_2
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_save_default_eap
 * DESCRIPTION
 *  To save default eap settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_save_default_eap_to_display_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set default EAP EAP-PEAP + EAP-MSCHAPV2 */
    g_wlan_display_context.auth_type1 |= WLAN_EAP_PEAP;
    g_wlan_display_context.auth_type1 |= WLAN_EAP_TTLS;
    g_wlan_display_context.auth_type1 |= WLAN_EAP_SIM;
    g_wlan_display_context.auth_type1 |= WLAN_EAP_AKA;
    
    g_wlan_display_context.eap_peap_auth_type |= WLAN_EAP_MSCHAV2;
    g_wlan_display_context.eap_peap_auth_type |= WLAN_EAP_GTC;

    g_wlan_display_context.eap_ttls_auth_type |= WLAN_EAP_SIM;
    g_wlan_display_context.eap_ttls_auth_type |= WLAN_EAP_MSCHAV2;
    g_wlan_display_context.eap_ttls_auth_type |= WLAN_MSCHAPV2;
    g_wlan_display_context.eap_ttls_auth_type |= WLAN_EAP_GTC;
    g_wlan_display_context.eap_ttls_auth_type |= WLAN_PAP;
    g_wlan_display_context.eap_ttls_auth_type |= WLAN_CHAP;
    g_wlan_display_context.eap_ttls_auth_type |= WLAN_MSCHAP;
    g_wlan_display_context.eap_ttls_auth_type |= WLAN_EAP_AKA;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_save_default_eap_connect
 * DESCRIPTION
 *  To save default eap settings and connect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_save_default_eap_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wlan_save_default_eap_to_display_cntx();
    mmi_wlan_entry_find_network_connect();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_default_eap_input
 * DESCRIPTION
 *  To ask user to input user name & password
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_default_eap_input(void)
{
    g_wlan_display_context.inline_default_eap_cui_id = cui_inline_create(
                             wlan_parent_group_id,
							 &eap_default_inline_struct);

    cui_inline_set_value(g_wlan_display_context.inline_default_eap_cui_id, CUI_INLINE_ITEM_ID_BASE + WLAN_USER_INFO_USERNAME, g_wlan_display_context.username_str); 
	cui_inline_set_fullscreen_edit_title_icon(
		g_wlan_display_context.inline_default_eap_cui_id, 
		CUI_INLINE_ITEM_ID_BASE + WLAN_USER_INFO_USERNAME, 
		GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));
    cui_inline_set_fullscreen_edit_title_icon(
		g_wlan_display_context.inline_default_eap_cui_id, 
		CUI_INLINE_ITEM_ID_BASE + WLAN_USER_INFO_PASSWORD, 
		GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));
    cui_inline_set_value(g_wlan_display_context.inline_default_eap_cui_id, CUI_INLINE_ITEM_ID_BASE + WLAN_USER_INFO_PASSWORD, g_wlan_display_context.password_str); 
    cui_inline_set_title_icon(g_wlan_display_context.inline_default_eap_cui_id, GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));
    cui_inline_run(g_wlan_display_context.inline_default_eap_cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_save_default_eap_to_profile
 * DESCRIPTION
 *  To save the default eap settings
 * PARAMETERS
 *  prof
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_save_default_eap_to_profile(mmi_wlan_profile_struct *prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (prof->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X || 
        prof->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY ||
        prof->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY)
    {
        prof->auth_type1 = g_wlan_display_context.auth_type1;
        prof->eap_peap_auth_type = g_wlan_display_context.eap_peap_auth_type;
        prof->eap_ttls_auth_type = g_wlan_display_context.eap_ttls_auth_type;
    #ifndef __CERTMAN_SUPPORT__
        mmi_ucs2cpy((CHAR*)prof->client_ca_path, (const CHAR*)g_wlan_display_context.client_ca_path);
        mmi_ucs2cpy((CHAR*)prof->root_ca_path, (const CHAR*)g_wlan_display_context.root_ca_path);
        mmi_ucs2cpy((CHAR*)prof->private_key_path, (const CHAR*)g_wlan_display_context.private_key_path);
    #else
        prof->client_ca_id = g_wlan_display_context.client_ca_id;
        prof->root_ca_id = g_wlan_display_context.root_ca_id;
    #endif /* __CERTMAN_SUPPORT__ */
    
        mmi_ucs2_to_asc((CHAR*)prof->private_key_passwd, (CHAR*)g_wlan_display_context.private_key_passwd_str);
        mmi_ucs2_to_asc((CHAR*)prof->username, (CHAR*)g_wlan_display_context.username_str);
        mmi_ucs2_to_asc((CHAR*)prof->password, (CHAR*)g_wlan_display_context.password_str);

        memset(g_wlan_display_context.username_str, 0, sizeof(g_wlan_display_context.username_str));
        memset(g_wlan_display_context.password_str, 0, sizeof(g_wlan_display_context.password_str));
    }
	
    if(g_wlan_display_context.allow_peap0 > 0)
    {
    	prof->peap_version |= SUPC_PHASE1_PEAP_0;
    }
    else
    {
    	prof->peap_version &= ~SUPC_PHASE1_PEAP_0;
    }
    
    if(g_wlan_display_context.allow_peap1 > 0)
    {
    	prof->peap_version |= SUPC_PHASE1_PEAP_1;
    }
    else
    {
    	prof->peap_version &= ~SUPC_PHASE1_PEAP_1;
    }
}

#endif /* __MMI_WLAN_FEATURES__ */ 

#endif /* __TCPIP__ */
