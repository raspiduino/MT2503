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
 * PushMsgScreenHdlr.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the various screen handler API of Push message.
 *
 * Author:
 * -------
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
//#include "MMI_include.h"
#include "MMI_features.h"
#ifdef __WAP_PUSH_SUPPORT__

#include "CommonScreens.h"
#include "mmi_frm_input_gprot.h"

//#include "SMSGuiInterfaceProt.h"
//#include "IdleAppProt.h"
#include "WAPPushUIProts.h"

#ifdef __MMI_FTE_SUPPORT__
#include "wgui_categories_util.h"
#endif /*__MMI_FTE_SUPPORT__*/

#ifdef __MMI_EMAIL__
#include "EmailAppGProt.h"
#endif

//#if defined(__MMI_WLAN_FEATURES__)
//#include "NetworkSetupDefs.h"
//#endif
    #include "MMI_features.h"
    #include "MMIDataType.h"
    #include "InlineCuiGprot.h"
    #include "mmi_rp_app_mmi_wap_push_def.h"
    #include "ImeGprot.h"
    #include "wgui_categories_inputs.h"
    #include "custom_phb_config.h"
    #include "GlobalResDef.h"
    #include "GlobalMenuItems.h"
    #include "WAPPushUITypes.h"
    #include "WAPPushScreenHdlr.h"
    #include "kal_public_api.h"
    #include "kal_general_types.h"
    #include "CustMenuRes.h"
    #include "mmi_frm_events_gprot.h"
    #include "mmi_frm_mem_gprot.h"
    #include "string.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "GlobalConstants.h"
    #include "DebugInitDef_Int.h"
    #include "menucuigprot.h"
    #include "CustDataRes.h"
    #include "gui_data_types.h"
    #include "WAPPushDMgr.h"
    #include "Unicodexdcl.h"
    #include "wgui_categories_util.h"
    #include "wgui_categories_list.h"
    #include "WAPPushResDef.h"
    #include "WAPPushSrvTypes.h"
    #include "WAPPushSrvProts.h"
    #include "wgui_categories_email.h"
    #include "kal_trace.h"
    #include "mmi_inet_app_trc.h"
    #include "MMI_inet_app_trc.h"
    #include "wgui_categories_text_viewer.h"
    #include "wgui_categories_popup.h"
    #include "MessagesMiscell.h"
    #include "mmi_frm_history_gprot.h"
    #include "IdleAppDef.h"
    #include "wgui_categories.h"
    #include "gdi_include.h"
    #include "CommonScreensResDef.h"
    #include "AlertScreen.h"
    #include "NetSetSrvGprot.h"
    #include "NetSetAppGprot.h"
    #include "pmg_struct.h"
    #include "common_nvram_editor_data_item.h"
    #include "UMGProt.h"
    #include "mmi_frm_scenario_gprot.h"
	#include "WAPPushGprots.h"
extern U8 wgui_inline_list_menu_changed;
static U16 g_push_scrhdlr_index;
static U16 g_push_rc_index;

//typedef void (*FuncPtr) (void);
//extern FuncPtr currKeyFuncPtrs[MAX_KEYS][MAX_KEY_TYPE];
void mmi_wap_push_draw_dummy_screen (MMI_BOOL gdi_lock);
#ifdef __MMI_NCENTER_SUPPORT__
extern mmi_ret mmi_wap_push_ncenter_msg_queue_handler(mmi_event_struct *evt);
#endif
/************************************************************************/
/* Inline CUI Start                                             */
/************************************************************************/
mmi_id menu_id_new;
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
static const cui_inline_item_caption_struct g_mmi_brw_push_sender_caption = 
{
    STR_ID_BRW_PUSH_SENDER_ADDRESS
};

static const cui_inline_item_caption_struct g_mmi_brw_push_smsc_caption = 
{
    STR_ID_BRW_PUSH_SMSC_ADDR
};
static const cui_inline_item_caption_struct g_mmi_brw_push_ip_caption = 
{
    STR_ID_PUSH_INBOX_TRUST_LIST_IP_ADDRESS
};



static const cui_inline_item_text_edit_struct g_mmi_brw_push_sender_edit = 
{
    0, 0, (MMI_PHB_NUMBER_LENGTH + 1), IMM_INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING, 0, NULL
};

static const cui_inline_item_text_edit_struct g_mmi_brw_push_smsc_edit = 
{
    0, 0, (MMI_PHB_NUMBER_LENGTH + 1), IMM_INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING, 0, NULL
};


static const cui_inline_item_ip4_struct g_mmi_brw_push_ip_edit = 
{
    0, 0, 0, 0
};


static const cui_inline_set_item_struct g_mmi_brw_push_ph_num_inline_item[4] =
{
    {MMI_BRW_PUSH_PH_NUM_SENDER_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION,    IMG_GLOBAL_L1, (void*)&g_mmi_brw_push_sender_caption},
    {MMI_BRW_PUSH_PH_NUM_SENDER_EDIT,    CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_LEFT_JUSTIFY,       0, (void*)&g_mmi_brw_push_sender_edit},
    {MMI_BRW_PUSH_PH_NUM_SMSC_CAPTION,     CUI_INLINE_ITEM_TYPE_CAPTION,      IMG_GLOBAL_L2, (void*)&g_mmi_brw_push_smsc_caption},
    {MMI_BRW_PUSH_PH_NUM_SMSC_EDIT, CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_LEFT_JUSTIFY, 0, (void*)&g_mmi_brw_push_smsc_edit}
};


static const cui_inline_struct g_mmi_brw_push_ph_num_inline_screen = 
{
    4,
    STR_ID_PUSH_INBOX_TRUST_LIST_PHONE_NUMBER,
    SERVICES_WAP_MENU_ID,
    CUI_INLINE_SCREEN_DEFAULT_TEXT,
    NULL,
    g_mmi_brw_push_ph_num_inline_item
};

static const cui_inline_set_item_struct g_mmi_brw_push_ip_inline_item[2] =
{
    {MMI_BRW_PUSH_IP_NUM_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION ,      IMG_GLOBAL_L1, (void*)&g_mmi_brw_push_ip_caption},
    {MMI_BRW_PUSH_IP_NUM_EDIT,    CUI_INLINE_ITEM_TYPE_IP4,       0, (void*)&g_mmi_brw_push_ip_edit}
};


static const cui_inline_struct g_mmi_brw_push_ip_inline_screen = 
{
    2,
    STR_ID_PUSH_INBOX_TRUST_LIST_IP_ADDRESS,
    SERVICES_WAP_MENU_ID,
    CUI_INLINE_SCREEN_DEFAULT_TEXT,
    NULL,
    g_mmi_brw_push_ip_inline_item
};
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*For Inline CUI END*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

mmi_wap_push_context_struct *g_push_cntxt;

mmi_wap_push_screenDB_struct g_screenDB[]=
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    {  
        SCR_ID_PUSH_WHITE_LIST,
		NULL,
        NULL,
		MENU_ID_PUSH_WHITE_LIST,
        mmi_wap_push_scrhdlr_create_static_screen,
        mmi_wap_push_scrhdlr_pre_dynamic_screen_white_list,
        mmi_wap_push_scrhdlr_draw_dynamic_screen,
        mmi_wap_push_scrhdlr_post_static_screen,
		mmi_wap_push_setting_entry_white_list,
		mmi_wap_push_scrhdlr_exit_static_screen,
		NULL,
		mmi_wap_push_scrhdlr_rsk_static_screen,
		mmi_wap_push_scrhdlr_hilite_dynamic_screen,
		mmi_wap_push_scrhdlr_delete_static_screen
	},
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
	#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    {   
        SCR_ID_PUSH_BLACK_LIST,
		NULL,
        NULL,
		MENU_ID_PUSH_BLACK_LIST,
        mmi_wap_push_scrhdlr_create_static_screen,
        mmi_wap_push_scrhdlr_pre_dynamic_screen_black_list,
        mmi_wap_push_scrhdlr_draw_dynamic_screen,
        mmi_wap_push_scrhdlr_post_static_screen,
		mmi_wap_push_setting_entry_black_list,
		mmi_wap_push_scrhdlr_exit_static_screen,
		NULL,
		mmi_wap_push_scrhdlr_rsk_static_screen,
		mmi_wap_push_scrhdlr_hilite_dynamic_screen,
		mmi_wap_push_scrhdlr_delete_static_screen
	},
	#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
    /* End of synchronous dynamic screens */

    {   
        SCR_ID_PUSH_INBOX,
		NULL,
        NULL,
		0,
        mmi_wap_push_scrhdlr_create_static_screen,
        mmi_wap_push_scrhdlr_pre_async_dynamic_screen_inbox,
        mmi_wap_push_scrhdlr_draw_async_dynamic_screen,
        mmi_wap_push_scrhdlr_post_async_dynamic_screen_inbox,
		mmi_wap_push_setting_entry_service_inbox,
		mmi_wap_push_scrhdlr_exit_static_screen,
		mmi_wap_push_scrhdlr_lsk_service_inbox,
		mmi_wap_push_scrhdlr_rsk_static_screen,
		mmi_wap_push_scrhdlr_hilite_async_dynamic_screen,
		mmi_wap_push_scrhdlr_delete_static_screen
	},
    /* End of Asynchronous dynamic screens */

    {   
        SCR_ID_PUSH_SETTING,
		NULL,
        NULL,
		MENU_ID_SERVICE_MSG_SETTING,
        mmi_wap_push_scrhdlr_create_static_screen,
        mmi_wap_push_scrhdlr_pre_static_screen,
        mmi_wap_push_scrhdlr_draw_static_screen,
        mmi_wap_push_scrhdlr_post_static_screen,
		mmi_wap_push_setting_entry_main_menu,
		mmi_wap_push_scrhdlr_exit_static_screen,
		NULL,
		mmi_wap_push_scrhdlr_rsk_static_screen,
		NULL,
		mmi_wap_push_scrhdlr_delete_static_screen
	},
#ifdef __MMI_PUSH_IN_MSG__
    {   
        SCR_ID_PUSH_ENTRY_SERVICE_MSG,
		NULL,
        NULL,
		MENU_ID_SERVICE_MESSAGE,
        mmi_wap_push_scrhdlr_create_static_screen,
        mmi_wap_push_scrhdlr_pre_static_screen,
        mmi_wap_push_scrhdlr_draw_static_screen,
        mmi_wap_push_scrhdlr_post_static_screen,
		mmi_wap_push_entry_service_message,
		mmi_wap_push_scrhdlr_exit_static_screen,
		NULL,
		mmi_wap_push_scrhdlr_rsk_static_screen,
		NULL,
		mmi_wap_push_scrhdlr_delete_static_screen
	},
#endif /* __MMI_PUSH_IN_MSG__ */
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    {   
        SCR_ID_PUSH_WHITE_LIST_OPTIONS,
		NULL,
        NULL,
		MENU_ID_PUSH_ADDR_LIST_OPTIONS,
        mmi_wap_push_scrhdlr_create_static_screen,
        mmi_wap_push_scrhdlr_pre_static_screen,
        mmi_wap_push_scrhdlr_draw_static_screen,
        mmi_wap_push_scrhdlr_post_static_screen,
		mmi_wap_push_setting_entry_wl_opt_menu,
		mmi_wap_push_scrhdlr_exit_static_screen,
		NULL,
		mmi_wap_push_scrhdlr_rsk_static_screen,
		NULL,
		mmi_wap_push_scrhdlr_delete_static_screen
	},
    {   
        SCR_ID_PUSH_WHITE_LIST_ADD_NEW,
		NULL,
        NULL,
		MENU_ID_PUSH_ADD_NEW,
        mmi_wap_push_scrhdlr_create_static_screen,
        mmi_wap_push_scrhdlr_pre_static_screen,
        mmi_wap_push_scrhdlr_draw_static_screen,
        mmi_wap_push_scrhdlr_post_static_screen,
		mmi_wap_push_setting_entry_wl_add_new_menu,
		mmi_wap_push_scrhdlr_exit_static_screen,
		NULL,
		mmi_wap_push_scrhdlr_rsk_static_screen,
		NULL,
		mmi_wap_push_scrhdlr_delete_static_screen
	},
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
#ifndef __MMI_WAP_PUSH_ADVANCED_FEATURE_SLIM__
    {   
        SCR_ID_BRW_SEND_BY_OPTIONS,
		NULL,
        NULL,
		MENU_ID_PUSH_SERVICE_MSG_SEND_BY,
        mmi_wap_push_scrhdlr_create_static_screen,
        mmi_wap_push_scrhdlr_pre_static_screen,
        mmi_wap_push_scrhdlr_draw_static_screen,
        mmi_wap_push_scrhdlr_post_static_screen,
		mmi_wap_push_entry_send_by_opt_menu,
		mmi_wap_push_scrhdlr_exit_static_screen,
		NULL,
		mmi_wap_push_scrhdlr_rsk_static_screen,
		NULL,
		mmi_wap_push_scrhdlr_delete_static_screen
	},
#endif
    {   
        SCR_ID_BRW_READ_SERVICE_MESSAGE_OPTIONS,
		NULL,
        NULL,
		MENU_ID_PUSH_MSG_OPTION,
        mmi_wap_push_scrhdlr_create_static_screen,
        mmi_wap_push_scrhdlr_pre_static_screen,
        mmi_wap_push_scrhdlr_draw_static_screen,
        mmi_wap_push_scrhdlr_post_static_screen,
		mmi_wap_push_entry_msg_opt_menu,
		mmi_wap_push_scrhdlr_exit_static_screen,
		NULL,
		mmi_wap_push_scrhdlr_rsk_static_screen,
		NULL,
		mmi_wap_push_scrhdlr_delete_static_screen
	},
#if 0
	#if (MMI_MAX_SIM_NUM == 2)
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
    #endif /* __MMI_WAP_DUAL_SIM__ */
#endif /*0*/
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    {   
        SCR_ID_PUSH_UNKNWN_ADDR_OPTIONS,
		NULL,
        NULL,
		MENU_ID_PUSH_UNKNOWN_ADDR_OPTIONS,
        mmi_wap_push_scrhdlr_create_static_screen,
        mmi_wap_push_scrhdlr_pre_static_screen,
        mmi_wap_push_scrhdlr_draw_static_screen,
        mmi_wap_push_scrhdlr_post_nuknwn_addr_opt,
		mmi_wap_push_entry_unknwn_addr_opt_menu,
		mmi_wap_push_scrhdlr_exit_static_screen,
		NULL,
		mmi_wap_push_scrhdlr_rsk_static_screen,
		NULL,
		mmi_wap_push_scrhdlr_delete_static_screen
	},
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
#ifdef __MMI_PUSH_IN_UM__
    {   
        SCR_ID_UM_MESSAGE_OPTIONS,
		NULL,
        NULL,
		MENU_ID_PUSH_INBOX_OPTION,
        mmi_wap_push_scrhdlr_create_static_screen,
        mmi_wap_push_scrhdlr_pre_static_screen,
        mmi_wap_push_scrhdlr_draw_static_screen,
        mmi_wap_push_scrhdlr_post_static_screen,
		mmi_wap_push_entry_um_list_opt_menu,
		mmi_wap_push_scrhdlr_exit_static_screen,
		NULL,
		mmi_wap_push_scrhdlr_rsk_static_screen,
		NULL,
		mmi_wap_push_scrhdlr_delete_static_screen
	},
#endif /* __MMI_PUSH_IN_UM__ */
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
#endif /* 0 */
    /* End of static list screens */
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    {   
        SCR_ID_PUSH_WHITE_LIST_ADD_NEW_PHONE_NUM,
		NULL,
        NULL,
		MENU_ID_PUSH_ADD_NEW_PHONE_NUMBER,
        mmi_wap_push_scrhdlr_create_static_screen,
        mmi_wap_push_scrhdlr_pre_inline_screen_add_new_ph_num,
        mmi_wap_push_scrhdlr_draw_inline_screen,
        mmi_wap_push_scrhdlr_post_static_screen,
		mmi_wap_push_scrhdlr_entry_add_new_ph_num,
		mmi_wap_push_scrhdlr_exit_inline_screen,
		NULL,
		mmi_wap_push_scrhdlr_rsk_inline_screen,
		mmi_wap_push_scrhdlr_hilite_static_screen,
		mmi_wap_push_scrhdlr_delete_static_screen
	},
    {   
        SCR_ID_PUSH_WHITE_LIST_ADD_NEW_IP_ADDR,
		NULL,
        NULL,
		MENU_ID_PUSH_ADD_NEW_IP_ADDR,
        mmi_wap_push_scrhdlr_create_static_screen,
        mmi_wap_push_scrhdlr_pre_inline_screen_add_new_ip,
        mmi_wap_push_scrhdlr_draw_inline_screen,
        mmi_wap_push_scrhdlr_post_static_screen,
		mmi_wap_push_scrhdlr_entry_add_new_ip,
		mmi_wap_push_scrhdlr_exit_inline_screen,
		NULL,
		mmi_wap_push_scrhdlr_rsk_inline_screen,
		mmi_wap_push_scrhdlr_hilite_static_screen,
		mmi_wap_push_scrhdlr_delete_static_screen
	},
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    /* End of inline screens */
    {   
        SCR_ID_PUSH_ENABLE_PUSH,
		NULL,
        NULL,
		MENU_ID_SERVICE_MSG_ENABLE,
        mmi_wap_push_scrhdlr_create_static_screen,
        mmi_wap_push_scrhdlr_pre_selection_screen,
        mmi_wap_push_scrhdlr_draw_selection_screen,
        mmi_wap_push_scrhdlr_post_static_screen,
		mmi_wap_push_scrhdlr_entry_enable_push,
		mmi_wap_push_scrhdlr_exit_static_screen,
		mmi_wap_push_scrhdlr_lsk_selection_screen,
		mmi_wap_push_scrhdlr_rsk_static_screen,
		mmi_wap_push_scrhdlr_hilite_static_screen,
		mmi_wap_push_scrhdlr_delete_static_screen
	},
	#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    {   
        SCR_ID_PUSH_ENABLE_BL_SETTING,
		NULL,
        NULL,
		MENU_ID_PUSH_ENABLE_BLACK_LIST,
        mmi_wap_push_scrhdlr_create_static_screen,
        mmi_wap_push_scrhdlr_pre_selection_screen,
        mmi_wap_push_scrhdlr_draw_selection_screen,
        mmi_wap_push_scrhdlr_post_static_screen,
		mmi_wap_push_scrhdlr_entry_enable_black_list,
		mmi_wap_push_scrhdlr_exit_static_screen,
		mmi_wap_push_scrhdlr_lsk_selection_screen,
		mmi_wap_push_scrhdlr_rsk_static_screen,
		mmi_wap_push_scrhdlr_hilite_static_screen,
		mmi_wap_push_scrhdlr_delete_static_screen
	},
	#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    {   
        SCR_ID_PUSH_ENABLE_WL_SETTING,
		NULL,
        NULL,
		MENU_ID_PUSH_ENABLE_WHITE_LIST,
        mmi_wap_push_scrhdlr_create_static_screen,
        mmi_wap_push_scrhdlr_pre_selection_screen,
        mmi_wap_push_scrhdlr_draw_selection_screen,
        mmi_wap_push_scrhdlr_post_static_screen,
		mmi_wap_push_scrhdlr_entry_enable_white_list,
		mmi_wap_push_scrhdlr_exit_static_screen,
		mmi_wap_push_scrhdlr_lsk_selection_screen,
		mmi_wap_push_scrhdlr_rsk_static_screen,
		mmi_wap_push_scrhdlr_hilite_static_screen,
		mmi_wap_push_scrhdlr_delete_static_screen
	},
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    {   
        SCR_ID_PUSH_SL_SETTING,
		NULL,
        NULL,
		MENU_ID_SERVICE_MSG_SL_SETTING,
        mmi_wap_push_scrhdlr_create_static_screen,
        mmi_wap_push_scrhdlr_pre_selection_screen,
        mmi_wap_push_scrhdlr_draw_selection_screen,
        mmi_wap_push_scrhdlr_post_static_screen,
		mmi_wap_push_scrhdlr_entry_enable_sl_set,
		mmi_wap_push_scrhdlr_exit_static_screen,
		mmi_wap_push_scrhdlr_lsk_selection_screen,
		mmi_wap_push_scrhdlr_rsk_static_screen,
		mmi_wap_push_scrhdlr_hilite_static_screen,
		mmi_wap_push_scrhdlr_delete_static_screen
	},
    /* End of selection screens */
    {   
        SCR_ID_BRW_READ_SERVICE_MESSAGE,
		NULL,
        NULL,
		0,
        mmi_wap_push_scrhdlr_create_static_screen,
        mmi_wap_push_scrhdlr_pre_selected_message_screen,
        mmi_wap_push_scrhdlr_draw_message_screen,
        mmi_wap_push_scrhdlr_post_static_screen,
		mmi_wap_push_scrhdlr_entry_message_display,
		mmi_wap_push_scrhdlr_exit_static_screen,
		mmi_wap_push_scrhdlr_lsk_selected_message_screen,
		mmi_wap_push_scrhdlr_rsk_selected_message_screen,
		NULL,
		mmi_wap_push_scrhdlr_delete_static_screen
	},
#ifndef __MMI_WAP_PUSH_SIA_SLIM__
    {   
        SCR_ID_PUSH_DISPALY_SIA_CNF,
		NULL,
        NULL,
		0,
        mmi_wap_push_scrhdlr_create_static_screen,
        mmi_wap_push_scrhdlr_pre_selected_message_screen,
        mmi_wap_push_scrhdlr_draw_message_screen,
        mmi_wap_push_scrhdlr_post_sia_dlg_screen,
		mmi_wap_push_scrhdlr_entry_sia_dlg_display,
		mmi_wap_push_scrhdlr_exit_static_screen,
		mmi_wap_push_scrhdlr_lsk_sia_dlg_screen,
		mmi_wap_push_scrhdlr_rsk_sia_dlg_screen,
		NULL,
		mmi_wap_push_scrhdlr_delete_static_screen
	},

    /* End of message screens */
#endif
    {   
        SCR_ID_BRW_NEW_PUSH_MESSAGE_IND,
		NULL,
        NULL,
		0,
        mmi_wap_push_scrhdlr_create_static_screen,
        mmi_wap_push_scrhdlr_pre_notification_screen,
        mmi_wap_push_scrhdlr_draw_notification_screen,
        mmi_wap_push_scrhdlr_post_notification_screen,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		mmi_wap_push_scrhdlr_delete_static_screen
	},
    {   
        SCR_ID_BRW_PUSH_MSG_DELETED,
		NULL,
        NULL,
		0,
        mmi_wap_push_scrhdlr_create_static_screen,
        mmi_wap_push_scrhdlr_pre_small_screen,
        mmi_wap_push_scrhdlr_draw_small_screen,
        NULL,
		mmi_wap_push_scrhdlr_entry_msg_deleted_screen,
		NULL,
		mmi_push_close_active_screen,
		NULL,
		NULL,
		mmi_wap_push_scrhdlr_delete_static_screen
	},
    /* End of notification screens */

    {   
        SCR_ID_PUSH_GENERIC_PROCESSING,
		NULL,
        NULL,
		0,
        mmi_wap_push_scrhdlr_create_static_screen,
        mmi_wap_push_scrhdlr_pre_progress_screen,
        mmi_wap_push_scrhdlr_draw_progress_screen,
        mmi_wap_push_scrhdlr_post_progress_screen,
		mmi_wap_push_scrhdlr_entry_generic_processing_ex,
		NULL,
		NULL,
		NULL,
		NULL,
		mmi_wap_push_scrhdlr_delete_static_screen
	},
    {
        SCR_ID_PUSH_POPUP_SCREEN,
		NULL,
        NULL,
		0,
        mmi_wap_push_scrhdlr_create_static_screen,
        mmi_wap_push_scrhdlr_pre_progress_screen,
        mmi_wap_push_scrhdlr_draw_progress_screen,
        mmi_wap_push_scrhdlr_post_progress_screen,
		NULL,
		mmi_wap_push_exit_new_msg_popup,
		NULL,
		NULL,
		NULL,
		mmi_wap_push_scrhdlr_delete_static_screen
	},
    {
        SCR_ID_PUSH_PROCESSING,
		NULL,
        NULL,
		0,
        mmi_wap_push_scrhdlr_create_static_screen,
        mmi_wap_push_scrhdlr_pre_progress_screen,
        mmi_wap_push_scrhdlr_draw_progress_screen,
        mmi_wap_push_scrhdlr_post_progress_screen,
		mmi_wap_push_scrhdlr_entry_inbox_processing,
		NULL,
		NULL,
		NULL,
		NULL,
		mmi_wap_push_scrhdlr_delete_static_screen
	},
    {
        SCR_ID_PUSH_ASYNC_PROCESSING,
		NULL,
        NULL,
		0,
        mmi_wap_push_scrhdlr_create_static_screen,
        mmi_wap_push_scrhdlr_pre_progress_screen,
        mmi_wap_push_scrhdlr_draw_progress_screen,
        mmi_wap_push_scrhdlr_post_progress_screen,
		mmi_wap_push_scrhdlr_entry_async_processing,
		NULL,
		NULL,
		NULL,
		NULL,
		mmi_wap_push_scrhdlr_delete_static_screen
	},
    /* End of processing screens */


    /* Please add New entry above this line */
    {0, NULL, NULL, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}
};



mmi_wap_push_resourceDB_struct g_push_resourceDB[] =
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    {   
        SCR_ID_PUSH_WHITE_LIST,
        MENU_ID_PUSH_WHITE_LIST,
        STR_ID_PUSH_WHITE_LIST,
        IMG_BRW_PUSH_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK, 
        STR_GLOBAL_BACK, 
        IMG_GLOBAL_BACK,
        0
	},
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    {   
        SCR_ID_PUSH_BLACK_LIST,
        MENU_ID_PUSH_BLACK_LIST,
        STR_ID_PUSH_BLACK_LIST,
        IMG_BRW_PUSH_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK, 
        STR_GLOBAL_BACK, 
        IMG_GLOBAL_BACK,
        0
	},
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
    /* End of synchronous dynamic screens */

    {   
        SCR_ID_PUSH_INBOX,
        0,
        STR_ID_PUSH_INBOX,
        IMG_BRW_PUSH_CAPTION,
        STR_GLOBAL_READ,
        IMG_GLOBAL_OK, 
        STR_GLOBAL_BACK, 
        IMG_GLOBAL_BACK,
        0
	},
    /* End of Asynchronous dynamic screens */

	{
		SCR_ID_PUSH_SETTING,
        MENU_ID_SERVICE_MSG_SETTING,
        STR_ID_PUSH_SERVICE_MESSAG,
        IMG_BRW_PUSH_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK, 
        STR_GLOBAL_BACK, 
        IMG_GLOBAL_BACK,
        0
    },
#ifdef __MMI_PUSH_IN_MSG__
    {   
        SCR_ID_PUSH_ENTRY_SERVICE_MSG,
        MENU_ID_SERVICE_MESSAGE,
        STR_ID_PUSH_SERVICE_MESSAGE,
        IMG_BRW_PUSH_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK, 
        STR_GLOBAL_BACK, 
        IMG_GLOBAL_BACK,
        0
	},
#endif /* __MMI_PUSH_IN_MSG__ */
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    {   
        SCR_ID_PUSH_WHITE_LIST_OPTIONS,
        MENU_ID_PUSH_ADDR_LIST_OPTIONS,
        STR_GLOBAL_OPTIONS,
        IMG_BRW_PUSH_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK, 
        STR_GLOBAL_BACK, 
        IMG_GLOBAL_BACK,
        0
	},
    {   
        SCR_ID_PUSH_WHITE_LIST_ADD_NEW,
        MENU_ID_PUSH_ADD_NEW,
        STR_ID_PUSH_INBOX_ADD_NEW,
        IMG_BRW_PUSH_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK, 
        STR_GLOBAL_BACK, 
        IMG_GLOBAL_BACK,
        0
	},
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
#ifndef __MMI_WAP_PUSH_ADVANCED_FEATURE_SLIM__
    {   
        SCR_ID_BRW_SEND_BY_OPTIONS,
        MENU_ID_PUSH_SERVICE_MSG_SEND_BY,
        STR_GLOBAL_SEND,
        IMG_BRW_PUSH_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK, 
        STR_GLOBAL_BACK, 
        IMG_GLOBAL_BACK,
        0
	},
#endif
    {   
        SCR_ID_BRW_READ_SERVICE_MESSAGE_OPTIONS,
        MENU_ID_PUSH_MSG_OPTION,
        STR_GLOBAL_OPTIONS,
        IMG_BRW_PUSH_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK, 
        STR_GLOBAL_BACK, 
        IMG_GLOBAL_BACK,
        0
	},
#if 0
#if (MMI_MAX_SIM_NUM == 2)
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
#endif /* __MMI_WAP_DUAL_SIM__ */
#endif /* 0 */
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    {   
        SCR_ID_PUSH_UNKNWN_ADDR_OPTIONS,
        MENU_ID_PUSH_UNKNOWN_ADDR_OPTIONS,
        STR_GLOBAL_OPTIONS,
        IMG_BRW_PUSH_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK, 
        STR_GLOBAL_BACK, 
        IMG_GLOBAL_BACK,
        0
	},
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
#ifdef __MMI_PUSH_IN_UM__
    {   
        SCR_ID_UM_MESSAGE_OPTIONS,
        MENU_ID_PUSH_INBOX_OPTION,
        STR_GLOBAL_OPTIONS,
        IMG_BRW_PUSH_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK, 
        STR_GLOBAL_BACK, 
        IMG_GLOBAL_BACK,
        0
	},
#endif /* __MMI_PUSH_IN_UM__ */
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
#endif /* 0 */
    /* End of static list screens */
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    {   
        SCR_ID_PUSH_WHITE_LIST_ADD_NEW_PHONE_NUM,
        MENU_ID_PUSH_ADD_NEW_PHONE_NUMBER,
        STR_ID_PUSH_INBOX_TRUST_LIST_PHONE_NUMBER,
        IMG_BRW_PUSH_CAPTION,
        0,
        0, 
        STR_GLOBAL_BACK, 
        IMG_GLOBAL_BACK,
        0
	},
    {   
        SCR_ID_PUSH_WHITE_LIST_ADD_NEW_IP_ADDR,
        MENU_ID_PUSH_ADD_NEW_IP_ADDR,
        STR_ID_PUSH_INBOX_TRUST_LIST_IP_ADDRESS,
        IMG_BRW_PUSH_CAPTION,
        0,
        0, 
        STR_GLOBAL_BACK, 
        IMG_GLOBAL_BACK,
        0
	},
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
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
#endif
    /* End of inline screens */

    {   
        SCR_ID_PUSH_ENABLE_PUSH,
        MENU_ID_SERVICE_MSG_ENABLE,
        STR_ID_PUSH_INBOX_ENABLE_PUSH,
        IMG_BRW_PUSH_CAPTION,
        STR_GLOBAL_SELECT,
        0,
        STR_GLOBAL_BACK, 
        IMG_GLOBAL_BACK,
        0
	},
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    {   
        SCR_ID_PUSH_ENABLE_BL_SETTING,
        MENU_ID_PUSH_ENABLE_BLACK_LIST,
        STR_ID_PUSH_ENABLE_BLACK_LIST,
        IMG_BRW_PUSH_CAPTION,
        STR_GLOBAL_SELECT,
        0,
        STR_GLOBAL_BACK, 
        IMG_GLOBAL_BACK,
        0
	},
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    {   
        SCR_ID_PUSH_ENABLE_WL_SETTING,
        MENU_ID_PUSH_ENABLE_WHITE_LIST,
        STR_ID_PUSH_ENABLE_WHITE_LIST,
        IMG_BRW_PUSH_CAPTION,
        STR_GLOBAL_SELECT,
        0, 
        STR_GLOBAL_BACK, 
        IMG_GLOBAL_BACK,
        0
	},
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    {   
        SCR_ID_PUSH_SL_SETTING,
        MENU_ID_SERVICE_MSG_SL_SETTING,
        STR_ID_PUSH_ENABLE_SERVICE_LOADING,
        IMG_BRW_PUSH_CAPTION,
        STR_GLOBAL_SELECT,
        0, 
        STR_GLOBAL_BACK, 
        IMG_GLOBAL_BACK,
        0
	},
    /* End of selection screens */

    {   
        SCR_ID_BRW_READ_SERVICE_MESSAGE,
        0,
        0,
        IMG_BRW_PUSH_CAPTION,
        0,
        0,
        0, 
        0,
        0
	},
#ifndef __MMI_WAP_PUSH_SIA_SLIM__
    {   
        SCR_ID_PUSH_DISPALY_SIA_CNF,
        0,
        0,
        IMG_BRW_PUSH_CAPTION,
        0,
        0,
        0, 
        0,
        0
	},
#endif
    /* End of message screens */

    {   
        SCR_ID_BRW_NEW_PUSH_MESSAGE_IND,
        0,
        0,
        IMG_BRW_PUSH_CAPTION,
        0,
        0, 
        0, 
        0,
        0
	},
    {   
        SCR_ID_BRW_PUSH_MSG_DELETED,
        0,
        STR_ID_PUSH_INBOX,
        IMG_BRW_PUSH_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK, 
        0, 
        0,
        0
	},
    /* End of notification screens */

    {SCR_ID_PUSH_GENERIC_PROCESSING, 0, 0, 0, 0, 0, 0, 0, 0},
    {SCR_ID_PUSH_POPUP_SCREEN, 0, 0, 0, 0, 0, 0, 0, 0},
    {SCR_ID_PUSH_PROCESSING, 0, 0, 0, 0, 0, 0, 0, 0},
    {SCR_ID_PUSH_ASYNC_PROCESSING, 0, 0, 0, 0, 0, 0, 0, 0},
    /* End of processing screens */

    /* Please add New entry above this line */
    {0, 0, 0, 0, 0, 0, 0 }
};



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_get_screenDB_for_menu_id
 * DESCRIPTION
 * 
 * PARAMETERS
 *  menu_id      [IN]
 * RETURNS
 *  Screen database pointer.
 *****************************************************************************/
mmi_wap_push_screenDB_struct* mmi_wap_push_scrhdlr_get_screenDB_for_menu_id (U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 incr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while (g_screenDB[incr].scrn_id != 0)
	{
		if(g_screenDB[incr].parent_menu_id == menu_id)
		{
			return &g_screenDB[incr];
		}
        incr++;
	}
	return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_get_screenDB_for_screen_id
 * DESCRIPTION
 * 
 * PARAMETERS
 *  menu_id      [IN]
 * RETURNS
 *  Screen database pointer.
 *****************************************************************************/
mmi_wap_push_screenDB_struct* mmi_wap_push_scrhdlr_get_screenDB_for_screen_id (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 incr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while (g_screenDB[incr].scrn_id != 0)
	{
		if(g_screenDB[incr].scrn_id == screen_id)
		{
			return &g_screenDB[incr];
		}
        incr++;
	}
	return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_set_scrhdlr_DB_id
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [U16]
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_set_scrhdlr_DB_id (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 incr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_screenDB[incr].scrn_id != 0)
    {
        if (g_screenDB[incr].scrn_id == screen_id)
        {
            g_push_scrhdlr_index = incr;
            return;
        }
        incr++;
    }
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_get_screenDB_for_menu_id
 * DESCRIPTION
 * 
 * PARAMETERS
 *  menu_id      [IN]
 * RETURNS
 *  Screen database pointer.
 *****************************************************************************/
mmi_wap_push_resourceDB_struct* mmi_wap_push_scrhdlr_get_resourceDB_for_menu_id (U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 incr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while (g_push_resourceDB[incr].scrn_id != 0)
	{
		if(g_push_resourceDB[incr].menu_item_id == menu_id)
		{
			return &g_push_resourceDB[incr];
		}
        incr++;
	}
	return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_screenDB
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  screen DB pointer.
 *****************************************************************************/
mmi_wap_push_resourceDB_struct* mmi_wap_push_rc_get_resourceDB (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &(g_push_resourceDB[g_push_rc_index]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_screenDB
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  screen DB pointer.
 *****************************************************************************/
mmi_wap_push_screenDB_struct* mmi_wap_push_scrhdlr_get_screenDB (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &(g_screenDB[g_push_scrhdlr_index]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_set_rc_DB_id
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [U16]
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_set_rc_DB_id (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 incr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_push_resourceDB[incr].scrn_id != 0)
    {
        if (g_push_resourceDB[incr].scrn_id == screen_id)
        {
            g_push_rc_index = incr;
            return;
        }
        incr++;
    }
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_if_init
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  void.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_if_init (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wap_push_screenDB_struct *scrDB = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_wap_push_scrhdlr_get_screenDB();
    if (scrDB->create_func != NULL)
    {
        scrDB->create_func(screen_id);
    }
    if (scrDB->pre_func != NULL)
    {
        scrDB->pre_func(screen_id);
    }
    if (scrDB->draw_func != NULL)
    {
        scrDB->draw_func(screen_id);
    }
    if (scrDB->post_func != NULL)
    {
        scrDB->post_func(screen_id);
    }
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_dummy_history_func
 * DESCRIPTION
 * 
 * PARAMETERS
 *  arg      [void]
 * RETURNS
 *  TRUE.
 *****************************************************************************/
void mmi_wap_push_scrhdlr_dummy_history_func(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_setting_create_screen_main_menu
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [U16]
 * RETURNS
 *  TRUE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_create_static_screen (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wap_push_screenDB_struct *scrDB = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_wap_push_scrhdlr_get_screenDB();
    scrDB->rcDB = mmi_wap_push_rc_get_resourceDB();
    //mmi_frm_scrn_first_enter (g_push_cntxt->scr_grp_id, screen_id, mmi_wap_push_scrhdlr_dummy_history_func, (void *)scrDB);
    //mmi_frm_scrn_set_user_data(g_push_cntxt->scr_grp_id, screen_id, (void *)scrDB);
	///mmi_frm_create_new_screen(mmi_wap_push_scrhdlr_dummy_history_func, (void *)scrDB);
	return MMI_TRUE;
}





/**********************************************************************************************************/
/*                                       Start CODE FOR static screen                                     */
/**********************************************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_static_scr_num_of_item
 * DESCRIPTION
 * 
 * PARAMETERS
 *  menu_id      [U16]
 * RETURNS
 *  TRUE if first entry otherwise FALSE.
 *****************************************************************************/
S32 mmi_wap_push_get_static_scr_num_of_item (U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return (S32)GetNumOfChild_Ext(menu_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_static_scr_list_of_item
 * DESCRIPTION
 * 
 * PARAMETERS
 *  menu_id      [U16]
 * RETURNS
 *  List of items.
 *****************************************************************************/
U16* mmi_wap_push_get_static_scr_list_of_item(U16 menu_id, U16 *item_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetSequenceStringIds_Ext(menu_id, item_list);
    return item_list;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_static_scr_list_of_icon
 * DESCRIPTION
 * 
 * PARAMETERS
 *  menu_id      [U16]
 * RETURNS
 *  List of icons.
 *****************************************************************************/
U16* mmi_wap_push_get_static_scr_list_of_icon(U16 menu_id, U16 *icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    icon = (U16*) gIndexIconsImageList;
	return icon;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_static_scr_list_of_description
 * DESCRIPTION
 * 
 * PARAMETERS
 *  menu_id      [U16]
 * RETURNS
 *  List of hints.
 *****************************************************************************/
U8** mmi_wap_push_get_static_scr_list_of_description (U16 menu_id,U8 **popUpList)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menu_id == 0)
    {
        return NULL;
    }
    ConstructHintsList(menu_id, popUpList);
    return popUpList;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_set_hide_handler
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 *  hide_hdlr      [IN]
 * RETURNS
 *  TRUE if first entry otherwise FALSE.
 *****************************************************************************/
void mmi_wap_push_set_hide_handler (U16 screen_id, hide_hdlr_func_ptr *hide_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (screen_id)
    {
#ifndef __MMI_WAP_PUSH_ADVANCED_FEATURE_SLIM__
    case SCR_ID_BRW_SEND_BY_OPTIONS:

         *hide_hdlr = mmi_wap_push_hide_handler_send_by;
        break;
#endif
    case SCR_ID_BRW_READ_SERVICE_MESSAGE_OPTIONS:
         *hide_hdlr = mmi_wap_push_hide_handler_message_option;
        break;
    case SCR_ID_PUSH_UNKNWN_ADDR_OPTIONS:
         *hide_hdlr = mmi_wap_push_hide_handler_unknwn_addr;
        break;
    case SCR_ID_BRW_PUSH_CONNECT_SIM_OPTIONS:
        // *hide_hdlr = mmi_wap_push_hide_handler_connect_sim;
        break;
    default:
        *hide_hdlr = NULL;
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_set_highlighter_func
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 *  hide_hdlr      [IN]
 * RETURNS
 *  TRUE if first entry otherwise FALSE.
 *****************************************************************************/
void mmi_wap_push_set_leaf_node_handler (U16 screen_id, leaf_node_func *leaf_node_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (screen_id)
    {
    case SCR_ID_PUSH_SETTING:
         *leaf_node_func = mmi_wap_push_scrhdlr_lsk_setting_menu;
        break;
    case SCR_ID_PUSH_WHITE_LIST_OPTIONS:
         *leaf_node_func = mmi_wap_push_scrhdlr_lsk_wl_options_menu;
        break;
    case SCR_ID_PUSH_WHITE_LIST_ADD_NEW:
         *leaf_node_func = mmi_wap_push_scrhdlr_lsk_add_new_options_menu;
        break;
    case SCR_ID_BRW_READ_SERVICE_MESSAGE_OPTIONS:
         *leaf_node_func = mmi_wap_push_scrhdlr_lsk_msg_option_menu;
        break;
    case SCR_ID_BRW_PUSH_CONNECT_SIM_OPTIONS:
         // *leaf_node_func = mmi_wap_push_scrhdlr_lsk_connect_sim_menu;
        break;
    case SCR_ID_PUSH_UNKNWN_ADDR_OPTIONS:
         *leaf_node_func = mmi_wap_push_scrhdlr_lsk_unknwn_addr_opt_menu;
        break;
    case SCR_ID_PUSH_ENTRY_SERVICE_MSG:
         *leaf_node_func = mmi_wap_push_scrhdlr_lsk_service_msg_main_menu;
        break;
    default:
        *leaf_node_func = NULL;
    }
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*0*/
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_pre_static_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [U16]
 * RETURNS
 *  TRUE if first entry otherwise FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_pre_static_screen (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wap_push_screenDB_struct *scrDB = NULL;
    mmi_wap_push_scrhdlr_static_screen_struct  **screen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_wap_push_scrhdlr_get_screenDB();
	
	if(scrDB->screen == NULL)
	{
        screen = (mmi_wap_push_scrhdlr_static_screen_struct**) (&(scrDB->screen));
		*screen = (mmi_wap_push_scrhdlr_static_screen_struct*)OslMalloc (sizeof (mmi_wap_push_scrhdlr_static_screen_struct));
        memset(*screen, 0, (sizeof (mmi_wap_push_scrhdlr_static_screen_struct)));

        (*screen)->scrn_id = screen_id;
        (*screen)->hilighted_item = 0;

        (*screen)->number_of_items = mmi_wap_push_get_static_scr_num_of_item;
		(*screen)->list_of_items = mmi_wap_push_get_static_scr_list_of_item;
		(*screen)->list_of_icons = mmi_wap_push_get_static_scr_list_of_icon;
		(*screen)->list_of_descriptions = mmi_wap_push_get_static_scr_list_of_description;
        mmi_wap_push_set_hide_handler(screen_id, &((*screen)->hide_handler)); 
		((*screen)->highlighter_func)= NULL;
     //   mmi_wap_push_set_highlighter_func(screen_id, &((*screen)->highlighter_func)); 
        mmi_wap_push_set_leaf_node_handler(screen_id, &((*screen)->leaf_node_hdlr));

		return MMI_TRUE;
	}
    return MMI_FALSE;
}

#if 0
#ifdef __MMI_PUSH_IN_UM__
#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
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
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */
#endif /* __MMI_PUSH_IN_UM__ */
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
#ifdef __MMI_PUSH_IN_UM__
#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
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
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */
#endif /* __MMI_PUSH_IN_UM__ */
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
#ifdef __MMI_PUSH_IN_UM__
#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
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
/* under construction !*/
/* under construction !*/
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */
#endif /* __MMI_PUSH_IN_UM__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*0*/
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_hilite_static_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  index      [IN]
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_scrhdlr_hilite_static_screen (S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wap_push_screenDB_struct *scrDB = NULL;
    mmi_wap_push_scrhdlr_static_screen_struct  **screen;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//scrDB = mmi_frm_get_current_screen_argument();
    scrDB = mmi_frm_scrn_get_user_data (g_push_cntxt->scr_grp_id, mmi_frm_scrn_get_active_id());
    screen = (mmi_wap_push_scrhdlr_static_screen_struct**) (&(scrDB->screen));
	(*screen)->hilighted_item = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_post_static_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  MMI_TRUE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_post_static_screen (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_post_nuknwn_addr_opt
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  MMI_TRUE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_post_nuknwn_addr_opt (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetKeyDownHandler(mmi_wap_push_end_key_sia_dlg_screen, KEY_END);
    return MMI_TRUE;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_default_hilite_hdlr_action
 * DESCRIPTION
 * 
 * PARAMETERS
 *  hilited_menu    [IN]
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_scrhdlr_default_hilite_hdlr_action (U16 hilited_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * It's a dummy function. This function will be executed only in case 
     * when there is not highlight handler for a given menu item.
     */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_lsk_static_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void.
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_scrhdlr_lsk_static_screen (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 hilite_menu = 0;
    mmi_wap_push_screenDB_struct *scrDB = NULL;
    mmi_wap_push_scrhdlr_static_screen_struct  **screen;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//scrDB = mmi_frm_get_current_screen_argument();
    scrDB = mmi_frm_scrn_get_user_data (g_push_cntxt->scr_grp_id, mmi_frm_scrn_get_active_id());
    screen = (mmi_wap_push_scrhdlr_static_screen_struct**) (&(scrDB->screen));

	hilite_menu = GetSeqItemId_Ext((U16)scrDB->rcDB->menu_item_id, (*screen)->hilighted_item);

    scrDB = mmi_wap_push_scrhdlr_get_screenDB_for_menu_id(hilite_menu);

	if(scrDB != NULL)
	{
		scrDB->EntryFunction();
	}
	else
	{
        mmi_wap_push_scrhdlr_default_hilite_hdlr_action (hilite_menu);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_exit_static_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void.
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_scrhdlr_exit_static_screen (void)
{
#ifdef __MMI_PUSH_IN_UM__
#ifdef __MMI_UM_ITERATOR_VIEWER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wap_push_screenDB_struct *scrDB = NULL;
    mmi_wap_push_scrhdlr_message_screen_struct *screen = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * This Api assume "message screen and unknown message screen are mutually exclusive in MMI.
     * And for unknown message lnk_func and rnk_func function pointers are set as NULL.
     * To remove this assumption we can write a seprate exit screen handler for message screen.
     */
    scrDB = mmi_wap_push_scrhdlr_get_screenDB_for_screen_id(SCR_ID_BRW_READ_SERVICE_MESSAGE);
    screen = scrDB->screen;
    if ((screen != NULL) && (screen->lnk_func != NULL) && (screen->rnk_func != NULL))
    {
    #if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) 
        mmi_frm_gesture_stop_listen_event();
    #endif
    }
#endif /* __MMI_UM_ITERATOR_VIEWER__ */
#endif /* __MMI_PUSH_IN_UM__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_rsk_static_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void.
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_scrhdlr_rsk_static_screen (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_delete_static_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  dummy        [IN]
 * RETURNS
 *  0.
 *****************************************************************************/
mmi_ret mmi_wap_push_scrhdlr_delete_static_screen (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wap_push_screenDB_struct *scrDB = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   scrDB = (mmi_wap_push_screenDB_struct *)evt->user_data;
   switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT :
            if (scrDB && (NULL != scrDB->screen))
            {
                OslMfree(scrDB->screen);
            }
            scrDB->screen = NULL;
            break;

    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_draw_static_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_draw_static_screen (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    mmi_wap_push_screenDB_struct *scrDB = NULL;
    mmi_wap_push_resourceDB_struct *resourceDB = NULL;
    mmi_wap_push_scrhdlr_static_screen_struct  *static_screen = NULL;
//    mmi_id menu_gid;
    mmi_group_node_struct node_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_wap_push_scrhdlr_get_screenDB();
    static_screen = scrDB->screen;
    resourceDB = scrDB->rcDB;

    if (mmi_frm_group_get_info (g_push_cntxt->scr_grp_id,&node_info) == MMI_RET_OK)
    {
        mmi_frm_group_set_proc_data (g_push_cntxt->scr_grp_id, node_info.proc, (void *)scrDB);
    }
    else
        ASSERT(0);

    MMI_ASSERT (static_screen->leaf_node_hdlr);
	menu_id_new = cui_menu_create(g_push_cntxt->scr_grp_id,
								CUI_MENU_SRC_TYPE_RESOURCE,
								CUI_MENU_TYPE_FROM_RESOURCE,
								scrDB->parent_menu_id,
								MMI_TRUE, NULL);

   /* 
    cui_menu_set_default_title(menu_gid, 
        (UI_string_type) GetString(resourceDB->title_str_id), 
        (UI_image_type) GetImage(mmi_wap_push_get_title_icon(resourceDB->title_icon_id)));
        */
    cui_menu_set_default_title_image(menu_id_new, (UI_image_type) GetImage(mmi_wap_push_get_title_icon(resourceDB->title_icon_id)));

    cui_menu_run(menu_id_new);
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_draw_static_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_draw_static_screen_app_sub_menu (U16 screen_id)/*option screen*/
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    mmi_wap_push_screenDB_struct *scrDB = NULL;
    
    mmi_wap_push_scrhdlr_static_screen_struct  *static_screen = NULL;
    mmi_id menu_gid;
    mmi_group_node_struct node_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_wap_push_scrhdlr_get_screenDB();
    static_screen = scrDB->screen;

    if (mmi_frm_group_get_info (g_push_cntxt->scr_grp_id,&node_info) == MMI_RET_OK)
    {
        mmi_frm_group_set_proc_data (g_push_cntxt->scr_grp_id, node_info.proc, (void *)scrDB);
    }
    else
    {
        ASSERT(0);
    }

    MMI_ASSERT (static_screen->leaf_node_hdlr);
	menu_gid = cui_menu_create_and_run(g_push_cntxt->scr_grp_id,
								CUI_MENU_SRC_TYPE_RESOURCE,
								CUI_MENU_TYPE_FROM_RESOURCE,
								scrDB->parent_menu_id,
								MMI_TRUE, NULL);
	//cui_menu_enable_cascading_option_menu(menu_gid);
  //  cui_menu_run(menu_gid);
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_draw_static_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_draw_static_screen_option (U16 screen_id)/*option screen*/
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer = NULL;
    PU8 popUpList[MAX_SUB_MENUS];
    U16 str_item_list[MAX_SUB_MENUS];
    U16 *img_list = NULL;
    S32 highlighted_index = 0;

    mmi_wap_push_screenDB_struct *scrDB = NULL;
    mmi_wap_push_resourceDB_struct *resourceDB = NULL;
    mmi_wap_push_scrhdlr_static_screen_struct  *static_screen = NULL;
    mmi_id menu_gid;
    mmi_group_node_struct node_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_wap_push_scrhdlr_get_screenDB();
    static_screen = scrDB->screen;

    if (mmi_frm_group_get_info (g_push_cntxt->scr_grp_id,&node_info) == MMI_RET_OK)
    {
        mmi_frm_group_set_proc_data (g_push_cntxt->scr_grp_id, node_info.proc, (void *)scrDB);
    }
    else
    {
        ASSERT(0);
    }


    MMI_ASSERT (static_screen->leaf_node_hdlr);
	menu_gid = cui_menu_create_and_run(g_push_cntxt->scr_grp_id,
								CUI_MENU_SRC_TYPE_RESOURCE,
								CUI_MENU_TYPE_FROM_RESOURCE,
								scrDB->parent_menu_id,
								MMI_TRUE, NULL);
	//cui_menu_enable_cascading_option_menu(menu_gid);
    //cui_menu_run(menu_gid);
    return MMI_TRUE;
}
/**********************************************************************************************************/
/*                                       End CODE FOR static screen                                     */
/**********************************************************************************************************/


/**********************************************************************************************************/
/*                                       Start CODE FOR Selection screen                                  */
/**********************************************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_lsk_selection_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_scrhdlr_lsk_selection_screen (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
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


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_sel_scr_num_of_item
 * DESCRIPTION
 * 
 * PARAMETERS
 *  menu_id      [IN]
 * RETURNS
 *  number of items.
 *****************************************************************************/
U32 mmi_wap_push_get_sel_scr_num_of_item (U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U32)GetNumOfChild_Ext(menu_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_sel_scr_list_of_item
 * DESCRIPTION
 * 
 * PARAMETERS
 *  menu_id      [IN]
 * RETURNS
 *  string array.
 *****************************************************************************/
U8** mmi_wap_push_get_sel_scr_list_of_item (U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS] = {0};
    U16 count = 0;
    U16 num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetSequenceStringIds_Ext(menu_id, nStrItemList);
    num = GetNumOfChild_Ext(menu_id);

    for (count = 0; count < num; count++)
    {
        memset((S8*) subMenuDataPtrs[count], 0, MAX_SUB_MENU_SIZE);
        mmi_ucs2ncpy((S8*) subMenuDataPtrs[count], (S8*) GetString(nStrItemList[count]), MAX_SUBMENU_CHARACTERS);
    }
    return subMenuDataPtrs;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_sel_scr_hilited_index
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  index.
 *****************************************************************************/
U16 mmi_wap_push_get_sel_scr_hilited_index (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_wap_push_get_hilited_index (screen_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_pre_selection_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_pre_selection_screen (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wap_push_screenDB_struct *scrDB = NULL;
    mmi_wap_push_scrhdlr_selection_screen_struct  **screen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_wap_push_scrhdlr_get_screenDB();
	
	if(scrDB->screen == NULL)
	{
        screen = (mmi_wap_push_scrhdlr_selection_screen_struct**) (&(scrDB->screen));
		*screen = (mmi_wap_push_scrhdlr_selection_screen_struct*)OslMalloc (sizeof (mmi_wap_push_scrhdlr_selection_screen_struct));
        memset(*screen, 0, (sizeof (mmi_wap_push_scrhdlr_selection_screen_struct)));

        (*screen)->scrn_id = screen_id;
        (*screen)->hilighted_item = 0;

        (*screen)->number_of_items = mmi_wap_push_get_sel_scr_num_of_item;
		(*screen)->list_of_items = mmi_wap_push_get_sel_scr_list_of_item;
		(*screen)->higlighted_index = mmi_wap_push_get_sel_scr_hilited_index;
        (*screen)->hide_handler = NULL;

		return MMI_TRUE;
	}
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_draw_selection_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_draw_selection_screen (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer = NULL;

    mmi_wap_push_screenDB_struct *scrDB = NULL;
    mmi_wap_push_resourceDB_struct *resourceDB = NULL;
    mmi_wap_push_scrhdlr_selection_screen_struct  *sel_screen = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_wap_push_scrhdlr_get_screenDB();
    resourceDB = scrDB->rcDB;
    sel_screen = scrDB->screen;

    if (mmi_frm_scrn_enter(g_push_cntxt->scr_grp_id, scrDB->scrn_id, scrDB->exit_screen, scrDB->EntryFunction, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return MMI_FALSE;
    }
//    EntryNewScreen(scrDB->scrn_id, scrDB->exit_screen, scrDB->EntryFunction,  NULL);
     mmi_frm_scrn_set_user_data(g_push_cntxt->scr_grp_id, screen_id, (void *)scrDB);

    //gui_buffer = GetCurrGuiBuffer(scrDB->scrn_id);
     gui_buffer = mmi_frm_scrn_get_gui_buf(g_push_cntxt->scr_grp_id, scrDB->scrn_id);
    if (sel_screen->hide_handler != NULL)
    {
        (*(sel_screen->hide_handler)) (gui_buffer);
    }
    SetParentHandler(resourceDB->menu_item_id);
    RegisterHighlightHandler(scrDB->hilite_handler);

	if (scrDB->delete_screen_handler != NULL)
	{
        mmi_frm_scrn_set_leave_proc(g_push_cntxt->scr_grp_id, scrDB->scrn_id, scrDB->delete_screen_handler);
    }
    ShowCategory36Screen(
        resourceDB->title_str_id,
        mmi_wap_push_get_title_icon(resourceDB->title_icon_id),
        resourceDB->lsk_str_id,
        resourceDB->lsk_icon_id,
        resourceDB->rsk_str_id,
        resourceDB->rsk_icon_id,
        sel_screen->number_of_items(resourceDB->menu_item_id),
        sel_screen->list_of_items(resourceDB->menu_item_id),
        sel_screen->higlighted_index(scrDB->scrn_id),
        gui_buffer);

    SetRightSoftkeyFunction(scrDB->rsk_func, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(scrDB->lsk_func, KEY_EVENT_UP);
	return MMI_TRUE;
}


/**********************************************************************************************************/
/*                                       END CODE FOR Selection screen                                    */
/**********************************************************************************************************/









/**********************************************************************************************************/
/*                                       Start CODE FOR Inline screen                                  */
/**********************************************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_lsk_selection_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_scrhdlr_lsk_inline_screen (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_rsk_inline_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_scrhdlr_rsk_inline_screen (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wap_push_screenDB_struct *scrDB = NULL;
    Default_func_ptr rsk_done_hdlr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//scrDB = mmi_frm_get_current_screen_argument();
    scrDB = mmi_frm_scrn_get_user_data (g_push_cntxt->scr_grp_id, mmi_frm_scrn_get_active_id());
    mmi_wap_push_set_inline_screen_done_hdlr (&rsk_done_hdlr, scrDB->scrn_id);
    rsk_done_hdlr();
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
#endif /* 0*/
cui_inline_item_ip4_struct temp_data;
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_pre_inline_screen_add_new_ip
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_pre_inline_screen_add_new_ip (U16 screen_id)
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wap_push_screenDB_struct *scrDB = NULL;
    mmi_wap_push_scrhdlr_inline_screen_struct  **screen;
    U8 proxy_ip[4];

    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_wap_push_scrhdlr_get_screenDB();
	
	if(scrDB->screen == NULL)
	{
        screen = (mmi_wap_push_scrhdlr_inline_screen_struct**) (&(scrDB->screen));
		*screen = (mmi_wap_push_scrhdlr_inline_screen_struct*)OslMalloc (sizeof (mmi_wap_push_scrhdlr_inline_screen_struct));
        memset(*screen, 0, (sizeof (mmi_wap_push_scrhdlr_inline_screen_struct)));

        (*screen)->scrn_id = screen_id;
        (*screen)->hilighted_item = 0;

        g_push_cntxt->inline_gid = cui_inline_create(GRP_ID_BRW_PUSH_INLINE, &g_mmi_brw_push_ip_inline_screen);

         if (srv_wap_push_convert_proxy_ipstring_to_array((U8*) g_push_set_p->ip_addr, proxy_ip) != SRV_WAP_PUSH_ERR)
        {
            temp_data.b1 =  proxy_ip[0];
            temp_data.b2 =  proxy_ip[1];
            temp_data.b3 =  proxy_ip[2];
            temp_data.b4 =  proxy_ip[3];
        }
        else
        {
           temp_data.b1 =  (U8) g_push_set_p->ip_addr[0];
           temp_data.b2 =  (U8) g_push_set_p->ip_addr[1];
           temp_data.b3 =  (U8) g_push_set_p->ip_addr[2];
           temp_data.b4 =  (U8) g_push_set_p->ip_addr[3];
        }


        cui_inline_set_value(g_push_cntxt->inline_gid, MMI_BRW_PUSH_IP_NUM_EDIT, (void *)(&temp_data));

        /*
        (*screen)->number_of_items = mmi_wap_push_get_number_of_inline_scr_item (screen_id);
		(*screen)->image_list_icons = mmi_wap_push_get_add_new_ip_image_icon;
        (*screen)->inline_items = mmi_wap_push_fill_inline_item_for_add_new_ip;
        //mmi_wap_push_add_new_ip_addr_set_buffers();*/
		return MMI_TRUE;
	}
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_pre_inline_screen_add_new_ph_num
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_pre_inline_screen_add_new_ph_num (U16 screen_id)
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wap_push_screenDB_struct *scrDB = NULL;
    mmi_wap_push_scrhdlr_inline_screen_struct  **screen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_wap_push_scrhdlr_get_screenDB();
	
	if(scrDB->screen == NULL)
	{
        screen = (mmi_wap_push_scrhdlr_inline_screen_struct**) (&(scrDB->screen));
		*screen = (mmi_wap_push_scrhdlr_inline_screen_struct*)OslMalloc (sizeof (mmi_wap_push_scrhdlr_inline_screen_struct));
        memset(*screen, 0, (sizeof (mmi_wap_push_scrhdlr_inline_screen_struct)));

        (*screen)->scrn_id = screen_id;
        (*screen)->hilighted_item = 0;
        g_push_cntxt->inline_gid = cui_inline_create(GRP_ID_BRW_PUSH_INLINE, &g_mmi_brw_push_ph_num_inline_screen);
        cui_inline_set_value(g_push_cntxt->inline_gid, MMI_BRW_PUSH_PH_NUM_SENDER_EDIT, (void *)g_push_set_p->sender_address);
        cui_inline_set_value(g_push_cntxt->inline_gid, MMI_BRW_PUSH_PH_NUM_SMSC_EDIT, (void *)g_push_set_p->smsc_address);
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
#endif /* 0 MAUI_02442929 */

/*
        (*screen)->number_of_items = mmi_wap_push_get_number_of_inline_scr_item (screen_id);
		(*screen)->image_list_icons = mmi_wap_push_get_add_new_ph_num_image_icon;
        (*screen)->inline_items = mmi_wap_push_fill_inline_item_for_add_new_ph_num;
        //mmi_wap_push_add_new_ph_num_set_buffers();
        */
		return MMI_TRUE;
	}
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_exit_inline_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_scrhdlr_exit_inline_screen (void)
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
 *  mmi_wap_push_scrhdlr_draw_inline_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_draw_inline_screen (U16 screen_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


	mmi_wap_push_screenDB_struct *scrDB = NULL;
	mmi_wap_push_resourceDB_struct *resourceDB = NULL;

    mmi_group_node_struct node_info;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_wap_push_scrhdlr_get_screenDB();
    resourceDB = scrDB->rcDB;

    if (mmi_frm_group_get_info (GRP_ID_BRW_PUSH_INLINE,&node_info) == MMI_RET_OK)
    {
        mmi_frm_group_set_proc_data (GRP_ID_BRW_PUSH_INLINE, node_info.proc, (void *)scrDB);
    }
    else
        ASSERT(0);

    cui_inline_set_title(g_push_cntxt->inline_gid, resourceDB->title_str_id, mmi_wap_push_get_title_icon(resourceDB->title_icon_id));
    cui_inline_run(g_push_cntxt->inline_gid);
    
	return MMI_TRUE;
}


/**********************************************************************************************************/
/*                                       END CODE FOR Selection screen                                    */
/**********************************************************************************************************/










/**********************************************************************************************************/
/*                                       Start CODE FOR Dynamic screen                                    */
/**********************************************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_pre_dynamic_screen_black_list
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_pre_dynamic_screen_black_list (U16 screen_id)
{
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    mmi_wap_push_screenDB_struct *scrDB = NULL;
    mmi_wap_push_scrhdlr_dynamic_screen_struct  **screen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_wap_push_scrhdlr_get_screenDB();

    screen = (mmi_wap_push_scrhdlr_dynamic_screen_struct**) (&(scrDB->screen));	
	if(scrDB->screen == NULL)
	{
		*screen = (mmi_wap_push_scrhdlr_dynamic_screen_struct*)OslMalloc (sizeof (mmi_wap_push_scrhdlr_dynamic_screen_struct));
        memset(*screen, 0, (sizeof (mmi_wap_push_scrhdlr_dynamic_screen_struct)));

        (*screen)->scrn_id = screen_id;
        (*screen)->hilighted_item = 0;

        (*screen)->dynamic_list_handler = mmi_wap_push_get_list_item;
    #if defined(__MMI_FTE_SUPPORT__) &&  defined(__MMI_TOUCH_SCREEN__)
        (*screen)->tap_callback_func = mmi_push_handle_tap_on_validation_list_screen;
    #endif /* __MMI_FTE_SUPPORT__ */
		result = MMI_TRUE;
	}
    (*screen)->number_of_items = mmi_wap_push_get_number_of_black_list();
    return result;
#else 
	return MMI_FALSE;
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_pre_dynamic_screen_white_list
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_pre_dynamic_screen_white_list (U16 screen_id)
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    mmi_wap_push_screenDB_struct *scrDB = NULL;
    mmi_wap_push_scrhdlr_dynamic_screen_struct  **screen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_wap_push_scrhdlr_get_screenDB();
	
    screen = (mmi_wap_push_scrhdlr_dynamic_screen_struct**) (&(scrDB->screen));
	if(scrDB->screen == NULL)
	{
		*screen = (mmi_wap_push_scrhdlr_dynamic_screen_struct*)OslMalloc (sizeof (mmi_wap_push_scrhdlr_dynamic_screen_struct));
        memset(*screen, 0, (sizeof (mmi_wap_push_scrhdlr_dynamic_screen_struct)));

        (*screen)->scrn_id = screen_id;
        (*screen)->hilighted_item = 0;

        (*screen)->dynamic_list_handler = mmi_wap_push_get_list_item;
    #if defined(__MMI_FTE_SUPPORT__) &&  defined(__MMI_TOUCH_SCREEN__)
        (*screen)->tap_callback_func = mmi_push_handle_tap_on_validation_list_screen;
    #endif /* __MMI_FTE_SUPPORT__ */
		result = MMI_TRUE;
	}
    (*screen)->number_of_items = mmi_wap_push_get_number_of_white_list();
    return result;
#else 
	return MMI_FALSE;
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_hilite_dynamic_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
void mmi_wap_push_scrhdlr_hilite_dynamic_screen (S32 index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    mmi_wap_push_set_crnt_hilited_index(index);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_draw_dynamic_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_draw_dynamic_screen (U16 screen_id)
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
	mmi_wap_push_screenDB_struct *scrDB = NULL;
	mmi_wap_push_resourceDB_struct *resourceDB = NULL;
	mmi_wap_push_scrhdlr_dynamic_screen_struct *screen = NULL;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_wap_push_scrhdlr_get_screenDB();
    resourceDB = scrDB->rcDB;
    screen = scrDB->screen;

    if (mmi_frm_scrn_enter(g_push_cntxt->scr_grp_id, scrDB->scrn_id, scrDB->exit_screen, scrDB->EntryFunction, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    //EntryNewScreen(scrDB->scrn_id, scrDB->exit_screen, scrDB->EntryFunction,  NULL);
     mmi_frm_scrn_set_user_data(g_push_cntxt->scr_grp_id, screen_id, (void *)scrDB);

    //gui_buffer = GetCurrGuiBuffer(scrDB->scrn_id);
     gui_buffer = mmi_frm_scrn_get_gui_buf(g_push_cntxt->scr_grp_id, scrDB->scrn_id);

    SetParentHandler(resourceDB->menu_item_id);
    RegisterHighlightHandler(scrDB->hilite_handler);

	if (scrDB->delete_screen_handler != NULL)
	{
        mmi_frm_scrn_set_leave_proc(g_push_cntxt->scr_grp_id, scrDB->scrn_id, scrDB->delete_screen_handler);
    }
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ShowCategory184Screen(
        resourceDB->title_str_id,
        mmi_wap_push_get_title_icon(resourceDB->title_icon_id),
        resourceDB->lsk_str_id,
        resourceDB->lsk_icon_id,
        resourceDB->rsk_str_id,
        resourceDB->rsk_icon_id,
        screen->number_of_items,
        screen->dynamic_list_handler,
        0,
        0,
        gui_buffer);


#if defined(__MMI_FTE_SUPPORT__) &&  defined(__MMI_TOUCH_SCREEN__)
    if (screen->tap_callback_func != NULL)
    {
        wgui_register_tap_callback (screen->tap_callback_func);
    }
#endif /* __MMI_FTE_SUPPORT__ */

    SetRightSoftkeyFunction(scrDB->rsk_func, KEY_EVENT_UP);
#endif /* __MMI_WAP_PUSH_WHITE_LIST__*/
	return MMI_TRUE;
}


/**********************************************************************************************************/
/*                                       END CODE FOR Dynamic screen                                      */
/**********************************************************************************************************/











/**********************************************************************************************************/
/*                                       Start CODE FOR Dynamic screen                                    */
/**********************************************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_post_async_dynamic_screen_inbox
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_post_async_dynamic_screen_inbox (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //DeleteScreenIfPresent(SCR_ID_PUSH_PROCESSING);
    mmi_wap_push_delete_screen_if_present(SCR_ID_PUSH_PROCESSING);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_lsk_service_inbox
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_scrhdlr_lsk_service_inbox (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_push_read_selected_message();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_pre_async_dynamic_screen_inbox
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_pre_async_dynamic_screen_inbox (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    mmi_wap_push_screenDB_struct *scrDB = NULL;
    mmi_wap_push_scrhdlr_async_dynamic_screen_struct  **screen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_wap_push_scrhdlr_get_screenDB();

    screen = (mmi_wap_push_scrhdlr_async_dynamic_screen_struct**) (&(scrDB->screen));	
	if(scrDB->screen == NULL)
	{
		*screen = (mmi_wap_push_scrhdlr_async_dynamic_screen_struct*)OslMalloc (sizeof (mmi_wap_push_scrhdlr_async_dynamic_screen_struct));
        memset(*screen, 0, (sizeof (mmi_wap_push_scrhdlr_async_dynamic_screen_struct)));

        (*screen)->scrn_id = screen_id;
        (*screen)->hilighted_item = 0;

        (*screen)->async_dynamic_list_handler = mmi_wap_push_get_async_items;
		result = MMI_TRUE;
	}
    mmi_wap_push_get_inbox_details (&(*screen)->number_of_items, &(*screen)->selected_item, &(*screen)->default_icon);
    mmi_wap_push_set_inbox_status();
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_hilite_async_dynamic_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
void mmi_wap_push_scrhdlr_hilite_async_dynamic_screen (S32 index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_push_set_highlighted_index_item(index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_draw_async_dynamic_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_draw_async_dynamic_screen (U16 screen_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    S32 list_not_ready = 0;

	mmi_wap_push_screenDB_struct *scrDB = NULL;
	mmi_wap_push_resourceDB_struct *resourceDB = NULL;
	mmi_wap_push_scrhdlr_async_dynamic_screen_struct *screen = NULL;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_wap_push_scrhdlr_get_screenDB();
    resourceDB = scrDB->rcDB;
    screen = scrDB->screen;

    if (mmi_frm_scrn_enter(g_push_cntxt->scr_grp_id, scrDB->scrn_id, scrDB->exit_screen, scrDB->EntryFunction, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return MMI_FALSE;
    }
    //EntryNewScreen(scrDB->scrn_id, scrDB->exit_screen, scrDB->EntryFunction,  NULL);
     mmi_frm_scrn_set_user_data(g_push_cntxt->scr_grp_id, screen_id, (void *)scrDB);

    //gui_buffer = GetCurrGuiBuffer(scrDB->scrn_id);
     gui_buffer = mmi_frm_scrn_get_gui_buf(g_push_cntxt->scr_grp_id, scrDB->scrn_id);

    SetParentHandler(resourceDB->menu_item_id);
    RegisterHighlightHandler(scrDB->hilite_handler);


	if (scrDB->delete_screen_handler != NULL)
	{
        mmi_frm_scrn_set_leave_proc(g_push_cntxt->scr_grp_id, scrDB->scrn_id, scrDB->delete_screen_handler);
    }
	EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	#if (MMI_MAX_SIM_NUM >= 2)
    wgui_cat_list_set_display_more_icon(MMI_TRUE);
    #endif
    ShowCategory262Screen(
        (U8*) GetString(resourceDB->title_str_id),
        mmi_wap_push_get_title_icon(resourceDB->title_icon_id),
        resourceDB->lsk_str_id,
        resourceDB->lsk_icon_id,
        resourceDB->rsk_str_id,
        resourceDB->rsk_icon_id,
        screen->number_of_items,
        screen->async_dynamic_list_handler,
        NULL,
        screen->selected_item,
        screen->default_icon,
        gui_buffer,
        &list_not_ready);

    if (list_not_ready)
    {
        mmi_wap_push_scrhdlr_entry_async_processing ();
        //DeleteScreenIfPresent(SCR_ID_PUSH_ASYNC_PROCESSING);
        //mmi_wap_push_delete_screen_if_present(SCR_ID_PUSH_ASYNC_PROCESSING);
    }

    if (scrDB->rsk_func != NULL)
    {
        SetRightSoftkeyFunction(scrDB->rsk_func, KEY_EVENT_UP);
    }
    if (scrDB->lsk_func != NULL)
    {
        SetLeftSoftkeyFunction(scrDB->lsk_func, KEY_EVENT_UP);
	    SetCenterSoftkeyFunction(scrDB->lsk_func, KEY_EVENT_UP);
    }
	return MMI_TRUE;
}


/**********************************************************************************************************/
/*                                       END CODE FOR Dynamic screen                                      */
/**********************************************************************************************************/












/**********************************************************************************************************/
/*                                       Start CODE FOR Dynamic screen                                    */
/**********************************************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_rsk_sia_dlg_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void.
 *****************************************************************************/
#ifndef __MMI_WAP_PUSH_SIA_SLIM__
void mmi_wap_push_scrhdlr_rsk_sia_dlg_screen (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_push_handle_rsk_on_sia_dlg_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_lsk_sia_dlg_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_scrhdlr_lsk_sia_dlg_screen (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_push_handle_lsk_sia_dlg_screen();
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_lsk_selected_message_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_scrhdlr_lsk_selected_message_screen (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_push_entry_msg_opt_menu();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_rsk_selected_message_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_scrhdlr_rsk_selected_message_screen (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PUSH_IN_UM__
    //srv_wap_push_send_um_refresh_ind();
#endif /* __MMI_PUSH_IN_UM__ */
    mmi_frm_scrn_close_active_id();
#ifdef __MMI_PUSH_IN_UM__
    g_srv_wap_push_cntxt->read_from_um = MMI_FALSE;
#endif /* __MMI_PUSH_IN_UM__ */
	#ifdef __MMI_NCENTER_SUPPORT__
	if(g_srv_wap_push_cntxt->message_queue_front != NULL)
         {
           mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_WAP_PUSH, MMI_EVENT_UNREAD_MSG, mmi_wap_push_ncenter_msg_queue_handler, (void *)NULL);
  
       }
    #endif
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_pre_selected_message_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_pre_selected_message_screen (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wap_push_screenDB_struct *scrDB = NULL;
    mmi_wap_push_scrhdlr_message_screen_struct  **screen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_wap_push_scrhdlr_get_screenDB();

    screen = (mmi_wap_push_scrhdlr_message_screen_struct**) (&(scrDB->screen));	
	if(scrDB->screen == NULL)
	{
		*screen = (mmi_wap_push_scrhdlr_message_screen_struct*)OslMalloc (sizeof (mmi_wap_push_scrhdlr_message_screen_struct));
        memset(*screen, 0, (sizeof (mmi_wap_push_scrhdlr_message_screen_struct)));

        (*screen)->scrn_id = screen_id;

        mmi_wap_push_get_message_screen_data (
            screen_id,
            &((*screen)->title_string_id),
            &((*screen)->lsk_string_id),
            &((*screen)->lsk_image_id),
            &((*screen)->rsk_string_id),
            &((*screen)->rsk_image_id),
            &((*screen)->data_init_func),
            &((*screen)->csk_func),
            &((*screen)->lnk_func),
            &((*screen)->rnk_func));
   #if defined (__MMI_FTE_SUPPORT__ ) && defined (__MMI_ICON_BAR_SUPPORT__)
        mmi_push_uiplugin_init_viewer_fte_data (&((*screen)->fte_data), screen_id);
    #endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_PUSH_IN_UM__
    #ifdef __MMI_UM_ITERATOR_VIEWER__
        if (g_srv_wap_push_cntxt->read_from_um)
        {
            mmi_push_uiplugin_get_slide_buttons_data (&((*screen)->slide_buttons_data), screen_id);
        }
    #endif
#endif /* __MMI_PUSH_IN_UM__ */

		return MMI_TRUE;
	}
#ifdef __MMI_PUSH_IN_UM__
    #ifdef __MMI_UM_ITERATOR_VIEWER__
        if (g_srv_wap_push_cntxt->read_from_um)
        {
            mmi_push_uiplugin_get_slide_buttons_data (&((*screen)->slide_buttons_data), screen_id);
        }
    #endif
#endif /* __MMI_PUSH_IN_UM__ */
    return MMI_FALSE;
}

#ifdef __MMI_PUSH_IN_UM__
#ifdef __MMI_UM_ITERATOR_VIEWER__
void mmi_wap_push_update_viewer_slide_button_data (void)
{
    mmi_wap_push_screenDB_struct *scrDB = NULL;
    mmi_wap_push_scrhdlr_message_screen_struct **screen = NULL;
    scrDB = mmi_wap_push_scrhdlr_get_screenDB_for_screen_id (SCR_ID_BRW_READ_SERVICE_MESSAGE);
    MMI_ASSERT (scrDB->screen != NULL);
    screen = (mmi_wap_push_scrhdlr_message_screen_struct**) (&(scrDB->screen));
    mmi_push_uiplugin_get_slide_buttons_data (&((*screen)->slide_buttons_data), (*screen)->scrn_id);
}
#endif /* __MMI_UM_ITERATOR_VIEWER__ */
#endif /* __MMI_PUSH_IN_UM__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_draw_message_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_draw_message_screen (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
	mmi_wap_push_screenDB_struct *scrDB = NULL;
	mmi_wap_push_resourceDB_struct *resourceDB = NULL;
	mmi_wap_push_scrhdlr_message_screen_struct *screen = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_INSIDE_VIEW);

	scrDB = mmi_wap_push_scrhdlr_get_screenDB();
    resourceDB = scrDB->rcDB;
    screen = scrDB->screen;

    if (mmi_frm_scrn_enter(g_push_cntxt->scr_grp_id, scrDB->scrn_id, scrDB->exit_screen, scrDB->EntryFunction, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return MMI_FALSE;
    }
    //EntryNewScreen(scrDB->scrn_id, scrDB->exit_screen, scrDB->EntryFunction,  NULL);
     mmi_frm_scrn_set_user_data(g_push_cntxt->scr_grp_id, screen_id, (void *)scrDB);
    //gui_buffer = GetCurrGuiBuffer(scrDB->scrn_id);
     gui_buffer = mmi_frm_scrn_get_gui_buf(g_push_cntxt->scr_grp_id, scrDB->scrn_id);

    if (screen->data_init_func != NULL)
    {
        screen->data_init_func();
    }

#ifdef __MMI_ICON_BAR_SUPPORT__
    if (screen->fte_data.item_count != 0)
    {
		wgui_icon_bar_setup
			(screen->fte_data.item_count,
			screen->fte_data.content_icon,
			screen->fte_data.disabled_content_icon,
			screen->fte_data.string,
			screen->fte_data.callback);
    }
#endif /*__MMI_ICON_BAR_SUPPORT__*/

    if (screen->csk_func != NULL)
    {
		if(screen_id == SCR_ID_BRW_READ_SERVICE_MESSAGE)
			EnableCenterSoftkey(0, IMG_GLOBAL_WEB_BROWSER_CSK);
		else
			EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }

	if (scrDB->delete_screen_handler != NULL)
	{
        mmi_frm_scrn_set_leave_proc(g_push_cntxt->scr_grp_id, scrDB->scrn_id, scrDB->delete_screen_handler);
    }

#ifdef __MMI_UM_ITERATOR_VIEWER__
    if ((screen->lnk_func != NULL) && (screen->rnk_func != NULL))
    {

        wgui_cat_text_viewer_setup_slide_buttons (
            (WCHAR*)screen->slide_buttons_data.left_button_string,
            screen->slide_buttons_data.left_button_down_img,
            screen->slide_buttons_data.left_button_up_img,
            screen->slide_buttons_data.left_button_func,
            (WCHAR*)screen->slide_buttons_data.right_button_string,
            screen->slide_buttons_data.right_button_down_img,
            screen->slide_buttons_data.right_button_up_img,
            screen->slide_buttons_data.right_button_func,
            (WCHAR*)(&(screen->slide_buttons_data.middle_string)),
            0);

    }
#endif /* __MMI_UM_ITERATOR_VIEWER__ */

    ShowCategory74Screen(
        screen->title_string_id,
        mmi_wap_push_get_title_icon(resourceDB->title_icon_id),
        screen->lsk_string_id,
        screen->lsk_image_id,
        screen->rsk_string_id,
        screen->rsk_image_id,
        (U8*) subMenuData,    /* data is filled by data_init_func */
        mmi_ucs2strlen((const S8*)subMenuData),
        gui_buffer);

    if (scrDB->lsk_func)
    {
        SetLeftSoftkeyFunction(scrDB->lsk_func, KEY_EVENT_UP);
    }

    if (scrDB->rsk_func)
    {
        SetRightSoftkeyFunction(scrDB->rsk_func, KEY_EVENT_UP);
    }

    if (screen->csk_func != NULL)
    {
        SetCenterSoftkeyFunction(screen->csk_func, KEY_EVENT_UP);
    }

    if (screen->lnk_func != NULL)
    {
        SetKeyUpHandler(screen->lnk_func, KEY_LEFT_ARROW);
#ifdef __MMI_PUSH_IN_UM__
#ifdef __MMI_UM_ITERATOR_VIEWER__
        SetKeyDownHandler(wgui_cat_text_viewer_show_left_slide_button_down, KEY_LEFT_ARROW);
    #if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) 
	    mmi_frm_gesture_listen_event(MMI_FRM_GESTURE_RIGHT, mmi_wap_push_display_prev_viewer_through_swipe);
    #endif
#endif /* __MMI_UM_ITERATOR_VIEWER__ */
#endif /* __MMI_PUSH_IN_UM__ */
    }
    if (screen->rnk_func != NULL)
    {
        SetKeyUpHandler(screen->rnk_func, KEY_RIGHT_ARROW);
#ifdef __MMI_PUSH_IN_UM__
#ifdef __MMI_UM_ITERATOR_VIEWER__
        SetKeyDownHandler(wgui_cat_text_viewer_show_right_slide_button_down, KEY_RIGHT_ARROW);
    #if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) 
	    mmi_frm_gesture_listen_event(MMI_FRM_GESTURE_LEFT, mmi_wap_push_display_next_viewer_through_swipe);
    #endif
#endif /* __MMI_UM_ITERATOR_VIEWER__ */
#endif /* __MMI_PUSH_IN_UM__ */
    }

    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_END_VIEW);
	return MMI_TRUE;
}

#ifndef __MMI_WAP_PUSH_SIA_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_post_sia_dlg_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  MMI_TRUE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_post_sia_dlg_screen (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetKeyDownHandler(mmi_wap_push_end_key_sia_dlg_screen, KEY_END);
    return MMI_TRUE;
}
#endif

/**********************************************************************************************************/
/*                                       END CODE FOR Dynamic screen                                      */
/**********************************************************************************************************/









/**********************************************************************************************************/
/*                                       Start CODE FOR progress screen                                   */
/**********************************************************************************************************/



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_pre_progress_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_pre_progress_screen (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wap_push_screenDB_struct *scrDB = NULL;
    mmi_wap_push_scrhdlr_progress_screen_struct  **screen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_wap_push_scrhdlr_get_screenDB();

    screen = (mmi_wap_push_scrhdlr_progress_screen_struct**) (&(scrDB->screen));	
	if(scrDB->screen == NULL)
	{
		*screen = (mmi_wap_push_scrhdlr_progress_screen_struct*)OslMalloc (sizeof (mmi_wap_push_scrhdlr_progress_screen_struct));
        memset(*screen, 0, (sizeof (mmi_wap_push_scrhdlr_progress_screen_struct)));

        (*screen)->scrn_id = screen_id;
        mmi_wap_push_get_progress_scr_img_and_str_id (screen_id, &(*screen)->msg_str_id, &(*screen)->msg_img_id);

		return MMI_TRUE;
	}
    return MMI_FALSE;
}


mmi_ret mmi_push_popup_confirm_group_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   switch (evt->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE :
        case EVT_ID_GROUP_FOCUSED:
            g_push_cntxt->scr_grp_id = GRP_ID_BRW_PUSH_POPUP_CONFIRM;
        break;
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
            g_push_cntxt->scr_grp_id = GRP_ID_INVALID;
            break;
        case EVT_ID_GROUP_DEINIT:
            /* need addd code to release buffer */
            mmi_frm_group_close (GRP_ID_BRW_PUSH_POPUP_CONFIRM);
            //g_push_cntxt->scr_grp_id = GRP_ID_INVALID;
            break;
        default:
            break;

    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_draw_progress_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_draw_progress_screen (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_wap_push_screenDB_struct *scrDB = NULL;
	mmi_wap_push_scrhdlr_progress_screen_struct *screen = NULL;
    mmi_group_node_struct node_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_wap_push_scrhdlr_get_screenDB();
    screen = scrDB->screen;

   if (mmi_frm_group_get_info (g_push_cntxt->scr_grp_id, &node_info)== MMI_RET_ERR)
    //if (g_push_cntxt->scr_grp_id == GRP_ID_INVALID)
    {
        mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_BRW_PUSH_POPUP_CONFIRM, mmi_push_popup_confirm_group_proc, NULL);
        mmi_frm_group_enter(GRP_ID_BRW_PUSH_POPUP_CONFIRM, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        g_push_cntxt->scr_grp_id = GRP_ID_BRW_PUSH_POPUP_CONFIRM;
    }

    if (mmi_frm_scrn_enter(g_push_cntxt->scr_grp_id, scrDB->scrn_id, scrDB->exit_screen, scrDB->EntryFunction, MMI_FRM_UNKNOW_SCRN) == MMI_FALSE)
    {
        return MMI_FALSE;
    }
//    EntryNewScreen(scrDB->scrn_id, scrDB->exit_screen, scrDB->EntryFunction,  NULL);
     mmi_frm_scrn_set_user_data(g_push_cntxt->scr_grp_id, screen_id, (void *)scrDB);
	if (scrDB->delete_screen_handler != NULL)
	{
        mmi_frm_scrn_set_leave_proc(g_push_cntxt->scr_grp_id, scrDB->scrn_id, scrDB->delete_screen_handler);
    }

    ShowCategory65Screen((PU8) GetString(screen->msg_str_id), screen->msg_img_id, NULL);

	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_post_progress_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_post_progress_screen (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (screen_id)
    {
    case SCR_ID_PUSH_POPUP_SCREEN:
        {
            GetCurrEndKeyDownHandler();
            SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_DOWN);
            SetGroupKeyHandler(mmi_push_close_active_screen, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_UP);
            ClearKeyHandler(KEY_END, KEY_EVENT_UP);
            SetKeyDownHandler(ExecCurrEndKeyDownHandler, KEY_END);
            ForceSubLCDScreen(mmi_wap_push_start_msg_sub_anm);
        }
        break;
    default:
        {
            SetKeyDownHandler(NULL, KEY_LEFT_ARROW);
            SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);
            ClearAllKeyHandler();
            ClearKeyHandler(KEY_END, KEY_EVENT_UP);
            ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
            ClearKeyHandler(KEY_END, KEY_REPEAT);
        }
        break;
    }
    return MMI_TRUE;
}



/**********************************************************************************************************/
/*                                       END CODE FOR progress screen                                     */
/**********************************************************************************************************/







/**********************************************************************************************************/
/*                                       Start CODE FOR notification screen                               */
/**********************************************************************************************************/



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_pre_notification_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_pre_notification_screen (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wap_push_screenDB_struct *scrDB = NULL;
    mmi_wap_push_resourceDB_struct *resourceDB = NULL;
    mmi_wap_push_scrhdlr_notification_screen_struct  **screen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_wap_push_scrhdlr_get_screenDB();
    resourceDB = scrDB->rcDB;

    screen = (mmi_wap_push_scrhdlr_notification_screen_struct**) (&(scrDB->screen));	
	if(scrDB->screen == NULL)
	{
        if (screen_id == SCR_ID_BRW_NEW_PUSH_MESSAGE_IND)
        {
            resourceDB->lsk_str_id = 0;
            resourceDB->lsk_icon_id =0;
            resourceDB->rsk_str_id = 0;
            resourceDB->rsk_icon_id =0;
        }
		*screen = (mmi_wap_push_scrhdlr_notification_screen_struct*)OslMalloc (sizeof (mmi_wap_push_scrhdlr_notification_screen_struct));
        memset(*screen, 0, (sizeof (mmi_wap_push_scrhdlr_notification_screen_struct)));

        (*screen)->scrn_id = screen_id;
        mmi_wap_push_get_notification_scr_img_and_str_id (screen_id, &(*screen)->msg_str_id, &(*screen)->msg_img_id);

		return MMI_TRUE;
	}
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_draw_notification_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_draw_notification_screen (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_wap_push_screenDB_struct *scrDB = NULL;
	mmi_wap_push_resourceDB_struct *resourceDB = NULL;
	mmi_wap_push_scrhdlr_notification_screen_struct *screen = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_wap_push_scrhdlr_get_screenDB();
    resourceDB = scrDB->rcDB;
    screen = scrDB->screen;

    if (mmi_frm_scrn_enter(g_push_cntxt->scr_grp_id, scrDB->scrn_id, scrDB->exit_screen, scrDB->EntryFunction, MMI_FRM_UNKNOW_SCRN) == MMI_FALSE)
    {
        return MMI_FALSE;
    }
//    EntryNewScreen(scrDB->scrn_id, scrDB->exit_screen, scrDB->EntryFunction,  NULL);
     mmi_frm_scrn_set_user_data(g_push_cntxt->scr_grp_id, screen_id, (void *)scrDB);

	if (scrDB->delete_screen_handler != NULL)
	{
        mmi_frm_scrn_set_leave_proc(g_push_cntxt->scr_grp_id, scrDB->scrn_id, scrDB->delete_screen_handler);
    }
    ShowCategory154Screen(
        resourceDB->title_str_id,
        mmi_wap_push_get_title_icon(resourceDB->title_icon_id),
        resourceDB->lsk_str_id,
        resourceDB->lsk_icon_id,
        resourceDB->rsk_str_id,
        resourceDB->rsk_icon_id,
        (PU8) GetString(screen->msg_str_id),
        (PU8) NULL,
        screen->msg_img_id,
        NULL);

    if (scrDB->lsk_func)
    {
        SetLeftSoftkeyFunction(scrDB->lsk_func, KEY_EVENT_UP);
    }

    if (scrDB->rsk_func)
    {
        SetRightSoftkeyFunction(scrDB->rsk_func, KEY_EVENT_UP);
    }
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_post_notification_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_post_notification_screen (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (screen_id)
    {
    case SCR_ID_BRW_NEW_PUSH_MESSAGE_IND:
        {
            GetCurrEndKeyDownHandler();
            ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        }
        break;
    default:
        {
            GetCurrEndKeyDownHandler();
            SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_DOWN);
            SetGroupKeyHandler(mmi_push_close_active_screen, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_UP);
            ClearKeyHandler(KEY_END, KEY_EVENT_UP);
            SetKeyDownHandler(ExecCurrEndKeyDownHandler, KEY_END);
        }
        break;
    }
    return MMI_TRUE;
}



/**********************************************************************************************************/
/*                                       END CODE FOR notification screen                                 */
/**********************************************************************************************************/












/**********************************************************************************************************/
/*                                       Start CODE FOR small screen                                      */
/**********************************************************************************************************/



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_pre_small_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_pre_small_screen (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wap_push_screenDB_struct *scrDB = NULL;
    mmi_wap_push_resourceDB_struct *resourceDB = NULL;
    mmi_wap_push_scrhdlr_small_screen_struct  **screen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_wap_push_scrhdlr_get_screenDB();
    resourceDB = scrDB->rcDB;

    screen = (mmi_wap_push_scrhdlr_small_screen_struct**) (&(scrDB->screen));	
	if(scrDB->screen == NULL)
	{
		*screen = (mmi_wap_push_scrhdlr_small_screen_struct*)OslMalloc (sizeof (mmi_wap_push_scrhdlr_small_screen_struct));
        memset(*screen, 0, (sizeof (mmi_wap_push_scrhdlr_small_screen_struct)));

        (*screen)->scrn_id = screen_id;
        mmi_wap_push_get_notification_scr_img_and_str_id (screen_id, &(*screen)->msg_str_id, &(*screen)->msg_img_id);

        /* Used as a dirty patch to control the title of message deleted dialogue */
        if (screen_id == SCR_ID_BRW_PUSH_MSG_DELETED)
        {
            resourceDB->title_str_id = mmi_wap_push_get_title_str_id_for_msg_deleted_screen ();
        }

		return MMI_TRUE;
	}
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_scrhdlr_draw_small_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_scrhdlr_draw_small_screen (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_wap_push_screenDB_struct *scrDB = NULL;
	mmi_wap_push_resourceDB_struct *resourceDB = NULL;
	mmi_wap_push_scrhdlr_small_screen_struct *screen = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_wap_push_scrhdlr_get_screenDB();
    resourceDB = scrDB->rcDB;
    screen = scrDB->screen;
    if (mmi_frm_scrn_enter(g_push_cntxt->scr_grp_id, scrDB->scrn_id, scrDB->exit_screen, scrDB->EntryFunction, MMI_FRM_UNKNOW_SCRN) == MMI_FALSE)
    {
        return MMI_FALSE;
    }
//    EntryNewScreen(scrDB->scrn_id, scrDB->exit_screen, scrDB->EntryFunction,  NULL);
     mmi_frm_scrn_set_user_data(g_push_cntxt->scr_grp_id, screen_id, (void *)scrDB);
	if (scrDB->delete_screen_handler != NULL)
	{
        mmi_frm_scrn_set_leave_proc(g_push_cntxt->scr_grp_id, scrDB->scrn_id, scrDB->delete_screen_handler);
    }
    ShowCategory8Screen(
        resourceDB->title_str_id,
        mmi_wap_push_get_title_icon(resourceDB->title_icon_id),
        resourceDB->lsk_str_id,
        resourceDB->lsk_icon_id,
        resourceDB->rsk_str_id,
        resourceDB->rsk_icon_id,
        screen->msg_str_id,
        screen->msg_img_id,
        NULL);
    if (scrDB->lsk_func)
    {
        SetLeftSoftkeyFunction(scrDB->lsk_func, KEY_EVENT_UP);
    }
    if (scrDB->rsk_func)
    {
        SetRightSoftkeyFunction(scrDB->rsk_func, KEY_EVENT_UP);
    }
	return MMI_TRUE;
}

/**********************************************************************************************************/
/*                                       END CODE FOR small screen                                        */
/**********************************************************************************************************/







/**********************************************************************************************************/
/*                                       Start CODE FOR Entry functions screen                            */
/**********************************************************************************************************/
void mmi_wap_push_entry_um_list_opt_menu (void)
{
    mmi_wap_push_if_draw_screen(SCR_ID_UM_MESSAGE_OPTIONS);
    return;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */

void mmi_wap_push_entry_send_by_opt_menu (void)
{
    mmi_wap_push_if_draw_screen(SCR_ID_BRW_SEND_BY_OPTIONS);
    return;
}


void mmi_wap_push_entry_msg_opt_menu (void)
{
    mmi_wap_push_if_draw_screen(SCR_ID_BRW_READ_SERVICE_MESSAGE_OPTIONS);
    return;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

void mmi_wap_push_entry_unknwn_addr_opt_menu (void)
{
    mmi_wap_push_if_draw_screen(SCR_ID_PUSH_UNKNWN_ADDR_OPTIONS);
    return;
}


void mmi_wap_push_setting_entry_main_menu (void)
{
    mmi_wap_push_if_draw_screen(SCR_ID_PUSH_SETTING);
    return;
}

void mmi_wap_push_entry_service_message (void)
{
    mmi_wap_push_if_draw_screen(SCR_ID_PUSH_ENTRY_SERVICE_MSG);
    return;
}


void mmi_wap_push_setting_entry_wl_opt_menu (void)
{
    mmi_wap_push_if_draw_screen(SCR_ID_PUSH_WHITE_LIST_OPTIONS);
    return;
}


void mmi_wap_push_setting_entry_wl_add_new_menu (void)
{
    mmi_wap_push_if_draw_screen(SCR_ID_PUSH_WHITE_LIST_ADD_NEW);
    return;
}

void mmi_wap_push_scrhdlr_entry_enable_push (void)
{
    mmi_wap_push_if_draw_screen(SCR_ID_PUSH_ENABLE_PUSH);
}

void mmi_wap_push_scrhdlr_entry_enable_sl_set (void)
{
    mmi_wap_push_if_draw_screen(SCR_ID_PUSH_SL_SETTING);
}

void mmi_wap_push_scrhdlr_entry_enable_black_list (void)
{
    mmi_wap_push_if_draw_screen(SCR_ID_PUSH_ENABLE_BL_SETTING);
}

void mmi_wap_push_scrhdlr_entry_enable_white_list (void)
{
    mmi_wap_push_if_draw_screen(SCR_ID_PUSH_ENABLE_WL_SETTING);
}

void mmi_wap_push_scrhdlr_entry_add_new_ph_num (void)
{
    mmi_wap_push_if_draw_screen(SCR_ID_PUSH_WHITE_LIST_ADD_NEW_PHONE_NUM);
}

void mmi_wap_push_scrhdlr_entry_add_new_ip (void)
{
    mmi_wap_push_if_draw_screen(SCR_ID_PUSH_WHITE_LIST_ADD_NEW_IP_ADDR);
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0*/

void mmi_wap_push_setting_entry_white_list (void)
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    g_push_set_p->selected_list_type = SRV_WAP_PUSH_WHITE_LIST;
    mmi_wap_push_if_draw_screen(SCR_ID_PUSH_WHITE_LIST);
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
}

void mmi_wap_push_setting_entry_black_list (void)
{
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    g_push_set_p->selected_list_type = SRV_WAP_PUSH_BLACK_LIST;
    mmi_wap_push_if_draw_screen(SCR_ID_PUSH_BLACK_LIST);
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
}

void mmi_wap_push_scrhdlr_entry_message_display (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ret_code = SRV_WAP_PUSH_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_code = mmi_wap_push_if_draw_screen(SCR_ID_BRW_READ_SERVICE_MESSAGE);
    if (ret_code == SRV_WAP_PUSH_ASYNC_WAIT)
    {
        mmi_wap_push_scrhdlr_entry_generic_processing();
    }
}
#if !defined(__MMI_WAP_PUSH_SIA_SLIM__) || defined(__MMI_WAP_PUSH_WHITE_LIST__) 
void mmi_wap_push_scrhdlr_entry_sia_dlg_display (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ret_code = SRV_WAP_PUSH_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_push_create_idle_callback_group();
    ret_code = mmi_wap_push_if_draw_screen(SCR_ID_PUSH_DISPALY_SIA_CNF);
    if (ret_code == SRV_WAP_PUSH_ASYNC_WAIT)
    {
        ASSERT(0);
    }
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_unlock_gdi_buffer
 * DESCRIPTION
 *  Unlock the gdi buffer
 * PARAMETERS
 *  void.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_unlock_gdi_buffer (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_push_cntxt->gdi_locked)
    {
        MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_GDI_UNLOCKED);
        gdi_lcd_freeze(FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_draw_dummy_screen
 * DESCRIPTION
 *  Display a dummy screen on Idle callback before actual message display.
 * PARAMETERS
 *  void.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_draw_dummy_screen (MMI_BOOL gdi_lock)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (SCR_ID_BRW_PUSH_DUMMY_SCREEN != mmi_frm_scrn_get_active_id())
    {
        MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_FREEZ_GDI);
        if (gdi_lock)
        {
            if (mmi_frm_scrn_enter(g_push_cntxt->scr_grp_id, SCR_ID_BRW_PUSH_DUMMY_SCREEN, mmi_wap_push_unlock_gdi_buffer, NULL, MMI_FRM_UNKNOW_SCRN) == MMI_FALSE)
            {
                return;
            }
            //EntryNewScreen(SCR_ID_BRW_PUSH_DUMMY_SCREEN, mmi_wap_push_unlock_gdi_buffer, NULL, NULL);
            //mmi_frm_scrn_set_user_data(g_push_cntxt->scr_grp_id, SCR_ID_BRW_PUSH_DUMMY_SCREEN, (void *)scrDB);
            g_push_cntxt->gdi_locked = MMI_TRUE;
            gdi_lcd_freeze(TRUE);
            //memset(currKeyFuncPtrs, 0, sizeof(currKeyFuncPtrs));
            mmi_frm_set_all_key_hdlr_null();
        }
        else
        {
            mmi_frm_display_dummy_screen();
        }
    }
}

mmi_ret mmi_push_popup_confirmation_group_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   switch (evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT :
		{
			mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct *)evt;

			switch(alert->result)
			{
				case MMI_ALERT_CNFM_YES:
					(g_push_cntxt->confirmation_lsk)();
					break;
				case MMI_ALERT_CNFM_NO:
					(g_push_cntxt->confirmation_rsk)();
					break;
			}
		}
	}
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_event_based_confirm
 * DESCRIPTION
 *  This function can be used to Display confirmation screen which select the 
 *  image and tone on the basis of Event passed.
 * PARAMETERS
 *  str_id        [IN]
 *  lsk           [IN]
 *  rsk           [IN]
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_event_based_confirm(U16 str_id, Default_func_ptr lsk, Default_func_ptr rsk, Default_func_ptr csk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_popup;
    mmi_group_node_struct node_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&confirm_popup, CNFM_TYPE_YESNO);

	confirm_popup.callback = mmi_push_popup_confirmation_group_proc;

   if (mmi_frm_group_get_info (g_push_cntxt->scr_grp_id, &node_info)== MMI_RET_ERR)
    //if (g_push_cntxt->scr_grp_id == GRP_ID_INVALID)
    {
        confirm_popup.parent_id = GRP_ID_ROOT;
    }
    else
    {
        confirm_popup.parent_id = g_push_cntxt->scr_grp_id;
    }
	
	if(csk == NULL)
		confirm_popup.f_auto_map_empty_softkey = MMI_FALSE;
	else
		confirm_popup.f_auto_map_empty_softkey = MMI_TRUE;
	g_push_cntxt->confirmation_lsk = lsk;
	g_push_cntxt->confirmation_rsk = rsk;
	g_push_cntxt->confirmation_csk = csk;  
    mmi_confirm_display((UI_string_type) GetString (str_id), MMI_EVENT_QUERY, &confirm_popup);
}



U16 mmi_wap_push_map_internal_event (U16 event_id)
{
    switch (event_id)
    {
    case SRV_WAP_PUSH_EVENT_FAILURE:
        return MMI_EVENT_FAILURE;

    case SRV_WAP_PUSH_EVENT_INFO:
        return MMI_EVENT_INFO;

    case SRV_WAP_PUSH_EVENT_WARNING:
        return MMI_EVENT_WARNING;

    case SRV_WAP_PUSH_EVENT_SUCCESS:
        return MMI_EVENT_SUCCESS;

    case SRV_WAP_PUSH_EVENT_PROGRESS:
        return MMI_EVENT_PROGRESS;

    case SRV_WAP_PUSH_EVENT_QUERY:
        return MMI_EVENT_QUERY;

    case SRV_WAP_PUSH_EVENT_MESSAGE_SENT:
        return MMI_EVENT_MESSAGE_SENT;

    case SRV_WAP_PUSH_EVENT_PROPLEM:
        return MMI_EVENT_PROPLEM;

    case SRV_WAP_PUSH_EVENT_EXPLICITLY_SAVED:
        return MMI_EVENT_EXPLICITLY_SAVED;

    case SRV_WAP_PUSH_EVENT_EXPLICITLY_DELETED:
        return MMI_EVENT_EXPLICITLY_DELETED;

    case SRV_WAP_PUSH_EVENT_CONFIRM:
        return MMI_EVENT_CONFIRM;

    case SRV_WAP_PUSH_EVENT_BATTERY_WARNING:
        return MMI_EVENT_BATTERY_WARNING;

    case SRV_WAP_PUSH_EVENT_NOT_AVAILABLE:
        return MMI_EVENT_NOT_AVAILABLE;

    case SRV_WAP_PUSH_EVENT_ANSPHONE:
        return MMI_EVENT_ANSPHONE;

    case SRV_WAP_PUSH_EVENT_REMIND:
        return MMI_EVENT_REMIND;

    case SRV_WAP_PUSH_EVENT_BATTERY_NOTIFY:
        return MMI_EVENT_BATTERY_NOTIFY;

    case SRV_WAP_PUSH_EVENT_TOTAL_NUM:
        return MMI_EVENT_TOTAL_NUM;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_event_based_display_popup
 * DESCRIPTION
 *  This function can be used to Display popup which select the image and tone on the basis of Event passed.
 * PARAMETERS
 *  event_id       [IN]
 *  str_id         [IN]
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_event_based_display_popup (U16 event_id, U16 str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_gid;
    mmi_group_node_struct node_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_get_info (g_push_cntxt->scr_grp_id, &node_info)== MMI_RET_ERR)
    {
        menu_gid = GRP_ID_ROOT;
    }
    else
    {
        menu_gid = g_push_cntxt->scr_grp_id;
    }

    mmi_popup_display_simple((WCHAR*)GetString (str_id),(mmi_event_notify_enum)mmi_wap_push_map_internal_event(event_id), GRP_ID_ROOT,NULL);
}


void mmi_wap_push_scrhdlr_entry_generic_processing_ex (void)
{
        mmi_wap_push_if_draw_screen(SCR_ID_PUSH_GENERIC_PROCESSING);
}

void mmi_wap_push_scrhdlr_entry_generic_processing (void)
{
    if (!(mmi_wap_push_is_screen_present(SCR_ID_PUSH_GENERIC_PROCESSING) || (mmi_frm_scrn_get_active_id() == SCR_ID_PUSH_GENERIC_PROCESSING)))
    {
        mmi_wap_push_scrhdlr_entry_generic_processing_ex();
    }
}

MMI_BOOL mmi_wap_push_scrhdlr_draw_message_popup (mmi_scenario_id scen_id, void *arg)
{
    mmi_group_node_struct node_info;
    if (mmi_frm_group_get_info (g_push_cntxt->scr_grp_id, &node_info)== MMI_RET_ERR)
//    if (g_push_cntxt->scr_grp_id == GRP_ID_INVALID)
    {
       // mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_BRW_PUSH_POPUP_CONFIRM, mmi_push_popup_confirm_group_proc, NULL);
       // mmi_frm_group_enter(GRP_ID_BRW_PUSH_POPUP_CONFIRM, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_BRW_PUSH_POPUP_CONFIRM, mmi_push_popup_confirm_group_proc, NULL,MMI_FRM_NODE_SMART_CLOSE_FLAG);
        g_push_cntxt->scr_grp_id = GRP_ID_BRW_PUSH_POPUP_CONFIRM;
    }

    mmi_frm_start_scenario(MMI_SCENARIO_ID_WAP_PUSH);
    mmi_wap_push_if_draw_screen(SCR_ID_PUSH_POPUP_SCREEN);
return MMI_TRUE;
}

void mmi_wap_push_scrhdlr_entry_inbox_processing (void)
{
    mmi_wap_push_if_draw_screen(SCR_ID_PUSH_PROCESSING);
}

void mmi_wap_push_scrhdlr_entry_async_processing (void)
{
    mmi_wap_push_if_draw_screen(SCR_ID_PUSH_ASYNC_PROCESSING);
}

void mmi_wap_push_scrhdlr_entry_new_msg_ind_screen (void)
{
    mmi_wap_push_if_draw_screen(SCR_ID_BRW_NEW_PUSH_MESSAGE_IND);
}

void mmi_wap_push_scrhdlr_entry_msg_deleted_screen (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_node_struct node_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_get_info (g_push_cntxt->scr_grp_id, &node_info)== MMI_RET_ERR)
    //if (g_push_cntxt->scr_grp_id == GRP_ID_INVALID)
    {
        mmi_wap_push_create_idle_callback_group();
    }
    mmi_wap_push_if_draw_screen(SCR_ID_BRW_PUSH_MSG_DELETED);
}

void mmi_wap_push_setting_entry_service_inbox (void)
{
    if (g_push_inbox_ctxt->num_of_messages == 0)
    {
        mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_FAILURE, STR_GLOBAL_EMPTY);
        mmi_wap_push_delete_screen_if_present(SCR_ID_PUSH_PROCESSING);
//        DeleteScreenIfPresent(SCR_ID_PUSH_PROCESSING);
        return;
    }
    mmi_wap_push_if_draw_screen(SCR_ID_PUSH_INBOX);
}


/**********************************************************************************************************/
/*                                       Start CODE FOR LSK handler                                       */
/**********************************************************************************************************/


U16 mmi_wap_push_get_hint_from_menu_id (U16 menu_id)
{
    switch (menu_id)
    {
    case MENU_ID_SERVICE_MSG_ENABLE:
        return mmi_wap_push_get_enable_push_string();
        
    case MENU_ID_SERVICE_MSG_SL_SETTING:
        return mmi_wap_push_get_sl_setting_string();
        
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    case MENU_ID_PUSH_ENABLE_WHITE_LIST:
        return mmi_wap_push_get_enable_wl_string();
        
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */

#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    case MENU_ID_PUSH_ENABLE_BLACK_LIST:
            return mmi_wap_push_get_enable_bl_string();
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
        
    }
    return STR_GLOBAL_ERROR;
}


mmi_ret mmi_wap_push_scrhdlr_lsk_setting_menu (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wap_push_screenDB_struct *scrDB = NULL;
    mmi_wap_push_resourceDB_struct *resourceDB = NULL;
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (menu_evt->evt_id)
    {
		case EVT_ID_CUI_MENU_LIST_ENTRY:
            {
                switch (menu_evt->parent_menu_id)
                {
                case MENU_ID_SERVICE_MSG_ENABLE:
                case MENU_ID_SERVICE_MSG_SL_SETTING:
            #ifdef __MMI_WAP_PUSH_WHITE_LIST__
                case MENU_ID_PUSH_ENABLE_WHITE_LIST:
            #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */

            #ifdef __MMI_WAP_PUSH_BLACK_LIST__
                case MENU_ID_PUSH_ENABLE_BLACK_LIST:
 	        #endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
                   scrDB = mmi_wap_push_scrhdlr_get_screenDB_for_menu_id(menu_evt->parent_menu_id);
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                    if (menu_evt->cui_menu_event_flags != CUI_MENU_LIST_FROM_HISTORY)
                    {
                        cui_menu_set_currlist_highlighted_id (menu_evt->sender_id, 
                            cui_menu_get_currlist_menu_id_from_index (
                            menu_evt->sender_id, mmi_wap_push_get_sel_scr_hilited_index(
                            scrDB->scrn_id)));
                    }
                    resourceDB = mmi_wap_push_scrhdlr_get_resourceDB_for_menu_id (menu_evt->parent_menu_id);
                    cui_menu_set_currlist_title(menu_evt->sender_id, 
                        (WCHAR*) GetString(resourceDB->title_str_id), 
                        (UI_image_type) GetImage(mmi_wap_push_get_title_icon(resourceDB->title_icon_id)));
                    break;
                case MENU_ID_SERVICE_MSG_SETTING:
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                    cui_menu_set_item_hint(
                        menu_evt->sender_id, 
                        MENU_ID_SERVICE_MSG_ENABLE, 
                        (UI_string_type)GetString (mmi_wap_push_get_hint_from_menu_id (MENU_ID_SERVICE_MSG_ENABLE)));
                    cui_menu_set_item_hint(
                        menu_evt->sender_id, 
                        MENU_ID_SERVICE_MSG_SL_SETTING, 
                        (UI_string_type)GetString (mmi_wap_push_get_hint_from_menu_id (MENU_ID_SERVICE_MSG_SL_SETTING)));
                #ifdef __MMI_WAP_PUSH_WHITE_LIST__
                    cui_menu_set_item_hint(
                        menu_evt->sender_id, 
                        MENU_ID_PUSH_ENABLE_WHITE_LIST, 
                        (UI_string_type)GetString (mmi_wap_push_get_hint_from_menu_id (MENU_ID_PUSH_ENABLE_WHITE_LIST)));
                #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
				#ifdef __MMI_WAP_PUSH_BLACK_LIST__
                    cui_menu_set_item_hint(
                        menu_evt->sender_id, 
                        MENU_ID_PUSH_ENABLE_BLACK_LIST, 
                        (UI_string_type)GetString (mmi_wap_push_get_hint_from_menu_id (MENU_ID_PUSH_ENABLE_BLACK_LIST)));
                #endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
					break;
			    }
			    cui_menu_enable_center_softkey(
					menu_evt->sender_id,
					0,
					IMG_GLOBAL_COMMON_CSK);       
            }
		break;
		case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;
		case EVT_ID_CUI_MENU_ITEM_SELECT:
		case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
            switch (menu_evt->highlighted_menu_id)
            {
                case MENU_ID_PUSH_ENABLE_SETTING_ACCEPT_ALL:
                    srv_wap_push_set_enable_push(SRV_WAP_PUSH_ENABLE_SETTING_ACCEPT_ALL);
                    cui_menu_close(menu_evt->sender_id);
                    break;
            #ifdef __MMI_WAP_PUSH_WHITE_LIST__
                case MENU_ID_PUSH_ENABLE_SETTING_ACCEPT_AUTHENTICATED:
                     srv_wap_push_set_enable_push(SRV_WAP_PUSH_ENABLE_SETTING_ACCEPT_AUTHENTICATED);
                    cui_menu_close(menu_evt->sender_id);
                    break;
            #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
                case MENU_ID_PUSH_ENABLE_SETTING_DISABLE:
                    srv_wap_push_set_enable_push(SRV_WAP_PUSH_ENABLE_SETTING_DISABLE);
                    cui_menu_close(menu_evt->sender_id);
                    break;
                case MENU_ID_PUSH_SL_SETTING_PROMPT:
                    srv_wap_push_set_sl_setting(SRV_WAP_PUSH_SL_SETTING_PROMPT);
                    cui_menu_close(menu_evt->sender_id);
                    break;
                case MENU_ID_PUSH_SL_SETTING_AUTO_LAUNCH:
                    srv_wap_push_set_sl_setting(SRV_WAP_PUSH_SL_SETTING_AUTO_LAUNCH);
                    cui_menu_close(menu_evt->sender_id);
                    break;
                case MENU_ID_PUSH_SL_SETTING_DISABLE:
                    srv_wap_push_set_sl_setting(SRV_WAP_PUSH_SL_SETTING_DISABLED);
                    cui_menu_close(menu_evt->sender_id);
                    break;
            #ifdef __MMI_WAP_PUSH_WHITE_LIST__
                case MENU_ID_PUSH_WL_SETTING_DISCARD:
                    srv_wap_push_set_wl_setting(SRV_WAP_PUSH_WL_SETTING_DISCARD);
                    cui_menu_close(menu_evt->sender_id);
                    break;
                case MENU_ID_PUSH_WL_SETTING_NOTIFY:
                    srv_wap_push_set_wl_setting(SRV_WAP_PUSH_WL_SETTING_NOTIFY);
                    cui_menu_close(menu_evt->sender_id);
                    break;
                case MENU_ID_PUSH_WL_SETTING_DISABLE:
                    srv_wap_push_set_wl_setting(SRV_WAP_PUSH_WL_SETTING_DISABLE);
                    cui_menu_close(menu_evt->sender_id);
                    break;
                case MENU_ID_PUSH_WHITE_LIST:
                    g_push_set_p->selected_list_type = SRV_WAP_PUSH_WHITE_LIST;
                    mmi_wap_push_confirm_before_list_edit();
                    break;
            #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
            #ifdef __MMI_WAP_PUSH_BLACK_LIST__
                case MENU_ID_PUSH_BL_SETTING_NOTIFY:
                    srv_wap_push_set_bl_setting(SRV_WAP_PUSH_BL_SETTING_NOTIFY);
                    cui_menu_close(menu_evt->sender_id);
                    break;
                case MENU_ID_PUSH_BL_SETTING_DISABLE:
                    srv_wap_push_set_bl_setting(SRV_WAP_PUSH_BL_SETTING_DISABLE);
                    cui_menu_close(menu_evt->sender_id);
                    break;
                case MENU_ID_PUSH_BLACK_LIST:
                    g_push_set_p->selected_list_type = SRV_WAP_PUSH_BLACK_LIST;
                    mmi_wap_push_confirm_before_list_edit();
                    break;
            #endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
            }
		break;
		case EVT_ID_CUI_MENU_CLOSE_REQUEST:
			cui_menu_close(menu_evt->sender_id);
		default:
			break;
	}
	return MMI_RET_OK;
}


mmi_ret mmi_wap_push_scrhdlr_lsk_wl_options_menu (mmi_event_struct *evt)
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wap_push_screenDB_struct *scrDB = NULL;
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (menu_evt->evt_id)
    {
		case EVT_ID_CUI_MENU_LIST_ENTRY:
		    cui_menu_enable_center_softkey(
					menu_evt->sender_id,
					0,
					IMG_GLOBAL_COMMON_CSK); 
     		break;
		case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;
		case EVT_ID_CUI_MENU_ITEM_SELECT:
		case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
            switch (menu_evt->highlighted_menu_id)
            {
                case MENU_ID_PUSH_MODIFY_ADDR_LIST:
                    mmi_wap_push_modify_pre_entry();
                    break;
                case MENU_ID_PUSH_DELETE_ADDR_LIST:
                    mmi_wap_push_confirm_delete_list();
                    break;
                case MENU_ID_PUSH_DELETE_ALL_ADDR_LIST:
                    mmi_wap_push_setting_confirm_delete_all_list_entry();
                    break;
            }
		break;
		case EVT_ID_CUI_MENU_CLOSE_REQUEST:
			cui_menu_close(menu_evt->sender_id);
		default:
			break;
	}
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
	return MMI_RET_OK;
}


mmi_ret mmi_wap_push_scrhdlr_lsk_add_new_options_menu (mmi_event_struct *evt)
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wap_push_screenDB_struct *scrDB = NULL;
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (menu_evt->evt_id)
    {
		case EVT_ID_CUI_MENU_LIST_ENTRY:
			cui_menu_enable_center_softkey(
				menu_evt->sender_id,
				0,
				IMG_GLOBAL_COMMON_CSK);
     		break;
		case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;
		case EVT_ID_CUI_MENU_ITEM_SELECT:
		case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
            switch (menu_evt->highlighted_menu_id)
            {
                case MENU_ID_PUSH_ADD_NEW_PHONE_NUMBER:
                    mmi_wap_push_add_new_ph_no_pre_entry();
                    break;
                case MENU_ID_PUSH_ADD_NEW_IP_ADDR:
                    mmi_wap_push_add_new_ip_addr_pre_entry();
                    break;
            }
		break;
		case EVT_ID_CUI_MENU_CLOSE_REQUEST:
			cui_menu_close(menu_evt->sender_id);
		default:
			break;
	}
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
	return MMI_RET_OK;
}


mmi_ret mmi_wap_push_scrhdlr_lsk_msg_option_menu (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (menu_evt->evt_id)
    {
		case EVT_ID_CUI_MENU_LIST_ENTRY:
			switch (menu_evt->parent_menu_id)
			{
			case MENU_ID_PUSH_MSG_OPTION:
				{
					cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_PUSH_SERVICE_MSG_DELETE_ALL,(MMI_BOOL)!(mmi_wap_push_is_screen_present(SCR_ID_PUSH_INBOX)));
                  #ifndef __MMI_WAP_PUSH_ADVANCED_FEATURE_SLIM__
					cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_PUSH_SERVICE_MSG_SEND_BY, !mmi_wap_push_hide_send_by());
                    #endif
				}
				break;
          #ifndef __MMI_WAP_PUSH_ADVANCED_FEATURE_SLIM__
			case MENU_ID_PUSH_SERVICE_MSG_SEND_BY:
				{
					if (
					
						#if defined (__FLIGHT_MODE_SUPPORT__)
						(!srv_mode_switch_is_network_service_available()) ||
						#endif 
						(!srv_sim_ctrl_get_one_available_sim()))
					{
						cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_PUSH_SERVICE_MSG_SEND_BY_SMS, MMI_TRUE);
					}
					else
					{
						cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_PUSH_SERVICE_MSG_SEND_BY_SMS, MMI_FALSE);
					}
					#if defined(MMS_SUPPORT)
					    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_PUSH_SERVICE_MSG_SEND_BY_MMS, !mms_is_ready());
                    #else
						cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_PUSH_SERVICE_MSG_SEND_BY_MMS, MMI_TRUE);
                    #endif
					#if  defined(__MMI_EMAIL__)
					    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_PUSH_SERVICE_MSG_SEND_BY_EMAIL, !mmi_email_is_email_can_forward());
                    #else
					    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_PUSH_SERVICE_MSG_SEND_BY_EMAIL, MMI_TRUE);
                    #endif
				}
				break;
            #endif
			}
			cui_menu_enable_center_softkey(
				menu_evt->sender_id,
				0,
				IMG_GLOBAL_COMMON_CSK);
			break;
		case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;
		case EVT_ID_CUI_MENU_ITEM_SELECT:
		case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
            switch (menu_evt->highlighted_menu_id)
            {
                case MENU_ID_PUSH_SERVICE_MSG_GOTO:
                    mmi_wap_push_launch_selected_message();
                    break;
            #ifdef __MMI_WAP_PUSH_WHITE_LIST__
                case MENU_ID_PUSH_SERVICE_MSG_ADD_TO_TRUST_LIST:
                    g_srv_wap_push_cntxt->add_list_type = SRV_WAP_PUSH_WHITE_LIST;
                    mmi_wap_push_add_to_validation_list_confirm();
                    break;
            #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
			#ifdef __MMI_WAP_PUSH_BLACK_LIST__
                case MENU_ID_PUSH_SERVICE_MSG_ADD_TO_BLACK_LIST:
                    g_srv_wap_push_cntxt->add_list_type = SRV_WAP_PUSH_BLACK_LIST;
                    mmi_wap_push_add_to_validation_list_confirm();
                    break;
            #endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
            #ifndef __MMI_WAP_PUSH_ADVANCED_FEATURE_SLIM__
                case MENU_ID_PUSH_SERVICE_MSG_ADD_BOOKMARK:
                    mmi_wap_push_add_to_bookmark_list();
                    break;
                case MENU_ID_PUSH_SERVICE_MSG_SEND_BY_MMS:
                    srv_wap_push_send_by_mms();
                    break;
                case MENU_ID_PUSH_SERVICE_MSG_SEND_BY_SMS:
                    mmi_wap_push_send_by_sms();
                    break;
                case MENU_ID_PUSH_SERVICE_MSG_SEND_BY_EMAIL:
                    srv_wap_push_send_by_email();
                    break;
              #endif
                case MENU_ID_PUSH_SERVICE_MSG_DELETE:
                    mmi_wap_push_delete_from_msg_option();
                    break;
                case MENU_ID_PUSH_SERVICE_MSG_DELETE_ALL:
                    mmi_wap_push_delete_all_from_msg_option();
                    break;
            }
		break;
		case EVT_ID_CUI_MENU_CLOSE_REQUEST:
			cui_menu_close(menu_evt->sender_id);
		default:
			break;
	}
	return MMI_RET_OK;
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
	   	#if (MMI_MAX_SIM_NUM == 2)
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
			#endif /* __MMI_WAP_DUAL_SIM__ */ 
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
#if (MMI_MAX_SIM_NUM == 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #ifdef __WIFI_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif 
/* under construction !*/
#endif /*  __MMI_WAP_DUAL_SIM__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* if 0*/

mmi_ret mmi_wap_push_scrhdlr_lsk_unknwn_addr_opt_menu (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (menu_evt->evt_id)
    {
		case EVT_ID_CUI_MENU_LIST_ENTRY:
			switch (menu_evt->parent_menu_id)
			{
			#if (defined (__MMI_WAP_PUSH_WHITE_LIST__) || defined(__MMI_WAP_PUSH_BLACK_LIST__))
					case MENU_ID_PUSH_UNKNOWN_ADDR_OPTIONS:
					#ifdef __MMI_WAP_PUSH_WHITE_LIST__
						if(g_push_set_p->general_set.enable_white_list == WAP_PMG_WL_DISABLED)
						{
							cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_PUSH_UNKNOWN_ADDR_ACCEPT_AND_ADD_TO_WL, MMI_TRUE);
						}
						else
						{
							cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_PUSH_UNKNOWN_ADDR_ACCEPT_AND_ADD_TO_WL, MMI_FALSE);
						}
				    #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
					
					#ifdef __MMI_WAP_PUSH_BLACK_LIST__
						if(g_push_set_p->general_set.enable_black_list == WAP_PMG_BL_DISABLED)
						{
							cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_PUSH_UNKNOWN_ADDR_REJECT_AND_ADD_TO_BL, MMI_TRUE);
						}
						else
						{
							cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_PUSH_UNKNOWN_ADDR_REJECT_AND_ADD_TO_BL, MMI_FALSE);
						}      
					#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
				        break;
			#endif /* defined (__MMI_WAP_PUSH_WHITE_LIST__) || (__MMI_WAP_PUSH_BLACK_LIST__) */
		    }
			cui_menu_enable_center_softkey(
					menu_evt->sender_id,
					0,
					IMG_GLOBAL_COMMON_CSK);
            break;
		case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;
		case EVT_ID_CUI_MENU_ITEM_SELECT:
		case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        #ifdef __MMI_WAP_PUSH_WHITE_LIST__
            switch (menu_evt->highlighted_menu_id)
            {
                case MENU_ID_PUSH_UNKNOWN_ADDR_ACCEPT:
                    mmi_wap_push_accept_unknwn_addr_req();
                    break;
                case MENU_ID_PUSH_UNKNOWN_ADDR_REJECT:
                    mmi_wap_push_reject_unknwn_addr_req();
                    break;
                case MENU_ID_PUSH_UNKNOWN_ADDR_ACCEPT_AND_ADD_TO_WL:
                    {
                    mmi_wap_push_accept_and_add_wl_unknwn_addr_req();
                    if(srv_wap_push_check_trustlist_full())
                          srv_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_GLOBAL_MEMORY_FULL);   
                    }      
                    break;
                #ifdef __MMI_WAP_PUSH_BLACK_LIST__
                case MENU_ID_PUSH_UNKNOWN_ADDR_REJECT_AND_ADD_TO_BL:
                    {
                    mmi_wap_push_reject_and_add_bl_unknwn_addr_req();
                    if(srv_wap_push_check_blacklist_full())
                          srv_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_GLOBAL_MEMORY_FULL);
                    }
                    break;
                #endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
            }
            break;
        #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
		case EVT_ID_CUI_MENU_CLOSE_REQUEST:
			cui_menu_close(menu_evt->sender_id);
            break;
		default:
			break;
	}
	return MMI_RET_OK;
}


mmi_ret mmi_wap_push_scrhdlr_lsk_service_msg_main_menu (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (menu_evt->evt_id)
    {
		case EVT_ID_CUI_MENU_LIST_ENTRY:
            cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
			cui_menu_enable_center_softkey(
					menu_evt->sender_id,
					0,
					IMG_GLOBAL_COMMON_CSK);  
            break;
		case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;
		case EVT_ID_CUI_MENU_ITEM_SELECT:
		case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
            switch (menu_evt->highlighted_menu_id)
            {
            #ifdef __MMI_PUSH_IN_MSG__
                case MENU_ID_WAP_PUSH_INBOX:
                    mmi_brw_push_pre_entry_inbox_validation();
                    break;
                case MENU_ID_SERVICE_MSG_SETTING:
                    cui_wap_push_service_msg_setting_launch(g_push_cntxt->service_msg_cid);
                    break;
            #endif /* __MMI_PUSH_IN_MSG__ */
            }
            break;
		case EVT_ID_CUI_MENU_CLOSE_REQUEST:
			cui_menu_close(menu_evt->sender_id);
            break;
		default:
			break;
	}
	return MMI_RET_OK;
}

#ifdef __MMI_PUSH_IN_UM__
mmi_ret mmi_wap_push_scrhdlr_lsk_um_list_opt_menu (mmi_event_struct *menu_cui_evt, mmi_um_opt_para_struct * um_option_para )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)menu_cui_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (menu_evt->evt_id)
    {
		case EVT_ID_CUI_MENU_LIST_ENTRY:
            break;
		case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;
		case EVT_ID_CUI_MENU_ITEM_SELECT:
		case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
            switch (menu_evt->highlighted_menu_id)
            {
                case MENU_ID_PUSH_SERVICE_MSG_READ:
                    mmi_brw_push_delete_previous_instance_of_push();
                    um_option_para->display_flag = MMI_TRUE;
                    g_push_cntxt->um_msg_id = um_option_para->msg_id;
                    g_push_cntxt->um_parent_group_id = um_option_para->parent_grp_id;
                #ifdef __MMI_UM_ITERATOR_VIEWER__
                    g_push_cntxt->um_user_data = menu_cui_evt->user_data;
                #endif /* __MMI_UM_ITERATOR_VIEWER__ */
                    mmi_wap_push_read_message_from_um_option(um_option_para->parent_grp_id);
                    break;
                case MENU_ID_PUSH_UM_COMPILE_OPTION_MSG_DELETE:
                    mmi_brw_push_delete_previous_instance_of_push();
                    um_option_para->display_flag = MMI_TRUE;
                    g_push_cntxt->um_msg_id = um_option_para->msg_id;
                    g_push_cntxt->um_parent_group_id = um_option_para->parent_grp_id;
                    mmi_wap_push_delete_message_from_um_option();
                    break;
		        default:
                    um_option_para->display_flag = MMI_TRUE;
			        break;
            }
            break;
		default:
			break;
	}
	return MMI_RET_OK;
}
#endif /* __MMI_PUSH_IN_UM__ */


void mmi_wap_push_dummy_screen_show (void)
{
    mmi_frm_scrn_enter(
            GRP_ID_BRW_PUSH_DUMMY, 
            SCR_ID_BRW_PUSH_DUMMY_SCREEN, 
            NULL, 
            mmi_wap_push_dummy_screen_show, 
            MMI_FRM_FULL_SCRN);

}

void mmi_wap_push_dummy_screen (mmi_id  group_id)
{
     
   /* mmi_frm_group_create(group_id, 
                         GRP_ID_BRW_PUSH_DUMMY,
                         mmi_dummy_proc,
                         (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_BRW_PUSH_DUMMY , MMI_FRM_NODE_SMART_CLOSE_FLAG);
    */
    mmi_frm_group_create_ex(group_id, 
                         GRP_ID_BRW_PUSH_DUMMY,
                         mmi_dummy_proc,
                         (void*)NULL,
                         MMI_FRM_NODE_SMART_CLOSE_FLAG); 
    mmi_wap_push_dummy_screen_show();
}
#endif /* WAP_SUPPORT*/
