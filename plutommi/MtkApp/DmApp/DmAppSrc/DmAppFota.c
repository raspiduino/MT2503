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
 *  DmAppFota.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  DM application FOTA screen.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __DM_FOTA_SUPPORT__
/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/
#include "MMI_include.h"
#include "MMIDataType.h"
#include "NotificationGprot.h"
#include "Wgui_categories_util.h"
#include "mmi_frm_input_gprot.h"
#include "AlertScreen.h"
#include "DmAppFota.h"
#include "DmSrvIprot.h"
#include "mmi_rp_srv_dm_def.h"

/****************************************************************************
 * Global Variable
 ****************************************************************************/

/****************************************************************************
 * Static Variable
 ****************************************************************************/
static mmi_dm_fota_cntx fota_cntx;

/****************************************************************************
 * Local Function
 ****************************************************************************/

void mmi_dm_fota_display_fota_update_result_via_nmgr(MMI_BOOL result)
{
    mmi_frm_nmgr_notify_by_app(
        MMI_SCENARIO_ID_DM,
        MMI_EVENT_INFO,
        mmi_dm_fota_display_fota_update_result,
        (void*)result);
}


MMI_BOOL mmi_dm_fota_display_fota_update_result(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    mmi_confirm_property_struct cnf_arg;
    MMI_BOOL result = (MMI_BOOL)(arg);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_id = mmi_frm_group_create(
                GRP_ID_ROOT,
                GRP_ID_AUTO_GEN,
                NULL,
                NULL);
    mmi_frm_group_enter(group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    if (result == MMI_TRUE)
    {
        mmi_confirm_property_init(&cnf_arg, CNFM_TYPE_OK);
        cnf_arg.parent_id = group_id;
        cnf_arg.callback = NULL;
        cnf_arg.f_enter_history = MMI_TRUE;
        cnf_arg.f_auto_map_empty_softkey = MMI_TRUE;
        mmi_confirm_display(
            (WCHAR*)GetString(STR_ID_DMUI_UPDATE_SUCCESS),
            MMI_EVENT_SUCCESS,
            &cnf_arg);
    }
    else
    {
        mmi_confirm_property_init(&cnf_arg, CNFM_TYPE_OK);
        cnf_arg.parent_id = group_id;
        cnf_arg.callback = NULL;
        cnf_arg.f_enter_history = MMI_TRUE;
        cnf_arg.f_auto_map_empty_softkey = MMI_TRUE;
        mmi_confirm_display(
            (WCHAR*)GetString(STR_ID_DMUI_UPDATE_FAILURE),
            MMI_EVENT_FAILURE,
            &cnf_arg);
    }
    return MMI_TRUE;
}


void mmi_dm_fota_display_update_cnf_via_nmgr(dm_ui_mode_enum ui_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ui_mode)
    {
        case DM_UI_MODE_INFORMATION:
        {
            mmi_frm_nmgr_popup(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_INFO,
                (WCHAR*)GetString(STR_ID_DMUI_NOTIF_UPDATE_REQUEST));
            break;
        }

        case DM_UI_MODE_USERINTERACTION:
        {
            mmi_frm_nmgr_notify_by_app(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_DEFAULT,
                mmi_dm_fota_display_update_cnf_nmgr_hdlr,
                NULL);
            break;
        }

        default:
            break;
    }
}


MMI_BOOL mmi_dm_fota_display_update_cnf_nmgr_hdlr(mmi_scenario_id scen_id, void *arg)
{
    mmi_frm_group_create(
        GRP_ID_ROOT,
        GRP_ID_DMAPP_GLOBAL,
        NULL,
        NULL);
    mmi_frm_group_enter(GRP_ID_DMAPP_GLOBAL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_dm_fota_display_update_cnf();
    return MMI_TRUE;
}


void mmi_dm_fota_display_update_cnf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_DMAPP_GLOBAL, 
                        SCR_ID_DMUI_UPDATE,
                        NULL,
                        (FuncPtr)mmi_dm_fota_display_update_cnf, 
                        MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        mmi_frm_scrn_set_leave_proc(
            GRP_ID_DMAPP_GLOBAL,
            SCR_ID_DMUI_UPDATE,
            mmi_dm_fota_update_cnf_leave_proc);

        ShowCategory74Screen(
            STR_ID_DMUI_NOTIF_UPDATE_CAPTION,
            IMG_NONE,
            STR_GLOBAL_UPDATE,
            IMG_GLOBAL_YES,
            STR_ID_DMUI_NOTIF_UPDATE_DEFER,
            IMG_GLOBAL_NO,
            (U8*)GetString(STR_ID_DMUI_NOTIF_UPDATE_REBOOT),
            mmi_wcslen((WCHAR*)GetString(STR_ID_DMUI_NOTIF_UPDATE_REBOOT)),
            gui_buffer);

        SetLeftSoftkeyFunction(mmi_dm_fota_update_cnf_lsk_hdlr, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_dm_fota_update_cnf_csk_hdlr, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_dm_fota_update_cnf_rsk_hdlr, KEY_EVENT_UP);
    }
}


void mmi_dm_fota_update_cnf_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(GRP_ID_DMAPP_GLOBAL, SCR_ID_DMUI_UPDATE);
    mmi_dm_fota_entry_reset_progress();
    srv_dm_fota_update_app_rsp(DM_UI_INTERACTION_ACTION_ACCEPT, 0);
}


void mmi_dm_fota_update_cnf_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dm_fota_update_cnf_lsk_hdlr();
}


void mmi_dm_fota_update_cnf_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dm_fota_entry_update_defer();
}


mmi_ret mmi_dm_fota_update_cnf_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_SCRN_GOBACK_IN_END_KEY ||
        evt->evt_id == EVT_ID_SCRN_DELETE_REQ_IN_END_KEY)
    {
        srv_dm_fota_update_app_rsp(
            DM_UI_INTERACTION_ACTION_DEFER,
            SRV_DM_TIME_USER_INTERACTION_DEFER);
    }

    return MMI_RET_ALLOW_CLOSE;
}


void mmi_dm_fota_entry_update_defer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_DMAPP_GLOBAL,
                        SCR_ID_DMUI_UPDATE_DEFER,
                        NULL,
                        (FuncPtr)mmi_dm_fota_entry_update_defer,
                        MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
        if (gui_buffer == NULL)
        {
            fota_cntx.highlight_defer_time_index = 0;
        }

        RegisterHighlightHandler(mmi_dm_fota_update_defer_highlight_hdlr);

        mmi_wcscpy((WCHAR*)subMenuData[SRV_DM_FOTA_UPDATE_DEFER_TIME_1_HOUR], L"1");
        mmi_wcscat((WCHAR*)subMenuData[SRV_DM_FOTA_UPDATE_DEFER_TIME_1_HOUR], (WCHAR*)GetString(STR_ID_DMUI_UPDATE_DEFER_HOUR_LATER));
        mmi_wcscpy((WCHAR*)subMenuData[SRV_DM_FOTA_UPDATE_DEFER_TIME_2_HOUR], L"2");
        mmi_wcscat((WCHAR*)subMenuData[SRV_DM_FOTA_UPDATE_DEFER_TIME_2_HOUR], (WCHAR*)GetString(STR_ID_DMUI_UPDATE_DEFER_HOURS_LATER));
        mmi_wcscpy((WCHAR*)subMenuData[SRV_DM_FOTA_UPDATE_DEFER_TIME_4_HOUR], L"4");
        mmi_wcscat((WCHAR*)subMenuData[SRV_DM_FOTA_UPDATE_DEFER_TIME_4_HOUR], (WCHAR*)GetString(STR_ID_DMUI_UPDATE_DEFER_HOURS_LATER));
        mmi_wcscpy((WCHAR*)subMenuData[SRV_DM_FOTA_UPDATE_DEFER_TIME_24_HOUR], L"24");
        mmi_wcscat((WCHAR*)subMenuData[SRV_DM_FOTA_UPDATE_DEFER_TIME_24_HOUR], (WCHAR*)GetString(STR_ID_DMUI_UPDATE_DEFER_HOURS_LATER));

        ShowCategory6Screen(
            STR_ID_DMUI_NOTIF_UPDATE_DEFER,
            IMG_ID_DMUI_MAIN,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            SRV_DM_FOTA_UPDATE_DEFER_TIME_TOTAL,
            (U8**)subMenuDataPtrs,
            NULL,
            fota_cntx.highlight_defer_time_index,
            gui_buffer);

        SetLeftSoftkeyFunction(mmi_dm_fota_update_defer_lsk_hdlr, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_dm_fota_update_defer_csk_hdlr, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_dm_fota_update_defer_rsk_hdlr, KEY_EVENT_UP);
    }
}


void mmi_dm_fota_update_defer_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_dm_fota_update_app_rsp(DM_UI_INTERACTION_ACTION_DEFER, fota_cntx.sel_defer_time);
    mmi_frm_group_close(GRP_ID_DMAPP_GLOBAL);
}


void mmi_dm_fota_update_defer_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dm_fota_update_defer_lsk_hdlr();
}


void mmi_dm_fota_update_defer_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();
}


void mmi_dm_fota_update_defer_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fota_cntx.highlight_defer_time_index = index;

    switch (index)
    {
        case SRV_DM_FOTA_UPDATE_DEFER_TIME_1_HOUR:
            fota_cntx.sel_defer_time = 1 * 3600 * 1000;
            break;

        case SRV_DM_FOTA_UPDATE_DEFER_TIME_2_HOUR:
            fota_cntx.sel_defer_time = 2 * 3600 * 1000;
            break;

        case SRV_DM_FOTA_UPDATE_DEFER_TIME_4_HOUR:
            fota_cntx.sel_defer_time = 4 * 3600 * 1000;
            break;

        case SRV_DM_FOTA_UPDATE_DEFER_TIME_24_HOUR:
            fota_cntx.sel_defer_time = 24 * 3600 * 1000;
            break;

        default:
            break;
    }
}


void mmi_dm_fota_entry_reset_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_USER_DEFINE);
    arg.parent_id = GRP_ID_DMAPP_GLOBAL;
    arg.f_enter_history = MMI_TRUE;
    arg.f_auto_dismiss = MMI_FALSE;
    mmi_confirm_display(
        (WCHAR*)GetString(STR_ID_DMUI_NOTIF_REBOOT_PROGRESS),
        MMI_EVENT_PROGRESS,
        &arg);
    mmi_frm_clear_key_handler(KEY_END, KEY_LONG_PRESS);
}
#endif /* __DM_FOTA_SUPPORT__ */
