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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_mem_h__
#define __idp_mem_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include "drv_features_mdp.h"

#if defined(DRV_IDP_SUPPORT)
#include "kal_general_types.h"
#include <idp_core.h>

typedef enum
{
  IDP_MEM_ALIGN_TYPE_1_BYTE,
  IDP_MEM_ALIGN_TYPE_2_BYTE,
  IDP_MEM_ALIGN_TYPE_4_BYTE,
  IDP_MEM_ALIGN_TYPE_8_BYTE,
  IDP_MEM_ALIGN_TYPE_16_BYTE,
  IDP_MEM_ALIGN_TYPE_32_BYTE
} idp_mem_align_type;

typedef struct
{
  kal_bool      ext_ram_init;
  kal_uint8    *ext_ram_start_ptr;
  kal_uint32    ext_ram_total_length;
  kal_uint32    ext_ram_index;
  char    const *ext_ram_filename;
  unsigned int  ext_ram_lineno;
  
  kal_bool      int_ram_init;
  kal_uint8    *int_ram_start_ptr;
  kal_uint32    int_ram_total_length;
  kal_uint32    int_ram_index;
  char   const *int_ram_filename;
  unsigned int  int_ram_lineno;
} idp_mem_struct;

#define IDP_EXTMEM_INIT(start_ptr, length)                  \
  do                                                        \
  {                                                         \
    idp_extmem_init(start_ptr, length, __FILE__, __LINE__); \
  } while(0)

#define IDP_INTMEM_INIT(start_ptr, length)                  \
  do                                                        \
  {                                                         \
    idp_intmem_init(start_ptr, length, __FILE__, __LINE__); \
  } while(0)

extern void idp_extmem_init(
  kal_uint8 * const start_ptr,
  kal_uint32 const length,
  char const * const filename,
  kal_uint32 const lineno);

extern void idp_extmem_init_tmp(idp_mem_struct * const idp_mem);

extern void *idp_extmem_get_buffer_ex(
  idp_mem_struct * const idp_mem,
  kal_uint32 const size,
  idp_mem_align_type const align);

extern void *idp_extmem_get_buffer(
  kal_uint32 const size,
  idp_mem_align_type const align);

extern kal_bool idp_extmem_is_buffer_available_ex(
  idp_mem_struct * const idp_mem,
  kal_uint32 const size,
  idp_mem_align_type const align);

extern kal_bool idp_extmem_is_buffer_available(
  kal_uint32 const size,
  idp_mem_align_type const align);

extern void idp_extmem_deinit_ex(idp_mem_struct * const idp_mem);

extern void idp_extmem_deinit(void);

extern void idp_intmem_init(
  kal_uint8 * const start_ptr,
  kal_uint32 const length,
  char const * const filename,
  kal_uint32 const lineno);

extern void idp_intmem_init_tmp(idp_mem_struct * const idp_mem);

extern void *idp_intmem_get_buffer_ex(
  idp_mem_struct * const idp_mem,
  kal_uint32 const size,
  idp_mem_align_type const align);

extern void *idp_intmem_get_buffer(
  kal_uint32 const size,
  idp_mem_align_type const align);

extern kal_bool idp_intmem_is_buffer_available_ex(
  idp_mem_struct * const idp_mem,
  kal_uint32 const size,
  idp_mem_align_type const align);

extern kal_bool idp_intmem_is_buffer_available(
  kal_uint32 const size,
  idp_mem_align_type const align);

extern void idp_intmem_deinit_ex(idp_mem_struct * const idp_mem);

extern void idp_intmem_deinit(void);

#endif //#if defined(DRV_IDP_SUPPORT)
#endif
