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
 *  NwInfoApp.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  UI part of network information.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "NwInfoProt.h"
#include "IdleGprot.h"
#include "MMIDataType.h"
#include "SimCtrlSrvGprot.h"
#include "kal_general_types.h"
#include "MMI_features.h"
#include "gui_typedef.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "NwInfoSrvGprot.h"
#include "wgui_categories_util.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "mmi_rp_app_nw_info_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "wgui_categories.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_categories_list.h"
#include "BootupSrvGprot.h"
#include "mmi_frm_utility_gprot.h"
#include "SimCtrlGprot.h"
#include "WguiCategoryGprot.h"


#ifdef __MMI_NW_INFO_INVALID_SIM_MESSAGE__

/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct
{
    U16 scr_id;
} mmi_nw_info_display_info_struct;


typedef U8 mmi_nw_info_sim_bit_set;

typedef struct
{
    mmi_nw_info_sim_bit_set invalid_sims_processed;
    mmi_nw_info_sim_bit_set invalid_sims_confirmed;
} mmi_nw_info_cntx_struct;


/****************************************************************************
 * Global variables
 ****************************************************************************/

static const mmi_nw_info_display_info_struct g_mmi_nw_info_display_info[] =
{
#if (MMI_MAX_SIM_NUM == 1)
    { SCR_ID_NW_INFO_INVALID_SIM1 },
#endif
#if (MMI_MAX_SIM_NUM >= 2)
    { SCR_ID_NW_INFO_INVALID_SIM1 },
    { SCR_ID_NW_INFO_INVALID_SIM2 },
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    { SCR_ID_NW_INFO_INVALID_SIM3 },
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    { SCR_ID_NW_INFO_INVALID_SIM4 },
#endif
};


static mmi_nw_info_cntx_struct g_mmi_nw_info_cntx =
{
    0,
    0
};


/****************************************************************************
 * Functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_on_early_init
 * DESCRIPTION
 *  Initialize on early init
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_nw_info_on_early_init(mmi_event_struct *evt)
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
 * [Invalid SIM]
 *
 * Handling of invalid SIM message
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_close_active_invalid_sim
 * DESCRIPTION
 *  Close active invalid SIM screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nw_info_close_active_invalid_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_sim_enum sim;
    MMI_ID active_scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    active_scr_id = mmi_frm_scrn_get_active_id();
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if (active_scr_id == g_mmi_nw_info_display_info[i].scr_id)
        {
            sim = mmi_frm_index_to_sim(i);
            g_mmi_nw_info_cntx.invalid_sims_confirmed |= sim;
            mmi_frm_scrn_close_active_id();
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_get_static_buffer
 * DESCRIPTION
 *  Get static buffer. Assume the buffer will not be used cross screens.
 * PARAMETERS
 *  size        [IN]
 * RETURNS
 *  Buffer pointer
 *****************************************************************************/
U8 *mmi_nw_info_get_static_buffer(S32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    buffer = (U8*)subMenuData;
    buffer = (U8*)(((U32)buffer + 3) & ~(0x3)); /* Align to 4 bytes */

    *size = (MAX_SUB_MENUS * MAX_SUB_MENU_SIZE) - 4;

    return buffer;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_entry_invalid_sim
 * DESCRIPTION
 *  Entry function of invalid SIM screen
 * PARAMETERS
 *  es_data     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nw_info_entry_invalid_sim(mmi_scrn_essential_struct *es_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)
    S32 i;
    WCHAR *text_buffer;
    S32 buffer_size = 0;
    mmi_sim_enum sim = MMI_SIM1;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            es_data->group_id,
            es_data->scrn_id,
            NULL,
            NULL,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

#if (MMI_MAX_SIM_NUM >= 2)
    text_buffer = (WCHAR*)mmi_nw_info_get_static_buffer(&buffer_size);

    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if (g_mmi_nw_info_display_info[i].scr_id == es_data->scrn_id)
        {
            sim = mmi_frm_index_to_sim(i);
            break;
        }
    }

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    mmi_sim_ctrl_gen_str_with_name(
        text_buffer,
        (buffer_size / sizeof(WCHAR)),
        STR_ID_NW_INFO_INVALID_SIMX_MSG_NAME,
        sim);
#else
    mmi_sim_ctrl_gen_str(
        text_buffer,
        (buffer_size / sizeof(WCHAR)),
        STR_ID_NW_INFO_INVALID_SIMX_MSG,
        sim);
#endif

#ifndef __MMI_WGUI_DISABLE_CSK__
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif /* #ifndef __MMI_WGUI_DISABLE_CSK__ */

    ShowCategory7Screen(
        STR_ID_NW_INFO_INVALID_SIM_TITLE,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        0,
        (U8*)text_buffer,
        mmi_frm_scrn_get_gui_buf(es_data->group_id, es_data->scrn_id));
        
#else /* Single SIM project */

    ShowCategory7Screen(
        STR_ID_NW_INFO_INVALID_SIM_TITLE,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        0,
        (U8*)get_string(STR_ID_NW_INFO_INVALID_SIM_MSG),
        mmi_frm_scrn_get_gui_buf(es_data->group_id, es_data->scrn_id));
        
#endif

    /* [MAUI_02446047] Disable clipboard function */
    wgui_inputs_ml_set_style(0, GUI_MULTI_LINE_INPUT_BOX_DISABLE_CLIPBOARD);

    SetLeftSoftkeyFunction(mmi_nw_info_close_active_invalid_sim, KEY_EVENT_UP);
#ifndef __MMI_WGUI_DISABLE_CSK__
    SetCenterSoftkeyFunction(mmi_nw_info_close_active_invalid_sim, KEY_EVENT_UP);
#endif /* #ifndef __MMI_WGUI_DISABLE_CSK__ */
    SetKeyHandler(mmi_nw_info_close_active_invalid_sim, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_any_invalid_sim_msg_is_pending
 * DESCRIPTION
 *  Query whether any pending invalid SIM message screen
 * PARAMETERS
 *  void
 * RETURNS
 *  (U8)MMI_TRUE if screen displayed
 *****************************************************************************/
U8 mmi_nw_info_any_invalid_sim_msg_is_pending(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 pending_sims; /* bit set */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /*
     * pending_sims[i] = invalid_sim_processed[i] &&
     *                   !invalid_sim_confirmed[i]
     */
    pending_sims = (g_mmi_nw_info_cntx.invalid_sims_processed &
                   (~g_mmi_nw_info_cntx.invalid_sims_confirmed));
    
    return (U8)(pending_sims != 0 ? MMI_TRUE : MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_display_invalid_sim
 * DESCRIPTION
 *  Callback by idle to display invalid SIM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nw_info_display_invalid_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 scr_id;
    mmi_sim_enum sim;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        sim = mmi_frm_index_to_sim(i);

        if ((g_mmi_nw_info_cntx.invalid_sims_processed & sim) != 0 &&
            (g_mmi_nw_info_cntx.invalid_sims_confirmed & sim) == 0)
        {
            scr_id = g_mmi_nw_info_display_info[i].scr_id;
            mmi_frm_scrn_first_enter(
                mmi_idle_get_group_id(),
                scr_id,
                (FuncPtr)mmi_nw_info_entry_invalid_sim,
                &g_mmi_nw_info_cntx);
                
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_on_register_failed
 * DESCRIPTION
 *  Display invalid SIM screen for register failed.
 * PARAMETERS
 *  evt         [IN] srv_nw_info_register_failed_evt_struct*
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_nw_info_on_register_failed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_register_failed_evt_struct *failed_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_NW_INFO_REGISTER_FAILED);

    failed_evt = (srv_nw_info_register_failed_evt_struct*)evt;

    if (srv_bootup_is_booting())
    {
        return MMI_RET_OK;
    }

    if ((g_mmi_nw_info_cntx.invalid_sims_processed & failed_evt->sim) != 0)
    {
        /* We only process once for an invalid SIM */
        return MMI_RET_OK;
    }

    g_mmi_nw_info_cntx.invalid_sims_processed |= failed_evt->sim;

    /* Show invalid SIM screen only on idle */
    mmi_idle_notify_event();
        
    return MMI_RET_OK;
}

#else /* __MMI_NW_INFO_INVALID_SIM_MESSAGE__ */

mmi_ret mmi_nw_info_on_early_init(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}

#endif /* __MMI_NW_INFO_INVALID_SIM_MESSAGE__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_on_sim_unavailable
 * DESCRIPTION
 *  Reset the display info for an invalid SIM if the SIM is removed
 * PARAMETERS
 *  evt         [IN] srv_sim_ctrl_unavailable_evt_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_nw_info_on_sim_availablity_changed(mmi_event_struct *evt)
{
#ifdef __MMI_NW_INFO_INVALID_SIM_MESSAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_availability_changed_evt_struct *avai_change_evt;
    mmi_sim_enum sim;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bootup_is_booting())
    {
        return MMI_RET_OK;
    }
    
    avai_change_evt = (srv_sim_ctrl_availability_changed_evt_struct*)evt;

    if (avai_change_evt->unavailable_cause == SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED)
    {
        sim = avai_change_evt->sim;
    
        if ((g_mmi_nw_info_cntx.invalid_sims_processed & sim) != 0 &&
            (g_mmi_nw_info_cntx.invalid_sims_confirmed & sim) == 0)
        {
            /* Pending or has been shown */
            S32 sim_index = mmi_frm_sim_to_index(sim);
            mmi_frm_scrn_close(
                mmi_idle_get_group_id(),
                g_mmi_nw_info_display_info[sim_index].scr_id);
        }

        /* Reset the state of the SIM */
        g_mmi_nw_info_cntx.invalid_sims_processed &= ~sim;
        g_mmi_nw_info_cntx.invalid_sims_confirmed &= ~sim;
    }
#endif

    return MMI_RET_OK;
}

