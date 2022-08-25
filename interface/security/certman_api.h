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
 *    certman_api.h
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
#ifndef CERTMAN_API_H
#define CERTMAN_API_H

#include "certman_struct.h"


/*************************************************************************
 * CERTMAN SERVICE READY SUBSCRIPTION -- INTERFACE FUNCTION
 ************************************************************************/

/*****************************************************************************
 * <GROUP certman_utility_funcs>
 *
 * FUNCTION
 *  certman_send_ready_mmi_req
 * DESCRIPTION
 *  This function is used to notify the ready notification from certman.
 * PARAMETERS
 *  src_mod    :   [IN]        Source module id of the subscriber.
 * RETURNS
 *  void
 *****************************************************************************/
void certman_send_ready_mmi_req(module_type src_mod);
/*****************************************************************************
 * <GROUP certman_utility_funcs>
 *
 * FUNCTION
 *  certman_send_ready_subscribe_req
 * DESCRIPTION
 *  This function is used to subscribe the ready notification from certman.
 * PARAMETERS
 *  src_mod    :   [IN]        Source module id of the subscriber.
 * RETURNS
 *  void
 *****************************************************************************/
void certman_send_ready_subscribe_req(module_type src_mod);


/*************************************************************************
 * PARSE LIBRARY APIs
 ************************************************************************/

/*****************************************************************************
 * <GROUP certman_parse_funcs>
 *
 * FUNCTION
 *  certman_ctx_parse_new_by_file
 * DESCRIPTION
 *  This API creates the parse context object based on the specified file.
 *  NOTE : 1. Caller must ensure to pass in the correct encoding type, and it is 
 *            strongly recommended to use the certman_parse_get_encoding_type_by_file API
 *            to determine the correct type as it also performs a quick check on 
 *            whether the content is supported or not.
 *         2. This API will do a quick check on whether the provided file exists, 
 *            if it is valid, and whether content is indeed supported. 
 *            Caller must be prepared to handle the error cases if encountered.
 *         3. When a PKCS #12 is to be parsed, application must ensure the password 
 *            protecting the file is obtained from the user. 
 *            The password must be set into parse context by certman_parse_set_decrypt_password API
 *            before a "certman_send_parse_begin_req" request can be sent to Certman.
 *         4. The lifetime of the parse context object only needs to last until 
 *            a "certman_send_parse_begin_req" request has sent to Certman, 
 *            and the parse context object must be released by application using 
 *            certman_ctx_parse_free API.
 *         5. Although caller may release the parse context object as soon as the 
 *            "certman_send_parse_begin_req" request is made, it is recommended though that 
 *            this request is released after the response to "certman_send_parse_begin_req" is replied from Certman,
 *            where application may check whether an error had occurred before the context is released. 
 *            This helps in scenario where PKCS #12 password is incorrect, 
 *            where the password input is required from user again and applications 
 *            will then not need to re-create the entire parse context from scratch, 
 *            and may simply replace the existing password in context with certman_parse_set_decrypt_password API.
 * PARAMETERS
 *  filename        :   [IN]        Specified file to be parsed (certman_send_parse_begin_req).
 *  file_encoding   :   [IN]        Encoding type of specified file (certman_encoding_enum).
 *  ctx_parse       :   [IN/OUT]    Certman parse context.
 * RETURN VALUES
 *  CERTMAN_ERR_NONE                :   Success
 *  CERTMAN_ERR_MEMFULL             :   Memory full error
 *  CERTMAN_ERR_FILE_NOT_FOUND      :   file not found or filename is NULL pointer
 *  CERTMAN_ERR_FS_ERROR            :   other file system errors
 *  CERTMAN_ERR_INVALID_ENCODING    :   unable to parse file with the specified encoding type
 *  CERTMAN_ERR_UNSUPPORTED_CONTENT :   file is parse-able but the content cannot be supported. (eg, private key exists in PEM file, PKCS#12 file with public-key integrity/privacy mode)
 * SEE ALSO
 *  certman_parse_get_encoding_type_by_file, certman_ctx_parse_free
 *****************************************************************************/
certman_error_enum certman_ctx_parse_new_by_file(
	            const kal_wchar *filename,
	            certman_encoding_enum file_encoding,
	            certman_ctx_parse_struct **ctx_parse);

/*****************************************************************************
 * <GROUP certman_parse_funcs>
 *
 * FUNCTION
 *  certman_ctx_parse_free
 * DESCRIPTION
 *  This function is to release the parse context object, must be called once a parse request has sent to Certman.
 * PARAMETERS
 *  ctx_parse      :   [IN]    Specified certman parse context.
 * RETURNS
 *  void
 *****************************************************************************/
void certman_ctx_parse_free(certman_ctx_parse_struct *ctx_parse);


/*****************************************************************************
 * <GROUP certman_parse_funcs>
 *
 * FUNCTION
 *  certman_parse_get_encoding_type_by_file
 * DESCRIPTION
 *  This API determines the correct encoding type of the specified file if it can be supported.
 *  NOTE : It is strongly recommended to use this API to determine the correct encoding type, 
 *         as it also performs a very quick check on whether the file can be supported, 
 *         and so user can be notified sooner if it is not.
 * PARAMETERS
 *  filename        :   [IN]        Specified file.
 *  encoding        :   [IN/OUT]    File encoding type output location (certman_encoding_enum).
 * RETURN VALUES
 *  CERTMAN_ERR_NONE                :   Success
 *  CERTMAN_ERR_MEMFULL             :   Memory full error
 *  CERTMAN_ERR_FILE_NOT_FOUND      :   file not found or filename is NULL pointer
 *  CERTMAN_ERR_FS_ERROR            :   other file system errors
 *  CERTMAN_ERR_UNSUPPORTED_CONTENT :   file is parse-able but the content cannot be supported. 
 *****************************************************************************/
certman_error_enum certman_parse_get_encoding_type_by_file(
	            const kal_wchar* filename,
	            certman_encoding_enum *encoding);

/*****************************************************************************
 * <GROUP certman_parse_funcs>
 *
 * FUNCTION
 *  certman_parse_set_decrypt_password
 * DESCRIPTION
 *  This API helps to set the password for decrypting the PKCS#12 file.
 *  NOTE : 1. if the specified file is protected by password, applications should 
 *            create parse context first by API : certman_ctx_parse_new_by_file, then
 *            set the associated password by API : certman_parse_set_decrypt_password
 *         2. The password must be zero-terminated ASCII string with no more than 
 *            CERTMAN_PASSWORD_LENGTH (32) characters.
 * PARAMETERS
 *  ctx_parse       :   [IN]    Source module id of the subscriber. 
 *  password        :   [IN]    Source module id of the subscriber.  
 * RETURN VALUES
 *  CERTMAN_ERR_NONE                :   Success
 *  CERTMAN_ERR_MEMFULL             :   Memory full error
 *  CERTMAN_ERR_INVALID_CONTEXT     :   NULL pointer, or context not correctly setup
 *  CERTMAN_ERR_INVALID_PASSWORD    :   password does not match the requirement
 *****************************************************************************/
certman_error_enum certman_parse_set_decrypt_password(
	            certman_ctx_parse_struct *ctx_parse,
	            const kal_uint8 *password);

/*****************************************************************************
 * <GROUP certman_parse_funcs>
 *
 * FUNCTION
 *  certman_parsed_data_free
 * DESCRIPTION
 *  This API is used to release the parsed data object.
 *  NOTE : Applications have to call this API to release the parsed data object after 
 *         receive the MSG_ID_CERTMAN_PARSE_CERT_DETAIL_CNF (This primitive will be sent 
 *         as a response to when certman_send_parse_cert_detail_req is called.
 * PARAMETERS
 *  parsed_data        :   [IN]     the specified parsed data object.
 * RETURNS
 *  void
 * SEE ALSO
 *  certman_send_parse_cert_detail_req
 *****************************************************************************/
void certman_parsed_data_free(certman_parsed_data_struct *parsed_data);

/*************************************************************************
 * PARSE INTERFACE FUNCTIONS
 ************************************************************************/

/*****************************************************************************
 * <GROUP certman_parse_funcs>
 *
 * FUNCTION
 *  certman_send_parse_begin_req
 * DESCRIPTION
 *  This interface function assists caller in sending a MSG_ID_CERTMAN_PARSE_BEGIN_REQ primitive to Certman.
 *  Caller should expect the response from MSG_ID_CERTMAN_PARSE_BEGIN_CNF primitive.
 *  NOTE : 1. This service begins the parse operation, on successful return of this service
 *            the "parsed_info" will be filled with statistical information such as 
 *            the number of certificates held within the file, and the referenced ID of each certificates in file
 *            for application to refer to obtain detailed information later on.
 *         2. The main purpose of this service is to traverse through the file and attempt to 
 *            locate all certificates (and keys if PKCS#12 file) and keep them within the Certman,
 *            each of the located certificates will be identified by a reference ID 
 *            which is made available to application in the returned "parsed_info" parameter,
 *            and application may retrieve the parsed certificate content by the 
 *            MSG_ID_CERTMAN_PARSE_CERT_DETAIL_REQ service.
 *         3. Caller must ensure the password is obtained from user if a PKCS #12 file 
 *            is to be parsed, failing to do so will result in Certman returning the 
 *            corresponding error cause. In the case when the obtained password is incorrect, 
 *            Certman returns CERTMAN_ERR_INCORRECT_PASSWORD in its response primitive and 
 *            no job will be created. This would require user to re-enter the password and 
 *            application needs to resend the "parse begin" operation again.
 *         4. As Certman keeps track of parse states on behalf of caller, therefore it is 
 *            crucial that caller triggers MSG_ID_CERTMAN_PARSE_END_REQ when all certificates 
 *            have imported, or user aborts or simply application has completed with the parse/import operation.
 *            Application is reminded to trigger MSG_ID_CERTMAN_PARSE_END_REQ when user aborts import operation including pressing END-Key. 
 * PARAMETERS
 *  src_mod     :   [IN]        Source module id of the caller application.
 *  trans_id    :   [IN]        Input transaction id from the caller applications.
 *  ctx_parse   :   [IN]        Specified parse context. 
 * RETURNS
 *  void
 * SEE ALSO
 *  certman_send_parse_cert_detail_req, certman_send_parse_end_req
 *****************************************************************************/
void certman_send_parse_begin_req(
                module_type src_mod,
	            kal_uint32 trans_id,
	            certman_ctx_parse_struct *ctx_parse);

/*****************************************************************************
 * <GROUP certman_parse_funcs>
 *
 * FUNCTION
 *  certman_send_parse_cert_detail_req
 * DESCRIPTION
 *  This interface function assists caller in sending a MSG_ID_CERTMAN_PARSE_DETAIL_REQ primitive to Certman. 
 *  Caller should expect the response from MSG_ID_CERTMAN_PARSE_DETAIL_CNF primitive.
 *  NOTE : 1. The purpose of this service is to get the parsed certificate data of the associated 
 *            parse job ("job_id") and the certificate reference ID.
 *         2. Certificate Management Application may display the information contained in 
 *            returned parsed_data to user, and acquire user's confirmation 
 *            before import this certificate to system. 
 *         3. Caller is reminded that the "parsed_data" does not use control buffer 
 *            nor part of local parameter's memory space, it is caller's responsibility 
 *            to release the "parsed_data" object by certman_parsed_data_free API 
 *            when it is no longer needed. The reason for this design is that 
 *            the caller may store the parsed_data object internally to provide a flexible UI representation. 
 *         4. It is possible that Certman finds the requested certificate exists in Certman's certificate database storage 
 *            (ie, already imported or predefined), and in such case, the MSG_ID_CERTMAN_PARSE_NEXT_CNF 
 *            will return error status, where Certificate Management Application may 
 *            need to show an error prompt to user, and prohibit user to import this certificate. 
 *         5. The "cert_exists" parameter within the "parsed_data" object specifies whether the 
 *            currently parsed certificate already exists in Certman's certificate database, 
 *            application may wish to warn user and must not allow user to install this certificate 
 *            if this flag has been set.
 * PARAMETERS
 *  src_mod     :   [IN]        Source module id of the caller application.
 *  trans_id    :   [IN]        Input transaction id from the caller applications.
 *  job_id      :   [IN]        Associated certman job id (from parse_begin_cnf)
 *  cert_ref_id :   [IN]        Associated certificate reference id (from parse_begin_cnf)
 * RETURNS
 *  void
 * SEE ALSO
 *  certman_send_parse_begin_req, certman_send_parse_end_req
 *****************************************************************************/
void certman_send_parse_cert_detail_req(
	            module_type src_mod,
	            kal_uint32 trans_id,
	            kal_uint16 job_id,
	            kal_uint32 cert_ref_id);

/*****************************************************************************
 * <GROUP certman_parse_funcs>
 *
 * FUNCTION
 *  certman_send_parse_end_req
 * DESCRIPTION
 *  This interface function assists caller in sending a MSG_ID_CERTMAN_PARSE_END_REQ primitive to Certman.
 *  Caller should expect the response from MSG_ID_CERTMAN_PARSE_END_CNF primitive.
 *  NOTE : This service will release the parse states of the associated "job_id" in Certman,
 *         once this request is made, caller must not make any further parse/import requests with this "job_id".
 * PARAMETERS
 *  src_mod    :   [IN]     Source module id of the caller application.
 *  trans_id   :   [IN]     Input transaction id from the caller applications.
 *  job_id     :   [IN]     Associated certman job id (from parse_begin_cnf). 
 * RETURNS
 *  void
 * SEE ALSO
 *  certman_send_parse_begin_req, certman_send_parse_cert_detail_req 
 *****************************************************************************/
void certman_send_parse_end_req(
	            module_type src_mod,
	            kal_uint32 trans_id,
	            kal_uint16 job_id);


/*************************************************************************
 * IMPORT LIBRARY APIs
 ************************************************************************/

/*****************************************************************************
 * <GROUP certman_import_funcs>
 *
 * FUNCTION
 *  certman_ctx_import_new
 * DESCRIPTION
 *  This API is used to create a new import context object when a parsed certificate is to be imported to system.
 *  NOTE : 1. This API takes the parse job ID as generated by Certman and provided to application through MSG_ID_CERTMAN_PARSE_BEGIN_REQ/CNF service,
 *            it also takes in a certificate reference ID, which is provided to application through the MSG_ID_CERTMAN_PARSE_CERT_DETAIL_REQ/CNF service.
 *            The combination of these 2 IDs allows Certman to identify which certificate of which parse context (ie, the data source, or file) that the certificate should be imported.
 *         2. The lifetime of the created context only needs to exist until this import request is sent to Certman.
 *            Caller must use certman_ctx_import_free API to release the import context object either when it is no longer needed, or after the request has sent. 
 *         3. Caller must ensure all necessary information is obtained from user before an import request is made:
 *            (1)Unique label must be set for ALL certificates: certman_import_set_label, and certman_import_check_label_exists API
 *            (2)Additional information for personal certificates: private key protection method certman_import_set_privkey_protection, 
 *            (3)and private key exportability : certman_import_set_privkey_exportable.
 *         4. Once all inputs are gathered, caller may send this request to Certman using certman_send_import_req interface function. Caller may destroy the import context at this point if needs to, as the request is made with message primitive approach, all required data is copy onto the local parameter.
 *         5. The interface function helps to extract the necessary data from import context and constructs a valid import request.
 *            Please be aware that import request is the only method available currently for importing a certificate (and private key) into system, 
 *            and a new import request (and import context) must be created for each certificate to be imported.
 * PARAMETERS
 *  parse_job_id    :   [IN]     Associated certman parse job id.
 *  cert_ref_id     :   [IN]     Specified certificate reference id in associated parse job.
 *  ctx_import      :   [IN\OUT] Import context output location
 * RETURN VALUES
 *  CERTMAN_ERR_NONE    : Success
 *  CERTMAN_ERR_MEMFULL : Memory full error
 * SEE ALSO
 *  certman_ctx_import_free, certman_import_set_label, certman_import_check_label_exists,
 *  certman_import_set_privkey_protection, certman_import_set_privkey_exportable,
 *  certman_send_import_req
 *****************************************************************************/
certman_error_enum certman_ctx_import_new(
	            kal_uint16 parse_job_id,
	            kal_uint32 cert_ref_id,
	            certman_ctx_import_struct **ctx_import);

/*****************************************************************************
 * <GROUP certman_import_funcs>
 *
 * FUNCTION
 *  certman_ctx_import_free
 * DESCRIPTION
 *  This API is used to release the import context object. 
 *  This context can be released as soon as an import request is sent to Certman.
 * PARAMETERS
 *  ctx_import     :   [IN] Specified import context.
 * RETURNS
 *  void
 * SEE ALSO
 *  certman_ctx_import_new
 *****************************************************************************/
void certman_ctx_import_free(certman_ctx_import_struct *ctx_import);

/*****************************************************************************
 * <GROUP certman_import_funcs>
 *
 * FUNCTION
 *  certman_import_check_label_exists
 * DESCRIPTION
 *  This API checks whether the label has already existed. 
 *  The label must be zero-terminated string, with encoding type specified by "dcs" parameter 
 *  (ie, ASCII or UCS2). Caller must ensure the number of ASCII character does not exceed 
 *  CERTMAN_LABEL_LENGTH (64) characters, and half of the size (32) for UCS2 characters.
 * PARAMETERS
 *  label   :   [IN]     Specified label string.
 *  dcs     :   [IN]     Encoding scheme identifier (certman_dcs_enum).
 * RETURN VALUES
 *  CERTMAN_ERR_NONE            :   label not found
 *  CERTMAN_ERR_LABEL_EXISTS    :   label already exists
 *  CERTMAN_ERR_INVALID_LABEL   :   the label parameter is a NULL pointer or empty value or exceeds the limited size
 * SEE ALSO
 *  certman_import_set_label, certman_ctx_import_new 
 *****************************************************************************/
certman_error_enum certman_import_check_label_exists(
	            const kal_uint8 *label,
	            certman_dcs_enum dcs);

/*****************************************************************************
 * <GROUP certman_import_funcs>
 *
 * FUNCTION
 *  certman_import_set_label
 * DESCRIPTION
 *  This API is used to add a certificate label to the context object.
 *  NOTE : 1. The label must be obtained from user for each of the certificate to be imported, 
 *            and caller must ensure the label is unique by using this check function certman_import_check_label_exists,
 *            and may trigger this function again to replace the new label with the previously added label.
 *         2. The label must be zero-terminated string, with encoding type specified by "dcs" parameter (ie, ASCII or UCS2). 
 *            Caller must ensure the number of ASCII character does not exceed CERTMAN_LABEL_LENGTH (64) characters, and half of the size (32) for UCS2 characters.
 * PARAMETERS
 *  ctx_import  :   [IN]     Specified import context.
 *  label       :   [IN]     Specified label string.
 *  dcs         :   [IN]     Encoding scheme identifier of label string (certman_dcs_enum)
 * RETURNS
 *  void
 * SEE ALSO
 *  certman_ctx_import_new, certman_import_check_label_exists 
 *****************************************************************************/
certman_error_enum certman_import_set_label(
	            certman_ctx_import_struct *ctx_import,
	            const kal_uint8 *label,
	            certman_dcs_enum dcs);

/*****************************************************************************
 * <GROUP certman_import_funcs>
 *
 * FUNCTION
 *  certman_import_set_privkey_protection
 * DESCRIPTION
 *  This API is used to add the private key protection method to the context object. 
 *  NOTE : 1. This option must be made available to user whenever importing a personal certificate, 
 *            and currently 3 types of protection methods are supported:
 *            (1)CERTMAN_PROTECT_NONE :
 *                  key stored in Certman password protected storage, and usage of key is transparent to user
 *            (2)CERTMAN_PROTECT_USAGE_CONFIRM :
 *                  key stored in Certman password protected storage, and confirmation from user is required when this key is to be used
 *            (3)CERTMAN_PROTECT_USAGE_PASSWORD :
 *                  key storage protected by user specified password, and the password is required from user when this key is to be used.
 *         2. Caller must ensure the user specifies a password when the protection method is CERTMAN_PROTECT_USAGE_PASSWORD. 
 *            As for the other two types of protection methods (CERTMAN_PROTECT_NONE and CERTMAN_PROTECT_USAGE_CONFIRM), 
 *            no password is needed and application must not prompt user for such information.
 *         3. When the password is required, caller must ensure that the password is 
 *            a zero-terminated ASCII string and cannot be NULL or empty value. 
 *            The maximum number of characters of a password is defined by CERTMAN_PASSWORD_LENGTH (32).
 *         4. If this API is not triggered, Certman by default assumes CERTMAN_PROTECT_NONE. 
 * PARAMETERS
 *  ctx_import      :   [IN]     Specified import context.
 *  protect_method  :   [IN]     Specified key protection mode (certman_privkey_protection_enum).
 *  password        :   [IN]     Associated password (necessary if CERTMAN_PROTECT_USAGE_PASSWORD).
 * RETURN VALUES
 *  CERTMAN_ERR_NONE                :   Success
 *  CERTMAN_ERR_MEMFULL             :   Memory full error
 *  CERTMAN_ERR_INVALID_CONTEXT     :   NULL pointer, or context not correctly setup
 *  CERTMAN_ERR_INVALID_PASSWORD    :   password does not match the requirement
 * SEE ALSO
 *  certman_ctx_import_new
 *****************************************************************************/
certman_error_enum certman_import_set_privkey_protection(
	            certman_ctx_import_struct *ctx_import,
	            certman_privkey_protection_enum protect_method,
	            const kal_uint8 *password);

/*****************************************************************************
 * <GROUP certman_import_funcs>
 *
 * FUNCTION
 *  certman_import_set_privkey_exportable
 * DESCRIPTION
 *  This API is used to specify whether the private key of the associated personal certificate can be exported later on. 
 *  NOTE : 1. This option must be made to user on importing of a personal certificate. 
 *         2. By default, Certman allows exportation of private key if this API is not triggered.
 * PARAMETERS
 *  ctx_import  :   [IN]     Specified import context.
 *  exportable  :   [IN]     Specified export setting, 0 = cannot be exported later on and 1 = private key export allowed.
 * RETURN VALUES
 *  CERTMAN_ERR_NONE                :   Success
 *  CERTMAN_ERR_INVALID_CONTEXT     :   NULL pointer, or context not correctly setup
 *  CERTMAN_ERR_OUT_OF_RANGE        :   exportable is not 0 or 1
 * SEE ALSO
 *  certman_ctx_import_new 
 *****************************************************************************/
certman_error_enum certman_import_set_privkey_exportable(
	            certman_ctx_import_struct *ctx_import,
	            kal_uint8 exportable);


/*************************************************************************
 * IMPORT INTERFACE FUNCTIONS
 ************************************************************************/

/*****************************************************************************
 * <GROUP certman_import_funcs>
 *
 * FUNCTION
 *  certman_send_import_req
 * DESCRIPTION
 *  This interface function assists caller in sending a MSG_ID_CERTMAN_IMPORT_REQ primitive to Certman. 
 *  Caller should expect the response from MSG_ID_CERTMAN_IMPORT_CNF primitive.
 *  NOTE : 1. This API transforms the import context object to the primitive based import request 
 *            and has this request sent to Certman for certificate processing and storage. 
 *         2. Provided that all required information had provided by caller, Certman should save the certificate without problem 
 *            unless it is a file I/O related issue. 
 *         3. The caller is reminded to release the import context object by certman_ctx_import_free API 
 *            after this API is triggered to avoid memory leaks.
 * PARAMETERS
 *  src_mod         :   [IN]     Source module id of the caller application.
 *  trans_id        :   [IN]     Input transaction id from the caller applications.
 *  ctx_import      :   [IN]     Associated import context.
 * RETURNS
 *  void
 * SEE ALSO
 *  certman_ctx_import_new, certman_ctx_import_free 
 *****************************************************************************/
void certman_send_import_req(
	            module_type src_mod,
	            kal_uint32 trans_id,
	            const certman_ctx_import_struct *ctx_import);


/*************************************************************************
 * RETRIEVE LIBRARY APIs
 ************************************************************************/

/*****************************************************************************
 * <GROUP certman_retrieve_funcs>
 *
 * FUNCTION
 *  certman_get_cert_ids_by_type
 * DESCRIPTION
 *  This interface function assists caller to query the certificate ID list by specified type
 *  Currently only support quering maximum CERTMAN_NUM_ID_IN_LIST number of certificate ID list.
 * PARAMETERS
 *  type    :   [IN]    specified certificate type (certman_certtype_enum).
 *  ids_qry :   [IN/OUT]    query result output location.
 * RETURNS
 *  void
 *****************************************************************************/
void certman_get_cert_ids_by_type(
                certman_certtype_enum type,
	            certman_cert_ids_result_struct *ids_qry);

/*****************************************************************************
 * <GROUP certman_retrieve_funcs>
 *
 * FUNCTION
 *  certman_get_cert_count
 * DESCRIPTION
 *  This API allows caller to retrieve the number of certificates in system satisfying the requirements.
 *  NOTE : 1. The "cert_group" and "key_purpose" parameters must be a value concatenated from 
 *            "certman_cert_group_enum" and "certman_keypurpose_enum" respectively. 
 *         2. Caller may use "CERTMAN_CERTGRP_NONE" and "CERTMAN_KP_NONE" if the parameters are not required.
 *         3. Caller must ensure Certman task is ready before using this API, 
 *            failure to do so will result in function returning a value of 0.
 * PARAMETERS
 *  cert_group  :   [IN]     specified certificate groups (certman_cert_group_enum).
 *  key_purpose :   [IN]     specified key purposes (certman_keypurpose_enum).
 * RETURNS
 *  number of certificates satisfying requirements
 *****************************************************************************/
kal_uint32 certman_get_cert_count(
	            kal_uint32 cert_group,
	            kal_uint32 key_purpose);

/*****************************************************************************
 * <GROUP certman_retrieve_funcs>
 *
 * FUNCTION
 *  certman_get_cert_label
 * DESCRIPTION
 *  retrieves certificate label given the specified certificate ID
 * PARAMETERS
 *  cert_id         :   [IN]        ID of the certificate label to retrieve
 *  label_buffer    :   [IN\OUT]    buffer provided by caller in which label will be filled into
 *  bufsize         :   [IN]        buffer size (the number of usable bytes in buffer, include zero-terminate)
 *  dcs_out         :   [IN\OUT]    identifies label's DCS param (ie, whether string in label_buffer is ASCII or UCS2)
 * RETURN VALUES
 *  CERTMAN_ERR_NONE            :   Success
 *  CERTMAN_ERR_CERT_NOT_FOUND  :   can't find out the certificate in database by specified id
 *****************************************************************************/
certman_error_enum certman_get_cert_label(
	            kal_uint32 cert_id,
	            kal_uint8 *label_buffer,
	            kal_uint32 bufsize,
	            certman_dcs_enum *dcs_out);

/*****************************************************************************
 * <GROUP certman_retrieve_funcs>
 *
 * FUNCTION
 *  certman_cert_display_content_free
 * DESCRIPTION
 *  This API helps caller to release the contents held within a certificate display object.
 *  NOTE : This API is generally used to release the display object as obtained from MSG_ID_CERTMAN_GET_CERT_DISP_BY_ID_CNF,
 *         and only the contents (ie, serial number, subject and issuer name) will be released as these occupies memory, 
 *         the display object itself is not released because it is not required to do so.
 * PARAMETERS
 *  cert_disp       :   [IN]    Specified certificate display object.
 * RETURNS
 *  void
 *****************************************************************************/
void certman_cert_display_content_free(certman_cert_display_struct *cert_disp);


/*************************************************************************
 * RETRIEVE INTERFACE FUNCTIONS -- List and Display Info
 ************************************************************************/

/*****************************************************************************
 * <GROUP certman_retrieve_funcs>
 *
 * FUNCTION
 *  certman_send_get_cert_list_by_group_req
 * DESCRIPTION
 *  This interface function assists caller in sending a MSG_ID_CERTMAN_GET_CERT_LIST_BY_GROUP_REQ primitive to Certman. 
 *  Caller should expect the data to be returned through the MSG_ID_CERTMAN_GET_CERT_LIST_BY_GROUP_CNF primitive.
 *  NOTE : 1. The "cert_group" parameter defines the group(s) of certificates that are in caller's interests.
 *            Multiple groups can be concatenated together by the OR operation, 
 *            ie, if the certificate info of all Root CA and Intermediate CA are required, 
 *            cert_group may be set to a value of CERTMAN_CERTGRP_ROOTCA | CERTMAN_CERTGRP_CA.
 *         2. The "key_purpose" parameter defines the certificate usage purpose where it must match for 
 *            a hit to occur. Application wishing to specifying more than 1 purposes may concatenate the 
 *            values together with OR operation. Application is allowed to specify CERTMAN_KP_NONE in this 
 *            retrieval request as no public key will be made available in its response primitive.
 *         3. The "more" parameter must match the value of "more" from the MSG_ID_CERTMAN_GET_CERT_LIST_BY_GROUP_CNF primitive,
 *            and caller should pass in 0 on initial request for Certman to return list of certificate info from the beginning. 
 *            The returned data will be sorted in alphabetical order of labels.
 * PARAMETERS
 *  src_mod         :   [IN]    Source module id of the caller application.
 *  trans_id        :   [IN]    Transaction id from the caller applications.
 *  cert_group      :   [IN]    specified certificate groups (certman_cert_group_enum).
 *  key_purpose     :   [IN]    specified key purposes (certman_keypurpose_enum).
 *  more            :   [IN]    index flag for cert list query, first time query is 0, then use the value from MSG_ID_CERTMAN_GET_CERT_LIST_BY_GROUP_CNF to fetch other certs until all certs being retrieved
 * RETURNS
 *  void
 * SEE ALSO
 *  certman_send_get_cert_list_by_domain_req, certman_send_get_certid_by_group_req
 *****************************************************************************/
void certman_send_get_cert_list_by_group_req(
	            module_type src_mod,
            	kal_uint32 trans_id,
            	kal_uint32 cert_group,
            	kal_uint32 key_purpose,
            	kal_uint32 pubkey_type,
            	kal_uint32 more);

/*****************************************************************************
 * <GROUP certman_retrieve_funcs>
 *
 * FUNCTION
 *  certman_send_get_cert_list_by_domain_req
 * DESCRIPTION
 *  This interface function assists caller in sending a MSG_ID_CERTMAN_GET_CERT_LIST_BY_DOMAIN_REQ primitive to Certman. 
 *  Caller should expect the data to be returned through the MSG_ID_CERTMAN_GET_CERT_LIST_BY_DOMAIN_CNF primitive.
 *  NOTE : 1. The "domain" parameter defines the domain(s) of certificate that are in caller's interests.
 *            Multiple domains can be concatenated together by the OR operation, 
 *            ie, if the certificate info of all Operator and Manufacturer domains are required, 
 *            domain may be set to a value of CERTMAN_DOMAIN_OPERATOR | CERTMAN_DOMAIN_MANUFACTURER.
 *         2. The "key_purpose" parameter defines the certificate usage purpose where it must match for a hit to occur. 
 *            Application wishing to specifying more than 1 purposes may concatenate the values together with OR operation. 
 *            Application is allowed to specify CERTMAN_KP_NONE in this retrieval request as no public key will be made available in its response primitive.
 *         3. The "more" parameter must match the value of "more" from the MSG_ID_CERTMAN_GET_CERT_LIST_BY_DOMAIN_CNF primitive, 
 *            and caller should pass in 0 on initial request for Certman to return list of info from the beginning. The returned data will be sorted in alphabetical order of labels.
 * PARAMETERS
 *  src_mod         :   [IN]    Source module id of the caller application.
 *  trans_id        :   [IN]    Transaction id from the caller applications.
 *  domain          :   [IN]    specified certificate domains (certman_domain_enum).
 *  key_purpose     :   [IN]    specified key purposes (certman_keypurpose_enum).
 *  more            :   [IN]    index flag for cert list query, first time query is 0, then use the value from MSG_ID_CERTMAN_GET_CERT_LIST_BY_DOMAIN_CNF to fetch other certs until all certs being retrieved
 * RETURNS
 *  void
 * SEE ALSO
 *  certman_send_get_cert_list_by_group_req 
 *****************************************************************************/
void certman_send_get_cert_list_by_domain_req(
            	module_type src_mod,
            	kal_uint32 trans_id,
            	kal_uint32 domain,
            	kal_uint32 key_purpose,
            	kal_uint32 more);

/*****************************************************************************
 * <GROUP certman_retrieve_funcs>
 *
 * FUNCTION
 *  certman_send_get_cert_list_by_issuers_file_req
 * DESCRIPTION
 *  This interface function assists caller in sending a MSG_ID_CERTMAN_GET_CERT_LIST_BY_ISSUERS_FILE_REQ primitive to Certman. 
 *  Caller should expect the result of this request to be returned via MSG_ID_CERTMAN_GET_CERT_LIST_BY_ISSUERS_FILE_CNF primitive,
 *  and should the request succeeded, the matched certificate will be returned via the one or more MSG_ID_CERTMAN_GET_CERT_LIST_BY_ISSUERS_DATA_IND primitive.
 *  NOTE : 1. This request will return certificate information matching the specified certificate group and key purpose. 
 *            In addition, the issuer names of the certificate validation chain by matched certificate 
 *            must be one of the issuer name described within the issuers name file provided.
 *         2. In fact, this is a special API for supporting client certficiate authentication. 
 *         3. The "cert_group" parameter defines the group(s) of certificates that are in caller's interests.
 *            Multiple groups can be concatenated together by the OR operation, 
 *            ie, if the certificate info of all Root CA and Intermediate CA are required, 
 *            cert_group may be set to a value of CERTMAN_CERTGRP_ROOTCA | CERTMAN_CERTGRP_CA.
 *         4. The "key_purpose" parameter defines the certificate usage purpose where it must match for 
 *            a hit to occur. Application wishing to specifying more than 1 purposes may concatenate the 
 *            values together with OR operation. Application is allowed to specify CERTMAN_KP_NONE in this 
 *            retrieval request as no public key will be made available in its response primitive. 
 *         5. The "issuers_filename" parameter defines the filename where the issuers name could be located. 
 *            This parameter must not be set to NULL or an empty string and CertMan will not be deleting this file 
 *            when its operation has completed, caller has full ownership of the file itself. 
 *            Caller may delete the file should it chooses to as soon as it receives MSG_ID_CERTMAN_GET_CERT_LIST_BY_ISSUERS_FILE_CNF primitive.
 *         6. The format of the issuers' name file is defined as follows:
 *            |<---- 2 --->|<--- sizenum of bytes -->| ...
 *            |Entry size 1|DER encoded issuer name 1|Entry size 2|DER encoded issuer name 2|
 *            |Entry size 3|DER encoded issuer name 3|Entry size 4|DER encoded issuer name 4|
 *            | .....
 *            Basically, it's a multiple entries of issuers' name where each entry is a concatenation of a "size" (2 bytes) 
 *            followed by a DER encoded name data and no header such as "number of entries" or footer such as "the end of record" is required.
 *         7. As the number of issuers in file and the number of matching certificates cannot be predetermined, 
 *            the returning of certificate list information back to the application may need to be done through 
 *            a series of primitives depending on the number of certificates found.
 *            The primitive that CertMan uses in transferring the data back to application is done 
 *            via MSG_ID_CERTMAN_GET_CERT_LIST_BY_ISSUERS_DATA_IND, 
 *            where each data indication primitive is capable of storing CERTMAN_NUM_CERT_IN_LIST number 
 *            of certificates information. The total number of matched certificates is returned during 
 *            MSG_ID_CERTMAN_GET_CERT_LIST_BY_ISSUERS_FILE_CNF for application to prepare sufficient memory 
 *            for the data to come, and the end of data indication primitives will be identified 
 *            by the "last" parameter in the MSG_ID_CERTMAN_GET_CERT_LIST_BY_ISSUERS_DATA_IND's local parameter.
 *         8. The "pubkey_types" parameter defines the public key types filters,
 *            Applications may use OR operation for certman_pubkey_type_enum to set public key requirements.
 *            And the "num_types" defines the total number of pubkey requirements being set by applications.
 * PARAMETERS
 *  src_mod             :   [IN]    Source module id of the caller application.
 *  trans_id            :   [IN]    Input transaction id from the caller applications.
 *  cert_group          :   [IN]    specified certificate groups (certman_cert_group_enum).
 *  key_purpose         :   [IN]    specified key purposes (certman_keypurpose_enum).
 *  pubkey_types        :   [IN]    specified public key types (certman_pubkey_type_enum).
 *  num_types           :   [IN]    the number of specified public key types in pubkey_types array.
 *  issuers_filename    :   [IN]    specified issuer names file.
 * RETURNS
 *  void
 *****************************************************************************/
void certman_send_get_cert_list_by_issuers_file_req(
            	module_type src_mod,
            	kal_uint32 trans_id,
            	kal_uint32 cert_group,
            	kal_uint32 key_purpose,
            	kal_uint8 pubkey_types[CERTMAN_NUM_KEYTYPE_IN_LIST],    /* certman_pubkey_type_enum */
            	kal_uint8 num_types,
            	const kal_wchar *issuers_filename);

/*****************************************************************************
 * <GROUP certman_retrieve_funcs>
 *
 * FUNCTION
 *  certman_send_get_cert_disp_by_id_req
 * DESCRIPTION
 *  This interface function assists caller in sending a MSG_ID_CERTMAN_GET_CERT_DISP_BY_ID_REQ primitive to Certman. 
 *  Caller should expect the data to be returned through MSG_ID_CERTMAN_GET_CERT_DISP_BY_ID_CNF primitive. 
 *  NOTE : 1. The returned data of this request will primarily be used for certificate display, and so the included parameters are limited. 
 *         2. The returned certificate display content should be released by caller using certman_cert_display_content_free API.
 * PARAMETERS
 *  src_mod     :   [IN]     Source module id of the caller application.
 *  trans_id    :   [IN]     Input transaction id from the caller applications.
 *  cert_id     :   [IN]     specified certificate id.
 * RETURNS
 *  void
 * SEE ALSO
 *  certman_send_get_cert_chain_disp_by_id_req, certman_send_get_cert_by_id_req, 
 *  certman_cert_display_content_free
 *****************************************************************************/
void certman_send_get_cert_disp_by_id_req(
            	module_type src_mod,
            	kal_uint32 trans_id,
            	kal_uint32 cert_id);

/*****************************************************************************
 * <GROUP certman_retrieve_funcs>
 *
 * FUNCTION
 *  certman_send_get_cert_chain_disp_by_id_req
 * DESCRIPTION
 *  This interface function assists caller in sending a MSG_ID_CERTMAN_GET_CERT_CHAIN_DISP_BY_ID_REQ primitive to Certman.
 *  Caller should expect the data to be returned through MSG_ID_CERTMAN_GET_CERT_CHAIN_DISP_BY_ID_CNF primitive. 
 *  NOTE : The returned data of this request will primarily be used for certificate chain display, 
 *         where only the labels of each of the predecessors in the chain starting from the requested certificate will be returned.
 * PARAMETERS
 *  src_mod     :   [IN]     Source module id of the caller application.
 *  trans_id    :   [IN]     Input transaction id from the caller applications.
 *  cert_id     :   [IN]     specified certificate id.
 * RETURNS
 *  void
 *****************************************************************************/
void certman_send_get_cert_chain_disp_by_id_req(
            	module_type src_mod,
            	kal_uint32 trans_id,
            	kal_uint32 cert_id);


/*************************************************************************
 * RETRIEVE INTERFACE FUNCTIONS -- Certificate IDs
 ************************************************************************/

/*****************************************************************************
 * <GROUP certman_retrieve_funcs>
 *
 * FUNCTION
 *  certman_send_get_certid_by_group_req
 * DESCRIPTION
 *  This interface function assists caller in sending a MSG_ID_CERTMAN_GET_CERTID_BY_GROUP_REQ primitive to Certman. 
 *  Caller should expect the data to be returned through the MSG_ID_CERTMAN_GET_CERTID _BY_GROUP_CNF primitive. 
 *  NOTE : 1. The "cert_group" parameter defines the group(s) of certificates that are in caller's interests.
 *            Multiple groups can be concatenated together by the OR operation, 
 *            ie, if the certificate info of all Root CA and Intermediate CA are required, 
 *            cert_group may be set to a value of CERTMAN_CERTGRP_ROOTCA | CERTMAN_CERTGRP_CA.
 *         2. The "key_purpose" parameter defines the certificate usage purpose where it must match for 
 *            a hit to occur. Application wishing to specifying more than 1 purposes may concatenate the 
 *            values together with OR operation. Application is allowed to specify CERTMAN_KP_NONE in this 
 *            retrieval request as no public key will be made available in its response primitive.
 *         3. The "more" parameter must match the value of "more" from the MSG_ID_CERTMAN_GET_CERT_LIST_BY_GROUP_CNF primitive,
 *            and caller should pass in 0 on initial request for Certman to return list of certificate info from the beginning. 
 *            The returned data will be sorted in alphabetical order of labels.
 * PARAMETERS
 *  src_mod         :   [IN]    Source module id of the caller application.
 *  trans_id        :   [IN]    Transaction id from the caller applications.
 *  cert_group      :   [IN]    specified certificate groups (certman_cert_group_enum).
 *  key_purpose     :   [IN]    specified key purposes (certman_keypurpose_enum).
 *  more            :   [IN]    index flag for cert list query, first time query is 0, then use the value from MSG_ID_CERTMAN_GET_CERT_LIST_BY_GROUP_CNF to fetch other certs until all certs being retrieved
 * RETURNS
 *  void
 * SEE ALSO
 *  certman_send_get_certid_by_domain_req, certman_send_get_cert_list_by_group_req
 *****************************************************************************/
void certman_send_get_certid_by_group_req(
            	module_type src_mod,
            	kal_uint32 trans_id,
            	kal_uint32 cert_group,
            	kal_uint32 key_purpose,
            	kal_uint32 more);

/*****************************************************************************
 * <GROUP certman_retrieve_funcs>
 *
 * FUNCTION
 *  certman_send_get_certid_by_domain_req
 * DESCRIPTION
 *  This interface function assists caller in sending a MSG_ID_CERTMAN_GET_CERTID_BY_DOMAIN_REQ primitive to Certman. 
 *  Caller should expect the data to be returned through the MSG_ID_CERTMAN_GET_CERTID _BY_DOMAIN_CNF primitive.
 *  NOTE : 1. The "domain" parameter defines the domain(s) of certificate that are in caller's interests.
 *            Multiple domains can be concatenated together by the OR operation, 
 *            ie, if the certificate info of all Operator and Manufacturer domains are required, 
 *            domain may be set to a value of CERTMAN_DOMAIN_OPERATOR | CERTMAN_DOMAIN_MANUFACTURER.
 *         2. The "key_purpose" parameter defines the certificate usage purpose where it must match for a hit to occur. 
 *            Application wishing to specifying more than 1 purposes may concatenate the values together with OR operation. 
 *            Application is allowed to specify CERTMAN_KP_NONE in this retrieval request as no public key will be made available in its response primitive.
 *         3. The "more" parameter must match the value of "more" from the MSG_ID_CERTMAN_GET_CERT_LIST_BY_DOMAIN_CNF primitive, 
 *            and caller should pass in 0 on initial request for Certman to return list of info from the beginning. The returned data will be sorted in alphabetical order of labels.
 * PARAMETERS
 *  src_mod         :   [IN]    Source module id of the caller application.
 *  trans_id        :   [IN]    Transaction id from the caller applications.
 *  domain          :   [IN]    specified certificate domains (certman_domain_enum).
 *  key_purpose     :   [IN]    specified key purposes (certman_keypurpose_enum).
 *  more            :   [IN]    index flag for cert list query, first time query is 0, then use the value from MSG_ID_CERTMAN_GET_CERT_LIST_BY_DOMAIN_CNF to fetch other certs until all certs being retrieved
 * RETURNS
 *  void
 * SEE ALSO
 *  certman_send_get_certid_by_group_req, certman_send_get_cert_list_by_domain_req 
 *****************************************************************************/
void certman_send_get_certid_by_domain_req(
            	module_type src_mod,
            	kal_uint32 trans_id,
            	kal_uint32 domain,
            	kal_uint32 key_purpose,
            	kal_uint32 more);


/*************************************************************************
 * RETRIEVE INTERFACE FUNCTIONS -- Certificate + Private Key Data Through File
 ************************************************************************/

/*****************************************************************************
 * <GROUP certman_retrieve_funcs>
 *
 * FUNCTION
 *  certman_send_get_cert_by_id_req
 * DESCRIPTION
 *  This interface function assists caller in sending a MSG_ID_CERTMAN_GET_CERT_BY_ID_REQ primitive to Certman. 
 *  Caller should expect the data to be returned through MSG_ID_CERTMAN_GET_CERT_BY_ID_CNF primitive.
 *  NOTE : 1. Certman will generate a new file for each request and have the requested certificate placed in this file. 
 *         2. The file path will be returned to caller through the response primitive, 
 *            and caller is expected to delete the file when it is no longer needed. 
 *         3. If the "output_dir" parameter is NULL, the file will be located within Certman's temp folder under system drive, and this folder will be cleaned by Certman during each bootup.
 *         4. In the case when a personal certificate is to be retrieved, the MSG_ID_CERTMAN_GET_CERT_BY_ID_CNF will return the certificate data only, 
 *            caller must use the MSG_ID_CERTMAN_GET_PRIVKEY_REQ primitive with the same certificate ID to request for its private key.
 *         5. Currently for this service, Certman only allows an encoding type of either 
 *            CERTMAN_ENC_DER or CERTMAN_ENC_PEM as these are found to be the only formats required in either protocol usage, or internally within applications' scopes.
 *         6. The "key_purpose" parameter defines the certificate usage purpose where it must match for a hit to occur. 
 *            Application wishing to specifying more than 1 purposes may concatenate the values together with OR operation. 
 *            Application is strictly disallowed to specify CERTMAN_KP_NONE in this retrieval request as using this service means application intends to operate on certificate's public key.
 *         7. The "output_dir" parameter specifies the output directory of the generated file. 
 *            Caller must ensure that this is a full path including the drive letter and a final slash "\" character at the end of path.
 * PARAMETERS
 *  src_mod         :   [IN]    Source module id of the caller application.
 *  trans_id        :   [IN]    Input transaction id from the caller applications.
 *  cert_id         :   [IN]    Specified certificate id.
 *  encoding        :   [IN]    Specified certificate output encoding type (certman_encoding_enum).
 *  key_purpose     :   [IN]    Specified key purposes (certman_keypurpose_enum).
 *  output_dir      :   [IN]    The specified output directory.
 * RETURNS
 *  void
 *****************************************************************************/
void certman_send_get_cert_by_id_req(
            	module_type src_mod,
            	kal_uint32 trans_id,
            	kal_uint32 cert_id,
            	certman_encoding_enum encoding,
            	kal_uint32 key_purpose,
            	const kal_wchar *output_dir);

/*****************************************************************************
 * <GROUP certman_retrieve_funcs>
 *
 * FUNCTION
 *  certman_send_get_trusted_cert_by_id_req
 * DESCRIPTION
 *  This interface function assists caller in sending a MSG_ID_CERTMAN_GET_TRUSTED_CERT_BY_ID_REQ primitive to Certman. 
 *  Caller should expect the data to be returned through MSG_ID_CERTMAN_GET_TRUSTED_CERT_BY_ID_CNF primitive.
 *  NOTE : 1. This API is used to load the link files of trusted certificates.
 *         2. If applications need to prepare a trusted certificate folder by specified requirements.
 *            Then use the prepared folder to perform certificate validation process.
 *            Applications can use this API to load the link files of trusted certificates in certman database.
 *         3. Due to the certman and PKI database can only support folder with link files
 *            doesn't support the folder with real certificates. 
 *            Applications are reminded that the API should be used to prepare the trusted folder.
 *         4. The "key_purpose" parameter defines the certificate usage purpose where it must match for a hit to occur. 
 *            Application wishing to specifying more than 1 purposes may concatenate the values together with OR operation. 
 *            Application is strictly disallowed to specify CERTMAN_KP_NONE in this retrieval request as using this service means application intends to operate on certificate's public key.
 *         5. The "output_dir" parameter specifies the output directory of the generated file. 
 *            Caller must ensure that this is a full path including the drive letter and a final slash "\" character at the end of path.
 * PARAMETERS
 *  src_mod         :   [IN]    Source module id of the caller application.
 *  trans_id        :   [IN]    Input transaction id from the caller applications.
 *  cert_id         :   [IN]    Specified certificate id.
 *  key_purpose     :   [IN]    Specified key purposes (certman_keypurpose_enum).
 *  output_dir      :   [IN]    The specified output directory.
 * RETURNS
 *  void
 * SEE ALSO
 *  certman_send_get_cert_by_id_req
 *****************************************************************************/
void certman_send_get_trusted_cert_by_id_req(
                module_type src_mod, 
                kal_uint32 trans_id, 
                kal_uint32 cert_id, 
                kal_uint32 key_purpose, 
                const kal_wchar *output_dir);

/*****************************************************************************
 * <GROUP certman_retrieve_funcs>
 *
 * FUNCTION
 *  certman_send_get_cert_chain_req
 * DESCRIPTION
 *  This interface function assists caller in sending a MSG_ID_CERTMAN_GET_CERT_CHAIN_REQ primitive to Certman.
 *  Caller should expect the data to be returned through MSG_ID_CERTMAN_GET_CERT_CHAIN_CNF primitive.
 *  NOTE : 1. Certman will generate a new file for each request and have the requested certificate(s) placed in this file. 
 *         2. The file path will be returned to caller through the response primitive, 
 *            and caller is expected to delete the file when it is no longer needed. 
 *            The file will be located within Certman's temp folder under system drive, and this folder will be cleaned by Certman during each bootup.
 *         3. There is no encoding type associated with this request as a chain of certificates can only be encoded in either PEM or PKCS family formats.
 *            It was decided that the chain of certificates will always be encoded in PEM with multiple BEGIN/END separating each certificates.
 *         4. The "key_purpose" parameter defines the certificate usage purpose where it must match for a hit to occur. 
 *            Application wishing to specifying more than 1 purposes may concatenate the values together with OR operation. 
 *            Application is strictly disallowed to specify CERTMAN_KP_NONE in this retrieval request as using this service means application intends to operate on certificate's public key.
 *         5. The "output_dir" parameter specifies the output directory of the generated file. 
 *            Caller must ensure that this is a full path including the drive letter and a final slash "\" character at the end of path.
 *         6. Please be reminded that this request will only include the relevant certificates 
 *            (ie, issuer's certificate on the requested certificate, and its issuer, and issuers¡K),
 *            in the order of {requested certificate, issuer of requested certificate, issuer of the issuer, ¡K, root CA certificate}. 
 *            No private key will be included in this request.
 * PARAMETERS
 *  src_mod         :   [IN]    Source module id of the caller application.
 *  trans_id        :   [IN]    Input transaction id from the caller applications.
 *  cert_id         :   [IN]    Specified certificate id.
 *  key_purpose     :   [IN]    Specified key purposes (certman_keypurpose_enum).
 *  output_dir      :   [IN]    The specified output directory.
 * RETURNS
 *  void
 * SEE ALSO
 *  certman_send_get_cert_by_id_req
 *****************************************************************************/
void certman_send_get_cert_chain_req(
            	module_type src_mod,
            	kal_uint32 trans_id,
            	kal_uint32 cert_id,
            	kal_uint32 key_purpose,
            	const kal_wchar *output_dir);

/*****************************************************************************
 * <GROUP certman_retrieve_funcs>
 *
 * FUNCTION
 *  certman_send_get_privkey_req
 * DESCRIPTION
 *  This interface function assist caller in sending a MSG_ID_CERTMAN_GET_PRIVKEY_REQ primitive to Certman. 
 *  Caller should expect the data to be returned through MSG_ID_CERTMAN_GET_PRIVKEY_CNF primitive.
 *  NOTE : 1. Certman will generate a new file for each request and have the requested private key placed in this file. 
 *            The file path will be returned to caller through the response primitive, 
 *            and caller is expected to delete the file when it is no longer needed. The file will be located within Certman's temp folder under system drive, and this folder will be cleaned by Certman during each bootup.
 *         2. The encoding type is used to specify whether the generated file should be in DER or PEM (base 64) encoding.
 *         3. The "output_dir" parameter specifies the output directory of the generated file. Caller must ensure that this is a full path including the drive letter and a final slash "\" character at the end of path.
 *            If output_dir == NULL, the key data file will be saved in certman temp folder.
 *         4. The private key file will be protected by password for security purpose. 
 *            The password will be different for each of the file generated (ie, different for each request), 
 *            and hence this will not be the same password to what the user had specified during private key import operation. 
 *            The password will be randomly produced on each request, and will be passed to caller through the "password callback function", which must be provided by caller as Certman does not keep the password information within itself. 
 *         5. Caller must prepare at least a CERTMAN_PKPWD_SIZE(60) sized buffer for storing password. 
 *            The password must not assume to be a string value or zero-terminated, 
 *            the additional "size" parameter has included indicating the number of bytes the password occupies. 
 *            Caller must be responsible for copying the password across to its own buffer when the callback is triggered, 
 *            as Certman does not keep track of generated password, the private key file will be unable to decrypt 
 *            if this information is not stored at this point in time.
 *         6. The format of the file produced will thus be PKCS#8 Encrypted Private Key format, 
 *            and caller is expected to have enough knowledge on decrypting the file or 
 *            may simply pass the password and private key information further up/down the stack for the true private key manipulator to use. In case when caller is unable to decrypt the file, 
 *            Certman provides the certman_util_decrypt_privkey_file_out_file utility API where it may decrypt on caller's behalf.
 *         7. The requirements on private key protection are based on the following three fundamental rules, 
 *            which all applications should follow in order to gain maximum security:
 *            (1)private key file must be encrypted in case of system failure and an attack directly on file system
 *            (2)password must not be hard-coded
 *            (3)password must not appear on Catcher log
 *         8. In addition to the password protection on the generated private key file, 
 *            applications are reminded that the private key itself is protected by one of the protection method selected by user during import:
 *            (1)CERTMAN_PROTECT_NONE
 *            (2)CERTMAN_PROTECT_USAGE_CONFIRM
 *            (3)CERTMAN_PROTECT_USAGE_PASSWORD
 *         9. In the case of protection by USAGE_CONFIRM or USAGE_PASSWORD, 
 *            CertMan will trigger Certificate Management Application in displaying appropriate confirmation 
 *            or pin input dialog before proceeding.
 *            Private key retriever must be aware that user input can be a slow process and 
 *            hence the caller must be able to handle scenario such as processing Certman's private key retrieval response 
 *            after its own protocol request timer times out. 
 *            In the case when Certman is unable to proceed (eg, user fails to confirm key usage, or consecutively incorrect PIN inputs, or user presses END-key), 
 *            Certman will return an error status in the MSG_ID_CERTMAN_GET_PRIVKEY_CNF, no file will be generated and hence password callback will not be triggered. 
 *            Caller must then perform necessary termination procedure as user has denied the request. 
 * PARAMETERS
 *  src_mod         :   [IN]    Source module id of the caller application.
 *  trans_id        :   [IN]    Input transaction id from the caller applications.
 *  cert_id         :   [IN]    Specified certificate id.
 *  pwd_cb          :   [IN]    caller specified password callback function
 *  encoding        :   [IN]    identify DER or PEM encoding
 *  output_dir      :   [IN]    The specified output directory.
 * RETURNS
 *  void
 * SEE ALSO
 *  certman_send_get_privkey_req_auto_accept 
 *****************************************************************************/
void certman_send_get_privkey_req(
            	module_type src_mod,
            	kal_uint32 trans_id,
            	kal_uint32 cert_id,
            	certman_fp_pwd_cb pwd_cb,
            	certman_encoding_enum encoding,
            	const kal_wchar *output_dir);

/*****************************************************************************
 * <GROUP certman_retrieve_funcs>
 *
 * FUNCTION
 *  certman_send_get_privkey_req_auto_accept
 * DESCRIPTION
 *  This API is similar with certman_send_get_privkey_req except the following notes.
 *  NOTE : 1. In the case when caller triggers the private key retrieval request, 
 *            CertMan assumes caller has already acquired private key access permission from user beforehand, 
 *            thus CertMan will attempt to bypass all user confirmations or inputs as much as possible. 
 *            For example, if the private key protection has been set to CERTMAN_PROTECT_USAGE_CONFIRM, 
 *            sending request using this function will always assumes user accepts the private key access, 
 *            causing no UI confirmation to be shown to user. 
 *            (If the request is made with certman_send_get_privkey_req( ), UI confirmation will always be shown when retrieving the same private key).
 *         2. In the case of CERTMAN_PROTECT_USAGE_PASSWORD, sending request will always assume 
 *            caller had acquired user's permission in accessing the private key and user had provided the password for the decryption.
 *            If caller did not specify a password (ie, "user_specified_pwd" is NULL, or empty string), 
 *            and the key protection requires a password input, CertMan will then 
 *            reply CERTMAN_ERR_ACCESS_DENIED back to caller immediately through response primitive and no UI for PIN input will be displayed. 
 *            Caller must correctly pass in password as an ASCII string of no more than CERTMAN_PASSWORD_LENGTH characters and with zero-termination, 
 *            failure in satisfying this might lead CertMan to unable to decrypt private key file and a high chance in replying CERTMAN_ERR_ACCESS_DENIED to caller.
 *         3. If the private key has been protected with CERTMAN_PROTECT_USAGE_CONFIRM and has also provided a password, 
 *            the password will be ignored and CertMan will proceed the steps described in the CERTMAN_PROTECT_USAGE_CONFIRM case above.
 * PARAMETERS
 *  src_mod             :   [IN]    Source module id of the caller application.
 *  trans_id            :   [IN]    Input transaction id from the caller applications.
 *  cert_id             :   [IN]    Specified certificate id.
 *  pwd_cb              :   [IN]    caller specified password callback function
 *  encoding            :   [IN]    identify DER or PEM encoding
 *  user_specified_pwd  :   [IN]    caller specified password string
 *  output_dir          :   [IN]    The specified output directory.
 * RETURNS
 *  void
 * SEE ALSO
 *  certman_send_get_privkey_req 
 *****************************************************************************/
void certman_send_get_privkey_req_auto_accept (
            	module_type src_mod,
            	kal_uint32 trans_id,
            	kal_uint32 cert_id,
            	certman_fp_pwd_cb pwd_cb,
            	certman_encoding_enum encoding,
            	const kal_uint8 *user_specified_pwd,
            	const kal_wchar *output_dir);


/*************************************************************************
 * RETRIEVE INTERFACE FUNCTIONS -- User to Unlock Private Key Storage
 ************************************************************************/

/*****************************************************************************
 * <GROUP certman_retrieve_funcs>
 *
 * FUNCTION
 *  certman_send_privkey_usage_password_rsp
 * DESCRIPTION
 *  This interface function assists Certificate Management Application in sending the MSG_ID_CERTMAN_PRIVKEY_USAGE_PASSWORD_RSP primitive to Certman.
 *  NOTE : 1. Application must fill in "result" as 1 if it had sent the password via the "pcb" function,
 *         2. and "result" must be set to 0 if no password could be obtained (hence "pcb" not triggered).
 *         3. the pcb means password callback function provided by MSG_ID_CERTMAN_PRIVKEY_USAGE_PASSWORD_IND.
 * PARAMETERS
 *  src_mod     :   [IN]     Source module id of the caller application.
 *  trans_id    :   [IN]     Input transaction id from the caller applications.
 *  result      :   [IN]     0 = no password is obtained (eg, RSK/END-Key aborts), 1 = password sent to Certman via "pcb" password callback 
 * RETURNS
 *  void
 * SEE ALSO
 *  certman_send_get_privkey_req 
 *****************************************************************************/
void certman_send_privkey_usage_password_rsp(
            	module_type src_mod,
            	kal_uint32 trans_id,
            	kal_uint8 result);

/*****************************************************************************
 * <GROUP certman_retrieve_funcs>
 *
 * FUNCTION
 *  certman_send_privkey_usage_confirm_rsp
 * DESCRIPTION
 *  This interface function assists Certificate Management Application in sending the MSG_ID_CERTMAN_PRIVKEY_USAGE_CONFIRM_RSP primitive to Certman.
 * PARAMETERS
 *  src_mod     :   [IN]     Source module id of the caller application.
 *  trans_id    :   [IN]     Input transaction id from the caller applications.
 *  result      :   [IN]     0 = no confirmation is obtained (eg, RSK/END-Key aborts), 1 = confirmation obtained.
 * RETURNS
 *  void
 * SEE ALSO
 *  certman_send_get_privkey_req 
 *****************************************************************************/
void certman_send_privkey_usage_confirm_rsp(
            	module_type src_mod,
            	kal_uint32 trans_id,
            	kal_uint8 result);


/*************************************************************************
 * VALIDATION LIBRARY APIs
 ************************************************************************/

/*****************************************************************************
 * <GROUP certman_validate_funcs>
 *
 * FUNCTION
 *  certman_ctx_validate_new
 * DESCRIPTION
 *  This API is used to create a new validate context object when a certificate chain is to be validated by specified trusted certificates.
 *  NOTE : The lifetime of the created context only needs to exist until this validate request is sent (certman_send_validate_req) to Certman.
 *         Caller must use certman_ctx_validate_free API to release the import context object either when it is no longer needed, or after the request has sent. 
 * PARAMETERS
 *  valsource       :   [IN]     currently support source cert chain in array only (certman_valsource_enum).
 *  valtype         :   [IN]     currently support validating trusted issuer only (certman_valtype_enum).
 *  ctx_validate    :   [IN\OUT] validation context output location
 * RETURN VALUES
 *  CERTMAN_ERR_NONE                :   Success
 *  CERTMAN_ERR_MEMFULL             :   Memory full error
 * SEE ALSO
 *  certman_ctx_validate_free, certman_validate_set_verify_path, 
 *  certman_validate_add_cert, certman_send_validate_req
 *****************************************************************************/
certman_error_enum certman_ctx_validate_new(
                certman_valsource_enum valsource,
                certman_valtype_enum valtype,
                certman_ctx_validate_struct **ctx_validate);

/*****************************************************************************
 * <GROUP certman_validate_funcs>
 *
 * FUNCTION
 *  certman_ctx_validate_free
 * DESCRIPTION
 *  This API is used to release the validate context object. 
 *  This context can be released as soon as an validation request is sent to Certman.
 * PARAMETERS
 *  ctx_validate    :   [IN]   Specified validate context. 
 * RETURNS
 *  void
 * SEE ALSO
 *  certman_ctx_validate_new
 *****************************************************************************/
void certman_ctx_validate_free(certman_ctx_validate_struct *ctx_validate);

/*****************************************************************************
 * <GROUP certman_validate_funcs>
 *
 * FUNCTION
 *  certman_validate_add_cert
 * DESCRIPTION
 *  This API is used to prepare the validation certificate chain array source for specified validation context object.
 *  NOTE : 1. The source of the validate certificate chain is certificate array like material 
 *            and the application need pay more attention for the sequence of the insertion. 
 *            The certificate in array index 0 is the end-entity to be validated and 
 *            the other certificates are used to build the certificate chain.
 *         2. If the sequence should be the end-entity add first for index 0, 
 *            and the root certificate of the chain shall be the last one certificate to add.
 * PARAMETERS
 *  ctx_validate    :   [IN]    associated validate context
 *  cert_type       :   [IN]    certificate type of the inserting one
 *  data            :   [IN]    certificate data
 *  size            :   [IN]    certificate data size
 * RETURN VALUES
 *  CERTMAN_ERR_NONE            :   Success
 *  CERTMAN_ERR_INVALID_CONTEXT :   The context parameter is invalid
 *  CERTMAN_ERR_INVALID_DATA    :   the data or size parameter is invalid
 *  CERTMAN_ERR_TOO_MANY_CERTS  :   more than CERTMAN_NUM_CERT_IN_VALIDATE certs had been inserted
 * SEE ALSO
 *  certman_ctx_validate_new, certman_validate_set_verify_path, certman_send_validate_req
 *****************************************************************************/
certman_error_enum certman_validate_add_cert(
                certman_ctx_validate_struct *ctx_validate,
                certman_certtype_enum cert_type,
                const void *data,
                kal_uint32 size);

/*****************************************************************************
 * <GROUP certman_validate_funcs>
 *
 * FUNCTION
 *  certman_validate_set_verify_path
 * DESCRIPTION
 *  This API is used to set the caller's specified trusted ca certificates pool.
 *  NOTE : 1. Applications may want to set themselves' trusted ca certificate list to validate input certificate chain.
 *            Caller can use collect the specified certificates into predefined folder.
 *            Then call this API to notify Certman where the pool is.
 *         2. If applications want to set the trusted certs pool, please call this API before
 *            calling the certman_send_validate_req API
 *         3. If the "type" parameter is PEM or DER, certman will ignore the certificates
 *            with wrong types in specified trusted folder.
 * PARAMETERS
 *  ctx_validate    :   [IN]    associated validate context
 *  path            :   [IN]    specified trusted certificates folder path(should be full path and null terminated)
 *  type            :   [IN]    the certificate type in specified folder DER or PEM(certman_encoding_enum).
 * RETURN VALUES
 *  CERTMAN_ERR_INVALID_CONTEXT :   The specified context is invalid
 *  CERTMAN_ERR_INVALID_DATA    :   The type parameter isn't DER or PEM
 *  CERTMAN_ERR_INVALID_PATH    :   The path length is too long
 *  CERTMAN_ERR_INVALID_NONE    :   Success
 * SEE ALSO
 *  certman_ctx_validate_new, certman_ctx_validate_free, 
 *  certman_validate_add_cert, certman_send_validate_req
 *****************************************************************************/
certman_error_enum certman_validate_set_verify_path(
                certman_ctx_validate_struct *ctx_validate,
                const kal_wchar *path,
                certman_encoding_enum type);

/*****************************************************************************
 * <GROUP certman_validate_funcs>
 *
 * FUNCTION
 *  certman_validate_set_ocsp_opt
 * DESCRIPTION
 *  This API is used to sustomize OCSP verification options for
 *  certificate validation.
 * PARAMETERS
 *  ctx_validate    :   [IN]    associated validate context
 *  option          :   [IN]    OCSP verification options, 
 *  value           :   [IN]    value of the option
 * RETURN VALUES
 *  CERTMAN_ERR_NONE :   Success.
 *  CERTMAN_ERR_INVALID_INPUT    :   The specified context is invalid
 *****************************************************************************/
extern  certman_error_enum
certman_validate_set_ocsp_opt(certman_ctx_validate_struct *ctx_validate,
                              certman_ocsp_opt_enum option,
                              void* value);


/*************************************************************************
 * VALIDATION INTERFACE FUNCTIONS
 ************************************************************************/

/*****************************************************************************
 * <GROUP certman_validate_funcs>
 *
 * FUNCTION
 *  certman_send_validate_req
 * DESCRIPTION
 *  This interface function assists caller in sending a MSG_ID_CERTMAN_VALIDATE_REQ primitive to Certman. 
 *  Caller should expect the response from MSG_ID_CERTMAN_VALIDATE_CNF primitive.
 *  NOTE : 1. This API transforms the validate context object to the primitive based validation request.
 *         2. The caller is reminded to release the validate context object by certman_ctx_validate_free API 
 *            after this API is triggered to avoid memory leaks.
 *         3. Caller can specified the last trusted certificate output path.
 *            If caller doesn't specified a output path, the last cert will be saved in certman temp folder returned in response primitvie.
 * PARAMETERS
 *  src_mod         :   [IN]    Source module id of the caller application.
 *  trans_id        :   [IN]    Input transaction id from the caller applications.
 *  output_dir      :   [IN]    Selected last trusted certificate output location.
 *  ctx_validate    :   [IN]    Associated import context.
 * RETURNS
 *  void
 * SEE ALSO
 *  certman_ctx_validate_free, certman_ctx_validate_new
 *  certman_validate_add_cert, certman_validate_set_verify_path
 *****************************************************************************/
void certman_send_validate_req(
                module_type src_mod,
                kal_uint32 trans_id,
                const kal_wchar *output_dir,
                certman_ctx_validate_struct *ctx_validate);

/*****************************************************************************
 * <GROUP certman_validate_funcs>
 *
 * FUNCTION
 *  certman_form_validate_req
 * DESCRIPTION
 *  This interface function assists caller to form a MSG_ID_CERTMAN_VALIDATE_REQ primitive to Certman. 
 *  NOTE : This API won't have caller to send the request, just form the request instead.
 * PARAMETERS
 *  req             :   [IN]    The request object need to be formed.
 *  trans_id        :   [IN]    Input transaction id from the caller applications.
 *  output_dir      :   [IN]    Selected last trusted certificate output location.
 *  ctx_validate    :   [IN]    Associated import context.
 * RETURNS
 *  void
 * SEE ALSO
 *  certman_send_validate_req 
 *****************************************************************************/
certman_error_enum certman_form_validate_req(
                certman_validate_req_struct *req,
                kal_uint32 trans_id,
                const kal_wchar *output_dir,
                certman_ctx_validate_struct *ctx_validate);


/*************************************************************************
 * DELETION INTERFACE FUNCTIONS
 ************************************************************************/

/*****************************************************************************
 * <GROUP certman_delete_funcs>
 *
 * FUNCTION
 *  certman_send_delete_cert_req
 * DESCRIPTION
 *  This interface function assists caller in sending a MSG_ID_CERTMAN_DELETE_CERT_REQ primitive to Certman. 
 *  Caller should expect the data to be returned through MSG_ID_CERTMAN_DELETE_CERT_CNF primitive.
 *  NOTE : 1. Caller must be aware that some certificates may be set with read-only, and cannot be deleted manually. 
 *            Deleting this type of certificate will always cause Certman to return failed error status in MSG_ID_CERTMAN_DELETE_CERT_CNF.
 *         2. Application must be aware that deleting a personal certificate will result in 
 *            deletion of the associated private key automatically as well. 
 *            Please be noted that no user's confirmation or password is required for this operation.
 * PARAMETERS
 *  src_mod     :   [IN]    Source module id of the caller application.
 *  trans_id    :   [IN]    Input transaction id from the caller applications.
 *  cert_id     :   [IN]    Specified certificate id.
 * RETURNS
 *  void
 * SEE ALSO
 *  certman_send_delete_all_cert_req 
 *****************************************************************************/
void certman_send_delete_cert_req(
            	module_type src_mod,
            	kal_uint32 trans_id,
            	kal_uint32 cert_id);

/*****************************************************************************
 * <GROUP certman_delete_funcs>
 *
 * FUNCTION
 *  certman_send_delete_all_cert_req
 * DESCRIPTION
 *  This interface function assists caller in sending a MSG_ID_CERTMAN_DELETE_ALL_CERT_REQ primitive to Certman. 
 *  Caller should expect the data to be returned through MSG_ID_CERTMAN_DELETE_ALL_CERT_CNF primitive.
 *  NOTE : 1. Caller must be aware that although the purpose of this primitive is to delete all certificates (and keys) on system, 
 *            however the read-only certificates will still be remained unchanged, ie, after this operation has completed successfully, 
 *            all read-only certificate will still remain and visible when queried later on.
 * PARAMETERS
 *  src_mod         :   [IN]    Source module id of the caller application.
 *  trans_id        :   [IN]    Transaction id from the caller applications.
 *  cert_group      :   [IN]    specified certificate groups (certman_cert_group_enum).
 * RETURNS
 *  void
 * SEE ALSO
 *  certman_send_delete_cert_req 
 *****************************************************************************/
void certman_send_delete_all_cert_req(
            	module_type src_mod,
            	kal_uint32 trans_id,
            	kal_uint32 cert_group);


/*************************************************************************
 * MISCELLANEOUS UTILITIES APIs
 ************************************************************************/

/*****************************************************************************
 * <GROUP certman_utility_funcs>
 *
 * FUNCTION
 *  certman_util_decrypt_privkey_file_out_file
 * DESCRIPTION
 *  This utility function has been provided to assist application in decrypting 
 *  the password protected private key file that was generated by Certman. 
 *  NOTE : 1. The use of this API is not mandatory, as the file uses the standard PKCS #8 encrypted private key format,
 *            and can be decoded by others provided they support for this as well.
 *         2. Caller needs to specify the desired output encoding type, 
 *            this API currently allows output encoding type of DER and PEM, 
 *            and the decrypted private key will be stored into a file specified in "output_filename". 
 *         3. Caller is reminded that storing of unencrypted private key data on file is subject to security risk, 
 *            and caller must ensure this file is deleted when it is no longer needed. 
 *         4. The memory allocated by "output_filename" will be from control buffer, 
 *            and caller is responsible for releasing this filename pointer also.
 *         5. The output private key format will be in PKCS #8 private key format 
 *            (ie, the unencrypted version), and it is expected caller to have sufficient knowledge in performing further operations. 
 * PARAMETERS
 *  filename            :   [IN]        zero-terminated filename.
 *  password            :   [IN]        Transaction id from the caller applications.
 *  size                :   [IN]        size of password (number of bytes).
 *  output_encoding     :   [IN]        CERTMAN_ENC_DER or CERTMAN_ENC_PEM (certman_encoding_enum)
 *  output_filename     :   [IN\OUT]    decrypted private key file caller must release this pointer from memory, and delete file from file system
 * RETURN VALUES
 *  CERTMAN_ERR_NONE                :   Success
 *  CERTMAN_ERR_MEMFULL             :   Memory full error
 *  CERTMAN_ERR_FILE_NOT_FOUND      :   Can't find the specified file error
 *  CERTMAN_ERR_FS_ERROR            :   Other file system error
 *  CERTMAN_ERR_INCORRECT_PASSWORD  :   Password error
 *  CERTMAN_ERR_INVALID_ENCODING    :   File content encoding error
 * SEE ALSO
 *  certman_send_get_privkey_req, certman_send_get_privkey_req_auto_accept 
 *****************************************************************************/
certman_error_enum certman_util_decrypt_privkey_file_out_file(
            	const kal_wchar *filename,
            	const kal_uint8 *password,
            	kal_uint32 size,
            	certman_encoding_enum output_encoding,
            	kal_wchar **output_filename);

/*****************************************************************************
 * <GROUP certman_utility_funcs>
 *
 * FUNCTION
 *  certman_util_check_id_as_cert
 * DESCRIPTION
 *  This utility function has been provided to assist application in checking 
 *  whether the certificate of the specified ID does exist on system, in addition, 
 *  caller may specify the additional check condition such as certificate group, domain and/or key purposes.
 *  NOTE : 1. Caller wishing to perform a simple check on whether the certificate exists, 
 *            it then may set:
 *              cert_group to CERTMAN_CERTGRP_NONE
 *              domain to CERTMAN_DOMAIN_NONE
 *              key_purpose to CERTMAN_KP_NONE
 *            or otherwise, it may specify more than one certificate group by 
 *            concatenating the values in certman_cert_group_enum enumeration, or one or more domain by values in certman_domain_enum or one or more key purpose by values in certman_keypurpose_enum.
 *         2. This utility will simply checks the certificate information stored on CertMan's database in memory
 *            and will actually not go into file system to check on existence of the certificate raw data itself.
 * PARAMETERS
 *  id              :   [IN]    The specified ID to check.
 *  cert_group      :   [IN]    specified certificate groups (certman_cert_group_enum).
 *  domain          :   [IN]    specified certificate domains (certman_domain_enum).
 *  key_purpose     :   [IN]    Specified key purposes (certman_keypurpose_enum).
 * RETURN VALUES
 *  CERTMAN_ERR_NONE                :   Success
 *  CERTMAN_ERR_INVALID_CERT_GROUP  :   cert_group setting invalid
 *  CERTMAN_ERR_INVALID_DOMAIN      :   domain setting invalid
 *  CERTMAN_ERR_INVALID_KEY_PURPOSE :   key_purpose setting invalid
 *  CERTMAN_ERR_CERT_NOT_FOUND      :   can't find certificate with specified ID
 * SEE ALSO
 *  certman_util_check_id_as_privkey 
 *****************************************************************************/
certman_error_enum certman_util_check_id_as_cert(
            	kal_uint32 id,
            	kal_uint32 cert_group,
            	kal_uint32 domain,
            	kal_uint32 key_purpose);

/*****************************************************************************
 * <GROUP certman_utility_funcs>
 *
 * FUNCTION
 *  certman_util_check_id_as_privkey
 * DESCRIPTION
 *  This utility function has been provided to assist application in checking 
 *  whether the private key of the specified ID does exist on system.
 *  NOTE : This utility will simply checks the private key information stored in CertMan's database in memory and 
 *         will actually not go into file system to check on existence of the private key raw data itself, 
 *         no UI confirmation will be required from user (eg, password input or user confirmation dialog).
 * PARAMETERS
 *  id      :   [IN]    The specified ID to check.
 * RETURN VALUES
 *  CERTMAN_ERR_NONE            :   Success
 *  CERTMAN_ERR_KEY_NOT_FOUND   :   can't find private key with specified ID
 * SEE ALSO
 *  certman_util_check_id_as_cert 
 *****************************************************************************/
certman_error_enum certman_util_check_id_as_privkey(kal_uint32 id);

/*****************************************************************************
 * <GROUP certman_utility_funcs>
 *
 * FUNCTION
 *  certman_util_signature_verify_by_id
 * DESCRIPTION
 *  This utility function to verify the signature by specified certificate public key. 
 * PARAMETERS
 *  id          :   [IN]        The specified certificate ID to check.
 *  sig_vfy     :   [IN]        certman signataure verify param setting struct
 *  verified    :   [IN\OUT]    verify outcome
 * RETURN VALUES
 *  CERTMAN_ERR_NONE            :   Success
 *  CERTMAN_ERR_INVALID_INPUT   :   input invalid
 *  CERTMAN_ERR_CERT_NOT_FOUND  :   can't find private key with specified ID
 *  CERTMAN_ERR_FS_ERROR        :   FS error
 *  CERTMAN_ERR_FAIL            :   verified failed
 *****************************************************************************/
certman_error_enum certman_util_signature_verify_by_id(
                kal_uint32 id, 
                certman_signature_vfy_params_struct *sig_vfy,
                kal_int8 *verified);


/*************************************************************************
 * MISCELLANEOUS UTILITIES INTERFACE FUNCTIONS
 ************************************************************************/

/*****************************************************************************
 * <GROUP certman_utility_funcs>
 *
 * FUNCTION
 *  certman_send_update_key_purpose_req
 * DESCRIPTION
 *  This interface function assists caller in sending a MSG_ID_CERTMAN_UPDATE_KEY_PURPOSE_REQ primitive to Certman.
 *  Caller should expect the data to be returned through MSG_ID_CERTMAN_UPDATE_KEY_PURPOSE_CNF primitive. 
 *  NOTE : 1. The "key_purpose" parameter should define a set of key purposes that are enabled by user (ie, replaces "key_purpose_allowed" parameter). 
 *         2. Application should ensure that the set of allowed purposes does not exceed the restriction from "key_purpose_all" of the associated certificate. 
 *            Should this event occurred, Certman would simply discard any "out of range" or "additional" key purposes that are incorrectly set, 
 *            and have the final set of key purposes returned in response primitive.
 * PARAMETERS
 *  src_mod         :   [IN]    Source module id of the caller application.
 *  trans_id        :   [IN]    Input transaction id from the caller applications.
 *  cert_id         :   [IN]    Specified certificate id.
 *  key_purpose     :   [IN]    Specified key purposes (OR'd value from certman_keypurpose_enum, must not go beyond "key_purpose_all").
 * RETURNS
 *  void
 *****************************************************************************/
void certman_send_update_key_purpose_req(
            	module_type src_mod,
            	kal_uint32 trans_id,
            	kal_uint32 cert_id,
            	kal_uint32 key_purpose);


/*****************************************************************************
 * <GROUP certman_ocsp_funcs>
 *
 * FUNCTION
 *  certman_ocsp_set_config
 * DESCRIPTION
 * PARAMETERS
 *  use_ocsp          : [IN]    Use OCSP to validate certificates.
 *                              Default: False.
 *  must_pass         : [IN]    must pass the OCSP validation.
 *                              If this flag is set and no response from server,
 *                              it would be taken as validation fail.
 *                              Default: False.
 *  default_responder : [IN]    Use the specified server for querying status. 
 *                              The format is http(s)://server.name:port/path
 *                              
 * RETURNS
 *  CERTMAN_ERR_NONE                :   Success
 *  CERTMAN_ERR_INVALID_INPUT       :   Invalid parameters
 *****************************************************************************/
certman_error_enum certman_ocsp_set_config(
                   kal_bool use_ocsp,
                   kal_bool must_pass,
                   kal_char *default_responder);


/*****************************************************************************
 * <GROUP certman_ocsp_funcs>
 *
 * FUNCTION
 *  certman_ocsp_get_config
 * DESCRIPTION
 * PARAMETERS
 *  use_ocsp          : [IN]    Use OCSP to validate certificates.
 *                              Default: False.
 *  must_pass         : [IN]    must pass the OCSP validation.
 *                              If this flag is set and no response from server,
 *                              it would be taken as validation fail.
 *                              Default: False.
 *  default_responder : [OUT]   buffer returning default responder 
 *                              The format is http(s)://server.name:port/path
 *  buf_size          : [IN]    buffer size of default_responder
 *                              
 * RETURNS
 *  CERTMAN_ERR_NONE                :   Success
 *  CERTMAN_ERR_INVALID_INPUT       :   Invalid parameters
 *****************************************************************************/
certman_error_enum certman_ocsp_get_config(
                   kal_bool *use_ocsp,
                   kal_bool *must_pass,
                   kal_char *default_responder,
                   kal_int32 *buf_size);


/*****************************************************************************
 * <GROUP certman_ocsp_funcs>
 *
 * FUNCTION
 *  certman_ocsp_set_default_id
 * DESCRIPTION
 *  Set the default string id and application id.
 *  OCSP module will use these informations to register application id with CBM.
 * PARAMETERS 
 *  string_id          : [IN]   string id to be showed for user interaction
 *  icon_id            : [IN]   icon id to be showed for user interaction
 *                              
 * RETURNS
 *  CERTMAN_ERR_NONE: for the first time to set the parameter or the same 
 *                    values are provided in one boot session
 *  CERTMAN_ERR_FAIL: different values are provided during the same boot-time.
 *****************************************************************************/
certman_error_enum
certman_ocsp_set_default_id(kal_uint16 string_id, kal_uint16 icon_id);

/*****************************************************************************
 * <GROUP certman_ocsp_funcs>
 *
 * FUNCTION
 *  certman_ocsp_check_responder_url
 * DESCRIPTION
 * PARAMETERS
 *  url : [IN]    URL string to be parsed
 * RETURNS
 *  CERTMAN_ERR_NONE           :   Success
 *  CERTMAN_ERR_INVALID_INPUT  :   Invalid parameters URL fomrat
 *****************************************************************************/
certman_error_enum certman_ocsp_check_responder_url(kal_char *url);


/*****************************************************************************
 * <GROUP certman_ocsp_funcs>
 *
 * FUNCTION
 *  certman_ocsp_verify_cert
 * DESCRIPTION
 * PARAMETERS
 *  src_mod :      [IN] This function will send MSG_ID_CERTMAN_OCSP_VERIFY_CERT_REQ
 *                      by allocating ILM with this module id and reply CNF message
 *                      to this module after verified.
 *  cert :         [IN] certificate content of end-entity in DER format
 *  cert_len :     [IN] size of cert in bytes
 *  issuer :       [IN] end-entity's issuer certificate in DER format
 *  issuer_len :   [IN] size of issuer in bytes
 *  trusted_path : [IN] trusted pool, optional. Use CERTMAN_SHARED_CERTS_PATH 
 *                      is not provided.
 *  type :         [IN] encoding type of trusted certificates in trusted_path.
 *  trans_id :     [OUT] transaction id.
 *  customize_options [IN] : bitmask of options in certman_ocsp_opt_enum
 *  customize_params  [IN] : values of the customized parameters.
 * RETURNS
 *  CERTMAN_ERR_NONE       : Success, generally some error in the error
 *                           checking, but must_pass is not set in config
 *  CERTMAN_ERR_WOULDBLOCK : waiting for validation response
 *  CERTMAN_ERR_MEMFULL    : out-of-memory to accomplish the operation
 *  CERTMAN_EXT_NOT_FOUND  : a default responder is not set and OCSP url is not
 *                           specified in the certificate
 *  CERTMAN_ERR_FAIL : other errors
 *****************************************************************************/
certman_error_enum
certman_ocsp_verify_cert(module_type src_mod,
                         const void* cert, kal_uint32 cert_len,
                         const void* issuer, kal_uint32 issuer_len,
                         kal_wchar *trusted_path, certman_encoding_enum type,
                         kal_uint8 *trans_id,
                         kal_uint32 customize_options,
                         certman_ocsp_customize_param_struct *customize_params);


/*****************************************************************************
 * <GROUP certman_ocsp_funcs>
 *
 * FUNCTION
 *  certman_ocsp_abort_verify_cert
 * DESCRIPTION
 * PARAMETERS
 *  trans_id :    [IN]   transaction id returned from certman_ocsp_verify_cert().
 * RETURNS
 *  CERTMAN_ERR_NONE : operation aborted
 *  CERTMAN_ERR_INVALID_CONTEXT : no matching context found
 *****************************************************************************/
certman_error_enum
certman_ocsp_abort_verify_cert(kal_uint8 trans_id);

#ifdef CERTMAN_AT_CMD

/*****************************************************************************
 *
 * FUNCTION
 *  certman_import_usert_cert_file
 * DESCRIPTION
 *  This interface function assists caller in sending a MSG_ID_CERTMAN_IMPORT_REQ primitive to Certman after which which Certman will install this file.
 *  
 * PARAMETERS
 *  src_mod         		:   [IN]     Source module id of the caller application.
 *  filename        		:   [IN]     Name of the certificate file to be imported.
 *  parse_password       :   [IN]     Password required to parse the Certificate file. Password will be NULL if no password required to parse the file.
 * RETURNS
 *  CERTMAN_ERR_FAIL : Filename is NULL
 *  CERTMAN_ERR_NONE: 
 *****************************************************************************/
int certman_import_usert_cert_file(module_type src_mod, const kal_wchar* filename, const kal_uint8 *parse_password);



/*****************************************************************************
 *
 * FUNCTION
 *  certman_send_get_user_privkey
 * DESCRIPTION
 *  This interface function stores the private key of the already installed user certificate(installed using certman_import_usert_cert_file API)in a file.
 *  which Certman will install.
 * PARAMETERS
 *  src_mod         :   [IN]     Source module id of the caller application.
 *  filepath         :   [IN]      Name of the  file with absolute  path where private key will be written.
 * RETURNS
 *  int
 *****************************************************************************/
int certman_get_user_privkey(module_type src_mod, const kal_wchar *filepath);


/*****************************************************************************
 *
 * FUNCTION
 *  certman_user_cert_status
 * DESCRIPTION
 *  This interface function checks user_certificate installed in system or not
 * PARAMETERS
 *  
 * RETURNS
 *  CERTMAN_CERT_STATUS_NOT_FOUND : certificate not installed
 *  CERTMAN_CERT_STATUS_INSTALLED:
 *****************************************************************************/

//certman_user_cert_check_status_enum certman_get_user_cert_status(certman_user_cert_status_enum user_enum);
certman_user_cert_status_enum certman_user_cert_status(void);


#endif /* CERTMAN_AT_CMD */

#endif  /* CERTMAN_API_H */
