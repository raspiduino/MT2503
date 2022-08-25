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
 *    certman_sap.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    Certificate Manager exported services
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#ifndef _CERTMAN_SAP_H
#define _CERTMAN_SAP_H
/*------------ MSG_ID_CERTMAN_MSG_CODE_BEGIN ---------------*/

#ifdef __BUILD_DOM__
    /*****************************************************************************
    * <GROUP  Messages>        
    *
    * Certman SAP Primitives
    ******************************************************************************/
    typedef enum {
#endif /* __BUILD_DOM__ */

    /* This primitive is used to subscribe the ready notification from certman.
    *
    * Direction: APP -> Certman
    * Local parameter: None
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_READY_SUBSCRIBE_REQ = MSG_ID_CERTMAN_MSG_CODE_BEGIN,


    /* This primitive is used to notify the subscribed applications that the Certman is ready now.
    *
    * Direction: Certman -> APP
    * Local parameter: None
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_READY_SUBSCRIBE_CNF,
    

    /* This primitive is used to request the certman parsing service
    *  Please check the API : certman_send_parse_begin_req for detailed description
    *
    * Direction: APP -> Certman
    * Local parameter: certman_parse_begin_req_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_PARSE_BEGIN_REQ,

    /* This primitive will be sent as a response to when certman_send_parse_begin_req is called, 
    *  and on success call to this service caller should use the returned "job_id" for subsequent parse/import operations. 
    *  When the status is not CERTMAN_ERR_NONE, no job will be created in Certman and hence the job_id will be invalid, application must resend "parse begin" request should it wishes to correct the error and retry again.
    *
    *  The "parsed_info" parameter contains the statistical information such as the number of certificates found in file. 
    *  It is array based and indexed by the certman_parsed_cert_group_enum enumeration, where:
    *       parsed_info [CERTMAN_PARSED_CERTGRP_ALL].cert_count = number of all certificates found in file, and
    *       parsed_info [CERTMAN_PARSED_CERTGRP_ROOTCA].cert_count = number of all root CA certificates found.
    *  The "cert_ref_ids" in each of the "parsed_info" array element is the reference IDs of the certificates found in the file 
    *  which belongs to that particular certificate group, for example:
    *       parsed_info [CERTMAN_PARSED_CERTGRP_ALL].cert_ref_ids = all certificate reference IDs within this file
    *       parsed_info [CERTMAN_PARSED_CERTGRP_ROOTCA].cert_ref_ids = all root CA certificate reference IDs within this file.
    *    
    *  Please be reminded that the information refer to by CERTMAN_PARSED_CERTGRP_ALL contains information from Root CA + Other CA + Other User + Personal Certificate. 
    *  This structure allows Certificate Management Application to design its import UI sequence flow without limited by Certman.
    *  The "num_private_key" parameter specify the number of private keys found in file, this should always matches the number of personal certificate.
    *
    *  Possible Return Values :
    *   CERTMAN_ERR_NONE                :   Success
    *   CERTMAN_ERR_MEMFULL             :   Memory full error
    *   CERTMAN_ERR_INVALID_CONTEXT     :   NULL pointer, or context not correctly setup
    *   CERTMAN_ERR_FILE_NOT_FOUND      :   File is NULL pointer or cannot be found
    *   CERTMAN_ERR_FS_ERROR            :   File system error
    *   CERTMAN_ERR_INVALID_ENCODING    :   Encoding type error
    *   CERTMAN_ERR_UNSUPPORTED_CONTENT :   thorough analysis of data reveals that content in file cannot be supported
    *   CERTMAN_ERR_INCORRECT_PASSWORD  :   unable to decrypt file with the specified password
    *   CERTMAN_ERR_NEED_PASSWORD       :   file is password protected and context does not contain password information
    *   
    * Direction: Certman -> APP
    * Local parameter: certman_parse_begin_cnf_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_PARSE_BEGIN_CNF,


    /* This primitive is used to request the certman to finish the parsing job
    *  Please check the API : certman_send_parse_end_req for detailed description
    *
    * Direction: APP -> Certman
    * Local parameter: certman_parse_end_req_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_PARSE_END_REQ,


    /* This primitive will be sent as a response to when certman_send_parse_end_req is called, 
    *  the status of this response should always be CERTMAN_ERR_NONE.
    *
    *  Possible Return Values :
    *   CERTMAN_ERR_NONE            :   Success
    *   CERTMAN_ERR_INVALID_JOB	    :   no such job_id found in Certman   
    *
    * Direction: Certman -> APP
    * Local parameter: certman_parse_end_cnf_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_PARSE_END_CNF,


    /* This primitive is used to request the certman to get the parsed certificate data of the associated 
    *  parse job ("job_id") and the certificate reference ID.
    *  Please check the API : certman_send_parse_cert_detail_req for detailed description
    *
    * Direction: APP -> Certman
    * Local parameter: certman_parse_cert_detail_req_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_PARSE_CERT_DETAIL_REQ,


    /* This primitive will be sent as a response to when certman_send_parse_cert_detail_req is called.
    *  Application is reminded that the "parsed_data" must be released by application using certman_parsed_data_free API.
    *
    *
    *  Possible Return Values :
    *   CERTMAN_ERR_NONE                :   Success
    *   CERTMAN_ERR_MEMFULL             :   Memory full error
    *   CERTMAN_ERR_UNSUPPORTED_CONTENT :   parsing of specified certificate has failed
    *   CERTMAN_ERR_INVALID_JOB         :   no such job_id found in Certman
    *   CERTMAN_ERR_INVALID_CERT_ID     :   no such cert_ref_id found in the specified job
    *   CERTMAN_ERR_FS_ERROR            :   general file system error
    *
    * Direction: Certman -> APP
    * Local parameter: certman_parse_cert_detail_cnf_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_PARSE_CERT_DETAIL_CNF,


    /* This primitive is used to request the certman import service
    *  Please check the API : certman_send_import_req for detailed description
    *
    * Direction: APP -> Certman
    * Local parameter: certman_import_req_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_IMPORT_REQ,


    /* This primitive will be sent as a response to when certman_send_import_req is called.
    *  On successful import of the certificate, the status will be set to CERTMAN_ERR_NONE, 
    *  and its certificate ID and label returned for application's reference.
    *
    *  Possible Return Values :
    *   CERTMAN_ERR_NONE                :   Success
    *   CERTMAN_ERR_MEMFULL             :   Memory full error
    *   CERTMAN_ERR_INVALID_CONTEXT     :   NULL pointer, or context not correctly setup
    *   CERTMAN_ERR_CERT_EXISTS         :   This certificate had imported in certman database
    *   CERTMAN_ERR_LABEL_EXISTS        :   certificate label duplicated
    *   CERTMAN_ERR_DISK_FULL           :   disk full to import certificate
    *   CERTMAN_ERR_UNSUPPORTED_CONTENT :   parsing of current certificate has failed
    *   CERTMAN_ERR_INVALID_JOB         :   no such job_id found in Certman
    *   CERTMAN_ERR_INVALID_CERT_ID     :   no such cert_ref_id found in the specified job
    *   CERTMAN_ERR_FS_ERROR            :   this error may be returned either when loading certificate data from file, or writing imported certificate data to file
    *
    * Direction: Certman -> APP
    * Local parameter: certman_import_cnf_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_IMPORT_CNF,


    /* This primitive is used to request the certman to query the certificates in system database 
    *  by specified certificate groups and key purposes criteria.
    *  Please check the API : certman_send_get_cert_list_by_group_req for detailed description
    *
    * Direction: APP -> Certman
    * Local parameter: certman_get_cert_list_by_group_req_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_GET_CERT_LIST_BY_GROUP_REQ,


    /* This primitive will be sent as a response to when certman_send_get_cert_list_by_group_req is called.
    *  Each of these responses are only allowed a max of CERTMAN_NUM_CERT_IN_LIST info per primitive, 
    *  the number of valid certificate info entries in "cert_list" array is described in "size" parameter, 
    *  and the value of "more" indicates whether the list has ended. 
    *  
    *  Receiver wishing to obtain the next set of certificate info must pass the "more" value to certman_send_get_cert_list_by_group_req
    *  with exact same conditions that were given.
    * 
    *  The certificate list element structure is certman_cert_list_elem_struct
    *
    *  A request containing valid "cert_group" and "key_purpose" and found no matching certificates is not considered an error, 
    *  the "status" in this confirmation primitive will be CERTMAN_ERR_NONE and "size" and "more" will both be set to 0.
    *
    *  Possible Return Values :
    *   CERTMAN_ERR_NONE                :   Success
    *   CERTMAN_ERR_MEMFULL             :   Memory full error
    *   CERTMAN_ERR_INVALID_GROUP       :   cert_group parameter setting error
    *   CERTMAN_ERR_INVALID_KEY_PURPOSE :   key_purpose parameter setting error
    *
    * Direction: Certman -> APP
    * Local parameter: certman_get_cert_list_by_group_cnf_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_GET_CERT_LIST_BY_GROUP_CNF,


    /* This primitive is used to request the certman to query the certificates in system database 
    *  by specified certificate groups and domains criteria.
    *  Please check the API : certman_send_get_cert_list_by_domain_req for detailed description
    *
    * Direction: APP -> Certman
    * Local parameter: certman_get_cert_list_by_domain_req_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_GET_CERT_LIST_BY_DOMAIN_REQ,


    /* This primitive will be sent as a response to when certman_send_get_cert_list_by_domain_req is called. 
    *  Each of these responses are only allowed a max of CERTMAN_NUM_CERT_IN_LIST info per primitive, 
    *  the number of valid certificate info entries in "cert_list" array is described in "size" parameter, 
    *  and the value of "more" indicates whether the list has ended. 
    *
    *  Receiver wishing to obtain the next set of certificate info must pass the "more" value to certman_send_get_cert_list_by_domain_req
    *  with exact same conditions that were given.
    *
    *  A request containing valid "domain" and "key_purpose" and found no matching certificates is not considered an error, 
    *  the "status" in this confirmation primitive will be CERTMAN_ERR_NONE and "size" and "more" will both be set to 0.
    *
    *  The certificate list element structure is certman_cert_list_elem_struct
    *
    *  Possible Return Values :
    *   CERTMAN_ERR_NONE                :   Success
    *   CERTMAN_ERR_MEMFULL             :   Memory full error
    *   CERTMAN_ERR_INVALID_DOMAIN      :   domain parameter setting error
    *   CERTMAN_ERR_INVALID_KEY_PURPOSE :   key_purpose parameter setting error
    *
    * Direction: Certman -> APP
    * Local parameter: certman_get_cert_list_by_domain_cnf_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_GET_CERT_LIST_BY_DOMAIN_CNF,


    /* This primitive is used to request the certman to do client authentication.
    *  The desired issuer names list from server should be provided in file using predefined format.
    *  The desired public key types from server should be provided also for filter criteria.
    *  Please check the API : certman_send_get_cert_list_by_issuers_file_req for detailed description
    *
    * Direction: APP -> Certman
    * Local parameter: certman_get_cert_list_by_issuers_file_req_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_GET_CERT_LIST_BY_ISSUERS_FILE_REQ,


    /* This primitive will be sent as a response to when certman_send_get_cert_list_by_issuers_file_req is called. 
    *  The "num_certs" parameter determines the number of certificate information entries to expect through 
    *  the MSG_ID_CERTMAN_GET_CERT_LIST_BY_ISSUERS_DATA_IND primitives that follows. 
    *  
    *  Please note there will not be any data_ind sent to application if this value equals to 0.
    *  A request containing valid "cert_group" and "key_purpose" but found no matching certificates is not considered an error, 
    *  the "status" in this confirmation primitive will be CERTMAN_ERR_NONE and "num_certs" will be set to 0, 
    *  and there will be no MSG_ID_CERTMAN_GET_CERT_LIST_BY_ISSUERS_DATA_IND sent to application.
    *
    *  CertMan guarantees that num_certs will always be 0 shall there be an error occurred (ie, status not CERTMAN_ERR_NONE).
    *  CertMan also guarantees that this primitive will always be sent to application 
    *  before MSG_ID_CERTMAN_GET_CERT_LIST_BY_ISSUERS_DATA_IND if any.    
    *
    *  Possible Return Values :
    *   CERTMAN_ERR_NONE                :   Success
    *   CERTMAN_ERR_MEMFULL             :   Memory full error
    *   CERTMAN_ERR_INVALID_CERT_GROUP  :   cert_group parameter setting error
    *   CERTMAN_ERR_INVALID_KEY_PURPOSE :   key_purpose parameter setting error
    *   CERTMAN_ERR_INVALID_FILENAME    :   the issuer file name parameter setting error
    *   CERTMAN_ERR_FILE_NOT_FOUND      :   issuer file not found
    *   CERTMAN_ERR_FS_ERROR            :   general file system error
    *
    * Direction: Certman -> APP
    * Local parameter: certman_get_cert_list_by_issuers_file_cnf_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_GET_CERT_LIST_BY_ISSUERS_FILE_CNF,


    /* This primitive will be sent as a data response to when certman_send_get_cert_list_by_issuers_file_req is called. 
    *  This primitive will only be sent when the "num_certs" parameter in the MSG_ID_CERTMAN_GET_CERT_LIST_BY_ISSUERS_FILE_CNF does not equal to 0.
    *  
    *  The "cert_list" array contains the information of the matching certificates.
    *  The "last" parameter indicates whether this data_ind is the last primitive of its sequence.
    *
    *  The "status" should always equal to CERTMAN_ERR_NONE in this primitive as all data have already been collected and ready beforehand.    
    *
    * Direction: Certman -> APP
    * Local parameter: certman_get_cert_list_by_issuers_data_ind_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_GET_CERT_LIST_BY_ISSUERS_DATA_IND,


    /* This primitive is used to request the certman to get the certificate display information data by specified certificate ID.
    *  Please check the API : certman_send_get_cert_disp_by_id_req for detailed description
    *
    * Direction: APP -> Certman
    * Local parameter: certman_get_cert_disp_by_id_req_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_GET_CERT_DISP_BY_ID_REQ,


    /* This primitive will be sent as a response to when certman_send_get_cert_disp_by_id_req is called.
    *  On success retrieval of certificate information, the certificate's displayable information will be filled in "cert" parameter, 
    *  and caller must be responsible for releasing the contents within the "cert" object 
    *  using the Certman's API: certman_cert_display_content_free.
    *
    *  The "cert_info" parameter contains other information about this certificate.
    *  The certificate list element structure is certman_cert_list_elem_struct.
    *
    *  Possible Return Values :
    *   CERTMAN_ERR_NONE                :   Success
    *   CERTMAN_ERR_MEMFULL             :   Memory full error
    *   CERTMAN_ERR_CERT_NOT_FOUND      :   certificate of specified ID can't be found 
    *
    * Direction: Certman -> APP
    * Local parameter: certman_get_cert_disp_by_id_cnf_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_GET_CERT_DISP_BY_ID_CNF,


    /* This primitive is used to request the certman to get the certificate chain display information data by specified certificate ID.
    *  Please check the API : certman_send_get_cert_chain_disp_by_id_req for detailed description
    *
    * Direction: APP -> Certman
    * Local parameter: certman_get_cert_chain_disp_by_id_req_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_GET_CERT_CHAIN_DISP_BY_ID_REQ,


    /* This primitive will be sent as a response to when certman_send_get_cert_chain_disp_by_id_req is called.
    *  On success retrieval of certificate chain information, the "labels" array will be filled with label of the certificates preceding the requested one,
    *  where label at index 0 will be the label of the requested certificate, at index 1 the label of the issuer of this certificate, 
    *  index 2 the label of the issuer at index 1¡K and so on, until at index size-1 the label of the root CA for this chain.
    *
    *  The "dcs" array specify whether the label at the corresponding index is an ASCII or UCS2 encoding.
    *  When the number of certificates in chain exceeds the CERTMAN_NUM_CERT_IN_CHAIN_DISP limitation, 
    *  this response primitive would have CERTMAN_ERR_CHAIN_TOO_LARGE in its status and no label will be made available in the array.
    *
    *  Possible Return Values :
    *   CERTMAN_ERR_NONE                :   Success
    *   CERTMAN_ERR_MEMFULL             :   Memory full error
    *   CERTMAN_ERR_CERT_NOT_FOUND      :   certificate of specified ID can't be found 
    *   CERTMAN_ERR_CHAIN_TOO_LARGE     :   certificate chain too long
    *
    * Direction: Certman -> APP
    * Local parameter: certman_get_cert_chain_disp_by_id_cnf_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_GET_CERT_CHAIN_DISP_BY_ID_CNF,


    /* This primitive is used to request the certman to get the certificate IDs by specified certificate groups filter.
    *  Please check the API : certman_send_get_certid_by_group_req for detailed description
    *
    * Direction: APP -> Certman
    * Local parameter: certman_get_certid_by_group_req_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_GET_CERTID_BY_GROUP_REQ,


    /* This primitive will be sent as a response to when certman_send_get_certid_by_group_req is called.
    *  Each of these responses are only allowed a max of CERTMAN_NUM_ID_IN_LIST IDs per primitive, 
    *  the number of valid IDs in "certids" array is described in "size" parameter, 
    *  and the value of "more" indicates whether the list has ended. 
    *
    *  Receiver wishing to obtain the next set of IDs must pass the "more" value to certman_send_get_certid_by_group_req with 
    *  exact same conditions that were given.
    *
    *  Possible Return Values :
    *   CERTMAN_ERR_NONE                :   Success
    *   CERTMAN_ERR_MEMFULL             :   Memory full error
    *   CERTMAN_ERR_INVALID_GROUP       :   cert_group parameter setting error
    *   CERTMAN_ERR_INVALID_KEY_PURPOSE :   key_purpose parameter setting error
    *
    * Direction: Certman -> APP
    * Local parameter: certman_get_certid_by_group_cnf_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_GET_CERTID_BY_GROUP_CNF,


    /* This primitive is used to request the certman to get the certificate IDs by specified certificate domains filter.
    *  Please check the API : certman_send_get_certid_by_domain_req for detailed description
    *
    * Direction: APP -> Certman
    * Local parameter: certman_get_certid_by_domain_req_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_GET_CERTID_BY_DOMAIN_REQ,


    /* This primitive will be sent as a response to when certman_send_get_certid_by_domain_req is called.
    *  Each of these responses are only allowed a max of CERTMAN_NUM_ID_IN_LIST IDs per primitive, 
    *  the number of valid IDs in "certids" array is described in "size" parameter, 
    *  and the value of "more" indicates whether the list has ended. 
    *
    *  Receiver wishing to obtain the next set of IDs must pass the "more" value to certman_send_get_certid_by_domain_req
    *  with exact same conditions that were given.
    *    
    *  Possible Return Values :
    *   CERTMAN_ERR_NONE                :   Success
    *   CERTMAN_ERR_MEMFULL             :   Memory full error
    *   CERTMAN_ERR_INVALID_DOMAIN      :   domain parameter setting error
    *   CERTMAN_ERR_INVALID_KEY_PURPOSE :   key_purpose parameter setting error
    *
    * Direction: Certman -> APP
    * Local parameter: certman_get_certid_by_domain_cnf_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_GET_CERTID_BY_DOMAIN_CNF,


    /* This primitive is used to request the certman to get the certificate data by specified certificate ID.
    *  Please check the API : certman_send_get_cert_by_id_req for detailed description
    *
    * Direction: APP -> Certman
    * Local parameter: certman_get_cert_by_id_req_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_GET_CERT_BY_ID_REQ,


    /* This primitive will be sent as a response to when certman_send_get_cert_by_id_req is called.
    *
    *  Possible Return Values :
    *   CERTMAN_ERR_NONE                :   Success
    *   CERTMAN_ERR_MEMFULL             :   Memory full error
    *   CERTMAN_ERR_KEY_PURPOSE_DENIED  :   key purpose denied by certificate info setting
    *   CERTMAN_ERR_INVALID_ENCODING    :   encoding parameter setting error
    *   CERTMAN_ERR_DISK_FULL           :   file system disk full
    *   CERTMAN_ERR_CERT_NOT_FOUND      :   certificate of specified ID can't be found 
    *   CERTMAN_ERR_FS_ERROR            :   general file system error
    *
    * Direction: Certman -> APP
    * Local parameter: certman_get_cert_by_id_cnf_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_GET_CERT_BY_ID_CNF,


    /* This primitive is used to request the certman to prepare the trusted ca certificates pool for certman validation process.
    *  Please check the API : certman_send_get_trusted_cert_by_id_req for detailed description
    *
    * Direction: APP -> Certman
    * Local parameter: certman_get_trusted_cert_by_id_req_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_GET_TRUSTED_CERT_BY_ID_REQ,


    /* This primitive will be sent as a response to when certman_send_get_trusted_cert_by_id_req is called.
    *
    *  Possible Return Values :
    *   CERTMAN_ERR_NONE                :   Success
    *   CERTMAN_ERR_MEMFULL             :   Memory full error
    *   CERTMAN_ERR_KEY_PURPOSE_DENIED  :   key purpose denied by certificate info setting
    *   CERTMAN_ERR_DISK_FULL           :   file system disk full
    *   CERTMAN_ERR_CERT_NOT_FOUND      :   certificate of specified ID can't be found 
    *   CERTMAN_ERR_FS_ERROR            :   general file system error
    *
    * Direction: Certman -> APP
    * Local parameter: certman_get_trusted_cert_by_id_cnf_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_GET_TRUSTED_CERT_BY_ID_CNF,


    /* This primitive is used to request the certman to output the certificate chain by specified certificate ID.
    *  Please check the API : certman_send_get_cert_chain_req for detailed description
    *
    * Direction: APP -> Certman
    * Local parameter: certman_get_cert_chain_req_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_GET_CERT_CHAIN_REQ,


    /* This primitive will be sent as a response to when certman_send_get_cert_chain_req is called.
    *
    *  Possible Return Values :
    *   CERTMAN_ERR_NONE                :   Success
    *   CERTMAN_ERR_MEMFULL             :   Memory full error
    *   CERTMAN_ERR_INVALID_CERT_GROUP  :   cert_group parameter setting error
    *   CERTMAN_ERR_INVALID_ENCODING    :   encoding parameter setting error
    *   CERTMAN_ERR_INVALID_PATH        :   output path parameter setting error
    *   CERTMAN_ERR_DISK_FULL           :   file system disk full
    *   CERTMAN_ERR_CERT_NOT_FOUND      :   certificate of specified ID can't be found 
    *   CERTMAN_ERR_FS_ERROR            :   general file system error
    *
    * Direction: Certman -> APP
    * Local parameter: certman_get_cert_chain_cnf_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_GET_CERT_CHAIN_CNF,


    /* This primitive is used to request the certman to output the associated private key by specified certificate ID.
    *  Certman will generate a new file for each request and have the requested private key placed in this file.
    *  Please check the API : certman_send_get_privkey_req and certman_send_get_privkey_req_auto_accept for detailed description
    *
    * Direction: APP -> Certman
    * Local parameter: certman_get_privkey_req_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_GET_PRIVKEY_REQ,


    /* This primitive will be sent as a response to when certman_send_get_privkey_req or certman_send_get_privkey_req_auto_accept is called.
    *
    *  Possible Return Values :
    *   CERTMAN_ERR_NONE                :   Success
    *   CERTMAN_ERR_MEMFULL             :   Memory full error
    *   CERTMAN_ERR_ACCESS_DENIED       :   not exportable key or user reject/cancel the confirm message
    *   CERTMAN_ERR_INVALID_ENCODING    :   encoding parameter setting error
    *   CERTMAN_ERR_NO_PWD_CALLBACK     :   caller doesn't assign the private key temp file password callback function
    *   CERTMAN_ERR_DISK_FULL           :   file system disk full
    *   CERTMAN_ERR_KEY_NOT_FOUND      :   certificate of specified ID can't be found 
    *   CERTMAN_ERR_FS_ERROR            :   general file system error
    *
    * Direction: Certman -> APP
    * Local parameter: certman_get_privkey_cnf_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_GET_PRIVKEY_CNF,


    /* This is a primitive that Certificate Management Application must handle and implement, 
    *  for the purpose of displaying a PIN input dialog when a private key is about to be accessed. 
    *
    *  Caller must ensure that the password is an ASCII string and cannot be NULL or empty value. 
    *  The maximum number of characters of a password is defined by CERTMAN_PASSWORD_LENGTH (32). 
    *  Certman provides the "cert_id" matching the certificate of the private key to be retrieved, 
    *  and extracted its label and placed in "label" parameter for application to use to display.
    *
    *  Certificate Management Application must ensure this dialog can be shown at anytime whenever it is received (except during call, but must be shown immediately after call ended), the reason being that this request would only be triggered by Certman when a private key is needed by some other modules (may include the Certificate Management Application itself during PKCS#12 export operation), sending this request means other modules are pended (they may well have their own progressing screen in background), 
    *  hence this dialog must be made visible to user when it is needed so the requesting module may proceed as soon as input has acquired.
    * 
    *  Upon successful acquisition of PIN from user, it must be passed to Certman through the password callback function "pcb", 
    *  and sends the MSG_ID_CERTMAN_PRIVKEY_USAGE_PASSWORD_RSP to Certman with result set to 1. 
    *
    *  If user aborts the PIN input (either by RSK cancel, or END-Key), "pcb" does not need to be called, 
    *  but MSG_ID_CERTMAN_PRIVKEY_USAGE_PASSWORD_RSP must still be sent to Certman having result set to 0 indicate no password has been provided and user aborts. 
    *  An empty password is strictly disallowed. 
    *  
    *  Application must fill in the correct "trans_id" and "cert_id" when triggering the "pcb" password callback, and the "size" parameter needs to be the size of entire password string including the zero-termiante.
    *
    *  To provide a user friendly interface of the PIN input and validation process, 
    *  a "state" parameter has been added, indicating whether the last PIN validation succeeded or failed, 
    *  or whether this is the first PIN input operation or PIN operation aborted by Certman.
    *  There are 4 allowable "states":
    *       CERTMAN_PWDAUTH_FIRST:
    *           first PIN input event, application should display the PIN input dialog
    *       CERTMAN_PWDAUTH_FAILED_RETRY_AGAIN:
    *           last PIN was incorrect, application might want to display a "incorrect pin" error popup to the user, and must request user to retry again
    *       CERTMAN_PWDAUTH_FAILED_ABORT:
    *           last PIN was incorrect, application might want to display a "incorrect pin" error popup to the user, and must not  allow user to continue PIN input operation
    *       CERTMAN_PWDAUTH_SUCCEEDED:
    *           last PIN input was validated successfully, application is recommended to close the PIN input dialog straightaway without further prompt to user.
    *
    *  It is guaranteed that Certman will always send a state of "CERTMAN_PWDAUTH_FIRST" to application for the first PIN input operation, 
    *  and may send one or more "CERTMAN_PWDAUTH_FAILED_RETRY_AGAIN" if the PIN was incorrect, 
    *  and finally Certman will send either "CERTMAN_PWDAUTH_FAILED_ABORT" or "CERTMAN_PWDAUTH_SUCCEEDED" 
    *  depends on whether retries count exceeded, or PIN could be validated successfully.    
    *
    * Direction: Certman -> APP
    * Local parameter: certman_privkey_usage_password_ind_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_PRIVKEY_USAGE_PASSWORD_IND,


    /* This primitive is used to notify the certman that the private key usage password query from user was finished no matter success or aborted.
    *  Please check the API : certman_send_privkey_usage_password_rsp for detailed description
    *
    * Direction: APP -> Certman
    * Local parameter: certman_privkey_usage_password_rsp_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_PRIVKEY_USAGE_PASSWORD_RSP,


    /* This is a primitive that Certificate Management Application must handle and implement, 
    *  for the purpose of obtaining user's confirmation when a private key is about to be accessed. 
    *
    *  Certman provides the "cert_id" matching the certificate of the private key to be retrieved, 
    *  and extracted its label and placed in "label" parameter for application to use to display. Application must allow user to choose whether the private key can be accessed (ie, "yes", or "no" style)
    *  
    *  Certificate Management Application must ensure this dialog can be shown at anytime whenever it is received (except during call, but must be shown immediately after call ended), 
    *  the reason being that this request would only be triggered by Certman when a private key is needed by some other modules (may include the Certificate Management Application itself during PKCS#12 export operation), 
    *  sending this request means other modules are pended (they may well have their own progressing screen in background), 
    *  hence this dialog must be made visible to user when it is needed so the requesting module may proceed as soon as input has acquired.
    *
    *  Regardless of whether user has successfully made the choice, 
    *  application must send back the response via MSG_ID_CERTMAN_PRIVKEY_USAGE_CONFIRM_RSP primitive, 
    *  the interface function certman_send_privkey_usage_confirm_rsp can be used for returning the result also.
    *
    *  When user allows private key to be accessed, application must sends to Certman a result of 1, 
    *  and when user denies the private key access, or presses END-Key to abort, application must then send a result of 0 to Certman. 
    *  Application may remove the confirmation dialog as soon as user makes the choice and its result sent.
    *
    * Direction: Certman -> APP
    * Local parameter: certman_privkey_usage_confirm_ind_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_PRIVKEY_USAGE_CONFIRM_IND,


    /* This primitive is used to notify the certman that the private key usage confirm query from user was finished no matter success or aborted.
    *  Please check the API : certman_send_privkey_usage_confirm_rsp for detailed description
    *
    * Direction: APP -> Certman
    * Local parameter: certman_privkey_usage_confirm_rsp_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_PRIVKEY_USAGE_CONFIRM_RSP,


    /* This primitive is used to request the certman to validate the specified certificate chain.
    *  Please check the API : certman_send_validate_req for detailed description
    *
    * Direction: APP -> Certman
    * Local parameter: certman_validate_req_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_VALIDATE_REQ,


    /* This primitive will be sent as a response to when certman_send_validate_req is called.
    *  The validation outcome will set in the response primitive and the trusted certificate will be saved
    *  in a file if found and the full file name will also be returned in response.
    * 
    *  Possible Return Values :
    *   CERTMAN_ERR_NONE                        :   Success
    *   CERTMAN_ERR_MEMFULL                     :   Memory full error
    *   CERTMAN_ERR_INVALID_VALIDATION_PARAM    :   the validation type or validation source type parameters setting error
    *   CERTMAN_ERR_INVALID_PATH                :   the output path setting error
    *   CERTMAN_ERR_NO_TRUSTED_CERT_FOUND       :   no trusted certificate in validation chain
    *   CERTMAN_ERR_CERT_EXPIRED                :   the last trusted certificate in chain had expired
    *   CERTMAN_ERR_FAIL                        :   general error cause by data content
    *   CERTMAN_ERR_DISK_FULL                   :   file system disk full
    *   CERTMAN_ERR_FS_ERROR                    :   general file system error
    *   CERTMAN_ERR_CORRUPTED_DATA              :   the certificate data is corrupted     
    *   CERTMAN_ERR_INVALID_CONTEXT             :   validate context parameter error
    *
    * Direction: Certman -> APP
    * Local parameter: certman_validate_cnf_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_VALIDATE_CNF,


    /* This primitive is used to request the certman to delete the specified certificate by specified certificate ID.
    *  Please check the API : certman_send_delete_cert_req for detailed description
    *
    * Direction: APP -> Certman
    * Local parameter: certman_delete_cert_req_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_DELETE_CERT_REQ,


    /* This primitive will be sent as a response to when certman_send_delete_cert_req is called.
    * 
    *  Possible Return Values :
    *   CERTMAN_ERR_NONE                :   Success
    *   CERTMAN_ERR_READ_ONLY           :   The specified certificate is read-only
    *   CERTMAN_ERR_CERT_NOT_FOUND      :   can't find the certificate of specified ID.
    *   CERTMAN_ERR_FS_ERROR            :   general file system error
    *
    * Direction: Certman -> APP
    * Local parameter: certman_delete_cert_cnf_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_DELETE_CERT_CNF,


    /* This primitive is used to request the certman to delete all certificates by specified certificate groups.
    *  Please check the API : certman_send_delete_all_cert_req for detailed description
    *
    * Direction: APP -> Certman
    * Local parameter: certman_delete_all_cert_req_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_DELETE_ALL_CERT_REQ,


    /* This primitive will be sent as a response to when certman_send_delete_all_cert_req is called.
    * 
    *  Possible Return Values :
    *   CERTMAN_ERR_NONE        :   Success
    *   CERTMAN_ERR_FS_ERROR    :   general file system error
    *
    * Direction: Certman -> APP
    * Local parameter: certman_delete_all_cert_cnf_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_DELETE_ALL_CERT_CNF,


    /* This primitive is used to request the certman to update cerificate key purpose by specified certificate ID.
    *  Please check the API : certman_send_update_key_purpose_req for detailed description
    *
    * Direction: APP -> Certman
    * Local parameter: certman_update_key_purpose_req_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_UPDATE_KEY_PURPOSE_REQ,


    /* This primitive will be sent as a response to when certman_send_update_key_purpose_req is called.
    * 
    *  Possible Return Values :
    *   CERTMAN_ERR_NONE                    :   Success
    *   CERTMAN_ERR_CERT_NOT_FOUND          :   can't find the certificate of specified ID.
    *   CERTMAN_ERR_INVALID_KEY_PURPOSE     :   key purpose setting error
    *
    * Direction: Certman -> APP
    * Local parameter: certman_update_key_purpose_cnf_struct
    * Peer buffer: None
    */
    MSG_ID_CERTMAN_UPDATE_KEY_PURPOSE_CNF,

    /* This primitive will be sent to certman to start OCSP verification when
	 * certman_ocsp_verify_cert() is called.
     * 
     * Direction: APP -> Certman
     * Local parameter: certman_ocsp_verify_cert_req_struct
     * Peer buffer: None
     */
    MSG_ID_CERTMAN_OCSP_VERIFY_CERT_REQ,
	
    /* This primitive will be sent as a response to application to report
	 * the OCSP validation status after corresponding to certman_ocsp_verify_cert().
     * 
     * Direction: Certman -> APP
     * Local parameter: certman_ocsp_verify_cert_cnf_struct
     * Peer buffer: None
     */
    MSG_ID_CERTMAN_OCSP_VERIFY_CERT_CNF,

/* DOM-NOT_FOR_SDK_BEGIN */

    MSG_ID_CERTMAN_EXPORT_REQ,
    MSG_ID_CERTMAN_EXPORT_CNF,
    MSG_ID_CERTMAN_IMPORT_USER_CERT,
    MSG_ID_CERTMAN_EXPORT_USER_PRIV_KEY,
    MSG_ID_CERTMAN_USER_CERT_RSP,
    MSG_ID_CERTMAN_CODE_END = MSG_ID_CERTMAN_USER_CERT_RSP,

/* DOM-NOT_FOR_SDK_END */

#ifdef __BUILD_DOM__
           } sap_certman_enum;
#endif /* __BUILD_DOM__ */
#endif /*_CERTMAN_SAP_H*/

/*------------ CERTMAN_MSG_CODE_END ---------------*/
