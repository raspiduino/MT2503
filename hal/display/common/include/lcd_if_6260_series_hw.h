/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001-2007
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


/*******************************************************************************
 * Filename:
 * ---------
 * lcd_if.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is to define LCD HW register in 6250 chips.
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 04 24 2014 edwardyc.lin
 * removed!
 * 	.
 *
 * 04 14 2014 edwardyc.lin
 * removed!
 * 	.
 *
 * 03 05 2014 edwardyc.lin
 * removed!
 * 	.
 *
 * 01 25 2013 ricky.lin
 * removed!
 * .
 *
 * 01 21 2013 ricky.lin
 * removed!
 * .
 *
 * 01 21 2013 joey.pan
 * removed!
 * Mrege PQv2 modification.
 *
 * 01 21 2013 joey.pan
 * removed!
 * Merge PQv2 modification.
 *
 * 01 15 2013 joey.pan
 * removed!
 * Turn off pq function in image playback.
 *
 * 01 14 2013 joey.pan
 * removed!
 * Fix PQ color enable macro typos.
 *
 * 01 03 2013 joey.pan
 * removed!
 * Sync display de-feature settings.
 *
 * 01 03 2013 joey.pan
 * removed!
 * Add LCD color enable control.
 *
 * 11 12 2012 joey.pan
 * removed!
 * Fix MT6260 LCD build error.
 *
 *
 * 
 *******************************************************************************/
#ifndef __LCD_IF_6260_SERIES_HW_H__
#define __LCD_IF_6260_SERIES_HW_H__

#include "kal_release.h"
#include "drv_features_display.h"
#include "drv_sw_features_display.h"

#if defined(DRV_LCD_MT6260_SERIES)
   #define LCD_PARALLEL_CTRL0_REG      (LCD_base+0x0F00)
   #define LCD_PARALLEL_DATA0_REG      (LCD_base+0x0F10)
   #define LCD_PARALLEL_CTRL1_REG      (LCD_base+0x0F20)
   #define LCD_PARALLEL_DATA1_REG      (LCD_base+0x0F30)
   #define LCD_PARALLEL_CTRL2_REG      (LCD_base+0x0F40)
   #define LCD_PARALLEL_DATA2_REG      (LCD_base+0x0F50)
   #define LCD_SERIAL_CTRL0_REG        (LCD_base+0x0F80)
   #define LCD_SERIAL_DATA0_REG        (LCD_base+0x0F90)
   #define LCD_SERIAL_CTRL1_REG        (LCD_base+0x0FA0)
   #define LCD_SERIAL_DATA1_REG        (LCD_base+0x0FB0)
   #define LCD_SERIAL_SPE_CTRL0_REG        (LCD_base+0x0F88)
   #define LCD_SERIAL_SPE_DATA0_REG        (LCD_base+0x0F98)
   #define LCD_SERIAL_SPE_CTRL1_REG        (LCD_base+0x0FA8)
   #define LCD_SERIAL_SPE_DATA1_REG        (LCD_base+0x0FB8)


   #define LCD_PARALLEL0_A0_LOW_ADDR   (LCD_base+0x0F00)
   #define LCD_PARALLEL0_A0_HIGH_ADDR  (LCD_base+0x0F10)
   #define LCD_PARALLEL1_A0_LOW_ADDR   (LCD_base+0x0F20)
   #define LCD_PARALLEL1_A0_HIGH_ADDR  (LCD_base+0x0F30)
   #define LCD_PARALLEL2_A0_LOW_ADDR   (LCD_base+0x0F40)
   #define LCD_PARALLEL2_A0_HIGH_ADDR  (LCD_base+0x0F50)
   #define LCD_SERIAL0_A0_LOW_ADDR     (LCD_base+0x0F80)
   #define LCD_SERIAL0_A0_HIGH_ADDR    (LCD_base+0x0F90)
   #define LCD_SERIAL1_A0_LOW_ADDR     (LCD_base+0x0FA0)
   #define LCD_SERIAL1_A0_HIGH_ADDR    (LCD_base+0x0FB0)

   #define LCD_SERIAL0_A0_SPE_LOW_ADDR     (LCD_base+0x0F88)
   #define LCD_SERIAL0_A0_SPE_HIGH_ADDR    (LCD_base+0x0F98)
   #define LCD_SERIAL1_A0_SPE_LOW_ADDR     (LCD_base+0x0FA8)
   #define LCD_SERIAL1_A0_SPE_HIGH_ADDR    (LCD_base+0x0FB8)

   #define LCD_STA_REG                 (LCD_base+0x0000)
   #define LCD_INT_ENABLE_REG          (LCD_base+0x0004)
   #define LCD_INT_STATUS_REG          (LCD_base+0x0008)
   #define LCD_START_REG               (LCD_base+0x000C)
   #define LCD_RSTB_REG                (LCD_base+0x0010)

   #define LCD_SIF_PIX_CON_REG         (LCD_base+0x0018)
   #define LCD_SIF0_TIMING_REG         (LCD_base+0x001C)
   #define LCD_SIF1_TIMING_REG         (LCD_base+0x0020)
   #define LCD_SIF_CON_REG             (LCD_base+0x0028)
   #define LCD_SIF_CS_REG              (LCD_base+0x002C)
   #define LCD_SIF_PAD_SEL_REG         (LCD_base+0x0300)
   #define LCD_SIF_STR_BYTE_CON_REG    (LCD_base+0x0270)
   #define LCD_SIF_WR_STR_BYTE_REG    (LCD_base+0x0278)
   #define LCD_SIF_RD_STR_BYTE_REG    (LCD_base+0x027C)

   #define LCD_PARALLEL0_CONFIG_REG    (LCD_base+0x0030)
   #define LCD_PARALLEL1_CONFIG_REG    (LCD_base+0x0034)
   #define LCD_PARALLEL2_CONFIG_REG    (LCD_base+0x0038)
   #define LCD_PARALLEL_PDW_REG        (LCD_base+0x003C)

   //#define LCD_GAMMA_CON_REG           (LCD_base+0x0040)

   #define LCD_CALC_HTT_REG            (LCD_base+0x0044)
   #define LCD_SYNC_LCM_SIZE_REG       (LCD_base+0x0048)
   #define LCD_SYNC_CNT_REG            (LCD_base+0x004C)

   #define LCD_TECON_REG               (LCD_base+0x0050)
   #define LCD_GMCCON_REG              (LCD_base+0x0054)

   #define LCD_PALETTE_ADDR_REG        (LCD_base+0x007C)

   #define LCD_ROI_CTRL_REG            (LCD_base+0x0080)
   #define LCD_ROI_OFFSET_REG          (LCD_base+0x0084)
   #define LCD_ROI_CMD_ADDR_REG        (LCD_base+0x0088)
   #define LCD_ROI_DATA_ADDR_REG       (LCD_base+0x008C)
   #define LCD_ROI_SIZE_REG            (LCD_base+0x0090)
   #define LCD_ROI_BG_COLOR_REG        (LCD_base+0x009C)

   #define LCD_LAYER0_BASE_ADDR        (LCD_base+0x00B0)
   #define LCD_LAYER0_CTRL_REG         (LCD_base+0x00B0)
   #define LCD_LAYER0_SRC_KEY_REG      (LCD_base+0x00B4)
   #define LCD_LAYER0_OFFSET_REG       (LCD_base+0x00B8)
   #define LCD_LAYER0_BUFF_ADDR_REG    (LCD_base+0x00BC)
   #define LCD_LAYER0_SIZE_REG         (LCD_base+0x00C0)
   #define LCD_LAYER0_MEM_OFFSET_REG   (LCD_base+0x00C8)
   #define LCD_LAYER0_MEM_PITCH_REG    (LCD_base+0x00CC)
   
   #define LCD_LAYER1_CTRL_REG         (LCD_base+0x00E0)
   #define LCD_LAYER1_SRC_KEY_REG      (LCD_base+0x00E4)
   #define LCD_LAYER1_OFFSET_REG       (LCD_base+0x00E8)
   #define LCD_LAYER1_BUFF_ADDR_REG    (LCD_base+0x00EC)
   #define LCD_LAYER1_SIZE_REG         (LCD_base+0x00F0)
   #define LCD_LAYER1_MEM_OFFSET_REG   (LCD_base+0x00F8)
   #define LCD_LAYER1_MEM_PITCH_REG    (LCD_base+0x00FC)

   #define LCD_LAYER2_CTRL_REG         (LCD_base+0x0110)
   #define LCD_LAYER2_SRC_KEY_REG      (LCD_base+0x0114)
   #define LCD_LAYER2_OFFSET_REG       (LCD_base+0x0118)
   #define LCD_LAYER2_BUFF_ADDR_REG    (LCD_base+0x011C)
   #define LCD_LAYER2_SIZE_REG         (LCD_base+0x0120)
   #define LCD_LAYER2_MEM_OFFSET_REG   (LCD_base+0x0128)
   #define LCD_LAYER2_MEM_PITCH_REG    (LCD_base+0x012C)
   
   #define LCD_LAYER3_CTRL_REG         (LCD_base+0x0140)
   #define LCD_LAYER3_SRC_KEY_REG      (LCD_base+0x0144)
   #define LCD_LAYER3_OFFSET_REG       (LCD_base+0x0148)
   #define LCD_LAYER3_BUFF_ADDR_REG    (LCD_base+0x014C)
   #define LCD_LAYER3_SIZE_REG         (LCD_base+0x0150)
   #define LCD_LAYER3_MEM_OFFSET_REG   (LCD_base+0x0158)
   #define LCD_LAYER3_MEM_PITCH_REG    (LCD_base+0x015C)

   #define REG_LCD_PALETTE_ADDR        (*((volatile unsigned int *)   LCD_PALETTE_ADDR_REG))
   #define SET_LUT0_PALETTE_BUFF_ADDRESS(addr)      REG_LCD_PALETTE_ADDR = (unsigned int) addr

   /// command queue, max 64 entries
   #define LCD_CMD_PARAMETER0_ADDR     (LCD_base + 0x0C00)

   #define LCD_DITHER_CON_REG          (LCD_base + 0x0170)

   #define LCD_NLI_START_REG           (LCD_base + 0x0200)
   #define LCD_NLI_CLEAR_REG           (LCD_base + 0x0204)


   #define LCD_FRAME_COUNT_CON_REG     (LCD_base + 0x0220)
   #define LCD_FRAME_COUNT_REG         (LCD_base + 0x0224)

   #define LCD_ULTRA_CON_REG           (LCD_base + 0x0240)
   #define LCD_CONSUME_RATE_REG        (LCD_base + 0x0244)
   #define LCD_DBI_ULTRA_TH_REG        (LCD_base + 0x0248)
   #define LCD_GMC_ULTRA_TH_REG        (LCD_base + 0x024C)

   /*------------------------------------------------------------------*/

   #define REG_LCD_STA                    *((volatile unsigned short *) (LCD_STA_REG))
   #define REG_LCD_INT_ENABLE             *((volatile unsigned short *) (LCD_INT_ENABLE_REG))
   #define REG_LCD_INT_STATUS             *((volatile unsigned short *) (LCD_INT_STATUS_REG))
   #define REG_LCD_START                  *((volatile unsigned short *) (LCD_START_REG))
   #define REG_LCD_RSTB                   *((volatile unsigned short *) (LCD_RSTB_REG))

   #define REG_LCD_PARALLEL0_CONFIG       *((volatile unsigned int *)   (LCD_PARALLEL0_CONFIG_REG))
   #define REG_LCD_PARALLEL1_CONFIG       *((volatile unsigned int *)   (LCD_PARALLEL1_CONFIG_REG))
   #define REG_LCD_PARALLEL2_CONFIG       *((volatile unsigned int *)   (LCD_PARALLEL2_CONFIG_REG))
   #define REG_LCD_PARALLEL_PDW           *((volatile unsigned int *)   (LCD_PARALLEL_PDW_REG))

   #define REG_LCD_CALC_HTT               *((volatile unsigned int *)   (LCD_CALC_HTT_REG))
   #define REG_LCD_SYNC_LCM_SIZE          *((volatile unsigned int *)   (LCD_SYNC_LCM_SIZE_REG))
   #define REG_LCD_SYNC_CNT               *((volatile unsigned int *)   (LCD_SYNC_CNT_REG))
   #define REG_LCD_SYNC_COUNT               *((volatile unsigned int *) (LCD_SYNC_CNT_REG))	
   #define REG_LCD_SIF0_TIMING_REG         *((volatile unsigned int *)   (LCD_SIF0_TIMING_REG))
   #define REG_LCD_SIF1_TIMING_REG         *((volatile unsigned int *)   (LCD_SIF1_TIMING_REG))
   #define REG_LCD_SIF_CON_REG             *((volatile unsigned int *)   (LCD_SIF_CON_REG))
   #define REG_LCD_SIF_PIX_CON_REG			*((volatile unsigned short *) LCD_SIF_PIX_CON_REG)
   #define REG_LCD_SIF_CS_REG              *((volatile unsigned int *)   (LCD_SIF_CS_REG))
   #define REG_LCD_SIF_PAD_SEL_REG         *((volatile unsigned int *)   (LCD_SIF_PAD_SEL_REG))
   #define REG_LCD_SIF_STR_BYTE_CON_REG         *((volatile unsigned int *)   (LCD_SIF_STR_BYTE_CON_REG))
   #define REG_LCD_SIF_WR_STR_BYTE_REG         *((volatile unsigned int *)   (LCD_SIF_WR_STR_BYTE_REG))
   #define REG_LCD_SIF_RD_STR_BYTE_REG         *((volatile unsigned int *)   (LCD_SIF_RD_STR_BYTE_REG))

   #define REG_LCD_TECON                  *((volatile unsigned int *)   (LCD_TECON_REG))
   #define REG_LCD_GMCCON                 *((volatile unsigned int *)   (LCD_GMCCON_REG))

   #define REG_LCD_PARALLEL_CTRL0         *((volatile unsigned int *)   (LCD_PARALLEL_CTRL0_REG))
   #define REG_LCD_PARALLEL_DATA0         *((volatile unsigned int *)   (LCD_PARALLEL_DATA0_REG))
   #define REG_LCD_PARALLEL_CTRL1         *((volatile unsigned int *)   (LCD_PARALLEL_CTRL1_REG))
   #define REG_LCD_PARALLEL_DATA1         *((volatile unsigned int *)   (LCD_PARALLEL_DATA1_REG))
   #define REG_LCD_PARALLEL_CTRL2         *((volatile unsigned int *)   (LCD_PARALLEL_CTRL2_REG))
   #define REG_LCD_PARALLEL_DATA2         *((volatile unsigned int *)   (LCD_PARALLEL_DATA2_REG))

   #define REG_LCD_SERIAL_CTRL0           *((volatile unsigned int *) (LCD_SERIAL_CTRL0_REG))
   #define REG_LCD_SERIAL_DATA0           *((volatile unsigned int *) (LCD_SERIAL_DATA0_REG))
   #define REG_LCD_SERIAL_CTRL1           *((volatile unsigned int *) (LCD_SERIAL_CTRL1_REG))
   #define REG_LCD_SERIAL_DATA1           *((volatile unsigned int *) (LCD_SERIAL_DATA1_REG))

   #define REG_LCD_SERIAL_SPE_CTRL0           *((volatile unsigned int *) (LCD_SERIAL_SPE_CTRL0_REG))
   #define REG_LCD_SERIAL_SPE_DATA0           *((volatile unsigned int *) (LCD_SERIAL_SPE_DATA0_REG))
   #define REG_LCD_SERIAL_SPE_CTRL1           *((volatile unsigned int *) (LCD_SERIAL_SPE_CTRL1_REG))
   #define REG_LCD_SERIAL_SPE_DATA1           *((volatile unsigned int *) (LCD_SERIAL_SPE_DATA1_REG))

   #define REG_LCD_SCMD0                  REG_LCD_SERIAL_CTRL0
   #define REG_LCD_SDAT0                  REG_LCD_SERIAL_DATA0
   #define REG_LCD_SCMD1                  REG_LCD_SERIAL_CTRL1
   #define REG_LCD_SDAT1                  REG_LCD_SERIAL_DATA1

   #define REG_LCD_SPE_SCMD0                  REG_LCD_SERIAL_SPE_CTRL0
   #define REG_LCD_SPE_SDAT0                  REG_LCD_SERIAL_SPE_DATA0
   #define REG_LCD_SPE_SCMD1                  REG_LCD_SERIAL_SPE_CTRL1
   #define REG_LCD_SPE_SDAT1                  REG_LCD_SERIAL_SPE_DATA1

   #define REG_LCD_ROI_CTRL               *((volatile unsigned int *)   (LCD_ROI_CTRL_REG))
   #define REG_LCD_ROI_OFFSET             *((volatile unsigned int *)   (LCD_ROI_OFFSET_REG))
   #define REG_LCD_ROI_CMD_ADDR           *((volatile unsigned short *) (LCD_ROI_CMD_ADDR_REG))
   #define REG_LCD_ROI_DATA_ADDR          *((volatile unsigned short *) (LCD_ROI_DATA_ADDR_REG))
   #define REG_LCD_ROI_SIZE               *((volatile unsigned int *)   (LCD_ROI_SIZE_REG))
   #define REG_LCD_ROI_BACKGROUND_COLOR   *((volatile unsigned int *)   (LCD_ROI_BG_COLOR_REG))

   #define REG_LCD_LAYER0_CTRL            *((volatile unsigned int *)   (LCD_LAYER0_CTRL_REG))
   #define REG_LCD_LAYER0_SRC_KEY         *((volatile unsigned int *)   (LCD_LAYER0_SRC_KEY_REG))
   #define REG_LCD_LAYER0_OFFSET          *((volatile unsigned int *)   (LCD_LAYER0_OFFSET_REG))
   #define REG_LCD_LAYER0_BUFF_ADDR       *((volatile unsigned int *)   (LCD_LAYER0_BUFF_ADDR_REG))
   #define REG_LCD_LAYER0_SIZE            *((volatile unsigned int *)   (LCD_LAYER0_SIZE_REG))
   #define REG_LCD_LAYER0_MEM_OFFSET      *((volatile unsigned int *)   (LCD_LAYER0_MEM_OFFSET_REG))
   #define REG_LCD_LAYER0_MEM_PITCH       *((volatile unsigned short *) (LCD_LAYER0_MEM_PITCH_REG))
  
   #define REG_LCD_LAYER1_CTRL            *((volatile unsigned int *)   (LCD_LAYER1_CTRL_REG))
   #define REG_LCD_LAYER1_SRC_KEY         *((volatile unsigned int *)   (LCD_LAYER1_SRC_KEY_REG))
   #define REG_LCD_LAYER1_OFFSET          *((volatile unsigned int *)   (LCD_LAYER1_OFFSET_REG))
   #define REG_LCD_LAYER1_BUFF_ADDR       *((volatile unsigned int *)   (LCD_LAYER1_BUFF_ADDR_REG))
   #define REG_LCD_LAYER1_SIZE            *((volatile unsigned int *)   (LCD_LAYER1_SIZE_REG))
   #define REG_LCD_LAYER1_MEM_OFFSET      *((volatile unsigned int *)   (LCD_LAYER1_MEM_OFFSET_REG))
   #define REG_LCD_LAYER1_MEM_PITCH       *((volatile unsigned short *) (LCD_LAYER1_MEM_PITCH_REG))
   
   #define REG_LCD_LAYER2_CTRL            *((volatile unsigned int *)   (LCD_LAYER2_CTRL_REG))
   #define REG_LCD_LAYER2_SRC_KEY         *((volatile unsigned int *)   (LCD_LAYER2_SRC_KEY_REG))
   #define REG_LCD_LAYER2_OFFSET          *((volatile unsigned int *)   (LCD_LAYER2_OFFSET_REG))
   #define REG_LCD_LAYER2_BUFF_ADDR       *((volatile unsigned int *)   (LCD_LAYER2_BUFF_ADDR_REG))
   #define REG_LCD_LAYER2_SIZE            *((volatile unsigned int *)   (LCD_LAYER2_SIZE_REG))
   #define REG_LCD_LAYER2_MEM_OFFSET      *((volatile unsigned int *)   (LCD_LAYER2_MEM_OFFSET_REG))
   #define REG_LCD_LAYER2_MEM_PITCH       *((volatile unsigned short *) (LCD_LAYER2_MEM_PITCH_REG))

   #define REG_LCD_LAYER3_CTRL            *((volatile unsigned int *)   (LCD_LAYER3_CTRL_REG))
   #define REG_LCD_LAYER3_SRC_KEY         *((volatile unsigned int *)   (LCD_LAYER3_SRC_KEY_REG))
   #define REG_LCD_LAYER3_OFFSET          *((volatile unsigned int *)   (LCD_LAYER3_OFFSET_REG))
   #define REG_LCD_LAYER3_BUFF_ADDR       *((volatile unsigned int *)   (LCD_LAYER3_BUFF_ADDR_REG))
   #define REG_LCD_LAYER3_SIZE            *((volatile unsigned int *)   (LCD_LAYER3_SIZE_REG))
   #define REG_LCD_LAYER3_MEM_OFFSET      *((volatile unsigned int *)   (LCD_LAYER3_MEM_OFFSET_REG))
   #define REG_LCD_LAYER3_MEM_PITCH       *((volatile unsigned short *) (LCD_LAYER3_MEM_PITCH_REG))


   #define REG_LCD_DITHER_CON             *((volatile unsigned int *)   (LCD_DITHER_CON_REG))

   #define REG_LCD_COUNTER_CON            *((volatile unsigned int *)   (LCD_FRAME_COUNT_CON_REG))
   #define REG_LCD_COUNTER                *((volatile unsigned int *)   (LCD_FRAME_COUNT_REG))

   #define REG_LCD_ULTRA_CON              *((volatile unsigned int *)   (LCD_ULTRA_CON_REG))
   #define REG_LCD_CONSUME_RATE           *((volatile unsigned int *)   (LCD_CONSUME_RATE_REG))
   #define REG_LCD_DBI_ULTRA_TH           *((volatile unsigned int *)   (LCD_DBI_ULTRA_TH_REG))
   #define REG_LCD_GMC_ULTRA_TH           *((volatile unsigned int *)   (LCD_GMC_ULTRA_TH_REG))

///******************************************************///
///******** Defition of Cmmand format *******************///
   #define LCD_CMD                             0x00800000
   #define LCD_DATA                            0x00000000

///******************************************************///

///******** Defition of Status register *****************///
   #define LCD_STATUS_RUN_BIT                  0x0001
   #define LCD_STATUS_WAIT_CMDQ_BIT            0x0002
   #define LCD_STATUS_WAIT_HTT_BIT             0x0008
   #define LCD_STATUS_TE_PEND_BIT              0x0010
   #define LCD_STATUS_BUSY_BIT                 0x0020
   #define LCD_STATUS_GMC_REQUEST_BIT          0x0040
///******************************************************///
///******** Defition of Interrupt register **************///
   #define LCD_INT_ENABLE_COMPLETE_BIT         0x0001
   #define LCD_INT_ENABLE_REG_COMPLETE_BIT     0x0002
   #define LCD_INT_ENABLE_CMD_COMPLETE_BIT     0x0004
   #define LCD_INT_ENABLE_HTT_COMPLETE_BIT     0x0010
   #define LCD_INT_ENABLE_SYNC_COMPLETE_BIT    0x0020
   #define LCD_INT_ENABLE_VSYNC_COMPLETE_BIT   0x0020

///******************************************************///
///******** Defition of Interrupt status register *******///
   #define LCD_INT_STATUS_COMPLETE_BIT         0x0001


///******************************************************///
///******** Defition of Start register ******************///
   #define LCD_START_BIT                       0x8000
   #define LCD_IF_RESET_BIT                    0x0001

   /// bit mapping of LCD transfer start register
   #define LCD_START_START_BIT                 LCD_START_BIT

   /// bit mapping of LCD parallel or serial interface control register
   #define LCD_CTRL_RESET_BIT                  LCD_IF_RESET_BIT

///******************************************************///
///******** Defition of LCD PIF register ****************///

   typedef enum
   {
    LCD_PARALLEL_BUS_WIDTH_8BIT = 0,
    LCD_PARALLEL_BUS_WIDTH_9BIT = 1,
    LCD_PARALLEL_BUS_WIDTH_16BIT = 2,
    LCD_PARALLEL_BUS_WIDTH_18BIT = 3
   }LCD_PARALLEL_BUS_WIDTH_ENUM;

   #define LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_MASK    0x3F
   #define LCD_PARALLEL_CONFIG_WRITE_SETUP_TIME_MASK    0xF00

   #define LCD_PARALLEL_CONFIG_WRITE_HOLD_TIME_MASK     0xF000

   #define LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_MASK   0x3F0000
   #define LCD_PARALLEL_CONFIG_READ_SETUP_TIME_MASK     0xF000000
   #define LCD_PARALLEL_CONFIG_READ_HOLD_TIME_MASK      0xF0000000

   #define LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_OFFSET  0
   #define LCD_PARALLEL_CONFIG_WRITE_SETUP_TIME_OFFSET  8
   #define LCD_PARALLEL_CONFIG_WRITE_HOLD_TIME_OFFSET   12
   #define LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_OFFSET 16
   #define LCD_PARALLEL_CONFIG_READ_SETUP_TIME_OFFSET   24
   #define LCD_PARALLEL_CONFIG_READ_HOLD_TIME_OFFSET    28
   
   #define LCD_PARALLEL_IF_BUS_WIDTH_MASK(if_num)       0x7 << (if_num * 4)
   #define LCD_PARALLEL_IF_BUS_WIDTH_OFFSET(if_num)     (if_num * 4)

   #define LCD_PARALLEL_IF_CHW_MASK(if_num)       0xF << ((if_num * 4) + 16)
   #define LCD_PARALLEL_IF_CHW_OFFSET(if_num)     ((if_num * 4) + 16)
///******************************************************///
///******** Defition of LCD TECON register **************///
   #define LCD_TE_ENABLE_BIT                    0x1
   #define LCD_TE_SYNCEDGE_BIT                  0x2
   #define LCD_TE_SW_TE_BIT                     0x8000

///******************************************************///
   typedef enum
   {
    LCD_PARALLEL_CLOCK_104MHZ = 0,
    LCD_PARALLEL_CLOCK_26MHZ = 0x4000,
    LCD_PARALLEL_CLOCK_52MHZ = 0x8000,
    LCD_PARALLEL_CLOCK_RSVD = 0xC000
   }LCD_PARALLEL_IF_CLOCK_ENUM;
   
///******** Defition of LCD GMC register ****************///
   typedef enum
   {
     LCD_GMCCON_BURST_4_BYTE = 0,
     LCD_GMCCON_BURST_16_BYTE = 2,
     LCD_GMCCON_BURST_32_BYTE = 3,
     LCD_GMCCON_BURST_64_BYTE = 4    ///for other values, are burst 16 bytes
   } LCD_GMCCON_BURST_TYPE;
   #define LCD_GMC_THROTTLE_CTRL_ENABLE_BIT    0x10
   #define LCD_GMC_THROTTLE_BURST_MASK         0x7
   #define LCD_GMC_THROTTLE_PERIOD_MASK        0xFFFF0000

///******************************************************///
///******** Defition of WMEN register *******************///
   typedef enum
   {
     LCD_WMEM_COLOR_RGB565 = 0,
     LCD_WMEM_COLOR_RGB888 = 2,
     LCD_WMEM_COLOR_ARGB8888 = 4,
     LCD_WMEM_COLOR_ARGB8888_WITH_PIXEL_ALPHA = 6,
     LCD_WMEM_COLOR_PARGB6666 = 8,
     LCD_WMEM_COLOR_PARGB6666_WITH_PIXEL_ALPHA = 0xA,
     LCD_WMEM_COLOR_RSVD
   }LCD_WMEM_COLOR_FORMAT_ENUM;


   #define LCD_ROI_WMEM_CTRL_FORMAT            0x000E
   #define LCD_ROI_WMEM_CTRL_FORMAT_OFFSET     0x0001
   #define LCD_ROI_WMEM_ALPHA_MASK             0xFF00
   #define LCD_ROI_WMEM_ALPHA_OFFSET           0x0008
   #define LCD_ROI_WMEM_ADDRINC_DISABLE_BIT    0x0010
   #define LCD_ROI_WMEM_CTRL_TO_LCM            0x0001
   #define LCD_ROI_WMEM_CTRL_TO_LCM_OFFSET     0x0000

   #define LCD_ROI_WMEM_OFFSETX_OFFSET         0
   #define LCD_ROI_WMEM_OFFSETY_OFFSET         16

///******************************************************///
///******** Defition of ROI register ********************///
   #define LCD_LAYER_ENABLE_BIT(n) (1 << (31 - n))
   #define LCD_ROI_CTRL_SEND_RES_MOD_BIT       0x01000000
   #define LCD_ROI_CTRL_PERIOD_MASK            0x00FF0000
   #define LCD_ROI_CTRL_LAYER_MASK             0xF0000000
   #define LCD_ROI_CTRL_CMD_ENABLE_BIT         0x00008000
   #define LCD_ROI_CTRL_DATA_FORMAT_MASK       0x020000FF   ///24 bit interface support
   
   #define LCD_ROI_CTRL_CMDQ_SEL_BIT          0  					
   #define LCD_ROI_CTRL_CMD_NUMBER_MASK        0x00003F00

   #define LCD_WINDOW_OFFSET_Y_OFFSET_MASK     0x07FF0000
   #define LCD_WINDOW_OFFSET_X_OFFSET_MASK     0x000007FF
   #define LCD_WINDOW_SIZE_ROW_MASK            0x07FF0000
   #define LCD_WINDOW_SIZE_COLUMN_MASK         0x000007FF
   
   #define LCD_ROI_CTRL_PERIOD_OFFSET          16 
   #define LCD_ROI_CTRL_W2MEM_OFFSET           14
   #define LCD_ROI_CTRL_COLOR_OFFSET           26

///******************************************************///
///******** Defition of HWREF register ******************///
   #define LCD_HWREF_LAYER_MASK                 LCD_ROI_CTRL_LAYER_MASK
   #define LCD_HW_TRIGGER_HWREF_SEL_MASK        0x00030000
   #define LCD_HW_TRIGGER_HWREF_ENABLE_BIT      0x80
   #define LCD_HW_TRIGGER_HWREF_SWREF_BIT       0x1
   #define LCD_HW_TRIGGER_HWREF_SWREF_MODE_BIT  0x4
   #define LCD_HW_TRIGGER_HWREF_HWREF_MODE_BIT  0x2

   ///TODO: need to confirm the MDP change
/* resolve build error redefined in lcd_if.h  
   typedef enum
   {
    LCD_HWREF_SEL_ROT_DMA0 = 0,     //LCD_HWREF_SEL_VDO_ROT
    LCD_HWREF_SEL_ROT_DMA1 = 1,     //LCD_HWREF_SEL_RGB_ROT0
    LCD_HWREF_SEL_ROT_DMA2 = 2,     //LCD_HWREF_SEL_RGB_ROT1
    LCD_HWREF_SEL_RSVD = 3
   }LCD_HW_TRIGGER_SRC_ENUM;
*/
///******************************************************///
///******** Defition of Layer register ******************///
   #define LCD_CMD_QUEUE_LENGTH                 64

   #define LCD_TOTAL_LAYER                      4
   #define LCD_LAYER_ADDR_OFFSET                0x30

   #define LCD_LAYER_CTRL_OPACITY_ENABLE_BIT    0x00000100   
   //#define LCD_LAYER_CTRL_SOURCE_AUTO_INC_BIT 0x00008000
   #define LCD_LAYER_CTRL_DATA_SWAP_BIT         0x00010000
   #define LCD_LAYER_CTRL_DITHER_ENABLE_BIT     0x00040000
   //#define LCD_LAYER_CTRL_LGAMMA_ENABLE_BIT     0x00080000
   #define LCD_LAYER_CTRL_SOURCE_KEY_ENABLE_BIT 0x00004000
   #define LCD_LAYER_CTRL_DST_KEY_ENABLE_BIT    0x01000000

   #define LCD_LAYER_ALPHA_VAL_OFFSET           0
   #define LCD_MAX_OPACITY                      0xFF   
   #define LCD_LAYER_OPACITY_VAL_OFFSET         0
   #define LCD_LAYER_CTRL_ROTATE_OFFSET         11
   #define LCD_LAYER_CTRL_FORMAT_OFFSET         20
   #define LCD_LAYER_CTRL_OPACITY_VALUE_MASK    0xFF
   #define LCD_LAYER_CTRL_ROTATE_MASK           0x00003800
   #define LCD_LAYER_CTRL_COLOR_FORMAT_MASK     0x00F00000
   #define LCD_LAYER_MASK                       0xF0000000
   
   typedef enum
   {
     LCD_LAYER_COLOR_8BPP_INDEX = 0,   
     LCD_LAYER_COLOR_RGB565,
     LCD_LAYER_COLOR_UYVY422,
     LCD_LAYER_COLOR_RGB888,
     LCD_LAYER_COLOR_ARGB8888,
     LCD_LAYER_COLOR_PARGB8888,
     LCD_LAYER_COLOR_XRGB,
     LCD_LAYER_COLOR_ARGB6666,
     LCD_LAYER_COLOR_PARGB6666,
     LCD_LAYER_MONO
   } LCD_LAYER_SOURCE_COLOR_FORMAT_ENUM;


///******************************************************///
///******** Macro of LCD STATUS**************************///
   #define LCD_BUSY            (REG_LCD_STA & LCD_STATUS_BUSY_BIT)
   #define LCD_IS_RUNNING      (REG_LCD_STA & LCD_STATUS_RUN_BIT)
   #define LCD_WAIT_TE         (REG_LCD_STA & LCD_STATUS_TE_PEND_BIT)

///******************************************************///
///******** Macro of LCD INT ****************************///

   #define ENABLE_LCD_TRANSFER_COMPLETE_INT   REG_LCD_INT_ENABLE |= LCD_INT_ENABLE_COMPLETE_BIT;
   #define DISABLE_LCD_TRANSFER_COMPLETE_INT  REG_LCD_INT_ENABLE &= ~LCD_INT_ENABLE_COMPLETE_BIT;
   #define ENABLE_LCD_REG_COMPLETE_INT        REG_LCD_INT_ENABLE |= LCD_INT_ENABLE_REG_COMPLETE_BIT;
   #define DISABLE_LCD_REG_COMPLETE_INT       REG_LCD_INT_ENABLE &= ~LCD_INT_ENABLE_REG_COMPLETE_BIT;
   #define ENABLE_LCD_CMD_COMPLETE_INT        REG_LCD_INT_ENABLE |= LCD_INT_ENABLE_CMD_COMPLETE_BIT;
   #define DISABLE_LCD_CMD_COMPLETE_INT       REG_LCD_INT_ENABLE &= ~LCD_INT_ENABLE_CMD_COMPLETE_BIT;
   #define ENABLE_LCD_VSYNC_COMPLETE_INT      REG_LCD_INT_ENABLE |= LCD_INT_ENABLE_VSYNC_COMPLETE_BIT;
   #define DISABLE_LCD_VSYNC_COMPLETE_INT     REG_LCD_INT_ENABLE &= ~LCD_INT_ENABLE_VSYNC_COMPLETE_BIT;

   #define ENABLE_LCD_HTT_COMPLETE_INT        REG_LCD_INT_ENABLE |= LCD_INT_ENABLE_HTT_COMPLETE_BIT;
   #define DISABLE_LCD_HTT_COMPLETE_INT       REG_LCD_INT_ENABLE &= ~LCD_INT_ENABLE_HTT_COMPLETE_BIT;

   #define ENABLE_LCD_SYNC_COMPLETE_INT       REG_LCD_INT_ENABLE |= LCD_INT_ENABLE_SYNC_COMPLETE_BIT;
   #define DISABLE_LCD_SYNC_COMPLETE_INT      REG_LCD_INT_ENABLE &= ~LCD_INT_ENABLE_SYNC_COMPLETE_BIT;

   #define LCD_CLEAR_INT_STATUS()      \
   {                                   \
     kal_uint32 i = REG_LCD_INT_STATUS;\
   }

///******************************************************///
///******** Macro of LCD START***************************///
   #define SET_LCD_CTRL_RESET_PIN       REG_LCD_RSTB= LCD_IF_RESET_BIT;
   #define CLEAR_LCD_CTRL_RESET_PIN     REG_LCD_RSTB = 0;
   #define STOP_LCD_TRANSFER            REG_LCD_START = 0;

   #define START_LCD_TRANSFER           REG_LCD_START = 0;\
                                        REG_LCD_START = LCD_START_BIT;

   #define LCD_CMD_IS_PENDING           (REG_LCD_STA & LCD_INT_ENABLE_CMD_COMPLETE_BIT)

///******************************************************///
///******** Macro of LCD TECON***************************///
   #define ENABLE_LCD_TE_DETECT()       REG_LCD_TECON |= LCD_TE_ENABLE_BIT;
   #define DISABLE_LCD_TE_DETECT()      REG_LCD_TECON &= ~LCD_TE_ENABLE_BIT;
   #define SET_TE_RISING_DETECT()       REG_LCD_TECON &= ~LCD_TE_SYNCEDGE_BIT;
   #define SET_TE_FALLING_DETECT()      REG_LCD_TECON |= LCD_TE_SYNCEDGE_BIT;

   #define LCD_SET_SW_TE                REG_LCD_TECON |= LCD_TE_SW_TE_BIT;
   
///******************************************************///
///******** Macro of LCD SIF*****************************///
   ///******** Defition of SIF register ********************///
   typedef enum
   {
     LCD_SCNF_IF_WIDTH_8 = 0,
     LCD_SCNF_IF_WIDTH_9,
     LCD_SCNF_IF_WIDTH_16,
     LCD_SCNF_IF_WIDTH_18,
     LCD_SCNF_IF_WIDTH_24,
     LCD_SCNF_IF_WIDTH_32
   }LCD_SCNF_IF_WIDTH_ENUM;

      typedef enum
   {
     LCD_SCNF_IF_2PIN_WIDTH_16 = 2,
     LCD_SCNF_IF_2PIN_WIDTH_18 =3,
     LCD_SCNF_IF_2PIN_WIDTH_24 =4,
     LCD_SCNF_IF_2PIN_WIDTH_12 =6    
   }LCD_SCNF_IF_2PIN_WIDTH_ENUM;

      typedef enum
   {
     LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_8 = 0,
     LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_9,
	 LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_16,     
	 LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_18,
	 LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_24,
	 LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_32
   }LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_ENUM;

#if defined(MT6261) || defined(MT2502)
// 6261/2502	0: 520/4 = 132MHz
//			1: 520/5 = 104MHz
//			2: 520/6 = 91MHz
//			3: 520/7 = 78MHz
//			4: 520/8 = 65MHz
//			5: 26MHz
typedef enum
{
	LCD_SERIAL_CLOCK_132MHZ = 0,
	LCD_SERIAL_CLOCK_104MHZ = 1,
	LCD_SERIAL_CLOCK_91MHZ = 2,
	LCD_SERIAL_CLOCK_78MHZ = 3,
	LCD_SERIAL_CLOCK_65MHZ = 4,
	LCD_SERIAL_CLOCK_26MHZ = 5,
	LCD_SERIAL_CLOCK_RSVD = 6
}LCD_SERIAL_IF_CLOCK_ENUM;
#elif defined(MT2501)
// 2501 	0: 624/4 = 156MHz
//		1: 624/5 = 132MHz
//		2: 624/6 = 104MHz
//		3: 624/7 = 91MHz
//		4: 624/8 = 78MHz
//		5: 26MHz
//		6: RSVD
typedef enum
{
	LCD_SERIAL_CLOCK_156MHZ = 0,
	LCD_SERIAL_CLOCK_132MHZ = 1,
	LCD_SERIAL_CLOCK_104MHZ = 2,
	LCD_SERIAL_CLOCK_91MHZ = 3,
	LCD_SERIAL_CLOCK_78sMHZ = 4,
	LCD_SERIAL_CLOCK_26MHZ = 5,
	LCD_SERIAL_CLOCK_RSVD = 6
}LCD_SERIAL_IF_CLOCK_ENUM;
#else
   typedef enum
   {
    LCD_SERIAL_CLOCK_132MHZ = 0,
    LCD_SERIAL_CLOCK_104MHZ = 1,
    LCD_SERIAL_CLOCK_91MHZ = 2,
    LCD_SERIAL_CLOCK_26MHZ = 3,
    LCD_SERIAL_CLOCK_RSVD = 4
   }LCD_SERIAL_IF_CLOCK_ENUM;
#endif

   #define LCD_SERIAL_CONFIG_SIF0_SIZE_MASK             0x0007
   #define LCD_SERIAL_CONFIG_SIF0_SIZE_OFFSET           0
   #define LCD_SERIAL_CONFIG_SIF0_3WIRE_BIT             0x0008
   #define LCD_SERIAL_CONFIG_SIF0_SDI_ENABLE_BIT        0x0010
   #define LCD_SERIAL_CONFIG_SIF0_LSCK_PHASE_BIT        0x0020
   #define LCD_SERIAL_CONFIG_SIF0_LSCK_DEF_LEVEL_BIT    0x0040
   #define LCD_SERIAL_CONFIG_SIF0_CLK_DIV2_BIT          0x0080
   
   #define LCD_SERIAL_CONFIG_SIF1_SIZE_MASK             0x0700
   #define LCD_SERIAL_CONFIG_SIF1_SIZE_OFFSET           8
   #define LCD_SERIAL_CONFIG_SIF1_3WIRE_BIT             0x0800
   #define LCD_SERIAL_CONFIG_SIF1_SDI_ENABLE_BIT        0x1000
   #define LCD_SERIAL_CONFIG_SIF1_LSCK_PHASE_BIT        0x2000
   #define LCD_SERIAL_CONFIG_SIF1_LSCK_DEF_LEVEL_BIT    0x4000
   #define LCD_SERIAL_CONFIG_SIF1_CLK_DIV2_BIT          0x8000

   #define LCD_SERIAL_PIX_CONFIG_SIF0_2PIN_SIZE_MASK	0x0007
   #define LCD_SERIAL_PIX_CONFIG_SIF0_2PIN_SIZE_OFFSET	0
   #define LCD_SERIAL_PIX_CONFIG_SIF0_PIX_2PIN_BIT	 	0x0010
   #define LCD_SERIAL_PIX_CONFIG_SIF0_SINGLE_A0_BIT		0x0040
   #define LCD_SERIAL_PIX_CONFIG_SIF0_CS_STAY_LOW_BIT	0x0080

   #define LCD_SERIAL_PIX_CONFIG_SIF1_2PIN_SIZE_MASK	0x0700
   #define LCD_SERIAL_PIX_CONFIG_SIF1_2PIN_SIZE_OFFSET	8
   #define LCD_SERIAL_PIX_CONFIG_SIF1_PIX_2PIN_BIT	 	0x1000
   #define LCD_SERIAL_PIX_CONFIG_SIF1_SINGLE_A0_BIT		0x4000
   #define LCD_SERIAL_PIX_CONFIG_SIF1_CS_STAY_LOW_BIT	0x8000

   #define LCD_SERIAL_STR_BYTE_CONFIG_SIF0_PIX_SIZE_MASK	 0x0007
   #define LCD_SERIAL_STR_BYTE_CONFIG_SIF0_PIX_SIZE_OFFSET   0
   #define LCD_SERIAL_STR_BYTE_CONFIG_SIF0_STR_BYTE_MODE_BIT    0x0080

   #define LCD_SERIAL_STR_BYTE_CONFIG_SIF1_PIX_SIZE_MASK	 0x0700
   #define LCD_SERIAL_STR_BYTE_CONFIG_SIF1_PIX_SIZE_OFFSET   7
   #define LCD_SERIAL_STR_BYTE_CONFIG_SIF1_STR_BYTE_MODE_BIT    0x8000


   
   #define LCD_SERIAL_CONFIG_SIF_HW_CS_CTRL_BIT         0x01000000
   
   #define LCD_SERIAL_TIMING_CONFIG_WR_2ND_OFFSET       0
   #define LCD_SERIAL_TIMING_CONFIG_WR_2ND_MASK         0x00000F
   #define LCD_SERIAL_TIMING_CONFIG_WR_1ST_OFFSET       4
   #define LCD_SERIAL_TIMING_CONFIG_WR_1ST_MASK         0x0000F0
   #define LCD_SERIAL_TIMING_CONFIG_RD_2ND_OFFSET       8
   #define LCD_SERIAL_TIMING_CONFIG_RD_2ND_MASK         0x000F00
   #define LCD_SERIAL_TIMING_CONFIG_RD_1ST_OFFSET       12
   #define LCD_SERIAL_TIMING_CONFIG_RD_1ST_MASK         0x00F000
   #define LCD_SERIAL_TIMING_CONFIG_CSH_OFFSET          16
   #define LCD_SERIAL_TIMING_CONFIG_CSH_MASK            0x0F0000
   #define LCD_SERIAL_TIMING_CONFIG_CSS_OFFSET          20
   #define LCD_SERIAL_TIMING_CONFIG_CSS_MASK            0xF00000
   
   #define LCD_SERIAL_CONFIG_CS0_LEVEL_BIT              0x01
   #define LCD_SERIAL_CONFIG_CS1_LEVEL_BIT              0x02

  //E2
   ///Timing setting
   #define SET_LCD_SERIAL_IF_CSS(ifnum, n)       (*(volatile unsigned int *)(LCD_SIF0_TIMING_REG + 4 * (ifnum))) &= ~LCD_SERIAL_TIMING_CONFIG_CSS_MASK;\
                                                 (*(volatile unsigned int *)(LCD_SIF0_TIMING_REG + 4 * (ifnum))) |= ((n & 0xF) << LCD_SERIAL_TIMING_CONFIG_CSS_OFFSET)
   #define SET_LCD_SERIAL_IF_CSH(ifnum, n)      (*(volatile unsigned int *)(LCD_SIF0_TIMING_REG + 4 * (ifnum)))  &= ~LCD_SERIAL_TIMING_CONFIG_CSH_MASK;\
                                                 (*(volatile unsigned int *)(LCD_SIF0_TIMING_REG + 4 * (ifnum))) |= ((n & 0xF) << LCD_SERIAL_TIMING_CONFIG_CSH_OFFSET)
   #define SET_LCD_SERIAL_IF_RD_1ST(ifnum, n)   (*(volatile unsigned int *)(LCD_SIF0_TIMING_REG + 4 * (ifnum)))  &= ~LCD_SERIAL_TIMING_CONFIG_RD_1ST_MASK;\
                                                 (*(volatile unsigned int *)(LCD_SIF0_TIMING_REG + 4 * (ifnum)))  |= ((n & 0xF) << LCD_SERIAL_TIMING_CONFIG_RD_1ST_OFFSET)
   #define SET_LCD_SERIAL_IF_RD_2ND(ifnum, n)   (*(volatile unsigned int *)(LCD_SIF0_TIMING_REG + 4 * (ifnum)))  &= ~LCD_SERIAL_TIMING_CONFIG_RD_2ND_MASK;\
                                                 (*(volatile unsigned int *)(LCD_SIF0_TIMING_REG + 4 * (ifnum)))  |= ((n & 0xF) << LCD_SERIAL_TIMING_CONFIG_RD_2ND_OFFSET)
   #define SET_LCD_SERIAL_IF_WR_1ST(ifnum, n)   (*(volatile unsigned int *)(LCD_SIF0_TIMING_REG + 4 * (ifnum)))  &= ~LCD_SERIAL_TIMING_CONFIG_WR_1ST_MASK;\
                                                 (*(volatile unsigned int *)(LCD_SIF0_TIMING_REG + 4 * (ifnum)))  |= ((n & 0xF) << LCD_SERIAL_TIMING_CONFIG_WR_1ST_OFFSET)
   #define SET_LCD_SERIAL_IF_WR_2ND(ifnum, n)   (*(volatile unsigned int *)(LCD_SIF0_TIMING_REG + 4 * (ifnum)))  &= ~LCD_SERIAL_TIMING_CONFIG_WR_2ND_MASK;\
                                                 (*(volatile unsigned int *)(LCD_SIF0_TIMING_REG + 4 * (ifnum)))  |= ((n & 0xF) << LCD_SERIAL_TIMING_CONFIG_WR_2ND_OFFSET)

   /// Serial Control Setting
   #define ENABLE_LCD_SERIAL0_SDI            REG_LCD_SIF_CON_REG |= LCD_SERIAL_CONFIG_SIF0_SDI_ENABLE_BIT
   #define DISABLE_LCD_SERIAL0_SDI           REG_LCD_SIF_CON_REG &= ~(LCD_SERIAL_CONFIG_SIF0_SDI_ENABLE_BIT)
   #define ENABLE_LCD_SERIAL1_SDI            REG_LCD_SIF_CON_REG |= LCD_SERIAL_CONFIG_SIF1_SDI_ENABLE_BIT
   #define DISABLE_LCD_SERIAL1_SDI           REG_LCD_SIF_CON_REG &= ~(LCD_SERIAL_CONFIG_SIF1_SDI_ENABLE_BIT)
   
   #define ENABLE_LCD_SERIAL0_3WIRE          REG_LCD_SIF_CON_REG |= LCD_SERIAL_CONFIG_SIF0_3WIRE_BIT
   #define DISABLE_LCD_SERIAL0_3WIRE         REG_LCD_SIF_CON_REG &= ~(LCD_SERIAL_CONFIG_SIF0_3WIRE_BIT)
   #define ENABLE_LCD_SERIAL1_3WIRE          REG_LCD_SIF_CON_REG |= LCD_SERIAL_CONFIG_SIF1_3WIRE_BIT
   #define DISABLE_LCD_SERIAL1_3WIRE         REG_LCD_SIF_CON_REG &= ~(LCD_SERIAL_CONFIG_SIF1_3WIRE_BIT)

   #define ENABLE_LCD_SERIAL0_2PIN   		 REG_LCD_SIF_PIX_CON_REG |= LCD_SERIAL_PIX_CONFIG_SIF0_PIX_2PIN_BIT
   #define DISABLE_LCD_SERIAL0_2PIN   	     REG_LCD_SIF_PIX_CON_REG &= ~(LCD_SERIAL_PIX_CONFIG_SIF0_PIX_2PIN_BIT)
   #define ENABLE_LCD_SERIAL1_2PIN   		 REG_LCD_SIF_PIX_CON_REG |= LCD_SERIAL_PIX_CONFIG_SIF1_PIX_2PIN_BIT
   #define DISABLE_LCD_SERIAL1_2PIN			 REG_LCD_SIF_PIX_CON_REG &= ~(LCD_SERIAL_PIX_CONFIG_SIF1_PIX_2PIN_BIT)

   #define ENABLE_LCD_SERIAL0_SINGLE_A0 	 REG_LCD_SIF_PIX_CON_REG |= LCD_SERIAL_PIX_CONFIG_SIF0_SINGLE_A0_BIT 
   #define DISABLE_LCD_SERIAL0_SINGLE_A0   	 REG_LCD_SIF_PIX_CON_REG &= ~(LCD_SERIAL_PIX_CONFIG_SIF0_SINGLE_A0_BIT)
   #define ENABLE_LCD_SERIAL1_SINGLE_A0   	 REG_LCD_SIF_PIX_CON_REG |= LCD_SERIAL_PIX_CONFIG_SIF1_SINGLE_A0_BIT 
   #define DISABLE_LCD_SERIAL1_SINGLE_A0     REG_LCD_SIF_PIX_CON_REG &= ~(LCD_SERIAL_PIX_CONFIG_SIF1_SINGLE_A0_BIT)

   #define ENABLE_LCD_SERIAL0_CS_STAY_LOW    REG_LCD_SIF_PIX_CON_REG |= LCD_SERIAL_PIX_CONFIG_SIF0_CS_STAY_LOW_BIT 
   #define DISABLE_LCD_SERIAL0_CS_STAY_LOW   REG_LCD_SIF_PIX_CON_REG &= ~(LCD_SERIAL_PIX_CONFIG_SIF0_CS_STAY_LOW_BIT)  
   #define ENABLE_LCD_SERIAL1_CS_STAY_LOW    REG_LCD_SIF_PIX_CON_REG |= LCD_SERIAL_PIX_CONFIG_SIF1_CS_STAY_LOW_BIT 
   #define DISABLE_LCD_SERIAL1_CS_STAY_LOW   REG_LCD_SIF_PIX_CON_REG &= ~(LCD_SERIAL_PIX_CONFIG_SIF1_CS_STAY_LOW_BIT)

   #define ENABLE_LCD_SERIAL0_STR_BYTE    REG_LCD_SIF_STR_BYTE_CON_REG |= LCD_SERIAL_STR_BYTE_CONFIG_SIF0_STR_BYTE_MODE_BIT 
   #define DISABLE_LCD_SERIAL0_STR_BYTE   REG_LCD_SIF_STR_BYTE_CON_REG &= ~(LCD_SERIAL_STR_BYTE_CONFIG_SIF0_STR_BYTE_MODE_BIT)  
   #define ENABLE_LCD_SERIAL1_STR_BYTE    REG_LCD_SIF_STR_BYTE_CON_REG |= LCD_SERIAL_STR_BYTE_CONFIG_SIF1_STR_BYTE_MODE_BIT 
   #define DISABLE_LCD_SERIAL1_STR_BYTE   REG_LCD_SIF_STR_BYTE_CON_REG &= ~(LCD_SERIAL_STR_BYTE_CONFIG_SIF1_STR_BYTE_MODE_BIT)




   #define SET_LCD_SERIAL0_IF_SIZE(n)        REG_LCD_SIF_CON_REG &= ~(LCD_SERIAL_CONFIG_SIF0_SIZE_MASK);\
                                             REG_LCD_SIF_CON_REG |= ((n & LCD_SERIAL_CONFIG_SIF0_SIZE_MASK) << LCD_SERIAL_CONFIG_SIF0_SIZE_OFFSET)
   #define SET_LCD_SERIAL1_IF_SIZE(n)        REG_LCD_SIF_CON_REG &= ~(LCD_SERIAL_CONFIG_SIF1_SIZE_MASK);\
                                             REG_LCD_SIF_CON_REG |= ((n & LCD_SERIAL_CONFIG_SIF1_SIZE_MASK) << LCD_SERIAL_CONFIG_SIF1_SIZE_OFFSET)

   #define SET_LCD_SERIAL0_IF_2PIN_SIZE(n)	 REG_LCD_SIF_PIX_CON_REG &= ~(LCD_SERIAL_PIX_CONFIG_SIF0_2PIN_SIZE_MASK);\
											 REG_LCD_SIF_PIX_CON_REG |= ((n & LCD_SERIAL_PIX_CONFIG_SIF0_2PIN_SIZE_MASK) << LCD_SERIAL_PIX_CONFIG_SIF0_2PIN_SIZE_OFFSET)
   
   #define SET_LCD_SERIAL1_IF_2PIN_SIZE(n)   REG_LCD_SIF_PIX_CON_REG &= ~(LCD_SERIAL_PIX_CONFIG_SIF1_2PIN_SIZE_MASK);\
											 REG_LCD_SIF_PIX_CON_REG |= ((n & LCD_SERIAL_PIX_CONFIG_SIF1_2PIN_SIZE_MASK) << LCD_SERIAL_PIX_CONFIG_SIF1_2PIN_SIZE_OFFSET)

   #define SET_LCD_SERIAL0_IF_STR_BYTE_PIX_SIZE(n) 	REG_LCD_SIF_STR_BYTE_CON_REG &= ~(LCD_SERIAL_STR_BYTE_CONFIG_SIF0_PIX_SIZE_MASK);\
											   		REG_LCD_SIF_STR_BYTE_CON_REG |= ((n & LCD_SERIAL_STR_BYTE_CONFIG_SIF0_PIX_SIZE_MASK) << LCD_SERIAL_STR_BYTE_CONFIG_SIF0_PIX_SIZE_OFFSET)

   #define SET_LCD_SERIAL1_IF_STR_BYTE_PIX_SIZE(n) 	REG_LCD_SIF_STR_BYTE_CON_REG &= ~(LCD_SERIAL_STR_BYTE_CONFIG_SIF1_PIX_SIZE_MASK);\
													REG_LCD_SIF_STR_BYTE_CON_REG |= ((n & LCD_SERIAL_STR_BYTE_CONFIG_SIF1_PIX_SIZE_MASK) << LCD_SERIAL_STR_BYTE_CONFIG_SIF1_PIX_SIZE_OFFSET)
	 
   #define SET_LCD_SERIAL0_9_BIT_MODE          REG_LCD_SIF_CON_REG |= LCD_SERIAL_CONFIG_SIF0_SDI_ENABLE_BIT
   #define SET_LCD_SERIAL0_8_BIT_MODE          REG_LCD_SIF_CON_REG &= ~(LCD_SERIAL_CONFIG_SIF0_SDI_ENABLE_BIT)
   #define SET_LCD_SERIAL1_9_BIT_MODE          REG_LCD_SIF_CON_REG |= LCD_SERIAL_CONFIG_SIF1_SDI_ENABLE_BIT
   #define SET_LCD_SERIAL1_8_BIT_MODE          REG_LCD_SIF_CON_REG &= ~(LCD_SERIAL_CONFIG_SIF1_SDI_ENABLE_BIT)

   #define SET_LCD_SERIAL0_CLOCK_PHASE_HIGH REG_LCD_SIF_CON_REG |= LCD_SERIAL_CONFIG_SIF0_LSCK_PHASE_BIT;
   #define SET_LCD_SERIAL0_CLOCK_PHASE_LOW  REG_LCD_SIF_CON_REG &= ~LCD_SERIAL_CONFIG_SIF0_LSCK_PHASE_BIT;
   #define SET_LCD_SERIAL1_CLOCK_PHASE_HIGH REG_LCD_SIF_CON_REG |= LCD_SERIAL_CONFIG_SIF1_LSCK_PHASE_BIT;
   #define SET_LCD_SERIAL1_CLOCK_PHASE_LOW  REG_LCD_SIF_CON_REG &= ~LCD_SERIAL_CONFIG_SIF1_LSCK_PHASE_BIT;

   #define SET_LCD_SERIAL0_CLOCK_DEF_HIGH REG_LCD_SIF_CON_REG |= LCD_SERIAL_CONFIG_SIF0_LSCK_PHASE_BIT;
   #define SET_LCD_SERIAL0_CLOCK_DEF_LOW  REG_LCD_SIF_CON_REG &= ~LCD_SERIAL_CONFIG_SIF0_LSCK_PHASE_BIT;
   #define SET_LCD_SERIAL1_CLOCK_DEF_HIGH REG_LCD_SIF_CON_REG |= LCD_SERIAL_CONFIG_SIF1_LSCK_PHASE_BIT;
   #define SET_LCD_SERIAL1_CLOCK_DEF_LOW  REG_LCD_SIF_CON_REG &= ~LCD_SERIAL_CONFIG_SIF1_LSCK_PHASE_BIT;

   #define ENABLE_LCD_SERIAL_IF_HW_CS          REG_LCD_SIF_CON_REG |= LCD_SERIAL_CONFIG_SIF_HW_CS_CTRL_BIT
   #define DISABLE_LCD_SERIAL_IF_HW_CS        REG_LCD_SIF_CON_REG &= ~(LCD_SERIAL_CONFIG_SIF_HW_CS_CTRL_BIT)
   
   #define SET_LCD_SERIAL_IF_REG(if_num, val)        REG_LCD_SIF_CON_REG  = (val)
   #define GET_LCD_SERIAL_IF_REG(if_num)             REG_LCD_SIF_CON_REG
   #define SET_LCD_SERIAL_PIX_CON_REG(if_num, val)   REG_LCD_SIF_PIX_CON_REG  = (val)
   #define GET_LCD_SERIAL_PIX_CON_REG(if_num) 		 REG_LCD_SIF_PIX_CON_REG
   #define SET_LCD_SERIAL_STR_BYTE_CON_REG(if_num, val)   REG_LCD_SIF_STR_BYTE_CON_REG  = (val)
   #define GET_LCD_SERIAL_STR_BYTE_CON_REG(if_num)   REG_LCD_SIF_STR_BYTE_CON_REG
   #define GET_LCD_SERIAL_IF_TIMING_REG(if_num)      *((volatile unsigned int *)(LCD_SIF0_TIMING_REG + 4 * (if_num))) 

   #define ENABLE_LCD_SERIAL0_CS               REG_LCD_SIF_CS_REG &= ~(LCD_SERIAL_CONFIG_CS0_LEVEL_BIT)
   #define DISABLE_LCD_SERIAL0_CS              REG_LCD_SIF_CS_REG |= LCD_SERIAL_CONFIG_CS0_LEVEL_BIT
   #define ENABLE_LCD_SERIAL1_CS               REG_LCD_SIF_CS_REG &= ~(LCD_SERIAL_CONFIG_CS1_LEVEL_BIT)
   #define DISABLE_LCD_SERIAL1_CS              REG_LCD_SIF_CS_REG |= LCD_SERIAL_CONFIG_CS1_LEVEL_BIT
///******************************************************///
///******** Macro of LCD PIF*****************************///

   #define LCD_PARALLEL_IF_OFFSET 4
   #define SET_LCD_PARALLEL_IF_REG(if_num, val)   *((volatile unsigned int *) (LCD_PARALLEL0_CONFIG_REG + LCD_PARALLEL_IF_OFFSET * (if_num))) = (val)
   #define GET_LCD_PARALLEL_IF_REG(if_num)   *((volatile unsigned int *) (LCD_PARALLEL0_CONFIG_REG + LCD_PARALLEL_IF_OFFSET * (if_num)))
   
   // HW clock rate is: 104 MHz. It can't be configured.
   //#define SET_LCD_PARALLEL_CLOCK(if_num, clk)

   #define SET_LCD_PARALLEL_CE2WR_SETUP_TIME(if_num, write_setup_time)\
   {\
      *((volatile unsigned int *) (LCD_PARALLEL0_CONFIG_REG + if_num * 4)) &= ~LCD_PARALLEL_CONFIG_WRITE_SETUP_TIME_MASK;\
      *((volatile unsigned int *) (LCD_PARALLEL0_CONFIG_REG + if_num * 4)) |= (write_setup_time << LCD_PARALLEL_CONFIG_WRITE_SETUP_TIME_OFFSET);\
   }

   #define SET_LCD_PARALLEL_CE2WR_HOLD_TIME(if_num, hold_time)\
   {\
      *((volatile unsigned int *) (LCD_PARALLEL0_CONFIG_REG + if_num * 4)) &= ~LCD_PARALLEL_CONFIG_WRITE_HOLD_TIME_MASK;\
      *((volatile unsigned int *) (LCD_PARALLEL0_CONFIG_REG + if_num * 4)) |= (hold_time << LCD_PARALLEL_CONFIG_WRITE_HOLD_TIME_OFFSET);\
   }

   #define SET_LCD_PARALLEL_WRITE_WAIT_STATE(if_num, wait_state_time)\
   {\
      *((volatile unsigned int *) (LCD_PARALLEL0_CONFIG_REG + if_num * 4)) &= ~LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_MASK;\
      *((volatile unsigned int *) (LCD_PARALLEL0_CONFIG_REG + if_num * 4)) |= (wait_state_time << LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_OFFSET);\
   }


   #define SET_LCD_PARALLEL_READ_HOLD_TIME(if_num, hold_time)\
   {\
      *((volatile unsigned int *) (LCD_PARALLEL0_CONFIG_REG + if_num * 4)) &= ~LCD_PARALLEL_CONFIG_READ_HOLD_TIME_MASK;\
      *((volatile unsigned int *) (LCD_PARALLEL0_CONFIG_REG + if_num * 4)) |= (hold_time << LCD_PARALLEL_CONFIG_READ_HOLD_TIME_OFFSET);\
   }

   #define SET_LCD_PARALLEL_READ_LATENCY_TIME(if_num, read_latency_time)\
   {\
      *((volatile unsigned int *) (LCD_PARALLEL0_CONFIG_REG + if_num * 4)) &= ~LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_MASK;\
      *((volatile unsigned int *) (LCD_PARALLEL0_CONFIG_REG + if_num * 4)) |= (read_latency_time << LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_OFFSET);\
   }

   #define SET_LCD_PARALLEL_CE2RD_SETUP_TIME(if_num, read_setup_time)\
   {\
      *((volatile unsigned int *) (LCD_PARALLEL0_CONFIG_REG + if_num * 4)) &= ~LCD_PARALLEL_CONFIG_READ_SETUP_TIME_MASK;\
      *((volatile unsigned int *) (LCD_PARALLEL0_CONFIG_REG + if_num * 4)) |= (read_setup_time << LCD_PARALLEL_CONFIG_READ_SETUP_TIME_OFFSET);\
   }

   #define GET_LCD_PARALLEL_CE2WR_SETUP_TIME(if_num)  ((*((volatile unsigned int *) (LCD_PARALLEL0_CONFIG_REG + if_num * 4)) & LCD_PARALLEL_CONFIG_WRITE_SETUP_TIME_MASK) >> LCD_PARALLEL_CONFIG_WRITE_SETUP_TIME_OFFSET);

   #define GET_LCD_PARALLEL_CE2WR_HOLD_TIME(if_num)   ((*((volatile unsigned int *) (LCD_PARALLEL0_CONFIG_REG + if_num * 4)) & LCD_PARALLEL_CONFIG_WRITE_HOLD_TIME_MASK) >> LCD_PARALLEL_CONFIG_WRITE_HOLD_TIME_OFFSET);

   #define GET_LCD_PARALLEL_WRITE_WAIT_STATE(if_num)   ((*((volatile unsigned int *) (LCD_PARALLEL0_CONFIG_REG + if_num * 4)) & LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_MASK) >> LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_OFFSET);

   #define GET_LCD_PARALLEL_READ_LATENCY_TIME(if_num, read_latency_time)   ((*((volatile unsigned int *) (LCD_PARALLEL0_CONFIG_REG + if_num * 4)) & LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_MASK) >> LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_OFFSET);

   //width: LCD_PARALLEL_BUS_WIDTH_ENUM
   #define SET_LCD_PARALLEL_DATA_BUS(if_num, width)\
   {\
      REG_LCD_PARALLEL_PDW &= ~(LCD_PARALLEL_IF_BUS_WIDTH_MASK(if_num));\
      REG_LCD_PARALLEL_PDW |= (width << LCD_PARALLEL_IF_BUS_WIDTH_OFFSET(if_num));\
   }

   #define SET_LCD_PARALLEL_CHW(if_num, cycle)\
   {\
      REG_LCD_PARALLEL_PDW &= ~(LCD_PARALLEL_IF_CHW_MASK(if_num));\
      REG_LCD_PARALLEL_PDW |= (cycle << LCD_PARALLEL_IF_CHW_OFFSET(if_num));\
   }

   //E2 remove gamma table. Add the following macros to backward compatiable.
   #define SET_GAMMA_TABLE(gamma_table_id, gamma_index, gamma_value)
   #define SET_LCD_SERIAL_GAMMA_TABLE(n)
   #define SET_LCD_PARALLEL0_GAMMA_R_TABLE(n)
   #define SET_LCD_PARALLEL0_GAMMA_G_TABLE(n)
   #define SET_LCD_PARALLEL0_GAMMA_B_TABLE(n)
   #define SET_LCD_PARALLEL1_GAMMA_TABLE(n)
   #define SET_LCD_PARALLEL2_GAMMA_TABLE(n)
   //LQT
   #define SET_LCD_PARALLEL_GAMMA_R_TABLE(n)
   #define SET_LCD_PARALLEL_GAMMA_G_TABLE(n)
   #define SET_LCD_PARALLEL_GAMMA_B_TABLE(n)
   #define DISABLE_LCD_PARALLEL0_GAMMA(backup_val)

   //LCD_PARALLEL_CLOCK_52MHZ
   #define SET_LCD_PARALLEL_IF_TIMING(if_num, clk, Whold, Wsetup, Wwait_state, Rhold, Rsetup, Rlatency, period)\
   {                                                        \
   	 SET_LCD_PARALLEL_CE2WR_HOLD_TIME(if_num, Whold);       \
   	 SET_LCD_PARALLEL_CE2WR_SETUP_TIME(if_num, Wsetup);     \
   	 SET_LCD_PARALLEL_WRITE_WAIT_STATE(if_num, Wwait_state);\
   	 SET_LCD_PARALLEL_READ_HOLD_TIME(if_num, Rhold);        \
   	 SET_LCD_PARALLEL_CE2RD_SETUP_TIME(if_num, Rsetup);     \
   	 SET_LCD_PARALLEL_READ_LATENCY_TIME(if_num, Rlatency);  \
   	 SET_LCD_PARALLEL_CHW(if_num, period);                  \
   }

   #define SET_LCD_PARALLEL_IF_ATTRB(if_num, width)  \
   {                                                 \
       SET_LCD_PARALLEL_DATA_BUS(if_num, width);     \
   }


   ///set SIF timing
   ///TODO: implement it later, just set empty now
   #define LCD_SERIAL_CLOCK_MUX_SEL_REG (CONFIG_base+0x108) //0xA0010108  //bit[11] 0:user clock source slection 1:98MHz backup for 104MHz
   #define LCD_SERIAL_CLOCK_MUX_SEL_OFFSET 11 
   #define LCD_SERIAL_CLOCK_REG (CONFIG_base+0x11C) //0xA001011C  //bit[6,5,4]  000:156MHz,001:130MHz,010:104MHz,011:78MHz,1xx:52MHz
#if defined(MT6260)
	#define LCD_SERIAL_CLOCK_MASK  0x180
   #define LCD_SERIAL_CLOCK_OFFSET  7
#elif (defined(MT6261) ||  defined(MT2501) ||  defined(MT2502))
	#define LCD_SERIAL_CLOCK_MASK  0x70
   #define LCD_SERIAL_CLOCK_OFFSET  4
#endif
   #define SET_LCD_SERIAL_CLOCK(if_num, clk)	\
   {											\
	*((volatile unsigned int *)LCD_SERIAL_CLOCK_REG) &= (~LCD_SERIAL_CLOCK_MASK); 	\
	*((volatile unsigned int *)LCD_SERIAL_CLOCK_REG) |= (clk << LCD_SERIAL_CLOCK_OFFSET);	 \
   }
   #define GET_LCD_SERIAL_CLOCK(if_num)	((*((volatile unsigned int *)LCD_SERIAL_CLOCK_REG) & LCD_SERIAL_CLOCK_MASK) >> LCD_SERIAL_CLOCK_OFFSET);
   #define SET_LCD_SERIAL_IF_TIMING(if_num, clk, div, period)
   #define SET_LCD_SERIAL_IF_ATTRB(spo, sph, _3wire, csp0, csp1)
   //#define SET_LCD_SERIAL_IF_TIMING(wr_high, wr_low, rd_high, rd_low)
   
   #define LCD_FRAME_UPDATE_TIME_LOG_CONTROL(enable_flag)
   #define LCD_GET_FRAME_UPDATE_TIME(countA, countB)   
///******************************************************///
///******** Macro of GMC THROTTLE************************///

   #define LCD_ENABLE_GMCCON_THROTTLE()                   \
     do {                                                 \
       REG_LCD_GMCCON |= LCD_GMC_THROTTLE_CTRL_ENABLE_BIT; \
     } while(0)

   #define LCD_DISABLE_GMCCON_THROTTLE()                  \
     do {                                                 \
       REG_LCD_GMCCON &=~ LCD_GMC_THROTTLE_CTRL_ENABLE_BIT;\
     } while(0)

   #define LCD_SET_GMCCON_BURST_SIZE(n)                  \
     do {                                                 \
       REG_LCD_GMCCON &=~ LCD_GMC_THROTTLE_BURST_MASK;     \
       REG_LCD_GMCCON |= (n & 0x7);                        \
     } while(0)

   #define LCD_SET_GMCCON_THROTTLE_PERIOD(n)                 \
     do {                                                 \
       REG_LCD_GMCCON &=~ LCD_GMC_THROTTLE_PERIOD_MASK;    \
       REG_LCD_GMCCON |= ((n & 0xFFFF) << 16);             \
     } while(0)

   #define LCD_GET_GMCCON_BURST_SIZE   REG_LCD_GMCCON & LCD_GMC_THROTTLE_BURST_MASK;
///******************************************************///
///******** Macro of W2MEM ******************************///
   #define LCD_WRITE_MEM_AND_LCM
   #define LCD_WRITE_MEM_ONLY
   
   #define SET_LCD_ROI_CTRL_W2MEM_DISCONT
   #define SET_LCD_ROI_CTRL_W2MEM_CONT
   #define FIX_LCD_ROI_CTRL_W2MEM_BUG     // empty for btmt build pass
   
   #define SET_LCD_ROI_WMEM_OFFSET(x, y)
   #define LCD_WRITE_MEM_RGB565
   #define LCD_WRITE_MEM_RGB888
   #define LCD_WRITE_MEM_ARGB8888
   #define LCD_WRITE_MEM_PARGB8888
   #define LCD_WRITE_MEM_ARGB8888_WITH_PIXEL_ALPHA
   #define LCD_WRITE_MEM_PARGB8888_WITH_PIXEL_ALPHA
   #define LCD_WRITE_MEM_PARGB6666
   #define LCD_WRITE_MEM_PARGB6666_WITH_PIXEL_ALPHA


   /* mem_color_format: LCD_WMEM_COLOR_FORMAT_ENUM */
   #define SET_LCD_WRITE_MEM_FORMAT(format)
   //#define SET_LCD_MAIN_WINDOW_SIZE (column,row)  REG_LCD_MAIN_WINDOW_SIZE = ((row<<16)|column);
   #define SET_LCD_WMEM_PITCH(width)

///******************************************************///
///******** Macro of ROI ******************************///
   //#define SET_LCD_DISABLE_LAYER(n)         REG_LCD_ROI_CTRL &= ~n;
   #define SET_LCD_SEND_RES_MODE(n)           REG_LCD_ROI_CTRL &= (~LCD_ROI_CTRL_SEND_RES_MOD_BIT);\
                                              REG_LCD_ROI_CTRL |= (n & 0x1)<<24;

   #define SET_LCD_ROI_CTRL_NUMBER_OF_CMD(n)  REG_LCD_ROI_CTRL &= ~LCD_ROI_CTRL_CMD_NUMBER_MASK;\
                                              REG_LCD_ROI_CTRL |= (( n - 1) << 8);
   #define SET_LCD_CMD_QUEUE1                 
   #define SET_LCD_CMD_QUEUE2                 

   #define SET_LCD_ENABLE_LAYER(n)            REG_LCD_ROI_CTRL &= ~LCD_ROI_CTRL_LAYER_MASK;\
                                              REG_LCD_ROI_CTRL |= (n);
   #define SET_LCD_ROI_CTRL_CMD_LATENCY(n)    
   #define GET_LCD_ROI_CTRL_CMD_LATENCY()     0
   
   #define ENABLE_LCD_ROI_CTRL_CMD_FIRST      REG_LCD_ROI_CTRL |= LCD_ROI_CTRL_CMD_ENABLE_BIT;
   #define DISABLE_LCD_ROI_CTRL_CMD_FIRST     REG_LCD_ROI_CTRL &= ~LCD_ROI_CTRL_CMD_ENABLE_BIT;
   #define ENABLE_LCD_ROI_CTRL_W2MEM
   #define DISABLE_LCD_ROI_CTRL_W2MEM

   #define SET_LCD_ROI_CTRL_OUTPUT_FORMAT(n)   REG_LCD_ROI_CTRL &= ~LCD_ROI_CTRL_DATA_FORMAT_MASK;\
                                               REG_LCD_ROI_CTRL |= n;
   #define GET_LCD_ROI_CTRL_OUTPUT_FORMAT      (REG_LCD_ROI_CTRL & LCD_ROI_CTRL_DATA_FORMAT_MASK)
   #define SET_LCD_ROI_WINDOW_OFFSET(x, y)     REG_LCD_ROI_OFFSET = (( y << 16) | x);
   #define SET_LCD_ROI_WINDOW_SIZE(column,row) REG_LCD_ROI_SIZE = ((row << 16) | column);
   #define DISABLE_ALL_LCD_LAYER_WINDOW        REG_LCD_ROI_CTRL &= ~LCD_ROI_CTRL_LAYER_MASK;   
   #define SET_WROI_CONTINUOUS_COUNT(n)        REG_LCD_ROI_W2LCM_CONTI  &= ~WROI_CONTINUOUS_COUNT_MASK;\
                                               REG_LCD_ROI_W2LCM_CONTI |= (n & 0xff);
   #define WROI_CONTINUOUS_COUNT_MASK          0xFF
///******************************************************///
///******** Macro of Layer ***************************///
   #define REG_LCD_LAYER_CTRL(n)          *((volatile unsigned int *) (LCD_LAYER0_CTRL_REG       + (n) * LCD_LAYER_ADDR_OFFSET))
   #define REG_LCD_LAYER_COLOR_KEY(n)     *((volatile unsigned int *) (LCD_LAYER0_SRC_KEY_REG    + (n) * LCD_LAYER_ADDR_OFFSET))
   #define REG_LCD_LAYER_OFFSET(n)        *((volatile unsigned int *) (LCD_LAYER0_OFFSET_REG     + (n) * LCD_LAYER_ADDR_OFFSET))
   #define REG_LCD_LAYER_BUFF_ADDR(n)     *((volatile unsigned int *) (LCD_LAYER0_BUFF_ADDR_REG  + (n) * LCD_LAYER_ADDR_OFFSET))
   #define REG_LCD_LAYER_SIZE(n)          *((volatile unsigned int *) (LCD_LAYER0_SIZE_REG       + (n) * LCD_LAYER_ADDR_OFFSET))
   #define REG_LCD_LAYER_SCROLL_OFFSET(n)
   #define REG_LCD_LAYER_MEM_OFFSET(n)    *((volatile unsigned int *) (LCD_LAYER0_MEM_OFFSET_REG + (n) * LCD_LAYER_ADDR_OFFSET))
   #define REG_LCD_LAYER_MEM_PITCH(n)     *((volatile unsigned int *) (LCD_LAYER0_MEM_PITCH_REG  + (n) * LCD_LAYER_ADDR_OFFSET))

   #define SET_LCD_LAYER_SOURCE_KEY(index, color)          REG_LCD_LAYER_COLOR_KEY(index) = color;
   #define SET_LCD_LAYER_WINDOW_OFFSET(index, x, y)        REG_LCD_LAYER_OFFSET(index) = ((y << 16) | x);
   #define SET_LCD_LAYER_WINDOW_SIZE(index, width, height) REG_LCD_LAYER_SIZE(index) = ((height << 16) | width);
   #define SET_LCD_LAYER_WINDOW_WMEM_OFFSET(index, x, y)   REG_LCD_LAYER_MEM_OFFSET(index) = ((y << 16) | x);
   #define SET_LCD_LAYER_WINDOW_WMEM_PITCH(index, width)   REG_LCD_LAYER_MEM_PITCH(index) = width;
   //#define GET_LCD_LAYER_WINDOW_WIDTH(index)               (kal_uint16) (REG_LCD_LAYER_SIZE(index) & 0xFFFF);
   //#define GET_LCD_LAYER_WINDOW_HEIGHT(index)              (kal_uint16) (REG_LCD_LAYER_SIZE(index) >> 16) & 0xFFFF);

   #define SET_LCD_LAYER_ROTATE(layer_index, n)            REG_LCD_LAYER_CTRL(layer_index) &= ~LCD_LAYER_CTRL_ROTATE_MASK;\
                                                           REG_LCD_LAYER_CTRL(layer_index) |= (n<<11);
   #define GET_LCD_LAYER_COLOR_FORMAT(layer_index)         (REG_LCD_LAYER_CTRL(layer_index) >> LCD_LAYER_CTRL_FORMAT_OFFSET) & 0xF;

   //For LQT used.
   #define LCD_LAYER_CTRL_SOURCE_AUTO_INC_BIT       0x00008000     /* source address auto increament */   
   #define ENABLE_LCD_LAYER0_SOURCE_KEY             REG_LCD_LAYER0_CTRL |= LCD_LAYER_CTRL_SOURCE_KEY_ENABLE_BIT;
   #define DISABLE_LCD_LAYER0_SOURCE_KEY            REG_LCD_LAYER0_CTRL &= ~LCD_LAYER_CTRL_SOURCE_KEY_ENABLE_BIT;   
   #define ENABLE_LAYER0_ADDR_AUTO_INC              REG_LCD_LAYER0_CTRL = ~LCD_LAYER_CTRL_SOURCE_AUTO_INC_BIT;
   #define DISABLE_LAYER0_ADDR_AUTO_INC             REG_LCD_LAYER0_CTRL |= LCD_LAYER_CTRL_SOURCE_AUTO_INC_BIT;
   #define ENABLE_LAYER0_READ_DATA_SWAP             REG_LCD_LAYER0_CTRL |= LCD_LAYER_CTRL_DATA_SWAP_BIT;
   #define DISABLE_LAYER0_READ_DATA_SWAP            REG_LCD_LAYER0_CTRL &= ~LCD_LAYER_CTRL_DATA_SWAP_BIT;   
   #define ENABLE_LCD_LAYER0_OPACITY                REG_LCD_LAYER0_CTRL |= LCD_LAYER_CTRL_OPACITY_ENABLE_BIT;
   #define DISABLE_LCD_LAYER0_OPACITY               REG_LCD_LAYER0_CTRL &= ~LCD_LAYER_CTRL_OPACITY_ENABLE_BIT;
                                                    
   #define DISABLE_LCD_LAYER_OPACITY(layer_index)      REG_LCD_LAYER_CTRL(layer_index) = REG_LCD_LAYER_CTRL(layer_index) & (~LCD_LAYER_CTRL_OPACITY_ENABLE_BIT);
   #define ENABLE_LCD_LAYER_OPACITY(layer_index)       REG_LCD_LAYER_CTRL(layer_index) = REG_LCD_LAYER_CTRL(layer_index) | (LCD_LAYER_CTRL_OPACITY_ENABLE_BIT);

   #define SET_LCD_LAYER_OPACITY(layer_index, val)     REG_LCD_LAYER_CTRL(layer_index) = REG_LCD_LAYER_CTRL(layer_index) & (~LCD_LAYER_CTRL_OPACITY_VALUE_MASK);\
   	                                                   REG_LCD_LAYER_CTRL(layer_index) = REG_LCD_LAYER_CTRL(layer_index) | (val & LCD_LAYER_CTRL_OPACITY_VALUE_MASK);
   
   #define DISABLE_LCD_LAYER_SOURCE_KEY(layer_index)   REG_LCD_LAYER_CTRL(layer_index) = REG_LCD_LAYER_CTRL(layer_index) & (~LCD_LAYER_CTRL_SOURCE_KEY_ENABLE_BIT);
   #define ENABLE_LCD_LAYER_SOURCE_KEY(layer_index)    REG_LCD_LAYER_CTRL(layer_index) = REG_LCD_LAYER_CTRL(layer_index) | (LCD_LAYER_CTRL_SOURCE_KEY_ENABLE_BIT);
   #define DISABLE_LCD_LAYER_DST_KEY(layer_index)   REG_LCD_LAYER_CTRL(layer_index) = REG_LCD_LAYER_CTRL(layer_index) & (~LCD_LAYER_CTRL_DST_KEY_ENABLE_BIT);
   #define ENABLE_LCD_LAYER_DST_KEY(layer_index)    REG_LCD_LAYER_CTRL(layer_index) = REG_LCD_LAYER_CTRL(layer_index) | (LCD_LAYER_CTRL_DST_KEY_ENABLE_BIT);

   #define ENABLE_LAYER_ADDR_AUTO_INC(layer_index)     REG_LCD_LAYER_CTRL(layer_index) = REG_LCD_LAYER_CTRL(layer_index) & (~LCD_LAYER_CTRL_SOURCE_AUTO_INC_BIT);

   #define DISABLE_LAYER_READ_DATA_SWAP(layer_index)   REG_LCD_LAYER_CTRL(layer_index) = REG_LCD_LAYER_CTRL(layer_index) & (~LCD_LAYER_CTRL_DATA_SWAP_BIT);

   #define SET_LCD_LAYER_COLOR_FORMAT(layer_index, color_format)   REG_LCD_LAYER_CTRL(layer_index) = REG_LCD_LAYER_CTRL(layer_index) & (~LCD_LAYER_CTRL_COLOR_FORMAT_MASK);\
                                                                   REG_LCD_LAYER_CTRL(layer_index) = REG_LCD_LAYER_CTRL(layer_index) | (color_format << 20);

   /*-------------------------DDv2 only start ----------------------------*/
   // Write mem setting
   #define LCD_SET_ROI_WMEM_CTRL_CLEAR
   #define LCD_SET_ROI_WMEM_CTRL_MEM_ONLY
   #define LCD_SET_ROI_WMEM_CTRL_MEM_AND_LCM
   #define LCD_SET_ROI_WMEM_CTRL_FMT(fmt)
   #define LCD_SET_ROI_WMEM_CTRL_ALPHA(alpha)
   #define LCD_SET_ROI_WMEM_CTRL_PITCH_EN

   #define LCD_SET_ROI_WMEM_ADDR(addr)
   #define LCD_SET_ROI_WMEM_OFFSET(x,y)

   #define LCD_SET_ROI_WMEM_ADDR_LEGACY(addr,offset)

   // ROI setting
   #define LCD_SET_ROI_CONTROL(val)            REG_LCD_ROI_CTRL             = val   
   #define LCD_SET_ROI_CTRL_CLEAR              REG_LCD_ROI_CTRL             &= (~0xF300FFFF);
   #define LCD_SET_ROI_CTRL_CMD_EN             REG_LCD_ROI_CTRL            |= LCD_ROI_CTRL_CMD_ENABLE_BIT;
   #define LCD_SET_ROI_CTRL_FMT(fmt)           REG_LCD_ROI_CTRL            |= ((fmt) & LCD_ROI_CTRL_DATA_FORMAT_MASK);

   #define LCD_SET_ROI_CTRL_PERIOD(period) 

   #define LCD_SET_ROI_CTRL_FLATTEN_EN(en)     REG_LCD_ROI_CTRL            |= (((en) & 0x1) << LCD_ROI_CTRL_W2MEM_OFFSET);
   #define LCD_SET_ROI_CTRL_LAYER_EN(layer)    REG_LCD_ROI_CTRL            |= LCD_LAYER_ENABLE_BIT(layer);

   #define LCD_COLOR_EN_MASK 0x04000000
#if 1
   #define SET_LCD_ROI_CTRL_COLOR_EN(en)\
   {\
      REG_LCD_ROI_CTRL &= ~LCD_COLOR_EN_MASK;\
      REG_LCD_ROI_CTRL |= ((en & 0x1) << 26);\
   }
#else
/* under construction !*/
#endif

   #define LCD_SET_ROI_OFFSET(x,y)             REG_LCD_ROI_OFFSET           = (((y)<<16) | (x));
   #define LCD_SET_ROI_SIZE(w,h)               REG_LCD_ROI_SIZE             = (((h)<<16) | (w));
   #define LCD_SET_ROI_BG_COLOR(color)         REG_LCD_ROI_BACKGROUND_COLOR = (color);
   #define LCD_SET_ROI_CMD_ADDR(cmd)           REG_LCD_ROI_CMD_ADDR         = (cmd);
   #define LCD_SET_ROI_DATA_ADDR(data)         REG_LCD_ROI_DATA_ADDR        = (data);
   #define LCD_GET_ROI_WIDTH                   (kal_uint16)(REG_LCD_ROI_SIZE & 0xFFFF)
   #define LCD_GET_ROI_HEIGHT                  (kal_uint16)((REG_LCD_ROI_SIZE >> 16) & 0xFFFF)
   #define GET_LCD_LAYER_WINDOW_WIDTH(layer_index)  (kal_uint16) (REG_LCD_LAYER_SIZE(layer_index) & 0xFFFF)
   #define GET_LCD_LAYER_WINDOW_HEIGHT(layer_index) (kal_uint16) ((REG_LCD_LAYER_SIZE(layer_index) >> 16) & 0xFFFF)
   #define GET_LCD_LAYER_WINDOW_OFFSET_X(layer_index)	 (kal_uint16) (REG_LCD_LAYER_OFFSET(layer_index) & 0xFFFF)
   #define GET_LCD_LAYER_WINDOW_OFFSET_Y(layer_index)	 (kal_uint16) ((REG_LCD_LAYER_OFFSET(layer_index) >> 16) & 0xFFFF)
   #define GET_LCD_LAYER_CTRL_ROTATE(layer_index)	 (kal_uint16) ((REG_LCD_LAYER_CTRL(layer_index) & LCD_LAYER_CTRL_ROTATE_MASK) >> LCD_LAYER_CTRL_ROTATE_OFFSET)

   // Layer setting
   #define LCD_SET_LAYER_CTRL(n, val)          *((volatile unsigned int *) (LCD_LAYER0_CTRL_REG + (n) * LCD_LAYER_ADDR_OFFSET))  = val
   #define LCD_SET_LAYER_CTRL_CLEAR(n)         *((volatile unsigned int *) (LCD_LAYER0_CTRL_REG + (n) * LCD_LAYER_ADDR_OFFSET))  = 0;
   #define LCD_SET_LAYER_CTRL_SOURCE_KEY_EN(n) *((volatile unsigned int *) (LCD_LAYER0_CTRL_REG + (n) * LCD_LAYER_ADDR_OFFSET)) |= LCD_LAYER_CTRL_SOURCE_KEY_ENABLE_BIT;
   #define LCD_SET_LAYER_CTRL_OPACITY_EN(n)    *((volatile unsigned int *) (LCD_LAYER0_CTRL_REG + (n) * LCD_LAYER_ADDR_OFFSET)) |= LCD_LAYER_CTRL_OPACITY_ENABLE_BIT;
   #define LCD_SET_LAYER_CTRL_OPACITY(n,value) *((volatile unsigned int *) (LCD_LAYER0_CTRL_REG + (n) * LCD_LAYER_ADDR_OFFSET)) |= ((value) << LCD_LAYER_ALPHA_VAL_OFFSET);
   #define LCD_SET_LAYER_CTRL_ROTATE(n,angle)  *((volatile unsigned int *) (LCD_LAYER0_CTRL_REG + (n) * LCD_LAYER_ADDR_OFFSET)) |= ((angle) << LCD_LAYER_CTRL_ROTATE_OFFSET);
   #define LCD_GET_LAYER_CTRL_ROTATE(n)        (((*((volatile unsigned int *) (LCD_LAYER0_CTRL_REG + (n) * LCD_LAYER_ADDR_OFFSET)))>> LCD_LAYER_CTRL_ROTATE_OFFSET) & 0x7);
   #define GET_LCD_LAYER_ROTATE(n)              LCD_GET_LAYER_CTRL_ROTATE(n)

   #define LCD_SET_LAYER_CTRL_DATA_SWAP_EN(n)  *((volatile unsigned int *) (LCD_LAYER0_CTRL_REG + (n) * LCD_LAYER_ADDR_OFFSET)) |= LCD_LAYER_CTRL_DATA_SWAP_BIT;
   #define LCD_SET_LAYER_CTRL_DITHER_EN(n)     *((volatile unsigned int *) (LCD_LAYER0_CTRL_REG + (n) * LCD_LAYER_ADDR_OFFSET)) |= LCD_LAYER_CTRL_DITHER_ENABLE_BIT;
   #define LCD_SET_LAYER_CTRL_FMT(n,fmt)       *((volatile unsigned int *) (LCD_LAYER0_CTRL_REG + (n) * LCD_LAYER_ADDR_OFFSET)) |= ((fmt) << LCD_LAYER_CTRL_FORMAT_OFFSET);

   #define LCD_SET_LAYER_COLOR_KEY(n,key)      *((volatile unsigned int *) (LCD_LAYER0_SRC_KEY_REG   + (n)  * LCD_LAYER_ADDR_OFFSET)) = (key);
   #define LCD_SET_LAYER_OFFSET(n,x,y)         *((volatile unsigned int *) (LCD_LAYER0_OFFSET_REG    + (n)  * LCD_LAYER_ADDR_OFFSET)) = (((y)<<16) | (x));
   #define LCD_SET_LAYER_BUFF_ADDR(n,addr)     *((volatile unsigned int *) (LCD_LAYER0_BUFF_ADDR_REG + (n)  * LCD_LAYER_ADDR_OFFSET)) = (addr);
   #define LCD_SET_LAYER_SIZE(n,w,h)           *((volatile unsigned int *) (LCD_LAYER0_SIZE_REG      + (n)  * LCD_LAYER_ADDR_OFFSET)) = (((h)<<16) | (w));
   #define LCD_SET_LAYER_MEM_OFFSET(n,x,y)     *((volatile unsigned int *) (LCD_LAYER0_MEM_OFFSET_REG + (n) * LCD_LAYER_ADDR_OFFSET)) = (((y)<<16) | (x));

   #define LCD_CLEAR_LAYER_REG(id)          do{                                                                     \
                                                if(id>3)  ASSERT(0);                                                \
                                                memset((void *)(LCD_LAYER0_BASE_ADDR + (id) * LCD_LAYER_ADDR_OFFSET) ,0 , LCD_LAYER0_MEM_PITCH_REG - LCD_LAYER0_BASE_ADDR + 4);  \
                                            } while(0);       

   /*-------------------------DDv2 only end ----------------------------*/

///******************************************************///
///******** Macro of HWTRG HWREF ************************///
   #define SET_LCD_HW_TRIGGER_LAYER(n)
   #define GET_LCD_HW_TRIGGER_LAYER
   #define ENABLE_LCD_HW_TRIGGER_UPDATE
   #define DISABLE_LCD_HW_TRIGGER_UPDATE
   #define LCD_HW_TRIGGER_BUSY
   #define LCD_CLEAR_HW_TRIGGER_DLY
   #define SET_LCD_HW_TRIGGER_SWREF_BIT
   #define CLEAR_LCD_HW_TRIGGER_SWREF_BIT
   #define SET_LCD_HW_TRIGGER_HWREF_BIT    SET_LCD_HW_TRIGGER_SWREF_BIT
   #define CLEAR_LCD_HW_TRIGGER_HWREF_BIT  CLEAR_LCD_HW_TRIGGER_SWREF_BIT
   #define SET_SWREF_MODE(n)
   #define SET_HWREF_MODE(n)
   #define SET_LCD_HW_TRIGGER_SRC(module)

///******************************************************///
///******** Macro of Dither ************************///
   #define LCD_DITHER_BIT_MASK 0x333
   #define SET_LCD_DITHER_SEED(r_seed, g_seed, b_seed)
   #define SET_LCD_DITHER_BIT(r, g, b)\
   {\
      *((volatile unsigned int *) LCD_DITHER_CON_REG) &= ~LCD_DITHER_BIT_MASK;\
      *((volatile unsigned int *) LCD_DITHER_CON_REG) |= (((r & 0x3) << 8) | ((g & 0x3) << 4) |(b & 0x3));\
   }

///******************************************************///
///******** Macro of PQ ************************///
   #define LCD_DITHER_PQ_MASK 0x08000000
   #define SET_LCD_DITHER_PQ(en)\
   {\
      *((volatile unsigned int *) LCD_DITHER_CON_REG) &= ~LCD_DITHER_PQ_MASK;\
      *((volatile unsigned int *) LCD_DITHER_CON_REG) |= ((en & 0x1) << 27);\
   }

///******************************************************///
///******** Macro of LGamma *****************************///
   #define SET_LCD_LGAMMA_OFFSET_REG(n, value)    *((volatile unsigned short *)LCD_LGAMMA_OFFSET_REG(n)) = value;
   #define SET_LCD_LGAMMA_SLOPE_REG(n, value)     *((volatile unsigned short *)LCD_LGAMMA_SLOPE_REG(n)) = value;

///******************************************************///
///******** Macro of Driving Current ********************///
#define LCD_DRIVING_CURRENT_ADD_0MA 0x00
#define LCD_DRIVING_CURRENT_ADD_2MA 0x01
#define LCD_DRIVING_CURRENT_ADD_4MA 0x02
#define LCD_DRIVING_CURRENT_ADD_6MA 0x03
#define LCD_DRIVING_CURRENT_ADD_8MA 0x04
#define LCD_DRIVING_CURRENT_ADD_10MA 0x05
#define LCD_DRIVING_CURRENT_ADD_12MA 0x06
#define LCD_DRIVING_CURRENT_ADD_14MA 0x07

#define LCD_DRIVING_CURRENT_OFFSET 8
#define LCD_DRIVING_CURRENT_MASK 0x700
#if defined(MT6260)
#define LCD_DRIVING_CURRENT_REG	(GPIO_base + 0x800) //0xA0020800 //GPIO_DRV0[10,9,8]
#elif defined(MT6261) || defined(MT2501) || defined(MT2502)

#define LCD_DRIVING_CURRENT_REG	(GPIO_base + 0x810) //0xA0020810 //GPIO_DRV1
#define LCD_DRIVING_CURRENT_SERIAL0_1V8_OFFSET 22				// GPIO 45-50
#define LCD_DRIVING_CURRENT_SERIAL0_1V8_MASK 0xC00000 		// Bit 23:22
#define LCD_DRIVING_CURRENT_SERIAL0_2V8_OFFSET 12				// GPIO25-30
#define LCD_DRIVING_CURRENT_SERIAL0_2V8_MASK 0x3000 			// Bit 13:12
#define LCD_DRIVING_CURRENT_SERIAL1_1V8_OFFSET 22				// GPIO 45-50
#define LCD_DRIVING_CURRENT_SERIAL1_1V8_MASK 0xC00000 		// Bit 23:22
#define LCD_DRIVING_CURRENT_SERIAL1_2V8_OFFSET_1 18			// GPIO42
#define LCD_DRIVING_CURRENT_SERIAL1_2V8_MASK_1 0xC0000 		// Bit 19:18
#define LCD_DRIVING_CURRENT_SERIAL1_2V8_OFFSET_2 12			// GPIO25-30
#define LCD_DRIVING_CURRENT_SERIAL1_2V8_MASK_2 0x3000 			// Bit 13:12

#define CONFIG_LCD_DRIVING_CURRNET_SERIAL0_1V8(current) \
   {\
      *((volatile unsigned int *) LCD_DRIVING_CURRENT_REG) &= ~LCD_DRIVING_CURRENT_SERIAL0_1V8_MASK;\
      *((volatile unsigned int *) LCD_DRIVING_CURRENT_REG) |= (current << LCD_DRIVING_CURRENT_SERIAL0_1V8_OFFSET);\
   }

#define CONFIG_LCD_DRIVING_CURRNET_SERIAL0_2V8(current) \
   {\
      *((volatile unsigned int *) LCD_DRIVING_CURRENT_REG) &= ~LCD_DRIVING_CURRENT_SERIAL0_2V8_MASK;\
      *((volatile unsigned int *) LCD_DRIVING_CURRENT_REG) |= (current << LCD_DRIVING_CURRENT_SERIAL0_2V8_OFFSET);\
   }

#define CONFIG_LCD_DRIVING_CURRNET_SERIAL1_1V8(current) \
   {\
      *((volatile unsigned int *) LCD_DRIVING_CURRENT_REG) &= ~LCD_DRIVING_CURRENT_SERIAL1_1V8_MASK;\
      *((volatile unsigned int *) LCD_DRIVING_CURRENT_REG) |= (current << LCD_DRIVING_CURRENT_SERIAL1_1V8_OFFSET);\
   }

#define CONFIG_LCD_DRIVING_CURRNET_SERIAL1_2V8(current) \
   {\
      *((volatile unsigned int *) LCD_DRIVING_CURRENT_REG) &= ~LCD_DRIVING_CURRENT_SERIAL1_2V8_MASK_1;\
      *((volatile unsigned int *) LCD_DRIVING_CURRENT_REG) |= (current << LCD_DRIVING_CURRENT_SERIAL1_2V8_OFFSET_1);\
	*((volatile unsigned int *) LCD_DRIVING_CURRENT_REG) &= ~LCD_DRIVING_CURRENT_SERIAL1_2V8_MASK_2;\
	*((volatile unsigned int *) LCD_DRIVING_CURRENT_REG) |= (current << LCD_DRIVING_CURRENT_SERIAL1_2V8_OFFSET_2);\
   }

#endif

//Dong: if using 16bit interface, specially need to set nld9~nld15 driving current
// 0xA0020810 bit 6:8  for gpio 29 nld12
// 0xA0020810 bit 9:11  for gpio 27~28 nld13~nld14
// 0xA0020820 bit 14:(0xA0020830 bit 0)  for gpio 49 nld15

/* Edward: 6261 use these bits:
Serial0_1v8: bit: 23:22 for gpio 45-50
Serial0_2v8: bit: 13:12 for gpio 25-30
Serial1_1v8: bit: 23:22 for gpio 45-50
Serial1_2v8: bit: 19:18 13:12 for gpio 25-30 gpio42

*/
#if defined(__FLAVOR_16BITLCM_WIFI__) 
#define CONFIG_LCD_DRIVING_CURRNET(current) \
   {\
      *((volatile unsigned int *) LCD_DRIVING_CURRENT_REG) &= ~LCD_DRIVING_CURRENT_MASK;\
      *((volatile unsigned int *) LCD_DRIVING_CURRENT_REG) |= (current << LCD_DRIVING_CURRENT_OFFSET);\
      *((volatile unsigned int *) 0xA0020810) |= (current << 9);\
      *((volatile unsigned int *) 0xA0020810) |= (current << 6);\
      *((volatile unsigned int *) 0xA0020820) |= (current << 14);\
   }
#else
#define CONFIG_LCD_DRIVING_CURRNET(current) \
   {\
      *((volatile unsigned int *) LCD_DRIVING_CURRENT_REG) &= ~LCD_DRIVING_CURRENT_MASK;\
      *((volatile unsigned int *) LCD_DRIVING_CURRENT_REG) |= (current << LCD_DRIVING_CURRENT_OFFSET);\
   }
   
#endif 

   ///TODO: confirm the Pin driving setting both for S00 and S01
   //LCD driving current control     
/*
   #define REG_LCD_CTRL_PIN_DRIVING_CURRENT  *((volatile unsigned short *) 0x80000504)
   #define LCD_CTRL_PIN_DRIVING_CURRENT_OFFSET  0
   #define LCD_CTRL_PIN_DRIVING_CURRENT_MAX     3   
   #define LCD_CTRL_PIN_DRIVING_CURRENT_MASK    0x3

   #define CONFIG_LCD_CONTROL_PIN_DRIVING_CURRNET(current) \
      {\
         REG_LCD_CTRL_PIN_DRIVING_CURRENT &= ~LCD_CTRL_PIN_DRIVING_CURRENT_MASK;\
         REG_LCD_CTRL_PIN_DRIVING_CURRENT |= ((current & LCD_CTRL_PIN_DRIVING_CURRENT_MAX) << LCD_CTRL_PIN_DRIVING_CURRENT_OFFSET);\
      }

   #define REG_LCD_CTRL_LSCE0B_PIN_DRIVING_CURRENT  *((volatile unsigned short *) 0x80000500)
   #define LCD_CTRL_LSCE0B_PIN_DRIVING_CURRENT_OFFSET  10
   #define LCD_CTRL_LSCE0B_PIN_DRIVING_CURRENT_MAX     3   
   #define LCD_CTRL_LSCE0B_PIN_DRIVING_CURRENT_MASK    0xC00
   
   #define CONFIG_LCD_CTRL_LSCE0B_PIN_DRIVING_CURRNET(current) \
         {\
            REG_LCD_CTRL_LSCE0B_PIN_DRIVING_CURRENT &= ~LCD_CTRL_LSCE0B_PIN_DRIVING_CURRENT_MASK;\
            REG_LCD_CTRL_LSCE0B_PIN_DRIVING_CURRENT |= ((current & LCD_CTRL_LSCE0B_PIN_DRIVING_CURRENT_MAX) << LCD_CTRL_LSCE0B_PIN_DRIVING_CURRENT_OFFSET);\
         }


   #define REG_LCD_NLD_PIN_DRIVING_CURRENT  *((volatile unsigned short *) 0x80000504)
   #define LCD_NLD_PIN_DRIVING_CURRENT_OFFSET  8
   #define LCD_NLD_PIN_DRIVING_CURRENT_MAX  3
   #define LCD_NLD_PIN_DRIVING_CURRENT_MASK  0x300
   #define CONFIG_LCD_NLD_PIN_DRIVING_CURRNET(current) \
      {\
         REG_LCD_NLD_PIN_DRIVING_CURRENT &= ~LCD_NLD_PIN_DRIVING_CURRENT_MASK;\
         REG_LCD_NLD_PIN_DRIVING_CURRENT |= ((current & LCD_NLD_PIN_DRIVING_CURRENT_MAX) << LCD_NLD_PIN_DRIVING_CURRENT_OFFSET);\
      }
 */
  
///******************************************************///
///******** Macro of Frame Count ************************///
   #define LCD_COUNTER_SEL_MASK           0x30
   #define LCD_COUNTER_CLEAR_BIT          0x2
   #define LCD_COUNTER_START_BIT          0x1
   #define LCD_COUNTER_UPDATE_TIME_BIT    0x10
   #define LCD_START_DEBUG_COUNTER        REG_LCD_COUNTER_CON |= LCD_COUNTER_START_BIT;
   #define LCD_CLEAR_DEBUG_COUNTER        REG_LCD_COUNTER_CON |= LCD_COUNTER_CLEAR_BIT;\
                                          REG_LCD_COUNTER_CON &= ~(LCD_COUNTER_CLEAR_BIT);
   #define LCD_SET_FRAME_COUNTER          REG_LCD_COUNTER_CON &= ~LCD_COUNTER_SEL_MASK;
   #define LCD_SET_UPDATE_TIME_COUNTER    REG_LCD_COUNTER_CON &= ~LCD_COUNTER_SEL_MASK;\
                                          REG_LCD_COUNTER_CON |= LCD_COUNTER_UPDATE_TIME_BIT;

///******************************************************///
///******** Macro of LUT ********************************///
   //Not support index color
   #define SET_LUT0_COLOR(index, color)           
   #define GET_LUT0_COLOR(index)           0

///******************************************************///
///******** Macro of LCM Command Queue ******************///
   #define SET_LCD_CMD_PARAMETER(index, cmd, para)   *((volatile unsigned int *) (LCD_CMD_PARAMETER0_ADDR + (index << 2))) = para|cmd;
#ifdef FPGA
   //Only for FPGA test
   #define SET_LCD_CMD_PARAMETER_BY_CPU(addr, val)   *((volatile unsigned int *) (addr)) = val;
#endif

typedef struct
{
    kal_bool    lcd_ta_running;
    kal_uint32  lcd_ta_time_curr;
    kal_uint32  lcd_ta_time_prev;
    kal_uint32  lcd_ta_time_diff;
    kal_uint16  lcd_ta_roi_w;
    kal_uint16  lcd_ta_roi_h;
    kal_uint32  lcd_ta_frame_rate;

} lcd_ta_struct;


   /*------------------------LCD TECON-----------------------------*/
   #define REG_LCD_CALC_HTT           *((volatile unsigned int *)   (LCD_CALC_HTT_REG))
   #define REG_LCD_SYNC_LCM_SIZE      *((volatile unsigned int *)   (LCD_SYNC_LCM_SIZE_REG))
   #define REG_LCD_SYNC_COUNT         *((volatile unsigned int *)   (LCD_SYNC_CNT_REG))
   #define REG_LCD_TECON              *((volatile unsigned int *)   (LCD_TECON_REG))


   ///TE control
   #define LCD_TE_ENABLE_BIT          0x1
   #define LCD_TE_SYNCEDGE_BIT        0x2
   ///macros
   #define ENABLE_LCD_TE_DETECT()     REG_LCD_TECON |= LCD_TE_ENABLE_BIT;
   #define DISABLE_LCD_TE_DETECT()    REG_LCD_TECON &= ~LCD_TE_ENABLE_BIT;
   #define SET_TE_RISING_DETECT()     REG_LCD_TECON &= ~LCD_TE_SYNCEDGE_BIT;
   #define SET_TE_FALLING_DETECT()    REG_LCD_TECON |= LCD_TE_SYNCEDGE_BIT;

   //Not support VHSync
   #define TE_VH_SYNC_MODE_OFFSET
   #define TE_VH_SYNC_MODE_BIT

   #define TE_SCANLINE_MODE_OFFSET    2
   #define TE_SCANLINE_MODE_BIT       (1 << TE_SCANLINE_MODE_OFFSET)


   #define TE_WAITLINE_MASK           0xFFF
   #define TE_WAITLINE_OFFSET         0
   #define TE_HTT_MASK                0x3FF
   #define TE_HTT_OFFSET              0
   #define TE_VTT_MASK                0xFFF0000
   #define TE_VTT_OFFSET              16

   #define TE_HS_CNT_MASK             TE_WAITLINE_MASK
   #define TE_HS_CNT_OFFSET           TE_WAITLINE_OFFSET
   #define TE_HSYNC_WIDTH_MASK        TE_HTT_MASK
   #define TE_HSYNC_WIDTH_OFFSET      TE_HTT_OFFSET
   #define TE_HSYNC_HEIGHT_MASK       TE_VTT_MASK
   #define TE_HSYNC_HEIGHT_OFFSET     TE_VTT_OFFSET


   #define SET_TE_HS_CNT(n)           REG_LCD_SYNC_COUNT &= ~TE_HS_CNT_MASK;\
                                      REG_LCD_SYNC_COUNT |= ((n & TE_HS_CNT_MASK) << TE_HS_CNT_OFFSET)
   #define GET_TE_HS_CNT              ((REG_LCD_SYNC_COUNT & TE_HS_CNT_MASK) >> TE_HS_CNT_OFFSET)

   #define SET_TE_DIV(n)


   //Not support
   #define SET_TE_VH_SYNC_MODE
   #define SET_TE_DELAYTIME_SYNC_MODE REG_LCD_TECON &= ~(TE_SCANLINE_MODE_BIT)
   #define SET_TE_VS_WIDTH_LIMIT(n)

   //DelayTimeMode
   #define SET_TE_HS_WIDTH(n)         REG_LCD_SYNC_LCM_SIZE &= ~TE_HSYNC_WIDTH_MASK;\
                                      REG_LCD_SYNC_LCM_SIZE |= ((n & TE_HSYNC_WIDTH_MASK) << TE_HSYNC_WIDTH_OFFSET)
   #define SET_TE_DELAYTIME_MODE_HSYNC_WIDTH(n)  SET_TE_HS_WIDTH(n)

   #define SET_TE_SCANLINE_MODE              REG_LCD_TECON |= (TE_SCANLINE_MODE_BIT)
   #define SET_TE_SCANLINE_MODE_VTT(n)       REG_LCD_SYNC_LCM_SIZE &= ~TE_VTT_MASK;\
                                             REG_LCD_SYNC_LCM_SIZE |= ((n & TE_VTT_MASK) << TE_VTT_OFFSET)
   #define SET_TE_SCANLINE_MODE_HTT(n)       SET_TE_HS_WIDTH(n)

   #define GET_TE_CTRL_REG_VAL(val)          (val) = REG_LCD_TECON
   #define SET_TE_CTRL_REG_VAL(val)          REG_LCD_TECON = (val)

   #define GET_TE_CALC_HTT_REG_VAL(val)      (val) = REG_LCD_CALC_HTT
   #define SET_TE_CALC_HTT_REG_VAL(val)      REG_LCD_CALC_HTT = (val)

   #define GET_TE_SYNC_COUNTER_REG_VAL(val)  (val) = REG_LCD_SYNC_COUNT
   #define SET_TE_SYNC_COUNTER_REG_VAL(val)  REG_LCD_SYNC_COUNT = (val)

   #define GET_TE_SYNC_LCM_SIZE_REG_VAL(val)  (val) = REG_LCD_SYNC_LCM_SIZE
   #define SET_TE_SYNC_LCM_SIZE_REG_VAL(val)   REG_LCD_SYNC_LCM_SIZE = (val)	

   #define WFD_START_LCD_TRANSFER     REG_LCD_START = 0;\
                                      REG_LCD_START = LCD_START_START_BIT;
	
   #define DBI_ULTRA_EN_BIT     0x1
   #define GMC_ULTRA_EN_BIT     0x2
   #define CONSUME_PIXELS_MASK  0x3FF 
   #define CONSUME_PIXELS_BIT   0

   #define DBI_TH_HIGHT_MASK    0xFFFF0000
   #define DBI_TH_LOW_MASK      0xFFFF
   #define DBI_TH_HIGHT_OFFSET  16
   #define DBI_TH_LOW_OFFSET    0
   #define GMC_TH_HIGHT_MASK    0xFFFF0000
   #define GMC_TH_LOW_MASK      0xFFFF
   #define GMC_TH_HIGHT_OFFSET  16
   #define GMC_TH_LOW_OFFSET    0

   #define ENABLE_DBI_ULTRA_HIGH() REG_LCD_ULTRA_CON |= DBI_ULTRA_EN_BIT
   #define ENABLE_GMC_ULTRA_HIGH() REG_LCD_ULTRA_CON |= GMC_ULTRA_EN_BIT
   #define SET_LCD_CONSUME_RATE(n) REG_LCD_CONSUME_RATE = n
   #define SET_LCD_DBI_ULTRA_HIGH_THRESHOLD(low, high) REG_LCD_DBI_ULTRA_TH = ((high & 0xFFFF) << DBI_TH_HIGHT_OFFSET) | (low & 0xFFFF)
   #define SET_LCD_GMC_ULTRA_HIGH_THRESHOLD(low, high) REG_LCD_GMC_ULTRA_TH = ((high & 0xFFFF) << DBI_TH_HIGHT_OFFSET) | (low & 0xFFFF)

   #define RESET_TE_SYNC_CONTROL_REG()  REG_LCD_TECON = 0

/*!
 *  Set LCD Layer MEM Pitch value.
 *
 *  \param layer_order      LCD layer order (ie: ID)
 *  \param stride           Source image's stride
 *  \param bpp              Source image's byte per pixel
 *
 *  \remark                 For those chips not supported layer pitch,
 *                          please let this macro as null.
 *
 */
#define SET_LCD_LAYER_MEM_PITCH(layer_order, stride, bpp)\
       {\
          REG_LCD_LAYER_MEM_PITCH((layer_order)) = (stride);\
       }
#define SET_LCD_ROI_CTRL_PERIOD(n)   
#define SET_LCD_CTRL_INTERNAL_RESET  REG_LCD_START = 0;\
                                     REG_LCD_START = LCD_IF_RESET_BIT;\
                                     REG_LCD_START = 0;



#else
   #error not support chip
#endif

#endif //__LCD_IF_6260_SERIES_HW_H__


