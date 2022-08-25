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
 * MTSOC.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *      MTSOC chip Register
 *
 * Author:
 * -------
 *Run Liu (MTK54005)
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *******************************************************************************/
#ifndef _FMSOC_H
#define _FMSOC_H
  
#include "reg_base.h"
#include "kal_general_types.h"
/*****************************************************************************
 * HW register definitions and macros
 *****************************************************************************/
#define FM_PWR_CON_REG		(CONFIG_base + 0x0300) //CONFIG_base:0x80000000
#define FM_PWR_CON2_REG            (CONFIG_base + 0x0304)
#define FM_PWR_ACK_REG              (CONFIG_base + 0x0308)
#define FM_FSPI_MAS_BCLK_REG   (CONFIG_base +0x728)
#define FM_MCUSYS_PDN_SET2_REG   (CONFIG_base +0x718)
#define FM_MTCMOS_RST_REG   0x800F0120

#define REG_FM_PWR_CON		(*((volatile unsigned int*) FM_PWR_CON_REG))
#define REG_FM_PWR_CON2		(*((volatile unsigned int*) FM_PWR_CON2_REG))
#define REG_FM_PWR_ACK		(*((volatile unsigned int*) FM_PWR_ACK_REG))
#define REG_FM_FSPI_MAS_BCLK	(*((volatile unsigned int*) FM_FSPI_MAS_BCLK_REG))
#define REG_FM_FSPI_PDN_ENABLE	(*((volatile unsigned int*) FM_MCUSYS_PDN_SET2_REG))
#define REG_FM_MTCMOS_RST	(*((volatile unsigned int*) FM_MTCMOS_RST_REG))

#define FM_PWR_ON_BIT               (0x4000)
#define FM_ISOLATION_EN_BIT         (0x2000)
#define FM_PWRON_RSTB_BIT            (0x1000)
#if defined(MT6256FM)
#define FM_MEM_OFF_BIT          (0x40000000)
#elif defined(MT6255FM)/*MT6255FM E1*/
#define FM_MEM_OFF_BIT          (0x80000000)
#else//synch latest chip
#define FM_MEM_OFF_BIT          (0x80000000)
#endif
#define FM_CLK_DISABLE_BIT          (0x8)
#define FM_SYS_PWR_ACK			(0x8)
#define FM_FSPI_MAS_BCLK_BIT    (0x400)

#define FM_ENABLE_POWER() \
  do { REG_FM_PWR_CON |= FM_PWR_ON_BIT; } while(0)

#define FM_DISABLE_POWER() \
  do { REG_FM_PWR_CON &= ~FM_PWR_ON_BIT; } while(0)

#define FM_MEM_OFF() \
  do { REG_FM_PWR_CON2 |= FM_MEM_OFF_BIT; } while(0)

#define FM_MEM_ON() \
  do { REG_FM_PWR_CON2 &= ~FM_MEM_OFF_BIT; } while(0)

#define FM_CLK_DISABLE() \
    do { REG_FM_PWR_CON2 |= FM_CLK_DISABLE_BIT; } while(0)
  
#define FM_CLK_ENABLE() \
    do { REG_FM_PWR_CON2 &= ~FM_CLK_DISABLE_BIT; } while(0)

#define FM_RESET_POWER() \
  do { \
    REG_FM_PWR_CON &= ~FM_PWRON_RSTB_BIT; \
    REG_FM_PWR_CON |= FM_PWRON_RSTB_BIT; \
  } while(0)

#define FM_RESET_MTCMOS() \
  do { \
    REG_FM_MTCMOS_RST &= ~0x03; \
    REG_FM_MTCMOS_RST |= 0x03; \
  } while(0)

#define FM_ENABLE_RESET() \
  do { REG_FM_PWR_CON &= ~FM_PWRON_RSTB_BIT; } while(0)

#define FM_DISABLE_RESET() \
  do { REG_FM_PWR_CON |= FM_PWRON_RSTB_BIT; } while(0)
                            
#define FM_ENABLE_ISOLATION() \
  do { REG_FM_PWR_CON |= FM_ISOLATION_EN_BIT; } while(0)

#define FM_DISABLE_ISOLATION() \
  do { REG_FM_PWR_CON &= ~FM_ISOLATION_EN_BIT; } while(0)
         
#define FM_FSPI_MAS_BCLK_ENABLE() \
  do { REG_FM_FSPI_MAS_BCLK |= FM_FSPI_MAS_BCLK_BIT; } while(0)
#define FM_FSPI_MAS_BCLK_DISABLE() \
		do { REG_FM_FSPI_PDN_ENABLE |= FM_FSPI_MAS_BCLK_BIT; } while(0)

/* FSPI HW REG */
#define FSPI_MAS_CTRL_REG           (FM_base+0x0000) //FSPI_base:0x800F0000
#define FSPI_MAS_ADDR_REG          (FM_base+0x0004)
#define FSPI_MAS_WRDATA_REG     (FM_base+0x0008)
#define FSPI_MAS_RDDATA_REG      (FM_base+0x000c)
#define FSPI_MAS_CFG1_REG           (FM_base+0x0010)
#define FSPI_MAS_CFG2_REG           (FM_base+0x0014)
#define FSPI_MAS_MODESEL_REG    (FM_base+0x0020)
#define FSPI_MAS_RESET_REG         (FM_base+0x0030)

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
#define RDS_CRC_CORR_REG	(0xD6)
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
#define FM_DAC_CON1 (0x9C)//0x83
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


typedef struct {
   kal_uint16 addr;
   kal_uint16 and;
   kal_uint16 or;
} ctrl_word_operation;

#if defined(INTERNAL_ANTENNAL_SUPPORT)
#define FM_PowerOn_with_ShortAntenna
#endif

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
#if 0/*before system init, FM won't be open*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(MCU_512M)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(MCU_520M)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
#endif
#endif
