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
 * EngineerModeDevice.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for engineer mode device port interface 
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
 
#ifndef _ENGINEER_MODE_DEVICE_H
#define _ENGINEER_MODE_DEVICE_H

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMIDataType.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define EM_HW_LEVEL_ACT_GET 0
#define EM_HW_LEVEL_ACT_SET 1

#define SET_GPIO_ACTION  0
#define SET_GPO_ACTION  1

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
typedef void (*EM_SEND_UART_PROC) (void* value); 


/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
extern void LSKEmGPIOListMenu(void);

extern void EMFMBatteryStatusMsgHandler(void *inMsg);

/* Device - USB */
#if defined(__MMI_EM_DEV_USB_OTG_SRP__)
/* under construction !*/
#endif /* __MMI_EM_DEV_USB_OTG_SRP__ */

/* Device - Memory test */
extern void SendSetHWLevelInfoRsp(void *inMsg);

/* Set UART */
extern void mmi_em_dev_stop_uart_hdlr(void);

extern U32 EM_GetBaudRateByIdx(U8 idx);

extern U8 EM_GetIdxByBaudRate(U32 baud);

extern void EngineerModeGetUartReq(void);

extern U8 EngineerModeGetUartRes(void *inMsg);

extern void EngineerModeSetUartReq(
                uart_nvram_lid_function_enum func_id, 
                EM_SEND_UART_PROC proc, void * proc_param);

extern void EngineerModeSetUartRes(void *inMsg);

#ifdef __DYNAMIC_UART_PORT_SWITCHING__
extern void EngineeringModeUartSendDetachReq(void);

extern void EngineerModeDetachUartRes(void *inMsg);

extern void EngineeringModeUartSendAttachReq(void);

extern void EngineerModeAttachUartRes(void *inMsg);
#endif /* __DYNAMIC_UART_PORT_SWITCHING__ */

/* Device -> FM Radio */
#ifdef __MMI_FM_RADIO__
#ifdef __MMI_EM_DEV_FM_RADIO__
extern void EMFMRadioSendReq(void);
extern void EMFMRadioSendRes(void* inMsg);
#endif /*__MMI_EM_DEV_FM_RADIO__*/
#endif /* __MMI_FM_RADIO__ */

#ifdef __MMI_EM_FACTORY_LCD_TEST__
extern void mmi_em_lcd_test_req_ind_handler(void *inMsg);
#endif

extern void mmi_em_device_menu_sel_event_hdlr(cui_menu_event_struct *event);
extern void mmi_em_device_menu_event_entry_hdlr(cui_menu_event_struct *event);
extern void mmi_em_device_menu_event_exit_hdlr(cui_menu_event_struct *evt);

#ifdef __MMI_EM_NFC_SUPPORT__
extern void mmi_em_nfc_enter(void);
#endif /*__MMI_EM_MISC_NFC_SUPPORT__*/

#endif /* _ENGINEER_MODE_DEVICE_H */
