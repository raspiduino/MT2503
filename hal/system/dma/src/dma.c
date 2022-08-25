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
 *    dma.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the DMA driver.
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
 *
 * removed!
 * removed!
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if ( (defined(MT6205)) || (defined(MT6205B)) || (defined(MT6208)) || (defined(FPGA)) )

#include "drv_comm.h"
#include "drv_hisr.h"
#include "reg_base.h"
#include "config_hw.h"
#include "intrCtrl.h"
#include "drvpdn.h"
#include "dma_hw.h"
#include "dma_sw.h"
#include "che_hw.h"
#include "lcd_if.h"
#include "btif_sw.h"


//extern void UART_SetDMAIntr(void);
dma_func DMA_CallBac;

extern void DMA_USBTxLISR(void);
extern void DMA_USBRxLISR(void);

static void DMA_HISR(void);


/*
* FUNCTION
*	DMA1_CheckRunStat
*
* DESCRIPTION
*   	Check whether DAM1 is in running
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	KAL_TRUE, DMA1 is running
*	KAL_FALSE, DMA1 is stoped
*
* GLOBALS AFFECTED
*   external_global
*/
kal_bool DMA1_CheckRunStat(void)
{
	kal_uint16 tmp;
	tmp = DRV_Reg(DMA_GLBSTS);
	if (tmp & DMA_GLBSTS_RUN1)
		return KAL_TRUE;
	else
		return KAL_FALSE;
}

/*
* FUNCTION
*	DMA1_CheckITStat
*
* DESCRIPTION
*   	Check whether DAM1 has an interrupt pending
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	KAL_TRUE, DMA1 has an interrupt pending
*	KAL_FALSE, DMA1 doesn't have any interrupt pending
*
* GLOBALS AFFECTED
*   external_global
*/
kal_bool DMA1_CheckITStat(void)
{
	kal_uint16 tmp;
	tmp = DRV_Reg(DMA_GLBSTS);
	if (tmp & DMA_GLBSTS_IT1)
		return KAL_TRUE;
	else
		return KAL_FALSE;
}

/*
* FUNCTION
*	DMA1_Init
*
* DESCRIPTION
*   	DMA1 intialize the src addr, dst addr, and transfer size
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void DMA1_Init(kal_uint32 src, kal_uint32 dst, kal_uint16 count,void func(void))
{
	kal_uint16 LSB;
	kal_uint16 MSB;

	LSB = (kal_uint16)src;
	MSB = (kal_uint16)(src >> 16);
	DRV_WriteReg(DMA1_MSBSRC,MSB);
   DRV_WriteReg(DMA1_LSBSRC,LSB);
	LSB = (kal_uint16)dst;
	MSB = (kal_uint16)(dst >> 16);
	DRV_WriteReg(DMA1_MSBDST,MSB);
   DRV_WriteReg(DMA1_LSBDST,LSB);
   DRV_WriteReg(DMA1_COUNT,count);

	DMA_CallBac.dma1_func = func;
}

/*
* FUNCTION
*	DMA2_CheckRunStat
*
* DESCRIPTION
*   	Check whether DAM2 is in running
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	KAL_TRUE, DMA2 is running
*	KAL_FALSE, DMA2 is stoped
*
* GLOBALS AFFECTED
*   external_global
*/
kal_bool DMA2_CheckRunStat(void)
{
	kal_uint16 tmp;
	tmp = DRV_Reg(DMA_GLBSTS);
	if (tmp & DMA_GLBSTS_RUN2)
		return KAL_TRUE;
	else
		return KAL_FALSE;
}

/*
* FUNCTION
*	DMA2_CheckITStat
*
* DESCRIPTION
*   	Check whether DAM2 has an interrupt pending
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	KAL_TRUE, DMA2 has an interrupt pending
*	KAL_FALSE, DMA2 doesn't have any interrupt pending
*
* GLOBALS AFFECTED
*   external_global
*/
kal_bool DMA2_CheckITStat(void)
{
	kal_uint16 tmp;
	tmp = DRV_Reg(DMA_GLBSTS);
	if (tmp & DMA_GLBSTS_IT2)
		return KAL_TRUE;
	else
		return KAL_FALSE;
}

/*
* FUNCTION
*	DMA1_Init
*
* DESCRIPTION
*   	DMA1 intialize the src addr, dst addr, and transfer size
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void DMA2_Init(kal_uint32 src, kal_uint32 dst, kal_uint16 count,void func(void))
{
	kal_uint16 LSB;
	kal_uint16 MSB;

	LSB = (kal_uint16)src;
	MSB = (kal_uint16)(src >> 16);
	DRV_WriteReg(DMA2_MSBSRC,MSB);
	DRV_WriteReg(DMA2_LSBSRC,LSB);
	LSB = (kal_uint16)dst;
	MSB = (kal_uint16)(dst >> 16);
   DRV_WriteReg(DMA2_MSBDST,MSB);
	DRV_WriteReg(DMA2_LSBDST,LSB);
   DRV_WriteReg(DMA2_COUNT,count);
	DMA_CallBac.dma2_func = func;
}

/*
* FUNCTION
*	DMA_LISR
*
* DESCRIPTION
*   	DMA interrupt handler
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void DMA_HISR(void)
{
	if ((DRV_Reg(DMA1_INTSTS))& DMA_INTSTS_MASK)
	{
	   DMA1_Stop();
	   DMA1_ACKI();
	   DMA_CallBac.dma1_func();
	}

	if ((DRV_Reg(DMA2_INTSTS))& DMA_INTSTS_MASK)
	{
	   DMA2_Stop();
	   DMA2_ACKI();
	   DMA_CallBac.dma2_func();
	}
	IRQClearInt(IRQ_DMA_CODE);
	IRQUnmask(IRQ_DMA_CODE);
}

void DMA_LISR(void)
{
   IRQMask(IRQ_DMA_CODE);

   drv_active_hisr(DRV_DMA_HISR_ID);
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 
void DMA_Ini(void)
{
#if defined(TK6516)
   *(volatile kal_uint16 *)DRVPDN_CON1_CLR = DRVPDN_CON1_DMA;
#elif defined(MT6516)
   *(volatile kal_uint16 *)CG_CLR0 = CG_CON0_DMA;
#else   
   *(volatile kal_uint16 *)DRVPDN_CON0_CLR = DRVPDN_CON0_DMA;
#endif

   IRQ_Register_LISR(IRQ_DMA_CODE, DMA_LISR,"DMA handler");

   DRV_Register_HISR(DRV_DMA_HISR_ID, DMA_HISR);

   IRQSensitivity(IRQ_DMA_CODE,LEVEL_SENSITIVE);

   IRQUnmask(IRQ_DMA_CODE);
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif
#else /* MT6205 || MT6208 || MT6205B || FPGA */
#include "kal_release.h"
#include "drv_comm.h"
#include "drv_hisr.h"
#include "reg_base.h"
#include "config_hw.h"
#include "intrCtrl.h"
#include "dma_hw.h"
#include "dma_sw.h"
#include "drvpdn.h"
#include "che_hw.h"
#include "lcd_if.h"
#include "uart_sw.h"
#include "cache_sw.h"
#include "init.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "uart_internal.h"
#include "us_timer.h"

//unsigned int __return_address(void);
extern kal_bool INT_QueryIsROMSpace(kal_uint32 addr);

typedef void (* VOID_FUNC)(void);

extern void DMA_USBTxLISR(void);
extern void DMA_USBRxLISR(void);
//extern void UART_SetDMAIntr(void);
extern void UART_TrxHandler_VFIFO(UART_PORT port);
extern void UART_RecHandler_VFIFO(UART_PORT port);

#if defined(__DMA_BT_VIRTUAL_FIFO__)
extern void BTIF_DMA_TX_Threshold_Handler_VFIFO(void);
extern void BTIF_DMA_RX_Threshold_Handler_VFIFO(void);
#endif //__DMA_BT_VIRTUAL_FIFO__

#if defined(__DMA_V3__)
extern void UART_RecTimeOutHandler(UART_PORT port);
#endif //__DMA_V3__

extern UARTStruct UARTPort[MAX_UART_PORT_NUM];
extern kal_uint32 kal_get_mytask_priority(void);

void DMA_ERROR_LISR(void);
/*******************************************************************************
 * Define global data
 *******************************************************************************/
#if defined (__DMA_SUPPORT_CALLBACK_LISR__)
/*DMA_pending_info_struct Error checking*/
#if (defined (DMA_VFIFO_CH_E) && (DMA_VFIFO_CH_E >31)) || (DMA_MAX_CHANNEL > 31)
    #error "Need to extern DMA_pending_info_struct's pending_int_bit for channel account > 31"
#endif
typedef struct
{
    kal_uint32 free_index;
	kal_bool hisr_activated;
    kal_uint32 pending_int_bit[2]; /*suppose total DMA channel # < 32*/
#if defined(__DMA_V3__)   
/*UART channel of __DMA_V3__ has 2 int flag*/
    kal_uint32 pending_int1_bit[2]; /*suppose total DMA channel # < 32*/
#endif
} DMA_pending_info_struct;
static DMA_pending_info_struct g_DMA_pending_info = 
{
    0,
    KAL_FALSE, 
    {0,0}
#if defined(__DMA_V3__)   
    ,{0,0}
#endif
};
static kal_uint32 DMA_lisr_callback_ch_bit = 0; /*suppose total DMA channel # < 32*/


#if defined(__MULTI_CORE_SHARED_DMA__) && defined(__DMA2_SUPPORT__)

/*DMA_pending_info_struct Error checking*/
#if ( DMA2_MAX_CHANNEL > 31)
    #error "Need to extern DMA2_pending_info_struct's pending_int_bit for channel account > 31"
#endif


static DMA_pending_info_struct g_DMA2_pending_info = 
{
    0,
    KAL_FALSE, 
    {0,0}
#if defined(__DMA_V3__)   
    ,{0,0}
#endif
};
static kal_uint32 DMA2_lisr_callback_ch_bit = 0; /*suppose total DMA channel # < 32*/


#endif //__MULTI_CORE_SHARED_DMA__

#endif

/*================================================================================*/
// below is the changable area
/*================================================================================*/
#ifdef MT6218
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#elif defined(MT6261) || defined(MT2501) || defined(MT2502)
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR, 
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#elif defined(MT6250)
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR, 
   DMA_ERROR_LISR, //
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR, //
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR, //
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#elif defined(MT6260)
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR, 
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#elif defined(MT6218B) || defined(MT6217)
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#elif defined(MT6223) || defined(MT6223P)
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL+2] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#elif defined(TK6516) || defined(MT6516)
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL+2] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#elif defined(MT6253T) || defined(MT6253)
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#elif defined(MT6276)
#if defined(MT6276_S00)
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#else  /*MT6276_S00*/
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#endif /*MT6276_S00*/
#elif defined(MT6256)

#if defined(MT6256_S00)
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#else
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#endif

#elif defined(MT6255)
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};

#elif defined(MT6251)
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#elif defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#elif defined(MT6573)
VOID_FUNC DMA_LISR_FUNC[DMA_ALL_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR   
};

#if defined(__DMA2_SUPPORT__)
VOID_FUNC DMA2_LISR_FUNC[DMA2_ALL_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR 
};
static kal_uint32 PHY_DMA2_MASTER[DMA2_MAX_CHANNEL] = {DMA_GDMA1, DMA_GDMA2};
#endif //__DMA2_SUPPORT__

static kal_uint32 PHY_DMA_MASTER[DMA_MAX_CHANNEL] = {DMA_SIM, DMA_SIM2};
static kal_uint32 PHY_DMA_VFF[DMA_VFF_CH_NUM] = {VDMA_UART1TX_CH, VDMA_UART1RX_CH, VDMA_UART4TX_CH, VDMA_UART4RX_CH};

#elif defined(MT6575)
VOID_FUNC DMA_LISR_FUNC[DMA_ALL_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
};

/*AP-side*/
#if defined(__DMA2_SUPPORT__)
VOID_FUNC DMA2_LISR_FUNC[DMA2_ALL_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR 
};
static kal_uint32 PHY_DMA2_MASTER[DMA2_MAX_CHANNEL] = {DMA_AP_GDMA1, DMA_AP_GDMA2, DMA_SIM, DMA_SIM2, DMA_HIF0, DMA_HIF1};
#endif //__DMA2_SUPPORT__

/*MD-side*/
static kal_uint32 PHY_DMA_MASTER[DMA_MAX_CHANNEL] = {DMA_GDMA1, DMA_GDMA2};
static kal_uint32 PHY_DMA_VFF[DMA_VFF_CH_NUM] = {VDMA_UART1TX_CH, VDMA_UART1RX_CH, VDMA_UART2TX_CH, VDMA_UART2RX_CH};

#else
VOID_FUNC DMA_LISR_FUNC[DMA_MAX_CHANNEL] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
#endif

#if defined (SPARSE_CHANNEL_GROUP)
kal_uint32 DMA_Channel_Status = DMA_CHANNEL_MASK;
#elif defined(MT6260)
kal_uint32 DMA_Channel_Status = 0x03fe;
#elif defined(MT6261) || defined(MT2501) || defined(MT2502)
kal_uint32 DMA_Channel_Status = 0x01fe;
#else
kal_uint32 DMA_Channel_Status = 0xffff;
#endif //#if defined (MT6250)
/*================================================================================*/
static DMA_GBL_CLASS dma_gbl_class_g;
static const kal_uint8 dma_gbl_class_to_grade[DMA_MAX_GBL_CLASS + 1]
   = { 0 /* CLASS 0 */, 10 /* CLASS 1 */, 50 /* CLASS 2 */, 100 /* CLASS 3 */, 200 /* CLASS 4 */ };
static kal_uint16 dma_gbl_count[DMA_MAX_GBL_CLASS]
   = { 0 /* CLASS 1 */, 0 /* CLASS 2 */, 0 /* CLASS 3 */, 0 /* CLASS 4 */ };
static const DMA_GBL_PRIORITY_BANK dma_gbl_priority_bank[DMA_GBL_TOTAL_PRIORITY_BANK]
   = { {0, 9, 1}, {10, 39, 2}, {40, 89, 3}, {90, 119, 4}, {120, 169, 5}, {170, 199, 6}, {200, 249, 7}, {250, 255, 8} };



DMA_PWRCTRL DMA_PWR;

#if defined(__MULTI_CORE_SHARED_DMA__)

DMA_Master DMA_Owner[DMA_ALL_CHANNEL];

#if defined(__DMA2_SUPPORT__)
kal_uint32 DMA2_Channel_Status = 0xffff;
DMA_PWRCTRL DMA2_PWR;
DMA_Master DMA2_Owner[DMA2_ALL_CHANNEL];
#endif //__DMA2_SUPPORT__

#if defined(__DMA_V3__)
#pragma arm section rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
static DMA_SAVE_PARAM DMA_Save_Param[DMA_ALL_CHANNEL];
#if defined(__DMA2_SUPPORT__)
static DMA_SAVE_PARAM DMA2_Save_Param[DMA2_ALL_CHANNEL];
#endif //__DMA2_SUPPORT__
#pragma arm section rwdata , rodata , zidata
#endif


#else //__MULTI_CORE_SHARED_DMA__

#if defined(MT6223) || defined(MT6223P) || defined(TK6516) || defined(MT6516)
DMA_Master DMA_Owner[DMA_MAX_CHANNEL+2];
#else
DMA_Master DMA_Owner[DMA_MAX_CHANNEL];
#endif

#if defined(__DMA_V3__)
#pragma arm section rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
static DMA_SAVE_PARAM DMA_Save_Param[DMA_MAX_CHANNEL];
#pragma arm section rwdata , rodata , zidata
#endif

#endif  //__MULTI_CORE_SHARED_DMA__

static void DMA_HISR(void);

#if !defined(__FUE__)
static void dma_Vfifo_static_RecHandler_CallBack(kal_uint32 master);
#if defined(__DMA_V3__)
static void dma_Vfifo_static_RecTimeOutHandler_CallBack(kal_uint32 master);
#endif //#if defined(__DMA_V3__)
#endif


#if defined(__MULTI_CORE_SHARED_DMA__) && defined(__DMA2_SUPPORT__)
static void DMA2_Stop(kal_uint8 channel)
{
#if defined(__DMA_V3__)
   kal_uint32 temp;

   /* E1 DMA bug: if stopping or flushing a disabled DMA channel, an unexpected interrupt will be triggered. 
       Disable interrupt control bit before stop DMA*/
   if( !DMA2_CheckRunStat(channel) )
   {
       DMA2_ACKI(channel);
       return;   
   }
   temp = DRV_Reg32(DMA2_INT_EN(channel));
   DRV_WriteReg32(DMA2_INT_EN(channel), 0);
      
   //DMA_Flush(channel);
   DMA2_Stop_Now(channel);
   DMA2_WaitUntilRdy(channel);   // => pending 1 transaction time
   DMA2_ACKI(channel);        
   
   /* E1 DMA bug: restore intr. control bit */
   DRV_WriteReg32(DMA2_INT_EN(channel), temp);   
   
#else // __DMA_V3_
	DMA2_Stop_Now(channel);
	DMA2_ACKI(channel);
#endif	// __DMA_V3_
}

void DMA2_Run(kal_uint8 channel)
{
#if defined(__DMA_V3__)
   /* E1 DMA bug */
   if( DMA2_CheckRunStat(channel) )
       ASSERT(0);

   DMA2_Stop(channel);
   DMA2_Start(channel);
#else // __DMA_V3__
   DMA2_Stop(channel);

   /* DMA bug: DMA will never stop when start DMA with zero length */
   if(  channel < DMA_VFIFO_CH_S )
       ASSERT( DMA2_GetCount(channel) != 0 );
   
   DMA2_Start(channel);
#endif // __DMA_V3_  
}

#if 0
/* under construction !*/
/* under construction !*/
   #if !defined(__FUE__)
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
   #endif /* __FUE__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #if !defined(__FUE__)
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
   #endif /* __FUE__ */
/* under construction !*/
#endif 


static kal_uint8 DMA2_GetChannel(kal_uint8 DMA_CODE)
{
   kal_uint8 handle=0xff;
   kal_uint32 savedMask;
   
#if defined(__DMA_V3__)

   savedMask = SaveAndSetIRQMask();
   if ((DMA2_Channel_Status & (0x01<<DMA_CODE)) != 0)
   {
         handle = DMA_CODE;
         DMA2_Channel_Status &= ~(0x01<<DMA_CODE);
         DMA2_Owner[handle-1] = (DMA_Master)DMA_CODE;
   }
   RestoreIRQMask(savedMask);
   
   ASSERT(handle!=0xff);

   return (handle|0x80);

#endif //// __DMA_V3_   

}


static void DMA2_FreeChannel(kal_uint8 handle)
{
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();
   DMA2_Channel_Status |= (0x01<<handle);
   DMA2_Stop(handle);
   DMA2_Owner[handle-1] = DMA_IDLE;
   RestoreIRQMask(savedMask);
}


static kal_uint8 DMA2_FullSize_GetChannel(kal_uint8 DMA_CODE)
{
   kal_uint8 handle=0xff;
   kal_uint32 savedMask;

#if defined(__DMA_V3__)

   savedMask = SaveAndSetIRQMask();

   if ((DMA2_Channel_Status & (0x01<<DMA_CODE)) != 0)
   {
       handle = DMA_CODE;
       DMA2_Channel_Status &= ~(0x01<<DMA_CODE);
	   DMA2_Owner[handle-1] = (DMA_Master)DMA_CODE;
   }
	   
   RestoreIRQMask(savedMask);

   return (handle|0x80);

#endif //__DMA_V3__   
}


static void DMA2_FullSize_FreeChannel(kal_uint8 handle)
{
   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();

   DMA2_Channel_Status |= (0x01<<handle);
   DMA2_Stop(handle);
   DMA2_Owner[handle-1] = DMA_IDLE;

   RestoreIRQMask(savedMask);
}



static void DMA2_Config_Internal(kal_uint8 dma_no, DMA_INPUT *dma_menu, kal_bool fullsize, kal_bool b2w, kal_uint8 limit, kal_bool start)
{
   kal_uint32 dma_con = 0;
   kal_uint32 temp;
   kal_uint32 _savedMask;
   kal_uint32 priority;
   DMA_GBL_CLASS dma_gbl_class;
   kal_uint8 dma_gbl, bank = 0;
   kal_uint32 rom_assert = 0;


   if (DMA2_CheckRunStat(dma_no) || DMA2_CheckITStat(dma_no))
      ASSERT(0);

   ASSERT(DMA2_Owner[dma_no - 1] != DMA_IDLE);

   if (fullsize == KAL_TRUE)
      ASSERT(b2w == KAL_FALSE);

   ASSERT(dma_menu->count <= 0xffff);

   /* DMA bug: DMA will never stop when start DMA with zero length */
   if( start == KAL_TRUE )
       ASSERT(dma_menu->count != 0);


   DMA2_Stop(dma_no);


#if !defined(__MTK_L1CACHEABLE__)
   /* check if the memory address is in cached region for ARM9 platforms */
   if (dma_menu->type == DMA_SWCOPY) {
      if (INT_QueryIsCachedRAM(((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr, 1)) {
         EXT_ASSERT(0, ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr, 0, 0);
      }
      if (INT_QueryIsCachedRAM(((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr, 1)) {
         EXT_ASSERT(0, ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr, 0, 0);
      }
   } else if (fullsize == KAL_TRUE) {
      if (INT_QueryIsCachedRAM(((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr, 1)) {
         EXT_ASSERT(0, ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr, 0, 0);
      }
      if (INT_QueryIsCachedRAM(((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr, 1)) {
         EXT_ASSERT(0, ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr, 0, 0);
      }
   } else {
      if (INT_QueryIsCachedRAM(((DMA_HWMENU *)dma_menu->menu)->addr, 1)) {
         EXT_ASSERT(0, ((DMA_HWMENU *)dma_menu->menu)->addr, 0, 0);
      }
   }
   if (dma_menu->type == DMA_HWRX_RINGBUFF || dma_menu->type == DMA_HWTX_RINGBUFF) {
      if (INT_QueryIsCachedRAM(((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO, 1)) {
         EXT_ASSERT(0, (kal_uint32)(((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT), 0, 0);
      }
      if (INT_QueryIsCachedRAM(((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO, 1)) {
         EXT_ASSERT(0, (kal_uint32)(((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT), 0, 0);
      }
   }

#endif /* !__MTK_L1CACHEABLE__ */

   if (dma_menu->type == DMA_SWCOPY) {
      if (INT_QueryIsROMSpace(((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr)) {
          //EXT_ASSERT(0, ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr, 0, 0);
          rom_assert = 1;
      }
      if (INT_QueryIsROMSpace(((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr)) {
          //EXT_ASSERT(0, ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr, 0, 0);
          rom_assert = 2;
      }
   } else if (fullsize == KAL_TRUE) {
      if (INT_QueryIsROMSpace(((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr)) {
          //EXT_ASSERT(0, ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr, 0, 0);
         rom_assert = 3;
      }
      if (INT_QueryIsROMSpace(((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr)) {
          //EXT_ASSERT(0, ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr, 0, 0);
          rom_assert = 4;
      }
   } else {
      if (INT_QueryIsROMSpace(((DMA_HWMENU *)dma_menu->menu)->addr)) {
          //EXT_ASSERT(0, ((DMA_HWMENU *)dma_menu->menu)->addr, 0, 0);
          rom_assert = 5;
      }
   }
   if (dma_menu->type == DMA_HWRX_RINGBUFF || dma_menu->type == DMA_HWTX_RINGBUFF) {
      if (INT_QueryIsROMSpace((kal_uint32)((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO)) {
          //EXT_ASSERT(0, (kal_uint32)(((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT), 0, 0);
          rom_assert = 6;
      }
   }

   if (rom_assert > 0) {
       kal_print_string_trace(MOD_IDLE, TRACE_INFO, "ESB violation, caller:%x\n", __return_address());
       EXT_ASSERT(0, rom_assert, 0, 0);
   }



   switch(dma_menu->type) {
   case  DMA_HWTX:

#if defined( __DMA_V3__)

      if (fullsize == KAL_TRUE) 
      {         
         ASSERT( dma_no <= DMA2_FULL_CH_NUM );
         DRV_WriteReg32(DMA2_SRC(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->source);
         DRV_WriteReg32(DMA2_DST(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->destination);

         if( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->fixed_raddr)
         {
            /* Fixed read access, src address must be 8byte alignment */         
            ASSERT( ( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->source & 0x7 ) == 0 );                  
            dma_con |= ((((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->rsize)&DMA_CON_SIZE_MASK)<<DMA_CON_RSIZE_OFFSET;
            dma_con |= DMA_CON_SFIX;
		    if( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->req_ack_connect)
		    {
		       DMA_FULLSIZE_HWMENU* menu = (DMA_FULLSIZE_HWMENU *)dma_menu->menu;
		       DRV_WriteReg32(DMA2_CONNECT(dma_no), (menu->req_ack_connect|menu->req_ack_dir|menu->req_ack_ratio));
		    }									
         }

         if( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->fixed_waddr)
         {
            /* Fixed write access, dst address must be 8byte alignment */         
            ASSERT( ( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->destination & 0x7 ) == 0 );                  
            dma_con |= ((((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->wsize)&DMA_CON_SIZE_MASK)<<DMA_CON_WSIZE_OFFSET;
            dma_con |= DMA_CON_DFIX;
		    if( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->req_ack_connect)
		    {
		       DMA_FULLSIZE_HWMENU* menu = (DMA_FULLSIZE_HWMENU *)dma_menu->menu;
		       DRV_WriteReg32(DMA2_CONNECT(dma_no), (menu->req_ack_connect|menu->req_ack_dir|menu->req_ack_ratio));
		    }									
         }
      }
      else
      {
         ASSERT( dma_no > DMA2_FULL_CH_NUM );
		 dma_con |= DMA_CON_TXCONTRL;

		 #if defined(__DMA_SIM_TX_RX_SUPPORT__)
		 //AB: temp solution for SIM modification
		 if((DMA_SIM & ~0x80) != dma_no && (DMA_SIM2 & ~0x80) != dma_no){
         DRV_WriteReg32(DMA2_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr);
      }
				else{
					DRV_WriteReg32(((DMA2_PGMADDR(dma_no)) + 0), ((DMA_HWMENU *)dma_menu->menu)->addr);
				}
		 #else	/* __DMA_SIM_TX_RX_SUPPORT__ */
         DRV_WriteReg32(DMA2_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr);
		 #endif /* __DMA_SIM_TX_RX_SUPPORT__ */
      }
	  
      if (dma_menu->fixed_pattern)
      {
         dma_con |= DMA_CON_FIXED_PATTERN;
      }

#else //__DMA_V3__
      if (fullsize == KAL_TRUE)
	  {
		 temp = (kal_uint32)(((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->master);
	  }
      else
	  {
		 temp = (kal_uint32)(((DMA_HWMENU *)dma_menu->menu)->master);
	  }

      dma_con |= (kal_uint32)(temp << 20);
      dma_con |= DMA_CON_TXCONTRL;
      dma_con |= DMA_CON_DRQ;


      if (fullsize == KAL_TRUE) {
         DRV_WriteReg32(DMA2_SRC(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->source);
         DRV_WriteReg32(DMA2_DST(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->destination);
      }
      else {
         DRV_WriteReg32(DMA2_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr);
         if(b2w == KAL_TRUE)
            dma_con |= DMA_CON_B2W;
      }

#endif //__DMA_V3__
      break;

   case  DMA_HWRX:
#if defined( __DMA_V3__)

      ASSERT( dma_menu->fixed_pattern == 0 );

      if (fullsize == KAL_TRUE)
      {
         ASSERT( dma_no <= DMA2_FULL_CH_NUM );
         DRV_WriteReg32(DMA2_SRC(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->source);
         DRV_WriteReg32(DMA2_DST(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->destination);

         if( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->fixed_raddr)
         {
            /* Fixed read access, src address must be 8byte alignment */
            ASSERT( ( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->source & 0x7 ) == 0 );         
            dma_con |= ((((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->rsize)&DMA_CON_SIZE_MASK)<<DMA_CON_RSIZE_OFFSET;
            dma_con |= DMA_CON_SFIX;
		    if( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->req_ack_connect)
		    {
		       DMA_FULLSIZE_HWMENU* menu = (DMA_FULLSIZE_HWMENU *)dma_menu->menu;
		       DRV_WriteReg32(DMA2_CONNECT(dma_no), (menu->req_ack_connect|menu->req_ack_dir|menu->req_ack_ratio));
		    }									
			
         }

         if( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->fixed_waddr)
         {
            /* Fixed write access, dst address must be 8byte alignment */
            ASSERT( ( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->destination & 0x7 ) == 0 );         
            dma_con |= ((((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->wsize)&DMA_CON_SIZE_MASK)<<DMA_CON_WSIZE_OFFSET;
            dma_con |= DMA_CON_DFIX;
		    if( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->req_ack_connect)
		    {
		       DMA_FULLSIZE_HWMENU* menu = (DMA_FULLSIZE_HWMENU *)dma_menu->menu;
		       DRV_WriteReg32(DMA2_CONNECT(dma_no), (menu->req_ack_connect|menu->req_ack_dir|menu->req_ack_ratio));
		    }												
         }
      }
      else
      {
         ASSERT( dma_no > DMA2_FULL_CH_NUM );
		 dma_con |= DMA_CON_RXCONTRL;
		 #if defined(__DMA_SIM_TX_RX_SUPPORT__)
		 //AB: temp solution for SIM modification		  				
		 if((DMA_SIM & ~0x80) != dma_no && (DMA_SIM2 & ~0x80) != dma_no){
         DRV_WriteReg32(DMA2_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr);
      }
				else{
					DRV_WriteReg32(((DMA2_PGMADDR(dma_no)) + 4), ((DMA_HWMENU *)dma_menu->menu)->addr);
				}
		 #else	 /* __DMA_SIM_TX_RX_SUPPORT__ */ 
         DRV_WriteReg32(DMA2_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr);
		 #endif  /* __DMA_SIM_TX_RX_SUPPORT__ */
      }

#else //__DMA_V3__

      if (fullsize == KAL_TRUE)
	  {
		 dma_con |= (kal_uint32)(((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->master) << 20;
	  }
      else
	  {
		 dma_con |= (kal_uint32)(((DMA_HWMENU *)dma_menu->menu)->master) << 20;
	  }

      dma_con |= DMA_CON_RXCONTRL;
      dma_con |= DMA_CON_DRQ;

      if (fullsize == KAL_TRUE) {
         DRV_WriteReg32(DMA2_SRC(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->source);
         DRV_WriteReg32(DMA2_DST(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->destination);
      } else {
         DRV_WriteReg32(DMA2_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr);
         if(b2w == KAL_TRUE)
            dma_con |= DMA_CON_B2W;
      }
#endif //__DMA_V3__

      break;

   case DMA_SWCOPY:
   	
#if defined( __DMA_V3__)

      DRV_WriteReg32(DMA2_SRC(dma_no), ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr);
      DRV_WriteReg32(DMA2_DST(dma_no), ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr);

      if( ((DMA_SWCOPYMENU *)dma_menu->menu)->fixed_raddr)
      {
          /* Fixed read access, src address must be 8byte alignment */
          ASSERT( ( ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr & 0x7 ) == 0 );
          dma_con |= ((((DMA_SWCOPYMENU *)dma_menu->menu)->rsize)&DMA_CON_SIZE_MASK)<<DMA_CON_RSIZE_OFFSET;
          dma_con |= DMA_CON_SFIX;
		  if( ((DMA_SWCOPYMENU *)dma_menu->menu)->req_ack_connect)
		  {
		     DMA_SWCOPYMENU* menu = (DMA_SWCOPYMENU *)dma_menu->menu;
		     DRV_WriteReg32(DMA2_CONNECT(dma_no), (menu->req_ack_connect|menu->req_ack_dir|menu->req_ack_ratio));
		  }											  		  
      }

      if( ((DMA_SWCOPYMENU *)dma_menu->menu)->fixed_waddr)
      {
          /* Fixed write access, dst address must be 8byte alignment */
          ASSERT( ( ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr & 0x7 ) == 0 );
          dma_con |= ((((DMA_SWCOPYMENU *)dma_menu->menu)->wsize)&DMA_CON_SIZE_MASK)<<DMA_CON_WSIZE_OFFSET;
          dma_con |= DMA_CON_DFIX;
		  if( ((DMA_SWCOPYMENU *)dma_menu->menu)->req_ack_connect)
		  {
		     DMA_SWCOPYMENU* menu = (DMA_SWCOPYMENU *)dma_menu->menu;
		     DRV_WriteReg32(DMA2_CONNECT(dma_no), (menu->req_ack_connect|menu->req_ack_dir|menu->req_ack_ratio));
		  }											  		  
      }

      if (dma_menu->fixed_pattern)
      {
         dma_con |= DMA_CON_FIXED_PATTERN;
      }
#else //__DMA_V3__

      DRV_WriteReg32(DMA2_SRC(dma_no), ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr);
      DRV_WriteReg32(DMA2_DST(dma_no), ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr);
      dma_con = DMA_CON_SWCOPY;
	  
#endif //__DMA_V3__

      break;

   case DMA_HWTX_RINGBUFF:

#if defined( __DMA_V3__)

     ASSERT( fullsize == KAL_TRUE && dma_no <= DMA2_FULL_CH_NUM );

     /*E1 Bug: Len1 can not be zero */
     ASSERT( ( (DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT != 0 );

     dma_con |= DMA_CON_WPEN|DMA_CON_WPSD; //RAM -> Register

     DRV_WriteReg32(DMA2_WPTO(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
     DRV_WriteReg32(DMA2_SRC(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source);
     DRV_WriteReg32(DMA2_DST(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination);

     if( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->fixed_raddr)
     {
          /* Fixed read access, src address must be 8byte alignment */
          ASSERT( ( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source & 0x7 ) == 0 );     
         dma_con |= ((((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->rsize)&DMA_CON_SIZE_MASK)<<DMA_CON_RSIZE_OFFSET;
         dma_con |= DMA_CON_SFIX;
     }
	 
     if( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->fixed_waddr)
     {
          /* Fixed write access, dst address must be 8byte alignment */
          ASSERT( ( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination & 0x7 ) == 0 );     
         dma_con |= ((((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->wsize)&DMA_CON_SIZE_MASK)<<DMA_CON_WSIZE_OFFSET;
         dma_con |= DMA_CON_DFIX;
     }

     if (dma_menu->fixed_pattern)
     {
        dma_con |= DMA_CON_FIXED_PATTERN;
     }

#else //__DMA_V3__

      if (fullsize == KAL_TRUE)
	  {
		 dma_con |= ((kal_uint32)((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->master) << 20;
	  }
      else
	  {
		 dma_con |= ((kal_uint32)((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->master) << 20;
	  }

      dma_con |= DMA_CON_TXCONTRL;
      dma_con |= DMA_CON_DRQ;

      dma_con |= DMA_CON_WPEN;   /*RAM->Register*/

      if (fullsize == KAL_TRUE) {
         DRV_WriteReg32(DMA2_WPPT(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT);
         DRV_WriteReg32(DMA2_WPTO(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
         DRV_WriteReg32(DMA2_SRC(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source);
         DRV_WriteReg32(DMA2_DST(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination);
      } else {
         DRV_WriteReg32(DMA2_WPPT(dma_no), ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT);
         DRV_WriteReg32(DMA2_WPTO(dma_no), ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
         DRV_WriteReg32(DMA2_PGMADDR(dma_no), ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->addr);
         if(b2w == KAL_TRUE)
            dma_con |= DMA_CON_B2W;
      }

#endif //__DMA_V3__

      break;

   case DMA_HWRX_RINGBUFF:

#if defined(__DMA_V3__)

     ASSERT( fullsize == KAL_TRUE && dma_no <= DMA2_FULL_CH_NUM );

     /*E1 Bug: Len1 can not be zero */
     ASSERT(( (DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT != 0 ) ;

     ASSERT( dma_menu->fixed_pattern == 0 );
      
     dma_con |= DMA_CON_WPEN;


     DRV_WriteReg32(DMA2_WPTO(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
     DRV_WriteReg32(DMA2_SRC(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source);
     DRV_WriteReg32(DMA2_DST(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination);

     if( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->fixed_raddr)
     {
         /* Fixed write access, src address must be 8byte alignment */
        ASSERT( ( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source & 0x7 ) == 0 );     
        dma_con |= ((((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->rsize)&DMA_CON_SIZE_MASK)<<DMA_CON_RSIZE_OFFSET;
        dma_con |= DMA_CON_SFIX;
     }

     if( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->fixed_waddr)
     {
         /* Fixed write access, dst address must be 8byte alignment */
         ASSERT( ( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination & 0x7 ) == 0 );     
        dma_con |= ((((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->wsize)&DMA_CON_SIZE_MASK)<<DMA_CON_WSIZE_OFFSET;
        dma_con |= DMA_CON_DFIX;
     }

#else //__DMA_V3__

      if (fullsize == KAL_TRUE)
	  {
		 dma_con |= ((kal_uint32) ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->master) << 20;
	  }
      else
	  {
		 dma_con |= ((kal_uint32) ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->master) << 20;
	  }

      dma_con |= DMA_CON_RXCONTRL;
      dma_con |= DMA_CON_DRQ;

      dma_con |= DMA_CON_WPSD;      /*Register->RAM*/
      dma_con |= DMA_CON_WPEN;

      if (fullsize == KAL_TRUE) {
         DRV_WriteReg32(DMA2_WPPT(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT);
         DRV_WriteReg32(DMA2_WPTO(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
         DRV_WriteReg32(DMA2_SRC(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source);
         DRV_WriteReg32(DMA2_DST(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination);
      } else {
         DRV_WriteReg32(DMA2_WPPT(dma_no), ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT);
         DRV_WriteReg32(DMA2_WPTO(dma_no), ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
         DRV_WriteReg32(DMA2_PGMADDR(dma_no), ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->addr);
         if(b2w == KAL_TRUE)
            dma_con |= DMA_CON_B2W;
      }
	  
#endif //__DMA_V3__

      break;

   default:

      ASSERT(0);

      break;
   }

#if defined(__DMA_V3__)

  
   if (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE 
   	 && ( dma_con & ( DMA_CON_SFIX | DMA_CON_DFIX ) ) == 0 )  /* Fixed access, burst size must be single */
   {
       if(((DMA_TMODE *)(dma_menu->menu))->cycle==0)
       {
           dma_con |= (DMA_CON_BURST_SINGLE<<DMA_CON_BURST_OFFSET);
       }
       else
       {
           dma_con |= ((((DMA_TMODE *)(dma_menu->menu))->cycle-1)&0x07)<<DMA_CON_BURST_OFFSET;
       }
   }
   else
   {
       dma_con |= (DMA_CON_BURST_SINGLE<<DMA_CON_BURST_OFFSET);
   }

   if (dma_menu->callback != NULL)
   {
       /** astone: 20120215
        * This is an intermediatly solution for wrong shard channel INT rounting during many chips.
        **/
       ASSERT(0); 

      DRV_WriteReg32(DMA2_INT_EN(dma_no), 1);
      DMA2_LISR_FUNC[dma_no-1] = dma_menu->callback;
   }
   else
   {
      DRV_WriteReg32(DMA2_INT_EN(dma_no), 0);
   }

   // keep the original bw limit setting
   //dma_con |= (*DMA_CON(dma_no)&DMA_CON_SLOW_MASK);
   //DRV_WriteReg32(DMA_CON(dma_no),dma_con);

   if(dma_menu->type!=DMA_HWTX_RINGBUFF && dma_menu->type!=DMA_HWRX_RINGBUFF)
   {
       DMA2_Save_Param[dma_no-1].len1 = ((kal_uint32)dma_menu->count)<<(dma_menu->size);
	   DMA2_Save_Param[dma_no-1].len2 = 0;
	   DMA2_Save_Param[dma_no-1].size = dma_menu->size;
	   
   }
   else
   {
       DMA2_Save_Param[dma_no-1].len1 = (((kal_uint32)((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT)<<(dma_menu->size));
	   DMA2_Save_Param[dma_no-1].len2 = ((kal_uint32)dma_menu->count-(kal_uint32)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT))<<(dma_menu->size);
	   DMA2_Save_Param[dma_no-1].size = dma_menu->size;
   }

   #if defined(__DMA_SIM_TX_RX_SUPPORT__)
   //AB: temp solution for sim modification
   if((DMA_SIM & ~0x80) != dma_no && (DMA_SIM2 & ~0x80) != dma_no){
			DRV_WriteReg32(DMA2_COUNT(dma_no),DMA2_Save_Param[dma_no-1].len1);
			DRV_WriteReg32(DMA2_WPPT(dma_no),DMA2_Save_Param[dma_no-1].len2);	
		}else{
		  	if(DMA_HWTX == dma_menu->type)
			{
				DRV_WriteReg32(DMA2_COUNT(dma_no),DMA2_Save_Param[dma_no-1].len1);
			}else{
				DRV_WriteReg32(((DMA2_COUNT(dma_no)) + 4),DMA2_Save_Param[dma_no-1].len1);
			}
		}
   #else /* __DMA_SIM_TX_RX_SUPPORT__ */
   DRV_WriteReg32(DMA2_COUNT(dma_no),DMA2_Save_Param[dma_no-1].len1);
   DRV_WriteReg32(DMA2_WPPT(dma_no),DMA2_Save_Param[dma_no-1].len2);
   #endif  /* __DMA_SIM_TX_RX_SUPPORT__ */

   if( limit != 0 )
   {
       dma_con |= (( limit << DMA_CON_SLOW_OFFSET )& DMA_CON_SLOW_MASK);
	   dma_con |= DMA_CON_SLOW_EN;
   }

   DRV_WriteReg32(DMA2_CON(dma_no),dma_con);  
   
#else //__DMA_V3__

   switch(dma_menu->size) {
   case DMA_BYTE:
      if (dma_menu->type != DMA_SWCOPY) {
         if ( (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE) &&
              (((DMA_TMODE *)(dma_menu->menu))->cycle & 0xf0) )

            dma_con |= DMA_CON_BURST_16BEAT;

         else if ( (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE) &&
                   (((DMA_TMODE *)(dma_menu->menu))->cycle & 0x08) )

            dma_con |= DMA_CON_BURST_8BEAT;
	
         else if ( (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE) &&
                   (((DMA_TMODE *)(dma_menu->menu))->cycle & 0x04) )

             dma_con |= DMA_CON_BURST_4BEAT;
      }
      break;

   case DMA_SHORT:
      if (dma_menu->type != DMA_SWCOPY) {
         if ( (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE) &&
              (((DMA_TMODE *)(dma_menu->menu))->cycle & 0xf8) )

            dma_con |= DMA_CON_BURST_8BEAT;
	
         else if ( (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE) &&
                   (((DMA_TMODE *)(dma_menu->menu))->cycle & 0x04) )

            dma_con |= DMA_CON_BURST_4BEAT;
      }
      dma_con |= DMA_CON_SIZE_SHORT;

      break;

   case DMA_LONG:
      if (dma_menu->type != DMA_SWCOPY) {

         if ( (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE) &&
              (((DMA_TMODE *)(dma_menu->menu))->cycle & 0xfc) )

            dma_con |= DMA_CON_BURST_4BEAT;
      }
      dma_con |= DMA_CON_SIZE_LONG;

      break;

   default:

      ASSERT(0);

      break;
   }

   if (dma_menu->callback != NULL)
   {
       /** astone: 20120215
        * This is an intermediatly solution for wrong shard channel INT rounting during many chips.
        **/
       ASSERT(0); 

      dma_con |= DMA_CON_ITEN;
      DMA2_LISR_FUNC[dma_no-1] = dma_menu->callback;
   }

   DRV_WriteReg32(DMA2_CON(dma_no),dma_con);
   DRV_WriteReg32(DMA2_COUNT(dma_no),(kal_uint32)dma_menu->count);

#endif //__DMA_V3__


   if (start) {

      /* configuration is done and start the DMA */

      DMA2_Start(dma_no);
   }
}


static void DMA2_Quick_Config_Bidir(  kal_uint32 dma_no, kal_uint32 dst, kal_uint32 src, kal_uint32 count, DMA_Type type )
{
    kal_uint32 dma_con = 0;

   if (DMA2_CheckRunStat(dma_no) || DMA2_CheckITStat(dma_no)) {
      ASSERT(0);
   }

   ASSERT(DMA2_Owner[dma_no - 1] != DMA_IDLE);   
   
   /* DMA bug: DMA will never stop when start DMA with zero length */
   ASSERT( count != 0 ); 

   DMA2_Stop(dma_no);

   DRV_WriteReg32(DMA2_DST(dma_no), dst);

   DRV_WriteReg32(DMA2_SRC(dma_no), src);   

#if defined(__DMA_V3__)

   DMA2_Save_Param[dma_no-1].len1 = count<<DMA2_Save_Param[dma_no-1].size;
   DRV_WriteReg32(DMA2_COUNT(dma_no),DMA2_Save_Param[dma_no-1].len1);
   
#else //__DMA_V3__

   DRV_WriteReg32(DMA2_COUNT(dma_no),count);

   if( type == DMA_HWTX )
   {
       dma_con = DRV_Reg32(DMA2_CON(dma_no));
       dma_con &= ~( DMA_CON_TXCONTRL|DMA_CON_RXCONTRL );
       dma_con |= DMA_CON_TXCONTRL;       
       DRV_WriteReg32(DMA2_CON(dma_no),dma_con);       
   }else if( type == DMA_HWRX )
   {
       dma_con = DRV_Reg32(DMA2_CON(dma_no));
       dma_con &= ~( DMA_CON_TXCONTRL|DMA_CON_RXCONTRL );
       dma_con |= DMA_CON_RXCONTRL;       
       DRV_WriteReg32(DMA2_CON(dma_no),dma_con);              
   }
#endif //__DMA_V3__
   
   DMA2_Start(dma_no);
   
}

#pragma arm section code = "INTERNCODE"

static void DMA2_Quick_Config(kal_uint32 dma_no, kal_uint32 dst)
{
   if (DMA2_CheckRunStat(dma_no) || DMA2_CheckITStat(dma_no)) {
      ASSERT(0);
   }

   ASSERT(DMA2_Owner[dma_no - 1] != DMA_IDLE);

   DMA2_Stop(dma_no);

#if defined(__DMA_V3__)
   DRV_WriteReg32(DMA2_COUNT(dma_no),DMA2_Save_Param[dma_no-1].len1);   
#else //__DMA_V3__
   /* DMA bug: DMA will never stop when start DMA with zero length */
   ASSERT( DMA2_GetCount(dma_no) != 0 );
#endif //__DMA_V3__

   DRV_WriteReg32(DMA2_DST(dma_no), dst);

   DMA2_Start(dma_no);
}

#pragma arm section

#if defined (__DMA_SUPPORT_CALLBACK_LISR__)
void DMA2_Register_RT_CallBack ( kal_uint8 dma_no ) 
{
    kal_uint32 savedMask;
    savedMask = SaveAndSetIRQMask();
    DMA2_lisr_callback_ch_bit |= (1<<dma_no);
    RestoreIRQMask(savedMask);
}

void DMA2_Unregister_RT_CallBack ( kal_uint8 dma_no ) 
{
    kal_uint32 savedMask;
    savedMask = SaveAndSetIRQMask();
    DMA2_lisr_callback_ch_bit &= ~(1<<dma_no);
	RestoreIRQMask(savedMask);
}
#endif


void DMA2_HISR(void)
{
   kal_uint8 index;

#if defined (__DMA_SUPPORT_CALLBACK_LISR__)
   kal_uint32 pend_info_idx;
   kal_uint32 savedMask;

   /*get the pending channel info and update the free_index*/
   savedMask = SaveAndSetIRQMask();
   pend_info_idx = g_DMA2_pending_info.free_index;
   g_DMA2_pending_info.hisr_activated = KAL_FALSE;
   g_DMA2_pending_info.free_index = (g_DMA2_pending_info.free_index + 1) % (sizeof(g_DMA2_pending_info.pending_int_bit)/sizeof(g_DMA2_pending_info.pending_int_bit[0]));
   /*reset the free one */
   g_DMA2_pending_info.pending_int_bit[g_DMA2_pending_info.free_index] = 0;
   #if defined(__DMA_V3__)   
   g_DMA2_pending_info.pending_int1_bit[g_DMA2_pending_info.free_index] = 0;
   #endif  
   RestoreIRQMask(savedMask);
#endif

   for(index = 0; index < DMA2_MAX_CHANNEL; index++)
	{
	   kal_uint32 index_hw;

	   index_hw = ( PHY_DMA2_MASTER[index] & 0x7F)-1;
	   
    #if defined (__DMA_SUPPORT_CALLBACK_LISR__)
        if ( g_DMA2_pending_info.pending_int_bit[pend_info_idx] & (1 << (index_hw+1)) )
        {
            DMA2_LISR_FUNC[index_hw]();
        }
		
    #else //__DMA_SUPPORT_CALLBACK_LISR__
	
    #if defined(__DMA_V3__)
       if( DRV_Reg32(DMA_GLBST_INT) & ( 1<<index_hw ) )
    #else //__DMA_V3__
	   if (DRV_Reg32(DMA2_INTSTA(index_hw+1)) & DMA_INTSTA_BIT)
    #endif //__DMA_V3__	   
	   {
	      DMA2_Stop(index_hw+1);
	      DMA2_ACKI(index_hw+1);
          DMA2_LISR_FUNC[index_hw]();
	   }
	
    #endif //__DMA_SUPPORT_CALLBACK_LISR__
	
	}

#if !defined(__FUE__) &&( defined(__DMA_UART_VIRTUAL_FIFO__) || defined(__DMA_BT_VIRTUAL_FIFO__) )
	// handle virtual fifo interrupt
	for(index=DMA_VFIFO_CH_S; index<=DMA_VFIFO_CH_E; index++)
	{
        kal_uint32 VFF_ACK =0;
        kal_uint32 index_hw;
    #if defined(__MULTI_CORE_SHARED_DMA__)		
	#if defined(DMA2_VFF_CH_NUM) && (DMA2_VFF_CH_NUM != 0)
    	index_hw = PHY_DMA2_VFF[index]; 
	#endif
    #else
        index_hw = index;
    #endif
        /*VFF Over threshold handler*/
        if ( 
    #if defined (__DMA_SUPPORT_CALLBACK_LISR__)
        g_DMA_pending_info.pending_int_bit[pend_info_idx] & (1<<index_hw) 
    #else   
         DRV_Reg32(DMA_INTSTA(index_hw) ) & DMA_INTSTA_BIT
    #endif
            )
        {
           dma_Vfifo_static_RecHandler_CallBack(
            #if defined(__DMA_V3__)   
               index_hw-1
            #else
               (DRV_Reg32(DMA_CON(index)) >> 20)
            #endif //__DMA_V3__
               );			 
		    VFF_ACK = 1;
        }
    #if defined(__DMA_V3__)   
		/* VFF flush handler */
        if ( 
    #if defined (__DMA_SUPPORT_CALLBACK_LISR__)
            g_DMA_pending_info.pending_int1_bit[pend_info_idx] & (1<<index_hw) 
    #else  
            DRV_Reg32(DMA_INTSTA(index_hw) )& DMA_INTSTA_BIT1
    #endif
            )
        {
            dma_Vfifo_static_RecTimeOutHandler_CallBack(index_hw - 1);
		    VFF_ACK = 1;
        }
    #endif //__DMA_V3__		 

    #if !defined(__DMA_SUPPORT_CALLBACK_LISR__)	  
        if( VFF_ACK == 1 )
        {
           DMA_ACKI(index_hw); 
        }	
    #endif //__DMA_SUPPORT_CALLBACK_LISR__	

	}
#endif //!__FUE__ && ( __DMA_UART_VIRTUAL_FIFO__ || __DMA_BT_VIRTUAL_FIFO__)

#if !defined(__DMA_SUPPORT_CALLBACK_LISR__)	  
#if defined(DMA2_IRQ_CODE)
	IRQClearInt(DMA2_IRQ_CODE);
	IRQUnmask(DMA2_IRQ_CODE);
#endif
#endif //__DMA_SUPPORT_CALLBACK_LISR__		
	
}



void DMA2_LISR(void)
{
   kal_uint32 index, intsta;
#if defined(DMA2_IRQ_CODE)
   IRQMask(DMA2_IRQ_CODE);
#endif

#if defined(__DMA_SUPPORT_CALLBACK_LISR__)	  
   /*get the finished DMA channel info and close channel-- start*/
   for (
        index = 0; index < DMA_MAX_CHANNEL; index++
            )
   {
	   kal_uint32 index_hw;
       
	   index_hw = ( PHY_DMA2_MASTER[index] & 0x7F) -1;
	
    #if defined(__DMA_V3__)   
       /*because interrupt flag will be 1 after DMA finishs its job even the interrupt is disabled, we need to check inten too*/
       intsta = (DRV_Reg32(DMA2_INT_EN(index_hw+1))&1) != 0 ?  DRV_Reg32(DMA2_INTSTA(index_hw+1)) : 0 ;
    #else
       intsta = DRV_Reg32(DMA2_INTSTA(index_hw+1));
    #endif
       if ( intsta & DMA_INTSTA_BIT)
       {
           /*certain channel should not income twice before it is handled in call-back*/
           EXT_ASSERT((g_DMA2_pending_info.pending_int_bit[g_DMA2_pending_info.free_index] & (1<<(index_hw+1))) == 0, 
                      g_DMA2_pending_info.pending_int_bit[g_DMA2_pending_info.free_index] , (index_hw+1), g_DMA2_pending_info.free_index);
           DMA2_ACKI(index_hw+1);
           if( DMA2_lisr_callback_ch_bit & (1<<(index_hw+1)) )
           {
              DMA2_LISR_FUNC[index_hw]();
           }
           else
	       {
	           g_DMA2_pending_info.pending_int_bit[g_DMA2_pending_info.free_index] |= (1<<(index_hw+1));
	       }
       }

   }

   #if !defined(__FUE__)   
	  for(index=DMA_VFIFO_CH_S; index<=DMA_VFIFO_CH_E; index++)
	  {
		   kal_uint32 index_hw;
	   #if defined(__MULTI_CORE_SHARED_DMA__)	   
	   #if defined(DMA2_VFF_CH_NUM) && (DMA2_VFF_CH_NUM != 0)
		   index_hw = PHY_DMA2_VFF[index]; 
	   #endif
	   #else
		   index_hw = index;
	   #endif
	  
		  #if defined(__DMA_V3__)	
		  /*because interrupt flag will be 1 after DMA finishs its job even the interrupt is disabled, we need to check inten too*/
		  intsta = (DRV_Reg32(DMA_INT_EN(index_hw))&3) != 0 ?  DRV_Reg32(DMA_INTSTA(index_hw)) : 0 ;
		  #else
		  intsta = DRV_Reg32(DMA_INTSTA(index_hw));
		  #endif
		  if ( intsta & DMA_INTSTA_BIT)
		  {
			  /*certain channel should not income twice before it is handled in call-back*/
			  EXT_ASSERT((g_DMA_pending_info.pending_int_bit[g_DMA_pending_info.free_index] & (1<<index_hw)) == 0, 
						 g_DMA_pending_info.pending_int_bit[g_DMA_pending_info.free_index] , index_hw, g_DMA_pending_info.free_index);
			  /*because VFIFO interrput never stop before buffered data is handled even ack it. So we have to disable it.*/
			  DMA_DisableINT(index_hw); 			  
			  DMA_ACKI(index_hw);
			  if(  DMA_lisr_callback_ch_bit & (1<<index_hw) )
			  {
				  dma_Vfifo_static_RecHandler_CallBack(
				   #if defined(__DMA_V3__)	 
					  index_hw-1
				   #else
					  (DRV_Reg32(DMA_CON(index_hw)) >> 20)
				   #endif
					  );			   
			  }
			  else
			  { 		  
				  g_DMA_pending_info.pending_int_bit[g_DMA_pending_info.free_index] |= (1<<index_hw);
			  }
		  }
	   #if defined(__DMA_V3__)	 
		  if( intsta & DMA_INTSTA_BIT1 )
		  {
			  /*certain channel should not income twice before it is handled in call-back*/
			  EXT_ASSERT((g_DMA_pending_info.pending_int1_bit[g_DMA_pending_info.free_index] & (1<<index_hw)) == 0, 
						 g_DMA_pending_info.pending_int1_bit[g_DMA_pending_info.free_index] , index_hw, g_DMA_pending_info.free_index);
			  /*because VFIFO interrput never stop before buffered data is handled even ack it. So we have to disable it.*/
			  DMA_DisableINT(index_hw); 			  
			  DMA_ACKI(index_hw);
			  if(  DMA_lisr_callback_ch_bit & (1<<index_hw) )
			  {
				  dma_Vfifo_static_RecTimeOutHandler_CallBack(index_hw-1);
			  }
			  else
			  { 		  
				  g_DMA_pending_info.pending_int1_bit[g_DMA_pending_info.free_index] |= (1<<index_hw);
			  }
		  }
	   #endif
	  }
   #endif //!__FUE__

   /*call DMA realtime call-back in LISR -- end*/

   if( 
   	   g_DMA2_pending_info.hisr_activated == KAL_FALSE && (
   	   g_DMA2_pending_info.pending_int_bit[g_DMA2_pending_info.free_index]
   #if defined(__DMA_V3__)  
       || g_DMA2_pending_info.pending_int1_bit[g_DMA2_pending_info.free_index] 
   #endif
       )
     )
   {
   #if !defined(__FUE__)
       drv_active_hisr(DRV_DMA2_HISR_ID);
	   g_DMA2_pending_info.hisr_activated = KAL_TRUE;
	 #else 
	 			DMA2_HISR();
	 #endif
   }
#if defined(DMA2_IRQ_CODE)
   IRQClearInt(DMA2_IRQ_CODE);
   IRQUnmask(DMA2_IRQ_CODE);
#endif
#else   //__DMA_SUPPORT_CALLBACK_LISR__

#if !defined(__FUE__)
    drv_active_hisr(DRV_DMA2_HISR_ID);
#else 
		DMA2_HISR();
#endif

#endif //__DMA_SUPPORT_CALLBACK_LISR__
}

static void DMA2_Ini(void)	
{
   kal_uint8 index;

   for (index = 0; index < DMA2_MAX_CHANNEL; index++)
      DMA2_Owner[index] = DMA_IDLE;


   for(index = 0; index < DMA2_MAX_CHANNEL; index++)
       DMA2_CH_SEL(PHY_DMA2_MASTER[index]);
   
#if defined(DMA2_VFF_CH_NUM) && (DMA2_VFF_CH_NUM != 0)
	  for(index = 0; index < DMA2_VFF_CH_NUM; index++)
		 DMA_CH_SEL(PHY_DMA2_VFF[index]);	  
#endif
   
   DMA2_POWER_ON();

#if defined(DMA2_IRQ_CODE)
   IRQ_Register_LISR(DMA2_IRQ_CODE, DMA2_LISR, "DMA2 handler");
#endif

   DRV_Register_HISR(DRV_DMA2_HISR_ID, DMA2_HISR);

#if defined(DMA2_IRQ_CODE)
   IRQSensitivity(DMA2_IRQ_CODE,LEVEL_SENSITIVE);
#endif
#if defined(DMA2_IRQ_CODE)
   IRQUnmask(DMA2_IRQ_CODE);    
#endif
}

#endif //__MULTI_CORE_SHARED_DMA__ &&  __DMA2_SUPPORT__

void DMA_Stop(kal_uint8 channel)
{
#if defined(__DMA_V3__)
   kal_uint32 temp;
#endif //#if defined(__DMA_V3__)
   
#if defined(__MULTI_CORE_SHARED_DMA__) && defined(__DMA2_SUPPORT__)
   if( (channel & 0x80) == 0x80 )
   {
      DMA2_Stop((channel&0x7F));
      return;
   }
#endif //__MULTI_CORE_SHARED_DMA__ &&  __DMA2_SUPPORT__

#if defined(__DMA_V3__)
   /* E1 DMA bug: if stopping or flushing a disabled DMA channel, an unexpected interrupt will be triggered. 
       Disable interrupt control bit before stop DMA*/
   if( !DMA_CheckRunStat(channel) )
   {
       DMA_ACKI(channel);
       return;   
   }
   temp = DRV_Reg32(DMA_INT_EN(channel));
   DRV_WriteReg32(DMA_INT_EN(channel), 0);
      
   //DMA_Flush(channel);
   DMA_Stop_Now(channel);
   DMA_WaitUntilRdy(channel);   // => pending 1 transaction time
   DMA_ACKI(channel);        
   
   /* E1 DMA bug: restore intr. control bit */
   DRV_WriteReg32(DMA_INT_EN(channel), temp);   
   
#else // __DMA_V3_
	DMA_Stop_Now(channel);
	DMA_ACKI(channel);
#endif	// __DMA_V3_
}

void DMA_Run(kal_uint8 channel)
{
#if defined(__MULTI_CORE_SHARED_DMA__) && defined(__DMA2_SUPPORT__)
   if( (channel & 0x80) == 0x80 )
   {
      DMA2_Run((channel&0x7F));
      return;
   }
#endif //__MULTI_CORE_SHARED_DMA__ &&  __DMA2_SUPPORT__

#if defined(__DMA_V3__)

   /* E1 DMA bug */
   if( DMA_CheckRunStat(channel) )
       ASSERT(0);

   DMA_Stop(channel);
   DMA_Start(channel);
#else // __DMA_V3__
   DMA_Stop(channel);

   /* DMA bug: DMA will never stop when start DMA with zero length */
   if(  channel < DMA_VFIFO_CH_S )
       ASSERT( DMA_GetCount(channel) != 0 );
   
   DMA_Start(channel);
#endif // __DMA_V3_  
}

/// new API for SIM channel workaround
void DMA_WaitforDone(kal_uint8 channel)
{
#if defined(__MULTI_CORE_SHARED_DMA__)  && defined(__DMA2_SUPPORT__)
   if( (channel & 0x80) == 0x80 )
   {
      DMA2_WaitUntilRdy((channel&0x7F));
      return;
   }
#endif //__MULTI_CORE_SHARED_DMA__ &&  __DMA2_SUPPORT__
   DMA_WaitUntilRdy(channel); 
   
   return ;
}

#if defined(__DMA_V3__)
void DMA_CleanUp(kal_uint8 channel)
{
   kal_uint32 temp;
   
#if defined(__MULTI_CORE_SHARED_DMA__) && defined(__DMA2_SUPPORT__)
   if( (channel & 0x80) == 0x80 )
   {
      DMA2_Flush((channel&0x7F));
   } 
#endif //__MULTI_CORE_SHARED_DMA__ &&  __DMA2_SUPPORT__

   if( (channel & 0x80) == 0 )
   {
       DMA_Flush(channel);
   }

   DMA_WaitforDone(channel);
}
#endif //#if defined(__DMA_V3__)

#if 0  // need to be re-defined.
/* under construction !*/
/* under construction !*/
   #if !defined(__FUE__)
/* under construction !*/
/* under construction !*/
#if defined(MT6218B)
/* under construction !*/
#endif   /*MT6218B*/
/* under construction !*/
#if defined(__MULTI_CORE_SHARED_DMA__)  && defined(__DMA2_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //__MULTI_CORE_SHARED_DMA__ &&  __DMA2_SUPPORT__
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
   #endif /* __FUE__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #if !defined(__FUE__)
/* under construction !*/
/* under construction !*/
#if defined(MT6218B)
/* under construction !*/
#endif   /*MT6218B*/
/* under construction !*/
#if defined(__MULTI_CORE_SHARED_DMA__) && defined(__DMA2_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //__MULTI_CORE_SHARED_DMA__ &&  __DMA2_SUPPORT__
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
   #endif /* __FUE__ */
/* under construction !*/
#endif //#if 0  // need to be re-defined.

kal_uint8 DMA_GetChannel(DMA_Master DMA_CODE)
{
#if !defined(MT6260) && !defined(DMA_DEDICATED_CHANNEL_GROUP)
   kal_uint8 index;
#endif   
   kal_uint8 handle=0xff;
   kal_uint32 savedMask;

#if defined(__MULTI_CORE_SHARED_DMA__) && defined(__DMA2_SUPPORT__)
   if( (DMA_CODE & 0x80) == 0x80 )
      return DMA2_GetChannel((DMA_CODE&0x7F));
#endif //__MULTI_CORE_SHARED_DMA__ &&  __DMA2_SUPPORT__

#if defined(__DMA_V3__)

   // comment for WBT, assertion to guarantee safe index for DMA_Owner[].
   ASSERT(DMA_CODE <= DMA_MAX_CHANNEL);

   savedMask = SaveAndSetIRQMask();
   if ((DMA_Channel_Status & (0x01<<DMA_CODE)) != 0)
   {
         handle = DMA_CODE;
         DMA_Channel_Status &= ~(0x01<<DMA_CODE);
         DMA_Owner[handle-1] = DMA_CODE;
   }
   RestoreIRQMask(savedMask);
   
   ASSERT(handle!=0xff);

   return handle;


#else // __DMA_V3__
   savedMask = SaveAndSetIRQMask();
#if defined(MT6260) || defined(DMA_DEDICATED_CHANNEL_GROUP)

   if(DMA_CODE == DMA_RESERVED_0 || DMA_CODE == DMA_RESERVED_1)
   		ASSERT(0); //user should not use this API to get full size DMA, this API is for Half size DMA
   		
	//PC: DMA channel start at one,  DMA_Channel_status bit0 is not useless.
   if ((DMA_Channel_Status & (0x01<<DMA_CODE)) != 0)
   {
		 handle = DMA_CODE;
		 DMA_Channel_Status &= ~(0x01<<DMA_CODE);
   }
   
   RestoreIRQMask(savedMask);
   ASSERT(handle!=0xff);
   
   //DMA_Owner index begin from 0
   if (DMA_Owner[handle-1]==DMA_CODE)
        ASSERT(0);

   DMA_Owner[handle-1] = DMA_CODE;
   return handle;  
   //PC: end
#else  //DMA_DEDICATED_CHANNEL_GROUP
   ///AST, here index is exactly the index of channel number (begin from 1)
#if defined(MT6223) || defined(MT6223P) || defined(TK6516) || defined(MT6516)
   for (index = 4; index <= DMA_MAX_CHANNEL+2; index++)
#elif defined(MT6253T) || defined(MT6253)
   for (index = 5; index <= DMA_MAX_CHANNEL; index++)
#elif defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
   for (index = 2; index <= DMA_MAX_CHANNEL; index++)
#elif defined (MT6250)
  // "-2" for workaround HIF channel that hardcored tied to channel 16/17
   for (index = 2; index <= DMA_MAX_CHANNEL-2; index++)
#else /*MT6223*/
   for (index = 4; index <= DMA_MAX_CHANNEL; index++)
#endif
   {

#if defined (MT6250)
  // workaround HIF channel that hardcored tied to channel 16/17
       if (DMA_CODE == DMA_HIF0 || DMA_CODE == DMA_HIF1) {
           if ((DMA_Channel_Status & (0x01<<DMA_CODE)) != 0)
           {
               handle = DMA_CODE;
               DMA_Channel_Status &= ~(0x01<<DMA_CODE);
               break;
           }
       }

#endif //#if defined (MT6250)
 

       ///AST, DMA_Channel_status bit0 is not useless.
      if ((DMA_Channel_Status & (0x01<<index)) != 0)
      {
         handle = index;
         DMA_Channel_Status &= ~(0x01<<index);
         break;
      }
   }
   RestoreIRQMask(savedMask);
   ASSERT(handle!=0xff);

#if defined(MT6223) || defined(MT6223P) || defined(TK6516) || defined(MT6516)
   for (index = 4; index <= DMA_MAX_CHANNEL+2; index++)
#elif defined(MT6253T) || defined(MT6253)
   for (index = 5; index <= DMA_MAX_CHANNEL; index++)
#elif defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H) || defined(MT6250)
   for (index = 2; index <= DMA_MAX_CHANNEL; index++)   	
#else
   for (index = 4; index <= DMA_MAX_CHANNEL; index++)
#endif
   {
       ///AST, DMA_Owner index begin from 0
      if (DMA_Owner[index-1]==DMA_CODE)
         ASSERT(0);
   }

   DMA_Owner[handle-1] = DMA_CODE;
   return handle;
#endif //defined(DMA_DEDICATED_CHANNEL_GROUP)   
   
#endif //// __DMA_V3_   
}

void DMA_FreeChannel(kal_uint8 handle)
{
   kal_uint32 savedMask;
#if defined(__MULTI_CORE_SHARED_DMA__) && defined(__DMA2_SUPPORT__)
   if( (handle & 0x80) == 0x80 )
   {
      DMA2_FreeChannel((handle&0x7F));
      return;
   }
#endif //__MULTI_CORE_SHARED_DMA__ &&  __DMA2_SUPPORT__
   
   // comment for WBT, assertion to guarantee safe index for DMA_Owner[].
   ASSERT(handle <= DMA_MAX_CHANNEL);

   savedMask = SaveAndSetIRQMask();
   DMA_Channel_Status |= (0x01<<handle);
   DMA_Stop(handle);
   DMA_Owner[handle-1] = DMA_IDLE;
   RestoreIRQMask(savedMask);
}

kal_uint8 DMA_FullSize_GetChannel(DMA_Master DMA_CODE)   /* Hw handler. handle = 1~3 */
{
   kal_uint8 index;
   kal_uint8 handle=0xff;
   kal_uint32 savedMask;

#if defined(__MULTI_CORE_SHARED_DMA__) && defined(__DMA2_SUPPORT__)
   if( (DMA_CODE & 0x80) == 0x80 )
      return DMA2_FullSize_GetChannel((DMA_CODE&0x7F));
#endif //__MULTI_CORE_SHARED_DMA__ &&  __DMA2_SUPPORT__

#if defined(__DMA_V3__)

   savedMask = SaveAndSetIRQMask();

#if defined(__DMA_WIFI_SUPPORT_BY_GDMA__)

   if( DMA_CODE == DMA_WIFI )
   {
       /* WIFI always uses the channel 2 */
       handle = 2;
	   DMA_Channel_Status &= ~(0x01<<handle);
	   DMA_Owner[handle-1] = DMA_CODE;
   }
   else
#endif   	
   {
       for (index = 1; index <= DMA_MAX_FULL_CHANNEL; index++)
       {
          if ((DMA_Channel_Status & (0x01<<index)) != 0)
          {
             handle = index;
             DMA_Channel_Status &= ~(0x01<<index);
             break;
          }
       }

       if(index<=DMA_MAX_FULL_CHANNEL)
       {
           /** comment for WBT: here 'handle' should be equal to 'index', that is less or equal to DMA_MAX_FULL_CHANNEL. **/
           DMA_Owner[handle-1] = DMA_CODE;
       }
   }

   RestoreIRQMask(savedMask);

   return handle;

#else // __DMA_V3__

   savedMask = SaveAndSetIRQMask();

#ifdef MT6218B
   for (index = 2; index <= DMA_MAX_FULL_CHANNEL; index++)
#else
   for (index = 1; index <= DMA_MAX_FULL_CHANNEL; index++)
#endif
   {
      if ((DMA_Channel_Status & (0x01<<index)) != 0)
      {
         handle = index;
         DMA_Channel_Status &= ~(0x01<<index);
         break;
      }
   }

   RestoreIRQMask(savedMask);

   ASSERT(handle!=0xff);

#ifdef MT6218B
   for(index=2;index<=DMA_MAX_FULL_CHANNEL;index++)
#else /*MT6218B*/
   for(index=1;index<=DMA_MAX_FULL_CHANNEL;index++)
#endif
   {
      if (DMA_Owner[index-1]==DMA_CODE)
         ASSERT(0);
   }

   DMA_Owner[handle-1] = DMA_CODE;

   return handle;
#endif //__DMA_V3__   
}

void DMA_FullSize_FreeChannel(kal_uint8 handle)
{
   kal_uint32 savedMask;

#if defined(__MULTI_CORE_SHARED_DMA__) && defined(__DMA2_SUPPORT__)
   if( (handle & 0x80) == 0x80 )
   {
      DMA2_FullSize_FreeChannel((handle&0x7F));
      return;
   }
#endif //__MULTI_CORE_SHARED_DMA__ &&  __DMA2_SUPPORT__


   savedMask = SaveAndSetIRQMask();

   DMA_Channel_Status |= (0x01<<handle);
   DMA_Stop(handle);
   DMA_Owner[handle-1] = DMA_IDLE;

   RestoreIRQMask(savedMask);
}

void DMA_Config_Internal(kal_uint8 dma_no, DMA_INPUT *dma_menu, kal_bool fullsize, kal_bool b2w, kal_uint8 limit, kal_bool start)
{
   kal_uint32 dma_con = 0;
   #if !defined(MT6260) && !defined(DMA_DEDICATED_CHANNEL_GROUP)
   kal_uint32 temp;
   #endif
   kal_uint32 _savedMask;
   kal_uint32 priority;
   DMA_GBL_CLASS dma_gbl_class;
   kal_uint8 dma_gbl, bank = 0;
   kal_uint32 rom_assert = 0;

#if defined(__MULTI_CORE_SHARED_DMA__) && defined(__DMA2_SUPPORT__)
   if( (dma_no & 0x80) == 0x80 )
   {
      DMA2_Config_Internal((dma_no&0x7F), dma_menu, fullsize, b2w, limit, start);
      return;
   }
#endif //__MULTI_CORE_SHARED_DMA__ &&  __DMA2_SUPPORT__
   

   if (DMA_CheckRunStat(dma_no) || DMA_CheckITStat(dma_no))
      ASSERT(0);

   // comment for WBT, assertion to guarantee safe index for DMA_Owner[].
   ASSERT(dma_no <= DMA_MAX_CHANNEL);
   ASSERT(DMA_Owner[dma_no - 1] != DMA_IDLE);

   if (fullsize == KAL_TRUE)
      ASSERT(b2w == KAL_FALSE);

   ASSERT(dma_menu->count <= 0xffff);

   /* DMA bug: DMA will never stop when start DMA with zero length */
   if( start == KAL_TRUE &&  dma_no < DMA_VFIFO_CH_S)
       ASSERT(dma_menu->count != 0);


   DMA_Stop(dma_no);

#if defined (__DMA_FIXED_ADDRESS_NOT_SUPPORT__)
   if (DMA_SWCOPY == dma_menu->type) {
       if (KAL_TRUE == ((DMA_SWCOPYMENU *)dma_menu->menu)->fixed_raddr) {
           EXT_ASSERT(0, ((DMA_SWCOPYMENU *)dma_menu->menu)->fixed_raddr, 0, 0);
       }

       if (KAL_TRUE == ((DMA_SWCOPYMENU *)dma_menu->menu)->fixed_waddr) {
           EXT_ASSERT(0, ((DMA_SWCOPYMENU *)dma_menu->menu)->fixed_waddr, 0, 0);
       }
   }
   
   else if (KAL_TRUE == fullsize) {
       if (dma_menu->type == DMA_HWRX_RINGBUFF || dma_menu->type == DMA_HWTX_RINGBUFF) {
           if (KAL_TRUE == ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->fixed_raddr) {
               EXT_ASSERT(0, ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->fixed_raddr, 0, 0);
           }

           if (KAL_TRUE == ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->fixed_waddr) {
               EXT_ASSERT(0, ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->fixed_waddr, 0, 0);
           }
       }
       if (dma_menu->type == DMA_HWRX || dma_menu->type == DMA_HWTX) {
           if (KAL_TRUE == ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->fixed_raddr) {
               EXT_ASSERT(0, ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->fixed_raddr, 0, 0);
           }

           if (KAL_TRUE == ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->fixed_waddr) {
               EXT_ASSERT(0, ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->fixed_waddr, 0, 0);
           }
       }
   }
#endif //defined (__DMA_FIXED_ADDRESS_NOT_SUPPORT__)


#if !defined(__MTK_L1CACHEABLE__)
   /* check if the memory address is in cached region for ARM9 platforms */
   if (dma_menu->type == DMA_SWCOPY) {
      if (INT_QueryIsCachedRAM(((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr, 1)) {
         EXT_ASSERT(0, ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr, 0, 0);
      }
      if (INT_QueryIsCachedRAM(((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr, 1)) {
         EXT_ASSERT(0, ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr, 0, 0);
      }
   } else if (fullsize == KAL_TRUE) {
      if (INT_QueryIsCachedRAM(((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr, 1)) {
         EXT_ASSERT(0, ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr, 0, 0);
      }
      if (INT_QueryIsCachedRAM(((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr, 1)) {
         EXT_ASSERT(0, ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr, 0, 0);
      }
   } else {
      if (INT_QueryIsCachedRAM(((DMA_HWMENU *)dma_menu->menu)->addr, 1)) {
         EXT_ASSERT(0, ((DMA_HWMENU *)dma_menu->menu)->addr, 0, 0);
      }
   }
   if (dma_menu->type == DMA_HWRX_RINGBUFF || dma_menu->type == DMA_HWTX_RINGBUFF) {
      if (INT_QueryIsCachedRAM(((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO, 1)) {
         EXT_ASSERT(0, (kal_uint32)(((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT), 0, 0);
      }
      if (INT_QueryIsCachedRAM(((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO, 1)) {
         EXT_ASSERT(0, (kal_uint32)(((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT), 0, 0);
      }
   }

#endif /* !__MTK_L1CACHEABLE__ */

   if (dma_menu->type == DMA_SWCOPY) {
      if (INT_QueryIsROMSpace(((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr)) {
          //EXT_ASSERT(0, ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr, 0, 0);
          rom_assert = 1;
      }
      if (INT_QueryIsROMSpace(((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr)) {
          //EXT_ASSERT(0, ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr, 0, 0);
          rom_assert = 2;
      }
   } else if (fullsize == KAL_TRUE) {
      if (INT_QueryIsROMSpace(((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr)) {
          //EXT_ASSERT(0, ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr, 0, 0);
         rom_assert = 3;
      }
      if (INT_QueryIsROMSpace(((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr)) {
          //EXT_ASSERT(0, ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr, 0, 0);
          rom_assert = 4;
      }
   } else {
      if (INT_QueryIsROMSpace(((DMA_HWMENU *)dma_menu->menu)->addr)) {
          //EXT_ASSERT(0, ((DMA_HWMENU *)dma_menu->menu)->addr, 0, 0);
          rom_assert = 5;
      }
   }
   if (dma_menu->type == DMA_HWRX_RINGBUFF || dma_menu->type == DMA_HWTX_RINGBUFF) {
      if (INT_QueryIsROMSpace((kal_uint32)((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO)) {
          //EXT_ASSERT(0, (kal_uint32)(((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT), 0, 0);
          rom_assert = 6;
      }
   }

   if (rom_assert > 0) {
       kal_print_string_trace(MOD_IDLE, TRACE_INFO, "ESB violation, caller:%x\n", __return_address());
       EXT_ASSERT(0, rom_assert, 0, 0);
   }


   switch(dma_menu->type) {
   case  DMA_HWTX:

#if defined( __DMA_V3__)

      if (fullsize == KAL_TRUE) 
      {         
         ASSERT( dma_no <= DMA_FULL_CH_NUM );
         DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->source);
         DRV_WriteReg32(DMA_DST(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->destination);

         if( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->fixed_raddr)
         {
            /* Fixed read access, src address must be 8byte alignment */         
            ASSERT( ( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->source & 0x7 ) == 0 ); 
            dma_con |= ((((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->rsize)&DMA_CON_SIZE_MASK)<<DMA_CON_RSIZE_OFFSET;
            dma_con |= DMA_CON_SFIX;
		    if( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->req_ack_connect)
		    {
		       DMA_FULLSIZE_HWMENU* menu = (DMA_FULLSIZE_HWMENU *)dma_menu->menu;
		       DRV_WriteReg32(DMA_CONNECT(dma_no), (menu->req_ack_connect|menu->req_ack_dir|menu->req_ack_ratio));
		    }						
         }

         if( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->fixed_waddr)
         {
            ASSERT( ( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->destination & 0x7 ) == 0 );
            dma_con |= ((((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->wsize)&DMA_CON_SIZE_MASK)<<DMA_CON_WSIZE_OFFSET;
            dma_con |= DMA_CON_DFIX;
		    if( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->req_ack_connect)
		    {
		       DMA_FULLSIZE_HWMENU* menu = (DMA_FULLSIZE_HWMENU *)dma_menu->menu;
		       DRV_WriteReg32(DMA_CONNECT(dma_no), (menu->req_ack_connect|menu->req_ack_dir|menu->req_ack_ratio));
		    }			
         }
      }
      else
      {
         ASSERT( dma_no > DMA_FULL_CH_NUM );
		 dma_con |= DMA_CON_TXCONTRL;

#if defined(__DMA_SIM_TX_RX_SUPPORT__)
         //AB: temp solution for SIM modification
	     if(DMA_SIM != dma_no && DMA_SIM2 != dma_no){
              DRV_WriteReg32(DMA_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr);
         }
         else{
              DRV_WriteReg32(((DMA_PGMADDR(dma_no)) + 0), ((DMA_HWMENU *)dma_menu->menu)->addr);
         }
#else  /* __DMA_SIM_TX_RX_SUPPORT__ */
         DRV_WriteReg32(DMA_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr);
#endif /* __DMA_SIM_TX_RX_SUPPORT__ */

      }
	  
      if (dma_menu->fixed_pattern)
      {
         dma_con |= DMA_CON_FIXED_PATTERN;
      }

#else //__DMA_V3__
      if (fullsize == KAL_TRUE)
	  {
		 #if defined(MT6260) || defined(DMA_DEDICATED_CHANNEL_GROUP)
			//do nothing
		 #else
			temp = (kal_uint32)(((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->master);
		 	dma_con |= (kal_uint32)(temp << 20);
		 #endif
	  }
      else
	  {
		 #if defined(MT6260) || defined(DMA_DEDICATED_CHANNEL_GROUP)
			//do nothing
		 #else
			temp = (kal_uint32)(((DMA_HWMENU *)dma_menu->menu)->master);
		 	dma_con |= (kal_uint32)(temp << 20);
		 #endif
	  }

      dma_con |= DMA_CON_TXCONTRL;
      dma_con |= DMA_CON_DRQ;

      if (fullsize == KAL_TRUE) {
         if (((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->TMOD.burst_mode) {
#ifdef MT6218
            dma_con |= DMA_CON_TMOD;
            dma_con |= (kal_uint32)(((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->TMOD.cycle) << 9;
#endif	/* MT6218 */
         }
      } else {
         if (((DMA_HWMENU *)dma_menu->menu)->TMOD.burst_mode) {
#ifdef MT6218
            dma_con |= DMA_CON_TMOD;
            dma_con |= (kal_uint32)(((DMA_HWMENU *)dma_menu->menu)->TMOD.cycle) << 9;
#endif	/* MT6218 */
         }
      }

      if (fullsize == KAL_TRUE) {
         DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->source);
         DRV_WriteReg32(DMA_DST(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->destination);
      }
      else {
         DRV_WriteReg32(DMA_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr);
#if !defined(MT6218)
         if(b2w == KAL_TRUE)
            dma_con |= DMA_CON_B2W;
#endif
      }

#endif //__DMA_V3__
      break;

   case  DMA_HWRX:
#if defined( __DMA_V3__)

      ASSERT( dma_menu->fixed_pattern == 0 );

      if (fullsize == KAL_TRUE)
      {
         ASSERT( dma_no <= DMA_FULL_CH_NUM );
         DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->source);
         DRV_WriteReg32(DMA_DST(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->destination);

         if( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->fixed_raddr)
         {
            /* Fixed write access, src address must be 8byte alignment */
            ASSERT( ( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->source & 0x7 ) == 0 );         
            dma_con |= ((((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->rsize)&DMA_CON_SIZE_MASK)<<DMA_CON_RSIZE_OFFSET;
            dma_con |= DMA_CON_SFIX;
		    if( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->req_ack_connect)
		    {
		       DMA_FULLSIZE_HWMENU* menu = (DMA_FULLSIZE_HWMENU *)dma_menu->menu;
		       DRV_WriteReg32(DMA_CONNECT(dma_no), (menu->req_ack_connect|menu->req_ack_dir|menu->req_ack_ratio));
		    }									
         }

         if( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->fixed_waddr)
         {
            /* Fixed write access, dst address must be 8byte alignment */
            ASSERT( ( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->destination & 0x7 ) == 0 );         
            dma_con |= ((((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->wsize)&DMA_CON_SIZE_MASK)<<DMA_CON_WSIZE_OFFSET;
            dma_con |= DMA_CON_DFIX;
		    if( ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->req_ack_connect)
		    {
		       DMA_FULLSIZE_HWMENU* menu = (DMA_FULLSIZE_HWMENU *)dma_menu->menu;
		       DRV_WriteReg32(DMA_CONNECT(dma_no), (menu->req_ack_connect|menu->req_ack_dir|menu->req_ack_ratio));
		    }									
			
         }
      }
      else
      {
         ASSERT( dma_no > DMA_FULL_CH_NUM );
		 dma_con |= DMA_CON_RXCONTRL;
#if defined(__DMA_SIM_TX_RX_SUPPORT__)
         //AB: temp solution for SIM modification		 
	     if(DMA_SIM != dma_no && DMA_SIM2 != dma_no){
	         DRV_WriteReg32(DMA_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr);
         }
         else{
             DRV_WriteReg32(((DMA_PGMADDR(dma_no)) + 4), ((DMA_HWMENU *)dma_menu->menu)->addr);
         }
#else 	/* __DMA_SIM_TX_RX_SUPPORT__ */ 
         DRV_WriteReg32(DMA_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr);
#endif  /* __DMA_SIM_TX_RX_SUPPORT__ */
      }

#else //__DMA_V3__

      if (fullsize == KAL_TRUE)
	  {
		 #if defined(MT6260) || defined(DMA_DEDICATED_CHANNEL_GROUP)
			//do nothing
		 #else
			dma_con |= (kal_uint32)(((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->master) << 20;
		 #endif
	  }
      else
	  {
		 #if defined(MT6260) || defined(DMA_DEDICATED_CHANNEL_GROUP)
			//do nothing
		 #else
			dma_con |= (kal_uint32)(((DMA_HWMENU *)dma_menu->menu)->master) << 20;
		 #endif
	  }

      dma_con |= DMA_CON_RXCONTRL;
      dma_con |= DMA_CON_DRQ;

      if (fullsize == KAL_TRUE) {
         if (((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->TMOD.burst_mode) {
#ifdef MT6218
            dma_con |= DMA_CON_TMOD;
            dma_con |= (kal_uint32)(((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->TMOD.cycle) << 9;
#endif	/* MT6218 */
         }
      } else {
         if (((DMA_HWMENU *)dma_menu->menu)->TMOD.burst_mode) {
#ifdef MT6218
            dma_con |= DMA_CON_TMOD;
            dma_con |= (kal_uint32)(((DMA_HWMENU *)dma_menu->menu)->TMOD.cycle) << 9;
#endif	/* MT6218 */
         }
      }

      if (fullsize == KAL_TRUE) {
         DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->source);
         DRV_WriteReg32(DMA_DST(dma_no), ((DMA_FULLSIZE_HWMENU *)dma_menu->menu)->destination);
      } else {
         DRV_WriteReg32(DMA_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr);
#if !defined(MT6218)
         if(b2w == KAL_TRUE)
            dma_con |= DMA_CON_B2W;
#endif
      }
#endif //__DMA_V3__

      break;

   case DMA_SWCOPY:
   	
#if defined( __DMA_V3__)

      DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr);
      DRV_WriteReg32(DMA_DST(dma_no), ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr);

      if( ((DMA_SWCOPYMENU *)dma_menu->menu)->fixed_raddr)
      {
          /* Fixed read access, src address must be 8byte alignment */
          ASSERT( ( ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr & 0x7 ) == 0 );
          dma_con |= ((((DMA_SWCOPYMENU *)dma_menu->menu)->rsize)&DMA_CON_SIZE_MASK)<<DMA_CON_RSIZE_OFFSET;
          dma_con |= DMA_CON_SFIX;
		  if( ((DMA_SWCOPYMENU *)dma_menu->menu)->req_ack_connect)
		  {
		     DMA_SWCOPYMENU* menu = (DMA_SWCOPYMENU *)dma_menu->menu;
		     DRV_WriteReg32(DMA_CONNECT(dma_no), (menu->req_ack_connect|menu->req_ack_dir|menu->req_ack_ratio));
		  }											  
      }

      if( ((DMA_SWCOPYMENU *)dma_menu->menu)->fixed_waddr)
      {
          /* Fixed write access, dst address must be 8byte alignment */
          ASSERT( ( ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr & 0x7 ) == 0 );
          dma_con |= ((((DMA_SWCOPYMENU *)dma_menu->menu)->wsize)&DMA_CON_SIZE_MASK)<<DMA_CON_WSIZE_OFFSET;
          dma_con |= DMA_CON_DFIX;
		  if( ((DMA_SWCOPYMENU *)dma_menu->menu)->req_ack_connect)
		  {
		     DMA_SWCOPYMENU* menu = (DMA_SWCOPYMENU *)dma_menu->menu;
		     DRV_WriteReg32(DMA_CONNECT(dma_no), (menu->req_ack_connect|menu->req_ack_dir|menu->req_ack_ratio));
		  }											  
      }

      if (dma_menu->fixed_pattern)
      {
         dma_con |= DMA_CON_FIXED_PATTERN;
      }
#else //__DMA_V3__

      DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr);
      DRV_WriteReg32(DMA_DST(dma_no), ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr);
      dma_con = DMA_CON_SWCOPY;
	  
#endif //__DMA_V3__

      break;

   case DMA_HWTX_RINGBUFF:

#if defined( __DMA_V3__)

     ASSERT( fullsize == KAL_TRUE && dma_no <= DMA_FULL_CH_NUM );

     /*E1 Bug: Len1 can not be zero */
     ASSERT( ( (DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT != 0 );

     dma_con |= DMA_CON_WPEN|DMA_CON_WPSD; //RAM -> Register

     DRV_WriteReg32(DMA_WPTO(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
     DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source);
     DRV_WriteReg32(DMA_DST(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination);

     if( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->fixed_raddr)
     {
          /* Fixed read access, src address must be 8byte alignment */
          ASSERT( ( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source & 0x7 ) == 0 );     
         dma_con |= ((((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->rsize)&DMA_CON_SIZE_MASK)<<DMA_CON_RSIZE_OFFSET;
         dma_con |= DMA_CON_SFIX;
     }
	 
     if( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->fixed_waddr)
     {
          /* Fixed write access, dst address must be 8byte alignment */
          ASSERT( ( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination & 0x7 ) == 0 );     
         dma_con |= ((((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->wsize)&DMA_CON_SIZE_MASK)<<DMA_CON_WSIZE_OFFSET;
         dma_con |= DMA_CON_DFIX;
     }

     if (dma_menu->fixed_pattern)
     {
        dma_con |= DMA_CON_FIXED_PATTERN;
     }

#else //__DMA_V3__

      if (fullsize == KAL_TRUE)
	  {
		 #if defined(MT6260) || defined(DMA_DEDICATED_CHANNEL_GROUP)
			//do nothing
		 #else
			dma_con |= ((kal_uint32)((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->master) << 20;
		 #endif
	  }
      else
	  {
		 #if defined(MT6260) || defined(DMA_DEDICATED_CHANNEL_GROUP)
			//do nothing
		 #else
			dma_con |= ((kal_uint32)((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->master) << 20;
		 #endif
	  }

      dma_con |= DMA_CON_TXCONTRL;
      dma_con |= DMA_CON_DRQ;

      if (fullsize == KAL_TRUE) {
         if (((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->TMOD.burst_mode) {
#ifdef MT6218
            dma_con |= DMA_CON_TMOD;
            dma_con |= (kal_uint32)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->TMOD.cycle) << 9;
#endif	/* MT6218 */
         }
      } else {
         if (((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->TMOD.burst_mode) {
#ifdef MT6218
            dma_con |= DMA_CON_TMOD;
            dma_con |= (kal_uint32)(((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->TMOD.cycle) << 9;
#endif	/* MT6218 */
         }
      }

      dma_con |= DMA_CON_WPEN;   /*RAM->Register*/

      if (fullsize == KAL_TRUE) {
         DRV_WriteReg32(DMA_WPPT(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT);
         DRV_WriteReg32(DMA_WPTO(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
         DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source);
         DRV_WriteReg32(DMA_DST(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination);
      } else {
         DRV_WriteReg32(DMA_WPPT(dma_no), ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT);
         DRV_WriteReg32(DMA_WPTO(dma_no), ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
         DRV_WriteReg32(DMA_PGMADDR(dma_no), ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->addr);
#if !defined(MT6218)
         if(b2w == KAL_TRUE)
            dma_con |= DMA_CON_B2W;
#endif
      }

#endif //__DMA_V3__

      break;

   case DMA_HWRX_RINGBUFF:

#if defined(__DMA_V3__)

     ASSERT( fullsize == KAL_TRUE && dma_no <= DMA_FULL_CH_NUM );

     /*E1 Bug: Len1 can not be zero */
     ASSERT(( (DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT != 0 ) ;

     ASSERT( dma_menu->fixed_pattern == 0 );
      
     dma_con |= DMA_CON_WPEN;


     DRV_WriteReg32(DMA_WPTO(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
     DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source);
     DRV_WriteReg32(DMA_DST(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination);

     if( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->fixed_raddr)
     {
         /* Fixed write access, src address must be 8byte alignment */
        ASSERT( ( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source & 0x7 ) == 0 );     
        dma_con |= ((((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->rsize)&DMA_CON_SIZE_MASK)<<DMA_CON_RSIZE_OFFSET;
        dma_con |= DMA_CON_SFIX;
     }

     if( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->fixed_waddr)
     {
         /* Fixed write access, dst address must be 8byte alignment */
         ASSERT( ( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination & 0x7 ) == 0 );     
        dma_con |= ((((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->wsize)&DMA_CON_SIZE_MASK)<<DMA_CON_WSIZE_OFFSET;
        dma_con |= DMA_CON_DFIX;
     }

#else //__DMA_V3__

      if (fullsize == KAL_TRUE)
	  {
		 #if defined(MT6260) || defined(DMA_DEDICATED_CHANNEL_GROUP)
			//do nothing
		 #else
			dma_con |= ((kal_uint32) ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->master) << 20;
		 #endif
	  }
      else
	  {
		 #if defined(MT6260) || defined(DMA_DEDICATED_CHANNEL_GROUP)
			//do nothing
		 #else
			dma_con |= ((kal_uint32) ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->master) << 20;
		 #endif
	  }

      dma_con |= DMA_CON_RXCONTRL;
      dma_con |= DMA_CON_DRQ;

      if (fullsize == KAL_TRUE) {
         if (((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->TMOD.burst_mode) {
#ifdef MT6218
            dma_con |= DMA_CON_TMOD;
            dma_con |= (kal_uint32)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->TMOD.cycle) << 9;
#endif	/* MT6218 */
         }
      } else {
         if (((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->TMOD.burst_mode) {
#ifdef MT6218
            dma_con |= DMA_CON_TMOD;
            dma_con |= (kal_uint32)(((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->TMOD.cycle) << 9;
#endif	/* MT6218 */
         }
      }

      dma_con |= DMA_CON_WPSD;      /*Register->RAM*/
      dma_con |= DMA_CON_WPEN;

      if (fullsize == KAL_TRUE) {
         DRV_WriteReg32(DMA_WPPT(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT);
         DRV_WriteReg32(DMA_WPTO(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
         DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source);
         DRV_WriteReg32(DMA_DST(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination);
      } else {
         DRV_WriteReg32(DMA_WPPT(dma_no), ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT);
         DRV_WriteReg32(DMA_WPTO(dma_no), ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
         DRV_WriteReg32(DMA_PGMADDR(dma_no), ((DMA_HWRINGBUFF_MENU *)dma_menu->menu)->addr);
#if !defined(MT6218)
         if(b2w == KAL_TRUE)
            dma_con |= DMA_CON_B2W;
#endif
      }
	  
#endif //__DMA_V3__

      break;

   default:

      ASSERT(0);

      break;
   }

#if defined(__DMA_V3__)

  
   if (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE 
   	 && ( dma_con & ( DMA_CON_SFIX | DMA_CON_DFIX ) ) == 0 )  /* Fixed access, burst size must be single */
   {
       if(((DMA_TMODE *)(dma_menu->menu))->cycle==0)
       {
           dma_con |= (DMA_CON_BURST_SINGLE<<DMA_CON_BURST_OFFSET);
       }
       else
       {
           dma_con |= ((((DMA_TMODE *)(dma_menu->menu))->cycle-1)&0x07)<<DMA_CON_BURST_OFFSET;
       }
   }
   else
   {
       dma_con |= (DMA_CON_BURST_SINGLE<<DMA_CON_BURST_OFFSET);
   }

   if (dma_menu->callback != NULL)
   {
      DRV_WriteReg32(DMA_INT_EN(dma_no), 1);
      DMA_LISR_FUNC[dma_no-1] = dma_menu->callback;
   }
   else
   {
      DRV_WriteReg32(DMA_INT_EN(dma_no), 0);
   }

   // keep the original bw limit setting
   //dma_con |= (*DMA_CON(dma_no)&DMA_CON_SLOW_MASK);
   //DRV_WriteReg32(DMA_CON(dma_no),dma_con);

   if(dma_menu->type!=DMA_HWTX_RINGBUFF && dma_menu->type!=DMA_HWRX_RINGBUFF)
   {
       DMA_Save_Param[dma_no-1].len1 = ((kal_uint32)dma_menu->count)<<(dma_menu->size);
	   DMA_Save_Param[dma_no-1].len2 = 0;
	   DMA_Save_Param[dma_no-1].size = dma_menu->size;
	   
   }
   else
   {
       DMA_Save_Param[dma_no-1].len1 = (((kal_uint32)((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT)<<(dma_menu->size));
	   DMA_Save_Param[dma_no-1].len2 = ((kal_uint32)dma_menu->count-(kal_uint32)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT))<<(dma_menu->size);
	   DMA_Save_Param[dma_no-1].size = dma_menu->size;
   }

#if defined(__DMA_SIM_TX_RX_SUPPORT__)
   //AB: temp solution for sim modification
   if(DMA_SIM != dma_no && DMA_SIM2 != dma_no)
   {
       DRV_WriteReg32(DMA_COUNT(dma_no),DMA_Save_Param[dma_no-1].len1);
       DRV_WriteReg32(DMA_WPPT(dma_no),DMA_Save_Param[dma_no-1].len2);   
   }else{
       if(DMA_HWTX == dma_menu->type)
       {
           DRV_WriteReg32(DMA_COUNT(dma_no),DMA_Save_Param[dma_no-1].len1);
       }else{
           DRV_WriteReg32(((DMA_COUNT(dma_no)) + 4),DMA_Save_Param[dma_no-1].len1);
       }
   }

#else /* __DMA_SIM_TX_RX_SUPPORT__ */
   DRV_WriteReg32(DMA_COUNT(dma_no),DMA_Save_Param[dma_no-1].len1);
   DRV_WriteReg32(DMA_WPPT(dma_no),DMA_Save_Param[dma_no-1].len2);
#endif  /* __DMA_SIM_TX_RX_SUPPORT__ */

   if( limit != 0 )
   {
       dma_con |= (( limit << DMA_CON_SLOW_OFFSET )& DMA_CON_SLOW_MASK);
	   dma_con |= DMA_CON_SLOW_EN;
   }

   DRV_WriteReg32(DMA_CON(dma_no),dma_con);  
   
#else //__DMA_V3__

   switch(dma_menu->size) {
   case DMA_BYTE:

#if !defined(MT6218)
      if (dma_menu->type != DMA_SWCOPY) {

		#if defined(MT6260) || defined(DMA_LESS_BURST_CTRL)
		 if ( (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE) &&
                   (((DMA_TMODE *)(dma_menu->menu))->cycle & 0xfc) )

             dma_con |= DMA_CON_BURST_4BEAT;
		#else
         if ( (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE) &&
              (((DMA_TMODE *)(dma_menu->menu))->cycle & 0xf0) )

            dma_con |= DMA_CON_BURST_16BEAT;

         else if ( (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE) &&
                   (((DMA_TMODE *)(dma_menu->menu))->cycle & 0x08) )

            dma_con |= DMA_CON_BURST_8BEAT;
	  
         else if ( (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE) &&
                   (((DMA_TMODE *)(dma_menu->menu))->cycle & 0x04) )

             dma_con |= DMA_CON_BURST_4BEAT;
		#endif	 
      }
#endif  /* ! MT6218 */

      break;

   case DMA_SHORT:

#if !defined(MT6218)
	#if defined(MT6260) || defined(DMA_LESS_BURST_CTRL)
		 if ( (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE) &&
                   (((DMA_TMODE *)(dma_menu->menu))->cycle & 0xfc) )

            dma_con |= DMA_CON_BURST_4BEAT;
	#else
      if (dma_menu->type != DMA_SWCOPY) {

         if ( (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE) &&
              (((DMA_TMODE *)(dma_menu->menu))->cycle & 0xf8) )

            dma_con |= DMA_CON_BURST_8BEAT;

         else if ( (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE) &&
                   (((DMA_TMODE *)(dma_menu->menu))->cycle & 0x04) )

            dma_con |= DMA_CON_BURST_4BEAT;
      }
	#endif
#endif  /* ! MT6218 */

      dma_con |= DMA_CON_SIZE_SHORT;

      break;

   case DMA_LONG:

#if !defined(MT6218)
      if (dma_menu->type != DMA_SWCOPY) {

         if ( (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE) &&
              (((DMA_TMODE *)(dma_menu->menu))->cycle & 0xfc) )

            dma_con |= DMA_CON_BURST_4BEAT;
      }
#endif  /* !MT6218 */

      dma_con |= DMA_CON_SIZE_LONG;

      break;

   default:

      ASSERT(0);

      break;
   }

   if (dma_menu->callback != NULL)
   {
      dma_con |= DMA_CON_ITEN;
      DMA_LISR_FUNC[dma_no-1] = dma_menu->callback;
   }

   DRV_WriteReg32(DMA_CON(dma_no),dma_con);
   DRV_WriteReg32(DMA_COUNT(dma_no),(kal_uint32)dma_menu->count);

   /* set the bandwidth limiter */

   _savedMask = SaveAndSetIRQMask();

   dma_gbl_class = dma_gbl_class_g;

   RestoreIRQMask(_savedMask);

   if (dma_gbl_class == 0) {

      /* full speed */

      DRV_WriteReg8(DMA_LIMITER(dma_no), 0);
   } else {

      dma_gbl = dma_gbl_class_to_grade[dma_gbl_class];

      priority = kal_get_mytask_priority();

      if (priority <= dma_gbl_priority_bank[0].upper && priority >= dma_gbl_priority_bank[0].lower)
         bank = dma_gbl_priority_bank[0].bank;
      else if (priority <= dma_gbl_priority_bank[1].upper && priority >= dma_gbl_priority_bank[1].lower)
         bank = dma_gbl_priority_bank[1].bank;
      else if (priority <= dma_gbl_priority_bank[2].upper && priority >= dma_gbl_priority_bank[2].lower)
         bank = dma_gbl_priority_bank[2].bank;
      else if (priority <= dma_gbl_priority_bank[3].upper && priority >= dma_gbl_priority_bank[3].lower)
         bank = dma_gbl_priority_bank[3].bank;
      else if (priority <= dma_gbl_priority_bank[4].upper && priority >= dma_gbl_priority_bank[4].lower)
         bank = dma_gbl_priority_bank[4].bank;
      else if (priority <= dma_gbl_priority_bank[5].upper && priority >= dma_gbl_priority_bank[5].lower)
         bank = dma_gbl_priority_bank[5].bank;
      else if (priority <= dma_gbl_priority_bank[6].upper && priority >= dma_gbl_priority_bank[6].lower)
         bank = dma_gbl_priority_bank[6].bank;
      else if (priority <= dma_gbl_priority_bank[7].upper && priority >= dma_gbl_priority_bank[7].lower)
         bank = dma_gbl_priority_bank[7].bank;
      else
         ASSERT(0);

      DRV_WriteReg8(DMA_LIMITER(dma_no), DMA_GBL_PRIORITY_2_BL(bank, dma_gbl));
   }

#if defined(MT6218B) || defined(MT6217)
   lcd_dma_slow_down(dma_gbl_class);
#endif

#endif //__DMA_V3__

   APB_DUMMY_READ();
   if (start) {

      /* configuration is done and start the DMA */

      DMA_Start(dma_no);
   }
}

void DMA_Quick_Config_Bidir(  kal_uint32 dma_no, kal_uint32 dst, kal_uint32 src, kal_uint32 count, DMA_Type type )
{
    kal_uint32 dma_con = 0;


#if defined(__MULTI_CORE_SHARED_DMA__) && defined(__DMA2_SUPPORT__)
   if( (dma_no & 0x80) == 0x80 )
   {
      DMA2_Quick_Config_Bidir((dma_no&0x7F), dst, src,count,type);
      return;
   }
#endif //__MULTI_CORE_SHARED_DMA__ &&  __DMA2_SUPPORT__

   if (DMA_CheckRunStat(dma_no) || DMA_CheckITStat(dma_no)) {
      ASSERT(0);
   }

   ASSERT(DMA_Owner[dma_no - 1] != DMA_IDLE);   
   
   /* DMA bug: DMA will never stop when start DMA with zero length */
   ASSERT( count != 0 ); 

   DMA_Stop(dma_no);

   DRV_WriteReg32(DMA_DST(dma_no), dst);

   DRV_WriteReg32(DMA_SRC(dma_no), src);   

#if defined(__DMA_V3__)

   DMA_Save_Param[dma_no-1].len1 = count<<DMA_Save_Param[dma_no-1].size;
   DRV_WriteReg32(DMA_COUNT(dma_no),DMA_Save_Param[dma_no-1].len1);
   
#else //__DMA_V3__

   DRV_WriteReg32(DMA_COUNT(dma_no),count);

   if( type == DMA_HWTX )
   {
       dma_con = DRV_Reg32(DMA_CON(dma_no));
       dma_con &= ~( DMA_CON_TXCONTRL|DMA_CON_RXCONTRL );
       dma_con |= DMA_CON_TXCONTRL;       
       DRV_WriteReg32(DMA_CON(dma_no),dma_con);       
   }else if( type == DMA_HWRX )
   {
       dma_con = DRV_Reg32(DMA_CON(dma_no));
       dma_con &= ~( DMA_CON_TXCONTRL|DMA_CON_RXCONTRL );
       dma_con |= DMA_CON_RXCONTRL;       
       DRV_WriteReg32(DMA_CON(dma_no),dma_con);              
   }
#endif //__DMA_V3__
   
   APB_DUMMY_READ();
   DMA_Start(dma_no);
   
}

#pragma arm section code = "INTERNCODE"

void DMA_Quick_Config(kal_uint32 dma_no, kal_uint32 dst)
{

#if defined(__MULTI_CORE_SHARED_DMA__) && defined(__DMA2_SUPPORT__)
   if( (dma_no & 0x80) == 0x80 )
   {
      DMA2_Quick_Config((dma_no&0x7F),dst);
      return;
   }
#endif //__MULTI_CORE_SHARED_DMA__ &&  __DMA2_SUPPORT__

   if (DMA_CheckRunStat(dma_no) || DMA_CheckITStat(dma_no)) {
      ASSERT(0);
   }

   ASSERT(DMA_Owner[dma_no - 1] != DMA_IDLE);

   DMA_Stop(dma_no);

#if defined(__DMA_V3__)
   DRV_WriteReg32(DMA_COUNT(dma_no),DMA_Save_Param[dma_no-1].len1);   
#else //__DMA_V3__
   /* DMA bug: DMA will never stop when start DMA with zero length */
   if(  dma_no < DMA_VFIFO_CH_S )   
       ASSERT( DMA_GetCount(dma_no) != 0 );
#endif //__DMA_V3__


   DRV_WriteReg32(DMA_DST(dma_no), dst);

   APB_DUMMY_READ();
   DMA_Start(dma_no);
}

#pragma arm section

void DMA_ERROR_LISR(void)
{
   while(1);
}

#if defined (__DMA_SUPPORT_CALLBACK_LISR__)
void DMA_Register_RT_CallBack ( kal_uint8 dma_no ) 
{
#if defined(__MULTI_CORE_SHARED_DMA__) && defined(__DMA2_SUPPORT__)
   if( (dma_no & 0x80) == 0x80 )
   {
      DMA2_Register_RT_CallBack((dma_no&0x7F));
      return;
   }
#endif //__MULTI_CORE_SHARED_DMA__ &&  __DMA2_SUPPORT__

#if defined(DMA_IRQ_CODE)
    IRQMask(DMA_IRQ_CODE);
#endif
    DMA_lisr_callback_ch_bit |= (1<<dma_no);
#if defined(DMA_IRQ_CODE)
    IRQUnmask(DMA_IRQ_CODE);
#endif
}

void DMA_Unregister_RT_CallBack ( kal_uint8 dma_no ) 
{
#if defined(__MULTI_CORE_SHARED_DMA__) && defined(__DMA2_SUPPORT__)
   if( (dma_no & 0x80) == 0x80 )
   {
      DMA2_Unregister_RT_CallBack((dma_no&0x7F));
      return;
   }
#endif //__MULTI_CORE_SHARED_DMA__ &&  __DMA2_SUPPORT__

#if defined(DMA_IRQ_CODE)
    IRQMask(DMA_IRQ_CODE);
#endif
    DMA_lisr_callback_ch_bit &= ~(1<<dma_no);
#if defined(DMA_IRQ_CODE)
    IRQUnmask(DMA_IRQ_CODE);
#endif
}
#endif

void DMA_HISR(void)
{
   kal_uint8 index;
   
#if defined (__DMA_SUPPORT_CALLBACK_LISR__)
   kal_uint32 pend_info_idx;
   kal_uint32 savedMask;

   /*get the pending channel info and update the free_index*/
   savedMask = SaveAndSetIRQMask();
   pend_info_idx = g_DMA_pending_info.free_index;
   g_DMA_pending_info.hisr_activated = KAL_FALSE;
   g_DMA_pending_info.free_index = (g_DMA_pending_info.free_index + 1) % (sizeof(g_DMA_pending_info.pending_int_bit)/sizeof(g_DMA_pending_info.pending_int_bit[0]));
   /*reset the free one */
   g_DMA_pending_info.pending_int_bit[g_DMA_pending_info.free_index] = 0;
    #if defined(__DMA_V3__)   
   g_DMA_pending_info.pending_int1_bit[g_DMA_pending_info.free_index] = 0;
    #endif
   RestoreIRQMask(savedMask);
#endif

#if defined(MT6223) || defined(MT6223P) || defined(TK6516) || defined(MT6516)
   for(index = 0; index < DMA_MAX_CHANNEL+2; index++)
#else /* MT6223 */
   for(index = 0; index < DMA_MAX_CHANNEL; index++)
#endif
	{
	   kal_uint32 index_hw;

    #if defined(MT6223) || defined(MT6223P) || defined(TK6516) || defined(MT6516)
       if(index == 1 || index == 2 )
          continue;
    #elif defined (SPARSE_CHANNEL_GROUP)
       if ((DMA_CHANNEL_MASK & (1<<(index+1))) == 0)
           continue;
    #endif

    #if defined(__MULTI_CORE_SHARED_DMA__)
	   index_hw = PHY_DMA_MASTER[index]-1;
    #else
       index_hw = index;
    #endif
    #if defined (__DMA_SUPPORT_CALLBACK_LISR__)
        if ( g_DMA_pending_info.pending_int_bit[pend_info_idx] & (1 << (index_hw+1)) )
        {
            DMA_LISR_FUNC[index_hw]();
        }
		
    #else //__DMA_SUPPORT_CALLBACK_LISR__
	
    #if defined(__DMA_V3__)
       if( DRV_Reg32(DMA_GLBST_INT) & ( 1<<index_hw ) )
    #else //__DMA_V3__
	   if (DRV_Reg32(DMA_INTSTA(index_hw+1)) & DMA_INTSTA_BIT)
    #endif //__DMA_V3__	   
	   {
	      DMA_Stop(index_hw+1);
	      DMA_ACKI(index_hw+1);
          DMA_LISR_FUNC[index_hw]();
	   }
	
    #endif //__DMA_SUPPORT_CALLBACK_LISR__
	
	}

#if !defined(__FUE__) &&( defined(__DMA_UART_VIRTUAL_FIFO__) || defined(__DMA_BT_VIRTUAL_FIFO__) )
	// handle virtual fifo interrupt
	for(index=DMA_VFIFO_CH_S; index<=DMA_VFIFO_CH_E; index++)
	{
        kal_uint32 VFF_ACK =0;
        kal_uint32 index_hw;
    #if defined(__MULTI_CORE_SHARED_DMA__)		
    	index_hw = PHY_DMA_VFF[index]; 
    #else
        index_hw = index;
    #endif
        /*VFF Over threshold handler*/
        if ( 
    #if defined (__DMA_SUPPORT_CALLBACK_LISR__)
        g_DMA_pending_info.pending_int_bit[pend_info_idx] & (1<<index_hw) 
    #else   
         DRV_Reg32(DMA_INTSTA(index_hw) ) & DMA_INTSTA_BIT
    #endif
            )
        {
           dma_Vfifo_static_RecHandler_CallBack(
            #if defined(__DMA_V3__)   
               index_hw-1
            #else
				#if defined(MT6260) || defined(DMA_DEDICATED_CHANNEL_GROUP)
					index_hw
				#else
					(DRV_Reg32(DMA_CON(index)) >> 20)
				#endif
            #endif //__DMA_V3__
               );			 
		    VFF_ACK = 1;
        }
    #if defined(__DMA_V3__)   
		/* VFF flush handler */
        if ( 
    #if defined (__DMA_SUPPORT_CALLBACK_LISR__)
            g_DMA_pending_info.pending_int1_bit[pend_info_idx] & (1<<index_hw) 
    #else  
            DRV_Reg32(DMA_INTSTA(index_hw) )& DMA_INTSTA_BIT1
    #endif
            )
        {
            dma_Vfifo_static_RecTimeOutHandler_CallBack(index_hw - 1);
		    VFF_ACK = 1;
        }
    #endif //__DMA_V3__		 

    #if !defined(__DMA_SUPPORT_CALLBACK_LISR__)	  
        if( VFF_ACK == 1 )
        {
           DMA_ACKI(index_hw); 
        }	
    #endif //__DMA_SUPPORT_CALLBACK_LISR__	

	}
#endif //!__FUE__ && ( __DMA_UART_VIRTUAL_FIFO__ || __DMA_BT_VIRTUAL_FIFO__)

#if !defined(__DMA_SUPPORT_CALLBACK_LISR__)	  
#if defined(DMA_IRQ_CODE)
	IRQClearInt(DMA_IRQ_CODE);
	IRQUnmask(DMA_IRQ_CODE);
#endif	
#endif //__DMA_SUPPORT_CALLBACK_LISR__		
	
}


void DMA_LISR(void)
{
#if defined(__DMA_SUPPORT_CALLBACK_LISR__)	  
    kal_uint32 index;
    kal_uint32 intsta;
#endif  //#if defined(__DMA_SUPPORT_CALLBACK_LISR__)	  

#if defined(DMA_IRQ_CODE)
   IRQMask(DMA_IRQ_CODE);
#endif

#if defined(__DMA_SUPPORT_CALLBACK_LISR__)	  
   /*get the finished DMA channel info and close channel-- start*/
   for (
   #if defined(MT6223) || defined(MT6223P) || defined(TK6516) || defined(MT6516)
        index = 0; index < DMA_MAX_CHANNEL+2; index++
   #else
        index = 0; index < DMA_MAX_CHANNEL; index++
   #endif
            )
   {
	   kal_uint32 index_hw;
       
    #if defined(MT6223) || defined(MT6223P) || defined(TK6516) || defined(MT6516)
       if(index == 1 || index == 2 )
          continue;
    #elif defined (SPARSE_CHANNEL_GROUP)
       if ((DMA_CHANNEL_MASK & (1<<(index+1))) == 0)
           continue;
    #endif
	
    #if defined(__MULTI_CORE_SHARED_DMA__)
	   index_hw = PHY_DMA_MASTER[index]-1;
    #else
       index_hw = index;
    #endif
	
    #if defined(__DMA_V3__)   
       /*because interrupt flag will be 1 after DMA finishs its job even the interrupt is disabled, we need to check inten too*/
       intsta = (DRV_Reg32(DMA_INT_EN(index_hw+1))&1) != 0 ?  DRV_Reg32(DMA_INTSTA(index_hw+1)) : 0 ;
    #else
       intsta = DRV_Reg32(DMA_INTSTA(index_hw+1));
    #endif
       if ( intsta & DMA_INTSTA_BIT)
       {
           /*certain channel should not income twice before it is handled in call-back*/
           EXT_ASSERT((g_DMA_pending_info.pending_int_bit[g_DMA_pending_info.free_index] & (1<<(index_hw+1))) == 0, 
                      g_DMA_pending_info.pending_int_bit[g_DMA_pending_info.free_index] , (index_hw+1), g_DMA_pending_info.free_index);
           DMA_ACKI(index_hw+1);
           if( DMA_lisr_callback_ch_bit & (1<<(index_hw+1)) )
           {
              DMA_LISR_FUNC[index_hw]();
           }
           else
	       {
	           g_DMA_pending_info.pending_int_bit[g_DMA_pending_info.free_index] |= (1<<(index_hw+1));
	       }
       }

   }

#if !defined(__FUE__)   
   for(index=DMA_VFIFO_CH_S; index<=DMA_VFIFO_CH_E; index++)
   {
        kal_uint32 index_hw;
    #if defined(__MULTI_CORE_SHARED_DMA__)		
    	index_hw = PHY_DMA_VFF[index]; 
    #else
        index_hw = index;
    #endif
   
       #if defined(__DMA_V3__)   
       /*because interrupt flag will be 1 after DMA finishs its job even the interrupt is disabled, we need to check inten too*/
       intsta = (DRV_Reg32(DMA_INT_EN(index_hw))&3) != 0 ?  DRV_Reg32(DMA_INTSTA(index_hw)) : 0 ;
       #else
       intsta = DRV_Reg32(DMA_INTSTA(index_hw));
       #endif
       if ( intsta & DMA_INTSTA_BIT)
       {
           /*certain channel should not income twice before it is handled in call-back*/
           EXT_ASSERT((g_DMA_pending_info.pending_int_bit[g_DMA_pending_info.free_index] & (1<<index_hw)) == 0, 
                      g_DMA_pending_info.pending_int_bit[g_DMA_pending_info.free_index] , index_hw, g_DMA_pending_info.free_index);
           /*because VFIFO interrput never stop before buffered data is handled even ack it. So we have to disable it.*/
           DMA_DisableINT(index_hw);			   
           DMA_ACKI(index_hw);
           if(  DMA_lisr_callback_ch_bit & (1<<index_hw) )
           {
               dma_Vfifo_static_RecHandler_CallBack(
                #if defined(__DMA_V3__)   
                   index_hw-1
                #else
					#if defined(MT6260) || defined(DMA_DEDICATED_CHANNEL_GROUP)
						index_hw
					#else
						(DRV_Reg32(DMA_CON(index_hw)) >> 20)
					#endif
                #endif
                   );               
           }
	       else
           {           
               g_DMA_pending_info.pending_int_bit[g_DMA_pending_info.free_index] |= (1<<index_hw);
           }
       }
    #if defined(__DMA_V3__)   
       if( intsta & DMA_INTSTA_BIT1 )
       {
           /*certain channel should not income twice before it is handled in call-back*/
           EXT_ASSERT((g_DMA_pending_info.pending_int1_bit[g_DMA_pending_info.free_index] & (1<<index_hw)) == 0, 
                      g_DMA_pending_info.pending_int1_bit[g_DMA_pending_info.free_index] , index_hw, g_DMA_pending_info.free_index);
           /*because VFIFO interrput never stop before buffered data is handled even ack it. So we have to disable it.*/
           DMA_DisableINT(index_hw);			   
           DMA_ACKI(index_hw);
           if(  DMA_lisr_callback_ch_bit & (1<<index_hw) )
           {
               dma_Vfifo_static_RecTimeOutHandler_CallBack(index_hw-1);
           }
	       else
           {           
               g_DMA_pending_info.pending_int1_bit[g_DMA_pending_info.free_index] |= (1<<index_hw);
           }
       }
    #endif
   }
#endif //!__FUE__

   /*call DMA realtime call-back in LISR -- end*/

   if( 
   	   g_DMA_pending_info.hisr_activated == KAL_FALSE && (
   	   g_DMA_pending_info.pending_int_bit[g_DMA_pending_info.free_index]
   #if defined(__DMA_V3__)  
       || g_DMA_pending_info.pending_int1_bit[g_DMA_pending_info.free_index] 
   #endif
       )
     )
   {
#if !defined(__FUE__)   
       drv_active_hisr(DRV_DMA_HISR_ID);
	   g_DMA_pending_info.hisr_activated = KAL_TRUE;
#else
			DMA_HISR();
#endif	   
   }
#if defined(DMA_IRQ_CODE) 
   IRQClearInt(DMA_IRQ_CODE);
   IRQUnmask(DMA_IRQ_CODE);
#endif
#else   //__DMA_SUPPORT_CALLBACK_LISR__

#if !defined(__FUE__)
    drv_active_hisr(DRV_DMA_HISR_ID);
#else 
		DMA_HISR();
#endif

#endif //__DMA_SUPPORT_CALLBACK_LISR__
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 
void DMA_Ini(void)
{
   kal_uint8 index;

#if defined(MT6223) || defined(MT6223P) || defined(TK6516) || defined(MT6516)
   for (index = 0; index < DMA_MAX_CHANNEL+2; index++)
#else /* MT6223 */
   for (index = 0; index < DMA_MAX_CHANNEL; index++)
#endif
      DMA_Owner[index] = DMA_IDLE;

#if defined(__MULTI_CORE_SHARED_DMA__)

   for(index = 0; index < DMA_MAX_CHANNEL; index++)
       DMA_CH_SEL(PHY_DMA_MASTER[index]);
   
   for(index = 0; index < DMA_VFF_CH_NUM; index++)
       DMA_CH_SEL(PHY_DMA_VFF[index]);

#endif //__MULTI_CORE_SHARED_DMA__

   DMA_POWER_ON();

#if defined(MT6250_S00)
   /* KeTing: Due to the bug which L2 clock depends on LZMA CG */
   PDN_CLR(PDN_LZMA);
#endif


#if defined(DMA_IRQ_CODE)
   IRQ_Register_LISR(DMA_IRQ_CODE, DMA_LISR, "DMA handler");
#endif

   DRV_Register_HISR(DRV_DMA_HISR_ID, DMA_HISR);

#if defined(DMA_IRQ_CODE)
   IRQSensitivity(DMA_IRQ_CODE,LEVEL_SENSITIVE);
#endif

#if defined(DMA_IRQ_CODE)
   IRQUnmask(DMA_IRQ_CODE);
#endif
   
#if defined(__MULTI_CORE_SHARED_DMA__) && defined(__DMA2_SUPPORT__)

   DMA2_Ini();

#endif   
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

kal_bool DMA_memcpy(const void *src, const void *dst, kal_uint32 length)
{

#if ( DMA_MAX_FULL_CHANNEL > 0 )

   kal_uint8 handle=0xff;
   DMA_INPUT input = {
       DMA_SWCOPY, DMA_BYTE, 0, 
#if defined(__DMA_API_V2__)
       KAL_FALSE, 
#endif 
       NULL, NULL
   };
   DMA_SWCOPYMENU menu = {0};

#if !defined(__MTK_L1CACHEABLE__)
   if (INT_QueryIsCachedRAM(src, length) || INT_QueryIsCachedRAM(dst, length)) {
      EXT_ASSERT(0, (kal_uint32)src, (kal_uint32)dst, length);
   }
#endif /* !__MTK_L1CACHEABLE__ */

   handle = DMA_FullSize_GetChannel(DMA_SW);
   ASSERT(handle!=0xff);

   if (handle != 0xff)
   {
      menu.srcaddr = (kal_uint32)src;
      menu.dstaddr = (kal_uint32)dst;
      input.type = DMA_SWCOPY;
      input.menu = &menu;
      input.callback = NULL;


#if defined(__DMA_V3__)
      if(length > DMA_COUNT_MAX)
         return KAL_FALSE;

      input.size = DMA_BYTE;
      input.count = length;
	  menu.TMOD.burst_mode = KAL_TRUE;
	  menu.TMOD.cycle = 8;
#else //__DMA_V3__  
      if ((menu.srcaddr|menu.dstaddr|length) & 0x01)
      {
         if(length > 0xffff)
            return KAL_FALSE;
         input.size = DMA_BYTE;
         input.count = length;
      }
      else if ((menu.srcaddr|menu.dstaddr|length) & 0x02)
      {
         if((length>>1) > 0xffff)
            return KAL_FALSE;
         input.size = DMA_SHORT;
         input.count = length>>1;
      }
      else
      {
         if((length>>2) > 0xffff)
            return KAL_FALSE;
         input.size = DMA_LONG;
         input.count = length>>2;
      }
#endif //__DMA_V3__
      DMA_FullSize_Config(handle,&input,KAL_TRUE);
      DMA_WaitforDone(handle);
      DMA_FullSize_FreeChannel(handle);
#if defined(__WRITE_THROUGH_CACHEABLE__) && ! defined(__FUE__)
/* under construction !*/
#endif /*__WRITE_THROUGH_CACHEABLE__ */

      return KAL_TRUE;
   }
   else
   {
      return KAL_FALSE;
   }
#else //DMA_MAX_FULL_CHANNEL > 0

   return KAL_FALSE;

#endif //DMA_MAX_FULL_CHANNEL > 0   

}


/*
 * This function is used to set the DMA Global Bandwidth Limiter.
 * All DMA channels' bandwidth limit will be updated.
 */
DMA_GBL_HANDLE DMA_SetGBL(DMA_GBL_CLASS dma_gbl_class)
{
#if defined(__DMA_V3__)

    /* EMI bandwidth limiter is applied, To slow down DMA is not required. */

#else //__DMA_V3__

   kal_uint8 is_update;
   kal_uint32 _savedMask;
   kal_uint8 limiter;
   kal_uint16 i;

   if (dma_gbl_class > DMA_MAX_GBL_CLASS)
      return (DMA_GBL_HANDLE)DMA_INVALID_GBL_HANDLE;

   is_update = 0;

   _savedMask = SaveAndSetIRQMask();

   if (dma_gbl_class != 0)
      dma_gbl_count[dma_gbl_class - 1]++;

   if (dma_gbl_class > dma_gbl_class_g) {
      dma_gbl_class_g = dma_gbl_class;
      is_update = 1;
   }

   RestoreIRQMask(_savedMask);

   if (is_update == 1) {

      /* need to set DMA bandwidth limit */

      limiter = dma_gbl_class_to_grade[dma_gbl_class];
#if defined (SPARSE_CHANNEL_GROUP)
      for (i = 1; i <= DMA_MAX_CHANNEL; i++) {
          if ((DMA_CHANNEL_MASK & (1<<i)) == 0)
              continue;
          DRV_WriteReg8(DMA_LIMITER(i), limiter);
      }
#else
#ifdef MT6218B
      for (i = 2; i <= DMA_MAX_CHANNEL; i++)
#elif defined(MT6223) || defined(MT6223P) || defined(TK6516) || defined(MT6516) /* MT6218B */
      DRV_WriteReg8(DMA_LIMITER(1), limiter);
      for (i = 4; i <= DMA_MAX_CHANNEL+2; i++)
#else   /* MT6218B */
      for (i = 1; i <= DMA_MAX_CHANNEL; i++)
#endif   /* MT6218B */

         DRV_WriteReg8(DMA_LIMITER(i), limiter);
#endif //#if defined (SPARSE_CHANNEL_GROUP)
#if ( defined(MT6218B) || defined(MT6217) )
      lcd_dma_slow_down(dma_gbl_class);
#endif
   }

#endif //__DMA_V3__
   return (DMA_GBL_HANDLE)dma_gbl_class;
}


/*
 * This function is used to restore the DMA Global Bandwidth Limiter.
 * All DMA channels' limiter will be updated.
 */
void DMA_RestoreGBL(DMA_GBL_HANDLE dma_gbl_handle)
{
#if defined(__DMA_V3__)

    /* EMI bandwidth limiter is applied, To slow down DMA is not required. */

#else //__DMA_V3__

   DMA_GBL_CLASS dma_gbl_class;
   kal_uint8 is_update, max;
   kal_int16 i;
   kal_uint32 _savedMask;
   kal_uint8 limiter;

   if (dma_gbl_handle == DMA_INVALID_GBL_HANDLE)
      return ;

   dma_gbl_class = (DMA_GBL_CLASS)dma_gbl_handle;

   if (dma_gbl_class > DMA_MAX_GBL_CLASS)
      return ;

   is_update = 0;

   /* update DMA GBL */

   _savedMask = SaveAndSetIRQMask();

   if (dma_gbl_class != 0)
      dma_gbl_count[dma_gbl_class - 1]--;

   max = 0;

   /* get the current max of available DMA gbl */
   for (i = DMA_MAX_GBL_CLASS - 1; i >= 0; i--) {
      if (dma_gbl_count[i] > 0) {
         max = i + 1;
         break;
      }
   }

   if (max != dma_gbl_class_g) {

      dma_gbl_class_g = max;

      is_update = 1;
   }

   RestoreIRQMask(_savedMask);

   if (is_update == 0)
      return ;
   else {

      /* need to set DMA bandwidth limit */

      limiter = dma_gbl_class_to_grade[dma_gbl_class];

#if defined (SPARSE_CHANNEL_GROUP)
      for (i = 1; i <= DMA_MAX_CHANNEL; i++) {
          if ((DMA_CHANNEL_MASK & (1<<i)) == 0)
              continue;
          DRV_WriteReg8(DMA_LIMITER(i), limiter);
      }
#else  //#if defined (SPARSE_CHANNEL_GROUP)
#ifdef MT6218B
      for (i = 2; i <= DMA_MAX_CHANNEL; i++)
#elif defined(MT6223) || defined(MT6223P) || defined(TK6516) || defined(MT6516)/* MT6218B */
      DRV_WriteReg8(DMA_LIMITER(1), limiter);
      for (i = 4; i <= DMA_MAX_CHANNEL+2; i++)
#else /* MT6218B */
      for (i = 1; i <= DMA_MAX_CHANNEL; i++)
#endif /* MT6218B */

#if defined(__DMA_V3__)
         DRV_WriteReg32(DMA_LIMITER(i), (DRV_Reg32(DMA_LIMITER(i))&(~DMA_CON_SLOW_MASK)) | (limiter<<DMA_CON_SLOW_OFFSET));
#else //__DMA_V3__
         DRV_WriteReg8(DMA_LIMITER(i), limiter);
#endif// __DMA_V3__

#endif //#if defined (SPARSE_CHANNEL_GROUP)

#if ( defined(MT6218B) || defined(MT6217) )
      lcd_dma_slow_down(dma_gbl_class);
#endif
   }

#endif //__DMA_V3__   
}

kal_bool DMA_Valid_Addr_Chk(const void *src, kal_uint32 length)
{
#if defined(MT6276)
	if(((kal_uint32)(src) < 0x3FFFFFFF) && 
		/*check if across bank boundary*/
		((((kal_uint32)(src)+length) & ((kal_uint32)(src)& 0xF0000000))==((kal_uint32)(src)& 0xF0000000)))
	{
	  return KAL_TRUE;
	}
	else
	{
	  return KAL_FALSE;
	}
#else
	{
	  return KAL_TRUE;
	}
#endif /*MT6276*/
}

#endif  /* MT6205 || MT6208 || MT6205B || FPGA */



#ifdef MT6218B

/*
* FUNCTION
*	dma_ch1_init
*
* DESCRIPTION
*  This function is used to initialize DMA channel 1.
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
 */
void dma_ch1_init(kal_uint32 dstaddr, kal_uint16 len, kal_uint8 limiter)
{
   DRV_WriteReg32(DMA_DST(1), dstaddr);

   DRV_WriteReg32(DMA_COUNT(1), (kal_uint32)len);

   DRV_WriteReg32(DMA_CON(1), 0 | DMA_CON_SIZE_BYTE | DMA_CON_SINC);

   DRV_WriteReg32(DMA_LIMITER(1),limiter);
}

/*
 * This function is used to start DMA channel 1 for transfer.
 */
void dma_ch1_start(kal_uint32 srcaddr)
{
   DMA_Stop_Now(1);

   DMA_ACKI(1);

   DRV_WriteReg32(DMA_SRC(1), srcaddr);

   DMA_Start(1);
}

/*
 * This function is used to stop transfer of DMA channel 1.
 */
void dma_ch1_stop()
{
   DMA_Stop_Now(1);

   DMA_ACKI(1);
}

#endif   /* MT6218B */


#if !defined(__FUE__)
static kal_uint32 dma_slowdown_handle;
static kal_uint32 dma_slowdown_mask;

kal_uint8 dma_slowdown_get_handle(void)
{
   ASSERT(dma_slowdown_handle<32);
   return dma_slowdown_handle++;
}

void dma_slowdown(kal_uint8 handle)
{
#if defined(__DMA_V3__)

    /* EMI bandwidth limiter is applied, To slow down DMA is not required. */

#else //__DMA_V3__

   kal_uint32 _savedMask;

   _savedMask = SaveAndSetIRQMask();

   if (dma_slowdown_mask == 0)
   {
      /* Enable WT slowdown */
#if defined(MT6223) || defined(MT6223P)
      *(volatile kal_uint32*)0x80000700 |= 0xFF << 1;
#endif

#if defined(TK6516) || defined(MT6516)

      DRV_WriteReg32(DMA_LIMITER(1),0xff);
      DRV_WriteReg32(DMA_LIMITER(4),0xc8);
      DRV_WriteReg32(DMA_LIMITER(5),0xc8);

#else /* TK6516 || MT6516  */

      che_slowdown();

      /*
       * Original lcd_dma_slow_down(void) internally uses 0x3F as command
       * latency. Here we pass "4" to new lcd_dma_slow_down(level) such that
       * the command latency is longer than before.
       */

#if defined(MT6218B) || defined(MT6217) || defined(MT6223) || defined(MT6223P) || defined(MT6238) || defined(MT6239)
      {
         kal_uint8 index;

#if !defined(MT6238) && !defined(MT6239)
         lcd_dma_slow_down(DMA_GBL_CLASS4);
#endif

#if defined(MT6218B) || defined(__DIRECT_SENSOR_SUPPORT__)
         /* nop */
#else   /* MT6218B || __DIRECT_SENSOR_SUPPORT__ */
         DRV_WriteReg32(DMA_LIMITER(1),0xff);
#endif   /* MT6218B || __DIRECT_SENSOR_SUPPORT__ */

#if defined(MT6223)  || defined(MT6223P)
         /* DMA_MAX_CHANNEL = 6; Note DMA channel of MT6223 is not contiguous, ie.DMA 1,4,5,6,7,8 */
         for(index = 4; index <= DMA_MAX_CHANNEL+2; index++)
#else  /* MT6223 || defined(MT6223P)*/
         DRV_WriteReg32(DMA_LIMITER(2),0xff);

         DRV_WriteReg32(DMA_LIMITER(3),0xff);

         for(index = 4; index <= DMA_MAX_CHANNEL; index++)
#endif /* MT6223 || defined(MT6223P)*/
         {
            #if defined (SPARSE_CHANNEL_GROUP)
             if ((DMA_CHANNEL_MASK & (1<<index)) == 0)
                 continue;
            #endif  //#if defined (SPARSE_CHANNEL_GROUP)
            DRV_WriteReg32(DMA_LIMITER(index),0xc8);
         }
      }

#elif defined(MT6208) || defined(MT6205B)   /* MT6218B || MT6217 || MT6223 */

      lcd_dma_slow_down(4);

#endif   /* MT6218B || MT6217 || MT6223 || MT6223P */

#endif /* TK6516 || MT6516  */
   }

   dma_slowdown_mask |= (1 << handle);

   RestoreIRQMask(_savedMask);
#endif //__DMA_V3__   
}

/*
* FUNCTION
*	dma_recover
*
* DESCRIPTION
*  Recover DMA limiter
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*/
void dma_recover(kal_uint8 handle)
{

#if defined(__DMA_V3__)

    /* EMI bandwidth limiter is applied, To slow down DMA is not required. */

#else //__DMA_V3__

   kal_uint32 _savedMask;

   _savedMask = SaveAndSetIRQMask();

   dma_slowdown_mask &= ~(1 << handle);

   if (dma_slowdown_mask == 0)
   {
#if defined(TK6516)  || defined(MT6516)

      {
         kal_uint8 limiter;
         limiter = dma_gbl_class_to_grade[dma_gbl_class_g];
         DRV_WriteReg32(DMA_LIMITER(1), limiter);
         DRV_WriteReg32(DMA_LIMITER(4), limiter);
         DRV_WriteReg32(DMA_LIMITER(5), limiter);
      }

#else /* TK6516 || MT6516 */
      che_recover();

#if defined(MT6208) || defined(MT6205B) || defined(MT6218B) || defined(MT6217) || defined(MT6223) || defined(MT6223P)
      lcd_dma_recovery();
#endif   /* MT6208 || MT6205B || MT6218B || MT6217 || MT6223 || MT6223P */

#if defined(MT6218B) || defined(MT6217) || defined(MT6223) || defined(MT6223P) || defined(MT6238) || defined(MT6239)
      {
         kal_uint8 index;
         kal_uint8 limiter;

         limiter = dma_gbl_class_to_grade[dma_gbl_class_g];

#ifdef MT6218B
         for(index = 2; index <= DMA_MAX_CHANNEL; index++)
         {
#elif defined(MT6223) || defined(MT6223P)   /* MT6218B */
#if !defined(__DIRECT_SENSOR_SUPPORT__)
         DRV_WriteReg32(DMA_LIMITER(1), limiter);
#endif
         for(index = 4; index <= DMA_MAX_CHANNEL+2; index++)
         {
#else   /* MT6218B */
         for(index = 1; index <= DMA_MAX_CHANNEL; index++)
         {
#endif   /* MT6218B */
            #if defined (SPARSE_CHANNEL_GROUP)
             if ((DMA_CHANNEL_MASK & (1<<index)) == 0)
                 continue;
            #endif  //#if defined (SPARSE_CHANNEL_GROUP)
            DRV_WriteReg32(DMA_LIMITER(index), limiter);
         }
      }
#endif   /* MT6218B || MT6217 || MT6223 */

	    /* Enable WT slowdown */
#if defined(MT6223) || defined(MT6223P)
         /// clear WT_SDCNT (wavetable slowdown count)
         *ACIF_CON0 &= ~0x1FE;
#endif

#endif /* TK6516 || MT6516  */
   }

   RestoreIRQMask(_savedMask);
#endif //__DMA_V3__   
}



/*
* FUNCTION
*	dma_Vfifo_static_RecHandler_CallBack
*
* DESCRIPTION
*  To call Vfifo static RecHandler CallBack
*
* CALLS
*
* PARAMETERS
*	master
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*/
void dma_Vfifo_static_RecHandler_CallBack(kal_uint32 master)
{
#if !defined(__FUE__)

    switch( (master) )
    {
#if defined(__DMA_UART_VIRTUAL_FIFO__)			    
		case DMA_CON_MASTER_UART1RX:
			UART_RecHandler_VFIFO(uart_port1);
			break;
		case DMA_CON_MASTER_UART1TX:
			UART_TrxHandler_VFIFO(uart_port1);
			break;
		case DMA_CON_MASTER_UART2RX:
			UART_RecHandler_VFIFO(uart_port2);
			break;
		case DMA_CON_MASTER_UART2TX:
			UART_TrxHandler_VFIFO(uart_port2);
			break;
#if defined(DMA_CON_MASTER_UART3RX)
		case DMA_CON_MASTER_UART3RX:
			UART_RecHandler_VFIFO(uart_port3);
			break;
#endif /*DMA_CON_MASTER_UART3RX */
#if defined(DMA_CON_MASTER_UART3TX)
		case DMA_CON_MASTER_UART3TX:
			UART_TrxHandler_VFIFO(uart_port3);
			break;
#endif /*DMA_CON_MASTER_UART3TX */		
#if defined(DMA_CON_MASTER_UART4RX)
		case DMA_CON_MASTER_UART4RX:
			UART_RecHandler_VFIFO(DMA_REMP_UART_PORT4);
			break;			
#endif /* DMA_CON_MASTER_UART4RX */
#if defined(DMA_CON_MASTER_UART4TX)
		case DMA_CON_MASTER_UART4TX:
			UART_TrxHandler_VFIFO(DMA_REMP_UART_PORT4);
			break;
#endif /* DMA_CON_MASTER_UART4TX */

#endif //__DMA_UART_VIRTUAL_FIFO__					
#if defined(__DMA_BT_VIRTUAL_FIFO__)
		case DMA_CON_MASTER_BTIFTX:
			BTIF_DMA_TX_Threshold_Handler_VFIFO(); //Flush and threadhold handler
			break;
		case DMA_CON_MASTER_BTIFRX:
			BTIF_DMA_RX_Threshold_Handler_VFIFO();
			break;
#endif //__DMA_BT_VIRTUAL_FIFO__					
    }

#endif //!__FUE__
}
/*
* FUNCTION
*	dma_Vfifo_static_RecTimeOutHandler_CallBack
*
* DESCRIPTION
*  To call Vfifo static RecTimeOutHandler CallBack
*
* CALLS
*
* PARAMETERS
*	master
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*/
#if defined(__DMA_V3__)
void dma_Vfifo_static_RecTimeOutHandler_CallBack(kal_uint32 master)
{
#if defined (__DMA_V3__) && !defined(__FUE__) 
    switch( (master) )
    {
#if defined(__DMA_UART_VIRTUAL_FIFO__)			    			    
		case DMA_CON_MASTER_UART1RX:
			UART_RecTimeOutHandler(uart_port1);
			break;
		case DMA_CON_MASTER_UART2RX:
			UART_RecTimeOutHandler(uart_port2);
			break;
	#if defined(DMA_CON_MASTER_UART3RX)
		case DMA_CON_MASTER_UART3RX:
			UART_RecTimeOutHandler(uart_port3);
			break;
	#endif
#endif	//__DMA_UART_VIRTUAL_FIFO__		
#if defined(__DMA_BT_VIRTUAL_FIFO__)
		case DMA_CON_MASTER_BTIFTX:
			BTIF_DMA_TX_Threshold_Handler_VFIFO(); //Flush and threadhold handler
			break;
		case DMA_CON_MASTER_BTIFRX:
			BTIF_DMA_RX_Threshold_Handler_VFIFO();
			break;					
#endif	//__DMA_UART_VIRTUAL_FIFO__												
    }
#endif //__DMA_V3__ && !__FUE__
}
#endif

#if defined(__RTL_SIMULATION_FOR_60QBIT__)

#include "ebm_if.h"

static EBM_LOG_T dma_slowdown_ibus_log, dma_slowdown_dbus_log;
static EBM_LOG_T dma_recover_ibus_log, dma_recover_dbus_log;
extern void	cp15_clean_dcache(void);
extern void cp15_invalidate_icache(void);
extern void test_lcd_dma_init( void );
extern void test_lcd_dma_slow_down(kal_uint8 level);
extern void test_lcd_dma_recovery(void);


/*
 * DMA slowdown test code.
 */
void test_dma_slowdown( void )
{
   kal_uint32 _savedMask;
   kal_uint8 handle = 0;

    /*Initialize lcd variable to force enter worst path*/
    test_lcd_dma_init();
    dma_slowdown_mask = 0;
    EBM_INIT();

    /* invalidate and clean ICACHE && DCACHE */
    cp15_clean_dcache();
    cp15_invalidate_icache();

    EBM_START();

   _savedMask = SaveAndSetIRQMask();

   if (dma_slowdown_mask == 0)
   {

      che_slowdown();

      /*
       * Original lcd_dma_slow_down(void) internally uses 0x3F as command
       * latency. Here we pass "4" to new lcd_dma_slow_down(level) such that
       * the command latency is longer than before.
       */

      {
         kal_uint8 index;

         test_lcd_dma_slow_down(DMA_GBL_CLASS4);

#if defined(__DMA_V3__)

         for(index = 1; index <= DMA_MAX_CHANNEL; index++)
         {
			DRV_WriteReg32(DMA_LIMITER(index), (DRV_Reg32(DMA_LIMITER(index))&(~DMA_CON_SLOW_MASK)) | (0xc8<<DMA_CON_SLOW_OFFSET));
         }        

#else //__DMA_V3__

         DRV_WriteReg32(DMA_LIMITER(1),0xff);

         DRV_WriteReg32(DMA_LIMITER(2),0xff);

         DRV_WriteReg32(DMA_LIMITER(3),0xff);

         for(index = 4; index <= DMA_MAX_CHANNEL; index++)
         {
            #if defined (SPARSE_CHANNEL_GROUP)
             if ((DMA_CHANNEL_MASK & (1<<index)) == 0)
                 continue;
            #endif  //#if defined (SPARSE_CHANNEL_GROUP)
            DRV_WriteReg32(DMA_LIMITER(index),0xc8);
         }
#endif //__DMA_V3__		 
      }


   }

   dma_slowdown_mask |= (1 << handle);

   RestoreIRQMask(_savedMask);    

      
    EBM_PAUSE();
    EBM_GET_MCU_IBUS_LOG(&dma_slowdown_ibus_log);
    EBM_GET_MCU_DBUS_LOG(&dma_slowdown_dbus_log);

    EBM_STOP();   
	
}

/*
 * DMA recover 60 qbit test code.
 */
void test_dma_recover( void )
{
   kal_uint32 _savedMask;
   kal_uint8 handle = 0;

    /*Initialize lcd variable to force enter worst path*/
    test_lcd_dma_init();
    dma_slowdown_mask = 0;

    EBM_INIT();


    /* invalidate and clean ICACHE && DCACHE */
    cp15_clean_dcache();
    cp15_invalidate_icache();

    EBM_START();

   _savedMask = SaveAndSetIRQMask();

   dma_slowdown_mask &= ~(1 << handle);

   if (dma_slowdown_mask == 0)
   {
      che_recover();

      test_lcd_dma_recovery();

      {
         kal_uint8 index;
         kal_uint8 limiter;

         limiter = dma_gbl_class_to_grade[dma_gbl_class_g];

         for(index = 1; index <= DMA_MAX_CHANNEL; index++)
         {

#if defined(__DMA_V3__)
            DRV_WriteReg32(DMA_LIMITER(index), (DRV_Reg32(DMA_LIMITER(index))&(~DMA_CON_SLOW_MASK)) | (limiter<<DMA_CON_SLOW_OFFSET));
#else //__DMA_V3__
            #if defined (SPARSE_CHANNEL_GROUP)
             if ((DMA_CHANNEL_MASK & (1<<index)) == 0)
                 continue;
            #endif  //#if defined (SPARSE_CHANNEL_GROUP)
            DRV_WriteReg32(DMA_LIMITER(index), limiter);
#endif //__DMA_V3__
         }
      }

   }

   RestoreIRQMask(_savedMask);
   
    EBM_PAUSE();
    EBM_GET_MCU_IBUS_LOG(&dma_recover_ibus_log);
    EBM_GET_MCU_DBUS_LOG(&dma_recover_dbus_log);

    EBM_STOP();   
}

#endif //__RTL_SIMULATION_FOR_60QBIT__

/*
* FUNCTION
*	dma_recover_all
*
* DESCRIPTION
*  Recover all DMA limiter
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*/
void dma_recover_all()
{
   kal_uint32 _savedMask;
   kal_uint8 index;

#if !defined( __MULTI_CORE_SHARED_DMA__)

#if !defined(MT6205B) && !defined(MT6208)
   kal_uint8 limiter;
#endif

   _savedMask = SaveAndSetIRQMask();

#if defined(MT6205B) || defined(MT6218B) || defined(MT6217) || defined(MT6223) || defined(MT6223P)
      lcd_dma_recovery();
#endif

#if !defined(MT6205B) && !defined(MT6208)

   limiter = dma_gbl_class_to_grade[dma_gbl_class_g];

#ifdef MT6218B
   for(index = 2; index <= DMA_MAX_CHANNEL; index++) {
#elif defined(MT6223)  || defined(MT6223P) || defined(TK6516) || defined(MT6516) /* MT6218B */
#if !defined(__DIRECT_SENSOR_SUPPORT__)
   DRV_WriteReg32(DMA_LIMITER(1), limiter);
#endif
   for(index = 4; index <= DMA_MAX_CHANNEL+2; index++) {   
#else   /* MT6218B */
   for(index = 1; index <= DMA_MAX_CHANNEL; index++) {
#endif   /* MT6218B */

#if defined(__DMA_V3__)
      DRV_WriteReg32(DMA_LIMITER(index), (DRV_Reg32(DMA_LIMITER(index))&(~DMA_CON_SLOW_MASK)) | (limiter<<DMA_CON_SLOW_OFFSET));
#else //__DMA_V3__
      #if defined (SPARSE_CHANNEL_GROUP)
      if ((DMA_CHANNEL_MASK & (1<<index)) == 0)
          continue;
      #endif  //#if defined (SPARSE_CHANNEL_GROUP)
      DRV_WriteReg32(DMA_LIMITER(index), limiter);
#endif //__DMA_V3__
   }

#endif
	    /* Enable WT slowdown */
#if defined(MT6223) || defined(MT6223P)
   /// clear WT_SDCNT (wavetable slowdown count)
   *ACIF_CON0 &= ~0x1FE;
#endif

   RestoreIRQMask(_savedMask);


#endif //!__MULTI_CORE_SHARED_DMA__

}
#endif /* !__FUE__ */

#if defined(__DMA_UART_VIRTUAL_FIFO__) && !defined(__FUE__)

#if defined(MT6268T) || defined(MT6268H)

void FPGA_DMA_HISR(void)
{
   kal_uint32 index, con;


   for (index = DMA_VFIFO_CH_S; index <= DMA_VFIFO_CH_E; index++)
   {
      con = DRV_Reg32(FPGA_DMA_CON(index));

      if (DRV_Reg32(FPGA_DMA_INTSTA(index)) & DMA_INTSTA_BIT)
      {
         switch (con >> 20)
         {
            case DMA_CON_MASTER_UART1RX:
               UART_RecHandler_VFIFO(uart_port1);
               break;
            case DMA_CON_MASTER_UART1TX:
               UART_TrxHandler_VFIFO(uart_port1);
               break;
            case DMA_CON_MASTER_UART2RX:
               UART_RecHandler_VFIFO(uart_port2);
               break;
            case DMA_CON_MASTER_UART2TX:
               UART_TrxHandler_VFIFO(uart_port2);
               break;                                 
            case DMA_CON_MASTER_UART3RX:
               UART_RecHandler_VFIFO(uart_port3);
               break;
            case DMA_CON_MASTER_UART3TX:
               UART_TrxHandler_VFIFO(uart_port3);
               break;
            default:
               break;
         }
         FPGA_DMA_ACKI(index);
      }
   }
   IRQClearInt(IRQ_FPGA_DMA_CODE);
   IRQUnmask(IRQ_FPGA_DMA_CODE);
}

void FPGA_DMA_LISR(void)
{
   IRQMask(IRQ_FPGA_DMA_CODE);

   drv_active_hisr(DRV_FPGA_DMA_HISR_ID);
}

#endif   /* MT6268T || MT6268H */

/*
* FUNCTION
*	DMA_Vfifo_init
*
* DESCRIPTION
*  DMA virtual FIFO
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*/

#if defined(__MEUT__) || defined(__MEIT__)
#if defined(MT6268T) || defined(MT6268H)
static kal_bool fpga_dma_init = KAL_FALSE;
#endif
#endif

#if defined(__MULTI_CORE_SHARED_DMA__)

void DMA_Vfifo_init(void)
{
#if defined(__DMA_V3__)
    kal_uint32 index;
    for( index = 0; index < MAX_UART_PORT_NUM; index++)
    {
        if( UART_VFIFO_support[index] )
        {
		    DRV_WriteReg32(DMA_INT_EN(UARTPort[index].Tx_DMA_Ch), DMA_INTSTA_BIT);
            DRV_WriteReg32(DMA_INT_EN(UARTPort[index].Rx_DMA_Ch), DMA_INTSTA_BIT|DMA_INTSTA_BIT1);
        }	
    }

#else //__MULTI_CORE_SHARED_DMA__
#error __MULTI_CORE_SHARED_DMA__ can not be used in DMA_V3!
#endif //__MULTI_CORE_SHARED_DMA__


}

#else //__MULTI_CORE_SHARED_DMA__


void DMA_Vfifo_init(void)
{
	kal_uint32 dma_con = 0;


#if defined(MT6268T) || defined(MT6268H)
   if (1) 
   {
#if defined(__MEUT__) || defined(__MEIT__)
      if (fpga_dma_init == KAL_FALSE)
      {
#endif
      IRQ_Register_LISR(IRQ_FPGA_DMA_CODE, FPGA_DMA_LISR, "FPGA DMA LISR");
      DRV_Register_HISR(DRV_FPGA_DMA_HISR_ID, FPGA_DMA_HISR);
      IRQSensitivity(IRQ_FPGA_DMA_CODE, LEVEL_SENSITIVE);
      IRQUnmask(IRQ_FPGA_DMA_CODE);
#if defined(__MEUT__) || defined(__MEIT__)
      fpga_dma_init = KAL_TRUE;
      }
#endif

      if(UART_VFIFO_support[uart_port1])
      {
         // DMA10 for UART1 RX, DMA12 for UART1 TX   
         #if defined(MT6260) || defined(DMA_DEDICATED_CHANNEL_GROUP)
		 dma_con = DMA_CON_DIR | DMA_CON_DRQ | DMA_CON_ITEN;
		 #else
         dma_con = (DMA_CON_MASTER_UART1RX << 20) | DMA_CON_DIR | DMA_CON_DRQ | DMA_CON_ITEN;
		 #endif
         //DRV_WriteReg32(DMA_CON(VDMA_UART1RX_CH),dma_con);   
         DRV_WriteReg32(FPGA_DMA_CON(UARTPort[uart_port1].Rx_DMA_Ch), dma_con);   
         dma_con = 0;
		 #if defined(MT6260) || defined(DMA_DEDICATED_CHANNEL_GROUP)
		 dma_con = DMA_CON_DRQ;
		 #else
         dma_con = (DMA_CON_MASTER_UART1TX << 20) | DMA_CON_DRQ;
		 #endif
         //DRV_WriteReg32(DMA_CON(VDMA_UART1TX_CH),dma_con);
         DRV_WriteReg32(FPGA_DMA_CON(UARTPort[uart_port1].Tx_DMA_Ch), dma_con);
      }
      if(UART_VFIFO_support[uart_port2])
      {
         // DMA11 for UART2 Rx, DMA13 for UART2 TX
         #if defined(MT6260) || defined(DMA_DEDICATED_CHANNEL_GROUP)
		 dma_con = DMA_CON_DIR | DMA_CON_DRQ | DMA_CON_ITEN;
		 #else
         dma_con = (DMA_CON_MASTER_UART2RX << 20) | DMA_CON_DIR | DMA_CON_DRQ | DMA_CON_ITEN;
		 #endif
         //DRV_WriteReg32(DMA_CON(VDMA_UART2RX_CH),dma_con);
         DRV_WriteReg32(FPGA_DMA_CON(UARTPort[uart_port2].Rx_DMA_Ch), dma_con);
         dma_con = 0;
		 #if defined(MT6260) || defined(DMA_DEDICATED_CHANNEL_GROUP)
		 dma_con = DMA_CON_DRQ;
		 #else
         dma_con = (DMA_CON_MASTER_UART2TX << 20) | DMA_CON_DRQ;
		 #endif
         //DRV_WriteReg32(DMA_CON(VDMA_UART2RX_CH),dma_con);
         DRV_WriteReg32(FPGA_DMA_CON(UARTPort[uart_port2].Tx_DMA_Ch), dma_con);
      }
      if(UART_VFIFO_support[uart_port3])
      {
         // DMA13 for UART3 Rx, DMA14 for UART3 TX
         #if defined(MT6260) || defined(DMA_DEDICATED_CHANNEL_GROUP)
		 dma_con = DMA_CON_DIR | DMA_CON_DRQ | DMA_CON_ITEN;
		 #else
         dma_con = (DMA_CON_MASTER_UART3RX << 20) | DMA_CON_DIR | DMA_CON_DRQ | DMA_CON_ITEN;
		 #endif
         //DRV_WriteReg32(DMA_CON(VDMA_UART3RX_CH),dma_con);
         DRV_WriteReg32(FPGA_DMA_CON(UARTPort[uart_port3].Rx_DMA_Ch), dma_con);   
         dma_con = 0;
		 #if defined(MT6260) || defined(DMA_DEDICATED_CHANNEL_GROUP)
		 dma_con = DMA_CON_DRQ;
		 #else
         dma_con = (DMA_CON_MASTER_UART3TX << 20) | DMA_CON_DRQ;
		 #endif
         //DRV_WriteReg32(DMA_CON(VDMA_UART3TX_CH),dma_con);
         DRV_WriteReg32(FPGA_DMA_CON(UARTPort[uart_port3].Tx_DMA_Ch), dma_con);
      }
   }
   else 
#endif  /* MT6268T || MT6268H */
#if defined(__DMA_UART_VFIFO_SINGLE_TUNNEL__)
   {
#if defined(__DMA_V3__)
      #error __DMA_UART_VFIFO_SINGLE_TUNNEL__ can not be used in DMA_V2!
#endif //__DMA_V3__
      if(UART_SINGLE_VFIFO_support[uart1_rx_tunnel])
      {
         dma_con = 0;
         dma_con = (DMA_CON_MASTER_UART1RX << 20)|DMA_CON_DIR|DMA_CON_DRQ|DMA_CON_ITEN;
         DRV_WriteReg32(DMA_CON(UARTPort[uart_port1].Rx_DMA_Ch),dma_con);
      }
      if(UART_SINGLE_VFIFO_support[uart1_tx_tunnel])
      {
         dma_con = 0;
         dma_con = (DMA_CON_MASTER_UART1TX << 20)|DMA_CON_DRQ;
         DRV_WriteReg32(DMA_CON(UARTPort[uart_port1].Tx_DMA_Ch),dma_con);
      }
      if(UART_SINGLE_VFIFO_support[uart2_rx_tunnel])
      {
         dma_con = 0;
         dma_con = (DMA_CON_MASTER_UART2RX << 20)|DMA_CON_DIR|DMA_CON_DRQ|DMA_CON_ITEN;
         DRV_WriteReg32(DMA_CON(UARTPort[uart_port2].Rx_DMA_Ch),dma_con);
      }
      if(UART_SINGLE_VFIFO_support[uart2_tx_tunnel])
      {
         dma_con = 0;
         dma_con = (DMA_CON_MASTER_UART2TX << 20)|DMA_CON_DRQ;
         DRV_WriteReg32(DMA_CON(UARTPort[uart_port2].Tx_DMA_Ch),dma_con);
      }
#if defined(__UART3_SUPPORT__) && !defined(TK6516) && !defined(MT6516) && !defined(MT6251)	  
      if(UART_SINGLE_VFIFO_support[uart3_rx_tunnel])
      {
         dma_con = 0;
         dma_con = (DMA_CON_MASTER_UART3RX << 20)|DMA_CON_DIR|DMA_CON_DRQ|DMA_CON_ITEN;
         DRV_WriteReg32(DMA_CON(UARTPort[uart_port3].Rx_DMA_Ch),dma_con);
      }
      if(UART_SINGLE_VFIFO_support[uart3_tx_tunnel])
      {
         dma_con = 0;
         dma_con = (DMA_CON_MASTER_UART3TX << 20)|DMA_CON_DRQ;
         DRV_WriteReg32(DMA_CON(UARTPort[uart_port3].Tx_DMA_Ch),dma_con);
      }
#endif /* !TK6516 && !MT6516 */						   	  
   }
#else //#if defined(__DMA_UART_VFIFO_SINGLE_TUNNEL__)
   {
	if(UART_VFIFO_support[uart_port1])
	{
#if defined(__DMA_V3__)
        DRV_WriteReg32(DMA_INT_EN(UARTPort[uart_port1].Tx_DMA_Ch), DMA_INTSTA_BIT);
        DRV_WriteReg32(DMA_INT_EN(UARTPort[uart_port1].Rx_DMA_Ch), DMA_INTSTA_BIT|DMA_INTSTA_BIT1);
#else //__DMA_V3__      
	// DMA10 for UART1 RX, DMA12 for UART1 TX
	dma_con = (DMA_CON_MASTER_UART1RX << 20)|DMA_CON_DIR|DMA_CON_DRQ|DMA_CON_ITEN;
	   //DRV_WriteReg32(DMA_CON(VDMA_UART1RX_CH),dma_con);
	   DRV_WriteReg32(DMA_CON(UARTPort[uart_port1].Rx_DMA_Ch),dma_con);
	dma_con = 0;
	dma_con = (DMA_CON_MASTER_UART1TX << 20)|DMA_CON_DRQ;
	   //DRV_WriteReg32(DMA_CON(VDMA_UART1TX_CH),dma_con);
	   DRV_WriteReg32(DMA_CON(UARTPort[uart_port1].Tx_DMA_Ch),dma_con);
#endif 	//__DMA_V3__	 	   
    }

    if(UART_VFIFO_support[uart_port2])
    {
#if defined(__DMA_V3__)
        DRV_WriteReg32(DMA_INT_EN(UARTPort[uart_port2].Tx_DMA_Ch), DMA_INTSTA_BIT);
        DRV_WriteReg32(DMA_INT_EN(UARTPort[uart_port2].Rx_DMA_Ch), DMA_INTSTA_BIT|DMA_INTSTA_BIT1);
#else //__DMA_V3__      
	 // DMA11 for UART2 Rx, DMA13 for UART2 TX
	 dma_con = (DMA_CON_MASTER_UART2RX << 20)|DMA_CON_DIR|DMA_CON_DRQ|DMA_CON_ITEN;
	   //DRV_WriteReg32(DMA_CON(VDMA_UART2RX_CH),dma_con);
	   DRV_WriteReg32(DMA_CON(UARTPort[uart_port2].Rx_DMA_Ch),dma_con);
	 dma_con = 0;
	 dma_con = (DMA_CON_MASTER_UART2TX << 20)|DMA_CON_DRQ;
	   //DRV_WriteReg32(DMA_CON(VDMA_UART2RX_CH),dma_con);
	   DRV_WriteReg32(DMA_CON(UARTPort[uart_port2].Tx_DMA_Ch),dma_con);
#endif 	//__DMA_V3__	 	   
    }
#if defined(__UART3_SUPPORT__) && !defined(TK6516) && !defined(MT6516) && !defined(MT6251)
	if(UART_VFIFO_support[uart_port3])
	{
#if defined(__DMA_V3__)
        DRV_WriteReg32(DMA_INT_EN(UARTPort[uart_port3].Tx_DMA_Ch), DMA_INTSTA_BIT);
        DRV_WriteReg32(DMA_INT_EN(UARTPort[uart_port3].Rx_DMA_Ch), DMA_INTSTA_BIT|DMA_INTSTA_BIT1);
#else //__DMA_V3__      	
	   // DMA13 for UART3 Rx, DMA14 for UART3 TX
	   dma_con = (DMA_CON_MASTER_UART3RX << 20)|DMA_CON_DIR|DMA_CON_DRQ|DMA_CON_ITEN;
	   //DRV_WriteReg32(DMA_CON(VDMA_UART3RX_CH),dma_con);
	   DRV_WriteReg32(DMA_CON(UARTPort[uart_port3].Rx_DMA_Ch),dma_con);
	   dma_con = 0;
	   dma_con = (DMA_CON_MASTER_UART3TX << 20)|DMA_CON_DRQ;
	   //DRV_WriteReg32(DMA_CON(VDMA_UART3TX_CH),dma_con);
	   DRV_WriteReg32(DMA_CON(UARTPort[uart_port3].Tx_DMA_Ch),dma_con);
#endif 	//__DMA_V3__	 	   
    }
#endif /* !TK6516 && !MT6516 */					   
   }
#endif//#if defined(__DMA_UART_VFIFO_SINGLE_TUNNEL__)
}


#endif //__MULTI_CORE_SHARED_DMA__


#if 1 //defined(__MEUT__) || defined(__MEIT__)

#if 0 // defined(__MULTI_CORE_SHARED_DMA__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__DMA_V3__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //__DMA_V3__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else //__MULTI_CORE_SHARED_DMA__

int DMA_Vfifo_SetChan(UART_PORT port)
{
	kal_uint32 dma_con = 0;


#if defined(MT6268T) || defined(MT6268H)
   if (1) 
   {
      if (fpga_dma_init == KAL_FALSE)
      {
         IRQ_Register_LISR(IRQ_FPGA_DMA_CODE, FPGA_DMA_LISR, "FPGA DMA LISR");
         DRV_Register_HISR(DRV_FPGA_DMA_HISR_ID, FPGA_DMA_HISR);
         IRQSensitivity(IRQ_FPGA_DMA_CODE, LEVEL_SENSITIVE);
         IRQUnmask(IRQ_FPGA_DMA_CODE);
         fpga_dma_init = KAL_TRUE;
      }

      if(UART_VFIFO_support[port] != KAL_TRUE)
          return KAL_FALSE;

      if(port == uart_port1)
      {
         // DMA10 for UART1 RX, DMA12 for UART1 TX   
         dma_con = (DMA_CON_MASTER_UART1RX << 20) | DMA_CON_DIR | DMA_CON_DRQ | DMA_CON_ITEN;
         //DRV_WriteReg32(DMA_CON(VDMA_UART1RX_CH),dma_con);   
         DRV_WriteReg32(FPGA_DMA_CON(UARTPort[uart_port1].Rx_DMA_Ch), dma_con);   
         dma_con = 0;
         dma_con = (DMA_CON_MASTER_UART1TX << 20) | DMA_CON_DRQ;
         //DRV_WriteReg32(DMA_CON(VDMA_UART1TX_CH),dma_con);
         DRV_WriteReg32(FPGA_DMA_CON(UARTPort[uart_port1].Tx_DMA_Ch), dma_con);
      }
      else if(port == uart_port2)
      {
         // DMA11 for UART2 Rx, DMA13 for UART2 TX
         dma_con = (DMA_CON_MASTER_UART2RX << 20) | DMA_CON_DIR | DMA_CON_DRQ | DMA_CON_ITEN;
         //DRV_WriteReg32(DMA_CON(VDMA_UART2RX_CH),dma_con);
         DRV_WriteReg32(FPGA_DMA_CON(UARTPort[uart_port2].Rx_DMA_Ch), dma_con);
         dma_con = 0;
         dma_con = (DMA_CON_MASTER_UART2TX << 20) | DMA_CON_DRQ;
         //DRV_WriteReg32(DMA_CON(VDMA_UART2RX_CH),dma_con);
         DRV_WriteReg32(FPGA_DMA_CON(UARTPort[uart_port2].Tx_DMA_Ch), dma_con);
      }
      else if(port == uart_port3)
      {
         // DMA13 for UART3 Rx, DMA14 for UART3 TX
         dma_con = (DMA_CON_MASTER_UART3RX << 20) | DMA_CON_DIR | DMA_CON_DRQ | DMA_CON_ITEN;
         //DRV_WriteReg32(DMA_CON(VDMA_UART3RX_CH),dma_con);
         DRV_WriteReg32(FPGA_DMA_CON(UARTPort[uart_port3].Rx_DMA_Ch), dma_con);   
         dma_con = 0;
         dma_con = (DMA_CON_MASTER_UART3TX << 20) | DMA_CON_DRQ;
         //DRV_WriteReg32(DMA_CON(VDMA_UART3TX_CH),dma_con);
         DRV_WriteReg32(FPGA_DMA_CON(UARTPort[uart_port3].Tx_DMA_Ch), dma_con);
      }
  }
  else 
#endif  /* MT6268T || MT6268H */
#if defined(__DMA_UART_VFIFO_SINGLE_TUNNEL__) // only for MT6235
   {
#if defined(__DMA_V3__)
      #error __DMA_UART_VFIFO_SINGLE_TUNNEL__ can not be used in DMA_V2!
#endif //__DMA_V3__
       if (port == uart_port1) {
           if(UART_SINGLE_VFIFO_support[uart1_rx_tunnel])
           {
               dma_con = 0;
               dma_con = (DMA_CON_MASTER_UART1RX << 20)|DMA_CON_DIR|DMA_CON_DRQ|DMA_CON_ITEN;
               DRV_WriteReg32(DMA_CON(UARTPort[uart_port1].Rx_DMA_Ch),dma_con);
           }
           if(UART_SINGLE_VFIFO_support[uart1_tx_tunnel])
           {
               dma_con = 0;
               dma_con = (DMA_CON_MASTER_UART1TX << 20)|DMA_CON_DRQ;
               DRV_WriteReg32(DMA_CON(UARTPort[uart_port1].Tx_DMA_Ch),dma_con);
           }
       }
       
       if (port == uart_port2) {
           if(UART_SINGLE_VFIFO_support[uart2_rx_tunnel])
           {
               dma_con = 0;
               dma_con = (DMA_CON_MASTER_UART2RX << 20)|DMA_CON_DIR|DMA_CON_DRQ|DMA_CON_ITEN;
               DRV_WriteReg32(DMA_CON(UARTPort[uart_port2].Rx_DMA_Ch),dma_con);
           }
           if(UART_SINGLE_VFIFO_support[uart2_tx_tunnel])
           {
               dma_con = 0;
               dma_con = (DMA_CON_MASTER_UART2TX << 20)|DMA_CON_DRQ;
               DRV_WriteReg32(DMA_CON(UARTPort[uart_port2].Tx_DMA_Ch),dma_con);
           }
       }
#if defined(__UART3_SUPPORT__) && !defined(TK6516) && !defined(MT6516) && !defined(MT6251)	  
       if (port == uart_port3) {
       
           if(UART_SINGLE_VFIFO_support[uart3_rx_tunnel])
           {
               dma_con = 0;
               dma_con = (DMA_CON_MASTER_UART3RX << 20)|DMA_CON_DIR|DMA_CON_DRQ|DMA_CON_ITEN;
               DRV_WriteReg32(DMA_CON(UARTPort[uart_port3].Rx_DMA_Ch),dma_con);
           }
           if(UART_SINGLE_VFIFO_support[uart3_tx_tunnel])
           {
               dma_con = 0;
               dma_con = (DMA_CON_MASTER_UART3TX << 20)|DMA_CON_DRQ;
               DRV_WriteReg32(DMA_CON(UARTPort[uart_port3].Tx_DMA_Ch),dma_con);
           }
       }
#endif /* !TK6516 && !MT6516 */						   	  
   }
#else //#if defined(__DMA_UART_VFIFO_SINGLE_TUNNEL__)
 {

     if(UART_VFIFO_support[port] != KAL_TRUE)
         return KAL_FALSE;

	if(port == uart_port1)
	{
#if defined(__DMA_V3__)
       DRV_WriteReg32(DMA_INT_EN(UARTPort[uart_port1].Rx_DMA_Ch), DMA_INTSTA_BIT|DMA_INTSTA_BIT1);
       DRV_WriteReg32(DMA_INT_EN(UARTPort[uart_port1].Tx_DMA_Ch), DMA_INTSTA_BIT);       
#else //__DMA_V3__
	   // DMA10 for UART1 RX, DMA12 for UART1 TX
	   #if defined(MT6260) || defined(DMA_DEDICATED_CHANNEL_GROUP)
	   dma_con = DMA_CON_DIR|DMA_CON_DRQ|DMA_CON_ITEN;
	   #else
	   dma_con = (DMA_CON_MASTER_UART1RX << 20)|DMA_CON_DIR|DMA_CON_DRQ|DMA_CON_ITEN;
	   #endif
	   //DRV_WriteReg32(DMA_CON(VDMA_UART1RX_CH),dma_con);
	   DRV_WriteReg32(DMA_CON(UARTPort[uart_port1].Rx_DMA_Ch),dma_con);
	   dma_con = 0;
	   #if defined(MT6260) || defined(DMA_DEDICATED_CHANNEL_GROUP)
	   dma_con = DMA_CON_DRQ;
	   #else
	   dma_con = (DMA_CON_MASTER_UART1TX << 20)|DMA_CON_DRQ;
	   #endif
	   //DRV_WriteReg32(DMA_CON(VDMA_UART1TX_CH),dma_con);
	   DRV_WriteReg32(DMA_CON(UARTPort[uart_port1].Tx_DMA_Ch),dma_con);
#endif //__DMA_V3__	   
 }
 else if(port == uart_port2)
 {
#if defined(__DMA_V3__)
       DRV_WriteReg32(DMA_INT_EN(UARTPort[uart_port2].Rx_DMA_Ch), DMA_INTSTA_BIT|DMA_INTSTA_BIT1);
       DRV_WriteReg32(DMA_INT_EN(UARTPort[uart_port2].Tx_DMA_Ch), DMA_INTSTA_BIT);       
#else //__DMA_V3__    
	   // DMA11 for UART2 Rx, DMA13 for UART2 TX
	   #if defined(MT6260) || defined(DMA_DEDICATED_CHANNEL_GROUP)
	   dma_con = DMA_CON_DIR|DMA_CON_DRQ|DMA_CON_ITEN;
	   #else
	   dma_con = (DMA_CON_MASTER_UART2RX << 20)|DMA_CON_DIR|DMA_CON_DRQ|DMA_CON_ITEN;
	   #endif	   
	   //DRV_WriteReg32(DMA_CON(VDMA_UART2RX_CH),dma_con);
	   DRV_WriteReg32(DMA_CON(UARTPort[uart_port2].Rx_DMA_Ch),dma_con);
	   dma_con = 0;
	   #if defined(MT6260) || defined(DMA_DEDICATED_CHANNEL_GROUP)
	   dma_con = DMA_CON_DRQ;
	   #else
	   dma_con = (DMA_CON_MASTER_UART2TX << 20)|DMA_CON_DRQ;
	   #endif
	   //DRV_WriteReg32(DMA_CON(VDMA_UART2RX_CH),dma_con);
	   DRV_WriteReg32(DMA_CON(UARTPort[uart_port2].Tx_DMA_Ch),dma_con);
#endif 	//__DMA_V3__	   
 }
#if defined(__UART3_SUPPORT__) && !defined(TK6516)  && !defined(MT6516) && !defined(MT6251)
	else if(port == uart_port3)
	{
#if defined(__DMA_V3__)
       DRV_WriteReg32(DMA_INT_EN(UARTPort[uart_port3].Rx_DMA_Ch), DMA_INTSTA_BIT|DMA_INTSTA_BIT1);
       DRV_WriteReg32(DMA_INT_EN(UARTPort[uart_port3].Tx_DMA_Ch), DMA_INTSTA_BIT);       
#else //__DMA_V3__	
	   // DMA13 for UART3 Rx, DMA14 for UART3 TX
	   dma_con = (DMA_CON_MASTER_UART3RX << 20)|DMA_CON_DIR|DMA_CON_DRQ|DMA_CON_ITEN;
	   //DRV_WriteReg32(DMA_CON(VDMA_UART3RX_CH),dma_con);
	   DRV_WriteReg32(DMA_CON(UARTPort[uart_port3].Rx_DMA_Ch),dma_con);
	   dma_con = 0;
	   dma_con = (DMA_CON_MASTER_UART3TX << 20)|DMA_CON_DRQ;
	   //DRV_WriteReg32(DMA_CON(VDMA_UART3TX_CH),dma_con);
	   DRV_WriteReg32(DMA_CON(UARTPort[uart_port3].Tx_DMA_Ch),dma_con);
#endif 	//__DMA_V3__	   
   }
#endif /* !TK6516 && !MT6516 */					   
 }
#endif //#if defined(__DMA_UART_VFIFO_SINGLE_TUNNEL__)

 return KAL_TRUE;
}

#endif //__MULTI_CORE_SHARED_DMA__

#endif //#if defined(__MEUT__) || defined(__MEIT__)


/*
* FUNCTION
*	DMA_Vfifo_SetAdrs
*
* DESCRIPTION
*  DMA virtual FIFO set address
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*/
void DMA_Vfifo_SetAdrs(kal_uint32 adrs, kal_uint32 len, DMA_VFIFO_UART ch, kal_bool IsTx )
{
#if defined(MT6268T) || defined(MT6268H)
   if (1) 
   {
      DRV_WriteReg32(FPGA_DMA_PGMADDR(ch), adrs);
      DRV_WriteReg32(DMA_FFSIZE(ch), len);
      DRV_WriteReg32(DMA_ALTLEN(ch), DMA_VIFOF_ALERT_LENGTH); //maximum of alert threshold will effect the flow control 
      DRV_Reg(FPGA_DMA_COUNT(ch)) = (IsTx)?DMA_TX_TRIGGER_LEVEL(len):DMA_RX_TRIGGER_LEVEL(len); // set trigger level for DMA interrupt
   }
   else
#endif   /* MT6268T || MT6268H */
   {
#if defined(__DMA_V3__)
      ASSERT( ( adrs & 0x7 ) == 0 );
      ASSERT( ( len & 0xFFFF0007 ) == 0 );
#endif
   
	DRV_WriteReg32(DMA_PGMADDR(ch), adrs);
	DRV_WriteReg32(DMA_FFSIZE(ch), len);
#if defined(__DMA_V3__)	  
	  DRV_Reg(DMA_VFF_THRE(ch)) = (IsTx)?DMA_TX_TRIGGER_LEVEL(len):DMA_RX_TRIGGER_LEVEL(len); // set trigger level for DMA interrupt     
	  if( IsTx == KAL_FALSE )
	  {
	      DRV_WriteReg32(DMA_ALTLEN(ch), DMA_VIFOF_ALERT_LENGTH); //maximum of alert threshold will effect the flow control	  
	  }
#else //__DMA_V3__
	DRV_WriteReg32(DMA_ALTLEN(ch), DMA_VIFOF_ALERT_LENGTH); //maximum of alert threshold will effect the flow control
	DRV_Reg(DMA_COUNT(ch)) = (IsTx)?DMA_TX_TRIGGER_LEVEL(len):DMA_RX_TRIGGER_LEVEL(len); // set trigger level for DMA interrupt
#endif//__DMA_V3__	  
}
}

/*
* FUNCTION
*	DMA_Vfifo_Flush
*
* DESCRIPTION
*  Flushing DMA virtual FIFO
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*/
void DMA_Vfifo_Flush(DMA_VFIFO_UART ch)
{
#if defined(__DMA_V3__)	 
   kal_uint32 temp;
   /* E1 DMA bug: if stopping or flushing a disabled DMA channel, an unexpected interrupt will be triggered. 
       Disable interrupt control bit before stop DMA*/
   if( !DMA_CheckRunStat(ch) )
       return;   
   temp = DRV_Reg32(DMA_INT_EN(ch));
   DRV_WriteReg32(DMA_INT_EN(ch), 0);
      
   DMA_Flush(ch);
   DMA_WaitUntilRdy(ch);
   DMA_ACKI(ch);        
   
   /* E1 DMA bug: restore intr. control bit */
   DRV_WriteReg32(DMA_INT_EN(ch), temp);      
#else //__DMA_V3__
   DMA_Stop(ch);
#endif //__DMA_V3__
   DMA_Start(ch);
}

#endif  /* __DMA_UART_VIRTUAL_FIFO__ && !__FUE__ */


