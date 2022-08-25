
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
 * tcp.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Header file of tcp_input.c and tcp_output.c
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
 * @(#)tcp.h   8.1 (Berkeley) 6/10/93
 * $FreeBSD: src/sys/netinet/tcp.h,v 1.13.2.3 2001/03/01 22:08:42 jlemon Exp $
 */
#ifdef __MTK_TARGET__

#ifndef _TCP_H_
#define _TCP_H_

#include "tcpip_config.h"
#include "event_shed.h"
#include "ip.h"
#include "in_pcb.h"
//#include "kal_release.h"
#include "in.h"
#include "route.h"
#include "mbuf.h"

#if 0
#ifndef _TCPIP_CONFIG_H_
/* under construction !*/
#endif /* !_TCPIP_CONFIG_H_ */
/* under construction !*/
/* under construction !*/
#ifndef _EVENT_SHED_H
/* under construction !*/
#endif /* _EVENT_SHED_H */
#endif
/* auto add by kw_check begin*/
#include "soc2tcpip_struct.h"
//#include "kal_non_specific_general_types.h"
//#include "kal_nucleus_common_defs.h"
/* auto add by kw_check end */
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_internal_api.h"
#include "kal_public_defs.h"


struct tcpip_timer
{
    int     c_flags;            /* state of this entry */
    eventid event_id;
};

#ifdef TCP_SUPPORT

typedef enum
{
    CLOSED_,        /* 0, closed */
    LISTEN_,        /* 1, listening for connection */
    SYN_SENT_,      /* 2, active, have sent syn */
    SYN_RCVD_,      /* 3, have sent and received syn */
    /* states < TCPS_ESTABLISHED are those where connections not established */
    ESTABLISHED_,   /* 4, established */
    CLOSE_WAIT_,    /* 5, rcvd fin, waiting for close */
    /* states > TCPS_CLOSE_WAIT are those where user has closed */
    FIN_WAIT_1_,    /* 6, have closed, sent fin */
    CLOSING_,       /* 7, closed xchd FIN; await FIN ACK */
    LAST_ACK_,      /* 8, had fin and close; await FIN ACK */
    /* states > TCPS_CLOSE_WAIT && < TCPS_FIN_WAIT_2 await ACK of FIN */
    FIN_WAIT_2_,    /* 9, have closed, fin is acked */
    TIME_WAIT_      /* 10, in 2*msl quiet wait after close */
} tcp_states;


typedef u_int32_t tcp_seq;
typedef u_int32_t tcp_cc;       /* connection count per rfc1644 */

/*
 * TCP header.
 * Per RFC 793, September, 1981.
 */
struct tcphdr
{
    u_short th_sport;       /* source port */
    u_short th_dport;       /* destination port */
    tcp_seq th_seq;         /* sequence number */
    tcp_seq th_ack;         /* acknowledgement number */
    u_char th_off;          /* tcp data offset + unused 4 bits */
    u_char th_flags;
    u_short th_win;         /* window */
    u_short th_sum;         /* checksum */
    u_short th_urp;         /* urgent pointer */
};


/*
 * Tcp+ip header, after ip options removed.
 */
struct tcp_ip_hdr_struct
{
    struct  ip_overlay_struct ti_i;     /* overlaid ip structure */
    struct  tcphdr ti_t;                /* tcp header */
};

#define TH_FIN  0x01
#define TH_SYN  0x02
#define TH_RST  0x04
#define TH_PUSH 0x08
#define TH_ACK  0x10
#define TH_URG  0x20
#define TH_ECE  0x40
#define TH_CWR  0x80
#define TH_FLAGS    (TH_FIN|TH_SYN|TH_RST|TH_ACK|TH_URG|TH_ECE|TH_CWR)

/*
 * TCP FSM state definitions.
 * Per RFC793, September, 1981.
 */

#define TCP_NSTATES 11

#define TCPS_CLOSED     0       /* closed */
#define TCPS_LISTEN     1       /* listening for connection */
#define TCPS_SYN_SENT       2   /* active, have sent syn */
#define TCPS_SYN_RECEIVED   3   /* have send and received syn */
/* states < TCPS_ESTABLISHED are those where connections not established */
#define TCPS_ESTABLISHED    4   /* established */
#define TCPS_CLOSE_WAIT     5   /* rcvd fin, waiting for close */
/* states > TCPS_CLOSE_WAIT are those where user has closed */
#define TCPS_FIN_WAIT_1     6   /* have closed, sent fin */
#define TCPS_CLOSING        7   /* closed xchd FIN; await FIN ACK */
#define TCPS_LAST_ACK       8   /* had fin and close; await FIN ACK */
/* states > TCPS_CLOSE_WAIT && < TCPS_FIN_WAIT_2 await ACK of FIN */
#define TCPS_FIN_WAIT_2     9   /* have closed, fin is acked */
#define TCPS_TIME_WAIT      10  /* in 2*msl quiet wait after close */


/* tcp_var.h */
/* TCP segment queue entry */
struct tseg_qent
{
    struct
    {
        struct tseg_qent *le_next;  /* next element */
        struct tseg_qent **le_prev; /* address of previous next element */
    } tqe_q;
    int tqe_len;                    /* TCP segment data length */
#ifdef TCPSACK_SUPPORT
    /* The timstamp can be used to find first four new continous data blocks */
    u_int32_t sackblocks_ts;
#endif /* TCPSACK_SUPPORT */
    struct tcphdr *tqe_th;          /* a pointer to tcp header */
    struct mbuf *tqe_m;             /* mbuf contains packet */
};

struct tsegqe_head
{
    struct tseg_qent *lh_first; /* first element */
};

#ifdef TCPSACK_SUPPORT
typedef enum
{
    NORMAL = 0,
    ENLARGE
} SACK_QUEUE_UPDATE_TYPE;

struct sack_rxtseg_block
{
    unsigned int left_edge;         /* The left edge of a data block needs to be retransmitted */
    unsigned int right_edge;        /* The right edge of a data block needs to be retransmitted */
    struct sack_rxtseg_block *next; /* The next data block needs to be retransmitted */
};

struct sack_rxtseg_queue
{
    unsigned int protect;
    unsigned int max_seq;   /* The right edge of this sack retransmission queue */
    unsigned int min_seq;   /* The left edge of this sack retransmission queue */
    struct sack_rxtseg_block *head;
};
#endif /* TCPSACK_SUPPORT */

/*
 * Tcp control block, one per tcp; fields:
 * Organized for 16 byte cacheline efficiency.
 */

typedef enum
{
    DONT_FREE = 0,
    NEED_FREE
} free_status;

struct tcpcb
{
    int free_flag;
    int t_dupacks;              /* consecutive dup acks recd */
    struct tsegqe_head t_segq;  /* this is the sequence queue of tcp module */
    u_int t_maxseg;             /* maximum segment size */
    u_int t_maxopd;             /* sizeof MSS + TCP option */

    /* TCP timers */
    struct tcpip_timer tt_rexmt;    /* retransmit timer */
    struct tcpip_timer tt_persist;  /* retransmit persistence */
    struct tcpip_timer tt_keep;     /* keepalive */
    struct tcpip_timer tt_2msl;     /* 2*msl TIME_WAIT timer */
    struct tcpip_timer tt_delack;   /* delayed ACK timer */
#ifdef TCPSACK_SUPPORT
    struct tcpip_timer tt_sackrxt;  /* SACK retransmit timer */
#endif /* TCPSACK_SUPPORT */
    struct inpcb *t_inpcb;          /* back pointer to internet pcb */
    int t_state;                    /* state of this connection */
    u_int t_flags;
    int t_force;            /* 1 if forcing out a byte *//* attar : persists to send */
    int needWait2MSL;       /* 1: wait 2MSL and close socket; 0: Close socket immediately */

    /* send sequence numbers */
    tcp_seq snd_una;    /* send unacknowledged */
    tcp_seq snd_nxt;    /* send next */
    tcp_seq snd_up;     /* send urgent pointer */
    tcp_seq snd_wl1;    /* window update seg seq number */
    tcp_seq snd_wl2;    /* window update seg ack number */
    tcp_seq iss;        /* initial send sequence number */
    u_long snd_wnd;     /* send window */

    /* receive sequence numbers */
    u_long  rcv_wnd;    /* receive window */
    tcp_seq rcv_nxt;    /* receive next */
    tcp_seq rcv_up;     /* receive urgent pointer */
    tcp_seq irs;        /* initial receive sequence number */

    /* retransmit var */
    tcp_seq snd_max;    /* highest sequence number sent;
                         * used to recognize retransmits
                         */
    /* receive var */
    tcp_seq rcv_adv;    /* advertised window */

    /* congesting control */
    u_long snd_cwnd;        /* congestion-controlled window */
    u_long snd_ssthresh;    /* snd_cwnd size threshold for
                             * for slow start exponential to
                             * linear switch
                             */
    /* other vars */
    tcp_seq snd_recover;    /* for use in fast recovery */

    u_long t_rcvtime;   /* inactivity time, the latest time that we receives peer's segment */
    u_long t_starttime; /* time connection was established */
    int t_rtttime;      /* round trip time */
    tcp_seq t_rtseq;    /* sequence number being timed */
    int t_rxtcur;       /* current retransmit value (ticks) */
    int t_srtt;         /* smoothed round-trip time */
    int t_rttvar;       /* variance in round-trip time */

    /* Scotiie: Retransmit Times */
    int t_rxtshift;         /* log(2) of rexmt exp. backoff */
    u_int t_rttmin;         /* minimum rtt allowed */
    u_long t_rttupdated;    /* number of times rtt sampled */
    u_long max_sndwnd;      /* largest window peer has offered */

    u_char snd_scale;       /* window scaling for send window */
    u_char rcv_scale;       /* window scaling for recv window */
    u_char request_r_scale; /* pending window scaling */
    u_char requested_s_scale;
    u_long ts_recent;       /* timestamp echo data */
    u_long ts_recent_age;   /* when last updated */
    tcp_seq last_ack_sent;
    u_long syn_sent_tick;   /* time of last SYN, for SYNACK with zero Tstamp */

    /* experimental */
    /* Scottie: The following three variables are used to prevent
     * bad retransmit, see tcp_timer_rexmt() */
    u_long snd_cwnd_prev;       /* cwnd prior to retransmit *//* Scottie: Kept the cwnd value before retransmitting an TCP segment. */
    u_long snd_ssthresh_prev;   /* ssthresh prior to retransmit *//* Scottie: Kept the ssthresh value before retransmitting an TCP segment. */
    u_long t_badrxtwin;         /* window for retransmit recovery */
    /* Scottie: t_badrxtwin, an estimated time period, if we can get ack
     * for previous restransmitted segment within this period.
     * It menas that we shall not retransmit the previous segment.
     * Because the ack is in flight already.
     */
#ifdef TCPSACK_SUPPORT
    u_int32_t sack_timestamp;   /* The TCP segement that triggers us to reply SACK option */
    struct sack_rxtseg_queue sack_rxt_queue;
#endif /* TCPSACK_SUPPORT */
    kal_uint64 snd_acked;
};

struct tcptemp
{
    u_char tt_ipgen[40];    /* the size must be of max ip header, now IPv6 */
    struct tcphdr tt_t;
};

/*
 * Structure to hold TCP options that are only used during segment
 * processing (in tcp_input), but not held in the tcpcb.
 * It's basically used to reduce the number of parameters
 * to tcp_dooptions.
 */
struct tcpopt
{
    u_long      to_flags;    /* which options are present */
    u_int32_t   to_tsval;
    u_int32_t   to_tsecr;
    u_int16_t   to_mss;
    u_int8_t    to_requested_s_scale;
#ifdef TCPSACK_SUPPORT
    /* Scottie: In TCP implementation, there are at most four data blocks in SACK option. */
    u_int8_t    to_pad;
    int     no_sackblocks;      /* no_blocks must be in the range of 0-4. */
    u_int32_t   sack_blocks[4][2];
    /* [][0]: left edge of a continous data block,
     * [][1]: right edge of a continous data block
     */
#else /* !TCPSACK_SUPPORT */
    u_int8_t    to_pad;
#endif /* !TCPSACK_SUPPORT */
};

#define TOF_TS          0x0001      /* timestamp */
#define TOF_MSS         0x0010
#define TOF_SCALE       0x0020
#define TOF_SACKP       0x0040      /* for SACK Permitted */
#define TOF_SACK        0x0080      /* for SACK Option */

#define intotcpcb(ip)   ((struct tcpcb *)(ip)->inp_ppcb)

#define TCPOPT_EOL          0
#define TCPOPT_NOP          1
#define TCPOPT_MAXSEG       2
#define TCPOLEN_MAXSEG      4
#define TCPOPT_WINDOW       3
#define TCPOLEN_WINDOW      3
#define TCPOPT_SACK_PERMITTED       4       /* Experimental */
#define TCPOLEN_SACK_PERMITTED      2
#define TCPOPT_SACK         5       /* Experimental */
#define TCPOMINLEN_SACK     10
#define TCPOMAXLEN_SACK     34
#define TCPOPT_TIMESTAMP    8
#define TCPOLEN_TIMESTAMP   10
#define TCPOLEN_TSTAMP_APPA     (TCPOLEN_TIMESTAMP + 2)  /* appendix A */
#define TCPOPT_TSTAMP_HDR                   \
    (TCPOPT_NOP << 24 | TCPOPT_NOP << 16 |  \
     TCPOPT_TIMESTAMP << 8 | TCPOLEN_TIMESTAMP)

/*
 * Default maximum segment size for TCP.
 * With an IP MSS of 576, this is 536,
 * but 512 is probably more convenient.
 * This should be defined as MIN(512, IP_MSS - sizeof (struct tcp_ip_hdr_struct)).
 */
#define TCP_MSS     512

#define TCP_MAXWIN  65535       /* largest value for (unscaled) window */
#define TTCP_CLIENT_SND_WND  4096   /* dflt send window for T/TCP client */

#define TCP_MAX_WINSHIFT    14  /* maximum window shift */

#define TCP_MAXBURST        4   /* maximum segments in a burst */

#define TCP_MAXHLEN     (0xf<<2)    /* max length of header in bytes */
#define TCP_MAXOLEN     (TCP_MAXHLEN - sizeof(struct tcphdr))
                        /* max space left for options, 40 bytes */

/*
 * User-settable options (used with setsockopt).
 */
#define TCP_NODELAY     0x01    /* don't delay send to coalesce packets */
#define TCP_MAXSEG      0x02    /* set maximum segment size */
#define TCP_NOPUSH      0x04    /* don't push last block of write */
#define TCP_NOOPT       0x08    /* don't use TCP options */

#define TF_ACKNOW       0x00001     /* ack peer immediately */
#define TF_DELACK       0x00002     /* ack, but try to delay it */
#define TF_NODELAY      0x00004     /* don't delay packets to coalesce */
#define TF_NOOPT        0x00008     /* don't use tcp options */
#define TF_SENTFIN      0x00010     /* have sent FIN */
#define TF_REQ_SCALE    0x00020     /* have/will request window scaling */
#define TF_RCVD_SCALE   0x00040     /* other side has requested scaling */
#define TF_REQ_TSTMP    0x00080     /* have/will request timestamps */
#define TF_RCVD_TSTMP   0x00100     /* a timestamp was received in SYN */
#define TF_SACK_PERMIT  0x00200     /* other side said I could SACK */
#define TF_NEEDSYN      0x00400     /* send SYN (implicit state) */
#define TF_NEEDFIN      0x00800     /* send FIN (implicit state) */
#define TF_NOPUSH       0x01000     /* don't push */
#define TF_MORETOCOME   0x02000     /* More data to be appended to sock */
#define TF_LQ_OVERFLOW  0x04000     /* listen queue overflow */
#define TF_LASTIDLE     0x08000     /* connection was previously idle */
#define TF_RXWIN0SENT   0x10000     /* sent a receiver win 0 in response */
#define TF_SACKRXTNOW   0x20000     /* sack feature: retransmit necessary data block */
#define TF_ACKMSEG      0x40000     /* ack many segment */


#define SEQ_LT(a,b) ((int)((a)-(b)) < 0)
#define SEQ_LEQ(a,b)    ((int)((a)-(b)) <= 0)
#define SEQ_GT(a,b) ((int)((a)-(b)) > 0)
#define SEQ_GEQ(a,b)    ((int)((a)-(b)) >= 0)

/* for modulo comparisons of timestamps */
#define TSTMP_LT(a,b)   ((int)((a)-(b)) < 0)
#define TSTMP_GEQ(a,b)  ((int)((a)-(b)) >= 0)


extern int tcp_delack_enabled;
extern int tcp_backoff[];
extern void tcp_quench(struct inpcb *inp);

extern void tcp_mtudisc(struct inpcb *inp);

/* tv = value, if value is outside (tvmin, tvmax), set tv to min or max */
#define TCPT_RANGESET(tv, value, tvmin, tvmax) do {\
    (tv) = (value);                                 \
    if ((u_long)(tv) < (u_long)(tvmin))             \
        (tv) = (tvmin);                             \
    else if ((u_long)(tv) > (u_long)(tvmax))        \
        (tv) = (tvmax);                             \
} while(0)

#define TCPTV_PERSMIN   (5 * KAL_TICKS_1_SEC)   /* retransmit persistence */
#define TCPTV_PERSMAX   (60 * KAL_TICKS_1_SEC)  /* maximum persist interval */
#define TCP_MAXRXTSHIFT     12      /* maximum retransmits */
#define TCPS_HAVEESTABLISHED(s) ((s) >= TCPS_ESTABLISHED)
#define TCPS_HAVERCVDFIN(s) ((s) >= TCPS_TIME_WAIT)


extern struct inpcbinfo tcbinfo;
extern tcp_seq tcp_iss;


extern int tcp_usr_attach(kal_uint8 profile_id, kal_int8 socket_id);
extern int tcp_usr_bind(kal_uint8 profile_id, kal_int8 socket_id, struct sockaddr *nam);
extern int tcp_usr_connect(kal_uint8 profile_id, kal_int8 socket_id, struct sockaddr *nam);
extern int tcp_usr_listen(kal_uint8 profile_id, kal_int8 socket_id, kal_uint8 max_socket_no);
extern int tcp_usr_accept(kal_uint8 profile_id, kal_int8 o_socket_id, kal_int8 n_socket_id);
extern int tcp_usr_send(kal_uint8 profile_id, kal_int8 socket_id, kal_uint8 flags, mbuf *m, struct sockaddr *nam);
extern int tcp_usr_detach(kal_int8 socket_id);
extern int tcp_usr_shutdown(kal_int8 socket_id);
extern int tcp_set_usr_option(
            kal_uint8 profile_id,
            kal_int8 socket_id,
            kal_uint16 option,
            kal_uint8 *data,
            kal_uint8 *data_length);
extern int tcp_get_usr_option(
            kal_uint8 profile_id,
            kal_int8 socket_id,
            kal_uint16 option,
            kal_uint8 *data,
            kal_uint8 *data_length);

extern void tcp_free_accept(struct tcpcb *tp);
extern void tcp_drop(struct tcpcb *tp);
extern void tcp_mss(struct tcpcb *tp, int offer);
extern int tcp_output(struct tcpcb *tp);
void tcp_close(struct tcpcb *tp);
void tcp_free(struct tcpcb *tp);
extern struct tcpcb *tcp_stop(struct tcpcb *tp);
extern tcp_seq tcp_new_isn(void);
extern void tcp_respond(
                struct tcpcb *tp,
                kal_uint8 profile_id,
                void *ipgen,
                struct tcphdr *th,
                struct mbuf *m,
                tcp_seq ack,
                tcp_seq seq,
                int flags);
extern void tcp_canceltimers(struct tcpcb *tp);
extern int tcp_mssopt(struct tcpcb *tp);

/* tcp_fun */
extern void tcp_fillheaders(struct tcpcb *tp, void *ip_ptr, void *tcp_ptr);
extern int sbspace(struct inpcb *inp);
extern struct tcptemp *tcp_maketemplate(struct tcpcb *tp);
extern struct tcpcb *tcp_newtcpcb(struct inpcb *inp);
struct rtentry *tcp_rtlookup(struct inpcb *inp);
extern void tcp_connect_fail(struct tcpcb *tp);

#ifdef TCPSACK_SUPPORT
extern void init_sack_rxtseg_queue(struct sack_rxtseg_queue *queue, u_int left, u_int right);
extern void reset_sack_rxtseg_queue(struct sack_rxtseg_queue *queue, u_int left_edge, u_int right_edge);
extern void insert_rcv_sack_block(
                struct sack_rxtseg_queue *queue,
                u_int left_edge,
                u_int right_edge,
                SACK_QUEUE_UPDATE_TYPE update_type);
extern void clean_sack_rxtseg_queue(struct sack_rxtseg_queue *queue);
#endif /* TCPSACK_SUPPORT */

#define tcp_rcvseqinit(tp)  \
    (tp)->rcv_adv = (tp)->rcv_nxt = (tp)->irs + 1

#define tcp_sendseqinit(tp)                                         \
    (tp)->snd_una = (tp)->snd_nxt = (tp)->snd_max = (tp)->snd_up =  \
        (tp)->snd_recover = (tp)->iss

/* timestamp wrap-around time */
#define TCP_PAWS_IDLE   (24 * 24 * 60 * 60)

#define TCP_RTT_SCALE       32  /* multiplier for srtt; 3 bits frac. */
#define TCP_RTT_SHIFT       5   /* shift for srtt; 3 bits frac. */
#define TCP_RTTVAR_SCALE    16  /* multiplier for rttvar; 2 bits */
#define TCP_RTTVAR_SHIFT    4   /* shift for rttvar; 2 bits */
#define TCP_DELTA_SHIFT     2   /* see tcp_input.c */

/* Scottie: srtt+4 * rttvar, see TCP/IP Illustrated Volume1, page 305 */
#define TCP_REXMTVAL(tp)                                    \
    max((tp)->t_rttmin,                                     \
        (((tp)->t_srtt >> (TCP_RTT_SHIFT - TCP_DELTA_SHIFT)) + (tp)->t_rttvar) * KAL_TICKS_500_MSEC)
	

#define TCPTV_REXMTMAX (64 * KAL_TICKS_1_SEC)  /* max allowable REXMT value */

#define TCP_ISSINCR 1250

#endif /* !_TCP_H_ */
#endif /* TCP_SUPPORT */

#endif /* __MTK_TARGET__ */

