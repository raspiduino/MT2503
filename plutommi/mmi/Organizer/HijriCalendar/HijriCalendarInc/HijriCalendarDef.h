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
 * HijriCalendar.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#ifndef HIJRI_CALENDAR_DEFS_H

#define HIJRI_CALENDAR_DEFS_H

#include "MMI_features.h"					//RHR remove

//RHR add begin

#include "MMIDataType.h"
#include "gui_data_types.h"
#include "custom_mmi_default_value.h"
    
//RHR add end

#define MMI_HIJRI_DATE_STR_LEN      200 /* increased the length */
#define MMI_HIJRI_FEST_DETAILS_STR_LEN		1000	/* festival details string length need to find max length */
#define MMI_HIJRI_YEAR_LEN          5
#define MMI_HIJRI_LEAP_YEARS        11
#define MMI_HIJRI_MONTH_LEN         3
#define MMI_HIJRI_DAY_LEN           3
#define MMI_HIJRI_DATE_LEN          11
#define MMI_HIJRI_MAX_FESTIVAL_NAME_LENGTH	50


#define MMI_HIJRI_NUM_MONTHS    12
#define MMI_HIJRI_DAYS_IN_ODD_MONTHS    30
#define MMI_HIJRI_DAYS_IN_EVEN_MONTHS   29
#define MMI_HIJRI_SUM_DAYS_TWO_MONTHS   59
#define MMI_HIJRI_DAYS_IN_HIJRI_YEAR  354
#define MMI_HIJRI_NEXT_OCCURENCES   5
#define MMI_HIJRI_START_YEAR 2000
#define MMI_HIJRI_END_YEAR   2030
#define MMI_HIJRI_ARABIC_UNICODE_NUMERAL_START 0x0660
#define MMI_HIJRI_URDU_UNICODE_NUMERAL_START 0x06F0 

typedef enum
{
    MMI_HIJRI_CONSTANT_ZERO,
    MMI_HIJRI_CONSTANT_ONE,
    MMI_HIJRI_CONSTANT_TWO,
    MMI_HIJRI_CONSTANT_TEN = 10
}mmi_hijri_constants;

typedef enum
{
    MMI_HIJRI_ADD_TWO_DAYS = 2,
    MMI_HIJRI_ADD_ONE_DAY = 1,
    MMI_HIJRI_NO_CORRECTION = 0,
    MMI_HIJRI_SUB_ONE_DAY = -1,
    MMI_HIJRI_SUB_TWO_DAYS = -2
}mmi_hijri_date_correction_enum;

typedef enum
{
    MMI_HIJRI_AHAD,
    MMI_HIJRI_ITHNAYN,
    MMI_HIJRI_THULAATHAA,
    MMI_HIJRI_ARABIA,
    MMI_HIJRI_KHAMIS,
    MMI_HIJRI_JUMU,
    MMI_HIJRI_SABT,
    MMI_HIJRI_MAX_WEEKDAYS
} mmi_hijri_weekday_enum;

typedef enum
{
    MMI_HIJRI_MUHARRAM,
    MMI_HIJRI_SAFAR,
    MMI_HIJRI_RABBI_AWWAL,
    MMI_HIJRI_RABBI_THANI,
    MMI_HIJRI_JUMADA_AWWAL,
    MMI_HIJRI_JUMADA_THANI,
    MMI_HIJRI_RAJAB,
    MMI_HIJRI_SHABAN,
    MMI_HIJRI_RAMADAN,
    MMI_HIJRI_SHAWWAL,
    MMI_HIJRI_QIDAH,
    MMI_HIJRI_HIJIAHSS,
    MMI_HIJRI_MAX_MONTHS
} mmi_hijri_month_enum;

typedef enum
{
    MMI_HIJRI_NEW_YEAR,
    MMI_HIJRI_ASHURAH_DAY,
    MMI_HIJRI_MALWID_SUNNI,
    MMI_HIJRI_MALWID_SHIA,
    MMI_HIJRI_BDAY_TALIB,
    MMI_HIJRI_ISRA_MIRAJ,
    MMI_HIJRI_SHAB_BARAAT,
    MMI_HIJRI_FIRST_DAY_FASTING,
    MMI_HIJRI_NAZUL_QURAN,
    MMI_HIJRI_EID_FITR,
    MMI_HIJRI_HIJJAH,
    MMI_HIJRI_EID_ADHA,
    MMI_HJIRI_EID_GHADEER,
    MMI_HIJRI_MAX_FESTIVALS
} mmi_hijri_festival_enum;

typedef enum
{
    MMI_HIJRICAL_NONE,
    MMI_HIJRICAL_FESTIVAL_REMINDER,
    MMI_HIJRICAL_DAY_REMINDER
} mmi_hijri_reminder_type;

typedef struct
{
    U8 day;
    U8 month;
    U16 year;
} mmi_hijri_date_struct;

typedef struct
{
    U8 day;
    U8 month;
} mmi_hijri_festival_date_struct;

typedef struct
{
    U8 fest_detail_str[(MMI_HIJRI_FEST_DETAILS_STR_LEN + 1) * ENCODING_LENGTH];
	UI_character_type hijri_date_string[MMI_HIJRI_DATE_STR_LEN];    
    U8 year_buff[MMI_HIJRI_YEAR_LEN*ENCODING_LENGTH];
    U8 title_str[(MMI_HIJRI_MAX_FESTIVAL_NAME_LENGTH + 4) * ENCODING_LENGTH]; /* 4 for <  > */
    mmi_hijri_date_struct hijri_date;
    MYTIME clndr_date;
    mmi_hijri_date_struct hijri_base_date;
    S8 fest_dates_highlight_year[MMI_HIJRI_MAX_FESTIVALS + MMI_HIJRI_CONSTANT_TWO];
    U8 dateStr[MMI_HIJRI_MAX_FESTIVALS + MMI_HIJRI_CONSTANT_TWO][11*ENCODING_LENGTH];
    U8 nextFestDateStr[MMI_HIJRI_NEXT_OCCURENCES*(MMI_HIJRI_DATE_LEN + 1)*ENCODING_LENGTH];
    S32 highlighted_index;
    U8 date_correction;
    U16 fest_year;
    U8 reminder_for_hijri;
} mmi_hijri_cntx_struct;

const mmi_hijri_date_struct base_hijri_date = 
{
    24,
    9,
    1420
};

 const U16 mmi_hijri_leap_year_table[MMI_HIJRI_LEAP_YEARS] =
{2, 5, 7, 10, 13, 16, 18, 21, 24, 26, 29};

const mmi_hijri_festival_date_struct mmi_hijri_base_fest_date[MMI_HIJRI_MAX_FESTIVALS] =
{
    {1,1},
    {10,1},
    {12,3},
    {17,3},
    {13,7},
    {27,7},
    {15,8},
    {1,9},
    {27,9},
    {1,10},
    {8,12},
    {10,12},
    {18,12}
};

mmi_hijri_cntx_struct g_mmi_hijri_cntx;


extern mmi_hijri_date_struct mmi_hijri_greg_to_hijri(MYTIME date);
extern mmi_hijri_date_struct mmi_hijri_increment_hijri_date(U16 days);
extern void mmi_hijri_get_fest_greg_date(mmi_hijri_date_struct hijri_start_date, mmi_hijri_date_struct hijri_end_date);

#endif
