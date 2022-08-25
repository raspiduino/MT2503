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
 *  SecSetHPVeri.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  High priority verification of SIM
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

/****************************************************************************
 * Include
 ****************************************************************************/

#include "SecSetProt.h"
#include "SimCtrlSrvGprot.h"
#include "PwdCuiGprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "GlobalResDef.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "kal_public_api.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_rp_app_security_setting_def.h"
#include "mmi_frm_mem_gprot.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_util.h"
#include "NotificationGprot.h"
#include "MMI_features.h"
#include "GlobalConstants.h"
#include "BootupAppGprot.h"
#include "BootupSrvGprot.h"
#include "SimCtrlGprot.h"
#include "mmi_frm_utility_gprot.h"


/****************************************************************************
 * Config
 ****************************************************************************/

/*
 * Support verify PIN anytime after bootup
 * L4C may send VERIFY_PIN_RESULT_IND to request PIN from user again.
 */
//#define __MMI_SECSET_HPVERI_CHV1__
#if defined(__MMI_TELEPHONY_SUPPORT__)

/****************************************************************************
 * Context
 ****************************************************************************/

typedef struct
{
    mmi_id grp_id;
    mmi_sim_enum sim;
    srv_sim_ctrl_pwd_type_enum type;
    mmi_id chv_cui;
    mmi_secset_ubchv_handle ubchv_handle;
    MMI_BOOL init_verifying;
    MMI_BOOL handled_by_nmgr;
    mmi_scenario_id scenario;
} mmi_secset_hpveri_cntx_struct;


static mmi_secset_hpveri_cntx_struct g_mmi_secset_hpveri_cntx =
{
    0,
    MMI_SIM_NONE,
    SRV_SIM_CTRL_PWD_TYPE_CHV1,
    0,
    MMI_SECSET_UBCHV_INVALID_HANDLE,
    MMI_FALSE,
    MMI_FALSE
};


/****************************************************************************
 * Functions
 ****************************************************************************/

static MMI_BOOL mmi_secset_hpveri_show_next_or_close(mmi_secset_hpveri_cntx_struct *cntx);
static mmi_ret mmi_secset_hpveri_ubchv1_result_proc(mmi_event_struct *evt);
static mmi_ret mmi_secset_hpveri_on_init_veri_completed(mmi_event_struct *evt);
//#ifdef __MMI_SECSET_HPVERI_CHV1__
static mmi_ret mmi_secset_hpveri_chv1_input_proc(mmi_event_struct *evt);
static mmi_ret mmi_secset_hpveri_chv1_result_proc(mmi_event_struct *evt);
//#endif


static mmi_sim_enum mmi_secset_hpveri_get_next_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_sim_enum sim;
    srv_sim_ctrl_ua_cause_enum ua_cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        sim = mmi_frm_index_to_sim(i);
        
        ua_cause = srv_sim_ctrl_get_unavailable_cause(sim);
        switch (ua_cause)
        {
            case SRV_SIM_CTRL_UA_CAUSE_CHV1_REQUIRED:
            case SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED:
            case SRV_SIM_CTRL_UA_CAUSE_PERSON_REQUIRED:
                return sim;
        }
    }

    return MMI_SIM_NONE;
}


static mmi_ret mmi_secset_hpveri_grp_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_hpveri_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_secset_hpveri_cntx_struct*)evt->user_data;
    
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_GROUP_DELETE_REQ:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
            if (mmi_secset_hpveri_get_next_sim() != MMI_SIM_NONE)
            {
                if (cntx->ubchv_handle == MMI_SECSET_UBCHV_INVALID_HANDLE &&
                    !cntx->init_verifying &&
                    cntx->chv_cui == 0)
                {
                    return -1; /* Not allow closing until all SIMs unblocked */
                }
                else
                {
                    /*
                     * Let GOBACK/DEINIT event can be passed to screen level.
                     * If we block the event here, all screens including NEW_CHV1,
                     * CONFIRM_CHV1 will not be deleted.
                     */
                }
            }
            break;
    
        case EVT_ID_GROUP_DEINIT:
            MMI_TRACE(MMI_SECSET_TRC_GROUP, TRC_MMI_SECSET_HPVERI_GROUP_DEINIT, cntx->grp_id);
        
            MMI_ASSERT(cntx->ubchv_handle == MMI_SECSET_UBCHV_INVALID_HANDLE);
            cntx->grp_id = 0;
            cntx->sim = MMI_SIM_NONE;
            mmi_frm_end_scenario(cntx->scenario);
            break;
    }
    
    return MMI_RET_OK;
}


static MMI_BOOL mmi_secset_hpveri_show_next_or_close(mmi_secset_hpveri_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_ua_cause_enum ua_cause;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->ubchv_handle == MMI_SECSET_UBCHV_INVALID_HANDLE &&
        !cntx->init_verifying &&
        cntx->chv_cui == 0)
    {
        cntx->sim = mmi_secset_hpveri_get_next_sim();

        MMI_TRACE(MMI_SECSET_TRC_GROUP, TRC_MMI_SECSET_HPVERI_SHOW_NEXT_OR_CLOSE_NEW, cntx->sim);
        
        if (cntx->sim != MMI_SIM_NONE)
        {
            ua_cause = srv_sim_ctrl_get_unavailable_cause(cntx->sim);

            if (srv_sim_ctrl_is_initializing(cntx->sim))
            {
                cntx->init_verifying = mmi_bootup_sec_do_verification(
                    cntx->grp_id,
                    mmi_secset_hpveri_on_init_veri_completed,
                    cntx);

                MMI_ASSERT(cntx->init_verifying);
            }
            else if (ua_cause == SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED)
            {
                cntx->type = SRV_SIM_CTRL_PWD_TYPE_UBCHV1;
            
                cntx->ubchv_handle = mmi_secset_ubchv_create(
                    cntx->grp_id,
                    cntx->sim,
                    cntx->type,
                    mmi_secset_hpveri_ubchv1_result_proc,
                    cntx);

                mmi_secset_ubchv_run(cntx->ubchv_handle);
            }
//#ifdef __MMI_SECSET_HPVERI_CHV1__
            else if (ua_cause == SRV_SIM_CTRL_UA_CAUSE_CHV1_REQUIRED)
            {
                WCHAR message[MMI_SECSET_SIM_MAX_STR_LEN + 1];
                WCHAR *remaining_attempts_prompt;
                
                cntx->type = SRV_SIM_CTRL_PWD_TYPE_CHV1;

                mmi_secset_sim_get_string(
                    cntx->sim,
                    SRV_SIM_CTRL_PWD_TYPE_CHV1,
                    MMI_SECSET_STR_INPUT_CHV,
                    message,
                    MMI_SECSET_SIM_MAX_STR_LEN);
                cntx->chv_cui = cui_pwd_basic_create_dynamic_str(
                    cntx->grp_id,
                    message,
                    MMI_SECSET_MIN_CHV_LEN,
                    MMI_SECSET_MAX_CHV_LEN);
                    
                cui_pwd_basic_set_cancel_enabled(cntx->chv_cui, MMI_FALSE);
                cui_pwd_basic_set_auxiliary(
                    cntx->chv_cui,
                    CUI_PWD_AUXILIARY_BASIC_DEFAULT,
                    MMI_TRUE,
                    STR_ID_SECSET_SOFTKEY_EMERGENCY);
                cui_pwd_basic_set_proc(cntx->chv_cui, mmi_secset_hpveri_chv1_input_proc, cntx);

                remaining_attempts_prompt = (WCHAR*)mmi_malloc(
                    (CUI_PWD_MAX_EXTRA_MSG_STR_LEN + 30) * sizeof(WCHAR));
                mmi_secset_n_attempts_to_str(
                    srv_sim_ctrl_get_n_remaining_attempts(cntx->sim, cntx->type),
                    remaining_attempts_prompt,
                    CUI_PWD_MAX_EXTRA_MSG_STR_LEN);
                cui_pwd_basic_set_extra_msg(cntx->chv_cui, remaining_attempts_prompt);
                mmi_mfree(remaining_attempts_prompt);
                    
                cui_pwd_basic_run(cntx->chv_cui);
            }
//#endif /* __MMI_SECSET_HPVERI_CHV1__ */

            return MMI_TRUE;
        }
        else
        {
            mmi_frm_group_close(cntx->grp_id);
        }
    }
    else /* Some UBCHV/CHV screen is already there */
    {
        MMI_TRACE(MMI_SECSET_TRC_GROUP, TRC_MMI_SECSET_HPVERI_SHOW_NEXT_OR_CLOSE_RUNNING,
            cntx->sim, (U32)cntx->ubchv_handle, (U32)cntx->init_verifying);
    
        return MMI_TRUE;
    }

    return MMI_FALSE;;
}


static mmi_ret mmi_secset_hpveri_show_next_after_popup(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *result_evt;
    mmi_secset_hpveri_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_POPUP_QUIT)
    {
        result_evt = (mmi_alert_result_evt_struct*)evt;
        cntx = (mmi_secset_hpveri_cntx_struct*)result_evt->user_tag;

        mmi_secset_hpveri_show_next_or_close(cntx);
    }

    return MMI_RET_OK;
}


static void mmi_secset_hpveri_popup_and_check_next(
                mmi_secset_hpveri_cntx_struct *cntx,
                const WCHAR *message,
                mmi_event_notify_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct popup_arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_property_init(&popup_arg);
    popup_arg.callback = mmi_secset_hpveri_show_next_after_popup;
    popup_arg.parent_id = cntx->grp_id;
    popup_arg.user_tag = cntx;
    
    if (!mmi_popup_display(
            (WCHAR*)message,
            type,
            &popup_arg))
    {
        mmi_secset_hpveri_show_next_or_close(cntx);
    }
}


static mmi_ret mmi_secset_hpveri_on_init_veri_completed(mmi_event_struct *evt)
{
    mmi_secset_hpveri_cntx_struct *cntx;

    MMI_EXT_ASSERT(evt->evt_id == EVT_ID_MMI_BOOTUP_VERIFICATION_COMPLETED,
        evt->evt_id, 0, 0);

    cntx = (mmi_secset_hpveri_cntx_struct*)(evt->user_data);
    cntx->init_verifying = MMI_FALSE;
    mmi_secset_hpveri_show_next_or_close(cntx);

    return MMI_RET_OK;
}


static MMI_BOOL mmi_secset_hpveri_nmgr_entry(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_hpveri_cntx_struct *cntx;
    mmi_sim_enum sim;
    srv_sim_ctrl_ua_cause_enum ua_cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim = mmi_secset_hpveri_get_next_sim();

    MMI_TRACE(MMI_SECSET_TRC_GROUP, TRC_MMI_SECSET_HPVERI_NMGR_ENTRY, sim);
    
    /* SIM Status may change during SIM event -> NMGR -> callback */
    if (sim == MMI_SIM_NONE)
    {
        /* No SIM requires verification */
        return MMI_FALSE;
    }

    if (mmi_frm_group_is_present(GRP_ID_SECSET_VERIFICATION))
    {
        /* We are already processing verifications */
        return MMI_FALSE;
    }
    
    cntx = &g_mmi_secset_hpveri_cntx;
    cntx->grp_id = GRP_ID_SECSET_VERIFICATION;
    cntx->sim = sim;
    cntx->handled_by_nmgr = MMI_FALSE;
    
    mmi_frm_group_create_ex(
        GRP_ID_ROOT,    
        cntx->grp_id,
        mmi_secset_hpveri_grp_proc,
        cntx,
        MMI_FRM_NODE_NONE_FLAG);
        
    //mmi_frm_group_enter(cntx->grp_id, MMI_FRM_NODE_NONE_FLAG);

    ua_cause = srv_sim_ctrl_get_unavailable_cause(sim);
    if (srv_sim_ctrl_is_initializing(sim))
    {
        cntx->init_verifying = mmi_bootup_sec_do_verification(
            cntx->grp_id,
            mmi_secset_hpveri_on_init_veri_completed,
            cntx);

        MMI_ASSERT(cntx->init_verifying);
    }
    else if (ua_cause == SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED)
    {
        WCHAR message[MMI_SECSET_SIM_MAX_STR_LEN + 1];

        mmi_secset_sim_get_string(
            sim,
            SRV_SIM_CTRL_PWD_TYPE_CHV1,
            MMI_SECSET_STR_CHV_BLOCKED,
            message,
            MMI_SECSET_SIM_MAX_STR_LEN);
    
        mmi_secset_hpveri_popup_and_check_next(
            cntx,
            message,
            MMI_EVENT_FAILURE);
    }
//#ifdef __MMI_SECSET_HPVERI_CHV1__
    else if (ua_cause == SRV_SIM_CTRL_UA_CAUSE_CHV1_REQUIRED)
    {
        mmi_secset_hpveri_show_next_or_close(cntx);
    }
//#endif /* __MMI_SECSET_HPVERI_CHV1__ */
    else
    {
        MMI_ASSERT(0);
    }

    /* Scenario will be ended on group deinit */
    mmi_frm_start_scenario(cntx->scenario);

    return MMI_TRUE;
}


#define mmi_secset_hpveri_decide_scenario() (MMI_SCENARIO_ID_DEFAULT)


/* Let known UBCHV1 to be displayed first rather than by event,
   to avoid screen flicker or improper background of popup */
void mmi_secset_hpveri_display_ubchv1(mmi_id grp_id, mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_hpveri_cntx_struct *cntx;
    MMI_BOOL popup_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    cntx = &g_mmi_secset_hpveri_cntx;
    popup_msg = MMI_FALSE;

    if (srv_sim_ctrl_get_unavailable_cause(sim) == SRV_SIM_CTRL_UA_CAUSE_UBCHV1_BLOCKED)
    {
        mmi_secset_sim_display_popup(
            sim,
            SRV_SIM_CTRL_PWD_TYPE_UBCHV1,
            MMI_SECSET_STR_UBCHV_BLOCKED,
            MMI_EVENT_FAILURE,
            grp_id,
            NULL);
            
        return;
    }
    
    if (!mmi_frm_group_is_present(GRP_ID_SECSET_VERIFICATION))
    {
        if (!cntx->handled_by_nmgr)
        {
            cntx->sim = sim;
            cntx->handled_by_nmgr = MMI_TRUE;
            cntx->scenario = mmi_secset_hpveri_decide_scenario();
            
            /*
             * Assume NMGR will call the entry directly in call stack
             * if not deterred. Otherwise the background may change
             * when the popup is shown.
             */
            if (!mmi_frm_nmgr_notify_by_app(
                    cntx->scenario,
                    MMI_EVENT_FAILURE,
                    mmi_secset_hpveri_nmgr_entry,
                    cntx))
            {
                /* Deferred */
                popup_msg = MMI_TRUE;
            }
        }
        else
        {
            popup_msg = MMI_TRUE;
        }
    }
    else
    {
        popup_msg = MMI_TRUE;
    }

    if (popup_msg)
    {
        mmi_secset_sim_display_popup(
            sim,
            SRV_SIM_CTRL_PWD_TYPE_UBCHV1,
            MMI_SECSET_STR_CHV_BLOCKED,
            MMI_EVENT_FAILURE,
            grp_id,
            NULL);
    }
}


static void mmi_secset_hpveri_show_verification(
    mmi_sim_enum sim,
    mmi_secset_hpveri_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_notify_enum notify_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx->handled_by_nmgr)
    {
        cntx->sim = sim;
        /* handled_by_nmgr will be reset in mmi_secset_hpveri_nmgr_entry() */
        cntx->handled_by_nmgr = MMI_TRUE;

        notify_type = MMI_EVENT_FAILURE;
        if (srv_sim_ctrl_is_initializing(sim))
        {
            notify_type = MMI_EVENT_INFO;
        }
        cntx->scenario = mmi_secset_hpveri_decide_scenario();
        
        mmi_frm_nmgr_notify_by_app(
            cntx->scenario,
            notify_type,
            mmi_secset_hpveri_nmgr_entry,
            cntx);
    }
}


#if defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)
static void mmi_secset_hpveri_notify_sim_ready(mmi_sim_enum sim)
{
#if (MMI_MAX_SIM_NUM >= 2)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR sim_ready_msg[60 + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    if (srv_sim_ctrl_get_num_of_inserted() <= 1)
    {
        mmi_frm_nmgr_popup(
            mmi_secset_hpveri_decide_scenario(),
            MMI_EVENT_INFO,
            get_string(STR_ID_SECSET_SIM_READY));
    }
    else
#endif /* defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */
    {
        mmi_sim_ctrl_gen_str(
            sim_ready_msg,
            60,
            STR_ID_SECSET_SIMX_READY,
            sim);

        mmi_frm_nmgr_popup(
            mmi_secset_hpveri_decide_scenario(),
            MMI_EVENT_INFO,
            sim_ready_msg);
    }
    
#else /* (MMI_MAX_SIM_NUM >= 2) */

    mmi_frm_nmgr_popup(
        mmi_secset_hpveri_decide_scenario(),
        MMI_EVENT_INFO,
        get_string(STR_ID_SECSET_SIM_READY));
        
#endif /* (MMI_MAX_SIM_NUM >= 2) */
}
#endif /* defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__) */


mmi_ret mmi_secset_hpveri_on_sim_availability_changed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_availability_changed_evt_struct *avai_evt;
    mmi_secset_hpveri_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bootup_is_booting())
    {
        return MMI_RET_OK;
    }

    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED);

    avai_evt = (srv_sim_ctrl_availability_changed_evt_struct*)evt;
    cntx = &g_mmi_secset_hpveri_cntx;

    switch (avai_evt->unavailable_cause)
    {
        case SRV_SIM_CTRL_UA_CAUSE_CHV1_REQUIRED:
        case SRV_SIM_CTRL_UA_CAUSE_PERSON_REQUIRED:
            if (!mmi_frm_group_is_present(GRP_ID_SECSET_VERIFICATION))
            {
                MMI_TRACE(MMI_SECSET_TRC_GROUP, TRC_MMI_SECSET_HPVERI_NMGR_NOTIFY,
                    avai_evt->sim, avai_evt->unavailable_cause);

                mmi_secset_hpveri_show_verification(avai_evt->sim, cntx);
            }
            else
            {
                /* Already displayed, and we don't need popup for CHV1 */
            }
            break;
            
        case SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED:
            if (!mmi_frm_group_is_present(GRP_ID_SECSET_VERIFICATION))
            {
                MMI_TRACE(MMI_SECSET_TRC_GROUP, TRC_MMI_SECSET_HPVERI_NMGR_NOTIFY,
                    avai_evt->sim, avai_evt->unavailable_cause);

                mmi_secset_hpveri_show_verification(avai_evt->sim, cntx);
            }
            else if (cntx->sim != avai_evt->sim) /* Already displayed for another SIM */
            {
                /* Only popup if SIM is blocked */
                if (!srv_sim_ctrl_is_initializing(avai_evt->sim))
                {
                    WCHAR message[MMI_SECSET_SIM_MAX_STR_LEN + 1];

                    mmi_secset_sim_get_string(
                        avai_evt->sim,
                        SRV_SIM_CTRL_PWD_TYPE_CHV1,
                        MMI_SECSET_STR_CHV_BLOCKED,
                        message,
                        MMI_SECSET_SIM_MAX_STR_LEN);
                
                    mmi_frm_nmgr_popup(
                        MMI_SCENARIO_ID_DEFAULT,
                        MMI_EVENT_FAILURE,
                        message);
                }
            }
            else /* cntx->sim == avai_evt->sim */
            {
                /* We are already processing or will check later */
            }
            break;

        case SRV_SIM_CTRL_UA_CAUSE_UBCHV1_BLOCKED:
            /* Processed by mmi_secset_hpveri_ubchv1_result_proc() */
            break;

        case SRV_SIM_CTRL_UA_CAUSE_NONE:
            if (avai_evt->unavailable_cause_before == SRV_SIM_CTRL_UA_CAUSE_CHV1_REQUIRED ||
                avai_evt->unavailable_cause_before == SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED ||
                avai_evt->unavailable_cause_before == SRV_SIM_CTRL_UA_CAUSE_PERSON_REQUIRED)
            {
                break;
            }
#if defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)
            else if (avai_evt->unavailable_cause_before == SRV_SIM_CTRL_UA_CAUSE_INITIALIZING)
            {
                /* We don't need to verify the newly-inserted SIM */
                mmi_secset_hpveri_notify_sim_ready(avai_evt->sim);
                break;
            }
#endif
            /* Go through to remove all related screens */

        default:
            if (mmi_frm_group_is_present(GRP_ID_SECSET_VERIFICATION))
            {
                mmi_secset_hpveri_cntx_struct *cntx;
            
                cntx = &g_mmi_secset_hpveri_cntx;
                
                if (cntx->sim == avai_evt->sim)
                {
                    if (cntx->ubchv_handle != MMI_SECSET_UBCHV_INVALID_HANDLE)
                    {
                        mmi_secset_ubchv_close(cntx->ubchv_handle);
                        cntx->ubchv_handle = MMI_SECSET_UBCHV_INVALID_HANDLE;
                        cntx->sim = MMI_SIM_NONE;
                        mmi_secset_hpveri_show_next_or_close(cntx);
                    }
                //#ifdef __MMI_SECSET_HPVERI_CHV1__
                    else if (cntx->chv_cui != 0)
                    {
                        cui_pwd_basic_close(cntx->chv_cui);
                        cntx->chv_cui = 0;
                    }
                //#endif
                    else if (cntx->init_verifying)
                    {
                        /* mmi_secset_hpveri_on_init_veri_completed() will be invoked. */
                    }
                }
            }
            break;
    }

    return MMI_RET_OK;
}


static mmi_ret mmi_secset_hpveri_ubchv1_result_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_hpveri_cntx_struct *cntx;
    mmi_secset_ubchv_handle pre_ubchv_handle;
    WCHAR message[MMI_SECSET_SIM_MAX_STR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_secset_hpveri_cntx_struct*)evt->user_data;

    pre_ubchv_handle = cntx->ubchv_handle;
    cntx->ubchv_handle = MMI_SECSET_UBCHV_INVALID_HANDLE;

    switch (evt->evt_id)
    {
        case EVT_ID_SECSET_UBCHV_UNBLOCKED:
            mmi_secset_hpveri_popup_and_check_next(
                cntx,
                get_string(STR_GLOBAL_DONE),
                MMI_EVENT_SUCCESS);
            break;
        
        case EVT_ID_SECSET_UBCHV_BLOCKED:
            mmi_secset_sim_get_string(
                cntx->sim,
                SRV_SIM_CTRL_PWD_TYPE_UBCHV1,
                MMI_SECSET_STR_UBCHV_BLOCKED,
                message,
                MMI_SECSET_SIM_MAX_STR_LEN);
        
            mmi_secset_hpveri_popup_and_check_next(
                cntx,
                message,
                MMI_EVENT_FAILURE);
            break;
            
        case EVT_ID_SECSET_UBCHV_SIM_ERROR:
            mmi_secset_sim_get_string(
                cntx->sim,
                SRV_SIM_CTRL_PWD_TYPE_UBCHV1,
                MMI_SECSET_STR_SIM_ERROR,
                message,
                MMI_SECSET_SIM_MAX_STR_LEN);
        
            mmi_secset_hpveri_popup_and_check_next(
                cntx,
                message,
                MMI_EVENT_FAILURE);
            break;

        case EVT_ID_SECSET_UBCHV_CANCEL:
            MMI_ASSERT(0);
            break;
            
        case EVT_ID_SECSET_UBCHV_PASSIVE_CLOSING:
            return MMI_SECSET_DONT_CLOSE;
    }

    mmi_secset_ubchv_close(pre_ubchv_handle);

    return MMI_RET_OK;
}


#if defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)
mmi_ret mmi_secset_hpveri_on_bootup_completed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim = mmi_secset_hpveri_get_next_sim();
    if (sim != MMI_SIM_NONE)
    {
        mmi_secset_hpveri_show_verification(sim, &g_mmi_secset_hpveri_cntx);
    }

    return MMI_RET_OK;
}
#endif /* defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__) */


//#ifdef __MMI_SECSET_HPVERI_CHV1__

static mmi_ret mmi_secset_hpveri_chv1_input_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_hpveri_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_secset_hpveri_cntx_struct*)evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_PWD_BASIC_DONE:
        {
            cui_pwd_basic_done_evt_struct *done_evt;

            MMI_TRACE(MMI_SECSET_TRC_GROUP, TRC_MMI_SECSET_HPVERI_CHV1_INPUT_DONE, cntx->sim);

            done_evt = (cui_pwd_basic_done_evt_struct*)evt;
            srv_sim_ctrl_verify(
                cntx->sim,
                SRV_SIM_CTRL_PWD_TYPE_CHV1,
                done_evt->input,
                mmi_secset_hpveri_chv1_result_proc,
                cntx);
                
            mmi_secset_show_waiting(cntx->grp_id);
        
            break;
        }

        case EVT_ID_CUI_PWD_BASIC_KEY:
        {
            cui_pwd_basic_key_evt_struct *key_evt;
            const WCHAR *number;

            key_evt = (cui_pwd_basic_key_evt_struct*)evt;

            if (key_evt->key_type == KEY_EVENT_DOWN)
            {
                if (key_evt->key_code == KEY_SEND ||
                    key_evt->key_code == KEY_SEND1 ||
                    key_evt->key_code == KEY_SEND2)
                {
                    number = cui_pwd_basic_get_input(cntx->chv_cui);
                    if (number[0] != L'\0')
                    {
                        mmi_secset_make_emergency_call(cntx->grp_id, number);
                        cui_pwd_basic_clear_input(cntx->chv_cui);
                    }
                }
            }
            
            break;
        }

        case EVT_ID_CUI_PWD_BASIC_CANCEL:
            /* Cancel should be already disabled */
            MMI_EXT_ASSERT(0, cntx->chv_cui, cntx->sim, cntx->type);
            break;
            
        case EVT_ID_CUI_PWD_BASIC_PASSIVE_CLOSING:
            return -1;

        case EVT_ID_CUI_PWD_BASIC_AUX:
        {
            cui_pwd_basic_aux_evt_struct *aux_evt;

            aux_evt = (cui_pwd_basic_aux_evt_struct*)evt;
            if (aux_evt->type == CUI_PWD_AUXILIARY_BASIC_DEFAULT)
            {
                mmi_confirm_property_struct confirm_arg;

                mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);
                confirm_arg.parent_id = cntx->grp_id;
                confirm_arg.callback = mmi_secset_make_emergency_call_on_yes;
                confirm_arg.user_tag = NULL;

                mmi_confirm_display(
                    get_string(STR_ID_SECSET_EMERGENCY_CALL_ASK),
                    MMI_EVENT_QUERY,
                    &confirm_arg);
            }
        
            break;
        }
    }

    return MMI_RET_OK;
}


static mmi_ret mmi_secset_hpveri_chv1_result_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_hpveri_cntx_struct *cntx;
    srv_sim_ctrl_verify_result_evt_struct *result_evt;
    mmi_id prev_chv_cui;
    WCHAR message[MMI_SECSET_SIM_MAX_STR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id != EVT_ID_SRV_SIM_CTRL_VERIFY_RESULT)
    {
        return MMI_RET_OK;
    }

    cntx = (mmi_secset_hpveri_cntx_struct*)evt->user_data;
    result_evt = (srv_sim_ctrl_verify_result_evt_struct*)evt;

    MMI_TRACE(MMI_SECSET_TRC_GROUP, TRC_MMI_SECSET_HPVERI_CHV1_RESULT,
        result_evt->sim, result_evt->success, result_evt->fail_cause);
    
    mmi_secset_close_waiting(cntx->grp_id);

    if (result_evt->success)
    {
        prev_chv_cui = cntx->chv_cui;
        cntx->chv_cui = 0;

        mmi_secset_hpveri_popup_and_check_next(
            cntx,
            get_string(STR_GLOBAL_DONE),
            MMI_EVENT_SUCCESS);

        cui_pwd_basic_close(prev_chv_cui);
    }
    else if (result_evt->fail_cause == SRV_SIM_CTRL_FAIL_CAUSE_WRONG_PASSWORD)
    {
        if (srv_sim_ctrl_pwd_is_blocked(result_evt->sim, result_evt->type))
        {
            prev_chv_cui = cntx->chv_cui;
            cntx->chv_cui = 0;

            mmi_secset_sim_get_string(
                result_evt->sim,
                result_evt->type,
                MMI_SECSET_STR_CHV_BLOCKED,
                message,
                MMI_SECSET_SIM_MAX_STR_LEN);
            
            mmi_secset_hpveri_popup_and_check_next(
                cntx,
                message,
                MMI_EVENT_FAILURE);

            cui_pwd_basic_close(prev_chv_cui);
        }
        else
        {
            WCHAR *remaining_attempts_prompt;
        
            remaining_attempts_prompt = (WCHAR*)mmi_malloc(
                (CUI_PWD_MAX_EXTRA_MSG_STR_LEN + 30) * sizeof(WCHAR));
            mmi_secset_n_attempts_to_str(
                srv_sim_ctrl_get_n_remaining_attempts(result_evt->sim, result_evt->type),
                remaining_attempts_prompt,
                CUI_PWD_MAX_EXTRA_MSG_STR_LEN);
            cui_pwd_basic_set_extra_msg(cntx->chv_cui, remaining_attempts_prompt);
            mmi_mfree(remaining_attempts_prompt);

            mmi_secset_sim_display_popup(
                result_evt->sim,
                result_evt->type,
                MMI_SECSET_STR_WRONG_CHV,
                MMI_EVENT_FAILURE,
                cntx->grp_id,
                cntx);
        }
    }
    else
    {
        prev_chv_cui = cntx->chv_cui;
        cntx->chv_cui = 0;

        switch (result_evt->fail_cause)
        {
            case SRV_SIM_CTRL_FAIL_CAUSE_OPERATION_BLOCKED:
                mmi_secset_sim_get_string(
                    result_evt->sim,
                    result_evt->type,
                    MMI_SECSET_STR_CHV_BLOCKED,
                    message,
                    MMI_SECSET_SIM_MAX_STR_LEN);
                
                mmi_secset_hpveri_popup_and_check_next(
                    cntx,
                    message,
                    MMI_EVENT_FAILURE);
                break;

            case SRV_SIM_CTRL_FAIL_CAUSE_TEMP_FAIL:
                mmi_popup_display_simple(
                    get_string(STR_ID_SECSET_TEMP_FAIL),
                    MMI_EVENT_FAILURE,
                    cntx->grp_id,
                    cntx);
                break;

            case SRV_SIM_CTRL_FAIL_CAUSE_SIM_ERROR:
                mmi_secset_sim_get_string(
                    result_evt->sim,
                    result_evt->type,
                    MMI_SECSET_STR_SIM_ERROR,
                    message,
                    MMI_SECSET_SIM_MAX_STR_LEN);
                
                mmi_secset_hpveri_popup_and_check_next(
                    cntx,
                    message,
                    MMI_EVENT_FAILURE);
                break;
        }
    
        cui_pwd_basic_close(prev_chv_cui);
    }

    return MMI_RET_OK;
}
//#endif /* __MMI_SECSET_HPVERI_CHV1__ */


#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
static void mmi_secset_hpveri_chv1_update_prompt(mmi_secset_hpveri_cntx_struct *cntx)
{
//#ifdef __MMI_SECSET_HPVERI_CHV1__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR prompt[MMI_SECSET_SIM_MAX_STR_LEN + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->chv_cui != 0)
    {
        mmi_secset_sim_get_string(
            cntx->sim,
            cntx->type,
            MMI_SECSET_STR_INPUT_CHV,
            prompt,
            MMI_SECSET_SIM_MAX_STR_LEN);

        cui_pwd_basic_set_input_prompt(cntx->chv_cui, prompt);
    }
//#endif /* __MMI_SECSET_HPVERI_CHV1__ */
}
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */


/*
 * Called from mmi_secset_sim_on_event_detected().
 */
mmi_ret mmi_secset_hpveri_on_sim_number_changed(mmi_event_struct *evt)
{
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_hpveri_cntx_struct *cntx;
    srv_sim_ctrl_event_detected_evt_struct *detected_evt;
    S32 n_sims;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &g_mmi_secset_hpveri_cntx;
    detected_evt = (srv_sim_ctrl_event_detected_evt_struct*)evt;

    n_sims = srv_sim_ctrl_get_num_of_inserted();
    switch (detected_evt->type)
    {
        case SRV_SIM_CTRL_EVENT_DET_REMOVED:
        case SRV_SIM_CTRL_EVENT_DET_RECOVERY_START:
            if (n_sims == 1)
            {
                mmi_secset_hpveri_chv1_update_prompt(cntx);
                if (cntx->ubchv_handle != MMI_SECSET_UBCHV_INVALID_HANDLE)
                {
                    mmi_secset_ubchv_update_prompt(cntx->ubchv_handle);
                }
            }
            break;
        
        case SRV_SIM_CTRL_EVENT_DET_INSERTED:
        case SRV_SIM_CTRL_EVENT_DET_RECOVERY_END:
            if (n_sims == 2)
            {
                mmi_secset_hpveri_chv1_update_prompt(cntx);
                if (cntx->ubchv_handle != MMI_SECSET_UBCHV_INVALID_HANDLE)
                {
                    mmi_secset_ubchv_update_prompt(cntx->ubchv_handle);
                }
            }
            break;
    }
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
    
    return MMI_RET_OK;
}

#endif/*#if defined(__MMI_TELEPHONY_SUPPORT__)*/
