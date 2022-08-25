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
 *	 Maui
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
 * 09 30 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 11 23 2010 hung-wen.hsieh
 * removed!
 * .
 *
 * 10 18 2010 ct.fang
 * removed!
 * .
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * add to source control recursely
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_imgdma_jpeg_mt6238_h__
#define __idp_imgdma_jpeg_mt6238_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include "reg_base.h"
#include "drv_features_mdp.h"
#include "drv_comm.h"
#include <idp_define.h>

#if defined(DRV_IDP_6238_SERIES)

#include "idp_imgdma.h"
#include <idp_core.h>
#include "img_common_enum.h"

/* ===================================================
 *                    JPEG DMA
 * =================================================== */

/** \defgroup imgdma_jpeg JPEG DMA
 * @{
 */
/* 6238 register definition of JPEG image DMA */
#define IMGDMA_JPEG_START_REG        (IMGDMA_base + 0x0100)
#define IMGDMA_JPEG_CTRL_REG         (IMGDMA_base + 0x0104)
#define IMGDMA_JPEG_BASE_ADDR_REG    (IMGDMA_base + 0x0108)
#define IMGDMA_JPEG_WIDTH_REG        (IMGDMA_base + 0x010C)
#define IMGDMA_JPEG_HEIGHT_REG       (IMGDMA_base + 0x0110)
#define IMGDMA_JPEG_FIFO_LENGTH_REG  (IMGDMA_base + 0x0114)

#define REG_IMGDMA_JPEG_START        *((volatile unsigned int *)(IMGDMA_base + 0x0100))
#define REG_IMGDMA_JPEG_CTRL         *((volatile unsigned int *)(IMGDMA_base + 0x0104))
#define REG_IMGDMA_JPEG_BASE_ADDR    *((volatile unsigned int *)(IMGDMA_base + 0x0108))
#define REG_IMGDMA_JPEG_WIDTH        *((volatile unsigned int *)(IMGDMA_base + 0x010C))
#define REG_IMGDMA_JPEG_HEIGHT       *((volatile unsigned int *)(IMGDMA_base + 0x0110))
#define REG_IMGDMA_JPEG_FIFO_LENGTH  *((volatile unsigned int *)(IMGDMA_base + 0x0114))

/* bit mapping of JPEG image dma control register */
#define IMGDMA_JPEG_AUTO_RESTART_BIT   0x00000008
#define IMGDMA_JPEG_DATA_FORMAT_MASK   0x00000006
#define IMGDMA_JPEG_INTR_ENABLE_BIT     0x00000001

#define IMGDMA_JPEG_FORMAT_YUV422    0x00000000
#define IMGDMA_JPEG_FORMAT_GRAY      0x00000002
#define IMGDMA_JPEG_FORMAT_YUV420    0x00000004
#define IMGDMA_JPEG_FORMAT_YUV411    0x00000006

/* macros of JPEG image DMA start register */
#define START_IMGDMA_JPEG()  do { REG_IMGDMA_JPEG_START = 1; } while(0)
#define STOP_IMGDMA_JPEG()   do { REG_IMGDMA_JPEG_START = 0; } while(0)

/**
 * \brief Check if JPEG DMA is started or not.
 */
#define IS_IMGDMA_JPEG_START()                      \
  ((0x1 == (REG_IMGDMA_JPEG_START & 0x1))           \
   ? KAL_TRUE                                       \
   : KAL_FALSE)

/* macros of JPEG image DMA control register */
/**
 * \brief enable auto restarting of the JPEG DMA
 */
#define ENABLE_IMGDMA_JPEG_AUTO_RESTART()                               \
  do { REG_IMGDMA_JPEG_CTRL |= IMGDMA_JPEG_AUTO_RESTART_BIT; } while(0)

/**
 * \brief disable auto restarting of the JPEG DMA
 */
#define DISABLE_IMGDMA_JPEG_AUTO_RESTART()                              \
  do { REG_IMGDMA_JPEG_CTRL &= ~IMGDMA_JPEG_AUTO_RESTART_BIT; } while(0)

#define SET_IMGDMA_JPEG_YUV422()                                        \
  do { REG_IMGDMA_JPEG_CTRL &= ~IMGDMA_JPEG_DATA_FORMAT_MASK; } while(0)

#define SET_IMGDMA_JPEG_YUV420()                                  \
  do { REG_IMGDMA_JPEG_CTRL &= ~IMGDMA_JPEG_DATA_FORMAT_MASK;     \
    REG_IMGDMA_JPEG_CTRL |= IMGDMA_JPEG_FORMAT_YUV420; } while(0)

#define SET_IMGDMA_JPEG_YUV411()                                  \
  do { REG_IMGDMA_JPEG_CTRL &= ~IMGDMA_JPEG_DATA_FORMAT_MASK;     \
    REG_IMGDMA_JPEG_CTRL |= IMGDMA_JPEG_FORMAT_YUV411; } while(0)

#define SET_IMGDMA_JPEG_GRAY()                                  \
  do {REG_IMGDMA_JPEG_CTRL &= ~IMGDMA_JPEG_DATA_FORMAT_MASK;    \
    REG_IMGDMA_JPEG_CTRL |= IMGDMA_JPEG_FORMAT_GRAY; } while(0)

#define ENABLE_IMGDMA_JPEG_INT()                                      \
  do { REG_IMGDMA_JPEG_CTRL |= IMGDMA_JPEG_INTR_ENABLE_BIT; } while(0)

#define DISABLE_IMGDMA_JPEG_INT()                                       \
  do { REG_IMGDMA_JPEG_CTRL &= ~IMGDMA_JPEG_INTR_ENABLE_BIT; } while(0)

#define JPEG_FORMAT_GRAY 0
#define JPEG_FORMAT_YUV422 1
#define JPEG_FORMAT_YUV420 2
#define JPEG_FORMAT_YUV411 3

enum idp_imgdma_jpeg_error_code_t
{
  IDP_IMGDMA_JPEG_NO_ERROR,
  IDP_IMGDMA_JPEG_ERROR_CODE_NOT_ENOUGH_WORKING_MEM
};
typedef enum idp_imgdma_jpeg_error_code_t idp_imgdma_jpeg_error_code_t;

enum
{
  IDP_IMGDMA_JPEG_QUERY_ERROR_CODE = 1
};

/**
 * \brief JPEG DMA structure
 *
 * Programmers can use this structure to set up JPEG DMA.
 */
typedef struct
{
  kal_bool                  restart; /**< 1: automatic reastart while current frame is finished */

  kal_bool                  intr_en; /**< int */
  idp_lisr_intr_cb_t        intr_cb;
  idp_lisr_intr_cb_param_t  intr_cb_param;

  kal_uint32                jpeg_file_buffer_address; /**< the start address of JPEG file located */
  kal_uint16                target_width; /**< the width of target image */
  kal_uint16                target_height; /**< the height of target image */
  kal_uint16                fifo_size; /**< FIFO size */
  //img_color_fmt_yuv_enum_t  jpeg_yuv_mode; /**< YUV420, YUV422 or Gray mode */
  kal_uint32				jpeg_yuv_mode; /**< YUV420, YUV422 or Gray mode */

#if defined(DRV_IDP_FEATURE__HW_FRAME_SYNC)
  kal_bool                  hw_frame_sync; /**< KAL_TRUE: enable HW frame sync; KAL_FALSE: disable. */
#endif // #if defined(DRV_IDP_FEATURE__HW_FRAME_SYNC)
} idp_imgdma_jpeg_struct;

IDP_HW_COMMON_API_DECLARATION(imgdma_jpeg)

extern void *idp_imgdma_jpeg_intr_cb_param;
extern void (*idp_imgdma_jpeg_intr_cb)(void *);

extern kal_bool idp_imgdma_jpeg_config_real(
    idp_imgdma_jpeg_struct * const jpeg_struct,
    kal_bool const config_to_hardware);

extern kal_bool idp_imgdma_jpeg_stop_real(
  idp_imgdma_jpeg_struct const * const jpeg_struct);

extern kal_bool idp_imgdma_jpeg_get_working_mem_real(
  kal_bool const use_internal_mem,
  idp_imgdma_jpeg_struct * const jpeg_struct,
  kal_bool const do_alloc,
  kal_uint32 const max_allowable_size);

extern void idp_imgdma_jpeg_close_real(void);

/** @} */

#endif // defined(DRV_IDP_6238_SERIES)

#endif // __idp_imgdma_jpeg_mt6238_h__
