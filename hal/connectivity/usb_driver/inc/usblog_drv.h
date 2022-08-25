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
 *    usblog_drv.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *    This file intends for USB logging hardware related function definitions
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef USB_LOGGING_DRV_H
#define USB_LOGGING_DRV_H

#include "kal_non_specific_general_types.h"


#if (defined(DRV_USB_LOGGING_V3)||defined(DRV_USB_LOGGING_V6)||defined(DRV_USB_LOGGING_V7))
#define  USBACM_LOGGING_DSP_SOURCE_NUM   		2
#define  USBACM_LOGGING_TOTAL_SOURCE_NUM   		USBACM_LOGGING_DSP_SOURCE_NUM

#elif defined(DRV_USB_LOGGING_V4)
#define  USBACM_LOGGING_DSP_SOURCE_NUM   		0
#define  USBACM_LOGGING_3G_SOURCE_NUM   			3
#define  USBACM_LOGGING_TOTAL_SOURCE_NUM   		(USBACM_LOGGING_3G_SOURCE_NUM + USBACM_LOGGING_DSP_SOURCE_NUM)

#elif defined(DRV_USB_LOGGING_V5)||defined(DRV_USB_LOGGING_V8)
#define  USBACM_LOGGING_DSP_SOURCE_NUM   		2
#define  USBACM_LOGGING_3G_SOURCE_NUM   			3
#ifdef __MODEM_3G_LOGGING__
/* under construction !*/
#else
#define  USBACM_LOGGING_TOTAL_SOURCE_NUM   		(USBACM_LOGGING_DSP_SOURCE_NUM)
#endif

#endif  //logging source number


//#ifdef __DSPIRDBG__

#if (defined(DRV_USB_LOGGING_V1)||defined(DRV_USB_LOGGING_V2))
#define USB_LOGGING_DSP_BUFFER1_NUM	3
#define USB_LOGGING_DSP_BUFFER1_SIZE	(1024*4)
#elif (defined(DRV_USB_LOGGING_V3)||defined(DRV_USB_LOGGING_V6)||defined(DRV_USB_LOGGING_V7))
// Number of Layer 1 sub buffer used inside DSP, it is a "fixed number" from DSP
#define USB_LOGGING_DSP_BUFFER1_NUM	3
#define USB_LOGGING_DSP_BUFFER2_NUM	3

// IRDBG use WORD (2 byte) as one unit
#define IRDBG_L2_BUFF_UNIT_SIZE					2		// Per unit occupy 2 bytes
#define IRDBG_L2_BUFF_HEADER_SIZE_BY_UNIT		2		// Header occupy 2 WORDs
#define IRDBG_L2_BUFF_DATA_SIZE_BY_UNIT			510		// Data occupy 510 WORDs
#define IRDBG_L2_BUFF_SIZE_BY_UNIT				(IRDBG_L2_BUFF_HEADER_SIZE_BY_UNIT + IRDBG_L2_BUFF_DATA_SIZE_BY_UNIT)
#define IRDBG_L2_BUFF_SIZE							(IRDBG_L2_BUFF_SIZE_BY_UNIT*IRDBG_L2_BUFF_UNIT_SIZE)
#define IRDBG_L2_HOST_BUFF_NUM					8	// Could be 1, 2, 4, 8
#define IRDBG_L2_SLAVE_BUFF_NUM					8	// Could be 1, 2, 4, 8

#define USB_LOGGING_DSP_BUFFER1_SIZE					(IRDBG_L2_BUFF_SIZE*IRDBG_L2_HOST_BUFF_NUM)
#define USB_LOGGING_DSP_BUFFER2_SIZE					(IRDBG_L2_BUFF_SIZE*IRDBG_L2_SLAVE_BUFF_NUM)

// The header we need to fill into L2 buffer before start IRDBG functionality
#define IRDBG_HOST_L2_BUFF_HEADER				0x11111111
#define IRDBG_SLAVE_L2_BUFF_HEADER				0x22222222

#elif defined(DRV_USB_LOGGING_V5)
/* IRDBG part */
// Number of Layer 1 sub buffer used inside DSP, it is a "fixed number" from DSP
#define USB_LOGGING_DSP_BUFFER1_NUM			3
#define USB_LOGGING_DSP_BUFFER2_NUM			3

// IRDBG use WORD (2 byte) as one unit
#define IRDBG_L2_BUFF_UNIT_SIZE					2		// Per unit occupy 2 bytes
#define IRDBG_L2_BUFF_HEADER_SIZE_BY_UNIT		2		// Header occupy 2 WORDs
#define IRDBG_L2_BUFF_DATA_SIZE_BY_UNIT			510		// Data occupy 510 WORDs
#define IRDBG_L2_BUFF_SIZE_BY_UNIT				(IRDBG_L2_BUFF_HEADER_SIZE_BY_UNIT + IRDBG_L2_BUFF_DATA_SIZE_BY_UNIT)
#define IRDBG_L2_BUFF_SIZE							(IRDBG_L2_BUFF_SIZE_BY_UNIT*IRDBG_L2_BUFF_UNIT_SIZE)
#define IRDBG_L2_HOST_BUFF_NUM					8	// Could be 1, 2, 4, 8
#define IRDBG_L2_SLAVE_BUFF_NUM					8	// Could be 1, 2, 4, 8

#define USB_LOGGING_DSP_BUFFER1_SIZE					(IRDBG_L2_BUFF_SIZE*IRDBG_L2_HOST_BUFF_NUM)
#define USB_LOGGING_DSP_BUFFER2_SIZE					(IRDBG_L2_BUFF_SIZE*IRDBG_L2_SLAVE_BUFF_NUM)

// The header we need to fill into L2 buffer before start IRDBG functionality
#define IRDBG_HOST_L2_BUFF_HEADER				0x11111111
#define IRDBG_SLAVE_L2_BUFF_HEADER				0x22222222

#elif defined(DRV_USB_LOGGING_V8)
#define USB_LOGGING_DSP_BUFFER1_NUM			8
#define USB_LOGGING_DSP_BUFFER2_NUM			8
#define MDCI_BUFF_SIZE						(8192-4)
#define USB_LOGGING_DSP_BUFFER1_SIZE		(MDCI_BUFF_SIZE+4)
#define USB_LOGGING_DSP_BUFFER2_SIZE		(MDCI_BUFF_SIZE+4) 
#define	USB_MDCI_DSP_BUFFER1_SIZE_VALUE		((USB_LOGGING_DSP_BUFFER1_NUM<<12)|(MDCI_BUFF_SIZE/4))
#define	USB_MDCI_DSP_BUFFER2_SIZE_VALUE		((USB_LOGGING_DSP_BUFFER2_NUM<<12)|(MDCI_BUFF_SIZE/4))

// The header we need to fill into L2 buffer before start IRDBG functionality
#define IRDBG_HOST_L2_BUFF_HEADER				0x11111111
#define IRDBG_SLAVE_L2_BUFF_HEADER				0x22222222


#endif

//#endif /* __DSPIRDBG__ */


//#ifdef __MODEM_3G_LOGGING__

#if defined(DRV_USB_LOGGING_V4)
#define USB_LOGGING_3G_BUFFER1_NUM		4
#define USB_LOGGING_3G_BUFFER2_NUM		4
#define USB_LOGGING_3G_BUFFER3_NUM		5
#define USB_LOGGING_3G_BUFFER4_NUM		2
#define USB_LOGGING_3G_BUFFER1_SIZE		(1024*4)
#define USB_LOGGING_3G_BUFFER2_SIZE		(1024*4)
#define USB_LOGGING_3G_BUFFER3_SIZE		(1024*4)
#define USB_LOGGING_3G_BUFFER4_SIZE		(1024*16)
#elif defined(DRV_USB_LOGGING_V5)||defined(DRV_USB_LOGGING_V8)

/* 3G MODEM part */
#define USB_LOGGING_3G_BUFFER1_NUM		4
#define USB_LOGGING_3G_BUFFER2_NUM		4
#define USB_LOGGING_3G_BUFFER3_NUM		5
#define USB_LOGGING_3G_BUFFER4_NUM		2
#define USB_LOGGING_3G_BUFFER1_SIZE		(1024*4)
#define USB_LOGGING_3G_BUFFER2_SIZE		(1024*4)
#define USB_LOGGING_3G_BUFFER3_SIZE		(1024*4)
#define USB_LOGGING_3G_BUFFER4_SIZE		(1024*16)

#endif

//#endif /* __MODEM_3G_LOGGING__ */


/* HISR handler function type */
typedef void (*usb_log_hdlr_ptr)(void);
typedef void (*usb_mdci_hdlr_ptr)(kal_uint32 addr, kal_uint32 len, kal_uint32 index);

typedef struct
{
	usb_log_hdlr_ptr	log_dsp1_hdlr;
#if (defined(DRV_USB_LOGGING_V3)||defined(DRV_USB_LOGGING_V6)||defined(DRV_USB_LOGGING_V5)||defined(DRV_USB_LOGGING_V7))
	usb_log_hdlr_ptr	log_dsp2_hdlr;
#endif
#if defined(DRV_USB_LOGGING_V8)
	usb_mdci_hdlr_ptr	mdci_hdlr;
#endif
#if (defined(DRV_USB_LOGGING_V4)||defined(DRV_USB_LOGGING_V5)||defined(DRV_USB_LOGGING_V8))
	usb_log_hdlr_ptr	log_3g_hdlr;
#endif
}USB_LOGGING_Struct;


#if (defined(DRV_USB_LOGGING_V1)||defined(DRV_USB_LOGGING_V2))
extern kal_uint8 USB_LOGGING_Get_Buff_Num(void);
extern kal_uint32 USB_LOGGING_Get_Buff_Size(void);
extern void USB_LOGGING_Clear_Buff(kal_uint8 index);
extern void USB_LOGGING_DSP_Init(kal_uint8* add1);
extern void USB_LOGGING_Register_DSP_Hldr(usb_log_hdlr_ptr log_dsp1_hdlr);
extern void USB_LOGGING_DSP_Start(void);
extern void USB_LOGGING_DSP_Stop(void);

#if defined(DRV_USB_LOGGING_V1)
extern void IRDBG_Callback(void);
extern kal_bool USB_LOGGING_Check_Buff_Full(kal_uint8 index);
#elif defined(DRV_USB_LOGGING_V2)
extern kal_uint16 USB_LOGGING_Get_DSP1_Status(void);
extern void USB_LOGGING_DSP_Drv_Create_ISR(void);
extern void USB_LOGGING_DSP_Drv_Activate_ISR(void);
#endif

#elif (defined(DRV_USB_LOGGING_V3)||defined(DRV_USB_LOGGING_V6)||defined(DRV_USB_LOGGING_V7))
extern kal_uint8 USB_LOGGING_Get_Buff_Num(kal_uint8 buf_index);
extern kal_uint32 USB_LOGGING_Get_Buff_Size(kal_uint8 buf_index);
extern void USB_LOGGING_Clear_Buff(kal_uint8 buf_index, kal_uint8 index);
extern kal_uint16 USB_LOGGING_Get_DSP1_Status(void);
extern kal_uint16 USB_LOGGING_Get_DSP2_Status(void);
extern void USB_LOGGING_DSP_Init(kal_uint8* add1, kal_uint8* add2);
extern void USB_LOGGING_Register_DSP_Hldr(usb_log_hdlr_ptr log_dsp1_hdlr, usb_log_hdlr_ptr log_dsp2_hdlr);
extern void USB_LOGGING_DSP_Start(void);
extern void USB_LOGGING_DSP_Stop(void);
extern void USB_LOGGING_DSP_Drv_Create_ISR(void);
extern void USB_LOGGING_DSP_Drv_Activate_ISR(void);

#elif defined(DRV_USB_LOGGING_V4)
extern kal_uint8 USB_LOGGING_Get_Buff_Num(kal_uint8 buf_index);
extern kal_uint32 USB_LOGGING_Get_Buff_Size(kal_uint8 buf_index);
extern void USB_LOGGING_Clear_Buff(kal_uint8 buf_index, kal_uint8 index);
extern kal_uint16 USB_LOGGING_Get_DSP1_Status(void);
extern void USB_LOGGING_DSP_Init(kal_uint8* add1);
extern void USB_LOGGING_Register_DSP_Hldr(usb_log_hdlr_ptr log_dsp1_hdlr);
extern void USB_LOGGING_DSP_Start(void);
extern void USB_LOGGING_DSP_Stop(void);
extern void USB_LOGGING_DSP_Drv_Create_ISR(void);
extern void USB_LOGGING_DSP_Drv_Activate_ISR(void);

extern void USB_LOGGING_Register_3G_Hldr(usb_log_hdlr_ptr log_3g_hdlr);
extern void USB_LOGGING_3G_HISR(void);

#elif defined(DRV_USB_LOGGING_V5)
extern kal_uint8 USB_LOGGING_Get_Buff_Num(kal_uint8 buf_index);
extern kal_uint32 USB_LOGGING_Get_Buff_Size(kal_uint8 buf_index);
extern void USB_LOGGING_Clear_Buff(kal_uint8 buf_index, kal_uint8 index);
extern kal_uint16 USB_LOGGING_Get_DSP1_Status(void);
extern kal_uint16 USB_LOGGING_Get_DSP2_Status(void);
extern void USB_LOGGING_DSP_Init(kal_uint8* add1, kal_uint8* add2);
extern void USB_LOGGING_Register_DSP_Hldr(usb_log_hdlr_ptr log_dsp1_hdlr, usb_log_hdlr_ptr log_dsp2_hdlr);
extern void USB_LOGGING_DSP_Start(void);
extern void USB_LOGGING_DSP_Stop(void);
extern void USB_LOGGING_DSP_Drv_Create_ISR(void);
extern void USB_LOGGING_DSP_Drv_Activate_ISR(void);

extern void USB_LOGGING_Register_3G_Hldr(usb_log_hdlr_ptr log_3g_hdlr);
extern void USB_LOGGING_3G_HISR(void);
extern void USB_LOGGING_IRDBG_Trigger(void);
#elif defined(DRV_USB_LOGGING_V8)
	extern kal_uint8 USB_LOGGING_Get_Buff_Num(kal_uint8 buf_index);
	extern kal_uint32 USB_LOGGING_Get_Buff_Size(kal_uint8 buf_index);
	extern void USB_LOGGING_Clear_Buff(kal_uint8 buf_index, kal_uint8 index);
	extern kal_uint16 USB_LOGGING_Get_DSP1_Status(void);
	extern kal_uint16 USB_LOGGING_Get_DSP2_Status(void);
	extern void USB_LOGGING_DSP_Init(kal_uint8* add1, kal_uint8* add2);
	extern void USB_LOGGING_Register_DSP_Hldr(usb_mdci_hdlr_ptr mdci_hdlr);
	extern void USB_LOGGING_DSP_Start(void);
	extern void USB_LOGGING_DSP_Stop(void);
	extern void USB_LOGGING_DSP_Drv_Create_ISR(void);
	extern void USB_LOGGING_DSP_Drv_Activate_ISR(void);
	extern void USB_LOGGING_Register_3G_Hldr(usb_log_hdlr_ptr log_3g_hdlr);
	extern void USB_LOGGING_3G_HISR(void);

#endif

#endif  /* USB_LOGGING_DRV_H */

