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
 *  NwInfoSignal.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Signal icon of network information
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
#include "NwInfoProt.h"
#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "NwInfoProt.h"
#include "CallSetSrvGprot.h"
#include "CphsSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "MMIDataType.h"
#include "mmi_rp_srv_status_icons_def.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "NwInfoSrvGprot.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "mmi_frm_utility_gprot.h"
#include "GlobalResDef.h"
#include "BootupSrvGprot.h"


/****************************************************************************
 * Configurations
 ****************************************************************************/

#if defined(__OP02__)
/*
 * If this option is defined, the signal icon will display 0 grid on limited service;
 * That is, show >= 1 grid(s) only when full service.
 */
#define MMI_NW_INFO_SHOW_0_GRID_ON_LIMITED_SERVICE
#endif


typedef struct
{
    U16 mainlcd_normal;
    U16 mainlcd_closed;
    U16 mainlcd_line_1;
    U16 mainlcd_line_2;
    U16 sublcd_normal;
    U16 sublcd_closed;
} mmi_nw_info_signal_image_struct;


/****************************************************************************
 * Functions
 ****************************************************************************/

static void mmi_nw_info_signal_set_strength(
                mmi_sim_enum sim,
                S32 strength_in_percentage);


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_change_image
 * DESCRIPTION
 *  Change the image of status icon.
 *  This function checks the validity of icon_id & image_id; if invalid,
 *  ignore directly.
 * PARAMETERS
 *  icon_id     [IN] Icon ID. Do nothing if icon_id == STATUS_ICON_INVALID_ID
 *  image_id    [IN] Image ID. Do nothing if image_id == 0
 * RETURNS
 *  void
 *****************************************************************************/
#define mmi_nw_info_signal_change_image(icon_id, image_id) \
    do { \
        if (icon_id != STATUS_ICON_INVALID_ID && image_id != 0) \
            wgui_status_icon_bar_change_icon_image(icon_id, image_id); \
    } while (0)


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_set_icon_display
 * DESCRIPTION
 *  Set icon to display or hidden
 * PARAMETERS
 *  icon_id     [IN] Icon ID. Do nothing if STATUS_ICON_INVALID_ID
 *  display     [IN] MMI_TRUE to display to icon;
 *                   MMI_FALSE to hide
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nw_info_signal_set_icon_display(S32 icon_id, MMI_BOOL display)
{
    if (icon_id != STATUS_ICON_INVALID_ID)
    {
        if (display)
        {
            wgui_status_icon_bar_set_icon_display(icon_id);
        }
        else
        {
            wgui_status_icon_bar_reset_icon_display(icon_id);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_get_icon_id
 * DESCRIPTION
 *  Get signal strength icon ID of SIM.
 * PARAMETERS
 *  sim             [IN]  Which SIM
 *  mainlcd_icon_id [OUT] Icon ID of main LCD
 *  sublcd_icon_id  [OUT] Icon ID of sub LCD
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nw_info_signal_get_icon_id(
                mmi_sim_enum sim,
                S32 *mainlcd_icon_id,
                S32 *sublcd_icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim == MMI_SIM1)
    {
        *mainlcd_icon_id = STATUS_ICON_SIGNAL_STRENGTH;
    #ifdef __MMI_SUBLCD__
        *sublcd_icon_id = STATUS_ICON_SUBLCD_SIGNAL_STRENGTH;
    #endif
    }
#if (MMI_MAX_SIM_NUM >= 2)
    else if (sim == MMI_SIM2)
    {
        *mainlcd_icon_id = STATUS_ICON_SLAVE_SIGNAL_STRENGTH;
    #ifdef __MMI_SUBLCD__
        *sublcd_icon_id = STATUS_ICON_SUBLCD_SLAVE_SIGNAL_STRENGTH;
    #endif
    }
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    else if (sim == MMI_SIM3)
    {
        *mainlcd_icon_id = STATUS_ICON_SIM3_SIGNAL_STRENGTH;
    #ifdef __MMI_SUBLCD__
        *sublcd_icon_id = STATUS_ICON_INVALID_ID;
    #endif
    }
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    else if (sim == MMI_SIM4)
    {
        *mainlcd_icon_id = STATUS_ICON_SIM4_SIGNAL_STRENGTH;
    #ifdef __MMI_SUBLCD__
        *sublcd_icon_id = STATUS_ICON_INVALID_ID;
    #endif
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_get_image_id
 * DESCRIPTION
 *  Get signal strength icon ID of SIM.
 * PARAMETERS
 *  sim                     [IN]  Which SIM
 *  n_inserted_sim          [IN]  Number of SIMs inserted
 *  out_image               [OUT] Image config by given input condition
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nw_info_signal_get_image_id(
                mmi_sim_enum sim,
                S32 n_inserted_sim,
                mmi_nw_info_signal_image_struct *out_image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifndef __MMI_SUBLCD__
    out_image->sublcd_normal = 0;
    out_image->sublcd_closed = 0;
#endif
#ifndef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
    out_image->mainlcd_line_1 = 0;
    out_image->mainlcd_line_2 = 0;
#endif

#if (MMI_MAX_SIM_NUM == 1)
    out_image->mainlcd_normal = IMG_SI_SIGNAL_STRENGTH;
    out_image->mainlcd_closed = IMG_SI_SIGNAL_STRENGTH;
#ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
    out_image->mainlcd_line_1 = IMG_SI_SIGNAL_STRENGTH_L1;
    out_image->mainlcd_line_2 = IMG_SI_SIGNAL_STRENGTH_L2;
#endif
#ifdef __MMI_SUBLCD__
    out_image->sublcd_normal = IMG_SLSI_SIGNAL_STRENGTH;
    out_image->sublcd_closed = IMG_SLSI_SIGNAL_STRENGTH;
#endif
#endif /* (MMI_MAX_SIM_NUM == 1) */

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    if (n_inserted_sim <= 1)
    {
        out_image->mainlcd_normal = IMG_SI_SIGNAL_STRENGTH;
        out_image->mainlcd_closed = IMG_SI_SIGNAL_STRENGTH;
    #ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
        out_image->mainlcd_line_1 = IMG_SI_SIGNAL_STRENGTH_L1;
        out_image->mainlcd_line_2 = IMG_SI_SIGNAL_STRENGTH_L2;
    #endif
    #ifdef __MMI_SUBLCD__
        out_image->sublcd_normal = IMG_SLSI_SIGNAL_STRENGTH;
        out_image->sublcd_closed = IMG_SLSI_SIGNAL_STRENGTH;
    #endif
        return;
    }
#endif

#if (MMI_MAX_SIM_NUM >= 2)
    if (sim == MMI_SIM1)
    {
        out_image->mainlcd_normal = IMG_SI_MASTER_SIGNAL_STRENGTH;
        out_image->mainlcd_closed = IMG_SI_MASTER_SIGNAL_CLOSED;
    #ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
        out_image->mainlcd_line_1 = IMG_SI_MASTER_SIGNAL_STRENGTH_L1;
        out_image->mainlcd_line_2 = IMG_SI_MASTER_SIGNAL_STRENGTH_L2;
    #endif
    #ifdef __MMI_SUBLCD__
        out_image->sublcd_normal = IMG_SLSI_SIGNAL_STRENGTH;
        out_image->sublcd_closed = IMG_SLSI_SIGNAL_CLOSE;
    #endif
    }
    else if (sim == MMI_SIM2)
    {
        out_image->mainlcd_normal = IMG_SI_SLAVE_SIGNAL_STRENGTH;
        out_image->mainlcd_closed = IMG_SI_SLAVE_SIGNAL_CLOSED;
    #ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
        out_image->mainlcd_line_1 = IMG_SI_SLAVE_SIGNAL_STRENGTH_L1;
        out_image->mainlcd_line_2 = IMG_SI_SLAVE_SIGNAL_STRENGTH_L2;
    #endif
    #ifdef __MMI_SUBLCD__
        out_image->sublcd_normal = IMG_SLSI_SLAVE_SIGNAL_STRENGTH;
        out_image->sublcd_closed = IMG_SLSI_SLAVE_SIGNAL_CLOSE;
    #endif
    }
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    else if (sim == MMI_SIM3)
    {
        out_image->mainlcd_normal = IMG_SI_SIM3_SIGNAL_STRENGTH;
        out_image->mainlcd_closed = IMG_SI_SIM3_SIGNAL_CLOSED;
    #ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
        out_image->mainlcd_line_1 = IMG_SI_SIM3_SIGNAL_STRENGTH_L1;
        out_image->mainlcd_line_2 = IMG_SI_SIM3_SIGNAL_STRENGTH_L2;
    #endif
    #ifdef __MMI_SUBLCD__
        out_image->sublcd_normal = 0;
        out_image->sublcd_closed = 0;
    #endif
    }
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    else if (sim == MMI_SIM4)
    {
        out_image->mainlcd_normal = IMG_SI_SIM4_SIGNAL_STRENGTH;
        out_image->mainlcd_closed = IMG_SI_SIM4_SIGNAL_CLOSED;
    #ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
        out_image->mainlcd_line_1 = IMG_SI_SIM4_SIGNAL_STRENGTH_L1;
        out_image->mainlcd_line_2 = IMG_SI_SIM4_SIGNAL_STRENGTH_L2;
    #endif
    #ifdef __MMI_SUBLCD__
        out_image->sublcd_normal = 0;
        out_image->sublcd_closed = 0;
    #endif
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_on_early_init
 * DESCRIPTION
 *  Initialize signal icon on early init
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_nw_info_signal_on_early_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__OP02__)

#if (MMI_MAX_SIM_NUM >= 2)
    wgui_status_icon_bar_change_icon_image(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_CLOSED);
    wgui_status_icon_bar_change_icon_image(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_CLOSED);
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    wgui_status_icon_bar_change_icon_image(STATUS_ICON_SIM3_SIGNAL_STRENGTH, IMG_SI_SIM3_SIGNAL_CLOSED);
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    wgui_status_icon_bar_change_icon_image(STATUS_ICON_SIM4_SIGNAL_STRENGTH, IMG_SI_SIM4_SIGNAL_CLOSED);
#endif


#if !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)

    wgui_status_icon_bar_set_icon_display(STATUS_ICON_SIGNAL_STRENGTH);
#if (MMI_MAX_SIM_NUM >= 2)
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_SLAVE_SIGNAL_STRENGTH);
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_SIM3_SIGNAL_STRENGTH);
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_SIM4_SIGNAL_STRENGTH);
#endif

#ifdef __MMI_SUBLCD__
#if (MMI_MAX_SIM_NUM >= 2)
    wgui_status_icon_bar_change_icon_image(STATUS_ICON_SUBLCD_SIGNAL_STRENGTH, IMG_SLSI_SIGNAL_CLOSE);
    wgui_status_icon_bar_change_icon_image(STATUS_ICON_SUBLCD_SLAVE_SIGNAL_STRENGTH, IMG_SLSI_SLAVE_SIGNAL_CLOSE);
#endif
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_SUBLCD_SIGNAL_STRENGTH);
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_SUBLCD_SLAVE_SIGNAL_STRENGTH);
#endif /* __MMI_SUBLCD__ */

#endif /* !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */

#endif /* !defined(__OP02__) */

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_set_image
 * DESCRIPTION
 *  Set the image for the signal icon
 * PARAMETERS
 *  sim             [IN]
 *  n_inserted      [IN] Number of SIMs inserted at present
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nw_info_signal_set_image(mmi_sim_enum sim, S32 n_inserted)
{
    S32 mainlcd_icon_id = STATUS_ICON_INVALID_ID,
        sublcd_icon_id = STATUS_ICON_INVALID_ID;
    mmi_nw_info_signal_image_struct image = { 0 };

    mmi_nw_info_signal_get_icon_id(sim, &mainlcd_icon_id, &sublcd_icon_id);
    mmi_nw_info_signal_get_image_id(sim, n_inserted, &image);

    if (n_inserted == 0)
    {
        U16 image_id = image.mainlcd_normal;
    #ifdef __MMI_SUBLCD__
        U16 sub_image_id = image.sublcd_normal;
        #endif

        if(MMI_SIM1 != sim)
        {
            image_id = image.mainlcd_closed;
        #ifdef __MMI_SUBLCD__
            sub_image_id = image.sublcd_closed;
        #endif
        }
        mmi_nw_info_signal_change_image(mainlcd_icon_id, image_id);
    #ifdef __MMI_SUBLCD__
        mmi_nw_info_signal_change_image(sublcd_icon_id, sub_image_id);
    #endif
    }
    else if (n_inserted >= 1)
    {
        srv_mode_switch_type_enum mode;
    
        mode = srv_mode_switch_get_current_mode();
        if (mode & sim)
        {
        #ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
            if (!srv_cphs_is_service_available(SRV_CPHS_GROUP_CPHS_TELESERVICES, SRV_CPHS_SERVICE_ALS, sim))
            {
                /* Line is not supported, identified by EF_CSP */
                mmi_nw_info_signal_change_image(mainlcd_icon_id, image.mainlcd_normal);
            }
            else
            {
                srv_callset_line_id_enum line_id = srv_callset_line_switch_get_id(sim);
            
                if (line_id == SRV_CALLSET_LINE1 && image.mainlcd_line_1 != 0)
                {
                    mmi_nw_info_signal_change_image(mainlcd_icon_id, image.mainlcd_line_1);
                }
                else if (line_id == SRV_CALLSET_LINE2 && image.mainlcd_line_2 != 0)
                {
                    mmi_nw_info_signal_change_image(mainlcd_icon_id, image.mainlcd_line_2);
                }
                else
                {
                    mmi_nw_info_signal_change_image(mainlcd_icon_id, image.mainlcd_normal);
                }
            }
        #else /* __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ */
        
            mmi_nw_info_signal_change_image(mainlcd_icon_id, image.mainlcd_normal);
            
        #endif
        
        #ifdef __MMI_SUBLCD__
            mmi_nw_info_signal_change_image(sublcd_icon_id, image.sublcd_normal);
        #endif
        }
    #ifndef __OP02__ /* OP02: Show closed icon only if SIM is not inserted */
        else /* Mode is not enabled */
        {
            mmi_nw_info_signal_change_image(mainlcd_icon_id, image.mainlcd_closed);
        #ifdef __MMI_SUBLCD__
            mmi_nw_info_signal_change_image(sublcd_icon_id, image.sublcd_closed);
        #endif
        }
    #endif /* __OP02__ */
    }
}


#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_set_all_icon_properties
 * DESCRIPTION
 *  Set all properties, e.g. hide/unhide, image, by current condition
 * PARAMETERS
 *  n_inserted      [IN] Number of SIMs inserted at present
 *  inserted_sims   [IN] Bitset of inserted SIMs
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nw_info_signal_set_all_icon_properties(S32 n_inserted, mmi_sim_enum inserted_sims)
{
    S32 i;
    mmi_sim_enum sim;
    S32 mainlcd_icon_id = STATUS_ICON_INVALID_ID,
        sublcd_icon_id = STATUS_ICON_INVALID_ID;
    srv_mode_switch_type_enum mode;
    mmi_sim_enum sim_to_show = MMI_SIM_NONE;

    mode = srv_mode_switch_get_current_mode();

    if (n_inserted <= 1)
    {
        sim_to_show = MMI_SIM1;
        if (mode == SRV_MODE_SWITCH_ALL_OFF)
        {
            for (i = 0, sim = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim <<= 1)
            {
                if (srv_sim_ctrl_is_inserted(sim))
                {
                    sim_to_show = sim;
                    break;
                }
            }
        }
        else
        {
            /* Only one signal icon can be shown */
            for (i = 0, sim = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim <<= 1)
            {
                if (mode & sim)
                {
                    sim_to_show = sim;
                    break;
                }
            }
        }
    }
    else
    {
        sim_to_show = inserted_sims;
    }

    for (i = 0, sim = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim <<= 1)
    {
        mmi_nw_info_signal_get_icon_id(sim, &mainlcd_icon_id, &sublcd_icon_id);
        
        if (sim_to_show & sim)
        {
            mmi_nw_info_signal_set_image(sim, n_inserted);

            mmi_nw_info_signal_set_icon_display(mainlcd_icon_id, MMI_TRUE);
        #ifdef __MMI_SUBLCD__
            mmi_nw_info_signal_set_icon_display(sublcd_icon_id, MMI_TRUE);
        #endif
        }
        else
        {
            mmi_nw_info_signal_set_icon_display(mainlcd_icon_id, MMI_FALSE);
        #ifdef __MMI_SUBLCD__
            mmi_nw_info_signal_set_icon_display(sublcd_icon_id, MMI_FALSE);
        #endif
        }
    }
}
#endif

#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_on_sim_slot_ready
 * DESCRIPTION
 *  Initialize signal icon on by SIM slot status
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_nw_info_signal_on_sim_slot_ready(mmi_event_struct *evt)
{
#if defined(__OP02__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_sim_slot_ready_evt_struct *slot_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    slot_evt = (srv_bootup_sim_slot_ready_evt_struct*)evt;

    /*
     * Rule for OP02:
     * Show SIM closed icon if and only if SIM is absent. Not according to
     * network mode.
     */

    if ((slot_evt->inserted_sims & MMI_SIM1) == 0)
    {
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_CLOSED);
#ifdef __MMI_SUBLCD__
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_SUBLCD_SIGNAL_STRENGTH, IMG_SLSI_SIGNAL_CLOSE);
#endif
    }
    if ((slot_evt->inserted_sims & MMI_SIM2) == 0)
    {
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_CLOSED);
#ifdef __MMI_SUBLCD__
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_SUBLCD_SLAVE_SIGNAL_STRENGTH, IMG_SLSI_SLAVE_SIGNAL_CLOSE);
#endif
    }
#if (MMI_MAX_SIM_NUM >= 3)
    if ((slot_evt->inserted_sims & MMI_SIM3) == 0)
    {
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_SIM3_SIGNAL_STRENGTH, IMG_SI_SIM3_SIGNAL_CLOSED);
    }
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    if ((slot_evt->inserted_sims & MMI_SIM4) == 0)
    {
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_SIM4_SIGNAL_STRENGTH, IMG_SI_SIM4_SIGNAL_CLOSED);
    }
#endif

    wgui_status_icon_bar_set_icon_display(STATUS_ICON_SIGNAL_STRENGTH);
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_SLAVE_SIGNAL_STRENGTH);
    
#elif defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_sim_slot_ready_evt_struct *slot_evt;
    S32 mainlcd_icon_id = STATUS_ICON_INVALID_ID,
        sublcd_icon_id = STATUS_ICON_INVALID_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    slot_evt = (srv_bootup_sim_slot_ready_evt_struct*)evt;

    if (slot_evt->n_inserted == 0)
    {
        mmi_nw_info_signal_get_icon_id(MMI_SIM1, &mainlcd_icon_id, &sublcd_icon_id);
        mmi_nw_info_signal_change_image(mainlcd_icon_id, IMG_SI_SIGNAL_STRENGTH);
        mmi_nw_info_signal_change_image(sublcd_icon_id, IMG_SLSI_SIGNAL_STRENGTH);
        
        mmi_nw_info_signal_set_icon_display(mainlcd_icon_id, MMI_TRUE);
    #ifdef __MMI_SUBLCD__
        mmi_nw_info_signal_set_icon_display(sublcd_icon_id, MMI_TRUE);
    #endif
    }
    else if (slot_evt->n_inserted == MMI_SIM1)
    {
        mmi_nw_info_signal_get_icon_id(slot_evt->inserted_sims, &mainlcd_icon_id, &sublcd_icon_id);
        mmi_nw_info_signal_change_image(mainlcd_icon_id, IMG_SI_SIGNAL_STRENGTH);
        mmi_nw_info_signal_change_image(sublcd_icon_id, IMG_SLSI_SIGNAL_STRENGTH);

        mmi_nw_info_signal_set_icon_display(mainlcd_icon_id, MMI_TRUE);
    #ifdef __MMI_SUBLCD__
        mmi_nw_info_signal_set_icon_display(sublcd_icon_id, MMI_TRUE);
    #endif
    }
    else
    {
        S32 i;
        mmi_sim_enum sim;
        
        for (i = 0, sim = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim <<= 1)
        {
            mmi_nw_info_signal_get_icon_id(sim, &mainlcd_icon_id, &sublcd_icon_id);
        
            if (slot_evt->inserted_sims & sim)
            {
                mmi_nw_info_signal_set_icon_display(mainlcd_icon_id, MMI_TRUE);
            #ifdef __MMI_SUBLCD__
                mmi_nw_info_signal_set_icon_display(sublcd_icon_id, MMI_TRUE);
            #endif
            }
            else
            {
                mmi_nw_info_signal_set_icon_display(mainlcd_icon_id, MMI_FALSE);
            #ifdef __MMI_SUBLCD__
                mmi_nw_info_signal_set_icon_display(sublcd_icon_id, MMI_FALSE);
            #endif
            }
        }
    }
    
#endif
    
    return MMI_RET_OK;
}
#endif /* (MMI_MAX_SIM_NUM >= 2) */

#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_get_inserted_sims
 * DESCRIPTION
 *  Get the bitset of inserted SIMs.
 * PARAMETERS
 *  void
 * RETURNS
 *  The bitset of inserted SIMs
 *****************************************************************************/
static mmi_sim_enum mmi_nw_info_signal_get_inserted_sims(void)
{
    S32 i;
    mmi_sim_enum inserted_sims;
    mmi_sim_enum sim;

    inserted_sims = MMI_SIM_NONE;
    for (i = 0, sim = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim <<= 1)
    {
        if (srv_sim_ctrl_is_inserted(sim))
        {
            inserted_sims |= sim;
        }
    }

    return inserted_sims;
}
#endif /* #if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */

/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_on_mode_decided
 * DESCRIPTION
 *  Initialize signal strength icons.
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_nw_info_signal_on_mode_decided(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __OP02__ /* OP02 behavior depends on SIM present rather than mode */

#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)

    mmi_nw_info_signal_set_all_icon_properties(
        srv_sim_ctrl_get_num_of_inserted(),
        mmi_nw_info_signal_get_inserted_sims());

#else

    /*
     * Traditional signal UE design:
     * Regardless how many SIMs are inserted, always show icons with SIM numbers
     */

#if (MMI_MAX_SIM_NUM >= 2)
    if (srv_nw_info_is_enabled(MMI_SIM1))
    {
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH);
    #ifdef __MMI_SUBLCD__
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_SUBLCD_SIGNAL_STRENGTH, IMG_SLSI_SIGNAL_STRENGTH);
    #endif
    }
    
    if (srv_nw_info_is_enabled(MMI_SIM2))
    {
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_STRENGTH);
    #ifdef __MMI_SUBLCD__
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_SUBLCD_SLAVE_SIGNAL_STRENGTH, IMG_SLSI_SLAVE_SIGNAL_STRENGTH);
    #endif
    }
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    if (srv_nw_info_is_enabled(MMI_SIM3))
    {
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_SIM3_SIGNAL_STRENGTH, IMG_SI_SIM3_SIGNAL_STRENGTH);
    }
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    if (srv_nw_info_is_enabled(MMI_SIM4))
    {
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_SIM4_SIGNAL_STRENGTH, IMG_SI_SIM4_SIGNAL_STRENGTH);
    }
#endif

#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */

#endif /* !defined(__OP02__) */

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_on_service_avai_changed
 * DESCRIPTION
 *  Handler for service availability chahnged.
 *  To update signal strength icon.
 * PARAMETERS
 *  evt     [IN] srv_nw_info_service_availability_changed_evt_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_nw_info_signal_on_service_avai_changed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_service_availability_changed_evt_struct *availability_evt;
    S32 strength_in_percentage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED);
    
    availability_evt = (srv_nw_info_service_availability_changed_evt_struct*)evt;

    strength_in_percentage = 0;
    switch (availability_evt->new_status)
    {
        case SRV_NW_INFO_SA_NO_SERVICE:
    #ifdef MMI_NW_INFO_SHOW_0_GRID_ON_LIMITED_SERVICE
        case SRV_NW_INFO_SA_LIMITED_SERVICE:
    #endif
            strength_in_percentage = 0;
            break;

        case SRV_NW_INFO_SA_FULL_SERVICE:
    #ifndef MMI_NW_INFO_SHOW_0_GRID_ON_LIMITED_SERVICE
        case SRV_NW_INFO_SA_LIMITED_SERVICE:
    #endif
            strength_in_percentage =
                srv_nw_info_get_signal_strength_in_percentage(availability_evt->sim);
            break;
            
        case SRV_NW_INFO_SA_SEARCHING:
            /* Don't change; go through to return */
        default:
            /* Ignore */
            return MMI_RET_OK;
    }

    mmi_nw_info_signal_set_strength(availability_evt->sim, strength_in_percentage);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_set_strength
 * DESCRIPTION
 *  Set the icon of signal strength by given value
 * PARAMETERS
 *  sim                     [IN] Which SIM
 *  strength_in_percentage  [IN] Signal strength
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nw_info_signal_set_strength(
                mmi_sim_enum sim,
                S32 strength_in_percentage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 percent = strength_in_percentage;
    S32 mainlcd_icon_id = STATUS_ICON_INVALID_ID,
        sublcd_icon_id = STATUS_ICON_INVALID_ID;
    srv_nw_info_service_availability_enum service_availability = srv_nw_info_get_service_availability(sim);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_nw_info_signal_get_icon_id(
        sim,
        &mainlcd_icon_id,
        &sublcd_icon_id);

	if (!srv_sim_ctrl_is_inserted(sim) || service_availability != SRV_NW_INFO_SA_FULL_SERVICE)
	{
		percent = 0;
	}
    MMI_TRACE(MMI_NW_INFO_TRC_GROUP, TRC_MMI_NW_INFO_SIGNAL_ICON_CHANGED,
        sim, percent);
        
    wgui_status_icon_bar_change_icon_level(mainlcd_icon_id, percent);
    if (sublcd_icon_id != STATUS_ICON_INVALID_ID)
    {
        wgui_status_icon_bar_change_icon_level(sublcd_icon_id, percent);
    }

    wgui_status_icon_bar_update();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_on_strength_changed
 * DESCRIPTION
 *  Handler for signal strength changed.
 *  Update signal strength icon.
 * PARAMETERS
 *  evt     [IN] srv_nw_info_signal_strength_changed_evt_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_nw_info_signal_on_strength_changed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_signal_strength_changed_evt_struct *strength_evt;
    srv_nw_info_service_availability_enum service_availability;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_NW_INFO_SIGNAL_STRENGTH_CHANGED);

    strength_evt = (srv_nw_info_signal_strength_changed_evt_struct*)evt;

    service_availability = srv_nw_info_get_service_availability(strength_evt->sim);
    if (service_availability != SRV_NW_INFO_SA_NO_SERVICE &&
    #ifdef MMI_NW_INFO_SHOW_0_GRID_ON_LIMITED_SERVICE
        service_availability != SRV_NW_INFO_SA_LIMITED_SERVICE &&
    #endif
        service_availability != SRV_NW_INFO_SA_SEARCHING)
    {
        mmi_nw_info_signal_set_strength(strength_evt->sim, strength_evt->new_percentage);
    }
	// slim_ifelse
    //else
    //{
        /*
         * The strength icon will be updated from NO_SERVICE/SEARCHING to
         * FULL/LIMITED_SERVICE by mmi_nw_info_signal_on_service_avai_changed()
         */
    //}

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_on_mode_switched
 * DESCRIPTION
 *  Update signal right after mode switched
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_nw_info_signal_on_mode_switched(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_sim_enum sim_id;
    srv_nw_info_service_availability_enum service_availability;
    S32 n_inserted_sims;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    n_inserted_sims = srv_sim_ctrl_get_num_of_inserted();

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__

    mmi_nw_info_signal_set_all_icon_properties(
        n_inserted_sims,
        mmi_nw_info_signal_get_inserted_sims());
        
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
    
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        sim_id = mmi_frm_index_to_sim(i);

    #ifdef __OP02__
        if (!srv_sim_ctrl_is_inserted(sim_id))
        {
            /*
             * We don't need to change icon if SIM is not inserted.
             * Keep "x" antenna icon.
             */
            continue;
        }
    #endif

        /* Change icon image by current mode */
        mmi_nw_info_signal_set_image(sim_id, n_inserted_sims);

        /* update level */
        service_availability = srv_nw_info_get_service_availability(sim_id);

        /* If SIM is not inserted, we will only show "x" antenna icon */
        if (srv_mode_switch_get_network_mode(sim_id) == SRV_MODE_SWITCH_ON &&
            service_availability != SRV_NW_INFO_SA_NO_SERVICE &&
        #ifdef MMI_NW_INFO_SHOW_0_GRID_ON_LIMITED_SERVICE
            service_availability != SRV_NW_INFO_SA_LIMITED_SERVICE &&
        #endif
            service_availability != SRV_NW_INFO_SA_SEARCHING)
        {
            S32 strength;

            strength = srv_nw_info_get_signal_strength_in_percentage(sim_id);
            mmi_nw_info_signal_set_strength(sim_id, strength);
        }
    #if defined(__OP02__)
        else if (service_availability != SRV_NW_INFO_SA_SEARCHING)
        {
            /* Mode off or NO_SERVICE/LIMITED_SERVICE */
            mmi_nw_info_signal_set_strength(sim_id, 0);
        }
    #endif
        
    }

    return MMI_RET_OK;
}


#ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_on_line_switched
 * DESCRIPTION
 *  Change signal image for line switch
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_nw_info_signal_on_line_switched(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_line_switched_evt_struct *switch_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch_evt = (srv_callset_line_switched_evt_struct*)evt;

    mmi_nw_info_signal_set_image(
        switch_evt->sim,
        srv_sim_ctrl_get_num_of_inserted());
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_on_csp_refreshed
 * DESCRIPTION
 *  EF_CSP describes the enableness of line
 *  Change signal image on CSP refreshed.
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_nw_info_signal_on_csp_refreshed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cphs_csp_refresh_struct *csp_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    csp_evt = (srv_cphs_csp_refresh_struct*)evt;

    mmi_nw_info_signal_set_image(
        csp_evt->sim_id,
        srv_sim_ctrl_get_num_of_inserted());
    
    return MMI_RET_OK;
}
#endif /* __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ */


#if defined(__SIM_HOT_SWAP_SUPPORT__) && defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_on_sim_event
 * DESCRIPTION
 *  Update signal icons by SIM events
 * PARAMETERS
 *  evt     [IN] srv_sim_ctrl_event_detected_evt_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_nw_info_signal_on_sim_event(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_event_detected_evt_struct *sim_evt;
    S32 n_inserted_sims;
    MMI_BOOL update_dynamic_ui;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_evt = (srv_sim_ctrl_event_detected_evt_struct*)evt;

    if (srv_bootup_is_booting())
    {
        return MMI_RET_OK;
    }

    n_inserted_sims = srv_sim_ctrl_get_num_of_inserted();

    update_dynamic_ui = MMI_FALSE;
    
    if (sim_evt->type == SRV_SIM_CTRL_EVENT_DET_INSERTED ||
        sim_evt->type == SRV_SIM_CTRL_EVENT_DET_RECOVERY_END)
    {
        if (n_inserted_sims == 2)
        {
            update_dynamic_ui = MMI_TRUE;
        }
    }

    if (sim_evt->type == SRV_SIM_CTRL_EVENT_DET_INSERTED ||
        sim_evt->type == SRV_SIM_CTRL_EVENT_DET_RECOVERY_END)
    {
        if (n_inserted_sims == 1)
        {
            update_dynamic_ui = MMI_TRUE;
        }
    }

    if (update_dynamic_ui)
    {
        mmi_nw_info_signal_set_all_icon_properties(
            srv_sim_ctrl_get_num_of_inserted(),
            mmi_nw_info_signal_get_inserted_sims());
    }

    return MMI_RET_OK;
}
#endif

