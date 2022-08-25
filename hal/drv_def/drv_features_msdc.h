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
 *    drv_features_msdc.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for the msdc driver features
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __DRV_FEATURES_MSDC_H__
#define __DRV_FEATURES_MSDC_H__

/**************** MSDC ******************/
#include "drv_features_chip_select.h"

/***** Chip Options *****/
#if defined(DRV_MSDC_MT6250_SERIES)
    #define DRV_MSDC_FIFO_COUNT_4_BITS
    #define DRV_MSDC_CLK_MT6276_SERIES
    #define DRV_MSDC_CLK_SEARCH
    #define DRV_MSDC_FORCE_WAIT_FOR_PROG_R1B_MALFUNCTION // fix issue happened in PEGATRON
    #define DRV_MSDC_DRIVING_6255_SERIES
	#define DRV_MSDC_CHECK_MULTIBLOCK_WRITE_FINISHED
	#define DRV_MSDC_4_BYTE_BURST
#elif defined(DRV_MSDC_MT6255_SERIES)
    #define DRV_MSDC_CLK_MT6256_SERIES
    #define DRV_MSDC_CLK_SEARCH
    #define DRV_MSDC_MT6238_SERIES				/*second MSDC controller*/
    #define DRV_MSDC_FORCE_WAIT_FOR_PROG_R1B_MALFUNCTION // fix issue happened in PEGATRON
    #define DRV_MSDC_DRIVING_6255_SERIES
#elif defined(DRV_MSDC_MT6260_SERIES)
	#define DRV_MSDC_FIFO_COUNT_4_BITS
    #define DRV_MSDC_CLK_MT6276_SERIES
    #define DRV_MSDC_CLK_SEARCH
    #define DRV_MSDC_FORCE_WAIT_FOR_PROG_R1B_MALFUNCTION // fix issue happened in PEGATRON
		#define DRV_MSDC_CHECK_MULTIBLOCK_WRITE_FINISHED
    #define DRV_MSDC_DRIVING_6255_SERIES
	#define DRV_MSDC_CLK_MT6260_SERIES 
		#define DRV_MSDC_4_BYTE_BURST
#elif defined(DRV_MSDC_6261_SERIES)
	#define DRV_MSDC_FIFO_COUNT_4_BITS
    #define DRV_MSDC_CLK_MT6276_SERIES
    #define DRV_MSDC_CLK_SEARCH
    #define DRV_MSDC_FORCE_WAIT_FOR_PROG_R1B_MALFUNCTION // fix issue happened in PEGATRON
		#define DRV_MSDC_CHECK_MULTIBLOCK_WRITE_FINISHED
    #define DRV_MSDC_DRIVING_6255_SERIES
		//#define DRV_MSDC_CLK_PAT_6260_SERIES 
		#define DRV_MSDC_4_BYTE_BURST
		#define DRV_MSDC_CLKSRC_MT6261_SERIES
		#define DRV_MSDC_RST_MT6261_SERIES
		#define DRV_MSDC_GPIO_MT6261_SERIES
		#define DRV_MSDC_DBG_MT6261_SERIES
		#define __MSDC_CD_EINT__
#elif defined(DRV_MSDC_2501_SERIES)
	#define DRV_MSDC_FIFO_COUNT_4_BITS
    #define DRV_MSDC_CLK_MT6276_SERIES
    #define DRV_MSDC_CLK_SEARCH
    #define DRV_MSDC_FORCE_WAIT_FOR_PROG_R1B_MALFUNCTION // fix issue happened in PEGATRON
		#define DRV_MSDC_CHECK_MULTIBLOCK_WRITE_FINISHED
    #define DRV_MSDC_DRIVING_6255_SERIES
		//#define DRV_MSDC_CLK_PAT_6260_SERIES 
		#define DRV_MSDC_4_BYTE_BURST
		#define DRV_MSDC_CLKSRC_MT6261_SERIES
		#define DRV_MSDC_RST_MT6261_SERIES
		#define DRV_MSDC_GPIO_MT6261_SERIES
		#define DRV_MSDC_DBG_MT6261_SERIES
		#if defined(__MTK_INTERNAL__) 
		#if defined(__FLAVOR_BTDV3_FTE_QVGA_ON_61PHONE__) || defined(__FLAVOR_BTDV3_PLUTO_128X128_ON_61PHONE__) || defined(__FLAVOR_BTDV3_PLUTO_128X128_1LINK_ON_61PHONE__)
/* under construction !*/
		#endif
		#endif
#elif defined(DRV_MSDC_MT6276_SERIES)


    #define DRV_MSDC_CLK_MT6276_SERIES
    #define DRV_MSDC_CLK_SEARCH
    #define DRV_MSDC_MT6238_SERIES				/*second MSDC controller*/
    #define DRV_MSDC_FORCE_WAIT_FOR_PROG_R1B_MALFUNCTION // fix issue happened in PEGATRON
#elif defined(DRV_MSDC_MT6256_SERIES)
    #define DRV_MSDC_CLK_MT6256_SERIES
    #define DRV_MSDC_CLK_SEARCH
    #define DRV_MSDC_MT6238_SERIES				/*second MSDC controller*/
    #define DRV_MSDC_FORCE_WAIT_FOR_PROG_R1B_MALFUNCTION // fix issue happened in PEGATRON
#endif
#define R1B_INTERRUPT_MODE

/***** Coding Options *****/
#if defined(__MSDC_DUAL_CARD_SWITCH__)
#define DRV_MSDC_DUAL_TCARD_BY_SWITCH
#endif


//#ifdef __MSDC2_MSP_DVT__
//#define MSDC_TEST_MSDC2_FROM_MSDC1_CODE	//this option is used on msdc.c to tell that we want to test msdc2 on msdc code
//#endif

//#define MSDC2_SDIO_TEST
//#ifdef MSDC2_SDIO_TEST // guilin test msdc2-sdio
//    #define MSDC_TEST_MSDC2_FROM_MSDC1_CODE
//    #define __MSDC_NO_WRITE_PROTECT__
//#endif
/*we may enable __DRV_MSDC_CLK_SEARCH__ in makefile of some projects*/
//#ifdef __DRV_MSDC_CLK_SEARCH__
//#define DRV_MSDC_CLK_SEARCH
//#endif

//#define MSDC_START_DMA_IN_CALLBACK
#define MSDC_DMA		// using DMA transfer instead of polling
#define SD_STOP_SLOW // used for some card with incorrect busy status (Siemens, 

//The three level control the trace number. deafault is LEVEL1 and LEVEL2
#define MSDC_TRACE_LEVEL1
#define MSDC_TRACE_LEVEL2
//#define MSDC_TRACE_LEVEL3



#if defined(DRV_MSDC_SD_SDIO_SHARE_BY_SWITCH)
#define DRV_MSDC_HW_CONTENTION
#endif

#if defined( DRV_MSDC_SD_SDIO_SHARE_BY_SWITCH) || defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
#define DRV_MSDC_SHARE_BY_SWITCH
#endif


#define __DRV_MSDC_FAST_FORMAT__




#ifdef __DYNAMIC_SWITCH_CACHEABILITY__
#define MSDC_CACHED_SUPPORT
#else
	#ifdef MSDC_CACHED_SUPPORT
	#undef MSDC_CACHED_SUPPORT
	#endif
#endif


#if defined(__MSDC_4BIT_BUSWIDTH__)
#define MSDC_SD_BITS4_BUS		// using 4bits bus width for SD card which has this feature
#endif


#define DCL_MSDC_INTERFACE
#if !defined(__MSDC_SD_MMC__)
#define DRV_MSDC_OFF
#endif



#endif /*End __DRV_FEATURES_MSDC_H__*/
