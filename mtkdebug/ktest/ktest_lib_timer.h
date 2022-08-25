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
 *   ktest_lib_timer.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  Timer test case library interface
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
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __KTEST__
 
#ifndef KTEST_LIB_TIMER_H
#define KTEST_LIB_TIMER_H

#include "ktest_common.h"
#include "stack_timer.h"

/*should be included together*/
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "stack_types.h"
#include "task_config.h"

#include "stacklib.h"         /* Basic type for dll, evshed, stacktimer */
#include "stdlib.h"
#include "event_shed.h"
#include "kal_release.h"

#if defined(KAL_ON_NUCLEUS)
#include "tm_defs.h"
#elif defined(KAL_ON_THREADX)
#include "tx_timer.h"
#elif defined(KAL_ON_OSCAR)
#include "osc_type.h"
#endif

//#define KTEST_DEBUG

typedef struct {
    kal_uint32 save_time;
    kal_uint32 delay_tick;
}cb_time_s;
#define KTEST_TIMER_NUM 3
extern cb_time_s   global_cb_array[KTEST_TIMER_NUM];
extern void ktest_init_timer_cb(cb_time_s *, kal_uint32);

extern volatile kal_int32 ktest_timer_g_count;

extern kal_uint32 compare_time_error(kal_uint32, kal_uint32, kal_uint32);

extern kal_taskid ktest_create_task_timeslice(kal_char* task_name, kal_uint8 priority,
                           kal_uint32 stack_size, kal_task_func_ptr entry_func,
                           void *entry_param, kal_uint32 time_slice);

extern kal_timerid create_set_timer(kal_timer_func_ptr handler_func_ptr,
                   void *handler_param_ptr, kal_uint32 delay);

extern kal_bool ktest_set_aligned_timer(kal_timerid timer, kal_uint8 max_delay);

extern void event_cb4(void * cb_data);
extern void ktest_timer_event_cb5(void *data_db);
extern void ktest_timer_event_cb7(void *data_db);

extern void ktest_timer_cb_timeout_fail(void *cb_data);
extern void ktest_sys_mem_free(kal_uint32 size);


#endif /*KTEST_LIB_TIMER_H*/
#endif  /*__KTEST__*/

