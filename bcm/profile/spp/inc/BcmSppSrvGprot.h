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
 * SppSrvGprot.h
 *
 * Project:
 * --------
 *  
 *
 * Description:
 * ------------
 *   This file is for BT SPP service.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 ****************************************************************************/
#ifndef __SRV_SPP_GPROT_H__
#define __SRV_SPP_GPROT_H__


#ifdef __BT_SPP_PROFILE__

#include "bcmadp.h"
#include "Bcm_btcmSrvGprot.h"

#include "bt_common_config.h"
#include "Bluetooth_struct.h"

/*spp srv notify app callback function type define*/
typedef S32 (*btSppNotify) (U32 evt, void* para);
/*spp srv handler type define*/
typedef S32 SppHandle;
/*spp security level define*/
typedef U8 SppSecurityLevel;

/***************************************************************************** 
* define
*****************************************************************************/
#define SRV_SPP_MIN_BUFF_SIZE (SPP_MIN_TX_BUFSIZE + SPP_MIN_RX_BUFSIZE)
//SPP_MAX_SERVICE_NAME_LENGTH is the buffer of the name, -2 for header
#define SRV_SPP_SERVICE_NAME_LENGTH (SPP_MAX_SERVICE_NAME_LENGTH - 2)/3

//spp security level just for internal use
#define BTSPP_AUTHENTICATION_IN  0x01     /* Authentication on incoming required */
#define BTSPP_AUTHORIZATION_IN   0x02     /* Authorization on incoming required */
#define BTSPP_ENCRYPTION_IN      0x04     /* Encryption on incoming required */

#define BTSPP_AUTHENTICATION_OUT 0x08     /* Authentication on outgoing required */
#define BTSPP_AUTHORIZATION_OUT  0x10     /* Authorization on outgoing required */
#define BTSPP_ENCRYPTION_OUT     0x20     /* Encryption on outgoing required */

#define BTSPP_BROADCAST_IN       0x40     /* Reception of broadcast packets allowed */
#define BTSPP_NO_SECURITY        0x00

#define BTSPP_DEFAULT  (BTSPP_AUTHENTICATION_IN |  BTSPP_AUTHENTICATION_OUT)
#define BTSPP_DEFAULT_ALL \
						(BTSPP_AUTHENTICATION_IN \
						| BTSPP_AUTHENTICATION_OUT \
						| BTSPP_ENCRYPTION_IN \
						| BTSPP_ENCRYPTION_OUT)

/***************************************************************************** 
* enum
*****************************************************************************/
/*spp connect type*/
typedef enum{
	//instance support connect with sco or not.
	SRV_SPP_CONNECT_WITH_SCO = 0x00000001,
	SRV_SPP_CONNECT_WITHOUT_SCO = 0x00000002
}srv_spp_connect_type;

/*spp security level*/
typedef enum{
	SRV_SPP_SEC_NAN = BTSPP_NO_SECURITY,
	SRV_SPP_SEC_AUTHENTICATION = BTSPP_DEFAULT,
	SRV_SPP_SEC_AUTHENTICATION_AND_ENCRYPTION = BTSPP_DEFAULT_ALL,
	SRV_SPP_SEC_ALL = 0xff
}srv_spp_security_level;

/*spp srv error enum*/
typedef enum{
	SRV_SPP_BIND_FAIL = -1,
	SRV_SPP_CONNECT_FAIL = -2,
	SRV_SPP_INVALID_HANDLE = -3,
	SRV_SPP_INVALID_PORT = -4
}srv_spp_error_enum;

/***************************************************************************** 
* Structure
*****************************************************************************/
typedef struct{
	MMI_BOOL ret;
	S32 para;
	void* user_data;
#ifdef __BCM_SUPPORT__
    srv_bt_cm_bt_addr dev_addr;
    void* inst;
#endif
}srv_spp_event_cntx;

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif
/***********************************for init by native app************************/
/*****************************************************************************
 * FUNCTION
 * 	srv_spp_init
 * DESCRIPTION
 *	This function is for spp server init when boot up
 * PARAMETERS
 
 * RETURNS
 *	void
 *****************************************************************************/
extern void srv_spp_init(void);

/***********************************SDK start*********************************/
/*****************************************************************************
 * FUNCTION
 *  	srv_spp_open
 * DESCRIPTION
 *  	This function is for app create a service instance
 * PARAMETERS
 
 * RETURNS
 *  	SppHandle: spp instance hdlr
 *****************************************************************************/
extern SppHandle srv_spp_open(void);

/*****************************************************************************
 * FUNCTION
 *  	srv_spp_set_notify_hdlr
 * DESCRIPTION
 *  	This function is for app set a notify callback 
 * PARAMETERS
 *  	handle:srv instance handler id
 *  	event_mask: the event of app care
 *  	notifier:  the notify callback function
 * RETURNS
 *  	void
 *****************************************************************************/
extern void srv_spp_set_notify_hdlr(SppHandle handle, U32 event_mask, btSppNotify notifier, void* user_data);

/*****************************************************************************
 * FUNCTION
 *  	srv_spp_bind
 * DESCRIPTION
 *  	This function is for server app bind a spp service
 * PARAMETERS
 *  	handle: spp instance handler         
 *  	uuid: spp server uuid
 * RETURNS
 *  	void
 *****************************************************************************/
extern void srv_spp_bind(SppHandle handle, U32 uuid);

/*****************************************************************************
 * FUNCTION
 *  	srv_spp_connect
 * DESCRIPTION
 *  	This function is for client app connect remote server with no sco support
 * PARAMETERS
 *  	handle: client service handle
 * 	uuid: app uuid
 *  	bt_addr: remote server bt address
 *  	buf: for tx rx buffer
 *  	tx_size: tx buffer size
 *  	rx_size: rx buffer size
 * RETURNS
 *  	void
 *****************************************************************************/
extern void srv_spp_connect(SppHandle handle,
					U32 uuid,
					srv_bt_cm_bt_addr* bt_addr,
					void* buf,
					U32 tx_size,
					U32 rx_size
					);

/*****************************************************************************
 * FUNCTION
 *  	srv_spp_connect_ex
 * DESCRIPTION
 *  	This function is for client connect remote server
 * PARAMETERS
 *  	handle : client app service handle
 *  	uuid: app uuid
 *  	bt_addr: bt address.
 *  	buf: for tx rx buffer
 *  	tx_size: tx buffer size
 *  	rx_size: rx_size
 *  	connect_type: with sco or not
 * RETURNS
 *  	void
 *****************************************************************************/
extern void srv_spp_connect_ex(SppHandle handle, 
						U32 uuid,
						srv_bt_cm_bt_addr* bt_addr,
						void* buf,
						U32 tx_size,
						U32 rx_size,
						srv_spp_connect_type conn_type
						);

/*****************************************************************************
 * FUNCTION
 *  	srv_spp_accept
 * DESCRIPTION
 *  	This function is for server to accept a connect
 * PARAMETERS
 *  	conn_id: connect id         
 *  	buf: tx rx buffer
 *  	tx_size: tx buffer size
 *  	rx_size: rx buffer size
 * RETURNS
 *  	void
 *****************************************************************************/
extern void srv_spp_accept(S32 conn_id,
						void* buf, 
						U32 tx_size,
						U32 rx_size
						);

/*****************************************************************************
 * FUNCTION
 *  	srv_spp_reject
 * DESCRIPTION
 *  	This function is for server to reject a connect
 * PARAMETERS
 *  	conn_id:connect id
 * RETURNS
 *  	void
 *****************************************************************************/
extern void srv_spp_reject(S32 conn_id);


/*****************************************************************************
 * FUNCTION
 *  	srv_spp_disconnect
 * DESCRIPTION
 *  	This function is for app disconnect a connect
 * PARAMETERS
 *  	conn_id:connnect id
 * RETURNS
 *  	void
 *****************************************************************************/
extern void srv_spp_disconnect(S32 conn_id);

/*****************************************************************************
 * FUNCTION
 *  	srv_spp_write
 * DESCRIPTION
 *  	This function is for app write data
 * PARAMETERS
 *  	conn_id: connect id 
 *  	buf: data buf want to transfer
 *  	size: the size of data want to transfer
 * RETURNS
 *  	U32 : the size of data transfer successfully in fact
 *****************************************************************************/
extern U32 srv_spp_write(U32 conn_id, void* buf, U32 size);

/*****************************************************************************
 * FUNCTION
 *  	srv_spp_read
 * DESCRIPTION
 *  	This function is for app read data
 * PARAMETERS
 *  	conn_id: connect id 
 *  	buf: data buf want to receive
 *  	size: the size of data want to receive
 * RETURNS
 *  	U32 : the size of data recevie successfully in fact
 *****************************************************************************/
extern U32 srv_spp_read(U32 conn_id, void* buf, U32 size);

/*****************************************************************************
 * FUNCTION
 *  	srv_spp_close
 * DESCRIPTION
 *  	This function is for close a service instance
 * PARAMETERS
 *  	handle:instance handler 
 * RETURNS
 *  	void
 *****************************************************************************/
extern void srv_spp_close(SppHandle handle);

/*****************************************************************************
 * FUNCTION
 *  	srv_spp_get_dev_addr
 * DESCRIPTION
 *	This funciton is for get the remote device bt address by conn_id
 * PARAMETERS
 *  	conn_id: connect id (in)
 *  	bt_addr: bt_addr.(out)
 * RETURNS
 *  	void
 *****************************************************************************/
extern void srv_spp_get_dev_addr(S32 conn_id, srv_bt_cm_bt_addr* bt_addr);

/*****************************************************************************
 * FUNCTION
 *  	srv_spp_set_security_level
 * DESCRIPTION
 *  	This function is for set security level by handle
 * PARAMETERS
 *  	handle: spp instance handle 
 *  	level: spp instance security level 
 * RETURNS
 *  	void
 *****************************************************************************/
extern void srv_spp_set_security_level(SppHandle handle, SppSecurityLevel level);

/*****************************************************************************
 * FUNCTION
 *  	srv_spp_set_service_name
 * DESCRIPTION
 *  	This function is for set service name by handle
 * PARAMETERS
 *  	handle: spp instance handle 
 *  	name: spp instance name charset: ucs2
 * RETURNS
 *  	void
 *****************************************************************************/
extern void srv_spp_set_service_name(SppHandle handle, WCHAR* name);

/***********************************SDK end**********************************/
#ifdef __cplusplus
}
#endif

#endif /*__MMI_SPP_SUPPORT__*/
#endif /*__SRV_SPP_GPROT_H__*/


