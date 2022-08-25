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
*  CallLogMainMenu.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_features.h"
#include "MMIDataType.h"

#if defined(__MMI_TELEPHONY_SUPPORT__) || defined(__MMI_BT_PBAP_CLIENT__)

#include "menucuigprot.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "GlobalResDef.h"
#include "CommonScreensResDef.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "DebugInitDef_Int.h"
#include "string.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "AlertScreen.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "GlobalConstants.h"
#include "mmi_frm_mem_gprot.h"

#include "CallLogSrvGprot.h"
#include "CallLogConfig.h"
#include "CallLogProt.h"
#include "CallLogLayout.h"
#include "mmi_rp_app_calllog_def.h"
#if defined(__MMI_BT_PBAP_CLIENT__)
#if defined(__MMI_PHB_PBAPC_SYNC_CONTACT__)
#include "mmi_rp_app_phonebook_def.h"
#include "calllogAdpPbapc.h"
#endif
#endif

#ifdef __MMI_NCENTER_SUPPORT__
#include "Vsrv_ncenter.h"
#endif


/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
/*---------------------- Instance --------------------------------------------*/
#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
static mmi_clog_inst_struct *mmi_clog_alloc_inst(mmi_clog_cntx_struct *cntx);
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
static void mmi_clog_destroy_inst(mmi_clog_inst_struct *inst);
#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
static mmi_clog_inst_struct *mmi_clog_get_inst_by_pid(S32 pid);
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */

/*---------------------- Group proc -----------------------------------------*/
static MMI_RET mmi_clog_group_proc(mmi_event_struct *evt);

/*---------------------- Misc ------------------------------------------------*/

/*---------------------- UI Elements -----------------------------------------*/
/* Screen Entry */
static void mmi_clog_enter(mmi_clog_inst_struct *inst);
#ifdef __MMI_CLOG_TAB_SUPPORT__
static void mmi_clog_enter_tab(mmi_clog_inst_struct *inst);
#endif
static void mmi_clog_enter_lt(mmi_clog_inst_struct *inst, S32 by_menu_id);

#ifndef __MMI_CLOG_TAB_SUPPORT__
static void mmi_clog_enter_list(mmi_clog_inst_struct *inst);

/*---------------------- Menu CUI --------------------------------------------*/
/* CUI Entry */
static void mmi_clog_enter_cui_list(mmi_clog_inst_struct *inst, MMI_MENU_ID root_menu_id);
static void mmi_clog_hide_menu(MMI_ID mm_gid);

/* CUI Event Handler */
#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
static MMI_RET mmi_clog_evt_mc_entry_hdlr(cui_menu_event_struct *evt);
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
#ifndef __MMI_CLOG_FPBW__
static void mmi_clog_set_hint(mmi_clog_inst_struct *inst, MMI_MENU_ID menu_id);
#endif /*__MMI_CLOG_FPBW__*/
static void mmi_clog_format_hint(srv_clog_num_info_struct *num_info, WCHAR *buf, U32 buf_len);
static void mmi_clog_evt_mc_hlt_hdlr(cui_menu_event_struct *evt);
static void mmi_clog_evt_mc_select_hdlr(
                mmi_clog_inst_struct *inst,
                MMI_MENU_ID parent_gid,
                MMI_MENU_ID sel_menu_id);
static void mmi_clog_enter_sub_items(mmi_clog_inst_struct *inst, MMI_MENU_ID parent_menu_id);
static void mmi_clog_evt_mc_close_hdlr(mmi_clog_inst_struct *inst);

/* Delete box */
static void mmi_clog_if_delete_log_list(mmi_clog_inst_struct *inst);
static void mmi_clog_delete_log_list(mmi_clog_inst_struct *inst);
static MMI_MENU_ID mmi_clog_menu_id_del2clt(MMI_MENU_ID del_menu_id);
static S32 mmi_clog_delete_all_logs_result(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            void *req_data,
            void *cnf_data,
            MMI_BOOL more,
            srv_clog_ret_enum ret);
#endif /* __MMI_CLOG_TAB_SUPPORT__*/
/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
#ifndef __MMI_CLOG_TAB_SUPPORT__
extern NMGR_HANDLE nmgr_handle;
#endif /*__MMI_CLOG_TAB_SUPPORT__*/

#if defined(__MMI_BT_PBAP_CLIENT__)
extern mmi_clog_rsp_missed_call g_is_missed_call;
#endif
#ifdef __MMI_NCENTER_SUPPORT__
extern vsrv_notification_handle g_ncenter_hdl;
#endif /*__MMI_NCENTER_SUPPORT__*/

#if defined(__MMI_BT_PBAP_CLIENT__) && defined(__MMI_PHB_PBAPC_SYNC_CONTACT__)
extern mmi_clog_pbapc_ex_inst_struct* mmi_clog_get_pbapc_cntx_ex();
#endif


/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_update_status_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_update_status_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* For Gemini/Gemini+, only one status icon is needed */
#ifdef __MMI_TELEPHONY_SUPPORT__
    if (0 != srv_clog_get_unread_missed_call_num())
    {
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_MISSED_CALL);
    #if (defined(__MMI_SUBLCD__) && !defined(__MMI_SUBLCD_SHORT_STATUSICON_LIST__))
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_SUBLCD_MISSED_CALL);
    #endif
    }
    else
    {
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_MISSED_CALL);
    #if (defined(__MMI_SUBLCD__) && !defined(__MMI_SUBLCD_SHORT_STATUSICON_LIST__))
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SUBLCD_MISSED_CALL);
    #endif
    }
#endif /* __MMI_TELEPHONY_SUPPORT__ */
    wgui_status_icon_bar_update();
}


#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_alloc_inst
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static mmi_clog_inst_struct *mmi_clog_alloc_inst(mmi_clog_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_CLOG_INST_MAX_NUM == 1) /* For slim */
    {
        MMI_CLOG_SET_BIT(cntx->inst_list[0].flags, MMI_CLOG_CMN_INST_FLAG_IS_USED | MMI_CLOG_INST_TYPE_CLOG);
        return &cntx->inst_list[0];
    }
    else
    {
        for (i = 0; i < MMI_CLOG_INST_MAX_NUM; i++)
        {
            if (!MMI_CLOG_CHECK_BIT(cntx->inst_list[i].flags, MMI_CLOG_CMN_INST_FLAG_IS_USED))
            {
                MMI_CLOG_SET_BIT(cntx->inst_list[i].flags, MMI_CLOG_CMN_INST_FLAG_IS_USED | MMI_CLOG_INST_TYPE_CLOG);
                return &cntx->inst_list[i];
            }
        }
        MMI_CLOG_ASSERT(0);
        return NULL;
    }
}
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_destroy_inst
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_destroy_inst(mmi_clog_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!MMI_CLOG_IS_INST_VALID(inst, MMI_CLOG_INST_TYPE_CLOG))
        return;
#ifdef __MMI_TELEPHONY_SUPPORT__
    if (!SRV_CLOG_IS_ELM_INVALID(inst->handle))
        srv_clog_destroy(inst->handle);
#endif /* __MMI_TELEPHONY_SUPPORT__ */
    memset(inst, 0x0, sizeof(mmi_clog_inst_struct));
}


#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_get_inst_by_pid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pid     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_clog_inst_struct *mmi_clog_get_inst_by_pid(S32 pid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_clog_inst_struct *inst;
    mmi_clog_cntx_struct *cntx = mmi_clog_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_CLOG_INST_MAX_NUM == 1) /* For slim */
    {
        inst = &cntx->inst_list[0];
        if (MMI_CLOG_IS_INST_VALID(inst, MMI_CLOG_INST_TYPE_CLOG) && inst->srv_pid == pid)
            return inst;
        else
            return NULL;
    }
    else
    {
        for (i = 0; i < MMI_CLOG_INST_MAX_NUM; i++)
        {
            inst = &cntx->inst_list[i];
            if (!MMI_CLOG_IS_INST_VALID(inst, MMI_CLOG_INST_TYPE_CLOG))
                continue;
            if (inst->srv_pid == pid)
                return inst;
        }
        /* The inst may be destroy as group is invalid */
        return NULL;
    }
}
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_create_srv_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static SRV_CLOG_HANDLE mmi_clog_create_srv_handle(mmi_clog_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_create_struct create;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_init_para(SRV_CLOG_PARA_CREATE, &create);
    create.user_data = inst;
    return srv_clog_create(&create);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_get_num_info_by_menu_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst            [IN]         
 *  menu_id         [IN]        
 *  num_info        [IN]         
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_get_num_info_by_menu_id(
            mmi_clog_inst_struct *inst,
            MMI_MENU_ID menu_id,
            srv_clog_num_info_struct *num_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    const mmi_clog_lt_id_attr_struct *attr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    attr = mmi_clog_get_attr_by_menu_id(menu_id);
    if (!attr)
        return MMI_FALSE;
#ifdef __MMI_TELEPHONY_SUPPORT__
    ret = srv_clog_get_list_num_info(inst->handle, &attr->idt, num_info);
    if (ret != SRV_CLOG_RET_OK)
        return MMI_FALSE;
#endif /* __MMI_TELEPHONY_SUPPORT__ */
    return MMI_TRUE;
}

#ifdef __MMI_APP_MANAGER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_appmgr_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_id mmi_clog_appmgr_launch(void* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_launch();
    return GRP_ID_CLOG_ROOT;
}
#endif /* __MMI_APP_MANAGER_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if SRV_PBAPC_LINK_NUM >= 2
#if defined (__MMI_BT_PBAP_CLIENT__) && defined (__MMI_PHB_PBAPC_SYNC_CONTACT__)
static void mmi_clog_pbapc_bt_mydev_highlight_hdlr(S32 idx)
{
    mmi_clog_pbapc_ex_inst_struct *pbapc_cntx = NULL; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pbapc_cntx = mmi_clog_get_pbapc_cntx_ex();
    pbapc_cntx->index= idx;
}


void mmi_clog_bt_enter_list(void)
{
    g_is_missed_call.is_from_bt = MMI_FALSE;

    mmi_clog_launch_ex(GRP_ID_CLOG_BEGIN, MMI_CLOG_MAINMENU_DEF_LT_TYPE, MMI_CLOG_MAINMENU_DEF_LT_ID);
}


static S32 mmi_clog_pbapc_bt_get_mydev_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    U8 index, idx;
    S32 ret;
    srv_bt_cm_bt_addr addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < data_size; index++)
    {
        idx = item_index + index;
        
        ret = srv_phb_pbapc_get_btd_addr(&addr, idx);
        kal_prompt_trace(MOD_MMI, "[TEST]mmi_clog_pbapc_bt_get_mydev_item: ret = %d, idx = %d", ret, idx);        
        if (ret >= 0)
        {
            srv_bt_cm_get_dev_ucs2_name(&addr, SRV_BT_CM_BD_UCS2_NAME_LEN, menu_data[index].item_list[0]);
        }
        else
        {
            kal_wsprintf(
                menu_data[idx].item_list[0],
                "%w",
                (U16*)GetString(STR_ID_PHB_PBAPC_BT1 + idx));
        }
        menu_data[idx].image_list[0] = NULL;
    }
    
    return data_size;


}


void mmi_clog_pbap_bt_dev_name_list(void)
{
    U8* guiBuffer;
    U32 i;

    if (!mmi_frm_scrn_enter(
    GRP_ID_CLOG_BEGIN,
    SCR_ID_CLOG_NAME_LIST,
    NULL,
    mmi_clog_pbap_bt_dev_name_list,
    MMI_FRM_FULL_SCRN))
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    RegisterHighlightHandler(mmi_clog_pbapc_bt_mydev_highlight_hdlr);
    //wgui_list_menu_disable_access_by_shortcut();

    wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_NO_ICON);

    wgui_cat1032_show(
     (WCHAR*)GetString(MAIN_MENU_CALL_LOG_TEXT),
     (PU8)GetImage(GetRootTitleIcon(MAIN_MENU_CALL_LOG)),
    (WCHAR*)GetString(STR_GLOBAL_OK),
     0,
     (WCHAR*)GetString(STR_GLOBAL_BACK),
     (PU8)GetImage(IMG_GLOBAL_BACK),
     2,
     mmi_clog_pbapc_bt_get_mydev_item,
     NULL,
     0,
     0,
     NULL,
     NULL,
     guiBuffer,
     NULL);
    wgui_restore_list_menu_slim_style();

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_clog_bt_enter_list, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_clog_bt_enter_list, KEY_EVENT_UP);
        
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
            wgui_register_tap_callback(mmi_clog_bt_enter_list);
#endif  // defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)

}


void mmi_clog_bt_list_launch()
{
    MMI_ID gid;
    mmi_clog_cntx_struct *cntx;
    mmi_clog_inst_struct *inst;
    SRV_CLOG_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gid = mmi_clog_get_valid_act_gid();

    gid = mmi_clog_alloc_gid(MMI_CLOG_GRP_TYPE_NM);

    mmi_frm_group_create(GRP_ID_ROOT, gid, NULL, NULL);

    mmi_frm_group_enter(gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_clog_pbap_bt_dev_name_list();
}
#endif
#endif

void mmi_clog_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if SRV_PBAPC_LINK_NUM >= 2

#if defined (__MMI_BT_PBAP_CLIENT__) && defined (__MMI_PHB_PBAPC_SYNC_CONTACT__)

    mmi_clog_bt_list_launch(GRP_ID_ROOT);
#else
    mmi_clog_launch_ex(GRP_ID_ROOT, MMI_CLOG_SENDKEY_DEF_LT_TYPE, MMI_CLOG_SENDKEY_DEF_LT_ID);
#endif
#else
    mmi_clog_launch_ex(GRP_ID_ROOT, MMI_CLOG_MAINMENU_DEF_LT_TYPE, MMI_CLOG_MAINMENU_DEF_LT_ID);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_sendkey_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_sendkey_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if SRV_PBAPC_LINK_NUM >= 2
#if defined (__MMI_BT_PBAP_CLIENT__) && defined (__MMI_PHB_PBAPC_SYNC_CONTACT__)
    mmi_clog_bt_list_launch(GRP_ID_ROOT);
#else
    mmi_clog_launch_ex(GRP_ID_ROOT, MMI_CLOG_SENDKEY_DEF_LT_TYPE, MMI_CLOG_SENDKEY_DEF_LT_ID);

#endif
#else

    mmi_clog_launch_ex(GRP_ID_ROOT, MMI_CLOG_SENDKEY_DEF_LT_TYPE, MMI_CLOG_SENDKEY_DEF_LT_ID);

#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_dclt_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_dclt_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_launch_ex(GRP_ID_ROOT, MMI_CLOG_MAINMENU_DEF_LT_TYPE, MMI_CLOG_LT_ID_DIALED_CALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_mclt_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_clog_test_get_last_num(U8* number, S32 error_code)
{
    if (error_code>=0 ) 
    {


    }

}
void mmi_clog_mclt_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_launch_ex(GRP_ID_ROOT, MMI_CLOG_MAINMENU_DEF_LT_TYPE, MMI_CLOG_LT_ID_MISSED_CALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_rclt_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_rclt_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_launch_ex(GRP_ID_ROOT, MMI_CLOG_MAINMENU_DEF_LT_TYPE, MMI_CLOG_LT_ID_RECVED_CALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_aclt_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_aclt_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_launch_ex(GRP_ID_ROOT, MMI_CLOG_MAINMENU_DEF_LT_TYPE, MMI_CLOG_LT_ID_ALL_CALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_launch_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_gid      [IN]        
 *  lt_type         [IN]        
 *  lt_id           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_launch_ex(MMI_ID parent_gid, mmi_clog_lt_type_enum lt_type, mmi_clog_lt_id_enum lt_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    MMI_ID gid;
    mmi_clog_cntx_struct *cntx;
    mmi_clog_inst_struct *inst;
    SRV_CLOG_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gid = mmi_clog_get_valid_act_gid();
#if defined(__MMI_TELEPHONY_SUPPORT__)
    if (!mmi_clog_is_ready())
    {
        if (mmi_frm_group_is_in_top_scope(gid))
            mmi_clog_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE, MMI_EVENT_FAILURE, gid, NULL);

        MMI_CLOG_IT_TRACE((MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_LAUNCH_EX, parent_gid, lt_type, lt_id, -1, GRP_ID_INVALID, 0));

        return;
    }
#endif /* __MMI_TELEPHONY_SUPPORT__ */
    /* Please not change the order of all Group id in CallLog.Res as it's used here */
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
    for (i = GRP_ID_CLOG_ROOT; i < SCR_ID_CLOG_MAIN_MENU; i++)
#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    for (i = GRP_ID_CLOG_ROOT; i < GRP_ID_CLOG_GPRS_COUNT_LAST; i++)
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    {
        if (mmi_frm_group_is_present((MMI_ID)i))
            mmi_frm_group_close((MMI_ID)i);
    }

#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
    cntx = mmi_clog_get_cntx();
    inst = &cntx->inst_list[0];
    MMI_CLOG_SET_BIT(inst->flags, MMI_CLOG_CMN_INST_FLAG_IS_USED | MMI_CLOG_INST_TYPE_CLOG);
    gid = GRP_ID_CLOG_ROOT;
#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    cntx = mmi_clog_get_cntx();
    inst = mmi_clog_alloc_inst(cntx);
    if (!inst)
    {
        if (mmi_frm_group_is_in_top_scope(gid))
            mmi_clog_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE, MMI_EVENT_FAILURE, gid, NULL);

        MMI_CLOG_IT_TRACE((MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_LAUNCH_EX, parent_gid, lt_type, lt_id, -2, GRP_ID_INVALID, 0));
        return;
    }

    gid = mmi_clog_alloc_gid(MMI_CLOG_GRP_TYPE_MM);
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    MMI_CLOG_IT_ASSERT(!MMI_CLOG_IS_GID_INVALID(gid));
    gid = mmi_frm_group_create_ex(parent_gid, gid, mmi_clog_group_proc, inst, MMI_FRM_NODE_SMART_CLOSE_FLAG);
#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
  #ifdef __MMI_TELEPHONY_SUPPORT__
    handle = mmi_clog_create_srv_handle(inst);
  #endif /* __MMI_TELEPHONY_SUPPORT__ */
#if defined(__MMI_TELEPHONY_SUPPORT__)
    if (SRV_CLOG_IS_ELM_INVALID(handle))
    {
        if (mmi_frm_group_is_in_top_scope(gid))
            mmi_clog_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE, MMI_EVENT_FAILURE, gid, NULL);

        MMI_CLOG_IT_TRACE((MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_LAUNCH_EX, parent_gid, lt_type, lt_id, -3, gid, handle));

        return;
    }
#endif /* __MMI_TELEPHONY_SUPPORT__ */
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    inst->self_gid = gid;
    inst->lt_type = lt_type;
    inst->sel_lt_id = lt_id;
#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
#ifdef __MMI_TELEPHONY_SUPPORT__
    inst->handle = handle;
#endif
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_LAUNCH_EX, parent_gid, lt_type, lt_id, 0, gid, inst->handle);

    mmi_clog_update_mini_tab_bar();

    mmi_clog_enter(inst);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static MMI_RET mmi_clog_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/            
    mmi_clog_inst_struct *inst = (mmi_clog_inst_struct*) evt->user_data;
    cui_menu_event_struct *mc_evt = (cui_menu_event_struct*) evt;
    mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:           
            mmi_clog_destroy_inst(inst);
            break;
#if !defined(__MMI_CLOG_TAB_SUPPORT__)
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            //mmi_clog_evt_mc_entry_hdlr(mc_evt);
            break;

        case EVT_ID_CUI_MENU_ITEM_HILITE:
            mmi_clog_evt_mc_hlt_hdlr(mc_evt);
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_clog_evt_mc_select_hdlr(inst, mc_evt->parent_menu_id, mc_evt->highlighted_menu_id);
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            mmi_clog_evt_mc_close_hdlr(inst);
            break;
            
        case EVT_ID_ALERT_QUIT:
            if (alert->result == MMI_ALERT_CNFM_YES)
                mmi_clog_delete_log_list(inst);
            break;
#endif /*__MMI_CLOG_TAB_SUPPORT__*/
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_enter(mmi_clog_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_CLOG_TAB_SUPPORT__)

    if (inst->lt_type == MMI_CLOG_LT_TYPE_LIST)
    {
        mmi_clog_enter_list(inst);
    }
#else /*__MMI_CLOG_TAB_SUPPORT__*/    

    if (inst->lt_type == MMI_CLOG_LT_TYPE_TAB)
    {
        mmi_clog_enter_tab(inst);
    }

#endif /* __MMI_CLOG_TAB_SUPPORT__ */

}


#ifdef __MMI_CLOG_TAB_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_tab
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_enter_tab(mmi_clog_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_enter_lt(inst, MMI_FALSE);
}
#endif /* __MMI_CLOG_TAB_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_lt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst            [IN]         
 *  by_menu_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void mmi_clog_enter_lt(mmi_clog_inst_struct *inst, S32 by_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID lt_gid;
    const mmi_clog_lt_id_attr_struct *attr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (by_menu_id)
    {
        attr = mmi_clog_get_attr_by_menu_id(inst->sel_menu_id);
        MMI_CLOG_ASSERT(attr);
        inst->sel_lt_id = attr->lt_id;
    }
	lt_gid = mmi_clog_lt_create_and_run(inst, MMI_CLOG_LT_STYLE_LIST);
	MMI_CLOG_ASSERT(!MMI_CLOG_IS_GID_INVALID(lt_gid));
}


#ifndef __MMI_CLOG_TAB_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_enter_list(mmi_clog_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (inst->sel_lt_id)
    {
        case MMI_CLOG_LT_ID_DIALED_CALL:
        case MMI_CLOG_LT_ID_MISSED_CALL:
        case MMI_CLOG_LT_ID_RECVED_CALL:
        case MMI_CLOG_LT_ID_ALL_CALL:
            mmi_clog_enter_lt(inst, MMI_FALSE);
            break;

        case MMI_CLOG_LT_ID_UNKNOWN:
            inst->sel_lt_id = MMI_CLOG_LT_ID_DIALED_CALL;
            mmi_clog_enter_cui_list(inst, MAIN_MENU_CALL_LOG);
            break;

        default:    /* Main menu */
            MMI_CLOG_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_cui_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst                [IN]         
 *  root_menu_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_enter_cui_list(mmi_clog_inst_struct *inst, MMI_MENU_ID root_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst->mm_gid = cui_menu_create(
                    inst->self_gid,
                    CUI_MENU_SRC_TYPE_RESOURCE,
                    CUI_MENU_TYPE_APPMAIN,
                    root_menu_id,
                    MMI_TRUE,
                    inst);

    MMI_CLOG_ASSERT(!MMI_CLOG_IS_GID_INVALID(inst->mm_gid));
#ifndef __MMI_CLOG_SLIM__
    cui_menu_set_default_title_image_by_id(inst->mm_gid, GetRootTitleIcon(MAIN_MENU_CALL_LOG));
#endif /*__MMI_CLOG_SLIM__*/
    mmi_clog_hide_menu(inst->mm_gid);
    cui_menu_run(inst->mm_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_hide_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mm_gid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_hide_menu(MMI_ID mm_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//#if !defined(__OP12__) && !defined(__MMI_CLOG_FPBW__) 
  //  cui_menu_set_item_hidden(mm_gid, MENU_ID_CLOG_ALL_CALL, MMI_TRUE);
//#endif 
#ifdef __MMI_BT_PBAP_CLIENT__
    cui_menu_set_item_hidden(mm_gid, MENU_ID_CLOG_DELETE_BOX, MMI_TRUE);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_evt_mc_entry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static MMI_RET mmi_clog_evt_mc_entry_hdlr(cui_menu_event_struct *evt)
{
#ifndef __MMI_CLOG_FPBW__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 count;
    MMI_MENU_ID menu_id;
    mmi_clog_inst_struct *inst = (mmi_clog_inst_struct*) evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = cui_menu_get_currlist_item_count(evt->sender_id);
    for (i = 0; i < MMI_CLOG_LT_ID_MAX_NUM && i < count; i++)
    {
        menu_id = cui_menu_get_currlist_menu_id_from_index(evt->sender_id, i);
        mmi_clog_set_hint(inst, menu_id);
    }
#else /*__MMI_CLOG_FPBW__*/

    cui_menu_set_currlist_flags(evt->sender_id,CUI_MENU_LIST_WITH_NO_ICON );

#endif /*__MMI_CLOG_FPBW__*/
    return MMI_RET_OK;
}

#ifndef __MMI_CLOG_FPBW__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_set_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]         
 *  menu_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_set_hint(mmi_clog_inst_struct *inst, MMI_MENU_ID menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    MMI_MENU_ID clt_menu_id;
    srv_clog_num_info_struct num_info = {0};
    WCHAR value[MAX_SUB_MENU_HINT_SIZE / ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clt_menu_id = mmi_clog_menu_id_del2clt(menu_id);
    ret = mmi_clog_get_num_info_by_menu_id(inst, clt_menu_id, &num_info);
    if (!ret)
        return;
    mmi_clog_format_hint(&num_info, value, MAX_SUB_MENU_HINT_SIZE / ENCODING_LENGTH - 1);
    cui_menu_set_item_hint(inst->mm_gid, menu_id, value);
}
#endif /* __MMI_CLOG_FPBW__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_format_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  num_info        [IN]         
 *  buf             [OUT]         
 *  buf_len         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_format_hint(srv_clog_num_info_struct *num_info, WCHAR *buf, U32 buf_len)
{
#ifndef __MMI_CLOG_FPBW__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 total_num;
    WCHAR *temp_buf;
    MMI_STR_ID str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total_num = num_info->num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS];
    if (!total_num)
    {
        mmi_wcsncpy(buf, (const WCHAR*)get_string(STR_ID_CLOG_NO_ENTRY), buf_len);
    }
    else
    {
        str_id = (total_num == 1 ? STR_ID_CLOG_ENTRY : STR_ID_CLOG_ENTRIES);
        temp_buf = OslMalloc(MMI_CLOG_TMP_BUF_SIZE);
        kal_wsprintf(temp_buf, "%d %w", total_num, get_string(str_id));
		mmi_wcsncpy(buf, temp_buf, buf_len);
        OslMfree(temp_buf);
    }
#endif /* __MMI_CLOG_FPBW__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_evt_mc_hlt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt            [IN]         
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_clog_evt_mc_hlt_hdlr(cui_menu_event_struct *evt)
{
#ifndef __MMI_CLOG_FPBW__
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    MMI_MENU_ID clt_menu_id;
    srv_clog_num_info_struct num_info = {0};
    mmi_clog_inst_struct *inst = (mmi_clog_inst_struct*) evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->parent_menu_id != MENU_ID_CLOG_DELETE_BOX)
        return ;

    clt_menu_id = mmi_clog_menu_id_del2clt(evt->highlighted_menu_id);
    ret = mmi_clog_get_num_info_by_menu_id(inst, clt_menu_id, &num_info);
    if (!ret)
        return ;
    if (num_info.num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS] == 0)
    {
        cui_menu_change_left_softkey_string(inst->mm_gid, NULL);
        cui_menu_change_center_softkey_content(inst->mm_gid, NULL, NULL);
    }
#endif /*__MMI_CLOG_FPBW__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_evt_mc_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst                [IN]         
 *  parent_menu_id      [IN]        
 *  sel_menu_id         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
 static void mmi_clog_evt_mc_select_hdlr(
                mmi_clog_inst_struct *inst,
                MMI_MENU_ID parent_menu_id,
                MMI_MENU_ID sel_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst->sel_menu_id = sel_menu_id;
    mmi_clog_enter_sub_items(inst, parent_menu_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_sub_items
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst                [IN]         
 *  parent_menu_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_enter_sub_items(mmi_clog_inst_struct *inst, MMI_MENU_ID parent_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
	MMI_MENU_ID clt_menu_id;
    srv_clog_num_info_struct num_info = {0};   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (inst->sel_menu_id)
    {
        case MENU_ID_CLOG_DIALED_CALL:
        case MENU_ID_CLOG_MISSED_CALL:
        case MENU_ID_CLOG_RECVED_CALL:
        case MENU_ID_CLOG_ALL_CALL:
            mmi_clog_enter_lt(inst, MMI_TRUE);
            break;
        case MENU_ID_CLOG_DEL_DIALED_CALL:
        case MENU_ID_CLOG_DEL_MISSED_CALL:
        case MENU_ID_CLOG_DEL_RECVED_CALL:
        case MENU_ID_CLOG_DEL_ALL_CALL:
            clt_menu_id = mmi_clog_menu_id_del2clt(inst->sel_menu_id);
            ret = mmi_clog_get_num_info_by_menu_id(inst, clt_menu_id, &num_info);
            if (!ret)
            {             
#ifdef __MMI_CLOG_FPBW__ 
                mmi_clog_popup(STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE, inst->self_gid, inst);
#endif /*__MMI_CLOG_FPBW__*/
                return ;
            }
            if (num_info.num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS] == 0)
            {  
#ifdef __MMI_CLOG_FPBW__             
                mmi_clog_popup(STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE, inst->self_gid, inst);                
#endif /*__MMI_CLOG_FPBW__*/
                return ;
            }
            mmi_clog_if_delete_log_list(inst);
            break;

        case MENU_ID_CLOG_DELETE_BOX:
            break;

        default:
#ifdef __MMI_CLOG_ACCESSORIES__
            mmi_clog_enter_accessories(inst->sel_menu_id, inst->self_gid);
#endif
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_evt_mc_close_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_clog_evt_mc_close_hdlr(mmi_clog_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_close(inst->mm_gid);
    inst->mm_gid = GRP_ID_INVALID;  /* already smart closed */   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_if_delete_log_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_if_delete_log_list(mmi_clog_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_confirm(
        CNFM_TYPE_YESNO,
        STR_GLOBAL_DELETE_ALL_ASK,
        MMI_EVENT_QUERY,
        inst->self_gid,
        inst,
 #ifndef __MMI_CLOG_FPBW__
        MMI_CLOG_ALERT_FLAG_AUTO_DISMISS | MMI_CLOG_ALERT_FLAG_HIDE_CSK);
 #else /*__MMI_CLOG_FPBW__*/
        MMI_CLOG_ALERT_FLAG_AUTO_DISMISS);
 #endif /*__MMI_CLOG_FPBW__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_delete_log_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_clog_delete_log_list(mmi_clog_inst_struct *inst)
{
#ifdef __MMI_TELEPHONY_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_clog_lt_id_attr_struct *attr;
    srv_clog_del_all_logs_req_struct req_data;
    MMI_MENU_ID menu_id = MENU_ID_CLOG_DEL_DIALED_CALL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_id = mmi_clog_menu_id_del2clt(inst->sel_menu_id);
    attr = mmi_clog_get_attr_by_menu_id(menu_id);
    MMI_CLOG_ASSERT(attr);

    memcpy(&req_data, &attr->idt, sizeof(srv_clog_log_identity_struct));
    inst->srv_pid = srv_clog_delete_all_logs(inst->handle, 0, &req_data, mmi_clog_delete_all_logs_result);
#endif /* __MMI_TELEPHONY_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_menu_id_del2clt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  del_menu_id     [IN]      
 * RETURNS
 *  
 *****************************************************************************/
static MMI_MENU_ID mmi_clog_menu_id_del2clt(MMI_MENU_ID del_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_MENU_ID clt_menu_id = MENU_ID_CLOG_DIALED_CALL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*  as the order of each is same, we can use this rule to slim it,
    this may harm the maintainability a little as it depends on the resgen process,
    luckly we can think this process may not be changed in a long time,
    so, code size is a little more important than maintaibability here. */

    if (del_menu_id >= MENU_ID_CLOG_DEL_DIALED_CALL)
        clt_menu_id += del_menu_id - MENU_ID_CLOG_DEL_DIALED_CALL;
    else
        clt_menu_id = del_menu_id;
    return clt_menu_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_delete_all_logs_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  pid             [IN]        
 *  req_data        [IN]         
 *  cnf_data        [IN]         
 *  more            [IN]        
 *  ret             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_delete_all_logs_result(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            void *req_data,
            void *cnf_data,
            MMI_BOOL more,
            srv_clog_ret_enum ret)
{
#ifdef __MMI_TELEPHONY_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_inst_struct *inst;
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
    mmi_clog_cntx_struct *cntx = mmi_clog_get_cntx();
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_display_dummy_screen();
    mmi_frm_scrn_close_active_id(); // close dummy screen
    
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
    inst = &cntx->inst_list[0];
#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    inst = mmi_clog_get_inst_by_pid(pid);
    if (!inst)
        return SRV_CLOG_RET_OK;
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    if((inst->sel_menu_id == MENU_ID_CLOG_DEL_MISSED_CALL || inst->sel_menu_id == MENU_ID_CLOG_DEL_ALL_CALL)
        && (srv_clog_get_unread_missed_call_num() == 0))
    {   
        if(nmgr_handle != NULL)
        {
            mmi_frm_nmgr_alert_cancel(nmgr_handle);
            nmgr_handle = NULL;
        }

#ifdef __MMI_NCENTER_SUPPORT__
        vsrv_ncenter_close_notification(g_ncenter_hdl);
#endif /*__MMI_NCENTER_SUPPORT__*/
    }
    
    if (ret != SRV_CLOG_RET_OK)
    {
        MMI_CLOG_IT_TRACE((MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_DELETE_ALL_LOGS_RESULT, handle, pid, ret));
        mmi_clog_popup(STR_GLOBAL_UNFINISHED, MMI_EVENT_FAILURE, inst->self_gid, inst);
    }
#ifdef __MMI_CLOG_FPBW__
    else
        mmi_clog_popup(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, inst->self_gid, inst);        
#endif /*__MMI_CLOG_FPBW__*/
#endif /* __MMI_TELEPHONY_SUPPORT__ */
    return SRV_CLOG_RET_OK;
}
#endif /* __MMI_CLOG_TAB_SUPPORT__ */


#ifdef __MMI_CLOG_EVENT_REFRESH_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_inst_srv_evt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 *  evt         [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_inst_srv_evt_hdlr(mmi_clog_inst_struct *inst, mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_CLOG_ADD_LOG:
        case EVT_ID_SRV_CLOG_DEL_LOG:
        case EVT_ID_SRV_CLOG_DEL_ALL:
        case EVT_ID_SRV_CLOG_UPDATE_LOG:
        case EVT_ID_SRV_CLOG_UPDATE_ALL:
            if (!MMI_CLOG_IS_GID_INVALID(inst->mm_gid))
                cui_menu_refresh_currlist(inst->mm_gid);
            break;

        default:
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_mm_srv_evt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_RET mmi_clog_mm_srv_evt_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_clog_inst_struct *inst;
    mmi_clog_cntx_struct *cntx = mmi_clog_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_CLOG_INST_MAX_NUM; i++)
    {
        inst = &cntx->inst_list[i];

        if (!MMI_CLOG_IS_INST_VALID(inst, MMI_CLOG_INST_TYPE_CLOG))
            continue;
        /* Check if has main menu */
        if (inst->lt_type == MMI_CLOG_LT_TYPE_TAB)
            continue;
        /* Check if main menu is created */
        if (MMI_CLOG_IS_GID_INVALID(inst->mm_gid))
            continue;
        if (inst->handle == ((srv_clog_evt_log_op_struct*) evt)->handle)
            continue;
        mmi_clog_inst_srv_evt_hdlr(inst, evt);
    }
    return MMI_RET_OK;
}

#endif /* __MMI_CLOG_EVENT_REFRESH_SUPPORT__ */

#endif /* __MMI_TELEPHONY_SUPPORT__ || __MMI_BT_PBAP_CLIENT__ */
