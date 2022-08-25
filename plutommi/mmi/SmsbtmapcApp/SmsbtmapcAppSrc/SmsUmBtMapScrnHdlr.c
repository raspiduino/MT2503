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
 * UMScrHdlr.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_BT_MAP_CLIENT__

#ifdef __MMI_UM_CONVERSATION_BOX__
#undef __MMI_UM_CONVERSATION_BOX__
#endif

#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
#undef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
#endif

#include "mmi_rp_app_smsbtunifiedmessage_def.h"
#include "mmi_rp_app_sms_def.h"
#include "SmsUmBtMapGProt.h"
#include "SmsUmBtMapProt.h"
#include "GlobalResDef.h"
#include "DateTimeType.h"
#include "Gpiosrvgprot.h"
#include "Custom_mmi_default_value.h"
#include "app_datetime.h"
#include "mmi_rp_app_unifiedmessage_def.h"
#include "SmsBtMapCSrvGProt.h"
#include "mmi_features.h"
#include "Wgui_fixed_menus.h" // This header file is included to SSC support 
#include "BtcmSrvGprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_softkeys.h"

typedef enum
{
    MMI_SMS_UM_BT_UI_ENTRY_MAIN_MENU
} mmi_sms_um_bt_ui_main_menu_delete_folder_enum;

extern mmi_sms_bt_cntx_struct *g_sms_bt_ui_p;
extern mmi_sms_bt_entry_folder_userdata g_ef_usdata;
extern NMGR_HANDLE g_new_bt_msg_handle;
extern U8 g_new_bt_msg_dev_mask;

extern srv_sms_btmapc_bt_enum	g_sms_active_dev_index;	   /* Bt index ID */


static S32 mmi_sms_um_bt_ui_mainmenu_req_msg_num_cb(S32 pid, srv_um_get_msg_num_result *rsp, S32 para);
static MMI_BOOL mmi_sms_um_bt_ui_sh_main_msg_get_num(mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx);
SrvSmsCallbackFunc mmi_sms_bt_get_callback_hdlr(srv_um_msg_btmapc_box_enum box_enum);

typedef void (*mmi_sms_um_bt_ui_sh_key_hdlr)(void);
typedef void (*mmi_sms_um_bt_ui_sh_hilite_hdlr)(S32 index);

mmi_sms_bt_context_struct g_sms_bt_cntx;

MMI_BOOL g_sms_bt_aprc_enter_tab = MMI_FALSE;
//mmi_sms_um_bt_ui_cc_scrn_cntx_struct g_sms_bt_sh_get_item_scrn_cntx = {0};
mmi_sms_um_bt_ui_cc_scrn_cntx_struct * g_sms_bt_sh_get_item_scrn_cntx = NULL;

mmi_sms_um_bt_ui_aprc_263_struct g_sms_bt_aprc_int_cntx = {0};
srv_um_msg_btmapc_box_enum g_sms_bt_mmi_box_type = SRV_UM_MSG_BTMAPC_BOX_NONE;

extern mmi_um_tab_page g_tab_last_enter;
extern mmi_um_tab_page g_tab_curr_first_enter;
extern fixed_list_menu MMI_fixed_list_menu;
extern MMI_BOOL g_exit_folder;




static MMI_RET mmi_sms_um_bt_ui_app_proc(mmi_event_struct *evt)
{
	return MMI_RET_OK;
}

void mmi_sms_um_bt_entry_main_message_menu(void)
{
	mmi_sms_um_bt_entry_main_message_menu_int();
}
mmi_ret mmi_sms_um_bt_ui_package_proc(mmi_event_struct *evt)
{
	return MMI_RET_OK;
}

MMI_BOOL mmi_sms_um_bt_ui_sh_tsfr_fsm_event(U16 sh_evt, mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx, void *arg)
{
    U16 fsm_event;

    fsm_event = mmi_sms_um_bt_ui_ut_get_fsm_event_by_ui_event(sh_evt);
    return scrn_cntx->fsm.event_hdlr(scrn_cntx->scrn_id, fsm_event, arg);
}

void mmi_sms_um_bt_ui_sh_set_general_cntx(
        mmi_sms_um_bt_ui_aprc_general_cntx_struct *general_aprc_cntx, 
        U16 group_id, 
        U16 disp_scrn_id, 
        U16 menu_item_id, 
        U16 title_str_id, 
        U16 title_icon_id, 
        U16 lsk_str_id, 
        U16 lsk_icon_id, 
        U16 rsk_str_id, 
        U16 rsk_icon_id, 
        U16 csk_icon_id, 
        mmi_sms_um_bt_ui_sh_hilite_hdlr hilite_hdlr, 
        U16 hilite_idx, 
        U16 num_of_item, 
        mmi_sms_um_entry_func_ptr entry_func, 
        mmi_sms_um_entry_func_ptr exit_func, 
        U8 *gui_buffer, 
        mmi_sms_um_bt_ui_sh_key_hdlr lsk, 
        mmi_sms_um_bt_ui_sh_key_hdlr rsk, 
        mmi_sms_um_bt_ui_sh_key_hdlr csk, 
        mmi_proc_func leave_proc)
{
    /* General context */
    general_aprc_cntx->grp_id = group_id;
    general_aprc_cntx->scrn_id = disp_scrn_id;
    general_aprc_cntx->menu_item_id = menu_item_id;
    general_aprc_cntx->title_str_id = title_str_id;
    general_aprc_cntx->title_icon_id = title_icon_id;
    general_aprc_cntx->lsk_str_id = lsk_str_id;
    general_aprc_cntx->lsk_icon_id = lsk_icon_id;
    general_aprc_cntx->rsk_str_id = rsk_str_id;
    general_aprc_cntx->rsk_icon_id = rsk_icon_id;
    general_aprc_cntx->csk_icon_id = csk_icon_id;
    general_aprc_cntx->hilite_hdlr = hilite_hdlr;
    general_aprc_cntx->hilite_idx = hilite_idx;
    general_aprc_cntx->num_of_item = num_of_item;
    general_aprc_cntx->entry_func = entry_func;
    general_aprc_cntx->exit_func = exit_func;
    general_aprc_cntx->gui_buffer = gui_buffer;
    general_aprc_cntx->key_hdlr.lsk_hdlr = lsk;
    general_aprc_cntx->key_hdlr.rsk_hdlr = rsk;
    general_aprc_cntx->key_hdlr.csk_hdlr = csk;
    general_aprc_cntx->leave_proc = leave_proc;
}
void mmi_sms_um_bt_ui_sh_setting_write_msg_entry(mmi_scrn_essential_struct *arg, U16 type)
{
	return;
}



/*****************************************************************************
 * FUNCTION
 * mmi_sms_um_bt_ui_sh_main_msg_entry_inbox
 * DESCRIPTION
 *  Entry inbox from main message menu.
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_bt_main_msg_entry_box(srv_um_msg_btmapc_box_enum msg_box)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	switch(msg_box)
	{
	case SRV_UM_MSG_BTMAPC_BOX_INBOX:
		{
			mmi_sms_um_bt_ui_if_entry_general(0, GRP_ID_ROOT, MMI_TRUE, MMI_SMS_UM_BT_ENTRY_SCREEN_GENERAL_FOLDER, NULL);
			mmi_sms_um_bt_ui_sh_main_msg_entry_inbox();
			break;
		}

	case SRV_UM_MSG_BTMAPC_BOX_OUTBOX:
		{
			mmi_sms_um_bt_ui_if_entry_general(0, GRP_ID_ROOT, MMI_TRUE, MMI_SMS_UM_BT_ENTRY_SCREEN_GENERAL_FOLDER, NULL);
			mmi_sms_um_bt_ui_sh_main_msg_entry_sent();
			break;
		}

	case SRV_UM_MSG_BTMAPC_BOX_DRAFTS:
		{
			mmi_sms_um_bt_ui_if_entry_general(0, GRP_ID_ROOT, MMI_TRUE, MMI_SMS_UM_BT_ENTRY_SCREEN_GENERAL_FOLDER, NULL);
			mmi_sms_um_bt_ui_sh_main_msg_entry_draft();
			break;
		}

	case SRV_UM_MSG_BTMAPC_BOX_UNSENT:
		{
			mmi_sms_um_bt_ui_if_entry_general(0, GRP_ID_ROOT, MMI_TRUE, MMI_SMS_UM_BT_ENTRY_SCREEN_GENERAL_FOLDER, NULL);
			mmi_sms_um_bt_ui_sh_main_msg_entry_outbox();
			break;
		}

	default:
		ASSERT(0);
	}
}
void mmi_sms_um_bt_ui_sh_main_msg_clear_folder_hint_by_menu_id(U16 menu_id, U8 **hint_ptr, U16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_test_menu_item_hide(menu_id))
    {
        index = GetIndexOfStringId_Ext(MAIN_MENU_SMS_BT_MESSAGES_MENUID, menu_id);
        if (NULL == hint_ptr[index])
        {
            /* set as global */
            hint_ptr[index] = hintData[index];
        }
        memset(hint_ptr[index], 0, sizeof(length));
    }
}
void mmi_sms_um_bt_ui_sh_main_msg_clear_folder_hint(U8 **popup_list, U16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_sh_main_msg_clear_folder_hint_by_menu_id(MENU_ID_SMS_UM_INBOX, popup_list, length);
    mmi_sms_um_bt_ui_sh_main_msg_clear_folder_hint_by_menu_id(MENU_ID_SMS_UM_DRAFT, popup_list, length);
    mmi_sms_um_bt_ui_sh_main_msg_clear_folder_hint_by_menu_id(MENU_ID_SMS_UM_UNSENT, popup_list, length);
    mmi_sms_um_bt_ui_sh_main_msg_clear_folder_hint_by_menu_id(MENU_ID_SMS_UM_SENT, popup_list, length);
}

void mmi_sms_um_bt_ui_sh_main_msg_delete_folder_entry(mmi_scrn_essential_struct *arg, U16 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 str_id_item_list[MAX_SUB_MENUS];
    U16 item_icons[MAX_SUB_MENUS];
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_um_bt_ui_aprc_st_union aprc_union;
    mmi_sms_um_bt_ui_aprc_st_main_menu_struct *aprc;
    mmi_um_entry_main_msg_evt_struct entry_main_msg_evt;
    U16 menu_id;
    mmi_sms_um_entry_func_ptr entry_func = mmi_sms_um_bt_ui_sh_main_msg_entry; 
    mmi_sms_um_entry_func_ptr exit_func = mmi_sms_um_bt_ui_sh_main_msg_exit; 
    mmi_sms_um_bt_ui_sh_hilite_hdlr hilite_hdlr =  mmi_sms_um_bt_ui_sh_main_msg_hilite_hdlr;
    mmi_sms_um_bt_ui_sh_key_hdlr lsk = NULL; 
    mmi_sms_um_bt_ui_sh_key_hdlr csk = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&aprc_union, 0, sizeof(mmi_sms_um_bt_ui_aprc_st_union));
    aprc = &(aprc_union.main_menu);
    scrn_cntx = (mmi_sms_um_bt_ui_cc_scrn_cntx_struct *)arg->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    {
        /* Arrange the menu items */
        mmi_sms_um_bt_ui_sh_main_msg_arrange_menu_item(scrn_cntx);
        menu_id = MAIN_MENU_SMS_BT_MESSAGES_MENUID;
    }
    mmi_sms_um_bt_ui_sh_set_general_cntx(
            &aprc->general_aprc_cntx, 
            scrn_cntx->group_id, 
            scrn_cntx->screen_hdlr.disp_scrn_id, 
            menu_id, 
            STR_ID_SMS_UM_BT_MAIN_MENU_MESSAGES_TEXT, 
            IMG_UM_ENTRY_SCRN_CAPTION, 
            STR_GLOBAL_OK, 
            IMG_GLOBAL_OK, 
            STR_GLOBAL_BACK, 
            IMG_GLOBAL_BACK, 
            IMG_GLOBAL_COMMON_CSK, 
            hilite_hdlr, 
            0, 
            GetNumOfChild_Ext(menu_id), 
            entry_func, 
            exit_func, 
            NULL, 
            lsk, 
            mmi_sms_um_bt_ui_sh_general_folder_rsk_hdlr, 
            csk, 
            mmi_sms_um_bt_ui_sh_general_folder_leave_proc);

    /* Specified context */
    /* Construct the menu item strings */
    GetSequenceStringIds_Ext(menu_id, str_id_item_list);
    MMI_ASSERT(MAX_SUB_MENUS >= aprc->general_aprc_cntx.num_of_item);

    /* Copy to global buffer and use the global buffer pointer */
    for (i = 0; i < aprc->general_aprc_cntx.num_of_item; i++)
    {
        mmi_ucs2cpy((CHAR*)subMenuData[i], (CHAR*)get_string((MMI_ID_TYPE)str_id_item_list[i]));
    }
    aprc->list_of_items = (U8 **)subMenuDataPtrs;
    GetSequenceImageIds_Ext(menu_id, item_icons);
    ConstructHintsList(menu_id, hintDataPtrs);
    /* Clear the folder hint string */
    aprc->list_of_item_hints = NULL;
    aprc->list_of_item_icons = (U16 *)item_icons;

    if (mmi_is_redrawing_bk_screens() == MMI_TRUE)
    {
        return;
    }

    /* inform FSM to check the current data */
    mmi_sms_um_bt_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_CHECK, NULL);

    {
        /* Send the event out */
		MMI_FRM_INIT_EVENT(&entry_main_msg_evt, EVT_ID_MMI_SMS_UM_BT_ENTRY_MAIN_MSG);
        entry_main_msg_evt.is_entry = MMI_TRUE;
        entry_main_msg_evt.um_user_data = (void *)scrn_cntx;
        MMI_FRM_CB_EMIT_POST_EVENT(&entry_main_msg_evt);
    }
}

MMI_BOOL mmi_sms_um_bt_ui_sh_mainmenu_fsm_init(
                    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx, 
                    mmi_sms_um_bt_ui_cc_scrn_cntx_setting_struct *setting, 
                    U16 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;
    /* FSM initialize */
    {
        mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx = &(scrn_cntx->fsm);
        mmi_sms_um_bt_ui_fsm_entry_list_struct *fsm;
        fsm = &(fsm_cntx->cntx.fsm_entry_list);
        memset(fsm, 0, sizeof(mmi_sms_um_bt_ui_fsm_entry_list_struct));
        
        /* External setting */
        fsm->scrn_id = scrn_cntx->scrn_id;
        fsm->req_folder_type= setting->folder;
        fsm->get_msg_num = mmi_sms_um_bt_ui_fsm_el_get_msg_num;
        /* Internal setting */
        fsm->pid = 0;
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_NONE;
        memset(&(fsm->req_msg_num_result), 0, sizeof(srv_um_get_msg_num_result));
    }
    /* Appearance initialize */
    mmi_sms_um_bt_ui_aprc_set_cntx(&(scrn_cntx->aprc), setting->aprc_type);

    /* Screen handler initialize */
    scrn_cntx->screen_hdlr.disp_scrn_id = setting->disp_scrn_id;
    scrn_cntx->screen_hdlr.folder_type = setting->folder;
    memset(&(scrn_cntx->screen_hdlr.hilite_info), 0, sizeof(mmi_sms_um_bt_ui_sh_hilite_info_struct));
    scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_FALSE;
    scrn_cntx->screen_hdlr.num_of_item = 0;
    scrn_cntx->screen_hdlr.scrn_data = setting->scrn_data;

    return result;
}

MMI_BOOL mmi_sms_um_bt_ui_sh_main_msg_init(
                    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx, 
                    mmi_sms_um_bt_ui_cc_scrn_cntx_setting_struct *setting)
{
    return mmi_sms_um_bt_ui_sh_mainmenu_fsm_init(scrn_cntx, setting, 1);
}

MMI_BOOL mmi_sms_um_bt_ui_sh_main_msg_proc_interanl(U16 scrn_id, U16 event, mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    switch (event)
    {
        case MMI_UM_UI_EVENT_INIT:
            MMI_ASSERT(scrn_cntx->screen_hdlr.is_scrn_displayed == MMI_FALSE);
            scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_TRUE;
            mmi_sms_um_bt_ui_sh_create(mmi_sms_um_bt_ui_sh_main_msg_entry, scrn_cntx);
            break;
            
        case MMI_UM_UI_EVENT_CHECK:
        case MMI_UM_UI_EVENT_READY:
        case MMI_UM_UI_EVENT_REFRESH:
            mmi_sms_um_bt_ui_sh_main_msg_get_num(scrn_cntx);
           /* no break here, so it will reset message number using code below. */
        case MMI_UM_UI_EVENT_UNREADY:
            mmi_sms_um_bt_ui_sh_main_msg_reset(scrn_cntx);
    }
    return MMI_TRUE;
}

static MMI_BOOL mmi_sms_um_bt_ui_sh_main_msg_get_num(mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    MMI_BOOL is_processing = MMI_FALSE;
    mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx = &(scrn_cntx->fsm);
    mmi_sms_um_bt_ui_fsm_entry_list_struct *fsm;
    fsm = &(fsm_cntx->cntx.fsm_entry_list);

    if (mmi_sms_um_bt_ui_int_is_available())
    {
        if (fsm->pid == 0)
        {
            fsm->req_srv_status = MMI_UM_UI_REQ_SRV_PROGRESS;
            //fsm->pid = srv_um_get_msg_num(
            //                fsm->req_folder_type.msg_type, 
            //                fsm->req_folder_type.sim_id, 
            //                mmi_sms_um_bt_ui_mainmenu_req_msg_num_cb, 
            //                fsm->scrn_id);
            fsm->pid=srv_sms_um_bt_get_msg_num(
                            fsm->req_folder_type.msg_type, 
                            fsm->req_folder_type.sim_id, 
                            mmi_sms_um_bt_ui_mainmenu_req_msg_num_cb, 
                            fsm->scrn_id);
            if (MMI_UM_UI_REQ_SRV_NONE == fsm->req_srv_status) /* sync callback, reset pid here */
            {
                fsm->pid = 0;
            }
            is_processing = MMI_TRUE;
        }
    }
    return is_processing;
}
static S32 mmi_sms_um_bt_ui_mainmenu_req_msg_num_cb(S32 pid, srv_um_get_msg_num_result *rsp, S32 para)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx;
    mmi_sms_um_bt_ui_fsm_entry_list_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check pid if invalid */
    
    scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx((U16)para);
    
    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_list);

    //if((pid != 0) && (pid == fsm->pid))
    {
        memcpy(&(fsm->req_msg_num_result), rsp, sizeof(srv_um_get_msg_num_result));
        mmi_sms_um_bt_ui_sh_main_msg_update(scrn_cntx);
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_NONE;
        fsm->pid = 0;
    }
    return SRV_UM_RESULT_OK;
}

MMI_BOOL mmi_sms_um_bt_ui_sh_main_msg_event_hdlr(U16 scrn_id, U16 event, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    result = MMI_TRUE;
    switch (event)
    {
        case MMI_UM_UI_EVENT_INIT:
        case MMI_UM_UI_EVENT_ABORT:
        case MMI_UM_UI_EVENT_CHECK:
        case MMI_UM_UI_EVENT_READY:
        case MMI_UM_UI_EVENT_UNREADY:
        case MMI_UM_UI_EVENT_REFRESH:
        {
        #ifndef __MMI_UM_EL_FSM_SUPPORT__
            result = mmi_sms_um_bt_ui_sh_main_msg_proc_interanl(scrn_id,event,scrn_cntx);
        #else
            result = mmi_sms_um_bt_ui_sh_tsfr_fsm_event(event,scrn_cntx,arg);
        #endif
            break;
        }
        case MMI_UM_UI_EVENT_DELETE:
        {
            mmi_sms_um_bt_ui_sh_evt_hdlr_delete(scrn_cntx, arg);
            break;
        }
        case MMI_UM_UI_EVENT_DELETED:
        {
            /* Set child screen as 0 */
            scrn_cntx->child_scrn_id = 0;
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}
void mmi_sms_um_bt_ui_sh_main_msg_entry(mmi_scrn_essential_struct *arg)
{
    mmi_sms_um_bt_ui_sh_main_msg_delete_folder_entry(arg, MMI_SMS_UM_BT_UI_ENTRY_MAIN_MENU);
}
void mmi_sms_um_bt_ui_sh_main_msg_exit(mmi_scrn_essential_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_entry_main_msg_evt_struct entry_main_msg_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Send the event out */
    //MMI_FRM_INIT_EVENT(&entry_main_msg_evt, EVT_ID_MMI_SMS_UM_BT_ENTRY_MAIN_MSG);
	MMI_FRM_INIT_EVENT(&entry_main_msg_evt, EVT_ID_MMI_SMS_UM_BT_ENTRY_MAIN_MSG);
    entry_main_msg_evt.is_entry = MMI_FALSE;
    entry_main_msg_evt.um_user_data = (void *)arg->user_data;
    MMI_FRM_CB_EMIT_POST_EVENT(&entry_main_msg_evt);
}
void mmi_sms_um_main_menu_general_highlight(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(f, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(f, KEY_EVENT_UP);
}
void mmi_sms_um_bt_ui_sh_main_msg_hilite_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_id = GetSeqItemId_Ext(MAIN_MENU_SMS_BT_MESSAGES_MENUID, (U16)index);
    switch (menu_id)
    {
        case MENU_ID_SMS_UM_WRITE_MSG:
        {
            mmi_sms_um_main_menu_general_highlight(mmi_sms_um_bt_ui_sh_main_msg_entry_write_msg);
            break;
        }
        case MENU_ID_SMS_UM_INBOX:
        {
            mmi_sms_um_main_menu_general_highlight(mmi_sms_um_bt_ui_sh_main_msg_entry_inbox);
            break;
        }
        case MENU_ID_SMS_UM_DRAFT:
        {
            mmi_sms_um_main_menu_general_highlight(mmi_sms_um_bt_ui_sh_main_msg_entry_draft);
            break;
        }
        case MENU_ID_SMS_UM_UNSENT:
        {
            mmi_sms_um_main_menu_general_highlight(mmi_sms_um_bt_ui_sh_main_msg_entry_outbox);
            break;
        }
        case MENU_ID_SMS_UM_SENT:
        {
            mmi_sms_um_main_menu_general_highlight(mmi_sms_um_bt_ui_sh_main_msg_entry_sent);
            break;
        }
        default:
        {
            ExecuteCurrHiliteHandler(index);
            break;
        }
    }
}
void mmi_sms_um_bt_ui_sh_main_msg_delete_folder_update(void *arg, U16 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 num_of_item;
    U16 str_id_item_list[MAX_SUB_MENUS];
    U16 item_icons[MAX_SUB_MENUS];
    sms_um_bt_get_msg_num_result *msg_num_info;
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_um_bt_ui_aprc_st_union aprc_union;
    mmi_sms_um_bt_ui_aprc_st_main_menu_struct *aprc;
    U16 menu_id = MAIN_MENU_SMS_BT_MESSAGES_MENUID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&aprc_union, 0, sizeof(mmi_sms_um_bt_ui_aprc_st_union));
    aprc = &(aprc_union.main_menu);
    scrn_cntx = (mmi_sms_um_bt_ui_cc_scrn_cntx_struct *)arg;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    mmi_sms_um_bt_ui_fsm_el_get_msg_num(scrn_cntx->scrn_id, &msg_num_info);
    /* Update the stirng of folder menu item */
    if (mmi_frm_scrn_get_active_id() != scrn_cntx->screen_hdlr.disp_scrn_id)
    {
        return;
    }
    menu_id = MAIN_MENU_SMS_BT_MESSAGES_MENUID;
    i = 0;
    num_of_item = 0;
    memset(str_id_item_list, 0, sizeof(str_id_item_list));
    num_of_item = GetSequenceStringIds_Ext(menu_id, str_id_item_list);
    MMI_ASSERT(MAX_SUB_MENUS >= num_of_item);

    if (type == 0)
    {
        ConstructHintsList(MAIN_MENU_SMS_BT_MESSAGES_MENUID, hintDataPtrs);
    }
    /* Construct the menu item strings */
    aprc->general_aprc_cntx.num_of_item = num_of_item;
#ifdef __MMI_MESSAGE_MAIN_MENU_HINT_INLINE__
    if (type == MMI_SMS_UM_BT_UI_ENTRY_MAIN_MENU)
    {
        mmi_sms_um_bt_ui_sh_main_msg_update_item(subMenuDataPtrs, msg_num_info);
    }
    aprc->list_of_items = subMenuDataPtrs;
    aprc->list_of_item_hints = NULL;
#else /* __MMI_MESSAGE_MAIN_MENU_HINT_INLINE__ */
    for (i = 0; i < num_of_item; i++)
    {
        mmi_ucs2cpy((CHAR*)subMenuData[i], (CHAR*)get_string((MMI_ID_TYPE)str_id_item_list[i]));
        memset(hintData[i], 0, MAX_SUB_MENU_HINT_SIZE);
        hintDataPtrs[i] = hintData[i];
    }
    if (type == MMI_SMS_UM_BT_UI_ENTRY_MAIN_MENU)
    {
        //mmi_sms_um_bt_ui_sh_main_msg_update_item_hint(hintDataPtrs, msg_num_info);
    }
    aprc->list_of_items = subMenuDataPtrs;
    aprc->list_of_item_hints = hintDataPtrs;
#endif /* __MMI_MESSAGE_MAIN_MENU_HINT_INLINE__ */
    GetSequenceImageIds_Ext(MAIN_MENU_SMS_BT_MESSAGES_MENUID, item_icons);
    aprc->list_of_item_icons = item_icons;
    
    scrn_cntx->aprc.redraw_func(&aprc_union, scrn_cntx->aprc.st_type, MMI_UM_UI_APRC_REDRAW_BODY);
}

void mmi_sms_um_bt_ui_sh_main_msg_update(void *arg)
{
    mmi_sms_um_bt_ui_sh_main_msg_delete_folder_update(arg, 0);
}
void mmi_sms_um_bt_ui_sh_main_msg_update_item(U8 **item_string, srv_um_get_msg_num_result *msg_num_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 num_of_item;
    U16 menu_id_idx;
    U16 item_str_id[MAX_SUB_MENUS];
    U8 hint_asc[MAX_SUB_MENU_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_num_info != NULL);
    
    num_of_item = GetSequenceStringIds_Ext(MAIN_MENU_SMS_BT_MESSAGES_MENUID, item_str_id);
    MMI_ASSERT(MAX_SUB_MENUS >= num_of_item);

    for (i = 0; i < num_of_item; i++)
    {
        /* Only copy UM menu item */
        menu_id_idx = GetSeqItemId_Ext(MAIN_MENU_SMS_BT_MESSAGES_MENUID, i);
        if (MENU_ID_UM_INBOX    == menu_id_idx ||
            MENU_ID_UM_DRAFT    == menu_id_idx ||
            MENU_ID_UM_UNSENT   == menu_id_idx ||
            MENU_ID_UM_SENT     == menu_id_idx ||
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            MENU_ID_UM_ARCHIVE  == menu_id_idx ||
        #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
        #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
            MENU_ID_UM_SIM      == menu_id_idx ||
        #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
        #ifdef __MMI_UM_REPORT_BOX__
            MENU_ID_UM_REPORT   == menu_id_idx ||
        #endif /* __MMI_UM_REPORT_BOX__ */
            MMI_TRUE)
        {
            mmi_ucs2cpy((CHAR*)item_string[i], (CHAR*)get_string((MMI_ID_TYPE)item_str_id[i]));
        }
        else
        {
            /* Do not need to redraw */
            item_string[i] = NULL;
        }
    }

    /* Inbox */
    if (!mmi_frm_test_menu_item_hide(MENU_ID_UM_INBOX))
    {
        i = GetIndexOfStringId_Ext(MAIN_MENU_SMS_BT_MESSAGES_MENUID, MENU_ID_UM_INBOX);
        sprintf((CHAR *)hint_asc, " (%d/%d)", msg_num_info->inbox_unread_msg_number, msg_num_info->inbox_msg_number);
        //mmi_sms_um_bt_ui_ut_concate_str_with_num((CHAR *)hint_asc, (CHAR *)item_string[i]);
    }

    /* Draft, outbox, sent */
    mmi_sms_um_bt_ui_ut_update_item_by_menu_id(MAIN_MENU_SMS_BT_MESSAGES_MENUID, MENU_ID_UM_DRAFT, item_string, msg_num_info->draft_msg_number);
    mmi_sms_um_bt_ui_ut_update_item_by_menu_id(MAIN_MENU_SMS_BT_MESSAGES_MENUID, MENU_ID_UM_UNSENT, item_string, msg_num_info->unsent_msg_number);
    mmi_sms_um_bt_ui_ut_update_item_by_menu_id(MAIN_MENU_SMS_BT_MESSAGES_MENUID, MENU_ID_UM_SENT, item_string, msg_num_info->sent_msg_number);
}

void mmi_sms_um_bt_ui_sh_main_msg_reset(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 num_of_item;
    U16 str_id_item_list[MAX_SUB_MENUS];
    U16 item_icons[MAX_SUB_MENUS];
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_um_bt_ui_aprc_st_union aprc_union;
    mmi_sms_um_bt_ui_aprc_st_main_menu_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&aprc_union, 0, sizeof(mmi_sms_um_bt_ui_aprc_st_union));
    aprc = &(aprc_union.main_menu);
    memset(&aprc_union, 0, sizeof(mmi_sms_um_bt_ui_aprc_struct_union));
    scrn_cntx = (mmi_sms_um_bt_ui_cc_scrn_cntx_struct *)arg;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* Update the stirng of folder menu item */
    if (MMI_SCENARIO_STATE_ACTIVE != 
        mmi_frm_scrn_get_state(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id))
    {
        return;
    }

    i = 0;
    num_of_item = 0;
    memset(str_id_item_list, 0, sizeof(str_id_item_list));
    num_of_item = GetSequenceStringIds_Ext(MAIN_MENU_SMS_BT_MESSAGES_MENUID, str_id_item_list);
    MMI_ASSERT(MAX_SUB_MENUS >= num_of_item);

    /* Construct the menu item strings */
    aprc->general_aprc_cntx.num_of_item = num_of_item;
    for (i = 0; i < num_of_item; i++)
    {
        mmi_ucs2cpy((CHAR*)subMenuData[i], (CHAR*)get_string((MMI_ID_TYPE)str_id_item_list[i]));
    }
    ConstructHintsList(MAIN_MENU_SMS_BT_MESSAGES_MENUID, hintDataPtrs);
    /* Clear the folder hint string */
    //mmi_sms_um_bt_ui_sh_main_msg_clear_folder_hint(hintDataPtrs, MAX_SUB_MENU_HINT_SIZE);

    aprc->list_of_items = subMenuDataPtrs;
    aprc->list_of_item_hints = hintDataPtrs;
    GetSequenceImageIds_Ext(MAIN_MENU_SMS_BT_MESSAGES_MENUID, item_icons);
    aprc->list_of_item_icons = item_icons;
    
    //scrn_cntx->aprc.redraw_func(&aprc_union, scrn_cntx->aprc.st_type, MMI_UM_UI_APRC_REDRAW_BODY);
}
void mmi_sms_um_bt_ui_sh_main_msg_entry_folder(srv_um_msg_btmapc_box_enum msg_box, U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_nubmer_got = MMI_FALSE;
    U16 number;
    srv_sms_um_box_identity_struct folder;
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx_folder;
    sms_um_bt_get_msg_num_result *msg_num_info;
    U16 tmp_scrn_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    number=srv_sms_btmapc_get_list_size(msg_box);
    kal_prompt_trace(MOD_MMI, "[SMS], Entry cui_tab_enter  g_sms_bt_ui_p->bt_active_index = %d", g_sms_um_ui_main_menu_scrn_id);
    if (g_sms_um_ui_main_menu_scrn_id != 0)
    {
        scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx(scrn_id);
        CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);


        if (mmi_sms_um_bt_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id))
        {
            //mmi_sms_um_bt_ui_ut_del_relative_scrn(&(scrn_cntx->child_scrn_id));
            kal_prompt_trace(MOD_MMI, "[SMS], Entry mmi_sms_um_bt_ui_sh_main_msg_entry_folder mmi_sms_um_bt_ui_cc_check_scrn_alive");
        }
        
        scrn_cntx->fsm.cntx.fsm_entry_list.get_msg_num(scrn_cntx->scrn_id, &msg_num_info);
        folder.msg_box_type = msg_box;
        folder.msg_type = g_sms_um_ui_p->setting.support_msg_type;
        folder.sim_id = SRV_UM_SIM_ALL;
        tmp_scrn_id = scrn_cntx->child_scrn_id;
        scrn_cntx->child_scrn_id = mmi_sms_um_bt_ui_if_entry_general(scrn_cntx->scrn_id, scrn_cntx->group_id, MMI_FALSE, MMI_SMS_UM_BT_ENTRY_SCREEN_GENERAL_FOLDER, &folder);
        scrn_cntx_folder = mmi_sms_um_bt_ui_cc_get_scrn_cntx(scrn_cntx->child_scrn_id);
        scrn_cntx_folder->child_scrn_id = tmp_scrn_id;
        //number = mmi_sms_um_bt_ui_ut_get_msg_num_by_msg_box(msg_box, msg_num_info);
        
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_BT_MSG_GET_BOX_NUMBER, msg_box, number);
        {
            mmi_sms_um_bt_ui_fsm_entry_list_struct * fsm_node = &scrn_cntx->fsm.cntx.fsm_entry_list;
            is_nubmer_got = (MMI_BOOL)(fsm_node->pid == 0);
        }
        if (0 == number && is_nubmer_got)
        {
            number = 0xffff;
        #if !defined(__MMI_UM_FILTER_BY_SIM_SUPPORT__)
            mmi_sms_um_bt_ui_cc_send_event(scrn_cntx->child_scrn_id, MMI_UM_UI_EVENT_SET_NUM_MSG_INSIDE, &number);
        #endif
        }
        mmi_sms_um_bt_ui_ut_send_init_event(scrn_cntx->child_scrn_id);
    }
    else
    {
        folder.msg_box_type = msg_box;
        folder.msg_type = SRV_UM_MSG_SMS;
        folder.sim_id = SRV_UM_SIM_ALL;
        tmp_scrn_id = mmi_sms_um_bt_ui_if_entry_general(0, (g_sms_um_ui_p->cc_cntx.grp_table[0].grp_id), MMI_FALSE, MMI_SMS_UM_BT_ENTRY_SCREEN_GENERAL_FOLDER, &folder);

        if (0 == number)
        {
            //number = 0xffff;
        #if !defined(__MMI_UM_FILTER_BY_SIM_SUPPORT__)
            //mmi_sms_um_bt_ui_cc_send_event(tmp_scrn_id, MMI_UM_UI_EVENT_SET_NUM_MSG_INSIDE, &number);
        #endif
        }
        mmi_sms_um_bt_ui_ut_send_init_event(tmp_scrn_id);
    }
}


void mmi_sms_bt_get_inbox_list_cb(srv_sms_callback_struct* data)
{
    mmi_sms_bt_entry_folder_userdata *userdata = data->user_data; 

    g_sms_bt_ui_p[userdata->bt_index].is_on_request = MMI_FALSE;
    g_sms_bt_ui_p[userdata->bt_index].need_refresh[MMI_SMS_BT_BOX_INBOX] = MMI_FALSE;
    if(data->result == MMI_TRUE)
    {
        //mmi_sms_bt_entry_folder_userdata *userdata = data->user_data;        
        g_sms_bt_ui_p[userdata->bt_index].last_entered = SRV_SMS_BTMAPC_BOX_INBOX;
        if((((*g_sms_um_ui_p).cc_cntx).grp_table[0].grp_id != 0) && 
            g_sms_active_dev_index == userdata->bt_index &&
            g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered == SRV_SMS_BTMAPC_BOX_INBOX)
        {
            mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
            srv_um_msg_btmapc_box_enum box_type = SRV_UM_MSG_BTMAPC_BOX_INBOX;
			if (g_new_bt_msg_handle)
			{
				if(userdata->bt_index == SRV_SMS_BTMAPC_BT_INDEX0)
				{
					if(g_new_bt_msg_dev_mask & MMI_SMS_BT_DEV0)
						g_new_bt_msg_dev_mask &= ~MMI_SMS_BT_DEV0;
					if(!g_new_bt_msg_dev_mask)
					{
						mmi_frm_nmgr_alert_cancel(g_new_bt_msg_handle);
						g_new_bt_msg_handle = NULL;
					}					
				}
				else if(userdata->bt_index == SRV_SMS_BTMAPC_BT_INDEX1)
				{
					if(g_new_bt_msg_dev_mask & MMI_SMS_BT_DEV1)
						g_new_bt_msg_dev_mask &= ~MMI_SMS_BT_DEV1;
					if(!g_new_bt_msg_dev_mask)
					{
						mmi_frm_nmgr_alert_cancel(g_new_bt_msg_handle);
						g_new_bt_msg_handle = NULL;
					}					
				}
			}

            scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx(userdata->scrn_id);
            kal_prompt_trace(MOD_MMI, "[SMS], Entry mmi_sms_bt_get_inbox_list_cb  mmi_sms_um_bt_ui_ut_del_relative_scrn userdata->scrn_id = %d",userdata->scrn_id);
			
            if (mmi_sms_um_bt_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id) && 
                srv_sms_btmapc_get_list_size(SRV_UM_MSG_BTMAPC_BOX_INBOX) == 0)
            {
                kal_prompt_trace(MOD_MMI, "[SMS], Entry mmi_sms_bt_get_inbox_list_cb  mmi_sms_um_bt_ui_ut_del_relative_scrn");
                //mmi_sms_um_bt_ui_ut_del_relative_scrn(&(scrn_cntx->child_scrn_id));
            }
            if (scrn_cntx->aprc.st_type == MMI_SMS_UM_BT_UI_SCRN_TYPE_BT_FOLDER || userdata->is_back_folder == MMI_TRUE)
            {
                kal_prompt_trace(MOD_MMI, "[SMS], Entry mmi_sms_bt_get_inbox_list_cb  mmi_sms_um_bt_ui_cc_send_event  scrn_cntx->aprc.st_type = %d   userdata->is_back_folder = %d", scrn_cntx->aprc.st_type , userdata->is_back_folder);
                mmi_sms_um_bt_ui_cc_send_event(userdata->scrn_id, MMI_UM_UI_EVENT_INIT, &box_type);

                return;
            }
            kal_prompt_trace(MOD_MMI, "[SMS], Entry mmi_sms_um_bt_ui_sh_main_msg_entry_folder");
            mmi_sms_um_bt_ui_sh_main_msg_entry_folder(SRV_UM_MSG_BTMAPC_BOX_INBOX, userdata->scrn_id);
        }
        else if ((((*g_sms_um_ui_p).cc_cntx).grp_table[0].grp_id != 0) && 
                    g_sms_active_dev_index == userdata->bt_index &&
                    g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered != SRV_SMS_BTMAPC_BOX_NONE)
        {
            SrvSmsCallbackFunc func = mmi_sms_bt_get_callback_hdlr(g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered);
            g_sms_bt_ui_p[g_sms_active_dev_index].is_on_request = MMI_TRUE;
            g_sms_bt_ui_p[g_sms_active_dev_index].sms_handle = srv_sms_btmapc_get_msg_list_by_tab(g_sms_active_dev_index, MMI_TRUE, g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered, func, (void *)&g_ef_usdata);                         
        }
    }
    else
    {        
        mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
        //mmi_sms_bt_entry_folder_userdata *userdata = data->user_data;
        srv_um_msg_btmapc_box_enum box_type = SRV_UM_MSG_BTMAPC_BOX_INBOX;
        kal_prompt_trace(MOD_MMI, "[SMS], Entry mmi_sms_bt_get_inbox_list_cb else flow");
        scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx(userdata->scrn_id);
        if((((*g_sms_um_ui_p).cc_cntx).grp_table[0].grp_id != 0) && 
            g_sms_active_dev_index == userdata->bt_index &&
            g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered == SRV_SMS_BTMAPC_BOX_INBOX)
        {
            if (mmi_sms_um_bt_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id) && 
                    srv_sms_btmapc_get_list_size(SRV_UM_MSG_BTMAPC_BOX_INBOX) == 0)
            {
                mmi_sms_um_bt_ui_ut_del_relative_scrn(&(scrn_cntx->child_scrn_id));
            }
            mmi_display_popup(GetString(STR_GLOBAL_FAILED), MMI_EVENT_FAILURE);   

            if (scrn_cntx->aprc.st_type == MMI_SMS_UM_BT_UI_SCRN_TYPE_BT_FOLDER || userdata->is_back_folder == MMI_TRUE)
            {          
                mmi_sms_um_bt_ui_cc_send_event(userdata->scrn_id, MMI_UM_UI_EVENT_INIT, &box_type);

                return;
            }
            mmi_sms_um_bt_ui_sh_main_msg_entry_folder(SRV_UM_MSG_BTMAPC_BOX_INBOX, userdata->scrn_id);
        }
    }

}

void mmi_sms_bt_get_outbox_list_cb(srv_sms_callback_struct* data)
{
    mmi_sms_bt_entry_folder_userdata *userdata = data->user_data; 

    g_sms_bt_ui_p[userdata->bt_index].is_on_request = MMI_FALSE;
    g_sms_bt_ui_p[userdata->bt_index].need_refresh[MMI_SMS_BT_BOX_OUTBOX] = MMI_FALSE;
    if(data->result == MMI_TRUE)
    {
        //mmi_sms_bt_entry_folder_userdata *userdata = data->user_data;
        kal_prompt_trace(MOD_MMI, "Akhil result TRUE");        
        g_sms_bt_ui_p[userdata->bt_index].last_entered = SRV_SMS_BTMAPC_BOX_OUTBOX;
        if((((*g_sms_um_ui_p).cc_cntx).grp_table[0].grp_id != 0) &&
             g_sms_active_dev_index == userdata->bt_index &&            
            (g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered == SRV_SMS_BTMAPC_BOX_OUTBOX))
        {
            mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
            srv_um_msg_btmapc_box_enum box_type = SRV_UM_MSG_BTMAPC_BOX_OUTBOX;
            
            scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx(userdata->scrn_id);
            if (mmi_sms_um_bt_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id))
            {
            }
            if (scrn_cntx->aprc.st_type == MMI_SMS_UM_BT_UI_SCRN_TYPE_BT_FOLDER || userdata->is_back_folder == MMI_TRUE)
            {                
                mmi_sms_um_bt_ui_cc_send_event(userdata->scrn_id, MMI_UM_UI_EVENT_INIT, &box_type);
                    
                return;
            }
            
            mmi_sms_um_bt_ui_sh_main_msg_entry_folder(SRV_UM_MSG_BTMAPC_BOX_OUTBOX, userdata->scrn_id);
        }
        else if ((((*g_sms_um_ui_p).cc_cntx).grp_table[0].grp_id != 0) && 
                    g_sms_active_dev_index == userdata->bt_index &&
                    g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered != SRV_SMS_BTMAPC_BOX_NONE)
        {
            SrvSmsCallbackFunc func = mmi_sms_bt_get_callback_hdlr(g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered);
            g_sms_bt_ui_p[g_sms_active_dev_index].is_on_request = MMI_TRUE;

            g_sms_bt_ui_p[g_sms_active_dev_index].sms_handle = srv_sms_btmapc_get_msg_list_by_tab(g_sms_active_dev_index, MMI_TRUE, g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered, func, (void *)&g_ef_usdata);                            
                     
        }
    }
    else
    {        
        mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
        //mmi_sms_bt_entry_folder_userdata *userdata = data->user_data;
        srv_um_msg_btmapc_box_enum box_type = SRV_UM_MSG_BTMAPC_BOX_OUTBOX;
      
        scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx(userdata->scrn_id);
        if((((*g_sms_um_ui_p).cc_cntx).grp_table[0].grp_id != 0) &&
             g_sms_active_dev_index == userdata->bt_index &&
            (g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered == SRV_SMS_BTMAPC_BOX_OUTBOX))
        {
            if (mmi_sms_um_bt_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id) && 
                    srv_sms_btmapc_get_list_size(SRV_UM_MSG_BTMAPC_BOX_OUTBOX) == 0)
            {
                mmi_sms_um_bt_ui_ut_del_relative_scrn(&(scrn_cntx->child_scrn_id));
            }
            mmi_display_popup(GetString(STR_GLOBAL_FAILED), MMI_EVENT_FAILURE);   

            if (scrn_cntx->aprc.st_type == MMI_SMS_UM_BT_UI_SCRN_TYPE_BT_FOLDER || userdata->is_back_folder == MMI_TRUE)
            {          
                mmi_sms_um_bt_ui_cc_send_event(userdata->scrn_id, MMI_UM_UI_EVENT_INIT, &box_type);

                return;
            }
            mmi_sms_um_bt_ui_sh_main_msg_entry_folder(SRV_UM_MSG_BTMAPC_BOX_OUTBOX, userdata->scrn_id);
        }
    }
}


void mmi_sms_bt_get_unsent_list_cb(srv_sms_callback_struct* data)
{
    mmi_sms_bt_entry_folder_userdata *userdata = data->user_data; 

    g_sms_bt_ui_p[userdata->bt_index].is_on_request = MMI_FALSE;
    g_sms_bt_ui_p[userdata->bt_index].need_refresh[MMI_SMS_BT_BOX_UNSENT] = MMI_FALSE;
    if(data->result == MMI_TRUE)
    {
        //mmi_sms_bt_entry_folder_userdata *userdata = data->user_data;       
        g_sms_bt_ui_p[userdata->bt_index].last_entered = SRV_SMS_BTMAPC_BOX_UNSENT;
        if((((*g_sms_um_ui_p).cc_cntx).grp_table[0].grp_id != 0) &&
             g_sms_active_dev_index == userdata->bt_index &&
            (g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered == SRV_SMS_BTMAPC_BOX_UNSENT))
        {
            mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
            srv_um_msg_btmapc_box_enum box_type = SRV_UM_MSG_BTMAPC_BOX_UNSENT;
            
            scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx(userdata->scrn_id);
            if (mmi_sms_um_bt_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id))
            {
                //mmi_sms_um_bt_ui_ut_del_relative_scrn(&(scrn_cntx->child_scrn_id));
            }
            if (scrn_cntx->aprc.st_type == MMI_SMS_UM_BT_UI_SCRN_TYPE_BT_FOLDER || userdata->is_back_folder == MMI_TRUE)
            {                
                mmi_sms_um_bt_ui_cc_send_event(userdata->scrn_id, MMI_UM_UI_EVENT_INIT, &box_type);
                    
                return;
            }
            
            mmi_sms_um_bt_ui_sh_main_msg_entry_folder(SRV_UM_MSG_BTMAPC_BOX_UNSENT, userdata->scrn_id);
        }
        else if ((((*g_sms_um_ui_p).cc_cntx).grp_table[0].grp_id != 0) && 
                    g_sms_active_dev_index == userdata->bt_index &&
                    g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered != SRV_SMS_BTMAPC_BOX_NONE)
        {
            SrvSmsCallbackFunc func = mmi_sms_bt_get_callback_hdlr(g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered);
            g_sms_bt_ui_p[g_sms_active_dev_index].is_on_request = MMI_TRUE;
            g_sms_bt_ui_p[g_sms_active_dev_index].sms_handle = srv_sms_btmapc_get_msg_list_by_tab(g_sms_active_dev_index, MMI_TRUE, g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered, func, (void *)&g_ef_usdata);                                                           
        }
    }
    else
    {
        mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
        //mmi_sms_bt_entry_folder_userdata *userdata = data->user_data;
        srv_um_msg_btmapc_box_enum box_type = SRV_UM_MSG_BTMAPC_BOX_UNSENT;

        scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx(userdata->scrn_id);
        if((((*g_sms_um_ui_p).cc_cntx).grp_table[0].grp_id != 0) &&
             g_sms_active_dev_index == userdata->bt_index &&           
            (g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered == SRV_SMS_BTMAPC_BOX_UNSENT))
        {
            if (mmi_sms_um_bt_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id) && 
                    srv_sms_btmapc_get_list_size(SRV_UM_MSG_BTMAPC_BOX_UNSENT) == 0)
            {
                mmi_sms_um_bt_ui_ut_del_relative_scrn(&(scrn_cntx->child_scrn_id));
            }
            mmi_display_popup(GetString(STR_GLOBAL_FAILED), MMI_EVENT_FAILURE);   

            if (scrn_cntx->aprc.st_type == MMI_SMS_UM_BT_UI_SCRN_TYPE_BT_FOLDER || userdata->is_back_folder == MMI_TRUE)
            {          
                mmi_sms_um_bt_ui_cc_send_event(userdata->scrn_id, MMI_UM_UI_EVENT_INIT, &box_type);

                return;
            }
            mmi_sms_um_bt_ui_sh_main_msg_entry_folder(SRV_UM_MSG_BTMAPC_BOX_UNSENT, userdata->scrn_id);
        }
    }

}


void mmi_sms_bt_get_drafts_list_cb(srv_sms_callback_struct* data)
{
    mmi_sms_bt_entry_folder_userdata *userdata = data->user_data; 

    g_sms_bt_ui_p[userdata->bt_index].is_on_request = MMI_FALSE;
    g_sms_bt_ui_p[userdata->bt_index].need_refresh[MMI_SMS_BT_BOX_DRAFTS] = MMI_FALSE;
    if(data->result == MMI_TRUE)
    {
        //mmi_sms_bt_entry_folder_userdata *userdata = data->user_data;
        kal_wap_trace(MOD_MMI_COMMON_APP,TRACE_GROUP_6,"Akhil result TRUE");        
        g_sms_bt_ui_p[userdata->bt_index].last_entered = SRV_SMS_BTMAPC_BOX_DRAFTS;
        if((((*g_sms_um_ui_p).cc_cntx).grp_table[0].grp_id != 0) &&
             g_sms_active_dev_index == userdata->bt_index &&    
            (g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered == SRV_SMS_BTMAPC_BOX_DRAFTS))
        {
            mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
            srv_um_msg_btmapc_box_enum box_type = SRV_UM_MSG_BTMAPC_BOX_DRAFTS;
            
            scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx(userdata->scrn_id);
            if (mmi_sms_um_bt_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id))
            {
                //mmi_sms_um_bt_ui_ut_del_relative_scrn(&(scrn_cntx->child_scrn_id));
            }
            if (scrn_cntx->aprc.st_type == MMI_SMS_UM_BT_UI_SCRN_TYPE_BT_FOLDER || userdata->is_back_folder == MMI_TRUE)
            {                
                mmi_sms_um_bt_ui_cc_send_event(userdata->scrn_id, MMI_UM_UI_EVENT_INIT, &box_type);
                    
                return;
            }
            mmi_sms_um_bt_ui_sh_main_msg_entry_folder(SRV_UM_MSG_BTMAPC_BOX_DRAFTS, userdata->scrn_id);
        }
        else if ((((*g_sms_um_ui_p).cc_cntx).grp_table[0].grp_id != 0) && 
                    g_sms_active_dev_index == userdata->bt_index &&    
                    g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered != SRV_SMS_BTMAPC_BOX_NONE)
        {
            SrvSmsCallbackFunc func = mmi_sms_bt_get_callback_hdlr(g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered);
            g_sms_bt_ui_p[g_sms_active_dev_index].is_on_request = MMI_TRUE;
            g_sms_bt_ui_p[g_sms_active_dev_index].sms_handle = srv_sms_btmapc_get_msg_list_by_tab(g_sms_active_dev_index, MMI_TRUE, g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered, func, (void *)&g_ef_usdata);                                                              
        }
    }
    else
    {        
        mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
        //mmi_sms_bt_entry_folder_userdata *userdata = data->user_data;
        srv_um_msg_btmapc_box_enum box_type = SRV_UM_MSG_BTMAPC_BOX_DRAFTS;
        
        scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx(userdata->scrn_id);
        if((((*g_sms_um_ui_p).cc_cntx).grp_table[0].grp_id != 0) &&
             g_sms_active_dev_index == userdata->bt_index &&    
            (g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered == SRV_SMS_BTMAPC_BOX_DRAFTS))
        {
            if (mmi_sms_um_bt_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id) && 
                    srv_sms_btmapc_get_list_size(SRV_UM_MSG_BTMAPC_BOX_DRAFTS) == 0)
            {
                mmi_sms_um_bt_ui_ut_del_relative_scrn(&(scrn_cntx->child_scrn_id));
            }
            mmi_display_popup(GetString(STR_GLOBAL_FAILED), MMI_EVENT_FAILURE);   

            if (scrn_cntx->aprc.st_type == MMI_SMS_UM_BT_UI_SCRN_TYPE_BT_FOLDER || userdata->is_back_folder == MMI_TRUE)
            {          
                mmi_sms_um_bt_ui_cc_send_event(userdata->scrn_id, MMI_UM_UI_EVENT_INIT, &box_type);

                return;
            }
            mmi_sms_um_bt_ui_sh_main_msg_entry_folder(SRV_UM_MSG_BTMAPC_BOX_DRAFTS, userdata->scrn_id);
        }
    }
}

SrvSmsCallbackFunc mmi_sms_bt_get_callback_hdlr(srv_um_msg_btmapc_box_enum box_enum)
{
    SrvSmsCallbackFunc func = NULL;
    switch (box_enum)
    {
        case SRV_UM_MSG_BTMAPC_BOX_INBOX:
        {
            func = mmi_sms_bt_get_inbox_list_cb;
            break;
        }
        case SRV_UM_MSG_BTMAPC_BOX_OUTBOX:
        {
            func = mmi_sms_bt_get_outbox_list_cb;
            break;
        }
        case SRV_UM_MSG_BTMAPC_BOX_DRAFTS:
        {
            func = mmi_sms_bt_get_drafts_list_cb;
            break;
        }
        case SRV_UM_MSG_BTMAPC_BOX_UNSENT:
        {
            func = mmi_sms_bt_get_unsent_list_cb;
            break;
        }
        default:
        {
            func = NULL;
            break;
        }
    }
    return func;
}




void mmi_sms_um_bt_ui_sh_main_msg_entry_write_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    scrn_cntx = mmi_sms_um_bt_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    mmi_sms_um_bt_ui_adp_cui_launch_by_menu_id(mmi_sms_um_bt_ui_cc_get_root_grp_id(scrn_cntx->group_id), MENU_ID_SMS_UM_WRITE_MSG);
}


void mmi_sms_um_bt_ui_sh_main_msg_entry_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_bt_entry_folder_userdata *userdata;
    U16 scrn_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //scrn_cntx = mmi_sms_um_bt_ui_sh_get_active_user_data();
    if (g_sms_um_ui_main_menu_scrn_id != 0)  
    {
        scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx(g_sms_um_ui_main_menu_scrn_id);
    }
    else 
    {
        scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx((g_sms_um_ui_p->cc_cntx.scrn_table[0].scrn_id));
    }
        ClearAllKeyHandler();
    SetKeyUpHandler(NULL,KEY_END);
    SetKeyDownHandler(NULL,KEY_END);
    
    userdata = &g_ef_usdata;
    userdata->is_back_folder = MMI_FALSE;
    userdata->scrn_id = scrn_cntx->scrn_id;
    userdata->bt_index = g_sms_active_dev_index;
    g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered = SRV_SMS_BTMAPC_BOX_INBOX;

    if (mmi_sms_um_bt_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id))
    {
        mmi_sms_um_bt_ui_ut_del_relative_scrn(&(scrn_cntx->child_scrn_id));
    }
    
    g_sms_bt_ui_p[g_sms_active_dev_index].is_bt_connected = srv_bt_mapc_adp_is_connected(g_sms_active_dev_index);
        
    #ifndef __MTK_TARGET__
    g_sms_bt_ui_p[g_sms_active_dev_index].is_bt_connected = MMI_TRUE;
    #endif
    if (!g_sms_bt_ui_p[g_sms_active_dev_index].is_bt_connected)
    {
        if (srv_sms_btmapc_get_list_size(SRV_UM_MSG_BTMAPC_BOX_INBOX) != 0)
        {
        #ifndef __MMI_TELEPHONY_SUPPORT__
            srv_sms_btmapc_delete_all();
        #else
            srv_sms_btmapc_storage_reset_data(MMI_TRUE);
        #endif
        }
        mmi_sms_um_bt_ui_sh_main_msg_entry_folder(SRV_UM_MSG_BTMAPC_BOX_INBOX, userdata->scrn_id);

        return;
    }
    
    #if 0  
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
	
    if (1)
    {
        if (g_sms_um_ui_main_menu_scrn_id == 0)
            g_sms_bt_ui_p[g_sms_active_dev_index].mmi_need_update_list = MMI_TRUE;
        scrn_cntx->child_scrn_id = mmi_sms_um_bt_ui_if_entry_processing(scrn_cntx->scrn_id, scrn_cntx->group_id, MMI_FALSE);
        if (!g_sms_bt_ui_p[g_sms_active_dev_index].is_on_request)
        {
            g_sms_bt_ui_p[g_sms_active_dev_index].is_on_request = MMI_TRUE;

            g_sms_bt_ui_p[g_sms_active_dev_index].sms_handle = srv_sms_btmapc_get_msg_list_by_tab(g_sms_active_dev_index,MMI_TRUE, SRV_SMS_BTMAPC_BOX_INBOX, mmi_sms_bt_get_inbox_list_cb, (void *)userdata);                                        

        }
        mmi_sms_um_bt_ui_ut_send_init_event(scrn_cntx->child_scrn_id);
    }
    else
    {
        kal_wap_trace(MOD_MMI_COMMON_APP,TRACE_GROUP_6,"FALSE");
        //scrn_cntx->child_scrn_id = mmi_sms_um_bt_ui_if_entry_general(scrn_cntx->scrn_id, scrn_cntx->group_id, MMI_FALSE, MMI_SMS_UM_BT_ENTRY_SCREEN_GENERAL_FOLDER, scrn_cntx);
        //scrn_cntx->child_scrn_id = mmi_sms_um_bt_ui_if_entry_processing(scrn_cntx->scrn_id, scrn_cntx->group_id, MMI_FALSE);
        g_sms_bt_ui_p[g_sms_active_dev_index].sms_handle = srv_sms_btmapc_get_msg_list_by_tab(g_sms_active_dev_index, MMI_FALSE, SRV_SMS_BTMAPC_BOX_INBOX, mmi_sms_bt_get_inbox_list_cb, (void *)userdata);                           
    }    
  //  mmi_sms_um_bt_ui_sh_main_msg_entry_folder(SRV_UM_MSG_BTMAPC_BOX_INBOX);
}
void mmi_sms_um_bt_ui_sh_main_msg_entry_draft(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_bt_entry_folder_userdata *userdata;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx(g_sms_um_ui_main_menu_scrn_id);
     ClearAllKeyHandler();
    SetKeyUpHandler(NULL,KEY_END);
    SetKeyDownHandler(NULL,KEY_END);

    userdata = &g_ef_usdata;
    userdata->is_back_folder = MMI_FALSE;
    userdata->scrn_id = scrn_cntx->scrn_id;
    userdata->bt_index = g_sms_active_dev_index;
    g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered = SRV_SMS_BTMAPC_BOX_DRAFTS;
    if (mmi_sms_um_bt_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id))
    {
        mmi_sms_um_bt_ui_ut_del_relative_scrn(&(scrn_cntx->child_scrn_id));
    }

    g_sms_bt_ui_p[g_sms_active_dev_index].is_bt_connected = srv_bt_mapc_adp_is_connected(g_sms_active_dev_index);
    if (!g_sms_bt_ui_p[g_sms_active_dev_index].is_bt_connected)
    {
        if (srv_sms_btmapc_get_list_size(SRV_UM_MSG_BTMAPC_BOX_DRAFTS) != 0)
        {
        #ifndef __MMI_TELEPHONY_SUPPORT__
            srv_sms_btmapc_delete_all();
        #else
            srv_sms_btmapc_storage_reset_data(MMI_TRUE);
        #endif
        }
        if(((*g_sms_um_ui_p).cc_cntx).grp_table[0].grp_id != 0)
        {
            mmi_sms_um_bt_ui_sh_main_msg_entry_folder(SRV_UM_MSG_BTMAPC_BOX_DRAFTS, userdata->scrn_id);
        }      
        return;
    }
    
    if (1)
    {
        if (g_sms_um_ui_main_menu_scrn_id == 0)
            g_sms_bt_ui_p[g_sms_active_dev_index].mmi_need_update_list = MMI_TRUE;
        scrn_cntx->child_scrn_id = mmi_sms_um_bt_ui_if_entry_processing(scrn_cntx->scrn_id, scrn_cntx->group_id, MMI_FALSE);
        if (!g_sms_bt_ui_p[g_sms_active_dev_index].is_on_request)
        {
            g_sms_bt_ui_p[g_sms_active_dev_index].is_on_request = MMI_TRUE;
            g_sms_bt_ui_p[g_sms_active_dev_index].sms_handle = srv_sms_btmapc_get_msg_list_by_tab(g_sms_active_dev_index,MMI_TRUE, SRV_SMS_BTMAPC_BOX_DRAFTS, mmi_sms_bt_get_drafts_list_cb, (void *)userdata);                                       
        }
        mmi_sms_um_bt_ui_ut_send_init_event(scrn_cntx->child_scrn_id);
    }
    else
    {
            g_sms_bt_ui_p[g_sms_active_dev_index].sms_handle = srv_sms_btmapc_get_msg_list_by_tab(g_sms_active_dev_index,MMI_FALSE, SRV_SMS_BTMAPC_BOX_DRAFTS, mmi_sms_bt_get_drafts_list_cb, (void *)userdata);                           
    }
    //mmi_sms_um_bt_ui_sh_main_msg_entry_folder(SRV_UM_MSG_BTMAPC_BOX_DRAFTS);
}
void mmi_sms_um_bt_ui_sh_main_msg_entry_outbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_bt_entry_folder_userdata *userdata;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sms_um_ui_main_menu_scrn_id != 0)  
    {
        scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx(g_sms_um_ui_main_menu_scrn_id);
    }
    else 
    {
        scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx((g_sms_um_ui_p->cc_cntx.scrn_table[0].scrn_id));
    }
    ClearAllKeyHandler();
    SetKeyUpHandler(NULL,KEY_END);
    SetKeyDownHandler(NULL,KEY_END);

    userdata = &g_ef_usdata;
    userdata->is_back_folder = MMI_FALSE;
    userdata->scrn_id = scrn_cntx->scrn_id;
    userdata->bt_index = g_sms_active_dev_index;
    g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered = SRV_SMS_BTMAPC_BOX_UNSENT;
    if (mmi_sms_um_bt_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id))
    {
        mmi_sms_um_bt_ui_ut_del_relative_scrn(&(scrn_cntx->child_scrn_id));
    }

    g_sms_bt_ui_p[g_sms_active_dev_index].is_bt_connected = srv_bt_mapc_adp_is_connected(g_sms_active_dev_index);
    if (!g_sms_bt_ui_p[g_sms_active_dev_index].is_bt_connected)
    {
        if (srv_sms_btmapc_get_list_size(SRV_UM_MSG_BTMAPC_BOX_UNSENT) != 0)
        {
        #ifndef __MMI_TELEPHONY_SUPPORT__
            srv_sms_btmapc_delete_all();
        #else
            srv_sms_btmapc_storage_reset_data(MMI_TRUE);
        #endif
        }
        if(((*g_sms_um_ui_p).cc_cntx).grp_table[0].grp_id != 0)
        {
            mmi_sms_um_bt_ui_sh_main_msg_entry_folder(SRV_UM_MSG_BTMAPC_BOX_UNSENT, userdata->scrn_id);
        }
        return;
    }
    
    if (1)
    {
        if (g_sms_um_ui_main_menu_scrn_id == 0)
            g_sms_bt_ui_p[g_sms_active_dev_index].mmi_need_update_list = MMI_TRUE;
        scrn_cntx->child_scrn_id = mmi_sms_um_bt_ui_if_entry_processing(scrn_cntx->scrn_id, scrn_cntx->group_id, MMI_FALSE);
        if (!g_sms_bt_ui_p[g_sms_active_dev_index].is_on_request)
        {
        #ifndef __MMI_TELEPHONY_SUPPORT__
            srv_sms_btmapc_delete_all();
        #else
            srv_sms_btmapc_storage_reset_data(MMI_TRUE);
        #endif
            g_sms_bt_ui_p[g_sms_active_dev_index].is_on_request = MMI_TRUE;
            g_sms_bt_ui_p[g_sms_active_dev_index].sms_handle = srv_sms_btmapc_get_msg_list_by_tab(g_sms_active_dev_index, MMI_TRUE, SRV_SMS_BTMAPC_BOX_UNSENT, mmi_sms_bt_get_unsent_list_cb, (void *)userdata);                                       
        }
        mmi_sms_um_bt_ui_ut_send_init_event(scrn_cntx->child_scrn_id);
    }
    else
    {
        g_sms_bt_ui_p[g_sms_active_dev_index].sms_handle = srv_sms_btmapc_get_msg_list_by_tab(g_sms_active_dev_index, MMI_FALSE, SRV_SMS_BTMAPC_BOX_UNSENT, mmi_sms_bt_get_unsent_list_cb, (void *)userdata);                          
    }
	//mmi_sms_um_bt_ui_sh_main_msg_entry_folder(SRV_UM_MSG_BTMAPC_BOX_UNSENT);SRV_SMS_BTMAPC_BOX_UNSENT
}
void mmi_sms_um_bt_ui_sh_main_msg_entry_sent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_bt_entry_folder_userdata *userdata;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx(g_sms_um_ui_main_menu_scrn_id);
    ClearAllKeyHandler();
    SetKeyUpHandler(NULL,KEY_END);
    SetKeyDownHandler(NULL,KEY_END);

    userdata = &g_ef_usdata;
    userdata->is_back_folder = MMI_FALSE;
    userdata->scrn_id = scrn_cntx->scrn_id;
    userdata->bt_index = g_sms_active_dev_index;
    g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered = SRV_SMS_BTMAPC_BOX_OUTBOX;
    if (mmi_sms_um_bt_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id))
    {
        mmi_sms_um_bt_ui_ut_del_relative_scrn(&(scrn_cntx->child_scrn_id));
    }

    g_sms_bt_ui_p[g_sms_active_dev_index].is_bt_connected = srv_bt_mapc_adp_is_connected(g_sms_active_dev_index);
    if (!g_sms_bt_ui_p[g_sms_active_dev_index].is_bt_connected)
    {
        if (srv_sms_btmapc_get_list_size(SRV_UM_MSG_BTMAPC_BOX_OUTBOX) != 0)
        {
        #ifndef __MMI_TELEPHONY_SUPPORT__
            srv_sms_btmapc_delete_all();
        #else
            srv_sms_btmapc_storage_reset_data(MMI_TRUE);
        #endif
        }
        if(((*g_sms_um_ui_p).cc_cntx).grp_table[0].grp_id != 0)
        {
            mmi_sms_um_bt_ui_sh_main_msg_entry_folder(SRV_UM_MSG_BTMAPC_BOX_OUTBOX, userdata->scrn_id);
        }
        return;
    }
    
    if (1)
    {
        if (g_sms_um_ui_main_menu_scrn_id == 0)
            g_sms_bt_ui_p[g_sms_active_dev_index].mmi_need_update_list = MMI_TRUE;
        scrn_cntx->child_scrn_id = mmi_sms_um_bt_ui_if_entry_processing(scrn_cntx->scrn_id, scrn_cntx->group_id, MMI_FALSE);
        if (!g_sms_bt_ui_p[g_sms_active_dev_index].is_on_request)
        {
            g_sms_bt_ui_p[g_sms_active_dev_index].is_on_request = MMI_TRUE;
            g_sms_bt_ui_p[g_sms_active_dev_index].sms_handle = srv_sms_btmapc_get_msg_list_by_tab(g_sms_active_dev_index, MMI_TRUE, SRV_SMS_BTMAPC_BOX_OUTBOX, mmi_sms_bt_get_outbox_list_cb, (void *)userdata);                                     
        }
        mmi_sms_um_bt_ui_ut_send_init_event(scrn_cntx->child_scrn_id);
    }
    else
    {
        g_sms_bt_ui_p[g_sms_active_dev_index].sms_handle = srv_sms_btmapc_get_msg_list_by_tab(g_sms_active_dev_index, MMI_FALSE, SRV_SMS_BTMAPC_BOX_OUTBOX, mmi_sms_bt_get_outbox_list_cb, (void *)userdata);                            
    }
    //mmi_sms_um_bt_ui_sh_main_msg_entry_folder(SRV_UM_MSG_BTMAPC_BOX_OUTBOX);
}

void mmi_sms_um_bt_ui_sh_main_message_update_by_app(U16 menu_item_id, U8 *update_string, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Should not update UM related menu id */
    if (MENU_ID_UM_WRITE_MSG == menu_item_id || 
        MENU_ID_UM_INBOX == menu_item_id || 
        MENU_ID_UM_DRAFT == menu_item_id || 
        MENU_ID_UM_UNSENT == menu_item_id || 
        MENU_ID_UM_SENT == menu_item_id || 
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        MENU_ID_UM_ARCHIVE == menu_item_id || 
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        MENU_ID_UM_SIM == menu_item_id || 
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    #ifdef __MMI_UM_REPORT_BOX__
        MENU_ID_UM_REPORT == menu_item_id ||
    #endif /* __MMI_UM_REPORT_BOX__ */

    #ifdef __MMI_UM_TEMPLATE_SUPPORT__
        MENU_ID_UM_TEMPLATE == menu_item_id || 
    #endif /* __MMI_UM_TEMPLATE_SUPPORT__ */
        MENU_ID_UM_SETTING == menu_item_id)
    {
        MMI_ASSERT(0);
    }
    MMI_ASSERT(update_string != NULL);
    scrn_cntx = (mmi_sms_um_bt_ui_cc_scrn_cntx_struct *)user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* Update the stirng of folder menu item */
    if (MMI_SCENARIO_STATE_ACTIVE != 
        mmi_frm_scrn_get_state(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id))
    {
        return;
    }

    /* Check if the update menu id is hided */
    if (!mmi_frm_test_menu_item_hide(menu_item_id))
    {
        i = GetIndexOfStringId_Ext(MAIN_MENU_SMS_BT_MESSAGES_MENUID, menu_item_id);

        mmi_ucs2cpy((CHAR*)subMenuData[i], (CHAR*)update_string);
        Category53ChangeItemText((S32)i, (U8*)subMenuData[i]);

        RedrawCategoryFunction();
    }
}

MMI_BOOL mmi_sms_um_bt_ui_sh_general_folder_init(
                    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx, 
                    mmi_sms_um_bt_ui_cc_scrn_cntx_setting_struct *setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    mmi_sms_um_bt_ui_fsm_ef_setting_struct fsm_setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;
    
    /* FSM initialize */
    memset(&fsm_setting, 0, sizeof(mmi_sms_um_bt_ui_fsm_ef_setting_struct));
    fsm_setting.folder_mode = MMI_UM_FOLDER_MODE_DEFAULT;
    fsm_setting.folder_type = setting->folder;
    fsm_setting.scrn_callback_hdlr = mmi_sms_um_bt_ui_sh_general_folder_fsm_cb;
    fsm_setting.scrn_id = scrn_cntx->scrn_id;
    mmi_sms_um_bt_ui_fsm_ef_init(&(scrn_cntx->fsm), fsm_setting);

    /* Appearance initialize */
    mmi_sms_um_bt_ui_aprc_set_cntx(&(scrn_cntx->aprc), setting->aprc_type);

    /* Screen handler initialize */
    scrn_cntx->screen_hdlr.disp_scrn_id = setting->disp_scrn_id;
    scrn_cntx->screen_hdlr.folder_type = setting->folder;
    memset(&(scrn_cntx->screen_hdlr.hilite_info), 0, sizeof(mmi_sms_um_bt_ui_sh_hilite_info_struct));
    scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_FALSE;
    scrn_cntx->screen_hdlr.num_of_item = 0;
    scrn_cntx->screen_hdlr.scrn_data = setting->scrn_data;

    return result;
}
MMI_BOOL mmi_sms_um_bt_ui_sh_general_folder_event_hdlr(U16 scrn_id, U16 event, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    result = MMI_TRUE;
    switch (event)
    {
        case MMI_UM_UI_EVENT_INIT:
        case MMI_UM_UI_EVENT_ABORT:
        case MMI_UM_UI_EVENT_CHECK:
        case MMI_UM_UI_EVENT_UNREADY:
        case MMI_UM_UI_EVENT_REL_DATA_LIST:
        {
            #if 0
/* under construction !*/
/* under construction !*/
            #endif
            result = mmi_sms_um_bt_ui_sh_tsfr_fsm_event(event,scrn_cntx,arg);
            break;
        }
        case MMI_UM_UI_EVENT_READY:
        {
            if (mmi_sms_um_bt_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id))
            {
                /* If current state is not check ready, return */
                if (mmi_sms_um_bt_ui_fsm_get_fsm_state(&(scrn_cntx->fsm)) != MMI_UM_UI_FSM_EF_CHECK_READY)
                {
                    break;
                }

                /* Invoke FSM mechanism */
                #if 0
/* under construction !*/
/* under construction !*/
                #endif
                result = mmi_sms_um_bt_ui_sh_tsfr_fsm_event(event,scrn_cntx,arg);
            }
            break;
        }
        case MMI_UM_UI_EVENT_REFRESH:
        {
            srv_um_msg_btmapc_box_enum *msg_box;

            msg_box = (srv_um_msg_btmapc_box_enum *)arg;
            /* Check current box folder */
            if ((scrn_cntx->screen_hdlr.folder_type.msg_box_type & *msg_box) == 0)
            {
                break;
            }

            /***********************************************************************************
             * Empty screen => other screen => new message => it should set a fake number of 
             * message
             * Because we use the trick solution to set the data list as NULL to avoid the 
             * un-necessary loading screen.
             **********************************************************************************/
            if (0 == scrn_cntx->screen_hdlr.num_of_item)
            {
                scrn_cntx->screen_hdlr.num_of_item = 1;
            }
            //srv_um_bt_reset_data(); 
            //No any action 
            /*if (mmi_sms_um_bt_ui_fsm_get_fsm_state(&(scrn_cntx->fsm)) == MMI_UM_UI_FSM_EF_CHECK_DATA)
            {
                // Turn on the update flag 
                result = scrn_cntx->fsm.event_hdlr(scrn_id, MMI_UM_UI_FSM_EVENT_UPDATE_DATA_LIST, NULL);

                // Check child group id, child must be option menu 
                // Dial confirm => refresh indication, Option => delete confirm (conversations), any confirm popup 
                if ((0 != scrn_cntx->child_group_id && mmi_frm_group_get_active_id() == scrn_cntx->child_group_id) ||
                    (GRP_ID_INVALID != scrn_cntx->screen_hdlr.cf_grp_id))
                {
                    // Display a hint to end user 
                    mmi_popup_display_simple(
                            (WCHAR *)get_string(STR_GLOBAL_UPDATE), 
                            MMI_EVENT_INFO, 
                            scrn_cntx->group_id, 
                            NULL);
                }
            }*/
            //else
            //{
                /* Invoke refresh mechanism */
                #if 0
/* under construction !*/
/* under construction !*/
                #endif
                result = mmi_sms_um_bt_ui_sh_tsfr_fsm_event(event,scrn_cntx,arg);
            //}
            break;
        }
        case MMI_UM_UI_EVENT_DELETE:
        {
            mmi_sms_um_bt_ui_sh_evt_hdlr_delete(scrn_cntx, arg);
            break;
        }
        case MMI_UM_UI_EVENT_DELETED:
        {
            /* Set child screen as 0 */
            scrn_cntx->child_scrn_id = 0;
            /* During update data, it could not call "GobackHistory" in loading screen */
            if (mmi_sms_um_bt_ui_fsm_get_fsm_state(&(scrn_cntx->fsm)) == MMI_UM_UI_FSM_EF_UPDATE_DATA && 
                MMI_SCENARIO_STATE_ACTIVE != mmi_frm_scrn_get_state(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id))
            {
                //MMI_ASSERT(0);
            }
            /* 
             * During updating data, screen is not in history. It should delete the screen context.
             * The scenario should be messaging => inbox => get_list => display loading => press end key
             */
            if ((MMI_UM_UI_FSM_EF_UPDATE_DATA == mmi_sms_um_bt_ui_fsm_get_fsm_state(&(scrn_cntx->fsm)) ||
                 MMI_UM_UI_FSM_EF_CHECK_READY == mmi_sms_um_bt_ui_fsm_get_fsm_state(&(scrn_cntx->fsm))) && 
                MMI_FALSE == mmi_frm_scrn_is_present(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id, MMI_FRM_NODE_ALL_FLAG))
            {
                mmi_sms_um_bt_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
            }
            break;
        }
        case MMI_UM_UI_EVENT_HIGHLIGHT_CHANGE:
        {
            mmi_sms_um_bt_ui_sh_hilite_folder_info_struct *hilite_folder;
            /* Set the new highlight */
            hilite_folder = (mmi_sms_um_bt_ui_sh_hilite_folder_info_struct *)arg;

            if (scrn_cntx->screen_hdlr.folder_type.msg_box_type == hilite_folder->folder_info.msg_box_type)
            {
                scrn_cntx->screen_hdlr.hilite_info.msg_id = hilite_folder->hilite_info.msg_id;
                scrn_cntx->screen_hdlr.hilite_info.msg_type = hilite_folder->hilite_info.msg_type;
            #ifdef __MMI_UM_CONVERSATION_BOX__
                scrn_cntx->screen_hdlr.hilite_info.thrd_id.type = hilite_folder->hilite_info.thrd_id.type;
                scrn_cntx->screen_hdlr.hilite_info.thrd_id.value = hilite_folder->hilite_info.thrd_id.value;
            #endif /* __MMI_UM_CONVERSATION_BOX__ */
            }
            break;
        }
        case MMI_UM_UI_EVENT_HIGHLIGHT_IDX_CHANGE:
        {
            mmi_sms_um_bt_ui_sh_hilite_folder_info_struct *hilite_folder;
            /* Set the new highlight */
            hilite_folder = (mmi_sms_um_bt_ui_sh_hilite_folder_info_struct *)arg;

            if (scrn_cntx->screen_hdlr.folder_type.msg_box_type == hilite_folder->folder_info.msg_box_type)
            {
                scrn_cntx->screen_hdlr.hilite_info.index = hilite_folder->hilite_info.index;
            }
            break;
        }
        case MMI_UM_UI_EVENT_SET_NUM_MSG_INSIDE:
        {
            U16 *num;

            num = (U16 *)arg;
            if (0xffff == *num)
            {
                /* Set event to FSM */
                result = scrn_cntx->fsm.event_hdlr(scrn_id, MMI_UM_UI_FSM_EVENT_KEEP_DATA_LIST, NULL);
            }
            break;
        }
        case MMI_UM_UI_EVENT_SET_FILTER_TYPE:
        {
            srv_um_list_filter_struct *filter;

            filter = (srv_um_list_filter_struct *)arg;
            /* Set the sorting type */
            mmi_sms_um_bt_ui_fsm_ef_set_list_filter_type(&(scrn_cntx->fsm), *filter);
            break;
        }
    #ifdef __MMI_UM_CONVERSATION_BOX__
        case MMI_UM_UI_EVENT_SET_FOLDER_MODE:
        {
            mmi_sms_um_bt_ui_folder_mode_enum *mode;

            mode = (mmi_sms_um_bt_ui_folder_mode_enum *)arg;
            /* Set the folder mode */
            mmi_sms_um_bt_ui_fsm_ef_set_folder_mode(&(scrn_cntx->fsm), *mode);
            break;
        }
    #endif /* __MMI_UM_CONVERSATIO_BOX__ */
        default:
        {
            break;
        }
    }

    return result;
}
MMI_BOOL mmi_sms_um_bt_ui_sh_general_folder_fsm_cb(U16 scrn_id, U16 state, U16 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 num_item;
    MMI_BOOL result;
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_um_bt_ui_folder_mode_enum folder_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;
    scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* Based on the Mode, get the entry function pointer */
    folder_mode = mmi_sms_um_bt_ui_fsm_ef_get_folder_mode(&(scrn_cntx->fsm));

    switch (state)
    {
        case MMI_UM_UI_FSM_EF_CHECK_READY:
        {
            MMI_ID child_group_id;

            /* call UI interface to entry a process screen with RSK */
            /* Check child group id, option menu */
            if (0 != scrn_cntx->child_group_id)
            {
                if (mmi_frm_group_get_active_id() == scrn_cntx->child_group_id)
                {
                    /* Display a hint to end user */
                    mmi_popup_display_simple(
                            (WCHAR *)get_string(STR_GLOBAL_UPDATE), 
                            MMI_EVENT_INFO, 
                            scrn_cntx->group_id, 
                            NULL);
                }
                else
                {
                    child_group_id = scrn_cntx->child_group_id;
                    scrn_cntx->child_group_id = 0;
                    /* Reset the data list */
                    mmi_sms_um_bt_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_REL_DATA_LIST, NULL);
                    
                    /* Reset cache in the Service level */
                    srv_um_sms_clear_msg_info_cache(SRV_UM_MSG_ALL, SRV_UM_MSG_BOX_ALL);
                    cui_menu_close(child_group_id);
                }
            }
            else
            {
            }
            break;
        }
        case MMI_UM_UI_FSM_EF_CHECK_DATA:
        {
        #ifdef __MMI_UM_CONVERSATION_BOX__
            U16 tmp_child_scrn_id;
        #endif /* __MMI_UM_CONVERSATION_BOX__ */
        #ifdef __MMI_UM_ITERATOR_VIEWER__
            mmi_sms_um_iter_viewer_info_struct *viewer_info;
        #endif /* __MMI_UM_ITERATOR_VIEWER__ */

            /* It is ready to display screen */
            num_item = mmi_sms_um_bt_ui_sh_general_folder_get_msg_num(scrn_cntx);

        #ifdef __MMI_UM_CONVERSATION_BOX__
            tmp_child_scrn_id = scrn_cntx->child_scrn_id;
            /* In thread message mode, the empty list should delete thread list, too */
            if (0 == num_item &&
                MMI_UM_FOLDER_MODE_THREAD_MSG == folder_mode)
            {
                /* delete current screen */
                result = mmi_sms_um_bt_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
                /* delete child screen */
                mmi_sms_um_bt_ui_ut_del_relative_scrn(&tmp_child_scrn_id);
                return result;
            }
        #endif /* __MMI_UM_CONVERSATION_BOX__ */
			if (0 == num_item )
			{
			    memset(&scrn_cntx->screen_hdlr.hilite_info, 0, sizeof(scrn_cntx->screen_hdlr.hilite_info));
			}
            /* Check if it has the child screen */
            if (mmi_sms_um_bt_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id))
            {
                #if 1
                /* folder screen is not in the history/active */
                if (!mmi_frm_scrn_is_present(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id, MMI_FRM_NODE_ALL_FLAG))
                {
                    mmi_sms_um_bt_ui_sh_create(mmi_sms_um_bt_ui_sh_general_folder_get_entry_func(folder_mode), scrn_cntx);
                    /* After entry, the child processing screen will be deleted */
                }
                else
                #endif
                {
                    /* The child should be removed */
                    mmi_sms_um_bt_ui_ut_del_relative_scrn(&(scrn_cntx->child_scrn_id));
                }
            }
            else
            {
                if (MMI_SCENARIO_STATE_ACTIVE == mmi_frm_scrn_get_state(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id))
                {
            #ifdef __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__
                    /* Not during SSP status, update it */
                    if (!gui_screen_smooth_scrolling_moved_by_pen())
                    {
                #ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
                        if (MMI_UM_FOLDER_MODE_THREAD_MSG == mmi_sms_um_bt_ui_fsm_ef_get_folder_mode(&scrn_cntx->fsm))
                        {
                            mmi_cat_conversation_refresh(
                                    MMI_fixed_list_menu.n_items,
                                    MMI_fixed_list_menu.highlighted_item,
                                    mmi_sms_um_bt_ui_sh_thread_enhance_get_async_item);
                        }
                        else
                #endif /* __MMI_UM_CONVERSATION_BOX_ENHANCE__ */
                        {
                            mmi_cat_refresh_asyncdynamic_list(
                                    MMI_fixed_list_menu.n_items, 
                                    MMI_fixed_list_menu.highlighted_item, 
                                    mmi_sms_um_bt_ui_sh_get_async_item,
                                    NULL);
                        }
                    }
            #endif /* __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__ */
                }
                else if (!mmi_frm_scrn_is_present(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id, MMI_FRM_NODE_ALL_FLAG))
                {
                    /* this screen is not created yet */
                    kal_prompt_trace(MOD_MMI, "[SMS], Entry mmi_sms_um_bt_ui_sh_general_folder_fsm_cb mmi_sms_um_bt_ui_sh_create");
                    mmi_sms_um_bt_ui_sh_create(mmi_sms_um_bt_ui_sh_general_folder_get_entry_func(folder_mode), scrn_cntx);
                }
                /***********************************************************
                 * Other cases:
                 *  (a) SSP => during collect msg info => other screen over
                 **********************************************************/
            }
        #ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
            /* try to prevent double loading, or black background */
            if ((MMI_UM_FOLDER_MODE_THREAD_MSG == mmi_sms_um_bt_ui_fsm_ef_get_folder_mode(&scrn_cntx->fsm)) &&
                (!mmi_sms_um_bt_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id) && 
                (MMI_UM_UI_FSM_EF_UPDATE_DATA == scrn_cntx->fsm.cntx.fsm_entry_folder.state)))
            {
                scrn_cntx->child_scrn_id = mmi_sms_um_bt_ui_if_entry_processing(scrn_id, scrn_cntx->group_id, MMI_FALSE);
                mmi_sms_um_bt_ui_ut_send_init_event(scrn_cntx->child_scrn_id);
            }
        #endif

        #ifdef __MMI_UM_ITERATOR_VIEWER__
            if (NULL != scrn_cntx->ext_app_user_data)
            {
                viewer_info = (mmi_sms_um_iter_viewer_info_struct *)scrn_cntx->ext_app_user_data;
                /* notify app to get the data */
                viewer_info->func_cb(viewer_info->user_data);
                OslMfree(scrn_cntx->ext_app_user_data);
                scrn_cntx->ext_app_user_data = NULL;
            }
        #endif /* __MMI_UM_ITERATOR_VIEWER__ */
            break;
        }
        case MMI_UM_UI_FSM_EF_UPDATE_DATA:
        {
            /* call UI interface to entry a process screen without RSK */
            if (mmi_sms_um_bt_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id))
            {
            }
            else
            {
                /* Entry processing screen */
            #ifdef __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__
                if (scrn_cntx->screen_hdlr.is_scrn_displayed == MMI_FALSE ||
                #ifdef __MMI_UM_CONVERSATION_BOX__
                    (mmi_sms_um_bt_ui_fsm_ef_get_action(&(scrn_cntx->fsm)) != MMI_UM_UI_ACTION_GET_THRD_INFO &&
                #endif /* __MMI_UM_CONVERSATION_BOX__ */
                    mmi_sms_um_bt_ui_fsm_ef_get_action(&(scrn_cntx->fsm)) != MMI_UM_UI_ACTION_GET_MSG_INFO
                #ifdef __MMI_UM_CONVERSATION_BOX__
                     )
                #endif /* __MMI_UM_CONVERSATION_BOX__ */
                    )
            #endif /* __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__ */
                {
                #ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
                    if (((MMI_UM_FOLDER_MODE_THREAD_MSG == folder_mode) && 
                    (mmi_sms_um_bt_ui_fsm_ef_get_action(&(scrn_cntx->fsm)) == MMI_UM_UI_ACTION_GET_MSG_CONTENT)))
                    {
                        break;
                    }
                #endif /* __MMI_UM_CONVERSATION_BOX_ENHANCE__ */
                    scrn_cntx->child_scrn_id = mmi_sms_um_bt_ui_if_entry_processing(scrn_id, scrn_cntx->group_id, MMI_FALSE);
                    mmi_sms_um_bt_ui_ut_send_init_event(scrn_cntx->child_scrn_id);
                }
            }
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}

mmi_um_tab_page mmi_sms_bt_idx_to_tab_page(srv_sms_btmapc_bt_enum bt_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_entry_tab_enum tab_pages_enter;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (bt_index)
    {
        case SRV_SMS_BTMAPC_BT_INDEX0:
        {
            tab_pages_enter = MMI_SMS_UM_BT_UI_TAB1;
            break;
        }
        case SRV_SMS_BTMAPC_BT_INDEX1:
        {
            tab_pages_enter = MMI_SMS_UM_BT_UI_TAB2;
            break;
        }
        case SRV_SMS_BTMAPC_BT_INDEX2:
        {
			tab_pages_enter = MMI_SMS_UM_BT_UI_TAB0;
            break;
        }
        default:
        {
            break;
        }        
    }
    return tab_pages_enter;
}

void mmi_sms_um_bt_ui_sh_general_folder_tab_entry(mmi_scrn_essential_struct* scr_ess)
{
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx = scr_ess->user_data;

#ifdef __MMI_TELEPHONY_SUPPORT__
    mmi_frm_tab_struct tab_pages_info_array[2] = {0};
#endif
    U16 i;
    U16 num_item;
    srv_um_list_cntx_struct *data_list;
    mmi_sms_um_bt_ui_aprc_st_union aprc_union;
    mmi_sms_um_bt_ui_aprc_st_folder_struct *aprc;
    
    MMI_ID lsk_str_id = 0;
    MMI_ID lsk_icon_id = 0;
    MMI_ID csk_icon_id = 0;
    void (*lsk_hdlr)(void) = NULL;     /* Left soft key handler */
    void (*csk_hdlr)(void) = NULL;     /* Center soft key handler */
    
#ifdef __MMI_UM_CONVERSATION_BOX__
    MMI_BOOL result;
    U16 title_len = 0;
    U8 *hint_asc;
    srv_um_bt_msg_info_struct **msg_detail_info;
#endif /* __MMI_UM_CONVERSATION_BOX__ */
    mmi_sms_um_entry_folder_evt_struct entry_folder_evt;
    mmi_sms_bt_box_enum mmi_box_type;
    SrvSmsCallbackFunc func = NULL;

    mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx;
    mmi_sms_um_bt_ui_fsm_entry_folder_struct *fsm;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_prompt_trace(MOD_MMI, "[SMS], Entry mmi_sms_um_bt_ui_sh_general_folder_tab_entry");
    memset(&aprc_union, 0, sizeof(mmi_sms_um_bt_ui_aprc_st_union));
    aprc = &(aprc_union.folder);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    if (g_sms_bt_aprc_enter_tab)
    {
        //memcpy(&g_sms_bt_sh_get_item_scrn_cntx, scrn_cntx, sizeof(mmi_sms_um_bt_ui_cc_scrn_cntx_struct));
        //g_sms_bt_aprc_enter_tab = MMI_FALSE;
        g_sms_bt_sh_get_item_scrn_cntx = scrn_cntx;
        g_sms_bt_aprc_enter_tab = MMI_FALSE;
    }
    else
    {
        scrn_cntx = g_sms_bt_sh_get_item_scrn_cntx;
    }

    if (g_sms_bt_ui_p[g_sms_active_dev_index].mmi_need_update_list)
    {        
        scrn_cntx->fsm.cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_TRUE;
    }
    
    /*check if need refresh*/
    g_sms_bt_mmi_box_type = scrn_cntx->fsm.cntx.fsm_entry_folder.folder_type.msg_box_type;
    switch (g_sms_bt_mmi_box_type)
    {
        case SRV_UM_MSG_BTMAPC_BOX_INBOX:
        {
            mmi_box_type = MMI_SMS_BT_BOX_INBOX;
            func = mmi_sms_bt_get_inbox_list_cb;
            break;
        }
        case SRV_UM_MSG_BTMAPC_BOX_OUTBOX:
        {
            mmi_box_type = MMI_SMS_BT_BOX_OUTBOX;
            func = mmi_sms_bt_get_outbox_list_cb;
            break;
        }
        case SRV_UM_MSG_BTMAPC_BOX_DRAFTS:
        {
            mmi_box_type = MMI_SMS_BT_BOX_DRAFTS;
            func = mmi_sms_bt_get_drafts_list_cb;
            break;
        }
        case SRV_UM_MSG_BTMAPC_BOX_UNSENT:
        {
            mmi_box_type = MMI_SMS_BT_BOX_UNSENT;
            func = mmi_sms_bt_get_unsent_list_cb;
            break;
        }
        //lifang
        default:
        {
            mmi_box_type = MMI_SMS_BT_BOX_INBOX;
            func = mmi_sms_bt_get_inbox_list_cb;
            break;
        }
    }
    
    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);
    if (fsm->folder_info.data_list)
    {
        fsm->folder_info.data_list->msg_number = srv_sms_btmapc_get_list_size(fsm->folder_type.msg_box_type);
    }
    
    /* set the number of items */
    num_item = mmi_sms_um_bt_ui_sh_general_folder_get_msg_num(scrn_cntx);
    data_list = mmi_sms_um_bt_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    /* if data list is NULL, it means FSM does not have the correct message number info. */
    if (NULL != data_list)
    {
        scrn_cntx->screen_hdlr.num_of_item = num_item;

        /* error handling for highlight */
        if (scrn_cntx->screen_hdlr.hilite_info.index >= num_item &&
            num_item != 0)
        {
            /* highlight to last one */
            scrn_cntx->screen_hdlr.hilite_info.index = num_item - 1;
        }
    }

    /* If there is no message, the lsk string should not display */
    if (0 != scrn_cntx->screen_hdlr.num_of_item)
    {
        lsk_str_id = STR_GLOBAL_VIEW;
        lsk_icon_id = IMG_GLOBAL_OPTIONS;
        csk_icon_id = IMG_GLOBAL_COMMON_CSK;
        lsk_hdlr = mmi_sms_um_bt_ui_sh_general_folder_lsk_hdlr;
        csk_hdlr = mmi_sms_um_bt_ui_sh_general_folder_csk_hdlr;
    }
#if defined(__MMI_UM_FILTER_BY_SIM_SUPPORT__)
    else if((scrn_cntx->fsm.cntx.fsm_entry_folder.folder_mode == MMI_UM_FOLDER_MODE_DEFAULT) &&
                ((scrn_cntx->fsm.cntx.fsm_entry_folder.folder_type.msg_box_type !=  SRV_UM_MSG_BTMAPC_BOX_DRAFTS) &&
                (scrn_cntx->fsm.cntx.fsm_entry_folder.folder_type.msg_box_type !=  SRV_UM_MSG_BOX_ARCHIVE)))
                
    {
        //lsk_str_id = STR_UM_FILTER_BY;
        lsk_icon_id = IMG_GLOBAL_OPTIONS;
        csk_icon_id = IMG_GLOBAL_OPTION_CSK;
        lsk_hdlr = mmi_sms_um_bt_ui_sh_general_folder_lsk_hdlr;
        csk_hdlr = mmi_sms_um_bt_ui_sh_general_folder_csk_hdlr;
    }
#endif /* __MMI_UM_FILTER_BY_SIM_SUPPORT__ */

    mmi_sms_um_bt_ui_sh_set_general_cntx(
            &aprc->general_aprc_cntx, 
            scrn_cntx->group_id, 
            scrn_cntx->screen_hdlr.disp_scrn_id, 
            0, 
            mmi_sms_um_bt_ui_ut_get_str_id_by_folder(scrn_cntx->screen_hdlr.folder_type), 
            IMG_UM_ENTRY_SCRN_CAPTION, 
            lsk_str_id, 
            lsk_icon_id, 
            STR_GLOBAL_BACK, 
            IMG_GLOBAL_BACK, 
            csk_icon_id, 
            mmi_sms_um_bt_ui_sh_general_folder_hilite_hdlr, 
            scrn_cntx->screen_hdlr.hilite_info.index, 
            scrn_cntx->screen_hdlr.num_of_item, 
            mmi_sms_um_bt_ui_sh_general_folder_entry, 
            mmi_sms_um_bt_ui_sh_general_folder_exit, 
            NULL, 
            lsk_hdlr, 
            mmi_sms_um_bt_ui_sh_general_folder_rsk_hdlr, 
            csk_hdlr, 
            mmi_sms_um_bt_ui_sh_general_folder_leave_proc);
    {
        aprc->get_item_cb = mmi_sms_um_bt_ui_sh_get_async_item;
    }
    aprc->get_item_hint_cb = NULL;
    aprc->hilite_notify_cb = mmi_sms_um_bt_ui_sh_general_folder_notify_highlight;
    //scrn_cntx->screen_hdlr.is_scrn_displayed = scrn_cntx->aprc.draw_func(&aprc_union, scrn_cntx->aprc.st_type);

    memcpy(&g_sms_bt_aprc_int_cntx, aprc, sizeof(mmi_sms_um_bt_ui_aprc_263_struct));
    
#ifdef __MMI_TELEPHONY_SUPPORT__ 
    tab_pages_info_array[0].screen_id = aprc->general_aprc_cntx.scrn_id + 1;
    tab_pages_info_array[0].tab_entry_func = (FuncPtr)mmi_sms_bt_um_ui_aprc_263_tab_local;
#ifdef __MMI_MAINLCD_240X320__
    tab_pages_info_array[0].tab_icon = (U8*)GetImage(IMG_UM_LOCAL);
    tab_pages_info_array[0].tab_string = 0;
#else
    tab_pages_info_array[0].tab_icon = 0;
    tab_pages_info_array[0].tab_string = (U8*)GetString(STR_UM_LOCAL);
#endif
    tab_pages_info_array[0].user_data = scrn_cntx;
    
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    tab_pages_info_array[1].screen_id = aprc->general_aprc_cntx.scrn_id;
#else
    tab_pages_info_array[1].screen_id = aprc->general_aprc_cntx.scrn_id + 2;
#endif
    tab_pages_info_array[1].tab_entry_func = (FuncPtr)mmi_sms_bt_um_ui_aprc_263_tab_BT;
#ifdef __MMI_MAINLCD_240X320__
    tab_pages_info_array[1].tab_icon = (U8*)GetImage(IMG_UM_BT);
    tab_pages_info_array[1].tab_string = 0;
#else
    tab_pages_info_array[1].tab_icon = 0;
    tab_pages_info_array[1].tab_string = (U8*)GetString(STR_UM_BT);
#endif
    tab_pages_info_array[1].user_data = scrn_cntx;

#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    cui_tab_create(
        aprc->general_aprc_cntx.grp_id, 
        aprc->general_aprc_cntx.scrn_id,
        tab_pages_info_array,
        2,
        1,
        scrn_cntx
    ); 
#else
    mmi_frm_scrn_tab_enter(
       aprc->general_aprc_cntx.grp_id, 
       aprc->general_aprc_cntx.scrn_id,
       mmi_sms_um_bt_ui_sh_general_folder_exit, 
       (FuncPtr)mmi_sms_um_bt_ui_sh_general_folder_tab_entry, 
       tab_pages_info_array, 
       2, 
       1);
#endif/*__MMI_TAB_BAR_SUPPORT_TAB_PAGE__*/    
#else
    {
        mmi_scrn_essential_struct ess_struct;
        ess_struct.scrn_id = scrn_cntx->screen_hdlr.disp_scrn_id;
        ess_struct.group_id = scrn_cntx->group_id;
        ess_struct.user_data = scrn_cntx;
        mmi_sms_bt_um_ui_aprc_263_tab_BT(&ess_struct);
    }
#endif    

    if (mmi_is_redrawing_bk_screens() == MMI_TRUE)
    {
        return;
    }
    
    /* After drawing, the child should be removed */
    mmi_sms_um_bt_ui_ut_del_relative_scrn(&(scrn_cntx->child_scrn_id));
    if (g_bt_category_error_flag)
        scrn_cntx->screen_hdlr.is_scrn_displayed = g_bt_category_error_flag;
    /* Due to the category usage, it should check the screen is displayed or not */
    if (scrn_cntx->screen_hdlr.is_scrn_displayed == MMI_FALSE || g_sms_bt_ui_p[g_sms_active_dev_index].mmi_need_update_list)
    {
        #if defined(__MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__)
        MMI_fixed_list_menu.n_items = num_item;
        MMI_fixed_list_menu.highlighted_item = scrn_cntx->screen_hdlr.hilite_info.index;
        #endif
        g_sms_bt_ui_p[g_sms_active_dev_index].mmi_need_update_list = MMI_FALSE;
        mmi_sms_um_bt_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_CHECK, NULL);
    #ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
        if (MMI_UM_FOLDER_MODE_THREAD_MSG == mmi_sms_um_bt_ui_fsm_ef_get_folder_mode(&scrn_cntx->fsm))
        {
            scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_TRUE;
        }
     #endif /* __MMI_UM_CONVERSATION_BOX_ENHANCE__ */

    }
    /* global setting reset */
    if (MMI_TRUE == scrn_cntx->screen_hdlr.is_scrn_displayed)
    {
        if (g_sms_bt_ui_p[g_sms_active_dev_index].need_refresh[mmi_box_type] && 
            g_sms_bt_ui_p[g_sms_active_dev_index].is_bt_connected &&
            !g_sms_bt_ui_p[g_sms_active_dev_index].is_on_request)
        {   
            mmi_sms_bt_entry_folder_userdata *userdata;

            scrn_cntx->screen_hdlr.is_scrn_displayed == MMI_TRUE;
            g_bt_category_error_flag = MMI_TRUE;
            //g_sms_bt_ui_p->mmi_need_update_list = MMI_TRUE;
            userdata = &g_ef_usdata;
            userdata->is_back_folder = MMI_TRUE;
            userdata->scrn_id = scrn_cntx->scrn_id;
            kal_prompt_trace(MOD_MMI, "[SMS], Entry mmi_sms_um_bt_ui_sh_general_folder_tab_entry is_scrn_displayed");
            scrn_cntx->child_scrn_id = mmi_sms_um_bt_ui_if_entry_processing(scrn_cntx->scrn_id, scrn_cntx->group_id, MMI_FALSE);
            g_sms_bt_ui_p[g_sms_active_dev_index].is_on_request = MMI_TRUE;
            g_sms_bt_ui_p[g_sms_active_dev_index].sms_handle = srv_sms_btmapc_get_msg_list_by_tab(g_sms_active_dev_index, MMI_TRUE,
                scrn_cntx->fsm.cntx.fsm_entry_folder.folder_type.msg_box_type,
                func,
                userdata);

            mmi_sms_um_bt_ui_ut_send_init_event(scrn_cntx->child_scrn_id);
            return;
        }
        /* Send the event out */
        MMI_FRM_INIT_EVENT(&entry_folder_evt, EVT_ID_MMI_SMS_UM_BT_ENTRY_FOLDER);
        entry_folder_evt.is_entry = MMI_TRUE;
        entry_folder_evt.msg_box = scrn_cntx->screen_hdlr.folder_type.msg_box_type;
        entry_folder_evt.um_user_data = (void *)scrn_cntx;
        MMI_FRM_CB_EMIT_POST_EVENT(&entry_folder_evt);
    }
}


void mmi_sms_um_bt_ui_sh_general_folder_entry(mmi_scrn_essential_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 num_item;
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    srv_um_list_cntx_struct *data_list;
    mmi_sms_um_bt_ui_aprc_st_union aprc_union;
    mmi_sms_um_bt_ui_aprc_st_folder_struct *aprc;
    
    MMI_ID lsk_str_id = 0;
    MMI_ID lsk_icon_id = 0;
    MMI_ID csk_icon_id = 0;
    void (*lsk_hdlr)(void) = NULL;     /* Left soft key handler */
    void (*csk_hdlr)(void) = NULL;     /* Center soft key handler */
    
#ifdef __MMI_UM_CONVERSATION_BOX__
    MMI_BOOL result;
    U16 title_len = 0;
    U8 *hint_asc;
    srv_um_bt_msg_info_struct **msg_detail_info;
#endif /* __MMI_UM_CONVERSATION_BOX__ */
    mmi_sms_um_entry_folder_evt_struct entry_folder_evt;

    srv_um_msg_btmapc_box_enum box_type;
    mmi_sms_bt_box_enum mmi_box_type;


    SrvSmsCallbackFunc func = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    memset(&aprc_union, 0, sizeof(mmi_sms_um_bt_ui_aprc_st_union));
    aprc = &(aprc_union.folder);
    scrn_cntx = (mmi_sms_um_bt_ui_cc_scrn_cntx_struct *)arg->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    /*check if need refresh*/
    box_type = scrn_cntx->fsm.cntx.fsm_entry_folder.folder_type.msg_box_type;
    switch (box_type)
    {
        case SRV_UM_MSG_BTMAPC_BOX_INBOX:
        {
            mmi_box_type = MMI_SMS_BT_BOX_INBOX;
            func = mmi_sms_bt_get_inbox_list_cb;
            break;
        }
        case SRV_UM_MSG_BTMAPC_BOX_OUTBOX:
        {
            mmi_box_type = MMI_SMS_BT_BOX_OUTBOX;
            func = mmi_sms_bt_get_outbox_list_cb;
            break;
        }
        case SRV_UM_MSG_BTMAPC_BOX_DRAFTS:
        {
            mmi_box_type = MMI_SMS_BT_BOX_DRAFTS;
            func = mmi_sms_bt_get_drafts_list_cb;
            break;
        }
        case SRV_UM_MSG_BTMAPC_BOX_UNSENT:
        {
            mmi_box_type = MMI_SMS_BT_BOX_UNSENT;
            func = mmi_sms_bt_get_unsent_list_cb;
            break;
        }
        //lifang
        default:
        {
            mmi_box_type = MMI_SMS_BT_BOX_INBOX;
            func = mmi_sms_bt_get_unsent_list_cb;
            break;
        }
    }
    
    /* set the number of items */
    num_item = mmi_sms_um_bt_ui_sh_general_folder_get_msg_num(scrn_cntx);
    data_list = mmi_sms_um_bt_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    /* if data list is NULL, it means FSM does not have the correct message number info. */
    if (NULL != data_list)
    {
        scrn_cntx->screen_hdlr.num_of_item = num_item;
        /* search the specified highlight index based on the highlight msg id and msg type*/
        if (NULL != data_list)
        {
            for (i = 0; i < num_item; i++)
            {
                if (((srv_um_msg_node_struct*)data_list->list)[i].msg_id == scrn_cntx->screen_hdlr.hilite_info.msg_id &&
                    ((srv_um_msg_node_struct*)data_list->list)[i].msg_type == scrn_cntx->screen_hdlr.hilite_info.msg_type)
                {
                    scrn_cntx->screen_hdlr.hilite_info.index = i;
                    break;
                }
            }
        }
        
        /* error handling for highlight */
        if (scrn_cntx->screen_hdlr.hilite_info.index >= num_item &&
            num_item != 0)
        {
            /* highlight to last one */
            scrn_cntx->screen_hdlr.hilite_info.index = num_item - 1;
        }
    }

    /* If there is no message, the lsk string should not display */
    if (0 != scrn_cntx->screen_hdlr.num_of_item)
    {
        lsk_str_id = STR_GLOBAL_VIEW;
        lsk_icon_id = IMG_GLOBAL_OPTIONS;
        csk_icon_id = IMG_GLOBAL_COMMON_CSK;
        lsk_hdlr = mmi_sms_um_bt_ui_sh_general_folder_lsk_hdlr;
        csk_hdlr = mmi_sms_um_bt_ui_sh_general_folder_csk_hdlr;
    }
#if defined(__MMI_UM_FILTER_BY_SIM_SUPPORT__)
    else if((scrn_cntx->fsm.cntx.fsm_entry_folder.folder_mode == MMI_UM_FOLDER_MODE_DEFAULT) &&
                ((scrn_cntx->fsm.cntx.fsm_entry_folder.folder_type.msg_box_type !=  SRV_UM_MSG_BTMAPC_BOX_DRAFTS) &&
                (scrn_cntx->fsm.cntx.fsm_entry_folder.folder_type.msg_box_type !=  SRV_UM_MSG_BOX_ARCHIVE)))
                
    {
        lsk_str_id = STR_UM_FILTER_BY;
        lsk_icon_id = IMG_GLOBAL_OPTIONS;
        csk_icon_id = IMG_GLOBAL_OPTION_CSK;
        lsk_hdlr = mmi_sms_um_bt_ui_sh_general_folder_lsk_hdlr;
        csk_hdlr = mmi_sms_um_bt_ui_sh_general_folder_csk_hdlr;
    }
#endif /* __MMI_UM_FILTER_BY_SIM_SUPPORT__ */

    mmi_sms_um_bt_ui_sh_set_general_cntx(
            &aprc->general_aprc_cntx, 
            scrn_cntx->group_id, 
            scrn_cntx->screen_hdlr.disp_scrn_id, 
            0, 
            mmi_sms_um_bt_ui_ut_get_str_id_by_folder(scrn_cntx->screen_hdlr.folder_type), 
            IMG_UM_ENTRY_SCRN_CAPTION, 
            lsk_str_id, 
            lsk_icon_id, 
            STR_GLOBAL_BACK, 
            IMG_GLOBAL_BACK, 
            csk_icon_id, 
            mmi_sms_um_bt_ui_sh_general_folder_hilite_hdlr, 
            scrn_cntx->screen_hdlr.hilite_info.index, 
            scrn_cntx->screen_hdlr.num_of_item, 
            mmi_sms_um_bt_ui_sh_general_folder_entry, 
            mmi_sms_um_bt_ui_sh_general_folder_exit, 
            NULL, 
            lsk_hdlr, 
            mmi_sms_um_bt_ui_sh_general_folder_rsk_hdlr, 
            csk_hdlr, 
            mmi_sms_um_bt_ui_sh_general_folder_leave_proc);
    {
        aprc->get_item_cb = mmi_sms_um_bt_ui_sh_get_async_item;
    }
    aprc->get_item_hint_cb = NULL;
    aprc->hilite_notify_cb = mmi_sms_um_bt_ui_sh_general_folder_notify_highlight;
    scrn_cntx->screen_hdlr.is_scrn_displayed = scrn_cntx->aprc.draw_func(&aprc_union, scrn_cntx->aprc.st_type);

    if (mmi_is_redrawing_bk_screens() == MMI_TRUE)
    {
        return;
    }
    
    /* After drawing, the child should be removed */
    mmi_sms_um_bt_ui_ut_del_relative_scrn(&(scrn_cntx->child_scrn_id));
    
    /* Due to the category usage, it should check the screen is displayed or not */
    if (scrn_cntx->screen_hdlr.is_scrn_displayed == MMI_FALSE)
    {
        mmi_sms_um_bt_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_CHECK, NULL);
    #ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
        if (MMI_UM_FOLDER_MODE_THREAD_MSG == mmi_sms_um_bt_ui_fsm_ef_get_folder_mode(&scrn_cntx->fsm))
        {
            scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_TRUE;
        }
     #endif /* __MMI_UM_CONVERSATION_BOX_ENHANCE__ */
    }
    
    /* global setting reset */
    if (MMI_TRUE == scrn_cntx->screen_hdlr.is_scrn_displayed)
    {
        /* Send the event out */
        MMI_FRM_INIT_EVENT(&entry_folder_evt, EVT_ID_MMI_SMS_UM_BT_ENTRY_FOLDER);
        entry_folder_evt.is_entry = MMI_TRUE;
        entry_folder_evt.msg_box = scrn_cntx->screen_hdlr.folder_type.msg_box_type;
        entry_folder_evt.um_user_data = (void *)scrn_cntx;
        MMI_FRM_CB_EMIT_POST_EVENT(&entry_folder_evt);
    }
}
void mmi_sms_um_bt_ui_sh_general_folder_exit(mmi_scrn_essential_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_um_entry_folder_evt_struct entry_folder_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = (mmi_sms_um_bt_ui_cc_scrn_cntx_struct *)arg->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

#ifdef __MMI_UM_CONVERSATION_BOX__
    if (NULL != scrn_cntx->aprc.user_data)
    {
        OslMfree(scrn_cntx->aprc.user_data);
        scrn_cntx->aprc.user_data = NULL;
    }
#endif /* __MMI_UM_CONVERSATION_BOX__ */
    scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_FALSE;

    /* Send the event out */
    MMI_FRM_INIT_EVENT(&entry_folder_evt, EVT_ID_MMI_SMS_UM_BT_ENTRY_FOLDER);
    entry_folder_evt.is_entry = MMI_FALSE;
    entry_folder_evt.msg_box = scrn_cntx->screen_hdlr.folder_type.msg_box_type;
    entry_folder_evt.um_user_data = (void *)scrn_cntx;
    MMI_FRM_CB_EMIT_POST_EVENT(&entry_folder_evt);
}

U8 mmi_sms_um_bt_ui_sh_general_folder_destroy(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clean the cache memory */
    srv_um_sms_clear_msg_info_cache(SRV_UM_MSG_ALL, SRV_UM_MSG_BOX_ALL);
    result = mmi_sms_um_bt_ui_sh_destroy(arg);

    return result;
}
mmi_ret mmi_sms_um_bt_ui_sh_general_folder_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_RET_OK;

    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
        #ifdef __GENERAL_TTS__
            mmi_sms_um_bt_ui_tts_stop();
        #endif
            wgui_set_menu_empty_string_by_id(STR_GLOBAL_EMPTY);

            mmi_sms_um_bt_ui_sh_general_folder_destroy(evt->user_data);

            #ifndef __MMI_TELEPHONY_SUPPORT__
                srv_sms_btmapc_delete_all();
            #else
                srv_sms_btmapc_storage_reset_data(MMI_TRUE);
            #endif

            g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered = SRV_SMS_BTMAPC_BOX_NONE;
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_set_sms_context
 * DESCRIPTION
 *  Get inbox message header
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_bt_um_set_sms_context(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_box_enum msg_box_type;
    mmi_sms_bt_list_enum list_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_get_msg_list_index(&msg_box_type, (U16) msg_id);

	switch (msg_box_type)
    {
        case SRV_SMS_BOX_INBOX:
            list_type = MMI_SMS_BT_LIST_INBOX;
            break;

        case SRV_SMS_BOX_UNSENT:
            list_type = MMI_SMS_BT_LIST_UNSENT;
            break;

        case SRV_SMS_BOX_OUTBOX:
            list_type = MMI_SMS_BT_LIST_OUTBOX;
            break;

        case SRV_SMS_BOX_DRAFTS:
            list_type = MMI_SMS_BT_LIST_DRAFTS;
            break;

    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__        
        case SRV_SMS_BOX_ARCHIVE:
            list_type = MMI_SMS_BT_LIST_ARCHIVE;
            break;
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case SRV_SMS_BOX_SIM:
            list_type = MMI_SMS_BT_LIST_SIMBOX;
            break;
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

    #ifdef __MMI_UM_REPORT_BOX__
        case SRV_SMS_BOX_REPORT:
            list_type = MMI_SMS_BT_LIST_REPORT;
            break; 
    #endif /* __MMI_UM_REPORT_BOX__ */

        default:
            list_type = MMI_SMS_BT_LIST_NONE;
            break;
    }

    g_sms_bt_cntx.curr_msg_id = (U16)msg_id;
    g_sms_bt_cntx.curr_box_type = msg_box_type;
    g_sms_bt_cntx.curr_list_type = list_type;
}


void mmi_sms_um_bt_ui_sh_general_folder_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID opt_grp_id;
    MMI_ID opt_menu_id;
    MMI_MENU_ID msg_menu_id;
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    srv_um_list_cntx_struct *data_list;
	mmi_sms_um_opt_para_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_sms_um_bt_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

   // g_sms_cntx.curr_msg_id = 

	memset(&para, 0, sizeof(mmi_sms_um_opt_para_struct));
                para.msg_id = scrn_cntx->screen_hdlr.hilite_info.msg_id;
                para.parent_grp_id = mmi_sms_um_bt_ui_cc_get_root_grp_id(scrn_cntx->group_id);
                para.display_flag = MMI_TRUE;
                para.user_data = (void *)scrn_cntx;

	 mmi_sms_bt_um_set_sms_context( para.msg_id);

            g_sms_bt_cntx.is_from_hs = MMI_FALSE;
			mmi_sms_bt_group_entry(para.parent_grp_id);
	        mmi_sms_bt_box_list_opt_pre_view();
}
void mmi_sms_um_bt_ui_sh_general_folder_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_exit_folder = MMI_TRUE;
    mmi_sms_um_bt_ui_sh_rsk_hdlr();
    #ifdef __MMI_TELEPHONY_SUPPORT__
    mmi_um_ui_sh_rsk_hdlr();
    #endif
    mmi_frm_scrn_close(g_sms_um_ui_p->cc_cntx.grp_table[0].grp_id, g_um_loading_scrn_id);
    g_tab_last_enter = MMI_UM_TAB_PAGE_BT;
    
}
void mmi_sms_um_bt_ui_sh_general_folder_csk_hdlr(void)
{
        mmi_sms_um_bt_ui_sh_general_folder_lsk_hdlr();
}
U16 mmi_sms_um_bt_ui_sh_general_folder_get_msg_num(mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 num_of_item;
    mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx;
    mmi_sms_um_bt_ui_fsm_entry_folder_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num_of_item = 0;

    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);

    num_of_item = fsm->get_msg_num(scrn_cntx->scrn_id);

    return num_of_item;
}

void mmi_sms_um_bt_ui_sh_general_folder_hilite_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined( __MMI_UM_REPORT_BOX__ ) || defined (__GENERAL_TTS__)
    srv_um_msg_btmapc_box_enum hilite_msg_box_type;
#endif /* defined( __MMI_UM_REPORT_BOX__ ) || defined (__GENERAL_TTS__) */
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx;
    mmi_sms_um_bt_ui_fsm_entry_folder_struct *fsm;
    MMI_BOOL result;
    srv_um_bt_msg_info_struct **msg_detail_info;
    srv_um_list_cntx_struct *data_list;
#ifdef __MMI_FTE_SUPPORT__
    mmi_sms_um_bt_ui_aprc_st_union aprc_union;
    mmi_sms_um_bt_ui_aprc_st_folder_struct *aprc;
    mmi_sms_um_bt_ui_folder_mode_enum folder_mode;
#endif /* __MMI_FTE_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_sms_um_bt_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);
    result = fsm->get_msg_info(scrn_cntx->scrn_id, (U16) index, 1, &msg_detail_info, NULL);
    data_list = mmi_sms_um_bt_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));

    /* Tricky for category bugs */
    if (result == MMI_FALSE)
    {
        return;
    }
    /* Tricky for category bugs */
    MMI_ASSERT(result != MMI_FALSE);
    MMI_ASSERT(data_list != NULL);

    /* Set highlight message id & type */
    scrn_cntx->screen_hdlr.hilite_info.index = index;
    g_sms_bt_aprc_int_cntx.general_aprc_cntx.hilite_idx = index;
    scrn_cntx->screen_hdlr.hilite_info.msg_id = ((srv_um_msg_node_struct*)data_list->list)[index].msg_id;
    scrn_cntx->screen_hdlr.hilite_info.msg_type = ((srv_um_msg_node_struct*)data_list->list)[index].msg_type;
    {
        ChangeCenterSoftkey(0, msg_detail_info[0]->csk_icon_id);
    }

}
void mmi_sms_um_bt_ui_sh_general_folder_notify_highlight(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    srv_um_list_cntx_struct *data_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_sms_um_bt_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    data_list = mmi_sms_um_bt_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    
    if (data_list != NULL)
    {
        /* Set highlight message id & type */
        scrn_cntx->screen_hdlr.hilite_info.index = index;
        g_sms_bt_aprc_int_cntx.general_aprc_cntx.hilite_idx = index;
        scrn_cntx->screen_hdlr.hilite_info.msg_id = ((srv_um_msg_node_struct*)data_list->list)[index].msg_id;
        scrn_cntx->screen_hdlr.hilite_info.msg_type = ((srv_um_msg_node_struct*)data_list->list)[index].msg_type;
    }
}

mmi_sms_um_entry_func_ptr mmi_sms_um_bt_ui_sh_general_folder_get_entry_func(mmi_sms_um_bt_ui_folder_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_entry_func_ptr func_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    func_ptr = NULL;

    switch (mode)
    {
        case MMI_UM_FOLDER_MODE_DEFAULT:
        {
            func_ptr = mmi_sms_um_bt_ui_sh_general_folder_tab_entry;
            break;
        }
    #ifdef __MMI_UM_CONVERSATION_BOX__
        case MMI_UM_FOLDER_MODE_CONVERSATION_BOX:
        {
            func_ptr = mmi_sms_um_bt_ui_sh_cs_entry;
            break;
        }
        case MMI_UM_FOLDER_MODE_THREAD_MSG:
        {
            func_ptr = mmi_sms_um_bt_ui_sh_general_folder_tab_entry;
            break;
        }
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return func_ptr;
}
MMI_BOOL mmi_sms_um_bt_ui_sh_write_msg_init(
                    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx, 
                    mmi_sms_um_bt_ui_cc_scrn_cntx_setting_struct *setting)
{
	return;
    //return mmi_sms_um_bt_ui_sh_non_fsm_init(scrn_cntx, setting);
}

MMI_BOOL mmi_sms_um_bt_ui_sh_write_msg_event_hdlr(U16 scrn_id, U16 event, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    result = MMI_TRUE;
    switch (event)
    {
        case MMI_UM_UI_EVENT_INIT:
        {
            mmi_sms_um_bt_ui_sh_create(mmi_sms_um_bt_ui_sh_write_msg_entry, scrn_cntx);
            break;
        }
        case MMI_UM_UI_EVENT_DELETE:
        {
            mmi_sms_um_bt_ui_sh_evt_hdlr_delete(scrn_cntx, arg);
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}
MMI_BOOLmmi_sms_um_bt_ui_sh_write_msg_event_hdlr(U16 scrn_id, U16 event, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx =mmi_sms_um_bt_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    result = MMI_TRUE;
    switch (event)
    {
        case MMI_UM_UI_EVENT_INIT:
        {
           mmi_sms_um_bt_ui_sh_create(mmi_sms_um_bt_ui_sh_write_msg_entry, scrn_cntx);
            break;
        }
        case MMI_UM_UI_EVENT_DELETE:
        {
           mmi_sms_um_bt_ui_sh_evt_hdlr_delete(scrn_cntx, arg);
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}
void mmi_sms_um_bt_ui_sh_write_msg_entry(mmi_scrn_essential_struct *arg)
{
   mmi_sms_um_bt_ui_sh_setting_write_msg_entry(arg, 0);
}
void mmi_sms_um_bt_ui_sh_write_msg_hilite_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx =mmi_sms_um_bt_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    scrn_cntx->screen_hdlr.hilite_info.index = (U16)index;
}
void mmi_sms_um_bt_ui_sh_write_msg_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 hilite_menu_id;
    MMI_ID root_grp_id;
   mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx =mmi_sms_um_bt_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    hilite_menu_id = GetSeqItemId_Ext((U16)MENU_ID_UM_WRITE_MSG, scrn_cntx->screen_hdlr.hilite_info.index);

    root_grp_id =mmi_sms_um_bt_ui_cc_get_root_grp_id(scrn_cntx->group_id);
    switch (hilite_menu_id)
    {
        case MENU_ID_UM_WRITE_MSG_SMS:
        {
           mmi_sms_um_bt_ui_adp_cui_launch_by_menu_id(root_grp_id, MENU_ID_UM_WRITE_MSG_SMS);
           mmi_sms_um_bt_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
            break;
        }
    #ifdef __MMI_MMS_IN_UM__
        case MENU_ID_UM_WRITE_MSG_MMS:
        {
           mmi_sms_um_bt_ui_adp_cui_launch_by_menu_id(root_grp_id, MENU_ID_UM_WRITE_MSG_MMS);
           mmi_sms_um_bt_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */
        default:
        {
            break;
        }
    }
}
MMI_BOOL mmi_sms_um_bt_ui_sh_process_init(
                    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx, 
                    mmi_sms_um_bt_ui_cc_scrn_cntx_setting_struct *setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;
    
    /* FSM initialize */
    
    /* Appearance initialize */
    mmi_sms_um_bt_ui_aprc_set_cntx(&(scrn_cntx->aprc), setting->aprc_type);

    /* Screen handler initialize */
    scrn_cntx->screen_hdlr.disp_scrn_id = setting->disp_scrn_id;
    scrn_cntx->screen_hdlr.folder_type = setting->folder;
    memset(&(scrn_cntx->screen_hdlr.hilite_info), 0, sizeof(mmi_sms_um_bt_ui_sh_hilite_info_struct));
    scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_FALSE;
    scrn_cntx->screen_hdlr.num_of_item = 0;
    scrn_cntx->screen_hdlr.scrn_data = setting->scrn_data;

    return result;
    //return mmi_sms_um_bt_ui_sh_non_fsm_init(scrn_cntx, setting);
	return MMI_TRUE;
}

MMI_BOOL mmi_sms_um_bt_ui_sh_process_event_hdlr(U16 scrn_id, U16 event, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    result = MMI_TRUE;
    switch (event)
    {
        case MMI_UM_UI_EVENT_INIT:
        {
            mmi_sms_um_bt_ui_sh_create(mmi_sms_um_bt_ui_sh_process_entry, scrn_cntx);
            break;
        }
        case MMI_UM_UI_EVENT_DELETE:
        {
            StopTimer(MESSAGES_INPROGRESS_TIMER_ID);
            mmi_sms_um_bt_ui_sh_evt_hdlr_delete(scrn_cntx, arg);
            break;
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
        #endif
        default:
        {
            break;
        }
    }

    return result;
}

void mmi_sms_um_bt_ui_sh_process_entry(mmi_scrn_essential_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_msg_enum parent_support_type;
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_um_bt_ui_aprc_st_union aprc_union;
    mmi_sms_um_bt_ui_aprc_st_loading_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&aprc_union, 0, sizeof(mmi_sms_um_bt_ui_aprc_st_union));
    aprc = &(aprc_union.loading);
    scrn_cntx = (mmi_sms_um_bt_ui_cc_scrn_cntx_struct *)arg->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* For popup, it should turn on backlight first */
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    /* General context */
    aprc->general_aprc_cntx.grp_id = scrn_cntx->group_id;
    aprc->general_aprc_cntx.scrn_id = scrn_cntx->screen_hdlr.disp_scrn_id;
    
    /* Check if ready of service */
    parent_support_type = mmi_sms_um_bt_ui_cc_get_support_msg_type_by_scrn_id(scrn_cntx->parent_scrn_id);
    if (srv_um_check_ready_type(parent_support_type))
    {
        /* ready */
        aprc->scrn_effect = MMI_UM_UI_BLOCK_SLIDE_SHOW;
    }
    else
    {
        /* not_ready */
        aprc->general_aprc_cntx.rsk_str_id = STR_GLOBAL_CANCEL;
        aprc->general_aprc_cntx.rsk_icon_id = IMG_GLOBAL_BACK;
        aprc->general_aprc_cntx.key_hdlr.rsk_hdlr = mmi_sms_um_bt_ui_sh_process_rsk_hdlr;
    }
    aprc->general_aprc_cntx.entry_func = mmi_sms_um_bt_ui_sh_process_entry;
    aprc->general_aprc_cntx.leave_proc = mmi_sms_um_bt_ui_sh_leave_proc;

    /* Specified context */
    aprc->msg_icon_id = mmi_get_event_based_image(MMI_EVENT_PROGRESS);
    /* Deleting or Moving */
    aprc->msg_str_id = STR_GLOBAL_LOADING;
    
    scrn_cntx->aprc.draw_func(&aprc_union, scrn_cntx->aprc.st_type);
}
void mmi_sms_um_bt_ui_sh_process_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_sms_um_bt_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* Delete parent screen */
    mmi_sms_um_bt_ui_ut_del_relative_scrn(&(scrn_cntx->parent_scrn_id));

    /* Delete itself */
    mmi_sms_um_bt_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
}
void mmi_sms_um_bt_ui_sh_process_clean_rsk_hdlr(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_um_bt_ui_aprc_st_union aprc_union;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&aprc_union, 0, sizeof(mmi_sms_um_bt_ui_aprc_st_union));
    scrn_cntx = (mmi_sms_um_bt_ui_cc_scrn_cntx_struct *)arg;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* General context */
    scrn_cntx->aprc.redraw_func(&aprc_union, scrn_cntx->aprc.st_type, MMI_UM_UI_APRC_REDRAW_KEY);
}
void mmi_sms_um_bt_ui_sh_create(mmi_sms_um_entry_func_ptr entry_func_ptr, mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    if (SCR_ID_SMS_UM_BT_MAIN_MESSAGE == scrn_cntx->screen_hdlr.disp_scrn_id) //scrn_cntx->screen_hdlr.disp_scrn_id ==)
    {
        mmi_scrn_essential_struct scrn_arg;

        scrn_arg.group_id = scrn_cntx->group_id;
        scrn_arg.scrn_id = scrn_cntx->screen_hdlr.disp_scrn_id;
        scrn_arg.user_data = scrn_cntx;

        entry_func_ptr((mmi_scrn_essential_struct *)&scrn_arg);
    }
    else if (SCR_ID_SMS_UM_BT_FOLDER == scrn_cntx->screen_hdlr.disp_scrn_id)
    {  
        mmi_scrn_essential_struct scrn_arg;

        g_sms_bt_aprc_enter_tab = MMI_TRUE;
        g_bt_category_error_flag = MMI_FALSE;
        scrn_arg.group_id = scrn_cntx->group_id;
        scrn_arg.scrn_id = scrn_cntx->screen_hdlr.disp_scrn_id;
        scrn_arg.user_data = scrn_cntx;
        mmi_frm_scrn_set_user_data(scrn_arg.group_id, 
                             scrn_arg.scrn_id,
                             (void *)scrn_cntx);
        /*mmi_frm_scrn_first_enter(scrn_arg.group_id, 
                             scrn_arg.scrn_id,
                             mmi_sms_um_bt_ui_sh_general_folder_tab_entry,
                             (void*)scrn_arg.user_data);*/
        kal_prompt_trace(MOD_MMI, "[SMS], Entry mmi_sms_um_bt_ui_sh_create mmi_sms_um_bt_ui_sh_general_folder_tab_entry");
        mmi_sms_um_bt_ui_sh_general_folder_tab_entry(&scrn_arg);
    }
    else
    {
        kal_prompt_trace(MOD_MMI, "[SMS], Entry mmi_sms_um_bt_ui_sh_create mmi_is_redrawing_bk_screens");
        if (mmi_is_redrawing_bk_screens() == MMI_TRUE)
        {
            return;
        }
        kal_prompt_trace(MOD_MMI, "[SMS], Entry mmi_sms_um_bt_ui_sh_create mmi_frm_scrn_first_enter");
        mmi_frm_scrn_first_enter(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id, (FuncPtr)entry_func_ptr, (void *)scrn_cntx);
    }
    //OslMfree(scrn_arg);
}
void mmi_sms_um_bt_ui_sh_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_sms_um_bt_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    mmi_sms_um_bt_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
}
U8 mmi_sms_um_bt_ui_sh_destroy(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 fsm_event;
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;

    scrn_cntx = (mmi_sms_um_bt_ui_cc_scrn_cntx_struct *)arg;

    /* Notify parent screen deleted */
    mmi_sms_um_bt_ui_ut_notify_scrn_deleted(scrn_cntx->parent_scrn_id);

    /* Send Delete event to finite state machine if necessary */
    fsm_event = mmi_sms_um_bt_ui_ut_get_fsm_event_by_ui_event(MMI_UM_UI_EVENT_DELETE);
    if (scrn_cntx->fsm.type != MMI_UM_UI_FSM_NONE)
    {
        if (NULL != scrn_cntx->fsm.event_hdlr)
        {
            result = scrn_cntx->fsm.event_hdlr(scrn_cntx->scrn_id, fsm_event, NULL);
        }
    }
    
    /* Delete the screen context */
    if (result == MMI_TRUE)
    {
        mmi_sms_um_bt_ui_cc_delete_scrn_cntx(scrn_cntx->scrn_id);
		//Added for BT dialer, stop timer
		StopTimer(SMS_BT_TIMER_ID);
    }
    else
    {
        MMI_ASSERT(0);
    }

    return MMI_FALSE;
}
mmi_ret mmi_sms_um_bt_ui_sh_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_RET_OK;

    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
            mmi_sms_um_bt_ui_sh_destroy(evt->user_data);
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}
S32 mmi_sms_um_bt_ui_sh_get_async_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_of_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 i;
    U16 copy_len;
    MYTIME time;
    UI_character_type str[MMI_UM_UI_MAX_LEN_TIME_STR];
    UI_character_type msg_time[MMI_UM_UI_MAX_LEN_TIME_STR];
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx;
    mmi_sms_um_bt_ui_fsm_entry_folder_struct *fsm;
    srv_um_bt_msg_info_struct **msg_detail_info;
    srv_um_list_cntx_struct *data_list;
	S32 msg_num=5;
	//S32 temp;
#ifdef __MMI_UM_REPORT_BOX__
    S8 *time_tmp_string = NULL;
#endif /* __MMI_UM_REPORT_BOX__ */
#ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__2
    CHAR *message_contents[MMI_UM_CONTENT_CACHE_UNIT_AMOUNT];
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((!srv_bt_mapc_adp_is_connected(g_sms_active_dev_index) && 
        (srv_sms_btmapc_get_list_size(g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered) == 0)))
    {
        return WGUI_GET_DATA_NONE;
    }
    
    scrn_cntx = mmi_sms_um_bt_ui_sh_get_active_user_data();
    if (scrn_cntx == NULL)
        scrn_cntx = g_sms_bt_sh_get_item_scrn_cntx;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);

	/*********** BT-Dialer No need to get the more than 5 elemets *******/

    result = fsm->get_msg_info(scrn_cntx->scrn_id, 
                               (U16) start_index, 
                               (U16) num_of_item, 
                               &msg_detail_info, 
                               NULL);

    kal_wap_trace(MOD_MMI_COMMON_APP,TRACE_GROUP_7,"Get Async item result: %d",result);
    
    if (result == MMI_FALSE)
    {
        //g_bt_category_error_flag = MMI_FALSE;
        kal_wap_trace(MOD_MMI_COMMON_APP,TRACE_GROUP_7,"Get Async item is displayed: %d",scrn_cntx->screen_hdlr.is_scrn_displayed);
        if (scrn_cntx->screen_hdlr.is_scrn_displayed == MMI_TRUE || 
            (g_sms_um_ui_main_menu_scrn_id == 0 && g_sms_bt_ui_p[g_sms_active_dev_index].mmi_need_update_list))
        {
            mmi_sms_um_bt_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_INIT, NULL);
        #ifdef __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__
            return WGUI_GET_DATA_LOADING;
        #else /* __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__ */
            return WGUI_GET_DATA_NONE;
        #endif /* __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__ */
        }
        else
        {
         //g_bt_category_error_flag = MMI_TRUE;
            g_sms_bt_ui_p[g_sms_active_dev_index].mmi_need_update_list = MMI_TRUE;
        #ifdef __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__
            return WGUI_GET_DATA_LOADING;
        #else /* __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__ */
            return WGUI_GET_DATA_NONE;
        #endif /* __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__ */
        }
    }
    scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_TRUE;
    g_bt_category_error_flag = MMI_TRUE;
    data_list = mmi_sms_um_bt_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    MMI_ASSERT(data_list != NULL);

    /* Has data, copy to the framework */
    for (i = 0; i < num_of_item; i++)
    {

    /*address*/
    if (msg_detail_info[i]->address_length == 0)
    {
        mmi_ucs2ncpy(
            (S8*) menu_data[i].item_list[0],
            (S8*) GetString(STR_GLOBAL_NO_NUMBER),
            SRV_UM_MAX_SUBJECT_LEN);
    }
    else
    {
        copy_len = MAX_SUBMENU_CHARACTERS - 1;
        if (msg_detail_info[i]->address_length < MAX_SUBMENU_CHARACTERS)
        {
            copy_len = msg_detail_info[i]->address_length;
        }
        if (0 == mmi_ucs2strlen((S8*)msg_detail_info[i]->sender_name))
        {  
            mmi_ucs2ncpy((S8*) menu_data[i].item_list[0], 
                     (S8*) msg_detail_info[i]->address, 
                     copy_len);
        }
        else
        {
            mmi_ucs2ncpy((S8*) menu_data[i].item_list[0], 
                         (S8*) msg_detail_info[i]->sender_name, 
                         mmi_ucs2strlen((S8*)msg_detail_info[i]->sender_name));
        }
    }    
    
        /*Timestamp*/
        memset((CHAR*)str, 0, sizeof(str));
        memset((CHAR*)msg_time, 0, sizeof(msg_time));

        copy_len = MAX_SUBMENU_CHARACTERS;
        if (MMI_UM_UI_MAX_LEN_TIME_STR < MAX_SUBMENU_CHARACTERS)
        {
            copy_len = MMI_UM_UI_MAX_LEN_TIME_STR;
        }


        if (msg_detail_info[i]->timestamp != 0)
        {
            U32 local_sec = 0;

            memset(&time, 0, sizeof(MYTIME));
	        mmi_dt_utc_sec_2_mytime(msg_detail_info[i]->timestamp, &time, MMI_FALSE);
            /* Normal time display as IDLE */
            date_string(&time, str, DT_IDLE_SCREEN);
            mmi_ucs2ncpy((S8*) msg_time, (S8*) str, (MMI_UM_UI_MAX_LEN_TIME_STR - 1));
            mmi_ucs2ncat((S8*) msg_time, (S8*) " ", 1);

            time_string(&time, str, DT_IDLE_SCREEN);
            mmi_ucs2ncat((S8*) msg_time, (S8*) str, (MMI_UM_UI_MAX_LEN_TIME_STR - 1));
        }

        mmi_ucs2ncpy(
            (S8*) menu_data[i].item_list[1],
            (S8*) msg_time,
            copy_len);

    #ifdef __MMI_UM_REPORT_BOX__
        /* Concate the time / subject into 1 string in subject/time field in report box */
        if (SRV_UM_MSG_BOX_REPORT == scrn_cntx->screen_hdlr.folder_type.msg_box_type)
        {
            time_tmp_string = OslMalloc(MAX_SUB_MENU_SIZE);
            mmi_ucs2cpy(time_tmp_string, (S8 *)menu_data[i].item_list[1]);
            /* concate into time field */
            mmi_ucs2cat((S8 *) menu_data[i].item_list[1], (S8 *)L" ");
            copy_len = (MAX_SUBMENU_CHARACTERS - 1) - mmi_ucs2strlen((S8 *)menu_data[i].item_list[1]);
            mmi_ucs2ncat((S8 *) menu_data[i].item_list[1], (S8 *) menu_data[i].item_list[0], copy_len);
            /* copy back to subject field */
            copy_len = mmi_ucs2strlen((S8 *) menu_data[i].item_list[1]);
            mmi_ucs2ncpy((S8 *) menu_data[i].item_list[0], (S8 *) menu_data[i].item_list[1], copy_len);
            /* copy the original time string */
            mmi_ucs2cpy((S8 *)menu_data[i].item_list[1], time_tmp_string);
            /* Free the temp data */
            OslMfree(time_tmp_string);
            time_tmp_string = NULL;
        }
    #endif /* __MMI_UM_REPORT_BOX__ */

        /* status icon */
    #ifdef __MMI_UM_CONVERSATION_BOX__
        folder_mode = mmi_sms_um_bt_ui_fsm_ef_get_folder_mode(&(scrn_cntx->fsm));
        if (MMI_UM_FOLDER_MODE_CONVERSATION_BOX == folder_mode)
        {
            if (thread_detail_info[i]->unread_msg_number > 0)
            {
                /* has unread */
                menu_data[i].image_list[0] = (PU8) GetImage(IMG_UM_UNREAD_THREAD_MSG);
            }
            else
            {
                /* all read */
                menu_data[i].image_list[0] = (PU8) GetImage(IMG_UM_READ_THREAD_MSG);
            }
        }
        else
    #endif
        {
            menu_data[i].image_list[0] = (PU8) GetImage(msg_detail_info[i]->icon_id);
        }

        menu_data[i].image_list[1] = NULL;
    }
    //num_of_item=temp;
    return num_of_item;
}

void mmi_sms_um_bt_ui_sh_evt_hdlr_delete(mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_is_present(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id);
    }
    else
    {
        mmi_sms_um_bt_ui_sh_destroy(scrn_cntx);
    }
    /* Destroy function will delete the finite state machine and screen context */
}
mmi_sms_um_bt_ui_cc_scrn_cntx_struct *mmi_sms_um_bt_ui_sh_get_active_user_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID grp_id;
    MMI_ID scrn_id;
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grp_id = mmi_frm_group_get_active_id();
    scrn_id = mmi_frm_scrn_get_active_id();

    user_data = (mmi_sms_um_bt_ui_cc_scrn_cntx_struct *)mmi_frm_scrn_get_user_data(grp_id, scrn_id);

    return user_data;
}

void mmi_sms_um_bt_ui_sh_main_msg_arrange_menu_item(mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	return;
}



///////////////////////////////////////////////////////////////////////

void mmi_sms_um_bt_entry_main_message_menu_with_check()
{
 
}

void mmi_sms_um_bt_close_list_screen()
{
	mmi_frm_scrn_close(g_sms_um_ui_p->cc_cntx.grp_table[0].grp_id,SCR_ID_SMS_UM_BT_FOLDER);
	mmi_frm_scrn_close_active_id();
}
#endif
