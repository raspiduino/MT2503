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

/*******************************************************************************
 * Filename:
 * ---------
 * IPSecApp.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements functions of IPSec settings application.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_IPSEC__

/* #define MMI_IPSEC_UT */
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
#include "kmp_app.h"
#include "ProfilesSrvGprot.h"
#include "InlineCuiGprot.h"
#include "menucuigprot.h"
#include "FSEditorCuiGprot.h"
#include "App_str.h"
#include "mmi_rp_app_ipsec_def.h"
#include "IPSecAppProt.h"
#include "wgui_categories_list.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "gui_data_types.h"
#include "string.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "common_nvram_editor_data_item.h"
#include "wgui_categories_list.h"
#include "mmi_frm_events_gprot.h"
#include "nvram_common_defs.h"
#include "Unicodexdcl.h"
#include "CustDataRes.h"
#include "wgui_categories_util.h"
#include "gui_fixed_menuitems.h"
#include "GlobalConstants.h"
#include "wgui_categories.h"
#include "ImeGprot.h"
#include "wgui_categories_inputs.h"
#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
#include "gui.h"
#include "AlertScreen.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "in.h"
#include "soc_api.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "wgui_touch_screen.h"
mmi_ipsec_context_struct                g_ipsec_cntx;
mmi_ipsec_context_struct                *g_ipsec_cntx_p = &g_ipsec_cntx;

static MMI_BOOL                         is_ipsec_alg_inline_changed = MMI_FALSE;
/* this array is used for storing the profile name when renaming the profile name */ 
static UI_character_type  rename_prof_name[MMI_IPSEC_MAX_PROF_NAME_LEN + 1];

extern const    U16         gIndexIconsImageList[];
extern kal_uint16 soc_htons(kal_uint16 a);
void mmi_ipsec_send_test_request(U16 rsp_id);/* for testing only */

/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_init
 * DESCRIPTION
 *  Initialize IPSec application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 activated = 0;
    U8 act_index = 0;
    S16 err = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_ipsec_cntx_p, 0, sizeof(mmi_ipsec_context_struct));
    g_ipsec_cntx_p->working_status = MMI_IPSEC_STATUS_LOCALSETTINGS;
    g_ipsec_cntx_p->activated = MMI_FALSE; 
    g_ipsec_cntx_p->activated_index = MMI_IPSEC_MAX_PROFILE_NUM;
    g_ipsec_cntx_p->profile_selected = 0;
    ReadValue(NVRAM_IPSEC_ACTIVATE_ON_START, &activated, DS_BYTE, &err);
    ReadValue(NVRAM_IPSEC_ACTIVATE_PROF_INDEX, &act_index, DS_BYTE, &err);
    if (activated)
    {
        if (act_index < MMI_IPSEC_MAX_PROFILE_NUM)
        {
            g_ipsec_cntx_p->profile_selected = act_index;
            mmi_ipsec_prof_activate();
        }
    }
}

#define MMI_IPSEC_SCREENS
/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_launch
 * DESCRIPTION
 *  Entry profile list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(
        GRP_ID_ROOT,
        GRP_ID_IPSEC,
        mmi_ipsec_scr_group_proc,
        (void*)NULL);
    mmi_frm_group_enter(GRP_ID_IPSEC, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    g_ipsec_cntx_p->profile_selected = 0;
    mmi_ipsec_prof_pre_entry_prof_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_scr_group_proc
 * DESCRIPTION
 *  Entry profile list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_ipsec_scr_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    mmi_group_event_struct *inline_evt = (mmi_group_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_ID_IPSECAPP_PROF_LIST_OPT_ACTIVATE:
                    mmi_ipsec_prof_activate();
                    break;

                case MENU_ID_IPSECAPP_PROF_LIST_OPT_DEACTIVATE:
                    mmi_ipsec_prof_deactivate();
                    break;

                case MENU_ID_IPSECAPP_PROF_LIST_OPT_EDIT:
                    break;

                case MENU_ID_IPSECAPP_PROF_LIST_OPT_RENAME:
                    memcpy(
                        rename_prof_name,
                        g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].prof_name,
                        sizeof(rename_prof_name));
                    mmi_ipsec_entry_prof_rename();
                    break;

                case MENU_ID_IPSECAPP_PROF_SETTINGS_POLICY:
                    mmi_ipsec_prof_pre_entry_prof_policy();
                    break;

                case MENU_ID_IPSECAPP_PROF_SETTINGS_IKE:
                    mmi_ipsec_prof_pre_entry_prof_ike();
                    break;

                default:
                    break;
            }
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;

        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
            cui_fseditor_get_text(
                g_ipsec_cntx_p->cui_rename_editor_id,
                rename_prof_name,
                sizeof(rename_prof_name));
            mmi_ipsec_save_prof_name();
            break;

        case EVT_ID_CUI_FSEDITOR_ABORT:
            cui_fseditor_close(g_ipsec_cntx_p->cui_rename_editor_id);
            break;
            
        case EVT_ID_GROUP_EXIT:
            break;
    }

    /* handle inline CUI event */
    if (inline_evt->sender_id == g_ipsec_cntx_p->cui_policy_inline_id)
    {
        mmi_ipsec_policy_inline_proc(inline_evt);
    }
    else if (inline_evt->sender_id == g_ipsec_cntx_p->cui_policy_alg_inline_id)
    {
        mmi_ipsec_policy_alg_inline_proc(inline_evt);
    }
    else if (inline_evt->sender_id == g_ipsec_cntx_p->cui_ike_inline_id)
    {
        mmi_ipsec_ike_inline_proc(inline_evt);
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_entry_prof_list
 * DESCRIPTION
 *  Entry profile list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_entry_prof_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8                  *nStrItemList[MMI_IPSEC_MAX_PROFILE_NUM];
    U16                 nIconItemList[MMI_IPSEC_MAX_PROFILE_NUM];
    U8                  *guiBuffer;
    nvram_ef_ipsec_profile_name_struct profile_name;
    S16 err = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_IPSEC,
                        SCR_ID_IPSECAPP_PFOF_LIST,
                        NULL,
                        (FuncPtr)mmi_ipsec_entry_prof_list,
                        MMI_FRM_FULL_SCRN))
    {
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();

        for (i = 0; i < MMI_IPSEC_MAX_PROFILE_NUM; i++)
        {
            ReadRecord(
                NVRAM_EF_IPSEC_PROFILE_NAME_LID,
                (U16)(i + 1),
                &profile_name,
                sizeof(nvram_ef_ipsec_profile_name_struct),
                &err);
            if (!mmi_ucs2strlen((S8*)profile_name.prof_name))
            {
                mmi_ucs2cpy((S8*)g_ipsec_cntx_p->profiles[i].prof_name, (S8*)GetString((U16)(STR_ID_IPSECAPP_DEFAULT_PROFILE_NAME1 + i)));
            }
            else
            {
                mmi_ucs2cpy((S8*)g_ipsec_cntx_p->profiles[i].prof_name, (S8*)profile_name.prof_name);
            }
            nStrItemList[i] = (U8*)g_ipsec_cntx_p->profiles[i].prof_name;
            nIconItemList[i] = 0;
        }

        if (g_ipsec_cntx_p->activated)
        {
            nIconItemList[g_ipsec_cntx_p->activated_index] = IMG_VICON;
            if (guiBuffer == NULL)
            {
                // first entry
                g_ipsec_cntx_p->profile_selected = g_ipsec_cntx_p->activated_index;
            }
        }
    
        RegisterHighlightHandler(mmi_ipsec_hilite_prof_list);
    
        ShowCategory73Screen(
            STR_ID_IPSECAPP_PROFILE,
            GetRootTitleIcon(MENU_ID_IPSECAPP_SETTINGS),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            MMI_IPSEC_MAX_PROFILE_NUM,
            nStrItemList,
            (U16*)nIconItemList,
            (U16*)gIndexIconsImageList,
            (S32)g_ipsec_cntx_p->profile_selected,
            guiBuffer,
            ICON_ICON_TEXT);

        SetLeftSoftkeyFunction(mmi_ipsec_entry_prof_list_opt, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_ipsec_prof_list_csk_hdlr, KEY_EVENT_UP);
#ifdef __MMI_FTE_SUPPORT__
        wgui_register_tap_callback(mmi_ipsec_fte_prof_list_tap_callback);
#endif /* __MMI_FTE_SUPPORT__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_entry_prof_list_opt
 * DESCRIPTION
 *  Entry function of Profile->Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_entry_prof_list_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ipsec_cntx_p->cui_option_menu_id = cui_menu_create(
                                            GRP_ID_IPSEC,
                                            CUI_MENU_SRC_TYPE_RESOURCE,
                                            CUI_MENU_TYPE_OPTION,
                                            MENU_ID_IPSECAPP_PROF_LIST_OPT,
                                            MMI_TRUE,
                                            NULL);
    if (g_ipsec_cntx_p->activated_index == g_ipsec_cntx_p->profile_selected)
    {
        cui_menu_set_item_hidden(
            g_ipsec_cntx_p->cui_option_menu_id,
            MENU_ID_IPSECAPP_PROF_LIST_OPT_ACTIVATE,
            MMI_TRUE);
        cui_menu_set_item_hidden(
            g_ipsec_cntx_p->cui_option_menu_id,
            MENU_ID_IPSECAPP_PROF_LIST_OPT_DEACTIVATE,
            MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(
            g_ipsec_cntx_p->cui_option_menu_id,
            MENU_ID_IPSECAPP_PROF_LIST_OPT_ACTIVATE,
            MMI_FALSE);
        cui_menu_set_item_hidden(
            g_ipsec_cntx_p->cui_option_menu_id,
            MENU_ID_IPSECAPP_PROF_LIST_OPT_DEACTIVATE,
            MMI_TRUE);
    }

    cui_menu_set_default_title_image(
        g_ipsec_cntx_p->cui_option_menu_id,
        get_image(GetRootTitleIcon(MENU_ID_IPSECAPP_SETTINGS)));
    cui_menu_run(g_ipsec_cntx_p->cui_option_menu_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_pre_entry_prof_list
 * DESCRIPTION
 *  Pre-Entry function of profile liset screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_prof_pre_entry_prof_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_ipsec_cntx_p->profiles, 0, sizeof(g_ipsec_cntx_p->profiles));
    memset(&(g_ipsec_cntx_p->prof_misc), 0, sizeof(mmi_ipsec_profile_misc_struct));
    /* activated, activated_index & profile_selected ignored */
    if (g_ipsec_cntx_p->working_status == MMI_IPSEC_STATUS_LOCALSETTINGS)
    {
        mmi_ipsec_entry_prof_list();
    }
    else
    {
        mmi_ipsec_show_popup_screen(
            (WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
            MMI_EVENT_FAILURE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_read_prof_ike_from_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_read_prof_policy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_ipsec_policy_struct     policy_storage_buffer;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_IPSEC_POLICY_LID, (U16)(g_ipsec_cntx_p->profile_selected + 1), &policy_storage_buffer, NVRAM_EF_IPSEC_POLICY_SIZE, &error);
    /* LOADING POLICY */
    /* src port */
    if (policy_storage_buffer.src_port == 0)
    {
        policy_storage_buffer.src_port = 80;
    }
    g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_port = policy_storage_buffer.src_port;

    /* src addr */
    g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_addr[0] = policy_storage_buffer.src_addr[0];    
    g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_addr[1] = policy_storage_buffer.src_addr[1];
    g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_addr[2] = policy_storage_buffer.src_addr[2];
    g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_addr[3] = policy_storage_buffer.src_addr[3];
    
    /* dest port */
    if (policy_storage_buffer.dest_port == 0)
    {
        policy_storage_buffer.dest_port = 80;
    }
    g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_port = policy_storage_buffer.dest_port;

    /* dest addr */
    g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_addr[0] = policy_storage_buffer.dest_addr[0];    
    g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_addr[1] = policy_storage_buffer.dest_addr[1];
    g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_addr[2] = policy_storage_buffer.dest_addr[2];
    g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_addr[3] = policy_storage_buffer.dest_addr[3];
    
    /* ipsec mode */
    g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.ipsec_mode = (mmi_ipsec_mode_item_enum)policy_storage_buffer.ipsec_mode;

    /* tunnel port */
    g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.tunnel_port = policy_storage_buffer.tunnel_port;

    /* tunnel addr */
    g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.tunnel_addr[0] = policy_storage_buffer.tunnel_addr[0];    
    g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.tunnel_addr[1] = policy_storage_buffer.tunnel_addr[1];
    g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.tunnel_addr[2] = policy_storage_buffer.tunnel_addr[2];
    g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.tunnel_addr[3] = policy_storage_buffer.tunnel_addr[3];

    /* AH authentication */
    g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.alg_ah_auth = policy_storage_buffer.alg_ah_auth;
    g_ipsec_cntx_p->policy_ike_temp.alg_ah_auth = policy_storage_buffer.alg_ah_auth;

    /* ESP authentication */
    g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.alg_esp_auth = policy_storage_buffer.alg_esp_auth;
    g_ipsec_cntx_p->policy_ike_temp.alg_esp_auth = policy_storage_buffer.alg_esp_auth;

    /* ESP encryption */
    g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.alg_esp_enc = policy_storage_buffer.alg_esp_enc;
    g_ipsec_cntx_p->policy_ike_temp.alg_esp_enc = policy_storage_buffer.alg_esp_enc;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_read_prof_ike
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_read_prof_ike(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_ipsec_ike_struct        ike_storage_buffer;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_IPSEC_IKE_LID, (U16)(g_ipsec_cntx_p->profile_selected + 1), &ike_storage_buffer, NVRAM_EF_IPSEC_IKE_SIZE, &error);
    /* LOADING IKE */
    /* Pre-shared key */
    mmi_asc_to_ucs2(
        (S8*)g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.preshared_key, 
        (S8*)ike_storage_buffer.preshared_key);
    /* Auth method */
    g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.auth_method = ike_storage_buffer.auth_method;
    /* Enc method */
    g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.enc_method = ike_storage_buffer.enc_method;
    /* DH method */
    g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.dh_method = ike_storage_buffer.dh_method;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_pre_entry_prof_policy
 * DESCRIPTION
 *  Pre-Entry function of policy setting screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_prof_pre_entry_prof_policy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ipsec_read_prof_policy();
    mmi_ipsec_entry_prof_policy();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_pre_entry_prof_ike
 * DESCRIPTION
 *  Pre-Entry function of ike setting screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_prof_pre_entry_prof_ike(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ipsec_read_prof_ike();
    mmi_ipsec_entry_prof_ike();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_entry_prof_policy
 * DESCRIPTION
 *  Entry function of policy settings screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_entry_prof_policy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_struct inline_struct = {0};

    cui_inline_item_caption_struct      caption_1;
    cui_inline_item_text_edit_struct    text_editor_2;
    cui_inline_item_caption_struct      caption_3;
    cui_inline_item_ip4_struct          ip4_4;
    cui_inline_item_caption_struct      caption_5;
    cui_inline_item_text_edit_struct    text_editor_6;
    cui_inline_item_caption_struct      caption_7;
    cui_inline_item_ip4_struct          ip4_8;
#ifdef __MMI_IPSEC_TUNNEL_MODE__
    cui_inline_item_caption_struct      caption_9;
    cui_inline_item_select_struct       select_10;
    cui_inline_item_caption_struct      caption_11;
    cui_inline_item_text_edit_struct    text_editor_12;
    cui_inline_item_caption_struct      caption_13;
    cui_inline_item_ip4_struct          ip4_14;
#endif /* __MMI_IPSEC_TUNNEL_MODE__ */
    cui_inline_item_display_only_struct display_only_15;

    cui_inline_set_item_struct inline_item[MMI_IPSEC_POLICY_TOTAL_ITEM - CUI_INLINE_ITEM_ID_BASE];
    WCHAR set_value_port[MMI_IPSEC_MAX_PORT_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(is_ipsec_alg_inline_changed == MMI_TRUE)
    {
        is_ipsec_alg_inline_changed = MMI_FALSE;
    }
    
    caption_1.string_id = STR_ID_IPSECAPP_SRC_PORT;
    inline_item[0].item_id = MMI_IPSEC_POLICY_SRC_PORT_CAP;
    inline_item[0].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[0].image_id = IMG_ID_IPSECAPP_POLICY_SRC_PORT;
    inline_item[0].item_data = &caption_1;
    
    text_editor_2.string_id = 0;
    text_editor_2.default_text_id = 0;
    text_editor_2.buffer_size = MMI_IPSEC_MAX_PORT_LEN + 1;
    text_editor_2.input_type = IMM_INPUT_TYPE_NUMERIC;
    text_editor_2.input_extended_type = 0;
    text_editor_2.required_input_mode_set = NULL;
    inline_item[1].item_id = MMI_IPSEC_POLICY_SRC_PORT;
    inline_item[1].item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_NO_LEADING_ZERO;
    inline_item[1].image_id = 0;
    inline_item[1].item_data = &text_editor_2;

    caption_3.string_id = STR_ID_IPSECAPP_SRC_ADDR;
    inline_item[2].item_id = MMI_IPSEC_POLICY_SRC_ADDR_CAP;
    inline_item[2].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[2].image_id = IMG_ID_IPSECAPP_POLICY_SRC_ADDR;
    inline_item[2].item_data = &caption_3;

    ip4_4.b1 = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_addr[0];
    ip4_4.b2 = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_addr[1];
    ip4_4.b3 = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_addr[2];
    ip4_4.b4 = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_addr[3];
    inline_item[3].item_id = MMI_IPSEC_POLICY_SRC_ADDR;
    inline_item[3].item_flag = CUI_INLINE_ITEM_TYPE_IP4;
    inline_item[3].image_id = 0;
    inline_item[3].item_data = &ip4_4;

    caption_5.string_id = STR_ID_IPSECAPP_DEST_PORT;
    inline_item[4].item_id = MMI_IPSEC_POLICY_DEST_PORT_CAP;
    inline_item[4].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[4].image_id = IMG_ID_IPSECAPP_POLICY_DEST_PORT;
    inline_item[4].item_data = &caption_5;

    text_editor_6.string_id = 0;
    text_editor_6.default_text_id = 0;
    text_editor_6.buffer_size = MMI_IPSEC_MAX_PORT_LEN + 1;
    text_editor_6.input_type = IMM_INPUT_TYPE_NUMERIC;
    text_editor_6.input_extended_type = 0;
    text_editor_6.required_input_mode_set = NULL;
    inline_item[5].item_id = MMI_IPSEC_POLICY_DEST_PORT;
    inline_item[5].item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_NO_LEADING_ZERO;
    inline_item[5].image_id = 0;
    inline_item[5].item_data = &text_editor_6;

    caption_7.string_id = STR_ID_IPSECAPP_DEST_ADDR;
    inline_item[6].item_id = MMI_IPSEC_POLICY_DEST_ADDR_CAP;
    inline_item[6].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[6].image_id = IMG_ID_IPSECAPP_POLICY_DEST_ADDR;
    inline_item[6].item_data = &caption_7;

    ip4_8.b1 = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_addr[0];
    ip4_8.b2 = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_addr[1];
    ip4_8.b3 = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_addr[2];
    ip4_8.b4 = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_addr[3];
    inline_item[7].item_id = MMI_IPSEC_POLICY_DEST_ADDR;
    inline_item[7].item_flag = CUI_INLINE_ITEM_TYPE_IP4;
    inline_item[7].image_id = 0;
    inline_item[7].item_data = &ip4_8;

#ifdef __MMI_IPSEC_TUNNEL_MODE__
    g_ipsec_cntx_p->prof_misc.ipsec_mode[MMI_IPSEC_MODE_TUNNEL] = (U8*)GetString(STR_ID_IPSECAPP_TUNNEL_MODE);
    g_ipsec_cntx_p->prof_misc.ipsec_mode[MMI_IPSEC_MODE_TRANSPORT] = (U8*)GetString(STR_ID_IPSECAPP_TRANSPORT_MODE);

    caption_9.string_id = STR_ID_IPSECAPP_IPSEC_MODE;
    inline_item[8].item_id = MMI_IPSEC_POLICY_MODE_CAP;
    inline_item[8].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[8].image_id = IMG_ID_IPSECAPP_POLICY_MODE;
    inline_item[8].item_data = &caption_9;

    select_10.n_items = MMI_IPSEC_MODE_TOTAL_ITEM;
    select_10.highlighted_item = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.ipsec_mode;
    select_10.list_of_item_id = (U16*)g_ipsec_cntx_p->prof_misc.ipsec_mode;
    inline_item[9].item_id = MMI_IPSEC_POLICY_MODE;
    inline_item[9].item_flag = CUI_INLINE_ITEM_TYPE_SELECT;
    inline_item[9].image_id = 0;
    inline_item[9].item_data = &select_10;

    caption_11.string_id = STR_ID_IPSECAPP_TUNNEL_PORT;
    inline_item[10].item_id = MMI_IPSEC_POLICY_TUNNEL_PORT_CAP;
    inline_item[10].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[10].image_id = IMG_ID_IPSECAPP_POLICY_TUNNEL_PORT;
    inline_item[10].item_data = &caption_11;

    text_editor_12.string_id = 0;
    text_editor_12.default_text_id = 0;
    text_editor_12.buffer_size = MMI_IPSEC_MAX_PORT_LEN + 1;
    text_editor_12.input_type = IMM_INPUT_TYPE_NUMERIC;
    text_editor_12.input_extended_type = 0;
    text_editor_12.required_input_mode_set = NULL;
    inline_item[11].item_id = MMI_IPSEC_POLICY_TUNNEL_PORT;
    if (g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.ipsec_mode == MMI_IPSEC_MODE_TRANSPORT)
    {
        inline_item[11].item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_DISABLE | CUI_INLINE_ITEM_NO_LEADING_ZERO;
    }
    else
    {
        inline_item[11].item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_NO_LEADING_ZERO;
    }
    inline_item[11].image_id = 0;
    inline_item[11].item_data = &text_editor_12;

    caption_13.string_id = STR_ID_IPSECAPP_TUNNEL_ADDR;
    inline_item[12].item_id = MMI_IPSEC_POLICY_TUNNEL_ADDR_CAP;
    inline_item[12].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[12].image_id = IMG_ID_IPSECAPP_POLICY_TUNNEL_ADDR;
    inline_item[12].item_data = &caption_13;

    ip4_14.b1 = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.tunnel_addr[0];
    ip4_14.b2 = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.tunnel_addr[1];
    ip4_14.b3 = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.tunnel_addr[2];
    ip4_14.b4 = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.tunnel_addr[3];
    inline_item[13].item_id = MMI_IPSEC_POLICY_TUNNEL_ADDR;
    if (g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.ipsec_mode == MMI_IPSEC_MODE_TRANSPORT)
    {
        inline_item[13].item_flag = CUI_INLINE_ITEM_TYPE_IP4 | CUI_INLINE_ITEM_DISABLE;
    }
    else
    {
        inline_item[13].item_flag = CUI_INLINE_ITEM_TYPE_IP4;
    }
    inline_item[13].image_id = 0;
    inline_item[13].item_data = &ip4_14;
#endif /* __MMI_IPSEC_TUNNEL_MODE__ */
    display_only_15.string_id = STR_ID_IPSECAPP_ALG;
    inline_item[MMI_IPSEC_POLICY_ALG - CUI_INLINE_ITEM_ID_BASE].item_id = MMI_IPSEC_POLICY_ALG;
    inline_item[MMI_IPSEC_POLICY_ALG - CUI_INLINE_ITEM_ID_BASE].item_flag = CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_DISPLAY_NO_RESPONSE_NUMKEY;
    inline_item[MMI_IPSEC_POLICY_ALG - CUI_INLINE_ITEM_ID_BASE].image_id = IMG_ID_IPSECAPP_POLICY_ALG;
    inline_item[MMI_IPSEC_POLICY_ALG - CUI_INLINE_ITEM_ID_BASE].item_data = &display_only_15;

    inline_struct.items_count = (U8)(MMI_IPSEC_POLICY_TOTAL_ITEM - CUI_INLINE_ITEM_ID_BASE);
    inline_struct.title = STR_ID_IPSECAPP_POLICY;
    inline_struct.title_icon = GetRootTitleIcon(MENU_ID_IPSECAPP_SETTINGS);
    inline_struct.screen_flag = CUI_INLINE_SCREEN_LOOP;
    inline_struct.softkey = NULL;
    inline_struct.items = inline_item;
    
    g_ipsec_cntx_p->cui_policy_inline_id = cui_inline_create(GRP_ID_IPSEC, &inline_struct);
    app_ucs2_itoa(
        g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_port, 
        (kal_int8*)set_value_port,
        10);
    cui_inline_set_value(
        g_ipsec_cntx_p->cui_policy_inline_id,
        MMI_IPSEC_POLICY_SRC_PORT,
        set_value_port);
    app_ucs2_itoa(
        g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_port, 
        (kal_int8*)set_value_port,
        10);
    cui_inline_set_value(
        g_ipsec_cntx_p->cui_policy_inline_id,
        MMI_IPSEC_POLICY_DEST_PORT,
        set_value_port);
#ifdef __MMI_IPSEC_TUNNEL_MODE__
    app_ucs2_itoa(
        g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.tunnel_port, 
        (kal_int8*)set_value_port,
        10);
    cui_inline_set_value(
        g_ipsec_cntx_p->cui_policy_inline_id,
        MMI_IPSEC_POLICY_TUNNEL_PORT,
        set_value_port;
#endif /* __MMI_IPSEC_TUNNEL_MODE__ */
    cui_inline_run(g_ipsec_cntx_p->cui_policy_inline_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_policy_inline_proc
 * DESCRIPTION
 *  Entry Authentication setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_policy_inline_proc(mmi_group_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_inline_notify_struct *inline_notify = (cui_event_inline_notify_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_SET_KEY:
        {
            cui_event_inline_set_key_struct *set_key_evt = (cui_event_inline_set_key_struct*)evt;
            if (set_key_evt->item_id == MMI_IPSEC_POLICY_ALG)
            {
                ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);
                ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
                SetLeftSoftkeyFunction(mmi_ipsec_entry_prof_policy_alg, KEY_EVENT_UP);
                SetCenterSoftkeyFunction(mmi_ipsec_entry_prof_policy_alg, KEY_EVENT_UP);
            }
            break;
        }
        
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            mmi_ipsec_save_prof_policy_confirm();
            break;
        }

        case EVT_ID_CUI_INLINE_NOTIFY:
        {
            switch(inline_notify->event_type)
            {
                case CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED:
                {
                #ifdef __MMI_IPSEC_TUNNEL_MODE__
                    S32 index;
                    cui_inline_get_value(evt->sender_id, MMI_IPSEC_POLICY_MODE, &index);
                    if (index == MMI_IPSEC_MODE_TRANSPORT) /* disable tunnel port & addr */
                    {
                        cui_inline_set_item_attributes(
                            evt->sender_id,
                            MMI_IPSEC_POLICY_TUNNEL_PORT,
                            CUI_INLINE_SET_ATTRIBUTE,
                            CUI_INLINE_ITEM_DISABLE);
                        cui_inline_set_item_attributes(
                            evt->sender_id,
                            MMI_IPSEC_POLICY_TUNNEL_ADDR,
                            CUI_INLINE_SET_ATTRIBUTE,
                            CUI_INLINE_ITEM_DISABLE);
                    }
                    else if (index == MMI_IPSEC_MODE_TUNNEL)/* enable tunnel addr & port */
                    {
                        cui_inline_set_item_attributes(
                            evt->sender_id,
                            MMI_IPSEC_POLICY_TUNNEL_PORT,
                            CUI_INLINE_RESET_ATTRIBUTE,
                            CUI_INLINE_ITEM_DISABLE);
                        cui_inline_set_item_attributes(
                            evt->sender_id,
                            MMI_IPSEC_POLICY_TUNNEL_ADDR,
                            CUI_INLINE_RESET_ATTRIBUTE,
                            CUI_INLINE_ITEM_DISABLE);
                    }
                #endif /* __MMI_IPSEC_TUNNEL_MODE__ */
                    break;
                }

                default:
                    break;
            }
            break;
        }

        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        {
            cui_event_inline_common_struct *inline_common_event = (cui_event_inline_common_struct*)evt;

            if (is_ipsec_alg_inline_changed == MMI_TRUE)
            {
                cui_inline_set_screen_attributes(inline_common_event->sender_id, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_SCREEN_CHANGED);
            }   
            break;
        }

        case EVT_ID_CUI_INLINE_ABORT:
            cui_inline_close(evt->sender_id);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_entry_prof_policy_alg
 * DESCRIPTION
 *  Entry Authentication setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_entry_prof_policy_alg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_struct inline_struct = {0};

    cui_inline_item_caption_struct      caption_1;
    cui_inline_item_select_struct       select_2;
    cui_inline_item_caption_struct      caption_3;
    cui_inline_item_select_struct       select_4;
    cui_inline_item_caption_struct      caption_5;
    cui_inline_item_select_struct       select_6;

    cui_inline_set_item_struct inline_item[MMI_IPSEC_ALG_TOTAL_ITEM - CUI_INLINE_ITEM_ID_BASE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ipsec_cntx_p->prof_misc.auth_method[MMI_IPSEC_AUTH_NONE] = STR_GLOBAL_NONE;
    g_ipsec_cntx_p->prof_misc.auth_method[MMI_IPSEC_AUTH_MD5] = STR_ID_IPSECAPP_SELECTION_AUTH_MD5;
    g_ipsec_cntx_p->prof_misc.auth_method[MMI_IPSEC_AUTH_SHA1] = STR_ID_IPSECAPP_SELECTION_AUTH_SHA1;

    g_ipsec_cntx_p->prof_misc.enc_method[MMI_IPSEC_ENC_NONE] = STR_GLOBAL_NONE;
    g_ipsec_cntx_p->prof_misc.enc_method[MMI_IPSEC_ENC_DES] = STR_ID_IPSECAPP_SELECTION_ENC_DES;
    g_ipsec_cntx_p->prof_misc.enc_method[MMI_IPSEC_ENC_3DES] = STR_ID_IPSECAPP_SELECTION_ENC_3DES;
    
    caption_1.string_id = STR_ID_IPSECAPP_ALG_AH_AUTH;
    inline_item[0].item_id = MMI_IPSEC_ALG_AH_AUTH_CAP;
    inline_item[0].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[0].image_id = IMG_ID_IPSECAPP_ALG_AH_AUTH;
    inline_item[0].item_data = &caption_1;

    select_2.n_items = MMI_IPSEC_AUTH_TOTAL_ITEM;
    select_2.highlighted_item = g_ipsec_cntx_p->policy_ike_temp.alg_ah_auth;
    select_2.list_of_item_id = (U16*)g_ipsec_cntx_p->prof_misc.auth_method;
    inline_item[1].item_id = MMI_IPSEC_ALG_AH_AUTH;
    inline_item[1].item_flag = CUI_INLINE_ITEM_TYPE_SELECT;
    inline_item[1].image_id = 0;
    inline_item[1].item_data = &select_2;

    caption_3.string_id = STR_ID_IPSECAPP_ALG_ESP_AUTH;
    inline_item[2].item_id = MMI_IPSEC_ALG_ESP_AUTH_CAP;
    inline_item[2].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[2].image_id = IMG_ID_IPSECAPP_ALG_ESP_AUTH;
    inline_item[2].item_data = &caption_3;

    select_4.n_items = MMI_IPSEC_AUTH_TOTAL_ITEM;
    select_4.highlighted_item = g_ipsec_cntx_p->policy_ike_temp.alg_esp_auth;
    select_4.list_of_item_id = (U16*)g_ipsec_cntx_p->prof_misc.auth_method;
    inline_item[3].item_id = MMI_IPSEC_ALG_ESP_AUTH;
    inline_item[3].item_flag = CUI_INLINE_ITEM_TYPE_SELECT;
    inline_item[3].image_id = 0;
    inline_item[3].item_data = &select_4;

    caption_5.string_id = STR_ID_IPSECAPP_ALG_ESP_ENC;
    inline_item[4].item_id = MMI_IPSEC_ALG_ESP_ENC_CAP;
    inline_item[4].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[4].image_id = IMG_ID_IPSECAPP_ALG_ESP_ENC;
    inline_item[4].item_data = &caption_5;

    select_6.n_items = MMI_IPSEC_ENC_TOTAL_ITEM;
    select_6.highlighted_item = g_ipsec_cntx_p->policy_ike_temp.alg_esp_enc;
    select_6.list_of_item_id = (U16*)g_ipsec_cntx_p->prof_misc.enc_method;
    inline_item[5].item_id = MMI_IPSEC_ALG_ESP_ENC;
    inline_item[5].item_flag = CUI_INLINE_ITEM_TYPE_SELECT;
    inline_item[5].image_id = 0;
    inline_item[5].item_data = &select_6;

    inline_struct.items_count = (U8)(MMI_IPSEC_ALG_TOTAL_ITEM - CUI_INLINE_ITEM_ID_BASE);
    inline_struct.title = STR_ID_IPSECAPP_ALG;
    inline_struct.title_icon = GetRootTitleIcon(MENU_ID_IPSECAPP_SETTINGS);
    inline_struct.screen_flag = CUI_INLINE_SCREEN_LOOP;
    inline_struct.softkey = NULL;
    inline_struct.items = inline_item;
    
    g_ipsec_cntx_p->cui_policy_alg_inline_id = cui_inline_create(GRP_ID_IPSEC, &inline_struct);
    cui_inline_run(g_ipsec_cntx_p->cui_policy_alg_inline_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_policy_alg_inline_proc
 * DESCRIPTION
 *  Entry Authentication setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_policy_alg_inline_proc(mmi_group_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            mmi_ipsec_save_prof_policy_alg();
            break;
        }

        case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_inline_close(evt->sender_id);
            break;
        }

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_entry_prof_ike
 * DESCRIPTION
 *  Entry function of ike settings screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_entry_prof_ike(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_struct inline_struct = {0};

    cui_inline_item_caption_struct          caption_1;
    cui_inline_item_fullscreen_edit_struct  fullscreen_editor_2;
    cui_inline_item_caption_struct          caption_3;
    cui_inline_item_select_struct           select_4;
    cui_inline_item_caption_struct          caption_5;
    cui_inline_item_select_struct           select_6;
    cui_inline_item_caption_struct          caption_7;
    cui_inline_item_select_struct           select_8;

    cui_inline_set_item_struct inline_item[MMI_IPSEC_ALG_TOTAL_ITEM - CUI_INLINE_ITEM_ID_BASE + 2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ipsec_cntx_p->prof_misc.auth_method[MMI_IPSEC_AUTH_NONE] = STR_GLOBAL_NONE;
    g_ipsec_cntx_p->prof_misc.auth_method[MMI_IPSEC_AUTH_MD5] = STR_ID_IPSECAPP_SELECTION_AUTH_MD5;
    g_ipsec_cntx_p->prof_misc.auth_method[MMI_IPSEC_AUTH_SHA1] = STR_ID_IPSECAPP_SELECTION_AUTH_SHA1;

    g_ipsec_cntx_p->prof_misc.enc_method[MMI_IPSEC_ENC_NONE] = STR_GLOBAL_NONE;
    g_ipsec_cntx_p->prof_misc.enc_method[MMI_IPSEC_ENC_DES] = STR_ID_IPSECAPP_SELECTION_ENC_DES;
    g_ipsec_cntx_p->prof_misc.enc_method[MMI_IPSEC_ENC_3DES] = STR_ID_IPSECAPP_SELECTION_ENC_3DES;

    g_ipsec_cntx_p->prof_misc.dh_method[MMI_IPSEC_DH_MODP768] = STR_GLOBAL_LOW;
    g_ipsec_cntx_p->prof_misc.dh_method[MMI_IPSEC_DH_MODP1024] = STR_GLOBAL_MEDIUM;

    caption_1.string_id = STR_ID_IPSECAPP_IKE_PRESHARED_KEY;
    inline_item[0].item_id = MMI_IPSEC_IKE_PRESHARED_KEY_CAP;
    inline_item[0].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[0].image_id = IMG_ID_IPSECAPP_IKE_PRESHARED_KEY;
    inline_item[0].item_data = &caption_1;
    
    fullscreen_editor_2.string_id = 0;
    fullscreen_editor_2.default_text_id = 0;
    fullscreen_editor_2.title = STR_ID_IPSECAPP_IKE_PRESHARED_KEY;
    fullscreen_editor_2.title_icon = GetRootTitleIcon(MENU_ID_IPSECAPP_SETTINGS);
    fullscreen_editor_2.input_extended_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
    fullscreen_editor_2.input_type = IMM_INPUT_TYPE_ASCII_PASSWORD;
    fullscreen_editor_2.buffer_size = MMI_IPSEC_MAX_KEY_LEN + 1;  
    fullscreen_editor_2.required_input_mode_set = NULL;
    inline_item[1].item_id = MMI_IPSEC_IKE_PRESHARED_KEY;
    inline_item[1].item_flag = CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT;
    inline_item[1].image_id = 0;
    inline_item[1].item_data = &fullscreen_editor_2;

    caption_3.string_id = STR_GLOBAL_AUTHENTICATION;
    inline_item[2].item_id = MMI_IPSEC_IKE_AUTH_METHOD_CAP;
    inline_item[2].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[2].image_id = IMG_ID_IPSECAPP_IKE_AUTH_METHOD;
    inline_item[2].item_data = &caption_3;

    select_4.n_items = MMI_IPSEC_AUTH_TOTAL_ITEM - 1;
    select_4.highlighted_item = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.auth_method;
    select_4.list_of_item_id = (U16*)g_ipsec_cntx_p->prof_misc.auth_method;
    inline_item[3].item_id = MMI_IPSEC_IKE_AUTH_METHOD;
    inline_item[3].item_flag = CUI_INLINE_ITEM_TYPE_SELECT;
    inline_item[3].image_id = 0;
    inline_item[3].item_data = &select_4;

    caption_5.string_id = STR_ID_IPSECAPP_IKE_ENC_METHOD;
    inline_item[4].item_id = MMI_IPSEC_IKE_ENC_METHOD_CAP;
    inline_item[4].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[4].image_id = IMG_ID_IPSECAPP_IKE_ENC_METHOD;
    inline_item[4].item_data = &caption_5;

    select_6.n_items = MMI_IPSEC_AUTH_TOTAL_ITEM - 1;
    select_6.highlighted_item = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.enc_method;
    select_6.list_of_item_id = (U16*)g_ipsec_cntx_p->prof_misc.enc_method;
    inline_item[5].item_id = MMI_IPSEC_IKE_ENC_METHOD;
    inline_item[5].item_flag = CUI_INLINE_ITEM_TYPE_SELECT;
    inline_item[5].image_id = 0;
    inline_item[5].item_data = &select_6;

    caption_7.string_id = STR_ID_IPSECAPP_IKE_DH_METHOD;
    inline_item[6].item_id = MMI_IPSEC_IKE_DH_METHOD_CAP;
    inline_item[6].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[6].image_id = IMG_ID_IPSECAPP_IKE_DH_METHOD;
    inline_item[6].item_data = &caption_7;

    select_8.n_items = MMI_IPSEC_DH_TOTAL_ITEM;
    select_8.highlighted_item = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.dh_method;
    select_8.list_of_item_id = (U16*)g_ipsec_cntx_p->prof_misc.dh_method;
    inline_item[7].item_id = MMI_IPSEC_IKE_DH_METHOD;
    inline_item[7].item_flag = CUI_INLINE_ITEM_TYPE_SELECT;
    inline_item[7].image_id = 0;
    inline_item[7].item_data = &select_8;

    inline_struct.items_count = (U8)(MMI_IPSEC_IKE_TOTAL_ITEM - CUI_INLINE_ITEM_ID_BASE);
    inline_struct.title = STR_ID_IPSECAPP_IKE;   
    inline_struct.title_icon = GetRootTitleIcon(MENU_ID_IPSECAPP_SETTINGS);
    inline_struct.screen_flag = CUI_INLINE_SCREEN_LOOP;
    inline_struct.softkey = NULL;
    inline_struct.items = inline_item;
    
    g_ipsec_cntx_p->cui_ike_inline_id = cui_inline_create(GRP_ID_IPSEC, &inline_struct);
    cui_inline_set_value(
        g_ipsec_cntx_p->cui_ike_inline_id,
        MMI_IPSEC_IKE_PRESHARED_KEY,
        &g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.preshared_key);
    cui_inline_run(g_ipsec_cntx_p->cui_ike_inline_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_ike_inline_proc
 * DESCRIPTION
 *  Entry Authentication setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_ike_inline_proc(mmi_group_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_inline_notify_struct *inline_notify = (cui_event_inline_notify_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            mmi_ipsec_save_prof_ike_confirm();
            break;
        }

        case EVT_ID_CUI_INLINE_NOTIFY:
        {
            switch(inline_notify->event_type)
            {
                case CUI_INLINE_NOTIFY_TEXT_NOT_EMPTY:
                {
                    cui_inline_get_value(
                        evt->sender_id,
                        MMI_IPSEC_IKE_PRESHARED_KEY,
                        &g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.preshared_key);
                    break;
                }

                default:
                    break;
            }
            break;
        }

        case EVT_ID_CUI_INLINE_ABORT:
            cui_inline_close(evt->sender_id);
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_entry_prof_rename
 * DESCRIPTION
 *  Rename the profile selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_entry_prof_rename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ipsec_cntx_p->cui_rename_editor_id = cui_fseditor_create(GRP_ID_IPSEC);
    cui_fseditor_set_title(
        g_ipsec_cntx_p->cui_rename_editor_id,
        STR_GLOBAL_RENAME,
        GetRootTitleIcon(MENU_ID_IPSECAPP_SETTINGS));
    cui_fseditor_set_buffer(
        g_ipsec_cntx_p->cui_rename_editor_id,
        rename_prof_name,
        MMI_IPSEC_MAX_PROF_NAME_LEN + 1,
        MMI_IPSEC_MAX_PROF_NAME_LEN);
    cui_fseditor_run(g_ipsec_cntx_p->cui_rename_editor_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_entry_progressing
 * DESCRIPTION
 *  Common entry function for all progressing screens.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_entry_progressing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_IPSEC, 
                        SCR_ID_IPSECAPP_PROF_PROGRESSING,
                        NULL,
                        (FuncPtr)mmi_ipsec_entry_progressing, 
                        MMI_FRM_FULL_SCRN))
    {
        if (g_ipsec_cntx_p->working_status == MMI_IPSEC_STATUS_ACTIVATING)
        {
            ShowCategory66Screen(
                STR_ID_IPSECAPP_PROGRESSING,
                GetRootTitleIcon(MENU_ID_IPSECAPP_SETTINGS),
                0,
                0,
                0,
                0,
                (PU8) GetString(STR_GLOBAL_PLEASE_WAIT),
                mmi_get_event_based_image(MMI_EVENT_PROGRESS),
                NULL);
        }
        else if (g_ipsec_cntx_p->working_status == MMI_IPSEC_STATUS_DEACTIVATING)
        {
            ShowCategory66Screen(
                STR_ID_IPSECAPP_PROGRESSING,
                GetRootTitleIcon(MENU_ID_IPSECAPP_SETTINGS),
                0,
                0,
                0,
                0,
                (PU8) GetString(STR_GLOBAL_PLEASE_WAIT),
                mmi_get_event_based_image(MMI_EVENT_PROGRESS),
                NULL);
        }
    }
}


#define MMI_IPSEC_PROFILE_SAVING
/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_save_prof_policy
 * DESCRIPTION
 *  Save Policy Setting data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_save_prof_policy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_ipsec_policy_struct     policy_storage_buffer;
    S16 error;
    S32 port_num;
    WCHAR get_value_port[MMI_IPSEC_MAX_PORT_LEN + 1];
    cui_inline_item_ip4_struct get_value_ip4;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&(policy_storage_buffer), 0, sizeof(nvram_ef_ipsec_policy_struct));

    /* POLICY WRITING */
    /* source port */
    cui_inline_get_value(
        g_ipsec_cntx_p->cui_policy_inline_id,
        MMI_IPSEC_POLICY_SRC_PORT,
        &get_value_port);
    port_num = gui_atoi(get_value_port);
    if (mmi_ucs2strlen((S8*)get_value_port) == 0)
    {
        mmi_ipsec_show_popup_screen((WCHAR*)GetString(STR_ID_IPSECAPP_PORTNUM_EMPTY), MMI_EVENT_FAILURE);
        return;
    }
    else if ((port_num > MMI_IPSEC_MAX_PORT_NUM) || (port_num <= 0))
    {
        mmi_ipsec_show_popup_screen((WCHAR*)GetString(STR_ID_IPSECAPP_PORTNUM_OUTOF_RANGE), MMI_EVENT_FAILURE);
        return;
    }
    else /* valid port number */
    {
        policy_storage_buffer.src_port = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_port = port_num;
    }

    /* source addr */
    cui_inline_get_value(
        g_ipsec_cntx_p->cui_policy_inline_id,
        MMI_IPSEC_POLICY_SRC_ADDR,
        &get_value_ip4);
    policy_storage_buffer.src_addr[0] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_addr[0] = get_value_ip4.b1;
    policy_storage_buffer.src_addr[1] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_addr[1] = get_value_ip4.b2;
    policy_storage_buffer.src_addr[2] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_addr[2] = get_value_ip4.b3;
    policy_storage_buffer.src_addr[3] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_addr[3] = get_value_ip4.b4;

    /* dest port */
    cui_inline_get_value(
        g_ipsec_cntx_p->cui_policy_inline_id,
        MMI_IPSEC_POLICY_DEST_PORT,
        &get_value_port);
    port_num = gui_atoi(get_value_port);
    if (mmi_ucs2strlen((S8*)get_value_port) == 0)
    {
        mmi_ipsec_show_popup_screen((WCHAR*)GetString(STR_ID_IPSECAPP_PORTNUM_EMPTY), MMI_EVENT_FAILURE);
        return;
    }
    else if ((port_num > MMI_IPSEC_MAX_PORT_NUM) || (port_num <= 0))
    {
        mmi_ipsec_show_popup_screen((WCHAR*)GetString(STR_ID_IPSECAPP_PORTNUM_OUTOF_RANGE), MMI_EVENT_FAILURE);
        return;
    }
    else /* valid port number */
    {
        policy_storage_buffer.dest_port = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_port = (U16)port_num;
    }
    
    /* dest addr */
    cui_inline_get_value(
        g_ipsec_cntx_p->cui_policy_inline_id,
        MMI_IPSEC_POLICY_DEST_ADDR,
        &get_value_ip4);
    policy_storage_buffer.dest_addr[0] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_addr[0] = get_value_ip4.b1;
    policy_storage_buffer.dest_addr[1] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_addr[1] = get_value_ip4.b2;
    policy_storage_buffer.dest_addr[2] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_addr[2] = get_value_ip4.b3;
    policy_storage_buffer.dest_addr[3] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_addr[3] = get_value_ip4.b4;

    /* ipsec mode */
    policy_storage_buffer.ipsec_mode = MMI_IPSEC_MODE_TRANSPORT;
    policy_storage_buffer.tunnel_port = 0;
    policy_storage_buffer.tunnel_addr[0] = 0;
    policy_storage_buffer.tunnel_addr[1] = 0;
    policy_storage_buffer.tunnel_addr[2] = 0;
    policy_storage_buffer.tunnel_addr[3] = 0;
#ifdef __MMI_IPSEC_TUNNEL_MODE__
    /* working on tunnel mode */
    if (g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.ipsec_mode == MMI_IPSEC_MODE_TUNNEL)
    {
        /* tunnel port */
        cui_inline_get_value(
            g_ipsec_cntx_p->cui_policy_inline_id,
            MMI_IPSEC_POLICY_DEST_PORT,
            &get_value_port);
        port_num = gui_atoi(get_value_port);
        if (mmi_ucs2strlen((S8*)get_value_port) == 0)
        {
            mmi_ipsec_show_popup_screen((WCHAR*)GetString(STR_ID_IPSECAPP_PORTNUM_EMPTY), MMI_EVENT_FAILURE);
            return;
        }
        else if ((port_num > MMI_IPSEC_MAX_PORT_NUM) || (port_num <= 0))
        {
            mmi_ipsec_show_popup_screen((WCHAR*)GetString(STR_ID_IPSECAPP_PORTNUM_OUTOF_RANGE), MMI_EVENT_FAILURE);
            return;
        }
        else /* valid port number */
        {
            policy_storage_buffer.tunnel_port = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.tunnel_port = (U16)port_num;
        }

        /* tunnel addr */
        cui_inline_get_value(
            g_ipsec_cntx_p->cui_policy_inline_id,
            MMI_IPSEC_POLICY_TUNNEL_ADDR,
            &get_value_ip4);
        policy_storage_buffer.tunnel_addr[0] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.tunnel_addr[0] = get_value_ip4.b1;
        policy_storage_buffer.tunnel_addr[1] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.tunnel_addr[1] = get_value_ip4.b2;
        policy_storage_buffer.tunnel_addr[2] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.tunnel_addr[2] = get_value_ip4.b3;
        policy_storage_buffer.tunnel_addr[3] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.tunnel_addr[3] = get_value_ip4.b4;
    }
#endif /* __MMI_IPSEC_TUNNEL_MODE__ */

    if (is_ipsec_alg_inline_changed == MMI_TRUE)
    {
        /* AH authentication */
        g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.alg_ah_auth = g_ipsec_cntx_p->policy_ike_temp.alg_ah_auth;

        /* ESP authentication */
        g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.alg_esp_auth = g_ipsec_cntx_p->policy_ike_temp.alg_esp_auth;

        /* ESP encryption */
        g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.alg_esp_enc = g_ipsec_cntx_p->policy_ike_temp.alg_esp_enc;
    }
    
    policy_storage_buffer.alg_ah_auth = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.alg_ah_auth;
    policy_storage_buffer.alg_esp_auth = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.alg_esp_auth;
    policy_storage_buffer.alg_esp_enc = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.alg_esp_enc;

    WriteRecord(NVRAM_EF_IPSEC_POLICY_LID, (U16)(g_ipsec_cntx_p->profile_selected + 1), &policy_storage_buffer, NVRAM_EF_IPSEC_POLICY_SIZE, &error);

    if (error == NVRAM_WRITE_SUCCESS)
    {
        mmi_ipsec_show_popup_screen((WCHAR*)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS);
        if (g_ipsec_cntx_p->activated_index == g_ipsec_cntx_p->profile_selected)
        {
            mmi_ipsec_prof_reactivate();
        }
    }
    cui_inline_close(g_ipsec_cntx_p->cui_policy_inline_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_save_prof_policy_confirm
 * DESCRIPTION
 *  Display confirmation screen for Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_save_prof_policy_confirm(void)
{
    mmi_ipsec_display_confirm(STR_GLOBAL_SAVE_ASK, mmi_ipsec_save_prof_policy, mmi_ipsec_prof_go_back_to_edit_menu);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_save_prof_policy_alg
 * DESCRIPTION
 *  Highlight handler of all common full screen editor.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_save_prof_policy_alg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(
        g_ipsec_cntx_p->cui_policy_alg_inline_id,
        MMI_IPSEC_ALG_AH_AUTH,
        &g_ipsec_cntx_p->policy_ike_temp.alg_ah_auth);
    cui_inline_get_value(
        g_ipsec_cntx_p->cui_policy_alg_inline_id,
        MMI_IPSEC_ALG_ESP_AUTH,
        &g_ipsec_cntx_p->policy_ike_temp.alg_esp_auth);
    cui_inline_get_value(
        g_ipsec_cntx_p->cui_policy_alg_inline_id,
        MMI_IPSEC_ALG_ESP_ENC,
        &g_ipsec_cntx_p->policy_ike_temp.alg_esp_enc);

    if (g_ipsec_cntx_p->policy_ike_temp.alg_ah_auth == MMI_IPSEC_AUTH_NONE &&
        g_ipsec_cntx_p->policy_ike_temp.alg_esp_auth == MMI_IPSEC_AUTH_NONE)
    {
        mmi_ipsec_show_popup_screen((WCHAR*)GetString(STR_ID_IPSECAPP_ALL_OPTIONS_NONE), MMI_EVENT_FAILURE);
    }
    else
    {
        is_ipsec_alg_inline_changed = MMI_TRUE;
        cui_inline_close(g_ipsec_cntx_p->cui_policy_alg_inline_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_save_prof_ike
 * DESCRIPTION
 *  Save Policy Setting data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_save_prof_ike(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_ipsec_ike_struct        ike_storage_buffer;
    S16 error;
    WCHAR                       get_value_preshared_key[MMI_IPSEC_MAX_KEY_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(
        g_ipsec_cntx_p->cui_ike_inline_id,
        MMI_IPSEC_IKE_PRESHARED_KEY,
        &get_value_preshared_key);
    if (mmi_ucs2strlen((S8*)get_value_preshared_key) == 0)
    {
        mmi_ipsec_show_popup_screen((WCHAR*)GetString(STR_ID_IPSECAPP_INPUT_PRE_SHARED_KEY), MMI_EVENT_FAILURE);
        return;
    }

    memset(&(ike_storage_buffer), 0, sizeof(nvram_ef_ipsec_ike_struct));
    /*  IKE WRITING */
    /* Pre-shared key */
    cui_inline_get_value(
        g_ipsec_cntx_p->cui_ike_inline_id,
        MMI_IPSEC_IKE_PRESHARED_KEY,
        &g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.preshared_key);
    mmi_ucs2_to_asc(
        (S8*)ike_storage_buffer.preshared_key,
        (S8*)g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.preshared_key);

    /* Auth method */
    cui_inline_get_value(
        g_ipsec_cntx_p->cui_ike_inline_id,
        MMI_IPSEC_IKE_AUTH_METHOD,
        &g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.auth_method);
    ike_storage_buffer.auth_method = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.auth_method;

    /* Enc method */
    cui_inline_get_value(
        g_ipsec_cntx_p->cui_ike_inline_id,
        MMI_IPSEC_IKE_ENC_METHOD,
        &g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.enc_method);
    ike_storage_buffer.enc_method = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.enc_method;

    /* DH method */
    cui_inline_get_value(
        g_ipsec_cntx_p->cui_ike_inline_id,
        MMI_IPSEC_IKE_DH_METHOD,
        &g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.dh_method);
    ike_storage_buffer.dh_method = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.dh_method;

    WriteRecord(NVRAM_EF_IPSEC_IKE_LID, (U16)(g_ipsec_cntx_p->profile_selected + 1), &ike_storage_buffer, NVRAM_EF_IPSEC_IKE_SIZE, &error);
    if (error == NVRAM_WRITE_SUCCESS)
    {
        mmi_ipsec_show_popup_screen((WCHAR*)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS);
        if (g_ipsec_cntx_p->activated_index == g_ipsec_cntx_p->profile_selected)
        {
            mmi_ipsec_prof_reactivate();
        }
    }
    cui_inline_close(g_ipsec_cntx_p->cui_ike_inline_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_save_prof_ike_confirm
 * DESCRIPTION
 *  Display confirmation screen for Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_save_prof_ike_confirm(void)
{
    mmi_ipsec_display_confirm(STR_GLOBAL_SAVE_ASK, mmi_ipsec_save_prof_ike, mmi_ipsec_prof_go_back_to_edit_menu);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_save_prof_name
 * DESCRIPTION
 *  Save the profile name to nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_save_prof_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_ipsec_profile_name_struct profile_name;
    S16 err = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8 *)rename_prof_name) != 0)
    {
        memcpy(
            g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].prof_name,
            rename_prof_name,
            sizeof(UI_character_type) * (MMI_IPSEC_MAX_PROF_NAME_LEN + 1));
        mmi_ucs2cpy(
            (S8*)profile_name.prof_name,
            (S8*)g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].prof_name);
        WriteRecord(
            NVRAM_EF_IPSEC_PROFILE_NAME_LID, 
            (U16)(g_ipsec_cntx_p->profile_selected + 1), 
            &profile_name,
            sizeof(nvram_ef_ipsec_profile_name_struct), 
            &err);
        if (err == NVRAM_WRITE_SUCCESS)
        {
           mmi_ipsec_show_popup_screen((WCHAR*)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS); 
        }
        cui_fseditor_close(g_ipsec_cntx_p->cui_rename_editor_id);
    }
    else
    {
        mmi_ipsec_show_popup_screen((WCHAR*)GetString(STR_ID_IPSECAPP_PROFILE_NAME_EMPTY), MMI_EVENT_FAILURE);
    }
}


#define MMI_IPSEC_HILITE_HDLR
/*****************************************************************************
 * FUNCTION
 *  HighlightIPSecApp
 * DESCRIPTION
 *  Highlight handler of IPSec Settings Entry.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_hilite_main(void)
{
    SetLeftSoftkeyFunction(mmi_ipsec_launch, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_ipsec_launch, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_hilite_prof_list
 * DESCRIPTION
 *  Highlight handler of Profile list.
 * PARAMETERS
 *  item_index       [IN]        Index of highlighted profile.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_hilite_prof_list(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ipsec_cntx_p->activated == MMI_TRUE &&
        g_ipsec_cntx_p->activated_index == item_index)
    {
        SetCenterSoftkeyFunction(mmi_ipsec_prof_deactivate, KEY_EVENT_UP);
    }
    else
    {
        SetCenterSoftkeyFunction(mmi_ipsec_prof_activate, KEY_EVENT_UP);
    }
    g_ipsec_cntx_p->profile_selected = item_index;
}


#define MMI_IPSEC_MISC
/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_display_confirm
 * DESCRIPTION
 *  Display common confirmation screen.
 * PARAMETERS
 *  strId           [IN]        Confirmation string.
 *  lskFuncs        [IN]        Left soft key function.
 *  rskFuns         [IN]        Right soft key function.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_display_confirm(U16 strId, FuncPtr lskFuncs, FuncPtr rskFuns)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_IPSEC, 
                        GLOBAL_SCR_DUMMY,
                        NULL,
                        (FuncPtr)NULL, 
                        MMI_FRM_FULL_SCRN))
    {
        ShowCategory164Screen(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            strId,
            mmi_get_event_based_image(MMI_EVENT_QUERY),
            NULL);

        srv_prof_play_tone(SRV_PROF_TONE_NONE, NULL);
        SetLeftSoftkeyFunction(lskFuncs, KEY_EVENT_UP);
        SetRightSoftkeyFunction(rskFuns, KEY_EVENT_UP);
        
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(lskFuncs, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_prof_go_back_to_edit_menu
 * DESCRIPTION
 *  Delete all screen after Profile -> Edit screen and go back to Edit screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_prof_go_back_to_edit_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_close(g_ipsec_cntx_p->cui_policy_inline_id);
    cui_inline_close(g_ipsec_cntx_p->cui_ike_inline_id);
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_show_popup_screen
 * DESCRIPTION
 *  The general popup function
 * PARAMETERS
 *  string    [IN] the string of the popup
 *  event_id  [IN] the type of the popup 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_show_popup_screen(WCHAR* string, mmi_event_notify_enum event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple((WCHAR*)string, event_id, GRP_ID_IPSEC, NULL);
}


#define MMI_IPSEC_PS_RELATED
/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_prof_activate
 * DESCRIPTION
 *  Activate the profile selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_prof_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ipsec_read_prof_policy();
    mmi_ipsec_read_prof_ike();
#ifndef __MTK_TARGET__
    mmi_ipsec_show_popup_screen((WCHAR*)GetString(STR_GLOBAL_NOT_SUPPORT_AT_PC_SIMULATOR), MMI_EVENT_FAILURE);
    return;
#else /* __MTK_TARGET__ */
    g_ipsec_cntx_p->working_status = MMI_IPSEC_STATUS_ACTIVATING;
    if (g_ipsec_cntx_p->activated)
    {
        mmi_ipsec_entry_progressing();
        mmi_ipsec_deactivate_req();
    }
    else /* No account activated */
    {
        mmi_ipsec_entry_progressing();
        mmi_ipsec_init_req();
    }
#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_prof_reactivate
 * DESCRIPTION
 *  Reactivate the activated profile after been edited.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_prof_reactivate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    g_ipsec_cntx_p->working_status = MMI_IPSEC_STATUS_ACTIVATING;
    mmi_ipsec_deactivate_req();
#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_prof_deactivate
 * DESCRIPTION
 *  Deactivate the profile selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_prof_deactivate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
    mmi_ipsec_show_popup_screen((WCHAR*)GetString(STR_GLOBAL_NOT_SUPPORT_AT_PC_SIMULATOR), MMI_EVENT_FAILURE);
    return;
#else /* __MTK_TARGET__ */
    g_ipsec_cntx_p->working_status = MMI_IPSEC_STATUS_DEACTIVATING;
    if (g_ipsec_cntx_p->activated)
    {
        mmi_ipsec_entry_progressing();
        mmi_ipsec_deactivate_req();
    }
#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_init_req
 * DESCRIPTION
 *  send initializing request to IPSEC MODEL
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_init_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_kmp_init_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = OslAllocDataPtr(app_kmp_init_req_struct);

    msgReq->proto = MMI_RCT_KMP_IKEV1;
    msgReq->kmp_id = 1;
    msgReq->need_pfs = KAL_FALSE;
    msgReq->init_kmp = MMI_RCT_KMP_IKEV1;
    msgReq->sa_lifetime_byte = MMI_IPSEC_DEFAULT_SA_LIFETIME_BYTE;
    msgReq->sa_lifetime_time = MMI_IPSEC_DEFAULT_LIFETIME_SEC;
    msgReq->send_cert = KAL_FALSE;
    msgReq->send_cert_req = KAL_FALSE;

    mmi_frm_send_ilm(
        MOD_KMP_APP,
        PRT_MMI_IPSEC_INIT_REQ,
        (oslParaType*)msgReq,
        NULL);
    SetProtocolEventHandler(mmi_ipsec_init_rsp, PRT_MMI_IPSEC_INIT_RSP);
#ifdef MMI_IPSEC_UT
    mmi_ipsec_send_test_request(PRT_MMI_IPSEC_INIT_RSP);
#endif /* MMI_IPSEC_UT */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_init_rsp
 * DESCRIPTION
 *  Response handler corresponding to mmi_ipsec_init_req
 * PARAMETERS
 *  void
 * RETURNS
 *  info        [IN]        Data of response
 *****************************************************************************/
void mmi_ipsec_init_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_kmp_init_cnf_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (app_kmp_init_cnf_struct*)info;

    ClearProtocolEventHandler(PRT_MMI_IPSEC_INIT_RSP);

    if (msgRsp->result == MMI_TRUE)
    {
        if (g_ipsec_cntx_p->working_status == MMI_IPSEC_STATUS_ACTIVATING)
        {
            mmi_ipsec_alg_req();
        }
    }
    else
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_IPSECAPP_PROF_PROGRESSING)
        {
            mmi_ipsec_show_popup_screen((WCHAR*)GetString(STR_GLOBAL_UNFINISHED), MMI_EVENT_FAILURE);
        }
        mmi_frm_scrn_close(GRP_ID_IPSEC, SCR_ID_IPSECAPP_PROF_PROGRESSING);
    }
}

    
/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_alg_req
 * DESCRIPTION
 *  send algorithm request to IPSEC MODEL
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_alg_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_kmp_alg_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = OslAllocDataPtr(app_kmp_alg_req_struct);

    msgReq->kmp_id = 1;
    msgReq->kmp_cnt = 1;
    msgReq->proto = MMI_RCT_KMP_IKEV1;
    
    /* perfect forward secrecy, not used here */
    msgReq->alg_req[0].prf_alg.alg_type = MMI_RCT_ALG_SHA1;
    msgReq->alg_req[0].prf_alg.key_len = 0;

    /* Pre-shared Key */    
    /* Read from NVRAM */
    msgReq->alg_req[0].auth_method.alg_type = MMI_RCT_ALG_PSK;
    msgReq->alg_req[0].auth_method.key_len = mmi_ucs2strlen((S8*)g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.preshared_key);
    mmi_ucs2_to_asc((S8*)msgReq->alg_req[0].auth_method.key, (S8*)g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.preshared_key);
    
    /* Hash Method */
    if (g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.auth_method == MMI_IPSEC_AUTH_NONE)
    {
        msgReq->alg_req[0].hash_alg.alg_type = MMI_RCT_ALG_NON_AUTH;
	    msgReq->alg_req[0].hash_alg.key_len = 0;
    }
    else if (g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.auth_method == MMI_IPSEC_AUTH_MD5)
    {
        msgReq->alg_req[0].hash_alg.alg_type = MMI_RCT_ALG_MD5;
	    msgReq->alg_req[0].hash_alg.key_len = 0;
    }
    else if (g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.auth_method == MMI_IPSEC_AUTH_SHA1)
    {
        msgReq->alg_req[0].hash_alg.alg_type = MMI_RCT_ALG_SHA1;
	    msgReq->alg_req[0].hash_alg.key_len = 0;
    }

    /* Encryption Method */
    if (g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.enc_method == MMI_IPSEC_ENC_NONE)
    {
        msgReq->alg_req[0].enc_alg.alg_type = MMI_RCT_ALG_NULL_ENC;
		msgReq->alg_req[0].enc_alg.key_len = 0;
    }
    else if (g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.enc_method == MMI_IPSEC_ENC_DES)
    {
        /*msgReq->alg_req[0].auth_method.alg_type = MMI_RCT_ALG_DES_CBC;*/
		msgReq->alg_req[0].enc_alg.alg_type = MMI_RCT_ALG_DES_CBC;
		msgReq->alg_req[0].enc_alg.key_len = 0;
    }
    else if (g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.enc_method == MMI_IPSEC_ENC_3DES)
    {
       /* msgReq->alg_req[0].auth_method.alg_type = MMI_RCT_ALG_DES3_CBC;*/
		msgReq->alg_req[0].enc_alg.alg_type = MMI_RCT_ALG_DES3_CBC;
		msgReq->alg_req[0].enc_alg.key_len = 0;
    }

    /* Diffie-Hellman Group */
    if (g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.dh_method == MMI_IPSEC_DH_MODP768)
    {
        msgReq->alg_req[0].dh_group.alg_type = MMI_RCT_ALG_MODP768;
		msgReq->alg_req[0].dh_group.key_len = MMI_IPSEC_DEFAULT_DHGROUP_LEN;
    }
    else if (g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].ike_settings.dh_method == MMI_IPSEC_DH_MODP1024)
    {
        msgReq->alg_req[0].dh_group.alg_type = MMI_RCT_ALG_MODP1024;
        msgReq->alg_req[0].dh_group.key_len = MMI_IPSEC_DEFAULT_DHGROUP_LEN;
    }
  
    mmi_frm_send_ilm(
        MOD_KMP_APP,
        PRT_MMI_IPSEC_ALG_REQ,
        (oslParaType*)msgReq,
        NULL);

    SetProtocolEventHandler(mmi_ipsec_alg_rsp, PRT_MMI_IPSEC_ALG_RSP);
#ifdef MMI_IPSEC_UT
    mmi_ipsec_send_test_request(PRT_MMI_IPSEC_ALG_RSP);
#endif /* MMI_IPSEC_UT */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_alg_rsp
 * DESCRIPTION
 *  Response handler corresponding to mmi_ipsec_alg_req
 * PARAMETERS
 *  void
 * RETURNS
 *  info        [IN]        Data of response
 *****************************************************************************/
void mmi_ipsec_alg_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_kmp_alg_cnf_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (app_kmp_alg_cnf_struct*)info;

    ClearProtocolEventHandler(PRT_MMI_IPSEC_ALG_RSP);

    if (msgRsp->result == MMI_TRUE)
    {
        if (g_ipsec_cntx_p->working_status == MMI_IPSEC_STATUS_ACTIVATING)
        {
            mmi_ipsec_addr_req();
        }
    }
    else
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_IPSECAPP_PROF_PROGRESSING)
        {
            mmi_ipsec_show_popup_screen((WCHAR*)GetString(STR_GLOBAL_UNFINISHED), MMI_EVENT_FAILURE);
        }
        mmi_frm_scrn_close(GRP_ID_IPSEC, SCR_ID_IPSECAPP_PROF_PROGRESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_addr_req
 * DESCRIPTION
 *  send initializing request to IPSEC MODEL
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_addr_req(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_kmp_addr_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = OslAllocDataPtr(app_kmp_addr_req_struct);
    msgReq->kmp_id = 1;

    msgReq->proto = MMI_RCT_KMP_IKEV1;

    msgReq->peers_ipaddr.type = MMI_RCT_ADDR_INET;
    msgReq->peers_ipaddr.prefix_len = MMI_IPSEC_DEFAULT_PREFIX_LEN;
    msgReq->peers_ipaddr.addr.ipaddr.sa_family = MMI_IPSEC_AF_INET;
    msgReq->peers_ipaddr.addr.ipaddr.sa_len = sizeof(struct sockaddr);
    
    *(U16*)(msgReq->peers_ipaddr.addr.ipaddr.sa_data) = soc_htons(MMI_IPSEC_DEFAULT_SA_DATA);
    msgReq->peers_ipaddr.addr.ipaddr.sa_data[2] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_addr[0];
    msgReq->peers_ipaddr.addr.ipaddr.sa_data[3] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_addr[1];
    msgReq->peers_ipaddr.addr.ipaddr.sa_data[4] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_addr[2];
    msgReq->peers_ipaddr.addr.ipaddr.sa_data[5] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_addr[3];
    
    msgReq->peers_id.id_type = MMI_RCT_IDT_IPADDR;
    msgReq->peers_id.id_len = MMI_IPSEC_DEFAULT_PREFIX_LEN;
    msgReq->peers_id.id[0] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_addr[0];
    msgReq->peers_id.id[1] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_addr[1];
    msgReq->peers_id.id[2] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_addr[2];
    msgReq->peers_id.id[3] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_addr[3];
    
    msgReq->my_id.id_type = MMI_RCT_IDT_IPADDR;
    msgReq->my_id.id_len = MMI_IPSEC_DEFAULT_PREFIX_LEN;
    msgReq->my_id.id[0] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_addr[0];
    msgReq->my_id.id[1] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_addr[1];
    msgReq->my_id.id[2] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_addr[2];
    msgReq->my_id.id[3] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_addr[3];
    
    msgReq->my_pubkey.pub_len = MMI_IPSEC_DEFAULT_PKEY_LEN;
    msgReq->my_pubkey.priv_len = MMI_IPSEC_DEFAULT_PKEY_LEN;
    
    msgReq->peers_pubkey.pub_len = MMI_IPSEC_DEFAULT_PKEY_LEN;
    msgReq->peers_pubkey.priv_len = MMI_IPSEC_DEFAULT_PKEY_LEN;
    
    mmi_frm_send_ilm(
        MOD_KMP_APP,
        PRT_MMI_IPSEC_ADDR_REQ,
        (oslParaType*)msgReq,
        NULL);

    SetProtocolEventHandler(mmi_ipsec_addr_rsp, PRT_MMI_IPSEC_ADDR_RSP);
#ifdef MMI_IPSEC_UT
    mmi_ipsec_send_test_request(PRT_MMI_IPSEC_ADDR_RSP);
#endif /* MMI_IPSEC_UT */

#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_addr_rsp
 * DESCRIPTION
 *  Response handler corresponding to mmi_ipsec_addr_req
 * PARAMETERS
 *  void
 * RETURNS
 *  info        [IN]        Data of response
 *****************************************************************************/
void mmi_ipsec_addr_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_kmp_addr_cnf_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (app_kmp_addr_cnf_struct*)info;

    ClearProtocolEventHandler(PRT_MMI_IPSEC_ADDR_RSP);

    if (msgRsp->result == MMI_TRUE)
    {
        if (g_ipsec_cntx_p->working_status == MMI_IPSEC_STATUS_ACTIVATING)
        {
            mmi_ipsec_activate_req();
        }
    }
    else
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_IPSECAPP_PROF_PROGRESSING)
        {
            mmi_ipsec_show_popup_screen((WCHAR*)GetString(STR_GLOBAL_UNFINISHED), MMI_EVENT_FAILURE);
        }
        mmi_frm_scrn_close(GRP_ID_IPSEC, SCR_ID_IPSECAPP_PROF_PROGRESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_activate_req
 * DESCRIPTION
 *  send activating request to IPSEC MODEL
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_activate_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_kmp_active_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = OslAllocDataPtr(app_kmp_active_req_struct);

    msgReq->kmp_id = 1;

    mmi_frm_send_ilm(
        MOD_KMP_APP,
        PRT_MMI_IPSEC_ACTIVATE_REQ,
        (oslParaType*)msgReq,
        NULL);

    SetProtocolEventHandler(mmi_ipsec_activate_rsp, PRT_MMI_IPSEC_ACTIVATE_RSP);
#ifdef MMI_IPSEC_UT
    mmi_ipsec_send_test_request(PRT_MMI_IPSEC_ACTIVATE_RSP);
#endif /* MMI_IPSEC_UT */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_activate_rsp
 * DESCRIPTION
 *  Response handler corresponding to mmi_ipsec_activate_req
 * PARAMETERS
 *  void
 * RETURNS
 *  info        [IN]        Data of response
 *****************************************************************************/
void mmi_ipsec_activate_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_kmp_active_cnf_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (app_kmp_active_cnf_struct*)info;

    ClearProtocolEventHandler(PRT_MMI_IPSEC_ACTIVATE_RSP);

    if (msgRsp->result == MMI_TRUE)
    {
        if (g_ipsec_cntx_p->working_status == MMI_IPSEC_STATUS_ACTIVATING)
        {
            mmi_ipsec_policy_req();
        }
    }
    else
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_IPSECAPP_PROF_PROGRESSING)
        {
            mmi_ipsec_show_popup_screen((WCHAR*)GetString(STR_GLOBAL_UNFINISHED), MMI_EVENT_FAILURE);
        }
        mmi_frm_scrn_close(GRP_ID_IPSEC, SCR_ID_IPSECAPP_PROF_PROGRESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_policy_req
 * DESCRIPTION
 *  send deactivating request to IPSEC MODEL
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_policy_req(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_kmp_policy_add_req_struct *msgReq;
	U16 temp_port = 0;
	U8* temp_ptr = NULL;

    S32 sa_support = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = OslAllocDataPtr(app_kmp_policy_add_req_struct);

    /* kmp_id */
    msgReq->kmp_id = 1;
    
    /* order */
    msgReq->order = 0;

    /* direction */
    msgReq->direction = MMI_RCT_DIR_OUTBOUND;

    /* source addr */
    msgReq->src.type = MMI_RCT_ADDR_INET;
    msgReq->src.prefix_len = MMI_IPSEC_DEFAULT_PREFIX_LEN;
    msgReq->src.addr.ipaddr.sa_family = MMI_IPSEC_AF_INET;
    msgReq->src.addr.ipaddr.sa_len = sizeof(struct sockaddr);
    temp_port = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_port;
    temp_ptr = (U8*)(&temp_port);
    msgReq->src.addr.ipaddr.sa_data[0] = *(temp_ptr + 1);
    msgReq->src.addr.ipaddr.sa_data[1] = *temp_ptr;
    msgReq->src.addr.ipaddr.sa_data[2] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_addr[0];
    msgReq->src.addr.ipaddr.sa_data[3] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_addr[1];
    msgReq->src.addr.ipaddr.sa_data[4] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_addr[2];
    msgReq->src.addr.ipaddr.sa_data[5] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_addr[3];

    /* dest addr */
    msgReq->dst.type = MMI_RCT_ADDR_INET;
    msgReq->dst.prefix_len = MMI_IPSEC_DEFAULT_PREFIX_LEN;
    msgReq->dst.addr.ipaddr.sa_family = MMI_IPSEC_AF_INET;
    msgReq->dst.addr.ipaddr.sa_len = sizeof(struct sockaddr);
    temp_port = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_port;
    temp_ptr = (U8*)(&temp_port);
    msgReq->dst.addr.ipaddr.sa_data[0] = *(temp_ptr + 1);
    msgReq->dst.addr.ipaddr.sa_data[1] = *temp_ptr;
    msgReq->dst.addr.ipaddr.sa_data[2] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_addr[0];
    msgReq->dst.addr.ipaddr.sa_data[3] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_addr[1];
    msgReq->dst.addr.ipaddr.sa_data[4] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_addr[2];
    msgReq->dst.addr.ipaddr.sa_data[5] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.dest_addr[3];

    msgReq->upper_protocol = MMI_IPSEC_DEFAULT_PROTOCOL;

    /* req_id */
    msgReq->req_id = 0;

    /* action  */
    msgReq->action = MMI_RCT_ACT_AUTO_IPSEC;

    msgReq->ipsec_mode = MMI_RCT_IPSM_TRANSPORT;
    /* IPSec Mode */
    if (g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.ipsec_mode == MMI_IPSEC_MODE_TUNNEL)
    {
        msgReq->ipsec_mode = MMI_RCT_IPSM_TUNNEL;
    }
    else if (g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.ipsec_mode == MMI_IPSEC_MODE_TRANSPORT)
    {
        msgReq->ipsec_mode = MMI_RCT_IPSM_TRANSPORT;
    }
    
    /* IPSec Level */
    msgReq->ipsec_level = MMI_RCT_IPSL_UNIQUE;

    /* my_sa_ipaddr */
    msgReq->my_sa_ipaddr.type = MMI_RCT_ADDR_INET;
    msgReq->my_sa_ipaddr.prefix_len = MMI_IPSEC_DEFAULT_PREFIX_LEN;
    msgReq->my_sa_ipaddr.addr.ipaddr.sa_family = MMI_IPSEC_AF_INET;
    msgReq->my_sa_ipaddr.addr.ipaddr.sa_len = sizeof(struct sockaddr);
    temp_port = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_port;
    temp_ptr = (U8*)(&temp_port);
    msgReq->my_sa_ipaddr.addr.ipaddr.sa_data[0] = *temp_ptr;
    msgReq->my_sa_ipaddr.addr.ipaddr.sa_data[1] = *(temp_ptr + 1);
    msgReq->my_sa_ipaddr.addr.ipaddr.sa_data[2] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_addr[0];
    msgReq->my_sa_ipaddr.addr.ipaddr.sa_data[3] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_addr[1];
    msgReq->my_sa_ipaddr.addr.ipaddr.sa_data[4] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_addr[2];
    msgReq->my_sa_ipaddr.addr.ipaddr.sa_data[5] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.src_addr[3];

    /* peer SA ipaddr */
    msgReq->peers_sa_ipaddr.type = MMI_RCT_ADDR_INET;
    msgReq->peers_sa_ipaddr.prefix_len = MMI_IPSEC_DEFAULT_PREFIX_LEN;
    msgReq->peers_sa_ipaddr.addr.ipaddr.sa_family = MMI_IPSEC_AF_INET;
    msgReq->peers_sa_ipaddr.addr.ipaddr.sa_len = sizeof(struct sockaddr);
    temp_port = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.tunnel_port;
    temp_ptr = (U8*)(&temp_port);
    msgReq->peers_sa_ipaddr.addr.ipaddr.sa_data[0] = *temp_ptr;
    msgReq->peers_sa_ipaddr.addr.ipaddr.sa_data[1] = *(temp_ptr + 1);
    msgReq->peers_sa_ipaddr.addr.ipaddr.sa_data[2] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.tunnel_addr[0];
    msgReq->peers_sa_ipaddr.addr.ipaddr.sa_data[3] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.tunnel_addr[1];
    msgReq->peers_sa_ipaddr.addr.ipaddr.sa_data[4] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.tunnel_addr[2];
    msgReq->peers_sa_ipaddr.addr.ipaddr.sa_data[5] = g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.tunnel_addr[3];

    /* lifetime: time */
    msgReq->lifetime_time = MMI_IPSEC_DEFAULT_LIFETIME_SEC;

    /* lifetime: byte */
    msgReq->lifetime_byte = MMI_IPSEC_DEFAULT_LIFETIME_BYTE;

    /* ext sequence */
    msgReq->ext_sequence = KAL_FALSE;

    /* sa_support */
    if (msgReq->ipsec_mode == MMI_RCT_IPSM_TUNNEL)
    {
        msgReq->sa_support = 1;
    }
    else
    {
        msgReq->sa_support = 0;
    }

#if 1
    /* SA-AH */
    msgReq->sa_ah.sa_protocol = MMI_RCT_BOOL_ON;
    if (g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.alg_ah_auth == MMI_IPSEC_AUTH_NONE)
    {
        msgReq->sa_ah.auth_alg.alg_type = MMI_RCT_ALG_NON_AUTH;
        msgReq->sa_ah.auth_alg.key_len = 0;
    }
    else if (g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.alg_ah_auth == MMI_IPSEC_AUTH_MD5)
    {
        msgReq->sa_ah.auth_alg.alg_type = MMI_RCT_ALG_HMAC_MD5;
        msgReq->sa_ah.auth_alg.key_len = 0;
    }
    else if (g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.alg_ah_auth == MMI_IPSEC_AUTH_SHA1)
    {
        msgReq->sa_ah.auth_alg.alg_type = MMI_RCT_ALG_HMAC_SHA1;
        msgReq->sa_ah.auth_alg.key_len = 0;
    }

    if (msgReq->sa_ah.auth_alg.alg_type != MMI_RCT_ALG_NON_AUTH)
    {
        msgReq->sa_ah.sa_protocol = MMI_RCT_SATYPE_AH;
    }

    memset(msgReq->sa_ah.auth_alg.key, 0, MMI_IPSEC_MAX_KEY_LEN);
    msgReq->sa_ah.enc_alg.alg_type = MMI_RCT_BOOL_ON;  /* Enc */
    msgReq->sa_ah.enc_alg.key_len = 0;
    memset(msgReq->sa_ah.enc_alg.key, 0, MMI_IPSEC_MAX_KEY_LEN);
    msgReq->sa_ah.spi = 0;

    
    /* SA-ESP */
    sa_support = 0;
    msgReq->sa_esp.sa_protocol = MMI_RCT_BOOL_ON;
    if (g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.alg_esp_auth == MMI_IPSEC_AUTH_NONE) /* Auth */
    {
        msgReq->sa_esp.auth_alg.alg_type = MMI_RCT_ALG_NON_AUTH;
        msgReq->sa_esp.auth_alg.key_len = 0;
    }
    else if (g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.alg_esp_auth == MMI_IPSEC_AUTH_MD5)
    {
        msgReq->sa_esp.auth_alg.alg_type = MMI_RCT_ALG_HMAC_MD5;
        msgReq->sa_esp.auth_alg.key_len = 0;
        sa_support = 1;
    }
    else if (g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.alg_esp_auth == MMI_IPSEC_AUTH_SHA1)
    {
        msgReq->sa_esp.auth_alg.alg_type = MMI_RCT_ALG_HMAC_SHA1;
        msgReq->sa_esp.auth_alg.key_len = 0;
        sa_support = 1;
    }
    memset(msgReq->sa_esp.auth_alg.key, 0, MMI_IPSEC_MAX_KEY_LEN);
    
    if (g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.alg_esp_enc == MMI_IPSEC_ENC_NONE)   /* Enc */
    {
        msgReq->sa_esp.enc_alg.alg_type = MMI_RCT_ALG_NULL_ENC;
        msgReq->sa_esp.enc_alg.key_len = 0;
    }
    else if (g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.alg_esp_enc == MMI_IPSEC_ENC_DES)
    {
        msgReq->sa_esp.enc_alg.alg_type = MMI_RCT_ALG_DES_CBC;
        msgReq->sa_esp.enc_alg.key_len = 0;
        sa_support = 1;
    }
    else if (g_ipsec_cntx_p->profiles[g_ipsec_cntx_p->profile_selected].policy_settings.alg_esp_enc == MMI_IPSEC_ENC_3DES)
    {
        msgReq->sa_esp.enc_alg.alg_type = MMI_RCT_ALG_DES3_CBC;
        msgReq->sa_esp.enc_alg.key_len = 0;
        sa_support = 1;
    }
    memset(msgReq->sa_esp.enc_alg.key, 0, MMI_IPSEC_MAX_KEY_LEN);
    
    if (sa_support)
    {
        msgReq->sa_esp.sa_protocol = MMI_RCT_SATYPE_ESP;
    }

    msgReq->sa_support = 0;

    if (msgReq->sa_ah.sa_protocol && msgReq->sa_esp.sa_protocol)
    {
        msgReq->sa_support = MMI_RCT_SATYPE_AH_ESP;    /* Added by huiyong for test */
    }
    else if (msgReq->sa_ah.sa_protocol)
    {
        msgReq->sa_support = MMI_RCT_SATYPE_AH;    /* Added by huiyong for test */
    } 
    else if (msgReq->sa_esp.sa_protocol)
    {
        msgReq->sa_support = MMI_RCT_SATYPE_ESP;   /* Added by huiyong for test */
    }    

#endif

    /* MESSAGE parameters */
    SetProtocolEventHandler(mmi_ipsec_policy_rsp, PRT_MMI_IPSEC_ADD_POLICY_RSP);

    mmi_frm_send_ilm(
        MOD_KMP_APP,
        PRT_MMI_IPSEC_ADD_POLICY_REQ,
        (oslParaType*)msgReq,
        NULL);
    mmi_frm_send_ilm(
        MOD_KMP_APP,
        PRT_MMI_IPSEC_SETTING_OK_REQ,
        NULL,
        NULL);

#ifdef MMI_IPSEC_UT
    mmi_ipsec_send_test_request(PRT_MMI_IPSEC_ADD_POLICY_RSP);
#endif /* MMI_IPSEC_UT */

#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_policy_rsp
 * DESCRIPTION
 *  Response handler corresponding to mmi_ipsec_policy_req
 * PARAMETERS
 *  void
 * RETURNS
 *  info        [IN]        Data of response
 *****************************************************************************/
void mmi_ipsec_policy_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_kmp_policy_add_cnf_struct *msgRsp;
    U8 activated, act_index;
    S16 err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (app_kmp_policy_add_cnf_struct*)info;

    ClearProtocolEventHandler(PRT_MMI_IPSEC_ADD_POLICY_RSP);

    if (msgRsp->result == MMI_TRUE)
    {
        if (g_ipsec_cntx_p->working_status == MMI_IPSEC_STATUS_ACTIVATING)
        {
            mmi_frm_scrn_close(GRP_ID_IPSEC, SCR_ID_IPSECAPP_PFOF_LIST_OPT);
            mmi_frm_scrn_close(GRP_ID_IPSEC, SCR_ID_IPSECAPP_PROF_PROGRESSING);
            if (mmi_frm_group_get_active_id() == GRP_ID_IPSEC)
            {
                mmi_ipsec_show_popup_screen((WCHAR*)GetString(STR_GLOBAL_ACTIVATED), MMI_EVENT_SUCCESS);
            }

            g_ipsec_cntx_p->activated = MMI_TRUE;
            g_ipsec_cntx_p->activated_index = g_ipsec_cntx_p->profile_selected;
            g_ipsec_cntx_p->working_status = MMI_IPSEC_STATUS_LOCALSETTINGS;

            activated = g_ipsec_cntx_p->activated;
            act_index = g_ipsec_cntx_p->activated_index;
            WriteValue(NVRAM_IPSEC_ACTIVATE_ON_START, &activated, DS_BYTE, &err);
            WriteValue(NVRAM_IPSEC_ACTIVATE_PROF_INDEX, &act_index, DS_BYTE, &err);
        }
    }
    else
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_IPSECAPP_PROF_PROGRESSING)
        {
            mmi_ipsec_show_popup_screen((WCHAR*)GetString(STR_GLOBAL_UNFINISHED), MMI_EVENT_FAILURE);
        }
        mmi_frm_scrn_close(GRP_ID_IPSEC, SCR_ID_IPSECAPP_PROF_PROGRESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_deactivate_req
 * DESCRIPTION
 *  send deactivating request to IPSEC MODEL
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_deactivate_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_kmp_deactive_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = OslAllocDataPtr(app_kmp_deactive_req_struct);

    msgReq->kmp_id = 1;
    mmi_frm_send_ilm(
        MOD_KMP_APP,
        PRT_MMI_IPSEC_DEACTIVATE_REQ,
        (oslParaType*)msgReq,
        NULL);

    SetProtocolEventHandler(mmi_ipsec_deactivate_rsp, PRT_MMI_IPSEC_DEACTIVATE_RSP);
#ifdef MMI_IPSEC_UT
    mmi_ipsec_send_test_request(PRT_MMI_IPSEC_DEACTIVATE_RSP); /* only for test */
#endif /* MMI_IPSEC_UT */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_deactivate_rsp
 * DESCRIPTION
 *  Response handler corresponding to mmi_ipsec_deactivate_req
 * PARAMETERS
 *  void
 * RETURNS
 *  info        [IN]        Data of response
 *****************************************************************************/
void mmi_ipsec_deactivate_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_kmp_deactive_cnf_struct *msgRsp;
    S16 err;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (app_kmp_deactive_cnf_struct*)info;

    ClearProtocolEventHandler(PRT_MMI_IPSEC_DEACTIVATE_RSP);

    if (msgRsp->result == MMI_TRUE)
    {
        if (g_ipsec_cntx_p->working_status == MMI_IPSEC_STATUS_ACTIVATING)
        {
            mmi_ipsec_init_req();
        }
        else if (g_ipsec_cntx_p->working_status == MMI_IPSEC_STATUS_DEACTIVATING)
        {
            if (mmi_frm_scrn_get_active_id() == SCR_ID_IPSECAPP_PROF_PROGRESSING)
            {
                mmi_ipsec_show_popup_screen((WCHAR*)GetString(STR_ID_IPSECAPP_DEACTIVATED), MMI_EVENT_SUCCESS);
            }
            mmi_frm_scrn_close(GRP_ID_IPSEC, SCR_ID_IPSECAPP_PFOF_LIST_OPT);
            mmi_frm_scrn_close(GRP_ID_IPSEC, SCR_ID_IPSECAPP_PROF_PROGRESSING);
            g_ipsec_cntx_p->activated = MMI_FALSE;
            g_ipsec_cntx_p->activated_index = MMI_IPSEC_MAX_PROFILE_NUM;
            g_ipsec_cntx_p->working_status = MMI_IPSEC_STATUS_LOCALSETTINGS;

            WriteValue(NVRAM_IPSEC_ACTIVATE_ON_START, &g_ipsec_cntx_p->activated, DS_BYTE, &err);
            WriteValue(NVRAM_IPSEC_ACTIVATE_PROF_INDEX, &g_ipsec_cntx_p->activated_index, DS_BYTE, &err);
        }
    }
    else
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_IPSECAPP_PROF_PROGRESSING)
        {
            mmi_ipsec_show_popup_screen((WCHAR*)GetString(STR_GLOBAL_UNFINISHED), MMI_EVENT_FAILURE);
        }
        mmi_frm_scrn_close(GRP_ID_IPSEC, SCR_ID_IPSECAPP_PROF_PROGRESSING);
    }
}


#define MMI_IPSEC_ONLY_FOR_TEST
/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_send_test_request
 * DESCRIPTION
 *  For testing only
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_send_test_request(U16 rsp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (rsp_id)
    {
        case PRT_MMI_IPSEC_INIT_RSP:
        {
            Message.oslDataPtr = OslConstructDataPtr(sizeof(app_kmp_init_cnf_struct));
            ((app_kmp_init_cnf_struct*)Message.oslDataPtr)->result = MMI_TRUE;
            break;
        }
        case PRT_MMI_IPSEC_ALG_RSP:
        {
            Message.oslDataPtr = OslConstructDataPtr(sizeof(app_kmp_alg_cnf_struct));
            ((app_kmp_alg_cnf_struct*)Message.oslDataPtr)->result = MMI_TRUE;
            break;
        }
        case PRT_MMI_IPSEC_ADDR_RSP:
        {
            Message.oslDataPtr = OslConstructDataPtr(sizeof(app_kmp_addr_cnf_struct));
            ((app_kmp_addr_cnf_struct*)Message.oslDataPtr)->result = MMI_TRUE;
            break;
        }
        case PRT_MMI_IPSEC_ACTIVATE_RSP:
        {
            Message.oslDataPtr = OslConstructDataPtr(sizeof(app_kmp_active_cnf_struct));
            ((app_kmp_active_cnf_struct*)Message.oslDataPtr)->result = MMI_TRUE;
            break;
        }
        case PRT_MMI_IPSEC_ADD_POLICY_RSP:
        {
            Message.oslDataPtr = OslConstructDataPtr(sizeof(app_kmp_policy_add_cnf_struct));
            ((app_kmp_policy_add_cnf_struct*)Message.oslDataPtr)->result = MMI_TRUE;
            break;
        }
        case PRT_MMI_IPSEC_DEL_POLICY_RSP:
        {
            Message.oslDataPtr = OslConstructDataPtr(sizeof(app_kmp_policy_del_cnf_struct));
            ((app_kmp_policy_del_cnf_struct*)Message.oslDataPtr)->result = MMI_TRUE;
            break;
        }
        case PRT_MMI_IPSEC_DEACTIVATE_RSP:
        {
            Message.oslDataPtr = OslConstructDataPtr(sizeof(app_kmp_deactive_cnf_struct));
            ((app_kmp_deactive_cnf_struct*)Message.oslDataPtr)->result = MMI_TRUE;
            break;
        }
        default:
        {
            MMI_EXT_ASSERT(0, 0, 0, 0);
        }
    }
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = (msg_type)rsp_id;
    /* Message.oslDataPtr: code above */
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_prof_list_csk_hdlr
 * DESCRIPTION
 *  handle the CSK function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_prof_list_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ipsec_cntx_p->activated == MMI_TRUE &&
        g_ipsec_cntx_p->activated_index == g_ipsec_cntx_p->profile_selected)
    {
        mmi_ipsec_prof_deactivate();
    }
    else
    {
        mmi_ipsec_prof_activate();
    }
}


#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ipsec_fte_prof_list_tap_callback
 * DESCRIPTION
 *  FTE prof list tap callback function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ipsec_fte_prof_list_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        if (g_ipsec_cntx_p->activated == MMI_TRUE && g_ipsec_cntx_p->activated_index == index)
        {
            mmi_ipsec_prof_deactivate();
        }
        else
        {
            mmi_ipsec_prof_activate();
        }
    }
}
#endif /* __MMI_FTE_SUPPORT__ */
#endif /* __MMI_IPSEC__ */

