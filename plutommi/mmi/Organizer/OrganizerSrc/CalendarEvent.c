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
 * Calendar.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Calendar application.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      CalendarEvent.c
   Author:        Xuewei Sun
   Date Created:  May-25-2011
**********************************************************************************/
/*********************************************************************************
 * Include
 *********************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_CALENDAR_EVENT__

#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "custom_mmi_default_value.h"
#include "gui_typedef.h"
#include "app_datetime.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "wgui_categories_calendar.h"
#include "PhoneBookGprot.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "gui_theme_struct.h"
#include "gui_calendar.h"
#include "Unicodexdcl.h"
#include "mmi_frm_nvram_gprot.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"
#include "kal_trace.h"
#include "ToDoListGprot.h"
#include "wgui_datetime.h"
#include "mmi_rp_app_organizer_def.h"
#include "wgui_categories_list.h"
#include "stdio.h"
#include "AlarmFrameworkProt.h"
#include "nvram_common_defs.h"
#include "NotificationGprot.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "AlarmDef.h"
#include "wgui_categories.h"
#include "mmi_frm_history_gprot.h"
#include "bppxhtmlgprot.h"
#include "Menucuigprot.h"
#include "DateTimeType.h"
#include "CalendarProt.h"
#include "CalendarGprot.h"
#include "CommonScreens.h"
#include "kal_general_types.h"
#include "IndianCalendarDef.h"
#include "PixcomFontEngine.h"
#include "mmi_rp_app_uiframework_def.h"
#include "kal_public_api.h"
#include "mmi_common_app_trc.h"
#ifdef __MMI_HIJRI_CALENDAR__
#include "mmi_rp_app_hijri_calendar_def.h"
#include "HijriCalendarProt.h"
#include "HijriCalendarResdef.h"
#endif

#ifdef __MMI_INDICAL__
#include "mmi_rp_app_indical_def.h"
#include "IndianCalendarProt.h"
#endif

#include "gui_switch.h"
#include "lcd_sw_rnd.h"
#include "gdi_include.h"
#include "lcd_sw_inc.h"
#include "Gui_Setting.h"
#include "wgui.h"
#include "BppXhtmlGprot.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "fs_func.h"
#include "wgui_inline_edit.h"
#include "wgui_categories_text_viewer.h"
#ifdef __SYNCML_SUPPORT__
#include "Mmi_rp_srv_syncml_def.h" 
#endif
#include "mmi_rp_app_todolist_def.h"
#include "mmi_rp_app_calendar_def.h"
#include "TodolistProt.h"
#include "TodolistSrvGprot.h"
#if 0
#ifdef __MMI_HIJRI_CALENDAR__
/* under construction !*/
/* under construction !*/
#endif
#endif
#if 0
#ifdef __MMI_INDICAL__
/* under construction !*/
#endif
#endif

#ifdef __MMI_BIRTHDAY_REMINDER__
#include "BirthdayProt.h"
#endif 
#include "ToDoListDB.h"
#include "SyncMLGprot.h"
#include "InlineCuiGprot.h"
#include "vCalendar.h"
#ifdef __MMI_VCALENDAR__
#include "Vcalsrvgprot.h"
#include "mmi_rp_srv_vcalendar_def.h"
#endif
#include "gui_effect_oem.h"
#include "mdi_audio.h"
#include "SecSetCuiGprot.h"
#include "CalendarEventGprot.h"


/* 
 * Define
 */

#define MMI_CAL_TRACE0(sub_grp) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp)

#define MMI_CAL_TRACE1(sub_grp, arg) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg)
		
#define MMI_CAL_TRACE2(sub_grp, arg1, arg2) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2)

#define MMI_CAL_TRACE3(sub_grp, arg1, arg2, arg3) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2, arg3)

#define MMI_CAL_TRACE4(sub_grp, arg1, arg2, arg3, arg4) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2, arg3, arg4)

#define MMI_CAL_TRACE5(sub_grp, arg1, arg2, arg3, arg4, arg5) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2, arg3, arg4, arg5)

kal_bool g_is_entry_search_op = KAL_FALSE;


static const cui_inline_item_caption_struct cui_delete_spec_time_caption[2] =
{
    STR_TODO_START_TIME,
    STR_TODO_END_TIME
};

static const cui_inline_set_item_struct cui_delete_spec_time[6] = 
{
    {CUI_INLINE_ITEM_ID_BASE + 0, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_TODO_LIST_DATE, &cui_delete_spec_time_caption[0]},
    {CUI_INLINE_ITEM_ID_BASE + 1, CUI_INLINE_ITEM_TYPE_DATE | CUI_INLINE_ITEM_LEFT_JUSTIFY | CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT, 0, NULL},
    {CUI_INLINE_ITEM_ID_BASE + 2, CUI_INLINE_ITEM_TYPE_TIME | CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT, 0, NULL},
    {CUI_INLINE_ITEM_ID_BASE + 3, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_TODO_LIST_TIME, &cui_delete_spec_time_caption[1]},
    {CUI_INLINE_ITEM_ID_BASE + 4, CUI_INLINE_ITEM_TYPE_DATE | CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT, 0, NULL},
    {CUI_INLINE_ITEM_ID_BASE + 5, CUI_INLINE_ITEM_TYPE_TIME | CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT, 0, NULL}    
};

static mmi_id mmi_clndr_del_spec_child_gid;
static mmi_clndr_confirm_user_data_struct clndr_confirm_user_data;
#ifdef __MMI_SNS_CALENDAR__ 
static U16 g_clndr_event_filter[SRV_TDL_EVENT_SOURCE_TOTAL+1];
#endif
//static MMI_BOOL g_clndr_is_filter_changed;
srv_tdl_event_source_enum g_clndr_event_filter_select;
/********************************************************************************* 
 * Local Function
 *********************************************************************************/
static void mmi_clndr_next_day_list(void);
static void mmi_clndr_previous_day_list(void);
static void mmi_clndr_exit_daily_list(void); 
static void mmi_clndr_delete_spec_time_confirm(mmi_id parent_id);
static mmi_ret mmi_cal_list_option_group_proc(mmi_event_struct* evt);

static void mmi_cal_list_option_menu_entry_hdlr(cui_menu_event_struct *menu_evt);
#ifdef __MMI_TODO_SEARCH__
static void mmi_cal_list_option_menu_highlight_hdlr(cui_menu_event_struct *menu_evt);
#endif
static void mmi_cal_list_option_menu_select_hdlr(cui_menu_event_struct *menu_evt);

static mmi_ret mmi_clndr_list_leave_proc(mmi_event_struct *parm);
static mmi_ret mmi_clndr_delete_group_proc(mmi_event_struct *evt);
static U8 mmi_clndr_get_spec_time(void);
static void mmi_tdl_delete_goback(mmi_id parent_id);

static void mmi_clndr_entry_list_option(void);
void mmi_clndr_entry_daily_list(void);
void mmi_clndr_list_highlight_hdlr(S32 index);

#ifdef __MMI_SNS_CALENDAR__ 
static void mmi_clndr_event_filter_custom_csk_hdlr(void);
static void mmi_clndr_event_filter_custom_csk_hdlr(void);
void mmi_clndr_entry_filter_hdlr(void);
#endif

extern void mmi_clndr_reset_event_search_state_exclude_all_search(void);
extern void mmi_clndr_reset_event_search_state(void);
extern void mmi_tdl_set_reminder(
                    const srv_tdl_vcal_enum vcal_type, 
                    const void *data,
                    const U16 index);
extern void mmi_tdl_compute_pre_reminder_time(
                        U8 alarm_type,
                        MYTIME *alarm_time,
                        MYTIME *start_time,
                        MYTIME *pre_reminder);
extern srv_reminder_repeat_enum mmi_tdl_repeat_conv2reminder(mmi_tdl_repeat_rule_enum repeat);

#define SNS_ADD
void mmi_clndr_get_event_detatils(
			   S32 start_index, 
			   gui_iconlist_menu_item *menu_data, 
			   S32 num_item,
			   MYTIME* date);

static MMI_BOOL mmi_clndr_get_curr_store_idx(srv_tdl_event_source_enum *source_id, S32 *event_id);

/*********************************************************************************
 * Global Variable
 *********************************************************************************/

/********************************************************************************* 
 * Global Function
 *********************************************************************************/
  

/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_entry_view_hdlr
 * DESCRIPTION
 *  Execute View option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_entry_view_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id parent_id;
	srv_tdl_event_source_enum source_id;
	S32 event_id;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	parent_id = mmi_tdl_sg_mgr_get_current_sg_id();
	mmi_clndr_get_curr_store_idx(&source_id, &event_id);
	mmi_tdl_view_with_sg(parent_id, SRV_TDL_VCAL_EVENT, source_id, event_id);    
}


#ifdef __MMI_TOUCH_SCREEN__
 /*****************************************************************************
  * FUNCTION
  *  mmi_clndr_tap_list_callback
  * DESCRIPTION
  *  tap on vcalendar item. view it
  * PARAMETERS
  *  mmi_tap_type_enum	 [IN] tap type.
  *  S32				 [IN] item index.
  * RETURNS
  *  void
  *****************************************************************************/
 void mmi_clndr_tap_list_callback(mmi_tap_type_enum tap_type, S32 index)
 {
	 /*----------------------------------------------------------------*/
	 /* Local Variables 											   */
	 /*----------------------------------------------------------------*/
 
	 /*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/
	 if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM)
	 {
		 // only change the highlight
		 return;
	 }
	 
	 g_tdl_cntx.curr_option = TODO_LIST_TASK_OPTION_VIEW;
	 mmi_clndr_entry_view_hdlr();

 }
#endif /* __MMI_TOUCH_SCREEN__ */
 
 /*****************************************************************************
  * FUNCTION
  *  mmi_clndr_get_event_detatils
  * DESCRIPTION
  *  
  * PARAMETERS
  *  start_index	 [IN]		 
  *  menuData		 [?]		 
  *  num_item		 [IN]	
  *  data			 [IN]
  * RETURNS
  *  
  *****************************************************************************/
 void mmi_clndr_get_event_detatils(
				 S32 start_index, 
				 gui_iconlist_menu_item *menu_data, 
				 S32 num_item,
				 MYTIME* date)
 {
	 /*----------------------------------------------------------------*/
	 /* Local Variables 											   */
	 /*----------------------------------------------------------------*/
	 S32 i, count = 0;
	 srv_tdl_event_struct *pevent = NULL;
	 /*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/
//     MMI_TRACE(MMI_TDL_DATA_ALL_ASYNC_ITEM, start_index, num_item, g_tdl_cntx.total);
		 
	 /* Construct task list */
	 for (i = start_index; count < num_item; i++, count++)
	 {
	 	if(g_tdl_cntx.sorted_event[i].source_id == SRV_TDL_EVENT_SOURCE_LOCAL)
	 	{
			srv_tdl_get_cache(
				(void*)&pevent, 
				sizeof(srv_tdl_event_short_struct), 
				SRV_TDL_VCAL_EVENT,
				g_tdl_cntx.sorted_event[i].event_id);
	 	}
		else
		{
			 pevent = (srv_tdl_event_struct *)OslMalloc(sizeof(srv_tdl_event_struct));	
			 srv_tdl_event_get(
				 pevent, 
				 sizeof(srv_tdl_event_struct), 
				 g_tdl_cntx.sorted_event[i].source_id, 
				 g_tdl_cntx.sorted_event[i].event_id);
		}
		
		if (g_tdl_cntx.async_item_type == MMI_TDL_ASYNC_ALL || 
		 	g_tdl_cntx.async_item_type == MMI_TDL_ASYNC_SUB)
		 {
			 mmi_tdl_get_date_string(
						 &pevent->start_time, 
						 (CHAR*)menu_data[count].item_list[1], 
						 (MMI_TDL_MAX_DATE_STRING_LEN + 1) * ENCODING_LENGTH);
		 }
		 else if (g_tdl_cntx.async_item_type == MMI_TDL_ASYNC_DAILY)
		 {
			 mmi_tdl_get_time_string(
								 pevent,
								 SRV_TDL_VCAL_EVENT,
								 date,
								 (CHAR*)menu_data[count].item_list[1],
								 (MMI_TDL_MAX_TIME_STRING_LEN + 1) * 2);						
		 }
				 
		 /* Subject */
		 // birthday added from phonebook
		 if (pevent->category == MMI_TDL_CATEGORY_BIRTHDAY && pevent->src_id == SRV_TDL_EVENT_SOURCE_LOCAL)
		 {
		 	// add from phonebook
		 	 if(pevent->extend != -1)
		 	 {
			     srv_phb_get_name((U16)pevent->extend,(U16*)menu_data[count].item_list[0], MAX_TODO_NOTE_LEN - 1);
		 	 }
			 else
			 {
			 	mmi_ucs2ncpy(
					 (CHAR*)menu_data[count].item_list[0], 
					 (CHAR*)pevent->subject, 
					 SRV_TDL_SUBJECT_SIZE);
			 }
		 }
		 else
		 {
			 mmi_ucs2ncpy(
				 (CHAR*)menu_data[count].item_list[0], 
				 (CHAR*)pevent->subject, 
				 SRV_TDL_SUBJECT_SIZE);
		 }
		 
		 /* Alarm */
		 menu_data[count].image_list[0] = 0;
				 
#ifdef __MMI_BIRTHDAY_REMINDER__
		 if (pevent->category == MMI_TDL_CATEGORY_BIRTHDAY &&
		 pevent->alarm.type != MMI_BR_REMINDER_NONE)
		 {
			 menu_data[count].image_list[0] = (PU8)GetImage(IMG_TODO_LIST_ICON_ALARM);
		 }
		 else
#endif /* __MMI_BIRTHDAY_REMINDER__ */
		 {
			 if (pevent->alarm.type >= MMI_TDL_ALARM_ON)
			 {
				 menu_data[count].image_list[0] = (PU8)GetImage(IMG_TODO_LIST_ICON_ALARM);
			 }
		 }

		 /* Type */
		 menu_data[count].image_list[1] = (PU8)GetImage((U16)(pevent->category + IMG_TODO_LIST_ICON_REMINDER));

		 // event source 
#ifdef __MMI_SNS_CALENDAR__ 
		 if (pevent->src_id == SRV_TDL_EVENT_SOURCE_FACEBOOK)
		 {
			 menu_data[count].image_list[2] = (PU8)GetImage(IMG_CLNDR_EVENT_FACEBOOK);
		 }
		 else if(pevent->src_id == SRV_TDL_EVENT_SOURCE_KAIXIN)
		 {
             menu_data[count].image_list[2] = (PU8)GetImage(IMG_CLNDR_EVENT_KAIXIN);
		 }
		 else if(pevent->src_id == SRV_TDL_EVENT_SOURCE_RENREN)
		 {
             menu_data[count].image_list[2] = (PU8)GetImage(IMG_CLNDR_EVENT_RENREN);
		 }
		 else if(pevent->src_id == SRV_TDL_EVENT_SOURCE_TWITTER)
		 {
             menu_data[count].image_list[2] = (PU8)GetImage(IMG_CLNDR_EVENT_TWITTER);
		 }
#endif		
		 // free buffer
		 if(g_tdl_cntx.sorted_event[i].source_id != SRV_TDL_EVENT_SOURCE_LOCAL)
		 {
			 OslMfree(pevent);
		 }
	 }
 }


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_get_curr_store_idx
 * DESCRIPTION
 *  Get current selected item's store index
 * PARAMETERS
 * 
 * RETURNS
 * The store index of the item.
 *****************************************************************************/
static MMI_BOOL mmi_clndr_get_curr_store_idx(srv_tdl_event_source_enum *source_id, S32 *event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *event_id = g_tdl_cntx.curr_event_id;
    *source_id = g_tdl_cntx.curr_source_id;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_daily_event_list_update
 * DESCRIPTION
 *  update highlight day event list
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
MMI_BOOL mmi_clndr_daily_event_list_update(mmi_cal_daily_scrn_info *scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tdl_event_struct *pevent; 
    U32 i, j = 0;
    MMI_BOOL ret;
    U32 count = 0;
	U32 copy_cnt = 0;
	U32 mask[10] = {0};
	U32 mask_cnt = 1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_CAL_TRACE5(MMI_CAL_DAILY_EVENT_UPDATE, 
	               scrn_info->curr_date.nYear, scrn_info->curr_date.nMonth, scrn_info->curr_date.nDay,
	               g_tdl_cntx.daily_search.state, g_current_view_mode_context.current_mode);
	
    if(g_tdl_cntx.daily_search.state == MMI_CAL_EVENT_SEARCH_DONE_ERR)
    {
        return MMI_TRUE; // no need search anymore
    }
    if(g_tdl_cntx.daily_search.state == MMI_CAL_EVENT_SEARCH_IDLE &&
	!memcmp(&g_tdl_cntx.daily_search.date, &scrn_info->curr_date, 4))
	{
	    ASSERT(0);
	}
    if(g_tdl_cntx.daily_search.state == MMI_CAL_EVENT_SEARCH_DONE_OK &&
	!memcmp(&g_tdl_cntx.daily_search.date, &scrn_info->curr_date, 4))
	{
	    return MMI_TRUE;
	}
    if(g_tdl_cntx.daily_search.state == MMI_CAL_EVENT_SEARCH_GOING && 
	!memcmp(&g_tdl_cntx.daily_search.date, &scrn_info->curr_date, 4))
	{
	    return MMI_TRUE;
	}

    if(g_tdl_cntx.daily_search.state == MMI_CAL_EVENT_SEARCH_IDLE && 
	memcmp(&g_tdl_cntx.daily_search.date, &scrn_info->curr_date, 4))
	{
	    memcpy(&g_tdl_cntx.daily_search.date, &scrn_info->curr_date, sizeof(MYTIME));
	}
	// daily list, end the last search 
	if(g_tdl_cntx.daily_search.state == MMI_CAL_EVENT_SEARCH_GOING && 
	memcmp(&g_tdl_cntx.daily_search.date, &scrn_info->curr_date, 4))
	{
	    srv_tdl_event_search_end(g_tdl_cntx.daily_search.search_id);
	    g_tdl_cntx.daily_search.state = MMI_CAL_EVENT_SEARCH_IDLE;
	    memcpy(&g_tdl_cntx.daily_search.date, &scrn_info->curr_date, sizeof(MYTIME));
	}

	if(g_tdl_cntx.daily_search.state == MMI_CAL_EVENT_SEARCH_DONE_OK &&
	memcmp(&g_tdl_cntx.daily_search.date, &scrn_info->curr_date, 4))
	{
	    if(g_tdl_cntx.daily_search.event_buf)
	    {
	        OslMfree(g_tdl_cntx.daily_search.event_buf);
	        g_tdl_cntx.daily_search.event_buf = NULL;
	    }
	    g_tdl_cntx.daily_search.state = MMI_CAL_EVENT_SEARCH_IDLE;
	    memcpy(&g_tdl_cntx.daily_search.date, &scrn_info->curr_date, sizeof(MYTIME));
	    g_tdl_cntx.daily_search.event_cnt = 0;
	    g_tdl_cntx.daily_search.search_id = 0;
	}
	
	// get from monthly event list
	if(g_tdl_cntx.monthly_search.state == MMI_CAL_EVENT_SEARCH_DONE_OK && 
	!memcmp(&g_tdl_cntx.monthly_search.date, &scrn_info->curr_date, 3))
	{	 
	    if(g_tdl_cntx.monthly_search.event_cnt == 0)
	    {
	        g_tdl_cntx.daily_search.state = MMI_CAL_EVENT_SEARCH_DONE_OK;     
	        g_tdl_cntx.daily_search.event_cnt = 0;
	        return MMI_TRUE;
	    }
	    
	    ASSERT(g_tdl_cntx.monthly_search.event_buf);
	    pevent = (srv_tdl_event_struct *)OslMalloc(sizeof(srv_tdl_event_struct));
	    for(i = 0; i < g_tdl_cntx.monthly_search.event_cnt; i++)
	    {
			 srv_tdl_event_get(
				 pevent, 
				 sizeof(srv_tdl_event_struct), 
				 g_tdl_cntx.monthly_search.event_buf[i].source_id, 
				 g_tdl_cntx.monthly_search.event_buf[i].event_id);

		     ret = srv_tdl_event_search_check_daily((srv_tdl_event_short_struct *)pevent, scrn_info->curr_date);
		     if(ret)
		     {    
		     	  count++;
		          mask[i/32] = ((1 << (i%32)) | mask[i/32]); 
				  mask_cnt = i/32 + 1;
		     }  
	    }
	    
	    g_tdl_cntx.daily_search.event_cnt = count;
	    if(count > 0)
	    {
	        g_tdl_cntx.daily_search.event_buf = (srv_tdl_event_id_struct *)OslMalloc(count * sizeof(srv_tdl_event_id_struct));
	        for(i = 0; i < (32*mask_cnt); i++)
	        {
	            if(mask[i/32] & (1 << (i%32)))
	            {
					copy_cnt++;
	                memcpy(&g_tdl_cntx.daily_search.event_buf[j++] ,&g_tdl_cntx.monthly_search.event_buf[i], sizeof(srv_tdl_event_id_struct));
	            } 
	        }
			ASSERT(count == copy_cnt);
	    }
	    g_tdl_cntx.daily_search.state = MMI_CAL_EVENT_SEARCH_DONE_OK;   
	    OslMfree(pevent);
	    return MMI_TRUE;
	}
	// get from all event list
	if(g_tdl_cntx.all_search.state == MMI_CAL_EVENT_SEARCH_DONE_OK)
	{
		if(g_tdl_cntx.all_search.event_cnt == 0)
	    {
	        g_tdl_cntx.daily_search.state = MMI_CAL_EVENT_SEARCH_DONE_OK;     
	        g_tdl_cntx.daily_search.event_cnt = 0;
	        return MMI_TRUE;
	    }
	    
	    ASSERT(g_tdl_cntx.all_search.event_buf);
	    pevent = (srv_tdl_event_struct *)OslMalloc(sizeof(srv_tdl_event_struct));
	    for(i = 0; i < g_tdl_cntx.all_search.event_cnt; i++)
	    {
			 srv_tdl_event_get(
				 pevent, 
				 sizeof(srv_tdl_event_struct), 
				 g_tdl_cntx.all_search.event_buf[i].source_id, 
				 g_tdl_cntx.all_search.event_buf[i].event_id);

		     ret = srv_tdl_event_search_check_daily((srv_tdl_event_short_struct *)pevent, scrn_info->curr_date);
		     if(ret)
		     {    
		          count++;
		          mask[i/32] = ((1 << (i%32)) | mask[i/32]); 
				  mask_cnt = i/32 + 1;		          
		     }  
	    }
	    
	    g_tdl_cntx.daily_search.event_cnt = count;
	    if(count > 0)
	    {
	        g_tdl_cntx.daily_search.event_buf = (srv_tdl_event_id_struct *)OslMalloc(count * sizeof(srv_tdl_event_id_struct));
	        for(i = 0; i < (32*mask_cnt); i++)
	        {
	            if(mask[i/32] & (1 << (i%32)))
	            {
					copy_cnt++;
	                memcpy(&g_tdl_cntx.daily_search.event_buf[j++] ,&g_tdl_cntx.all_search.event_buf[i], sizeof(srv_tdl_event_id_struct));
	            } 
	        }
			ASSERT(count == copy_cnt);
	    }
	    g_tdl_cntx.daily_search.state = MMI_CAL_EVENT_SEARCH_DONE_OK;
	    OslMfree(pevent);
	    return MMI_TRUE;
	}
	g_tdl_cntx.daily_search.search_id = 0;
	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_weekly_event_list_update
 * DESCRIPTION
 *  update highlight weekly event list
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
MMI_BOOL mmi_clndr_weekly_event_list_update(MYTIME *date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tdl_event_struct *pevent; 
    U32 i, j = 0;
    MMI_BOOL ret;
    U32 count = 0;
	U32 copy_cnt = 0;
	U32 mask[10] = {0};
	U32 mask_cnt = 1;
    U8 dayIndex;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	dayIndex = date->DayIndex;
	
	MMI_CAL_TRACE5(MMI_CAL_WEEKLY_EVENT_UPDATE, date->nYear, date->nMonth, date->nDay,
	               g_tdl_cntx.weekly_search[dayIndex].state, g_current_view_mode_context.current_mode);
    
    if(g_tdl_cntx.weekly_search[dayIndex].state == MMI_CAL_EVENT_SEARCH_DONE_ERR)
    {
        return MMI_TRUE; // no need search anymore
    }
    if(g_tdl_cntx.weekly_search[dayIndex].state == MMI_CAL_EVENT_SEARCH_IDLE &&
	!memcmp(&g_tdl_cntx.weekly_search[dayIndex].date, date, 4))
	{
	    ASSERT(0);
	}
    if(g_tdl_cntx.weekly_search[dayIndex].state == MMI_CAL_EVENT_SEARCH_DONE_OK &&
	!memcmp(&g_tdl_cntx.weekly_search[dayIndex].date, date, 4))
	{
	    return MMI_TRUE;
	}
    if(g_tdl_cntx.weekly_search[dayIndex].state == MMI_CAL_EVENT_SEARCH_GOING && 
	!memcmp(&g_tdl_cntx.weekly_search[dayIndex].date, date, 4))
	{
	    return MMI_TRUE;
	}

    if(g_tdl_cntx.weekly_search[dayIndex].state == MMI_CAL_EVENT_SEARCH_IDLE && 
	memcmp(&g_tdl_cntx.weekly_search[dayIndex].date, date, 4))
	{
	    memcpy(&g_tdl_cntx.weekly_search[dayIndex].date, date, sizeof(MYTIME));
	}
	// daily list, end the last search 
	if(g_tdl_cntx.weekly_search[dayIndex].state == MMI_CAL_EVENT_SEARCH_GOING && 
	memcmp(&g_tdl_cntx.weekly_search[dayIndex].date, date, 4))
	{
	    srv_tdl_event_search_end(g_tdl_cntx.weekly_search[dayIndex].search_id);
	    g_tdl_cntx.weekly_search[dayIndex].state = MMI_CAL_EVENT_SEARCH_IDLE;
	    memcpy(&g_tdl_cntx.weekly_search[dayIndex].date, date, sizeof(MYTIME));
	}

	if(g_tdl_cntx.weekly_search[dayIndex].state == MMI_CAL_EVENT_SEARCH_DONE_OK &&
	memcmp(&g_tdl_cntx.weekly_search[dayIndex].date, date, 4))
	{
	    if(g_tdl_cntx.weekly_search[dayIndex].event_buf)
	    {
	        OslMfree(g_tdl_cntx.weekly_search[dayIndex].event_buf);
	        g_tdl_cntx.weekly_search[dayIndex].event_buf = NULL;
	    }
	    g_tdl_cntx.weekly_search[dayIndex].state = MMI_CAL_EVENT_SEARCH_IDLE;
	    memcpy(&g_tdl_cntx.weekly_search[dayIndex].date, date, sizeof(MYTIME));
	    g_tdl_cntx.weekly_search[dayIndex].event_cnt = 0;
	    g_tdl_cntx.weekly_search[dayIndex].search_id = 0;
	}
	
	// get from monthly event list
	if(g_tdl_cntx.monthly_search.state == MMI_CAL_EVENT_SEARCH_DONE_OK && 
	!memcmp(&g_tdl_cntx.monthly_search.date, date, 3))
	{	 
	    if(g_tdl_cntx.monthly_search.event_cnt == 0)
	    {
	        g_tdl_cntx.weekly_search[dayIndex].state = MMI_CAL_EVENT_SEARCH_DONE_OK;     
	        g_tdl_cntx.weekly_search[dayIndex].event_cnt = 0;
	        return MMI_TRUE;
	    }
	    
	    ASSERT(g_tdl_cntx.monthly_search.event_buf);
	    pevent = (srv_tdl_event_struct *)OslMalloc(sizeof(srv_tdl_event_struct));
	    for(i = 0; i < g_tdl_cntx.monthly_search.event_cnt; i++)
	    {
			 srv_tdl_event_get(
				 pevent, 
				 sizeof(srv_tdl_event_struct), 
				 g_tdl_cntx.monthly_search.event_buf[i].source_id, 
				 g_tdl_cntx.monthly_search.event_buf[i].event_id);

		     ret = srv_tdl_event_search_check_daily((srv_tdl_event_short_struct *)pevent, *date);
		     if(ret)
		     {    
				 mask[i/32] = ((1 << (i%32)) | mask[i/32]); 
				 mask_cnt = i/32 + 1;
		         count++;
		     }  
	    }
	    
	    g_tdl_cntx.weekly_search[dayIndex].event_cnt = count;
	    if(count > 0)
	    {
	        g_tdl_cntx.weekly_search[dayIndex].event_buf = (srv_tdl_event_id_struct *)OslMalloc(count * sizeof(srv_tdl_event_id_struct));
	        for(i = 0; i < (32*mask_cnt); i++)
	        {
	            if(mask[i/32] & (1 << (i%32)))
	            {
					copy_cnt++;
	                memcpy(&g_tdl_cntx.weekly_search[dayIndex].event_buf[j++] ,&g_tdl_cntx.monthly_search.event_buf[i], sizeof(srv_tdl_event_id_struct));
	            } 
	        }
			ASSERT(count == copy_cnt);
	    }
	    g_tdl_cntx.weekly_search[dayIndex].state = MMI_CAL_EVENT_SEARCH_DONE_OK;   
	    OslMfree(pevent);
	    return MMI_TRUE;
	}
	// get from all event list
	if(g_tdl_cntx.all_search.state == MMI_CAL_EVENT_SEARCH_DONE_OK)
	{
		if(g_tdl_cntx.all_search.event_cnt == 0)
	    {
	        g_tdl_cntx.weekly_search[dayIndex].state = MMI_CAL_EVENT_SEARCH_DONE_OK;     
	        g_tdl_cntx.weekly_search[dayIndex].event_cnt = 0;
	        return MMI_TRUE;
	    }
	    
	    ASSERT(g_tdl_cntx.all_search.event_buf);
	    pevent = (srv_tdl_event_struct *)OslMalloc(sizeof(srv_tdl_event_struct));
	    for(i = 0; i < g_tdl_cntx.all_search.event_cnt; i++)
	    {
			 srv_tdl_event_get(
				 pevent, 
				 sizeof(srv_tdl_event_struct), 
				 g_tdl_cntx.all_search.event_buf[i].source_id, 
				 g_tdl_cntx.all_search.event_buf[i].event_id);

		     ret = srv_tdl_event_search_check_daily((srv_tdl_event_short_struct *)pevent, *date);
		     if(ret)
		     {    
		          mask[i/32] = ((1 << (i%32)) | mask[i/32]); 
				  mask_cnt = i/32 + 1;	
		          count++;
		     }  
	    }
	    
	    g_tdl_cntx.weekly_search[dayIndex].event_cnt = count;
	    if(count > 0)
	    {
	        g_tdl_cntx.weekly_search[dayIndex].event_buf = (srv_tdl_event_id_struct *)OslMalloc(count * sizeof(srv_tdl_event_id_struct));
	        for(i = 0; i < (32*mask_cnt); i++)
	        {
	            if(mask[i/32] & (1 << (i%32)))
	            {
					copy_cnt++;
	                memcpy(&g_tdl_cntx.weekly_search[dayIndex].event_buf[j++] ,&g_tdl_cntx.all_search.event_buf[i], sizeof(srv_tdl_event_id_struct));
	            } 
	        }
			ASSERT(count == copy_cnt);
	    }
	    g_tdl_cntx.weekly_search[dayIndex].state = MMI_CAL_EVENT_SEARCH_DONE_OK;
	    OslMfree(pevent);
	    return MMI_TRUE;
	}
	g_tdl_cntx.weekly_search[dayIndex].search_id = 0;
	return MMI_FALSE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_monthly_event_list_update
 * DESCRIPTION
 *  update highlight monthly event list
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
MMI_BOOL mmi_clndr_monthly_event_list_update(mmi_cal_daily_scrn_info *scrn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tdl_event_struct *pevent; 
    U32 i, j = 0;
    MMI_BOOL ret;
    U32 count = 0;
	U32 copy_cnt = 0;
    U32 mask_cnt = 1;
	U32 mask[10] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_CAL_TRACE5(MMI_CAL_MONTHLY_EVENT_UPDATE, 
	               scrn_info->curr_date.nYear, scrn_info->curr_date.nMonth, scrn_info->curr_date.nDay,
	               g_tdl_cntx.monthly_search.state, g_current_view_mode_context.current_mode);
	
    if(g_tdl_cntx.monthly_search.state == MMI_CAL_EVENT_SEARCH_DONE_ERR)
    {
        return MMI_TRUE; // no need search anymore
    }
    if(g_tdl_cntx.monthly_search.state == MMI_CAL_EVENT_SEARCH_IDLE &&
	!memcmp(&g_tdl_cntx.monthly_search.date, &scrn_info->curr_date, 3))
	{
	    ASSERT(0);
	}
    if(g_tdl_cntx.monthly_search.state == MMI_CAL_EVENT_SEARCH_DONE_OK &&
	!memcmp(&g_tdl_cntx.monthly_search.date, &scrn_info->curr_date, 3))
	{
	    return MMI_TRUE;
	}
    if(g_tdl_cntx.monthly_search.state == MMI_CAL_EVENT_SEARCH_GOING && 
	!memcmp(&g_tdl_cntx.monthly_search.date, &scrn_info->curr_date, 3))
	{
	    return MMI_TRUE;
	}

    if(g_tdl_cntx.monthly_search.state == MMI_CAL_EVENT_SEARCH_IDLE && 
	memcmp(&g_tdl_cntx.monthly_search.date, &scrn_info->curr_date, 3))
	{
	    memcpy(&g_tdl_cntx.monthly_search.date, &scrn_info->curr_date, sizeof(MYTIME));
	}
	if(g_tdl_cntx.monthly_search.state == MMI_CAL_EVENT_SEARCH_GOING && 
	memcmp(&g_tdl_cntx.monthly_search.date, &scrn_info->curr_date, 3))
	{
	    srv_tdl_event_search_end(g_tdl_cntx.monthly_search.search_id);
	    g_tdl_cntx.monthly_search.state = MMI_CAL_EVENT_SEARCH_IDLE;
	    memcpy(&g_tdl_cntx.monthly_search.date, &scrn_info->curr_date, sizeof(MYTIME));
	}

	if(g_tdl_cntx.monthly_search.state == MMI_CAL_EVENT_SEARCH_DONE_OK &&
	memcmp(&g_tdl_cntx.monthly_search.date, &scrn_info->curr_date, 3))
	{
	    if(g_tdl_cntx.monthly_search.event_buf)
	    {
	        OslMfree(g_tdl_cntx.monthly_search.event_buf);
	        g_tdl_cntx.monthly_search.event_buf = NULL;
	    }
	    g_tdl_cntx.monthly_search.state = MMI_CAL_EVENT_SEARCH_IDLE;
	    memcpy(&g_tdl_cntx.monthly_search.date, &scrn_info->curr_date, sizeof(MYTIME));
	    g_tdl_cntx.monthly_search.event_cnt = 0;
	    g_tdl_cntx.monthly_search.search_id = 0;
	}
	
	// get from all event list
	if(g_tdl_cntx.all_search.state == MMI_CAL_EVENT_SEARCH_DONE_OK)
	{
		if(g_tdl_cntx.all_search.event_cnt == 0)
	    {
	        g_tdl_cntx.monthly_search.state = MMI_CAL_EVENT_SEARCH_DONE_OK;     
	        g_tdl_cntx.monthly_search.event_cnt = 0;
	        return MMI_TRUE;
	    }
	    
	    ASSERT(g_tdl_cntx.all_search.event_buf);
	    pevent = (srv_tdl_event_struct *)OslMalloc(sizeof(srv_tdl_event_struct));
	    for(i = 0; i < g_tdl_cntx.all_search.event_cnt; i++)
	    {
			 srv_tdl_event_get(
				 pevent, 
				 sizeof(srv_tdl_event_struct), 
				 g_tdl_cntx.all_search.event_buf[i].source_id, 
				 g_tdl_cntx.all_search.event_buf[i].event_id);

		     ret = srv_tdl_event_search_check_monthly((srv_tdl_event_short_struct *)pevent, scrn_info->curr_date);
		     if(ret)
		     {    
		          mask[i/32] = ((1 << (i%32)) | mask[i/32]); 
				  mask_cnt = i/32 + 1;	
		          count++;
		     }  
	    }
	    
	    g_tdl_cntx.monthly_search.event_cnt = count;
	    if(count > 0)
	    {
	        g_tdl_cntx.monthly_search.event_buf = (srv_tdl_event_id_struct *)OslMalloc(count * sizeof(srv_tdl_event_id_struct));
	        for(i = 0; i < (32*mask_cnt); i++)
	        {
	            if(mask[i/32] & (1 << (i%32)))
	            {
					copy_cnt++;
	                memcpy(&g_tdl_cntx.monthly_search.event_buf[j++] ,&g_tdl_cntx.all_search.event_buf[i], sizeof(srv_tdl_event_id_struct));
	            } 
	        }
			ASSERT(count == copy_cnt);
	    }
	    g_tdl_cntx.monthly_search.state = MMI_CAL_EVENT_SEARCH_DONE_OK;
	    OslMfree(pevent);
	    return MMI_TRUE;
	}
	g_tdl_cntx.monthly_search.search_id = 0;
	return MMI_FALSE;
}

#define SNS_END


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_get_async_items
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_index     [IN]        
 *  menuData        [?]         
 *  num_item        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_clndr_get_async_items(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cal_daily_scrn_info *scrn_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_tdl_cntx.async_item_type == MMI_TDL_ASYNC_DAILY)
    {
        scrn_data = mmi_frm_scrn_get_user_data(GRP_ID_CAL_MAIN, SCR_TDL_CAL_DAILY_LIST);
        mmi_clndr_get_event_detatils(start_index, menu_data, num_item, &scrn_data->curr_date);
    }
    else
    {
        mmi_clndr_get_event_detatils(start_index, menu_data, num_item, NULL);
    }
    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_list_leave_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_index     [IN]        
 *  menuData        [?]         
 *  num_item        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_clndr_list_leave_proc(mmi_event_struct *parm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (parm->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
            if (parm->user_data != NULL)
            {
                OslMfree(parm->user_data);
                parm->user_data = NULL;
            }
            g_tdl_cntx.curr_option = TODO_LIST_OPTION_TOTAL;
            break;
        }
        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_exit_daily_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clndr_exit_daily_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cal_daily_scrn_info *daily_scrn_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    daily_scrn_data = mmi_frm_scrn_get_user_data(GRP_ID_CAL_MAIN, SCR_TDL_CAL_DAILY_LIST);
    mmi_clndr_update_date(&daily_scrn_data->curr_date);
    wgui_cat85_set_disable_arrowkey(WGUI_CAT85_DISABLE_NONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_next_day_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clndr_next_day_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cal_daily_scrn_info *old_scrn_data;
    mmi_cal_daily_scrn_info *new_scrn_data = OslMalloc(sizeof(mmi_cal_daily_scrn_info));
    MYTIME int_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_scrn_data = mmi_frm_scrn_get_user_data(GRP_ID_CAL_MAIN, SCR_TDL_CAL_DAILY_LIST);

    /* Check date */
    if (old_scrn_data->curr_date.nMonth == 12 && 
        old_scrn_data->curr_date.nDay == 31 && 
        old_scrn_data->curr_date.nYear == CLNDR_END_YEAR)
    {
        mmi_popup_display_simple((WCHAR*)((UI_string_type)GetString(STR_CLNDR_OUT_OF_CALENDAR)), MMI_EVENT_FAILURE, GRP_ID_CAL_MAIN, NULL);
        return;
    }
        
    /* Update Date */
    memset(&int_time, 0, sizeof(MYTIME));
    int_time.nDay = 1;
    IncrementTime(old_scrn_data->curr_date, int_time, &old_scrn_data->curr_date);
    memcpy(new_scrn_data, old_scrn_data, sizeof(mmi_cal_daily_scrn_info));
    
    mmi_frm_send_incomplete_key_event_to_new_screen(MMI_TRUE);
    if (!mmi_frm_scrn_enter(GRP_ID_CAL_MAIN, SCR_ID_DUMMY, NULL, NULL, MMI_FRM_FULL_SCRN))
        return;
    mmi_frm_scrn_close(GRP_ID_CAL_MAIN, SCR_TDL_CAL_DAILY_LIST);
    mmi_frm_send_incomplete_key_event_to_new_screen(MMI_TRUE);
    mmi_frm_scrn_first_enter(
                    GRP_ID_CAL_MAIN, 
                    SCR_TDL_CAL_DAILY_LIST, 
                    mmi_clndr_entry_daily_list,
                    new_scrn_data);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_entry_list_option
 * DESCRIPTION
 *  Show option list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clndr_entry_list_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clndr_set_swith_mode_flag(MMI_FALSE);
    mmi_entry_list_option(GRP_ID_CAL_MAIN, MITEM_TODO_LIST_TASK_OPTION_VEVENT, mmi_cal_list_option_group_proc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cal_list_option_group_proc
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_cal_list_option_group_proc(mmi_event_struct* evt)
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
            mmi_cal_list_option_menu_entry_hdlr(menu_evt);
            break;
#ifdef __MMI_TODO_SEARCH__
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            mmi_cal_list_option_menu_highlight_hdlr(menu_evt);
            break;
#endif
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_cal_list_option_menu_select_hdlr(menu_evt);
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
 *  mmi_cal_list_option_menu_entry_hdlr
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cal_list_option_menu_entry_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_tdl_cntx.daily_search.event_cnt == 0 && g_current_view_mode_context.current_mode == MMI_VIEW_MODE_DAILY)
		|| (g_tdl_cntx.all_search.event_cnt == 0 && g_current_view_mode_context.current_mode == MMI_VIEW_MODE_ALL))
    {
        cui_menu_set_item_hidden(
            menu_evt->sender_id, 
            MITEM_TODO_LIST_VIEW, 
            MMI_TRUE); 
            cui_menu_set_item_hidden(
            menu_evt->sender_id, 
            MITEM_TODO_LIST_EDIT, 
            MMI_TRUE); 
 #ifdef __MMI_TODO_SEARCH__           
            cui_menu_set_item_hidden(
            menu_evt->sender_id, 
            MITEM_TODO_LIST_SEARCH, 
            MMI_TRUE); 
 #endif           
            cui_menu_set_item_hidden(
            menu_evt->sender_id, 
            MITEM_TODO_LIST_DELETE, 
            MMI_TRUE); 
        #ifdef __MMI_VCALENDAR__
            cui_menu_set_item_hidden(
            menu_evt->sender_id, 
            MENU_VCLNDR_FORWARD, 
            MMI_TRUE); 
        #ifdef __MMI_FILE_MANAGER__
            cui_menu_set_item_hidden(
            menu_evt->sender_id, 
            MENU_VCLNDR_SEND_BY_FILEMGR, 
            MMI_TRUE); 
        #endif
        #endif /* __MMI_VCALENDAR__ */       
    }
    else
    {
            cui_menu_set_item_hidden(
            menu_evt->sender_id, 
            MITEM_TODO_LIST_VIEW, 
            MMI_FALSE); 
 #ifdef __MMI_TODO_SEARCH__             
            cui_menu_set_item_hidden(
            menu_evt->sender_id, 
            MITEM_TODO_LIST_SEARCH, 
            MMI_FALSE); 
 #endif  	
            cui_menu_set_item_hidden(
            menu_evt->sender_id, 
            MITEM_TODO_LIST_EDIT, 
            MMI_FALSE); 
 
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
	
        #ifdef __MMI_VCALENDAR__
            cui_menu_set_item_hidden(
            menu_evt->sender_id, 
            MENU_VCLNDR_FORWARD, 
            MMI_FALSE); 
        #ifdef __MMI_FILE_MANAGER__
            cui_menu_set_item_hidden(
            menu_evt->sender_id, 
            MENU_VCLNDR_SEND_BY_FILEMGR, 
            MMI_FALSE); 
        #endif
        #endif /* __MMI_VCALENDAR__ */       
    }   
    switch (menu_evt->parent_menu_id)
    {
#ifdef __MMI_VCALENDAR__
        case MENU_VCLNDR_FORWARD:
            cui_menu_set_default_title(
                menu_evt->sender_id, 
                (WCHAR*)get_string(STR_ID_VCLNDR_FORWARD), 
                (UI_image_type)get_image(GetRootTitleIcon(ORGANIZER_CALENDER_MENU)));
            break;
#endif
#ifdef __MMI_TODO_SEARCH__
        case MITEM_TODO_LIST_SEARCH:
            cui_menu_set_default_title(
                    menu_evt->sender_id, 
                    get_string(STR_GLOBAL_SEARCH),
                    get_image(ORGANIZER_TITLE_IMAGEID));
            break;
#endif
        default:
            cui_menu_set_default_title(
                menu_evt->sender_id, 
                (WCHAR*)get_string(STR_GLOBAL_OPTIONS), 
                (UI_image_type)get_image(GetRootTitleIcon(ORGANIZER_CALENDER_MENU)));
            break;
    }
}

#ifdef __MMI_TODO_SEARCH__

/*****************************************************************************
 * FUNCTION
 *  mmi_cal_list_option_menu_highlight_hdlr
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cal_list_option_menu_highlight_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_tdl_common_group_data_struct *opt_user_data = menu_evt->user_data;     
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->highlighted_menu_id)
    {
        case MITEM_TODO_LIST_SEARCH:
            cui_menu_set_item_hidden(
                    opt_user_data->child_id, 
                    MITEM_TODO_LIST_SEARCH_BY_LOC, 
                    MMI_FALSE);            
            break;
            
        default:
            break;
    }
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_cal_list_option_menu_select_hdlr
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cal_list_option_menu_select_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_tdl_common_group_data_struct *opt_user_data = menu_evt->user_data;  
    srv_tdl_event_source_enum source_id;
    S32 event_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  //  g_tdl_cntx.curr_store_idx = mmi_tdl_get_curr_store_idx(); 
    if(!mmi_clndr_get_curr_store_idx(&source_id, &event_id))
    {
         // error happen;
         mmi_popup_display_simple(
                (WCHAR*)(get_string(STR_GLOBAL_ERROR)), 
                MMI_EVENT_FAILURE, 
                GRP_ID_ROOT, 
                NULL);
         return;
    };
 //   srv_tdl_get(&g_tdl_cntx.curr_event, sizeof(srv_tdl_event_struct), SRV_TDL_VCAL_EVENT, g_tdl_cntx.curr_store_idx);
    srv_tdl_event_get(
        &g_tdl_cntx.curr_event, 
        sizeof(srv_tdl_event_struct),
        source_id,
        event_id); 
    switch (menu_evt->highlighted_menu_id)
    {
#ifdef __MMI_SNS_CALENDAR__     
        case MENU_ID_CLNDR_EVENT_FILTER:
        {
            mmi_clndr_entry_filter_hdlr();
            break;
        }
#endif        
        case MITEM_TODO_LIST_VIEW:
        {
            g_tdl_cntx.curr_option = TODO_LIST_TASK_OPTION_VIEW;
            mmi_tdl_view_with_sg(
                        opt_user_data->parent_id, 
                        SRV_TDL_VCAL_EVENT,
                        g_tdl_cntx.curr_source_id, 
                        g_tdl_cntx.curr_event_id);        
            break;
        }
        case MITEM_TODO_LIST_ADD:
        {
            mmi_clndr_entry_add_hdlr();
            g_tdl_cntx.curr_option = TODO_LIST_TASK_OPTION_ADD;
            break;
        }
        case MITEM_TODO_LIST_EDIT:
        {
            mmi_cal_group_data_struct *cal_group_cntx;

            cal_group_cntx = mmi_frm_group_get_user_data(GRP_ID_CAL_MAIN);            
            g_tdl_cntx.curr_option = TODO_LIST_TASK_OPTION_EDIT;
           
        #ifdef __MMI_BIRTHDAY_REMINDER__
            if (g_tdl_cntx.curr_event.category == MMI_TDL_CATEGORY_BIRTHDAY)
            {
                mmi_tdl_br_entry_bday_edit_from_org(opt_user_data->parent_id);
            }
            else
        #endif
            {
                cal_group_cntx->cui_cal_save_gid = cui_cal_save_create(opt_user_data->parent_id);
                cui_cal_save_set_operation_type(cal_group_cntx->cui_cal_save_gid, MMI_TDL_OP_TYPE_EDIT);
                cui_cal_save_set_title(cal_group_cntx->cui_cal_save_gid, STR_GLOBAL_EDIT);
                cui_cal_save_set_event(cal_group_cntx->cui_cal_save_gid, &g_tdl_cntx.curr_event);
                cui_cal_save_run(cal_group_cntx->cui_cal_save_gid);
            }
            break;
        }
        case MITEM_TODO_LIST_DELETE:
        {
            g_tdl_cntx.curr_option = TODO_LIST_TASK_OPTION_DELETE;
            mmi_tdl_entry_delete_confirm(opt_user_data->parent_id);        
            break;
        }
    #ifdef __MMI_VCALENDAR__
    #ifndef __MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__
        case MENU_VCLNDR_SEND_BY_SMS:
        {
            cui_vcal_send_param_struct para;
            mmi_id sg_id;    

            para.send_type = MMI_VCAL_SEND_BY_SMS;
            para.vcal_type = SRV_VCAL_VEVENT;
            para.buff = &g_tdl_cntx.curr_event;
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
            para.vcal_type = SRV_VCAL_VEVENT;
            para.buff = &g_tdl_cntx.curr_event;
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
            para.vcal_type = SRV_VCAL_VEVENT;
            para.buff = &g_tdl_cntx.curr_event;
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
            para.vcal_type = SRV_VCAL_VEVENT;
            para.buff = &g_tdl_cntx.curr_event;
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
            param.para_type = MMI_VCAL_TYPE_BUFF;
            param.u.obj.vcal_type = SRV_VCAL_VEVENT;
            param.u.obj.buff = &g_tdl_cntx.curr_event;
            cui_vcal_save_to_file_set_para(sg_id, param);            
            cui_vcal_save_to_file_run(sg_id);
            break;
        }
    #endif /* __MMI_FILE_MANAGER__ */
    #endif /* __MMI_VCALENDAR__ */
    #ifdef __MMI_TODO_SEARCH__
        case MITEM_TODO_LIST_SEARCH_BY_TIME:
        {
            mmi_tdl_entry_search_by_time();
            break;
        }   
        case MITEM_TODO_LIST_SEARCH_BY_NOTE:
        {
            mmi_tdl_entry_search_by_note();
            break;
        }
        case MITEM_TODO_LIST_SEARCH_BY_LOC:
        {
            mmi_tdl_entry_search_by_location();
            break;
        }
    #endif
        default:
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_is_spec_time_event_exist
 * DESCRIPTION
 *  Check if event presents in sepc time.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_tdl_is_spec_time_event_exist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 total;
    U8 result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    g_tdl_cntx.search.type = SRV_TDL_SEARCH_TYPE_DURATION;    
    srv_tdl_search(
                        NULL,
                        NUM_OF_TDL,
                        (srv_tdl_vcal_enum)g_tdl_cntx.vcal_filter,
                        g_tdl_cntx.search,
                        &total);

    if (total > 0)
    {
        result = MMI_TRUE;
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_del_spec_time_popup_callback
 * DESCRIPTION
 *  Show task type list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_tdl_del_spec_time_popup_callback(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(parent_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_delete_spec_time
 * DESCRIPTION
 *  Delete events in spec time.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_tdl_delete_spec_time(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 error_code;
    U32 i;
	mmi_popup_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_tdl_cntx.search.type = SRV_TDL_SEARCH_TYPE_DURATION;
    error_code = srv_tdl_search(
                        g_tdl_cntx.sorted_list,
                        NUM_OF_TDL,
                        (srv_tdl_vcal_enum)g_tdl_cntx.vcal_filter,
                        g_tdl_cntx.search,
                        &g_tdl_cntx.total);
                        
    if (error_code != SRV_TDL_RESULT_OK)                        
    {
        return;
    }

	mmi_popup_property_init(&arg);
	arg.parent_id = parent_id;
	arg.callback = mmi_tdl_popup_proc;
	
    mmi_tdl_popup_user_data_init(&g_tdl_popup_user_data);
    g_tdl_popup_user_data.sg_id = parent_id;
    g_tdl_popup_user_data.callback_function = mmi_tdl_del_spec_time_popup_callback;
    arg.user_tag = (void*)&g_tdl_popup_user_data;	
	mmi_popup_display((WCHAR*)(get_string(STR_GLOBAL_DELETED)), MMI_EVENT_SUCCESS, &arg);
    
	for (i = 0; i < g_tdl_cntx.total; i++)
	{	
        mmi_tdl_delete_record(
                        g_tdl_cntx.sorted_list[i].index, 
                        g_tdl_cntx.sorted_list[i].type);
	}
	
     return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_delete_spec_time_confirm
 * DESCRIPTION
 *  Confirm if delete spec time events.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clndr_delete_spec_time_confirm(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_clndr_get_spec_time())
    {
        mmi_popup_display_simple(
                        (WCHAR*)(get_string(STR_TODO_LIST_WRONG_DATE_MSG)), 
                        MMI_EVENT_FAILURE, 
                        GRP_ID_ROOT, 
                        NULL);
        return;
    }

    if (!mmi_tdl_is_spec_time_event_exist())
    {
        mmi_popup_display_simple(
                        (WCHAR*)(get_string(STR_ID_TDL_NO_EVENTS)), 
                        MMI_EVENT_FAILURE, 
                        GRP_ID_ROOT, 
                        NULL);
        mmi_frm_group_close(GRP_ID_CAL_DELETE);
        return;
    }

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = parent_id;
    arg.callback = (mmi_proc_func)mmi_clndr_comfirm_proc;

    mmi_clndr_confirm_user_data_init(&clndr_confirm_user_data);
    clndr_confirm_user_data.sg_id = parent_id;
    clndr_confirm_user_data.LSK_function = mmi_tdl_delete_spec_time;
    clndr_confirm_user_data.RSK_function = mmi_tdl_delete_goback;
    arg.f_auto_map_empty_softkey = MMI_FALSE;
    arg.user_tag = (void*)&clndr_confirm_user_data;
    mmi_confirm_display(
        (WCHAR*)get_string(STR_ID_CLNDR_DELETE_SPEC_PERIOD_QUERY),
        MMI_EVENT_QUERY,
        &arg);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_delete_goback
 * DESCRIPTION
 *  Delete goback.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static void mmi_tdl_delete_goback(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(parent_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_get_spec_time
 * DESCRIPTION
 *  Check spec time.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
U8 mmi_clndr_get_spec_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = DT_TIME_GREATER;
    cui_inline_item_date_time_struct start_date, end_date;
    cui_inline_item_time_struct start_time, end_time;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_tdl_cntx.search.type = SRV_TDL_SEARCH_TYPE_DURATION;
    memset(&g_tdl_cntx.search.u.duration, 0, sizeof(MYTIME) * 2);

    cui_inline_get_value(mmi_clndr_del_spec_child_gid, CUI_INLINE_ITEM_ID_BASE + 1, &start_date);
    cui_inline_get_value(mmi_clndr_del_spec_child_gid, CUI_INLINE_ITEM_ID_BASE + 2, &start_time);    
    cui_inline_get_value(mmi_clndr_del_spec_child_gid, CUI_INLINE_ITEM_ID_BASE + 4, &end_date);
    cui_inline_get_value(mmi_clndr_del_spec_child_gid, CUI_INLINE_ITEM_ID_BASE + 5, &end_time);    
    g_tdl_cntx.search.u.duration[0].nYear = start_date.year;
    g_tdl_cntx.search.u.duration[0].nMonth = (U8)start_date.month;
    g_tdl_cntx.search.u.duration[0].nDay = (U8)start_date.day;
    g_tdl_cntx.search.u.duration[0].nHour = (U8)start_time.date_time.hour;
    g_tdl_cntx.search.u.duration[0].nMin = (U8)start_time.date_time.minute;
    g_tdl_cntx.search.u.duration[1].nYear = end_date.year;
    g_tdl_cntx.search.u.duration[1].nMonth = (U8)end_date.month;
    g_tdl_cntx.search.u.duration[1].nDay = (U8)end_date.day;
    g_tdl_cntx.search.u.duration[1].nHour = (U8)end_time.date_time.hour;
    g_tdl_cntx.search.u.duration[1].nMin = (U8)end_time.date_time.minute;
    
    /* check to time, from time must be less than to time */
    result = -(applib_dt_compare_time(
                    (applib_time_struct*)&g_tdl_cntx.search.u.duration[0],
                    (applib_time_struct*)&g_tdl_cntx.search.u.duration[1],
                    NULL));
                    
    if (result < 0)
    {
        memcpy(
            &g_tdl_cntx.search.u.duration[1],
            &g_tdl_cntx.search.u.duration[0],
            sizeof(MYTIME));
    }

    if (result >= 0)    /* To time is equal or greater than from time */
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    } 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_delete_group_proc
 * DESCRIPTION
 *  Exit function of task view all application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_clndr_delete_group_proc(mmi_event_struct *evt)
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
        case EVT_ID_CUI_INLINE_CSK_PRESS:
            mmi_clndr_delete_spec_time_confirm(GRP_ID_CAL_DELETE);
            break;
            
        case EVT_ID_CUI_INLINE_ABORT:
            mmi_frm_group_close(GRP_ID_CAL_DELETE);                    
            break;

        default:
            break;
    }
 
    return MMI_RET_OK;    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_list_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of to do list task list, store the index of selected task.
 * PARAMETERS
 *  nIndex      [IN]        Index of selected task.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_tdl_cntx.curr_selected = (U8)index;
    if(g_current_view_mode_context.current_mode == MMI_VIEW_MODE_DAILY)
    {
        g_tdl_cntx.curr_event_id = g_tdl_cntx.daily_search.event_buf[index].event_id;
        g_tdl_cntx.curr_source_id = g_tdl_cntx.daily_search.event_buf[index].source_id;
    }
    else if(g_current_view_mode_context.current_mode == MMI_VIEW_MODE_ALL)
    {
        g_tdl_cntx.curr_event_id = g_tdl_cntx.all_search.event_buf[index].event_id;
        g_tdl_cntx.curr_source_id = g_tdl_cntx.all_search.event_buf[index].source_id;
    }
    else
        ASSERT(0);
	
}


#define DAILY_LIST
/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_entry_daily_list
 * DESCRIPTION
 *  Entry function of calendar view all application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_entry_daily_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buff;
    U16 lsk_string = STR_GLOBAL_OPTIONS;
    S32 highlight_item = 0;
    U16 j;    
    mmi_cal_daily_scrn_info *scrn_data;
	srv_tdl_search_filter_struct search_info;
    S32 job_id;
    MMI_BOOL ret;
    U32 curr_event_id, curr_event_source;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_CAL_TRACE0(MMI_CAL_ENTRY_DAILLY_LIST);
    scrn_data = mmi_frm_scrn_get_user_data(GRP_ID_CAL_MAIN, SCR_TDL_CAL_DAILY_LIST);
    
    mmi_frm_send_incomplete_key_event_to_new_screen(MMI_TRUE);
    
    if (!mmi_frm_scrn_enter(
                    GRP_ID_CAL_MAIN,
                    SCR_TDL_CAL_DAILY_LIST,
                    mmi_clndr_exit_daily_list, 
                    mmi_clndr_entry_daily_list, 
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }
    mmi_frm_scrn_set_leave_proc(GRP_ID_CAL_MAIN, SCR_TDL_CAL_DAILY_LIST, mmi_clndr_list_leave_proc);
    
    g_current_view_mode_context.current_mode = MMI_VIEW_MODE_DAILY;
    gui_buff = mmi_frm_scrn_get_active_gui_buf();
    
    SetParentHandler(0);
    RegisterHighlightHandler(mmi_clndr_list_highlight_hdlr);
    
    ret = mmi_clndr_daily_event_list_update(scrn_data);
    
 SCREEN:   
    if((g_tdl_cntx.daily_search.state == MMI_CAL_EVENT_SEARCH_DONE_OK)&&
    !memcmp(&g_tdl_cntx.daily_search.date, &scrn_data->curr_date, 4))
    {
		g_tdl_cntx.sorted_event = g_tdl_cntx.daily_search.event_buf;
		if (g_tdl_cntx.daily_search.event_cnt == 0) /* Display <Empty> */
	    {    
	//        lsk_string = STR_GLOBAL_ADD;        
	        highlight_item = 0;
	    }
	    else /* Display list of event */
	    {
	        if (g_tdl_cntx.curr_option == TODO_LIST_TASK_OPTION_ADD && 
	            g_tdl_cntx.add_finish_flag)
	        {
	            
	            
	            gui_buff = NULL;
	            curr_event_id = g_tdl_cntx.curr_event_id;
	            curr_event_source = g_tdl_cntx.curr_source_id;       
                
	            for (j = 0; j < g_tdl_cntx.daily_search.event_cnt; j++)
	            {
	                if ((g_tdl_cntx.daily_search.event_buf[j].event_id == curr_event_id) &&
	                (g_tdl_cntx.daily_search.event_buf[j].source_id == curr_event_source))
	                {
	                    highlight_item = j;
	                    break;
	                }
	            }

	            g_tdl_cntx.curr_option = TODO_LIST_OPTION_TOTAL;
	            g_tdl_cntx.add_finish_flag =  MMI_FALSE;
	        }    
	    }
	}

    mmi_tdl_get_date_string(
                &scrn_data->curr_date,
                g_tdl_edit_cntx.title_buff,
                MMI_TDL_MAX_TITLE_BUF_SIZE * ENCODING_LENGTH);

    g_tdl_cntx.async_item_type = MMI_TDL_ASYNC_DAILY;
#ifdef __MMI_TOUCH_SCREEN__
    wgui_set_touch_title_bar_buttons();
    register_touch_button_handlers(
            mmi_clndr_previous_day_list, 
            NULL, 
            mmi_clndr_next_day_list,
            NULL);
    if (scrn_data->curr_date.nYear == CLNDR_END_YEAR 
        && scrn_data->curr_date.nMonth == 12 && scrn_data->curr_date.nDay == 31)
    {
        wgui_cat85_set_disable_arrowkey(WGUI_CAT85_DISABLE_RAR);
    }
    else if (scrn_data->curr_date.nYear == CLNDR_START_YEAR 
        && scrn_data->curr_date.nMonth == 1 && scrn_data->curr_date.nDay == 1)
    {
        wgui_cat85_set_disable_arrowkey(WGUI_CAT85_DISABLE_LAR);
    }
#endif /* __MMI_TOUCH_SCREEN__ */


    /* Only HVGA has toolbar for calendar daily view */
#if defined(__MMI_ICON_BAR_SUPPORT__) && defined(__MMI_MAINLCD_320X480__)
#if 0
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
#endif
#endif
    {
        mmi_clndr_setup_toolbar(MMI_VIEW_MODE_DAILY);
    }
#endif /* defined(__MMI_ICON_BAR_SUPPORT__) && defined(__MMI_MAINLCD_320X480__) */

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    if(ret && g_tdl_cntx.daily_search.state == MMI_CAL_EVENT_SEARCH_DONE_OK) // only compare the year,month,day 
    {
//#if 0
#ifdef __MMI_SNS_CALENDAR__			
	    ShowCategory85Screen(
	        (U8*)g_tdl_edit_cntx.title_buff,
	        GetRootTitleIcon(ORGANIZER_CALENDER_MENU),
	        lsk_string,
	        0,
	        STR_GLOBAL_BACK,
	        0,
	        g_tdl_cntx.daily_search.event_cnt,
	        mmi_clndr_get_async_items,
	        NULL,
	        highlight_item,
	        IMG_TODO_LIST_ICON_REMINDER,
            IMG_TODO_LIST_ICON_REMINDER,
	        IMG_TODO_LIST_ICON_ALARM,
	        gui_buff);    
#else
	    ShowCategory85Screen(
	        (U8*)g_tdl_edit_cntx.title_buff,
	        GetRootTitleIcon(ORGANIZER_CALENDER_MENU),
	        lsk_string,
	        0,
	        STR_GLOBAL_BACK,
	        0,
	        g_tdl_cntx.daily_search.event_cnt,
	        mmi_clndr_get_async_items,
	        NULL,
	        highlight_item,
	        IMG_TODO_LIST_ICON_REMINDER,
            IMG_TODO_LIST_ICON_REMINDER,
	        0,
	        gui_buff); 
#endif
//#endif 
		
	    if (g_tdl_cntx.daily_search.event_cnt == 0)
	    {
	        SetLeftSoftkeyFunction(mmi_clndr_entry_list_option, KEY_EVENT_UP);
	        SetCenterSoftkeyFunction(mmi_clndr_entry_list_option, KEY_EVENT_UP);    
	    }
	    else
	    {
#ifdef __MMI_TOUCH_SCREEN__
	        wgui_register_tap_callback(mmi_clndr_tap_list_callback);
#endif
	        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
	        SetLeftSoftkeyFunction(mmi_clndr_entry_list_option, KEY_EVENT_UP);
	        SetCenterSoftkeyFunction(mmi_clndr_entry_view_hdlr, KEY_EVENT_UP);
	    }
	    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
		SetKeyHandler(mmi_clndr_next_day_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	    SetKeyHandler(mmi_clndr_next_day_list, KEY_RIGHT_ARROW, KEY_EVENT_REPEAT);
		SetKeyHandler(mmi_clndr_previous_day_list, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	    SetKeyHandler(mmi_clndr_previous_day_list, KEY_LEFT_ARROW, KEY_EVENT_REPEAT);
#if 0
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
#endif
#endif
	    {
	        SetKeyHandler(mmi_clndr_swith_view_mode, KEY_POUND, KEY_EVENT_UP);
	        g_current_view_mode_context.current_mode = MMI_VIEW_MODE_DAILY;
	        mmi_clndr_set_swith_mode_flag(MMI_TRUE);
	    }
	    return;
    }
    // search daily event
    else if(g_tdl_cntx.daily_search.state == MMI_CAL_EVENT_SEARCH_DONE_ERR)
    {
		g_tdl_cntx.daily_search.state = MMI_CAL_EVENT_SEARCH_DONE_OK;
		 mmi_popup_display_simple(
	        (WCHAR*)(get_string(STR_GLOBAL_ERROR)), 
	        MMI_EVENT_FAILURE, 
	        GRP_ID_ROOT, 
	        NULL);
    }
    else
    {   
	    search_info.type = SRV_TDL_SEARCH_TYPE_DAILY;
	    memcpy(&search_info.u.date_time, &scrn_data->curr_date, sizeof(MYTIME));
		job_id = srv_tdl_event_search_begin(&search_info,SRV_TDL_EVENT_SORT_START_TIME,g_clndr_event_filter_select);
		if(job_id <= 0)
		{
		    memcpy(&g_tdl_cntx.daily_search.date, &scrn_data->curr_date, sizeof(MYTIME));
		    g_tdl_cntx.daily_search.state = MMI_CAL_EVENT_SEARCH_DONE_OK;
		    g_tdl_cntx.daily_search.event_cnt = 0;
		    ret = MMI_TRUE;
		    goto SCREEN;
		}
        else
        {
            memcpy(&g_tdl_cntx.daily_search.date, &scrn_data->curr_date, sizeof(MYTIME));
	        g_tdl_cntx.daily_search.search_id = job_id;
	        g_tdl_cntx.daily_search.state = MMI_CAL_EVENT_SEARCH_GOING;
	    }
	}
}

#define GLOBAL_FUNCTION
/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_event_close_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_event_close_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(GRP_ID_CAL_MAIN, SCR_TDL_CAL_DAILY_LIST);
    mmi_frm_scrn_close(GRP_ID_CAL_MAIN, SCR_TDL_CAL_ALL_LIST);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_entry_add_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_entry_add_hdlr(void)  /* All functions called this api should use CUI to revise, like this function. */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    MYTIME default_time;        
    mmi_cal_group_data_struct *group_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Hide options of adding task if the amount of todolist equals to max value */
    if (srv_tdl_is_full(SRV_TDL_VCAL_EVENT))
    {  
        mmi_popup_display_simple(
            (WCHAR*)(get_string(STR_ID_TDL_CAL_FULL)), 
            MMI_EVENT_FAILURE, 
            GRP_ID_ROOT, 
            NULL);
        return;
    }

    GetDateTime(&default_time);
    
    switch (g_current_view_mode_context.current_mode)
    {
        case MMI_VIEW_MODE_DAILY:
        {
            mmi_cal_daily_scrn_info *daily_scrn_data;
            daily_scrn_data = mmi_frm_scrn_get_user_data(GRP_ID_CAL_MAIN, SCR_TDL_CAL_DAILY_LIST);
            
            /* get the current time and keep the date */
            default_time.nYear = daily_scrn_data->curr_date.nYear;
            default_time.nMonth = daily_scrn_data->curr_date.nMonth;
            default_time.nDay = daily_scrn_data->curr_date.nDay;
            break;
        }
        case MMI_VIEW_MODE_ALL:
        {
            /* use today date */
            //GetDateTime(&default_time);
            break;
        }
        case MMI_VIEW_MODE_WEEK:
        {
            /* use current highlighted date */
            mmi_cal_main_scrn_info *main_scrn_data;
            main_scrn_data = mmi_frm_scrn_get_user_data(GRP_ID_CAL_MAIN, SCR_ID_CLNDR_SCREEN);
            //default_time = (MYTIME)main_scrn_data->highlight_time;
            memcpy(&default_time, &main_scrn_data->highlight_time, sizeof(MYTIME));
            break;
        }
        default:
        {
            /* use current highlighted date */
            mmi_cal_main_scrn_info *main_scrn_data;
            main_scrn_data = mmi_frm_scrn_get_user_data(GRP_ID_CAL_MAIN, SCR_ID_CLNDR_SCREEN);

            /* get the current time and keep the date */
            default_time.nYear = main_scrn_data->highlight_time.nYear;
            default_time.nMonth = main_scrn_data->highlight_time.nMonth;
            default_time.nDay = main_scrn_data->highlight_time.nDay;

            break;
        }
    }
    default_time.nMin = 0;
    default_time.nSec = 0;

    group_data = mmi_frm_group_get_user_data(GRP_ID_CAL_MAIN);
    group_data->cui_cal_save_gid = cui_cal_save_create(GRP_ID_CAL_MAIN);
    cui_cal_save_set_start_time(group_data->cui_cal_save_gid, &default_time);
    cui_cal_save_set_end_time(group_data->cui_cal_save_gid, &default_time);
    cui_cal_save_set_operation_type(group_data->cui_cal_save_gid, MMI_TDL_OP_TYPE_ADD);
    cui_cal_save_set_title(group_data->cui_cal_save_gid, STR_GLOBAL_ADD);
    cui_cal_save_run(group_data->cui_cal_save_gid);
}


#ifdef __MMI_SNS_CALENDAR__  
/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_event_filter_save_hdlr
 * DESCRIPTION
 *  Switch the status of highlighted item 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_clndr_event_filter_save_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//g_clndr_is_filter_changed = MMI_TRUE;
	mmi_clndr_reset_event_search_state();
    mmi_frm_scrn_close_active_id();
    
} 


static void mmi_tdl_filter_select_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_clndr_event_filter[index] == STR_ID_CLNDR_EVENT_SELECT_ALL)
	{
		g_clndr_event_filter_select = SRV_TDL_EVENT_SOURCE_TOTAL;
		return;
	}
	for(i = 0; i < SRV_TDL_EVENT_SOURCE_TOTAL; i++)
    {   
	    if(g_clndr_event_filter[index] == STR_ID_CLNDR_EVENT_LOCAL + i)
	    {
			g_clndr_event_filter_select = (srv_tdl_event_source_enum)i;
			return;
	    }
    }
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_entry_filter_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_entry_filter_hdlr(void)  /* All functions called this api should use CUI to revise, like this function. */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    U8 *gui_buffer = NULL;
    U8 i;
    U8 src_cnt = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!mmi_frm_scrn_enter(
        GRP_ID_CAL_MAIN, 
        SCR_ID_CLNDR_EVENT_FILTER,
        NULL,
        mmi_clndr_entry_filter_hdlr, 
        MMI_FRM_FULL_SCRN))
    {
        return;
    };
	gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_CAL_MAIN, SCR_ID_CLNDR_EVENT_FILTER);

    for(i = 0; i < SRV_TDL_EVENT_SOURCE_TOTAL; i++)
    {
        if(srv_tdl_has_source(i))
        {     
			g_clndr_event_filter[src_cnt] = STR_ID_CLNDR_EVENT_LOCAL + i;
	        src_cnt++;
	    }
    }
	g_clndr_event_filter[src_cnt] = STR_ID_CLNDR_EVENT_SELECT_ALL;
	src_cnt++;

    SetParentHandler(0);
    RegisterHighlightHandler(mmi_tdl_filter_select_highlight_hdlr);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory15Screen(
        STR_ID_CLNDR_EVENT_FILTER,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        src_cnt,
        g_clndr_event_filter,
        (U16*)gIndexIconsImageList,
        LIST_MENU,
        0,
        gui_buffer);
		

	SetLeftSoftkeyFunction(mmi_clndr_event_filter_save_hdlr, KEY_EVENT_UP);
	SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_clndr_event_filter_save_hdlr, KEY_EVENT_UP);
}
 
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_cal_event_search_check_relate_with_duration
 * DESCRIPTION
 *  Search the event list by specific duration.
 *  Including different cases
 *   1) Event starts before the duration and ends in it;
 *   2) Event starts in the duration and ends after it;
 *   3) Event starts and ends in the duration;
 *   4) Event starts before the duration and ends after it;
 *   5) Repeat ones.
 * PARAMETERS
 *  pevent :     [IN] The event to be checked.
 *  begin_time : [IN] The search condition.
 *                    The start time of the events in the searched list 
 *               should be later than begin_time.
 *  end_time :   [IN] The end time of the events shoud be 
 *               later than date_time.
 * RETURNS
 *  The check result of the operation.
 * RETURN VALUES
 *  MMI_TRUE : Check successfully.
 *  MMI_FALSE : Check failed.
 *****************************************************************************/ 
MMI_BOOL mmi_cal_event_search_check_relate_with_duration(
                const void *data, 
                const srv_tdl_vcal_enum vcal_type,
                const srv_tdl_search_filter_struct search_filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    srv_tdl_event_short_struct *pevent = (srv_tdl_event_short_struct*)data;
    MYTIME temp_start_time, temp_end_time;
    MYTIME duration_begin_time = search_filter.u.duration[0];
    MYTIME duration_end_time = search_filter.u.duration[1];    
    S32 ret1, ret2, ret3;    
    U32 dow_of_duration, dow_of_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: Add trace
    if (!pevent ||
        duration_begin_time.nYear == 0 || 
        duration_begin_time.nMonth == 0 || 
        duration_begin_time.nDay == 0 ||
        duration_end_time.nYear == 0 || 
        duration_end_time.nMonth == 0 || 
        duration_end_time.nDay == 0)
    {
        goto ERROR_CLEAN;
    }

    if (pevent->present)
    {
        /* 
         * Prepare for the repeat cases:
         * Make the start time have the same year, month and day, only check hour. 
         */
        memcpy(&temp_start_time, &pevent->start_time, sizeof(MYTIME));
        memcpy(&temp_end_time, &pevent->end_time, sizeof(MYTIME));
    
        temp_start_time.nYear = duration_begin_time.nYear;
        temp_start_time.nMonth = duration_begin_time.nMonth;
        temp_start_time.nDay = duration_begin_time.nDay;
        temp_start_time.DayIndex = duration_begin_time.DayIndex;
        
        temp_end_time.nYear = duration_end_time.nYear;
        temp_end_time.nMonth = duration_end_time.nMonth;
        temp_end_time.nDay = duration_end_time.nDay;
        temp_end_time.DayIndex = duration_end_time.DayIndex;
        
        switch (pevent->repeat.rule)
        {
            case MMI_TDL_RULE_ONCE:
            {
                /*
                 *   1) Event starts before the duration and ends in it;
                 *   2) Event starts in the duration and ends after it;
                 *   3) Event starts and ends in the duration;
                 *   4) Event starts before the duration and ends after it;
                 */
                ret1 = CompareTime(duration_begin_time, pevent->end_time, NULL);
                ret2 = CompareTime(pevent->start_time, duration_end_time, NULL);
                ret3 = CompareTime(pevent->start_time, pevent->end_time, NULL);
                if ((ret1 < 0 && ret2 < 0) || (ret1 == 0 && ret2 < 0 && ret3 == 0))
                {
                    result = MMI_TRUE;
                }
                break;
            }
            case MMI_TDL_RULE_DAILY:
            {
                /* Starts before the duration and daily repeat */
                if (CompareTime(pevent->start_time, duration_begin_time, NULL) <= 0)
                {                                        
                    /*
                     *   1) Event starts before the duration and ends in it;
                     *   2) Event starts in the duration and ends after it;
                     *   3) Event starts and ends in the duration;
                     *   4) Event starts before the duration and ends after it;
                     */
                    ret1 = CompareTime(duration_begin_time, temp_end_time, NULL);
                    ret2 = CompareTime(temp_start_time, duration_end_time, NULL);
                    ret3 = CompareTime(temp_start_time, temp_end_time, NULL);

                    if ((ret1 < 0 && ret2 < 0) || (ret1 == 0 && ret2 < 0 && ret3 == 0))
                    {
                        result = MMI_TRUE;
                    }
                }
                /* Starts in the duration */
                else if (CompareTime(duration_begin_time, pevent->start_time, NULL) < 0 &&
                         CompareTime(pevent->start_time, duration_end_time, NULL) < 0)
                {
                    result = MMI_TRUE;
                }
                break;
            }
            case MMI_TDL_RULE_DAYS:
            {                
                dow_of_duration = (S32)DOW(
                                    duration_begin_time.nYear,
                                    duration_begin_time.nMonth,
                                    duration_begin_time.nDay);
            
                /* Starts before the end of the duration and days repeat */
                if (CompareTime(pevent->start_time, duration_end_time, NULL) <= 0 &&
                    (pevent->repeat.dows & g_mmi_clndr_weekday_index[dow_of_duration]))
                {                    
                    /*
                     *   1) Event starts before the duration and ends in it;
                     *   2) Event starts in the duration and ends after it;
                     *   3) Event starts and ends in the duration;
                     *   4) Event starts before the duration and ends after it;
                     */
                    ret1 = CompareTime(duration_begin_time, temp_end_time, NULL);
                    ret2 = CompareTime(temp_start_time, duration_end_time, NULL);
                    ret3 = CompareTime(temp_start_time, temp_end_time, NULL);
                    
                    if ((ret1 < 0 && ret2 < 0) || (ret1 == 0 && ret2 < 0 && ret3 == 0))
                    {
                        result = MMI_TRUE;
                    }
                }
                break;
            }
            case MMI_TDL_RULE_WEEKLY:
            {
                dow_of_event = (S32)DOW(
                                    pevent->start_time.nYear,
                                    pevent->start_time.nMonth,
                                    pevent->start_time.nDay);
                dow_of_duration = (S32)DOW(
                                    duration_begin_time.nYear,
                                    duration_begin_time.nMonth,
                                    duration_begin_time.nDay);
            
                /* Starts before the end of the duration and dows are same */
                if ((dow_of_event == dow_of_duration) &&
                    CompareTime(pevent->start_time, duration_end_time, NULL) <= 0)
                {
                    /*
                     *   1) Event starts before the duration and ends in it;
                     *   2) Event starts in the duration and ends after it;
                     *   3) Event starts and ends in the duration;
                     *   4) Event starts before the duration and ends after it;
                     */
                    ret1 = CompareTime(duration_begin_time, temp_end_time, NULL);
                    ret2 = CompareTime(temp_start_time, duration_end_time, NULL);
                    ret3 = CompareTime(temp_start_time, temp_end_time, NULL);
                    
                    if ((ret1 < 0 && ret2 < 0) || (ret1 == 0 && ret2 < 0 && ret3 == 0))
                    {
                        result = MMI_TRUE;
                    }
                }
                break;
            }
            case MMI_TDL_RULE_MONTHLY:
            {
                if ((pevent->start_time.nDay == duration_end_time.nDay) &&
                    CompareTime(pevent->start_time, duration_end_time, NULL) <= 0)
                {
                    /*
                     *   1) Event starts before the duration and ends in it;
                     *   2) Event starts in the duration and ends after it;
                     *   3) Event starts and ends in the duration;
                     *   4) Event starts before the duration and ends after it;
                     */
                    ret1 = CompareTime(duration_begin_time, temp_end_time, NULL);
                    ret2 = CompareTime(temp_start_time, duration_end_time, NULL);
                    ret3 = CompareTime(temp_start_time, temp_end_time, NULL);
                    
                    if ((ret1 < 0 && ret2 < 0) || (ret1 == 0 && ret2 < 0 && ret3 == 0))
                    {
                        result = MMI_TRUE;
                    }                
                }            
                break;
            }
            case MMI_TDL_RULE_YEARLY:
            {
                if ((pevent->start_time.nDay == duration_end_time.nDay) &&
                    (pevent->start_time.nMonth == duration_end_time.nMonth) &&
                    CompareTime(pevent->start_time, duration_end_time, NULL) <= 0)
                {
                    /*
                     *   1) Event starts before the duration and ends in it;
                     *   2) Event starts in the duration and ends after it;
                     *   3) Event starts and ends in the duration;
                     *   4) Event starts before the duration and ends after it;
                     */
                    ret1 = CompareTime(duration_begin_time, temp_end_time, NULL);
                    ret2 = CompareTime(temp_start_time, duration_end_time, NULL);
                    ret3 = CompareTime(temp_start_time, temp_end_time, NULL);
                    
                    if ((ret1 < 0 && ret2 < 0) || (ret1 == 0 && ret2 < 0 && ret3 == 0))
                    {
                        result = MMI_TRUE;
                    }                
                }                        
                break;
            }
            // TODO: Add code for Tithi (Ask indian for co-work)
            default:
                break;
        }
    }
        
ERROR_CLEAN:   
    return result;    

}                


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_show_daily_event
 * DESCRIPTION
 *  Display to do list task of selected date.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_show_daily_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cal_daily_scrn_info *scrn_data = OslMalloc(sizeof(mmi_cal_daily_scrn_info));
    mmi_cal_main_scrn_info *main_scrn_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_CAL_TRACE0(MMI_CAL_SHOW_DAILY_LIST);
    main_scrn_data = mmi_frm_scrn_get_user_data(GRP_ID_CAL_MAIN, SCR_ID_CLNDR_SCREEN);
    memcpy(&scrn_data->curr_date, &main_scrn_data->highlight_time, sizeof(MYTIME));        
    mmi_frm_scrn_first_enter(GRP_ID_CAL_MAIN, SCR_TDL_CAL_DAILY_LIST, mmi_clndr_entry_daily_list, scrn_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_daily_pre_entry_screen
 * DESCRIPTION
 *  Display to do list task of selected date.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_daily_pre_entry_screen(MYTIME* date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cal_daily_scrn_info *scrn_data = OslMalloc(sizeof(mmi_cal_daily_scrn_info));
    memcpy(&scrn_data->curr_date, date, sizeof(MYTIME));
    mmi_frm_scrn_first_enter((mmi_id)GRP_ID_CAL_MAIN, SCR_TDL_CAL_DAILY_LIST, mmi_clndr_entry_daily_list, scrn_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_all_pre_entry_screen
 * DESCRIPTION
 *  Display to do list task of selected date.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_all_pre_entry_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_first_enter(GRP_ID_CAL_MAIN, SCR_TDL_CAL_ALL_LIST, mmi_clndr_entry_all_list, NULL);
    if (g_current_view_mode_context.switch_setting_flag)
    {
        mmi_frm_scrn_close(GRP_ID_CAL_MAIN, SCR_TDL_CAL_DAILY_LIST);
    }        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_previous_day_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_previous_day_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cal_daily_scrn_info *old_scrn_data;
    mmi_cal_daily_scrn_info *new_scrn_data = OslMalloc(sizeof(mmi_cal_daily_scrn_info));
    MYTIME decrement_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_scrn_data = mmi_frm_scrn_get_user_data(GRP_ID_CAL_MAIN, SCR_TDL_CAL_DAILY_LIST);
    
    /* Check date */
    if (old_scrn_data->curr_date.nMonth == 1 && 
        old_scrn_data->curr_date.nDay == 1 &&
        old_scrn_data->curr_date.nYear == CLNDR_START_YEAR)
    {
         mmi_popup_display_simple((WCHAR*)((UI_string_type)GetString(STR_CLNDR_OUT_OF_CALENDAR)), MMI_EVENT_FAILURE, GRP_ID_CAL_MAIN, NULL);
        return;
    }

    /* Update Date */
    memset(&decrement_time, 0, sizeof(MYTIME));
    decrement_time.nDay = 1;
    
    DecrementTime(old_scrn_data->curr_date, decrement_time, &old_scrn_data->curr_date);
    memcpy(new_scrn_data, old_scrn_data, sizeof(mmi_cal_daily_scrn_info));
    
    if (!mmi_frm_scrn_enter(GRP_ID_CAL_MAIN, SCR_ID_DUMMY, NULL, NULL, MMI_FRM_FULL_SCRN))
        return;
    mmi_frm_scrn_close(GRP_ID_CAL_MAIN, SCR_TDL_CAL_DAILY_LIST);
    mmi_frm_scrn_first_enter(
                    GRP_ID_CAL_MAIN, 
                    SCR_TDL_CAL_DAILY_LIST, 
                    mmi_clndr_entry_daily_list,
                    new_scrn_data);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_entry_all_list
 * DESCRIPTION
 *  Entry function of calendar view all application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_entry_all_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buff;
    U16 lsk_string = STR_GLOBAL_OPTIONS;
    S32 highlight_item = 0;
    U16 j;
    srv_tdl_search_filter_struct search_info;
    S32 job_id;
    U32 curr_event_id, curr_event_source;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (!mmi_frm_scrn_enter(
                    GRP_ID_CAL_MAIN,
                    SCR_TDL_CAL_ALL_LIST,
                    NULL, 
                    mmi_clndr_entry_all_list, 
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }
    
    g_tdl_cntx.async_item_type = MMI_TDL_ASYNC_ALL;
    g_current_view_mode_context.current_mode = MMI_VIEW_MODE_ALL;
    
    gui_buff = mmi_frm_scrn_get_active_gui_buf();
    SetParentHandler(0);
    RegisterHighlightHandler(mmi_clndr_list_highlight_hdlr);
    mmi_frm_scrn_set_leave_proc(
                    GRP_ID_CAL_MAIN,
                    SCR_TDL_CAL_ALL_LIST,
                    mmi_clndr_list_leave_proc);

SCREEN:
    if(g_tdl_cntx.all_search.state == MMI_CAL_EVENT_SEARCH_DONE_OK)
    {
		g_tdl_cntx.sorted_event = g_tdl_cntx.all_search.event_buf;
	    if (g_tdl_cntx.all_search.event_cnt == 0) /* Display <Empty> */
	    {    
	//        lsk_string = STR_GLOBAL_ADD;        
	        highlight_item = 0;       	
	    }
	    else /* display list of task */
	    {
	        /* after add new event, should highlight the new one when goback to event list */
	        if (g_tdl_cntx.curr_option == TODO_LIST_TASK_OPTION_ADD && g_tdl_cntx.add_finish_flag)
	        {
	            gui_buff = NULL;

	            curr_event_id = g_tdl_cntx.curr_event_id;
	            curr_event_source = g_tdl_cntx.curr_source_id;

	            for (j = 0; j < g_tdl_cntx.all_search.event_cnt; j++)
	            {
	                if ((g_tdl_cntx.all_search.event_buf[j].event_id == curr_event_id) &&
	                (g_tdl_cntx.all_search.event_buf[j].source_id == curr_event_source))
	                {
	                    highlight_item = j;
	                    break;
	                }
	            }
	            g_tdl_cntx.curr_option = TODO_LIST_OPTION_TOTAL;
	            g_tdl_cntx.add_finish_flag =  MMI_FALSE;
	        }    
	    }
    }
    mmi_ucs2ncpy(g_tdl_edit_cntx.title_buff, 
                 GetString(STR_ID_TDL_EVENTS), 
                 MMI_TDL_MAX_TITLE_BUF_SIZE - 1);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    if(g_tdl_cntx.all_search.state == MMI_CAL_EVENT_SEARCH_DONE_OK)
    {
#ifdef __MMI_SNS_CALENDAR__			
	    ShowCategory85Screen(
	        (U8*)g_tdl_edit_cntx.title_buff,
	        GetRootTitleIcon(ORGANIZER_CALENDER_MENU),
	        lsk_string,
	        0,
	        STR_GLOBAL_BACK,
	        0,
	        g_tdl_cntx.all_search.event_cnt,
	        mmi_clndr_get_async_items,
	        NULL,
	        highlight_item,
	        IMG_TODO_LIST_ICON_REMINDER,
            IMG_TODO_LIST_ICON_REMINDER,
	        IMG_TODO_LIST_ICON_ALARM,
	        gui_buff);
#else
	    ShowCategory85Screen(
	        (U8*)g_tdl_edit_cntx.title_buff,
	        GetRootTitleIcon(ORGANIZER_CALENDER_MENU),
	        lsk_string,
	        0,
	        STR_GLOBAL_BACK,
	        0,
	        g_tdl_cntx.all_search.event_cnt,
	        mmi_clndr_get_async_items,
	        NULL,
	        highlight_item,
	        IMG_TODO_LIST_ICON_REMINDER,
            IMG_TODO_LIST_ICON_REMINDER,
	        0,
	        gui_buff);
#endif
	    //SetDelScrnIDCallbackHandler(
	    //           SCR_TDL_CAL_ALL_LIST, 
	    //           (HistoryDelCBPtr)mmi_tdl_task_main_leave_proc); // TODO: Use its owner leave proc for screen group

	    if (g_tdl_cntx.all_search.event_cnt == 0)
	    {
	        SetLeftSoftkeyFunction(mmi_clndr_entry_list_option, KEY_EVENT_UP);
	        SetCenterSoftkeyFunction(mmi_clndr_entry_list_option, KEY_EVENT_UP);
	    }
	    else
	    {
	    #ifdef __MMI_TOUCH_SCREEN__
	        wgui_register_tap_callback(mmi_clndr_tap_list_callback);
	    #endif
	        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
	        SetLeftSoftkeyFunction(mmi_clndr_entry_list_option, KEY_EVENT_UP);
	        SetCenterSoftkeyFunction(mmi_clndr_entry_view_hdlr, KEY_EVENT_UP);
	    }

	    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	    SetKeyHandler(mmi_clndr_swith_view_mode, KEY_POUND, KEY_EVENT_UP);
	    return;
    }
    // search all event
    else if(g_tdl_cntx.all_search.state == MMI_CAL_EVENT_SEARCH_DONE_ERR)
    {
		g_tdl_cntx.all_search.state = MMI_CAL_EVENT_SEARCH_DONE_OK;
		 mmi_popup_display_simple(
	        (WCHAR*)(get_string(STR_GLOBAL_ERROR)), 
	        MMI_EVENT_FAILURE, 
	        GRP_ID_ROOT, 
	        NULL);
    }
    else
    {
	    search_info.type = SRV_TDL_SEARCH_TYPE_ALL;
		job_id = srv_tdl_event_search_begin(&search_info,SRV_TDL_EVENT_SORT_START_TIME, g_clndr_event_filter_select);
		if(job_id <= 0)   // no event source
		{
		    g_tdl_cntx.all_search.state = MMI_CAL_EVENT_SEARCH_DONE_OK;
		    g_tdl_cntx.all_search.event_cnt = 0;
		    goto SCREEN;
		}
        else
        {
	        g_tdl_cntx.all_search.search_id = job_id;        
	        g_tdl_cntx.all_search.state = MMI_CAL_EVENT_SEARCH_GOING;	        
	    }
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_entry_spec_time
 * DESCRIPTION
 *  Delete spec time events.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_entry_spec_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cal_main_scrn_info *scrn_data;    
    cui_inline_struct inline_data;
    cui_inline_item_date_time_struct start_date, end_date;
    cui_inline_item_time_struct start_time, end_time;
    cui_inline_item_softkey_struct softkey;
    MYTIME curr_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    softkey.softkey[MMI_LEFT_SOFTKEY].string_id = STR_GLOBAL_OK;
    softkey.softkey[MMI_LEFT_SOFTKEY].image_id = CUI_INLINE_SOFTKEY_DEFAULT_VALUE;
    softkey.softkey[MMI_RIGHT_SOFTKEY].string_id = CUI_INLINE_SOFTKEY_DEFAULT_VALUE;
    softkey.softkey[MMI_RIGHT_SOFTKEY].image_id = CUI_INLINE_SOFTKEY_DEFAULT_VALUE;
    softkey.softkey[MMI_CENTER_SOFTKEY].string_id = CUI_INLINE_SOFTKEY_DEFAULT_VALUE;
    softkey.softkey[MMI_CENTER_SOFTKEY].image_id = CUI_INLINE_SOFTKEY_DEFAULT_VALUE;
    scrn_data = (mmi_cal_main_scrn_info*)mmi_frm_scrn_get_user_data(
                                                       GRP_ID_CAL_MAIN, 
                                                       SCR_ID_CLNDR_SCREEN);
    g_tdl_cntx.vcal_filter = SRV_TDL_VCAL_EVENT;
    mmi_tdl_set_context_date((MYTIME *)&scrn_data->highlight_time);

    mmi_frm_group_create_ex(
            GRP_ID_CAL_MAIN,
            GRP_ID_CAL_DELETE, 
            mmi_clndr_delete_group_proc,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);

    inline_data.items_count = 6;
    inline_data.title = STR_ID_CLNDR_DELETE_SPEC_PERIOD;
    inline_data.title_icon = GetRootTitleIcon(ORGANIZER_CALENDER_MENU);
    inline_data.screen_flag = CUI_INLINE_SCREEN_DEFAULT_TEXT  | CUI_INLINE_SCREEN_DISABLE_DONE;
    inline_data.softkey = &softkey;
    inline_data.items = cui_delete_spec_time;
    mmi_clndr_del_spec_child_gid = cui_inline_create(GRP_ID_CAL_DELETE, &inline_data);
    
    if (mmi_clndr_del_spec_child_gid != GRP_ID_INVALID)
    {        
        start_date.year = scrn_data->highlight_time.nYear;
        start_date.month = scrn_data->highlight_time.nMonth;
        start_date.day = scrn_data->highlight_time.nDay;
        if (g_current_view_mode_context.current_mode == MMI_VIEW_MODE_WEEK)
        {
            start_time.date_time.hour = scrn_data->highlight_time.nHour;
            start_time.date_time.minute = scrn_data->highlight_time.nMin;
            
        }
        else
        {
            GetDateTime(&curr_time);
            start_time.date_time.hour = curr_time.nHour;
            start_time.date_time.minute = curr_time.nMin;
        }
        start_time.date_time.second = 0;
        memcpy(&end_date, &start_date, sizeof(cui_inline_item_date_time_struct));
        memcpy(&end_time, &start_time, sizeof(cui_inline_item_time_struct));

        cui_inline_set_value(
                mmi_clndr_del_spec_child_gid, 
                CUI_INLINE_ITEM_ID_BASE + 1, 
                &start_date);
        cui_inline_set_value(
                mmi_clndr_del_spec_child_gid, 
                CUI_INLINE_ITEM_ID_BASE + 2, 
                &start_time);
                
        cui_inline_set_value(
                mmi_clndr_del_spec_child_gid, 
                CUI_INLINE_ITEM_ID_BASE + 4, 
                &end_date);
        cui_inline_set_value(
                mmi_clndr_del_spec_child_gid, 
                CUI_INLINE_ITEM_ID_BASE + 5, 
                &end_time);                        
        cui_inline_run(mmi_clndr_del_spec_child_gid);
    }
    else
    {
        mmi_frm_group_close(GRP_ID_CAL_DELETE);
    }
}


mmi_ret mmi_clndr_search_callback_handler(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                 */
    /*----------------------------------------------------------------*/
    srv_tdl_search_callback_struct *reset_struct = (srv_tdl_search_callback_struct*)param;
    //mmi_cal_daily_scrn_info *scrn_data;	
    //U32 return_cnt;
    srv_tdl_event_id_struct *temp_p = NULL;
    int i;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_CAL_TRACE3(MMI_CAL_SEARCH_CALLBACK_HANDLER, reset_struct->job_id, reset_struct->event_cnt, g_current_view_mode_context.current_mode);

    //scrn_data = mmi_frm_scrn_get_user_data(GRP_ID_CAL_MAIN, SCR_TDL_CAL_DAILY_LIST);
    if(reset_struct->event_cnt > 0 && reset_struct->success)
    {
		temp_p = (srv_tdl_event_id_struct *)OslMalloc(reset_struct->event_cnt * sizeof(srv_tdl_event_id_struct));
		srv_tdl_event_search_get(
		                     reset_struct->job_id, 
		                     temp_p, 
                             reset_struct->event_cnt * sizeof(srv_tdl_event_id_struct), 
                             0);                                
    }
    srv_tdl_event_search_end(reset_struct->job_id);
	
    g_tdl_cntx.sorted_event = temp_p;
    g_tdl_cntx.total = reset_struct->event_cnt;
            
    if(g_tdl_cntx.daily_search.search_id == reset_struct->job_id)
	{
		// daily view
		g_tdl_cntx.daily_search.search_id = 0;
		g_tdl_cntx.daily_search.event_cnt = reset_struct->event_cnt;
		ASSERT(!g_tdl_cntx.daily_search.event_buf);
		g_tdl_cntx.daily_search.event_buf = temp_p;
		if(reset_struct->success)
		{
		    g_tdl_cntx.daily_search.state = MMI_CAL_EVENT_SEARCH_DONE_OK;
		}
		else
		{
			g_tdl_cntx.daily_search.state = MMI_CAL_EVENT_SEARCH_DONE_ERR;
		}
		mmi_frm_display_dummy_screen();
		mmi_frm_scrn_close_active_id();
	}
    else if(g_tdl_cntx.monthly_search.search_id == reset_struct->job_id)
    {
		// monthly view
		g_tdl_cntx.monthly_search.search_id = 0;
		g_tdl_cntx.monthly_search.event_cnt = reset_struct->event_cnt;
		ASSERT(!g_tdl_cntx.monthly_search.event_buf);
		g_tdl_cntx.monthly_search.event_buf = temp_p;
		if(reset_struct->success)
		{
		    g_tdl_cntx.monthly_search.state = MMI_CAL_EVENT_SEARCH_DONE_OK;
		}
		else
		{
		    g_tdl_cntx.monthly_search.state = MMI_CAL_EVENT_SEARCH_DONE_ERR;
		}
		wgui_cat83_refresh_events_reminder();
    }
	else if(g_tdl_cntx.all_search.search_id == reset_struct->job_id)
	{
		// all list
		g_tdl_cntx.all_search.search_id = 0;
		g_tdl_cntx.all_search.event_cnt = reset_struct->event_cnt;
		ASSERT(!g_tdl_cntx.all_search.event_buf);
		g_tdl_cntx.all_search.event_buf = temp_p;
		if(reset_struct->success)
		{
			g_tdl_cntx.all_search.state = MMI_CAL_EVENT_SEARCH_DONE_OK;
		}
		else
		{
			g_tdl_cntx.all_search.state = MMI_CAL_EVENT_SEARCH_DONE_ERR;
		}
		mmi_frm_display_dummy_screen();
		mmi_frm_scrn_close_active_id();
	}
    else if(g_tdl_cntx.special_search.search_id == reset_struct->job_id)
    {
		// search list
		g_tdl_cntx.special_search.search_id = 0;
		g_tdl_cntx.special_search.event_cnt = reset_struct->event_cnt;
		ASSERT(!g_tdl_cntx.special_search.event_buf);
		g_tdl_cntx.special_search.event_buf = temp_p;
		if(reset_struct->success)
		{
		    g_tdl_cntx.special_search.state = MMI_CAL_EVENT_SEARCH_DONE_OK;
		}
		else
		{
		    g_tdl_cntx.special_search.state = MMI_CAL_EVENT_SEARCH_DONE_ERR;
		}
		mmi_frm_display_dummy_screen();
		mmi_frm_scrn_close_active_id();
    }
	else
	{
		// weekly view
		for(i = 0; i < 7; i++)
		{
		   if(g_tdl_cntx.weekly_search[i].search_id == reset_struct->job_id)
		   {
				g_tdl_cntx.weekly_search[i].search_id = 0;
				g_tdl_cntx.weekly_search[i].event_cnt = reset_struct->event_cnt;
				ASSERT(!g_tdl_cntx.weekly_search[i].event_buf);
				g_tdl_cntx.weekly_search[i].event_buf = temp_p;
			    if(reset_struct->success)
				{
				    g_tdl_cntx.weekly_search[i].state = MMI_CAL_EVENT_SEARCH_DONE_OK;
				}
				else
				{
				    g_tdl_cntx.weekly_search[i].state = MMI_CAL_EVENT_SEARCH_DONE_ERR;
				}
				g_tdl_cntx.weekly_search_cnt--;
		        break;
		   }
		   
		}
		if(i >= 7)
		{
			// useless search callback
			if(temp_p)
			{
				OslMfree(temp_p);
			}
		}
		if(g_tdl_cntx.weekly_search_cnt == 0)
		{
			wgui_cat83_refresh_events_reminder();
		}
	}

	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_event_op_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_clndr_event_op_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tdl_event_op_struct *op_evt = NULL;
    srv_tdl_event_struct *pevent = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (evt->evt_id != EVT_ID_SRV_TDL_EVENT_OP)
    {
        return MMI_RET_OK;
    }
    
    op_evt = (srv_tdl_event_op_struct *)evt;

	if(op_evt->source_id == SRV_TDL_EVENT_SOURCE_LOCAL)
 	{
		srv_tdl_get_cache(
			(void*)&pevent, 
			sizeof(srv_tdl_event_short_struct), 
			SRV_TDL_VCAL_EVENT,
			op_evt->event_id);
 	}
	else
	{
//		 pevent = (srv_tdl_event_struct *)OslMalloc(sizeof(srv_tdl_event_struct));	
//		 srv_tdl_event_get(
//			 pevent, 
//			 sizeof(srv_tdl_event_struct),
//			 op_evt->source_id,
//			 op_evt->event_id); 
	}

    switch(op_evt->op_type)
    {
        case SRV_TDL_OP_ADD:
        case SRV_TDL_OP_UPDATE:
        case SRV_TDL_OP_DELETE:  
			//mmi_clndr_reset_event_search_state();
		if(g_is_entry_search_op == KAL_TRUE)
			mmi_clndr_reset_event_search_state_exclude_all_search();
		else
			mmi_clndr_reset_event_search_state();//View all中的操作，还是保留原始的清除动作；
            break;
            
        default:
            break;
    }

	if(op_evt->source_id == SRV_TDL_EVENT_SOURCE_LOCAL)
	{
	    switch(op_evt->op_type)
	    {
	        case SRV_TDL_OP_ADD:
	            if(pevent->alarm.type > MMI_TDL_ALARM_OFF)
	            {
					mmi_tdl_set_reminder(
						SRV_TDL_VCAL_EVENT,
	                    (void*)pevent, 
	                    op_evt->event_id);
	            }
	            break;
	            
	        case SRV_TDL_OP_UPDATE:
	            srv_reminder_cancel(
	                SRV_REMINDER_TYPE_CAL, 
	                op_evt->event_id);
	            if(pevent->alarm.type > MMI_TDL_ALARM_OFF)
	            {
	                mmi_tdl_set_reminder(
						SRV_TDL_VCAL_EVENT,
	                    (void*)pevent, 
	                    op_evt->event_id);
	            }
	            break;
	            
	        case SRV_TDL_OP_DELETE:  
	            srv_reminder_cancel(
	                SRV_REMINDER_TYPE_CAL, 
	                op_evt->event_id);
	            break;
	            
	        default:
	            break;
	    }

		//update the current content if necessary
		if(g_tdl_cntx.curr_event.event_id == op_evt->event_id &&
			g_tdl_cntx.curr_event.src_id == SRV_TDL_EVENT_SOURCE_LOCAL)
		{
			srv_tdl_event_get(
				 &g_tdl_cntx.curr_event, 
				 sizeof(srv_tdl_event_struct),
				 SRV_TDL_EVENT_SOURCE_LOCAL,
				 op_evt->event_id); 
		}
	}
	if(op_evt->source_id != SRV_TDL_EVENT_SOURCE_LOCAL)
	{
 //       OslMfree(pevent);
	}
    return MMI_RET_OK;
}

#endif /* __MMI_CALENDAR__ */


