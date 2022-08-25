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
*  BTNotificationMain.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   BT Notification Source File
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
*==============================================================================
*******************************************************************************/

#include "mmi_features.h"
#if (defined(__MMI_BT_NOTIFICATION__) || defined (__MMI_BT_NOTI_SRV__))

#ifdef __MMI_WEARABLE_DEVICE__
#define __MMI_BT_NOTIFICATION_FOR_WEARABLE__
#endif  //__MMI_WEARABLE_DEVICE__

#include "BTNotificationGprot.h"
#include "BTNotificationProt.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_rp_app_btnotification_def.h"
#include "GlobalResDef.h"
#include "mmi_frm_history_gprot.h"
#include "GlobalConstants.h"
#include "MenuCuiGprot.h"
#include "wgui_inline_edit.h"
#include "BTNotiSrvGprot.h"
#include "app_datetime.h"
#include "DateTimeType.h"
#include "mmi_rp_app_sms_def.h"
#include "mmi_rp_app_unifiedmessage_def.h"
#include "Mmi_rp_srv_bt_noti_def.h"
#include "wgui_categories_ems.h"
#include "btmmiscrgprots.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "wgui_categories_ems.h"
#include "wgui_fixed_menus.h"
#include "wgui_categories_list.h"
#include "wgui_categories_popup.h"
#include "wgui_categories_UCE.h"
#include "Gsm7BitNationalLang.h"
#include "SmsSrvGprot.h"
#include "UcmGprot.h"
#include "CommonScreens.h"
#include "mmi_rp_app_smsbtunifiedmessage_def.h"
#include "SmsBtMapCSrvGprot.h"
#include "BTMMIScrGprots.h"
#include "wgui_categories_list.h"
#include "SmsAppGprot.h"
#include "CommonScreensResDef.h"
#include "AlertScreen.h"
#ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
#include "mmi_rp_app_scr_locker_def.h"
#endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__


#ifndef __MTK_TARGET__
#define SRV_BT_NOTIFY_TEST_FSM
#define SRV_BT_NOTIFY_TEST_WITHOUT_SPP
#endif

mmi_bt_notification_cntx_struct g_mmi_bt_notification_cntx = {0};
mmi_bt_notification_option_struct g_mmi_bt_notification_option = {0};
mmi_bt_notification_cntx_struct* g_mmi_bt_notification_cntx_p;


static void mmi_bt_notification_main_show_category(void);
static void mmi_bt_notification_main_show_entry(MMI_ID parent_id);


#endif/*defined(__MMI_BT_NOTIFICATION__) || defined (__MMI_BT_NOTI_SRV__)*/

#ifdef __MMI_BT_NOTIFICATION__


void mmi_bt_notification_init()   // add in bootup
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_notification_cntx.id = 0;
    g_mmi_bt_notification_cntx.total = 0;
    g_mmi_bt_notification_cntx.current_dev = 0;
    g_mmi_bt_notification_cntx_p = &g_mmi_bt_notification_cntx;
    g_mmi_bt_notification_cntx_p->option_struct = &g_mmi_bt_notification_option;
    g_mmi_bt_notification_cntx_p->synced = MMI_TRUE;
#ifdef SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    //srv_bt_noti_recv_receive_data_test_without_spp(0);
    //srv_bt_noti_recv_receive_data_test_without_spp_1(0);
    //srv_bt_noti_recv_receive_data_test_without_spp_2(0);
#endif  //SRV_BT_NOTIFY_TEST_WITHOUT_SPP
}


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_btnotification
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_btnotification(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(mmi_bt_notification_launch, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_bt_notification_launch, KEY_EVENT_UP);
}


static void mmi_bt_notification_main_show_empty(WCHAR *device_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 list_not_ready;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_screen();
    wgui_cat1032_show(
        device_name,
        0,
        0,
        0,
        (WCHAR*)GetString(STR_GLOBAL_BACK),
        0,
        0,
        NULL,
        NULL,
        NULL,
        0,
        0,   
        0,
        NULL,
        &list_not_ready);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


static void mmi_bt_notification_main_show_disconnect(WCHAR *device_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 list_not_ready;
    MMI_ID hint_str_id;
    U8 *gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bt_cm_get_linked_dev_list_idx() == 0)
    {
        hint_str_id = STR_ID_BTNOTIFICATION_APPLICATION_NEED_USER_CONNECT;
    }
    else
    {
        hint_str_id = STR_ID_BTNOTIFICATION_APPLICATION_DISCONNECT;
    }
#ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
	wgui_showcategory6333_screen(NULL,
		(UI_string_type)GetString(STR_GLOBAL_OK),
		NULL,
		(UI_string_type)GetString(hint_str_id),
		NULL);
    SetLeftSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#else  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
    wgui_set_menu_empty_string_by_id(hint_str_id);
    wgui_cat1032_show(
        device_name,
        0,
        0,
        0,
        (WCHAR*)GetString(STR_GLOBAL_BACK),
        0,
        0,
        NULL,
        NULL,
        NULL,
        0,
        0,   
        0,
        gui_buffer,
        &list_not_ready);
    wgui_set_menu_empty_string_by_id(STR_GLOBAL_EMPTY);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
}


#ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__

static WCHAR g_bt_notification_icon_path_cache[SRV_BT_NOTI_MSG_LIST_MAX_NUM][BT_NOTIFY_ICON_FILE_NAME_LENTH];

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_msg_list_get_item_async
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_index       [IN]
 *  menu_data
 *  num_item
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_bt_notification_msg_list_get_item_async(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body								                          */
    /*----------------------------------------------------------------*/
    for (i = 0; i < num_item; ++i, ++start_index)
    {
        memset(&g_mmi_bt_notification_cntx_p->node, 0, sizeof(srv_bt_noti_data_msg_node_struct));
        srv_bt_noti_data_get_msg_info_ref(&g_mmi_bt_notification_cntx_p->current_dev_addr, start_index, &g_mmi_bt_notification_cntx_p->node);
        if (g_mmi_bt_notification_cntx_p->node.header.subtype == srv_bt_notify_subtype_sms)
        {
            menu_data[i].image_list[0] = (PU8)GetImage(IMG_MESSAGE_UNREAD);
            menu_data[i].flag_ext = NULL;
        }
        else
        {
            mmi_ucs2ncpy((CHAR*)g_bt_notification_icon_path_cache[start_index], (CHAR*)g_mmi_bt_notification_cntx_p->node.icon_file_path, BT_NOTIFY_ICON_FILE_NAME_LENTH-1);
            menu_data[i].image_list[0] = (PU8)g_bt_notification_icon_path_cache[start_index];
            menu_data[i].flag_ext |= UI_MENUITEM_IMAGE_PATH;
        }
	    mmi_ucs2ncpy((S8*) menu_data[i].item_list[0], (S8*) g_mmi_bt_notification_cntx_p->node.sender, BT_NOTIFY_SENDER_LENTH -1);
        if (mmi_ucs2strlen((S8*)g_mmi_bt_notification_cntx_p->node.title) > 1)
        {
	        mmi_ucs2ncpy((S8*) menu_data[i].item_list[1], (S8*) g_mmi_bt_notification_cntx_p->node.title, BT_NOTIFY_SENDER_LENTH -1);
        }
        else if (mmi_ucs2strlen((S8*)g_mmi_bt_notification_cntx_p->node.content) > 1)
        {
	        mmi_ucs2ncpy((S8*) menu_data[i].item_list[1], (S8*) g_mmi_bt_notification_cntx_p->node.content, BT_NOTIFY_SENDER_LENTH -1);
        }
        else
        {
	        mmi_ucs2ncpy((S8*) menu_data[i].item_list[1], (S8*) g_mmi_bt_notification_cntx_p->node.ticker_text, BT_NOTIFY_SENDER_LENTH -1);
        }
        //mmi_ucs2cat((S8 *) menu_data[i].item_list[1], (S8 *)L"...");
    }
    
    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_show_msg_list_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_notification_show_msg_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_notification_cntx_p->id = index;
}


static mmi_ret mmi_bt_notification_show_msg_list_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, evt->evt_id, 0);
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            //clear cache
            memset(&g_bt_notification_icon_path_cache, 0, SRV_BT_NOTI_MSG_LIST_MAX_NUM * BT_NOTIFY_ICON_FILE_NAME_LENTH);
            g_mmi_bt_notification_cntx_p->id = 0;
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_msg_list_mark_as_read_confirm_proc
 * DESCRIPTION
 *  mark all as readl confirm proc
 *  Functionality:
 * PARAMETERS
 *  mmi_alert_result_evt_struct [IN]                       
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_bt_notification_msg_list_mark_as_read_confirm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *confirm_evt = NULL;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ASSERT(evt);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, evt->evt_id, 1);
    
    switch (evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            confirm_evt = (mmi_alert_result_evt_struct*)evt;
            switch (confirm_evt->result)
            {
                case MMI_ALERT_CNFM_OK:
                case MMI_ALERT_CNFM_YES:
                {
                    break;
                }
                default:
                break;
            }
        }
    }

    return  MMI_RET_OK;
}


#if defined(__MMI_TOUCH_SCREEN__)

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_msg_list_long_tap_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_notification_msg_list_long_tap_hdlr(mmi_pen_point_struct pos)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

#endif  //defined(__MMI_TOUCH_SCREEN__)


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_main_show_entry_from_msg_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_notification_main_show_entry_from_msg_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_notification_main_show_entry(GRP_ID_BTNOTIFICATION_MSG_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_show_msg_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_notification_show_msg_list(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    //S32 total = 0;
    const srv_bt_cm_dev_struct* dev_p = NULL;
	#ifdef SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    WCHAR device_name[SRV_BT_CM_BD_UCS2_NAME_LEN] = L"BT Device";
	#else  //SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    WCHAR device_name[SRV_BT_CM_BD_UCS2_NAME_LEN] = {0};
	#endif  //SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    //S32 cat_err = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, g_mmi_bt_notification_cntx_p->current_dev, g_mmi_bt_notification_cntx_p->current_dev_addr.lap, g_mmi_bt_notification_cntx_p->current_dev_addr.uap, g_mmi_bt_notification_cntx_p->current_dev_addr.nap, 0);

    mmi_frm_group_create_ex(
        parent_id, 
        GRP_ID_BTNOTIFICATION_MSG_LIST, 
        mmi_bt_notification_show_msg_list_proc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    if (!mmi_frm_scrn_enter(GRP_ID_BTNOTIFICATION_MSG_LIST, SCR_ID_BTNOTIFICATION_MSG_LIST, NULL, mmi_bt_notification_show_msg_list, MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }
    
    #ifndef SRV_BT_NOTIFY_TEST_WITHOUT_SPP    
    dev_p = srv_bt_cm_get_linked_dev_info(g_mmi_bt_notification_cntx_p->current_dev);
    memcpy((void*)&g_mmi_bt_notification_cntx_p->current_dev_addr, (void*)&dev_p->bd_addr, sizeof(srv_bt_cm_bt_addr));
    
    srv_bt_cm_get_dev_ucs2_name(
        &(g_mmi_bt_notification_cntx_p->current_dev_addr),
        SRV_BT_CM_BD_UCS2_NAME_LEN,
        device_name);
    
    if (MMI_FALSE == srv_bt_noti_check_connection())
    {
        mmi_bt_notification_main_show_disconnect((WCHAR*)GetString(STR_ID_BTNOTIFICATION_APPLICATION_APP_NAME));
        return;
    }
    else if (MMI_FALSE == srv_bt_noti_check_connection_ext(&g_mmi_bt_notification_cntx_p->current_dev_addr))
    {
        mmi_bt_notification_main_show_disconnect(device_name);
        return;
    }
    #endif  //SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    g_mmi_bt_notification_cntx_p->total = srv_bt_noti_data_get_msg_num(&g_mmi_bt_notification_cntx_p->current_dev_addr);
    
    if (g_mmi_bt_notification_cntx_p->total == 0)
    { 
        mmi_bt_notification_main_show_empty(device_name);
    }
    else
    {
        guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_BTNOTIFICATION_MSG_LIST, SCR_ID_BTNOTIFICATION_MSG_LIST);

        if (guiBuffer != NULL)
        {
            list_menu_category_history *hist = (list_menu_category_history*) guiBuffer;
            g_mmi_bt_notification_cntx_p->id = hist->highlighted_item;
        }

        /* register highligh handler */
        RegisterHighlightHandler(mmi_bt_notification_show_msg_list_highlight_hdlr);
        
        wgui_cat_set_list_menu_empty_lable((UI_string_type)get_string(STR_GLOBAL_EMPTY));
        wgui_swatch_two_line_menu_list_screen(
             (PU8)device_name,
             NULL,
             STR_GLOBAL_VIEW,
             NULL,
             STR_GLOBAL_BACK,
             g_mmi_bt_notification_cntx_p->total,
             mmi_bt_notification_msg_list_get_item_async,
             g_mmi_bt_notification_cntx_p->id,
             guiBuffer);
        
        /* register LSK, RSK hanlders */
        SetLeftSoftkeyFunction(mmi_bt_notification_main_show_entry_from_msg_list, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_bt_notification_main_show_entry_from_msg_list, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        #if defined(__MMI_TOUCH_SCREEN__)
        wgui_register_pen_long_tap_handler(mmi_bt_notification_msg_list_long_tap_hdlr);
        #endif  //defined(__MMI_TOUCH_SCREEN__)
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_show_msg_list_from_dev_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_notification_show_msg_list_from_dev_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_notification_show_msg_list(GRP_ID_BTNOTIFICATION_APP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_mre_install_show
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_notification_mre_install_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    ShowCategory165Screen(
        0,
        0,
        0,
        0,
        (UI_string_type)GetString(STR_ID_BTNOTIFICATION_POPUP_MRE_INSTALL),
        IMG_GLOBAL_LOADING,
        gui_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_mre_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_bt_notification_mre_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, evt->evt_id, 2);
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            mmi_bt_notification_mre_install_show();
            break;

        case EVT_ID_SCRN_DEINIT:
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_mre_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scen_id
 *  arg
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_bt_notification_mre_entry(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_BTNOTIFICATION_MRE,
        mmi_bt_notification_mre_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_create(GRP_ID_BTNOTIFICATION_MRE, 
        SCR_ID_BTNOTIFICATION_MRE, 
        mmi_bt_notification_mre_proc,
        NULL);

    return MMI_TRUE;
}

#endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_dev_list_get_item_async
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_index       [IN]
 *  menu_data
 *  num_item
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_bt_notification_dev_list_get_item_async(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body								                          */
    /*----------------------------------------------------------------*/
    for (i = 0; i < num_item; ++i, ++start_index)
    {
        const srv_bt_cm_dev_struct* dev_p = srv_bt_cm_get_linked_dev_info(i);
        if (dev_p != NULL)
        {
            srv_bt_cm_get_dev_ucs2_name(
                &(dev_p->bd_addr),
                SRV_BT_CM_BD_UCS2_NAME_LEN,
                menu_data[i].item_list[0]);
            
            menu_data[i].image_list[0] = (PU8)mmi_bt_get_device_image(dev_p->cod);
        }
        else
        {
            kal_wsprintf((WCHAR*)menu_data[i].item_list[0], "BT Device %d", i+1);
            menu_data[i].image_list[0] = (PU8)mmi_bt_get_device_image(NULL);
        }
    }
    
    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_show_dev_list_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_notification_show_dev_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_notification_cntx_p->current_dev = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_main_show_entry_from_dev_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_notification_main_show_entry_from_dev_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_notification_main_show_entry(GRP_ID_BTNOTIFICATION_APP);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_bt_notification_show_dev_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_notification_show_dev_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    #ifdef SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    S32 total = 2;
    #else  //SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    S32 total = srv_bt_cm_get_linked_dev_list_idx();
    #endif  //SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    S32 cat_err = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    #ifndef SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    if (MMI_FALSE == srv_bt_noti_check_connection())
    {
        mmi_bt_notification_main_show_disconnect((WCHAR*)GetString(STR_ID_BTNOTIFICATION_APPLICATION_APP_NAME));
        return;
    }
    
    if (srv_bt_cm_get_linked_dev_list_idx() == 1)
    {
        mmi_frm_group_close(GRP_ID_BTNOTIFICATION_APP);
    }
    #endif  //SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    
    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_BTNOTIFICATION_APP, SCR_ID_BTNOTIFICATION_DEV_LIST);

    if (guiBuffer != NULL)
    {
        list_menu_category_history *hist = (list_menu_category_history*) guiBuffer;
        g_mmi_bt_notification_cntx_p->current_dev = hist->highlighted_item;
    }
    
    /* register highligh handler */
    RegisterHighlightHandler(mmi_bt_notification_show_dev_list_highlight_hdlr);
    

    #ifdef __MMI_BT_DIALER_SUPPORT__
    wgui_set_menu_empty_string_by_id(STR_GLOBAL_EMPTY);
    #endif
    
    #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
    wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON);
    #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
    
    wgui_cat1032_show(
        get_string(STR_ID_BTNOTIFICATION_APPLICATION_APP_NAME),
        NULL,
        get_string(STR_GLOBAL_OK),
        get_image(IMG_GLOBAL_OK),
        get_string(STR_GLOBAL_BACK),
        get_image(IMG_GLOBAL_BACK),
        total,
        mmi_bt_notification_dev_list_get_item_async,
        NULL,
        g_mmi_bt_notification_cntx_p->current_dev,
        0,    
        IMG_GLOBAL_L1, /* to calculate the coordinate offset of string */
        0,
        guiBuffer,
        &cat_err);

    #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
    wgui_restore_list_menu_slim_style();
    #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__

    if (total > 0)
    {
        /* register LSK, RSK hanlders */
        #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
        SetLeftSoftkeyFunction(mmi_bt_notification_show_msg_list_from_dev_list, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_bt_notification_show_msg_list_from_dev_list, KEY_EVENT_UP);
        #else  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
        SetLeftSoftkeyFunction(mmi_bt_notification_main_show_entry_from_dev_list, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_bt_notification_main_show_entry_from_dev_list, KEY_EVENT_UP);
        #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
    }
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);  
}


static mmi_ret mmi_bt_notification_launch_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, evt->evt_id, 3);
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            mmi_bt_notification_show_dev_list();
            break;

        case EVT_ID_SCRN_GOBACK:
            break;

        case EVT_ID_GROUP_DEINIT:
            g_mmi_bt_notification_cntx_p->current_dev = 0;
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


void mmi_bt_notification_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_notification_cntx_p->launch_from_popup)
    {
        U8 i = 0;
        U32 device_num = srv_bt_cm_get_linked_dev_list_idx();
        const srv_bt_cm_dev_struct* dev_p = NULL;

        //correct the index, cause the bt addr is form event in popup
        for (i = 0; i < device_num; i++)
        {
            dev_p = srv_bt_cm_get_linked_dev_info(i);
            if (g_mmi_bt_notification_cntx_p->popup_dev_addr.lap == dev_p->bd_addr.lap &&
                g_mmi_bt_notification_cntx_p->popup_dev_addr.uap == dev_p->bd_addr.uap &&
                g_mmi_bt_notification_cntx_p->popup_dev_addr.nap == dev_p->bd_addr.nap)
            {
                g_mmi_bt_notification_cntx_p->current_dev = i;
            }
        }
        //memset(g_mmi_bt_notification_cntx_p->popup_dev_addr, 0, sizeof(srv_bt_cm_bt_addr));
        mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MAIN);
        mmi_bt_notification_main_show_entry(GRP_ID_ROOT);
    }
    else
    {
        mmi_frm_group_create_ex(GRP_ID_ROOT,
            GRP_ID_BTNOTIFICATION_APP,
            mmi_bt_notification_launch_proc,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
        
        if (srv_bt_cm_get_linked_dev_list_idx() == 1)
        {//direct enter list or main category when it is just one device linked
            #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
            mmi_bt_notification_show_msg_list(GRP_ID_BTNOTIFICATION_APP);
            #else  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
            mmi_bt_notification_main_show_entry(GRP_ID_BTNOTIFICATION_APP);
            #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
        }
        else
        {
            mmi_frm_scrn_create(GRP_ID_BTNOTIFICATION_APP, 
                SCR_ID_BTNOTIFICATION_DEV_LIST, 
                mmi_bt_notification_launch_proc,
                NULL);
        }
    }
    g_mmi_bt_notification_cntx_p->launch_from_popup = MMI_FALSE;
}


static void mmi_bt_notification_menu_cui_entry_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(cui_menu_is_menu_event(menu_evt->evt_id))
    {
        wgui_inputs_options_menu_handler((mmi_event_struct*)menu_evt, GRP_ID_BTNOTIFICATION_EDIT);
    }
}


static void mmi_bt_notification_entry_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 process_image_id; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (mmi_frm_scrn_enter(
            GRP_ID_BTNOTIFICATION_EDIT,
            SCR_ID_BTNOTIFICATION_PROCESSING,
            NULL,
            mmi_bt_notification_entry_processing,
            MMI_FRM_FULL_SCRN))
    {
        process_image_id = mmi_get_event_based_image(MMI_EVENT_PROGRESS);
    #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
        mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
    #endif

        /*do not set title and title icon, otherwise processing screen will be a full screen*/
        ShowCategory8Screen(
            0,
            0,
            0,
            0,
            g_mmi_bt_notification_cntx_p->process_body_StrId,
            0,
            g_mmi_bt_notification_cntx_p->process_rsk_StrId,
            process_image_id,
            NULL);


        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);
    }
}


static void mmi_bt_notification_pre_entry_processing(U16 bodyStrId, U16 rskStrId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_notification_cntx_p->process_body_StrId = bodyStrId;
    g_mmi_bt_notification_cntx_p->process_rsk_StrId = rskStrId;
}


static mmi_ret mmi_bt_notification_editor_opt_select_hdlr(mmi_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *cui_menu_evt = (cui_menu_event_struct*)menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cui_menu_evt->highlighted_menu_id)
    {
		case MENU_ID_BTNOTIFICATION_EDITOR_SEND:
        {	
            MMI_BOOL result;
            
            mmi_bt_notification_pre_entry_processing(STR_GLOBAL_SENDING, NULL);
			result = srv_bt_noti_data_reply_remote_sms(&g_mmi_bt_notification_cntx_p->current_dev_addr,
                (WCHAR *)g_mmi_bt_notification_cntx_p->option_struct->send_number, 
                (WCHAR *)g_mmi_bt_notification_cntx_p->option_struct->content);
            mmi_frm_group_close(GRP_ID_BTNOTIFICATION_EDIT);
            if (result)
            {
                mmi_display_popup((UI_string_type)GetString(STR_GLOBAL_SENT), MMI_EVENT_SUCCESS);
            }
            else
            {
                mmi_display_popup((UI_string_type)GetString(STR_GLOBAL_FAILED), MMI_EVENT_FAILURE);
            }
            break;
        }
    }
    if(cui_menu_is_menu_event(menu_evt->evt_id))
    {
        wgui_inputs_options_menu_handler((mmi_event_struct*)menu_evt, GRP_ID_BTNOTIFICATION_EDIT);
    }
    return MMI_RET_OK;
}


static mmi_ret mmi_bt_notification_send_sms_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
	cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, evt->evt_id, 4);
	switch (menu_evt->evt_id)
	{
		case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            mmi_bt_notification_menu_cui_entry_hdlr(evt);
            break;
        }
		case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            mmi_bt_notification_editor_opt_select_hdlr(evt);
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_evt->sender_id);
            break;
        }
    }
    return MMI_RET_OK;
}


static void mmi_bt_notification_sms_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_bt_notification_pre_entry_processing(STR_GLOBAL_SENDING, NULL);
	result = srv_bt_noti_data_reply_remote_sms(&g_mmi_bt_notification_cntx_p->current_dev_addr,
        (WCHAR *)g_mmi_bt_notification_cntx_p->option_struct->send_number, 
        (WCHAR *)g_mmi_bt_notification_cntx_p->option_struct->content);
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_EDIT);
    if (result)
    {
        mmi_display_popup((UI_string_type)GetString(STR_GLOBAL_SENT), MMI_EVENT_SUCCESS);
    }
    else
    {
        mmi_display_popup((UI_string_type)GetString(STR_GLOBAL_FAILED), MMI_EVENT_FAILURE);
    }
}


static void mmi_bt_notification_entry_eitor_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_gid = cui_menu_create(
                    GRP_ID_BTNOTIFICATION_EDIT,
                    CUI_MENU_SRC_TYPE_RESOURCE,
                    CUI_MENU_TYPE_OPTION,
                    MENU_ID_BTNOTIFICATION_EDITOR_OPT,
                    MMI_FALSE,
                    NULL);

    cui_menu_set_default_title_image_by_id(menu_cui_gid, IMG_SMS_ENTRY_SCRN_CAPTION);

    cui_menu_run(menu_cui_gid);
}


static void mmi_bt_notification_popup_launch_app()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MAIN);
    g_mmi_bt_notification_cntx_p->launch_from_popup = MMI_TRUE;
    mmi_bt_notification_launch();
}


static void mmi_bt_notification_popup_view()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_POPUP);
    mmi_bt_notification_popup_launch_app();
}


static void mmi_bt_notification_popup_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;    

    srv_bt_noti_data_msg_node_struct * data_node;
    applib_time_struct create_time;
    WCHAR  time[20];
    WCHAR* timestamp_buffer;
    WCHAR* sms_title_buffer;
    U32 timestamp; 
    WCHAR* text_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    memset(&g_mmi_bt_notification_cntx_p->node, 0, sizeof(srv_bt_noti_data_msg_node_struct));
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, g_mmi_bt_notification_cntx_p->current_dev, g_mmi_bt_notification_cntx_p->popup_dev_addr.lap, g_mmi_bt_notification_cntx_p->popup_dev_addr.uap, g_mmi_bt_notification_cntx_p->popup_dev_addr.nap, 1);
    
    if(!srv_bt_noti_data_get_msg_info_ref(&g_mmi_bt_notification_cntx_p->popup_dev_addr, 0, &g_mmi_bt_notification_cntx_p->node))
    {
        mmi_frm_group_close(GRP_ID_BTNOTIFICATION_POPUP);
        return;
    }
    
    data_node = &g_mmi_bt_notification_cntx_p->node;        
    text_buffer = (WCHAR*)&g_mmi_bt_notification_cntx_p->category_text_buffer;
    memset(text_buffer, 0, sizeof(WCHAR) * (BT_NOTIFY_CONTENT_LENTH + BT_NOTIFY_TICKER_TEXT_LENTH + 2));
    if (data_node->content[0] != 0)
    {
        mmi_ucs2cat((PS8) text_buffer, (const PS8) data_node->content);          
    }
    mmi_ucs2cat((PS8) text_buffer, (const PS8) data_node->ticker_text); 

    //timestamp
    timestamp_buffer = OslMalloc(sizeof(WCHAR) * 60);
    memset(timestamp_buffer, 0, sizeof(WCHAR) * 60);
    timestamp = applib_dt_sec_utc_to_local(data_node->timestamp); 
    applib_dt_utc_sec_2_mytime(timestamp, &create_time, MMI_FALSE); 
    date_string((MYTIME*) & create_time, (UI_string_type)time, DT_IDLE_SCREEN);
    mmi_ucs2cat((PS8) timestamp_buffer, (const PS8) time);
    mmi_ucs2cat((PS8) timestamp_buffer, (const PS8) (L" "));
    time_string((MYTIME*) & create_time, (UI_string_type)time, DT_IDLE_SCREEN);
    mmi_ucs2cat((PS8)timestamp_buffer, (const PS8)time);

    //show category
    if (srv_bt_notify_subtype_sms == data_node->header.subtype)
    {
        sms_title_buffer = OslMalloc(sizeof(WCHAR) * (100)); 
        memset(sms_title_buffer, 0, sizeof(WCHAR) * (100));    
        sms_title_buffer = mmi_wcscpy(sms_title_buffer, (WCHAR*)GetString(STR_ID_BTNOTIFICATION_APPLICATION_FROM));  
        mmi_ucs2cat((PS8)sms_title_buffer, (const PS8)(L" "));   
        mmi_ucs2cat((PS8)sms_title_buffer, (const PS8)data_node->sender);
        #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
        wgui_showcategory6333_screen(
            (UI_string_type)GetString(STR_ID_BTNOTIFICATION_APPLICATION_SMS),
            (UI_string_type)GetString(STR_GLOBAL_VIEW),
            (UI_string_type)GetString(STR_GLOBAL_CANCEL), 
            (UI_string_type)text_buffer,
            (UI_string_type)timestamp_buffer);
        #else  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
        wgui_showcategory632_screen(
            (UI_string_type)GetString(STR_ID_BTNOTIFICATION_APPLICATION_SMS),
            (UI_string_type)sms_title_buffer,
            (UI_string_type)GetString(STR_GLOBAL_VIEW),
            (UI_string_type)GetString(STR_GLOBAL_CANCEL),
            (UI_string_type)text_buffer,
            (UI_string_type)timestamp_buffer);
        #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
        OslMfree(sms_title_buffer);
    }
    else
    {
        #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
        wgui_showcategory6333_screen(
            (UI_string_type)data_node->sender,
            (UI_string_type)GetString(STR_GLOBAL_VIEW),
            (UI_string_type)GetString(STR_GLOBAL_CANCEL), 
            (UI_string_type)text_buffer,
            (UI_string_type)timestamp_buffer);
        #else  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
        if (data_node->title != NULL)
        {
            wgui_showcategory632_screen(
                (UI_string_type)data_node->sender,
                (UI_string_type)data_node->title,
                (UI_string_type)GetString(STR_GLOBAL_VIEW),
                (UI_string_type)GetString(STR_GLOBAL_CANCEL),
                (UI_string_type)text_buffer,
                (UI_string_type)timestamp_buffer);
        }
        else
        {
            wgui_showcategory632_screen(
                (UI_string_type)data_node->sender,
                 NULL,
                (UI_string_type)GetString(STR_GLOBAL_VIEW),
                (UI_string_type)GetString(STR_GLOBAL_CANCEL),            
                (UI_string_type)text_buffer,
                (UI_string_type)timestamp_buffer);
        }
        #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
    }
    
    OslMfree(timestamp_buffer);
    show_softkey_background();
    show_left_softkey();
    show_right_softkey();
    SetLeftSoftkeyFunction((FuncPtr)mmi_bt_notification_popup_view, KEY_EVENT_UP);
    SetRightSoftkeyFunction((FuncPtr)mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction((FuncPtr)mmi_bt_notification_popup_view, KEY_EVENT_UP);
}


static mmi_ret mmi_bt_notification_popup_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, evt->evt_id, 5);
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            break;
        case EVT_ID_SCRN_ACTIVE:
            mmi_bt_notification_popup_show();
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


static MMI_BOOL mmi_bt_notification_popup_entry(mmi_scenario_id id, void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(
            GRP_ID_ROOT,
            GRP_ID_BTNOTIFICATION_POPUP,
            mmi_bt_notification_popup_proc,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_create(GRP_ID_BTNOTIFICATION_POPUP, 
        SCR_ID_BTNOTIFICATION_POPUP, 
        mmi_bt_notification_popup_proc,
        NULL);

    return MMI_TRUE;
}


static mmi_ret mmi_bt_notification_editor_scrn_leave_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, param->evt_id, 6);
    switch (param->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
            g_mmi_bt_notification_cntx_p->is_in_composer = MMI_FALSE;
            if (g_mmi_bt_notification_cntx_p->need_popup)
            {
                mmi_frm_group_close(GRP_ID_BTNOTIFICATION_POPUP);
                
                mmi_frm_nmgr_notify_by_app(
                    MMI_SCENARIO_ID_BT_NOTIFY,
                    MMI_EVENT_BT_NOTIFY,
                    mmi_bt_notification_popup_entry,
                    &g_mmi_bt_notification_cntx_p->refresh_cntx);
                
                g_mmi_bt_notification_cntx_p->need_popup = MMI_FALSE;
            }
            break;
        }

        default:
            break;
    }

    return MMI_RET_OK; 
}


static void mmi_bt_notification_entry_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(GRP_ID_BTNOTIFICATION_EDIT, 
        SCR_ID_BTNOTIFICATION_EDIT, 
        NULL, 
        mmi_bt_notification_entry_editor, 
        MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_BTNOTIFICATION_EDIT, SCR_ID_BTNOTIFICATION_EDIT);

        wgui_uce_initialize_editor(
            (U8 *)(g_mmi_bt_notification_cntx_p->option_struct)->content,
            (MMI_BT_NOTIFICATION_SMS_MAX_NUMBER / ENCODING_LENGTH),
            1,
            1,
            (U8)(MMI_BT_NOTIFICATION_SMS_MAX_NUMBER / ENCODING_LENGTH - 1),
            mmi_sms_editor_get_message_size_callback,
            mmi_sms_editor_text_change_callback,
            mmi_sms_editor_display_type_callback,
            mmi_sms_editor_remaining_char_count,
            mmi_sms_editor_segment_count,
            NULL,
            NULL);
        
        mmi_sms_update_editor_info((CHAR*)(g_mmi_bt_notification_cntx_p->option_struct)->content);
        ShowCategory280Screen(
            STR_ID_SMS_BT_MESSAGE_MENUENTRY,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            STR_GLOBAL_OPTIONS,
            IMG_SMS_COMMON_NOIMAGE,
            STR_GLOBAL_BACK,
            IMG_SMS_COMMON_NOIMAGE,
            WGUI_UCE_MSG_TYPE_SMS,
            IMM_INPUT_TYPE_SENTENCE,
            NULL,
            NULL,
            gui_buffer);
        
        SetCategory280RightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

        SetLeftSoftkeyFunction(mmi_bt_notification_entry_eitor_options, KEY_EVENT_UP);

        SetCenterSoftkeyFunction(mmi_bt_notification_sms_send, KEY_EVENT_UP);
              
        mmi_frm_scrn_set_leave_proc(
            GRP_ID_BTNOTIFICATION_EDIT,
            SCR_ID_BTNOTIFICATION_EDIT,
            mmi_bt_notification_editor_scrn_leave_proc);
    }
}


static void mmi_bt_notification_send_sms(WCHAR *phone_number, WCHAR *content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((g_mmi_bt_notification_cntx_p->option_struct)->send_number, 0, BT_NOTIFY_NUMBER_LENTH * ENCODING_LENGTH + 1);
    memset((g_mmi_bt_notification_cntx_p->option_struct)->content, 0, BT_NOTIFY_SEND_SMS_CONTENT_LENTH * ENCODING_LENGTH + 1);
    if (phone_number != NULL)
    {
        memcpy((g_mmi_bt_notification_cntx_p->option_struct)->send_number, 
            phone_number, 
            mmi_wcslen(phone_number)*ENCODING_LENGTH + 1);
    }
    if (content != NULL)
    {
        memcpy((g_mmi_bt_notification_cntx_p->option_struct)->content, 
            content, 
            mmi_wcslen(content)*ENCODING_LENGTH + 1);
    }
    
    mmi_frm_group_create_ex(
                    GRP_ID_ROOT,
                    GRP_ID_BTNOTIFICATION_EDIT,
                    mmi_bt_notification_send_sms_proc,
                    NULL,
                    MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_bt_notification_entry_editor();
    g_mmi_bt_notification_cntx_p->is_in_composer = MMI_TRUE;

}


static void mmi_bt_notification_main_option_reply(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_notification_cntx_p->total > 0 && g_mmi_bt_notification_cntx_p->id < g_mmi_bt_notification_cntx_p->total)
    {
        g_mmi_bt_notification_cntx_p->option_struct->id = g_mmi_bt_notification_cntx_p->id;
        g_mmi_bt_notification_cntx_p->option_struct->option_enum = MMI_BT_NOTIFICATION_OPTION_REPLY;
        mmi_bt_notification_send_sms(g_mmi_bt_notification_cntx_p->node.send_number, NULL);
    }
}


static void mmi_bt_notification_main_option_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_notification_cntx_p->total > 0 && g_mmi_bt_notification_cntx_p->id < g_mmi_bt_notification_cntx_p->total)
    {
        g_mmi_bt_notification_cntx_p->option_struct->id = g_mmi_bt_notification_cntx_p->id;
        g_mmi_bt_notification_cntx_p->option_struct->option_enum = MMI_BT_NOTIFICATION_OPTION_FORWARD;
    }
}


static void mmi_bt_notification_main_option_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_notification_cntx_p->total > 0 && g_mmi_bt_notification_cntx_p->id < g_mmi_bt_notification_cntx_p->total)
    {
        g_mmi_bt_notification_cntx_p->option_struct->id = g_mmi_bt_notification_cntx_p->id;
        g_mmi_bt_notification_cntx_p->option_struct->option_enum = MMI_BT_NOTIFICATION_OPTION_CALL;
        

        if ((g_mmi_bt_notification_cntx_p->node.send_number[0] != '\0') || (g_mmi_bt_notification_cntx_p->node.send_number[1] != '\0'))
        {
            mmi_ucm_init_call_para(&param);
        
            param.dial_type = SRV_UCM_CALL_TYPE_ALL;
            param.ucs2_num_uri = (U16 *)g_mmi_bt_notification_cntx_p->node.send_number;
        
            mmi_ucm_call_launch(0, &param);
        }
        else
        {
            mmi_display_popup(
                (UI_string_type)GetString(STR_GLOBAL_FAILED),
                MMI_EVENT_FAILURE);
        }
    }
}


static void mmi_bt_notification_block(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    result = srv_bt_noti_data_block_remote_notification(&g_mmi_bt_notification_cntx_p->current_dev_addr, g_mmi_bt_notification_cntx_p->node.app_id);
    if (result)
    {
        mmi_display_popup(
            (UI_string_type)GetString(STR_ID_BTNOTIFICATION_POPUP_BLOCKED),
            MMI_EVENT_SUCCESS);
    }
    else
    {
        mmi_display_popup(
            (UI_string_type)GetString(STR_GLOBAL_FAILED),
            MMI_EVENT_FAILURE);
    }
    
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_BLOCK);
}


static void mmi_bt_notification_block_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    mmi_id str_id;
    WCHAR* pop_str, *str;
   
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    str_id = STR_ID_BTNOTIFICATION_APPLICATION_BLOCK_NOTIFY;
    str = (WCHAR *)GetString(str_id);
    pop_str = (WCHAR *)OslMalloc((mmi_wcslen(str) + BT_NOTIFY_SENDER_LENTH + 2 + 1) * ENCODING_LENGTH);// 2 is '\n' and '?'
    memcpy (pop_str, str, (mmi_wcslen(str) + 1) * ENCODING_LENGTH);
    mmi_wcscat(pop_str, L"\n");
    mmi_wcscat(pop_str, g_mmi_bt_notification_cntx_p->node.sender);
    mmi_wcscat(pop_str, L"?");
    #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
    wgui_showcategory6333_screen(
        NULL,
        (UI_string_type)GetString(STR_GLOBAL_YES),
        (UI_string_type)GetString(STR_GLOBAL_NO),
        pop_str,
        NULL);
    #else  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__
    ShowCategory165Screen(
        STR_GLOBAL_YES,
        0,
        STR_GLOBAL_NO,
        0,
        pop_str,
        IMG_GLOBAL_L1,
        gui_buffer);
    #endif  //__MMI_BT_NOTIFICATION_FOR_WEARABLE__

    SetLeftSoftkeyFunction(mmi_bt_notification_block, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_bt_notification_block, KEY_EVENT_UP);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    OslMfree(pop_str);
}


static mmi_ret mmi_bt_notification_block_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, evt->evt_id, 7);
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            mmi_bt_notification_block_show();
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


static void mmi_bt_notification_main_option_block(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_notification_cntx_p->total > 0 && g_mmi_bt_notification_cntx_p->id < g_mmi_bt_notification_cntx_p->total)
    {
        g_mmi_bt_notification_cntx_p->option_struct->id = g_mmi_bt_notification_cntx_p->id;
        g_mmi_bt_notification_cntx_p->option_struct->option_enum = MMI_BT_NOTIFICATION_OPTION_FORWARD;

        mmi_frm_group_create_ex(
                        GRP_ID_ROOT,
                        GRP_ID_BTNOTIFICATION_BLOCK,
                        mmi_bt_notification_block_proc,
                        NULL,
                        MMI_FRM_NODE_SMART_CLOSE_FLAG);
        
        mmi_frm_scrn_create(GRP_ID_BTNOTIFICATION_BLOCK, 
            SCR_ID_BTNOTIFICATION_BLOCK, 
            mmi_bt_notification_block_proc,
            NULL);
    }
}


static void mmi_bt_notification_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_notification_cntx_p->total > 0 && g_mmi_bt_notification_cntx_p->id < g_mmi_bt_notification_cntx_p->total)
    {
        srv_bt_noti_data_delete_msg(&g_mmi_bt_notification_cntx_p->current_dev_addr, g_mmi_bt_notification_cntx_p->id);         
    }
    
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_DELETE);
}


static void mmi_bt_notification_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_bt_noti_data_delete_all(&g_mmi_bt_notification_cntx_p->current_dev_addr);
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_DELETE);
}


static void mmi_bt_notification_delete_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    mmi_id str_id;

    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    if (MMI_BT_NOTIFICATION_OPTION_DELETE == g_mmi_bt_notification_cntx_p->option_struct->option_enum)
        str_id = STR_ID_BTNOTIFICATION_APPLICATION_DELETE_MATRX;
    else
        str_id = STR_ID_BTNOTIFICATION_APPLICATION_EMPTY_MATRX;

    ShowCategory165Screen(
        STR_GLOBAL_YES,
        0,
        STR_GLOBAL_NO,
        0,
        (UI_string_type) GetString(str_id),
        IMG_GLOBAL_L1,
        gui_buffer);
    

    if (MMI_BT_NOTIFICATION_OPTION_DELETE == g_mmi_bt_notification_cntx_p->option_struct->option_enum)
    {
        SetLeftSoftkeyFunction(mmi_bt_notification_delete, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_bt_notification_delete, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_bt_notification_empty, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_bt_notification_empty, KEY_EVENT_UP);
    }
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


static mmi_ret mmi_bt_notification_delete_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, evt->evt_id, 8);
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            mmi_bt_notification_delete_show();
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


static void mmi_bt_notification_main_option_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_notification_cntx_p->total > 0 && g_mmi_bt_notification_cntx_p->id < g_mmi_bt_notification_cntx_p->total)
    {
        g_mmi_bt_notification_cntx_p->scrn_type = MMI_BT_NOTIFICATION_SCRN_DELETE;
        g_mmi_bt_notification_cntx_p->option_struct->id = g_mmi_bt_notification_cntx_p->id;
        g_mmi_bt_notification_cntx_p->option_struct->option_enum = MMI_BT_NOTIFICATION_OPTION_DELETE;
        
        mmi_frm_group_create_ex(
                        GRP_ID_ROOT,
                        GRP_ID_BTNOTIFICATION_DELETE,
                        mmi_bt_notification_delete_proc,
                        NULL,
                        MMI_FRM_NODE_SMART_CLOSE_FLAG);

        mmi_frm_scrn_create(GRP_ID_BTNOTIFICATION_DELETE, 
            SCR_ID_BTNOTIFICATION_MAIN_DELETE, 
            mmi_bt_notification_delete_proc,
            NULL);
    }
}


static void mmi_bt_notification_main_option_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_notification_cntx_p->total > 0 && g_mmi_bt_notification_cntx_p->id < g_mmi_bt_notification_cntx_p->total)
    {
        g_mmi_bt_notification_cntx_p->scrn_type = MMI_BT_NOTIFICATION_SCRN_DELETE;
        g_mmi_bt_notification_cntx_p->option_struct->id = g_mmi_bt_notification_cntx_p->id;
        g_mmi_bt_notification_cntx_p->option_struct->option_enum = MMI_BT_NOTIFICATION_OPTION_EMPTY;
        mmi_frm_group_create_ex(
                        GRP_ID_ROOT,
                        GRP_ID_BTNOTIFICATION_DELETE,
                        mmi_bt_notification_delete_proc,
                        NULL,
                        MMI_FRM_NODE_SMART_CLOSE_FLAG);

        mmi_frm_scrn_create(GRP_ID_BTNOTIFICATION_DELETE, 
            SCR_ID_BTNOTIFICATION_MAIN_DELETE, 
            mmi_bt_notification_delete_proc,
            NULL);
    }
}


static mmi_ret mmi_bt_notification_main_option_select(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                 */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct *)evt;
    
    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_ID_BTNOTIFICATION_APPLICATION_OPT_REPLY:
            mmi_bt_notification_main_option_reply();
            break;
            
        case MENU_ID_BTNOTIFICATION_APPLICATION_OPT_FORWARD:
            mmi_bt_notification_main_option_forward();
            break;
            
        case MENU_ID_BTNOTIFICATION_APPLICATION_OPT_CALL:
            mmi_bt_notification_main_option_call();
            break;

        case MENU_ID_BTNOTIFICATION_APPLICATION_OPT_BLOCK:
            mmi_bt_notification_main_option_block();
            break;
            
        case MENU_ID_BTNOTIFICATION_APPLICATION_OPT_DELETE:
            mmi_bt_notification_main_option_delete();
            break;
            
        case MENU_ID_BTNOTIFICATION_APPLICATION_OPT_EMPTY:
            mmi_bt_notification_main_option_empty();
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


static mmi_ret mmi_bt_notification_main_option_entry(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                 */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct *)evt;

    if (srv_bt_notify_subtype_sms != g_mmi_bt_notification_cntx_p->node.header.subtype)
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_BTNOTIFICATION_APPLICATION_OPT_REPLY, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_BTNOTIFICATION_APPLICATION_OPT_FORWARD, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_BTNOTIFICATION_APPLICATION_OPT_CALL, MMI_TRUE);
    }
    else
    {
        if (!(g_mmi_bt_notification_cntx_p->option_struct)->is_sender_valid)
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_BTNOTIFICATION_APPLICATION_OPT_REPLY, MMI_TRUE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_BTNOTIFICATION_APPLICATION_OPT_CALL, MMI_TRUE);
        }
            
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_BTNOTIFICATION_APPLICATION_OPT_BLOCK, MMI_TRUE);
    }

    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_BTNOTIFICATION_APPLICATION_OPT_FORWARD, MMI_TRUE);    
    return MMI_RET_OK;
}


static mmi_ret mmi_bt_notification_main_option_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;
    MMI_ID ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                 */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, evt->evt_id, 9);
    menu_evt = (cui_menu_event_struct *)evt;
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            ret = mmi_bt_notification_main_option_entry(evt);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            ret = mmi_bt_notification_main_option_select(evt);
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
    return ret;
}


static void mmi_bt_notification_main_show_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID opt_grp_id;
    MMI_ID option_menu_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                 */
    /*----------------------------------------------------------------*/
    opt_grp_id = mmi_frm_group_create(
                            GRP_ID_BTNOTIFICATION_MAIN, 
                            GRP_ID_AUTO_GEN, 
                            mmi_bt_notification_main_option_proc, 
                            NULL);
    mmi_frm_group_enter(opt_grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    option_menu_id = cui_menu_create(
                            opt_grp_id, 
                            CUI_MENU_SRC_TYPE_RESOURCE, 
                            CUI_MENU_TYPE_OPTION, 
                            MENU_ID_BTNOTIFICATION_APPLICATION_OPT, 
                            MMI_FALSE, 
                            NULL);    
    cui_menu_set_default_title(option_menu_id,
        (UI_string_type)GetString(STR_GLOBAL_OPTIONS),
        NULL
        );
    cui_menu_run(option_menu_id);
}


static void mmi_bt_notification_main_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_notification_cntx_p->total = srv_bt_noti_data_get_msg_num(&g_mmi_bt_notification_cntx_p->current_dev_addr);
    if (g_mmi_bt_notification_cntx_p->total == 0 || g_mmi_bt_notification_cntx_p->id >= g_mmi_bt_notification_cntx_p->total)
    {
        return;
    }
    
    if (srv_bt_notify_subtype_sms == g_mmi_bt_notification_cntx_p->node.header.subtype)
    {
        if ((g_mmi_bt_notification_cntx_p->option_struct)->is_sender_valid)
        {
            mmi_bt_notification_main_option_reply();
        }
        else
        {
            mmi_bt_notification_main_option_delete();
        }
    }
    else
    {
        mmi_bt_notification_main_option_delete();
    }
}


static void mmi_bt_notification_main_left_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_notification_cntx_p->id > 0)
        g_mmi_bt_notification_cntx_p->id--;
    else
        g_mmi_bt_notification_cntx_p->id = g_mmi_bt_notification_cntx_p->total - 1;
    
    mmi_bt_notification_main_show_category();
}


static void mmi_bt_notification_main_right_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_notification_cntx_p->id < g_mmi_bt_notification_cntx_p->total - 1)
        g_mmi_bt_notification_cntx_p->id++;
    else
        g_mmi_bt_notification_cntx_p->id = 0;
    
    mmi_bt_notification_main_show_category();
}



static void mmi_bt_notification_main_show_category(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    srv_bt_noti_data_msg_node_struct * node_data;
    U8* icon_buffer;  //type
    WCHAR* text_buffer;   //txt
    applib_time_struct create_time;
    WCHAR  time[40];
    #if defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) && defined(__MMI_TOUCH_SCREEN__)
    WCHAR* time_buffer;
    #else  //defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) && defined(__MMI_TOUCH_SCREEN__)
    WCHAR* number_buffer;  //"9/10"
    #endif  //defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) && defined(__MMI_TOUCH_SCREEN__)
    U32 timestamp;
	#ifdef SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    WCHAR device_name[SRV_BT_CM_BD_UCS2_NAME_LEN] = L"BT Device";
	#else  //SRV_BT_NOTIFY_TEST_WITHOUT_SPP
    WCHAR device_name[SRV_BT_CM_BD_UCS2_NAME_LEN] = {0};
	#endif  //SRV_BT_NOTIFY_TEST_WITHOUT_SPP

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, g_mmi_bt_notification_cntx_p->current_dev, g_mmi_bt_notification_cntx_p->current_dev_addr.lap, g_mmi_bt_notification_cntx_p->current_dev_addr.uap, g_mmi_bt_notification_cntx_p->current_dev_addr.nap, 2);
    
    #ifndef SRV_BT_NOTIFY_TEST_WITHOUT_SPP
	srv_bt_cm_get_dev_ucs2_name(
        &(g_mmi_bt_notification_cntx_p->current_dev_addr),
        SRV_BT_CM_BD_UCS2_NAME_LEN,
        device_name);

    if (MMI_FALSE == srv_bt_noti_check_connection())
    {
        mmi_bt_notification_main_show_disconnect((WCHAR*)GetString(STR_ID_BTNOTIFICATION_APPLICATION_APP_NAME));
        return;
    }
    else if (MMI_FALSE == srv_bt_noti_check_connection_ext(&g_mmi_bt_notification_cntx_p->current_dev_addr))
    {
        mmi_bt_notification_main_show_disconnect(device_name);
        return;
    }
    #endif  //SRV_BT_NOTIFY_TEST_WITHOUT_SPP

    g_mmi_bt_notification_cntx_p->total = srv_bt_noti_data_get_msg_num(&g_mmi_bt_notification_cntx_p->current_dev_addr);

    if (g_mmi_bt_notification_cntx_p->total == 0)
    {
        g_mmi_bt_notification_cntx_p->id = 0;
        mmi_bt_notification_main_show_empty(device_name);
        return;
    }
    
    clear_screen();
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    if (g_mmi_bt_notification_cntx_p->id >= g_mmi_bt_notification_cntx_p->total)
    {
        g_mmi_bt_notification_cntx_p->id = (g_mmi_bt_notification_cntx_p->total - 1);
    }
    memset(&g_mmi_bt_notification_cntx_p->node, 0, sizeof(srv_bt_noti_data_msg_node_struct));
    srv_bt_noti_data_get_msg_info_ref(&g_mmi_bt_notification_cntx_p->current_dev_addr, g_mmi_bt_notification_cntx_p->id, &g_mmi_bt_notification_cntx_p->node);

    #if !defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) || !defined(__MMI_TOUCH_SCREEN__)
    //number
    number_buffer = OslMalloc(sizeof(WCHAR) * 10);
    kal_wsprintf(number_buffer, "%d/%d", 
        g_mmi_bt_notification_cntx_p->id + 1, 
        g_mmi_bt_notification_cntx_p->total);
    set_cat145_show_number((U8*)number_buffer);
    #endif  //!defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) || !defined(__MMI_TOUCH_SCREEN__)
    

    node_data = &g_mmi_bt_notification_cntx_p->node;
    MMI_ASSERT(node_data);

    //image
    if (srv_bt_notify_subtype_sms != node_data->header.subtype)
    {
        set_cat145_show_image_file_path((U8*)node_data->icon_file_path);
        //icon
        icon_buffer = (U8*)node_data->sender;
    }
    else
    {
        set_cat145_show_image_finish();
        icon_buffer = (U8*)GetString(STR_ID_BTNOTIFICATION_APPLICATION_SMS);
    }

    //title + context + ticker_text + time
    text_buffer = (WCHAR*)&g_mmi_bt_notification_cntx_p->category_text_buffer;
    memset(text_buffer, 0, sizeof(WCHAR) * (BT_NOTIFY_CONTENT_LENTH + 100));
    if (srv_bt_notify_subtype_sms != node_data->header.subtype)
    {
        #if !defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__)
        if (node_data->title[0] != 0)
        {
            text_buffer = mmi_wcscpy(text_buffer, (PU16)node_data->title);
            mmi_ucs2cat((PS8) text_buffer, (const PS8) (L"\n"));
        }
        #endif  //!defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__)
        if (node_data->content[0] != 0)
        {
            mmi_ucs2cat((PS8) text_buffer, (const PS8) node_data->content);
            mmi_ucs2cat((PS8) text_buffer, (const PS8) (L"\n"));
        }          
        mmi_ucs2cat((PS8) text_buffer, (const PS8) node_data->ticker_text);
    }
    else
    {
        text_buffer = mmi_wcscpy(text_buffer, (PU16) (GetString(STR_ID_BTNOTIFICATION_APPLICATION_FROM)));   
        mmi_ucs2cat((PS8) text_buffer, (const PS8) (L" "));          
        mmi_ucs2cat((PS8) text_buffer, (const PS8) node_data->sender);    
        mmi_ucs2cat((PS8) text_buffer, (const PS8) (L"\n"));          
        mmi_ucs2cat((PS8) text_buffer, (const PS8) node_data->content);   
        mmi_ucs2cat((PS8) text_buffer, (const PS8) (L"\n"));             
        mmi_ucs2cat((PS8) text_buffer, (const PS8) node_data->ticker_text); 
    }
    mmi_ucs2cat((PS8) text_buffer, (const PS8) (L"\n"));
    timestamp = applib_dt_sec_utc_to_local(node_data->timestamp);
    applib_dt_utc_sec_2_mytime(timestamp, &create_time, MMI_FALSE);
    date_string((MYTIME*) & create_time, time, DT_IDLE_SCREEN);
    #if defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) && defined(__MMI_TOUCH_SCREEN__)
    time_buffer = OslMalloc(sizeof(WCHAR) * 100);
    mmi_ucs2cpy((PS8) time_buffer, (const PS8)time);   
    mmi_ucs2cat((PS8) time_buffer, (const PS8) (L" "));
    time_string((MYTIME*) & create_time, time, DT_IDLE_SCREEN);
    mmi_ucs2cat((PS8) time_buffer, (const PS8)time); 
    #else  //defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) && defined(__MMI_TOUCH_SCREEN__)
    mmi_ucs2cat((PS8) text_buffer, (const PS8)time);
    mmi_ucs2cat((PS8) text_buffer, (const PS8) (L" "));
    time_string((MYTIME*) & create_time, time, DT_IDLE_SCREEN);
    mmi_ucs2cat((PS8) text_buffer, (const PS8)time);
    #endif  //defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) && defined(__MMI_TOUCH_SCREEN__)
    
    //show category
    #if defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_BTcat145_footer_area_register_controlled_callback(mmi_bt_notification_main_option_block, 0);
    ShowBTNotiCategory145Screen_WEARABLE_DEVICE(
        (U8*)(node_data->title[0] == 0 ? NULL : node_data->title),
        NULL,
        STR_ID_BTNOTIFICATION_APPLICATION_OPTION_BLOCK,
        NULL,
        NULL,
        NULL,
        IMG_MESSAGE_UNREAD,
        (U8*)icon_buffer,
        (U8*)text_buffer,
        NULL,
        gui_buffer,
        (U8*)time_buffer);
    #else  //defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) && defined(__MMI_TOUCH_SCREEN__)
    ShowBTNotiCategory145Screen(
        (U8 *)device_name,
        0,
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        IMG_MESSAGE_UNREAD,
        (U8*)icon_buffer,
        (U8*)text_buffer,
        0,
        gui_buffer);
    #endif  //defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) && defined(__MMI_TOUCH_SCREEN__)

    g_mmi_bt_notification_cntx_p->option_struct->id = g_mmi_bt_notification_cntx_p->id;
    if ( g_mmi_bt_notification_cntx_p->node.header.subtype == srv_bt_notify_subtype_sms)
    {
        MMI_BOOL is_number_valid = MMI_FALSE;
        is_number_valid = srv_sms_btmapc_check_ucs2_number((char *)g_mmi_bt_notification_cntx_p->node.send_number);
        if (!is_number_valid || 
            ((g_mmi_bt_notification_cntx_p->node.send_number[0] == '\0') && 
            (g_mmi_bt_notification_cntx_p->node.send_number[1] == '\0')))
        {
            (g_mmi_bt_notification_cntx_p->option_struct)->is_sender_valid = MMI_FALSE;
        }
        else
        {
            (g_mmi_bt_notification_cntx_p->option_struct)->is_sender_valid = MMI_TRUE;
        }
    }

    SetLeftSoftkeyFunction(mmi_bt_notification_main_show_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_bt_notification_main_csk_hdlr, KEY_EVENT_UP);
    SetKeyHandler((FuncPtr)mmi_bt_notification_main_left_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_UP);
    SetKeyHandler((FuncPtr)mmi_bt_notification_main_right_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    #if defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) && defined(__MMI_TOUCH_SCREEN__)
    OslMfree(time_buffer);
    #else  //defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) && defined(__MMI_TOUCH_SCREEN__)
    OslMfree(number_buffer);
    #endif  //defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__) && defined(__MMI_TOUCH_SCREEN__)
}


static mmi_ret mmi_bt_notification_main_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, evt->evt_id, 10);
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            mmi_bt_notification_main_show_category();
            break;

        case EVT_ID_SCRN_GOBACK:
            break;

        case EVT_ID_SCRN_DEINIT:
            set_cat145_show_number_finish();
            break;

        case EVT_ID_GROUP_DEINIT:
            #if !defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__)
            g_mmi_bt_notification_cntx_p->id = 0;
            #endif  //!defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__)
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


static void mmi_bt_notification_main_show_entry(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    const srv_bt_cm_dev_struct* dev_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__)
    if (g_mmi_bt_notification_cntx_p->launch_from_popup)
    #endif  //defined(__MMI_BT_NOTIFICATION_FOR_WEARABLE__)
    {
        #if !defined(SRV_BT_NOTIFY_TEST_WITHOUT_SPP)
        dev_p = srv_bt_cm_get_linked_dev_info(g_mmi_bt_notification_cntx_p->current_dev);
        memcpy((void*)&g_mmi_bt_notification_cntx_p->current_dev_addr, (void*)&dev_p->bd_addr, sizeof(srv_bt_cm_bt_addr));
        #endif  //!defined(SRV_BT_NOTIFY_TEST_WITHOUT_SPP)
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, g_mmi_bt_notification_cntx_p->current_dev, g_mmi_bt_notification_cntx_p->current_dev_addr.lap, g_mmi_bt_notification_cntx_p->current_dev_addr.uap, g_mmi_bt_notification_cntx_p->current_dev_addr.nap, 3);
    
    g_mmi_bt_notification_cntx_p->scrn_type = MMI_BT_NOTIFICATION_SCRN_MAIN;
    mmi_frm_group_create_ex(parent_id,
                            GRP_ID_BTNOTIFICATION_MAIN,
                            mmi_bt_notification_main_proc,
                            g_mmi_bt_notification_cntx_p,
                            MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_create(GRP_ID_BTNOTIFICATION_MAIN, 
        SCR_ID_BTNOTIFICATION_MAIN, 
        mmi_bt_notification_main_proc,
        g_mmi_bt_notification_cntx_p);
}


static void mmi_bt_notification_sync_time()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_noti_sync_event_struct *sync_time = &g_mmi_bt_notification_cntx_p->sync_time_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sync_time->call_back(&sync_time->bt_addr, sync_time->time, sync_time->time_zone, MMI_TRUE);
    
    g_mmi_bt_notification_cntx_p->synced = MMI_TRUE;

    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_SYNC_TIME);

    mmi_display_popup(
            (UI_string_type)GetString(STR_ID_BTNOTIFICATION_POPUP_SYNCED),
            MMI_EVENT_SUCCESS);
}


static void mmi_bt_notification_sync_time_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    ShowCategory165Screen(
        STR_GLOBAL_YES,
        0,
        STR_GLOBAL_NO,
        0,
        (UI_string_type)GetString(STR_ID_BTNOTIFICATION_POPUP_SYNC_TIME),
        IMG_GLOBAL_L1,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_bt_notification_sync_time, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_bt_notification_sync_time, KEY_EVENT_UP);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_END,KEY_EVENT_DOWN);
}


static mmi_ret mmi_bt_notification_sync_time_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, evt->evt_id, 11);
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            mmi_bt_notification_sync_time_show();
            break;
        case EVT_ID_GROUP_DEINIT:
            if (!g_mmi_bt_notification_cntx_p->synced)
            {
                srv_bt_noti_sync_event_struct *sync_time = &g_mmi_bt_notification_cntx_p->sync_time_cntx;
                sync_time->call_back(&sync_time->bt_addr, sync_time->time, sync_time->time_zone, MMI_FALSE);
                g_mmi_bt_notification_cntx_p->synced = MMI_TRUE;
            }
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


#endif /* __MMI_BT_NOTIFICATION__ */

#if (defined(__MMI_BT_NOTIFICATION__) || defined (__MMI_BT_NOTI_SRV__))

mmi_ret mmi_bt_notification_event_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_PROC, evt->evt_id, 12);
	#ifdef __MMI_BT_NOTIFICATION__
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MRE);
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_DELETE);
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_BLOCK);
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_EDIT);
    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_POPUP);
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_BT_NOTI_REFRESH:
        {
            srv_bt_noti_refresh_evt_struct* refresh_evt = (srv_bt_noti_refresh_evt_struct*)evt;
            memcpy((void*)&g_mmi_bt_notification_cntx_p->popup_dev_addr, (void*)&refresh_evt->bt_addr, sizeof(srv_bt_cm_bt_addr));
            MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_CURRENT_ADDRESS, g_mmi_bt_notification_cntx_p->current_dev, g_mmi_bt_notification_cntx_p->popup_dev_addr.lap, g_mmi_bt_notification_cntx_p->popup_dev_addr.uap, g_mmi_bt_notification_cntx_p->popup_dev_addr.nap, 4+refresh_evt->refresh_type);
            if (SRV_BT_NOTIFY_REFRESH_NEW != refresh_evt->refresh_type)
            {
                srv_bt_noti_sync_event_struct *sync_time = &g_mmi_bt_notification_cntx_p->sync_time_cntx;
                
                if (sync_time == NULL || (g_mmi_bt_notification_cntx_p->popup_dev_addr.lap == sync_time->bt_addr.lap &&
                        g_mmi_bt_notification_cntx_p->popup_dev_addr.uap == sync_time->bt_addr.uap &&
                        g_mmi_bt_notification_cntx_p->popup_dev_addr.nap == sync_time->bt_addr.nap))
                {//forbid to call sync while spp disconnect
                    g_mmi_bt_notification_cntx_p->synced = MMI_TRUE;
                    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_SYNC_TIME);
                }
                if (!srv_bt_noti_check_connection_ext(&g_mmi_bt_notification_cntx_p->popup_dev_addr) &&
                    (mmi_frm_group_get_active_id() == GRP_ID_BTNOTIFICATION_MAIN || mmi_frm_group_get_active_id() == GRP_ID_BTNOTIFICATION_MSG_LIST) &&
                    g_mmi_bt_notification_cntx_p->popup_dev_addr.lap == g_mmi_bt_notification_cntx_p->current_dev_addr.lap &&
                    g_mmi_bt_notification_cntx_p->popup_dev_addr.uap == g_mmi_bt_notification_cntx_p->current_dev_addr.uap &&
                    g_mmi_bt_notification_cntx_p->popup_dev_addr.nap == g_mmi_bt_notification_cntx_p->current_dev_addr.nap)
                {
                    WCHAR device_name[SRV_BT_CM_BD_FNAME_LEN] = {0};
                    
                    srv_bt_cm_get_dev_ucs2_name(
                        &(g_mmi_bt_notification_cntx_p->popup_dev_addr),
                        SRV_BT_CM_BD_UCS2_NAME_LEN,
                        device_name);
                    
                    mmi_bt_notification_main_show_disconnect(device_name);
                }
                else if (!srv_bt_noti_check_connection() && mmi_frm_scrn_get_active_id() == SCR_ID_BTNOTIFICATION_DEV_LIST)
                {
                    mmi_bt_notification_main_show_disconnect((WCHAR*)GetString(STR_ID_BTNOTIFICATION_APPLICATION_APP_NAME));
                }
            }
            else
            {
                if (!g_mmi_bt_notification_cntx_p->is_in_composer)
                {
                    mmi_frm_group_close(GRP_ID_BTNOTIFICATION_POPUP);
                    
                    mmi_frm_nmgr_notify_by_app(
                        MMI_SCENARIO_ID_BT_NOTIFY,
                        MMI_EVENT_BT_NOTIFY,
                        mmi_bt_notification_popup_entry,
                        NULL);                  
                    g_mmi_bt_notification_cntx_p->need_popup = MMI_FALSE;
                }
                else
                {
                    memcpy(&g_mmi_bt_notification_cntx_p->refresh_cntx, refresh_evt, sizeof(srv_bt_noti_refresh_evt_struct));
                    g_mmi_bt_notification_cntx_p->need_popup = MMI_TRUE;
                }
            }
            break;
        }
        case EVT_ID_SRV_BT_NOTI_SYNC_DEV:
        {
            srv_bt_noti_sync_event_struct* sync_evt = (srv_bt_noti_sync_event_struct*)evt;
            
            mmi_frm_group_close(GRP_ID_BTNOTIFICATION_SYNC_TIME);

            memcpy(&g_mmi_bt_notification_cntx_p->sync_time_cntx, sync_evt, sizeof(srv_bt_noti_sync_event_struct));

            g_mmi_bt_notification_cntx_p->synced = MMI_FALSE;

	        mmi_frm_group_create_ex(
	                    GRP_ID_ROOT,
	                    GRP_ID_BTNOTIFICATION_SYNC_TIME,
	                    mmi_bt_notification_sync_time_proc,
	                    NULL,
	                    MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    	    mmi_frm_scrn_create(GRP_ID_BTNOTIFICATION_SYNC_TIME, 
    	        SCR_ID_BTNOTIFICATION_SYNC_TIME, 
    	        mmi_bt_notification_sync_time_proc,
    	        sync_evt);
                
                break;
        }
        #ifdef __MMI_BT_NOTIFICATION_FOR_WEARABLE__
        case EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING:
        {
            mmi_frm_group_close(GRP_ID_BTNOTIFICATION_SYNC_TIME);
            //return MMI_RET_DONT_CARE;
            break;
        }
        case EVT_ID_SRV_BT_NOTI_MRE_INSTALL_NOTIFY:
        {
            srv_bt_noti_mre_install_event_notify_struct *mre_install = (srv_bt_noti_mre_install_event_notify_struct *)evt;
            MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BT_NOTIFICATION_MRE, mre_install->ret_code, mre_install->err_code);

            if (mre_install->ret_code == SRV_BT_NOTI_MRE_INSTALL_START)
            {
                mmi_frm_group_create_ex(
    	                    GRP_ID_ROOT,
    	                    GRP_ID_BTNOTIFICATION_MRE,
    	                    mmi_bt_notification_mre_proc,
    	                    NULL,
    	                    MMI_FRM_NODE_SMART_CLOSE_FLAG);

                mmi_frm_scrn_create(GRP_ID_BTNOTIFICATION_MRE, 
        	        SCR_ID_BTNOTIFICATION_MRE, 
        	        mmi_bt_notification_mre_proc,
        	        mre_install);
            }
            else
            {
                mmi_frm_group_close(GRP_ID_BTNOTIFICATION_MRE);

                switch (mre_install->ret_code)
                {
                    case SRV_BT_NOTI_MRE_INSTALL_SUCCESS:
                    case SRV_BT_NOTI_MRE_UNINSTALL_SUCCESS:
                    {
                        MMI_STR_ID title = mre_install->ret_code == SRV_BT_NOTI_MRE_INSTALL_SUCCESS ? 
                            STR_ID_BTNOTIFICATION_POPUP_MRE_INSTALL_SUCCESS : STR_ID_BTNOTIFICATION_POPUP_MRE_UNINSTALL_SUCCESS;

                        mmi_popup_display_ext(
                            title,
                            MMI_EVENT_SUCCESS,
                            NULL);
                        
                        break;
                    }

                    case SRV_BT_NOTI_MRE_INSTALL_FAIL:                   
                    case SRV_BT_NOTI_MRE_UNINSTALL_FAIL:
                    {
                        MMI_STR_ID title;
                        if (mre_install->ret_code == SRV_BT_NOTI_MRE_UNINSTALL_FAIL)
                        {
                            title = STR_ID_BTNOTIFICATION_POPUP_MRE_UNINSTALL_FAIL;
                        }
                        else
                        {
                            switch (mre_install->err_code)
                            {
                                case SRV_BT_NOTIFY_RET_FILE_NOT_EXIST:
                                case SRV_BT_NOTIFY_RET_FILE_INTEGRITY_ERROR:
                                {
                                    title = STR_ID_BTNOTIFICATION_POPUP_MRE_INSTALL_FAIL_FOR_LOW_QUOTA;
                                    break;
                                }
                                
                                default:
                                {
                                    title = STR_ID_BTNOTIFICATION_POPUP_MRE_INSTALL_FAIL_FOR_INTERNAL_ERR;
                                    break;
                                }
                            }
                        }
                        
                        mmi_popup_display_ext(
                            title,
                            MMI_EVENT_FAILURE,
                            NULL);

                        break;
                    }
                }
            }

            break;
        }
        #endif /*__MMI_BT_NOTIFICATION_FOR_WEARABLE__*/
        default:
        {
            return MMI_RET_OK;
        }
    }
	#elif defined(__MMI_BT_NOTI_SRV__)
	switch(evt->evt_id)
	{
		case EVT_ID_SRV_BT_NOTI_SYNC_DEV:
		{
			srv_bt_noti_sync_event_struct* sync_evt = (srv_bt_noti_sync_event_struct*)evt;
			srv_bt_noti_sync_event_struct *sync_time = &g_mmi_bt_notification_cntx_p->sync_time_cntx;
			
			memcpy(&g_mmi_bt_notification_cntx_p->sync_time_cntx, sync_evt, sizeof(srv_bt_noti_sync_event_struct));
			
		    sync_time->call_back(&(sync_time->bt_addr), sync_time->time, sync_time->time_zone, MMI_FALSE);
			break;
		}
	}
	
	#endif/*__MMI_BT_NOTI_SRV__*/
    return MMI_RET_OK;
}

#endif/*defined(__MMI_BT_NOTIFICATION__) || defined (__MMI_BT_NOTI_SRV__)*/

