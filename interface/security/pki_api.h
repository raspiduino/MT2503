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
 *    pki_api.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    PKI exported services
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#ifndef PKI_API_H
#define PKI_API_H

#ifndef __APP_DATETIME_H__
#error "please include app_datetime.h before including pki_api.h"
#endif

/* for pki interface struct and enum */
#include "pki_defs.h"
#include "pki_struct.h"

/************ PKI Exported Common APIs **************/

/*****************************************************************************
 * <GROUP pki_memory_funcs>
 *
 * FUNCTION
 *  pki_lib_data_release
 * DESCRIPTION
 *  This function is to release the pki lib allocated resources
 *  If the specified data pointer is NULL, no operation will be executed.
 *  NOTE : You can use the APIs listed in SEE ALSO if you know the data exactly.
 *         But you can also use this APIs to release the queried data copied by PKI library.
 * PARAMETERS
 *  data       :   [IN]    associated data memory pointer
 * RETURNS
 *  void
 * SEE ALSO
 *  pki_pem_data_release, pki_x509_data_release, pki_validate_data_release, pki_pkcs8key_data_release
 *****************************************************************************/
extern void pki_lib_data_release(void *data);

/*****************************************************************************
 * <GROUP pki_context_funcs>
 *
 * FUNCTION
 *  pki_context_new
 * DESCRIPTION
 *  This function is for backward compatible of unified interface.
 *  Applications should use this API to create a PKI context at first.
 *  Then the pki context should be used all the other PKI APIs.
 * PARAMETERS
 *  pki_ctx   :   [IN/OUT]    Returned PKI context
 * RETURN VALUES
 *  PKI_ERR_NONE : Always return success
 * SEE ALSO
 *  pki_context_release
 *****************************************************************************/
extern pki_error_enum pki_context_new(pki_context_struct **pki_ctx);

/*****************************************************************************
 * <GROUP pki_context_funcs>
 *
 * FUNCTION
 *  pki_context_release
 * DESCRIPTION
 *  This function is for backward compatible of unified interface.
 *  Applications should use this API to release the associated PKI context
 * PARAMETERS
 *  ctx   :   [IN]    application allocated pki context
 * RETURNS
 *  void
 *****************************************************************************/
extern void pki_context_release(pki_context_struct **ctx);

/************** PKI PEM Exported APIs *****************/

/*****************************************************************************
 * <GROUP pki_pem_funcs>
 *
 * FUNCTION
 *  pki_pem_decode
 * DESCRIPTION
 *  This function is to decode the first PEM encoded certificate/key data in PEM chain.
 *  NOTE : 1. The parameter "name" if NOT NULL, will show the decoded object is a key or a certificate.
 *            But the memory is allocated by PKI library, that need applications to release the memory by
 *            API:pki_pem_data_release
 *         2. The parameter "out_der" if NOT NULL, will store the decoded data.
 *            But the memory is allocated by PKI library, that need applications to release the memory by
 *            API:pki_pem_data_release
 *         3. The parameter "out_size" if NOT NULL, will store the decoded data length.
 *            Applications can call this API first use this attribute to query the data size 
 *            to prepare the buffer for copy operation
 *         4. If the function returns error, applications don't have to release any memory.
 * PARAMETERS
 *  pki_ctx     :   [IN]        associated pki context
 *  in_pem      :   [IN]        pem encoded certificate data
 *  in_size     :   [IN]        pem encoded certificate data length
 *  name        :   [IN/OUT]    output location of PEM header name
 *  out_der     :   [IN/OUT]    output location of certificate data
 *  out_size    :   [IN/OUT]    output location of certificate data length
 * RETURNS
 *  pki_error_enum
 * SEE ALSO
 *  pki_pem_data_release, pki_pem_decode_by_index
 *****************************************************************************/
extern pki_error_enum pki_pem_decode(
                pki_context_struct *pki_ctx, 
                void *in_pem, 
                kal_uint32 in_size,
                char **name,
                void **out_der,
                kal_uint32 *out_size);

/*****************************************************************************
 * <GROUP pki_pem_funcs>
 *
 * FUNCTION
 *  pki_pem_decode_by_index
 * DESCRIPTION
 *  This function is similar to pki_pem_decode. The only difference is that the API can specified the index in PEM data chain.
 *  The index of the first item in PEM chain is 0.
 *  NOTE : If the specified index is out of range in PEM chain, the API will returns error.
 * PARAMETERS
 *  pki_ctx     :   [IN]        associated pki context
 *  in_pem      :   [IN]        pem encoded certificate data
 *  in_size     :   [IN]        pem encoded certificate data length
 *  index       :   [IN]        index-th certificate in PEM certificate chain
 *  name        :   [IN/OUT]    output location of PEM header name
 *  out_der     :   [IN/OUT]    output location of certificate data
 *  out_size    :   [IN/OUT]    output location of certificate data length
 * RETURNS
 *  pki_error_enum 
 * SEE ALSO
 *  pki_pem_data_release, pki_pem_decode_by_index
 *****************************************************************************/
extern pki_error_enum pki_pem_decode_by_index(
                pki_context_struct *pki_ctx, 
                void *in_pem, 
                kal_uint32 in_size, 
                kal_uint32 index, 
                char **name, 
                void **out_der, 
                kal_uint32 *out_size);

/*****************************************************************************
 * <GROUP pki_pem_funcs>
 *
 * FUNCTION
 *  pki_pem_encode
 * DESCRIPTION
 *  This function is to encode the specified DER encoded data to PEM format
 *  NOTE : 1. The parameter "out_pem" if NOT NULL, will store the encoded data.
 *            But the memory is allocated by PKI library, that need applications to release the memory by
 *            API:pki_pem_data_release
 *         2. The parameter "out_size" if NOT NULL, will store the encoded data length.
 *            Applications can call this API first use this attribute to query the data size 
 *            to prepare the buffer for copy operation
 *         3. If the function returns error, applications don't have to release any memory.
 * PARAMETERS
 *  pki_ctx     :   [IN]        associated pki context
 *  name        :   [IN]        specified PEM header name for this data
 *  in_der      :   [IN]        DER encoded certificate data
 *  in_size     :   [IN]        DER encoded certificate data length
 *  out_pem     :   [IN/OUT]    output location of certificate PEM data
 *  out_size    :   [IN/OUT]    output location of certificate PEM data length
 * RETURNS
 *  pki_error_enum 
 * SEE ALSO
 *  pki_pem_data_release
 *****************************************************************************/
extern pki_error_enum pki_pem_encode(
                pki_context_struct *pki_ctx, 
                const char *name, 
                void *in_der, 
                kal_uint32 in_size, 
                void **out_pem, 
                kal_uint32 *out_size);

/*****************************************************************************
 * <GROUP pki_pem_funcs>
 *
 * FUNCTION
 *  pki_pem_data_release
 * DESCRIPTION
 *  This function is to release the pki pem allocated resources
 *  If the specified data pointer is NULL, no operation will be executed. 
 * PARAMETERS
 *  data        :   [IN]    associated data memory pointer
 * RETURNS
 *  void
 * SEE ALSO
 *  pki_lib_data_release, pki_pem_decode_by_index, pki_pem_decode, pki_pem_encode
 *****************************************************************************/
extern void pki_pem_data_release(void *data);


/************** PKI X509 Exported APIs *****************/

/*****************************************************************************
 * <GROUP pki_x509_funcs>
 *
 * FUNCTION
 *  pki_x509_new
 * DESCRIPTION
 *  This function is to create pki x509 context by specified certificate data in DER format
 *  NOTE : If the operation is success, applications need to release the context by API: pki_x509_release
 * PARAMETERS
 *  pki_ctx     :   [IN]        associated pki context
 *  data        :   [IN]        DER encoded certificate data
 *  size        :   [IN]        DER encoded certificate data length
 *  x509_out    :   [IN/OUT]    output location of pki x509 context
 * RETURNS
 *  pki_error_enum 
 * SEE ALSO
 *  pki_x509_release
 *****************************************************************************/
extern pki_error_enum pki_x509_new(
                    pki_context_struct *pki_ctx,
                    const void *data,
                    kal_uint32 size,
                    pki_x509_struct **x509_out);

/*****************************************************************************
 * <GROUP pki_x509_funcs>
 *
 * FUNCTION
 *  pki_x509_release
 * DESCRIPTION
 *  This function is to release the pki x509 context resources
 * PARAMETERS
 *  x509    :   [IN]        associated pki context
 * RETURNS
 *  pki_error_enum
 * SEE ALSO
 *  pki_x509_new
 *****************************************************************************/
extern void pki_x509_release(pki_x509_struct **x509);

/*****************************************************************************
 * <GROUP pki_x509_funcs>
 *
 * FUNCTION
 *  pki_x509_get_der
 * DESCRIPTION
 *  This function is to query the DER data part and the data length of the pki x509 context
 * PARAMETERS
 *  x509    :   [IN]        associated pki x509 context
 *  data    :   [IN/OUT]    data output location
 *  size    :   [IN/OUT]    data length output location
 * RETURNS
 *  pki_error_enum 
 *****************************************************************************/
extern pki_error_enum pki_x509_get_der(
                    pki_x509_struct *x509, 
                    const void **data, 
                    kal_uint32 *size);

/*****************************************************************************
 * <GROUP pki_x509_funcs>
 *
 * FUNCTION
 *  pki_x509_get_signature_algorithm
 * DESCRIPTION
 *  This function is to query the x509 signature algorithm
 *  NOTE : This queried signature algorithm will be stored in *alg
 *         If we can't support the algorithm, the *alg will be PKI_SIGNALG_TOTAL
 *         and the return value will be PKI_ERR_UNSUPPORTED_CONTENT
 * PARAMETERS
 *  x509    :   [IN]        associated pki x509 context
 *  alg     :   [IN/OUT]    algorithm output location
 * RETURNS
 *  pki_error_enum 
 *****************************************************************************/
extern pki_error_enum pki_x509_get_signature_algorithm(
                    pki_x509_struct *x509, 
                    pki_signature_alg *alg);

/*****************************************************************************
 * <GROUP pki_x509_funcs>
 *
 * FUNCTION
 *  pki_x509_get_signature
 * DESCRIPTION
 *  This function is to query the x509 signature data
 *  NOTE : 1. The parameter "signature" if NOT NULL, will store the queried sianature data.
 *            But the memory is allocated by PKI library, that need applications to release the memory by
 *            API:pki_x509_data_release
 *         2. The parameter "size" if NOT NULL, will store the queried sianature data length.
 *            Applications can call this API first use this attribute to query the data size 
 *            to prepare the buffer for copy operation
 *         3. If the function returns error, applications don't have to release any memory.
 * PARAMETERS
 *  x509        :   [IN]        associated pki x509 context
 *  signature   :   [IN/OUT]    signature data output location
 *  size        :   [IN/OUT]    signature data length output location
 * RETURNS
 *  pki_error_enum 
 * SEE ALSO
 *  pki_x509_data_release, pki_x509_get_serial, pki_x509_get_subjectuid, pki_x509_get_issueruid, pki_name_get_der
 *****************************************************************************/
extern pki_error_enum pki_x509_get_signature(
                    pki_x509_struct *x509, 
                    const void **signature, 
                    kal_uint32 *size);

/*****************************************************************************
 * <GROUP pki_x509_funcs>
 *
 * FUNCTION
 *  pki_x509_get_version
 * DESCRIPTION
 *  This function is to query the x509 version
 * PARAMETERS
 *  x509    :   [IN]        associated pki x509 context
 *  ver     :   [IN/OUT]    x509 version number output location
 * RETURNS
 *  pki_error_enum 
 *****************************************************************************/
extern pki_error_enum pki_x509_get_version(
                    pki_x509_struct *x509, 
                    kal_uint32 *ver);

/*****************************************************************************
 * <GROUP pki_x509_funcs>
 *
 * FUNCTION
 *  pki_x509_get_serial
 * DESCRIPTION
 *  This function is to query the x509 serial number
 *  NOTE : 1. The parameter "serial" if NOT NULL, will store the queried serial data.
 *            But the memory is allocated by PKI library, that need applications to release the memory by
 *            API:pki_x509_data_release
 *         2. The parameter "size" if NOT NULL, will store the queried serial data length.
 *            Applications can call this API first use this attribute to query the data size 
 *            to prepare the buffer for copy operation
 *         3. If the function returns error, applications don't have to release any memory.
 * PARAMETERS
 *  x509        :   [IN]        associated pki x509 context
 *  serial      :   [IN/OUT]    serial number output location
 *  size        :   [IN/OUT]    serial number size output location
 * RETURNS
 *  pki_error_enum
 * SEE ALSO
 *  pki_x509_data_release, pki_x509_get_signature, pki_x509_get_subjectuid, pki_x509_get_issueruid, pki_name_get_der
 *****************************************************************************/
extern pki_error_enum pki_x509_get_serial(
                    pki_x509_struct *x509, 
                    void **serial, 
                    kal_uint32 *size);

/*****************************************************************************
 * <GROUP pki_x509_funcs>
 *
 * FUNCTION
 *  pki_x509_get_validity
 * DESCRIPTION
 *  This function is to query the x509 not_before and not_after time information
 * PARAMETERS
 *  x509            :   [IN]        associated pki x509 context
 *  pki_not_before  :   [IN/OUT]    certificate not_before output location
 *  pki_not_after   :   [IN/OUT]    certificate not_after output location
 * RETURNS
 *  pki_error_enum 
 *****************************************************************************/
extern pki_error_enum pki_x509_get_validity(
                    pki_x509_struct *x509, 
                    applib_time_struct *pki_not_before, 
                    applib_time_struct *pki_not_after);

/*****************************************************************************
 * <GROUP pki_x509_funcs>
 *
 * FUNCTION
 *  pki_x509_get_fingerprint_sha1
 * DESCRIPTION
 *  This function is to query the x509 certificate SHA1 hash value
 * PARAMETERS
 *  x509        :   [IN]        associated pki x509 context
 *  fngrprnt    :   [IN/OUT]    certificate SHA1 hash output location
 *  size        :   [IN/OUT]    certificate SHA1 hash size
 * RETURNS
 *  pki_error_enum 
 *****************************************************************************/
extern pki_error_enum pki_x509_get_fingerprint_sha1(
                    pki_x509_struct *x509,
                    void *fngrprnt,
                    kal_uint32 size);

/*****************************************************************************
 * <GROUP pki_x509_funcs>
 *
 * FUNCTION
 *  pki_x509_get_pubkey_type
 * DESCRIPTION
 *  This function is to query the x509 certificate public key type
 * PARAMETERS
 *  x509            :   [IN]        associated pki x509 context
 *  keytype_out     :   [IN/OUT]    certificate key type output location
 * RETURNS
 *  pki_error_enum 
 *****************************************************************************/
extern pki_error_enum pki_x509_get_pubkey_type(
                    pki_x509_struct *x509, 
                    pki_pubkey_type_enum *keytype_out);

/*****************************************************************************
 * <GROUP pki_x509_funcs>
 *
 * FUNCTION
 *  pki_x509_get_issueruid
 * DESCRIPTION
 *  This function is to query the x509 certificate issuer unique ID
 *  NOTE : 1. The parameter "issueruid" if NOT NULL, will store the issuer unique ID.
 *            But the memory is allocated by PKI library, that need applications to release the memory by
 *            API:pki_x509_data_release
 *         2. The parameter "size" if NOT NULL, will store the issuer unique ID length.
 *            Applications can call this API first use this attribute to query the data size 
 *            to prepare the buffer for copy operation
 *         3. If the function returns error, applications don't have to release any memory.
 * PARAMETERS
 *  x509            :   [IN]        associated pki x509 context
 *  issueruid       :   [IN/OUT]    x509 certificate issuer unique ID output location
 *  size            :   [IN/OUT]    x509 certificate issuer unique ID length output location
 * RETURNS
 *  pki_error_enum
 * SEE ALSO
 *  pki_x509_data_release, pki_x509_get_serial, pki_x509_get_signature, pki_x509_get_subjectuid, pki_name_get_der 
 *****************************************************************************/
extern pki_error_enum pki_x509_get_issueruid(
                    pki_x509_struct *x509, 
                    void **issueruid, 
                    kal_uint32 *size);

/*****************************************************************************
 * <GROUP pki_x509_funcs>
 *
 * FUNCTION
 *  pki_x509_get_subjectuid
 * DESCRIPTION
 *  This function is to query the x509 certificate subject unique ID
 *  NOTE : 1. The parameter "issueruid" if NOT NULL, will store the subject unique ID.
 *            But the memory is allocated by PKI library, that need applications to release the memory by
 *            API:pki_x509_data_release
 *         2. The parameter "size" if NOT NULL, will store the subject unique ID length.
 *            Applications can call this API first use this attribute to query the data size 
 *            to prepare the buffer for copy operation
 *         3. If the function returns error, applications don't have to release any memory. 
 * PARAMETERS
 *  x509            :   [IN]        associated pki x509 context
 *  subjectuid      :   [IN/OUT]    x509 certificate subject unique ID output location
 *  size            :   [IN/OUT]    x509 certificate subject unique ID length output location
 * RETURNS
 *  pki_error_enum 
 * SEE ALSO
 *  pki_x509_data_release, pki_x509_get_serial, pki_x509_get_signature, pki_x509_get_issueruid, pki_name_get_der 
 *****************************************************************************/
extern pki_error_enum pki_x509_get_subjectuid(
                    pki_x509_struct *x509,
                    void **subjectuid, 
                    kal_uint32 *size);

/*****************************************************************************
 * <GROUP pki_x509_funcs>
 *
 * FUNCTION
 *  pki_x509_get_basic_constraints
 * DESCRIPTION
 *  This function is to query the x509 certificate basic_constraints extension values
 *  If the return value is PKI_ERR_EXT_NOT_FOUND, which implies there is no such extension
 *  in this certificate, then all the parameters won't be updated  
 * PARAMETERS
 *  x509        :   [IN]        associated pki x509 context
 *  critical    :   [IN/OUT]    basic_constraints extension critical setting output
 *  ca          :   [IN/OUT]    basic_constraints extension ca flag setting output
 *  pathlen     :   [IN/OUT]    basic_constraints extension path length setting output
 * RETURNS
 *  pki_error_enum 
 * SEE ALSO
 *  pki_x509_get_ext_key_usage
 *****************************************************************************/
extern pki_error_enum pki_x509_get_basic_constraints(
                    pki_x509_struct *x509, 
                    kal_uint32 *critical, 
                    kal_uint32 *ca, 
                    kal_uint32 *pathlen);

/*****************************************************************************
 * <GROUP pki_x509_funcs>
 *
 * FUNCTION
 *  pki_x509_get_ext_key_usage
 * DESCRIPTION
 *  This function is to query the x509 certificate extension key usage extension values
 *  If the return value is PKI_ERR_EXT_NOT_FOUND, which implies there is no such extension
 *  in this certificate, then all the parameters won't be updated  
 * PARAMETERS
 *  x509        :   [IN]        associated pki x509 context
 *  critical    :   [IN/OUT]    extension key usage extension critical setting output
 *  keypurpose  :   [IN/OUT]    extension key usage extension keypurpose setting output
 * RETURNS
 *  pki_error_enum
 * SEE ALSO
 *  pki_x509_get_basic_constraints
 *****************************************************************************/
extern pki_error_enum pki_x509_get_ext_key_usage(
                    pki_x509_struct *x509, 
                    kal_uint32 *critical,
                    kal_uint32 *keypurpose);

/*****************************************************************************
 * <GROUP pki_x509_funcs>
 *
 * FUNCTION
 *  pki_x509_get_ocsp_url
 * DESCRIPTION
 *  This function is to retrieve OCSP responder in Authority Information Access
 *  (AIA) extension in a certificate.
 *  An example is
 *      http://EVIntl-ocsp.verisign.com
 * PARAMETERS
 *  x509       : [IN]     associated pki x509 context
 *  url        : [OUT]    returning the URL of OCSP responder.
 *                        Use pki_x509_data_release() to free the string
 *                        allocated by PKI library.
 *  len        : [OUT]    returning required size to hold the OCSP responder URL
 * RETURNS
 *  pki_error_enum 
 * SEE ALSO
 *  pki_x509_data_release
 *****************************************************************************/
extern pki_error_enum pki_x509_get_ocsp_url(
                    pki_x509_struct *x509, 
                    kal_char **url, 
                    kal_uint32 *len);

/*****************************************************************************
 * <GROUP pki_x509_funcs>
 *
 * FUNCTION
 *  pki_x509_is_expired
 * DESCRIPTION
 *  This function is to check the x509 is expired or not
 * PARAMETERS
 *  x509        :   [IN]        associated pki x509 context
 * RETURN VALUES
 *  1 : expired
 *  0 : not expired
 * SEE ALSO
 *  pki_x509_get_validity
 *****************************************************************************/
extern kal_uint8 pki_x509_is_expired(pki_x509_struct *x509);

/*****************************************************************************
 * <GROUP pki_x509_funcs>
 *
 * FUNCTION
 *  pki_x509_get_cert_group
 * DESCRIPTION
 *  This function is to check the certificate group of the x509 cert
 *  If application set the input parameter has_key is true, then the group will be PKI_CERTGRP_PERSONAL
 *  The queried group will be stored in cert_group.
 * PARAMETERS
 *  x509        :   [IN]        associated pki x509 context
 *  has_key     :   [IN]        private key existence flag
 *  cert_group  :   [IN/OUT]    certificate group output location
 * RETURNS
 *  pki_error_enum
 *****************************************************************************/
extern pki_error_enum pki_x509_get_cert_group(
                    pki_x509_struct *x509, 
                    kal_uint8 has_key, 
                    pki_cert_group_enum *cert_group);

/*****************************************************************************
 * <GROUP pki_x509_funcs>
 *
 * FUNCTION
 *  pki_x509_get_subject_hash
 * DESCRIPTION
 *  This function is to compute the hash value of specified cert subject string
 *  NOTE : This API is supported only by OpenSSL PKI library solution
 * PARAMETERS
 *  data        :   [IN]        associated certificate der data
 *  data_size   :   [IN]        length of certificate der data
 *  hash_val    :   [IN/OUT]    hash value output location
 * RETURNS
 *  pki_error_enum
 *****************************************************************************/
extern pki_error_enum pki_x509_get_subject_hash(
                    void *data,
                    kal_uint32 data_size,
                    kal_uint32 *hash_val);

/*****************************************************************************
 * <GROUP pki_x509_funcs>
 *
 * FUNCTION
 *  pki_x509_verify_by_pubkey
 * DESCRIPTION
 *  This function is to verify the specified public key and cert pair
 *  The result is stored in the input parameter "verified".
 * PARAMETERS
 *  x509        :   [IN]        associated pki x509 context
 *  pubkey      :   [IN]        key to verify
 *  verified    :   [IN/OUT]    verified outcome location
 * RETURNS
 *  pki_error_enum
 *****************************************************************************/
extern pki_error_enum pki_x509_verify_by_pubkey(
                    pki_x509_struct *x509,
                    pki_pubkey_struct *pubkey,
                    kal_uint8 *verified);

/*****************************************************************************
 * <GROUP pki_x509_funcs>
 *
 * FUNCTION
 *  pki_x509_data_release
 * DESCRIPTION
 *  This function is to release the pki x509 allocated resources
 *  If the specified data pointer is NULL, no operation will be executed.
 * PARAMETERS
 *  data        :   [IN]    associated data memory pointer
 * RETURNS
 *  void
 * SEE ALSO
 *  pki_x509_get_serial, pki_x509_get_signature, pki_x509_get_issueruid, pki_x509_get_subjectuid
 *****************************************************************************/
extern void pki_x509_data_release(void *data);

/*****************************************************************************
 * <GROUP pki_x509_name_funcs>
 *
 * FUNCTION
 *  pki_x509_get_issuer
 * DESCRIPTION
 *  This function is to query the issuer name DER data from specified x509 context
 *  NOTE : 1. This API will allocated memory for issuer name structure, 
 *            applications need to release the name structure by API : pki_name_release
 *         2. If applications only need to access the issuer name of DER format,
 *            pki_name_get_der can process the output issuer name structure.
 *            Also, the pki_name_release should be called after using.
 *         3. If applications need to parse the DER format name to ascii or ucs2 
 *            encoding strings, please use the API : pki_name_parse, 
 *            and call pki_name_release after using.
 *         4. If the function returns error, applications don't have to release anything
 * PARAMETERS
 *  x509        :   [IN]        associated pki x509 context
 *  issuer      :   [IN/OUT]    issuer name struct output location
 * RETURNS
 *  pki_error_enum
 * SEE ALSO
 *  pki_x509_get_subject, pki_name_release, pki_name_get_der, pki_name_parse
 *****************************************************************************/
extern pki_error_enum pki_x509_get_issuer(
                    pki_x509_struct *x509,
                    pki_name_struct **issuer);

/*****************************************************************************
 * <GROUP pki_x509_name_funcs>
 *
 * FUNCTION
 *  pki_x509_get_subject
 * DESCRIPTION
 *  This function is to query the subject name DER data from specified x509 context
 *  NOTE : 1. This API will allocated memory for subject name structure, 
 *            applications need to release the name structure by API : pki_name_release
 *         2. If applications only need to access the subject name of DER format,
 *            pki_name_get_der can "copy" the DER data from output subject name structure.
 *            Therefore the pki_name_get_der copied data should be released by pki_x509_data_release
 *            Also, the pki_name_release should be called after using.
 *         3. If applications need to parse the DER format name to ascii or ucs2 
 *            encoding strings, please use the API : pki_name_parse, 
 *            and call pki_name_release after using.
 *         4. If the function returns error, applications don't have to release anything
 * PARAMETERS
 *  x509        :   [IN]        associated pki x509 context
 *  subject     :   [IN/OUT]    subject name struct output location
 * RETURNS
 *  pki_error_enum
 * SEE ALSO
 *  pki_x509_get_issuer, pki_name_release, pki_name_get_der, pki_name_parse 
 *****************************************************************************/
extern pki_error_enum pki_x509_get_subject(
                    pki_x509_struct *x509, 
                    pki_name_struct **subject);

/*****************************************************************************
 * <GROUP pki_x509_name_funcs>
 *
 * FUNCTION
 *  pki_name_parse
 * DESCRIPTION
 *  This function is to parse the name list of DER format to string buffers of 
 *  specified name struct.
 *  NOTE : 1. The allocated memory pointer for parsed acsii or ucs2 strings will be stored
 *            in the input name structure.
 *         2. After parsing, applications can traverse the names array for each string buffer pointers
 *            and the dcs array indicates the corresponding string encoding scheme.
 *         3. The name string array is ordered using pki_name_structype_enum that
 *            applications can use this enum as index to query that strings are interested
 * PARAMETERS
 *  name_obj    :   [IN]     specified name list struct
 * RETURNS
 *  pki_error_enum
 * SEE ALSO
 *  pki_x509_get_subject, pki_x509_get_issuer, pki_name_release, pki_name_clear_parsed_names
 *****************************************************************************/
extern pki_error_enum pki_name_parse(pki_name_struct *name_obj);

/*****************************************************************************
 * <GROUP pki_x509_name_funcs>
 *
 * FUNCTION
 *  pki_name_clear_parsed_names
 * DESCRIPTION
 *  This function is to clear the parsed name string buffers of specified name struct
 *  NOTE : If the name structure is not parsed before, no operation will be executed.
 * PARAMETERS
 *  name_obj   :    [IN]     specified name list struct
 * RETURNS
 *  void
 * SEE ALSO
 *  pki_name_release, pki_name_parse
 *****************************************************************************/
extern void pki_name_clear_parsed_names(pki_name_struct *name_obj);

/*****************************************************************************
 * <GROUP pki_x509_name_funcs>
 *
 * FUNCTION
 *  pki_name_release
 * DESCRIPTION
 *  This function is to release the specified name struct
 * PARAMETERS
 *  name_obj    :   [IN]     specified name list struct
 * RETURNS
 *  void
 * SEE ALSO
 *  pki_x509_get_issuer, pki_x509_get_subject
 *****************************************************************************/
extern void pki_name_release(pki_name_struct **name_obj);

/*****************************************************************************
 * <GROUP pki_x509_name_funcs>
 *
 * FUNCTION
 *  pki_name_get_der
 * DESCRIPTION
 *  This function is to query the name der data of the specified name struct
 *  NOTE : 1. The parameter "data" if NOT NULL, will store the DER name data.
 *            But the memory is allocated by PKI library, that need applications to release the memory by
 *            API:pki_x509_data_release
 *         2. The parameter "size" if NOT NULL, will store the DER name data length.
 *            Applications can call this API first use this attribute to query the data size 
 *            to prepare the buffer for copy operation
 *         3. If the function returns error, applications don't have to release any memory.
 * PARAMETERS
 *  name_obj    :   [IN]    specified name list struct
 *  data        :   [IN]    name der format data output location
 *  size        :   [IN]    name der format data length output location
 * RETURNS
 *  pki_error_enum
 * SEE ALSO
 *  pki_x509_data_release, pki_x509_get_issuer, pki_x509_get_subject, pki_x509_get_serial, pki_x509_get_signature, pki_x509_get_issueruid, pki_name_get_subjectuid 
 *****************************************************************************/
extern pki_error_enum pki_name_get_der(
                    pki_name_struct *name_obj,
                    void **data,
                    kal_uint32 *size);



/************** PKI PUBLIC/PRIVATE KEY Exported APIs ******************/

/*****************************************************************************
 * <GROUP pki_key_funcs>
 *
 * FUNCTION
 *  pki_pubkey_new_by_x509
 * DESCRIPTION
 *  This function is to create a x509 public key struct by specified x509 context
 *  NOTE : 1. The parameter "pubkey_out" if NOT NULL, will store the allocated public key data structure.
 *            But the memory is allocated by PKI library, that need applications to release the memory by
 *            API:pki_pubkey_release
 *         2. If the function returns error, applications don't have to release any memory.
 * PARAMETERS
 *  x509            :   [IN]        specified pki x509 context
 *  pubkey_out      :   [IN/OUT]    output location of x509 public key struct
 * RETURNS
 *  pki_error_enum 
 * SEE ALSO
 *  pki_pubkey_release
 *****************************************************************************/
extern pki_error_enum pki_pubkey_new_by_x509(
                    pki_x509_struct *x509,
                    pki_pubkey_struct **pubkey_out);

/*****************************************************************************
 * <GROUP pki_key_funcs>
 *
 * FUNCTION
 *  pki_pubkey_release
 * DESCRIPTION
 *  This function is to release the allocated x509 public key struct
 * PARAMETERS
 *  pubkey      :   [IN]    specified x509 public key struct
 * RETURNS
 *  void
 * SEE ALSO
 *  pki_pubkey_new_by_x509 
 *****************************************************************************/
extern void pki_pubkey_release(pki_pubkey_struct **pubkey);

/*****************************************************************************
 * <GROUP pki_key_funcs>
 *
 * FUNCTION
 *  pki_pubkey_get_keytype
 * DESCRIPTION
 *  This function is to query the public key type of specified x509 public key struct
 * PARAMETERS
 *  pubkey      :   [IN]        specified x509 public key struct
 *  keytype     :   [IN/OUT]    x509 public key type output location (pki_pubkey_type_enum)
 * RETURNS
 *  pki_error_enum
 * SEE ALSO
 *  pki_pubkey_new_by_x509, pki_pubkey_get_keydata, pki_pubkey_release 
 *****************************************************************************/
extern pki_error_enum pki_pubkey_get_keytype(
                    pki_pubkey_struct *pubkey,
                    pki_pubkey_type_enum *keytype);

/*****************************************************************************
 * <GROUP pki_key_funcs>
 *
 * FUNCTION
 *  pki_pubkey_get_keydata
 * DESCRIPTION
 *  This function is to query the public key data of specified x509 public key struct
 * PARAMETERS
 *  pubkey          :   [IN]        specified x509 public key struct
 *  key_der_out     :   [IN/OUT]    x509 public key der data output location
 *  key_size_out    :   [IN/OUT]    x509 public key data size output location 
 * RETURNS
 *  pki_error_enum
 * SEE ALSO
 *  pki_pubkey_new_by_x509, pki_pubkey_get_keytype, pki_pubkey_release
 *****************************************************************************/
pki_error_enum pki_pubkey_get_keydata(
                pki_pubkey_struct *pubkey, 
                void **key_der_out, 
                kal_uint32 *key_size_out);

/*****************************************************************************
 * <GROUP pki_key_funcs>
 *
 * FUNCTION
 *  pki_pubkey_signature_verify
 * DESCRIPTION
 *  This function is to verify the signature by given hashed data and 
 *  specified pubkey context (only support RSA_MD5 / RSA_SHA1 now)
 * PARAMETERS
 *  pubkey          :   [IN]        specified x509 public key struct
 *  hash_data       :   [IN]        hashed data
 *  hash_len        :   [IN]        hashed data length
 *  hash_alg        :   [IN]        pki_hash_alg_enum
 *  signature       :   [IN]        signature data
 *  sig_len         :   [IN]        signature data length
 *  verified        :   [IN/OUT]    verified outcome location
 * RETURNS
 *  pki_error_enum
 * SEE ALSO
 *  pki_pubkey_new_by_x509, pki_pubkey_release  
 *****************************************************************************/
extern pki_error_enum pki_pubkey_signature_verify(
                    pki_pubkey_struct *pubkey,
                    void *hash_data,
                    kal_uint32 hash_len,
                    pki_hash_alg_enum hash_alg,
                    void *signature,
                    kal_uint32 sig_len,
                    kal_int8 *verified);

/*****************************************************************************
 * <GROUP pki_key_funcs>
 *
 * FUNCTION
 *  pki_privkey_new_by_pkcs8key
 * DESCRIPTION
 *  This function is to transform a pkcs8 key to private key format
 *  NOTE : 1. The parameter "privkey_out" if NOT NULL, will store the allocated private key data structure.
 *            But the memory is allocated by PKI library, that need applications to release the memory by
 *            API:pki_privkey_release
 *         2. If the function returns error, applications don't have to release any memory.
 * PARAMETERS
 *  pkcs8key        :   [IN]        specified p8 key key struct
 *  privkey_out     :   [IN/OUT]    private key output location
 * RETURNS
 *  pki_error_enum
 * SEE ALSO
 *  pki_pkcs8key_new, pki_privkey_release
 *****************************************************************************/
extern pki_error_enum pki_privkey_new_by_pkcs8key(pki_pkcs8key_struct *pkcs8key, pki_privkey_struct **privkey_out);

/*****************************************************************************
 * <GROUP pki_key_funcs>
 *
 * FUNCTION
 *  pki_privkey_release
 * DESCRIPTION
 *  This function is to release private key resource
 * PARAMETERS
 *  privkey     :   [IN]    private key location
 * RETURNS
 *  pki_error_enum
 * SEE ALSO
 *  pki_privkey_new_by_pkcs8key
 *****************************************************************************/
extern void pki_privkey_release(pki_privkey_struct **privkey);

/*****************************************************************************
 * <GROUP pki_key_funcs>
 *
 * FUNCTION
 *  pki_pubkey_privkey_is_pair
 * DESCRIPTION
 *  This function is to check specified x509 public/private key pair
 * PARAMETERS
 *  privkey     :   [IN]        specified x509 private key struct
 *  pubkey      :   [IN]        specified x509 public key struct
 *  paired      :   [IN/OUT]    pair check output location
 * RETURNS
 *  pki_error_enum
 * SEE ALSO
 *  pki_privkey_new_by_pkcs8key, pki_pubkey_new_by_x509
 *****************************************************************************/
extern pki_error_enum pki_pubkey_privkey_is_pair(
                    pki_pubkey_struct *pubkey,
                    pki_privkey_struct *privkey,
                    kal_uint8 *paired);


/************** PKI PKCS8 Exported APIs ******************/

/*****************************************************************************
 * <GROUP pki_pkcs8_funcs>
 *
 * FUNCTION
 *  pki_pkcs8key_new
 * DESCRIPTION
 *  This function is to create a pkcs8 key struct by specified private key data
 * PARAMETERS
 *  pki_ctx         :   [IN]        associated pki context
 *  data            :   [IN]        private key data
 *  size            :   [IN]        private key data size
 *  pkcs8key_out    :   [IN/OUT]    pkcs8 structure output location
 * RETURNS
 *  pki_error_enum
 * SEE ALSO
 *  pki_pkcs8key_release
 *****************************************************************************/
extern pki_error_enum pki_pkcs8key_new(
                    pki_context_struct *pki_ctx,
                    const void *data,
                    kal_uint32 size,
                    pki_pkcs8key_struct **pkcs8key_out);

/*****************************************************************************
 * <GROUP pki_pkcs8_funcs>
 *
 * FUNCTION
 *  pki_pkcs8key_release
 * DESCRIPTION
 *  This function is to release a pkcs8 key struct data
 * PARAMETERS
 *  pkcs8key    :   [IN]    specified pkcs8 structure
 * RETURNS
 *  void 
 * SEE ALSO
 *  pki_pkcs8key_new
 *****************************************************************************/
extern void pki_pkcs8key_release(pki_pkcs8key_struct **pkcs8key);

/*****************************************************************************
 * <GROUP pki_pkcs8_funcs>
 *
 * FUNCTION
 *  pki_pkcs8key_get_der
 * DESCRIPTION
 *  This function is to get the DER format data part of specified pkcs8
 *  NOTE : applications don't have to release memory for this get operation 
 * PARAMETERS
 *  pkcs8key    :   [IN]        specified pkcs8 structure
 *  data        :   [IN/OUT]    the key data output location
 *  data        :   [IN/OUT]    the key data length output location 
 * RETURNS
 *  pki_error_enum 
 * SEE ALSO
 *  pki_pkcs8key_new
 *****************************************************************************/
extern pki_error_enum pki_pkcs8key_get_der(
                    pki_pkcs8key_struct *pkcs8key,
                    const void **data,
                    kal_uint32 *size);

/*****************************************************************************
 * <GROUP pki_pkcs8_funcs>
 *
 * FUNCTION
 *  pki_pkcs8key_encrypt
 * DESCRIPTION
 *  This function is to encrypt the specified pkcs8 key structure
 *  NOTE : 1. The parameter "encdata_out" if NOT NULL, will store the encrypted DER pkcs8 key data.
 *            But the memory is allocated by PKI library, that need applications to release the memory by
 *            API:pki_pkcs8key_data_release
 *         2. The parameter "encsize_out" if NOT NULL, will store the encrypted DER pkcs8 key data length.
 *            Applications can call this API first use this attribute to query the data size 
 *            to prepare the buffer for copy operation
 *         3. If the function returns error, applications don't have to release any memory.
 * PARAMETERS
 *  pkcs8key        :   [IN]        specified pkcs8 structure
 *  pwd             :   [IN]        specified password for encryption
 *  pwd_size        :   [IN]        specified password length
 *  encdata_out     :   [IN/OUT]    encrypted pkcs8 key data in DER format
 *  encsize_out     :   [IN/OUT]    encrypted pkcs8 key data length
 * RETURNS
 *  pki_error_enum 
 * SEE ALSO
 *  pki_pkcs8key_new, pki_pkcs8key_data_release
 *****************************************************************************/
extern pki_error_enum pki_pkcs8key_encrypt(
                    pki_pkcs8key_struct *pkcs8key,
                    const char *pwd,
                    kal_uint32 pwd_size,
                    void **encdata_out,
                    kal_uint32 *encsize_out);

/*****************************************************************************
 * <GROUP pki_pkcs8_funcs>
 *
 * FUNCTION
 *  pki_pkcs8key_data_release
 * DESCRIPTION
 *  This function is to release the pki pkcs8key allocated resources
 * PARAMETERS
 *  data        :   [IN]        associated data memory pointer
 * RETURNS
 *  void
 * SEE ALSO
 *  pki_pkcs8key_encrypt, pki_pkcs8enckey_decrypt
 *****************************************************************************/
extern void pki_pkcs8key_data_release(void *data);

/*****************************************************************************
 * <GROUP pki_pkcs8_funcs>
 *
 * FUNCTION
 *  pki_pkcs8enckey_new
 * DESCRIPTION
 *  This function is to create a encrypted pkcs8 key struct by specified pkcs8 key data
 * PARAMETERS
 *  pki_ctx             :   [IN]        associated pki context
 *  encdata             :   [IN]        encrypted pkcs8 key data (DER format)
 *  size                :   [IN]        encrypted pkcs8 key data size
 *  pkcs8enckey_out     :   [IN/OUT]    encrypted pkcs8 structure output location
 * RETURNS
 *  pki_error_enum
 * SEE ALSO
 *  pki_pkcs8enckey_release
 *****************************************************************************/
extern pki_error_enum pki_pkcs8enckey_new(
                    pki_context_struct *pki_ctx,
                    const void *encdata,
                    kal_uint32 size,
                    pki_pkcs8enckey_struct **pkcs8enckey_out);

/*****************************************************************************
 * <GROUP pki_pkcs8_funcs>
 *
 * FUNCTION
 *  pki_pkcs8enckey_release
 * DESCRIPTION
 *  This function is to release a encrypted pkcs8 key struct data
 * PARAMETERS
 *  pkcs8enckey     :   [IN]    specified encrypted pkcs8 structure
 * RETURNS
 *  void
 * SEE ALSO
 *  pki_pkcs8enckey_new 
 *****************************************************************************/
extern void pki_pkcs8enckey_release(pki_pkcs8enckey_struct **pkcs8enckey);

/*****************************************************************************
 * <GROUP pki_pkcs8_funcs>
 *
 * FUNCTION
 *  pki_pkcs8enckey_get_der
 * DESCRIPTION
 *  This function is to get the DER format data part of specified encrypted pkcs8
 *  NOTE : applications don't have to release memory for this get operation 
 * PARAMETERS
 *  pkcs8enckey :    [IN]       specified encrypted pkcs8 structure
 *  data        :    [IN\OUT]   decrypted pkcs8 key data in DER format
 *  size        :    [IN\OUT]   decrypted pkcs8 key data length
 * RETURNS
 *  pki_error_enum
 * SEE ALSO
 *  pki_pkcs8enckey_new 
 *****************************************************************************/
extern pki_error_enum pki_pkcs8enckey_get_der(
                    pki_pkcs8enckey_struct *pkcs8enckey,
                    const void **data,
                    kal_uint32 *size);

/*****************************************************************************
 * <GROUP pki_pkcs8_funcs>
 *
 * FUNCTION
 *  pki_pkcs8enckey_decrypt
 * DESCRIPTION
 *  This function is to decrypt the specified pkcs8 encrypted key structure
 *  NOTE : 1. The parameter "decdata_out" if NOT NULL, will store the DER pkcs8 key data.
 *            But the memory is allocated by PKI library, that need applications to release the memory by
 *            API:pki_pkcs8key_data_release
 *         2. The parameter "decsize_out" if NOT NULL, will store the DER pkcs8 key data length.
 *            Applications can call this API first use this attribute to query the data size 
 *            to prepare the buffer for copy operation
 *         3. If the function returns error, applications don't have to release any memory.
 * PARAMETERS
 *  pkcs8key        :   [IN]        specified encrypted pkcs8 structure
 *  pwd             :   [IN]        specified password for encryption
 *  pwd_size        :   [IN]        specified password length
 *  decdata_out     :   [IN/OUT]    decrypted pkcs8 key data in DER format
 *  decsize_out     :   [IN/OUT]    decrypted pkcs8 key data length 
 * RETURNS
 *  pki_error_enum
 * SEE ALSO
 *  pki_pkcs8enckey_new, pki_pkcs8key_data_release 
 *****************************************************************************/
extern pki_error_enum pki_pkcs8enckey_decrypt(
                    pki_pkcs8enckey_struct *pkcs8enckey,
                    const char *pwd,
                    kal_uint32 pwd_size,
                    void **decdata_out,
                    kal_uint32 *decsize_out);


/************** PKI PKCS7 Exported APIs ******************/

/*****************************************************************************
 * <GROUP pki_pkcs7_funcs>
 *
 * FUNCTION
 *  pki_pkcs7dec_new
 * DESCRIPTION
 *  This function is to create a pkcs7 decode context
 * PARAMETERS
 *  pki_ctx         :   [IN]        associated pki context
 *  data            :   [IN]        DER format pkcs7 data
 *  size            :   [IN]        DER format pkcs7 data size
 *  pk7dec_out      :   [IN/OUT]    pkcs7 decode context structure output location
 * RETURNS
 *  pki_error_enum
 * SEE ALSO
 *  pki_pkcs7dec_new 
 *****************************************************************************/
extern pki_error_enum pki_pkcs7dec_new(
                    pki_context_struct *pki_ctx,
                    void *data,
                    kal_uint32 size,
                    pki_pkcs7dec_struct **pk7dec_out);

/*****************************************************************************
 * <GROUP pki_pkcs7_funcs>
 *
 * FUNCTION
 *  pki_pkcs7dec_release
 * DESCRIPTION
 *  This function is to release the pki pkcs7dec context resources
 * PARAMETERS
 *  pkcs7dec        :   [IN]        associated pkcs7 decode context
 * RETURNS
 *  void 
 * SEE ALSO
 *  pki_pkcs7dec_new
 *****************************************************************************/
extern void pki_pkcs7dec_release(pki_pkcs7dec_struct **pkcs7dec);

/*****************************************************************************
 * <GROUP pki_pkcs7_funcs>
 *
 * FUNCTION
 *  pki_pkcs7dec_get_content_type
 * DESCRIPTION
 *  This function is to query the content type of associated pkcs7dec context
 * PARAMETERS
 *  pkcs7dec    :   [IN]        associated pkcs7 context
 *  cnttype     :   [IN/OUT]    content type of specified pkcs7 context (pki_pkcs7_cnttype_enum)
 * RETURNS
 *  pki_error_enum
 * SEE ALSO
 *  pki_pkcs7dec_new 
 *****************************************************************************/
extern pki_error_enum pki_pkcs7dec_get_content_type(
                    pki_pkcs7dec_struct *pkcs7dec,
                    pki_pkcs7_cnttype_enum *cnttype);

/*****************************************************************************
 * <GROUP pki_pkcs7_funcs>
 *
 * FUNCTION
 *  pki_pkcs7dec_signed_get_cert_count
 * DESCRIPTION
 *  This function is to query the nuber of certificates in specified pkcs7 signed context
 *  NOTE : 1. we can only support the signed type pkcs7 data
 *         2. if the specified pkcs7 context isn't signed type, returns PKI_ERR_INVALID_CONTEXT
 * PARAMETERS
 *  pkcs7dec    :   [IN]        associated pkcs7 context
 *  num_certs   :   [IN/OUT]    number of certificates in this pkcs7 output location
 * RETURNS
 *  pki_error_enum
 * SEE ALSO
 *  pki_pkcs7dec_new, pki_pkcs7dec_get_content_type
 *****************************************************************************/
extern pki_error_enum pki_pkcs7dec_signed_get_cert_count(
                    pki_pkcs7dec_struct *pkcs7dec,
                    kal_uint32 *num_certs);

/*****************************************************************************
 * <GROUP pki_pkcs7_funcs>
 *
 * FUNCTION
 *  pki_pkcs7dec_signed_get_cert_by_index
 * DESCRIPTION
 *  This function is to query the certificate data by index in specified pkcs7 signed context
 *  NOTE : 1. we can only support the signed type pkcs7 data
 *         2. if the specified pkcs7 context isn't signed type, returns PKI_ERR_INVALID_CONTEXT
 *         3. if the specified index is larger than the cert count of this pkcs7, returns error
 *         4. if the parameter x509_out is NULL, no new x509 context will be created.
 *            otherwise, applications need to call API:pki_x509_release to release the x509 context
 * PARAMETERS
 *  pkcs7dec    :   [IN]        associated pkcs7 context
 *  index       :   [IN]        index of certificate list
 *  x509_out    :   [IN/OUT]    x509 context of certificate output location
 * RETURNS
 *  pki_error_enum
 * SEE ALSO
 *  pki_pkcs7dec_new, pki_pkcs7dec_get_content_type, pki_pkcs7dec_signed_get_cert_count
 *****************************************************************************/
extern pki_error_enum pki_pkcs7dec_signed_get_cert_by_index(
                    pki_pkcs7dec_struct *pkcs7dec,
                    kal_uint32 index,
                    pki_x509_struct **x509_out);


/************** PKI PKCS12 Exported APIs ******************/

/*****************************************************************************
 * <GROUP pki_pkcs12_funcs>
 *
 * FUNCTION
 *  pki_pkcs12dec_is_passenc
 * DESCRIPTION
 *  This function is to check the specified pkcs12 encoded data is pretected by password
 * PARAMETERS
 *  pki_ctx         :   [IN]        associated pki context
 *  data            :   [IN]        DER format pkcs12 data
 *  size            :   [IN]        DER format pkcs12 data size
 *  use_pwd         :   [IN/OUT]    password protected flag output location
 * RETURNS
 *  pki_error_enum 
 * SEE ALSO
 *  pki_pkcs12dec_begin
 *****************************************************************************/
extern pki_error_enum pki_pkcs12dec_is_passenc(
                    pki_context_struct *pki_ctx,
                    void *data,
                    kal_uint32 size,
                    kal_uint32 *use_pwd);

/*****************************************************************************
 * <GROUP pki_pkcs12_funcs>
 *
 * FUNCTION
 *  pki_pkcs12dec_begin
 * DESCRIPTION
 *  This function is to create a pkcs12 decode context for parsing specified pkcs12 encoded data
 * PARAMETERS
 *  pki_ctx         :   [IN]        associated pki context
 *  data            :   [IN]        DER format pkcs12 encoded data
 *  size            :   [IN]        DER format pkcs12 encoded data size
 *  pwd             :   [IN]        pkcs12 passward data
 *  pwd_size        :   [IN]        pkcs12 passward data size 
 *  pkcs12dec_out   :   [IN/OUT]    pkcs12 decode context output location
 * RETURNS
 *  pki_error_enum
 * SEE ALSO
 *  pki_pkcs12dec_release
 *****************************************************************************/
extern pki_error_enum pki_pkcs12dec_begin(
                    pki_context_struct *pki_ctx,
                    void *data,
                    kal_uint32 size,
                    const char *pwd,
                    kal_uint32 pwd_size,
                    pki_pkcs12dec_struct **pkcs12dec_out);


/*****************************************************************************
 * <GROUP pki_pkcs12_funcs>
 *
 * FUNCTION
 *  pki_pkcs12dec_get_bag
 * DESCRIPTION
 *  This function is to get a bag from specified pkcs12 decode context
 *  NOTE : 1. we can only support types - PKI_SAFEBAG_KEYBAG, PKI_SAFEBAG_SHROUDEDKEYBAG, PKI_SAFEBAG_CERTBAG
 *         2. the bag_type and bag_out will be updated only if the specified values are not null
 *         3. if the returned bag_type is not supported one, don't have to release the output bag context "*bag_out"
 *         4. if the bag_out is specified, a new context will be created by PKI library
 *            PKI_SAFEBAG_KEYBAG, PKI_SAFEBAG_SHROUDEDKEYBAG --> create a pkcs8key context
 *            PKI_SAFEBAG_CERTBAG --> create a x509 context
 *            please remember to release the created contexts by corresponding APIs
 * PARAMETERS
 *  pkcs12dec   :   [IN]        associated pkcs12 decode context
 *  pwd         :   [IN]        pkcs12 passward data
 *  pwd_size    :   [IN]        pkcs12 passward data size 
 *  bag_type    :   [IN/OUT]    returned bag type output location (pki_safebag_type_enum)
 *  bag_out     :   [IN/OUT]    returned bag context data output location
 * RETURNS
 *  pki_error_enum
 * SEE ALSO
 *  pki_pkcs12dec_begin, pki_pkcs8key_release, pki_x509_release, pki_pkcs12dec_release
 *****************************************************************************/
extern pki_error_enum pki_pkcs12dec_get_bag(
                    pki_pkcs12dec_struct *pkcs12dec,
                    const void *pwd, 
                    kal_uint32 pwd_size,
                    pki_safebag_type_enum *bag_type,
                    void **bag_out);

/*****************************************************************************
 * <GROUP pki_pkcs12_funcs>
 *
 * FUNCTION
 *  pki_pkcs12dec_release
 * DESCRIPTION
 *  This function is to release the specified pkcs12 decode context
 * PARAMETERS
 *  pkcs12dec   :   [IN]    associated pkcs12 context location
 * RETURNS
 *  void
 * SEE ALSO
 *  pki_pkcs12dec_begin 
 *****************************************************************************/
extern void pki_pkcs12dec_release(pki_pkcs12dec_struct **pkcs12dec);


/************** PKI VALIDATION Exported APIs ******************/

/*****************************************************************************
 * <GROUP pki_validation_funcs>
 *
 * FUNCTION
 *  pki_validate_new
 * DESCRIPTION
 *  This function is to create a validation context for validation process
 * PARAMETERS
 *  pki_ctx     :   [IN]        associated pki context
 *  usage       :   [IN]        context for validation or chain generation (pki_valusage_enum)
 *  val_out     :   [IN/OUT]    validation context output location
 * RETURNS
 *  pki_error_enum 
 * SEE ALSO
 *  pki_validate_release
 *****************************************************************************/
extern pki_error_enum pki_validate_new(
                    pki_context_struct *pki_ctx,
                    pki_valusage_enum usage,
                    pki_validate_struct **val_out);

/*****************************************************************************
 * <GROUP pki_validation_funcs>
 *
 * FUNCTION
 *  pki_validate_set_verify_path
 * DESCRIPTION
 *  This function is to set associated trusted ca pools from application folder
 *  to specified validation context
 *  NOTE : all files in the specified path will be added into trusted pool, but the files
 *         whose type isn't specfied filetype will be ignored.
 * PARAMETERS
 *  val         :   [IN]        associated validation context
 *  path        :   [IN]        associated trusted ca pool path
 *  filetype    :   [IN\OUT]    specified certificate file type (pki_filetype_enum)
 * RETURNS
 *  pki_error_enum 
 * SEE ALSO
 *  pki_validate_new
 *****************************************************************************/
pki_error_enum pki_validate_set_verify_path(
                    pki_validate_struct *val,
                    kal_wchar *path,
                    pki_filetype_enum filetype);

/*****************************************************************************
 * <GROUP pki_validation_funcs>
 *
 * FUNCTION
 *  pki_validate_add_cert
 * DESCRIPTION
 *  This function is to add a certificate to the validation context for validation
 * PARAMETERS
 *  val         :   [IN]    associated validation context
 *  trusted     :   [IN]    identify the current certificate is trusted or not
 *  cert        :   [IN]    certificate data for inserting in the validation context (should be DER format)
 *  size        :   [IN]    the certificate data length
 * RETURNS
 *  pki_error_enum 
 * SEE ALSO
 *  pki_validate_new
 *****************************************************************************/
extern pki_error_enum pki_validate_add_cert(
                        pki_validate_struct *val, 
                        kal_uint8 trusted, 
                        const void *cert, 
                        kal_uint32 size);

/*****************************************************************************
 * <GROUP pki_validation_funcs>
 *
 * FUNCTION
 *  pki_validate_execute
 * DESCRIPTION
 *  This function is to execute the validation process of the specified validation context with the input end-entity certificate
 *  NOTE : the warning array stores all the warnings in validation process
 * PARAMETERS
 *  val             :   [IN]        associated validation context
 *  cert            :   [IN]        the end-entity certificate data that need to be validated
 *  size            :   [IN]        the certificate data length
 *  all_warnings    :   [IN/OUT]    identify the warnings in this validation process
 * RETURNS
 *  pki_error_enum 
 * SEE ALSO
 *  pki_validate_new, pki_validate_get_path_warnings, pki_validate_get_path_length, pki_validate_get_cert_in_path
 *****************************************************************************/
extern pki_error_enum pki_validate_execute(
                        pki_validate_struct *val,
                        const void *cert,
                        kal_uint32 size,
                        kal_uint32 *all_warnings);

/*****************************************************************************
 * <GROUP pki_validation_funcs>
 *
 * FUNCTION
 *  pki_validate_get_path_warnings
 * DESCRIPTION
 *  This function is to get the validation warnings of specified validation context
 * PARAMETERS
 *  val             :   [IN]        associated validation context
 *  warnings_array  :   [IN/OUT]    output location for warnings
 *  array_size      :   [IN/OUT]    warning array size output location
 * RETURNS
 *  pki_error_enum 
 *****************************************************************************/
extern pki_error_enum pki_validate_get_path_warnings(pki_validate_struct *val, kal_uint32 *warnings_array, kal_uint32 *array_size);

/*****************************************************************************
 * <GROUP pki_validation_funcs>
 *
 * FUNCTION
 *  pki_validate_get_path_length
 * DESCRIPTION
 *  This function is to query the certificate chain length of the validation context
 * PARAMETERS
 *  val                 :   [IN]    associated validation context
 *  num_certs_in_path   :   [IN]    number of certs after chain built
 * RETURNS
 *  pki_error_enum 
 *****************************************************************************/
extern pki_error_enum pki_validate_get_path_length(pki_validate_struct *val, kal_uint32 *num_certs_in_path);

/*****************************************************************************
 * <GROUP pki_validation_funcs>
 *
 * FUNCTION
 *  pki_validate_get_cert_in_path
 * DESCRIPTION
 *  This function is to get a cert data from built validation chain
 * PARAMETERS
 *  val         :   [IN]        associated validation context
 *  idx         :   [IN]        cert index for of chain
 *  cert        :   [IN/OUT]    certificate data output location
 *  size        :   [IN/OUT]    certificate data length output location
 *  warnings    :   [IN/OUT]    validation warning of this certificate
 * RETURNS
 *  pki_error_enum 
 *****************************************************************************/
extern pki_error_enum pki_validate_get_cert_in_path(pki_validate_struct *val, kal_uint32 idx, const void **cert, kal_uint32 *size, kal_uint32 *warnings);

/*****************************************************************************
 * <GROUP pki_validation_funcs>
 *
 * FUNCTION
 *  pki_validate_release
 * DESCRIPTION
 *  This function is release allocated resources of the validation context
 * PARAMETERS
 *  val     :   [IN]    associated validation context
 * RETURNS
 *  pki_error_enum
 * SEE ALSO
 *  pki_validate_new 
 *****************************************************************************/
extern void pki_validate_release(pki_validate_struct **val);

/*****************************************************************************
 * <GROUP pki_validation_funcs>
 *
 * FUNCTION
 *  pki_validate_data_release
 * DESCRIPTION
 *  This function is to release the pki validation allocated resources
 * PARAMETERS
 *  data    :   [IN]        associated data memory pointer
 * RETURNS
 *  void
 *****************************************************************************/
extern void pki_validate_data_release(const void *data);


/*****************************************************************************
 * <GROUP pki_ocsp_funcs>
 *
 * FUNCTION
 *  pki_ocsp_check_url
 * DESCRIPTION
 *  Parse OCSP responder URL
 *  The URL should be http(s)://host.name(:port)/path
 * PARAMETERS
 *  url :        [IN]       target URL to be checked
 * RETURNS
 *  PKI_ERR_NONE: a valid address
 *  PKI_ERR_FAIL: illegal address string
 *****************************************************************************/
extern pki_error_enum pki_ocsp_check_url(kal_char *url);


/*****************************************************************************
 * <GROUP pki_ocsp_funcs>
 *
 * FUNCTION
 *  pki_ocsp_parse_url
 * DESCRIPTION
 *  This function parses OCSP responder URL and set the pointers to the
 *  string in the output buffer
 *  The URL should be http(s)://host.name(:port)/path
 * PARAMETERS
 *  url :        [IN]       target URL to be parsed
 *  outbuf :     [IN/OUT]   output buffer provided by caller to hold parsed
 *                          strings 
 *  outbuf_len : [IN]       size of outbuf, the size should be >= strlen(url)+1
 *  phost :      [OUT]      pointer to host domain name or address
 *  pport :      [OUT]      pointer to port number in string
 *  ppath :      [OUT]      pointer to path
 *  ssl :        [OUT]      use SSL or not
 * RETURNS
 *  PKI_ERR_NONE: a valid address
 *  PKI_ERR_INVALID_INPUT: error on processing the passed arguments
 *  PKI_ERR_FAIL: illegal address string
 *  PKI_ERR_EXCEED_MAX_DATA_SIZE: insufficient output buffer size
 *****************************************************************************/
extern pki_error_enum 
pki_ocsp_parse_url(kal_char *url, kal_char *outbuf, kal_int32 outbuf_len, 
                   char **phost, char **pport, char **ppath, kal_bool *ssl);


/*****************************************************************************
 * <GROUP pki_ocsp_funcs>
 *
 * FUNCTION
 *  pki_ocsp_compose_req
 * DESCRIPTION
 *  This function composes OCSP request message to be sent to responder
 * PARAMETERS
 *  cert :       [IN]  DER-encoded certificate to retrieve the status
 *  cert_len :   [IN]  length in bytes of the DER-encoded cert
 *  issuer :     [IN]  DER-encoded isser certificate of cert
 *  issuer_len : [IN]  length in bytes of the DER-encoded issuer
 *  use_nonce :  [IN]  use nonce or not
 *  signkey :    [IN]  private key to sign the request message
 *  req :        [IN]  output buffer to hold the composed request message 
 *                     in DER format
 *  req_len :    [IN]  buffer length 
 * RETURNS
 *  PKI_ERR_NONE: the request message is composed successfully
 *  PKI_ERR_INVALID_INPUT: error on processing the passed arguments
 *  PKI_ERR_EXCEED_MAX_DATA_SIZE: the given buffer size is not enough, the
 *                                required size is passed back from req_len 
 *  PKI_ERR_FAIL: common internal library fail
 *****************************************************************************/
extern pki_error_enum 
pki_ocsp_compose_req(void *cert, kal_uint32 cert_len,
                     void *issuer, kal_uint32 issuer_len,
                     kal_bool use_nonce,
                     pki_pkcs8key_struct *signkey,
                     void *req, kal_int32 *req_len);


/*****************************************************************************
 * <GROUP pki_ocsp_funcs>
 *
 * FUNCTION
 *  pki_ocsp_verify_rsp
 * DESCRIPTION
 *  This function verify received OCSP response message
 * PARAMETERS
 *  req_msg :         [IN]      DER-encoded OCSP request
 *  req_len :         [IN]      the length of request message
 *  rsp_msg :         [IN]      DER-encoded OCSP response message
 *  rsp_len:          [IN]      the length of response message
 *  trusted_ca_path : [IN]      Path storing trustd certificates
 *  ca_filetype :     [IN]      Certificate file encoding type for the
 *                              certificates in trusted_ca_path
 *  issuer :          [IN]      Issuer of the certificate to be verified with
 *                              OCSP
 *  issuer_len :      [IN]      number of bytes in issuer
 *  nsec :            [IN]      We allow the times to be within 'nsec' of the
 *                              current time, in seconds, for checking
 *                              thisUpdate and nextUpdate
 *  maxage :          [IN]      The maximum acceptable age that thisUpdate field
 *                              can be. This check only applied if the value
 *                              is >=not recommended. 0 is not recommended.
 * RETURNS
 *  PKI_ERR_NONE: the status is good
 *  PKI_ERR_INVALID_INPUT: error on processing the passed arguments
 *  PKI_ERR_OCSP_VERIFY_FAIL: checking nonce, untrusted certificate in response,
 *                            
 *  PKI_ERR_MEMFULL: cannot not finish the operation due to out of memory 
 *  PKI_ERR_UNSUPPORTED_CONTENT: error on parsing the data
 *  PKI_ERR_OCSP_STATUS_REVOKED: the certificate is revoked
 *  PKI_ERR_OCSP_STATUS_UNKNOWN: the certificate is unknown
 *  PKI_ERR_OCSP_TIME_VALIDITY: proelbm in checking time fields
 *  PKI_ERR_FAIL: common internal library fail
 *****************************************************************************/
extern pki_error_enum 
pki_ocsp_verify_rsp(void *req_msg, kal_uint32 req_len,
                    void *rsp_msg, kal_uint32 rsp_len,
                    kal_wchar *trusted_ca_path, pki_filetype_enum ca_filetype,
                    void *issuer, kal_uint32 issuer_len,
                    kal_int32 nsec, kal_int32 maxage);



/* DOM-NOT_FOR_SDK_BEGIN */
/*****************************************************************************
 * FUNCTION
 *  pki_validate_save_link_files
 * DESCRIPTION
 *  This function is save temp link files for verification in app specified  folder
 *  NOTE : specific for Certman utility
 * PARAMETERS
 *  hash_value      :   [IN]    link file name
 *  output_path     :   [IN]    link file path
 *  cert_file       :   [IN]    real file name
 *  del_no_match    :   [IN]    delete flag if found not match files
 * RETURNS
 *  pki_error_enum 
 *****************************************************************************/
extern pki_error_enum pki_validate_save_link_files(kal_uint32 hash_value, kal_wchar * output_path, kal_wchar *cert_file, kal_uint8 del_no_match);

#ifdef PKI_PKCS_EXORT
/* PKCS #7 -- ENCODE */
extern pki_error_enum
pki_pkcs7enc_new(pki_context_struct *pki_ctx, pki_pkcs7_cnttype_enum cnttype, pki_pkcs7enc_struct **pk7enc_out);

extern pki_error_enum
pki_pkcs7enc_final(pki_pkcs7enc_struct **pkcs7enc, void **data, kal_uint32 *size);

extern void
pki_pkcs7enc_abort(pki_pkcs7enc_struct **pkcs7enc);

/* PKCS #12 -- ENCODE -- generate/abort */
extern pki_error_enum
pki_pkcs12enc_final(pki_pkcs12enc_struct *pkcs12enc, const char *pwd, kal_uint32 pwd_size, void **data, kal_uint32 *size);

extern void
pki_pkcs12enc_abort(pki_pkcs12enc_struct **pkcs12enc);

/* PKCS #12 -- ENCODE -- context */
extern pki_error_enum
pki_pkcs12enc_new(pki_context_struct *pki_ctx, pki_pkcs12enc_struct **pkcs12enc_out);

/* PKCS #12 -- ENCODE -- SafeContent */
extern pki_error_enum
pki_pkcs12enc_add_safecntenc_unenc(pki_pkcs12enc_struct *pkcs12enc, pki_safecntenc_struct **safecontent_out);

extern pki_error_enum
pki_pkcs12enc_add_safecntenc_passenc(pki_pkcs12enc_struct *pkcs12enc, const char *pwd, kal_uint32 pwd_size, pki_safecntenc_struct **safecontent_out);
#endif  /* PKI_PKCS_EXPORT */
/* DOM-NOT_FOR_SDK_END */


#endif  /* PKI_API_H */
