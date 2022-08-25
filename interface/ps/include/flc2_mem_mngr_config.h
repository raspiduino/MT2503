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
 *   flc2_mem_mngr.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides the function declarations used for gprs flow
 *   control implementation.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _FLC2_MEM_MNGR_H
#define _FLC2_MEM_MNGR_H

#include "kal_general_types.h"

/*************************************************************************
 * Constants
 *************************************************************************/

#ifdef __MTK_INTERNAL__
/* under construction !*/
#else
#define FLC2_MEM_FIX_SIZE_GUARD_OVERHEAD (0)
#endif


#define FLC2_MB_CTRL_HEADER_LEN (FLC2_MAX(FLC2_MAX(sizeof(flc2_mb_adm_ctrl_header_struct), \
    sizeof(flc2_mb_fix_size_ctrl_header_struct)), sizeof(flc2_mb_multi_size_ctrl_header_struct)))
/* Fix size */
#define FLC2_MEM_FIX_SIZE_CHUNK_SIZE (128)
#define FLC2_MEM_FIX_SIZE_CHUNK_OVERHEAD (4)
#define FLC2_MEM_FIX_SIZE_CHUNK_TOTAL_OVERHEAD (FLC2_MEM_FIX_SIZE_CHUNK_OVERHEAD + FLC2_MEM_FIX_SIZE_GUARD_OVERHEAD )
#define FLC2_MEM_FIX_SIZE_CTRL_HEADER_LEN (((sizeof(flc2_mb_fix_size_ctrl_header_struct)+3)/4)*4)

#define FLC2_MEM_ADM_CTRL_HEADER_LEN (((sizeof(flc2_mb_adm_ctrl_header_struct)+3)/4)*4)

#define FLC2_MEM_AFM_CTRL_HEADER_LEN (((sizeof(flc2_mb_afm_ctrl_header_struct)+3)/4)*4)

/* Definations for Multi Size Pool */
#define FLC2_MEM_MULTI_SIZE_OVERHEAD_PER_UNIT (4)
#define FLC2_MEM_MULTI_SIZE_CHUNK_HEADER_SIZE sizeof(flc2_mem_multi_size_chunk_header_struct) /* 2B for Check patent, 2B for status, 4B for next index, 4B for previous index*/
#define FLC2_MEM_MULTI_SIZE_CHUNK_BODY_SIZE (2048)
#define FLC2_MEM_MULTI_SIZE_CHUNK_SIZE (FLC2_MEM_MULTI_SIZE_CHUNK_HEADER_SIZE+FLC2_MEM_MULTI_SIZE_CHUNK_BODY_SIZE)
#define FLC2_MEM_MULTI_SIZE_CTRL_HEADER_LEN (((sizeof(flc2_mb_multi_size_ctrl_header_struct)+3)/4)*4)
/*************************************************************************
 * Global Vars
 *************************************************************************/

/*************************************************************************
 * Globals
 *************************************************************************/

/*************************************************************************
 * Macros
 *************************************************************************/
/*************************************************************************
 * Macros for counting MB size
 *************************************************************************/

#define FLC2_MEM_SIZE_FOUR_ALIGN(_SIZE_)  (((_SIZE_+3)/4)*4) 


/* Multi size */
#define FLC2_MULTI_SIZE_POOL_SIZE_ALIGN(_SIZE_) \
    (((_SIZE_ + (FLC2_MEM_MULTI_SIZE_CHUNK_BODY_SIZE-1))/FLC2_MEM_MULTI_SIZE_CHUNK_BODY_SIZE)*FLC2_MEM_MULTI_SIZE_CHUNK_BODY_SIZE)

#define FLC2_MULTI_SIZE_POOL_TOTOAL_SIZE_COUNT(_SIZE) \
    (((FLC2_MULTI_SIZE_POOL_SIZE_ALIGN(_SIZE_)/FLC2_MEM_MULTI_SIZE_CHUNK_BODY_SIZE) * FLC2_MEM_MULTI_SIZE_CHUNK_SIZE) \
    + FLC2_MEM_MULTI_SIZE_CTRL_HEADER_LEN)

/* Fix size */
/* Block size + peer_buff_struct header overhead */
#define FLC2_FIX_POOL_SIZE_ALIGN(_SIZE_) \
    ((((((_SIZE_ / 2) + sizeof(peer_buff_struct)) + 3)/4) * 4) * 2)

/* Pool size without memory block control header overhead */
#define FLC2_FIX_SIZE_POOL_SIZE_COUNT(_UNIT_SIZE_, _PKT_COUNT_) \
    (_UNIT_SIZE_ * _PKT_COUNT_)

/* Pool size with mb control header overhead */
#define FLC2_FIX_SIZE_ACTUAL_SIZE_COUNT(_UNIT_SIZE_, _PKT_COUNT_) \
    ((FLC2_FIX_POOL_SIZE_ALIGN(_UNIT_SIZE_) + FLC2_MEM_FIX_SIZE_CHUNK_OVERHEAD)  * _PKT_COUNT_)
    
#define FLC2_ADM_UNIT_SIZE_COUNT(_size_) (_size_ + 8) //8 byte for the peer_buffer header


extern kal_uint32 flc2_mem_mb_grow_size(kal_uint8 mb_index, kal_uint32 req_size);
extern void flc2_mem_mb_shrink_size(kal_uint8 mb_index, kal_uint32 size);
extern void flc2_resume_related_pool(kal_uint8 curr_pool_id, kal_uint8 mb_index);

#endif /* _FLC2_MEM_MNGR_H */

