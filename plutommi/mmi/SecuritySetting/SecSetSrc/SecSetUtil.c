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
 *  SecSetUtil.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Utility of security setting
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "SecSetProt.h"
#include "UcmGprot.h"           /* mmi_ucm_app_make_call */
#include "UcmSrvGprot.h"        /* srv_ucm_query_error_message */
#include "custom_ecc.h"         /* ecc_custom_verify_emergency_number */
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "mmi_rp_app_security_setting_def.h"
#include "wgui_categories_util.h"
#include "Unicodexdcl.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "AlertScreen.h"
#include "mmi_frm_events_gprot.h"
#include "CommonScreensResDef.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_list.h"
#include "wgui_categories.h"


/****************************************************************************
 * Constants
 ****************************************************************************/

#define MMI_SECSET_DEFAULT_EMERGENCY_CALL_NUM   L"112"


/****************************************************************************
 * Functions
 ****************************************************************************/

WCHAR *mmi_secset_n_attempts_to_str(
            S32 n_remaining_attempts,
            WCHAR *out_str_buffer,
            S32 max_str_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    out_str_buffer[0] = L'\0';
    
    if (n_remaining_attempts <= 0 || 1000 <= n_remaining_attempts)
    {
        out_str_buffer[0] = L'\0';
    }
    else
    {
        mmi_wsprintf(
            out_str_buffer,
            (max_str_len + 1) * sizeof(WCHAR),
            STR_ID_SECSET_REMAINING_TRIALS_PROMPT,
            n_remaining_attempts);
    }

    return out_str_buffer;
}


MMI_BOOL mmi_secset_make_emergency_call(mmi_id grp_id, const WCHAR* number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_ecc_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_ecc_number = ecc_custom_verify_emergency_number(
                        (kal_uint8*)number,
                        mmi_wcslen(number),
                        ECC_ENCODING_UCS2,
                        ECC_ALL_CALL,
                        NULL,
                        NULL,
                        NULL);

    MMI_TRACE(MMI_SECSET_TRC_GROUP, TRC_MMI_SECSET_MAKE_ECC, grp_id, is_ecc_number);
    
    if (is_ecc_number)
    {
		mmi_ucm_app_make_call((mmi_ucm_call_type_enum)SRV_UCM_VOICE_CALL_TYPE_ALL, (U8*)number);
    }
    else
    {
        mmi_popup_display_simple(
            get_string(srv_ucm_query_error_message(SRV_UCM_RESULT_SOS_NUMBER_ONLY)),
            MMI_EVENT_FAILURE,
            grp_id,
            NULL);
    }

    return is_ecc_number;
}


mmi_ret mmi_secset_make_emergency_call_on_yes(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *result_evt;
    mmi_ucm_make_call_para_struct makecall_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        result_evt = (mmi_alert_result_evt_struct*)evt;
        
        if (result_evt->result == MMI_ALERT_CNFM_YES)
        {
            mmi_ucm_init_call_para(&makecall_para);
            makecall_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_ALL;
            makecall_para.ucs2_num_uri = (U16*) MMI_SECSET_DEFAULT_EMERGENCY_CALL_NUM;
            mmi_ucm_call_launch(0, &makecall_para);
            //mmi_ucm_app_make_call(
            //    SRV_UCM_VOICE_CALL_TYPE,
            //    (U8*)MMI_SECSET_DEFAULT_EMERGENCY_CALL_NUM);
        }
    }

    return MMI_RET_OK;
}



static mmi_ret mmi_secset_forbid_screen_leaving(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK:
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
            return -1;
    }

    return MMI_RET_OK;
}


static void mmi_secset_entry_dummy_waiting(mmi_scrn_essential_struct *es_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            es_data->group_id,
            es_data->scrn_id,
            NULL,
            (FuncPtr)mmi_secset_entry_dummy_waiting,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    ShowCategoryDummyScreen();
}


mmi_id mmi_secset_show_waiting(mmi_id grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_first_enter(
        grp_id,
        SCR_ID_SECSET_DUMMY_WAITING,
        (FuncPtr)mmi_secset_entry_dummy_waiting,
        NULL);

    mmi_frm_scrn_set_leave_proc(
        grp_id,
        SCR_ID_SECSET_DUMMY_WAITING,
        mmi_secset_forbid_screen_leaving);

    return SCR_ID_SECSET_DUMMY_WAITING;
}


void mmi_secset_close_waiting(mmi_id grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_set_leave_proc(grp_id, SCR_ID_SECSET_DUMMY_WAITING, NULL);
    mmi_frm_scrn_close(grp_id, SCR_ID_SECSET_DUMMY_WAITING);
}
