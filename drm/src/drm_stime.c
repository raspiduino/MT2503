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
 * drm_stime.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for DRM secure time implementation
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifdef __DRM_SUPPORT__

#ifdef __DRM_SEC_CLK_NITZ__

#include "app_datetime.h"
//#include "datetimegprot.h"
#include "MMIDataType.h"
#include "Drm_prot.h"
#include "App_datetime.h"
#define DRM_SECS_IN_15_MIN 15*60

typedef struct _drm_secure_time_cntx
{
    kal_bool status;
	kal_int32* timer_id;
/*May be new design*/	
	kal_uint32 time_sec;
	kal_uint32 ticks;
}drm_stime_cntx_struct;

drm_stime_cntx_struct g_drm_stime;


/*****************************************************************************
 * FUNCTION
 *  drm_stime_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void drm_stime_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_drm_stime.status = KAL_FALSE;
	g_drm_stime.time_sec = 0;
	g_drm_stime.ticks = 0;
	g_drm_stime.timer_id = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  drm_stime_get_secure_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  stime       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool drm_stime_get_secure_time(applib_time_struct *stime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
kal_uint32 ticks_now, ticks_diff, offset;
applib_time_struct time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
if(g_drm_stime.status)
    {
		kal_get_time(&ticks_now);
		ticks_diff = ticks_now - g_drm_stime.ticks;
		offset = kal_ticks_to_secs(ticks_diff);
		applib_dt_utc_sec_2_mytime(offset + g_drm_stime.time_sec, stime, KAL_FALSE);
		return KAL_TRUE;
	}
	else
	{
    	 memset(stime,0,sizeof(applib_time_struct));
    	 stime->nYear = DT_MIN_YEAR;
		 stime->nMonth = 1;
		 stime->nDay = 1;
		 return KAL_FALSE;
	}
}


/*****************************************************************************
 * FUNCTION
 *  drmt_stime_timeout_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void drmt_stime_timeout_hdlr(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     drm_stime_init();
	 drm_send_msg(stack_get_active_module_id(), MOD_MMI, MSG_ID_DRMT_NOTIFY_STIME_EXP_IND, NULL, NULL);
}



drm_stime_copy_mytime(applib_time_struct *out_time, applib_time_struct *in_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    out_time->DayIndex = in_time->DayIndex;
	out_time->nDay= in_time->nDay;
	out_time->nHour= in_time->nHour;
	out_time->nMin= in_time->nMin;
	out_time->nMonth= in_time->nMonth;
	out_time->nSec= in_time->nSec;
	out_time->nYear= in_time->nYear;
}

/*called at every NITZ indication*/


/*****************************************************************************
 * FUNCTION
 *  drm_stime_nitz_update_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nitz_time       [?]         
 *  sim_id          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool drm_stime_nitz_update_cb(applib_time_struct *nitz_time, mmi_sim_enum sim_id, U8 time_zone_p, FLOAT* time_zone, U8 light_saving_present)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_int32 nitz_time_sec, time_diff;
    applib_time_struct nitz_time_utc;
    float time_zone_temp = (float)*time_zone;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //drm_stime_copy_mytime(&nitz_time_utc, nitz_time);
    if(time_zone_p)
    {
        //applib_dt_utc_to_rtc_with_default_tz(nitz_time, &nitz_time_utc);
        applib_dt_utc_to_rtc(time_zone_temp, nitz_time, &nitz_time_utc);
    }
    else
    {
        applib_dt_utc_to_rtc((U8)0, nitz_time, &nitz_time_utc);
    }
    if (applib_dt_is_valid(&nitz_time_utc))
    {
        nitz_time_sec = applib_dt_mytime_2_utc_sec(&nitz_time_utc, light_saving_present);
        if(nitz_time_sec < g_drm_stime.time_sec)
        {
            time_diff = g_drm_stime.time_sec - nitz_time_sec;
        }
        else
        {
            time_diff = nitz_time_sec - g_drm_stime.time_sec;
        }

        if(time_diff > DRM_SECS_IN_15_MIN)
        {
            kal_get_time(&g_drm_stime.ticks);
            g_drm_stime.time_sec = nitz_time_sec;
            g_drm_stime.status = KAL_TRUE;
            if(g_drm_stime.timer_id)
            drmt_stop_timer(g_drm_stime.timer_id);
            g_drm_stime.timer_id = drmt_start_timer(DRM_STIME_EXPIRE_PERIOD, NULL, drmt_stime_timeout_hdlr);
            return KAL_TRUE;
        }
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  drm_stime_rtc_update_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void drm_stime_rtc_update_cb(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#endif /*__DRM_SEC_CLK_NITZ__*/
#endif /* __DRM_SUPPORT__ */ 

