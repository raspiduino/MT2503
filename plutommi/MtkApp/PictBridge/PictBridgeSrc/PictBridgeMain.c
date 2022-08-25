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
 *    PictBridgeMain.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for PictBridge appliction.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_PICT_BRIDGE_SUPPORT__

#include "PictBridgeDef.h"
#include "PictBridgeProt.h"
#include "PictBridgeStruct.h"

#ifdef __MMI_RMGR_EXTEND_RIGHTS_AFTER_EXIT_AP__
#include "Drm_gprot.h"
#include "RightsMgrGProt.h"
#endif /* __MMI_RMGR_EXTEND_RIGHTS_AFTER_EXIT_AP__ */

#ifdef __DM_LAWMO_SUPPORT__
#include "dmuigprot.h"
#endif
#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"
#endif
/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "fs_type.h"
#include "string.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "AlertScreen.h"
#include "CustDataRes.h"
#include "mmi_rp_srv_pict_bridge_def.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"
#include "Pictcuigprot.h"
#include "PictBridgeResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_multimedia.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "Unicodexdcl.h"
#include "kal_public_api.h"
#include "wgui_categories_popup.h"
#include "gui_typedef.h"
#include "stdlib.h"
#include "mmi_frm_input_gprot.h"
#include "custom_events_notify.h"
#include "mmi_frm_history_gprot.h"
#include "drm_def.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
/* auto add by kw_check end */
/*
 * Global Variable
 */
extern pict_bridge_setting_struct g_pict_bridge_setting;
extern mmi_id g_pict_gid;
/*
 * Local Variable
 */
pict_bridge_context_struct g_pict_bridge_context;

/*
 * Local Function
 */
static void mmi_pict_entry_print_user_abort(void);

#if defined(__DM_LAWMO_SUPPORT__)
/*****************************************************************************
* FUNCTION
*  mmi_pict_dmui_lock_notify
* DESCRIPTION
*  dm lock notify
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
static void mmi_pict_dmui_lock_notify(mmi_dmui_app_id_enum app_id, mmi_dmui_cmd_enum cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (app_id != MMI_DMUI_APP_ID_PICT)
        return;
    
    switch (cmd)
    {    
    case MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK:
    {
        if (g_pict_bridge_context.printing == PICT_PRINTING_NOW || 
            g_pict_bridge_context.printing == PICT_PRINTING_ERROR)
        {
         #ifdef __MTK_TARGET__
            if (g_pict_bridge_context.next_operation_request == NULL)
            {        
                g_pict_bridge_context.next_operation_request = mmi_pict_prepare_xml_abort_job;
                mmi_pict_send_dps_operation_req();
            }
            else
            {
                g_pict_bridge_context.next_operation_request = mmi_pict_prepare_xml_abort_job;
            }
            if (g_pict_bridge_context.printing != PICT_PRINTING_NONE)
            {
                mmi_pict_entry_print_done(MMI_FALSE, STR_ID_PICT_PRINT_ABORTED);
            }
          #endif
        }
        else
        {
            mmi_dmui_lawmo_report(MMI_DMUI_APP_ID_PICT, cmd, MMI_DMUI_RESULT_SUCCESS);             
        }
    }
    break;

    default:    
        mmi_dmui_lawmo_report( MMI_DMUI_APP_ID_PICT, cmd, MMI_DMUI_RESULT_SUCCESS);
        break;
    }     
}
#endif /* __DM_LAWMO_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_init
 * DESCRIPTION
 *  PictBridge initialization function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_pict_bridge_setting, 0, sizeof(pict_bridge_setting_struct));
    memset(&g_pict_bridge_context, 0, sizeof(pict_bridge_context_struct));

    fs_handle = FS_Open((U16*) PICT_XML_DIR, FS_OPEN_DIR | FS_READ_ONLY);
    if (fs_handle < FS_NO_ERROR)
    {
        FS_CreateDir((U16*) PICT_XML_DIR);
    }
    else
    {
        FS_Close(fs_handle);
    }

#ifdef __MTK_TARGET__
    mmi_pict_protocol_init();
#else
    mmi_pict_xml_init();
#endif

#if defined(__DM_LAWMO_SUPPORT__)   
    mmi_dmui_lawmo_register_notify(MMI_DMUI_APP_ID_PICT, 
            MMI_DMUI_MO_TYPE_LAWMO_LOCK,
            mmi_pict_dmui_lock_notify);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_error_connection_to_pc
 * DESCRIPTION
 *  Entry function for indication of connection to PC
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_error_connection_to_pc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple(
        (WCHAR*)GetString(STR_ID_PICT_CONNECT_TO_PC),
        MMI_EVENT_FAILURE,
        g_pict_gid,
        NULL);   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_host_reset_popop
 * DESCRIPTION
 *  Entry function for indication of USB host reset
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_host_reset_popop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_pict_disp_popup(CUI_PICT_RESULT_ERROR, STR_ID_PICT_USB_RESET, MMI_EVENT_INFO);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_print_preview
 * DESCRIPTION
 *  Entry function for print preview
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_print_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 image_id;
    U8* guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(g_pict_gid, SCR_ID_PICT_PREVIEW, NULL, 
        mmi_pict_entry_print_preview, MMI_FRM_UNKNOW_SCRN))
        return;

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();;

    if (g_pict_bridge_setting.layout == 1) /* 2-up layout */
    {
        image_id = IMG_ID_PICT_LAYOUT2;
    }
    else if (g_pict_bridge_setting.layout == 2) /* 4-up layout */
    {
        image_id = IMG_ID_PICT_LAYOUT4;
    }
    else /* 1-up layout */
    {
        image_id = IMG_ID_PICT_LAYOUT1;
    }

    ShowCategory132Screen(
        (U8*) GetString(STR_ID_PICT_PREVIEW), /* title string */
        mmi_pict_return_title_icon(),         /* image ID of title icon */
        STR_GLOBAL_PRINT,                    /* string ID of LSK */
        0,                                    /* image ID of LSK */
        STR_GLOBAL_BACK,                      /* string ID of RSK */
        0,                                    /* image ID of RSK */
        image_id,                             /* image ID, displayed at the center */
        guiBuffer);

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    SetLeftSoftkeyFunction(mmi_pict_entry_print_now, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_pict_entry_print_now, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_update_printing_info_str
 * DESCRIPTION
 *  Entry function for printing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pict_update_printing_info_str(void)
{
    mmi_ucs2cpy((PS8) g_pict_bridge_context.printing_percentage, GetString(STR_ID_PICT_PRINTING));

    if (g_pict_bridge_context.printing_curr_page &&
        g_pict_bridge_context.printing_total_page)
    {
        kal_wsprintf((kal_wchar *)(g_pict_bridge_context.printing_percentage) + mmi_ucs2strlen((PS8)g_pict_bridge_context.printing_percentage),
            " %d/%d",
            g_pict_bridge_context.printing_curr_page,
            g_pict_bridge_context.printing_total_page);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_pict_printing_screen_del_callback
* DESCRIPTION
*  Callback function when printing screen is deleted.
* PARAMETERS
*  param       [IN]        Parameter from framework
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_pict_printing_screen_del_callback(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_pict_bridge_context.printing != PICT_PRINTING_NONE)
        mmi_pict_entry_print_abort();

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_print_now
 * DESCRIPTION
 *  Entry function for printing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_print_now(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_context.printing == PICT_PRINTING_NONE && g_pict_bridge_context.dps_status == PICT_DPS_BUSY)
    {
        cui_pict_disp_popup(CUI_PICT_RESULT_BUSY, STR_ID_PICT_PRINTER_BUSY, MMI_EVENT_FAILURE);
        return;
    }

    if (!mmi_frm_scrn_enter(g_pict_gid, SCR_ID_PICT_PRINTING, NULL, 
        mmi_pict_entry_print_now, MMI_FRM_UNKNOW_SCRN))
        return;

    mmi_pict_update_printing_info_str();
    
    ShowCategory66Screen(
        STR_GLOBAL_PRINT,
        mmi_pict_return_title_icon(),
        0,
        IMG_GLOBAL_OK,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_BACK,
        g_pict_bridge_context.printing_percentage,
        IMG_ID_PICT_PRINTING,
        NULL);
    
    SetRightSoftkeyFunction(mmi_pict_entry_print_user_abort, KEY_EVENT_UP);
    mmi_frm_scrn_set_leave_proc(g_pict_gid, SCR_ID_PICT_PRINTING, (mmi_proc_func) mmi_pict_printing_screen_del_callback);

    wgui_status_icon_bar_show_icon(STATUS_ICON_PRINT); /* show print icon */

    if (g_pict_bridge_context.printing == PICT_PRINTING_NONE)
    {
        g_pict_bridge_context.printing = PICT_PRINTING_NOW;
#ifdef __MTK_TARGET__
        g_pict_bridge_context.next_operation_request = mmi_pict_prepare_xml_start_job;
        mmi_frm_send_ilm(MOD_USB,MSG_ID_MMI_USB_START_JOB_REQ,NULL,NULL);
        mmi_pict_send_dps_operation_req();
#else
        g_pict_bridge_context.xml_operation_cmd = g_pict_bridge_context.xml_modis_buffer;
        mmi_pict_prepare_xml_start_job();
#endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_update_print_progression
 * DESCRIPTION
 *  Updating for printing progression
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_update_print_progression(const char *percentage_ansii)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *p1;
    S8 *p2;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strlen((PS8) percentage_ansii) > PICT_PROGRESS_LEN)
    {
        return; /* syntax error */
    }

    p1 = (S8*) percentage_ansii;

    p2 = (S8*) percentage_ansii;
    do
    {
        p2++; 
    } while(*p2 != '/');
    p2++;

    g_pict_bridge_context.printing_curr_page = (U8)atoi(p1);
    g_pict_bridge_context.printing_total_page = (U8)atoi(p2);

    if (GetActiveScreenId() == SCR_ID_PICT_PRINTING)
    {
        mmi_pict_update_printing_info_str();
        cat66_update_progress_string();
    }   
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_print_user_abort
 * DESCRIPTION
 *  Entry function for printing job abortion
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pict_entry_print_user_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pict_bridge_context.user_abort = 1;
    mmi_pict_entry_print_abort();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_print_abort
 * DESCRIPTION
 *  Entry function for printing job abortion
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_print_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
#ifdef __MTK_TARGET__
    if (g_pict_bridge_context.next_operation_request == NULL)
    {
        /*
         * DREQUEST to USB (start print)
         * KEYPAD event from L4C (user press abort)
         * HRESPONSE from USB
         * DREQUEST to USB (abort print, need to be pending after HRESPONSE)
         */
        g_pict_bridge_context.next_operation_request = mmi_pict_prepare_xml_abort_job;
        mmi_pict_send_dps_operation_req();
    }
    else
    {
        /* zgyu: since DPS spec. say at any give time, only one request can be performed.
          *since here do not maintain transaction state, we can only check @next_operation_request
        */
        g_pict_bridge_context.next_operation_request = mmi_pict_prepare_xml_abort_job;
    }
    
    if (g_pict_bridge_context.printing != PICT_PRINTING_NONE)
    {
        mmi_pict_entry_print_done(MMI_FALSE, STR_ID_PICT_PRINT_ABORTED);
    }

#else
    mmi_pict_entry_print_done(MMI_FALSE, STR_ID_PICT_PRINT_ABORTED);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_print_continue
 * DESCRIPTION
 *  Entry function for printing job resume
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_print_continue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    wgui_status_icon_bar_hide_icon(STATUS_ICON_PRINT_FAIL); /* hide print error icon */

    mmi_pict_go_back_from_print_error();
    
#ifdef __MTK_TARGET__
    /* since error information screen can be re-entry,
     * and we can not confirm continueJob response will be received before re-entry
     * so we should check if APP is waiting for operaetion's response too, as abortJob
     */
    if (g_pict_bridge_context.next_operation_request == NULL)
    {
        g_pict_bridge_context.next_operation_request = mmi_pict_prepare_xml_continue_job;
        mmi_pict_send_dps_operation_req();
    }
    else
    {
        g_pict_bridge_context.next_operation_request = mmi_pict_prepare_xml_continue_job;
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_print_error_information
 * DESCRIPTION
 *  Entry function for print error
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_print_error_information(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(g_pict_gid, SCR_ID_PICT_ERROR, NULL, 
        mmi_pict_entry_print_error_information, MMI_FRM_UNKNOW_SCRN))
        return;

    ShowCategory165Screen(
        STR_GLOBAL_YES,
        0,
        STR_GLOBAL_NO,
        0,
        get_string(g_pict_bridge_context.error_string_id),
        mmi_get_event_based_image(MMI_EVENT_QUERY),
        NULL);

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    SetLeftSoftkeyFunction(mmi_pict_entry_print_continue, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_pict_entry_print_continue, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_pict_entry_print_user_abort, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_print_error
 * DESCRIPTION
 *  Entry function for print error screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_popup_print_error(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_node_struct node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_reset_icon_display(STATUS_ICON_PRINT); /* hide print icon */
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_PRINT_FAIL); /* show print error icon */
    wgui_status_icon_bar_update();

    
    mmi_popup_display_simple(
        (WCHAR*)GetString(STR_ID_PICT_ERROR),
        MMI_EVENT_FAILURE,
        g_pict_gid,
        NULL);   

    /* prevent from continuous error indication from the printer */
    mmi_frm_scrn_close(g_pict_gid, SCR_ID_PICT_ERROR);

    if (mmi_frm_scrn_is_present(g_pict_gid, SCR_ID_PICT_PRINTING, MMI_FRM_NODE_ALL_FLAG)) /* if not printing in the background */
    {
        mmi_frm_node_info_init(&node);

        node.id = SCR_ID_PICT_ERROR;
        node.entry_proc = (mmi_proc_func)mmi_pict_entry_print_error_information;
        mmi_frm_scrn_insert(g_pict_gid, SCR_ID_PICT_PRINTING, &node, MMI_FRM_INSERT_AFTER_SCRN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_go_back_from_print_error
 * DESCRIPTION
 *  Go back from print error screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_go_back_from_print_error(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_is_present(g_pict_gid, SCR_ID_PICT_PRINTING, MMI_FRM_NODE_ALL_FLAG))
    {
        /* we think if it is in history, then it is the top one
         * maybe there are other case we not considered now
         */
         mmi_frm_scrn_close_active_id();
    }
    else
    {
        /* due to re-entry pictbridge APP in case of error state */
        mmi_pict_entry_print_now();
        mmi_frm_scrn_close(g_pict_gid, SCR_ID_PICT_ERROR);        
    }
}


#ifdef __MMI_RMGR_EXTEND_RIGHTS_AFTER_EXIT_AP__

mmi_ret mmi_pict_rmgr_group_proc(mmi_event_struct *evt)
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
 *  mmi_pict_entry_extend_rights_screen
 * DESCRIPTION
 *  Entry function for extend DRM rights
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_extend_rights_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rmgr_request_rights_confirm();
}
#endif /* __MMI_RMGR_EXTEND_RIGHTS_AFTER_EXIT_AP__ */

#ifdef __DRM_SUPPORT__
extern void mmi_pict_drm_consume_callback(kal_int32 result, kal_int32 id);
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_print_done
 * DESCRIPTION
 *  Entry function for printing job completion
 * PARAMETERS
 *  result          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_print_done(pBOOL result, U16 error_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL need_drm_right = MMI_FALSE;
    FS_HANDLE fs_handle = NULL;
#ifdef __DRM_SUPPORT__
        S32 right_id;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    /* for abort case, when receive abort response, send close job request */
    if (g_pict_bridge_context.next_operation_request != mmi_pict_prepare_xml_abort_job)
        mmi_frm_send_ilm(MOD_USB,MSG_ID_MMI_USB_CLOSE_JOB_REQ,NULL,NULL);
#endif

    g_pict_bridge_context.printing = PICT_PRINTING_NONE;
    
    if (result)
    {
        /* consume the last file */
#ifdef __MTK_TARGET__
#ifdef __DRM_SUPPORT__
#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__
        fs_handle = DRM_open_file((U16*)g_pict_bridge_context.printing_filepath, FS_READ_ONLY, DRM_PERMISSION_PRINT);
        if (g_pict_bridge_context.multi_file_consume[g_pict_bridge_context.curr_index] == 0)
        {
            right_id = DRM_consume_rights(fs_handle, DRM_PERMISSION_PRINT, mmi_pict_drm_consume_callback);
            DRM_stop_consume(right_id);
            g_pict_bridge_context.multi_file_consume[g_pict_bridge_context.curr_index] = 1;
        }
        DRM_close_file(fs_handle);
#else
        fs_handle = DRM_open_file((U16*) g_pict_bridge_context.printing_filepath, FS_READ_ONLY, DRM_PERMISSION_PRINT);
        if (g_pict_bridge_context.drm_consume_cnt == 0)
        {
            right_id = DRM_consume_rights(fs_handle, DRM_PERMISSION_PRINT, mmi_pict_drm_consume_callback);
            DRM_stop_consume(right_id);
            g_pict_bridge_context.drm_consume_cnt = 1;
        }
        DRM_close_file(fs_handle);
#endif
#endif
#endif
        cui_pict_disp_popup(CUI_PICT_RESULT_OK, STR_GLOBAL_DONE, MMI_EVENT_SUCCESS);
    }
    else
    {    
        if (error_string != STR_ID_PICT_PRINT_ABORTED || g_pict_bridge_context.user_abort)            
        {            
            cui_pict_disp_popup(CUI_PICT_RESULT_ERROR, error_string, MMI_EVENT_FAILURE);    
        }   
        else
        {
            cui_pict_send_result_to_parent(CUI_PICT_RESULT_CANCEL);
        }
    }

    wgui_status_icon_bar_reset_icon_display(STATUS_ICON_PRINT); /* hide print icon */
    wgui_status_icon_bar_reset_icon_display(STATUS_ICON_PRINT_FAIL); /* hide print error icon */
    wgui_status_icon_bar_update();
    
    memset(&g_pict_bridge_context.printing_percentage[0], 0, 32 * ENCODING_LENGTH);
    g_pict_bridge_context.printing_curr_page = 0;
    g_pict_bridge_context.printing_total_page = 0;
    g_pict_bridge_context.user_abort = 0;

#ifdef __DRM_SUPPORT__
#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__

#ifdef __MMI_RMGR_EXTEND_RIGHTS_AFTER_EXIT_AP__
    if (g_pict_bridge_context.multi_file_select == 1 &&
        g_pict_bridge_context.multi_file_consume[0] == 1 &&
        mmi_rmgr_extend_rights_by_path((U16*) g_pict_bridge_context.printing_filepath,
        DRM_PERMISSION_PRINT, mmi_pict_return_title_icon()) == MMI_RMGR_STATUS_REQUEST_RIGHTS)
    {
        need_drm_right = MMI_TRUE;
    }
#endif /* __MMI_RMGR_EXTEND_RIGHTS_AFTER_EXIT_AP__ */

    memset(&g_pict_bridge_context.multi_file_consume[0], 0, PICT_MAX_MULTI_FILES);

#else

#ifdef __MMI_RMGR_EXTEND_RIGHTS_AFTER_EXIT_AP__
    if (g_pict_bridge_context.drm_consume_cnt == 1 &&
        mmi_rmgr_extend_rights_by_path((U16*) g_pict_bridge_context.printing_filepath,
        DRM_PERMISSION_PRINT, mmi_pict_return_title_icon()) == MMI_RMGR_STATUS_REQUEST_RIGHTS)
    {
        need_drm_right = MMI_TRUE;
    }
#endif /* __MMI_RMGR_EXTEND_RIGHTS_AFTER_EXIT_AP__ */

    g_pict_bridge_context.drm_consume_cnt = 0;

#endif
#endif /*__DRM_SUPPORT__ */

#ifdef __MMI_RMGR_EXTEND_RIGHTS_AFTER_EXIT_AP__
    if (need_drm_right)
    {
        mmi_id gid;
        mmi_frm_node_struct node;
        
        gid = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_pict_rmgr_group_proc, NULL);        
        mmi_frm_node_info_init(&node);

        node.id = gid;
        node.entry_proc = mmi_pict_rmgr_group_proc;
        mmi_frm_group_insert(GRP_ID_ROOT, g_pict_gid, &node, MMI_FRM_NODE_AFTER_FLAG);
        
        mmi_frm_scrn_enter(gid, SCR_ID_PICT_DUMMY, NULL, mmi_pict_entry_extend_rights_screen, 0);        
    }
#endif
}


#ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_printer_connected
 * DESCRIPTION
 *  Entry function for printer connected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_printer_connected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple(
        (WCHAR*)GetString(STR_ID_PICT_PRINTER_CONNECTED),
        MMI_EVENT_INFO,
        g_pict_gid,
        NULL);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_popup_idle_state_error
 * DESCRIPTION
 *  Entry function for error reported in idle state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_popup_idle_state_error(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple(
        (WCHAR*) GetString(STR_ID_PICT_ERROR),
        MMI_EVENT_FAILURE,
        g_pict_gid,
        NULL);
}
#endif /* __MMI_PICT_BRIDGE_COMPLIANCE_TEST__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_return_title_icon
 * DESCRIPTION
 *  Title icon of PictBridge related screens
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_pict_return_title_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* IMG_ID_PICT_TITLE is not populated so return the file manager root icon */
    return GetRootTitleIcon(MAIN_MENU_FILE_MNGR_MENUID);
}

#if !defined(__MMI_FMGR_MULTI_SELECT_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_pict_get_file_date
 * DESCRIPTION
 *  Get file date for single file print
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_get_file_date(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle;
    FS_FileInfo fs_fileinfo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_handle = FS_Open((U16*) g_pict_bridge_context.printing_filepath, FS_READ_ONLY);
    FS_GetFileInfo(fs_handle, &fs_fileinfo);
    g_pict_bridge_context.printing_filedate = fs_fileinfo.DirEntry->DateTime;
    FS_Close(fs_handle);
}
#endif /* defined(__MMI_FMGR_MULTI_SELECT_SUPPORT__) */


#ifdef __MMI_PICT_BRIDGE_CROPPING__
/*****************************************************************************
 * FUNCTION
 *  mmi_pict_get_file_dimension
 * DESCRIPTION
 *  Get file dimension for single file print
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_get_file_dimension(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__
    S8 image_file_path[(SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH];
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__
    mmi_ucs2cpy(image_file_path, (S8*) g_pict_bridge_context.printing_filepath);
    srv_fmgr_path_remove_filename((WCHAR*)image_file_path);
    mmi_ucs2cat(image_file_path, (S8*) g_pict_bridge_context.multi_file_path[0]);
    gdi_image_get_dimension_file(image_file_path, &g_pict_bridge_context.image_width, &g_pict_bridge_context.image_height);
#else /* defined(__MMI_FMGR_MULTI_SELECT_SUPPORT__) */
    gdi_image_get_dimension_file((S8*) g_pict_bridge_context.printing_filepath, &g_pict_bridge_context.image_width, &g_pict_bridge_context.image_height);
#endif /* defined(__MMI_FMGR_MULTI_SELECT_SUPPORT__) */
}
#endif /* __MMI_PICT_BRIDGE_CROPPING__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_jpg_format_validation
 * DESCRIPTION
 *  Validate the JPG file is accepted to print
 * PARAMETERS
 *  file            [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_pict_jpg_format_validation(S8 *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT gdi_ret = GDI_FAILED;
    S32 width = 0, height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check image header */
    if (gdi_image_get_type_from_file((PS8) file) != GDI_IMAGE_TYPE_JPG_FILE)
    {
        return MMI_FALSE;
    }

    /* Check image resolution */
    gdi_ret = gdi_image_get_dimension_file((PS8) file, (S32*) & width, (S32*) & height);
    if (gdi_ret < GDI_SUCCEED || width <= 0 || height <= 0)
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}

#endif /* __MMI_PICT_BRIDGE_SUPPORT__ */

