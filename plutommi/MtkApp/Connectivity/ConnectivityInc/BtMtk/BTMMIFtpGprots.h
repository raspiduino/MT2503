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

/******************************************************************************
 * 
 * Filename
 * ---------
 *  BTMMIFtpGprots.h
 * 
 * Project:
 * --------
 *  
 * 
 * Description:
 * ------------
 *  
 * 
 * Author:
 * -------
 * -------
 * 
 *=============================================================================
 *            HISTORY
 * Below this line,  this part is controlled by PVCS VM. DO NOT MODIFY!!
 *-----------------------------------------------------------------------------
 * $Log$
 *
 * 03 02 2011 zhanying.liu
 * removed!
 * .reduce ftp buffer size for slim load
 *
 * 12 16 2010 zhanying.liu
 * removed!
 * .update RHR code check in.
 *
 * 12 14 2010 zhanying.liu
 * removed!
 * .update RHR add files
 *
 * 12 14 2010 zhanying.liu
 * removed!
 * .MAUI RHR code check in
 *
 * 11 23 2010 zhanying.liu
 * removed!
 * .BT CM revise code check in
 *
 * 10 15 2010 zhanying.liu
 * removed!
 * .remove __MMI_USB_SPLIT_SUPPORT__
 *
 * 09 25 2010 zhanying.liu
 * removed!
 * .check in code for USB-Split
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 * 
 *-----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *=============================================================================
 ******************************************************************************/

#ifndef __BT_MMI_FTP_GPROTS_H__
#define __BT_MMI_FTP_GPROTS_H__
// RHR: add
#include "MMI_features.h"
#include "stack_msgs.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
// RHR: add

#include "BtcmSrvGprot.h"


#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
/*****************************************************************
    GLOBAL VARIABLE
*****************************************************************/

/* ftp client memory buffer size */
#ifndef __LOW_COST_SUPPORT_COMMON__
#define FTPC_MEM_BUFF_SIZE              (14336)
#else
#define FTPC_MEM_BUFF_SIZE              (7168)
#endif
/* OBEX FTP UUID */
extern const kal_uint8 OBEX_FTP_UUID[];

/************************************************************************
    Extern Global Function
*************************************************************************/

/****************************************************************************** 
 * FUNCTION
 *  mmi_bt_ftp_init
 * DESCRIPTION
 *  this function is to init ftp
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
extern void mmi_bt_ftp_init(void);


/****************************************************************************** 
 * FUNCTION
 *  mmi_bt_ftp_deinit
 * DESCRIPTION
 *  this function is to deinit ftp
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
extern void mmi_bt_ftp_deinit(void);


/****************************************************************************** 
 * FUNCTION
 *  mmi_bt_ftp_event_hdlr
 * DESCRIPTION
 *  this function is to deal with the message from ftp service,
 *  and deal with the screen flow according the the message from the service
 * PARAMETERS
 *  msg_id:    [IN]    message ID
 *  msg:       [IN]    message pointer
 *  
 * RETURNS
 *  void
 ******************************************************************************/
extern void mmi_bt_ftp_event_hdlr(msg_type msg_id, void *msg);


/****************************************************************************** 
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param    [IN]
 *  
 * RETURNS
 *  
 ******************************************************************************/
extern MMI_RET mmi_ftp_enter_usb_ms_callback(mmi_event_struct *param);


/****************************************************************************** 
 * FUNCTION
 *  mmi_bt_ftp_usb_plugin_hdle
 * DESCRIPTION
 *  this function is to deal with the event that USB plugin 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
extern void mmi_bt_ftp_usb_plugin_hdle(void);


/****************************************************************************** 
 * FUNCTION
 *  mmi_bt_ftp_usb_plugin_check
 * DESCRIPTION
 *  this function is to pre deal with the event that usb plug in
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL
 ******************************************************************************/
extern BOOL mmi_bt_ftp_usb_plugin_check(void);


#ifdef __MMI_FTS_SUPPORT__
/****************************************************************************** 
 * FUNCTION
 *  mmi_bt_ftps_activate
 * DESCRIPTION
 *  this function is to activate ftp server
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
//extern void mmi_bt_ftps_activate(void);


/****************************************************************************** 
 * FUNCTION
 *  mmi_bt_ftps_deactivate
 * DESCRIPTION
 *  this function is to deactivate ftp server
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ******************************************************************************/
//extern void mmi_bt_ftps_deactivate(void);


/****************************************************************************** 
 * FUNCTION
 *  mmi_bt_ftps_disconnect_client
 * DESCRIPTION
 *  this function is to disconnect ftp client, it will be called by CM
 * PARAMETERS
 *  bd_addr:      [IN]    bd address
 *  
 * RETURNS
 *  void
 ******************************************************************************/
extern void mmi_bt_ftps_disconnect_client(srv_bt_cm_bt_addr bd_addr);


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftp_server_is_receiving
 * DESCRIPTION
 *  this function is to judge whether FTP server is receiving files or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: ftp server is receiving files
 *  MMI_FALSE:ftp server is not receiving files
 ******************************************************************************/
extern MMI_BOOL mmi_ftp_server_is_receiving(void);


/****************************************************************************** 
 * FUNCTION
 *  mmi_bth_ftps_connection_authorize_rsp_hdler
 * DESCRIPTION
 *  this function is to deal with ftp server connection authorize response from CM
 * PARAMETERS
 *  bd_addr:    [IN]    bd address
 *  result:     [IN]    authorize result
 *  
 * RETURNS
 *  void
 ******************************************************************************/
//extern void mmi_bth_ftps_connection_authorize_rsp_hdler(srv_bt_cm_bt_addr bd_addr, U32 result);
#endif /* __MMI_FTS_SUPPORT__ */ 


#ifdef __MMI_FTC_SUPPORT__
/****************************************************************************** 
 * FUNCTION
 *  mmi_bt_ftpc_connect_server
 * DESCRIPTION
 *  this function is to connect ftp server
 * PARAMETERS
 *  bd_addr:    [IN]    bd address
 *  
 * RETURNS
 *  void
 ******************************************************************************/
extern void mmi_bt_ftpc_connect_server(srv_bt_cm_bt_addr bd_addr);


/****************************************************************************** 
 * FUNCTION
 *  mmi_bt_ftpc_disconnect_server
 * DESCRIPTION
 *  this function is to disconnect ftp server from client
 * PARAMETERS
 *  bd_addr:      [IN]    bd address
 *  g_conn_id:    [IN]    connection ID
 *  
 * RETURNS
 *  void
 ******************************************************************************/
extern void mmi_bt_ftpc_disconnect_server(srv_bt_cm_bt_addr bd_addr, U32 g_conn_id);


/****************************************************************************** 
 * FUNCTION
 *  mmi_bt_ftpc_is_run
 * DESCRIPTION
 *  this function is to judge whether ftp client is running or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE:  ftp client is running
 *  MMI_FALSE: ftp client is not running
 ******************************************************************************/
extern MMI_BOOL mmi_bt_ftpc_is_run(void);


/****************************************************************************** 
 * FUNCTION
 *  mmi_ftp_client_is_receiving
 * DESCRIPTION
 *  this function is to judge whether ftp client is receiving files nor not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: ftp client is receiving files 
 *  MMI_FALSE:ftp client is nor receiving files
 ******************************************************************************/
extern MMI_BOOL mmi_ftp_client_is_receiving(void);
#endif /* __MMI_FTC_SUPPORT__ */

#endif /* defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) */ 

#endif /* __BT_MMI_FTP_GPROTS_H__ */ 
