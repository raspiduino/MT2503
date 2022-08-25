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
 *  DmAppDl.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  DM application download.
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
#ifdef SYNCML_DM_SUPPORT

/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/
#include "MMI_include.h"
#include "MMIDataType.h"
#include "NotificationGprot.h"
#include "Wgui_softkeys.h"
#include "Wgui_categories_util.h"
#include "mmi_frm_input_gprot.h"
#include "DmSrvIprot.h"
#include "DmAppDl.h"
#include "mmi_rp_srv_dm_def.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"

/****************************************************************************
 * Global Variable
 ****************************************************************************/

/****************************************************************************
 * Static Variable
 ****************************************************************************/
static U32 curr_percent;

/****************************************************************************
 * Local Function
 ****************************************************************************/

void mmi_dm_dl_start_evt_hdlr(MMI_BOOL is_resume, MMI_BOOL auto_resume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_resume == MMI_TRUE)
    {
        if (auto_resume == MMI_TRUE)
        {
            mmi_dm_dl_display_auto_resume();
            srv_dm_dl_start_app_rsp(DM_UI_INTERACTION_ACTION_ACCEPT);
        }
        else
        {
            mmi_dm_dl_display_resume_cnf_via_nmgr();
        }
    }
    else
    {
        // let dl agent to show cnf screen
        srv_dm_dl_start_app_rsp(DM_UI_INTERACTION_ACTION_ACCEPT);
    }
}


void mmi_dm_dl_display_auto_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_nmgr_popup(
        MMI_SCENARIO_ID_DM,
        MMI_EVENT_PROGRESS,
        (WCHAR*)GetString(STR_ID_DMUI_NOTIF_DOWNLOAD_RESUME));
}


void mmi_dm_dl_display_resume_cnf_via_nmgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_nmgr_is_scenario_deferred(
                        MMI_SCENARIO_ID_DM,
                        mmi_dm_dl_display_resume_cnf_nmgr_hdlr,
                        NULL))
    {
        return;
    }

    mmi_frm_nmgr_notify_by_app(
        MMI_SCENARIO_ID_DM,
        MMI_EVENT_DEFAULT,
        mmi_dm_dl_display_resume_cnf_nmgr_hdlr,
        NULL);
}


MMI_BOOL mmi_dm_dl_display_resume_cnf_nmgr_hdlr(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(
        GRP_ID_ROOT,
        GRP_ID_DMAPP_GLOBAL,
        NULL,
        NULL);
    mmi_frm_group_enter(GRP_ID_DMAPP_GLOBAL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_dm_dl_display_resume_cnf();
    return MMI_TRUE;
}


void mmi_dm_dl_display_resume_cnf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    MMI_ID scrn_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = GRP_ID_DMAPP_GLOBAL;
    arg.callback = mmi_dm_dl_resume_cnf_hdlr;
    arg.f_enter_history = MMI_TRUE;
    scrn_id = mmi_confirm_display(
        (WCHAR*)GetString(STR_ID_DM_DL_RESUME_ASK),
        MMI_EVENT_QUERY,
        &arg);

    mmi_frm_scrn_set_leave_proc(
        GRP_ID_DMAPP_GLOBAL,
        scrn_id,
        mmi_dm_dl_resume_cnf_leave_proc);
}


mmi_ret mmi_dm_dl_resume_cnf_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert_result_evt = (mmi_alert_result_evt_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (alert_result_evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (alert_result_evt->result)
        {
            case MMI_ALERT_CNFM_YES:
            {
                srv_dm_dl_start_app_rsp(DM_UI_INTERACTION_ACTION_ACCEPT);
                break;
            }

            case MMI_ALERT_CNFM_NO:
            {
                srv_dm_dl_start_app_rsp(DM_UI_INTERACTION_ACTION_CANCEL);
                break;
            }

            default:
                break;
        }
    }
    return MMI_RET_OK;
}


mmi_ret mmi_dm_dl_resume_cnf_leave_proc(mmi_event_struct *evt)
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
        srv_dm_dl_start_app_rsp(DM_UI_INTERACTION_ACTION_CANCEL);
    }

    return MMI_RET_ALLOW_CLOSE;
}


void mmi_dm_dl_progress_hdlr(U32 acc_size, U32 total_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 cur_dl_percent = acc_size * 100 / total_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (total_size != 0)
    {
        cur_dl_percent = acc_size * 100 / total_size;
    }
    else
    {
        cur_dl_percent = 0;
    }

    mmi_dm_dl_display_progress_via_nmgr(cur_dl_percent);
}


void mmi_dm_dl_finish_hdlr(srv_dm_app_adp_dl_finish_cause_enum cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cause)
    {
        case SRV_DM_APP_ADP_DL_FINISH:
            break;

        case SRV_DM_APP_ADP_DL_CANCEL:
        {
            mmi_frm_nmgr_popup(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_FAILURE,
                (WCHAR*)GetString(STR_ID_DMUI_DOWNLOAD_FAILURE));
        }
            break;

        case SRV_DM_APP_ADP_DL_NO_MEM:
        {
            mmi_frm_nmgr_popup(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_FAILURE,
                (WCHAR*)GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY));
        }
            break;

        case SRV_DM_APP_ADP_DL_NW_UNAVAIL:
        {
            mmi_frm_nmgr_popup(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_FAILURE,
                (WCHAR*)GetString(STR_ID_DMUI_DOWNLOAD_PAUSE_BY_NETWORK_ANOMALY));
        }
            break;
    }

    mmi_frm_nmgr_cancel_deferred_scenario(
        MMI_SCENARIO_ID_DM,
        mmi_dm_dl_display_progress_nmgr_hdlr,
        NULL);
    mmi_frm_scrn_set_leave_proc(
            GRP_ID_DMAPP_GLOBAL,
            SCR_ID_DMUI_DOWNLOAD_PROGRESS,
            NULL);
    mmi_frm_scrn_close(GRP_ID_DMAPP_GLOBAL, SCR_ID_DMUI_DOWNLOAD_PROGRESS);
}


void mmi_dm_dl_display_progress_via_nmgr(U32 percentage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() == SCR_ID_DMUI_DOWNLOAD_PROGRESS)   /* current screen is download progress */
    {
        if (percentage != curr_percent)
        {
            /* save download percent and update screen */
            curr_percent = percentage;
            UpdateCategory402Value((U16) percentage, NULL);
        }

        if (curr_percent == 100)
        {
            ChangeRightSoftkey(0, 0);
            SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
            UpdateCategory402Value((U16) percentage, (U8*)GetString(STR_GLOBAL_PLEASE_WAIT));
        }
    }
    else if (MMI_FALSE == mmi_frm_scrn_is_present(GRP_ID_DMAPP_GLOBAL, SCR_ID_DMUI_DOWNLOAD_PROGRESS, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))   /* download progress not a scr in history */
    {
        /* not the first time reach the 100 percentage */
        if (percentage == 100)
        {
            return;
        }
        /* save download percent and display download screen */
        curr_percent = percentage;
        if (MMI_FALSE == mmi_frm_nmgr_is_scenario_deferred(MMI_SCENARIO_ID_DM, mmi_dm_dl_display_progress_nmgr_hdlr, NULL))
        {
            mmi_frm_nmgr_notify_by_app(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_PROGRESS,
                mmi_dm_dl_display_progress_nmgr_hdlr,
                NULL);
        }
    }
    else    /* update percentage */
    {
        curr_percent = percentage;
    }
}


MMI_BOOL mmi_dm_dl_display_progress_nmgr_hdlr(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(
        GRP_ID_ROOT,
        GRP_ID_DMAPP_GLOBAL,
        NULL,
        NULL);
    mmi_frm_group_enter(GRP_ID_DMAPP_GLOBAL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_dm_dl_display_progress();
    return MMI_TRUE;
}


void mmi_dm_dl_display_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *progress_string = NULL;
    U32 percent = srv_dm_dl_get_curr_percent();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_DMAPP_GLOBAL, 
                        SCR_ID_DMUI_DOWNLOAD_PROGRESS,
                        NULL,
                        (FuncPtr)mmi_dm_dl_display_progress,
                        MMI_FRM_FULL_SCRN))
    {
        mmi_frm_scrn_set_leave_proc(
            GRP_ID_DMAPP_GLOBAL,
            SCR_ID_DMUI_DOWNLOAD_PROGRESS,
            mmi_dm_dl_progress_leave_proc);

        if (percent == 100)
        {
            progress_string = (U8*)GetString(STR_GLOBAL_PLEASE_WAIT);
        }

        ShowCategory402Screen(
            (U8*)GetString(STR_GLOBAL_DOWNLOADING),
            IMG_ID_DMUI_MAIN,
            0,
            0,
            STR_GLOBAL_CANCEL,
            IMG_GLOBAL_BACK,
            NULL,
            percent,
            progress_string);

        SetRightSoftkeyFunction(mmi_dm_dl_progress_rsk_hdlr, KEY_EVENT_UP);

        if (percent == 100)
        {
            ChangeRightSoftkey(0, 0);
        }
    }
}


void mmi_dm_dl_progress_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_dm_dl_progress_app_rsp(DM_DOWNLOADING_USER_CANCEL);
    mmi_frm_scrn_close(
        GRP_ID_DMAPP_GLOBAL,
        SCR_ID_DMUI_DOWNLOAD_PROGRESS);
}


mmi_ret mmi_dm_dl_progress_leave_proc(mmi_event_struct *evt)
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
         return -1; /* Forbid closing */
    }

    return MMI_RET_ALLOW_CLOSE;
}
#endif /* SYNCML_DM_SUPPORT */

