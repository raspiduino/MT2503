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
 * AlarmDef.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines string, screen, and image ids for alarm application.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/
 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : AlarmDef.h

   PURPOSE     : Alarm application 

   REMARKS     : nil

   AUTHOR      : Gautam Saluja

   DATE     : June 16,03

**************************************************************/
#ifndef _MMI_ALARMDEF_H
#define _MMI_ALARMDEF_H

#include "MMIDataType.h"
#include "DateTimeType.h"
#include "AlarmFrameworkProt.h"
#include "AlarmResDef.h"
#include "FileMgrSrvGprot.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "MMI_features.h"
#include "custom_mmi_default_value.h"
#include "kal_non_specific_general_types.h"
#include "app_datetime.h"
#include "AlarmProt.h"
#include "AlarmSlim.h"

/*****************************************************************************
 * Define
*****************************************************************************/
#ifdef __MMI_ALARM_SLIM__
  	#ifndef __MMI_DEV_NEW_SLIM__
	#define __MMI_DEV_NEW_SLIM__
	#endif
	//#ifndef __MMI_PROFILE_HIGH_PRIORITY__
	//#define __MMI_PROFILE_HIGH_PRIORITY__
	//#endif
#endif
#define MMI_ALM_TRACE0(sub_grp) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp)

#define MMI_ALM_TRACE1(sub_grp, arg) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg)
		
#define MMI_ALM_TRACE2(sub_grp, arg1, arg2) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2)

#define MMI_ALM_TRACE3(sub_grp, arg1, arg2, arg3) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2, arg3)

#define RETURN_IF_FAIL(p) if(!(p)){MMI_ALM_TRACE1(MMI_ALM_ABNORMAL_RETURN, __LINE__); return;}
#define RETURN_VAL_IF_FAIL(p, ret) if(!(p)){MMI_ALM_TRACE1(MMI_ALM_ABNORMAL_RETURN, __LINE__); return (ret);}

#define ALARM_TONE_FILE 0X0308
#define SIZE_OF_DATE_STRING   (13*ENCODING_LENGTH)      /* Jan, 10 2004 + 1 */
#define MAX_SNOOZE_CHANCES 10

/* PMT Pankaj removedd the macro for count of number of menu items in the Edit Alarm screen. */
#define NUM_STATE_FOR_ALM 2

#ifdef __MMI_ALM_SNOOZE_SETTING__
#define ALM_SNOOZE_INTERVAL_SETTING_NUM 4//5

typedef enum
{
   // ALARM_SNOOZE_OFF,
    ALARM_SNOOZE_PERIOD_ONE,
    ALARM_SNOOZE_PERIOD_THREE,
    ALARM_SNOOZE_PERIOD_FIVE,
    ALARM_SNOOZE_PERIOD_TEN
}ALARM_SNOOZE_ENUM;


#endif
#if 0
#ifdef __MMI_TODOLIST__
/* under construction !*/
#else /* __MMI_TODOLIST__ */ 
/* under construction !*/
#endif /* __MMI_TODOLIST__ */ 
#endif /* __MMI_TODOLIST__ */ 

#ifdef __MMI_ALM_CUSTOMIZE_TONE__
#define NUM_AUDIO_OPTIONS 2
#endif 

#define NUM_DAYS 7
#define HOUR_LENGTH 2
#define MINUTE_LENGTH 2
#define COLON_LENGTH  1
#define AM_PM_LENGTH 2
#define SPACE_LENGTH 1
#define SIZE_OF_ALARM_STRING  ((HOUR_LENGTH + MINUTE_LENGTH + COLON_LENGTH + AM_PM_LENGTH + SPACE_LENGTH + 1) * ENCODING_LENGTH)
#define ALARM_FREQ_NUM 3

#define SET_STATE 1
#define UNSET_STATE  0

#ifdef __MMI_ALM_CUSTOMIZE_TONE__
#if 0
#ifdef __MMI_ALM_FM_RADIO_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

typedef enum ALM_AUDIO_OPTIONS
{
    ALM_AUDIO_OPTIONS_TONE,
    ALM_AUDIO_OPTIONS_FMRADIO_CHANNEL,
    ALM_AUDIO_OPTIONS_FMRADIO_MANUAL
} ALM_AUDIO_OPTIONS;
#endif /* __MMI_ALM_CUSTOMIZE_TONE__ */ 

/* +3 for AM /PM */
#ifdef __MMI_ALM_ALERT_TYPE__
#define ALM_ALERT_TYPE_SETTING_NUM 3
#define ALM_ALERT_VIBRATION_AND_RING 0
#define ALM_ALERT_RING 1
#define ALM_ALERT_VIBRATION 2
#endif /* __MMI_ALM_ALERT_TYPE__ */ 


/*****************************************************************************
 * Typedef 
*****************************************************************************/
typedef struct
{
    S32 CurrHiliteState;                                /* enabled or disabled state */
    S32 CurrHiliteFreq;                                 /* index of current selected frequency, used in inline selection */
#ifdef __MMI_ALM_CUST_VOLUME__
    S32 CurrHiliteVol;                                  /* index of current highlighted volume */
#endif 
	// move AlmList to 
    //alm_nvram_struct AlmList[NUM_OF_ALM];
    U8 curr_hour;
    U8 curr_min;
#ifdef __MMI_BTD_BOX_UI_STYLE__
    U8 time_text[40];                                   /* store time item display buffer */
#endif
    U8 CurrHiliteAlarm;                                 /* index of current highlighted alarm */
#ifndef __MMI_DEV_NEW_SLIM__ 	
    U8 IsSaveToHistory;                                 /* shall alarm screen save to history or not */
#endif	
    U8 IsDOWSet;                                        /* to see if DOW component is enabled */
    U8 CurrHiliteSetting;
#ifdef __MMI_ALM_CUSTOMIZE_TONE__
    S32 CurrHiliteAudioOption;                          /* the current alarm's audio option */
    U16 CurrHiliteAudioOptionValue;                     /* The value can be <Ring Tone ID> or <FM Frequency> or <Channel List ID> */
#ifndef __MMI_ALARM_SLIM2__
    U8 tone_path[SRV_FMGR_PATH_BUFFER_SIZE];  /* Selected tone path*/
#endif
    MMI_BOOL audio_select;
#endif /* __MMI_ALM_CUSTOMIZE_TONE__ */ 
#ifdef __MMI_ALM_ALERT_TYPE__
    S32 CurrHilightAlertType;
#endif 
#ifdef __MMI_ALM_SNOOZE_SETTING__
    S32 CurrHilightSnoozeInterval;
	U8 CurrHiliteSnoozeValue;
#endif
    U16 curr_gid;    /* current group id */
    U16 user_tag;
    MMI_BOOL vibing;
    U16 default_tone;
	U8 active_alm_idx;
	MMI_BOOL is_tone_playing;
	MMI_BOOL IsExitByTimer;
} alm_context_struct;

#ifndef NUM_MONTHS
#define NUM_MONTHS 12
#define NUM_MIN_HR  60
#define NUM_HRS_DAY  24

typedef enum MONTH_LIST
{
    JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
} MONTH_LIST;
#endif /* NUM_MONTHS */ 

typedef enum TIME_EQUALITY
{
    TIME_LESS = -1,
    TIME_EQUAL,
    TIME_GREATER
} TIME_EQUALITY;

typedef enum
{
//#ifdef __MMI_INLINE_SLIM__
#ifdef __MMI_DEV_NEW_SLIM__
#ifndef __MMI_MAINLCD_96X64__
    MMI_ALM_INLINE_STATUS_CAPTION,
#endif
#endif
    MMI_ALM_INLINE_STATUS, 
#ifdef __MMI_DEV_NEW_SLIM__
#ifndef __MMI_MAINLCD_96X64__
	MMI_ALM_INLINE_TIME_CAPTION,
#endif
#endif
    MMI_ALM_INLINE_TIME, 
#ifdef __MMI_ALM_SNOOZE_SETTING__
#ifndef __MMI_MAINLCD_96X64__
    MMI_ALM_INLINE_SNOOZE_CAPTION,
#endif
    MMI_ALM_INLINE_SNOOZE,
#endif

#ifndef __MMI_MAINLCD_96X64__
    MMI_ALM_INLINE_REPEAT_CAPTION, 
#endif
    MMI_ALM_INLINE_REPEAT, 
#ifdef __ORIGINAL_DOW__
    MMI_ALM_INLINE_DOW,
#endif /* __ORIGINAL_DOW__ */
#ifdef __MMI_ALM_CUST_VOLUME__
    MMI_ALM_INLINE_CUST_VOL_CAPTION,
    MMI_ALM_INLINE_CUST_VOL,
#endif 
#ifdef __MMI_ALM_CUSTOMIZE_TONE__
#ifndef __MMI_MAINLCD_96X64__
    MMI_ALM_INLINE_TONE_CAPTION,
#endif
#if 0
#ifdef __MMI_ALM_FM_RADIO_SUPPORT__    
/* under construction !*/
#endif    
#endif    
    MMI_ALM_INLINE_TONE_STRING,
#endif 
#ifdef __MMI_ALM_ALERT_TYPE__
#ifndef __MMI_MAINLCD_96X64__
    MMI_ALM_INLINE_ALERT_TYPE_CAPTION,
#endif
    MMI_ALM_INLINE_ALERT_TYPE,
#endif 
	MMI_ALM_INLINE_TOTAL
}mmi_alm_inline_enum;

/*****************************************************************************
* Global variable
*****************************************************************************/

extern alm_context_struct g_alm_cntx;

#endif /* _MMI_ALARMDEF_H */ // #ifndef _MMI_ALARMDEF_H

