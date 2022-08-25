
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
 * in.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Header file of in.c
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
 * @(#)in.h 8.3 (Berkeley) 1/3/94
 * $FreeBSD: src/sys/netinet/in.h,v 1.48.2.5 2001/12/14 19:53:55 jlemon Exp $
 */
#ifdef __MTK_TARGET__

#ifndef _IN_H_
#define _IN_H_
#if 0
#ifndef _TCPIP_CONFIG_H_
/* under construction !*/
#endif /* !_TCPIP_CONFIG_H_ */
#endif
/* auto add by kw_check begin*/
#include "tcpip_config.h"
//#include "kal_non_specific_general_types.h"
#include "soc2tcpip_struct.h"
#include "cbm_consts.h"
#include "kal_general_types.h"

/* auto add by kw_check end */
 
#define	IN_CLASSA(i)		(((u_int32_t)(i) & 0x80000000) == 0)
#define	IN_CLASSA_NET		0xff000000
#define	IN_CLASSA_NSHIFT	24
#define	IN_CLASSA_HOST		0x00ffffff
#define	IN_CLASSA_MAX		128

#define	IN_CLASSB(i)		(((u_int32_t)(i) & 0xc0000000) == 0x80000000)
#define	IN_CLASSB_NET		0xffff0000
#define	IN_CLASSB_NSHIFT	16
#define	IN_CLASSB_HOST		0x0000ffff
#define	IN_CLASSB_MAX		65536

#define	IN_CLASSC(i)		(((u_int32_t)(i) & 0xe0000000) == 0xc0000000)
#define	IN_CLASSC_NET		0xffffff00
#define	IN_CLASSC_NSHIFT	8
#define	IN_CLASSC_HOST		0x000000ff

#define	IN_CLASSD(i)		(((u_int32_t)(i) & 0xf0000000) == 0xe0000000)
#define	IN_CLASSD_NET		0xf0000000	/* These ones aren't really */
#define	IN_CLASSD_NSHIFT	28		/* net and host fields, but */
#define	IN_CLASSD_HOST		0x0fffffff	/* routing needn't know.    */
#define	IN_MULTICAST(i)		IN_CLASSD(i)

#define	IN_EXPERIMENTAL(i)	(((u_int32_t)(i) & 0xf0000000) == 0xf0000000)
#define	IN_BADCLASS(i)		(((u_int32_t)(i) & 0xf0000000) == 0xf0000000)

#define	IN_EXPERIMENTAL(i)	(((u_int32_t)(i) & 0xf0000000) == 0xf0000000)
#define	IN_MULTICAST(i)		IN_CLASSD(i)

#define IN_CLASSA_NSHIFT    24
#define IN_LOOPBACKNET      127        /* official! */
#define INADDR_ANY          (u_int32_t)0x00000000
#define INADDR_LOOPBACK     (u_int32_t)0x7f000000
#define INADDR_BROADCAST    (u_int32_t)0xffffffff      /* must be masked */
#define	IN_LOOPBACKNET		127			/* official! */

#define INADDR_LOOPMASK     (u_int32_t)0xff000000

typedef enum {
    FUNC_nil,
    FUNC_arprequest,
    FUNC_arp_input,
    FUNC_icmp_error,
    FUNC_icmp_input,
    FUNC_icmp_reflect,
    FUNC_router_solicit,
    FUNC_ip_srcroute,
    FUNC_ip_insertoptions,
    FUNC_tcp_output,
    FUNC_tcp_respond
} tpdu_func_enum;


/*
 * Constants and structures defined by the internet system,
 * Per RFC 790, September 1981, and numerous additions.
 */

/*
 * Local port number conventions:
 *
 * When a user does a bind(2) or connect(2) with a port number of zero,
 * a non-conflicting local port address is chosen.
 * The default range is IPPORT_RESERVED through
 * IPPORT_USERRESERVED, although that is settable by sysctl.
 *
 * A user may set the IPPROTO_IP option IP_PORTRANGE to change this
 * default assignment range.
 *
 * The value IP_PORTRANGE_DEFAULT causes the default behavior.
 *
 * The value IP_PORTRANGE_HIGH changes the range of candidate port numbers
 * into the "high" range.  These are reserved for client outbound connections
 * which do not want to be filtered by any firewalls.
 *
 * The value IP_PORTRANGE_LOW changes the range to the "low" are
 * that is (by convention) restricted to privileged processes.  This
 * convention is based on "vouchsafe" principles only.  It is only secure
 * if you trust the remote host to restrict these ports.
 *
 * The default range of ports and the high range can be changed by
 * sysctl(3).  (net.inet.ip.port{hi,low}{first,last}_auto)
 *
 * Changing those values has bad security implications if you are
 * using a a stateless firewall that is allowing packets outside of that
 * range in order to allow transparent outgoing connections.
 *
 * Such a firewall configuration will generally depend on the use of these
 * default values.  If you change them, you may find your Security
 * Administrator looking for you with a heavy object.
 *
 * For a slightly more orthodox text view on this:
 *
 *            ftp://ftp.isi.edu/in-notes/iana/assignments/port-numbers
 *
 *    port numbers are divided into three ranges:
 *
 *                0 -  1023 Well Known Ports
 *             1024 - 49151 Registered Ports
 *            49152 - 65535 Dynamic and/or Private Ports
 *
 */

/*
 * Ports < IPPORT_RESERVED are reserved for
 * privileged processes (e.g. root).         (IP_PORTRANGE_LOW)
 * Ports > IPPORT_USERRESERVED are reserved
 * for servers, not necessarily privileged.  (IP_PORTRANGE_DEFAULT)
 */
#ifndef _CBM_API_H
//#include "cbm_api.h"
#endif

//#include "custom_data_account.h"
//#include "abm_api.h"

/* allow the special cases for sending DHCP messages */
#define DHCP_SERVERPORT (67)
#define DHCP_CLIENTPORT (68)


//#define	IPPORT_RESERVED     0 
#define	IPPORT_RESERVED        1024
#define	IPPORT_USERRESERVED    5000
//#ifndef __HOTSPOT_SUPPORT__
#define	IPPORT_HIFIRSTAUTO     49152
//#else
//#define	IPPORT_HIFIRSTAUTO     58000
//#endif
#define	IPPORT_HILASTAUTO      65535

#define     TCPIP_NAT_MAX_LOCAL_PORT    100

/*
 * Internet address (a structure for historical reasons)
 */
struct in_addr
{
    kal_uint32 s_addr;
};

/*
 * Definitions of bits in internet address integers.
 * On subnets, the decomposition of addresses to host and net parts
 * is done according to subnet mask, not the masks here.
 */
#define IN_CLASSD(i)        (((u_int32_t)(i) & 0xf0000000) == 0xe0000000)
#define IN_MULTICAST(i)     IN_CLASSD(i)
#define IN_BADCLASS(i)      (((u_int32_t)(i) & 0xf0000000) == 0xf0000000)

/*
 * Options for use with [gs]etsockopt at the IP level.
 * First word of comment is data type; bool is stored in int.
 */
/* attar deleted */
/*
 * Defaults and limits for options
 */
#define IP_DEFAULT_MULTICAST_TTL    1  /* normally limit m'casts to 1 hop  */
#define IP_MAX_MEMBERSHIPS          20 /* per socket */


/*
 * Structure used by kernel to store most
 * addresses.
 */
struct sockaddr
{
    u_char sa_len;      /* total length */
    u_char sa_family;   /* address family */
    char sa_data[14];   /* actually longer; address value */
};

/*
 * Socket address, internet style.
 */
struct sockaddr_in
{
    u_char     sin_len;
    u_char     sin_family;
    u_short    sin_port;
    struct     in_addr sin_addr;
    char       sin_zero[8];
};

#define satosin(sa)     ((struct sockaddr_in *)(sa))
#define sintosa(sin)    ((struct sockaddr *)(sin))

extern int in_cksum(struct mbuf *m, int len);
extern int in_cksum_hdr(u_char *h);
#ifdef __NON_4BYTES_ADJUST__  
extern int in_cksum_input(struct mbuf *m, int len);
#endif

extern int get_tcpip_profile_id(kal_uint32 ip_addr);
extern int get_tcpip_sap_id(kal_uint8 profile_id);
extern cbm_bearer_enum profile_id_to_bearer(kal_uint8 profile_id);

extern kal_uint16 tcpip_ul_free_hdr_size;


typedef struct {
    void* addr;
    tpdu_func_enum func;
} tpdu_log_struct;

/* FLC buffer debugging */
typedef struct
{
    kal_uint32 tcp_rcvd;    /* TCP send request */
    kal_uint32 tcp_sent;
    kal_uint32 sspdu_free;  /* freed TCP segments */
    //kal_uint32 tpdu_alloc;
    kal_uint32 tpdu_free;
    kal_uint32 udp_rcvd;
    kal_uint32 udp_sent;
    kal_uint32 tpdu_full;
    kal_uint32 wndrv_ind;
#ifdef TCP_LOG_RTO
    kal_uint32 tcp_rexmt_timer[100][5];
    kal_uint32 tcp_timer_index;
#endif /* TCP_LOG_RTO */
#ifdef TCP_LOG_SND_WND
    /* socket_id, tp->snd_wnd */
    kal_uint32 tcp_snd_wnd[300][2];
    kal_uint32 tcp_snd_wnd_index;
    kal_uint32 tcp_peer_win[300][2];
    kal_uint32 tcp_peer_win_index;
#endif /* TCP_LOG_SND_WND */
#ifdef TCPIP_LOG_TPDU
    tpdu_log_struct tpdu_log[50];    /* alloc, free */
#endif /* TCPIP_LOG_TPDU */
} tcpip_counter;
extern tcpip_counter g_tcpip_counter;


//#ifdef __WIFI_SUPPORT__

#define WIFI_PROFILE_ID    CBM_WIFI_ACCT_ID

//#endif /* !__WIFI_SUPPORT__ */

#define MAX_TCPIP_PROFILE_NUM    CBM_ALL_NWK_ACCT_ID//64/*MAX_ACTIVE_BEARER_NUM*/

int ip_set_usr_option(kal_uint8 profile_id,
        kal_int8 socket_id,
        kal_uint16 option,
        kal_uint8 *data,
        kal_uint8 *data_length);

int ip_get_usr_option(kal_uint8 profile_id,
        kal_int8 socket_id,
        kal_uint16 option,
        kal_uint8 *data,
        kal_uint8 *data_length);

int in_canforward(struct in_addr in);

void tpdu_mem_log(void *p, int is_alloc, tpdu_func_enum func);
void check_tpdu(void);

#endif /* !_IN_H_ */

#endif /* __MTK_TARGET__ */


