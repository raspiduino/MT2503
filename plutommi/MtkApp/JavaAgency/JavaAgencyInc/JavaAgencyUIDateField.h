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
 *   JavaAgencyUIDateField.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 

#ifndef __JAVA_AGENCY_DATEFIELD_H__
#define __JAVA_AGENCY_DATEFIELD_H__

#ifdef __J2ME__

#include "mmi_include.h"

#include "DateTimeType.h"
#include "DateTimeGprot.h"

#include "wgui_calendar.h"

#define  MMI_JAVA_UI_CLNDR_DAY_LEN           3*ENCODING_LENGTH
#define  MMI_JAVA_UI_CLNDR_MON_LEN           3*ENCODING_LENGTH
#define  MMI_JAVA_UI_CLNDR_YEAR_LEN          6*ENCODING_LENGTH

#define MMI_JAVA_UI_CLNDR_COLUMN 7
#define MMI_JAVA_UI_CLNDR_ROW 6

#define MMI_JAVA_UI_CLNDR_VERTICAL_SELECT_LEN (5 * ENCODING_LENGTH)

#define MMI_JAVA_UI_CLNDR_MAX_ROW 24

#define  MMI_JAVA_UI_CLNDR_TITLE_LEN            12*ENCODING_LENGTH

#define MMI_JAVA_UI_CLNDR_HORIZON_LIST_CELL_LEN  (4)
#define MMI_JAVA_UI_CLNDR_VERTICAL_LIST_CELL_LEN  (6)
#define MMI_JAVA_UI_CLNDR_VERTICAL_SELECT_LEN (5 * ENCODING_LENGTH)

#define MMI_JAVA_UI_CLNDR_CELL_SIZE sizeof(gui_calendar_cell_struct)

#define MMI_JAVA_UI_CLNDR_START_WEEKDAY 0
#define MMI_JAVA_UI_CLNDR_TOTAL_WEEKDAY 7

#define MMI_JAVA_UI_CLNDR_MAX_YEAR_BUF_SIZE 5
#define MMI_JAVA_UI_CLNDR_MAX_DATE_BUF_SIZE 3
#define MMI_JAVA_UI_CLNDR_MAX_TIME_BUF_SIZE 3

#define MMI_JAVA_UI_CLNDR_WEEK_SYMBOL_LEN 1

#define  MMI_JAVA_UI_CLNDR_START_YEAR     1900      /* the frist year in the database table */
#define  MMI_JAVA_UI_CLNDR_MONTH_DAYS   31
#define  MMI_JAVA_UI_CLNDR_END_YEAR         2030    /* the frist year in the database table */

typedef enum
{
    MMI_JAVA_UI_CLNDR_KEY_UP = 0,
    MMI_JAVA_UI_CLNDR_KEY_DOWN,
    MMI_JAVA_UI_CLNDR_KEY_LEFT,
    MMI_JAVA_UI_CLNDR_KEY_RIGHT,
    MMI_JAVA_UI_CLNDR_KEY_TOTAL
} MMI_JAVA_UI_CLNDR_KEY_ENUM;

typedef enum 
{
    MMI_JAVA_UI_CLNDR_NEXT_MONTH,
    MMI_JAVA_UI_CLNDR_PRIVOUS_MONTH,
    MMI_JAVA_UI_CLNDR_NEXT_WEEK,
    MMI_JAVA_UI_CLNDR_PRIVOUS_WEEK,
#ifdef __MMI_TOUCH_SCREEN__
    MMI_JAVA_UI_CLNDR_NEXT_YEAR,
    MMI_JAVA_UI_CLNDR_PRIVOUS_YEAR,
    MMI_JAVA_UI_CLNDR_NEXT_PERIOD,
    MMI_JAVA_UI_CLNDR_PRIVOUS_PERIOD,
    MMI_JAVA_UI_CLNDR_NEXT_MULTI_PERIOD,
    MMI_JAVA_UI_CLNDR_PRIVOUS_MULTI_PERIOD,
#endif /* __MMI_TOUCH_SCREEN__ */ 
    MMI_JAVA_UI_CLNDR_CLNDAR_MOVEMENT_TOTAL
} MMI_JAVA_UI_CLNDR_CLNDAR_MOVEMENT_ENUM;

typedef struct
{
    MYTIME CalTime;
    S8 DayBuf[MMI_JAVA_UI_CLNDR_DAY_LEN];
    S8 MonBuf[MMI_JAVA_UI_CLNDR_MON_LEN];
    S8 YearBuf[MMI_JAVA_UI_CLNDR_YEAR_LEN];
    U8 DayOnFirst;
    U8 NumDaysInMonth;
    U8 *Title;
    U8 *HorizonList[MMI_JAVA_UI_CLNDR_COLUMN];
    U8 *VerticalList[MMI_JAVA_UI_CLNDR_ROW];
    gui_calendar_cell_struct *CalendarCell;
    U8 RowNumber;
    U8 horizon_select1[MMI_JAVA_UI_CLNDR_VERTICAL_SELECT_LEN];
    U8 horizon_select2[MMI_JAVA_UI_CLNDR_VERTICAL_SELECT_LEN];

    kal_int32 vm_id;
    void (*callback) (kal_bool validate, kal_int32 year, kal_int32 month, kal_int32 day, kal_int32 display_id);

} mmi_java_ui_clndr_context_struct;

typedef struct
{
    kal_int32 hour;
    kal_int32 minute;
    kal_int32 second;

    kal_int32 vm_id;
    void (*callback) (kal_bool validate, kal_int32 hour, kal_int32 minute, kal_int32 second, kal_int32 display_id);

} mmi_java_ui_time_context_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_int32 year;
    kal_int32 month;
    kal_int32 day;

    kal_int32 vm_id;
    void (*callback) (kal_bool validate, kal_int32 year, kal_int32 month, kal_int32 day, kal_int32 display_id);

}mmi_java_ui_datefield_date_show_req_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_bool validate;
    kal_int32 year;
    kal_int32 month;
    kal_int32 day;

    kal_int32 vm_id;
    void (*callback) (kal_bool validate, kal_int32 year, kal_int32 month, kal_int32 day, kal_int32 display_id);
}mmi_java_ui_datefield_date_show_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_int32 hour;
    kal_int32 minute;
    kal_int32 second;

    kal_int32 vm_id;
    void (*callback) (kal_bool validate, kal_int32 hour, kal_int32 minute, kal_int32 second, kal_int32 display_id);

}mmi_java_ui_datefield_time_show_req_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_bool validate;
    kal_int32 hour;
    kal_int32 minute;
    kal_int32 second;

    kal_int32 vm_id;
    void (*callback) (kal_bool validate, kal_int32 hour, kal_int32 minute, kal_int32 second, kal_int32 display_id);
}mmi_java_ui_datefield_time_show_rsp_struct;


extern void mmi_java_ui_datefield_int(void);
extern void mmi_java_ui_datefield_date_show_req(void *msg);
extern void mmi_java_ui_datafield_date_hide_req(void *msg);
extern void mmi_java_ui_datefield_time_show_req(void *msg);
extern void mmi_java_ui_datafield_time_hide_req(void *msg);
extern void mmi_java_ui_datefield_exit_screen(MMI_ID scrn_id);

#endif /* __J2ME__ */
#endif /* __JAVA_AGENCY_DATEFIELD_H__ */

