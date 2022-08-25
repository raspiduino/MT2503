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
 *    idp_imgdma_wdma2.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    
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

#ifndef __idp_imgdma_wdma2_mt6236_h__
#define __idp_imgdma_wdma2_mt6236_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include <idp_define.h>

#if defined(DRV_IDP_MT6236_SERIES)

#include <idp_core.h>
#include "idp_imgdma.h"
#include "img_common_enum.h"
#include "reg_base.h"

/* ===================================================
 *                        WDMA2
 * =================================================== */

/** \defgroup imgdma_wdma2 WDMA2
 * @{
 */
#define W_DMA2_BASE                           (W_DMA2_base)
// W_DMA0 register addresses
#define IMGDMA_WDMA2_STATUS_FLAG_REG          (W_DMA2_BASE + 0x0000)
#define IMGDMA_WDMA2_STATUS_FLAG_CLR_REG      (W_DMA2_BASE + 0x1020)
#define IMGDMA_WDMA2_INTERRUPT_REG            (W_DMA2_BASE + 0x0004)
#define IMGDMA_WDMA2_CFG_REG                  (W_DMA2_BASE + 0x0008)
#define IMGDMA_WDMA2_LCD_REG                  (W_DMA2_BASE + 0x000c)
#define IMGDMA_WDMA2_OUT_SEL_REG              (W_DMA2_BASE + 0x0010)
#define IMGDMA_WDMA2_STOP_REG                 (W_DMA2_BASE + 0x0014)
#define IMGDMA_WDMA2_EN_REG                   (W_DMA2_BASE + 0x0018)
#define IMGDMA_WDMA2_RESET_REG                (W_DMA2_BASE + 0x001c)
#define IMGDMA_WDMA2_QUEUE_RSTA_REG           (W_DMA2_BASE + 0x0020)
#define IMGDMA_WDMA2_QUEUE_WSTA_REG           (W_DMA2_BASE + 0x0024)
#define IMGDMA_WDMA2_QUEUE_DATA_REG           (W_DMA2_BASE + 0x0028)
#define IMGDMA_WDMA2_QUEUE_BASE_REG           (W_DMA2_BASE + 0x002c)
#define IMGDMA_WDMA2_LCD_RPT_REG              (W_DMA2_BASE + 0x0030)
#define IMGDMA_WDMA2_EXEC_CNT_REG             (W_DMA2_BASE + 0x0034)
#define IMGDMA_WDMA2_Y_DST_STR_ADDR0_REG      (W_DMA2_BASE + 0x0040)
#define IMGDMA_WDMA2_U_DST_STR_ADDR0_REG      (W_DMA2_BASE + 0x0044)
#define IMGDMA_WDMA2_V_DST_STR_ADDR0_REG      (W_DMA2_BASE + 0x0048)
#define IMGDMA_WDMA2_Y_DST_STR_ADDR1_REG      (W_DMA2_BASE + 0x004c)
#define IMGDMA_WDMA2_U_DST_STR_ADDR1_REG      (W_DMA2_BASE + 0x0050)
#define IMGDMA_WDMA2_V_DST_STR_ADDR1_REG      (W_DMA2_BASE + 0x0054)
#define IMGDMA_WDMA2_Y_DST_STR_ADDR2_REG      (W_DMA2_BASE + 0x0058)
#define IMGDMA_WDMA2_U_DST_STR_ADDR2_REG      (W_DMA2_BASE + 0x005c)
#define IMGDMA_WDMA2_V_DST_STR_ADDR2_REG      (W_DMA2_BASE + 0x0060)
#define IMGDMA_WDMA2_SRC_SIZE_REG             (W_DMA2_BASE + 0x0064)
#define IMGDMA_WDMA2_CLIP_OFFSET_REG          (W_DMA2_BASE + 0x0068)
#define IMGDMA_WDMA2_CLIP_SIZE_REG            (W_DMA2_BASE + 0x006c)
#define IMGDMA_WDMA2_DST_SIZE_REG             (W_DMA2_BASE + 0x0070)
#define IMGDMA_WDMA2_CON_REG                  (W_DMA2_BASE + 0x0074)
#define IMGDMA_WDMA2_CUR_SRC_POSITION_REG     (W_DMA2_BASE + 0x007c)
#define IMGDMA_WDMA2_SLOW_DOWN_REG            (W_DMA2_BASE + 0x0078)
#define IMGDMA_WDMA2_DBG_ST0_REG              (W_DMA2_BASE + 0x0090)
#define IMGDMA_WDMA2_DBG_ST1_REG              (W_DMA2_BASE + 0x0094)
#define IMGDMA_WDMA2_DBG_ST2_REG              (W_DMA2_BASE + 0x0098)
#define IMGDMA_WDMA2_DBG_ST3_REG              (W_DMA2_BASE + 0x009c)
#define IMGDMA_WDMA2_DBG_ST4_REG              (W_DMA2_BASE + 0x00a0)
#define IMGDMA_WDMA2_DBG_ST5_REG              (W_DMA2_BASE + 0x00a4)
#define IMGDMA_WDMA2_DBG_ST6_REG              (W_DMA2_BASE + 0x00a8)
#define IMGDMA_WDMA2_DBG_ST7_REG              (W_DMA2_BASE + 0x00ac)
#define IMGDMA_WDMA2_DBG_ST8_REG              (W_DMA2_BASE + 0x00b0)
#define IMGDMA_WDMA2_RPT_ADV_REG              (W_DMA2_BASE + 0x1000)
#define IMGDMA_WDMA2_WPT_ADV_REG              (W_DMA2_BASE + 0x1004)
#define IMGDMA_WDMA2_LCD_RPTADV_REG           (W_DMA2_BASE + 0x1008)
#define IMGDMA_WDMA2_LCD_SLOW_FRM_REG         (W_DMA2_BASE + 0x1010)
#define IMGDMA_WDMA2_LCD_RESET_REG            (W_DMA2_BASE + 0x100c)

// W_DMA2 register accesses
#if !defined(MDP_C_MODEL)
#define REG_IMGDMA_WDMA2_STATUS_FLAG          *((volatile unsigned int *)IMGDMA_WDMA2_STATUS_FLAG_REG)
#define REG_IMGDMA_WDMA2_STATUS_FLAG_CLR      *((volatile unsigned int *)IMGDMA_WDMA2_STATUS_FLAG_CLR_REG)
#define REG_IMGDMA_WDMA2_INTERRUPT            *((volatile unsigned int *)IMGDMA_WDMA2_INTERRUPT_REG)
#define REG_IMGDMA_WDMA2_CFG                  *((volatile unsigned int *)IMGDMA_WDMA2_CFG_REG)
#define REG_IMGDMA_WDMA2_LCD                  *((volatile unsigned int *)IMGDMA_WDMA2_LCD_REG)
#define REG_IMGDMA_WDMA2_OUT_SEL              *((volatile unsigned int *)IMGDMA_WDMA2_OUT_SEL_REG)
#define REG_IMGDMA_WDMA2_STOP                 *((volatile unsigned int *)IMGDMA_WDMA2_STOP_REG)
#define REG_IMGDMA_WDMA2_EN                   *((volatile unsigned int *)IMGDMA_WDMA2_EN_REG)
#define REG_IMGDMA_WDMA2_RESET                *((volatile unsigned int *)IMGDMA_WDMA2_RESET_REG)
#define REG_IMGDMA_WDMA2_QUEUE_RSTA           *((volatile unsigned int *)IMGDMA_WDMA2_QUEUE_RSTA_REG)
#define REG_IMGDMA_WDMA2_QUEUE_WSTA           *((volatile unsigned int *)IMGDMA_WDMA2_QUEUE_WSTA_REG)
#define REG_IMGDMA_WDMA2_QUEUE_DATA           *((volatile unsigned int *)IMGDMA_WDMA2_QUEUE_DATA_REG)
#define REG_IMGDMA_WDMA2_QUEUE_BASE           *((volatile unsigned int *)IMGDMA_WDMA2_QUEUE_BASE_REG)
#define REG_IMGDMA_WDMA2_LCD_RPT              *((volatile unsigned int *)IMGDMA_WDMA2_LCD_RPT_REG)
#define REG_IMGDMA_WDMA2_EXEC_CNT             *((volatile unsigned int *)IMGDMA_WDMA2_EXEC_CNT_REG)
#define REG_IMGDMA_WDMA2_Y_DST_STR_ADDR0      *((volatile unsigned int *)IMGDMA_WDMA2_Y_DST_STR_ADDR0_REG)
#define REG_IMGDMA_WDMA2_U_DST_STR_ADDR0      *((volatile unsigned int *)IMGDMA_WDMA2_U_DST_STR_ADDR0_REG)
#define REG_IMGDMA_WDMA2_V_DST_STR_ADDR0      *((volatile unsigned int *)IMGDMA_WDMA2_V_DST_STR_ADDR0_REG)
#define REG_IMGDMA_WDMA2_Y_DST_STR_ADDR1      *((volatile unsigned int *)IMGDMA_WDMA2_Y_DST_STR_ADDR1_REG)
#define REG_IMGDMA_WDMA2_U_DST_STR_ADDR1      *((volatile unsigned int *)IMGDMA_WDMA2_U_DST_STR_ADDR1_REG)
#define REG_IMGDMA_WDMA2_V_DST_STR_ADDR1      *((volatile unsigned int *)IMGDMA_WDMA2_V_DST_STR_ADDR1_REG)
#define REG_IMGDMA_WDMA2_Y_DST_STR_ADDR2      *((volatile unsigned int *)IMGDMA_WDMA2_Y_DST_STR_ADDR2_REG)
#define REG_IMGDMA_WDMA2_U_DST_STR_ADDR2      *((volatile unsigned int *)IMGDMA_WDMA2_U_DST_STR_ADDR2_REG)
#define REG_IMGDMA_WDMA2_V_DST_STR_ADDR2      *((volatile unsigned int *)IMGDMA_WDMA2_V_DST_STR_ADDR2_REG)
#define REG_IMGDMA_WDMA2_SRC_SIZE             *((volatile unsigned int *)IMGDMA_WDMA2_SRC_SIZE_REG)
#define REG_IMGDMA_WDMA2_CLIP_OFFSET          *((volatile unsigned int *)IMGDMA_WDMA2_CLIP_OFFSET_REG)
#define REG_IMGDMA_WDMA2_CLIP_SIZE            *((volatile unsigned int *)IMGDMA_WDMA2_CLIP_SIZE_REG)
#define REG_IMGDMA_WDMA2_DST_SIZE             *((volatile unsigned int *)IMGDMA_WDMA2_DST_SIZE_REG)
#define REG_IMGDMA_WDMA2_CON                  *((volatile unsigned int *)IMGDMA_WDMA2_CON_REG)
#define REG_IMGDMA_WDMA2_CUR_SRC_POSITION     *((volatile unsigned int *)IMGDMA_WDMA2_CUR_SRC_POSITION_REG)
#define REG_IMGDMA_WDMA2_SLOW_DOWN            *((volatile unsigned int *)IMGDMA_WDMA2_SLOW_DOWN_REG)
#define REG_IMGDMA_WDMA2_DBG_ST0              *((volatile unsigned int *)IMGDMA_WDMA2_DBG_ST0_REG)
#define REG_IMGDMA_WDMA2_DBG_ST1              *((volatile unsigned int *)IMGDMA_WDMA2_DBG_ST1_REG)
#define REG_IMGDMA_WDMA2_DBG_ST2              *((volatile unsigned int *)IMGDMA_WDMA2_DBG_ST2_REG)
#define REG_IMGDMA_WDMA2_DBG_ST3              *((volatile unsigned int *)IMGDMA_WDMA2_DBG_ST3_REG)
#define REG_IMGDMA_WDMA2_DBG_ST4              *((volatile unsigned int *)IMGDMA_WDMA2_DBG_ST4_REG)
#define REG_IMGDMA_WDMA2_DBG_ST5              *((volatile unsigned int *)IMGDMA_WDMA2_DBG_ST5_REG)
#define REG_IMGDMA_WDMA2_DBG_ST6              *((volatile unsigned int *)IMGDMA_WDMA2_DBG_ST6_REG)
#define REG_IMGDMA_WDMA2_DBG_ST7              *((volatile unsigned int *)IMGDMA_WDMA2_DBG_ST7_REG)
#define REG_IMGDMA_WDMA2_DBG_ST8              *((volatile unsigned int *)IMGDMA_WDMA2_DBG_ST8_REG)
#define REG_IMGDMA_WDMA2_RPT_ADV              *((volatile unsigned int *)IMGDMA_WDMA2_RPT_ADV_REG)
#define REG_IMGDMA_WDMA2_WPT_ADV              *((volatile unsigned int *)IMGDMA_WDMA2_WPT_ADV_REG)
#define REG_IMGDMA_WDMA2_LCD_RPTADV           *((volatile unsigned int *)IMGDMA_WDMA2_LCD_RPTADV_REG)
#define REG_IMGDMA_WDMA2_LCD_SLOW_FRM         *((volatile unsigned int *)IMGDMA_WDMA2_LCD_SLOW_FRM_REG)
#define REG_IMGDMA_WDMA2_LCD_RESET            *((volatile unsigned int *)IMGDMA_WDMA2_LCD_RESET_REG)
#else // !defined(MDP_C_MODEL)
#define REG_IMGDMA_WDMA2_STATUS_FLAG          W_DMA2_STATUS_FLAG
#define REG_IMGDMA_WDMA2_INTERRUPT            W_DMA2_INTERRUPT
#define REG_IMGDMA_WDMA2_CFG                  W_DMA2_CFG
#define REG_IMGDMA_WDMA2_LCD                  W_DMA2_LCD
#define REG_IMGDMA_WDMA2_OUT_SEL              W_DMA2_OUT_SEL
#define REG_IMGDMA_WDMA2_STOP                 W_DMA2_STOP
#define REG_IMGDMA_WDMA2_EN                   W_DMA2_EN
#define REG_IMGDMA_WDMA2_RESET                W_DMA2_RESET
#define REG_IMGDMA_WDMA2_QUEUE_RSTA           W_DMA2_QUEUE_RSTA
#define REG_IMGDMA_WDMA2_QUEUE_WSTA           W_DMA2_QUEUE_WSTA
#define REG_IMGDMA_WDMA2_QUEUE_DATA           W_DMA2_QUEUE_DATA
#define REG_IMGDMA_WDMA2_QUEUE_BASE           W_DMA2_QUEUE_BASE
#define REG_IMGDMA_WDMA2_LCD_RPT              W_DMA2_LCD_RPT
#define REG_IMGDMA_WDMA2_EXEC_CNT             W_DMA2_EXEC_CNT
#define REG_IMGDMA_WDMA2_Y_DST_STR_ADDR0      W_DMA2_Y_DST_STR_ADDR0
#define REG_IMGDMA_WDMA2_U_DST_STR_ADDR0      W_DMA2_U_DST_STR_ADDR0
#define REG_IMGDMA_WDMA2_V_DST_STR_ADDR0      W_DMA2_V_DST_STR_ADDR0
#define REG_IMGDMA_WDMA2_Y_DST_STR_ADDR1      W_DMA2_Y_DST_STR_ADDR1
#define REG_IMGDMA_WDMA2_U_DST_STR_ADDR1      W_DMA2_U_DST_STR_ADDR1
#define REG_IMGDMA_WDMA2_V_DST_STR_ADDR1      W_DMA2_V_DST_STR_ADDR1
#define REG_IMGDMA_WDMA2_Y_DST_STR_ADDR2      W_DMA2_Y_DST_STR_ADDR2
#define REG_IMGDMA_WDMA2_U_DST_STR_ADDR2      W_DMA2_U_DST_STR_ADDR2
#define REG_IMGDMA_WDMA2_V_DST_STR_ADDR2      W_DMA2_V_DST_STR_ADDR2
#define REG_IMGDMA_WDMA2_SRC_SIZE             W_DMA2_SRC_SIZE
#define REG_IMGDMA_WDMA2_CLIP_OFFSET          W_DMA2_CLIP_OFFSET
#define REG_IMGDMA_WDMA2_CLIP_SIZE            W_DMA2_CLIP_SIZE
#define REG_IMGDMA_WDMA2_DST_SIZE             W_DMA2_DST_SIZE
#define REG_IMGDMA_WDMA2_CON                  W_DMA2_CON
#define REG_IMGDMA_WDMA2_SLOW_DOWN            W_DMA2_SLOW_DOWN
#if 0 // Not available in MDP c model
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

/**
 * \brief Check if WDMA2 is started or not.
 */
#define IMGDMA_WDMA2_IS_ENABLED() \
    ((0x1 == (REG_IMGDMA_WDMA2_EN & 0x1)) ? KAL_TRUE : KAL_FALSE)

// Start WDMA2
#define IMGDMA_WDMA2_START() \
    do { REG_IMGDMA_WDMA2_EN = 0x1; } while(0)

// Stop WDMA2, stop at frame end
#define IMGDMA_WDMA2_STOP() \
    do { REG_IMGDMA_WDMA2_STOP = 0x1; } while(0)

// Warm reset WDMA2, reset at GMC transaction end
#define IMGDMA_WDMA2_WARM_RESET() \
    do { REG_IMGDMA_WDMA2_RESET = 0x2; } while(0)

// Hard reset WDMA2, reset immediately, pending GMC transaction may cause state machine incorrect
#define IMGDMA_WDMA2_HARD_RESET() \
    do { REG_IMGDMA_WDMA2_RESET = 0x1; \
         REG_IMGDMA_WDMA2_RESET = 0x0; } while(0)

// Enable interrupt
#define IMGDMA_WDMA2_INTERRUPT_ENABLE() \
    do { REG_IMGDMA_WDMA2_INTERRUPT |= IMGDMA_INTERRUPT_INTEN_BIT; } while(0)

// Disable interrupt
#define IMGDMA_WDMA2_INTERRUPT_DISABLE() \
    do { REG_IMGDMA_WDMA2_INTERRUPT &= ~IMGDMA_INTERRUPT_INTEN_BIT; } while(0)

// Enable auto loop
#define IMGDMA_WDMA2_AUTO_LOOP_ENABLE() \
    do { REG_IMGDMA_WDMA2_CFG |= IMGDMA_CFG_AUTO_LOOP_BIT; } while(0)

// Disable auto loop
#define IMGDMA_WDMA2_AUTO_LOOP_DISABLE() \
    do { REG_IMGDMA_WDMA2_CFG &= ~IMGDMA_CFG_AUTO_LOOP_BIT; } while(0)

// Descriptor mode
#define IMGDMA_WDMA2_DESCRIPTOR_MODE() \
    do { REG_IMGDMA_WDMA2_CFG |= IMGDMA_CFG_MODE_BIT; } while(0)

// Register mode
#define IMGDMA_WDMA2_REGISTOR_MODE() \
    do { REG_IMGDMA_WDMA2_CFG &= ~IMGDMA_CFG_MODE_BIT; } while(0)

// Enable frame sync
#define IMGDMA_WDMA2_FRAME_SYNC_ENABLE() \
    do { REG_IMGDMA_WDMA2_CFG |= IMGDMA_CFG_FRAME_SYNC_EN_BIT; } while(0)

// Disable frame sync
#define IMGDMA_WDMA2_FRAME_SYNC_DISABLE() \
    do { REG_IMGDMA_WDMA2_CFG &= ~IMGDMA_CFG_FRAME_SYNC_EN_BIT; } while(0)

#define IMGDMA_WDMA2_CFG_QUEUEDEPTH_MASK 0x00000f00

#define IMGDMA_WDMA2_SET_QUEUE_DEPTH(depth) \
    do { REG_IMGDMA_WDMA2_CFG = \
        ((REG_IMGDMA_WDMA2_CFG & ~IMGDMA_WDMA2_CFG_QUEUEDEPTH_MASK) | \
         (IMGDMA_WDMA2_CFG_QUEUEDEPTH_MASK & ((depth) << 8))); } while(0)

/** 
 *  WDMA HW trigger LCD options! 
 *  WARNING: choose only one from below five!
 */
// No HW trigger LCD
#define IMGDMA_WDMA2_HW_TRIGGER_LCD_DISABLE() \
    do { REG_IMGDMA_WDMA2_LCD = 0x0; } while(0)

// Enable HW trigger LCD but no sync
#define IMGDMA_WDMA2_HW_TRIGGER_LCD_BUT_NO_SYNC() \
    do { REG_IMGDMA_WDMA2_LCD = IMGDMA_WDMA_LCD_HWTRIG_BIT; } while(0)

// Enable HW trigger LCD and sync w/ LCD, if LCD busy, stall WDMA2
#define IMGDMA_WDMA2_HW_TRIGGER_LCD_SYNC_N_STALL() \
    do { REG_IMGDMA_WDMA2_LCD = \
        ((IMGDMA_WDMA_LCD_HWTRIG_BIT | IMGDMA_WDMA_LCD_HWSYNC_BIT) | IMGDMA_WDMA_LCD_HWSYNCFULL_STALL); } while(0)

// Enable HW trigger LCD and sync w/ LCD, if LCD busy, WDMA2 redraws current output frame
#define IMGDMA_WDMA2_HW_TRIGGER_LCD_SYNC_N_REDRAW() \
    do { REG_IMGDMA_WDMA2_LCD = \
        ((IMGDMA_WDMA_LCD_HWTRIG_BIT | IMGDMA_WDMA_LCD_HWSYNC_BIT) | IMGDMA_WDMA_LCD_HWSYNCFULL_REDRAW); } while(0)

// Enable HW trigger LCD and sync w/ LCD, if LCD busy, WDMA2 drops incoming data (frame or pixels?) <== Recommanded when using HW trigger mode...
#define IMGDMA_WDMA2_HW_TRIGGER_LCD_SYNC_N_DROP() \
    do { REG_IMGDMA_WDMA2_LCD = \
        ((IMGDMA_WDMA_LCD_HWTRIG_BIT | IMGDMA_WDMA_LCD_HWSYNC_BIT) | IMGDMA_WDMA_LCD_HWSYNCFULL_DROP); } while(0)

// TODO: according to LCD spec, WDMA2, WDMA1, ROT_DMA0 can HW trigger LCD...

// Below macros set up BYPASS, STALL, DROP modes and output selection
/**
 * START    BYPASS    DROP    NEXT_ENG   MEMORY
 *   0        1         -        -         -    ==> bypass (to where?), cannot turn on WDMA
 *   0        0         0        -         -    ==> stall prev engine, cannot turn on WDMA
 *   0        0         1        -         -    ==> drop prev engine (to where?), cannot turn on WDMA
 *   1        -         -        0         0    ==> Error!
 *   1        -         -        ?         ?    ==> WDMA output to either or both memory/next engine
 */

// WARNING: only use w/o enable WDMA engine
#define IMGDMA_WDMA2_BYPASS_MODE() \
    do { REG_IMGDMA_WDMA2_OUT_SEL = 0x8000; } while(0)

// WARNING: only use w/o enable WDMA engine
#define IMGDMA_WDMA2_STALL_PREV_ENGINE() \
    do { REG_IMGDMA_WDMA2_OUT_SEL = 0x0; } while(0)

// WARNING: only use w/o enable WDMA engine
#define IMGDMA_WDMA2_DROP_PREV_ENGINE() \
    do { REG_IMGDMA_WDMA2_OUT_SEL = 0x1; } while(0)

// WARNING: Must select either one or both!
// output to external memory 
#define IMGDMA_WDMA2_OUTPUT_TO_MEM() \
    do { REG_IMGDMA_WDMA2_OUT_SEL &= ~0x8001; \
         REG_IMGDMA_WDMA2_OUT_SEL |= IMGDMA_WDMA_OUT_SEL_OUT1_BIT; } while(0)

// output to MOUT
#define IMGDMA_WDMA2_OUTPUT_TO_NEXT_ENGINE() \
    do { REG_IMGDMA_WDMA2_OUT_SEL &= ~0x8001; \
         REG_IMGDMA_WDMA2_OUT_SEL |= IMGDMA_WDMA_OUT_SEL_OUT2_BIT; } while(0)

// If set to YUV format, SW needs to set VH, UH, YH, VV, UV, and YV
#define IMGDMA_WDMA2_SET_OUTPUT_FORMAT(format) \
    do { REG_IMGDMA_WDMA2_CON = \
        ((REG_IMGDMA_WDMA2_CON & (~IMGDMA_WDMA_CON_OUTPUT_FORMAT_MASK)) | (format)); } while(0)

#define IMGDMA_WDMA2_RGB_ROUND_ENABLE() \
    do { REG_IMGDMA_WDMA2_CON |= IMGDMA_WDMA_CON_ROUND_BIT; } while(0)

#define IMGDMA_WDMA2_RGB_ROUND_DISABLE() \
    do { REG_IMGDMA_WDMA2_CON &= ~IMGDMA_WDMA_CON_ROUND_BIT; } while(0)

#define IMGDMA_WDMA2_SET_OUTPUT_YUV444() \
    do { REG_IMGDMA_WDMA2_CON = \
        ((REG_IMGDMA_WDMA2_CON & (~0x0fff0007)) | 0x05550005); } while(0)

#define IMGDMA_WDMA2_SET_OUTPUT_YUV422() \
    do { REG_IMGDMA_WDMA2_CON = \
        ((REG_IMGDMA_WDMA2_CON & (~0x0fff0007)) | 0x05690005); } while(0)

#define IMGDMA_WDMA2_SET_OUTPUT_YUV420() \
    do { REG_IMGDMA_WDMA2_CON = \
        ((REG_IMGDMA_WDMA2_CON & (~0x0fff0007)) | 0x0a690005); } while(0)

#define IMGDMA_WDMA2_SET_OUTPUT_YUV411() \
    do { REG_IMGDMA_WDMA2_CON = \
        ((REG_IMGDMA_WDMA2_CON & (~0x0fff0007)) | 0x057d0005); } while(0)

#define IMGDMA_WDMA2_SET_OUTPUT_YUV400() \
    do { REG_IMGDMA_WDMA2_CON = \
        ((REG_IMGDMA_WDMA2_CON & (~0x0fff0007)) | 0x00410005); } while(0)

/**
 * \brief WDMA2 structure
 *
 * Programmers can use this structure to set up WDMA2.
 */
typedef idp_imgdma_wdma_struct idp_imgdma_wdma2_struct;

IDP_HW_COMMON_API_DECLARATION(imgdma_wdma2)

extern void *idp_imgdma_wdma2_intr_cb_param;
extern void (*idp_imgdma_wdma2_intr_cb)(void *);

extern void
idp_imgdma_wdma2_open_real(void);

extern kal_bool 
idp_imgdma_wdma2_config_real(
    idp_imgdma_wdma2_struct * const wdma2_struct, 
    kal_bool const config_to_hardware);

extern kal_bool 
idp_imgdma_wdma2_get_working_mem_real(
    kal_bool const use_internal_mem,
    idp_imgdma_wdma2_struct const * const wdma2_struct,
    kal_bool const do_alloc,
    kal_uint32 const max_allowable_size);

extern kal_bool
idp_imgdma_wdma2_start_real(
    idp_imgdma_wdma2_struct const * const p_wdma2_struct);

extern kal_bool
idp_imgdma_wdma2_stop_real(
    idp_imgdma_wdma2_struct const * const p_wdma2_struct);

/** @} */

#endif // #if defined(DRV_IDP_MT6236_SERIES)
#endif // #ifndef __idp_imgdma_wdma2_mt6236_h__
