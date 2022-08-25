
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
 * if.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Header file of if.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifdef __MTK_TARGET__

#ifndef _IF_H_
#define _IF_H_
#if 0
#ifndef _TCPIP_CONFIG_H_
/* under construction !*/
#endif /* !_TCPIP_CONFIG_H_ */
#endif
/* auto add by kw_check begin*/
#include "tcpip_config.h"
//#include "kal_nucleus_common_defs.h"
//#include "kal_non_specific_general_types.h"
#include "soc_consts.h"
#include "soc2tcpip_struct.h"
#include "cbm_consts.h"
#include "app_ltlcom.h"
#include "tcp.h"
/* auto add by kw_check end */
//#ifndef _CBM_API_H
#include "cbm_api.h"
//#endif
#include "kal_internal_api.h"
#include "kal_general_types.h"


/* WNDRV */
#define BIT(n)          ((kal_uint32) 1 << (n))


#define ETHERTYPE_IP    0x0800
#define ETHERTYPE_ARP   0x0806

#define	ARP_MSG			0xFF
#define ARP_SOCKET_ANY  (-1)


#define ARP_REFRESH_TIMER KAL_TICKS_1_MIN*5     /* 5min */
#define DNAV4_REXMT (3)                         /* RFC 4436 */

struct arphdr
{
    kal_uint16 ar_hrd;              /* format of hardware address */
#define ARPHRD_ETHER        (1)     /* ethernet hardware format */
#define ARPHRD_IEEE802      (6)     /* token-ring hardware format */
    kal_uint16 ar_pro;              /* format of protocol address */
    kal_uint8 ar_hln;               /* length of hardware address */
    kal_uint8 ar_pln;               /* length of protocol address */
    kal_uint16 ar_op;               /* one of: */
#define ARPOP_REQUEST       (1)     /* request to resolve address */
#define ARPOP_REPLY         (2)     /* response to previous request */
};

struct ether_arp
{
    struct arphdr ea_hdr;               /* fixed-size header */
    kal_uint8 arp_sha[ETHER_ADDR_LEN];  /* sender hardware address */
    kal_uint8 arp_spa[IP_ADDR_LEN];     /* sender protocol address */
    kal_uint8 arp_tha[ETHER_ADDR_LEN];  /* target hardware address */
    kal_uint8 arp_tpa[IP_ADDR_LEN];     /* target protocol address */
};
#define arp_hrd   ea_hdr.ar_hrd
#define arp_pro   ea_hdr.ar_pro
#define arp_hln   ea_hdr.ar_hln
#define arp_pln   ea_hdr.ar_pln
#define arp_op    ea_hdr.ar_op

#define ROUTER_SOLICIT  0
#define ARP_REQUESTS    1
#define GRATUITOUS_ARP  2

/**
 * Enum for caller of direction for operation on ARP cache
 */
typedef enum arp_dir
{
    ARP_OUT,    /**< For an ARP lookup resulted from sending outgoing packet, e.g., arpresolve(). */
    ARP_IN,     /**< For an ARP lookup resulted from receiving an ARP message, e.g., arp_input(). */
    ARP_IN_OUT  /**< A dummy value for callers to arplookup() when the direction is not used, e.g., arptimer(), tcpip_set_bearer(). */
} arp_dir;


/**
 * Enum for operation to ARP cache entrie(s)
 */
typedef enum arpt_op
{
    ARPT_ADD,       /* For adding an ARP entry in ARP cache. */
    ARPT_DELEXP,    /* For deleting all expired ARP entry in ARP cache. */
    ARPT_CLEAR,     /* For clearing entire ARP cache. */
    ARPT_MOVE       /* For move an entry between separated ARP tables. Currently only move from IN to OUT. */
} arpt_op;


struct arpt
{
    kal_uint32  prot_addr;      /* Protocol address of next hop, in host byte order */
    kal_uint32  exp_time;       /* expiration time in seconds */
    kal_uint8   hw_addr[ETHER_ADDR_LEN];    /* MAC address of next hop, in network byte order */
    kal_uint8   tos;
    kal_uint8   asked;          /* times of asked, recorded for flooding avoidance */
    kal_uint8   profile_id;     /* recorded for sending the held packet */
    int     socket_id;          /* socket used in m_free_ul() to free held packet */
    mbuf    *hold;
};

struct arpsnd
{
    kal_int8    snd_type;       /*gratuitous or all_hosts or rtr_solic*/
    kal_uint8   profile_id;     /* recorded for sending the held packet */
};

#define NUM_MAX_HOLD    (3)
#define NUM_ARP_OUT     (5)
#define NUM_ARP_IN      (3)
#define NUM_ARP_ENTRY   (NUM_ARP_OUT+NUM_ARP_IN)
#define NUM_ARP(dir)    ((dir)==ARP_OUT ? NUM_ARP_OUT : NUM_ARP_IN)

#define ARP_LBOUND(dir)    ((dir)==ARP_OUT ? 0 : NUM_ARP_OUT)
#define ARP_UBOUND(dir)    ((dir)==ARP_OUT ? NUM_ARP_OUT : NUM_ARP_ENTRY)
#define ARP_WITHIN_OUT(i)  (0<=(i) && (i)<NUM_ARP_OUT)
#define ARP_WITHIN_IN(i)   (NUM_ARP_OUT<=(i) && (i)<NUM_ARP_ENTRY)
#define ARP_DIR(i)         (ARP_WITHIN_IN(i) ? ARP_IN : ARP_OUT)


extern const kal_uint8 etherbroadcastaddr[];
extern const kal_uint8 etherallzeroes[];


extern kal_uint8 g_temp_context_id;


extern void if_input(cbm_bearer_enum bearer_id, peer_buff_struct *peer_buff_ptr, local_para_struct *local_para_ptr);
extern void if_output(
                kal_uint8 profile_id,
                mbuf *m,
                kal_uint32 dest_addr,
                u_char *target_mac,
                kal_uint16 protocol,
                int socket_id,
                u_char tos);


#ifdef __WIFI_SUPPORT__
typedef enum
{
    PWR_SAVING,
    PWR_WASTING
} pwr_state_enum;

#define PS_OCTETS   ((MAX_IP_SOCKET_NUM+7)/8)

extern pwr_state_enum      cur_state;      /* ZI default to 0, i.e., PWR_SAVING; */
extern kal_uint8           wifi_ps_handle; /* WiFi power saving handle */
extern kal_uint8           pwr_wasting[];     /* ;-) */
#endif /* __WIFI_SUPPORT__ */

extern kal_bool tcpip_wifi_arpresolve(kal_uint8 profile_id,
                           mbuf *m,
                           kal_uint32 dest_addr,
                           kal_uint8 *desten,
                           int socket_id,
                           u_char tos);
extern void tcpip_wifi_arprequest(kal_uint8 profile_id, kal_uint32 target_ip, const kal_uint8 *target_mac);
extern void tcpip_wifi_arp_input(cbm_bearer_enum bearer_id, mbuf *m);

extern kal_int8 tcpip_wifi_arplookup(kal_uint32 nexthop, kal_bool create, /*enum*/ arp_dir dir);

extern void tcpip_wifi_get_arp_hw_addr(kal_int8 id, kal_uint8 *tcpip_hw_addr);
extern void tcpip_wifi_send_arp(struct arpsnd *snd);
extern void tcpip_wif_set_arp_conflict_mac(kal_int32 value);
extern void tcpip_wif_set_arp_last_conflict_time(kal_int32 value);
extern void tcpip_wifi_pwr_saving_off(kal_uint8 s);
extern void tcpip_wifi_pwr_saving_on(kal_uint8 s);
extern void tcpip_wifi_arp_freehold(kal_int8 socket_id);
extern kal_int8 tcpip_wifi_arp_rtrequest(/*enum*/ arpt_op req, kal_uint32 ip_addr,
                    /*enum*/ arp_dir dir, kal_bool perm);

///nat
extern void tcpip_wifi_init_tcpip_nat(void);
extern kal_bool tcpip_wifi_nat_ip_packet_input(struct mbuf *m, kal_int8 tcpip_sap_id);
extern void tcpip_wifi_nat_ip_packet_output(struct mbuf *m, kal_int8 tcpip_sap_id);
extern kal_uint32*  tcpip_wifi_get_nat_gprs_ip_addr_p();
extern kal_uint32  tcpip_wifi_get_nat_gprs_ip_addr();
extern void tcpip_wifi_set_nat_gprs_ip_addr(kal_uint32 nat_gprs_ip_addr_t);
extern void tcpip_wifi_set_nat_local_gprs_addr(kal_uint32 nat_local_gprs_addr_t);
extern kal_uint32  tcpip_wifi_get_nat_out_context_id();
extern void tcpip_wifi_set_nat_out_context_id(kal_uint32 nat_out_context_id_t);
extern kal_int8  tcpip_wifi_get_nat_out_profile_id();
extern void tcpip_wifi_set_nat_out_profile_id(kal_uint32 nat_out_profile_id_t);
extern kal_uint32  tcpip_wifi_get_nat_wifi_ip_addr_netmask();
extern void tcpip_wifi_set_nat_wifi_ip_addr_netmask(kal_uint32 nat_wifi_ip_addr_netmask_t);
extern kal_uint32*  tcpip_wifi_get_nat_wifi_ip_addr_netmask_p();
extern kal_uint32  tcpip_wifi_get_nat_wifi_ip_addr();
extern void tcpip_wifi_set_nat_wifi_ip_addr(kal_uint32 nat_wifi_ip_addr_t);
extern kal_uint32*  tcpip_wifi_get_nat_wifi_ip_addr_p();
extern kal_uint16*  tcpip_wifi_get_local_tcpip_port_used();
extern void tcpip_wifi_set_nat_send_data_flag(kal_uint32 nat_send_data_flag_t);
extern void tcpip_wifi_set_nat_send_data_wifi_flag(kal_uint32 nat_send_data_wifi_flag_t);
extern kal_int8  tcpip_wifi_get_nat_in_profile_id();
extern void tcpip_wifi_set_nat_in_profile_id(kal_int8 nat_in_profile_id_t);
#if 0
#ifdef _ARP_
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef ARP_LOG_HISTORY
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* ARP_LOG_HISTORY */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __WIFI_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __WIFI_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* _ARP_ */
/* under construction !*/
#endif

extern kal_bool is_local(kal_uint32 local, kal_uint32 dest, kal_uint32 mask);
extern kal_uint32 next_hop(kal_uint8 profile_id, kal_uint32 dest);
extern void octets2int(kal_uint8 *expr, kal_uint32 *ip);
extern void int2octets(kal_uint32 ip, kal_uint8 *expr);
extern char *ip_sprintf(kal_uint32 ip);
extern kal_char *ether_sprintf(kal_uint8 *ap);

#ifdef ARP_UT
extern void print_arpt(void);
#endif /* ARP_UT */

#ifdef ARP_UT
#define UT_PRINT_ARP()     print_arpt()
#else /* !ARP_UT */
#define UT_PRINT_ARP()  /* empty */
#endif /* !ARP_UT */


void pwr_saving_on(kal_uint8 s);
void pwr_saving_off(kal_uint8 s);

extern void print_wifi_info(void);

int bearer_to_tcpip_sap_id(kal_int8 bearer);

kal_uint8 bearer_to_tcpip_profile_id(cbm_bearer_enum bearer_id);
#endif /* !_IF_H_ */

#endif /* __MTK_TARGET__ */

