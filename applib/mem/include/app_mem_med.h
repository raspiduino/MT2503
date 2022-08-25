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
 *  app_mem_med.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Public interface of ASM (application-shared memory) for MED.
 *  do not put or include MMI related in this file.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __APP_MEM_MED_H__
#define __APP_MEM_MED_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "kal_general_types.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#undef FILE_PATH_VALUE
#ifdef __32_32_SEG__
#define FILE_PATH_VALUE   NULL
#else
#define FILE_PATH_VALUE   __FILE__
#endif


/***************************************************************************** 
* Typedef 
*****************************************************************************/
#ifdef __MED_IN_ASM__
/* free callback type of cache mem. */
typedef void (*applib_mem_cache_free_cb_type)(void *mem_ptr);
#endif

/***************************************************************************** 
* Export Functions 
*****************************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */
#if !defined __ASM_ALLOC_FLAG_ENUM__
#define __ASM_ALLOC_FLAG_ENUM__
typedef enum
{
    ASM_ALLOC_DEFAULT_FLAG = 0,     /* default value : return cacheable memory*/
    ASM_ALLOC_IS_FB_FLAG = (1<<0),  /* framebuffer usage : return non-cacheable (and continuous if defined __MMI_USE_MMV2__ )memory*/
    ASM_ALLOC_IS_SW_FLAG = (1<<1),  /* for SW usage, cacheable (and non-continuous if defined __MMI_USE_MMV2__ )memory*/
    ASM_ALLOC_IS_TOP_FLAG = (1<<2)   /* Usually for HW usge(framebuffer usage), force allocate from top address side. provide a flexiblilty to fine-tune external fragment issue*/
} asm_alloc_flag;
#endif
#ifdef __MED_IN_ASM__
extern void *applib_mem_ap_cache_alloc_int(kal_uint32 mem_size, asm_alloc_flag alloc_flag, applib_mem_cache_free_cb_type free_cb, kal_char *file, kal_uint32 line);
extern void applib_mem_ap_cache_free_int(void *mem_ptr, kal_char *file, kal_uint32 line);
extern kal_bool applib_mem_ap_cache_free_till_enough_int(kal_uint32 size, kal_bool is_continuous, kal_char *file, kal_uint32 line);
extern kal_bool applib_mem_ap_cache_set_priority(void *mem_ptr, kal_uint32 cache_priority);
#endif
extern void *mmi_frm_asm_alloc_int(kal_uint16 id, kal_uint32 size, asm_alloc_flag alloc_flag, kal_char* file, kal_uint32 line);
extern void mmi_frm_asm_free_int(kal_uint16 id, void *ptr, kal_char* file, kal_uint32 line);
extern void *mmi_frm_asm_alloc_anonymous_int(kal_uint32 size, asm_alloc_flag alloc_flag, kal_char* file, kal_uint32 line);
extern void mmi_frm_asm_free_anonymous_int(void *ptr, kal_char* file, kal_uint32 line);
extern kal_uint32 mmi_frm_asm_get_max_alloc_anonymous(void);

/* anonymous access */
#define applib_asm_alloc_anonymous(_size)      mmi_frm_asm_alloc_anonymous_int(_size, ASM_ALLOC_DEFAULT_FLAG, FILE_PATH_VALUE, __LINE__)
#define applib_asm_alloc_anonymous_nc(_size)      mmi_frm_asm_alloc_anonymous_int(_size, ASM_ALLOC_IS_FB_FLAG, FILE_PATH_VALUE, __LINE__)
#define applib_asm_alloc_anonymous_sw(_size)      mmi_frm_asm_alloc_anonymous_int(_size, ASM_ALLOC_IS_SW_FLAG, FILE_PATH_VALUE, __LINE__)
#define applib_asm_free_anonymous(_mem_ptr)    mmi_frm_asm_free_anonymous_int(_mem_ptr, FILE_PATH_VALUE, __LINE__)
#define applib_asm_get_max_alloc_anonymous()    mmi_frm_asm_get_max_alloc_anonymous()

/* DOM-NOT_FOR_SDK-END */

#define applib_asm_alloc_r(_id, _size)   mmi_frm_asm_alloc_int(_id, _size, ASM_ALLOC_DEFAULT_FLAG, FILE_PATH_VALUE, __LINE__)

#define applib_asm_alloc_sw_r(_id, _size)   mmi_frm_asm_alloc_int(_id, _size, ASM_ALLOC_IS_SW_FLAG, FILE_PATH_VALUE, __LINE__)

#define applib_asm_alloc_sw_r_dbg(_id, _size,  _f, _l)   mmi_frm_asm_alloc_int(_id, _size, ASM_ALLOC_IS_SW_FLAG, _f, _l)

#define applib_asm_alloc_nc_r(_id, _size)   mmi_frm_asm_alloc_int(_id, _size, ASM_ALLOC_IS_FB_FLAG, FILE_PATH_VALUE, __LINE__)

#define applib_asm_free_r(_id, _mem_ptr)  mmi_frm_asm_free_int(_id, _mem_ptr, FILE_PATH_VALUE, __LINE__)

#define applib_asm_alloc_r_dbg(_id, _size, file, line)   mmi_frm_asm_alloc_int(_id, _size, ASM_ALLOC_DEFAULT_FLAG, file, line)

#define applib_asm_alloc_nc_r_dbg(_id, _size, file, line)   mmi_frm_asm_alloc_int(_id, _size, ASM_ALLOC_IS_FB_FLAG, file, line)

#define applib_asm_free_r_dbg(_id, _mem_ptr, file, line)  mmi_frm_asm_free_int(_id, _mem_ptr, file, line)

#define applib_mem_ap_cache_alloc(_size, _free_cb) applib_mem_ap_cache_alloc_int(_size, ASM_ALLOC_DEFAULT_FLAG, _free_cb,  FILE_PATH_VALUE, __LINE__)

#define applib_mem_ap_cache_alloc_dbg(_size, _free_cb, _f, _l) applib_mem_ap_cache_alloc_int(_size, ASM_ALLOC_DEFAULT_FLAG, _free_cb, _f, _l)

#define applib_mem_ap_cache_alloc_sw(_size, _free_cb) applib_mem_ap_cache_alloc_int(_size, ASM_ALLOC_IS_SW_FLAG, _free_cb,  FILE_PATH_VALUE, __LINE__)

#define applib_mem_ap_cache_alloc_sw_dbg(_size, _free_cb, _f, _l) applib_mem_ap_cache_alloc_int(_size, ASM_ALLOC_IS_SW_FLAG, _free_cb, _f, _l)

#define applib_mem_ap_cache_alloc_nc(_size, _free_cb) applib_mem_ap_cache_alloc_int(_size, ASM_ALLOC_IS_FB_FLAG, _free_cb,  FILE_PATH_VALUE, __LINE__)

#define applib_mem_ap_cache_alloc_nc_dbg(_size, _free_cb, _f, _l) applib_mem_ap_cache_alloc_int(_size, ASM_ALLOC_IS_FB_FLAG, _free_cb,  _f, _l)

#define applib_mem_ap_cache_free(_mem_ptr)  applib_mem_ap_cache_free_int(_mem_ptr, FILE_PATH_VALUE, __LINE__)

#define applib_mem_ap_cache_free_dbg(_mem_ptr, _f, _l)  applib_mem_ap_cache_free_int(_mem_ptr, _f, _l)

#ifdef __cplusplus
}   /* extern "C" { */
#endif

#endif /* __APP_MEM_MED_H__ */ 

