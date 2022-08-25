/***********************************************************************
*   This software/firmware and related documentation ("MediaTek Software") 
*   are protected under relevant copyright laws. The information contained 
*   herein is confidential and proprietary to MediaTek Inc. and/or its licensors.
*
*   Without the prior written permission of MediaTek Inc. and/or its licensors, 
*   any reproduction, modification, use or disclosure of MediaTek Software, and 
*   information contained herein, in whole or in part, shall be strictly prohibited.
*
*   MediaTek Inc. (C) [2007]. All rights reserved.
*
*************************************************************************/ 
/*******************************************************************************
 * Filename:
 * ---------
 *  gps_main.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  gps_time_sync.c
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "gps_uart_hdlr.h"
#include "gps_main.h"
#include "gps_time_sync.h"
#include "app_datetime.h"
#include "stack_msgs.h"
#include "ps_public_struct.h"
#include "gps_struct.h"

#define GPS_TIME_SYNC_INVALID_TIME_DURATION (12*3600)
#define TIME_STATUS_FILE_NAME L"Z:\\gps_time_sync.inc"
typedef enum
{
	TIME_UPDATE_STATE_NONE,
	TIME_UPDATE_STATE_NTP,
	TIME_UPDATE_STATE_NITZ,
	TIME_UPDATE_STATE_GPS,
} time_update_state;

typedef struct
{
    LOCAL_PARA_HDR
	kal_uint32 curr_sec;
	time_update_state state;
} gps_time_update_struct;

struct
{
	kal_uint32 curr_sec;
	time_update_state update_state;
	kal_uint32 account_id;
	kal_int8 is_init;
} gps_time_sync_cntx;


extern gps_uart_context_struct g_gps_cntx;

void gps_time_sync_update_ext(kal_uint32 curr_sec, time_update_state state);
void gps_time_sync_restart_timer();
void gps_time_sync_init(kal_uint32 account_id);
void gps_time_sync_deinit();
void gps_time_sync_update_handle(void* param);


void ntp_time_sync_callback(kal_int32 result, kal_int64 offset, void *usr_data)
{
	kal_uint32 seconds;
	kal_int32 offset_seconds;
	applib_time_struct tm;
	
	kal_prompt_trace(MOD_GPS, "[TIMESYNC]ntp_time_sync_callback, result:%d, offset:%d", result, (kal_int32)(offset/1000));
    if (result == 0)
	{
		offset_seconds = (kal_int32) (offset/1000);
		applib_dt_get_rtc_time(&tm);
		
		kal_prompt_trace(MOD_GPS, "[TIMESYNC]date_time:%d-%d-%d %d:%d:%d", tm.nYear, tm.nMonth, tm.nDay, tm.nHour, tm.nMin, tm.nSec);
		seconds = applib_dt_mytime_2_utc_sec(&tm, KAL_FALSE);
		seconds += offset_seconds;
		gps_time_sync_update_ext(seconds, TIME_UPDATE_STATE_NTP);
	}
	ntpd_sync_time_close();
	
}

void gps_time_sync_trigger_ntp(void* param)
{
	kal_prompt_trace(MOD_GPS, "[TIMESYNC]gps_time_sync_trigger_ntp");
	ntpd_sync_time_ext(ntp_time_sync_callback, gps_time_sync_cntx.account_id, NULL);
	gps_time_sync_restart_timer();
}

void gps_time_sync_load_time()
{
	kal_int32 fHandle, ret, write_len;
	// save time to nvram and rtc
	kal_prompt_trace(MOD_GPS, "[TIMESYNC]gps_time_sync_load_time");
	fHandle = FS_Open(TIME_STATUS_FILE_NAME, FS_READ_ONLY);
	if (fHandle >= 0)
	{
		ret = FS_Read(fHandle, &gps_time_sync_cntx, sizeof(gps_time_sync_cntx), &write_len);
		FS_Close(fHandle);
	}
	else
	{
		kal_prompt_trace(MOD_GPS, "[TIMESYNC]gps_time_sync_load_time error:%d", fHandle);
	}
}

void gps_time_sync_save_time()
{
	kal_int32 fHandle, ret, write_len;
	// save time to nvram and rtc
	kal_prompt_trace(MOD_GPS, "[TIMESYNC]gps_time_sync_save_time");
	fHandle = FS_Open(TIME_STATUS_FILE_NAME, FS_CREATE_ALWAYS);
	if (fHandle >= 0)
	{
		ret = FS_Write(fHandle, &gps_time_sync_cntx, sizeof(gps_time_sync_cntx), &write_len);
		FS_Close(fHandle);
	}
	else
	{
		kal_prompt_trace(MOD_GPS, "[TIMESYNC]gps_time_sync_save_time error:%d", fHandle);
		//
	}
}
void gps_time_sync_restart_timer()
{
	kal_prompt_trace(MOD_GPS, "[TIMESYNC]gps_time_sync_restart_timer");
	gps_stop_timer(GPS_TIME_SYNC_TIMER);
	gps_start_timer(GPS_TIME_SYNC_TIMER, GPS_TIME_SYNC_INVALID_TIME_DURATION*1000, gps_time_sync_trigger_ntp, NULL);
}

kal_bool gps_time_sync_is_system_time_valid()
{
	kal_uint32 t_loc;
	applib_time_struct t_time;
	kal_prompt_trace(MOD_GPS, "[TIMESYNC]gps_time_sync_is_system_time_valid, state:%d", gps_time_sync_cntx.update_state);
	if (gps_time_sync_cntx.update_state == TIME_UPDATE_STATE_NONE)
	{
		return KAL_FALSE;
	}
	applib_dt_get_rtc_time(&t_time);
	kal_prompt_trace(MOD_GPS, "[TIMESYNC]date_time:%d-%d-%d %d:%d:%d", t_time.nYear, t_time.nMonth, t_time.nDay, t_time.nHour, t_time.nMin, t_time.nSec);
	t_loc = applib_dt_mytime_2_utc_sec(&t_time, KAL_FALSE);
	kal_prompt_trace(MOD_GPS, "[TIMESYNC]curr_sec:%d, last_sync_sec:%d", t_loc, gps_time_sync_cntx.curr_sec);

	if (t_loc < gps_time_sync_cntx.curr_sec || t_loc - gps_time_sync_cntx.curr_sec >= GPS_TIME_SYNC_INVALID_TIME_DURATION)
	{
		return KAL_FALSE;
	}
	return KAL_TRUE;
}

kal_bool gps_time_sync_is_system_time_valid_ext()
{
	kal_uint32 t_loc;
	applib_time_struct t_time;
	kal_prompt_trace(MOD_GPS, "[TIMESYNC]gps_time_sync_is_system_time_valid, state:%d", gps_time_sync_cntx.update_state);
	if (gps_time_sync_cntx.update_state == TIME_UPDATE_STATE_NONE)
	{
		return KAL_FALSE;
	}
	applib_dt_get_rtc_time(&t_time);
	kal_prompt_trace(MOD_GPS, "[TIMESYNC]date_time:%d-%d-%d %d:%d:%d", t_time.nYear, t_time.nMonth, t_time.nDay, t_time.nHour, t_time.nMin, t_time.nSec);
	t_loc = applib_dt_mytime_2_utc_sec(&t_time, KAL_FALSE);
	kal_prompt_trace(MOD_GPS, "[TIMESYNC]curr_sec:%d, last_sync_sec:%d", t_loc, gps_time_sync_cntx.curr_sec);

	if (t_loc < gps_time_sync_cntx.curr_sec)
	{
		return KAL_FALSE;
	}
	return KAL_TRUE;
}

void gps_time_sync_nitz_sync(kal_uint32 curr_sec)
{
	kal_prompt_trace(MOD_GPS, "[TIMESYNC]gps_time_sync_nitz_sync");
	gps_time_sync_update_ext(curr_sec, TIME_UPDATE_STATE_NITZ);
}

void gps_time_sync_gps_sync()
{
    applib_time_struct updateTime;
	kal_uint32 t_sec;

	kal_prompt_trace(MOD_GPS, "[TIMESYNC]gps_time_sync_gps_sync");
	updateTime.nYear = g_gps_cntx.parser.nmea.rmc.utc_date.year + YEARFORMATE;
	updateTime.nMonth = g_gps_cntx.parser.nmea.rmc.utc_date.month;
	updateTime.nDay = g_gps_cntx.parser.nmea.rmc.utc_date.day;
	updateTime.nHour = g_gps_cntx.parser.nmea.rmc.utc_time.hour;
	updateTime.nMin = g_gps_cntx.parser.nmea.rmc.utc_time.minute;
	updateTime.nSec = g_gps_cntx.parser.nmea.rmc.utc_time.second;
	t_sec = applib_dt_mytime_2_utc_sec(&updateTime, KAL_FALSE);	
	kal_prompt_trace(MOD_GPS, "[TIMESYNC]date_time:%d-%d-%d %d:%d:%d", updateTime.nYear, updateTime.nMonth, updateTime.nDay, updateTime.nHour, updateTime.nMin, updateTime.nSec);
	gps_time_sync_update_ext(t_sec, TIME_UPDATE_STATE_GPS);
}

void gps_time_sync_update_ext(kal_uint32 curr_sec, time_update_state state)
{
	
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	ilm_struct *ilm_ptr = NULL;
	gps_time_update_struct * ind_p;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if (!gps_time_sync_cntx.is_init)
	{
		return;
	}
	kal_prompt_trace(MOD_GPS, "[TIMESYNC]gps_time_sync_update_ext, sec:%d, state:%d", curr_sec, state);
	ind_p = (gps_time_update_struct*) construct_local_para( sizeof(gps_time_update_struct), TD_CTRL);

	ind_p->curr_sec = curr_sec;
	ind_p->state = state;
	
	ilm_ptr = allocate_ilm(stack_get_active_module_id());
	ilm_ptr->src_mod_id = stack_get_active_module_id();
	ilm_ptr->dest_mod_id = MOD_GPS;
	ilm_ptr->sap_id = 0;

	ilm_ptr->msg_id = (msg_type) MSG_ID_GPS_SYNC_TIME;
	ilm_ptr->local_para_ptr = (local_para_struct*)ind_p;
	ilm_ptr->peer_buff_ptr = NULL;
	
	msg_send_ext_queue(ilm_ptr);
}

void gps_time_sync_set_rtc(applib_time_struct *t)
{

	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	rtc_alarm_info_struct set_time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	kal_prompt_trace(MOD_GPS, "[TIMESYNC]gps_time_sync_set_rtc");
	kal_prompt_trace(MOD_GPS, "[TIMESYNC]date_time:%d-%d-%d %d:%d:%d", t->nYear, t->nMonth, t->nDay, t->nHour, t->nMin, t->nSec);

    set_time.alarm_format = 0;
    set_time.alarm_index = 0;
    set_time.type = 0;
    set_time.text[0] = '\0';
    set_time.recurr = 0;
    set_time.data_time.rtc_sec = t->nSec;
    set_time.data_time.rtc_min = t->nMin;
    set_time.data_time.rtc_hour = t->nHour;

    set_time.data_time.rtc_day = t->nDay;
    set_time.data_time.rtc_mon = t->nMonth;
    set_time.data_time.rtc_year = t->nYear - YEARFORMATE;
    set_time.data_time.rtc_wday = applib_dt_dow(t->nYear, t->nMonth, t->nDay);
	l4cuem_rtc_set_time_req(RTC_TIME_CLOCK_IND, set_time, RTC_SETTING_TYPE_DATETIME);
}

void gps_time_sync_update(kal_uint32 curr_sec, time_update_state state)
{
	applib_time_struct t_time;
	kal_prompt_trace(MOD_GPS, "[TIMESYNC]gps_time_sync_update, sec:%d, state:%d", curr_sec, state);
	if (!gps_time_sync_is_system_time_valid() || state >= gps_time_sync_cntx.update_state)
	{
		gps_time_sync_cntx.curr_sec = curr_sec;
		gps_time_sync_cntx.update_state = state;
		applib_dt_utc_sec_2_mytime(curr_sec, &t_time, KAL_FALSE);
		gps_time_sync_set_rtc(&t_time);
		gps_time_sync_save_time();
		gps_time_sync_restart_timer();
	}
}

void gps_time_sync_message_handle(ilm_struct *ilm_ptr)
{
    kal_uint16 msg_id = ilm_ptr->msg_id;
	gps_assist_ind_struct * assist_struct_p;
	kal_prompt_trace(MOD_GPS, "[TIMESYNC]gps_time_sync_message_handle msg_id:%d", msg_id);
    switch(msg_id)
	{
		case MSG_ID_ENABLE_TIME_SYNC:
			{
				assist_struct_p = (gps_assist_ind_struct * ) ilm_ptr->local_para_ptr;
				gps_time_sync_init(assist_struct_p->account_id);
			}
			break;
		case MSG_ID_DISABLE_TIME_SYNC:
			gps_time_sync_deinit();
			break;
		case MSG_ID_GPS_SYNC_TIME:
			gps_time_sync_update_handle(ilm_ptr->local_para_ptr);
			break;
	}
}

void gps_time_sync_update_handle(void* param)
{
	gps_time_update_struct* update_time = (gps_time_update_struct*) param;
	kal_prompt_trace(MOD_GPS, "[TIMESYNC]gps_time_sync_update_handle");

	gps_time_sync_update(update_time->curr_sec, update_time->state);
}
void gps_time_sync_deinit()
{
	kal_prompt_trace(MOD_GPS, "[TIMESYNC]gps_time_sync_deinit, is_init:%d", gps_time_sync_cntx.is_init);
	if (!gps_time_sync_cntx.is_init)
	{
		return;
	}
	gps_time_sync_cntx.is_init = 0;
	gps_stop_timer(GPS_TIME_SYNC_TIMER);
}

void gps_time_sync_init(kal_uint32 account_id)
{
	kal_uint32 t_loc;
	applib_time_struct t_time;
	kal_prompt_trace(MOD_GPS, "[TIMESYNC]gps_time_sync_init is_init:%d", gps_time_sync_cntx.is_init);
    if (stack_query_boot_mode() == FACTORY_BOOT)
    {
		kal_prompt_trace(MOD_GPS, "[TIMESYNC]on factory mode");
        return;
    }
	if (gps_time_sync_cntx.is_init)
	{
		return;
	}
	gps_time_sync_cntx.curr_sec = 0;
	gps_time_sync_cntx.update_state = TIME_UPDATE_STATE_NONE;
	gps_time_sync_load_time();
	gps_time_sync_cntx.account_id = account_id;
	gps_time_sync_cntx.is_init = 1;
	if (gps_time_sync_is_system_time_valid())
	{
        applib_dt_get_rtc_time(&t_time);
        t_loc = applib_dt_mytime_2_utc_sec(&t_time, KAL_FALSE);
		gps_stop_timer(GPS_TIME_SYNC_TIMER);
		gps_start_timer(GPS_TIME_SYNC_TIMER, GPS_TIME_SYNC_INVALID_TIME_DURATION + gps_time_sync_cntx.curr_sec - t_loc, gps_time_sync_trigger_ntp, NULL);
	}
	else
	{
		// trigger ntp
		//ntpd_sync_time_ext(ntp_time_sync_callback, NULL);
		gps_stop_timer(GPS_TIME_SYNC_TIMER);
		gps_start_timer(GPS_TIME_SYNC_TIMER, 20000, gps_time_sync_trigger_ntp, NULL);
	}
}

