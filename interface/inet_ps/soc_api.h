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
 * Filename:
 * ---------
 *	soc_api.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains structs and function prototypes of Socket API.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
 
#ifndef _SOC_API_H
#define _SOC_API_H

#ifndef _APP2SOC_STRUCT_H
#include "app2soc_struct.h" /* soc_enums.h is included by app2soc_struct.h */
#endif /* !_APP2SOC_STRUCT_H */

#ifndef _SOC_CONSTS_H
#include "soc_consts.h"
#endif /* !_SOC_CONSTS_H */

#if 0
#ifndef _CUSTOM_DATA_ACCOUNT_H
/* under construction !*/
#endif
#endif

#include "custom_qos_def.h"

#include "kal_general_types.h"
#include "stack_config.h"

/* Macros for SOC_SELECT */
typedef struct
{
    kal_uint8	fds_bits[MAX_IP_SOCKET_NUM]; /* select set based on socket id */
} soc_fd_set;

/*
 * <GROUP  Macro_Funcs>
 * 
 * set the socket id which you want to select 
 */
#define	SOC_FD_SET(s, p)            ((p)->fds_bits[s] |= 0x01)

/*
 * <GROUP  Macro_Funcs>
 * 
 * clear the socket id which you don't want to select 
 */
#define	SOC_FD_CLR(s, p)            ((p)->fds_bits[s] &= ~(0x01))

/*
 * <GROUP  Macro_Funcs>
 * 
 * check if the socket id is selected 
 */
#define	SOC_FD_ISSET(s, p)          ((p)->fds_bits[s] & 0x02)

/*
 * <GROUP  Macro_Funcs>
 *  
 * clear the select set 
 */
#define	SOC_FD_ZERO(p)              kal_mem_set(p, 0x00, sizeof(*(p)))

/*
 * <GROUP  Macro_Funcs>
 *  
 * copy the select set 
 */
#define	SOC_FD_COPY(orig, copy)     kal_mem_cpy(copy, orig, sizeof(*(orig)))


/*
 * <GROUP  Macro_Funcs>
 *  
 * account id in the SMS address 
 */
#define	SOCK_ACCT_ID(addr) (kal_uint8 *)((kal_uint8 *)addr + (MAX_SOCK_ADDR_LEN - MAX_NWK_ACCT_SIZE))

/*=============================
 * structs 
 *=============================*/

/* select timeout structure */
typedef struct 
{
    kal_uint32 tv_sec;  /* select timeout: no. of second */
    kal_uint32 tv_usec; /* select timeout: no. of microsecond */
} soc_timeval_struct;

/* socket address structure */
typedef struct 
{
    socket_type_enum	sock_type; /* socket type */
    kal_int16	addr_len; /* address length */
    kal_uint16	port; /* port number */
    kal_uint8	addr[MAX_SOCK_ADDR_LEN];
    /* IP address. For keep the 4-type boundary, 
     * please do not declare other variables above "addr"
    */
} sockaddr_struct;

typedef struct
{
    void *iov_buf;
    kal_int32 iov_len;
} soc_iovec_struct;

typedef struct 
{
  sockaddr_struct addr;
  soc_iovec_struct *iov;
  kal_int32              iov_num;
} soc_msghdr_struct;

/* socket linger timeout structure */
typedef struct
{
    kal_bool   onoff; /* KAL_TRUE: enable linger timeout KAL_FALSE: disable linger timeout */
    kal_uint16 linger_time; /* linger timeout (unit in seconds) */
} soc_linger_struct;

/*=================================================== 
 *
 * Socket APIs prototypes
 *
 *===================================================*/

/*****************************************************************************
 * <GROUP  Berkley_API>
 *
 * FUNCTION
 *  soc_create
 * DESCRIPTION
 *  This API is to create a socket. 
 *  If you want to do the loopback testing, 
 *  please use the LOOPBACK_ACCT_ID if you can. Otherwise, 
 *  you have to pay attention to use some socket APIs, such as cbm_open_bearer, 
 *  soc_abort_dns_query. On the contrary, if you use the LOOPBACK_ACCT_ID 
 *  during loopback testing, socket can check possible illegal usages 
 *  and return error if your usage is not right. 
 *  
 *  If the non-blocking and asynchronous socket is adopted, 
 *  the notifications will be sent to the module specified by the mod_id. 
 *  If the blocking socket is adopted, application shall use the same mod_id 
 *  for each socket creation even the application has several sub modules. 
 *  In the case that application has several sub modules and use blocking-mode socket, 
 *  the mod_id shall be one of module id of its sub modules.
 *  If the user cannot decide the network account s/he wants to use currently, 
 *  Please add "Always Ask" property into data account. 
 *  When real network activation occurs, a query would be display to ask the user 
 *  which account s/he wants to use to connect to network. 
 *  For more detailed understanding of the structure of data account layout, 
 *  please take the reference of SAP_APP_CBM.
 *
 *  P.S. We assume applications shall set its module id before calling our 
 *  Socket API so that Socket can check the socket used by applications 
 *  is valid or not. The following function is provided by the system service 
 *  to set active module id:
 *  stack_set_active_module_id( task_index, mod_id);
 *  The mod_id shall be the same as the one specified in soc_create.
 * PARAMETERS
 *  domain              : [IN]  Socket domain. Currently, only SOC_PF_INET supported
 *  type                : [IN]  Socket type. please take the reference of soc_type_enum.      
 *  protocol            : [IN]  Socket protocol. This one shall set to zero except type is SOC_SOCK_RAW.
 *                            When type is SOC_SOCK_RAW, the protocol can be SOC_IPPROTO_ICMP or
 *                            SOC_IPPROTO_RAW.
 *  mod_id              : [IN]  Module id.
 *  nwk_account_id      : [IN]  Network account id. Application id, sim info, multiple accounts 
 *                            and always-ask info is encoded in the network account id.
 * RETURN VALUES
 *  >=0 : socket id
 *	SOC_INVAL :			  wrong parameters, domain, type, protocol
 *  SOC_INVALID_ACCOUNT : wrong account id, nwk_account_id
 *  SOC_LIMIT_RESOURCE :  no socket available
 *  SOC_BEARER_FAIL :	  bearer broken
 * EXAMPLE
 *  Create a TCP socket:
 * <code>
 *  kal_int8 fd;
 *  fd = soc_create(SOC_PF_INET, SOC_SOCK_STREAM, 0, MOD_TEST, nwk_acct_id);
 *  if (fd < 0) { kal_trace(TRACE_ERROR, INVALID_SOCK_ID); }
 * </code>
 *
 *  Create a UDP socket:
 * <code>
 *  kal_int8 fd;
 *  fd = soc_create(SOC_PF_INET, SOC_SOCK_DGRAM, 0, MOD_TEST, nwk_acct_id);
 *  if (fd < 0) { kal_trace(TRACE_ERROR, INVALID_SOCK_ID); }  
 * </code>
 *
 *  Create a loopback TCP socket:
 * <code>
 *  kal_int8 fd;
 *  fd = soc_create(SOC_PF_INET, SOC_SOCK_STREAM, 0, MOD_TEST, LOOPBACK_ACCT_ID);
 *  if (fd < 0) { kal_trace(TRACE_ERROR, INVALID_SOCK_ID); }
 * </code>
 *
 *  Create a RAW socket and generate all data include headers by the application:
 * <code>
 *  kal_int8 fd;
 *  kal_int8 ret;
 *  kal_uint8 val = KAL_TRUE;
 *  fd = soc_create(SOC_PF_INET, SOC_SOCK_RAW, 0, MOD_TEST, account_id);
 *  if (fd < 0) { kal_trace(TRACE_ERROR, INVALID_SOCK_ID); }
 *  ...
 *  ret = soc_setsockopt(fd, SOC_IP_HDRINCL, &val, sizeof(val));
 *  ...
 *  soc_sendto(...);
 * </code>
 *
 *  Create a RAW ICMP socket:
 * <code>
 *  kal_int8 fd;
 *  kal_int8 ret;
 *  kal_uint8 val = KAL_TRUE;
 *  fd = soc_create(SOC_PF_INET, SOC_SOCK_RAW, SOC_IPPROTO_ICMP, MOD_TEST, account_id);
 *  if (fd < 0) { kal_trace(TRACE_ERROR, INVALID_SOCK_ID); }
 *  ...
 *  soc_sendto(...);
 * </code>
 *
 *  Create a SMS socket:
 * <code>
 *  kal_int8 fd;
 *  fd = soc_create(SOC_PF_INET, SOC_SOCK_SMS, 0, MOD_TEST, 0);
 *  if (fd < 0) { kal_trace(TRACE_ERROR, INVALID_SOCK_ID); }  
 * </code>
 *****************************************************************************/
extern kal_int8 soc_create(kal_uint8         domain,
                           socket_type_enum  type,
                           kal_uint8         protocol,
                           module_type       mod_id,
                           kal_uint32        nwk_account_id);

/*****************************************************************************
 * <GROUP  Berkley_API>
 *
 * FUNCTION
 *  soc_close
 * DESCRIPTION
 *  Close the socket. This function free a free socket slot from socket pool and
 *  trigger ABM to close the corresponding bearer if required.
 *
 *  SOC will activate the corresponding bearer automatically before doing the data transaction. 
 *  When the application close all of its sockets, the bearer will be deactivated automatically 
 *  after 1 seconds. If the application doesn't want the bearer be automatically deactivated, 
 *  please call the API "cbm_hold_bearer" provided by the CBM to hold the bearer. Once the bearer
 *  is hold. The bearer will be deactivated only after all its socket are closed and cbm_release_bearer
 *  is called. For more detailed usage, please take the reference of SAP_APP_CBM.
 * PARAMETERS
 *  s           : [IN]  socket id      
 * RETURN VALUES
 *  SOC_SUCCESS : success
 *  SOC_INVALID_SOCKET : invalid socket id
 * EXAMPLE
 * <code>
 *  kal_int8 s, ret;
 *  ret = soc_close((kal_int8) s);
 *  if (ret < 0) { kal_trace(TRACE_ERROR, INVALID_SOCK_ID); }
 * </code>
 *****************************************************************************/
extern kal_int8 soc_close(kal_int8 s);

/*****************************************************************************
 * <GROUP  Berkley_API>
 *
 * FUNCTION
 *  soc_bind
 * DESCRIPTION
 *  This function binds a local address which contain IP and port to a socket.
 *  If you want to bind to a local address to do the loopback testing, 
 *  you can bind to the loopback address here (127.0.0.1).
 * PARAMETERS
 *  s           : [IN]   socket id     
 *  addr        : [IN]   local addr to be binded      
 * RETURN VALUES
 *  SOC_SUCCESS : success
 *  SOC_INVALID_SOCKET : invalid socket id
 *  SOC_BEARER_FAIL : bearer broken
 *  SOC_ERROR : unspecified error
 *  SOC_ADDRINUSE : the local port has been bound by other socket
 * EXAMPLE
 *  loopback usage:
 *  <code>
 *  kal_uint8 local_address[4] = {127, 0, 0, 1};
 *  kal_int8 socket_id;
 *  sockaddr_struct local;
 *  socket_id = soc_create(PF_INET, SOCK_STREAM, 0, MOD_TEST, LOOPBACK_ACCT_ID);
 *  kal_mem_set(&local, 0x00, sizeof(local));
 *  local.addr_len = 0x04;
 *  local.port = xx;
 *  kal_mem_cpy(local.addr, local_address, local.addr_len);
 *  ret = soc_bind(socket_id, &local);
 *  if (ret < 0)
 *  {
 *      return ERROR;
 *  }
 *  </code>
 * 
 *  normal usage:
 *  <code>
 *  kal_uint8 local_address[4] = {172, 1, 1, 1};
 *  kal_int8 socket_id;
 *  sockaddr_struct local;
 *  socket_id = soc_create(PF_INET, SOCK_STREAM, 0, MOD_TEST, LOOPBACK_ACCT_ID);
 *  kal_mem_set(&local, 0x00, sizeof(local));
 *  local.addr_len = 0x04;
 *  local.port = xx;
 *  kal_mem_cpy(local.addr, local_address, local.addr_len);
 *  ret = soc_bind(socket_id, &local);
 *  if (ret < 0)
 *  {
 *      return ERROR;
 *  }  
 *  </code>
 *****************************************************************************/
extern kal_int8 soc_bind(kal_int8 s, sockaddr_struct *addr);

/*****************************************************************************
 * <GROUP  Berkley_API>
 *
 * FUNCTION
 *  soc_listen
 * DESCRIPTION
 *  This function makes a socket to a server socket to wait client connections. 
 *  This API is always in blocking mode. If users's account id may be the 
 *  always-ask account id, s/he has to call the API "cbm_open_bearer" before
 *  it create the socket. Otherwise, the user's task may be blocking in the
 *  the API "soc_listen" for a long time.
 *  For more detailed of cbm_open_bearer, please take the reference of "SAP_APP_CBM". 
 *  
 *  P.S. This API can only be used for the server socket.
 * PARAMETERS
 *  s           : [IN]        socket id
 *  backlog     : [IN]        max number of connections
 * RETURN VALUES
 *  SOC_SUCCESS : success
 *  SOC_INVALID_SOCKET : invalid socket id
 *  SOC_BEARER_FAIL : bearer broken
 *  SOC_OPNOTSUPP :	only TCP can be listened
 *  SOC_ALREADY : already listened
 *  SOC_ERROR :	unspecified error
 *  SOC_BEARER_FAIL : bearer broken
 * EXAMPLE
 *  Create a server socket:
 * <code>
 *  sockaddr_struct addr;
 *  kal_int8 socket_id;
 *  kal_mem_set(&addr, 0x00, sizeof(addr));
 *  addr.addr_len = 0x04;
 *  addr.port = xx;
 *  if ((socket_id =  
 *  soc_create(PF_INET, SOCK_STREAM, 0, MOD_SIP, network_id)) < 0)
 *  {
 *      return ERROR;
 *  }
 *  soc_setsockopt(socket_id, SOC_NBIO, &val, sizeof(val));
 *  val = SOC_READ | SOC_WRITE | SOC_CLOSE | SOC_ACCEPT;
 *  soc_setsockopt(socket_id, SOC_ASYNC, &val, sizeof(val)); 
 *  ret = soc_bind(socket_id, &addr);
 *  if (ret < 0)
 *  {
 *      soc_close(socket_id);
 *      return ERROR;
 *  }
 *  ret = soc_listen(socket_id, 5);
 *  if (ret < 0)
 *  {
 *      soc_close(socket_id);
 *      return ERROR;
 *  }
 * </code>
 *****************************************************************************/
extern kal_int8 soc_listen(kal_int8 s, kal_uint8 backlog);

/*****************************************************************************
 * <GROUP  Berkley_API>
 *
 * FUNCTION
 *  soc_accept
 * DESCRIPTION
 *  This function waits for the incoming connections and return a socket id
 *  of new connection.
 *
 *  We support three different modes for this function: 
 *  1. blocking mode: 
 *     the result will be returned only after the operation is done.
 *  2. non-blocking mode: 
 *     the result will be returned even if the operation is not done.
 *     However, the user has to query the result by itself.
 *  3. non-blocking plus asyn mode:
 *     the result will be returned even if the operation is not done.
 *     The result will be reported to the user later by the primitive.
 *
 *  By default, if user doesn't set the socket option (SOC_NBIO) 
 *  to change the mode, the mode will be blocking.
 *  Moreover, if you use the non-blocking mode and wants to receive the 
 *  notification event, please set the SOC_ASYN socket option.
 *  Otherwise, there will be no event sent to notify you that you can
 *  keep on accepting the client connection.
 *
 *  P.S. this API can only be used for server socket.
 * PARAMETERS
 *  s           : [IN]         socket id
 *  addr        : [OUT]        address of foreign host
 * RETURN VALUES
 *  >=0 : socket id of new connection
 *  SOC_INVALID_SOCKET : invalid socket id
 *  SOC_INVAL : socket is not calling soc_listen
 *  SOC_WOULDBLOCK : non-blocking
 *  SOC_CONNABORTED : server socket cannot receive anymore 
 *  SOC_BEARER_FAIL : bearer broken
 *  SOC_ERROR : unspecified error
 * EXAMPLE
 *  non-blocking plus asyn case:
 * <code>
 *  kal_int8 result;
 *  sockaddr_struct addr;
 *  kal_uint8 local_address[4] = {172, 1, 1, 1};
 *  kal_mem_set(&local, 0x00, sizeof(local));
 *  local.addr_len = 0x04;
 *  local.port = xx;
 *  kal_mem_cpy(local.addr, local_address, local.addr_len);
 *  ret = soc_bind(socket_id, &local);
 *  if (ret < 0)
 *  {
 *      return ERROR;
 *  }
 *  result = soc_listen((kal_int8) handle, 5);
 *  if (result >= 0)
 *  {
 *      result = soc_accept((kal_int8) handle, &addr);
 *      if (result == SOC_WOULDBLOCK)
 *      {
 *          the client socket is not accepted yet
 *      }
 *  }
 * </code>
 *  when the client socket is accepted:
 * <code>
 *  app_soc_accept_ind_hdlr(app_soc_notify_ind_struct *ind)
 *  {
 *      if (ind->event_type == SOC_ACCEPT)
 *      {
 *          soc_accept(...);
 *      }
 *  }
 * </code>
 *
 *  blocking case:
 * <code>
 *  kal_int8 result;
 *  sockaddr_struct addr;
 *  kal_uint8 local_address[4] = {172, 1, 1, 1};
 *  kal_mem_set(&local, 0x00, sizeof(local));
 *  local.addr_len = 0x04;
 *  local.port = xx;
 *  kal_mem_cpy(local.addr, local_address, local.addr_len);
 *  ret = soc_bind(socket_id, &local);
 *  if (ret < 0)
 *  {
 *      return ERROR;
 *  }
 *  result = soc_listen((kal_int8) handle, 5);
 *  if (result >= 0)
 *  {
 *      result = soc_accept((kal_int8) handle, &addr);
 *      if (result >= 0)
 *      {
 *          client socket is accepted
 *      }
 *  } 
 * </code>
 *****************************************************************************/
extern kal_int8 soc_accept(kal_int8 s, sockaddr_struct *addr);

/*****************************************************************************
 * <GROUP  Berkley_API>
 *
 * FUNCTION
 *  soc_connect
 * DESCRIPTION
 *  This function connects to the server and
 *  trigger ABM to establish the corresponding bearer if the bearer is
 *  not established. The server address is specified in the parameter addr.
 *  If you want to use the loopback to do the testing, 
 *  the address you connect should be the "loopback" address, such as 127.0.0.1
 *   
 *  We support three different modes for this function: 
 *  1. blocking mode: 
 *     the result will be returned only after the operation is done.
 *  2. non-blocking mode: 
 *     the result will be returned even if the operation is not done.
 *     However, the user has to query the result by itself.
 *  3. non-blocking plus asyn mode:
 *     the result will be returned even if the operation is not done.
 *     The result will be reported to the user later by the primitive.
 *
 *  By default, if user doesn't set the socket option (SOC_NBIO) 
 *  to change the mode, the mode will be blocking.
 *  Moreover, if you use the non-blocking mode and wants to receive the 
 *  notification event, please set the SOC_ASYN socket option.
 *  Otherwise, there will be no event sent to notify you that the
 *  connection is setup successfully.
 *
 *  P.S. This API only can be used for client socket. For the TCP socket,
 *  it has to call soc_connect before it sends or receives the data.
 * PARAMETERS
 *  s           : [IN]            socket id
 *  addr        : [IN]            pointer of server address 
 * RETURN VALUES
 *  >=0 : socket id of new connection
 *  SOC_INVALID_SOCKET : invalid socket id
 *  SOC_INVAL : addr is NULL
 *  SOC_WOULDBLOCK : in progressing
 *  SOC_ALREADY : already connected or connecting (only happened for non-blocking)
 *  SOC_BEARER_FAIL : bearer broken
 *  SOC_OPNOTSUPP : the socket is already be listened
 *  SOC_ERROR : unspecified error
 * EXAMPLE
 * blocking case:
 * <code>
 *  sockaddr_struct addr;
 *  kal_int8 result;
 *  ...
 *  addr.addr[0] = 10;
 *  addr.addr[1] = 1;
 *  addr.addr[2] = 1;
 *  addr.addr[3] = 1;
 *  addr.addr_len = sizeof(ipn);
 *  addr.port = (unsigned short)port;
 *  result = soc_connect((kal_int8) handle, &addr);
 *  if (result == SOC_SUCCESS)
 *  {
 *     return result;
 *  }
 * </code>
 *
 * non-blocking plus asyn case:
 * <code>
 *  kal_int8 handle;
 *  sockaddr_struct addr;
 *  kal_int8 result;
 *  kal_uint8 option;
 *  handle = 
 *  soc_create(SOC_PF_INET, SOC_SOCK_STREAM, 0, MOD_TEST, nwk_account_id); 
 *  option = SOC_READ | SOC_WRITE | SOC_ACCEPT | SOC_CONNECT | SOC_CLOSE;
 *  result = soc_setsockopt(handle, SOC_ASYNC, &option, sizeof(kal_uint8));
 *  option = KAL_TRUE;
 *  result = soc_setsockopt(handle, SOC_NBIO, &option, sizeof(option));
 *  addr.addr[0] = 10;
 *  addr.addr[1] = 1;
 *  addr.addr[2] = 1;
 *  addr.addr[3] = 1;
 *  addr.addr_len = sizeof(ipn);
 *  addr.port = (unsigned short)port;
 *  result = soc_connect((kal_int8) handle, &addr);
 *  if (result == SOC_WOULDBLOCK)
 *  {
 *    return NOT_DONE;
 *  } 
 * </code>
 *  after the APP_SOC_NOTIFY_IND(SOC_CONNECT) is received:
 * <code>
 * app_soc_notify_ind_hdlr(app_soc_notify_ind_struct *msg)
 * {
 *     if (msg->event_type == SOC_CONNECT)
 *     {
 *        if (msg->result == KAL_TRUE)
 *        {
 *            soc_send(...);
 *        }
 *        else
 *        {
 *            return error;
 *        }
 *     }
 * }
 * </code>
 *****************************************************************************/
extern kal_int8 soc_connect(kal_int8 s, sockaddr_struct *addr);

/*****************************************************************************
 * <GROUP  Berkley_API>
 *
 * FUNCTION
 *  soc_sendto
 * DESCRIPTION
 *  Send the data to the destination. The destination address is specified
 *  in the address "addr". For the UDP socket, if it doesn't specify the address
 *  in "addr", it has to call soc_connect bofore it calls soc_sendto.
 *
 *  SOC will trigger the ABM (Application Bearer Manager) to 
 *  activate the corresponding bearer. However, if the account hasn't been specified at this time, 
 *  a account query will be displayed to ask user which account s/he wants to use to connect to network.
 *  For sending the RAW-type packets, you have to pay attention to some rules listed belw:
 *  1. If your protocol type is "IPPROTO-RAW", you must set the "IP-HDRINCL" option 
 *  at first before you send the packet.
 *  2. If the packet you send is RAW-type packet, this kind of packet cannot be fragmented. 
 *  Therefore, you have pay attention not to send the oversized packet.
 *   
 *  We support three different modes for this function: 
 *  1. blocking mode: 
 *     the result will be returned only after the operation is done.
 *  2. non-blocking mode: 
 *     the result will be returned even if the operation is not done.
 *     However, the user has to query the result by itself.
 *  3. non-blocking plus asyn mode:
 *     the result will be returned even if the operation is not done.
 *     The result will be reported to the user later by the primitive.
 *
 *  By default, if user doesn't set the socket option (SOC_NBIO) 
 *  to change the mode, the mode will be blocking.
 *  Moreover, if you use the non-blocking mode and wants to receive the 
 *  notification event, please set the SOC_ASYN socket option.
 *  Otherwise, there will be no event sent to notify you that you can
 *  keep on transmitting data.
 * PARAMETERS
 *  s           : [IN]   socket id     
 *  buf         : [IN]   contain data to be sent      
 *  len         : [IN]   data length     
 *  flags       : [IN]   flags, eg, out-of-band data. Currently not used, set to zero
 *  addr        : [IN]   destination address 
 * RETURN VALUES
 *  >=0 : SUCCESS
 *  SOC_INVALID_SOCKET : invalid socket id
 *  SOC_INVAL : buf is NULL or len equals to zero
 *  SOC_WOULDBLOCK : buffer not available or bearer is establishing
 *  SOC_BEARER_FAIL : bearer broken
 *  SOC_NOTCONN : socket is not connected in case of TCP
 *  SOC_PIPE : socket is already been shutdown
 *  SOC_MSGSIZE : message is too long
 *  SOC_ERROR : unspecified error
 *  SOC_NOTBIND : in case of sending ICMP Echo Request, shall bind before
 * SEE ALSO
 *   soc_send
 * EXAMPLE
 *  non-blocking plus asyn case:
 * <code>
 *  kal_int8 sod_id;
 *  kal_uint8 *msg_buf;
 *  kal_int32 msg_len;
 *  sockaddr_struct toaddr;
 *  kal_uint8 option;
 *  kal_int8 rt;
 *  soc_id = 
 *  soc_create(SOC_PF_INET, SOC_SOCK_STREAM, 0, MOD_TEST, nwk_account_id); 
 *  option = SOC_READ | SOC_WRITE | SOC_ACCEPT | SOC_CONNECT | SOC_CLOSE;
 *  rt = soc_setsockopt(soc_id, SOC_ASYNC, &option, sizeof(kal_uint8));
 *  option = KAL_TRUE;
 *  rt = soc_setsockopt(soc_id, SOC_NBIO, &option, sizeof(option));
 *  rt = soc_sendto(soc_id, (kal_uint8*) msg_buf, msg_len, 0, &toaddr);
 *  if (rt == SOC_WOULDBLOCK)
 *  {
 *     //data cannot be sent now. you can send it later.
 *  }
 * </code>
 *  when the SOC_WRITE event is received:
 *  app_soc_notify_ind_hdlr(app_soc_notify_ind_struct *ind)
 *  {
 *     if (ind->event_type == SOC_WRITE)
 *     {
 *        soc_sendto(...);
 *     }
 *  }
 *
 *  blocking case:
 * <code>
 *  kal_int8 sod_id;
 *  kal_uint8 *msg_buf;
 *  kal_int32 msg_len;
 *  sockaddr_struct toaddr;
 *  ...
 *  rt = soc_sendto(soc_id, (kal_uint8*) msg_buf, msg_len, 0, &toaddr);
 *  if (rt >= 0)
 *  {
 *     //data is sent out successfully.
 *  } 
 * </code>
 *****************************************************************************/
extern kal_int32 soc_sendto(kal_int8	     s,
                            const void       *buf,
                            kal_int32	     len,
                            kal_uint8 	     flags,
                            sockaddr_struct *addr);

/*****************************************************************************
 * <GROUP  Berkley_API>
 *
 * FUNCTION
 *  soc_send
 * DESCRIPTION
 *  This function sends data to a host which already connected previously.
 *   
 *  We support three different modes for this function: 
 *  1. blocking mode: 
 *     the result will be returned only after the operation is done.
 *  2. non-blocking mode: 
 *     the result will be returned even if the operation is not done.
 *     However, the user has to query the result by itself.
 *  3. non-blocking plus asyn mode:
 *     the result will be returned even if the operation is not done.
 *     The result will be reported to the user later by the primitive.
 *
 *  By default, if user doesn't set the socket option (SOC_NBIO) 
 *  to change the mode, the mode will be blocking.
 *  Moreover, if you use the non-blocking mode and wants to receive the 
 *  notification event, please set the SOC_ASYN socket option.
 *  Otherwise, there will be no event sent to notify you that you can
 *  keep on transmitting data.
 * PARAMETERS
 *  s           : [IN]        socket id
 *  buf         : [IN]        buffer for receiving data     
 *  len         : [IN]        buffer size
 *  flags       : [IN]        flags, eg, out-of-band data. Currently not used, set to zero
 * RETURN VALUES
 *  >=0 : number of bytes sent
 *  SOC_INVALID_SOCKET : invalid socket id
 *  SOC_INVAL : buf is NULL or len equals to zero
 *  SOC_WOULDBLOCK : buffer not available or bearer is establishing
 *  SOC_BEARER_FAIL : bearer broken
 *  SOC_NOTCONN : socket is not connected in case of TCP
 *  SOC_PIPE : socket is already been shutdown
 *  SOC_MSGSIZE : message is too long
 *  SOC_ERROR : unspecified error
 *  SOC_NOTBIND : in case of sending ICMP Echo Request, shall bind before
 * SEE ALSO
 *   soc_sendto
 * EXAMPLE
 *  non-blocking plus asyn case:
 * <code>
 *  kal_int8 sod_id;
 *  kal_uint8 *msg_buf;
 *  kal_int32 msg_len;
 *  sockaddr_struct toaddr;
 *  kal_uint8 option;
 *  kal_int8 rt;
 *  soc_id = 
 *  soc_create(SOC_PF_INET, SOC_SOCK_STREAM, 0, MOD_TEST, nwk_account_id); 
 *  option = SOC_READ | SOC_WRITE | SOC_ACCEPT | SOC_CONNECT | SOC_CLOSE;
 *  rt = soc_setsockopt(soc_id, SOC_ASYNC, &option, sizeof(kal_uint8));
 *  option = KAL_TRUE;
 *  rt = soc_setsockopt(soc_id, SOC_NBIO, &option, sizeof(option));
 *  ...
 *  rt = soc_send(soc_id, (kal_uint8*) msg_buf, msg_len, 0);
 *  if (rt == SOC_WOULDBLOCK)
 *  {
 *     //data cannot be sent now. you can send it later.
 *  }
 * </code>
 *  when the SOC_WRITE event is received:
 *  app_soc_notify_ind_hdlr(app_soc_notify_ind_struct *ind)
 *  {
 *     if (ind->event_type == SOC_WRITE)
 *     {
 *        soc_send(...);
 *     }
 *  }
 *
 *  blocking case:
 * <code>
 *  kal_int8 sod_id;
 *  kal_uint8 *msg_buf;
 *  kal_int32 msg_len;
 *  sockaddr_struct toaddr;
 *  ...
 *  rt = soc_send(soc_id, (kal_uint8*) msg_buf, msg_len);
 *  if (rt >= 0)
 *  {
 *     //data is sent out successfully.
 *  } 
 * </code>
 *****************************************************************************/
extern kal_int32 soc_send(kal_int8	 s,
                          const void *buf,
                          kal_int32  len,
                          kal_uint8	 flags);

/*****************************************************************************
 * <GROUP  Berkley_API>
 *
 * FUNCTION
 *  soc_sendmsg
 * DESCRIPTION
 *  This function sends data to a host by multiple buffers.
 *   
 *  We support three different modes for this function: 
 *  1. blocking mode: 
 *     the result will be returned only after the operation is done.
 *  2. non-blocking mode: 
 *     the result will be returned even if the operation is not done.
 *     However, the user has to query the result by itself.
 *  3. non-blocking plus asyn mode:
 *     the result will be returned even if the operation is not done.
 *     The result will be reported to the user later by the primitive.
 *
 *  By default, if user doesn't set the socket option (SOC_NBIO) 
 *  to change the mode, the mode will be blocking.
 *  Moreover, if you use the non-blocking mode and wants to receive the 
 *  notification event, please set the SOC_ASYN socket option.
 *  Otherwise, there will be no event sent to notify you that you can
 *  keep on transmitting data.
 * PARAMETERS
 *  s           : [IN]        socket id
 *  buf         : [IN]        buffer for receiving data     
 *  len         : [IN]        buffer size
 *  flags       : [IN]        flags, eg, out-of-band data. Currently not used, set to zero
 * RETURN VALUES
 *  >=0 : number of bytes sent
 *  SOC_INVALID_SOCKET : invalid socket id
 *  SOC_INVAL : buf is NULL or len equals to zero
 *  SOC_WOULDBLOCK : buffer not available or bearer is establishing
 *  SOC_BEARER_FAIL : bearer broken
 *  SOC_NOTCONN : socket is not connected in case of TCP
 *  SOC_PIPE : socket is already been shutdown
 *  SOC_MSGSIZE : message is too long
 *  SOC_ERROR : unspecified error
 *  SOC_NOTBIND : in case of sending ICMP Echo Request, shall bind before
 * SEE ALSO
 *   soc_sendto
 * EXAMPLE
 *  non-blocking plus asyn case:
 * <code>
 *   soc_msghdr_struct msghdr;
 *   soc_iovec_struct iov;
 *   memset(&msghdr, 0, sizeof(msghdr));
 *   iov.iov_buf = (void *)data;
 *   iov.iov_len = dataLen;
 *   msghdr.iov = (void *)&iov;
 *   msghdr.iov_num = 1;
 *   error = soc_sendmsg((kal_int8)socketId, (soc_msghdr_struct *)&msghdr, 0);
 * </code>
 *****************************************************************************/
extern kal_int32 soc_sendmsg(kal_int8      s,
                    soc_msghdr_struct *buf,
                    kal_uint32       flags);

/*******************************************************************************
 * <GROUP  Berkley_API>
 *
 * FUNCTION  
 *  soc_recvfrom
 * Description
 *  Receive data and return the source address.
 *  When we receive the FIN from the peer side, we would return 0.
 *  This is normal Berkeley socket behavior.
 * 
 *  We support three different modes for this function:
 * 
 * 
 * 
 * 
 *   1. blocking mode: the result will be returned only after the
 *      operation is done.
 *   2. non-blocking mode: the result will be returned even if the
 *      operation is not done. However, the user has to query the result by
 *      itself.
 *   3. non-blocking plus asyn mode: the result will be returned even if
 *      the operation is not done. The result will be reported to the user
 *      later by the primitive.
 * 
 *  By default, if user doesn't set the socket option (SOC_NBIO)
 *  to change the mode, the mode will be blocking.
 *  Moreover, if you use the non-blocking mode and wants to receive the
 *  notification event, please set the SOC_ASYN socket option.
 *  Otherwise, there will be no event sent to notify you that you can
 *  keep on receiving data.
 * 
 *  SOC will trigger the ABM (Application Bearer Manager) to activate the
 *  corresponding bearer
 *  if the network account specified by nwk_account_id is not opened yet.
 *  However, if the account hasn't been specified at this time,
 *  a query would be sent from socket to MMI to ask user which account s/he
 *  wants to use to
 *  connect to network.
 * 
 *  Note that for SMS sockets, the SC and OA addresses are passed back to
 *  fromaddr.
 *  This is an example of returned fromaddr, note that our system is
 *  little-endian byte ordered.
 * 
 * 
 * 
 * 
 *   1. The first two bytes is the socket_type field. It is set to
 *      SOC_SOCK_SMS for SMS push message to be distinguished from normal UDP
 *      sockets, which is set to SOC_DGRAM.
 *   2. The following two bytes is the addr_len, standing for the valid
 *      bytes in the following
 *   3. addr[0-11]: the SC address, the first byte is the length in bytes.
 *      The first byte (0x07) claims the length of SC address including the
 *      number plan byte. The fist byte in SC address (0x91) is numbering plan.
 *      Therefore, the SC address is 886938348409, in least significant nibble
 *      first format.
 *   4. addr[12-23]: the OA address. the first byte is the length in
 *      bytes. The first byte (0x07) claims the length of OA address including
 *      the numbering plan byte. The fist byte in OA address (0x91) is
 *      numbering plan. Therefore, the OA address is 886913216106, in least
 *      significant nibble first format.
 *   5. port in the fromaddr in this example is the last block 0xF023.
 *      0xF023 in little-endian byte order equals 9200 in decimal.
 *   6. There is an unused 4-byte in this address format. We hide the SIM
 *      info within the 4 bytes for SMS. For UDP push, we not only hide the SIM
 *      info in these four bytes but the account info as well. User can use the
 *      macro &quot;(kal_uint8 *)SOCK_ACCT_ID((kal_uint8 *)addr)&quot; to
 *      obtain the account info.
 *  <img name="sap_app_soc_sms_content" />
 *  For receiving ICMP packets, the user data contains the ICMP header.
 *  Note that this is also applied to soc_recv.
 * Parameters
 *  s :         [IN] socket id
 *  buf :       [IN] buffer for receiving data
 *  len :       [IN] buffer size
 *  flags :     [IN] flags
 *  fromaddr :  [OUT] remote addess 
 * Return Values
 *  0 :                   receive the FIN from the server
 *  SOC_INVALID_SOCKET :  invalid socket id
 *  SOC_INVAL :           buf is NULL or len equals to zero
 *  SOC_WOULDBLOCK :      no data available
 *  SOC_BEARER_FAIL :     bearer broken
 *  SOC_NOTCONN :         socket is not connected in case of TCP
 *  SOC_PIPE :            socket is already been shutdown
 *  SOC_ERROR :           unspecified error
 *  See Also
 *  soc_recv
 * Example
 *  non-blocking plus aysn case:
 * 
 * <code>
 *  kal_int8 soc_id;
 *  kal_uint8 *recv_buf;
 *  kal_int32 recv_buf_len;
 *  sockaddr_struct fromaddr;
 *  kal_uint8 option;
 *  kal_int8 rt;
 *  soc_id =
 *  soc_create(SOC_PF_INET, SOC_SOCK_STREAM, 0, MOD_TEST, nwk_account_id);
 *  option = SOC_READ | SOC_WRITE | SOC_ACCEPT | SOC_CONNECT | SOC_CLOSE;
 *  rt = soc_setsockopt(soc_id, SOC_ASYNC, &amp;option, sizeof(kal_uint8));
 *  option = KAL_TRUE;
 *  rt = soc_setsockopt(soc_id, SOC_NBIO, &amp;option, sizeof(option));
 *  rt = soc_recvfrom(
 *              soc-&gt;soc_id,
 *              recv_buf,
 *              recv_buf_len,
 *              0,
 *              &amp;fromaddr);
 *  if (rt &gt;= 0)
 *  {
 *     //received the data or FIN from the peer side.
 *  }
 *  else if (rt == SOC_WOULDBLOCK)
 *  {
 *     //The data is not received yet and will receive the SOC_READ later.
 *  }
 * </code>
 * receive the SOC_READ:
 * 
 * <code>
 *  app_soc_notify_ind_hdlr(app_soc_notify_ind_struct *ind)
 *  {
 *      if (ind-&gt;recv_event == SOC_READ)
 *      {
 *          soc_recvfrom(...);
 *      }
 *  }
 * </code>
 * 
 * 
 * 
 * 
 * 
 * blocking case:
 * 
 * <code>
 *  kal_int8 soc_id;
 *  kal_uint8 *recv_buf;
 *  kal_int32 recv_buf_len;
 *  sockaddr_struct fromaddr;
 *  ...
 *  rt = soc_recvfrom(
 *              soc-&gt;soc_id,
 *              recv_buf,
 *              recv_buf_len,
 *              0,
 *              &amp;fromaddr);
 *  if (rt &gt;= 0)
 *  {
 *      //received the data from the peer side.
 *  }
 * </code>                                                                     
 *******************************************************************************/
extern kal_int32 soc_recvfrom(kal_int8        s,
                              void            *buf,
                              kal_int32       len,
                              kal_uint8       flags,
                              sockaddr_struct *fromaddr);

/*****************************************************************************
 * <GROUP  Berkley_API>
 *
 * FUNCTION
 *  soc_recv
 * DESCRIPTION
 *  This function receives data from a host connected previously.
 *  When we receive the FIN from the peer side, we would return 0. 
 *  This is normal Berkeley socket behavior.
 *   
 *  We support three different modes for this function: 
 *  1. blocking mode: 
 *     the result will be returned only after the operation is done.
 *  2. non-blocking mode: 
 *     the result will be returned even if the operation is not done.
 *     However, the user has to query the result by itself.
 *  3. non-blocking plus asyn mode:
 *     the result will be returned even if the operation is not done.
 *     The result will be reported to the user later by the primitive.
 *
 *  By default, if user doesn't set the socket option (SOC_NBIO) 
 *  to change the mode, the mode will be blocking.
 *  Moreover, if you use the non-blocking mode and wants to receive the 
 *  notification event, please set the SOC_ASYN socket option.
 *  Otherwise, there will be no event sent to notify you that you can
 *  keep on receiving data.
 *
 *  How to Handle the asynchronous event SOC_READ for incoming packet is listed below:
 *  In order to suppress SOC_NOTIFY_INDs for incoming packets, 
 *  there is a mechanism implemented in Socket:
 *  Socket will NOT send SOC_NOTIFY_IND for each incoming packet.
 *  Socket will send SOC_NOTIFY_IND only when socket's queue is empty. 
 *  For example, the 1st incoming packet will trigger the 1st SOC_NOTIFY_IND 
 *  and the 2nd incoming packet will NOT trigger 2nd SOC_NOTIFY_IND 
 *  (because socket's queue is not empty).
 *  Thus, the application shall continue to receive all data until it gets SOC_WOULDBLOCK 
 *  from soc_recv() or soc_recvfrom(). Like the example code:
 * PARAMETERS
 *  s           : [IN]            socket id 
 *  buf         : [IN]        buffer for receiving data            
 *  len         : [IN]            buffer size
 *  flags       : [IN]        flags. If the flag SOC_MSG_PEEK is set, the data will
 *                            not be removed form the received buffer. We just peek 
 *                            at what have been received in the receive buffer.
 *                            If the flag SOC_MSG_TRUNC is set, the UDP data which exceeds
 *                            the receive buffer size will be truncated. If this flag is not
 *                            set, the UDP packet which exceeds the receive buffer size will
 *                            be dropped.
 * RETURN VALUES
 *  >0 : number of bytes received
 *   0 : receive the FIN from the server
 *  SOC_INVALID_SOCKET : invalid socket id
 *  SOC_INVAL : buf is NULL or len equals to zero
 *  SOC_WOULDBLOCK : no data available 
 *  SOC_BEARER_FAIL : bearer broken
 *  SOC_NOTCONN : socket is not connected in case of TCP
 *  SOC_PIPE : socket is already been shutdown
 *  SOC_ERROR : unspecified error
 * SEE ALSO
 *   soc_recvfrom
 * EXAMPLE
 * <code>
 *  void app_recv_handler()
 * {
 *   kal_int8 handle;
 *   kal_int32 rt;
 *   kal_uint8 option;
 *   handle = 
 *   soc_create(SOC_PF_INET, SOC_SOCK_STREAM, 0, MOD_TEST, nwk_account_id); 
 *   option = SOC_READ | SOC_WRITE | SOC_ACCEPT | SOC_CONNECT | SOC_CLOSE;
 *   rt = soc_setsockopt(handle, SOC_ASYNC, &option, sizeof(kal_uint8));
 *   option = KAL_TRUE;
 *   rt = soc_setsockopt(handle, SOC_NBIO, &option, sizeof(option));
 *   do {
 *     rt = soc_recv(...);
 *     if (rt > 0) {
 *       //process the received data
 *     }
 *   } while (rt > 0);
 *
 *   if (rt < 0 && rt != SOC_WOULDBLOCK) {
 *     //error handling
 *   }
 *
 *   if(rt == 0)
 *   {
 *	   //we receive the FIN from the peer side
 *   }
 *   else if (rt == SOC_WOULDBLOCK)
 *   {
 *      //not done yet and will receive SOC_READ later.
 *   }
 *   else
 *   {
 *      //receive the data successfully
 *   }
 * }
 * </code>   
 *****************************************************************************/
extern kal_int32 soc_recv(kal_int8  s,
                          void *buf,
                          kal_int32 len,
                          kal_uint8 flags);

/*****************************************************************************
 * <GROUP  Berkley_API>
 *
 * FUNCTION
 *  soc_recvmsg
 * DESCRIPTION
 *  This function receives data from a host connected previously and put received
 *  data into multiple receive buffers.
 *  When we receive the FIN from the peer side, we would return 0. 
 *  This is normal Berkeley socket behavior.
 *   
 *  We support three different modes for this function: 
 *  1. blocking mode: 
 *     the result will be returned only after the operation is done.
 *  2. non-blocking mode: 
 *     the result will be returned even if the operation is not done.
 *     However, the user has to query the result by itself.
 *  3. non-blocking plus asyn mode:
 *     the result will be returned even if the operation is not done.
 *     The result will be reported to the user later by the primitive.
 *
 *  By default, if user doesn't set the socket option (SOC_NBIO) 
 *  to change the mode, the mode will be blocking.
 *  Moreover, if you use the non-blocking mode and wants to receive the 
 *  notification event, please set the SOC_ASYN socket option.
 *  Otherwise, there will be no event sent to notify you that you can
 *  keep on receiving data.
 *
 *  How to Handle the asynchronous event SOC_READ for incoming packet is listed below:
 *  In order to suppress SOC_NOTIFY_INDs for incoming packets, 
 *  there is a mechanism implemented in Socket:
 *  Socket will NOT send SOC_NOTIFY_IND for each incoming packet.
 *  Socket will send SOC_NOTIFY_IND only when socket's queue is empty. 
 *  For example, the 1st incoming packet will trigger the 1st SOC_NOTIFY_IND 
 *  and the 2nd incoming packet will NOT trigger 2nd SOC_NOTIFY_IND 
 *  (because socket's queue is not empty).
 *  Thus, the application shall continue to receive all data until it gets SOC_WOULDBLOCK 
 *  from soc_recv() or soc_recvfrom(). Like the example code:
 * PARAMETERS
 *  s           : [IN]            socket id 
 *  buf         : [IN]        buffer for receiving data            
 *  len         : [IN]            buffer size
 *  flags       : [IN]        flags. If the flag SOC_MSG_PEEK is set, the data will
 *                            not be removed form the received buffer. We just peek 
 *                            at what have been received in the receive buffer.
 *                            If the flag SOC_MSG_TRUNC is set, the UDP data which exceeds
 *                            the receive buffer size will be truncated. If this flag is not
 *                            set, the UDP packet which exceeds the receive buffer size will
 *                            be dropped.
 * RETURN VALUES
 *  >0 : number of bytes received
 *   0 : receive the FIN from the server
 *  SOC_INVALID_SOCKET : invalid socket id
 *  SOC_INVAL : buf is NULL or len equals to zero
 *  SOC_WOULDBLOCK : no data available 
 *  SOC_BEARER_FAIL : bearer broken
 *  SOC_NOTCONN : socket is not connected in case of TCP
 *  SOC_PIPE : socket is already been shutdown
 *  SOC_ERROR : unspecified error
 * SEE ALSO
 *   soc_recvfrom
 * EXAMPLE
 * <code>
 *   soc_msghdr_struct msg;
 *   soc_iovec_struct iov;
 *   memset(&msg, 0, sizeof(soc_msghdr_struct));
 *   iov.iov_buf = buf;
 *   iov.iov_len = bufLen;
 *   msg.iov = &iov;
 *   msg.iov_num = 1;
 *   error = soc_recvmsg((kal_int8) socketId, &msg, 0);
 *   memcpy(&sockaddr, &msg.addr, sizeof(sockaddr));   
 * </code>   
 *****************************************************************************/
extern kal_int32 soc_recvmsg(kal_int8 s, soc_msghdr_struct *buf, kal_uint32 flags);

#ifndef GEN_FOR_PC

/*****************************************************************************
 * <GROUP  Berkley_API>
 *
 * FUNCTION
 *  soc_select
 * DESCRIPTION
 *  Allow the application to query the status of multiple sockets.
 *  If tv is null, soc_select will wait indefinitely until the first socket is ready. 
 *  If both tv_sec and tv_msec are zero, soc_select will timeout immediately for 
 *  polling the sockets in the set.
 *  in: 
 *  1. If listen has been called and a connection is pending, accept will succeed. 
 *  2. Data is available for reading (includes OOB data if SOC_OOBINLINE is enabled). 
 *  3. Connection has been closed/reset/terminated
 *  out: 
 *  1. If processing a connect request (non-blocking mode), connection has succeeded. 
 *  2. Data can be sent. 
 *  ex: 
 *  If processing a connect request (non-blocking mode), connection attempt failed. 
 *  OOB data is available for reading (only if SOC_OOBINLINE is disabled).
 *  Useful Macros:
 *   SOC_FD_ZERO(soc_fd_set)		 reset soc_fd_set
 *   SOC_FD_SET(s, soc_fd_set)		 add a particular socket with id of s to soc_fd_set
 *   SOC_FD_CLR(s, soc_fd_set)		 remove a particular socket with id of s from soc_fd_set
 *   SOC_FD_ISSET(s, soc_fd_set)	 Nonzero if s is a member of the soc_fd_set (s is ready). 
 *                                   Otherwise, zero 
 *   SOC_FD_COPY(fd_orig, fd_copy)	 replace soc_fd_set in fd_copy with soc_fd_set in fd_orig
 * PARAMETERS
 *  ndesc       : [IN]            max selected socket id plus 1
 *  in          : [IN]        input soc_fd_set (readfds)
 *  out         : [IN]        output soc_fd_set (writefds)
 *  ex          : [IN]        exception soc_fd_set (exceptfds)
 *  tv          : [IN]            specify the timeout value,
 *                              tv == NULL: block until ready
 *                              tv != NULL && value == 0: return immediately
 *                              tv != NULL && value != 0: return after timeout
 * RETURN VALUES
 *  >0 :                     number of ready sockets
 *   0 :                     timeout expires before anything interesting happens
 *  SOC_INVALID_SOCKET :	 selected sockets are not belong to this module
 *  SOC_INVAL : 			 invalid arguments: ndesc, in, out, ex
 *  SOC_WOULDBLOCK :		 non-blocking
 *  SOC_BEARER_FAIL :		 bearer broken
 *  SOC_ERROR :	    		 unspecified error
 * EXAMPLE
 * <code>
 *  soc_timeval_struct timeout;
 *  soc_fd_set writefds;
 *  timeout.tv_sec = 0;
 *  timeout.tv_usec = 2000;
 *  SOC_FD_ZERO(&writefds);
 *  SOC_FD_SET((bf_u32)sockIds[sock].id, &writefds);
 *  if (soc_select(sockIds[sock].id+1, 0, &writefds, 0, &timeout) >= 0)
 *  {
 *     if (SOC_FD_ISSET(sockIds[sock].id, &writefds))
 *     {
 *         //socket is ready for writting data
 *     }
 *  }
 * </code>   
 *****************************************************************************/
extern kal_int8 soc_select(kal_uint8  ndesc,
                           soc_fd_set     *in,
                           soc_fd_set     *out,
                           soc_fd_set     *ex,
                           soc_timeval_struct *tv);
#endif /* !GEN_FOR_PC */

/*****************************************************************************
 * <GROUP  Berkley_API>
 *
 * FUNCTION
 *  soc_shutdown
 * DESCRIPTION
 *  This function shutdowns the connection in aspects of reading, writing
 *  or both. 
 *  For the read-half, soc_shutdown discards the received data that applications haven't yet 
 *  and any incoming data. For the write-half of TCP, the remaining data will be sent first, 
 *  then FIN will be sent to close the connection.
 * PARAMETERS
 *  s           : [IN]        socket id
 *  how         : [IN]        specify shutdown read/write/both
 * RETURN VALUES
 *  SOC_SUCCESS : success
 *  SOC_INVALID_SOCKET : invalid socket id
 *  SOC_INVAL : invalid how
 *  SOC_ERROR : unspecified error
 * EXAMPLE
 * <code>
 * kal_int8 handle;
 * soc_shutdown((kal_int8) handle, SHUT_WR);
 * </code>
 *****************************************************************************/
extern kal_int8 soc_shutdown(kal_int8 s, kal_uint8 how);

/*****************************************************************************
 * <GROUP  Berkley_API>
 *
 * FUNCTION
 *  soc_setsockopt
 * DESCRIPTION
 *  This function sets the socket options.
 * PARAMETERS
 *  s               : [IN]        socket id
 *  option          : [IN]        option type (soc_option_enum)
 *  val             : [IN]         option value (soc_event_enum for SOC_ASYNC)
 *  val_size        : [IN]        option value size
 * RETURN VALUES
 *  SOC_SUCCESS :            success
 *  SOC_INVALID_SOCKET :	 invalid socket id
 *  SOC_INVAL :			     invalid arguments: option, val and val_size
 *  SOC_ERROR :			     unspecified error
 * SEE ALSO
 *   soc_getsockopt
 * EXAMPLE
 * SOC_NBIO:
 * this option must to be set if you want to use the non-blocking mode or
 * non-blocking plus asyn mode.
 * val contains KAL_TRUE indicates non-blocking shall be adopted, 
 * KAL_FALSE indicates blocking mode shall be adopted. 
 * For example, set a socket to non-blocking mode:
 * kal_bool val = KAL_TRUE;
 * soc_setsockopt(s, SOC_NBIO, &val, sizeof(kal_bool));
 *
 * SOC_SILENT_LISTEN:
 * val contains KAL_TRUE indicates the silent listen shall be adopted, 
 * KAL_FALSE indicates non-silent listen shall be adopted. 
 * This is SOC_SOCK_SMS property. For example, if you want to let the socket be 
 * the passive to activate the bear, you can set a socket to silent listen mode:
 * For example:
 * kal_bool val = KAL_TRUE;
 * soc_setsockopt(s, SOC_SILENT_LISTEN, &val, sizeof(kal_bool))
 *
 * SOC_UDP_NEED_ICMP:
 * This option is used to deliver NOTIFY(close) for ICMP error.
 * val contains KAL_TRUE indicates this option shall be enabled, 
 * KAL_FALSE indicates this option shall be disabled. 
 * For example, if you want to let set a socket to UDP NEED ICMP mode:
 * kal_bool val = KAL_TRUE;
 * soc_setsockopt(s, SOC_UDP_NEED_ICMP, &val, sizeof(kal_bool))
 *
 * SOC_ASYNC:
 * this option needs to be set if you want to use the non-blocking plus asyn mode.
 * val contains the events application wants to receive. 
 * For example, if application wants to receive 
 * READ/WRITE/CLOSE/CONNECT events, 
 * it shall call soc_setsockopt like the following:
 * kal_uint8 val = 0;
 * val = SOC_READ | SOC_WRITE | SOC_CLOSE | SOC_CONNECT;
 * soc_setsockopt(s, SOC_ASYNC, &val, sizeof(kal_uint8));
 * P.S. if you are using the server socket, please remember to set the SOC_ACCPET event.
 *
 * SOC_TCP_MAXSEG:
 * A process can only decrease the MSS. When a TCP socket is created, 
 * the default MSS is set to 512. The MSS is updated according to the value announced 
 * from peer TCP after the socket completes TCP three-way handshake. 
 * Therefore, after a socket is created but before connected, a process can only decrease 
 * the MSS from its default of 512. After a connection is established, 
 * the process can decrease the MSS from the new updated value.
 *
 * The value of TCP MSS is reduced to fit the interface MTU if the application set an 
 * unacceptable large value.
 * For example:
 * kal_uint8 val = 512;
 * soc_setsockopt(s, SOC_TCP_MAXSEG, &val, sizeof(kal_uint8)); 
 *
 * SOC_LISTEN_BEARER:
 * val contains bear type indicates which kind of bear we want to receive packets from. 
 * For example, set a socket to receive the WiFi bear:
 * kal_uint8 val = SOC_BEARER_WIFI;
 * soc_setsockopt(s, SOC_LISTEN_BEARER, &val, sizeof(kal_uint8));
 *
 * SOC_WIFI_NOWAKEUP:
 * val contains KAL_TRUE indicates this option shall be enabled, 
 * KAL_FALSE indicates this option shall be disabled. 
 * This option is to make WNDRV sends outgoing packet to in power saving mode. 
 * For example:
 * kal_bool val = KAL_TRUE;
 * soc_setsockopt(s, SOC_WIFI_NOWAKEUP, &val, sizeof(kal_bool))
 *
 * SOC_IP_HDRINCL:
 * val contains KAL_TRUE indicates this option shall be enabled, 
 * KAL_FALSE indicates this option shall be disabled. If this option is set for a raw IP socket, 
 * we must build our own IP header for all the datagrams that we send on the raw socket. 
 * We can only set this socket option if the socket type in soc_create is 
 * SOC_SOCK_RAW(raw socket) and protocol in soc_create is not SOC_IPPROTO_ICMP.
 * For example:
 * kal_bool val = KAL_TRUE;
 * soc_setsockopt(s, SOC_IP_HDRINCL, &val, sizeof(kal_bool))
 *
 * SOC_UDP_ANY_FPORT:
 * val contains KAL_TRUE indicates this option shall be enabled, 
 * KAL_FALSE indicates this option shall be disabled. For a connected UDP socket, 
 * this option makes socket deliver incoming packet from the same remote 
 * address but different remote port. 
 * For example:
 * kal_bool val = KAL_TRUE;
 * soc_setsockopt(s, SOC_UDP_ANY_FPORT, &val, sizeof(kal_bool))
 *
 * SOC_IP_TTL:
 * val contains the TTL values . If you want to change the default TTL (64), 
 * you can set this option. For example:
 * kal_uint8 val = 128;
 * soc_setsockopt(s, SOC_IP_TTL, &val, sizeof(kal_uint8))
 *
 * SOC_QOS:
 * val contains the TOS values . If you want to set the TOS values, you can set this option. 
 * For example:
 * kal_uint8 val = 0x80;
 * soc_setsockopt(s, SOC_QOS, &val, sizeof(kal_uint8))
 *
 * SOC_KEEPALIVE:
 * val contains KAL_TRUE indicates this option shall be enabled, 
 * KAL_FALSE indicates this option shall be disabled. 
 * You can use this option to enable or disable the keep-alive timer in TCP. 
 * For example:
 * kal_bool val = KAL_TRUE;
 * soc_setsockopt(s, SOC_KEEPALIVE, &val, sizeof(kal_bool))
 *
 * SOC_NODELAY:
 * val contains KAL_TRUE indicates this option shall be enabled, 
 * KAL_FALSE indicates this option shall be disabled. 
 * If you want to send the packet directly without waiting a packet size larger than MSS, 
 * you can set this option. For example:
 * kal_bool val = KAL_TRUE;
 * soc_setsockopt(s, SOC_NODELAY, &val, sizeof(kal_bool))
 *
 * SOC_SENDBUF:
 * val contains the value of send buffer's high water mark.  
 * If you want to set the high water mark, you can set this option. 
 * If the value you set is smaller than the MSS, the mss would be adjusted to this value. 
 * The value must be greater than 0 and smaller than the SSPDU + SSPDU_GROW. 
 * For example:
 * kal_uint32 val = 1024;
 * soc_setsockopt(s, SOC_SENDBUF, &val, sizeof(kal_uint32))
 *
 * SOC_RECVBUF:
 * val contains the value of receive buffer's high water mark.  
 * If you want to set the high water mark, you can set this option. 
 * This value must be greater than 0 and smaller than the SRPDU size.  
 * For example:
 * kal_uint32 val = 4096;
 * soc_setsockopt(s, SOC_RECVBUF, &val, sizeof(kal_uint32))
 *
 * SOC_LINGER:
 * val contains the value of enable/diable LINGER option and the value of LINGER time. 
 * This option is used in linger on close. 
 * For example:
 * soc_linger_struct val; 
 * val.onoff = KAL_TRUE; val.
 * linger_time = 3; (sec)
 * soc_setsockopt(s, SOC_LINGER, &val, sizeof(soc_linger_struct_val));
 *
 * SOC_IPSEC_POLICY:
 * val contains sadb_x_policy structure content.
 * You can set this option to set the IPSEC policy.
 * If you want to get the IPSEC policy, 
 * you can set this option. For example:
 * struct sadb_x_policy policy;
 * policy.sadb_x_policy_len = PFKEY_UNIT64(sizeof(policy));
 * policy.sadb_x_policy_exttype = SADB_X_EXT_POLICY;
 * policy.sadb_x_policy_type = 4;  // IPSEC_POLICY_BYPASS;
 * policy.sadb_x_policy_dir = 1;   // IPSEC_DIR_INBOUND;
 * soc_setsockopt(s, SOC_IPSEC_POLICY, &policy, sizeof(sadb_x_policy))
 *
 * SOC_TCP_DELAYED_ACK:
 * The SOC_TCP_DELAYED_ACK function is enable by default. That is to say, 
 * if you don't set this option. The default SOC_TCP_DELAYED_ACK value is TRUE.
 * val contains KAL_TRUE indicates this option shall be enabled, 
 * KAL_FALSE indicates this option shall be disabled. 
 * If you want to enable the "TCP no delay" function, 
 * you can set this option. For example:
 * kal_bool val = KAL_TRUE;
 * soc_setsockopt(s, SOC_TCP_DELAYED_ACK, &val, sizeof(kal_bool))
 *
 * SOC_TCP_SACK:
 * The SOC_TCP_SACK function is enable by default. That is to say, 
 * if you don't set this option. The default SOC_TCP_SACK value is TRUE.
 * val contains KAL_TRUE indicates this option shall be enabled, 
 * KAL_FALSE indicates this option shall be disabled. 
 * If you want to enable the "TCP SACK" function, 
 * you can set this option. For example:
 * kal_bool val = KAL_TRUE;
 * soc_setsockopt(s, SOC_TCP_SACK, &val, sizeof(kal_bool)) 
 *
 * SOC_TCP_TIME_STAMP:
 * The SOC_TCP_TIME_STAMP function is enable by default. That is to say, 
 * if you don't set this option. The default SOC_TCP_TIME_STAMP value is TRUE.
 * val contains KAL_TRUE indicates this option shall be enabled, 
 * KAL_FALSE indicates this option shall be disabled. 
 * If you want to enable the "TCP TIME STAMP" function, 
 * you can set this option. For example:
 * kal_bool val = KAL_TRUE;
 * soc_setsockopt(s, SOC_TCP_TIME_STAMP, &val, sizeof(kal_bool)) 
 *
 *****************************************************************************/
extern kal_int8 soc_setsockopt(kal_int8   s,
                               kal_uint32 option,
                               void       *val,
                               kal_uint8  val_size);

/*****************************************************************************
 * <GROUP  Berkley_API>
 *
 * FUNCTION
 *  soc_getsockopt
 * DESCRIPTION
 *  This function gets the socket options.
 * PARAMETERS
 *  s               : [IN]        socket id
 *  option          : [IN]        option type (soc_option_enum)
 *  val             : [IN]    option value
 *  val_size        : [IN]        option value size
 * RETURN VALUES
 *  SOC_SUCCESS :        get the socket option successfully
 *  SOC_INVALID_SOCKET : invalid socket id
 *  SOC_INVAL :			 invalid arguments: option, val and val_size
 *  SOC_ERROR :			 unspecified error
 * SEE ALSO
 *   soc_setsockopt
 * EXAMPLE
 *  SOC_ASYNC:
 *  return the option value of configured asyn event.
 *  <code>
 *  kal_uint8 event;
 *  soc_getsockopt(socket_id, SOC_ASYNC, &event, sizeof(event));
 *  </code>
 *  
 * SOC_TCP_DELAYED_ACK:
 * val contains kal_bool to hold the option behavior.
 * If you don't set this option, the default value you get is KAL_TRUE.
 * If you to get this option, you can do:
 * <code>
 * kal_bool val;
 * soc_getsockopt(s, SOC_TCP_DELAYED_ACK, &val, sizeof(kal_bool))
 * </code>
 *
 * SOC_TCP_SACK:
 * val contains kal_bool to hold the option behavior.
 * If you don't set this option, the default value you get is KAL_TRUE.
 * If you to get this option, you can do:
 * <code>
 * kal_bool val;
 * soc_getsockopt(s, SOC_TCP_SACK, &val, sizeof(kal_bool))
 * </code>
 *
 * SOC_TCP_TIME_STAMP:
 * val contains kal_bool to hold the option behavior.
 * If you don't set this option, the default value you get is KAL_TRUE.
 * If you to get this option, you can do:
 *  <code>
 *  kal_bool val;
 *  soc_getsockopt(s, SOC_TCP_TIME_STAMP, &val, sizeof(kal_bool))
 *  </code>  
 *****************************************************************************/
extern kal_int8 soc_getsockopt(kal_int8   s,
                               kal_uint32 option,
                               void       *val,
                               kal_uint8  val_size);

/*****************************************************************************
 * <GROUP  Others>
 *
 * FUNCTION
 *  soc_setsockqos
 *
 * DESCRIPTION
 *  Set QoS requirement to a socket
 *
 * PARAMETERS
 *  s               : [IN]        socket id
 *  qos_profile_id  : [IN]        profile id,
 *                              use SOC_NEW_QOS_PROFILE to create new profile
 *  app_type        : [IN]        application type
 *  bandwidth       : [IN]        required bandwidth in kilobits per second
 *  dl_filter_num   : [IN]        number of filters in parameter dl_filter (<=8)
 *  dl_filter       : [IN]        pointer to a list of downlink filters
 *
 * RETURN VALUES
 *  SOC_SUCCESS : success
 *  negative : fail
 *****************************************************************************/
extern kal_int8 soc_setsockqos(kal_int8 s,
                               kal_uint8 *qos_profile_id, 
                               custom_app_qos_type_enum app_type,
                               kal_uint16 bandwidth,
                               kal_uint8 dl_filter_num,
                               soc_dl_filter_struct *dl_filter);

/* currently, this function only support non-blocking mode */

/*****************************************************************************
 * <GROUP  DNS_API>
 *
 * FUNCTION
 *  soc_gethostbyname
 * DESCRIPTION
 *  This function gets the IP of the given domain name.
 *  Get a host address (i.e., IP address) by its domain name. 
 *  Only one host address is obtained through this function. 
 *  If the bearer is not activated when this API is called, 
 *  the bearer activation would be triggered. However, 
 *  if the account id is not specified in soc_gethostbyname, 
 *  an account query would be displayed to ask the user which account 
 *  s/he wants to use.
 *  
 *  This API only supports the non-blokcing mode, i.e., 
 *  is_blocking shall be set to KAL_FALSE.
 *  Thus, soc_gethostbyname will be returned immediately instead of 
 *  blocking and waiting for the result. 
 *  If user doesn't get the returned value directly after it calls this API,
 *  the returned value "SOC_WOULDBLOCK" will be returned normally.
 *  SOC will send a notification to application when it gets the response 
 *  of previous DNS query later.
 *  On the contrary, if user gets the result directly, the result will be 
 *  returned directly in the parameter "addr".
 * PARAMETERS
 *  is_blocking         : [IN]        whether block or non-block mode are used,
 *                                  currently only support non-block mode
 *  mod_id              : [IN]        module id
 *  request_id          : [IN]        embedded in response message
 *  domain_name         : [IN]        Domain_name
 *  addr                : [IN]        resolved address
 *  addr_len            : [IN/OUT]    address length     
 *  access_id           : [IN]        embedded in response message
 *  nwk_account_id      : [IN]        Nwk_account_id
 * RETURN VALUES
 *  SOC_SUCCESS :			     Get IP address successfully
 *  SOC_INVAL :			         invalid arguments: null domain_name, etc.
 *  SOC_ERROR :			         unspecified error
 *  SOC_WOULDBLOCK :		     wait response from network
 *  SOC_LIMIT_RESOURCE :		 socket resources not available
 * EXAMPLE
 * <code>
 * ret = soc_gethostbyname(
 *           KAL_FALSE,
 *           MOD_SAF,
 *           ch_id,
 *           (const kal_char*)ch->stun_addr,
 *           ch->stun_ip_addr.addr,
 *           (kal_uint8*) & ch->stun_ip_addr.addr_len,
 *           0,
 *           ch->data_account_id);
 *
 *   if (ret == SOC_SUCCESS)
 *   {
 *       //processing the success state
 *       ¡K..
 *   }
 *   else if (ret == SOC_WOULDBLOCK)
 *   {
 *      //processing the wouldblock state
 *      ¡K..
 *   }
 *
 * </code>
 *****************************************************************************/
extern kal_int8 soc_gethostbyname(kal_bool is_blocking,
                           module_type     mod_id,
                           kal_int32       request_id,
                           const kal_char  *domain_name,
                           kal_uint8       *addr,
                           kal_uint8       *addr_len,
                           kal_uint8       access_id,
                           kal_uint32      nwk_account_id);


/* New API for resolving one domain name mapping to multiple IP addresses */

/*****************************************************************************
 * <GROUP  DNS_API>
 *
 * FUNCTION
 *  soc_gethostbyname2
 * DESCRIPTION
 *  This function gets the IP of the given domain name, this new API is capable 
 *  of returing multiple IP addresses.
 *  Get host addresses (i.e., IP address) by its domain name. 
 *  This is an extended API for returning the answer mapping a domain name to multiple IP addresses.
 *
 *  If the bearer is not activated when this API is called, 
 *  the bearer activation would be triggered. However, 
 *  if the account id is not specified in soc_gethostbyname2, 
 *  an account query would be displayed to ask the user which account s/he wants to use. 
 *
 *  If a cached entry is found, this new extended API is capable of returning multiple IP addresses 
 *  from the addr field in the argument. The number of returned entries is set in the argument 
 *  out_entry_num if the input argument is not NULL.
 *  Application can set the maximum allowed number of return entries in the in_entry_num field 
 *  according to the allocated buffer size for addr.
 *  If is_blocking is set to zero, soc_gethostbyname will be returned immediately. 
 *  SOC will send a notification to application when it gets the response of previous DNS query.
 *  Currently, only non-blocking mode is supported, i.e., is_blocking shall be set to KAL_FALSE.
 *
 *  This API only supports the non-blokcing mode, i.e., 
 *  is_blocking shall be set to KAL_FALSE.
 *  Thus, soc_gethostbyname2 will be returned immediately instead of 
 *  blocking and waiting for the result. 
 *  If user doesn't get the returned value directly after it calls this API,
 *  the returned value "SOC_WOULDBLOCK" will be returned normally.
 *  SOC will send a notification to application when it gets the response 
 *  of previous DNS query later.
 * PARAMETERS
 *  is_blocking         : [IN]        whether block or non-block mode are used,
 *                                  currently only support non-block mode
 *  mod_id              : [IN]        module id
 *  request_id          : [IN]        embedded in response message
 *  domain_name         : [IN]        Domain_name
 *  addr                : [IN]        resolved address
 *  addr_len            : [IN/OUT]    address length     
 *  access_id           : [IN]        embedded in response message
 *  nwk_account_id      : [IN]        Nwk_account_id
 *  in_entry_num        : [IN]        max allowed number of return entries
 *  out_entry_num       : [OUT]       number of returned entries
 * RETURN VALUES
 *  SOC_SUCCESS :		 Get IP address successfully
 *  SOC_INVAL :			 invalid arguments: null domain_name, etc.
 *  SOC_ERROR :			 unspecified error
 *  SOC_WOULDBLOCK :	 wait response from network
 *  SOC_LIMIT_RESOURCE : socket resources not available
 *****************************************************************************/
extern kal_int8 soc_gethostbyname2(kal_bool is_blocking,
                           module_type     mod_id,
                           kal_int32       request_id,
                           const kal_char  *domain_name,
                           kal_uint8       *addr,
                           kal_uint8       *addr_len,
                           kal_uint8       access_id,
                           kal_uint32      nwk_account_id,
                           kal_uint8       in_entry_num,
                           kal_uint8       *out_entry_num);


/* currently, this function only support non-blocking mode */

/*****************************************************************************
 * <GROUP  DNS_API>
 *
 * FUNCTION
 *  soc_gethostbyaddr
 * DESCRIPTION
 *  This function gets the domain name of the given IP. If the buffer to hold the query result 
 *  is too small, the result is truncated and wanted length is returned 
 *  through the variable "domain_name_len". In addition, an error code "SOC_NAMETOOLONG" 
 *  would be returned. 
 *
 *  If the bearer is not activated when this API is called, the bearer activation would be triggered. 
 *  However, if the account id is not specified in soc_getsockaddr, an account query would be displayed 
 *  to ask the user which account s/he wants to use. 
 *  If a cached entry is found, this API is capable of returning the domain name related to the IP address.
 *  Otherwise, the returned value SOC_WOULDBLOCK is returned. When user receives
 *  this returned value, this means the result will be reported later by primitive.
 *  We only supports the non-blocking mode for this API.
 * PARAMETERS
 *  is_blocking         : [IN]           indicate whether block or non-block mode are used, currently only non-block mode support 
 *  mod_id              : [IN]           module id 
 *  request_id          : [IN]           embedded in response message 
 *  domain_name         : [IN]           resolved domain name      
 *  domain_name_len     : [IN/OUT]       Domain name length for the buffer to hold the domain name
 *  addr                : [IN]           IP address 
 *  addr_len            : [IN]           IP address length 
 *  access_id           : [IN]           embedded in response message  
 *  nwk_account_id      : [IN]           Nwk_account_id 
 * RETURN VALUES
 *  SOC_SUCCESS :		 Get IP address successfully
 *  SOC_INVAL :          invalid arguments: null domain_name, etc.
 *  SOC_ERROR :			 unspecified error
 *  SOC_WOULDBLOCK :	 wait response from network
 *  SOC_LIMIT_RESOURCE : socket resources not available
 *  SOC_NAMETOOLONG :	 domain name is to long to put in the parameter domain_name
 *****************************************************************************/
extern kal_int8 soc_gethostbyaddr(kal_bool         is_blocking,
                           module_type      mod_id,
                           kal_int32        request_id,
                           kal_char         *domain_name,
                           kal_uint32       *domain_name_len,
                           const kal_uint8  *addr,
                           kal_uint8	    addr_len,
                           kal_uint8        access_id,
                           kal_uint32       nwk_account_id);

/*****************************************************************************
 * <GROUP  DNS_API>
 *
 * FUNCTION
 *  soc_gethostbysrv
 * DESCRIPTION
 *  This function gets the SRV RR of given domain name.
 *  Perform DNS SRV RR query.
 *
 *  If the bearer is not activated when this API is called, the bearer activation would be triggered. 
 *  However, if the account id is not specified in soc_gethostbysrv, 
 *  an account query would be displayed to ask the user which account s/he wants to use. 
 *  
 *  This API is in non-blocking mode.
 *	Normally, the API "soc_gethostbysrv" doesn't return immediately. 
 *  It always returns the "SOC_WOULDBLOCK" instead.
 *  please pay attention to this and should handle the "SOC_WOULDBLOCK" case.
 *  If the return value is SOC_WOULDBLOCK, SOC will notify the result in 
 *  APP_SOC_GET_HOST_BY_SRV_IND. entry[0] is preferred than entry[1] and so on.
 *  If the result is obtained in cache when user calls this API, 
 *  the result is returned directly in the "OUT" parameter "entry".
 *	if input entries are not enough, SOC will not copy all records 
 *  into input entry pointer.
 * PARAMETERS
 *  mod_id              : [IN]            Module id
 *  request_id          : [IN]            Embedded in response message
 *  domain_name         : [IN]            Domain name
 *  access_id           : [IN]            Embedded in response message
 *  nwk_account_id      : [IN]            Network account id
 *  entry               : [IN]        Used to return the SRV RR
 *  in_entry_num        : [IN]            number of expected responded entries
 *  out_entry_num       : [OUT]        number of filled SRV RR
 * RETURN VALUES
 *  SOC_SUCCESS :			 Get IP address successfully
 *  SOC_INVAL :			     invalid arguments: null domain_name, etc.
 *  SOC_ERROR :			     unspecified error
 *  SOC_WOULDBLOCK :		 wait response from network
 *  SOC_LIMIT_RESOURCE :	 socket resources not available
 *****************************************************************************/
extern kal_int8 soc_gethostbysrv(module_type         mod_id,
                          kal_int32           request_id,
                          const kal_char      *domain_name,
                          kal_uint8           access_id,
                          kal_uint32          nwk_account_id,
                          soc_dns_srv_struct  *entry,
                          kal_uint8           in_entry_num,
                          kal_uint8           *out_entry_num);

/*****************************************************************************
 * <GROUP  DNS_API>
 *
 * FUNCTION
 *  soc_gethostbynaptr
 * DESCRIPTION
 *  This function gets the NAPTR RR of given domain name.
 *  Perform DNS NAPTR RR query.
 *  If the bearer is not activated when this API is called, the bearer activation would be triggered. \
 *  However, if the account id is not specified in soc_gethostbynaptr. 
 *  an account query would be displayed to ask the user which account s/he wants to use. 
 *  If the return value is SOC_WOULDBLOCK, SOC will notify the result in APP_SOC_GET_DNS_SRV_IND.
 *  This API is also non-blocking.
 *
 *  This API is in non-blocking mode.
 *	Normally, the API "soc_gethostbynaptr" doesn't return immediately. 
 *  It always returns the "SOC_WOULDBLOCK" instead.
 *  please pay attention to this and should handle the "SOC_WOULDBLOCK" case.
 *  If the return value is SOC_WOULDBLOCK, SOC will notify the result in 
 *  APP_SOC_GET_HOST_BY_NAPTR_IND. entry[0] is preferred than entry[1] and so on.
 *  If the result is obtained in cache when user calls this API, 
 *  the result is returned directly in the "OUT" parameter "entry".
 *	if input entries are not enough, SOC will not copy all records 
 *  into input entry pointer.
 * PARAMETERS
 *  mod_id              : [IN]            Module id
 *  request_id          : [IN]            Embedded in response message
 *  domain_name         : [IN]            Domain name
 *  access_id           : [IN]            Embedded in response message
 *  nwk_account_id      : [IN]            Network account id
 *  entry               : [IN]        Used to return the NAPTR RR
 *  in_entry_num        : [IN]            Entry array number
 *  out_entry_num       : [OUT]        Used to return the NAPTR RR number
 * RETURN VALUES
 *  SOC_SUCCESS :			Get IP address successfully
 *  SOC_INVAL :			    invalid arguments: null domain_name, etc.
 *  SOC_ERROR :			    unspecified error
 *  SOC_WOULDBLOCK :		wait response from network
 *  SOC_LIMIT_RESOURCE :	socket resources not availabl
 *****************************************************************************/
extern kal_int8 soc_gethostbynaptr(module_type           mod_id,
                            kal_int32             request_id,
                            const kal_char        *domain_name,
                            kal_uint8             access_id,
                            kal_uint32            nwk_account_id,
                            soc_dns_naptr_struct  *entry,
                            kal_uint8             in_entry_num,
                            kal_uint8             *out_entry_num);

/*****************************************************************************
 * <GROUP  DNS_API>
 *
 * FUNCTION
 *  soc_abort_dns_query
 * DESCRIPTION
 *  This function is used to aborts DNS query. User can abort the DNS query
 *  by different choices, such as module id, request id, account id, etc.
 * PARAMETERS
 *  by_mod_id               : [IN]        Match DNS query by module id
 *  mod_id                  : [IN]        Module id
 *  by_request_id           : [IN]        Match DNS query by request id
 *  request_id              : [IN]        Request id
 *  by_access_id            : [IN]        Match DNS query by access id
 *  access_id               : [IN]        Access id
 *  by_nwk_account_id       : [IN]        Match DNS query by network account id
 *  nwk_account_id          : [IN]        Network account id
 * RETURN VALUES
 *  SOC_SUCCESS :          corresponding DNS query found and aborted
 *  SOC_ERROR :            cannot found corresponding DNS query
 * EXAMPLE
 *  Abort DNS query by module id:
 *  <code>
 *  soc_abort_dns_query(
 *           KAL_TRUE,   [by_mod_id]
 *           MOD_SIP,    [module id]
 *           KAL_FALSE,  [by_request_id]
 *           0,          [request_id]
 *           KAL_TRUE,   [by_access_id]
 *           id,         [access_id]
 *           KAL_FALSE,  [by_nwk_account_id]
 *           0);         [nwk_account_id]
 *  </code>
 *****************************************************************************/
extern kal_int8 soc_abort_dns_query(kal_bool     by_mod_id,
                             module_type  mod_id,
                             kal_bool     by_request_id,
                             kal_uint32   request_id,
                             kal_bool     by_access_id,
                             kal_uint8    access_id,
                             kal_bool     by_nwk_account_id,
                             kal_uint32   nwk_account_id);
                            
/*****************************************************************************
 * <GROUP  Others>
 *
 * FUNCTION
 *  soc_getlocalip
 * DESCRIPTION
 *  This function returns the local IP address.
 *  Obsoleted, this function does not associate the address to data account.
 *  Use soc_get_account_localip() instead.
 * PARAMETERS
 *  local_ip        : [OUT]        copy the IP address, used as return
 * RETURN VALUES
 *  SOC_SUCCESS : success
 *  SOC_INVAL : bearer is not activated, no IP address info
 *****************************************************************************/                        
extern kal_int8 soc_getlocalip(kal_uint8 *local_ip);

/*****************************************************************************
 * <GROUP  Others>
 *
 * FUNCTION
 *  soc_get_account_localip
 * DESCRIPTION
 *  This function is used to get the local IP held by this socket id.
 * PARAMETERS
 *  s               : [IN]            Socket id
 *  local_ip        : [OUT]        copy the IP address, used as return
 * RETURN VALUES
 *  SOC_SUCCESS :		    Get IP address successfully
 *  SOC_INVAL :			    invalid argument: null local_ip.
 *  SOC_BEARER_FAIL :	    bearer is not activated
 *  SOC_INVALID_SOCKET :    invalid socket
 *  SOC_INVALID_ACCOUNT :   invalid account
 * EXAMPLE
 * <code>
 * static kal_uint8 ip[4];
 * kal_int8 result;
 * result = soc_get_account_localip((kal_int8)fd, ip);
 * if (result == SOC_SUCCESS)
 * { 
 *     //get the local IP address successfully 
 * }
 * </code>
 *****************************************************************************/
extern kal_int8 soc_get_account_localip(kal_int8 s, kal_uint8 *local_ip);

/*****************************************************************************
 * <GROUP  Others>
 *
 * FUNCTION
 *  soc_get_localip_by_account
 * DESCRIPTION
 *  This function is used to get the local IP held by the account id
 * PARAMETERS
 *  account_id      : [IN]            network account id
 *  local_ip        : [OUT]           copy the IP address, used as return
 * RETURNS
 *  SOC_SUCCESS: success
 *  negative: bearer is not activated, no IP address info
 * EXAMPLE
 * <code>
 * kal_int8 result;
 * kal_uint8 ip[4];
 * result = soc_get_localip_by_account(account_id, ip);
 * if (result == SOC_SUCCESS)
 * {
 *	    //get address successfully
 * }
 * </code>
 *****************************************************************************/
extern kal_int8 soc_get_localip_by_account(kal_uint32 account_id,
                                           kal_uint8 *local_ip);


/*****************************************************************************
 * <GROUP  Others>
 *
 * FUNCTION
 *  soc_getsockaddr
 * DESCRIPTION
 *  This function returns the remote or local address assoicated
 *  with given socket.
 * PARAMETERS
 *  s               : [IN]            socket id
 *  is_local        : [IN]            true: local false: remote
 *  addr            : [OUT]        copy the address, used as return 
 * RETURN VALUES
 *  SOC_SUCCESS :            success
 *  SOC_INVAL :			     invalid argument
 *  SOC_INVALID_SOCKET :   	 not a valid socket
 *  SOC_PIPE :	    		 socket is broken
 *  SOC_NOTCONN :			 not a connected socket
 *  SOC_ERROR :	    		 cannot found corresponding DNS query (or socket not bound for SOC_SOCK_SMS)
 * EXAMPLE
 * <code>
 * kal_int8 result;
 * sockaddr_struct addr;
 * result = soc_getsockaddr((kal_int8) handle, local ? KAL_TRUE : KAL_FALSE, &addr);
 * if (result == SOC_SUCCESS)
 * {
 *	    //get the local or remote address successfully
 * }
 * </code>
 *****************************************************************************/
extern kal_int8 soc_getsockaddr(kal_int8         s, 
                         kal_bool         is_local,
                         sockaddr_struct  *addr);

/*****************************************************************************
 * <GROUP  Others>
 *
 * FUNCTION
 *  soc_get_last_error
 * DESCRIPTION
 *  This function is used to get the last network error.
 *  A successful function call, or a call to soc_get_last_error,
 *  does not reset the error cause.
 *  
 *  Currently, the detail_cause is valid when the error is SOC_BEARER_FAIL. 
 *  I list some special causes for SOC_BEARER_FAIL in the following:
 * 	INSUFF_RESOURCE: GPRS activation failure due to the existence of Circuit Switch service.
 *	CM_L4C_CC_CALL_ABORT: User aborts CSD call during CSD call establishment.
 * PARAMETERS
 *  s                   : [IN]            socket id
 *  error               : [OUT]        major error cause. socket error cause.
 *  detail_cause        : [OUT]        detail_cause, minor error cause. 
 * RETURN VALUES
 *  SOC_SUCCESS :		 Get IP address successfully
 *  SOC_INVALID_SOCKET : Invalid socket id
 * SEE ALSO
 *   soc_set_last_error
 * EXAMPLE
 * <code>
 * kal_int8 err;
 * kal_int32 detail;
 *
 * s = soc_create(SOC_PF_INET, SOC_SOCK_STREAM, 0, MOD_TEST, nwk_acct_id);
 *
 * if (s < 0)
 * {
 *     soc_get_last_error(s, &err, &detail);
 * }
 * </code>
 *****************************************************************************/
extern kal_int8 soc_get_last_error(kal_int8   s,
                            kal_int8   *error, 
                            kal_int32  *detail_cause);

/*****************************************************************************
 * <GROUP  Others>
 *
 * FUNCTION
 *  soc_set_last_error
 * DESCRIPTION
 *  This function is used to set the last network error.
 * PARAMETERS
 *  s                   : [IN]        socket id
 *  error               : [IN]        major error cause. socket error.
 *  detail_cause        : [IN]        minor error cause. detail error cause.
 * RETURN VALUES
 *  SOC_SUCCESS : success
 *  SOC_INVALID_SOCKET : invalid socket id
 * SEE ALSO
 *   soc_get_last_error
 * EXAMPLE
 * <code>
 * kal_int32 error, detail_cause;
 *
 * s = soc_create(SOC_PF_INET, SOC_SOCK_STREAM, 0, MOD_TEST, nwk_acct_id);
 *
 * if (s >= 0)
 * {
 *     ret = soc_set_last_error(s, (kal_int8)error, detail_cause);
 * }
 * </code>
 *****************************************************************************/
extern kal_int8 soc_set_last_error(kal_int8   s,
                            kal_int8   error, 
                            kal_int32  detail_cause);

/*****************************************************************************
 * <GROUP  Others>
 *
 * FUNCTION
 *  soc_ip_check
 * DESCRIPTION
 *  This function is used to check whether an input string asci_addr is in the form 
 *  of valid dotted-decimal format, if so, validate the IP address with the valid IP range.
 * PARAMETERS
 *  asci_addr       : [IN]            FQDN or IP address string        
 *  ip_addr         : [OUT]        To return back the address to calling function.
 *  ip_validity     : [OUT]        Validity of the IP address
 * RETURN VALUES
 *  TRUE :  an IP address
 *  FALSE : not an IP address
 * EXAMPLE
 * <code>
 * kal_bool ret;
 * kal_uint8 ip_addr[4];
 * kal_bool ip_validity;
 * ret = soc_ip_check("1.2.3.4", ip_addr, &ip_validity);
 * </code>
 *****************************************************************************/
extern kal_bool soc_ip_check(kal_char   *asci_addr, 
                      kal_uint8  *ip_addr, 
                      kal_bool   *ip_validity);

/*****************************************************************************
 * <GROUP  Others>
 *
 * FUNCTION
 *  soc_read_notify
 * DESCRIPTION
 *  This function is used to enable/disable READ notification.
 *  Once the READ notification is disabled, when socket receives
 *  the data, it will not send the notification APP_SOC_NOTIFY_IND(SOC_READ)
 *  to notify the user that the data can be read.
 * PARAMETERS
 *  s                   : [IN]        socket id
 *  set                 : [IN]        TRUE: enable FALSE: disable
 * RETURN VALUES
 *  void
 * EXAMPLE
 * disable the read notification:
 * <code>
 * soc_read_notify(sock_id, KAL_TRUE);
 * </code>
 *****************************************************************************/
extern void soc_read_notify(kal_int8 s, kal_bool set);

/*****************************************************************************
 * <GROUP  Others>
 *
 * FUNCTION
 *  soc_ready_for_read
 * DESCRIPTION
 *  This function is used to probe the socket receive queue.
 *  This gives a interface for application to tell whether there is data 
 *  in the receive queue but it always returns KAL_FALSE for SMS sockets.  
 * PARAMETERS
 *  s                   : [IN]        socket id
 * RETURN VALUES
 *  KAL_TRUE : there is data for read
 *  KAL_FALSE : there is no dadta for read
 * EXAMPLE
 * <code>
 * kal_int32 error, detail_cause;
 *
 * s = soc_create(SOC_PF_INET, SOC_SOCK_STREAM, 0, MOD_TEST, nwk_acct_id);
 *
 * if (s >= 0)
 * {
 *     ...
 *     if (soc_ready_for_read(s) == KAL_TRUE)
 *	   {
 *         //data is ready for read
 *     }
 * }
 * </code>
 *****************************************************************************/
extern kal_bool soc_ready_for_read(kal_int8 s);

/*****************************************************************************
 * <GROUP  Others>
 *
 * FUNCTION
 *  soc_set_csd_auto_disconnect_timer
 * DESCRIPTION
 *  This function is used to set the value of CSD idle timeout.
 *  The CSD idle timeout value is the whole system value.
 *  Thus, after you have changed the value, be sure to set it back to
 *  the default value 120. Otherwise, you may influence other applications.
 * PARAMETERS
 *  sec                   : [IN]        csd idle time in seconds
 * RETURN VALUES
 *  KAL_TRUE : set the csd auto disconnection timeout successfully
 *  KAL_FALSE :  fail to set the csd auto disconnection timeout
 * SEE ALSO
 *   soc_get_csd_auto_disconnect_timer
 * EXAMPLE
 * <code>
 * if (soc_set_csd_auto_disconnect_timer(500) == KAL_TRUE)
 * { 
 *     //set the timeout successfully 
 * }
 * </code>
 *****************************************************************************/
extern kal_bool soc_set_csd_auto_disconnect_timer(kal_uint16 sec);

/*****************************************************************************
 * <GROUP  Others>
 *
 * FUNCTION
 *  soc_get_csd_auto_disconnect_timer
 * DESCRIPTION
 *  This function is used to get the value of CSD idle timeout.
 *  The default value is 120 seconds.
 * PARAMETERS
 *  sec                   : [OUT]        csd idle time in seconds
 * RETURN VALUES
 *  KAL_TRUE : get the csd auto disconnection timeout successfully
 *  KAL_FALSE :  csd auto disconnect mechanism is not supported
 * SEE ALSO
 *   soc_set_csd_auto_disconnect_timer
 * EXAMPLE
 * <code>
 * kal_uint16 sec;
 * if (soc_get_csd_auto_disconnect_timer(&sec) == KAL_TRUE)
 * { 
 *     //get the timeout successfully 
 * }
 * </code>
 *****************************************************************************/
extern kal_bool soc_get_csd_auto_disconnect_timer(kal_uint16 *sec);

/*****************************************************************************
 * <GROUP  Others>
 *
 * FUNCTION
 *  soc_set_gprs_auto_disconnect_timer
 * DESCRIPTION
 *  This function is used to set the value of PS(packet service) idle timeout.
 *  The PS idle timeout value is the whole system value.
 *  Thus, after you have changed the value, be sure to set it back to
 *  the default value 120. Otherwise, you may influence other applications.  
 * PARAMETERS
 *  sec                   : [IN]        ps idle time in seconds
 *  account_id            : [IN]        network account id
 * RETURN VALUES
 *  KAL_TRUE : set the ps auto disconnection timeout successfully
 *  KAL_FALSE :  fail to set the gprs auto disconnection timeout
 * SEE ALSO
 *   soc_get_gprs_auto_disconnect_timer
 * EXAMPLE
 * <code>
 * if (soc_set_gprs_auto_disconnect_timer(500, account_id) == KAL_TRUE)
 * {    
 *     //set the timeout successfully 
 * }
 * </code>
 *****************************************************************************/
extern kal_bool soc_set_gprs_auto_disconnect_timer(kal_uint16 sec, kal_uint32 account_id);

/*****************************************************************************
 * <GROUP  Others>
 *
 * FUNCTION
 *  soc_get_gprs_auto_disconnect_timer
 * DESCRIPTION
 *  This function is used to get the value of PS(packet service) idle timeout.
 * PARAMETERS
 *  sec                   : [OUT]        ps idle time in seconds
 *  account_id            : [IN]        network account id
 * RETURN VALUES
 *  KAL_TRUE : get the ps auto disconnection timeout successfully
 *  KAL_FALSE :  gprs auto disconnection mechanism is not supported
 * SEE ALSO
 *   soc_set_gprs_auto_disconnect_timer
 * EXAMPLE
 * <code>
 * kal_uint16 sec;
 * if (soc_get_gprs_auto_disconnect_timer(&sec, account_id) == KAL_TRUE)
 * { 
 *     //get the timeout successfully 
 * }
 * </code>
 *****************************************************************************/
extern kal_bool soc_get_gprs_auto_disconnect_timer(kal_uint16 *sec, kal_uint32 account_id);

/*****************************************************************************
 * <GROUP  Others>
 *
 * FUNCTION
 *  soc_cksum
 * DESCRIPTION
 *  This function returns the checksum result of the given buffer.
 *  The algorithm is based on example in RFC 1071
 *
 *  Notice that the checksum buffer must be 2-byte aligned, otherwise,
 *  the return result will be 0, which means no checksum for a transmitted 
 *  datagram.
 *
 *  Accordint to the specification, if the computed checksum is zero,
 *  it is transmitted  as all ones. For this case, soc_cksum() will return 
 *  do a check and return 0xffff.
 *  An all zero transmitted checksum value means that the transmitter generated 
 *  no checksum.
 * PARAMETERS
 *  buf     : [IN]        buffer storing data to compute check sum.
 *                      The starting address must be 2-byte aligned, otherwise,
 *                      this function returns 0.
 *  len     : [IN]        The length of the data in the buffer to be computed,
 *                      count in bytes
 * RETURN VALUES
 *  >0 :      checksum result.
 *  0 :       the buf is not 2-byte aligned, ap should handle this error case.
 * EXAMPLE
 * <code>
 * if (soc_cksum((kal_uint16*) recv_buffer, recv_buff_len) == 0)
 * {
 *     kal_wap_trace(MOD_APP, TRACE_INFO, "recv_buffer is not 2-byte aligned!!");
 * }
 * </code>
 *****************************************************************************/
extern kal_uint16 soc_cksum(kal_uint16 *buf, kal_int32 len);

/*****************************************************************************
 * <GROUP  Others>
 *
 * FUNCTION
 *  soc_set_module
 * DESCRIPTION
 *  This function sets the module id associate to the socket id.
 *  The notification from SOC to application will be sent to the new module.
 * 
 *  Note that this function should not be called inside a socket protection
 *  segment, which causes a dead-lock.
 * PARAMETERS
 *  s       : [IN]        socket id
 *  mod     : [IN]        new module id
 * RETURN VALUES
 *  >0 :                     the id of original module id associated to the socket
 *  SOC_INVALID_SOCKET :     given an invalid socket id.
 *  SOC_INVAL :              given an invalid module id.
 *  SOC_OPNOTSUPP :          operation not supported.
 *                           This API is only supported if __SSL_SUPPORT__ is set.
 * EXAMPLE
 *  change the reported module id to TLS:
 *  <code>
 *  soc_set_module(sock_id, MOD_TLS);
 *  </code>
 *****************************************************************************/
extern kal_int32 soc_set_module(kal_uint8 s, module_type mod);

/*****************************************************************************
 * <GROUP  Others>
 *
 * FUNCTION
 *  soc_resume_qos_context
 * DESCRIPTION
 *  For real-time applications which use secondary PDP context and pause for a
 *  while, the network gateway might release the RAB.
 *  This API is used for the purpose of resuming the RAB to the network.
 *
 * PARAMETERS
 *  qos_profile_id       : [IN]        qos profile id
 *
 * RETURN VALUES
 *  SOC_SUCCESS : success
 *  negative : fail
 *****************************************************************************/
extern kal_int8 soc_resume_qos_context(kal_uint8 qos_profile_id);

/*****************************************************************************
 * <GROUP  Others>
 *
 * FUNCTION
 *  soc_set_dns_srv_addr
 * DESCRIPTION
 *  If you set the global dns server address and profile dns server address at the same time,
 *  we will use the profile dns server address instead of global dns server address
 * PARAMETERS
 *  account_id       : [IN]        network account id
 *  srv_type         : [IN]        dns service type (soc_dns_srv_addr_enum)
 *  dns_addr         : [OUT]       dns server address
 * RETURN VALUES
 *  SOC_SUCCESS : success
 *  negative : fail
 *****************************************************************************/
extern kal_int8 soc_set_dns_srv_addr(kal_uint32 account_id,
                                     kal_uint8 srv_type,
                                     kal_uint8 *dns_addr);
                      
/*****************************************************************************
 * <GROUP  Others>
 *
 * FUNCTION
 *  soc_set_dns_timeout
 * DESCRIPTION
 *  Application can use this API to change DNS timeout value. DNS timeout is
 *  the value which the longest time we can wait for each sent out DNS query.
 *  If application has some IOT network problem, s/he may use this API to change
 *  the default DNS timeout value.
 *  currently, our timeout value is 2 seconds. After the query is sent out, if we didn't
 *  get the response within 2 seconds, we will sent another request to retry again.
 *  P.S. this value is global setting, once the value is changed, it applied to all DNS query behavior.
 *  That is to say, other application which needs to do DNS query will applied the same setting after 
 *  the value is changed.
 * PARAMETERS
 *  time_val       : [IN]        DNS timeout value
 * RETURN VALUES
 *  SOC_SUCCESS : success
 *  negative : fail
 *****************************************************************************/
extern kal_int8 soc_set_dns_timeout(kal_uint16 time_val);

/*****************************************************************************
 * <GROUP  Others>
 *
 * FUNCTION
 *  soc_get_dns_timeout
 * DESCRIPTION
 *  Application can use this API to get the current system DNS timeout value.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  DNS time out value
 *****************************************************************************/
extern kal_uint16 soc_get_dns_timeout(void);

/*****************************************************************************
 * <GROUP  Others>
 *
 * FUNCTION
 *  soc_set_dns_retry
 * DESCRIPTION
 *  Application can use this API to change DNS retry value. DNS retry value is
 *  the value which the longest number we can try before we get the DNS result.
 *
 *  currently, our default retry number is "3". If application want to change it,
 *  s/he can use this API.
 *  P.S. this value is global setting, once the value is changed, it applied to all DNS query behavior.
 *  That is to say, other application which needs to do DNS query will applied the same setting after 
 *  the value is changed.
 * PARAMETERS
 *  time_val       : [IN]        DNS timeout value
 * RETURN VALUES
 *  SOC_SUCCESS : success
 *  negative : fail
 *****************************************************************************/
extern kal_int8 soc_set_dns_retry(kal_uint16 retry_count);

/*****************************************************************************
 * <GROUP  Others>
 *
 * FUNCTION
 *  soc_get_dns_retry
 * DESCRIPTION
 *  Application can use this API to get current system DNS retry number.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  DNS retry number
 *  negative : fail
 *****************************************************************************/
extern kal_uint16 soc_get_dns_retry(void);

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*****************************************************************************
 * <GROUP  Others>
 *
 * FUNCTION
 *  soc_htonl
 * DESCRIPTION
 *  Convert long integer (32 bits) from host byte order to network byte order  
 * PARAMETERS
 *  a      : [IN]        
 * RETURNS
 *  converted result in unsigned integer
 * EXAMPLE
 * <code>
 * loopback = soc_htonl(0x7f000001);
 * </code>
 *****************************************************************************/
extern kal_uint32 soc_htonl(kal_uint32 a);

/*
 * <GROUP  Macro_Funcs>
 *  
 * convert long integer from the network byte order to the host byte order 
 */
#define soc_ntohl(a)    soc_htonl(a)

/*****************************************************************************
 * <GROUP  Others>
 *
 * FUNCTION
 *  soc_htonl
 * DESCRIPTION
 *  Convert short integer (16 bits) from host byte order to network byte order  
 * PARAMETERS
 *  a      : [IN]        
 * RETURNS
 *  converted result in unsigned integer
 * EXAMPLE
 * <code>
 * sockaddr sock_addr;
 * ((struct sockaddr_in *) sock_addr)->sin_port = soc_htons(port);
 * </code>
 *****************************************************************************/
extern kal_uint16 soc_htons(kal_uint16 a);

/*
 * <GROUP  Macro_Funcs>
 *  
 * convert short integer from the network byte order to the host byte order 
 */
#define soc_ntohs(a)    soc_htons(a)
#ifdef __cplusplus
}
#endif /* __cplusplus */

/*
 * <GROUP  Macro_Funcs>
 * 
 * convert long integer from the network byte order to the host byte order 
 */
#define	NTOHL(x)	(x) = soc_ntohl((kal_uint32)(x))

/*
 * <GROUP  Macro_Funcs>
 *  
 * convert short integer from the network byte order to the host byte order 
 */
#define	NTOHS(x)	(x) = soc_ntohs((kal_uint16)(x))

/*
 * <GROUP  Macro_Funcs>
 *
 * convert long integer from the host byte order to the network byte order 
 */
#define	HTONL(x)	(x) = soc_htonl((kal_uint32)(x))

/*
 * <GROUP  Macro_Funcs>
 *
 * convert short integer from the host byte order to the network byte order 
 */
#define	HTONS(x)	(x) = soc_htons((kal_uint16)(x))

/*
 * <GROUP  Macro_Funcs>
 *
 * check if the IP address is 0.0.0.0 
 */
#define IP_ALL_ZEROS(a)     (!(a[0] | a[1] | a[2] | a[3]))

/*
 * <GROUP  Macro_Funcs>
 *
 * check if the IP address is 255.255.255.255 
 */
#define IP_ALL_ONES(a)      (!((a[0] & a[1] & a[2] & a[3]) ^ 0xff))

/*
 * <GROUP  Macro_Funcs>
 * 
 * check if the IP address "a" is equal to the IP address "b" 
 */
#define IP_ALL_MATCH(a, b)  (!((a[0] ^ b[0]) | (a[1] ^ b[1]) | (a[2] ^ b[2]) | (a[3] ^ a[3])))

#endif /* !_SOC_API_H */


