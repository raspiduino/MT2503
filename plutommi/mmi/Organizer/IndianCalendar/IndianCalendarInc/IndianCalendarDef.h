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
 * IndianCalendarDefs.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines constant, enum value, structure for 
 * Indian Calendar application.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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

#ifndef INDICAL_DEFS_H

#define INDICAL_DEFS_H

#include "MMI_features.h"
#include "MMIDataType.h"

//RHR add begin

#include "custom_mmi_default_value.h"

//RHR add end

/*---------------------------------------------------------------------------*/
/* Definition */
/*---------------------------------------------------------------------------*/
#define     INDICAL_MAX_OPTIONS                     4
#define     INDICAL_MAX_TITHI_OPTIONS               4
#define     INDICAL_MAX_OSD_OPTIONS                 3
#define     MAX_FESTIVALS                           MMI_INDICAL_MAX_FIX_DATE_FESTIVALS + MMI_INDICAL_MAX_VARI_DATE_FESTIVALS

#define     MAX_FESTIVAL_NAME_LENGTH                26
#define     MAX_FESTIVAL_DISPLAY                    10

#define     MAX_TITHI_VALUES                        16
#define     INDICAL_MAX_DATE_SIZE                   12
#define     MAX_TITHI_PER_YEAR                      28

#define     MAX_LEN_STR_INDIAN_DATE                 200
#define    MAX_LEN_FEST_DESC                        600
#define     INDICAL_START_YEAR                      2000
#define     INDICAL_END_YEAR                        2030
#define     INDICAL_NO_OF_YEAR_SUPPORT              INDICAL_END_YEAR - INDICAL_START_YEAR
#define     INDICAL_NO_OF_MONTHS_PER_YEAR           12
#define     INDICAL_DIFF_GREG_AND_INDIAN_YEAR       57

#define     INDICAL_GREG_DAY_LEN                    3*ENCODING_LENGTH
#define     INDICAL_GREG_MON_LEN                    3*ENCODING_LENGTH
#define     INDICAL_GREG_YEAR_LEN                   6*ENCODING_LENGTH
#define     MMI_INDICAL_NO_ADHIKA_MONTH             0xFF
#define     MMI_INDICAL_INDEX_TO_NORMAL             1

#ifndef     __MMI_INDICAL_DYNAMIC_ADHIKA_INFO_GEN__
#define     __MMI_INDICAL_DYNAMIC_ADHIKA_INFO_GEN__
#endif

/* 
 * Here we assume the maximum Year the buffer could accomodate is 99. 
 * If the requirement exceed this limit then we have to change the
 * buffer length.
 */
#define     INDICAL_FESTIVAL_DISPLAY_MAX_YEAR_BUFFER_LEN        3*ENCODING_LENGTH

#define     MAX_YEAR_VALUE                                      5*ENCODING_LENGTH

#ifndef _MMI_DATETIMEDEF_H
#define _MMI_DATETIMEDEF_H
#endif 

#define     GetDateTime(t) applib_dt_get_date_time((applib_time_struct *)t)

/*---------------------------------------------------------------------------*/
/* Enum */
/*---------------------------------------------------------------------------*/

typedef enum
{
    MMI_INDICAL_RAVIWARA,
    MMI_INDICAL_SOMAVARA,
    MMI_INDICAL_MANGALVARA,
    MMI_INDICAL_BUDHAVARA,
    MMI_INDICAL_GURUVARA,
    MMI_INDICAL_SUKRAVARA,
    MMI_INDICAL_SANIVARA,

    MMI_INDICAL_WEEKDAY_MAX
} indical_weekday_enum;

typedef enum
{
    MMI_INDICAL_CHAITRA,
    MMI_INDICAL_VAISAKHA,
    MMI_INDICAL_JYAISTHA,
    MMI_INDICAL_ASADHA,
    MMI_INDICAL_SRAVANA,
    MMI_INDICAL_BHADRAPADA,
    MMI_INDICAL_ASVINA,
    MMI_INDICAL_KARTTIKA,
    MMI_INDICAL_MARGASIRSA,
    MMI_INDICAL_PAUSA,
    MMI_INDICAL_MAGHA,
    MMI_INDICAL_PHALGUNA,

    MMI_INDICAL_MONTH_MAX
} indical_month_enum;

typedef enum
{

    MMI_INDICAL_PRATHMA = 1,
    MMI_INDICAL_DVITIYA
} indical_adhika_enum;

typedef enum
{
    MMI_INDICAL_KRISHANA_PAKSHA,
    MMI_INDICAL_SHUKLA_PAKSHA
} indical_paksha_enum;

typedef enum
{
    MMI_INDICAL_EKAM = 1,
    MMI_INDICAL_DWITIYA,
    MMI_INDICAL_TRITIYA,
    MMI_INDICAL_CHATURTHI,
    MMI_INDICAL_PANCHAMI,
    MMI_INDICAL_SASTHI,
    MMI_INDICAL_SAPTAMI,
    MMI_INDICAL_ASTHAMI,
    MMI_INDICAL_NAVMI,
    MMI_INDICAL_DASHMI,
    MMI_INDICAL_EKADASHI,
    MMI_INDICAL_DUADASHI,
    MMI_INDICAL_TRIYODASHI,
    MMI_INDICAL_CHATURDASHI,
    MMI_INDICAL_PURANMASI
} indical_tithi_day_enum;

typedef enum
{
    MMI_INDICAL_GURU_GOVIND_SINGH_JAYANTI,
    MMI_INDICAL_LOHRI,
    MMI_INDICAL_MAKAR_SAKRANTI,
    MMI_INDICAL_BAISHAKHI,

    MMI_INDICAL_MAX_FIX_DATE_FESTIVALS
} indical_fix_date_festival_enums;

typedef enum
{
    MMI_INDICAL_BASANT_PANCHMI,
    MMI_INDICAL_MAHASHIV_RATRI,
    MMI_INDICAL_HOLIKA_DEHAN,
    MMI_INDICAL_HOLI,
    MMI_INDICAL_NAV_VARSHA,
    MMI_INDICAL_RAM_NAVMI,
    MMI_INDICAL_RAKSHA_BANDHAN,
    MMI_INDICAL_JANMASTMI,
    MMI_INDICAL_GANESH_CHATURTHI,
    MMI_INDICAL_NAWMI,
    MMI_INDICAL_DASHEHRA,
    MMI_INDICAL_DEEPAWALI,

    MMI_INDICAL_MAX_VARI_DATE_FESTIVALS
} indical_vari_date_festival_enum;

/*-------------------- Structure definations --------------------------*/
typedef struct
{
    U8 yy;
    U8 mm;
    U8 dd;
} mmi_indical_gregorian_date_struct;

typedef struct
{
    U8 adhika;
    U8 month;
    U8 paksha;
    U8 tithi;
} mmi_indical_indian_date_struct;

typedef struct
{
    U8 dd1;
    U8 dd2;
} DT_SD_struct;

typedef struct
{
    U8 dd1;
    U8 dd2;
} ST_DD_struct;

typedef struct
{
    DT_SD_struct dd_st;
    ST_DD_struct st_dd;
} indical_special_tithi_struct;

typedef struct
{
    U8 tithi;
    U8 month;
} mmi_indical_base_indian_date_struct;

typedef struct
{
    U8 dd;
    U8 mm;
} indical_festivals_base_struct;

typedef struct
{
    U8 year;
    U8 prathama;
    U8 dwitiya;
} indical_adhika_month_struct;

typedef struct
{
    S16 indical_adhika_month_prefix;
} mmi_indical_info_struct;

typedef struct
{
    U8 fest_detail_str[MAX_LEN_FEST_DESC * ENCODING_LENGTH];    
    U8 indianDateString[MAX_LEN_STR_INDIAN_DATE *ENCODING_LENGTH];
    U8 popupList[MAX_FESTIVALS][11*ENCODING_LENGTH];    
    U8 title_str[(MAX_FESTIVAL_NAME_LENGTH + 4) * ENCODING_LENGTH];
    MYTIME curr_greg_time;
    mmi_indical_info_struct mmi_indical_info_struct;
    mmi_indical_indian_date_struct indianDate;
    mmi_indical_indian_date_struct indianBaseDate;
    mmi_indical_gregorian_date_struct gregorianDate;
    indical_adhika_month_struct indical_adhika_month_info_year;
    U8 indiCalFestivalHighlightIndex;
    U8 fest_disp_index[MAX_FESTIVALS];
    U8 reminder_for_indical;
    pBOOL saving_tithi_reminder;
} mmi_indical_cntx_struct;                              /* g_mmi_indical_cntx; */

extern void mmi_indical_get_indian_date(
                mmi_indical_gregorian_date_struct *,
                U8,
                mmi_indical_indian_date_struct *,
                U8 *);
extern U8 mmi_indical_get_tithi_delta(mmi_indical_gregorian_date_struct *);
extern void mmi_indical_get_tithi(mmi_indical_gregorian_date_struct *, mmi_indical_indian_date_struct *, U8);
extern void mmi_indical_increment_month_and_paksha(mmi_indical_indian_date_struct *, U8);
extern U8 mmi_indical_get_samvat_year(mmi_indical_gregorian_date_struct *);
extern U8 mmi_indical_check_for_two_tithi_same_gdate(mmi_indical_gregorian_date_struct *);
extern U8 mmi_indical_check_for_single_tithi_two_gdate(mmi_indical_gregorian_date_struct *gregorian_date);

extern void mmi_indical_get_festival(mmi_indical_gregorian_date_struct *, U8 *);
extern U8 increment_gregorian_date(MYTIME, S8, mmi_indical_gregorian_date_struct *);
extern U8 increment_gregorian_date_update_orig_date(MYTIME *, U8, mmi_indical_gregorian_date_struct *);
extern void mmi_indical_update_festival_date_for_offset(indical_festivals_base_struct *, U8, U16);
extern void mmi_indical_fill_adhika_month_array_single(indical_adhika_month_struct *indical_adhika_month, U8 year);
extern void mmi_indical_initialise_time_from_date(MYTIME *gregorian_time, mmi_indical_gregorian_date_struct indical_gregorian_date);
extern void mmi_indical_get_base_tithi(mmi_indical_indian_date_struct *indical_indian_date, U8 year, U8 month_counter);
extern U8 mmi_indical_compare_festivals_date(mmi_indical_gregorian_date_struct *indical_festival_array, U8 index, indical_festivals_base_struct indical_festival);
extern pBOOL mmi_indical_get_saving_tithi_reminder(void);
extern void mmi_indical_set_saving_tithi_reminder(pBOOL flag);

#endif /* INDICAL_DEFS_H */ 

