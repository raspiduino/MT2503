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
 * ToDoListApp.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * ToDolist interfaces with other applications.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
 
/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"
 
#ifdef __MMI_TODOLIST__

#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
//#include "mtpnp_ad_master_if.h"
//#include "mtpnp_ad_master_common_def.h"
#include "NetSetSrvGprot.h"
#include "NetSetAppGprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_util.h"
#include "CustMenuRes.h"
#include "wgui_categories_list.h"
#include "GlobalConstants.h"
#include "custom_mmi_default_value.h"
#include "mmi_frm_mem_gprot.h"
#include "app_datetime.h"
#include "string.h"
#include "ImeGprot.h"
#include "wgui_categories_popup.h"
#include "CustDataRes.h"
#include "custom_events_notify.h"
#include "Unicodexdcl.h"
#include "wgui_categories.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "IndianCalendarDef.h"
#include "mmi_common_app_trc.h"
#include "NotificationGprot.h"
#include "CalendarGprot.h"
#include "mmi_rp_srv_syncml_def.h"
#include "AlertScreen.h"
#include "HomeScreenOp11V32Def.h"
#include "mmi_rp_app_organizer_def.h"
#include "gui_data_types.h"
#include "kal_trace.h"
#include "mmi_frm_history_gprot.h"
#include "Conversions.h"
#include "CommonScreens.h"
#include "Fseditorcuigprot.h" 
#include "SyncMLGProt.h"
#include "AlarmFrameworkProt.h"
#include "CalendarProt.h"
#include "BirthdayProt.h"
#include "ToDoListProt.h"
#include "ToDoListSrvGprot.h"
#include "ToDoListGprot.h"
#include "vCalendar.h"
#include "Inlinecuigprot.h"
#include "Menucuigprot.h"
#include "mmi_rp_srv_vcalendar_def.h"
#include "mmi_rp_app_todolist_def.h"
#include "mmi_rp_app_calendar_def.h"
#include "SimCtrlSrvGprot.h"  
#include "Dmuigprot.h"
#ifdef __MMI_BIRTHDAY_REMINDER__
#include "BirthdayProt.h"
#endif
#if 0
#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/* under construction !*/
/* under construction !*/
#endif
#endif
#if 0
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
#endif
#endif
#ifdef __MMI_VCALENDAR__
#include "Vcalsrvgprot.h"
#include "mmi_rp_srv_vcalendar_def.h"
#endif
#include "NwUsabSrvGprot.h"
#include "CalendarEventGprot.h"
#include "wgui_touch_screen.h"

/*****************************************************************************
 * Define
 *****************************************************************************/
#define MMI_TDL_TRACE0(sub_grp) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp)

#define MMI_TDL_TRACE1(sub_grp, arg) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg)
		
#define MMI_TDL_TRACE2(sub_grp, arg1, arg2) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2)

#define MMI_TDL_TRACE3(sub_grp, arg1, arg2, arg3) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2, arg3)
		

#define STATIC_DECLARATION
/*****************************************************************************
 * Static Declaration
 *****************************************************************************/

extern kal_bool g_is_entry_search_op;
#if 0
#ifdef __MMI_OP11_TODOLIST_DIARY_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_DIARY_SUPPORT__ */
#endif 

#if 0
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

void mmi_tdl_entry_search_process(void);

#if defined __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ || defined __MMI_SYNCML_SYNC_TASK_SUPPORT__
static U16 mmi_tdl_vcal_sync_err_mapping(U16 vCalenar_err);
#endif

#if 0
#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */
#endif

static void mmi_tdl_entry_search_list(void);

static void mmi_tdl_entry_search_int(void);
static mmi_ret mmi_tdl_search_proc(mmi_event_struct *evt);
static void mmi_tdl_entry_search_list_option(void);
static mmi_ret mmi_tdl_search_option_group_proc(mmi_event_struct* evt);

static void mmi_tdl_search_opt_menu_entry_hdlr(cui_menu_event_struct *menu_evt);
static void mmi_tdl_search_opt_menu_select_hdlr(cui_menu_event_struct *menu_evt);

const cui_inline_item_caption_struct cui_search_by_time_option =
{
    STR_GLOBAL_TIME
};

const cui_inline_set_item_struct cui_search_by_time[3] = 
{
    {CUI_INLINE_ITEM_ID_BASE + 0, CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH, 0, &cui_search_by_time_option},
    {CUI_INLINE_ITEM_ID_BASE + 1, CUI_INLINE_ITEM_TYPE_DATE | CUI_INLINE_ITEM_FULL_WIDTH, 0, NULL},
    {CUI_INLINE_ITEM_ID_BASE + 2, CUI_INLINE_ITEM_TYPE_TIME | CUI_INLINE_ITEM_FULL_WIDTH, 0, NULL},
};

#if 0
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif


/*****************************************************************************
 * Global Variable
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
extern void mmi_clndr_tap_list_callback(mmi_tap_type_enum tap_type, S32 index);
#endif
extern void mmi_clndr_entry_view_hdlr(void);

/*****************************************************************************
 * Local Function
 *****************************************************************************/ 


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_is_busy
 * DESCRIPTION
 *  TDL is busy now?
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE TDL is busy now
 *  MMI_FALSE TDL isn't busy now
 *****************************************************************************/
MMI_BOOL mmi_tdl_is_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 sg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (sg_id = GRP_ID_TDL_BEGIN; sg_id < GRP_ID_TDL_END; sg_id++)
    {
        if (mmi_frm_group_is_present(sg_id))
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  TDLShowAllList
 * DESCRIPTION
 *  Entry function of To Do List from Organizer
 *  Display all task list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TDLShowAllList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_tdl_cntx.curr_option = TODO_LIST_OPTION_TOTAL;
    g_tdl_cntx.vcal_filter = SRV_TDL_VCAL_TASK;
    mmi_tdl_entry_task_view_all();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_check_phone_lock
 * DESCRIPTION
 *  Check phone lock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_tdl_check_phone_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__
    if(mmi_dmui_is_phone_lock())
    {
        return MMI_TRUE;
    }
#endif

    return MMI_FALSE;
}

#if 0
#ifdef __MMI_OP11_TODOLIST_DIARY_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_TODOLIST_DIARY_SUPPORT__ */
#endif

#ifdef __MMI_TODO_SEARCH__
/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_entry_search_int
 * DESCRIPTION
 *  Proc function of search group.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_tdl_entry_search_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 *gui_buffer;
	U16 sub_items;
	U16 item_list[4];
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
             GRP_ID_TDL_SEARCH,
             SCR_ID_TDL_SEARCH,
             NULL,
             mmi_tdl_entry_search_int,
             MMI_FRM_FULL_SCRN))
    {
        return;
    }

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();        
    SetParentHandler(MITEM_TODO_LIST_SEARCH);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    
	if (g_tdl_cntx.vcal_filter == SRV_TDL_VCAL_TASK)
    {
        mmi_frm_hide_menu_item(MITEM_TODO_LIST_SEARCH_BY_LOC);
    }
    else
    {
        mmi_frm_unhide_menu_item(MITEM_TODO_LIST_SEARCH_BY_LOC);
    }

    sub_items = GetNumOfChild_Ext(MITEM_TODO_LIST_SEARCH);
    GetSequenceStringIds_Ext(MITEM_TODO_LIST_SEARCH, item_list); 

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ShowCategory52Screen(
        STR_GLOBAL_SEARCH,
        GetRootTitleIcon(ORGANIZER_TODOLIST_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        sub_items,
        item_list,
        (PU16)gIndexIconsImageList,
        0,
        0,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_entry_search_by_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tdl_entry_search_by_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    cui_inline_struct inline_data;
    cui_inline_item_date_time_struct date;
    cui_inline_item_time_struct time;    
    mmi_tdl_search_group_data_struct *search_group_data;
    MYTIME curr_time;
    
	/*----------------------------------------------------------------*/
    /* Code Body      												  */
    /*----------------------------------------------------------------*/  
    g_tdl_cntx.search.type = SRV_TDL_SEARCH_TYPE_TIME;
    inline_data.items_count = 3;
    inline_data.title = STR_ID_TODO_SEARCH_BY_TIME;
    inline_data.title_icon = GetRootTitleIcon(ORGANIZER_TODOLIST_MENU);
    inline_data.screen_flag = CUI_INLINE_SCREEN_DISABLE_DONE;
    inline_data.softkey = NULL;
    inline_data.items = cui_search_by_time;    
    search_group_data = 
            (mmi_tdl_search_group_data_struct*)OslMalloc(sizeof(mmi_tdl_search_group_data_struct));
            
    if (SRV_TDL_VCAL_TASK == g_tdl_cntx.vcal_filter)            
    {
        search_group_data->parent_id = GRP_ID_TDL_MAIN;
    }
    else
    {
        search_group_data->parent_id = GRP_ID_CAL_MAIN;
    }
    
    search_group_data->group_id = 
            mmi_frm_group_create(search_group_data->parent_id, GRP_ID_TDL_SEARCH, mmi_tdl_search_proc, search_group_data);
    mmi_frm_group_enter(GRP_ID_TDL_SEARCH, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    search_group_data->cui_inline_gid = cui_inline_create(GRP_ID_TDL_SEARCH, &inline_data);
    if (search_group_data->cui_inline_gid != GRP_ID_INVALID)
    {
        GetDateTime(&curr_time);
        memset(&date, 0, sizeof(cui_inline_item_date_time_struct));
        date.year = curr_time.nYear;
        date.month = curr_time.nMonth;
        date.day = curr_time.nDay;
        time.date_time.hour = curr_time.nHour;
        time.date_time.minute = curr_time.nMin;
        time.date_time.second = 0;
        cui_inline_set_value(search_group_data->cui_inline_gid, CUI_INLINE_ITEM_ID_BASE + 1, &date);
        cui_inline_set_value(search_group_data->cui_inline_gid, CUI_INLINE_ITEM_ID_BASE + 2, &time);
        cui_inline_run(search_group_data->cui_inline_gid);
    }
    else
    {
        mmi_frm_group_close(GRP_ID_TDL_SEARCH);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_search_proc
 * DESCRIPTION
 *  Exit function of task view all application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_tdl_search_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_tdl_search_group_data_struct *search_group_data = evt->user_data;
    cui_tdl_save_result_struct *tdl_save_evt = (cui_tdl_save_result_struct*)evt;
    cui_inline_item_date_time_struct date;
    cui_inline_item_time_struct time;   
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_ENTER:
            g_is_entry_search_op = KAL_TRUE;
			break;
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            cui_inline_get_value(
                        search_group_data->cui_inline_gid, 
                        CUI_INLINE_ITEM_ID_BASE + 1, 
                        &date);
            cui_inline_get_value(
                        search_group_data->cui_inline_gid, 
                        CUI_INLINE_ITEM_ID_BASE + 2, 
                        &time);
            g_tdl_cntx.search.u.date_time.nDay = (U8)date.day;
            g_tdl_cntx.search.u.date_time.nMonth = (U8)date.month;
            g_tdl_cntx.search.u.date_time.nYear = date.year;;
            g_tdl_cntx.search.u.date_time.nHour = (U8)time.date_time.hour;
            g_tdl_cntx.search.u.date_time.nMin = (U8)time.date_time.minute;
            
            mmi_tdl_entry_search_process();
            cui_inline_close(search_group_data->cui_inline_gid);
            break;
        }   
        case EVT_ID_CUI_INLINE_ABORT:
        case EVT_ID_CUI_FSEDITOR_ABORT:
        {
            mmi_frm_group_close(GRP_ID_TDL_SEARCH);
            break;
        }   
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        case EVT_ID_CUI_FSEDITOR_CSK_PRESSED:
        {
            S32 buf_size = MAX_TODO_LIST_NOTE;

            if (SRV_TDL_SEARCH_TYPE_LOCATION == g_tdl_cntx.search.type)
            {
                buf_size = MAX_TDL_LOCATION_LEN;
            }
            cui_fseditor_get_text(
                            search_group_data->fseditor_gid,
                            g_tdl_cntx.search.u.str_buf,
                            buf_size);
            mmi_tdl_entry_search_process();
            cui_fseditor_close(search_group_data->fseditor_gid);
            break;        
        }
        case EVT_ID_TDL_SAVE_FAIL:
        case EVT_ID_TDL_SAVE_CANCEL:
        case EVT_ID_TDL_SAVE_SUCCESS:
        {
            cui_tdl_save_close(tdl_save_evt->sender_id);
            cui_cal_save_close(tdl_save_evt->sender_id);
            break;
        }
    #ifdef __MMI_VCALENDAR__
        case EVT_ID_CUI_VCAL_FAIL:
        case EVT_ID_CUI_VCAL_SUCCESS:
        case EVT_ID_CUI_VCAL_FAIL_NOT_ENOUGH_MEMORY:
        case EVT_ID_CUI_VCAL_USER_CANCEL:
        {
            mmi_group_event_struct *evt_send = (mmi_group_event_struct*)evt;
            cui_vcal_save_to_file_close(evt_send->sender_id);
            break;
        }                
    #endif /* __MMI_VCALENDAR__ */
	    case EVT_ID_GROUP_DEINIT:
    #ifdef __MMI_CALENDAR_EVENT__
			if(g_tdl_cntx.special_search.event_buf)
			{
				OslMfree(g_tdl_cntx.special_search.event_buf);
				g_tdl_cntx.special_search.event_buf = NULL;
			}
			g_tdl_cntx.special_search.event_cnt = 0;
			g_tdl_cntx.special_search.search_id = 0;
			g_tdl_cntx.special_search.state = MMI_CAL_EVENT_SEARCH_IDLE;
			g_is_entry_search_op = KAL_FALSE;
			if(g_is_entry_search_op == KAL_FALSE)
			  //退出search group,返回view all的event list界面前，再做一次完整清除；
			  //否则，之前删除的event会在返回到view all的event list界面中又显示错误的出来；
			  mmi_clndr_reset_event_search_state();
    #endif
	        OslMfree(search_group_data);
            break;
        default:
            break;
    }
 
    return MMI_RET_OK;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_highlight_search_by_note
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tdl_entry_search_by_note(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_tdl_search_group_data_struct *search_group_data;
    
	/*----------------------------------------------------------------*/
    /* Code Body      												  */
    /*----------------------------------------------------------------*/
    search_group_data = 
            (mmi_tdl_search_group_data_struct*)OslMalloc(sizeof(mmi_tdl_search_group_data_struct));

    if (SRV_TDL_VCAL_TASK == g_tdl_cntx.vcal_filter)            
    {
        search_group_data->parent_id = GRP_ID_TDL_MAIN;
    }
    else
    {
        search_group_data->parent_id = GRP_ID_CAL_MAIN;
    }
    
    search_group_data->group_id = 
            mmi_frm_group_create(search_group_data->parent_id, GRP_ID_TDL_SEARCH, mmi_tdl_search_proc, search_group_data);
    mmi_frm_group_enter(GRP_ID_TDL_SEARCH, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    memset(g_tdl_cntx.search.u.str_buf, 0, MAX_TODO_NOTE_LEN);
    g_tdl_cntx.search.type = SRV_TDL_SEARCH_TYPE_SUBJECT;

    search_group_data->fseditor_gid = cui_fseditor_create(GRP_ID_TDL_SEARCH);

    if (0 == search_group_data->fseditor_gid)
    {
        return;
    }

    cui_fseditor_set_title(
                        search_group_data->fseditor_gid, 
                        STR_ID_TODO_SEARCH_BY_NOTE, 
                        GetRootTitleIcon(ORGANIZER_TODOLIST_MENU));

    cui_fseditor_set_buffer(
                        search_group_data->fseditor_gid, 
                        (PU8)g_tdl_cntx.search.u.str_buf, 
                        MAX_TODO_NOTE_LEN * ENCODING_LENGTH, 
                        MAX_TODO_NOTE_LEN - 1);                        
    cui_fseditor_run(search_group_data->fseditor_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_entry_search_by_location
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tdl_entry_search_by_location(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_tdl_search_group_data_struct *search_group_data;
    
	/*----------------------------------------------------------------*/
    /* Code Body      												  */
    /*----------------------------------------------------------------*/
    search_group_data = 
            (mmi_tdl_search_group_data_struct*)OslMalloc(sizeof(mmi_tdl_search_group_data_struct));
            
    search_group_data->parent_id = GRP_ID_CAL_MAIN;
    search_group_data->group_id = 
            mmi_frm_group_create(GRP_ID_CAL_MAIN, GRP_ID_TDL_SEARCH, mmi_tdl_search_proc, search_group_data);
    mmi_frm_group_enter(GRP_ID_TDL_SEARCH, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    memset(g_tdl_cntx.search.u.str_buf, 0, MAX_TDL_LOCATION_SIZE * ENCODING_LENGTH);
    g_tdl_cntx.search.type = SRV_TDL_SEARCH_TYPE_LOCATION;

    search_group_data->fseditor_gid = cui_fseditor_create(GRP_ID_TDL_SEARCH);

    if (0 == search_group_data->fseditor_gid)
    {
        return;
    }

    cui_fseditor_set_title(
                        search_group_data->fseditor_gid, 
                        STR_ID_TODO_SEARCH_BY_LOCATION, 
                        GetRootTitleIcon(ORGANIZER_TODOLIST_MENU));

    cui_fseditor_set_buffer(
                        search_group_data->fseditor_gid, 
                        (PU8)g_tdl_cntx.search.u.str_buf, 
                        MAX_TDL_LOCATION_SIZE * ENCODING_LENGTH, 
                        MAX_TDL_LOCATION_LEN);
                        
    cui_fseditor_set_input_method(
                        search_group_data->fseditor_gid, 
                        IMM_INPUT_TYPE_SENTENCE, 
                        NULL, 
                        0);                   
    cui_fseditor_run(search_group_data->fseditor_gid);
}


void mmi_tdl_search_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_tdl_cntx.curr_selected = index;
#ifdef __MMI_CALENDAR_EVENT__
	if(g_tdl_cntx.special_search.state == MMI_CAL_EVENT_SEARCH_DONE_OK)
    {
        g_tdl_cntx.curr_event_id = g_tdl_cntx.special_search.event_buf[index].event_id;
        g_tdl_cntx.curr_source_id = g_tdl_cntx.special_search.event_buf[index].source_id;
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_entry_search_process
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tdl_entry_search_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(GRP_ID_TDL_SEARCH, GLOBAL_SCR_DUMMY, NULL, NULL, MMI_FRM_FULL_SCRN))
    {
        return;
    }
    ShowCategory66Screen(
        STR_GLOBAL_SEARCH,
        GetRootTitleIcon(ORGANIZER_TODOLIST_MENU),
        0,
        0,
        0,
        0,
        (PU8)GetString(STR_GLOBAL_SEARCHING),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);	
	mmi_tdl_entry_search_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_entry_search_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_tdl_entry_search_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buff;
    S32 total_item = 0;
    U16 lsk_string = STR_GLOBAL_OPTIONS;
    U16 result;
    U32 i,j=0;
	MMI_BOOL ret;
	srv_tdl_event_struct *pevent = NULL;
	S32 job_id;
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
             GRP_ID_TDL_SEARCH,
             SCR_ID_TDL_SEARCH_RES_LIST,
             NULL,
             mmi_tdl_entry_search_list,
             MMI_FRM_FULL_SCRN))
    {
        return;
    }
	g_tdl_cntx.async_item_type = MMI_TDL_ASYNC_SUB;

    if(g_tdl_cntx.vcal_filter == SRV_TDL_VCAL_TASK)
    {
	    result = srv_tdl_search(
	                    g_tdl_cntx.sorted_list, 
	                    NUM_OF_TDL, 
	                    g_tdl_cntx.vcal_filter, 
	                    g_tdl_cntx.search, 
	                    &g_tdl_cntx.total);

	    result = srv_tdl_sort(
	                    g_tdl_cntx.sorted_list,
	                    g_tdl_cntx.total,
	                    SRV_TDL_SORT_TYPE_ENTRY_TIME);
		
		if (result != SRV_TDL_RESULT_OK)
	    {
	        return;
	    }
    }
	else
	{	
#ifdef __MMI_CALENDAR_EVENT__
		g_current_view_mode_context.current_mode = MMI_VIEW_MODE_SEARCH;
		if(g_tdl_cntx.special_search.state == MMI_CAL_EVENT_SEARCH_DONE_OK)
		{
			
		}
		else if(g_tdl_cntx.all_search.state == MMI_CAL_EVENT_SEARCH_DONE_OK)
		{
			if(g_tdl_cntx.special_search.event_buf)
			{
				OslMfree(g_tdl_cntx.special_search.event_buf);
				g_tdl_cntx.special_search.event_buf = NULL;
			}
			
			if(g_tdl_cntx.all_search.event_cnt > 0)
			{
			    g_tdl_cntx.special_search.event_buf = (srv_tdl_event_id_struct *)OslMalloc
				                                  (g_tdl_cntx.all_search.event_cnt * sizeof(srv_tdl_event_id_struct));
				for(i = 0; i < g_tdl_cntx.all_search.event_cnt; i++)
				{
				    if(g_tdl_cntx.all_search.event_buf[i].source_id == SRV_TDL_EVENT_SOURCE_LOCAL)
				 	{
						srv_tdl_get_cache(
							(void*)&pevent, 
							sizeof(srv_tdl_event_short_struct), 
							SRV_TDL_VCAL_EVENT,
							g_tdl_cntx.all_search.event_buf[i].event_id);
				 	}
					else
					{
						 pevent = (srv_tdl_event_struct *)OslMalloc(sizeof(srv_tdl_event_struct));	
						 srv_tdl_event_get(
							 pevent, 
							 sizeof(srv_tdl_event_struct), 
							 g_tdl_cntx.all_search.event_buf[i].source_id, 
							 g_tdl_cntx.all_search.event_buf[i].event_id);
					}

					ret = srv_tdl_search_default_check((void*)pevent, SRV_TDL_VCAL_EVENT, g_tdl_cntx.search);
					if(ret)
					{
						g_tdl_cntx.special_search.event_cnt++;
						g_tdl_cntx.special_search.event_buf[j].source_id = g_tdl_cntx.all_search.event_buf[i].source_id;
						g_tdl_cntx.special_search.event_buf[j].event_id = g_tdl_cntx.all_search.event_buf[i].event_id;
						j++;
					}
					if(g_tdl_cntx.all_search.event_buf[i].source_id != SRV_TDL_EVENT_SOURCE_LOCAL)
					{
						OslMfree(pevent);
					}
				}
			}
			g_tdl_cntx.special_search.state = MMI_CAL_EVENT_SEARCH_DONE_OK;
			g_tdl_cntx.sorted_event = g_tdl_cntx.special_search.event_buf;
			g_tdl_cntx.total = j;
		}
		else if(g_tdl_cntx.special_search.state == MMI_CAL_EVENT_SEARCH_IDLE)
		{
			job_id = srv_tdl_event_search_begin(&g_tdl_cntx.search,SRV_TDL_EVENT_SORT_START_TIME, g_clndr_event_filter_select);
			if(job_id <= 0)   // no event source
			{
				g_tdl_cntx.special_search.state = MMI_CAL_EVENT_SEARCH_DONE_OK;
				g_tdl_cntx.special_search.event_cnt = 0;
				return;
			}
			if(g_tdl_cntx.special_search.search_id == 0)
			{
				g_tdl_cntx.special_search.search_id = job_id;		 
				g_tdl_cntx.special_search.state = MMI_CAL_EVENT_SEARCH_GOING;			
			}
			else
			{
				ASSERT(0);
			}
			if(job_id < 0)
			{
				//pop up error
				g_tdl_cntx.special_search.state = MMI_CAL_EVENT_SEARCH_DONE_ERR;	
				g_tdl_cntx.special_search.event_cnt = 0;
				mmi_popup_display_simple(
					(WCHAR*)(get_string(STR_GLOBAL_ERROR)), 
					MMI_EVENT_FAILURE, 
					GRP_ID_ROOT, 
					NULL);
			}
		}
		else
		{
			ASSERT(0);
		}
#endif	
	}

    gui_buff = mmi_frm_scrn_get_active_gui_buf();
	if(g_tdl_cntx.vcal_filter == SRV_TDL_VCAL_TASK)
	{
        RegisterHighlightHandler(mmi_list_highlight_hdlr);
	}
	else
	{
		RegisterHighlightHandler(mmi_tdl_search_highlight_hdlr);
	}

    if (g_tdl_cntx.total == 0) /* Display <Empty> */
    {    
        lsk_string = 0;
    }
    
  //  g_tdl_cntx.async_item_type = MMI_TDL_ASYNC_ALL;
    
    mmi_ucs2ncpy(g_tdl_edit_cntx.title_buff, 
                 GetString(STR_GLOBAL_SEARCH), 
                 MMI_TDL_MAX_TITLE_BUF_SIZE - 1);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
if(g_tdl_cntx.vcal_filter == SRV_TDL_VCAL_TASK)
{
#ifdef __MMI_FTE_SUPPORT__ 	
	ShowCategory85Screen(
        (U8*)g_tdl_edit_cntx.title_buff,
        GetRootTitleIcon(ORGANIZER_TODOLIST_MENU),
        lsk_string,
        0,
        STR_GLOBAL_BACK,
        0,
        g_tdl_cntx.total,
        mmi_tdl_get_async_items,
        NULL,
        0,
        IMG_TODO_LIST_ICON_REMINDER,
        IMG_TODO_LIST_ICON_REMINDER,
        IMG_TODO_LIST_ICON_ALARM,
        gui_buff);
#else
	ShowCategory85Screen(
		(U8*)g_tdl_edit_cntx.title_buff,
		GetRootTitleIcon(ORGANIZER_TODOLIST_MENU),
		lsk_string,
		0,
		STR_GLOBAL_BACK,
		0,
		g_tdl_cntx.total,
		mmi_tdl_get_async_items,
		NULL,
		0,
		IMG_TODO_LIST_ICON_REMINDER,
		IMG_TODO_LIST_ICON_REMINDER,   
		0,
		gui_buff);
#endif
}
else
{
#ifdef __MMI_CALENDAR_EVENT__
#if 0
#ifdef __MMI_SNS_CALENDAR__		
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
#endif	
#endif
}
    if (g_tdl_cntx.total > 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(mmi_tdl_entry_search_list_option, KEY_EVENT_UP);
		
		if(g_tdl_cntx.vcal_filter == SRV_TDL_VCAL_TASK)
		{
    #ifdef __MMI_TOUCH_SCREEN__
            wgui_register_tap_callback(mmi_tdl_tap_list_callback);
    #endif /* __MMI_TOUCH_SCREEN__ */
            SetCenterSoftkeyFunction(mmi_tdl_entry_view_hdlr, KEY_EVENT_UP);
		}
		else
		{
	#ifdef __MMI_CALENDAR_EVENT__		
	#ifdef __MMI_TOUCH_SCREEN__
            wgui_register_tap_callback(mmi_clndr_tap_list_callback);
    #endif /* __MMI_TOUCH_SCREEN__ */
            SetCenterSoftkeyFunction(mmi_clndr_entry_view_hdlr, KEY_EVENT_UP);
	#endif
		}
    }
    else
    {
        ChangeCenterSoftkey(0, 0);
    }
    
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_entry_search_list_option
 * DESCRIPTION
 *  Entry task list option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_tdl_entry_search_list_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_entry_list_option(GRP_ID_TDL_SEARCH,
                          MITEM_TODO_LIST_TASK_OPTION_SEARCH,
                          mmi_tdl_search_option_group_proc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_search_option_group_proc
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_tdl_search_option_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    mmi_tdl_common_group_data_struct *opt_user_data;     
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    opt_user_data = (mmi_tdl_common_group_data_struct*)evt->user_data;
    switch(menu_evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        {
            OslMfree(opt_user_data);
            break;
        }  
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            mmi_tdl_search_opt_menu_entry_hdlr(menu_evt);
            break;
            
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_tdl_search_opt_menu_select_hdlr(menu_evt);
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(opt_user_data->child_id);
            mmi_frm_group_close(opt_user_data->group_id);
            break;
    }
    return MMI_RET_OK;        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_option_menu_cui_entry_hdlr
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_tdl_search_opt_menu_entry_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->parent_menu_id)
    {
#ifdef __MMI_VCALENDAR__
        case MENU_VCLNDR_FORWARD:
            cui_menu_set_default_title(
                        menu_evt->sender_id, 
                        get_string(STR_ID_VCLNDR_FORWARD),
                        get_image(ORGANIZER_TITLE_IMAGEID));
        break;
#endif 
        default:
            cui_menu_set_default_title(
                menu_evt->sender_id, 
                (WCHAR*)get_string(STR_GLOBAL_OPTIONS), 
                (UI_image_type)get_image(GetRootTitleIcon(ORGANIZER_TODOLIST_MENU)));
        break;
    }

	if(g_tdl_cntx.curr_source_id != SRV_TDL_EVENT_SOURCE_LOCAL)
	{
	            cui_menu_set_item_hidden(
	            menu_evt->sender_id, 
	            MITEM_TODO_LIST_DELETE, 
	            MMI_TRUE); 
	}
	else
	{
	            cui_menu_set_item_hidden(
	            menu_evt->sender_id, 
	            MITEM_TODO_LIST_DELETE, 
	            MMI_FALSE); 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_search_opt_menu_select_hdlr
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_tdl_search_opt_menu_select_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_tdl_common_group_data_struct *opt_user_data = menu_evt->user_data;     
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	if (g_tdl_cntx.vcal_filter == SRV_TDL_VCAL_EVENT)
	{
#ifdef __MMI_CALENDAR_EVENT__		
		srv_tdl_get(
			(void*)&g_tdl_cntx.curr_event, 
			sizeof(srv_tdl_event_struct), 
			g_tdl_cntx.curr_source_id,
			g_tdl_cntx.curr_event_id);	
#endif
	}
	else
	{
		g_tdl_cntx.curr_store_idx = mmi_tdl_get_curr_store_idx();	 
		srv_tdl_get(
			(void*)&g_tdl_cntx.curr_task, 
			sizeof(srv_tdl_task_struct), 
			SRV_TDL_VCAL_TASK,
			g_tdl_cntx.curr_store_idx);
	}

    switch (menu_evt->highlighted_menu_id)
    {
        case MITEM_TODO_LIST_VIEW:
        {
            g_tdl_cntx.curr_option = TODO_LIST_TASK_OPTION_VIEW;
			if(g_tdl_cntx.vcal_filter == SRV_TDL_VCAL_TASK)
			{
                 mmi_tdl_view_with_sg(
                        opt_user_data->parent_id, 
                        g_tdl_cntx.vcal_filter, 
                        0,
                        g_tdl_cntx.curr_store_idx);  
			}
			else
			{
		#ifdef __MMI_CALENDAR_EVENT__	
	             mmi_tdl_view_with_sg(
						opt_user_data->parent_id, 
		                 g_tdl_cntx.vcal_filter, 
		                 g_tdl_cntx.curr_source_id, 
		                 g_tdl_cntx.curr_event_id);   
		#endif
			}
            break;
        }   
        case MITEM_TODO_LIST_EDIT:
        {
            mmi_tdl_search_group_data_struct *tdl_search_group_cntx;
        
            tdl_search_group_cntx = mmi_frm_group_get_user_data(GRP_ID_TDL_SEARCH);
            g_tdl_cntx.curr_option = TODO_LIST_TASK_OPTION_EDIT;
            
            if (SRV_TDL_VCAL_TASK == g_tdl_cntx.vcal_filter)
            {
                tdl_search_group_cntx->cui_tdl_save_gid = cui_tdl_save_create(GRP_ID_TDL_SEARCH);
                cui_tdl_save_set_operation_type(tdl_search_group_cntx->cui_tdl_save_gid, MMI_TDL_OP_TYPE_EDIT);
                cui_tdl_save_set_title(tdl_search_group_cntx->cui_tdl_save_gid, STR_GLOBAL_EDIT);
                cui_tdl_save_set_task(tdl_search_group_cntx->cui_tdl_save_gid, &g_tdl_cntx.curr_task);                
                cui_tdl_save_run(tdl_search_group_cntx->cui_tdl_save_gid);
            }
            else
            {
            #ifdef __MMI_BIRTHDAY_REMINDER__
                if (g_tdl_cntx.curr_event.category == MMI_TDL_CATEGORY_BIRTHDAY)
                {
                    mmi_tdl_br_entry_bday_edit_from_org(GRP_ID_TDL_SEARCH);
                }
                else
            #endif
                {
                    tdl_search_group_cntx->cui_cal_save_gid = cui_cal_save_create(GRP_ID_TDL_SEARCH);
                    cui_cal_save_set_event(tdl_search_group_cntx->cui_cal_save_gid, &g_tdl_cntx.curr_event);
                    cui_cal_save_set_operation_type(tdl_search_group_cntx->cui_cal_save_gid, MMI_TDL_OP_TYPE_EDIT);
                    cui_cal_save_set_title(tdl_search_group_cntx->cui_cal_save_gid, STR_GLOBAL_EDIT);
                    cui_cal_save_run(tdl_search_group_cntx->cui_cal_save_gid);
                }
            }
            break;
        }       
        case MITEM_TODO_LIST_DELETE:
        {
            g_tdl_cntx.curr_option = TODO_LIST_TASK_OPTION_DELETE;
            mmi_tdl_entry_delete_confirm(opt_user_data->parent_id);        
            break;
        }   
        case MITEM_TODO_LIST_DELETE_ALL:
        {
            g_tdl_cntx.curr_option = TODO_LIST_TASK_OPTION_DELETE_ALL;
            mmi_tdl_delete_all_searched_confirm(opt_user_data->parent_id);
            break;
        }   
    #ifdef __MMI_VCALENDAR__
    #ifndef __MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__
        case MENU_VCLNDR_SEND_BY_SMS:
        {
            cui_vcal_send_param_struct para;
            mmi_id sg_id;
            para.send_type = MMI_VCAL_SEND_BY_SMS;
			if(g_tdl_cntx.vcal_filter == SRV_TDL_VCAL_TASK)
			{
                para.vcal_type = SRV_VCAL_VTODO;
                para.buff = &g_tdl_cntx.curr_task;
			}
			else
			{
				para.vcal_type = SRV_VCAL_VEVENT;
                para.buff = &g_tdl_cntx.curr_event;
			}
            sg_id = cui_vcal_send_create(opt_user_data->parent_id);
            cui_vcal_send_set_para(sg_id, para);
            cui_vcal_send_run(sg_id);
            break;
        }
    #endif
    #ifdef __MMI_MMS__
        case MENU_VCLNDR_SEND_BY_MMS:
        {
            cui_vcal_send_param_struct para;
            mmi_id sg_id;
            para.send_type = MMI_VCAL_SEND_BY_MMS;
			if(g_tdl_cntx.vcal_filter == SRV_TDL_VCAL_TASK)
			{
                para.vcal_type = SRV_VCAL_VTODO;
                para.buff = &g_tdl_cntx.curr_task;
			}
			else
			{
				para.vcal_type = SRV_VCAL_VEVENT;
                para.buff = &g_tdl_cntx.curr_event;
			}
            sg_id = cui_vcal_send_create(opt_user_data->parent_id);
            cui_vcal_send_set_para(sg_id, para);
            cui_vcal_send_run(sg_id);
            break;
        }
    #endif
    #ifdef __MMI_EMAIL__
        case MENU_VCLNDR_SEND_BY_EMAIL:
        {
            cui_vcal_send_param_struct para;
            mmi_id sg_id;
            para.send_type = MMI_VCAL_SEND_BY_EMAIL;
			if(g_tdl_cntx.vcal_filter == SRV_TDL_VCAL_TASK)
			{
                para.vcal_type = SRV_VCAL_VTODO;
                para.buff = &g_tdl_cntx.curr_task;
			}
			else
			{
				para.vcal_type = SRV_VCAL_VEVENT;
                para.buff = &g_tdl_cntx.curr_event;
			}
            sg_id = cui_vcal_send_create(opt_user_data->parent_id);
            cui_vcal_send_set_para(sg_id, para);
            cui_vcal_send_run(sg_id);
            break;
        }
    #endif
    #ifdef __MMI_OPP_SUPPORT__
        case MENU_VCLNDR_SEND_BY_BT:
        {
            cui_vcal_send_param_struct para;
            mmi_id sg_id;
            para.send_type = MMI_VCAL_SEND_BY_OPP;
			if(g_tdl_cntx.vcal_filter == SRV_TDL_VCAL_TASK)
			{
                para.vcal_type = SRV_VCAL_VTODO;
                para.buff = &g_tdl_cntx.curr_task;
			}
			else
			{
				para.vcal_type = SRV_VCAL_VEVENT;
                para.buff = &g_tdl_cntx.curr_event;
			}
            sg_id = cui_vcal_send_create(opt_user_data->parent_id);
            cui_vcal_send_set_para(sg_id, para);
            cui_vcal_send_run(sg_id);
            break;
        }
    #endif        
    #ifdef __MMI_FILE_MANAGER__
        case MENU_VCLNDR_SEND_BY_FILEMGR:
        {
            mmi_id sg_id;
            cui_vcal_save_to_file_param_struct param;

            sg_id = cui_vcal_save_to_file_create(opt_user_data->parent_id);
            if (SRV_TDL_VCAL_EVENT == g_tdl_cntx.vcal_filter)
            {
                param.para_type = MMI_VCAL_TYPE_BUFF;
                param.u.obj.vcal_type = SRV_VCAL_VEVENT;
                param.u.obj.buff = &g_tdl_cntx.curr_event;
                cui_vcal_save_to_file_set_para(sg_id, param);            
                cui_vcal_save_to_file_run(sg_id);
            }
            else
            {
                param.para_type = MMI_VCAL_TYPE_BUFF;
                param.u.obj.vcal_type = SRV_VCAL_VTODO;
                param.u.obj.buff = &g_tdl_cntx.curr_task;
                cui_vcal_save_to_file_set_para(sg_id, param);            
                cui_vcal_save_to_file_run(sg_id);
            }
            break;
        }
    #endif
    #endif /* __MMI_VCALENDAR__ */
        default:
            break;
    }
}
#endif /* __MMI_TODO_SEARCH__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_is_pending_reminder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_tdl_is_pending_reminder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() == SCR_TDL_REMINDER)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

#if defined __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ || defined __MMI_SYNCML_SYNC_TASK_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_vcal_sync_err_mapping
 * DESCRIPTION
 *  Mapping error code from vcalendar to syncML
 * PARAMETERS
 *  vCalenar_err        [IN]    error code of vCalendar
 * RETURNS
 *  U16  error code of syncML
 *****************************************************************************/
static U16 mmi_tdl_vcal_sync_err_mapping(U16 vCalenar_err)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(vCalenar_err)
    {
        case SRV_VCAL_RESULT_SUCCESS:
            return MMI_TDL_SYNCML_ERR_NO_ERROR;
        case SRV_VCAL_RESULT_UNSUPPORT_FORMAT:
            return MMI_TDL_SYNCML_ERR_UNSUPPORT_FORMAT;
        default:
            return MMI_TDL_SYNCML_ERR_UNKNOWN;
    }

}
#endif /* defined __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ || defined __MMI_SYNCML_SYNC_TASK_SUPPORT__ */


#define GLOBAL_FUNCTIION
/*****************************************************************************
 * Global Function
 *****************************************************************************/
#if 0
#ifdef __MMI_OP11_TODOLIST_DIARY_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_PROF_BEEP_WHEN_BGPLAYING__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_PROF_BEEP_WHEN_BGPLAYING__
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
    #ifdef __MMI_BIRTHDAY_REMINDER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_BIRTHDAY_REMINDER__ */    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_TODOLIST_DIARY_SUPPORT__ */
#endif

#ifdef __SYNCML_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_db_is_sync_now
 * DESCRIPTION
 *  test whether the sync is going
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
U8 mmi_tdl_db_is_sync_now(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    if (mmi_syncml_is_calendar_sync_now() && g_tdl_cntx.vcal_filter == SRV_TDL_VCAL_EVENT)
    {
        return MMI_TRUE;
    }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    if (mmi_syncml_is_task_sync_now() && g_tdl_cntx.vcal_filter == SRV_TDL_VCAL_TASK)
    {
        return MMI_TRUE;
    }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

    return MMI_FALSE;
}


#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_sync_vevent
 * DESCRIPTION
 *  Synchronize the calendar data
 * PARAMETERS
 *  action        [IN]            sync type
 *  path          [IN/OUT]     file path of sync data
 *  index         [IN/OUT]     index of todolist
 * RETURNS
 *  U16  error code
 *****************************************************************************/
U16 mmi_tdl_sync_vevent(U8 action, CHAR *path, U16 *index, U8 sync_chset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result = MMI_TDL_SYNCML_ERR_NO_ERROR;
    U16 t;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TDL_TRACE1(MMI_TDL_SYNC_VTODO, *index);
    
    /* transfer error code */
    switch(action)
    {           
        case MMI_TDL_SYNCML_ADD:
        {
            srv_vcal_parse_struct *handle;
            void *pobject;
            srv_vcal_type_enum vcal_type;
            U8 flag_finish;
            
            handle = srv_vcal_parse_begin((U16*)path, (mmi_chset_enum)sync_chset);
            result = srv_vcal_parse(handle, &pobject, (srv_vcal_type_enum*)&vcal_type, (U8*)&flag_finish);
            if (vcal_type != SRV_VCAL_VEVENT || result != SRV_VCAL_RESULT_SUCCESS)
            {
                result = MMI_TDL_SYNCML_ERR_UNSUPPORT_FORMAT;
            }
            else
            {
                memcpy(&g_tdl_cntx.curr_event, pobject, sizeof(srv_tdl_event_struct));
            }
            srv_vcal_parse_free_object(handle, pobject);
            srv_vcal_parse_end(handle);
            if (result != SRV_VCAL_RESULT_SUCCESS)
            {
                result = mmi_tdl_vcal_sync_err_mapping(result);
                break;
            }
            
            /* Subject should not be empty. If empty, will return. */
            if (mmi_ucs2strlen((CHAR*)g_tdl_cntx.curr_event.subject) == 0)
            {
                result = MMI_TDL_SYNCML_ERR_EMPTY_NAME;
                break;
            }
            
            if (g_tdl_cntx.curr_event.alarm.first_launch.nYear == 0)
            {
                g_tdl_cntx.curr_event.alarm.type = MMI_TDL_ALARM_OFF;
            }
            else
            {
                g_tdl_cntx.curr_event.alarm.type = MMI_TDL_ALARM_CUSTOM;
                mmi_tdl_save_adjust_alarm_type(&g_tdl_cntx.curr_event.alarm, &g_tdl_cntx.curr_event.start_time); 
            }
            
        	result = mmi_tdl_save_adjust_field(
                    (void*)&g_tdl_cntx.curr_event, 
                    sizeof(srv_tdl_event_struct), 
                    SRV_TDL_VCAL_EVENT);
			if(result != MMI_TDL_SUCCESS)
			{
			    result = mmi_tdl_vcal_sync_err_mapping(result);
                break;
			}

            result = srv_tdl_add(
                            &g_tdl_cntx.curr_event, 
                            SRV_TDL_VCAL_EVENT, 
                            &t);
                            
            if (result == SRV_TDL_RESULT_OK)
            {
                *index = t; /* Wen, 2009/10/29 */
                result = MMI_TDL_SYNCML_ERR_NO_ERROR;
            #ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
                mmi_syncml_calendar_data_changed_notification(SYNCML_RECORD_ADD, *index);
            #endif
            }
            else if (result == SRV_TDL_RESULT_ADD_NOT_ENOUGH_MEMORY)
            {
                result = MMI_TDL_SYNCML_ERR_MEMORY_FULL;
            }
            else
            {
                result = MMI_TDL_SYNCML_ERR_UNKNOWN;
            }
            break;
        }
		case MMI_TDL_SYNCML_MODIFY:
		{
            srv_vcal_parse_struct *handle;
            void *pobject;
            srv_vcal_type_enum vcal_type;
            U8 flag_finish;
            
            handle = srv_vcal_parse_begin((U16*)path, (mmi_chset_enum)sync_chset);
            result = srv_vcal_parse(handle, &pobject, (srv_vcal_type_enum*)&vcal_type, (U8*)&flag_finish);
            if (vcal_type != SRV_VCAL_VEVENT || result != SRV_VCAL_RESULT_SUCCESS)
            {
                result = MMI_TDL_SYNCML_ERR_UNSUPPORT_FORMAT;
            }
            else
            {
                memcpy(&g_tdl_cntx.curr_event, pobject, sizeof(srv_tdl_event_struct));
            }
            srv_vcal_parse_free_object(handle, pobject);
            srv_vcal_parse_end(handle);
            if (result != SRV_VCAL_RESULT_SUCCESS)
            {
                result = mmi_tdl_vcal_sync_err_mapping(result);
                break;
            }
            if (*index > NUM_OF_CAL)
            {
                result = MMI_TDL_SYNCML_ERR_INVALID_INDEX;
                break;
            }

            /* Subject should not be empty. If empty, will return. */
            if (mmi_ucs2strlen((CHAR*)g_tdl_cntx.curr_event.subject) == 0)
            {
                result = MMI_TDL_SYNCML_ERR_EMPTY_NAME;
                break;
            }
                        
            if (g_tdl_cntx.curr_event.alarm.first_launch.nYear == 0)
            {
                g_tdl_cntx.curr_event.alarm.type = MMI_TDL_ALARM_OFF;
            }
            else
            {
                g_tdl_cntx.curr_event.alarm.type = MMI_TDL_ALARM_CUSTOM;
                mmi_tdl_save_adjust_alarm_type(&g_tdl_cntx.curr_event.alarm, &g_tdl_cntx.curr_event.start_time); 
            }
            
        	result = mmi_tdl_save_adjust_field(
                    (void*)&g_tdl_cntx.curr_event, 
                    sizeof(srv_tdl_event_struct), 
                    SRV_TDL_VCAL_EVENT);
			if(result != MMI_TDL_SUCCESS)
			{
			    result = mmi_tdl_vcal_sync_err_mapping(result);
                break;
			}

            result = srv_tdl_update(
                            (void*)&g_tdl_cntx.curr_event, 
                            SRV_TDL_VCAL_EVENT,
                            *index);

            if (result == SRV_TDL_RESULT_OK)
            {
                result = MMI_TDL_SYNCML_ERR_NO_ERROR;
            #ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
                mmi_syncml_calendar_data_changed_notification(SYNCML_RECORD_MODIFY, *index);
            #endif
            }
            else
            {
                result = MMI_TDL_SYNCML_ERR_NOT_FOUND;
            }
            break;
        }
        case MMI_TDL_SYNCML_DELETE:
        {
            if (*index >= NUM_OF_CAL)
            {
                result = MMI_TDL_SYNCML_ERR_INVALID_INDEX;
                break;
            }
            result = mmi_tdl_delete_record(*index, SRV_TDL_VCAL_EVENT);
            
            if (result)
            {
                result = MMI_TDL_SYNCML_ERR_NO_ERROR;
            }
            else
            {
                result = MMI_TDL_SYNCML_ERR_NOT_FOUND;
            }
			break;
        } 
        case MMI_TDL_SYNCML_GET:
        {
            srv_vcal_build_struct *handle;
            
            if (*index >= NUM_OF_CAL)
            {
                result = MMI_TDL_SYNCML_ERR_INVALID_INDEX;
                break;
            }
            srv_tdl_get(
                (void*)&g_tdl_cntx.curr_event, 
                sizeof(srv_tdl_event_struct), 
                SRV_TDL_VCAL_EVENT,
                *index);
            handle = srv_vcal_build_begin((U16*)path, SRV_VCAL_VER_VCAL_1_0);
            result = srv_vcal_build_add(handle, &g_tdl_cntx.curr_event, SRV_VCAL_VEVENT);
            srv_vcal_build_end(handle);
            result = mmi_tdl_vcal_sync_err_mapping(result);
            break;
        }
        default:
            result =  MMI_TDL_SYNCML_ERR_INVALID_OPERATION;
            break;
			
    }
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_get_total_cal_index
 * DESCRIPTION
 *  Get store index of all todolist
 * PARAMETERS
 *  list        [IN/OUT]            index list of todolist
 * RETURNS
 *  U16  total amount of todolist
 *****************************************************************************/
U16 mmi_tdl_get_total_cal_index(U16 *list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 count = 0;   
    srv_tdl_event_task_struct *temp_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_list = OslMalloc(sizeof(srv_tdl_event_task_struct) * NUM_OF_CAL);
    
    srv_tdl_get_all_index(temp_list, NUM_OF_CAL, SRV_TDL_VCAL_EVENT, &count);

	if (list == NULL)
	{
		goto EXIT;
	}
	
    for (i = 0; i < count; i++)
    {
        list[i] = temp_list[i].index;
    }

EXIT:
    OslMfree(temp_list);
    return count;
}
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_sync_vtodo
 * DESCRIPTION
 *  Synchronize the task data
 * PARAMETERS
 *  action        [IN]            sync type
 *  path          [IN/OUT]     file path of sync data
 *  index         [IN/OUT]     index of todolist
 * RETURNS
 *  U16  error code
 *****************************************************************************/
U16 mmi_tdl_sync_vtodo(U8 action, CHAR *path, U16 *index, U8 sync_chset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result = MMI_TDL_SYNCML_ERR_NO_ERROR;
	S32 perse_result = SRV_VCAL_RESULT_SUCCESS;
    srv_tdl_task_struct task;
    U16 t;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TDL_TRACE1(MMI_TDL_SYNC_VTODO, *index);
    
    /* transfer error code */
    switch(action)
    {           
        case MMI_TDL_SYNCML_ADD:
        {
            srv_vcal_parse_struct *handle;
            void *pobject;
            srv_vcal_type_enum vcal_type;
            U8 flag_finish;
            
            handle = srv_vcal_parse_begin((U16*)path, (mmi_chset_enum)sync_chset);
            perse_result = srv_vcal_parse(handle, &pobject, (srv_vcal_type_enum*)&vcal_type, (U8*)&flag_finish);
            if ((vcal_type != SRV_VCAL_VTODO) || (perse_result != SRV_VCAL_RESULT_SUCCESS))
            {
                result = MMI_TDL_SYNCML_ERR_UNSUPPORT_FORMAT;
            }
            else
            {
                memcpy(&g_tdl_cntx.curr_task, pobject, sizeof(srv_tdl_task_struct));
            }
            srv_vcal_parse_free_object(handle, pobject);
            srv_vcal_parse_end(handle);
            if (result != SRV_VCAL_RESULT_SUCCESS)
            {
                result = mmi_tdl_vcal_sync_err_mapping(result);
                break;
            }

            /* Subject should not be empty. If empty, will return. */
            if (mmi_ucs2strlen((CHAR*)g_tdl_cntx.curr_task.subject) == 0)
            {
                result = MMI_TDL_SYNCML_ERR_EMPTY_NAME;
                break;
            }

            if (g_tdl_cntx.curr_task.alarm.first_launch.nYear == 0)
            {
                g_tdl_cntx.curr_task.alarm.type = MMI_TDL_ALARM_OFF;
            }
            else
            {
                g_tdl_cntx.curr_task.alarm.type = MMI_TDL_ALARM_CUSTOM;
                mmi_tdl_save_adjust_alarm_type(&g_tdl_cntx.curr_task.alarm, &g_tdl_cntx.curr_task.due_time); 
            }

        	result = mmi_tdl_save_adjust_field(
                    (void*)&g_tdl_cntx.curr_task, 
                    sizeof(srv_tdl_task_struct), 
                    SRV_TDL_VCAL_TASK);
			if(result != MMI_TDL_SUCCESS)
			{
			    result = mmi_tdl_vcal_sync_err_mapping(result);
                break;
			}

            result = srv_tdl_add(
                            &g_tdl_cntx.curr_task, 
                            SRV_TDL_VCAL_TASK, 
                            &t);
                            
            if (result == SRV_TDL_RESULT_OK)
            {
                *index = t;
                result = MMI_TDL_SYNCML_ERR_NO_ERROR;
            #ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
                mmi_syncml_task_data_changed_notification(SYNCML_RECORD_ADD, *index);
            #endif
            }
            else if (result == SRV_TDL_RESULT_ADD_NOT_ENOUGH_MEMORY)
            {
                result = MMI_TDL_SYNCML_ERR_MEMORY_FULL;
            }
            else
            {
                result = MMI_TDL_SYNCML_ERR_UNKNOWN;
            }
            break;
        }
		case MMI_TDL_SYNCML_MODIFY:
		{
            srv_vcal_parse_struct *handle;
            void *pobject;
            srv_vcal_type_enum vcal_type;
            U8 flag_finish;
            
            handle = srv_vcal_parse_begin((U16*)path, (mmi_chset_enum)sync_chset);
            perse_result = srv_vcal_parse(handle, &pobject, (srv_vcal_type_enum*)&vcal_type, (U8*)&flag_finish);
            if ((vcal_type != SRV_VCAL_VTODO) || (perse_result != SRV_VCAL_RESULT_SUCCESS))
            {
                result = MMI_TDL_SYNCML_ERR_UNSUPPORT_FORMAT;
            }
            else
            {
                memcpy(&g_tdl_cntx.curr_task, pobject, sizeof(srv_tdl_task_struct));
            }
            srv_vcal_parse_free_object(handle, pobject);  
            srv_vcal_parse_end(handle);
            if (vcal_type != SRV_VCAL_VTODO)
            {
                result = MMI_TDL_SYNCML_ERR_UNSUPPORT_FORMAT;
                break;
            }
            
            if (result != SRV_VCAL_RESULT_SUCCESS)
            {
                result = mmi_tdl_vcal_sync_err_mapping(result);
                break;
            }
            
            if (*index > NUM_OF_TASK)
            {
                result = MMI_TDL_SYNCML_ERR_INVALID_INDEX;
                break;
            }

            /* Subject should not be empty. If empty, will return. */
            if (mmi_ucs2strlen((CHAR*)g_tdl_cntx.curr_task.subject) == 0)
            {
                result = MMI_TDL_SYNCML_ERR_EMPTY_NAME;
                break;
            }

            if (g_tdl_cntx.curr_task.alarm.first_launch.nYear == 0)
            {
                g_tdl_cntx.curr_task.alarm.type = MMI_TDL_ALARM_OFF;
            }
            else
            {
                g_tdl_cntx.curr_task.alarm.type = MMI_TDL_ALARM_CUSTOM;
                mmi_tdl_save_adjust_alarm_type(&g_tdl_cntx.curr_task.alarm, &g_tdl_cntx.curr_task.due_time); 
            }

        	result = mmi_tdl_save_adjust_field(
                                (void*)&g_tdl_cntx.curr_task, 
        	                    sizeof(srv_tdl_task_struct), 
        	                    SRV_TDL_VCAL_TASK);
			if(result != MMI_TDL_SUCCESS)
			{
			    result = mmi_tdl_vcal_sync_err_mapping(result);
                break;
			}

            result = srv_tdl_update(
                            (void*)&g_tdl_cntx.curr_task, 
                            SRV_TDL_VCAL_TASK,
                            *index);

            if (result == SRV_TDL_RESULT_OK)
            {
                result = MMI_TDL_SYNCML_ERR_NO_ERROR;
            #ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
                mmi_syncml_task_data_changed_notification(SYNCML_RECORD_MODIFY, *index);
            #endif
            }
            else
            {
                result = MMI_TDL_SYNCML_ERR_NOT_FOUND;
            }
            break;
        }
        case MMI_TDL_SYNCML_DELETE:
        {
            if (*index >= NUM_OF_TASK)
            {
                result = MMI_TDL_SYNCML_ERR_INVALID_INDEX;
                break;
            }
            result = mmi_tdl_delete_record(*index, SRV_TDL_VCAL_TASK);
            
            if (result)
            {
                result = MMI_TDL_SYNCML_ERR_NO_ERROR;
            }
            else
            {
                result = MMI_TDL_SYNCML_ERR_NOT_FOUND;
            }
            break;
        }
        case MMI_TDL_SYNCML_GET:
        {
            srv_vcal_build_struct *handle;
        
            if (*index >= NUM_OF_TASK)
            {
                result = MMI_TDL_SYNCML_ERR_INVALID_INDEX;
                break;
            }
            srv_tdl_get(
                (void*)&g_tdl_cntx.curr_task, 
                sizeof(srv_tdl_task_struct), 
                SRV_TDL_VCAL_TASK,
                *index);
            handle = srv_vcal_build_begin((U16*)path, SRV_VCAL_VER_VCAL_1_0);
            result = srv_vcal_build_add(handle, &g_tdl_cntx.curr_task, SRV_VCAL_VTODO);
            srv_vcal_build_end(handle);
            result = mmi_tdl_vcal_sync_err_mapping(result);
            break;
        }
        default:
            result =  MMI_TDL_SYNCML_ERR_INVALID_OPERATION;
            break;
			
    }
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_get_total_cal_index
 * DESCRIPTION
 *  Get store index of all todolist
 * PARAMETERS
 *  list        [IN/OUT]            index list of todolist
 * RETURNS
 *  U16  total amount of todolist
 *****************************************************************************/
U16 mmi_tdl_get_total_task_index(U16 *list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i; 
    U16 count = 0;   
    srv_tdl_event_task_struct *temp_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_list = OslMalloc(sizeof(srv_tdl_event_task_struct) * NUM_OF_TASK);
    
    srv_tdl_get_all_index(temp_list, NUM_OF_TASK, SRV_TDL_VCAL_TASK, &count);

	if (list == NULL)/* Wen, 2009/10/29 */
	{
		goto EXIT;
	}
    for (i = 0; i < count; i++)
    {
        list[i] = temp_list[i].index;
    }

EXIT:
    OslMfree(temp_list);
    return count;
}
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */
#endif /* __SYNCML_SUPPORT__ */

#if 0
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_FTE_SUPPORT__    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */
#endif

#if 0
#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */
#endif
#endif /* __MMI_TODOLIST__ */

#if 0
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_TODOLIST__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_TODOLIST__ */    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_TODOLIST__	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_TODOLIST__ */	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_TODOLIST__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_TODOLIST__ */		
/* under construction !*/
#endif /*  __MMI_OP11_HOMESCREEN__ */
#endif

