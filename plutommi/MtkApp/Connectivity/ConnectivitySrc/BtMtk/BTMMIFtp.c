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

/******************************************************************************
 * 
 * Filename
 * ---------
 *  BTMMIFtp.c
 * 
 * Project:
 * --------
 *  
 * 
 * Description:
 * ------------
 *  
 * 
 * Author:
 * -------
 * -------
 * 
 *=============================================================================
 *            HISTORY
 * Below this line,  this part is controlled by PVCS VM. DO NOT MODIFY!!
 *-----------------------------------------------------------------------------
 * $Log$
 *
 * 01 18 2012 zhanying.liu
 * removed!
 * .update
 *
 * 09 20 2011 zhanying.liu
 * removed!
 * .remove S8 type
 *
 * 06 15 2011 zhanying.liu
 * removed!
 * .replace gpio header file and api with service header file and api
 *
 * 06 01 2011 zhanying.liu
 * removed!
 * .modify group create and enter & default rsk handler
 *
 * 05 31 2011 zhanying.liu
 * removed!
 * . adjust compile option in showcategory
 *
 * 05 26 2011 zhanying.liu
 * removed!
 * . remove USB phase out API
 *
 * 04 13 2011 zhanying.liu
 * removed!
 * .update trace
 *
 * 12 16 2010 zhanying.liu
 * removed!
 * .update RHR code check in.
 *
 * 12 14 2010 zhanying.liu
 * removed!
 * .update RHR add files
 *
 * 12 14 2010 zhanying.liu
 * removed!
 * .MAUI RHR code check in
 *
 * 11 27 2010 zhanying.liu
 * removed!
 * .add srv_ftps_set_permission() in FTP service
 *
 * 11 26 2010 aidan.hung
 * removed!
 * Remove Pluto FMGR resource files on COSMIOS project
 *
 * 11 24 2010 zhanying.liu
 * removed!
 * .remove receive disable judgement to MMI
 *
 * 11 23 2010 zhanying.liu
 * removed!
 * .BT CM revise code check in
 *
 * 10 19 2010 zhanying.liu
 * removed!
 * .clear the handle if cancel select drive
 *
 * 10 15 2010 zhanying.liu
 * removed!
 * .remove __MMI_USB_SPLIT_SUPPORT__
 *
 * 09 28 2010 zhanying.liu
 * removed!
 * . show popup firstly, then cancel select drive
 *
 * 09 25 2010 zhanying.liu
 * removed!
 * .check in code for USB-Split
 *
 * 09 21 2010 zhanying.liu
 * removed!
 * .ignore the afterwards key to keep from re-entry
 *
 * 07 27 2010 zhanying.liu
 * removed!
 * .remove unused header files
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 * 
 *-----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *=============================================================================
 ******************************************************************************/
#include "MMI_features.h"

#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
//#include "MMI_include.h"
//#include "CommonScreens.h"      /* DisplayPopup */
//#include "MainMenuDef.h"        /* for MAIN_MENU_TITLE_EXTRA_APP_ICON  */
//#include "ProfileGprots.h"      /* PlayRequestTone */
#include "ProfilesSrvGprot.h"
//#include "FileManagerGProt.h"   /* MMI_PUBLIC_DRV */
//#include "FileManagerDef.h"
#include "BtcmSrvGprot.h"
//#include "Bluetooth_struct.h"
#include "BTMMIObexGprots.h"
//#include "ExtDeviceDefs.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif
//#include "BTMMIScr.h"
#include "BTMMIScrGprots.h"
#include "BTMMIFtpGprots.h"
#include "BTMMIFtp.h"
#include "filemgrcuigprot.h"
#include "MenuCUIGprot.h" /* Add Menu CUI support */
#include "FileMgrGProt.h"

// RHR: add
#include "MMIDataType.h"
#include "gui_data_types.h"
#include "FtpSrvGprots.h"
#include "wgui_touch_screen.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "custom_events_notify.h"
#include "wgui_categories_popup.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "DebugInitDef_Int.h"
#include "wgui_categories_list.h"
#include "wgui_categories.h"
#include "MMI_conn_app_trc.h"
#include "kal_trace.h"
#include "Unicodexdcl.h"
#include "FileMgrSrvGProt.h"
#include "wgui_categories_text_viewer.h"
#include "CommonScreensResDef.h"
#include "AlertScreen.h"
#include "mmi_rp_srv_filemanager_def.h"
#include "fs_errcode.h"
#include "mmi_rp_file_type_def.h"
#include "string.h"
#include "mmi_res_range_def.h"
#include "GpioSrvGprot.h"
#include "FileMgrType.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"
#include "mmi_rp_app_uiframework_def.h"
#include "gui_typedef.h"
#include "NotificationGprot.h"
#include "stack_msgs.h"
#include "stack_config.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
// RHR: add

/***************************************************************************** 
* CONTEXT
*****************************************************************************/
mmi_ftp_scr_cntx_struct g_mmi_ftp_scr_cntx;
mmi_ftp_scr_cntx_struct *g_mmi_ftp_scr_cntx_p = &g_mmi_ftp_scr_cntx;

/***************************************************************************** 
* Local Variable
*****************************************************************************/
#ifdef __MMI_FTC_SUPPORT__
static U16 mmi_ftpc_notify_str[MMI_FTP_NOTY_STR_SIZE];
#endif /* __MMI_FTC_SUPPORT__ */ 

/***************************************************************************** 
 * MACROS
 *****************************************************************************/
#ifdef __MMI_FTC_SUPPORT__
#define MMI_FTPC_BUILD_ABORTING_NOTY_STR()                              \
{                                                                       \
   kal_wstrcpy((U16*)mmi_ftpc_notify_str, (U16*)GetString(STR_GLOBAL_CANCELLING)); \
}

#define MMI_FTPC_BUILD_CONNECTING_NOTY_STR()                            \
{                                                                       \
   kal_wstrcpy((U16*)mmi_ftpc_notify_str, (U16*)GetString(STR_GLOBAL_CONNECTING)); \
}

#define MMI_FTPC_BUILD_REFRESHING_NOTY_STR()                            \
{                                                                       \
   kal_wstrcpy((U16*)mmi_ftpc_notify_str, (U16*)GetString(STR_BT_REFRESHING)); \
}

#define MMI_FTPC_BUILD_DISCONNECTING_NOTY_STR()                         \
{                                                                       \
   kal_wstrcpy((U16*)mmi_ftpc_notify_str, (U16*)GetString(STR_GLOBAL_DISCONNECTING)); \
}

#define MMI_FTPC_BUILD_NOTY_STR()                                       \
{                                                                       \
    U16 recv_cnt = (U16)(g_mmi_ftp_scr_cntx.received_obj_cnt - g_mmi_ftp_scr_cntx.failed_obj_cnt); \
    if (recv_cnt > 0)                                                   \
    {                                                                   \
        if (g_mmi_ftp_scr_cntx.failed_obj_cnt == 0 && recv_cnt > 1)     \
        {                                                               \
            kal_wsprintf((WCHAR*)mmi_ftpc_notify_str, "%w", (U16*)GetString(STR_BT_ALL_FILE_RECEIVED)); \
        }                                                               \
        else                                                            \
        {                                                               \
            kal_wsprintf(                                               \
                (WCHAR*)mmi_ftpc_notify_str,                            \
                "%d %w%w",                                              \
                recv_cnt,                                               \
                (U16*)GetString((U16)(recv_cnt > 1 ? STR_FTP_NOTY_RECV_FILE_TIL : STR_FTP_NOTY_RECV_FILE_TIL_SINGLE)), \
                (U16*)GetString(STR_FTP_FILE_RECEIVED));                \
        }                                                               \
    }                                                                   \
    else /* (recv_cnt == 0) */                                          \
    {                                                                   \
        mmi_ftpc_notify_str[0] = 0;                                     \
    }                                                                   \
}


//#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
#define MMI_FTPC_GET_ALL_CONFIRM_STR()                                  \
{                                                                       \
   U16 cnt[8];                                                          \
   kal_wstrcpy((U16*)mmi_ftpc_notify_str, (U16*)GetString(STR_FTP_GET_ALL_CONFIRM_HEAD)); \
   kal_wsprintf((U16*)cnt, "%d", g_mmi_ftp_scr_cntx_p->file_cnt_cur_folder);           \
   kal_wstrcat((U16*)mmi_ftpc_notify_str, (U16*)cnt);                   \
   kal_wstrcat((U16*)mmi_ftpc_notify_str, (U16*) GetString(STR_FTP_GET_ALL_CONFIRM_TAIL)); \
}
//#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 
#endif /* __MMI_FTC_SUPPORT__ */ 

/***************************************************************************** 
 * External Functions
 *****************************************************************************/
#ifdef __MMI_FTC_SUPPORT__
static mmi_ret mmi_ftpc_idle_notify_screen_leave_proc(mmi_event_struct *para);
static mmi_ret mmi_ftpc_file_browser_leave_proc(mmi_event_struct *para);
static mmi_ret mmi_ftpc_connecting_screen_leave_proc(mmi_event_struct *para);
static void mmi_ftpc_file_browser_highlight_hdlr(S32 index);
static pBOOL mmi_ftpc_browsing_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
static void mmi_ftpc_entry_exit_confirm_scr(void);
static void mmi_ftpc_abort(void);
static void mmi_ftpc_exit_file_browser(void);
static void mmi_ftpc_get_file_notify(S32 hd, U32 event, S32 retval);
static void mmi_ftpc_get_single_file(void);
static void mmi_ftpc_connect_scr_RSK(void);
static void mmi_ftpc_entry_canceling(void);
static void mmi_ftpc_entry_aborting(void);
static void mmi_ftpc_entry_back_to_parent_folder(void);
static void mmi_ftpc_entry_disconnecting(void);
static void mmi_ftpc_connect_rsp_hd(srv_ftpc_connect_struct* result_p);
static void mmi_ftpc_set_folder_rsp_hd(srv_ftpc_set_folder_struct* result_p);
static void mmi_ftpc_get_folder_content_rsp_hd(srv_ftpc_get_folder_struct* result_p);
static void mmi_ftpc_get_file_content_rsp_hd(srv_ftpc_get_file_struct* result_p);
static void mmi_ftpc_disconnect_server_rsp_hd(srv_ftpc_disconnect_struct* result_p);
static void mmi_ftpc_del_scr(MMI_ID grp_id, MMI_ID scr_id);
static void mmi_ftpc_recv_get_obj_info(mmi_bt_recv_obj_info_struct *obj_info_p);
static void mmi_ftpc_addhistory(MMI_ID grp_id, MMI_ID scr_id, mmi_proc_func entry_proc);
static void mmi_ftpc_obj_receive_ind(void);
static void mmi_ftpc_browser_history_replace(void);
static void mmi_ftpc_entry_file_browser(void);
static void mmi_ftpc_notify_recv_err(U16 cause);
static void mmi_ftpc_clear_abort_scr(void);
static void mmi_ftpc_entry_connect_scr(void);
static void mmi_ftpc_pre_entry_idle_notify_scr(void);
static void mmi_ftpc_entry_idle_notify_scr(void);
static void mmi_ftpc_convert_filesize_to_string(U32 size, U16 *dest_str);
static void mmi_ftpc_get_next_file(void);
static void mmi_ftpc_file_browser_option_hdlr(mmi_event_struct *evt);
static void mmi_ftpc_show_file_browser_options(void);
static void mmi_ftpc_entry_opening_folder(void);
static void mmi_ftpc_entry_obj_detail(void);

#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
static void mmi_ftpc_add_to_list(U16 index);
static S32 mmi_ftpc_mark_several_set_state(S32 item_index);
static void mmi_ftpc_get_list_files(void);
static void mmi_ftpc_get_all_files(void);
static void mmi_ftpc_list_option_delete(U16 item_index);
static MMI_BOOL mmi_ftpc_check_list(void);
static void mmi_ftpc_free_list(void);
//static MMI_BOOL mmi_ftpc_find_next_file_index(void);
static void mmi_ftpc_get_all_confirm_scr(void);
static void mmi_ftpc_get_several_option_hdlr(mmi_event_struct *evt);
static MMI_BOOL mmi_ftpc_is_file_in_marked_list(U16 index);
static void mmi_ftpc_entry_mark_several_screen(void);
static void mmi_ftpc_show_get_several_options(void);
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 

#ifndef __MMI_BT_RECV_FDR_SWITCH__
static void mmi_ftpc_notify_scr_browse(void);
#endif  /* __MMI_BT_RECV_FDR_SWITCH__ */

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_ftpc_tap_file_browser_callback_function(mmi_tap_type_enum tap_type, S32 index);
//static void mmi_ftpc_tap_get_several_callback_function(mmi_tap_type_enum tap_type, S32 index);
#endif  // defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)

#endif /* __MMI_FTC_SUPPORT__ */ 

#ifdef __MMI_FTS_SUPPORT__
static void mmi_ftps_start_ind_handle(srv_ftps_start_indication_struct* start_ind_p);
static void mmi_ftps_stop_ind_handle(void* para);
static void mmi_ftps_connect_ind_handle(srv_ftps_connect_indication_struct* connect_ind_p);
static void mmi_ftps_authorize_ind_handle(srv_ftps_authorize_indication_struct* authorize_ind_p);
static void mmi_ftps_event_handle(S32 hd, U16 event, void* para);
static void mmi_ftps_disconnect_ind_handle(srv_ftps_disconnect_indication_struct* dis_ind_p);
static void mmi_ftps_operation_begin_ind_handle(srv_ftps_operation_begin_struct* para);
static void mmi_ftps_operation_end_ind_handle(srv_ftps_operation_end_struct* op_end_ind_p);
static void mmi_ftps_popup(U32 flag);
#endif

static void mmi_ftp_popup_hdlr(UI_string_type string, mmi_event_notify_enum event_id);

/*****************************************************************************
    MMI FTP SCR FUNCTIONS
*****************************************************************************/
#ifdef __MMI_FTC_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_entry_connect_scr
 * DESCRIPTION
 *  This function is to entry the connecting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_entry_connect_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_CONNECTING, NULL, mmi_ftpc_entry_connect_scr, MMI_FRM_FULL_SCRN))
    {
        MMI_FTPC_BUILD_CONNECTING_NOTY_STR();
        img_id = mmi_get_event_based_image(MMI_EVENT_PROGRESS);
        ShowCategory66Screen(
            STR_GLOBAL_CONNECTING,
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            0,
            0,
            STR_GLOBAL_CANCEL,
            0,
            (U8*)mmi_ftpc_notify_str,
            img_id,
            NULL);

        SetRightSoftkeyFunction(mmi_ftpc_connect_scr_RSK, KEY_EVENT_UP);
        mmi_frm_scrn_set_leave_proc(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_CONNECTING, mmi_ftpc_connecting_screen_leave_proc);
    }
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftpc_file_browser_option_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
static void mmi_ftpc_file_browser_option_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_MENU_ID menu_id = ((cui_menu_event_struct*)evt)->highlighted_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_id)
    {
        case MENU_CONN_FTP_FILE_OPTION_GET:
            g_mmi_ftp_scr_cntx_p->pull_type = MMI_FTP_PULL_TYPE_SINGLE;
            mmi_ftpc_get_single_file();
            break;

        case MENU_CONN_FTP_FOLDER_OPTION_OPEN:
            if (srv_ftpc_change_folder(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd, g_mmi_ftp_scr_cntx_p->sel_obj_id)
                == SRV_FTP_RESULT_OK)
            {
                mmi_ftpc_entry_opening_folder();
            }
            else
            {
                mmi_ftpc_notify_recv_err(SRV_FTPC_NOTIFY_ACTION_NOT_ALLOWED);
            }
            break;

        case MENU_CONN_FTP_GEN_OPTION_REFRESH:
            if (srv_ftpc_refresh_folder(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd)
                == SRV_FTP_RESULT_OK)
            {
                mmi_ftpc_entry_opening_folder();
            }
            else
            {
                mmi_ftpc_notify_recv_err(SRV_FTPC_NOTIFY_ACTION_NOT_ALLOWED);
            }
            break;

        case MENU_CONN_FTP_GEN_OPTION_DETAIL:
            mmi_ftpc_entry_obj_detail();
            break;

        case MENU_CONN_FTP_GEN_OPTION_BACK_TO_ROOT_DIR:
            if (srv_ftpc_back_root_folder(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd) == SRV_FTP_RESULT_OK)
            {
                mmi_ftpc_entry_opening_folder();
            }
            else
            {
                mmi_ftpc_notify_recv_err(SRV_FTPC_NOTIFY_ACTION_NOT_ALLOWED);
            }
            break;

        case MENU_CONN_FTP_GEN_OPTION_DISCONNECT:
            mmi_ftpc_entry_exit_confirm_scr();
            break;

#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
        case MENU_CONN_FTP_FILE_OPTION_GET_SEVERAL:
            mmi_ftpc_entry_mark_several_screen();
            break;

        case MENU_CONN_FTP_FILE_OPTION_GET_ALL:
            mmi_ftpc_get_all_confirm_scr();
            break;
#endif  /* __MMI_FTC_MULTIPULL_SUPPORT__ */

        default:
            break;
    }
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftpc_show_file_browser_options
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ******************************************************************************/
static void mmi_ftpc_show_file_browser_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID menu_gid;
    MMI_MENU_ID root;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_ftp_scr_cntx_p->entity_cnt_cur_folder != 0)
    {
        /* if (srv_ftpc_get_obj_info(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd, */
        /*                           g_mmi_ftp_scr_cntx_p->sel_obj_id, */
        /*                           &(g_mmi_ftp_scr_cntx_p->obj_entity)) */
        /*     >= FS_NO_ERROR) */
        /* already update in highlight handler */

        /* folder option screen */
        if (g_mmi_ftp_scr_cntx_p->obj_entity.type == SRV_FTP_OBJ_TYPE_FOLDER)
        {
            root = MENU_CONN_FTP_FOLDER_OPTION;
        }
        else /* file option screen */
        {
            root = MENU_CONN_FTP_FILE_OPTION;
        }
    }
    else /* empty folder option screen */
    {
        root = MENU_CONN_FTP_EMPTY_FOLDER_OPTION;
    }

    menu_gid = cui_menu_create(
        g_mmi_ftp_scr_cntx_p->subgid1, 
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_OPTION,
        root,
        MMI_TRUE,
        (void*)g_mmi_ftp_scr_cntx_p);

    MMI_ASSERT(menu_gid != GRP_ID_INVALID);

    g_mmi_ftp_scr_cntx_p->file_browser_menu_gid = menu_gid;
    //cui_menu_enable_cascading_option_menu(menu_gid);

    cui_menu_set_currlist_title(
        menu_gid,
        (WCHAR*)GetString(STR_GLOBAL_OPTIONS),
        (UI_image_type)GetImage(GetRootTitleIcon(MENU_CONN_BT_MAIN)));
    /* cui_menu_set_currlist_left_softkey(menu_gid, (WCHAR*)GetString(STR_GLOBAL_OK)); */
    /* cui_menu_set_currlist_right_softkey(menu_gid, (WCHAR*)GetString(STR_GLOBAL_BACK)); */
    
    cui_menu_run(menu_gid);
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftpc_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt    [IN]
 *  
 * RETURNS
 *  mmi_ret
 ******************************************************************************/
static mmi_ret mmi_ftpc_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            g_mmi_ftp_scr_cntx_p->gid = GRP_ID_INVALID;
            break;
            
        case EVT_ID_GROUP_INACTIVE:
            if (mmi_frm_scrn_get_count(g_mmi_ftp_scr_cntx_p->gid) == 0)
            {
                mmi_frm_group_close(g_mmi_ftp_scr_cntx_p->gid);
            }
            break;
    }

    return MMI_RET_OK;
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftpc_subgroup1_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt    [IN]
 *  
 * RETURNS
 *  mmi_ret
 ******************************************************************************/
static mmi_ret mmi_ftpc_subgroup1_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            g_mmi_ftp_scr_cntx_p->subgid1 = GRP_ID_INVALID;
            break;


        case EVT_ID_GROUP_INACTIVE:
            if (mmi_frm_scrn_get_count(g_mmi_ftp_scr_cntx_p->subgid1) == 0)
            {
                mmi_frm_group_close(g_mmi_ftp_scr_cntx_p->subgid1);
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            if (g_mmi_ftp_scr_cntx_p->file_browser_menu_gid != GRP_ID_INVALID)
            {
                mmi_ftpc_file_browser_option_hdlr(evt);
            }
#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
            else if (g_mmi_ftp_scr_cntx_p->get_several_menu_gid != GRP_ID_INVALID)
            {
                mmi_ftpc_get_several_option_hdlr(evt);
            }
#endif  /* __MMI_FTC_MULTIPULL_SUPPORT__ */
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            if (g_mmi_ftp_scr_cntx_p->file_browser_menu_gid != GRP_ID_INVALID)
            {
                cui_menu_close(g_mmi_ftp_scr_cntx_p->file_browser_menu_gid);
                g_mmi_ftp_scr_cntx_p->file_browser_menu_gid = GRP_ID_INVALID;
            }

            if (g_mmi_ftp_scr_cntx_p->get_several_menu_gid != GRP_ID_INVALID)
            {
                cui_menu_close(g_mmi_ftp_scr_cntx_p->get_several_menu_gid);
                g_mmi_ftp_scr_cntx_p->get_several_menu_gid = GRP_ID_INVALID;
            }
            
            break;
    }

    return MMI_RET_OK;
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftpc_subgroup2_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt    [IN]
 *  
 * RETURNS
 *  mmi_ret
 ******************************************************************************/
static mmi_ret mmi_ftpc_subgroup2_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            g_mmi_ftp_scr_cntx_p->subgid2 = GRP_ID_INVALID;
            break;

        case EVT_ID_GROUP_INACTIVE:
            if (mmi_frm_scrn_get_count(g_mmi_ftp_scr_cntx_p->subgid2) == 0)
            {
                mmi_frm_group_close(g_mmi_ftp_scr_cntx_p->subgid2);
            }
    }

    return MMI_RET_OK;
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftpc_pre_entry_connect_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
static void mmi_ftpc_pre_entry_connect_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_ftp_scr_cntx_p->subgid1 = mmi_frm_group_create_ex(
        g_mmi_ftp_scr_cntx_p->gid,
        GRP_ID_AUTO_GEN,
        mmi_ftpc_subgroup1_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_ftpc_entry_connect_scr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_entry_canceling
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_entry_canceling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_CONNECT_CANCELING,
                           NULL, mmi_ftpc_entry_canceling, MMI_FRM_FULL_SCRN))
    {
        MMI_FTPC_BUILD_ABORTING_NOTY_STR();
        img_id = mmi_get_event_based_image(MMI_EVENT_PROGRESS);
        ShowCategory66Screen(
            STR_GLOBAL_CANCELLING,
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            0,
            0,
            0,
            0,
            (U8*)mmi_ftpc_notify_str,
            img_id,
            NULL);

        mmi_ftpc_del_scr(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_CONNECTING);
    }
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftpc_file_browser_csk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ******************************************************************************/
static void mmi_ftpc_file_browser_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_ftp_scr_cntx_p->entity_cnt_cur_folder != 0)
    {
        /* result = srv_ftpc_get_obj_info(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd, */
        /*                                g_mmi_ftp_scr_cntx_p->sel_obj_id, */
        /*                                &(g_mmi_ftp_scr_cntx_p->obj_entity)); */
        /* already update in the highlight handler */
        if (g_mmi_ftp_scr_cntx_p->obj_entity.type == SRV_FTP_OBJ_TYPE_FOLDER)
        {
            if (srv_ftpc_change_folder(
                    g_mmi_ftp_scr_cntx_p->ftpc_srv_hd,
                    g_mmi_ftp_scr_cntx_p->sel_obj_id)
                == SRV_FTP_RESULT_OK)
            {
                mmi_ftpc_entry_opening_folder();
                return;
            }
        }
    }

     /* file or empty folder */
    mmi_ftpc_show_file_browser_options();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_entry_file_browser
 * DESCRIPTION
 *  This function is to display the folder content of the remote phone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_entry_file_browser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_is_present(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_FILE_BROWSER, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_ftpc_del_scr(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_FILE_BROWSER);
    }
    
    if (mmi_frm_scrn_enter(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_FILE_BROWSER,
                           NULL, mmi_ftpc_entry_file_browser, MMI_FRM_FULL_SCRN))
    {
        RegisterHighlightHandler(mmi_ftpc_file_browser_highlight_hdlr);
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        ShowCategory184Screen(
            STR_FTP_FILE_BROWSER,
            GetRootTitleIcon(MENU_CONN_BT_MAIN), /* title text and icon */
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,                  /* LSK text and icon */
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,                     /* RSK text and icon */
            g_mmi_ftp_scr_cntx_p->entity_cnt_cur_folder,
            mmi_ftpc_browsing_item,
            NULL,                                /* No Hint inside first */
            0,
            gui_buffer);

        SetLeftSoftkeyFunction(mmi_ftpc_show_file_browser_options, KEY_EVENT_UP);
        //SetKeyHandler(mmi_ftpc_show_file_browser_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

        SetRightSoftkeyFunction(mmi_ftpc_entry_back_to_parent_folder, KEY_EVENT_UP);
        //SetKeyHandler(mmi_ftpc_entry_back_to_parent_folder, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

        /* if is empty folder, no highlight item,
           else will set the icon in highlight handle */
        if (g_mmi_ftp_scr_cntx_p->entity_cnt_cur_folder == 0)
        {
            ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
        }
        SetCenterSoftkeyFunction(mmi_ftpc_file_browser_csk_hdlr, KEY_EVENT_UP);
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_tap_callback(mmi_ftpc_tap_file_browser_callback_function);
#endif  // defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)

        mmi_frm_scrn_close(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_OPENING_FOLDER);
        mmi_frm_scrn_set_leave_proc(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_FILE_BROWSER, mmi_ftpc_file_browser_leave_proc);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_entry_disconnecting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_entry_disconnecting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_DISCONNECTING,
                           NULL, mmi_ftpc_entry_disconnecting, MMI_FRM_FULL_SCRN))
    {
        MMI_FTPC_BUILD_DISCONNECTING_NOTY_STR();
        img_id = mmi_get_event_based_image(MMI_EVENT_PROGRESS);
        ShowCategory66Screen(
            STR_GLOBAL_DISCONNECTING,
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            0,
            0,
            0,
            0,
            (U8*)mmi_ftpc_notify_str,
            img_id,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_entry_opening_folder
 * DESCRIPTION
 *  this function is used to get file browser content
 *  No RSK: because previous scr's data is lost
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_entry_opening_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            g_mmi_ftp_scr_cntx_p->subgid1,
            SCR_FTP_OPENING_FOLDER,
            NULL,
            mmi_ftpc_entry_opening_folder,
            MMI_FRM_FULL_SCRN))
    {
        MMI_FTPC_BUILD_REFRESHING_NOTY_STR();
        img_id = mmi_get_event_based_image(MMI_EVENT_PROGRESS);
        ShowCategory66Screen(
            STR_BT_REFRESHING,
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            0,
            0,
            0,
            0,
            (U8*)mmi_ftpc_notify_str,
            img_id,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_entry_obj_detail
 * DESCRIPTION
 *  This function is to display the detailed info about the selected object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_entry_obj_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* guiBuffer;
    CHAR* info;
    U32 pre_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPC_ENTRY_OBJ_DETAIL);


    if (mmi_frm_scrn_enter(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_DETAIL_INFO,
                           NULL, mmi_ftpc_entry_obj_detail, MMI_FRM_FULL_SCRN))
    {
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();
        info = (CHAR*)subMenuData;

        /* srv_ftpc_get_obj_info(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd, */
        /*                       g_mmi_ftp_scr_cntx_p->sel_obj_id, */
        /*                       &(g_mmi_ftp_scr_cntx_p->obj_entity)); */
        /* already update in highlight handler */

        mmi_ucs2cpy(info, (CHAR*)GetString(STR_FTP_DETAIL_NAME));
        mmi_ucs2cat(info, (CHAR*)L"\n");

        pre_len = mmi_ucs2strlen(info);
        srv_ftpc_get_obj_detail_info(
            g_mmi_ftp_scr_cntx_p->ftpc_srv_hd,
            g_mmi_ftp_scr_cntx_p->sel_obj_id,
            (U16*)&info[pre_len * 2]);

        srv_fmgr_path_hide_extension((WCHAR*)&info[pre_len * 2]);
        mmi_ucs2cat(info, (CHAR*)L"\n");
        mmi_ucs2cat(info, (CHAR*)GetString(STR_FTP_DETAIL_DATE));
        mmi_ucs2cat(info, (CHAR*)L"\n");
        mmi_ucs2cat(info, (CHAR*)g_mmi_ftp_scr_cntx_p->obj_entity.created_date);
        mmi_ucs2cat(info, (CHAR*)L"\n");

        if (g_mmi_ftp_scr_cntx_p->obj_entity.type == SRV_FTP_OBJ_TYPE_FILE)
        {
            U16 size_str[8];

            mmi_ucs2cat(info, (CHAR*)GetString(STR_FTP_DETAIL_SIZE));
            mmi_ucs2cat(info, (CHAR*)L"\n");
            if (g_mmi_ftp_scr_cntx_p->obj_entity.size != RECV_UNKNOWN_SIZE)
            {
                mmi_ftpc_convert_filesize_to_string(g_mmi_ftp_scr_cntx_p->obj_entity.size, size_str);
                mmi_ucs2cat(info, (CHAR*)size_str);
            }
            else
            {
                mmi_ucs2cat(info, (CHAR*)GetString(STR_GLOBAL_EMPTY));
            }
            mmi_ucs2cat(info, (CHAR*)L"\n");
        }

        ShowCategory74Screen(
            STR_GLOBAL_DETAILS,
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8)subMenuData,
            MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
            guiBuffer);

        //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_entry_recv_obj
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_entry_recv_obj(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            g_mmi_ftp_scr_cntx_p->subgid1,
            SCR_FTP_RECEIVING,
            NULL,
            mmi_ftpc_entry_recv_obj,
            MMI_FRM_FULL_SCRN))
    {
        ShowRecvingScreen(SCR_FTP_RECEIVING, mmi_ftpc_recv_get_obj_info);
        SetRightSoftkeyFunction(mmi_ftpc_abort, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_entry_aborting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_entry_aborting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            g_mmi_ftp_scr_cntx_p->subgid1,
            SCR_FTP_ABORTING,
            NULL,
            mmi_ftpc_entry_aborting,
            MMI_FRM_FULL_SCRN))
    {
        MMI_FTPC_BUILD_ABORTING_NOTY_STR();
        img_id = mmi_get_event_based_image(MMI_EVENT_PROGRESS);
        ShowCategory66Screen(
            STR_GLOBAL_CANCELLING, 
            GetRootTitleIcon(MENU_CONN_BT_MAIN), 
            0,
            0,
            0,
            0,
            (U8*)mmi_ftpc_notify_str, 
            img_id, 
            NULL);

        if (mmi_frm_scrn_is_present(
                g_mmi_ftp_scr_cntx_p->subgid1,
                SCR_FTP_RECEIVING,
                MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
            mmi_frm_scrn_close(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_RECEIVING);
        }
    }
}


/****************************************************************************** 
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ******************************************************************************/
static void mmi_ftpc_pre_entry_idle_notify_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_ftp_scr_cntx_p->subgid2 = mmi_frm_group_create_ex(
        g_mmi_ftp_scr_cntx_p->gid,
        GRP_ID_AUTO_GEN,
        mmi_ftpc_subgroup2_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
        
    mmi_ftpc_entry_idle_notify_scr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_entry_idle_notify_scr
 * DESCRIPTION
 *  This function is to display notify screen in idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_entry_idle_notify_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPC_ENTRY_IDLE_NOTIFY_SCR);

    if (mmi_frm_scrn_enter(
            g_mmi_ftp_scr_cntx_p->subgid2,
            SCR_FTP_NOTY_FILE_RECV,
            NULL,
            mmi_ftpc_entry_idle_notify_scr,
            MMI_FRM_FULL_SCRN))
    {
#ifdef __MMI_BT_RECV_FDR_SWITCH__
        ShowCategory154Screen(
            STR_FTP_FILE_BROWSER,
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            0,
            0,
            STR_GLOBAL_BACK,
            0,
            (U8*)mmi_ftpc_notify_str,
            NULL,
            IMG_GLOBAL_INFO,
            NULL);

#else /* __MMI_BT_RECV_FDR_SWITCH__ */
        ShowCategory154Screen(
            STR_FTP_FILE_BROWSER,
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            STR_FTP_NOTY_RECV_FILE_BROWSE,
            0,
            STR_GLOBAL_BACK,
            0,
            (U8*)mmi_ftpc_notify_str,
            NULL,
            IMG_GLOBAL_INFO,
            NULL);
#endif /* __MMI_BT_RECV_FDR_SWITCH__ */

#ifndef __MMI_BT_RECV_FDR_SWITCH__
        SetLeftSoftkeyFunction(mmi_ftpc_notify_scr_browse, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_ftpc_notify_scr_browse, KEY_EVENT_UP);
#endif
        //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        mmi_frm_scrn_set_leave_proc(
            g_mmi_ftp_scr_cntx_p->subgid2,
            SCR_FTP_NOTY_FILE_RECV,
            mmi_ftpc_idle_notify_screen_leave_proc);
    }
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftpc_exit_confirm_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
static mmi_ret mmi_ftpc_exit_confirm_proc(mmi_event_struct* evt)
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
            mmi_alert_result_evt_struct* alert = (mmi_alert_result_evt_struct*)evt;
            switch(alert->result)
            {
                case MMI_ALERT_CNFM_YES:
                    mmi_ftpc_exit_file_browser();
                    break;

                case MMI_ALERT_CNFM_NO:
                    break;
            }
        }
        break;
    }
    
    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_entry_exit_confirm_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_entry_exit_confirm_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ftpc_is_running())
    {
        mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
        arg.parent_id = g_mmi_ftp_scr_cntx_p->subgid1;
        arg.callback = mmi_ftpc_exit_confirm_proc;
        mmi_confirm_display(
            (WCHAR*)GetString(STR_FTP_CON_EXIT),
            MMI_EVENT_QUERY,
            &arg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_del_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_del_scr(MMI_ID grp_id, MMI_ID scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_set_leave_proc(grp_id, scr_id, NULL);
    mmi_frm_scrn_close(grp_id, scr_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_notify_recv_err
 * DESCRIPTION
 *  This function is to display popup sceren when receiving error then
 *  delete all ftp screen except the file browser screen
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_notify_recv_err(U16 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPC_NOTIFY_RECV_ERR, cause);
    
    if (cause == SRV_FTPC_NOTIFY_DISK_FULL)
    {
        mmi_ftp_popup_hdlr((UI_string_type)GetString(STR_GLOBAL_MEMORY_FULL), MMI_EVENT_FAILURE);
    }
    else if (cause == SRV_FTPC_NOTIFY_ROOT_DIR_FULL)
    {
        mmi_ftp_popup_hdlr((UI_string_type)GetString(FMGR_FS_ROOT_DIR_FULL_TEXT), MMI_EVENT_FAILURE);
    }
    else if (cause == SRV_FTPC_NOTIFY_WRITE_FILE_FAIL)
    {
        mmi_ftp_popup_hdlr((UI_string_type)GetString(STR_BT_WRITE_FILE_FAIL), MMI_EVENT_FAILURE);
    }
    else if (cause == SRV_FTPC_NOTIFY_CONNECTION_DISCONNECTED)
    {
        mmi_ftp_popup_hdlr((UI_string_type)GetString(STR_FTP_CON_DISCONNECTED), MMI_EVENT_FAILURE);
    }
    else if (cause == SRV_FTPC_NOTIFY_ACTION_NOT_ALLOWED)
    {
        mmi_ftp_popup_hdlr((UI_string_type)GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
    }
    else if (cause == SRV_FTPC_NOTIFY_BROWSE_FILES_FAILED)
    {
        mmi_ftp_popup_hdlr((UI_string_type)GetString(STR_FTP_NOTIFY_BROWSE_FILES_FAILED),
                           MMI_EVENT_FAILURE);
    }
    else if (cause == SRV_FTPC_NOTIFY_GOEP_STATUS_BUSY)
    {
        mmi_ftp_popup_hdlr((UI_string_type)GetString(STR_FTP_NOTIFY_GOEP_STATUS_BUSY),
                           MMI_EVENT_FAILURE);
    }
    else if (cause == SRV_FTPC_NOTIFY_WORK_FOLDER_NO_EXIST)
    {
        /* Z:\@ftp\ not exist   and   E:\received not exist */
        mmi_ftp_popup_hdlr((UI_string_type)GetString(STR_FTP_NOTIFY_WORK_FOLDER_NO_EXIST),
                           MMI_EVENT_FAILURE);
    }
    else if (cause == SRV_FTPC_NOTIFY_FS_DEVICE_BUSY)
    {
        mmi_ftp_popup_hdlr((UI_string_type)GetString(srv_fmgr_fs_error_get_string(FS_DEVICE_BUSY)),
                           MMI_EVENT_FAILURE);
    }
    else if (cause == SRV_FTPC_NOTIFY_NO_CARD)
    {
        mmi_ftp_popup_hdlr((UI_string_type)GetString(STR_BT_NO_CARD),
                           MMI_EVENT_FAILURE);
    }
    else if (cause == SRV_FTPC_NOTIFY_FS_WRITE_PROTEC)
    {
        mmi_ftp_popup_hdlr((UI_string_type)GetString(srv_fmgr_fs_error_get_string(FS_WRITE_PROTECTION)),
                           MMI_EVENT_FAILURE);
    }
    /* support device busy case for MT6601 */
    else if (cause == SRV_FTPC_NOTIFY_LAST)
    {
        goto CLEAR_SCRS;
    }
    else
    {
        mmi_ftp_popup_hdlr((UI_string_type)GetString(STR_GLOBAL_UNFINISHED), MMI_EVENT_FAILURE);
    }

CLEAR_SCRS:
    /* DeleteScreenIfPresent won't stop by registered delete callback function */
    mmi_ftpc_del_scr(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_RECEIVING);
    mmi_ftpc_del_scr(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_ABORTING);
    mmi_ftpc_del_scr(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_DISCONNECTING);
    mmi_ftpc_del_scr(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_DETAIL_INFO);
    mmi_ftpc_del_scr(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_CONNECT_CANCELING);
    mmi_ftpc_del_scr(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_CONNECTING);
    mmi_ftpc_del_scr(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_OPENING_FOLDER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_file_browser_highlight_hdlr
 * DESCRIPTION
 *  This function is to save the highlight index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_file_browser_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_ftp_scr_cntx_p->sel_obj_id = (U16)index;
    if (g_mmi_ftp_scr_cntx_p->entity_cnt_cur_folder != 0)
    {
        result = srv_ftpc_get_obj_info(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd,
                                       (U16)index,
                                       &(g_mmi_ftp_scr_cntx_p->obj_entity));
        if (result >= FS_NO_ERROR)
        {
            if (g_mmi_ftp_scr_cntx_p->obj_entity.type == SRV_FTP_OBJ_TYPE_FOLDER)
            {
                ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            }
            else /* file */
            {
                ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_file_browser_leave_proc
 * DESCRIPTION
 *  This function is the callback funcion for deleting file_browser screen
 * PARAMETERS
 *  p       [?]     [?]
 * RETURNS
 *  U8
 *****************************************************************************/
static mmi_ret mmi_ftpc_file_browser_leave_proc(mmi_event_struct *para)
{
    switch (para->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
            srv_ftpc_disconnect_server(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd);
#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
            mmi_ftpc_free_list();
#endif
            break;

        default:
            break;
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_idle_notify_screen_leave_proc
 * DESCRIPTION
 *  This function is the callback funcion for deleting idle notify screen
 * PARAMETERS
 *  p
 * RETURNS
 *  U8
 *****************************************************************************/
static mmi_ret mmi_ftpc_idle_notify_screen_leave_proc(mmi_event_struct *para)
{
    switch (para->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
            //stopRequestedTone(GENERAL_TONE);
            srv_prof_stop_tone(SRV_PROF_TONE_GENERAL_TONE);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_connecting_screen_leave_proc
 * DESCRIPTION
 *  This function is the callback funcion for deleting sending screen
 * PARAMETERS
 *  p
 * RETURNS
 *  U8
 *****************************************************************************/
static mmi_ret mmi_ftpc_connecting_screen_leave_proc(mmi_event_struct *para)
{
    switch (para->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
            srv_ftpc_disconnect_server(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_connect_scr_RSK
 * DESCRIPTION
 *  RSK function of connecting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_connect_scr_RSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ftpc_entry_canceling();
    srv_ftpc_abort(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_browser_history_replace
 * DESCRIPTION
 *  This function is to replace history for file browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_browser_history_replace(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_node_struct new_node_info;
    MMI_ID out_scr_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPC_BROWSER_HISTORY_REPLACE, g_mmi_ftp_scr_cntx_p->got_root_flag);
    if (mmi_frm_scrn_is_present(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_FILE_BROWSER, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_ftpc_del_scr(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_FILE_BROWSER);
    }

    new_node_info.id = SCR_FTP_FILE_BROWSER;
    new_node_info.entry_proc = (mmi_proc_func)mmi_ftpc_entry_file_browser;

    out_scr_id = (g_mmi_ftp_scr_cntx_p->got_root_flag == 1) ? SCR_FTP_OPENING_FOLDER : SCR_FTP_CONNECTING;
    mmi_frm_scrn_replace(g_mmi_ftp_scr_cntx_p->subgid1, out_scr_id, &new_node_info);
    mmi_frm_scrn_set_leave_proc(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_FILE_BROWSER, mmi_ftpc_file_browser_leave_proc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_addhistory
 * DESCRIPTION
 *  This function is to add aborting screen to History
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_addhistory(MMI_ID grp_id, MMI_ID scr_id, mmi_proc_func entry_proc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_node_struct scr_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPC_ADDHISTORY);

    scr_info.id = scr_id;
    scr_info.entry_proc = entry_proc;
    mmi_frm_scrn_insert(grp_id, SCR_ID_INVALID, &scr_info, MMI_FRM_NODE_AT_LATEST_FLAG);
}


#ifndef __MMI_BT_RECV_FDR_SWITCH__
/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_notify_scr_browse
 * DESCRIPTION
 *  This function is to browse the received folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_notify_scr_browse(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    U16 title_str_id, title_icon_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        if (srv_usb_check_path_exported((WCHAR*)g_mmi_ftp_scr_cntx_p->ftpc_recv_path))
        {
            /* phone drive is exported, can't use this app */
            mmi_usb_app_unavailable_popup(0); /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_ALL(&filter);

    mmi_fmgr_get_app_title_info(APP_FTP, &title_str_id, &title_icon_id, NULL);
    cui_folder_browser_launch(
        GRP_ID_ROOT,
        (WCHAR*)g_mmi_ftp_scr_cntx_p->ftpc_recv_path,
        &filter,
        CUI_FOLDER_BROWSER_OPT_USE_CSK_OFF,
        title_str_id,
        title_icon_id);
    
    mmi_frm_scrn_close(g_mmi_ftp_scr_cntx_p->subgid2, SCR_FTP_NOTY_FILE_RECV);
}
#endif /* __MMI_BT_RECV_FDR_SWITCH__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_obj_receive_ind
 * DESCRIPTION
 *  This function is to notify user that ftp received a unrecognized object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_obj_receive_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPC_OBJ_RECEIVE_IND);

    MMI_FTPC_BUILD_NOTY_STR();
    if (mmi_ftpc_notify_str[0] == 0)
    {
        mmi_popup_display_simple(
            (WCHAR*)GetString(STR_GLOBAL_UNFINISHED),
            MMI_EVENT_FAILURE,
            g_mmi_ftp_scr_cntx_p->subgid1,
            NULL);
    }
    else
    {
        mmi_ftpc_pre_entry_idle_notify_scr();
        srv_prof_play_tone(SRV_PROF_TONE_GENERAL_TONE, NULL);
    }

    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    if (mmi_frm_scrn_is_present(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_RECEIVING, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_frm_scrn_close(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_RECEIVING);
    }
    
    if (mmi_frm_scrn_is_present(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_ABORTING, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_frm_scrn_close(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_ABORTING);
    }

#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
    mmi_ftpc_free_list();

    /* set storage as memory card, then remove memory card,
     * it will display a popup, then should goback to file browser screen */
    if (mmi_frm_scrn_is_present(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_MARK_SEVERAL, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_frm_scrn_close(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_MARK_SEVERAL);
    }
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_browsing_item
 * DESCRIPTION
 *  This function is to display the folder content of the remote phone
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         [?]
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static pBOOL mmi_ftpc_browsing_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_ftpc_get_obj_info(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd,
                                   (U16)item_index,
                                   &(g_mmi_ftp_scr_cntx_p->obj_entity));
    if (result >= FS_NO_ERROR)
    {
        mmi_wcsncpy((U16*)str_buff, (const U16*)g_mmi_ftp_scr_cntx_p->obj_entity.name, MAX_SUBMENU_CHARACTERS);
        if (g_mmi_ftp_scr_cntx_p->obj_entity.actual_name_len > MAX_SUBMENU_CHARACTERS)
        {
            str_buff[MAX_SUBMENU_CHARACTERS - 3] = 0x002E;
            str_buff[MAX_SUBMENU_CHARACTERS - 2] = 0x002E;
            str_buff[MAX_SUBMENU_CHARACTERS - 1] = 0x002E;
        }

        /* show folder icon */
        if (g_mmi_ftp_scr_cntx_p->obj_entity.type == SRV_FTP_OBJ_TYPE_FOLDER)
        {
            //*img_buff_p = (PU8)GetImage((U16)mmi_fmgr_get_filetype_small_icon(FMGR_TYPE_FOLDER, NULL));
            *img_buff_p = (PU8)GetImage((U16)srv_fmgr_types_get_icon(FMGR_TYPE_FOLDER, NULL, SRV_FMGR_TYPES_ICON_SMALL));
        }
        else /* show obj icon */
        {
            /* FMGR_Revise */
            mmi_fmgr_filetype_enum type;

            type = srv_fmgr_types_find_type_by_filename_str((WCHAR*)(g_mmi_ftp_scr_cntx_p->obj_entity.name));

            *img_buff_p = (PU8)GetImage((U16)srv_fmgr_types_get_icon(type, NULL, SRV_FMGR_TYPES_ICON_SMALL));

            srv_fmgr_path_hide_extension((WCHAR*)str_buff);
        }
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_entry_back_to_parent_folder
 * DESCRIPTION
 *  This function is to display the folder content of the parent folder or disconnect when
 *  in the root folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_entry_back_to_parent_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_ftp_scr_cntx_p->browse_depth == 0)
    {
        //mmi_ftpc_entry_exit_confirm_scr();
        mmi_ftpc_exit_file_browser();
    }
    else
    {
        if (srv_ftpc_back_folder(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd) == SRV_FTP_RESULT_OK)
        {
            mmi_ftpc_entry_opening_folder();
        }
        else
        {
            mmi_ftpc_notify_recv_err(SRV_FTPC_NOTIFY_ACTION_NOT_ALLOWED);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_exit_file_browser
 * DESCRIPTION
 *  This function is to exit file browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_exit_file_browser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_ftpc_disconnect_server(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd);
    mmi_ftpc_entry_disconnecting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_abort
 * DESCRIPTION
 *  This is common function to abort getting object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ftpc_abort(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd) == SRV_FTP_RESULT_OK)
    {
        mmi_ftpc_entry_aborting();
    }
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftpc_get_file_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hd    [IN]
 *  event    [IN]
 *  retval    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
static void mmi_ftpc_get_file_notify(S32 hd, U32 event, S32 retval)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    WCHAR obj_path[MMI_FTPC_MAX_RECV_PATH];
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPC_GET_FILE_NOTIFY, hd, event, retval);
    switch (event)
    {
        case BTRECV_EV_START:
            if (retval >= 0)
            {
                g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd = hd;

                mmi_bt_get_receive_info(
                    g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd,
                    (void*)obj_path,
                    BTRECV_INFO_STORAGE); //BTRECV_INFO_STORAGE; //BTRECV_INFO_OBJ_PATH; //BTRECV_INFO_OBJ_FLDR;

                /* remember the drive, used for next start */
                //g_mmi_ftp_scr_cntx_p->ftpc_recv_path[0] = obj_path[0];
                mmi_bt_get_receive_info(
                    g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd,
                    (void*)g_mmi_ftp_scr_cntx_p->ftpc_recv_path,
                    BTRECV_INFO_OBJ_FLDR);

                switch (g_mmi_ftp_scr_cntx_p->pull_type)
                {
                    case MMI_FTP_PULL_TYPE_SINGLE:
                        index = g_mmi_ftp_scr_cntx_p->sel_obj_id;
                        break;

#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
                    case MMI_FTP_PULL_TYPE_MULTI:
                        index = srv_ftpc_get_fileindex(
                            g_mmi_ftp_scr_cntx_p->ftpc_srv_hd, 
                            g_mmi_ftp_scr_cntx_p->download_list.p_obj_indexs_in_folder[g_mmi_ftp_scr_cntx.received_obj_cnt]);
                        break;

                    case MMI_FTP_PULL_TYPE_ALL:
                        index = srv_ftpc_get_fileindex(
                            g_mmi_ftp_scr_cntx_p->ftpc_srv_hd,
                            g_mmi_ftp_scr_cntx.received_obj_cnt);
                        break;
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */

                    default:
                        mmi_bt_stop_receive(g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd, BTRECV_RET_USER_ABORT);
                        return;
                }

                result = srv_ftpc_get_file(
                    g_mmi_ftp_scr_cntx_p->ftpc_srv_hd,
                    index,
                    (const U16*)obj_path);

                switch (result)
                {
                    case SRV_FTPC_GET_FILE_SUCCESS:
                        /* the single or first file */
                        if (g_mmi_ftp_scr_cntx_p->received_obj_cnt == 0)
                        {
                            mmi_ftpc_entry_recv_obj();
#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
                            if (mmi_frm_scrn_is_present(
                                    g_mmi_ftp_scr_cntx_p->subgid1,
                                    SCR_FTP_MARK_SEVERAL,
                                    MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
                            {
                                mmi_frm_scrn_close(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_MARK_SEVERAL);
                            }
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */
                        }
                        break;

                    case SRV_FTPC_GET_FILE_GOEP_STATUS_BUSY:
                        mmi_bt_stop_receive(g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd, BTRECV_RET_USER_ABORT);
                        mmi_ftpc_notify_recv_err(SRV_FTPC_NOTIFY_GOEP_STATUS_BUSY);
                        break;

                    default:
                        mmi_bt_stop_receive(g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd, BTRECV_RET_USER_ABORT);
                        mmi_ftpc_notify_recv_err(SRV_FTPC_NOTIFY_ACTION_NOT_ALLOWED);
                        break;
                }
            }
            else
            {
                g_mmi_ftp_scr_cntx_p->received_obj_cnt++;
                g_mmi_ftp_scr_cntx_p->failed_obj_cnt++;
                g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd = -1;
                mmi_ftpc_obj_receive_ind();
            }
        break;

        case BTRECV_EV_DONE:
            g_mmi_ftp_scr_cntx_p->received_obj_cnt++;
            switch (retval)
            {
                case BTRECV_RET_USER_ABORT: /* user press cancel */
                    mmi_ftpc_clear_abort_scr();
                    g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd = -1;
                    break;

                case BTRECV_RET_SUCC:
                    mmi_ftpc_get_next_file();
                    break;

                case BTRECV_RET_MEMORY_FULL:
                case BTRECV_RET_MSDC_MISSED:
                    g_mmi_ftp_scr_cntx_p->failed_obj_cnt++;
                /*     mmi_bt_get_receive_info( */
                /*         g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd, */
                /*         (void*)g_mmi_ftp_scr_cntx_p->ftpc_recv_path, */
                /*         BTRECV_INFO_OBJ_FLDR); */

                    g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd = -1;

                    mmi_ftpc_obj_receive_ind();
                    break;

                case BTRECV_RET_FAIL:
                    g_mmi_ftp_scr_cntx_p->failed_obj_cnt++;
                    mmi_ftpc_get_next_file();
                    break;

                default:
                    g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd = -1;
            }

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_get_single_file
 * DESCRIPTION
 *  Used to get the first file in list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_get_single_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_recv_obj_info file_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPC_GET_SINGLE_FILE, g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd);
    if (g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd > 0)
    {
        //kal_prompt_trace(MOD_MMI, "[FTPMMI_SCR] _mmi_ftpc_get_single_file(), re-entry");
        return;
    }
    
    
    g_mmi_ftp_scr_cntx_p->received_obj_cnt = 0;
    g_mmi_ftp_scr_cntx_p->failed_obj_cnt = 0;

    if (g_mmi_ftp_scr_cntx_p->obj_entity.actual_name_len <= MAX_SUBMENU_CHARACTERS)
    {
        file_info.name = g_mmi_ftp_scr_cntx_p->obj_entity.name;
    }
    else
    {
        file_info.name = (WCHAR*)OslMalloc((g_mmi_ftp_scr_cntx_p->obj_entity.actual_name_len + 1) * ENCODING_LENGTH);
        srv_ftpc_get_obj_detail_info(
            g_mmi_ftp_scr_cntx_p->ftpc_srv_hd,
            g_mmi_ftp_scr_cntx_p->sel_obj_id,
            (U16*)file_info.name);
    }
    
    file_info.size = g_mmi_ftp_scr_cntx_p->obj_entity.size;
    file_info.mime = NULL;
    file_info.type = 0;
    
    g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd = mmi_bt_start_receive(
        mmi_ftpc_get_file_notify,
        &file_info,
        NULL,
        BTRECV_OPT_BKGOUND);

    if (g_mmi_ftp_scr_cntx_p->obj_entity.actual_name_len > MAX_SUBMENU_CHARACTERS)
    {
        OslMfree(file_info.name);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_clear_abort_scr
 * DESCRIPTION
 *  This function is to clear aborting screens
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_clear_abort_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cur_scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur_scr_id = mmi_frm_scrn_get_active_id();
    switch (cur_scr_id)
    {
        case SCR_FTP_ABORTING:
#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
            mmi_ftpc_del_scr(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_DISCONNECTING);
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */
            mmi_ftpc_del_scr(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_ABORTING);
            return;
        
        default: /* pop up screen */
            mmi_ftpc_del_scr(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_ABORTING);
            mmi_ftpc_del_scr(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_DETAIL_INFO);
            return;
    }
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftpc_event_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hd    [IN]
 *  event    [IN]
 *  para    [IN]
 *  
 * RETURNS
 *  void
 ******************************************************************************/
static void mmi_ftpc_event_handle(S32 hd, U16 event, void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPC_EVENT_HANDLE, event);
    if (hd == g_mmi_ftp_scr_cntx_p->ftpc_srv_hd)
    {
        switch (event)
        {
        case SRV_FTPC_EVENT_CONNECT:
            mmi_ftpc_connect_rsp_hd((srv_ftpc_connect_struct*)para);
            return;

        case SRV_FTPC_EVENT_SET_FOLDER:
            mmi_ftpc_set_folder_rsp_hd((srv_ftpc_set_folder_struct*)para);
            return;

        case SRV_FTPC_EVENT_GET_FOLDER_CONTENT:
            mmi_ftpc_get_folder_content_rsp_hd((srv_ftpc_get_folder_struct*)para);
            return;

            //case SRV_FTPC_EVENT_RECEV_PROGRESSING:

        case SRV_FTPC_EVENT_GET_FILE:
            mmi_ftpc_get_file_content_rsp_hd((srv_ftpc_get_file_struct*)para);
            return;


        case SRV_FTPC_EVENT_DISCONNECT:
            mmi_ftpc_disconnect_server_rsp_hd((srv_ftpc_disconnect_struct*)para);
            return;

        default:
            break;
        }
    }
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_bt_ftpc_connect_server
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bd_addr    [IN]
 *  
 * RETURNS
 *  void
 ******************************************************************************/
void mmi_bt_ftpc_connect_server(srv_bt_cm_bt_addr bd_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 event_mask;
    S32 ftpc_tmp_hd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_BT_FTPC_CONNECT_SERVER);
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* phone drive is exported, cant use this app */
        mmi_usb_app_unavailable_popup(0); /* pass 0 will show default string */
         return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    g_mmi_ftp_scr_cntx_p->gid = mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_AUTO_GEN,
        mmi_ftpc_group_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    /* press endkey, waiting for the backgroud disconnect indication */
    ftpc_tmp_hd = srv_ftp_open(SRV_FTP_ROLE_CLIENT);
    if (ftpc_tmp_hd < 0)
    {
        mmi_popup_display_simple(
            (WCHAR*)GetString(STR_FTP_DEV_BUSY),
            MMI_EVENT_FAILURE,
            g_mmi_ftp_scr_cntx_p->gid,
            NULL);
        //mmi_frm_group_close(g_mmi_ftp_scr_cntx_p->gid);
        return;
    }

    g_mmi_ftp_scr_cntx_p->ftpc_srv_hd = ftpc_tmp_hd;
    g_mmi_ftp_scr_cntx_p->browse_depth = -1;
    g_mmi_ftp_scr_cntx_p->got_root_flag = 0;
    //g_mmi_ftp_scr_cntx_p->sel_opt_id = 0;
#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
    mmi_ftpc_free_list();
#endif
    
    event_mask = SRV_FTPC_EVENT_CONNECT | SRV_FTPC_EVENT_SET_FOLDER |
        SRV_FTPC_EVENT_GET_FOLDER_CONTENT | SRV_FTPC_EVENT_GET_FILE | SRV_FTPC_EVENT_DISCONNECT;
    srv_ftp_set_notify(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd, mmi_ftpc_event_handle, event_mask);

    if (srv_ftpc_connect_server(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd, bd_addr) == SRV_FTP_RESULT_OK)
    {
        mmi_ftpc_pre_entry_connect_scr();
    }
    else
    {
        mmi_popup_display_simple(
            (WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE), //(WCHAR*)GetString(STR_FTP_DEV_BUSY),
            MMI_EVENT_FAILURE,
            g_mmi_ftp_scr_cntx_p->gid,
            NULL);

        srv_ftp_close(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd);
        g_mmi_ftp_scr_cntx_p->ftpc_srv_hd = -1;
        //mmi_frm_group_close(g_mmi_ftp_scr_cntx_p->gid);
    }
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftpc_connect_rsp_hd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result_p    [IN]
 *  
 * RETURNS
 *  void
 ******************************************************************************/
static void mmi_ftpc_connect_rsp_hd(srv_ftpc_connect_struct* result_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPC_CONNECT_RSP_HD, result_p->connect_result);
    if (result_p->connect_result == SRV_FTPC_CONNECT_SUCCESS)
    {
        g_mmi_ftp_scr_cntx_p->browse_depth = 0;
    }
    else
    {
        if (result_p->is_abort_from_client)
        {
            mmi_ftpc_notify_recv_err(SRV_FTPC_NOTIFY_LAST);
        }
        else
        {
            /* passkey screen del callback */
            mmi_bt_reject_passkey_ind(
                result_p->bd_address.lap,
                result_p->bd_address.uap,
                result_p->bd_address.nap);

            if (result_p->connect_result == SRV_FTPC_CONNECT_SCO_REJECT)
            {
                mmi_bt_popup_operation_not_allowed();
                mmi_ftpc_notify_recv_err(SRV_FTPC_NOTIFY_LAST);
            }
            else if (result_p->connect_result == SRV_FTPC_CONNECT_REJECT_FROM_SERVER)
            {
                mmi_ftpc_notify_recv_err(SRV_FTPC_NOTIFY_REJECT_FROM_SERVER);
            }
            else //other results
            {
                mmi_ftpc_notify_recv_err(SRV_FTPC_NOTIFY_REJECT_FROM_SERVER);
            }
        }

        srv_ftp_close(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd);
        g_mmi_ftp_scr_cntx_p->ftpc_srv_hd = -1;
        mmi_ftpc_del_scr(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_CONNECTING);
        mmi_ftpc_del_scr(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_FILE_BROWSER);
        mmi_frm_group_close(g_mmi_ftp_scr_cntx_p->subgid1);
    }
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftpc_set_folder_rsp_hd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result_p    [IN]
 *  
 * RETURNS
 *  void
 ******************************************************************************/
static void mmi_ftpc_set_folder_rsp_hd(srv_ftpc_set_folder_struct* result_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPC_SET_FOLDER_RSP_HD, result_p->result);
    
    switch (result_p->result)
    {
        case SRV_FTPC_SET_FOLDER_SUCCESS:
            g_mmi_ftp_scr_cntx_p->browse_depth++;
            break;

        case SRV_FTPC_SET_FOLDER_BACK_SUCCESS:
            g_mmi_ftp_scr_cntx_p->browse_depth--;
            break;

        case SRV_FTPC_SET_FOLDER_BACK_ROOT_SUCCESS:
            g_mmi_ftp_scr_cntx_p->browse_depth = 0;
            break;

        case SRV_FTPC_SET_FOLDER_NOT_ALLOWED:
            mmi_ftpc_notify_recv_err(SRV_FTPC_NOTIFY_ACTION_NOT_ALLOWED);
            break;

        case SRV_FTPC_SET_FOLDER_REJECT_FROM_SERVER:
            mmi_ftpc_notify_recv_err(SRV_FTPC_NOTIFY_REJECT_FROM_SERVER);
            break;

        case SRV_FTPC_SET_FOLDER_BACK_FAIL:
            g_mmi_ftp_scr_cntx_p->browse_depth = 0;
            mmi_ftpc_notify_recv_err(SRV_FTPC_NOTIFY_BROWSE_FILES_FAILED);
            mmi_ftpc_addhistory(
                g_mmi_ftp_scr_cntx_p->subgid1,
                SCR_FTP_DISCONNECTING,
                (mmi_proc_func)mmi_ftpc_entry_disconnecting);
            break;

        default:
            break;
    }
}


/****************************************************************************** 
 * FUNCTION
 *  srv_ftpc_disp_folder_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status    [IN]
 *  
 * RETURNS
 *  void
 ******************************************************************************/
static void srv_ftpc_disp_folder_content(U8 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID active_scr_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, SRV_FTPC_DISP_FOLDER_CONTENT, status);

    active_scr_id = mmi_frm_scrn_get_active_id();
    if (active_scr_id == SCR_FTP_OPENING_FOLDER || active_scr_id == SCR_FTP_CONNECTING)
    {
        mmi_ftpc_entry_file_browser();
    }
    else
    {
        mmi_ftpc_browser_history_replace();
    }
    
    switch (status)
    {
        case SRV_FTPC_FOLDER_EMPTY:
            mmi_ftpc_notify_recv_err(SRV_FTPC_NOTIFY_BROWSE_FILES_FAILED);
            break;

        case SRV_FTPC_FOLDER_PARTIAL:
            mmi_ftp_popup_hdlr((UI_string_type)GetString(STR_BT_PARTIAL_CONTENT), MMI_EVENT_SUCCESS);
            break;

        case SRV_FTPC_FOLDER_FULL:
            break;

        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_get_next_file
 * DESCRIPTION
 *  when a file downloaded success, will call it to handle.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_get_next_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_recv_obj_info file_info;
    bt_recv_storage storage_info;
    U16 file_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPC_GET_NEXT_FILE);

    switch (g_mmi_ftp_scr_cntx_p->pull_type)
    {
#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
        case MMI_FTP_PULL_TYPE_ALL:
        {
            if (g_mmi_ftp_scr_cntx.received_obj_cnt < g_mmi_ftp_scr_cntx_p->file_cnt_cur_folder)
            {
                file_index = srv_ftpc_get_fileindex(
                    g_mmi_ftp_scr_cntx_p->ftpc_srv_hd,
                    g_mmi_ftp_scr_cntx.received_obj_cnt);

                srv_ftpc_get_obj_info(
                    g_mmi_ftp_scr_cntx_p->ftpc_srv_hd,
                    file_index,
                    &(g_mmi_ftp_scr_cntx_p->obj_entity));

                if (g_mmi_ftp_scr_cntx_p->obj_entity.actual_name_len <= MAX_SUBMENU_CHARACTERS)
                {
                    file_info.name = g_mmi_ftp_scr_cntx_p->obj_entity.name;
                }
                else
                {
                    file_info.name = (WCHAR*)OslMalloc(
                        (g_mmi_ftp_scr_cntx_p->obj_entity.actual_name_len + 1) * ENCODING_LENGTH);
                    srv_ftpc_get_obj_detail_info(
                        g_mmi_ftp_scr_cntx_p->ftpc_srv_hd,
                        file_index,
                        (U16*)file_info.name);
                }

                file_info.size = g_mmi_ftp_scr_cntx_p->obj_entity.size;
                file_info.mime = NULL;
                file_info.type = 0;
                storage_info.drive = (CHAR)g_mmi_ftp_scr_cntx_p->ftpc_recv_path[0];
                storage_info.folder = NULL;

                g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd = mmi_bt_start_receive(
                    mmi_ftpc_get_file_notify,
                    &file_info,
                    &storage_info,
                    BTRECV_OPT_BKGOUND);

                if (g_mmi_ftp_scr_cntx_p->obj_entity.actual_name_len > MAX_SUBMENU_CHARACTERS)
                {
                    OslMfree(file_info.name);
                }
            }
            else /* all files down completed */
            {
/*                 mmi_bt_get_receive_info( */
/*                     g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd, */
/*                     (void*)g_mmi_ftp_scr_cntx_p->ftpc_recv_path, */
/*                     BTRECV_INFO_OBJ_FLDR); */

                g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd = -1;

                mmi_ftpc_obj_receive_ind();
            }
        }
        break;

        case MMI_FTP_PULL_TYPE_MULTI:
        {
            mmi_ftpc_download_list *p_down_list = &g_mmi_ftp_scr_cntx.download_list;

            if (g_mmi_ftp_scr_cntx.received_obj_cnt < p_down_list->list_obj_cnt)
            {
                file_index = srv_ftpc_get_fileindex(
                    g_mmi_ftp_scr_cntx_p->ftpc_srv_hd,
                    p_down_list->p_obj_indexs_in_folder[g_mmi_ftp_scr_cntx.received_obj_cnt]);
                
                srv_ftpc_get_obj_info(
                    g_mmi_ftp_scr_cntx_p->ftpc_srv_hd,
                    file_index,
                    &(g_mmi_ftp_scr_cntx_p->obj_entity));

                if (g_mmi_ftp_scr_cntx_p->obj_entity.actual_name_len <= MAX_SUBMENU_CHARACTERS)
                {
                    file_info.name = g_mmi_ftp_scr_cntx_p->obj_entity.name;
                }
                else
                {
                    file_info.name = (WCHAR*)OslMalloc(
                        (g_mmi_ftp_scr_cntx_p->obj_entity.actual_name_len + 1) * ENCODING_LENGTH);
                    srv_ftpc_get_obj_detail_info(
                        g_mmi_ftp_scr_cntx_p->ftpc_srv_hd,
                        file_index,
                        (U16*)file_info.name);
                }

                file_info.size = g_mmi_ftp_scr_cntx_p->obj_entity.size;
                file_info.mime = NULL;
                file_info.type = 0;
                storage_info.drive = (CHAR)g_mmi_ftp_scr_cntx_p->ftpc_recv_path[0];
                storage_info.folder = NULL;

                g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd = mmi_bt_start_receive(
                    mmi_ftpc_get_file_notify,
                    &file_info,
                    &storage_info,
                    BTRECV_OPT_BKGOUND);

                if (g_mmi_ftp_scr_cntx_p->obj_entity.actual_name_len > MAX_SUBMENU_CHARACTERS)
                {
                    OslMfree(file_info.name);
                }
            }
            else /* all list files have downloaded */
            {
/*                 mmi_bt_get_receive_info( */
/*                     g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd, */
/*                     (void*)g_mmi_ftp_scr_cntx_p->ftpc_recv_path, */
/*                     BTRECV_INFO_OBJ_FLDR); */

                g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd = -1;

                mmi_ftpc_obj_receive_ind();
            }
        }
        break;
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */

        case MMI_FTP_PULL_TYPE_SINGLE:
/*             mmi_bt_get_receive_info( */
/*                 g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd, */
/*                 (void*)g_mmi_ftp_scr_cntx_p->ftpc_recv_path, */
/*                 BTRECV_INFO_OBJ_FLDR); */

            g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd = -1;

            mmi_ftpc_obj_receive_ind();
            break;
    }
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftpc_get_folder_content_rsp_hd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result_p    [IN]
 *  
 * RETURNS
 *  void
 ******************************************************************************/
static void mmi_ftpc_get_folder_content_rsp_hd(srv_ftpc_get_folder_struct* result_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPC_GET_FOLDER_CONTENT_RSP_HD, result_p->result, result_p->entity_cnt, result_p->file_cnt);

    g_mmi_ftp_scr_cntx_p->entity_cnt_cur_folder = result_p->entity_cnt;
#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
    g_mmi_ftp_scr_cntx_p->file_cnt_cur_folder = result_p->file_cnt;
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */

    switch (result_p->result)
    {
        case SRV_FTPC_GET_FOLDER_SUCCESS:
            srv_ftpc_disp_folder_content(SRV_FTPC_FOLDER_FULL);
            g_mmi_ftp_scr_cntx_p->got_root_flag = 1;
            break;

        case SRV_FTPC_GET_FOLDER_FAIL:
            srv_ftpc_disp_folder_content(SRV_FTPC_FOLDER_EMPTY);
            break;

        case SRV_FTPC_GET_FOLDER_PATIAL_CONTENT:
            srv_ftpc_disp_folder_content(SRV_FTPC_FOLDER_PARTIAL);
            g_mmi_ftp_scr_cntx_p->got_root_flag = 1; /* no need to judge(if (flag == 0) flag = 1)*/
            break;

        default:
            break;
    }
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftpc_get_file_content_rsp_hd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result_p    [IN]
 *  
 * RETURNS
 *  void
 ******************************************************************************/
static void mmi_ftpc_get_file_content_rsp_hd(srv_ftpc_get_file_struct* result_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPC_GET_FILE_CONTENT_RSP_HD, result_p->is_abort_from_client, result_p->result);

    UpdateRecvingScreen(SCR_FTP_RECEIVING);

    if (result_p->is_abort_from_client)
    {
        mmi_bt_stop_receive(g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd, BTRECV_RET_USER_ABORT);
#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
        mmi_ftpc_free_list();
#endif  /* __MMI_FTC_MULTIPULL_SUPPORT__ */
    }
    else
    {
        if (result_p->result == SRV_FTPC_GET_FILE_SUCCESS)
        {
            mmi_bt_stop_receive(g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd, BTRECV_RET_SUCC);
        }
        else if (result_p->result == SRV_FTPC_GET_FILE_FAIL)
        {
            mmi_bt_stop_receive(g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd, BTRECV_RET_FAIL); /* !!should use _FAIL */
        }
        else /* SRV_FTPC_GET_FILE_DISK_FULL || SRV_FTPC_GET_FILE_WRITE_FILE_FAIL || SRV_FTPC_GET_FILE_NO_CARD */
        {
            mmi_bt_stop_receive(
                g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd,
                BTRECV_RET_MSDC_MISSED);
        }
    }
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftpc_disconnect_server_rsp_hd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result_p    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
static void mmi_ftpc_disconnect_server_rsp_hd(srv_ftpc_disconnect_struct* result_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPC_DISCONNECT_SERVER_RSP_HD, 0);
    //MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPC_DISCONNECT_SERVER_RSP_HD, g_mmi_ftp_scr_cntx_p->ftpc_disconn_from_cm);
    //g_mmi_ftp_scr_cntx_p->ftpc_disconn_from_cm = 0;
    
    if (!(result_p->is_from_client))
    {
        mmi_ftpc_notify_recv_err(SRV_FTPC_NOTIFY_CONNECTION_DISCONNECTED);
    }

    if (g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd > 0)
    {
        mmi_bt_stop_receive(g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd,
                            BTRECV_RET_USER_ABORT);
    }

    srv_ftp_close(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd);
    g_mmi_ftp_scr_cntx_p->ftpc_srv_hd = -1;
    mmi_ftpc_del_scr(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_CONNECTING);
    mmi_ftpc_del_scr(g_mmi_ftp_scr_cntx_p->subgid1, SCR_FTP_FILE_BROWSER);
    mmi_frm_group_close(g_mmi_ftp_scr_cntx_p->subgid1);
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftp_client_is_receiving
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 ******************************************************************************/
MMI_BOOL mmi_ftp_client_is_receiving(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_ftpc_is_receiving();
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_bt_ftpc_disconnect_server
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bd_addr    [IN]
 *  g_conn_id    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
void mmi_bt_ftpc_disconnect_server(srv_bt_cm_bt_addr bd_addr, U32 g_conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_BT_FTPC_DISCONNECT_SERVER);
    
    srv_ftpc_disconnect_server(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd);
    //g_mmi_ftp_scr_cntx_p->ftpc_disconn_from_cm = 1;
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_bt_ftpc_is_run
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
MMI_BOOL mmi_bt_ftpc_is_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_ftpc_is_running();
}


#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
/****************************************************************************** 
 * FUNCTION
 *  mmi_ftpc_get_all_confirm_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
static mmi_ret mmi_ftpc_get_all_confirm_proc(mmi_event_struct* evt)
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
            mmi_alert_result_evt_struct* alert = (mmi_alert_result_evt_struct*)evt;
            switch(alert->result)
            {
                case MMI_ALERT_CNFM_YES:
                    mmi_ftpc_get_all_files();
                    break;

                case MMI_ALERT_CNFM_NO:
                    break;
            }
        }
        break;
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_get_all_confirm_scr
 * DESCRIPTION
 *  Display a confirm when user select to get all files
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_get_all_confirm_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FTPC_GET_ALL_CONFIRM_STR();
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = g_mmi_ftp_scr_cntx_p->subgid1;
    arg.callback = mmi_ftpc_get_all_confirm_proc;
    mmi_confirm_display(
        (WCHAR*)mmi_ftpc_notify_str,
        MMI_EVENT_QUERY,
        &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_add_to_list
 * DESCRIPTION
 *  Add a file to download list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_add_to_list(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ftpc_download_list *p_down_list = &g_mmi_ftp_scr_cntx.download_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ftpc_check_list())
    {
        p_down_list->p_obj_indexs_in_folder[p_down_list->list_obj_cnt] = index;
        p_down_list->list_obj_cnt++;
    }
    else
    {
        mmi_ftp_popup_hdlr((UI_string_type)GetString(STR_FTP_LIST_ARRIVE_MAX), MMI_EVENT_FAILURE);
    }
}




/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_get_list_files
 * DESCRIPTION
 *  Used to get the first file in list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_get_list_files(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ftpc_download_list* p_down_list = &g_mmi_ftp_scr_cntx_p->download_list;
    bt_recv_obj_info file_info;
    U16 file_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_FTP_TRC_CLASS,
        MMI_FTPC_GET_LIST_FILES,
        g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd,
        p_down_list->list_obj_cnt);

    if (g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd > 0)
    {
        //kal_prompt_trace(MOD_MMI, "[FTPMMI_SCR] mmi_ftpc_get_list_files(), re-entry");
        return;
    }

    g_mmi_ftp_scr_cntx_p->pull_type = MMI_FTP_PULL_TYPE_MULTI;
    g_mmi_ftp_scr_cntx_p->received_obj_cnt = 0;
    g_mmi_ftp_scr_cntx.failed_obj_cnt = 0;

    file_index = srv_ftpc_get_fileindex(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd, p_down_list->p_obj_indexs_in_folder[0]);
    srv_ftpc_get_obj_info(
        g_mmi_ftp_scr_cntx_p->ftpc_srv_hd,
        file_index,
        &(g_mmi_ftp_scr_cntx_p->obj_entity));

    if (g_mmi_ftp_scr_cntx_p->obj_entity.actual_name_len <= MAX_SUBMENU_CHARACTERS)
    {
        file_info.name = g_mmi_ftp_scr_cntx_p->obj_entity.name;
    }
    else
    {
        file_info.name = (WCHAR*)OslMalloc((g_mmi_ftp_scr_cntx_p->obj_entity.actual_name_len + 1) * ENCODING_LENGTH);
        srv_ftpc_get_obj_detail_info(
            g_mmi_ftp_scr_cntx_p->ftpc_srv_hd,
            file_index,
            (U16*)file_info.name);
    }

    file_info.size = g_mmi_ftp_scr_cntx_p->obj_entity.size;
    file_info.mime = NULL;
    file_info.type = 0;

    g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd = mmi_bt_start_receive(
        mmi_ftpc_get_file_notify,
        &file_info,
        NULL,
        BTRECV_OPT_BKGOUND);

    if (g_mmi_ftp_scr_cntx_p->obj_entity.actual_name_len > MAX_SUBMENU_CHARACTERS)
    {
        OslMfree(file_info.name);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_get_all_files
 * DESCRIPTION
 *  Used to get the first file when user select get all files
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_get_all_files(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_recv_obj_info file_info;
    U16 file_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_FTP_TRC_CLASS,
        MMI_FTPC_GET_ALL,
        g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd,
        g_mmi_ftp_scr_cntx_p->file_cnt_cur_folder);

    if (g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd > 0)
    {
        //kal_prompt_trace(MOD_MMI, "[FTPMMI_SCR] mmi_ftpc_get_all_files(), re-entry");
        return;
    }

    g_mmi_ftp_scr_cntx_p->pull_type = MMI_FTP_PULL_TYPE_ALL;
    //g_mmi_ftp_scr_cntx_p->curent_file_id = 0;
    g_mmi_ftp_scr_cntx_p->received_obj_cnt = 0;
    g_mmi_ftp_scr_cntx.failed_obj_cnt = 0;

    file_index = srv_ftpc_get_fileindex(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd, 0);
    srv_ftpc_get_obj_info(
        g_mmi_ftp_scr_cntx_p->ftpc_srv_hd,
        file_index,
        &(g_mmi_ftp_scr_cntx_p->obj_entity));

    if (g_mmi_ftp_scr_cntx_p->obj_entity.actual_name_len <= MAX_SUBMENU_CHARACTERS)
    {
        file_info.name = g_mmi_ftp_scr_cntx_p->obj_entity.name;
    }
    else
    {
        file_info.name = (WCHAR*)OslMalloc((g_mmi_ftp_scr_cntx_p->obj_entity.actual_name_len + 1) * ENCODING_LENGTH);
        srv_ftpc_get_obj_detail_info(
            g_mmi_ftp_scr_cntx_p->ftpc_srv_hd,
            file_index,
            (U16*)file_info.name);
    }
        
    file_info.size = g_mmi_ftp_scr_cntx_p->obj_entity.size;
    file_info.mime = NULL;
    file_info.type = 0;

    g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd = mmi_bt_start_receive(
        mmi_ftpc_get_file_notify,
        &file_info,
        NULL,
        BTRECV_OPT_BKGOUND);

    if (g_mmi_ftp_scr_cntx_p->obj_entity.actual_name_len > MAX_SUBMENU_CHARACTERS)
    {
        OslMfree(file_info.name);
    }
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftpc_find_next_file_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 ******************************************************************************/
/* static MMI_BOOL mmi_ftpc_find_next_file_index(void) */
/* { */
/*     /\*----------------------------------------------------------------*\/ */
/*     /\* Local Variables                                                *\/ */
/*     /\*----------------------------------------------------------------*\/ */
/*     U16 i; */
    
/*     /\*----------------------------------------------------------------*\/ */
/*     /\* Code Body                                                      *\/ */
/*     /\*----------------------------------------------------------------*\/ */
/*     MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPC_FIND_NEXT_FILE_INDEX); */
/*     for (i = g_mmi_ftp_scr_cntx_p->curent_file_id; i < g_mmi_ftp_scr_cntx_p->entity_cnt_cur_folder; ++i) */
/*     { */
/*         if (srv_ftpc_get_obj_info(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd, */
/*                                   i, */
/*                                   &(g_mmi_ftp_scr_cntx_p->obj_entity)) >= FS_NO_ERROR) */
/*         { */
/*             if (SRV_FTP_OBJ_TYPE_FILE == g_mmi_ftp_scr_cntx_p->obj_entity.type) */
/*             { */
/*                 g_mmi_ftp_scr_cntx_p->curent_file_id = i; */
/*                 return MMI_TRUE; */
/*             } */
/*         } */
/*     } */

/*     return MMI_FALSE; */
/* } */


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_list_option_delete
 * DESCRIPTION
 *  used to delete the hilited file in list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_list_option_delete(U16 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, idx;
    mmi_ftpc_download_list* p_down_list = &g_mmi_ftp_scr_cntx.download_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPC_LIST_OPTION_DELETE, item_index);
    for (i = 0, idx = 0xFFFF; i < p_down_list->list_obj_cnt; ++i)
    {
        if (p_down_list->p_obj_indexs_in_folder[i] == item_index)
        {
            idx = i;
            break;
        }
    }

    if (idx < p_down_list->list_obj_cnt)
    {
        for (i = idx + 1; i < p_down_list->list_obj_cnt; ++i)
        {
            p_down_list->p_obj_indexs_in_folder[i - 1] = p_down_list->p_obj_indexs_in_folder[i];
        }

        if (--p_down_list->list_obj_cnt == 0)
        {
            mmi_ftpc_free_list();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_check_list
 * DESCRIPTION
 *  This is function to check the list when user add a file to list
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_ftpc_check_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ftpc_download_list* p_down_list = &g_mmi_ftp_scr_cntx.download_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPC_CHECK_LIST);

    /* now, if a list have no obj, the buffer will be freed, we have no empty list */
    /* if list does not exist */
    if (p_down_list->p_obj_indexs_in_folder == NULL)
    {
        p_down_list->p_obj_indexs_in_folder = get_ctrl_buffer(MMI_FTPC_MULPULL_LIST_INIT * sizeof(U16));
        p_down_list->list_capability = MMI_FTPC_MULPULL_LIST_INIT;
        p_down_list->list_obj_cnt = 0;
    }
    else if (p_down_list->list_capability == p_down_list->list_obj_cnt)
    {
        if ((p_down_list->list_capability + MMI_FTPC_MULPULL_LIST_INC) <= MMI_FTPC_MULPULL_LIST_MAX)
        {
            /* allocate new buffer and copy the data */
            U16* p_new_list = get_ctrl_buffer((p_down_list->list_capability + MMI_FTPC_MULPULL_LIST_INC) * sizeof(U16));

            memcpy(p_new_list, p_down_list->p_obj_indexs_in_folder, p_down_list->list_capability * sizeof(U16));

            /* free old buffer */
            free_ctrl_buffer(p_down_list->p_obj_indexs_in_folder);
            p_down_list->p_obj_indexs_in_folder = p_new_list;
            p_down_list->list_capability += MMI_FTPC_MULPULL_LIST_INC;
        }
        else
        {
            return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftpc_free_list
 * DESCRIPTION
 *  This is function to delete the list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftpc_free_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ftpc_download_list *p_down_list = &g_mmi_ftp_scr_cntx.download_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPC_FREE_LIST);
    if (p_down_list->p_obj_indexs_in_folder)
    {
        free_ctrl_buffer(p_down_list->p_obj_indexs_in_folder);
        p_down_list->p_obj_indexs_in_folder = NULL;
    }

    p_down_list->list_capability = 0;
    p_down_list->list_obj_cnt = 0;
}


static void mmi_ftpc_show_get_several_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_ftp_scr_cntx_p->get_several_menu_gid = cui_menu_create(
        g_mmi_ftp_scr_cntx_p->subgid1, 
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_OPTION,
        MENU_CONN_FTP_GET_SEVERAL_OPTION,
        MMI_TRUE,
        (void*)g_mmi_ftp_scr_cntx_p);

    if (g_mmi_ftp_scr_cntx_p->get_several_menu_gid != GRP_ID_INVALID)
    {
        //cui_menu_enable_cascading_option_menu(menu_gid);

        cui_menu_set_currlist_title(
            g_mmi_ftp_scr_cntx_p->get_several_menu_gid,
            (WCHAR*)GetString(STR_GLOBAL_OPTIONS),
            (UI_image_type)GetImage(GetRootTitleIcon(MENU_CONN_BT_MAIN)));
        /* cui_menu_set_currlist_left_softkey( */
        /*     g_mmi_ftp_scr_cntx_p->get_several_menu_gid, */
        /*     (WCHAR*)GetString(STR_GLOBAL_OK)); */
        /* cui_menu_set_currlist_right_softkey( */
        /*     g_mmi_ftp_scr_cntx_p->get_several_menu_gid, */
        /*     (WCHAR*)GetString(STR_GLOBAL_BACK)); */

        if (mmi_ftpc_is_file_in_marked_list(g_mmi_ftp_scr_cntx_p->mark_several_highlight_index))
        {
            cui_menu_set_item_hidden(
                g_mmi_ftp_scr_cntx_p->get_several_menu_gid,
                MENU_CONN_FTP_GET_SEVERAL_MARK,
                MMI_TRUE);
            cui_menu_set_item_hidden(
                g_mmi_ftp_scr_cntx_p->get_several_menu_gid,
                MENU_CONN_FTP_GET_SEVERAL_UNMARK,
                MMI_FALSE);
            cui_menu_set_item_hidden(
                g_mmi_ftp_scr_cntx_p->get_several_menu_gid,
                MENU_CONN_FTP_GET_SEVERAL_UNMARK_ALL,
                MMI_FALSE);
            cui_menu_set_item_hidden(
                g_mmi_ftp_scr_cntx_p->get_several_menu_gid,
                MENU_CONN_FTP_GET_SEVERAL_GET_MARKED_FILE,
                MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(
                g_mmi_ftp_scr_cntx_p->get_several_menu_gid,
                MENU_CONN_FTP_GET_SEVERAL_MARK,
                MMI_FALSE);

            cui_menu_set_item_hidden(
                g_mmi_ftp_scr_cntx_p->get_several_menu_gid,
                MENU_CONN_FTP_GET_SEVERAL_UNMARK,
                MMI_TRUE);

            if (g_mmi_ftp_scr_cntx.download_list.list_obj_cnt == 0)
            {
                cui_menu_set_item_hidden(
                    g_mmi_ftp_scr_cntx_p->get_several_menu_gid,
                    MENU_CONN_FTP_GET_SEVERAL_UNMARK_ALL,
                    MMI_TRUE);

                cui_menu_set_item_hidden(
                    g_mmi_ftp_scr_cntx_p->get_several_menu_gid,
                    MENU_CONN_FTP_GET_SEVERAL_GET_MARKED_FILE,
                    MMI_TRUE);
            }
            else
            {
                cui_menu_set_item_hidden(
                    g_mmi_ftp_scr_cntx_p->get_several_menu_gid,
                    MENU_CONN_FTP_GET_SEVERAL_UNMARK_ALL,
                    MMI_FALSE);

                cui_menu_set_item_hidden(
                    g_mmi_ftp_scr_cntx_p->get_several_menu_gid,
                    MENU_CONN_FTP_GET_SEVERAL_GET_MARKED_FILE,
                    MMI_FALSE);
            }
        }

        cui_menu_run(g_mmi_ftp_scr_cntx_p->get_several_menu_gid);
    }
}



static MMI_BOOL mmi_ftpc_is_file_in_marked_list(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ftpc_download_list *p_down_list = &g_mmi_ftp_scr_cntx.download_list;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < p_down_list->list_obj_cnt; ++i)
    {
        if (p_down_list->p_obj_indexs_in_folder[i] == index)
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


static S32 mmi_ftpc_mark_several_get_state(S32 item_index, PU8 *checkbox_image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *checkbox_image = mmi_ftpc_is_file_in_marked_list((U16)item_index) ?
        (PU8)GetImage(CHECKBOX_ON_IMAGE_ID) :
        (PU8)GetImage(CHECKBOX_OFF_IMAGE_ID);
    return MMI_TRUE;
}


static S32 mmi_ftpc_mark_several_set_state(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ftpc_is_file_in_marked_list((U16)item_index))
    {
        mmi_ftpc_list_option_delete((U16)item_index);
    }
    else
    {
        mmi_ftpc_add_to_list((U16)item_index);
    }

    return MMI_TRUE;
}


static void mmi_ftpc_mark_several_highlight_hdlr(S32 item_index)
{
    g_mmi_ftp_scr_cntx_p->mark_several_highlight_index = (U16)item_index;
}


pBOOL mmi_ftpc_get_mark_several_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 file_index;
    mmi_fmgr_filetype_enum type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_index = srv_ftpc_get_fileindex(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd, (U16)item_index);
    if (srv_ftpc_get_obj_info(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd,
                              file_index,
                              &(g_mmi_ftp_scr_cntx_p->obj_entity))
        >= FS_NO_ERROR)
    {
        mmi_wcsncpy((U16*)str_buff, (const U16*)g_mmi_ftp_scr_cntx_p->obj_entity.name, MAX_SUBMENU_CHARACTERS);
        if (g_mmi_ftp_scr_cntx_p->obj_entity.actual_name_len > MAX_SUBMENU_CHARACTERS)
        {
            str_buff[MAX_SUBMENU_CHARACTERS - 3] = 0x002E;
            str_buff[MAX_SUBMENU_CHARACTERS - 2] = 0x002E;
            str_buff[MAX_SUBMENU_CHARACTERS - 1] = 0x002E;
        }

        type = srv_fmgr_types_find_type_by_filename_str((WCHAR*)(g_mmi_ftp_scr_cntx_p->obj_entity.name));

        *img_buff_p = (PU8)GetImage((U16)srv_fmgr_types_get_icon(type, NULL, SRV_FMGR_TYPES_ICON_SMALL));

        srv_fmgr_path_hide_extension((WCHAR*)str_buff);
    }

    return MMI_TRUE;
}


static void mmi_ftpc_leave_mark_several_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ftpc_free_list();
    mmi_frm_scrn_close_active_id();
}

static void mmi_ftpc_mark_unmark_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPC_MARK_UNMARK_CHANGE, g_mmi_ftp_scr_cntx_p->mark_several_highlight_index);
    mmi_ftpc_mark_several_set_state((S32)g_mmi_ftp_scr_cntx_p->mark_several_highlight_index);
    RedrawCategoryFunction();
}


static void mmi_ftpc_entry_mark_several_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(g_mmi_ftp_scr_cntx_p->subgid1,
                           SCR_FTP_MARK_SEVERAL,
                           NULL,
                           mmi_ftpc_entry_mark_several_screen,
                           MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
        RegisterHighlightHandler(mmi_ftpc_mark_several_highlight_hdlr);

        ShowCategory384Screen(
            (UI_string_type)GetString(STR_FTP_FILE_BROWSER),
            (PU8)GetImage(GetRootTitleIcon(MENU_CONN_BT_MAIN)),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            NULL,
            g_mmi_ftp_scr_cntx_p->file_cnt_cur_folder,
            mmi_ftpc_get_mark_several_item,
            NULL,
            mmi_ftpc_mark_several_get_state,
            mmi_ftpc_mark_several_set_state,
            0,
            gui_buffer);

        SetLeftSoftkeyFunction(mmi_ftpc_show_get_several_options, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_ftpc_leave_mark_several_screen, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_MARK_CSK);
        SetCenterSoftkeyFunction(mmi_ftpc_mark_unmark_change, KEY_EVENT_UP);
/* #ifdef __MMI_FTE_SUPPORT__ */
/*         wgui_register_tap_callback(mmi_ftpc_tap_get_several_callback_function); */
/* #endif /\* __MMI_FTE_SUPPORT__ *\/ */
    }
}


static void mmi_ftpc_get_several_option_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_MENU_ID menu_id = ((cui_menu_event_struct*)evt)->highlighted_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPC_GET_SEVERAL_OPTION_HDLR, menu_id);
    switch (menu_id)
    {
        case MENU_CONN_FTP_GET_SEVERAL_MARK:
        case MENU_CONN_FTP_GET_SEVERAL_UNMARK:
            mmi_ftpc_mark_several_set_state((S32)g_mmi_ftp_scr_cntx_p->mark_several_highlight_index);
            mmi_frm_scrn_close_active_id();
            break;

        case MENU_CONN_FTP_GET_SEVERAL_UNMARK_ALL:
            mmi_ftpc_free_list();
            mmi_frm_scrn_close_active_id();
            break;
                        
        case MENU_CONN_FTP_GET_SEVERAL_GET_MARKED_FILE:
            mmi_ftpc_get_list_files();
            //mmi_frm_scrn_close_active_id();
            break;

        default:
            mmi_frm_scrn_close_active_id();
    }
}
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftpc_recv_get_obj_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj_info_p    [IN]
 *  
 * RETURN VALUE LIST
 *  
 ******************************************************************************/
static void mmi_ftpc_recv_get_obj_info(mmi_bt_recv_obj_info_struct *obj_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_ftp_scr_cntx_p->pull_type)
    {
        case MMI_FTP_PULL_TYPE_SINGLE:
            obj_info_p->cur_obj_num = 1;
            obj_info_p->total_obj_num = 1;
            break;
            
#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
        case MMI_FTP_PULL_TYPE_MULTI:
            obj_info_p->cur_obj_num = g_mmi_ftp_scr_cntx.received_obj_cnt + 1;
            obj_info_p->total_obj_num = g_mmi_ftp_scr_cntx.download_list.list_obj_cnt;
            break;
            
        case MMI_FTP_PULL_TYPE_ALL:
            obj_info_p->cur_obj_num = g_mmi_ftp_scr_cntx.received_obj_cnt + 1;
            obj_info_p->total_obj_num = g_mmi_ftp_scr_cntx_p->file_cnt_cur_folder;
        break;
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */
    }

    obj_info_p->total_obj_size = srv_ftpc_get_total_obj_size();
    obj_info_p->recv_obj_size = srv_ftpc_get_recved_obj_size();
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftpc_convert_filesize_to_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size    [IN]
 *  dest_str    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
static void mmi_ftpc_convert_filesize_to_string(U32 size, U16 *dest_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (size >= (1 << 30))
    {
        size = size >> 20; //size /= (1024 * 1024);
        kal_wsprintf((WCHAR*)dest_str,
                     "%d.%dG",
                     (U16)(size >> 10),
                     (U16)((size & 0x03FF) / 103)); //(U16)((size % 1024) / 103));
    }
    else if (size >= (1 << 20))
    {
        size = size >> 10;
        kal_wsprintf((WCHAR*)dest_str,
                     "%d.%dM",
                     (U16)(size >> 10),
                     (U16)((size & 0x03FF) / 103));
    }
    else if (size >= (1 << 10))
    {
        kal_wsprintf((WCHAR*)dest_str,
                     "%d.%dK",
                     (U16)(size >> 10),
                     (U16)((size & 0x03FF) / 103));
    }
    else
    {
        kal_wsprintf((WCHAR*)dest_str, "%dB", (U16)(size));
    }
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/****************************************************************************** 
 * FUNCTION
 *  mmi_ftpc_tap_intuitive_command
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
static void mmi_ftpc_tap_intuitive_command(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ftpc_change_folder(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd, g_mmi_ftp_scr_cntx_p->sel_obj_id) == SRV_FTP_RESULT_OK)
    {
        mmi_ftpc_entry_opening_folder();
    }
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftpc_file_browser_current_item_with_intuitive_command
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
static MMI_BOOL mmi_ftpc_file_browser_current_item_with_intuitive_command(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_ftpc_get_obj_info(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd,
                                   g_mmi_ftp_scr_cntx_p->sel_obj_id,
                                   &(g_mmi_ftp_scr_cntx_p->obj_entity));
    if ((result >= FS_NO_ERROR) &&
        (g_mmi_ftp_scr_cntx_p->obj_entity.type == SRV_FTP_OBJ_TYPE_FOLDER))
    {
            return MMI_TRUE;
    }
    
    return MMI_FALSE;
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftpc_tap_file_browser_callback_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tap_type    [IN]
 *  index       [IN]
 *  
 * RETURNS
 *  void
 ******************************************************************************/
static void mmi_ftpc_tap_file_browser_callback_function(mmi_tap_type_enum tap_type, S32 index)
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

    if (mmi_ftpc_file_browser_current_item_with_intuitive_command(index))
    {
        {
            mmi_ftpc_tap_intuitive_command();
        }
    }
    else if (wgui_category_if_pop_option_menu())
    {
        mmi_ftpc_show_file_browser_options();
    }
}


/* static void mmi_ftpc_tap_get_several_callback_function(mmi_tap_type_enum tap_type, S32 index) */
/* { */
/*     if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM) */
/*     { */
/*         return; */
/*     } */

/*     mmi_ftpc_mark_unmark_change(); */
/* } */

#endif  // defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)

#endif /* __MMI_FTC_SUPPORT__ */


#ifdef __MMI_FTS_SUPPORT__
/****************************************************************************** 
 * FUNCTION
 *  mmi_bt_ftps_activate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
// void mmi_bt_ftps_activate(void)
// {
//     /*----------------------------------------------------------------*/
//     /* Local Variables                                                */
//     /*----------------------------------------------------------------*/
//     U16 event_mask;
    
//     /*----------------------------------------------------------------*/
//     /* Code Body                                                      */
//     /*----------------------------------------------------------------*/
//     g_mmi_ftp_scr_cntx_p->ftps_srv_hd = srv_ftp_open(SRV_FTP_ROLE_SERVER);
//     if (g_mmi_ftp_scr_cntx_p->ftps_srv_hd > SRV_FTP_SERVER_HANDLE_DOMAIN)
//     {
//         event_mask = SRV_FTPS_EVENT_START | SRV_FTPS_EVENT_STOP | SRV_FTPS_EVENT_CONNECT |
//             SRV_FTPS_EVENT_AUTHORIZE | SRV_FTPS_EVENT_DISCONNECT | SRV_FTPS_EVENT_OPERATION_BEGIN |
//             SRV_FTPS_EVENT_OPERATION_END;
//         srv_ftp_set_notify(g_mmi_ftp_scr_cntx_p->ftps_srv_hd, mmi_ftps_event_handle, event_mask);
//     }

//     srv_ftps_activate(g_mmi_ftp_scr_cntx_p->ftps_srv_hd);

//     MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_BT_FTPS_ACTIVATE, g_mmi_ftp_scr_cntx_p->ftps_srv_hd);
// }


/****************************************************************************** 
 * FUNCTION
 *  mmi_bt_ftps_deactivate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
// void mmi_bt_ftps_deactivate(void)
// {
//     /*----------------------------------------------------------------*/
//     /* Local Variables                                                */
//     /*----------------------------------------------------------------*/

//     /*----------------------------------------------------------------*/
//     /* Code Body                                                      */
//     /*----------------------------------------------------------------*/
//     MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_BT_FTPS_DEACTIVATE);
//     srv_ftps_deactivate(g_mmi_ftp_scr_cntx_p->ftps_srv_hd);
// }


/****************************************************************************** 
 * FUNCTION
 *  mmi_bt_ftps_disconnect_client
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bd_addr    [IN]
 *  g_conn_id    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
void mmi_bt_ftps_disconnect_client(srv_bt_cm_bt_addr bd_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_BT_FTPS_DISCONNECT_CLIENT);
    srv_ftps_disconnect_client(bd_addr);
    g_mmi_ftp_scr_cntx_p->ftps_disconn_from_cm = 1;
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftps_event_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hd    [IN]
 *  event    [IN]
 *  para    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
static void mmi_ftps_event_handle(S32 hd, U16 event, void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPS_EVENT_HANDLE, event);
    if (hd == g_mmi_ftp_scr_cntx_p->ftps_srv_hd)
    {
        switch (event)
        {
            case SRV_FTPS_EVENT_START:
                mmi_ftps_start_ind_handle((srv_ftps_start_indication_struct*)para);
                break;

            case SRV_FTPS_EVENT_STOP:
                mmi_ftps_stop_ind_handle(para);
                break;

            case SRV_FTPS_EVENT_AUTHORIZE:
                mmi_ftps_authorize_ind_handle((srv_ftps_authorize_indication_struct*)para);
                break;

            case SRV_FTPS_EVENT_CONNECT:
                mmi_ftps_connect_ind_handle((srv_ftps_connect_indication_struct*)para);
                break;

            case SRV_FTPS_EVENT_DISCONNECT:
                mmi_ftps_disconnect_ind_handle((srv_ftps_disconnect_indication_struct*)para);
                break;

            case SRV_FTPS_EVENT_OPERATION_BEGIN:
                mmi_ftps_operation_begin_ind_handle((srv_ftps_operation_begin_struct*)para);
                break;

            case SRV_FTPS_EVENT_OPERATION_END:
                mmi_ftps_operation_end_ind_handle((srv_ftps_operation_end_struct*)para);
                break;

            default:
                break;
        }
    }
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftps_start_ind_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_ind_p    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
static void mmi_ftps_start_ind_handle(srv_ftps_start_indication_struct* start_ind_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPS_START_IND_HANDLE, start_ind_p->result);
//     if (start_ind_p->result == SRV_FTPS_START_OK)
//     {
//         g_mmi_ftp_scr_cntx_p->ftps_srv_hd = srv_ftp_open(SRV_FTP_ROLE_SERVER);
//         if (g_mmi_ftp_scr_cntx_p->ftps_srv_hd > SRV_FTP_SERVER_HANDLE_DOMAIN)
//         {
//             event_mask = SRV_FTPS_EVENT_START | SRV_FTPS_EVENT_STOP | SRV_FTPS_EVENT_CONNECT |
//                 SRV_FTPS_EVENT_AUTHORIZE | SRV_FTPS_EVENT_DISCONNECT | SRV_FTPS_EVENT_OPERATION_BEGIN |
//                 SRV_FTPS_EVENT_OPERATION_END;
//             srv_ftp_set_notify(g_mmi_ftp_scr_cntx_p->ftps_srv_hd, mmi_ftps_event_handle, event_mask);
//         }
//     }
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftps_stop_ind_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para    [IN]
 *  
 * RETURNS
 *  void
 ******************************************************************************/
static void mmi_ftps_stop_ind_handle(void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPS_STOP_IND_HANDLE);
    //srv_ftp_close(g_mmi_ftp_scr_cntx_p->ftps_srv_hd);
    //g_mmi_ftp_scr_cntx_p->ftps_srv_hd = -1;
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftps_authorize_rsp_hdler
 * DESCRIPTION
 *  register callback in CM callback function table
 * PARAMETERS
 *  bd_addr    [IN]
 *  result    [IN]
 *  
 * RETURNS
 *  void
 ******************************************************************************/
static void mmi_ftps_authorize_rsp_hdler(srv_bt_cm_bt_addr* bd_addr, U32 profile_id, U32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_BTH_FTPS_CONNECTION_AUTHORIZE_RSP_HDLER, result);
    if (profile_id == SRV_BT_CM_OBEX_FILE_TRANSFER_UUID)
    {
        if (result == 1)
        {
            srv_ftps_authorize_accept(g_mmi_ftp_scr_cntx_p->ftps_srv_hd);
        }
        else
        {
            srv_ftps_authorize_reject(g_mmi_ftp_scr_cntx_p->ftps_srv_hd);
        }
    }
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftps_authorize_ind_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  authorize_ind_p    [IN]
 *  
 * RETURNS
 *  void
 ******************************************************************************/
static void mmi_ftps_authorize_ind_handle(srv_ftps_authorize_indication_struct* authorize_ind_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPS_AUTHORIZE_IND_HANDLE);

#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* it is better not show this popup, could be a change feature */
        //mmi_usb_app_unavailable_popup(0); /* pass 0 will show default string */
        srv_ftps_authorize_reject(g_mmi_ftp_scr_cntx_p->ftps_srv_hd);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    mmi_bt_authorize_ind_notify(
        authorize_ind_p->dev_name_p,
        &authorize_ind_p->bd_address,
        SRV_BT_CM_OBEX_FILE_TRANSFER_UUID,
        (void*)mmi_ftps_authorize_rsp_hdler);
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftps_connect_ind_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  connect_ind_p    [IN]
 *  
 * RETURNS
 *  void
 ******************************************************************************/
static void mmi_ftps_connect_ind_handle(srv_ftps_connect_indication_struct* connect_ind_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* call connect ind hdlr to notify CM */
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPS_CONNECT_IND_HANDLE);
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftps_disconnect_ind_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dis_ind_p    [IN]
 *  
 * RETURNS
 *  void
 ******************************************************************************/
static void mmi_ftps_disconnect_ind_handle(srv_ftps_disconnect_indication_struct* dis_ind_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPS_DISCONNECT_IND_HANDLE, g_mmi_ftp_scr_cntx_p->ftps_disconn_from_cm);
//     if (g_mmi_ftp_scr_cntx_p->ftps_disconn_from_cm == 0)
//     {
//         srv_bt_cm_disconnect_ind_hdler(
//             (srv_bt_cm_bt_addr*)&dis_ind_p->bd_address,
//             (U32)SRV_BT_CM_OBEX_FILE_TRANSFER_UUID,
//             (U32)dis_ind_p->cm_conn_id);
//     }
//     else
//     {
//         srv_bt_cm_disconnect_cnf_hdler(
//             MMI_TRUE,
//             (srv_bt_cm_bt_addr*)&dis_ind_p->bd_address,
//             (U32)SRV_BT_CM_OBEX_FILE_TRANSFER_UUID,
//             (U32)dis_ind_p->cm_conn_id);
//     }
    mmi_bt_authorize_screen_close(SRV_BT_CM_OBEX_FILE_TRANSFER_UUID);

    g_mmi_ftp_scr_cntx_p->ftps_disconn_from_cm = 0;
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftps_read_error_flag_and_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  error_flag    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
static void mmi_ftps_read_error_flag_and_popup(U32 error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPS_READ_ERROR_FLAG_AND_POPUP, error_flag);
    if (SRV_FTP_MASK_ROOT_DIR_FULL == error_flag)
    {
        mmi_ftps_popup(SRV_FTP_MASK_ROOT_DIR_FULL);
    }
    else if (SRV_FTP_MASK_DISK_FULL == error_flag)
    {
        mmi_ftps_popup(SRV_FTP_MASK_DISK_FULL);
    }
#ifdef __USB_IN_NORMAL_MODE__
    else if (SRV_FTP_MASK_DEVICE_EXPORTED == error_flag)
    {
        /* phone drive is exported, cant use this app */
        mmi_usb_app_unavailable_popup(0); /* pass 0 will show default string */
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    else if ((SRV_FTP_MASK_FS_DEVICE_BUSY == error_flag)
             || (SRV_FTP_MASK_FS_LOCK_MUTEX_FAIL == error_flag))
    {
        mmi_ftps_popup(SRV_FTP_MASK_FS_DEVICE_BUSY);
    }
    else if (SRV_FTP_MASK_FS_NO_CARD == error_flag)
    {
        mmi_ftps_popup(SRV_FTP_MASK_FS_NO_CARD);
    }
    else if (SRV_FTP_MASK_FS_WRITE_PROTEC == error_flag)
    {
        mmi_ftps_popup(SRV_FTP_MASK_FS_WRITE_PROTEC);
    }
    else if (error_flag == SRV_FTP_MASK_WRITE_FILE_FAIL)
    {
        mmi_ftps_popup(SRV_FTP_MASK_WRITE_FILE_FAIL);
    }
    /* SRV_FTP_MASK_RESULT_FAIL will not show popup */
}


static void mmi_ftps_push_file_notify(S32 hd, U32 event, S32 retval)
{
    WCHAR obj_path[SRV_FMGR_PATH_MAX_LEN + 1];
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPS_PUSH_FILE_NOTIFY, event, retval);
    
    switch (event)
    {
        case BTRECV_EV_START:
            //kal_prompt_trace(MOD_MMI, "mmi_ftps_push_file_notify(), start:retval = %d", retval);
            if (retval >= 0)
            {
                g_mmi_ftp_scr_cntx_p->ftps_start_recv_hd = hd;
                mmi_bt_get_receive_info(
                    g_mmi_ftp_scr_cntx_p->ftps_start_recv_hd,
                    (void*)obj_path,
                    BTRECV_INFO_STORAGE);

                srv_ftps_accept_push_obj(g_mmi_ftp_scr_cntx_p->ftps_srv_hd, 1, (U16*)obj_path);

            }
            else
            {
                srv_ftps_reject_push_obj(g_mmi_ftp_scr_cntx_p->ftps_srv_hd, 1);
                switch(retval)
                {
                    case BTRECV_RET_MEMORY_FULL:
                        mmi_ftps_read_error_flag_and_popup(SRV_FTP_MASK_DISK_FULL);
                        break;

                    case BTRECV_RET_MSDC_MISSED:
                        mmi_ftps_read_error_flag_and_popup(SRV_FTP_MASK_FS_NO_CARD);
                        break;
                }
            }
        break;

        case BTRECV_EV_DONE:
            g_mmi_ftp_scr_cntx_p->ftps_start_recv_hd = -1;
            switch (retval)
            {
                case BTRECV_RET_SUCC:
                    break;
                
                case BTRECV_RET_USER_ABORT:
                    break;

                case BTRECV_RET_MEMORY_FULL:
                    mmi_ftps_read_error_flag_and_popup(SRV_FTP_MASK_DISK_FULL);
                    break;

                case BTRECV_RET_MSDC_MISSED:
                    mmi_ftps_read_error_flag_and_popup(SRV_FTP_MASK_FS_NO_CARD);
                    break;

                case BTRECV_RET_FAIL:
                    mmi_ftp_popup_hdlr((UI_string_type)GetString(STR_BT_RECEIVE_FAIL), MMI_EVENT_FAILURE);
                    break;

                default:
                    mmi_ftps_read_error_flag_and_popup(retval);
                    break;
            }
            break;
            
/*         default: */
/*             break; */
    }
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftps_operation_push_ind_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  op_begin_ind_p    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
static void mmi_ftps_operation_push_begin_ind_handle(srv_ftps_operation_begin_struct* op_begin_ind_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_recv_obj_info file_info;
    bt_recv_storage storage_info;
    U16* path_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPS_OPERATION_PUSH_BEGIN_IND_HANDLE, op_begin_ind_p->result);
    if (mmi_bt_receiving_disabled())
    {
        srv_ftps_reject_push_obj(g_mmi_ftp_scr_cntx_p->ftps_srv_hd, 1);
        return;
    }

    if (op_begin_ind_p->result != SRV_FTP_MASK_RESULT_OK)
    {
        srv_ftps_reject_push_obj(g_mmi_ftp_scr_cntx_p->ftps_srv_hd, 1);
        mmi_ftps_read_error_flag_and_popup(op_begin_ind_p->result);
    }
    else
    {
        file_info.name = op_begin_ind_p->name_p;
        file_info.size = op_begin_ind_p->obj_total_size;
        file_info.mime = NULL;
        file_info.type = 0;

        path_p = srv_ftps_get_current_folder();
        storage_info.drive = (CHAR)path_p[0];
        storage_info.folder = (WCHAR*)(path_p + 3);

        g_mmi_ftp_scr_cntx_p->ftps_start_recv_hd = mmi_bt_start_receive(
            mmi_ftps_push_file_notify,
            &file_info,
            &storage_info,
            BTRECV_OPT_KEEP_NAME);
    }
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftps_operation_begin_ind_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  op_begin_ind_p    [IN]
 *  
 * RETURNS
 *  void
 ******************************************************************************/
static void mmi_ftps_operation_begin_ind_handle(srv_ftps_operation_begin_struct* op_begin_ind_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPS_OPERATION_BEGIN_IND_HANDLE, op_begin_ind_p->operation);
    switch(op_begin_ind_p->operation)
    {
        case SRV_FTPS_OPERATION_PULL:
            break;

        case SRV_FTPS_OPERATION_PUSH:
            mmi_ftps_operation_push_begin_ind_handle(op_begin_ind_p);
            break;
    }
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftps_operation_push_end_ind_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  op_end_ind_p    [IN]
 *  
 * RETURNS
 *  void
 ******************************************************************************/
static void mmi_ftps_operation_push_end_ind_handle(srv_ftps_operation_end_struct* op_end_ind_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPS_OPERATION_PUSH_END_IND_HANDLE, op_end_ind_p->result);
    mmi_bt_stop_receive(
        g_mmi_ftp_scr_cntx_p->ftps_start_recv_hd,
        (op_end_ind_p->result == SRV_FTP_MASK_RESULT_OK ? BTRECV_RET_SUCC : op_end_ind_p->result));
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftps_operation_end_ind_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  op_end_ind_p    [IN]
 *  
 * RETURNS
 *  void
 ******************************************************************************/
static void mmi_ftps_operation_end_ind_handle(srv_ftps_operation_end_struct* op_end_ind_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTPS_OPERATION_END_IND_HANDLE, op_end_ind_p->operation);
    switch(op_end_ind_p->operation)
    {
        case SRV_FTPS_OPERATION_PULL:
            break;


        case SRV_FTPS_OPERATION_PUSH:
            mmi_ftps_operation_push_end_ind_handle(op_end_ind_p);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ftps_popup
 * DESCRIPTION
 *  This function is to notify user that ftp client put one object to the server
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftps_popup(U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 string;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*MMI_TRUE: means other ap suppress enable, not popup */
    switch (flag)
    {
        case SRV_FTP_MASK_WRITE_FILE_FAIL:
            string = (PU8)GetString(STR_BT_WRITE_FILE_FAIL);
            break;

        case SRV_FTP_MASK_FS_DEVICE_BUSY:
            string = (PU8)GetString(srv_fmgr_fs_error_get_string(FS_DEVICE_BUSY));
            break;

        case SRV_FTP_MASK_DISK_FULL:
            string = (PU8)GetString(STR_GLOBAL_MEMORY_FULL);
            break;

        case SRV_FTP_MASK_ROOT_DIR_FULL:
            string = (PU8)GetString(FMGR_FS_ROOT_DIR_FULL_TEXT);
            break;

        case SRV_FTP_MASK_FS_NO_CARD:
            string = (PU8)GetString(STR_BT_NO_CARD);
            break;

        case SRV_FTP_MASK_FS_WRITE_PROTEC:
            string = (PU8)GetString(srv_fmgr_fs_error_get_string(FS_WRITE_PROTECTION));
            break;

        default:
            ASSERT(0);
            return;
    }

    mmi_ftp_popup_hdlr((UI_string_type)string, MMI_EVENT_FAILURE);
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftp_server_is_receiving
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ******************************************************************************/
MMI_BOOL mmi_ftp_server_is_receiving(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_ftps_is_receiving();
}
#endif /* __MMI_FTS_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_ftp_popup_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string
 *  event_id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ftp_popup_hdlr(UI_string_type string, mmi_event_notify_enum event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FTP_TRC_CLASS, MMI_FTP_POPUP_HDLR, string);
    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, event_id, string);
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_bt_ftp_event_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id    [IN]
 *  msg    [IN]
 *  
 * RETURNS
 *  void
 ******************************************************************************/
void mmi_bt_ftp_event_hdlr(msg_type msg_id, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_ftp_event_handle(msg_id, msg);
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_bt_ftp_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
void mmi_bt_ftp_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 event_mask;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_ftp_init();
// #ifdef __MMI_FTC_SUPPORT__
//     g_mmi_ftp_scr_cntx_p->ftpc_disconn_from_cm = 0;
// #endif  /* __MMI_FTC_SUPPORT__ */

#ifdef __MMI_FTS_SUPPORT__
//     g_mmi_ftp_scr_cntx_p->ftps_disconn_from_cm = 0;
    g_mmi_ftp_scr_cntx_p->ftps_srv_hd = srv_ftp_open(SRV_FTP_ROLE_SERVER);
    if (g_mmi_ftp_scr_cntx_p->ftps_srv_hd > SRV_FTP_SERVER_HANDLE_DOMAIN)
    {
        event_mask = SRV_FTPS_EVENT_START | SRV_FTPS_EVENT_STOP | SRV_FTPS_EVENT_CONNECT |
            SRV_FTPS_EVENT_AUTHORIZE | SRV_FTPS_EVENT_DISCONNECT | SRV_FTPS_EVENT_OPERATION_BEGIN |
            SRV_FTPS_EVENT_OPERATION_END;
        srv_ftp_set_notify(g_mmi_ftp_scr_cntx_p->ftps_srv_hd, mmi_ftps_event_handle, event_mask);
    }

    srv_ftps_set_permission(mmi_bt_get_setting_int(BTFF_ITEM_FTP_ACCESS));
    
#endif  /* __MMI_FTS_SUPPORT__ */
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_bt_ftp_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
void mmi_bt_ftp_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_ftp_deinit();

#ifdef __MMI_FTC_SUPPORT__
    if (mmi_frm_group_is_present(g_mmi_ftp_scr_cntx_p->subgid1))
    {
        mmi_frm_group_close(g_mmi_ftp_scr_cntx_p->subgid1);
    }

    /* close handle in disconnect indication */
    if (g_mmi_ftp_scr_cntx_p->ftpc_srv_hd > 0)
    {
        srv_ftp_close(g_mmi_ftp_scr_cntx_p->ftpc_srv_hd);
        g_mmi_ftp_scr_cntx_p->ftpc_srv_hd = -1;
    }
#endif

#ifdef __MMI_FTS_SUPPORT__
    if (g_mmi_ftp_scr_cntx_p->ftps_srv_hd > SRV_FTP_SERVER_HANDLE_DOMAIN)
    {
        srv_ftp_close(g_mmi_ftp_scr_cntx_p->ftps_srv_hd);
        g_mmi_ftp_scr_cntx_p->ftps_srv_hd = -1;
    }
#endif
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftp_enter_usb_ms_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
MMI_RET mmi_ftp_enter_usb_ms_callback(mmi_event_struct *param)
{
    //EVT_ID_USB_ENTER_MS_MODE
#ifdef __MMI_FTC_SUPPORT__
    srv_ftpc_stop_receiving();
    if (g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd > 0)
    {
        mmi_bt_stop_receive(g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd,
                            BTRECV_RET_USER_ABORT);
    }
#endif

#ifdef __MMI_FTS_SUPPORT__  
    srv_ftps_stop_receiving();
    if (g_mmi_ftp_scr_cntx_p->ftps_start_recv_hd > 0)
    {
        mmi_bt_stop_receive(g_mmi_ftp_scr_cntx_p->ftps_start_recv_hd,
                            BTRECV_RET_USER_ABORT);
    }
#endif

    return MMI_RET_OK;
}




/****************************************************************************** 
 * FUNCTION
 *  mmi_bt_ftp_usb_plugin_hdle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
void mmi_bt_ftp_usb_plugin_hdle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* #ifdef __USB_IN_NORMAL_MODE__ */
    /* if (mmi_usb_check_path_exported()) */
#ifdef __MMI_FTC_SUPPORT__
    srv_ftpc_stop_receiving();
    if (g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd > 0)
    {
        mmi_bt_stop_receive(g_mmi_ftp_scr_cntx_p->ftpc_start_recv_hd,
                            BTRECV_RET_USER_ABORT);
    }
#endif

#ifdef __MMI_FTS_SUPPORT__  
    srv_ftps_stop_receiving();
    if (g_mmi_ftp_scr_cntx_p->ftps_start_recv_hd > 0)
    {
        mmi_bt_stop_receive(g_mmi_ftp_scr_cntx_p->ftps_start_recv_hd,
                            BTRECV_RET_USER_ABORT);
    }
#endif
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_bt_ftp_usb_plugin_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL
 ******************************************************************************/
BOOL mmi_bt_ftp_usb_plugin_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_ftp_usb_plugin_check();
}

#endif /* defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) */
