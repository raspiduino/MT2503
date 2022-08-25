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
 * APP2SOC_STRUCT.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common struct of Applications and SOC.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _APP2SOC_STRUCT_H
#define _APP2SOC_STRUCT_H

#include "kal_general_types.h"
#ifndef _SOC_CONSTS_H
#include "soc_consts.h"
#endif /* !_SOC_CONSTS_H */

/*
 * <GROUP  Macro_Consts>
 * 
 * Max DNS address entry for soc_gethostbyname 
 */
#define SOC_MAX_A_ENTRY              (5)
/*
 * <GROUP  Macro_Consts>
 * 
 * Max DNS name entry for soc_gethostbyaddr 
 */
#define SOC_MAX_PTR_ENTRY            (1)
/*
 * <GROUP  Macro_Consts>
 * 
 * Max DNS service entry for soc_gethostbysrv 
 */
#define SOC_MAX_SRV_ENTRY            (2)
/*
 * <GROUP  Macro_Consts>
 * 
 * Max DNS NAPTR entry for soc_gethostbynaptr 
 */
#define SOC_MAX_NAPTR_ENTRY          (3)
/*
 * <GROUP  Macro_Consts>
 * 
 * Max DNS name length 
 */
#define SOC_MAX_DNS_NAME_LEN         (255)
/*
 * <GROUP  Macro_Consts>
 * 
 * Max DNS NAPTR service length 
 */
#define SOC_MAX_NAPTR_SRV_LEN        (70)
/*
 * <GROUP  Macro_Consts>
 * 
 * Max DNS NAPTR flag length 
 */
#define SOC_MAX_NAPTR_FLAGS_LEN      (3)
/*
 * <GROUP  Macro_Consts>
 * 
 * MAX NAPTR regular expression length 
 */
#define SOC_MAX_NAPTR_REGEXP_LEN     (100)


/* The structure for DNS A RR entry */
typedef struct
{
    kal_uint8 address[4];   /* resolved IP address for queried domain name */
} soc_dns_a_struct;


/* The structure for DNS PTR RR entry */
typedef struct
{
    kal_char ptrname[SOC_MAX_DNS_NAME_LEN];    /* resolved domain name
                                                 * for specific IP address */
} soc_dns_ptr_struct;


/* The structure for DNS SRV RR entry */
typedef struct
{
    kal_uint16  priority;   /* the client MUST attempt to use target host 
                             * with the lowest-numbered priority. */
    kal_uint16  weight;     /* relative weight for entries with the same
                             * priority.
                             * Larger weights SHOULD be given a proportionately
                             * higher probability of being selected. */
    kal_uint16  port;       /* port number */
    kal_char    target[SOC_MAX_DNS_NAME_LEN];  /* service. null terminated */

} soc_dns_srv_struct;


/* The structure for DNS NAPTR RR entry */
typedef struct
{
    kal_uint16  order;                              /* order */
    kal_uint16  pref;                              /* preference */
    kal_char    flag;     /* flags, RFC 3403, some chars */
    kal_char    flags[SOC_MAX_NAPTR_FLAGS_LEN];     /* flags, RFC 3403, some chars */
    kal_char    service[SOC_MAX_NAPTR_SRV_LEN];    /* null terminated */
    kal_char    regexp[SOC_MAX_NAPTR_REGEXP_LEN];  /* regular expression, null terminated */
    kal_char    replacement[SOC_MAX_DNS_NAME_LEN]; /* null terminated */
} soc_dns_naptr_struct;


/* The structure for application notification indication.  
 * Notification to application for some events, e.g., socket is readable, socket is connected,
 * etc. In case of TCP half-write close by peer, event_type will be SOC_CLOSE and error_cause will 
 * be SOC_CONNRESET. 
 * P.S. if application wants to accept this primitive, it should run in its own task 
 * instead of a task containing multiple applications, such as MMI. However, 
 * if application wants to run in the task of MMI and also wants to receive this primitive, 
 * it should use the "framework multiple protocol event handler" (since 08B). 
 * Otherwise, the primitive may be received by other applications running in the same task as you.
 */
typedef struct
{
   kal_uint8       ref_count;
   kal_uint16      msg_len;	
   kal_int8        socket_id;    /* socket ID */
   soc_event_enum  event_type;   /* soc_event_enum */
   kal_bool        result;       /* notification result. KAL_TRUE: success, KAL_FALSE: error */
   soc_error_enum  error_cause;  /* used only when EVENT is close/connect */
   kal_int32       detail_cause; /* refer to ps_cause_enum if error_cause is
                                  * SOC_BEARER_FAIL */
} app_soc_notify_ind_struct;

/* Notification to application the result of DNS address query (soc_gethostbyname).
 * P.S. if application wants to accept this primitive, it should run in 
 * its own task instead of a task containing multiple applications, 
 * such as MMI. However, if application wants to run in the task of MMI 
 * and also wants to receive this primitive, it should use the 
 * "framework multiple protocol event handler" (since 08B). 
 * Otherwise, the primitive may be received by other 
 * applications running in the same task as you.
 */
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_int32	request_id; /* request id */
    kal_uint32  account_id; /* network account id */
    kal_int32   detail_cause;  /* refer to ps_cause_enum if error_cause
                                * is SOC_BEARER_FAIL */
    soc_dns_a_struct entry[SOC_MAX_A_ENTRY]; /* entries */
    
    kal_bool    result;     /* the result of soc_gethostbyname */
    kal_uint8   access_id;  /* access id */
    
    kal_uint8	addr_len;   /* the first record in entry,  */
    kal_uint8	addr[16];   /* for backward compatibility */
    kal_uint8   num_entry;  /* number of entries. field of num_entry and entry are made 
                               to carry multiple answers for one domain name mapping to 
                               multiple IP addresses. */
    kal_int8    error_cause;   /* bearer fail */

} app_soc_get_host_by_name_ind_struct;


/* Notification to application the result of DNS name query (soc_gethostbyaddr).
 * P.S. if application wants to accept this primitive, it should run in 
 * its own task instead of a task containing multiple applications, such as MMI. However, 
 * if application wants to run in the task of MMI and also wants to receive this primitive, 
 * it should use the "framework multiple protocol event handler" (since 08B). 
 * Otherwise, the primitive may be received by other applications running in the same task as you.
 */
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    
    kal_int32   request_id;                     /* request id */
    kal_uint32  account_id;                     /* network account id */
    kal_int32   detail_cause;  /* refer to ps_cause_enum if error_cause
                                * is SOC_BEARER_FAIL */
    soc_dns_ptr_struct entry[SOC_MAX_PTR_ENTRY]; /* entries */
    
    kal_bool	result;                         /* the result of soc_gethostbyaddr */
    kal_uint8   access_id;                      /* access id */
    kal_char    name[SOC_MAX_DNS_NAME_LEN];     /* DNS name. null terminated */
    kal_uint8   num_entry;                      /* number of entry */  
    kal_int8    error_cause;   /* bearer fail */
} app_soc_get_host_by_addr_ind_struct;


/* Notification to application the result of DNS SRV RR query (soc_gethostbysrv).
 * P.S. if application wants to accept this primitive, it should run in 
 * its own task instead of a task containing multiple applications, 
 * such as MMI. However, if application wants to run in the task of MMI and also 
 * wants to receive this primitive, it should use the 
 * "framework multiple protocol event handler" (since 08B). 
 * Otherwise, the primitive may be received by other 
 * applications running in the same task as you.
 */
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;

    kal_int32   request_id;     /* request id */
    kal_uint32  account_id;     /* network account id */
    kal_int32   detail_cause;  /* refer to ps_cause_enum if error_cause
                                * is SOC_BEARER_FAIL */
    
    soc_dns_srv_struct entry[SOC_MAX_SRV_ENTRY]; /* entries */
    kal_uint8   access_id;      /* access id */
    kal_uint8   num_entry;      /* number of entry */
    kal_int8    error_cause;   /* bearer fail */
    kal_bool    result;         /* the result of soc_gethostbysrv */
} app_soc_get_host_by_srv_ind_struct;


/* Notification to application the result of DNS NAPTR RR query (soc_gethostbynaptr).
 * P.S. if application wants to accept this primitive, it should run in 
 * its own task instead of a task containing multiple applications, 
 * such as MMI. However, if application wants to run in the task of MMI and also 
 * wants to receive this primitive, it should use the 
 * "framework multiple protocol event handler" (since 08B). 
 * Otherwise, the primitive may be received by other 
 * applications running in the same task as you.
 */
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;

    kal_uint32  account_id;  /* network account id */
    kal_int32   request_id;  /* request id */
    kal_int32   detail_cause;  /* refer to ps_cause_enum if error_cause
                                * is SOC_BEARER_FAIL */
    soc_dns_naptr_struct entry[SOC_MAX_NAPTR_ENTRY]; /* entries */                     
    kal_uint8   access_id;   /* access id */
    kal_uint8   num_entry;   /* number of entry */
    kal_int8    error_cause;   /* bearer fail */
    kal_bool    result;      /* the result of soc_gethostbynaptr */
} app_soc_get_host_by_naptr_ind_struct;

/* DOM-NOT_FOR_SDK-BEGIN */
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;	
    kal_uint32  account_id; /* 0xff: all bearers */
    kal_uint8   qos_profile_id;
} app_soc_deactivate_req_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;	
    kal_uint32  account_id;
} app_soc_activate_req_struct;

/* The decrypted ssl output data */
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint32  ret; /* read or write data size */
    kal_uint32  len; /* buffer length */
    kal_bool    mf;
} app_ssl_data_output_msg_struct;

/* The decrypted ssl input data */
typedef app_ssl_data_output_msg_struct app_ssl_data_input_msg_struct;

/* socket downlink filter structure */
typedef struct
{
    kal_uint32  ipsec_spi;            /* IPSec */
    kal_uint32  flow_label;           /* IPv6 */
    kal_uint16  remote_start_port;    /* inclusive */
    kal_uint16  remote_end_port;      /* inclusive */
    kal_uint16  local_start_port;
    kal_uint16  local_end_port;
    
    kal_uint8   pfi;                  /* filter id */
    kal_uint8   epi;                  /* evaluation precedence */
    kal_uint8   protocol;             /* TCP, UDP, ... */
    kal_uint8   remote_addr[4]; 
    kal_uint8   remote_addr_prefix_len;     /* 0..32 */
    kal_uint8   tos_mask;             /* set to 0 if not required to exam ToS */
    kal_uint8   tos;
} soc_dl_filter_struct;
/* DOM-NOT_FOR_SDK-END */

#endif /* !_APP2SOC_STRUCT_H */ 

