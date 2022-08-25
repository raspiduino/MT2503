/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * drm_consume.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for DRM service, wrapper layer.
 *
 * Author:
 * -------
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifdef __DRM_SUPPORT__

#include "drm_trace.h"
#include "drm_gprot.h"
#include "drm_main.h"
#include "drm_prot.h"
#include "drm_memory.h"

#include "kal_general_types.h"
#include "fs_type.h"
#include "drm_def.h"
#include "stack_config.h"
#include "kal_internal_api.h"
#include "fs_errcode.h"
#include "kal_trace.h"
#include "drm_errcode.h"

#define DRM_CONSUME_DEBUG_ON

#ifdef DRM_CONSUME_DEBUG_ON
#define DRM_CONSUME_DEBUG(x,y)   kal_trace y
#define DRM_CONSUME_DEBUGP(x)   drm_trace x
#else /* DRM_CONSUME_DEBUG_ON */ 
#define DRM_CONSUME_DEBUG(x,y)
#define DRM_CONSUME_DEBUGP(x)
#endif /* DRM_CONSUME_DEBUG_ON */ 

#define DRM_CHECK_RIGHT_ISSUER_IN_MOVABLE

#define DRM_UNUSED_PARAMETER(a) while((&a)==NULL);

#ifdef DRM_CHECK_TIME_PERIODICALLY
kal_mutexid g_drm_consumer_mutex = NULL;
static drm_consumer_struct g_drm_consumer_tbl[DRM_MAX_FILE_HANDLE];
#endif /* DRM_CHECK_TIME_PERIODICALLY */ 

#ifdef DRM_CHECK_TIME_PERIODICALLY


/*****************************************************************************
 * FUNCTION
 *  drmt_create_consumer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drmt_create_consumer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(g_drm_consumer_mutex);

    for (i = 0; i < DRM_MAX_FILE_HANDLE; i++)
    {
        /* if (g_drm_consumer_tbl[i].evid == NULL && g_drm_consumer_tbl[i].callback == NULL) */
        if (g_drm_consumer_tbl[i].handle == 0
    #ifdef DRM_CHECK_TIME_PERIODICALLY
            && g_drm_consumer_tbl[i].callback == NULL
    #endif 
            )
        {
            break;
        }
    }
    kal_give_mutex(g_drm_consumer_mutex);

    if (i == DRM_MAX_FILE_HANDLE)
    {
        kal_bool EXEED_MAX_FILE_HANDLE = KAL_FALSE;

        ASSERT(EXEED_MAX_FILE_HANDLE);
        return -1;
    }
    return i;

}


/*****************************************************************************
 * FUNCTION
 *  drmt_clean_consume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id              [IN]        
 *  consumer(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void drmt_clean_consume(kal_int32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 consumer = id - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == 0)
        return;

    if (consumer >= 0 && consumer < DRM_MAX_FILE_HANDLE)
    {
        kal_take_mutex(g_drm_consumer_mutex);
        if (g_drm_consumer_tbl[consumer].cid)
        {
            drmt_mem_free(g_drm_consumer_tbl[consumer].cid);
        }
        memset(&g_drm_consumer_tbl[consumer], 0, sizeof(drm_consumer_struct));
        kal_give_mutex(g_drm_consumer_mutex);
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  drmt_get_consumer_by_ref
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drmt_get_consumer_by_ref(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < DRM_MAX_FILE_HANDLE; i++)
    {
        if (&g_drm_consumer_tbl[i] == (drm_consumer_struct*) arg)
        {
            break;
        }

    }
    if (i == DRM_MAX_FILE_HANDLE)
    {
        kal_bool EXEED_MAX_FILE_HANDLE = KAL_FALSE;

        ASSERT(EXEED_MAX_FILE_HANDLE);
        return -1;
    }

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_consume_set_cb_executed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id              [IN]        
 *  consumer(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void drmt_consume_set_cb_executed(kal_int32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 consumer = id - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == 0)
        return;

    if (consumer >= 0 && consumer < DRM_MAX_FILE_HANDLE)
    {
        kal_take_mutex(g_drm_consumer_mutex);
        g_drm_consumer_tbl[consumer].cb_executed = KAL_TRUE;
        kal_give_mutex(g_drm_consumer_mutex);
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  drmt_consume_is_cb_executed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id              [IN]        
 *  consumer(?)     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool drmt_consume_is_cb_executed(kal_int32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 consumer = id - 1;
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == 0)
    {
        return KAL_TRUE;
    }

    if (consumer >= 0 && consumer < DRM_MAX_FILE_HANDLE)
    {
        kal_take_mutex(g_drm_consumer_mutex);
        result = g_drm_consumer_tbl[consumer].cb_executed;
        kal_give_mutex(g_drm_consumer_mutex);
    }
    else
    {
        ASSERT(0);
    }

    return result;

}


/*****************************************************************************
 * FUNCTION
 *  drmt_update_consumer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  consumer        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool drmt_update_consumer(kal_int32 consumer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drm_constraint_struct *cons;
    applib_time_struct time;
    kal_uint32 ltime, previous_time;
    kal_bool update = KAL_FALSE;
    drm_rights_status_enum status = DRM_STATUS_RIGHTS_PRESENT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_dt_get_rtc_time(&time);

    ltime = applib_dt_mytime_2_utc_sec(&time, KAL_FALSE);

    if (g_drm_consumer_tbl[consumer].is_paused)
    {
        g_drm_consumer_tbl[consumer].chkpoint = ltime;
    }
    else
    {
        previous_time = g_drm_consumer_tbl[consumer].chkpoint;
        g_drm_consumer_tbl[consumer].chkpoint = ltime;
        g_drm_consumer_tbl[consumer].time_passed += ltime - previous_time;

        cons = &g_drm_consumer_tbl[consumer].cons;

        /* date-time or Interval */
        if (cons->end_time != 0 && ltime > cons->end_time)
        {
            update = KAL_TRUE;
        }
    #ifdef __DRM_V02__
        /* accumulated */
        if (cons->accum_dur != 0)
        {
            if (cons->accum_dur < g_drm_consumer_tbl[consumer].time_passed)
            {
                update = KAL_TRUE;
            }
        }

        if (g_drm_consumer_tbl[consumer].time_passed >= 5)
        {
            if (!g_drm_consumer_tbl[consumer].cid)
            {
                drm_core_update_consumer(
                    g_drm_consumer_tbl[consumer].handle,
                    g_drm_consumer_tbl[consumer].time_passed,
                    g_drm_consumer_tbl[consumer].count_minus,
                    &status);
            }
            else
            {
                drm_core_update_consumer_by_cid(
                    g_drm_consumer_tbl[consumer].handle,
                    g_drm_consumer_tbl[consumer].time_passed,
                    g_drm_consumer_tbl[consumer].count_minus,
                    &status);
            }

            if (status != DRM_STATUS_RIGHTS_PRESENT && status != DRM_STATUS_NOT_PROTECTED)
            {
                update = KAL_TRUE;
            }
            else
            {
                if (cons->accum_dur != 0)
                {
                    cons->accum_dur -= g_drm_consumer_tbl[consumer].time_passed;
                }
            }

            g_drm_consumer_tbl[consumer].time_passed = 0;

        }
    #endif /* __DRM_V02__ */ 
        return update;
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_consume_timeout_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void drmt_consume_timeout_hdlr(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 consumer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(g_drm_consumer_mutex);

    consumer = drmt_get_consumer_by_ref(arg);

    if (consumer >= 0 && consumer < DRM_MAX_FILE_HANDLE)
    {

        if (g_drm_consumer_tbl[consumer].is_waiting_clean)
        {
            DRM_CONSUME_DEBUG(
                "[DRM] consume clean consumer = %d",
                (TRACE_GROUP_GENERAL, DRM_PROC_132CC2BAAE8D05B9A454355DF953BB0F, consumer));
            if (g_drm_consumer_tbl[consumer].cid)
            {
                drmt_mem_free(g_drm_consumer_tbl[consumer].cid);
            }
            memset(&g_drm_consumer_tbl[consumer], 0, sizeof(drm_consumer_struct));
        }
        else if (g_drm_consumer_tbl[consumer].callback)
        {
            if (drmt_update_consumer(consumer))
            {
                drmt_ro_expiry_ind_struct *ind =
                    (drmt_ro_expiry_ind_struct*) construct_local_para(sizeof(drmt_ro_expiry_ind_struct), TD_RESET);
                ind->callback = g_drm_consumer_tbl[consumer].callback;
                ind->result = -1;
                ind->id = consumer + 1;

                DRM_CONSUME_DEBUG(
                    "[DRM] consume update consumer = %d",
                    (TRACE_GROUP_GENERAL, DRM_PROC_B79E602BD77807A86E9E844657E9AE93, consumer));

                g_drm_consumer_tbl[consumer].is_waiting_clean = KAL_TRUE;

                drm_send_msg(
                    MOD_DRMT,
                    g_drm_consumer_tbl[consumer].source,
                    MSG_ID_DRMT_RO_EXPIRY_IND,
                    (void*)ind,
                    NULL);
            }
            else
            {
                g_drm_consumer_tbl[consumer].evid = drmt_start_timer(
                                                        DRM_REGULAR_CHECK_PERIOD,
                                                        (void*)&g_drm_consumer_tbl[consumer],
                                                        drmt_consume_timeout_hdlr);
            }
        }
        else
        {
            kal_bool METERUSAGE_CALLBACK_DISAPPEAR = KAL_FALSE;

            ASSERT(METERUSAGE_CALLBACK_DISAPPEAR);
        }
    }
    kal_give_mutex(g_drm_consumer_mutex);

}

#endif /* DRM_CHECK_TIME_PERIODICALLY */ 

#define DRM_INTERFACE_CONSUME_CONTROL_HANDLE


/*****************************************************************************
 * FUNCTION
 *  DRM_consume_rights_aux
 * DESCRIPTION
 *  consume DRM rights
 * PARAMETERS
 *  source          [IN]        
 *  cid             [?]         
 *  permission      [IN]        
 *  callback        [IN]        
 *  count_minus     [IN]        
 *  module          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 DRM_consume_rights_aux(
            FS_HANDLE source,
            drm_cid_struct *cid,
            kal_uint8 permission,
            void (*callback) (kal_int32 result, kal_int32 id),
            kal_bool count_minus,
            module_type module)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 error;

#ifdef DRM_CHECK_TIME_PERIODICALLY
    kal_int32 consumer = 0;
    applib_time_struct time;
    drm_constraint_struct *cons;
#endif /* DRM_CHECK_TIME_PERIODICALLY */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef DRM_CHECK_TIME_PERIODICALLY
    DRM_UNUSED_PARAMETER(count_minus);
    DRM_UNUSED_PARAMETER(module);
    DRM_UNUSED_PARAMETER(callback);
#endif /* DRM_CHECK_TIME_PERIODICALLY */ 

#ifdef DRM_CHECK_TIME_PERIODICALLY
    if (!callback)
    {
        ASSERT(0);
        DRM_CONSUME_DEBUG(
            "[DRM] Consume Right invalid para",
            (TRACE_GROUP_ERROR, DRM_PROC_34495C3950743E51DD5068E7B3296AE8));
        return DRM_RESULT_INVALID_PARA;
    }
#endif /* DRM_CHECK_TIME_PERIODICALLY */ 

    if (cid || DRM_get_object_method(source, NULL) != DRM_METHOD_NONE)
    {
    #ifdef DRM_CHECK_TIME_PERIODICALLY
        /* get consumer id */
        consumer = drmt_create_consumer();

        cons = &(g_drm_consumer_tbl[consumer].cons);

        DRM_CONSUME_DEBUG(
            "[DRM] Consume Right consumer = %d, fp = %d, perm = %d, only time = %d",
            (TRACE_GROUP_GENERAL, DRM_PROC_28B4BC2786DD5B1AC43F8EDB5FBA4FDB, consumer, source, permission, count_minus));

        if (consumer < 0)
        {
            ASSERT(0);
            DRM_CONSUME_DEBUG(
                "[DRM] Consume Right no valid consumer",
                (TRACE_GROUP_ERROR, DRM_PROC_070085A43ABBEB409261C509F2B93A8E));
            return DRM_RESULT_INVALID_PARA;
        }

        kal_take_mutex(g_drm_consumer_mutex);

        if (!cid)
        {
            error = drm_core_consume_rights(source, permission, count_minus, cons);
        }
        else
        {
            error = drm_core_consume_rights_by_cid(cid, permission, count_minus, cons);
        }

        if (error >= 0)
        {
            g_drm_consumer_tbl[consumer].handle = error;
            /* Initial consumer */
            applib_dt_get_rtc_time(&time);
            if (!cid)
            {
                g_drm_consumer_tbl[consumer].cid = NULL;
            }
            else
            {
                g_drm_consumer_tbl[consumer].cid = (drm_cid_struct*) drmt_mem_alloc(sizeof(drm_cid_struct));
                memcpy(g_drm_consumer_tbl[consumer].cid, cid, sizeof(drm_cid_struct));
            }
            g_drm_consumer_tbl[consumer].chkpoint = applib_dt_mytime_2_utc_sec(&time, KAL_FALSE);
            g_drm_consumer_tbl[consumer].time_passed = 0;
            g_drm_consumer_tbl[consumer].evid = NULL;
            g_drm_consumer_tbl[consumer].source = module;
            g_drm_consumer_tbl[consumer].callback = callback;
            g_drm_consumer_tbl[consumer].is_paused = KAL_FALSE;
            g_drm_consumer_tbl[consumer].is_waiting_clean = KAL_FALSE;
            g_drm_consumer_tbl[consumer].count_minus = count_minus;

            /* Time based constraint, we update the constraint time by time */
            if ((cons->type & DRM_CONSTRAINT_DATETIME) ||
                (cons->type & DRM_CONSTRAINT_INTERVAL) || (cons->type & DRM_CONSTRAINT_ACCUMULATED))
            {
                /* transfer interval to datetime */
                if (cons->type & DRM_CONSTRAINT_INTERVAL)
                {
                    kal_int32 tmp_end_time;
                    kal_uint32 chkpoint;

                    applib_dt_get_rtc_time(&time);
                    chkpoint = applib_dt_mytime_2_utc_sec(&time, KAL_FALSE);

                    /* setup the start time and end time */
                    cons->start_time = chkpoint;

                    /* multiple constraints */
                    tmp_end_time = chkpoint + cons->interval;

                    if (cons->end_time == 0 || cons->end_time > tmp_end_time)
                    {
                        cons->end_time = tmp_end_time;
                    }
                }

                if ((cons->type & DRM_CONSTRAINT_INTERVAL) && count_minus == KAL_TRUE)
                {
                    /*
                     * It should be the first time to invoke consume right.
                     * (do not transfer interval to datetime)
                     * 
                     * There is a special case in our system.
                     * If count_minus == 1, that means application try to resume consume
                     * but the constraint is changed! we should not use the newer RO here.
                     * Therefore, we skip the consume mechanism, always return true.
                     * 
                     * count + datetime (OK)
                     * count + interval (OK)
                     * datetime + interval (should stop but continue, known issue)
                     * datetime + datetime (should stop but continue, known issue)
                     * datetime + count, (should stop but continue, known issue)
                     */
                    g_drm_consumer_tbl[consumer].evid = NULL;
                }
                else
                {
                    g_drm_consumer_tbl[consumer].evid = drmt_start_timer(
                                                            DRM_REGULAR_CHECK_PERIOD,
                                                            (void*)&g_drm_consumer_tbl[consumer],
                                                            drmt_consume_timeout_hdlr);
                }

                DRM_CONSUME_DEBUG(
                    "[DRM] consume start_timer endtime = %d, accum = %d",
                    (TRACE_GROUP_GENERAL, DRM_PROC_7295D728DEFFB0C6A9ADE22A45DAB91C, g_drm_consumer_tbl[consumer].cons.end_time, g_drm_consumer_tbl[consumer].cons.accum_dur));
            }
            else
            {
                g_drm_consumer_tbl[consumer].evid = NULL;

                DRM_CONSUME_DEBUG(
                    "[DRM] consume count used = %d, total = %d, only_time = %d",
                    (TRACE_GROUP_GENERAL, DRM_PROC_EEFAB64483F997CC4B15885841726012, cons->used_count, cons->total_count, count_minus));
                DRM_CONSUME_DEBUG(
                    "[DRM] consume count time_count = %d, total = %d, only_time = %d",
                    (TRACE_GROUP_GENERAL, DRM_PROC_8F0C5DFFA9C73F5FF4CBBA31E5D72EBC, cons->timed_count, cons->total_timed_count, count_minus));

            }
        }
        else
        {
            DRM_CONSUME_DEBUG(
                "[DRM] consume right error %d",
                (TRACE_GROUP_ERROR, DRM_PROC_2B57B9E430EB9601A7772704DFB9B167, error));
        }

        kal_give_mutex(g_drm_consumer_mutex);

        if (error < 0)
        {
            drmt_clean_consume(consumer + 1);
            return error;
        }
        else
        {
            return consumer + 1;
        }
    #else /* DRM_CHECK_TIME_PERIODICALLY */ 
        if (!cid)
        {
            error = drm_core_consume_rights(source, permission, count_minus, NULL);
        }
        else
        {
            error = drm_core_consume_rights_by_cid(cid, permission, count_minus, NULL);
        }
        return error;
    #endif /* DRM_CHECK_TIME_PERIODICALLY */ 
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  DRM_consume_rights
 * DESCRIPTION
 *  consume DRM rights
 * PARAMETERS
 *  source          [IN]        
 *  permission      [IN]        
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 DRM_consume_rights(FS_HANDLE source, kal_uint8 permission, void (*callback) (kal_int32 result, kal_int32 id))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DRM_consume_rights_aux(source, NULL, permission, callback, KAL_FALSE, stack_get_active_module_id());
}


/*****************************************************************************
 * FUNCTION
 *  DRM_consume_timed_rights
 * DESCRIPTION
 * PARAMETERS
 *  source          [IN]        
 *  permission      [IN]        
 *  callback        [IN]        
 * RETURNS
 *****************************************************************************/
kal_int32 DRM_consume_timed_rights(
            FS_HANDLE source,
            kal_uint8 permission,
            void (*callback) (kal_int32 result, kal_int32 id))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DRM_consume_rights_aux(source, NULL, permission, callback, KAL_TRUE, stack_get_active_module_id());
}


/*****************************************************************************
 * FUNCTION
 *  DRM_consume_rights_with_module
 * DESCRIPTION
 *  consume DRM rights
 * PARAMETERS
 *  source          [IN]        
 *  permission      [IN]        
 *  callback        [IN]        
 *  module          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 DRM_consume_rights_with_module(
            FS_HANDLE source,
            kal_uint8 permission,
            void (*callback) (kal_int32 result, kal_int32 id),
            module_type module)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DRM_consume_rights_aux(source, NULL, permission, callback, KAL_FALSE, module);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_consume_timed_rights_with_module
 * DESCRIPTION
 * PARAMETERS
 *  source          [IN]        
 *  permission      [IN]        
 *  callback        [IN]        
 *  module          [IN]        
 * RETURNS
 *****************************************************************************/
kal_int32 DRM_consume_timed_rights_with_module(
            FS_HANDLE source,
            kal_uint8 permission,
            void (*callback) (kal_int32 result, kal_int32 id),
            module_type module)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DRM_consume_rights_aux(source, NULL, permission, callback, KAL_TRUE, module);
}

#define DRM_INTERFACE_CONSUME_CONTROL_CID


/*****************************************************************************
 * FUNCTION
 *  DRM_consume_rights_by_cid
 * DESCRIPTION
 *  consume DRM rights
 * PARAMETERS
 *  cid                 [IN]        Content id of the content
 *  permission          [IN]        Permission to consume
 *  callback            [IN]        Callback for rights expired
 *  is_drm_msg(?)       [IN]        Applications have to tell DRM agent the content is drm message or not.
 * RETURNS
 *  DRM error code
 *****************************************************************************/
kal_int32 DRM_consume_rights_by_cid(
            drm_cid_struct *cid,
            kal_uint8 permission,
            void (*callback) (kal_int32 result, kal_int32 id))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DRM_consume_rights_aux(0, cid, permission, callback, KAL_FALSE, stack_get_active_module_id());
}


/*****************************************************************************
 * FUNCTION
 *  DRM_consume_timed_rights_by_cid
 * DESCRIPTION
 * PARAMETERS
 *  cid                 [IN]        Content id of the content
 *  permission          [IN]        Permission to consume
 *  callback            [IN]        Callback for rights expired
 *  is_drm_msg(?)       [IN]        Applications have to tell DRM agent the content is drm message or not.
 * RETURNS
 *  DRM error code
 *****************************************************************************/
kal_int32 DRM_consume_timed_rights_by_cid(
            drm_cid_struct *cid,
            kal_uint8 permission,
            void (*callback) (kal_int32 result, kal_int32 id))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DRM_consume_rights_aux(0, cid, permission, callback, KAL_TRUE, stack_get_active_module_id());
}

#define DRM_INTERFACE_CONSUME_CONTROL_COMMON


/*****************************************************************************
 * FUNCTION
 *  DRM_pause_consume
 * DESCRIPTION
 *  To pause rights consuming
 * PARAMETERS
 *  id      [IN]        
 *  input(?)        [IN]        File handle(?)
 *  sec_pass(?)     [IN]        How many seconds passed(?)
 * RETURNS
 *  void
 *****************************************************************************/
void DRM_pause_consume(kal_int32 id)
{
#ifdef DRM_CHECK_TIME_PERIODICALLY
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 consumer = id - 1;
    applib_time_struct time;
    kal_uint32 ltime, previous_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_CONSUME_DEBUG(
        "[DRM] pause_consume, consumer = %d",
        (TRACE_GROUP_GENERAL, DRM_PROC_51A09153F42584592CEA9342F28FB2C3, consumer));

    if (id == 0)
        return;

    if (consumer >= 0 && consumer < DRM_MAX_FILE_HANDLE && g_drm_consumer_tbl[consumer].source != MOD_NIL)
    {
        if (g_drm_consumer_tbl[consumer].is_paused == KAL_FALSE)
        {
            kal_take_mutex(g_drm_consumer_mutex);

            g_drm_consumer_tbl[consumer].is_paused = KAL_TRUE;
            applib_dt_get_rtc_time(&time);
            ltime = applib_dt_mytime_2_utc_sec(&time, KAL_FALSE);
            previous_time = g_drm_consumer_tbl[consumer].chkpoint;
            g_drm_consumer_tbl[consumer].chkpoint = ltime;
            g_drm_consumer_tbl[consumer].time_passed += ltime - previous_time;

            kal_give_mutex(g_drm_consumer_mutex);

            DRM_CONSUME_DEBUG(
                "[DRM] pause_consume, chktime = %d, time_passed = %d ",
                (TRACE_GROUP_GENERAL, DRM_PROC_51A09153F42584592CEA9342F28FB2C4, g_drm_consumer_tbl[consumer].chkpoint, g_drm_consumer_tbl[consumer].time_passed));
        }
        else
        {
            ASSERT(0);
        }
    }
    else
    {
        /* sometimes AP get error when consume right */
        /* ASSERT(0); */
    }
#endif /* DRM_CHECK_TIME_PERIODICALLY */ 
}


/*****************************************************************************
 * FUNCTION
 *  DRM_stop_consume
 * DESCRIPTION
 *  To stop rights consuming
 * PARAMETERS
 *  id      [IN]        
 *  input(?)        [IN]        File handle(?)(?)
 *  sec_pass(?)     [IN]        How many seconds passed(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void DRM_stop_consume(kal_int32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef DRM_CHECK_TIME_PERIODICALLY
    kal_uint32 ltime;
    applib_time_struct time;
    drm_rights_status_enum status;
    kal_int32 consumer = id - 1;
#endif /* DRM_CHECK_TIME_PERIODICALLY */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef DRM_CHECK_TIME_PERIODICALLY

    drm_core_stop_consume(id);

#else /* DRM_CHECK_TIME_PERIODICALLY */ 
    if (id == 0)
        return;

    if (consumer >= 0 && consumer < DRM_MAX_FILE_HANDLE && g_drm_consumer_tbl[consumer].source != MOD_NIL)
    {
        kal_take_mutex(g_drm_consumer_mutex);

        /* prevent AP call stop_consume after pause_consume */
        if (!g_drm_consumer_tbl[consumer].is_paused)
        {
            applib_dt_get_rtc_time(&time);
            ltime = applib_dt_mytime_2_utc_sec(&time, KAL_FALSE);
            g_drm_consumer_tbl[consumer].time_passed += ltime - g_drm_consumer_tbl[consumer].chkpoint;
        }

        DRM_CONSUME_DEBUG(
            "[DRM] stop consume, consumer = %d, time_passed = %d",
            (TRACE_GROUP_GENERAL, DRM_PROC_2B57B9E430EB9601A7772704DFB9B166, consumer, g_drm_consumer_tbl[consumer].time_passed));

        if (!g_drm_consumer_tbl[consumer].cid)
        {
            drm_core_update_consumer(
                g_drm_consumer_tbl[consumer].handle,
                g_drm_consumer_tbl[consumer].time_passed,
                g_drm_consumer_tbl[consumer].count_minus,
                &status);
        }
        else
        {
            drm_core_update_consumer_by_cid(
                g_drm_consumer_tbl[consumer].handle,
                g_drm_consumer_tbl[consumer].time_passed,
                g_drm_consumer_tbl[consumer].count_minus,
                &status);
        }

        g_drm_consumer_tbl[consumer].time_passed = 0;

        if (!g_drm_consumer_tbl[consumer].cid)
        {
            drm_core_stop_consume(g_drm_consumer_tbl[consumer].handle);
        }
        else
        {
            drm_core_stop_consume_by_cid(g_drm_consumer_tbl[consumer].handle);
        }

        if (g_drm_consumer_tbl[consumer].evid == 0)
        {
            DRM_CONSUME_DEBUG(
                "[DRM] stop consume count, only_time = %d",
                (TRACE_GROUP_GENERAL, DRM_PROC_0C4F5AF5E0BD87FA2D1E3C344CEB99FD, g_drm_consumer_tbl[consumer].count_minus));

            /* count-based rights, free the table entry immediately */
            if (g_drm_consumer_tbl[consumer].cid)
            {
                drmt_mem_free(g_drm_consumer_tbl[consumer].cid);
            }
            memset(&g_drm_consumer_tbl[consumer], 0, sizeof(drm_consumer_struct));
        }
        else
        {
            DRM_CONSUME_DEBUG(
                "[DRM] stop consume time, waiting_clean = %d, is_paused = %d, cb_executed = %d",
                (TRACE_GROUP_GENERAL, DRM_PROC_F707DD1FEADCC76230032CAE9794C202, g_drm_consumer_tbl[consumer].is_waiting_clean, g_drm_consumer_tbl[consumer].is_paused, g_drm_consumer_tbl[consumer].cb_executed));

            if (g_drm_consumer_tbl[consumer].is_waiting_clean)
            {
                if (g_drm_consumer_tbl[consumer].cb_executed)
                {
                    if (g_drm_consumer_tbl[consumer].cid)
                    {
                        drmt_mem_free(g_drm_consumer_tbl[consumer].cid);
                    }
                    memset(&g_drm_consumer_tbl[consumer], 0, sizeof(drm_consumer_struct));
                }
                else
                {
                    g_drm_consumer_tbl[consumer].cb_executed = KAL_TRUE;
                }
            }
            else
            {
                /* time-based rights, free the memory when final timer out */
                g_drm_consumer_tbl[consumer].is_waiting_clean = KAL_TRUE;
            }
        }

        kal_give_mutex(g_drm_consumer_mutex);
    }
    else
    {
        DRM_CONSUME_DEBUG(
            "[DRM] stop consume, invalid id = %d",
            (TRACE_GROUP_ERROR, DRM_PROC_0D4CA3F9EDF90B7288E7132D63ACEFC4, id));
        /* sometimes AP get error when consume right */
        /* ASSERT(0); */
    }
#endif /* DRM_CHECK_TIME_PERIODICALLY */ 

}


/*****************************************************************************
 * FUNCTION
 *  DRM_resume_consume
 * DESCRIPTION
 *  To resume rights consuming
 * PARAMETERS
 *  id      [IN]        
 *  input(?)        [IN]        File handle(?)
 *  sec_pass(?)     [IN]        How many seconds passed(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool DRM_resume_consume(kal_int32 id)
{
#ifdef DRM_CHECK_TIME_PERIODICALLY
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 consumer = id - 1;
    applib_time_struct time;
    kal_uint32 ltime;
    drm_rights_status_enum status = DRM_STATUS_NO_RIGHTS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_CONSUME_DEBUG(
        "[DRM] resume_consume, consumer = %d",
        (TRACE_GROUP_GENERAL, DRM_PROC_268522A5D590F8D82DAE04973321BA39, consumer));

    if (id == 0)
        return KAL_TRUE;

    if (consumer >= 0 && consumer < DRM_MAX_FILE_HANDLE && g_drm_consumer_tbl[consumer].source != MOD_NIL)
    {
        if (g_drm_consumer_tbl[consumer].is_paused != KAL_TRUE)
        {
            return KAL_TRUE;
        }
        kal_take_mutex(g_drm_consumer_mutex);
        g_drm_consumer_tbl[consumer].is_paused = KAL_FALSE;
        applib_dt_get_rtc_time(&time);
        ltime = applib_dt_mytime_2_utc_sec(&time, KAL_FALSE);
        g_drm_consumer_tbl[consumer].chkpoint = ltime;
        kal_give_mutex(g_drm_consumer_mutex);

        DRM_CONSUME_DEBUG(
            "[DRM] resume_consume, chktime = %d, time_passed = %d ",
            (TRACE_GROUP_9, DRM_PROC_268522A5D590F8D82DAE04973321BA40, g_drm_consumer_tbl[consumer].chkpoint, g_drm_consumer_tbl[consumer].time_passed));

        if (!g_drm_consumer_tbl[consumer].cid)
        {
            drm_core_update_consumer(
                g_drm_consumer_tbl[consumer].handle,
                0,
                g_drm_consumer_tbl[consumer].count_minus,
                &status);
        }
        else
        {
            drm_core_update_consumer_by_cid(
                g_drm_consumer_tbl[consumer].handle,
                0,
                g_drm_consumer_tbl[consumer].count_minus,
                &status);
        }

        if (status == DRM_STATUS_RIGHTS_PRESENT)
        {
            return KAL_TRUE;
        }
        else
        {
            return KAL_FALSE;
        }
    }
    else
    {
        /* sometimes AP get error when consume right */
        /* ASSERT(0); */
        return KAL_FALSE;
    }
#endif /* DRM_CHECK_TIME_PERIODICALLY */ 
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  DRM_consume_table_is_in_use
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *****************************************************************************/
kal_bool DRM_consume_table_is_in_use(void)
{
#ifdef DRM_CHECK_TIME_PERIODICALLY
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(g_drm_consumer_mutex);
    for (i = 0; i < DRM_MAX_FILE_HANDLE; i++)
    {
        if (g_drm_consumer_tbl[i].handle != 0)
        {
            break;
        }
    }
    kal_give_mutex(g_drm_consumer_mutex);

    if (i != DRM_MAX_FILE_HANDLE)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
#else /* DRM_CHECK_TIME_PERIODICALLY */ 
    return KAL_FALSE;
#endif /* DRM_CHECK_TIME_PERIODICALLY */ 
}

#define DRM_INTERFACE_VALIDATE_HANDLE


/*****************************************************************************
 * FUNCTION
 *  DRM_validate_permission
 * DESCRIPTION
 *  check DRM rights with specific permission
 * PARAMETERS
 *  handle          [IN]        Is already opened, it will also carry the error code of FS_Open.
 *  path            [?]         [?]         [?]
 *  permission      [IN]        If permission == DRM_PERMISSION_PLAY, this function will check the permission by current mime_type
 *  file_path(?)        [IN]            If file_path != NULL, means we should open the file here.(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool DRM_validate_permission(FS_HANDLE handle, kal_wchar *path, kal_uint8 permission)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_MEM_START_EVAL
    if (path)
    {
        handle = drm_core_open_file(path, FS_READ_ONLY | FS_OPEN_SHARED, permission);
        if (handle < FS_NO_ERROR)
        {
            return KAL_FALSE;
        }
    }

    /* cannot use drm right object during database backup or sweep */
    if (drmt_engine_is_process_database() && DRM_is_drm_file(handle, NULL))
    {
        DRM_CONSUME_DEBUG(
            "[DRM] validate fail by g_drm_is_process_database",
            (TRACE_GROUP_ERROR, DRM_PROC_F1271A584DB6AA8B8674A41EA5EC63FF));
    #ifdef __DRM_MTK__
        if ( DRM_get_object_method(handle, NULL) == DRM_METHOD_FORWARD_LOCK )

        {
            result = KAL_TRUE;
        }
        else
    #endif 
        {
            result = KAL_FALSE;
        }
    }
    else
    {
        result = drm_core_validate_permission(handle, permission);
    }

    if (path)
    {
        drm_core_close_file(handle);
    }
    DRM_MEM_END_EVAL

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  DRM_validate_timed_permission
 * DESCRIPTION
 *  check DRM rights with specific permission
 * PARAMETERS
 *  handle          [IN]        Is already opened, it will also carry the error code of FS_Open.
 *  permission      [IN]        If permission == DRM_PERMISSION_PLAY, this function will check the permission by current mime_type
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool DRM_validate_timed_permission(FS_HANDLE handle, kal_uint8 permission)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_MEM_START_EVAL

    /* cannot use drm right object during database backup or sweep */
    if (drmt_engine_is_process_database() && DRM_is_drm_file(handle, NULL))
    {
        DRM_CONSUME_DEBUG(
            "[DRM] validate fail by g_drm_is_process_database",
            (TRACE_GROUP_ERROR, DRM_PROC_F1271A584DB6AA8B8674A41EA5EC63FF));
    #ifdef __DRM_MTK__
        if ( DRM_get_object_method(handle, NULL) == DRM_METHOD_FORWARD_LOCK )
        {
            return KAL_TRUE;
        }
    #endif 
        {
            return KAL_FALSE;
        }
    }

    result = drm_core_validate_timed_permission(handle, permission);
    DRM_MEM_END_EVAL
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  DRM_validate_future_permission
 * DESCRIPTION
 *  check DRM rights with specific permission
 * PARAMETERS
 *  handle          [IN]        file handle of valided file
 *  permission      [IN]        permission to validate
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool DRM_validate_future_permission(FS_HANDLE handle, kal_uint8 permission)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_MEM_START_EVAL

    /* cannot use drm right object during database backup or sweep */
    if (drmt_engine_is_process_database() && DRM_is_drm_file(handle, NULL))
    {
        DRM_CONSUME_DEBUG(
            "[DRM] validate fail by g_drm_is_process_database",
            (TRACE_GROUP_ERROR, DRM_PROC_F1271A584DB6AA8B8674A41EA5EC63FF));
    #ifdef __DRM_MTK__
        if ( DRM_get_object_method(handle, NULL) == DRM_METHOD_FORWARD_LOCK )
        {
            return KAL_TRUE;
        }
    #endif
        {
            return KAL_FALSE;
        }
    }

    result = drm_core_validate_future_permission(handle, permission);
    DRM_MEM_END_EVAL
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  DRM_interdev_movable
 * DESCRIPTION
 * PARAMETERS
 *  handle      [IN]        
 *  path        [?]         [?]         [?]
 * RETURNS
 *****************************************************************************/
kal_bool DRM_interdev_movable(FS_HANDLE handle, kal_wchar *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_MEM_START_EVAL
    if (path)
    {
        handle = drm_core_open_file(path, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_NONE);
        if (handle < DRM_RESULT_OK)
        {
            return KAL_FALSE;
        }
    }

    result = drm_core_interdev_movable(handle);

#ifdef DRM_CHECK_RIGHT_ISSUER_IN_MOVABLE
    if (result == KAL_TRUE && drm_core_get_object_method(handle) != DRM_METHOD_NONE)
    {
        kal_uint32 size = 0;

        if (drm_core_get_rights_issuer(handle, NULL, &size) >= DRM_RESULT_OK && size != 0)
        {
            result = KAL_TRUE;
        }
        else
        {
            result = KAL_FALSE;
        }
    }
#endif /* DRM_CHECK_RIGHT_ISSUER_IN_MOVABLE */ 

    if (path)
    {
        drm_core_close_file(handle);
    }

    DRM_MEM_END_EVAL
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  DRM_rights_extendable
 * DESCRIPTION
 *  only for filemanager to check if the rights is extendable
 * PARAMETERS
 *  handle      [IN]        file handle
 *  path        [IN]        path
 * RETURNS
 *  a boolean value
 *****************************************************************************/
kal_bool DRM_rights_extendable(kal_wchar *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_TRUE;
    kal_uint8 method;
    FS_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = drm_core_open_file(path, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_NONE);
    if (handle < DRM_RESULT_OK)
    {
        return KAL_FALSE;
    }

    method = drm_core_get_object_method(handle);

    if (method == DRM_METHOD_FORWARD_LOCK
        || method == DRM_METHOD_COMBINED_DELIVERY
        || method == DRM_METHOD_NONE)
    {
        result = KAL_FALSE;
    }
    else
    {
    #ifdef __DRM_V02__
        kal_wchar *sepa = kal_wstrrchr(path, (kal_int32) '\\');

        /* multipart archive  */
        if (DRM_is_archive(handle, NULL) && sepa && app_ucs2_strnicmp((kal_int8*)(sepa - 4), (kal_int8*)L".odf\\", 5) != 0)
        {
            result = KAL_FALSE;
        }
        else
    #endif
        {

        #ifdef DRM_CHECK_RIGHT_ISSUER_IN_MOVABLE
            kal_uint32 size = 0;
            if (drm_core_get_rights_issuer(handle, NULL, &size)>= DRM_RESULT_OK && size != 0)
            {
                result = KAL_TRUE;
            }
            else
            {
                result = KAL_FALSE;
            }
        #else
            result = KAL_TRUE;
        #endif
        }
    }

    drm_core_close_file(handle);

    return result;
}


#define DRM_INTERFACE_VALIDATE_CID


/*****************************************************************************
 * FUNCTION
 *  DRM_validate_permission_by_cid
 * DESCRIPTION
 *  check DRM rights with specific permission
 * PARAMETERS
 *  cid                 [IN]        Content id of the content
 *  permission          [IN]        Permission to consume
 *  is_drm_msg(?)       [IN]        Applications have to tell DRM agent the content is drm message or not.
 * RETURNS
 *  Success/Fail = KAL_TRUE/KAL_FALSE
 *****************************************************************************/
kal_bool DRM_validate_permission_by_cid(drm_cid_struct *cid, kal_uint8 permission)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* cannot use drm right object during database backup or sweep */
    if (drmt_engine_is_process_database())
    {
        DRM_CONSUME_DEBUG(
            "[DRM] validate fail by g_drm_is_process_database",
            (TRACE_GROUP_ERROR, DRM_PROC_F1271A584DB6AA8B8674A41EA5EC63FF));
        return KAL_FALSE;
    }

    DRM_MEM_START_EVAL
    result = drm_core_validate_permission_by_cid(cid, permission, KAL_FALSE);
    DRM_MEM_END_EVAL

    DRM_CONSUME_DEBUG("DRM_validate_permission_by_cid result = %d",
            (TRACE_GROUP_9, DRM_ITF_9FF0DD4F811194AD49B061928BE0E765, result));

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  DRM_validate_timed_permission_by_cid
 * DESCRIPTION
 *  check DRM rights with specific permission
 * PARAMETERS
 *  cid                 [IN]        Content id of the content
 *  permission          [IN]        Permission to consume
 *  is_drm_msg(?)       [IN]        Applications have to tell DRM agent the content is drm message or not.
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool DRM_validate_timed_permission_by_cid(drm_cid_struct *cid, kal_uint8 permission)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* cannot use drm right object during database backup or sweep */
    if (drmt_engine_is_process_database())
    {
        DRM_CONSUME_DEBUG(
            "[DRM] validate fail by g_drm_is_process_database",
            (TRACE_GROUP_ERROR, DRM_PROC_F1271A584DB6AA8B8674A41EA5EC63FF));
        return KAL_FALSE;
    }

    DRM_MEM_START_EVAL
    result = drm_core_validate_permission_by_cid(cid, permission, KAL_TRUE);
    DRM_MEM_END_EVAL

    DRM_CONSUME_DEBUG("DRM_validate_timed_permission_by_cid, result = %d",
            (TRACE_GROUP_9, DRM_ITF_9FF0DD4F811194AD49B061928BE0E766, result));

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  DRM_validate_forward_rule
 * DESCRIPTION
 *  check DRM rights with specific permission
 * PARAMETERS
 *  handle          [IN]        Is already opened, it will also carry the error code of FS_Open.
 *  permission      [IN]        If permission == DRM_PERMISSION_PLAY, this function will check the permission by current mime_type
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool DRM_validate_forward_rule(FS_HANDLE handle, kal_uint8 permission)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drm_constraint_struct cons;
    kal_int32 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (DRM_is_drm_file(handle, NULL) == KAL_TRUE)
    {
        error = drm_core_get_constraint(handle, permission, &cons);

        if (DRM_RESULT_OK <= error &&
            DRM_STATUS_RIGHTS_PRESENT == cons.status &&
            ((DRM_CONSTRAINT_NONE == cons.type) ||
             (!(DRM_CONSTRAINT_COUNT & cons.type) && !(DRM_CONSTRAINT_TIMEDCOUNT & cons.type))))
        {
            return KAL_TRUE;
        }
        return KAL_FALSE;
    }

    return KAL_TRUE;
}

#endif /* __DRM_SUPPORT__ */ 

