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
 *  App_time.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Get current time
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <time.h>
#include "kal_release.h"
#include "dcl.h"
#include "kal_general_types.h"

static DCL_HANDLE g_rtc_handler;
/*****************************************************************************
 * FUNCTION
 *  mmi_sample_code
 * DESCRIPTION
 * Returns the time since the Epoch (00:00:00 UTC, January 1, 1970),
 * measured in seconds.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint32	time
 *****************************************************************************/
kal_uint32 app_getcurrtime(void)
{
    kal_uint32 secs;

#ifdef __MTK_TARGET__
    RTC_CTRL_GET_TIME_T rtc;
    struct tm when;

    g_rtc_handler = DclRTC_Open(DCL_RTC, FLAGS_NONE);
    DclRTC_Control(g_rtc_handler, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T *)&rtc);
    //RTC_GetTime(&rtc);
    /* RTC_GetTime() returns the timestamp of current time.
     * the returned 'year' counts from 2000, i.e., for year 2004, year is 4 */
    when.tm_sec = rtc.u1Sec;
    when.tm_min = rtc.u1Min;
    when.tm_hour = rtc.u1Hour;
    when.tm_mday = rtc.u1Day;
    when.tm_mon = rtc.u1Mon - 1;
    /* mktime() expects the yeaer counting from 1900,
     * and returns total seconds elapsed since 1970.01.01 midnight */
    when.tm_year = rtc.u1Year + (2000-1900);
    when.tm_isdst = 0;
    secs = (kal_uint32)mktime(&when);

#else /* !__MTK_TARGET__ */ 
    //kal_uint32 ltime;
    secs = (kal_uint32)time(0);
#endif /* !__MTK_TARGET__ */ 

    return secs;
}


/*
 * Returns the time since the Epoch (00:00:00 UTC, January 1, 1970),
 * measured in seconds.
 * [in/out] kal_uint32 *t_loc  return value is also stored in *tloc, if t_loc is non-null
 */
kal_uint32 app_gettime(kal_uint32 *t_loc)
{    
    kal_uint32 secs;

    secs = app_getcurrtime();
    
    if (t_loc != NULL)
    {
        *t_loc = secs;      
    }
    return secs;
}
