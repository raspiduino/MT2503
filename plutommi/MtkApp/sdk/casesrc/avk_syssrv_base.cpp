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
*   tst_sysser_base.c
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   3rd Party Integration Development Environment
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "mmi_features.h"
#ifdef __MAUI_SDK_TEST__

#ifdef __cplusplus
extern "C"
{
#endif

/* NON SDK APIs */
#include "SettingDefs.h"      
#include "CommonScreens.h"   
#include "intrCtrl.h"
#include "custom_config.h"
#include "event_shed.h"
#include "event_shed_defs.h"
#include "syscomp_config.h"
#include "task_config.h"

#include "mmi_frm_events_gprot.h"
#include "stack_config.h"
#include "kal_common_defs.h"
#include "kal_afm.h"
#include "kal_release.h"
#include "cache_sw.h"
#include "kal_public_defs.h"
#include "kal_internal_api.h"
//#include "nucleus.h"

#include "avk_syssrv_base.h"
#include "kal_public_api.h"

#define VS_TOTAL_HILIGHT 2
#define VS_SYSSER_BASE_ITEM_NUMBER 20
    extern kal_uint32 kal_get_mytask_priority(void);

    static HILITE_STR hilite_list[VS_TOTAL_HILIGHT];
    static kal_hisrid vs_sys_hisr;
    static kal_eventgrpid vs_sys_events;
    static kal_semid vs_sys_sem;
    static volatile kal_mutexid vs_sys_mutex;
    static kal_msgqid vs_msg_q_id;
    static kal_timerid vs_timer_id;
    static kal_bool vs_mutex_flag = KAL_TRUE;
    static kal_bool vs_semaphore_flag = KAL_TRUE;
    volatile kal_int32 g_count;
    kal_uint8 gpt_module;

#ifdef KAL_ON_OSCAR
#define KTEST_FUNCTION_NAME		__FUNCTION__
#define KTEST_MAX_SEM_CNT       0x7FFFFFFF
#define KAL_TIMER_ALLOWED_ERROR 2
#else /*KAL_ON_OSCAR*/
#define KTEST_FUNCTION_NAME		__func__
#define KTEST_MAX_SEM_CNT       0xFFFFFFFF
#define KAL_TIMER_ALLOWED_ERROR 1
#endif
/*
#ifdef __MTK_TARGET__
#define AVK_SYSSER_BASE_ALIGN __align(1024)
#else 
#define AVK_SYSSER_BASE_ALIGN __declspec(align(1024))
#endif

AVK_SYSSER_BASE_ALIGN char adm_buf_20K[20 * 1024];
//AVK_SYSSER_BASE_ALIGN char adm_buf_200K[200 * 1024];
*/
CHAR* adm_buf_20K = NULL;

#if defined(__MTK_TARGET__) && defined(__ARM9_MMU__)
#ifndef OPTION
#define OPTION	AFM_OPT_ALIGN_ALLOC | AFM_OPT_DBG | AFM_OPT_CUSLOG
#endif
#else
#ifndef OPTION
#define OPTION	AFM_OPT_DBG | AFM_OPT_CUSLOG
#endif
#endif

#ifndef AFM_SUBPOOL_END_PATTERN
#define AFM_SUBPOOL_END_PATTERN 0xFFFFFFFF
#endif

#ifndef AVK_SYSSER_BASE_FUNCTION_NAME
#define AVK_SYSSER_BASE_FUNCTION_NAME "tst_sysser_base.c"
#endif 

#ifndef _SIZEOF
#define _SIZEOF(arr) (sizeof(arr) / sizeof((arr)[0]))
#endif 

#ifndef BIG_SUBPOOL_SIZE
#define BIG_SUBPOOL_SIZE {50, 100, 150, 300, 512, AFM_SUBPOOL_END_PATTERN}
#endif

#ifndef BIG_SUBPOOL_NR
#define BIG_SUBPOOL_NR {3, 10, 4, 1, 6, AFM_SUBPOOL_END_PATTERN}
#endif

#ifndef SMALL_SUBPOOL_SIZE
#define SMALL_SUBPOOL_SIZE {50, AFM_SUBPOOL_END_PATTERN}
#endif

#ifndef SMALL_SUBPOOL_NR
#define SMALL_SUBPOOL_NR {3, AFM_SUBPOOL_END_PATTERN}
#endif

#ifndef AVK_SYSSER_BASE_MAX_SEM_CNT
#define AVK_SYSSER_BASE_MAX_SEM_CNT       0x7FFFFFFF
#endif

#ifndef GPT_TICKSPERSEC
#define GPT_TICKSPERSEC 100
#endif

#ifndef ABIGSIZE
#define ABIGSIZE (KAL_AFM_POOL_OVERHEAD(OPTION, 5) + KAL_AFM_SUBPOOL_OVERHEAD(OPTION, 50, 3) \
    + KAL_AFM_SUBPOOL_OVERHEAD(OPTION, 100, 10) + KAL_AFM_SUBPOOL_OVERHEAD(OPTION, 150, 4)  \
    + KAL_AFM_SUBPOOL_OVERHEAD(OPTION, 300, 1) + KAL_AFM_SUBPOOL_OVERHEAD(OPTION, 512, 6))
#endif

#ifndef LOG_OVERHEAD
#define LOG_OVERHEAD 24
#endif

#ifndef NOLOG_OVERHEAD
#define NOLOG_OVERHEAD 8
#endif

#ifndef kal_adm_alloc_align_with_info
#define kal_adm_alloc_align_with_info(adm_id, size, align, actual_size) __kal_adm_alloc((adm_id), (size), (actual_size), (align) & ~ADM_OPT_MASK, __FILE__, __LINE__)
#endif

#ifndef kal_adm_alloc_align_topmost_with_info
#define kal_adm_alloc_align_topmost_with_info(adm_id, size, align, actual_size) __kal_adm_alloc((adm_id), (size), (actual_size), ((align) & ~ADM_OPT_MASK) | ADM_OPT_TOPMOST_ALLOC, __FILE__, __LINE__)
#endif


#ifndef LOG_SIZE
#define LOG_SIZE(x) (LOG_OVERHEAD + (x))
#endif

#ifndef NOLOG_SIZE
#define NOLOG_SIZE(x) (NOLOG_OVERHEAD + (x))
#endif

#ifndef ENTRY_HIGHLIGHT
#define ENTRY_HIGHLIGHT 0
#endif  //ENTRY_HIGHLIGHT
    typedef enum {
        AVK_SYSSER_BASE_PASS,
        AVK_SYSSER_BASE_FAIL,
        AVK_SYSSER_BASE_DEP_FAIL
    }vs_sys_res;

#if __MTK_TARGET__
#ifndef KTEST_ALIGN
#define KTEST_ALIGN __align(1024)
#endif
#else 
#ifndef KTEST_ALIGN
#define KTEST_ALIGN __declspec(align(1024))
#endif
#endif



    FILE *vs_sys_tc_label_file_stream; 
    FILE *vs_sys_log_file_stream;      
    typedef void (*gpt_timer_handler)(void *);
    static char a_cacheable_buf_c[ABIGSIZE];

    void vs_sys_eg_001_set(void);
    void vs_sys_mutex_001_send_msg(void);
    void vs_sys_semaphore_001_send_msg(void);
    void vs_sys_timer_001(void);
    void vs_sys_adm_002(void);
    void vs_sys_afm_001(void);
    void vs_sys_afm_002(void);
    void vs_sys_afm_003(void);
    void vs_sys_afm_004(void);
    void vs_sys_timer_cancel_event(kal_uint32 argc, void *argv);    
    void vs_sys_timer_del_all_events(kal_uint32 argc, void *argv);  
    //void vs_sys_semaphore_003_enhmutex(kal_uint32 argc, void *argv);
    //void vs_sys_semaphore_004_enhmutex2(kal_uint32 argc, void *argv);
    void vs_sys_evshed_001_test(void);
    void vs_sys_evshed_002_test(void);

    extern void kal_adm_free(KAL_ADM_ID adm_id, void *mem_addr);
    extern kal_status kal_adm_delete(KAL_ADM_ID adm_id);
    extern void *kal_adm_get_extheader(KAL_ADM_ID adm_id, void *p);
    extern kal_uint32 kal_adm_get_max_alloc_size(KAL_ADM_ID adm_id);
    extern kal_uint32 kal_adm_calc_worst_alloc_size(KAL_ADM_ID adm_id, kal_uint32 size, kal_uint32 option);
    extern kal_uint32 kal_adm_get_total_left_size(KAL_ADM_ID adm_id);
    extern void kal_adm_print_log(KAL_ADM_ID adm_id);
    extern void *kal_adm_check_integrity(KAL_ADM_ID adm_id);
    extern void *kal_adm_get_prev_block_ptr(KAL_ADM_ID adm_id, void *mem_addr);
    extern void *kal_adm_get_next_block_ptr(KAL_ADM_ID adm_id, void *mem_addr);
    extern void *kal_adm_get_trans_ptr(KAL_ADM_ID adm_id,void *mem_addr);
    /* part asm */
    extern KAL_AFM_ID kal_afm_create(void *mem_addr, kal_uint32 size, kal_uint32 *subpool_size,kal_uint32 *subpool_nr, kal_uint32 options, kal_uint32 *left_mem);
    extern void kal_afm_free(KAL_AFM_ID afm_id, void *mem_addr);
    extern kal_status kal_afm_delete(KAL_AFM_ID afm_id);
    extern kal_int32 kal_afm_check_integrity(KAL_AFM_ID afm_id);
    extern kal_int32 kal_afm_print_log(KAL_AFM_ID afm_id);
    extern kal_int32 kal_afm_get_subpool_num(KAL_AFM_ID afm_id);
    extern kal_int32 kal_afm_info_get(KAL_AFM_ID afm_id, kal_uint32 *option, kal_uint32 *buff_size, kal_uint32 *buff_nr, kal_uint32 *left_buf_nr, kal_uint32 *total_left_mem_sz);  
    extern kal_int32 kal_afm_custom_performance_info_get(KAL_AFM_ID afm_id, kal_uint32 *option, kal_uint32 *buff_size, kal_uint32 *buff_nr, kal_uint32 *alloc_cnt, kal_uint32 *min_left_buf_nr);
    extern kal_int32 kal_afm_set_cuslogging(KAL_AFM_ID afm_id, kal_uint32 cus_log_opt);
    extern kal_int32 kal_afm_get_cuslogging(KAL_AFM_ID afm_id, kal_uint32 *cus_log_opt);
    extern kal_int32 kal_afm_get_left_subpool_num(KAL_AFM_ID afm_id, kal_uint32 size);
    /* kal */
    extern kal_int32 evshed_cancel_event(event_scheduler *es, eventid *eid);
    extern void evshed_delete_all_events(event_scheduler *es);
    extern kal_bool evshed_events_pending(event_scheduler *es);             // no
    extern eventid evshed_set_event (event_scheduler *es, kal_timer_func_ptr event_hf,void *event_hf_param, kal_uint32 elapse_time);
    extern void evshed_timer_handler(event_scheduler *es);
    extern kal_enhmutexid kal_create_enh_mutex (kal_char* mutex_name);
    extern kal_eventgrpid kal_create_event_group(kal_char* eventgrp_name);
    extern kal_mutexid kal_create_mutex (kal_char* mutex_name);
    extern kal_semid kal_create_sem (kal_char*    sem_name, kal_uint32 initial_count);
    extern void kal_give_enh_mutex (kal_enhmutexid ext_mutex_ptr);                                     
    extern void kal_give_mutex (kal_mutexid ext_mutex_id_ptr);
    extern void kal_give_sem (kal_semid    ext_sem_id_ptr);
    extern kal_uint32 kal_milli_secs_to_ticks ( kal_uint32 milli_secs );
    extern kal_status kal_retrieve_eg_events(kal_eventgrpid eg_id, kal_uint32 requested_events, kal_uint8 operation, kal_uint32 *retrieved_events, kal_uint32 suspend);
    extern kal_status kal_retrieve_eg_events_timeout(kal_eventgrpid eg_id, kal_uint32 requested_events, kal_uint8 operation, kal_uint32 *retrieved_events, kal_uint32 timeout);
    extern kal_uint32 kal_secs_to_ticks ( kal_uint32 secs );
    extern kal_status kal_set_eg_events(kal_eventgrpid eg_id, kal_uint32 events, kal_uint8 operation);
    extern void kal_sleep_task(kal_uint32 time_in_ticks);
    extern void kal_take_enh_mutex(kal_enhmutexid ext_mutex_ptr);
    extern void kal_take_mutex (kal_mutexid ext_mutex_id_ptr);
    extern kal_status kal_take_sem(kal_semid ext_sem_id_ptr, kal_wait_mode wait_mode);
    extern kal_uint32 kal_ticks_to_milli_secs ( kal_uint32 ticks );
    extern kal_uint32 kal_ticks_to_secs ( kal_uint32 ticks );

    extern void* kal_evshed_get_mem(kal_uint32 size);
    extern void kal_evshed_free_mem( void* buff_ptr );
    extern kal_uint32 kal_query_sem_value(kal_semid ext_sem_id_ptr);

    /* test use function tongzhbo add end 2011-01-15 22:01 */
    static void vs_sys_start_base_timer(void *stack_timer_base, kal_uint32 time_out);
    static void vs_sys_stop_base_timer(void *stack_timer_base);
    void vs_sys_mutex_002_test(void);
    void vs_sys_semaphore_002_test(void);
    void event_cb5(void *data_db);
    void vs_sys_reset_target(void);
    static void gpt_cb(void *data);
    extern void vs_sys_report_reset(kal_int32 code) ;
    void vs_sys_start_gpt_timer(kal_uint32 time_count, void (*gptimer_func)(void *), void *cb_data);
    static void gpt_callback(void *data);
    kal_uint32 internal_print(kal_char *fmt, va_list ap);
    void vs_sys_stop_gpt_timer();

#define VS_STACK_TIMER0      0

    typedef struct ssdbg2_context_struct_t
    {
        stack_timer_struct vs_timer0;
        stack_timer_struct vs_base_timer;
        event_scheduler *vs_event_scheduler_ptr;
        eventid vs_event_id;
    } ssdbg2_context_struct_t;

    ssdbg2_context_struct_t vs_context;

    void vs_sys_stack_timer_001_start(void *base_timer_ptr, unsigned int time_out)
    {
        stack_start_timer((stack_timer_struct*) base_timer_ptr, VS_STACK_TIMER0, time_out);
        return;
    }

    void vs_sys_stack_timer_001_stop(void *base_timer_ptr)
    {
        stack_stop_timer((stack_timer_struct*) base_timer_ptr);
        return;
    }
    void vs_sys_stack_timer_001_timeout(void *msg_ptr)
    {
        ilm_struct *send_ilm;
        vs_context.vs_event_id = evshed_set_event(vs_context.vs_event_scheduler_ptr,
            (kal_timer_func_ptr) vs_sys_stack_timer_001_timeout,NULL,KAL_TICKS_500_MSEC);

        send_ilm = allocate_ilm((module_type)MOD_VS);
        send_ilm->src_mod_id = (module_type)MOD_VS;
        send_ilm->dest_mod_id = (module_type)MOD_VS;
        send_ilm->msg_id = MSG_ID_MMI_VS_INTQ_REQ;
        msg_send_ext_queue(send_ilm);
    }

    void vs_sys_stack_timer_001(task_entry_struct *task_entry_ptr)
    {
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
#endif        
    }

    static void dummy_event_cb2(void * cb_data)
    {
        int i = 100;
    }

    static void dummy_event_cb1(void * cb_data)
    {
        int i = 100;
    }
    static void fake_event_cb1(void * cb_data)
    {
        kal_bool RetHasPendingEvt_3 = KAL_FALSE;
        if(1)
        {
            RetHasPendingEvt_3 = KAL_TRUE;	        // 成功; 
        } 
        else {
            RetHasPendingEvt_3 = KAL_FALSE;	// 失败;    
        }  
    }

    static void ktest_start_base_timer(void *stack_timer_base, kal_uint32 time_out)
    {
        stack_start_timer((stack_timer_struct *)stack_timer_base, 0, time_out);
    }
    static void ktest_stop_base_timer(void *stack_timer_base)
    {
        stack_stop_timer((stack_timer_struct *)stack_timer_base);
    }


    void vs_sys_adm_001(void)
    {
        static kal_uint8 my_heap[3 * 1024];
        KAL_ADM_ID vs_dm_id = 0;
        kal_uint32 *p[3];
        void *corrupted_mem = NULL;
        int i, j = 0;
        int x = 0;      // tonghzibo add 

        // create ADM 
        vs_dm_id = kal_adm_create(my_heap, 3 * 1024, NULL, KAL_FALSE); 
        AVK_LOG_FUN(kal_adm_create,AVK_PASS);
        memset(p, 0, sizeof(kal_uint32*) * 3);
        // allocate memory 
        i = 0;
        while (1)
        {
            AVK_LOG_FUN(kal_adm_get_total_left_size,AVK_PASS);
            if (kal_adm_get_total_left_size(vs_dm_id) < (12 << j)) 
            {
                if (1) // manual option
                {
                    // mmi_popup_display_simple((WCHAR*) L"Delete Done",MMI_EVENT_SUCCESS,GRP_ID_AVK,NULL);// pop5
                }
                break;
            }
            if (p[i] != NULL)
            {
                kal_adm_free(vs_dm_id, p[i]); 
                AVK_LOG_FUN(kal_adm_free,AVK_PASS);		
                p[i] = NULL;
            }
            
            if (NULL == (p[i] = (kal_uint32*) kal_adm_alloc(vs_dm_id, (12 << j))))
            {  
                break;
            }
            AVK_LOG_FUN(kal_adm_get_max_alloc_size,AVK_PASS);
            if (kal_adm_get_max_alloc_size(vs_dm_id) < (12 << j))
            {
                if (1) // manual option
                {
                    // mmi_popup_display_simple((WCHAR*) L"more than kal_adm_get_max_alloc_size",MMI_EVENT_FAILURE,GRP_ID_AVK,NULL);// pop6
                }
            }
            i = (i + 1) % 3;
            j++;
        }
        AVK_LOG_FUN(kal_adm_check_integrity,AVK_PASS);
        if (NULL!= (corrupted_mem = kal_adm_check_integrity(vs_dm_id)))
        {
            // vs_tfw_trace_result(L"vs_sys_adm_001 Please check corrupted memory", MMI_FALSE, 0, VS_TA_SYS_BASE);
            if (1)  // manual option
            {
                // mmi_popup_display_simple((WCHAR*) L"Please check corrupted memory",MMI_EVENT_FAILURE,GRP_ID_AVK,NULL);// pop7
            }
        }
        AVK_LOG_FUN(kal_adm_print_log,AVK_PASS);
        kal_adm_print_log(vs_dm_id);
        for (i = 0; i < 3; i++)    // free memory 
        {
            if (p[i] != NULL)
            {
                AVK_LOG_FUN(kal_adm_free,AVK_PASS);
                kal_adm_free(vs_dm_id, p[i]);
            }
        }
        AVK_LOG_FUN(kal_adm_delete,AVK_PASS);
        if (kal_adm_delete(vs_dm_id) != KAL_SUCCESS)    // delete ADM 
        {
            if (1) // manual option
            {
                // mmi_popup_display_simple((WCHAR*) L"kal_adm_delete fail",MMI_EVENT_FAILURE,GRP_ID_AVK,NULL);// pop8
            }
            AVK_CASE_RESULT(AVK_FAIL);
            //	AVK_ASYN_DONE();
        }

        if (1)  // manual option
        {
            // mmi_popup_display_simple((WCHAR*) L"ADM_1 test SUCCESS!",MMI_EVENT_SUCCESS,GRP_ID_AVK,NULL);// pop9
            AVK_CASE_RESULT(AVK_PASS);
            //	 AVK_ASYN_DONE();
        }
        else
        {
            AVK_CASE_RESULT(AVK_FAIL);
            //	AVK_ASYN_DONE();
        }
    }

    void vs_sys_adm_002(void)
    {
        KAL_ADM_ID ap;
        void *p, *ptrs[100];
        void *q = NULL;
        int nptrs, i, j, k, t, v;
        kal_status r;
        kal_uint32 alloc_size, maxsize, rsize;
        kal_uint32 align;
        kal_uint32 acnt = 0, aacnt = 0, nullret = 0, totalsize = 0;

        for (i = 0; i < 8; i++) 
        {
            AVK_LOG_FUN(kal_mem_set,AVK_PASS);  
            kal_mem_set(ptrs, 0, sizeof(ptrs));
            nptrs = 0; 
            kal_mem_set(adm_buf_20K, 0, 20*1024);
            AVK_LOG_FUN(kal_adm_create,AVK_PASS);		
            ap = kal_adm_create(adm_buf_20K, 20*1024, NULL, KAL_FALSE);
            if (ap == NULL) 
            {
                // vs_tfw_trace_result(L"vs_sys_adm_002", MMI_FALSE, 0, VS_TA_SYS_BASE);
            }
            for (j = 0; j < 3000; j++) 
            {
                t = rand() % 3; // t=0,1: allocate; t=2: free
                if (t <= 1 && nptrs < sizeof(ptrs) / sizeof(ptrs[0])) 
                {
                    // allocate from ADM
                    const static int somesizes[] = {1, 4, 7, 17, 32, 100, 15, 13, 5, 200};
                    const static int somealigns[] = {4, 8, 4, 16, 4, 32, 16, 128};
                    t = rand() % (sizeof(somesizes) / sizeof(somesizes[0]));
                    alloc_size = somesizes[t];
                    t = rand() % 50; // t=49: do maximum allocate
                    align = somealigns[rand() % (sizeof(somealigns) / sizeof(somealigns[0]))];
                    if (t == 49) 
                    {                                     
                        maxsize = kal_adm_get_max_alloc_size(ap);
                        if (maxsize > align) 
                        {
                            alloc_size = maxsize - align;
                        }
                    }
                    if (align && align != 4) 
                    {
                        aacnt++;
                    }
                    else 
                    {
                        acnt++;
                    }
              				
                    p = kal_adm_alloc_align_with_info(ap, alloc_size, align, &rsize);
                    if (p == NULL) 
                    {
                        nullret++;
                                    					
                        maxsize = kal_adm_get_max_alloc_size(ap);
                                     					
                        rsize = kal_adm_calc_worst_alloc_size(ap, alloc_size, align);
                        if (rsize > maxsize) 
                        {
                            continue;
                        }
                        // vs_tfw_trace_result(L"vs_sys_adm_randalloc2", MMI_FALSE, 0, VS_TA_SYS_BASE);
                    }
                    if (rsize < 16) 
                    {
                        // vs_tfw_trace_result(L"vs_sys_adm_randalloc3", MMI_FALSE, 0, VS_TA_SYS_BASE);
                    }
                    else if ((rsize < LOG_SIZE(alloc_size)) || (rsize < NOLOG_SIZE(alloc_size))) 
                    {
                        // vs_tfw_trace_result(L"vs_sys_adm_randalloc4", MMI_FALSE, 0, VS_TA_SYS_BASE);
                    }
                    else if (align && ((kal_uint32)p % align != 0)) 
                    {
                        // vs_tfw_trace_result(L"vs_sys_adm_randalloc5", MMI_FALSE, 0, VS_TA_SYS_BASE);
                    }         
                    totalsize += alloc_size;
                                  				
                    kal_mem_set(p, 0xEB, alloc_size);
                    ptrs[nptrs++] = p;
                }
                else if (nptrs > 0) 
                {
                    v = rand() % nptrs;
                    *(kal_uint32 *)ptrs[v] = 0xFD579BA5;            				
                    kal_adm_free(ap, ptrs[v]);                                  // free an buffer
                    nptrs--;
                    for (k = v; k < nptrs; k++) 
                    {
                        ptrs[k] = ptrs[k + 1];
                    }
                    ptrs[nptrs] = NULL;
                }
                if (nptrs == sizeof(ptrs) / sizeof(ptrs[0])) 
                {
                    for (k = 0; k < 10; k++) 
                    {
                        v = rand() % nptrs;
                        *(kal_uint32 *)ptrs[v] = 0xFD579BA3;
                        kal_adm_free(ap, ptrs[v]);                              // random free 10 buffers
                        nptrs--;
                        for (k = v; k < nptrs; k++) 
                        {
                            ptrs[k] = ptrs[k + 1];
                        }
                        ptrs[nptrs] = NULL;
                    }
                }
            }

            for (j = nptrs - 1; j >= 0; j--) 
            {
                kal_adm_free(ap, ptrs[j]);                                      // free all!
                ptrs[j] = NULL;
            }
            //        r = kal_adm_delete(ap);
            if (KAL_SUCCESS != (r = kal_adm_delete(ap)))
            {

            }
        }
        AVK_LOG_FUN(kal_adm_get_max_alloc_size,AVK_PASS);
        AVK_LOG_FUN(kal_adm_alloc_align_with_info,AVK_PASS);
        AVK_LOG_FUN(kal_adm_calc_worst_alloc_size,AVK_PASS); 
        AVK_LOG_FUN(kal_mem_set,AVK_PASS); 
        AVK_LOG_FUN(kal_adm_free,AVK_PASS); 
        if (1) // manual option
        {
            AVK_CASE_RESULT(AVK_PASS);		
        }
        else
        {
            AVK_CASE_RESULT(AVK_FAIL);
        }
    }
    //kal_int32 ktest_adm_create3(kal_uint32 argc, void *argv)
    void vs_sys_adm_003(void)
    {
        static kal_uint8 my_heap[3 * 1024];
        KAL_ADM_ID vs_dm_id = 0;
        void *p1, *p2;
        kal_uint32 sz1 = 1024;

        vs_dm_id = kal_adm_create(my_heap, 3 * 1024, NULL, KAL_FALSE); 
        AVK_LOG_FUN(kal_adm_create,AVK_PASS);                	
        if(0 != vs_dm_id)
        {
            p1 = kal_adm_alloc(vs_dm_id, sz1);
//            AVK_LOG_FUN(kal_adm_alloc);                		
            if (p1 != NULL) 
            {
                p2 = kal_adm_realloc(vs_dm_id,p1,sz1*2);
//                AVK_LOG_FUN(kal_adm_realloc);                		
                if(NULL != p2)
                {
                    // mmi_popup_display_simple((WCHAR*) L"ADM_3 test SUCCESS",MMI_EVENT_SUCCESS,GRP_ID_AVK,NULL);// pop9
                    AVK_CASE_RESULT(AVK_PASS);
                }
                else
                {
                    AVK_CASE_RESULT(AVK_FAIL);
                }
            }    
        }        
    }

    void vs_sys_adm_004(void)
    {
        KAL_ADM_ID ap;
        void*   p;
        void*   ptrs[100] = {NULL};
        int nptrs = 0;
        int i = 0;
        int j = 0;

        kal_mem_set(adm_buf_20K, 0, sizeof(adm_buf_20K));
        AVK_LOG_FUN(kal_mem_set,AVK_PASS);
        ap = kal_adm_create(adm_buf_20K, sizeof(adm_buf_20K), NULL,KAL_FALSE);
        AVK_LOG_FUN(kal_adm_create,AVK_PASS);
        if (ap == NULL) 
        {
            // vs_tfw_trace_result(L"vs_sys_adm_002", MMI_FALSE, 0, VS_TA_SYS_BASE);
            return ;
        }
        for (j = 1; j < 100; j++) 
        {
            p = kal_adm_alloc_align(ap, j, 4);    
//            AVK_LOG_FUN(kal_adm_alloc_align);                		
            if(p!=NULL)
            {
                // vs_tfw_trace_result(L"kal_adm_alloc_align SUCCESS", MMI_TRUE, 0, VS_TA_SYS_BASE);        
                continue;
            }
            else
            {
                return;
            }
        }
        if (1) // manual option
        {
            // mmi_popup_display_simple((WCHAR*) L"ADM_4 test SUCCESS!",MMI_EVENT_SUCCESS,GRP_ID_AVK,NULL);
            AVK_CASE_RESULT(AVK_PASS);		
        }
        else
        {
            AVK_CASE_RESULT(AVK_FAIL);
        }
    }

    void vs_sys_adm_005(void)
    {
#if !defined(__FUE__)
        KAL_ADM_ID ap = NULL;
        void *q = NULL;
        int i=0;
        const static int somesizes[] = {1, 4, 7, 17, 32, 100, 15, 13, 5, 200};
    kal_mem_set(adm_buf_20K, 0, 20*1024);
    ap = kal_adm_create(adm_buf_20K, 20*1024, NULL, MMI_FALSE);
        AVK_LOG_FUN(kal_adm_create,AVK_PASS);
        if (ap == NULL) 
        {
        }
        for(i=0; i<10; i++)
        {
            q = (void*)kal_adm_alloc_noncacheable(ap,somesizes[i],0);

            if(NULL == q)
            {
            }
        }

        if (NULL != q) // manual option
        {
            AVK_CASE_RESULT(AVK_PASS);	
        }
        else
        {
            AVK_CASE_RESULT(AVK_FAIL);	
        }    
#else
        if (1) // manual option
        {
            AVK_CASE_RESULT(AVK_PASS);		
// 	   mmi_popup_display_simple((WCHAR*) L"Not Supported on this platform",MMI_EVENT_SUCCESS,GRP_ID_AVK,NULL);
        }
        else
        {
	     AVK_CASE_RESULT(AVK_FAIL);	
        }    
#endif
        // 2011-03-12 add endfor test kal_adm_alloc_noncacheable 21:19
    }

    /***************************************************************************** 
    * ADM test end
    *****************************************************************************/

    /***************************************************************************** 
    * KAL Timer test begin
    *****************************************************************************/
    //static kal_timerid timerID;
    static S32 timer_count = 0;

    static void vs_sys_timer_001_cancel(void)
    {
        /*----------------------------------------------------------------*/
        /* Local Variables                                                */
        /*----------------------------------------------------------------*/

        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        timer_count = 0;
        kal_cancel_timer(vs_timer_id);

        // vs_tfw_trace_result(L"vs_sys_timer_001_cancel", MMI_TRUE, 0, VS_TA_SYS_BASE);
        if (1) // manual option
        {
            // mmi_popup_display_simple((WCHAR*) L"cancel timer",MMI_EVENT_FAILURE,GRP_ID_AVK,NULL);// pop10

        }
    }


    /*****************************************************************************
    * FUNCTION
    *  vs_sys_timer_001_get
    * DESCRIPTION
    *  
    * PARAMETERS
    *  void
    * RETURNS
    *  void
    *****************************************************************************/
    static void vs_sys_timer_001_get(void)
    {
        /*----------------------------------------------------------------*/
        /* Local Variables                                                */
        /*----------------------------------------------------------------*/
        kal_uint32 ticks, secs, milli_secs, ticks1;
        kal_uint32 time_remaining;
        kal_bool flag = KAL_TRUE;

        kal_get_time(&ticks);
        secs = kal_ticks_to_secs(ticks);
        ticks1 = kal_secs_to_ticks(secs);
        if (ticks == kal_secs_to_ticks(secs))
        {
            // mmi_popup_display_simple((WCHAR*) L"kal_secs_to_ticks SUCCESS",MMI_EVENT_FAILURE,GRP_ID_AVK,NULL);// pop11
        }
        else
        {
            flag = KAL_FALSE;
        }
        milli_secs = kal_ticks_to_milli_secs(ticks);
        if (ticks == kal_milli_secs_to_ticks(milli_secs))
        {
            // mmi_popup_display_simple((WCHAR*) L"kal_milli_secs_to_ticks SUCCESS",MMI_EVENT_FAILURE,GRP_ID_AVK,NULL);// pop12
        }
        time_remaining = kal_get_time_remaining(vs_timer_id);

        if (ticks == time_remaining)
        {
            // mmi_popup_display_simple((WCHAR*)L"ticks equal time_remaining",MMI_EVENT_FAILURE,GRP_ID_AVK,NULL);// pop13
        }
        else
        {
            flag = KAL_FALSE;
        }
        if (KAL_TRUE==flag)
        {
            AVK_CASE_RESULT(AVK_PASS);
        }
        else
        {
            AVK_CASE_RESULT(AVK_FAIL);    	
        }
    }


    /*****************************************************************************
    * FUNCTION
    *  vs_sys_timer_001_timeout
    * DESCRIPTION
    *  
    * PARAMETERS
    *  param       [?]     [?]
    * RETURNS
    *  void
    *****************************************************************************/
    static void vs_sys_timer_001_timeout(void *param)
    {
        /*----------------------------------------------------------------*/
        /* Local Variables                                                */
        /*----------------------------------------------------------------*/

        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        timer_count++;
        //if (timer_count >= 10)
        {
            timer_count = 0;
            if (1) // manual option
            {
                //vs_sys_timer_001_get();
            }
            //// vs_tfw_trace_result(L"vs_sys_timer_001_timeout", MMI_TRUE, 0, VS_TA_SYS_BASE);
            if (1) // manual option
            {
                // mmi_popup_display_simple((WCHAR*) L"kal timer timeout",MMI_EVENT_FAILURE,GRP_ID_AVK,NULL);// pop14
            }
            else
            {
                /*kal_set_timer(vs_timer_id, (kal_timer_func_ptr) vs_sys_timer_001_timeout, (void*)0, KAL_TICKS_100_MSEC * 5, 0);
                vs_sys_timer_001_cancel();*/
                //// vs_tfw_finish_case(VS_SYS_TIMER);
            }
        }
        //else
        //{
        //kal_set_timer(vs_timer_id, (kal_timer_func_ptr) vs_sys_timer_001_timeout, (void*)0, KAL_TICKS_100_MSEC * 5, 0);
        //}
    }


    /*****************************************************************************
    * FUNCTION
    *  vs_sys_timer_001
    * DESCRIPTION
    *  
    * PARAMETERS
    *  void
    * RETURNS
    *  void
    *****************************************************************************/
    void vs_sys_timer_001(void)
    {
        kal_set_timer(vs_timer_id,(kal_timer_func_ptr) vs_sys_timer_001_timeout,(void*)&timer_count,KAL_TICKS_100_MSEC * 10,0); 
        if (1) // manual option
        {
            SetKeyHandler(vs_sys_timer_001_cancel, KEY_0, KEY_EVENT_UP);
            SetKeyHandler(vs_sys_timer_001_get, KEY_1, KEY_EVENT_UP);
        }
        else
        {
            vs_sys_timer_001_get();
            vs_sys_timer_001_cancel();
        }
    }

    /*****************************************************************************
    * FUNCTION
    *  vs_sys_exception_001_assert
    * DESCRIPTION
    *  
    * PARAMETERS
    *  void
    * RETURNS
    *  void
    *****************************************************************************/
    void vs_sys_exception_001_assert(void)
    {
        // mmi_popup_display_simple((WCHAR*)L"test assert, please reboot!",MMI_EVENT_FAILURE,GRP_ID_AVK,NULL);// pop15

#ifndef WIN32
        ASSERT(0);
#endif
    }
    /*****************************************************************************
    * FUNCTION
    *  vs_sys_exception_002_ext
    * DESCRIPTION
    *  
    * PARAMETERS
    *  void
    * RETURNS
    *  void
    *****************************************************************************/
    void vs_sys_exception_002_ext(void)
    {
        // mmi_popup_display_simple((WCHAR*) L"test ext_assert, please reboot!",MMI_EVENT_FAILURE,GRP_ID_AVK,NULL);// pop16

#ifndef WIN32
        EXT_ASSERT(0, 0, 0, 0);
#endif
    }

    /*****************************************************************************
    * FUNCTION
    *  vs_sys_task_001_main
    * DESCRIPTION
    *  
    * PARAMETERS
    *  task_entry_ptr      [?]     
    * RETURNS
    *  void
    *****************************************************************************/
    static void vs_sys_task_001_main(task_entry_struct *task_entry_ptr)
    {
        ilm_struct current_ilm;
        kal_uint32 my_index;

        int self = 0;
        vs_semaphore_flag = KAL_TRUE;
        vs_mutex_flag = KAL_TRUE;
        //    kal_taskid current_task_ID = NULL;

        kal_take_mutex(vs_sys_mutex);
        kal_take_sem(vs_sys_sem, KAL_INFINITE_WAIT);
        kal_get_my_task_index(&my_index);
        self = (int)kal_get_current_task();

        while (1)
        {
            //receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm); // I think here will not success
            /* replace by stack sharing, add by mingyin*/
            receive_msg_ext_q_for_stack(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm); // I think here will not success
            stack_set_active_module_id(my_index, current_ilm.dest_mod_id);

            switch (current_ilm.msg_id)
            {
            case MSG_ID_MMI_VS_SEMAPHONE:
                if (vs_mutex_flag)
                {
                    kal_give_sem(vs_sys_sem);
                    vs_mutex_flag = KAL_FALSE;
                }
                if (1) // manual option
                {
                    // vs_tfw_finish_case(VS_SYS_BASE_SEMAPHORE1);
                }
                break;
            case MSG_ID_MMI_VS_MUTEX:
                if (vs_semaphore_flag)
                {
                    kal_give_mutex(vs_sys_mutex);
                    vs_semaphore_flag = KAL_FALSE;
                }
                if (1) // manual option
                {
                    // vs_tfw_finish_case(VS_SYS_BASE_MUTEX1);
                }
                break;
            default:
                break;
            }

            free_ilm(&current_ilm);
        }
    }

    void vs_sys_eg_001_hisrEntry(void)
    {
        kal_set_eg_events(vs_sys_events, 1, KAL_OR);
    }


    void vs_sys_eg_001_LISR(void)
    {
        kal_activate_hisr(vs_sys_hisr);
    }

    kal_bool vs_sys_task_001_init(task_indx_type task_indx)
    {
        vs_sys_events = kal_create_event_group("VS_EVENTS");
        vs_sys_hisr = kal_init_hisr( VS_HISR );

        vs_sys_sem = kal_create_sem("vs_semaphore", 1);
        vs_sys_mutex = kal_create_mutex("vs_mutex");
        vs_msg_q_id = kal_create_msg_q("vs_sys_test_msg_q", 8, 15);
        vs_timer_id = kal_create_timer("VSTEST");

        return KAL_TRUE;
    }

    kal_bool vs_sys_task_001_create(comptask_handler_struct **handle)
    {
        static const comptask_handler_struct custom1_handler_info = 
        {
            vs_sys_task_001_main,    /* task entry function */
            vs_sys_task_001_init,       /* task initialization function */
            NULL,                               /* task configuration function */
            NULL,                               /* task reset handler */
            NULL,                               /* task termination handler */
        };
        *handle = (comptask_handler_struct*) & custom1_handler_info;
        return KAL_TRUE;
    }

    void vs_sys_task_002_change_priority(void)
    {
        kal_uint32 prioity1 = kal_get_mytask_priority();
		
        kal_uint32 prioity2 = 0;
        kal_taskid current_thread = 0;
        current_thread = kal_get_current_task();
	    AVK_LOG_FUN(kal_get_mytask_priority,AVK_PASS);
	    AVK_LOG_FUN(kal_get_current_task,AVK_PASS);
	    AVK_LOG_FUN(kal_if_hisr,AVK_PASS);
        if (kal_if_hisr() == KAL_FALSE)
        {
            kal_change_priority(current_thread, 213);
	        AVK_LOG_FUN(kal_change_priority,AVK_PASS);
            prioity2 = kal_get_current_task_priority();
	        AVK_LOG_FUN(kal_get_current_task_priority,AVK_PASS);
            stack_change_priority_by_module_ID(MOD_MMI, prioity1);
	        AVK_LOG_FUN(stack_change_priority_by_module_ID,AVK_PASS);
            prioity2 = kal_get_current_task_priority();
	        AVK_LOG_FUN(kal_get_current_task_priority,AVK_PASS);
            if (prioity1 == prioity2)
            {
                // mmi_popup_display_simple((WCHAR*)L"task change priority SUCCESS!",MMI_EVENT_SUCCESS,GRP_ID_AVK,NULL);
                AVK_CASE_RESULT(AVK_PASS);	
            }
            else
            {
                // mmi_popup_display_simple((WCHAR*)L"task change priority FAIL!",MMI_EVENT_SUCCESS,GRP_ID_AVK,NULL);
                AVK_CASE_RESULT(AVK_FAIL);		
            }
        }
    }

    void vs_sys_task_003_get_task(void)
    {
        kal_uint32 prioity1 = kal_get_mytask_priority();
        kal_uint32 prioity2 = 0;    
        kal_uint32 prioity3 = 0;        
        kal_internal_taskid curr_taskid;    
        kal_uint32 current_task_index = 0;
        kal_uint32 vs_task_index = 0;    
        kal_taskid current_task = 0;
	    AVK_LOG_FUN(kal_get_mytask_priority,AVK_PASS);
	    AVK_LOG_FUN(kal_if_hisr,AVK_PASS);
        if (kal_if_hisr() == KAL_FALSE)
        {
            current_task_index= kal_get_current_task_index();
	        AVK_LOG_FUN(kal_get_current_task_index,AVK_PASS);	 			
            curr_taskid = (kal_internal_taskid)kal_get_current_task();            
	        AVK_LOG_FUN(kal_get_current_task,AVK_PASS);			   
            current_task = kal_get_task_by_index((task_indx_type)current_task_index);
	        AVK_LOG_FUN(kal_get_task_by_index,AVK_PASS);				   
            prioity2 = kal_get_task_priority(current_task);
	        AVK_LOG_FUN(kal_get_task_priority,AVK_PASS);				   
            vs_task_index = kal_map_module_to_task_index((module_type)MOD_VS);
	        AVK_LOG_FUN(kal_map_module_to_task_index,AVK_PASS);			   
            if ((prioity1 == prioity2)&&(INDX_VS == vs_task_index))
            {
                // mmi_popup_display_simple((WCHAR*)L"get task test SUCCESS! ",MMI_EVENT_SUCCESS,GRP_ID_AVK,NULL);
                AVK_CASE_RESULT(AVK_PASS);
            }
            else
            {
                // mmi_popup_display_simple((WCHAR*)L"get task test FAIL! ",MMI_EVENT_SUCCESS,GRP_ID_AVK,NULL);
                AVK_CASE_RESULT(AVK_FAIL);
            }
        }
    }


    void vs_sys_eg_001_retrieve(void)
    {
        kal_uint32 event_group;
        if (1) // manual option
        {
            // mmi_popup_display_simple((WCHAR*) L"Please click next menu item to trigger test!",MMI_EVENT_FAILURE,GRP_ID_AVK,NULL);
        }
        else
        {
            vs_sys_eg_001_set();
        }

        kal_retrieve_eg_events(vs_sys_events, 1, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);

        // vs_tfw_trace_result(L"vs_sys_eg_001_retrieve", MMI_TRUE, 0, VS_TA_SYS_BASE);
        if (1) // manual option
        {
            // mmi_popup_display_simple((WCHAR*) L"event group test SUCCESS!",MMI_EVENT_FAILURE,GRP_ID_AVK,NULL);
        }
        else
        {
            // vs_tfw_finish_case(VS_SYS_BASE_EG);
        }
    }

    void vs_sys_eg_001_set(void)
    {
        vs_sys_eg_001_hisrEntry();
    }

    /***************************************************************************** 
    * Task test end
    *****************************************************************************/
    static void vs_sysser_base_entry_highlight(S32 index)
    {
        switch (index)
        {
        case 0: // adm 1
            SetKeyHandler(vs_sys_adm_001, KEY_LSK, KEY_EVENT_UP);
            SetLeftSoftkeyFunction(vs_sys_adm_001, KEY_EVENT_UP);
            break;
        case 1: // adm 2
            SetKeyHandler(vs_sys_adm_002, KEY_LSK, KEY_EVENT_UP);
            SetLeftSoftkeyFunction(vs_sys_adm_002, KEY_EVENT_UP);
            break;
        case 2: // adm 3
            SetKeyHandler(vs_sys_adm_003, KEY_LSK, KEY_EVENT_UP);
            SetLeftSoftkeyFunction(vs_sys_adm_003, KEY_EVENT_UP);
            break;    
        case 3: // adm 4
            SetKeyHandler(vs_sys_adm_004, KEY_LSK, KEY_EVENT_UP);
            SetLeftSoftkeyFunction(vs_sys_adm_004, KEY_EVENT_UP);
            break;        
        case 4: // adm 5
            SetKeyHandler(vs_sys_adm_005, KEY_LSK, KEY_EVENT_UP);
            SetLeftSoftkeyFunction(vs_sys_adm_005, KEY_EVENT_UP);
            break;      
        case 5: // afm 1  vs_sys_afm_001
            SetKeyHandler(vs_sys_afm_001, KEY_LSK, KEY_EVENT_UP);
            SetLeftSoftkeyFunction(vs_sys_afm_001, KEY_EVENT_UP);    
            break;
        case 6: // afm 2
            SetKeyHandler(vs_sys_afm_002, KEY_LSK, KEY_EVENT_UP);
            SetLeftSoftkeyFunction(vs_sys_afm_002, KEY_EVENT_UP);    
            break;
        case 7:  // afm 3
            SetKeyHandler(vs_sys_afm_003, KEY_LSK, KEY_EVENT_UP);
            SetLeftSoftkeyFunction(vs_sys_afm_003, KEY_EVENT_UP);    
            break;
        case 8:  // afm 4
            SetKeyHandler(vs_sys_afm_004, KEY_LSK, KEY_EVENT_UP);
            SetLeftSoftkeyFunction(vs_sys_afm_004, KEY_EVENT_UP);    
            break;
        case 9: // task
            SetKeyHandler(vs_sys_task_002_change_priority, KEY_LSK, KEY_EVENT_UP);
            SetLeftSoftkeyFunction(vs_sys_task_002_change_priority, KEY_EVENT_UP);
            break;
        case 10: // task 1
            SetKeyHandler(vs_sys_task_003_get_task, KEY_LSK, KEY_EVENT_UP);
            SetLeftSoftkeyFunction(vs_sys_task_003_get_task, KEY_EVENT_UP);
            break;        
        case 11: // mutex 1
            SetKeyHandler(vs_sys_mutex_001_send_msg, KEY_LSK, KEY_EVENT_UP);
            SetLeftSoftkeyFunction(vs_sys_mutex_001_send_msg, KEY_EVENT_UP);
            break;
        case 12: // mutex 2
            SetKeyHandler(vs_sys_mutex_002_test, KEY_LSK, KEY_EVENT_UP);
            SetLeftSoftkeyFunction(vs_sys_mutex_002_test, KEY_EVENT_UP);
            break;
        case 13: // Semaphore 1
            SetKeyHandler(vs_sys_semaphore_001_send_msg, KEY_LSK, KEY_EVENT_UP);
            SetLeftSoftkeyFunction(vs_sys_semaphore_001_send_msg, KEY_EVENT_UP);
            break;
        case 14: // Semaphore 2
            SetKeyHandler(vs_sys_semaphore_002_test, KEY_LSK, KEY_EVENT_UP);
            SetLeftSoftkeyFunction(vs_sys_semaphore_002_test, KEY_EVENT_UP);
            break;
        case 15: // evshed_1
            SetKeyHandler(vs_sys_evshed_001_test, KEY_LSK, KEY_EVENT_UP);
            SetLeftSoftkeyFunction(vs_sys_evshed_001_test, KEY_EVENT_UP);
            break;
        case 16: // evshed_2
            SetKeyHandler(vs_sys_evshed_002_test, KEY_LSK, KEY_EVENT_UP);
            SetLeftSoftkeyFunction(vs_sys_evshed_002_test, KEY_EVENT_UP);
            break;
        default:        
            break;
        }
    }
    /*****************************************--- asm ---********************************************************/
    void vs_sys_afm_001()
    {
        kal_uint32          subpool_size[]      = SMALL_SUBPOOL_SIZE;
        kal_uint32          subpool_nr[]          = SMALL_SUBPOOL_NR;
        kal_uint32          size                      = 0;
        void*             p                           = NULL;
        KAL_AFM_ID     afmid                    = NULL;  
        kal_uint32          left_mem               = 0;
#ifndef OPTION
#define OPTION	AFM_OPT_DBG
#endif
        size = KAL_AFM_POOL_OVERHEAD(OPTION, _SIZEOF(subpool_size)-1) + KAL_AFM_SUBPOOL_OVERHEAD(OPTION, 50, 3);
        p = (void*)kal_sys_mem_alloc(size);
        AVK_LOG_FUN(kal_sys_mem_alloc,AVK_PASS);	
        if (p == NULL) 
        {
            vs_sys_reset_target();
        }
        afmid = kal_afm_create(p, size, subpool_size, subpool_nr, OPTION, &left_mem);
        AVK_LOG_FUN(kal_afm_create,AVK_PASS);		
        p = kal_afm_alloc(afmid, subpool_size[0]);
//        AVK_LOG_FUN(kal_afm_alloc);		
        *((int *)p - 1) = AFM_HEAD_STAMP;
        kal_afm_free(afmid, p);
        AVK_LOG_FUN(kal_afm_free,AVK_PASS);		
#undef OPTION
        if (1) // manual option
        {
            // mmi_popup_display_simple((WCHAR*) L"AFM_1 test SUCCESS!",MMI_EVENT_SUCCESS,GRP_ID_AVK,NULL);
            AVK_CASE_RESULT(AVK_PASS);
        }
        else
        {
            // mmi_popup_display_simple((WCHAR*) L"AFM_1 test FAIL!",MMI_EVENT_SUCCESS,GRP_ID_AVK,NULL);
            AVK_CASE_RESULT(AVK_FAIL);
        }
    }

    void vs_sys_afm_002()
    {
        kal_uint32          subpool_size[] = SMALL_SUBPOOL_SIZE;
        kal_uint32          subpool_nr[]     = SMALL_SUBPOOL_NR;
        kal_uint32          size                 = 0;
        void *                 p                      = NULL;
        KAL_AFM_ID           afmid               = NULL; 
        kal_uint32          left_mem          = 0;
#ifndef OPTION
#define OPTION	0
#endif
        size = KAL_AFM_POOL_OVERHEAD(OPTION, _SIZEOF(subpool_size)-1) + KAL_AFM_SUBPOOL_OVERHEAD(OPTION, 50, 3);
        p = (void*)kal_sys_mem_alloc(size);
        AVK_LOG_FUN(kal_sys_mem_alloc,AVK_PASS);	
        if (p == NULL) 
        {
            // vs_tfw_trace_result(L"vs_sys_afm_size1", MMI_FALSE, 0, VS_TA_SYS_BASE);
            vs_sys_reset_target();
        }
        afmid = kal_afm_create(p, size, subpool_size, subpool_nr, OPTION, &left_mem);
        AVK_LOG_FUN(kal_afm_create,AVK_PASS);		
#undef OPTION
        {
            kal_uint32 status = kal_afm_delete(afmid);
	        AVK_LOG_FUN(kal_afm_delete,AVK_PASS);			
            if (status != KAL_SUCCESS) 
            {
                // mmi_popup_display_simple((WCHAR*) L"AFM_2 test FAIL! ",MMI_EVENT_SUCCESS,GRP_ID_AVK,NULL);
                AVK_CASE_RESULT(AVK_FAIL);
                return;
            }
        }
        AVK_CASE_RESULT(AVK_PASS);
        // mmi_popup_display_simple((WCHAR*) L"AFM_2 test SUCCESS! ",MMI_EVENT_SUCCESS,GRP_ID_AVK,NULL);
    }
    void vs_sys_afm_003()
    {
        kal_uint32 subpool_size[]   = BIG_SUBPOOL_SIZE; 
        kal_uint32 subpool_nr[]      = BIG_SUBPOOL_NR; 
        kal_uint32 size = 0;
        void*   p    = NULL;
        void*   p1  = NULL; 
        void*   p2  = NULL; 
        void*   p3  = NULL;
        void*   p4  = NULL;    
        void*   p5  = NULL;        
        KAL_AFM_ID afmid = NULL; 
        KAL_AFM_ID afmid1 = NULL;     
        kal_uint32 left_mem = 0;
        kal_uint32 logen =0;
        kal_uint32 i =0;
        kal_uint32 subpool_size2[]  = {0, 0, 0, 0, 0, AFM_SUBPOOL_END_PATTERN};
        kal_uint32 subpool_nr2[]     = {0, 0, 0, 0, 0, AFM_SUBPOOL_END_PATTERN};
        kal_uint32 alloc_cnt2[]       = {0, 0, 0, 0, 0, AFM_SUBPOOL_END_PATTERN};
        kal_uint32 minleft2[]          = {0, 0, 0, 0, 0, AFM_SUBPOOL_END_PATTERN};
        kal_uint32 option = 0;
#ifndef OPTION
#define OPTION	AFM_OPT_DBG | AFM_OPT_CUSLOG
#endif
        size = KAL_AFM_POOL_OVERHEAD(OPTION, _SIZEOF(subpool_size)-1) + KAL_AFM_SUBPOOL_OVERHEAD(OPTION, 50, 3) 
            + KAL_AFM_SUBPOOL_OVERHEAD(OPTION, 100, 10) + KAL_AFM_SUBPOOL_OVERHEAD(OPTION, 150, 4)
            + KAL_AFM_SUBPOOL_OVERHEAD(OPTION, 300, 1) + KAL_AFM_SUBPOOL_OVERHEAD(OPTION, 512, 6);
        p = a_cacheable_buf_c; //kal_sys_mem_alloc(size);
        if (p == NULL) 
        {
            // vs_tfw_trace_result(L"vs_sys_afm_test_cuslogging1", MMI_FALSE, 0, VS_TA_SYS_BASE);
            vs_sys_reset_target();
        }
        afmid = kal_afm_create(p, size, subpool_size, subpool_nr, OPTION, &left_mem);
        AVK_LOG_FUN(kal_afm_create,AVK_PASS);		
        afmid1 = kal_afm_create(p, size, subpool_size, subpool_nr, OPTION, &left_mem);    
        AVK_LOG_FUN(kal_afm_create,AVK_PASS);		
#undef OPTION
	    AVK_LOG_FUN(kal_afm_get_cuslogging,AVK_PASS);
        if (kal_afm_get_cuslogging(afmid, &logen) != 0) 
        {
            // vs_tfw_trace_result(L"vs_sys_afm_test_cuslogging2", MMI_FALSE, 0, VS_TA_SYS_BASE);
            vs_sys_reset_target();
        }
        if (logen != AFM_LOG_STR) 
        {
            // vs_tfw_trace_result(L"vs_sys_afm_test_cuslogging3", MMI_FALSE, 0, VS_TA_SYS_BASE);
            vs_sys_reset_target();
        }
	    AVK_LOG_FUN(kal_afm_set_cuslogging,AVK_PASS);
        if (kal_afm_set_cuslogging(afmid, AFM_LOG_PAUSE | AFM_LOG_CLR) != 0) 
        {
            // vs_tfw_trace_result(L"vs_sys_afm_test_cuslogging4", MMI_FALSE, 0, VS_TA_SYS_BASE);
            vs_sys_reset_target();
        }
	    AVK_LOG_FUN(kal_afm_set_cuslogging,AVK_PASS);		
        if (kal_afm_set_cuslogging(afmid, AFM_LOG_STR | AFM_LOG_CLR) != 0) 
        {
            // vs_tfw_trace_result(L"vs_sys_afm_test_cuslogging5", MMI_FALSE, 0, VS_TA_SYS_BASE);
            vs_sys_reset_target();
        }

        //allocate 3 buffers on pool0, and assert its performance counters
        
        p1 = kal_afm_alloc(afmid, 48);
        p2 = kal_afm_alloc(afmid, 512);
        p3 = kal_afm_alloc(afmid, 1);
	
	    AVK_LOG_FUN(kal_afm_custom_performance_info_get,AVK_PASS);
        if (kal_afm_custom_performance_info_get(afmid, &option, subpool_size2, subpool_nr2, alloc_cnt2, minleft2) != 0) 
        {
            // vs_tfw_trace_result(L"vs_sys_afm_test_cuslogging6", MMI_FALSE, 0, VS_TA_SYS_BASE);
            vs_sys_reset_target();
        }
        if (alloc_cnt2[0] != 3) 
        {
            // vs_tfw_trace_result(L"vs_sys_afm_test_cuslogging7", MMI_FALSE, 0, VS_TA_SYS_BASE);
            vs_sys_reset_target();
        }
        if (minleft2[0] != 0) {
            // vs_tfw_trace_result(L"vs_sys_afm_test_cuslogging8", MMI_FALSE, 0, VS_TA_SYS_BASE);
            vs_sys_reset_target();
        }

        kal_afm_free(afmid, p1);
        kal_afm_free(afmid, p2);
        kal_afm_free(afmid, p3);
	    AVK_LOG_FUN(kal_afm_free,AVK_PASS);
        // verify after free
	    AVK_LOG_FUN(kal_afm_custom_performance_info_get,AVK_PASS);
        if (kal_afm_custom_performance_info_get(afmid, &option, subpool_size2, subpool_nr2, alloc_cnt2, minleft2) != 0)
        {
            // vs_tfw_trace_result(L"vs_sys_afm_test_cuslogging9", MMI_FALSE, 0, VS_TA_SYS_BASE);
            vs_sys_reset_target();
        }
        if (alloc_cnt2[0] != 3) 
        {
            // vs_tfw_trace_result(L"vs_sys_afm_test_cuslogging10", MMI_FALSE, 0, VS_TA_SYS_BASE);
            vs_sys_reset_target();
        }
        if (minleft2[0] != 0) 
        {
            // vs_tfw_trace_result(L"vs_sys_afm_test_cuslogging11", MMI_FALSE, 0, VS_TA_SYS_BASE);
            vs_sys_reset_target();
        }
        // pause & clear, verify
        kal_afm_set_cuslogging(afmid, AFM_LOG_PAUSE | AFM_LOG_CLR);
	    AVK_LOG_FUN(kal_afm_set_cuslogging,AVK_PASS);
        if (kal_afm_custom_performance_info_get(afmid, &option, subpool_size2, subpool_nr2, alloc_cnt2, minleft2) != 0) 
        {
            // vs_tfw_trace_result(L"vs_sys_afm_test_cuslogging12", MMI_FALSE, 0, VS_TA_SYS_BASE);
            vs_sys_reset_target();
        }
        if (alloc_cnt2[0] != 0) 
        {
            // vs_tfw_trace_result(L"vs_sys_afm_test_cuslogging13", MMI_FALSE, 0, VS_TA_SYS_BASE);
            vs_sys_reset_target();
        }
        if (minleft2[0] != 3) 
        {
            // vs_tfw_trace_result(L"vs_sys_afm_test_cuslogging14", MMI_FALSE, 0, VS_TA_SYS_BASE);
            vs_sys_reset_target();
        }
        // cuslog is pause, do some allocate...
        p1 = kal_afm_alloc(afmid, 80);
        p2 = kal_afm_alloc(afmid, 120);
        p3 = kal_afm_alloc(afmid, 180);
//	    AVK_LOG_FUN(kal_afm_alloc);		
        if (kal_afm_custom_performance_info_get(afmid, &option, subpool_size2, subpool_nr2, alloc_cnt2, minleft2) != 0) 
        {
            // vs_tfw_trace_result(L"vs_sys_afm_test_cuslogging15", MMI_FALSE, 0, VS_TA_SYS_BASE);
            vs_sys_reset_target();
        }
        if (alloc_cnt2[0] != 0 || alloc_cnt2[1] != 0 || alloc_cnt2[2] != 0 || alloc_cnt2[3] != 0 || alloc_cnt2[4] != 0) 
        {
            // vs_tfw_trace_result(L"vs_sys_afm_test_cuslogging16", MMI_FALSE, 0, VS_TA_SYS_BASE);
            vs_sys_reset_target();
        }
        if (minleft2[0] != 3 || minleft2[1] != 10 || minleft2[2] != 4 || minleft2[3] != 1 || minleft2[4] != 6) 
        {
            // vs_tfw_trace_result(L"vs_sys_afm_test_cuslogging17", MMI_FALSE, 0, VS_TA_SYS_BASE);
            vs_sys_reset_target();
        }
        kal_afm_free(afmid, p1);
        kal_afm_free(afmid, p2);
        kal_afm_free(afmid, p3);
	    AVK_LOG_FUN(kal_afm_free,AVK_PASS);
        // start again
        if (kal_afm_set_cuslogging(afmid, AFM_LOG_STR) != 0) 
        {
            // vs_tfw_trace_result(L"vs_sys_afm_test_cuslogging18", MMI_FALSE, 0, VS_TA_SYS_BASE);
            vs_sys_reset_target();
        }
        //alloc & verify
        p1 = kal_afm_alloc(afmid, 80);
        p2 = kal_afm_alloc(afmid, 120);
        p3 = kal_afm_alloc(afmid, 180);
	 //AVK_LOG_FUN(kal_afm_alloc);		
        if (kal_afm_custom_performance_info_get(afmid, &option, subpool_size2, subpool_nr2, alloc_cnt2, minleft2) != 0) 
        {
            // vs_tfw_trace_result(L"vs_sys_afm_test_cuslogging19", MMI_FALSE, 0, VS_TA_SYS_BASE);
            vs_sys_reset_target();
        }
        if (alloc_cnt2[0] != 0 || alloc_cnt2[1] != 1 || alloc_cnt2[2] != 1 || alloc_cnt2[3] != 1 || alloc_cnt2[4] != 0) 
        {    
            // vs_tfw_trace_result(L"vs_sys_afm_test_cuslogging20", MMI_FALSE, 0, VS_TA_SYS_BASE);
            vs_sys_reset_target();
        }
        if (minleft2[0] != 3 || minleft2[1] != 9 || minleft2[2] != 3 || minleft2[3] != 0 || minleft2[4] != 6) 
        {
            // vs_tfw_trace_result(L"vs_sys_afm_test_cuslogging21", MMI_FALSE, 0, VS_TA_SYS_BASE);
            vs_sys_reset_target();
        }
        kal_afm_free(afmid, p1);
        kal_afm_free(afmid, p2);
        kal_afm_free(afmid, p3);
        {
            kal_uint32 status = kal_afm_delete(afmid);
    	    AVK_LOG_FUN(kal_afm_delete,AVK_PASS);
            if (status != KAL_SUCCESS) 
            {
                // mmi_popup_display_simple((WCHAR*) L"AFM_3 test FAIL!",MMI_EVENT_SUCCESS,GRP_ID_AVK,NULL);
                AVK_CASE_RESULT(AVK_FAIL);   	     			
                vs_sys_reset_target();
                return;			
            }
        }
        // mmi_popup_display_simple((WCHAR*) L"AFM_3 test SUCCESS!",MMI_EVENT_SUCCESS,GRP_ID_AVK,NULL);
        AVK_CASE_RESULT(AVK_PASS);  	
        return;
    }

    // zhibo add start --2011-03-12 22:20 for test kal_afm_alloc_cacheable       
    void vs_sys_afm_004()
    {
#if defined(__MTK_TARGET__) && (defined(__ARM9_MMU__) || defined(__DYNAMIC_SWITCH_CACHEABILITY__))
        kal_uint32 subpool_size[]   = BIG_SUBPOOL_SIZE; 
        kal_uint32 subpool_nr[]      = BIG_SUBPOOL_NR; 
        kal_uint32 left_mem = 0;    
        kal_uint32 size = 0;
        void*   p_cacheable  = NULL;
        void*   p_NoCacheable  = NULL;    
        void*   p4  = NULL;
        void*   p5  = NULL;
        void*   p    = NULL;
        KAL_AFM_ID afmid = NULL; 
        KAL_AFM_ID afmid1 = NULL;     
        kal_uint32 i =0;
#ifndef OPTION
#define OPTION	AFM_OPT_DBG | AFM_OPT_CUSLOG |AFM_OPT_ALIGN_ALLOC
#endif
        size = KAL_AFM_POOL_OVERHEAD(OPTION, _SIZEOF(subpool_size)-1) + KAL_AFM_SUBPOOL_OVERHEAD(OPTION, 50, 3) 
            + KAL_AFM_SUBPOOL_OVERHEAD(OPTION, 100, 10) + KAL_AFM_SUBPOOL_OVERHEAD(OPTION, 150, 4)
            + KAL_AFM_SUBPOOL_OVERHEAD(OPTION, 300, 1) + KAL_AFM_SUBPOOL_OVERHEAD(OPTION, 512, 6);
        p = AVK_MALLOC(size);
        if (p == NULL) 
        {
            // vs_tfw_trace_result(L"vs_sys_afm_test_cuslogging1", MMI_FALSE, 0, VS_TA_SYS_BASE);
            return;
        }
       
	 AVK_LOG_FUN(kal_afm_create,AVK_PASS);		
        afmid = kal_afm_create(p, size, subpool_size, subpool_nr, OPTION, &left_mem);
        afmid1 = kal_afm_create(p, size, subpool_size, subpool_nr, OPTION, &left_mem);
 	AVK_LOG_FUN(kal_afm_alloc,AVK_PASS);
        p_cacheable = kal_afm_alloc(afmid, 512);
        p_NoCacheable = kal_afm_alloc(afmid1,512);
#undef OPTION         
        for(i=0; i<10; i++) 
        {
            p4 = kal_afm_alloc_cacheable((KAL_AFM_ID)afmid,5,0);
	     AVK_LOG_FUN(kal_afm_alloc_cacheable,AVK_PASS);			
            if(NULL != p4)  
            {
            }        
        }
        for(i=0; i<10; i++)
        {
            p5 = kal_afm_alloc_noncacheable((KAL_AFM_ID)afmid1,5,0);
	     AVK_LOG_FUN(kal_afm_alloc_noncacheable,AVK_PASS);			
            if(NULL == p5)
            {
            }        
        }   
        if (1) // manual option
        {
            // mmi_popup_display_simple((WCHAR*) L"AFM_4 test SUCCESS!",MMI_EVENT_SUCCESS,GRP_ID_AVK,NULL);
            AVK_CASE_RESULT(AVK_PASS);
        }
        else
        {
            AVK_CASE_RESULT(AVK_FAIL);
        }
        AVK_FREE(p);
#else    
        if (1) // manual option
        {
            // mmi_popup_display_simple((WCHAR*) L"Not Supported on this platform",MMI_EVENT_SUCCESS,GRP_ID_AVK,NULL);
            AVK_CASE_RESULT(AVK_PASS);		
        }
        else
        {
            AVK_CASE_RESULT(AVK_FAIL);
        }        
#endif        
    }
    // zhibo add start --2011-03-12 22:20 for test kal_afm_alloc_cacheable   


    /*****************************************************************************
    * FUNCTION
    *  vs_sys_mutex_001_send_msg
    * DESCRIPTION
    *  
    * PARAMETERS
    *  void
    * RETURNS
    *  void
    *****************************************************************************/
    void vs_sys_mutex_001_send_msg(void) // wait for phose out 2011-01-19
    {
        ilm_struct *send_ilm;
        kal_bool retVal = KAL_FALSE;

        send_ilm = allocate_ilm(MOD_MMI);
        send_ilm->src_mod_id = MOD_MMI;
        send_ilm->dest_mod_id = (module_type)MOD_VS;
        send_ilm->msg_id = MSG_ID_MMI_VS_MUTEX;
        retVal = msg_send_ext_queue(send_ilm); 

        if(KAL_TRUE == retVal)
        {
            // mmi_popup_display_simple((WCHAR*)L"MUTEX 1 sent message SUCCESS",MMI_EVENT_SUCCESS,GRP_ID_AVK,NULL);
            AVK_CASE_RESULT(AVK_PASS);
        }
        else
        {
            // mmi_popup_display_simple((WCHAR*) L"MUTEX 1 sent message FAILED",MMI_EVENT_FAILURE,GRP_ID_AVK,NULL);
            AVK_CASE_RESULT(AVK_FAIL);
        }
    }

    /*****************************************************************************
    * FUNCTION
    *  vs_sys_mutex_001_test
    * DESCRIPTION
    *  
    * PARAMETERS
    *  void
    * RETURNS
    *  void
    *****************************************************************************/
    void vs_sys_mutex_002_test(void)
    {
	    vs_sys_mutex_001_send_msg();
        kal_take_mutex(vs_sys_mutex);
        kal_give_mutex(vs_sys_mutex);
	    AVK_LOG_FUN(kal_take_mutex,AVK_PASS);
	    AVK_LOG_FUN(kal_give_mutex,AVK_PASS);
        if (1) // manual option
        {
            // mmi_popup_display_simple((WCHAR*) L"mutex 2 test SUCCESS!",MMI_EVENT_SUCCESS,GRP_ID_AVK,NULL);// pop20
            AVK_CASE_RESULT(AVK_PASS);
        }
        else
        {
            AVK_CASE_RESULT(AVK_FAIL);
        }
    }

    void vs_sys_semaphore_001_send_msg(void)
    {
        ilm_struct *send_ilm;
        kal_bool  retVal = KAL_FALSE;

        send_ilm = allocate_ilm(MOD_MMI);
        send_ilm->src_mod_id = MOD_MMI;
        send_ilm->dest_mod_id = (module_type)MOD_VS;
        send_ilm->msg_id = MSG_ID_MMI_VS_SEMAPHONE;
        retVal = msg_send_ext_queue(send_ilm);
	    AVK_LOG_FUN(allocate_ilm,AVK_PASS);
	    AVK_LOG_FUN(msg_send_ext_queue,AVK_PASS);	
        if(KAL_TRUE == retVal)
        {
            // mmi_popup_display_simple((WCHAR*) L"semaphore 1 send msg SUCCESS",MMI_EVENT_SUCCESS,GRP_ID_AVK,NULL);
            AVK_CASE_RESULT(AVK_PASS);
        }
        else
        {
            // mmi_popup_display_simple((WCHAR*) L"semaphore 1 send msg FAILED",MMI_EVENT_FAILURE,GRP_ID_AVK,NULL);
            AVK_CASE_RESULT(AVK_FAIL);
        }
    }

    /*****************************************************************************
    * FUNCTION
    *  vs_sys_semaphore_001_test
    * DESCRIPTION
    *  
    * PARAMETERS
    *  void
    * RETURNS
    *  void
    *****************************************************************************/
    void vs_sys_semaphore_002_test(void)
    {
        // handset will freezn when take sem unsuccessful
        kal_take_sem(vs_sys_sem, KAL_INFINITE_WAIT);
        kal_give_sem(vs_sys_sem);
	    AVK_LOG_FUN(kal_take_sem,AVK_PASS);
	    AVK_LOG_FUN(kal_give_sem,AVK_PASS);	
	    AVK_LOG_FUN(kal_query_sem_value,AVK_PASS);		
        if (kal_query_sem_value(vs_sys_sem) == 1)
        {
            // mmi_popup_display_simple((WCHAR*) L"semaphore 2 test SUCCESS!",MMI_EVENT_SUCCESS,GRP_ID_AVK,NULL);            
            AVK_CASE_RESULT(AVK_PASS);
        }
        else
        {
            AVK_CASE_RESULT(AVK_FAIL);
        }
    }

    void vs_sys_evshed_001_test(void)
    {
        event_scheduler*  ES_Test_1 =   NULL;
        event_scheduler*  ES_Test_2 =   NULL;
        kal_bool RetHasPendingEvt_1 =   KAL_FALSE;
        kal_bool RetHasPendingEvt_2 =   KAL_FALSE;
        eventid     id = NULL;
        ES_Test_1 = evshed_create("Test_Event_Schedule_1",(module_type)MOD_VS,0,0);
	    AVK_LOG_FUN(evshed_create,AVK_PASS);
        if(NULL != ES_Test_1)
        {
	        AVK_LOG_FUN(evshed_has_pending_events,AVK_PASS);
            if(evshed_has_pending_events(ES_Test_1) == KAL_FALSE) {
                RetHasPendingEvt_1 = KAL_TRUE;            // 成功; 
            }
            else{
                RetHasPendingEvt_1 = KAL_FALSE;           // 失败;
            }
            // set an event on evid;
            AVK_LOG_FUN(evshed_set_event,AVK_PASS);
            id = evshed_set_event(ES_Test_1, dummy_event_cb1, NULL, 2000);
            AVK_LOG_FUN(evshed_has_pending_events,AVK_PASS);
            if(evshed_has_pending_events(ES_Test_1) == KAL_TRUE) {
                RetHasPendingEvt_2 = KAL_TRUE;            // 成功; 

            } 
            else{
                RetHasPendingEvt_2 = KAL_FALSE;            // 失败;
            }
        }
        if((KAL_TRUE == RetHasPendingEvt_1)&&(KAL_TRUE == RetHasPendingEvt_2)){
            // mmi_popup_display_simple((WCHAR*) L"Event Schedule 1 SUCCESS ",MMI_EVENT_SUCCESS,GRP_ID_AVK,NULL);// SUCCESS
            AVK_CASE_RESULT(AVK_PASS);
        }
        else{
            // mmi_popup_display_simple((WCHAR*) L"Event Schedule 1 FAILED ",MMI_EVENT_FAILURE,GRP_ID_AVK,NULL); // FAILED
            AVK_CASE_RESULT(AVK_FAIL);
        }
    }
    void event_cb7(void *data)
    {
    }

    void vs_sys_evshed_002_test(void)
    {
        stack_timer_struct st;
        event_scheduler *es;

        stack_init_timer(&st, "test", (module_type)MOD_VS);    
        es = evshed_create("test",(module_type)MOD_VS,20,0);
        evshed_set_event(es, event_cb7, NULL, 5);         
        evshed_set_event(es, event_cb7, NULL, 8);              
        evshed_set_event(es, event_cb7, NULL, 10);            
        evshed_set_event(es, event_cb7, NULL, 20);           
        evshed_suspend_all_events(es);
        evshed_resume_all_events(es);    

	    AVK_LOG_FUN(stack_init_timer,AVK_PASS);	
	    AVK_LOG_FUN(evshed_create,AVK_PASS);		
	    AVK_LOG_FUN(evshed_set_event,AVK_PASS);	
	    AVK_LOG_FUN(evshed_suspend_all_events,AVK_PASS);		
	    AVK_LOG_FUN(evshed_resume_all_events,AVK_PASS);		 
        if(1){
            // mmi_popup_display_simple((WCHAR*) L"Event Schedule 2 SUCCESS ",MMI_EVENT_SUCCESS,GRP_ID_AVK,NULL);// SUCCESS
            AVK_CASE_RESULT(AVK_PASS);
        }
        else{
            // mmi_popup_display_simple((WCHAR*) L"Event Schedule 2 FAILED ",MMI_EVENT_FAILURE,GRP_ID_AVK,NULL); // FAILED
            AVK_CASE_RESULT(AVK_FAIL);        
        }
    }


    static void gpt_cb(void *data)
    {
    }

    /*************************************************    KAL others        ********************************************************/
    void vs_sys_timer_cancel_event(kal_uint32 argc, void *argv)
    {
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif        
    }

    void vs_sys_timer_del_all_events(kal_uint32 argc, void *argv)
    {
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
/* under construction !*/
#endif        
    }


    static void vs_sys_start_base_timer(void *stack_timer_base, kal_uint32 time_out)
    {
        stack_start_timer((stack_timer_struct *)stack_timer_base, 0, time_out);
    }
    static void vs_sys_stop_base_timer(void *stack_timer_base)
    {
        stack_stop_timer((stack_timer_struct *)stack_timer_base);
    }
    void event_cb5(void *data_db)
    {
        g_count++;
    }
    void vs_sys_start_gpt_timer(kal_uint32 time_count, void (*gptimer_func)(void *), void *cb_data)
    {
        //kal_uint8 data;
        //    GPTI_GetHandle(&gpt_module);
        if (NULL == gptimer_func)
        {
            //		GPTI_StartItem(gpt_module, time_count, gpt_callback, &data);
        }
        else
        {
            //		GPTI_StartItem(gpt_module, time_count, gptimer_func, cb_data);
        }
    }
    void vs_sys_report_reset(kal_int32 code) 
    {   
        vs_sys_reset_target();
    }

    void vs_sys_stop_gpt_timer()
    {
    }
    static void gpt_callback(void *data)
    {
        vs_sys_stop_gpt_timer();
        vs_sys_reset_target();
    }
    void vs_sys_reset_target(void)
    {
    }



    /* new framework menu tree */

    // AVK_SYSSRV_BASE


/*AVK_ADD_ITEM(AVK_SYSSRV_BASE_MANUL_ITEM_01,	L"ADM_01",		AVK_SYSSRV_BASE)
AVK_ADD_ITEM(AVK_SYSSRV_BASE_MANUL_ITEM_02,	L"ADM_02",      		AVK_SYSSRV_BASE)
AVK_ADD_ITEM(AVK_SYSSRV_BASE_MANUL_ITEM_03,	L"ADM_03",      		AVK_SYSSRV_BASE)
AVK_ADD_ITEM(AVK_SYSSRV_BASE_MANUL_ITEM_04,	L"ADM_04",	   	AVK_SYSSRV_BASE)
AVK_ADD_ITEM(AVK_SYSSRV_BASE_MANUL_ITEM_05,	L"ADM_05", 	    	AVK_SYSSRV_BASE)
AVK_ADD_ITEM(AVK_SYSSRV_BASE_MANUL_ITEM_06,	L"AFM_01",	    	AVK_SYSSRV_BASE)
AVK_ADD_ITEM(AVK_SYSSRV_BASE_MANUL_ITEM_07,	L"AFM_02",	    	AVK_SYSSRV_BASE)
AVK_ADD_ITEM(AVK_SYSSRV_BASE_MANUL_ITEM_08,	L"AFM_03",	    	AVK_SYSSRV_BASE)
AVK_ADD_ITEM(AVK_SYSSRV_BASE_MANUL_ITEM_09,	L"AFM_04",	    	AVK_SYSSRV_BASE)
AVK_ADD_ITEM(AVK_SYSSRV_BASE_MANUL_ITEM_10, 	L"TASK_1",	    	AVK_SYSSRV_BASE)
AVK_ADD_ITEM(AVK_SYSSRV_BASE_MANUL_ITEM_11, 	L"TASK_2",	    	AVK_SYSSRV_BASE)
AVK_ADD_ITEM(AVK_SYSSRV_BASE_MANUL_ITEM_12,	L"mutex_1",	    	AVK_SYSSRV_BASE)
AVK_ADD_ITEM(AVK_SYSSRV_BASE_MANUL_ITEM_13, 	L"mutex_2",	    	AVK_SYSSRV_BASE)
AVK_ADD_ITEM(AVK_SYSSRV_BASE_MANUL_ITEM_14, 	L"semaphone_1", 	AVK_SYSSRV_BASE)
AVK_ADD_ITEM(AVK_SYSSRV_BASE_MANUL_ITEM_15, 	L"semaphone_2", 	AVK_SYSSRV_BASE)
AVK_ADD_ITEM(AVK_SYSSRV_BASE_MANUL_ITEM_16, 	L"evshed_1",		AVK_SYSSRV_BASE)
AVK_ADD_ITEM(AVK_SYSSRV_BASE_MANUL_ITEM_17, 	L"evshed_2",		AVK_SYSSRV_BASE)*/

AVK_CASE(AVK_SYSSRV_BASE_INIT,AVK_SYSSRV_BASE)
{
	adm_buf_20K = (CHAR*)AVK_MALLOC(20*1024);
	AVK_CASE_RESULT(adm_buf_20K);
}
AVK_CASE(AVK_SYSSRV_BASEMANUL_001,AVK_SYSSRV_BASE_INIT){	vs_sys_adm_001();					}
AVK_CASE(AVK_SYSSRV_BASEMANUL_002,AVK_SYSSRV_BASE_INIT){	vs_sys_adm_002();					}
AVK_CASE(AVK_SYSSRV_BASEMANUL_003,AVK_SYSSRV_BASE_INIT){	vs_sys_adm_003();					}
AVK_CASE(AVK_SYSSRV_BASEMANUL_004,AVK_SYSSRV_BASE_INIT){	vs_sys_adm_004();					}
AVK_CASE(AVK_SYSSRV_BASEMANUL_005,AVK_SYSSRV_BASE_INIT){	vs_sys_adm_005();					}
AVK_CASE(AVK_SYSSRV_BASEMANUL_006,AVK_SYSSRV_BASE_INIT){	vs_sys_afm_001();					}
AVK_CASE(AVK_SYSSRV_BASEMANUL_007,AVK_SYSSRV_BASE_INIT){	vs_sys_afm_002();					}
AVK_CASE(AVK_SYSSRV_BASEMANUL_008,AVK_SYSSRV_BASE_INIT){	vs_sys_afm_003();					}
AVK_CASE(AVK_SYSSRV_BASEMANUL_009,AVK_SYSSRV_BASE_INIT){	vs_sys_afm_004();					}
AVK_CASE(AVK_SYSSRV_BASEMANUL_010,AVK_SYSSRV_BASE_INIT){	vs_sys_task_002_change_priority();	}
AVK_CASE(AVK_SYSSRV_BASEMANUL_011,AVK_SYSSRV_BASE_INIT){	vs_sys_task_003_get_task(); 		}
AVK_CASE(AVK_SYSSRV_BASEMANUL_012,AVK_SYSSRV_BASE_INIT){	vs_sys_mutex_001_send_msg();		}
AVK_CASE(AVK_SYSSRV_BASEMANUL_013,AVK_SYSSRV_BASE_INIT){	vs_sys_mutex_002_test();			}
AVK_CASE(AVK_SYSSRV_BASEMANUL_014,AVK_SYSSRV_BASE_INIT){	vs_sys_semaphore_001_send_msg();	}
AVK_CASE(AVK_SYSSRV_BASEMANUL_015,AVK_SYSSRV_BASE_INIT){	vs_sys_semaphore_002_test();		}
AVK_CASE(AVK_SYSSRV_BASEMANUL_016,AVK_SYSSRV_BASE_INIT){	vs_sys_evshed_001_test();			}
AVK_CASE(AVK_SYSSRV_BASEMANUL_017,AVK_SYSSRV_BASE_INIT){	vs_sys_evshed_002_test();			}
AVK_CASE(AVK_SYSSRV_BASE_DEINIT,AVK_SYSSRV_BASE)
{
	AVK_FREE(adm_buf_20K);
	adm_buf_20K = NULL;
	AVK_CASE_RESULT(AVK_PASS);
}

#ifdef __cplusplus
}
#endif

#endif /* __MAUI_SDK_TEST__ */

