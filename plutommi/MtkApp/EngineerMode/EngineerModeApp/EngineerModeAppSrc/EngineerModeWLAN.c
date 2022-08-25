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
 *  EngineerModeWLAN.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  WLAN settings in Engineer mode, incluing 
 *      - Switching of Milenage Simulation & Real Network
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_EM_DEV_WLAN_EAP_MODE__

/*****************************************************************************
* Include
*****************************************************************************/
#include "GlobalResDef.h"
#include "mmi_rp_app_engineermode1_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "EngineerModeUtil.h"
#include "EngineerModeWLAN.h"
#include "MenuCuiGprot.h"
#include "AlertScreen.h"
#include "supc_inc.h"

/*****************************************************************************
* Define
*****************************************************************************/

/*****************************************************************************
* Global Variable
*****************************************************************************/

/*****************************************************************************
* Function Definition
*****************************************************************************/
static mmi_ret mmi_em_set_wlan_eap_mode_proc(mmi_event_struct* evt);
static void mmi_em_select_wlan_mode(mmi_id send_id, mmi_menu_id highlighted_menu_id);

/*****************************************************************************
* FUNCTION
*  mmi_em_enter_wlan_eap_mode_settings
* DESCRIPTION
*  Entry function for setting WLAN eap mode
* PARAMETERS
*
* RETURNS
*  void
*****************************************************************************/
void mmi_em_enter_wlan_eap_mode_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id eap_mode_gid;
    // mmi_id eap_mode_cid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // Create group
    eap_mode_gid = mmi_frm_group_create_ex (
                                GRP_ID_ROOT, 
                                GRP_ID_AUTO_GEN, 
                                mmi_em_set_wlan_eap_mode_proc, 
                                NULL, 
                                MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_menu_create_and_run (
                        eap_mode_gid, 
                        CUI_MENU_SRC_TYPE_RESOURCE, 
                        CUI_MENU_TYPE_APPSUB, 
                        MENU_ID_EM_DEV_WLAN_SETTING, 
                        MMI_TRUE, 
                        NULL);
#if 0    
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
#endif    
}

/*****************************************************************************
* FUNCTION
*  mmi_em_set_wlan_eap_mode_proc
* DESCRIPTION
*  Entry function for setting WLAN eap mode
* PARAMETERS
*
* RETURNS
*  mmi_ret
*****************************************************************************/
static mmi_ret mmi_em_set_wlan_eap_mode_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        return MMI_RET_OK;

    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(menu_evt->sender_id);
        return MMI_RET_OK;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
        mmi_em_select_wlan_mode(menu_evt->sender_id, menu_evt->highlighted_menu_id);
        return MMI_RET_OK;
        
    default:
        break;
    }

    if (cui_menu_is_menu_event(evt->evt_id))
    {
        return MMI_RET_DONT_CARE;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*  mmi_em_select_wlan_mode
* DESCRIPTION
*  Event handler - EVT_ID_CUI_MENU_ITEM_SELECT 
* PARAMETERS
* mmi_menu_id
* RETURNS
*  void
*****************************************************************************/
static void mmi_em_select_wlan_mode(mmi_id send_id, mmi_menu_id highlighted_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(highlighted_menu_id)
    {
    case MENU_ID_EM_DEV_WLAN_EAP_MODE_SIMULATION:
        //MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_EM_SET_EAP_MODE, WPA_SUPC_MODE_SIMULATOR);
        wpa_supplicant_set_mode(WPA_SUPC_MODE_SIMULATOR);
        break;
    case MENU_ID_EM_DEV_WLAN_EAP_MODE_REAL_NETWORK:
        //MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_EM_SET_EAP_MODE, WPA_SUPC_MODE_REALNETWORK);
        wpa_supplicant_set_mode(WPA_SUPC_MODE_REALNETWORK);
        break;
    default:
        return;
    }

	mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, send_id, NULL);
    // cui_menu_close (send_id);
}

#endif /* __MMI_EM_DEV_WLAN_EAP_MODE__ */

