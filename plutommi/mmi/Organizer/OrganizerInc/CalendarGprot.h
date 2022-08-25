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
 * CalendarGprot.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines the Calendar external APIs.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef CALENDAR_GPROT_H
#define CALENDAR_GPROT_H

#include "MMI_features.h"

#ifdef __MMI_CALENDAR__

#include "custom_mmi_default_value.h"
#include "MMIDataType.h"
#include "wgui_categories_calendar.h"
#include "gdi_include.h"     
#include "Gui_Setting.h"     
#include "wgui.h"     
#include "kal_general_types.h"

 
/*********************************************************************************
 * Define
 *********************************************************************************/
#define CLNDR_HORIZON_LIST_CELL_LEN  (4)
#define CLNDR_VERTICAL_LIST_CELL_LEN  (6)

#define CLNDR_COLUMN 7
#define CLNDR_ROW 6

#define CLNDR_TOTAL_WEEKDAY 7

#define CLNDR_CELL_SIZE sizeof(gui_calendar_cell_struct)

#define CLNDR_MONTHLY_VIEW 1
#define CLNDR_WEEKLY_VIEW 2

#define CLNDR_INFO_BOX_ROW 2

#define CLNDR_MAX_INFO_BOX_LEN ((MAX_TODO_NOTE_LEN + CLNDR_TIME_PERIOD_STRING_LENGTH + CLNDR_INFO_BOX_COUNTER) * ENCODING_LENGTH)

#define  CLNDR_START_YEAR     1970      /* the frist year in the database table */
#define  CLNDR_MONTH_DAYS   31
#define  CLNDR_END_YEAR         2030    /* the frist year in the database table */

#define CALENDAR_CONTEXT_SIZE   (CLNDR_TITLE_LEN * CLNDR_COLUMN) + (CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH * CLNDR_COLUMN) + (CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH * CLNDR_ROW) + (CLNDR_ROW * CLNDR_COLUMN * CLNDR_CELL_SIZE)

#define CLNDR_WEEKLY_PERIOD_INTERVAL 2   /* one cell means two hours in calendar weekly view screen */

#define  CLNDR_TABLE_START_YEAR     1969        /* the frist year in the database table */
#define  CLNDR_TABLE_END_YEAR       2031        /* the last year in the database table */

#define CLNDR_TIME_STRING_LENGTH (5)    /* HH:MM */
#define CLNDR_TIME_PERIOD_STRING_LENGTH (11)    /* HH:MM-HH:MM */
#define CLNDR_DATE_STRING_LENGTH (10)   /* YYYY/MM/DD */
#define CLNDR_INFO_BOX_COUNTER (7)        /* (15-01) */



/******************************************************************************* 
 * Typedef 
 *******************************************************************************/
typedef enum
{
    MMI_CAL_LAUNCH_TYPE_AUTO,
    MMI_CAL_LAUNCH_TYPE_MONTHLY,
    MMI_CAL_LAUNCH_TYPE_WEEKLY,
    MMI_CAL_LAUNCH_TYPE_DAILY,
    MMI_CAL_LAUNCH_TYPE_ALL,
    MMI_CAL_LAUNCH_TYPE_END_OF_ENUM
}mmi_cal_launch_type_enum;

typedef enum
{
	MMI_CAL_EVENT_SEARCH_IDLE,
	MMI_CAL_EVENT_SEARCH_GOING,
	MMI_CAL_EVENT_SEARCH_DONE_OK,
	MMI_CAL_EVENT_SEARCH_DONE_ERR
}mmi_cal_event_search_state_enum;

/******************************************************************************* 
 * Global Function 
 *******************************************************************************/
extern void mmi_clndr_launch(mmi_id parent_id, mmi_cal_launch_type_enum dis_type, MYTIME *curr_time);

extern void mmi_clndr_entry_main_menu(void);

extern MMI_BOOL mmi_cal_is_busy(void);
extern void mmi_clndr_util_num_to_unicode(S32 num, U8 *str, U8 len);

#if 0
#ifdef  __MMI_CALENDAR_ON_IDLE_SCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__MMI_CALENDAR_ON_IDLE_SCREEN__*/
/* under construction !*/
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_CALENDAR_EVENT__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_CALENDAR_EVENT__ */
/* under construction !*/
#endif /* defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */
#endif //if 0

extern void mmi_entry_calendar(MYTIME calTime);
extern void mmi_clndr_update_date(MYTIME* date);

#if defined(__MMI_ICON_BAR_SUPPORT__)
extern void mmi_clndr_setup_toolbar(U8 view_mode);
#endif
#endif /* __MMI_CALENDAR__ */

#endif /* CALENDAR_GPROT_H */
