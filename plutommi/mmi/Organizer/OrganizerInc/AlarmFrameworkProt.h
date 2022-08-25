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
 * AlarmFrameworkProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is defines constant, enum value, structure, and function prototypes used in alarm framework.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

   FILENAME : AlarmFrameWorkProt.h

   PURPOSE     : Alarms application 

   REMARKS     : nil

   AUTHOR      : NEERAJ SHARMA

   DATE     : Jun 16,03

**************************************************************/

#ifndef _PIXTEL_ALARMFRAMEWORKPROT_H
#define _PIXTEL_ALARMFRAMEWORKPROT_H

#include "MMI_features.h"
#include "DateTimeType.h"
#include "custom_mmi_default_value.h"

    #include "MMIDataType.h"
    #include "kal_non_specific_general_types.h"

#include "ReminderSrvGprot.h"
#include "AlarmProt.h"
#include "AlarmDef.h"
/* 
 * Define
 */

#define  ALM_ALL_DAYS         0x7F           /* Week day mask */
#define  ALM_WEEK_DAYS        0x3e           /* 0111110, default day of week */

#define  ALM_SNOOZE_INTERVAL  4              /* in minutes */
#define  ALM_EXPIRE_DURATION     30000       /* alarm expire duration 30 sec */

#define  ALM_FACTORY_RTC_TIME 3              /* factory rtc time 3 second */

#define ALM_DEFAULT_EXPIRY_PERIOD  30        /* default expire period */ 
#define ALM_WITHOUD_EXPIRY_PERIOD  0         /* Not wait time for expire */

/* 
 * Typedef 
 */
#ifndef __MMI_DEV_NEW_SLIM__
/* context struct for alarm framework */
typedef struct
{
    U8 CurrAlmIndex;                        /* index of current expired alarm */
    U8 EnabledAlarms;                       /* number of alarms waiting for excuting */
    U8 IsAlmTonePlaying;                    /* weather play tone */
    U8 IsPwronAlarm;                        /* tells if power on is bcos of alarm */
    U8 IsExitByTimer;                       /* if exit by timer */
    U8 IsWaitForPwroff;                     /* if wait for power off */
    U8 IsPendingAlm;                        /* if alarm expire but cannot be excute due to some reasons */
    U8 IsSpofDisabled;                      /* if schedule power off disabled */
    U8 IsExpiryDisabled;                    /* if expiried alarm disabled */
    U8 IsATPwrOffAnimation;                 /* if animation play the power off */
    U8 ATPwrCycle;                          /* if AT mode power on */
    U8 IsAppExecuting;                      /* if application is executing and could not power off */
} alm_framework_context_struct;


/* alarm queue node struct */
typedef struct
{
    MYTIME Time;                            /* alarm time */
    U8 Index;                               /* alarm node index */
    U8 IsExpired;                           /* if expired */
} alm_queue_node_struct;


/* start indexes for alarm types */
typedef enum
{
    ALM_SPON_START = 0,                                     /* schedule power on alarm start index */
    ALM_THM_START = (ALM_SPON_START + NUM_OF_SPOF),         /* theme update alarm start index */
    ALM_TDL_START = (ALM_THM_START + NUM_OF_THM_ALM),       /* todolist alarm start index */
    ALM_CAL_START = (ALM_TDL_START + NUM_OF_TASK),
    ALM_ALM_START = (ALM_CAL_START + NUM_OF_CAL),           /* alarm start index */
    ALM_AZAAN_START = (ALM_ALM_START + NUM_OF_ALM),         /* Azaan alarm start index */
    ALM_FMSR_START = (ALM_AZAAN_START + NUM_OF_AZAAN),      /* schedule FM alarm start index */
    ALM_FMRDO_START = (ALM_FMSR_START + NUM_OF_FMSR),       /* FM alarm start index */
    ALM_SPOF_START = (ALM_FMRDO_START + NUM_OF_FMRDO),      /* schedule power off alarm start index */
    ALM_FACTORY = (ALM_SPOF_START + NUM_OF_SPOF),           /* factory alarm start index */
    ALM_BIRTHDAY,                                           /* birthday alarm start index */
    ALM_PWR_RESET,                                          /* resets alarm start index */
    ALM_SYNCML,                                             /* 1 alarm for syncml */
    ALM_LANGLN = (ALM_SYNCML + NUM_OF_SYNCML),              /* language alarm start index */
    ALM_INDEX_TOTAL                                         /* total */
} ALM_INDEX_ENUM;


/* weather have indicated */
typedef enum
{
    ALM_HAS_NO_IND = 0,              /* not indicate */                                     
    ALM_HAS_IND                      /* has indicated */
} ALM_INDICATION_ENUM;
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_THEMES_APPLICATION__
/* under construction !*/
#endif 
#ifdef __MMI_TODOLIST__
/* under construction !*/
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __MMI_AZAAN_ALARM__
/* under construction !*/
#endif /* __MMI_AZAAN_ALARM__ */ 
#if defined(__MMI_FM_RADIO_SCHEDULE_REC__)
/* under construction !*/
#endif 
#ifdef __MMI_FM_RADIO_SCHEDULER__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (defined(__SYNCML_SUPPORT__) && !defined(__MMI_OP01_SYNCML_SETTING__))
/* under construction !*/
#endif
#if (defined(__MMI_LANGLN_WK_ALARM__))
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* alarm repeat reminder types */
typedef enum
{
    ALM_FREQ_OFF = SRV_REMINDER_REPEAT_OFF,          /* alarm off */
    ALM_FREQ_ONCE = SRV_REMINDER_REPEAT_ONCE,         /* alarm once */
    ALM_FREQ_HOURLY = SRV_REMINDER_REPEAT_HOURLY,       /* hourly repeat */
    ALM_FREQ_EVERYDAY = SRV_REMINDER_REPEAT_EVERYDAY,     /* everyday repeat */
    ALM_FREQ_DAYS = SRV_REMINDER_REPEAT_DAYS,         /* specific DOWs repeat */ 
    ALM_FREQ_WEEKLY = SRV_REMINDER_REPEAT_WEEKLY,       /* weekly repeat */
    ALM_FREQ_MONTHLY = SRV_REMINDER_REPEAT_MONTHLY,      /* monthly repeat */
    ALM_FREQ_SEASONALLY = SRV_REMINDER_REPEAT_SEASONLY,   /* secondly repeat */
    ALM_FREQ_YEARLY = SRV_REMINDER_REPEAT_YEARLY,       /* yearly repeat */ 
#ifdef __MMI_INDICAL__
    ALM_FREQ_TITHI = SRV_REMINDER_REPEAT_TITHI,
#endif /* __MMI_INDICAL__ */
    ALM_FREQ_TOTAL         /* total */
} FREQ_ALARM;

extern void PendingAlarmReminder(void);

extern U8 AlmIsRTCPwron(void);

extern void AlmReInitialize(void);

extern U8 AlmIsTonePlaying(void);

extern MMI_BOOL mmi_alm_is_in_alarm(void);
extern void AlmATPowerReset(U8 power_off, U8 time);
#ifndef __MMI_DEV_NEW_SLIM__
typedef void (*ExpiryTimeCBPtr) (U8, MYTIME *, U8 *, U8 *, MYTIME *);
typedef U8(*ExpiryHandlerCBPtr) (U8 index, U16 *period, BOOL power_on);
typedef void (*InitAlarmNvramCBPtr) (void);
typedef void (*ReInitAlarmQueueCBPtr) (void);
typedef void (*StopAlarmCBPtr) (void);

/* alarm framework callback function structure for other applications */
typedef struct
{
    U8 alarmStartIndex;								/* alarm start index of application */
    ExpiryTimeCBPtr expiryTimeCBPtr;				/* callback function to get application alarm information */
    ExpiryHandlerCBPtr expiryHandlerCBPtr;			/* alarm expiry handler when alarm time */
    InitAlarmNvramCBPtr initAlarmNvramCBPtr;		/* init function of applications */
    ReInitAlarmQueueCBPtr reInitAlarmQueueCBPtr;	/* reinit alarm queue information after date and time change */
    StopAlarmCBPtr stopAlarmCBPtr;					/* time out function after alarm expiry end */
} AlarmCallback;

/* 
 * Extern Global Variable
 */

extern alm_framework_context_struct g_alm_frm_cntx;   /* alarm framework context */
#if 0
/* under construction !*/
#endif
//extern S8 *gAlmFreqList[ALM_FREQ_TOTAL];    /* alarm frequent type list */

/* 
 * Extern Global Function
 */


extern void InitAlarmFrameWork(void);
extern void AlmDeInit(void);

extern void AlmInitRTCPwron(void);


extern void PendingAlarmInPwronPeriod(void);


/*****************************************************************************
 * FUNCTION
 *  AlmSendPowerOn
 * DESCRIPTION
 *  Display check disk screen, reset language, then send power on request.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void AlmSendPowerOn(void);


/*****************************************************************************
 * FUNCTION
 *  AlmSendPowerOff
 * DESCRIPTION
 *  Send power off request.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void AlmSendPowerOff(void);


/*****************************************************************************
 * FUNCTION
 *  AlmExecPwrOffAlarm
 * DESCRIPTION
 *  RTC power on handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void AlmExecPwrOffAlarm(void);


/*****************************************************************************
 * FUNCTION
 *  AlmExecPwrOnAlarm
 * DESCRIPTION
 *  Popup one alarm entry from queue and execute corresponding handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void AlmExecPwrOnAlarm(void);


/*****************************************************************************
 * FUNCTION
 *  AlmSetAlarm
 * DESCRIPTION
 *  To insert alarm into queue and register the nearest alarm to RTC.
 *  Update alarm profile of L4C if it's normal alarm.
 * PARAMETERS
 *  index : [IN] Index of alarm
 * RETURNS
 *  void
 *****************************************************************************/
extern void AlmSetAlarm(U8 index);


/*****************************************************************************
 * FUNCTION
 *  AlmCancelAlarm
 * DESCRIPTION
 *  To remove alarm from queue and register the nearest alarm to RTC.
 *  Update alarm profile of L4C if it's normal alarm.
 * PARAMETERS
 *  index : [IN] Index of alarm
 * RETURNS
 *  void
 *****************************************************************************/
extern void AlmCancelAlarm(U8 index);


extern void AlmCancelMulltiAlarm(U8* index, U8 amount);


/*****************************************************************************
 * FUNCTION
 *  AlmGetStringValue
 * DESCRIPTION
 *  Compute the string value of given integer. The string will dispaly exact 2 digits.
 * PARAMETERS
 *  StringVal : [IN/OUT] Pointer to store the result.
 *  Val : [IN] Value to be computed
 * RETURNS
 *  void
 *****************************************************************************/
extern void AlmGetStringValue(S8 *StringVal, U8 Val);

extern void AlmSetExpiryTimeCB(U8 AlmType, ExpiryTimeCBPtr funcPtr);

extern void AlmSetExpiryHandlerCB(U8 AlmType, ExpiryHandlerCBPtr expiryHandler);


extern void AlmSetInitHandlerCB(U8 AlmType, InitAlarmNvramCBPtr initNvram, ReInitAlarmQueueCBPtr reInitQueue);
extern void AlmSetStopAlarmCB(U8 AlmType, StopAlarmCBPtr stopAlarm);
extern void mmi_alm_set_start_index(U8 AlmType, U8 startIndex);


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_get_index_from_queue
 * DESCRIPTION
 *  get alarm index from queue.
 * PARAMETERS
 *  num  : [IN] Nth item of alarm queue      
 * RETURNS
 *  alarm index
 *****************************************************************************/
extern U8 mmi_alm_get_index_from_queue(U8 num);


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_get_freq_order
 * DESCRIPTION
 *  Get frequency index of inline selection.
 * PARAMETERS
 *  freqNum : [IN] frequent numbers     
 *  freqSet : [IN] frequent set      
 *  freq : [IN] frequent enum value
 * RETURNS
 *  void
 *****************************************************************************/
extern U8 mmi_alm_get_freq_order(U8 freqNum, const U8 *freqSet, U8 freq);


extern void AlmStartAlarmOnHW(MYTIME alarmTime);
extern void AlmStopAlarmOnHW(void);


/*****************************************************************************
 * FUNCTION
 *  AlmInsertIntoQueue
 * DESCRIPTION
 *  Insert an alarm node to the queue.
 * PARAMETERS
 *  index  : [IN] Index of alarm
 *  saveflag : [IN] Flag to determine save directly to NVRAM or not
 * RETURNS
 *  The position of alarm in queue.
 *****************************************************************************/
extern U8 AlmInsertIntoQueue(U8 index, U8 saveflag);


extern U8 AlmRemoveFromQueue(U8 index, U8 saveflag);
extern U8 AlmFindNodeInQueue(U8 index);
#define AlmActualTime srv_reminder_calc_time;

/*****************************************************************************
 * FUNCTION
 *  AlmGetType
 * DESCRIPTION
 *  To get the type of alarm
 * PARAMETERS
 *  index : [IN] Index of alarm
 * RETURNS
 *  Enum value of alarm type
 *****************************************************************************/
extern U8 AlmGetType(U8 index);


extern void AlmWriteQueueToNvram(void);
extern void AlmInitQueue(void);
extern U8 AlmGetRepeat(U8 index);
extern void AlmExpiryHandler(void *msg);
extern void AlmExitPreviousAlarm(void);
extern void AlmSetAlarmRSP(void *msg);


/*****************************************************************************
 * FUNCTION
 *  AlmHandleAlarmTimeout
 * DESCRIPTION
 *  Timer expiry handler for normal alarm.
 *  Exit previous alarm screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void AlmHandleAlarmTimeout(void);


/*****************************************************************************
 * FUNCTION
 *  AlmHandlePendingTimeout
 * DESCRIPTION
 *  Execute pending alarm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void AlmHandlePendingTimeout(void);


extern void AlmCheckAlarmState(void);


/*****************************************************************************
 * FUNCTION
 *  AlmInitLCDModule
 * DESCRIPTION
 *  Initialize main and sub lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void AlmInitLCDModule(void);


extern MYTIME AlmGetAlarmTime(U8 index);




extern void FactoryExpiryTimeCB(U8 index, MYTIME *alarmTime, U8 *Freq, U8 *WeekDays, MYTIME *preReminder);
extern void ResetExpiryTimeCB(U8 index, MYTIME *alarmTime, U8 *Freq, U8 *WeekDays, MYTIME *preReminder);
extern U8 ResetExpiryHandler(U8 index, U16 *period, BOOL power_on);
extern U8 mmi_alm_spof_disable_check(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_almfrm_exist_recent_alarm
 * DESCRIPTION
 *  next alarm will be coming
 * PARAMETERS
 *  void
 * RETURNS
 *	MMI_FALSE
 *	MMI_TRUE
 *****************************************************************************/
extern MMI_BOOL mmi_almfrm_exist_recent_alarm(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_almfrm_notify_finish
 * DESCRIPTION
 *  check the next alarm
 * PARAMETERS
 *  stop		:[IN]	stop or snooze the current alarm
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_almfrm_notify_finish(U8 stop);
#endif


#if (defined(__MMI_ENGINEER_MODE__))      /* Robin Add 1001 for MMI Feature */

/*****************************************************************************
 * FUNCTION
 *  FactorySetAlarm
 * DESCRIPTION
 *  Set facrtory mode alarm.
 * PARAMETERS
 *  sec : [IN] Not used  
 * RETURNS
 *  void
 *****************************************************************************/
extern void FactorySetAlarm(U8 sec);


extern U8 FactoryExpiryHandler(U8 Index, U16 *period, BOOL power_on);
#endif /* defined(__MMI_ENGINEER_MODE__)) */ 

#ifndef __MMI_DEV_NEW_SLIM__

extern void AlmEnableExpiryHandler_Ext(S8* file, U32 line);
extern void AlmDisableExpiryHandler_Ext(S8* file, U32 line);

extern void AlmEnableSPOF_Ext(S8* file, U32 line);
extern void AlmDisableSPOF_Ext(S8* file, U32 line);

extern void mmi_alm_enable_pwroff_ext(S8* file, U32 line);
extern void mmi_alm_disable_pwroff_ext(S8* file, U32 line);

/* Enable all kinds of alarm function */
#define AlmEnableExpiryHandler()    AlmEnableExpiryHandler_Ext(NULL, __LINE__)

/* Disable all kinds of alarm function */
#define AlmDisableExpiryHandler()   AlmDisableExpiryHandler_Ext(NULL, __LINE__)

/* Enable schedule power off alarm function */
#define AlmEnableSPOF()     AlmEnableSPOF_Ext(NULL, __LINE__)

/* Disable schedule power off alarm function */
#define AlmDisableSPOF()    AlmDisableSPOF_Ext(NULL, __LINE__)

/* set enable power off mobile when alarm expiry end */
#define mmi_alm_enable_pwroff()     mmi_alm_enable_pwroff_ext(NULL, __LINE__)

/* can't power off mobile when alarm expiry */
#define mmi_alm_disable_pwroff()    mmi_alm_disable_pwroff_ext(NULL, __LINE__)

#endif

#endif /* _PIXTEL_ALARMFRAMEWORKPROT_H */ 

