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
 *   kal_vm.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This header file define MTK intrnal APIs for in-house user.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VM_H__
#define __VM_H__

#include "kal_public_api.h"
#ifdef __MTK_TARGET__
#include "custom_scatstruct.h"
#endif

#if defined(__MTK_TARGET__) && defined(__KAL_STACK_ISOLATION__)
#ifdef __ARM9_MMU__
#define KAL_VM_STACK_PAGESIZE 1024
#else //!__ARM9_MMU__
#define KAL_VM_STACK_PAGESIZE 4096
#endif //__ARM9_MMU__
#define KAL_VM_STACK_UPALIGN(x) ( ((x) + KAL_VM_STACK_PAGESIZE - 1) / KAL_VM_STACK_PAGESIZE * KAL_VM_STACK_PAGESIZE)
#define KAL_VM_STACK_ALIGNED(x) ( (x) & ~(KAL_VM_STACK_PAGESIZE - 1) == 0 )
#define kal_vm_stack_begin() (custom_get_FLMM_STACKSPACE_Base())
#define kal_vm_stack_end()   (custom_get_FLMM_STACKSPACE_End())
#endif  // __KAL_STACK_ISOLATION__

#ifdef __KAL_VM__

#ifdef __MTK_TARGET__
static __inline kal_uint32 kal_vm_flmm_begin(void)
{
    return (kal_uint32)custom_get_FLMM_VASPACE_Base();
}
static __inline kal_uint32 kal_vm_flmm_end(void)
{
    return (kal_uint32)custom_get_FLMM_VASPACE_End();
}
static __inline kal_uint32 kal_pa_flmm_begin(void)
{
    return (kal_uint32)custom_get_FLMM_PASPACE_Base();
}
static __inline kal_uint32 kal_pa_flmm_end(void)
{
    return (kal_uint32)custom_get_FLMM_PASPACE_End();
}

static __inline kal_bool is_flmm_pa(kal_uint32 addr)
{
    return (addr >= kal_pa_flmm_begin()) && (addr < kal_pa_flmm_end()) ? KAL_TRUE : KAL_FALSE;
}
static __inline kal_bool is_flmm_va(kal_uint32 addr)
{
    return (addr >= kal_vm_flmm_begin()) && (addr < kal_vm_flmm_end()) ? KAL_TRUE : KAL_FALSE;
}

#endif /* __MTK_TARGET__ */

/*******************************************************************************
 * SLMM APIs
 ******************************************************************************/

#define KAL_SLMM_LIMIT_E_OVERQUOTA ((kal_uint32)-33)
#define KAL_SLMM_LIMIT_E_OOPM      ((kal_uint32)-34)

// following APIs are in kal_public_api.h also
KAL_SLMM_ID kal_create_slmm(KAL_FLMM_ID flmm_id, kal_uint32 size, kal_uint32 flags);
void *__kal_slmm_alloc(KAL_SLMM_ID slmm_id, kal_uint32 size, kal_uint32 option, kal_int32 *errcode, kal_char *filename, kal_int32 lineno);
#define kal_slmm_alloc(slmm_id, size, option, errcode) __kal_slmm_alloc((slmm_id), (size), (option), (errcode), __FILE__, __LINE__)
#define kal_slmm_alloc_dbg(slmm_id, size, option, errcode, filename, lineno) __kal_slmm_alloc((slmm_id), (size), (option), (errcode), (filename), (lineno))
void kal_slmm_free(KAL_SLMM_ID slmm_id, void *ptr);
kal_status kal_slmm_delete(KAL_SLMM_ID slmm_id);
kal_uint32 kal_slmm_vm_start(KAL_SLMM_ID slmm_id);
kal_uint32 kal_slmm_vm_end(KAL_SLMM_ID slmm_id);

kal_int32 kal_slmm_limit(KAL_SLMM_ID slmm_id, kal_uint32 size);
kal_uint32 kal_slmm_get_alloc_count(KAL_SLMM_ID slmm_id);
kal_uint32 kal_slmm_get_total_left_size(KAL_SLMM_ID slmm_id);
kal_uint32 kal_slmm_get_max_alloc_size(KAL_SLMM_ID slmm_id);
kal_uint32 kal_slmm_get_committed_size(KAL_SLMM_ID slmm_id);
typedef kal_bool (*kal_slmm_visitor)(KAL_SLMM_ID slmm_id, kal_vm_meminfo_t *info, void *ptr, void *userdata);
void kal_slmm_traverse(KAL_SLMM_ID slmm_id, kal_uint32 flags, kal_slmm_visitor visitor, void *userdata);
void *kal_slmm_check_integrity(KAL_SLMM_ID slmm_id);

/*******************************************************************************
 * FLMM APIs
 ******************************************************************************/
KAL_FLMM_ID kal_create_flmm(void *va_begin, kal_uint32 va_size, 
    void *pa_begin, kal_uint32 pa_usersize, kal_uint32 pa_oversize, kal_uint32 flags);

void *__kal_flmm_alloc(KAL_FLMM_ID flmm_id, kal_uint32 vsize, kal_uint32 plimits, kal_uint32 option, kal_int32 *errcode, kal_char *filename, kal_int32 lineno);
/*void *kal_flmm_alloc(KAL_FLMM_ID flmm_id, kal_uint32 vsize, kal_uint32 option);*/
#define kal_flmm_alloc(flmm_id, vsize, option, errcode) __kal_flmm_alloc((flmm_id), (vsize), 0, (option), (errcode), __FILE__, __LINE__)
/*void *kal_flmm_alloc_dbg(KAL_FLMM_ID flmm_id, kal_uint32 vsize, kal_uint32 option, kal_char *filename, kal_int32 lineno);*/
#define kal_flmm_alloc_dbg(flmm_id, vsize, option, errcode, filename, lineno) __kal_flmm_alloc((flmm_id), (vsize), 0, (option), (errcode), filename, lineno)
kal_int32 kal_flmm_free(KAL_FLMM_ID flmm_id, void *ptr);

void *kal_flmm_lock_mem(KAL_FLMM_ID flmm_id, void *ptr, kal_uint32 size);
void *kal_flmm_unlock_mem(KAL_FLMM_ID flmm_id, void *ptr, kal_uint32 size);


kal_uint32 kal_flmm_vm_start(KAL_FLMM_ID flmm_id);
kal_uint32 kal_flmm_vm_end(KAL_FLMM_ID flmm_id);
kal_uint32 kal_flmm_pm_start(KAL_FLMM_ID flmm_id);
kal_uint32 kal_flmm_pm_end(KAL_FLMM_ID flmm_id);
kal_uint32 kal_flmm_get_total_left_size(KAL_FLMM_ID flmm_id);
kal_uint32 kal_flmm_get_max_alloc_size(KAL_FLMM_ID flmm_id);
kal_bool kal_flmm_is_allocatable(KAL_FLMM_ID flmm_id, kal_uint32 size, kal_uint32 flags);
typedef kal_bool (*kal_flmm_visitor)(KAL_FLMM_ID flmm_id, kal_vm_meminfo_t *info, void *ptr, void *userdata);
void kal_flmm_traverse(KAL_FLMM_ID flmm_id, kal_uint32 flags, kal_flmm_visitor visitor, void *userdata);
void *kal_flmm_check_integrity(KAL_FLMM_ID flmm_id);

#ifdef __MTK_TARGET__
#define KAL_FLMM_VA_ATTRIBUTE __attribute__((section("FLMM_VASPACE"), aligned(1*1024*1024), zero_init))
#define KAL_FLMM_PA_ATTRIBUTE __attribute__((section("FLMM_PASPACE"), aligned(4*1024), zero_init))
#else
#define KAL_FLMM_VA_ATTRIBUTE __declspec(align(4096)) // windows platform only support 8192 alignment
#define KAL_FLMM_PA_ATTRIBUTE __declspec(align(4096))
#endif

#define UINT32S_FOR_BITMAP(x) ( ((x) + 31) / 32 )

#define STRUCT_FLMM_CB_SIZE 272
#define STRUCT_FLMM_PAGE_SIZE 4
#define STRUCT_FLMM_BLOCK_SIZE 32

#define _FLMM_CONFIG_HEAD_OVERHEAD(pa_pages) \
          KAL_VM_PAGE_UPALIGN( STRUCT_FLMM_CB_SIZE + \
            (pa_pages) * STRUCT_FLMM_PAGE_SIZE + \
            KAL_VM_PAGESIZE /* FOR sub free list */ + \
            STRUCT_FLMM_BLOCK_SIZE )
#define _FLMM_CONFIG_FOOT_OVERHEAD(pa_pages) \
          KAL_VM_PAGE_UPALIGN( STRUCT_FLMM_BLOCK_SIZE + \
            UINT32S_FOR_BITMAP(pa_pages)*4 + \
            (1+UINT32S_FOR_BITMAP(UINT32S_FOR_BITMAP(pa_pages)))*4 )
#define _FLMM_CONFIG_MMU_OVERHEAD(va_size) KAL_VM_PAGE_UPALIGN( (va_size) / 1024 )

#define FLMM_CONFIG_NEWOVERHEAD(pa_size, va_size) \
                                    (_FLMM_CONFIG_HEAD_OVERHEAD((pa_size) / KAL_VM_PAGESIZE) + \
                                     _FLMM_CONFIG_FOOT_OVERHEAD((pa_size) / KAL_VM_PAGESIZE) + \
                                     _FLMM_CONFIG_MMU_OVERHEAD(va_size))
#define FLMM_CONFIG_OVERHEAD(pa_size) FLMM_CONFIG_NEWOVERHEAD((pa_size), (pa_size)*4)

#ifdef __MTK_TARGET__
/*******************************************************************************
 * Cache Internal API 
 ******************************************************************************/
 struct slmm_cb;
kal_uint32 flmm_dynamic_switch_cacheable_region(void **addr, kal_uint32 len, kal_uint32 cacheable);
kal_uint32 flmm_virt_to_phys(void *addr);
kal_uint32 flmm_phys_to_virt(void *addr);

kal_int32 flmm_clean_dcache(kal_uint32 addr, kal_uint32 len);
kal_int32 flmm_invalidate_dcache(kal_uint32 addr, kal_uint32 len);
kal_int32 flmm_clean_and_invalidate_dcache(kal_uint32 addr, kal_uint32 len);

kal_uint32 slmm_virt_to_phys(struct slmm_cb *slmm_cb, void *addr);

/*******************************************************************************
 * pagefault handler
 ******************************************************************************/
kal_int32 kal_vm_pagefault(kal_uint32 error_code, kal_uint32 addr, kal_uint32 fsr);
#endif /* __MTK_TARGET__ */

#endif /* __KAL_VM__ */

#endif /* __VM_H__ */
