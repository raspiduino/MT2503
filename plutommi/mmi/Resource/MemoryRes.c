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
 *   MemoryRes.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements memory resource related functions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#include "MMI_features.h"
#include "app_mem.h"
#include "app_mem_config.h"

#ifdef __MTK_TARGET__
#define ALIGN(n) __align(n)  //target alignment
#else
#define ALIGN(n)  __declspec(align(n)) //modis alignment
#endif

/* memory pool */
#ifdef __MTK_TARGET__
#ifdef __DYNAMIC_SWITCH_CACHEABILITY__
#pragma arm section zidata = "DYNAMICCACHEABLEZI_C_MMIPOOL"
#else
#pragma arm section zidata = "LARGEPOOL_FIRST_ZI"
#endif
#endif /* __MTK_TARGET__ */

#if APPLIB_MEM_AP_POOL_ALIGN > 0
/* 
 * There is an ARM ADS issue.
 * 
 * If APPLIB_MEM_AP_POOL_SIZE is 1.2MB and __align(512*1024),
 * the pool g_applib_mem_ap_pool[] will take 1.5MB. 
 *
 * As a result, we do not set __align here. Instead, the alignment
 * is configured in the scatter files.
 *
 * (Note: this issue no longer exists in ARM RVCT)
 */
// __align(APPLIB_MEM_AP_POOL_ALIGN)
#endif

/* Use kal_uint32 to be 4-byte aligned */
#if defined __MMI_USE_MMV2__
    #define AP_ASM_USE_SIZE (APPLIB_MEM_AP_POOL_SIZE + 102400)
    KAL_FLMM_VA_ATTRIBUTE U8 g_applib_mem_ap_va_pool[AP_ASM_USE_SIZE*4]    ;
    KAL_FLMM_PA_ATTRIBUTE U8 g_applib_mem_ap_pool[AP_ASM_USE_SIZE+FLMM_CONFIG_OVERHEAD(AP_ASM_USE_SIZE)]    ;
#else
ALIGN(ASM_ALIGN_SIZE)  U8 g_applib_mem_ap_pool[APPLIB_MEM_AP_POOL_SIZE + 10240];
#endif

U32 mmi_res_get_asm_pool_size()
{
    return sizeof(g_applib_mem_ap_pool);
}

void* mmi_res_get_asm_pool()
{
    return (void*)g_applib_mem_ap_pool;
}

#if defined __MMI_USE_MMV2__
U32 mmi_res_get_asm_pool_va_size()
{
    return sizeof(g_applib_mem_ap_va_pool);
}

void* mmi_res_get_asm_va_pool()
{
    return (void*)g_applib_mem_ap_va_pool;
}


U32 mmi_res_get_asm_pool_size_wo_flmm_overhead()
{
    return sizeof(g_applib_mem_ap_pool) - FLMM_CONFIG_OVERHEAD(AP_ASM_USE_SIZE);
}
#endif

#ifdef __cplusplus
}
#endif
