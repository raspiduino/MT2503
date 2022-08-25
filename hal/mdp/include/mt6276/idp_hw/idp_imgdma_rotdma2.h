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
 * 01 07 2011 chrono.wu
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
 * MT6256 naming check-in
 *
 * removed!
 * removed!
 * MT6255 HQA check-in
 *
 * removed!
 * removed!
 * MM integration check-in
 *
 * removed!
 * removed!
 * MM integration check-in
 *
 * removed!
 * removed!
 * Modify the typo error
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

#ifndef __idp_imgdma_rotdma2_mt6276_h__
#define __idp_imgdma_rotdma2_mt6276_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include <idp_define.h>

#if defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6256_SERIES)

#include "idp_imgdma.h"
#include <idp_core.h>
#include "img_common_enum.h"
#include "idp_hw_common.h"
#include <mt6276/idp_mem.h>

#include "reg_base.h"
#include "kal_non_specific_general_types.h"


/** \defgroup imgdma_rotdma2 ROTDMA2
 * @{
 */
#ifndef MDP_C_MODEL
#define ROT_DMA2_BASE ROT_DMA2_base

#define IMGDMA_ROT_DMA2_IRQ_FLAG_REG              (ROT_DMA2_BASE + 0x0000)
#define IMGDMA_ROT_DMA2_IRQ_FLAG_CLR_REG          (ROT_DMA2_BASE + 0x0008)
#define IMGDMA_ROT_DMA2_CFG_REG                   (ROT_DMA2_BASE + 0x0018)
#define IMGDMA_ROT_DMA2_IN_SEL_REG                (ROT_DMA2_BASE + 0x0020)
#define IMGDMA_ROT_DMA2_STOP_REG                  (ROT_DMA2_BASE + 0x0028)
#define IMGDMA_ROT_DMA2_EN_REG                    (ROT_DMA2_BASE + 0x0030)
#define IMGDMA_ROT_DMA2_RESET_REG                 (ROT_DMA2_BASE + 0x0038)
#define IMGDMA_ROT_DMA2_LOCK_REG                  (ROT_DMA2_BASE + 0x003C)
#define IMGDMA_ROT_DMA2_QUEUE_RSTA_REG            (ROT_DMA2_BASE + 0x0040)
#define IMGDMA_ROT_DMA2_RD_BASE_REG               (ROT_DMA2_BASE + 0x0048)
#define IMGDMA_ROT_DMA2_RPT_ADVANCE_REG           (ROT_DMA2_BASE + 0x0050)
#define IMGDMA_ROT_DMA2_QUEUE_WSTA_REG            (ROT_DMA2_BASE + 0x0058)
#define IMGDMA_ROT_DMA2_WR_BASE_REG               (ROT_DMA2_BASE + 0x0060)
#define IMGDMA_ROT_DMA2_WPT_ADVANCE_REG           (ROT_DMA2_BASE + 0x0068)
#define IMGDMA_ROT_DMA2_DES_AVAILABLE_SPACE_REG   (ROT_DMA2_BASE + 0x006c)
#define IMGDMA_ROT_DMA2_QUEUE_DATA_REG            (ROT_DMA2_BASE + 0x0070)
#define IMGDMA_ROT_DMA2_QUEUE_BASE_REG            (ROT_DMA2_BASE + 0x0078)
#define IMGDMA_ROT_DMA2_EXEC_CNT_REG              (ROT_DMA2_BASE + 0x0080)
#define IMGDMA_ROT_DMA2_DROPPED_FRAME_CNT_REG     (ROT_DMA2_BASE + 0x0088)
#define IMGDMA_ROT_DMA2_LCD_REG                   (ROT_DMA2_BASE + 0x0200)
#define IMGDMA_ROT_DMA2_LCD_STA_REG               (ROT_DMA2_BASE + 0x0208)
#define IMGDMA_ROT_DMA2_LCD_RPT_ADVANCE_REG       (ROT_DMA2_BASE + 0x0210)
#define IMGDMA_ROT_DMA2_LCD_RPT_BASE_REG          (ROT_DMA2_BASE + 0x0218)
#define IMGDMA_ROT_DMA2_SLOW_DOWN_REG             (ROT_DMA2_BASE + 0x0300)
#define IMGDMA_ROT_DMA2_BUF_ADDR0_REG             (ROT_DMA2_BASE + 0x0308)
#define IMGDMA_ROT_DMA2_BUF_ADDR1_REG             (ROT_DMA2_BASE + 0x0310)
#define IMGDMA_ROT_DMA2_BUF_ADDR2_REG             (ROT_DMA2_BASE + 0x0380)
#define IMGDMA_ROT_DMA2_BUF_ADDR3_REG             (ROT_DMA2_BASE + 0x0388)
#define IMGDMA_ROT_DMA2_DST_STR_ADDR              (ROT_DMA2_BASE + 0x0314)
#define IMGDMA_ROT_DMA2_Y_DST_STR_ADDR_REG        (ROT_DMA2_BASE + 0x0318)
#define IMGDMA_ROT_DMA2_U_DST_STR_ADDR_REG        (ROT_DMA2_BASE + 0x0320)
#define IMGDMA_ROT_DMA2_V_DST_STR_ADDR_REG        (ROT_DMA2_BASE + 0x0328)
#define IMGDMA_ROT_DMA2_SRC_SIZE_REG              (ROT_DMA2_BASE + 0x0330)
#define IMGDMA_ROT_DMA2_CLIP_SIZE_REG             (ROT_DMA2_BASE + 0x0338)
#define IMGDMA_ROT_DMA2_CLIP_OFFSET_REG           (ROT_DMA2_BASE + 0x0340)
#define IMGDMA_ROT_DMA2_DST_SIZE_REG              (ROT_DMA2_BASE + 0x0348)
#define IMGDMA_ROT_DMA2_CLIP_W_IN_BYTE_REG        (ROT_DMA2_BASE + 0x0350)
#define IMGDMA_ROT_DMA2_CLIP_H_IN_BYTE_REG        (ROT_DMA2_BASE + 0x0358)
#define IMGDMA_ROT_DMA2_CON_REG                   (ROT_DMA2_BASE + 0x0368)
#define IMGDMA_ROT_DMA2_DITHER                    (ROT_DMA2_BASE + 0x0370)



#define REG_IMGDMA_ROT_DMA2_IRQ_FLAG                *((volatile unsigned int*)IMGDMA_ROT_DMA2_IRQ_FLAG_REG)              
#define REG_IMGDMA_ROT_DMA2_IRQ_FLAG_CLR            *((volatile unsigned int*)IMGDMA_ROT_DMA2_IRQ_FLAG_CLR_REG)          
#define REG_IMGDMA_ROT_DMA2_CFG                     *((volatile unsigned int*)IMGDMA_ROT_DMA2_CFG_REG)                   
#define REG_IMGDMA_ROT_DMA2_IN_SEL                  *((volatile unsigned int*)IMGDMA_ROT_DMA2_IN_SEL_REG)                
#define REG_IMGDMA_ROT_DMA2_STOP                    *((volatile unsigned int*)IMGDMA_ROT_DMA2_STOP_REG)                  
#define REG_IMGDMA_ROT_DMA2_EN                      *((volatile unsigned int*)IMGDMA_ROT_DMA2_EN_REG)                    
#define REG_IMGDMA_ROT_DMA2_RESET                   *((volatile unsigned int*)IMGDMA_ROT_DMA2_RESET_REG)                 
#define REG_IMGDMA_ROT_DMA2_LOCK                    *((volatile unsigned int*)IMGDMA_ROT_DMA2_LOCK_REG)                  
#define REG_IMGDMA_ROT_DMA2_QUEUE_RSTA              *((volatile unsigned int*)IMGDMA_ROT_DMA2_QUEUE_RSTA_REG)            
#define REG_IMGDMA_ROT_DMA2_RD_BASE                 *((volatile unsigned int*)IMGDMA_ROT_DMA2_RD_BASE_REG)               
#define REG_IMGDMA_ROT_DMA2_RPT_ADVANCE             *((volatile unsigned int*)IMGDMA_ROT_DMA2_RPT_ADVANCE_REG)           
#define REG_IMGDMA_ROT_DMA2_QUEUE_WSTA              *((volatile unsigned int*)IMGDMA_ROT_DMA2_QUEUE_WSTA_REG)            
#define REG_IMGDMA_ROT_DMA2_WR_BASE                 *((volatile unsigned int*)IMGDMA_ROT_DMA2_WR_BASE_REG)               
#define REG_IMGDMA_ROT_DMA2_WPT_ADVANCE             *((volatile unsigned int*)IMGDMA_ROT_DMA2_WPT_ADVANCE_REG)           
#define REG_IMGDMA_ROT_DMA2_DES_AVAILABLE_SPACE     *((volatile unsigned int*)IMGDMA_ROT_DMA2_DES_AVAILABLE_SPACE_REG)   
#define REG_IMGDMA_ROT_DMA2_QUEUE_DATA              *((volatile unsigned int*)IMGDMA_ROT_DMA2_QUEUE_DATA_REG)            
#define REG_IMGDMA_ROT_DMA2_QUEUE_BASE              *((volatile unsigned int*)IMGDMA_ROT_DMA2_QUEUE_BASE_REG)            
#define REG_IMGDMA_ROT_DMA2_EXEC_CNT                *((volatile unsigned int*)IMGDMA_ROT_DMA2_EXEC_CNT_REG)              
#define REG_IMGDMA_ROT_DMA2_DROPPED_FRAME_CNT       *((volatile unsigned int*)IMGDMA_ROT_DMA2_DROPPED_FRAME_CNT_REG)     
#define REG_IMGDMA_ROT_DMA2_LCD                     *((volatile unsigned int*)IMGDMA_ROT_DMA2_LCD_REG)                   
#define REG_IMGDMA_ROT_DMA2_LCD_STA                 *((volatile unsigned int*)IMGDMA_ROT_DMA2_LCD_STA_REG)               
#define REG_IMGDMA_ROT_DMA2_LCD_RPT_ADVANCE         *((volatile unsigned int*)IMGDMA_ROT_DMA2_LCD_RPT_ADVANCE_REG)       
#define REG_IMGDMA_ROT_DMA2_LCD_RPT_BASE            *((volatile unsigned int*)IMGDMA_ROT_DMA2_LCD_RPT_BASE_REG)          
#define REG_IMGDMA_ROT_DMA2_SLOW_DOWN               *((volatile unsigned int*)IMGDMA_ROT_DMA2_SLOW_DOWN_REG)             
#define REG_IMGDMA_ROT_DMA2_BUF_ADDR0               *((volatile unsigned int*)IMGDMA_ROT_DMA2_BUF_ADDR0_REG)             
#define REG_IMGDMA_ROT_DMA2_BUF_ADDR1               *((volatile unsigned int*)IMGDMA_ROT_DMA2_BUF_ADDR1_REG)             
#define REG_IMGDMA_ROT_DMA2_BUF_ADDR2               *((volatile unsigned int*)IMGDMA_ROT_DMA2_BUF_ADDR2_REG)             
#define REG_IMGDMA_ROT_DMA2_BUF_ADDR3               *((volatile unsigned int*)IMGDMA_ROT_DMA2_BUF_ADDR3_REG)             
#define REG_IMGDMA_ROT_DMA2_DST_STR_ADDR            *((volatile unsigned int*)IMGDMA_ROT_DMA2_DST_STR_ADDR)
#define REG_IMGDMA_ROT_DMA2_Y_DST_STR_ADDR          *((volatile unsigned int*)IMGDMA_ROT_DMA2_Y_DST_STR_ADDR_REG)       
#define REG_IMGDMA_ROT_DMA2_U_DST_STR_ADDR          *((volatile unsigned int*)IMGDMA_ROT_DMA2_U_DST_STR_ADDR_REG)       
#define REG_IMGDMA_ROT_DMA2_V_DST_STR_ADDR          *((volatile unsigned int*)IMGDMA_ROT_DMA2_V_DST_STR_ADDR_REG)       
#define REG_IMGDMA_ROT_DMA2_SRC_SIZE                *((volatile unsigned int*)IMGDMA_ROT_DMA2_SRC_SIZE_REG)              
#define REG_IMGDMA_ROT_DMA2_CLIP_SIZE               *((volatile unsigned int*)IMGDMA_ROT_DMA2_CLIP_SIZE_REG)             
#define REG_IMGDMA_ROT_DMA2_CLIP_OFFSET             *((volatile unsigned int*)IMGDMA_ROT_DMA2_CLIP_OFFSET_REG)           
#define REG_IMGDMA_ROT_DMA2_DST_SIZE                *((volatile unsigned int*)IMGDMA_ROT_DMA2_DST_SIZE_REG)              
#define REG_IMGDMA_ROT_DMA2_CLIP_W_IN_BYTE          *((volatile unsigned int*)IMGDMA_ROT_DMA2_CLIP_W_IN_BYTE_REG)        
#define REG_IMGDMA_ROT_DMA2_CLIP_H_IN_BYTE          *((volatile unsigned int*)IMGDMA_ROT_DMA2_CLIP_H_IN_BYTE_REG)        
#define REG_IMGDMA_ROT_DMA2_CON                     *((volatile unsigned int*)IMGDMA_ROT_DMA2_CON_REG)                   
#define REG_IMGDMA_ROT_DMA2_DITHER                  *((volatile unsigned int*)IMGDMA_ROT_DMA2_DITHER)   
#else
#define REG_IMGDMA_ROT_DMA2_IRQ_FLAG                (ROT_DMA2_IRQ_FLAG)   
#define REG_IMGDMA_ROT_DMA2_IRQ_FLAG_CLR            ()      
#define REG_IMGDMA_ROT_DMA2_CFG                     (ROT_DMA2_CFG)   
#define REG_IMGDMA_ROT_DMA2_IN_SEL                  (ROT_DMA2_IN_SEL)   
#define REG_IMGDMA_ROT_DMA2_STOP                    (ROT_DMA2_STOP)   
#define REG_IMGDMA_ROT_DMA2_EN                      (ROT_DMA2_EN)   
#define REG_IMGDMA_ROT_DMA2_RESET                   (ROT_DMA2_RESET)   
#define REG_IMGDMA_ROT_DMA2_LOCK                    ()      
#define REG_IMGDMA_ROT_DMA2_QUEUE_RSTA              (ROT_DMA2_QUEUE_RSTA)   
#define REG_IMGDMA_ROT_DMA2_RD_BASE                 (ROT_DMA2_RD_BASE)   
#define REG_IMGDMA_ROT_DMA2_RPT_ADVANCE             (ROT_DMA2_RPT_ADVANCE)   
#define REG_IMGDMA_ROT_DMA2_QUEUE_WSTA              (ROT_DMA2_QUEUE_WSTA)   
#define REG_IMGDMA_ROT_DMA2_WR_BASE                 (ROT_DMA2_WR_BASE)   
#define REG_IMGDMA_ROT_DMA2_WPT_ADVANCE             (ROT_DMA2_WPT_ADVANCE)   
#define REG_IMGDMA_ROT_DMA2_DES_AVAILABLE_SPACE     ()      
#define REG_IMGDMA_ROT_DMA2_QUEUE_DATA              (ROT_DMA2_QUEUE_DATA)   
#define REG_IMGDMA_ROT_DMA2_QUEUE_BASE              (ROT_DMA2_QUEUE_BASE)   
#define REG_IMGDMA_ROT_DMA2_EXEC_CNT                (ROT_DMA2_EXEC_CNT)   
#define REG_IMGDMA_ROT_DMA2_DROPPED_FRAME_CNT       (ROT_DMA2_DROPPED_FRAME_CNT)   
#define REG_IMGDMA_ROT_DMA2_LCD                     (ROT_DMA2_LCD)   
#define REG_IMGDMA_ROT_DMA2_LCD_STA                 (ROT_DMA2_LCD_STA)   
#define REG_IMGDMA_ROT_DMA2_LCD_RPT_ADVANCE         (ROT_DMA2_LCD_RPT_ADVANCE)   
#define REG_IMGDMA_ROT_DMA2_LCD_RPT_BASE            (ROT_DMA2_LCD_RD_BASE)   
#define REG_IMGDMA_ROT_DMA2_SLOW_DOWN               (ROT_DMA2_SLOW_DOWN)   
#define REG_IMGDMA_ROT_DMA2_BUF_ADDR0               (ROT_DMA2_BUF_BASE_ADDR0)   
#define REG_IMGDMA_ROT_DMA2_BUF_ADDR1               (ROT_DMA2_BUF_BASE_ADDR1)   
#define REG_IMGDMA_ROT_DMA2_BUF_ADDR2               (ROT_DMA2_BUF_BASE_ADDR2)   
#define REG_IMGDMA_ROT_DMA2_BUF_ADDR3               (ROT_DMA2_BUF_BASE_ADDR3)  
#define REG_IMGDMA_ROT_DMA2_DST_STR_ADDR            (ROT_DMA2_DST_STR_ADDR)  
#define REG_IMGDMA_ROT_DMA2_Y_DST_STR_ADDR          (ROT_DMA2_Y_DST_STR_ADDR)  
#define REG_IMGDMA_ROT_DMA2_U_DST_STR_ADDR          (ROT_DMA2_U_DST_STR_ADDR)  
#define REG_IMGDMA_ROT_DMA2_V_DST_STR_ADDR          (ROT_DMA2_V_DST_STR_ADDR)  
#define REG_IMGDMA_ROT_DMA2_SRC_SIZE                (ROT_DMA2_SRC_SIZE)   
#define REG_IMGDMA_ROT_DMA2_CLIP_SIZE               (ROT_DMA2_CLIP_SIZE)   
#define REG_IMGDMA_ROT_DMA2_CLIP_OFFSET             (ROT_DMA2_CLIP_OFFSET)   
#define REG_IMGDMA_ROT_DMA2_DST_SIZE                (ROT_DMA2_DST_SIZE)   
#define REG_IMGDMA_ROT_DMA2_CLIP_W_IN_BYTE          (ROT_DMA2_CLIP_W_IN_BYTE)   
#define REG_IMGDMA_ROT_DMA2_CLIP_H_IN_BYTE          (ROT_DMA2_CLIP_H_IN_BYTE)   
#define REG_IMGDMA_ROT_DMA2_CON                     (ROT_DMA2_CON)   
#define REG_IMGDMA_ROT_DMA2_DITHER                  (ROT_DMA2_DITHER)
#endif // MDP_C_MODEL


/**
 * \brief Check if IRT0 is started or not.
 */
/// Is enabled
#define IMGDMA_ROTDMA2_IS_ENABLED() \
    ((0x1 == (REG_IMGDMA_ROT_DMA2_EN & 0x1)) ? KAL_TRUE : KAL_FALSE)

// Start ROTDMA2
#define IMGDMA_ROTDMA2_START() \
    do { REG_IMGDMA_ROT_DMA2_EN = 0x1; } while(0)

// Stop ROTDMA2, stop at frame end
#define IMGDMA_ROTDMA2_STOP() \
    do { REG_IMGDMA_ROT_DMA2_STOP = 0x1; } while(0)

// Warm reset ROTDMA2, reset at GMC transaction end
#define IMGDMA_ROTDMA2_WARM_RESET() \
    do { REG_IMGDMA_ROT_DMA2_RESET = 0x2; } while(0)

// Hard reset ROTDMA2, reset immediately, pending GMC transaction may cause state machine incorrect
#define IMGDMA_ROTDMA2_HARD_RESET() \
    do { REG_IMGDMA_ROT_DMA2_RESET = 0x1; \
         REG_IMGDMA_ROT_DMA2_RESET = 0x0; } while(0)

#define IMGDMA_ROTDMA2_INTERRUPT_ENABLE() \
    do { REG_IMGDMA_ROT_DMA2_CON |= 0x80000000; } while(0)

#define IMGDMA_ROTDMA2_INTERRUPT_DISABLE() \
    do { REG_IMGDMA_ROT_DMA2_CON &= ~0x80000000; } while(0)

#define IMGDMA_ROTDMA2_AUTO_LOOP_ENABLE() \
    do { REG_IMGDMA_ROT_DMA2_CFG |= 0x00000001; } while(0)

#define IMGDMA_ROTDMA2_AUTO_LOOP_DISABLE() \
    do { REG_IMGDMA_ROT_DMA2_CFG &= ~0x00000001; } while(0)

// Descriptor mode
#define IMGDMA_ROTDMA2_DESCRIPTOR_MODE() \
    do { REG_IMGDMA_ROT_DMA2_CFG |= 0x00000080; } while(0)

// Register mode
#define IMGDMA_ROTDMA2_REGISTER_MODE() \
    do { REG_IMGDMA_ROT_DMA2_CFG &= ~0x00000080; } while(0)

// Enable frame sync
#define IMGDMA_ROTDMA2_FRAME_SYNC_ENABLE() \
    do { REG_IMGDMA_ROT_DMA2_CFG |= 0x80000000; } while(0)

// Disable frame sync
#define IMGDMA_ROTDMA2_FRAME_SYNC_DISABLE() \
    do { REG_IMGDMA_ROT_DMA2_CFG &= ~0x80000000; } while(0)



#define IMGDMA_ROTDMA_LCD_HWTRIG_BIT                0x00000001
#define IMGDMA_ROTDMA_LCD_HWSYNC_BIT                0x00000002
#define IMGDMA_ROTDMA_LCD_HWSYNCFULL_STALL          0x00000000 /**< When LCD not done, ROTDMA is stalled... */
#define IMGDMA_ROTDMA_LCD_HWSYNCFULL_DROP           0x00000004 /**< When LCD not done, ROTDMA not redraw but drop incoming frame. */
#define IMGDMA_ROTDMA_LCD_HWTRIG_ALL                0x00000010
#define IMGDMA_ROTDMA_LCD_WARM_RST_WAIT_LCD         0x00008000

/** 
 *  WDMA HW trigger LCD options! 
 *  WARNING: choose only one from below five!
 */
// No HW trigger LCD
#define IMGDMA_ROTDMA2_HW_TRIGGER_LCD_DISABLE() \
    do { REG_IMGDMA_ROT_DMA2_LCD = 0x0; } while(0)

// Enable HW trigger LCD but no sync
#define IMGDMA_ROTDMA2_HW_TRIGGER_LCD_BUT_NO_SYNC() \
    do { REG_IMGDMA_ROT_DMA2_LCD = IMGDMA_ROTDMA_LCD_HWTRIG_BIT; } while(0)

// Enable HW trigger LCD and sync w/ LCD, if LCD busy, stall WDMA2
#define IMGDMA_ROTDMA2_HW_TRIGGER_LCD_SYNC_N_STALL() \
    do { REG_IMGDMA_ROT_DMA2_LCD = \
        ((IMGDMA_ROTDMA_LCD_HWTRIG_BIT | IMGDMA_ROTDMA_LCD_HWSYNC_BIT) | IMGDMA_ROTDMA_LCD_HWSYNCFULL_STALL); } while(0)

// Enable HW trigger LCD and sync w/ LCD, if LCD busy, WDMA2 drops incoming data (frame or pixels?) <== Recommanded when using HW trigger mode...
#define IMGDMA_ROTDMA2_HW_TRIGGER_LCD_SYNC_N_DROP() \
    do { REG_IMGDMA_ROT_DMA2_LCD = \
        ((IMGDMA_ROTDMA_LCD_HWTRIG_BIT | IMGDMA_ROTDMA_LCD_HWSYNC_BIT) | IMGDMA_ROTDMA_LCD_HWSYNCFULL_DROP); } while(0)

// WARNING: only use w/o enable WDMA engine
#define IMGDMA_ROTDMA2_STALL_PREV_ENGINE() \
    do { REG_IMGDMA_ROT_DMA2_IN_SEL = 0x0; } while(0)

// WARNING: only use w/o enable WDMA engine
#define IMGDMA_ROTDMA2_DROP_PREV_ENGINE() \
    do { REG_IMGDMA_ROT_DMA2_IN_SEL = 0x1; } while(0)

#define IMGDMA_ROTDMA2_CON_OUTPUT_FORMAT_MASK        0x00000007
#define IMGDMA_ROTDMA2_CON_OUTPUT_FORMAT_ARGB8888    0x00000000
#define IMGDMA_ROTDMA2_CON_OUTPUT_FORMAT_RGB888      0x00000001
#define IMGDMA_ROTDMA2_CON_OUTPUT_FORMAT_RGB565      0x00000002
#define IMGDMA_ROTDMA2_CON_OUTPUT_FORMAT_BGR888      0x00000003
#define IMGDMA_ROTDMA2_CON_OUTPUT_FORMAT_YUYV422     0x00000004
#define IMGDMA_ROTDMA2_CON_OUTPUT_FORMAT_YUY2        0x00000005
#define IMGDMA_ROTDMA2_CON_OUTPUT_FORMAT_PLANAR_YUV  0x00000007

#define IMGDMA_ROTDMA2_CON_A_VALUE_MASK              0x0000ff00
#define IMGDMA_ROTDMA2_CON_ROUND_BIT                 0x00000008 /**< rounding when output RGB format */

/** Holmes added */
#define IMGDMA_ROTDMA2_SEG0_EN						 0x00010000	
#define IMGDMA_ROTDMA2_SEG1_EN						 0x00020000	
#define IMGDMA_ROTDMA2_SEG2_EN						 0x00040000	
#define IMGDMA_ROTDMA2_SEG3_EN						 0x00080000
#define IMGDMA_ROTDMA2_SEG4_EN						 0x00100000
#define IMGDMA_ROTDMA2_SEG5_EN						 0x00200000	
#define IMGDMA_ROTDMA2_SEG6_EN						 0x00400000
#define IMGDMA_ROTDMA2_SEG7_EN						 0x00800000	
#define IMGDMA_ROTDMA2_SEG8_EN						 0x01000000
#define IMGDMA_ROTDMA2_SEG9_EN						 0x02000000	
#define IMGDMA_ROTDMA2_SEG10_EN						 0x04000000	

#define IMGDMA_ROTDMA2_CFG_QUEUEDEPTH_MASK           0x00000F00


#define IMGDMA_ROTDMA2_SET_OUTPUT_FORMAT(format) \
    do { REG_IMGDMA_ROT_DMA2_CON = \
        ((REG_IMGDMA_ROT_DMA2_CON & (~IMGDMA_ROTDMA2_CON_OUTPUT_FORMAT_MASK)) | (format)); } while(0)

#define IMGDMA_ROTDMA2_RGB_ROUND_ENABLE() \
    do { REG_IMGDMA_ROT_DMA2_CON |= IMGDMA_ROTDMA2_CON_ROUND_BIT; } while(0)

#define IMGDMA_ROTDMA2_RGB_ROUND_DISABLE() \
    do { REG_IMGDMA_ROT_DMA2_CON &= ~IMGDMA_ROTDMA2_CON_ROUND_BIT; } while(0)

#define IMGDMA_ROTDMA2_SET_OUTPUT_YUV444() \
    do { REG_IMGDMA_ROT_DMA2_CON = \
        ((REG_IMGDMA_ROT_DMA2_CON & (~0x03fc0007)) | 0x01540007); } while(0)

#define IMGDMA_ROTDMA2_SET_OUTPUT_YUV422() \
    do { REG_IMGDMA_ROT_DMA2_CON = \
        ((REG_IMGDMA_ROT_DMA2_CON & (~0x03fc0007)) | 0x01640007); } while(0)

#define IMGDMA_ROTDMA2_SET_OUTPUT_YUV420() \
    do { REG_IMGDMA_ROT_DMA2_CON = \
        ((REG_IMGDMA_ROT_DMA2_CON & (~0x03fc0007)) | 0x02640007); } while(0)

#define IMGDMA_ROTDMA2_SET_OUTPUT_YUV411() \
    do { REG_IMGDMA_ROT_DMA2_CON = \
        ((REG_IMGDMA_ROT_DMA2_CON & (~0x03fc0007)) | 0x01740007); } while(0)

#define IMGDMA_ROTDMA2_SET_OUTPUT_YUV400() \
    do { REG_IMGDMA_ROT_DMA2_CON = \
        ((REG_IMGDMA_ROT_DMA2_CON & (~0x03fc0007)) | 0x00440007); } while(0)


#define IMGDMA_ROTDMA2_ROT_0() \
    do { REG_IMGDMA_ROT_DMA2_CON = \
        ((REG_IMGDMA_ROT_DMA2_CON & ~0x18000000) | 0x0); } while(0)

#define IMGDMA_ROTDMA2_ROT_90CW() \
    do { REG_IMGDMA_ROT_DMA2_CON = \
        ((REG_IMGDMA_ROT_DMA2_CON & ~0x18000000) | 0x08000000); } while(0)

#define IMGDMA_ROTDMA2_ROT_180CW() \
    do { REG_IMGDMA_ROT_DMA2_CON = \
        ((REG_IMGDMA_ROT_DMA2_CON & ~0x18000000) | 0x10000000); } while(0)

#define IMGDMA_ROTDMA2_ROT_270CW() \
    do { REG_IMGDMA_ROT_DMA2_CON = \
        ((REG_IMGDMA_ROT_DMA2_CON & ~0x18000000) | 0x18000000); } while(0)

#define IMGDMA_ROTDMA2_FLIP_ENABLE() \
    do { REG_IMGDMA_ROT_DMA2_CON |= 0x20000000; } while(0)

#define IMGDMA_ROTDMA2_FLIP_DISABLE() \
    do { REG_IMGDMA_ROT_DMA2_CON &= ~0x20000000; } while(0)

#define IMGDMA_ROTDMA2_SET_ALPHA(alpha) \
    do { REG_IMGDMA_ROT_DMA2_CON = \
        ((REG_IMGDMA_ROT_DMA2_CON & ~IMGDMA_ROTDMA2_CON_A_VALUE_MASK) | \
         (((alpha) << 8) & IMGDMA_ROTDMA2_CON_A_VALUE_MASK)); } while(0)

	/** Holmes added */
#define IMGDMA_ROTDMA2_DITHER_ENABLE() \
	do { REG_IMGDMA_ROT_DMA2_DITHER |= 0x1; } while(0)
	
#define IMGDMA_ROTDMA2_DITHER_DISABLE() \
	do { REG_IMGDMA_ROT_DMA2_DITHER &= ~0x1; } while(0)
	
#define IMGDMA_ROTDMA2_PROTECT_ENABLE() \
	do { REG_IMGDMA_ROT_DMA2_SLOW_DOWN |= 0x8000; } while(0)
			
#define IMGDMA_ROTDMA2_PROTECT_DISABLE() \
	do { REG_IMGDMA_ROT_DMA2_SLOW_DOWN &= ~0x8000; } while(0)
	
#define IMGDMA_ROTDMA2_RESAMPLE_ENABLE() \
	do { REG_IMGDMA_ROT_DMA2_SLOW_DOWN |= 0x100; } while(0)
				
#define IMGDMA_ROTDMA2_RESAMPLE_DISABLE() \
	do { REG_IMGDMA_ROT_DMA2_SLOW_DOWN &= ~0x100; } while(0)
	
#define IMGDMA_ROTDMA2_IS_RESAMPLE_USED() \
	((REG_IMGDMA_ROT_DMA2_SLOW_DOWN&0x100)&& 1) 
		
#define IMGDMA_ROTDMA2_SET_SEED(seed1,seed2,seed3) \
    do {REG_IMGDMA_ROT_DMA2_DITHER = \
         ((REG_IMGDMA_ROT_DMA2_DITHER & 0x1) | \
         (((seed1)<< 20)|((seed2)<< 16)|((seed3)<< 12) )); } while(0)

//Add descriptor mode command
#define IMGDMA_ROTDMA2_SET_QUEUE_BASE_ADDR(n)   \
    do {REG_IMGDMA_ROT_DMA2_QUEUE_BASE= (n&0xFFFFFFFF); } while(0)

#define IMGDMA_ROTDMA2_PUSH_QUEUE_DATA(n)   \
    do {REG_IMGDMA_ROT_DMA2_QUEUE_DATA= (n&0xFFFFFFFF); } while(0)

#define IMGDMA_ROTDMA2_IS_QUEUE_WRITE_BUSY() \
	(((REG_IMGDMA_ROT_DMA2_QUEUE_WSTA&0x1)==1) ? KAL_TRUE : KAL_FALSE)	

#define IMGDMA_ROTDMA2_SET_DESCIPTOR_SEG(n)   \
    do {REG_IMGDMA_ROT_DMA2_CFG = \
        (REG_IMGDMA_ROT_DMA2_CFG | (n&0x07FF0000)); } while(0)

#define IMGDMA_ROTDMA2_SET_QUEUE_DEPTH(depth) \
    do { REG_IMGDMA_ROT_DMA2_CFG = \
        ((REG_IMGDMA_ROT_DMA2_CFG & ~IMGDMA_ROTDMA2_CFG_QUEUEDEPTH_MASK) | \
         (IMGDMA_ROTDMA2_CFG_QUEUEDEPTH_MASK & ((depth) << 8))); } while(0)

#define IMGDMA_ROTDMA2_QUEUE_EMPTY_DROP() \
    do { REG_IMGDMA_ROT_DMA2_CFG |= 0x00008000; } while(0)

#define IMGDMA_ROTDMA2_QUEUE_EMPTY_STALL() \
    do { REG_IMGDMA_ROT_DMA2_CFG &= ~0x00008000; } while(0)


/**
 * \brief IRT0 structure
 *
 * Programmers can use this structure to set up IRT0.
 */
typedef struct
{
    kal_bool                      intr_en; /**< enable int or not */

	/** Holmes added */
    kal_bool                      resample_en; /**< resample enable */
    kal_bool                      isp_datapath; /**< isp datapath enable */
	kal_bool                      dither_en;  /**< dither enable */

    
    idp_lisr_intr_cb_t            intr_cb;
    idp_lisr_intr_cb_param_t      intr_cb_param;
    
    kal_bool                      descriptor_mode;
    
    kal_bool                      auto_loop; /**< auto loop mode */

    kal_bool                      stall_prev_engine;
    kal_bool                      drop_prev_engine;
    kal_bool                      q_empty_drop;
	
    kal_bool                      hw_frame_sync;
  
    img_rot_angle_enum_t          rot_angle; /**< rotate direction */
    kal_bool                      flip; /**< flip or not */
      
    kal_bool                      hw_trigger_lcd; /**< enable hw trigger LCD */
    idp_lcd_hw_trigger_mode_t     hw_trigger_mode;
    kal_bool                      hw_trigger_rst_wait_lcd;
    kal_bool                      fgLcdRdPtrAdvance;

    kal_uint8                     queue_depth; /**[1,16] */

    kal_uint32                    y_dest_start_addr;
    kal_uint32                    u_dest_start_addr;
    kal_uint32                    v_dest_start_addr;


    kal_bool                      rgb_output;
    img_color_fmt_rgb_enum_t      rgb_color_fmt; /**< output rgb format */
    img_color_fmt_yuv_enum_t      yuv_color_fmt; /**< output yuv format */

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
    kal_uint32                    _y_dest_start_addr;
    kal_uint32                    _u_dest_start_addr;
    kal_uint32                    _v_dest_start_addr;
    kal_uint32                    work_mem_line_count;
    kal_uint32                    wm_addr_0;
    kal_uint32                    wm_addr_1;
    kal_uint32                    wm_addr_2;
    kal_uint32                    wm_addr_3;

    /** Dithering Seed  */
    kal_uint8                     dithering_seed1;
    kal_uint8                     dithering_seed2;
    kal_uint8                     dithering_seed3;    
    
    //// For easy debugging...
    kal_uint8                 _yh;
    kal_uint8                 _yv;
    kal_uint8                 _uh;
    kal_uint8                 _uv;
    kal_uint8                 _vh;
    kal_uint8                 _vv;
} idp_imgdma_rotdma2_struct;

IDP_HW_COMMON_API_DECLARATION(imgdma_rotdma2)

extern void *idp_imgdma_rotdma2_intr_cb_param;
extern void (*idp_imgdma_rotdma2_intr_cb)(void *);

extern kal_bool idp_imgdma_rotdma2_config_real(
    idp_imgdma_rotdma2_struct * const rotdma2_struct, 
    kal_bool const config_to_hardware);

extern kal_bool idp_imgdma_rotdma2_get_working_mem_real(
    kal_bool const use_internal_mem,
    idp_imgdma_rotdma2_struct * const rotdma2_struct,
    kal_bool const do_alloc,
    kal_uint32 const max_allowable_size);

extern kal_bool
idp_imgdma_rotdma2_start_real(
    idp_imgdma_rotdma2_struct const * const p_rotdma2_struct);

extern kal_bool
idp_imgdma_rotdma2_stop_real(
    idp_imgdma_rotdma2_struct const * const p_rotdma2_struct);

extern void
idp_imgdma_rotdma2_open_real(void);

extern void
idp_imgdma_ROTDMA2_queue_push(kal_uint32 const data);

extern void
idp_imgdma_ROTDMA2_set_queue_depth(kal_uint32 const data);

extern void
idp_imgdma_ROTDMA2_set_queue_base_addr(kal_uint32 const data);

extern void
idp_imgdma_ROTDMA2_set_queue_segs(kal_uint32 const data);

extern void
idp_imgdma_ROTDMA2_enable_descriptor_mode(kal_bool enable);

extern void
idp_imgdma_ROTDMA2_queue_empty_drop(kal_bool enable);
/** @} */

#endif // #if defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6256_SERIES)

#endif // __idp_imgdma_rotdma2_mt6276_h__
