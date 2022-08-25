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
 *  PhnsetDisplay.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for phone setup menu service interface
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
  *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
#include "MMI_features.h"
/*  Include: MMI header file */
#include "SettingMenuService.h"
#include "PhoneSetup.h"
#include "PhoneSetupGprots.h"
#include "WPSSProtos.h"
#include "Menucuigprot.h"

/* auto add by kw_check begin */
#include "GlobalConstants.h"
#include "MMIDataType.h"
#include "MMI_features.h"
#include "SettingGenum.h"
#include "CustDataRes.h"
#include "mmi_rp_app_phonesetting_new_def.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_general_types.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "mmi_frm_nvram_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "AlertScreen.h"
#include "DebugInitDef_Int.h"
#include "gui_typedef.h"
#include "gui_data_types.h"
#include "MMI_common_app_trc.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "wgui_categories_util.h"
/* auto add by kw_check end */
#include "SettingGprots.h"
#include "SimCtrlSrvGprot.h"
#include "SearchWebGprot.h" /* Google search */
#include "HomeScreenOp11V32Gprot.h"

#ifdef __MMI_VUI_SCREEN_LOCK_KEY__
#include "ScreenLockKeyImageSetting.h"
#include "mmi_rp_app_screen_lock_key_img_setting_def.h"
#endif

#ifdef __MMI_AUTO_KEYPAD_LOCK__
#include "ScrLockerGprot.h"
#include "mmi_rp_app_scr_locker_def.h"
#endif
#include "MMI_ap_dcm_config.h"
#ifdef __MMI_MAINLCD_96X64__
#include "mmi_rp_app_gpio_def.h"
extern void mmi_phset_gpio_entry_backlite_timeout(void);
#endif

/***************************************************************************** 
* Define
*****************************************************************************/
#ifdef __MMI_MOTION_DIAL__
#ifndef PHNSET_MOTION_DIAL_NUM
#define PHNSET_MOTION_DIAL_NUM 2
#endif /* PHNSET_MOTION_DIAL_NUM */

#endif /* __MMI_MOTION_DIAL__ */

#ifdef __MMI_MOTION_MAINMENU__
#ifndef PHNSET_MOTION_MAINMENU_NUM
#define PHNSET_MOTION_MAINMENU_NUM 2
#endif /* PHNSET_MOTION_DIAL_NUM */
#endif /* __MMI_MOTION_MAINMENU__ */

/***************************************************************************** 
* Typedef
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern PHNSET_CNTX *g_phnset_cntx_p;
extern PU8 subMenuDataPtrs[MAX_SUB_MENUS];

/***************************************************************************** 
* External Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/

/***************************************************************************** 
* External Function
*****************************************************************************/

/*****************************************************************************
* Local Function 
*****************************************************************************/
/* Phone Setup Display */

/* Display -> Main Menu Style */
#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
static U8 PhnsetMainMenuStyleList(U8** pMainMenuStyleList, U16 total_style);
static void EntryPhnsetMainMenuStyle(MMI_ID parent_gid);
static void PhnsetMainMenuStyleSelectLskHdlr(U8 highlight_item);
static mmi_ret mmi_phnset_main_menu_style_proc(mmi_event_struct *param);
static void mmi_phnset_init_main_menu_style_list(void);
#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */

/* Display -> Dial Style */
#ifdef __MMI_MOTION_DIAL__
static U8 PhnsetDialStyleList(U8** pMainMenuStyleList, U16 total_style);
static void EntryPhnsetDialStyle(MMI_ID parent_gid);
static void PhnsetDialStyleSelectLskHdlr(U8 highlight_item);
static void mmi_phnset_init_dial_style_list(void);
static mmi_ret mmi_phnset_dial_style_proc(mmi_event_struct *param);
#endif /* __MMI_MOTION_DIAL__ */




/* Display -> VUI Main Menu Effect */
#ifdef __MMI_VUI_MAINMENU__
static void mmi_entry_phnset_vui_mainmenu_effect(MMI_ID parent_gid);
static mmi_ret mmi_phnset_set_vui_mainmenu_effect_proc(mmi_event_struct *param);
static void mmi_phnset_init_set_vui_mainmenu_effect_list(void);
#endif /* __MMI_VUI_MAINMENU__ */

/* Display -> Calendar In Idle */
#if 0
#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
#endif
/* Display -> Dual Clock In Idle */
#ifdef __MMI_DUAL_CLOCK__
static void mmi_phnset_entry_dual_clock_idle_screen(MMI_ID parent_gid);
static mmi_ret mmi_phnset_dual_clock_idle_screen_proc(mmi_event_struct *param);
static void mmi_phnset_dual_clock_idle_screen_select_handler(mmi_event_struct *param);
#endif

/* Display -> Operator HomeScreen */
#if 0
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__) */
#endif
/* Display -> Operator ToolBar */

/* Display -> Show Date And Time In Idle */
static void mmi_phnset_entry_show_date_time(MMI_ID parent_gid);
static mmi_ret mmi_phnset_show_date_time_proc(mmi_event_struct *param);
static void mmi_phnset_show_date_time_select_handler(mmi_event_struct *param);

/* Display -> Show Operator Name In Idle */
#if 0
#ifdef __MMI_OPERATOR_NAME_MENU__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
/* Display -> Clock Type In Idle */
#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
static void EntryPhnsetIdleClockType(MMI_ID parent_gid);
static mmi_ret mmi_phnset_idle_clock_type_proc(mmi_event_struct *param);
static void mmi_phnset_init_idle_clock_type_list(void);
#endif

/* Display -> Screen Switch Effect */
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
static void EntryPhnsetScreenSwitchEffectScreen(MMI_ID parent_gid);
static void PhnsetScreenSwitchEffectHandler(U8 highlighted_item);
static mmi_ret mmi_phnset_screen_switch_effect_proc(mmi_event_struct *param);
static void mmi_phnset_init_screen_switch_effect_list(void);
#endif
#ifdef __MMI_IDLE_SCREEN_OWNER_NUMBER__
static void mmi_phnset_show_owner_number_entry(mmi_id parent_gid, U16 highlight_id);
static mmi_ret mmi_phnset_show_owner_number_proc(mmi_event_struct *param);
static void mmi_phnset_show_owner_number_set_status(U8 highlight_id);
static void mmi_phnset_show_owner_number_hint_handler(void);
#endif
static mmi_ret mmi_phnset_disp_setup_sub_menu_init(void);
static mmi_ret mmi_phnset_disp_setup_sub_menu_entry_handler(cui_menu_event_struct *param);
#ifndef __MMI_PHNSET_SLIM__    
static mmi_ret mmi_phnset_disp_setup_sub_menu_highlight_handler(cui_menu_event_struct *param);
#endif
static mmi_ret mmi_phnset_disp_setup_sub_menu_select_handler(cui_menu_event_struct *param, MMI_ID parent_gid);


#ifdef __MMI_BT_BOX_TEST_DIALER_PAD_STYLE__ 
static void mmi_phnset_init_screen_btbox_dialer_type_list(MMI_ID cui_gid);
void PhnsetSetBtBoxDialerTypeStatus(mmi_phnset_BT_BOX_TYPE_enum status);
static void PhnsetBtBoxDialerTypeHandler(U8 highlighted_item);
mmi_ret mmi_phnset_btbox_dialer_type_proc(mmi_event_struct *param);
static void EntryBtBoxDialerType(void);
void HighlightBtBoxDialerType(void);

//for picker test
static void mmi_phnset_init_screen_btbox_picker_type_list(MMI_ID cui_gid);
void PhnsetSetBtBoxPickerTypeStatus(mmi_phnset_BT_BOX_Picker_TYPE_enum status);
static void PhnsetBtBoxPickerTypeHandler(U8 highlighted_item);
mmi_ret mmi_phnset_btbox_picker_type_proc(mmi_event_struct *param);
static void EntryBtBoxPickerType(void);
void HighlightBtBoxPickerType(void);

#endif  //__MMI_BT_BOX_TEST_DIALER_PAD_STYLE__
/* main menu style and motion main menu */
#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  HintPhnsetMainMenuStyle
 * DESCRIPTION
 *  This function is Hint handler for Phone setup-> Display --> Main menu style
 *  Follow functions:
 * PARAMETERS
 *  index       [IN]            
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void HintPhnsetMainMenuStyle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* p = NULL;
    U8 style = PhnsetGetMainMenuStyle();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (style)
    {
    #ifdef __MMI_MAINMENU_MATRIX_SUPPORT__  /* 071705 Calvin added */
        case PHNSET_MAINMENU_STYLE_MATRIX:
            p = GetString(STR_MAINMENU_STYLE_MATRIX);
            break;
    #endif /* __MMI_MAINMENU_MATRIX_SUPPORT__ */ 

    #ifdef __MMI_MAINMENU_PAGE_SUPPORT__    /* 071705 Calvin added */
        case PHNSET_MAINMENU_STYLE_PAGE:
            p = GetString(STR_MAINMENU_STYLE_PAGE);
            break;
    #endif /* __MMI_MAINMENU_PAGE_SUPPORT__ */ 

    #ifdef __MMI_MAINMENU_LIST_SUPPORT__    /* 071705 Calvin added */
        case PHNSET_MAINMENU_STYLE_LIST:
            p = GetString(STR_MAINMENU_STYLE_LIST);
            break;
    #endif /* __MMI_MAINMENU_LIST_SUPPORT__ */ 

    #ifdef __MMI_MAINMENU_CIRCULAR_SUPPORT__        /* 071705 Calvin modified */
        case PHNSET_MAINMENU_STYLE_CIRCULE:
            p = GetString(STR_MAINMENU_STYLE_CIRCULAR);
            break;
    #endif /* __MMI_MAINMENU_CIRCULAR_SUPPORT__ */ 

    #ifdef __MMI_MAINMENU_ROTATE_SUPPORT__
        case PHNSET_MAINMENU_STYLE_ROTATE:
            p = GetString(STR_MAINMENU_STYLE_ROTATE);   /* PDG1   Manish */
            break;
    #endif /* __MMI_MAINMENU_ROTATE_SUPPORT__ */ 

    #ifdef __MMI_MOTION_MAINMENU__
        case PHNSET_MAINMENU_STYLE_MOTION:
            {
                U16 motion_style = 0;
                
                motion_style = (U16)(g_phnset_cntx_p->MenuStyle - PHNSET_MAINMENU_STYLE_MOTION);

                switch(motion_style)
                {
                case 0:
                    p = GetString(STR_ID_PHNSET_MOTION_MAINMENU_1);
                    break;
                    
                case 1:
                    p = GetString(STR_ID_PHNSET_MOTION_MAINMENU_2);
                    break;
                    
                case 2:
                    p = GetString(STR_ID_PHNSET_MOTION_MAINMENU_3);
                    break;
                    
                case 3:
                    p = GetString(STR_ID_PHNSET_MOTION_MAINMENU_4);
                    break;
                    
                case 4:
                    p = GetString(STR_ID_PHNSET_MOTION_MAINMENU_5);
                    break;
                    
                default:
                    p = GetString(STR_GLOBAL_EMPTY);
                    break;
                }
            }
            break;
    #endif /* __MMI_MOTION_MAINMENU__ */

        default:
            {
                p = GetString(STR_GLOBAL_EMPTY);
            }
            break;
    }

    cui_menu_set_item_hint(
        mmi_frm_group_get_active_id(),
        MENU_SETTING_MAINMENU_STYLE,
        (WCHAR*)p);

}


/*****************************************************************************
 * FUNCTION
 *  PhnsetMainMenuStyleList
 * DESCRIPTION
 *  This function is construct string list for Phone setup->IdleScreenDisplay --> Main Menu Style
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
static U8 PhnsetMainMenuStyleList(U8** pMainMenuStyleList, U16 total_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U16 comm_style_str_id[12] = {0};
    U8 style_count = 0; /* count of style string */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MAINMENU_MATRIX_SUPPORT__
    comm_style_str_id[0] = STR_MAINMENU_STYLE_MATRIX;
#endif 

#ifdef __MMI_MAINMENU_PAGE_SUPPORT__
    comm_style_str_id[1] = STR_MAINMENU_STYLE_PAGE;
#endif 

#ifdef __MMI_MAINMENU_LIST_SUPPORT__
    comm_style_str_id[2] = STR_MAINMENU_STYLE_LIST;
#endif 

#ifdef __MMI_MAINMENU_CIRCULAR_SUPPORT__
    comm_style_str_id[3] = STR_MAINMENU_STYLE_CIRCULAR;
#endif 

#ifdef __MMI_MAINMENU_ROTATE_SUPPORT__
    comm_style_str_id[4] = STR_MAINMENU_STYLE_ROTATE;
#endif 

    /* set common style string */
    for (i = 0; i < 6; i++)
    {
        if (comm_style_str_id[i] != 0)
        {
            pMainMenuStyleList[style_count] = (U8*)GetString(comm_style_str_id[i]);
            style_count++;
        }
    }

#ifdef __MMI_MOTION_MAINMENU__
    /* set motion style string */
    for (i = 0; i < PHNSET_MOTION_MAINMENU_NUM; i++)
    {
        switch(i)
        {
        case 0:
            pMainMenuStyleList[style_count] = (U8*)GetString(STR_ID_PHNSET_MOTION_MAINMENU_1);
            break;
            
        case 1:
            pMainMenuStyleList[style_count] = (U8*)GetString(STR_ID_PHNSET_MOTION_MAINMENU_2);
            break;
            
        case 2:
            pMainMenuStyleList[style_count] = (U8*)GetString(STR_ID_PHNSET_MOTION_MAINMENU_3);
            break;
            
        case 3:
            pMainMenuStyleList[style_count] = (U8*)GetString(STR_ID_PHNSET_MOTION_MAINMENU_4);
            break;
            
        case 4:
            pMainMenuStyleList[style_count] = (U8*)GetString(STR_ID_PHNSET_MOTION_MAINMENU_5);
            break;
            
        default:
            pMainMenuStyleList[style_count] = (U8*)GetString(STR_GLOBAL_EMPTY);
            break;
        }
        
        style_count++;
    }

#endif /* __MMI_MOTION_MAINMENU__ */

    return style_count;

}


/*****************************************************************************
 * FUNCTION
 *  EntryPhnsetMainMenuStyle
 * DESCRIPTION
 *  This function is Entry function for Phone setup->IdleScreenDisplay --> Main Menu Style
 *  Following functions: HighlightPhnsetMainMenuStyleSelect
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void EntryPhnsetMainMenuStyle(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phnset_appcreate_menucui_create(
        parent_gid,
        GRP_ID_PHNSET_MAINMENU_STYLE,
        MENU_SETTING_MAINMENU_STYLE,
        mmi_phnset_main_menu_style_proc);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_main_menu_style_proc
 * DESCRIPTION
 *  Menu CUI proc function formmi_phnset_main_menu_style 
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_phnset_main_menu_style_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        mmi_phnset_init_main_menu_style_list();
        break;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
        PhnsetMainMenuStyleSelectLskHdlr((U8)((cui_menu_event_struct*)param)->highlighted_menu_id);
        break;
        
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(mmi_frm_group_get_active_id());
        break;
        
    case EVT_ID_GROUP_DEINIT:
        if (param->user_data)
    	{
    	    OslMfree(param->user_data);
    	}
        break;
    default:
		break;
    }
    return MMI_RET_OK;
}
 
 
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_init_main_menu_style_list
 * DESCRIPTION
 *  Initialize the main menu style setting menu list 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phnset_init_main_menu_style_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phnset_radio_button_menu_data_struct radio_button_menu;
    U8 nNumofItem;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Retrieve no of child of menu item to be displayed */
#ifdef __MMI_MOTION_MAINMENU__
    nNumofItem = PHNSET_MAINMENU_STYLE_MOTION + PHNSET_MOTION_MAINMENU_NUM;  /* Yvonne provide this marco */
#else   /* __MMI_MOTION_MAINMENU__ */
    nNumofItem = PHNSET_MAINMENU_STYLE_MAX;
#endif  /* __MMI_MOTION_MAINMENU__ */

    PhnsetMainMenuStyleList(subMenuDataPtrs, nNumofItem);

    radio_button_menu.group_id = GRP_ID_PHNSET_MAINMENU_STYLE;
    radio_button_menu.menu_title_str_id = STR_MAINMENU_STYLE;
    radio_button_menu.menu_icon_id = MAIN_MENU_TITLE_SETTINGS_ICON;
    radio_button_menu.menu_item_num = nNumofItem;
    radio_button_menu.menu_item_str_list = subMenuDataPtrs;
    radio_button_menu.menu_item_str_id_list = NULL;
    radio_button_menu.highlighted_item_idx = g_phnset_cntx_p->MenuStyle;

    mmi_phnset_init_radio_button_menu(&radio_button_menu);
    
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
/*****************************************************************************
 * FUNCTION
 *  PhnsetMainMenuStyleSelectLskHdlr
 * DESCRIPTION
 *  This function is left softkey handling function
 *  for Phonesetup->IdleScreenDisplay -> MainMenu style -> Select
 *  Functionality: Save the setting menu style
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void PhnsetMainMenuStyleSelectLskHdlr(U8 highlight_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S16 Err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_phnset_cntx_p->MenuStyle != highlight_item)
    {
        g_phnset_cntx_p->MenuStyle = highlight_item;
        //WriteValue(NVRAM_SET_MAINMENU_STYLE, &(g_phnset_cntx_p->MenuStyle), DS_BYTE, &Err);
		WriteValueSlim(NVRAM_SET_MAINMENU_STYLE, &(g_phnset_cntx_p->MenuStyle), DS_BYTE);
    }

    mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
    mmi_frm_group_close(GRP_ID_PHNSET_MAINMENU_STYLE);
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetGetMainMenuStyle
 * DESCRIPTION
 *  This function is to get setting main menu style
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
U8 PhnsetGetMainMenuStyle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MOTION_MAINMENU__
    if (g_phnset_cntx_p->MenuStyle >= PHNSET_MAINMENU_STYLE_MOTION)
    {
        return PHNSET_MAINMENU_STYLE_MOTION;
    }
#endif  /* __MMI_MOTION_MAINMENU__ */

    return g_phnset_cntx_p->MenuStyle;
}


#ifdef __MMI_MOTION_MAINMENU__
/*****************************************************************************
 * FUNCTION
 *  GetMainMenuMotionStyle
 * DESCRIPTION
 *  This function is to get content id of motion style
 * PARAMETERS
 *  void           
 * RETURNS
 *  U16
 *****************************************************************************/
U16 GetMainMenuMotionStyle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_phnset_cntx_p->MenuStyle >= PHNSET_MAINMENU_STYLE_MOTION) 
        && ((g_phnset_cntx_p->MenuStyle - PHNSET_MAINMENU_STYLE_MOTION) < PHNSET_MOTION_MAINMENU_NUM))
    {
        U16 motion_img_id;

        motion_img_id = (U16)(g_phnset_cntx_p->MenuStyle - PHNSET_MAINMENU_STYLE_MOTION);

        switch(motion_img_id)
        {
        case 0:
            return IMG_ID_SWFLASH_MAINMENU1;
            break;

        case 1:
            return IMG_ID_SWFLASH_MAINMENU2;
            break;

        case 2:
            return IMG_ID_SWFLASH_MAINMENU3;
            break;

        case 3:
            return IMG_ID_SWFLASH_MAINMENU3;
            break;

        case 4:
            return IMG_ID_SWFLASH_MAINMENU4;
            break;

        default:
            return 0;
            break;
        }
    }

    return 0;
}
#endif /* __MMI_MOTION_MAINMENU__ */
#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */ 
/* main menu style and motion main menu */


/* motion dial style */
#ifdef __MMI_MOTION_DIAL__


/*****************************************************************************
 * FUNCTION
 *  HintPhnsetDialStyle
 * DESCRIPTION
 *  This function is Hint handler for Phone setup->IdleScreenDisplay --> Dial style
 *  Follow functions:
 * PARAMETERS
 *  index       [IN]                      
 * RETURNS
 *  void
 *****************************************************************************/
void HintPhnsetDialStyle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phnset_cntx_p->DialStyle < PHNSET_MOTION_DIAL_NUM)
    {
        switch(g_phnset_cntx_p->DialStyle)
        {
        case 0:
            p = GetString(STR_ID_PHNSET_MOTION_DIAL_1);
        	break;

        case 1:
            p = GetString(STR_ID_PHNSET_MOTION_DIAL_2);
        	break;

        case 2:
            p = GetString(STR_ID_PHNSET_MOTION_DIAL_3);
            break;

        case 3:
            p = GetString(STR_ID_PHNSET_MOTION_DIAL_4);
            break;

        case 4:
            p = GetString(STR_ID_PHNSET_MOTION_DIAL_5);
            break;    

        default:
            p = GetString(STR_GLOBAL_EMPTY);
            break;
        }
    }
    else
    {
        p = GetString(STR_GLOBAL_EMPTY);
    }
    cui_menu_set_item_hint(
        mmi_frm_group_get_active_id(),
        MENU_SETTING_DIAL_STYLE,
        (WCHAR*)p);

}


/*****************************************************************************
 * FUNCTION
 *  PhnsetDialStyleList
 * DESCRIPTION
 *  This function is construct string list for Phone setup->IdleScreenDisplay --> Dial Style
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 PhnsetDialStyleList(U8** pMainMenuStyleList, U16 total_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < total_style; i++)
    {
        switch(i)
        {
        case 0:
            pMainMenuStyleList[i] = (U8*)GetString(STR_ID_PHNSET_MOTION_DIAL_1);
            break;
            
        case 1:
            pMainMenuStyleList[i] = (U8*)GetString(STR_ID_PHNSET_MOTION_DIAL_2);
            break;
            
        case 2:
            pMainMenuStyleList[i] = (U8*)GetString(STR_ID_PHNSET_MOTION_DIAL_3);
            break;
            
        case 3:
            pMainMenuStyleList[i] = (U8*)GetString(STR_ID_PHNSET_MOTION_DIAL_4);
            break;
            
        case 4:
            pMainMenuStyleList[i] = (U8*)GetString(STR_ID_PHNSET_MOTION_DIAL_5);
            break;    
            
        default:
            pMainMenuStyleList[i] = (U8*)GetString(STR_GLOBAL_EMPTY);
            break;
        }
    }

    return i;

}


/*****************************************************************************
 * FUNCTION
 *  EntryPhnsetDialStyle
 * DESCRIPTION
 *  This function is Entry function for Phone setup->IdleScreenDisplay --> Dial Style
 *  Following functions: HighlightPhnsetDialStyle
 * PARAMETERS
 *  void           
 * RETURNS
 *  void
 *****************************************************************************/
static void EntryPhnsetDialStyle(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        mmi_phnset_appcreate_menucui_create(
        parent_gid,
        GRP_ID_PHNSET_DIAL_STYLE,
        MENU_SETTING_DIAL_STYLE,
        mmi_phnset_dial_style_proc);
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetDialStyleSelectLskHdlr
 * DESCRIPTION
 *  This function is left soft key handling function
 *  for Phone setup->IdleScreenDisplay -> Dial style -> Select
 *  Functionality: Save the setting dial style
 * PARAMETERS
 *  void           
 * RETURNS
 *  void
 *****************************************************************************/
static void PhnsetDialStyleSelectLskHdlr(U8 highlight_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S16 Err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    highlight_item = (U8) GetHighlightedItem();

    if (g_phnset_cntx_p->DialStyle != highlight_item)
    {
        g_phnset_cntx_p->DialStyle = highlight_item;
        //WriteValue(NVRAM_SET_DIAL_STYLE, &(g_phnset_cntx_p->DialStyle), DS_BYTE, &Err);
		WriteValueSlim(NVRAM_SET_DIAL_STYLE, &(g_phnset_cntx_p->DialStyle), DS_BYTE);
    }

    mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
    mmi_frm_group_close(GRP_ID_PHNSET_DIAL_STYLE);
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetGetDialStyle
 * DESCRIPTION
 *  This function is to get value of dial motion style
 * PARAMETERS
 *  void           
 * RETURNS
 *  U16
 *****************************************************************************/
U16 PhnsetGetDialStyle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_phnset_cntx_p->DialStyle)
    {
    case 0:
        return IMG_ID_SWFLASH_DIALER1;
    	break;

    case 1:
        return IMG_ID_SWFLASH_DIALER2;
    	break;

    case 2:
        return IMG_ID_SWFLASH_DIALER3;
        break;

    case 3:
        return IMG_ID_SWFLASH_DIALER4;
        break;

    case 4:
        return IMG_ID_SWFLASH_DIALER5;
        break;

    default:
        return 0;
        break;
    }
    
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_dial_style_proc
 * DESCRIPTION
 *  Proc function for mmi_phnset_dial_style 
 * PARAMETERS
 *  param   [IN]
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phnset_dial_style_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch (param->evt_id)
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        mmi_phnset_init_dial_style_list();
        break;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
        PhnsetDialStyleSelectLskHdlr((U8)((cui_menu_event_struct*)param)->highlighted_menu_id);
        break;
        
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(mmi_frm_group_get_active_id());
        break;
        
    case EVT_ID_GROUP_DEINIT:
        if (param->user_data)
    	{
    	    OslMfree(param->user_data);
    	}
        break;
    default:
		break;
    }
    return MMI_RET_OK;  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_init_dial_style_list
 * DESCRIPTION
 *  Initialize dial style setting menu list 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phnset_init_dial_style_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phnset_radio_button_menu_data_struct radio_button_menu;
    U8 nNumofItem = PHNSET_MOTION_DIAL_NUM;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PhnsetDialStyleList(subMenuDataPtrs, nNumofItem);

    radio_button_menu.group_id = MENU_SETTING_DIAL_STYLE;
    radio_button_menu.menu_title_str_id = STR_ID_PHNSET_DIAL_STYLE;
    radio_button_menu.menu_icon_id = MAIN_MENU_TITLE_SETTINGS_ICON;
    radio_button_menu.menu_item_num = nNumofItem;
    radio_button_menu.menu_item_str_list = subMenuDataPtrs;
    radio_button_menu.menu_item_str_id_list = NULL;
    radio_button_menu.highlighted_item_idx = g_phnset_cntx_p->DialStyle;

    mmi_phnset_init_radio_button_menu(&radio_button_menu);    
}
#endif  /* __MMI_MOTION_DIAL__ */
/* motion dial style */




/* VUI Main menu effect */
#ifdef __MMI_VUI_MAINMENU__
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_get_vui_mm_effect_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_phnset_get_vui_mm_effect_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return g_phnset_cntx_p->vui_mm_effect;
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_hint_phnset_vui_mainmenu_effect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hint_phnset_vui_mainmenu_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* hint_str = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_phnset_cntx_p->vui_mm_effect)
    {
        case 0:
            hint_str = (CHAR*) GetString(STR_ID_VUI_PHNSET_MAINMENU_EFFECT1);
            break;

        case 1:
            hint_str = (CHAR*) GetString(STR_ID_VUI_PHNSET_MAINMENU_EFFECT2);
            break;
            
        case 2:
            hint_str = (CHAR*) GetString(STR_ID_VUI_PHNSET_MAINMENU_EFFECT3);
            break;
                
        case 3:
            hint_str = (CHAR*) GetString(STR_ID_VUI_PHNSET_MAINMENU_EFFECT4);
            break;
            
		case 4:
			hint_str = (CHAR*) GetString(STR_ID_VUI_PHNSET_MAINMENU_EFFECT5);
            break;

		case 5:
			hint_str = (CHAR*) GetString(STR_GLOBAL_NONE);
            break;
            
        default:
            MMI_ASSERT(0);
    }
    cui_menu_set_item_hint(
        mmi_frm_group_get_active_id(),
        MENU_ID_VUI_PHNSET_MAINMENU_EFFECT,
        (WCHAR*)hint_str);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_set_vui_mainmenu_effect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_set_vui_mainmenu_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //WriteValue(NVRAM_VUI_PHNSET_MAINMENU_EFFECT, &(g_phnset_cntx_p->vui_mm_effect), DS_BYTE, &error);
	WriteValueSlim(NVRAM_VUI_PHNSET_MAINMENU_EFFECT, &(g_phnset_cntx_p->vui_mm_effect), DS_BYTE);
    
    mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
    
    mmi_frm_group_close(GRP_ID_PHNSET_VUI_MAINMENU_EFFECT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_entry_phnset_vui_mainmenu_effect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_entry_phnset_vui_mainmenu_effect(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phnset_appcreate_menucui_create(
        parent_gid,
        GRP_ID_PHNSET_VUI_MAINMENU_EFFECT,
        MENU_ID_VUI_PHNSET_MAINMENU_EFFECT,
        mmi_phnset_set_vui_mainmenu_effect_proc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_set_vui_mainmenu_effect_proc
 * DESCRIPTION
 *  Menu CUI proc function formmi_phnset_set_vui_mainmenu_effect 
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_phnset_set_vui_mainmenu_effect_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        mmi_phnset_init_set_vui_mainmenu_effect_list();
        break;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
        g_phnset_cntx_p->vui_mm_effect = (U8)((cui_menu_event_struct*)param)->highlighted_menu_id; 
        mmi_phnset_set_vui_mainmenu_effect();
        break;
        
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(mmi_frm_group_get_active_id());
        break;
        
    case EVT_ID_GROUP_DEINIT:
        if (param->user_data)
    	{
    	    OslMfree(param->user_data);
    	}
        break;
    default:
		break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_init_set_vui_mainmenu_effect_list
 * DESCRIPTION
 *  Initialize set VUI mainmenu effect menu list 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_init_set_vui_mainmenu_effect_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phnset_radio_button_menu_data_struct radio_button_menu;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    subMenuDataPtrs[0] = (PU8) GetString(STR_ID_VUI_PHNSET_MAINMENU_EFFECT1);
    subMenuDataPtrs[1] = (PU8) GetString(STR_ID_VUI_PHNSET_MAINMENU_EFFECT2);
    subMenuDataPtrs[2] = (PU8) GetString(STR_ID_VUI_PHNSET_MAINMENU_EFFECT3);
    subMenuDataPtrs[3] = (PU8) GetString(STR_ID_VUI_PHNSET_MAINMENU_EFFECT4);
	subMenuDataPtrs[4] = (PU8) GetString(STR_ID_VUI_PHNSET_MAINMENU_EFFECT5);
	subMenuDataPtrs[5] = (PU8) GetString(STR_GLOBAL_NONE);

    radio_button_menu.group_id = GRP_ID_PHNSET_VUI_MAINMENU_EFFECT;
    radio_button_menu.menu_title_str_id = STR_ID_VUI_PHNSET_MAINMENU_EFFECT;
    radio_button_menu.menu_icon_id = MAIN_MENU_TITLE_SETTINGS_ICON;
    radio_button_menu.menu_item_num = 6;
    radio_button_menu.menu_item_str_list = subMenuDataPtrs;
    radio_button_menu.menu_item_str_id_list = NULL;
    radio_button_menu.highlighted_item_idx = g_phnset_cntx_p->vui_mm_effect;

    mmi_phnset_init_radio_button_menu(&radio_button_menu);
    
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
#endif /* __MMI_VUI_MAINMENU__ */
/* VUI Main menu effect */

#if 0
/* under construction !*/
#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
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
#ifdef __MMI_AP_DCM_SETTING__
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
#ifdef __MMI_AP_DCM_SETTING__
/* under construction !*/
#endif
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
/* under construction !*/
#endif

/* dual clock in idle */
#ifdef __MMI_DUAL_CLOCK__

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  HighlightPhnsetDualClockIdleScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HintPhnsetDualClockIdleScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     mmi_id hint_str;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PhnsetGetDualClockState())
    {
        g_phnset_cntx_p->curDualClockStatus = 1; 
        hint_str = STR_GLOBAL_ON;
    }
    else
    {
        g_phnset_cntx_p->curDualClockStatus = 0; 
        hint_str = STR_GLOBAL_OFF;
    }
    cui_menu_set_item_hint(
        mmi_frm_group_get_active_id(),
        MENU_ID_PHNSET_DUAL_CLOCK_IDLESCREEN,
        (WCHAR*)GetString(hint_str));
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
/*****************************************************************************
 * FUNCTION
 *  PhnsetGetDualClockState
 * DESCRIPTION
 *    
 * PARAMETERS
 *  void
 * RETURNS
 *  current calendar screen status
 *****************************************************************************/
U8 PhnsetGetDualClockState(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WC_TZ_SUPPORT__    
    return g_phnset_cntx_p->curDualClockStatus;
#else
	/* if not support world clock time zone user can't set foreign city and dual clock */
    return 0;	
#endif
}
#if 0
/* under construction !*/
#endif
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_entry_dual_clock_idle_screen
 * DESCRIPTION
 *  Entry show dual clock idle screen setting menu 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_entry_dual_clock_idle_screen(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phnset_appcreate_menucui_create(
        parent_gid,
        GRP_ID_PHNSET_DUAL_CLOCK_IDLESCREEN,
        MENU_ID_PHNSET_DUAL_CLOCK_IDLESCREEN,
        mmi_phnset_dual_clock_idle_screen_proc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_dual_clock_idle_screen_proc
 * DESCRIPTION
 *  Proc function for dual clock idle screen setting menu 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phnset_dual_clock_idle_screen_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        mmi_phnset_init_on_off_radio_button_menu(
            GRP_ID_PHNSET_CALENDAR_IDLESCREEN,
            STR_ID_PHNSET_DUAL_CLOCK_SCREEN,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            g_phnset_cntx_p->curDualClockStatus);
        return MMI_RET_OK;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
        mmi_phnset_dual_clock_idle_screen_select_handler(param);
        return MMI_RET_OK;
        
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(mmi_frm_group_get_active_id());
		return MMI_RET_OK;
		
    default:
		break;
    }
    return MMI_RET_OK;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_dual_clock_idle_screen_select_handler
 * DESCRIPTION
 *  Select handler for dual clock idle screen setting menu 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_dual_clock_idle_screen_select_handler(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menucui_param = (cui_menu_event_struct*)param;
    //S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_cntx_p->curDualClockStatus = (U8)menucui_param->highlighted_menu_id;
    //WriteValue(NVRAM_SET_DUALCLOCK_IDLESCREEN, &(g_phnset_cntx_p->curDualClockStatus), DS_BYTE, &error);
	WriteValueSlim(NVRAM_SET_DUALCLOCK_IDLESCREEN, &(g_phnset_cntx_p->curDualClockStatus), DS_BYTE);
    mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);    
    mmi_frm_group_close(GRP_ID_PHNSET_DUAL_CLOCK_IDLESCREEN);    
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
#if 0
/* under construction !*/
#endif
#endif /* __MMI_DUAL_CLOCK__ */
/* dual clock in idle */

#if 0
/* under construction !*/
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__)
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
#ifdef __MMI_AP_DCM_SETTING__
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
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)        
/* under construction !*/
#endif
/* under construction !*/
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
#endif
/* under construction !*/
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
#endif /* No need to set highlight in menu cui -- Cong Zhou 1013 */
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
#ifdef __MMI_AP_DCM_SETTING__
/* under construction !*/
#endif 
#endif /* #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__) */
/* under construction !*/
#endif

#ifndef __MMI_MAINLCD_96X64__
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  HintPhnsetShowDateTime
 * DESCRIPTION
 *  This function is hint handling function
 *  for Phonesetup -> Language
 *  Functionality:
 * PARAMETERS
 *  index       [IN]            
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void HintPhnsetShowDateTime(void)
{
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    cui_menu_set_item_hint(
        mmi_frm_group_get_active_id(),
        MENU_SETTING_SHOW_DT_TIME,
        (WCHAR*)GetString((PhnsetGetShowDateTimeStatus() ? STR_GLOBAL_ON : STR_GLOBAL_OFF))
        );
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_entry_show_date_time
 * DESCRIPTION
 *  Entry show date and time setting menu 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_entry_show_date_time(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phnset_appcreate_menucui_create(
        parent_gid,
        GRP_ID_PHNSET_SHOW_DT_TIME,
        MENU_SETTING_SHOW_DT_TIME,
        mmi_phnset_show_date_time_proc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_show_date_time_proc
 * DESCRIPTION
 *  Proc function for show date and time setting menu 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phnset_show_date_time_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
		g_phnset_cntx_p->curShowDtStatus = (U8)PhnsetGetShowDateTimeStatus();
        mmi_phnset_init_on_off_radio_button_menu(
            GRP_ID_PHNSET_SHOW_DT_TIME,
            STR_SETTING_SHOW_DT_TIME,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            g_phnset_cntx_p->curShowDtStatus);
        return MMI_RET_OK;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
        mmi_phnset_show_date_time_select_handler(param);
        return MMI_RET_OK;
        
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(mmi_frm_group_get_active_id());
		return MMI_RET_OK;
		
    default:
		break;
    }
    return MMI_RET_OK;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_show_date_time_select_handler
 * DESCRIPTION
 *  Select handler for show date and time setting menu 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_show_date_time_select_handler(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menucui_param = (cui_menu_event_struct*)param;
    //S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_cntx_p->curShowDtStatus = (U8)menucui_param->highlighted_menu_id;
    //WriteValue(NVRAM_SETTING_STATUS_DT_TIME, &(g_phnset_cntx_p->curShowDtStatus), DS_BYTE, &error);
	WriteValueSlim(NVRAM_SETTING_STATUS_DT_TIME, &(g_phnset_cntx_p->curShowDtStatus), DS_BYTE);
    mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);    
    mmi_frm_group_close(GRP_ID_PHNSET_SHOW_DT_TIME);    
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
#endif

/*****************************************************************************
 * FUNCTION
 *  PhnsetSetShowDTStatus
 * DESCRIPTION
 *  This function is to set show data time statu on/off
 *  Follow functions:
 * PARAMETERS
 *  status      [IN]            
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetSetShowDTStatus(U8 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_phnset_cntx_p->curShowDtStatus = status;
    //WriteValue(NVRAM_SETTING_STATUS_DT_TIME, &status, DS_BYTE, &error); 
	WriteValueSlim(NVRAM_SETTING_STATUS_DT_TIME, &status, DS_BYTE);
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetGetShowDateTimeStatus
 * DESCRIPTION
 *  This function is to get show date/time on/off status
 *  Functionality:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL PhnsetGetShowDateTimeStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data = 0;
    //S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ReadValue(NVRAM_SETTING_STATUS_DT_TIME, &data, DS_BYTE, &error);
	ReadValueSlim(NVRAM_SETTING_STATUS_DT_TIME, &data, DS_BYTE);

    if (data == 0)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}

#ifdef __MMI_IDLE_SCREEN_OWNER_NUMBER__
static mmi_sim_enum g_owner_number_setting_sim;
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_show_owner_number_entry
 * DESCRIPTION
 *  Entry function for show owner number setting menu 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_show_owner_number_entry(mmi_id parent_gid, U16 highlight_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GEMINI__
    switch(highlight_id)
    {
    case MENU_SETTING_OWNER_NUMBER_SIM1:
        g_owner_number_setting_sim = MMI_SIM1;
        break;
    case MENU_SETTING_OWNER_NUMBER_SIM2:
        g_owner_number_setting_sim = MMI_SIM2;
        break;
    #if (MMI_MAX_SIM_NUM >= 3)   
    case MENU_SETTING_OWNER_NUMBER_SIM3:
        g_owner_number_setting_sim = MMI_SIM3;
        break;
    #if (MMI_MAX_SIM_NUM >= 4)
    case MENU_SETTING_OWNER_NUMBER_SIM4:
        g_owner_number_setting_sim = MMI_SIM4;
        break;
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */   
    default:
        ASSERT(0);
    }
#else
    g_owner_number_setting_sim = MMI_SIM1;
#endif /* __GEMINI__ */
 
    mmi_phnset_appcreate_menucui_create(
        parent_gid,
        GRP_ID_PHNSET_SHOW_OWNER_NUMBER,
        highlight_id,
        mmi_phnset_show_owner_number_proc);      
}

 
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_show_owner_number_proc
 * DESCRIPTION
 *  Proc function for show owner number 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phnset_show_owner_number_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *event = (cui_menu_event_struct*)param; 
    mmi_id curr_gid = mmi_frm_group_get_active_id();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event->evt_id)
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
#ifdef __GEMINI__  
        if (event->parent_menu_id == MENU_SETTING_OWNER_NUMBER)
    	{
            cui_menu_set_currlist_flags(curr_gid, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS); 
            cui_menu_set_currlist_left_softkey_by_id(curr_gid, STR_GLOBAL_OK);
            cui_menu_set_currlist_right_softkey_by_id(curr_gid, (WCHAR*)GetString(STR_GLOBAL_BACK));    
            cui_menu_set_currlist_title_by_id(curr_gid, STR_ID_PHNSET_SHOW_OWNER_NUMBER, MAIN_MENU_TITLE_SETTINGS_ICON);	
            mmi_phnset_show_owner_number_hint_handler();  
            if (!srv_sim_ctrl_is_available(MMI_SIM1))
            {
                cui_menu_set_item_hidden(curr_gid, MENU_SETTING_OWNER_NUMBER_SIM1, MMI_TRUE);
            }
            if (!srv_sim_ctrl_is_available(MMI_SIM2))
        	{
                cui_menu_set_item_hidden(curr_gid, MENU_SETTING_OWNER_NUMBER_SIM2, MMI_TRUE);
        	}            

            #if (MMI_MAX_SIM_NUM >= 3)            
            if (!srv_sim_ctrl_is_available(MMI_SIM3))
            {
                cui_menu_set_item_hidden(curr_gid, MENU_SETTING_OWNER_NUMBER_SIM3, MMI_TRUE);
            }
            #if (MMI_MAX_SIM_NUM >= 4)
            if (!srv_sim_ctrl_is_available(MMI_SIM4))
        	{
                cui_menu_set_item_hidden(curr_gid, MENU_SETTING_OWNER_NUMBER_SIM4, MMI_TRUE);
        	}            
            #endif /* (MMI_MAX_SIM_NUM >= 4) */
            #endif /* (MMI_MAX_SIM_NUM >= 3) */    
            return MMI_RET_OK;
    	}
#endif /* __GEMINI__ */
        mmi_phnset_init_on_off_radio_button_menu(
            GRP_ID_PHNSET_SHOW_OWNER_NUMBER,
            STR_ID_PHNSET_SHOW_OWNER_NUMBER,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            (U8)mmi_phnset_show_owner_number_is_on(g_owner_number_setting_sim));    	
        return MMI_RET_OK;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
#ifdef __GEMINI__        
        if (event->parent_menu_id == MENU_SETTING_OWNER_NUMBER_SIM1
            || event->parent_menu_id == MENU_SETTING_OWNER_NUMBER_SIM2
            #if (MMI_MAX_SIM_NUM >= 3)   
            || event->parent_menu_id == MENU_SETTING_OWNER_NUMBER_SIM3
            #if (MMI_MAX_SIM_NUM >= 4)            
            || event->parent_menu_id == MENU_SETTING_OWNER_NUMBER_SIM4
            #endif /* (MMI_MAX_SIM_NUM >= 4) */
            #endif /* (MMI_MAX_SIM_NUM >= 3) */ 
            )
#endif
        {
            mmi_phnset_show_owner_number_set_status(event->highlighted_menu_id);
        }
        return MMI_RET_OK;
        
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(curr_gid);
		return MMI_RET_OK;
		
    default:
		break;
    }
    return MMI_RET_OK;        

}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_show_owner_number_hint_handler
 * DESCRIPTION
 *  Hint handler for show owner number 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_show_owner_number_hint_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id_sim1;
#ifdef __GEMINI__
    U16 string_id_sim2;
#if (MMI_MAX_SIM_NUM >= 3) 
    U16 string_id_sim3;
#if (MMI_MAX_SIM_NUM >= 4)  
    U16 string_id_sim4;
#endif /* (MMI_MAX_SIM_NUM >= 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */     
#endif /* __GEMINI__ */
    mmi_id group_gid = mmi_frm_group_get_active_id();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    string_id_sim1 = (mmi_phnset_show_owner_number_is_on(MMI_SIM1))? STR_GLOBAL_ON : STR_GLOBAL_OFF;
#ifdef __GEMINI__
    cui_menu_set_item_hint(group_gid, MENU_SETTING_OWNER_NUMBER_SIM1, (WCHAR*)GetString(string_id_sim1));
    string_id_sim2 = (mmi_phnset_show_owner_number_is_on(MMI_SIM2))? STR_GLOBAL_ON : STR_GLOBAL_OFF;
    cui_menu_set_item_hint(group_gid, MENU_SETTING_OWNER_NUMBER_SIM2, (WCHAR*)GetString(string_id_sim2));    
#if (MMI_MAX_SIM_NUM >= 3) 
    string_id_sim3 = (mmi_phnset_show_owner_number_is_on(MMI_SIM3))? STR_GLOBAL_ON : STR_GLOBAL_OFF;
    cui_menu_set_item_hint(group_gid, MENU_SETTING_OWNER_NUMBER_SIM3, (WCHAR*)GetString(string_id_sim3));    
#if (MMI_MAX_SIM_NUM >= 4)  
    string_id_sim4 = (mmi_phnset_show_owner_number_is_on(MMI_SIM4))? STR_GLOBAL_ON : STR_GLOBAL_OFF;
    cui_menu_set_item_hint(group_gid, MENU_SETTING_OWNER_NUMBER_SIM4, (WCHAR*)GetString(string_id_sim4));    
#endif /* (MMI_MAX_SIM_NUM >= 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */     

#else
    cui_menu_set_item_hint(group_gid, MENU_SETTING_OWNER_NUMBER, (WCHAR*)GetString(string_id_sim1));
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_show_owner_number_set_status
 * DESCRIPTION
 *  Set show owner number status 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_show_owner_number_set_status(U8 highlight_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    //S16 error;
    U32 nvram_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_owner_number_setting_sim)
	{
	case MMI_SIM1:
        nvram_id = NVRAM_SETTING_OWNER_NO;		
		break;
    #if (MMI_MAX_SIM_NUM >= 2)
	case MMI_SIM2:
        nvram_id = NVRAM_CARD2_OWNER_NUMBER;		
		break;
        
    #if (MMI_MAX_SIM_NUM >= 3)
	case MMI_SIM3:
        nvram_id = NVRAM_CARD3_OWNER_NUMBER;		
		break;        
        
    #if (MMI_MAX_SIM_NUM >= 4)
	case MMI_SIM4:
        nvram_id = NVRAM_CARD4_OWNER_NUMBER;		
		break;
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */  
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
    
	default:
        ASSERT(0); 
	}
    ASSERT(highlight_id == 0 || highlight_id == 1);
    data = highlight_id;
    //WriteValue(nvram_id, &data, DS_BYTE, &error);
	WriteValueSlim(nvram_id, &data, DS_BYTE);
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[PhnsetDisplay.c] mmi_phnset_show_owner_number_set_status sim[%d] on[%d]", g_owner_number_setting_sim, data);    
    mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);    
    mmi_frm_group_close(GRP_ID_PHNSET_SHOW_OWNER_NUMBER);     
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_show_owner_number_get_status
 * DESCRIPTION
 *  Get the show owner number status setting 
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_phnset_show_owner_number_is_on(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    //S16 error;
    U32 nvram_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim)
	{
	case MMI_SIM1:
        nvram_id = NVRAM_SETTING_OWNER_NO;		
		break;

    #if (MMI_MAX_SIM_NUM >= 2)
	case MMI_SIM2:
        nvram_id = NVRAM_CARD2_OWNER_NUMBER;		
		break;
        
    #if (MMI_MAX_SIM_NUM >= 3)
	case MMI_SIM3:
        nvram_id = NVRAM_CARD3_OWNER_NUMBER;		
		break;        
        
    #if (MMI_MAX_SIM_NUM >= 4)
	case MMI_SIM4:
        nvram_id = NVRAM_CARD4_OWNER_NUMBER;		
		break;
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */  
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
    
	default:
        break; 
	}
    if (nvram_id == 0)
	{
	    return MMI_FALSE;
	}

    //ReadValue(nvram_id, &data, DS_BYTE, &error);
	ReadValueSlim(nvram_id, &data, DS_BYTE);
    if (data != 0 && data != 1)
	{
        // Invalid value, reset to 0
        data = 0;
        //WriteValue(nvram_id, &data, DS_BYTE, &error);
		WriteValueSlim(nvram_id, &data, DS_BYTE);
	}
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[PhnsetDisplay.c] mmi_phnset_show_owner_number_is_on sim[%d] on[%d]", sim, data);
    return (MMI_BOOL)data;
}
#endif /* __MMI_IDLE_SCREEN_OWNER_NUMBER__ */
/* show owner number in idle */

#if 0
/* under construction !*/
#ifdef __MMI_OPERATOR_NAME_MENU__
#ifdef __MMI_AP_DCM_SETTING__
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
#ifdef __MMI_AP_DCM_SETTING__
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
#endif /* __MMI_OPERATOR_NAME_MENU__ */ 
/* under construction !*/
#endif

/* clock type in idle */
#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
/*****************************************************************************
 * FUNCTION
 *  PhnsetReadIdleClockType
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetReadIdleClockType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ReadValue(NVRAM_PHNSET_IDLE_CLOCK_TYPE, &(g_phnset_cntx_p->curtCLKType), DS_BYTE, &error);
	ReadValueSlim(NVRAM_PHNSET_IDLE_CLOCK_TYPE, &(g_phnset_cntx_p->curtCLKType), DS_BYTE);

    if (g_phnset_cntx_p->curtCLKType > 1)
    {
    	/* different default value for HVGA Main LCD modify */
#ifdef __MMI_MAINLCD_320X480__ 
        g_phnset_cntx_p->curtCLKType = 1; 	
#else				
        g_phnset_cntx_p->curtCLKType = 0;
#endif /* __MMI_MAINLCD_320X480__ */

        //WriteValue(NVRAM_PHNSET_IDLE_CLOCK_TYPE, &(g_phnset_cntx_p->curtCLKType), DS_BYTE, &error);
		WriteValueSlim(NVRAM_PHNSET_IDLE_CLOCK_TYPE, &(g_phnset_cntx_p->curtCLKType), DS_BYTE);
    }
    wgui_set_clock_type((U8) g_phnset_cntx_p->curtCLKType);
}

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  HintPhnsetIdleClockType
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintPhnsetIdleClockType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* hint_str = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_phnset_cntx_p->curtCLKType)
    {
            /* 
             * case MMI_PHNSET_IDLECLKTYPE_NONE:
             * mmi_ucs2cpy((CHAR*)hintData[index],(CHAR*)GetString(STR_GLOBAL_NONE));
             * break;            
             */
        case MMI_PHNSET_IDLECLKTYPE_DIGITAL:
            hint_str = (CHAR*) GetString(STR_ID_PHNSET_DISPCHAR_DIGITAL);
            break;
        case MMI_PHNSET_IDLECLKTYPE_ANALOG:
            hint_str = (CHAR*) GetString(STR_ID_PHNSET_DISPCHAR_ANALOG);
            break;
        default:
            MMI_ASSERT(0);
    }
    cui_menu_set_item_hint(
        mmi_frm_group_get_active_id(),
        MENU_SETTING_IDLE_CLOCK_TYPE,
        (WCHAR*)hint_str);
    
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetIdleClockType
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetIdleClockType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //WriteValue(NVRAM_PHNSET_IDLE_CLOCK_TYPE, &(g_phnset_cntx_p->curtCLKType), DS_BYTE, &error);
	WriteValueSlim(NVRAM_PHNSET_IDLE_CLOCK_TYPE, &(g_phnset_cntx_p->curtCLKType), DS_BYTE);
    wgui_set_clock_type((U8) g_phnset_cntx_p->curtCLKType);
    g_phnset_cntx_p->isCorrectSet = 1;
    mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
    mmi_frm_group_close(GRP_ID_PHNSET_IDLE_CLOCK_TYPE);
}


/*****************************************************************************
 * FUNCTION
 *  EntryPhnsetIdleClockType
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void EntryPhnsetIdleClockType(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phnset_appcreate_menucui_create(
        parent_gid,
        GRP_ID_PHNSET_IDLE_CLOCK_TYPE,
        MENU_SETTING_IDLE_CLOCK_TYPE,
        mmi_phnset_idle_clock_type_proc);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_idle_clock_type_proc
 * DESCRIPTION
 *  Menu CUI proc function formmi_phnset_idle_clock_type 
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_phnset_idle_clock_type_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        mmi_phnset_init_idle_clock_type_list();
        break;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
        g_phnset_cntx_p->curtCLKType = (U8)((cui_menu_event_struct*)param)->highlighted_menu_id;        
        PhnsetIdleClockType();
        break;
        
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(mmi_frm_group_get_active_id());
        break;
        
    case EVT_ID_GROUP_DEINIT:
        if (param->user_data)
    	{
    	    OslMfree(param->user_data);
    	}
        break;
    default:
		break;
    }
    return MMI_RET_OK;
}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_init_idle_clock_type_list
 * DESCRIPTION
 *  Initialize idle clock type setting menu list 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_init_idle_clock_type_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phnset_radio_button_menu_data_struct radio_button_menu;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_cntx_p->isCorrectSet = 0;
    /*
     * subMenuDataPtrs[MMI_PHNSET_IDLECLKTYPE_NONE] = (PU8)GetString( STR_GLOBAL_NONE );;
     */
    subMenuDataPtrs[MMI_PHNSET_IDLECLKTYPE_ANALOG] = (PU8) GetString(STR_ID_PHNSET_DISPCHAR_ANALOG);
    subMenuDataPtrs[MMI_PHNSET_IDLECLKTYPE_DIGITAL] = (PU8) GetString(STR_ID_PHNSET_DISPCHAR_DIGITAL);

    if (g_phnset_cntx_p->curtCLKType > 1)
    {
        PhnsetReadIdleClockType();  /* __USB_IN_NORMAL_MODE__ */
    }

    radio_button_menu.group_id = GRP_ID_PHNSET_IDLE_CLOCK_TYPE;
    radio_button_menu.menu_title_str_id = STR_ID_IDLE_CLOCK_TYPE;
    radio_button_menu.menu_icon_id = MAIN_MENU_TITLE_SETTINGS_ICON;
    radio_button_menu.menu_item_num = MMI_PHNSET_IDLECLKTYPE_MAX;
    radio_button_menu.menu_item_str_list = subMenuDataPtrs;
    radio_button_menu.menu_item_str_id_list = NULL;
    radio_button_menu.highlighted_item_idx = (U8)g_phnset_cntx_p->curtCLKType;

    mmi_phnset_init_radio_button_menu(&radio_button_menu);
    
}

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif 
#endif /* defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) */ 

/* clock type in idle */


/* screen switch effect */
#ifdef __MMI_SCREEN_SWITCH_EFFECT__

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  HintPhnsetScreenSwitchEffectStatus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HintPhnsetScreenSwitchEffectStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phnset_sse_status_enum ss_status = MMI_PHNSET_SSE_NONE;
    CHAR* hint_str = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ss_status = PhnsetGetScreenSwitchEffectStatus();

	switch(ss_status)
	{
	case MMI_PHNSET_SSE_NONE:
		hint_str = (CHAR*) GetString(STR_GLOBAL_NONE);
		break;

	case MMI_PHNSET_SSE_SIMPLE:
		hint_str = (CHAR*) GetString(STR_ID_PHNSET_SSE_SIMPLE);
		break;

	case MMI_PHNSET_SSE_FULL:
		hint_str = (CHAR*) GetString(STR_ID_PHNSET_SSE_FULL);
	    break;

	default:
	    break;
	}
    cui_menu_set_item_hint(
        mmi_frm_group_get_active_id(),
        MENU_ID_PHNSET_SCRSWITCH_EFFECT,
        (WCHAR*)hint_str);  
    
}

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
/*****************************************************************************
 * FUNCTION
 *  PhnsetGetScreenSwitchEffectStatus
 * DESCRIPTION
 *    
 * PARAMETERS
 *  void
 * RETURNS
 *  current screen switch effect status
 *****************************************************************************/
mmi_phnset_sse_status_enum PhnsetGetScreenSwitchEffectStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (mmi_phnset_sse_status_enum)g_phnset_cntx_p->curScrSwitchEffect;
}

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  PhnsetScreenSwitchEffectHandler
 * DESCRIPTION
 *  set LSK of screen switch effect screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void PhnsetScreenSwitchEffectHandler(U8 highlighted_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phnset_sse_status_enum status = MMI_PHNSET_SSE_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	status = (mmi_phnset_sse_status_enum)GetHighlightedItem();

	PhnsetSetScreenSwitchEffectStatus(status);

	mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);

    mmi_frm_group_close(GRP_ID_PHNSET_SCRSWITCH_EFFECT);
}


/*****************************************************************************
 * FUNCTION
 *  EntryPhnsetScreenSwitchEffectScreen
 * DESCRIPTION
 *  This function is Left soft key handler for Phone setup->IdleScreenDisplay-> Screen Switch Effect
 * PARAMETERS
 *  void           
 * RETURNS
 *  void
 *****************************************************************************/
static void EntryPhnsetScreenSwitchEffectScreen(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phnset_appcreate_menucui_create(
        parent_gid,
        GRP_ID_PHNSET_SCRSWITCH_EFFECT,
        MENU_ID_PHNSET_SCRSWITCH_EFFECT,
        mmi_phnset_screen_switch_effect_proc);
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
/*****************************************************************************
 * FUNCTION
 *  PhnsetSetScreenSwitchEffectStatus
 * DESCRIPTION
 *  Set current ScreenSwitchEffect Status
 * PARAMETERS
 *  MMI_BOOL
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetSetScreenSwitchEffectStatus(mmi_phnset_sse_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_cntx_p->curScrSwitchEffect = status;

    //WriteValue(NVRAM_SET_SCREFFECT_STYLE, &(g_phnset_cntx_p->curScrSwitchEffect), DS_BYTE, &error);
	WriteValueSlim(NVRAM_SET_SCREFFECT_STYLE, &(g_phnset_cntx_p->curScrSwitchEffect), DS_BYTE);

}

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_screen_switch_effect_proc
 * DESCRIPTION
 *  Menu CUI proc function formmi_phnset_screen_switch_effect 
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_phnset_screen_switch_effect_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        mmi_phnset_init_screen_switch_effect_list();
        break;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
        PhnsetScreenSwitchEffectHandler((U8)((cui_menu_event_struct*)param)->highlighted_menu_id);
        break;
        
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(mmi_frm_group_get_active_id());
        break;
        
    case EVT_ID_GROUP_DEINIT:
        if (param->user_data)
    	{
    	    OslMfree(param->user_data);
    	}
        break;
    default:
		break;
    }
    return MMI_RET_OK;
}

 
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_init_screen_switch_effect_list
 * DESCRIPTION
 *  Initialize screen switch effect menu list 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_init_screen_switch_effect_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phnset_radio_button_menu_data_struct radio_button_menu;
    U16 nStrItemList[3] = {STR_GLOBAL_NONE, STR_ID_PHNSET_SSE_SIMPLE, STR_ID_PHNSET_SSE_FULL};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    radio_button_menu.group_id = GRP_ID_PHNSET_SCRSWITCH_EFFECT;
    radio_button_menu.menu_title_str_id = STR_ID_PHNSET_SCREEN_SWITCH_EFFECT;
    radio_button_menu.menu_icon_id = MAIN_MENU_TITLE_SETTINGS_ICON;
    radio_button_menu.menu_item_num = MMI_PHNSET_SSE_NUM;
    radio_button_menu.menu_item_str_list = NULL;
    radio_button_menu.menu_item_str_id_list = nStrItemList;
    radio_button_menu.highlighted_item_idx = g_phnset_cntx_p->curScrSwitchEffect;

    mmi_phnset_init_radio_button_menu(&radio_button_menu);
    
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
#endif /* __MMI_SCREEN_SWITCH_EFFECT__ */
#if 0
/* screen switch effect */#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
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
#ifdef __MMI_DUAL_CLOCK__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_CLOCK__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)*/
#endif

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_disp_setup_sub_menu_handler
 * DESCRIPTION
 *  Proc function for display setup group 
 * PARAMETERS
 *  param   [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_phnset_disp_setup_sub_menu_handler(cui_menu_event_struct *param, MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_DONT_CARE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        ret = mmi_phnset_disp_setup_sub_menu_entry_handler(param);
        break;
#ifndef __MMI_PHNSET_SLIM__    
        
    case EVT_ID_CUI_MENU_ITEM_HILITE:
        ret =  mmi_phnset_disp_setup_sub_menu_highlight_handler(param);
        break;
#endif
    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:        
        ret = mmi_phnset_disp_setup_sub_menu_select_handler(param, parent_gid);
        break;

    default:
        break;
    }
    if (ret != MMI_RET_DONT_CARE)
    {
        return ret;
    }
#ifndef __MMI_MAINLCD_96X64__   
    /* Try sub menu handler */
    ret = mmi_phnset_wallpaper_sub_menu_handler(param, parent_gid);
    if (ret != MMI_RET_DONT_CARE)
    {
        return ret;
    }
#endif
#ifndef __MMI_MAINLCD_96X64__  
#ifdef __MMI_POWER_ON_OFF_DISPLAY__    
    ret = mmi_phnset_pwr_on_off_sub_menu_handler(param, parent_gid);
    if (ret != MMI_RET_DONT_CARE)
    {
        return ret;
    }
#endif /* __MMI_POWER_ON_OFF_DISPLAY__ */  
#endif
#ifdef __MMI_SCREEN_SAVER__
    ret = mmi_phnset_screensaver_sub_menu_handler(param, parent_gid);
    if (ret != MMI_RET_DONT_CARE)
    {
        return ret;
    }
#endif /* __MMI_SCREEN_SAVER__ */
#ifdef __MMI_SEARCH_WEB_GOOGLE__
  #ifdef __MMI_VUI_LAUNCHER__
    #ifdef __MMI_VUI_LAUNCHER_KEY__
    if(MMI_PHNSET_LAUNCHER_KEY == mmi_phnset_launcher_get_launcher_type())
    {
    ret = mmi_search_web_google_sub_menu_handler(param, parent_gid);
    if (ret != MMI_RET_DONT_CARE)
    {
        return ret;
    }
    }
	#endif
  #else
    	 ret = mmi_search_web_google_sub_menu_handler(param, parent_gid);
    	 if (ret != MMI_RET_DONT_CARE)
    		{
        	return ret;
    		}
  #endif
#endif
#ifdef __MMI_PHNSET_APPICON_SUPPORT__
         ret = mmi_phnset_appicon_sub_menu_handler(param, parent_gid);
         if(ret != MMI_RET_DONT_CARE)
             return ret;
#endif

    return MMI_RET_DONT_CARE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_disp_setup_sub_menu_entry_handler
 * DESCRIPTION
 *  Entry proc for display setup menu
 * PARAMETERS
 *  param   [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phnset_disp_setup_sub_menu_entry_handler(cui_menu_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->parent_menu_id)
    {
    case MENU_IDLE_SCR_DISP:
        return mmi_phnset_disp_setup_sub_menu_init();
#ifdef __MMI_IDLE_SCREEN_OWNER_NUMBER__
#ifdef __GEMINI__        
    case MENU_SETTING_OWNER_NUMBER:
        return mmi_phnset_show_owner_number_proc((mmi_event_struct*)param);
#endif            
#endif /* __MMI_IDLE_SCREEN_OWNER_NUMBER__ */
    default:
        break;
    }
    return MMI_RET_DONT_CARE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_disp_setup_sub_menu_highlight_handler
 * DESCRIPTION
 *  Highlight proc for display setup menu
 * PARAMETERS
 *  param   [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
#ifndef __MMI_PHNSET_SLIM__    
static mmi_ret mmi_phnset_disp_setup_sub_menu_highlight_handler(cui_menu_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->highlighted_menu_id)
    {
    default:
        break;
    }
    return MMI_RET_DONT_CARE;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_disp_setup_sub_menu_select_handler
 * DESCRIPTION
 *  Select proc for display setup menu
 * PARAMETERS
 *  param   [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phnset_disp_setup_sub_menu_select_handler(cui_menu_event_struct *param, MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->highlighted_menu_id)
    {

#ifdef __MMI_VUI_SCREEN_LOCK_KEY__
    case MENU_ID_SCREEN_LOCK_KEY_IMG_SETTING:
        mmi_screen_lock_key_img_setting_entry(parent_gid);
        return MMI_RET_OK;
#endif

#ifdef __MMI_AUTO_KEYPAD_LOCK__
    case MENU_ID_SLK_TIME_SETTING_MENU:
        mmi_scr_locker_screen_auto_lock_entry(parent_gid);
        return MMI_RET_OK;
#endif
    
#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
    case MENU_SETTING_MAINMENU_STYLE:
        EntryPhnsetMainMenuStyle(parent_gid);
        return MMI_RET_OK;        
#endif 

#ifdef __MMI_MOTION_DIAL__
    case MENU_SETTING_DIAL_STYLE:
        EntryPhnsetDialStyle(parent_gid);
        return MMI_RET_OK;        
#endif /* __MMI_MOTION_DIAL__ */

#if defined(__MMI_VUI_MAINMENU__) || ((defined(__MMI_VUI_LAUNCHER_KEY__) || defined(__MMI_VUI_LAUNCHER__)) && defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__))
    case MENU_ID_VUI_PHNSET_MAINMENU_EFFECT:
		#if (defined(__MMI_VUI_LAUNCHER_KEY__) || defined(__MMI_VUI_LAUNCHER__)) && defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
		mmi_phnset_menu_effect_launch(parent_gid);
		#else /* __MMI_VUI_LAUNCHER_KEY__ */
        mmi_entry_phnset_vui_mainmenu_effect(parent_gid);
		#endif /* __MMI_VUI_LAUNCHER_KEY__ */
        return MMI_RET_OK;        
#endif
#if 0
#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__        
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */        
#endif        
#ifdef __MMI_DUAL_CLOCK__
#if 0
#ifndef __MMI_VUI_HOMESCREEN_DUALCLOCK__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_VUI_HOMESCREEN_DUALCLOCK__ */
#endif
#endif /* __MMI_DUAL_CLOCK__ */
#if 0
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */
#endif
#ifndef __MMI_MAINLCD_96X64__     
    case MENU_SETTING_SHOW_DT_TIME:
        mmi_phnset_entry_show_date_time(parent_gid);
        return MMI_RET_OK;        
#endif        

#if 0
#if defined(__MMI_OPERATOR_NAME_MENU__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
#endif 
        
#ifdef __MMI_SCREEN_SWITCH_EFFECT__    
    case MENU_ID_PHNSET_SCRSWITCH_EFFECT:
        EntryPhnsetScreenSwitchEffectScreen(parent_gid);
        return MMI_RET_OK;
#endif /* __MMI_SCREEN_SWITCH_EFFECT__ */
        
#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__    
    case MENU_SETTING_IDLE_CLOCK_TYPE:
        EntryPhnsetIdleClockType(parent_gid);
        return MMI_RET_OK;
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */
    
#if ((defined(__MMI_LAUNCHER_APP_LIST__) && defined(__MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT__) || defined(__MMI_VUI_LAUNCHER_KEY__) && defined(__MMI_VUI_LAUNCHER__)))
	case MENU_ID_VUI_PHNSET_LAUNCHER:
		mmi_phnset_launcher_switch_launch();
		return MMI_RET_OK;
#endif /* __MMI_VUI_LAUNCHER_KEY__ */

    /* Show owner number */
#ifdef __MMI_IDLE_SCREEN_OWNER_NUMBER__
#ifdef __GEMINI__
    case MENU_SETTING_OWNER_NUMBER_SIM1:
    case MENU_SETTING_OWNER_NUMBER_SIM2:
    #if (MMI_MAX_SIM_NUM >= 3)  
    case MENU_SETTING_OWNER_NUMBER_SIM3:        
    #if (MMI_MAX_SIM_NUM >= 4)  
    case MENU_SETTING_OWNER_NUMBER_SIM4:        
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */   
        mmi_phnset_show_owner_number_entry(parent_gid, param->highlighted_menu_id);
        return MMI_RET_OK;
#else
    case MENU_SETTING_OWNER_NUMBER:
        mmi_phnset_show_owner_number_entry(parent_gid, MENU_SETTING_OWNER_NUMBER);
        return MMI_RET_OK;
#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif /* __MMI_IDLE_SCREEN_OWNER_NUMBER__ */
#if defined(__MMI_MAINLCD_96X64__) && defined(__MMI_BACKLIGHT_SUPPORT__)
    case MENU_ID_PHNSET_GPIO_BACKLITE:
		mmi_phset_gpio_entry_backlite_timeout();
		return MMI_RET_OK;
#endif
#ifdef __MMI_BT_BOX_TEST_DIALER_PAD_STYLE__ 
	
	case MENU_SETTING_BT_BOX_UT:
		EntryBtBoxDialerType();
	    return MMI_RET_OK;
        
	case MENU_SETTING_BT_BOX_PICKER_UT:
		EntryBtBoxPickerType();
		return MMI_RET_OK;
	
#endif  //__MMI_BT_BOX_TEST_DIALER_PAD_STYLE__
    default:
        break;
    }
    return MMI_RET_DONT_CARE;
}

void mmi_phnset_hide_menu_ext(MMI_ID main_menu_cui_id,const mmi_setting_hide_menu_struct* hide_menu_struct)
{
   S8 i;
  for (i = 0; hide_menu_struct[i].menu_id != 0; i++)
	{
		if (hide_menu_struct[i].is_hide_func())
		{
			cui_menu_set_item_hidden(main_menu_cui_id, hide_menu_struct[i].menu_id, MMI_TRUE);
		}	
		else
		{
			cui_menu_set_item_hidden(main_menu_cui_id, hide_menu_struct[i].menu_id, MMI_FALSE);
		}
	}
}
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_disp_setup_sub_menu_init
 * DESCRIPTION
 *  Initialize the main menu of display setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_phnset_disp_setup_sub_menu_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U16 i;
    MMI_ID disp_main_menu_cui_id = mmi_frm_group_get_active_id();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Hide menu item */
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
#endif
    mmi_phnset_hide_menu_ext(disp_main_menu_cui_id,mmi_phnset_disp_hide_menu);
#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
#ifdef __MMI_APP_MANAGER_SUPPORT__
	cui_menu_set_item_hidden(disp_main_menu_cui_id, MENU_SETTING_MAINMENU_STYLE, MMI_TRUE);
#endif /* __MMI_APP_MANAGER_SUPPORT__ */
#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */
    
#ifdef __MMI_SEARCH_WEB_GOOGLE__
  #ifdef __MMI_VUI_LAUNCHER__
    #ifdef __MMI_VUI_LAUNCHER_KEY__
   	if(MMI_PHNSET_LAUNCHER_FTE == mmi_phnset_launcher_get_launcher_type())
   	{
    	cui_menu_set_item_hidden(disp_main_menu_cui_id, MENU_ID_SETTING_GOOGLE_HINT_ENTRY, MMI_TRUE);
    }
    else
    {
    	cui_menu_set_item_hidden(disp_main_menu_cui_id, MENU_ID_SETTING_GOOGLE_HINT_ENTRY, MMI_FALSE);
    }
	#else
		cui_menu_set_item_hidden(disp_main_menu_cui_id, MENU_ID_SETTING_GOOGLE_HINT_ENTRY, MMI_TRUE);
	#endif
  #else
    cui_menu_set_item_hidden(disp_main_menu_cui_id, MENU_ID_SETTING_GOOGLE_HINT_ENTRY, MMI_FALSE);
  #endif
#endif    
    /* set menu list flags to numbered icon menu list at the first time enter*/
    cui_menu_set_currlist_flags(disp_main_menu_cui_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

    /* set hints of menu item */
#ifndef __MMI_MAINLCD_96X64__
    HintPhnsetShowDateTime(); 
#endif
#if 0
#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__    
/* under construction !*/
#endif
#endif
#ifdef __MMI_MOTION_DIAL__
    HintPhnsetDialStyle();
#endif
#ifdef __MMI_DUAL_CLOCK__
    HintPhnsetDualClockIdleScreen();
#endif
#if 0
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__)
/* under construction !*/
#endif
#endif
#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
    HintPhnsetIdleClockType();
#endif
#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
    HintPhnsetMainMenuStyle();
#endif
#if 0
#ifdef __MMI_OPERATOR_NAME_MENU__
/* under construction !*/
#endif
#endif
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
    HintPhnsetScreenSwitchEffectStatus();
#endif

#if (defined(__MMI_VUI_LAUNCHER_KEY__) || defined(__MMI_VUI_LAUNCHER__)) && defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
	mmi_phnset_menu_effect_type_hint();
#elif defined(__MMI_VUI_MAINMENU__)
    mmi_hint_phnset_vui_mainmenu_effect();
#endif
#ifndef __MMI_MAINLCD_96X64__
    HintPhnsetWallpaper();
#endif
#ifdef __MMI_SCREEN_SAVER__
    HintPhnsetScreenSaver();
#endif /* __MMI_SCREEN_SAVER__ */
#ifdef __MMI_SUB_WALLPAPER__
    HintPhnsetSubWallpaper();
#endif
#if 0
#ifdef __DAILY_WALLPAPER__
/* under construction !*/
#endif
#endif
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    HintPhnsetPwrOnDisplay();
    HintPhnsetPwrOffDisplay();
#endif
#ifdef __MMI_PHNSET_APPICON_SUPPORT__
    mmi_phnset_appicon_set_hint();
#endif

#ifdef __MMI_IDLE_SCREEN_OWNER_NUMBER__
#ifndef __MMI_DUAL_SIM_MASTER__        
    mmi_phnset_show_owner_number_hint_handler();
#endif            
#endif /* __MMI_IDLE_SCREEN_OWNER_NUMBER__ */

#ifdef __MMI_SEARCH_WEB_GOOGLE__
  #ifdef __MMI_VUI_LAUNCHER__
    #ifdef __MMI_VUI_LAUNCHER_KEY__
   	if(MMI_PHNSET_LAUNCHER_KEY == mmi_phnset_launcher_get_launcher_type())
   	{
    	mmi_search_web_google_set_menu_hint(disp_main_menu_cui_id);
    }
	#endif
  #else
    mmi_search_web_google_set_menu_hint(disp_main_menu_cui_id);
  #endif
#endif

#ifdef __MMI_VUI_SCREEN_LOCK_KEY__
    mmi_screen_lock_key_img_setting_set_hint();
#endif

#if defined(__MMI_AUTO_KEYPAD_LOCK__) && !defined(__MMI_SCREEN_LOCK_CLASSIC_NEPTUNE_LIKE_BWUI__)
    mmi_scr_locker_screen_auto_lock_set_hint();
#endif

    cui_menu_set_currlist_left_softkey_by_id(disp_main_menu_cui_id, STR_GLOBAL_OK);
    cui_menu_set_currlist_right_softkey_by_id(disp_main_menu_cui_id, STR_GLOBAL_BACK);    
    cui_menu_set_currlist_title_by_id(disp_main_menu_cui_id, STR_IDLE_SCR_DISP, MAIN_MENU_TITLE_SETTINGS_ICON);
#if ((defined(__MMI_LAUNCHER_APP_LIST__) && defined(__MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT__) || defined(__MMI_VUI_LAUNCHER_KEY__) && defined(__MMI_VUI_LAUNCHER__)))
	mmi_phnset_launcher_switch_hint();
#endif /* __MMI_VUI_LAUNCHER_KEY__ */
    return MMI_RET_OK;
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
#ifdef __MMI_MAINLCD_96X64__

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_disp_main_menu_handler
 * DESCRIPTION
 *  proc function for menu cui in GRP_ID_PHNSET_DISP
 * PARAMETERS
 *  param : [IN]    menu cui event
 * RETURNS
 *  process result
 *****************************************************************************/
static mmi_ret mmi_phnset_disp_main_menu_handler(cui_menu_event_struct *param, MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
      case EVT_ID_CUI_MENU_CLOSE_REQUEST:
       {
         cui_menu_close(mmi_frm_group_get_active_id());
         return MMI_RET_OK; 
       }
    default:
        break;            
    }
    return MMI_RET_DONT_CARE;
}

mmi_ret mmi_phnset_disp_setup_proc(cui_menu_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menucui_event;
    mmi_ret ret = MMI_RET_DONT_CARE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
     /* Menu CUI event */
    if (cui_menu_is_menu_event(param->evt_id))
    {
        menucui_event = (cui_menu_event_struct*)param;

        ret = mmi_phnset_disp_main_menu_handler(menucui_event, GRP_ID_PHNSET_DISP_SETUP);      
        if (ret != MMI_RET_DONT_CARE)
        {
            return ret;
        }       
        ret= mmi_phnset_disp_setup_sub_menu_handler(menucui_event, GRP_ID_PHNSET_DISP_SETUP);
       if (ret != MMI_RET_DONT_CARE)
        {
            return ret;
        }
       return MMI_RET_DONT_CARE;
    }
     return MMI_RET_OK;
}

void EntryPhnsetDispScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
       MMI_ID main_menu_cui_id;
       
       /*----------------------------------------------------------------*/
       /* Code Body                                                      */
       /*----------------------------------------------------------------*/
       mmi_frm_group_create_ex(
           GRP_ID_ROOT,
           GRP_ID_PHNSET_DISP_SETUP,
           mmi_phnset_disp_setup_proc,
           NULL, 
           MMI_FRM_NODE_SMART_CLOSE_FLAG);
       main_menu_cui_id = cui_menu_create(
           GRP_ID_PHNSET_DISP_SETUP,
           CUI_MENU_SRC_TYPE_RESOURCE,
           CUI_MENU_TYPE_APPMAIN,
           MENU_IDLE_SCR_DISP,
           MMI_FALSE,
           NULL);      
       cui_menu_set_default_title_image_by_id(main_menu_cui_id, MAIN_MENU_TITLE_SETTINGS_ICON);
       cui_menu_run(main_menu_cui_id);

}
/*****************************************************************************
 * FUNCTION
 *  HighlightPhnsetScr
 * DESCRIPTION
 *  This function is highlight handler for display
 *  Follow functions: EntryPhnsetScr
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightPhnsetDispScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryPhnsetDispScr, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(EntryPhnsetDispScr, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif

#ifdef __MMI_BT_BOX_TEST_DIALER_PAD_STYLE__ 
static void mmi_phnset_init_screen_btbox_dialer_type_list(MMI_ID cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 i;
    phnset_radio_button_menu_data_struct radio_button_menu;
    U16 nStrItemList[3]= {STR_ID_PHNSET_BT_BOX_UT1, STR_ID_PHNSET_BT_BOX_UT2, STR_ID_PHNSET_BT_BOX_UT3};
    /*
	for (i = 0; i < 3; i++)
		{
			 nStrItemList[i] = (U16*)GetString(STR_ID_PHNSET_BT_BOX_UT1+i);
		}
    */
    radio_button_menu.group_id = GRP_ID_PHNSET_BTBOX_DIALER_TYPE;
    radio_button_menu.menu_title_str_id = STR_ID_PHNSET_BT_BOX_UT;
    radio_button_menu.menu_item_num = MMI_PHNSET_BT_BOX_TYPE_NUM;
    radio_button_menu.menu_item_str_list = NULL;
    radio_button_menu.menu_item_str_id_list = nStrItemList;
    radio_button_menu.highlighted_item_idx = g_phnset_cntx_p->curBtBoxDialerType;

    mmi_phnset_init_radio_button_menu(&radio_button_menu);

	/////////////////////////////////
/*
    cui_menu_set_default_title_by_id(cui_gid, STR_ID_PHNSET_BT_BOX_UT, NULL);
	cui_menu_set_currlist_flags(cui_gid, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
	cui_menu_set_currlist_highlighted_id(cui_gid, g_phnset_cntx_p->curBtBoxDialerType);
*/
}


void PhnsetSetBtBoxDialerTypeStatus(mmi_phnset_BT_BOX_TYPE_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_cntx_p->curBtBoxDialerType = status;

    WriteValue(NVRAM_DISPCHAR_BT_BOX_DIALER_TYPE, &(g_phnset_cntx_p->curBtBoxDialerType), DS_BYTE, &error);

}


static void PhnsetBtBoxDialerTypeHandler(U8 highlighted_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phnset_BT_BOX_TYPE_enum status = MMI_PHNSET_BT_BOX_TYPE1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	status = (mmi_phnset_BT_BOX_TYPE_enum)GetHighlightedItem();

	PhnsetSetBtBoxDialerTypeStatus(status);

	mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);

    mmi_frm_group_close(GRP_ID_PHNSET_BTBOX_DIALER_TYPE);
}



mmi_ret mmi_phnset_btbox_dialer_type_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	 cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)param;
	
    switch (param->evt_id)
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        mmi_phnset_init_screen_btbox_dialer_type_list(menu_evt->sender_id);
        break;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
        PhnsetBtBoxDialerTypeHandler((U8)((cui_menu_event_struct*)param)->highlighted_menu_id);
        break;
        
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(mmi_frm_group_get_active_id());
        break;
        
    case EVT_ID_GROUP_DEINIT:
        if (param->user_data)
    	{
    	    OslMfree(param->user_data);
    	}
        break;
    default:
		break;
    }
    return MMI_RET_OK;
}




static void EntryBtBoxDialerType(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
       MMI_ID main_menu_cui_id;
       
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
       mmi_frm_group_create_ex(
           GRP_ID_ROOT,
           GRP_ID_PHNSET_BTBOX_DIALER_TYPE,
           mmi_phnset_btbox_dialer_type_proc,
           NULL, 
           MMI_FRM_NODE_SMART_CLOSE_FLAG);
	   cui_menu_create_and_run(
		GRP_ID_PHNSET_BTBOX_DIALER_TYPE,
		CUI_MENU_SRC_TYPE_APPCREATE, //CUI_MENU_SRC_TYPE_RESOURCE,	 
		CUI_MENU_TYPE_APPSUB,
		MENU_SETTING_BT_BOX_UT,
		MMI_FALSE,
		NULL);
}


void HighlightBtBoxDialerType(void)
{
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryBtBoxDialerType, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(EntryBtBoxDialerType, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


static void mmi_phnset_init_screen_btbox_picker_type_list(MMI_ID cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 i;
    phnset_radio_button_menu_data_struct radio_button_menu;
    U16 nStrItemList[2]= {STR_ID_PHNSET_BT_BOX_PICKER_UT1, STR_ID_PHNSET_BT_BOX_PICKER_UT2};
    /*
	for (i = 0; i < 3; i++)
		{
			 nStrItemList[i] = (U16*)GetString(STR_ID_PHNSET_BT_BOX_PICKER_UT1+i);
		}
    */
    radio_button_menu.group_id = GRP_ID_PHNSET_BTBOX_PICKER_TYPE;
    radio_button_menu.menu_title_str_id = STR_ID_PHNSET_BT_BOX_PICKER_UT;
    radio_button_menu.menu_item_num = MMI_PHNSET_BT_BOX_PICKER_TYPE_NUM;
    radio_button_menu.menu_item_str_list = NULL;
    radio_button_menu.menu_item_str_id_list = nStrItemList;
    radio_button_menu.highlighted_item_idx = g_phnset_cntx_p->curBtBoxPickerType;

    mmi_phnset_init_radio_button_menu(&radio_button_menu);

	/////////////////////////////////
/*
    cui_menu_set_default_title_by_id(cui_gid, STR_ID_PHNSET_BT_BOX_PICKER_UT, NULL);
	cui_menu_set_currlist_flags(cui_gid, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
	cui_menu_set_currlist_highlighted_id(cui_gid, g_phnset_cntx_p->curBtBoxPickerType);
*/
}


void PhnsetSetBtBoxPickerTypeStatus(mmi_phnset_BT_BOX_Picker_TYPE_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_cntx_p->curBtBoxPickerType = status;

    WriteValue(NVRAM_DISPCHAR_BT_BOX_PICKER_TYPE, &(g_phnset_cntx_p->curBtBoxPickerType), DS_BYTE, &error);

}


static void PhnsetBtBoxPickerTypeHandler(U8 highlighted_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phnset_BT_BOX_Picker_TYPE_enum status = MMI_PHNSET_BT_BOX_PICKER_TYPE1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	status = (mmi_phnset_BT_BOX_Picker_TYPE_enum)GetHighlightedItem();

	PhnsetSetBtBoxPickerTypeStatus(status);

	mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);

    mmi_frm_group_close(GRP_ID_PHNSET_BTBOX_PICKER_TYPE);
}



mmi_ret mmi_phnset_btbox_picker_type_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	 cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)param;
	
    switch (param->evt_id)
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        mmi_phnset_init_screen_btbox_picker_type_list(menu_evt->sender_id);
        break;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
        PhnsetBtBoxPickerTypeHandler((U8)((cui_menu_event_struct*)param)->highlighted_menu_id);
        break;
        
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(mmi_frm_group_get_active_id());
        break;
        
    case EVT_ID_GROUP_DEINIT:
        if (param->user_data)
    	{
    	    OslMfree(param->user_data);
    	}
        break;
    default:
		break;
    }
    return MMI_RET_OK;
}




static void EntryBtBoxPickerType(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
       MMI_ID main_menu_cui_id;
       
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
       mmi_frm_group_create_ex(
           GRP_ID_ROOT,
           GRP_ID_PHNSET_BTBOX_PICKER_TYPE,
           mmi_phnset_btbox_picker_type_proc,
           NULL, 
           MMI_FRM_NODE_SMART_CLOSE_FLAG);
	   cui_menu_create_and_run(
		GRP_ID_PHNSET_BTBOX_PICKER_TYPE,
		CUI_MENU_SRC_TYPE_APPCREATE, //CUI_MENU_SRC_TYPE_RESOURCE,	 
		CUI_MENU_TYPE_APPSUB,
		MENU_SETTING_BT_BOX_PICKER_UT,
		MMI_FALSE,
		NULL);
}


void HighlightBtBoxPickerType(void)
{
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryBtBoxPickerType, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(EntryBtBoxPickerType, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}

#endif  //__MMI_BT_BOX_TEST_DIALER_PAD_STYLE__

