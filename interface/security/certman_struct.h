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
 *    certman_struct.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    Certificate Manager exported structures and constant definitions
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#ifndef CERTMAN_STRUCT_H
#define CERTMAN_STRUCT_H

#ifndef __APP_DATETIME_H__
#include "app_datetime.h"
#endif

#include "certman_defs.h"

#if 0
#ifndef CERTMAN_INT_STRUCT_H
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* CERTMAN_INT_STRUCT_H */
#endif


/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  certman_fp_pwd_cb
 * DESCRIPTION
 *  This callback function type is to copy the password to decrypt the output 
 *  private key data file from certman.
 *  NOTE : 1. Caller need to prepare a such callback function to backup the password.
 *            Because the password won't be saved in Certman.
 *         2. The callback implementation must be responsible for copying the content 
 *            in "pwd" onto its internal buffer.
 *         3. CERTMAN_PKPWD_SIZE = private key protection password
 * PARAMETERS
 *  trans_id    :   [IN]    Transaction ID for applicaion.
 *  cert_id     :   [IN]    Associated certificate ID.
 *  *pwd        :   [IN]    password data
 *  size        :   [IN]    password data length
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*certman_fp_pwd_cb)(
	                kal_uint32 trans_id,
	                kal_uint32 cert_id,
	                const kal_uint8 *pwd,
	                kal_uint32 size);

/* This structure defines the display name string array */
typedef struct
{
    kal_uint8           *names[CERTMAN_NAMETYPE_SIZE];     /* array indexed by certman_name_type_enum, each element is a zero-terminated string. */
    certman_dcs_enum    dcs[CERTMAN_NAMETYPE_SIZE];        /* specify the encoding type of the corresponding name string in "names" array */
} certman_disp_name_struct;

/* This sturct defines the display attributes of one certificate.
   User of this object must be responsible for releasing the memories held within by certman_cert_display_content_free */
typedef struct
{
    certman_certtype_enum       cert_type;                  /* certificate type (certman_certtype_enum) */
    kal_uint8                   label[CERTMAN_LABEL_SIZE];  /* certificate label */
    certman_dcs_enum            dcs_label;                  /* the dcs of label */
    kal_uint32                  version;                    /* certificate version, 3 means version 3.. etc.  */
    kal_uint32                  serial_size;                /* number of valid bytes in "serial" array */
    kal_uint8                   serial[CERTMAN_SERIAL_SIZE];/* this is not a string, this array must be treated as an array of octets forming the serial number long integer */
    certman_disp_name_struct    issuer;                     /* issuer name string */
    certman_disp_name_struct    subject;                    /* subject name string */
    applib_time_struct          valid_from;                 /* valid not before information */
    applib_time_struct          valid_until;                /* valid not after information */
    kal_uint8                   fngrprt_sha1[CERTMAN_SHA1_SIZE];    /* this is not a string, this array contains CERTMAN_SHA1_SIZE octets for the certificate's finger print */
    certman_signature_alg       sigalg;                     /* associated signature algorithm (certman_signature_alg) */
} certman_cert_display_struct;

/* This sturct defines the parsed information. */
typedef struct
{
    kal_uint32  cert_ref_ids[CERTMAN_NUM_PARSED_CERT];  /* reference IDs of this parse context certs */
    kal_uint16  cert_count;                             /* the total numbers of certificates of this parse context */
} certman_parsed_info_struct;

/* This struct defines the returned detailed certificate attributes */
typedef struct
{
    certman_cert_display_struct     cert;           /* the certificate display data */
    kal_uint8                       not_validated;  /* valid information, 1 means validated */
    kal_uint8                       cert_exists;    /* certificate already exists in Certman's database, must not allow user to import this certificate again. */
    certman_cert_group_enum         cert_group;     /* certificate group (certman_cert_group_enum) */
    kal_uint8                       cert_expired;   /* set to 1 when this certificate has expired, MMI should warn user before importing. */
    kal_uint32                      key_purposes;   /* certificate key purpose */
} certman_parsed_data_struct;

/* This structure defines the information about a certificate that is useful on our device. */
typedef struct
{
    kal_uint32                  id;                 /* unique certificate ID assigned by Certman */
    kal_uint8                   label[CERTMAN_LABEL_SIZE]; /* unique certificate label specified by user */
    certman_dcs_enum            dcs;                /* label string dcs */
    kal_uint32                  properties;         /* an OR'd result of values from certman_property_enum */
    certman_cert_group_enum     group;              /* certman_cert_group_enum */
    certman_domain_enum         domain;             /* certman_domain_enum */
    certman_storage_enum        storage;            /* certman_storage_enum */
    kal_uint32                  key_purpose_all;        /* an OR'd result of values from certman_keypurpose_enum */
    kal_uint32                  key_purpose_allowed;    /* an OR'd result of values from certman_keypurpose_enum used to check against key usage purposes provided by certificate retriever */
    applib_time_struct          not_before;
    applib_time_struct          not_after;
} certman_cert_list_elem_struct;

/* This structure is designed for certman validation input certificate object array */
typedef struct
{
    const void *data;       /* certificate data */
    kal_uint32 size;        /* certificate data length */
    kal_uint8 trusted;      /* trusted flag */
} certman_cert_data_struct;


/*************************************************************************
 * LOCAL PARAMETERS -- PARSE
 ************************************************************************/

/* This structure defines the certman parse begin request */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 trans_id;            /* application transaction ID */
    kal_uint32 pregid;              /* password registered ID for certman to forbid password leaked from primitive */
    certman_encoding_enum encoding; /* specified encoding scheme of the parse file */
    kal_wchar *filename;            /* specified file name */
} certman_parse_begin_req_struct;

/* This structure defines the certman parse begin confirm */
typedef struct
{
    kal_uint8                   ref_count;
    kal_uint16                  msg_len;
    kal_uint32                  trans_id;   /* application transaction ID */
    kal_uint16                  job_id;     /* registered certman job ID */
    kal_uint16                  num_private_key;    /* the number of private keys found in parsed file */
    certman_parsed_info_struct  parsed_info[CERTMAN_PARSED_CERTGRP_SIZE];   /* parsed information, indexed by certman_parsed_cert_group_enum */
    certman_error_enum          status;     /* parse begin confirm return value */
} certman_parse_begin_cnf_struct;

/* This structure defines the certman parse detail certificate request */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 trans_id;        /* application transaction ID */
    kal_uint16 job_id;          /* associated certman parse job ID */
    kal_uint32 cert_ref_id;     /* specified certificate reference id from parse begin confirm message */
} certman_parse_cert_detail_req_struct;

/* This structure defines the certman parse detail certificate confirm */
typedef struct
{
    kal_uint8                       ref_count;
    kal_uint16                      msg_len;
    kal_uint32                      trans_id;       /* application transaction ID */
    certman_parsed_data_struct      *parsed_data;   /* parsed certificate data  */
    certman_error_enum              status;         /* parse detail result */
} certman_parse_cert_detail_cnf_struct;

/* This structure defines the certman parse end request */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 trans_id;        /* application transaction ID */
    kal_uint16 job_id;          /* registered certman parse job ID */
} certman_parse_end_req_struct;

/* This structure defines the certman parse end confirm */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;   /* application transaction ID */
    certman_error_enum      status;     /* parse end result */
} certman_parse_end_cnf_struct;


/*************************************************************************
 * LOCAL PARAMETERS -- IMPORT
 ************************************************************************/

/* This structure defines the certman import request */
typedef struct
{
    kal_uint8                           ref_count;
    kal_uint16                          msg_len;
    kal_uint16                          parse_job_id;   /* associated certman parse job ID */
    kal_uint32                          cert_ref_id;    /* certificate reference ID from parse begin confirm message */
    kal_uint32                          trans_id;       /* application transaction ID */
    kal_uint8                           label[CERTMAN_LABEL_SIZE];  /* the label string for importing certificate */
    certman_dcs_enum                    dcs;                        /* label string dcs */
    certman_privkey_protection_enum     privkey_protection;         /* the private key protection setting if this is a client certificate (certman_privkey_protection_enum) */
    kal_uint32                          pregid;                     /* the password registered ID in certman to forbid password leaked from primitive */
    kal_uint8                           privkey_exportable;         /* specified the private key exportable (Not support export now) */
} certman_import_req_struct;

/* This structure defines the certman import confirm */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;                   /* application transaction ID */
    kal_uint8               label[CERTMAN_LABEL_SIZE];  /* label of inserting certificate */
    certman_dcs_enum        dcs;                        /* label string dcs */
    kal_uint32              cert_id;                    /* the certificate ID for the importing certificate */
    certman_error_enum      status;                     /* import operation result */
} certman_import_cnf_struct;


/*************************************************************************
 * LOCAL PARAMETERS -- RETRIEVE -- List and Display Info
 ************************************************************************/
/* This structure defines the certman get certificate list by type struct */
typedef struct
{
    kal_uint16              num_ids;                            /* the number of certificates in list array */
    kal_uint32              cert_ids[CERTMAN_NUM_ID_IN_LIST];   /* filtered out certificate list */
} certman_cert_ids_result_struct;

/* This structure defines the certman signature verify utility params struct */
typedef struct
{
    certman_signature_alg   hash_alg;
    void                    *hash_data;
    kal_uint32              hash_len;
    void                    *signature;
    kal_uint32              sig_len;
} certman_signature_vfy_params_struct;

/* This structure defines the certman get certificate list by group request */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;       /* application transaction ID */
    kal_uint32              cert_group;     /* certificate group filter OR'd by certman_cert_group_enum */
    kal_uint32              key_purpose;    /* key purpose filter OR'd by certman_keypurpose_enum */
    kal_uint32              pubkey_type;    /* public key type filter OR'd by certman_pubkey_type_enum */
    kal_uint32              more;           /* caller need to set the more value as got from certman_get_cert_list_by_group_cnf_struct, except the first it should be 0 */
} certman_get_cert_list_by_group_req_struct;

/* This structure defines the certman get certificate list by group confirm */
typedef struct
{
    kal_uint8                       ref_count;
    kal_uint16                      msg_len;
    kal_uint32                      trans_id;       /* application transaction ID */
    kal_uint32                      cert_group;     /* certificate group filter OR'd by certman_cert_group_enum */
    kal_uint32                      key_purpose;    /* certman_keypurpose_enum */
    kal_uint32                      pubkey_type;    /* public key type filter OR'd by certman_pubkey_type_enum */
    certman_cert_list_elem_struct   cert_list[CERTMAN_NUM_CERT_IN_LIST];    /* filtered out certificate list */
    kal_uint16                      size;           /* the number of certificates in list array */
    kal_uint16                      more;           /* the progress index value returned to caller for continuous querying */
    certman_error_enum              status;         /* get certificate list by group operation result */
} certman_get_cert_list_by_group_cnf_struct;

/* This structure defines the certman get certificate list by domain request */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;       /* application transaction ID */
    kal_uint32              domain;         /* certificate domain filter OR'd by certman_cert_domain_enum */
    kal_uint32              key_purpose;    /* key purpose filter OR'd by certman_keypurpose_enum */
    kal_uint32              more;           /* caller need to set the more value as got from certman_get_cert_list_by_domain_cnf_struct, except the first it should be 0 */
} certman_get_cert_list_by_domain_req_struct;

/* This structure defines the certman get certificate list by domain confirm */
typedef struct
{
    kal_uint8                       ref_count;
    kal_uint16                      msg_len;
    kal_uint32                      trans_id;       /* application transaction ID */
    kal_uint32                      domain;         /* certificate domain filter OR'd by certman_cert_domain_enum */
    kal_uint32                      key_purpose;    /* certman_keypurpose_enum */
    certman_cert_list_elem_struct   cert_list[CERTMAN_NUM_CERT_IN_LIST];    /* filtered out certificate list */
    kal_uint16                      size;           /* the number of certificates in list array */
    kal_uint16                      more;           /* the progress index value returned to caller for continuous querying */
    certman_error_enum              status;         /* get certificate list by domain operation result */
} certman_get_cert_list_by_domain_cnf_struct;

/* This structure defines the certman get certificate list by issuers file request */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;       /* application transaction ID */
    kal_uint32              cert_group;     /* certificate group filter OR'd by certman_cert_group_enum */
    kal_uint32              key_purpose;    /* key purpose filter OR'd by certman_keypurpose_enum */
	kal_uint8               pubkey_types[CERTMAN_NUM_KEYTYPE_IN_LIST];  /* specified public key type filter list (certman_pubkey_type_enum) */
    kal_uint8               num_types;      /* public key type filter list size */
    kal_wchar               *issuers_filename;  /* specified issuer names file full path */
} certman_get_cert_list_by_issuers_file_req_struct;

/* This structure defines the certman get certificate list by issuers file confirm */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;   /* application transaction ID */
    kal_uint16              num_certs;  /* the number of filtered out certificates */
    certman_error_enum      status;     /* get certificate list by issuers file result */
} certman_get_cert_list_by_issuers_file_cnf_struct;

/* This structure defines the certman get certificate list by issuers file filtered certificate data indication */
typedef struct
{
    kal_uint8                       ref_count;
    kal_uint16                      msg_len;
    kal_uint32                      trans_id;   /* application transaction ID */
    certman_cert_list_elem_struct   cert_list[CERTMAN_NUM_CERT_IN_LIST];    /* filtered certificate list */
    kal_uint32                      size;   /* filtered certificate list size */
    kal_uint8                       seg;    /* first segment starts from 1, implies the sequence number of data indication */
    kal_uint8                       seg_count;  /* total number of data indications that caller should expact recieved from certman */
    kal_uint8                       last;   /* last one data indication flag */
} certman_get_cert_list_by_issuers_data_ind_struct;

/* This structure defines the certman get certificate display information by specified ID request */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;   /* application transaction ID */
    kal_uint32              cert_id;    /* specified certificate ID */
    kal_uint32              key_purpose;/* key purpose filter OR'd by certman_keypurpose_enum */
    kal_uint8               load_pubkey;/* load public key flag */
} certman_get_cert_disp_by_id_req_struct;

/* This structure defines the certman public key object */
typedef struct
{
    void *data;         /* public key data */
    kal_uint32 size;    /* public key data length */
} certman_pubkey_struct;

/* This structure defines the certman get certificate display information by specified ID confirm */
typedef struct
{
    kal_uint8                       ref_count;
    kal_uint16                      msg_len;
    kal_uint32                      trans_id;   /* application transaction ID */
    kal_uint32                      cert_id;    /* specified certificate ID */
    kal_uint32                      key_purpose;/* certman_keypurpose_enum */
    certman_cert_list_elem_struct   cert_info;  /* associate certificate information in certman database */
    certman_cert_display_struct     cert;       /* certificate display content, must be released by certman_cert_display_content_free(), ie, certman_cert_display_content_free(&(cnf->cert)); */
    kal_uint8                       has_pubkey; /* identify the public key attribute */
    certman_pubkey_type_enum        pubkey_type;/* identify the public key type */
    union
    {
        certman_pubkey_struct *key;     /* need to be released by certman_pubkey_free(), ie, certman_pubkey_free(cnf->pubkey.key); */
    } pubkey;   /* public key union structure */
    certman_error_enum              status; /* get certificate display data by certificate ID result */
} certman_get_cert_disp_by_id_cnf_struct;

/* This structure defines the certman get certificate chain display information by specified ID request */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;   /* application transaction ID */
    kal_uint32              cert_id;    /* specified certificate ID */
} certman_get_cert_chain_disp_by_id_req_struct;

/* This structure defines the certman get certificate chain display information by specified ID confirm */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;   /* application transaction ID */
    kal_uint8               labels[CERTMAN_NUM_CERT_IN_CHAIN_DISP][CERTMAN_LABEL_SIZE]; /* 2 dimension array for certicates' label string of certificates in chain */
    certman_dcs_enum        dcs[CERTMAN_NUM_CERT_IN_CHAIN_DISP];    /* identify each label string dcs in label string array */
    kal_uint32              size;   /* the number of certificates in chain */
    certman_error_enum      status; /* get certificate display chain data by certificate ID result */
} certman_get_cert_chain_disp_by_id_cnf_struct;



/*************************************************************************
 * LOCAL PARAMETERS -- RETRIEVE -- Certificate IDs
 ************************************************************************/

/* This structure defines the certman get certificate IDs by group request */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;       /* application transaction ID */
    kal_uint32              cert_group;     /* certificate group filter OR'd by certman_cert_group_enum */
    kal_uint32              key_purpose;    /* key purpose filter OR'd by certman_keypurpose_enum */
    kal_uint32              more;           /* caller need to set the more value as got from certman_get_certid_by_group_cnf_struct, except the first it should be 0 */
} certman_get_certid_by_group_req_struct;

/* This structure defines the certman get certificate IDs by group confirm */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;       /* application transaction ID */
    kal_uint32              cert_group;     /* certificate group filter OR'd by certman_cert_group_enum */
    kal_uint32              key_purpose;    /* certman_keypurpose_enum */
    kal_uint32              certids[CERTMAN_NUM_ID_IN_LIST];    /* the filtered certificate IDs array */
    kal_uint16              size;           /* the number of IDs in certids array */
    kal_uint16              more;           /* the progress index value returned to caller for continuous querying */
    certman_error_enum      status;         /* get certificate IDs by group operation result */
} certman_get_certid_by_group_cnf_struct;

/* This structure defines the certman get certificate IDs by domain request */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;       /* application transaction ID */
    kal_uint32              domain;         /* certificate domain filter OR'd by certman_cert_domain_enum */
    kal_uint32              key_purpose;    /* key purpose filter OR'd by certman_keypurpose_enum */
    kal_uint32              more;           /* caller need to set the more value as got from certman_get_certid_by_domain_cnf_struct, except the first it should be 0 */
} certman_get_certid_by_domain_req_struct;

/* This structure defines the certman get certificate IDs by domain confirm */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;       /* application transaction ID */
    kal_uint32              domain;         /* certman_domain_enum */
    kal_uint32              key_purpose;    /* certman_keypurpose_enum */
    kal_uint32              certids[CERTMAN_NUM_ID_IN_LIST];    /* the filtered certificate IDs array */
    kal_uint16              size;           /* the number of IDs in certids array */
    kal_uint16              more;           /* the progress index value returned to caller for continuous querying */
    certman_error_enum      status;         /* get certificate IDs by domain operation result */
} certman_get_certid_by_domain_cnf_struct;


/*************************************************************************
 * LOCAL PARAMETERS -- RETRIEVE -- Certificate + Private Key Data Through File
 ************************************************************************/

/* This structure defines the certman get certificate data by specified ID request */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;       /* application transaction ID */
    kal_uint32              cert_id;        /* specified certificate ID */
    certman_encoding_enum   encoding;       /* specified output encoding type (DER/PEM) */
    kal_uint32              key_purpose;    /* key purpose filter OR'd by certman_keypurpose_enum */
    kal_wchar               *output_dir;    /* specified output file path */
} certman_get_cert_by_id_req_struct;

/* This structure defines the certman get certificate data by specified ID confirm */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;   /* application transaction ID */
    kal_uint32              cert_id;    /* specified certificate ID */
    kal_wchar               filename[CERTMAN_FILENAME_LENGTH+1];    /* DER/PEM encoded single X.509 certificate */
    certman_error_enum      status;     /* get certificate data by specified ID operation result */
} certman_get_cert_by_id_cnf_struct;

/* This structure defines the certman get trusted certificate for validation trusted pool by specified ID request */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;   /* application transaction ID */
    kal_uint32              cert_id;    /* specified certificate ID */
    kal_uint32              key_purpose;/* key purpose filter OR'd by certman_keypurpose_enum */
    kal_wchar               *output_dir;/* specified output file path */
} certman_get_trusted_cert_by_id_req_struct;

/* This structure defines the certman get certificate data by specified ID request */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;   /* application transaction ID */
    kal_uint32              cert_id;    /* specified certificate ID */
    kal_wchar               filename[CERTMAN_FILENAME_LENGTH+1];    /* DER/PEM encoded single X.509 certificate */
    certman_error_enum      status;     /* get trusted certificate data for validation trusted pool by specified ID operation result */
} certman_get_trusted_cert_by_id_cnf_struct;

/* This structure defines the certman get certificate chain by specified ID request */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;   /* application transaction ID */
    kal_uint32              cert_id;    /* specified certificate ID */
    kal_uint32              key_purpose;/* key purpose filter OR'd by certman_keypurpose_enum */
    kal_wchar               *output_dir;/* specified output file path */
} certman_get_cert_chain_req_struct;

/* This structure defines the certman get certificate chain by specified ID confirm */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;   /* application transaction ID */
    kal_wchar               filename[CERTMAN_FILENAME_LENGTH+1];    /* PEM encoded X.509 certificate chain */
    kal_uint32              num_certs;  /* number of certs */
    kal_uint32              cert_id;    /* specified certificate ID */
    certman_error_enum      status;     /* get certificate chain by specified ID operation result */
} certman_get_cert_chain_cnf_struct;

/* This structure defines the certman get private key data by specified certificate ID request */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;   /* application transaction ID */
    kal_uint32              cert_id;    /* specified certificate ID */
    certman_fp_pwd_cb       pwd_cb;     /* specified password callback function from caller to get output encrypted private key data password */
    certman_encoding_enum   encoding;   /* specified output file encoding */
    kal_uint8               auto_accept;    /* auto accept flag */
    kal_uint32              pregid;         /* pre-registered password id by certmain exported request API (protect password) */
    kal_wchar               *output_dir;    /* specified output file path */
} certman_get_privkey_req_struct;

/* This structure defines the certman get private key data by specified certificate ID confirm */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;   /* application transaction ID */
    kal_uint32              cert_id;    /* specified certificate ID */
    kal_wchar               filename[CERTMAN_FILENAME_LENGTH+1];    /* DER/PEM encoded PKCS#8 private key (password protected) */
    certman_error_enum      status;     /* get private key operation result */
} certman_get_privkey_cnf_struct;



/*************************************************************************
 * LOCAL PARAMETERS -- RETRIEVE -- User to Unlock Private Key Storage
 ************************************************************************/

/* This structure defines the certman private key password request indication */
typedef struct
{
    kal_uint8                       ref_count;
    kal_uint16                      msg_len;
    kal_uint32                      trans_id;   /* application transaction ID */
    kal_uint32                      cert_id;    /* specified certificate ID */
    kal_uint8                       label[CERTMAN_LABEL_SIZE];  /* the label string of specified certificate that the application may need some hint for password query */
    certman_dcs_enum                dcs;    /* label string dcs */
    certman_fp_pwd_cb               pcb;    /* specified password callback function from certman to copy the password from application, 
                                               application need to use this api to copy password to certman */
    certman_pwdauth_stage_enum      state;  /* the password query staus (certman_pwdauth_stage_enum) */
} certman_privkey_usage_password_ind_struct;

/* This structure defines the certman private key password request response */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;   /* application transaction ID */
    kal_uint8               result;     /* the private key password query result */
} certman_privkey_usage_password_rsp_struct;

/* This structure defines the certman private key usage confirm request indication */
typedef struct
{
    kal_uint8           ref_count;
    kal_uint16          msg_len;
    kal_uint32          trans_id;   /* application transaction ID */
    kal_uint32          cert_id;    /* specified certificate ID */
    kal_uint8           label[CERTMAN_LABEL_SIZE];  /* the label string of specified certificate that the application may need some hint for confirm query */
    certman_dcs_enum    dcs;    /* label string dcs */
} certman_privkey_usage_confirm_ind_struct;

/* This structure defines the certman private key usage confirm request response */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;   /* application transaction ID */
    kal_uint8               result;     /* the private key confirm query result */
} certman_privkey_usage_confirm_rsp_struct;


/*************************************************************************
 * LOCAL PARAMETERS -- VALIDATION
 ************************************************************************/
/* This structure defines the user-specific customizable network parameters for OCSP verification */
typedef struct {
    kal_uint32  data_account;   /* User specific data account */
    kal_uint8   proxy_addr[4];  /* User specific proxy address */
    kal_uint16  proxy_port;     /* User specific proxy port */
} certman_ocsp_network_profile_struct;


/* This structure defines the user-specific customizable parameters for OCSP verification */
typedef struct {
    kal_bool    use_ocsp;       /* User specific proxy port */
    kal_bool    must_pass;      /* User specific must-pass OCSP verification */
    kal_char    responder[256]; /* User specific proxy port */
    kal_uint32  retry_timer;    /* Retry interval for each request in seconds */
    certman_ocsp_network_profile_struct network;   /* User specific network profile */
} certman_ocsp_customize_param_struct;


/* This structure defines the certman validate request for certman validation service */
typedef struct
{
    kal_uint8                   ref_count;
    kal_uint16                  msg_len;
    kal_uint32                  trans_id;   /* application transaction ID */
    kal_uint32                  num_certs;  /* number of certificates in certs array */
    certman_cert_data_struct    certs[CERTMAN_NUM_CERT_IN_VALIDATE];    /* the certificate chain data that need to be validated */
    certman_valsource_enum      validate_source;    /* always CERTMAN_VALSOURCE_ARRAY now */
    certman_valtype_enum        validate_type;      /* always CERTMAN_VALTYPE_TRUSTED_ISSUER now */
    kal_uint8                   verify_type;       /* CERTMAN_ENC_DER/CERTMAN_ENC_PEM */
    kal_wchar                   verify_path[CERTMAN_FILENAME_LENGTH+1]; /* the specified trusted certs pool set by caller */
    kal_wchar                   *output_dir;/* specified output file path */

#ifdef __OCSP_SUPPORT__
    kal_uint32  customize_ocsp_options;  /* Bitmask of certman_ocsp_opt_enum to specified the customized options */
    certman_ocsp_customize_param_struct customize_ocsp_params; /* customized OCSP verification options */
#endif /* __OCSP_SUPPORT__ */
} certman_validate_req_struct;

/* This structure defines the trusted certificate data object in certman validation confirm message */
typedef struct
{
    kal_wchar   filename[CERTMAN_FILENAME_LENGTH+1];    /* DER encoded X509 cert */
    kal_uint32  size;       /* size of cert data stored in file */
    kal_uint32  cert_id;    /* specified certificate ID */
} certman_trusted_cert_struct;

/* This structure defines the certman validate confirm message */
typedef struct
{
    kal_uint8                   ref_count;
    kal_uint16                  msg_len;
    certman_valsource_enum      validate_source;    /* always CERTMAN_VALSOURCE_ARRAY now  */
    certman_valtype_enum        validate_type;      /* always CERTMAN_VALTYPE_TRUSTED_ISSUER now */
    kal_uint32                  trans_id;           /* application transaction ID */
    certman_trusted_cert_struct trusted_cert;       /* the trusted certificate data information */
    kal_uint8                   has_trusted_cert;   /* trusted_cert valid flag */
    certman_error_enum          status;             /* validation operation result */
} certman_validate_cnf_struct;


/*************************************************************************
 * LOCAL PARAMETERS -- DELETION
 ************************************************************************/

/* This structure defines the certman delete certificate request */
typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint32      trans_id;   /* application transaction ID */
    kal_uint32      cert_id;    /* specified certificate ID */
} certman_delete_cert_req_struct;

/* This structure defines the certman delete certificate confirm */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;   /* application transaction ID */
    kal_uint32              cert_id;    /* specified certificate ID */
    certman_error_enum      status;     /* delete operation result */
} certman_delete_cert_cnf_struct;

/* This structure defines the certman delete certificates by group request */
typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint32      trans_id;   /* application transaction ID */
    kal_uint32      cert_group; /* certificate group filter OR'd by certman_cert_group_enum */
} certman_delete_all_cert_req_struct;

/* This structure defines the certman delete certificates by group confirm */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;   /* application transaction ID */
    kal_uint32              cert_group; /* certificate group filter OR'd by certman_cert_group_enum */
    certman_error_enum      status;     /* delete certificates by groups filter result */
} certman_delete_all_cert_cnf_struct;


/*************************************************************************
 * LOCAL PARAMETERS -- MISCELLANEOUS UTILITIES
 ************************************************************************/

/* This structure defines the certman update key purpose by specified ID request */
typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint32      trans_id;   /* application transaction ID */
    kal_uint32      cert_id;    /* specified certificate ID */
	kal_uint32      key_purpose;/* key purpose filter OR'd by certman_keypurpose_enum */
} certman_update_key_purpose_req_struct;

/* This structure defines the certman update key purpose by specified ID confirm */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;       /* application transaction ID */
    kal_uint32              cert_id;        /* specified certificate ID */
    kal_uint32              key_purpose;    /* certman_keypurpose_enum */
    certman_error_enum      status;         /* update key purpose of specified ID result */
} certman_update_key_purpose_cnf_struct;


/* This structure is the request message to trigger the certman ocsp validation procedure */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint8               trans_id;   /* a unique number generated by OCSP and keep for matching by app */
} certman_ocsp_verify_cert_req_struct;


/* This structure is the confirm message to report the certman ocsp validation result */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint8               trans_id;   /* a unique number generated by OCSP and keep for matching by app */
    certman_error_enum      status;     /* validation operation result */
} certman_ocsp_verify_cert_cnf_struct;


typedef struct
{
    kal_wchar *filename;
	certman_encoding_enum encoding;
	kal_uint8 *pwd;
} certman_ctx_parse_struct;


typedef struct
{
    kal_uint16 parse_job_id;
    kal_uint32 cert_ref_id;
    char label[CERTMAN_LABEL_SIZE];
    certman_dcs_enum dcs;
    certman_privkey_protection_enum privkey_protection;
    char *password;
    kal_uint8 privkey_exportable;
} certman_ctx_import_struct;


typedef struct
{
    kal_uint32                  num_certs;
    certman_cert_data_struct    certs[CERTMAN_NUM_CERT_IN_VALIDATE];
    kal_wchar                   verify_path[CERTMAN_FILENAME_LENGTH+1]; /* JAVA PKI */
    kal_uint8                   verify_type;   /* (DER/PEM) JAVA PKI */
    certman_valsource_enum      validate_source;
    certman_valtype_enum        validate_type;

#ifdef __OCSP_SUPPORT__
    kal_uint32  customize_ocsp_options;
    certman_ocsp_customize_param_struct ocsp_params;
#endif /* __OCSP_SUPPORT__ */
} certman_ctx_validate_struct;

#ifdef CERTMAN_AT_CMD
typedef struct
{
	kal_uint8 ref_count;
    kal_uint16 msg_len;
	kal_uint8   src_id;
    kal_wchar* filename;        
    kal_uint8 *parse_password;        
} certman_user_cert_import_struct ;

typedef struct
{
	kal_uint8 ref_count;
    kal_uint16 msg_len;
	kal_uint8   src_id;
    kal_wchar* filename;        /* Path, where private key to be exported. */
} certman_user_cert_key_export_struct ;

typedef struct
{
	kal_uint8 ref_count;
    certman_user_cert_op_enum op;				/* Operation */
	kal_uint8   src_id;
    certman_user_cert_op_status_enum status;       /* status */
} certman_user_cert_rsp_struct ;
#endif

#endif  /* CERTMAN_STRUCT_H */
