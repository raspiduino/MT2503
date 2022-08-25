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
 *   armlibc_rt_heap.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides runtime support for RVCT31 C library heap functionality
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
  
#if defined(__RVCT__) && defined(__MTK_TARGET__)

#define CLIB_H /* don't include clib.h */
#include "kal_release.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
#include <string.h>

#define WEAK_SYMBOL __attribute__((weak))

extern void *kal_sys_mem_alloc(kal_uint32 size);
extern void custom_config_libc_heap(kal_uint32 *heap_size, void **heap_addr);

/* sysheap adm will use ADM logging facility to save memory
 * but we still use a lr to track where it was allocate 
 */
static KAL_ADM_ID sysheap_admid;
static kal_mutexid sysheap_mutex;
static __inline void sysheap_lock(void)
{
    if (kal_query_systemInit() == KAL_FALSE) {
        kal_take_mutex(sysheap_mutex);
    }
}
static __inline void sysheap_unlock(void)
{
    if (kal_query_systemInit() == KAL_FALSE) {
        kal_give_mutex(sysheap_mutex);
    }
}

#define KAL_SYSHEAP_STAT
#ifdef KAL_SYSHEAP_STAT
kal_uint32 sysheap_curused;
kal_uint32 sysheap_maxused;
kal_uint32 sysheap_alloc;
kal_uint32 sysheap_allocfailed;
kal_uint32 sysheap_free;
kal_uint32 sysheap_configsize;
#define SYSHEAPSTAT_INC(v) ((void)(++v))
static __inline void sysheapstat_add_alloc(kal_uint32 size) 
{
    kal_uint32 newused = (sysheap_curused += size);
    if (newused > sysheap_maxused) {
        sysheap_maxused = newused;
    }
}
static __inline void sysheapstat_sub_alloc(kal_uint32 size)
{
    sysheap_curused -= size;
}
#else 
#define SYSHEAPSTAT_INC(v) ((void)0)
#define sysheapstat_add_alloc(size) ((void)0)
#define sysheapstat_sub_alloc(size) ((void)0)
#endif

struct sysheap_mb {
    kal_uint32 size;
    unsigned long lr;
    char user[4];
};
/* SYSHEAPMB_HEADERSIZE = user field offset in struct */
#define SYSHEAPMB_HEADERSIZE ((int)(&((struct sysheap_mb *)0)->user))

kal_uint32 kal_adm_internal_usersize(KAL_ADM_ID adm_id, void *mem_addr);

static void *__smalloc(size_t size, unsigned long lr) 
{
    struct sysheap_mb *pb;
    
    size = (size + 3) & ~3; 
    
    sysheap_lock();
    pb = kal_adm_alloc(sysheap_admid, size + SYSHEAPMB_HEADERSIZE);
    sysheap_unlock();
    
    SYSHEAPSTAT_INC(sysheap_alloc);
    if (pb == NULL) {
        SYSHEAPSTAT_INC(sysheap_allocfailed);
        return NULL;
    }
    sysheapstat_add_alloc(size);
    
    pb->lr = lr;
    pb->size = size;
    return (void *)pb->user;
}

void *malloc(size_t size)
{
#pragma import(clib_init_heap)
    if (sysheap_admid == NULL) {
        kal_fatal_error_handler(KAL_ERROR_SHOULD_NOT_EXECUTE, KAL_ERROR_KAL_SUB_ERROR_CODE5);
    }
    
    return __smalloc(size, __return_address());
}

void *calloc(size_t nmemb, size_t size)
{
#pragma import(clib_init_heap)
    size_t total = nmemb * size;
    void *ptr;
    
    if (sysheap_admid == NULL) {
        kal_fatal_error_handler(KAL_ERROR_SHOULD_NOT_EXECUTE, KAL_ERROR_KAL_SUB_ERROR_CODE6);
    }
    
    ptr = __smalloc(total, __return_address());
    if (ptr) {
        memset(ptr, 0, total);
    }
    return ptr;
}

static void __sfree(void *ptr)
{
    struct sysheap_mb *pb;
    
    pb = (struct sysheap_mb *)((char *)ptr - SYSHEAPMB_HEADERSIZE);
    pb->lr ^= 0xDEADAAAA; /* save a flag to say it's already free */
    
    sysheapstat_sub_alloc(pb->size);
    
    sysheap_lock();
    kal_adm_free(sysheap_admid, pb);
    sysheap_unlock();
    
    SYSHEAPSTAT_INC(sysheap_free);
}

void free(void * ptr)
{
#pragma import(clib_init_heap)
    if (ptr == NULL) {
        return;
    }
    if (sysheap_admid == NULL) {
        kal_fatal_error_handler(KAL_ERROR_SHOULD_NOT_EXECUTE, KAL_ERROR_KAL_SUB_ERROR_CODE7);
    }
    
    __sfree(ptr);
}

void *realloc(void * ptr, size_t size)
{
#pragma import(clib_init_heap)
    struct sysheap_mb *old_pb, *pb;
    kal_uint32 old_size;
    
    if (sysheap_admid == NULL) {
        kal_fatal_error_handler(KAL_ERROR_SHOULD_NOT_EXECUTE, KAL_ERROR_KAL_SUB_ERROR_CODE8);
    }
    
    if (size == 0) {
        if (ptr) {
            __sfree(ptr);
        }
        return NULL;
    }
    if (ptr == NULL) {
        return __smalloc(size, __return_address());
    }
    
    old_pb = (struct sysheap_mb *)((char *)ptr - SYSHEAPMB_HEADERSIZE);
    old_size = old_pb->size;
    
    size = (size + 3) & ~3; // 4-Byte align
    
    sysheap_lock();
    pb = kal_adm_realloc(sysheap_admid, ptr, size + SYSHEAPMB_HEADERSIZE);
    sysheap_unlock();
    
    SYSHEAPSTAT_INC(sysheap_alloc);
    if (pb == NULL) {
        SYSHEAPSTAT_INC(sysheap_allocfailed);
        return NULL;
    }
    
    /* pessimistic: first count the new size, then subtract old size */
    sysheapstat_add_alloc(size);
    sysheapstat_sub_alloc(old_size);
    
    pb->lr = __return_address();
    pb->size = size;
    return (void *)pb->user;
}

extern int __cpp_initialize__aeabi_ WEAK_SYMBOL;
static int has_cxx_rt(void)
{
    if (&__cpp_initialize__aeabi_) {
        return 1;
    }
    return 0;
}

int clib_init_heap(void)
{
    void *heap_addr;
    kal_uint32 heap_size;
    
    custom_config_libc_heap(&heap_size, &heap_addr);
    if (heap_size == 0 && has_cxx_rt()) {
        heap_size = 2048;
        heap_addr = kal_sys_mem_alloc(heap_size);
        if (heap_addr == NULL) {
            kal_fatal_error_handler(KAL_ERROR_MEMMNGT_BUFFER_OVERRUN, heap_size);
        }
    }
    if (heap_size) {
        sysheap_admid = kal_adm_create(heap_addr, heap_size, NULL/*subpool_size*/, KAL_FALSE/*islogging*/);
        if (sysheap_admid == NULL) {
            kal_fatal_error_handler(KAL_ERROR_MEMMNGT_BUFFER_OVERRUN, heap_size);
        }
        sysheap_mutex = kal_create_mutex("sysheap");
    }
    sysheap_configsize = heap_size;
    
    return 0;
}

#pragma arm section code = "SHOULD_NOT_USED_FUNCTION"
unsigned __rt_heap_extend(int ignore,
                            void ** base,
                            unsigned requestedsize)
{    
    return 0;
}
#pragma arm section code

#endif /* __MTK_TARGET__ && __RVCT__ */
