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
 *    btif_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for BTIF driver.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef BTIF_SW_H
#define BTIF_SW_H

#if defined(MT6236) || defined(MT6236B) || defined(MT6256) || defined(MT6276) || defined(MT6255) || defined(MT6250)


#include "drv_features.h"
#include "stack_config.h"
//#include "typedefs.h"
#include "bmd.h"
#include "drv_comm.h"
#include "dma_sw.h"
#include "dcl.h"


typedef enum { //toy add for single tunnel vfifo.
  btif_rx_tunnel=0,
  btif_tx_tunnel,
  btif_null_tunnel=99	/* a dummy tunnel for those who doesn't use physical port */
} BTIF_TUNNEL;

typedef enum {
      btif_sleep_on_tx_allow = 0,
      btif_sleep_on_tx_forbid
} BTIF_SLEEP_ON_TX;


typedef struct
{
      kal_uint8                      *rx_buffer;   /* data buffer */
      kal_uint8                      *tx_buffer;   /* data buffer */
} BTIF_RingBufferStruct;


typedef void (*BTIF_TX_FUNC)();
typedef void (*BTIF_RX_FUNC)();

//typedef kal_uint32 module_type;
//typedef kal_uint32 kal_hisrid;

typedef struct
{
      kal_bool                       initialized;
      kal_bool                       power_on;
      module_type                    ownerid;
      module_type                    BTIF_id;
      BTIF_RingBufferStruct          RingBuffers;
      BUFFER_INFO                    Rx_Buffer;  /* receive buffer */
      BUFFER_INFO                    Tx_Buffer;  /* transmit buffer */
      kal_hisrid                     hisr;
      BTIF_SLEEP_ON_TX               sleep_on_tx;
      kal_bool               		    EnableTX;
      /*TY adds these to expand flexibility 2004/10/15*/
      BTIF_TX_FUNC                   tx_cb;
      BTIF_RX_FUNC                   rx_cb;
		kal_uint32 						    Rx_DMA_Ch;
		kal_uint32 						    Tx_DMA_Ch;
} BTIFStruct;


/*start of local parameter struct */
typedef struct
{
	kal_uint8 	ref_count;
	kal_uint16 	msg_len;			/* LOCAL_PARA_HDR */
}btif_ready_to_read_ind_struct;

typedef struct
{
	kal_uint8 	ref_count;
	kal_uint16 	msg_len;			/* LOCAL_PARA_HDR */
}btif_ready_to_write_ind_struct;
/*end of local parameter struct */


#define DRV_WriteReg(addr,data)     ((*(volatile kal_uint16 *)(addr)) = (kal_uint16)(data))
#define DRV_Reg(addr)               (*(volatile kal_uint16 *)(addr))
#define DRV_WriteReg8(addr,data)     ((*(volatile kal_uint8 *)(addr)) = (kal_uint8)(data))
#define DRV_Reg8(addr)               (*(volatile kal_uint8 *)(addr))
#define DRV_WriteReg16(addr,data)     ((*(volatile kal_uint16 *)(addr)) = (kal_uint16)(data))
#define DRV_Reg16(addr)               (*(volatile kal_uint16 *)(addr))
#define DRV_WriteReg32(addr,data)     ((*(volatile kal_uint32 *)(addr)) = (kal_uint32)(data))
#define DRV_Reg32(addr)               (*(volatile kal_uint32 *)(addr))


#define BtifEnableTxIntr(_baseaddr)   \
{\
   kal_uint16 _IER;\
   kal_uint32 _savedMask;\
   _savedMask = SaveAndSetIRQMask();\
   _IER = DRV_Reg(BTIF_IER_ADDR);\
   _IER |= BTIF_IER_TXEEN;\
   DRV_WriteReg(BTIF_IER_ADDR,_IER);\
   RestoreIRQMask(_savedMask);\
}

#define BtifDisableTxIntr(_baseaddr)   \
{\
   kal_uint16 _IER;\
   kal_uint32 _savedMask;\
   _savedMask = SaveAndSetIRQMask();\
   _IER = DRV_Reg(BTIF_IER_ADDR);\
   _IER &= ~BTIF_IER_TXEEN;\
   DRV_WriteReg(BTIF_IER_ADDR,_IER);\
   RestoreIRQMask(_savedMask);\
}
/*BTIF Customization */
typedef struct{
	kal_uint8*	rx_adrs;
	kal_uint8*	tx_adrs;
	kal_uint16	rx_len;
	kal_uint16	tx_len;
	module_type	owerid;		// only the specified owner can use it
}BTIF_ring_buffer_struct;

typedef struct {
   const BTIF_ring_buffer_struct * (*BTIF_Get_Data)(void);
}BTIF_customize_function_struct;


extern void BTIF_HWInit_VFIFO(void);

// UART like functions
void     BTIF_TurnOnPower(DCL_DEV dummy1, kal_bool enable);

kal_bool BTIF_Open(DCL_DEV dummy1, module_type dummy2);
void     BTIF_SetDCBConfig(DCL_DEV dummy1, UARTDCBStruct *dummy2, module_type dummy3);
void     BTIF_Close(DCL_DEV dummy1, module_type dummy2);

extern void BTIF_Register_RX_cb( module_type ownerid, BTIF_RX_FUNC func);
extern void BTIF_Register_TX_cb( module_type ownerid, BTIF_TX_FUNC func);
extern void BTIF_default_tx_cb(void);
extern void BTIF_default_rx_cb(void);

extern void BTIF_HISR(void);
extern void BTIF_LISR(void);

kal_uint16 BTIF_GetBytes(DCL_DEV dummy1, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type dummy2);
kal_uint16 BTIF_PutBytes(DCL_DEV dummy1, kal_uint8 *Buffaddr, kal_uint16 Length, module_type dummy2);

extern BTIFStruct rBTIF;

/*BTIF customize*/
//extern void BTIF_customize_init(void);

#endif	//	#if defined(MT6236) || defined(MT6236B) ||defined(MT6256) || defined(MT6276) || defined(MT6255) || defined(MT6250)

#if defined(MT6236) || defined(MT6236B) || defined(MT6250)

#if defined(MT6236) || defined(MT6236B)
// Stryker ++ DVT Only
#define IRQ_BTIF_CODE           (53)
#define IRQ35_CODE              IRQ_BTIF_CODE
#endif

void BTIF_HWInit_VFIFO_with_VirtualPort(void);
void BTIF_DMA_Vfifo_init(void);
void BTIF_DMA_Vfifo_SetAdrs(kal_uint32 adrs, kal_uint32 len, kal_uint32 ch, kal_bool IsTx );

extern kal_uint16 BTIF_GetBytesAvail(void);
extern kal_uint16 BTIF_GetTxRoomLeft(void);
//extern void BTIF_SleepOnTx_Enable( BTIF_SLEEP_ON_TX enable_flag);
//extern void BTIF_SetSleepEnable(kal_bool enable);

/*ISR handler for VFIFO*/
extern void BTIF_RecTimeOutHandler_VFIFO(void);
extern void BTIF_TrxHandler_VFIFO(void);
extern void BTIF_RecHandler_VFIFO(void);
extern void BTIF_THRE_hdr_VFIFO(void);

extern void BTIF_ReceiveHandler(void);
extern void BTIF_TransmitHandler(void);
extern void BTIF_Polling_RX_Send_To_Tx(void);
extern void BTIF_VFIFO_RX_Send_To_Uart_Tx(void);

#elif defined(MT6256) || defined(MT6276) || defined(MT6255)
///////////////////////////////////////////////////////////
////////////////    New DMA Area    ///////////////////////
extern kal_uint16 BTIF_GetBytesAvail(void);

void VFIFO_BTIF_HWInit_with_Manual_Flush(void);
void VFIFO_BTIF_HW_Reset(void);
void VFIFO_Warm_Reset_TX(void);
void VFIFO_Warm_Reset_RX(void);
void VFIFO_Hard_Reset_TX(void);
void VFIFO_Hard_Reset_RX(void);
void VFIFO_Enable_TX(void);
void VFIFO_Enable_RX(void);

//  DMA ISR
void VFIFO_BTIF_DMA_TX_Handler(void);
void VFIFO_BTIF_DMA_RX_Handler(void);

void VFIFO_BTIF_RX_DMA_DisableINT(void);
void VFIFO_BTIF_RX_DMA_EnableINT(void);
void VFIFO_BTIF_TX_DMA_DisableINT(void);
void VFIFO_BTIF_TX_DMA_EnableINT(void);
#if defined (__BTMODULE_MT6276__)

extern int Brt_MT6236_76_ARM7_Workaround_PutBytes_Use_DMA_1_use_MCU_0;
#endif
////////////////    New DMA Area    ///////////////////////
///////////////////////////////////////////////////////////
#endif//    #if defined(MT6256) || defined(MT6276) || defined(MT6255)

#endif   /*BTIF_SW_H*/
