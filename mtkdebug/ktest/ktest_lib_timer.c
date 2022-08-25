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
 *   ktest_lib_timer.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  Write timer test case library here. The lib should de independent from RTOS
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* this file is valid only when __KTEST__ has been defined */
#ifdef __KTEST__
#include "ktest_lib_timer.h"
 
extern kal_uint32 sys_mem_ptr;
extern void* kal_sys_mem_alloc(kal_uint32 size);

void ktest_sys_mem_free(kal_uint32 size)
{
    sys_mem_ptr -= size;
}

void ktest_timer_cb_timeout_fail(void *cb_data)
{
        ktest_report(KTEST_FAIL, KTEST_TCID, NULL);
        ktest_reset_target();
}

/*This works as a counter*/
volatile kal_int32 ktest_timer_g_count;
cb_time_s   global_cb_array[KTEST_TIMER_NUM];

void ktest_init_timer_cb(cb_time_s *time, kal_uint32 delay)
{
    kal_get_time(&(time->save_time));
    time->delay_tick = delay;
    return;
}

/*specify the expected error*/
kal_uint32 compare_time_error(kal_uint32 a_int, kal_uint32 b_int, kal_uint32 error)
{
    kal_uint32 int_error = ((a_int > b_int) ? (a_int - b_int) : (b_int - a_int));

    if(int_error <= error)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

#if defined(KAL_ON_NUCLEUS)
kal_taskid ktest_create_task_timeslice(kal_char* task_name, kal_uint8 priority,
                           kal_uint32 stack_size, kal_task_func_ptr entry_func,
                           void *entry_param, kal_uint32 time_slice)

{
   kal_internal_taskid task_id_ptr = (kal_internal_taskid)KAL_NILTASK_ID;
   void *stack_addr;
   STATUS ret_status;

   stack_addr = kal_sys_mem_alloc(stack_size);

   if (stack_addr == NULL)
   {
      kal_fatal_error_handler (KAL_ERROR_TASKMNGT_CREATE_MEMFAILED, KAL_ERROR_KAL_SUB_ERROR_CODE1);
   }

   /* Allocate memory for task control block */
   task_id_ptr = (kal_internal_taskid) kal_sys_mem_alloc ( sizeof ( kal_task_type ) );

   if ( task_id_ptr == NULL )
   {
      kal_fatal_error_handler (KAL_ERROR_TASKMNGT_CREATE_MEMFAILED, KAL_ERROR_KAL_SUB_ERROR_CODE2);
   }

   kal_mem_set(task_id_ptr, 0, sizeof (kal_task_type));

   ret_status = NU_Create_Task ((NU_TASK*)task_id_ptr,
                                (kal_char *) task_name,
                                ( kal_nu_task_func_ptr )entry_func,
                                (UNSIGNED) entry_param,
                                NULL,
                                stack_addr,
                                stack_size,
                                (OPTION)priority,
                                time_slice, /* Zero time slice disables preemption
                                  between same priority tasks */
                                NU_PREEMPT, /* Allow preemption */
                                NU_START  /* Put the task in ready state*/);

   if ( NU_SUCCESS != ret_status ) {
      kal_fatal_error_handler (KAL_ERROR_TASKMNGT_CREATE_FAILED, (kal_int32)ret_status);
   }

#if defined(DEBUG_KAL)
   task_id_ptr->task_name = task_name;
#endif /* DEBUG_KAL */

   return(kal_taskid) task_id_ptr;
}
#endif /*(KAL_ON_NUCLEUS)*/

kal_timerid create_set_timer(kal_timer_func_ptr handler_func_ptr,
                   void *handler_param_ptr, kal_uint32 delay)
{
    kal_timerid tid;

    tid = kal_create_timer("test");
    kal_set_timer(tid, handler_func_ptr, handler_param_ptr, delay, 0);
    return tid;
}

/*XXX note currently this function depends on Nucleus.
 * To solve the problem cleanly, kal_set_aligned_timer
 * should accept kal_timerid
 * */

#if defined(KAL_ON_NUCLEUS)
kal_bool ktest_set_aligned_timer(kal_timerid timer, kal_uint8 max_delay)
{
    TM_TCB *tm_ptr;
    kal_internal_timerid kal_timer = (kal_internal_timerid)timer;
    tm_ptr = &(((TM_APP_TCB *)&(kal_timer->timer_id))->tm_actual_timer);

    return kal_set_aligned_timer(tm_ptr, max_delay);
}
#endif  /*(KAL_ON_NUCLEUS)*/

/*increase counter. Check timer accuracy, if fail report error and reset. if ok, keep silent*/
void event_cb4(void * cb_data)
{
    kal_uint32 elapse_time, now;
    ktest_timer_g_count++;

    if (cb_data != NULL)
    {
        cb_time_s *ptr = (cb_time_s *)cb_data;

        kal_get_time(&now);
        elapse_time = now - ptr->save_time;

        if (compare_time_error(elapse_time, ptr->delay_tick,
                    KAL_TIMER_ALLOWED_ERROR) == 0)
        {
            ktest_report(KTEST_FAIL, KTEST_TCID,
                        "elapse time is %d delay is %d",
                        elapse_time,
                        ptr->delay_tick);

            ktest_reset_target();
        }
    }

    return;
}

/*do nothing*/
void ktest_timer_event_cb7(void *data)
{
}

/*XXX: should remove reference to ktest_timer_event_cb5*/
void ktest_timer_event_cb5(void *data_db)
{
    ktest_timer_g_count++;
}

#endif  /* __KTEST__ */
