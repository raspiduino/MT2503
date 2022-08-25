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
 * BTMMISendGprots.h
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __BT_MMI_SEND_GPROTS_H__
#define __BT_MMI_SEND_GPROTS_H__

#include "MMI_features.h"
#include "MMIDataType.h"
/***************************************************************************** 
* Constant
*****************************************************************************/
/* Send profile selection */


/***************************************************************************** 
* Structure
*****************************************************************************/


/***************************************************************************** 
* Prototype
*****************************************************************************/
#ifdef __MMI_OPP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_oppc_init
 * DESCRIPTION
 *  OPP client initializing API. 
 *  This function regesters ASM and initializes OPP client context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_oppc_init(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_oppc_deinit
 * DESCRIPTION
 *  OPP client de-initializing API. 
 *  This function close OPP client service.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_oppc_deinit(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_oppc_usb_plugin_hdlr
 * DESCRIPTION
 *  This function handles USB plugin message.
 *  If the OPP client is sending, this function will end the sending.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_oppc_usb_plugin_hdlr(void);
#endif /* __MMI_OPP_SUPPORT__ */

#ifdef __MMI_BIP_SUPPORT__
/* BIPI API*/
/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_init
 * DESCRIPTION
 *  BIP client initializing API. 
 *  This function regesters ASM and initializes BIP client context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_bipi_init(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_deinit
 * DESCRIPTION
 *  BIP client de-initializing API. 
 *  This function close BIP client service.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_bipi_deinit(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_usb_mode_check
 * DESCRIPTION
 *  BIP client checking function for USB message handling. 
 *  This function checks if BIP need to handle the USB plugin message.
 *  If the OPP client is sending, this function will end the sending.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL:        MMI_TRUE for handling the USB plugin message and MMI_FALSE for not handling the message
 *****************************************************************************/
extern MMI_BOOL mmi_bipi_usb_mode_check(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_usb_mode_cnf_hdlr
 * DESCRIPTION
 *  BIP client handler, to be executed before entering USB mass storage mode. 
 *  This function cleans the sending file before entering USB mass storage mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_bipi_usb_mode_cnf_hdlr(void);

#endif /* __MMI_BIP_SUPPORT__ */

#ifdef __MMI_BT_DEF_SEND_DEVICE__
/*****************************************************************************
 * FUNCTION
 *  mmi_btsend_delete_device_callback
 * DESCRIPTION
 *  This function is the callback of CM delete device.
 * PARAMETERS
 *  dev:        The device that to be deleted
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_btsend_delete_device_callback(void* dev);
#endif

#ifdef __MMI_BT_APK_SMART_INSTALL_SUPPORT__
#include "custom_btcm_config.h"
extern void mmi_bt_oppc_disconn_for_smart_install(srv_bt_cm_bt_addr *dev_addr, void* cb_ptr);

extern void mmi_bt_oppc_conn_for_smart_install(srv_bt_cm_bt_addr *dev_addr, void* cb_ptr);


#endif
#endif /* __BT_MMI_OBEX_GPROTS_H__ */ 

