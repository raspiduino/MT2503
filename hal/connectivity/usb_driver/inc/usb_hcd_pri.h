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
 *    usb_hcd_pri.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file intends for usb host hardware related function definitions. Only use for hardware driver.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef USB_HCD_PRI_H
#define USB_HCD_PRI_H

#include "usb_drv.h"
//#include "usb_drv_pri.h"
#include "usb_custom.h"
#include "usb_hw.h"
#include "dcl.h"
//#include "kal_non_specific_general_types.h"
//#include "usb_hcd.h"

#define  USB_HCD_DEBOUNCE_DELAY			(10)	 /* 10ms unit */
#define  USB_HCD_RESET_RECOVERY_DELAY	(1)
#define  USB_HCD_RESET_DELAY			(6)
#define  USB_HCD_RESUME_DELAY			(2)  //20ms
#define  USB_HCD_DMA_TIMER					(500)


#if defined (DRV_USB_IP_V3)


#define USBHCD_DMA_CheckRunStat(_baseaddr,_n)		(USB_DRV_Reg(USB_DMACNTL_HCD(_baseaddr,_n))&USB_DMACNTL_DMAEN)
#define USBHCD_DMA_CheckPPRunStat(_baseaddr,_n)			(USB_DRV_Reg(USB_DMAPPCNTL_HCD(_baseaddr,_n))&USB_DMACNTL_DMAEN)
#define USBHCD_DMA_Stop(_baseaddr,_n)					USB_DRV_ClearBits(USB_DMACNTL_HCD(_baseaddr,_n), USB_DMACNTL_DMAEN)


#define  USB_HCD_DMA_TX_CSR		(USB_TXCSR_AUTOSET|USB_TXCSR_DMAREQENAB|USB_TXCSR_DMAREQMODE)
#define  USB_HCD_DMA_TX_CSR_ISO	(USB_TXCSR_AUTOSET|USB_TXCSR_DMAREQENAB|USB_TXCSR_DMAREQMODE|USB_TXCSR_ISO)


#define  USB_HCD_DMA_RX_CSR		(USB_RXCSR_AUTOCLEAR|USB_RXCSR_DMAREQENAB|USB_RXCSR_AUTOREQ)
#define  USB_HCD_DMA_RX_CSR_ISO	(USB_RXCSR_AUTOCLEAR|USB_RXCSR_DMAREQENAB|USB_RXCSR_AUTOREQ|USB_RXCSR_ISO)

#endif /* DRV_USB_IP_V2 */


/* endpoint information*/
typedef struct
{
	/* keep send/recv buffer addr, wait for scheduler*/
	kal_uint8					*p_data;
	kal_uint16					data_length;
	/* If normal mode and data length > max pkt size */
	kal_uint16					max_packet_size;
	kal_uint16					sofar;

	USB_ENDPT_TXFER_TYPE		ep_type;			/* Control, interrupt, bulk or ISO */
	USB_EP_DIRECTION			direction;			/* For control endpoint, this indicates data direction*/
	kal_bool					b_enable;

	kal_bool					b_dma_enable;
}USB_HCD_EP_INFO;

typedef enum
{
	 USBH_STATE_START,
	 USBH_STATE_IDLE,
	 USBH_STATE_WAIT_VRISE,
	 USBH_STATE_WAIT_BCON,
	 USBH_STATE_HOST,
	 USBH_STATE_SUSPEND
}USB_HCD_STATE;


typedef struct 
{
	const USB_HOST_COMMON_PARAM		*host_common_param;	

	USB_HCD_STATE				host_state;		
	USB_HCD_STATUS				reset_reason;

	/* interrupt handler */
	usb_hcd_intr_handler_ptr	attach_hdlr;
	usb_hcd_intr_handler_ptr	detach_hdlr;
	usb_hcd_intr_handler_ptr	resume_hdlr;		/* Host receive remote wakeup handler */

	/* endpoint related information*/
	usb_hcd_intr_handler_ptr			ep0_hdlr;
	usb_hcd_intr_handler_ptr			ep_tx_hdlr[MAX_TX_EP_NUM];
	usb_hcd_intr_handler_ptr			ep_rx_hdlr[MAX_RX_EP_NUM];
	USB_HCD_EP_INFO				ep0_info;
	USB_HCD_EP_INFO				ep_tx_info[MAX_TX_EP_NUM];
	USB_HCD_EP_INFO				ep_rx_info[MAX_RX_EP_NUM];

	kal_bool					ep0_setup;
	kal_bool					ep0_status;

 	USB_EP_STATE		ep_tx_enb_state[MAX_TX_EP_NUM];
 	USB_EP_STATE		ep_rx_enb_state[MAX_RX_EP_NUM];
	/* FIFO flush interrupt */
	kal_bool					ep_tx_flush_intr[MAX_TX_EP_NUM];
	kal_bool					ep_rx_flush_intr[MAX_RX_EP_NUM];
	/* TX FIFOWrite interrupt */
	kal_bool					ep0_fifo_intr;
	kal_bool					ep_tx_fifo_intr[MAX_TX_EP_NUM];
	kal_bool					ep_rx_fifo_intr[MAX_RX_EP_NUM];
	kal_bool					b_hcd_is_high_speed;

	kal_uint8				ep_rx_real_num;			
	kal_uint8				ep_tx_real_num;
	
	/* Attach/detach debounce timer */
	kal_uint32					gpt_handle;    /*GPT handle*/

	/* may be omit */
//	kal_uint32					resume_timer; 	

	kal_bool					b_unmask_irq;

	/* DMA parameters */
	/* DMA RX timer */
	kal_uint32					dma_gpt_handle[MAX_RX_EP_NUM];    /*GPT handle*/
	kal_uint8					dma_port[2][MAX_EP_NUM]; 	/* record TX/RX ep's DMA port number */
	USB_EP_DIRECTION		dma_dir[MAX_DMA_NUM]; 			/* record  DMA port's direction */
  kal_bool					dma_pktrdy[MAX_DMA_NUM];
  kal_bool					dma_running[MAX_DMA_NUM];
	kal_bool					dma_callback_upd_run[MAX_DMA_NUM]; /* take PP buffer */
	usb_dma_callback			dma_callback[MAX_DMA_NUM];			/* take PP buffer */
	kal_uint32 				dma_length[MAX_DMA_NUM];
	kal_uint32 				dma_addr[MAX_DMA_NUM];
	kal_bool 					is_bidirection_dma[MAX_DMA_NUM];
	kal_uint8					dma_channel;
	kal_uint8					dma_tx_ep_num[MAX_DMA_NUM];  		/* record  DMA port's TX ep number */
	kal_uint8					dma_rx_ep_num[MAX_DMA_NUM];  		/* record  DMA port's RX ep number */
	kal_bool					b_enable_dma_burst_auto_chge;		/* For DVT use only, enable DMA auto changed burst mode */
 	kal_bool					b_disable_attach;
 	kal_uint8				usb_ip_port;
}USB_HCD_Struct;



extern USB_HCD_Struct g_UsbHcdInfo[USB_IP_NUM];


#endif /* USB_HCD_PRI_H */

