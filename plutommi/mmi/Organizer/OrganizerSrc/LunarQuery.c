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
 * LunarQuery.c
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
 * 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/**********************************************************************************
   Filename:     
   Author:        
   Date Created:  
**********************************************************************************/
/*********************************************************************************
 * Include
 *********************************************************************************/
#include "MMI_features.h"  


#ifdef __MMI_LUNAR_QUERY__
#include "MMIDataType.h"
#include "wgui_categories_calendar.h"
#include "mmi_rp_app_lunar_query_def.h"
#include "LunarQuery.h"
#include "InlineCuiGprot.h"
#include "GlobalResDef.h"
#include "ShortcutsGProts.h"
/******************************************************************************* 
 * Define 
 *******************************************************************************/
#define  LUNAR_INFO_TABLE_START_YEAR     1969        /* the frist year in the database table */
#define  LUNAR_INFO_TABLE_END_YEAR       2031        /* the last year in the database table */

/********************************************************************************
 * Extern Global Struct 
 ********************************************************************************/
const U16 gSolarAccu365Days[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
const U16 gSolarAccu366Days[] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};

const U8 solar_terms_table[][12] = 
{
  
  {0x64, 0x43, 0x65, 0x54, 0x65, 0x66, 0x77, 0x87, 0x87, 0x98, 0x87, 0x76},       /* 1970 */
  {0x65, 0x43, 0x65, 0x55, 0x66, 0x66, 0x87, 0x88, 0x88, 0x98, 0x87, 0x86},
  {0x65, 0x53, 0x54, 0x54, 0x55, 0x55, 0x77, 0x77, 0x77, 0x87, 0x76, 0x76},
  {0x54, 0x43, 0x65, 0x54, 0x65, 0x65, 0x77, 0x87, 0x87, 0x87, 0x76, 0x76},
  {0x64, 0x43, 0x65, 0x54, 0x65, 0x66, 0x77, 0x87, 0x87, 0x98, 0x86, 0x76},
  {0x64, 0x43, 0x65, 0x55, 0x66, 0x66, 0x87, 0x88, 0x88, 0x98, 0x87, 0x86},       /* 1975 */
  {0x65, 0x43, 0x54, 0x44, 0x55, 0x55, 0x77, 0x77, 0x77, 0x87, 0x76, 0x76},
  {0x54, 0x43, 0x55, 0x54, 0x55, 0x65, 0x77, 0x77, 0x87, 0x87, 0x76, 0x76},
  {0x54, 0x43, 0x65, 0x54, 0x65, 0x66, 0x77, 0x87, 0x87, 0x88, 0x87, 0x76},
  {0x64, 0x43, 0x65, 0x55, 0x66, 0x66, 0x87, 0x88, 0x87, 0x98, 0x87, 0x86},
  {0x65, 0x43, 0x54, 0x44, 0x55, 0x55, 0x77, 0x77, 0x77, 0x87, 0x76, 0x75},       /* 1980 */
  {0x54, 0x43, 0x55, 0x54, 0x55, 0x65, 0x77, 0x77, 0x87, 0x87, 0x76, 0x76},
  {0x54, 0x43, 0x65, 0x54, 0x65, 0x66, 0x77, 0x87, 0x87, 0x88, 0x86, 0x76},
  {0x64, 0x43, 0x65, 0x54, 0x65, 0x66, 0x87, 0x88, 0x87, 0x98, 0x87, 0x86},
  {0x65, 0x43, 0x54, 0x44, 0x55, 0x55, 0x77, 0x77, 0x77, 0x87, 0x76, 0x75},
  {0x54, 0x43, 0x54, 0x54, 0x55, 0x65, 0x77, 0x77, 0x87, 0x87, 0x76, 0x76},       /* 1985 */
  {0x54, 0x43, 0x65, 0x54, 0x65, 0x66, 0x77, 0x87, 0x87, 0x88, 0x86, 0x76},
  {0x64, 0x43, 0x65, 0x54, 0x65, 0x66, 0x87, 0x88, 0x87, 0x98, 0x87, 0x76},
  {0x65, 0x43, 0x54, 0x44, 0x55, 0x55, 0x77, 0x77, 0x77, 0x87, 0x76, 0x75},
  {0x54, 0x42, 0x54, 0x54, 0x55, 0x65, 0x77, 0x77, 0x87, 0x87, 0x76, 0x76},
  {0x54, 0x43, 0x65, 0x54, 0x65, 0x65, 0x77, 0x87, 0x87, 0x88, 0x86, 0x76},       /* 1990 */
  {0x64, 0x43, 0x65, 0x54, 0x65, 0x66, 0x77, 0x87, 0x87, 0x98, 0x87, 0x76},
  {0x65, 0x43, 0x54, 0x44, 0x55, 0x55, 0x76, 0x77, 0x77, 0x87, 0x76, 0x75},
  {0x54, 0x42, 0x54, 0x54, 0x55, 0x65, 0x77, 0x77, 0x77, 0x87, 0x76, 0x76},
  {0x54, 0x43, 0x65, 0x54, 0x65, 0x66, 0x77, 0x87, 0x87, 0x87, 0x76, 0x76},
  {0x64, 0x43, 0x65, 0x54, 0x65, 0x66, 0x77, 0x87, 0x87, 0x98, 0x87, 0x76},       /* 1995 */
  {0x65, 0x43, 0x54, 0x44, 0x55, 0x55, 0x76, 0x77, 0x77, 0x87, 0x76, 0x75},
  {0x54, 0x42, 0x54, 0x54, 0x55, 0x65, 0x77, 0x77, 0x77, 0x87, 0x76, 0x76},
  {0x54, 0x43, 0x65, 0x54, 0x65, 0x65, 0x77, 0x87, 0x87, 0x87, 0x76, 0x76},
  {0x64, 0x43, 0x65, 0x54, 0x65, 0x66, 0x77, 0x87, 0x87, 0x98, 0x87, 0x76},
  {0x65, 0x43, 0x54, 0x44, 0x55, 0x55, 0x76, 0x77, 0x77, 0x87, 0x76, 0x75},       /* 2000 */
  {0x54, 0x42, 0x54, 0x54, 0x55, 0x55, 0x77, 0x77, 0x77, 0x87, 0x76, 0x76},
  {0x54, 0x43, 0x65, 0x54, 0x65, 0x65, 0x77, 0x87, 0x87, 0x87, 0x76, 0x76},
  {0x64, 0x43, 0x65, 0x54, 0x65, 0x66, 0x77, 0x87, 0x87, 0x98, 0x87, 0x76},
  {0x65, 0x43, 0x54, 0x44, 0x55, 0x55, 0x76, 0x77, 0x77, 0x87, 0x76, 0x75},
  {0x54, 0x42, 0x54, 0x54, 0x55, 0x55, 0x77, 0x77, 0x77, 0x87, 0x76, 0x76},       /* 2005 */
  {0x54, 0x43, 0x65, 0x54, 0x65, 0x65, 0x77, 0x87, 0x87, 0x87, 0x76, 0x76},
  {0x64, 0x43, 0x65, 0x54, 0x65, 0x66, 0x77, 0x87, 0x87, 0x98, 0x86, 0x76},
  {0x64, 0x43, 0x54, 0x44, 0x55, 0x55, 0x76, 0x77, 0x77, 0x87, 0x76, 0x75},
  {0x54, 0x32, 0x54, 0x44, 0x55, 0x55, 0x77, 0x77, 0x77, 0x87, 0x76, 0x76},
  {0x54, 0x43, 0x65, 0x54, 0x55, 0x65, 0x77, 0x77, 0x87, 0x87, 0x76, 0x76},       /* 2010 */
  {0x64, 0x43, 0x65, 0x54, 0x65, 0x66, 0x77, 0x87, 0x87, 0x88, 0x87, 0x76},
  {0x65, 0x43, 0x54, 0x44, 0x54, 0x55, 0x76, 0x77, 0x76, 0x87, 0x76, 0x75},
  {0x54, 0x42, 0x54, 0x44, 0x55, 0x55, 0x76, 0x77, 0x77, 0x87, 0x76, 0x76},
  {0x54, 0x43, 0x55, 0x54, 0x55, 0x65, 0x77, 0x77, 0x87, 0x87, 0x76, 0x76},
  {0x54, 0x43, 0x65, 0x54, 0x65, 0x66, 0x77, 0x87, 0x87, 0x88, 0x86, 0x76},       /* 2015 */
  {0x64, 0x43, 0x54, 0x43, 0x54, 0x55, 0x76, 0x77, 0x76, 0x87, 0x76, 0x65},
  {0x54, 0x32, 0x54, 0x44, 0x55, 0x55, 0x77, 0x77, 0x77, 0x87, 0x76, 0x75},
  {0x54, 0x42, 0x54, 0x54, 0x55, 0x65, 0x77, 0x77, 0x87, 0x87, 0x76, 0x76},
  {0x54, 0x43, 0x65, 0x54, 0x65, 0x65, 0x77, 0x87, 0x87, 0x88, 0x86, 0x76},
  {0x64, 0x43, 0x54, 0x43, 0x54, 0x55, 0x76, 0x77, 0x76, 0x87, 0x76, 0x65},       /* 2020 */
  {0x54, 0x32, 0x54, 0x44, 0x55, 0x55, 0x76, 0x77, 0x77, 0x87, 0x76, 0x75},
  {0x54, 0x42, 0x54, 0x54, 0x55, 0x65, 0x77, 0x77, 0x87, 0x87, 0x76, 0x76},
  {0x54, 0x43, 0x65, 0x54, 0x65, 0x66, 0x77, 0x87, 0x87, 0x87, 0x76, 0x76},
  {0x64, 0x43, 0x54, 0x43, 0x54, 0x55, 0x66, 0x77, 0x76, 0x87, 0x76, 0x65},
  {0x54, 0x32, 0x54, 0x44, 0x55, 0x55, 0x76, 0x77, 0x77, 0x87, 0x76, 0x75},       /* 2025 */
  {0x54, 0x42, 0x54, 0x54, 0x55, 0x65, 0x77, 0x77, 0x77, 0x87, 0x76, 0x76},
  {0x54, 0x43, 0x65, 0x54, 0x65, 0x65, 0x77, 0x87, 0x87, 0x87, 0x76, 0x76},
  {0x64, 0x43, 0x54, 0x43, 0x54, 0x55, 0x66, 0x76, 0x76, 0x87, 0x76, 0x65},
  {0x54, 0x32, 0x54, 0x44, 0x55, 0x55, 0x76, 0x77, 0x77, 0x87, 0x76, 0x75},
  {0x54, 0x42, 0x54, 0x54, 0x55, 0x65, 0x77, 0x77, 0x77, 0x87, 0x76, 0x76},       /* 2030 */
};

const lunar_query_info_struct gLunarQueryInfo[] = 
{
    {47, 0, 5482},
    {36, 0, 2921},   /* 1970 */
    {26, 5, 5970},
    {45, 0, 6994},
    {33, 0, 6949},
    {22, 4, 5707},
    {41, 0, 6731},   /* 1975 */
    {30, 8, 5291},
    {48, 0, 4781},
    {37, 0, 5485},
    {27, 6, 2921},
    {46, 0, 3497},    /* 1980 */
    {35, 0, 7570},
    {24, 4, 7461},
    {43, 0, 7461},
    {32, 10, 6733},
    {50, 0, 2646},   /* 1985 */
    {39, 0, 4790},
    {28, 6, 1461},
    {47, 0, 5845},
    {36, 0, 3753},
    {26, 5, 7826},    /* 1990 */
    {45, 0, 3730},
    {34, 0, 3366},
    {22, 3, 2646},
    {40, 0, 2647},
    {30, 8, 5334},   /* 1995 */
    {49, 0, 4954},
    {37, 0, 5845},
    {27, 5, 5833},
    {46, 0, 5961},
    {35, 0, 5779},   /* 2000 */
    {23, 4, 5419},
    {42, 0, 5419},
    {31, 0, 2651},
    {21, 2, 5466},
    {39, 0, 5482},   /* 2005 */
    {28, 7, 6997},
    {48, 0, 7076},
    {37, 0, 6985},
    {25, 5, 6803},
    {44, 0, 6805},   /* 2010 */
    {33, 0, 5421},
    {22, 4, 2733},
    {40, 0, 2741},
    {30, 9, 5546},
    {49, 0, 5586},   /* 2015 */
    {38, 0, 3493},
    {27, 6, 7498},
    {46, 0, 3402},
    {35, 0, 3221},
    {24, 4, 5422},   /* 2020 */
    {42, 0, 5462},
    {31, 0, 2741},
    {21, 2, 5554},
    {40, 0, 5842},
    {28, 6, 3749},    /* 2025 */
    {47, 0, 5925},
    {36, 0, 5707},
    {25, 5, 3223},
    {43, 0, 3243},
    {33, 0, 1370},   /* 2030 */
    {22, 3, 2774},   /* 2031 */
};

mmi_id mmi_lunar_jump_to_date_gid;
mmi_id mmi_lunar_select_year_gid;

/********************************************************************************
 * Typedef 
 ********************************************************************************/
typedef enum
{
    LUNAR_QUERY,
    FESTIVAL_QUERY,
    TERMS_QUERY,
    LUNAR_ITEM_TOTAL
}LUNAR_MENU_ITEM_ENUM;

typedef enum
{
    SLIGHT_COLD,
    GREAT_COLD,
    SPRING_BEGINS,
    THE_RAINS,
    INSECTS_AWAKEN,
    VERNAL_EQUINOX,
    CLEAR_AND_BRIGHT,
    GRAIN_RAIN,
    SUMMER_BEGINS,
    GRAIN_BUDS,
    GRAIN_IN_EAR,
    SUMMER_SOLSTICE,
    SLIGHT_HEAT,
    GREAT_HEAT,
    AUTUMN_BEGINS,
    STOPPING_THE_HEAT,
    WHITE_DEWS,
    AUTUMN_EQUINOX,
    COLD_DEWS,
    HOAR_FROST_FALLS,
    WINTER_BEGINS,
    LIGHT_SNOW,
    HEAVY_SNOW,
    WINTER_SOLSTICE,
    SOLAR_TERM_TOTAL
} SOLAR_TERMS_ENUM;
typedef enum
{
    SPRING_FESTIVAL = STR_LUNAR_SPRING_FESTIVAL,
    LANTERN_FESTIVAL = STR_LUNAR_LANTERN_FESTIVAL,
    DRAGON_BOAT_FESTIVAL = STR_LUNAR_DRAGON_BOAT_FESTIVAL, 
    DOUBLE_SEVENTH_DAY = STR_LUNAR_DOUBLE_SEVENTH_DAY,
    MID_AUTUMN_FESTIVAL = STR_LUNAR_MID_AUTUMN_FESTIVAL,
    DOUBLE_NINTH_DAY = STR_LUNAR_DOUBLE_NINTH_DAY
} LUNAR_FESTIVAL_ENUM;

typedef enum
{
    NEW_YEARS_DAY = STR_LUNAR_NEW_YEARS_DAY,
    INTERNATION_WOMEN_DAY = STR_LUNAR_INTERNATION_WOMEN_DAY,
    INTERNATION_LABOUR_DAY = STR_LUNAR_INTERNATION_LABOUR_DAY,
    INTERNATION_CHILDRENS_DAY = STR_LUNAR_INTERNATION_CHILDRENS_DAY,
    NATIONAL_DAY = STR_LUNAR_NATIONAL_DAY,
    SOLAR_FESTIVAL_TOTAL = 11  // total number of festivals
} SOLAR_FESTIVAL_ENUM;
/******************************************************************************* 
 * cui items 
 *******************************************************************************/
cui_inline_item_caption_struct cui_lunar_jump_date_caption =
{
    STR_GLOBAL_DATE
};

cui_inline_item_caption_struct cui_lunar_select_year_caption =
{
    STR_LUNAR_CHINESE_YEAR
};

cui_inline_set_item_struct cui_lunar_jump_to_date[2] = 
{
    {CUI_INLINE_ITEM_ID_BASE + 0, CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH, 0, &cui_lunar_jump_date_caption},
    {CUI_INLINE_ITEM_ID_BASE + 1, CUI_INLINE_ITEM_TYPE_DATE | CUI_INLINE_ITEM_FULL_WIDTH , 0, NULL},
};

cui_inline_set_item_struct cui_lunar_select_year[2] = 
{
    {CUI_INLINE_ITEM_ID_BASE + 0, CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH, 0, &cui_lunar_select_year_caption},
    {CUI_INLINE_ITEM_ID_BASE + 1, CUI_INLINE_ITEM_TYPE_DATE | CUI_INLINE_ITEM_FULL_WIDTH , 0, NULL},
};

/******************************************************************************* 
 * Global Function 
 *******************************************************************************/
lunar_cntx_struct g_lunar_cntx;

/*****************************************************************************
 * FUNCTION
 *  mmi_lunar_solar2lunar
 * DESCRIPTION
 *  This function is to convert solar date to lunar date.
 * CALLS
 * PARAMETERS
 *  clndr_date      [IN/OUT]        clndr date to be computed
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lunar_solar2lunar(lunar_date_info_struct *clndr_date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    U32 year_index;
    U32 month_index;
    U32 lunar_days_sum = 0;
    U32 intercalary_month = 0;
    U32 lunar_monthly_days = 0;
    U32 solar_accu_day = 0;
    U32 lunar_accu_day = 0;
    U32 is_leap_year = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_leap_year = IsLeapYear(clndr_date->SolarYear);
    if(is_leap_year == 1)
    {  
        solar_accu_day = gSolarAccu366Days[clndr_date->SolarMonth - 1] + clndr_date->SolarDay;
    }
    else
    {
        solar_accu_day = gSolarAccu365Days[clndr_date->SolarMonth - 1] + clndr_date->SolarDay;
    }
    year_index = clndr_date->SolarYear - LUNAR_INFO_TABLE_START_YEAR;

    /* to check if today is earlier than the Chinese New Year of this year */
    if (solar_accu_day <= gLunarQueryInfo[year_index].BaseDays)
    {
        year_index--;
        clndr_date->LunarYear = clndr_date->SolarYear- 1;
        if(IsLeapYear(clndr_date->SolarYear - 1))
        {
            lunar_accu_day = solar_accu_day + 366 - gLunarQueryInfo[year_index].BaseDays;
        }
        else
        {
            lunar_accu_day = solar_accu_day + 365 - gLunarQueryInfo[year_index].BaseDays;
        }
    }
    else
    {
        clndr_date->LunarYear = clndr_date->SolarYear;
        lunar_accu_day = solar_accu_day - gLunarQueryInfo[year_index].BaseDays;
    }
    

    /* to calculate the lunar month and day */
    for (month_index = 0; month_index < 13; month_index++)
    {
        if (gLunarQueryInfo[year_index].MonthDays & (0x01 << month_index))
        {
            lunar_monthly_days = 30;
        }
        else
        {
            lunar_monthly_days = 29;
        }
        lunar_days_sum += lunar_monthly_days;

        if (lunar_days_sum >= lunar_accu_day)
        {
            lunar_days_sum -= lunar_monthly_days;
            break;
        }     
    }
    clndr_date->LunarMonth = (month_index + 1);
    clndr_date->LunarDay = lunar_accu_day - lunar_days_sum;

    /* to adjust Lunar month if there is a intercalary month in this year */
    intercalary_month = gLunarQueryInfo[year_index].Intercalary;
    if(intercalary_month == 0)
    {
        clndr_date->LeapMonth = MMI_FALSE;
    }
    else
    {
        if(clndr_date->LunarMonth == intercalary_month + 1)
        {
            clndr_date->LunarMonth--;
            clndr_date->LeapMonth = MMI_TRUE;   
        }
        else if(clndr_date->LunarMonth > intercalary_month + 1)
        {
            clndr_date->LunarMonth--;
            clndr_date->LeapMonth = MMI_FALSE;
        }
        else
        {
            clndr_date->LeapMonth = MMI_FALSE;
        }
    }
    /* to calculate the Kan and Chin of this year */
    clndr_date->KanYear = (clndr_date->LunarYear - 1900 + 36) % 10;
    clndr_date->ChiYear = (clndr_date->LunarYear - 1900 + 36) % 12;

    /* to calculate the lunar day of solar term in this month */
    if(clndr_date->SolarDay == (solar_terms_table[clndr_date->SolarYear - CLNDR_FIRST_NAVI_YEAR][clndr_date->SolarMonth - 1]>>4))                                 
    {
        clndr_date->SolarTerm = clndr_date->SolarMonth * 2 - 1;
    }
    else if(clndr_date->SolarDay == (solar_terms_table[clndr_date->SolarYear - CLNDR_FIRST_NAVI_YEAR][clndr_date->SolarMonth - 1]&0X0F + 16))
    {
        clndr_date->SolarTerm = clndr_date->SolarMonth * 2;
    }
    else
    {
        clndr_date->SolarTerm = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_lunar_lunar2solar
 * DESCRIPTION
 *  This function is to convert a lunar date to solar date.
 * CALLS
 * PARAMETERS
 *  clndr_date      [IN/OUT]        clndr date to be computed
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lunar_lunar2solar(lunar_date_info_struct *clndr_date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    U32 year_index;
    U32 month_index;
    U32 lunar_month;
    U32 intercalary_month;
    U32 lunar_monthly_days;
    U32 solar_accu_day = 0;
    U32 lunar_accu_day = 0;
    U32 is_leap_year;
    U32 solar_yearly_day;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    year_index = clndr_date->LunarYear - LUNAR_INFO_TABLE_START_YEAR;
    lunar_month = clndr_date->LunarMonth;
    
    /* calculate the accu day of this lunar year */
    intercalary_month = gLunarQueryInfo[year_index].Intercalary;
    if(intercalary_month != 0 && intercalary_month < clndr_date->LunarMonth)
    {
       lunar_month++;
    }
    for (month_index = 0; month_index < (lunar_month - 1); month_index++)
    {
        if (gLunarQueryInfo[year_index].MonthDays & (0x01 << month_index))
        {
            lunar_monthly_days = 30;
        }
        else
        {
            lunar_monthly_days = 29;
        }
        lunar_accu_day += lunar_monthly_days; 
    }
    lunar_accu_day += clndr_date->LunarDay;

    /* compute solar year and accu day */
    is_leap_year = IsLeapYear(clndr_date->LunarYear);
    if(is_leap_year == 1)
    {
        solar_yearly_day = 366;
    }
    else
    {
        solar_yearly_day = 365;
    }
    if(lunar_accu_day < solar_yearly_day - gLunarQueryInfo[year_index].BaseDays)
    {
        clndr_date->SolarYear = clndr_date->LunarYear;
        solar_accu_day = gLunarQueryInfo[year_index].BaseDays + lunar_accu_day;
    }
    else
    {
        clndr_date->SolarYear = clndr_date->LunarYear + 1;
        solar_accu_day = gLunarQueryInfo[year_index].BaseDays + lunar_accu_day - solar_yearly_day;
    }

    /* compute solar month and day */
    if(solar_yearly_day == 366)
    {
        for(lunar_month = 0; lunar_month < 12; lunar_month++)
        {
            if((gSolarAccu366Days[lunar_month] < solar_accu_day)&&
               (gSolarAccu366Days[lunar_month + 1] >= solar_accu_day))
            {
                clndr_date->SolarMonth = lunar_month + 1;
                clndr_date->SolarDay = solar_accu_day - gSolarAccu366Days[lunar_month];
                break;
            }
        }
    }
    else
    {
        for(lunar_month = 0; lunar_month < 12; lunar_month++)
        {
            if((gSolarAccu365Days[lunar_month] < solar_accu_day)&&
               (gSolarAccu365Days[lunar_month + 1] >= solar_accu_day))
            {
                clndr_date->SolarMonth = lunar_month + 1;
                clndr_date->SolarDay = solar_accu_day - gSolarAccu365Days[lunar_month];
				break;
            }
        }
    }

    /* to calculate the Kan and Chin of this year */
    clndr_date->KanYear = (clndr_date->LunarYear - 1900 + 36) % 10;
    clndr_date->ChiYear = (clndr_date->LunarYear - 1900 + 36) % 12;

    /* to calculate the lunar day of solar term in this month */
    if(clndr_date->SolarDay == (solar_terms_table[clndr_date->SolarYear - CLNDR_FIRST_NAVI_YEAR][clndr_date->SolarMonth - 1]>>4))                                 
    {
        clndr_date->SolarTerm = clndr_date->SolarMonth * 2 - 1;
    }
    else if(clndr_date->SolarDay == (solar_terms_table[clndr_date->SolarYear - CLNDR_FIRST_NAVI_YEAR][clndr_date->SolarMonth - 1]&0X0F + 16))
    {
        clndr_date->SolarTerm = clndr_date->SolarMonth * 2;
    }
    else
    {
        clndr_date->SolarTerm = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_lunar_festival_query
 * DESCRIPTION
 *  This function is to query the lunar and solar date of a given lunar festival
 * CALLS
 * PARAMETERS
 *  lunar_year          [IN]        lunar year
 *  lunar_festival      [IN]        lunar festival id
 *  clndr_date          [OUT]       solar and lunar info
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_lunar_festival_query(U32 lunar_year, LUNAR_FESTIVAL_ENUM lunar_festival, lunar_date_info_struct *clndr_date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clndr_date->LunarYear = lunar_year;
    clndr_date->LeapMonth = MMI_FALSE;
    
    switch(lunar_festival) 
    {
        case SPRING_FESTIVAL:
            clndr_date->LunarMonth = 1;
            clndr_date->LunarDay = 1;
        break;
        
        case LANTERN_FESTIVAL:
            clndr_date->LunarMonth = 1;
            clndr_date->LunarDay = 15;
        break;
        
        case DRAGON_BOAT_FESTIVAL:
            clndr_date->LunarMonth = 5;
            clndr_date->LunarDay = 5;
        break;

        case DOUBLE_SEVENTH_DAY:
            clndr_date->LunarMonth = 7;
            clndr_date->LunarDay = 7;
        break;
        
        case MID_AUTUMN_FESTIVAL:
            clndr_date->LunarMonth = 8;
            clndr_date->LunarDay = 15;
        break;

        case DOUBLE_NINTH_DAY:
            clndr_date->LunarMonth = 9;
            clndr_date->LunarDay = 9;
        break;
    }
    
    mmi_lunar_lunar2solar(clndr_date);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_solar_festival_query
 * DESCRIPTION
 *  This function is to query the lunar and solar date of a given solar festival
 * CALLS
 * PARAMETERS
 *  solar_year          [IN]        solar year
 *  solar_festival      [IN]        solar festival id
 *  clndr_date          [OUT]       solar and lunar info
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_solar_festival_query(U32 solar_year, SOLAR_FESTIVAL_ENUM solar_festival, lunar_date_info_struct *clndr_date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clndr_date->SolarYear = solar_year;
    
    switch(solar_festival)
    {
        case NEW_YEARS_DAY:
            clndr_date->SolarMonth = 1;
            clndr_date->SolarDay = 1;
        break;
        
        case INTERNATION_WOMEN_DAY:
            clndr_date->SolarMonth = 3;
            clndr_date->SolarDay = 8;
        break;
        
        case INTERNATION_LABOUR_DAY:
            clndr_date->SolarMonth = 5;
            clndr_date->SolarDay = 1;
        break;

        case INTERNATION_CHILDRENS_DAY:
            clndr_date->SolarMonth = 6;
            clndr_date->SolarDay = 1;
        break;
        
        case NATIONAL_DAY:
            clndr_date->SolarMonth = 10;
            clndr_date->SolarDay = 1;
        break;
    }
    
    mmi_lunar_solar2lunar(clndr_date);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_solar_terms_query
 * DESCRIPTION
 *  query the lunar and solar date of a given solar term
 * CALLS
 * PARAMETERS
 *  solar_year          [IN]        solar year
 *  solar_term          [IN]        solar term id
 *  clndr_date          [OUT]       solar and lunar info
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_solar_terms_query(U32 solar_year, SOLAR_TERMS_ENUM solar_term, lunar_date_info_struct *clndr_date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clndr_date->SolarYear = solar_year; 
    clndr_date->SolarMonth = (solar_term / 2) + 1;
    if(solar_term % 2 == 1)
    {
        clndr_date->SolarDay = (solar_terms_table[clndr_date->SolarYear - CLNDR_FIRST_NAVI_YEAR][clndr_date->SolarMonth - 1] & 0X0F) + 16;
    }
    else
    {
        clndr_date->SolarDay = solar_terms_table[clndr_date->SolarYear - CLNDR_FIRST_NAVI_YEAR][clndr_date->SolarMonth - 1] >> 4;
    }

    mmi_lunar_solar2lunar(clndr_date); 
}


static void mmi_lunar_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_lunar_cntx.highlight_idx = index;
}


static void mmi_lunar_festival_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_lunar_cntx.highlight_idx = index + STR_LUNAR_NEW_YEARS_DAY;
}


void mmi_lunar_date_output_str(lunar_date_info_struct *lunar_date, WCHAR* lunar_str)
{
    /* Chinese year/month/day information */
    mmi_wcscpy(lunar_str, (WCHAR*)GetString((U16) (STR_LUNAR_KAN1 + lunar_date->KanYear)));
    mmi_wcscat(lunar_str, (WCHAR*)GetString((U16) (STR_LUNAR_CHI1 + lunar_date->ChiYear)));
    mmi_wcscat(lunar_str, (WCHAR*)GetString(STR_LUNAR_CHINESE_YEAR));


    if (lunar_date->LeapMonth == MMI_TRUE)
    {
        mmi_wcscat(lunar_str, (WCHAR*)GetString(STR_LUNAR_LEAP_MONTH));
    }

    if(lunar_date->LunarMonth == 1)
    {
        mmi_wcscat(lunar_str, (WCHAR*)GetString((U16) (STR_LUNAR_CHINESE_ZHENG_YUE)));
    }
    else if (lunar_date->LunarMonth <= 10)
    {
        mmi_wcscat(lunar_str, (WCHAR*)GetString((U16) (STR_LUNAR_CHINESE_NO1 + lunar_date->LunarMonth - 1)));
    }
    else if (lunar_date->LunarMonth == 12)
    {
        mmi_wcscat(lunar_str, (WCHAR*)GetString((U16) (STR_LUNAR_CHINESE_LA_YUE)));
    }
    else
    {
        mmi_wcscat(lunar_str, (WCHAR*)GetString(STR_LUNAR_CHINESE_NO10));
        mmi_wcscat(lunar_str, (WCHAR*)GetString((U16) (STR_LUNAR_CHINESE_NO1 )));
    }
    mmi_wcscat(lunar_str, (WCHAR*)GetString(STR_LUNAR_CHINESE_MONTH));

    if (lunar_date->LunarDay <= 10)
    {
        mmi_wcscat(lunar_str, (WCHAR*)GetString((U16) (STR_LUNAR_CHINESE_CHU)));
        mmi_wcscat(lunar_str, (WCHAR*)GetString((U16) (STR_LUNAR_CHINESE_NO1 + lunar_date->LunarDay - 1)));
    }
    else if (lunar_date->LunarDay < 20)
    {
        mmi_wcscat(lunar_str, (WCHAR*)GetString(STR_LUNAR_CHINESE_NO10));
        if (lunar_date->LunarDay > 10)
        {
            mmi_wcscat(lunar_str, (WCHAR*)GetString((U16) (STR_LUNAR_CHINESE_NO1 + lunar_date->LunarDay % 10 - 1)));
        }
    }
    else if(lunar_date->LunarDay == 20)
    {
        mmi_wcscat(lunar_str, (WCHAR*)GetString(STR_LUNAR_CHINESE_NO2));
        mmi_wcscat(lunar_str, (WCHAR*)GetString(STR_LUNAR_CHINESE_NO10));
    }
    else if (lunar_date->LunarDay < 30)
    {
        mmi_wcscat(lunar_str, (WCHAR*)GetString(STR_LUNAR_CHINESE_NO20));
        mmi_wcscat(lunar_str, (WCHAR*)GetString((U16) (STR_LUNAR_CHINESE_NO1 + lunar_date->LunarDay % 10 - 1)));
    }
    else
    {
        mmi_wcscat(lunar_str, (WCHAR*)GetString(STR_LUNAR_CHINESE_NO30));
    }

    /* Solar Term */
  /*  if (lunar_date->SolarTerm != 0)
    {
        mmi_ucs2cat(lunar_str, " ");
        mmi_ucs2cat(
            lunar_str,
            GetString((U16) (STR_LUNAR_SOLARTERM1 + lunar_date->SolarTerm)));
    }*/
}


static void mmi_lunar_show_lunar_screen(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
	WCHAR  lunar_str[40] = {0};
	int str_len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            GRP_ID_LUNAR_MAIN, 
            SCR_ID_LUNAR_QUERY_INFO, 
            NULL, 
            (FuncPtr)mmi_lunar_show_lunar_screen, 
            MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        kal_wsprintf(lunar_str,"%d/%02d/%02d\n",g_lunar_cntx.clndr_date.SolarYear,
                             g_lunar_cntx.clndr_date.SolarMonth,
                             g_lunar_cntx.clndr_date.SolarDay);
        
        str_len = kal_wstrlen(lunar_str);

        mmi_lunar_date_output_str(&g_lunar_cntx.clndr_date, lunar_str + str_len);

        ShowCategory74Screen(
            NULL,
            NULL,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            NULL,
            NULL,
            (char*)lunar_str,
            kal_wstrlen(lunar_str)+1,
            gui_buffer);

        SetLeftSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
}


static void mmi_festival_highlight_select_hdlr(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_lunar_cntx.highlight_idx)
    {
        case SPRING_FESTIVAL:
        case LANTERN_FESTIVAL:
        case DRAGON_BOAT_FESTIVAL:
        case DOUBLE_SEVENTH_DAY:
        case MID_AUTUMN_FESTIVAL:
        case DOUBLE_NINTH_DAY:
            mmi_lunar_festival_query(g_lunar_cntx.clndr_date.SolarYear,
                                           g_lunar_cntx.highlight_idx,
                                           &g_lunar_cntx.clndr_date);
            break;   
        case NEW_YEARS_DAY:
        case INTERNATION_WOMEN_DAY:
        case INTERNATION_LABOUR_DAY:
        case INTERNATION_CHILDRENS_DAY:
        case NATIONAL_DAY:
            mmi_solar_festival_query(g_lunar_cntx.clndr_date.SolarYear,
                               g_lunar_cntx.highlight_idx,
                               &g_lunar_cntx.clndr_date);
            break;
    }
    mmi_lunar_show_lunar_screen(NULL);   
}


static void mmi_solar_terms_highlight_select_hdlr(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_solar_terms_query(g_lunar_cntx.clndr_date.SolarYear,
                                g_lunar_cntx.highlight_idx,
                                &g_lunar_cntx.clndr_date);
    
    mmi_lunar_show_lunar_screen(NULL);  

}


static void mmi_lunar_entry_festival_screen(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U8* title_str[SOLAR_FESTIVAL_TOTAL];
    int i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            GRP_ID_LUNAR_SELECT_YEAR, 
            SCR_ID_LUNAR_FESTIVALS, 
            NULL, 
            (FuncPtr)mmi_lunar_entry_festival_screen, 
            MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf(); 
        RegisterHighlightHandler(mmi_lunar_festival_highlight_hdlr);

        for(i = 0; i < SOLAR_FESTIVAL_TOTAL; i++)
        {
           title_str[i] = GetString(STR_LUNAR_NEW_YEARS_DAY + i);
        }
        
        ShowCategory6Screen(
            NULL,
            NULL,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            SOLAR_FESTIVAL_TOTAL,
            title_str,
            NULL,
            0,
            gui_buffer);

        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetLeftSoftkeyFunction(mmi_festival_highlight_select_hdlr, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_festival_highlight_select_hdlr, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
}



static void mmi_lunar_entry_solar_terms_screen(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U8* title_str[SOLAR_TERM_TOTAL];
    int i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            GRP_ID_LUNAR_SELECT_YEAR, 
            SCR_ID_LUNAR_SOLAR_TERMS, 
            NULL, 
            (FuncPtr)mmi_lunar_entry_solar_terms_screen, 
            MMI_FRM_FULL_SCRN))
    {    
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
        RegisterHighlightHandler(mmi_lunar_highlight_hdlr);

        for(i = 0; i < SOLAR_TERM_TOTAL; i++)
        {
           title_str[i] = GetString(STR_LUNAR_SOLARTERM1 + i);
        }
        
        ShowCategory6Screen(
            NULL,
            NULL,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            SOLAR_TERM_TOTAL,
            title_str,
            NULL,
            0,
            gui_buffer);
        
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetLeftSoftkeyFunction(mmi_solar_terms_highlight_select_hdlr, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_solar_terms_highlight_select_hdlr, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_lunar_jump_date_proc
 * DESCRIPTION
 *  Exit function of task view all application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_lunar_jump_date_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_item_date_time_struct date;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
           cui_inline_get_value(
                mmi_lunar_jump_to_date_gid, 
                CUI_INLINE_ITEM_ID_BASE + 1, 
                &date);
            g_lunar_cntx.clndr_date.SolarYear = date.year;
            g_lunar_cntx.clndr_date.SolarMonth = date.month;
            g_lunar_cntx.clndr_date.SolarDay = date.day;
            
            mmi_lunar_solar2lunar(&g_lunar_cntx.clndr_date);
            mmi_lunar_show_lunar_screen(NULL);           
            break;
            
        case EVT_ID_CUI_INLINE_ABORT:
            mmi_frm_group_close(GRP_ID_LUNAR_JUMP_DATE);
            break;
            
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
            break;
            
        case EVT_ID_GROUP_DEINIT:
            break;
            
        case EVT_ID_GROUP_FOCUSED:
            break;
        default:
            break;
    }
 
    return MMI_RET_OK;    
}


static mmi_ret mmi_lunar_select_year_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_item_date_time_struct date;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
            
           cui_inline_get_value(
                mmi_lunar_select_year_gid, 
                CUI_INLINE_ITEM_ID_BASE + 1, 
                &date);
            g_lunar_cntx.clndr_date.SolarYear = date.year;
            if((int)evt->user_data == TERMS_QUERY)
            {
                mmi_lunar_entry_solar_terms_screen(NULL);
            }
    
            else if((int)evt->user_data == FESTIVAL_QUERY)
            {    
                mmi_lunar_entry_festival_screen(NULL);  
            }
             
            break;
            
        case EVT_ID_CUI_INLINE_ABORT:
            mmi_frm_group_close(GRP_ID_LUNAR_SELECT_YEAR);
            break;
            
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
            break;
            
        case EVT_ID_GROUP_DEINIT:
            break;
            
        case EVT_ID_GROUP_FOCUSED:
            break;
        default:
            break;
    }
 
    return MMI_RET_OK;    
}


static void mmi_lunar_entry_jump_date_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/      
    cui_inline_struct inline_data;
    cui_inline_item_date_time_struct date; 
    MYTIME currTime;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(
                    GRP_ID_LUNAR_MAIN,
                    GRP_ID_LUNAR_JUMP_DATE,
                    mmi_lunar_jump_date_proc,
                    NULL);
    mmi_frm_group_enter(
                    GRP_ID_LUNAR_JUMP_DATE,
                    MMI_FRM_NODE_SMART_CLOSE_FLAG);

    inline_data.items_count = 2;
    inline_data.title = STR_LUNAR_LUNAR_QUERY;
    inline_data.title_icon = GetRootTitleIcon(ORGANIZER_LUNAR_QUERY_MENU);
    inline_data.screen_flag = CUI_INLINE_SCREEN_DISABLE_DONE;
    inline_data.softkey = NULL;
    inline_data.items = cui_lunar_jump_to_date;

    mmi_lunar_jump_to_date_gid = cui_inline_create(
                                        GRP_ID_LUNAR_JUMP_DATE,
                                        &inline_data);

    if (mmi_lunar_jump_to_date_gid != GRP_ID_INVALID)
    {    
		GetDateTime(&currTime);
        date.year = currTime.nYear;
        date.month = currTime.nMonth;
        date.day = currTime.nDay;
        
        cui_inline_set_value(
                mmi_lunar_jump_to_date_gid, 
                CUI_INLINE_ITEM_ID_BASE + 1, 
                &date);
        cui_inline_run(mmi_lunar_jump_to_date_gid);
    }
    else
    {
        mmi_frm_group_close(GRP_ID_LUNAR_JUMP_DATE);
    }
}


static void mmi_lunar_entry_select_year_screen(LUNAR_MENU_ITEM_ENUM highlight_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/     
    cui_inline_struct inline_data;
    MYTIME currTime;
	cui_inline_item_date_time_struct date;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(
                    GRP_ID_LUNAR_MAIN,
                    GRP_ID_LUNAR_SELECT_YEAR,
                    mmi_lunar_select_year_proc,
                    (void*)highlight_idx);
    mmi_frm_group_enter(
                    GRP_ID_LUNAR_SELECT_YEAR,
                    MMI_FRM_NODE_SMART_CLOSE_FLAG);

    inline_data.items_count = 2;
    if(highlight_idx == FESTIVAL_QUERY)
    {
        inline_data.title = STR_LUNAR_FESTIVAL_QUERY;
    }
    else
    {
        inline_data.title = STR_LUNAR_SOLAR_TERMS_QUERY;
    }
    inline_data.title_icon = GetRootTitleIcon(ORGANIZER_LUNAR_QUERY_MENU);
    inline_data.screen_flag = CUI_INLINE_SCREEN_DEFAULT_TEXT;
    inline_data.softkey = NULL;
    inline_data.items = cui_lunar_select_year;

    mmi_lunar_select_year_gid = cui_inline_create(
                                        GRP_ID_LUNAR_SELECT_YEAR,
                                        &inline_data);  
    if (mmi_lunar_select_year_gid != GRP_ID_INVALID)
    {    
		GetDateTime(&currTime);     
        date.year = currTime.nYear;
        
        cui_inline_set_item_attributes(mmi_lunar_select_year_gid, 
               CUI_INLINE_ITEM_ID_BASE + 1,
               CUI_INLINE_SET_ATTRIBUTE,
               CUI_INLINE_ITEM_YEAR_ONLY);
		cui_inline_set_screen_attributes(mmi_lunar_select_year_gid, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_SCREEN_DISABLE_DONE);
	    cui_inline_set_value(
                mmi_lunar_select_year_gid, 
                CUI_INLINE_ITEM_ID_BASE + 1, 
                &date);
        cui_inline_run(mmi_lunar_select_year_gid);
    }
    else
    {
        mmi_frm_group_close(GRP_ID_LUNAR_SELECT_YEAR);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_lunar_query_select_hdlr
 * DESCRIPTION
 *  lunar menu items select handler
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_lunar_query_select_hdlr(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_lunar_cntx.highlight_idx)
    {
        case LUNAR_QUERY:
            mmi_lunar_entry_jump_date_screen();
            break;
        case FESTIVAL_QUERY:
            mmi_lunar_entry_select_year_screen(FESTIVAL_QUERY);
            break;
        case TERMS_QUERY:
            mmi_lunar_entry_select_year_screen(TERMS_QUERY);
            break;         
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_lunar_entry_main_screen
 * DESCRIPTION
 *  show lunar main menu.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_lunar_entry_main_screen(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U16 img_list[LUNAR_ITEM_TOTAL];
    U8* title_str[LUNAR_ITEM_TOTAL];
    int i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            scrn_data->group_id, 
            SCR_ID_LUNAR_MAIN_SCREEN, 
            NULL, 
            (FuncPtr)mmi_lunar_entry_main_screen, 
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    for(i = 0; i < LUNAR_ITEM_TOTAL; i++)
    {
       img_list[i] = IMG_GLOBAL_L1 + i;
       title_str[i] = GetString(STR_LUNAR_LUNAR_QUERY + i);
    }
    RegisterHighlightHandler(mmi_lunar_highlight_hdlr);     
    ShowCategory53Screen(
        NULL,
        NULL,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        LUNAR_ITEM_TOTAL,
        title_str,
        img_list,
        NULL,
        0,
        0,
        gui_buffer);
    
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetLeftSoftkeyFunction(mmi_lunar_query_select_hdlr, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_lunar_query_select_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryLunarQueryMenu
 * DESCRIPTION
 *  Entry lunar main menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryLunarQueryMenu(void)
{
    /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
    
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     mmi_frm_group_create(
                 GRP_ID_ROOT,
                 GRP_ID_LUNAR_MAIN, 
                 NULL,
                 &g_lunar_cntx);
    
     mmi_frm_group_enter(GRP_ID_LUNAR_MAIN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
     mmi_frm_scrn_first_enter(
            GRP_ID_LUNAR_MAIN, 
            SCR_ID_LUNAR_MAIN_SCREEN, 
            mmi_lunar_entry_main_screen, 
            NULL);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightLunarQueryMenu
 * DESCRIPTION
 *  Highlight handler of Lunar query menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightLunarQueryMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetLeftSoftkeyFunction(EntryLunarQueryMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(EntryLunarQueryMenu, KEY_EVENT_UP);  
}


void mmi_lunar_query_shct_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __DISABLE_SHORTCUTS_IMPL__
        if(!IsChineseSet())
        {
            mmi_shct_dynamic_register(ORGANIZER_LUNAR_QUERY_MENU, MMI_FALSE);
        }
        else
        {
            mmi_shct_dynamic_register(ORGANIZER_LUNAR_QUERY_MENU, MMI_TRUE);
        }         
#endif  /* __DISABLE_SHORTCUTS_IMPL__ */
}

#endif /*__MMI_LUNAR_QUERY__*/


