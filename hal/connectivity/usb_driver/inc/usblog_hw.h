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
 *    usblog_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *    This file intends for USB logging tool hardware register definitions
 *
 * Author:
 * -------
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef  USB_LOGGING_HW_H
#define USB_LOGGING_HW_H

#include "reg_base.h"


#if defined(DRV_USB_LOGGING_V1)||defined(DRV_USB_LOGGING_V2)
#define IRDBG_DSP_BASE_ADDRESS	DPRAM_CPU_base

#elif defined(DRV_USB_LOGGING_V3)||defined(DRV_USB_LOGGING_V4)||defined(DRV_USB_LOGGING_V5)||defined(DRV_USB_LOGGING_V6)||defined(DRV_USB_LOGGING_V7)
#define IRDBG_DSP_HOST_BASE_ADDRESS		DPRAM_CPU_base
#define IRDBG_DSP_SLAVE_BASE_ADDRESS		DPRAM2_CPU_base

#else //for further Design

#endif
//=================================================================

#if defined(DRV_USB_LOGGING_V1)
/* IRDBG part */
#define IRDBG_DSP_BASE_ADDR_1	(IRDBG_DSP_BASE_ADDRESS+0x27b*2)
#define IRDBG_DSP_BASE_ADDR_2	(IRDBG_DSP_BASE_ADDRESS+0x276*2)
#define IRDBG_DSP_BUFF_IND_1	(IRDBG_DSP_BASE_ADDRESS+0x277*2)
#define IRDBG_DSP_BUFF_IND_2	(IRDBG_DSP_BASE_ADDRESS+0x278*2)
#define IRDBG_DSP_BUFF_IND_3	(IRDBG_DSP_BASE_ADDRESS+0x279*2)
#define IRDBG_DSP_START_IND	(IRDBG_DSP_BASE_ADDRESS+0x27a*2)
#elif defined(DRV_USB_LOGGING_V2)
/* IRDBG part */
#define IRDBG_DSP_BASE_ADDR_1	(IRDBG_DSP_BASE_ADDRESS+0x2c7*2)
#define IRDBG_DSP_BASE_ADDR_2	(IRDBG_DSP_BASE_ADDRESS+0x2c8*2)
#define IRDBG_DSP_BUFF_IND_1	(IRDBG_DSP_BASE_ADDRESS+0x2c3*2)
#define IRDBG_DSP_BUFF_IND_2	(IRDBG_DSP_BASE_ADDRESS+0x2c4*2)
#define IRDBG_DSP_BUFF_IND_3	(IRDBG_DSP_BASE_ADDRESS+0x2c5*2)
#define IRDBG_DSP_START_IND	(IRDBG_DSP_BASE_ADDRESS+0x2c9*2)
#define IRDBG_DSP_BUFF_SIZE	(IRDBG_DSP_BASE_ADDRESS+0x2c6*2)
#define IRDBG_STA				(IRDBG_base+0x00)	/* RC */
#elif defined(DRV_USB_LOGGING_V3)
/* IRDBG part */
//Low 16 bit of buffer start address 
#define IRDBG_DSP_HOST_BASE_ADDR_1		(IRDBG_DSP_HOST_BASE_ADDRESS+0x13f*2)
// High 16 bit of buffer start address
#define IRDBG_DSP_HOST_BASE_ADDR_2		(IRDBG_DSP_HOST_BASE_ADDRESS+0x140*2)
// When finish tx of buffer #1, fill 0 at this address
#define IRDBG_DSP_HOST_BUFF_IND_1		(IRDBG_DSP_HOST_BASE_ADDRESS+0x141*2)
// When finish tx of buffer #2, fill 0 at this address
#define IRDBG_DSP_HOST_BUFF_IND_2		(IRDBG_DSP_HOST_BASE_ADDRESS+0x142*2)
// When finish tx of buffer #3, fill 0 at this address
#define IRDBG_DSP_HOST_BUFF_IND_3		(IRDBG_DSP_HOST_BASE_ADDRESS+0x143*2)
// Fill 1 to indicate we are ready to send data for DSP
#define IRDBG_DSP_HOST_START_IND			(IRDBG_DSP_HOST_BASE_ADDRESS+0x144*2)
// Indicate the size of layer 2 sub buffer
#define IRDBG_DSP_HOST_SUB_BUFF_SIZE		(IRDBG_DSP_HOST_BASE_ADDRESS+0x145*2)
// Indicate the number of layer 2 sub buffers we assign
#define IRDBG_DSP_HOST_SUB_BUFF_NUM		(IRDBG_DSP_HOST_BASE_ADDRESS+0x152*2)
// Buffer status, filled by DSP, DSP will fill this address and 
// trigger an intr to notify there is a buffer ready to be sent out


#define IRDBG_DSP_SLAVE_BASE_ADDR_1		(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x27b*2)
#define IRDBG_DSP_SLAVE_BASE_ADDR_2		(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x276*2)
#define IRDBG_DSP_SLAVE_BUFF_IND_1		(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x277*2)
#define IRDBG_DSP_SLAVE_BUFF_IND_2		(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x278*2)
#define IRDBG_DSP_SLAVE_BUFF_IND_3		(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x279*2)
#define IRDBG_DSP_SLAVE_START_IND			(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x27a*2)
#define IRDBG_DSP_SLAVE_SUB_BUFF_SIZE	(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x293*2)
#define IRDBG_DSP_SLAVE_SUB_BUFF_NUM		(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x294*2)

#define IRDBG_HOST_STA						(IRDBG_base+0x00)	/* 16bit, RC */
#define IRDBG_SLAVE_STA					(IRDBG2_base+0x00)		/* 16bit, RC */


// Provide by Wego
#define IRDBG_DSP_SLAVE_FILTER_1		(IRDBG_DSP_SLAVE_BASE_ADDRESS + 0x3CC)
#define IRDBG_DSP_SLAVE_FILTER_2		(IRDBG_DSP_SLAVE_BASE_ADDRESS + 0x3E0)

// Provided by Wego
#define IRDBG_DSP_HOST_FILTER_1		(IRDBG_DSP_HOST_BASE_ADDRESS + 0x1E2)
#define IRDBG_DSP_HOST_FILTER_2		(IRDBG_DSP_HOST_BASE_ADDRESS + 0x1F8)

#if 0    //MT6238 Test
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

#elif defined(DRV_USB_LOGGING_V4)
/* IRDBG part */

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
#endif

#elif defined(DRV_USB_LOGGING_V5)
/* IRDBG part */

#if !defined(DRV_USB_LOGGING_V5_SINGLE_DSP)
	//Low 16 bit of buffer start address 
	#define IRDBG_DSP_HOST_BASE_ADDR_1		(IRDBG_DSP_HOST_BASE_ADDRESS+0x13f*2)
	// High 16 bit of buffer start address
	#define IRDBG_DSP_HOST_BASE_ADDR_2		(IRDBG_DSP_HOST_BASE_ADDRESS+0x140*2)
	// When finish tx of buffer #1, fill 0 at this address
	#define IRDBG_DSP_HOST_BUFF_IND_1		(IRDBG_DSP_HOST_BASE_ADDRESS+0x141*2)
	// When finish tx of buffer #2, fill 0 at this address
	#define IRDBG_DSP_HOST_BUFF_IND_2		(IRDBG_DSP_HOST_BASE_ADDRESS+0x142*2)
	// When finish tx of buffer #3, fill 0 at this address
	#define IRDBG_DSP_HOST_BUFF_IND_3		(IRDBG_DSP_HOST_BASE_ADDRESS+0x143*2)
	// Fill 1 to indicate we are ready to send data for DSP
	#define IRDBG_DSP_HOST_START_IND			(IRDBG_DSP_HOST_BASE_ADDRESS+0x144*2)
	// Indicate the size of layer 2 sub buffer
	#define IRDBG_DSP_HOST_SUB_BUFF_SIZE		(IRDBG_DSP_HOST_BASE_ADDRESS+0x145*2)
	// Indicate the number of layer 2 sub buffers we assign
	#define IRDBG_DSP_HOST_SUB_BUFF_NUM		(IRDBG_DSP_HOST_BASE_ADDRESS+0x152*2)
#else
#ifdef DRV_USB_LOGGING_MT50
	//Low 16 bit of buffer start address 
	#define IRDBG_DSP_HOST_BASE_ADDR_1		(IRDBG_DSP_HOST_BASE_ADDRESS+0x3ac8*2)
	// High 16 bit of buffer start address
	#define IRDBG_DSP_HOST_BASE_ADDR_2		(IRDBG_DSP_HOST_BASE_ADDRESS+0x3ac9*2)
	// When finish tx of buffer #1, fill 0 at this address
	#define IRDBG_DSP_HOST_BUFF_IND_1		(IRDBG_DSP_HOST_BASE_ADDRESS+0x3aca*2)
	// When finish tx of buffer #2, fill 0 at this address
	#define IRDBG_DSP_HOST_BUFF_IND_2		(IRDBG_DSP_HOST_BASE_ADDRESS+0x3acb*2)
	// When finish tx of buffer #3, fill 0 at this address
	#define IRDBG_DSP_HOST_BUFF_IND_3		(IRDBG_DSP_HOST_BASE_ADDRESS+0x3acc*2)
	// Fill 1 to indicate we are ready to send data for DSP
	#define IRDBG_DSP_HOST_START_IND			(IRDBG_DSP_HOST_BASE_ADDRESS+0x3acd*2)
	// Indicate the size of layer 2 sub buffer
	#define IRDBG_DSP_HOST_SUB_BUFF_SIZE		(IRDBG_DSP_HOST_BASE_ADDRESS+0x3ace*2)
	// Indicate the number of layer 2 sub buffers we assign
	#define IRDBG_DSP_HOST_SUB_BUFF_NUM 	(IRDBG_DSP_HOST_BASE_ADDRESS+0x3acf*2)
#else
	//Low 16 bit of buffer start address 
	#define IRDBG_DSP_HOST_BASE_ADDR_1		(IRDBG_DSP_HOST_BASE_ADDRESS+0x3a70*2)
	// High 16 bit of buffer start address
	#define IRDBG_DSP_HOST_BASE_ADDR_2		(IRDBG_DSP_HOST_BASE_ADDRESS+0x3a71*2)
	// When finish tx of buffer #1, fill 0 at this address
	#define IRDBG_DSP_HOST_BUFF_IND_1		(IRDBG_DSP_HOST_BASE_ADDRESS+0x3a72*2)
	// When finish tx of buffer #2, fill 0 at this address
	#define IRDBG_DSP_HOST_BUFF_IND_2		(IRDBG_DSP_HOST_BASE_ADDRESS+0x3a73*2)
	// When finish tx of buffer #3, fill 0 at this address
	#define IRDBG_DSP_HOST_BUFF_IND_3		(IRDBG_DSP_HOST_BASE_ADDRESS+0x3a74*2)
	// Fill 1 to indicate we are ready to send data for DSP
	#define IRDBG_DSP_HOST_START_IND			(IRDBG_DSP_HOST_BASE_ADDRESS+0x3a75*2)
	// Indicate the size of layer 2 sub buffer
	#define IRDBG_DSP_HOST_SUB_BUFF_SIZE		(IRDBG_DSP_HOST_BASE_ADDRESS+0x3a76*2)
	// Indicate the number of layer 2 sub buffers we assign
	#define IRDBG_DSP_HOST_SUB_BUFF_NUM		(IRDBG_DSP_HOST_BASE_ADDRESS+0x3a77*2)
#endif
#endif

// Buffer status, filled by DSP, DSP will fill this address and 
// trigger an intr to notify there is a buffer ready to be sent out

#define IRDBG_DSP_SLAVE_BASE_ADDR_1		(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x27b*2)
#define IRDBG_DSP_SLAVE_BASE_ADDR_2		(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x276*2)
#define IRDBG_DSP_SLAVE_BUFF_IND_1		(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x277*2)
#define IRDBG_DSP_SLAVE_BUFF_IND_2		(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x278*2)
#define IRDBG_DSP_SLAVE_BUFF_IND_3		(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x279*2)
#define IRDBG_DSP_SLAVE_START_IND			(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x27a*2)
#define IRDBG_DSP_SLAVE_SUB_BUFF_SIZE	(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x293*2)
#define IRDBG_DSP_SLAVE_SUB_BUFF_NUM		(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x294*2)

#ifdef DRV_USB_LOGGING_MT50
#define IRDBG1_base	IRDMA_base
#define IRQ_IRDEBUG1_CODE	IRQ_IRDEBUG_CODE
#elif defined(DRV_USB_LOGGING_V5_SINGLE_DSP)
#define IRDBG1_base	IRDBG_base
#define IRQ_IRDEBUG1_CODE	IRQ_IRDEBUG2_CODE
#endif

#define IRDBG_HOST_STA						(IRDBG1_base+0x00)	/* 16bit, RC */
#if !defined(DRV_USB_LOGGING_V5_SINGLE_DSP)
#define IRDBG_SLAVE_STA					(IRDBG2_base+0x00)		/* 16bit, RC */
#endif

// Provide by Wego
#define IRDBG_DSP_SLAVE_FILTER_1		(IRDBG_DSP_SLAVE_BASE_ADDRESS + 0x3CC)
#define IRDBG_DSP_SLAVE_FILTER_2		(IRDBG_DSP_SLAVE_BASE_ADDRESS + 0x3E0)

// Provided by Wego
#ifdef DRV_USB_LOGGING_MT50

#define IRDBG_DSP_HOST_FILTER_1		(IRDBG_DSP_HOST_BASE_ADDRESS + 0x3AD1*2)
#define IRDBG_DSP_HOST_FILTER_2		(IRDBG_DSP_HOST_BASE_ADDRESS + 0x3AD2*2)

#else
#define IRDBG_DSP_HOST_FILTER_1		(IRDBG_DSP_HOST_BASE_ADDRESS + 0x1E2)
#define IRDBG_DSP_HOST_FILTER_2		(IRDBG_DSP_HOST_BASE_ADDRESS + 0x1F8)

#endif
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#elif defined(DRV_USB_LOGGING_V6)
/* IRDBG part */

#define IRDBG_DSP_HOST_SWDBG					(IRDBG_DSP_HOST_BASE_ADDRESS+0x149*2)
#define IRDBG_DSP_HOST_CNTL			 			(IRDBG_DSP_HOST_BASE_ADDRESS+0x0F0*2)

#define IRDBG_DSP_HOST_START_IND			(IRDBG_DSP_HOST_BASE_ADDRESS+0x14A*2)
#define IRDBG_DSP_HOST_SUB_BUFF_SIZE	(IRDBG_DSP_HOST_BASE_ADDRESS+0x14B*2)
#define IRDBG_DSP_HOST_SUB_BUFF_NUM		(IRDBG_DSP_HOST_BASE_ADDRESS+0x14C*2) 
#define IRDBG_DSP_HOST_BASE_ADDR_1		(IRDBG_DSP_HOST_BASE_ADDRESS+0x14D*2)  //Low
#define IRDBG_DSP_HOST_BASE_ADDR_2		(IRDBG_DSP_HOST_BASE_ADDRESS+0x14E*2) //UP
#define IRDBG_DSP_HOST_BUFF_IND_1			(IRDBG_DSP_HOST_BASE_ADDRESS+0x14F*2)
#define IRDBG_DSP_HOST_BUFF_IND_2			(IRDBG_DSP_HOST_BASE_ADDRESS+0x150*2)
#define IRDBG_DSP_HOST_BUFF_IND_3			(IRDBG_DSP_HOST_BASE_ADDRESS+0x151*2)

#define IRDBG_DSP_SLAVE_SWDBG					(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x2A8*2)
#define IRDBG_DSP_SLAVE_CNTL			 		(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x1E4*2)

#define IRDBG_DSP_SLAVE_START_IND			(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x2A9*2)
#define IRDBG_DSP_SLAVE_SUB_BUFF_SIZE	(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x2AA*2)
#define IRDBG_DSP_SLAVE_SUB_BUFF_NUM	(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x2AB*2)
#define IRDBG_DSP_SLAVE_BASE_ADDR_1		(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x2AC*2)
#define IRDBG_DSP_SLAVE_BASE_ADDR_2		(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x2AD*2)
#define IRDBG_DSP_SLAVE_BUFF_IND_1		(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x2AE*2)
#define IRDBG_DSP_SLAVE_BUFF_IND_2		(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x2AF*2)
#define IRDBG_DSP_SLAVE_BUFF_IND_3		(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x2B0*2)

#define IRDBG_HOST_STA						(IRDBG_base+0x00)	/* 16bit, RC */
#define IRDBG_SLAVE_STA					(IRDBG2_base+0x00)		/* 16bit, RC */


/////Debug
#define IRDBG_DSP_HOST_FILTER		(IRDBG_DSP_HOST_BASE_ADDRESS + 0x1E2)
#define IRDBG_DSP_Slave_FILTER		(IRDBG_DSP_HOST_BASE_ADDRESS + 0x3CC)


#elif defined(DRV_USB_LOGGING_V7)

#define IRDBG_DSP_HOST_SWDBG		(IRDBG_DSP_HOST_BASE_ADDRESS+0x149*2)
#define IRDBG_DSP_HOST_CNTL		(IRDBG_DSP_HOST_BASE_ADDRESS+0x0F0*2)

#define IRDBG_DSP_HOST_START_IND	(IRDBG_DSP_HOST_BASE_ADDRESS+0x14A*2)
#define IRDBG_DSP_HOST_SUB_BUFF_SIZE	(IRDBG_DSP_HOST_BASE_ADDRESS+0x14B*2)
#define IRDBG_DSP_HOST_SUB_BUFF_NUM	(IRDBG_DSP_HOST_BASE_ADDRESS+0x14C*2) 
#define IRDBG_DSP_HOST_BASE_ADDR_1	(IRDBG_DSP_HOST_BASE_ADDRESS+0x14D*2)	//Low
#define IRDBG_DSP_HOST_BASE_ADDR_2	(IRDBG_DSP_HOST_BASE_ADDRESS+0x14E*2)	//UP
#define IRDBG_DSP_HOST_BUFF_IND_1	(IRDBG_DSP_HOST_BASE_ADDRESS+0x14F*2)
#define IRDBG_DSP_HOST_BUFF_IND_2	(IRDBG_DSP_HOST_BASE_ADDRESS+0x150*2)
#define IRDBG_DSP_HOST_BUFF_IND_3	(IRDBG_DSP_HOST_BASE_ADDRESS+0x151*2)

#define IRDBG_DSP_SLAVE_SWDBG		(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x32A*2)
#define IRDBG_DSP_SLAVE_CNTL		(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x1E4*2)

#define IRDBG_DSP_SLAVE_START_IND	(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x32B*2)
#define IRDBG_DSP_SLAVE_SUB_BUFF_SIZE	(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x32C*2)
#define IRDBG_DSP_SLAVE_SUB_BUFF_NUM	(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x32D*2)
#define IRDBG_DSP_SLAVE_BASE_ADDR_1	(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x32E*2)
#define IRDBG_DSP_SLAVE_BASE_ADDR_2	(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x32F*2)
#define IRDBG_DSP_SLAVE_BUFF_IND_1	(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x330*2)
#define IRDBG_DSP_SLAVE_BUFF_IND_2	(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x331*2)
#define IRDBG_DSP_SLAVE_BUFF_IND_3	(IRDBG_DSP_SLAVE_BASE_ADDRESS+0x332*2)

#define IRDBG_HOST_STA			(IRDBG_base+0x00)	/* 16bit, RC */
#define IRDBG_SLAVE_STA			(IRDBG2_base+0x00)	/* 16bit, RC */

/////Debug
#define IRDBG_DSP_HOST_FILTER		(IRDBG_DSP_HOST_BASE_ADDRESS + 0x1E2)
#define IRDBG_DSP_Slave_FILTER		(IRDBG_DSP_HOST_BASE_ADDRESS + 0x3CC)


#elif defined(DRV_USB_LOGGING_V8)

#define	MD2G_SHEME_BASE				BFMDIF_base		//(0x65000000) in MT6276
#define DP_MLTUSBLOG1_BUFE_H_ADDR   (MD2G_SHEME_BASE+0x062a)  //-> higher 16 bit of BufE address                                                        
#define DP_MLTUSBLOG1_BUFE_L_ADDR   (MD2G_SHEME_BASE+0x062c)  //-> lower 16 bit of BufE address                                                        
#define DP_MLTUSBLOG1_SIZE_ADDR     (MD2G_SHEME_BASE+0x062e)  //-> size and number of BufE
#define DP_MLTUSBLOG1_BUSY_ADDR     (MD2G_SHEME_BASE+0x0630)  //-> Usb busy state, 0: busy, 1: not busy                                             

#define	MDCI_DSPBUSY	0x00	//MCU is not ready to receive data
#define	MDCI_DSPREADY	0x01
#define	MDCI_DSPSTART	0x100
#define DP_MLTUSBLOG2_BUFE_H_ADDR   (MD2G_SHEME_BASE+0x0632)  //                                                                                       
#define DP_MLTUSBLOG2_BUFE_L_ADDR   (MD2G_SHEME_BASE+0x0634)  //                                                                                       
#define DP_MLTUSBLOG2_SIZE_ADDR     (MD2G_SHEME_BASE+0x0636)  //                                                                                       
#define DP_MLTUSBLOG2_BUSY_ADDR     (MD2G_SHEME_BASE+0x0638)  //


#endif

#endif  /* USB_LOGGING_HW_H */               

