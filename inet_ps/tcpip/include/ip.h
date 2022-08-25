
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
 * ip.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Header file of ip_input.c and ip_output.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/*
 * Copyright (c) 1982, 1986, 1993
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
 * @(#)ip.h 8.2 (Berkeley) 6/1/94
 * $FreeBSD: src/sys/netinet/ip.h,v 1.17 1999/12/22 19:13:20 shin Exp $
 */
#ifdef __MTK_TARGET__

#ifndef _IP_H_
#define _IP_H_
#if 0
#ifndef _TCPIP_CONFIG_H_
/* under construction !*/
#endif /* !_TCPIP_CONFIG_H_ */
#endif
#ifndef _CBM_API_H
#include "cbm_api.h"
#endif
/* auto add by kw_check begin*/
#include "tcpip_config.h"
#include "soc2tcpip_struct.h"
#include "in.h"
//#include "kal_non_specific_general_types.h"
#include "kal_general_types.h"

#include "cbm_consts.h"
#include "route.h"
/* auto add by kw_check end */
/*
 * Definitions for internet protocol version 4.
 * Per RFC 791, September 1981.
 */
#define IPVERSION   4

/*
 * Structure of an internet header, naked of options.
 */
typedef struct ip
{
    u_char ip_vhl;          /* version << 4 | header length >> 2 */
    u_char ip_tos;          /* type of service */
    u_short ip_len;         /* total length */
    u_short ip_id;          /* identification */
    u_short ip_off;         /* fragment offset field */
    u_char ip_ttl;          /* time to live */
    u_char ip_p;            /* protocol */
    u_short ip_sum;         /* checksum */
    struct in_addr ip_src, ip_dst;  /* source and dest address */
} ip;

#define	IP_MAKE_VHL(v, hl)	((v << 4) | hl)
#define	IP_VHL_HL(vhl)		(vhl & 0x0f)
#define	IP_VHL_V(vhl)		(vhl >> 4)
#define	IP_VHL_BORING		0x45

#define	IP_RF 0x8000            /* reserved fragment flag */
#define	IP_DF 0x4000            /* dont fragment flag */
#define	IP_MF 0x2000            /* more fragments flag */
#define	IP_OFFMASK 0x1fff       /* mask for fragmenting bits */

typedef enum
{
    IP_DONT_FRAGMENT = 0,
    IP_ALLOW_FRAGMENT,
    IP_FRAGMENT_NOT_LAST,
    IP_FRAGMENT_LAST
} ip_fragment_flag_enum;

#define	IP_MAXPACKET    65535   /* maximum packet size */

/*
 * Definitions for IP type of service (ip_tos)
 */
#define	IPTOS_LOWDELAY      0x10
#define	IPTOS_THROUGHPUT    0x08
#define	IPTOS_RELIABILITY   0x04
#define	IPTOS_MINCOST       0x02
/* ECN bits proposed by Sally Floyd */
#define	IPTOS_CE        0x01    /* congestion experienced */
#define	IPTOS_ECT       0x02    /* ECN-capable transport */


/*
 * Definitions for options.
 */
#define	IPOPT_COPIED(o)     ((o)&0x80)
#define	IPOPT_CLASS(o)      ((o)&0x60)
#define	IPOPT_NUMBER(o)     ((o)&0x1f)

#define	IPOPT_CONTROL       0x00
#define	IPOPT_RESERVED1     0x20
#define	IPOPT_DEBMEAS       0x40
#define	IPOPT_RESERVED2     0x60

#define IPOPT_EOL       0       /* end of option list */
#define IPOPT_NOP       1       /* no operation */

#define IPOPT_RR        7       /* record packet route */
#define IPOPT_TS        68      /* timestamp */
#define IPOPT_SECURITY     130  /* provide s,c,h,tcc */
#define IPOPT_LSRR      131     /* loose source route */
#define IPOPT_SSRR      137     /* strict source route */

/*
 * Offsets to fields in options other than EOL and NOP.
 */
#define IPOPT_OPTVAL        0       /* option ID */
#define IPOPT_OLEN          1       /* option length */
#define IPOPT_OFFSET        2       /* offset within option */
#define IPOPT_MINOFF        4       /* min value of above */

/* flag bits for ipt_flg */
#define IPOPT_TS_TSONLY     0       /* timestamps only */
#define IPOPT_TS_TSANDADDR  1       /* timestamps and addresses */
#define IPOPT_TS_PRESPEC    3       /* specified modules only */

/* bits for security (not byte swapped) */
#define IPOPT_SECUR_UNCLASS  0x0000
#define IPOPT_SECUR_CONFID   0xf135
#define IPOPT_SECUR_EFTO     0x789a
#define IPOPT_SECUR_MMMM     0xbc4d
#define IPOPT_SECUR_RESTR    0xaf13
#define IPOPT_SECUR_SECRET   0xd788
#define IPOPT_SECUR_TOPSECRET   0x6bc5

/*
 * Internet implementation parameters.
 */
#define MAXTTL      255     /* maximum time to live (seconds) */
#define IPDEFTTL    128      /* default ttl, from RFC 1340 */
#define IPFRAGTTL   60      /* time to live for frags, slowhz */ /* attar : ticks : every 0.5s */
#define IPTTLDEC    1       /* subtracted when forwarding */

#define IP_MSS      576     /* default maximum segment size */

#ifdef __IPSEC__    /* added by hyzhang */

/* flags passed to ip_output as last parameter */
#define	IP_FORWARDING		0x1		/* most of ip header exists */
#define	IP_RAWOUTPUT		0x2		/* raw ip header exists */
#define	IP_SENDONES		    0x4		/* send all-ones broadcast */
#define	IP_ROUTETOIF		SO_DONTROUTE	/* bypass routing tables */
#define	IP_ALLOWBROADCAST	SO_BROADCAST	/* can send broadcast packets */

#endif

/*
 * Overlay for ip header used by other protocols (tcp, udp), 20 bytes.
 */
struct ip_overlay_struct
{
    u_char ih_x1[9];        /* (unused) */
    u_char ih_pr;           /* protocol */
    u_short ih_len;         /* protocol length */
    struct in_addr ih_src;      /* source internet address */
    struct in_addr ih_dst;      /* destination internet address */
};

/*
 * Ip reassembly queue structure.  Each fragment
 * being reassembled is attached to one of these structures.
 * They are timed out after ipq_ttl drops to 0, and may also
 * be reclaimed if memory becomes tight.
 */
struct ipq_struct
{
    struct ipq_struct *next, *prev; /* to other reass headers */
    u_char ipq_ttl;                 /* time for reass q to live */
    u_char ipq_p;                   /* protocol of this fragment */
    u_short ipq_id;                 /* sequence id for reassembly */
    kal_uint8 profile_id;           /* source profile_id */
    struct mbuf *ipq_frags;         /* to ip headers of fragments */
    struct in_addr ipq_src, ipq_dst;
};

/*
 * Structure stored in mbuf in inpcb.ip_options
 * and passed to ip_output when ip options are in use.
 * The actual length of the options (including ipopt_dst)
 * is in m_len.
 */
#define MAX_IPOPTLEN    40

struct ipoption
{
    struct in_addr ipopt_dst;       /* first-hop dst if source routed */
    char ipopt_list[MAX_IPOPTLEN];  /* options proper */
};

/* Packet reassembly stuff */

#define IPREASS_NHASH_LOG2      2
#define IPREASS_NHASH           (1 << IPREASS_NHASH_LOG2)
#define IPREASS_HMASK           (IPREASS_NHASH - 1)
#define IPREASS_HASH(x,y)   \
        (((x & 0xF) ^ (y & 0xF)) & IPREASS_HMASK)


extern kal_uint32  tcpip_stop_g;

extern void ip_init(void);
#ifdef UDP_SUPPORT
extern void udp_init(void);
extern void udp_input(kal_uint8 profile_id, struct mbuf *m, int off, int proto);

#endif /* UDP_SUPPORT */

#ifdef TCP_SUPPORT
extern void tcp_init(void);
extern void tcp_ctlinput(int cmd, struct sockaddr *sa, void *vip);
extern void tcp_input(kal_uint8 profile_id, struct mbuf *m, int off0, int proto);
#endif /* TCP_SUPPORT */

#ifdef RIP_SUPPORT
extern void rip_init(void);
extern void raw_ip_input(kal_uint8 profile_id, struct mbuf *m, int off, int proto);

#endif /* RIP_SUPPORT */

#ifdef __IPSEC__
extern void ipsec_up_input(cbm_bearer_enum bearer_id, kal_uint8 profile_id, 
                           struct mbuf *m, int off);
extern void ah4_input(cbm_bearer_enum bearer_id, kal_uint8 profile_id, 
                      struct mbuf *m, int off);

#ifdef IPSEC_ESP
extern void esp4_input(cbm_bearer_enum bearer_id, kal_uint8 profile_id, 
                       struct mbuf *m, int off);
#endif  /* IPSEC_ESP */

kal_int32 soc_tcpip_get_header_size(kal_int8 soc_id, kal_int32 profile_id, 
                                    kal_int32 *hdr_size, kal_int32 *tail_size);
#endif  /* __IPSEC__ */

extern void icmp_input(kal_uint8 profile_id, struct mbuf *, int, int);

extern void ip_input(cbm_bearer_enum bearer_id, struct mbuf *m);
extern int ip_output(kal_uint8 profile_id,
                     struct mbuf *m0,
                     struct mbuf *opt,
                     struct route *ro,
                     int flags,
                     int socket_id);

extern int ip_output_f(kal_uint8 profile_id,
                       struct mbuf *m0,
                       struct mbuf *opt,
                       struct route *ro,
                       int flags,
                       kal_uint16 *inp_ip_id,
                       kal_uint8 fragment_flags,
                       kal_uint16 fragment_offset,
                       int socket_id);

extern void ip_stripoptions(struct mbuf *m);
extern struct mbuf *ip_srcroute(void);
extern void ip_freef(struct ipq_struct *fp);

#endif /* !_IP_H_ */

#endif /* __MTK_TARGET__ */

