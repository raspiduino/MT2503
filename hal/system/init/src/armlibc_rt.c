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
 *   armlibc_rt.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides runtime support for RVCT31 C library, its safe to 
 *   compile & link this file in ADS12 
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#define CLIB_H /* don't include clib.h */
#include "kal_release.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
#include <string.h>

#include "stack_buff_pool.h"
#include "ctrl_buff_pool.h"
#include "sysconf_statistics.h"
#include <time.h>

/*************************************************************************
* FUNCTION
*  use_clib
*
* DESCRIPTION
*  This function is defined to be referenced in bootarm.obj
*  Some symbols defined here will affect linker behavior so we need linker
*  see them as quick as possible
*
* CALLS
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*  None
*
*************************************************************************/
void use_clib(void)
{
}

/*************************************************************************
* FUNCTION
*  __rt_div0
*
* DESCRIPTION
*  The function handles divide-by-zero exception.
*
* CALLS
*  kal_fatal_error_handler

* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*  None
*
*************************************************************************/
void __rt_div0(void)
{
    kal_fatal_error_handler(KAL_ERROR_DIV_BY_0_FAILED, 0);
}

#undef strtok_r
#undef localtime_r
#undef gmtime_r

#if defined(KAL_ON_OSCAR)
/* for oscar support */

char *strtok_r(char *s1, const char *s2, char **ptr)
{
    return strtok(s1, s2);
}

struct tm *localtime_r(const time_t *timer,
                       struct tm *result)
{
    *result = *localtime(timer);
    return result;
}

#elif defined(__MTK_TARGET__) && !defined(__RVCT__)
/* for ADS1.2 support */

char *strtok_r(char *s1, const char *s2, char **ptr)
{
    return (char *)kal_strtok_r((kal_char *)s1, (const kal_char *)s2, (kal_char **)ptr);
}

struct tm *localtime_r(const time_t *timer,
                       struct tm *result)
{
    *result = *localtime(timer);
    return result;
}

#elif defined(__MTK_TARGET__) && defined(__RVCT__) && (__ARMCC_VERSION / 10000 < 30)
/* for RVCT 2.x */

struct tm *localtime_r(const time_t *timer,
                       struct tm *result)
{
    *result = *localtime(timer);
    return result;
}

#endif /* !KAL_ON_OSCAR */

struct tm *gmtime_r(const time_t *timer,
                    struct tm *result)
{
    return localtime_r(timer, result); /* maintain target consistentency localtime = gmtime */
}

#ifdef KAL_ON_OSCAR
void clib_get_heap_statistics(clib_heap_statistics_struct *pstat)
{
    memset(pstat, 0, sizeof(*pstat));
}
#endif

/* because build system defined __RVCT__ under modis, use __MTK_TARGET__ also */
#ifdef __MTK_TARGET__

#define WEAK_SYMBOL __attribute__((weak))

#ifndef __RVCT__
/* for ADS1.2 support */
void clib_basic_init(void)
{
}
void clib_init(void)
{
}
#else

#ifndef __ARMCC_VERSION
#error "__ARMCC_VERSION not defined by ARMCC"
#endif

#if (__ARMCC_VERSION / 10000) != 31 && (__ARMCC_VERSION / 10000) != 22
#error "only RVCT2.2/RVCT3.1 supported"
#endif

#include <locale.h>
#include <wchar.h>
#include <time.h>
#include <float.h>
#include <signal.h>
#include <rt_sys.h>
#include <rt_misc.h>
#include <rt_fp.h>

#if  __ARMCC_VERSION / 10000 == 31
#pragma import(__use_no_semihosting)
#endif
#pragma import(__use_no_semihosting_swi)
#pragma import(__use_iso8859_ctype)
#pragma import(__use_iso8859_collate)
#pragma import(__use_iso8859_monetary)
#pragma import(__use_iso8859_numeric)
#pragma import(__use_iso8859_locale)
//#pragma import(__use_realtime_heap)
//#pragma import(__use_two_region_memory)
//#pragma import(__use_realtime_division)

/******************************  libspace part *********************************/
struct thread_libspace_mini {
    int errno;
    unsigned int fpstatus;
};
static struct thread_libspace_mini init_libspace;
static struct thread_libspace_mini *tasks_libspace_ptr = &init_libspace;

#pragma arm section code="SHOULD_NOT_USED_FUNCTION"
void *__user_perthread_libspace(void)
{
    return NULL;
}
#pragma arm section

#undef CLIB_THRAEDSAFE_LIBSPACE
#ifndef CLIB_THRAEDSAFE_LIBSPACE
static __inline int _get_threadindex(void)
{
    return 0;
}
#else
/* I won't implement this yet */
#error "c standard library thread safe libspace is not supported yet"
/* the key point to support thread safe errno & switchable floating point 
 * environment is provide a errno/fpstatus for each thread in system
 * so we must has a distinguish thread index for each thread. in my design now:
 *   0: LISR
 *   [1, 1+total_tasks): for each task
 *   [1+total_tasks, 1+total_tasks+total_hisrs): for each HISR
 */
static int _get_threadindex(void)
{
    if (in_lisr) {
        /* all LISR share a C library context */
        return 0;
    }
    if (in_hisr) {
        return 1 + total_tasks + hisr_index;
    }
    return 1 + task_index;
}
#endif

int *__aeabi_errno_addr(void)
{
    int task_index = _get_threadindex();
    return &tasks_libspace_ptr[task_index].errno;
}
int *__rt_errno_addr(void)
{
    return __aeabi_errno_addr();
}
unsigned *__rt_fp_status_addr(void)
{
    int task_index = _get_threadindex();
    return &tasks_libspace_ptr[task_index].fpstatus;
}

/******************************  mutex part **************************************/
int _mutex_initialize(void **ptr_to_mutex)
{
    kal_mutexid mutex;
    
    mutex = kal_create_mutex("clib_mtx");
    *ptr_to_mutex = mutex;
    
    return 1;
}
void _mutex_acquire(void **ptr_to_mutex)
{
    kal_mutexid mutex = *(kal_mutexid *)ptr_to_mutex;
    
    kal_take_mutex(mutex);
}
void _mutex_release(void **ptr_to_mutex)
{
    kal_mutexid mutex = *(kal_mutexid *)ptr_to_mutex;
    
    kal_give_mutex(mutex);
}

/*************************************************************************
* FUNCTION
*  __rt_raise
*
* DESCRIPTION
*  This dummy function is implemented to raise signal
*
* CALLS
*  should_not_execute_function
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*  None
*
*************************************************************************/
void __rt_raise(int signal, int type)
{
    if (signal == SIGFPE) {
        switch (type) {
            case _FPE_OVERFLOW:
            case _FPE_UNDERFLOW:
            case _FPE_INEXACT:
            case _FPE_INVALID:
                return;
            case _FPE_ZERODIVIDE:
                /* default: goto exception handling */
                break;
        }
    }
    kal_fatal_error_handler(KAL_ERROR_SHOULD_NOT_EXECUTE, KAL_ERROR_KAL_SUB_ERROR_CODE2);
}

/*************************************************************************
* FUNCTION
*  _rand_init
*
* DESCRIPTION
*  Default _rand_init will call srand(1) always, because MAUI will call srand(seed) 
*  sooner or later, so overwrite it to do nothing.
*
* CALLS
*  None
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*  None
*
*************************************************************************/
void $Sub$$_rand_init(void)
{
}

/*************************************************************************
* FUNCTION
*  _ttywrch
*
* DESCRIPTION
*  The function write a character to console, just discard it
*
* CALLS
*  None
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*  None
*
*************************************************************************/
void $Sub$$_ttywrch(int ch)
{
    /* discard, nothing to do*/
    return;
}

/*************************************************************************
* FUNCTION
*  _sys_exit
*
* DESCRIPTION
*  The dummy do system exit action, MAUI doesn't support it and fatal. 
*
* CALLS
*  should_not_execute_function
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*  None
*
*************************************************************************/
void $Sub$$_sys_exit(int returncode)
{
    kal_fatal_error_handler(KAL_ERROR_SHOULD_NOT_EXECUTE, KAL_ERROR_KAL_SUB_ERROR_CODE3);
}

/*************************************************************************
* FUNCTION
*  __aeabi_atexit
*
* DESCRIPTION
*  default __aeabi_atexit() will call malloc() to allocate deallocate function node
*  MAUI won't exit so __aeabi_atexit() don't need to save that 
*
* CALLS
*  None
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*  None
*
*************************************************************************/
int $Sub$$__aeabi_atexit(void (*func)(void *), void *arg, void *dso_handle)
{
    return 0;
}
int $Sub$$__cxa_atexit(void (*func)(void *), void *arg, void *dso_handle)
{
    return 0;
}

/******************************  disabled part **********************************/

/*************************************************************************
* FUNCTION
*  __ARM_get_argv
*
* DESCRIPTION
*  This dummy function is implemented to suppress argc,argv processing
*  in standard C library
*
* CALLS
*  None
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*  None
*
*************************************************************************/
__value_in_regs struct __argc_argv $Sub$$__ARM_get_argv(void *reserved)
{
    struct __argc_argv args = { /*argc*/0, /*argv*/NULL, /*r2*/0, /*r3*/0 };
    
    return args;
}


/*************************************************************************
* FUNCTION
*  __user_initial_stackheap
*
* DESCRIPTION
*  This dummy function is implemented to make the linker happy for RVCT. 
*
* CALLS
*  None
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*  None
*
*************************************************************************/
__value_in_regs struct __initial_stackheap 
__user_initial_stackheap(unsigned _R0, unsigned _SP, unsigned _R2, unsigned _SL)
{
    struct __initial_stackheap config;
    
    kal_fatal_error_handler(KAL_ERROR_SHOULD_NOT_EXECUTE, 0);
    
    config.heap_base = _R0;
    config.stack_base = _SP;
    config.heap_limit = _R2;
    config.stack_limit = _SL;
    
    return config;
}

/* C++ library will link this function */
char *getenv(const char * name)
{
    return NULL;
}

clock_t clock(void)
{
    clock_t now;
    
    kal_get_time((kal_uint32 *)&now);
    return now;
}

time_t time(time_t * timer)
{
    kal_fatal_error_handler(KAL_ERROR_SHOULD_NOT_EXECUTE, KAL_ERROR_KAL_SUB_ERROR_CODE4);
    if (timer) {
        *timer = 0;
    }
    return 0;
}

extern char *$Super$$setlocale(int category, const char * locale);
char *$Sub$$setlocale(int category, const char * locale)
{
    return NULL;
}

/* ARM C library for RVCT3.1 build 739 below (fix in 739) has a bug for qsort
 * if your qsort for a 0-element array (nmemb is 0) or the element size is 0
 * qsort should do nothing, but qsort will dead loop in it.
 */
extern void $Super$$qsort(void * base, size_t nmemb, size_t size,
           int (* compar)(const void *, const void *));
void $Sub$$qsort(void * base, size_t nmemb, size_t size,
           int (* compar)(const void *, const void *))
{
    if (nmemb == 0 || size == 0) {
        return;
    }
    $Super$$qsort(base, nmemb, size, compar);
}


/* ARM CPP runtime library for RVCT3.1 build 1021 below (fix in 1021) has 
 *  a bug for __cxa_vec_cctor
 * if it called with constructor = NULL, then it should do nothing, but actually
 *  call 0
 * in ARM EABI, __cxa_vec_cctor has a return type of void * instead of void
 */
/* Disable it now because this source file is not release to customer */
#if 0 && (__ARMCC_VERSION / 10000) == 31 && (__ARMCC_VERSION % 10000) < 1021
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

/*******************************************************************************
tailoring disabled functions
*******************************************************************************/
#pragma arm section code="SHOULD_NOT_USED_FUNCTION"
#pragma diag_suppress 940 /* ignore all 'missing return statement at end of non-void function' warning */

#define NOTSUPPORT_FUNCTION
#define INIT_NOTSUPPORT_FUNCTION
#define LINKTIME_CHECKING {}
#define WANT_CLIB_LIST
#include "clib_list.h"

#pragma diag_default 940
#pragma arm section code

extern int clib_init_heap(void) __attribute__((weak));
extern int clib_init_io(void) __attribute__((weak));
/******************************* initlialize **********************************/
/* ??? If __user_initial_stackheap is not referenced, linking may fail with 
 *     very low possibility. Maybe it's toolchain's potential bug.
 *     import __user_initial_stackheap to workaround */
#pragma import(__user_initial_stackheap)
/* import __user_perproc_libspace && __user_libspace to resolve the weak reference
 *     of __user_perproc_libspace in RVCT3.1/569 C library helper function 
 *     __rt_locale.
 */
#pragma import(__user_perproc_libspace)
#pragma import(__user_libspace)

void clib_basic_init(void)
{   
    $Super$$setlocale(LC_ALL, "");
#ifndef __ARM_FPUV2__
    _fp_init();
#endif
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 
void clib_init(void)
{
    // KALTotalTasks is not set yet, don't use it
#ifdef CLIB_THRAEDSAFE_LIBSPACE
    kal_uint32 total_threads;
    
    total_threads = 1/* for LISR */ + total_tasks + total_hisrs;
    tasks_libspace_ptr = (struct thread_libspace_mini *)kal_sys_mem_alloc(total_threads * sizeof(struct thread_libspace_mini));
    if (tasks_libspace_ptr == NULL) {
        EXT_ASSERT(0, 0, 0, 0);
    }
    memset(task_libspace_ptr, 0, sizeof(total_threads * sizeof(struct thread_libspace_mini)));
#endif

    if (clib_init_heap) {
        clib_init_heap();
    }
    if (clib_init_io) {
        clib_init_io();
    }
    __rt_lib_init(0, 0);
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

#endif /* __RVCT__ */

/*******************************************************************************
tailoring heap functions
*******************************************************************************/
/* go into armlibc_rt_heap.c for weak reference
 * 1. if any function define in armlibc_rt_heap.c (malloc/calloc/free/realloc) used
 *    then clib_init_heap is defined & has non NULL value, then clib_init_heap 
 *    get called to initialize heap
 * 2. else, armlibc_rt_heap.c won't linked into MAUI, and clib_init_heap is zero
 */
extern kal_uint32 sysheap_curused WEAK_SYMBOL;
extern kal_uint32 sysheap_maxused WEAK_SYMBOL;
extern kal_uint32 sysheap_alloc WEAK_SYMBOL;
extern kal_uint32 sysheap_allocfailed WEAK_SYMBOL;
extern kal_uint32 sysheap_free WEAK_SYMBOL;
extern kal_uint32 sysheap_configsize WEAK_SYMBOL;

void clib_get_heap_statistics(clib_heap_statistics_struct *pstat)
{
    memset(pstat, 0, sizeof(*pstat));
    if (&sysheap_curused) {
        pstat->curr_alloc_mem = sysheap_curused;
    }
    if (&sysheap_maxused) {
        pstat->max_alloc_mem = sysheap_maxused;
    }
    if (&sysheap_alloc) {
        pstat->alloc_count = sysheap_alloc;
    }
    if (&sysheap_allocfailed) {
        pstat->alloc_fail_count = sysheap_allocfailed;
    }
    if (&sysheap_configsize) {
        pstat->config_size = sysheap_configsize;
    }
} 

#endif /* __MTK_TARGET__ */

