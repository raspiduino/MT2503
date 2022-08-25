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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * MT6251.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *      MT6251 Register
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#ifndef MT6251_H
  #define MT6251_H
  
#include "reg_base.h"
#include "kal_general_types.h"
/*****************************************************************************
 * HW register definitions and macros
 *****************************************************************************/
#define FM_FSPI_MAS_BCLK_REG   (MD2GCONFG_base +0x020)

#define REG_FM_FSPI_MAS_BCLK	(*((volatile unsigned int*) FM_FSPI_MAS_BCLK_REG))

#define FM_FSPI_MAS_BCLK_BIT    (0x4000)

#define FM_FSPI_MAS_BCLK_ENABLE() \
  do { REG_FM_FSPI_MAS_BCLK |= FM_FSPI_MAS_BCLK_BIT; } while(0)

/* FSPI HW REG */
#define FSPI_MAS_CTRL_REG           (FMSYS_base+0x0000) //FSPI_base:0x82110000
#define FSPI_MAS_ADDR_REG          (FMSYS_base+0x0010)
#define FSPI_MAS_WRDATA_REG     (FMSYS_base+0x0020)
#define FSPI_MAS_RDDATA_REG      (FMSYS_base+0x0030)
#define FSPI_MAS_CFG1_REG           (FMSYS_base+0x0040)
#define FSPI_MAS_CFG2_REG           (FMSYS_base+0x0050)
#define FSPI_MAS_MODESEL_REG    (FMSYS_base+0x0080)
#define FSPI_MAS_RESET_REG         (FMSYS_base+0x00C0)
#define FM_RESET_REG 			 (FMSYS_base+0x0120)
#define FM_MEM_ON_REG			 (CONFIG_base+0x0360)

#define REG_FM_RESET	(*((volatile unsigned int*) FM_RESET_REG))
	#define FSPI_CORE_RSTB     (0x01)
	#define FSPI_RGF_RSTB       (0x02)

#define REG_FM_MEM_ON	(*((volatile unsigned int*) FM_MEM_ON_REG))

#define FM_MEM_POWER_ON() \
  do { REG_FM_MEM_ON |= 0x100; } while(0)

#define FM_SYS_RESET_ON() \
  do { REG_FM_FSPI_MAS_BCLK |= (FSPI_CORE_RSTB&FSPI_RGF_RSTB); } while(0)

#define FM_SYS_RESET_OFF() \
  do { REG_FM_FSPI_MAS_BCLK &= 0; } while(0)

/* FM related REG */
#define FM_CG1_CTRL		(0x60)
#define FM_CG2_CTRL		(0x61)
#define FM_HW_VER		(0x62)
#define FM_MAIN_CTRL		(0x63)
	#define TUNE (0x01)
	#define SEEK (0x02)
	#define SCAN (0x04)
	#define RXCAL (0x08)
	#define RDS_MASK (0x10)
#define FM_MAIN_CFG1		(0x66)
#define FM_MAIN_CFG2		(0x67)
#define FM_MAIN_MCLKDESENSE		(0x68)
#define FM_MAIN_INTR		(0x69) //STC_DONE interrupt status flag
	#define FM_INTR_STC_DONE	(0x01)
	#define   FM_INTR_IQCAL_DONE	(0x02)				
	#define   FM_INTR_DESENSE_HIT	(0x04)				
	#define   FM_INTR_CHNL_CHG	(0x08)				
	#define   FM_INTR_SW_INTR	(0x10)	
	#define FM_INTR_RDS		(0x20)
	
#define FM_MAIN_INTRMASK		(0x6A)
	#define INTR_STC_DONE_MASK (0x01)
	#define INTR_RDS_MASK (0x20)
#define FM_MAIN_EXTINTRMASK		(0x6B)
	#define EXT_STC_DONE_MASK (0x01)
	#define EXT_RDS_MASK (0x20)

#define FM_MAIN_CHANDETSTAT		(0x6F) //STC_DONE status flag
#define MASK_STC 		(0x01)  // Seek/Tune/PowerOn complete  D5 in  adress 6FH 

//#define CHNL_DET_STATUS		0x3F // the address of channel detection register
#define MASK_READCHAN (0xFFE0) // D4~D15 in address 6FH
#define SHIFT_READCHAN (0x4)

#define ADDR_SEARCH_THRESHOLD		(0xE0)		
#define ADDR_RSSI		(0xE8)
#define ADDR_PAMD		(0xE9)
#define FM_PG_SEL		(0x9F)

#define MASK_RSSI 		(0xFE00)
#define SHIFT_RSSI  		(0x9)

/*RDS Register */
#define RDS_RESET                                 (0xE0)
#define RDS_BER_THD_SET_REG		(0xDB)
#define RDS_BER_BAD_REG                    (0xDC)
#define RDS_GOODBK_CNT                     (0xF6)
#define RDS_BADBK_CNT                        (0xF7)
#define RDS_BKCNT_RESET			(0xF8)
#define RDS_DATA_A_E_REG			(0xF9)
#define RDS_DATA_CRC_FFOST		(0xFA)
	#define   RDS_GDBK_IND_A	(0x08)	
	#define   RDS_GDBK_IND_B	(0x04)	
	#define   RDS_GDBK_IND_C	(0x02)	
	#define   RDS_GDBK_IND_D	(0x01)	
	#define   OSTWD_E                    (0x10)
	#define   RDS_DCO_FIFO_OFST		(0x01E0)
#define RDS_FFOST_TRIG_TH			(0xFB)


#define RDS_INTR_STATUS_REG		(0xFD)
	#define   RDS_INTR_THRE		(0x01)
	#define   RDS_INTR_TO		(0x02)		
	#define   RDS_INTR_FULL		(0x04)			
	#define   RDS_INTR_MASK		(0x07)
#define RDS_BDGRP_ABD_CTRL_REG		(0xFE)
	#define BDGRP_ABD_EN (0x01)
	#define BER_RUN (0x2000)
	
/*I2S Register */	
#define FM_DAC_CON1 (0x9C)
#define FM_DAC_CON2 (0x84)

#define FM_FT_CON0 (0x86)
       #define FT_EN		(0x1)
#define FM_FT_CON9 (0x8F)
	   
#define FM_I2S_CON0 (0x90)
       #define I2S_SRC		(0x8)
	#define WLEN		(0x4)
	#define FORMAT          (0x2)
	#define I2S_EN		(0x1)

#define FM_CAP_ARRAY (0x26)/*short antenna cap*/

// enginner mode struct
typedef enum group_idx {
	   mono=0,
	   stereo,
	   RSSI_threshold,
	   HCC_Enable,
	   PAMD_threshold,
	   Softmute_Enable,
	   De_emphasis,
	   HL_Side,
	   Demod_BW,
	   Dynamic_Limiter,
	   Softmute_Rate,
	   AFC_Enable,
	   Softmute_Level,
	   Analog_Volume,
	   FMR_GROUP_TOTAL_NUMS
	} FMR_FACTORY_GROUP_ENUM;
	
typedef enum item_idx {
	   Sblend_OFF=0,
	   Sblend_ON,  
	   FMR_ITEM_TOTAL_NUMS
	} FMR_FACTORY_ITEM_INDEX;
// enginner mode struct

/*----------------------------------------------------------------------------*/
/* Loop count for time measurement                                            */
/*----------------------------------------------------------------------------*/
#if defined(MCU_13M)
/* 1T ~= 77 ns */
#define COUNTER_50US (325)
#define COUNTER_20US (130)
#define COUNTER_15US (97)
#define COUNTER_10US (65)
#define COUNTER_05US (32)
#define COUNTER_350NS (3)

#elif defined(MCU_15_36M)
/* 1T ~= 65 ns */
#define COUNTER_50US (384)
#define COUNTER_20US (153)
#define COUNTER_15US (174)
#define COUNTER_10US (76)
#define COUNTER_05US (38)
#define COUNTER_350NS (4)

#elif defined(MCU_26M)
/* 1T ~= 38 ns */
#define COUNTER_50US (658)
#define COUNTER_20US (263)
#define COUNTER_15US (197)
#define COUNTER_10US (132)
#define COUNTER_05US (66)
#define COUNTER_350NS (5)

#elif defined(MCU_30_72M)
/* 1T ~= 33 ns */
#define COUNTER_50US (757)
#define COUNTER_20US (303)
#define COUNTER_15US (227)
#define COUNTER_10US (151)
#define COUNTER_05US (75)
#define COUNTER_350NS (6)

#elif defined(MCU_39M)
/* 1T ~= 25 ns */
#define COUNTER_50US (1000)
#define COUNTER_20US (400)
#define COUNTER_15US (300)
#define COUNTER_10US (200)
#define COUNTER_05US (100)
#define COUNTER_350NS (7)

#elif defined(MCU_52M)
/* 1T ~= 19 ns */
#define COUNTER_50US (1316)
#define COUNTER_20US (526)
#define COUNTER_15US (395)
#define COUNTER_10US (263)
#define COUNTER_05US (132)
#define COUNTER_350NS (10)

#elif defined(MCU_61_44M)
/* 1T ~= 16 ns */
#define COUNTER_50US (1563)
#define COUNTER_20US (625)
#define COUNTER_15US (468)
#define COUNTER_10US (312)
#define COUNTER_05US (156)
#define COUNTER_350NS (11)

#elif defined(MCU_65M)
/* 1T ~= 15 ns */
#define COUNTER_50US (1666)
#define COUNTER_20US (666)
#define COUNTER_15US (500)
#define COUNTER_10US (333)
#define COUNTER_05US (166)
#define COUNTER_350NS (12)

#elif defined(MCU_78M)
/* 1T ~= 13 ns */
#define COUNTER_50US (1923)
#define COUNTER_20US (769)
#define COUNTER_15US (576)
#define COUNTER_10US (384)
#define COUNTER_05US (192)
#define COUNTER_350NS (13)

#elif defined(MCU_91M)
/* 1T ~= 11 ns */
#define COUNTER_50US (2272)
#define COUNTER_20US (909)
#define COUNTER_15US (681)
#define COUNTER_10US (454)
#define COUNTER_05US (227)
#define COUNTER_350NS (15)

#elif defined(MCU_104M)
/* 1T ~= 9.6 ns */
#define COUNTER_50US (2604)
#define COUNTER_20US (1042)
#define COUNTER_15US (781)
#define COUNTER_10US (521)
#define COUNTER_05US (260)
#define COUNTER_350NS (19)

#elif defined(MCU_122_88M)
/* 1T ~= 8.1 ns */
#define COUNTER_50US (3086)
#define COUNTER_20US (1235)
#define COUNTER_15US (925)
#define COUNTER_10US (617)
#define COUNTER_05US (308)
#define COUNTER_350NS (22)

#elif defined(MCU_208M)
/* 1T ~= 4.8 ns */
#define COUNTER_50US (5208)
#define COUNTER_20US (2084)
#define COUNTER_15US (1562)
#define COUNTER_10US (1042)
#define COUNTER_05US (520)
#define COUNTER_350NS (37)

#elif defined(MCU_245_76M)
/* 1T ~= 4.0 ns */
#define COUNTER_50US (6172)
#define COUNTER_20US (2470)
#define COUNTER_15US (1850)
#define COUNTER_10US (1234)
#define COUNTER_05US (616)
#define COUNTER_350NS (44)

#elif defined(MCU_312M)
/* 1T ~= 3.3 ns */
#define COUNTER_50US (10000)
#define COUNTER_20US (3000)
#define COUNTER_15US (2000)
#define COUNTER_10US (1500)
#define COUNTER_05US (1000)
#define COUNTER_350NS (60)

#elif defined(MCU_650M)
/* 1T ~= 1.54 ns */
#define COUNTER_50US (32467)
#define COUNTER_20US (12987)
#define COUNTER_15US (9740)
#define COUNTER_10US (6494)
#define COUNTER_05US (3247)
#define COUNTER_350NS (227)

#else

#error "Unsupported MCU clock rate for single bank support V2!"

#endif
#endif
