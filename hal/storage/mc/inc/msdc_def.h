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
 *   Msdc_def.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Header file of MSDC driver
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================ 
 ****************************************************************************/
#ifndef MSDC_DEF_H
#define MSDC_DEF_H

//RHR ADD
#include "kal_general_types.h"
#include "kal_public_defs.h"
//RHR REMOVE
/*
#include "kal_release.h"
#include "kal_non_specific_general_types.h"
*/
//RHR
#include "stack_config.h"
#include "drv_features.h"
#include "drvpdn.h"
#include "dma_sw.h"
#include "dma_hw.h"
#include "msdc_api.h"
#include "msdc_reg_adap.h"
#include "reg_base.h"
#include "dcl.h"

#define MSDC_DRV_TRC_FILE_MSDC			0
#define MSDC_DRV_TRC_FILE_SD			1
#define MSDC_DRV_TRC_FILE_SD_DRV		2
#define MSDC_DRV_TRC_FILE_MS			3
#define MSDC_DRV_TRC_FILE_MS_DRV		4
#define MSDC_DRV_TRC_FILE_MSP			5
#define MSDC_DRV_TRC_FILE_MSP_DRV		6

#ifdef	MSDC_CACHED_SUPPORT
#define	MSDC_UNCACHED_BUF_SIZE	4096
#define	MSDC_UNCACHED_TRASNFER_SIZE	(MSDC_UNCACHED_BUF_SIZE/4)
extern	kal_uint32	msdc_uncachedBuf[];
#endif

#if !defined(__FUE__) && !defined(__UBL__) && defined(MSDC_TRACE_LEVEL2)
//#include "SST_sla.h"
#define MSDC_SLA_Start_Logging(x) SLA_CustomLogging(x, SA_start)
#define MSDC_SLA_Stop_Logging(x) SLA_CustomLogging(x, SA_stop)
#else
#define MSDC_SLA_Start_Logging(x)
#define MSDC_SLA_Stop_Logging(x)
#endif

//registers address definition
#ifndef MSDC_TEST_MSDC2_FROM_MSDC1_CODE
#define MSDC_ADRS		MSDC_base 
#else //since MSDC2 SDIO driver is not stable now, we replace the base register when DVT test
#define MSDC_ADRS		MSDC2_base 
#endif





//#define APB_ACCESS_CLK	0x80000400	
// common for SD/MMC and MS(memory stick)

#define MSDC_CFG		(MSDC_ADRS)
#define MSDC_STA		(MSDC_ADRS+0x04)
#define MSDC_INTR		(MSDC_ADRS+0x08)

#define MSDC_DAT		(MSDC_ADRS+0x10)
#define MSDC_PS			(MSDC_ADRS+0x0c)

#define MSDC_IOCON		(MSDC_ADRS+0x14)
#define MSDC_IRQMASK0    (MSDC_ADRS+0x4c)
#ifdef DRV_MSDC_CHECK_MULTIBLOCK_WRITE_FINISHED
#define MSDC_DEBUG_SELECTION (MSDC_ADRS+0x90)
#define MSDC_DEBUG_REG 		 (MSDC_ADRS+0x94)
#endif


#if defined(DRV_MSDC_MT6238_SERIES)
#define MSDC_ADRS2 	MSDC2_base

#define MSDC_CFG2		(MSDC_ADRS2)
#define MSDC_STA2		(MSDC_ADRS2+0x04)
#define MSDC_INTR2		(MSDC_ADRS2+0x08)
#define MSDC_DAT2		(MSDC_ADRS2+0x0c)
#define MSDC_PS2		(MSDC_ADRS2+0x10)
#define MSDC_IOCON2		(MSDC_ADRS2+0x14)
#endif

#define MSDC_IOCON1		(MSDC_ADRS+0x18)




#define MSDC_CLKACB_CFG		(MSDC_ADRS+0x80)
#define MSDC_CLKACB_STA		(MSDC_ADRS+0x84)
#define MSDC_CLKACB_CRCSTA1	(MSDC_ADRS+0x88)
#define MSDC_CLKACB_CRCSTA2	(MSDC_ADRS+0x8C)


#ifndef __DMA_API_V2__
// macros
#define IS_MSDC_DMA_RUN(a) 	MSDC_Reg32(DMA_GLBSTA) & (kal_uint32)DMA_GLBSTA_RUN(a)
#else
#define IS_MSDC_DMA_RUN(a)	DMA_CheckRunStat(a)
#endif

// masks for MSDC_CFG
#define MSDC_CFG_MSDC		((kal_uint32)0x00000001)
#if defined(DRV_MSDC_CLK_MT6260_SERIES)
#define MSDC_CFG_CLKSRC_PAT ((kal_uint32)0x00800000)
#endif

#define MSDC_CFG_RST		((kal_uint32)0x00000002)
#define MSDC_CFG_NOCRC		((kal_uint32)0x00000004)
#define MSDC_CFG_CLKSRC		((kal_uint32)0x00000018)

#define MSDC_CFG_STDBY		((kal_uint32)0x00000020)
#define MSDC_CFG_CRED		((kal_uint32)0x00000040)
#define MSDC_CFG_SCKON		((kal_uint32)0x00000080)
#define MSDC_CFG_SCLKF		((kal_uint32)0x0000ff00)
#define MSDC_CFG_INTEN		((kal_uint32)0x00010000)
#define MSDC_CFG_DRQEN		((kal_uint32)0x00020000)
#define MSDC_CFG_PINEN		((kal_uint32)0x00040000)
#define MSDC_CFG_DIRQE		((kal_uint32)0x00080000)
#define MSDC_CFG_RCDEN		((kal_uint32)0x00100000)
#define MSDC_CFG_VDDPD		((kal_uint32)0x00200000)

#if defined(DRV_MSDC_FIFO_COUNT_4_BITS)
#define MSDC_CFG_FIFOTHD	((kal_uint32)0xF000000)
#else
#define MSDC_CFG_FIFOTHD	((kal_uint32)0x1F000000)
#endif

// masks for MSDC_STA
#define MSDC_STA_BF			0x0001
#define MSDC_STA_BE			0x0002
#define MSDC_STA_DRQ    	0x0004
#define MSDC_STA_INT		0x0008

#if defined(DRV_MSDC_FIFO_COUNT_4_BITS)
#define MSDC_STA_FIFOCNT	0x00F0
#else
#define MSDC_STA_FIFOCNT	0x01F0
#endif

#define MSDC_STA_FIFOCLR	0x4000
#define MSDC_STA_BUSY		0x8000

#define MSDC_INT_DIRQ		0x0001
#define MSDC_INT_PINIRQ		0x0002
#define MSDC_INT_SDCMDIRQ	0x0004
#define MSDC_INT_SDDATIRQ	0x0008
#define MSDC_INT_SDMCIRQ	0x0010
#define MSDC_INT_MSIFIRQ	0x0020
#define MSDC_INT_SDR1BIRQ	0x0040

// SDIO
#define MSDC_INT_SDIOIRQ	0x0080

// masks for MSDC_PS
#define MSDC_PS_CDEN		0x0001
#define MSDC_PS_PIEN0		0x0002
#define MSDC_PS_POEN0		0x0004
#define MSDC_PS_PIN0		0x0008
#define MSDC_PS_PINCH		0x0010
//#if defined(MT6228)||defined(MT6229) || defined(MT6227)|| defined(MT6226)|| defined(MT6226M)
#define MSDC_PS_DEBOUNCE	0xf000
#define MSDC_PS_DAT			0xff0000
#define MSDC_PS_CMD			0x1000000
//#endif

#define MSDC_IOCON_ODCCFG0		0x0007	// driving capacity of CMD/BS and SCLK
#define MSDC_IOCON_ODCCFG1		0x0038	// driving capacity of data lines
#define MSDC_IOCON_SCRCFG0		0x0040	// slew rate of the CMD/BS and SCLK
#define MSDC_IOCON_SCRCFG1		0x0080	// slew rate of the data lines
#define MSDC_IOCON_DMABURST		0x0300	// select burst type when data transfer by DMA
#define MSDC_IOCON_CMDRE		0x8000	// 0: latch the command at rising edge, 1: at falling edge
#define MSDC_IOCON_DSW			0x00010000
#define MSDC_IOCON_INTLH		0x00060000
#define MSDC_IOCON_CMDSEL		0x00080000
#define MSDC_IOCON_CRCDIS		0x00100000
#define MSDC_IOCON_SAMPON		0x00200000
#define MSDC_IOCON_FIXDLY		0x00C00000
#define MSDC_IOCON_SAMPLEDLY	0x03000000

#define MSDC_IOCON1_PRVAL_INS		0x00000003
#define MSDC_IOCON1_PRCFG_INS		0x00000004
#define MSDC_IOCON1_PRVAL_DA		0x00000030
#define MSDC_IOCON1_PRCFG_DA		0x00000040
#define MSDC_IOCON1_PRVAL_CM		0x00000300
#define MSDC_IOCON1_PRCFG_CM		0x00000400
#define MSDC_IOCON1_PRVAL_CK		0x00003000
#define MSDC_IOCON1_PRCFG_CK		0x00004000
#define MSDC_IOCON1_PRVAL_RST_WP	0x00030000
#define MSDC_IOCON1_PRCFG_RST_WP	0x00040000
#define MSDC_IOCON1_ALL_PULLUP_47K	0x00022222

#define MSDC_CLKACB_CFG_ACB_MODE		0x80000000
#define MSDC_CLKACB_CFG_CMD_PHASE_RED	0x20000000
#define MSDC_CLKACB_CFG_CMD_PHASE		0x1F000000
#define MSDC_CLKACB_CFG_TUN_BLOCK_NUM	0x00FF0000
#define MSDC_CLKACB_CFG_DAT_PHASE_RED	0x00002000
#define MSDC_CLKACB_CFG_DAT_PHASE		0x00001F00
#define MSDC_CLKACB_CFG_CLKPAD_RED		0x00000080
#define MSDC_CLKACB_CFG_CLK_LATCH		0x00000040
#define MSDC_CLKACB_CFG_SAMPLE_PERIOD	0x00000030
#define MSDC_CLKACB_CFG_SCANMODE		0x00000008
#define MSDC_CLKACB_CFG_FINE_EN			0x00000006
#define MSDC_CLKACB_CFG_COARSE_EN		0x00000002
#define MSDC_CLKACB_CFG_CLKTUN_ON		0x00000001

#define MSDC_CLKACB_STA_DET_CLK_PHASE	0x00000F00
#define MSDC_CLKACB_STA_ACB_TO			0x00000010
#define MSDC_CLKACB_STA_FINE_DONE		0x00000008
#define MSDC_CLKACB_STA_COARSE_DONE		0x00000004
#define MSDC_CLKACB_STA_DET_DONE		0x00000002
#define MSDC_CLKACB_STA_CLKTUN_DONE		0x00000001

#define MSDC_CLKACB_CRC_STA_ENABLE		0xFFFF0000
#define MSDC_CLKACB_CRC_STA_CRC			0x0000FFFF

#if defined(DRV_MSDC_CLK_MT6260_SERIES)||defined(DRV_MSDC_CLKSRC_MT6261_SERIES)

#define RG_MSDC1_26M_SEL 0x1
#define RG_MSDC2_26M_SEL 0x10
#define RG_POWERFULL_DIV_EN1 0x400
#define RG_POWERFULL_DIV_EN2 0x200
#endif
#if defined(DRV_MSDC_CLKSRC_MT6261_SERIES)
#define BT_APP_DIV_EN 0x8000
#define POWERFUL_DIV_EN1 0x400
#endif

#if defined(DRV_MSDC_DRIVING_6255_SERIES)
#define MSDC_ODC_4MA		0x0
#define MSDC_ODC_8MA		0x1
#define MSDC_ODC_12MA		0x2
#define MSDC_ODC_16MA		0x3
//#elif defined(DRV_MSDC_DRIVING_6260_SERIES)
//#define MSDC_ODC_4MA		0x0
//#define MSDC_ODC_8MA		0x1
//#define MSDC_ODC_12MA		0x2
//#define MSDC_ODC_16MA		0x3
#else
#define MSDC_ODC_4MA		0x0
#define MSDC_ODC_8MA		0x2
#define MSDC_ODC_12MA		0x4
#define MSDC_ODC_16MA		0x6
#endif
/*MSDC first CLK*/
#if defined(DRV_MSDC_CLK_MT6276_SERIES)
#define MSDC_CLOCK		98300	// (kHz)
#define MSDC_OP_CLOCK	15300
#define MSDC_30M		30700
#elif defined(DRV_MSDC_CLK_MT6256_SERIES)
#define MSDC_CLOCK		94500	// (kHz)
#define MSDC_OP_CLOCK	15300
#define MSDC_30M		32500
#elif defined(DRV_MSDC_CLK_MT6255_SERIES)
#define MSDC_CLOCK		104000	// (kHz)
#define MSDC_OP_CLOCK	13000
#define MSDC_30M		26000
#elif defined(DRV_MSDC_CLK_MT6260_SERIES)
#define MSDC_CLOCK		97000	// (kHz)
#define MSDC_OP_CLOCK	15300
#define MSDC_30M		30700
#endif


#define MSDC_ODC_SLEW_FAST		0
#define MSDC_ODC_SLEW_SLOW		1


//#if defined(MT6228)||defined(MT6229) || defined(MT6227)|| defined(MT6226)|| defined(MT6226M)
#define MSDC_IOCTRL_INS_DISABLE			0
#define MSDC_IOCTRL_INS_PULL_DOWN		1
#define MSDC_IOCTRL_INS_PULL_UP			2
#define MSDC_IOCTRL_INS_KEEPER			3
//#endif
#define DRV_MSDC_IDLE_VMC_OFF
#if defined(DRV_MSDC_IDLE_VMC_OFF)&& defined(__MSDC_SD_MMC__)
#define Idle_VMC_OnOff(on)	MSDC_turnOnVMC(on)
#else
#define Idle_VMC_OnOff(on) do{}while(0)
#endif

// useful macros

#define MSDC_LSD_WriteReg(adrs,data)		MSDC_WriteReg(adrs, data)
#define MSDC_LSD_ReadReg(adrs,pdata)		*(kal_uint16*)(pdata) = MSDC_Reg(adrs)
#define MSDC_LSD_WriteReg32(adrs,data)		MSDC_WriteReg32(adrs, data)
#define MSDC_LSD_ReadReg32(adrs,pdata)		*(kal_uint32*)(pdata) = MSDC_Reg32(adrs)
#define MSDC_LSD_ClearBits(address, mask)	MSDC_ClearBits(address, mask)
#define MSDC_LSD_SetBits(address, mask)		MSDC_SetBits(address, mask)
#define MSDC_LSD_ClearBits32(address, mask)	MSDC_ClearBits32(address, mask)
#define MSDC_LSD_SetBits32(address, mask)	MSDC_SetBits32(address, mask)

#if defined(MT6250) ||defined(MT6260)||defined(DRV_MSDC_RST_MT6261_SERIES)
#define MSDC_CLR_FIFO()         Reset_MSDC()
#else
#define MSDC_CLR_FIFO()			MSDC_LSD_SetBits32(MSDC_STA,MSDC_STA_FIFOCLR)
#endif

#define MSDC_IS_FIFO_EMPTY		(MSDC_Reg32(MSDC_STA) & MSDC_STA_BE)
#define MSDC_IS_FIFO_FULL		(MSDC_Reg32(MSDC_STA) & MSDC_STA_BF)
#define MSDC_IS_BUSY			(MSDC_Reg32(MSDC_STA) & MSDC_STA_BUSY)

#define MSDC_SET_FIFO(x)	{MSDC_LSD_ClearBits32(MSDC_CFG,MSDC_CFG_FIFOTHD);\
									MSDC_SetBits32(MSDC_CFG, (x << 24));}


#define MSDC_CLR_INT()		MSDC_Reg32(MSDC_INTR)
#define SET_FIFO_THRESHOLD(n)	{\
					MSDC_SetData32(MSDC_CFG, MSDC_CFG_FIFOTHD, (n << 28));\
				}
#define MSDC_IS_INT				(MSDC_Reg32(MSDC_STA) & MSDC_STA_INT)

#define EnableMSDC_DMA()	MSDC_LSD_SetBits32(MSDC_CFG,MSDC_CFG_DRQEN)
#define DisableMSDC_DMA()	MSDC_LSD_ClearBits32(MSDC_CFG,MSDC_CFG_DRQEN)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#define MSDC_ENABLE_INT()		MSDC_LSD_SetBits32(MSDC_CFG,MSDC_CFG_INTEN)
#define MSDC_DISABLE_INT()		MSDC_LSD_ClearBits32(MSDC_CFG,MSDC_CFG_INTEN)
#define MSDC_ENABLE_CARD_DETECTION()	MSDC_LSD_SetBits32(MSDC_PS, MSDC_PS_CDEN)
#define MSDC_DISABLE_CARD_DETECTION()	MSDC_LSD_ClearBits32(MSDC_PS, MSDC_PS_CDEN)	

#if defined(DRV_MSDC_MT6238_SERIES)
#define MSDC_CLR_FIFO2()			MSDC_LSD_SetBits32(MSDC_STA2,MSDC_STA_FIFOCLR)
#define MSDC_IS_FIFO_EMPTY2		(MSDC_Reg32(MSDC_STA2) & MSDC_STA_BE)
#define MSDC_IS_FIFO_FULL2		(MSDC_Reg32(MSDC_STA2) & MSDC_STA_BF)
#define MSDC_IS_BUSY2			(MSDC_Reg32(MSDC_STA2) & MSDC_STA_BUSY)
#define MSDC_SET_FIFO2(x)	{\
					MSDC_SetData32(MSDC_CFG2, MSDC_CFG_FIFOTHD, (x << 28));\
				}
#define TurnOnMSDC2()	(MSDC_WriteReg32(DRVPDN_CON0_CLR, DRVPDN_CON0_MSDC2))
#define TurnOffMSDC2()	(MSDC_WriteReg32(DRVPDN_CON0_SET, DRVPDN_CON0_MSDC2))
#define MSDC_CLR_INT2()		{\
					kal_uint32 tmp;\
					tmp = MSDC_Reg32(MSDC_INTR2);\
				}
#define SET_FIFO_THRESHOLD2(n)	{\
					MSDC_SetData32(MSDC_CFG2, MSDC_CFG_FIFOTHD, (n << 28));\
				}
#define MSDC_IS_INT2		(MSDC_Reg32(MSDC_STA2) & MSDC_STA_INT)
#define EnableMSDC_DMA2()	MSDC_LSD_SetBits32(MSDC_CFG2,MSDC_CFG_DRQEN)
#define DisableMSDC_DMA2()	MSDC_LSD_ClearBits32(MSDC_CFG2,MSDC_CFG_DRQEN)
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#define MSDC_ENABLE_INT2()		MSDC_LSD_SetBits32(MSDC_CFG2,MSDC_CFG_INTEN)
#define MSDC_DISABLE_INT2()		MSDC_LSD_ClearBits32(MSDC_CFG2,MSDC_CFG_INTEN)
#define MSDC_ENABLE_CARD_DETECTION2()	MSDC_LSD_SetBits32(MSDC_PS2, MSDC_PS_CDEN)
#define MSDC_DISABLE_CARD_DETECTION2()	MSDC_LSD_ClearBits32(MSDC_PS2, MSDC_PS_CDEN)	

#endif // DRV_MSDC_MT6238_SERIES

// define event flags
#define EVENT_SDCMDIRQ		((kal_uint32)0x00000001)
#define EVENT_SDDATIRQ		((kal_uint32)0x00000002)
#define EVENT_SDMCIRQ		((kal_uint32)0x00000004)
#define EVENT_MSIFIRQ		((kal_uint32)0x00000008)
#define EVENT_SDR1BIRQ		((kal_uint32)0x00000010)
#define EVENT_PINIRQ		((kal_uint32)0x00000020)
#define EVENT_MSRDYIRQ		((kal_uint32)0x00000040)
#define EVENT_DMAIRQ		((kal_uint32)0x00000100)
#define EVENT_INVALID_IRQ	((kal_uint32)0x80000000)
#define EVENT_ALLIRQ (EVENT_SDCMDIRQ|EVENT_SDDATIRQ|EVENT_SDMCIRQ|EVENT_MSIFIRQ|EVENT_SDR1BIRQ|EVENT_PINIRQ|EVENT_DMAIRQ)

#define MSDC_NOERROR						0
#define MSDC_ERR_CARD_DETECT			101
#define MSDC_CARD_NOT_PRESENT			102
#define MSDC_DMA_FAIL					104
#define MSDC_GPT_TIMEOUT_ERR			199

#define MSDC_TIMEOUT_PERIOD_INI		1100	// x1ms
#define MSDC_TIMEOUT_PERIOD_DAT		150		// x10ms
#define MSDC_TIMEOUT_PERIOD_CMD		50		// x10ms
#define MSDC_TIMEOUT_PERIOD_ACB		500		// x10ms
#define MSDC_TIMEOUT_PERIOD_DAT0_LOW        40  //  x10ms (at least 250ms)
#define MSDC_TIMEOUT_PERIOD_CARD_NOT_RDY    200 //  x10ms
#define MSDC_INI_CLOCK					240	// kHz
#define MSDC_WRITE_THD_POLL			2*128		// 1K bytes
#define MSDC_READ_THD_POLL				8*128		// 4k bytes




/*MSDC DBG print definitions*/
#define MSDC_DBG_ARRAY_SIZE	(1024)
#define MSDC_DBG_ARRAY_MASK	(MSDC_DBG_ARRAY_SIZE-1)



#ifdef __CUST_NEW__
//if __CUST_NEW__ is defined, following variables will be decalred and initialized by custom tool
extern const char gpio_simplug_ldo_switch;
extern const char gpio_sim_msdc_switch;
extern const char gpio_ext_sd_ldo_switch;
#else
//if __CUST_NEW__ is undefined, following variables will be declared in msdc.c and will be assigned value in msdc initialization
extern  kal_char gpio_simplug_ldo_switch;
extern  kal_char gpio_sim_msdc_switch;
extern  kal_char gpio_ext_sd_ldo_switch;
#endif
#define GPIO_LDO_SWITCH 				gpio_simplug_ldo_switch
#define GPIO_EXT_SD_LDO_SWITCH		gpio_ext_sd_ldo_switch
#define GPIO_SIM_MSDC_SWITCH 			gpio_sim_msdc_switch
#define GPIO_SELECT_MSDC				0
#define GPIO_SELECT_SIM					1
#define ENTER_CRITICAL()		{\
													kal_uint32 _savedMask;\
													_savedMask = SaveAndSetIRQMask();

#define EXIT_CRITICAL()			RestoreIRQMask(_savedMask);}



#if defined(__UBL__) || defined(__FUE__)
#include "msdc_fake_kal.h"
#define kal_set_eg_events(...) do { } while (0);
#define kal_retrieve_eg_events(...) do { } while (0);
#define kal_debug_print dbg_print
#define kal_query_systemInit() (KAL_FALSE)
#define INT_QueryExceptionStatus(...) (KAL_FALSE)
#define kal_sleep_task(x)	{\
							kal_uint32 i = x;\
							while(i--);\
						}
#define kal_prompt_trace(...) do { } while (0);
#define drv_trace1(...) do { } while (0);
#define drv_trace2(...) do { } while (0);
#define drv_trace4(...) do { } while (0);
#define drv_trace8(...) do { } while (0);


#ifdef R1B_INTERRUPT_MODE
#undef R1B_INTERRUPT_MODE
#endif
#ifdef __DRV_MSDC_FAST_FORMAT__
#undef __DRV_MSDC_FAST_FORMAT__
#endif

#ifdef __MULTI_BOOT__
#undef __MULTI_BOOT__
#endif
#else//defined(__UBL__) || defined(__FUE__)
extern kal_bool INT_QueryExceptionStatus(void);
#endif//defined(__UBL__) || defined(__FUE__)



// enum
typedef enum {
	POLLING,
	INTERRUPT,
	DMA
}T_RESP_TYPE;

typedef enum{
	FREQ_1BY2 = 0,		// f = 1/2 * 52M
	FREQ_1BY4 = 1,
	FREQ_1BY8 = 2,
	FREQ_1BY16 = 3
}SerClock_enum;

typedef enum {
	MSDC_CLOCK_MCU,
	MSDC_CLOCK_MCPLL
}T_MSDC_CLK_TYPE;

typedef enum{
 MSDC_IOCTRL_DISABLE		= 0,
 MSDC_IOCTRL_PULL_DOWN	= 1,
 MSDC_IOCTRL_PULL_UP		= 2,
 MSDC_IOCTRL_KEEPER		= 3
}msdc_ioctrl_enum;

#if defined(DRV_MSDC_MT6238_SERIES)
typedef enum{
	SD_EXT = 0,
	SD_MSDC1 = 0,
	SD_MSDC2 = 1,		
	SD_NUM = 2
}sd_select_enum;
#elif defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
typedef enum{
	SD_EXT = 0,
	SD_MSDC1 = 0,
	SD_T_CARD_2 =1,
	SD_NUM = 2
}sd_select_enum;
#else
typedef enum{
	SD_EXT = 0,
	SD_MSDC1 = 0,
#ifdef DRV_MSDC_SD_SDIO_SHARE_BY_SWITCH
	SD_SDIO = 1,
#endif
	SD_NUM
}sd_select_enum;
#endif

typedef enum {
	MCDEV_SD0 = 0,
	MCDEV_SD1 = 1,
	MCDEV_NUM = 2
} mcdev_enum;


#define MSDC_SCLKF_NUM	4
#define MSDC_CLKSRC_NUM	4
#define DIV_CLKSRC(x)	(x + 5)
#define DIV_SCLKF(x)	(x==0 ? 2 : (4*x))

typedef struct _msdc_clk_setting {
	kal_uint32 clksrc;
	kal_uint32 sclkf;
	kal_uint32 cardClk;
} msdc_clk_setting;

typedef enum {
	MSDC_AM_CMD,
	MSDC_AM_DAT,
	MSDC_AM_RESERVED
} msdc_acb_mode;
typedef enum {
	MSDC_ATS_DETECT,
	MSDC_ATS_COARSE,
	MSDC_ATS_FINE,
	MSDC_ATS_RESERVED
} msdc_acb_tun_scheme;
typedef enum {
	MSDC_ASM_DET,
	MSDC_ASM_FULL,
	MSDC_ASM_RESERVED
} msdc_acb_scan_mode;
typedef enum {
	MSDC_CLKSRC_DIV_5,
	MSDC_CLKSRC_DIV_6,
	MSDC_CLKSRC_DIV_7,
	MSDC_CLKSRC_DIV_8,
	MSDC_CLKSRC_RESERVED
} msdc_clksrc;
typedef enum {
	MSDC_DIRECT_NONE,
	MSDC_DIRECT_RIGHT,
	MSDC_DIRECT_LEFT
} msdc_direction;

extern kal_uint32 gMsdcClksrcRate[MSDC_CLKSRC_NUM];

typedef struct _tuning_topology {
	kal_uint32 (*HighSpeed)(msdc_clk_setting cs);
	kal_uint32 (*NormalSpeed1)(msdc_clk_setting cs);
	kal_uint32 (*NormalSpeed2)(msdc_clk_setting cs);
} tuning_topology;




typedef enum
{
	msdc_dbg_event_DMA_done,
	msdc_dbg_event_DMA_RLCT_Monitor,
	msdc_dbg_event_DMA_timeout,
	msdc_dbg_event_SD_CMD_issue,
	msdc_dbg_event_SD_CMD_issue2,
	msdc_dbg_event_SD_transfer_event_retreived1,
	msdc_dbg_event_SD_transfer_event_retreived2,
	msdc_dbg_event_SD_transfer_event_retreiving1,
	msdc_dbg_event_SD_transfer_event_retreiving2,
	msdc_dbg_event_SD_transfer_DMA_timeout_monitor,
	msdc_dbg_event_SD_transfer_timeout_assert,
	msdc_dbg_event_SD_transfer_poll_end1,
	msdc_dbg_event_SD_transfer_poll_end2,
	msdc_dbg_event_SD_cached_copy_start,
	msdc_dbg_event_SD_cached_copy_end,
	msdc_dbg_event_SD_datTimeOut_sta,
	msdc_dbg_event_GPT_timeout,
	msdc_dbg_event_SD_read_fail_systemInit,
	msdc_dbg_event_SD_clk_tuning,
	msdc_dbg_event_SD_datsta_systemInit,
	msdc_dbg_event_SD_multi_blk_write_issue1,
	msdc_dbg_event_SD_multi_blk_write_issue2
} msdc_dbg_Event;

/*move up here since it will be included in MSDC_HANDLE*/
typedef struct
{
	kal_uint32 (*Init)(void);
	kal_bool (*IsCardInd)(void);
	void (*PowerCtrl)(kal_bool on);
} MSDC_Custom_Handle;

typedef struct 
{
	kal_uint32				msdc_clock;     // clock rate of MSDC	
	kal_uint32				op_clock;       // clock rate of the serial clock output to card
	kal_uint32 				total_count;    // separate transfer count larger than 16 bits into various parts.	
	kal_uint32 				timeout_period; // x 10ms

	DMA_INPUT  				msdc_input;
	#if !defined(MT6250)
	DMA_HWMENU 				msdc_menu;
	#else
	DMA_FULLSIZE_HWMENU 	full_menu;
    DMA_HWMENU 				msdc_menu;
	#endif
	kal_bool 				isDMA_B2W	;
	volatile T_MSDC_CARD	mMSDC_type;     // indicate the type of card(SD, MMC, MS)
	volatile kal_bool		mIsPresent;     // card is present or not
	volatile kal_bool		mIsInitialized; // card is initialized or not
	volatile kal_bool		mIsChanged;     // card is changed or not
	volatile kal_bool 		is_timeout;     // flag to indicate whther the gpt is expired		
	kal_bool				mIsPWDown;      // is MSDC is power down
	DCL_HANDLE 				gpt_handle;     // handler of gpt timer 		
	kal_uint8	 			cmd_sta;        // store the status of the latest CMD transaction
	kal_uint8				dat_sta;        // store the status of the latest DAT transaction
	msdc_ioctrl_enum		ins_level;      // indicate the INS pin pull status;
	kal_uint8 				timeout_count;  // retry of card mounting during read or write
	kal_bool				is_poll;        // is busy-waiting or event-triggered for data trasaction
	kal_bool				is_aligned;     // is transfer by 4-byte alignment
	kal_bool				is_init_timeout;    // the initialization process larger than 1 sec
	kal_bool				send_ilm;       // 1: means to send ilm to fmt task
	kal_uint8 				msdc_dmaport;   // DMA setting
	kal_eventgrpid          MSDC_Events;    // events used for memory car
	kal_uint8 				dataCrcError_count; // we count the times to happen data CRC error
	kal_bool				trySingleLine;  //we use this flag to mrak that we want to rey single line on this card
#ifdef MSDC_CACHED_SUPPORT
	kal_bool				isCachedBuf;
	kal_uint32				cachedBufCopyPtr;
#endif

	
#ifdef DRV_MSDC_SHARE_BY_SWITCH
	kal_uint32				setting_MSDC_CFG;
	kal_uint32				setting_MSDC_IOCON;
	kal_uint32				setting_SDC_CFG;
#endif

	tuning_topology			tuningTopology;

	kal_bool MSDC_everPlugOut;//this is only be set true in plug out hisr, set false in MSDC_getStatus


	MSDC_Custom_Handle msdc_custom_handle;

#ifdef __DRV_MSDC_FAST_FORMAT__
	kal_bool	MSDC_fastFormat ;
#endif
	kal_uint32 msdcTimeoutDuration;


#ifdef	DRV_MSDC_CLK_SEARCH
	kal_uint32	msdc_clkTuneUpperBund;
#endif

#if defined(MSDC_START_DMA_IN_CALLBACK)
    kal_uint32 *msdc_uncachedBufs[2];
    kal_uint32  msdc_uncachedBufs_idx;
    kal_uint32  msdc_input_next;
#endif
    volatile kal_bool			mIsInitMSDC; // MSDC is initialized or not
    kal_uint16 msdc_int;
#if defined(MSDC_TRACE_LEVEL2) && defined(R1B_INTERRUPT_MODE)
    kal_uint32 LISR_Entry_Count;
    kal_uint32 SDCMDIRQ_Entry_Count;
    kal_uint32 SDMCIRQ_Entry_Count;
    kal_uint32 SDDATIRQ_Entry_Count;
    kal_uint32 SDR1bIRQ_Entry_count;
    kal_uint32 SDIOIRQ_Entry_Count;
    kal_uint32 SDPINIRQ_Entry_Count;
#endif     

}MSDC_HANDLE, *pMSDC_HANDLE; 

typedef struct
{
	T_MSDC_CARD type; // indicate the type of card(SD, MMC, MS)
	kal_bool	present; // card is present or not
}msdc_card_ind_strcut;

typedef struct
{
	kal_uint8 cmd_clk_odc;
	kal_uint8 dat_odc;
	kal_uint8 cmd_clk_slew;
	kal_uint8 dat_slew;
}msdc_io_ctrl_struct;

typedef enum
{
	MSDC_HOT_PLUG = 		0x1,	// MSDC support hot plugging
	MSDC2_HOT_PLUG = 		0x2,	// MSDC2 support hot plugging
	MSDC_WP = 				0x4,	//  MSDC support write protecton detection
	MSDC2_WP = 				0x8,	// MSDC2 support write protection detection
	MSDC_SD4_SDIO1 =		0x10,	// SD/MMC use MSDC1(4-bits) and SDIO use MSDC2(1-bits)
	MSDC_SDIO4_SD1	= 		0x20	// vice versa
	//MSDC_SDIO4_SDIO1,  // not support now
}msdc_custom_enum;

typedef struct
{
	msdc_dbg_Event event;
	kal_uint32 time;
	kal_uint32 data32_0;
	kal_uint32 data32_1;
} msdc_debugMessage;


typedef struct _msdc_lock_tag {
   kal_uint8 name[20];
   kal_uint32  lock_count;
   kal_taskid  owner_id;
   kal_mutexid mtd_mutex;
} MSDC_LOCK_TAG, *PMSDC_LOCK_TAG;

extern MSDC_HANDLE MSDC_Blk[SD_NUM];
extern MSDC_HANDLE *gMSDC_Handle;
extern kal_uint32 MSDC_Sector[128];
extern sd_select_enum current_card;


#define EXT_MEM_ID			(kal_uint32)(&MSDC_Blk[SD_EXT])
#define SIMPLUS_MEM_ID		(kal_uint32)(&MSDC_Blk[SD_SIM])
#define TCARD_2_MEM_ID		(kal_uint32)(&MSDC_Blk[SD_T_CARD_2])

#define MSDC_START_TIMER2(x) \
		msdc2_handle->is_timeout = KAL_FALSE;\
		MSDC_GPTI_StartItem(msdc2_handle->gpt_handle,\
                  x,\
                  MSDC_TimeOutHandler2,\
                  NULL)

#define MSDC_STOP_TIMER2()			\
		if(!msdc2_handle->mIsPresent )\
			return MSDC_CARD_NOT_PRESENT;\
		if(!msdc2_handle->is_timeout)\
		{\
			MSDC_GPTI_StopItem(msdc2_handle->gpt_handle);\
		}\
		else\
		{\
			kal_set_eg_events(msdc2_handle->MSDC_Events, 0, KAL_AND);\
		}



#if defined(__UBL__) || defined(__FUE__) /*bootloader case*/
    #define force_ASSERT(expr, e1, e2, e3) {if(!(expr)) {dbg_print("force_ASSERT:%s line:%d e1:%d,e2:%d,e3:%d\n",__FILE__,__LINE__, e1, e2, e3);while(1);}}
#else
    #define force_ASSERT(expr, e1, e2, e3) {EXT_ASSERT(expr, e1, e2, e3);}
#endif

// extern functions
kal_bool MSDC_STOP_TIMER(void);
kal_bool MSDC_START_TIMER(kal_uint16 x);
void  MSDC_IOInit();
void MSDC_ClockInit();

void MSDC_Initialize(void);
void MSDC_DeInit(void);
kal_bool MSDC_CardDetect(void);
void MSDC_HostSelect(T_MSDC_CARD type);
void BitFieldWrite32(kal_uint32 * dest, kal_uint32 src, kal_uint32 mask);
void BitFieldRead32(kal_uint32 * dest, kal_uint32 src, kal_uint32 mask);
void GetBitFieldN(kal_uint8* dest, kal_uint8* src, kal_uint16 start_bit, kal_uint16 width);
void MSDC_LISR(void);
void MSDC_HISR_Entry(void);
void MSDC_DMA_LISR(void);
void MSDC_DMA_HISR_Entry(void);
void Reset_MSDC();
extern void MSDC_PDNControl(kal_bool ON);
extern kal_bool MSDC_GetMediaChanged(sd_select_enum sel);
extern void MSDC_SendCardInd(module_type dest_id,sd_select_enum sel, kal_uint32 msg_id);
extern int MSDC_GetCardStatus(void *slot_id, int AckType);
extern void MSDC_InvertN(kal_uint8 *dest, kal_uint8 *src, kal_uint8 len);
extern void MSDC_TimeOutHandler(void *parameter);
extern kal_bool MSDC_Check_Card_Present(void);
//ATA Start
extern kal_bool MSDC_Check_Card_Mount(void);
//ATA End
extern void MSDC_SetClock(kal_uint32 clock);
extern void MSDC_SetClockSource(T_MSDC_CLK_TYPE type);
extern void MSDC_DMATransferFirst(kal_uint32 adrs,kal_uint32 count, kal_bool isTx);
extern kal_uint32 MSDC_DMATransferFinal(void);
extern 	void MSDC_Switch_Card(sd_select_enum sel);
extern void MSDC_Config_INS_WP(msdc_ioctrl_enum ins, msdc_ioctrl_enum wp);
extern void MSDC_add_dbg_msg( msdc_dbg_Event event, kal_uint32 data1, kal_uint32 data2);
extern void MSDC_turnOnVMC(kal_bool turnOnLdo);
#if defined(__UBL__) || defined(__FUE__)
//#define MSDC_GPTI_BusyWait(...) do { } while (0);
#define MSDC_BusyWait_ms(...)	 
#define kal_sleep_task(x)	{\
							kal_uint32 i = x;\
							while(i--);\
						}
#define MSDC_GPTI_GetHandle(...) 
#else
#define MSDC_GPT_CB_MAGIC_NUM 0x02000000
void MSDC_BusyWait_ms(kal_uint16 len);
kal_uint8 MSDC_GPTI_GetHandle(DCL_HANDLE *handle);
kal_bool MSDC_GPTI_StartItem(kal_uint8 module,kal_uint16 tick,void (*gptimer_func)(void *),void *parameter);
void MSDC_GPTI_StopItem(kal_uint8 module);
#endif//defined(__UBL__) || defined(__FUE__)

//! EMB
void* GetMsdcHandle(kal_uint8 id);

#if !defined(__FUE__) && !defined(__UBL__)
void init_MSDC_lock(PMSDC_LOCK_TAG lock, const kal_char *str);
void get_MSDC_lock(PMSDC_LOCK_TAG lock);
void free_MSDC_lock(PMSDC_LOCK_TAG lock);
#else /* __FUE__, __UBL__ */
#define init_MSDC_lock(x, y)
#define get_MSDC_lock(x)
#define free_MSDC_lock(x)
#endif /* !defined(__FUE__) && !defined(__UBL__) */

#if defined(__MSDC2_SD_MMC__) || defined(__MSDC2_SD_SDIO__)
void MSDC_Initialize2(void);
void MSDC_LISR2(void);
void MSDC_HISR_Entry2(void);
extern void MSDC_PDNControl2(kal_bool ON);
//extern	kal_bool MSDC_GetMediaChanged2(sd_select_enum sel);
extern int MSDC_GetCardStatus2(void *slot_id, int AckType);
extern void MSDC_TimeOutHandler2(void *parameter);
extern kal_bool MSDC_Check_Card_Present2(void);
extern void MSDC_SetClock2(kal_uint32 clock);
extern void MSDC_DMATransferFirst2(kal_uint32 adrs,kal_uint32 count, kal_bool isTx);
extern kal_uint32 MSDC_DMATransferFinal2(void);
#endif // __MSDC2_SD_MMC__

#endif // end of MSDC_DEF_H


