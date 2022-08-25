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
 * WgtMgrAppMain.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/
/* MMI */
#include "MMI_features.h"
#ifdef __MMI_GADGET_SUPPORT__

/************************************************************************/
/* Include Header                                                       */
/************************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"
/* ASM*/
#include "App_mem.h"

/* CUI  */
#include "menucuigprot.h"

/* USB */
#include "USBSrvGprot.h"

/* Widget Manager Service */
#include "WgtMgrSrvGprot.h"
#include "WgtMgrSrvIprot.h"

/* Widget Manager Application */
#include "WgtMgrAppGprot.h"
#include "WgtMgrAppIprot.h"
#include "mmi_rp_app_wgtmgr_def.h"

#include "MMIDataType.h"
#include "gui_typedef.h"
#include "wgui_touch_screen.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_popup.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "custom_events_notify.h"
#include "wgui_categories_list.h"
#include "GlobalConstants.h"
#include "wgui_include.h"
#include "wgui_categories.h"
#include "mmi_frm_mem_gprot.h"
#include "CommonScreensResDef.h"
#include "AlertScreen.h"
#include "Unicodexdcl.h"
#include "gui_data_types.h"
#include "mmi_frm_input_gprot.h"

/************************************************************************/
/* Structure and Definition                                             */
/************************************************************************/
/* this is used to indentify the menu item of widget manager tab pages */
typedef enum
{
    MMI_WGTMGR_WGT_TYPE_PHONE = 0,
    MMI_WGTMGR_WGT_TYPE_DOWNLOADED,
    MMI_WGTMGR_WGT_TYPE_TOTAL_NUM
} mmi_wgtmgr_wgt_type_enum;

/* The context of WgtMgrApp */
typedef struct
{
    srv_wgtmgr_wgt_asm_data_struct srv_wgtmgr_mem;
    S32 sort_list[SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM];
    U8 selected_tab_index;
    U8 selected_item_index;	
} mmi_wgtmgr_cntx_struct;

/* make sure size of nvram_wgtmgr_lid_struct is smaller than NVRAM_EF_WGTMGR_DATA_SIZE */
#ifndef COMPILE_ASSERT
#define COMPILE_ASSERT(exp, name) typedef int dummy##name [(exp) ? 1 : -1];
#endif

COMPILE_ASSERT(MMI_WGTMGR_MEM_POOL_SIZE >= sizeof(mmi_wgtmgr_cntx_struct), asm_size_check);


/************************************************************************/
/* Internal Function Declaration                                        */
/************************************************************************/
/* entry function */
static void mmi_wgtmgr_entry_main_int(void);
static void mmi_wgtmgr_entry_please_wait(void);
static void mmi_wgtmgr_entry_tab_phone_widgets(void);
static void mmi_wgtmgr_entry_tab_downloaded_widgets(void);
static void mmi_wgtmgr_entry_options(void);
static void mmi_wgtmgr_entry_deleting(void);


/* group event proc */
static mmi_ret mmi_wgtmgr_main_proc(mmi_event_struct *evt);
static mmi_ret mmi_wgtmgr_options_proc(mmi_event_struct *evt);

/* category function */
static S32 mmi_wgtmgr_phone_widgets_get_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item);
static S32 mmi_wgtmgr_downloaded_widgets_get_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item);
static MMI_BOOL mmi_wgtmgr_get_downloaded_wgt_icon_path(S32 index, WCHAR *path);

/* highlight handler */
static void mmi_wgtmgr_phone_wgt_highlight_hdlr(S32 index);
static void mmi_wgtmgr_downloaded_wgt_highlight_hdlr(S32 index);

/* menu CUI */
static void mmi_wgtmgr_set_option_list(cui_menu_event_struct *menu_evt);
static void mmi_wgtmgr_set_sort_by_list(cui_menu_event_struct *menu_evt);

/* callback function */
static void mmi_wgtmgr_delete_finish_callback(void *user_data);

/* misc functions */
static void mmi_wgtmgr_exit(void);
static void mmi_wgtmgr_main_pre_entry(void);
static void mmi_wgtmgr_enable_wgt(void);
static void mmi_wgtmgr_disable_wgt(void);
static void mmi_wgtmgr_set_sort_order(srv_wgtmgr_sort_order_enum index);
static void mmi_wgtmgr_display_delete_wgt_confirm(void);
static void mmi_wgtmgr_delete_wgt(void);
static S32 mmi_wgtmgr_get_dwgt_id_by_index(S32 index);

#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_TOUCH_SCREEN__)
static void mmi_wgtmgr_downloaded_wgt_tap_callback(mmi_tap_type_enum tap_type, S32 index);
#endif

/************************************************************************/
/* Golbal Variable                                                      */
/************************************************************************/
static mmi_wgtmgr_cntx_struct *g_mmi_wgtmgr_cntx_p = NULL;

/************************************************************************/
/* Local Function Definition                                                  */
/************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_init
 * DESCRIPTION
 *  This function is used to initialize the Widget Manager Application
 *  It should be invoked in InitializeAll()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_register(APPLIB_MEM_AP_ID_WGTMGR, STR_ID_WGTMGR_WIDGET_MANAGER, IMG_ID_WGTMGR_APP, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_exit
 * DESCRIPTION
 *  This function is invoked when Widget Manager Main screen group in deinit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop Widget Manager Service */
    srv_wgtmgr_stop();

    /* free ASM if necessary */
    if (g_mmi_wgtmgr_cntx_p != NULL)
    {
        applib_mem_ap_free(g_mmi_wgtmgr_cntx_p);
        g_mmi_wgtmgr_cntx_p = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_main_pre_entry
 * DESCRIPTION
 *  This function is used to allocate ASM and start Widget Manager Service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_main_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wgtmgr_cntx_struct *cntx_p = g_mmi_wgtmgr_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if the global context is null when entering Widget Manager */
    if (cntx_p != NULL)
    {
        MMI_ASSERT(0);
    }

    /* allocate ASM */
    cntx_p = (mmi_wgtmgr_cntx_struct *)applib_mem_ap_alloc(APPLIB_MEM_AP_ID_WGTMGR, MMI_WGTMGR_MEM_POOL_SIZE);

    if (cntx_p != NULL)
    {
        g_mmi_wgtmgr_cntx_p = cntx_p;

        /* zero init global context */
        kal_mem_set(cntx_p, 0, sizeof(mmi_wgtmgr_cntx_struct));

        /* display please wait because we need to start Widget Manager Service */
        mmi_wgtmgr_entry_please_wait();

        /* start Widget Manager Service, pass memory address and callback to it */
        srv_wgtmgr_start(&(cntx_p->srv_wgtmgr_mem), mmi_wgtmgr_entry_main_int, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_entry_main_int
 * DESCRIPTION
 *  This function is to display Widget Manager Application main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_entry_main_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_tab_struct tab_pages_info_array[MMI_WGTMGR_WGT_TYPE_TOTAL_NUM];
    U8 selected_tab_index = g_mmi_wgtmgr_cntx_p->selected_tab_index;
    U8 tab_num = MMI_WGTMGR_WGT_TYPE_TOTAL_NUM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if screen group is still present */
    if (mmi_frm_group_is_present(GRP_ID_WGTMGR_MAIN) == MMI_FALSE)
    {
        return;
    }

    srv_wgtmgr_get_downloaded_wgt_list(g_mmi_wgtmgr_cntx_p->sort_list);

    /* fill in tab infomation */
    /* 1. Phone widgets */
    tab_pages_info_array[MMI_WGTMGR_WGT_TYPE_PHONE].screen_id = SCR_ID_WGTMGR_TAB_PHONE_WIDGETS;
    tab_pages_info_array[MMI_WGTMGR_WGT_TYPE_PHONE].tab_entry_func = mmi_wgtmgr_entry_tab_phone_widgets;
    tab_pages_info_array[MMI_WGTMGR_WGT_TYPE_PHONE].tab_icon = (U8*)get_image(IMG_ID_WGTMGR_PHONE_WIDGETS);
    tab_pages_info_array[MMI_WGTMGR_WGT_TYPE_PHONE].tab_string = NULL; /* the tab needs no title */

    /* 2. Downloaded widgets */
    tab_pages_info_array[MMI_WGTMGR_WGT_TYPE_DOWNLOADED].screen_id = SCR_ID_WGTMGR_TAB_DOWNLOADED_WIDGETS;
    tab_pages_info_array[MMI_WGTMGR_WGT_TYPE_DOWNLOADED].tab_entry_func = mmi_wgtmgr_entry_tab_downloaded_widgets;
    tab_pages_info_array[MMI_WGTMGR_WGT_TYPE_DOWNLOADED].tab_icon = (U8*)get_image(IMG_ID_WGTMGR_DOWNLOADED_WIDGETS);
    tab_pages_info_array[MMI_WGTMGR_WGT_TYPE_DOWNLOADED].tab_string = NULL; /* the tab needs no title */

    /* restore selected_tab_index if value is wrong */
    if (selected_tab_index >= MMI_WGTMGR_WGT_TYPE_TOTAL_NUM)
    {
        selected_tab_index = MMI_WGTMGR_WGT_TYPE_PHONE;
    }

#ifdef __USB_IN_NORMAL_MODE__
    if(srv_usb_is_in_mass_storage_mode() == MMI_TRUE)
    {
        tab_num = 1;
        selected_tab_index = MMI_WGTMGR_WGT_TYPE_PHONE;
    }    
#endif

    /* this is used to update tab info */
    mmi_frm_scrn_tab_change_page_items(
        GRP_ID_WGTMGR_MAIN, 
        SCR_ID_WGTMGR_MAIN, 
        tab_pages_info_array,
        tab_num);


    /* enter tab screen */
    mmi_frm_scrn_tab_enter(
        GRP_ID_WGTMGR_MAIN,
        SCR_ID_WGTMGR_MAIN, 
        NULL, 
        mmi_wgtmgr_entry_main_int, 
        tab_pages_info_array, 
        tab_num, 
        selected_tab_index);
    
    /* close the please wait screen */
    mmi_frm_scrn_close(GRP_ID_WGTMGR_MAIN, SCR_ID_WGTMGR_PLEASE_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_entry_please_wait
 * DESCRIPTION
 *  This function is to display please wait screen to user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_entry_please_wait(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
          GRP_ID_WGTMGR_MAIN, 
          SCR_ID_WGTMGR_PLEASE_WAIT, 
          NULL, 
          mmi_wgtmgr_entry_please_wait, 
          MMI_FRM_FULL_SCRN) == MMI_TRUE)
    {
    #if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_MAINLCD_320X480__)  
        ShowCategory66Screen(
          STR_ID_WGTMGR_WIDGET_MANAGER,
          0,	 
          0,
          0,
          0,
          0,
          (U8*) GetString(STR_GLOBAL_PLEASE_WAIT),
          mmi_get_event_based_image(MMI_EVENT_PROGRESS),
          NULL);
    #else
        ShowCategory66Screen(
          STR_ID_WGTMGR_WIDGET_MANAGER,
          IMG_ID_WGTMGR_APP,
          0,
          0,
          0,
          0,
          (U8*) GetString(STR_GLOBAL_PLEASE_WAIT),
          mmi_get_event_based_image(MMI_EVENT_PROGRESS),
          NULL);
    #endif

        mmi_wgtmgr_clear_endkey_hdlr();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_entry_tab_phone_widgets
 * DESCRIPTION
 *  This function is used to enter SCR_ID_WGTMGR_TAB_PHONE_WIDGETS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_entry_tab_phone_widgets(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    PU8 icons[3];
    mmi_wgtmgr_cntx_struct *cntx_p = g_mmi_wgtmgr_cntx_p;
    S32 highlighted_item = 0;
    U16 left_key_string = STR_ID_WGTMGR_ENABLE;
    MMI_BOOL highlighted_wgt_is_enabled;
    void (*soft_key_hdlr) (void);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_tab_page_enter(
          GRP_ID_WGTMGR_MAIN, 
          SCR_ID_WGTMGR_MAIN, 
          SCR_ID_WGTMGR_TAB_PHONE_WIDGETS, 
          NULL, 
          mmi_wgtmgr_entry_tab_phone_widgets, 
          MMI_FRM_TAB_PAGE) == MMI_FALSE)
    {
        return;
  	}

    /* register highlight handler */
    RegisterHighlightHandler(mmi_wgtmgr_phone_wgt_highlight_hdlr);

    /* get gui buffer */
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    /* assign icons used to show enabled/disabled status and network access */
    icons[0] = get_image(IMG_ID_WGTMGR_ENABLED); //TODO
    icons[1] = get_image(IMG_ID_WGTMGR_WEB); //TODO
    icons[2] = get_image(IMG_NONE);

    /* if the highlighted tab page remains the same, use the value */
    if (cntx_p->selected_tab_index == MMI_WGTMGR_WGT_TYPE_PHONE)
    {
        highlighted_item = cntx_p->selected_item_index;
    }

    /* assign selected tab index to SRV_WGTMGR_WGT_TYPE_PHONE */    
    cntx_p->selected_tab_index = MMI_WGTMGR_WGT_TYPE_PHONE;

    highlighted_wgt_is_enabled = srv_wgtmgr_is_wgt_enabled(SRV_WGTMGR_WGT_TYPE_PHONE, highlighted_item);

    if (highlighted_wgt_is_enabled == MMI_TRUE)
   	{
        left_key_string = STR_ID_WGTMGR_DISABLE;
    }

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    /* show category */
    wgui_cat1006_show(
        (WCHAR*) get_string(STR_ID_WGTMGR_PHONE_WIDGETS),
        NULL,
        (WCHAR*) get_string(left_key_string),
        NULL,              /* left_softkey_icon */
        (WCHAR*) get_string(STR_GLOBAL_BACK),
        NULL,              /* right_softkey_icon */
        srv_wgtmgr_get_wgt_num(SRV_WGTMGR_WGT_TYPE_PHONE), /* number_of_items */
        mmi_wgtmgr_phone_widgets_get_async_items,
        NULL,              /* get hint callback */
        NULL,              /* get image path */
        srv_wgtmgr_get_phone_wgt_icon_id, /* get image id */
        icons,
        1,                 /* number_of_string, phone widget menu item has only 1 string */
        3,                 /* number_of_icon */
        highlighted_item,           /* highlighted_item */
        MMI_WGTMGR_WGT_TYPE_PHONE,  /* highlighted_tab */
        gui_buffer);

    /* register key handler */
    if (highlighted_wgt_is_enabled == MMI_TRUE)
   	{
        soft_key_hdlr = mmi_wgtmgr_disable_wgt;
    }
    else
    {
        soft_key_hdlr = mmi_wgtmgr_enable_wgt;
    }


    SetCenterSoftkeyFunction(soft_key_hdlr, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(soft_key_hdlr, KEY_EVENT_UP);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__ 
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
#endif /* __MMI_TOUCH_SCREEN__ */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_entry_tab_downloaded_widgets
 * DESCRIPTION
 *  This function is used to enter STR_ID_WGTMGR_DOWNLOADED_WIDGETS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_entry_tab_downloaded_widgets(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    PU8 icons[3];
    S32 highlighted_item = 0;
    mmi_wgtmgr_cntx_struct *cntx_p = g_mmi_wgtmgr_cntx_p;	
    S32 dwgt_num = srv_wgtmgr_get_wgt_num(SRV_WGTMGR_WGT_TYPE_DOWNLOADED);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_tab_page_enter(
          GRP_ID_WGTMGR_MAIN, 
          SCR_ID_WGTMGR_MAIN, 
          SCR_ID_WGTMGR_TAB_DOWNLOADED_WIDGETS, 
          NULL, 
          mmi_wgtmgr_entry_tab_downloaded_widgets, 
          MMI_FRM_TAB_PAGE) == MMI_FALSE)
   	{
        return;
    }

    RegisterHighlightHandler(mmi_wgtmgr_downloaded_wgt_highlight_hdlr);

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    icons[0] = get_image(IMG_ID_WGTMGR_ENABLED);
    icons[1] = get_image(IMG_ID_WGTMGR_WEB);
    icons[2] = get_image(IMG_NONE);	

    if (cntx_p->selected_tab_index == MMI_WGTMGR_WGT_TYPE_DOWNLOADED)
    {
        highlighted_item = cntx_p->selected_item_index;
    }
    cntx_p->selected_tab_index = MMI_WGTMGR_WGT_TYPE_DOWNLOADED;

    wgui_cat1006_show(
        (WCHAR*) get_string(STR_ID_WGTMGR_DOWNLOADED_WIDGETS),
        get_image(IMG_ID_WGTMGR_DOWNLOADED_WIDGETS), /* title_icon */
        (WCHAR*) get_string(STR_GLOBAL_OPTIONS),
        NULL, /* left_softkey_icon */
        (WCHAR*) get_string(STR_GLOBAL_BACK),
        NULL, /* right_softkey_icon */
        dwgt_num,   /* number_of_items */
        mmi_wgtmgr_downloaded_widgets_get_async_items,
        NULL, /* get hint callback */
        mmi_wgtmgr_get_downloaded_wgt_icon_path, /* get image path */
        0, /* get image id */
        icons,
        3,  /* number_of_string */
        3,  /* number_of_icon */
        highlighted_item,  /* highlighted_item */
        MMI_WGTMGR_WGT_TYPE_DOWNLOADED,  /* highlighted_tab */
        gui_buffer);

    /* set key handlers */
    if (dwgt_num == 0)
    {
        ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
        SetCenterSoftkeyFunction(mmi_wgtmgr_entry_options, KEY_EVENT_UP);
    }

    SetLeftSoftkeyFunction(mmi_wgtmgr_entry_options, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);	
#ifdef __MMI_TOUCH_SCREEN__ 
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
#endif /* __MMI_TOUCH_SCREEN__ */

#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_TOUCH_SCREEN__)  
    wgui_register_tap_callback(mmi_wgtmgr_downloaded_wgt_tap_callback);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_entry_options
 * DESCRIPTION
 *  This function is used to create options menu with menu CUI
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_entry_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_WGTMGR_MAIN, GRP_ID_WGTMGR_OPTIONS, mmi_wgtmgr_options_proc, NULL);
    mmi_frm_group_enter(GRP_ID_WGTMGR_OPTIONS, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    g_id = cui_menu_create(
             GRP_ID_WGTMGR_OPTIONS, 
             CUI_MENU_SRC_TYPE_RESOURCE, 
             CUI_MENU_TYPE_OPTION, 
             MENU_ID_WGTMGR_OPTIONS, 
             MMI_FALSE, 
             NULL);

    cui_menu_run(g_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_entry_deleting
 * DESCRIPTION
 *  This function is to display deleting menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_entry_deleting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(GRP_ID_WGTMGR_OPTIONS, SCR_ID_WGTMGR_DELETING, NULL, mmi_wgtmgr_entry_deleting, MMI_FRM_FULL_SCRN))
    {
    #if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_MAINLCD_320X480__)
        ShowCategory66Screen(
          STR_ID_WGTMGR_WIDGET_MANAGER,
          0,
          0,
          0,
          0,
          0,
          (U8*) GetString(STR_GLOBAL_DELETING),
          mmi_get_event_based_image(MMI_EVENT_PROGRESS),
          NULL);
    #else
        ShowCategory66Screen(
          STR_ID_WGTMGR_WIDGET_MANAGER,
          IMG_ID_WGTMGR_APP,
          0,
          0,
          0,
          0,
          (U8*) GetString(STR_GLOBAL_DELETING),
          mmi_get_event_based_image(MMI_EVENT_PROGRESS),
          NULL);
    #endif

        mmi_wgtmgr_clear_endkey_hdlr();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_main_proc
 * DESCRIPTION
 *  This function is the group event proc of Widget Manager Group
 * PARAMETERS
 *  evt: [IN] group event
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_wgtmgr_main_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    { 
        case EVT_ID_GROUP_DEINIT:
            mmi_wgtmgr_exit();
            break;

        case EVT_ID_MEM_IS_ENOUGH:
            mmi_wgtmgr_main_pre_entry();
            break;

        case EVT_ID_MEM_CANCELED:
            mmi_wgtmgr_exit();
            mmi_frm_group_close(GRP_ID_WGTMGR_MAIN);
            break;

        case EVT_ID_MEM_FREE_ASM:
            mmi_wgtmgr_exit();
            mmi_frm_group_close(GRP_ID_WGTMGR_MAIN);
            return MMI_MEM_FREED;
    }
    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_options_proc
 * DESCRIPTION
 *  This function is the group event proc of Widget Manager option group
 * PARAMETERS
 *  evt: [IN] group event
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_wgtmgr_options_proc(mmi_event_struct *evt)
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

            if (menu_evt->parent_menu_id == MENU_ID_WGTMGR_OPTIONS)
            { 
                mmi_wgtmgr_set_option_list(menu_evt);
            }
            if (menu_evt->parent_menu_id == MENU_ID_WGTMGR_SORT_BY)
            {
                mmi_wgtmgr_set_sort_by_list(menu_evt);
           	}
            break;

		
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:

            switch (menu_evt->highlighted_menu_id)
            {
                case MENU_ID_WGTMGR_ENABLE:
                   mmi_wgtmgr_enable_wgt();
                   mmi_frm_group_close(GRP_ID_WGTMGR_OPTIONS);
                   break;

                case MENU_ID_WGTMGR_DISABLE:
                   mmi_wgtmgr_disable_wgt();
                   mmi_frm_group_close(GRP_ID_WGTMGR_OPTIONS);
                   break;

                case MENU_ID_WGTMGR_DELETE:
                   mmi_wgtmgr_display_delete_wgt_confirm();
 					break;
				               
                case MENU_ID_WGTMGR_SORT_BY:
                    break;

                case MENU_ID_WGTMGR_SORT_BY_NAME:
                    mmi_wgtmgr_set_sort_order(SRV_WGTMGR_SORT_BY_NAME);
                    break;

                case MENU_ID_WGTMGR_SORT_BY_INSTALLED_TIME:
                    mmi_wgtmgr_set_sort_order(SRV_WGTMGR_SORT_BY_INSTALLED_TIME);                 
                    break;

                case MENU_ID_WGTMGR_SETTINGS:
                    mmi_wgtmgr_entry_settings();
                    break;
                default:
                    MMI_ASSERT(0);
                    break;

            }

            break; /* EVT_ID_CUI_MENU_ITEM_SELECT */           
   
       case EVT_ID_CUI_MENU_CLOSE_REQUEST:
           cui_menu_close(menu_evt->sender_id);		   
           break;

        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct *)evt;
            if (alert->result == MMI_ALERT_CNFM_YES)
            {
                mmi_wgtmgr_delete_wgt();
            }
            else if (alert->result == MMI_ALERT_CNFM_NO)
            {
                mmi_wgtmgr_leave_option_menu();
            }
            break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_phone_widgets_get_async_items
 * DESCRIPTION
 *  This function is to get phone widget info asynchronously
 * PARAMETERS
 *  start_indx:[IN] the first item to get 
 *  menuData:  [OUT] an array to store the widget info
 *  num_item:  [IN] number of items to get
 * RETURNS
 *  number of items gotten
 *****************************************************************************/
static S32 mmi_wgtmgr_phone_widgets_get_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    srv_wgtmgr_phone_wgt_info_struct info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if out of valid range */
    if (start_indx + num_item > srv_wgtmgr_get_wgt_num(SRV_WGTMGR_WGT_TYPE_PHONE))
    {
        MMI_ASSERT(0);
    }

    for (i = 0; i < num_item; i++)
    {
        srv_wgtmgr_get_phone_wgt_info(i + start_indx, &info);
        mmi_ucs2cpy((CHAR*) menuData[i].item_list[0], (const CHAR*) get_string(info.name));
        mmi_ucs2cpy((CHAR*) menuData[i].item_list[1], NULL); /* Phone widgets have no size info */
        mmi_ucs2cpy((CHAR*) menuData[i].item_list[2], NULL); /* Phone widgets have no version info */
        if (info.enabled == MMI_TRUE)
        {
            menuData[i].image_list[0] = get_image(IMG_ID_WGTMGR_ENABLED);//TODO
        }
        else
        {
            menuData[i].image_list[0] = get_image(IMG_NONE);
        }

        if (info.attribute & SRV_WGTMGR_ATTR_NETWORK_ACCESS)
        {
            menuData[i].image_list[1] = get_image(IMG_ID_WGTMGR_WEB);
        }
		else
        {
            menuData[i].image_list[1] = get_image(IMG_NONE);
        }
        menuData[i].image_list[2] = get_image(IMG_NONE);
    }
    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_get_downloaded_wgt_icon_path
 * DESCRIPTION
 *  This is used to get the icon path of a downloaded widget by index in Widget Manager App
 * PARAMETERS
 *  index : [IN]  The index of the downloaded widget
 *  path  : [OUT] The path of icon
 * RETURNS
 *  MMI_TRUE if successfully
 *****************************************************************************/
static MMI_BOOL mmi_wgtmgr_get_downloaded_wgt_icon_path(S32 index, WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    srv_wgtmgr_get_downloaded_wgt_icon_path(mmi_wgtmgr_get_dwgt_id_by_index(index), path);
    return MMI_TRUE;	
}



/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_downloaded_widgets_get_async_items
 * DESCRIPTION
 *  This function is to get downloaded widget info asynchronously
 * PARAMETERS
 *  start_indx:[IN] the first item to get 
 *  menuData:  [OUT] an array to store the widget info
 *  num_item:  [IN] number of items to get
 * RETURNS
 *  number of items gotten
 *****************************************************************************/
static S32 mmi_wgtmgr_downloaded_widgets_get_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    srv_wgtmgr_downloaded_wgt_info_struct info;
		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (start_indx + num_item > srv_wgtmgr_get_wgt_num(SRV_WGTMGR_WGT_TYPE_DOWNLOADED))
    {
        MMI_ASSERT(0);
    }

    for (i = 0; i < num_item; i++)
    {
        srv_wgtmgr_get_downloaded_wgt_info(mmi_wgtmgr_get_dwgt_id_by_index(i + start_indx), &info);
        mmi_ucs2cpy((CHAR*) menuData[i].item_list[0], (CHAR*) info.name);
        mmi_ucs2cpy((CHAR*) menuData[i].item_list[1], (CHAR*) info.size);
        mmi_ucs2cpy((CHAR*) menuData[i].item_list[2], (CHAR*) info.version);
        if (info.enabled == MMI_TRUE)
        {
            menuData[i].image_list[0] = get_image(IMG_ID_WGTMGR_ENABLED);
        }
        else
        {
            menuData[i].image_list[0] = get_image(IMG_NONE);
        }

        if (info.attribute & SRV_WGTMGR_ATTR_NETWORK_ACCESS)
        {
            menuData[i].image_list[1] = get_image(IMG_ID_WGTMGR_WEB);
        }
		else
        {
            menuData[i].image_list[1] = get_image(IMG_NONE);
        }
        menuData[i].image_list[2] = get_image(IMG_NONE);
    }
    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_phone_wgt_highlight_hdlr
 * DESCRIPTION
 *  This function is the highlight handler of phone widgets tab page
 * PARAMETERS
 *  index: [IN] the index of widget
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_phone_wgt_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID str_id;
    void (*soft_key_hdlr) (void);
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_wgtmgr_cntx_p->selected_item_index = index;
    if (srv_wgtmgr_is_wgt_enabled(SRV_WGTMGR_WGT_TYPE_PHONE, index) == MMI_TRUE)
    {
        str_id = STR_ID_WGTMGR_DISABLE;
        soft_key_hdlr = mmi_wgtmgr_disable_wgt;
    }
    else
   	{
        str_id = STR_ID_WGTMGR_ENABLE;
        soft_key_hdlr = mmi_wgtmgr_enable_wgt;
    }

    SetCenterSoftkeyFunction(soft_key_hdlr, KEY_EVENT_UP);
    ChangeLeftSoftkey(str_id, 0);
    SetLeftSoftkeyFunction(soft_key_hdlr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_downloaded_wgt_highlight_hdlr
 * DESCRIPTION
 *  This function is the highlight handler of downloaded widgets tab page
 * PARAMETERS
 *  index: [IN] the index of widget
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_downloaded_wgt_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_downloaded_wgt_info_struct *info_p = NULL;
    void (*soft_key_hdlr) (void);
    MMI_IMG_ID img_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_wgtmgr_cntx_p->selected_item_index = index;

    info_p = (srv_wgtmgr_downloaded_wgt_info_struct*)OslMalloc(sizeof(srv_wgtmgr_downloaded_wgt_info_struct));
    if (info_p == NULL)
    {
        MMI_ASSERT(0);
    }

    /* get widget info */
    srv_wgtmgr_get_downloaded_wgt_info(
        mmi_wgtmgr_get_dwgt_id_by_index(g_mmi_wgtmgr_cntx_p->selected_item_index), 
        info_p);

    if (info_p->attribute & SRV_WGTMGR_ATTR_NOT_DISABLE)
    {
        img_id = IMG_GLOBAL_OPTION_CSK;
        soft_key_hdlr = mmi_wgtmgr_entry_options;
    }
    else
    {
        img_id = IMG_GLOBAL_COMMON_CSK;
        if (info_p->enabled == MMI_TRUE)
        {
            soft_key_hdlr = mmi_wgtmgr_disable_wgt;
        }
		else
        {
            soft_key_hdlr = mmi_wgtmgr_enable_wgt;
        }
    }

    ChangeCenterSoftkey(0, img_id);
    SetCenterSoftkeyFunction(soft_key_hdlr, KEY_EVENT_UP);

    /* free control buffer */
    OslMfree(info_p);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_set_option_list
 * DESCRIPTION
 *  This function is used to set menu CUI component
 * PARAMETERS
 *  evt: [IN] group event
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_set_option_list(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_downloaded_wgt_info_struct *info_p = NULL;
    MMI_ID sender_id = menu_evt->sender_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_MAINLCD_320X480__)
    cui_menu_set_currlist_title(sender_id, get_string(STR_GLOBAL_OPTIONS), 0);
#else
    cui_menu_set_currlist_title(sender_id, get_string(STR_GLOBAL_OPTIONS), get_image(IMG_ID_WGTMGR_APP));
#endif

    cui_menu_enable_center_softkey(sender_id, 0, IMG_GLOBAL_COMMON_CSK);

    if (srv_wgtmgr_get_wgt_num(SRV_WGTMGR_WGT_TYPE_DOWNLOADED) == 0)
    {
        cui_menu_set_item_hidden(sender_id, MENU_ID_WGTMGR_ENABLE, MMI_TRUE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_WGTMGR_DISABLE, MMI_TRUE);
        cui_menu_set_item_hidden(sender_id, MENU_ID_WGTMGR_DELETE, MMI_TRUE);
        return;
    }

    /* allocate control buffer for widget info */
    info_p = (srv_wgtmgr_downloaded_wgt_info_struct*)OslMalloc(sizeof(srv_wgtmgr_downloaded_wgt_info_struct));
    if (info_p == NULL)
    {
        MMI_ASSERT(0);
    }

    /* get widget info */
    srv_wgtmgr_get_downloaded_wgt_info(
        mmi_wgtmgr_get_dwgt_id_by_index(g_mmi_wgtmgr_cntx_p->selected_item_index), 
        info_p);

    /* if widget is enabled or is not disable, hide enable option */
    if ((info_p->attribute & SRV_WGTMGR_ATTR_NOT_DISABLE) ||
        (info_p->enabled == MMI_TRUE))
    {
        cui_menu_set_item_hidden(sender_id, MENU_ID_WGTMGR_ENABLE, MMI_TRUE);
    }

    /* if widget is disabled or is not disable, hide disable option */
    if ((info_p->attribute & SRV_WGTMGR_ATTR_NOT_DISABLE) ||
        (info_p->enabled == MMI_FALSE))
   	{
        cui_menu_set_item_hidden(sender_id, MENU_ID_WGTMGR_DISABLE, MMI_TRUE);
    }

    /* if widget is not deletable, hide delete option */
    if (info_p->attribute & SRV_WGTMGR_ATTR_UNDELETABLE)
    {
        cui_menu_set_item_hidden(sender_id, MENU_ID_WGTMGR_DELETE, MMI_TRUE);
    }

    /* free control buffer */
    OslMfree(info_p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_set_sort_by_list
 * DESCRIPTION
 *  This function is used to set menu CUI component
 * PARAMETERS
 *  evt: [IN] group event
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_set_sort_by_list(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id highlight_item = MENU_ID_WGTMGR_SORT_BY_INSTALLED_TIME;
    MMI_ID sender_id = menu_evt->sender_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_MAINLCD_320X480__)
    cui_menu_set_currlist_title(sender_id, get_string(STR_GLOBAL_SORT_BY), 0);
#else
    cui_menu_set_currlist_title(sender_id, get_string(STR_GLOBAL_SORT_BY), get_image(IMG_ID_WGTMGR_APP));
#endif
    cui_menu_set_currlist_flags(sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

    if (srv_wgtmgr_get_sort_order() == SRV_WGTMGR_SORT_BY_NAME)
    {
        highlight_item = MENU_ID_WGTMGR_SORT_BY_NAME;
    }

    cui_menu_set_currlist_highlighted_id(sender_id, highlight_item);
    cui_menu_enable_center_softkey(sender_id, 0, IMG_GLOBAL_COMMON_CSK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_delete_finish_callback
 * DESCRIPTION
 *  This function is invoked when deletion is finished
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_delete_finish_callback(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple(get_string(STR_GLOBAL_DELETED), MMI_EVENT_SUCCESS, GRP_ID_WGTMGR_MAIN, NULL);
    mmi_frm_group_close(GRP_ID_WGTMGR_OPTIONS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_get_dwgt_id_by_index
 * DESCRIPTION
 *  This function is to translate from index to widget id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_wgtmgr_get_dwgt_id_by_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_wgtmgr_cntx_p->sort_list[index];
}



/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_enable_wgt
 * DESCRIPTION
 *  This function is used to enable a widget and display success popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_enable_wgt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_wgt_type_enum type;
    S32 id = g_mmi_wgtmgr_cntx_p->selected_item_index;	
    S32 ret;
    U16 str = STR_ID_WGTMGR_ENABLED;
    mmi_event_notify_enum event = MMI_EVENT_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_wgtmgr_cntx_p->selected_tab_index == MMI_WGTMGR_WGT_TYPE_PHONE)
    {
        type = SRV_WGTMGR_WGT_TYPE_PHONE;
    }
    else
    {
        type = SRV_WGTMGR_WGT_TYPE_DOWNLOADED;
        id = mmi_wgtmgr_get_dwgt_id_by_index(id);		
    }

    ret = srv_wgtmgr_enable_wgt(type, id);

    if (ret == SRV_WGTMGR_RET_MEMCARD_NOT_EXIST)
    {
        str = STR_GLOBAL_INSERT_MEMORY_CARD;
        event = MMI_EVENT_FAILURE;
    }
    else if (ret == SRV_WGTMGR_RET_EXCEED_MAX_ENABLED_NUM)
    {
        str = STR_ID_WGTMGR_OVER_MAX_ENABLED;
        event = MMI_EVENT_FAILURE;
    }    
    else if (ret == SRV_WGTMGR_RET_FILE_NOT_EXIST)
    {
        str = STR_GLOBAL_FILE_NOT_FOUND;
        event = MMI_EVENT_FAILURE;
    }
    mmi_popup_display_simple(get_string(str), event, GRP_ID_WGTMGR_MAIN, NULL);
		
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_disable_wgt
 * DESCRIPTION
 *  This function is used to disable a widget and display success popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_disable_wgt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_wgt_type_enum type;
    U16 id = g_mmi_wgtmgr_cntx_p->selected_item_index;		;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_wgtmgr_cntx_p->selected_tab_index == MMI_WGTMGR_WGT_TYPE_PHONE)
    {
        type = SRV_WGTMGR_WGT_TYPE_PHONE;
    }
    else
    {
        type = SRV_WGTMGR_WGT_TYPE_DOWNLOADED;
        id = mmi_wgtmgr_get_dwgt_id_by_index(g_mmi_wgtmgr_cntx_p->selected_item_index);
    }

    srv_wgtmgr_disable_wgt(type, id);
    mmi_popup_display_simple(get_string(STR_ID_WGTMGR_DISABLED), MMI_EVENT_SUCCESS, GRP_ID_WGTMGR_MAIN, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_set_sort_order
 * DESCRIPTION
 *  This function is used to set sort order
 * PARAMETERS
 *  index: [IN] sort order
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_set_sort_order(srv_wgtmgr_sort_order_enum index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_set_sort_order(index);
    mmi_popup_display_simple(get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, GRP_ID_WGTMGR_MAIN, NULL);
    mmi_frm_group_close(GRP_ID_WGTMGR_OPTIONS); 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_display_delete_wgt_confirm
 * DESCRIPTION
 *  This function is used to display delete widget confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_display_delete_wgt_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);

    arg.parent_id = GRP_ID_WGTMGR_OPTIONS;
    arg.f_auto_map_empty_softkey = MMI_FALSE;

    mmi_confirm_display(
          get_string(STR_ID_WGTMGR_DELETE_THIS_WIDGET),
          MMI_EVENT_QUERY,
          &arg);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_delete_wgt
 * DESCRIPTION
 *  This function is used to delete a widget
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wgtmgr_delete_wgt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wgtmgr_entry_deleting();
    srv_wgtmgr_delete_wgt(mmi_wgtmgr_get_dwgt_id_by_index(g_mmi_wgtmgr_cntx_p->selected_item_index), mmi_wgtmgr_delete_finish_callback, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_downloaded_wgt_tap_callback
 * DESCRIPTION
 *  This function is the callback function for FTE
 * PARAMETERS
 *  tap_type: [IN] type of tap
 *  index: [IN] index of tapped item
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_TOUCH_SCREEN__)
static void mmi_wgtmgr_downloaded_wgt_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_downloaded_wgt_info_struct *info_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        /* allocate control buffer for widget info */
        info_p = (srv_wgtmgr_downloaded_wgt_info_struct*)OslMalloc(sizeof(srv_wgtmgr_downloaded_wgt_info_struct));
        if (info_p == NULL)
        {
            MMI_ASSERT(0);
        }

        /* get widget info */
        srv_wgtmgr_get_downloaded_wgt_info(mmi_wgtmgr_get_dwgt_id_by_index(index), info_p);

        if (info_p->attribute & SRV_WGTMGR_ATTR_NOT_DISABLE)
        {
            mmi_wgtmgr_entry_options();
        }
        else
        {
            if (info_p->enabled == MMI_TRUE)
            {
                mmi_wgtmgr_disable_wgt();
            }
            else
            {
                mmi_wgtmgr_enable_wgt();
            }
        }
        /* free control buffer */
        OslMfree(info_p);
    }	
}
#endif

/************************************************************************/
/* Global Function Definition                                                  */
/************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_init_evt_hdlr
 * DESCRIPTION
 *  This function is used to initialize the Widget Manager Application
 *  It should be invoked in InitializeAll()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_wgtmgr_init_evt_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wgtmgr_init();
    return MMI_RET_OK;	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_main_highlight_hdlr
 * DESCRIPTION
 *  This function is the highlight handler of Widget Manager in phone setting menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wgtmgr_main_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_wgtmgr_entry_main, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_entry_main
 * DESCRIPTION
 *  This function is the entry of Widget Manager Application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wgtmgr_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* create screen group first */
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_WGTMGR_MAIN, mmi_wgtmgr_main_proc, NULL);

    /* enter screen group for displaying Widget Manager screen */
    mmi_frm_group_enter(GRP_ID_WGTMGR_MAIN, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_wgtmgr_main_pre_entry();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_clear_endkey_hdlr
 * DESCRIPTION
 *  This function is used to clear End Key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wgtmgr_clear_endkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_leave_option_menu
 * DESCRIPTION
 *  This function is to leave option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wgtmgr_leave_option_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(GRP_ID_WGTMGR_OPTIONS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_menu_handler
 * DESCRIPTION
 *  This function is to leave option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_wgtmgr_menu_handler(cui_menu_event_struct *evt, MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((evt->evt_id == EVT_ID_CUI_MENU_ITEM_SELECT || 
         evt->evt_id == EVT_ID_CUI_MENU_ITEM_CSK_SELECT) && 
         evt->highlighted_menu_id == MENU_ID_WGTMGR)
    {
        mmi_wgtmgr_entry_main();
        return MMI_RET_OK;
    }
    return MMI_RET_DONT_CARE;
}
#endif /* __MMI_GADGET_SUPPORT__ */

