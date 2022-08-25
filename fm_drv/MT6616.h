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
 * MT6616.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *      MT6616 Register
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#ifndef MT6616_H
  #define MT6616_H
#include "kal_general_types.h"

#define true         (kal_bool)(1==1)
#define false        (kal_bool)(1==0)
/* General propose constant */
#define FM_MAIN_CTRL		0x33
	#define TUNE 0x0001
	#define SEEK 0x0002
	#define SCAN 0x0004
	#define RXCAL 0x0008
	#define RDS_MASK 0x0010
#define FM_MAIN_CFG1		0x36
#define FM_MAIN_CFG2		0x37
#define FM_MAIN_MCLKDESENSE		0x38
#define FM_MAIN_INTR		0x39 //STC_DONE interrupt status flag
	#define FM_INTR_STC_DONE	0x0001
	#define   FM_INTR_IQCAL_DONE	0x0002				
	#define   FM_INTR_DESENSE_HIT	0x0004				
	#define   FM_INTR_CHNL_CHG	0x0008				
	#define   FM_INTR_SW_INTR	0x0010	
	#define FM_INTR_RDS		0x0020
	
#define FM_MAIN_EXTINTRMASK		0x3B
	#define EXT_STC_DONE_MASK 0x01
	#define EXT_RDS_MASK 0x20

#define FM_MAIN_CHANDETSTAT		0x3F //STC_DONE status flag
#define MASK_STC 		0x0001  // Seek/Tune/PowerOn complete  D5 in  adress 3FH 

//#define CHNL_DET_STATUS		0x3F // the address of channel detection register
#define MASK_READCHAN 0xFFE0 // D4~D15 in address 3FH
#define SHIFT_READCHAN 4

#define ADDR_RSSI		0x74
#define ADDR_PAMD		0x75 
#define MASK_RSSI 		0xFE00
#define SHIFT_RSSI  		9

/*RDS Register */

#define RDS_RESET                                 0x91
#define RDS_BER_THD_SET_REG		0xA7
#define RDS_BER_BAD_REG                    0xA8
#define RDS_GOODBK_CNT                     0xAA
#define RDS_BADBK_CNT                        0xAB
#define RDS_DATA_A_E_REG			0xAE
#define RDS_DATA_B_E_REG			0xAF
#define RDS_DATA_C_E_REG			0xB0
#define RDS_DATA_D_E_REG			0xB1
#define RDS_DATA_CRC_FFOST		0xB2
	#define   RDS_GDBK_IND_A	0x0008	
	#define   RDS_GDBK_IND_B	0x0004	
	#define   RDS_GDBK_IND_C	0x0002	
	#define   RDS_GDBK_IND_D	0x0001	
	#define   OSTWD_E                    0x0010
	#define   RDS_DCO_FIFO_OFST		0x01E0
#define RDS_FFOST_TRIG_TH			0xB3


#define RDS_INTR_STATUS_REG		0xB5
	#define   RDS_INTR_THRE		0x0001
	#define   RDS_INTR_TO		0x0002		
	#define   RDS_INTR_FULL		0x0004			
	#define   RDS_INTR_MASK		0x0007
#define RDS_BDGRP_ABD_CTRL_REG		0xB6
	#define BDGRP_ABD_EN 0x0001
	#define BER_RUN 0x2000
#define FM_DAC_CON1 0x83
#define FM_DAC_CON2 0x84

#define FM_FT_CON0 0x86
       #define FT_EN		0x0001
#define FM_FT_CON9 0x8F
	   
#define FM_I2S_CON0 0x90
       #define I2S_SRC		0x0008
	#define WLEN		0x0004
	#define FORMAT          0x0002
	#define I2S_EN		0x0001

/*FSPI Command*/
#if (defined(MT6616))
#ifdef FMR_DEBUG_TRACE
#define FMR_TRACE(trace_class,string) kal_prompt_trace(MOD_FMR, string)
#define FMR_TRACE0(trace_class,string,Para0) kal_prompt_trace(MOD_FMR, string,(Para0))
#define FMR_TRACE1(trace_class,string,Para0,Para1) kal_prompt_trace(MOD_FMR, string,(Para0),(Para1))
#else
#define FMR_TRACE(trace_class,string) kal_trace(TRACE_INFO,trace_class)
#define FMR_TRACE0(trace_class,string,Para0) kal_trace(TRACE_INFO,trace_class,(Para0))
#define FMR_TRACE1(trace_class,string,Para0,Para1) kal_trace(TRACE_INFO,trace_class,(Para0),(Para1))
#endif
#define FSPI_ENABLE_OPCODE				(0x01)
#define FSPI_MUX_SEL_OPCODE			(0x02)
#define FSPI_READ_OPCODE				(0x03)
#define FSPI_WRITE_OPCODE				(0x04)
//#define FI2C_READ_OPCODE				(0x05)
//#define FI2C_WRITE_OPCODE				(0x06)
#define FM_ENABLE_OPCODE				(0x07)
#define FM_RESET_OPCODE				(0x08)
#define FM_TUNE_OPCODE					(0x09)
#define FM_SEEK_OPCODE					(0x0A)
#define FM_SCAN_OPCODE					(0x0B)
#define RDS_ENABLE_OPCODE				(0x0C)
#define RDS_DATA_OPCODE				(0x0D)
#define FM_RAMPDOWN_OPCODE			(0x0E)
//#define FM_MCUCLK_SEL_OPCODE			(0x0F)
//#define FM_MODEMCLK_SEL_OPCODE		(0x10)
typedef struct{
   kal_uint8 buffer[256];
   kal_uint16 cmd;
   kal_uint16 event;
}HCI_data;
#endif

typedef struct{
   void (*callback)( kal_int16 wFreq, kal_uint8 wSignal_Lv, kal_bool is_vlaid );
   kal_bool bHWsearchStop;
   kal_bool is_preset;
   kal_bool is_searching;
#if (defined(MT6616))
   HCI_data FM_HCI_data;
#endif   
}FMR_data;
#endif
