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
 *  SimCtrlApp.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  UI handling for SIM events.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
#include "SimCtrlSrvGprot.h"
#include "BootupSrvGprot.h"
#include "mmi_rp_app_sim_ctrl_def.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "GlobalResDef.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "NotificationGprot.h"
#include "IdleGprot.h"
#include "SimCtrlGprot.h"
#include "mmi_frm_utility_gprot.h"
#include "NetSetSrvGprot.h"
#include "NetSetAppGprot.h"


#if !defined(__MMI_SIM_CTRL_SLIM__)

/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct
{
    srv_sim_ctrl_ua_cause_enum cause;
    U16 msg_str;
} mmi_sim_ctrl_cause_string_struct;


/****************************************************************************
 * Configurations
 ****************************************************************************/

static const mmi_sim_ctrl_cause_string_struct g_mmi_sim_ctrl_cause_string[] =
{
#if (MMI_MAX_SIM_NUM >= 2)

#ifdef __SIM_RECOVERY_ENHANCEMENT__
    { SRV_SIM_CTRL_UA_CAUSE_RECOVERY, STR_ID_SIM_CTRL_SIMX_CAME_OFF },
#endif
#ifndef  __SIM_HOT_SWAP_SUPPORT__
    { SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED, STR_ID_SIM_CTRL_SIMX_CAME_OFF },
#endif /* __SIM_HOT_SWAP_SUPPORT__ */
    { SRV_SIM_CTRL_UA_CAUSE_ACCESS_ERROR, STR_ID_SIM_CTRL_SIMX_ACCESS_ERROR },
    /* ------------------------------------------ */
    { SRV_SIM_CTRL_UA_CAUSE_END_OF_ENUM, 0 }
    
#else /* (MMI_MAX_SIM_NUM >= 2) */

#ifdef __SIM_RECOVERY_ENHANCEMENT__
    { SRV_SIM_CTRL_UA_CAUSE_RECOVERY, STR_ID_SIM_CTRL_SIM_CAME_OFF },
#endif
#ifndef  __SIM_HOT_SWAP_SUPPORT__
    { SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED, STR_ID_SIM_CTRL_SIM_CAME_OFF },
#endif
    { SRV_SIM_CTRL_UA_CAUSE_ACCESS_ERROR, STR_ID_SIM_CTRL_SIM_ACCESS_ERROR },
    /* ------------------------------------------------------------------------ */
    { SRV_SIM_CTRL_UA_CAUSE_END_OF_ENUM, 0 }
    
#endif /* (MMI_MAX_SIM_NUM >= 2) */
};


/****************************************************************************
 * Functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_sim_ctrl_to_popup_error
 * DESCRIPTION
 *  To query whether the cause is a fatal error that needs go back to idle
 *  and rearrange menus.
 * PARAMETERS
 *  cause       [IN] Cause
 * RETURNS
 *  MMI_TRUE if fatal error
 *****************************************************************************/
static MMI_BOOL mmi_sim_ctrl_to_popup_error(srv_sim_ctrl_ua_cause_enum cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; g_mmi_sim_ctrl_cause_string[i].cause != SRV_SIM_CTRL_UA_CAUSE_END_OF_ENUM; i++)
    {
        if (g_mmi_sim_ctrl_cause_string[i].cause == cause)
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sim_ctrl_get_cause_string
 * DESCRIPTION
 *  Get the string to prompt user for the cause
 * PARAMETERS
 *  sim     [IN] Which SIM
 *  cause   [IN] Cause
 * RETURNS
 *  String ID
 *****************************************************************************/
static WCHAR* mmi_sim_ctrl_get_cause_string(
    mmi_sim_enum sim,
    srv_sim_ctrl_ua_cause_enum cause,
    WCHAR *out_buffer,
    S32 max_n_chars)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_sim_ctrl_cause_string_struct *entry;
    U16 msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_id = STR_GLOBAL_ERROR;
    
    for (entry = g_mmi_sim_ctrl_cause_string;
         entry->cause != SRV_SIM_CTRL_UA_CAUSE_END_OF_ENUM;
         entry++)
    {
        if (entry->cause == cause)
        {
            msg_id = entry->msg_str;
            break;
        }
    }

#if (MMI_MAX_SIM_NUM >= 2)
    mmi_sim_ctrl_gen_str(out_buffer, max_n_chars, msg_id, sim);
#else
    mmi_wcsncpy(out_buffer, get_string(msg_id), max_n_chars);
#endif

    return out_buffer;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sim_ctrl_on_sim_availability_changed
 * DESCRIPTION
 *  Event proc for SIM availability changed.
 *  If a fatal error happens, it should prompt user and go back to idle.
 * PARAMETERS
 *  evt     [IN] srv_sim_ctrl_availability_changed_evt_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_sim_ctrl_on_sim_availability_changed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_availability_changed_evt_struct *avai_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED);
    
    if (srv_bootup_is_booting())
    {
        /* Ignore */
        return MMI_RET_OK;
    }

    avai_evt = (srv_sim_ctrl_availability_changed_evt_struct*)evt;

    if (!avai_evt->is_available_now &&
         mmi_sim_ctrl_to_popup_error(avai_evt->unavailable_cause))
    {
        WCHAR message[60 + 1];
       
#ifdef __SIM_RECOVERY_ENHANCEMENT__
        if ((avai_evt->unavailable_cause_before == SRV_SIM_CTRL_UA_CAUSE_INITIALIZING ||
             avai_evt->unavailable_cause_before == SRV_SIM_CTRL_UA_CAUSE_ACCESS_ERROR) &&
             avai_evt->unavailable_cause == SRV_SIM_CTRL_UA_CAUSE_RECOVERY)
        {
            /* Popup recovery message only on first-time recovery start */
            return MMI_RET_OK;
        }
#endif

        mmi_sim_ctrl_get_cause_string(
            avai_evt->sim,
            avai_evt->unavailable_cause,
            message,
            sizeof(message) / sizeof(message[0]) - 1);

        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, message);
    }

    return MMI_RET_OK;
}

#endif /* !defined(__MMI_SIM_CTRL_SLIM__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_sim_ctrl_get_sim_str_id
 * DESCRIPTION
 *  Get the string ID of SIM
 * PARAMETERS
 *  sim     [IN]
 * RETURNS
 *  String ID
 *****************************************************************************/
static U16 mmi_sim_ctrl_get_sim_str_id(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const U16 SIM_STR_ID[] =
    {
#if (MMI_MAX_SIM_NUM == 1)
        STR_GLOBAL_SIM,
#endif
#if (MMI_MAX_SIM_NUM >= 2)
        STR_GLOBAL_SIM_1,
        STR_GLOBAL_SIM_2,
#endif
#if (MMI_MAX_SIM_NUM >= 3)
        STR_GLOBAL_SIM_3,
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        STR_GLOBAL_SIM_4,
#endif
    };

    S32 sim_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    if (srv_sim_ctrl_get_num_of_inserted() <= 1)
    {
        return STR_GLOBAL_SIM;
    }
#endif

    sim_index = mmi_frm_sim_to_index(sim);

    return SIM_STR_ID[sim_index];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sim_ctrl_gen_str
 * DESCRIPTION
 *  Generate SIM related string.
 *  The "%S" in the string of template_str_res_id will be replaced with SIM
 *  string.
 * PARAMETERS
 *  out_buffer      [OUT]
 *  max_str_len     [IN] Maximum number of characters (in WCHAR)
 *                       Exclude NULL terminator
 *  template_str_res_id [IN] Template string ID
 *  sim             [IN]
 * RETURNS
 *  String ID
 *****************************************************************************/
WCHAR *mmi_sim_ctrl_gen_str(
        WCHAR *out_buffer,
        S32 max_str_len, /* excluding NULL terminator */
        U16 template_str_res_id,
        mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_wsprintf(
                out_buffer,
                (max_str_len + 1) * sizeof(WCHAR),
                template_str_res_id,
                mmi_sim_ctrl_get_sim_str_id(sim));
}


#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
/*****************************************************************************
 * FUNCTION
 *  mmi_sim_ctrl_gen_str_with_name
 * DESCRIPTION
 *  Generate SIM related string with SIM anme.
 *  The "%S" in the string of template_str_res_id will be replaced with SIM
 *  string. "%w" in will be replaced with "(SIM name)". The "%w" should be the
 *  right hand side of "%S".
 * PARAMETERS
 *  out_buffer      [OUT]
 *  max_str_len     [IN] Maximum number of characters (in WCHAR)
 *                       Exclude NULL terminator
 *  template_str_res_id [IN] Template string ID
 *  sim             [IN]
 * RETURNS
 *  String ID
 *****************************************************************************/
WCHAR *mmi_sim_ctrl_gen_str_with_name(
        WCHAR *out_buffer,
        S32 max_str_len, /* excluding NULL terminator */
        U16 template_str_res_id,
        mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR name_buffer[MMI_NETSET_SIM_NAME_MAX_LEN + 10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_netset_get_sim_name_with_brace(sim, name_buffer, sizeof(name_buffer));

    mmi_wsprintf(
        out_buffer,
        (max_str_len + 1) * sizeof(WCHAR),
        template_str_res_id,
        mmi_sim_ctrl_get_sim_str_id(sim),
        name_buffer);

    return out_buffer;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sim_ctrl_gen_str_with_name
 * DESCRIPTION
 *  Generate SIM related string with SIM anme.
 *  The "%S" in the string of template_str_res_id will be replaced with SIM
 *  string. SIM name will be append at tail.
 * PARAMETERS
 *  out_buffer      [OUT]
 *  max_str_len     [IN] Maximum number of characters (in WCHAR)
 *                       Exclude NULL terminator
 *  template_str_res_id [IN] Template string ID
 *  sim             [IN]
 * RETURNS
 *  String ID
 *****************************************************************************/
WCHAR *mmi_sim_ctrl_append_sim_name(
        WCHAR *out_buffer,
        S32 max_str_len, /* excluding NULL terminator */
        U16 template_str_res_id,
        mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 buffer_len, name_len;
    const WCHAR *sim_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sim_ctrl_gen_str(
        out_buffer,
        max_str_len,
        template_str_res_id,
        sim);

    sim_name = mmi_netset_get_sim_name(sim);
        
    if (sim_name != NULL && sim_name[0] != L'\0')
    {
        buffer_len = mmi_wcslen(out_buffer);
        name_len = mmi_wcslen(sim_name);

        if (buffer_len + name_len + 2 <= max_str_len)
        {
            out_buffer[buffer_len++] = L'(';
            mmi_wcsncpy(out_buffer + buffer_len, sim_name, max_str_len - buffer_len - 1);
            mmi_wcscat(out_buffer, L")");
        }
        else if (buffer_len + 6 <= max_str_len)
        {
            out_buffer[buffer_len++] = L'(';
            mmi_wcsncpy(out_buffer + buffer_len, sim_name, max_str_len - buffer_len - 4);
            mmi_wcscat(out_buffer, L"...)");
        }
        else
        {
            /* No enough space to append SIM name, do nothing */
        }
    }

    return out_buffer;
}
#endif


#ifdef  __SIM_HOT_SWAP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sim_ctrl_on_sim_event_detected
 * DESCRIPTION
 *  To prompt SIM events
 * PARAMETERS
 *  evt     [IN] srv_sim_ctrl_event_detected_evt_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_sim_ctrl_on_sim_event_detected(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    typedef struct
    {
        U16 inserted;
        U16 removed;
    } sim_message_struct;
    
    static const sim_message_struct SIM_MESSAGE =
    {
#if (MMI_MAX_SIM_NUM == 1)
        STR_ID_SIM_CTRL_SIM_INSERTED, STR_ID_SIM_CTRL_SIM_REMOVED
#else
        STR_ID_SIM_CTRL_SIMX_INSERTED, STR_ID_SIM_CTRL_SIMX_REMOVED
#endif
    };
    
    srv_sim_ctrl_event_detected_evt_struct *detected_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_EXT_ASSERT(evt->evt_id == EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED,
        evt->evt_id, 0, 0);

    detected_evt = (srv_sim_ctrl_event_detected_evt_struct*)evt;

    switch (detected_evt->type)
    {
        case SRV_SIM_CTRL_EVENT_DET_INSERTED:
        case SRV_SIM_CTRL_EVENT_DET_REMOVED:
        {
            U16 msg_str_id;

            msg_str_id = SIM_MESSAGE.removed;
            if (detected_evt->type == SRV_SIM_CTRL_EVENT_DET_INSERTED)
            {
                msg_str_id = SIM_MESSAGE.inserted;
            }
            
#if (MMI_MAX_SIM_NUM == 1)
            mmi_frm_nmgr_popup(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO,
                get_string(msg_str_id));
#else
            {
                WCHAR message[60 + 1];

                mmi_sim_ctrl_gen_str(
                    message,
                    sizeof(message) / sizeof(message[0]) - 1,
                    msg_str_id,
                    detected_evt->sim);
                
                mmi_frm_nmgr_popup(
                    MMI_SCENARIO_ID_DEFAULT,
                    MMI_EVENT_INFO,
                    message);
            }

#endif
            break;
        }
    }

    return MMI_RET_OK;
}
#endif /* __SIM_HOT_SWAP_SUPPORT__ */


#if (MMI_MAX_SIM_NUM >= 2) && defined(__UMTS_RAT__)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_3G_SWITCH__
/* under construction !*/
#endif
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_3G_SWITCH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
#ifdef __MMI_3G_SWITCH__
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
#else
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
/* under construction !*/
/* under construction !*/
#endif /* (MMI_MAX_SIM_NUM >= 2) && defined(__UMTS_RAT__) */

