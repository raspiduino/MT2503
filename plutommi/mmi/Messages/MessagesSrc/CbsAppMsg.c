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
 *  CbsAppMsg.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  CBS(Cell Broadcast Service) Application Message Handler
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_TELEPHONY_SUPPORT__
#ifdef __MMI_CBS_SUPPORT__

/**************************************************************
* Header Files Include
**************************************************************/
#include "MMIDataType.h"
#include "string.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "kal_general_types.h"
#include "nvram_common_defs.h"
#include "gui_data_types.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "Unicodexdcl.h"
#include "AlertScreen.h"
#include "CustDataRes.h"
#include "wgui_categories_text_viewer.h"
#include "SmsGuiInterfaceType.h"
#include "SmsAppType.h"
#include "SmsSrvGprot.h"
#include "NotificationGprot.h"
#ifdef __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__
#include "wgui_categories_idlescreen.h"
#endif
#ifdef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__
#include "ProfilesSrvGprot.h"
#endif

#include "CommonScreens.h"
#include "CbsSrvGprot.h"
#include "mmi_rp_app_cbs_def.h"
#include "mmi_rp_app_sms_def.h"
#include "MenuCuiGprot.h"
#include "SmsAppProt.h"
#include "CbsAppProt.h"
#include "IdleNotificationManagerGprot.h"
#include "IdleGProt.h"
#include "NwInfoSrvGProt.h"
#ifdef __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__
#include "ModeSwitchSrvGProt.h"
#endif /* __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__ */
#include "MMI_trc_Int.h"

#include "SmsUtilSrv.h"


/**************************************************************
* MARCO
**************************************************************/
#define MMI_CBS_MAX_CONTENT_LEN         (SRV_CBS_MAX_CONTENT_LEN)
#ifdef __MMI_OP12_MESSAGE_CB__
#define MMI_CBS_OP12_MCN                50
#endif /* __MMI_OP12_MESSAGE_CB__ */

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#else /* __MMI_DUAL_SIM_MASTER__ */
#define MMI_CBS_SIM_NUM                 1
#endif /* __MMI_DUAL_SIM_MASTER__ */

#if (!defined(__MMI_MESSAGES_CB_DISPLAY_IN_IDLE__) || defined(__MMI_MESSAGES_TWO_CB_MODES_DISPLAY__))
#define MMI_CBS_POPUP_NOTIFICATION_STYLE
#else /* (!defined(__MMI_MESSAGES_CB_DISPLAY_IN_IDLE__) || defined(__MMI_MESSAGES_TWO_CB_MODES_DISPLAY__)) */
#undef MMI_CBS_POPUP_NOTIFICATION_STYLE
#endif /* (!defined(__MMI_MESSAGES_CB_DISPLAY_IN_IDLE__) || defined(__MMI_MESSAGES_TWO_CB_MODES_DISPLAY__)) */


/**************************************************************
* Structure Declaration
**************************************************************/
typedef struct
{
    MMI_ID owner_gid;
    srv_sms_sim_enum sim_id;
    U16 msg_id;
    U16 title_str_id;
    U8 *content;
    S32 content_size;
    MMI_BOOL is_del_bg;
    MMI_BOOL is_op;
} cbs_viewer_cntx_struct;

typedef struct
{
    MMI_ID owner_gid;
    srv_sms_sim_enum sim_id;
    S32 list_index;
    U16 msg_id;
} cbs_inbox_cntx_struct;

typedef struct
{
    srv_sms_sim_enum sim_id;
    U16 msg_id;
    MMI_BOOL is_ind;
    srv_cbs_mode_enum mode;
} cbs_ind_info_struct;

typedef struct
{
    MMI_ID owner_gid;
    MMI_ID viewer_gid;
    srv_sms_sim_enum sim_id;
    U16 msg_id;
    cbs_ind_info_struct *ind_info;
} cbs_ind_viewer_cntx_struct;

#ifdef __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__
typedef struct
{
    srv_sms_sim_enum sim_id;
    U16 msg_id;
    U16 chnl_id;
    MMI_BOOL is_show;
} cbs_idle_ind_info_struct;
#endif /* __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__ */


/**************************************************************
* Global Variables Declaration
**************************************************************/ 


/**************************************************************
* Extern Function Declaration
**************************************************************/

/**************************************************************
* Static Variables Defination
**************************************************************/
static cbs_inbox_cntx_struct *curr_inbox_cntx;
static cbs_viewer_cntx_struct *curr_viewer_cntx;
#ifdef MMI_CBS_POPUP_NOTIFICATION_STYLE
static cbs_ind_viewer_cntx_struct *ind_viewer_cntx;
#endif
static WCHAR mmi_cbs_content[MMI_CBS_MAX_CONTENT_LEN + 1];

#ifdef __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__
static WCHAR mmi_cbs_idle_content[MMI_CBS_MAX_CONTENT_LEN + 1];
static cbs_idle_ind_info_struct idle_ind_info;
#else  /* __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__ */
static cbs_ind_info_struct immediate_ind_info;
#endif /* __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__ */

#ifdef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__
static cbs_ind_info_struct *normal_ind_info;
static cbs_ind_info_struct normal_ind_info_array[MMI_CBS_SIM_NUM];
#endif /* __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__ */


/**************************************************************
* Static Function Declaration
**************************************************************/
static void mmi_cbs_entry_inbox_list(mmi_scrn_essential_struct* scrn_data);
static void mmi_cbs_get_list_index(S32 index);
static S32 mmi_cbs_inbox_list_get_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size);
static void mmi_cbs_view_msg(void);
static MMI_ID mmi_cbs_viewer_run(
                MMI_ID parent_gid,
                U16 msg_id,
                srv_sms_sim_enum sim_id,
                U16 title_str_id);
static void mmi_cbs_entry_viewer(mmi_scrn_essential_struct* scrn_data);
static void mmi_cbs_entry_viewer_option(void);
static void mmi_cbs_viewer_csk_hdlr(void);
static void mmi_cbs_pre_delete_msg(void);
static void mmi_cbs_delete_msg(void);
static mmi_ret mmi_cbs_viewer_proc(mmi_event_struct* evt);
static mmi_ret mmi_cbs_inbox_proc(mmi_event_struct* evt);
static mmi_ret mmi_cbs_viewer_option_menu_proc(cui_menu_event_struct* menu_evt);

#ifdef __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__
static MMI_BOOL mmi_cbs_is_show_in_idle(void);
#endif /* __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__ */

#ifdef MMI_CBS_POPUP_NOTIFICATION_STYLE
static void mmi_cbs_entry_new_msg_ind(cbs_ind_info_struct *cntx);
static void mmi_cbs_ind_viewer_launch(MMI_ID parent_gid, cbs_ind_info_struct *ind_info);
static mmi_ret mmi_cbs_ind_viewer_proc(mmi_event_struct* evt);
static mmi_ret mmi_cbs_ind_viewer_ready_event_hdlr(mmi_event_struct *evt);

#ifndef __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__
static MMI_BOOL mmi_cbs_entry_immediate_ind(mmi_scenario_id scen_id, void *arg);
#endif /* __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__ */
static cbs_ind_info_struct* mmi_cbs_get_ind_info(
                                    srv_sms_sim_enum sim_id,
                                    srv_cbs_mode_enum mode);
static void mmi_cbs_cancel_new_msg_ind(srv_sms_sim_enum sim_id);
#endif /* MMI_CBS_POPUP_NOTIFICATION_STYLE */

#ifdef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__
static void mmi_cbs_nmgr_ind_notify_key_hdlr(void* user_data);
#endif /* __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__ */

static MMI_BOOL mmi_cbs_is_in_inbox_list(srv_sms_sim_enum sim_id);
static void mmi_cbs_refresh_inbox_list(void);

#ifdef __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__
static void mmi_cbs_show_content_in_idle(MMI_BOOL is_show);
#endif /* __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__ */
static mmi_cbs_msg_send_view_opt_evt(void);
/**************************************************************
* Function Defination
**************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_inbox_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_cbs_inbox_launch(MMI_ID parent_gid, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID curr_gid;
    cbs_inbox_cntx_struct *inbox_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_INBOX_LAUNCH);

    inbox_cntx = OslMalloc(sizeof(cbs_inbox_cntx_struct));

    curr_gid = mmi_frm_group_create(
                    parent_gid,
                    GRP_ID_AUTO_GEN,
                    mmi_cbs_inbox_proc,
                    inbox_cntx);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_INBOX_LAUNCH_1, curr_gid);

    inbox_cntx->owner_gid = curr_gid;
    inbox_cntx->sim_id = sim_id;
    inbox_cntx->list_index = 0;

    mmi_frm_group_enter(curr_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_first_enter(
        inbox_cntx->owner_gid,
        SCR_ID_CBS_INBOX_LIST,
        (FuncPtr)mmi_cbs_entry_inbox_list,
        inbox_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_entry_inbox_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_entry_inbox_list(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_frm_scrn_enter(
                scrn_data->group_id, 
                scrn_data->scrn_id,
                NULL,
                (FuncPtr)mmi_cbs_entry_inbox_list,
                MMI_FRM_FULL_SCRN);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_ENTRY_INBOX_LIST, result);

    if (result)
    {
        U8 *gui_buffer = NULL;
        S32 hilite_item = 0;
        S32 total_item = srv_cbs_get_msg_num(curr_inbox_cntx->sim_id);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_ENTRY_INBOX_LIST_1, total_item);

    #ifdef MMI_CBS_POPUP_NOTIFICATION_STYLE
        mmi_cbs_cancel_new_msg_ind(curr_inbox_cntx->sim_id);
    #endif /* MMI_CBS_POPUP_NOTIFICATION_STYLE */

        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        if (gui_buffer != NULL)
        {
            hilite_item = (curr_inbox_cntx->list_index < total_item) ? curr_inbox_cntx->list_index : 0;
        }

        RegisterHighlightHandler(mmi_cbs_get_list_index);

        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        
        wgui_cat1032_show(
            (WCHAR*)GetString(STR_ID_CBS_INBOX),
            (PU8)GetImage(IMG_SMS_ENTRY_SCRN_CAPTION),
            (WCHAR*)GetString(STR_GLOBAL_OK),
            (PU8)GetImage(IMG_GLOBAL_OK),
            (WCHAR*)GetString(STR_GLOBAL_BACK),
            (PU8)GetImage(IMG_GLOBAL_BACK),
            total_item,
            mmi_cbs_inbox_list_get_item,
            NULL,
            hilite_item,
            0,
            gIndexIconsImageList[0],
            0,
            gui_buffer,
            NULL);

        if (total_item == 0)
        {
            ChangeLeftSoftkey(0, 0);
            ChangeCenterSoftkey(0, IMG_NONE);
        }

        SetLeftSoftkeyFunction(mmi_cbs_view_msg, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_cbs_view_msg, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_get_list_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *          
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_get_list_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_inbox_cntx->list_index = index;
    curr_inbox_cntx->msg_id = srv_cbs_get_msg_id(
                                (U16)curr_inbox_cntx->list_index,
                                curr_inbox_cntx->sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_cb_inbox_list_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 * 
 *****************************************************************************/
static S32 mmi_cbs_inbox_list_get_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_enum sim_id = curr_inbox_cntx->sim_id;
    U32 total_item = srv_cbs_get_msg_num(sim_id);
    U16 msg_id;
    U16 chnl_id;
    U8 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_size >= (S32)total_item)
    {
        data_size = total_item;
    }

    for (index = 0; index < data_size; index++)
    {
        WCHAR name[SRV_CBS_CHNL_NAME_LEN + 1];
        S32 msg_index = index + start_index;
        msg_id = srv_cbs_get_msg_id((U16)msg_index, sim_id);
        chnl_id = srv_cbs_get_msg_chnl_id(msg_id, sim_id);
        srv_cbs_get_channel_name(name, chnl_id, sim_id);

        if (mmi_wcslen(name) == 0)
        {
            kal_wsprintf(name, "%d", chnl_id);
        }

        mmi_ucs2ncpy((CHAR *)menu_data[index].item_list[0], (const CHAR *)name, MAX_SUBMENU_CHARACTERS);
        menu_data[index].image_list[0] = get_image(gIndexIconsImageList[index + start_index]);
    }
    return data_size;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_view_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_view_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    srv_sms_sim_enum sim_id = curr_inbox_cntx->sim_id;
    U16 msg_id = curr_inbox_cntx->msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_VIEW_MSG);

    mmi_cbs_viewer_run(curr_inbox_cntx->owner_gid, msg_id, sim_id, STR_ID_CBS_MSG_BODY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_viewer_run
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_ID mmi_cbs_viewer_run(
                MMI_ID parent_gid,
                U16 msg_id,
                srv_sms_sim_enum sim_id,
                U16 title_str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    MMI_ID curr_gid = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_VIEWER_RUN, msg_id, sim_id);

    if (curr_viewer_cntx != NULL)
    {
        mmi_frm_group_close(curr_viewer_cntx->owner_gid);
    }

    result = srv_cbs_read_msg(
                msg_id,
                sim_id,
                mmi_cbs_content,
                MMI_CBS_MAX_CONTENT_LEN);

    if (result)
    {
        cbs_viewer_cntx_struct *viewer_cntx;

        viewer_cntx = OslMalloc(sizeof(cbs_viewer_cntx_struct));

        curr_gid = mmi_frm_group_create(
                        parent_gid,
                        GRP_ID_AUTO_GEN,
                        mmi_cbs_viewer_proc,
                        viewer_cntx);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_VIEWER_RUN_1, curr_gid);

        viewer_cntx->owner_gid = curr_gid;
        viewer_cntx->sim_id = sim_id;
        viewer_cntx->msg_id = msg_id;
        viewer_cntx->title_str_id = title_str_id;
        viewer_cntx->content = (U8*)mmi_cbs_content;
        viewer_cntx->content_size = mmi_wcslen(mmi_cbs_content) * sizeof(WCHAR);
        viewer_cntx->is_del_bg = MMI_FALSE;
        viewer_cntx->is_op = MMI_FALSE;

        mmi_frm_group_enter(curr_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

        mmi_frm_scrn_first_enter(
            viewer_cntx->owner_gid,
            SCR_ID_CBS_VIEWER,
            (FuncPtr)mmi_cbs_entry_viewer,
            viewer_cntx);
    }
    else
    {
        mmi_cbs_display_common_not_finished();
    }

    return curr_gid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_entry_viewer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_entry_viewer(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_frm_scrn_enter(
                scrn_data->group_id, 
                scrn_data->scrn_id,
                NULL,
                (FuncPtr)mmi_cbs_entry_viewer,
                MMI_FRM_FULL_SCRN);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_ENTRY_VIEWER, result);

    if (result)
    {
        U8 *gui_buffer = NULL;
        cbs_viewer_cntx_struct *viewer_cntx = (cbs_viewer_cntx_struct*)scrn_data->user_data;

        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

        ShowCategory74Screen(
            viewer_cntx->title_str_id,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            STR_GLOBAL_OPTIONS,
            IMG_SMS_COMMON_NOIMAGE,
            STR_GLOBAL_BACK,
            IMG_SMS_COMMON_NOIMAGE,
            viewer_cntx->content,
            viewer_cntx->content_size,
            gui_buffer);

        SetLeftSoftkeyFunction(mmi_cbs_entry_viewer_option, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_cbs_viewer_csk_hdlr, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_entry_viewer_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_entry_viewer_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_ENTRY_VIEWER_OPTION, curr_viewer_cntx->is_op);

    mmi_cbs_msg_send_view_opt_evt();

    menu_gid = cui_menu_create(
                    curr_viewer_cntx->owner_gid,
                    CUI_MENU_SRC_TYPE_RESOURCE,
                    CUI_MENU_TYPE_OPTION,
                    MENU_ID_CBS_VIEWER_OPTIONS,
                    MMI_FALSE,
                    curr_viewer_cntx);
#ifndef __MMI_SMS_SLIM__
    cui_menu_set_default_title_image(menu_gid, (UI_image_type)GetImage(IMG_SMS_ENTRY_SCRN_CAPTION));
#endif
    cui_menu_run(menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_pre_delete_msg
 * DESCRIPTION
 *  pre delete cb message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbs_viewer_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_VIEWER_CSK_HDLR, curr_viewer_cntx->is_op);

    mmi_cbs_msg_send_view_opt_evt();

    mmi_cbs_pre_delete_msg();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_pre_delete_msg
 * DESCRIPTION
 *  pre delete cb message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbs_pre_delete_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_entry_confirm(
        curr_viewer_cntx->owner_gid,
        STR_GLOBAL_DELETE_ASK,
	    mmi_cbs_delete_msg,
	    mmi_frm_scrn_close_active_id,
	    MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_msg_send_view_opt_evt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_cbs_msg_send_view_opt_evt(void)
{   
    if (!curr_viewer_cntx->is_op)
    {
        mmi_cbs_viewer_op_event_struct event_data;

        curr_viewer_cntx->is_op = MMI_TRUE;

        MMI_FRM_INIT_GROUP_EVENT(&event_data, EVT_ID_MMI_CBS_VIEWER_OP, curr_viewer_cntx->owner_gid);
        mmi_frm_group_send_to_parent(curr_viewer_cntx->owner_gid, (mmi_group_event_struct*)&event_data);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_delete_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbs_delete_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_DELETE_MSG, curr_viewer_cntx->is_del_bg);

    if (curr_viewer_cntx->is_del_bg)
    {
        result = MMI_TRUE;
    }
    else
    {
        result = srv_cbs_delete_msg(curr_viewer_cntx->msg_id, curr_viewer_cntx->sim_id);
    }

    if (result)
    {
        mmi_cbs_display_common_success(STR_GLOBAL_DELETED);
    }
    else
    {
        mmi_cbs_display_common_not_finished();

    }

    mmi_frm_scrn_close(curr_viewer_cntx->owner_gid, SCR_ID_CBS_VIEWER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_viewer_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_cbs_viewer_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    U16 event_id = evt->evt_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_VIEWER_PROC, event_id);

    if (cui_menu_is_menu_event(event_id))
    {
        cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

        mmi_cbs_viewer_option_menu_proc(menu_evt);
    }
    else
    {
        cbs_viewer_cntx_struct *viewer_cntx = (cbs_viewer_cntx_struct*)evt->user_data;

        switch (event_id)
        {
            case EVT_ID_GROUP_ACTIVE:
                curr_viewer_cntx = viewer_cntx;
                break;

            case EVT_ID_GROUP_DEINIT:
            {
                if (curr_viewer_cntx == viewer_cntx)
                {
                    curr_viewer_cntx = NULL;
                }

                OslMfree(viewer_cntx);                
                break;
            }
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_inbox_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_cbs_inbox_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    U16 event_id = evt->evt_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_INBOX_PROC, event_id);

    if (cui_menu_is_menu_event(event_id))
    {
        cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

        if (menu_evt->evt_id == EVT_ID_CUI_MENU_CLOSE_REQUEST)
        {
            cui_menu_close(menu_evt->sender_id);
        }
    }
    else
    {
        cbs_inbox_cntx_struct *inbox_cntx = (cbs_inbox_cntx_struct*)evt->user_data;

        switch (event_id)
        {
            case EVT_ID_GROUP_ACTIVE:
                curr_inbox_cntx = inbox_cntx;
                break;


            case EVT_ID_GROUP_DEINIT:
            {
                if (curr_inbox_cntx == inbox_cntx)
                {
                    curr_inbox_cntx = NULL;
                }

                OslMfree(inbox_cntx);                
                break;
            }
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_viewer_option_menu_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_cbs_viewer_option_menu_proc(cui_menu_event_struct* menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    cbs_viewer_cntx_struct *viewer_cntx = (cbs_viewer_cntx_struct*)menu_evt->app_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_VIEWER_OPTION_MENU_PROC, menu_evt->evt_id);

    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            curr_viewer_cntx = viewer_cntx;
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            switch (menu_evt->highlighted_menu_id)
            {
                case MENU_ID_CBS_VIEWER_OPT_DELETE:
                {
                    mmi_cbs_pre_delete_msg();
                    break;
                }

                case MENU_ID_CBS_VIEWER_OPT_USE_NUM:
                {
                    mmi_sms_pre_entry_use_detail_list_sg(
                        viewer_cntx->owner_gid,
                        MMI_SMS_ADDR_PHONENUMBER,
                        (S8*)viewer_cntx->content,
                        (U16)viewer_cntx->content_size,
                        NULL);
                    break;
                }

            #ifdef __MMI_MESSAGES_USE_URL__
                case MENU_ID_CBS_VIEWER_OPT_USE_URL:
                {
                    mmi_sms_pre_entry_use_detail_list_sg(
                        viewer_cntx->owner_gid,
                        MMI_SMS_ADDR__URL,
                        (S8*)viewer_cntx->content,
                        (U16)viewer_cntx->content_size,
                        NULL);
                    break;
                }
            #endif /* __MMI_MESSAGES_USE_URL__ */

                default:
                {
                    MMI_ASSERT(0);
                    break;
                }
            }
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


#ifdef __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__
/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_get_idle_content
 * DESCRIPTION
 *  Function for the Idle Category to get CB content
 * PARAMETERS
 *  void
 * RETURNS
 *  U8*
 *****************************************************************************/
U8* mmi_cbs_get_idle_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *content = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_GET_IDLE_CONTENT);

	if (mmi_cbs_is_show_in_idle())
    {
        content = (U8*)mmi_cbs_idle_content;
	}

	return content;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_show_content_in_idle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbs_show_content_in_idle(MMI_BOOL is_show)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_SHOW_CONTENT_IN_IDLE, is_show);

    idle_ind_info.is_show = is_show;

	if (mmi_idle_is_active())
    {
		mmi_idle_update_service_area();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_cb_is_show_in_idle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_cbs_is_show_in_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
#ifdef __MTK_TARGET__
    mmi_sim_enum mmi_sim_id = MMI_SIM1;
#endif /* __MTK_TARGET__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    if (idle_ind_info.sim_id == SRV_SMS_SIM_2)
    {
        mmi_sim_id = MMI_SIM2;
    }

	if  (srv_nw_info_get_service_availability(mmi_sim_id) != SRV_NW_INFO_SA_FULL_SERVICE)
	{
		result = MMI_FALSE;
	}
	else
#endif /* __MTK_TARGET__ */
    {
        result = idle_ind_info.is_show;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_IS_SHOW_IN_IDLE, result);

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_display_in_idle_cb_ready_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_cbs_display_in_idle_cb_ready_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_ready_event_struct *event_data = (srv_cbs_ready_event_struct*)evt; 
#if (MMI_MAX_SIM_NUM >=2)
    srv_sms_sim_enum curr_sim = idle_ind_info.sim_id;
#endif /* __GEMINI__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event_data->is_ready)
    {
    	return MMI_RET_OK;
    }
    
#if (MMI_MAX_SIM_NUM >= 2)
    if (curr_sim & event_data->sim_id)
#endif /* __GEMINI__ */
    {
        mmi_cbs_show_content_in_idle(MMI_FALSE);
    }
	return MMI_RET_OK;
}
#endif /* __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_new_msg_event_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_cbs_new_msg_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_new_msg_event_struct *new_msg = (srv_cbs_new_msg_event_struct*)evt; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_NEW_MSG_EVENT_PROC, new_msg->mode, new_msg->channel_id);

#ifdef __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__
#ifdef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__
    if ((new_msg->mode == SRV_CBS_MODE_IMMEDICATE)
    #ifdef __MMI_OP12_MESSAGE_CB__
        || (new_msg->channel_id == MMI_CBS_OP12_MCN)
    #endif /* __MMI_OP12_MESSAGE_CB__ */
       )
    {
        idle_ind_info.chnl_id = new_msg->channel_id;
        idle_ind_info.sim_id = new_msg->sim_id;
        idle_ind_info.msg_id = new_msg->msg_id;

		srv_cbs_read_msg(
		    new_msg->msg_id,
		    new_msg->sim_id,
		    mmi_cbs_idle_content,
		    MMI_CBS_MAX_CONTENT_LEN);

        mmi_cbs_show_content_in_idle(MMI_TRUE);
    }
    else
    {
        cbs_ind_info_struct *ind_info;

        ind_info = mmi_cbs_get_ind_info(new_msg->sim_id, new_msg->mode);

        ind_info->is_ind = MMI_TRUE;
        ind_info->msg_id = new_msg->msg_id;
        ind_info->sim_id = new_msg->sim_id;

        mmi_cbs_entry_new_msg_ind(ind_info);
    }
#else /* __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__ */
    idle_ind_info.chnl_id = new_msg->channel_id;
    idle_ind_info.sim_id = new_msg->sim_id;
    idle_ind_info.msg_id = new_msg->msg_id;

	srv_cbs_read_msg(
	    new_msg->msg_id,
	    new_msg->sim_id,
	    mmi_cbs_idle_content,
	    MMI_CBS_MAX_CONTENT_LEN);

    mmi_cbs_show_content_in_idle(MMI_TRUE);
#endif /* __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__ */

#else /* __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__ */
    if (!mmi_cbs_is_in_inbox_list(new_msg->sim_id))
    {
        cbs_ind_info_struct *ind_info;

        ind_info = mmi_cbs_get_ind_info(new_msg->sim_id, new_msg->mode);

        ind_info->is_ind = MMI_TRUE;
        ind_info->msg_id = new_msg->msg_id;
        ind_info->sim_id = new_msg->sim_id;
        ind_info->mode = new_msg->mode;

        mmi_cbs_entry_new_msg_ind(ind_info);
    }
#endif /* __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__ */

	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_gs_change_event_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_cbs_gs_change_event_proc(mmi_event_struct *evt)
{
#ifdef __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_gs_change_event_struct *change_data = (srv_cbs_gs_change_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_GS_CHANGE_EVENT_PROC, change_data->change_type);

	if (change_data->change_type == SRV_CBS_GS_CELL)
	{
		if (mmi_cbs_is_show_in_idle())
		{
			mmi_cbs_show_content_in_idle(MMI_FALSE);
		}
	}
#endif /* __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__ */

	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_msg_changed_event_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_cbs_msg_changed_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_id = SRV_CBS_INVALID_MSG_ID;
    srv_sms_sim_enum sim_id = SRV_SMS_SIM_1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_MSG_CHANGED_EVENT_PROC, evt->evt_id);

    switch (evt->evt_id)
    {
        case EVT_ID_SRV_CBS_ADD_MSG:
        {
            srv_cbs_add_msg_event_struct *event = (srv_cbs_add_msg_event_struct*)evt;

            msg_id = event->msg_id;
            sim_id = event->sim_id;
            break;
        }

        case EVT_ID_SRV_CBS_DEL_MSG:
        {
            srv_cbs_del_msg_event_struct *event = (srv_cbs_del_msg_event_struct*)evt;

            msg_id = event->msg_id;
            sim_id = event->sim_id;

        #ifdef __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__
            if ((idle_ind_info.msg_id == msg_id) && (idle_ind_info.sim_id == sim_id))
            {
                mmi_cbs_show_content_in_idle(MMI_FALSE);
                idle_ind_info.msg_id = SRV_CBS_INVALID_MSG_ID;
            }
        #endif /* __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__ */

            if ((curr_viewer_cntx != NULL) && 
                (msg_id == curr_viewer_cntx->msg_id) &&
                (sim_id == curr_viewer_cntx->sim_id))
            {
                curr_viewer_cntx->is_del_bg = MMI_TRUE;
            }
            break;
        }
        default:
            break;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_MSG_CHANGED_EVENT_PROC_1, msg_id, sim_id);

    if (msg_id != SRV_CBS_INVALID_MSG_ID)
    {
        if (mmi_cbs_is_in_inbox_list(sim_id))
        {
            if (msg_id != curr_inbox_cntx->msg_id)
            {
                U16 list_index;
				if(evt->evt_id != EVT_ID_SRV_CBS_ADD_MSG)
				{
                    list_index = (S32)srv_cbs_get_list_index(
                                        curr_inbox_cntx->msg_id,
                                        curr_inbox_cntx->sim_id);            

                    curr_inbox_cntx->list_index = list_index;
                } 
            }
        
            mmi_cbs_refresh_inbox_list();
        }
    }

	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_setting_changed_event_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_cbs_setting_changed_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__
    MMI_BOOL is_hiden = MMI_FALSE;;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_SETTING_CHANGED_EVENT_PROC, evt->evt_id);

    switch (evt->evt_id)
    {
        case EVT_ID_SRV_CBS_MODE_CHANGE:
        {
            srv_cbs_mode_change_event_struct *event_data;

            event_data = (srv_cbs_mode_change_event_struct*)evt;

            if (event_data->mode == MMI_FALSE)
            {
                is_hiden = MMI_TRUE;
            }
            break;
        }

        case EVT_ID_SRV_CBS_DEL_CHNL:
        {
            srv_cbs_del_chnl_event_struct *event_data;

            event_data = (srv_cbs_del_chnl_event_struct*)evt;

            if (event_data->chnl_id == idle_ind_info.chnl_id)
            {
                is_hiden = MMI_TRUE;
            }
            break;
        }

        case EVT_ID_SRV_CBS_UPDATE_CHNL:
        {
            srv_cbs_update_chnl_event_struct *event_data;

            event_data = (srv_cbs_update_chnl_event_struct*)evt;

            if ((event_data->old_chnl.id == idle_ind_info.chnl_id) &&
                (event_data->new_chnl.id != idle_ind_info.chnl_id))
            {
                is_hiden = MMI_TRUE;
            }
            break;
        }

        default:
            break;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_SETTING_CHANGED_EVENT_PROC_1, is_hiden);

    if (is_hiden)
    {
        mmi_cbs_show_content_in_idle(MMI_FALSE);
    }
#endif /* __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__ */

	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_mode_switch_event_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_cbs_mode_switch_event_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__
    srv_mode_switch_notify_struct *event_data = (srv_mode_switch_notify_struct*)evt; 
    srv_mode_switch_type_enum curr_mode = (srv_mode_switch_type_enum)event_data->gsm_select_mode;
#if (MMI_MAX_SIM_NUM >=2)
    srv_sms_sim_enum curr_sim = idle_ind_info.sim_id;
#endif /* __GEMINI__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((curr_mode == SRV_MODE_SWITCH_FLIGHT_MODE)
    #if (MMI_MAX_SIM_NUM >=2)
        || ((curr_mode == SRV_MODE_SWITCH_SIM1) && (curr_sim == SRV_SMS_SIM_1))
    #if (MMI_MAX_SIM_NUM >= 4)
        || ((curr_mode == SRV_MODE_SWITCH_SIM2) && (curr_sim == SRV_SMS_SIM_2))
     #if (MMI_MAX_SIM_NUM >= 3)
        || ((curr_mode == SRV_MODE_SWITCH_SIM3) && (curr_sim == SRV_SMS_SIM_3))
     #if (MMI_MAX_SIM_NUM >= 2)
        || ((curr_mode == SRV_MODE_SWITCH_SIM4) && (curr_sim == SRV_SMS_SIM_4))
     #endif
     #endif
     #endif
    #endif /* __MMI_DUAL_SIM_MASTER__ */
       )
    {
        mmi_cbs_show_content_in_idle(MMI_FALSE);
    }
#endif /* __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__ */

	return MMI_RET_OK;
}


#ifdef MMI_CBS_POPUP_NOTIFICATION_STYLE
/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_entry_new_msg_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_entry_new_msg_ind(cbs_ind_info_struct *ind_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_ENTRY_NEW_MSG_IND);

#ifdef __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__
#ifdef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__
    normal_ind_info = ind_info;
    mmi_frm_nmgr_notify_by_idle(MMI_SCENARIO_ID_CELL_BROADCAST, MMI_EVENT_NON_TONE, NULL);
#endif /* __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__ */
#else /* __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__ */
#ifdef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_ENTRY_NEW_MSG_IND_1, ind_info->mode);

    /* The priority of Immediate Msg is larger than Normal Msg */
    if (ind_info->mode == SRV_CBS_MODE_IMMEDICATE)
#endif /* __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__ */
    {
        
        MMI_BOOL is_deferred = MMI_FALSE;
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_ENTRY_NEW_MSG_IND_2, ind_viewer_cntx);
        if (ind_viewer_cntx == NULL)
        {
            is_deferred = mmi_frm_nmgr_is_scenario_deferred(
                            MMI_SCENARIO_ID_CELL_BROADCAST,
                            mmi_cbs_entry_immediate_ind,
                            NULL);
        }
        else
        {
            if ((mmi_frm_group_get_active_id() == ind_viewer_cntx->viewer_gid) &&
                (mmi_frm_scrn_get_active_id() == SCR_ID_CBS_VIEWER))
            {
                mmi_frm_group_close(ind_viewer_cntx->owner_gid);
            } 
        }
        if (!is_deferred)
        {
            mmi_frm_nmgr_notify_by_app(
                MMI_SCENARIO_ID_CELL_BROADCAST,
                MMI_EVENT_NON_TONE,
                mmi_cbs_entry_immediate_ind,
                NULL);
        }
    }
#ifdef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__
    else
    {
        normal_ind_info = ind_info;
        mmi_frm_nmgr_notify_by_idle(MMI_SCENARIO_ID_CELL_BROADCAST, MMI_EVENT_NON_TONE, NULL);
    }
#endif /* __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__ */
#endif /* __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_ind_viewer_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_ind_viewer_launch(MMI_ID parent_gid, cbs_ind_info_struct *ind_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID curr_gid;
    MMI_ID viewer_gid;
    cbs_ind_viewer_cntx_struct *ind_cntx;
    U16 title_str_id;
#if (MMI_MAX_SIM_NUM >=2)
    U16 str_type_array[] =
		       { 
				STR_ID_CBS_SIM1_NEW_MSG_TITLE
				,STR_ID_CBS_SIM2_NEW_MSG_TITLE
		#if (MMI_MAX_SIM_NUM >= 3)
				,STR_ID_CBS_SIM3_NEW_MSG_TITLE
		 #if (MMI_MAX_SIM_NUM >= 4)
				,STR_ID_CBS_SIM4_NEW_MSG_TITLE
		#endif
		#endif
			};
#endif
#if (MMI_MAX_SIM_NUM >=2)
    U32 sim_no=0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(srv_cbs_is_ready(ind_info->sim_id) &&
        srv_sim_ctrl_is_available((mmi_sim_enum)(ind_info->sim_id &(~MMI_GSM)))))
    {
        return;
    }
    
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_IND_VIEWER_LAUNCH);

    ind_cntx = OslMalloc(sizeof(cbs_ind_viewer_cntx_struct));

    curr_gid = mmi_frm_group_create(
                    parent_gid,
                    GRP_ID_AUTO_GEN,
                    mmi_cbs_ind_viewer_proc,
                    ind_cntx);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_IND_VIEWER_LAUNCH_1, curr_gid);

    ind_cntx->owner_gid = curr_gid;
    ind_cntx->sim_id = ind_info->sim_id;
    ind_cntx->msg_id = ind_info->msg_id;
    ind_cntx->ind_info = ind_info;

    mmi_frm_group_enter(curr_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
#if (MMI_MAX_SIM_NUM >=2)
   sim_no = srv_sms_sim_id_to_sim_index(ind_info->sim_id);
   title_str_id = str_type_array[sim_no];
#else /* __GEMINI__ */
    title_str_id = STR_ID_CBS_NEW_MSG_TITLE;     
#endif/*__GEMINI__*/

    viewer_gid = mmi_cbs_viewer_run(
                    curr_gid,
                    ind_info->msg_id,
                    ind_info->sim_id,
                    title_str_id);

    if (viewer_gid != GRP_ID_INVALID)
    {
        ind_cntx->viewer_gid = viewer_gid;
    }
    else
    {
        ind_info->is_ind = MMI_FALSE;
        mmi_frm_group_close(curr_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_ind_viewer_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_cbs_ind_viewer_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    U16 event_id = evt->evt_id;
    cbs_ind_viewer_cntx_struct *ind_cntx = (cbs_ind_viewer_cntx_struct*)evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_IND_VIEWER_PROC, event_id);

    switch (event_id)
    {
        case EVT_ID_GROUP_ACTIVE:
            ind_viewer_cntx = ind_cntx;
            break;
    
        case EVT_ID_GROUP_DEINIT:
        {
            if (ind_viewer_cntx == ind_cntx)
            {
                ind_viewer_cntx = NULL;
            }
            
            mmi_frm_cb_dereg_event(EVT_ID_SRV_CBS_READY_IND, mmi_cbs_ind_viewer_ready_event_hdlr, ind_cntx);
            OslMfree(ind_cntx);                
            break;
        }

        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_MMI_CBS_VIEWER_OP:
        {
            cbs_ind_info_struct *ind_info = ind_cntx->ind_info;

            if (ind_info->is_ind)
            {
                if ((ind_cntx->msg_id == ind_info->msg_id) &&
                    (ind_cntx->sim_id == ind_info->sim_id))
                {
                    ind_info->is_ind = MMI_FALSE;
                }
            }
            break;
        }

        case EVT_ID_GROUP_FIRST_ENTRY:
        {
            mmi_frm_cb_reg_event(EVT_ID_SRV_CBS_READY_IND, mmi_cbs_ind_viewer_ready_event_hdlr, ind_cntx);
            break;
        }
        
        default:
            break;
    }

    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_ind_viewer_ready_event_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_cbs_ind_viewer_ready_event_hdlr(mmi_event_struct *evt)
{
#ifdef __SIM_HOT_SWAP_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_ready_event_struct *event_data = (srv_cbs_ready_event_struct*)evt; 
    cbs_ind_viewer_cntx_struct *ind_cntx = (cbs_ind_viewer_cntx_struct*)evt->user_data;
    mmi_id cb_ind_group = ind_cntx->owner_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(mmi_frm_group_is_present(cb_ind_group) || mmi_frm_group_is_in_active_serial(cb_ind_group));
    if ((MMI_FALSE == event_data->is_ready) 
    #if (MMI_MAX_SIM_NUM >=2)
        && (ind_cntx->sim_id && event_data->sim_id)
    #endif /* (MMI_MAX_SIM_NUM >=2) */
        )
    {
        mmi_frm_group_close(cb_ind_group);
    }
#endif
	return MMI_RET_OK;
}


#ifndef __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__
/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_entry_immediate_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_cbs_entry_immediate_ind(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_ENTRY_IMMEDIATE_IND, scen_id);

    mmi_cbs_ind_viewer_launch(mmi_idle_get_group_id(), &immediate_ind_info);

	return MMI_TRUE;
}
#endif /* __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_get_ind_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static cbs_ind_info_struct* mmi_cbs_get_ind_info(
                                srv_sms_sim_enum sim_id,
                                srv_cbs_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbs_ind_info_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_GET_IND_INFO, sim_id, mode);

#ifdef __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__
    {
        U32 index;
        index = srv_sms_sim_id_to_sim_index(sim_id);
        cntx = &normal_ind_info_array[index];
    }
#else /* __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__ */
#ifdef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__
    if (mode == SRV_CBS_MODE_NORMAL)
    {
        U32 index;
        index = srv_sms_sim_id_to_sim_index(sim_id);
        cntx = &normal_ind_info_array[index];
    }
    else
#endif /* __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__ */
    {
        cntx = &immediate_ind_info;
    }
#endif /* __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__ */

    return cntx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_cancel_new_msg_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_cancel_new_msg_ind(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__
    U32 i;
#endif /* __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__
    if (immediate_ind_info.is_ind && (immediate_ind_info.sim_id == sim_id))
    {
        immediate_ind_info.is_ind = MMI_FALSE;

        mmi_frm_nmgr_cancel_deferred_scenario(
            MMI_SCENARIO_ID_CELL_BROADCAST,
            mmi_cbs_entry_immediate_ind,
            NULL);
    }
#endif /* __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__ */

#ifdef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__
    for (i = 0; i < MMI_CBS_SIM_NUM; i++)
    {
        if (normal_ind_info_array[i].is_ind && 
            (normal_ind_info_array[i].sim_id == sim_id))
        {
            normal_ind_info_array[i].is_ind = MMI_FALSE;
        }
    }
#endif /* __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__ */
}
#endif /* MMI_CBS_POPUP_NOTIFICATION_STYLE */


#ifdef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__

#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_nmgr_need_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_cbs_nmgr_need_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_CBS_SIM_NUM; i++)
    {
        if (normal_ind_info_array[i].is_ind)
        {
            normal_ind_info = &normal_ind_info_array[i];
            result = MMI_TRUE;
            break;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_NMGR_NEED_IND, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_nmgr_query_ind_notify
 * DESCRIPTION
 *  notify manager CB query function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cbs_nmgr_query_ind_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_no;
#if (MMI_MAX_SIM_NUM >=2)
    U16 str_type_array[] =
		       { 
				STR_ID_CBS_NEW_SIM1_MSG_FROM
				,STR_ID_CBS_NEW_SIM2_MSG_FROM
		#if (MMI_MAX_SIM_NUM >= 3)
				,STR_ID_CBS_NEW_SIM3_MSG_FROM
		 #if (MMI_MAX_SIM_NUM >= 4)
				,STR_ID_CBS_NEW_SIM4_MSG_FROM
		#endif
		#endif
			};
#endif
	U16 str_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_NMGR_QUERY_IND_NOTIFY);

    if ((normal_ind_info == NULL) ||
        (!srv_cbs_is_ready(normal_ind_info->sim_id)))
	{
        mmi_nmgr_answer(
            MMI_NMGR_APP_CELL_BROADCAST,
            MMI_NMGR_RESULT_NOT_READY,
            NULL,
            NULL);
	}
    else
    {
        mmi_nmgr_info_struct info;
        U16 chnl_id;
        static WCHAR chnl_name[SRV_CBS_CHNL_NAME_LEN + 1];

    #ifdef __LOW_COST_SUPPORT_COMMON__
        info.image = IMG_NEW_MESSAGE_NOTIFICATION_MSG;
    #else
        info.image = IMG_NEW_MESSAGE_NOTIFICATION_MSG_IN_IDLE;
    #endif /* __LOW_COST_SUPPORT_COMMON__ */
        info.left_softkey = STR_GLOBAL_READ;
        
        if (normal_ind_info->is_ind)
        {
            info.total_num = 1;
        }
        else
        {
            info.total_num = 0;
        }

        info.user_data = normal_ind_info;

    #if (MMI_MAX_SIM_NUM >=2)
	 sim_no = srv_sms_sim_id_to_sim_index(normal_ind_info->sim_id);
	 str_id = str_type_array[sim_no];
        info.idle_text1 = GetString(str_id);
    #else /* __GEMINI__ */
        info.idle_text1 = GetString(STR_ID_CBS_NEW_MSG_FROM);
    #endif  /* __MMI_DUAL_SIM_MASTER__ */

        chnl_id = srv_cbs_get_msg_chnl_id(normal_ind_info->msg_id, normal_ind_info->sim_id);
        srv_cbs_get_channel_name(chnl_name, chnl_id, normal_ind_info->sim_id);

        if (mmi_wcslen(chnl_name) == 0)
        {
            kal_wsprintf((WCHAR*)chnl_name, "%d", chnl_id);
        }
    
        info.idle_text2 = (S8*)chnl_name;

        mmi_nmgr_answer(
            MMI_NMGR_APP_CELL_BROADCAST,
            MMI_NMGR_RESULT_OK,
            &info,
            mmi_cbs_nmgr_ind_notify_key_hdlr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_nmgr_cancel_ind_notify
 * DESCRIPTION
 *  cancel the CB notification flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cbs_nmgr_cancel_ind_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_NMGR_CANCEL_IND_NOTIFY);
    normal_ind_info->is_ind = MMI_FALSE;
}
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_nmgr_ind_notify_key_hdlr
 * DESCRIPTION
 *  CB notification mananger LSK key handler
 * PARAMETERS
 *  user_data   [IN]    CB user data
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbs_nmgr_ind_notify_key_hdlr(void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_NMGR_IND_NOTIFY_KEY_HDLR);

    normal_ind_info->is_ind = MMI_FALSE;

    mmi_cbs_ind_viewer_launch(mmi_idle_get_group_id(), (cbs_ind_info_struct*)user_data);
}
#endif /* __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_entry_new_cb_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_cbs_entry_new_cb_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_ENTRY_NEW_CB_IND);

#ifndef __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__
    mmi_cbs_entry_new_msg_ind(&immediate_ind_info);
#endif /* __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_need_new_cb_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_cbs_need_new_cb_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_NEED_NEW_CB_IND, MMI_FALSE);
    return MMI_FALSE;
#else /* __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__ */
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_NEED_NEW_CB_IND, immediate_ind_info.is_ind);
    return immediate_ind_info.is_ind;
#endif /* __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_is_in_inbox_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_cbs_is_in_inbox_list(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((curr_inbox_cntx != NULL) &&
        (curr_inbox_cntx->sim_id == sim_id) && 
        (mmi_frm_scrn_get_active_id() == SCR_ID_CBS_INBOX_LIST))
    {

        result = MMI_TRUE;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_IS_IN_INBOX_LIST, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_refresh_inbox_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_refresh_inbox_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 total_item = srv_cbs_get_msg_num(curr_inbox_cntx->sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_REFRESH_INBOX_LIST, total_item);

    mmi_cat_refresh_asyncdynamic_list(total_item, curr_inbox_cntx->list_index, mmi_cbs_inbox_list_get_item, NULL);

    if (total_item > 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
        ChangeCenterSoftkey(0, IMG_NONE);
    }
}
#endif /*__MMI_CBS_SUPPORT__*/

#endif /*__MMI_TELEPHONY_SUPPORT__*/
