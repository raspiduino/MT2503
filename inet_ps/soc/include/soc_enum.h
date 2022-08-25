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
 * soc_enum.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains enums for Socket.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _SOC_ENUM_H
#define _SOC_ENUM_H

#include "soc_feature.h"
#include "cbm_consts.h"

typedef enum
{
    SOC_APP_NUM_SPARED = 3,                                             /* Spared app number: 3 */
    SOC_IPSEC_APP_NUM_END = SOC_APP_NUM_SPARED + ABM_IPSEC_APP_NUM,     /* IPSEC app number: 3+1 */
    SOC_WAP_APP_NUM_END = SOC_IPSEC_APP_NUM_END + ABM_WAP_APP_NUM,      /* WAP app number: 4+2 */
    SOC_STREAM_APP_NUM_END = SOC_WAP_APP_NUM_END + ABM_STREAM_APP_NUM,  /* Stream app number: 6+1 */
    SOC_JAVA_APP_NUM_END = SOC_STREAM_APP_NUM_END+ ABM_JAVA_APP_NUM,    /* Java app number: 7+2 */
    SOC_EMAIL_APP_NUM_END = SOC_JAVA_APP_NUM_END + ABM_EMAIL_APP_NUM,   /* EMAIL app number: 9+4 */
    SOC_VOIP_APP_NUM_END = SOC_EMAIL_APP_NUM_END + ABM_VOIP_APP_NUM,    /* VOIP app number: 13+1 */
    SOC_MMS_APP_NUM_END = SOC_VOIP_APP_NUM_END + ABM_MMS_APP_NUM,       /* MMS app number: 14+1 */
    SOC_WIFI_APP_NUM_END = SOC_MMS_APP_NUM_END + ABM_WIFI_APP_NUM,      /* WIFI app number: 15+1 */
    SOC_SAT_APP_NUM_END = SOC_WIFI_APP_NUM_END + ABM_SAT_APP_NUM,       /* SAT app number: 16+1 */
    SOC_SUPL_APP_NUM_END = SOC_SAT_APP_NUM_END + ABM_SUPL_APP_NUM,      /* SUPL app number: 17+1 */
    SOC_SSL_APP_NUM_END = SOC_SUPL_APP_NUM_END + ABM_SSL_APP_NUM,       /* SSL app number: 18+1 */
    SOC_IOT_APP_NUM_END = SOC_SSL_APP_NUM_END + ABM_IOT_APP_NUM,        /* IOT app number: 19+6 */

    MAX_SOC_APP = SOC_IOT_APP_NUM_END                                   /* Max app number: 25 */
} soc_max_app_num_enum;

typedef enum
{
    SOC_CLOSE_TIMER = 0,    /* for postponing socket close */
    SOC_SELECT_TIMER,       /* for select */
    SOC_DNS_TIMER,          /* for waiting dns response */
    SOC_CONC_TIMER,         /* for concatenated message */
    SOC_AUTO_DISC_TIMER,    /* for csd auto timeout or gprs linger timeout */
    SOC_AUTO_DEACT_TIMER,   /* for auto deactivate bearer */
    SOC_BEARER_TIMER,       /* for all bearer initialization timers */
    SOC_DATA_TIMER,         /* for data */
    SOC_BRIDGE_TIMER,       /* for continue send other type recv data */
    SOC_NUM_OF_TIMER
} soc_timer_enum;

typedef enum
{
    SOC_DATA_DIR_SEND = 1,
    SOC_DATA_DIR_RECV = 2
} soc_data_dir_enum;

typedef enum
{
    SOC_EVT_NOWAIT     = 0,
    SOC_EVT_READ       = 0x0001,
    SOC_EVT_WRITE      = 0x0002,
    SOC_EVT_CONNECT    = 0x0004,
    SOC_EVT_LISTEN     = 0x0008,
    SOC_EVT_SELECT     = 0x0010,
    SOC_EVT_ATTACH     = 0x0020,
    SOC_EVT_DETACH     = 0x0040,
    SOC_EVT_BIND       = 0x0080,
    SOC_EVT_ACCEPT     = 0x0100,
    SOC_EVT_SHUTDOWN   = 0x0200,
    SOC_EVT_SEND       = 0x0400,
    SOC_EVT_RECV       = 0x0800,
    SOC_EVT_BEARER     = 0x1000,
    SOC_EVT_OPTION     = 0x2000,
    SOC_EVT_LINGER     = 0x4000,
    SOC_EVT_DISCONNECT = 0x8000
} soc_wait_event_enum;

typedef enum
{
    SOC_ACC_CLOSED = 0,
    SOC_ACC_CLOSING,
    SOC_ACC_OPENING,
    SOC_ACC_OPENED
} soc_account_state_enum;

typedef enum
{
    SOC_IP_NO = 0,
    SOC_IP_OBTAINING,
    SOC_IP_AVAILABLE
} soc_ip_state_enum;

typedef enum
{
    SOC_S_NOUSE         = 0,
    SOC_S_INUSE         = 0x0001,
    SOC_S_ATTACHING     = 0x0002,   /* is process of attaching socket to protocol block */
    SOC_S_ATTACHED      = 0x0004,   /* socket attached to a protocol block */
    SOC_S_LISTENING     = 0x0008,   /* is process of listening */
    SOC_S_LISTENED      = 0x0010,   /* socket is listened */
    SOC_S_BINDING       = 0x0020,   /* is process of binding socket to a local address */
    SOC_S_BINDED        = 0x0040,   /* socket is binded */
    SOC_S_SHUTDOWNING   = 0x0080,   /* is process of shutdowning */
    SOC_S_SHUTDOWNED    = 0x0100,   /* socket is shutdowned, can't send more data to peer */
    SOC_S_CONNECTING    = 0x0200,   /* in process of connecting to peer */
    SOC_S_CONNECTED     = 0x0400,   /* socket connected to a peer */
    SOC_S_CONNECT_FAIL  = 0x0800,
    SOC_S_CANTRECVMORE  = 0x1000,   /* can't receive more data from peer */
    SOC_S_CLOSING       = 0x2000,
    // SOC_S_WAITACCEPT = 0x2000,   /* unaccepted, complete connection */
    SOC_S_CLOSED        = 0x4000,
    SOC_S_WAIT_BEARER   = 0x8000,   /* waiting for bearer confirm message */
    SOC_S_CLOSED_WAIT_RECV = 0x00010000,    /* recv tcpip_close_ind or abm_deactivate_ind 
                                               but recv queue not empty */
    SOC_S_WAIT_CNF      = 0x00020000,
    SOC_S_SENDING       = 0x00040000,
    SOC_S_RECVING       = 0x00080000,
    SOC_S_DISCONNECTING = 0x00100000,
    SOC_S_FINED         = 0x00200000,       /* received TCP FIN from peer */
    SOC_S_GROW_FAILED   = 0x00400000,        /* ever grow failed, expect RESUME notify */
    SOC_S_INIT_RECV_QUEUE = 0x00800000,      /* waiting queue initialization */
    SOC_S_WAIT_NWK_READY  = 0x01000000,      /* waiting network ready */

    SOC_S_SMSAL_ONE_REGISTERED  = 0x02000000,       /* SIM1 SMS has registered */
    SOC_S_SMSAL_TWO_REGISTERED  = 0x04000000,        /* SIM2 SMS has registered */
    SOC_S_SMSAL_THERE_REGISTERED  = 0x08000000,        /* SIM3 SMS has registered */
    SOC_S_SMSAL_FOUR_REGISTERED  = 0x10000000,        /* SIM4 SMS has registered */
    SOC_S_SMSAL_SIM_REGISTER_FAILED = 0x20000000   /* SIM SMS has registered fail */
} soc_state_enum;

typedef enum
{
    SOC_S_NWK_IS_NON_CSD_INIT =  0x00000001,    /* network is not initialized yet */
    SOC_S_NWK_IS_NON_PS_INIT =  0x00000002,    /* network is not initialized yet */
    SOC_S_NWK_IS_NON_WIFI_INIT =  0x00000004,    /* network is not initialized yet */
    SOC_S_NWK_IS_CSD_INIT =      0x00000008,    /* network is initialized */
    SOC_S_NWK_IS_PS_INIT =      0x00000010,    /* network is initialized */
    SOC_S_NWK_IS_WIFI_INIT =      0x00000020,    /* network is initialized */
    SOC_S_NWK_IS_CONGESTED = 0x00000040 /* network is congested */
} soc_nwk_status_enum;

typedef enum
{
    SOC_LOCAL_ADDR = 0,    /* local address, soc_is_addr_valid */
    SOC_REMOTE_ADDR = 1    /* remote address, for soc_is_addr_valid */
} soc_addr_enum;

typedef enum
{
    SOC_SMS_DEREGISTER = 0,   /* deregister SMS for soc_register_port_to_sms */
    SOC_SMS_REGISTER = 1      /* deregister SMS for soc_register_port_to_sms */
} soc_sms_register_port_enum;


#ifdef SOC_UT
typedef enum
{
    SOC_UT_APP_CREATE = 0,      /* 0   create tcp socket */
    SOC_UT_APP_CONNECT,         /* 1   connect           */
    SOC_UT_APP_LISTEN,          /* 2   listen            */
    SOC_UT_APP_BIND,            /* 3   bind              */
    SOC_UT_APP_RECV,            /* 4   recv              */
    SOC_UT_APP_RECVFROM,        /* 5   recvfrom          */
    SOC_UT_APP_SEND,            /* 6   send              */
    SOC_UT_APP_SENDTO,          /* 7   sendto            */
    SOC_UT_APP_CLOSE,           /* 8   close             */
    SOC_UT_APP_ACCEPT,          /* 9   accept            */
    SOC_UT_APP_SELECT,          /* 10  select            */
    SOC_UT_APP_SETOPT,          /* 11  set option        */
    SOC_UT_APP_GETOPT,          /* 12  get option        */
    SOC_UT_APP_SHUTDOWN,        /* 13  shutdown          */
    SOC_UT_MAPP_1,              /* 14  create/close      */
    SOC_UT_MAPP_2,              /* 15  TCP send/recv     */
    SOC_UT_MAPP_3,              /* 16  UDP send/recv     */
    SOC_UT_MAPP_4,              /* 17  TCP/UDP send/recv */
    SOC_UT_APP_GETHOSTBYNAME,   /* 18  DNS               */
    SOC_UT_MISC_SETTING,        /* 19  Misc setting      */
    SOC_UT_FUNC_NUM
} soc_ut_app_func_enum;

typedef enum
{
    SOC_UT_TCPIP_RECV_IND = 0,  /* 0 downlink data */
    SOC_UT_TCPIP_RECV_SEG_IND,  /* 1 downlink data with several IP fragments */
    SOC_UT_TCPIP_AUTO_CNF,      /* 2 */
    SOC_UT_TCPIP_PROV_IND,      /* 3 provisioning data */
    SOC_UT_TCPIP_DNS_IND,       /* 4 DNS data */
    SOC_UT_TCPIP_EMAIL_IND,     /* 5 e-mail data */
    SOC_UT_TCPIP_FUNC_NUM
} soc_tcpip_ut_app_func_enum;

typedef enum
{
    SOC_UT_EMAIL_GREETING,
    SOC_UT_EMAIL_USER_RSP,
    SOC_UT_EMAIL_PASS_RSP,
    SOC_UT_EMAIL_STAT_RSP,
    SOC_UT_EMAIL_LIST_RSP,
    SOC_UT_EMAIL_LIST_DATA,
    SOC_UT_EMAIL_RETR_RSP,
    SOC_UT_EMAIL_RETR_DATA,
    SOC_UT_EMAIL_DELE_RSP,
    SOC_UT_EMAIL_UIDL_RSP,
    SOC_UT_EMAIL_UIDL_DATA,
    SOC_UT_EMAIL_QUIT_RSP,
    SOC_UT_EMAIL_POP3_NUM_RSP
} soc_email_ut_pop3_cmd_enum;

typedef enum
{

    SOC_UT_IMAP_GREETING = SOC_UT_EMAIL_POP3_NUM_RSP,   /* GREETING */
    SOC_UT_IMAP_CAPA,                                   /* CAPABILITY  */
    SOC_UT_IMAP_LOGIN,                                  /* LOGIN */
    SOC_UT_IMAP_LIST,                                   /* LIST */
    SOC_UT_IMAP_LSUB,                                   /* LSUB */
    SOC_UT_IMAP_CREATE,
    SOC_UT_IMAP_SELECT,
    SOC_UT_IMAP_EXAMINE,
    SOC_UT_IMAP_SUBSCRIBE,
    SOC_UT_IMAP_STATUS,
    SOC_UT_IMAP_APPEND,
    SOC_UT_IMAP_CLOSE,
    SOC_UT_IMAP_FETCH,
    SOC_UT_IMAP_NOOP,
    SOC_UT_IMAP_LOGOUT,
    SOC_UT_IMAP_DEFAULT,
    SOC_UT_IMAP_NUM_RSP
} soc_email_ut_imap_cmd_enum;

typedef enum
{
    SOC_UT_IMAP_TAG              = 0x00000001,
    SOC_UT_IMAP_OK               = 0x00000002,
    SOC_UT_IMAP_BYE              = 0x00000004,
    SOC_UT_IMAP_NO               = 0x00000008,
    SOC_UT_IMAP_BAD              = 0x00000010,
    SOC_UT_IMAP_WRONG            = 0x00000020,
    SOC_UT_IMAP_IMAP4            = 0x00000040,     /* NOT IMAP4rev1 */
    SOC_UT_IMAP_IMAP4REV1        = 0x00000080,     /* IMAP4rev1 */
    SOC_UT_IMAP_LOGINDISABLED    = 0x00000100,
    SOC_UT_IMAP_PREAUTH          = 0x00000200,
    SOC_UT_IMAP_LIST_NOSELECT    = 0x00000400,     /* \Noselect */
    SOC_UT_IMAP_LIST_NOINFERIORS = 0x00000800,     /* \Noinferiors */
    SOC_UT_IMAP_LIST_MARKED      = 0x00001000,     /* \Marked */
    SOC_UT_IMAP_LIST_UNMARKED    = 0x00002000,     /* \Unmarked */
    SOC_UT_IMAP_INVALID_DATA     = 0x00004000,
    SOC_UT_IMAP_NO_CRLF          = 0x00008000,
    SOC_UT_IMAP_AUTOLOGOUT       = 0x00010000,
    SOC_UT_IMAP_UNSOLICITED      = 0x00020000,
    SOC_UT_IMAP_PLUS             = 0x00040000,

} soc_email_ut_flag_enum;

#endif /* SOC_UT */

#endif /* !_SOC_ENUM_H */

