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
 * LunarQuery.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/**********************************************************************************
   Filename:      
   Author:        
   Date Created:  
   Contains:      
**********************************************************************************/
#ifndef _MMI_LUNARQUERY_H
#define _MMI_LUNARQUERY_H
/*********************************************************************************
 * Include
 *********************************************************************************/
#include "MMIDataType.h"


/********************************************************************************
 * Typedef 
 ********************************************************************************/
typedef struct
{
    U8 BaseDays;    /* different days from solar Jan 1 to lunar Jan 1. */
    U8 Intercalary;     /* an intercalary month in the lunar calendar.                    
                           0==no intercalary month in this year. */
    U16 MonthDays;  /* the number of days in lunar month, bit-level representation 0=29, 1=30. */
} lunar_query_info_struct;

typedef struct
{
    U16 SolarYear;                      /* year in solar calendar system. */
    U16 LunarYear;                      /* year in lunar calendar system. */
    U8 SolarMonth;                      /* month in solar calendar system. */
    U8 SolarDay;                        /* day in solar calendar system. */
    U8 LunarMonth;                      /* month in lunar calendar system. */
    U8 LunarDay;                        /* day in lunar calendar system. */
    U8 KanYear;                         /* the Kan symbol of given lunar year */
    U8 ChiYear;                         /* the Chin symbol of given lunar year */
    BOOL LeapMonth;                     /* leapMOnth == TRUE if this is a lunar leap month */
    U8 SolarTerm;                       /* the (SolarTerm)th solar term day, 0 if not any solar term day */
} lunar_date_info_struct;

typedef struct
{
    S32 highlight_idx;
    lunar_date_info_struct clndr_date;
}lunar_cntx_struct;

/********************************************************************************
 * Extern Global Struct 
 ********************************************************************************/

/* ******************************************************************************
 *
 *  0xXX >> 4                              :base 0   first solar term of a month
 * (0xXX & 0x0F) + 16                      :base 16  second solar term of a month
 *  eg: cmcc_solar_term_table[0][0] = 0x64
 *       0x64 >> 4 = 6;                    :first term of january 1970 is 6th day
 *      (0x64 & 0x0F) + 16 = 20            :second term of january 1970 is 20th day
 *
 ********************************************************************************/
extern const U8 solar_terms_table[][12];

extern const lunar_query_info_struct gLunarQueryInfo[];


/********************************************************************************
 * Extern Global Function 
 ********************************************************************************/
extern void EntryLunarQueryMenu(void);
extern void HighlightLunarQueryMenu(void);
extern void mmi_lunar_query_shct_icon(void);
extern void mmi_lunar_solar2lunar(lunar_date_info_struct *clndr_date);
extern void mmi_lunar_lunar2solar(lunar_date_info_struct *clndr_date);
extern void mmi_lunar_date_output_str(lunar_date_info_struct *lunar_date, WCHAR* lunar_str);

#endif /* _MMI_LUNARQUERY_H */


