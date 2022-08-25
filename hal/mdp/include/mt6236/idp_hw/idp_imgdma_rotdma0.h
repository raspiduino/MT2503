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
 *    idp_imgdma_rotdma0.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    The header file of ROT_DMA0 HW driver of MT6236 IMGMDA
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
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_imgdma_rotdma0_mt6236_h__
#define __idp_imgdma_rotdma0_mt6236_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include <idp_define.h>

#if defined(DRV_IDP_MT6236_SERIES)

#include "idp_imgdma.h"
#include <idp_core.h>
#include "img_common_enum.h"
#include "idp_hw_common.h"
#include <mt6236/idp_mem.h>
#include "reg_base.h"

/** \defgroup imgdma_rotdma0 ROTDMA0
 * @{
 */
#define ROT_DMA0_BASE                       (ROT_DMA0_base)

#define IMGDMA_ROT_DMA0_STATUS_FLAG_REG     (ROT_DMA0_BASE + 0x0000)
#define IMGDMA_ROT_DMA0_STATUS_FLAG_CLR_REG (ROT_DMA0_BASE + 0x1020)
#define IMGDMA_ROT_DMA0_INTERRUPT_REG       (ROT_DMA0_BASE + 0x0004)
#define IMGDMA_ROT_DMA0_CFG_REG             (ROT_DMA0_BASE + 0x0008)
#define IMGDMA_ROT_DMA0_LCD_REG             (ROT_DMA0_BASE + 0x000c)
#define IMGDMA_ROT_DMA0_IN_SEL_REG          (ROT_DMA0_BASE + 0x0010)
#define IMGDMA_ROT_DMA0_STOP_REG            (ROT_DMA0_BASE + 0x0014)
#define IMGDMA_ROT_DMA0_EN_REG              (ROT_DMA0_BASE + 0x0018)
#define IMGDMA_ROT_DMA0_RESET_REG           (ROT_DMA0_BASE + 0x001c)
#define IMGDMA_ROT_DMA0_QUEUE_RSTA_REG      (ROT_DMA0_BASE + 0x0020)
#define IMGDMA_ROT_DMA0_QUEUE_WSTA_REG      (ROT_DMA0_BASE + 0x0024)
#define IMGDMA_ROT_DMA0_QUEUE_DATA_REG      (ROT_DMA0_BASE + 0x0028)
#define IMGDMA_ROT_DMA0_QUEUE_BASE_REG      (ROT_DMA0_BASE + 0x002c)
#define IMGDMA_ROT_DMA0_LCD_RPT_REG         (ROT_DMA0_BASE + 0x0030)
#define IMGDMA_ROT_DMA0_EXEC_CNT_REG        (ROT_DMA0_BASE + 0x0034)
#define IMGDMA_ROT_DMA0_BUF_ADDR0_REG       (ROT_DMA0_BASE + 0x0038)
#define IMGDMA_ROT_DMA0_BUF_ADDR1_REG       (ROT_DMA0_BASE + 0x003c)
#define IMGDMA_ROT_DMA0_DST_STR_ADDR0_REG   (ROT_DMA0_BASE + 0x0040)
#define IMGDMA_ROT_DMA0_DST_STR_ADDR1_REG   (ROT_DMA0_BASE + 0x0044)
#define IMGDMA_ROT_DMA0_DST_STR_ADDR2_REG   (ROT_DMA0_BASE + 0x0048)
#define IMGDMA_ROT_DMA0_CLIP_W_IN_BYTE_REG  (ROT_DMA0_BASE + 0x004c)
#define IMGDMA_ROT_DMA0_CLIP_H_IN_BYTE_REG  (ROT_DMA0_BASE + 0x0050)
#define IMGDMA_ROT_DMA0_FRAME_SIZE_REG      (ROT_DMA0_BASE + 0x0054)
#define IMGDMA_ROT_DMA0_SRC_SIZE_REG        (ROT_DMA0_BASE + 0x0058)
#define IMGDMA_ROT_DMA0_CLIP_OFFSET_REG     (ROT_DMA0_BASE + 0x005c)
#define IMGDMA_ROT_DMA0_CLIP_SIZE_REG       (ROT_DMA0_BASE + 0x0060)
#define IMGDMA_ROT_DMA0_DST_SIZE_REG        (ROT_DMA0_BASE + 0x0064)
#define IMGDMA_ROT_DMA0_CON_REG             (ROT_DMA0_BASE + 0x0068)
#define IMGDMA_ROT_DMA0_SLOW_DOWN_REG       (ROT_DMA0_BASE + 0x006c)
#define IMGDMA_ROT_DMA0_DEBUG_STATUS0_REG   (ROT_DMA0_BASE + 0x0090)
#define IMGDMA_ROT_DMA0_DEBUG_STATUS1_REG   (ROT_DMA0_BASE + 0x0094)
#define IMGDMA_ROT_DMA0_DEBUG_STATUS2_REG   (ROT_DMA0_BASE + 0x0098)
#define IMGDMA_ROT_DMA0_DEBUG_STATUS3_REG   (ROT_DMA0_BASE + 0x009c)
#define IMGDMA_ROT_DMA0_DEBUG_STATUS4_REG   (ROT_DMA0_BASE + 0x00a0)
#define IMGDMA_ROT_DMA0_DEBUG_STATUS5_REG   (ROT_DMA0_BASE + 0x00a4)
#define IMGDMA_ROT_DMA0_DEBUG_STATUS6_REG   (ROT_DMA0_BASE + 0x00a8)
#define IMGDMA_ROT_DMA0_DEBUG_STATUS7_REG   (ROT_DMA0_BASE + 0x00ac)
#define IMGDMA_ROT_DMA0_RPT_ADV_REG         (ROT_DMA0_BASE + 0x1000)
#define IMGDMA_ROT_DMA0_WPT_ADV_REG         (ROT_DMA0_BASE + 0x1004)
#define IMGDMA_ROT_DMA0_LCD_RPT_ADV_REG     (ROT_DMA0_BASE + 0x1008)
#define IMGDMA_ROT_DMA0_LCD_SLOW_FRM_REG    (ROT_DMA0_BASE + 0x1010)
#define IMGDMA_ROT_DMA0_LCD_RESET_REG       (ROT_DMA0_BASE + 0x100c)

// Move to mt6236\idp_hw\idp_imgdma.h
//#define MMSYS_IDP_LCD_OSEL_REG              (MMSYS_CONFIG_BASE + 0x0500)

#ifndef MDP_C_MODEL
#define REG_IMGDMA_ROT_DMA0_STATUS_FLAG     *((volatile unsigned int *) IMGDMA_ROT_DMA0_STATUS_FLAG_REG)
#define REG_IMGDMA_ROT_DMA0_STATUS_FLAG_CLR *((volatile unsigned int *) IMGDMA_ROT_DMA0_STATUS_FLAG_CLR_REG)
#define REG_IMGDMA_ROT_DMA0_INTERRUPT       *((volatile unsigned int *) IMGDMA_ROT_DMA0_INTERRUPT_REG)
#define REG_IMGDMA_ROT_DMA0_CFG             *((volatile unsigned int *) IMGDMA_ROT_DMA0_CFG_REG)
#define REG_IMGDMA_ROT_DMA0_LCD             *((volatile unsigned int *) IMGDMA_ROT_DMA0_LCD_REG)
#define REG_IMGDMA_ROT_DMA0_IN_SEL          *((volatile unsigned int *) IMGDMA_ROT_DMA0_IN_SEL_REG)
#define REG_IMGDMA_ROT_DMA0_STOP            *((volatile unsigned int *) IMGDMA_ROT_DMA0_STOP_REG)
#define REG_IMGDMA_ROT_DMA0_EN              *((volatile unsigned int *) IMGDMA_ROT_DMA0_EN_REG)
#define REG_IMGDMA_ROT_DMA0_RESET           *((volatile unsigned int *) IMGDMA_ROT_DMA0_RESET_REG)
#define REG_IMGDMA_ROT_DMA0_QUEUE_RSTA      *((volatile unsigned int *) IMGDMA_ROT_DMA0_QUEUE_RSTA_REG)
#define REG_IMGDMA_ROT_DMA0_QUEUE_WSTA      *((volatile unsigned int *) IMGDMA_ROT_DMA0_QUEUE_WSTA_REG)
#define REG_IMGDMA_ROT_DMA0_QUEUE_DATA      *((volatile unsigned int *) IMGDMA_ROT_DMA0_QUEUE_DATA_REG)
#define REG_IMGDMA_ROT_DMA0_QUEUE_BASE      *((volatile unsigned int *) IMGDMA_ROT_DMA0_QUEUE_BASE_REG)
#define REG_IMGDMA_ROT_DMA0_LCD_RPT         *((volatile unsigned int *) IMGDMA_ROT_DMA0_LCD_RPT_REG)
#define REG_IMGDMA_ROT_DMA0_EXEC_CNT        *((volatile unsigned int *) IMGDMA_ROT_DMA0_EXEC_CNT_REG)
#define REG_IMGDMA_ROT_DMA0_BUF_ADDR0       *((volatile unsigned int *) IMGDMA_ROT_DMA0_BUF_ADDR0_REG)
#define REG_IMGDMA_ROT_DMA0_BUF_ADDR1       *((volatile unsigned int *) IMGDMA_ROT_DMA0_BUF_ADDR1_REG)
#define REG_IMGDMA_ROT_DMA0_DST_STR_ADDR0   *((volatile unsigned int *) IMGDMA_ROT_DMA0_DST_STR_ADDR0_REG)
#define REG_IMGDMA_ROT_DMA0_DST_STR_ADDR1   *((volatile unsigned int *) IMGDMA_ROT_DMA0_DST_STR_ADDR1_REG)
#define REG_IMGDMA_ROT_DMA0_DST_STR_ADDR2   *((volatile unsigned int *) IMGDMA_ROT_DMA0_DST_STR_ADDR2_REG)
#define REG_IMGDMA_ROT_DMA0_CLIP_W_IN_BYTE  *((volatile unsigned int *) IMGDMA_ROT_DMA0_CLIP_W_IN_BYTE_REG)
#define REG_IMGDMA_ROT_DMA0_CLIP_H_IN_BYTE  *((volatile unsigned int *) IMGDMA_ROT_DMA0_CLIP_H_IN_BYTE_REG)
#define REG_IMGDMA_ROT_DMA0_FRAME_SIZE      *((volatile unsigned int *) IMGDMA_ROT_DMA0_FRAME_SIZE_REG)
#define REG_IMGDMA_ROT_DMA0_SRC_SIZE        *((volatile unsigned int *) IMGDMA_ROT_DMA0_SRC_SIZE_REG)
#define REG_IMGDMA_ROT_DMA0_CLIP_OFFSET     *((volatile unsigned int *) IMGDMA_ROT_DMA0_CLIP_OFFSET_REG)
#define REG_IMGDMA_ROT_DMA0_CLIP_SIZE       *((volatile unsigned int *) IMGDMA_ROT_DMA0_CLIP_SIZE_REG)
#define REG_IMGDMA_ROT_DMA0_DST_SIZE        *((volatile unsigned int *) IMGDMA_ROT_DMA0_DST_SIZE_REG)
#define REG_IMGDMA_ROT_DMA0_CON             *((volatile unsigned int *) IMGDMA_ROT_DMA0_CON_REG)
#define REG_IMGDMA_ROT_DMA0_SLOW_DOWN       *((volatile unsigned int *) IMGDMA_ROT_DMA0_SLOW_DOWN_REG)
#define REG_IMGDMA_ROT_DMA0_DEBUG_STATUS0   *((volatile unsigned int *) IMGDMA_ROT_DMA0_DEBUG_STATUS0_REG)
#define REG_IMGDMA_ROT_DMA0_DEBUG_STATUS1   *((volatile unsigned int *) IMGDMA_ROT_DMA0_DEBUG_STATUS1_REG)
#define REG_IMGDMA_ROT_DMA0_DEBUG_STATUS2   *((volatile unsigned int *) IMGDMA_ROT_DMA0_DEBUG_STATUS2_REG)
#define REG_IMGDMA_ROT_DMA0_DEBUG_STATUS3   *((volatile unsigned int *) IMGDMA_ROT_DMA0_DEBUG_STATUS3_REG)
#define REG_IMGDMA_ROT_DMA0_DEBUG_STATUS4   *((volatile unsigned int *) IMGDMA_ROT_DMA0_DEBUG_STATUS4_REG)
#define REG_IMGDMA_ROT_DMA0_DEBUG_STATUS5   *((volatile unsigned int *) IMGDMA_ROT_DMA0_DEBUG_STATUS5_REG)
#define REG_IMGDMA_ROT_DMA0_DEBUG_STATUS6   *((volatile unsigned int *) IMGDMA_ROT_DMA0_DEBUG_STATUS6_REG)
#define REG_IMGDMA_ROT_DMA0_DEBUG_STATUS7   *((volatile unsigned int *) IMGDMA_ROT_DMA0_DEBUG_STATUS7_REG)
#define REG_IMGDMA_ROT_DMA0_RPT_ADV         *((volatile unsigned int *) IMGDMA_ROT_DMA0_RPT_ADV_REG)
#define REG_IMGDMA_ROT_DMA0_WPT_ADV         *((volatile unsigned int *) IMGDMA_ROT_DMA0_WPT_ADV_REG)
#define REG_IMGDMA_ROT_DMA0_LCD_RPT_ADV     *((volatile unsigned int *) IMGDMA_ROT_DMA0_LCD_RPT_ADV_REG)
#define REG_IMGDMA_ROT_DMA0_LCD_SLOW_FRM    *((volatile unsigned int *) IMGDMA_ROT_DMA0_LCD_SLOW_FRM_REG)
#define REG_IMGDMA_ROT_DMA0_LCD_RESET       *((volatile unsigned int *) IMGDMA_ROT_DMA0_LCD_RESET_REG)
#else // MDP_C_MODEL
#define REG_IMGDMA_ROT_DMA0_STATUS_FLAG     ROT_DMA0_STATUS_FLAG 
#define REG_IMGDMA_ROT_DMA0_INTERRUPT       ROT_DMA0_INTERRUPT 
#define REG_IMGDMA_ROT_DMA0_CFG             ROT_DMA0_CFG 
#define REG_IMGDMA_ROT_DMA0_LCD             ROT_DMA0_LCD 
#define REG_IMGDMA_ROT_DMA0_IN_SEL          ROT_DMA0_IN_SEL 
#define REG_IMGDMA_ROT_DMA0_STOP            ROT_DMA0_STOP 
#define REG_IMGDMA_ROT_DMA0_EN              ROT_DMA0_EN 
#define REG_IMGDMA_ROT_DMA0_RESET           ROT_DMA0_RESET 
#define REG_IMGDMA_ROT_DMA0_QUEUE_RSTA      ROT_DMA0_QUEUE_RSTA 
#define REG_IMGDMA_ROT_DMA0_QUEUE_WSTA      ROT_DMA0_QUEUE_WSTA 
#define REG_IMGDMA_ROT_DMA0_QUEUE_DATA      ROT_DMA0_QUEUE_DATA 
#define REG_IMGDMA_ROT_DMA0_QUEUE_BASE      ROT_DMA0_QUEUE_BASE 
#define REG_IMGDMA_ROT_DMA0_LCD_RPT         ROT_DMA0_LCD_RPT 
#define REG_IMGDMA_ROT_DMA0_EXEC_CNT        ROT_DMA0_EXEC_CNT 
#define REG_IMGDMA_ROT_DMA0_BUF_ADDR0       ROT_DMA0_BUF_BASE_ADDR0 
#define REG_IMGDMA_ROT_DMA0_BUF_ADDR1       ROT_DMA0_BUF_BASE_ADDR1 
#define REG_IMGDMA_ROT_DMA0_DST_STR_ADDR0   ROT_DMA0_DST_STR_ADDR0 
#define REG_IMGDMA_ROT_DMA0_DST_STR_ADDR1   ROT_DMA0_DST_STR_ADDR1 
#define REG_IMGDMA_ROT_DMA0_DST_STR_ADDR2   ROT_DMA0_DST_STR_ADDR2 
#define REG_IMGDMA_ROT_DMA0_CLIP_W_IN_BYTE  ROT_DMA0_CLIP_W_IN_BYTE 
#define REG_IMGDMA_ROT_DMA0_CLIP_H_IN_BYTE  ROT_DMA0_CLIP_H_IN_BYTE 
#define REG_IMGDMA_ROT_DMA0_FRAME_SIZE      ROT_DMA0_FRAME_SIZE 
#define REG_IMGDMA_ROT_DMA0_SRC_SIZE        ROT_DMA0_SRC_SIZE 
#define REG_IMGDMA_ROT_DMA0_CLIP_OFFSET     ROT_DMA0_CLIP_OFFSET 
#define REG_IMGDMA_ROT_DMA0_CLIP_SIZE       ROT_DMA0_CLIP_SIZE 
#define REG_IMGDMA_ROT_DMA0_DST_SIZE        ROT_DMA0_DST_SIZE 
#define REG_IMGDMA_ROT_DMA0_CON             ROT_DMA0_CON 
#define REG_IMGDMA_ROT_DMA0_SLOW_DOWN       ROT_DMA0_SLOW_DOWN 
#if 0 // Not available in MDP C model
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // 0
#endif // MDP_C_MODEL

// Move to mt6236\idp_hw\idp_imgdma.h
//#define REG_MMSYS_IDP_LCD_OSEL              *((volatile unsigned int *) MMSYS_IDP_LCD_OSEL_REG)

/**
 * \brief Check if IRT0 is started or not.
 */
/// Is enabled
#define IMGDMA_ROTDMA0_IS_ENABLED() \
    ((0x1 == (REG_IMGDMA_ROT_DMA0_EN & 0x1)) ? KAL_TRUE : KAL_FALSE)

// Start ROTDMA0
#define IMGDMA_ROTDMA0_START() \
    do { REG_IMGDMA_ROT_DMA0_EN = 0x1; } while(0)

// Stop ROTDMA0, stop at frame end
#define IMGDMA_ROTDMA0_STOP() \
    do { REG_IMGDMA_ROT_DMA0_STOP = 0x1; } while(0)

// Warm reset ROTDMA0, reset at GMC transaction end
#define IMGDMA_ROTDMA0_WARM_RESET() \
    do { REG_IMGDMA_ROT_DMA0_RESET = 0x2; } while(0)

// Hard reset ROTDMA0, reset immediately, pending GMC transaction may cause state machine incorrect
#define IMGDMA_ROTDMA0_HARD_RESET() \
    do { REG_IMGDMA_ROT_DMA0_RESET = 0x1; \
         REG_IMGDMA_ROT_DMA0_RESET = 0x0; } while(0)

#define IMGDMA_ROTDMA0_INTERRUPT_ENABLE() \
    do { REG_IMGDMA_ROT_DMA0_INTERRUPT |= 0x1; } while(0)

#define IMGDMA_ROTDMA0_INTERRUPT_DISABLE() \
    do { REG_IMGDMA_ROT_DMA0_INTERRUPT &= ~0x1; } while(0)

#define IMGDMA_ROTDMA0_AUTO_LOOP_ENABLE() \
    do { REG_IMGDMA_ROT_DMA0_CFG |= IMGDMA_INTERRUPT_INTEN_BIT; } while(0)

#define IMGDMA_ROTDMA0_AUTO_LOOP_DISABLE() \
    do { REG_IMGDMA_ROT_DMA0_CFG &= ~IMGDMA_INTERRUPT_INTEN_BIT; } while(0)

// Descriptor mode
#define IMGDMA_ROTDMA0_DESCRIPTOR_MODE() \
    do { REG_IMGDMA_ROT_DMA0_CFG |= IMGDMA_CFG_MODE_BIT; } while(0)

// Register mode
#define IMGDMA_ROTDMA0_REGISTOR_MODE() \
    do { REG_IMGDMA_ROT_DMA0_CFG &= ~IMGDMA_CFG_MODE_BIT; } while(0)

// Enable frame sync
#define IMGDMA_ROTDMA0_FRAME_SYNC_ENABLE() \
    do { REG_IMGDMA_ROT_DMA0_CFG |= IMGDMA_CFG_FRAME_SYNC_EN_BIT; } while(0)

// Disable frame sync
#define IMGDMA_ROTDMA0_FRAME_SYNC_DISABLE() \
    do { REG_IMGDMA_ROT_DMA0_CFG &= ~IMGDMA_CFG_FRAME_SYNC_EN_BIT; } while(0)

#define IMGDMA_ROTDMA0_CFG_QUEUEDEPTH_MASK 0x00000f00

#define IMGDMA_ROTDMA0_SET_QUEUE_DEPTH(depth) \
    do { REG_IMGDMA_ROT_DMA0_CFG = \
        ((REG_IMGDMA_ROT_DMA0_CFG & ~IMGDMA_ROTDMA0_CFG_QUEUEDEPTH_MASK) | \
         (IMGDMA_ROTDMA0_CFG_QUEUEDEPTH_MASK & ((depth) << 8))); } while(0)

// MOUT -> ROT_DMA0
#define IMGDMA_ROTDMA0_FROM_MOUT() \
    do { REG_MMSYS_IDP_LCD_OSEL &= ~0x1; } while(0)

// W_DMA1 ->  ROT_DMA0
#define IMGDMA_ROTDMA0_FROM_WDMA1() \
    do { REG_MMSYS_IDP_LCD_OSEL |= 0x1; } while(0)


#define IMGDMA_ROTDMA_LCD_HWTRIG_BIT                0x00000001
#define IMGDMA_ROTDMA_LCD_HWSYNC_BIT                0x00000002
#define IMGDMA_ROTDMA_LCD_HWSYNCFULL_MASK           0x0000000c
#define IMGDMA_ROTDMA_LCD_HWSYNCFULL_STALL          0x00000000 /**< When LCD not done, ROTDMA is stalled... */
#define IMGDMA_ROTDMA_LCD_HWSYNCFULL_REDRAW         0x00000004 /**< When LCD not done, ROTDMA redraws the current output buffer. */
#define IMGDMA_ROTDMA_LCD_HWSYNCFULL_DROP           0x00000008 /**< When LCD not done, ROTDMA not redraw but drop incoming frame. */
#define IMGDMA_ROTDMA_LCD_HW_TRIG_ALL_BIT           0x00000010 /**< should pull this bit to ensure LCD state correctness under HW Trigger mode */

/** 
 *  WDMA HW trigger LCD options! 
 *  WARNING: choose only one from below five!
 */
// No HW trigger LCD
#define IMGDMA_ROTDMA0_HW_TRIGGER_LCD_DISABLE() \
    do { REG_IMGDMA_ROT_DMA0_LCD = 0x0; } while(0)

// Enable HW trigger LCD but no sync
#define IMGDMA_ROTDMA0_HW_TRIGGER_LCD_BUT_NO_SYNC() \
    do { REG_IMGDMA_ROT_DMA0_LCD = IMGDMA_ROTDMA_LCD_HWTRIG_BIT | IMGDMA_ROTDMA_LCD_HW_TRIG_ALL_BIT; } while(0)

// Enable HW trigger LCD and sync w/ LCD, if LCD busy, stall WDMA0
#define IMGDMA_ROTDMA0_HW_TRIGGER_LCD_SYNC_N_STALL() \
    do { REG_IMGDMA_ROT_DMA0_LCD = \
        ((IMGDMA_ROTDMA_LCD_HWTRIG_BIT | IMGDMA_ROTDMA_LCD_HWSYNC_BIT) | IMGDMA_ROTDMA_LCD_HWSYNCFULL_STALL | IMGDMA_ROTDMA_LCD_HW_TRIG_ALL_BIT); } while(0)

// Enable HW trigger LCD and sync w/ LCD, if LCD busy, WDMA0 redraws current output frame
#define IMGDMA_ROTDMA0_HW_TRIGGER_LCD_SYNC_N_REDRAW() \
    do { REG_IMGDMA_ROT_DMA0_LCD = \
        ((IMGDMA_ROTDMA_LCD_HWTRIG_BIT | IMGDMA_ROTDMA_LCD_HWSYNC_BIT) | IMGDMA_ROTDMA_LCD_HWSYNCFULL_REDRAW | IMGDMA_ROTDMA_LCD_HW_TRIG_ALL_BIT); } while(0)

// Enable HW trigger LCD and sync w/ LCD, if LCD busy, WDMA0 drops incoming data (frame or pixels?) <== Recommanded when using HW trigger mode...
#define IMGDMA_ROTDMA0_HW_TRIGGER_LCD_SYNC_N_DROP() \
    do { REG_IMGDMA_ROT_DMA0_LCD = \
        ((IMGDMA_ROTDMA_LCD_HWTRIG_BIT | IMGDMA_ROTDMA_LCD_HWSYNC_BIT) | IMGDMA_ROTDMA_LCD_HWSYNCFULL_DROP | IMGDMA_ROTDMA_LCD_HW_TRIG_ALL_BIT); } while(0)

// WARNING: only use w/o enable WDMA engine
#define IMGDMA_ROTDMA0_STALL_PREV_ENGINE() \
    do { REG_IMGDMA_ROT_DMA0_IN_SEL = 0x0; } while(0)

// WARNING: only use w/o enable WDMA engine
#define IMGDMA_ROTDMA0_DROP_PREV_ENGINE() \
    do { REG_IMGDMA_ROT_DMA0_IN_SEL = 0x1; } while(0)

#define IMGDMA_ROTDMA0_CON_OUTPUT_FORMAT_MASK        0x00000007
#define IMGDMA_ROTDMA0_CON_OUTPUT_FORMAT_ARGB8888    0x00000000
#define IMGDMA_ROTDMA0_CON_OUTPUT_FORMAT_RGB888      0x00000001
#define IMGDMA_ROTDMA0_CON_OUTPUT_FORMAT_RGB565      0x00000002
#define IMGDMA_ROTDMA0_CON_OUTPUT_FORMAT_BGR888      0x00000003
#define IMGDMA_ROTDMA0_CON_OUTPUT_FORMAT_YUYV422     0x00000004
#define IMGDMA_ROTDMA0_CON_A_VALUE_MASK              0x0000ff00
#define IMGDMA_ROTDMA0_CON_ROUND_BIT                 0x00000008 /**< rounding when output RGB format */

#define IMGDMA_ROTDMA0_SET_OUTPUT_FORMAT(format) \
    do { REG_IMGDMA_ROT_DMA0_CON = \
        ((REG_IMGDMA_ROT_DMA0_CON & (~IMGDMA_ROTDMA0_CON_OUTPUT_FORMAT_MASK)) | (format)); } while(0)

#define IMGDMA_ROTDMA0_RGB_ROUND_ENABLE() \
    do { REG_IMGDMA_ROT_DMA0_CON |= IMGDMA_ROTDMA0_CON_ROUND_BIT; } while(0)

#define IMGDMA_ROTDMA0_RGB_ROUND_DISABLE() \
    do { REG_IMGDMA_ROT_DMA0_CON &= ~IMGDMA_ROTDMA0_CON_ROUND_BIT; } while(0)

#define IMGDMA_ROTDMA0_ROT_0() \
    do { REG_IMGDMA_ROT_DMA0_CON = \
        ((REG_IMGDMA_ROT_DMA0_CON & ~0x30000000) | 0x0); } while(0)

#define IMGDMA_ROTDMA0_ROT_90CW() \
    do { REG_IMGDMA_ROT_DMA0_CON = \
        ((REG_IMGDMA_ROT_DMA0_CON & ~0x30000000) | 0x10000000); } while(0)

#define IMGDMA_ROTDMA0_ROT_180CW() \
    do { REG_IMGDMA_ROT_DMA0_CON = \
        ((REG_IMGDMA_ROT_DMA0_CON & ~0x30000000) | 0x20000000); } while(0)

#define IMGDMA_ROTDMA0_ROT_270CW() \
    do { REG_IMGDMA_ROT_DMA0_CON = \
        ((REG_IMGDMA_ROT_DMA0_CON & ~0x30000000) | 0x30000000); } while(0)

#define IMGDMA_ROTDMA0_FLIP_ENABLE() \
    do { REG_IMGDMA_ROT_DMA0_CON |= 0x40000000; } while(0)

#define IMGDMA_ROTDMA0_FLIP_DISABLE() \
    do { REG_IMGDMA_ROT_DMA0_CON &= ~0x40000000; } while(0)

#define IMGDMA_ROTDMA0_SET_ALPHA(alpha) \
    do { REG_IMGDMA_ROT_DMA0_CON = \
        ((REG_IMGDMA_ROT_DMA0_CON & ~IMGDMA_ROTDMA0_CON_A_VALUE_MASK) | \
         (((alpha) << 8) & IMGDMA_ROTDMA0_CON_A_VALUE_MASK)); } while(0)

#define IMGDMA_ROTDMA0_DBG_IS_DMA_BUSY() \
    ((0x0 != (REG_IMGDMA_ROT_DMA0_DEBUG_STATUS2&0xf0000000)) ? KAL_TRUE : KAL_FALSE)

/**
 * \brief IRT0 structure
 *
 * Programmers can use this structure to set up IRT0.
 *  @remark since ROTDMA will HW trigger LCD with destination start address rather than 
 *          destination base address. If the two addresses are different, then HW trigger will 
 *          results in incorrect output, LCD will directly read from destination start address. 
 *          ==> When in HW trigger mode, destination base/start address should be the same!
 */
typedef struct
{
    kal_bool                      intr_en; /**< enable int or not */
    
    idp_lisr_intr_cb_t            intr_cb;
    idp_lisr_intr_cb_param_t      intr_cb_param;
    
    kal_bool                      descriptor_mode;
    
    kal_bool                      restart; /**< auto loop mode */
    kal_bool                      input_from_mout; /**< either from mout or from W_DMA1 */

    kal_bool                      stall_prev_engine; /**< KAL_TRUE to stall prev engine, and this engine will not be enabled! this is rarely in use, default set to KAL_FALSE. */
    kal_bool                      drop_prev_engine; /**< KAL_TRUE to drop pixels from prev engine, and this engine will not be enabled! this is rarely in use, default set to KAL_FALSE. */

    kal_bool                      hw_frame_sync;
  
    img_rot_angle_enum_t          rot_angle; /**< rotate direction */
    kal_bool                      flip; /**< flip or not */
      
    kal_bool                      hw_trigger_lcd; /**< enable hw trigger LCD */
    idp_lcd_hw_trigger_mode_t     hw_trigger_mode;
    kal_bool                      hw_trigger_rst_wait_lcd; /**< KAL_TRUE will take LCD hand-shake into account when warm reset; KAL_FALSE, o.w. (default) */
    kal_bool                      fgLcdRdPtrAdvance;

    kal_uint8                     reg_mode_queue_depth; /**< [1, 3] */
    kal_uint32                    dest_base_addr0;
    kal_uint32                    dest_base_addr1;
    kal_uint32                    dest_base_addr2;

    kal_uint32                    dest_start_addr0;
    kal_uint32                    dest_start_addr1;
    kal_uint32                    dest_start_addr2;
    
    kal_uint32                    work_mem_line_count;
    kal_uint32                    wm_addr_0;
    kal_uint32                    wm_addr_1;

    kal_uint32                    color_fmt;
  
    kal_uint8                     alpha_value;
    
    kal_uint16                    src_width; /**< width */
    kal_uint16                    src_height; /**< height */

    kal_bool                      pitch_enable; /**< pitch */
    kal_uint16                    pitch_bytes; /**< horizontal pitch WARNING! the pitch is applied to three buffers */ 

    kal_bool                      clip; /**< enable source clipping */
    kal_uint16                    clip_top;
    kal_uint16                    clip_bottom;
    kal_uint16                    clip_left;
    kal_uint16                    clip_right;

    /** private member section */
    kal_uint32                    _wm_size_single; /**< the size of single working buffer in bytes. */
    
} idp_imgdma_rotdma0_struct;

IDP_HW_COMMON_API_DECLARATION(imgdma_rotdma0)

extern void *idp_imgdma_rotdma0_intr_cb_param;
extern void (*idp_imgdma_rotdma0_intr_cb)(void *);

extern kal_bool idp_imgdma_rotdma0_config_real(
    idp_imgdma_rotdma0_struct * const rotdma0_struct, 
    kal_bool const config_to_hardware);

extern kal_bool idp_imgdma_rotdma0_get_working_mem_real(
    kal_bool const use_internal_mem,
    idp_imgdma_rotdma0_struct * const rotdma0_struct,
    kal_bool const do_alloc,
    kal_uint32 const max_allowable_size);

extern kal_bool
idp_imgdma_rotdma0_start_real(
    idp_imgdma_rotdma0_struct const * const p_rotdma0_struct);

extern kal_bool
idp_imgdma_rotdma0_stop_real(
    idp_imgdma_rotdma0_struct const * const p_rotdma0_struct);

extern void
idp_imgdma_rotdma0_open_real(void);

/** @} */

#endif // #if defined(DRV_IDP_MT6236_SERIES)
#endif // #ifndef __idp_imgdma_rotdma0_mt6236_h__

