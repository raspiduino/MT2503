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
 * DateAndTime.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for date/time setting application
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
/*
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : DateAndTime.c

   PURPOSE     : nil

   REMARKS     : nil

   AUTHOR      : Gurinder Singh Chhabra

   DATE     : Oct 24, 2003

**************************************************************/
#ifndef _DATEANDTIME_C
#define _DATEANDTIME_C

/*  Include: MMI header file */
#include "MMI_features.h"
#include "AlarmFrameworkProt.h"
#include "wgui_datetime.h"
#include "ProtocolEvents.h"
#include "settingstructs.h"
#include "SettingsGexdcl.h"
#include "settingprot.h"
#include "ProtocolEvents.h"
#include "worldclock.h"
#include "AlarmGprot.h"
#include "DateTimeGprot.h"
#include "ProfilesSrvGprot.h"
#include "PhoneSetup.h"
#include "Menucuigprot.h"
#include "Inlinecuigprot.h"
#include "ATHandlerProt.h"
#ifdef __MMI_TDL_NITZ_SUPPORT__
#include "TodolistSrvGprot.h"
#endif
#if 0
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/* under construction !*/
#endif
#endif

#include "WorldClockCuiGprot.h"

/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_phonesetting_new_def.h"
#include "custom_mmi_default_value.h"
#include "mmi_rp_app_worldclock_def.h"
#include "ps_public_struct.h"
#include "GlobalConstants.h"
#include "mmi_frm_scenario_gprot.h"
#include "DateTimeType.h"
#include "app_datetime.h"
#include "mmi_frm_nvram_gprot.h"
#include "string.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "AlertScreen.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "stack_msgs.h"
#include "mmi_msg_struct.h"
#include "device.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "wgui_categories_sublcd.h"
#include "gui_data_types.h"
#include "Unicodexdcl.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "PixcomFontEngine.h"
#include "wgui_inputs.h"
#include "mmi_frm_history_gprot.h"
#include "stack_config.h"
#include "SettingDefs.h"
#include "mmi_rp_app_nitz_def.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "CustMenuRes.h"
#include "stdio.h"
/* auto add by kw_check end */
#include "SettingGprots.h"
#include "PhoneSetupGprots.h"
/*  Include: PS header file */
#include "IdleGprot.h"
#include "MMI_ap_dcm_config.h"

#ifdef __MMI_BTD_BOX_UI_STYLE__
#include "wgui_categories_btbox.h"
#endif
/* 
 * Define
 */
#define NUM_CITYS (NUMBER_OF_CITY-1)
#define MAX_CITY_NUM 100

typedef enum
{
#ifndef __MMI_HIDE_HOMECITY__
    PHNSET_DT_MNU_HOMECT,
#endif
#ifdef __MMI_DUAL_CLOCK__
	PHNSET_DT_MNU_FOREIGN_CITY,
#endif

#if 0
#ifndef __MMI_SEPARATE_DT_SETTING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_SEPARATE_DT_SETTING__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SEPARATE_DT_SETTING__ */ 
#else
	PHNSET_DT_MNU_DT,
    PHNSET_DT_MNU_DATEANDFORMAT = PHNSET_DT_MNU_DT,
    PHNSET_DT_MNU_FMT,
    PHNSET_DT_MNU_TIMEANDFORMAT = PHNSET_DT_MNU_FMT,
#endif
	PHNSET_DT_MNU_SEP,			/* date seperator */
	
#if 0	
#if (defined(__MMI_NITZ__) && defined(__MMI_AUTOTIMEZONE_IN_DATEANDTIME__))
/* under construction !*/
#endif 
#else
#if defined(__MMI_NITZ__) 
    PHNSET_DT_MNU_NITZ,
#endif 
#endif 

    PHNSET_DT_MNU_LAST
} phnset_DT_menu_enum;

#if !defined(__MMI_HIDE_HOMECITY__) && defined(__MMI_TWO_LAYER_HOMECITY__)
typedef struct
{
    FLOAT CityTimeZone; /* time difference */
    U16 CityName;       /* city name in English. */
    U8 tzdata_index;
} GMT_TZ_STRUCT;
#endif /* !defined(__MMI_HIDE_HOMECITY__) && defined(__MMI_TWO_LAYER_HOMECITY__) */

#ifndef YEARFORMATE
#define YEARFORMATE 2000
#endif 
#if 0
#ifndef __MMI_OP11_HOMESCREEN__
#ifdef __MMI_AP_DCM_SETTING__
/* under construction !*/
#endif
#endif
#else
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
#endif
/* Set date and time */
#ifndef __MMI_MAINLCD_96X64__
#define SET_DATE_AND_TIME_SET_TIME_CAPTION (CUI_INLINE_ITEM_ID_BASE + 1)
#endif
#define SET_DATE_AND_TIME_SET_TIME    (CUI_INLINE_ITEM_ID_BASE + 2)
#ifndef __MMI_MAINLCD_96X64__
#define SET_DATE_AND_TIME_SET_DATE_CAPTION (CUI_INLINE_ITEM_ID_BASE + 3)
#endif
#define SET_DATE_AND_TIME_SET_DATE    (CUI_INLINE_ITEM_ID_BASE + 4)
#ifdef __MMI_MAINLCD_96X64__
  #define SET_DATE_AND_TIME_SHOW_DATE_TIME_SELECT (CUI_INLINE_ITEM_ID_BASE + 6)
#else
#ifndef __MMI_PHNSET_DAYLIGHT_SAVING_DISABLE__
  #ifndef __MMI_MAINLCD_96X64__
     #define SET_DATE_AND_TIME_DAYLIGHT_SAVING_CAPTION (CUI_INLINE_ITEM_ID_BASE + 5)
  #endif
    #define SET_DATE_AND_TIME_DAYLIGHT_SAVING_SELECT  (CUI_INLINE_ITEM_ID_BASE + 6)
 #endif
#endif
#ifdef __MMI_BTD_BOX_UI_STYLE__
#define SET_DATE_AND_TIME_SET_YEAR_CAPTION (CUI_INLINE_ITEM_ID_BASE + 7)
#define SET_DATE_AND_TIME_SET_YEAR    (CUI_INLINE_ITEM_ID_BASE + 8)
#define SET_DATE_AND_TIME_SET_MONTH_AND_DAY_CAPTION (CUI_INLINE_ITEM_ID_BASE + 9)
#define SET_DATE_AND_TIME_SET_MONTH_AND_DAY    (CUI_INLINE_ITEM_ID_BASE + 10)
#endif  //__MMI_BTD_BOX_UI_STYLE__
#if 0
#ifndef __MMI_OP11_HOMESCREEN__
#ifdef __MMI_AP_DCM_SETTING__
/* under construction !*/
#endif
#endif
#else
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
#endif

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/* Set date and time format */
#ifndef __MMI_MAINLCD_96X64__
#define SET_FORMAT_TIME_FORMAT_CAPTION        (CUI_INLINE_ITEM_ID_BASE + 1)
#endif
#define SET_FORMAT_TIME_FORMAT_SELECT         (CUI_INLINE_ITEM_ID_BASE + 2)
#ifndef __MMI_MAINLCD_96X64__
#define SET_FORMAT_DATE_FORMAT_CAPTION        (CUI_INLINE_ITEM_ID_BASE + 3)
#endif
#define SET_FORMAT_DATE_FORMAT_SELECT         (CUI_INLINE_ITEM_ID_BASE + 4)
#ifndef __MMI_PHNSET_DATE_SEPARATOR_DISABLE__
#define SET_FORMAT_DATE_SEPARATOR_CAPTION        (CUI_INLINE_ITEM_ID_BASE + 5)
#define SET_FORMAT_DATE_SEPARATOR_SELECT         (CUI_INLINE_ITEM_ID_BASE + 6)
#endif
#if 0
#ifdef __MMI_SEPARATE_DT_SETTING__
/* under construction !*/
#ifndef __MMI_MAINLCD_96X64__
/* under construction !*/
#endif
/* under construction !*/
#ifndef __MMI_MAINLCD_96X64__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#ifndef __MMI_MAINLCD_96X64__
/* under construction !*/
#endif
/* under construction !*/
#ifndef __MMI_MAINLCD_96X64__
/* under construction !*/
#endif
/* under construction !*/
#ifndef __MMI_PHNSET_DAYLIGHT_SAVING_DISABLE__
#ifndef __MMI_MAINLCD_96X64__
/* under construction !*/
#endif
/* under construction !*/
#endif
#endif
#endif
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif 
/* 
 * Typedef 
 */

/* 
 * Local Variable
 */
#ifdef __MMI_TIMEZONE_SETTING__ 
static U8 *homeCityDataPtr[MAX_CITY_NUM];

#if !defined(__MMI_HIDE_HOMECITY__) && defined(__MMI_TWO_LAYER_HOMECITY__)
static U8 gmt_tz_str_buf[MAX_CITY_NUM][70];
static U8 gmt_tz_table[MAX_CITY_NUM];
#endif /* !defined(__MMI_HIDE_HOMECITY__) && defined(__MMI_TWO_LAYER_HOMECITY__) */
#endif

#if 0
#ifndef __MMI_OP11_HOMESCREEN__
#ifdef __MMI_AP_DCM_SETTING__
/* under construction !*/
#endif
#endif
#else
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
#endif
static const U16 g_phnset_dt_on_off_str_id[] = {STR_GLOBAL_OFF, STR_GLOBAL_ON};
static const U16 g_time_format_str_id[] = {STR_12, STR_24};
static const U16 g_date_format_str_id[] = {STR_ID_DD_MM_YYYY_S, STR_ID_MM_DD_YYYY_S, STR_ID_YYYY_MM_DD_S};
#ifndef __MMI_BTD_BOX_UI_STYLE__
static const cui_inline_item_time_struct g_phnset_date_and_time_common_inline_time = 
{
    {0, 0, 0, 0, 0, 0},
    0
};
#endif  //__MMI_BTD_BOX_UI_STYLE__

#ifndef __MMI_MAINLCD_96X64__
static const cui_inline_item_caption_struct g_phnset_set_date_time_caption1 = {STR_ENTER_TIME_FORMAT_DISP_CAPTION};
static const cui_inline_item_caption_struct g_phnset_set_date_time_caption2 = {STR_ENTER_DATE_FORMAT_DISP_CAPTION};
static const cui_inline_item_caption_struct g_phnset_set_date_time_caption3 = {STR_ID_PHNSET_SET_DST};
#ifdef __MMI_BTD_BOX_UI_STYLE__
static const cui_inline_item_caption_struct g_phnset_set_date_time_caption4 = {STR_ENTER_YEAR_FORMAT_DISP_CAPTION};
static const cui_inline_item_caption_struct g_phnset_set_date_time_caption5 = {STR_ENTER_MONTH_AND_DAY_FORMAT_DISP_CAPTION};
#endif
#endif
static const cui_inline_item_select_struct g_phnset_set_date_time_select1 = 
{
    2, /* Power on and Power off */
    0,
    g_phnset_dt_on_off_str_id
};
#ifndef __MMI_MAINLCD_96X64__
static const cui_inline_set_item_struct g_phnset_set_date_time_data[] =
{
#ifdef __MMI_BTD_BOX_UI_STYLE__
    {SET_DATE_AND_TIME_SET_TIME_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, NULL, &g_phnset_set_date_time_caption1},
    {SET_DATE_AND_TIME_SET_TIME, CUI_INLINE_ITEM_TYPE_DATETIME_SETTING_DISPLAY_ONLY, 0, NULL},
    {SET_DATE_AND_TIME_SET_YEAR_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, NULL, &g_phnset_set_date_time_caption4},
    {SET_DATE_AND_TIME_SET_YEAR, CUI_INLINE_ITEM_TYPE_DATETIME_SETTING_DISPLAY_ONLY, 0, NULL},
    {SET_DATE_AND_TIME_SET_MONTH_AND_DAY_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, NULL, &g_phnset_set_date_time_caption5},
    {SET_DATE_AND_TIME_SET_MONTH_AND_DAY, CUI_INLINE_ITEM_TYPE_DATETIME_SETTING_DISPLAY_ONLY, 0, NULL},
#else  //__MMI_BTD_BOX_UI_STYLE__
    {SET_DATE_AND_TIME_SET_TIME_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, NULL, &g_phnset_set_date_time_caption1},
    {SET_DATE_AND_TIME_SET_TIME, CUI_INLINE_ITEM_TYPE_TIME | CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT, 0, &g_phnset_date_and_time_common_inline_time},
    {SET_DATE_AND_TIME_SET_DATE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, NULL, &g_phnset_set_date_time_caption2},
    {SET_DATE_AND_TIME_SET_DATE, CUI_INLINE_ITEM_TYPE_DATE | CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT, 0, &(g_phnset_date_and_time_common_inline_time.date_time)},
#endif  //__MMI_BTD_BOX_UI_STYLE__
#ifndef __MMI_PHNSET_DAYLIGHT_SAVING_DISABLE__
    {SET_DATE_AND_TIME_DAYLIGHT_SAVING_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, NULL, &g_phnset_set_date_time_caption3},
    {SET_DATE_AND_TIME_DAYLIGHT_SAVING_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &g_phnset_set_date_time_select1}        
#endif
};
#else
static const cui_inline_set_item_struct g_phnset_set_date_time_data[] =
{
    {SET_DATE_AND_TIME_SET_TIME, CUI_INLINE_ITEM_TYPE_TIME | CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT, 0, &g_phnset_date_and_time_common_inline_time},
    {SET_DATE_AND_TIME_SET_DATE, CUI_INLINE_ITEM_TYPE_DATE | CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT, 0, &(g_phnset_date_and_time_common_inline_time.date_time)},    
    {SET_DATE_AND_TIME_SHOW_DATE_TIME_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &g_phnset_set_date_time_select1} 
};
#endif
static const cui_inline_struct g_phnset_set_date_time_inline =
{
    sizeof(g_phnset_set_date_time_data) / sizeof(cui_inline_set_item_struct),
    STR_ID_PHNSET_SET_DT,
    NULL,
#ifdef __MMI_BTD_BOX_UI_STYLE__
    CUI_INLINE_SCREEN_DEFAULT_TEXT,
#else
    CUI_INLINE_SCREEN_DEFAULT_TEXT | CUI_INLINE_SCREEN_DISABLE_DONE,
#endif
    NULL,
    g_phnset_set_date_time_data
};
#if 0
#ifndef __MMI_OP11_HOMESCREEN__
#ifdef __MMI_AP_DCM_SETTING__
/* under construction !*/
#endif
#endif
#else
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif 
#endif 

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/* Set date and time format */
static const U16 g_date_sep_str_id[] = {STR_DT_SEP_DOT, STR_DT_SEP_COLON, STR_DT_SEP_SLOPE, STR_DT_SEP_LINE};
#ifndef __MMI_MAINLCD_96X64__
static const cui_inline_item_caption_struct g_phnset_set_format_caption1 = {STR_GLOBAL_TIME};
#endif
static const cui_inline_item_select_struct g_phnset_set_format_select1 = 
{
    2, /* 12 and 24 */
    0,
    g_time_format_str_id
};
#ifndef __MMI_MAINLCD_96X64__
static const cui_inline_item_caption_struct g_phnset_set_format_caption2 ={STR_GLOBAL_DATE};
#endif
static const cui_inline_item_select_struct g_phnset_set_format_select2 = 
{
    3,  
    0,
    g_date_format_str_id
};
#ifndef __MMI_MAINLCD_96X64__
static const cui_inline_item_caption_struct g_phnset_set_format_caption3 ={STR_ID_PHNSET_SET_DATE_SEP};
#endif
static const cui_inline_item_select_struct g_phnset_set_format_select3 = 
{
    4,  
    0,
    g_date_sep_str_id
};
#ifndef __MMI_MAINLCD_96X64__
static const cui_inline_set_item_struct g_phnset_set_format_data[] =
{
    {SET_FORMAT_TIME_FORMAT_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, NULL, &g_phnset_set_format_caption1},
    {SET_FORMAT_TIME_FORMAT_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &g_phnset_set_format_select1},
    {SET_FORMAT_DATE_FORMAT_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, NULL, &g_phnset_set_format_caption2},
    {SET_FORMAT_DATE_FORMAT_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &g_phnset_set_format_select2},    
#ifndef __MMI_PHNSET_DATE_SEPARATOR_DISABLE__
    {SET_FORMAT_DATE_SEPARATOR_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, NULL, &g_phnset_set_format_caption3},
    {SET_FORMAT_DATE_SEPARATOR_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &g_phnset_set_format_select3}        
#endif
};
#else 
static const cui_inline_set_item_struct g_phnset_set_format_data[] =
{
    {SET_FORMAT_TIME_FORMAT_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &g_phnset_set_format_select1},
    {SET_FORMAT_DATE_FORMAT_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &g_phnset_set_format_select2},          
};
#endif
static const cui_inline_struct g_phnset_set_format_inline =
{
    sizeof(g_phnset_set_format_data) / sizeof(cui_inline_set_item_struct),
    STR_MENU9144_SETTIMEANDDATEFORMAT,
    NULL,
    CUI_INLINE_SCREEN_DEFAULT_TEXT | CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    g_phnset_set_format_data
};
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif



#if 0
#ifndef __MMI_OP11_HOMESCREEN__
#ifdef __MMI_AP_DCM_SETTING__
/* under construction !*/
#endif
#endif
#ifdef __MMI_SEPARATE_DT_SETTING__
/* under construction !*/
#ifndef __MMI_MAINLCD_96X64__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_MAINLCD_96X64__
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
#ifndef __MMI_MAINLCD_96X64__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_MAINLCD_96X64__
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_MAINLCD_96X64__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_PHNSET_DAYLIGHT_SAVING_DISABLE__
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#else
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
#endif
#ifndef __MMI_OP11_HOMESCREEN__
#ifdef __MMI_AP_DCM_SETTING__
/* under construction !*/
#endif 
#endif
/* under construction !*/
#endif
/* 
 * Global Variable
 */
#if 0
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif
#endif
/* 
 * Global Function
 */
#if !defined(__MMI_HIDE_HOMECITY__) && defined(__MMI_TWO_LAYER_HOMECITY__)
static void mmi_dt_get_gmt_tz_string(U8 *result, FLOAT timezone);
static void mmi_dt_gmt_tz_list(void);
static S32 mmi_dt_gmt_tz_get_hilite(U8 cityindex);
#endif /* !defined(__MMI_HIDE_HOMECITY__) && defined(__MMI_TWO_LAYER_HOMECITY__) */

#ifdef __MMI_TIMEZONE_CHANGE_DATETIME__
extern void mmi_dt_tz_update_datetime(S16 newTimeZone);
static void EntryPhnsetDateTimeUpdate(MMI_ID parent_gid);
static mmi_ret mmi_phnset_change_date_time_proc(mmi_event_struct *param);
static void mmi_phnset_init_change_date_time_list(void);
#endif

extern void Category53ChangeItemDescription(S32 index, U8 *text);
extern void DateTimerProc(void);

extern FLOAT GetTimeZone(U8 cityIndex);

#ifdef __MMI_DUAL_CLOCK__
extern U8 PhnsetGetForeignCity(void);
#ifndef __MMI_HIDE_HOMECITY__
extern void PhnsetSetForeignCity(void);
#endif /* __MMI_HIDE_HOMECITY__ */
#endif /* __MMI_DUAL_CLOCK__ */

/* Local Function */

static void EntryPhnsetSetFormat(MMI_ID parent_gid);
static mmi_ret mmi_phnset_set_format_proc(mmi_event_struct *param);
static void PhnsetSetFormat(MMI_ID inline_cui_gid);
static void PhnsetSetDT(MMI_ID inline_cui_gid);
#if 0
#ifdef __MMI_SEPARATE_DT_SETTING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
#endif 
/* AT handler */
#ifndef __MMI_PHNSET_AT_DISABLE__
static void ATSetRTC(void *msg, int mod_id);
static MMI_BOOL PhnsetSetDTFromAT(const MYTIME *mytime);
#endif
static void PhnsetConstructCityList(void);

static void PhnsetHCMultiTapHdlr(UI_character_type inp);
static void PhnsetSetTimeResHdlr(MMI_BOOL result, void *user_data);
static MYTIME mmi_phnset_date_and_time_inline_time_to_mytime(cui_inline_item_time_struct *inline_time);
static cui_inline_item_time_struct mmi_phnset_date_and_time_mytime_to_inline_time(const MYTIME *time);
static void mmi_phnset_date_and_time_init_format(void);
#ifndef __MMI_PHNSET_DAYLIGHT_SAVING_DISABLE__  
static void mmi_phnset_date_and_time_dst_changed_handler(U8 select_dst, cui_inline_item_time_struct *inline_time);
#endif
static mmi_ret mmi_phnset_time_and_date_sub_menu_select_handler(cui_menu_event_struct *param, MMI_ID parent_gid);
static mmi_ret mmi_phnset_time_and_date_sub_menu_entry_handler(cui_menu_event_struct *param, MMI_ID parent_gid);
static void mmi_phnset_init_time_and_date(void);
static void mmi_phnset_entry_set_date_and_time(MMI_ID parent_gid);
static mmi_ret mmi_phnset_set_date_time_proc(mmi_event_struct *param);
#ifndef __MMI_HIDE_HOMECITY__
static void mmi_phnset_entry_set_home_city(MMI_ID parent_gid);
static void mmi_phnset_entry_set_home_city_int(mmi_scrn_essential_struct *scrn_data);
#ifdef __MMI_WC_TZ_SUPPORT__
static void mmi_phnset_entry_wc_select_city(MMI_ID parent_gid);
#endif
#endif /* __MMI_HIDE_HOMECITY__ */
static U8 mmi_phnset_get_home_city_dst(void);

MMI_BOOL mmi_phnset_entry_group_check_ex(MMI_ID parent_gid,mmi_id group_id);
MMI_BOOL mmi_phnset_entry_group_check_ex(MMI_ID parent_gid,mmi_id group_id)
{
    if (mmi_frm_group_is_present(group_id))
       {
           mmi_popup_display_simple_ext(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_NOT_AVAILABLE, GRP_ID_ROOT, NULL);
           return MMI_TRUE;
       }
       if (!parent_gid)
       {
           parent_gid = GRP_ID_ROOT;
       }
           return MMI_FALSE;

}

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  HintPhnsetTimeAndDate
 * DESCRIPTION
 *  This function is hint handling function
 *  for Phonesetup -> Time and Data ( Set Home City, Auto Update Date and Time)
 *  Functionality:
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintPhnsetTimeAndDate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TIMEZONE_SETTING__    
#if !defined(__MMI_HIDE_HOMECITY__) && defined(__MMI_TWO_LAYER_HOMECITY__)
    U8 hint_timezone[30];
    FLOAT homecity_tz;
#endif
#endif
    MMI_ID menucui_id = mmi_frm_group_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TIMEZONE_SETTING__    
#ifndef __MMI_HIDE_HOMECITY__
#ifndef __MMI_TWO_LAYER_HOMECITY__
	 cui_menu_set_item_hint(
	    menucui_id,
	    MENU9142_SETHOMECITY,
	    (WCHAR*)g_phnset_cntx_p->CurHomeCityStrPtr);
#else /* __MMI_TWO_LAYER_HOMECITY__ */
     memset(hint_timezone, 0x00, 30);
     homecity_tz = GetTimeZone(PhnsetGetHomeCity());
     mmi_dt_get_gmt_tz_string(hint_timezone, homecity_tz);
		 cui_menu_set_item_hint(
		    menucui_id,
		    MENU9142_SETHOMECITY,
		    (WCHAR*)hint_timezone);
 #endif /* __MMI_TWO_LAYER_HOMECITY__ */
#ifdef __MMI_DUAL_CLOCK__
    cui_menu_set_item_hint(            
	    menucui_id,
	    MENU9142_SETFOREIGNCITY,
        (WCHAR*)g_phnset_cntx_p->CurForeignCityStrPtr);
#endif /* __MMI_OP11_HOMESCREEN__ */
#endif /* __MMI_HIDE_HOMECITY__ */
#endif /* __MMI_TIMEZONE_SETTING__ */
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif


#if 0
#ifndef __MMI_OP11_HOMESCREEN__
#ifdef __MMI_AP_DCM_SETTING__
/* under construction !*/
#endif
#endif
#else
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_date_and_time_mytime_to_inline_time
 * DESCRIPTION
 *  Transfer g_time_buffer to inline time struct 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static cui_inline_item_time_struct mmi_phnset_date_and_time_mytime_to_inline_time(const MYTIME *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_item_time_struct inline_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_time.date_time.year = time->nYear;
    inline_time.date_time.month = time->nMonth;
    inline_time.date_time.day = time->nDay;
    inline_time.date_time.hour = time->nHour;    
    inline_time.date_time.minute = time->nMin;
    inline_time.date_time.second = time->nSec;
    inline_time.date_format = 0;    
    return inline_time;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_date_and_time_inline_time_to_mytime
 * DESCRIPTION
 *  Transfer inline time struct data to g_time_buffer 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static MYTIME mmi_phnset_date_and_time_inline_time_to_mytime(cui_inline_item_time_struct *inline_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME time;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time.nYear = (kal_uint16)inline_time->date_time.year;
    time.nMonth = (kal_uint8)inline_time->date_time.month;
    time.nDay = (kal_uint8)inline_time->date_time.day;
    time.nHour = (kal_uint8)inline_time->date_time.hour;    
    time.nMin = (kal_uint8)inline_time->date_time.minute;
    /* Inline cui will not return second */
    time.nSec = 0;
    
    return time;
}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_date_and_time_init_format
 * DESCRIPTION
 *  Init date and time format 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_date_and_time_init_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_cntx_p->CurTimeFmt = (U8)srv_setting_get_time_format();
    g_phnset_cntx_p->CurDateFmt = (U8)srv_setting_get_date_format();
#ifndef __MMI_PHNSET_DATE_SEPARATOR_DISABLE__
	g_phnset_cntx_p->CurDateSep= (U8)srv_setting_get_date_seperator();    
#endif  
}

#ifndef __MMI_PHNSET_DAYLIGHT_SAVING_DISABLE__  
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_date_and_time_dst_changed_handler
 * DESCRIPTION
 *  Handler for change day light saving selection 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_date_and_time_dst_changed_handler(U8 select_dst, cui_inline_item_time_struct *inline_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME inc_time;
    MYTIME result;
    MYTIME get_time;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&inc_time, 0, sizeof(MYTIME));
    inc_time.nHour = 1;

    get_time = mmi_phnset_date_and_time_inline_time_to_mytime(inline_time);
    
    if(select_dst != g_phnset_cntx_p->currentDST)
    {
        /* on -> off */
        g_phnset_cntx_p->currentDST = select_dst;
        if (select_dst)
    	{
            /* on -> off */
            IncrementTime(get_time, inc_time, &result);
            
    	}
        else
        {
            /* off -> on */
            DecrementTime(get_time, inc_time, &result);
        }

        if (result.nYear > 2030 || result.nYear < 2000)
        {
            srv_prof_play_tone(SRV_PROF_TONE_ERROR, NULL);
            return;
        }
 
        (*inline_time) = mmi_phnset_date_and_time_mytime_to_inline_time(&result);
    }    
}
#endif 

/*****************************************************************************
 * FUNCTION
 *  EntryPhnsetSetDT
 * DESCRIPTION
 *  Set Date And Time Entry Function
 *  
 *  This Screen Uses Category 57 and Text Box Edit For Data Entry.
 * PARAMETERS
 *  curr_gid    [IN] Group ID where the set date and time app will be created on
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPhnsetSetDT(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phnset_entry_set_date_and_time(GRP_ID_ROOT);
}    


#ifdef __MMI_BTD_BOX_UI_STYLE__

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_set_date_time_picker_save
 * DESCRIPTION
 *  Save data from picker
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phnset_set_date_time_picker_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_picker_header *header;
    U8* picker_data = gui_picker_get_user_data();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(picker_data != NULL);
    header = (gui_picker_header*)picker_data;
    
    switch (header->type)
    {
        case GUI_PICKER_TYPE_YEAR:
        {
            gui_picker_year_struct *picker_year = (gui_picker_year_struct*)picker_data;
            g_phnset_cntx_p->settime.prev_time.nYear = picker_year->current_year;
            break;
        }
        case GUI_PICKER_TYPE_MONTH_AND_DAY:
        {
            gui_picker_month_and_day_struct *picker_month_and_day = (gui_picker_month_and_day_struct*)picker_data;
            g_phnset_cntx_p->settime.prev_time.nMonth = picker_month_and_day->month;
            g_phnset_cntx_p->settime.prev_time.nDay = picker_month_and_day->day;
            break;
        }
        case GUI_PICKER_TYPE_TIME:
        {
            gui_picker_time_struct *picker_time = (gui_picker_time_struct*)picker_data;
            g_phnset_cntx_p->settime.prev_time.nHour = picker_time->hour;
            g_phnset_cntx_p->settime.prev_time.nMin = picker_time->minute;
            break;
        }
    }

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_set_date_time_entry_picker
 * DESCRIPTION
 *  Enter the picker for date/time setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phnset_set_date_time_entry_picker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_picker_header *header;
    U8 picker_data[GUI_PICKER_STRUCT_MAX_SIZE] = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    header = (gui_picker_header*)picker_data;
    header->style = GUI_PICKER_STYLE_COSMOS;
    
    switch (g_phnset_cntx_p->settime.curHightlightItem)
    {
        case SET_DATE_AND_TIME_SET_TIME:
        {
            gui_picker_time_struct *picker_time = (gui_picker_time_struct *)picker_data;
            header->type = GUI_PICKER_TYPE_TIME;
            picker_time->display_row = 5;
            picker_time->hour = g_phnset_cntx_p->settime.prev_time.nHour;
            picker_time->minute = g_phnset_cntx_p->settime.prev_time.nMin;
            #ifdef __MMI_TOUCH_SCREEN__
            picker_time->two_page = MMI_FALSE;
            #else
            picker_time->two_page = MMI_TRUE;
            #endif
            break;
        }
        case SET_DATE_AND_TIME_SET_YEAR:
        {
            gui_picker_year_struct *picker_year = (gui_picker_year_struct *)picker_data;
            header->type = GUI_PICKER_TYPE_YEAR;
            picker_year->display_row = 5;
            picker_year->current_year = g_phnset_cntx_p->settime.prev_time.nYear;
            picker_year->min_year = YEARFORMATE;  //this must be YEARFORMATE
            picker_year->max_year = 2030;  //this should smaller than g_date_year_max in wgui_datetime.c
            break;
        }
        case SET_DATE_AND_TIME_SET_MONTH_AND_DAY:
        {
            gui_picker_month_and_day_struct *picker_month_and_day = (gui_picker_month_and_day_struct *)picker_data;
            header->type = GUI_PICKER_TYPE_MONTH_AND_DAY;
            picker_month_and_day->display_row = 5;
            picker_month_and_day->month = g_phnset_cntx_p->settime.prev_time.nMonth;
            picker_month_and_day->day = g_phnset_cntx_p->settime.prev_time.nDay;
            #ifdef __MMI_TOUCH_SCREEN__
            picker_month_and_day->two_page = MMI_FALSE;
            #else
            picker_month_and_day->two_page = MMI_TRUE;
            #endif
            break;
        }
    }
    wgui_picker_entry((U8*)picker_data, GRP_ID_PHNSET_SET_TIME_AND_DATE, mmi_phnset_set_date_time_picker_save);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_set_date_time_update
 * DESCRIPTION
 *  update cui values
 * PARAMETERS
 *  inlinecui_gid
 *  is_set
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phnset_set_date_time_update(MMI_ID inlinecui_gid, MMI_BOOL is_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!is_set)
    {
        GetDateTime(&g_phnset_cntx_p->settime.prev_time);
    	g_phnset_cntx_p->settime.prev_time.nSec = 0;
    }
    
    memset(g_phnset_cntx_p->settime.time_text, 0, 40);
    memset(g_phnset_cntx_p->settime.year_text, 0, 40);
    memset(g_phnset_cntx_p->settime.monthday_text, 0, 40);
    
    kal_wsprintf((WCHAR*)g_phnset_cntx_p->settime.time_text, "%02d : %02d", g_phnset_cntx_p->settime.prev_time.nHour, g_phnset_cntx_p->settime.prev_time.nMin);
    
    cui_inline_set_value(inlinecui_gid, 
                         SET_DATE_AND_TIME_SET_TIME,
                         &g_phnset_cntx_p->settime.time_text);

    kal_wsprintf((WCHAR*)g_phnset_cntx_p->settime.year_text, "%04d", g_phnset_cntx_p->settime.prev_time.nYear);
    
    cui_inline_set_value(inlinecui_gid, 
                         SET_DATE_AND_TIME_SET_YEAR,
                         &g_phnset_cntx_p->settime.year_text);
    
    kal_wsprintf((WCHAR*)g_phnset_cntx_p->settime.monthday_text, "%02d  /  %02d", g_phnset_cntx_p->settime.prev_time.nMonth, 
        g_phnset_cntx_p->settime.prev_time.nDay);
    
    cui_inline_set_value(inlinecui_gid, 
                         SET_DATE_AND_TIME_SET_MONTH_AND_DAY,
                         &g_phnset_cntx_p->settime.monthday_text);
}

#endif  //__MMI_BTD_BOX_UI_STYLE__

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_entry_set_date_and_time
 * DESCRIPTION
 *  Internal entry function 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_entry_set_date_and_time(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID inlinecui_gid;
    cui_inline_item_time_struct inline_time;
#ifdef __MMI_MAINLCD_96X64__
    //S16 error;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_cntx_p->curHightlightItem = PHNSET_DT_MNU_DT;
     if(mmi_phnset_entry_group_check_ex(parent_gid,GRP_ID_PHNSET_SET_TIME_AND_DATE))
        return;
    
    mmi_frm_group_create_ex(
        parent_gid,
        GRP_ID_PHNSET_SET_TIME_AND_DATE,
        mmi_phnset_set_date_time_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    inlinecui_gid = cui_inline_create(
        GRP_ID_PHNSET_SET_TIME_AND_DATE,
        &g_phnset_set_date_time_inline);

#ifdef __MMI_BTD_BOX_UI_STYLE__
    mmi_phnset_set_date_time_update(inlinecui_gid, MMI_FALSE);
#else  //__MMI_BTD_BOX_UI_STYLE__
    GetDateTime(&g_phnset_cntx_p->settime.prev_time);
	g_phnset_cntx_p->settime.prev_time.nSec = 0;
    inline_time = mmi_phnset_date_and_time_mytime_to_inline_time(&g_phnset_cntx_p->settime.prev_time);
#ifdef __MMI_MAINLCD_96X64__
   // ReadValue(NVRAM_SETTING_STATUS_DT_TIME, &g_phnset_cntx_p->curShowDtStatus, DS_BYTE, &error);
	ReadValueSlim(NVRAM_SETTING_STATUS_DT_TIME, &g_phnset_cntx_p->curShowDtStatus, DS_BYTE);
#else
#ifndef __MMI_PHNSET_DAYLIGHT_SAVING_DISABLE__
    g_phnset_cntx_p->currentDST = mmi_phnset_get_home_city_dst();
#endif        
#endif
    cui_inline_set_value(inlinecui_gid, SET_DATE_AND_TIME_SET_TIME, (void*)&inline_time);

    cui_inline_set_value(inlinecui_gid, SET_DATE_AND_TIME_SET_DATE, (void*)&(inline_time.date_time));
#endif  //__MMI_BTD_BOX_UI_STYLE__
#ifdef __MMI_MAINLCD_96X64__
     cui_inline_set_value(inlinecui_gid, SET_DATE_AND_TIME_SHOW_DATE_TIME_SELECT, (void*)g_phnset_cntx_p->curShowDtStatus);
#else
#ifndef __MMI_PHNSET_DAYLIGHT_SAVING_DISABLE__
    cui_inline_set_value(inlinecui_gid, SET_DATE_AND_TIME_DAYLIGHT_SAVING_SELECT, (void*)g_phnset_cntx_p->currentDST);
#endif
#endif
    cui_inline_run(inlinecui_gid);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_set_date_time_proc
 * DESCRIPTION
 *  Proc function for set date and time 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phnset_set_date_time_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_inline_notify_struct *notify_event = (cui_event_inline_notify_struct*)param; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
    case EVT_ID_CUI_INLINE_SUBMIT:
    case EVT_ID_CUI_INLINE_CSK_PRESS:        
        PhnsetSetDT(notify_event->sender_id);
        break;
        
    case EVT_ID_CUI_INLINE_ABORT:
        cui_inline_close(mmi_frm_group_get_active_id());
        break;
#ifdef __MMI_BTD_BOX_UI_STYLE__
    case EVT_ID_CUI_INLINE_NOTIFY:
    {      
		if (notify_event->event_type == CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM)
        {
            g_phnset_cntx_p->settime.curHightlightItem = notify_event->item_id;
            if (notify_event->item_id == SET_DATE_AND_TIME_SET_TIME ||
                notify_event->item_id == SET_DATE_AND_TIME_SET_YEAR ||
                notify_event->item_id == SET_DATE_AND_TIME_SET_MONTH_AND_DAY)
            {
                cui_inline_set_softkey_text(notify_event->sender_id, 
                        notify_event->item_id, 
                        MMI_LEFT_SOFTKEY, 
                        STR_GLOBAL_EDIT);
                wgui_inline_set_lsk_function(mmi_phnset_set_date_time_entry_picker);
            }
        }
        break;
    }
#else  //__MMI_BTD_BOX_UI_STYLE__
    case EVT_ID_CUI_INLINE_NOTIFY:
        {
#ifdef __MMI_MAINLCD_96X64__              
			if (notify_event->event_type == CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM)
            {
           
			
            if(notify_event->item_id == SET_DATE_AND_TIME_SET_TIME)
              {
               cui_inline_set_title_string_with_string_id(notify_event->sender_id,STR_PHNSET_DATETIME_TIME);
              }
            else if(notify_event->item_id == SET_DATE_AND_TIME_SET_DATE)
              {
                cui_inline_set_title_string_with_string_id(notify_event->sender_id,STR_PHNSET_DATETIME_DATE);
              }
            else
              {
                   cui_inline_set_title_string_with_string_id(notify_event->sender_id,STR_PHNSET_DATETIME_DISPLAY);
              }
			}
#endif 
#ifndef __MMI_MAINLCD_96X64__ 
#ifndef __MMI_PHNSET_DAYLIGHT_SAVING_DISABLE__            
            if ((notify_event->item_id == SET_DATE_AND_TIME_DAYLIGHT_SAVING_SELECT) && (notify_event->event_type == CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED))
        	{
                cui_inline_item_time_struct inline_time;
                U8 highlighted_item;
                cui_inline_get_value(notify_event->sender_id, SET_DATE_AND_TIME_SET_TIME, (void*)&inline_time);
                cui_inline_get_value(notify_event->sender_id, SET_DATE_AND_TIME_SET_DATE, (void*)&(inline_time.date_time));
                cui_inline_get_value(notify_event->sender_id, SET_DATE_AND_TIME_DAYLIGHT_SAVING_SELECT, (void*)&highlighted_item);
                
                mmi_phnset_date_and_time_dst_changed_handler(highlighted_item, &inline_time);
                
                cui_inline_set_value(notify_event->sender_id, SET_DATE_AND_TIME_SET_TIME, (void*)&inline_time);
                cui_inline_set_value(notify_event->sender_id, SET_DATE_AND_TIME_SET_DATE, (void*)&(inline_time.date_time));
                
        	}
#endif  
#endif            
            break;
        }
#endif  //__MMI_BTD_BOX_UI_STYLE__   
    case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        set_inline_date_boundary(2030, 2000, 12, 1);
#ifdef __MMI_BTD_BOX_UI_STYLE__
        mmi_phnset_set_date_time_update(notify_event->sender_id, MMI_TRUE);
#endif
        break;
        
    case EVT_ID_CUI_INLINE_MAIN_SCREEN_INACTIVE:
        set_inline_date_boundary(2030, 1970, 12, 1);   
        break;
        
    default:
        break;
    }
    return MMI_RET_OK;
}
#if 0
#ifndef __MMI_OP11_HOMESCREEN__
#ifdef __MMI_AP_DCM_SETTING__
/* under construction !*/
#endif
#endif
#else
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif 
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_get_home_city_dst
 * DESCRIPTION
 *  Get the day light saving setting of home city 
 * PARAMETERS
 *  
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_phnset_get_home_city_dst(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    //S16 error;

 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ReadValue(NVRAM_SETTING_DT_DST, &data, DS_BYTE, &error);
	ReadValueSlim(NVRAM_SETTING_DT_DST, &data, DS_BYTE);
    return data;
}
 

/*****************************************************************************
 * FUNCTION
 *  PhnsetSetDT
 * DESCRIPTION
 *  This function is to set date and time for Phonesetup-> Time and Date -> Set Time/DAte
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void PhnsetSetDT(MMI_ID inline_cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BTD_BOX_UI_STYLE__
    cui_inline_item_time_struct inline_time;
#endif
    MYTIME time;
#ifdef __MMI_MAINLCD_96X64__ 
   // S16 error;
#endif    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BTD_BOX_UI_STYLE__
    time = g_phnset_cntx_p->settime.prev_time;
#else
    cui_inline_get_value(inline_cui_gid, SET_DATE_AND_TIME_SET_TIME, (void*)&inline_time);
    cui_inline_get_value(inline_cui_gid, SET_DATE_AND_TIME_SET_DATE, (void*)&(inline_time.date_time));
#ifndef __MMI_MAINLCD_96X64__    
#ifndef __MMI_PHNSET_DAYLIGHT_SAVING_DISABLE__
    cui_inline_get_value(inline_cui_gid, SET_DATE_AND_TIME_DAYLIGHT_SAVING_SELECT, (void*)&(g_phnset_cntx_p->currentDST));
#endif    
#else 
    cui_inline_get_value(inline_cui_gid, SET_DATE_AND_TIME_SHOW_DATE_TIME_SELECT, (void*)&(g_phnset_cntx_p->curShowDtStatus));
#endif
    time = mmi_phnset_date_and_time_inline_time_to_mytime(&inline_time);
#endif  //__MMI_BTD_BOX_UI_STYLE__
#ifndef __MMI_MAINLCD_96X64__ 
#ifndef __MMI_PHNSET_DAYLIGHT_SAVING_DISABLE__
    if (mmi_phnset_get_home_city_dst() != g_phnset_cntx_p->currentDST)
    {
        mmi_dt_set_dst((U8) g_phnset_cntx_p->currentDST);
    }
  #endif
#else
   //WriteValue(NVRAM_SETTING_STATUS_DT_TIME, &(g_phnset_cntx_p->curShowDtStatus), DS_BYTE, &error);
   WriteValueSlim(NVRAM_SETTING_STATUS_DT_TIME, &(g_phnset_cntx_p->curShowDtStatus), DS_BYTE);
 #endif   
    PhnsetSendSetTimeReqMessage(&time);
}


#ifndef __MMI_PHNSET_AT_DISABLE__
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_date_and_time_init_at_handler
 * DESCRIPTION
 *  Init AT handler for date and time setting 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_date_and_time_init_at_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(ATSetRTC, PRT_MSG_ID_MMI_EQ_SET_RTC_TIME_REQ_IND);
//    SetProtocolEventHandler(ATSetDateandTimeFormat, PRT_MMI_EQ_SET_DATE_TIME_FORMAT_REQ_IND);    
//    SetProtocolEventHandler(AtQueryDTFmtIndHdlr, PRT_MMI_EQ_QUERY_DATE_TIME_FORMAT_REQ_IND);    
}


/*****************************************************************************
 * FUNCTION
 *  ATSetRTC
 * DESCRIPTION
 *  AT command set RTC
 * PARAMETERS
 *  msg     [?]     RTC
 * RETURNS
 *  void
 *****************************************************************************/
static void ATSetRTC(void *msg, int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME alarmDateTime;
    mmi_eq_set_rtc_time_req_ind_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_eq_set_rtc_time_req_ind_struct*) msg;

    if (msgReq->rtc_type == RTC_TIME_CLOCK_IND)
    {
        mmi_at_general_res_req_struct *rsp_msg;

        rsp_msg = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));

        alarmDateTime.nSec = msgReq->alarm.data_time.rtc_sec;
        alarmDateTime.nMin = msgReq->alarm.data_time.rtc_min;
        alarmDateTime.nHour = msgReq->alarm.data_time.rtc_hour;
        alarmDateTime.nDay = msgReq->alarm.data_time.rtc_day;
        alarmDateTime.nMonth = msgReq->alarm.data_time.rtc_mon;
        alarmDateTime.nYear = msgReq->alarm.data_time.rtc_year + YEARFORMATE;

        if (PhnsetSetDTFromAT(&alarmDateTime))
        {
            rsp_msg->result = (kal_bool)TRUE;
        }
        else
        {
            rsp_msg->result = (kal_bool)FALSE;
        }

		mmi_frm_send_ilm((oslModuleType)mod_id, (oslMsgType)MSG_ID_MMI_AT_GENERAL_RES_REQ, (oslParaType*)rsp_msg, NULL);
    }

    if (mmi_idle_is_active())
    {
        mmi_idle_display();
    }

}
#endif

/* 
 * Set Format
 */
#if 0
/* under construction !*/
#endif
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  EntryPhnsetSetFormat
 * DESCRIPTION
 *  This function is Entry function for Phonesetup-> Time and Date -> Set Format
 *  Following functions:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void EntryPhnsetSetFormat(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID inlinecui_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_phnset_entry_group_check_ex(parent_gid,GRP_ID_PHNSET_SET_TIME_AND_DATE_FORMAT))
            return;

    mmi_frm_group_create_ex(
        parent_gid,
        GRP_ID_PHNSET_SET_TIME_AND_DATE_FORMAT,
        mmi_phnset_set_format_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    inlinecui_gid = cui_inline_create(GRP_ID_PHNSET_SET_TIME_AND_DATE_FORMAT, &g_phnset_set_format_inline);

    mmi_phnset_date_and_time_init_format();
    
    cui_inline_set_value(inlinecui_gid, SET_FORMAT_TIME_FORMAT_SELECT, (void*)g_phnset_cntx_p->CurTimeFmt);
    cui_inline_set_value(inlinecui_gid, SET_FORMAT_DATE_FORMAT_SELECT, (void*)g_phnset_cntx_p->CurDateFmt);    
#ifndef __MMI_PHNSET_DATE_SEPARATOR_DISABLE__
    cui_inline_set_value(inlinecui_gid, SET_FORMAT_DATE_SEPARATOR_SELECT, (void*)g_phnset_cntx_p->CurDateSep);
#endif
    //cui_inline_set_all_items_softkey_text(inlinecui_gid, MMI_LEFT_SOFTKEY, STR_GLOBAL_SAVE);

    cui_inline_run(inlinecui_gid);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_set_format_proc
 * DESCRIPTION
 *  Proc function for set date and time format 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phnset_set_format_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_inline_notify_struct *notify_event = (cui_event_inline_notify_struct*)param; 
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
    case EVT_ID_CUI_INLINE_SUBMIT:
    case EVT_ID_CUI_INLINE_CSK_PRESS:
        PhnsetSetFormat(notify_event->sender_id);
        break;
        
    case EVT_ID_CUI_INLINE_ABORT:
        cui_inline_close(mmi_frm_group_get_active_id());
        break;
    case EVT_ID_CUI_INLINE_NOTIFY:
#ifdef __MMI_MAINLCD_96X64__
		if (notify_event->event_type == CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM)
		{
		    if(notify_event->item_id == SET_FORMAT_TIME_FORMAT_SELECT)
              {
               cui_inline_set_title_string_with_string_id(notify_event->sender_id,STR_PHNSET_FORMATE_TIMEFORMATE);
              }
            else
              {
               cui_inline_set_title_string_with_string_id(notify_event->sender_id,STR_PHNSET_FORMATE_DATEFORMATE);
              }
		}
#endif        
		break;
    default:
        break;
    }
    return MMI_RET_OK;    
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetSetFormat
 * DESCRIPTION
 *  This function is to set date/time format for PhoneSetup->Time and Date->Set Format
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void PhnsetSetFormat(MMI_ID inline_cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(inline_cui_gid, SET_FORMAT_TIME_FORMAT_SELECT, (void*)&g_phnset_cntx_p->CurTimeFmt);
    cui_inline_get_value(inline_cui_gid, SET_FORMAT_DATE_FORMAT_SELECT, (void*)&g_phnset_cntx_p->CurDateFmt);    
#ifndef __MMI_PHNSET_DATE_SEPARATOR_DISABLE__
    cui_inline_get_value(inline_cui_gid, SET_FORMAT_DATE_SEPARATOR_SELECT, (void*)&g_phnset_cntx_p->CurDateSep);
#endif
    /* Save New Time Format To NVRAM if Value is Changed. */
    srv_setting_set_time_format((srv_setting_time_format_enum) g_phnset_cntx_p->CurTimeFmt);
    /* Save New Date Format To NVRAM if Value is Changed. */
    srv_setting_set_date_format((srv_setting_date_format_enum) g_phnset_cntx_p->CurDateFmt);
#ifndef __MMI_PHNSET_DATE_SEPARATOR_DISABLE__	
	srv_setting_set_date_seperator((srv_setting_date_seperator_enum) g_phnset_cntx_p->CurDateSep);
#endif
    SUBLCD_RedrawCategoryFunction();
    mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);        
#if 0
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/* under construction !*/
#endif
#endif
    mmi_frm_group_close(GRP_ID_PHNSET_SET_TIME_AND_DATE_FORMAT);
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
#if 0
/* under construction !*/
#endif
#if 0
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_VUI_SHELL_OP01_HOMESCREEN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif


#if 0
#ifdef __MMI_SEPARATE_DT_SETTING__
#ifdef __MMI_AP_DCM_SETTING__
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
#ifndef __MMI_PHNSET_DAYLIGHT_SAVING_DISABLE__
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
#ifndef __MMI_PHNSET_DAYLIGHT_SAVING_DISABLE__        
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
#ifndef __MMI_PHNSET_DAYLIGHT_SAVING_DISABLE__        
/* under construction !*/
#endif
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
#endif        
/* under construction !*/
#ifndef __MMI_PHNSET_DAYLIGHT_SAVING_DISABLE__    
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
#ifndef __MMI_PHNSET_DATE_SEPARATOR_DISABLE__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#ifdef __MMI_AP_DCM_SETTING__
/* under construction !*/
#endif
#endif
#endif

#ifdef __MMI_TIMEZONE_SETTING__
/* 
 * Home City
 */


/*****************************************************************************
 * FUNCTION
 *  PhnsetInitTimeNDate
 * DESCRIPTION
 *  This function is to
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetInitTimeNDate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * int i =0;
     * for(i =0;i< NUM_CITYS;i++)
     * city_list[i]=STR_WCLOCK_CITY1 +i;
     * 
     * for(i =0;i< NUM_CITYS;i++)
     * city_number_icon[i] = IMG_NONE;
     */
    PhnsetConstructCityList();
    g_phnset_cntx_p->CurHomeCityStrPtr = homeCityDataPtr[g_phnset_cntx_p->currentCity];
#ifdef __MMI_DUAL_CLOCK__
	g_phnset_cntx_p->CurForeignCityStrPtr = homeCityDataPtr[g_phnset_cntx_p->foreign_city];
#endif

}


/*****************************************************************************
 * FUNCTION
 *  PhnsetReadNvmHomeCityIdxNStoreCityName
 * DESCRIPTION
 *  This function is to (1) Read home city index from nvram
 *  (2) Store city name (digits) in global variable
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetReadNvmHomeCityIdxNStoreCityName(void)   /* Used on Language change */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_CLOCK__
   /*
	ReadValue(FOREIGN_CITY, &(g_phnset_cntx_p->foreign_city), DS_BYTE, &error);
    if (error != NVRAM_READ_SUCCESS)
    {
        g_phnset_cntx_p->foreign_city = 0;
    }
    else 
	*/
	ReadValueSlim(FOREIGN_CITY, &(g_phnset_cntx_p->foreign_city), DS_BYTE);
	if (g_phnset_cntx_p->foreign_city > NUM_CITYS)
    {
        g_phnset_cntx_p->foreign_city = 0;
    }
    g_phnset_cntx_p->CurForeignCityStrID = TimeZoneData[g_phnset_cntx_p->foreign_city + 1].CityName;
		
#endif	/* __MMI_DUAL_CLOCK__ */	
	/*
    ReadValue(CURRENT_CITY, &(g_phnset_cntx_p->currentCity), DS_BYTE, &error);
    if (error != NVRAM_READ_SUCCESS)
    {
        g_phnset_cntx_p->currentCity = 0;
    }
    else 
	*/
	ReadValueSlim(CURRENT_CITY, &(g_phnset_cntx_p->currentCity), DS_BYTE);
	if (g_phnset_cntx_p->currentCity > NUM_CITYS)
    {
        g_phnset_cntx_p->currentCity = 0;
    }
    g_phnset_cntx_p->CurHomeCityStrID = TimeZoneData[g_phnset_cntx_p->currentCity + 1].CityName;

}


/*****************************************************************************
 * FUNCTION
 *  PhnsetReinitHomeCity
 * DESCRIPTION
 *  This function is to Restore the city index when language change
 *  Functionality: !!!NOTICE!!! the function should use together with PhnsetReadNvmHomeCityIdxNStoreCityName()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetReinitHomeCity(void) /* Used on Language change, together with PhnsetReadNvmHomeCityIdxNStoreCityName()  */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S16 error;
    U32 i;
    U8 num_city = NUMBER_OF_CITY;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PhnsetConstructCityList();
    for (i = 0; i < num_city; i++)
    {
        if (TimeZoneData[i].CityName == g_phnset_cntx_p->CurHomeCityStrID)
        {
            g_phnset_cntx_p->currentCity = i - 1;
            //WriteValue(CURRENT_CITY, &(g_phnset_cntx_p->currentCity), DS_BYTE, &error);
			WriteValueSlim(CURRENT_CITY, &(g_phnset_cntx_p->currentCity), DS_BYTE);
            break;
        }
    }
    g_phnset_cntx_p->CurHomeCityStrPtr = homeCityDataPtr[g_phnset_cntx_p->currentCity];

#ifdef __MMI_DUAL_CLOCK__
    for (i = 0; i < num_city; i++)
    {
        if (TimeZoneData[i].CityName == g_phnset_cntx_p->CurForeignCityStrID)
        {
            g_phnset_cntx_p->foreign_city= i - 1;
            //WriteValue(FOREIGN_CITY, &(g_phnset_cntx_p->foreign_city), DS_BYTE, &error);
			WriteValueSlim(FOREIGN_CITY, &(g_phnset_cntx_p->foreign_city), DS_BYTE);
            break;
        }
    }
	g_phnset_cntx_p->CurForeignCityStrPtr = homeCityDataPtr[g_phnset_cntx_p->foreign_city];
#endif /* __MMI_DUAL_CLOCK__ */

}
#endif /* __MMI_TIMEZONE_SETTING__ */

/*****************************************************************************
 * FUNCTION
 *  PhnsetInitSetTimeNDateNvram
 * DESCRIPTION
 *  This function is to read global variable from nvram
 *  for Phonesetup -> Time and Date ->Set Home City
 *  ->Set Time/Date
 *  ->Set Format
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetInitSetTimeNDateNvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_TIMEZONE_SETTING__
    PhnsetReadNvmHomeCityIdxNStoreCityName();
    g_phnset_cntx_p->CurTimeFmt = (U8)srv_setting_get_time_format();
    g_phnset_cntx_p->CurDateFmt = (U8)srv_setting_get_date_format();
    #endif
}

#ifdef __MMI_TIMEZONE_SETTING__
/*****************************************************************************
 * FUNCTION
 *  PhnsetConstructCityList
 * DESCRIPTION
 *  This function is to
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetConstructCityList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < NUM_CITYS; i++)
    {
        homeCityDataPtr[i] = (PU8) ((GetString) ((U16) (TimeZoneData[i + 1].CityName)));
    }
}


#ifndef __MMI_HIDE_HOMECITY__
/*****************************************************************************
 * FUNCTION
 *  mmi_setting_home_city_async_callback
 * DESCRIPTION
 *  This function is callback function for generating asynchronous list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_setting_home_city_async_callback(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	*img_buff_p = 0;

#ifdef __MMI_TWO_LAYER_HOMECITY__
    mmi_ucs2cpy((CHAR*)str_buff, (CHAR*)gmt_tz_str_buf[item_index]);
#else /* __MMI_TWO_LAYER_HOMECITY__ */
    mmi_ucs2cpy(
        (CHAR*) str_buff,
        (CHAR*) ((GetString)((U16) (TimeZoneData[item_index + 1].CityName))));
#endif /* __MMI_TWO_LAYER_HOMECITY__ */

#ifdef __MMI_TWO_LAYER_HOMECITY__
#ifdef __MMI_DUAL_CLOCK__
    if (g_phnset_cntx_p->city_flag == 1)
    {
        if (item_index == mmi_dt_gmt_tz_get_hilite(g_phnset_cntx_p->foreign_city))
        {
            *img_buff_p = get_image(IMG_VICON);
        }
    }
    else if (item_index == mmi_dt_gmt_tz_get_hilite(g_phnset_cntx_p->currentCity))
    {
        *img_buff_p = get_image(IMG_VICON);
    }
#else /* __MMI_DUAL_CLOCK__ */
    if (item_index == mmi_dt_gmt_tz_get_hilite(g_phnset_cntx_p->currentCity))
    {
        *img_buff_p = get_image(IMG_VICON);
    }
#endif /* __MMI_DUAL_CLOCK__ */

#else /* __MMI_TWO_LAYER_HOMECITY__ */

#ifdef __MMI_DUAL_CLOCK__
	if (g_phnset_cntx_p->city_flag == 1)
	{
		if (item_index == g_phnset_cntx_p->foreign_city)
		{
			*img_buff_p = get_image(IMG_VICON);
		}
	}
	else if (item_index == g_phnset_cntx_p->currentCity)
	{
		*img_buff_p = get_image(IMG_VICON);
	}
#else /* __MMI_DUAL_CLOCK__ */
	if (item_index == g_phnset_cntx_p->currentCity)
	{
		*img_buff_p = get_image(IMG_VICON);
	}
#endif /* __MMI_DUAL_CLOCK__ */
#endif /* __MMI_TWO_LAYER_HOMECITY__ */
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  EntryPhnsetSetHomeCity
 * DESCRIPTION
 *  This function is Entry function for Phonesetup->Time and Date->Set Homecity
 *  Following functions: PhnsetSetHomeCity
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPhnsetSetHomeCity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phnset_entry_set_home_city(GRP_ID_ROOT);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_entry_set_home_city
 * DESCRIPTION
 *  Entry function fro set homecity 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_entry_set_home_city(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_phnset_entry_group_check_ex(parent_gid,GRP_ID_PHNSET_SET_HOME_FOREIGN_CITY))
        return;
    
    mmi_frm_group_create_ex(
        parent_gid,
        GRP_ID_PHNSET_SET_HOME_FOREIGN_CITY,
        NULL,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_first_enter(
        GRP_ID_PHNSET_SET_HOME_FOREIGN_CITY,
        SETTINGS_SETHOMECITY_SCREENID,
        (FuncPtr)mmi_phnset_entry_set_home_city_int,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_entry_set_home_city_int
 * DESCRIPTION
 *  Internal entry function for set home city 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_entry_set_home_city_int(mmi_scrn_essential_struct *scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 string_id = 0;
    U8 *guiBuffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
        scrn_data->group_id,
        scrn_data->scrn_id,
        ExitPhnsetSetHomeCity,
        (FuncPtr)mmi_phnset_entry_set_home_city_int,
        MMI_FRM_UNKNOW_SCRN))	
	{
	    return;
	}

    guiBuffer = mmi_frm_scrn_get_gui_buf(scrn_data->group_id, scrn_data->scrn_id);

    PhnsetReadNvmHomeCityIdxNStoreCityName();
    PhnsetConstructCityList();

    if (guiBuffer == NULL)
    {
    #ifdef __MMI_TWO_LAYER_HOMECITY__   
    #ifdef __MMI_DUAL_CLOCK__
        if (g_phnset_cntx_p->city_flag == 1)    /* foreign city */
        {
            g_phnset_cntx_p->curHightlightItem = (U32) mmi_dt_gmt_tz_get_hilite(g_phnset_cntx_p->foreign_city);	
        }
        else
    #endif
        {
            g_phnset_cntx_p->curHightlightItem = (U32) mmi_dt_gmt_tz_get_hilite(g_phnset_cntx_p->currentCity);
		}

    #else /* __MMI_TWO_LAYER_HOMECITY__ */

    #ifdef __MMI_DUAL_CLOCK__
		if (g_phnset_cntx_p->city_flag == 1)    /* foreign city */
		{
			g_phnset_cntx_p->curHightlightItem = (U32) g_phnset_cntx_p->foreign_city;	
		}
		else
	#endif
		{
	        g_phnset_cntx_p->curHightlightItem = (U32) g_phnset_cntx_p->currentCity;
		}
    #endif /* __MMI_TWO_LAYER_HOMECITY__ */

    }
    
#ifdef __MMI_TWO_LAYER_HOMECITY__   
#ifdef __MMI_DUAL_CLOCK__
    if (g_phnset_cntx_p->city_flag == 1)    /* foreign city */
    {
		string_id = STR_MENU9142_SETFRNCITY;
    }
    else
#endif
    {
		string_id = STR_MENU9142_SETTIMEZONE;
	}

#else /* __MMI_TWO_LAYER_HOMECITY__ */

#ifdef __MMI_DUAL_CLOCK__
	if (g_phnset_cntx_p->city_flag == 1)    /* foreign city */
	{
		string_id = STR_MENU9142_SETFRNCITY;
	}
	else
#endif
	{
		string_id = STR_MENU9142_SETHOMECITY;
	}
#endif /* __MMI_TWO_LAYER_HOMECITY__ */
    

#if !defined(__MMI_HIDE_HOMECITY__) && defined(__MMI_TWO_LAYER_HOMECITY__)
	mmi_dt_gmt_tz_list();
#endif

	EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory184Screen(
        string_id,
        IMG_SCR_SETTING_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NUM_CITYS,
        mmi_setting_home_city_async_callback,
        NULL,
        g_phnset_cntx_p->curHightlightItem,
        guiBuffer);

    RegisterHighlightHandler(PhnsetHomeCityIdxHiliteHandler);

#ifndef __MMI_TWO_LAYER_HOMECITY__
    if (IsEnglishSet())
    {
        wgui_setup_multitap_functions(WGUI_MULTITAP_TYPE_UPPERCASE_ABC_NO_NUMBER, PhnsetHCMultiTapHdlr, PhnsetHCMultiTapCompleteHdlr);
    }
#endif /* __MMI_TWO_LAYER_HOMECITY__ */

    SetLeftSoftkeyFunction(PhnsetSetHomeCity, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(PhnsetSetHomeCity, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

#ifdef __MMI_DUAL_CLOCK__
	if (g_phnset_cntx_p->city_flag == 1)
	{
		SetLeftSoftkeyFunction(PhnsetSetForeignCity, KEY_EVENT_UP);
	    SetCenterSoftkeyFunction(PhnsetSetForeignCity, KEY_EVENT_UP);
		//SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	}
#endif
    
}


/*****************************************************************************
 * FUNCTION
 *  ExitPhnsetSetHomeCity
 * DESCRIPTION
 *  This function is Entry function for Phonesetup->Time and Date->Set Homecity
 *  Following functions: PhnsetSetHomeCity
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitPhnsetSetHomeCity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_TWO_LAYER_HOMECITY__
	wgui_reset_multitap();
#endif 
}

#ifdef __MMI_WC_TZ_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_wc_select_city_proc
 * DESCRIPTION
 *  proc function for select city cui
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static mmi_ret mmi_phnset_wc_select_city_proc(mmi_event_struct *param)
{
	cui_worldclock_event_struct *wc_evt = (cui_worldclock_event_struct *)param;
	U8 ret;

	switch(wc_evt->evt_id)
	{
		case EVT_ID_SCRN_DEINIT:
			break;
			
		case CUI_WC_SELECT_EVENT_OK:
			ret = mmi_wc_entry_from_phnset();
			if (ret == 1)
			{
				PhnsetSetHomeCity();
			}
#ifdef __MMI_DUAL_CLOCK__
			else if (ret == 2)
			{
				PhnsetSetForeignCity();
			}
#endif /* __MMI_DUAL_CLOCK__ */
			break;

		case CUI_WC_SELECT_EVENT_CANCEL:
		case CUI_WC_SELECT_EVENT_CLOSE_REQ:
			cui_worldclock_close(wc_evt->sender_id);
			break;
	}
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_entry_wc_select_city
 * DESCRIPTION
 *  Entry function fro set homecity 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_entry_wc_select_city(MMI_ID parent_gid)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                               						  */
	/*----------------------------------------------------------------*/
	mmi_id sub_grp;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      						   */
	/*----------------------------------------------------------------*/
     if(mmi_phnset_entry_group_check_ex(parent_gid,GRP_ID_PHNSET_SET_HOME_FOREIGN_CITY))
        return;

	mmi_frm_group_create_ex(parent_gid,
						     GRP_ID_PHNSET_SET_HOME_FOREIGN_CITY,
						     mmi_phnset_wc_select_city_proc,
						     NULL,
						     MMI_FRM_NODE_SMART_CLOSE_FLAG);
	
	sub_grp = cui_worldclock_create(GRP_ID_PHNSET_SET_HOME_FOREIGN_CITY);
	if (sub_grp != GRP_ID_INVALID)
	{
		cui_worldclock_run(sub_grp);
	}
	else
	{
		mmi_frm_group_close(GRP_ID_PHNSET_SET_HOME_FOREIGN_CITY);
	}

}
#endif /* __MMI_WC_TZ_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  PhnsetSetHomeCity
 * DESCRIPTION
 *  This function is to set home city for Phonesetup->Time and Date->Set Homecity
 *  Following functions:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetSetHomeCity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S16 error;
    S16 tmpCity;	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//ReadValue(CURRENT_CITY, &tmpCity, DS_BYTE, &error);
	ReadValueSlim(CURRENT_CITY, &tmpCity, DS_BYTE);

#ifndef __MMI_WC_TZ_SUPPORT__   
#ifdef __MMI_TWO_LAYER_HOMECITY__
    g_phnset_cntx_p->currentCity = gmt_tz_table[g_phnset_cntx_p->curHightlightItem + 1] - 1;
    if (tmpCity != (U8) g_phnset_cntx_p->currentCity)
    {
        g_phnset_cntx_p->CurHomeCityStrPtr = homeCityDataPtr[g_phnset_cntx_p->currentCity];
        //WriteValue(CURRENT_CITY, &(g_phnset_cntx_p->currentCity), DS_BYTE, &error);
		WriteValueSlim(CURRENT_CITY, &(g_phnset_cntx_p->currentCity), DS_BYTE);
    }
	tmpCity = (S16)(GetTimeZone(PhnsetGetHomeCity()) * 4);

#else /* __MMI_TWO_LAYER_HOMECITY__ */
	g_phnset_cntx_p->currentCity = (U8) g_phnset_cntx_p->curHightlightItem;
	if (IsEnglishSet())
    {
        wgui_reset_multitap();
    }

    if (tmpCity != (U8) g_phnset_cntx_p->curHightlightItem)
	{
        g_phnset_cntx_p->CurHomeCityStrPtr = homeCityDataPtr[g_phnset_cntx_p->currentCity];
		//WriteValue(CURRENT_CITY, &(g_phnset_cntx_p->currentCity), DS_BYTE, &error);
		WriteValueSlim(CURRENT_CITY, &(g_phnset_cntx_p->currentCity), DS_BYTE);
	}
	tmpCity = (S16)(GetTimeZone(PhnsetGetHomeCity()) * 4);
#endif /* __MMI_TWO_LAYER_HOMECITY__ */
#else /* __MMI_WC_TZ_SUPPORT__ */
	if ( g_wc_cntx.CurrCityIndex != 0)
    {
        g_phnset_cntx_p->currentCity = g_wc_cntx.CurrCityIndex - 1;
    }
    else
    {
        g_phnset_cntx_p->currentCity = 0xff;
    }

    if (tmpCity != (U8) g_phnset_cntx_p->currentCity)
	{
		g_phnset_cntx_p->CurHomeCityStrPtr = (U8*)GetString(TimeZoneData[g_wc_cntx.CurrCityIndex].CityName);
		//WriteValue(CURRENT_CITY, &(g_phnset_cntx_p->currentCity), DS_BYTE, &error);
		WriteValueSlim(CURRENT_CITY, &(g_phnset_cntx_p->currentCity), DS_BYTE);
	}
	tmpCity = (S16)(g_wc_cntx.CurrTZ * 4);
    g_wc_cntx.CurrCityIndex= 0xFF;
#endif /* __MMI_WC_TZ_SUPPORT__ */
	
	mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);

#ifdef __MMI_TIMEZONE_CHANGE_DATETIME__
    mmi_dt_tz_update_datetime(tmpCity);
#endif

    //WriteValue(NVRAM_TIMEZONE, &tmpCity, DS_SHORT, &error);
	WriteValueSlim(NVRAM_TIMEZONE, &tmpCity, DS_SHORT);
    
/* When time zone changed, TaskList should be updated */
#ifdef __MMI_TDL_NITZ_SUPPORT__
    srv_tdl_init();
#endif


    /* DeleteScreenIfPresent(SETTINGS_SETHOMECITY_SCREENID); */
    /*
    DeleteScreenIfPresent(SCR_ID_WC_BROWSE_CITY);
    */
    if (mmi_frm_group_is_present(GRP_ID_PHNSET_SET_HOME_FOREIGN_CITY))
	{
    mmi_frm_group_close(GRP_ID_PHNSET_SET_HOME_FOREIGN_CITY);
	}
    SUBLCD_RedrawCategoryFunction();
}

/*****************************************************************************
 * FUNCTION
 *  PhnsetSetForeignCity
 * DESCRIPTION
 *  This function is to set home city for Phonesetup->Time and Date->Set Homecity
 *  Following functions:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_DUAL_CLOCK__
void PhnsetSetForeignCity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S16 error;
    S16 tmpCity;	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//ReadValue(FOREIGN_CITY, &tmpCity, DS_BYTE, &error);
	ReadValueSlim(FOREIGN_CITY, &tmpCity, DS_BYTE);
           
#ifndef __MMI_WC_TZ_SUPPORT__    
#ifdef __MMI_TWO_LAYER_HOMECITY__
    g_phnset_cntx_p->foreign_city = gmt_tz_table[g_phnset_cntx_p->curHightlightItem + 1] - 1;
    if (tmpCity != (U8) g_phnset_cntx_p->foreign_city)
    {
        g_phnset_cntx_p->CurHomeCityStrPtr = homeCityDataPtr[g_phnset_cntx_p->foreign_city];
        //WriteValue(CURRENT_CITY, &(g_phnset_cntx_p->foreign_city), DS_BYTE, &error);
		WriteValueSlim(CURRENT_CITY, &(g_phnset_cntx_p->foreign_city), DS_BYTE);
    }
    tmpCity = (S16)(GetTimeZone(PhnsetGetForeignCity()) * 4);
    
#else /* __MMI_TWO_LAYER_HOMECITY__ */
	g_phnset_cntx_p->foreign_city = (U8) g_phnset_cntx_p->curHightlightItem;
	if (IsEnglishSet())
    {
        wgui_reset_multitap();
    }

    if (tmpCity != (U8) g_phnset_cntx_p->curHightlightItem)
	{
        g_phnset_cntx_p->CurForeignCityStrPtr = homeCityDataPtr[g_phnset_cntx_p->foreign_city];
		//WriteValue(FOREIGN_CITY, &(g_phnset_cntx_p->foreign_city), DS_BYTE, &error);
		WriteValueSlim(FOREIGN_CITY, &(g_phnset_cntx_p->foreign_city), DS_BYTE);
	}
	tmpCity = (S16)(GetTimeZone(PhnsetGetForeignCity()) * 4);
#endif /* __MMI_TWO_LAYER_HOMECITY__ */
#else /* __MMI_WC_TZ_SUPPORT__ */
	g_wc_cntx.FrnCityIdx = g_wc_cntx.CurrCityIndex;
	if ( g_wc_cntx.FrnCityIdx!= 0)
    {
        g_phnset_cntx_p->foreign_city = g_wc_cntx.FrnCityIdx - 1;
    }
    else
    {
        g_phnset_cntx_p->foreign_city = 0xff;
    }

    if (tmpCity != (U8) g_phnset_cntx_p->foreign_city)
	{
		g_phnset_cntx_p->CurForeignCityStrPtr = (U8*)GetString(TimeZoneData[g_wc_cntx.FrnCityIdx].CityName);
		//WriteValue(FOREIGN_CITY, &(g_phnset_cntx_p->foreign_city), DS_BYTE, &error);
		WriteValueSlim(FOREIGN_CITY, &(g_phnset_cntx_p->foreign_city), DS_BYTE);
	}
	tmpCity = (S16)(g_wc_cntx.CurrTZ * 4);
	g_wc_cntx.CurrCityIndex= 0xFF;
#endif  /* __MMI_WC_TZ_SUPPORT__ */      

	mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);

    //WriteValue(NVRAM_FRN_TIMEZONE, &tmpCity, DS_SHORT, &error);
	WriteValueSlim(NVRAM_FRN_TIMEZONE, &tmpCity, DS_SHORT);

    /*DeleteScreenIfPresent(SETTINGS_SETHOMECITY_SCREENID);*/
    /*
    DeleteScreenIfPresent(SCR_ID_WC_BROWSE_CITY);
    */
    mmi_frm_group_close(GRP_ID_PHNSET_SET_HOME_FOREIGN_CITY);
    SUBLCD_RedrawCategoryFunction();
}
#endif /* __MMI_DUAL_CLOCK__ */
#endif /* __MMI_HIDE_HOMECITY__ */ 


/*****************************************************************************
 * FUNCTION
 *  PhnsetHomeCityIdxHiliteHandler
 * DESCRIPTION
 *  This function is Highlight handler for Phonesetup->Time and Date->Set Homecity -> (list)
 *  Follow functions: EntryPhnsetMainMenuStyle
 * PARAMETERS
 *  cityIndex       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetHomeCityIdxHiliteHandler(S32 cityIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_cntx_p->curHightlightItem = (U32) cityIndex;
}

#endif /* __MMI_TIMEZONE_SETTING__ */
/*****************************************************************************
 * FUNCTION
 *  PhnsetGetHomeCity
 * DESCRIPTION
 *  This function is to get current home city setting
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 PhnsetGetHomeCity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_TIMEZONE_SETTING__
    return g_phnset_cntx_p->currentCity;
    #else
    return 0;
    #endif
}
#ifdef __MMI_TIMEZONE_SETTING__
#ifdef __MMI_DUAL_CLOCK__
/*****************************************************************************
 * FUNCTION
 *  PhnsetGetHomeCity
 * DESCRIPTION
 *  This function is to get current home city setting
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 PhnsetGetForeignCity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_phnset_cntx_p->foreign_city;
}
#endif /* __MMI_DUAL_CLOCK__ */

/*****************************************************************************
 * FUNCTION
 *  PhnsetHCGetNearbyIdx
 * DESCRIPTION
 *  This function is to get the nearby city index when multitap presing at browsing home city in english mode
 *  for Phonesetup->Time and Date->Home City
 *  Functionality:
 * PARAMETERS
 *  inp     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 PhnsetHCGetNearbyIdx(UI_character_type inp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 n1 = 0;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((inp >= (UI_character_type) 'A' && inp <= (UI_character_type) 'Z') ||
        (inp >= (UI_character_type) 'a' && inp <= (UI_character_type) 'z'))
    {
        for (i = 0; i < NUM_CITYS; i++)
        {
            memcpy(&n1, homeCityDataPtr[i], ENCODING_LENGTH);
            if (n1 == inp)
            {
                return (U8) (i);
            }
        }

        if (i == NUM_CITYS)
        {
             return i;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetHCMultiTapHdlr
 * DESCRIPTION
 *  This function is multitap handler when browsing home city in english mode
 *  for Phonesetup->Time and Date->Home City
 *  Functionality:
 * PARAMETERS
 *  inp     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetHCMultiTapHdlr(UI_character_type inp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx = (U32)PhnsetHCGetNearbyIdx(inp);
    if ((U8)idx != NUM_CITYS)
    {
        g_phnset_cntx_p->curHightlightItem = idx;
    }
    dynamic_list_goto_item((S32) g_phnset_cntx_p->curHightlightItem);
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetHCMultiTapCompleteHdlr
 * DESCRIPTION
 *  This function is to
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetHCMultiTapCompleteHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dynamic_list_goto_item((S32) g_phnset_cntx_p->curHightlightItem);
}
#endif /* __MMI_TIMEZONE_SETTING__ */
#ifndef __MMI_PHNSET_AT_DISABLE__
/*****************************************************************************
 * FUNCTION
 *  PhnsetSetDTFromAT
 * DESCRIPTION
 *  This function is to set date and time from AT command
 *  Functionality:
 * PARAMETERS
 *  mytime      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL PhnsetSetDTFromAT(const MYTIME *mytime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!applib_dt_is_valid((applib_time_struct*)mytime))
    {
        return MMI_FALSE;
    }

    PhnsetSendSetTimeReqMessage(mytime);

    return MMI_TRUE;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  PhnsetSendSetTimeReqMessage
 * DESCRIPTION
 *  This function is to send set time request to L4
 *  for Phonesetup->Time and Date->Set Time/Date
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetSendSetTimeReqMessage(const MYTIME *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifndef __MTK_TARGET__
    #ifdef __DRM_V02__
	applib_time_struct old_time, new_time;	
    #endif
    #endif
    MYTIME set_time = *time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifndef __MTK_TARGET__
    #ifdef __DRM_V02__
	applib_dt_get_rtc_time(&old_time);
    #endif
    #endif
    /*set_time.nSec = 0;*/
    mmi_dt_set_dt(&set_time, PhnsetSetTimeResHdlr, NULL);

    #ifndef __MTK_TARGET__
    #ifdef __DRM_V02__
    applib_dt_get_rtc_time(&new_time);
    DRM_update_local_time(&old_time, &new_time, KAL_FALSE);
    #endif
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetSetTimeResHdlr
 * DESCRIPTION
 *  This function is Set time response handler (MSG_ID_MMI_EQ_SET_RTC_TIME_RSP)
 *  for Phonesetup->Time and Date->Set Time/Date
 *  Functionality:
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetSetTimeResHdlr(MMI_BOOL result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
		mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
#if 0
#ifdef __MMI_SEPARATE_DT_SETTING__            
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else            
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
#else            
        if (mmi_frm_group_is_present(GRP_ID_PHNSET_SET_TIME_AND_DATE))
    	{
    	    mmi_frm_group_close(GRP_ID_PHNSET_SET_TIME_AND_DATE);
    	}
#endif            
    }
    else
    {
		mmi_popup_display_simple_ext(STR_GLOBAL_UNFINISHED, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ATSetHomeCity
 * DESCRIPTION
 *  Set home city from AT command
 * PARAMETERS
 *  CityIndex       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL ATSetHomeCity(U8 CityIndex)
{
#ifdef __MMI_TIMEZONE_SETTING__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 PrevCity;
	S16 timezone;
    //S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* index exceeds boundary */
    /* remove the 0 (none case), so size of home city table shall minus by 1 */
    if (CityIndex > (NUMBER_OF_CITY - 1) || CityIndex == 0)
    {
        return MMI_FALSE;
    }

    CityIndex -= 1; /* Sync to the index of highlite */

    /* read current city index from NVRAM */
    //ReadValue(CURRENT_CITY, &PrevCity, DS_BYTE, &error);
	ReadValueSlim(CURRENT_CITY, &PrevCity, DS_BYTE);

    {
        g_phnset_cntx_p->currentCity = CityIndex;

        /* retrieve string pointer of city name */
        /* The index of menu is bigger than that one of TimeZoneData */
        g_phnset_cntx_p->CurHomeCityStrPtr =
            (PU8) ((GetString) ((U16) (TimeZoneData[g_phnset_cntx_p->currentCity + 1].CityName)));

        /* write city index to NVRAM */
        //WriteValue(CURRENT_CITY, &(g_phnset_cntx_p->currentCity), DS_BYTE, &error);
		WriteValueSlim(CURRENT_CITY, &(g_phnset_cntx_p->currentCity), DS_BYTE);

        /* write NITZ setting to NVRAM */
        timezone = (S16) (GetTimeZone(PhnsetGetHomeCity()) * 4);

#ifdef __MMI_TIMEZONE_CHANGE_DATETIME__
        mmi_dt_tz_update_datetime(timezone);
#endif

		//WriteValue(NVRAM_TIMEZONE, &timezone, DS_SHORT, &error);
		WriteValueSlim(NVRAM_TIMEZONE, &timezone, DS_SHORT);

        /* Update Task List when Timezone is changed */
#ifdef __MMI_TDL_NITZ_SUPPORT__
        srv_tdl_init();
#endif
    }
#endif /* __MMI_TIMEZONE_SETTING__ */
    return MMI_TRUE;
}

#ifdef __MMI_TIMEZONE_SETTING__
#ifdef __MMI_WC_TZ_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_wc_entry_from_phnset
 * DESCRIPTION
 *  This function is Left softkey handler for Phonesetup-> Auto Update Date and Time
 *  Functionality: Toggle status only
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_wc_entry_from_phnset(void)
{
    /* Modified for apply Menu CUI */
    //if (IsScreenPresent(SCR9041_TIMEANDDATE))
    {
    	if (g_phnset_cntx_p->curHightlightItem == PHNSET_DT_MNU_HOMECT)
		{
			return 1;
		}
#ifdef __MMI_DUAL_CLOCK__
		else if (g_phnset_cntx_p->curHightlightItem == PHNSET_DT_MNU_FOREIGN_CITY)
		{
			return 2;
		}
#endif /* __MMI_DUAL_CLOCK__ */
    }
#if 0
#ifdef __MMI_VUI_HOMESCREEN_DUALCLOCK__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_DUAL_CLOCK__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_CLOCK__ */
/* under construction !*/
#endif 
#endif 
    
	return 0;
}
#endif /* __MMI_WC_TZ_SUPPORT__ */


#if !defined(__MMI_HIDE_HOMECITY__) && defined(__MMI_TWO_LAYER_HOMECITY__)
/*****************************************************************************
 * FUNCTION
 *  mmi_dt_get_gmt_tz_string
 * DESCRIPTION
 *  This function is construct hint of "Set time zone" menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dt_get_gmt_tz_string(U8 *result, FLOAT timezone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR tmpBuff[12]; /* "GMT +XX.XX" */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(result);

    memset(tmpBuff, 0x00, 12);

    if (timezone < 0)
    {
        timezone = 0 - timezone;
        sprintf(tmpBuff, "GMT -%3.2f", timezone);
    }
    else
    {
        sprintf(tmpBuff, "GMT +%3.2f", timezone);
    }
    
    mmi_asc_n_to_ucs2((CHAR*)result, (CHAR*)tmpBuff, 12);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dt_gmt_tz_list
 * DESCRIPTION
 *  This function is construct GMT and time zone list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dt_gmt_tz_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 gmt_tz_buf[30];
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < NUM_CITYS + 1; i++)
    {
        if (TimeZoneData[gmt_tz_table[i + 1]].CityName == STR_WCLOCK_CITY_NONE)
            break;
        
        memset(gmt_tz_buf, 0x00, 30);

        mmi_dt_get_gmt_tz_string((U8*)gmt_tz_buf, TimeZoneData[gmt_tz_table[i + 1]].CityTimeZone);
        mmi_ucs2cpy((CHAR*)gmt_tz_str_buf[i], (CHAR*)gmt_tz_buf);
        mmi_ucs2cat((CHAR*)gmt_tz_str_buf[i], (CHAR*)L" ");
        mmi_ucs2cat((CHAR*)gmt_tz_str_buf[i], (CHAR*)GetString((U16)(TimeZoneData[gmt_tz_table[i + 1]].CityName)));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dt_init_gmt_tz_table
 * DESCRIPTION
 *  This function is sort GMT and time zone table with GMT & city name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dt_init_gmt_tz_table(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j, k;
    static GMT_TZ_STRUCT gmt_tz_map[MAX_CITY_NUM];
    GMT_TZ_STRUCT tmp_gmt_tz;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(gmt_tz_map, 0x00, sizeof(GMT_TZ_STRUCT) * MAX_CITY_NUM);

    /* construct all simple city time zone info */
    for (i = 0; i < NUM_CITYS; i++)
    {
        gmt_tz_map[i].CityTimeZone = TimeZoneData[i + 1].CityTimeZone;
        gmt_tz_map[i].CityName = TimeZoneData[i + 1].CityName;
        gmt_tz_map[i].tzdata_index = i + 1;
    }

    for (i = 0; i < NUM_CITYS + 1; i++)
    {
        memcpy(&tmp_gmt_tz, &gmt_tz_map[i + 1], sizeof(GMT_TZ_STRUCT));    /* current compare unit */

        for (j = 0; j < i + 1; j++)
        {
            S16 sub_rst;

            sub_rst = (S16)((tmp_gmt_tz.CityTimeZone - gmt_tz_map[j].CityTimeZone) * 4);

            if (sub_rst > 0)    /* current time zone > j point time zone */
            {
                continue;
            }
            else if (sub_rst < 0)   /* current time zone < j point time zone */
            {
                /* move gmt_tz_map items */    
                for (k = i + 1; k > j; k--)
                {
                    memcpy(&gmt_tz_map[k], &gmt_tz_map[k - 1], sizeof(GMT_TZ_STRUCT)); 
                }
                
                memcpy(&gmt_tz_map[j], &tmp_gmt_tz, sizeof(GMT_TZ_STRUCT));
                break;
            }
            else
            {
                if (tmp_gmt_tz.CityName > gmt_tz_map[j].CityName)   /* same time zone but current city name big */
                {
                    continue;
                }
                else if (tmp_gmt_tz.CityName < gmt_tz_map[j].CityName)
                {
                    /* move gmt_tz_map items */    
                    for (k = i + 1; k > j; k--)
                    {
                        memcpy(&gmt_tz_map[k], &gmt_tz_map[k - 1], sizeof(GMT_TZ_STRUCT)); 
                    }
   
                    memcpy(&gmt_tz_map[j], &tmp_gmt_tz, sizeof(GMT_TZ_STRUCT));
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    
    i = 0;
    gmt_tz_table[0] = 0;

    for (j = 0; j < NUM_CITYS + 2; j++)
    {
        if (gmt_tz_map[j].tzdata_index != 0)
        {
            gmt_tz_table[i + 1] = gmt_tz_map[j].tzdata_index;
        }
        else
        {
            continue;
        }

        i++;
    }

    mmi_dt_gmt_tz_list();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dt_gmt_tz_get_hilite
 * DESCRIPTION
 *  This function is get high light index of city list with index of TimeZoneData
 * PARAMETERS
 *  void
 * RETURNS
 *  S32 high light index
 *****************************************************************************/
static S32 mmi_dt_gmt_tz_get_hilite(U8 cityindex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 1; i < NUM_CITYS + 1; i++)
    {
        if (gmt_tz_table[i] == (cityindex + 1))
            break;
    }

    return (S32)(i - 1);
}
#endif /* !defined(__MMI_HIDE_HOMECITY__) && defined(__MMI_TWO_LAYER_HOMECITY__) */

#ifdef __MMI_TIMEZONE_CHANGE_DATETIME__

/*****************************************************************************
 * FUNCTION
 *  PhnsetGetDateTimeUpdateStatus
 * DESCRIPTION
 *  return current date time update status
 * PARAMETERS
 *  void
 * RETURNS
 *  current date time update  status
 *****************************************************************************/
MMI_BOOL PhnsetGetDateTimeUpdateStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phnset_cntx_p->curDTUpdateStatus)
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
 *  mmi_dt_tz_update_datetime
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void%
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dt_tz_update_datetime(S16 newTimeZone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 increase_flag = 0;
    S16 oldTimeZone;
    //S16 error;
    applib_time_struct rtc_time;
    applib_time_struct tz_diff_mytime;
    applib_time_struct currTime;
    FLOAT tz_dif;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PhnsetGetDateTimeUpdateStatus() == MMI_FALSE)
        return;

    /* NITZ message accept to update time zone ignore */
#ifdef __MMI_NITZ_TZ_SUPPORT__
//     if (g_nitz_cntx.IsNITZPending == MMI_TRUE)
//        return; 
#endif /* __MMI_NITZ_TZ_SUPPORT__ */

    //ReadValue(NVRAM_TIMEZONE, &oldTimeZone, DS_SHORT, &error);
	ReadValueSlim(NVRAM_TIMEZONE, &oldTimeZone, DS_SHORT);

    if (newTimeZone > oldTimeZone)
    {
        increase_flag = 1;
        tz_dif = (FLOAT)(newTimeZone - oldTimeZone) / 4;
    }
    else if (newTimeZone < oldTimeZone)
    {
        increase_flag = 0;
        tz_dif = (FLOAT)(oldTimeZone - newTimeZone) / 4;
    }
    else
    {
        return;
    }
    
    applib_dt_get_rtc_time(&rtc_time);

    tz_diff_mytime = applib_conv_tz_to_mytime(tz_dif);

    if (increase_flag)
    {
        applib_dt_increase_time(&rtc_time, &tz_diff_mytime, &currTime);
    }
    else
    {
        applib_dt_decrease_time(&rtc_time, &tz_diff_mytime, &currTime);
    }

    if (applib_dt_is_valid(&currTime))
    {
        mmi_dt_set_rtc_dt((MYTIME*)&currTime);
    }
    else
    {
        return;
    }
}

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif

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
#endif

/*****************************************************************************
 * FUNCTION
 *  PhnsetDateTimeUpdateLSKHandler
 * DESCRIPTION
 *  This function is Left soft key handler
 * PARAMETERS
 *  void           
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetDateTimeUpdateLSKHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phnset_cntx_p->curDTUpdateStatus != g_phnset_cntx_p->curHightlightItem)
    {
        g_phnset_cntx_p->curDTUpdateStatus = g_phnset_cntx_p->curHightlightItem;
        
        //WriteValue(NVRAM_AUTOUPDATE_DT_STATUS, &(g_phnset_cntx_p->curDTUpdateStatus), DS_BYTE, &error);
		WriteValueSlim(NVRAM_AUTOUPDATE_DT_STATUS, &(g_phnset_cntx_p->curDTUpdateStatus), DS_BYTE);
    }

	mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
    
    mmi_frm_group_close(GRP_ID_PHNSET_CHANGE_DATE_TIME);
}


/*****************************************************************************
 * FUNCTION
 *  EntryPhnsetDateTimeUpdate
 * DESCRIPTION
 *  This function is Left soft key handler
 *  for Phone setup->Date and Time-> Date Time Update
 * PARAMETERS
 *  void           
 * RETURNS
 *  void
 *****************************************************************************/
static void EntryPhnsetDateTimeUpdate(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phnset_appcreate_menucui_create(
        parent_gid,
        GRP_ID_PHNSET_CHANGE_DATE_TIME,
        MENU_ID_TZ_CHANGE_DATETIME,
        mmi_phnset_change_date_time_proc);
}


/*****************************************************************************
 * FUNCTION
 *  HintPhnsetDateTimeUpdateStatus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HintPhnsetDateTimeUpdateStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* hint_str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PhnsetGetDateTimeUpdateStatus())
    {
        g_phnset_cntx_p->curDTUpdateStatus = 1; 
        hint_str = (CHAR*) GetString(STR_GLOBAL_ON);
    }
    else
    {
        g_phnset_cntx_p->curDTUpdateStatus = 0; 
        hint_str = (CHAR*) GetString(STR_GLOBAL_OFF);
    }
    cui_menu_set_item_hint(
        mmi_frm_group_get_active_id(),
        MENU_ID_TZ_CHANGE_DATETIME,
        (WCHAR*)hint_str);
}





/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_change_date_time_proc
 * DESCRIPTION
 *  Menu CUI proc function formmi_phnset_change_date_time 
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_phnset_change_date_time_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        mmi_phnset_init_change_date_time_list();
        break;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
        g_phnset_cntx_p->curHightlightItem = (S32)((cui_menu_event_struct*)param)->highlighted_menu_id;
        PhnsetDateTimeUpdateLSKHandler();
        break;
        
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(mmi_frm_group_get_active_id());
        break;
        
    default:
		break;
    }
    return MMI_RET_OK;
}

 
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_init_change_date_time_list
 * DESCRIPTION
 *  Initialize change date time menu list 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_init_change_date_time_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phnset_radio_button_menu_data_struct radio_button_menu;
    U16 menu_item[] = {STR_GLOBAL_OFF, STR_GLOBAL_ON};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    radio_button_menu.group_id = GRP_ID_PHNSET_CHANGE_DATE_TIME;
    radio_button_menu.menu_title_str_id = STR_ID_TZ_CHANGE_DATETIME_TITLE;
    radio_button_menu.menu_icon_id = MAIN_MENU_TITLE_SETTINGS_ICON;
    radio_button_menu.menu_item_num = 2;
    radio_button_menu.menu_item_str_list = NULL;
    radio_button_menu.menu_item_str_id_list = menu_item;
    radio_button_menu.highlighted_item_idx = g_phnset_cntx_p->curDTUpdateStatus;

    mmi_phnset_init_radio_button_menu(&radio_button_menu); 
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
#endif /* __MMI_TIMEZONE_CHANGE_DATETIME__ */
#endif /* __MMI_TIMEZONE_SETTING__ */

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_time_and_date_sub_menu_handler
 * DESCRIPTION
 *  Proc function for time and date group 
 * PARAMETERS
 *  param   [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_phnset_time_and_date_sub_menu_handler(cui_menu_event_struct *param, MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   switch (param->evt_id)
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        return mmi_phnset_time_and_date_sub_menu_entry_handler(param, parent_gid);

    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
         return mmi_phnset_time_and_date_sub_menu_select_handler(param, parent_gid);

    default:
        break;
    }

    return MMI_RET_DONT_CARE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_init_time_and_date
 * DESCRIPTION
 *  Init menu for time and date setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phnset_init_time_and_date(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID time_and_date_menu_gid = mmi_frm_group_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* hide menu item */
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
#endif /*__MMI_OP11_HOMESCREEN__*/
#endif

#ifdef __MMI_TIMEZONE_SETTING__
#ifdef __MMI_TIMEZONE_CHANGE_DATETIME__
    HintPhnsetDateTimeUpdateStatus();
#endif
#ifndef __MMI_HIDE_HOMECITY__
    HintPhnsetTimeAndDate();
#endif
#endif /* __MMI_TIMEZONE_SETTING__ */
    cui_menu_set_currlist_title_by_id(time_and_date_menu_gid, STR_MENU9141_TIME_AND_DATE, MAIN_MENU_TITLE_SETTINGS_ICON);
    
    cui_menu_set_currlist_flags(time_and_date_menu_gid, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

    cui_menu_set_currlist_left_softkey_by_id(time_and_date_menu_gid, STR_GLOBAL_OK);
    cui_menu_set_currlist_right_softkey_by_id(time_and_date_menu_gid, STR_GLOBAL_BACK);  
    /*
    highlight_menu_id = cui_menu_get_currlist_menu_id_from_index(time_and_date_menu_gid, g_phnset_cntx_p->curHightlightItem);
    cui_menu_set_currlist_highlighted_id(time_and_date_menu_gid, highlight_menu_id);
    */
}



/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_time_and_date_sub_menu_select_handler
 * DESCRIPTION
 *  Select proc function for time and date
 * PARAMETERS
 *  param   [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phnset_time_and_date_sub_menu_select_handler(cui_menu_event_struct *param, MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->highlighted_menu_id)
    {
#ifdef __MMI_TIMEZONE_SETTING__        
    case MENU9142_SETHOMECITY:
#ifdef __MMI_DUAL_CLOCK__
    	g_phnset_cntx_p->city_flag = PHNSET_HOME_CITY; /* home city */
#endif
        g_phnset_cntx_p->curHightlightItem = PHNSET_DT_MNU_HOMECT;
#ifndef __MMI_WC_TZ_SUPPORT__
    	mmi_phnset_entry_set_home_city(parent_gid);
#else
        mmi_phnset_entry_wc_select_city(parent_gid);
#endif
        return MMI_RET_OK;

#ifdef __MMI_DUAL_CLOCK__
    case MENU9142_SETFOREIGNCITY:
    	g_phnset_cntx_p->city_flag = PHNSET_FOREIGN_CITY; /* foreign city */
        g_phnset_cntx_p->curHightlightItem = PHNSET_DT_MNU_FOREIGN_CITY;
#ifndef __MMI_WC_TZ_SUPPORT__

    	mmi_phnset_entry_set_home_city(parent_gid);
#else
        mmi_phnset_entry_wc_select_city(parent_gid);
#endif
        return MMI_RET_OK;
#endif

#if defined(__MMI_TIMEZONE_CHANGE_DATETIME__)
    case MENU_ID_TZ_CHANGE_DATETIME:
        EntryPhnsetDateTimeUpdate(parent_gid);
        return MMI_RET_OK;
#endif
#endif
#if 0
#ifndef __MMI_SEPARATE_DT_SETTING__
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
#endif 
#else
	case MENU9143_SETTIMEANDDATE:
        mmi_phnset_entry_set_date_and_time(parent_gid);
        return MMI_RET_OK;
        
    case MENU9144_SETTIMEANDDATEFORMAT:
        g_phnset_cntx_p->curHightlightItem = PHNSET_DT_MNU_FMT;
        EntryPhnsetSetFormat(parent_gid);
        return MMI_RET_OK;
#endif 
        
    default:
        break;
    }
    return MMI_RET_DONT_CARE;   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_time_and_date_sub_menu_entry_handler
 * DESCRIPTION
 *  Entry proc function for time and date
 * PARAMETERS
 *  param   [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phnset_time_and_date_sub_menu_entry_handler(cui_menu_event_struct *param, MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param->parent_menu_id == MENU9141_TIME_AND_DATE)
    {
        mmi_phnset_init_time_and_date();
        return MMI_RET_OK;
    }
    return MMI_RET_DONT_CARE;
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif


/*
 * Date and time setting service
 */
U8 PhnsetGetTimeFormat(void)
{
    return (U8)srv_setting_get_time_format();
}
 
U8 PhnsetGetDateFormat(void) 
{
    return (U8)srv_setting_get_date_format();
}

U8 PhnsetGetDateSeperatorFormat(void)
{
    return (U8)srv_setting_get_date_seperator();
}
#ifdef __MMI_MAINLCD_96X64__

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_datetime_main_menu_handler
 * DESCRIPTION
 *  proc function for menu cui in GRP_ID_PHNSET_DISP
 * PARAMETERS
 *  param : [IN]    menu cui event
 * RETURNS
 *  process result
 *****************************************************************************/
static mmi_ret mmi_phnset_datetime_main_menu_handler(cui_menu_event_struct *param, MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
      case EVT_ID_CUI_MENU_CLOSE_REQUEST:
       {
         cui_menu_close(mmi_frm_group_get_active_id());
         return MMI_RET_OK; 
       }
    default:
        break;            
    }
    return MMI_RET_DONT_CARE;
}

mmi_ret mmi_phnset_datetime_setup_proc(cui_menu_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menucui_event;
    mmi_ret ret = MMI_RET_DONT_CARE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
     /* Menu CUI event */
    if (cui_menu_is_menu_event(param->evt_id))
    {
        menucui_event = (cui_menu_event_struct*)param;

        ret = mmi_phnset_datetime_main_menu_handler(menucui_event, GRP_ID_PHNSET_DATETIME_MAIN);      
        if (ret != MMI_RET_DONT_CARE)
        {
            return ret;
        }       
        ret= mmi_phnset_time_and_date_sub_menu_handler(menucui_event, GRP_ID_PHNSET_DATETIME_MAIN);
       if (ret != MMI_RET_DONT_CARE)
        {
            return ret;
        }
       return MMI_RET_DONT_CARE;
    }
     return MMI_RET_OK;
}

void EntryPhnsetDateTimeScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
       MMI_ID main_menu_cui_id;
       
       /*----------------------------------------------------------------*/
       /* Code Body                                                      */
       /*----------------------------------------------------------------*/
       mmi_frm_group_create_ex(
           GRP_ID_ROOT,
           GRP_ID_PHNSET_DATETIME_MAIN,
           mmi_phnset_datetime_setup_proc,
           NULL, 
           MMI_FRM_NODE_SMART_CLOSE_FLAG);
       main_menu_cui_id = cui_menu_create(
           GRP_ID_PHNSET_DATETIME_MAIN,
           CUI_MENU_SRC_TYPE_RESOURCE,
           CUI_MENU_TYPE_APPMAIN,
           MENU9141_TIME_AND_DATE,
           MMI_FALSE,
           NULL);      
       cui_menu_set_default_title_image_by_id(main_menu_cui_id, MAIN_MENU_TITLE_SETTINGS_ICON);
       cui_menu_run(main_menu_cui_id);

}
/*****************************************************************************
 * FUNCTION
 *  HighlightPhnsetDateTimeScr
 * DESCRIPTION
 *  This function is highlight handler for DateTime
 *  Follow functions: EntryPhnsetScr
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightPhnsetDateTimeScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryPhnsetDateTimeScr, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(EntryPhnsetDateTimeScr, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif
#endif /* _DATEANDTIME_C */ 

