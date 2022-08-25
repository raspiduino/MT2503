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
 * app_url.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains prototype for URI parsing utilities.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _APP_URL_H
#define _APP_URL_H

#include "kal_general_types.h"
#include "app_usedetails.h"

/* Scheme part of an URL, used to index into the arrays in the applib_url_struct type */
#define APPLIB_URL_SCHEME_PART             0
/* Authority part of an URL, used to index into the arrays in the applib_url_struct type */
#define APPLIB_URL_AUTHORITY_PART          1
/* Path part of an URL, used to index into the arrays in the applib_url_struct type */
#define APPLIB_URL_PATH_PART               2
/* Query part of an URL, used to index into the arrays in the applib_url_struct type */
#define APPLIB_URL_QUERY_PART              3
/* Fragment part of an URL, used to index into the arrays in the applib_url_struct type */
#define APPLIB_URL_FRAGMENT_PART           4
/* Userinfo part of an URL, used to index into the arrays in the applib_url_struct type */
#define APPLIB_URL_USERINFO_PART           5
/* Host part of an URL, used to index into the arrays in the applib_url_struct type */
#define APPLIB_URL_HOST_PART               6
/* Port part of an URL, used to index into the arrays in the applib_url_struct type */
#define APPLIB_URL_PORT_PART               7

/* Total number of part of an URL */
#define APPLIB_URL_NUM_PARTS               8

/* Error code of invalid URL due to invalid parameter */
#define APPLIB_URL_ERR_INVALID_PARAM	-1
/* Error code of invalid URL due to invalid scheme */
#define APPLIB_URL_ERR_INVALID_SCHEME	-2
/* Error code of invalid URL due to invalid host */
#define APPLIB_URL_ERR_INVALID_HOST		-3
/* Error code of invalid URL due to invalid port */
#define APPLIB_URL_ERR_INVALID_PORT		-4


/**********************************************************************
 * Type definitions
 **********************************************************************/

/* The scheme type */
typedef enum {
	applib_scheme_empty,    /* Empty scheme */
	applib_scheme_http,     /* http scheme */
	applib_scheme_https,    /* https scheme */
	applib_scheme_file,     /* file scheme */
	applib_scheme_wtai,     /* wtai scheme */
	applib_scheme_rtsp,     /* rtsp scheme */
	applib_scheme_tel,      /* tel scheme */
	applib_scheme_mailto,   /* mailto scheme */
	applib_scheme_sms,      /* sms scheme */
	applib_scheme_smsto,    /* smsto scheme */
	applib_scheme_mms,      /* mms scheme */
	applib_scheme_mmsto,    /* mmsto scheme */
	applib_scheme_unknown   /* Unknown scheme */
} url_scheme_type_enum;


/* The URL structure */
typedef struct {
    url_scheme_type_enum  scheme_type;                  /* The scheme type of URL */
    const char *          parts[APPLIB_URL_NUM_PARTS];  /* The string of different part of URL */
    int                   len[APPLIB_URL_NUM_PARTS];    /* The string length of different part of URL */
} applib_url_struct;


/* The scheme structure */
typedef struct 
{
	const char *leading_string; /* Scheme string */
	int scheme_type;            /* The scheme type */
} applib_scheme_struct;

/* Number of supported schemes for URL parsing and validity check */
#define APPLIB_NBR_OF_SUPPORTED_SCHEMES 11

/* Supported schemes for URL parsing and validity check */
#define APPLIB_URL_SUPPORTED_SCHEMES { \
    { "http",   applib_scheme_http }, \
    { "https",  applib_scheme_https }, \
    { "file",   applib_scheme_file }, \
    { "wtai",   applib_scheme_wtai }, \
    { "rtsp",   applib_scheme_rtsp }, \
    { "tel",   applib_scheme_tel }, \
    { "mailto",   applib_scheme_mailto }, \
    { "sms",   applib_scheme_sms }, \
    { "smsto",   applib_scheme_smsto }, \
    { "mms",   applib_scheme_mms }, \
    { "mmsto",   applib_scheme_mmsto } }
  
/*****************************************************************************
 * FUNCTION
 *  applib_url_check_scheme
 * DESCRIPTION
 *  This function is used to check if scheme part of an URL is valid or not.
 * PARAMETERS
 *  p   :   [IN]    URL which is want to be checked.
 * RETURN VALUES
 *  0: Scheme part is valid.
 *  APPLIB_URL_ERR_INVALID_SCHEME: Scheme part is invalid.
 *****************************************************************************/
extern int applib_url_check_scheme(applib_url_struct *p);

/*****************************************************************************
 * FUNCTION
 *  applib_url_check_host
 * DESCRIPTION
 *  This function is used to check if host part of an URL is valid or not.
 * PARAMETERS
 *  p   :   [IN]    URL which is want to be checked.
 * RETURN VALUES
 *  0: Host part is valid.
 *  APPLIB_URL_ERR_INVALID_HOST: Host part is invalid.
 *****************************************************************************/
extern int applib_url_check_host(applib_url_struct *p);

/*****************************************************************************
 * FUNCTION
 *  applib_url_check_port
 * DESCRIPTION
 *  This function is used to check if port part of an URL is valid or not.
 * PARAMETERS
 *  p   :   [IN]    URL which is want to be checked.
 * RETURN VALUES
 *  0: Port part is valid.
 *  APPLIB_URL_ERR_INVALID_PORT: Port part is invalid.
 *****************************************************************************/
extern int applib_url_check_port(applib_url_struct *p);

/*****************************************************************************
 * FUNCTION
 *  applib_url_check_ip
 * DESCRIPTION
 *  This function check whether address is in the form of IPv4 address,
 *  if so, validate the IP address with the valid IP range.
 * PARAMETERS
 *  addr    :   [IN]    IPv4 address string.
 *  len     :   [IN]    Length of IPv4 address string.
 * RETURNS
 *  1 if addr is an valid address.
 *****************************************************************************/
extern int applib_url_check_ip(const char *addr, int len);

/*****************************************************************************
 * FUNCTION
 *  applib_parse_url
 * DESCRIPTION
 *  This function is used to parse url to different parts into applib_url_struct structure.
 * PARAMETERS
 *  url :   [IN]    URL which is want to be parsed.
 *  p   :   [OUT]   Output applib_url_struct structure.
 * RETURNS
 *  0 if parsing successful, -1 if parsing failed.
 *****************************************************************************/
extern int applib_parse_url(const char *url, applib_url_struct *p);

/*****************************************************************************
 * FUNCTION
 *  applib_url_is_valid
 * DESCRIPTION
 *  To check if an URL is valid or not. Empty or unknown scheme is not allowed.
 * PARAMETERS
 *  url :   [IN]    URL which is want to be checked.
 * RETURN VALUES
 *  0: URL is valid.
 *  APPLIB_URL_ERR_INVALID_PARAM: parameter is invalid.
 *  APPLIB_URL_ERR_INVALID_SCHEME: Scheme part is invalid.
 *  APPLIB_URL_ERR_INVALID_HOST: Host part is invalid.
 *  APPLIB_URL_ERR_INVALID_PORT: Port part is invalid.
 *****************************************************************************/
extern int applib_url_is_valid(const char *url);

/*****************************************************************************
 * FUNCTION
 *  applib_url_is_valid_ext
 * DESCRIPTION
 *  To check if a URL is valid or not based on allow_empty_scheme and allow_empty_scheme.
 * PARAMETERS
 *  url                     :   [IN]    URL which is want to be checked.
 *  allow_empty_scheme      :   [IN]    Empty scheme is allowed or not.
 *  allow_unknown_scheme    :   [IN]    Scheme except for HTTP, HTTPS, FILE, WTAI, RTSP, TEL,
 *                                      MAILTO, SMS, SMSTO, MMS, and MMSTO is allowed or not.
 * RETURN VALUES
 *  0: URL is valid.
 *  APPLIB_URL_ERR_INVALID_PARAM: parameter is invalid.
 *  APPLIB_URL_ERR_INVALID_SCHEME: Scheme part is invalid.
 *  APPLIB_URL_ERR_INVALID_HOST: Host part is invalid.
 *  APPLIB_URL_ERR_INVALID_PORT: Port part is invalid.
 *****************************************************************************/
extern int applib_url_is_valid_ext(const char *url, kal_bool allow_empty_scheme, kal_bool allow_unknown_scheme);

/*****************************************************************************
 * FUNCTION
 *  applib_cvt_escape_string_to_normal_string
 * DESCRIPTION
 *  This function is used to convert escape string to strings.
 * PARAMETERS
 *  input       :   [IN]        Pointer to escape string
 *  input_len   :   [IN]        Length of escape string
 *  output      :   [IN/OUT]    Pointer to output string
 *  output_len  :   [IN]        Length of output string 
 * RETURNS
 *  KAL_TRUE if convert successfully, KAL_FALSE if convert failed.
 *****************************************************************************/
extern kal_bool applib_cvt_escape_string_to_normal_string(kal_char *input, kal_int32 input_len, kal_char *output, kal_int32 output_len);

/*****************************************************************************
 * FUNCTION
 *  applib_cvt_normal_string_to_escape_string
 * DESCRIPTION
 *  This function is used to convert string to escape strings.
 * PARAMETERS
 *  input                   :   [IN]        Pointer to string
 *  input_len               :   [IN]        Length of string
 *  special_chars_arry      :   [IN]        The array contains some ASCII characters shall be converted to escape_string
 *  special_chars_arry_len  :   [IN]        The length of special_chars_arry
 *  output                  :   [IN/OUT]    Pointer to output escape string
 *  output_len              :   [IN]        Length of output escape string 
 * RETURNS
 *  KAL_TRUE if convert successfully, KAL_FALSE if convert failed.
 *****************************************************************************/
extern kal_bool applib_cvt_normal_string_to_escape_string(kal_char *input, kal_int32 input_len, kal_char *special_chars_arry, kal_uint32 special_chars_arry_len, kal_char *output, kal_int32 output_len);
#ifdef BROWSER_SUPPORT
extern applib_address_node_struct *applib_parse_url_from_text(
        applib_mem_alloc_fn mem_alloc_fn, 
        applib_mem_free_fn mem_free_fn,
        applib_check_stop_fn check_stop_fn,
        char *input_data, 
        kal_int32 dataLen,
        kal_bool *is_stopped,
        kal_bool is_remove_duplicate);

extern applib_address_node_struct *applib_parse_url_from_text_unicode(
        applib_mem_alloc_fn mem_alloc_fn, 
        applib_mem_free_fn mem_free_fn,
        applib_check_stop_fn check_stop_fn,
        kal_wchar *input_data, 
        kal_int32 dataLen,
        kal_bool *is_stopped,
        kal_bool is_remove_duplicate);
#endif


#endif /* _APP_URL_H */

