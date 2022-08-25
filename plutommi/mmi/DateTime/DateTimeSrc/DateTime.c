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
 * DateTime.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 * This file implements date/time related utilities for other applications
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2004
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * DateTime.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file implements date/time related utilities for other applications
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : DateTime.c

   PURPOSE     : Utility functions to enable date and time display on idle screen

   REMARKS     : nil

   AUTHOR      : Neeraj Sharma, Vijay Vaidya

   DATE     : Aug' 28, 2002

**************************************************************/

    #include "MMI_features.h"
#ifndef _MMI_DATETIME_C
#define _MMI_DATETIME_C

/*  Include: MMI header file */
#include "Stdafx.h"
#include "DateTimeType.h"
#include "DateTimeGprot.h"
#include <time.h>

#include "AlarmFrameworkProt.h"
#include "SettingStructs.h"
#include "ProtocolEvents.h"
#include "ScrSaverGprot.h"
#include "UCMSrvGprot.h"

#ifdef __MMI_LCD_PARTIAL_ON__
#include "IdleAppProt.h"
#endif 

#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
#include "DTVPlayerGProt.h"
#endif  /* __MMI_MOBILE_TV_CMMB_SUPPORT__ */

#if defined(__VENUS_UI_ENGINE__)
#include "vdat_systime.h"
#endif /* __VENUS_UI_ENGINE__*/

#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
#include "ToDoListGprot.h" /* Homescreen 3.1 update sidebar */
#include "AlarmGprot.h"
#endif

#if !defined(__COSMOS_MMI__)
#include "mmi_rp_app_worldclock_def.h"
#endif
#include "mmi_rp_srv_datetime_def.h"
/*  Include: PS header file */


    #include "custom_mmi_default_value.h"
    #include "MMIDataType.h"
    #include "ps_public_struct.h"
    #include "kal_general_types.h"
    #include "mmi_frm_nvram_gprot.h"
    #include "mmi_frm_queue_gprot.h"
    #include "app_ltlcom.h"
    #include "mmi_msg_struct.h"
    #include "device.h"
    #include "app_datetime.h"
    #include "stack_config.h"
    #include "stack_msgs.h"
    #include "stack_common.h"
    #include "mmi_frm_events_gprot.h"
    #include "kal_public_api.h"
    #include "DebugInitDef_Int.h"
    #include "wgui_categories_util.h"
    #include "mmi_frm_timer_gprot.h"
    #include "MMI_common_app_trc.h"
    #include "mmi_common_app_trc.h"
    #include "kal_trace.h"
    #include "wgui_include.h"

#ifdef __MMI_WEARABLE_DEVICE__
#include "SwatchGprot.h"
#endif  //__MMI_WEARABLE_DEVICE__
/* 
 * Define
 */
#define  DT_UTC_BASE_YEAR  1970
#define  DT_MONTH_PER_YEAR    12
#define  DT_DAY_PER_YEAR         365
#define  DT_SEC_PER_DAY    86400
#define  DT_SEC_PER_HOUR      3600
#define  DT_SEC_PER_MIN    60
#define MMI_DT_YEAR_BOUNDARY     30


/* 
 * Typedef 
 */
typedef struct {
	mmi_dt_set_time_res_funcptr res_callback;
	MYTIME set_time;
#ifdef __MMI_BT_DIALER_SUPPORT__
	MYTIME old_time;
#endif /* __MMI_BT_DIALER_SUPPORT__ */
	void* usr_data;
}mmi_dt_cntx;
/* 
 * Local Variable
 */
 
static mmi_dt_cntx g_mmi_dt_cntx;

/* 
 * Local Function
 */
static void DTResetTime(void);
static void mmi_dt_set_rtc_dt_rsp(void* param);
static void mmi_dt_change_notify(const MYTIME *old_time, const MYTIME *new_time);
static void mmi_dt_conv_rtc2_mytime(MYTIME *out_time,  const rtc_format_struct *in_time);
static void mmi_dt_conv_mytime2_rtc(rtc_format_struct *out_time, const MYTIME *in_time);

/* 
 * Global Variable
 */

extern U8 g_dst;

#ifndef __MTK_TARGET__
extern MYTIME MyTime;

#else
/* Dynamicly update the home city's datetime for world clock */
#ifdef __MMI_WORLD_CLOCK__
extern void mmi_wc_update_datetime(void);
#endif

#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
#endif 

#endif /* __MTK_TARGET__ */

extern rtc_format_struct gclockData;

#if !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__)
extern MMI_BOOL srv_backlight_is_lcd_sleep(void);
#endif 
/* 
 * Global Function
 */
extern FLOAT GetTimeZone(U8);
extern U8 PhnsetGetHomeCity(void);

#ifdef  __MMI_CALENDAR_ON_IDLE_SCREEN__
extern void mmi_clndr_set_calendar_on_idle(void);
extern void wgui_calendar_idle_update(void);
#endif /*__MMI_CALENDAR_ON_IDLE_SCREEN__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_dt_get_tz
 * DESCRIPTION
 *  Get current time zone of MMI
 * PARAMETERS
 *  void
 * RETURNS
 *  time zone of current home city.
 *****************************************************************************/
FLOAT mmi_dt_get_tz(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetTimeZone(PhnsetGetHomeCity());
}


#if !defined(__COSMOS_MMI__)
/*****************************************************************************
 * FUNCTION
 *  mmi_dt_set_dst
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dt_set_dst(U8 dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // WriteValue(NVRAM_SETTING_DT_DST, &dst, DS_BYTE, &error);
	WriteValueSlim(NVRAM_SETTING_DT_DST, &dst, DS_BYTE);
    g_dst = (U8) dst;
}

#endif /*  */

void mmi_dt_set_dt(const MYTIME *time, mmi_dt_set_time_res_funcptr callback, void* usr_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_mmi_dt_cntx.res_callback = callback;
	g_mmi_dt_cntx.usr_data = usr_data;

	mmi_dt_set_rtc_dt((MYTIME *)time);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dt_set_rtc_dt
 * DESCRIPTION
 *  This function is to send set time request to L4
 *  Functionality:
 * PARAMETERS
 *  t       [?]     [?]
 *  a(?)        [IN/OUT](?)
 *  b(?)        [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dt_set_rtc_dt(MYTIME *t)
{

	
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_rtc_time_req_struct *time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SetProtocolEventHandler(mmi_dt_set_rtc_dt_rsp, HW_SET_TIME_REQ_SUCCESS);
	g_mmi_dt_cntx.set_time = *t;
	
    time = OslAllocDataPtr(mmi_eq_set_rtc_time_req_struct);
	
    time->info.alarm_format = 0;
    time->info.alarm_index = 0;
    time->info.type = 0;
    time->info.text[0] = '\0';
    time->info.recurr = 0;
    time->info.data_time.rtc_sec = t->nSec;
    time->info.data_time.rtc_min = t->nMin;
    time->info.data_time.rtc_hour = t->nHour;

    time->rtc_type = RTC_TIME_CLOCK_IND;
    time->set_type = RTC_SETTING_TYPE_DATETIME;
    time->info.data_time.rtc_day = t->nDay;
    time->info.data_time.rtc_mon = t->nMonth;
    time->info.data_time.rtc_year = t->nYear - YEARFORMATE;
    time->info.data_time.rtc_wday = applib_dt_dow(t->nYear, t->nMonth, t->nDay);

#ifdef __MMI_BT_DIALER_SUPPORT__
    DTGetRTCTime(&g_mmi_dt_cntx.old_time);
#endif /* __MMI_BT_DIALER_SUPPORT__ */
	mmi_frm_send_ilm(MOD_L4C, HW_SET_TIME_REQ, (oslParaType *)time, NULL);
	
#else /* __MTK_TARGET__ */ 
	mmi_eq_set_rtc_time_rsp_struct rsp;
	SetProtocolEventHandler(mmi_dt_set_rtc_dt_rsp, HW_SET_TIME_REQ_SUCCESS);

	g_mmi_dt_cntx.set_time = *t;
    MyTime = *t;

	rsp.result = 1;
	mmi_dt_set_rtc_dt_rsp(&rsp);

#endif /* __MTK_TARGET__ */

	//SetProtocolEventHandler(mmi_dt_set_rtc_dt_rsp, HW_SET_TIME_REQ_SUCCESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dt_set_rtc_dt_rsp
 * DESCRIPTION
 *  Function to set date and time information to global variable of MMI
 * PARAMETERS
 *  t       [IN]        Struct variable that stores date and time information from PS
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dt_set_rtc_dt_rsp(void* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_rtc_time_rsp_struct *res_ptr;
	MYTIME old_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(param != NULL);
	res_ptr = (mmi_eq_set_rtc_time_rsp_struct*)(param);
	
	if (res_ptr->result == 1)
	{
    #ifdef __MTK_TARGET__

		mmi_dt_conv_rtc2_mytime(&old_time, &gclockData);
	
        gclockData.rtc_year = g_mmi_dt_cntx.set_time.nYear- YEARFORMATE;
        gclockData.rtc_mon = g_mmi_dt_cntx.set_time.nMonth;
        gclockData.rtc_day = g_mmi_dt_cntx.set_time.nDay;
        gclockData.rtc_hour = g_mmi_dt_cntx.set_time.nHour;
        gclockData.rtc_min = g_mmi_dt_cntx.set_time.nMin;
    #else /* __MTK_TARGET__ */
		old_time = MyTime;
		MyTime = g_mmi_dt_cntx.set_time;
        DateTimerProc();
    #endif /* __MTK_TARGET__ */ 
#ifdef __MMI_BT_DIALER_SUPPORT__
	mmi_dt_change_notify(&g_mmi_dt_cntx.old_time, &g_mmi_dt_cntx.set_time);
#else
	mmi_dt_change_notify(&old_time, &g_mmi_dt_cntx.set_time);
#endif /* __MMI_BT_DIALER_SUPPORT__ */
	
#if defined(__VENUS_UI_ENGINE__)
        vdat_system_time_changed_handler();
#endif /* __VENUS_UI_ENGINE__ */

		/* update idle time */
        update_mainlcd_dt_display();
        update_sublcd_dt_display();

        AlmReInitialize();
	}

	if (g_mmi_dt_cntx.res_callback != NULL)
	{
		g_mmi_dt_cntx.res_callback((MMI_BOOL)(res_ptr->result == 1), g_mmi_dt_cntx.usr_data);
		g_mmi_dt_cntx.res_callback = NULL;
		g_mmi_dt_cntx.usr_data = NULL;
	}
}

/*****************************************************************************
 * FUNCTION
 *  SetDateTime
 * DESCRIPTION
 *  Function to set date and time information to global variable of MMI
 * PARAMETERS
 *  t       [IN]        Struct variable that stores date and time information from PS
 * RETURNS
 *  void
 *****************************************************************************/
void SetDateTime(void *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    rtc_format_struct *local_data = (rtc_format_struct*) t;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__

	memcpy(&gclockData, local_data, sizeof(rtc_format_struct));

    if (gclockData.rtc_year > MMI_DT_YEAR_BOUNDARY)
    {
        gclockData.rtc_year = 0;    /* reset to 2000 */
        DTResetTime();
    }
#else /* __MTK_TARGET__ */ 
	MyTime.DayIndex = local_data->rtc_wday;
	MyTime.nYear = local_data->rtc_year;
	MyTime.nMonth = local_data->rtc_mon;
	MyTime.nDay = local_data->rtc_day;
	MyTime.nHour = local_data->rtc_hour;
	MyTime.nMin = local_data->rtc_min;
	MyTime.nSec = local_data->rtc_sec;
#endif /* __MTK_TARGET__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  DTResetTimeRsp
 * DESCRIPTION
 *  Response handler of reset date/time.
 * PARAMETERS
 *  rsp     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void DTResetTimeRsp(void *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AlmReInitialize();
    SetProtocolEventHandler(L4SetClockRSP, MSG_ID_MMI_EQ_SET_RTC_TIME_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  DTResetTime
 * DESCRIPTION
 *  Reset Date/Time function when time reaches boundary
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void DTResetTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_rtc_time_req_struct *time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time = OslAllocDataPtr(mmi_eq_set_rtc_time_req_struct);
    time->info.alarm_format = 0;
    time->info.alarm_index = 0;
    time->info.type = 0;
    time->info.text[0] = '\0';
    time->info.recurr = 0;

    time->rtc_type = RTC_TIME_CLOCK_IND;
    time->set_type = RTC_SETTING_TYPE_DATETIME;
    time->info.data_time.rtc_sec = 0;
    time->info.data_time.rtc_min = gclockData.rtc_min;
    time->info.data_time.rtc_hour = gclockData.rtc_hour;
    time->info.data_time.rtc_day = gclockData.rtc_day;
    time->info.data_time.rtc_mon = gclockData.rtc_mon;
    time->info.data_time.rtc_wday = gclockData.rtc_wday;
    time->info.data_time.rtc_year = gclockData.rtc_year;

	mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_EQ_SET_RTC_TIME_REQ, (oslParaType *)time, NULL);

    SetProtocolEventHandler(DTResetTimeRsp, MSG_ID_MMI_EQ_SET_RTC_TIME_RSP);

}


/*****************************************************************************
 * FUNCTION
 *  DateTimerIndication
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_EQ_CLOCK_TICK_IND.
 *  1. Update global variable in MMI.
 *  2. Update date/time display in IDLE screen.
 * PARAMETERS
 *  p       [?]     [?]
 *  t(?)        [IN]        Struct variable that stores date and time information from PS(?)
 * RETURNS
 *  void
 *****************************************************************************/
void DateTimerIndication(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifdef __MTK_TARGET__
    mmi_eq_clock_tick_ind_struct *local_data = (mmi_eq_clock_tick_ind_struct*) p;

#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
    MMI_BOOL update_static_cal = MMI_FALSE;
#endif

#ifdef __MMI_WORLD_CLOCK__
    MMI_BOOL update_wc_flag = MMI_FALSE;
#endif

#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
#endif

    MMI_BOOL update_min = MMI_FALSE;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_DTTM_TRACE_001);
	if (gclockData.rtc_day != local_data->rtc_time.rtc_day)
    {
#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__       
	 update_static_cal = MMI_TRUE;
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
 
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
#endif
    }

#ifdef __MMI_WORLD_CLOCK__
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_DTTM_TRACE_002, gclockData.rtc_min, local_data->rtc_time.rtc_min);

    if (gclockData.rtc_min != local_data->rtc_time.rtc_min)
    {
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_DTTM_TRACE_003);
        update_wc_flag = MMI_TRUE;
    }
#endif /* __MMI_WORLD_CLOCK__ */

    if (gclockData.rtc_min != local_data->rtc_time.rtc_min)
    {
        update_min = MMI_TRUE;
    }   

    SetDateTime((void*)&local_data->rtc_time);
 
#ifdef __MMI_LCD_PARTIAL_ON__
#ifdef __MMI_SCREEN_SAVER__
    mmi_scr_saver_date_time_ind_hdlr();
#endif /* __MMI_SCREEN_SAVER__ */
#endif /* __MMI_LCD_PARTIAL_ON__ */ 

    /* Lisen0522 */
#if !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__)
    if (srv_backlight_is_lcd_sleep() == MMI_FALSE)
    {
        update_mainlcd_dt_display();
    }
#else /* !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__) */ 
    update_mainlcd_dt_display();
#endif /* !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__) */ 
    update_sublcd_dt_display();

#ifdef  __MMI_CALENDAR_ON_IDLE_SCREEN__        
    if (update_static_cal)
    {
        mmi_clndr_set_calendar_on_idle();
        wgui_calendar_system_date_change();
        wgui_calendar_idle_update();
    }
#endif /*__MMI_CALENDAR_ON_IDLE_SCREEN__*/

#ifdef __MMI_WORLD_CLOCK__
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_DTTM_TRACE_004, update_wc_flag);
    if (update_wc_flag)
    {
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_DTTM_TRACE_005);
        /* Update world clock date time */
        mmi_wc_update_datetime();
    }
#endif /* __MMI_WORLD_CLOCK__ */

#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */

#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    if (update_min)
    {
        mmi_dtv_player_date_time_update_hdlr();
    }
#endif /* __MMI_MOBILE_TV_CMMB_SUPPORT__ */

#if defined(__VENUS_UI_ENGINE__)
    if (update_min)
    {
        vdat_system_time_changed_handler();
    }
#endif /* __VENUS_UI_ENGINE__ */

    if (update_min)
    {
#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
        mmi_alm_update_hs32_sidebar_info();
        mmi_tdl_op11_hs32_update_sidebar_info();
        mmi_tdl_op11_hs32_update_today_shct_data();
        mmi_tdl_op11_hs32_update_thweek_shct_data();
#endif 
        #ifdef __MMI_WEARABLE_DEVICE__
        //change every minute
        mmi_idle_swatch_update_clock_by_minute();
        #endif  //__MMI_WEARABLE_DEVICE__
    }
#else /* __MTK_TARGET__ */ 
    DateTimerProc();
#endif /* __MTK_TARGET__ */ 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dt_check_rtc_time
 * DESCRIPTION
 * Check if rtc time is valid
 * PARAMETERS
 *  p       [?]     [?]
 *  t(?)        [IN]        Struct variable that stores date and time information from PS(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dt_check_rtc_time(void)
{
    if (gclockData.rtc_year > MMI_DT_YEAR_BOUNDARY)
    {
        gclockData.rtc_year = 0;    /* reset to 2000 */
        DTResetTime();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dt_conv_rtc_mytime
 * DESCRIPTION
 *  Handler of time change.
  * PARAMETERS
 *  out_time	:[IN]	old time
 *  in_time	:[IN]	new time
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dt_conv_rtc2_mytime(MYTIME *out_time,  const rtc_format_struct *in_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(out_time != NULL && in_time != NULL);
	
	out_time->DayIndex = in_time->rtc_wday;
	out_time->nYear = in_time->rtc_year + YEARFORMATE;
	out_time->nMonth = in_time->rtc_mon;
	out_time->nDay = in_time->rtc_day;
	out_time->nHour = in_time->rtc_hour;
	out_time->nMin = in_time->rtc_min;
	out_time->nSec = in_time->rtc_sec;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dt_conv_mytime2_rtc
 * DESCRIPTION
 *  Handler of time change.
  * PARAMETERS
 *  out_time	:[IN]	old time
 *  in_time	:[IN]	new time
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dt_conv_mytime2_rtc(rtc_format_struct *out_time, const MYTIME *in_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(out_time != NULL && in_time != NULL);
	
	out_time->rtc_wday = in_time->DayIndex;
	out_time->rtc_year = in_time->nYear - YEARFORMATE;
	out_time->rtc_mon = in_time->nMonth;
	out_time->rtc_day = in_time->nDay;
	out_time->rtc_hour = in_time->nHour;
	out_time->rtc_min = in_time->nMin;
	out_time->rtc_sec = in_time->nSec;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dt_change_notify
 * DESCRIPTION
 *  Handler of time change.
  * PARAMETERS
 *  old_time	:[IN]	old time
 *  new_time	:[IN]	new time
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dt_change_notify(const MYTIME *old_time, const MYTIME *new_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_datetimie_evt_struct dt_evt;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_FRM_INIT_EVENT(&dt_evt, EVT_ID_SRV_DATETIME_CHANGE);
	
	memcpy(&dt_evt.old_time, old_time, sizeof(MYTIME));
	memcpy(&dt_evt.new_time, new_time, sizeof(MYTIME));

	if (old_time->nMin != new_time->nMin)
	{
		dt_evt.change |= SRV_DATETIME_CHANGE_FLAG_MIN;
	}
	if (old_time->nHour != new_time->nHour)
	{
		dt_evt.change |= SRV_DATETIME_CHANGE_FLAG_HOUR;
	}
	if (old_time->nDay != new_time->nDay)
	{
		dt_evt.change |= SRV_DATETIME_CHANGE_FLAG_DAY;
	}
	
	if (old_time->nMonth != new_time->nMonth)
	{
		dt_evt.change |= SRV_DATETIME_CHANGE_FLAG_MONTH;
	}

	
	MMI_FRM_CB_EMIT_EVENT(&dt_evt);
}

#endif /* _MMI_DATETIME_C */ // #ifndef _MMI_DATETIME_C

