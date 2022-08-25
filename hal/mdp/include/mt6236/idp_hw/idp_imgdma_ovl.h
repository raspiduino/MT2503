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
 *    idp_imgdma_ovl.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    The header file of HW driver of OVL of MT6236
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_imgdma_ovl_mt6236_h__
#define __idp_imgdma_ovl_mt6236_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include <idp_define.h>

#if defined(DRV_IDP_MT6236_SERIES)

#include "idp_imgdma.h"
#include <idp_core.h>
#include "idp_hw_common.h"
#include "img_common_enum.h"
#include "reg_base.h"

/* ===================================================
 *                        OVL
 * =================================================== */

/** \defgroup imgdma_ovl OVL
 * @{
 */
#define OVL_DMA_BASE                      (OVL_DMA_base)

#define IMGDMA_OVL_STATUS_FLAG_REG        (OVL_DMA_BASE + 0x0000)
#define IMGDMA_OVL_STATUS_FLAG_CLR_REG    (OVL_DMA_BASE + 0x2020)
#define IMGDMA_OVL_INTERRUPT_REG          (OVL_DMA_BASE + 0x0004)
#define IMGDMA_OVL_CFG_REG                (OVL_DMA_BASE + 0x0008)
#define IMGDMA_OVL_STOP_REG               (OVL_DMA_BASE + 0x0010)
#define IMGDMA_OVL_IN_SEL_REG             (OVL_DMA_BASE + 0x000c)
#define IMGDMA_OVL_EN_REG                 (OVL_DMA_BASE + 0x0014)
#define IMGDMA_OVL_RESET_REG              (OVL_DMA_BASE + 0x0018)
#define IMGDMA_OVL_QUEUE_RSTA_REG         (OVL_DMA_BASE + 0x0020)
#define IMGDMA_OVL_QUEUE_WSTA_REG         (OVL_DMA_BASE + 0x0024)
#define IMGDMA_OVL_QUEUE_DATA_REG         (OVL_DMA_BASE + 0x0028)
#define IMGDMA_OVL_QUEUE_BASE_REG         (OVL_DMA_BASE + 0x002c)
#define IMGDMA_OVL_EXEC_CNT_REG           (OVL_DMA_BASE + 0x0034)
#define IMGDMA_OVL_MASK_BASE_REG          (OVL_DMA_BASE + 0x0040)
#define IMGDMA_OVL_SRC_SIZE_REG           (OVL_DMA_BASE + 0x0044)
#define IMGDMA_OVL_MASK_SIZE_REG          (OVL_DMA_BASE + 0x0048)
#define IMGDMA_OVL_MASK_CFG_REG           (OVL_DMA_BASE + 0x004c)
#define IMGDMA_OVL_CON_REG                (OVL_DMA_BASE + 0x0050)
#define IMGDMA_OVL_CUR_SRC_POSITION_REG   (OVL_DMA_BASE + 0x0054)
#define IMGDMA_OVL_CUR_MASK_POSITION_REG  (OVL_DMA_BASE + 0x0058)
#define IMGDMA_OVL_PAL_COLOR_BASE_REG     (OVL_DMA_BASE + 0x1000) // 00 to ff

#define REG_IMGDMA_OVL_STATUS_FLAG        *((volatile unsigned int *) IMGDMA_OVL_STATUS_FLAG_REG)
#define REG_IMGDMA_OVL_STATUS_FLAG_CLR    *((volatile unsigned int *) IMGDMA_OVL_STATUS_FLAG_CLR_REG)
#define REG_IMGDMA_OVL_INTERRUPT          *((volatile unsigned int *) IMGDMA_OVL_INTERRUPT_REG)
#define REG_IMGDMA_OVL_CFG                *((volatile unsigned int *) IMGDMA_OVL_CFG_REG)
#define REG_IMGDMA_OVL_STOP               *((volatile unsigned int *) IMGDMA_OVL_STOP_REG)
#define REG_IMGDMA_OVL_IN_SEL             *((volatile unsigned int *) IMGDMA_OVL_IN_SEL_REG)
#define REG_IMGDMA_OVL_EN                 *((volatile unsigned int *) IMGDMA_OVL_EN_REG)
#define REG_IMGDMA_OVL_RESET              *((volatile unsigned int *) IMGDMA_OVL_RESET_REG)
#define REG_IMGDMA_OVL_QUEUE_RSTA         *((volatile unsigned int *) IMGDMA_OVL_QUEUE_RSTA_REG)
#define REG_IMGDMA_OVL_QUEUE_WSTA         *((volatile unsigned int *) IMGDMA_OVL_QUEUE_WSTA_REG)
#define REG_IMGDMA_OVL_QUEUE_DATA         *((volatile unsigned int *) IMGDMA_OVL_QUEUE_DATA_REG)
#define REG_IMGDMA_OVL_QUEUE_BASE         *((volatile unsigned int *) IMGDMA_OVL_QUEUE_BASE_REG)
#define REG_IMGDMA_OVL_EXEC_CNT           *((volatile unsigned int *) IMGDMA_OVL_EXEC_CNT_REG)
#define REG_IMGDMA_OVL_MASK_BASE          *((volatile unsigned int *) IMGDMA_OVL_MASK_BASE_REG)
#define REG_IMGDMA_OVL_SRC_SIZE           *((volatile unsigned int *) IMGDMA_OVL_SRC_SIZE_REG)
#define REG_IMGDMA_OVL_MASK_SIZE          *((volatile unsigned int *) IMGDMA_OVL_MASK_SIZE_REG)
#define REG_IMGDMA_OVL_MASK_CFG           *((volatile unsigned int *) IMGDMA_OVL_MASK_CFG_REG)
#define REG_IMGDMA_OVL_CON                *((volatile unsigned int *) IMGDMA_OVL_CON_REG)
#define REG_IMGDMA_OVL_CUR_SRC_POSITION   *((volatile unsigned int *) IMGDMA_OVL_CUR_SRC_POSITION_REG)
#define REG_IMGDMA_OVL_CUR_MASK_POSITION  *((volatile unsigned int *) IMGDMA_OVL_CUR_MASK_POSITION_REG)
#define REG_IMGDMA_OVL_PAL_COLOR_BASE     *((volatile unsigned int *) IMGDMA_OVL_PAL_COLOR_BASE_REG)

// TODO: TBD
#define IMGDMA_OVL_INT_BIT                0x00000001
#define IMGDMA_OVL_1BPP_PHOTO_FRAME_MASK  0x00000006
#define IMGDMA_OVL_1BPP_PHOTO_FRAME_BIT   0x00000000
#define IMGDMA_OVL_2BPP_PHOTO_FRAME_BIT   0x00000002
#define IMGDMA_OVL_4BPP_PHOTO_FRAME_BIT   0x00000004
#define IMGDMA_OVL_8BPP_PHOTO_FRAME_BIT   0x00000006
#define IMGDMA_OVL_AUTO_RESTART_BIT       0x00000008
#define IMGDMA_OVL_PALEN_BIT              0x00000010
#define IMGDMA_OVL_PSEL_BIT               0x00000020
#define IMGDMA_OVL_OUTPUT_MASK            0x000007C0
#define IMGDMA_OVL_OUTPUT_VDOENC_BIT      0x00000040
#define IMGDMA_OVL_OUTPUT_JPEG_BIT        0x00000080
#define IMGDMA_OVL_OUTPUT_Y2R0_BIT        0x00000100
#define IMGDMA_OVL_OUTPUT_DRZ_BIT         0x00000200
#define IMGDMA_OVL_OUTPUT_PRZ_BIT         0x00000400

// TODO: TBD
#define IMGDMA_OVL_CONF_HRATIO_MASK       0x0000000F
#define IMGDMA_OVL_CONF_VRATIO_MASK       0x000000F0
#define IMGDMA_OVL_CONF_SOURCE_KEY_MASK   0x0000FF00

// Enable
#define IMGDMA_OVL_START() \
    do { REG_IMGDMA_OVL_EN = 0x1; } while(0)

// Stop, engine stops at the frame end
#define IMGDMA_OVL_STOP() \
    do { REG_IMGDMA_OVL_STOP = 0x1; } while(0)

// Warm reset, stops after GMC transaction done...
#define IMGDMA_OVL_WARM_RESET() \
    do { REG_IMGDMA_OVL_RESET = 0x2; } while(0)

// Hard reset, immediate reset, pending GMC transactions may cause engine state machine incorrect
#define IMGDMA_OVL_HARD_RESET() \
    do { REG_IMGDMA_OVL_RESET = 0x1; \
         REG_IMGDMA_OVL_RESET = 0x0; } while(0)

/**
 * WARNING: Only choose one from below three
 */
// WARNING: only effective when engine not enabled
#define IMGDMA_OVL_BYPASS_MODE() \
    do { REG_IMGDMA_OVL_IN_SEL = 0x8000; } while(0)

// WARNING: only effective when engine not enabled
#define IMGDMA_OVL_STALL_PREV_ENGINE_MODE() \
    do { REG_IMGDMA_OVL_IN_SEL = 0x0; } while(0)

// WARNING: only effective when engine not enabled
#define IMGDMA_OVL_DROP_PREV_ENGINE_MODE() \
    do { REG_IMGDMA_OVL_IN_SEL = 0x1; } while(0)

// Enable interrupt
#define IMGDMA_OVL_INTERRUPT_ENABLE() \
    do { REG_IMGDMA_OVL_INTERRUPT |= 0x1; } while(0)

// Disable interrupt
#define IMGDMA_OVL_INTERRUPT_DISABLE() \
    do { REG_IMGDMA_OVL_INTERRUPT &= ~0x1; } while(0)

// Enable frame sync
#define IMGDMA_OVL_FRAME_SYNC_ENABLE() \
    do { REG_IMGDMA_OVL_CFG |= 0x80000000; } while(0)

// Disable frame sync
#define IMGDMA_OVL_FRAME_SYNC_DISABLE() \
    do { REG_IMGDMA_OVL_CFG &= ~0x80000000; } while(0)

// Descriptor mode
#define IMGDMA_OVL_DESCRIPTOR_MODE() \
    do { REG_IMGDMA_OVL_CFG |= 0x80; } while(0)

// Register mode
#define IMGDMA_OVL_REGISTER_MODE() \
    do { REG_IMGDMA_OVL_CFG &= ~0x80; } while(0)

// Auto loop mode
#define IMGDMA_OVL_AUTO_LOOP_ENABLE() \
    do { REG_IMGDMA_OVL_CFG |= 0x1; } while(0)

// Non auto loop mode
#define IMGDMA_OVL_AUTO_LOOP_DISABLE() \
    do { REG_IMGDMA_OVL_CFG &= ~0x1; } while(0)

// Enable palette read/write, must enable this before write palette data
#if 0 // Removed
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // 0

// Enable masking
#define IMGDMA_OVL_MASK_ENABLE() \
    do { REG_IMGDMA_OVL_CON |= 0x2; } while(0)

// Disable masking
#define IMGDMA_OVL_MASK_DISABLE() \
    do { REG_IMGDMA_OVL_CON &= ~0x2; } while(0)

/* macros of OVL control register */
/**
 * \brief Check if OVL is started or not.
 */
#define IMGDMA_OVL_IS_ENABLED() \
    ((0x1 == (REG_IMGDMA_OVL_EN & 0x1)) ? KAL_TRUE : KAL_FALSE)

#define IMGDMA_OVL_SET_SRC_KEY(color) \
  do { \
    REG_IMGDMA_OVL_MASK_CFG = ((REG_IMGDMA_OVL_MASK_CFG&0xff00ffff) | (((color)<<16)&0x00ff0000)); \
  } while (0)

// TODO: TBD
#if 0
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

/**
 * \brief OVL structure
 *
 * Programmers can use this structure to set up OVL.
 */
typedef struct
{
  kal_bool                  intr_en; /**< interrup enable */
  idp_lisr_intr_cb_t        intr_cb;
  idp_lisr_intr_cb_param_t  intr_cb_param;

  kal_bool                  restart; /**< auto loop mode */
  kal_bool                  overlay_frame_mode; /**< KAL_TRUE to enable masking */
  kal_bool                  frame_sync_en;

  kal_bool                  bypass;
  
  /* overlay frame configuration */
  kal_uint32                overlay_frame_buffer_address; /**< bsae address of the overlay frame buffer */
  kal_uint16                overlay_frame_width; /**< overlay frame width */
  kal_uint16                overlay_frame_height; /**< overlay frame height */
  kal_uint16                overlay_frame_target_width; /**< overlay frame target width */
  kal_uint16                overlay_frame_target_height; /**< overlay frame target height */
  img_palette_mode_enum_t   overlay_palette_mode; /**< 1/2/4/8 bpp */
  kal_uint8                 overlay_frame_source_key; /**< source key of the overlay frame buffer */
} idp_imgdma_ovl_struct;

IDP_HW_COMMON_API_DECLARATION(imgdma_ovl)

extern void *idp_imgdma_ovl_intr_cb_param;
extern void (*idp_imgdma_ovl_intr_cb)(void *);

extern kal_bool idp_imgdma_ovl_set_palette_real(
  kal_uint8 const palette_size,
  kal_uint32 const * const palette_addr_ptr);

extern kal_bool idp_imgdma_ovl_set_palette(
  kal_uint32 const key,
  kal_uint8 const palette_size,
  kal_uint32 const * const palette_addr_ptr);

extern kal_bool idp_imgdma_ovl_config_real(
  idp_imgdma_ovl_struct * const ovl_struct, 
  kal_bool const config_to_hardware);

extern kal_bool idp_imgdma_ovl_get_working_mem_real(
  kal_bool const use_internal_mem,
  idp_imgdma_ovl_struct * const ovl_struct,
  kal_bool const do_alloc,
  kal_uint32 const max_allowable_size);

extern kal_bool
idp_imgdma_ovl_start_real(
    idp_imgdma_ovl_struct const * const p_ovl_struct);

extern kal_bool
idp_imgdma_ovl_stop_real(
    idp_imgdma_ovl_struct const * const p_ovl_struct);

extern void
idp_imgdma_ovl_open_real(void);

/** @} */

#endif // #if defined(DRV_IDP_MT6236_SERIES)
#endif // #ifndef __idp_imgdma_ovl_mt6236_h__

