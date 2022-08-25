
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
 * in_pcb.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Header file of in_pcb.c
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

/*
 * Copyright (c) 1982, 1986, 1990, 1993
 * The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 * This product includes software developed by the University of
 * California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * @(#)in_pcb.h   8.1 (Berkeley) 6/10/93
 * $FreeBSD: src/sys/netinet/in_pcb.h,v 1.32.2.5 2001/12/14 20:21:12 jlemon Exp $
 */
#ifdef __MTK_TARGET__

#ifndef _IN_PCB_H_
#define _IN_PCB_H_
#if 0
#ifndef _TCPIP_CONFIG_H_
/* under construction !*/
#endif /* !_TCPIP_CONFIG_H_ */
#endif
/* auto add by kw_check begin*/
#include "tcpip_config.h"
#include "ip.h"
//#include "kal_non_specific_general_types.h"
#include "soc_consts.h"
#include "tcp.h"
#include "soc2tcpip_struct.h"
#include "in.h"
#include "route.h"
//#include "ipsec.h"
#include "cbm_consts.h"
#include "kal_general_types.h"
/* auto add by kw_check end */
extern struct inpcb *global_inp[];
extern struct ifnet global_ifp[];
extern struct ipq_struct ipq[];
extern kal_uint8   g_local_mac[];           /* in network byte order */
extern kal_uint32  g_local_ip;              /* in host byte order */
extern kal_uint32  g_netmask;               /* in host byte order */
extern kal_uint32  g_gateway;               /* in host byte order */
extern kal_uint8   g_gateway_mac[];         /* in network byte order, only effect while probing gateway */
extern kal_uint32  g_local_broadcast;       /* in host byte order */
extern kal_bool    dhcp_probing_gateway;

extern kal_uint32  g_wifi_ap_ip;  
extern kal_uint8   g_wifi_ap_mac[ETHER_ADDR_LEN]; 

extern struct tcpip_timer global_ip_timer;
extern int tcpip_sap_id;

extern kal_uint32  g_wifi_bearer_type; 

#define AF_INET                 2  /* internetwork: UDP, TCP, etc. */

#define INPLOOKUP_WILDCARD      1
#define INP_SENDSPACE           1024*24
#define INP_RECVSPACE           1500

#define TCP_OPT_SND_BUF         0x0001
#define TCP_OPT_RCV_BUF         0x0002
#define TCP_OPT_KEEPALIVE       0x0004
#define TCP_OPT_MAXSEG          0x0008
#define TCP_OPT_LINGER          0x0010
#define UDP_OPT_ANY_FPORT       0x0020
#define WIFI_OPT_NOWAKEUP       0x0040
#define IP_OPT_HDRINCL          0x0080




/* //////////////////////////// */
#define PRUS_OOB -6
#define PRUS_EOF -7
/* //////////////////////////// */


/*
 * Common structure pcb for internet protocol implementation.
 * Here are stored pointers to local and foreign host table
 * entries, local and foreign socket numbers, and pointers
 * up (to a socket structure) and down (to a protocol-specific)
 * control block.
 */

struct inpcbinfo
{
    struct inpcb    *listhead;
    u_short         lastport;   /* remember the last port used in system */
    u_int           ipi_count;  /* number of pcbs in this list */
};

/*
 * NB: the zone allocator is type-stable EXCEPT FOR THE FIRST TWO LONGS
 * of the structure.  Therefore, it is important that the members in
 * that position not contain any information which is required to be
 * stable.
 */

struct sockbuf
{
    u_long sb_cc;       /* actual chars in buffer */
    u_long sb_hiwat;    /* max actual char count, high water mark */
    u_long sb_mbcnt;    /* chars of mbufs used, Maui does not use it */
    u_long sb_mbmax;    /* max chars of mbufs to use, Maui does not use it */
    struct mbuf *sb_mb;     /* the mbuf chain */
};

struct inpcb
{
    struct inpcbinfo    *inp_pcbinfo;  /* PCB list info */
    struct inpcb    *inp_next;
    struct inpcb    *inp_prev;

    /* local and foreign ports, local and foreign addr */
    /* all in network byte order */
    struct in_addr      inp_laddr;
    u_short             inp_lport;
    struct in_addr      inp_faddr;
    u_short             inp_fport;

    u_char     inp_ip_p;   /* rember protocol number */
    /* protocol proto */
    kal_int8    socket_id;  /* attar: modify back pointer to socket to socket id */
    kal_uint8   profile_id;

    kal_uint8   context_id;     /* context id to TCM for secondary context */

    int         l_socket_id;    /* listen socket id for TCP accepted sockets */

    u_char      inp_ip_ttl;  /* time to live */
    u_char      inp_ip_tos;  /* type of service */
    /* IP_FRAGMENT_SUPPORT */
    u_short     inp_ip_id;      /* ip identification number */

    /* protocol dependent part; options */
    caddr_t     inp_ppcb;       /* pointer to per-protocol pcb */
    struct      route inp_route;    /* placeholder for routing entry */

    int     so_rcv_cc;          /* char count in socket receive buffer */
    int     so_rcv_sb_hiwat;    /* maximum receive buffer size for this socket */
    struct sockbuf  so_snd;     /* scottie: send buffer */

    kal_uint8   max_socket_no;  /* max allowable connections for TCP listening sockets */
    kal_uint8   acc_socket_no;  /* accepted number of socket for a listen socket */
    kal_uint8   inp_options;    /* socket options */
    kal_uint8   inp_bearer_opt; /* aceptable bearer for incoming messages */
    kal_int32   linger;         /* linger option for TCP */

#ifdef __IPSEC__    /* added by hyzhang */
    int dom_family;
    struct inpcbpolicy *inp_sp; /* for IPSEC */
#endif
};

struct ifnet
{
    kal_uint32      if_ipaddress;
    cbm_bearer_enum if_bearerid;    /* bearer of iface, e.g., CBM_BEARER_WIFI */
    kal_uint16      if_mtu;
    kal_uint8       if_flags;       /* currently unused */
    kal_uint8       context_id;       /* currently unused */    
    kal_uint8	    profile_id;	    /* used to save the profile id for CBM wang jun update*/
    kal_uint32	    rx_data;	   /* used to save the data size of rx wang jun update*/
    kal_uint32	    tx_data;	   /* used to save the data size of tx wang jun update*/
    kal_uint32      starttime;    /*used to save the start connect time in seconds.*/
    kal_uint32      if_gateway;                     /* gateway address */
    kal_uint32      if_netmask;                     /* network mask */
    kal_uint32      if_broadcast;                   /* broadcast address */    
    kal_uint8       if_mac_addr[ETHER_ADDR_LEN];    /* mac address */
    kal_bool        if_dhcp_probing_gateway;        /*dhcp prob gateway*/
    kal_uint8       if_gateway_mac[ETHER_ADDR_LEN]; /* gateway address mac */
    kal_uint32      if_wifi_ap_ip;
    kal_uint8       if_wifi_ap_mac[ETHER_ADDR_LEN]; 
};

extern int in_pcballoc(int socket_id, struct inpcbinfo *inpcbinfo);
extern void in_pcbdetach(struct inpcb *inp);
extern int in_pcbbind(struct inpcb *inp, struct sockaddr *nam);
extern int in_pcbladdr(struct inpcb *inp, struct sockaddr *nam);
extern int in_pcbconnect(struct inpcb *inp, struct sockaddr *nam);
extern void in_pcbdisconnect(struct inpcb *inp);
extern void in_pcbfree(struct inpcb *inp);
extern struct inpcb *in_pcblookup_local(struct inpcbinfo *pcbinfo,
                                        struct in_addr laddr,
                                        u_int lport_arg,
                                        int wild_okay);

extern struct inpcb *in_pcblookup_foreign(struct inpcbinfo *pcbinfo,
                                         struct in_addr faddr,
                                         u_int fport_arg,
                                         struct in_addr laddr,
                                         u_int lport_arg,
                                         int wildcard);

extern int soreserve(struct inpcb *inp, u_long sndcc);

struct inpcb *in_match_wifibroadcast(struct inpcbinfo *pcbinfo,
                                     kal_uint8 profile_id,
                                     u_int dstport);


extern kal_uint32 custom_get_tcpip_max_profile_num(void);

extern void tcpip_recv_buf_init(void);
extern int tcpip_get_soc_recv_buf(struct inpcb *inp, int proto, u_long sndcc);
extern int tcpip_put_soc_recv_buf(kal_int8 soc_id);

#endif /* !_IN_PCB_H_ */

#endif /* __MTK_TARGET__ */

