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
 *   soc_consts.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains constants of socket APIs.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/
#ifndef _SOC_CONSTS_H
#define _SOC_CONSTS_H

/* please enable this compile option and remake soc, abm if you wants to do the 
 * network unit testing 
 */
//#define __NWK_APP_UT__

/*=============================
 * Constants
 *=============================*/

/* DOM-NOT_FOR_SDK-BEGIN */
/* Define number of socket used by applications */
/* WARNING: THESE CONSTANTS SHOULD BE CONFORM WITH FLOW CONTROL POOL BLOCKS */
/* The socket number defined for DHCP. 1, use spared */
#ifdef __WIFI_SUPPORT__
#define DHCP_SOCKETS   0 
#else /* !__WIFI_SUPPORT__ */
#define DHCP_SOCKETS   0
#endif /* !__WIFI_SUPPORT__ */

/* IPERF, iperf will block the screen, use the spared sockets */

/* The socket number defined for DNS */
#ifdef __TCPIP__
#define DNS_SOCKETS     2
#else /* !__TCPIP__ */
#define DNS_SOCKETS     0
#endif /* !__TCPIP__ */

/* The socket number defined for WAP. WAP: 1 SMS, 1 SMS UDP, 5 general sockets */
#ifdef WAP_SUPPORT
#define WAP_SOCKETS     5 
#else /* !WAP_SUPPORT */
#define WAP_SOCKETS     0
#endif /* !WAP_SUPPORT */

/* The socket number defined for Streaming */
#ifdef STREAM_SUPPORT
#define STREAM_SOCKETS     5
#else /* !STREAM_SUPPORT */
#define STREAM_SOCKETS     0
#endif /* !STREAM_SUPPORT */

#if defined(__IMPS__) && !defined(STREAM_SUPPORT)
#define IMPS_SOCKETS     5
#else
#define IMPS_SOCKETS     0
#endif

/* The socket number defined for POC, RTP, RTCP, SIP */
#if defined(__POC__) || defined(__J2ME__)
#define POC_J2ME_SOCKETS     3
#else /* !__POC__ && !__J2ME__ */
#define POC_J2ME_SOCKETS     0
#endif /* !__POC__ && !__J2ME__ */

/* The socket number defined for EMAIL. 1, use spared */
#ifdef __EMAIL__
#define EMAIL_SOCKETS     0 
#else /* !__EMAIL__ */
#define EMAIL_SOCKETS     0
#endif /* !__EMAIL__*/

/* The socket number defined for VOIP. 7 max 4 calls in MMI (3x3-way conf + 1 single), 2 UDP, 1 TCP */
#ifdef __VOIP__
#define VOIP_SOCKETS     6  /* 7 */
#else /* !__VOIP__ */
#define VOIP_SOCKETS     0
#endif /* !__VOIP__*/
/* DOM-NOT_FOR_SDK-END */

/* couting total socket numbers by compile options */
typedef enum
{
    SOCKET_SPARED = 4,                                  /*  Spared socket number: 4 */
    DHCP_SOCKET_END = SOCKET_SPARED + DHCP_SOCKETS,   /*  DHCP socket number: 0 */
    DNS_SOCKET_END = DHCP_SOCKET_END + DNS_SOCKETS,     /*  DNS socket number: 2 */
    WAP_SOCKET_END = DNS_SOCKET_END + WAP_SOCKETS,      /*  WAP socket number: 5 */
    STREAM_SOCKET_END = WAP_SOCKET_END + STREAM_SOCKETS,/*  Streaming socket number: 5 */
    POC_J2ME_SOCKET_END = STREAM_SOCKET_END + POC_J2ME_SOCKETS,   /*  POC, JAVA socket number: 3 */
    EMAIL_SOCKET_END = POC_J2ME_SOCKET_END + EMAIL_SOCKETS,  /*  EMAIL socket number: 0 */
    VOIP_SOCKET_END = EMAIL_SOCKET_END + VOIP_SOCKETS,  /*  VOIP socket number: 6 */
    IMPS_SOCKET_END = VOIP_SOCKET_END + IMPS_SOCKETS, /* when stream=0, imps=5 */
    
#ifndef __SOC_25_SOCKETS_SUPPPORT__ 
    MAX_IP_SOCKET_NUM = IMPS_SOCKET_END                 /* Max IP socket number: 25 */
#else
    MAX_IP_SOCKET_NUM = 25
#endif    
} soc_max_num_enum;

/*
 * <GROUP  Macro_Consts>
 *  
 * max SMS sockets supported 
 */
#define MAX_SMS_SOCKET_NUM  (3)     

/*
 * <GROUP  Macro_Consts>
 * 
 * Max socket number: Max IP socket number +  Max SMS socket number 
 */
#define MAX_SOCKET_NUM      (MAX_IP_SOCKET_NUM + MAX_SMS_SOCKET_NUM)

/*
 * <GROUP  Macro_Consts>
 * 
 * Check if this is the IP socket id 
 */
#define IS_IP_SOCKET_NUM(s)     (0 <= (s) && (s) < MAX_IP_SOCKET_NUM)

/*
 * <GROUP  Macro_Consts>
 * 
 * Check if this is the SMS socket id 
 */
#define IS_SMS_SOCKET_NUM(s)    (MAX_IP_SOCKET_NUM <= (s) && (s) < MAX_SOCKET_NUM)

/*
 * <GROUP  Macro_Consts>
 * 
 * check if this is a valid socket id 
 */
#define IS_VALID_SOCKET_NUM(s)  (0 <= (s) && (s) < MAX_SOCKET_NUM)


/*
 * <GROUP  Macro_Consts>
 * 
 * Number of socket slots in TCPIP. latter half part is temp socket id for incoming connections 
 */
#define MAX_TCPIP_SOC_NUM     (MAX_IP_SOCKET_NUM * 2)

/*
 * <GROUP  Macro_Consts>
 * 
 * network account size in SMS address 
 */
#define MAX_NWK_ACCT_SIZE           (4)

/*
 * <GROUP  Macro_Consts>
 * 
 * max socket address length 
 */
#define MAX_SOCK_ADDR_LEN           (28)

/*
 * <GROUP  Macro_Consts>
 *
 * length of an IP address 
 */
#define  IP_ADDR_LEN    (4)    

/*
 * <GROUP  Macro_Consts>
 * 
 * length of an Ethernet address 
 */
#define  ETHER_ADDR_LEN     (6)

#ifdef __TCPIP__
/*
 * <GROUP  Macro_Consts>
 * 
 * loopback address 
 */
#define LOOPBACK_ADDR    (0x7f000000)

/*
 * <GROUP  Macro_Consts>
 * 
 * loopback mask address 
 */
#define LOOPBACK_MASK    (0xff000000)  
#endif /* __TCPIP__ */  

/*
 * <GROUP  Macro_Consts>
 * 
 * Protocol Familty.  Currently, we only support Internet 
 */
#define SOC_PF_INET (0)

/* Protocols (RFC 1700) */

/*
 * <GROUP  Macro_Consts>
 * 
 * Control message protocol. Currently, only allow applicaion to set this type when RAW_SOCKET is used 
 */
#define SOC_IPPROTO_ICMP    (1)

/* for SOC/TCP/IP internal use, application shall NOT use */

/*
 * <GROUP  Macro_Consts>
 * 
 * dummy for IP 
 */
#define SOC_IPPROTO_IP      (0)

/*
 * <GROUP  Macro_Consts>
 * 
 * IP6 hop-by-hop options 
 */
#define SOC_IPPROTO_HOPOPTS (0)     

/*
 * <GROUP  Macro_Consts>
 * 
 * group mgmt protocol 
 */
#define SOC_IPPROTO_IGMP    (2)  

/*
 * <GROUP  Macro_Consts>
 * 
 * IPv4 encapsulation 
 */
#define SOC_IPPROTO_IPV4    (4)     

/*
 * <GROUP  Macro_Consts>
 * 
 * for compatibility 
 */
#define SOC_IPPROTO_IPIP    SOC_IPPROTO_IPV4    

/*
 * <GROUP  Macro_Consts>
 * 
 * tcp protocol  
 */
#define SOC_IPPROTO_TCP     (6)             

/*
 * <GROUP  Macro_Consts>
 * 
 * user datagram protocol 
 */
#define SOC_IPPROTO_UDP     (17)    

/*
 * <GROUP  Macro_Consts>
 * 
 * raw IP packet 
 */
#define SOC_IPPROTO_RAW     (255)   


/* Socket Type */
typedef enum
{
    SOC_SOCK_STREAM = 0,  /* stream socket, TCP */
    SOC_SOCK_DGRAM,       /* datagram socket, UDP */
    SOC_SOCK_SMS,         /* SMS bearer */
    SOC_SOCK_RAW          /* raw socket */
} socket_type_enum;

/*
 * <GROUP  Macro_Consts>
 * 
 * process out-of-band data 
 */
#define SOC_MSG_OOB         0x1
/*
 * <GROUP  Macro_Consts>
 * 
 * peek at incoming message and keep 
 * the received data in receive buffer without
 * removing it from the buffer.
 */
#define SOC_MSG_PEEK        0X2     
/*
 * <GROUP  Macro_Consts>
 * 
 * send without using routing tables 
 */
#define SOC_MSG_DONTROUTE   0x4   
/*
 * <GROUP  Macro_Consts>
 * 
 * data completes record  
 */
#define SOC_MSG_EOR         0x8   
/*
 * <GROUP  Macro_Consts>
 * 
 * data discarded before delivery  
 */
#define SOC_MSG_TRUNC       0x10    
/*
 * <GROUP  Macro_Consts>
 * 
 * control data lost before delivery 
 */
#define SOC_MSG_CTRUNC      0x20    
/*
 * <GROUP  Macro_Consts>
 * 
 * wait for full request or error 
 */
#define SOC_MSG_WAITALL     0x40    
/*
 * <GROUP  Macro_Consts>
 * 
 * this message should be nonblocking 
 */
#define SOC_MSG_DONTWAIT    0x80    
/*
 * <GROUP  Macro_Consts>
 * 
 * data completes connection 
 */
#define SOC_MSG_EOF         0x100   
/*
 * <GROUP  Macro_Consts>
 * 
 * used in sendit() 
 */
#define SOC_MSG_COMPAT      0x8000  


/* DOM-NOT_FOR_SDK-BEGIN */
/* TCPIP error cause. This is only used by TCPIP */
typedef enum
{
    TCPIP_ENOBUF = -20,
    TCPIP_ENOBUFS,        /* -19 */
    TCPIP_EINVAL,         /* -18 */
    TCPIP_EAFNOSUPPORT,   /* -17 */
    TCPIP_EPNOSUPPORT,    /* -16 */
    TCPIP_ECONNRESET,     /* -15 */
    TCPIP_EADDRINUSE,     /* -14 */
    TCPIP_EADDRNOTAVAIL,  /* -13 */
    TCPIP_EACCES,         /* -12 */
    TCPIP_EMSGSIZE,       /* -11 */
    TCPIP_EHOSTUNREACH,   /* -10 */
    TCPIP_ENETDOWN,       /*  -9 */
    TCPIP_EISCONN,        /*  -8 */
    TCPIP_ENOTCONN,       /*  -7 */
    TCPIP_ECONNREFUSED,   /*  -6 */
    TCPIP_EBEARERFAIL     /*  -5 */
} tcpip_error_cause;
/* DOM-NOT_FOR_SDK-END */

/* howto arguments for shutdown(2), specified by Posix.1g. */
typedef enum
{
    SHUT_RD   = 0x01,         /* shut down the reading side */
    SHUT_WR   = 0x02,         /* shut down the writing side */
    SHUT_RDWR = SHUT_RD | SHUT_WR   /* shut down both sides */
} soc_shutdown_enum;


/* Socket Options */
typedef enum
{
    SOC_OOBINLINE     = 0x01 << 0,  /* not support yet */
    SOC_LINGER        = 0x01 << 1,  /* linger on close */
    SOC_NBIO          = 0x01 << 2,  /* Nonblocking */
    SOC_ASYNC         = 0x01 << 3,  /* Asynchronous notification */   

    SOC_NODELAY       = 0x01 << 4,  /* disable Nagle algorithm or not */
    SOC_KEEPALIVE     = 0x01 << 5,  /* enable/disable the keepalive */
    SOC_RCVBUF        = 0x01 << 6,  /* set the socket receive buffer size */
    SOC_SENDBUF       = 0x01 << 7,  /* set the socket send buffer size */

    SOC_NREAD         = 0x01 << 8,  /* no. of bytes for read, only for soc_getsockopt */
    SOC_PKT_SIZE      = 0x01 << 9,  /* datagram max packet size */
    SOC_SILENT_LISTEN = 0x01 << 10, /* SOC_SOCK_SMS property */
    SOC_QOS           = 0x01 << 11, /* set the socket qos */

    SOC_TCP_MAXSEG    = 0x01 << 12, /* set the max segmemnt size */
    SOC_IP_TTL        = 0x01 << 13, /* set the IP TTL value */
    SOC_LISTEN_BEARER = 0x01 << 14, /* enable listen bearer */
    SOC_UDP_ANY_FPORT = 0x01 << 15, /* enable UDP any foreign port */

    SOC_WIFI_NOWAKEUP = 0x01 << 16, /* send packet in power saving mode */
    SOC_UDP_NEED_ICMP = 0x01 << 17, /* deliver NOTIFY(close) for ICMP error */
    SOC_IP_HDRINCL    = 0x01 << 18,  /* IP header included for raw sockets */
    SOC_IPSEC_POLICY      = 0x01 << 19, /* ip security policy */
    SOC_TCP_ACKED_DATA  = 0x01 << 20,  /* TCPIP acked data */
    SOC_TCP_DELAYED_ACK = 0x01 << 21, /* TCP delayed ack */
    SOC_TCP_SACK        = 0x01 << 22, /* TCP selective ack */
    SOC_TCP_TIME_STAMP  = 0x01 << 23,  /* TCP time stamp */
    SOC_TCP_ACK_MSEG  = 0x01 << 24   /* TCP ACK multiple segment */
} soc_option_enum;


/*
 * <GROUP  Macro_Consts>
 * 
 * Qos profile 
 */
#define SOC_NEW_QOS_PROFILE    (0xFF)

/*
 * <GROUP  Macro_Consts>
 * 
 * Max downlink filter number 
 */
#define SOC_MAX_DL_FILTER_NUM  (8)

/* Qos enum */
typedef enum
{
    SOC_QOS_BEST_EFFORT = 0x00,  /* (DSCP, ToS) = (0x00, 0x00), (0x18, 0x60) */
    SOC_QOS_BACKGROUND  = 0x40,  /* (DSCP, ToS) = (0x10, 0x40), (0x08, 0x20) */
    SOC_QOS_VIDEO       = 0x80,  /* (DSCP, ToS) = (0x20, 0x80), (0x28, 0xA0) */
    SOC_QOS_VOICE       = 0xC0   /* (DSCP, ToS) = (0x30, 0xC0), (0x38, 0xE0) */
} soc_qos_enum;


/* Socket return codes, negative values stand for errors */
typedef enum
{
    SOC_SUCCESS           = 0,     /* success */
    SOC_ERROR             = -1,    /* error */
    SOC_WOULDBLOCK        = -2,    /* not done yet */
    SOC_LIMIT_RESOURCE    = -3,    /* limited resource */
    SOC_INVALID_SOCKET    = -4,    /* invalid socket */
    SOC_INVALID_ACCOUNT   = -5,    /* invalid account id */
    SOC_NAMETOOLONG       = -6,    /* address too long */
    SOC_ALREADY           = -7,    /* operation already in progress */
    SOC_OPNOTSUPP         = -8,    /* operation not support */
    SOC_CONNABORTED       = -9,    /* Software caused connection abort */
    SOC_INVAL             = -10,   /* invalid argument */
    SOC_PIPE              = -11,   /* broken pipe */
    SOC_NOTCONN           = -12,   /* socket is not connected */
    SOC_MSGSIZE           = -13,   /* msg is too long */
    SOC_BEARER_FAIL       = -14,   /* bearer is broken */
    SOC_CONNRESET         = -15,   /* TCP half-write close, i.e., FINED */
    SOC_DHCP_ERROR        = -16,   /* DHCP error */
    SOC_IP_CHANGED        = -17,   /* IP has changed */
    SOC_ADDRINUSE         = -18,   /* address already in use */
    SOC_CANCEL_ACT_BEARER = -19    /* cancel the activation of bearer */
} soc_error_enum;


/* event */
typedef enum
{
    SOC_READ    = 0x01,  /* Notify for read */
    SOC_WRITE   = 0x02,  /* Notify for write */
    SOC_ACCEPT  = 0x04,  /* Notify for accept */
    SOC_CONNECT = 0x08,  /* Notify for connect */
    SOC_CLOSE   = 0x10   /* Notify for close */
} soc_event_enum;

/* DNS server address type */
typedef enum
{
    SOC_PRI_DNS_SRV_ADDR = 0, /* primary DNS server address */
    SOC_SEC_DNS_SRV_ADDR = 1, /* secondary DNS server address */
    SOC_MAX_APP_DNS_SRV_ADDR  /* max DNS server address */
} soc_dns_srv_addr_enum;

#ifdef __IPSEC__
/*
 * <GROUP  Macro_Consts>
 * 
 * IPv6 address family. It is used by IPSEC 
 */
#define SOC_AF_INET6    (1)

/*
 * <GROUP  Macro_Consts>
 * 
 * "key" protocol family. It is used by IPSEC 
 */
#define SOC_PF_KEY      (6)

/* IPSEC protocol */

/*
 * <GROUP  Macro_Consts>
 * 
 * IP6 Encap Sec. Payload 
 */
#define	SOC_IPPROTO_ESP		50

/*
 * <GROUP  Macro_Consts>
 * 
 * IP6 Auth Header 
 */
#define	SOC_IPPROTO_AH		51		

/*
 * <GROUP  Macro_Consts>
 * 
 * payload compression (IPComp) 
 */
#define	SOC_IPPROTO_IPCOMP  108

#define	SOC_IPPROTO_DONE	257

#endif  /* __IPSEC__ */


#endif /* !_SOC_CONSTS_H */


