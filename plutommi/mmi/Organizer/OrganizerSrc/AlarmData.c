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
 * AlarmData.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Alarm data management.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/*****************************************************************************
* Header files
*****************************************************************************/
#include "AlarmDef.h"
#include "AlarmGProt.h"

/* add header file start */
    #include "MMIDataType.h"
    #include "DebugInitDef_Int.h"
    #include "custom_mmi_default_value.h"
    #include "nvram_common_defs.h"
    #include "mmi_frm_nvram_gprot.h"
    #include "MMI_common_app_trc.h"
    #include "kal_trace.h"
    #include "AlarmFrameworkProt.h"
    #include "DateTimeType.h"
    #include "app_datetime.h"
    #include "kal_public_api.h"
    #include "kal_general_types.h"
    #include "mmi_common_app_trc.h"
/* add header file end */

/*****************************************************************************
* Global Variables 
*****************************************************************************/


/*****************************************************************************
 * Define
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  AlmWriteToNvram
 * DESCRIPTION
 *  Write alarm data to nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmReadNvram(void *node, U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 sError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index < NUM_OF_ALM);
    MMI_ASSERT(node != NULL);

    ReadRecord(NVRAM_EF_ALM_ALARM_DATA_LID, 
               (U16)(index + 1), 
               node, 
               NVRAM_ALM_ALARM_DATA_SIZE, 
               &sError);

}


/*****************************************************************************
 * FUNCTION
 *  AlmWriteToNvram
 * DESCRIPTION
 *  Write alarm data to nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmWriteToNvram(U8 index, void *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 sError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index < NUM_OF_ALM);
    MMI_ASSERT(node != NULL);

    WriteRecord(NVRAM_EF_ALM_ALARM_DATA_LID, 
                (U16)(index + 1), 
                node, 
                NVRAM_ALM_ALARM_DATA_SIZE, 
                &sError);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_get_info
 * DESCRIPTION
 *  This function is used to get alarm data
 * PARAMETERS
 *  index   :[IN] Alarm index, start from 0, if index is error, it will assert.
 *  hour    :[OUT] alarm time hour field
 *  min     :[OUT] alarm time min field
 *  state   :[OUT] 1 -> turn on, 0 -> turn off
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_get_info(U8 index, U8 *hour, U8 *min, U8 *state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index < NUM_OF_ALM);

	*hour = g_alm_cntx.AlmList[index].Hour;
	*min = g_alm_cntx.AlmList[index].Min;
	*state = g_alm_cntx.AlmList[index].State;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_get_alm_time
 * DESCRIPTION
 *  This function is used to get the next alarm.
 * PARAMETERS
 *  time         :[out] next alarm time.
 *  soonze       :[IN] whether care about soonze alarm
 * RETURNS
 *  MMI_BOOL    MMI_FALSE means there is no next alarm
 *****************************************************************************/
MMI_BOOL mmi_alm_get_alm_time(MYTIME *ActualTime, U8 index, MMI_BOOL snooze)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp = 0;
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    RETURN_VAL_IF_FAIL((index < NUM_OF_ALM) && (ActualTime!= NULL), MMI_FALSE);

    /* Don't care snooze alarm. */
    if (!snooze && g_alm_cntx.AlmList[index].Snooze != 0)
    {
        return MMI_FALSE;
    }
    
    if (!snooze)
    {
        temp = g_alm_cntx.AlmList[index].Snooze;
        g_alm_cntx.AlmList[index].Snooze = 0;
    }

    /* Get real alarm time */
    *ActualTime = AlmGetAlarmTime((U8)(ALM_ALM_START + index));

    if (!snooze)
    {
        g_alm_cntx.AlmList[index].Snooze = temp;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_search_default_callback
 * DESCRIPTION
 *  This function is used to get the next alarm.
 * PARAMETERS
 *  time         :[out] next alarm time.
 *  soonze       :[IN] whether care about soonze alarm
 * RETURNS
 *  MMI_BOOL    MMI_FALSE means there is no next alarm
 *****************************************************************************/
static MMI_BOOL mmi_alm_search_default_callback(U8 index, MYTIME *searchTime, MMI_BOOL snooze)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME alarmTime;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_alm_get_alm_time(&alarmTime, index, snooze))
    {
        return MMI_FALSE;
    }
    
    ret = CompareTime(alarmTime, *searchTime, NULL);
    if (ret == DT_TIME_EQUAL || ret == DT_TIME_GREATER)
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
 *  mmi_alm_compare_default_callback
 * DESCRIPTION
 *  This function is used to get the next alarm.
 * PARAMETERS
 *  time         :[out] next alarm time.
 *  soonze       :[IN] whether care about soonze alarm
 * RETURNS
 *  MMI_BOOL    MMI_FALSE means there is no next alarm
 *****************************************************************************/
static MMI_BOOL mmi_alm_compare_default_callback(U8 index1, U8 index2, MMI_BOOL snooze)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME alarmTime1, alarmTime2;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_alm_get_alm_time(&alarmTime1, index1, snooze);
    mmi_alm_get_alm_time(&alarmTime2, index2, snooze);
    
    ret = CompareTime(alarmTime1, alarmTime2, NULL);
    if (ret == DT_TIME_EQUAL || ret == DT_TIME_GREATER)
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
 *  mmi_alm_sort
 * DESCRIPTION
 *  This function is used to get the next alarm.
 * PARAMETERS
 *  time         :[OUT] next alarm time.
 *  soonze       :[IN] whether care about soonze alarm
 * RETURNS
 *  MMI_BOOL    MMI_FALSE means there is no next alarm
 *****************************************************************************/
void mmi_alm_sort(U8 *list, U8 len, MMI_BOOL snooze, AlmCompareCallback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j, temp;
    AlmCompareCallback funcptr;
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(list != NULL);

    funcptr = callback ? callback : mmi_alm_compare_default_callback;
    for (i = 0; i < len; i++)
    {
        for (j = i + 1; j < len; j++)
        {
            if (funcptr(list[i], list[j], snooze))
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_search
 * DESCRIPTION
 *  This function is used to get the next alarm.
 * PARAMETERS
 *  time         :[out] next alarm time.
 *  soonze       :[IN] whether care about soonze alarm
 * RETURNS
 *  MMI_BOOL    MMI_FALSE means there is no next alarm
 *****************************************************************************/
void mmi_alm_search(U8 *list, 
                          U8 size,
                          U8 *count,
                          MMI_BOOL snooze, 
                          MYTIME *time, 
                          AlmSearchCallback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    AlmSearchCallback funcptr;
    U8 i, cnt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(list != NULL && count != NULL && time != NULL);

    cnt = 0;
    funcptr = callback ? callback : mmi_alm_search_default_callback;
    for (i = 0; i < NUM_OF_ALM; i++)
    {
       if (g_alm_cntx.AlmList[i].State == 0)
        {
            continue;
        }    
       
        if (funcptr(i, time, snooze))
        {
            list[cnt++] = i;
        }    
    }
    *count = cnt;

    MMI_ALM_TRACE2(MMI_ALM_SEARCH_RESULT, snooze, cnt);
    
}


