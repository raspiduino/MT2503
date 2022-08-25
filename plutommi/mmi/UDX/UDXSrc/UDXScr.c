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
 *  UDXScr.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intended for UDX Agent screen flow.
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
 *============================================================================
 ****************************************************************************/
#include "mmi_features.h"

#ifdef __MMI_UDX_SUPPORT__
#include "ProtocolEvents.h"
#include "Thrdosinterface.h"
#include "mainmenudef.h"
#include "CommonScreens.h"
#include "ImeGprot.h"
#include "Conversions.h"
#include "custom_mmi_default_value.h"

#include "UDXProt.h"
#include "UDXGprot.h"
#include "mmi2udx_struct.h"
#include "custom_udx.h"
#include "mmi_rp_app_udx_def.h"
#include "FileMgrGprot.h"
#include "filemgrsrvgprot.h"
#include "fmt_struct.h"

#ifdef __MMI_UDX_VCARD_SUPPORT__
#include "PhonebookGprot.h"
#endif /* __MMI_UDX_VCARD_SUPPORT__ */

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif

#include "IdleAppDef.h" /* Idle Screen Flag */
#include "SettingProfile.h"
#include "gpioInc.h"
#include "Fmt_struct.h"
#include "UcmSrvGprot.h"
#include "MessagesMiscell.h"
#include "ctype.h"      /* For tolower() */
#include "AlarmFrameworkProt.h"
#include "PhoneSetupGprots.h"

#ifdef __MMI_OPP_SUPPORT__
#include "BTMMIObexGprots.h"
#include "ExtDeviceDefs.h"
#endif 

#include "menucuigprot.h"
#include "fseditorcuigprot.h"
#include "FileMgrCuiGprot.h"
#include "Phbcuigprot.h"
#include "BTsendcuigprot.h"
#include "ProfilesSrvGprot.h"
#include "idlegprot.h"
#include "mmi_rp_app_uiframework_def.h"
#include "CommonScreensResDef.h"
#include "Wgui_categories_util.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
static void mmi_udx_entry_main_menu(void);
static void mmi_udx_menu_cui_select_evt_hdlr(mmi_event_struct *param);
static void mmi_udx_menu_cui_entry_evt_hdlr(mmi_event_struct *param);
static void mmi_udx_menu_cui_close_notify_evt_hdlr(mmi_event_struct *event);

/* build */
static void mmi_udx_builder_build_file_from_builder(void);
static void mmi_udx_parser_parse_file_from_parser(void);

static void mmi_udx_settings_entry_evt_hdlr(cui_menu_event_struct* param);
static void mmi_udx_entry_help(void);
static void mmi_udx_entry_user_info(void);

static void mmi_udx_entry_cofilict_solution(void);
static void mmi_udx_confilct_solution_entry_evt_hdlr(cui_menu_event_struct *evt);
static void mmi_udx_entry_conflict_solution_save(cui_menu_event_struct *evt);

static S32 mmi_udx_data_type_select_get_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_items);
static S32 mmi_udx_data_type_select_get_state(S32 item_index, PU8 *checkbox_image);
static S32 mmi_udx_data_type_select_set_state(S32 item_index);
static void mmi_udx_data_type_select_check(void);

static void mmi_udx_builder_entry_data_type_select(void);
static void mmi_udx_highlight_hdlr(S32 index);
static void mmi_udx_builder_data_type_select_done(void);

static void mmi_udx_parser_file_selector_cui_evt_hdlr(mmi_event_struct *param);
static void mmi_udx_builder_filename_cui_evt_hdlr(mmi_event_struct *param);
static void mmi_udx_builder_folder_selector_cui_evt_hdlr(mmi_event_struct *param);

static void mmi_udx_builder_overwrite_exsiting_file_confirm(void);
static void mmi_udx_builder_overwrite_exsiting_file_confirm_yes(void);
static void mmi_udx_parser_data_type_select_done(void);

static void mmi_udx_builder_entry_filename(void);
static void mmi_udx_builder_enter_filename_done(void);
static void mmi_udx_show_aborting(void);
static void mmi_udx_entry_show_processing(void);
static MMI_BOOL mmi_udx_parser_data_type_exist(U8 data_type);

#if defined(__MMI_OPP_SUPPORT__)
static void mmi_udx_builder_exit_send_way(void);
static void mmi_udx_builder_entry_send_by_bt(void);
#endif /* __MMI_OPP_SUPPORT__ */


/***************************************************************************** 
 * Local Variable
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

#define COMMON_API
/*****************************************************************************
 * FUNCTION
 *  mmi_udx_entry_group_main_menu
 * DESCRIPTION
 *  UDX agent entry main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_udx_group_main_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
        /* menu cui event hdlr */
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            mmi_udx_menu_cui_select_evt_hdlr(param);
            break;
        }
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            mmi_udx_menu_cui_entry_evt_hdlr(param);
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            mmi_udx_menu_cui_close_notify_evt_hdlr(param);
            break;
        }
        /* fmgr cui event hdlr */
        case EVT_ID_CUI_FOLDER_SELECTOR_RESULT:
        {
            mmi_udx_builder_folder_selector_cui_evt_hdlr(param);
            break;
        }
        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
        {
            mmi_udx_parser_file_selector_cui_evt_hdlr(param);
            break;
        }
        /* phb multi select cui event handler */
        case EVT_ID_PHB_SELECT_MULTI_CONTACT:
        case EVT_ID_PHB_SELECT_MULTI_CONTACT_CANCEL:
        {
            mmi_udx_builder_contact_select_cui_evt_hdlr(param);
            break;
        }
        /* filename cui event handler */
        case EVT_ID_CUI_FILENAME_EDITOR_RESULT:
        {
            mmi_udx_builder_filename_cui_evt_hdlr(param);
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_menu_cui_entry_evt_hdlr
 * DESCRIPTION
 *  menu cui close event handler
 * PARAMETERS
 *  evt       [IN]            menu cui event handler
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_menu_cui_select_evt_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *evt = (cui_menu_event_struct *)param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MENU_ID_UDX_CONFLICT_SOLUTION == evt->parent_menu_id)
    {
        mmi_udx_entry_conflict_solution_save(evt);
        return;
    }
    
    switch(evt->highlighted_menu_id)
    {
        case MENU_ID_UDX_BUILD:
        {
            mmi_udx_builder_build_file_from_builder();
            break;
        }
        case MENU_ID_UDX_PARSE:
        {
            mmi_udx_parser_parse_file_from_parser();
            break;
        }
        case MENU_ID_UDX_CONFLICT_SOLUTION:
        {
            mmi_udx_entry_cofilict_solution();
            break;
        }
        case MENU_ID_UDX_USER_INFO:
        {
            mmi_udx_entry_user_info();
            break;
        }
        case MENU_ID_UDX_HELP:
        {
            mmi_udx_entry_help();
            break;
        }
        case MENU_ID_UDX_PARSE_USE_UDX_FILE:
        {
            g_mmi_udx_cntx.parse_header_only = MMI_FALSE;
            mmi_udx_paser_get_file_header_info();
            break;
        }
        case MENU_ID_UDX_PARSE_FILE_INFO:
        {
            g_mmi_udx_cntx.parse_header_only = MMI_TRUE;
            mmi_udx_paser_get_file_header_info(); 
            break;
        }
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_menu_cui_entry_evt_hdlr
 * DESCRIPTION
 *  menu cui close event handler
 * PARAMETERS
 *  evt       [IN]            menu cui event handler
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_menu_cui_entry_evt_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *evt = (cui_menu_event_struct*)param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->parent_menu_id)
    {
        case MENU_ID_UDX_MAIN_MENU:
        {
            /* when builder and parser finish, should goback udx main menu and ini context */
            mmi_udx_init_cntx();
            break;
        }
        case MENU_ID_UDX_SETTINGS:
        {
            mmi_udx_settings_entry_evt_hdlr(evt);
            break;
        }
        case MENU_ID_UDX_CONFLICT_SOLUTION:
        {
            mmi_udx_confilct_solution_entry_evt_hdlr(evt);
            break;
        }
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_menu_cui_close_notify_evt_hdlr
 * DESCRIPTION
 *  menu cui close event handler
 * PARAMETERS
 *  evt       [IN]            menu cui event handler
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_menu_cui_close_notify_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *evt = (cui_menu_event_struct*)event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* return current menu cui, close menu cui */
    cui_menu_close(evt->sender_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_highlight_hdlr
 * DESCRIPTION
 *  Highlight Handler for udx data select
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_udx_cntx.highlight_index = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_data_type_select_get_item
 * DESCRIPTION
 *  udx type select get item information
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_udx_data_type_select_get_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((start_index < 0) || (start_index >= MMI_UDX_TYPE_TOTAL))
    {
        return 0;
    }

    for (index = 0; index < num_items; index++)
    {
        mmi_ucs2cpy((CHAR*) menu_data[index].item_list[0], (CHAR*) GetString(udx_support_type_string_tbl[index].data_type_string));

        menu_data[index].image_list[0] = get_image(udx_support_type_string_tbl[index].img_id);
    }
    
    return num_items;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_data_type_select_get_state
 * DESCRIPTION
 *  get check box state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_udx_data_type_select_get_state(S32 item_index, PU8 *checkbox_image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL reset = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_udx_cntx.data_type_state[item_index])
    {
        switch (g_mmi_udx_cntx.data_type_array[item_index])
        {
    #ifdef __MMI_UDX_VCARD_SUPPORT__
            case UDX_TYPE_VCARD:                
                if (!mmi_phb_check_ready(MMI_FALSE))
                {
                    reset = MMI_TRUE;
                }
                break;
    #endif

            case UDX_TYPE_VCALENDAR:
            case UDX_TYPE_SMS:
            case UDX_TYPE_MMS:
            case UDX_TYPE_EMAIL:
            default:
                break;
        }

        if (reset)
        {
            g_mmi_udx_cntx.data_type_state[item_index] = 0;
        }
    }
        
    *checkbox_image = (g_mmi_udx_cntx.data_type_state[item_index]) ? (PU8)GetImage(CHECKBOX_ON_IMAGE_ID) : (PU8)GetImage(CHECKBOX_OFF_IMAGE_ID);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_data_type_select_set_state
 * DESCRIPTION
 *  get check box state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_udx_data_type_select_set_state(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL reset = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_udx_cntx.data_type_state[item_index] = !g_mmi_udx_cntx.data_type_state[item_index];

    if (g_mmi_udx_cntx.data_type_state[item_index])
    {
        switch (g_mmi_udx_cntx.data_type_array[item_index])
        {
        #ifdef __MMI_UDX_VCARD_SUPPORT__
            case UDX_TYPE_VCARD:                
                if (!mmi_phb_check_ready(MMI_TRUE))
                {
                    reset = MMI_TRUE;
                }
                break;
        #endif

            case UDX_TYPE_VCALENDAR:
            case UDX_TYPE_SMS:
            case UDX_TYPE_MMS:
            case UDX_TYPE_EMAIL:
            default:
                break;
        }

        if (reset)
        {
            g_mmi_udx_cntx.data_type_state[item_index] = !g_mmi_udx_cntx.data_type_state[item_index];
            return MMI_FALSE;
        }
    }
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_data_type_select_check
 * DESCRIPTION
 *  star or enter key check
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_data_type_select_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_udx_data_type_select_set_state(g_mmi_udx_cntx.highlight_index) == MMI_TRUE)
    {
        RedrawCategoryFunction();
    }
}


#define MMI_UDX_MAIN_MENU
/*****************************************************************************
 * FUNCTION
 *  mmi_udx_highlight_main_menu
 * DESCRIPTION
 *  UDX agent main menu highlight hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_highlight_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_udx_entry_group_main_menu, KEY_EVENT_UP);    
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_entry_group_main_menu
 * DESCRIPTION
 *  UDX agent entry main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_entry_group_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_udx_is_busy(MMI_TRUE))
    {
        return;
    }
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_UDX_MAIN, mmi_udx_group_main_proc, NULL);
    mmi_frm_group_enter(GRP_ID_UDX_MAIN, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_udx_entry_main_menu();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_entry_main_menu
 * DESCRIPTION
 *  UDX agent entry main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_entry_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_id = cui_menu_create(
                        GRP_ID_UDX_MAIN, 
                        CUI_MENU_SRC_TYPE_RESOURCE, 
                        CUI_MENU_TYPE_APPMAIN, 
                        MENU_ID_UDX_MAIN_MENU, 
                        MMI_FALSE, 
                        NULL);

    cui_menu_set_default_title(
        menu_cui_id, 
        (WCHAR*)get_string(STR_ID_UDX_MAIN_MENU), 
        (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_UDX_MAIN_MENU)));

    cui_menu_run(menu_cui_id);
}


#define MMI_UDX_SETTINGS
/*****************************************************************************
 * FUNCTION
 *  mmi_udx_settings_entry_evt_hdlr
 * DESCRIPTION
 *  UDX agent entry user info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_settings_entry_evt_hdlr(cui_menu_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_set_currlist_title(
        param->sender_id, 
        (WCHAR *)get_string(STR_GLOBAL_SETTINGS), 
        (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_UDX_MAIN_MENU)));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_entry_user_info
 * DESCRIPTION
 *  UDX agent entry user info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_entry_user_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    CHAR user_info[(MMI_PHB_NAME_LENGTH + 1) * ENCODING_LENGTH];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!mmi_frm_scrn_enter(
            GRP_ID_UDX_MAIN, 
            SCR_ID_UDX_USER_INFO, 
            NULL, 
            mmi_udx_entry_user_info, 
            MMI_FRM_UNKNOW_SCRN))
    {
        return;   
    }
    
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    mmi_udx_get_user_info(user_info);

    ShowCategory7Screen(
        STR_ID_UDX_USER_INFO,
        GetRootTitleIcon(MENU_ID_UDX_MAIN_MENU),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) user_info,
        gui_buffer);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_entry_cofilict_solution
 * DESCRIPTION
 *  UDX agent entry data use
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_entry_cofilict_solution(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cui_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_id = cui_menu_create(
                    GRP_ID_UDX_MAIN, 
                    CUI_MENU_SRC_TYPE_APPCREATE, 
                    CUI_MENU_TYPE_APPSUB, 
                    MENU_ID_UDX_CONFLICT_SOLUTION, 
                    MMI_FALSE, 
                    NULL);
    cui_menu_run(cui_id);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_udx_confilct_solution_entry_evt_hdlr
 * DESCRIPTION
 *  UDX agent entry data use
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_confilct_solution_entry_evt_hdlr(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id list_of_ids[MMI_UDX_DATA_USE_TOTAL];
    U16 list_of_str[MMI_UDX_DATA_USE_TOTAL];
	U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_of_ids[0] = MMI_UDX_DATA_USE_ADD;
    list_of_ids[1] = MMI_UDX_DATA_USE_REPLACE;
    list_of_str[0] = STR_ID_UDX_DATA_USE_ADD_NEW;
    list_of_str[1] = STR_GLOBAL_REPLACE;
    
    cui_menu_set_currlist(evt->sender_id, MMI_UDX_DATA_USE_TOTAL, list_of_ids);

    cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);

    cui_menu_set_currlist_title(
        evt->sender_id, 
        (WCHAR *)get_string(STR_ID_UDX_DATA_USE_WAY), 
        (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_UDX_MAIN_MENU)));

    
    for(i = 0; i < MMI_UDX_DATA_USE_TOTAL; i++)
    {
        cui_menu_set_item_string(
            evt->sender_id, 
            (mmi_menu_id)(MMI_UDX_DATA_USE_ADD + i), 
            (WCHAR*)get_string(list_of_str[i]));
    }

    /* now, only support the MMI_UDX_DATA_USE_ADD */
    cui_menu_set_item_hidden(evt->sender_id, MMI_UDX_DATA_USE_REPLACE, MMI_TRUE);
    
    cui_menu_set_currlist_left_softkey(
        evt->sender_id, 
        (UI_string_type)GetString(STR_GLOBAL_OK));
    
    g_mmi_udx_cntx.highlight_index = mmi_udx_get_data_use_way();

    cui_menu_set_currlist_highlighted_id(
        evt->sender_id, 
        (mmi_menu_id)(g_mmi_udx_cntx.highlight_index + MMI_UDX_DATA_USE_ADD));
}


/*****************************************************************************
 * FUNCTION
 mmi_udx_entry_conflict_solution_save
 * DESCRIPTION
 *  UDX agent entry data use save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_entry_conflict_solution_save(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_popup_display_simple(
        (WCHAR*)get_string(STR_GLOBAL_DONE), 
        MMI_EVENT_SUCCESS, 
        GRP_ID_ROOT, 
        NULL);
    
    WriteValue(NVRAM_UDX_DATA_USE_WAY, &(g_mmi_udx_cntx.highlight_index), DS_BYTE, &pError);

    cui_menu_close(evt->sender_id);
}


#define MMI_UDX_HELP
/*****************************************************************************
 * FUNCTION
 *  mmi_udx_entry_help
 * DESCRIPTION
 *  udx help entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_entry_help(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* gui_buffer;
    CHAR *help_info;    
    S32 info_size;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!mmi_frm_scrn_enter(
            GRP_ID_UDX_MAIN, 
            SCR_ID_UDX_HELP, 
            NULL, 
            mmi_udx_entry_help, 
            MMI_FRM_UNKNOW_SCRN))
    {
        return;   
    }
    
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    
    help_info = GetString(STR_ID_UDX_HELP_INFO);
    info_size = mmi_ucs2strlen((const CHAR *) help_info);

    ShowCategory74Screen(
        STR_GLOBAL_HELP,
        GetRootTitleIcon(MENU_ID_UDX_MAIN_MENU),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8 *)help_info,
        info_size,
        gui_buffer);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);    
}


#define MMI_UDX_BUILD
/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_build_file_from_builder
 * DESCRIPTION
 *  entry build
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_builder_build_file_from_builder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*)SRV_FMGR_PATH_ROOT))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    g_mmi_udx_cntx.start_from = MMI_UDX_BUILD_FROM_BUILDER;
    MMI_UDX_LOG1(MMI_UDX_AGENT_START_FROM_SCR, g_mmi_udx_cntx.start_from);

    mmi_udx_builder_entry_data_type_select();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_entry_data_type_select
 * DESCRIPTION
 *  build data type select entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_builder_entry_data_type_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U8 index, count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!mmi_frm_scrn_enter(
              GRP_ID_UDX_MAIN, 
              SCR_ID_UDX_DATA_TYPE_SELECT, 
              NULL, 
              mmi_udx_builder_entry_data_type_select, 
              MMI_FRM_UNKNOW_SCRN))
    {
        return;   
    }
    
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    if (gui_buffer == NULL)
    {
        for (index = 0; index < MMI_UDX_TYPE_TOTAL; index++)
        {
            g_mmi_udx_cntx.data_type_array[count++] = udx_support_type_tbl[index];
        }
    }
    
    RegisterHighlightHandler(mmi_udx_highlight_hdlr);
    
    EnableCenterSoftkey(0, IMG_GLOBAL_MARK_CSK);


    wgui_cat1024_show(
        (WCHAR*) GetString(STR_ID_UDX_BUILD),
        (PU8)GetImage(GetRootTitleIcon(MENU_ID_UDX_MAIN_MENU)),
        (WCHAR*) GetString(STR_GLOBAL_OK),
        (PU8) GetImage(IMG_GLOBAL_OK),
        (WCHAR*) GetString(STR_GLOBAL_BACK),
        (PU8) GetImage(IMG_GLOBAL_BACK),
        NULL,
        MMI_UDX_TYPE_TOTAL,
        mmi_udx_data_type_select_get_item,
        NULL,
        mmi_udx_data_type_select_get_state,
        mmi_udx_data_type_select_set_state,
        IMG_GLOBAL_L1,
        0,
        0,
        gui_buffer);

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback_all(UI_dummy_function);
#endif

    SetLeftSoftkeyFunction(mmi_udx_builder_data_type_select_done, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_udx_data_type_select_check, KEY_EVENT_UP);     
    SetKeyHandler(mmi_udx_data_type_select_check, KEY_ENTER, KEY_EVENT_UP);     
    
#ifndef __MMI_QWERTY_KEYPAD_SUPPORT__
    SetKeyHandler(mmi_udx_data_type_select_check, KEY_STAR, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_data_type_select_done
 * DESCRIPTION
 *  entry build type select done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_builder_data_type_select_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_udx_cntx.udx_agent.type_selected = 0;
    
    for (i = 0; i < MMI_UDX_TYPE_TOTAL; i++)
    {
        if (g_mmi_udx_cntx.data_type_state[i])
        {
            g_mmi_udx_cntx.udx_agent.type_selected |= udx_support_type_tbl[i];
        }
    }

    /* check if any data type selected */
    if (g_mmi_udx_cntx.udx_agent.type_selected == 0)
    {
        mmi_popup_display_simple(
            (WCHAR*)get_string(STR_ID_UDX_NO_DATA_TYPE_SELECTED), 
            MMI_EVENT_FAILURE, 
            GRP_ID_ROOT, 
            NULL);

        return;
    }

    g_mmi_udx_cntx.udx_agent.type_index = 0;
    
    mmi_udx_builder_select_data_record();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_data_type_select_fail
 * DESCRIPTION
 *  entry data select abort
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_builder_data_type_select_fail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_udx_builder_build_file_from_builder();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_entry_fmgr
 * DESCRIPTION
 *  save udx file to filemanager
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_builder_entry_fmgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cui_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_id = cui_folder_selector_create(
                    GRP_ID_UDX_MAIN, 
                    (const WCHAR * )SRV_FMGR_PATH_ROOT, 
                    CUI_FOLDER_SELECTOR_STYLE_WRITE, 
                    CUI_FOLDER_SELECTOR_OPT_FOLDER_TRAVERSE_ALL);

    cui_folder_selector_run(cui_id);

    g_mmi_udx_cntx.fmgr_gid = cui_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_folder_selector_cui_evt_hdlr
 * DESCRIPTION
 *  save udx file to filemanager, select path done
 * PARAMETERS
 *  path            [IN]
 *  is_short        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_builder_folder_selector_cui_evt_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_folder_selector_result_event_struct *evt = 
            (cui_folder_selector_result_event_struct *)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->result > 0)
    {
        cui_folder_selector_get_selected_filepath(
            evt->sender_id, 
            NULL, 
            (WCHAR *) g_mmi_udx_cntx.file_path, 
            (MMI_UDX_MAX_PATH_LENGTH + 1) * ENCODING_LENGTH);
        
        memset(g_mmi_udx_cntx.file_name, 0, (MMI_UDX_MAX_FILENAME_LENGTH + 1) * ENCODING_LENGTH);
        mmi_udx_builder_entry_filename();
    }
    else if (evt->result == 0)
    {
        /* user cancel, need cloase app list cui */
        mmi_udx_builder_app_list_cui_close();
        cui_folder_selector_close(evt->sender_id);
    }
    else
    {
        cui_folder_selector_close(evt->sender_id);
    } 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_entry_filename
 * DESCRIPTION
 *  enter file name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_builder_entry_filename()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_id = cui_filename_editor_create(
                    GRP_ID_UDX_MAIN, 
                    (WCHAR *) g_mmi_udx_cntx.file_name, 
                    sizeof(g_mmi_udx_cntx.file_name),
                    MMI_UDX_MAX_FILENAME_LENGTH, 
                    (const WCHAR *) g_mmi_udx_cntx.file_path, 
                    (const WCHAR *) L"udx");
    
    cui_filename_editor_set_title(cui_id, STR_GLOBAL_FILENAME, GetRootTitleIcon(MENU_ID_UDX_MAIN_MENU));
    
    cui_filename_editor_run(cui_id);

    g_mmi_udx_cntx.filename_gid = cui_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_filename_cui_evt_hdlr
 * DESCRIPTION
 *  enter file name done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_builder_filename_cui_evt_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_filename_editor_result_event_struct *evt = 
            (cui_filename_editor_result_event_struct *)param; 
    U16 str_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->result > 0)
    {
        cui_filename_editor_get_fullpath(
            evt->sender_id, 
            (WCHAR *) g_mmi_udx_cntx.file_path, 
            (MMI_UDX_MAX_PATH_LENGTH + 1) * ENCODING_LENGTH);

        /* processing screen will be hung under GRP_ID_UDX_MAIN */
        mmi_udx_builder_enter_filename_done();
    }
    else if (evt->result == 0)
    {
        /* user cancel, need cloase app list cui */
        mmi_udx_builder_app_list_cui_close();
        cui_filename_editor_close(evt->sender_id);
    }
    else
    {
        if (evt->result == FS_FILE_EXISTS)
        {
            mmi_udx_builder_overwrite_exsiting_file_confirm();
        }
        else
        {
            str_id = srv_fmgr_fs_error_get_string(evt->result);
            mmi_popup_display_simple(
                (WCHAR*)get_string(str_id), 
                MMI_EVENT_FAILURE, 
                GRP_ID_ROOT, 
                NULL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_overwrite_confirm_proc
 * DESCRIPTION
 *  save to fmgr enter filename done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_udx_builder_overwrite_confirm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*)evt;
            switch(alert->result)
            {
                case MMI_ALERT_CNFM_YES:
                    mmi_udx_builder_overwrite_exsiting_file_confirm_yes();
                    break;
                case MMI_ALERT_CNFM_NO:
                    mmi_frm_scrn_close_active_id();
                    break;
                default:
                    break;
            }
        }
        default:
            break;
    }
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_overwrite_exsiting_file_confirm
 * DESCRIPTION
 *  save to fmgr enter filename done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_builder_overwrite_exsiting_file_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);

    arg.callback = mmi_udx_builder_overwrite_confirm_proc;
    arg.parent_id = GRP_ID_UDX_MAIN;
    
    mmi_confirm_display(
        (WCHAR*)get_string(STR_GLOBAL_OVERWRITE_EXISTING_FILE), 
        MMI_EVENT_QUERY, 
        &arg);
    
    SetLeftSoftkeyFunction(mmi_udx_builder_overwrite_exsiting_file_confirm_yes, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_overwrite_exsiting_file_confirm_yes
 * DESCRIPTION
 *  save to fmgr enter filename done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_builder_overwrite_exsiting_file_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* now, the cui id should be filename CUI gid */
    cui_filename_editor_get_fullpath(
            g_mmi_udx_cntx.filename_gid, 
            (WCHAR *) g_mmi_udx_cntx.file_path, 
            (MMI_UDX_MAX_PATH_LENGTH + 1) * ENCODING_LENGTH);

    FS_Delete((WCHAR*)g_mmi_udx_cntx.file_path);
    
    /* processing screen will be hung under GRP_ID_UDX_MAIN */
    mmi_udx_builder_enter_filename_done();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_enter_filename_done
 * DESCRIPTION
 *  save to fmgr enter filename done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_builder_enter_filename_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = UDX_ERR_NO_ERROR;
    FS_HANDLE fh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_mmi_udx_cntx.start_from == MMI_UDX_BUILD_FROM_BUILDER ||
                g_mmi_udx_cntx.start_from == MMI_UDX_BUILD_FROM_OTHER_APP);

    /* creat the file */
    fh = FS_Open((U16*) g_mmi_udx_cntx.file_path, FS_CREATE_ALWAYS | FS_READ_WRITE);
    
    if (fh >= 0)
    {
        FS_Close(fh);
                
        mmi_udx_builder_run(MMI_UDX_BUILDER_HEADER_REQ);
        
        cui_filename_editor_close(g_mmi_udx_cntx.filename_gid);
        cui_folder_selector_close(g_mmi_udx_cntx.fmgr_gid);
    }
    else
    {
        mmi_popup_display_simple(
            (WCHAR*)get_string(srv_fmgr_fs_error_get_string(fh)), 
            MMI_EVENT_FAILURE, 
            GRP_ID_ROOT, 
            NULL);
    }    
}


#define MMI_UDX_PARSE
/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_parse_file_from_parser
 * DESCRIPTION
 *  udx entry parse
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_parser_parse_file_from_parser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    mmi_id cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*)SRV_FMGR_PATH_ROOT))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_UDX);
#if defined(__DRM_V02__)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
#endif /* defined(__DRM_V02__) */
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    cui_id = cui_file_selector_create(
                    GRP_ID_UDX_MAIN,
                    (const WCHAR *) SRV_FMGR_PATH_ROOT,
                    (const FMGR_FILTER *) &filter,
                    CUI_FILE_SELECTOR_STYLE_FILE_ONLY,
                    CUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_ALL);

    cui_file_selector_set_ui_style(cui_id, CUI_FMGR_UI_STYLE_BANNER_LIST);

    cui_file_selector_run(cui_id);

    g_mmi_udx_cntx.fmgr_gid = cui_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_file_selector_cui_evt_hdlr
 * DESCRIPTION
 *  parse select udx file done
 * PARAMETERS
 *  path            [IN]
 *  is_short        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_parser_file_selector_cui_evt_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_file_selector_result_event_struct * evt = 
        (cui_file_selector_result_event_struct *) param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->result > 0)
    {
        cui_file_selector_get_selected_filepath(
            evt->sender_id, 
            NULL, 
            (WCHAR *) g_mmi_udx_cntx.file_path, 
            (MMI_UDX_MAX_PATH_LENGTH + 1) * ENCODING_LENGTH);
        
        /* need to set before use */
        g_mmi_udx_cntx.start_from = MMI_UDX_PARSE_FROM_PARSER;
        
        mmi_udx_parser_entry_parse_option();
    }
    else
    {
        cui_file_selector_close(evt->sender_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_entry_parse_option
 * DESCRIPTION
 *  udx entry parse option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_parser_entry_parse_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_id = cui_menu_create(
                        GRP_ID_UDX_MAIN, 
                        CUI_MENU_SRC_TYPE_RESOURCE, 
                        CUI_MENU_TYPE_APPSUB, 
                        MENU_ID_UDX_PARSE_FILE_SUBMENU, 
                        MMI_FALSE, 
                        NULL);
    
    cui_menu_set_default_title_image(menu_cui_id, (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_UDX_MAIN_MENU)));

    cui_menu_run(menu_cui_id);
    
    g_mmi_udx_cntx.parse_menu_gid = menu_cui_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_entry_view_header_info
 * DESCRIPTION
 *  udx entry file view info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_parser_entry_view_header_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U16 record_temp1[6], record_temp2[12];
    CHAR *h_info = (CHAR *) subMenuData;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!mmi_frm_scrn_enter(
            GRP_ID_UDX_MAIN, 
            SCR_ID_UDX_FILE_VIEW_INFO, 
            NULL, 
            mmi_udx_parser_entry_view_header_info, 
            MMI_FRM_UNKNOW_SCRN))
    {
        return;   
    }
    
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    memset(h_info, 0, 2);
    
    /* vendor info */    
    if (mmi_ucs2strlen((const CHAR *) g_mmi_udx_cntx.udx_agent.header_info.vendor_info))
    {
        mmi_ucs2cat(h_info, GetString(STR_ID_UDX_VENDOR_INFO));
        mmi_ucs2cat(h_info, GetString(STR_ID_UDX_COLON));    
        mmi_ucs2cat(h_info, (CHAR *) L" \n");    
        mmi_ucs2cat(h_info, (const CHAR *) g_mmi_udx_cntx.udx_agent.header_info.vendor_info);        
        mmi_ucs2cat(h_info, (CHAR *)L"\n");
    }

    /* device info */
    if (mmi_ucs2strlen((const CHAR *) g_mmi_udx_cntx.udx_agent.header_info.device_info))
    {
        mmi_ucs2cat(h_info, GetString(STR_ID_UDX_DEVICE_INFO));        
        mmi_ucs2cat(h_info, GetString(STR_ID_UDX_COLON));    
        mmi_ucs2cat(h_info, (CHAR *) L" \n");    
        mmi_ucs2cat(h_info, (const CHAR *) g_mmi_udx_cntx.udx_agent.header_info.device_info);        
        mmi_ucs2cat(h_info, (CHAR *)L"\n");
    }
    
    /* UDX version */    
    if (mmi_ucs2strlen((const CHAR *) g_mmi_udx_cntx.udx_agent.header_info.udx_version))    
    {
        mmi_ucs2cat(h_info, GetString(STR_ID_UDX_UDX_VERSION));        
        mmi_ucs2cat(h_info, GetString(STR_ID_UDX_COLON));    
        mmi_ucs2cat(h_info, (CHAR *) L" \n");    
        mmi_ucs2cat(h_info, (const CHAR *) g_mmi_udx_cntx.udx_agent.header_info.udx_version);        
        mmi_ucs2cat(h_info, (CHAR *)L"\n");
    }
    
    /* user agent */    
    if (mmi_ucs2strlen((const CHAR *) g_mmi_udx_cntx.udx_agent.header_info.user_agent))
    {
        mmi_ucs2cat(h_info, GetString(STR_ID_UDX_USER_AGENT));        
        mmi_ucs2cat(h_info, GetString(STR_ID_UDX_COLON));    
        mmi_ucs2cat(h_info, (CHAR *) L" \n");    
        mmi_ucs2cat(h_info, (const CHAR *) g_mmi_udx_cntx.udx_agent.header_info.user_agent);        
        mmi_ucs2cat(h_info, (CHAR *)L"\n");
    }

    /* user info */    
    if (mmi_ucs2strlen((const CHAR *) g_mmi_udx_cntx.udx_agent.header_info.user_info))
    {
        mmi_ucs2cat(h_info, GetString(STR_ID_UDX_USER_INFO_FROM));        
        mmi_ucs2cat(h_info, GetString(STR_ID_UDX_COLON));    
        mmi_ucs2cat(h_info, (CHAR *) L" \n");    
        mmi_ucs2cat(h_info, (const CHAR *) g_mmi_udx_cntx.udx_agent.header_info.user_info);        
        mmi_ucs2cat(h_info, (CHAR *)L"\n");
    }        
    
    /* date */
    if (mmi_ucs2strlen((const CHAR *) g_mmi_udx_cntx.udx_agent.header_info.date))
    {    
        mmi_ucs2cat(h_info, GetString(STR_GLOBAL_DATE));        
        mmi_ucs2cat(h_info, GetString(STR_ID_UDX_COLON));    
        mmi_ucs2cat(h_info, (CHAR *) L" \n");    
        mmi_ucs2cat(h_info, (const CHAR *) g_mmi_udx_cntx.udx_agent.header_info.date);        
        mmi_ucs2cat(h_info, (CHAR *)L"\n");
    }        

    /* vcard version */    
    if (mmi_ucs2strlen((const CHAR *) g_mmi_udx_cntx.udx_agent.header_info.vcard_version))
    {
        mmi_ucs2cat(h_info, GetString(STR_ID_UDX_VCARD));        
        mmi_ucs2cat(h_info, GetString(STR_ID_UDX_VERSION));
        mmi_ucs2cat(h_info, GetString(STR_ID_UDX_COLON));        
        mmi_ucs2cat(h_info, (CHAR *) L" \n");    
        mmi_ucs2cat(h_info, (const CHAR *) g_mmi_udx_cntx.udx_agent.header_info.vcard_version);
        mmi_ucs2cat(h_info, (CHAR *)L"\n");
    }        

    /* vcard conuts (show always if support) */
    {
        mmi_ucs2cat(h_info, GetString(STR_ID_UDX_VCARD));        
        mmi_ucs2cat(h_info, GetString(STR_ID_UDX_COUNTS));            
        mmi_ucs2cat(h_info, GetString(STR_ID_UDX_COLON));        
        mmi_ucs2cat(h_info, (CHAR *) L" \n");    
        sprintf((CHAR *) record_temp1, "%d", g_mmi_udx_cntx.udx_agent.header_info.vcard_record);
        mmi_asc_to_ucs2((CHAR *) record_temp2, (CHAR *) record_temp1);
        mmi_ucs2cat(h_info, (const CHAR *) record_temp2);            
        mmi_ucs2cat(h_info, (CHAR *)L"\n");
    }
    
    ShowCategory74Screen(
        STR_ID_UDX_FILE_VIEW_INFO,
        GetRootTitleIcon(MENU_ID_UDX_MAIN_MENU), /* IMG_ID_UDX_MAIN_MENU, */
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8 *)h_info,
        mmi_ucs2strlen((const CHAR *) h_info),
        gui_buffer);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_entry_data_type_select
 * DESCRIPTION
 *  parse data type select entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_parser_entry_data_type_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U8 index, count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for (index = 0; index < MMI_UDX_TYPE_TOTAL; index++)
    {
        if (mmi_udx_parser_data_type_exist(udx_support_type_tbl[index]))
        {
            g_mmi_udx_cntx.data_type_array[count++] = udx_support_type_tbl[index];
        }
    }
 
	if (count == 0)
    {
        mmi_popup_display_simple(
            (WCHAR*)get_string(STR_ID_UDX_NO_DATA), 
            MMI_EVENT_WARNING, 
            GRP_ID_ROOT, 
            NULL);
        
        return;
    }
    
    if(!mmi_frm_scrn_enter(
            GRP_ID_UDX_MAIN, 
            SCR_ID_UDX_DATA_TYPE_SELECT, 
            NULL, 
            mmi_udx_parser_entry_data_type_select, 
            MMI_FRM_UNKNOW_SCRN))
    {
        return;   
    }

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    
    RegisterHighlightHandler(mmi_udx_highlight_hdlr);

    if (gui_buffer == NULL)
    {
        memset(&g_mmi_udx_cntx.data_type_state, 0, MMI_UDX_TYPE_TOTAL);
    }

    EnableCenterSoftkey(0, IMG_GLOBAL_MARK_CSK);

    wgui_cat1024_show(
        (WCHAR*) GetString(STR_ID_UDX_PARSE),
        (PU8)GetImage(GetRootTitleIcon(MENU_ID_UDX_MAIN_MENU)),
        (WCHAR*) GetString(STR_GLOBAL_OK),
        (PU8) GetImage(IMG_GLOBAL_OK),
        (WCHAR*) GetString(STR_GLOBAL_BACK),
        (PU8) GetImage(IMG_GLOBAL_BACK),
        NULL,
        MMI_UDX_TYPE_TOTAL,
        mmi_udx_data_type_select_get_item,
        NULL,
        mmi_udx_data_type_select_get_state,
        mmi_udx_data_type_select_set_state,
        IMG_GLOBAL_L1,
        0,
        0,
        gui_buffer);

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback_all(UI_dummy_function);
#endif

    SetLeftSoftkeyFunction(mmi_udx_parser_data_type_select_done, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_udx_parser_data_type_select_done, KEY_EVENT_UP);
    SetKeyHandler(mmi_udx_data_type_select_check, KEY_ENTER, KEY_EVENT_UP);     
    
#ifndef __MMI_QWERTY_KEYPAD_SUPPORT__
    SetKeyHandler(mmi_udx_data_type_select_check, KEY_STAR, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_data_type_exist
 * DESCRIPTION
 *  UDX agent parser check data type of the file to parse
 * PARAMETERS
 *  data_type           [IN]        the data type to check
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_udx_parser_data_type_exist(U8 data_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (data_type)
    {
        case UDX_TYPE_VCARD:
            if (g_mmi_udx_cntx.udx_agent.header_info.vcard_record != 0)
            {
                return MMI_TRUE;
            }
            break;

        case UDX_TYPE_VCALENDAR:
            if (g_mmi_udx_cntx.udx_agent.header_info.vcalendar_record != 0)
            {
                return MMI_TRUE;
            }
            break;
            
        case UDX_TYPE_SMS:
            if (g_mmi_udx_cntx.udx_agent.header_info.sms_record != 0)
            {
                return MMI_TRUE;
            }
            break;
            
        case UDX_TYPE_MMS:
            if (g_mmi_udx_cntx.udx_agent.header_info.mms_record != 0)
            {
                return MMI_TRUE;
            }
            break;
            
        case UDX_TYPE_EMAIL:
            if (g_mmi_udx_cntx.udx_agent.header_info.email_record != 0)
            {
                return MMI_TRUE;
            }
            break;
            
         default:
            MMI_ASSERT(0);
            break;
    } 
	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_data_type_select_done
 * DESCRIPTION
 *  parse data type select done, to parse file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_parser_data_type_select_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_udx_cntx.udx_agent.type_selected = 0;
    
    for (i = 0; i < MMI_UDX_TYPE_TOTAL; i++)
    {
        if (g_mmi_udx_cntx.data_type_state[i] == 1)
        {
            g_mmi_udx_cntx.udx_agent.type_selected |= g_mmi_udx_cntx.data_type_array[i];
        }
    }

    /* check if any data type selected */
    if (g_mmi_udx_cntx.udx_agent.type_selected == 0)
    {
        mmi_popup_display_simple(
            (WCHAR*)get_string(STR_ID_UDX_NO_DATA_TYPE_SELECTED), 
            MMI_EVENT_WARNING, 
            GRP_ID_ROOT, 
            NULL);

        return;
    }

    mmi_udx_parser_run(MMI_UDX_PARSER_BODY_REQ);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_end_show_log
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_parser_end_show_log(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U16 record_temp1[6], record_temp2[12];
    CHAR *parse_log = (CHAR *) subMenuData;
    CHAR *file_name;
    U8 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!mmi_frm_scrn_enter(
            GRP_ID_UDX_MAIN, 
            SCR_ID_UDX_PARSE_LOG, 
            NULL, 
            mmi_udx_parser_end_show_log, 
            MMI_FRM_UNKNOW_SCRN))
    {
        return;   
    }
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    MMI_ASSERT(g_mmi_udx_cntx.udx_agent.type_selected != 0);

    /* show file name */
    mmi_ucs2cpy(parse_log, GetString(STR_GLOBAL_FILENAME));  
    mmi_ucs2cat(parse_log, GetString(STR_ID_UDX_COLON));    
    mmi_ucs2cat(parse_log, (CHAR *) L" \n");

    file_name = (CHAR*)srv_fmgr_path_get_filename_ptr((WCHAR*)g_mmi_udx_cntx.file_path);        
    mmi_ucs2cat(parse_log, file_name);

    mmi_ucs2cat(parse_log, (CHAR *) L" \n");
    mmi_ucs2cat(parse_log, (CHAR *) L"\n");

    for (index = 0; index < MMI_UDX_TYPE_TOTAL; index++)
    {
        if (g_mmi_udx_cntx.udx_agent.type_selected & udx_support_type_tbl[index])
        {
            /*
             *  (Title) Parse log
             *  
             *  file_name
             *
             *  Data_type
             *  Parse: 14
             *  Add: 5
             *  Error: 2
             *
             *  Data_type
             *  Parse: 14
             *  Add: 5
             *  Error: 2
             *  ...
             */
            
            /* Data_type */
            mmi_ucs2cat(parse_log, GetString(udx_support_type_string_tbl[index].data_type_string));
            mmi_ucs2cat(parse_log, (CHAR *) L" \n");

            /* Parse: */
            mmi_ucs2cat(parse_log, GetString(STR_ID_UDX_PARSE_LOG_PARSE));
            mmi_ucs2cat(parse_log, GetString(STR_ID_UDX_COLON));
            sprintf((CHAR *) record_temp1, "%d", g_mmi_udx_cntx.udx_agent.parse_log[index].parse_success_count);
            mmi_asc_to_ucs2((CHAR *) record_temp2, (CHAR *) record_temp1);
            mmi_ucs2cat(parse_log, (const CHAR *) record_temp2);            
            mmi_ucs2cat(parse_log, (CHAR *) L"\n");

            /* Add: */            
            mmi_ucs2cat(parse_log, GetString(STR_GLOBAL_ADD));
            mmi_ucs2cat(parse_log, GetString(STR_ID_UDX_COLON));
            sprintf((CHAR *) record_temp1, "%d", g_mmi_udx_cntx.udx_agent.parse_log[index].store_success_count);
            mmi_asc_to_ucs2((CHAR *) record_temp2, (CHAR *) record_temp1);
            mmi_ucs2cat(parse_log, (const CHAR *) record_temp2);            
            mmi_ucs2cat(parse_log, (CHAR *) L"\n");

            /* Error: */            
            mmi_ucs2cat(parse_log, GetString(STR_GLOBAL_ERROR));
            mmi_ucs2cat(parse_log, GetString(STR_ID_UDX_COLON));
            sprintf((CHAR *) record_temp1,
                    "%d",
                    (g_mmi_udx_cntx.udx_agent.parse_log[index].parse_success_count - g_mmi_udx_cntx.udx_agent.parse_log[index].store_success_count));
            mmi_asc_to_ucs2((CHAR *) record_temp2, (CHAR *) record_temp1);
            mmi_ucs2cat(parse_log, (const CHAR *) record_temp2);            
            mmi_ucs2cat(parse_log, (CHAR *) L"\n");

            /* Next data type */            
            mmi_ucs2cat(parse_log, (CHAR *) L"\n");
        }
    }
    
    ShowCategory74Screen(
        STR_ID_UDX_PARSE_LOG,
        GetRootTitleIcon(MENU_ID_UDX_MAIN_MENU), /* IMG_ID_UDX_MAIN_MENU, */
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8 *)parse_log,
        mmi_ucs2strlen((const CHAR *) parse_log),
        gui_buffer);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);    
}


#define MMI_UDX_BUILD_SEND_BY_BT
#if defined(__MMI_OPP_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_entry_send_way
 * DESCRIPTION
 *  entry send way confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_builder_entry_send_way(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!mmi_frm_scrn_enter(
            GRP_ID_UDX_MAIN, 
            SCR_ID_UDX_SEND_WAY, 
            mmi_udx_builder_exit_send_way, 
            mmi_udx_builder_entry_send_way, 
            MMI_FRM_UNKNOW_SCRN))
    {
        return;   
    }
    
	if (g_mmi_udx_cntx.first_play_tone)
	{
        srv_prof_play_tone(mmi_get_event_based_sound(MMI_EVENT_QUERY), NULL);
		g_mmi_udx_cntx.first_play_tone = MMI_FALSE;
	}

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
    ShowCategory8Screen(
        STR_ID_UDX_MAIN_MENU,
        GetRootTitleIcon(MENU_ID_UDX_MAIN_MENU), /* IMG_ID_UDX_MAIN_MENU, */
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        STR_ID_UDX_SEND_VIA_BLUETOOTH,
        mmi_get_event_based_image(MMI_EVENT_QUERY),
        NULL);

    SetLeftSoftkeyFunction(mmi_udx_builder_entry_send_by_bt, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_udx_builder_entry_send_by_bt, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_exit_send_way
 * DESCRIPTION
 *  exit send way, to stop requset tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_builder_exit_send_way(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_prof_stop_tone(SRV_PROF_TONE_WARNING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_entry_send_by_bt
 * DESCRIPTION
 *  entry send udx via bluetooth opp
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_builder_entry_send_by_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cui_bt_sending_para_struct bt_sending_para;
    cui_bt_sending_obj_struct bt_sedding_obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&bt_sending_para, 0, sizeof(cui_bt_sending_para_struct));
    memset(&bt_sedding_obj, 0, sizeof(cui_bt_sending_obj_struct));

	bt_sending_para.total = 1;
	bt_sending_para.option = CUI_BT_SENDIND_OPT_NORMAL;
    bt_sending_para.obj = &bt_sedding_obj;

    bt_sending_para.obj->data.obj_type = BTSEND_USE_FILE;
    bt_sending_para.obj->data.u.file.is_sfn = MMI_FALSE;
    bt_sending_para.obj->data.u.file.path = (WCHAR *)g_mmi_udx_cntx.file_path;
	
	cui_bt_sending_launch(GRP_ID_UDX_MAIN, &bt_sending_para);

    mmi_frm_scrn_close(GRP_ID_UDX_MAIN, SCR_ID_UDX_SEND_WAY);
}
#endif /* defined(__MMI_OPP_SUPPORT__) */ 


#define MMI_UDX_SCR_UTIL
/*****************************************************************************
 * FUNCTION
 *  mmi_udx_show_processing
 * DESCRIPTION
 *  show processing del callback
 * PARAMETERS
 *  str               [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_show_processing(U16 str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    g_mmi_udx_cntx.info_str = str;
    mmi_udx_entry_show_processing();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_entry_show_processing
 * DESCRIPTION
 *  show processing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_entry_show_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if(!mmi_frm_scrn_enter(
            GRP_ID_UDX_MAIN, 
            SCR_ID_UDX_PROCESSING, 
            NULL, 
            mmi_udx_entry_show_processing, 
            MMI_FRM_UNKNOW_SCRN))
    {
        return;   
    }

    ShowCategory8Screen(
        STR_ID_UDX_MAIN_MENU,
        GetRootTitleIcon(MENU_ID_UDX_MAIN_MENU), /* IMG_ID_UDX_MAIN_MENU, */
        0,
        0,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_BACK,
        g_mmi_udx_cntx.info_str,
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) <= 0)
    {
        ClearInputEventHandler(MMI_DEVICE_KEY);
        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);      

        SetKeyHandler(mmi_udx_processing_abort, KEY_END, KEY_EVENT_DOWN);
    }
    
    SetRightSoftkeyFunction(mmi_udx_processing_abort, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_proccessing_scrn_leave_proc
 * DESCRIPTION
 *  show processing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_udx_proccessing_scrn_leave_proc(mmi_event_struct* event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */                                      
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */                                        
    /*----------------------------------------------------------------*/ 
    if (event->evt_id == EVT_ID_SCRN_DEINIT)
    {
 	    if (g_mmi_udx_cntx.udx_agent.state != MMI_UDX_AGENT_STATE_INIT)
	    {
	        g_mmi_udx_cntx.cancel_by_user = MMI_FALSE;
        
		    if (g_mmi_udx_cntx.start_from <= MMI_UDX_BUILD_FROM_OTHER_APP)
		    {
			    mmi_udx_builder_run(MMI_UDX_BUILDER_ABORT_REQ);
		    }
		    else if (g_mmi_udx_cntx.start_from >= MMI_UDX_PARSE_FROM_FILEMGR)
		    {
			    mmi_udx_parser_run(MMI_UDX_PARSER_ABORT_REQ);
		    }       
	    }       
    }  
    
    return MMI_RET_OK;    
}
    
    
/*****************************************************************************
 * FUNCTION
 *  mmi_udx_update_processing_percentage
 * DESCRIPTION
 *  show processing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_update_processing_percentage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */                                      
    /*----------------------------------------------------------------*/
    S32 percentage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */                                        
    /*----------------------------------------------------------------*/    
    MMI_ASSERT(g_mmi_udx_cntx.udx_agent.state != 0);

    percentage = (g_mmi_udx_cntx.udx_agent.sequence * 100) / g_mmi_udx_cntx.udx_agent.sequence_max;
    
    if (mmi_frm_scrn_get_active_id() == SCR_ID_UDX_PROCESSING_PERCENTAGE)
    {
        if(percentage != g_mmi_udx_cntx.percentage)
        {
            g_mmi_udx_cntx.percentage = percentage;
            UpdateCategory402Value((U16)percentage, NULL);
        }
    }
    else
    {
        g_mmi_udx_cntx.percentage = percentage;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_entry_show_processing_percentage
 * DESCRIPTION
 *  show processing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_entry_show_processing_percentage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!mmi_frm_scrn_enter(
            GRP_ID_UDX_MAIN, 
            SCR_ID_UDX_PROCESSING_PERCENTAGE, 
            NULL, 
            mmi_udx_entry_show_processing_percentage, 
            MMI_FRM_UNKNOW_SCRN))
    {
        return;   
    }
        
    ShowCategory402Screen(
            (U8*) GetString(STR_ID_UDX_MAIN_MENU),
            GetRootTitleIcon(MENU_ID_UDX_MAIN_MENU),
            0,
            0,
            STR_GLOBAL_CANCEL,
            IMG_GLOBAL_BACK,
            (U8*)GetString(g_mmi_udx_cntx.info_str),
            (U16) g_mmi_udx_cntx.percentage,
            NULL);

    mmi_frm_scrn_set_leave_proc(GRP_ID_UDX_MAIN, SCR_ID_UDX_PROCESSING_PERCENTAGE, mmi_udx_proccessing_scrn_leave_proc);

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) <= 0)
    {
        ClearInputEventHandler(MMI_DEVICE_KEY);
        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);      

        SetKeyHandler(mmi_udx_processing_abort, KEY_END, KEY_EVENT_DOWN);
    }
    
    SetRightSoftkeyFunction(mmi_udx_processing_abort, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_processing_abort
 * DESCRIPTION
 *  show aborting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_processing_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 key_code, key_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((g_mmi_udx_cntx.udx_agent.state != 0) || (g_mmi_udx_cntx.udx_agent.state != 0));

    g_mmi_udx_cntx.cancel_by_user = MMI_TRUE;
    
    GetkeyInfo(&key_code, &key_type);

    if (key_code == KEY_END)
    {
        g_mmi_udx_cntx.cancel_by_end_key = MMI_TRUE;
    }

    if (g_mmi_udx_cntx.start_from <= MMI_UDX_BUILD_FROM_OTHER_APP)
    {
        mmi_udx_builder_run(MMI_UDX_BUILDER_ABORT_REQ);
    }
    else if (g_mmi_udx_cntx.start_from >= MMI_UDX_PARSE_FROM_FILEMGR)
    {
        mmi_udx_parser_run(MMI_UDX_PARSER_ABORT_REQ);
    }
    
    mmi_udx_show_aborting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_show_aborting
 * DESCRIPTION
 *  show aborting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_show_aborting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!mmi_frm_scrn_enter(
            GRP_ID_UDX_MAIN, 
            SCR_ID_UDX_ABORTING, 
            NULL, 
            mmi_udx_show_aborting, 
            MMI_FRM_UNKNOW_SCRN))
    {
        return;   
    }
    
#ifdef __MMI_MAINLCD_240X320__
    ShowCategory8Screen(0xffff, 0xffff, 0, 0, 0, 0, STR_GLOBAL_CANCELLING, mmi_get_event_based_image(MMI_EVENT_PROGRESS), NULL);
#else /* __MMI_MAINLCD_240X320__ */ 
    ShowCategory8Screen(
        STR_ID_UDX_MAIN_MENU,
        GetRootTitleIcon(MENU_ID_UDX_MAIN_MENU), /* IMG_ID_UDX_MAIN_MENU, */
        0,
        0,
        0,
        0,
        STR_GLOBAL_CANCELLING,
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);
#endif /* __MMI_MAINLCD_240X320__ */ 

    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_agent_delete_scr
 * DESCRIPTION
 *  delete screen after build done, all abort
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_agent_delete_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_udx_cntx.cancel_by_end_key)
    {
        /* if press endkey, need goback idle screen */
        g_mmi_udx_cntx.cancel_by_end_key = MMI_FALSE;
        mmi_idle_display();
    }
    else
    {
        /* goback to udx main menu */
        mmi_frm_scrn_close(GRP_ID_UDX_MAIN, SCR_ID_UDX_PROCESSING);
        mmi_frm_scrn_close(GRP_ID_UDX_MAIN, SCR_ID_UDX_ABORTING);
        mmi_frm_scrn_close(GRP_ID_UDX_MAIN, SCR_ID_UDX_DATA_TYPE_SELECT);
        mmi_frm_scrn_close(GRP_ID_UDX_MAIN, SCR_ID_UDX_PROCESSING_PERCENTAGE);
        mmi_frm_scrn_close(GRP_ID_UDX_MAIN, SCR_ID_UDX_FILE_VIEW_INFO);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_header_del_scr
 * DESCRIPTION
 *  delete screen after parse done, all abort
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_parser_header_del_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_udx_cntx.cancel_by_end_key)
    {
        g_mmi_udx_cntx.cancel_by_end_key = MMI_FALSE;
        mmi_idle_display();
    }
    else
    {
        mmi_frm_scrn_close(GRP_ID_UDX_MAIN, SCR_ID_UDX_PROCESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_add_bt_confirm_before_cm
 * DESCRIPTION
 *  add send via bluetooth confirm screen to before cm
 * PARAMETERS
 *  scrn_id             [IN]
 *  func_ptr            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_insert_node(U16 scrn_id, udx_func_ptr func_ptr, mmi_scenario_node_flag flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_node_struct new_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_node.id = scrn_id;
    new_node.entry_proc = (mmi_proc_func)func_ptr;

    /* insert the node at group latest */
    mmi_frm_scrn_insert(
        GRP_ID_UDX_MAIN, 
        SCR_ID_UDX_PROCESSING_PERCENTAGE, 
        &new_node, 
        flag);
}


#endif /* __MMI_UDX_SUPPORT__ */
