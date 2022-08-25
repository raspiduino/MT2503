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
 *    idp_imgdma_jpgdma.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    The interface of HW driver of MT6236 JPG_DMA
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
 * 09 06 2011 chrono.wu
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

#ifndef __idp_imgdma_jpgdma_mt6236_h__
#define __idp_imgdma_jpgdma_mt6236_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include <idp_define.h>

#if defined(DRV_IDP_MT6236_SERIES)

#include "idp_imgdma.h"
#include <idp_core.h>
#include "img_common_enum.h"
#include "reg_base.h"

/* ===================================================
 *                    JPEG DMA
 * =================================================== */

/** \defgroup imgdma_jpgdma JPG_DMA
 * @{
 */
#define JPG_DMA_BASE                      (JPEG_DMA_base)
/* 6236 register definition of JPG_DMA */
#define IMGDMA_JPG_DMA_STOP_REG           (JPG_DMA_BASE + 0x0000)
#define IMGDMA_JPG_DMA_EN_REG             (JPG_DMA_BASE + 0x0004)
#define IMGDMA_JPG_DMA_RESET_REG          (JPG_DMA_BASE + 0x0008)
#define IMGDMA_JPG_DMA_CON_REG            (JPG_DMA_BASE + 0x000c)
#define IMGDMA_JPG_DMA_BUF_BASE_ADDR0_REG (JPG_DMA_BASE + 0x0010)
#define IMGDMA_JPG_DMA_BUF_BASE_ADDR1_REG (JPG_DMA_BASE + 0x0014)
#define IMGDMA_JPG_DMA_SIZE_REG           (JPG_DMA_BASE + 0x0018)
#define IMGDMA_JPG_DMA_INTERRUPT_REG      (JPG_DMA_BASE + 0x0020)
#define IMGDMA_JPG_DMA_DEBUG_STATUS0_REG  (JPG_DMA_BASE + 0x0090)
#define IMGDMA_JPG_DMA_DEBUG_STATUS1_REG  (JPG_DMA_BASE + 0x0094)
#define IMGDMA_JPG_DMA_DEBUG_STATUS2_REG  (JPG_DMA_BASE + 0x0098)
#define IMGDMA_JPG_DMA_DEBUG_STATUS3_REG  (JPG_DMA_BASE + 0x009c)
#define IMGDMA_JPG_DMA_DEBUG_STATUS4_REG  (JPG_DMA_BASE + 0x00a0)
#define IMGDMA_JPG_DMA_DEBUG_STATUS5_REG  (JPG_DMA_BASE + 0x00a4)
#define IMGDMA_JPG_DMA_DEBUG_STATUS6_REG  (JPG_DMA_BASE + 0x00a8)
#define IMGDMA_JPG_DMA_DEBUG_STATUS7_REG  (JPG_DMA_BASE + 0x00ac)

#define REG_IMGDMA_JPG_DMA_STOP           *((volatile unsigned int *) IMGDMA_JPG_DMA_STOP_REG)
#define REG_IMGDMA_JPG_DMA_EN             *((volatile unsigned int *) IMGDMA_JPG_DMA_EN_REG)
#define REG_IMGDMA_JPG_DMA_RESET          *((volatile unsigned int *) IMGDMA_JPG_DMA_RESET_REG)
#define REG_IMGDMA_JPG_DMA_CON            *((volatile unsigned int *) IMGDMA_JPG_DMA_CON_REG)
#define REG_IMGDMA_JPG_DMA_BUF_BASE_ADDR0 *((volatile unsigned int *) IMGDMA_JPG_DMA_BUF_BASE_ADDR0_REG)
#define REG_IMGDMA_JPG_DMA_BUF_BASE_ADDR1 *((volatile unsigned int *) IMGDMA_JPG_DMA_BUF_BASE_ADDR1_REG)
#define REG_IMGDMA_JPG_DMA_SIZE           *((volatile unsigned int *) IMGDMA_JPG_DMA_SIZE_REG)
#define REG_IMGDMA_JPG_DMA_INTERRUPT      *((volatile unsigned int *) IMGDMA_JPG_DMA_INTERRUPT_REG)
#define REG_IMGDMA_JPG_DMA_DEBUG_STATUS0  *((volatile unsigned int *) IMGDMA_JPG_DMA_DEBUG_STATUS0_REG)
#define REG_IMGDMA_JPG_DMA_DEBUG_STATUS1  *((volatile unsigned int *) IMGDMA_JPG_DMA_DEBUG_STATUS1_REG)
#define REG_IMGDMA_JPG_DMA_DEBUG_STATUS2  *((volatile unsigned int *) IMGDMA_JPG_DMA_DEBUG_STATUS2_REG)
#define REG_IMGDMA_JPG_DMA_DEBUG_STATUS3  *((volatile unsigned int *) IMGDMA_JPG_DMA_DEBUG_STATUS3_REG)
#define REG_IMGDMA_JPG_DMA_DEBUG_STATUS4  *((volatile unsigned int *) IMGDMA_JPG_DMA_DEBUG_STATUS4_REG)
#define REG_IMGDMA_JPG_DMA_DEBUG_STATUS5  *((volatile unsigned int *) IMGDMA_JPG_DMA_DEBUG_STATUS5_REG)
#define REG_IMGDMA_JPG_DMA_DEBUG_STATUS6  *((volatile unsigned int *) IMGDMA_JPG_DMA_DEBUG_STATUS6_REG)
#define REG_IMGDMA_JPG_DMA_DEBUG_STATUS7  *((volatile unsigned int *) IMGDMA_JPG_DMA_DEBUG_STATUS7_REG)

// bit mapping of JPG_DMA control register
#define IMGDMA_JPG_DMA_CON_REG_INTEN_BIT            0x00000001
#define IMGDMA_JPG_DMA_CON_REG_MODE_MASK            0x00000006 /**< YUV422, 420, 411, 400 */
#define IMGDMA_JPG_DMA_CON_REG_AUTO_RSTR_BIT        0x00000008
#define IMGDMA_JPG_DMA_CON_REG_DROP_BIT             0x00000010 // TODO: What is this?
#define IMGDMA_JPG_DMA_CON_REG_FRAME_SYNC_EN_BIT    0x00000080
#define IMGDMA_JPG_DMA_CON_REG_THROTTLE_EN_BIT      0x00001000
#define IMGDMA_JPG_DMA_CON_REG_THROTTLE_PERIOD_MASK 0xffff0000

// JPG_DMA working mode
#define IMGDMA_JPG_DMA_CON_REG_MODE_YUV422          0x00000000
#define IMGDMA_JPG_DMA_CON_REG_MODE_YUV420          0x00000002
#define IMGDMA_JPG_DMA_CON_REG_MODE_YUV411          0x00000004
#define IMGDMA_JPG_DMA_CON_REG_MODE_YUV400          0x00000006

// Start JPG_DMA
#define IMGDMA_JPG_DMA_START() \
    do { REG_IMGDMA_JPG_DMA_EN = 0x1; } while(0)

// Stop JPG_DMA at frame end. MUST polling REG_IMGDMA_JPG_DMA_EN
#define IMGDMA_JPG_DMA_STOP() \
    do { REG_IMGDMA_JPG_DMA_STOP = 0x1; } while(0)

// Warm reset JPG_DMA. Engine will wait for pending GMC transaction to avoid state machine error...
#define IMGDMA_JPG_DMA_WARM_RESET() \
    do { REG_IMGDMA_JPG_DMA_RESET = 0x2; } while(0)

// Hard reset JPG_DMA. Engine will not wait for pending GMC transaction. SW needs to wait for while...
#define IMGDMA_JPG_DMA_HARD_RESET() \
    do { REG_IMGDMA_JPG_DMA_RESET = 0x1; \
         REG_IMGDMA_JPG_DMA_RESET = 0x0; } while(0)

/**
 * \brief Check if JPEG DMA is started or not.
 */
#define IMGDMA_JPG_DMA_IS_ENABLED() \
    ((REG_IMGDMA_JPG_DMA_EN) ? KAL_TRUE : KAL_FALSE)

/* macros of JPEG image DMA control register */
/**
 * \brief enable auto restarting of the JPEG DMA
 */
#define IMGDMA_JPG_DMA_AUTO_RSTR_ENABLE() \
    do { REG_IMGDMA_JPG_DMA_CON |= IMGDMA_JPG_DMA_CON_REG_AUTO_RSTR_BIT; } while(0)

/**
 * \brief disable auto restarting of the JPEG DMA
 */
#define IMGDMA_JPG_DMA_AUTO_RSTR_DISABLE() \
    do { REG_IMGDMA_JPG_DMA_CON &= ~IMGDMA_JPG_DMA_CON_REG_AUTO_RSTR_BIT; } while(0)

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

// Enable interrupt
#define IMGDMA_JPG_DMA_INT_ENABLE() \
    do { REG_IMGDMA_JPG_DMA_CON |= IMGDMA_JPG_DMA_CON_REG_INTEN_BIT; } while(0)

// Disable interrupt
#define IMGDMA_JPG_DMA_INT_DISABLE() \
    do { REG_IMGDMA_JPG_DMA_CON &= ~IMGDMA_JPG_DMA_CON_REG_INTEN_BIT; } while(0)

// Enable ISP frame sync
#define IMGDMA_JPG_DMA_ISP_FRAME_SYNC_ENABLE() \
    do { REG_IMGDMA_JPG_DMA_CON |= IMGDMA_JPG_DMA_CON_REG_FRAME_SYNC_EN_BIT; } while(0)

// Disable ISP frame sync
#define IMGDMA_JPG_DMA_ISP_FRAME_SYNC_DISABLE() \
    do { REG_IMGDMA_JPG_DMA_CON &= ~IMGDMA_JPG_DMA_CON_REG_FRAME_SYNC_EN_BIT; } while(0)
    
// Set JPEG DMA source size
#define IMGDMA_JPG_DMA_SET_SRC_SIZE(width, height) \
    do { REG_IMGDMA_JPG_DMA_SIZE = (((width)&0xffff) | (((height)&0xffff)<<16)); } while(0)


// TODO: Check where these are used
#define JPEG_FORMAT_GRAY      0
#define JPEG_FORMAT_YUV422    1
#define JPEG_FORMAT_YUV420    2
#define JPEG_FORMAT_YUV411    3

// Min. num of lines for single working buffer in different YUV modes
#define IMGDMA_JPG_DMA_WM_NO_LINES_YUV422         (8)
#define IMGDMA_JPG_DMA_WM_NO_LINES_YUV420         (16)
#define IMGDMA_JPG_DMA_WM_NO_LINES_YUV411         (8)
#define IMGDMA_JPG_DMA_WM_NO_LINES_YUV400         (8)

#define IMGDMA_JPG_DMA_BPP_YUV422                 (2)
#define IMGDMA_JPG_DMA_BPP_YUV420                 (3/2)
#define IMGDMA_JPG_DMA_BPP_YUV411                 (3/2)
#define IMGDMA_JPG_DMA_BPP_YUV400                 (1)

#define IMGDMA_JPG_DMA_WIDTH_PAD_YUV422           (16)
#define IMGDMA_JPG_DMA_WIDTH_PAD_YUV420           (16)
#define IMGDMA_JPG_DMA_WIDTH_PAD_YUV411           (32)
#define IMGDMA_JPG_DMA_WIDTH_PAD_YUV400           (8)

/**
 * \brief JPG_DMA structure
 *
 * Programmers can use this structure to set up JPG_DMA.
 */
typedef struct
{
    kal_bool                  restart; /**< 1: automatic reastart while current frame is finished */

    kal_bool                  intr_en; /**< int */
    kal_bool                  frame_sync_en;
    
    idp_lisr_intr_cb_t        intr_cb;
    idp_lisr_intr_cb_param_t  intr_cb_param;

    kal_uint16                target_width; /**< target width before padding, padding according to YUV mode */
    kal_uint16                target_height; /**< target height */
    
    kal_uint16                fifo_size; /**< working buffer number of lines */

    kal_uint32                wm_addr_0; /**< the address of 1st working buffer. */
    kal_uint32                wm_addr_1; /**< the address of 2nd working buffer. Should be on differnt bank */
    
    img_color_fmt_yuv_enum_t  jpeg_yuv_mode; /**< YUV422, YUV420, YUV411, YUV400 mode */
    
    /* Below private data, not updated by client */
    kal_uint16                _target_width_padded; /**< padded width */
    kal_uint32                _single_working_buffer_size; /**< padded width * bpp * number of lines */
    
} idp_imgdma_jpgdma_struct;

IDP_HW_COMMON_API_DECLARATION(imgdma_jpgdma)

extern void *idp_imgdma_jpgdma_intr_cb_param;
extern void (*idp_imgdma_jpgdma_intr_cb)(void *);

extern kal_uint32 idp_imgdma_jpgdma_get_jpgdma_wb_nol(
  img_color_fmt_yuv_enum_t yuv_format);

extern kal_bool idp_imgdma_jpgdma_get_working_mem_size_real(
  idp_imgdma_jpgdma_struct * const p_jpgdma_struct,
  kal_uint32 * const p_size);

extern kal_bool idp_imgdma_jpgdma_config_real(
  idp_imgdma_jpgdma_struct * const jpgdma_struct, 
  kal_bool const config_to_hardware);

extern kal_bool idp_imgdma_jpgdma_get_working_mem_real(
  kal_bool const use_internal_mem,
  idp_imgdma_jpgdma_struct * const jpgdma_struct,
  kal_bool const do_alloc,
  kal_uint32 const max_allowable_size);

extern kal_bool
idp_imgdma_jpgdma_start_real(
    idp_imgdma_jpgdma_struct const * const p_jpgdma_struct);

extern kal_bool
idp_imgdma_jpgdma_stop_real(
    idp_imgdma_jpgdma_struct const * const p_jpgdma_struct);

/** @} */

#endif // #if defined(DRV_IDP_MT6236_SERIES)
#endif // #ifndef __idp_imgdma_jpgdma_mt6236_h__
