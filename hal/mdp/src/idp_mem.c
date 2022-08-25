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
 *
 * Project:
 * --------
 *
 * Description:
 * ------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#define THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL

#include "drv_comm.h"
#include "drv_features_mdp.h"

#if defined(DRV_IDP_SUPPORT)
#include "kal_general_types.h"
#include "kal_public_api.h"
#include <idp_mem.h>
#if defined(__MTK_TARGET__)
#include <cache_sw.h>
#include <init.h>
#endif

static idp_mem_struct g_idp_mem;

/* ============================================
 *                  external
 * ============================================ */
void
idp_extmem_init(
  kal_uint8 * const start_ptr,
  kal_uint32 const length,
  char const * const filename,
  kal_uint32 const lineno)
{
  ASSERT(filename != NULL);
   
#if defined(__MTK_TARGET__)
  if (INT_QueryIsNonCachedRAM(start_ptr, length) != 1)
  {
    ASSERT(0);
  }
#endif
  
  g_idp_mem.ext_ram_start_ptr = start_ptr;
  g_idp_mem.ext_ram_total_length = length;
  g_idp_mem.ext_ram_index = 0;
  g_idp_mem.ext_ram_init = KAL_TRUE;
  
  g_idp_mem.ext_ram_filename = filename;
  g_idp_mem.ext_ram_lineno = lineno;
}

/* ============================================
 *                  external ex
 * ============================================ */

void *
idp_extmem_get_buffer_ex(
  idp_mem_struct * const idp_mem,
  kal_uint32 const size,
  idp_mem_align_type const align)
{
  kal_uint8 *ptr;
  kal_uint32 mask;
  
  switch (align)
  {
  case IDP_MEM_ALIGN_TYPE_1_BYTE: mask = 0x0; break;
  case IDP_MEM_ALIGN_TYPE_2_BYTE: mask = 0x1; break;
  case IDP_MEM_ALIGN_TYPE_4_BYTE: mask = 0x3; break;
  case IDP_MEM_ALIGN_TYPE_8_BYTE: mask = 0x7; break;
  case IDP_MEM_ALIGN_TYPE_16_BYTE: mask = 0xf; break;
  case IDP_MEM_ALIGN_TYPE_32_BYTE: mask = 0x1f; break;
  default: ASSERT(0); mask = 0; break;
  }
  
	ptr = (void *)&(*idp_mem).ext_ram_start_ptr[(*idp_mem).ext_ram_index];
  
  ptr += mask;
  ptr = (kal_uint8 *) (((kal_uint32)ptr) & ~mask);
  
  (*idp_mem).ext_ram_index = (ptr - (*idp_mem).ext_ram_start_ptr);
	(*idp_mem).ext_ram_index += size;
  
	if ((*idp_mem).ext_ram_index > (*idp_mem).ext_ram_total_length)
  {
    return NULL;
  }
  
	return ptr;
}

kal_bool
idp_extmem_is_buffer_available_ex(
  idp_mem_struct * const idp_mem,
  kal_uint32 const size,
  idp_mem_align_type const align)
{
  kal_uint8 *ptr;
  kal_uint32 mask;
  
  switch (align)
  {
  case IDP_MEM_ALIGN_TYPE_1_BYTE: mask = 0x0; break;
  case IDP_MEM_ALIGN_TYPE_2_BYTE: mask = 0x1; break;
  case IDP_MEM_ALIGN_TYPE_4_BYTE: mask = 0x3; break;
  case IDP_MEM_ALIGN_TYPE_8_BYTE: mask = 0x7; break;
  case IDP_MEM_ALIGN_TYPE_16_BYTE: mask = 0xf; break;
  case IDP_MEM_ALIGN_TYPE_32_BYTE: mask = 0x1f; break;
  default: ASSERT(0); mask = 0; break;
  }
  
	ptr = (void *)&(*idp_mem).ext_ram_start_ptr[(*idp_mem).ext_ram_index];
  
  ptr += mask;
  ptr = (kal_uint8 *) (((kal_uint32)ptr) & ~mask);
  
  {
    kal_int32 offset = ptr + size - (*idp_mem).ext_ram_start_ptr;
    
    // Make sure I can cast to unsigned int
    ASSERT(0 == (offset & 0x80000000));
    
    if ((kal_uint32)(offset) > (*idp_mem).ext_ram_total_length)
    {
      return KAL_FALSE;
    }
    else
    {
      return KAL_TRUE;
    }
  }
}

void
idp_extmem_deinit_ex(idp_mem_struct * const idp_mem)
{
  (*idp_mem).ext_ram_total_length = 0;
  (*idp_mem).ext_ram_init = KAL_FALSE;
  (*idp_mem).ext_ram_filename = 0;
}

/* ============================================
 *                  external
 * ============================================ */

void *
idp_extmem_get_buffer(
  kal_uint32 const size,
  idp_mem_align_type const align)
{
  return idp_extmem_get_buffer_ex(&g_idp_mem, size, align);
}

kal_bool
idp_extmem_is_buffer_available(
  kal_uint32 const size,
  idp_mem_align_type const align)
{
  return idp_extmem_is_buffer_available_ex(&g_idp_mem, size, align);
}

void
idp_extmem_deinit(void)
{
  idp_extmem_deinit_ex(&g_idp_mem);
}

/* ============================================
 *                  external tmp
 * ============================================ */

void
idp_extmem_init_tmp(idp_mem_struct * const idp_mem)
{
  idp_mem->ext_ram_start_ptr = g_idp_mem.ext_ram_start_ptr;
  idp_mem->ext_ram_total_length = g_idp_mem.ext_ram_total_length;
  idp_mem->ext_ram_index = g_idp_mem.ext_ram_index;
  idp_mem->ext_ram_init = g_idp_mem.ext_ram_init;
  
  idp_mem->ext_ram_filename = g_idp_mem.ext_ram_filename;
  idp_mem->ext_ram_lineno = g_idp_mem.ext_ram_lineno;
}

/* ============================================
 *                  internal ex
 * ============================================ */

void *
idp_intmem_get_buffer_ex(
  idp_mem_struct * const idp_mem,
  kal_uint32 const size,
  idp_mem_align_type const align)
{
  kal_uint8 *ptr;
  kal_uint32 mask;
  
  switch (align)
  {
  case IDP_MEM_ALIGN_TYPE_1_BYTE: mask = 0x0; break;
  case IDP_MEM_ALIGN_TYPE_2_BYTE: mask = 0x1; break;
  case IDP_MEM_ALIGN_TYPE_4_BYTE: mask = 0x3; break;
  case IDP_MEM_ALIGN_TYPE_8_BYTE: mask = 0x7; break;
  case IDP_MEM_ALIGN_TYPE_16_BYTE: mask = 0xf; break;
  case IDP_MEM_ALIGN_TYPE_32_BYTE: mask = 0x1f; break;
  default: ASSERT(0); mask = 0; break;
  }
  
	ptr = (void *)&(*idp_mem).int_ram_start_ptr[(*idp_mem).int_ram_index];
  
  ptr += mask;
  ptr = (kal_uint8 *) (((kal_uint32)ptr) & ~mask);
  
  (*idp_mem).int_ram_index = (ptr - (*idp_mem).int_ram_start_ptr);
	(*idp_mem).int_ram_index += size;
  
	if ((*idp_mem).int_ram_index > (*idp_mem).int_ram_total_length)
  {
    return NULL;
  }
  
	return ptr;
}

kal_bool
idp_intmem_is_buffer_available_ex(
  idp_mem_struct * const idp_mem,
  kal_uint32 const size,
  idp_mem_align_type const align)
{
  kal_uint8 *ptr;
  kal_uint32 mask;
  
  switch (align)
  {
  case IDP_MEM_ALIGN_TYPE_1_BYTE: mask = 0x0; break;
  case IDP_MEM_ALIGN_TYPE_2_BYTE: mask = 0x1; break;
  case IDP_MEM_ALIGN_TYPE_4_BYTE: mask = 0x3; break;
  case IDP_MEM_ALIGN_TYPE_8_BYTE: mask = 0x7; break;
  case IDP_MEM_ALIGN_TYPE_16_BYTE: mask = 0xf; break;
  case IDP_MEM_ALIGN_TYPE_32_BYTE: mask = 0x1f; break;
  default: ASSERT(0); mask = 0; break;
  }
  
	ptr = (void *)&(*idp_mem).int_ram_start_ptr[(*idp_mem).int_ram_index];
  
  ptr += mask;
  ptr = (kal_uint8 *) (((kal_uint32)ptr) & ~mask);
  
  {
    kal_int32 offset = ptr + size - (*idp_mem).int_ram_start_ptr;
    
    // Make sure I can cast to unsigned int
    ASSERT(0 == (offset & 0x80000000));
    
    if ((kal_uint32)(offset) > (*idp_mem).int_ram_total_length)
    {
      return KAL_FALSE;
    }
    else
    {
      return KAL_TRUE;
    }
  }
}

void
idp_intmem_deinit_ex(idp_mem_struct * const idp_mem)
{
  (*idp_mem).int_ram_total_length = 0;
  (*idp_mem).int_ram_init = KAL_FALSE;
  (*idp_mem).int_ram_filename = 0;
}

/* ============================================
 *                  internal
 * ============================================ */

void
idp_intmem_init(
  kal_uint8 * const start_ptr,
  kal_uint32 const length,
  char const * const filename,
  kal_uint32 const lineno)
{
  ASSERT(filename != NULL);
  
#if defined(__MTK_TARGET__)
  if (INT_QueryIsNonCachedRAM(start_ptr, length) != 1)
  {
    ASSERT(0);
  }
#endif
  
  g_idp_mem.int_ram_start_ptr = start_ptr;
  g_idp_mem.int_ram_total_length = length;
  g_idp_mem.int_ram_index = 0;
  g_idp_mem.int_ram_init = KAL_TRUE;
  
  g_idp_mem.int_ram_filename = filename;
  g_idp_mem.int_ram_lineno = lineno;
}

void *
idp_intmem_get_buffer(
  kal_uint32 const size,
  idp_mem_align_type const align)
{
  return idp_intmem_get_buffer_ex(&g_idp_mem, size, align);
}

kal_bool
idp_intmem_is_buffer_available(
  kal_uint32 const size,
  idp_mem_align_type const align)
{
  return idp_intmem_is_buffer_available_ex(&g_idp_mem, size, align);
}

void
idp_intmem_deinit(void)
{
  idp_intmem_deinit_ex(&g_idp_mem);
}

/* ============================================
 *                  internal tmp
 * ============================================ */

void
idp_intmem_init_tmp(idp_mem_struct * const idp_mem)
{
  idp_mem->int_ram_start_ptr = g_idp_mem.int_ram_start_ptr;
  idp_mem->int_ram_total_length = g_idp_mem.int_ram_total_length;
  idp_mem->int_ram_index = g_idp_mem.int_ram_index;
  idp_mem->int_ram_init = g_idp_mem.int_ram_init;
  
  idp_mem->int_ram_filename = g_idp_mem.int_ram_filename;
  idp_mem->int_ram_lineno = g_idp_mem.int_ram_lineno;
}
#endif //#if defined(DRV_IDP_SUPPORT)
