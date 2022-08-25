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
 * HijriCalendarProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file contains the source code for Hijri Calendar implementation.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#ifndef HIJRI_CALENDAR_PROTS_H

#define HIJRI_CALENDAR_PROTS_H

//RHR add begin

#include "MMI_features.h"
#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
#include "gui_data_types.h"
#include "CalendarProt.h" 
#include "kal_general_types.h"
    
//RHR add end

extern void mmi_hijri_highlight_hijri_main_menu(void);
extern void mmi_hijri_highlight_day_details(void);
extern void mmi_hijri_highlight_hijri_festivals(void);
extern void mmi_hijri_highlight_date_correction(void);
//extern void mmi_hijri_highlight_send_date(void);
extern void mmi_hijri_highlight_send_by_SMS(void);
#ifdef __MMI_MMS__
extern void mmi_hijri_highlight_send_by_MMS(void);
#endif /* __MMI_MMS__ */
#ifdef __MMI_EMAIL__
extern void mmi_hijri_highlight_send_by_Email(void);
#endif
/*extern void mmi_hijri_highlight_festival_detail(void);*/
/*extern void mmi_hijri_highlight_next_occurence(void);*/
extern void mmi_hijri_highlight_add_reminder_for_festivals(void); /*  changed the name */
extern void mmi_hijri_highlight_jump_to_year(void);
extern void mmi_hijri_entry_main_menu(void);
extern void mmi_hijri_entry_day_details(void);
extern void mmi_hijri_pre_entry_festival_list(void);
extern void mmi_hijri_entry_festival_list(void);
extern void mmi_hijri_entry_date_correction(void);
extern void mmi_hijri_entry_send_date(void);
extern void mmi_hijri_send_by_SMS(void);
#ifdef __MMI_MMS__
extern void mmi_hijri_send_by_MMS(void);
#endif /* #ifdef __MMI_MMS__ */
extern void mmi_hijri_send_by_Email(void);
extern void mmi_hijri_entry_festival_detail(void);
extern void mmi_hijri_entry_next_occurence(void);
extern void mmi_hijri_entry_jump_to_year(void);
extern void mmi_hijri_highlighted_index(S32 index);
extern void mmi_hijri_make_detail_string(void);
extern U16 mmi_hijri_days_in_year(U16 year);
extern U16 mmi_hijri_convert_date_to_days(MYTIME date);
extern void mmi_hijri_add_correction(void);
extern pBOOL mmi_hijri_get_festival_names(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern S32 mmi_hijri_get_festival_dates(S32 item_index, UI_string_type *hint_array);
extern U16 mmi_hijri_get_fest_str_id(U8 index);
extern void mmi_hijri_get_festivals(void);
/*extern void mmi_hijri_verify_year(void);*/
extern U16 mmi_hijri_get_fest_detail_str_id(U8 index);
extern void mmi_hijri_pre_entry_jump_to_year(void);
extern void mmi_hijri_get_hijri_date_str(
        MYTIME curr_time,
        UI_string_type str_hijri_date1,
        UI_string_type str_hijri_date2);
extern S8 *mmi_hijri_get_hijri_date_string(void);
extern void mmi_hijri_fest_list_options(void);
extern void mmi_hijri_highlight_festival_options(void);
extern void mmi_hijri_go_back_to_main_menu(void);
//extern U8 mmi_hijri_adjust_month_days_for_leap_year(U16 year);, U8 month);
extern void mmi_hijri_adjust_base_date(void);
extern MMI_BOOL mmi_hijri_monthly_out_of_boundary(MYTIME *currDate, MMI_BOOL show_popup);
extern void mmi_hijri_pre_entry_main_menu(void);
extern U8 mmi_hijri_num_days_in_month(U8 month, U16 year);
extern mmi_ret mmi_hijri_init(mmi_event_struct *evt);
/* extern U16 mmi_hijri_get_hijri_year(MYTIME time);*/
extern void mmi_hijri_pre_entry_next_occurence(void);
extern void mmi_hijri_date_correction_set_hilite_index(U16 index);

extern void mmi_hijri_entry_day_details_options(void); /* ENTRY FUNCTION FOR DAY DETAILS OPTIONS */
extern void mmi_hijri_highlight_send_date(void); /* highlight handler for send date option */
extern void mmi_hijri_highlight_go_to_calendar_day_details(void);	/* highlight handler for go to calendar from day details option */
extern void mmi_hijri_decrement_day_details(void);		/* LNK functionality on day details screen */
extern void mmi_hijri_increment_day_details(void);		/* RNK functionality on day details screen */
extern void mmi_hijri_pre_entry_day_details(void);	/* pre entry function for hijri day details */
extern U8 mmi_hijri_get_date_str(MYTIME curr_time, U8* title); /* this function fille the title string for calendar main screen */
extern void mmi_hijri_go_to_calendar_day_details(void); /* handler function for LSK on go to calendar menu option from day details */ 
extern void mmi_hijri_entry_add_reminder_for_festivals(void);
extern void mmi_hijri_highlight_add_reminder_day_details(void);		/* highlight handler for add reminder from day details option */

#ifdef __MMI_TODOLIST__
extern void mmi_hijri_pre_entry_add_reminder_for_hijri(void); /* LSK handler function for add reminder via day details */
extern void mmi_hijri_entry_add_reminder_for_hijri_date(void);		/* add reminder function for hijri day details */
extern void mmi_hijri_pre_entry_add_reminder_for_festivals(void);
extern void mmi_hijri_get_reminder_date(MYTIME *time);
extern void mmi_hijri_get_reminder_name(U8* str_buff);
extern int mmi_hijri_is_hijri_reminder(void);
#endif /* __MMI_TODOLIST__ */

extern void mmi_hijri_highlight_go_to_calendar_festivals(void);
extern void mmi_hijri_go_to_calendar_festivals(void);
extern void mmi_hijri_fill_festival_date_and_day(CHAR *ucs2_data_fest, U8 index);
extern U16 mmi_hijri_get_string_id_of_day_from_date(CHAR *date);	/* to return the day of week from the date string */
extern void mmi_hijri_decrement_festival(void);			/* to show the details of the prev festival in the list */
extern void mmi_hijri_increment_festival(void);			/* to show the details of the next festival in the list */
extern pBOOL mmi_hijri_check_max_festival_limit(S32 index);	/* to check if the max festival limit has been reached or not */
extern S32 mmi_hijri_max_festival_in_current_festival_list(void); /* returns the number of festivals in the current festival list */
extern void mmi_hijri_get_date_from_festival_date_string(MYTIME* date);	/* to get date in MYTIME structure from fest date string. */
extern void mmi_hijri_get_list_of_festival_icons(MYTIME clndr_time, mmi_clndr_cell_struct *daily_task_info);  /* for fetching the icons of festival */
extern void mmi_hijri_go_back_to_calendar_options_screen(void);
extern void mmi_hijri_date_display_set_display_key_handler(void);
extern void mmi_hijri_festival_display_set_display_key_handler(void);
extern void mmi_hijri_prepare_fest_detail_string(void);
#ifdef __MMI_BASIC_UI_STYLE__
extern S32 mmi_hijri_get_festival_names_ext(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size);
#endif
#endif
