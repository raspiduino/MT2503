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
 *    idp_imgdma_rdma1.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    The header file of R_DMA1 HW driver of MT6236 IMGDMA
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 10 12 2011 chrono.wu
 * removed!
 * .
 *
 * 11 23 2010 chrono.wu
 * removed!
 * .
 *
 * removed!
 * removed!
 * 
 *
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_imgdma_rdma1_mt6236_h__
#define __idp_imgdma_rdma1_mt6236_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include <idp_define.h>

#if defined(DRV_IDP_MT6236_SERIES)

#include "idp_imgdma.h"
#include <idp_core.h>
#include "img_common_enum.h"
#include "reg_base.h"

/** \defgroup imgdma_rdma1 RDMA1
 *
 * \brief This module defines the functionalities which RDMA1
 * has.
 *
 * The input color format of R_DMAX includes all formats.
 * @{
 */
#define R_DMA1_BASE                         (R_DMA1_base)

// Register addresses
#define IMGDMA_RDMA1_STATUS_FLAG_REG        (R_DMA1_BASE + 0x0000)
#define IMGDMA_RDMA1_STATUS_FLAG_CLR_REG    (R_DMA1_BASE + 0x1020)
#define IMGDMA_RDMA1_INTERRUPT_REG	        (R_DMA1_BASE + 0x0004)
#define IMGDMA_RDMA1_CFG_REG                (R_DMA1_BASE + 0x0008)
#define IMGDMA_RDMA1_IN_SEL_REG	            (R_DMA1_BASE + 0x0010)
#define IMGDMA_RDMA1_STOP_REG               (R_DMA1_BASE + 0x0014)
#define IMGDMA_RDMA1_EN_REG	                (R_DMA1_BASE + 0x0018)
#define IMGDMA_RDMA1_RESET_REG	            (R_DMA1_BASE + 0x001c)
#define IMGDMA_RDMA1_QUEUE_RSTA_REG	        (R_DMA1_BASE + 0x0020)
#define IMGDMA_RDMA1_QUEUE_WSTA_REG	        (R_DMA1_BASE + 0x0024)
#define IMGDMA_RDMA1_QUEUE_DATA_REG	        (R_DMA1_BASE + 0x0028)
#define IMGDMA_RDMA1_QUEUE_BASE_REG	        (R_DMA1_BASE + 0x002c)
#define IMGDMA_RDMA1_EXEC_CNT_REG           (R_DMA1_BASE + 0x0034)
#define IMGDMA_RDMA1_Y_SRC_STR_ADDR_REG	    (R_DMA1_BASE + 0x0040)
#define IMGDMA_RDMA1_U_SRC_STR_ADDR_REG	    (R_DMA1_BASE + 0x0044)
#define IMGDMA_RDMA1_V_SRC_STR_ADDR_REG	    (R_DMA1_BASE + 0x0048)
#define IMGDMA_RDMA1_SRC_SIZE_REG           (R_DMA1_BASE + 0x004c)
#define IMGDMA_RDMA1_SRC_SIZE_IN_BYTE_REG   (R_DMA1_BASE + 0x0054)
#define IMGDMA_RDMA1_CLIP_SIZE_REG	        (R_DMA1_BASE + 0x0058)
#define IMGDMA_RDMA1_CLIP_SIZE_IN_BYTE_REG	(R_DMA1_BASE + 0x005c)
#define IMGDMA_RDMA1_CON_REG                (R_DMA1_BASE + 0x0060)
#define IMGDMA_RDMA1_SLOW_DOWN_REG	        (R_DMA1_BASE + 0x0070)
#define IMGDMA_RDMA1_DEBUG_STATUS0_REG	    (R_DMA1_BASE + 0x0090)
#define IMGDMA_RDMA1_DEBUG_STATUS1_REG	    (R_DMA1_BASE + 0x0094)
#define IMGDMA_RDMA1_DEBUG_STATUS2_REG	    (R_DMA1_BASE + 0x0098)
#define IMGDMA_RDMA1_DEBUG_STATUS3_REG	    (R_DMA1_BASE + 0x009c)
#define IMGDMA_RDMA1_DEBUG_STATUS4_REG	    (R_DMA1_BASE + 0x00a0)
#define IMGDMA_RDMA1_DEBUG_STATUS5_REG	    (R_DMA1_BASE + 0x00a4)
#define IMGDMA_RDMA1_DEBUG_STATUS6_REG	    (R_DMA1_BASE + 0x00a8)
#define IMGDMA_RDMA1_DEBUG_STATUS7_REG	    (R_DMA1_BASE + 0x00ac)
#define IMGDMA_RDMA1_DEBUG_STATUS8_REG	    (R_DMA1_BASE + 0x00b0)
#define IMGDMA_RDMA1_DEBUG_STATUS9_REG	    (R_DMA1_BASE + 0x00b4)
#define IMGDMA_RDMA1_DEBUG_STATUS10_REG	    (R_DMA1_BASE + 0x00b8)
#define IMGDMA_RDMA1_DEBUG_STATUS11_REG	    (R_DMA1_BASE + 0x00bc)
#define IMGDMA_RDMA1_DEBUG_STATUS12_REG	    (R_DMA1_BASE + 0x00c0)
#define IMGDMA_RDMA1_DEBUG_STATUS13_REG	    (R_DMA1_BASE + 0x00c4)
#define IMGDMA_RDMA1_DEBUG_STATUS14_REG	    (R_DMA1_BASE + 0x00c8)
#define IMGDMA_RDMA1_DEBUG_STATUS15_REG	    (R_DMA1_BASE + 0x00cc)

// Register access macros
#if !defined(MDP_C_MODEL)
#define REG_IMGDMA_RDMA1_STATUS_FLAG        *((volatile unsigned int *)IMGDMA_RDMA1_STATUS_FLAG_REG)
#define REG_IMGDMA_RDMA1_STATUS_FLAG_CLR    *((volatile unsigned int *)IMGDMA_RDMA1_STATUS_FLAG_CLR_REG)
#define REG_IMGDMA_RDMA1_INTERRUPT	        *((volatile unsigned int *)IMGDMA_RDMA1_INTERRUPT_REG)
#define REG_IMGDMA_RDMA1_CFG                *((volatile unsigned int *)IMGDMA_RDMA1_CFG_REG)
#define REG_IMGDMA_RDMA1_IN_SEL	            *((volatile unsigned int *)IMGDMA_RDMA1_IN_SEL_REG)
#define REG_IMGDMA_RDMA1_STOP               *((volatile unsigned int *)IMGDMA_RDMA1_STOP_REG)
#define REG_IMGDMA_RDMA1_EN	                *((volatile unsigned int *)IMGDMA_RDMA1_EN_REG)
#define REG_IMGDMA_RDMA1_RESET	            *((volatile unsigned int *)IMGDMA_RDMA1_RESET_REG)
#define REG_IMGDMA_RDMA1_QUEUE_RSTA	        *((volatile unsigned int *)IMGDMA_RDMA1_QUEUE_RSTA_REG)
#define REG_IMGDMA_RDMA1_QUEUE_WSTA	        *((volatile unsigned int *)IMGDMA_RDMA1_QUEUE_WSTA_REG)
#define REG_IMGDMA_RDMA1_QUEUE_DATA	        *((volatile unsigned int *)IMGDMA_RDMA1_QUEUE_DATA_REG)
#define REG_IMGDMA_RDMA1_QUEUE_BASE	        *((volatile unsigned int *)IMGDMA_RDMA1_QUEUE_BASE_REG)
#define REG_IMGDMA_RDMA1_EXEC_CNT           *((volatile unsigned int *)IMGDMA_RDMA1_EXEC_CNT_REG)
#define REG_IMGDMA_RDMA1_Y_SRC_STR_ADDR	    *((volatile unsigned int *)IMGDMA_RDMA1_Y_SRC_STR_ADDR_REG)
#define REG_IMGDMA_RDMA1_U_SRC_STR_ADDR	    *((volatile unsigned int *)IMGDMA_RDMA1_U_SRC_STR_ADDR_REG)
#define REG_IMGDMA_RDMA1_V_SRC_STR_ADDR	    *((volatile unsigned int *)IMGDMA_RDMA1_V_SRC_STR_ADDR_REG)
#define REG_IMGDMA_RDMA1_SRC_SIZE           *((volatile unsigned int *)IMGDMA_RDMA1_SRC_SIZE_REG)
#define REG_IMGDMA_RDMA1_SRC_SIZE_IN_BYTE   *((volatile unsigned int *)IMGDMA_RDMA1_SRC_SIZE_IN_BYTE_REG)
#define REG_IMGDMA_RDMA1_CLIP_SIZE	        *((volatile unsigned int *)IMGDMA_RDMA1_CLIP_SIZE_REG)
#define REG_IMGDMA_RDMA1_CLIP_SIZE_IN_BYTE	*((volatile unsigned int *)IMGDMA_RDMA1_CLIP_SIZE_IN_BYTE_REG)
#define REG_IMGDMA_RDMA1_CON                *((volatile unsigned int *)IMGDMA_RDMA1_CON_REG)
#define REG_IMGDMA_RDMA1_SLOW_DOWN	        *((volatile unsigned int *)IMGDMA_RDMA1_SLOW_DOWN_REG)
#define REG_IMGDMA_RDMA1_DEBUG_STATUS0	    *((volatile unsigned int *)IMGDMA_RDMA1_DEBUG_STATUS0_REG)
#define REG_IMGDMA_RDMA1_DEBUG_STATUS1	    *((volatile unsigned int *)IMGDMA_RDMA1_DEBUG_STATUS1_REG)
#define REG_IMGDMA_RDMA1_DEBUG_STATUS2	    *((volatile unsigned int *)IMGDMA_RDMA1_DEBUG_STATUS2_REG)
#define REG_IMGDMA_RDMA1_DEBUG_STATUS3	    *((volatile unsigned int *)IMGDMA_RDMA1_DEBUG_STATUS3_REG)
#define REG_IMGDMA_RDMA1_DEBUG_STATUS4	    *((volatile unsigned int *)IMGDMA_RDMA1_DEBUG_STATUS4_REG)
#define REG_IMGDMA_RDMA1_DEBUG_STATUS5	    *((volatile unsigned int *)IMGDMA_RDMA1_DEBUG_STATUS5_REG)
#define REG_IMGDMA_RDMA1_DEBUG_STATUS6	    *((volatile unsigned int *)IMGDMA_RDMA1_DEBUG_STATUS6_REG)
#define REG_IMGDMA_RDMA1_DEBUG_STATUS7	    *((volatile unsigned int *)IMGDMA_RDMA1_DEBUG_STATUS7_REG)
#define REG_IMGDMA_RDMA1_DEBUG_STATUS8	    *((volatile unsigned int *)IMGDMA_RDMA1_DEBUG_STATUS8_REG)
#define REG_IMGDMA_RDMA1_DEBUG_STATUS9	    *((volatile unsigned int *)IMGDMA_RDMA1_DEBUG_STATUS9_REG)
#define REG_IMGDMA_RDMA1_DEBUG_STATUS10	    *((volatile unsigned int *)IMGDMA_RDMA1_DEBUG_STATUS10_REG)
#define REG_IMGDMA_RDMA1_DEBUG_STATUS11	    *((volatile unsigned int *)IMGDMA_RDMA1_DEBUG_STATUS11_REG)
#define REG_IMGDMA_RDMA1_DEBUG_STATUS12	    *((volatile unsigned int *)IMGDMA_RDMA1_DEBUG_STATUS12_REG)
#define REG_IMGDMA_RDMA1_DEBUG_STATUS13	    *((volatile unsigned int *)IMGDMA_RDMA1_DEBUG_STATUS13_REG)
#define REG_IMGDMA_RDMA1_DEBUG_STATUS14	    *((volatile unsigned int *)IMGDMA_RDMA1_DEBUG_STATUS14_REG)
#define REG_IMGDMA_RDMA1_DEBUG_STATUS15	    *((volatile unsigned int *)IMGDMA_RDMA1_DEBUG_STATUS15_REG)
#else // !defined(MDP_C_MODEL)
#define REG_IMGDMA_RDMA1_STATUS_FLAG            R_DMA1_STATUS_FLAG
#define REG_IMGDMA_RDMA1_INTERRUPT              R_DMA1_INTERRUPT
#define REG_IMGDMA_RDMA1_CFG                    R_DMA1_CFG
#define REG_IMGDMA_RDMA1_IN_SEL                 R_DMA1_IN_SEL
#define REG_IMGDMA_RDMA1_STOP                   R_DMA1_STOP
#define REG_IMGDMA_RDMA1_EN                     R_DMA1_EN
#define REG_IMGDMA_RDMA1_RESET                  R_DMA1_RESET
#define REG_IMGDMA_RDMA1_QUEUE_RSTA             R_DMA1_QUEUE_RSTA
#define REG_IMGDMA_RDMA1_QUEUE_WSTA             R_DMA1_QUEUE_WSTA
#define REG_IMGDMA_RDMA1_QUEUE_DATA             R_DMA1_QUEUE_DATA 
#define REG_IMGDMA_RDMA1_QUEUE_BASE             R_DMA1_QUEUE_BASE 
#define REG_IMGDMA_RDMA1_EXEC_CNT               R_DMA1_EXEC_CNT 
#define REG_IMGDMA_RDMA1_Y_SRC_STR_ADDR         R_DMA1_Y_SRC_STR_ADDR 
#define REG_IMGDMA_RDMA1_U_SRC_STR_ADDR         R_DMA1_U_SRC_STR_ADDR 
#define REG_IMGDMA_RDMA1_V_SRC_STR_ADDR         R_DMA1_V_SRC_STR_ADDR 
#define REG_IMGDMA_RDMA1_SRC_SIZE               R_DMA1_SRC_SIZE 
#define REG_IMGDMA_RDMA1_SRC_SIZE_IN_BYTE       R_DMA1_SRC_SIZE_IN_BYTE 
#define REG_IMGDMA_RDMA1_CLIP_SIZE              R_DMA1_CLIP_SIZE 
#define REG_IMGDMA_RDMA1_CLIP_SIZE_IN_BYTE      R_DMA1_CLIP_SIZE_IN_BYTE 
#define REG_IMGDMA_RDMA1_CON                    R_DMA1_CON 
#define REG_IMGDMA_RDMA1_SLOW_DOWN              R_DMA1_SLOW_DOWN 
#if 0 // Not available on C model
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
#endif // 0
#endif // !defined(MDP_C_MODEL)

/* bit maps */

/* Macros of R_DMA */
/**
 * brief Enable interrupt for every frame
 */
// Enable RDMA1
#define IMGDMA_RDMA1_ENABLE() \
  do { REG_IMGDMA_RDMA1_EN = 0x1; } while(0)

// Stop RDMA1
#define IMGDMA_RDMA1_STOP() \
  do { REG_IMGDMA_RDMA1_STOP = 0x1; } while(0)

#define IMGDMA_RDMA1_IS_ENABLED() \
  ((0x1 == (REG_IMGDMA_RDMA1_EN&0x1)) ? KAL_TRUE : KAL_FALSE)

// Warm reset RDMA1
#define IMGDMA_RDMA1_WARM_RESET() \
  do { REG_IMGDMA_RDMA1_RESET = 0x2; } while(0)

// Hard reset RDMA1
#define IMGDMA_RDMA1_HARD_RESET() \
  do { REG_IMGDMA_RDMA1_RESET = 0x1; \
       REG_IMGDMA_RDMA1_RESET = 0x0; } while(0)

// Enable interrupt 
#define IMGDMA_RDMA1_INTERRUPT_ENABLE() \
  do { REG_IMGDMA_RDMA1_INTERRUPT |= 0x1; } while(0)

// Disable interrupt 
#define IMGDMA_RDMA1_INTERRUPT_DISABLE() \
  do { REG_IMGDMA_RDMA1_INTERRUPT &= ~0x1; } while(0)

// Enable auto loop
#define IMGDMA_RDMA1_AUTO_LOOP_ENABLE() \
  do { REG_IMGDMA_RDMA1_CFG |= 0x1; } while(0)

// Disable auto loop
#define IMGDMA_RDMA1_AUTO_LOOP_DISABLE() \
  do { REG_IMGDMA_RDMA1_CFG &= ~0x1; } while(0)

#define IMGDMA_RDMA1_FRAME_SYNC_ENABLE() \
    do { REG_IMGDMA_RDMA1_CFG |= 0x80000000; } while(0)

#define IMGDMA_RDMA1_FRAME_SYNC_DISABLE() \
    do { REG_IMGDMA_RDMA1_CFG &= ~0x80000000; } while(0)

// RDMA1 register mode
#define IMGDMA_RDMA1_REGISTER_MODE() \
  do { REG_IMGDMA_RDMA1_CFG &= ~0x80; } while(0)

// RDMA1 descriptor mode
#define IMGDMA_RDMA1_DESCRIPTOR_MODE() \
  do { REG_IMGDMA_RDMA1_CFG |= 0x80; } while(0)

// TODO: frame sync...

// WARNING: choose only one from below three when RDMA not enabled
// Bypass
#define IMGDMA_RDMA1_BYPASS_MODE() \
  do { REG_IMGDMA_RDMA1_IN_SEL = 0x8000; } while(0)

// Stall
#define IMGDMA_RDMA1_STALL_PREV_ENGINE_MODE() \
  do { REG_IMGDMA_RDMA1_IN_SEL = 0x0; } while(0)

// Drop
#define IMGDMA_RDMA1_DROP_PREV_ENGINE_MODE() \
  do { REG_IMGDMA_RDMA1_IN_SEL = 0x1; } while(0)

// WARNING: choose one from below two when RDMA enabled
// From memory
#define IMGDMA_RDMA1_IN_SEL_FROM_MEMORY() \
  do { REG_IMGDMA_RDMA1_IN_SEL = 0x0; } while(0)

// Only useful for RDMA1, from MOUT
#if 1
#define IMGDMA_RDMA1_IN_SEL_FROM_PREV_ENGINE() \
  do { REG_IMGDMA_RDMA1_IN_SEL = 0x2; } while(0)
#endif // 0

// If set to YUV format, SW needs to set VH, UH, YH, VV, UV, and YV
#define IMGDMA_RDMA1_SET_INPUT_FORMAT(format) \
    do { REG_IMGDMA_RDMA1_CON = \
        ((REG_IMGDMA_RDMA1_CON & (~IMGDMA_RDMA_CON_INPUT_FORMAT_MASK)) | (format)); } while(0)

#define IMGDMA_RDMA1_RGB_ROUND_ENABLE() \
    do { REG_IMGDMA_RDMA1_CON |= IMGDMA_RDMA_CON_ROUND_BIT; } while(0)

#define IMGDMA_RDMA1_RGB_ROUND_DISABLE() \
    do { REG_IMGDMA_RDMA1_CON &= ~IMGDMA_RDMA_CON_ROUND_BIT; } while(0)

#define IMGDMA_RDMA1_SET_INPUT_YUV444() \
    do { REG_IMGDMA_RDMA1_CON = \
        ((REG_IMGDMA_RDMA1_CON & (~0x0fff0007)) | 0x05550005); } while(0)

#define IMGDMA_RDMA1_SET_INPUT_YUV422() \
    do { REG_IMGDMA_RDMA1_CON = \
        ((REG_IMGDMA_RDMA1_CON & (~0x0fff0007)) | 0x05690005); } while(0)

#define IMGDMA_RDMA1_SET_INPUT_YUV420() \
    do { REG_IMGDMA_RDMA1_CON = \
        ((REG_IMGDMA_RDMA1_CON & (~0x0fff0007)) | 0x0a690005); } while(0)

#define IMGDMA_RDMA1_SET_INPUT_YUV411() \
    do { REG_IMGDMA_RDMA1_CON = \
        ((REG_IMGDMA_RDMA1_CON & (~0x0fff0007)) | 0x057d0005); } while(0)

#define IMGDMA_RDMA1_SET_INPUT_YUV400() \
    do { REG_IMGDMA_RDMA1_CON = \
        ((REG_IMGDMA_RDMA1_CON & (~0x0fff0007)) | 0x00410005); } while(0)


/**
 * \brief R_DMA structure
 *
 * Programmers can use this structure to set up R_DMA0 and R_DMA1.
 */
typedef idp_imgdma_rdma_struct idp_imgdma_rdma1_struct;

IDP_HW_COMMON_API_DECLARATION(imgdma_rdma1)

extern void *idp_imgdma_rdma1_intr_cb_param;
extern void (*idp_imgdma_rdma1_intr_cb)(void *);

extern kal_bool 
idp_imgdma_rdma1_config_real(
    idp_imgdma_rdma1_struct * const rdma1_struct, 
    kal_bool const config_to_hardware);

extern kal_bool 
idp_imgdma_rdma1_get_working_mem_real(
    kal_bool const use_internal_mem,
    idp_imgdma_rdma1_struct const * const rdma1_struct,
    kal_bool const do_alloc,
    kal_uint32 const max_allowable_size);

extern kal_bool
idp_imgdma_rdma1_start_real(
    idp_imgdma_rdma1_struct const * const p_rdma1_struct);

extern kal_bool
idp_imgdma_rdma1_stop_real(
    idp_imgdma_rdma1_struct const * const p_rdma1_struct);

extern void
idp_imgdma_rdma1_open_real(void);

/** @} */

#endif // #if defined(DRV_IDP_MT6236_SERIES)
#endif // #ifndef __idp_imgdma_rdma1_mt6236_h__

