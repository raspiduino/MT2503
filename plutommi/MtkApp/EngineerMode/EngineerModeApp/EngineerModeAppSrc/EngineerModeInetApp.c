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
 *   EngineerModeInetApp.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Engineering mode for Internet Application
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
/***************************************************************************** 
 * Include
 *****************************************************************************/
/* MMI */
#include "MMI_include.h"
#include "CommonScreens.h"

/* NVRAM (Please include it before "EngineerModeInetAppProt.h")*/
#include "nvram_common_defs.h"

/* NVRAM (Please include it before "EngineerModeInetAppProt.h")*/
#if defined(__MMI_EM_INET_APP_SLIM__) && !defined(__OPTR_NONE__)
#include "op_nvram_common_config.h"
#endif

#include "wgui_categories_util.h"
#include "common_nvram_editor_data_item.h"
/* Engineer Mode */
#include "mmi_rp_app_engineermode1_def.h"
#include "MenuCuiGprot.h"
#include "InlineCuiGprot.h"
#include "AlertScreen.h"

#include "EngineerModeUtil.h"
#include "EngineerModeInetAppGprot.h"
#include "EngineerModeInetAppProt.h"
#include "EngineerModeCommUI.h"
//#include "brs_vrsn.h"
#include "PixcomFontEngine.h"
#include "j2me_custom.h"

extern char* release_verno();
extern char* release_hw_ver();
extern char* build_date_time();

#if defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_EM_INET_APP_SLIM__)
/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
/* entry and exit function */
static void mmi_em_inet_entry_ua_main(void);
static void mmi_em_inet_entry_user_agent_options(void);
static void mmi_em_inet_entry_ua_activate(void);
static void mmi_em_inet_entry_ua_edit(void);
static void mmi_em_inet_entry_accept_header(void);
static void mmi_em_inet_entry_mms_version(void);

/* screen group proc func */
static MMI_RET mmi_em_inet_ua_proc(mmi_event_struct *evt);
static MMI_RET mmi_em_inet_accept_header_proc(mmi_event_struct *evt);
static MMI_RET mmi_em_inet_mms_version_proc(mmi_event_struct *evt);

/* menu cui related */
static void mmi_em_inet_set_main_menu(cui_menu_event_struct *menu_evt);
static void mmi_em_inet_set_user_agent_menu(cui_menu_event_struct *menu_evt);
static void mmi_em_inet_set_user_agent_options_menu(cui_menu_event_struct *menu_evt);
static void mmi_em_inet_set_accept_header_menu(cui_menu_event_struct *menu_evt);
static void mmi_em_inet_set_mms_version_menu(cui_menu_event_struct *menu_evt);


/* activate related function */
static void mmi_em_inet_activate_accept_header(mmi_em_inet_accept_header_enum index);
static void mmi_em_inet_activate_mms_version(mmi_em_inet_mms_version_enum index);

/* ua edit related function */
static void mmi_em_inet_ua_edit_save_changes(void);
static void mmi_em_inet_ua_edit_reject_changes(void);

/* utilities */
static mmi_em_inet_accept_header_enum mmi_em_inet_translate_accept_header_from_menu_id_to_index(MMI_MENU_ID menu_id);
static MMI_MENU_ID mmi_em_inet_translate_accept_header_from_index_to_menu_id(mmi_em_inet_accept_header_enum index);
static mmi_em_inet_mms_version_enum mmi_em_inet_translate_mms_version_from_menu_id_to_index(MMI_MENU_ID menu_id);
static MMI_MENU_ID mmi_em_inet_translate_mms_version_from_index_to_menu_id(mmi_em_inet_mms_version_enum index);

/* nvram */
static void mmi_em_inet_read_custpack(nvram_em_inet_custpack_struct* c_p);

/***************************************************************************** 
 * Definition
 *****************************************************************************/
#define MMI_EM_MAX_UA_NAME_LEN           (100)

/* for inline cui */
#define MMI_EM_INET_UA_STRING_CAPTION    (CUI_INLINE_ITEM_ID_BASE + 0)
#define MMI_EM_INET_UA_STRING_EDIT       (CUI_INLINE_ITEM_ID_BASE + 1)
#define MMI_EM_INET_UA_PROFILE_CAPTION   (CUI_INLINE_ITEM_ID_BASE + 2)
#define MMI_EM_INET_UA_PROFILE_EDIT      (CUI_INLINE_ITEM_ID_BASE + 3)

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/* dynamic context */
static mmi_em_inet_dynamic_cntx_struct *g_mmi_em_inet_dynamic_cntx_p;



/* inline cui structure */
static const cui_inline_item_caption_struct g_mmi_em_inet_ua_string_caption = 
{
    STR_ID_EM_MISC_INET_APP_USER_AGENT_STRING
};

static const cui_inline_item_fullscreen_edit_struct g_mmi_em_inet_ua_string_edit = 
{
    0,
    0,
    STR_ID_EM_MISC_INET_APP_USER_AGENT_STRING,
    0,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    IMM_INPUT_TYPE_ENGLISH_SENTENCE,
    MMI_EM_INET_MAX_UA_STRING_LEN,
    NULL
};

static const cui_inline_item_caption_struct g_mmi_em_inet_ua_profile_caption = 
{
    STR_ID_EM_MISC_INET_APP_USER_AGENT_PROFILE
};

static const cui_inline_item_fullscreen_edit_struct g_mmi_em_inet_ua_profile_edit = 
{
    0,
    0,
    STR_ID_EM_MISC_INET_APP_USER_AGENT_PROFILE,
    0,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    IMM_INPUT_TYPE_URL,
    MMI_EM_INET_MAX_UA_PROFILE_LEN,
    NULL
};

static const cui_inline_set_item_struct g_mmi_em_inet_inline_item[4] =
{
    {MMI_EM_INET_UA_STRING_CAPTION,  CUI_INLINE_ITEM_TYPE_CAPTION,         0, (void*)&g_mmi_em_inet_ua_string_caption},
    {MMI_EM_INET_UA_STRING_EDIT,     CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&g_mmi_em_inet_ua_string_edit},
    {MMI_EM_INET_UA_PROFILE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION ,        0, (void*)&g_mmi_em_inet_ua_profile_caption},
    {MMI_EM_INET_UA_PROFILE_EDIT,    CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&g_mmi_em_inet_ua_profile_edit}
};

static const cui_inline_struct g_mmi_em_inet_inline_screen = 
{
    4,
    STR_ID_EM_MISC_INET_APP_USER_AGENT,
    0,
    0,
    NULL,
    g_mmi_em_inet_inline_item
};


/***************************************************************************** 
 * Local Function
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_entry_ua_main
 * DESCRIPTION
 *  This is the entry function of user agent menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_inet_entry_ua_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* allocate memory */
    if (g_mmi_em_inet_dynamic_cntx_p == NULL)
    {
        g_mmi_em_inet_dynamic_cntx_p = (mmi_em_inet_dynamic_cntx_struct *)OslMalloc(sizeof(mmi_em_inet_dynamic_cntx_struct));
        kal_mem_set(g_mmi_em_inet_dynamic_cntx_p, 0, sizeof(mmi_em_inet_dynamic_cntx_struct));
    }

    /* get EM root group id */
    group_id = mmi_em_get_root_group();

    /* create and enter User Agent group */
    mmi_frm_group_create(group_id, GRP_ID_EM_MISC_INET_APP_USER_AGENT, mmi_em_inet_ua_proc, NULL);
    mmi_frm_group_enter(GRP_ID_EM_MISC_INET_APP_USER_AGENT, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    /* create menu cui */
    group_id = cui_menu_create(
                 GRP_ID_EM_MISC_INET_APP_USER_AGENT,
                 CUI_MENU_SRC_TYPE_APPCREATE, 
                 CUI_MENU_TYPE_APPSUB, 
                 MENU_ID_EM_MISC_INET_APP_USER_AGENT,
                 MMI_TRUE,
                 NULL);

    /* run menu cui */
    cui_menu_run(group_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_entry_user_agent_options
 * DESCRIPTION
 *  This is the entry function of user agent option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_inet_entry_user_agent_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_id = cui_menu_create(
                 GRP_ID_EM_MISC_INET_APP_USER_AGENT, 
                 CUI_MENU_SRC_TYPE_RESOURCE, 
                 CUI_MENU_TYPE_FROM_RESOURCE,
                 MENU_ID_EM_MISC_INET_APP_UA_OPTIONS,
                 MMI_FALSE, 
                 NULL);

    cui_menu_run(group_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_entry_ua_activate
 * DESCRIPTION
 *  This is the entry function for activate user agent
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_inet_entry_ua_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 select_idx = g_mmi_em_inet_dynamic_cntx_p->select_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /* update active user agent info and write to NVRAM if necessary */
    if (select_idx != applib_inet_get_active_user_agent_index())
    {
       applib_inet_activate_ua(select_idx);               
    }

    /* show popup to inform the activation is done */
    mmi_em_popup_by_str(STR_GLOBAL_ACTIVATED, MMI_EVENT_SUCCESS);

    /* delete screen up to MENU_ID_EM_MISC_INET_USER_AGENT_LIST */
    mmi_frm_group_close(GRP_ID_EM_MISC_INET_APP_USER_AGENT);
 }


/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_entry_ua_edit
 * DESCRIPTION
 *  This is the entry function for user agent edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_inet_entry_ua_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    mmi_em_inet_user_agent_edit_struct *edit_struct_p = NULL;
    nvram_em_inet_custpack_struct *custpack_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* create inline cui */
    group_id = cui_inline_create(GRP_ID_EM_MISC_INET_APP_USER_AGENT, &g_mmi_em_inet_inline_screen);

    /* allocate memory for edit buffer */
    edit_struct_p = (mmi_em_inet_user_agent_edit_struct*)OslMalloc(sizeof(mmi_em_inet_user_agent_edit_struct));
    g_mmi_em_inet_dynamic_cntx_p->edit_user_agent_p = edit_struct_p;
    g_mmi_em_inet_dynamic_cntx_p->inline_cui_id = group_id;

    /* allocate memory for reading user agent NVRAM */
    custpack_p = (nvram_em_inet_custpack_struct*) OslMalloc(sizeof(nvram_em_inet_custpack_struct));
    /* read user agent from NVRAM */
    mmi_em_inet_read_custpack(custpack_p);

    /* copy user agent */
    kal_wsprintf((unsigned short *)edit_struct_p->string,  "%s", custpack_p->user_agent_string);
    kal_wsprintf((unsigned short *)edit_struct_p->profile, "%s", custpack_p->user_agent_profile);

    /* free memory */
    OslMfree(custpack_p);
	
    cui_inline_set_value(group_id, MMI_EM_INET_UA_STRING_EDIT, (void*)edit_struct_p->string);
    cui_inline_set_value(group_id, MMI_EM_INET_UA_PROFILE_EDIT, (void*)edit_struct_p->profile);

    cui_inline_run(group_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_entry_accept_header
 * DESCRIPTION
 *  This is the entry function for accept header menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_inet_entry_accept_header(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_id = mmi_em_get_root_group();
    mmi_frm_group_create(group_id, GRP_ID_EM_MISC_INET_APP_ACCEPT_HEADER, mmi_em_inet_accept_header_proc, NULL);
    mmi_frm_group_enter(GRP_ID_EM_MISC_INET_APP_ACCEPT_HEADER, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    group_id = cui_menu_create(
                 GRP_ID_EM_MISC_INET_APP_ACCEPT_HEADER, 
                 CUI_MENU_SRC_TYPE_RESOURCE, 
                 CUI_MENU_TYPE_FROM_RESOURCE, 
                 MENU_ID_EM_MISC_INET_APP_ACCEPT_HEADER,
                 MMI_TRUE, 
                 NULL);

    cui_menu_run(group_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_entry_mms_version
 * DESCRIPTION
 *  This is the entry function for mms version menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_inet_entry_mms_version(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_id = mmi_em_get_root_group();
    mmi_frm_group_create(group_id, GRP_ID_EM_MISC_INET_APP_MMS_VERSION, mmi_em_inet_mms_version_proc, NULL);
    mmi_frm_group_enter(GRP_ID_EM_MISC_INET_APP_MMS_VERSION, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    group_id = cui_menu_create(
                 GRP_ID_EM_MISC_INET_APP_MMS_VERSION, 
                 CUI_MENU_SRC_TYPE_RESOURCE, 
                 CUI_MENU_TYPE_FROM_RESOURCE, 
                 MENU_ID_EM_MISC_INET_APP_MMS_VERSION,
                 MMI_TRUE,
                 NULL);

    cui_menu_run(group_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_ua_proc
 * DESCRIPTION
 *  This function is the group event proc of user agent group
 * PARAMETERS
 *  evt: [IN] group event
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static MMI_RET mmi_em_inet_ua_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    { 
        case EVT_ID_GROUP_DEINIT:
        {
            mmi_em_inet_dynamic_cntx_struct *dynamic_cntx_p = g_mmi_em_inet_dynamic_cntx_p;
            if (dynamic_cntx_p != NULL)
            {
                if (dynamic_cntx_p->edit_user_agent_p != NULL)
                {
                    OslMfree(dynamic_cntx_p->edit_user_agent_p);
                }
                OslMfree(dynamic_cntx_p);
				g_mmi_em_inet_dynamic_cntx_p = NULL;
            }
            break;
        }

        case EVT_ID_CUI_MENU_LIST_ENTRY:
       	{
            MMI_MENU_ID menu_id = menu_evt->parent_menu_id;
            if (menu_id == MENU_ID_EM_MISC_INET_APP_USER_AGENT)
            {
                mmi_em_inet_set_user_agent_menu(menu_evt);
            }
            else if (menu_id == MENU_ID_EM_MISC_INET_APP_UA_OPTIONS)
            {
                mmi_em_inet_set_user_agent_options_menu(menu_evt);
            }

            break;
        }     
	
        case EVT_ID_CUI_MENU_ITEM_SELECT:
     //   case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        {           
            MMI_MENU_ID highlighted_id = menu_evt->highlighted_menu_id;

            if (highlighted_id == MENU_ID_EM_MISC_INET_APP_UA_EDIT)
            {
                mmi_em_inet_entry_ua_edit();
            }
            else if (highlighted_id == MENU_ID_EM_MISC_INET_APP_UA_ACTIVATE)
            {
                mmi_em_inet_entry_ua_activate();
            }
            else /* this means a user agent is selected */
            {
                g_mmi_em_inet_dynamic_cntx_p->select_index = highlighted_id;
                mmi_em_inet_entry_user_agent_options();
            }
            break;
        }
		
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
           cui_menu_close(menu_evt->sender_id);		   
           break;


        case EVT_ID_CUI_INLINE_SUBMIT:
        {
		    mmi_confirm_property_struct arg;

			mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
			arg.parent_id = GRP_ID_EM_MISC_INET_APP_USER_AGENT;
			arg.callback = (mmi_proc_func)NULL;
			arg.user_tag = NULL;
			
			if (mmi_confirm_display((WCHAR*)GetString(STR_GLOBAL_SAVE_ASK), 
								MMI_EVENT_QUERY, 
								&arg))
			{
                SetLeftSoftkeyFunction(mmi_em_inet_ua_edit_save_changes, KEY_EVENT_UP);
                SetRightSoftkeyFunction(mmi_em_inet_ua_edit_reject_changes, KEY_EVENT_UP);
            }
            break;			
        }

        case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_abort_struct *abort = (cui_event_inline_abort_struct*)evt;
            cui_inline_close(abort->sender_id);
            break;
        }
    }

    return MMI_RET_OK;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_accept_header_proc
 * DESCRIPTION
 *  This function is the group event proc of accept header group
 * PARAMETERS
 *  evt: [IN] group event
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static MMI_RET mmi_em_inet_accept_header_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    { 
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            mmi_em_inet_set_accept_header_menu(menu_evt);
            break;
	
        case EVT_ID_CUI_MENU_ITEM_SELECT:
     //   case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        {           
            mmi_em_inet_accept_header_enum index = 
                mmi_em_inet_translate_accept_header_from_menu_id_to_index(menu_evt->highlighted_menu_id);
            mmi_em_inet_activate_accept_header(index);
            break;
        }
		
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
           cui_menu_close(menu_evt->sender_id);		   
           break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_mms_version_proc
 * DESCRIPTION
 *  This function is the group event proc of mms version group
 * PARAMETERS
 *  evt: [IN] group event
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static MMI_RET mmi_em_inet_mms_version_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    { 
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            mmi_em_inet_set_mms_version_menu(menu_evt);
            break;
	
        case EVT_ID_CUI_MENU_ITEM_SELECT:
    //    case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        {           
            mmi_em_inet_mms_version_enum index = 
                mmi_em_inet_translate_mms_version_from_menu_id_to_index(menu_evt->highlighted_menu_id);
            mmi_em_inet_activate_mms_version(index);
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
           cui_menu_close(menu_evt->sender_id);		   
           break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_set_main_menu
 * DESCRIPTION
 *  This function is used to set menu CUI component of main menu
 * PARAMETERS
 *  menu_evt: [IN] event
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_inet_set_main_menu(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *hint_data;
    MMI_ID owner_id = menu_evt->sender_id;
   /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set flag */
    cui_menu_set_currlist_flags(owner_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

    /* set LSK */
    cui_menu_set_currlist_left_softkey(owner_id, get_string(STR_GLOBAL_OK));

    /* set CSK */
  //  cui_menu_enable_center_softkey(owner_id, 0, IMG_GLOBAL_COMMON_CSK);

    /* set hint data */
    hint_data = (WCHAR*)OslMalloc(MMI_EM_MAX_UA_NAME_LEN);
    kal_wsprintf(hint_data, "%s", applib_inet_get_user_agent_from_list(applib_inet_get_active_user_agent_index()));
    cui_menu_set_item_hint(owner_id, MENU_ID_EM_MISC_INET_APP_USER_AGENT, hint_data);
    OslMfree(hint_data);

    cui_menu_set_item_hint(owner_id, MENU_ID_EM_MISC_INET_APP_ACCEPT_HEADER, (WCHAR*)get_string(STR_ID_EM_MISC_INET_APP_AH_WAP_1_2_1 + applib_inet_get_active_accept_header()));
    cui_menu_set_item_hint(owner_id, MENU_ID_EM_MISC_INET_APP_MMS_VERSION, (WCHAR*)get_string(STR_ID_EM_MISC_INET_APP_MV_MMS_1_0 + applib_inet_get_active_mms_version()));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_set_user_agent_menu
 * DESCRIPTION
 *  This function is used to set menu CUI component of user agent
 * PARAMETERS
 *  menu_evt: [IN] group event
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_inet_set_user_agent_menu(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_MENU_ID i, menu_id_list[MMI_EM_INET_USER_AGENT_TOTAL];
    WCHAR *ua_name;
    MMI_ID owner_id = menu_evt->sender_id;
    U16 active_ua_index = applib_inet_get_active_user_agent_index();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set title */
    cui_menu_set_currlist_title(owner_id, (WCHAR*)get_string(STR_ID_EM_MISC_INET_APP_USER_AGENT), 0);

    /* set LSK */
    cui_menu_set_currlist_left_softkey(owner_id, get_string(STR_GLOBAL_OPTIONS));

    /* set CSK */
 //   cui_menu_enable_center_softkey(owner_id, 0, IMG_GLOBAL_COMMON_CSK);


    /* create menu id list */
    for (i = 0; i < MMI_EM_INET_USER_AGENT_TOTAL; i++)
    {
        menu_id_list[i] = i;
    }

    /* set the menu id list */
    cui_menu_set_currlist(owner_id, MMI_EM_INET_USER_AGENT_TOTAL, menu_id_list);

    /* set each user agent name */
    ua_name = (WCHAR*)OslMalloc(MMI_EM_MAX_UA_NAME_LEN);
    for (i = 0; i < MMI_EM_INET_USER_AGENT_TOTAL; i++)
    {
        kal_wsprintf(ua_name, "%s", applib_inet_get_user_agent_from_list(i));
        cui_menu_set_item_string(owner_id, i, ua_name);
    }
    OslMfree(ua_name);

    /* set highlighted item */
    cui_menu_set_currlist_highlighted_id(owner_id, active_ua_index);

    /* set vicon image */
    cui_menu_set_item_image(owner_id, active_ua_index, IMG_VICON);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_set_user_agent_options_menu
 * DESCRIPTION
 *  This function is used to set menu CUI component of user agent options
 * PARAMETERS
 *  menu_evt: [IN] group event
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_inet_set_user_agent_options_menu(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID owner_id = menu_evt->sender_id;
    MMI_BOOL hide_edit_item = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set flag */
    cui_menu_set_currlist_flags(owner_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

    /* set LSK */
    cui_menu_set_currlist_left_softkey(owner_id, get_string(STR_GLOBAL_OK));

    /* set CSK */
 //   cui_menu_enable_center_softkey(owner_id, 0, IMG_GLOBAL_COMMON_CSK);

    /* hide edit option if seleted item is not editable */
    if (g_mmi_em_inet_dynamic_cntx_p->select_index == 0)
    {
        hide_edit_item = MMI_FALSE;
    }
    cui_menu_set_item_hidden(owner_id, MENU_ID_EM_MISC_INET_APP_UA_EDIT, hide_edit_item);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_set_accept_header_menu
 * DESCRIPTION
 *  This function is used to set menu CUI component of accept header
 * PARAMETERS
 *  menu_evt: [IN] group event
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_inet_set_accept_header_menu(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID owner_id = menu_evt->sender_id;
    MMI_MENU_ID highlight_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set flag */
    cui_menu_set_currlist_flags(owner_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);

    /* set LSK */
    cui_menu_set_currlist_left_softkey(owner_id, get_string(STR_GLOBAL_OK));

    /* set CSK */
 //   cui_menu_enable_center_softkey(owner_id, 0, IMG_GLOBAL_COMMON_CSK);	

    /* set highlighted item*/
    highlight_item = mmi_em_inet_translate_accept_header_from_index_to_menu_id(
        applib_inet_get_active_accept_header());
    cui_menu_set_currlist_highlighted_id(owner_id, highlight_item);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_set_mms_version_menu
 * DESCRIPTION
 *  This function is used to set menu CUI component
 * PARAMETERS
 *  evt: [IN] group event
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_inet_set_mms_version_menu(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID owner_id = menu_evt->sender_id;
    MMI_MENU_ID highlight_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set flag */
    cui_menu_set_currlist_flags(owner_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);

    /* set LSK */
    cui_menu_set_currlist_left_softkey(owner_id, get_string(STR_GLOBAL_OK));

    /* set CSK */
 //   cui_menu_enable_center_softkey(owner_id, 0, IMG_GLOBAL_COMMON_CSK);	

    /* set highlighted item*/
    highlight_item = mmi_em_inet_translate_mms_version_from_index_to_menu_id(
        applib_inet_get_active_mms_version());
    cui_menu_set_currlist_highlighted_id(owner_id, highlight_item);

}




/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_activate_accept_header
 * DESCRIPTION
 *  This function is called to activate accept header
 * PARAMETERS
 *  index: [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_inet_activate_accept_header(mmi_em_inet_accept_header_enum index)
{
     

    applib_inet_activate_accept_header(index);
    /* show popup to indicate the activation is done */
    mmi_em_popup_by_str(STR_GLOBAL_ACTIVATED, MMI_EVENT_SUCCESS);

    /* close active screen and back to main menu */
    mmi_frm_group_close(GRP_ID_EM_MISC_INET_APP_ACCEPT_HEADER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_activate_mms_version
 * DESCRIPTION
 *  This function is used to activate mms version
 * PARAMETERS
 *  index: [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_inet_activate_mms_version(mmi_em_inet_mms_version_enum index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    /* update active mms version if neccessary */
    applib_inet_activate_mms_version(index);

    /* show popup to indicate the activation is done */
    mmi_em_popup_by_str(STR_GLOBAL_ACTIVATED, MMI_EVENT_SUCCESS);

    /* close active screen and back to main menu */
    mmi_frm_group_close(GRP_ID_EM_MISC_INET_APP_MMS_VERSION);
}





/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_ua_edit_save_changes
 * DESCRIPTION
 *  This function is called when user wants to save change after editing ua
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_inet_ua_edit_save_changes(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
   
	applib_inet_set_ua_edited(g_mmi_em_inet_dynamic_cntx_p->edit_user_agent_p->string, g_mmi_em_inet_dynamic_cntx_p->edit_user_agent_p->profile);
    /* display popup to inform the save is done */
    mmi_em_popup_by_str(STR_GLOBAL_SAVED, MMI_EVENT_SUCCESS);

    /* back to main menu */
    mmi_frm_group_close(GRP_ID_EM_MISC_INET_APP_USER_AGENT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_ua_edit_reject_changes
 * DESCRIPTION
 *  This function is called when user reject to save change after editing ua
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_inet_ua_edit_reject_changes(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* go back to user agent list screen */
    //cui_menu_close(g_mmi_em_inet_dynamic_cntx_p->inline_cui_id);
    mmi_frm_group_close(GRP_ID_EM_MISC_INET_APP_USER_AGENT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_translate_accept_header_from_menu_id_to_index
 * DESCRIPTION
 *  This function is used to translate menu id to index
 * PARAMETERS
 *  menu_id: [IN] menu id
 * RETURNS
 *  index of accept header
 *****************************************************************************/
static mmi_em_inet_accept_header_enum mmi_em_inet_translate_accept_header_from_menu_id_to_index(MMI_MENU_ID menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return menu_id - MENU_ID_EM_MISC_INET_APP_AH_WAP_1_2_1 + MMI_EM_INET_ACCEPT_HEADER_WAP_1_2_1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_translate_accept_header_from_index_to_menu_id
 * DESCRIPTION
 *  This function is used to translate index to menu id
 * PARAMETERS
 *  index: [IN] index of accept header
 * RETURNS
 *  menu id
 *****************************************************************************/
static MMI_MENU_ID mmi_em_inet_translate_accept_header_from_index_to_menu_id(mmi_em_inet_accept_header_enum index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return index - MMI_EM_INET_ACCEPT_HEADER_WAP_1_2_1 + MENU_ID_EM_MISC_INET_APP_AH_WAP_1_2_1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_translate_mms_version_from_menu_id_to_index
 * DESCRIPTION
 *  This function is used to translate menu id to index
 * PARAMETERS
 *  menu_id: [IN] menu id
 * RETURNS
 *  index of mms version
 *****************************************************************************/
static mmi_em_inet_mms_version_enum mmi_em_inet_translate_mms_version_from_menu_id_to_index(MMI_MENU_ID menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return menu_id - MENU_ID_EM_MISC_INET_APP_MV_MMS_1_0 + MMI_EM_INET_MMS_VERSION_10;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_translate_mms_version_from_index_to_menu_id
 * DESCRIPTION
 *  This function is used to translate index to menu id
 * PARAMETERS
 *  index: [IN] index of mms version
 * RETURNS
 *  menu id
 *****************************************************************************/
static MMI_MENU_ID mmi_em_inet_translate_mms_version_from_index_to_menu_id(mmi_em_inet_mms_version_enum index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return index - MMI_EM_INET_MMS_VERSION_10 + MENU_ID_EM_MISC_INET_APP_MV_MMS_1_0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_read_custpack
 * DESCRIPTION
 *  This function is used to read user agent from nvram
 * PARAMETERS
 *  c_p     [IN/OUT] used to read NVRAM 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_inet_read_custpack(nvram_em_inet_custpack_struct* c_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* read custpack setting from NVRAM */
    ReadRecord(NVRAM_EF_INET_CUSTPACK_LID, 1, c_p, sizeof(nvram_em_inet_custpack_struct), &error);
    MMI_ASSERT(error == NVRAM_READ_SUCCESS);

}


/***************************************************************************** 
 * Glocal Function for Engineer Mode Inet App
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_init
 * DESCRIPTION
 *  This is the hilight handler for MENU_ID_EM_MISC_INET_MAIN
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_inet_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* read default value from MMI Cache */
   applib_inet_init();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_menu_entry_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_em_inet_menu_entry_handler(cui_menu_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event->parent_menu_id)
   	{
        case MENU_ID_EM_MISC_INTERNET_APPLICATION:
            mmi_em_inet_set_main_menu(event);
            break;

        default: 
            return MMI_RET_OK;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_menu_select_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_em_inet_menu_select_handler(cui_menu_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event->highlighted_menu_id)
   	{
        case MENU_ID_EM_MISC_INET_APP_USER_AGENT:
            mmi_em_inet_entry_ua_main();
            break;

        case MENU_ID_EM_MISC_INET_APP_ACCEPT_HEADER:
            mmi_em_inet_entry_accept_header();
            break;

		case MENU_ID_EM_MISC_INET_APP_MMS_VERSION:
            mmi_em_inet_entry_mms_version();
            break;			

        default: 
            return MMI_RET_OK;
    }
    return MMI_RET_OK;
}

#endif /* __MMI_EM_INET_APP_SLIM__ */
/***************************************************************************** 
 * Glocal Function for Inet App Service
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_em_inet_get_user_agent_string
 * DESCRIPTION
 *  This function is called to get active user agent string
 * PARAMETERS
 *  void
 * RETURNS
 *  active user agent string
 *****************************************************************************/



