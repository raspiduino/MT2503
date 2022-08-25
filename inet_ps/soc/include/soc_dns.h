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
 * soc_dns.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains constant/macro/enum/struct for DNS and 
 *   function prototypes of soc_dns.c.
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

#ifndef _SOC_DNS_H
#define _SOC_DNS_H

#include "soc_feature.h"
#include "soc_defs.h"
#include "kal_general_types.h"
#include "soc_consts.h"
#include "stack_config.h"
#include "app2soc_struct.h"

#define DNS_PORT            (53)
#define DNS_ADDR_LEN        (4)
#define DNS_MAX_CACHE       (5) /* max entry of DNS response */
#ifdef DNS_NEG_CACHE
#define DNS_MAX_NEG_CACHE   (3) /* max entry of negative DNS response */
#define SOC_MAX_SOA_ENTRY   (1)
#endif
#define DNS_MAX_RETRY       (3) /* max retry attempt for each server */
#define DNS_MAX_QUERY       (2) /* max pending DNS query */
#define DNS_MAX_PDU         (500)
#define DNS_MAX_NAME        (255)
#define DNS_MAX_UDP_MSG     (512)
#define DNS_MAX_LABEL       (63)
#define DNS_MAX_TTL         (24 * 60 * 60)
#define DNS_MAX_NEG_TTL     (3 * 60 * 60)


#define DNS_PTR_MASK        (0xc0)      /* a compressed label */
#define IN_ADDR_ARPA_LEN    (12)        /* strlen("IN-ADDR.ARPA") */
#define IN_ADDR_ARPA        "IN-ADDR.ARPA"

#define DNS_CNTX(_X_)       (SOC_CNTX(dns._X_))

typedef kal_int8 dns_result;

#define DNS_CLASS_IN          (1)       /* Internet Class */
#define DNS_DEFAULT_FLAG      (0x0100)  /* flag in Header of query */
#define DNS_OPCODE_STD_QUERY  (0)

/* Error cause */
#define DNS_OK                   (0)
#define DNS_FOUND                (1)    /* IP found in cache */
#define DNS_WAIT_RESPONSE        (2)    /* Wait DNS response from network */
#ifdef DNS_NEG_CACHE
#define DNS_NEG_FOUND            (3)
#endif
#define DNS_ERROR                (-1)
#define DNS_PARAMETER_ERROR      (-2)   /* Parameter error, wrong DNS name */
#define DNS_LIMIT_RESOURCE       (-3)   /* Run out of DNS resources */
#define DNS_SOCKET_ERROR         (-4)   /* Socket error, eg, sendto */
#define DNS_NO_DNS_SERVER        (-5)
#define DNS_NO_DUP_PENDING_REQ   (-6)
#define DNS_NAMETOOLONG          (-7)
#define DNS_PKTTOOLARGE          (-8)



/* server addr for secondary entry if not given */
#define DNS_AUX_SERVER_2   "217.115.138.24"    /* OpenNIC */
#define DNS_AUX_SERVER_3   "199.166.31.3"      /* QUASAR */
#define DNS_AUX_SERVER_4   "66.93.87.2"        /* SpeakEasy */
#define DNS_AUX_SERVER_5   "204.117.214.10"    /* SprintLink */

typedef enum
{
    DNS_FIND_EXIST_CACHE = 0,
    DNS_FIND_FREE_CACHE,
    DNS_REPLACE_CACHE
} dns_find_cache_enum;

typedef enum
{
    DNS_TYPE_A      = 1,    /* a host address */
    DNS_TYPE_NS     = 2,    /* an authoritative name server */
    DNS_TYPE_CNAME  = 5,    /* the canonical name for an alias */
    DNS_TYPE_SOA    = 6,    /* marks the start of a zone of authority */
    DNS_TYPE_PTR    = 12,   /* domain name pointer */
    DNS_TYPE_SRV    = 33,   /* service */
    DNS_TYPE_NAPTR  = 35,   /* naming authority pointer */
    DNS_TYPE_UNSUPPORTED
} dns_type_enum;


typedef enum
{
    DNS_IS_QUERY = 0,
    DNS_IS_RESPONSE = 1
} dns_qr_enum;


typedef enum
{
    DNS_RCODE_NO_ERROR = 0,
    DNS_RCODE_FORMAT_ERROR = 1,
    DNS_RCODE_SERVER_FAILURE = 2,
    DNS_RCODE_NAME_ERROR = 3,
    DNS_RCODE_NOT_IMPLEMENT = 4,
    DNS_RCODE_REFUSED = 5,
    DNS_RCODE_RESERVED
} dns_rcode_enum;

/* DNS_REF_ACCT has the higher priority than DNS_REF_GLOBAL */
typedef enum
{
    DNS_REF_GLOBAL = 0x01,
    DNS_REF_ACCT = 0x10
} dns_ref_enum;

/* dns server address */
typedef enum
{
    DNS_PRIMARY_SERVER   = SOC_PRI_DNS_SRV_ADDR,   
    DNS_SECONDARY_SERVER = SOC_SEC_DNS_SRV_ADDR,
#ifdef PUBLIC_DNS_SREVER
    DNS_3RD_SERVER = 2,
    DNS_4TH_SERVER = 3,
    DNS_5TH_SERVER = 4,
#endif /* PUBLIC_DNS_SREVER */
    DNS_MAX_SERVER              /* max candidate DNS servers */
} dns_server_enum;

#ifdef DNS_NEG_CACHE
/* The structure for DNS SOA RR entry */
typedef struct
{
    kal_uint32 serial;                      /* version number */
    kal_uint32 refresh;                     /* zone refresh interval */
    kal_uint32 retry;                       /* a failed refresh retry time */
    kal_uint32 expire;                      /* zone authority time interval */
    kal_uint32 minimum;                     /* minumum TTL field of this zone */
} soc_dns_soa_struct;
#endif



typedef struct
{
    kal_uint8 no_name;
    kal_uint8 *name;
    kal_uint16 type;
    kal_uint16 classes;
} dns_basic_sec_struct;


typedef struct
{
    kal_uint32 id     :16;

    kal_uint32 qr     : 1;
    kal_uint32 opcode : 4;
    kal_uint32 aa     : 1;
    kal_uint32 tc     : 1;
    kal_uint32 rd     : 1;

    kal_uint32 ra     : 1;
    kal_uint32 z      : 3;
    kal_uint32 rcode  : 4;

    kal_uint16 qdcount;
    kal_uint16 ancount;
    kal_uint16 nscount;
    kal_uint16 arcount;
} dns_header_sec_struct;


typedef struct
{
    dns_basic_sec_struct basic;
    kal_uint32 ttl;
    kal_uint16 rdlength;
    kal_uint8 *rdata;
} dns_answer_sec_struct;


typedef struct
{
    /* header section */
    dns_header_sec_struct hdr;

    /* question */
    dns_basic_sec_struct q;

    /* answer */
    dns_answer_sec_struct a;

#ifdef DNS_NEG_CACHE
    /* authority */
    dns_answer_sec_struct au;
#endif
} dns_query_struct;


typedef struct
{
    kal_uint8 pdu[DNS_MAX_PDU];
    kal_uint16 len;
} dns_query;


/*
 * we will try primary server first, if we got no response, we try secondary server
 * if we still got no response, we try primary server again ( retransmit timeout 
 * value is double )
 */
typedef struct
{
    kal_uint32 xid;            /* transaction id */
    kal_uint32   nw_acc_id;
    kal_uint32  account_id[DNS_MAX_DUP_QUERY];
    kal_uint32  request_id[DNS_MAX_DUP_QUERY];
    
    kal_char   *name;
    dns_query  *query;         /* query for retransmission */

    module_type mod_id[DNS_MAX_DUP_QUERY];
    kal_uint8  id;
    kal_uint8  retry_cnt;
    kal_uint8  server_index;   /* 0: primary, 1: secondary */
    kal_int8   s;              /* socket id */
    kal_uint8  type;           /* dns_type_enum */
    kal_bool   is_timer_running;
    kal_uint8  ip_addr[DNS_ADDR_LEN];

    /* Embedded in dns notification to application */
    kal_uint8   access_id[DNS_MAX_DUP_QUERY];
    kal_uint8   ap_id[DNS_MAX_DUP_QUERY];
} dns_transaction_struct;


typedef struct
{
    kal_uint32 ttl[SOC_MAX_A_ENTRY];
    soc_dns_a_struct entry[SOC_MAX_A_ENTRY];
    kal_uint8 num_entry;
} dns_a_struct;


typedef struct
{
    kal_uint32 ttl[SOC_MAX_PTR_ENTRY];
    soc_dns_ptr_struct entry[SOC_MAX_PTR_ENTRY];
    kal_uint8 num_entry;
} dns_ptr_struct;


typedef struct
{
    kal_uint32 ttl[SOC_MAX_SRV_ENTRY];
    soc_dns_srv_struct entry[SOC_MAX_SRV_ENTRY];
    kal_uint8 num_entry;
} dns_srv_struct;


typedef struct
{
    kal_uint32 ttl[SOC_MAX_NAPTR_ENTRY];
    soc_dns_naptr_struct entry[SOC_MAX_NAPTR_ENTRY];
    kal_uint8 num_entry;
} dns_naptr_struct;

#ifdef DNS_NEG_CACHE
typedef struct
{
    kal_uint32 ttl[SOC_MAX_SOA_ENTRY];
    soc_dns_soa_struct entry[SOC_MAX_SOA_ENTRY];
    kal_uint8 num_entry;
} dns_soa_struct;
#endif



#if defined(DNS_CFG_CACHE) || defined(DNS_NEG_CACHE)
typedef struct
{
    kal_uint32 last_modified;   /* last modified time */
    kal_uint32 expired;         /* expired time */
    kal_char *name;                     /* PTR */
    soc_dns_a_struct *a_rr;             /* A, multiple entries */
    soc_dns_srv_struct *srv_rr;         /* SRV */
    soc_dns_naptr_struct *naptr_rr;     /* NAPTR */
    
    kal_uint8 type;             /* dns_type_enum */
    kal_uint8 error;            /* error code for negative cache */
    kal_uint8 entries;          /* number of cached RRs */
    kal_uint8 ip_addr[DNS_ADDR_LEN];    /* A, backward compatible */
#ifdef DNS_FLUSH_CACHE 
    kal_uint8 dns_server[DNS_ADDR_LEN];
#endif /* DNS_FLUSH_CACHE */
} dns_cache_struct;
#endif /* DNS_CFG_CACHE or DNS_NEG_CACHE */

typedef struct
{
    kal_uint32 xid; /* transaction id, increment by one for each query */
    dns_transaction_struct *pending_req[DNS_MAX_QUERY];

#ifdef DNS_CFG_CACHE
    dns_cache_struct *cache[DNS_MAX_CACHE];
#endif /* DNS_CFG_CACHE */
#ifdef DNS_NEG_CACHE
    dns_cache_struct *neg_cache[DNS_MAX_NEG_CACHE];
#endif
} dns_context_struct;


/* ===================================
    function prototypes 
   =================================== */
extern
void soc_dns_ind(kal_bool result,
                 kal_uint8 *ip_addr,
                 kal_uint8 addr_len,
                 dns_a_struct *a,
                 dns_transaction_struct *trans,
                 kal_int8 error_cause,
                 kal_int32 detail_cause);

extern
void soc_dns_name_ind(kal_bool result,
                      kal_char *name,
                      dns_ptr_struct *ptr,
                      dns_transaction_struct *trans,
                      kal_int8 error_cause,
                      kal_int32 detail_cause);

extern
void soc_dns_srv_ind(kal_bool result,
                     dns_srv_struct *srv,
                     dns_transaction_struct *trans,
                     kal_int8 error_cause,
                     kal_int32 detail_cause);

extern
void soc_dns_naptr_ind(kal_bool result,
                       dns_naptr_struct *naptr,
                       dns_transaction_struct *trans,
                       kal_int8 error_cause,
                       kal_int32 detail_cause);

extern
dns_result dns_get_dns_rr(dns_type_enum type,
                          kal_char *name,
                          void *entry,
                          kal_uint8 in_entry_num,
                          kal_uint8 *out_entry_num,
                          module_type mod_id,
                          kal_uint32 request_id,
                          kal_uint8 access_id,
                          kal_uint32 nwk_account_id,
                          kal_bool is_blocking);

extern
dns_result dns_get_ip_by_name(kal_char *name,
                              kal_uint8 *ip_addr,
                              module_type mod_id,
                              kal_uint32 request_id,
                              kal_uint8 access_id,
                              kal_bool is_blocking,
                              kal_uint32 nwk_account_id,
                              kal_uint8 in_entry_num,
                              kal_uint8 *out_entry_num);

extern
dns_result dns_get_name_by_ip(kal_char *domain_name,
                              kal_uint32 *domain_name_len,
                              const kal_uint8 *ip_addr,
                              module_type mod_id,
                              kal_uint32 request_id,
                              kal_uint8 access_id,
                              kal_bool is_blocking,
                              kal_uint32 nwk_account_id);

extern void dns_recv_rsp_from_server(dns_transaction_struct *trans);

extern
dns_result dns_send_query_to_server(dns_transaction_struct *trans,
                                    module_type mod_id,
                                    kal_bool is_blocking,
                                    kal_bool is_so_locked,
                                    kal_uint32 nw_acc_id,
                                    kal_bool run_on_soc);

extern void dns_free_transaction(dns_transaction_struct *t);

extern void dns_query_retry(dns_transaction_struct *trans);

extern void soc_dns_handler(void *msg_ptr);

extern void dns_init(void);

extern void dns_start_timer(dns_transaction_struct *trans);

extern void dns_stop_timer(dns_transaction_struct *trans);

extern void soc_dns_adm_init(void);

extern void *soc_dns_adm_calloc(kal_int32 size);

void soc_dns_adm_free(void *ptr);

extern
dns_result dns_abort_query(kal_bool by_mod_id,
                           module_type mod_id,
                           kal_bool by_ap_id,
                           kal_uint8 ap_id,
                           kal_bool by_request_id,
                           kal_uint32 request_id,
                           kal_bool by_access_id,
                           kal_uint8 access_id,
                           kal_bool by_nwk_account_id,
                           kal_uint32 nwk_account_id);

#endif /* !_SOC_DNS_H */

