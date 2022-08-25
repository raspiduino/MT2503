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
 *  SecSetMenu.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Menu of security setup
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "SecSetProt.h"
#include "APNControlList.h" /* mmi_secset_acl_main_menu_proc */
#include "CertManMMIGprots.h" /* mmi_certman_secset_main_menu_proc */
#include "MMIDataType.h"
#include "MMI_features.h"
#include "menucuigprot.h"
#include "mmi_rp_app_security_setting_def.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "kal_general_types.h"
#include "string.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "mmi_frm_history_gprot.h"

#include "MMI_ap_dcm_config.h"
#ifdef __MMI_AP_DCM_SECSET__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif

/****************************************************************************
 * Configurations
 ****************************************************************************/

/*
 * Menu events will be broadcasted to ALL following procs in order
 * Please check whether the event is in your scope carefully.
 * menu_evt->sender_id = the instance ID of setting menu CUI
 */
static const mmi_proc_func mmi_secset_menu_procs_table[] =
{
 #if defined(__MMI_TELEPHONY_SUPPORT__) 
    mmi_secset_sim_main_menu_proc,
 #endif/*defined(__MMI_TELEPHONY_SUPPORT__)*/
    mmi_secset_phone_menu_proc,
#ifdef __MMI_ACL_SUPPORT__
    mmi_secset_acl_main_menu_proc,
#endif
#ifdef __CERTMAN_SUPPORT__
    mmi_certman_secset_main_menu_proc,
#endif
    
    /* ----- Add your menu proc before this line ---- */
    NULL
};


/****************************************************************************
 * Context
 ****************************************************************************/

typedef struct
{
    MMI_ID main_menu_cui;
} mmi_secset_menu_cntx_struct;

static mmi_secset_menu_cntx_struct g_mmi_secset_menu_cntx;


/****************************************************************************
 * Functions
 ****************************************************************************/

static void mmi_secset_broadcast_menu_event(const cui_menu_event_struct *menu_evt);

static mmi_ret mmi_secset_grp_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (cui_menu_is_menu_event(evt->evt_id))
    {
        menu_evt = (cui_menu_event_struct*)evt;

        switch (menu_evt->evt_id)
        {
            case EVT_ID_CUI_MENU_LIST_ENTRY:
                if (menu_evt->parent_menu_id == MENU_ID_SECSET_MAIN_MENU)
                {
                    cui_menu_set_currlist_title(
                        menu_evt->sender_id,
                        get_string(STR_ID_SECSET_APP_NAME),
                        get_image(MAIN_MENU_TITLE_SETTINGS_ICON));
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                    cui_menu_set_access_by_shortcut(menu_evt->sender_id, MMI_TRUE);
                }
                break;

            case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            {
                if (menu_evt->sender_id == g_mmi_secset_menu_cntx.main_menu_cui)
                {
                    g_mmi_secset_menu_cntx.main_menu_cui = 0;
                    cui_menu_close(menu_evt->sender_id);
                    return MMI_RET_OK;
                }
                break;
            }

            default:
                break;
        }
    
        mmi_secset_broadcast_menu_event(menu_evt);
    }
    
    return MMI_RET_OK;
}


static void mmi_secset_broadcast_menu_event(const cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_proc_func *proc_p;
    cui_menu_event_struct processed_menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&processed_menu_evt, menu_evt, sizeof(cui_menu_event_struct));
    processed_menu_evt.user_data = NULL;
    processed_menu_evt.app_data = NULL;

    for (proc_p = mmi_secset_menu_procs_table; *proc_p != NULL; proc_p++)
    {
        MMI_TRACE(MMI_SECSET_TRC_GROUP, TRC_MMI_SECSET_MENU_PROC, (U32)(*proc_p));
        (**proc_p)((mmi_event_struct*)&processed_menu_evt);
    }
    MMI_TRACE(MMI_SECSET_TRC_GROUP, TRC_MMI_SECSET_MENU_PROC, 0);
}


#ifdef __MMI_AP_DCM_SECSET__
#pragma arm section rodata , code
#endif

static void mmi_secset_entry_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_menu_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &g_mmi_secset_menu_cntx;
    
    mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_SECSET,
        mmi_secset_grp_proc,
        cntx,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    //mmi_frm_group_enter(GRP_ID_SECSET, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    cntx->main_menu_cui = cui_menu_create(
        GRP_ID_SECSET,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_FROM_RESOURCE,
        MENU_ID_SECSET_MAIN_MENU,
        MMI_TRUE,
        cntx);

    cui_menu_set_default_title_image(cntx->main_menu_cui, get_image(MAIN_MENU_TITLE_SETTINGS_ICON));

    cui_menu_run(cntx->main_menu_cui);
}


void mmi_secset_main_menu_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetCenterSoftkeyFunction(mmi_secset_entry_menu, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_secset_entry_menu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


