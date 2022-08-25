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
 *  SecSetSSC.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SSC handling for CHV
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

#include "MMI_features.h"
#ifndef __MMI_SECSET_SLIM_FOR_61__
#include "SecSetProt.h"
#include "MenuCuiGprot.h"
#include "SimCtrlSrvGprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
//#include "MMI_features.h"
#include "mmi_rp_app_security_setting_def.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "GlobalResDef.h"
#include "mmi_frm_mem_gprot.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "Unicodexdcl.h"
#include "AlertScreen.h"
#include "wgui_categories_util.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "CommonScreensResDef.h"
#include "mmi_frm_utility_gprot.h"
#include "NetSetAppGprot.h"


/****************************************************************************
 * Context
 ****************************************************************************/

typedef struct
{
    mmi_id grp_id;
    mmi_id sel_sim_cui;
    mmi_secset_ubchv_handle ubchv_handle;
    mmi_sim_enum sim;
    srv_sim_ctrl_pwd_type_enum pwd_type;
    WCHAR guard_pwd[MMI_SECSET_MAX_UBCHV_LEN + 1]; /* Assume MMI_SECSET_MAX_UBCHV_LEN >= MMI_SECSET_MAX_CHV_LEN */
    WCHAR new_pwd[MMI_SECSET_MAX_CHV_LEN + 1];
} mmi_secset_ssc_cntx_struct;

#if (MMI_MAX_SIM_NUM >= 2)
static mmi_secset_ssc_cntx_struct *g_mmi_secset_ssc_cntx;
#endif


/****************************************************************************
 * Functions
 ****************************************************************************/

static void mmi_secset_ssc_operate_sim(
    mmi_secset_ssc_cntx_struct *cntx,
    mmi_sim_enum sim,
    srv_sim_ctrl_pwd_type_enum pwd_type,
    const WCHAR *guard_pwd,
    const WCHAR *new_pwd);
static mmi_ret mmi_secset_ssc_change_chv_result_proc(mmi_event_struct *evt);
static mmi_ret mmi_secset_ssc_ubchv_result_proc(mmi_event_struct *evt);
static void mmi_secset_ssc_popup_and_show_ubchv2(
                mmi_secset_ssc_cntx_struct *cntx,
                mmi_sim_enum sim);
#if (MMI_MAX_SIM_NUM >= 2)
static S32 mmi_secset_ssc_get_n_available_sims(void);
#endif


#define mmi_secset_is_digit(w_ch) (L'0' <= (w_ch) && (w_ch) <= L'9')


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_ssc_parse_chv
 * DESCRIPTION
 *  L"**04*1234*5678*9012#" =>
 *  result_strs[0] = L"04"
 *  result_strs[1] = L"1234"
 *  result_strs[2] = L"5678"
 *  result_strs[3] = L"9012"
 * PARAMETERS
 *  input_buffer    [IN/OUT] String to be parsed, will be modified
 *  result_strs     [OUT] Result of parsing
 * RETURNS
 *  Valid format
 *****************************************************************************/
static MMI_BOOL mmi_secset_ssc_parse_chv(
                    WCHAR *input_buffer,
                    WCHAR *result_strs[4])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    WCHAR *ch_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (!(input_buffer[0] == L'*' && (input_buffer[1] == L'*')))
    {
        return MMI_FALSE;
    }

    ch_p = &(input_buffer[2]);
    for (i = 0; i < 3; i++)
    {
        result_strs[i] = ch_p;
        while (mmi_secset_is_digit(*ch_p))
        {
            ch_p++;
        }
        if (*ch_p != L'*')
        {
            return MMI_FALSE;
        }
        if (ch_p == result_strs[i])
        {
            /* Empty segment */
            return MMI_FALSE;
        }
        *ch_p = L'\0';
        
        ch_p++;
    }

    result_strs[3] = ch_p;
    while (mmi_secset_is_digit(*ch_p))
    {
        ch_p++;
    }
    if (*ch_p != L'#')
    {
        return MMI_FALSE;
    }
    if (ch_p == result_strs[3])
    {
        /* Empty segment */
        return MMI_FALSE;
    }
    *ch_p = L'\0';

    return MMI_TRUE;
}


#if (MMI_MAX_SIM_NUM >= 2)
static MMI_MENU_ID mmi_secset_ssc_get_menu_id(S32 sim_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const MMI_MENU_ID SEL_SIM_MENU_ID[] = 
    {
        MENU_ID_SECSET_SINGLE_SEL_SIM1,
        MENU_ID_SECSET_SINGLE_SEL_SIM2,
#if (MMI_MAX_SIM_NUM >= 3)
        MENU_ID_SECSET_SINGLE_SEL_SIM3,
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        MENU_ID_SECSET_SINGLE_SEL_SIM4
#endif
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return SEL_SIM_MENU_ID[sim_index];
}
#endif


#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
static void mmi_secset_ssc_show_sim_name(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    const WCHAR *sim_name;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        mmi_sim_enum sim = mmi_frm_index_to_sim(i);
        
        sim_name = mmi_netset_get_sim_name(sim);

        if (sim_name != NULL && sim_name[0] != L'\0')
        {
            cui_menu_set_item_hint(
                menu_evt->sender_id,
                mmi_secset_ssc_get_menu_id(i),
                (WCHAR*)sim_name);
        }
    }
}
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */


#if (MMI_MAX_SIM_NUM >= 2)
static void mmi_secset_ssc_set_menu_item_visible(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        mmi_sim_enum sim = mmi_frm_index_to_sim(i);
        MMI_MENU_ID menu_id = mmi_secset_ssc_get_menu_id(i);
        
        if (srv_sim_ctrl_is_available(sim))
        {
            mmi_frm_unhide_menu_item(menu_id);
        }
        else
        {
            mmi_frm_hide_menu_item(menu_id);
        }
    }
}
#endif /* #if (MMI_MAX_SIM_NUM >= 2) */


static mmi_ret mmi_secset_ssc_grp_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_ssc_cntx_struct *cntx;
#if (MMI_MAX_SIM_NUM >= 2)
    cui_menu_event_struct *menu_evt;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_secset_ssc_cntx_struct*)evt->user_data;

    switch (evt->evt_id)
    {
#if (MMI_MAX_SIM_NUM >= 2)
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            menu_evt = (cui_menu_event_struct*)evt;
            cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

            mmi_secset_ssc_set_menu_item_visible();

        #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
            mmi_secset_ssc_show_sim_name(menu_evt);
        #endif
            break;
        }
    
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            mmi_sim_enum sim;

            menu_evt = (cui_menu_event_struct*)evt;
            sim = MMI_SIM1;

#if (MMI_MAX_SIM_NUM >= 2)
            if (menu_evt->highlighted_menu_id == MENU_ID_SECSET_SINGLE_SEL_SIM1)
            {
                sim = MMI_SIM1;
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_SECSET_SINGLE_SEL_SIM2)
            {
                sim = MMI_SIM2;
            }
#endif /* (MMI_MAX_SIM_NUM >= 2) */

#if (MMI_MAX_SIM_NUM >= 3)
            else if (menu_evt->highlighted_menu_id == MENU_ID_SECSET_SINGLE_SEL_SIM3)
            {
                sim = MMI_SIM3;
            }
#endif /* (MMI_MAX_SIM_NUM >= 3) */

#if (MMI_MAX_SIM_NUM == 4)
            else if (menu_evt->highlighted_menu_id == MENU_ID_SECSET_SINGLE_SEL_SIM4)
            {
                sim = MMI_SIM4;
            }
#endif /* (MMI_MAX_SIM_NUM == 4) */

            mmi_secset_ssc_operate_sim(
                cntx,
                sim,
                cntx->pwd_type, 
                cntx->guard_pwd,
                cntx->new_pwd);

            MMI_ASSERT(menu_evt->sender_id == cntx->sel_sim_cui);

            cui_menu_close(menu_evt->sender_id);
            if (g_mmi_secset_ssc_cntx != NULL)
            {
                g_mmi_secset_ssc_cntx->sel_sim_cui = 0;
            }
            
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            menu_evt = (cui_menu_event_struct*)evt;

            MMI_ASSERT(menu_evt->sender_id == cntx->sel_sim_cui);
            
            cui_menu_close(menu_evt->sender_id);
            if (g_mmi_secset_ssc_cntx != NULL)
            {
                g_mmi_secset_ssc_cntx->sel_sim_cui = 0;
            }

            break;
        }
#endif
    
        case EVT_ID_GROUP_DEINIT:
            mmi_mfree(cntx);
		#if (MMI_MAX_SIM_NUM >= 2)
            g_mmi_secset_ssc_cntx = NULL;
		#endif
            break;
    }

    return MMI_RET_OK;
}


#if (MMI_MAX_SIM_NUM >= 2)
static S32 mmi_secset_ssc_get_n_available_sims(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count;
    S32 i;
    mmi_sim_enum sim;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = 0;
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        sim = srv_sim_ctrl_get_sim_by_index(i);
        if (srv_sim_ctrl_is_available(sim))
        {
            count++;
        }
    }

    MMI_TRACE(MMI_SECSET_TRC_GROUP, TRC_MMI_SECSET_SSC_N_AVAILABLE_SIMS, count);

    return count;
}
#endif /* (MMI_MAX_SIM_NUM >= 2) */


mmi_ret mmi_secset_ssc_on_sim_availability_changed(mmi_event_struct *evt)
{
#if (MMI_MAX_SIM_NUM >= 2)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_ssc_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = g_mmi_secset_ssc_cntx;
    
    if (cntx != NULL &&
        cntx->sel_sim_cui != 0 && 
        mmi_secset_ssc_get_n_available_sims() <= 1)
    {
        cui_menu_close(cntx->sel_sim_cui);
        if (g_mmi_secset_ssc_cntx != NULL)
        {
            g_mmi_secset_ssc_cntx->sel_sim_cui = 0;
        }
    }

#endif

    return MMI_RET_OK;
}


static void mmi_secset_ssc_chv_process(
    mmi_secset_ssc_cntx_struct *cntx,
    srv_sim_ctrl_pwd_type_enum pwd_type,
    const WCHAR *guard_pwd,
    const WCHAR *new_pwd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;
    S32 guard_pwd_len;
    S32 new_pwd_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guard_pwd_len = mmi_wcslen(guard_pwd);
    new_pwd_len = mmi_wcslen(new_pwd);

    if (guard_pwd_len == 0 || new_pwd_len == 0)
    {
        mmi_popup_display_simple(
            get_string(STR_GLOBAL_INVALID_FORMAT),
            MMI_EVENT_FAILURE,
            cntx->grp_id,
            cntx);
        return;
    }

    switch (pwd_type)
    {
        case SRV_SIM_CTRL_PWD_TYPE_CHV1:
        case SRV_SIM_CTRL_PWD_TYPE_CHV2:
            if (guard_pwd_len < MMI_SECSET_MIN_CHV_LEN || MMI_SECSET_MAX_CHV_LEN < guard_pwd_len ||
                new_pwd_len < MMI_SECSET_MIN_CHV_LEN || MMI_SECSET_MAX_CHV_LEN < new_pwd_len)
            {
                mmi_popup_display_simple(
                    get_string(STR_ID_SECSET_INVALID_LENGTH),
                    MMI_EVENT_FAILURE,
                    cntx->grp_id,
                    cntx);
                return;
            }
            break;

        case SRV_SIM_CTRL_PWD_TYPE_UBCHV1:
        case SRV_SIM_CTRL_PWD_TYPE_UBCHV2:
            if (guard_pwd_len < MMI_SECSET_MIN_UBCHV_LEN || MMI_SECSET_MAX_UBCHV_LEN < guard_pwd_len ||
                new_pwd_len < MMI_SECSET_MIN_CHV_LEN || MMI_SECSET_MAX_CHV_LEN < new_pwd_len)
            {
                mmi_popup_display_simple(
                    get_string(STR_ID_SECSET_INVALID_LENGTH),
                    MMI_EVENT_FAILURE,
                    cntx->grp_id,
                    cntx);
                return;
            }
            break;
    }

    
#if (MMI_MAX_SIM_NUM >= 2)
    if (mmi_secset_ssc_get_n_available_sims() > 1)
    {
        /* More than one SIM available */
        cntx->pwd_type = pwd_type;
        mmi_wcsncpy(cntx->guard_pwd, guard_pwd, sizeof(cntx->guard_pwd) / sizeof(WCHAR) - 1);
        mmi_wcsncpy(cntx->new_pwd, new_pwd, sizeof(cntx->new_pwd) / sizeof(WCHAR) - 1);
        
        cntx->sel_sim_cui = cui_menu_create_and_run(
            cntx->grp_id,
            CUI_MENU_SRC_TYPE_RESOURCE,
            CUI_MENU_TYPE_FROM_RESOURCE,
            MENU_ID_SECSET_SIM_SINGLE_SEL,
            MMI_TRUE,
            cntx);

        //cui_menu_run(cntx->sel_sim_cui);
    }
    else
#endif
    {
        sim = (mmi_sim_enum)srv_sim_ctrl_get_one_available_sim();

        if (sim != MMI_SIM_NONE)
        {
            mmi_secset_ssc_operate_sim(cntx, sim, pwd_type, guard_pwd, new_pwd);
        }
        else
        {
            mmi_popup_display_simple(
                get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
                MMI_EVENT_FAILURE,
                cntx->grp_id,
                cntx);
        }
    }
}


static void mmi_secset_ssc_operate_sim(
    mmi_secset_ssc_cntx_struct *cntx,
    mmi_sim_enum sim,
    srv_sim_ctrl_pwd_type_enum pwd_type,
    const WCHAR *guard_pwd,
    const WCHAR *new_pwd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->sim = sim;

    if (!srv_sim_ctrl_is_available(sim))
    {
        mmi_popup_display_simple(
            get_string(STR_GLOBAL_NOT_AVAILABLE),
            MMI_EVENT_FAILURE,
            cntx->grp_id,
            cntx);
        return;
    }
    
    switch (pwd_type)
    {
        case SRV_SIM_CTRL_PWD_TYPE_CHV1:
        case SRV_SIM_CTRL_PWD_TYPE_CHV2:
            if (srv_sim_ctrl_pwd_is_blocked(sim, pwd_type))
            {
                if (pwd_type == SRV_SIM_CTRL_PWD_TYPE_CHV2)
                {
                    mmi_secset_ssc_popup_and_show_ubchv2(cntx, sim);
                }
                else
                {
                    mmi_secset_sim_display_popup(
                        sim,
                        pwd_type,
                        MMI_SECSET_STR_CHV_BLOCKED,
                        MMI_EVENT_FAILURE,
                        cntx->grp_id,
                        cntx);
                }
            }
            else if (!srv_sim_ctrl_pwd_is_enabled(sim, pwd_type))
            {
                mmi_secset_sim_display_popup(
                    sim,
                    pwd_type,
                    MMI_SECSET_STR_CHV_DISABLED,
                    MMI_EVENT_FAILURE,
                    cntx->grp_id,
                    cntx);
            }
            else
            {
                srv_sim_ctrl_change_password(
                    sim,
                    pwd_type,
                    guard_pwd,
                    new_pwd,
                    mmi_secset_ssc_change_chv_result_proc,
                    cntx);

                mmi_secset_show_waiting(cntx->grp_id);
            }
            
            break;

        case SRV_SIM_CTRL_PWD_TYPE_UBCHV1:
        case SRV_SIM_CTRL_PWD_TYPE_UBCHV2:
            if (srv_sim_ctrl_pwd_is_blocked(sim, pwd_type))
            {
                mmi_secset_sim_display_popup(
                    sim,
                    pwd_type,
                    MMI_SECSET_STR_UBCHV_BLOCKED_ONLY,
                    MMI_EVENT_FAILURE,
                    cntx->grp_id,
                    cntx);
            }
            else
            {
                srv_sim_ctrl_verify_ubchv(
                    sim,
                    pwd_type,
                    guard_pwd,
                    new_pwd,
                    mmi_secset_ssc_ubchv_result_proc,
                    cntx);
                    
                mmi_secset_show_waiting(cntx->grp_id);
            }
                
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
}


static mmi_ret mmi_secset_ssc_change_chv_result_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_change_password_result_evt_struct *result_evt;
    mmi_secset_ssc_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id != EVT_ID_SRV_SIM_CTRL_CHANGE_PASSWORD_RESULT)
    {
        return MMI_RET_OK;
    }

    result_evt = (srv_sim_ctrl_change_password_result_evt_struct*)evt;
    cntx = (mmi_secset_ssc_cntx_struct*)evt->user_data;

    if (cntx->grp_id != GRP_ID_SECSET_SSC ||
        !mmi_frm_group_is_present(cntx->grp_id))
    {
        /* Invalid context */
        return MMI_RET_OK;
    }

    if (result_evt->success)
    {
        mmi_popup_display_simple(
            get_string(STR_GLOBAL_DONE),
            MMI_EVENT_SUCCESS,
            cntx->grp_id,
            cntx);
    }
    else if (result_evt->fail_cause == SRV_SIM_CTRL_FAIL_CAUSE_WRONG_PASSWORD)
    {
        if (!srv_sim_ctrl_pwd_is_blocked(result_evt->sim, result_evt->type))
        {
            mmi_secset_sim_display_popup(
                result_evt->sim,
                result_evt->type,
                MMI_SECSET_STR_WRONG_CHV,
                MMI_EVENT_FAILURE,
                cntx->grp_id,
                cntx);
        }
        else if (result_evt->type == SRV_SIM_CTRL_PWD_TYPE_CHV1)
        {
            mmi_secset_hpveri_display_ubchv1(cntx->grp_id, result_evt->sim);
        }
        else if (result_evt->type == SRV_SIM_CTRL_PWD_TYPE_CHV2)
        {
            mmi_secset_ssc_popup_and_show_ubchv2(cntx, result_evt->sim);
        }
    }
    else
    {
        mmi_secset_sim_display_error_popup(
            result_evt->sim,
            result_evt->type,
            result_evt->fail_cause,
            cntx->grp_id,
            cntx);
    }

    mmi_secset_close_waiting(cntx->grp_id);
    
    return MMI_RET_OK;
}


static mmi_ret mmi_secset_ssc_ubchv_result_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_verify_result_evt_struct *result_evt;
    mmi_secset_ssc_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id != EVT_ID_SRV_SIM_CTRL_VERIFY_RESULT)
    {
        return MMI_RET_OK;
    }

    result_evt = (srv_sim_ctrl_verify_result_evt_struct*)evt;
    cntx = (mmi_secset_ssc_cntx_struct*)evt->user_data;

    if (cntx->grp_id != GRP_ID_SECSET_SSC ||
        !mmi_frm_group_is_present(cntx->grp_id))
    {
        /* Invalid context */
        return MMI_RET_OK;
    }

    if (result_evt->success)
    {
        mmi_popup_display_simple(
            get_string(STR_GLOBAL_DONE),
            MMI_EVENT_SUCCESS,
            cntx->grp_id,
            cntx);
    }
    else if (result_evt->fail_cause == SRV_SIM_CTRL_FAIL_CAUSE_WRONG_PASSWORD)
    {
        if (!srv_sim_ctrl_pwd_is_blocked(result_evt->sim, result_evt->type))
        {
            mmi_secset_sim_display_popup(
                result_evt->sim,
                result_evt->type,
                MMI_SECSET_STR_WRONG_UBCHV,
                MMI_EVENT_FAILURE,
                cntx->grp_id,
                cntx);
        }
        else
        {
            mmi_secset_sim_display_popup(
                result_evt->sim,
                result_evt->type,
                MMI_SECSET_STR_UBCHV_BLOCKED_ONLY,
                MMI_EVENT_FAILURE,
                cntx->grp_id,
                cntx);
        }
    }
    else
    {
        mmi_secset_sim_display_error_popup(
            result_evt->sim,
            result_evt->type,
            result_evt->fail_cause,
            cntx->grp_id,
            cntx);
    }

    mmi_secset_close_waiting(cntx->grp_id);
    
    return MMI_RET_OK;
}


static mmi_ret mmi_secset_ssc_ubchv2_result_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_ssc_cntx_struct *cntx;
    mmi_secset_ubchv_handle ubchv_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_secset_ssc_cntx_struct*)evt->user_data;

    if (cntx->grp_id != GRP_ID_SECSET_SSC ||
        !mmi_frm_group_is_present(cntx->grp_id))
    {
        /* Screen may be closed during the processing */
        return MMI_RET_OK;
    }
    
    switch (evt->evt_id)
    {
        case EVT_ID_SECSET_UBCHV_UNBLOCKED:
            mmi_popup_display_simple(
                get_string(STR_GLOBAL_DONE),
                MMI_EVENT_SUCCESS,
                cntx->grp_id,
                cntx);
            ubchv_handle = cntx->ubchv_handle;
            cntx->ubchv_handle = MMI_SECSET_UBCHV_INVALID_HANDLE;
            mmi_secset_ubchv_close(ubchv_handle);
            break;
        
        case EVT_ID_SECSET_UBCHV_BLOCKED:
            mmi_secset_sim_display_popup(
                cntx->sim,
                SRV_SIM_CTRL_PWD_TYPE_UBCHV2,
                MMI_SECSET_STR_UBCHV_BLOCKED,
                MMI_EVENT_FAILURE,
                cntx->grp_id,
                cntx);
            ubchv_handle = cntx->ubchv_handle;
            cntx->ubchv_handle = MMI_SECSET_UBCHV_INVALID_HANDLE;
            mmi_secset_ubchv_close(ubchv_handle);
            break;
            
        case EVT_ID_SECSET_UBCHV_SIM_ERROR:
            mmi_secset_sim_display_popup(
                cntx->sim,
                SRV_SIM_CTRL_PWD_TYPE_UBCHV2,
                MMI_SECSET_STR_SIM_ERROR,
                MMI_EVENT_FAILURE,
                cntx->grp_id,
                cntx);
            ubchv_handle = cntx->ubchv_handle;
            cntx->ubchv_handle = MMI_SECSET_UBCHV_INVALID_HANDLE;
            mmi_secset_ubchv_close(ubchv_handle);
            break;
    
        case EVT_ID_SECSET_UBCHV_CANCEL:
            ubchv_handle = cntx->ubchv_handle;
            cntx->ubchv_handle = MMI_SECSET_UBCHV_INVALID_HANDLE;
            mmi_secset_ubchv_close(ubchv_handle);
            break;

        case EVT_ID_SECSET_UBCHV_PASSIVE_CLOSING:
            cntx->ubchv_handle = MMI_SECSET_UBCHV_INVALID_HANDLE;
            break;
    }

    return MMI_RET_OK;
}


static void mmi_secset_ssc_show_ubchv2(
    mmi_secset_ssc_cntx_struct *cntx,
    mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->ubchv_handle = mmi_secset_ubchv_create(
        cntx->grp_id,
        sim,
        SRV_SIM_CTRL_PWD_TYPE_UBCHV2,
        mmi_secset_ssc_ubchv2_result_proc,
        cntx);
    mmi_secset_ubchv_run(cntx->ubchv_handle);
}


mmi_ret mmi_secset_ssc_show_ubchv2_after_popup(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *result_evt;
    mmi_secset_ssc_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_POPUP_QUIT)
    {
        result_evt = (mmi_alert_result_evt_struct*)evt;
        cntx = (mmi_secset_ssc_cntx_struct*)result_evt->user_tag;

        if (cntx->grp_id == GRP_ID_SECSET_SSC &&
            mmi_frm_group_is_present(cntx->grp_id))
        {
            mmi_secset_ssc_show_ubchv2(cntx, cntx->sim);
        }
    }

    return MMI_RET_OK;
}


static void mmi_secset_ssc_popup_and_show_ubchv2(
                mmi_secset_ssc_cntx_struct *cntx,
                mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR message[MMI_SECSET_SIM_MAX_STR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->sim = sim;
    
    mmi_secset_sim_get_string(
        sim,
        SRV_SIM_CTRL_PWD_TYPE_UBCHV2,
        MMI_SECSET_STR_CHV_BLOCKED,
        message,
        MMI_SECSET_SIM_MAX_STR_LEN);
    
    if (srv_sim_ctrl_pwd_is_blocked(sim, SRV_SIM_CTRL_PWD_TYPE_UBCHV2))
    {
        /* Only popup, not show UBCHV screen */
        mmi_popup_display_simple(
            message,
            MMI_EVENT_FAILURE,
            GRP_ID_SECSET,
            cntx);
    }
    else
    {
        mmi_popup_property_struct popup_arg;
    
        mmi_popup_property_init(&popup_arg);
        popup_arg.parent_id = cntx->grp_id;
        popup_arg.callback = mmi_secset_ssc_show_ubchv2_after_popup;
        popup_arg.user_tag = cntx;

        if (!mmi_popup_display(
                message,
                MMI_EVENT_FAILURE,
                &popup_arg))
        {
            mmi_secset_ssc_show_ubchv2(cntx, sim);
        }
    }
}


static void mmi_secset_ssc_accept(
    srv_sim_ctrl_pwd_type_enum pwd_type,
    WCHAR *parse_result[4])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_group_is_present(GRP_ID_SECSET_SSC))
    {
        if (mmi_wcscmp(parse_result[2], parse_result[3]) == 0)
        {
            mmi_secset_ssc_cntx_struct *cntx;
                
            cntx = (mmi_secset_ssc_cntx_struct*)mmi_malloc(sizeof(mmi_secset_ssc_cntx_struct));
		#if (MMI_MAX_SIM_NUM >= 2)
            g_mmi_secset_ssc_cntx = cntx;
		#endif        
            cntx->grp_id = GRP_ID_SECSET_SSC;
            cntx->pwd_type = pwd_type;
            cntx->ubchv_handle = MMI_SECSET_UBCHV_INVALID_HANDLE;
            
            mmi_frm_group_create_ex(
                GRP_ID_ROOT,
                cntx->grp_id,
                mmi_secset_ssc_grp_proc,
                cntx,
                MMI_FRM_NODE_SMART_CLOSE_FLAG);

            //mmi_frm_group_enter(cntx->grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        
            mmi_secset_ssc_chv_process(
                cntx,
                pwd_type,
                parse_result[1],
                parse_result[2]);
        }
        else
        {
            MMI_STR_ID err_msg;

            err_msg = STR_GLOBAL_INVALID_FORMAT;
            if (pwd_type == SRV_SIM_CTRL_PWD_TYPE_CHV1 || pwd_type == SRV_SIM_CTRL_PWD_TYPE_UBCHV1)
            {
                err_msg = STR_ID_SECSET_CHV1_NOT_MATCH;
            }
            else if (pwd_type == SRV_SIM_CTRL_PWD_TYPE_CHV2 || pwd_type == SRV_SIM_CTRL_PWD_TYPE_UBCHV2)
            {
                err_msg = STR_ID_SECSET_CHV2_NOT_MATCH;
            }
            
            mmi_popup_display_ext(
                err_msg,
                MMI_EVENT_FAILURE,
                NULL);
        }
    }
    else
    {
        mmi_popup_display_ext(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            NULL);
    }
}


MMI_BOOL mmi_secset_ssc_process(const CHAR *input_in_ucs2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL accept;
    S32 input_str_len;
    WCHAR *input_copy;
    WCHAR *parse_result[4];
    srv_sim_ctrl_pwd_type_enum pwd_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    accept = MMI_FALSE;

    input_str_len = mmi_ucs2strlen((const CHAR*)input_in_ucs2);
    input_copy = (WCHAR*)mmi_malloc((input_str_len + 3) * sizeof(WCHAR));
    mmi_ucs2cpy((CHAR*)input_copy, (const CHAR*)input_in_ucs2);

    if (mmi_secset_ssc_parse_chv(input_copy, parse_result))
    {
        if (mmi_wcscmp(parse_result[0], L"04") == 0)
        {
            pwd_type = SRV_SIM_CTRL_PWD_TYPE_CHV1;
            accept = MMI_TRUE;
        }
        else if (mmi_wcscmp(parse_result[0], L"042") == 0)
        {
            pwd_type = SRV_SIM_CTRL_PWD_TYPE_CHV2;
            accept = MMI_TRUE;
        }
        else if (mmi_wcscmp(parse_result[0], L"05") == 0)
        {
            pwd_type = SRV_SIM_CTRL_PWD_TYPE_UBCHV1;
            accept = MMI_TRUE;
        }
        else if (mmi_wcscmp(parse_result[0], L"052") == 0)
        {
            pwd_type = SRV_SIM_CTRL_PWD_TYPE_UBCHV2;
            accept = MMI_TRUE;
        }

        if (accept)
        {
            mmi_secset_ssc_accept(pwd_type, parse_result);
        }
    }

    mmi_mfree(input_copy);

    MMI_TRACE(MMI_SECSET_TRC_GROUP, TRC_MMI_SECSET_SSC_PROCESS,
        (U32)input_in_ucs2, input_str_len, accept);

    return accept;
}

#endif/*__MMI_SECSET_SLIM_FOR_61__*/
