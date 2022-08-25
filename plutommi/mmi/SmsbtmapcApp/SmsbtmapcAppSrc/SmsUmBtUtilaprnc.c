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
 *  SmsUmBtMapProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service For BT Header File
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_BT_MAP_CLIENT__

#include "SmsUmBtMapGProt.h"
#include "SmsUmBtMapProt.h"
#include "GlobalResDef.h"
#include "CustMenuRes.h"
#include "mmi_rp_app_smsbtunifiedmessage_def.h"
#if (defined(__MMI_BT_NOTIFICATION__) || defined (__MMI_BT_NOTI_SRV__))
#include "Mmi_rp_app_btnotification_def.h"
#endif
#include "mmi_rp_app_sms_def.h"
#include "BTMMIScrGprots.h"
#include "SmsAppProt.h"
#include "Gui_effect_oem.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "Wgui_fixed_menus.h"
#include "BTNotisrvGprot.h"
#include "wgui_softkeys.h"


#define MMI_UM_BT_TAB_LEFT_X 0
#define MMI_UM_BT_TAB_RIGHT_X 59
#define MMI_UM_BT_TAB_UP_Y 35
#define MMI_UM_BT_TAB_DOWN_Y 58

S32 g_pid;
S32 g_para;
MMI_BOOL g_bt_category_error_flag = MMI_FALSE;
static MMI_BOOL g_is_bt_pen_down_tab = MMI_FALSE;

MMI_ID g_sms_cui_id;



extern mmi_sms_bt_cntx_struct *g_sms_bt_ui_p;
extern mmi_um_tab_page g_tab_last_enter;
extern mmi_um_tab_page g_tab_curr_first_enter;
extern MMI_BOOL g_enter_from_bt;
extern mmi_sms_bt_entry_folder_userdata g_ef_usdata;
extern srv_sms_btmapc_bt_enum	g_sms_active_dev_index;	   /* Bt index ID */


extern void mmi_sms_bt_get_inbox_list_cb(srv_sms_callback_struct* data);
extern void mmi_sms_bt_get_outbox_list_cb(srv_sms_callback_struct* data);
extern void mmi_sms_bt_get_unsent_list_cb(srv_sms_callback_struct* data);
extern void mmi_sms_bt_get_drafts_list_cb(srv_sms_callback_struct* data);
#if defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_BT_DIALER_SUPPORT__)
extern void mmi_bt_dialor_callback(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_connection_type conn_type, MMI_BOOL result,MMI_BOOL is_connect, MMI_BOOL is_indicate);
#endif

//extern void mmi_sms_bt_free_previous_mem(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_bt_ui_ut_get_msg_num_by_msg_box
 * DESCRIPTION
 *  Get the number of message based on the message box type
 *
 * PARAMETERS
 *  msg_box             [IN]: message box type
 *  msg_num_info        [IN]: the message number information
 *
 * RETURNS
 *  Number of messages
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
static void mmi_um_bt_tab_pen_down_handle(mmi_pen_point_struct pos)
{
    if ((pos.x < MMI_UM_BT_TAB_RIGHT_X && pos.x > MMI_UM_BT_TAB_LEFT_X) &&
        (pos.y < MMI_UM_BT_TAB_DOWN_Y && pos.y > MMI_UM_BT_TAB_UP_Y))
    {
        g_is_bt_pen_down_tab = MMI_TRUE;
    }
    else
    {
        g_is_bt_pen_down_tab = MMI_FALSE;
    }
}

static void mmi_um_bt_tab_pen_up_handle(mmi_pen_point_struct pos)
{
    if (g_is_bt_pen_down_tab &&
        (pos.x < MMI_UM_BT_TAB_RIGHT_X && pos.x > MMI_UM_BT_TAB_LEFT_X) &&
        (pos.y < MMI_UM_BT_TAB_DOWN_Y && pos.y > MMI_UM_BT_TAB_UP_Y))
    {
        g_enter_from_bt = MMI_TRUE;
        mmi_sms_um_bt_ui_sh_rsk_hdlr();
    }
    g_is_bt_pen_down_tab = MMI_FALSE;
}

static void mmi_um_bt_tab_pen_handle(S32 index)
{
    if (index == 0)
    {
        g_enter_from_bt = MMI_TRUE;
        mmi_sms_um_bt_ui_sh_rsk_hdlr();
    }
}
#endif

#ifdef __MMI_BT_MAPC_BY_SPP__
void mmi_sms_um_bt_connect_by_spp_cb(MMI_BOOL result)
{
    MMI_ID grp_id = mmi_frm_group_get_active_id();
    mmi_frm_scrn_close(grp_id,SCR_BT_CONNECTING);

    if (!result)
    {
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_FAILURE,
        (WCHAR*)GetString(STR_BT_CONN_FAILED));
    }
}
#endif

void mmi_sms_um_bt_connect_profile_cb(srv_bt_cm_bt_addr *dev_addr, srv_bt_cm_connection_type conn_type,MMI_BOOL result,MMI_BOOL is_connect, MMI_BOOL is_indicate)
{
    MMI_ID grp_id = mmi_frm_group_get_active_id();   
     
    //mmi_bt_dialer_conn_profile_end(SRV_BT_CM_MAPC_CONNECTION);// this is reset callback
    srv_bt_mapc_register_cm_callback(mmi_bt_dialor_callback);
    cui_bt_dialer_connecting_close(g_sms_cui_id);
    if (!result)
    {
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_FAILURE,
        (WCHAR*)GetString(STR_BT_CONN_FAILED));
    }
}

void mmi_sms_um_bt_connect_lsk_hdlr()
{
    MMI_ID cui_id;
    srv_bt_cm_bt_addr addr;
    S32 ret = SRV_BT_MAPC_SUCCESS;
    MMI_ID grp_id = mmi_frm_group_get_active_id();
    ret = srv_bt_mapc_get_bt_addr_by_idx(&addr, g_sms_active_dev_index);
    if (!ret && srv_bt_cm_get_existed_conn_num_by_addr(&addr))
    {
        cui_id = cui_bt_dialer_connecting_create(grp_id);
        if (cui_id != GRP_ID_INVALID)
        {
            g_sms_cui_id = cui_id;
            cui_bt_dialer_connecting_run(cui_id);
            srv_bt_mapc_connect_req_from_cm(addr, mmi_sms_um_bt_connect_profile_cb, MMI_TRUE); 
        }
    }
    else
    {
	srv_bt_mapc_set_cur_order_index(g_sms_active_dev_index);
	mmi_bt_dialer_show_popup(grp_id);
    }
}

static mmi_ret mmi_sms_um_bt_key_hdlr(mmi_frm_key_evt_struct *evt)
{
    mmi_scrn_essential_struct *et_data = (mmi_scrn_essential_struct *)evt->user_data; 
    if (evt->key_code == KEY_END)
    {                
        //memset(g_sms_um_ui_p, 0, sizeof(mmi_sms_um_bt_ui_cntx_struct));
        StopTimer(MESSAGES_INPROGRESS_TIMER_ID);
        g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered = SRV_SMS_BTMAPC_BOX_NONE;
        g_sms_um_ui_main_menu_scrn_id = 0;
        if ((g_sms_bt_ui_p[g_sms_active_dev_index].sms_handle != 0) && (g_sms_bt_ui_p[g_sms_active_dev_index].is_on_request == MMI_TRUE))
        {
            //srv_sms_btmapc_abort(g_sms_bt_ui_p->sms_handle,NULL,NULL);
        }
    }
#ifdef __MMI_TELEPHONY_SUPPORT__
    else if (evt->key_code == KEY_LEFT_ARROW || evt->key_code == KEY_RIGHT_ARROW)
    {
        if (evt->key_type == KEY_EVENT_DOWN)
        {
            mmi_sms_bt_um_ui_aprc_263_tab_local(et_data);
        }
        return MMI_RET_STOP_KEY_HANDLE;
    }
#endif
    return MMI_RET_OK;
}


U16 mmi_sms_um_bt_ui_ut_get_msg_num_by_msg_box(srv_um_msg_btmapc_box_enum msg_box, sms_um_bt_get_msg_num_result *msg_num_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_num = 0;
    
    switch (msg_box)
    {
        case SRV_UM_MSG_BTMAPC_BOX_INBOX:
        {
            msg_num = msg_num_info->inbox_msg_number;
            break;
        }
        case SRV_UM_MSG_BTMAPC_BOX_DRAFTS:
        {
            msg_num = msg_num_info->draft_msg_number;
            break;
        }
        case SRV_UM_MSG_BTMAPC_BOX_UNSENT:
        {
            msg_num = msg_num_info->unsent_msg_number;
            break;
        }
        case SRV_UM_MSG_BTMAPC_BOX_OUTBOX:
        {
            msg_num = msg_num_info->sent_msg_number;
            break;
        }
        case SRV_UM_MSG_BTMAPC_BOX_ALL:
        {
            msg_num = msg_num_info->inbox_msg_number
                      + msg_num_info->draft_msg_number
                      + msg_num_info->unsent_msg_number
                      + msg_num_info->sent_msg_number;
            break;
        }
        default:
        {
            msg_num = 0;
            break;
        }        
    }

    return msg_num;
}
MMI_BOOL mmi_sms_um_bt_ui_aprc_general_fw_function(mmi_sms_um_bt_ui_aprc_general_cntx_struct *general_cntx)
{
    if (MMI_FALSE == mmi_frm_scrn_enter(         
                                general_cntx->grp_id, 
                                general_cntx->scrn_id, 
                                (FuncPtr) general_cntx->exit_func, 
                                (FuncPtr) general_cntx->entry_func, 
                                MMI_FRM_SCRN_GROUP))
    {
        /* Could not display, insert to history */
        mmi_sms_um_bt_ui_aprc_reg_leave_proc(general_cntx);
        return MMI_FALSE;
    }

    mmi_sms_um_bt_ui_aprc_reg_leave_proc(general_cntx);

    RegisterHighlightHandler(general_cntx->hilite_hdlr);
    mmi_sms_um_bt_ui_aprc_enable_softkey(general_cntx);
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_bt_ui_aprc_set_cntx
 * DESCRIPTION
 *  It is used to set the appearnce context from the input.
 *  Because the screen handler does not know the drawing function of each 
 *  appearance, this function just sets the draw and re-draw in the aprc_cntx.
 *  Hence, screen handler does not need to know the detail of appearance. It
 *  just calls the draw/redraw function to display/update the screen.
 *
 * PARAMETERS
 *  aprc_node           [OUT]: the appearance context
 *  aprc_type           [IN]: the appearance type
 *
 * RETURNS
 *  MMI_TRUE: create successfully
 *  MMI_FALSE: create fail
 *****************************************************************************/
MMI_BOOL mmi_sms_um_bt_ui_aprc_set_cntx(mmi_sms_um_bt_ui_aprc_node_struct    *aprc_node, 
                                 mmi_sms_um_bt_ui_aprc_st_enum         aprc_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aprc_node->st_type = aprc_type;
    switch (aprc_type)
    {
        case MMI_SMS_UM_BT_UI_SCRN_TYPE_MAIN_MENU:
        {
            aprc_node->type = MMI_SMS_UM_BT_UI_APRC_53;
            aprc_node->draw_func = mmi_sms_um_bt_ui_aprc_53_draw;
            aprc_node->redraw_func = mmi_sms_um_bt_ui_aprc_53_redraw;
            break;
        }
        case MMI_SMS_UM_BT_UI_SCRN_TYPE_FOLDER:
        case MMI_SMS_UM_BT_UI_SCRN_TYPE_BT_FOLDER:
        {
            aprc_node->type = MMI_SMS_UM_BT_UI_APRC_263;
            aprc_node->draw_func = mmi_sms_um_bt_ui_aprc_263_draw;
            aprc_node->redraw_func = mmi_sms_um_bt_ui_aprc_263_redraw;
            break;
        }
        case MMI_SMS_UM_BT_UI_SCRN_TYPE_LOADING:
        {
            aprc_node->st_type = aprc_type;
            aprc_node->type = MMI_SMS_UM_BT_UI_APRC_165;
            aprc_node->draw_func = mmi_sms_um_bt_ui_aprc_165_draw;
            aprc_node->redraw_func = mmi_sms_um_bt_ui_aprc_165_redraw;
            break;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return MMI_TRUE;
}
mmi_sms_bt_box_enum mmi_sms_bt_get_mmi_box_type(srv_um_msg_btmapc_box_enum btmapc_box_type)
{
    mmi_sms_bt_box_enum mmi_box_type;
    switch (btmapc_box_type)
    {
        case SRV_UM_MSG_BTMAPC_BOX_INBOX:
        {
            mmi_box_type = MMI_SMS_BT_BOX_INBOX;
            break;
        }
        case SRV_UM_MSG_BTMAPC_BOX_OUTBOX:
        {
            mmi_box_type = MMI_SMS_BT_BOX_OUTBOX;
            break;
        }
        case SRV_UM_MSG_BTMAPC_BOX_DRAFTS:
        {
            mmi_box_type = MMI_SMS_BT_BOX_DRAFTS;
            break;
        }
        case SRV_UM_MSG_BTMAPC_BOX_UNSENT:
        {
            mmi_box_type = MMI_SMS_BT_BOX_UNSENT;
            break;
        }
        default:
        {
            mmi_box_type = MMI_SMS_BT_BOX_NONE;
            break;
        }
    }
    return mmi_box_type;
}

extern U8 g_sms_bt_opt_cancel_flag;
void mmi_sms_bt_processing_generic_time_out()
{
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx = mmi_sms_um_bt_ui_sh_get_active_user_data();
    mmi_sms_bt_box_enum box_type;
    box_type = mmi_sms_bt_get_mmi_box_type(scrn_cntx->screen_hdlr.folder_type.msg_box_type);
    
    g_sms_bt_ui_p[g_sms_active_dev_index].need_refresh[box_type] = MMI_FALSE;
    g_sms_bt_ui_p[g_sms_active_dev_index].is_on_request = MMI_FALSE;
    srv_sms_btmapc_cancel_op(g_sms_bt_ui_p[g_sms_active_dev_index].sms_handle);
	g_sms_bt_opt_cancel_flag = 1;
    StopTimer(MESSAGES_INPROGRESS_TIMER_ID);
    mmi_frm_scrn_close(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id);
    mmi_popup_display_ext(
            STR_GLOBAL_UNFINISHED,
            MMI_EVENT_FAILURE,
            NULL);    
}

MMI_BOOL mmi_sms_um_bt_ui_int_is_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_available;
    mmi_sms_um_bt_ui_cc_scrn_cntx_setting_struct setting;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_available = MMI_TRUE;
    memset(&setting, 0, sizeof(mmi_sms_um_bt_ui_cc_scrn_cntx_setting_struct));
    
    setting.folder.msg_type = g_sms_um_ui_p->setting.support_msg_type;
    setting.folder.sim_id = SRV_UM_SIM_ALL;
    is_available = (MMI_BOOL)(setting.folder.msg_type);

    return is_available;
}

MMI_BOOL mmi_sms_um_bt_ui_aprc_53_draw(mmi_sms_um_bt_ui_aprc_st_union *aprc_cntx, 
                                mmi_sms_um_bt_ui_aprc_st_enum aprc_st_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    mmi_sms_um_bt_ui_aprc_struct_union *aprc_int_cntx;
    mmi_sms_um_bt_ui_aprc_53_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aprc_int_cntx= OslMalloc(sizeof(mmi_sms_um_bt_ui_aprc_struct_union));
    memset(aprc_int_cntx,0, sizeof(mmi_sms_um_bt_ui_aprc_struct_union));
    aprc = &(aprc_int_cntx->aprc_53);
    mmi_sms_um_bt_ui_aprc_set_int_cntx(aprc_int_cntx, MMI_UM_UI_APRC_53, aprc_cntx, aprc_st_type);

    if (MMI_FALSE == mmi_sms_um_bt_ui_aprc_general_fw_function(&(aprc->general_aprc_cntx)))
    {
        OslMfree(aprc_int_cntx);
        return MMI_TRUE;
    }
    
    if (aprc->general_aprc_cntx.gui_buffer == NULL)
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    }
    else
    {
        gui_buffer = aprc->general_aprc_cntx.gui_buffer;
    }

    SetParentHandler(aprc->general_aprc_cntx.menu_item_id);

#ifdef __MMI_WGUI_MINI_TAB_BAR__
    wgui_enable_mini_tab_bar(aprc->general_aprc_cntx.menu_item_id);
#endif /* __MMI_WGUI_MINI_TAB_BAR__ */


    wgui_list_menu_enable_access_by_shortcut();
    ShowCategory53Screen(
        aprc->general_aprc_cntx.title_str_id,
        aprc->general_aprc_cntx.title_icon_id,
        aprc->general_aprc_cntx.lsk_str_id,
        aprc->general_aprc_cntx.lsk_icon_id,
        aprc->general_aprc_cntx.rsk_str_id,
        aprc->general_aprc_cntx.rsk_icon_id,
        aprc->general_aprc_cntx.num_of_item,
        aprc->list_of_items,
        aprc->list_of_item_icons,
        aprc->list_of_item_hints,
        0,
        aprc->general_aprc_cntx.hilite_idx,
        gui_buffer);
	//ShowCategory15Screen(
	//	aprc->general_aprc_cntx.title_str_id,
 //       aprc->general_aprc_cntx.title_icon_id,
 //       aprc->general_aprc_cntx.lsk_str_id,
 //       aprc->general_aprc_cntx.lsk_icon_id,
 //       aprc->general_aprc_cntx.rsk_str_id,
 //       aprc->general_aprc_cntx.rsk_icon_id,
 //       aprc->general_aprc_cntx.num_of_item,
 //       aprc->list_of_items,
 //       aprc->list_of_item_icons,
 //       LIST_MENU,
 //       aprc->general_aprc_cntx.hilite_idx,
 //       gui_buffer);
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    //mmi_sms_um_bt_ui_aprc_reg_intuitive_cmd_cb_hdlr(aprc->general_aprc_cntx.intuitive_cmd_cb_func);
#endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */

    mmi_sms_um_bt_ui_aprc_set_key_hdlr(&(aprc->general_aprc_cntx.key_hdlr));

    OslMfree(aprc_int_cntx);
    return MMI_TRUE;
}
MMI_BOOL mmi_sms_um_bt_ui_aprc_53_redraw(mmi_sms_um_bt_ui_aprc_st_union *aprc_cntx, 
                                  mmi_sms_um_bt_ui_aprc_st_enum aprc_st_type, 
                                  mmi_sms_um_bt_ui_aprc_redraw_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    mmi_sms_um_bt_ui_aprc_struct_union *aprc_int_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aprc_int_cntx= OslMalloc(sizeof(mmi_sms_um_bt_ui_aprc_struct_union));
    memset(aprc_int_cntx,0, sizeof(mmi_sms_um_bt_ui_aprc_struct_union));
    mmi_sms_um_bt_ui_aprc_set_int_cntx(aprc_int_cntx, MMI_SMS_UM_BT_UI_APRC_53, aprc_cntx, aprc_st_type);
    result = MMI_TRUE;

    if ((type & MMI_SMS_UM_BT_UI_APRC_REDRAW_BODY) == MMI_SMS_UM_BT_UI_APRC_REDRAW_BODY)
    {
        result = mmi_sms_um_bt_ui_aprc_53_redraw_body(aprc_int_cntx);
    }

    RedrawCategoryFunction();

    OslMfree(aprc_int_cntx);
    return result;
}

MMI_BOOL mmi_sms_um_bt_ui_aprc_53_redraw_body(mmi_sms_um_bt_ui_aprc_struct_union *aprc_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   mmi_sms_um_bt_ui_aprc_53_struct *aprc = &(aprc_cntx->aprc_53);
   U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Update each body */
    for (i = 0; i < aprc->general_aprc_cntx.num_of_item; i++)
    {
        /* Update menu item string */
        if (aprc->list_of_items[i] != NULL)
        {
            Category53ChangeItemText(i, aprc->list_of_items[i]);
        }

        /* Update menu item hint string */
        if (aprc->list_of_item_hints != NULL)
        {
            Category53ChangeItemDescription(i, aprc->list_of_item_hints[i]);
        }
        else
        {
            Category53ChangeItemDescription(i, NULL);
        }
    }

    return MMI_TRUE;
}


MMI_BOOL mmi_sms_um_bt_ui_aprc_165_draw(mmi_sms_um_bt_ui_aprc_st_union *aprc_cntx, 
                                 mmi_sms_um_bt_ui_aprc_st_enum aprc_st_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    mmi_sms_um_bt_ui_aprc_struct_union *aprc_int_cntx;
    mmi_sms_um_bt_ui_aprc_165_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aprc_int_cntx= OslMalloc(sizeof(mmi_sms_um_bt_ui_aprc_struct_union));
    memset(aprc_int_cntx,0, sizeof(mmi_sms_um_bt_ui_aprc_struct_union));
    aprc = &(aprc_int_cntx->aprc_165);
    mmi_sms_um_bt_ui_aprc_set_int_cntx(aprc_int_cntx, MMI_SMS_UM_BT_UI_APRC_165, aprc_cntx, aprc_st_type);


    if (MMI_FALSE == mmi_sms_um_bt_ui_aprc_general_fw_function(&(aprc->general_aprc_cntx)))
    {
        OslMfree(aprc_int_cntx);
        return MMI_TRUE;
    }
    
    if (aprc->general_aprc_cntx.gui_buffer == NULL)
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    }
    else
    {
        gui_buffer = aprc->general_aprc_cntx.gui_buffer;
    }

    /* It should block sliding show */
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
    if (aprc->scrn_effect == MMI_UM_UI_BLOCK_SLIDE_SHOW)
    {
        gui_screen_switch_effect_block(MMI_TRUE);
    }
#endif /* __MMI_SCREEN_SWITCH_EFFECT__ */

    ShowCategory165Screen(
        aprc->general_aprc_cntx.lsk_str_id,
        aprc->general_aprc_cntx.lsk_icon_id,
        aprc->general_aprc_cntx.rsk_str_id,
        aprc->general_aprc_cntx.rsk_icon_id,
        get_string(aprc->msg_str_id),
        aprc->msg_icon_id,
        gui_buffer);

    mmi_sms_um_bt_ui_aprc_set_key_hdlr(&(aprc->general_aprc_cntx.key_hdlr));
    MMI_SCR_SET_KEY_PROC(mmi_sms_um_bt_key_hdlr, (void *)NULL);
    /*ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);*/
    StartTimer(MESSAGES_INPROGRESS_TIMER_ID, MMI_SMS_UM_BT_PROGRESS_TIME_OUT, mmi_sms_bt_processing_generic_time_out);
    
    OslMfree(aprc_int_cntx);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_bt_ui_aprc_165_redraw
 * DESCRIPTION
 *  It is used to redraw the category 165 screen. It needs to call several
 *  framework APIs to accomplish displaying a screen. Sometiems it needs to
 *  update the screen. Screen handler should call this API to update the
 *  current screen.
 *
 * PARAMETERS
 *  aprc_cntx           [IN]: the necessary appearance context
 *  aprc_st_type        [IN]: The screen type of this appearance
 *  type                [IN]: Redrawing region
 *
 * RETURNS
 *  MMI_TRUE: the screen updates finished
 *  MMI_FALSE: the screen updates fail
 *****************************************************************************/
MMI_BOOL mmi_sms_um_bt_ui_aprc_165_redraw(mmi_sms_um_bt_ui_aprc_st_union *aprc_cntx, 
                                   mmi_sms_um_bt_ui_aprc_st_enum aprc_st_type, 
                                   mmi_sms_um_bt_ui_aprc_redraw_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_aprc_struct_union *aprc_int_cntx;
    mmi_sms_um_bt_ui_aprc_165_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aprc_int_cntx= OslMalloc(sizeof(mmi_sms_um_bt_ui_aprc_struct_union));
    memset(aprc_int_cntx,0, sizeof(mmi_sms_um_bt_ui_aprc_struct_union));
    aprc = &(aprc_int_cntx->aprc_165);
    mmi_sms_um_bt_ui_aprc_set_int_cntx(aprc_int_cntx, MMI_SMS_UM_BT_UI_APRC_165, aprc_cntx, aprc_st_type);

    /* redraw body */
    if ((type & MMI_SMS_UM_BT_UI_APRC_REDRAW_BODY) == MMI_SMS_UM_BT_UI_APRC_REDRAW_BODY)
    {
        wgui_cat_popup_update_string(get_string(aprc->msg_str_id));
    }

    OslMfree(aprc_int_cntx);
    return MMI_TRUE;
}
MMI_BOOL mmi_sms_um_bt_ui_aprc_263_draw(mmi_sms_um_bt_ui_aprc_st_union *aprc_cntx, 
                                 mmi_sms_um_bt_ui_aprc_st_enum aprc_st_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *title_str;
    U8 *gui_buffer;
    S32 list_not_ready;
    list_menu_category_history *list_gui_buffer;
    mmi_sms_um_bt_ui_aprc_struct_union *aprc_int_cntx;
    mmi_sms_um_bt_ui_aprc_263_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aprc_int_cntx= OslMalloc(sizeof(mmi_sms_um_bt_ui_aprc_struct_union));
    memset(aprc_int_cntx,0, sizeof(mmi_sms_um_bt_ui_aprc_struct_union));    
    aprc = &(aprc_int_cntx->aprc_263);
    mmi_sms_um_bt_ui_aprc_set_int_cntx(aprc_int_cntx, MMI_UM_UI_APRC_263, aprc_cntx, aprc_st_type);

    if (MMI_FALSE == mmi_sms_um_bt_ui_aprc_general_fw_function(&(aprc->general_aprc_cntx)))
    {
        OslMfree(aprc_int_cntx);
        return MMI_TRUE;
    }

    if (aprc->general_aprc_cntx.gui_buffer == NULL)
    {
        /* use the history gui buffer */
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
        /* arrange the highlight */
        if (gui_buffer != NULL)
        {
            list_gui_buffer = (list_menu_category_history *)gui_buffer;
            list_gui_buffer->highlighted_item = aprc->general_aprc_cntx.hilite_idx;
        }
    }
    else
    {
        gui_buffer = aprc->general_aprc_cntx.gui_buffer;
    }
    wgui_cat_set_list_menu_empty_lable((UI_string_type)get_string(STR_UM_EMPTY_MSG_ID));

    /* If it has the special title, it needs to display a specified string in title */
    if (NULL == aprc->special_title)
    {
        title_str = (U8 *) get_string(aprc->general_aprc_cntx.title_str_id);
    }
    else
    {
        title_str = aprc->special_title;
    }

    ShowCategory263Screen(
        title_str,
        aprc->general_aprc_cntx.title_icon_id,
        aprc->general_aprc_cntx.lsk_str_id,
        aprc->general_aprc_cntx.lsk_icon_id,
        aprc->general_aprc_cntx.rsk_str_id,
        aprc->general_aprc_cntx.rsk_icon_id,
        aprc->general_aprc_cntx.num_of_item,
        aprc->get_item_cb,
        aprc->get_item_hint_cb,
        aprc->general_aprc_cntx.hilite_idx,
        0,   /* for icon position used */
        gui_buffer,
        &list_not_ready);

    if (aprc->hilite_notify_cb != NULL)
    {
        wgui_async_list_register_update_callback(aprc->hilite_notify_cb);
    }

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    //mmi_sms_um_bt_ui_aprc_reg_intuitive_cmd_cb_hdlr(aprc->general_aprc_cntx.intuitive_cmd_cb_func);
#endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */

    /* the screen does not display */
    if (list_not_ready)
    {
        OslMfree(aprc_int_cntx);
        return MMI_FALSE;
    }

    mmi_sms_um_bt_ui_aprc_set_key_hdlr(&(aprc->general_aprc_cntx.key_hdlr));

    OslMfree(aprc_int_cntx);
    return MMI_TRUE;
}

void mmi_sms_bt_um_ui_aprc_263_tab_local(mmi_scrn_essential_struct* et_data)
{
    /*if (g_tab_curr_first_enter == MMI_UM_TAB_PAGE_BT)
    {
        if (!mmi_frm_scrn_tab_page_enter(
           et_data->group_id, 
           et_data->tab_id,
           et_data->scrn_id,
           NULL,
           (FuncPtr)mmi_sms_bt_um_ui_aprc_263_tab_local,
           MMI_FRM_TAB_PAGE))
        {
            return;
        }   
        
        switch (g_sms_bt_mmi_box_type)
        {
            case SRV_UM_MSG_BTMAPC_BOX_INBOX:
                mmi_um_ui_sh_main_msg_entry_inbox();
                break;
            case SRV_UM_MSG_BTMAPC_BOX_UNSENT:
                mmi_um_ui_sh_main_msg_entry_outbox();
                break;
            case SRV_UM_MSG_BTMAPC_BOX_OUTBOX:
                mmi_um_ui_sh_main_msg_entry_sent();
                break;
            case SRV_UM_MSG_BTMAPC_BOX_DRAFTS:
                mmi_um_ui_sh_main_msg_entry_draft();
                break;
            default:
                mmi_um_ui_sh_main_msg_entry_inbox();
                break;            
        }
    }
    else
    {*/
        g_enter_from_bt = MMI_TRUE;
        mmi_sms_um_bt_ui_sh_rsk_hdlr();
    //}
}
extern MMI_BOOL g_sms_bt_disable_del_event;
void mmi_sms_bt_um_ui_aprc_263_tab_BT(mmi_scrn_essential_struct* et_data)
{
    U8 *title_str;
    U8 *gui_buffer;
    S32 list_not_ready;
    list_menu_category_history *list_gui_buffer;
    mmi_sms_um_bt_ui_aprc_263_struct *aprc; 
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx = et_data->user_data;
	

    U16 i;
    U16 num_item;
    srv_um_list_cntx_struct *data_list;
    mmi_sms_um_bt_ui_aprc_st_union aprc_union;
    
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

        
    aprc = &(g_sms_bt_aprc_int_cntx);
    kal_prompt_trace(MOD_MMI, "[SMS], mmi_sms_bt_um_ui_aprc_263_tab_BT");

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
    kal_prompt_trace(MOD_MMI, "[SMS], Entry mmi_sms_bt_um_ui_aprc_263_tab_BT g_sms_bt_mmi_box_type = %d", g_sms_bt_mmi_box_type);
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
        kal_prompt_trace(MOD_MMI, "[SMS], Entry mmi_sms_bt_um_ui_aprc_263_tab_BT fsm->folder_info.data_list->msg_number = %d", fsm->folder_info.data_list->msg_number);
    }

    /* set the number of items */
    num_item = mmi_sms_um_bt_ui_sh_general_folder_get_msg_num(scrn_cntx);
    data_list = mmi_sms_um_bt_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    /* if data list is NULL, it means FSM does not have the correct message number info. */
    kal_prompt_trace(MOD_MMI, "[SMS], Entry mmi_sms_bt_um_ui_aprc_263_tab_BT num_item = %d", num_item);
    if (NULL != data_list)
    {
        scrn_cntx->screen_hdlr.num_of_item = num_item;
        aprc->general_aprc_cntx.num_of_item = num_item;
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
    kal_prompt_trace(MOD_MMI, "[SMS], 0 != scrn_cntx->screen_hdlr.num_of_item = %d", scrn_cntx->screen_hdlr.num_of_item);
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
    #ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    if (!cui_tab_enter(
            et_data->group_id, 
            et_data->scrn_id,
            NULL,
            (FuncPtr)mmi_sms_bt_um_ui_aprc_263_tab_BT,
            MMI_FRM_FULL_SCRN))
    {
        g_bt_category_error_flag = MMI_FALSE;
        return;
    }  
    #else
    if (!mmi_frm_scrn_tab_page_enter(
       et_data->group_id, 
       et_data->tab_id,
       et_data->scrn_id,
       NULL,
       (FuncPtr)mmi_sms_bt_um_ui_aprc_263_tab_BT,
       MMI_FRM_TAB_PAGE))
    {
        MMI_BOOL g_bt_category_error_flag = MMI_FALSE;
        return;
    }   
    #endif/*__MMI_TAB_BAR_SUPPORT_TAB_PAGE__*/
#else

	mmi_frm_send_incomplete_key_event_to_new_screen(MMI_TRUE);

    if (MMI_FALSE == mmi_frm_scrn_enter(         
            et_data->group_id, 
            et_data->scrn_id,
            NULL, 
            (FuncPtr)mmi_sms_bt_um_ui_aprc_263_tab_BT, 
            MMI_FRM_SCRN_GROUP))
    {
        kal_prompt_trace(MOD_MMI, "[SMS], mmi_frm_scrn_enter_mmi_sms_bt_um_ui_aprc_263_tab_BT_return");
        g_bt_category_error_flag = MMI_TRUE;
        return;
    }
        mmi_frm_scrn_set_user_data(et_data->group_id, et_data->scrn_id, scrn_cntx);
#endif

    if (g_bt_category_error_flag)
        scrn_cntx->screen_hdlr.is_scrn_displayed = g_bt_category_error_flag;

	g_sms_bt_disable_del_event = MMI_FALSE;

    mmi_sms_um_bt_ui_aprc_reg_leave_proc(&(aprc->general_aprc_cntx));

    RegisterHighlightHandler((aprc->general_aprc_cntx).hilite_hdlr);
    mmi_sms_um_bt_ui_aprc_enable_softkey(&(aprc->general_aprc_cntx));
    
    if (aprc->general_aprc_cntx.gui_buffer == NULL)
    {
        /* use the history gui buffer */
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
        /* arrange the highlight */
        if (gui_buffer != NULL)
        {
            list_gui_buffer = (list_menu_category_history *)gui_buffer;
            list_gui_buffer->highlighted_item = aprc->general_aprc_cntx.hilite_idx;
        }
    }
    else
    {
        gui_buffer = aprc->general_aprc_cntx.gui_buffer;
    }    
    
    if (NULL == aprc->special_title)
    {
        title_str = (U8 *) get_string(aprc->general_aprc_cntx.title_str_id);
    }
    else
    {
        title_str = aprc->special_title;
    }
        
    wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON);
    
    kal_prompt_trace(MOD_MMI, "[SMS], mmi_sms_bt_um_ui_aprc_263_tab_BT is_bt_connected = %d", g_sms_bt_ui_p[g_sms_active_dev_index].is_bt_connected);
    kal_prompt_trace(MOD_MMI, "[SMS], mmi_sms_bt_um_ui_aprc_263_tab_BT g_sms_bt_ui_p[g_sms_active_dev_index].is_bt_connected = %d", g_sms_bt_ui_p[g_sms_active_dev_index].is_bt_connected);
    kal_prompt_trace(MOD_MMI, "[SMS], mmi_sms_bt_um_ui_aprc_263_tab_BT g_sms_bt_ui_p[g_sms_active_dev_index].remote_not_support = %d", g_sms_bt_ui_p[g_sms_active_dev_index].remote_not_support);
    kal_prompt_trace(MOD_MMI, "[SMS], mmi_sms_bt_um_ui_aprc_263_tab_BT g_sms_bt_mmi_box_type = %d", g_sms_bt_mmi_box_type);
    kal_prompt_trace(MOD_MMI, "[SMS], mmi_sms_bt_um_ui_aprc_263_tab_BT srv_sms_btmapc_inbox_size = %d", srv_sms_btmapc_get_list_size(SRV_UM_MSG_BTMAPC_BOX_INBOX));
    kal_prompt_trace(MOD_MMI, "[SMS], mmi_sms_bt_um_ui_aprc_263_tab_BT srv_sms_btmapc_inbox_size = %d", srv_sms_btmapc_get_list_size(SRV_UM_MSG_BTMAPC_BOX_DRAFTS));

	
    
    if ((!g_sms_bt_ui_p[g_sms_active_dev_index].is_bt_connected) && 
        //#ifndef __MMI_BT_MAPC_BY_SPP__
        (g_sms_bt_ui_p[g_sms_active_dev_index].remote_not_support) &&
        //#endif
        (srv_bt_mapc_adp_is_connected(g_sms_active_dev_index))
         #ifndef __MMI_TELEPHONY_SUPPORT__
         && (g_sms_bt_mmi_box_type != SRV_UM_MSG_BTMAPC_BOX_DRAFTS ||
         srv_sms_btmapc_get_list_size(SRV_UM_MSG_BTMAPC_BOX_DRAFTS) == 0)
         #endif/*__MMI_TELEPHONY_SUPPORT__*/
         )
    {
        kal_prompt_trace(MOD_MMI, "[SMS], mmi_sms_bt_um_ui_aprc_263_tab_BT g_sms_bt_ui_p[g_sms_active_dev_index].remote_not_support = %d", g_sms_bt_ui_p[g_sms_active_dev_index].remote_not_support);
        g_sms_bt_ui_p[g_sms_active_dev_index].need_show_connect = MMI_FALSE;
        aprc->general_aprc_cntx.lsk_str_id = 0;
        aprc->general_aprc_cntx.lsk_icon_id = 0;
        aprc->general_aprc_cntx.key_hdlr.lsk_hdlr = NULL;
        //#ifdef __MMI_BT_MAPC_BY_SPP__
        if(g_sms_bt_ui_p[g_sms_active_dev_index].remote_not_support)
        {
            wgui_set_menu_empty_string_by_id(STR_ID_SMS_BT_RMOT_NOT_SUPPORT);
        }
        //#else
        #if (defined(__MMI_BT_NOTIFICATION__) || defined (__MMI_BT_NOTI_SRV__))
        else
        {
        wgui_set_menu_empty_string_by_id(STR_ID_BTNOTIFICATION_APPLICATION_NEED_USER_CONNECT);
        }
        #endif
        //#endif
    }
    else if (!g_sms_bt_ui_p[g_sms_active_dev_index].is_bt_connected
             #ifndef __MMI_TELEPHONY_SUPPORT__
             && (g_sms_bt_mmi_box_type != SRV_UM_MSG_BTMAPC_BOX_DRAFTS ||
             srv_sms_btmapc_get_list_size(SRV_UM_MSG_BTMAPC_BOX_DRAFTS) == 0)
            #endif/*__MMI_TELEPHONY_SUPPORT__*/
            )
    {
        kal_prompt_trace(MOD_MMI, "[SMS], mmi_sms_bt_um_ui_aprc_263_tab_BT g_sms_bt_ui_p[g_sms_active_dev_index].need_show_connect");
        g_sms_bt_ui_p[g_sms_active_dev_index].need_show_connect = MMI_TRUE;
        aprc->general_aprc_cntx.lsk_str_id = STR_ID_SMS_BT_CONN;
        aprc->general_aprc_cntx.key_hdlr.lsk_hdlr = mmi_sms_um_bt_connect_lsk_hdlr;
        aprc->general_aprc_cntx.key_hdlr.csk_hdlr = mmi_sms_um_bt_connect_lsk_hdlr;
        g_bt_category_error_flag = MMI_TRUE;
        wgui_set_menu_empty_string_by_id(STR_ID_SMS_BT_NO_CONN);
        kal_prompt_trace(MOD_MMI, "[SMS], mmi_sms_bt_um_ui_aprc_263_tab_BT wgui_set_menu_empty_string_by_id  STR_ID_SMS_BT_NO_CONN");		
    }
    else
    {
        kal_prompt_trace(MOD_MMI, "[SMS], mmi_sms_bt_um_ui_aprc_263_tab_BT wgui_set_menu_empty_string_by_id STR_GLOBAL_EMPTY", g_sms_bt_ui_p[g_sms_active_dev_index].need_show_connect);		
        g_sms_bt_ui_p[g_sms_active_dev_index].need_show_connect = MMI_FALSE;
        wgui_set_menu_empty_string_by_id(STR_GLOBAL_EMPTY);
    }
    
    
	wgui_cat1032_show(
        (WCHAR*)title_str,
        (PU8)GetImage(aprc->general_aprc_cntx.title_icon_id),
        (WCHAR*)GetString(aprc->general_aprc_cntx.lsk_str_id),
        (PU8)aprc->general_aprc_cntx.lsk_icon_id,
        (WCHAR*)GetString(aprc->general_aprc_cntx.rsk_str_id),
        (PU8)aprc->general_aprc_cntx.rsk_icon_id,
        aprc->general_aprc_cntx.num_of_item,
        aprc->get_item_cb,
        aprc->get_item_hint_cb,
        aprc->general_aprc_cntx.hilite_idx,
        1,
        IMG_MESSAGE_READ,   
        0,
        gui_buffer,
        &list_not_ready);

#ifdef __MMI_TOUCH_SCREEN__
#ifndef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    wgui_set_horizontal_tab_bar_select_callback(mmi_um_bt_tab_pen_handle);
#else
    wgui_set_horizontal_tab_bar_select_callback_ex(mmi_um_bt_tab_pen_handle);
#endif/*__MMI_TAB_BAR_SUPPORT_TAB_PAGE__*/
#endif/*__MMI_TOUCH_SCREEN__*/
    
    wgui_restore_list_menu_slim_style(); 
    
    if (aprc->hilite_notify_cb != NULL)
    {
        wgui_async_list_register_update_callback(aprc->hilite_notify_cb);
    }
    mmi_um_ui_aprc_set_key_hdlr(&(aprc->general_aprc_cntx.key_hdlr));
    g_tab_last_enter = MMI_UM_TAB_PAGE_BT;
    MMI_SCR_SET_KEY_PROC(mmi_sms_um_bt_key_hdlr, (void *)NULL);


//#ifndef __MMI_TELEPHONY_SUPPORT__
    //mmi_sms_um_bt_ui_ut_del_relative_scrn(&(scrn_cntx->child_scrn_id));
       if (g_bt_category_error_flag)
           scrn_cntx->screen_hdlr.is_scrn_displayed = g_bt_category_error_flag;
       /* Due to the category usage, it should check the screen is displayed or not */
        kal_prompt_trace(MOD_MMI, "[SMS], mmi_sms_bt_um_ui_aprc_263_tab_BT scrn_cntx->screen_hdlr.is_scrn_displayed = %d g_sms_bt_ui_p[g_sms_active_dev_index].mmi_need_update_list = %d", scrn_cntx->screen_hdlr.is_scrn_displayed, g_sms_bt_ui_p[g_sms_active_dev_index].mmi_need_update_list); 	   
       if (scrn_cntx->screen_hdlr.is_scrn_displayed == MMI_FALSE || g_sms_bt_ui_p[g_sms_active_dev_index].mmi_need_update_list)
       {
       #if defined(__MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__)
           MMI_fixed_list_menu.n_items = num_item;
           MMI_fixed_list_menu.highlighted_item = scrn_cntx->screen_hdlr.hilite_info.index;
       #endif
           g_sms_bt_ui_p[g_sms_active_dev_index].mmi_need_update_list = MMI_FALSE;
           mmi_sms_um_bt_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_INIT, NULL);
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
               (!g_sms_bt_ui_p[g_sms_active_dev_index].is_on_request))
           {   
               mmi_sms_bt_entry_folder_userdata *userdata;
               g_sms_bt_ui_p[g_sms_active_dev_index].need_refresh[mmi_box_type] = MMI_FALSE;
               scrn_cntx->screen_hdlr.is_scrn_displayed == MMI_TRUE;
               g_bt_category_error_flag = MMI_TRUE;
               userdata = &g_ef_usdata;
               userdata->is_back_folder = MMI_TRUE;
               userdata->scrn_id = scrn_cntx->scrn_id;
    
               userdata->bt_index = g_sms_active_dev_index;
               kal_prompt_trace(MOD_MMI, "[SMS], mmi_sms_bt_um_ui_aprc_263_tab_BT mmi_sms_um_bt_ui_if_entry_processing1377");	       
               scrn_cntx->child_scrn_id = mmi_sms_um_bt_ui_if_entry_processing(scrn_cntx->scrn_id, scrn_cntx->group_id, MMI_FALSE);
               g_sms_bt_ui_p[g_sms_active_dev_index].is_on_request = MMI_TRUE;
               if (scrn_cntx->fsm.cntx.fsm_entry_folder.folder_type.msg_box_type == SRV_UM_MSG_BTMAPC_BOX_UNSENT)
               {
                   if (srv_sms_btmapc_get_list_size(SRV_UM_MSG_BTMAPC_BOX_UNSENT) != 0)
                   {
                    #ifndef __MMI_TELEPHONY_SUPPORT__
                        srv_sms_btmapc_delete_all();
                    #else
                        srv_sms_btmapc_storage_reset_data(MMI_TRUE);
                    #endif
                   }
               } 

               kal_prompt_trace(MOD_MMI, "[SMS], mmi_sms_bt_um_ui_aprc_263_tab_BT srv_sms_btmapc_get_msg_list_by_tab");	       			   
               srv_sms_btmapc_get_msg_list_by_tab(g_sms_active_dev_index,MMI_TRUE,
                   scrn_cntx->fsm.cntx.fsm_entry_folder.folder_type.msg_box_type,
                   func,
                   userdata);                              
               kal_prompt_trace(MOD_MMI, "[SMS], mmi_sms_bt_um_ui_aprc_263_tab_BT scrn_cntx->child_scrn_id = %d", scrn_cntx->child_scrn_id);	           
               mmi_sms_um_bt_ui_ut_send_init_event(scrn_cntx->child_scrn_id);
               return;
           }
           /* Send the event out */
           MMI_FRM_INIT_EVENT(&entry_folder_evt, EVT_ID_MMI_SMS_UM_BT_ENTRY_FOLDER);
           entry_folder_evt.is_entry = MMI_TRUE;
           entry_folder_evt.msg_box = scrn_cntx->screen_hdlr.folder_type.msg_box_type;
           entry_folder_evt.um_user_data = (void *)scrn_cntx;
           kal_prompt_trace(MOD_MMI, "[SMS], mmi_sms_bt_um_ui_aprc_263_tab_BT EVT_ID_MMI_SMS_UM_BT_ENTRY_FOLDER");			   		   
           MMI_FRM_CB_EMIT_POST_EVENT(&entry_folder_evt);
       }

//#endif/*__MMI_TELEPHONY_SUPPORT__*/
}

mmi_ret mmi_um_bt_ui_aprc_key_proc(mmi_event_struct *event)
{
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)event;
    MMI_ID group_id, scrn_id;
    
    mmi_frm_get_active_scrn_id(&group_id, &scrn_id);
    if (scrn_id != SCR_ID_SMS_UM_BT_FOLDER)
        return MMI_RET_OK;
    return mmi_sms_um_bt_key_hdlr(key_evt);
}



MMI_BOOL mmi_sms_um_bt_ui_aprc_263_redraw(mmi_sms_um_bt_ui_aprc_st_union *aprc_cntx, 
                                   mmi_sms_um_bt_ui_aprc_st_enum aprc_st_type, 
                                   mmi_sms_um_bt_ui_aprc_redraw_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    mmi_sms_um_bt_ui_aprc_struct_union *aprc_int_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aprc_int_cntx= OslMalloc(sizeof(mmi_sms_um_bt_ui_aprc_struct_union));
    memset(aprc_int_cntx,0, sizeof(mmi_sms_um_bt_ui_aprc_struct_union));
    mmi_sms_um_bt_ui_aprc_set_int_cntx(aprc_int_cntx, MMI_UM_UI_APRC_263, aprc_cntx, aprc_st_type);
    result = MMI_TRUE;

    OslMfree(aprc_int_cntx);
    return result;
}

void mmi_sms_um_bt_ui_aprc_set_key_hdlr(mmi_sms_um_bt_ui_key_handler_struct *key_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (key_hdlr->lsk_hdlr != NULL)
    {
        SetLeftSoftkeyFunction(key_hdlr->lsk_hdlr, KEY_EVENT_UP);
    }
    if (key_hdlr->rsk_hdlr != NULL)
    {
        SetRightSoftkeyFunction(key_hdlr->rsk_hdlr, KEY_EVENT_UP);
    }
    if (key_hdlr->csk_hdlr != NULL)
    {
        SetCenterSoftkeyFunction(key_hdlr->csk_hdlr, KEY_EVENT_UP);
    }

    /* Send key handler by UCM */
    if (KEY_SEND == key_hdlr->special_key_code)
    {
        mmi_ucm_handle_sendkeys_for_call(key_hdlr->key_hdlr, KEY_EVENT_UP);
    }
    /* Special key for different purpose */
    else if (key_hdlr->special_key_code != 0)
    {
        SetKeyHandler(key_hdlr->key_hdlr, 
                      key_hdlr->special_key_code, 
                      KEY_EVENT_UP);
    }

    /* Clear end key */
    if (key_hdlr->clear_end_key)
    {
        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);
    }
}
void mmi_sms_um_bt_ui_aprc_enable_softkey(mmi_sms_um_bt_ui_aprc_general_cntx_struct *general_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* if csk icon/string is not equal to empty, it should enable csk handler */
    if (0 != general_cntx->csk_str_id ||
        0 != general_cntx->csk_icon_id)
    {
        EnableCenterSoftkey(general_cntx->csk_str_id, general_cntx->csk_icon_id);
    }
}
void mmi_sms_um_bt_ui_aprc_change_key_hdlr(mmi_sms_um_bt_ui_aprc_general_cntx_struct *general_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ChangeLeftSoftkey(general_cntx->lsk_str_id, general_cntx->lsk_icon_id);
    ChangeRightSoftkey(general_cntx->rsk_str_id, general_cntx->rsk_icon_id);
    ChangeCenterSoftkey(general_cntx->csk_str_id, general_cntx->csk_icon_id);
    /* If NULL, clear it. Else set as callback function */
    if (general_cntx->key_hdlr.lsk_hdlr != NULL)
    {
        SetLeftSoftkeyFunction(general_cntx->key_hdlr.lsk_hdlr, KEY_EVENT_UP);
    }
    else
    {
        clear_softkey_handler(MMI_LEFT_SOFTKEY);
    }
    if (general_cntx->key_hdlr.rsk_hdlr != NULL)
    {
        SetRightSoftkeyFunction(general_cntx->key_hdlr.rsk_hdlr, KEY_EVENT_UP);
    }
    else
    {
        clear_softkey_handler(MMI_RIGHT_SOFTKEY);
    }
    if (general_cntx->key_hdlr.csk_hdlr != NULL)
    {
        SetCenterSoftkeyFunction(general_cntx->key_hdlr.csk_hdlr, KEY_EVENT_UP);
    }
    else
    {
        clear_softkey_handler(MMI_CENTER_SOFTKEY);
    }

    if (general_cntx->key_hdlr.clear_end_key)
    {
        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);
    }
}
void mmi_sms_um_bt_ui_aprc_reg_leave_proc(mmi_sms_um_bt_ui_aprc_general_cntx_struct *general_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != general_cntx->leave_proc)
    {
        mmi_frm_scrn_set_leave_proc(general_cntx->grp_id, general_cntx->scrn_id, general_cntx->leave_proc);
    }
}
void mmi_sms_um_bt_ui_aprc_set_int_cntx(mmi_sms_um_bt_ui_aprc_struct_union *aprc_cntx, 
                                mmi_sms_um_bt_ui_aprc_type_enum aprc_type, 
                                mmi_sms_um_bt_ui_aprc_st_union *aprc_st_cntx, 
                                mmi_sms_um_bt_ui_aprc_st_enum aprc_st_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (aprc_st_type)
    {
        case MMI_SMS_UM_BT_UI_SCRN_TYPE_MAIN_MENU:
        case MMI_SMS_UM_BT_UI_SCRN_TYPE_LIST:
        {
           mmi_sms_um_bt_ui_aprc_st_main_menu_struct *aprc_ext = &(aprc_st_cntx->main_menu);
           mmi_sms_um_bt_ui_aprc_53_struct *aprc_int  = &(aprc_cntx->aprc_53);
            memset(aprc_cntx, 0, sizeof(mmi_sms_um_bt_ui_aprc_struct_union));

            memcpy(&(aprc_int->general_aprc_cntx), 
                   &(aprc_ext->general_aprc_cntx), 
                   sizeof(mmi_sms_um_bt_ui_aprc_general_cntx_struct));
            aprc_int->list_of_items = aprc_ext->list_of_items;
            aprc_int->list_of_item_hints = aprc_ext->list_of_item_hints;
            aprc_int->list_of_item_icons = aprc_ext->list_of_item_icons;
            break;
        }
         
        case MMI_SMS_UM_BT_UI_SCRN_TYPE_FOLDER:
        case MMI_SMS_UM_BT_UI_SCRN_TYPE_BT_FOLDER:
        {
           mmi_sms_um_bt_ui_aprc_st_folder_struct *aprc_ext = &(aprc_st_cntx->folder);
           mmi_sms_um_bt_ui_aprc_263_struct *aprc_int = &(aprc_cntx->aprc_263);

            memset(aprc_cntx, 0, sizeof(mmi_sms_um_bt_ui_aprc_struct_union));

            memcpy(&(aprc_int->general_aprc_cntx), 
                   &(aprc_ext->general_aprc_cntx), 
                   sizeof(mmi_sms_um_bt_ui_aprc_general_cntx_struct));
            aprc_int->get_item_cb = aprc_ext->get_item_cb;
            aprc_int->get_item_hint_cb = aprc_ext->get_item_hint_cb;
            aprc_int->hilite_notify_cb = aprc_ext->hilite_notify_cb;
            break;
        }
        case MMI_SMS_UM_BT_UI_SCRN_TYPE_LOADING:
        {
           mmi_sms_um_bt_ui_aprc_st_loading_struct *aprc_ext = &(aprc_st_cntx->loading);
           mmi_sms_um_bt_ui_aprc_165_struct *aprc_int  = &(aprc_cntx->aprc_165);
            memset(aprc_cntx, 0, sizeof(mmi_sms_um_bt_ui_aprc_struct_union));

            memcpy(&(aprc_int->general_aprc_cntx), 
                   &(aprc_ext->general_aprc_cntx), 
                   sizeof(mmi_sms_um_bt_ui_aprc_general_cntx_struct));
            aprc_int->msg_str_id = aprc_ext->msg_str_id;
            aprc_int->msg_icon_id = aprc_ext->msg_icon_id;
            aprc_int->scrn_effect = aprc_ext->scrn_effect;
            break;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_bt_ui_fsm_event_hdlr
 * DESCRIPTION
 *  The event handler of entry list finite state machine.
 *
 * PARAMETERS
 *  scrn_id             [IN]: the screen id
 *  event               [IN]: the event id
 *  arg                 [IN]: the event argument
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_sms_um_bt_ui_fsm_event_hdlr(U16 scrn_id, U16 event, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx;
    MMI_BOOL event_process_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    fsm_cntx = &(scrn_cntx->fsm);

    MMI_TRACE(
        MMI_COMMON_TRC_G6_MSG, 
        TRC_MMI_UM_UI_FSM_EL_EVENT_HANDLER, 
        scrn_id, 
        MMI_UM_UI_FSM_ENTRY_LIST, 
        fsm_cntx->cntx.fsm_entry_list.state, 
        event);
    
    event_process_result = MMI_TRUE;

    switch (fsm_cntx->type)
    {
        case MMI_UM_UI_FSM_ENTRY_FOLDER:
            MMI_TRACE(
                MMI_COMMON_TRC_G6_MSG, 
                TRC_MMI_UM_UI_FSM_EF_EVENT_HANDLER, 
                scrn_id, 
                MMI_UM_UI_FSM_ENTRY_FOLDER, 
                fsm_cntx->cntx.fsm_entry_folder.state, 
                event);
            /* The defined events */
            if (event < MMI_UM_UI_FSM_EVENT_TOTAL)
            {
                event_process_result = 
                    (*sms_um_bt_fsm_ef_tb[g_sms_um_bt_ui_fsm_ef_event_table[event][fsm_cntx->cntx.fsm_entry_folder.state]])(fsm_cntx, arg);
                /* 
                event_process_result = 
                    (*g_um_ui_fsm_ef_event_table[event][fsm_cntx->cntx.fsm_entry_folder.state])(fsm_cntx, arg);
                */
            }
            break;

        default:
            break;
    }

    return event_process_result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_bt_ui_fsm_el_get_msg_num
 * DESCRIPTION
 *  It is used for screen handler to get the message number information
 *
 * PARAMETERS
 *  scrn_id             [IN]: Screen id
 *  msg_num             [OUT]: Message number information
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_um_bt_ui_fsm_el_get_msg_num(U16 scrn_id, sms_um_bt_get_msg_num_result **msg_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    MMI_ASSERT(msg_num != NULL);

    fsm_cntx = &(scrn_cntx->fsm);

    /* during collect data, the number of list should be 0 */
    (*msg_num) = &(fsm_cntx->cntx.fsm_entry_list.req_msg_num_result);   
}

void mmi_sms_um_bt_ui_fsm_ef_init(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, mmi_sms_um_bt_ui_fsm_ef_setting_struct setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_fsm_entry_folder_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);
    memset(fsm, 0, sizeof(mmi_sms_um_bt_ui_fsm_entry_folder_struct));
    fsm->state = MMI_UM_UI_FSM_EF_INIT;

    /* External setting */
    fsm->scrn_id = setting.scrn_id;
    fsm->folder_mode = setting.folder_mode;
    fsm->folder_type = setting.folder_type;
    fsm_cntx->callback_hdlr = setting.scrn_callback_hdlr;

    /* Internal setting */
    fsm->folder_info.data_list_updated = MMI_TRUE;
    fsm->folder_info.data_list = NULL;
    fsm->pid = 0;
    fsm->action = MMI_UM_UI_ACTION_NONE;
    fsm->req_srv_status = MMI_UM_UI_REQ_SRV_NONE;
    fsm->get_msg_num = mmi_sms_um_bt_ui_fsm_ef_get_msg_num;
    fsm->get_msg_info = mmi_sms_um_bt_ui_fsm_ef_get_msg_info;
    fsm_cntx->type = MMI_UM_UI_FSM_ENTRY_FOLDER;
    fsm_cntx->event_hdlr = mmi_sms_um_bt_ui_fsm_event_hdlr;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_FSM_ENTRY_FOLDER_STATE, fsm->scrn_id, MMI_UM_UI_FSM_ENTRY_FOLDER, fsm->state);
}

void mmi_sms_um_bt_ui_fsm_ef_check_ready(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_fsm_entry_folder_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);
    fsm->state = MMI_UM_UI_FSM_EF_CHECK_READY;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_FSM_ENTRY_FOLDER_STATE, fsm->scrn_id, MMI_UM_UI_FSM_ENTRY_FOLDER, fsm->state);

    if ((fsm->folder_type.msg_type & srv_um_ready_msg_type()) != fsm->folder_type.msg_type)
    { 
        MMI_ASSERT((fsm->folder_type.msg_type & srv_um_ready_msg_type()) != fsm->folder_type.msg_type);
        return;
    }

    /* service is ready, go to get data */
    fsm->req_srv_status = MMI_UM_UI_REQ_SRV_NONE;
    fsm->action = MMI_UM_UI_ACTION_NONE;
    
    mmi_sms_um_bt_ui_fsm_ef_check_data(fsm_cntx);
}
void mmi_sms_um_bt_ui_fsm_ef_check_data(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_fsm_entry_folder_struct *fsm;
    S32 check_msg_list;
    S32 check_msg_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);
    fsm->state = MMI_UM_UI_FSM_EF_CHECK_DATA;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_FSM_ENTRY_FOLDER_STATE, fsm->scrn_id, MMI_UM_UI_FSM_ENTRY_FOLDER, fsm->state);

    /* request data list */
    if (NULL == fsm->folder_info.data_list &&
        MMI_TRUE == fsm->folder_info.data_list_updated)
    {
        check_msg_list = mmi_sms_um_bt_ui_fsm_ef_srv_check_msg_list(
                                            fsm->folder_type, 
                                            &(fsm->folder_info.filter_type), 
                                            mmi_sms_um_bt_ui_fsm_ef_msg_list_status_cb, 
                                            fsm->scrn_id, 
                                            &(fsm->folder_info.data_list), 
                                            fsm->folder_mode);
        /* Get the message list */
        if (check_msg_list > SRV_UM_RESULT_OK)
        {
            MMI_ASSERT(fsm->folder_info.data_list != NULL);
            fsm->folder_info.data_list_updated = MMI_FALSE;
            /* > 0, it is the list id and store in the fsm */
            fsm->folder_info.list_id = check_msg_list;
        }
    }

    /* data list needs to be updated */
    if (fsm->folder_info.data_list_updated == MMI_TRUE)
    {
        if (0 < fsm->folder_info.list_id)
        {
            /* release it first */
            srv_um_bt_release_msg_list(fsm->folder_info.list_id, MMI_TRUE);
            fsm->folder_info.list_id = 0;
            fsm->folder_info.data_list = NULL;
        }
        fsm->action = MMI_UM_UI_ACTION_GET_MSG_LIST;
        mmi_sms_um_bt_ui_fsm_ef_update_data(fsm_cntx);
        return;
    }

    /* Check the data list is empty. If yes, notify screen handler */
    if (NULL == fsm->folder_info.data_list)
    {
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_FINISH;
        fsm_cntx->callback_hdlr(fsm->scrn_id, (U16)fsm->state, (U16)fsm->req_srv_status);
        return;
    }
    else if (0 == fsm->folder_info.data_list->msg_number)
    {
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_FINISH;
        fsm_cntx->callback_hdlr(fsm->scrn_id, (U16)fsm->state, (U16)fsm->req_srv_status);
        return;
    }


    /* check message detail information */
    MMI_ASSERT(fsm->folder_info.num_of_req_item < MMI_UM_UI_MAX_MSG_INFO_NUM);

    /* check the last message index if overflow of data list */
    if ((fsm->folder_info.start_msg_idx + fsm->folder_info.num_of_req_item) > fsm->folder_info.data_list->msg_number)
    {
        /* the old message index is wrong, reassign it to 0 */
        fsm->folder_info.num_of_req_item = 0;
    }

    /* No need to get msg info because of the first time entry */
    if (fsm->folder_info.num_of_req_item == 0)
    {
        fsm_cntx->callback_hdlr(fsm->scrn_id, (U16)fsm->state, (U16)fsm->req_srv_status);
        return;
    }

    /* only need to check, it does not need to copy data */
    check_msg_info = mmi_sms_um_bt_ui_fsm_ef_srv_check_msg_info_by_ref(
                            fsm->folder_type, 
                            fsm->folder_info.data_list->list, 
                            fsm->folder_info.data_list->msg_number, 
                            fsm->folder_info.start_msg_idx, 
                            fsm->folder_info.num_of_req_item, 
                            NULL, 
                            NULL, 
                            fsm->folder_mode);

    /* Service has message detail information */
    if (check_msg_info >= SRV_UM_RESULT_OK)
    {
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_FINISH;
        /* Notify screen handler */
        fsm_cntx->callback_hdlr(fsm->scrn_id, (U16)fsm->state, (U16)fsm->req_srv_status);
    }
    else
    {
        fsm->action = MMI_UM_UI_ACTION_GET_MSG_INFO;
        mmi_sms_um_bt_ui_fsm_ef_update_data(fsm_cntx);
    }

}
void mmi_sms_um_bt_ui_fsm_ef_update_data(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_fsm_entry_folder_struct *fsm;
    void *msg_list;
    void *cb_func = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);
    fsm->state = MMI_UM_UI_FSM_EF_UPDATE_DATA;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_FSM_ENTRY_FOLDER_STATE, fsm->scrn_id, MMI_UM_UI_FSM_ENTRY_FOLDER, fsm->state);

    /* check necessary variable */
    MMI_ASSERT(fsm->folder_info.num_of_req_item < MMI_UM_UI_MAX_MSG_INFO_NUM);
    
    fsm->req_srv_status = MMI_UM_UI_REQ_SRV_PROGRESS;

    switch (fsm->action)
    {
        case MMI_UM_UI_ACTION_GET_MSG_LIST:
        {
			//fsm_cntx->callback_hdlr(fsm->scrn_id, (U16)fsm->state, (U16)fsm->req_srv_status);
            /* Request the data list from service */
            fsm->pid = mmi_sms_um_bt_ui_fsm_ef_srv_get_msg_list(
                                fsm->folder_type, 
                                &(fsm->folder_info.filter_type), 
                                mmi_sms_um_bt_ui_fsm_ef_req_msg_list_cb, 
                                fsm->scrn_id, 
                                fsm->folder_mode);
            break;
        }
        case MMI_UM_UI_ACTION_GET_MSG_INFO:
        {
            /* Request the message information from service */
            /* shift the message list pointer */
			fsm_cntx->callback_hdlr(fsm->scrn_id, (U16)fsm->state, (U16)fsm->req_srv_status);
            msg_list = fsm->folder_info.data_list->list;
            if (MMI_UM_FOLDER_MODE_DEFAULT == fsm->folder_mode)
            {
                msg_list = (void *)(((srv_um_msg_node_struct*)fsm->folder_info.data_list->list) + fsm->folder_info.start_msg_idx);
                cb_func = (void *)mmi_sms_um_bt_ui_fsm_ef_req_msg_info_cb;
            }
            else
            {
                MMI_ASSERT(0);
            }
            fsm->pid = mmi_sms_um_bt_ui_fsm_ef_srv_get_msg_info(
                                fsm->folder_type, 
                                msg_list,
                                fsm->folder_info.num_of_req_item, 
                                cb_func, 
                                fsm->scrn_id, 
                                fsm->folder_mode);
            break;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    /* Notify screen handler */
    fsm_cntx->callback_hdlr(fsm->scrn_id, (U16)fsm->state, (U16)fsm->req_srv_status);
}
void mmi_sms_um_bt_ui_fsm_ef_deinit(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_fsm_entry_folder_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);
    fsm->state = MMI_UM_UI_FSM_EF_DEINIT;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_FSM_ENTRY_FOLDER_STATE, fsm->scrn_id, MMI_UM_UI_FSM_ENTRY_FOLDER, fsm->state);
    
    /* release data list */
    if (0 < fsm->folder_info.list_id)
    {
        srv_sms_um_release_msg_list(fsm->folder_info.list_id, MMI_TRUE);
    }
    fsm->folder_info.list_id = 0;
    fsm->folder_info.data_list = NULL;
}

void mmi_sms_um_bt_ui_fsm_ef_msg_list_status_cb(S32 event, S32 list_cid, S32 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx;
    mmi_sms_um_bt_ui_fsm_entry_folder_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx((U16)para);
	//For BT dialer
	if(scrn_cntx == NULL)
		return;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);

    switch (event)
    {
        case SRV_UM_NOTIFY_LIST_RELEASED_IND:
        {
            /* Reset the data list */
            fsm->folder_info.data_list_updated = MMI_TRUE;
            fsm->folder_info.list_id = 0;
            fsm->folder_info.data_list = NULL;

            /* Send release event to fsm */
            mmi_sms_um_bt_ui_cc_send_event(fsm->scrn_id, MMI_UM_UI_EVENT_REL_DATA_LIST, NULL);
            break;
        }
        default:
        {
            break;
        }
    }
}
S32 mmi_sms_um_bt_ui_fsm_ef_req_list_msg_info_common_cb(S32 pid, S32 error, S32 para)
{
        /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx;
    mmi_sms_um_bt_ui_fsm_entry_folder_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check pid if invalid */
    //if (mmi_sms_um_bt_ui_fsm_check_invalid_pid(pid))
    //{
    //    /* remove it */
    //    mmi_sms_um_bt_ui_fsm_remove_invalid_pid(pid);
    //    return SRV_UM_RESULT_OK;
    //}
    
    scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx((U16)para);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);

    MMI_ASSERT(pid == fsm->pid);
    MMI_ASSERT(fsm->state == MMI_UM_UI_FSM_EF_UPDATE_DATA);

    /* Print the error log */
    if (error == SRV_UM_RESULT_CANCELLLED && fsm->req_srv_status == MMI_UM_UI_REQ_SRV_CANCELLING)
    {
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_CANCELLED;
    }

    if (error >= SRV_UM_RESULT_OK)
    {
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_FINISH;
    }

    /* Reset action */
    fsm->action = MMI_UM_UI_ACTION_NONE;
    /* Reset pid */
    fsm->pid = 0;

    /* List is gotten, go to check_data to get again */
    mmi_sms_um_bt_ui_fsm_ef_check_data(fsm_cntx);

     return SRV_UM_RESULT_OK;
}

S32 mmi_sms_um_bt_ui_fsm_ef_req_msg_list_cb(S32 pid, srv_um_get_msg_list_result *rsp, S32 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx;
    mmi_sms_um_bt_ui_fsm_entry_folder_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check pid if invalid */
    //if (mmi_sms_um_bt_ui_fsm_check_invalid_pid(pid))
    //{
    //    /* remove it */
    //    mmi_sms_um_bt_ui_fsm_remove_invalid_pid(pid);
    //    return SRV_UM_RESULT_OK;
    //}
    StopTimer(SMS_BT_TIMER_ID);
    scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx((U16)para);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);

    MMI_ASSERT(pid == fsm->pid);
    if (fsm->state != MMI_UM_UI_FSM_EF_UPDATE_DATA)
    {
        return SRV_UM_RESULT_OK;
    }

    /* Print the error log */
    if (rsp->error == SRV_UM_RESULT_CANCELLLED && fsm->req_srv_status == MMI_UM_UI_REQ_SRV_CANCELLING)
    {
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_CANCELLED;
    }

    if (rsp->error >= SRV_UM_RESULT_OK)
    {
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_FINISH;
    }

    /* Reset action */
    fsm->action = MMI_UM_UI_ACTION_NONE;
    /* Reset pid */
    fsm->pid = 0;

    /* List is gotten, go to check_data to get again */
    mmi_sms_um_bt_ui_fsm_ef_check_data(fsm_cntx);

    return SRV_UM_RESULT_OK;
}
S32 mmi_sms_um_bt_ui_fsm_ef_req_msg_info_cb(S32 pid, srv_um_get_msg_info_result *rsp, S32 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx;
    mmi_sms_um_bt_ui_fsm_entry_folder_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check pid if invalid */
    //if (mmi_sms_um_bt_ui_fsm_check_invalid_pid(pid))
    //{
    //    /* remove it */
    //    mmi_sms_um_bt_ui_fsm_remove_invalid_pid(pid);
    //    return SRV_UM_RESULT_OK;
    //}
    //
    scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx((U16)para);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    StopTimer(SMS_BT_TIMER_ID);
    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);

    MMI_ASSERT(pid == fsm->pid);
    //#ifdef __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__
    if (fsm->state != MMI_UM_UI_FSM_EF_UPDATE_DATA)
    {
        return SRV_UM_RESULT_OK;
    }
   // #else
    //MMI_ASSERT(fsm->state == MMI_UM_UI_FSM_EF_UPDATE_DATA);
    //#endif
   
    /* Print the error log */
    if (rsp->error == SRV_UM_RESULT_CANCELLLED && fsm->req_srv_status == MMI_UM_UI_REQ_SRV_CANCELLING)
    {
        fsm->req_srv_status = MMI_SMS_UM_BT_UI_REQ_SRV_CANCELLED;
    }

    if (rsp->error >= SRV_UM_RESULT_OK)
    {
        fsm->req_srv_status = MMI_SMS_UM_BT_UI_REQ_SRV_FINISH;
    }

    /* Reset pid */
    fsm->pid = 0;

    /* Reset action */
    fsm->action = MMI_SMS_UM_BT_UI_ACTION_NONE;

    //mmi_sms_bt_free_previous_mem();

    mmi_sms_um_bt_ui_fsm_ef_check_data(fsm_cntx);

    return SRV_UM_RESULT_OK;
}
U16 mmi_sms_um_bt_ui_fsm_ef_get_msg_num(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx;
    mmi_sms_um_bt_ui_fsm_entry_folder_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);

    if (fsm->folder_info.data_list == NULL)
    {
        return 0;
    }
    else
    {
        return fsm->folder_info.data_list->msg_number;
    }
}
MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_get_msg_info(
                    U16 scrn_id, 
                    U16 start_index, 
                    U16 num_of_req_item, 
                    srv_um_bt_msg_info_struct ***msg_info, 
                    srv_um_thread_info_struct ***thread_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 check_msg_info;
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx;
    mmi_sms_um_bt_ui_fsm_entry_folder_struct *fsm;
    srv_um_bt_msg_info_struct **msg_info_buffer;
    srv_um_thread_info_struct **thread_info_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);

    fsm->folder_info.start_msg_idx = start_index;
    fsm->folder_info.num_of_req_item = num_of_req_item;

    /* Data list is equal to NULL, no data. */
    /* During get message list state, no data */
    if (fsm->folder_info.data_list == NULL ||
        (fsm->state == MMI_UM_UI_FSM_EF_UPDATE_DATA && fsm->action == MMI_UM_UI_ACTION_GET_MSG_LIST))
    {
        (*msg_info) = NULL;
        return MMI_FALSE;
    }
    
    check_msg_info = SRV_UM_RESULT_OK;
    /* checking data from service */
    msg_info_buffer = mmi_sms_um_bt_ui_ut_get_msg_info_buf();
    thread_info_buffer = NULL;

    check_msg_info = mmi_sms_um_bt_ui_fsm_ef_srv_check_msg_info_by_ref(
                            fsm->folder_type, 
                            fsm->folder_info.data_list->list, 
                            fsm->folder_info.data_list->msg_number, 
                            fsm->folder_info.start_msg_idx, 
                            fsm->folder_info.num_of_req_item, 
                            msg_info_buffer, 
                            thread_info_buffer, 
                            fsm->folder_mode);

    /* No data */
    if (check_msg_info < SRV_UM_RESULT_OK)
    {
        (*msg_info) = NULL;
        return MMI_FALSE;
    }
    else
    {
        (*msg_info) = msg_info_buffer;
        return MMI_TRUE;
    }
}
U16 mmi_sms_um_bt_ui_fsm_ef_get_action(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_fsm_entry_folder_struct *fsm;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);

    return (U16)fsm->action;
}
void mmi_sms_um_bt_ui_fsm_ef_set_box_identity(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, srv_sms_um_box_identity_struct *box_identity)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_fsm_entry_folder_struct *fsm;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);

    /* Set the supporting message type */
    fsm->folder_type.msg_type = box_identity->msg_type;

    /* Set the supporting sim type */
    fsm->folder_type.sim_id = box_identity->sim_id;
}
srv_um_list_filter_struct *mmi_sms_um_bt_ui_fsm_ef_get_list_filter_type(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &(fsm_cntx->cntx.fsm_entry_folder.folder_info.filter_type);
}
void mmi_sms_um_bt_ui_fsm_ef_set_list_filter_type(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, srv_um_list_filter_struct filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&(fsm_cntx->cntx.fsm_entry_folder.folder_info.filter_type), 
           &filter, 
           sizeof(srv_um_list_filter_struct));
}
srv_um_sim_enum mmi_sms_um_bt_ui_fsm_ef_get_sim_type(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return fsm_cntx->cntx.fsm_entry_folder.folder_type.sim_id;
}
S32 mmi_sms_um_bt_ui_fsm_ef_srv_check_msg_list(
                srv_sms_um_box_identity_struct msg_box,
                srv_um_list_filter_struct *filter,
                srv_um_notify_list_handler cb_func,
                S32 user_data,
                srv_um_list_cntx_struct **list_cntx, 
                mmi_sms_um_bt_ui_folder_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error = 0;

    switch (mode)
    {
        case MMI_UM_FOLDER_MODE_DEFAULT:
        {
			error = srv_sms_um_check_msg_list(
				SRV_UM_LIST_TYPE_MSG_NODE,
				msg_box, 
				filter, 
				cb_func, 
				user_data, 
				list_cntx);
			//error = srv_sms_um_check_msg_list(
			//	msg_box, 
			//	filter, 
			//	cb_func, 
			//	user_data, 
			//	list_cntx);
			break;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return error;
}
S32 mmi_sms_um_bt_ui_fsm_ef_srv_get_msg_list(
                srv_sms_um_box_identity_struct msg_box, 
                srv_um_list_filter_struct *filter, 
                srv_um_get_list_cb cb_func, 
                S32 user_data, 
                mmi_sms_um_bt_ui_folder_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error = 0;

    switch (mode)
    {
        case MMI_UM_FOLDER_MODE_DEFAULT:
        {
            //error = srv_um_get_msg_list(
            //                    msg_box, 
            //                    filter, 
            //                    cb_func, 
            //                    user_data);

			srv_sms_um_bt_get_msg_list(
								0,
                                msg_box, 
                                filter, 
                                cb_func, 
                                user_data);
            break;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return error;
}
S32 mmi_sms_um_bt_ui_fsm_ef_srv_check_msg_info(
                    srv_sms_um_box_identity_struct msg_box, 
                    void *msg_list, 
                    U16 list_info_size, 
                    U16 start_entry, 
                    U16 msg_number, 
                    srv_um_bt_msg_info_struct msg_info[], 
                    mmi_sms_um_bt_ui_folder_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error = 0;

    switch (mode)
    {
        case MMI_UM_FOLDER_MODE_DEFAULT:
        {
           /* error = srv_um_check_msg_info(
                                msg_box, 
                                (srv_um_msg_node_struct *)msg_list, 
                                list_info_size, 
                                start_entry, 
                                msg_number, 
                                msg_info);*/
            break;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return error;
}

S32 mmi_sms_um_bt_ui_fsm_ef_srv_check_msg_info_by_ref(
                    srv_sms_um_box_identity_struct msg_box, 
                    void *msg_list, 
                    U16 list_info_size, 
                    U16 start_entry, 
                    U16 msg_number, 
                    srv_um_bt_msg_info_struct *msg_info[], 
                    srv_um_thread_info_struct *thread_info[], 
                    mmi_sms_um_bt_ui_folder_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error = 0;

    switch (mode)
    {
        case MMI_UM_FOLDER_MODE_DEFAULT:
        {
            //error = srv_um_check_msg_info_by_ref(
            //                    msg_box, 
            //                    (srv_um_msg_node_struct *)msg_list, 
            //                    list_info_size, 
            //                    start_entry, 
            //                    msg_number, 
            //                    msg_info);
            error = srv_sms_um_check_msg_info_by_ref(
                                msg_box, 
                                (srv_um_msg_node_struct *)msg_list, 
                                list_info_size, 
                                start_entry, 
                                msg_number, 
                                msg_info);
            break;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return error;
}
S32 mmi_sms_um_bt_ui_fsm_ef_srv_get_msg_info(
                    srv_sms_um_box_identity_struct msg_box,
                    void *msg_list,
                    U16 msg_number,
                    void *cb_func,
                    S32 user_data, 
                    mmi_sms_um_bt_ui_folder_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error = 0;

    switch (mode)
    {
        case MMI_UM_FOLDER_MODE_DEFAULT:
        {
			error = srv_sms_um_bt_get_msg_info(
									msg_box, 
				                    (srv_um_msg_node_struct *)msg_list, 
				                    msg_number, 
				                    (srv_um_get_msg_info_cb)cb_func, 
				                    user_data);
            break;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return error;
}
mmi_sms_um_bt_ui_folder_mode_enum mmi_sms_um_bt_ui_fsm_ef_get_folder_mode(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_folder_mode_enum mode;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mode = MMI_UM_FOLDER_MODE_TOTAL;

    if (MMI_UM_UI_FSM_ENTRY_FOLDER == fsm_cntx->type)
    {
        mode = fsm_cntx->cntx.fsm_entry_folder.folder_mode;
    }
    else
    {
        MMI_ASSERT(0);
    }

    return mode;
}
void mmi_sms_um_bt_ui_fsm_ef_set_folder_mode(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, mmi_sms_um_bt_ui_folder_mode_enum folder_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm_cntx->cntx.fsm_entry_folder.folder_mode = folder_mode;
}
srv_um_list_cntx_struct *mmi_sms_um_bt_ui_fsm_get_data_list_ptr(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_list_cntx_struct *data_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_list = NULL;
    
    switch (fsm_cntx->type)
    {
        case MMI_UM_UI_FSM_ENTRY_FOLDER:
        {
            data_list = fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list;
            break;
        }
        default:
        {
            break;
        }
    }

    return data_list;
}
void mmi_sms_um_bt_ui_fsm_set_data_list_ptr(
                    mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, 
                    srv_um_list_cntx_struct *data_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch (fsm_cntx->type)
    {
        case MMI_UM_UI_FSM_ENTRY_FOLDER:
        {
            fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list = data_list;
            break;
        }
        default:
        {
            break;
        }
    }
}
U16 mmi_sms_um_bt_ui_fsm_get_fsm_state(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    state = 0;
    
    switch (fsm_cntx->type)
    {
        case MMI_UM_UI_FSM_ENTRY_LIST:
        {
            state = fsm_cntx->cntx.fsm_entry_list.state;
            break;
        }
        case MMI_UM_UI_FSM_ENTRY_FOLDER:
        {
            state = fsm_cntx->cntx.fsm_entry_folder.state;
            break;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return state;
}
U16 mmi_sms_um_bt_ui_fsm_get_fsm_req_srv_status(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = 0;
    
    switch (fsm_cntx->type)
    {
        case MMI_UM_UI_FSM_ENTRY_LIST:
        {
            status = fsm_cntx->cntx.fsm_entry_list.req_srv_status;
            break;
        }
        case MMI_UM_UI_FSM_ENTRY_FOLDER:
        {
            status = fsm_cntx->cntx.fsm_entry_folder.req_srv_status;
            break;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return status;
}
MMI_BOOL mmi_sms_um_bt_ui_fsm_eh_dummy(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return MMI_TRUE;
}
MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_init_init(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (!g_sms_bt_ui_p[g_sms_active_dev_index].mmi_need_keep_list)
    {
        fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_TRUE;
        srv_sms_um_pool_clean(SRV_UM_MSG_SMS,SRV_UM_MSG_BOX_ALL);
    }
    g_sms_bt_ui_p[g_sms_active_dev_index].mmi_need_keep_list = MMI_FALSE;
    mmi_sms_um_bt_ui_fsm_ef_check_ready(fsm_cntx);
    
    return MMI_TRUE;
}
MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_init_delete(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_fsm_ef_deinit(fsm_cntx);
    
    return MMI_TRUE;
}
MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_init_kp_list(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check ready first. If it is not ready, it should not set the flag as FALSE */
    if (srv_um_check_ready_type(fsm_cntx->cntx.fsm_entry_folder.folder_type.msg_type))
    {
        fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_FALSE;
        g_sms_bt_ui_p[g_sms_active_dev_index].mmi_need_keep_list = MMI_TRUE;
    }

    return MMI_TRUE;
}
MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_cr_delete(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_fsm_ef_deinit(fsm_cntx);
    
    return MMI_TRUE;
}
MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_cr_ready(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_fsm_ef_check_ready(fsm_cntx);
    
    return MMI_TRUE;
}
MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_cr_check(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_fsm_ef_check_ready(fsm_cntx);
    
    return MMI_TRUE;
}
MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_cd_refresh(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_TRUE;
    mmi_sms_um_bt_ui_fsm_ef_check_data(fsm_cntx);
    
    return MMI_TRUE;
}
MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_cd_delete(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_fsm_ef_deinit(fsm_cntx);
    
    return MMI_TRUE;
}
MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_cd_check(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_fsm_ef_check_data(fsm_cntx);
    
    return MMI_TRUE;
}
MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_cd_unready(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_TRUE;
    mmi_sms_um_bt_ui_fsm_ef_check_ready(fsm_cntx);
    
    return MMI_TRUE;
}

MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_cd_rel_list(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* release and clean it */
    if (0 < fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id)
    {
        srv_um_release_msg_list(fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id, MMI_TRUE);
        fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id = 0;
        fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list = NULL;
    }
    fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_TRUE;
    
    return MMI_TRUE;
}
MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_cd_up_list(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_TRUE;
    /* release data list */
    if (0 < fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id)
    {
        srv_um_release_msg_list(fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id, MMI_TRUE);
        fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id = 0;
        fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list = NULL;
    }
    
    return MMI_TRUE;
}
MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_ud_refresh(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fsm_cntx->cntx.fsm_entry_folder.action == MMI_UM_UI_ACTION_GET_MSG_INFO)
    {
        fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_TRUE;
    }
    
    return MMI_TRUE;
}
MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_ud_check(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_fsm_entry_folder_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Notify screen handler to modify the screen */
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);
    
    fsm_cntx->callback_hdlr(fsm->scrn_id, (U16)fsm->state, (U16)fsm->req_srv_status);

    return MMI_TRUE;
}
void mmi_sms_um_bt_ui_fsm_ef_eh_common_unready_rel_list(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 pid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_TRUE;

    if (fsm_cntx->cntx.fsm_entry_folder.pid != 0)
    {
        fsm_cntx->cntx.fsm_entry_folder.req_srv_status = MMI_UM_UI_REQ_SRV_CANCELLED;
        /* release data list */
        if (0 < fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id)
        {
            srv_um_release_msg_list(fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id, MMI_TRUE);
            fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id = 0;
            fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list = NULL;
        }
        fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_TRUE;
        /* add the pid into invalid array */
        pid = fsm_cntx->cntx.fsm_entry_folder.pid;
        //mmi_sms_um_bt_ui_fsm_add_invalid_pid(pid);
        /* reset the pid of FSM */
        fsm_cntx->cntx.fsm_entry_folder.pid = 0;
    }
}
MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_ud_delete(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    S32 pid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;

    /* has action */
    if (fsm_cntx->cntx.fsm_entry_folder.pid != 0)
    {
        fsm_cntx->cntx.fsm_entry_folder.req_srv_status = MMI_UM_UI_REQ_SRV_CANCELLED;
        /* release data list */
        if (0 < fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id)
        {
            srv_um_release_msg_list(fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id, MMI_TRUE);
            fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id = 0;
            fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list = NULL;
        }
        fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_TRUE;
        /* add the pid into invalid array */
        pid = fsm_cntx->cntx.fsm_entry_folder.pid;
        //mmi_sms_um_bt_ui_fsm_add_invalid_pid(pid);
        /* reset the pid of FSM */
        fsm_cntx->cntx.fsm_entry_folder.pid = 0;
        
        if (srv_um_cancel_request(pid) < SRV_UM_RESULT_OK)
        {
            MMI_ASSERT(0);
        }      
    }
    else
    {
        mmi_sms_um_bt_ui_fsm_ef_deinit(fsm_cntx);
    }
    
    return result;
}
MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_ud_unready(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    S32 pid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;
    fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_TRUE;

    if (fsm_cntx->cntx.fsm_entry_folder.pid != 0)
    {
        fsm_cntx->cntx.fsm_entry_folder.req_srv_status = MMI_UM_UI_REQ_SRV_CANCELLED;
        /* release data list */
        if (0 < fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id)
        {
            srv_um_release_msg_list(fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id, MMI_TRUE);
            fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id = 0;
            fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list = NULL;
        }
        fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_TRUE;
        /* add the pid into invalid array */
        pid = fsm_cntx->cntx.fsm_entry_folder.pid;
        //mmi_sms_um_bt_ui_fsm_add_invalid_pid(pid);
        /* reset the pid of FSM */
        fsm_cntx->cntx.fsm_entry_folder.pid = 0;
        
        if (srv_um_cancel_request(pid) < SRV_UM_RESULT_OK)
        {
            result = MMI_FALSE;
        }
    }
    
    mmi_sms_um_bt_ui_fsm_ef_check_ready(fsm_cntx);
    
    return result;
}

MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_ud_rel_list(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 pid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Release data list */
    if (0 < fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id)
    {
        srv_um_release_msg_list(fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id, MMI_TRUE);
        fsm_cntx->cntx.fsm_entry_folder.folder_info.list_id = 0;
        fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list = NULL;
    }
    fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_TRUE;
    
    if (fsm_cntx->cntx.fsm_entry_folder.pid != 0)
    {
        fsm_cntx->cntx.fsm_entry_folder.req_srv_status = MMI_UM_UI_REQ_SRV_CANCELLED;
        /* add the pid into invalid array */
        pid = fsm_cntx->cntx.fsm_entry_folder.pid;
        //mmi_sms_um_bt_ui_fsm_add_invalid_pid(pid);
        /* reset the pid of FSM */
        fsm_cntx->cntx.fsm_entry_folder.pid = 0;
        
        if (srv_um_cancel_request(pid) < SRV_UM_RESULT_OK)
        {
            MMI_ASSERT(0);
        }
    }
    /* entry check_data state */
    mmi_sms_um_bt_ui_fsm_ef_check_data(fsm_cntx);
    return MMI_TRUE;
}

MMI_BOOL mmi_sms_um_bt_ui_fsm_ef_eh_ud_up_list(mmi_sms_um_bt_ui_fsm_node_struct *fsm_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm_cntx->cntx.fsm_entry_folder.folder_info.data_list_updated = MMI_TRUE;
    
    return MMI_TRUE;
}

U16 mmi_sms_um_bt_ui_ut_get_str_id_by_folder(srv_sms_um_box_identity_struct folder_type) /*Akhil*/
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_id = 0;
    
    switch (folder_type.msg_box_type)
    {
        case SRV_UM_MSG_BTMAPC_BOX_INBOX:
        {
            str_id = STR_GLOBAL_INBOX;
            break;
        }
        case SRV_UM_MSG_BTMAPC_BOX_UNSENT:
        {
           // str_id = STR_SMS_UM_BT_SEND_FAILED_MSG;
			str_id = STR_GLOBAL_OUTBOX;
            break;
        }
        case SRV_UM_MSG_BTMAPC_BOX_OUTBOX:
        {
           // 
            str_id = STR_SMS_UM_BT_SENT_ID;
            break;
        }
        case SRV_UM_MSG_BTMAPC_BOX_DRAFTS:
        {
            str_id = STR_GLOBAL_DRAFTS;
            break;
        }
        default:
        {
            break;
        }
    }

    return str_id;
}

U16 mmi_sms_um_bt_ui_ut_get_fsm_event_by_ui_event(U16 ui_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 fsm_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm_event = MMI_UM_UI_FSM_EVENT_TOTAL;
    
    switch (ui_event)
    {
        case MMI_UM_UI_EVENT_INIT:
        {
            fsm_event = MMI_UM_UI_FSM_EVENT_INIT;
            break;
        }
        case MMI_UM_UI_EVENT_REFRESH:
        {
            fsm_event = MMI_UM_UI_FSM_EVENT_REFRESH;
            break;
        }
        case MMI_UM_UI_EVENT_ABORT:
        {
            fsm_event = MMI_UM_UI_FSM_EVENT_ABORT;
            break;
        }
        case MMI_UM_UI_EVENT_DELETE:
        {
            fsm_event = MMI_UM_UI_FSM_EVENT_DELETE;
            break;
        }
        case MMI_UM_UI_EVENT_CHECK:
        {
            fsm_event = MMI_UM_UI_FSM_EVENT_CHECK;
            break;
        }
        case MMI_UM_UI_EVENT_READY:
        {
            fsm_event = MMI_UM_UI_FSM_EVENT_READY;
            break;
        }
        case MMI_UM_UI_EVENT_UNREADY:
        {
            fsm_event = MMI_UM_UI_FSM_EVENT_UNREADY;
            break;
        }
        case MMI_UM_UI_EVENT_REL_DATA_LIST:
        {
            fsm_event = MMI_UM_UI_FSM_EVENT_REL_DATA_LIST;
            break;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return fsm_event;
}
U16 mmi_sms_um_bt_ui_ut_create_scrn_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_um_ui_p->setting.scrn_id_counter++;

    if (0 == g_sms_um_ui_p->setting.scrn_id_counter)
    {
        g_sms_um_ui_p->setting.scrn_id_counter = 1;
    }
    return g_sms_um_ui_p->setting.scrn_id_counter;
}
srv_um_bt_msg_info_struct **mmi_sms_um_bt_ui_ut_get_msg_info_buf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_sms_um_ui_msg_info_buf_p, 0, sizeof(g_sms_um_ui_msg_info_buf_p));

    return g_sms_um_ui_msg_info_buf_p;
}
void mmi_sms_um_bt_ui_ut_del_relative_scrn(U16 *scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tmp_scrn_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmp_scrn_id = *scrn_id;
    *scrn_id = 0;
    kal_prompt_trace(MOD_MMI, "[SMS], Entry mmi_sms_um_bt_ui_ut_del_relative_scrn scrn_id = %d",*scrn_id);
    if (tmp_scrn_id > 0)
    {
        mmi_sms_um_bt_ui_cc_send_event(tmp_scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
    }
}
void mmi_sms_um_bt_ui_ut_notify_scrn_deleted(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scrn_id > 0)
    {
        mmi_sms_um_bt_ui_cc_send_event(scrn_id, MMI_UM_UI_EVENT_DELETED, NULL);
    }
}
void mmi_sms_um_bt_ui_ut_send_init_event(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scrn_id > 0)
    {
        mmi_sms_um_bt_ui_cc_send_event(scrn_id, MMI_SMS_UM_BT_UI_EVENT_INIT, NULL);
    }
}
U16 mmi_sms_um_bt_ui_ut_get_disp_scrn_id_by_scrn_id(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_bt_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scrn_id == 0)
    {
        MMI_ASSERT(0);
    }

    scrn_cntx = mmi_sms_um_bt_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    return scrn_cntx->screen_hdlr.disp_scrn_id;
}
void mmi_sms_um_bt_ui_ut_update_item_by_menu_id(U16 parent_menu_id, U16 menu_id, U8 **item_string, U16 number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U8 hint_asc[MAX_SUB_MENU_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_test_menu_item_hide(menu_id))
    {
        i = GetIndexOfStringId_Ext(parent_menu_id, menu_id);
        sprintf((S8 *)hint_asc, " (%d)", number);
        //mmi_sms_um_bt_ui_ut_concate_str_with_num((S8 *)hint_asc, (S8 *)item_string[i]);
    }
}

MMI_BOOL mmi_sms_bt_map_is_connected()
{
    return g_sms_bt_ui_p[g_sms_active_dev_index].is_bt_connected;
}

#endif
