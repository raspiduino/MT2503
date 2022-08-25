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
 *  IndianCalendarProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contains the function prototype declaration for the 
 *  Indian Calendar Application.
 *
 * Author:
 * -------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#ifndef INDICAL_PROTS_H

#define INDICAL_PROTS_H

#include "IndianCalendarDef.h"
#include "CalendarProt.h"

//RHR add begin

#include "MMI_features.h"
#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
//#include "kal_general_types.h"
#include "gui_data_types.h"
    
//RHR add end

extern void HighlightIndiCalTithiMenu(void);
extern void HighlightIndiCalFestivalListMenu(void);

extern void HighlightIndiCalSendTithiAsSMS(void);

extern void HighlightIndiCalSendTithi(void);
#ifdef __MMI_MMS__
extern void HighlightIndiCalSendTithiAsMMS(void);
#endif /* __MMI_MMS__ */
#ifdef __MMI_EMAIL__
extern void HighlightIndiCalSendTithiAsEMAIL(void);
#endif /* __MMI_EMAIL__ */

extern void mmi_indical_pre_entry_tithi_display(void);
extern void mmi_indical_tithi_display(void);
extern void mmi_indical_festival_list_display(void);
extern void mmi_indical_tithi_option_menu_display(void);
extern void mmi_indical_festival_option_menu_display(void);
extern void mmi_indical_festival_details_display(void);
extern void mmi_indical_send_tithi_as_SMS(void);
extern void mmi_indical_prepare_date_string(void);
/*-------------------------------- APIs ------------------------------------*/

extern void mmi_indical_get_festival_date(void);
extern U16 mmi_indical_get_festival_str_id(U8);
extern void mmi_indical_set_highlight_index(S32);
extern U16 mmi_indical_get_tithi_str_id(U8, U8);
extern void mmi_indical_get_indian_date_str(MYTIME curr_time, U8 *, U8 *);
extern U16 mmi_indical_get_paksha_strid(U8 nPaksha);
extern U16 mmi_indical_get_short_paksha_strid(U8 nPaksha);
extern U16 mmi_indical_get_short_adhika_strid(S16 nAdhikaMonth);
extern U16 mmi_indical_get_adhika_strid(U8 nAdhikaMonth);
extern U16 mmi_indical_get_month_strid(U8 nIndianMonth);
extern U16 mmi_indical_get_weekday_strid(U8 nWeekDay);
extern CHAR *mmi_indical_get_indian_date_string(void);
extern U16 mmi_indical_get_festival_details_str_id(U8 fest_index);
extern MMI_BOOL mmi_indical_monthly_out_of_boundary(MYTIME *currDate, MMI_BOOL show_popup);
extern U8 mmi_indical_go_to_greg_month(U8 year, U8 adhika_month);
extern void mmi_indical_special_tithi_adjust(MYTIME *time1, MYTIME *time2, S8 tithi_delta, U8 flag);

extern void mmi_indical_send_tithi(void);
#ifdef __MMI_MMS__
extern void mmi_indical_send_tithi_as_MMS(void);
#endif /* __MMI_MMS__ */
#ifdef __MMI_EMAIL__
extern void mmi_indical_send_tithi_as_EMAIL(void);
#endif /* __MMI_EMAIL */

extern void mmi_indical_pre_festival_list_display(void);
extern S32 GetIndicalFestListHint(S32 item_index, UI_string_type *hint_array);
pBOOL GetIndicalFestListItem(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);

extern void mmi_indical_go_to_calendar(void);
extern void mmi_indical_get_fest_date_go_to_calendar(void);
extern void mmi_indical_tithi_display_set_display_key_handler(void);
extern void mmi_indical_go_previous_date(void);
extern void mmi_indical_go_next_date(void);
extern void mmi_indical_get_fest_date(MYTIME *time);
extern void mmi_indical_exit_go_to_calendar(void);
extern void mmi_indical_go_next_festival(void);
extern void mmi_indical_go_prev_festival(void);
extern void mmi_indical_get_festival_icon(MYTIME clndr_time, mmi_clndr_cell_struct *daily_task_info);
extern void mmi_indical_get_paksha_end_icon(MYTIME clndr_time, mmi_clndr_cell_struct *daily_task_info, U8 paksha);
extern void mmi_indical_find_paksha_end_date(MYTIME *time, mmi_indical_indian_date_struct *indian_date, U8 paksha);
extern void mmi_indical_get_next_same_indian_date(MYTIME time, mmi_indical_indian_date_struct indian_date, mmi_indical_gregorian_date_struct *gregorian_date);
extern void mmi_indical_festival_details_set_display_key_handler(void);
extern void mmi_indical_prepare_fest_detail_string(void);
extern pBOOL mmi_indical_get_date_str(MYTIME curr_time, U8* title);
extern void HighlightIndiCalGoToCalendartTithi(void);
extern void HighlightIndiCalGoToCalendartFestival(void);
extern void mmi_indical_date_editor_callback(U8 *DateStr, U8 *day, U8 *month, U8 *year);
extern void mmi_indical_fill_inline_struct(void);
extern void mmi_indical_highlight_clndr_input_item(S32 nIndex);
extern void mmi_indical_validate_input(void);
#ifdef __MMI_BASIC_UI_STYLE__
extern S32 GetIndicalFestListItem_ext(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size);
#endif

#ifdef __MMI_TODOLIST__
extern void HighlightIndiCalTithiReminder(void);
extern void HighlightIndiCalFestivalReminder(void);
extern void mmi_indical_pre_entry_add_festival_reminder(void);
extern int mmi_indical_query_reminder(void);
extern void mmi_indical_add_reminder(void);
extern void mmi_indical_next_tithi_for_reminder(
                mmi_indical_indian_date_struct indical_indian_date,
                mmi_indical_gregorian_date_struct reminder_greg_date,
                MYTIME *time);
extern U8 mmi_indical_get_date_for_next_tithi(MYTIME *time, MYTIME start_time);
extern void mmi_indical_get_reminder_name(U8 *str_buff);
extern void mmi_indical_get_reminder_date(MYTIME *time);
extern void mmi_indical_find_dow(MYTIME curr_date, MYTIME *reminder_date);
extern U8 mmi_indical_is_reminder_in_week(
            MYTIME curr_week_begin,
            MYTIME next_week_begin,
            MYTIME start_time,
            MYTIME *reminder_date);
extern U16 srv_tdl_event_search_tithi_weekly(
                            const void *pevent,
                            const srv_tdl_vcal_enum vcal_type,
                            const srv_tdl_search_weely_struct weekly_search);
extern U16 srv_tdl_event_search_tithi_monthly(
                            const void *pevent,
                            const srv_tdl_vcal_enum vcal_type,
                            const MYTIME date);
extern U16 srv_tdl_event_search_tithi_daily(
                            const void *pevent,
                            const srv_tdl_vcal_enum vcal_type,
                            const MYTIME date);
extern U8 mmi_indical_check_one_tithi_two_greg_dates(MYTIME date);
extern void mmi_indical_pre_entry_add_tithi_reminder(void);

typedef enum
{
    MMI_INDICAL_NONE,
    MMI_INDICAL_FESTIVAL_REMINDER,
    MMI_INDICAL_TITHI_REMINDER
} indical_reminder_type;
#endif /* __MMI_TODOLIST__ */

#endif /* INDICAL_PROTS_H */ 

