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
 * idp_imgdma_ipgdma.h
 *
 * Project:
 * --------
 *   Maui
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
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 06 26 2012 chelun.tsai
 * removed!
 * fix build warnings.
 *
 * 09 22 2011 chelun.tsai
 * removed!
 * .
 *
 * 09 16 2011 chelun.tsai
 * removed!
 * .
 *
 * 08 17 2011 chelun.tsai
 * removed!
 * .
 *
 * 05 27 2011 chelun.tsai
 * removed!
 * MT6526 E2 MDP driver.
 *
 * 05 05 2011 chelun.tsai
 * removed!
 * last check in befor sample back.
 *
 * 01 07 2011 chrono.wu
 * removed!
 * .
 *
 * 12 06 2010 gellmann.chang
 * removed!
 * .
 *
 * 11 23 2010 gellmann.chang
 * removed!
 * .
 *
 * 10 18 2010 holmes.chiou
 * removed!
 * .
 *
 * removed!
 * removed!
 * MT6255 HQA check-in
 *
 * removed!
 * removed!
 * DVT check-in
 *
 * removed!
 * removed!
 * MDP driver
 *
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_imgdma_jpgdma_mt6256_e2_h__
#define __idp_imgdma_jpgdma_mt6256_e2_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include <idp_define.h>
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
/* 6236 register definition of JPG_DMA */
#ifndef MDP_C_MODEL

#define JPG_DMA_BASE                   JPEG_DMA_base

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

#else //#ifndef MDP_C_MODEL

#define REG_IMGDMA_JPG_DMA_STOP           (JPEG_DMA_STOP)
#define REG_IMGDMA_JPG_DMA_EN             (JPEG_DMA_EN)
#define REG_IMGDMA_JPG_DMA_RESET          (JPEG_DMA_RESET)
#define REG_IMGDMA_JPG_DMA_CON            (JPEG_DMA_CON)
#define REG_IMGDMA_JPG_DMA_BUF_BASE_ADDR0 (JPEG_DMA_BUF_BASE_ADDR0)
#define REG_IMGDMA_JPG_DMA_BUF_BASE_ADDR1 (JPEG_DMA_BUF_BASE_ADDR1)
#define REG_IMGDMA_JPG_DMA_SIZE           (JPEG_DMA_SIZE)
#define REG_IMGDMA_JPG_DMA_INTERRUPT      (JPEG_DMA_INT)
#define REG_IMGDMA_JPG_DMA_DEBUG_STATUS0  (JPEG_DMA_DEBUG_STATUS0)
#define REG_IMGDMA_JPG_DMA_DEBUG_STATUS1  (JPEG_DMA_DEBUG_STATUS1)
#define REG_IMGDMA_JPG_DMA_DEBUG_STATUS2  (JPEG_DMA_DEBUG_STATUS2)
#define REG_IMGDMA_JPG_DMA_DEBUG_STATUS3  (JPEG_DMA_DEBUG_STATUS3)
#define REG_IMGDMA_JPG_DMA_DEBUG_STATUS4  (JPEG_DMA_DEBUG_STATUS4)
#define REG_IMGDMA_JPG_DMA_DEBUG_STATUS5  (JPEG_DMA_DEBUG_STATUS5)
#define REG_IMGDMA_JPG_DMA_DEBUG_STATUS6  (JPEG_DMA_DEBUG_STATUS6)
#define REG_IMGDMA_JPG_DMA_DEBUG_STATUS7  (JPEG_DMA_DEBUG_STATUS7)

#endif //#ifndef MDP_C_MODEL

// Start JPG_DMA
#define IMGDMA_JPG_DMA_START() \
    do { REG_IMGDMA_JPG_DMA_EN = 0x1; } while(0)

// Stop JPG_DMA at frame end. MUST polling REG_IMGDMA_JPG_DMA_EN
#define IMGDMA_JPG_DMA_STOP() \
    do { REG_IMGDMA_JPG_DMA_STOP = 0x1; } while(0)

// Warm reset JPG_DMA. Engine will wait for pending GMC transaction to avoid state machine error...
#define IMGDMA_JPG_DMA_WARM_RESET() \
    do { REG_IMGDMA_JPG_DMA_RESET = 0x2; } while(0)

#define IMGDMA_JPG_DMA_WARM_RESET_BUSY_WAIT() \
    while ( 0x20000 == (REG_IMGDMA_JPG_DMA_RESET & 0x20000) )

// Hard reset JPG_DMA. Engine will not wait for pending GMC transaction. SW needs to wait for while...
//#define IMGDMA_JPG_DMA_HARD_RESET() \
//    do { REG_IMGDMA_JPG_DMA_RESET = 0x1; \
//         REG_IMGDMA_JPG_DMA_RESET = 0x0; } while(0)

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
    do { REG_IMGDMA_JPG_DMA_CON |= 0x08; } while(0)

/**
 * \brief disable auto restarting of the JPEG DMA
 */
#define IMGDMA_JPG_DMA_AUTO_RSTR_DISABLE() \
    do { REG_IMGDMA_JPG_DMA_CON &= ~0x08; } while(0)

/**
 * \brief enable FIFO mode the JPEG DMA
 */
#define IMGDMA_JPG_DMA_FIFO_MODE_ENABLE() \
    do { REG_IMGDMA_JPG_DMA_CON |= 0x0100; } while(0)

/**
 * \brief disable FIFO mode the JPEG DMA
 */
#define IMGDMA_JPG_DMA_FIFO_MODE_DISABLE() \
    do { REG_IMGDMA_JPG_DMA_CON &= ~0x0100; } while(0)

/**
 * \brief enable DOUBLE mode the JPEG DMA
 */
#define IMGDMA_JPG_DMA_DOUBLE_MODE_ENABLE() \
    do { REG_IMGDMA_JPG_DMA_CON |= 0x0200; } while(0)

/**
 * \brief disable DOUBLE mode the JPEG DMA
 */
#define IMGDMA_JPG_DMA_DOUBLE_MODE_DISABLE() \
    do { REG_IMGDMA_JPG_DMA_CON &= ~0x0200; } while(0)

// Enable interrupt
#define IMGDMA_JPG_DMA_INT_ENABLE() \
    do { REG_IMGDMA_JPG_DMA_CON |= 0x01; } while(0)

// Disable interrupt
#define IMGDMA_JPG_DMA_INT_DISABLE() \
    do { REG_IMGDMA_JPG_DMA_CON &= ~0x01; } while(0)

// Enable ISP frame sync
#define IMGDMA_JPG_DMA_ISP_FRAME_SYNC_ENABLE() \
    do { REG_IMGDMA_JPG_DMA_CON |= 0x0080; } while(0)

// Disable ISP frame sync
#define IMGDMA_JPG_DMA_ISP_FRAME_SYNC_DISABLE() \
    do { REG_IMGDMA_JPG_DMA_CON &= ~0x0080; } while(0)
    
// Set JPEG DMA source size
#define IMGDMA_JPG_DMA_SET_SRC_SIZE(width, height) \
    do { REG_IMGDMA_JPG_DMA_SIZE = (((width)&0xffff) | (((height)&0xffff)<<16)); } while(0)

/**
 * \brief JPG_DMA structure
 *
 * Programmers can use this structure to set up JPG_DMA.
 */
typedef struct
{
    idp_module_enum_t         input_src;
    kal_bool                  restart; /**< 1: automatic reastart while current frame is finished */
    kal_bool                  intr_en; /**< int */
    kal_bool                  frame_sync_en;
    
    idp_lisr_intr_cb_t        intr_cb;
    idp_lisr_intr_cb_param_t  intr_cb_param;

    kal_uint16                target_width; /**< target width before padding, padding according to YUV mode */
    kal_uint16                target_height; /**< target height */
    img_color_fmt_yuv_enum_t  yuv_fmt;
    kal_uint32                wm_addr_0; /**< the address of 1st working buffer. */
    kal_uint32                wm_addr_1; /**< the address of 2nd working buffer. Should be on differnt bank */
    
    /* Below private data, not updated by client */
    kal_bool                  fifo_mode;
    kal_bool                  double_buffer_mode; //if true=> double buffer mode
    kal_uint32                _single_working_buffer_size; /**< padded width * bpp * number of lines */
    
} idp_imgdma_jpgdma_struct;

IDP_HW_COMMON_API_DECLARATION(imgdma_jpgdma)

extern void *idp_imgdma_jpgdma_intr_cb_param;
extern void (*idp_imgdma_jpgdma_intr_cb)(void *);

extern kal_bool idp_imgdma_jpgdma_config_real(
  idp_imgdma_jpgdma_struct * const jpgdma_struct, 
    kal_bool const config_to_hardware);

extern kal_bool idp_imgdma_jpgdma_get_working_mem_real(
  kal_bool const use_internal_mem,
  idp_imgdma_jpgdma_struct * const jpgdma_struct,
  kal_bool const do_alloc,
  kal_uint32 const max_allowable_size);

extern void
idp_imgdma_jpgdma_open_real(void);

extern kal_bool
idp_imgdma_jpgdma_start_real(
    idp_imgdma_jpgdma_struct const * const p_jpgdma_struct);

extern kal_bool
idp_imgdma_jpgdma_stop_real(
    idp_imgdma_jpgdma_struct const * const p_jpgdma_struct);

extern kal_bool
idp_imgdma_jpgdma_is_busy_real(
    kal_bool * const busy,
    idp_imgdma_jpgdma_struct const * const p_jpgdma_struct);

extern kal_bool
idp_imgdma_jpgdma_get_working_mem_size_real(
    idp_imgdma_jpgdma_struct * const p_jpgdma_struct,
    kal_uint32 * const p_size);


#endif // __idp_imgdma_jpgdma_mt6256_e2_h__

