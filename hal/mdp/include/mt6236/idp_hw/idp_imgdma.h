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
 *    idp_imgdma.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    The header file for common parts of IMGDMA engines.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/** 
 * \defgroup idp Image data path
 * \brief This module defines image data path
 * @{
 */
/** 
 * \defgroup imgdma Image DMA
 * \brief This module defines image DMA.
 * @{
 */
#ifndef __idp_imgdma_mt6236_h__
#define __idp_imgdma_mt6236_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

/*****************************************************************************
 * include directives
 *****************************************************************************/
#include <idp_define.h>
#include "idp_core.h"
#include "img_common_enum.h"
#include "idp_hw_common.h"
#include "reg_base.h"

#if defined(DRV_IDP_MT6236_SERIES)

/*****************************************************************************
 * macros and compile options
 *****************************************************************************/
#define RDMA_MAX_INPUT_WIDTH         (65535)
#define RDMA_MAX_INPUT_HEIGHT        (65535)
#define WDMA_MAX_OUTPUT_WIDTH        (65535)
#define WDMA_MAX_OUTPUT_HEIGHT       (65535)

/*****************************************************************************
 * register definitions & macros
 *****************************************************************************/
#define MMSYS_CONFIG_BASE                         (MMCONFG_base)

#define MMSYS_IDP_INT_FLAG_REG                    (MMSYS_CONFIG_BASE + 0x0514)
#define MMSYS_IDP_REQ_FLAG_REG                    (MMSYS_CONFIG_BASE + 0x0520)
#define MMSYS_IDP_INT_FLAG_CLR_REG                (MMSYS_CONFIG_BASE + 0x051c)
#define MMSYS_IDP_LCD_OSEL_REG                    (MMSYS_CONFIG_BASE + 0x0500)

#define REG_MMSYS_IDP_INT_FLAG                    *((volatile unsigned int *) MMSYS_IDP_INT_FLAG_REG)
#define REG_MMSYS_IDP_REQ_FLAG                    *((volatile unsigned int *) MMSYS_IDP_REQ_FLAG_REG)
#define REG_MMSYS_IDP_INT_FLAG_CLR                *((volatile unsigned int *) MMSYS_IDP_INT_FLAG_CLR_REG)
#define REG_MMSYS_IDP_LCD_OSEL                    *((volatile unsigned int *) MMSYS_IDP_LCD_OSEL_REG)

// bit mapping of MMSYS IDP interrupt flag
#define MMSYS_IDP_ROT_DMA1_INT_FLAG               0x00000001
#define MMSYS_IDP_ROT_DMA0_INT_FLAG               0x00000002
#define MMSYS_IDP_R_DMA1_INT_FLAG                 0x00000004
#define MMSYS_IDP_R_DMA0_INT_FLAG                 0x00000008
#define MMSYS_IDP_W_DMA2_INT_FLAG                 0x00000010
#define MMSYS_IDP_W_DMA1_INT_FLAG                 0x00000020
#define MMSYS_IDP_W_DMA0_INT_FLAG                 0x00000040
#define MMSYS_IDP_OVL_DMA_INT_FLAG                0x00000080
#define MMSYS_IDP_JPEG_DMA_INT_FLAG               0x00000100

#define MMSYS_IDP_LCD_OSEL_LCD_FLAG               0x00000001
#define MMSYS_IDP_LCD_OSEL_GOVL_FLAG              0x00000002

#define IMGDMA_ACK_ROT_DMA1_INT()                 do { REG_MMSYS_IDP_INT_FLAG_CLR |= MMSYS_IDP_ROT_DMA1_INT_FLAG; } while(0)
#define IMGDMA_ACK_ROT_DMA0_INT()                 do { REG_MMSYS_IDP_INT_FLAG_CLR |= MMSYS_IDP_ROT_DMA0_INT_FLAG; } while(0)
#define IMGDMA_ACK_R_DMA1_INT()                   do { REG_MMSYS_IDP_INT_FLAG_CLR |= MMSYS_IDP_R_DMA1_INT_FLAG; } while(0)
#define IMGDMA_ACK_R_DMA0_INT()                   do { REG_MMSYS_IDP_INT_FLAG_CLR |= MMSYS_IDP_R_DMA0_INT_FLAG; } while(0)
#define IMGDMA_ACK_W_DMA2_INT()                   do { REG_MMSYS_IDP_INT_FLAG_CLR |= MMSYS_IDP_W_DMA2_INT_FLAG; } while(0)
#define IMGDMA_ACK_W_DMA1_INT()                   do { REG_MMSYS_IDP_INT_FLAG_CLR |= MMSYS_IDP_W_DMA1_INT_FLAG; } while(0)
#define IMGDMA_ACK_W_DMA0_INT()                   do { REG_MMSYS_IDP_INT_FLAG_CLR |= MMSYS_IDP_W_DMA0_INT_FLAG; } while(0)
#define IMGDMA_ACK_OVL_DMA_INT()                  do { REG_MMSYS_IDP_INT_FLAG_CLR |= MMSYS_IDP_OVL_DMA_INT_FLAG; } while(0)
#define IMGDMA_ACK_JPEG_DMA_INT()                 do { REG_MMSYS_IDP_INT_FLAG_CLR |= MMSYS_IDP_JPEG_DMA_INT_FLAG; } while(0)

// bit mapping of IMGDMA INTERRUPT
#define IMGDMA_INTERRUPT_INTEN_BIT                0x00000001
#define IMGDMA_INTERRUPT_INTFREQ_MASK             0x000000f0
#define IMGDMA_INTERRUPT_INTCNT_MASK              0x00000f00

// bit mapping of IMGDMA CFG
#define IMGDMA_CFG_AUTO_LOOP_BIT                  0x00000001
#define IMGDMA_CFG_MODE_BIT                       0x00000080
#define IMGDMA_CFG_FRAME_SYNC_EN_BIT              0x80000000

/**
 * WDMA bit/masks
 */
// bit mapping of WDMA0/1 LCD 
#define IMGDMA_WDMA_LCD_HWTRIG_BIT                0x00000001
#define IMGDMA_WDMA_LCD_HWSYNC_BIT                0x00000002
#define IMGDMA_WDMA_LCD_HWSYNCFULL_MASK           0x0000000c
/**
 * \def IMGDMA_WDMA_LCD_HWSYNCFULL_STALL 
 * When LCD not done, WDMA is stalled. 
 */
#define IMGDMA_WDMA_LCD_HWSYNCFULL_STALL          0x00000000
/**
 * \def IMGDMA_WDMA_LCD_HWSYNCFULL_REDRAW
 * When LCD not done, WDMA redraws the current output buffer. 
 */
#define IMGDMA_WDMA_LCD_HWSYNCFULL_REDRAW         0x00000004
/**
 * \def IMGDMA_WDMA_LCD_HWSYNCFULL_DROP
 * When LCD not done, WDMA not redraw but drop incoming frame. 
 */
#define IMGDMA_WDMA_LCD_HWSYNCFULL_DROP           0x00000008

/* bit mapping of WDMA output selection */
#define IMGDMA_WDMA_OUT_SEL_OUT1_BIT              0x00000002 /**< WDMA output to GMC (external memory) */
#define IMGDMA_WDMA_OUT_SEL_OUT2_BIT              0x00000004 /**< WDMA output to next engine */

/* bit mapping of WDMA output format */
#define IMGDMA_WDMA_CON_OUTPUT_FORMAT_MASK        0x00000007
#define IMGDMA_WDMA_CON_OUTPUT_FORMAT_ARGB8888    0x00000000
#define IMGDMA_WDMA_CON_OUTPUT_FORMAT_RGB888      0x00000001
#define IMGDMA_WDMA_CON_OUTPUT_FORMAT_RGB565      0x00000002
#define IMGDMA_WDMA_CON_OUTPUT_FORMAT_BGR888      0x00000003
#define IMGDMA_WDMA_CON_OUTPUT_FORMAT_YUYV422     0x00000004
#define IMGDMA_WDMA_CON_OUTPUT_FORMAT_YUV         0x00000005 /**< The sub sampling rate is defined by VH, UH, YH, VV, UV, YV */
#define IMGDMA_WDMA_CON_A_VALUE_MASK              0x0000ff00
#define IMGDMA_WDMA_CON_ROUND_BIT                 0x00000008 /**< rounding when output RGB format */

/* bit mapping of RDMA input format mask */
#define IMGDMA_RDMA_CON_INPUT_FORMAT_MASK         0x00000007
#define IMGDMA_RDMA_CON_INPUT_FORMAT_ARGB8888     0x00000000
#define IMGDMA_RDMA_CON_INPUT_FORMAT_RGB888       0x00000001
#define IMGDMA_RDMA_CON_INPUT_FORMAT_RGB565       0x00000002
#define IMGDMA_RDMA_CON_INPUT_FORMAT_BGR888       0x00000003
#define IMGDMA_RDMA_CON_INPUT_FORMAT_YUYV422      0x00000004
#define IMGDMA_RDMA_CON_INPUT_FORMAT_YUV          0x00000005 /**< The sub sampling rate is defined by VH, UH, YH, VV, UV, YV */
#define IMGDMA_RDMA_CON_ROUND_BIT                 0x00000008 /**< rounding when output RGB format */

//// Macro for computing the start addresses for U, V plane
//// Directly from spec P.5/135 of V1.10
#define SAMPLE_SHIFT(sample_code) \
    (kal_uint32)((0 == (kal_uint32)(sample_code)) ? 0 : ((kal_uint32)(sample_code) - 1))

/*
 * _rdma_: 0, 1
 */
#define IMGDMA_RDMA_DESC_SEG_0_Y_SRC_STR_ADDR_EN(_rdma_) \
  do { REG_IMGDMA_RDMA##_rdma_##_CFG |= 0x10000; } while(0)

#define IMGDMA_RDMA_DESC_SEG_0_Y_SRC_STR_ADDR_DIS(_rdma_) \
  do { REG_IMGDMA_RDMA##_rdma_##_CFG &= ~0x10000; } while(0)

#define IMGDMA_RDMA_DESC_SEG_1_U_SRC_STR_ADDR_EN(_rdma_) \
  do { REG_IMGDMA_RDMA##_rdma_##_CFG |= 0x20000; } while(0)

#define IMGDMA_RDMA_DESC_SEG_1_U_SRC_STR_ADDR_DIS(_rdma_) \
  do { REG_IMGDMA_RDMA##_rdma_##_CFG &= ~0x20000; } while(0)

#define IMGDMA_RDMA_DESC_SEG_2_V_SRC_STR_ADDR_EN(_rdma_) \
  do { REG_IMGDMA_RDMA##_rdma_##_CFG |= 0x40000; } while(0)

#define IMGDMA_RDMA_DESC_SEG_2_V_SRC_STR_ADDR_DIS(_rdma_) \
  do { REG_IMGDMA_RDMA##_rdma_##_CFG &= ~0x40000; } while(0)

#define IMGDMA_RDMA_DESC_SEG_3_SRC_SIZE_ADDR_EN(_rdma_) \
  do { REG_IMGDMA_RDMA##_rdma_##_CFG |= 0x80000; } while(0)

#define IMGDMA_RDMA_DESC_SEG_3_SRC_SIZE_ADDR_DIS(_rdma_) \
  do { REG_IMGDMA_RDMA##_rdma_##_CFG &= ~0x80000; } while(0)

#define IMGDMA_RDMA_DESC_SEG_4_SRC_W_IN_BYTE_EN(_rdma_) \
  do { REG_IMGDMA_RDMA##_rdma_##_CFG |= 0x100000; } while(0)

#define IMGDMA_RDMA_DESC_SEG_4_SRC_W_IN_BYTE_DIS(_rdma_) \
  do { REG_IMGDMA_RDMA##_rdma_##_CFG &= ~0x100000; } while(0)

#define IMGDMA_RDMA_DESC_SEG_5_CLIP_SIZE_EN(_rdma_) \
  do { REG_IMGDMA_RDMA##_rdma_##_CFG |= 0x200000; } while(0)

#define IMGDMA_RDMA_DESC_SEG_5_CLIP_SIZE_DIS(_rdma_) \
  do { REG_IMGDMA_RDMA##_rdma_##_CFG &= ~0x200000; } while(0)

#define IMGDMA_RDMA_DESC_SEG_6_CLIP_W_IN_BYTE_EN(_rdma_) \
  do { REG_IMGDMA_RDMA##_rdma_##_CFG |= 0x400000; } while(0)

#define IMGDMA_RDMA_DESC_SEG_6_CLIP_W_IN_BYTE_DIS(_rdma_) \
  do { REG_IMGDMA_RDMA##_rdma_##_CFG &= ~0x400000; } while(0)

#define IMGDMA_RDMA_DESC_SEG_7_CON_EN(_rdma_) \
  do { REG_IMGDMA_RDMA##_rdma_##_CFG |= 0x800000; } while(0)

#define IMGDMA_RDMA_DESC_SEG_7_CON_DIS(_rdma_) \
  do { REG_IMGDMA_RDMA##_rdma_##_CFG &= ~0x800000; } while(0)

/*****************************************************************************
 * type definitions
 *****************************************************************************/
typedef struct
{
    kal_uint32                y_start_addr;
    kal_uint32                u_start_addr;
    kal_uint32                v_start_addr;
} idp_yuv_base_addr;

/**
 * \brief R_DMA structure
 *
 * Programmers can use this structure to set up R_DMA0 and R_DMA1.
 */
typedef struct 
{
    kal_bool                  descriptor_mode; /**< KAL_TRUE for descriptor mode, KAL_FALSE for register mode (default). */

    kal_bool                  bypass;
    kal_bool                  stall_prev_engine;
    kal_bool                  drop_prev_engine;

    kal_bool                  auto_loop; /**< auto loop */

    kal_bool                  frame_sync_en;

    kal_bool                  rgb_rounding; /**< enable RGB rounding, only use when KAL_TRUE == output_rgb */
    
    kal_bool                  input_from_memory;
    
    /* Configs for register mode. */
#if 0   // Replaced by src_color_fmt.
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // #if 0
    kal_uint32                src_color_fmt; /**< img_color_fmt_rgb_enum_t or img_color_fmt_yuv_enum_t */
  
    kal_uint32                y_base_addr; /**< y base address */
    kal_uint32                u_base_addr; /**< u base address */
    kal_uint32                v_base_addr; /**< v base address */
    
    kal_uint32                pixel_number; /**< pixel numbers. deprecated? */
    kal_uint16                source_width; /**< 16 bit unsigned. */
    kal_uint16                source_height; /**< 16 bit unsigned. */

    kal_bool                  pitch_enable; /**< pitch */
    kal_uint16                pitch_bytes; /**< horizontal pitch WARNING! the pitch is applied to three buffers */ 
    
    kal_bool                  clip; /**< clip enable, this was called "pan" in MT6238 */
    kal_uint16                clip_left; /**< start from 0. */
    kal_uint16                clip_right; /**< max. value: (source width) - 1. */
    kal_uint16                clip_top; /**< start from 0. */
    kal_uint16                clip_bottom; /**< max. value: (source height) - 1. */

    /* Common config for both descriptor and register modes. */
    kal_bool                  intr_en; /**< interrupt enable. */
    idp_lisr_intr_cb_t        intr_cb; /**< interrupt callback function pointer. */
    idp_lisr_intr_cb_param_t  intr_cb_param; /**< interrupt callback function param. */

    /* private section, client must not modify below members. */
    
    kal_uint32                _y_str_addr;
    kal_uint32                _u_str_addr;
    kal_uint32                _v_str_addr;

    //// For easy debugging...
    kal_uint8                 _yh;
    kal_uint8                 _yv;
    kal_uint8                 _uh;
    kal_uint8                 _uv;
    kal_uint8                 _vh;
    kal_uint8                 _vv;
}idp_imgdma_rdma_struct;

typedef struct
{
    kal_bool                  intr_en; /**< interrupt */
    idp_lisr_intr_cb_t        intr_cb;
    idp_lisr_intr_cb_param_t  intr_cb_param;

    kal_bool                  bypass;
    kal_bool                  stall_prev_engine;
    kal_bool                  drop_prev_engine;

    kal_bool                  output_to_memory;
    kal_bool                  output_to_next_engine; /**< MOUT for WDMA0, ROT_DMA0 for WDMA1, none for WDMA2 */
    
    kal_bool                  auto_loop; /**< auto loop */

    kal_bool                  frame_sync_en;

    kal_bool                  rgb_rounding; /**< enable RGB rounding, only use when KAL_TRUE == output_rgb */
    
    kal_bool                  hw_trigger_lcd; /**< Not HW trigger LCD or HW sync w/ LCD (drop mode), only for WDMA0 and WDM1 */
    idp_lcd_hw_trigger_mode_t hw_trigger_mode;
    kal_bool                  hw_trigger_rst_wait_lcd;

#if 0   // Replaced by dest_color_fmt...
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // #if 0
    kal_uint32                dest_color_fmt; /**< img_color_fmt_rgb_enum_t or img_color_fmt_yuv_enum_t */
    
    kal_uint8                 alpha_value;

    kal_uint8                 reg_mode_queue_depth; /**< if reg mode, [1, 3] */
    idp_yuv_base_addr         dest[3];

    /* 0th set of destination start addresses */
    kal_uint32                dest_base_address_0_y; /**< If RGB output format is used, this is the destination start address of RGB buffer 0 */
    kal_uint32                dest_base_address_0_u;
    kal_uint32                dest_base_address_0_v;

    /* 1st set of destination start addresses */
    kal_uint32                dest_base_address_1_y; /**< If RGB output format is used, this is the destination start address of RGB buffer 1 */
    kal_uint32                dest_base_address_1_u;
    kal_uint32                dest_base_address_1_v;

    /* 2nd set of destination start addresses */
    kal_uint32                dest_base_address_2_y; /**< If RGB output format is used, this is the destination start address of RGB buffer 2 */
    kal_uint32                dest_base_address_2_u;
    kal_uint32                dest_base_address_2_v;
    
    kal_uint16                src_width; /**< image width, format alignment */
    kal_uint16                src_height; /**< image height, format alignment */
    
    kal_bool                  pitch_enable; /**< pitch */
    kal_uint16                pitch_w; /**< horizontal pitch WARNING! the pitch is applied to three buffers */ 
    
    kal_bool                  clip; /**< clip enable, this was called "pan" in MT6238 */
    kal_uint16                clip_left;
    kal_uint16                clip_right;
    kal_uint16                clip_top;
    kal_uint16                clip_bottom;

    //// For easy debugging...
    kal_uint8                 _yh;
    kal_uint8                 _yv;
    kal_uint8                 _uh;
    kal_uint8                 _uv;
    kal_uint8                 _vh;
    kal_uint8                 _vv;
} idp_imgdma_wdma_struct;

/**
 * Init IMGDMA HW engines
 */
extern void idp_imgdma_init(void);

/**
 * The LISR for IMGDMA interruption
 */
extern void image_dma_LISR(void);

#endif // #if defined(DRV_IDP_MT6236_SERIES)

#endif // #ifndef __idp_imgdma_mt6236_h__
/** @} */

